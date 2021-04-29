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


struct COMM_RECIVER
{
	BOOL		nResult; // return value from Dialog Box
	HINSTANCE	hInst;
	HWND		hWnd;
	HHOOK		hHook;
	HWND		parenthWnd, edit_hWnd;
};

static  COMM_RECIVER	g_Reciver;
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
VOID SetReciverStaticText( HWND hDlg, TCHAR* ptLn )
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
}//end of SetReciverStaticText
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// Max. nubmer of static text for reciver dialog is ???
BOOL InitReciverStaticText( HWND hDlg )
{
	TCHAR   szFullName[MAX_PATH];
	TCHAR	bufStr[MAX_PATH];
	FILE*	inFile;

	lstrcat( (LPTSTR)szFullName, _T("\\Util\\CommReciver.ctl") );
	if( NULL == (inFile = _tfopen((LPTSTR)szFullName, _T("r"))) )
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
					SetReciverStaticText( hDlg, bufStr );
				else
					break;
			}//end of while
		}//end of if
	}//end of while

	fclose( inFile );
	return( 0 ); // normal
}//end of InitReciverStaticText
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// Set font for all control - increase numCtrl when add new control
VOID InitReciverDlgControlFont( HWND hDlg )
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
}//end of InitReciverDlgControlFont
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// Free resource
VOID OnReciverDlgDestroy( )
{
	// destroy all windows which are created by CreateDialog or CreateWindow API
	if( g_Reciver.hHook )
	{
		UnhookWindowsHookEx( g_Reciver.hHook );
	}
	if( g_Reciver.hWnd != NULL )
	{
		DestroyWindow( g_Reciver.hWnd );
		g_Reciver.hWnd = NULL;
	}
}//end of OnReciverDlgDestroy
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
static VOID OnOK( HWND hDlg )
{
	AsynListen( hDlg );
	EnableWindow( GetDlgItem(hDlg,IDOK), 0 );
}//end of OnOK
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
static VOID OnCancel( HWND hDlg )
{
	if( WSACleanup() != 0 )
	{
		DisplayWSAError();
		return;
	}

	EnableWindow( GetDlgItem(hDlg,IDOK), 1 );
	OnReciverDlgDestroy( );
}//end of OnCancel
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// Disable all control in message group
static VOID DisableMessageControl( HWND hDlg )
{
	EnableWindow( GetDlgItem(hDlg, IDC_GP_R_MESG), 0 );
	EnableWindow( GetDlgItem(hDlg, IDC_ED_R_MSG),  0 );
	EnableWindow( GetDlgItem(hDlg, IDC_BT_R_SEND), 0 );
}//end of DisableMessageControl
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// Enable all control in message group
static VOID EnableMessageControl( HWND hDlg )
{
	EnableWindow( GetDlgItem(hDlg, IDC_GP_R_MESG), 1 );
	EnableWindow( GetDlgItem(hDlg, IDC_ED_R_MSG),  1 );
	EnableWindow( GetDlgItem(hDlg, IDC_BT_R_SEND), 1 );
}//end of DisableMessageControl
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// NOTE : Pre-defined TCP Port number. If other device using these port number
// for their communication, user need to change to other.
// Initialize all controls and GUI 
void OnInitReciverDlg( HWND hDlg )
{	
	int rv;

//	CenterDialog( hDlg );	

	//----------- Initial Combo box
	HWND hPortNum = GetDlgItem( hDlg, IDC_CB_TCP_PORT );
	SendDlgItemMessage( hDlg, IDC_CB_TCP_PORT, CB_ADDSTRING, 0, (LONG)_T("5050") );
	SendDlgItemMessage( hDlg, IDC_CB_TCP_PORT, CB_ADDSTRING, 0, (LONG)_T("6060") );
	SendDlgItemMessage( hDlg, IDC_CB_TCP_PORT, CB_ADDSTRING, 0, (LONG)_T("7070") );
	SendDlgItemMessage( hDlg, IDC_CB_TCP_PORT, CB_ADDSTRING, 0, (LONG)_T("8080") );
	SendDlgItemMessage( hDlg, IDC_CB_TCP_PORT, CB_SETCURSEL, 0, NULL );

	//----------- Disable all message control in message group
	DisableMessageControl( hDlg );

    if( (rv = WSAStartup(MAKEWORD(2,2), &g_wsaData) ) != 0 )
		DisplayWSAError();

	SetFocus( GetDlgItem(hDlg, IDOK) );	
}//end of OnInitReciverDlg
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
BOOL CALLBACK ReciverProc(HWND hDlg,UINT uMsg,WPARAM wParam,LPARAM lParam)
{
	int		i = 0;

	switch( uMsg )
	{
		case WM_INITDIALOG:
			OnInitReciverDlg( hDlg );
			break;
		case WM_COMMAND:
			{
				switch( LOWORD(wParam) )
				{
				case IDOK:
					OnOK( hDlg );
					break;
				case IDCANCEL:
					OnCancel( hDlg );
					break;
				case IDC_BT_R_SEND:
					SendSocketMessage( hDlg, IDC_ED_R_MSG );
					break;
				}//end of switch
			}//end of WM_COMMAND
			break;
		case WSA_ACCEPT: // Notification for accepting socket connection
			if( AcceptConnection( hDlg, lParam ) ) // connection up
			{
				SetWindowText( hDlg, _T("Connection Accepted!") );
				SetDlgItemText( hDlg, IDCANCEL, _T("Disconnect") );
				EnableMessageControl( hDlg );
			}//end of if
			break;// end of case - WSA_ACCEPT
		case WSA_READ: // Notify if data is waiting on a socket. This comes from WSAAsyncSelect().
			ReadSocketData( hDlg, wParam, lParam );
			break;
		case WM_MOUSEMOVE:
			break;
		default:
			break;
	}//end of switch - uMsg
	return( 0 );
}//end of CALLBACK ReciverProc

//+++++++++++++++++++++++++++++++++++++++++++++++++++++ CreateReciverDlg()
// INPUT : HWND ParentHwnd - The big window ??
// INPUT : HINSTANCE - ?????
// INPUT : HWND Edit_hWnd = NULL
BOOL CreateCommReciverDlg(HINSTANCE HInst, HWND ParentHwnd)
{
	BOOL	rv = 0;
	g_Reciver.hInst      = HInst;
	g_Reciver.parenthWnd = ParentHwnd;
//	g_Reciver.edit_hWnd  = Edit_hWnd;

	g_Reciver.hWnd = CreateDialog(  HInst,      // Application instance handle
		  							MAKEINTRESOURCE(IDD_COMM_RECEIVER),
									ParentHwnd, // Parent window handle
									(DLGPROC)(ReciverProc)
								);
	if( g_Reciver.hWnd == NULL )
		return( 1 );

	return( rv );
}//end of CreateCommReciverDlg

