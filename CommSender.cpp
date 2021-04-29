// char b[20];
// _itoa( i, b, 10 );
// MessageBox( NULL, b, "Kentest", MB_OK );
#include "stdafx.h"
#include "afxpriv.h"

#include "winsock.h"
#include "Communicate.h"
#include "mbstring.h"

#include <tchar.h>
#include <COMMCTRL.H>
#include "resource.h"
#include "stdio.h"
#include "FileReq.h"

struct COMM_SENDER
{
	BOOL		nResult; // return value from Dialog Box
	HINSTANCE	hInst;
	HWND		hWnd;
	HHOOK		hHook;
	HWND		parenthWnd, edit_hWnd;
};

static  COMM_SENDER		g_Sender;

//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
VOID SetSenderStaticText( HWND hDlg, TCHAR* ptLn )
{
	TCHAR		sep[] = _T("\"");
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
	if( NULL != _tcsstr( ptID, _T("IDC_STC_FILE") ) )
		SetDlgItemText( hDlg, IDC_STC_FILE, (LPCTSTR)ptText );
	else
		if( NULL != _tcsstr( ptID, _T("IDC_STC_ORIG_SIZE") ) )
			SetDlgItemText( hDlg, IDC_STC_ORIG_SIZE, (LPCTSTR)ptText );
	else
		if( NULL != _tcsstr( ptID, _T("IDC_STC_ED_WIN_SIZE") ) )
			SetDlgItemText( hDlg, IDC_STC_ED_WIN_SIZE, (LPCTSTR)ptText );
	else
		if( NULL != _tcsstr( ptID, _T("IDC_GP_LD_SIZE") ) )
			SetDlgItemText( hDlg, IDC_GP_LD_SIZE, (LPCTSTR)ptText );
	else
		if( NULL != _tcsstr( ptID, _T("IDC_RB_ORIG_SIZE") ) )
			SetDlgItemText( hDlg, IDC_RB_ORIG_SIZE, (LPCTSTR)ptText );
	else
		if( NULL != _tcsstr( ptID, _T("IDC_RB_FIT_ED_WIN") ) )
			SetDlgItemText( hDlg, IDC_RB_FIT_ED_WIN, (LPCTSTR)ptText );
	else
		if( NULL != _tcsstr( ptID, _T("IDC_CK_A_CH_INCLUDE") ) )
			SetDlgItemText( hDlg, IDC_CK_A_CH_INCLUDE, (LPCTSTR)ptText );
	else
		if( NULL != _tcsstr( ptID, _T("IDC_CK_A_CH_INVERT") ) )
			SetDlgItemText( hDlg, IDC_CK_A_CH_INVERT, (LPCTSTR)ptText );
	else
		if( NULL != _tcsstr( ptID, _T("IDC_CK_BLACK_TRIM") ) )
			SetDlgItemText( hDlg, IDC_CK_BLACK_TRIM, (LPCTSTR)ptText );
	else
		if( NULL != _tcsstr( ptID, _T("IDC_GP_POSITION") ) )
			SetDlgItemText( hDlg, IDC_GP_POSITION, (LPCTSTR)ptText );
	else
		if( NULL != _tcsstr( ptID, _T("IDOK") ) )
			SetDlgItemText( hDlg, IDOK, (LPCTSTR)ptText );
	else
		if( NULL != _tcsstr( ptID, _T("IDCANCEL") ) )
			rv = SetDlgItemText( hDlg, IDCANCEL, (LPCTSTR)ptText ); 
	else
		if( NULL != _tcsstr( ptID, _T("IDC_DLG_TITLE") ) )
			rv = SetWindowText( hDlg, (LPCTSTR)ptText ); // set dialog title
************/
}//end of SetSenderStaticText
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// Max. nubmer of static text for reciver dialog is ???
BOOL InitSenderStaticText( HWND hDlg )
{
	TCHAR		szFullName[MAX_PATH];
	TCHAR		bufStr[MAX_PATH];
	FILE*		inFile;

	lstrcat( szFullName, _T("\\Util\\CommReciver.ctl") );
	if( NULL == (inFile = _tfopen(szFullName, _T("r"))) )
	{
		MessageBox( NULL, _T("File not found."), _T("Warning"), MB_ICONSTOP|MB_OK );
		return( 1 );
	}
	while( !feof( inFile ) )
	{
		if( NULL == fgets( (CHAR*)bufStr, MAX_PATH, inFile ) )
		{
			fclose( inFile );
			return( 1 );// error
		}//end of if 

		if( NULL != _tcsstr( bufStr, _T("[Static Text") ) )
		{
			while( NULL != fgets( (CHAR*)bufStr, MAX_PATH, inFile ) )
			{
				if( NULL == _tcsstr( bufStr, _T("end") ) )
					SetSenderStaticText( hDlg, bufStr );
				else
					break;
			}//end of while
		}//end of if
	}//end of while

	fclose( inFile );
	return( 0 ); // normal
}//end of InitSenderStaticText
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// Disable all control in message group
static VOID DisableMessageControl( HWND hDlg )
{
	EnableWindow( GetDlgItem(hDlg, IDC_GP_MSG),  0 );
	EnableWindow( GetDlgItem(hDlg, IDC_ED_MSG),  0 );
	EnableWindow( GetDlgItem(hDlg, IDC_BT_SEND), 0 );
}//end of DisableMessageControl
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// Enable all control in message group
static VOID EnableMessageControl( HWND hDlg )
{
	EnableWindow( GetDlgItem(hDlg, IDC_GP_MSG),  1 );
	EnableWindow( GetDlgItem(hDlg, IDC_ED_MSG),  1 );
	EnableWindow( GetDlgItem(hDlg, IDC_BT_SEND), 1 );
}//end of DisableMessageControl
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// Set font for all control - increase numCtrl when add new control
VOID InitSenderDlgControlFont( HWND hDlg )
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
}//end of InitSenderDlgControlFont
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
static VOID OnOK( HWND hDlg )
{	
	if( ConnectToHost( hDlg ) ) // Success - Connection
	{
		SetWindowText( hDlg, _T("Sender - Connected with Host") );
		EnableMessageControl( hDlg );
	}
}//end of OnOK
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
static VOID OnCancel( HWND hDlg )
{
	if( WSACleanup() != 0 )
		DisplayWSAError();

	EndDialog( hDlg, 0 );
}//end of OnCancel
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// NOTE : Pre-defined TCP Port number. If other device using these port number
// for their communication, user need to change to other.
// Initialize all controls and GUI 
void OnInitSenderDlg( HWND hDlg )
{	
	int rv;
	g_Sender.hWnd = hDlg;

//	CenterDialog( hDlg );

	//----------- Initial Combo box
	HWND hPortNum = GetDlgItem( hDlg, IDC_CB_TCP_PORT );
	SendDlgItemMessage( hDlg, IDC_CB_PORT_NUM, CB_ADDSTRING, 0, (LONG)_T("5050") );
	SendDlgItemMessage( hDlg, IDC_CB_PORT_NUM, CB_ADDSTRING, 0, (LONG)_T("6060") );
	SendDlgItemMessage( hDlg, IDC_CB_PORT_NUM, CB_ADDSTRING, 0, (LONG)_T("7070") );
	SendDlgItemMessage( hDlg, IDC_CB_PORT_NUM, CB_ADDSTRING, 0, (LONG)_T("8080") );
	SendDlgItemMessage( hDlg, IDC_CB_PORT_NUM, CB_SETCURSEL, 0, NULL );
	
	//----------- Disable all message control in message group
	DisableMessageControl( hDlg );

    if( (rv = WSAStartup(MAKEWORD(2,2), &g_wsaData) ) != 0 )
		DisplayWSAError();

	SetFocus( GetDlgItem(hDlg, IDC_ED_HOST_ID) );	
}//end of OnInitSenderDlg
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
BOOL CALLBACK SenderProc(HWND hDlg,UINT uMsg,WPARAM wParam,LPARAM lParam)
{
	int		i = 0;

	switch( uMsg )
	{
		case WM_INITDIALOG:
			OnInitSenderDlg( hDlg );
			break;
		case WM_COMMAND:
			{
				switch( LOWORD(wParam) )
				{
				case IDOK: // do connection
					OnOK( hDlg );
					break;
				case IDCANCEL:
					OnCancel( hDlg );
					break;
				case IDC_BT_SEND:
					SendSocketMessage( hDlg, IDC_ED_MSG );
					break;
				}//end of switch
			}//end of WM_COMMAND
			break;
		case WM_DESTROY:
//			OnLoadPicDlgDestroy( hDlg );
			break;
		case WSA_READ: // Notify if data is waiting on a socket. This comes from WSAAsyncSelect().
			ReadSocketData( hDlg, wParam, lParam );
			break;
		case WM_MOUSEMOVE:
			break;

		default:
			break;

	}//end of switch - uMsg

	return( 0 );
}//end of CALLBACK SenderProc

//+++++++++++++++++++++++++++++++++++++++++++++++++++++ CreateReciverDlg()
// INPUT : HWND ParentHwnd - The big window ??
// INPUT : HINSTANCE - ?????
BOOL CreateCommSenderDlg(HINSTANCE HInst, HWND ParentHwnd)
{
	BOOL	rv = 0;
	g_Sender.hInst      = HInst;
	g_Sender.parenthWnd = ParentHwnd;
//	g_Sender.edit_hWnd  = Edit_hWnd;

	rv = DialogBox( HInst,      // Application instance handle
		  			MAKEINTRESOURCE(IDD_COMM_SENDER),
					ParentHwnd, // Parent window handle
					(DLGPROC)(SenderProc)
				);

	return( rv );
}//end of CreateCommSenderDlg

