// char b[20];
// _itoa( i, b, 10 );
// MessageBox( NULL, b, "Kentest", MB_OK );

#define IDIRECTPLAY2_OR_GREATER

#include "stdafx.h"
//#include "dplobby.h"
//#include "dplay.h"
#include <wininet.h>
#include <tchar.h>
#include <COMMCTRL.H>
#include <objbase.h>
#include <richedit.h>
#include "winsock.h"
#include "Communicate.h"
#include "mbstring.h"
#include "resource.h"
#include "stdio.h"
#include "FileReq.h"


#define FILE_SIZE			1024 * 64
#define MAX_NAME			200

struct COMM_MODEM
{
	BOOL		nResult; // return value from Dialog Box
	HINSTANCE	hInst;
	HWND		hWnd;
	HHOOK		hHook;
	HWND		parenthWnd, edit_hWnd;
	HWND		hWaitDlg;
};

static  COMM_MODEM	g_Modem;


//////////////////////////////////////////////////////////////////////////////////////
// S T A R T		D I R E C T P L A Y			 S E C T I O N S
//////////////////////////////////////////////////////////////////////////////////////
// Defines, and constants - from sample code
#define SAFE_DELETE(p)       { if(p) { delete (p);     (p)=NULL; } }
#define SAFE_DELETE_ARRAY(p) { if(p) { delete[] (p);   (p)=NULL; } }
#define SAFE_RELEASE(p)      { if(p) { (p)->Release(); (p)=NULL; } }

//testing only
#define DPLAY_SAMPLE_KEY     TEXT("Software\\Microsoft\\DirectX DirectPlay Samples")
#define EXITCODE_FORWARD      1  // Dialog success, so go forward
#define EXITCODE_BACKUP       2  // Dialog canceled, show previous dialog
#define EXITCODE_QUIT         3  // Dialog quit, close app
#define EXITCODE_ERROR        4  // Dialog error, terminate app
#define EXITCODE_LOBBYCONNECT 5  // Dialog connected from lobby, connect success
#define MAX_CHAT_STRINGS	  50
#define IDC_RETURN            102

VOID DisplayDPOpenError( HRESULT hr );
VOID OnListening( HWND hDlg );
//end of testing purpose only

// GUID allows DirectPlay to find other instances of the same program on the network.
// {18DE06A0-B963-11D3-A553-0050048A779F}
//GUID g_AppGUID = { 0x18DE06A0, 0xB963, 0x11D3, { 0xA5, 0x53, 0x00, 0x50, 0x04, 0x8A, 0x77, 0x9F } };

// {E9EB4143-0FA4-4e0b-BEB3-C5222657F9F2}
GUID g_AppGUID = { 0xe9eb4143, 0xfa4, 0x4e0b, { 0xbe, 0xb3, 0xc5, 0x22, 0x26, 0x57, 0xf9, 0xf2 } };

struct DPSessionInfo
{
	GUID guidSession;
	TCHAR szSession[MAX_NAME];
	DPSessionInfo* pDPSINext;
};

TCHAR				g_strSessionName[MAX_NAME];
TCHAR				g_strLocalPlayerName[MAX_NAME];
TCHAR				g_strPreferredProvider[MAX_NAME];
DWORD				g_dwNumberOfActivePlayers;
BOOL                g_bWaitForConnectionSettings;
BOOL				g_bHostPlayer;
DPID                g_LocalPlayerDPID; 

LPDIRECTPLAY4A		g_pDP					= NULL;
LPDPLCONNECTION		g_pDPLConnection		= NULL;
LPDIRECTPLAYLOBBY3	g_pDPLobby				= NULL;
HANDLE				g_hDPMessageEvent		= NULL;
HKEY				g_hDPlaySampleRegKey    = NULL;

DPSessionInfo       g_DPSIHead;
BOOL                g_bSearchingForSessions;


//////////////////////////////////////////////////////////////////////////////////////
// S T A R T		O F			C H A T			T E S T I N G			P U R P O S E

VOID*              g_pvDPMsgBuffer     = NULL;
DWORD              g_dwDPMsgBufferSize = 0;

//-----------------------------------------------------------------------------
// Name: DisplayNumberPlayersInChat()
// Desc: Displays the number of active players 
//-----------------------------------------------------------------------------
VOID DisplayNumberPlayersInChat( HWND hDlg )
{
    TCHAR strNumberPlayers[32];

    _stprintf( strNumberPlayers, _T("%d"), g_dwNumberOfActivePlayers );
    SetDlgItemText( hDlg, IDC_NUM_PLAYERS, strNumberPlayers );
}//end of DisplayNumberPlayersInChat
//-----------------------------------------------------------------------------
// Name: DPConnect_SessionsDlgCleanup()
// Desc: Deletes the linked list, g_DPSIHead
//-----------------------------------------------------------------------------
VOID DPConnect_SessionsDlgCleanup()
{
    DPSessionInfo* pDPSI = g_DPSIHead.pDPSINext;
    DPSessionInfo* pDPSIDelete;

    while ( pDPSI != &g_DPSIHead )
    {
        pDPSIDelete = pDPSI;       
        pDPSI = pDPSI->pDPSINext;

        SAFE_DELETE( pDPSIDelete );
    }

    // Re-link the g_DPSIHead circular linked list
    g_DPSIHead.pDPSINext = &g_DPSIHead;
}
//-----------------------------------------------------------------------------
// Name: DPConnect_EnumSessionsCallback()
// Desc: Enumerates the sessions, and stores them in the linked list, g_DPSIHead
//-----------------------------------------------------------------------------
BOOL FAR PASCAL DPConnect_EnumSessionsCallback( LPCDPSESSIONDESC2 pdpsd, 
                                                DWORD* pdwTimeout, 
                                                DWORD dwFlags, 
                                                VOID* pvContext )
{
    DPSessionInfo* pDPSINew = NULL;
    
    if( dwFlags & DPESC_TIMEDOUT )
        return FALSE; // The enumeration has timed out, so stop the enumeration.
    
    // Found a good session, save it
    pDPSINew = new DPSessionInfo; 
    if( NULL == pDPSINew )
        return FALSE;

    ZeroMemory( pDPSINew, sizeof(DPSessionInfo) );

    // Copy the information into pDPSINew
    pDPSINew->guidSession = pdpsd->guidInstance;
    _stprintf( pDPSINew->szSession, _T("%s (%d/%d)"), pdpsd->lpszSessionNameA, 
             pdpsd->dwCurrentPlayers, pdpsd->dwMaxPlayers );

    // Add pDPSINew to the circular linked list, g_pDPSIFirst
    pDPSINew->pDPSINext = g_DPSIHead.pDPSINext;
    g_DPSIHead.pDPSINext = pDPSINew;
    
    return TRUE;
}//end of DPConnect_EnumSessionsCallback

//-----------------------------------------------------------------------------
// Name: DPConnect_SessionsDlgInitListbox()
// Desc: Initializes the listbox
//-----------------------------------------------------------------------------
VOID DPConnect_SessionsDlgInitListbox( HWND hDlg )
{
    HWND          hWndListBox = GetDlgItem( hDlg, IDC_GAMES_LIST );
    LPDIRECTPLAY4 pDP = NULL;
    
    // Clear the contents from the list box, and display "Looking for modem session" text in listbox
    SendMessage( hWndListBox, LB_RESETCONTENT, 0, 0 );
    if( g_bSearchingForSessions )
    {
        SendMessage( hWndListBox, LB_ADDSTRING, 0, (LPARAM)"Looking for modem session..." );
    }
    else
    {
        SendMessage( hWndListBox, LB_ADDSTRING, 0, 
                     (LPARAM)"Click Create Session to create modem session."
                             "Click Dial to call host session." );
    }

    SendMessage( hWndListBox, LB_SETITEMDATA,  0, NULL );
    SendMessage( hWndListBox, LB_SETCURSEL,    0, 0 );

    // Disable the join button until sessions are found
    EnableWindow( GetDlgItem( hDlg, IDC_JOIN ), FALSE );
}//end of DPConnect_SessionsDlgInitListbox

//-----------------------------------------------------------------------------
// Name: DPConnect_SessionsDlgShowModemSession()
// Desc: Enumerates the DirectPlay sessions, and displays them in the listbox
//-----------------------------------------------------------------------------
HRESULT DPConnect_SessionsDlgShowModemSession( HWND hDlg )
{
    HRESULT        hr;
    HWND           hWndListBox = GetDlgItem( hDlg, IDC_GAMES_LIST );
    DPSESSIONDESC2 dpsd;
    DPSessionInfo* pDPSISelected = NULL;
    int            nItemSelected;
    GUID           guidSelectedSession;
    BOOL           bFindSelectedGUID;
    BOOL           bFoundSelectedGUID;

    // Try to keep the same session selected unless it goes away or 
    // there is no real session currently selected
    bFindSelectedGUID  = FALSE;
    bFoundSelectedGUID = TRUE;

    nItemSelected = SendMessage( hWndListBox, LB_GETCURSEL, 0, 0 );
    if( nItemSelected != LB_ERR )
    {
        pDPSISelected = (DPSessionInfo*) SendMessage( hWndListBox, LB_GETITEMDATA, 
                                                      nItemSelected, 0 );
        if( pDPSISelected != NULL )
        {
            guidSelectedSession = pDPSISelected->guidSession;
            bFindSelectedGUID = TRUE;
        }
    }
    
    // Remove the previous modem session from the linked list
    DPConnect_SessionsDlgCleanup();

    // Enum sessions and let DirectPlay decide the timeout
    ZeroMemory( &dpsd, sizeof(dpsd) );
    dpsd.dwSize          = sizeof(dpsd);
    dpsd.guidApplication = g_AppGUID;

    // Enumerate all the active DirectPlay games on the selected connection
    hr = g_pDP->EnumSessions( &dpsd, 0, DPConnect_EnumSessionsCallback, NULL, 
                              DPENUMSESSIONS_ALL | DPENUMSESSIONS_ASYNC );    
    if( FAILED(hr) )
    {
        if( hr == DPERR_USERCANCEL )
        {
            // The user canceled the DirectPlay connection dialog, so stop the search
            if( g_bSearchingForSessions )
            {
                CheckDlgButton( hDlg, IDC_SEARCH_CHECK, BST_UNCHECKED );
                SendMessage( hDlg, WM_COMMAND, IDC_SEARCH_CHECK, 0 );
            }

            return S_OK;
        }
        else 
        {
            DPConnect_SessionsDlgInitListbox( hDlg );
            if ( hr == DPERR_CONNECTING )
                return S_OK;

            return hr;
        }
    }

    // Tell listbox not to redraw itself since the contents are going to change
    SendMessage( hWndListBox, WM_SETREDRAW, FALSE, 0 );

    // Add the enumerated sessions to the listbox
    if( g_DPSIHead.pDPSINext != &g_DPSIHead )
    {
        // Clear the contents from the list box and enable the join button
        SendMessage( hWndListBox, LB_RESETCONTENT, 0, 0 );
        EnableWindow( GetDlgItem( hDlg, IDC_JOIN ), TRUE );
        
        DPSessionInfo* pDPSI = g_DPSIHead.pDPSINext;
        while ( pDPSI != &g_DPSIHead )
        {
            // Add session to the list box
            int nIndex = SendMessage( hWndListBox, LB_ADDSTRING, 0, 
                                      (LPARAM)pDPSI->szSession );
            SendMessage( hWndListBox, LB_SETITEMDATA, nIndex, (LPARAM)pDPSI );

            if( bFindSelectedGUID )
            {
                // Look for the session the was selected before
                if( pDPSI->guidSession == guidSelectedSession )
                {
                    SendMessage( hWndListBox, LB_SETCURSEL, nIndex, 0 );
                    bFoundSelectedGUID = TRUE;
                }
            }

            pDPSI = pDPSI->pDPSINext;
        }

        if( !bFindSelectedGUID || !bFoundSelectedGUID )
            SendMessage( hWndListBox, LB_SETCURSEL, 0, 0 );
    }
    else
    {
        // There are no active session, so just reset the listbox
        DPConnect_SessionsDlgInitListbox( hDlg );
    }

    // Tell listbox to redraw itself now since the contents have changed
    SendMessage( hWndListBox, WM_SETREDRAW, TRUE, 0 );
    InvalidateRect( hWndListBox, NULL, FALSE );

    return S_OK;
}//end of DPConnect_SessionsDlgShowModemSession
//-----------------------------------------------------------------------------
// Name: AddChatStringToListBox()
// Desc: Adds a string to the list box and ensures it is visible 
//-----------------------------------------------------------------------------
VOID AddChatStringToListBox( HWND hDlg, LPSTR strMsgText )
{
    // Add the message to the local listbox
    HWND hWndChatBox = GetDlgItem( hDlg, IDC_CHAT_LISTBOX );
    int nCount = SendMessage( hWndChatBox, LB_GETCOUNT, 0, 0 );
    if( nCount > MAX_CHAT_STRINGS )
        SendMessage( hWndChatBox, LB_DELETESTRING, 0, 0 );

    // Add it, and make sure it is visible
    int nIndex = SendMessage( hWndChatBox, LB_ADDSTRING, 0, (LPARAM)strMsgText );
    SendMessage( hWndChatBox, LB_SETTOPINDEX, nIndex, 0 );
}

//-----------------------------------------------------------------------------
// Name: HandleSystemMessages()
// Desc: Evaluates system messages and performs appropriate actions
//-----------------------------------------------------------------------------
HRESULT HandleSystemMessages( HWND hDlg, DPMSG_GENERIC* pMsg, DWORD dwMsgSize, 
                              DPID idFrom, DPID idTo )
{  
    switch( pMsg->dwType )
    {
        case DPSYS_CHAT:
            {
                DPMSG_CHAT* pChatMsg = (DPMSG_CHAT*) pMsg;
                DPCHAT* pChatStruct = pChatMsg->lpChat;

                // A chat string came in, so add it to the listbox
                AddChatStringToListBox( hDlg, pChatStruct->lpszMessageA );
            }
            break;

        case DPSYS_SESSIONLOST:
            // Non-host message.  This message is sent to all players 
            // when the host exits the modem session.
            if( g_bHostPlayer )
                return E_FAIL; // Sanity check

            PostQuitMessage( DPERR_SESSIONLOST );
            break;

        case DPSYS_CREATEPLAYERORGROUP:
            DPMSG_CREATEPLAYERORGROUP* pCreateMsg;
            pCreateMsg = (DPMSG_CREATEPLAYERORGROUP*) pMsg;

            // Update the number of active players
            g_dwNumberOfActivePlayers++;

            DisplayNumberPlayersInChat( hDlg );
            break;

        case DPSYS_DESTROYPLAYERORGROUP:
            DPMSG_DESTROYPLAYERORGROUP* pDeleteMsg;
            pDeleteMsg = (DPMSG_DESTROYPLAYERORGROUP*) pMsg;

            // Update the number of active players
            g_dwNumberOfActivePlayers--;

            DisplayNumberPlayersInChat( hDlg );
            break;
    }

    return S_OK;
}

//-----------------------------------------------------------------------------
// Name: ProcessDirectPlayMessages()
// Desc: Processes for DirectPlay messages
//-----------------------------------------------------------------------------
HRESULT ProcessDirectPlayMessages( HWND hDlg )
{
    DPID    idFrom;
    DPID    idTo;
    LPVOID  pvMsgBuffer;
    DWORD   dwMsgBufferSize;
    HRESULT hr;

    // Read all messages in queue
    dwMsgBufferSize = g_dwDPMsgBufferSize;
    pvMsgBuffer     = g_pvDPMsgBuffer;
    
    while( TRUE )
    {
        // See what's out there
        idFrom = 0;
        idTo   = 0;

        hr = g_pDP->Receive( &idFrom, &idTo, DPRECEIVE_ALL, 
                             pvMsgBuffer, &dwMsgBufferSize );

        if( hr == DPERR_BUFFERTOOSMALL )
        {
            // The current buffer was too small, 
            // so reallocate it and try again
            SAFE_DELETE_ARRAY( pvMsgBuffer );

            pvMsgBuffer = new BYTE[ dwMsgBufferSize ];
            if( pvMsgBuffer == NULL )
                return E_OUTOFMEMORY;

            // Save new buffer in globals
            g_pvDPMsgBuffer     = pvMsgBuffer;
            g_dwDPMsgBufferSize = dwMsgBufferSize;

            continue; // Now that the buffer is bigger, try again
        }

        if( DPERR_NOMESSAGES == hr )
            return S_OK;

        if( FAILED(hr) )
            return hr;

        // Handle the messages. If its from DPID_SYSMSG, its a system message, 
        // otherwise its an application message. 
        if( idFrom == DPID_SYSMSG )
        {
            hr = HandleSystemMessages( hDlg, (DPMSG_GENERIC*)pvMsgBuffer, 
                                       dwMsgBufferSize, idFrom, idTo );
            if( FAILED(hr) )
                return hr;
        }
        else
        {
            // This very simple client has no application defined DirectPlay messages.
            return E_FAIL;
        }
    }

    return S_OK;
}

//-----------------------------------------------------------------------------
// Name: SendChatMessage()
// Desc: Create chat string based on the editbox and send it to everyone 
//-----------------------------------------------------------------------------
HRESULT SendChatMessage( HWND hDlg )
{
    HRESULT hr;
    DPCHAT  dpc;
    TCHAR*  strEditboxBuffer = NULL;
    TCHAR*  strChatBuffer    = NULL;
    DWORD   dwEditboxBufferSize;
    DWORD   dwPlayerNameSize;
    DWORD   dwChatBufferSize;

    // Get length of item text
    dwEditboxBufferSize = SendDlgItemMessage( hDlg, IDC_CHAT_EDIT, 
                                              WM_GETTEXTLENGTH, 0, 0 );
    if( dwEditboxBufferSize == 0 )
        return S_OK;  // Don't do anything for blank messages 

    // Figure out how much room we need
    dwPlayerNameSize = lstrlen( g_strLocalPlayerName ) + 3;
    dwChatBufferSize = dwPlayerNameSize + dwEditboxBufferSize;

    // Make room for it
    strChatBuffer = (LPTSTR) new TCHAR[ dwChatBufferSize + 1 ];
    if( NULL == strChatBuffer )
        return E_OUTOFMEMORY;
    strEditboxBuffer = (LPTSTR) new TCHAR[ dwEditboxBufferSize + 1 ];
    if( NULL == strEditboxBuffer )
        return E_OUTOFMEMORY;

    // Make the chat string from the player's name and the edit box string
    GetDlgItemText( hDlg, IDC_CHAT_EDIT, strEditboxBuffer, dwEditboxBufferSize + 1 );
    _stprintf( strChatBuffer, _T("<%s> %s"), g_strLocalPlayerName, strEditboxBuffer );

    // Send the chat message to all of the other players
    ZeroMemory( &dpc, sizeof(DPCHAT) );
    dpc.dwSize       = sizeof(DPCHAT);

#ifdef _UNICODE
    dpc.lpszMessage  = strChatBuffer;
#else
	dpc.lpszMessageA = strChatBuffer;
#endif

    if( FAILED( hr = g_pDP->SendChatMessage( g_LocalPlayerDPID, DPID_ALLPLAYERS, 0, &dpc ) ) )
        return hr;

    // Add the chat message to the local listbox
    AddChatStringToListBox( hDlg, (LPSTR)strChatBuffer );

    // Cleanup
    SAFE_DELETE_ARRAY( strChatBuffer );
    SAFE_DELETE_ARRAY( strEditboxBuffer );
    SetDlgItemText( hDlg, IDC_CHAT_EDIT, _T("") );

    return S_OK;
}
//-----------------------------------------------------------------------------
// Name: OnInitDialog()
// Desc: Inits the dialog for the greeting game.
//-----------------------------------------------------------------------------
HRESULT OnInitDialog( HWND hDlg )
{
    DWORD           dwBufferSize;
    BYTE*           pData = NULL;
    DPSESSIONDESC2* pdpsd;
    HRESULT         hr;

    // Load and set the icon
    HINSTANCE hInst = (HINSTANCE) GetWindowLong( hDlg, GWL_HINSTANCE );
//    HICON hIcon = LoadIcon( hInst, MAKEINTRESOURCE( IDI_MAIN ) );
//    SendMessage( hDlg, WM_SETICON, ICON_BIG,   (LPARAM) hIcon );  // Set big icon
//    SendMessage( hDlg, WM_SETICON, ICON_SMALL, (LPARAM) hIcon );  // Set small icon

    // Get the size of the dpsd
    g_pDP->GetSessionDesc( NULL, &dwBufferSize );

    // Allocate space for it now that we know the size 
    pData = new BYTE[ dwBufferSize ];
    if( pData == NULL )
        return E_OUTOFMEMORY;

    // Now, get the dpsd in the buffer
    if( FAILED( hr = g_pDP->GetSessionDesc( pData, &dwBufferSize ) ) )
        return hr;

    // Typecast the data to a DPSESSIONDESC2* 
    pdpsd = (DPSESSIONDESC2*) pData;
    g_dwNumberOfActivePlayers = pdpsd->dwCurrentPlayers;

    // Update the dialog box
    DisplayNumberPlayersInChat( hDlg );

    // Set the default button id to be IDC_RETURN.  We handle in the dlg proc,
    // and make it send chat messages to all of the players
    SendMessage( hDlg, DM_SETDEFID, IDC_RETURN, 0L );
    SetFocus( GetDlgItem( hDlg, IDC_CHAT_EDIT ) );

    SendMessage( GetDlgItem( hDlg, IDC_CHAT_EDIT ), EM_SETEVENTMASK, 0, ENM_UPDATE );
    EnableWindow( GetDlgItem( hDlg, IDC_SEND ), FALSE );

    return S_OK;
}

//-----------------------------------------------------------------------------
// Name: ChatDlgProc()
// Desc: Handles dialog messages
//-----------------------------------------------------------------------------
BOOL CALLBACK ChatDlgProc( HWND hDlg, UINT msg, WPARAM wParam, LPARAM lParam )
{
    HRESULT hr;

    switch( msg ) 
    {
        case WM_INITDIALOG:
            {
                if( FAILED( hr = OnInitDialog( hDlg ) ) )
                    PostQuitMessage( EXITCODE_ERROR );
            }
            break;

        case WM_NOTIFY:
            if( LOWORD(wParam) == IDC_CHAT_EDIT ) 
            {
                EnableWindow( GetDlgItem( hDlg, IDC_SEND ), TRUE );
            }
            break;

        case WM_COMMAND:
            switch( LOWORD(wParam) )
            {
                case IDC_CHAT_EDIT:
                    if( HIWORD(wParam) == EN_UPDATE )
                    {
                        BOOL bEnableSend;
                        if( 0 == GetWindowTextLength( GetDlgItem( hDlg, IDC_CHAT_EDIT ) ) )
                            bEnableSend = FALSE;
                        else
                            bEnableSend = TRUE;

                        EnableWindow( GetDlgItem( hDlg, IDC_SEND ), bEnableSend );
                    }
                    break;

                case IDC_SEND:
                case IDC_RETURN:
                    // The enter key was pressed, so send out the chat message
                    if( FAILED( hr = SendChatMessage( hDlg ) ) )
                        PostQuitMessage( EXITCODE_ERROR );
                    break;

                case IDCANCEL:
                    PostQuitMessage( EXITCODE_QUIT );
                    return TRUE;
            }
            break;
    }

    return FALSE; // Didn't handle message
}


//-----------------------------------------------------------------------------
// Name: DoChatClient()
// Desc: Creates the main game window, and process Windows and DirectPlay messages
//-----------------------------------------------------------------------------
int DoChatClient( HINSTANCE hInst )
{
    HWND    hDlg = NULL;
    BOOL    bDone = FALSE;
    int     nExitCode;
    HRESULT hr; 
    DWORD   dwResult;
    MSG     msg;

    if( g_pDP == NULL )
        return E_FAIL;  // Sanity check

    // Display the greeting game dialog box.
    hDlg = CreateDialog( hInst, MAKEINTRESOURCE(IDD_MAIN_GAME), 
                         NULL, (DLGPROC)ChatDlgProc );

    while( !bDone ) 
    { 
        dwResult = MsgWaitForMultipleObjects( 1, &g_hDPMessageEvent, 
                                              FALSE, INFINITE, QS_ALLEVENTS );
        switch( dwResult )
        {
            case WAIT_OBJECT_0 + 0:
                // g_hDPMessageEvent is signaled, so there are
                // DirectPlay messages available
                if( FAILED( hr = ProcessDirectPlayMessages( hDlg ) ) ) 
                    return EXITCODE_ERROR;
                break;

            case WAIT_OBJECT_0 + 1:
                // Windows messages are available
                while( PeekMessage( &msg, NULL, 0, 0, PM_REMOVE ) ) 
                { 
                    if( !IsDialogMessage( hDlg, &msg ) )  
                    {
                        TranslateMessage( &msg ); 
                        DispatchMessage( &msg ); 
                    }

                    if( msg.message == WM_QUIT )
                    {
                        // See the above EXITCODE #defines for 
                        // what nExitCode could be 
                        nExitCode = msg.wParam;

                        EndDialog( hDlg, nExitCode );
                        bDone = TRUE;
                    }
                }
                break;
        }
    }

    return nExitCode;
}
// E N D		O F			C H A T			T E S T I N G			P U R P O S E
//////////////////////////////////////////////////////////////////////////////////////

//-----------------------------------------------------------------------------
// Name: WriteRegKey()
// Desc: Writes a registry key 
//-----------------------------------------------------------------------------
HRESULT WriteRegKey( HKEY hKey, TCHAR* strName, TCHAR* strValue )
{
	LONG bResult;

	bResult = RegSetValueEx( hKey, strName, 0, REG_SZ, (LPBYTE)strValue, lstrlen(strValue) + 1 );
	if ( bResult != ERROR_SUCCESS )
		return E_FAIL;

    return S_OK;
}

//-----------------------------------------------------------------------------
// Name: ReadRegKey()
// Desc: Read a registry key 
//-----------------------------------------------------------------------------
HRESULT ReadRegKey( HKEY hKey, TCHAR* strName, TCHAR* strValue, 
                    DWORD dwLength, TCHAR* strDefault )
{
	DWORD dwType;
	LONG bResult;

	bResult = RegQueryValueEx( hKey, strName, 0, &dwType, 
							 (LPBYTE) strValue, &dwLength );
	if ( bResult != ERROR_SUCCESS )
		lstrcpy( strValue, strDefault );

    return S_OK;
}//end of ReadRegKey
//-----------------------------------------------------------------------------
// Name: DPConnect_EnumConnectionsCallback()
// Desc: Enumerates through all DirectPlay connections types, 
//       and stores them in the listbox
//-----------------------------------------------------------------------------
BOOL FAR PASCAL DPConnect_EnumConnectionsCallback( LPCGUID   pguidSP, 
                                                   VOID*     pConnection, 
                                                   DWORD     dwConnectionSize, 
                                                   LPCDPNAME pName, 
                                                   DWORD     dwFlags, 
                                                   VOID*     pvContext )
{
    HRESULT       hr;
    LPDIRECTPLAY4 pDP = NULL;
    VOID*         pConnectionBuffer = NULL;
    HWND          hWndListBox = (HWND)pvContext;
    LRESULT       iIndex;

    // Create a IDirectPlay object
    if( FAILED( hr = CoCreateInstance( CLSID_DirectPlay, NULL, CLSCTX_ALL, 
                                       IID_IDirectPlay4A, (VOID**)&pDP ) ) )
        return FALSE; // Error, stop enumerating
    
    // Test the if the connection is available by attempting to initialize 
    // the connection
    if( FAILED( hr = pDP->InitializeConnection( pConnection, 0 ) ) )
    {
        SAFE_RELEASE( pDP );
        return TRUE; // Unavailable connection, keep enumerating
    }

    // Don't need the IDirectPlay interface anymore, so release it
    SAFE_RELEASE( pDP ); 
    
    // Found a good connection, so put it in the listbox
    iIndex = SendMessage( hWndListBox, LB_ADDSTRING, 0, 
                          (LPARAM)pName->lpszShortNameA );
    if( iIndex == CB_ERR )
        return FALSE; // Error, stop enumerating

    pConnectionBuffer = new BYTE[ dwConnectionSize ];
    if( pConnectionBuffer == NULL )
        return FALSE; // Error, stop enumerating

    // Store pointer to GUID in listbox
    memcpy( pConnectionBuffer, pConnection, dwConnectionSize );
    SendMessage( hWndListBox, LB_SETITEMDATA, iIndex, (LPARAM)pConnectionBuffer );

    return TRUE; // Keep enumerating
}//end of DPConnect_EnumConnectionsCallback
//-----------------------------------------------------------------------------
// Name: DPConnect_GetLobbyConnectionSettingsMessage()
// Desc: Attepts to get a lobby connection settings message.  If it does 
//       it returns S_OK otherwise it returns S_FALSE 
//-----------------------------------------------------------------------------
HRESULT DPConnect_GetLobbyConnectionSettingsMessage()
{
    HRESULT hr = NOERROR;
    LPVOID  pvMsgBuffer = NULL;
    DWORD   dwMsgBufferSize = 0;
    DWORD   dwMsgFlags;

    while( 1 )
    {
        hr = g_pDPLobby->ReceiveLobbyMessage( 0, 0, &dwMsgFlags, pvMsgBuffer, &dwMsgBufferSize );
        if( hr == DPERR_BUFFERTOOSMALL ) 
        {
            // The current buffer was too small, 
            // so reallocate it and try again
            SAFE_DELETE_ARRAY( pvMsgBuffer );

            pvMsgBuffer = new BYTE[ dwMsgBufferSize ];
            if( pvMsgBuffer == NULL )
                return E_OUTOFMEMORY;

            continue; // Now that the buffer is bigger, try again
        }

        if( DPERR_NOMESSAGES == hr )
            break;

        if( FAILED(hr) )
            break;

        // Found a messages, check to see if its a CONNECTIONSETTINGS message
        if( dwMsgFlags & DPLMSG_SYSTEM )
        {
            // If it is found then stop looking for it
            if( ( (DPLMSG_GENERIC*)pvMsgBuffer)->dwType == DPLSYS_NEWCONNECTIONSETTINGS )
                break;
        }
    }//end of while - TRUE

    // Cleanup buffer
    SAFE_DELETE_ARRAY( pvMsgBuffer );

    // Return S_FALSE if there we no connection settings messages
    if( DPERR_NOMESSAGES == hr )
        return S_FALSE;

    // If the message was recieved the hr should be S_OK
    return hr; 
}//end of DPConnect_GetLobbyConnectionSettingsMessage

//-----------------------------------------------------------------------------
// Name: DPConnect_LobbyWaitDlgProc()
// Desc: Handles dialog messages.  This dialog starts a timer that attempts to
//       either receive a lobby connection settings message or 
//       connect to new session via the lobby connection depending on the 
//       g_bWaitForConnectionSettings flag.
//-----------------------------------------------------------------------------
BOOL CALLBACK DPConnect_LobbyWaitDlgProc( HWND hDlg, UINT msg, WPARAM wParam, LPARAM lParam )
{
    static HRESULT* phr = NULL;

    switch( msg )
    {
        case WM_INITDIALOG:
            // Save the HRESULT pointer
            phr = (HRESULT*)lParam;           

            if( g_bWaitForConnectionSettings )
                SetDlgItemText( hDlg, IDC_WAIT_TEXT, TEXT("Waiting for connection...") );
            else
                SetDlgItemText( hDlg, IDC_WAIT_TEXT, TEXT("Finding Modem Session...") );

            // Create a timer.  The dialog will attempt to connect at every WM_TIMER
            SetTimer( hDlg, 0, 250, NULL );
            break;

        case WM_DESTROY:
            KillTimer( hDlg, 0 );
            break;

        case WM_TIMER:
            // Attempt to connect to the modem session
            if( g_bWaitForConnectionSettings )
            {
                *phr = DPConnect_GetLobbyConnectionSettingsMessage();
                if( *phr == S_OK )
                    EndDialog( hDlg, 0 );
            }
            else
            {
                *phr = g_pDPLobby->ConnectEx( DPCONNECT_RETURNSTATUS, IID_IDirectPlay4A, 
                                              (VOID**)&g_pDP, NULL );
                if( *phr == DPERR_CONNECTING )
                    break; // Try again on the next WM_TIMER message

                EndDialog( hDlg, 0 );
            }

            break;
        
        case WM_COMMAND:
            switch( LOWORD(wParam) )
            {
                case IDCANCEL:
                    // the async Connect will be stopped when the
                    // IDirectPlayLobby3 interface is released.
                    
                    // Set the HRESULT to user cancel and close the dialog
                    *phr = DPERR_USERCANCEL;
                    EndDialog( hDlg, 0 );
                    break;

                default:
                    return FALSE; // Message not handled
            }
            break;

        default:
            return FALSE; // Message not handled
    }//end of switch - msg
    return TRUE; // Message handled
}//end of DPConnect_LobbyWaitDlgProc

//-----------------------------------------------------------------------------
// Name: DPConnect_DoLobbyLaunch()
// Desc: The app was launched by the lobby server, so connect to the session
//       and create the player
//-----------------------------------------------------------------------------
HRESULT DPConnect_DoLobbyLaunch()
{
    HRESULT hr;

    // Detrimine if this is the host player 
    g_bHostPlayer = ( (g_pDPLConnection->dwFlags & DPLCONNECTION_CREATESESSION) != 0 );

    // Set our session flags
    g_pDPLConnection->lpSessionDesc->dwFlags = DPSESSION_KEEPALIVE | DPSESSION_MIGRATEHOST;

    // Let lobby know our connection flags
    if( FAILED( hr = g_pDPLobby->SetConnectionSettings( 0, 0, g_pDPLConnection ) ) )
        return hr;

    // If we're hosting, just call ConnectEx syncronously.  Otherwise, display
    // the connecting dialog and do the connect asynchronously.
    if( g_bHostPlayer )
    {
        // Connect to the lobby syncronously
        if( FAILED( hr = g_pDPLobby->ConnectEx( 0, IID_IDirectPlay4A, (VOID**)&g_pDP, NULL ) ) )
            return hr;
    }
    else
    {
        // Use the IDD_LOBBY_WAIT_STATUS dialog to attempt to connect to 
        // the new session
        g_bWaitForConnectionSettings = FALSE;

        // Connect to the lobby asyncronously
        DialogBoxParam( NULL, MAKEINTRESOURCE( IDD_COMM_WAITING ), NULL,
                        (DLGPROC)DPConnect_LobbyWaitDlgProc, (LPARAM)&hr );
        if( FAILED(hr) )
            return hr; // This may be DPERR_USERCANCEL if the user canceled the dialog
    }

#ifdef _UNICODE
    lstrcpy( g_strLocalPlayerName, g_pDPLConnection->lpPlayerName->lpszShortName );
#else
	lstrcpy( g_strLocalPlayerName, g_pDPLConnection->lpPlayerName->lpszShortNameA );
#endif

    // Create our player
    DPNAME dpname;
    ZeroMemory( &dpname, sizeof(DPNAME) );
    dpname.dwSize         = sizeof(DPNAME);

#ifdef _UNICODE
    dpname.lpszShortName  = g_strLocalPlayerName;
#else
	dpname.lpszShortNameA  = g_strLocalPlayerName;
#endif

    if( FAILED( hr = g_pDP->CreatePlayer( &g_LocalPlayerDPID, &dpname, 
                                          g_hDPMessageEvent, NULL, 0, 0 ) ) )
        return hr;

    // Successfully lobby launch, note that we don't release the lobby object
    return S_OK;
}//end of DPConnect_DoLobbyLaunch

//-----------------------------------------------------------------------------
// Name: DPConnect_CheckForLobbyLaunch()
// Desc: Determines if we were launched by a lobby. If so, gets the connection
//       settings and creates our player using the information from the lobby
//-----------------------------------------------------------------------------
HRESULT DPConnect_CheckForLobbyLaunch( BOOL* pbLaunchedByLobby )
{
    HRESULT hr;
    DWORD   dwSize;

    if( NULL == pbLaunchedByLobby ) 
        return E_FAIL;

    // Create a new lobby object
    SAFE_RELEASE( g_pDPLobby );
    if( FAILED( hr = CoCreateInstance( CLSID_DirectPlayLobby, NULL,
                                       CLSCTX_INPROC_SERVER, IID_IDirectPlayLobby3A,
                                       (VOID**)&g_pDPLobby ) ) )
    {
        if( hr == E_NOINTERFACE )
        {
            MessageBox( NULL, TEXT("This application requires DirectPlay 6 or later. The sample will now quit."),
                        TEXT("DirectPlay Sample"), MB_OK | MB_ICONERROR );
        }
        return hr;
    }

    // Get connection settings from the lobby (into g_pdplConnection)
    hr = g_pDPLobby->GetConnectionSettings( 0, NULL, &dwSize );
    if( FAILED(hr) && (DPERR_BUFFERTOOSMALL != hr) )
    {
        if( DPERR_NOTLOBBIED == hr )
        {
            *pbLaunchedByLobby = FALSE;

            // Cleanup since we were not launched from the lobby
            SAFE_DELETE_ARRAY( g_pDPLConnection );
            SAFE_RELEASE( g_pDPLobby );

            return S_OK;
        }
        return hr; 
    }

    // Allocate memory for the connection
    SAFE_DELETE_ARRAY( g_pDPLConnection );
    g_pDPLConnection = (DPLCONNECTION*)new BYTE[ dwSize ];

    // Get the connection settings
    if( FAILED( hr = g_pDPLobby->GetConnectionSettings(0, g_pDPLConnection, &dwSize) ) )
        return hr;

    *pbLaunchedByLobby = TRUE;

    if( FAILED( hr = DPConnect_DoLobbyLaunch() ) )
    {
        // Cleanup 
        SAFE_DELETE_ARRAY( g_pDPLConnection );
        SAFE_RELEASE( g_pDPLobby );

        return hr; // This may be DPERR_USERCANCEL if the user canceled the dialog
    }

    return S_OK;
}//end of DPConnect_CheckForLobbyLaunch
//-----------------------------------------------------------------------------
// Name: DPConnect_WaitForLobbyLaunch()
// Desc: Wait for the a lobby connection and connect when found
//-----------------------------------------------------------------------------
HRESULT DPConnect_WaitForLobbyLaunch( HWND hDlg )
{
    HRESULT hr;
    BOOL    bLaunchedByLobby;

    // Create a new lobby object
    SAFE_RELEASE( g_pDPLobby );

    if( FAILED( hr = CoCreateInstance( CLSID_DirectPlayLobby, NULL,
                                       CLSCTX_INPROC_SERVER, IID_IDirectPlayLobby3A,
                                       (VOID**)&g_pDPLobby ) ) )
        return hr;

    // Put the application into wait mode
    if( FAILED( hr = g_pDPLobby->WaitForConnectionSettings( 0 ) ) )
        return hr;

    // Use the IDD_LOBBY_WAIT_STATUS dialog to check for a connection message
    g_bWaitForConnectionSettings = TRUE;

    EnableWindow( hDlg, FALSE );
/*** save
	g_Modem.hWaitDlg = CreateDialog(g_Modem.hInst,      // Application instance handle
									MAKEINTRESOURCE(IDD_COMM_WAITING),
									hDlg, // Parent window handle
									(DLGPROC)(BaseLineHVDlgProc)
								);
*** save ***/
    // Display a dialog box and wait for the connection settings
    DialogBoxParam( NULL, MAKEINTRESOURCE( IDD_COMM_WAITING ), hDlg,
                    (DLGPROC)DPConnect_LobbyWaitDlgProc, (LPARAM)&hr );
   
    EnableWindow( hDlg, TRUE );

    if( FAILED(hr) )
    {
        g_pDPLobby->WaitForConnectionSettings( DPLWAIT_CANCEL );
        SAFE_RELEASE( g_pDPLobby );

        return hr;
    }

    // The lobby server has launched the session, so check for a lobby
    // launch to continue on to connect to the session and create the player
    if( FAILED( hr = DPConnect_CheckForLobbyLaunch( &bLaunchedByLobby ) ) )
        return hr; // This may be DPERR_USERCANCEL if the user canceled the dialog

    return S_OK;
}//end of DPConnect_WaitForLobbyLaunch
//-----------------------------------------------------------------------------
// Name: DPConnect_SessionsDlgCreateModemSession()
// Desc: Asks the user the session name, and creates a new DirectPlay session
//-----------------------------------------------------------------------------
HRESULT DPConnect_SessionsDlgCreateModemSession( HWND hDlg )
{
    DPSESSIONDESC2 dpsd;
    DPNAME         dpname;
    HRESULT        hr;
    int            nResult = 0;; 
    HINSTANCE      hInst;

    hInst = (HINSTANCE) GetWindowLong( hDlg, GWL_HINSTANCE );

    // Display a modal multiplayer connect dialog box.
    EnableWindow( hDlg, FALSE ); 
//    nResult = DialogBox( hInst, MAKEINTRESOURCE(IDD_MULTIPLAYER_CREATE), 
//                         hDlg, DPConnect_CreateSessionDlgProc );
    EnableWindow( hDlg, TRUE ); 

//    if( nResult == IDCANCEL )
//        return S_OK;

    // Setup the DPSESSIONDESC2 based on g_AppGUID, and g_strSessionName.
    // The DPSESSION_KEEPALIVE flag keeps the session alive if players abnormally exit
    ZeroMemory( &dpsd, sizeof(dpsd) );
    dpsd.dwSize           = sizeof(dpsd);
    dpsd.guidApplication  = g_AppGUID;

#ifdef _UNICODE
    dpsd.lpszSessionName = g_strSessionName;
#else
	dpsd.lpszSessionNameA = g_strSessionName;
#endif
	
    dpsd.dwMaxPlayers     = 10;
    dpsd.dwFlags          = DPSESSION_KEEPALIVE | DPSESSION_MIGRATEHOST;
//    if( g_bUseProtocol )
    dpsd.dwFlags |= DPSESSION_DIRECTPLAYPROTOCOL;

    // Create a new session
    g_bHostPlayer = TRUE;
	 
    if( FAILED( hr = g_pDP->Open( &dpsd, DPOPEN_CREATE ) ) )
        return hr;

    // Create player based on g_strLocalPlayerName.  
    // Store the player's DPID in g_LocalPlayerDPID.
    // Also all DirectPlay messages for this player will signal g_hDPMessageEvent
    ZeroMemory( &dpname, sizeof(DPNAME) );
    dpname.dwSize         = sizeof(DPNAME);

#ifdef _UNICODE
    dpname.lpszShortName = g_strLocalPlayerName;
#else
	dpname.lpszShortNameA = g_strLocalPlayerName;
#endif

    if( FAILED( hr = g_pDP->CreatePlayer( &g_LocalPlayerDPID, &dpname, 
                                          g_hDPMessageEvent, NULL, 0, 
                                          DPPLAYER_SERVERPLAYER ) ) )
        return hr;

    // DirectPlay connect successful, so end dialog
    EndDialog( hDlg, EXITCODE_FORWARD );

    return S_OK;
}
//-----------------------------------------------------------------------------
// Name: DPConnect_ConnectionsDlgCleanup()
// Desc: Deletes the connection buffers from the listbox
//-----------------------------------------------------------------------------
VOID DPConnect_ConnectionsDlgCleanup( HWND hDlg )
{
    VOID*   pConnectionBuffer = NULL;
    DWORD   iIndex;
    DWORD   dwCount;

    HWND hWndListBox = GetDlgItem( hDlg, IDC_CONNECTION_LIST );

    dwCount = SendMessage( hWndListBox, LB_GETCOUNT, 0, 0 );
    for( iIndex = 0; iIndex < dwCount; iIndex++ )
    {
        pConnectionBuffer = (VOID*) SendMessage( hWndListBox, LB_GETITEMDATA, 
                                                 iIndex, 0 );
        SAFE_DELETE_ARRAY( pConnectionBuffer );
    }
}
//-----------------------------------------------------------------------------
// Name: DPConnect_ConnectionsDlgOnOK()
// Desc: Stores the player name g_strPlayerName, and in creates a IDirectPlay
//       object based on the connection type the user selected. 
//-----------------------------------------------------------------------------
HRESULT DPConnect_ConnectionsDlgOnOK( HWND hDlg )
{
    VOID*   pConnection = NULL;
    LRESULT iIndex;
    HRESULT hr;

    GetDlgItemText( hDlg, IDC_PLAYER_NAME_EDIT, g_strLocalPlayerName, MAX_NAME );
    if( lstrlen( g_strLocalPlayerName ) == 0 )
    {
        MessageBox( hDlg, TEXT("You must enter a valid player name."),
                    TEXT("DirectPlay Sample"), MB_OK );
        return S_OK;
    }

    HWND hWndListBox = GetDlgItem( hDlg, IDC_CONNECTION_LIST );

    iIndex = SendMessage( hWndListBox, LB_GETCURSEL, 0, 0 );
    SendMessage( hWndListBox, LB_GETTEXT, iIndex, (LPARAM)g_strPreferredProvider );

    pConnection = (VOID*) SendMessage( hWndListBox, LB_GETITEMDATA, iIndex, 0 );
    if( NULL == pConnection )
    {
        if( FAILED( hr = DPConnect_WaitForLobbyLaunch( hDlg ) ) )
        {
            if( hr == DPERR_USERCANCEL )
                return S_OK;

            return hr;
        }

        EndDialog( hDlg, EXITCODE_LOBBYCONNECT );
        return S_OK;
    }

    // Release previously selected DirectPlay object, if any.
    SAFE_RELEASE( g_pDP );

    // Create the DirectPlay object
    if( FAILED( hr = CoCreateInstance( CLSID_DirectPlay, NULL, CLSCTX_ALL, 
                                       IID_IDirectPlay4A, (VOID**)&g_pDP ) ) )
        return hr;
    
    // Initialize the connection based on the selected connection type
    if( FAILED( hr = g_pDP->InitializeConnection( pConnection, 0 ) ) )
        return hr;

    EndDialog( hDlg, EXITCODE_FORWARD );

    return S_OK;
}//end of DPConnect_ConnectionsDlgOnOK
//-----------------------------------------------------------------------------
// Name: DPConnect_ConnectionsDlgFillListBox()
// Desc: Fills the DirectPlay connection listbox, and also adds
//       a "Wait for Lobby" connection option.
//-----------------------------------------------------------------------------
HRESULT DPConnect_ConnectionsDlgFillListBox( HWND hDlg )
{
    HRESULT       hr;
    HWND          hWndListBox = GetDlgItem( hDlg, IDC_CONNECTION_LIST );
    LPDIRECTPLAY4 pDP = NULL;
    int           nIndex;

    // Create a IDirectPlay object
    if( FAILED( hr = CoCreateInstance( CLSID_DirectPlay, NULL, CLSCTX_ALL, 
                                       IID_IDirectPlay4A, (VOID**)&pDP ) ) )
    {
        if( hr == E_NOINTERFACE )
        {
            MessageBox( NULL, TEXT("This application requires DirectPlay 6 or later. The sample will now quit."),
                        TEXT("DirectPlay Sample"), MB_OK | MB_ICONERROR );
        }

        return hr;
    }

    // Enumerate all DirectPlay connections, and store them in the listbox
    if( FAILED( hr = pDP->EnumConnections( &g_AppGUID, DPConnect_EnumConnectionsCallback, 
                                           hWndListBox, 0 ) ) )
    {
        SAFE_RELEASE( pDP );
        return hr;
    }

    SAFE_RELEASE( pDP );
    
    // Add "Wait for Lobby Connection" selection in list box
    SendMessage( hWndListBox, LB_ADDSTRING, 0, (LPARAM)"Wait for Lobby Connection" );

    SetFocus( hWndListBox );
    nIndex = SendMessage( hWndListBox, LB_FINDSTRINGEXACT, (WPARAM)-1, 
                          (LPARAM)g_strPreferredProvider );
    if( nIndex != LB_ERR ) 
        SendMessage( hWndListBox, LB_SETCURSEL, nIndex, 0 );
    else
        SendMessage( hWndListBox, LB_SETCURSEL, 0, 0 );

    return S_OK;
}


//-----------------------------------------------------------------------------
// Name: DPConnect_ConnectionsDlgProc()
// Desc: Handles messages for the multiplayer connect dialog
//-----------------------------------------------------------------------------
BOOL CALLBACK DPConnect_ConnectionsDlgProc( HWND hDlg, UINT msg, WPARAM wParam, LPARAM lParam )
{
    HRESULT hr;

    switch( msg )
    {
        case WM_INITDIALOG:
            {
                SetDlgItemText( hDlg, IDC_PLAYER_NAME_EDIT, g_strLocalPlayerName );

                // Load and set the icon
                HINSTANCE hInst = (HINSTANCE) GetWindowLong( hDlg, GWL_HINSTANCE );

                if( FAILED( hr = DPConnect_ConnectionsDlgFillListBox( hDlg ) ) )
                    EndDialog( hDlg, EXITCODE_ERROR );

				SendMessage( hDlg, WM_COMMAND, IDOK, 0 ); // Do IDOK 
            }
            break;

        case WM_COMMAND:
            switch( LOWORD(wParam) )
            {
                case IDC_CONNECTION_LIST:
                    if( HIWORD(wParam) != LBN_DBLCLK )
                        break;
                    // Fall through

                case IDOK:
                    if( FAILED( hr = DPConnect_ConnectionsDlgOnOK( hDlg ) ) )
                        EndDialog( hDlg, EXITCODE_ERROR );

                    break;

                case IDCANCEL:
                    EndDialog( hDlg, EXITCODE_QUIT );
                    break;

                default:
                    return FALSE; // Message not handled
            }
            break;
        
        case WM_DESTROY:
            DPConnect_ConnectionsDlgCleanup( hDlg );
            break;

        default:
            return FALSE; // Message not handled
    }

    // Message was handled
    return TRUE; 
}
//-----------------------------------------------------------------------------
// Name: DPConnect_SessionsDlgJoinModemSession()
// Desc: Joins the selected DirectPlay session
//-----------------------------------------------------------------------------
HRESULT DPConnect_SessionsDlgJoinModemSession( HWND hDlg )
{
    DPSESSIONDESC2 dpsd;
    DPNAME         dpname;
    HRESULT        hr;
    HWND           hWndListBox = GetDlgItem( hDlg, IDC_GAMES_LIST );
    DPSessionInfo* pDPSISelected = NULL;
    int            nItemSelected;

    nItemSelected = SendMessage( hWndListBox, LB_GETCURSEL, 0, 0 );
    
    // Add status text in list box
    pDPSISelected = (DPSessionInfo*) SendMessage( hWndListBox, LB_GETITEMDATA, 
                                                  nItemSelected, 0 );

    if( NULL == pDPSISelected )
    {
        MessageBox( hDlg, TEXT("There are no modem session to join."), TEXT("ACG"), MB_OK );
        return S_OK;
    }

    // Setup the DPSESSIONDESC2, and get the session guid from 
    // the selected listbox item
    ZeroMemory( &dpsd, sizeof(dpsd) );
    dpsd.dwSize          = sizeof(dpsd);
    dpsd.guidInstance    = pDPSISelected->guidSession;
    dpsd.guidApplication = g_AppGUID;

    // Join the session
    g_bHostPlayer = FALSE;
    if( FAILED( hr = g_pDP->Open( &dpsd, DPOPEN_JOIN ) ) )
        return hr;

    // Create player based on g_strLocalPlayerName.  
    // Store the player's DPID in g_LocalPlayerDPID.
    // Also all DirectPlay messages for this player will signal g_hDPMessageEvent
    ZeroMemory( &dpname, sizeof(DPNAME) );
    dpname.dwSize         = sizeof(DPNAME);

#ifdef _UNICODE
    dpname.lpszShortName  = g_strLocalPlayerName;
#else
	dpname.lpszShortNameA  = g_strLocalPlayerName;
#endif
    
    if( FAILED( hr = g_pDP->CreatePlayer( &g_LocalPlayerDPID, &dpname, g_hDPMessageEvent, NULL, 0, 0 ) ) )
        return hr;

    // DirectPlay connect successful, so end dialog
    EndDialog( hDlg, EXITCODE_FORWARD );

    return S_OK;
}
//-----------------------------------------------------------------------------
// Name: DPConnect_SessionsDlgProc()
//-----------------------------------------------------------------------------
BOOL CALLBACK DPConnect_SessionsDlgProc( HWND hDlg, UINT msg, WPARAM wParam, LPARAM lParam )
{
    HRESULT hr;
	DWORD	rv;

    switch( msg )
    {
        case WM_INITDIALOG:
            {
                // Load and set the icon
                HINSTANCE hInst = (HINSTANCE) GetWindowLong( hDlg, GWL_HINSTANCE );

                g_bSearchingForSessions = FALSE;
                SetDlgItemText( hDlg, IDC_SEARCH_CHECK, _T("Start Search") );
                DPConnect_SessionsDlgInitListbox( hDlg );

//testing only
	// Check is auto listening mode
				SetTimer( hDlg, 101, 3000, NULL );
				SetTimer( hDlg, 102, 5000, NULL );
/**
if( FAILED( hr = DPConnect_SessionsDlgCreateModemSession( hDlg ) ) )
{
     MessageBox( hDlg, TEXT("Unable to create Modem Session."),
                TEXT("ACG"), MB_OK | MB_ICONERROR );
}
**/
//HWND hMod = FindWindow( "Dialog", "Modem Connection" );
//HWND hBut = FindWindow( "Button", "Answer..." );
//LONG AnsID = GetWindowLong( hBut, GWL_ID );
//SendMessage( hMod, WM_COMMAND, AnsID, 0 );
//end of testing oonly

            }
            break;

        case WM_TIMER:
			switch( wParam )
			{
			case 1:
				{
					if( FAILED( hr = DPConnect_SessionsDlgShowModemSession( hDlg ) ) )
					{
						KillTimer( hDlg, 1 );
						MessageBox( hDlg, TEXT("Error enumerating DirectPlay modem session."),
									TEXT("ACG"), MB_OK | MB_ICONERROR );
					}

					if( IsWindowEnabled( GetDlgItem( hDlg, IDC_JOIN ) ) )
						SendMessage( hDlg, WM_COMMAND, IDC_JOIN, 0 ); // Do the Join Session
				}//end of case 1
				break;
			case 101:
				{
					KillTimer( hDlg, 101 );
					HWND hMod = FindWindow( NULL, _T("Modem Session") );
					SendMessage( hMod, WM_COMMAND, IDC_CREATE, 0 );					
				}//end of case 101
				break;
			case 102:
				{
					KillTimer( hDlg, 102 );
					HWND hDPDlg = FindWindow( NULL, _T("Modem Connection") );
					if( hDPDlg == NULL )
						rv = GetLastError();
					HWND hBut = FindWindowEx( hDPDlg, NULL, NULL, _T("Answer...") );
					if( hBut == NULL )
						rv = GetLastError();
					LONG AnsID = GetWindowLong( hBut, GWL_ID );
					SendMessage( hDPDlg, WM_COMMAND, AnsID, 0 );
				}// end of case 102
				break;
			}//end of switch

            break;

        case WM_COMMAND:
            switch( LOWORD(wParam) )
            {
                case IDC_SEARCH_CHECK:
                    g_bSearchingForSessions = !g_bSearchingForSessions;

                    if( g_bSearchingForSessions )
                    {
                        // Start the timer, and start the async enumeratation
                        SetDlgItemText( hDlg, IDC_SEARCH_CHECK, _T("Searching...") );
                        SetTimer( hDlg, 1, 250, NULL );
                        if( FAILED( hr = DPConnect_SessionsDlgShowModemSession( hDlg ) ) )
                        {
                            KillTimer( hDlg, 1 );
                            MessageBox( hDlg, TEXT("Error enumerating DirectPlay Modem Session."),
                                        TEXT("ACG"), MB_OK | MB_ICONERROR );
                        }
//							SendMessage( hDlg, WM_COMMAND, IDC_JOIN, 0 ); // Do the Join Session
                    }
                    else
                    {
                        // Stop the timer, and stop the async enumeration
                        KillTimer( hDlg, 1 );

                        DPSESSIONDESC2 dpsd;
                        ZeroMemory( &dpsd, sizeof(dpsd) );
                        dpsd.dwSize          = sizeof(dpsd);
                        dpsd.guidApplication = g_AppGUID;
                        hr = g_pDP->EnumSessions( &dpsd, 0, DPConnect_EnumSessionsCallback, 
                                                  NULL,  DPENUMSESSIONS_STOPASYNC );
                        if( hr != DPERR_GENERIC && FAILED(hr) ) 
                            EndDialog( hDlg, EXITCODE_ERROR );

                        SetDlgItemText( hDlg, IDC_SEARCH_CHECK, _T("Start Search") );

                        DPConnect_SessionsDlgInitListbox( hDlg );
                    }
					
                    break;

                case IDC_GAMES_LIST:
                    if( HIWORD(wParam) != LBN_DBLCLK )
                        break;
                    // Fall through

                case IDC_JOIN:
                    if( FAILED( hr = DPConnect_SessionsDlgJoinModemSession( hDlg ) ) )
                    {
                        MessageBox( hDlg, TEXT("Unable to join Modem Session."),
                                    TEXT("ACG"), MB_OK | MB_ICONINFORMATION );
                    }                    
                    break;

                case IDC_CREATE:
                    if( FAILED( hr = DPConnect_SessionsDlgCreateModemSession( hDlg ) ) )
                    {
                        MessageBox( hDlg, TEXT("Unable to create Modem Session."),
                                    TEXT("ACG"), MB_OK | MB_ICONINFORMATION );
                    }
                    break;

                case IDCANCEL: // The close button was press
                    EndDialog( hDlg, EXITCODE_QUIT );
//                    break;
                case IDC_BACK: // "Cancel" button was pressed
                    EndDialog( hDlg, EXITCODE_QUIT );
                    break;

                default:
                    return FALSE; // Message not handled
            }
            break;
        
        case WM_DESTROY:
            KillTimer( hDlg, 1 );                    
            DPConnect_SessionsDlgCleanup();
            break;

        default:
            return FALSE; // Message not handled
    }

    // Message was handled
    return TRUE; 
}



//-----------------------------------------------------------------------------
// Name: DPConnect_StartDirectPlayConnect()
// Desc: Prompts the user for the DirectPlay connection and the DirectPlay 
//       session they want to join or create.  This function returns one
//       of the EXITCODEs as #defined above
//-----------------------------------------------------------------------------
int DPConnect_StartDirectPlayConnect( HINSTANCE hInst, BOOL bBackTrack = FALSE )
{
    int nExitCode;
    int nStep;

    // Setup the g_DPSIHead circular linked list
    ZeroMemory( &g_DPSIHead, sizeof( DPSessionInfo ) );
    g_DPSIHead.pDPSINext = &g_DPSIHead;
    
    // If the back track flag is true, then the user has already been through
    // the connect process once, and has back tracked out of the main 'game' 
    // so we need start at the last dialog box
    if( bBackTrack )
        nStep = 1;
    else
        nStep = 0;

    // Show the dialog boxes to connect
    while( TRUE )
    {
        switch( nStep )
        {
            case 0:
                nExitCode = DialogBox( hInst, MAKEINTRESOURCE(IDD_MUTLIPLAYER_CONNECT), 
                                       NULL, (DLGPROC)DPConnect_ConnectionsDlgProc );
                break;

            case 1:
                nExitCode = DialogBox( hInst, MAKEINTRESOURCE(IDD_COMM_MODEM), 
                                       NULL, (DLGPROC)DPConnect_SessionsDlgProc );
                break;
        }

        if( nExitCode == EXITCODE_ERROR || nExitCode == EXITCODE_QUIT )
            return nExitCode;

        if( nExitCode == EXITCODE_BACKUP )
            nStep--;
        else
            nStep++;

        if( nExitCode == EXITCODE_LOBBYCONNECT )
            return EXITCODE_LOBBYCONNECT;

        if( nStep == 2 )
            break;
    }

    return EXITCODE_FORWARD;
}


//-----------------------------------------------------------------------------
// Name: DoConnectAndModem()
// Desc: Connect to other players using DirectPlay.
//-----------------------------------------------------------------------------
HRESULT DoConnectAndModem( HINSTANCE hInst )
{
    int     nExitCode;
    HRESULT hr;
    BOOL    bLaunchedByLobby;

    // See if we were launched from a lobby server
    hr = DPConnect_CheckForLobbyLaunch( &bLaunchedByLobby );
    if( FAILED(hr) )
    {
        if( hr == DPERR_USERCANCEL )
            return S_OK;

        return hr;
    }

    if( !bLaunchedByLobby )
    {
        // If not, the first step is to prompt the user about the network 
        // connection and which session they would like to join or 
        // if they want to create a new one.
        nExitCode = DPConnect_StartDirectPlayConnect( hInst, FALSE );

        // See the above EXITCODE #defines for what nExitCode could be 
        if( nExitCode == EXITCODE_QUIT )
        {
            // The user canceled the mutliplayer connect.
            // The sample will now quit.
            return E_ABORT;
        }

        if( nExitCode == EXITCODE_ERROR || g_pDP == NULL )
        {
            MessageBox( NULL, TEXT("Mutliplayer connect failed. The sample will now quit."),
                        TEXT("DirectPlay Sample"), MB_OK | MB_ICONERROR );
            return E_FAIL;
        }
    }

    // The next step is to start the game
    nExitCode = DoChatClient( hInst );

    if( nExitCode == EXITCODE_ERROR )
    {
        MessageBox( NULL, _T("An error occured during the game. The sample will now quit."),
                    TEXT("DirectPlay Sample"), MB_OK | MB_ICONERROR );
        return E_FAIL;
    }

    return S_OK;
}



//////////////////////////////////////////////////////////////////////////////////////
// E N D		D I R E C T P L A Y			 S E C T I O N S
//////////////////////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////////////////
// S T A R T		 G U I		 C O N T R O L		 S E C T I O N
//////////////////////////////////////////////////////////////////////////////////////
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
VOID SetModemStaticText( HWND hDlg, TCHAR* ptLn )
{
	TCHAR	sep[] = _T("\"");
	TCHAR*	ptID;
	TCHAR*	ptText;
	TCHAR*	ptEnd;
//	BOOL	rv;
	
	ptID   = _tcstok( ptLn, sep );
	ptText = _tcstok( NULL, sep );
	ptEnd  = _tcstok( NULL, sep );
	if( ptEnd != NULL )
		*ptEnd = '\0';
/***************
	if( NULL != _tcsstr( ptID, (TCHAR*)"IDC_STC_FILE" ) )
		SetDlgItemText( hDlg, IDC_STC_FILE, (LPCTSTR)ptText );
	else
		if( NULL != _tcsstr( ptID, (TCHAR*)"IDC_STC_ORIG_SIZE" ) )
			SetDlgItemText( hDlg, IDC_STC_ORIG_SIZE, (LPCTSTR)ptText );
	else
		if( NULL != _tcsstr( ptID, (TCHAR*)"IDC_STC_ED_WIN_SIZE" ) )
			SetDlgItemText( hDlg, IDC_STC_ED_WIN_SIZE, (LPCTSTR)ptText );
	else
		if( NULL != _tcsstr( ptID, (TCHAR*)"IDC_GP_LD_SIZE" ) )
			SetDlgItemText( hDlg, IDC_GP_LD_SIZE, (LPCTSTR)ptText );
	else
		if( NULL != _tcsstr( ptID, (TCHAR*)"IDC_RB_ORIG_SIZE" ) )
			SetDlgItemText( hDlg, IDC_RB_ORIG_SIZE, (LPCTSTR)ptText );
	else
		if( NULL != _tcsstr( ptID, (TCHAR*)"IDC_RB_FIT_ED_WIN" ) )
			SetDlgItemText( hDlg, IDC_RB_FIT_ED_WIN, (LPCTSTR)ptText );
	else
		if( NULL != _tcsstr( ptID, (TCHAR*)"IDC_CK_A_CH_INCLUDE" ) )
			SetDlgItemText( hDlg, IDC_CK_A_CH_INCLUDE, (LPCTSTR)ptText );
	else
		if( NULL != _tcsstr( ptID, (TCHAR*)"IDC_CK_A_CH_INVERT" ) )
			SetDlgItemText( hDlg, IDC_CK_A_CH_INVERT, (LPCTSTR)ptText );
	else
		if( NULL != _tcsstr( ptID, (TCHAR*)"IDC_CK_BLACK_TRIM" ) )
			SetDlgItemText( hDlg, IDC_CK_BLACK_TRIM, (LPCTSTR)ptText );
	else
		if( NULL != _tcsstr( ptID, (TCHAR*)"IDC_GP_POSITION" ) )
			SetDlgItemText( hDlg, IDC_GP_POSITION, (LPCTSTR)ptText );
	else
		if( NULL != _tcsstr( ptID, (TCHAR*)"IDOK" ) )
			SetDlgItemText( hDlg, IDOK, (LPCTSTR)ptText );
	else
		if( NULL != _tcsstr( ptID, (TCHAR*)"IDCANCEL" ) )
			rv = SetDlgItemText( hDlg, IDCANCEL, (LPCTSTR)ptText ); 
	else
		if( NULL != _tcsstr( ptID, (TCHAR*)"IDC_DLG_TITLE" ) )
			rv = SetWindowText( hDlg, (LPCTSTR)ptText ); // set dialog title
************/
}//end of SetModemStaticText
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// Max. nubmer of static text for reciver dialog is ???
BOOL InitModemStaticText( HWND hDlg )
{
	TCHAR   szFullName[MAX_PATH];
	TCHAR	bufStr[MAX_PATH];
	FILE*	inFile;

	lstrcat( (LPTSTR)szFullName, _T("\\Util\\CommReciver.ctl") ); // need to change to download.ctl??
	if( NULL == (inFile = _tfopen((LPTSTR)szFullName, _T("r"))) )
	{
		MessageBox( NULL, _T("File not found."), _T("Warning"), MB_ICONSTOP|MB_OK );
		return( 1 );
	}
	while( !feof( inFile ) )
	{
		if( NULL == _fgetts( bufStr, MAX_PATH, inFile ) )
		{
			fclose( inFile );
			return( 1 );// error
		}//end of if 

		if( NULL != _tcsstr( bufStr, _T("[Static Text") ) )
		{
			while( NULL != _fgetts( bufStr, MAX_PATH, inFile ) )
			{
				if( NULL == _tcsstr( bufStr, _T("end")) )
					SetModemStaticText( hDlg, bufStr );
				else
					break;
			}//end of while
		}//end of if
	}//end of while

	fclose( inFile );
	return( 0 ); // normal
}//end of InitModemStaticText
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// Set font for all control - increase numCtrl when add new control
VOID InitModemDlgControlFont( HWND hDlg )
{
	const int numCtrl = 25; // total 65 controls
	HWND hFont = NULL;
	HWND hCtrl = NULL;
/***	
	for( int i = 0; i < numCtrl; i++ )
	{
		hCtrl = GetDlgItem( hDlg, IDC_STC_FILE + i );
		ChangeControlFont( hCtrl, hFont, UILang_UIFont,0, UILang_UIFontSize, FW_NORMAL);
	}//end of for
***/
}//end of InitModemDlgControlFont
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// Free resource
VOID OnModemDlgDestroy( )
{
	// destroy all windows which are created by CreateDialog or CreateWindow API
	if( g_Modem.hHook )
	{
		UnhookWindowsHookEx( g_Modem.hHook );
	}
	if( g_Modem.hWnd != NULL )
	{
		DestroyWindow( g_Modem.hWnd );
		g_Modem.hWnd = NULL;
	}
}//end of OnModemDlgDestroy
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
VOID OnListening( HWND hDlg )
{
    HRESULT hr;

    // Read information from registry
    RegCreateKeyEx( HKEY_CURRENT_USER, DPLAY_SAMPLE_KEY, 0, NULL,
                    REG_OPTION_NON_VOLATILE, KEY_ALL_ACCESS, NULL, 
                    &g_hDPlaySampleRegKey, NULL );

    ReadRegKey( g_hDPlaySampleRegKey, _T("Player Name"), g_strLocalPlayerName, MAX_NAME, _T("") );
    ReadRegKey( g_hDPlaySampleRegKey, _T("Session Name"), g_strSessionName, MAX_NAME, _T("") );
    ReadRegKey( g_hDPlaySampleRegKey, _T("Preferred Provider"), g_strPreferredProvider, MAX_NAME, _T("") );

    g_hDPMessageEvent = CreateEvent( NULL, FALSE, FALSE, NULL );

    if( FAILED( hr = CoInitialize( NULL ) ) )
        return;

    hr = DoConnectAndModem( g_Modem.hInst );
    if( SUCCEEDED( hr ) )
    {
        // Write information to the registry
        WriteRegKey( g_hDPlaySampleRegKey, _T("Player Name"), g_strLocalPlayerName );
        WriteRegKey( g_hDPlaySampleRegKey, _T("Session Name"), g_strSessionName );
        WriteRegKey( g_hDPlaySampleRegKey, _T("Preferred Provider"), g_strPreferredProvider );
    }

    // Cleanup DirectPlay
    if( g_pDP )
    {
        g_pDP->DestroyPlayer( g_LocalPlayerDPID );
        g_pDP->Close();

        SAFE_DELETE_ARRAY( g_pDPLConnection );
        SAFE_RELEASE( g_pDPLobby );
        SAFE_RELEASE( g_pDP );
    }

    CoUninitialize();

    CloseHandle( g_hDPlaySampleRegKey );
    CloseHandle( g_hDPMessageEvent );

    return;
}//end of OnListening
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
static VOID OnCancel( HWND hDlg )
{
//	if( WSACleanup() != 0 )
//	{
//		DisplayWSAError();
//		return;
//	}

//	EnableWindow( GetDlgItem(hDlg,IDOK), 1 );
//	g_Modem.szFullUrl[0] = '\0';
//	g_Modem.szUrl[0]		= '\0';
	OnModemDlgDestroy( );
}//end of OnCancel
//+++++++++++++++++++++++++++++++++++++++++++++++++++++ CreateReciverDlg()
// INPUT : HWND ParentHwnd - The big window ??
// INPUT : HINSTANCE - ?????
BOOL CreateCommModemDlg(HINSTANCE HInst, HWND ParentHwnd)
{
	BOOL	rv = 0;
	g_Modem.hInst      = HInst;
	g_Modem.parenthWnd = ParentHwnd;

	OnListening( ParentHwnd );

	return( rv );
}//end of CreateCommModemDlg

//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
VOID DisplayDPOpenError( HRESULT hr )
{
	switch( hr )
	{
	case DPERR_ACCESSDENIED:
		break;
	case DPERR_ALREADYINITIALIZED:
		break;
	case DPERR_AUTHENTICATIONFAILED:
		break;
	case DPERR_CANNOTCREATESERVER:
		break;
	case DPERR_CANTCREATEPLAYER:
		break;
	case DPERR_CANTLOADCAPI:
		break;
	case DPERR_CANTLOADSECURITYPACKAGE:
		break;
	case DPERR_CANTLOADSSPI:
		break;
	case DPERR_CONNECTING:
		break;
	case DPERR_CONNECTIONLOST: 
		break;
	case DPERR_ENCRYPTIONFAILED:
		break;
	case DPERR_ENCRYPTIONNOTSUPPORTED:
		break;
	case DPERR_INVALIDFLAGS:
		break;
	case DPERR_INVALIDPARAMS:
		break;
	case DPERR_INVALIDPASSWORD:
		break;
	case DPERR_LOGONDENIED:
		break;
	case DPERR_NOCONNECTION:
		break;
	case DPERR_NONEWPLAYERS: 
		break;
	case DPERR_NOSESSIONS:
		break;
	case DPERR_SIGNFAILED:
		break;
	case DPERR_TIMEOUT:
		break;
	case DPERR_UNINITIALIZED:
		break;
	case DPERR_USERCANCEL:
		break;
	}//end of switch



}//end of DisplayDPOpenError