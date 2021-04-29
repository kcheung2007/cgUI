#include "stdafx.h"
#include "afxpriv.h"

#include "winsock.h"
#include "Communicate.h"
#include "mbstring.h"

#include <tchar.h>
#include <COMMCTRL.H>
#include "resource.h"
#include "stdio.h"

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// Doing client connection - connect to remote host
// When a network client wants to connect to a server, it must have:
// 1.) a TCP port number (gotten via getservbyname()) and
// 2.) an IP address of the remote host (gotten via gethostbyname()).
// The following summarizes the steps used to connect:
// - Get the name of the remote host computer (store in "g_szBuff", name or IP)
// - Check to see if the hosts file knows the computer (gethostbyname)
// - Get the host information (hostent structure filled)
// - Fill in the address of the remote host into the servent structure (memcpy)
// - Get the NAME of the port to connect to the remote host from the user.
// - Get the port number (getservbyname)
// - Fill in the port number of the servent structure
// - Establish a connection (connect)
// RETURN : 1 - Success; 0 - Fail
BOOL ConnectToHost( HWND hDlg )
{
	char			szTemp[255];
	SOCKADDR_IN		destSin;  // DESTination Socket INternet	
	PSOCKADDR_IN	pDestSin = &destSin;

	// Get the name of the remote host. Store the string in szBuff.
	GetDlgItemText( hDlg, IDC_ED_HOST_ID, (LPTSTR)g_szBuff, NAME_LEN );
	if( g_szBuff == "" )
		return( 0 );

	g_Sock = socket( AF_INET, SOCK_STREAM, 0 );
    if( g_Sock == INVALID_SOCKET )
	{
		MessageBox(hDlg, _T("socket() failed"), _T("Error"), MB_OK);
        return( 0 );
	}

    // Retrieve the IP address and TCP Port number
    // Global variable szBuff contains the remote host name.
	pDestSin->sin_family = AF_INET;
    g_pHostEnt = gethostbyname( g_szBuff );

	if( g_pHostEnt == NULL )
	{
		sprintf(szTemp, "%d is the error. Make sure '%s' is listed in the hosts file.", WSAGetLastError(), g_szBuff);
        MessageBox( hDlg, (LPCTSTR)szTemp, _T("gethostbyname() failed."), MB_OK );         
		return( 0 );
	}      
	memcpy( (char FAR *)&(pDestSin->sin_addr), g_pHostEnt->h_addr, g_pHostEnt->h_length );
   
	// Retrieve the Port number - actual port number
	int port = GetDlgItemInt( hDlg, IDC_CB_PORT_NUM, NULL, 1 );
	pDestSin->sin_port = htons( port );   // Convert to network ordering 

	if( connect( g_Sock, (PSOCKADDR)&destSin, sizeof(SOCKADDR_IN) ) < 0 )
	{
		closesocket( g_Sock );
        MessageBox( hDlg, _T("connect() failed"), _T("Error"), MB_OK );
		return( 0 );
	}
    
    // Send main window a WSA_READ when either data is pending on
    // the socket (FD_READ) or the connection is closed (FD_CLOSE)
	if( 0 < WSAAsyncSelect(g_Sock, hDlg, WSA_READ, FD_READ | FD_CLOSE) )
	{  
		wsprintf( (LPTSTR)szTemp, _T("%d (0x%x)") );
        MessageBox( hDlg, _T("Error on WSAAsyncSelect()"), (LPCTSTR)szTemp, MB_OK );
        closesocket( g_Sock );
		return( 0 );
	}
	return( 1 ); // Success - Connection
}//end of ConnectToHost
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
VOID ReadSocketData( HWND hDlg, WPARAM wParam, LPARAM lParam )
{
	char	szTemp[ MSG_LENGTH ];
	int		rv;

	if( WSAGETSELECTEVENT(lParam) == FD_READ )
	{
         rv = recv( (SOCKET)wParam, szTemp, MSG_LENGTH, NO_FLAGS_SET );
         if( rv ) 
		 {
            szTemp[rv] = '\0';
			MessageBox( NULL, (LPCTSTR)szTemp, _T("WSA_READ"), MB_OK );
         }
         else
            MessageBox( hDlg, _T("Connection broken"), _T("Error"), MB_OK );
	}//end of if - FD_READ
	else
		MessageBox( hDlg, _T("Connection lost"), _T("WSA_READ"), MB_OK );
}// end of ReadSocketData

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
VOID SendSocketMessage( HWND hDlg, DWORD ctrlID )
{
	char	szMsg[MSG_LENGTH];

	GetDlgItemText( hDlg, ctrlID, (LPTSTR)szMsg, MSG_LENGTH );
	send( g_Sock, szMsg, strlen(szMsg), NO_FLAGS_SET );
	SetDlgItemText( hDlg, ctrlID, _T("") );
	SetFocus( GetDlgItem( hDlg, ctrlID ) );
}//end of SendMessage

//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// RETURN : 1 = Success, 0 = Fail
BOOL AcceptConnection( HWND hDlg, LPARAM lParam )
{
	SOCKADDR_IN	accSin;		// Accept socket address - internet style
	int			accSinLen;	// Accept socket address length
	int			rv = 0;

	if( WSAGETSELECTERROR( lParam ) == 0 ) // Success
	{   
		// Accept the incoming connection.
        accSinLen = sizeof( accSin );
        g_Sock = accept( g_Sock,(struct sockaddr FAR *) &accSin, (int FAR *)&accSinLen );
        
		if( g_Sock < 0 )
		{
            sprintf( g_szBuff, "%d is the error", WSAGetLastError() );
            MessageBox( hDlg, (LPCTSTR)g_szBuff, _T("accept(sock) failed"), MB_OK );
            return( 0 );
		}    

        // Send main window a WSA_READ when either data is pending on
        // the socket (FD_READ) or the connection is closed (FD_CLOSE)
        if( 0 < WSAAsyncSelect( g_Sock, hDlg, WSA_READ, FD_READ | FD_CLOSE ) ) 
		{
           wsprintf( (LPTSTR)g_szBuff, _T("%d (0x%x)"), rv, rv );
           MessageBox( hDlg, _T("Error on WSAAsyncSelect()"), (LPTSTR)g_szBuff, MB_OK);
           closesocket( g_Sock );
		   return( 0 );
        }
		// handle GUI
		return( 1 );
//		SetWindowText( hDlg, "Connection Accepted!");
//		SetDlgItemText( hDlg, IDCANCEL, "Disconnect" );
	}//end of if - Success
    else 
	{         
		MessageBox(hDlg, _T("accept()"), _T("Error occured!"), MB_OK);
     
		//   Cancel any further notifications.
        WSAAsyncSelect( g_Sock, hDlg, 0, 0);
        SetWindowText( hDlg, _T("Async Listen call canceled"));
		return( 0 );
	}
}//end of AcceptConnection
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
VOID AsynListen( HWND hDlg )
{	
	DWORD			dwSize;	
	SOCKADDR_IN		locSockIn;
	PSOCKADDR_IN	pLocSin = &locSockIn;
	INT				rv;

	g_Sock = socket( AF_INET, SOCK_STREAM, 0);    
	if( g_Sock == INVALID_SOCKET )
	{            
		MessageBox( hDlg, _T("socket() failed"), _T("Error"), MB_OK );
		return;         
	}

	SetWindowText( hDlg, _T("Waiting for connection.. (Async)") );

	// Retrieve the IP address and TCP Port number
	pLocSin->sin_family = AF_INET;

    dwSize = sizeof( g_szBuff );
    gethostname( g_szBuff, dwSize );
    pLocSin->sin_addr.s_addr = INADDR_ANY;

	//Retrieve the Port number
	int port = GetDlgItemInt( hDlg, IDC_CB_TCP_PORT, NULL, 1 );
	pLocSin->sin_port = htons( port );   // Convert to network ordering 

	// Bind the socket address
    if( bind(g_Sock, (struct sockaddr FAR *)&locSockIn, sizeof(SOCKADDR_IN)) == SOCKET_ERROR ) 
	{
		sprintf( g_szBuff, "%d is the error", WSAGetLastError() );
        MessageBox( hDlg, (LPCTSTR)g_szBuff, _T("bind(g_Sock) failed"), MB_OK );
        closesocket( g_Sock );
        return;
	}// end of binding socket

	// Listening
	if( listen( g_Sock, MAX_PENDING_CONNECTS ) < 0 ) 
	{    
		sprintf( g_szBuff, "%d is the error", WSAGetLastError() );
        MessageBox( hDlg, (LPCTSTR)g_szBuff, _T("listen(g_Sock) failed"), MB_OK );
        return;
	}// end of if - listening

	// Send WSA_ACCEPT message when something is trying to connect.
	rv = WSAAsyncSelect(g_Sock, hDlg, WSA_ACCEPT, FD_ACCEPT);
	if( 0 < rv )
	{            
		wsprintf( (LPTSTR)g_szBuff, _T("%d (0x%x)"));
        MessageBox( hDlg, _T("Error on WSAAsyncSelect()"), (LPTSTR)g_szBuff, MB_OK);
        SetWindowText( hDlg, _T("Async listen cancelled") );
        closesocket( g_Sock );         
	}//end of if - accepting incoming call

}//end of AsynListen

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
VOID DisplayWSAError( )
{
	_TCHAR	szTemp[80];
	INT		eCode = WSAGetLastError();
	switch( eCode )
	{
	case WSANOTINITIALISED:
		lstrcpy( szTemp, _T("WSA has not initialized yet.") );
		break;
	case WSASYSNOTREADY:
		lstrcpy( szTemp, _T("Network subsystem is not ready for network communication.") );
		break;
	case WSAVERNOTSUPPORTED:
		lstrcpy( szTemp, _T("Unsupport version of WinSock.") );
		break;
	case WSAEINPROGRESS:
		lstrcpy( szTemp, _T("A blocking Windows Sockets 1.1 operation is in progress.") );
		break;
	case WSAENETDOWN:
		lstrcpy( szTemp, _T("The network subsystem has failed.") );
		break;
	case WSAHOST_NOT_FOUND:
		lstrcpy( szTemp, _T("Authoritative Answer Host not found.") );
		break;
	case WSATRY_AGAIN:
		lstrcpy( szTemp, _T("Server failure. Try again later.") );
		break;
	default:
		_stprintf( szTemp, _T("%d is the err"), eCode );
	}//end of switch - eCode

	MessageBox( NULL, szTemp, _T("Message"), MB_OK|MB_ICONINFORMATION );
}//end of DisplayWSAError