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

struct COMM_FINDER
{
	BOOL		nResult; // return value from Dialog Box
	HINSTANCE	hInst;
	HWND		hWnd;
	HHOOK		hHook;
	HWND		parenthWnd, edit_hWnd;
};

static  COMM_FINDER		g_Finder;
/**
static	WSADATA			g_wsaData;
static PHOSTENT	g_pHostEnt;
static SOCKET	g_Sock;
static CHAR		g_szBuff[ 80 ];
**/
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
VOID SetFinderStaticText( HWND hDlg, CHAR* ptLn )
{
	CHAR	sep[] = "\"";
	CHAR*	ptID;
	CHAR*	ptText;
	CHAR*	ptEnd;
//	BOOL	rv;
	
	ptID   = strtok( ptLn, sep );
	ptText = strtok( NULL, sep );
	ptEnd  = strtok( NULL, sep );
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
}//end of SetFinderStaticText
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// Max. nubmer of static text for reciver dialog is ???
BOOL InitFinderStaticText( HWND hDlg )
{
	CHAR   szFullName[MAX_PATH];
	CHAR	bufStr[MAX_PATH];
	FILE*	inFile;

	strcat( szFullName, "\\Util\\CommReciver.ctl" );
	if( NULL == (inFile = fopen(szFullName, "r")) )
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

		if( NULL != strstr( bufStr, "[Static Text]" ) )
		{
			while( NULL != fgets( bufStr, MAX_PATH, inFile ) )
			{
				if( NULL == strstr( bufStr, "end") )
					SetFinderStaticText( hDlg, bufStr );
				else
					break;
			}//end of while
		}//end of if
	}//end of while

	fclose( inFile );
	return( 0 ); // normal
}//end of InitFinderStaticText
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// Set font for all control - increase numCtrl when add new control
VOID InitFinderDlgControlFont( HWND hDlg )
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
}//end of InitFinderDlgControlFont
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
static VOID OnOK( HWND hDlg )
{
	if( WSACleanup() != 0 )
		DisplayWSAError();

	EndDialog( hDlg, 0 );
}//end of OnOK
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
VOID OnHostNameSel( HWND hDlg )
{
	EnableWindow( GetDlgItem(hDlg,IDC_ED_HOSTNAME), 1 );
	EnableWindow( GetDlgItem(hDlg,IDC_ED_IP_ADDR), 0 );
}//end of OnHostNameSel
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
VOID OnIPAddrSel( HWND hDlg )
{
	EnableWindow( GetDlgItem(hDlg,IDC_ED_HOSTNAME), 0 );
	EnableWindow( GetDlgItem(hDlg,IDC_ED_IP_ADDR), 1 );
}//end of OnIPAddrSel
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
VOID FindHostByName( HWND hDlg )
{
	char		HostName[NAME_LEN]; 
	char		szBuf[NAME_LEN];
	int			count = 0;

	GetDlgItemText( hDlg, IDC_ED_HOSTNAME, (LPTSTR)HostName, NAME_LEN );

	if( ( g_pHostEnt = gethostbyname(HostName) ) == NULL) 
	{
		DisplayWSAError();
		return;
	}

	// Enumerate all the hosts IP addresses.
    while( g_pHostEnt->h_addr_list[count] != NULL ) 
	{     
		sprintf( szBuf, "%u.%u.%u.%u",
						(unsigned char) g_pHostEnt->h_addr_list[count][0],
						(unsigned char) g_pHostEnt->h_addr_list[count][1],
						(unsigned char) g_pHostEnt->h_addr_list[count][2],
						(unsigned char) g_pHostEnt->h_addr_list[count][3]
				);
		count++;                
	}// while( more IP addresses )

	strcpy( HostName, g_pHostEnt->h_name );
	strcat( HostName, " - " );
	strcat( HostName, szBuf );

    SetDlgItemText( hDlg, IDC_STC_DISP_HOST, (LPCTSTR)HostName );

}//end of FindHostByName
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
VOID FindHostByIPAddr( HWND hDlg )
{
	char		szIPAddr[NAME_LEN]; 
	char		szBuf[NAME_LEN];
	int			count = 0;

	GetDlgItemText( hDlg, IDC_ED_IP_ADDR, (LPTSTR)szIPAddr, NAME_LEN );

	UINT addr = inet_addr( szIPAddr );
	if( ( g_pHostEnt = gethostbyaddr((char *)&addr,4,AF_INET) ) == NULL) 
	{
		DisplayWSAError();
		return;
	}

	// Enumerate all the hosts IP addresses.
    while( g_pHostEnt->h_addr_list[count] != NULL ) 
	{     
		sprintf( szBuf, "%u.%u.%u.%u",
						(unsigned char) g_pHostEnt->h_addr_list[count][0],
						(unsigned char) g_pHostEnt->h_addr_list[count][1],
						(unsigned char) g_pHostEnt->h_addr_list[count][2],
						(unsigned char) g_pHostEnt->h_addr_list[count][3]
				);
		count++;                
	}// while( more IP addresses )

	strcpy( szIPAddr, g_pHostEnt->h_name );
	strcat( szIPAddr, " - " );
	strcat( szIPAddr, szBuf );

    SetDlgItemText( hDlg, IDC_STC_DISP_HOST, (LPTSTR)szIPAddr );

}//end of FindHostByIPAddr
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
VOID OnFind( HWND hDlg )
{
	if( IsDlgButtonChecked(hDlg, IDC_RB_HOSTNAME) )
		FindHostByName( hDlg );
	else
		FindHostByIPAddr( hDlg );

	SetDlgItemText( hDlg, IDOK, _T("OK") );
}//end of OnFind
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// NOTE : Pre-defined TCP Port number. If other device using these port number
// for their communication, user need to change to other.
// Initialize all controls and GUI 
void OnInitFinderDlg( HWND hDlg )
{	
	int rv;
	g_Finder.hWnd = hDlg;

//	CenterDialog( hDlg );	
	//---------- Initial radio button
	CheckDlgButton( hDlg, IDC_RB_HOSTNAME, 1 );
	EnableWindow( GetDlgItem(hDlg,IDC_ED_HOSTNAME), 1 );
	CheckDlgButton( hDlg, IDC_RB_IP_ADDR, 0 );
	EnableWindow( GetDlgItem(hDlg,IDC_ED_IP_ADDR), 0 );

	//----------- Initial Combo box
	HWND hPortNum = GetDlgItem( hDlg, IDC_CB_TCP_PORT );
	SendDlgItemMessage( hDlg, IDC_CB_TCP_PORT, CB_ADDSTRING, 0, (LONG)_T("5050") );
	SendDlgItemMessage( hDlg, IDC_CB_TCP_PORT, CB_ADDSTRING, 0, (LONG)_T("6060") );
	SendDlgItemMessage( hDlg, IDC_CB_TCP_PORT, CB_ADDSTRING, 0, (LONG)_T("7070") );
	SendDlgItemMessage( hDlg, IDC_CB_TCP_PORT, CB_ADDSTRING, 0, (LONG)_T("8080") );
	SendDlgItemMessage( hDlg, IDC_CB_TCP_PORT, CB_SETCURSEL, 0, NULL );

    if( (rv = WSAStartup(MAKEWORD(2,2), &g_wsaData) ) != 0 )
		DisplayWSAError();

//	SetFocus( GetDlgItem(hDlg, IDOK) );	
}//end of OnInitFinderDlg
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
BOOL CALLBACK FinderProc(HWND hDlg,UINT uMsg,WPARAM wParam,LPARAM lParam)
{
	int		i = 0;

	switch( uMsg )
	{
		case WM_INITDIALOG:
			OnInitFinderDlg( hDlg );
			break;
		case WM_COMMAND:
			{
				switch( LOWORD(wParam) )
				{
				case IDOK:
					OnOK( hDlg );
					break;
				case IDC_RB_HOSTNAME:
					OnHostNameSel( hDlg );
					break;
				case IDC_RB_IP_ADDR:
					OnIPAddrSel( hDlg );
					break;
				case IDC_BT_FIND:
					OnFind( hDlg );
					break;
				}//end of switch
			}//end of WM_COMMAND
			break;
		default:
			break;
	}//end of switch - uMsg

	return( 0 );
}//end of CALLBACK FinderProc

//+++++++++++++++++++++++++++++++++++++++++++++++++++++ CreateReciverDlg()
// INPUT : HWND ParentHwnd - The big window ??
// INPUT : HINSTANCE - ?????
BOOL CreateCommFinderDlg(HINSTANCE HInst, HWND ParentHwnd)
{
	BOOL	rv = 0;
	g_Finder.hInst      = HInst;
	g_Finder.parenthWnd = ParentHwnd;

	rv = DialogBox( HInst,      // Application instance handle
		  			MAKEINTRESOURCE(IDD_COMM_FINDER),
					ParentHwnd, // Parent window handle
					(DLGPROC)(FinderProc)
				);

	return( rv );
}//end of CreateCommFinderDlg

