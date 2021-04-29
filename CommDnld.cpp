// char b[20];
// _itoa( i, b, 10 );
// MessageBox( NULL, b, "Kentest", MB_OK );

#include "stdafx.h"
#include "afxpriv.h"

#include "winsock.h"
#include "Communicate.h"
#include "mbstring.h"
#include <wininet.h>

#include <tchar.h>
#include <COMMCTRL.H>
#include "resource.h"
#include "stdio.h"
#include "FileReq.h"


#define FILE_SIZE						1024 * 64

struct COMM_DNLD
{
	BOOL		nResult; // return value from Dialog Box
	HINSTANCE	hInst;
	HWND		hWnd;
	HHOOK		hHook;
	HWND		parenthWnd, edit_hWnd;

	TCHAR		szFullUrl[NAME_LEN];
	TCHAR		szUrl[NAME_LEN];
	DWORD		dwServiceType;

	HWND		hUrl;	

	// --------------- HTTP section
	HWND		hHTML;	
	LPTSTR		pHTML;
	BOOL		httpFileType;	// HTML (ascii) = 0; image (binary) = 1
	DWORD		dwSizeHtml;

	// --------------- FTP section
	HWND		hFTP;
	LPTSTR		pFTP;
	BOOL		ftpCERN;		// CERN proxy - 1 proxy exist; 0 no proxy
	TCHAR		szUserName[NAME_LEN];
	TCHAR		szPassword[NAME_LEN];

	// --------------- File section

};

static  COMM_DNLD	g_DnLd;

//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
LPVOID KAllocMem( DWORD cb )
{
    return HeapAlloc(GetProcessHeap(), HEAP_GENERATE_EXCEPTIONS | HEAP_ZERO_MEMORY, cb);
}//end of KAllocMem
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
BOOL KFreeMem( LPVOID pMem )
{
    return HeapFree(GetProcessHeap(), 0, pMem);
}//end of KFreeMem
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
VOID SetDownloadStaticText( HWND hDlg, TCHAR* ptLn )
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
}//end of SetDownloadStaticText
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// Max. nubmer of static text for reciver dialog is ???
BOOL InitDownloadStaticText( HWND hDlg )
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
		if( NULL == fgets( (CHAR*)bufStr, MAX_PATH, inFile ) )
		{
			fclose( inFile );
			return( 1 );// error
		}//end of if 

		if( NULL != _tcsstr( bufStr, (TCHAR*)"[Static Text" ) )
		{
			while( NULL != fgets( (CHAR*)bufStr, MAX_PATH, inFile ) )
			{
				if( NULL == _tcsstr( bufStr, (TCHAR*)"end") )
					SetDownloadStaticText( hDlg, bufStr );
				else
					break;
			}//end of while
		}//end of if
	}//end of while

	fclose( inFile );
	return( 0 ); // normal
}//end of InitDownloadStaticText
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// Set font for all control - increase numCtrl when add new control
VOID InitDownloadDlgControlFont( HWND hDlg )
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
}//end of InitDownloadDlgControlFont
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// Free resource
VOID OnDownloadDlgDestroy( )
{
	// destroy all windows which are created by CreateDialog or CreateWindow API
	if( g_DnLd.hHook )
	{
		UnhookWindowsHookEx( g_DnLd.hHook );
	}
	if( g_DnLd.hWnd != NULL )
	{
		DestroyWindow( g_DnLd.hWnd );
		g_DnLd.hWnd = NULL;
	}
	if( g_DnLd.pHTML )
		KFreeMem( g_DnLd.pHTML );

	if( g_DnLd.pFTP )
		KFreeMem( g_DnLd.pFTP );
}//end of OnDownloadDlgDestroy
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
void OnGetFile( HWND hDlg )
{
	HCURSOR	hCursor = SetCursor( LoadCursor(NULL, IDC_WAIT) );
	ShowCursor( 1 );
		
	GetDlgItemText( hDlg, IDC_ED_FILE, g_DnLd.szUrl, NAME_LEN );

	//strip out white space in url
	int i=0, j=0;
	while( g_DnLd.szUrl[i] )		
	{			
		while( g_DnLd.szUrl[i] == ' ' )
			i++;			
		g_DnLd.szUrl[j++] = g_DnLd.szUrl[i++];		
	}//end of while

	g_DnLd.szUrl[j] = '\0';
	if( !lstrlen(g_DnLd.szUrl) )
	{
		MessageBox( hDlg, _T("You haven't enter a URL yet."), _T("Error"), MB_OK );
		return;
	}

	i = 0; // For File url, change all / to \\ in the url
	while( g_DnLd.szUrl[i] ) 
	{
		if( g_DnLd.szUrl[i] == '/' ) 
			g_DnLd.szUrl[i] = '\\';
		i++;
	}//end of while	

	CharLower( g_DnLd.szUrl ); //change to all lower case

	if( _tcsstr(g_DnLd.szUrl, _T("file:\\")) ) // "file:\\" included
		lstrcpy( g_DnLd.szUrl, &g_DnLd.szUrl[8] );

	if( CopyFile(	g_DnLd.szUrl, // pointer to existing source file
					_T("C:\\me"), // pointer to destination file
					0			  // overwrite any existing file
				) // Copy file 
		) // if
		MessageBox( NULL, _T("File download complete."), g_DnLd.szUrl, MB_OK );
	else
		MessageBox( NULL, _T("File download file."), g_DnLd.szUrl, MB_OK );

	ShowCursor( 0 );
	SetCursor( hCursor );

//	EnableWindow( GetDlgItem(hDlg,IDOK), 0 );
}//end of OnGetFile
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
VOID OnSendFile( HWND hDlg )
{
	DWORD	rv;
	HCURSOR	hCursor = SetCursor( LoadCursor(NULL, IDC_WAIT) );
	ShowCursor( 1 );
		
	GetDlgItemText( hDlg, IDC_ED_FILE, g_DnLd.szUrl, NAME_LEN );

	//strip out white space in url
	int i=0, j=0;
	while( g_DnLd.szUrl[i] )		
	{			
		while( g_DnLd.szUrl[i] == ' ' )
			i++;			
		g_DnLd.szUrl[j++] = g_DnLd.szUrl[i++];		
	}//end of while

	g_DnLd.szUrl[j] = '\0';
	if( !lstrlen(g_DnLd.szUrl) )
	{
		MessageBox( hDlg, _T("You haven't enter a URL yet."), _T("Error"), MB_OK );
		return;
	}

	i = 0; // For File url, change all / to \\ in the url
	while( g_DnLd.szUrl[i] ) 
	{
		if( g_DnLd.szUrl[i] == '/' ) 
			g_DnLd.szUrl[i] = '\\';
		i++;
	}//end of while	

	CharLower( g_DnLd.szUrl ); //change to all lower case

	if( _tcsstr(g_DnLd.szUrl, _T("file:\\")) ) // "file:\\" included
		lstrcpy( g_DnLd.szUrl, &g_DnLd.szUrl[8] );

	if( CopyFile(	_T("C:\\me"),		// pointer to existing source file
					g_DnLd.szUrl,	// pointer to destination file
					0				// overwrite any existing file
				) // Copy file 
		) // if
		MessageBox( NULL, _T("File download complete."), g_DnLd.szUrl, MB_OK );
	else
	{
		rv = GetLastError();
		MessageBox( NULL, _T("File download file."), g_DnLd.szUrl, MB_OK );
	}//end of else

	ShowCursor( 0 );
	SetCursor( hCursor );

//	EnableWindow( GetDlgItem(hDlg,IDOK), 0 );
}//end of OnSendFile

//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
VOID OnGetHTTP( HWND hDlg )
{		
	HCURSOR	hCursor = SetCursor( LoadCursor(NULL, IDC_WAIT) );
	ShowCursor( 1 );
		
	g_DnLd.pHTML[0] = '\0';
	
	GetDlgItemText( hDlg, IDC_ED_HTTP, g_DnLd.szUrl, NAME_LEN );

	//strip out white space in url
	int i=0, j=0;
	while( g_DnLd.szUrl[i] )		
	{			
		while( g_DnLd.szUrl[i] == ' ' )
			i++;			
		g_DnLd.szUrl[j++] = g_DnLd.szUrl[i++];		
	}//end of while

	g_DnLd.szUrl[j] = '\0';
	if( !lstrlen(g_DnLd.szUrl) )
	{
		MessageBox( hDlg, _T("You haven't enter a URL yet."), _T("Error"), MB_OK );
		return;
	}

	i = 0; // change all \ to / in the url
	while( g_DnLd.szUrl[i] ) 
	{
		if( g_DnLd.szUrl[i] == '\\' ) 
			g_DnLd.szUrl[i] = '/';
		i++;
	}//end of while	

	CharLower( g_DnLd.szUrl ); //change to all lower case

	if( _tcsstr(g_DnLd.szUrl, _T("http://")) )
	{	
		lstrcpy( g_DnLd.szFullUrl, g_DnLd.szUrl );
	}
	else
	{	// "http://" not include 
		lstrcpy( g_DnLd.szFullUrl, _T("http://") );
		lstrcat( g_DnLd.szFullUrl, g_DnLd.szUrl );
	}

	// Internet Session -------------------------------------------- Internet session
	HINTERNET hInternetSession;		
	hInternetSession = InternetOpen(_T("Acg - Download"), INTERNET_OPEN_TYPE_PRECONFIG, NULL, NULL, 0);
	if( hInternetSession == NULL ) 		
	{
		MessageBox( hDlg, _T("Internet Open Fails"), _T("Error"), MB_OK );
		goto CursorBackAndExit;
	}
		
	HINTERNET hInternetFile;
	// download html and text. Modify if needs to download binary file.
	hInternetFile = InternetOpenUrl(hInternetSession, 
									g_DnLd.szFullUrl,
									NULL, 
									0, 
//									INTERNET_FLAG_TRANSFER_ASCII // for FTP only
									INTERNET_FLAG_TRANSFER_BINARY
									| INTERNET_FLAG_RELOAD 
									| INTERNET_FLAG_DONT_CACHE, 
									0
								);
	if( !hInternetFile )
	{
		MessageBox(hDlg, _T("InternetOpenUrl failed! Check URL or connection"), g_DnLd.szFullUrl, MB_OK);
		goto CursorBackAndExit;
	}

//---- open a file
	HANDLE	f;
	DWORD	dwWritten;
	//download the file to c:\deleteme					
	f = CreateFile( _T("c:\\me"), GENERIC_WRITE,  0, NULL, CREATE_ALWAYS,FILE_ATTRIBUTE_NORMAL, NULL); 
	if( f == INVALID_HANDLE_VALUE )					
	{						
		MessageBox( hDlg, _T("Can't open c:\\deleteme to write! Enough free space on C:???"), g_DnLd.szFullUrl, MB_OK);
		return;				
	}//end of if
//end of open file

// --- start download HTML file
	DWORD	dwRead;
	DWORD	dwDnSize;
	TCHAR	szTemp[1024];
	BYTE	bufImage[FILE_SIZE];
	int		nTimes;
	nTimes = 1;

	dwDnSize = 0;
	if( g_DnLd.httpFileType ) // image - 1
	{
		while( InternetReadFile(hInternetFile, (LPVOID)bufImage, FILE_SIZE, &dwRead) )
		{
			if( !dwRead )
				break;
			szTemp[dwRead]='\0'; // end of string - new line ??
			WriteFile( f, (LPVOID)szTemp, dwRead, &dwWritten, NULL );
			dwDnSize += dwWritten;
		}//end of while - read internet image file
	}//end of if - image downlaod
	else // html - 0
	{					
		while( InternetReadFile(hInternetFile, (LPVOID)szTemp, 1023, &dwRead) )
		{
			if( !dwRead )
				break;
			szTemp[dwRead]='\0'; // end of string - new line ??
			WriteFile( f, (LPVOID)szTemp, dwRead, &dwWritten, NULL );
			dwDnSize += dwWritten;
		}//end of while - read internet html file
	}//end of else - html download

	CloseHandle( f );

// NEXT line - save for testing purpose
	SetDlgItemInt( hDlg, IDC_ED_SHOW_HTML, dwDnSize, 0 );
		
	InternetCloseHandle(hInternetFile);				
	
CursorBackAndExit:
	InternetCloseHandle( hInternetSession );
	ShowCursor( 0 );
	SetCursor( hCursor );

//	EnableWindow( GetDlgItem(hDlg,IDOK), 0 );
}//end of OnGetHTTP
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
void OnCERNCheckBut( HWND hDlg )
{
	g_DnLd.ftpCERN ^= 1;
}// end of OnCERNCheckBut
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// To pass username and password to InternetOpenUrl, URL use the following 
// format: http://username:password@server:port/path for internally constructs of URL
// Since we only use InternetOpenUrl, there is no other way to pass in username and
// password.	Doesn't apply to FILE url.
void OnGetFTP( HWND hDlg )
{
	HCURSOR	hCursor = SetCursor( LoadCursor(NULL, IDC_WAIT) );
	ShowCursor( 1 );
		
	g_DnLd.pFTP[0] = '\0';
	
	GetDlgItemText( hDlg, IDC_ED_FTP,      g_DnLd.szUrl,      NAME_LEN );
	GetDlgItemText( hDlg, IDC_ED_USERNAME, g_DnLd.szUserName, NAME_LEN );
	GetDlgItemText( hDlg, IDC_ED_PASSWORD, g_DnLd.szPassword, NAME_LEN );

	//strip out white space in url
	int i=0, j=0;
	while( g_DnLd.szUrl[i] )		
	{			
		while( g_DnLd.szUrl[i] == ' ' )
			i++;			
		g_DnLd.szUrl[j++] = g_DnLd.szUrl[i++];		
	}//end of while

	g_DnLd.szUrl[j] = '\0';
	if( !lstrlen(g_DnLd.szUrl) )
	{
		MessageBox( hDlg, _T("You haven't enter a URL yet."), _T("Error"), MB_OK );
		return;
	}

	i = 0; // For FTP url, change all \ to / in the url
	while( g_DnLd.szUrl[i] ) 
	{
		if( g_DnLd.szUrl[i] == '\\' ) 
			g_DnLd.szUrl[i] = '/';
		i++;
	}//end of while	

	CharLower( g_DnLd.szUrl ); //change to all lower case

	if( _tcsstr(g_DnLd.szUrl, _T("ftp://")) ) // "ftp://" included
		lstrcpy( g_DnLd.szUrl, &g_DnLd.szUrl[7] );

/**** save this is a working code for reference
***** save this is a working code
	lstrcat( g_DnLd.szFullUrl, "ftp://" );
	if( lstrlen(g_DnLd.szUserName) && lstrlen(g_DnLd.szPassword) )
	{
		lstrcat( g_DnLd.szFullUrl, g_DnLd.szUserName );
		lstrcat( g_DnLd.szFullUrl, ":" );
		lstrcat( g_DnLd.szFullUrl, (LPCTSTR)g_DnLd.szPassword );
		lstrcat( g_DnLd.szFullUrl, "@" );
	}//end of if - strlen of username and password

	lstrcat( g_DnLd.szFullUrl, g_DnLd.szUrl );

	HINTERNET hInternetFile;
	DWORD	  flag;
	if( g_DnLd.ftpCERN ) // CERN proxy exist - 1
		flag = INTERNET_FLAG_RELOAD | INTERNET_FLAG_DONT_CACHE;
	else // CERN proxy does not exist
		flag = INTERNET_FLAG_RELOAD | INTERNET_FLAG_DONT_CACHE | INTERNET_FLAG_RAW_DATA;
		
	// download html and text. Modify if needs to download binary file.
	lstrcat( g_DnLd.szFullUrl, "/home/i/in/inno/public_html/601.gif" );
	hInternetFile = InternetOpenUrl(	hInternetSession, 
										g_DnLd.szFullUrl,
										NULL, 
										0, 
										flag,
										0
								);
	if( !hInternetFile )
	{
		DWORD rv = GetLastError();
		MessageBox(hDlg, "InternetOpenUrl failed! Check URL or connection", g_DnLd.szFullUrl, MB_OK);
		goto CursorBackAndExit;
	}

//---- open a file
	HANDLE	f;
	DWORD	dwWritten;

	DeleteFile( "c:\\me" );

	//download the file to c:\me					
	f = CreateFile("c:\\me", GENERIC_WRITE,  0, NULL, CREATE_ALWAYS,FILE_ATTRIBUTE_NORMAL, NULL); 
	if( f == INVALID_HANDLE_VALUE )					
	{						
		MessageBox( hDlg, "Can't open c:\\deleteme to write! Enough free space on C:???", g_DnLd.szFullUrl, MB_OK);
		return;				
	}//end of if
//end of open file

// --- start download FTP file
	DWORD	dwRead;
	DWORD	dwDnSize;
	TCHAR	szTemp[1024];
	BYTE	bufFile[FILE_SIZE];
	int		nTimes;
	nTimes = 1;

	while( InternetReadFile(hInternetFile, (LPVOID)szTemp, 1023, &dwRead) )
	{
		if( !dwRead )
			break;
		szTemp[dwRead]='\0'; // end of string - new line ??
		WriteFile( f, (LPVOID)szTemp, dwRead, &dwWritten, NULL );
		dwDnSize += dwWritten;
	}//end of while - read internet html file

	CloseHandle( f );

  // NEXT line - save for testing purpose
	SetDlgItemInt( hDlg, IDC_ED_SHOW_HTML, dwDnSize, 0 );
**** save this is a working code
**** save this is a working code ******/

	// Internet Session -------------------------------------------- Internet session
	DWORD		rv;
	HINTERNET	hInternetSession;		
	hInternetSession = InternetOpen(_T("Acg - Download"), INTERNET_OPEN_TYPE_PRECONFIG, NULL, NULL, 0);
	if( hInternetSession == NULL ) 		
	{
		MessageBox( hDlg, _T("Internet Open Fails"), _T("Error"), MB_OK );
		goto CursorBackAndExit;
	}
	HINTERNET	hInternetFile;
	hInternetFile = InternetConnect( hInternetSession,
									_T("ftpup.dnai.com"), // = g_DnLd.szUrl
									INTERNET_DEFAULT_FTP_PORT,
									_T("inno"),
									_T("zgDd2Kj5"),
									INTERNET_SERVICE_FTP,
									0,
									0
								);
	if( !hInternetFile )
	{
		rv = GetLastError();
		MessageBox(hDlg, _T("InternetConnect failed! Check URL or connection"), g_DnLd.szFullUrl, MB_OK);
		goto CursorBackAndExit;
	}

	rv = FtpGetFile( hInternetFile, 
					_T("/home/i/in/inno/public_html/601.gif"),
					_T("c:\\me"), 
					0,
					FILE_ATTRIBUTE_NORMAL,
					FTP_TRANSFER_TYPE_BINARY,
					0 
				);
	if( !rv )
	{
		DWORD rv = GetLastError();
		MessageBox(hDlg, _T("FtpGetFile failed! Check URL or connection"), g_DnLd.szFullUrl, MB_OK);
		goto CursorBackAndExit;
	}

	
	InternetCloseHandle(hInternetFile);				

CursorBackAndExit:
	InternetCloseHandle( hInternetSession );
	ShowCursor( 0 );
	SetCursor( hCursor );

//	EnableWindow( GetDlgItem(hDlg,IDOK), 0 );

}//end of OnGetFTP
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
VOID OnSendFTP( HWND hDlg )
{
	DWORD				rv;

	HCURSOR	hCursor = SetCursor( LoadCursor(NULL, IDC_WAIT) );
	ShowCursor( 1 );
		
	g_DnLd.pFTP[0] = '\0';
	
	GetDlgItemText( hDlg, IDC_ED_FTP,      g_DnLd.szUrl,      NAME_LEN );
	GetDlgItemText( hDlg, IDC_ED_USERNAME, g_DnLd.szUserName, NAME_LEN );
	GetDlgItemText( hDlg, IDC_ED_PASSWORD, g_DnLd.szPassword, NAME_LEN );

	//strip out white space in url
	int i=0, j=0;
	while( g_DnLd.szUrl[i] )		
	{			
		while( g_DnLd.szUrl[i] == ' ' )
			i++;			
		g_DnLd.szUrl[j++] = g_DnLd.szUrl[i++];		
	}//end of while

	g_DnLd.szUrl[j] = '\0';
	if( !lstrlen(g_DnLd.szUrl) )
	{
		MessageBox( hDlg, _T("You haven't enter a URL yet."), _T("Error"), MB_OK );
		return;
	}

	i = 0; // For FTP url, change all \ to / in the url
	while( g_DnLd.szUrl[i] ) 
	{
		if( g_DnLd.szUrl[i] == '\\' ) 
			g_DnLd.szUrl[i] = '/';
		i++;
	}//end of while	

	CharLower( g_DnLd.szUrl ); //change to all lower case

	if( _tcsstr(g_DnLd.szUrl, _T("ftp://")) ) // "ftp://" included
		lstrcpy( g_DnLd.szUrl, &g_DnLd.szUrl[7] );

/****** save for reference
	lstrcat( g_DnLd.szFullUrl, "ftp://" );
	if( lstrlen(g_DnLd.szUserName) && lstrlen(g_DnLd.szPassword) )
	{
		lstrcat( g_DnLd.szFullUrl, g_DnLd.szUserName );
		lstrcat( g_DnLd.szFullUrl, ":" );
		lstrcat( g_DnLd.szFullUrl, (LPCTSTR)g_DnLd.szPassword );
		lstrcat( g_DnLd.szFullUrl, "@" );
	}//end of if - strlen of username and password

	lstrcat( g_DnLd.szFullUrl, g_DnLd.szUrl );
**** save for reference *****/

	// Internet Session -------------------------------------------- Internet session
	HINTERNET hInternetSession;		
	hInternetSession = InternetOpen(_T("Acg - Download"), INTERNET_OPEN_TYPE_PRECONFIG, NULL, NULL, 0);
	if( hInternetSession == NULL ) 		
	{
		MessageBox( hDlg, _T("Internet Open Fails"), _T("Error"), MB_OK );
		goto CursorBackAndExit;
	}

	HINTERNET	hInternetFile;
	hInternetFile = InternetConnect( hInternetSession,
									_T("ftpup.dnai.com"),
									INTERNET_DEFAULT_FTP_PORT,
									_T("inno"),
									_T("zgDd2Kj5"),
									INTERNET_SERVICE_FTP,
									0,
									0
								);
	if( !hInternetFile )
	{
		DWORD rv = GetLastError();
		MessageBox(hDlg, _T("InternetConnect failed! Check URL or connection"), g_DnLd.szFullUrl, MB_OK);
		goto CursorBackAndExit;
	}

	rv = FtpPutFile( hInternetFile, 
					_T("c:\\you"),
					_T("you"), 
					FTP_TRANSFER_TYPE_BINARY,
					0 
				);
	if( !rv )
	{
		DWORD rv = GetLastError();
		MessageBox(hDlg, _T("FtpPutFile failed! Check URL or connection"), g_DnLd.szFullUrl, MB_OK);
		goto CursorBackAndExit;
	}

// NEXT line - save for testing purpose
//	SetDlgItemInt( hDlg, IDC_ED_SHOW_HTML, dwWritten, 0 );
	
	InternetCloseHandle(hInternetFile);				

CursorBackAndExit:
	InternetCloseHandle( hInternetSession );
	ShowCursor( 0 );
	SetCursor( hCursor );
}//end of OnSendFTP
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
static VOID OnCancel( HWND hDlg )
{
//	if( WSACleanup() != 0 )
//	{
//		DisplayWSAError();
//		return;
//	}

//	EnableWindow( GetDlgItem(hDlg,IDOK), 1 );
	g_DnLd.szFullUrl[0] = '\0';
	g_DnLd.szUrl[0]		= '\0';
	OnDownloadDlgDestroy( );
}//end of OnCancel
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
void OnHTMLRadioBut( HWND hDlg )
{
	g_DnLd.httpFileType = 0;
	CheckRadioButton( hDlg, IDC_RB_HTML, IDC_RB_IMAGE, IDC_RB_HTML );
}//end of OnHTMLRadioBut
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
void OnImageRadioBut( HWND hDlg )
{
	g_DnLd.httpFileType = 1;
	CheckRadioButton( hDlg, IDC_RB_HTML, IDC_RB_IMAGE, IDC_RB_IMAGE );
}//end of OnHTMLRadioBut
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// NOTE : Pre-defined TCP Port number. If other device using these port number
// for their communication, user need to change to other.
// Initialize all controls and GUI 
void OnInitDownloadDlg( HWND hDlg )
{	
//	int rv;

//	CenterDialog( hDlg );	

//----- HTTP download section
	CheckRadioButton( hDlg, IDC_RB_HTML, IDC_RB_IMAGE, IDC_RB_IMAGE );
	g_DnLd.httpFileType = 1; // default to image (binary) file
	g_DnLd.dwSizeHtml = FILE_SIZE;
	g_DnLd.pHTML = (LPTSTR)KAllocMem(g_DnLd.dwSizeHtml);
	if( !g_DnLd.pHTML )
	{
		MessageBox( hDlg, _T("Memory Allocation Failure"), _T("Error"), MB_OK );
		return;
	}
//	g_DnLd.hUrl  = GetDlgItem( hDlg, IDC_ED_HTTP );	
	g_DnLd.pHTML[0] = g_DnLd.szUrl[0] = '\0';
	
//---- FTP download section
	CheckDlgButton( hDlg, IDC_CK_CERN, 1 );
	g_DnLd.ftpCERN = 1;
	g_DnLd.dwSizeHtml = FILE_SIZE;
	g_DnLd.pFTP = (LPTSTR)KAllocMem(g_DnLd.dwSizeHtml);
	if( !g_DnLd.pFTP )
	{
		MessageBox( hDlg, _T("Memory Allocation Failure"), _T("Error"), MB_OK );
		return;
	}
	g_DnLd.pFTP[0] = g_DnLd.szUrl[0] = '\0';

//save	SetFocus( GetDlgItem(hDlg, IDOK) );	
}//end of OnInitDownloadDlg
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
BOOL CALLBACK DownloadProc(HWND hDlg,UINT uMsg,WPARAM wParam,LPARAM lParam)
{
	int		i = 0;

	switch( uMsg )
	{
		case WM_INITDIALOG:
			OnInitDownloadDlg( hDlg );
			break;
		case WM_COMMAND:
			{
				switch( LOWORD(wParam) )
				{
				// -------------- HTTP section
				case IDC_RB_HTML: 
					OnHTMLRadioBut( hDlg );
					break;
				case IDC_RB_IMAGE:
					OnImageRadioBut( hDlg );
					break;
				case IDC_BT_HTTP_GET: // get http object
					OnGetHTTP( hDlg );
					break;
				// -------------- FTP section
				case IDC_CK_CERN: 
					OnCERNCheckBut( hDlg );
					break;
				case IDC_BT_FTP_GET:
					OnGetFTP( hDlg );
					break;
				case IDC_BT_FTP_SEND:
					OnSendFTP( hDlg );
					break;
				//------------- File section
				case IDC_BT_FILE_GET:
					OnGetFile( hDlg );
					break;
				case IDC_BT_FILE_SEND:
					OnSendFile( hDlg );
					break;
				case IDCANCEL:
					OnCancel( hDlg );
					break;
				}//end of switch
			}//end of WM_COMMAND
			break;
		default:
			break;
	}//end of switch - uMsg
	return( 0 );
}//end of CALLBACK DownloadProc
//+++++++++++++++++++++++++++++++++++++++++++++++++++++ CreateReciverDlg()
// INPUT : HWND ParentHwnd - The big window ??
// INPUT : HINSTANCE - ?????
BOOL CreateCommDownloadDlg(HINSTANCE HInst, HWND ParentHwnd)
{
	BOOL	rv = 0;
	g_DnLd.hInst      = HInst;
	g_DnLd.parenthWnd = ParentHwnd;

	g_DnLd.hWnd = CreateDialog(  HInst,      // Application instance handle
		  						MAKEINTRESOURCE(IDD_COMM_DOWNLOAD),
								ParentHwnd, // Parent window handle
								(DLGPROC)(DownloadProc)
							);
	if( g_DnLd.hWnd == NULL )
		return( 1 );

	return( rv );
}//end of CreateCommDownloadDlg

