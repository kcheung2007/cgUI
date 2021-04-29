/* COPYRIGHT NOTICE:
********************************************************
*  Copyright (c) 2000 InnoVision Technology, Inc.      *
*  All rights reserved.                                *
*  PROPRIETARY AND CONFIDENTIAL                        *
*  DO NOT DISTRIBUTE                                   *
********************************************************
*/

// cgUI.cpp : Defines the class behaviors for the application.
//

#include "stdafx.h"
#include "afxdisp.h"
#include "cgUI.h"
#include "MainFrm.h"
#include "ChildFrm.h"
#include "cgUIDoc.h"
#include "cgUIView.h"
//#include "Global.h"


#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

extern CURSOR_HANDLE g_hCursor;
extern DWORD		 g_CodePage;
extern TCHAR		 UILang_UIFont[256];
extern int			 UILang_UIFontSize;

/////////////////////////////////////////////////////////////////////////////
// CCgUIApp

extern void SetUILanguage();


BEGIN_MESSAGE_MAP(CCgUIApp, CWinApp)
	//{{AFX_MSG_MAP(CCgUIApp)
	ON_COMMAND(ID_APP_ABOUT, OnAppAbout)
	ON_COMMAND(ID_FILE_PAGE_SETUP, OnFilePageSetup)
	//}}AFX_MSG_MAP
	// Standard file based document commands	
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CCgUIApp construction

CCgUIApp::CCgUIApp()
{
	// TODO: add construction code here,
	// Place all significant initialization in InitInstance
}//end of CCgUIApp - constructor

/////////////////////////////////////////////////////////////////////////////
// The one and only CCgUIApp object

CCgUIApp theApp;


/////////////////////////////////////////////////////////////////////////////////
// Test if filename ends with suffix
static BOOL CompareFilenameSuffix(LPCTSTR pPathName, LPCTSTR lpszSuffix)
{
	int len = lstrlen(pPathName);
	int suflen = lstrlen(lpszSuffix);
	return( (suflen>0 && len>suflen && lstrcmpi(&pPathName[len-suflen], lpszSuffix)==0 ));	
}
////////////////////////////////////////////////////////////////////////////////////////
// Callback function that test the file extension
static BOOL CALLBACK ixProjFunc(LPCTSTR pPathName)
{
	return CompareFilenameSuffix(pPathName, _T(".acg"));
}

////////////////////////////////////////////////////////////////////////////////////////
// Callback function that test the file extension
static BOOL CALLBACK ixFileFunc(LPCTSTR pPathName)
{
	return( CompareFilenameSuffix(pPathName, _T(".bmp")) );
}

/////////////////////////////////////////////////////////////////////////////
// CCgUIApp initialization
BOOL CCgUIApp::InitInstance()
{
	TRACE0( "cgUI.cpp : CCgUIApp::InitInstance\n" );
	
	if( !AfxOleInit() ) // Initialize OLE libraries
	{
		AfxMessageBox(IDP_OLE_INIT_FAILED);
		return FALSE;
	}

	if( !AfxSocketInit() )
	{
		AfxMessageBox(IDP_SOCKETS_INIT_FAILED);
		return FALSE;
	}
	AfxEnableControlContainer();

	// Standard initialization
	// If you are not using these features and wish to reduce the size
	//  of your final executable, you should remove from the following
	//  the specific initialization routines you do not need.

#ifdef _AFXDLL
	Enable3dControls();			// Call this when using MFC in a shared DLL
#else
	Enable3dControlsStatic();	// Call this when linking to MFC statically
#endif

	// Change the registry key under which our settings are stored.
	SetRegistryKey(IDS_REG_KEY); // string table

	LoadStdProfileSettings( MAX_LIST );  // Load standard INI file options (including MRU)

	// Add recent file category for Project type
//	CString szKey;
	m_ixFileMgr.Add( ID_FILE_MRU_PROJ1,			// base command ID
					  _T("Recent Project List"),// szSection = registry key name 
					  _T("File%d"),				// szFileEntry = registry value name
					  ixProjFunc,				// test for .acg file
					  MAX_LIST					// max number list/menu entries
				);									

	// Add recent file category for file type
	m_ixFileMgr.Add( ID_FILE_MRU_FILE1,			// base command ID
					 _T("Recent File List"),	// szSection = registry key name 
					 _T("File%d"),				// szFileEntry = registry value name
					 ixFileFunc,				// test for non acg file
					 MAX_LIST					// max number list/menu entries
				);									

	// Register the application's document templates.  Document templates
	//  serve as the connection between documents, frame windows and views.
	CMultiDocTemplate* pDocTemplate;
	pDocTemplate = new CMultiDocTemplate(	MENU_TYPE,
											RUNTIME_CLASS(CCgUIDoc),
											RUNTIME_CLASS(CChildFrame), // custom MDI child frame
											RUNTIME_CLASS(CCgUIView)
										);
	AddDocTemplate(pDocTemplate);

	// create main MDI Frame window
	CMainFrame* pMainFrame = new CMainFrame;
	if( !pMainFrame->LoadFrame(IDR_MAINFRAME) )
		return FALSE;
	m_pMainWnd = pMainFrame;

//save - comment out without any effect, don't know why yet - save for a while first
//	ChangeControlFont( pMainFrame->m_hWnd, NULL, UILang_UIFont,0, UILang_UIFontSize, FW_NORMAL);

	// Parse command line for standard shell commands, DDE, file open
	CCommandLineInfo cmdInfo;	  
	// Dispatch commands specified on the command line
	if( !ProcessShellCommand(cmdInfo) )
		return FALSE;

	// The main window has been initialized, so show and update it.
	pMainFrame->ShowWindow(m_nCmdShow);
	pMainFrame->UpdateWindow();

	return TRUE;
}//end of CCgUIApp::InitInstance

/////////////////////////////////////////////////////////////////////////////
// CAboutDlg dialog used for App About

class CAboutDlg : public CDialog
{
public:
	CAboutDlg();

// Dialog Data
	//{{AFX_DATA(CAboutDlg)
	enum { IDD = IDD_ABOUTBOX };
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAboutDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	//{{AFX_MSG(CAboutDlg)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};//end of class - CAbout

CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
{
	//{{AFX_DATA_INIT(CAboutDlg)
	//}}AFX_DATA_INIT
}//end of about dialog constructor

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CAboutDlg)
	//}}AFX_DATA_MAP
}//end of CAboutDlg::DoDataExchange

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
	//{{AFX_MSG_MAP(CAboutDlg)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

// App command to run the dialog
void CCgUIApp::OnAppAbout()
{
	CAboutDlg aboutDlg;
	aboutDlg.DoModal();
}//end of CCgUIApp::OnAppAbout

/////////////////////////////////////////////////////////////////////////////
// CCgUIApp message handlers


////////////////////////////////////////////////////////////////////////////////////////////
// This file menu item was moved to page menu by the request of Jim. Therefore, should move 
// this function back to MainFrame.
void CCgUIApp::OnFilePageSetup() 
{
	// TODO: Add your command handler code here
	CPageSetupDlg pgSetupDlg;
	int nRet = pgSetupDlg.DoModal();

	switch ( nRet )   
	{   
	case -1:     
		AfxMessageBox(_T("Dialog box could not be created!"));
      break;
    case IDABORT:
      // Do something
       break;
    case IDOK:
       // Do something
       break;
    case IDCANCEL:
      // Do something
       break;
    default:
      // Do something
      break;
   }//end of switch

}//end of CCgUIApp::OnFilePageSetup() 

/////////////////////////////////////////////////////////////////////////////////////////////
BOOL CCgUIApp::InitApplication() 
{
	// TODO: Add your specialized code here and/or call the base class
	TRACE0( "cgUI.cpp : CCgUIApp::InitApplication\n" );

	HWND hAppWnd = ::FindWindow( NULL, APP_TITLE );
	if( hAppWnd )
	{
		::SetForegroundWindow( hAppWnd );
		::exit( 0 );
	}//end of if - hAppWnd
	
	ZeroMemory( g_szAppPath, MAX_PATH );
	GetCurrentDirectory( _MAX_PATH, (LPTSTR)g_szAppPath );
	CString tmpPath( g_szAppPath );
	SetAppPath( tmpPath );	// set the app path here

	g_CodePage = GetCodePage();
	SetUILanguage();

	g_hCursor.Arrow     = LoadCursor( MAKEINTRESOURCE(IDC_NORMAL));
	g_hCursor.FourWay   = LoadCursor( MAKEINTRESOURCE(IDC_4WAY)  );
	g_hCursor.Horz      = LoadCursor( MAKEINTRESOURCE(IDC_HORIZ) );
	g_hCursor.Vert      = LoadCursor( MAKEINTRESOURCE(IDC_VERT)  );
	g_hCursor.LeftRight = LoadCursor( MAKEINTRESOURCE(IDC_LEFT_RIGHT) );
	g_hCursor.RightLeft = LoadCursor( MAKEINTRESOURCE(IDC_RIGHT_LEFT) );
	g_hCursor.RotateZ   = LoadCursor( MAKEINTRESOURCE(IDC_ROTATE)  );

	return CWinApp::InitApplication();
}//end of CCgUIApp::InitApplication
/////////////////////////////////////////////////////////////////////////////////////////////
int CCgUIApp::ExitInstance() 
{
	TRACE0( "cgUI.cpp : CCgUIApp::ExitInstance\n" );

	CGS_Close();
	return CWinApp::ExitInstance();
}///end of CCgUIApp::ExitInstance()
/////////////////////////////////////////////////////////////////////////////////////////////
int CCgUIApp::Run() 
{
	// TODO: Add your specialized code here and/or call the base class
	TRACE0( "cgUI.cpp : CCgUIApp::Run\n" );
	AfxGetMainWnd()->SendMessage( WM_COMMAND, ID_LOAD_MENU, 0 );
	
	return CWinApp::Run();
}//end of CCgUIApp::Run()
/////////////////////////////////////////////////////////////////////////////////////////////
void CCgUIApp::AddToRecentFileList(LPCTSTR pPathName) 
{
	TRACE0("cgUI.cpp : CCgUIApp::AddToRecentFileList\n" );
	if( m_ixFileMgr.AddToRecentFileList(pPathName) )
		return;

	CWinApp::AddToRecentFileList(pPathName);
}//end of CCgUIApp::AddToRecentFileList
/////////////////////////////////////////////////////////////////////////////////////////////
BOOL CCgUIApp::OnCmdMsg(UINT nID, int nCode, void* pExtra, AFX_CMDHANDLERINFO* pHandlerInfo) 
{
	if( m_ixFileMgr.OnCmdMsg(nID, nCode, pExtra, pHandlerInfo) )
		return( 1 );

	return CWinApp::OnCmdMsg(nID, nCode, pExtra, pHandlerInfo);
}//end of CCgUIApp::OnCmdMsg

////////////////////////////////////////////////////////////////////////////////////////
// Make sure the application path is located in the current directory.
// If not, do the file search from the point of GetCurrentPath().
// INPUT : CString tmpPath - path return by GetCurrentPath()
VOID CCgUIApp::SetAppPath( CString tmpPath )
{
 	tmpPath += _T("\\*.*");
 	CFileFind finder;
 	BOOL bWorking = finder.FindFile( tmpPath );
 	while( bWorking )   
 	{
 		bWorking = finder.FindNextFile();
		if( !stricmp( finder.GetFileName(), _T("alpha.exe") )) 
 		{
 			_tcscpy( g_szAppPath, (_TCHAR*)(LPCTSTR)finder.GetRoot() );
 			return;
 		}
 		if( finder.IsDots() )
 			continue;
 		if( finder.IsDirectory() )
 		{
 			CString str = finder.GetFilePath();
 			SetAppPath(str);			
 		}// end of if
 	}// end of while
}//end of CCgUIApp::SetAppPath()
