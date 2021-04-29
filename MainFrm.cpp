/* COPYRIGHT NOTICE:
********************************************************
********************************************************
*/
// MainFrm.cpp : implementation of the CMainFrame class
//

#include "stdafx.h"
#include "cgUI.h"
#include "cgUIDoc.h"
#include "MainFrm.h"
#include "afxpriv.h"
#include "AddPic.h"
#include "FileReq.h"
#include "PageSetupDlg.h"
#include "TitleVdoSetup.h"
#include "SpellCheck.h"
#include "DlgBarLeft.h"
#include "VMVdoSetup.h"
#include "DlgPrefer.h"
#include <direct.h>
#include "Communicate.h"
#include "CharMap.h"
#include "FontLocator.h"
#include "AcgMsgBox.h"
#include "ProgSetting.h"
#include "PalDlg.h"

#include "TWAIN.H"
#include "TABLE.H"
#include "DCA_GLUE.H"
#include "DCA_APP.H"
#include "DCA_ACQ.H"
#include "CAPTEST.H"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

// From AFXIMPL.H
#define		_countof(array)		(sizeof(array)/sizeof(array[0]))
#define		_COMM			0
#define		CX_BOTTOM_DLG	640
#define		ATTRIB_BOX_X	10
#define		PALVERSION      0x300	
#define		LD_PIC_TIMER	0x301
#define		TOP_WND_TIMER	0x302

extern CURSOR_HANDLE	g_hCursor;
extern DWORD			g_txtGfxState;
extern _TCHAR			UILang_UIFont[256];
extern int				UILang_UIFontSize;

static HGLOBAL  _ghDIB		= NULL; // handle to the current DIB
static HBITMAP  hbm			= NULL;	// holder handle to bit map passed from Source
static HPALETTE hDibPal		= NULL;	// handle to palette
static int      FirstDraw	= 0;
/////////////////////////////////////////////////////////////////////////////
// CMainFrame

static UINT BASED_CODE PanelButtons[] =
{	// same order as in the bitmap
	ID_FORMAT_LFT, // left
	ID_FORMAT_CNT, // center
	ID_FORMAT_RIT, // right
	ID_FORMAT_JUT, // justify
	ID_FORMAT_TOP, // top
	ID_FORMAT_MID, // middle
	ID_FORMAT_BOT, // bottom
	ID_FORMAT_PTR, // pointer - deleted on 11-15-2000
	ID_FORMAT_PAL, // palette
	ID_FORMAT_GRD  // grid
};

IMPLEMENT_DYNAMIC(CMainFrame, CMDIFrameWnd)

BEGIN_MESSAGE_MAP(CMainFrame, CMDIFrameWnd)
	ON_COMMAND_EX(CG_ID_VIEW_BOTTOM, OnBarCheck)
	ON_UPDATE_COMMAND_UI(CG_ID_VIEW_BOTTOM, OnUpdateControlBarMenu)
	//{{AFX_MSG_MAP(CMainFrame)
	ON_WM_CREATE()
	ON_COMMAND(ID_FORMAT_LFT, OnFmtLeft)
	ON_COMMAND(ID_FORMAT_CNT, OnFmtCenter)
	ON_COMMAND(ID_FORMAT_RIT, OnFmtRight)
	ON_COMMAND(ID_FORMAT_JUT, OnFmtJustify)
	ON_COMMAND(ID_FORMAT_TOP, OnFmtTop)
	ON_COMMAND(ID_FORMAT_MID, OnFmtMiddle)
	ON_COMMAND(ID_FORMAT_BOT, OnFmtBottom)
	ON_COMMAND(ID_VIEW_PANEL_BAR, OnViewPanelBar)
	ON_UPDATE_COMMAND_UI(ID_VIEW_PANEL_BAR, OnUpdateViewPanelBar)
	ON_WM_SIZE()	
	ON_COMMAND(ID_FORMAT_GRD, OnFmtGrid)
	ON_COMMAND(ID_TXTGFX_BOX, OnAddObjBox)
	ON_COMMAND(ID_TXTGFX_FILL, OnAddObjFill)
	ON_COMMAND(ID_TXTGFX_LINE, OnAddObjLine)
	ON_COMMAND(ID_TXTGFX_OVAL, OnAddObjOval)
	ON_COMMAND(ID_TXTGFX_TEXT, OnAddObjText)
	ON_COMMAND(ID_TXTGFX_IMPORT, OnAddObjImport)
	ON_COMMAND(ID_FORMAT_PAL, OnFormatPal)
	ON_COMMAND(ID_FORMAT_PTR, OnFormatPtr) // This function was deleted on 11-15-2000
	ON_COMMAND(ID_FILE_OPEN, OnFileOpen)
	ON_COMMAND(ID_VDO_SET_UP, OnVdoSetUp)
	ON_COMMAND(ID_PG_ADD_PIC, OnPgAddPic)
	ON_COMMAND(ID_PG_CLEAR_ALL, OnPgClearAll)
	ON_COMMAND(ID_PG_CLEAR_TEXT, OnPgClearText)
	ON_COMMAND(ID_PG_WORD_WRAP, OnPgWordWrap)
	ON_COMMAND(ID_PG_CLEAR_GRAPHIC, OnPgClearGraphic)
	ON_COMMAND(ID_PG_SPELL_CHECK, OnPgSpellCheck)
	ON_COMMAND(ID_LOAD_MENU, OnLoadNewMenu)
	ON_COMMAND(ID_FILE_SAVE, OnFileSave)
	ON_COMMAND(ID_REFRESH_ATT_BOX, OnRefreshAttBox)
	ON_COMMAND(ID_REFRESH_CAPTURE, OnRefreshAttCapture)
	ON_COMMAND(ID_REFRESH_ATT_FACE, OnRefreshAttFace)
	ON_COMMAND(ID_REFRESH_ATT_LINE, OnRefreshAttLine)
	ON_COMMAND(ID_REFRESH_ATT_OUTLINE1, OnRefreshAttOutline1)
	ON_COMMAND(ID_REFRESH_ATT_OUTLINE2, OnRefreshAttOutline2)
	ON_COMMAND(ID_REFRESH_ATT_OVAL, OnRefreshAttOval)
	ON_COMMAND(ID_REFRESH_ATT_SHADOW, OnRefreshAttShadow)
	ON_COMMAND(ID_REFRESH_ATT_CAST, OnRefreshAttCast)
	ON_COMMAND(ID_REFRESH_ATT_TEXT, OnRefreshAttText)
	ON_COMMAND(ID_REFRESH_EFFECT, OnRefreshEffect)
	ON_COMMAND(ID_REFRESH_PAGE, OnRefreshPage)
	ON_COMMAND(ID_REFRESH_ATT_FILL, OnRefreshAttFill)
	ON_COMMAND(IDM_COMM_RECEIVER, OnCommReceiver)
	ON_COMMAND(IDM_COMM_SENDER, OnCommSender)
	ON_COMMAND(IDM_DOWNLOAD, OnDownload)
	ON_COMMAND(IDM_HOST_FINDER, OnHostFinder)
	ON_COMMAND(IDM_MODEM, OnModem)
	ON_COMMAND(ID_FILE_NEW, OnFileNew)
	ON_COMMAND(ID_FILE_MRU_FILE1, OnFileMruFile1)
	ON_UPDATE_COMMAND_UI(ID_FILE_MRU_FILE1, OnUpdateFileMruFile1)
	ON_COMMAND(ID_FILE_MRU_PROJ1, OnFileMruProj1)
	ON_UPDATE_COMMAND_UI(ID_FILE_MRU_PROJ1, OnUpdateFileMruProj1)
	ON_COMMAND(ID_FILE_SAVE_AS, OnFileSaveAs)
	ON_COMMAND(ID_FORMAT_UNDO, OnFmtUndo)
	ON_COMMAND(ID_FORMAT_REDO, OnFmtRedo)
	ON_COMMAND(ID_FILE_TAB_SETUP, OnFileTabSetup)
	ON_WM_CLOSE()
	ON_COMMAND(ID_FILE_PREFERENCE, OnFilePreference)
	ON_COMMAND(ID_FILE_PRINT, OnFilePrint)
	ON_COMMAND(ID_FILE_IMPORT_TEXT, OnFileImportText)
	ON_COMMAND(ID_CLIP_COPY, OnClipCopy)
	ON_COMMAND(ID_CLIP_PASTE, OnClipPaste)
	ON_COMMAND(ID_VIEW_TOOLBAR, OnViewToolbar)
	ON_UPDATE_COMMAND_UI(ID_VIEW_TOOLBAR, OnUpdateViewToolbar)
	ON_COMMAND(ID_FILE_SELECT_SCANNER, OnFileSelectScanner)
	ON_COMMAND(ID_FILE_SCAN_IMAGE, OnFileScanImage)
	ON_WM_TIMER()
	ON_COMMAND(ID_EDIT_CHAR_MAP, OnEditCharMap)
	ON_COMMAND(ID_EDIT_FONT_LOCATOR, OnEditFontLocator)
	ON_COMMAND(ID_REFRESH_BASELINE, OnRefreshBaseline)
	ON_COMMAND(ID_UNCHECK_ALPHA, OnUncheckAlpha)
	ON_COMMAND(ID_FILE_IMPORT_GFX, OnFileImportGfx)
	ON_COMMAND(ID_FILE_EXPORT_PAGE, OnFileExportPage)
	ON_COMMAND(ID_FILE_EXPORT_PROJECT, OnFileExportProject)
	ON_COMMAND(ID_TXTGFX_MAG, OnAddObjMag)
	ON_COMMAND(ID_TXTGFX_MAG_MINUS, OnAddObjMagMinus)
	ON_COMMAND(ID_TXTGFX_MAG_PLUS, OnAddObjMagPlus)
	ON_COMMAND(ID_HELP_TOPICS, OnHelpTopics)
	ON_COMMAND(ID_FILE_PROG_SETTING, OnProgramSetting)
	ON_COMMAND(ID_LN_CLEAR, OnLnClear)
	ON_COMMAND(ID_LN_DELETE, OnLnDelete)
	ON_COMMAND(ID_LN_INSERT_AFTER, OnLnInsertAfter)
	ON_COMMAND(ID_LN_INSERT_BEFORE, OnLnInsertBefore)
	ON_COMMAND(ID_LN_JUST_CENTER, OnLnJustCenter)
	ON_COMMAND(ID_LN_JUST_FLUSH, OnLnJustFlush)
	ON_COMMAND(ID_LN_JUST_LEFT, OnLnJustLeft)
	ON_COMMAND(ID_LN_JUST_RIGHT, OnLnJustRight)
	ON_COMMAND(ID_STYLE_COPY, OnStyleCopy)
	ON_COMMAND(ID_STYLE_PASTE, OnStylePaste)
	ON_COMMAND(ID_STYLE_RESET, OnStyleReset)
	ON_COMMAND(ID_STYLE_SAVE_TO_BIN, OnStyleSaveToBin)
	ON_COMMAND(ID_FKEY_F1, OnFkeyF1)
	ON_COMMAND(ID_FKEY_F10, OnFkeyF10)
	ON_COMMAND(ID_FKEY_F11, OnFkeyF11)
	ON_COMMAND(ID_FKEY_F12, OnFkeyF12)
	ON_COMMAND(ID_FKEY_F2, OnFkeyF2)
	ON_COMMAND(ID_FKEY_F3, OnFkeyF3)
	ON_COMMAND(ID_FKEY_F4, OnFkeyF4)
	ON_COMMAND(ID_FKEY_F5, OnFkeyF5)
	ON_COMMAND(ID_FKEY_F6, OnFkeyF6)
	ON_COMMAND(ID_FKEY_F7, OnFkeyF7)
	ON_COMMAND(ID_FKEY_F8, OnFkeyF8)
	ON_COMMAND(ID_FKEY_F9, OnFkeyF9)
	ON_COMMAND(ID_PAGE_CENTER, OnPageCenter)
	ON_COMMAND(ID_PAGE_COPY, OnPageCopy)
	ON_COMMAND(ID_PAGE_CUT, OnPageCut)
	ON_COMMAND(ID_PAGE_DUPLICATE, OnPageDuplicate)
	ON_COMMAND(ID_PAGE_FLUSH, OnPageFlush)
	ON_COMMAND(ID_PAGE_IN_NEW_AFTER, OnPageInNewAfter)
	ON_COMMAND(ID_PAGE_IN_NEW_BEFORE, OnPageInNewBefore)
	ON_COMMAND(ID_PAGE_LEFT, OnPageLeft)
	ON_COMMAND(ID_PAGE_PASTE_AFTER, OnPagePasteAfter)
	ON_COMMAND(ID_PAGE_PASTE_BEFORE, OnPagePasteBefore)
	ON_COMMAND(ID_PAGE_RIGHT, OnPageRight)
	ON_COMMAND(ID_ED_REDO, OnEdRedo)
	ON_COMMAND(ID_ED_UNDO, OnEdUndo)
	ON_COMMAND(ID_POS_PASTE, OnPasteInPosition)
	ON_COMMAND(ID_TXTGFX_POLYGON, OnAddObjPolygon)
	ON_COMMAND(ID_TXTGFX_CURV, OnAddObjCurve)
	ON_COMMAND(ID_REFRESH_ATT_CURV, OnRefreshAttCurve)
	ON_COMMAND(ID_REFRESH_ATT_POLY, OnRefreshAttPoly)
	ON_COMMAND(ID_REFRESH_ATT_PIC, OnRefreshAttPic)
	ON_COMMAND(ID_SET_PAGE_SCROLL_POS, OnSetPageScrollPos)
	ON_COMMAND(ID_SET_BIN_TOP_SCROLL_POS, OnSetBinTopScrollPos)
	ON_COMMAND(ID_SET_BIN_BOT_SCROLL_POS, OnSetBinBotScrollPos)
	//}}AFX_MSG_MAP
	ON_NOTIFY_EX_RANGE(TTN_NEEDTEXTW, 0, 0xFFFF, OnDynamicTipText)
    ON_NOTIFY_EX_RANGE(TTN_NEEDTEXTA, 0, 0xFFFF, OnDynamicTipText)
	ON_MESSAGE( WM_RESIZE_LEFT_BAR, OnResizeLeftBar )
	ON_MESSAGE( WM_RESIZE_RTOP_BIN, OnResizeTopBin )
	ON_MESSAGE( PM_XFERDONE, OnTWXferDone )
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMainFrame construction/destruction
/////////////////////////////////////////////////////////////////////////////
CMainFrame::CMainFrame()
{
	// TODO: add member initialization code here
	TRACE0( "MainFrm.cpp : CMainFrame::CMainFrame - constructor\n" );

	m_bPanelBar		= 1;			//default show panel tool bar
	m_bToolBar		= 1;
	m_pDlgText		= NULL;
	m_pDlgLine		= NULL;
	m_pDlgCurv		= NULL;
	m_pDlgPoly		= NULL;
	m_pDlgBox		= NULL;
	m_pDlgFill		= NULL;
	m_pDlgOval		= NULL;
	m_pDlgImport	= NULL;

	g_txtGfxState	= ID_TXTGFX_BOX;	// default
	m_vdoSetupType  = SETUP_TYPE;		// set the machine type	
	LoadMenuText();
}//end of constructor
/////////////////////////////////////////////////////////////////////////////
CMainFrame::~CMainFrame()
{
	if( m_ttData != NULL )
		free( m_ttData );

	delete [] m_pMainMenu;
	delete [] m_pSubMenu;

	CleanAttribDlgs();
}//end of destructor

/////////////////////////////////////////////////////////////////////////////////////////
// Create the main window frame and do all initialization for the frame attribute
// Must create bottom dialog bar at the end because of the focus issue
// NOTE : Because of inconsistenc of GUI layout. Name convention is not match with 
//        function of GUI layout. MUST function change names later.
int CMainFrame::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	TRACE0("MainFrm.cpp : CMainFrame::OnCreate\n" );
	if( CMDIFrameWnd::OnCreate(lpCreateStruct) == -1 )
		return -1;

	CreateMainToolbar();	// +++++++ Create Toolbar	
	
	CreateDlgBarTopBin();	// create this one first
	CreateTxtGfxToolbar();  // then create tool bar

//	CreateDlgBarBotBin();	
//	CreateDlgBarCir();
//	CreateDlgBarFbg();
//	CreateDlgBarGrd();
//	CreateDlgBarLne();
//	CreateDlgBarPal();

	CreateDlgBarLeft();		// +++++++ Create Dialog bar	
	CreateDlgBarBottom();	// Must be the last one because of focus issue	

	m_numTip = LoadTooltipText( "\\Util\\Toolbar.ctl", &m_ttData );

	SetWindowText( APP_TITLE ); // application title

	//JRS 00-12-18 add dongle support ----------------
	#if _ENABLE_DONGLE_CHECK
	double DongleInitOK;
	DongleInitOK=CGS_GetValDbl(STATUS_DONGLE_INIT);
	if(DongleInitOK==0.0)
	{
		AfxMessageBox(_T("Error: InnoVision security device not found.\nPlease check that device is attached to parallel port."));
		_exit(1);
	}
	#endif //_ENABLE_DONGLE_CHECK
	//------------------------------------------------
	
	SetTimer( TOP_WND_TIMER, 5000, 0 );
	return( 0 );
}//end of CMainFrame::OnCreate
/////////////////////////////////////////////////////////////////////////////
BOOL CMainFrame::PreCreateWindow(CREATESTRUCT& cs)
{
	TRACE0("MainFrm.cpp : CMainFrame::PreCreateWindow\n" );
	if( !CMDIFrameWnd::PreCreateWindow(cs) )
		return FALSE;
	
	cs.style &= ~FWS_ADDTOTITLE;

	// TODO: Modify the Window class or styles here by modifying the CREATESTRUCT cs
	HDC hDC  = ::GetDC( NULL ); // primary display device DC
	INT xRes = GetDeviceCaps( hDC, HORZRES );
	INT yRes = GetDeviceCaps( hDC, VERTRES );

	if( yRes < 768 )
	{
		m_winW = 800; m_winH = 582;
	}
	else
	{
		m_winW = 1024; m_winH = 740;
	}

	cs.cx = m_winW;
	cs.cy = m_winH;
	cs.x  = 0;
	cs.y  = 0;

	::ReleaseDC( NULL, hDC );
	return TRUE;
}//end of PreCreateWindow

/////////////////////////////////////////////////////////////////////////////
// CMainFrame diagnostics

#ifdef _DEBUG
void CMainFrame::AssertValid() const
{
	CMDIFrameWnd::AssertValid();
}
/////////////////////////////////////////////////////////////////////////////
void CMainFrame::Dump(CDumpContext& dc) const
{
	CMDIFrameWnd::Dump(dc);
}

#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CMainFrame message handlers
/////////////////////////////////////////////////////////////////////////////
// By default, DockControlBar will dock each Toolbar on a seperate line.  
// By calculating a rectangle, we in effect are simulating a Toolbar being 
// dragged to that location and docked.
// INPUT : CControlBar *pLeftOf - pointer to the right handside toolbar
// INPUT : CControlBar *pBar - pointer to the left hand side toolbar 
void CMainFrame::DockControlBarLeftOf(CControlBar *pLeftOf, CControlBar *pBar )
{
/*** comment out 10-13-00 ***
	TRACE0("MainFrm.cpp : CMainFrame::DockControlBarLeftOf\n" );
	CRect rect;
	DWORD dw;
	UINT n;

	// get MFC to adjust the dimensions of all docked ToolBars
	// so that GetWindowRect will be accurate
	RecalcLayout();
	pLeftOf->GetWindowRect(&rect);
	rect.OffsetRect(1,0);
	dw = pLeftOf->GetBarStyle();
	n = 0;
	n = (dw&CBRS_ALIGN_TOP) ? AFX_IDW_DOCKBAR_TOP : n;
	n = (dw&CBRS_ALIGN_BOTTOM && n==0) ? AFX_IDW_DOCKBAR_BOTTOM : n;
	n = (dw&CBRS_ALIGN_LEFT && n==0) ? AFX_IDW_DOCKBAR_LEFT : n;
	n = (dw&CBRS_ALIGN_RIGHT && n==0) ? AFX_IDW_DOCKBAR_RIGHT : n;

	DockControlBar(pBar,n,&rect);
*** comment out 10-13-00 ***/
}//end of DockControlBarLeftOf

/////////////////////////////////////////////////////////////////////////////
// By default, DockControlBar will dock each Toolbar on a seperate line.  
// By calculating a rectangle, we in effect are simulating a Toolbar being 
// dragged to that location and docked.
// INPUT : CControlBar *pBottomOf - pointer to the bottom side toolbar
// INPUT : CControlBar *pBar - pointer to the top side toolbar 
// Using CControlBar make this function work for both Toolbar and Dialog bar
void CMainFrame::DockControlBarBottomOf(CControlBar *pBottomOf, CControlBar *pBar)
{
/*** comment out 10-13-00
	TRACE0("MainFrm.cpp : CMainFrame::DockControlBarBottomOf\n" );
	CRect	rect;
	DWORD	dw;
	UINT	n;

	RecalcLayout();
	pBottomOf->GetWindowRect(&rect);
	rect.OffsetRect(1,1);
	dw = pBottomOf->GetBarStyle();
	n = 0;
	n = (dw&CBRS_ALIGN_TOP) ? AFX_IDW_DOCKBAR_TOP : n;
	n = (dw&CBRS_ALIGN_BOTTOM && n==0) ? AFX_IDW_DOCKBAR_BOTTOM : n;
	n = (dw&CBRS_ALIGN_LEFT && n==0) ? AFX_IDW_DOCKBAR_LEFT : n;
	n = (dw&CBRS_ALIGN_RIGHT && n==0) ? AFX_IDW_DOCKBAR_RIGHT : n;
	
	DockControlBar(pBar,n,&rect);
*** comment out 10-13-00 ***/

}//end of DockControlBarBottomOf
///////////////////////////////////////////////////////////////////////////////////////////////
void CMainFrame::OnFmtUndo() 
{
	CGS_EditUndo();	
}//end of CMainFrame::OnFmtUndo
///////////////////////////////////////////////////////////////////////////////////////////////
void CMainFrame::OnFmtRedo() 
{
	CGS_EditRedo();
	
}//end of CMainFrame::OnFmtRedo
///////////////////////////////////////////////////////////////////////////////////////////////
// Left justify the whole page
void CMainFrame::OnFmtLeft() 
{
	TRACE0("MainFrm.cpp : CMainFrame::OnFmtLeft()\n");
	CGS_Action(CGSA_PAGE_JUSTIFY_LEFT);
	
}//end of OnFmtLeft
/////////////////////////////////////////////////////////////////////////////
// Center justify the whole page
void CMainFrame::OnFmtCenter() 
{
	CGS_Action(CGSA_PAGE_JUSTIFY_CENTER);
}//end of OnFmtCenter
/////////////////////////////////////////////////////////////////////////////
// Right justify the whole page
void CMainFrame::OnFmtRight() 
{
	CGS_Action(CGSA_PAGE_JUSTIFY_RIGHT);
}//end of OnFmtRight
/////////////////////////////////////////////////////////////////////////////
// Force justify
void CMainFrame::OnFmtJustify() 
{
	CGS_Action(CGSA_PAGE_JUSTIFY_FLUSH);
}//end of OnFmtJustify
/////////////////////////////////////////////////////////////////////////////
void CMainFrame::OnFmtGrid() 
{
	IXReg_UpdateVertScrollBar( 53.333 );

}//end of CMainFrame::OnFmtGrid
/////////////////////////////////////////////////////////////////////////////
// Vertical Top
void CMainFrame::OnFmtTop() 
{
	CGS_Action(CGSA_PAGE_V_JUSTIFY_BOT);
}//end of OnFmtTop
/////////////////////////////////////////////////////////////////////////////
void CMainFrame::OnFmtMiddle() 
{
	CGS_Action(CGSA_PAGE_V_JUSTIFY_CENTER);
}//end of OnFmtMiddle
/////////////////////////////////////////////////////////////////////////////
void CMainFrame::OnFmtBottom() 
{
	CGS_Action(CGSA_PAGE_V_JUSTIFY_BOT);
}//end of OnFmtBottom
/////////////////////////////////////////////////////////////////////////////
// By default, panel bar is show up. ie: Only Toggle the menu and 
// show or hide the panel bar.
// NOTE : For unknow reason, after the panel bar is toggled, the left dialog 
// bar will change back to the default size (640x480), ie: need to redraw it.

void CMainFrame::OnViewToolbar() 
{
	TRACE0("MainFrm.cpp : CMainFrame::OnViewToolbar\n");
	m_bToolBar ^= 1;	

	if( m_bToolBar )
		ShowControlBar( &m_wndToolBar, 1, 0 );
	else
		ShowControlBar( &m_wndToolBar, 0, 0 );

	OnResizeLeftBar( 0, 0 );
	m_dlgBarLeft.m_pDlgPage->RedrawWindow(NULL, NULL, RDW_INVALIDATE | RDW_UPDATENOW | RDW_ERASE );
}//end of OnViewToolbar()
/////////////////////////////////////////////////////////////////////////////
// Check is the panel bar has been close or not. Handle the situation that
// the panel bar was closed by the system close buttom but not the menu.
void CMainFrame::OnUpdateViewToolbar(CCmdUI* pCmdUI) 
{	
/** comment out on 10-13-00
	TRACE0("MainFrm.cpp : CMainFrame::OnUpdateViewToolbar\n");
	if( (m_wndToolBar.GetStyle() & WS_VISIBLE) == WS_VISIBLE )
	{
		m_bToolBar = 1;
		pCmdUI->SetCheck( 1 );
	}
	else
	{
		m_bToolBar = 0;
		pCmdUI->SetCheck( 0 );
	}	
*** comment out on 10-13-00 ****/
}//end of OnUpdateViewToolbar

/////////////////////////////////////////////////////////////////////////////
// By default, panel bar is show up. ie: Only Toggle the menu and 
// show or hide the panel bar.
// NOTE : For unknow reason, after the panel bar is toggled, the left dialog 
// bar will change back to the default size (640x480), ie: need to redraw it.
void CMainFrame::OnViewPanelBar() 
{

	TRACE0("MainFrm.cpp : CMainFrame::OnViewPanelBar\n");
	m_bPanelBar ^= 1;	

	if( m_bPanelBar )
		ShowControlBar( &m_wndPanelBar, 1, 0 );
	else
		ShowControlBar( &m_wndPanelBar, 0, 0 );

	OnResizeLeftBar( 0, 0 );
	m_dlgBarLeft.m_pDlgPage->RedrawWindow(NULL, NULL, RDW_INVALIDATE | RDW_UPDATENOW | RDW_ERASE );

}//end of OnViewPanelBar
/////////////////////////////////////////////////////////////////////////////
// Check is the panel bar has been close or not. Handle the situation that
// the panel bar was closed by the system close buttom but not the menu.
void CMainFrame::OnUpdateViewPanelBar(CCmdUI* pCmdUI) 
{
/*
	TRACE0("MainFrm.cpp : CMainFrame::OnUpdateViewPanelBar\n");
	if( (m_wndPanelBar.GetStyle() & WS_VISIBLE) == WS_VISIBLE )
	{
		m_bPanelBar = 1;
		pCmdUI->SetCheck( 1 );
	}
	else
	{
		m_bPanelBar = 0;
		pCmdUI->SetCheck( 0 );
	}
*/
}//end of OnUpdateViewPanelBar
/////////////////////////////////////////////////////////////////////////////
// Default main toolbar
void CMainFrame::CreateMainToolbar()
{	
	if( !m_wndToolBar.CreateEx(this, TBSTYLE_FLAT, WS_CHILD | WS_VISIBLE | CBRS_TOP
		| /*CBRS_GRIPPER |*/ CBRS_TOOLTIPS /*| CBRS_FLYBY | CBRS_SIZE_DYNAMIC*/) ||
		!m_wndToolBar.LoadToolBar(IDR_MAINFRAME))
	{
		TRACE0("Failed to create toolbar\n");
		return;      // fail to create
	}

	// create docking toolbar
	m_wndToolBar.EnableDocking(CBRS_ALIGN_ANY);
	EnableDocking(CBRS_ALIGN_ANY); // Can dock all four sides
	DockControlBar(&m_wndToolBar);

}//end of CMainFrame::CreateMainToolbar()
/////////////////////////////////////////////////////////////////////////////
void CMainFrame::CreateTxtGfxToolbar()
{

	if( !m_wndTxtGfxBar.CreateEx(this, TBSTYLE_FLAT, WS_CHILD | WS_VISIBLE | CBRS_RIGHT
		| CBRS_TOOLTIPS /*| CBRS_FLYBY | CBRS_SIZE_DYNAMIC*/) ||
#if LITE_TOOLBAR
		!m_wndTxtGfxBar.LoadToolBar(IDR_LITE_TXTGRAF))
#else
		!m_wndTxtGfxBar.LoadToolBar(IDR_TEXTGRAPH))
#endif
	{
		TRACE0("Failed to create toolbar\n");
		return;      // fail to create
	}

	// create docking toolbar
	m_wndTxtGfxBar.SetWindowText(_T("Text Graph Bar") );
	m_wndTxtGfxBar.EnableDocking(CBRS_ALIGN_RIGHT);
}//end of CMainFrame::CreateTxtGfxToolbar()
/////////////////////////////////////////////////////////////////////////////
// Create bottom dialog bar. Only able to dock on the bottom.
void CMainFrame::CreateDlgBarBottom()
{
	TRACE0( "MainFrm.cpp : CMainFrame::CreateDlgBarBottom\n" );
	if( !m_dlgBarBot.Create(this, IDD_DLGBAR_BOTTOM, CBRS_BOTTOM, IDD_DLGBAR_BOTTOM))
	{
		TRACE0("Failed to create bottom dialog bar from CDlgBarBot class\n");
		return;      // fail to create
	}
	// rename the title name when floating	
	m_dlgBarBot.SetWindowText(_T("Bottom dialog bar"));

	m_dlgBarBot.EnableDocking(CBRS_ALIGN_BOTTOM); // Dock bottom only
	DockControlBar(&m_dlgBarBot);

}//end of CMainFrame::CreateDlgBarBottom()

/////////////////////////////////////////////////////////////////////////////
// Create right handside text dialog bar. Able to dock both left & right side.
void CMainFrame::CreateDlgBarTopBin()
{
	TRACE0( "MainFrm.cpp : CMainFrame::CreateDlgBarTopBin\n" );
	if( !m_dlgBarBinTop.Create(this, IDD_DLGBAR_BINTOP, CBRS_RIGHT , IDD_DLGBAR_BINTOP))
	{
		TRACE0("Failed to create TXT Panel dialog bar from CDlgBarTxt class\n");
		return;      // fail to create
	}
	// rename the title name when floating	
	m_dlgBarBinTop.SetWindowText( _T("Top Bin dlg bar") ); 

}//end of CMainFrame::CreateDlgBarTopBin()
/////////////////////////////////////////////////////////////////////////////
// Create the left hand side dialog bar for page and layer.
// Only able to dock on left or right side
void CMainFrame::CreateDlgBarLeft()
{
	if( !m_dlgBarLeft.Create(this, IDD_DLGBAR_LEFT, CBRS_LEFT/*|CBRS_SIZE_DYNAMIC|CBRS_FLYBY*/, IDD_DLGBAR_LEFT))
	{
		TRACE0("Failed to create left dialog bar from CDlgBarLeft class\n");
		return;      // fail to create
	}
	// rename the title name when floating	
	m_dlgBarLeft.SetWindowText(_T("Left dialog bar")); 
	m_dlgBarLeft.m_pDlgPage  = NULL;
	m_dlgBarLeft.m_pDlgLayer = NULL;

//051699 - add 
 	m_dlgBarLeft.EnableDocking(CBRS_ALIGN_LEFT); // Dock left only
	DockControlBar(&m_dlgBarLeft);
//051699 - add

}//end of CMainFrame::CreateDlgBarLeft()
/////////////////////////////////////////////////////////////////////////////
// Create right handside circular dialog bar. Able to dock on left or right
void CMainFrame::CreateDlgBarCir()
{
	if( !m_dlgBarCir.Create(this, IDD_DLGBAR_PCIR, CBRS_RIGHT , IDD_DLGBAR_PCIR))
	{
		TRACE0("Failed to create Cir panel dialog bar from CDlgBarCir class\n");
		return;      // fail to create
	}
	// rename the title name when floating	
	m_dlgBarCir.SetWindowText(_T("Cir dialog bar")); 
	ShowControlBar( &m_dlgBarCir, 0, 0 );

}//end of CMainFrame::CreateDlgBarCir()

/////////////////////////////////////////////////////////////////////////////
// Create right handside dialog bar. Able to dock on left or right
void CMainFrame::CreateDlgBarFbg()
{
	if( !m_dlgBarFbg.Create(this, IDD_DLGBAR_PFBG, CBRS_RIGHT , IDD_DLGBAR_PFBG))
	{
		TRACE0("Failed to create Fbg panel dialog bar from CDlgBarFbg class\n");
		return;      // fail to create
	}
	// rename the title name when floating	
	m_dlgBarFbg.SetWindowText(_T("Fbg dialog bar")); 
	ShowControlBar( &m_dlgBarFbg, 0, 0 );

}//end of CMainFrame::CreateDlgBarFbg()

/////////////////////////////////////////////////////////////////////////////
// Create right handside Grd dialog bar. Able to dock on right and left side.
void CMainFrame::CreateDlgBarGrd()
{
	if( !m_dlgBarGrd.Create(this, IDD_DLGBAR_PGRD, CBRS_RIGHT , IDD_DLGBAR_PGRD))
	{
		TRACE0("Failed to create Grd panel dialog bar from CDlgBarGrd class\n");
		return;      // fail to create
	}
	// rename the title name when floating	
	m_dlgBarGrd.SetWindowText(_T("Grd dialog bar")); 
	ShowControlBar( &m_dlgBarGrd, 0, 0 );

}//end of CMainFrame::CreateDlgBarGrd()

/////////////////////////////////////////////////////////////////////////////
// Create right hand side palette dialog bar. Able to dock on right and left side.
void CMainFrame::CreateDlgBarPal()
{
	if( !m_dlgBarPal.Create(this, IDD_DLGBAR_PPAL, CBRS_RIGHT , IDD_DLGBAR_PPAL))
	{
		TRACE0("Failed to create Pal panel dialog bar from CDlgBarPal class\n");
		return;      // fail to create
	}
	// rename the title name when floating	
	m_dlgBarPal.SetWindowText(_T("Pal dialog bar") ); 
	ShowControlBar( &m_dlgBarPal, 0, 0 );

}//end of CMainFrame::CreateDlgBarPal()
/////////////////////////////////////////////////////////////////////////////
// Notification message for showing tooltip.
// INPUT : UINT id - control id that mouse pointing to
// INPUT : NMHDR *pNMHDR - pointer to notification message
// OUTPUT: LRESULT *pResult - result
// RETURN: BOOL - 1 is OK
BOOL CMainFrame::OnDynamicTipText(UINT id, NMHDR *pNMHDR, LRESULT *pResult)
{
	// SetTBTipText should only be called for TTN_NEEDTEXT notifications!
	ASSERT(pNMHDR->code == TTN_NEEDTEXTA || pNMHDR->code == TTN_NEEDTEXTW);

	TOOLTIPTEXTA* pTTTA = (TOOLTIPTEXTA*)pNMHDR; // ASCII message
	TOOLTIPTEXTW* pTTTW = (TOOLTIPTEXTW*)pNMHDR; // UNICODE message
	CString strTipText; // used to hold final tool tip text before UNICODE conversion

	UINT nID = pNMHDR->idFrom;

	if( pNMHDR->code == TTN_NEEDTEXTA && (pTTTA->uFlags & TTF_IDISHWND) ||
		pNMHDR->code == TTN_NEEDTEXTW && (pTTTW->uFlags & TTF_IDISHWND) )
	{		
		nID = ((UINT)(WORD)::GetDlgCtrlID((HWND)nID)); // idFrom is actually the HWND of the tool
	}

	SetToolbarTipText( nID, strTipText );

#ifdef _MBCS //define NON UNICODE
	if( pNMHDR->code == TTN_NEEDTEXTA )
		lstrcpyn( pTTTA->szText, strTipText, _countof(pTTTA->szText) );
	else
		_mbstowcsz( pTTTW->szText, strTipText, _countof(pTTTW->szText) );
#endif

#ifdef _UNICODE// define UNICODE
	if (pNMHDR->code == TTN_NEEDTEXTA)
		_wcstombsz(pTTTA->szText, (unsigned short*)(LPCTSTR)strTipText, _countof(pTTTA->szText));
	else
		lstrcpyn( (TCHAR*)pTTTW->szText, strTipText, _countof(pTTTW->szText));
#endif // end of define UNICODE

	*pResult = 0;

	// bring the tooltip window above other popup windows
	::SetWindowPos( pNMHDR->hwndFrom, HWND_TOP, 0,0,0,0, SWP_NOACTIVATE|SWP_NOSIZE|SWP_NOMOVE );

	return( 1 );    // message was handled
}//end of CMainFrame::OnDynamicTipText

/////////////////////////////////////////////////////////////////////////////
// The order of the ID must be same as the order in CTL file.
// INPUT : UINT nID - control id
// INPUT : CString& strTip - address of CString object
VOID CMainFrame::SetToolbarTipText( UINT nID, CString& strTip )
{
	switch( nID )
	{
	case ID_FILE_NEW:
		strTip = m_ttData[0].szTT;
		break;
	case ID_FILE_OPEN:
		strTip = m_ttData[1].szTT;
		break;
	case ID_FILE_SAVE:
		strTip = m_ttData[2].szTT;
		break;
	case ID_EDIT_CUT:
		strTip = m_ttData[3].szTT;
		break;
	case ID_EDIT_COPY:
		strTip = m_ttData[4].szTT;
		break;
	case ID_EDIT_PASTE:
		strTip = m_ttData[5].szTT;
		break;
	case ID_FILE_PRINT:
		strTip = m_ttData[6].szTT;
		break;
	case ID_APP_ABOUT:
		strTip = m_ttData[7].szTT;
		break;
	case ID_FORMAT_LFT:
		strTip = m_ttData[8].szTT;
		break;
	case ID_FORMAT_CNT:
		strTip = m_ttData[9].szTT;
		break;
	case ID_FORMAT_RIT:
		strTip = m_ttData[10].szTT;
		break;
	case ID_FORMAT_JUT:
		strTip = m_ttData[11].szTT;
		break;
	case ID_FORMAT_TOP:
		strTip = m_ttData[12].szTT;
		break;
	case ID_FORMAT_MID:
		strTip = m_ttData[13].szTT;
		break;
	case ID_FORMAT_BOT:
		strTip = m_ttData[14].szTT;
		break;
	case ID_FORMAT_PTR:
		strTip = m_ttData[15].szTT;
		break;
	case ID_FORMAT_PAL:
		strTip = m_ttData[16].szTT;
		break;
	case ID_FORMAT_GRD:
		strTip = m_ttData[17].szTT;
		break;
	case ID_TXTGFX_TEXT:
		strTip = m_ttData[18].szTT;
		break;
	case ID_TXTGFX_LINE:
		strTip = m_ttData[19].szTT;
		break;
	case ID_TXTGFX_BOX:
		strTip = m_ttData[20].szTT;
		break;
	case ID_TXTGFX_OVAL:
		strTip = m_ttData[21].szTT;
		break;
	case ID_TXTGFX_FILL:
		strTip = m_ttData[22].szTT;
		break;
	case ID_TXTGFX_IMPORT:
		strTip = m_ttData[23].szTT;
		break;
	case ID_TXTGFX_MAG:
		strTip = m_ttData[24].szTT;
		break;
	case ID_TXTGFX_MAG_PLUS:
		strTip = m_ttData[25].szTT;
		break;
	case ID_TXTGFX_MAG_MINUS:
		strTip = m_ttData[26].szTT;
		break;
	case ID_TXTGFX_CURV:
		strTip = m_ttData[27].szTT;
		break;
	case ID_TXTGFX_POLYGON:
		strTip = m_ttData[28].szTT;
		break;
	}//end of switch
}//end of CMainFrame::SetToolbarTipText
//////////////////////////////////////////////////////////////////////////////////////
// Resize the child window as the main window sizing
void CMainFrame::OnSize(UINT nType, int cx, int cy) 
{
	CMDIFrameWnd::OnSize(nType, cx, cy);
	TRACE3("MainFrm.cpp : OnSize - nType = %d, cx = %d, cy = %d\n", nType, cx, cy );

	CRect rcClient;
	::GetClientRect( m_hWndMDIClient, rcClient );
	MDIGetActive()->SetWindowPos( NULL, 0, 0, rcClient.Width(), rcClient.Height(), 
									SWP_NOMOVE | SWP_SHOWWINDOW | SWP_NOZORDER );
	OnResizeLeftBar( 0, 0 );
	OnResizeTopBin( 0, 0 );

	CRect	rc;	// +++++ center the bottom bar
	GetWindowRect( &rc );

	m_dlgBarBot.GetClientRect( rcClient );
	m_dlgBarBot.SetWindowPos( &wndTop, rc.Width()/2-rcClient.Width()/2, 0, 0, 0, SWP_NOSIZE );

}//end of CMainFrame::OnSize
//////////////////////////////////////////////////////////////////////////////////////////
// Custom message map function for resizing the left handside dialog bar when the application
// is resizing. All controls inside the dialog bar need to resize.
LRESULT CMainFrame::OnResizeLeftBar(WPARAM wParam, LPARAM lParam)
{
	const int dCXBox  = 8;	 // delta adjustment
	const int dCYBox  = 118; 
	const int dCYPage = 30;	

	CRect rcClient;
	::GetClientRect( m_hWndMDIClient, rcClient );

	CRect	rcBar;
	m_dlgBarLeft.GetClientRect( rcBar );
	m_dlgBarLeft.SetWindowPos( NULL, 0, 0, rcBar.Width(), rcClient.Height() + 3, 
								SWP_NOMOVE | SWP_SHOWWINDOW | SWP_NOZORDER );

	CRect	rcTab;
	CTabCtrl* pTab = (CTabCtrl*)m_dlgBarLeft.GetDlgItem(IDC_TAB_LEFT);
	if( pTab == NULL )
		return( (LRESULT)1 ); // error
	pTab->GetClientRect( rcTab );
	pTab->SetWindowPos( NULL, 0, 0, rcBar.Width(), rcClient.Height(),
						SWP_NOMOVE | SWP_SHOWWINDOW | SWP_NOZORDER );

	// ++++ Resize control in page dialog
	if( m_dlgBarLeft.m_pDlgPage == NULL )
		return( (LRESULT)1 ); // error
	m_dlgBarLeft.m_pDlgPage->ReSizeControl( rcClient );

	// ++++ Resize control in layer dialog
	if( m_dlgBarLeft.m_pDlgLayer == NULL )
		return( (LRESULT)1 ); // error
	m_dlgBarLeft.m_pDlgLayer->ReSizeControl( rcClient );

	return( (LRESULT)0 );
}//end of OnResizeLeftBar
//////////////////////////////////////////////////////////////////////////////////////////
// Custom message map function - Resize all controls inside the Top Bin dialog
LRESULT CMainFrame::OnResizeTopBin(WPARAM wParam, LPARAM lParam)
{
	const int dCXBox  = 11;	// delta adjustment
	const int dCXBar  = 10;
	const int dCYBox  = 25;
	const int dCYBar  = 5;

	CRect rcClient;
	::GetClientRect( m_hWndMDIClient, rcClient );
	
	CRect	rcBar;
	m_dlgBarBinTop.GetClientRect( rcBar );
	m_dlgBarBinTop.SetWindowPos( NULL, 0, 0, 
								 rcBar.Width(), rcClient.Height() + 4, 
								 SWP_NOMOVE | SWP_SHOWWINDOW | SWP_NOZORDER );
	
	CRect rcTopVSBar; // +++++ resize top bin
	CScrollBar* pVSBar = (CScrollBar*)m_dlgBarBinTop.GetDlgItem(IDC_VSB_TOPBIN);
	if( pVSBar == NULL )
		return( (LRESULT)1 ); // error
	pVSBar->GetClientRect( rcTopVSBar );
	pVSBar->SetWindowPos( NULL, 0, 0, 
							rcTopVSBar.Width(), rcClient.Height()/2 - dCYBox,
							SWP_NOMOVE | SWP_SHOWWINDOW | SWP_NOZORDER );

	CRect rcStcBox; // ++++++ resize top bin scroll bar
	CStatic* pStcBox = (CStatic*)m_dlgBarBinTop.GetDlgItem(IDC_LIST_TOP_BIN);
	if( pStcBox == NULL )
		return( (LRESULT)1 ); // error
	pStcBox->GetClientRect( rcStcBox );
	pStcBox->SetWindowPos( NULL, 0, 0, 
							rcBar.Width() - rcTopVSBar.Width() - dCXBox, rcClient.Height()/2 - dCYBox,
							SWP_NOMOVE | SWP_SHOWWINDOW | SWP_NOZORDER );

	// ++++++++ resize bottom bin
	pStcBox = (CStatic*)m_dlgBarBinTop.GetDlgItem(IDC_LIST_BOT_BIN);
	if( pStcBox == NULL )
		return( (LRESULT)1 ); // error
	pStcBox->GetClientRect( rcStcBox );
	pStcBox->SetWindowPos( NULL, rcStcBox.left + dCYBar, rcClient.Height()/2 + dCYBox, 
							rcBar.Width() - rcTopVSBar.Width() - dCXBar, rcClient.Height()/2 - dCYBox,
							SWP_SHOWWINDOW | SWP_NOZORDER );

	CRect rcVSBar; // ++++++ resize bottom bin scroll bar
	pVSBar = (CScrollBar*)m_dlgBarBinTop.GetDlgItem(IDC_VSB_BOTBIN);
	if( pVSBar == NULL )
		return( (LRESULT)1 ); // error
	pVSBar->GetClientRect( rcVSBar );
	pVSBar->SetWindowPos( NULL, rcStcBox.right + dCXBox, rcClient.Height()/2 + dCYBox, 
							rcVSBar.Width(), rcClient.Height()/2 - dCYBox,
							SWP_SHOWWINDOW | SWP_NOZORDER );
/***** save save 0616
	// ++++ move the show color button
	CButton* pBut = (CButton*)m_dlgBarBinTop.GetDlgItem(IDC_SHOW_COLOR);
	if( pBut == NULL )
		return( (LRESULT)1 );
	pBut->SetWindowPos( NULL, rcStcBox.left + dCYBar, rcClient.Height()/2 + dCYBar,
						0, 0, SWP_NOSIZE | SWP_SHOWWINDOW | SWP_NOZORDER );

	CRect rcBut;// ++++ move the show texture button
	pBut = (CButton*)m_dlgBarBinTop.GetDlgItem(IDC_SHOW_TEXTURE);
	if( pBut == NULL )
		return( (LRESULT)1 );
	pBut->GetClientRect( rcBut );
	pBut->SetWindowPos( NULL, rcStcBox.left + dCXBar + rcBut.Width(), rcClient.Height()/2 + dCYBar,
						0, 0, SWP_NOSIZE | SWP_SHOWWINDOW | SWP_NOZORDER );
***** save save 0616 ****/
	return( (LRESULT)0 );
}//end of CMainFrame::OnResizeTopBin
//////////////////////////////////////////////////////////////////////////////////////////
// Custom message map function - Resize all controls inside the Top Bin dialog
LRESULT CMainFrame::OnTWXferDone(WPARAM wParam, LPARAM lParam)
{
	// Get rid of old image first, because this App only deals with one
	CleanUpApp();

	// get private message, hbm in wParam, from DCA_ACQ.C convert from
	// DCA_ACQ.C returns a DIB, so change to DDB for sample App
	if( wParam != NULL )
	{
		_ghDIB = (HGLOBAL)wParam;	// image in memory
		
		if( !SaveScanedImage( _ghDIB ) )
			return((LRESULT)1 );

		// Set timer to call LoadPictureDlg() - Cannot call LoadPictureDlg()
		// directly here in debug mode (release mode OK) because of the fail of 
		// Assert() of window handle
		m_LdPicTimer = SetTimer( LD_PIC_TIMER, 1500, 0 );
	}//end of if - wParam

	return( (LRESULT)0 );
}//end of OnTWXferDone
//////////////////////////////////////////////////////////////////////////////////////////
void CMainFrame::OnAddObjPolygon() 
{	
	CGS_SetValDbl( EDIT_SET_OBJECT_SUBTYPE_MODE, (double)POLYGON_OBJ_SUBTYPE );

	CleanAttribDlgs();

	CDialog* pAttribDlg = m_dlgBarBot.GetAttribDlgPtr();	
	CTabCtrl* ptTab = (CTabCtrl*)pAttribDlg->GetDlgItem(IDC_TAB_ATTRIB);
	CRect rcTab;
	ptTab->GetWindowRect( rcTab );

	// Push state with highligth effect
	m_wndTxtGfxBar.GetToolBarCtrl().CheckButton( g_txtGfxState, 0 );
	g_txtGfxState = ID_TXTGFX_POLYGON; // set the tab state and button state
	m_wndTxtGfxBar.GetToolBarCtrl().CheckButton( g_txtGfxState, 1 );

	m_pDlgPoly = new CAttribPolygon;
	m_pDlgPoly->Create( IDD_ATTRIB_POLYGON, pAttribDlg );
	m_pDlgPoly->SetWindowPos( NULL, rcTab.Width() + ATTRIB_BOX_X, 0, 0, 0,SWP_SHOWWINDOW | SWP_NOSIZE);
	
	AfxGetMainWnd()->SetFocus();
}//end of CMainFrame::OnAddObjPolygon() 
//////////////////////////////////////////////////////////////////////////////////////////
void CMainFrame::OnAddObjCurve() 
{
	CGS_SetValDbl( EDIT_SET_OBJECT_SUBTYPE_MODE, (double)CURVE_OBJ_SUBTYPE );

	CleanAttribDlgs();

	CDialog* pAttribDlg = m_dlgBarBot.GetAttribDlgPtr();	
	CTabCtrl* ptTab = (CTabCtrl*)pAttribDlg->GetDlgItem(IDC_TAB_ATTRIB);
	CRect rcTab;
	ptTab->GetWindowRect( rcTab );

	// Push state with highligth effect
	m_wndTxtGfxBar.GetToolBarCtrl().CheckButton( g_txtGfxState, 0 );
	g_txtGfxState = ID_TXTGFX_CURV; // set the tab state and button state
	m_wndTxtGfxBar.GetToolBarCtrl().CheckButton( g_txtGfxState, 1 );

	m_pDlgCurv = new CAttribCurve;
	m_pDlgCurv->Create( IDD_ATTRIB_CURVE, pAttribDlg );
	m_pDlgCurv->SetWindowPos( NULL, rcTab.Width() + ATTRIB_BOX_X, 0, 0, 0,SWP_SHOWWINDOW | SWP_NOSIZE);
	
	AfxGetMainWnd()->SetFocus();
}//end of CMainFrame::OnAddObjCurve() 
//////////////////////////////////////////////////////////////////////////////////////////
void CMainFrame::OnAddObjBox() 
{
	CGS_SetValDbl( EDIT_SET_OBJECT_SUBTYPE_MODE, (double)BOX_OBJ_SUBTYPE );

	CleanAttribDlgs();

	CDialog* pAttribDlg = m_dlgBarBot.GetAttribDlgPtr();	
	CTabCtrl* ptTab = (CTabCtrl*)pAttribDlg->GetDlgItem(IDC_TAB_ATTRIB);
	CRect rcTab;
	ptTab->GetWindowRect( rcTab );

	// Push state with highligth effect
	m_wndTxtGfxBar.GetToolBarCtrl().CheckButton( g_txtGfxState, 0 );
	g_txtGfxState = ID_TXTGFX_BOX; // set the tab state and button state
	m_wndTxtGfxBar.GetToolBarCtrl().CheckButton( g_txtGfxState, 1 );
		
	m_pDlgBox = new CAttribBox;
	m_pDlgBox->Create( IDD_ATTRIB_BOX, pAttribDlg );
	m_pDlgBox->SetWindowPos( NULL, rcTab.Width() + ATTRIB_BOX_X, 0, 0, 0,SWP_SHOWWINDOW | SWP_NOSIZE);
	
	AfxGetMainWnd()->SetFocus();

	CGS_EditAddBox(FALSE);//FALSE = Rectangle JRS 01-03-27
}//end of CMainFrame::OnAddObjBox
//////////////////////////////////////////////////////////////////////////////////////////
void CMainFrame::OnAddObjFill() 
{
	CGS_SetValDbl( EDIT_SET_OBJECT_SUBTYPE_MODE, (double)FULL_SCREEN_BACKGROUND_OBJ_SUBTYPE );

	CleanAttribDlgs();

	CDialog* pAttribDlg = m_dlgBarBot.GetAttribDlgPtr();	
	CTabCtrl* ptTab = (CTabCtrl*)pAttribDlg->GetDlgItem(IDC_TAB_ATTRIB);
	CRect rcTab;
	ptTab->GetWindowRect( rcTab );

	// Push state with highligth effect
	m_wndTxtGfxBar.GetToolBarCtrl().CheckButton( g_txtGfxState, 0 );
	g_txtGfxState = ID_TXTGFX_FILL; // set the tab state and button state
	m_wndTxtGfxBar.GetToolBarCtrl().CheckButton( g_txtGfxState, 1 );
	
	m_pDlgFill = new CAttribFill;
	m_pDlgFill->Create( IDD_ATTRIB_FILL, pAttribDlg );
	m_pDlgFill->SetWindowPos( NULL, rcTab.Width() + ATTRIB_BOX_X, 0, 0, 0,SWP_SHOWWINDOW | SWP_NOSIZE);

	AfxGetMainWnd()->SetFocus();

	CGS_EditAddBox(TRUE);//TRUE=FULL SCREEN JRS 01-03-27
}//end of CMainFrame::OnAddObjFill
//////////////////////////////////////////////////////////////////////////////////////////
void CMainFrame::OnAddObjLine() 
{
	CGS_SetValDbl( EDIT_SET_OBJECT_SUBTYPE_MODE, (double)LINE_OBJ_SUBTYPE );

	CleanAttribDlgs();

	CDialog* pAttribDlg = m_dlgBarBot.GetAttribDlgPtr();	
	CTabCtrl* ptTab = (CTabCtrl*)pAttribDlg->GetDlgItem(IDC_TAB_ATTRIB);
	CRect rcTab;
	ptTab->GetWindowRect( rcTab );

	// Push state with highligth effect
	m_wndTxtGfxBar.GetToolBarCtrl().CheckButton( g_txtGfxState, 0 );
	g_txtGfxState = ID_TXTGFX_LINE; // set the tab state and button state
	m_wndTxtGfxBar.GetToolBarCtrl().CheckButton( g_txtGfxState, 1 );
	
	m_pDlgLine = new CAttribLine;
	m_pDlgLine->Create( IDD_ATTRIB_LINE, pAttribDlg );
	m_pDlgLine->SetWindowPos( NULL, rcTab.Width() + ATTRIB_BOX_X, 0, 0, 0,SWP_SHOWWINDOW | SWP_NOSIZE);

	AfxGetMainWnd()->SetFocus();	
}//end of CMainFrame::OnAddObjLine
//////////////////////////////////////////////////////////////////////////////////////////
void CMainFrame::OnAddObjOval() 
{
	CGS_SetValDbl( EDIT_SET_OBJECT_SUBTYPE_MODE, (double)ELLIPSE_OBJ_SUBTYPE );

	CleanAttribDlgs();

	CDialog* pAttribDlg = m_dlgBarBot.GetAttribDlgPtr();	
	CTabCtrl* ptTab = (CTabCtrl*)pAttribDlg->GetDlgItem(IDC_TAB_ATTRIB);
	CRect rcTab;
	ptTab->GetWindowRect( rcTab );

	// Push state with highligth effect
	m_wndTxtGfxBar.GetToolBarCtrl().CheckButton( g_txtGfxState, 0 );
	g_txtGfxState = ID_TXTGFX_OVAL; // set the tab state and button state
	m_wndTxtGfxBar.GetToolBarCtrl().CheckButton( g_txtGfxState, 1 );

	m_pDlgOval = new CAttribOval;
	m_pDlgOval->Create( IDD_ATTRIB_OVAL, pAttribDlg );
	m_pDlgOval->SetWindowPos( NULL, rcTab.Width() + ATTRIB_BOX_X, 0, 0, 0,SWP_SHOWWINDOW | SWP_NOSIZE);

	AfxGetMainWnd()->SetFocus();
}//end of CMainFrame::OnAddObjOval
//////////////////////////////////////////////////////////////////////////////////////////
// Select the toolbar button, activate the tab control, Set the button state
void CMainFrame::OnAddObjText() 
{	
	CGS_SetValDbl( EDIT_SET_OBJECT_SUBTYPE_MODE, (double)TEXT_OBJ_SUBTYPE );

	CleanAttribDlgs();

	CDialog* pAttribDlg = m_dlgBarBot.GetAttribDlgPtr();	
	CTabCtrl* ptTab = (CTabCtrl*)pAttribDlg->GetDlgItem(IDC_TAB_ATTRIB);
	CRect rcTab;
	ptTab->GetWindowRect( rcTab );
	
	// Push state with highligth effect
	m_wndTxtGfxBar.GetToolBarCtrl().CheckButton( g_txtGfxState, 0 );
	g_txtGfxState = ID_TXTGFX_TEXT; // set the tab state and button state
	m_wndTxtGfxBar.GetToolBarCtrl().CheckButton( g_txtGfxState, 1 );

	m_pDlgText = new CAttribText;
	m_pDlgText->Create( IDD_ATTRIB_TEXT, pAttribDlg );
	m_pDlgText->SetWindowPos( NULL, rcTab.Width() + ATTRIB_BOX_X, 0, 0, 0,SWP_SHOWWINDOW | SWP_NOSIZE);
		
	AfxGetMainWnd()->SetFocus();
}//end of CMainFrame::OnAddObjText

//////////////////////////////////////////////////////////////////////////////////////////
void CMainFrame::OnAddObjImport() 
{
	CGS_SetValDbl( EDIT_SET_OBJECT_SUBTYPE_MODE, (double)PICTURE_OBJ_SUBTYPE );

	FILE_REQ_FOLDER_INFO	imgFRD; // Get from core
	ZeroMemory( &imgFRD, sizeof(imgFRD) );

	imgFRD.nFileType = FILE_CATEGORY_PICTURE;
	CGS_GetFileCategoryPathInfo( &imgFRD );

	// Pop up the import picture dialog
	imgFRD.opt = OPEN_OP;
	_tcscpy( imgFRD.DlgTitle, _T("Open Picture") );
	if( !FileRequestDlg(&imgFRD, FILE_CATEGORY_PICTURE) )
		return;
	LoadPictureDlg();

	// After pop up the import picture dialog, 
	// change to the picture attribute
	CleanAttribDlgs();
	CDialog* pAttribDlg = m_dlgBarBot.GetAttribDlgPtr();	
	CTabCtrl* ptTab = (CTabCtrl*)pAttribDlg->GetDlgItem(IDC_TAB_ATTRIB);

	CRect rcTab;
	ptTab->GetWindowRect( rcTab );

	// Push state with highligth effect
	m_wndTxtGfxBar.GetToolBarCtrl().CheckButton( g_txtGfxState, 0 );
	g_txtGfxState = ID_TXTGFX_IMPORT; // set the tab state and button state
	m_wndTxtGfxBar.GetToolBarCtrl().CheckButton( g_txtGfxState, 1 );

	m_pDlgImport = new CAttribImport;
	m_pDlgImport->Create( IDD_ATTRIB_IMPORT, pAttribDlg );
	m_pDlgImport->SetWindowPos( NULL, rcTab.Width() + ATTRIB_BOX_X, 0, 0, 0,SWP_SHOWWINDOW | SWP_NOSIZE);

	AfxGetMainWnd()->SetFocus();
}//end of CMainFrame::OnAddObjImport

//////////////////////////////////////////////////////////////////////////////////////////
void CMainFrame::OnFormatPal() 
{	
	int nRet = -1;
	CPalDlg dlgPal;
	dlgPal.SetPaletteState( ID_FORMAT_PAL );
    // Create and show the dialog box  	
    nRet = dlgPal.DoModal();   
    switch ( nRet )	// Handle the return value from DoModal
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
    };//end of switch

}//end of CMainFrame::OnFormatPal
//////////////////////////////////////////////////////////////////////////////////////////
// Popup Picon selection dialog
void CMainFrame::OnFormatPtr() 
{
	// This function was deleted on 11-15-2000
}//end of CMainFrame::OnFormatPtr
////////////////////////////////////////////////////////////////////////////////////////////
void CMainFrame::OnFileNew() 
{
	TRACE0("\nMainFrm.cpp : OnFileNew\n" );
	int		rc;
	if( CGS_GetValDbl(EDIT_PROJECT_MODIFIED) ) // if current project has been modified
	{
		rc = ACGMessageBox( m_hWnd, _T("M0000"), _T("INFO"), MB_YESNOCANCEL | MB_ICONQUESTION );
		switch( rc )
		{
		case IDYES:
			if( CGS_GetValDbl(EDIT_PROJECT_NEEDS_FILENAME) )
				OnFileSaveAs();
			else
				OnFileSave();
			break;
		case IDNO:
			break;
		case IDCANCEL:
			return; // do nothing
			break;
		}//end of swtich - rc
	}//end of if - projec modified

	//added JRS 00-12-31
	CGS_NewProject();

}//end of CMainFrame::OnFileNew
//////////////////////////////////////////////////////////////////////////////////////////
void CMainFrame::OnFileOpen() 
{
	TRACE0( _T("\nMainFrm.cpp : OnFileOpen\n") );

	int		rc;
	if( CGS_GetValDbl(EDIT_PROJECT_MODIFIED) ) // if current project has been modified
	{
		rc = ACGMessageBox( m_hWnd, _T("M0000"), _T("INFO"), MB_YESNOCANCEL | MB_ICONQUESTION );
		switch( rc )
		{
		case IDYES:
			if( CGS_GetValDbl(EDIT_PROJECT_NEEDS_FILENAME) )
				OnFileSaveAs();
			else
				OnFileSave();
			break;
		case IDNO:
			break;
		case IDCANCEL:
			return; // do nothing
			break;
		}//end of swtich - rc
	}//end of if - projec modified

	FILE_REQ_FOLDER_INFO	projFRD;
	ZeroMemory( &projFRD, sizeof(FILE_REQ_FOLDER_INFO) );
//	projFRD.FileName = "untitle";
	projFRD.opt = OPEN_OP;
	_tcscpy( projFRD.DlgTitle, _T("Open Project") );
	if( !FileRequestDlg(&projFRD, FILE_CATEGORY_PROJECT) ) // open file fail
		return;

	TRACE0( _T("\nMainFrm.cpp : AddToRecentFileList\n") );
	AfxGetApp()->AddToRecentFileList( projFRD.CompleteFileName );

	char	szFileName[MAX_PATH];
	UnicodeToMultiByte( CP_ACP, projFRD.CompleteFileName, szFileName );
/*
	WideCharToMultiByte(CP_ACP,                  // code page
						0,		                 // dwFlags
						projFRD.CompleteFileName,// lpWideCharStr
						-1,                      // cchWideCharStr
						szFileName,				 // lpMultiByteStr
						sizeof(szFileName),		 // cchMultiByte
						NULL,                    // lpDefaultChar
						NULL					 // lpUsedDefaultChar
					);                  
*/
	CGS_LoadProject( szFileName );
}//end of CMainFrame::OnFileOpen
////////////////////////////////////////////////////////////////////////////////////////////////////////
VOID CMainFrame::CleanAttribDlgs()
{
	if( m_pDlgText != NULL )
	{
		m_pDlgText->DeleteAttribText();
		delete m_pDlgText;
		m_pDlgText = NULL;
	}
	if( m_pDlgLine != NULL )
	{
		m_pDlgLine->DeleteAttribLine();
		delete m_pDlgLine;
		m_pDlgLine = NULL;
	}
	if( m_pDlgCurv != NULL )
	{
		m_pDlgCurv->DeleteAttribCurve();
		delete m_pDlgCurv;
		m_pDlgCurv = NULL;
	}
	if( m_pDlgPoly != NULL )
	{
		m_pDlgPoly->DeleteAttribPoly();
		delete m_pDlgPoly;
		m_pDlgPoly = NULL;
	}
	if( m_pDlgBox != NULL )
	{
		m_pDlgBox->DeleteAttribBox();
		delete m_pDlgBox;
		m_pDlgBox = NULL;
	}
	if( m_pDlgFill != NULL )
	{
		m_pDlgFill->DeleteAttribFill();
		delete m_pDlgFill;
		m_pDlgFill = NULL;
	}
	if( m_pDlgOval != NULL )
	{
		m_pDlgOval->DeleteAttribOval();
		delete m_pDlgOval;
		m_pDlgOval = NULL;
	}
	if( m_pDlgImport != NULL )
	{
		m_pDlgImport->DeleteAttribImport();
		delete m_pDlgImport;
		m_pDlgImport = NULL;
	}
}//end of CMainFrame::CleanAttribDlgs()
//////////////////////////////////////////////////////////////////////////////////////////
// Launch the video setup dialog
void CMainFrame::OnVdoSetUp() 
{
	switch( m_vdoSetupType )
	{
	case TITLE_MACHINE:
		VdoSetupTitleMachine();
		break;
	case VIDEO_MACHINE:
		VdoSetupVideoMachine();
		break;
	}//end of switch
	

}//end of CMainFrame::OnVdoSetUp() 
//////////////////////////////////////////////////////////////////////////////////////////////////////
void CMainFrame::OnPgAddPic() 
{
	FILE_REQ_FOLDER_INFO	imgFRD;
	ZeroMemory( &imgFRD, sizeof( imgFRD ) );
	imgFRD.opt = OPEN_OP;
	_tcscpy( imgFRD.DlgTitle, _T("Open Picture") );
	if( !FileRequestDlg( &imgFRD, FILE_CATEGORY_PICTURE ) )
		return;

	LoadPictureDlg();
}//end of CMainFrame::OnPgAddPic
//////////////////////////////////////////////////////////////////////////////////////////////////////
void CMainFrame::OnPgClearAll() 
{
	CGS_Action( CGSA_CLEAR_ALL );
	
}//end of CMainFrame::OnPgClearAll
//////////////////////////////////////////////////////////////////////////////////////////////////////
void CMainFrame::OnPgClearText() 
{
	CGS_Action( CGSA_CLEAR_TEXT );
	
}//end of CMainFrame::OnPgClearText
//////////////////////////////////////////////////////////////////////////////////////////////////////
void CMainFrame::OnPageCenter() 
{
	CGS_Action( CGSA_PAGE_JUSTIFY_CENTER );
	
}//end of CMainFrame::OnPageCenter() 
//////////////////////////////////////////////////////////////////////////////////////////////////////
void CMainFrame::OnPageCopy() 
{
	CGS_Action( CGSA_COPY_PAGE );
	
}//end of CMainFrame::OnPageCopy() 
//////////////////////////////////////////////////////////////////////////////////////////////////////
void CMainFrame::OnPageCut() 
{
	CGS_Action( CGSA_CUT_PAGE );
	
}//end of CMainFrame::OnPageCut() 
//////////////////////////////////////////////////////////////////////////////////////////////////////
void CMainFrame::OnPageDuplicate() 
{
	CGS_Action( CGSA_DUPLICATE_PAGE );
	
}//end of CMainFrame::OnPageDuplicate() 
//////////////////////////////////////////////////////////////////////////////////////////////////////
void CMainFrame::OnPageFlush() 
{
	CGS_Action( CGSA_PAGE_JUSTIFY_FLUSH );
	
}//end of CMainFrame::OnPageFlush() 
//////////////////////////////////////////////////////////////////////////////////////////////////////
void CMainFrame::OnPageInNewAfter() 
{
	CGS_Action( CGSA_INSERT_PAGE_AFTER );
	
}//end of CMainFrame::OnPageInNewAfter() 
//////////////////////////////////////////////////////////////////////////////////////////////////////
void CMainFrame::OnPageInNewBefore() 
{
	CGS_Action( CGSA_INSERT_PAGE_BEFORE );
	
}//end of CMainFrame::OnPageInNewBefore() 
//////////////////////////////////////////////////////////////////////////////////////////////////////
void CMainFrame::OnPageLeft() 
{
	CGS_Action( CGSA_PAGE_JUSTIFY_LEFT );
	
}//end of CMainFrame::OnPageLeft() 
//////////////////////////////////////////////////////////////////////////////////////////////////////
void CMainFrame::OnPagePasteAfter() 
{
	CGS_Action( CGSA_PASTE_PAGE_AFTER );
	
}//end of CMainFrame::OnPagePasteAfter() 
//////////////////////////////////////////////////////////////////////////////////////////////////////
void CMainFrame::OnPagePasteBefore() 
{
	CGS_Action( CGSA_PASTE_PAGE_BEFORE );
	
}//end of CMainFrame::OnPagePasteBefore() 
//////////////////////////////////////////////////////////////////////////////////////////////////////
void CMainFrame::OnPageRight() 
{
	CGS_Action( CGSA_PAGE_JUSTIFY_RIGHT );
	
}//end of CMainFrame::OnPageRight() 
//////////////////////////////////////////////////////////////////////////////////////////////////////
// Check the state of the "Page" menu item. Check the menu item
// if it is currently unchecked. Otherwise, uncheck the menu item
// if it is not currently checked.
void CMainFrame::OnPgWordWrap() 
{
   CMenu* mmenu = GetMenu();
   CMenu* submenu = mmenu->GetSubMenu( 5 ); // Get Page position = 5
   
   UINT state = submenu->GetMenuState(ID_PG_WORD_WRAP, MF_BYCOMMAND);
   ASSERT( state != 0xFFFFFFFF );

   if( state & MF_CHECKED )
      submenu->CheckMenuItem( ID_PG_WORD_WRAP, MF_UNCHECKED | MF_BYCOMMAND );
   else
      submenu->CheckMenuItem( ID_PG_WORD_WRAP, MF_CHECKED | MF_BYCOMMAND );
	
}//end of CMainFrame::OnPgWordWrap
//////////////////////////////////////////////////////////////////////////////////////////////////////
void CMainFrame::OnPgClearGraphic() 
{
	CGS_Action( CGSA_CLEAR_GRAPHICS );
	
}//end of CMainFrame::OnPgClearGraphic
//////////////////////////////////////////////////////////////////////////////////////////////////////
// Popup load picture dialog
VOID CMainFrame::LoadPictureDlg()
{
	int nRet = -1;
	CAddPic dlgAddPic;
	
	// Create and show the dialog box
	nRet = dlgAddPic.DoModal();	
	switch ( nRet ) // Handle the return value from DoModal
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
	};//end of switch	
}//end of CMainFrame::LoadPictureDlg()
//////////////////////////////////////////////////////////////////////////////////////////////////////
void CMainFrame::OnPgSpellCheck() 
{
	// TODO: Add your command handler code here
	int nRet = -1;
	CSpellCheck dlgSpellCheck;
	
	// Create and show the dialog box
	nRet = dlgSpellCheck.DoModal();	
	switch ( nRet ) // Handle the return value from DoModal
	{
	case -1: 
		AfxMessageBox(_T("Dialog box could not be created!"));	  
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
	};//end of switch		
}//end of CMainFrame::OnPgSpellCheck
/////////////////////////////////////////////////////////////////////////////////////////////////////
// There is no control id for menu item. Therefore, searching the item string and replace the
// existing string to other language.
VOID CMainFrame::ChangeFileMenuText()
{
	INT		pos;
	UINT	id;
	DWORD	i, j;
	CMenu* pSubmenu;
	CMenu* pMenu = GetMenu();

	for( i = 0; i < m_nMenu; i++ )
	{
		pos = FindMenuItemPos( pMenu, (LPCTSTR)m_pMainMenu[i].szSearch );
		pMenu->ModifyMenu( pos, MF_BYPOSITION, pos, (LPCTSTR)m_pMainMenu[i].szDisplay );
			
		pSubmenu = pMenu->GetSubMenu(pos);
		for( j = 0; j < m_nSubm; j++ )
		{
			pos = FindMenuItemPos( pSubmenu, (LPCTSTR)m_pSubMenu[j].szSearch );
			if( -1 < pos )
			{
				id = pSubmenu->GetMenuItemID(pos);
				pSubmenu->ModifyMenu( id, MF_BYCOMMAND, id, (LPCTSTR)m_pSubMenu[j].szDisplay );
			}//end of if
		}//end of for - j
	}//end of for - i

   DrawMenuBar();
}//end of CMainFrame::ChangeFileMenuText()
//////////////////////////////////////////////////////////////////////////////////////////////
// INPUT   : CMenu* Menu - pointer to Menu object
// INPUT   : LPCTSTR szSearch - the search string
// RETUREN : INT - menu item position
INT CMainFrame::FindMenuItemPos(CMenu *Menu, LPCTSTR szSearch)
{
	ASSERT(Menu);
    ASSERT(::IsMenu(Menu->GetSafeHmenu()));

    int count = Menu->GetMenuItemCount();
    for( int i = 0; i < count; i++ )
    {
       CString str;
       if( Menu->GetMenuString(i, str, MF_BYPOSITION) && (NULL != _tcsstr(szSearch,str)) )          
         return i;
	}

   return -1;
}//end of CMainFrame::FindMenuItemPos
//////////////////////////////////////////////////////////////////////////////////////////////
// User defined command map function - NOT message map
void CMainFrame::OnLoadNewMenu() 
{
	TRACE0("MainFrm.cpp : CMainFrame::OnLoadNewMenu()\n");
	ChangeFileMenuText();

}//end of CMainFrame::OnLoadNewMenu
///////////////////////////////////////////////////////////////////////////////////////
// Add file name to popup menu
// INPUT : DWORD startID - starting ID of MRU file
// INPUT : UINT posMenu - popup menu item position
VOID CMainFrame::AddFileNameToMenu(DWORD startID, CString szList, UINT posMenu)
{
/*** commment out 10-13-00
	CRecentFileList	fileList(startID, szList, _T("File%d"), MAX_FILE, AFX_ABBREV_FILENAME_LEN );
	fileList.ReadList();

	CString strName;
	CString szTest;
	INT		nIndex = 0;
	INT		nList  = fileList.GetSize();
	INT		nFile  = 0;
	INT		nProj  = 0;

	for( nIndex = 0; nIndex < nList; nIndex++ ) // add the most recent file list and project list
	{
		if( !fileList.GetDisplayName( strName, nIndex, (const TCHAR*)g_szAppPath, sizeof(g_szAppPath), TRUE) )
			break;

	}//end of for
**** comment out 10-13-00 ****/
}//end of CMainFrame::AddFileNameToMenu
////////////////////////////////////////////////////////////////////////////////////////////////
// Read the menu text from external text file which contains two section: one for menu item
// the other for Submenu item (popup menu)
VOID CMainFrame::LoadMenuText()
{
	IN_TEXT_DATA* txtMenu = NULL;
	IN_TEXT_DATA* txtSubm = NULL;

	_TCHAR	sep[] = _T("\"");
	_TCHAR*	ptID;
	_TCHAR*	ptTT;
	_TCHAR*	ptEnd;

	// get number of menu item
	m_nMenu = LoadTextFromCtl( "\\Util\\Menu.ctl", "[Menu]",    &txtMenu );
	if( m_nMenu == 0 )
		return;

	// get number of submenu item
	m_nSubm = LoadTextFromCtl( "\\Util\\Menu.ctl", "[SubMenu]", &txtSubm );
	if( m_nSubm == 0 )
		return;

	m_pMainMenu = new MENU_DATA[m_nMenu];
	m_pSubMenu  = new MENU_DATA[m_nSubm];

	int j = 0;
	DWORD i = 0;
	for( i = 0; i < m_nMenu; i++ )
	{
		ptID   = _tcstok( txtMenu[i].szTT, sep );		
		ptTT   = _tcstok( NULL, sep );
		ptEnd  = _tcstok( NULL, sep );
		if( ptEnd != 0 )
			*ptEnd = '\0';
			
		_tcscpy( m_pMainMenu[i].szSearch,  ptID );
		_tcscpy( m_pMainMenu[i].szDisplay, ptTT );
	}//end of for

	for( i = 0; i < m_nSubm; i++ )
	{
		ptID   = _tcstok( txtSubm[i].szTT, sep );
		
		ptTT   = _tcstok( NULL, sep );
		ptEnd  = _tcstok( NULL, sep );
		if( ptEnd != 0 )
			*ptEnd = '\0';

		_tcscpy( m_pSubMenu[i].szSearch,  ptID );
		_tcscpy( m_pSubMenu[i].szDisplay, ptTT );
	}//end of for

	free( txtMenu );
	free( txtSubm );

}//end of CMainFrame::LoadMenuText()
////////////////////////////////////////////////////////////////////////////////////////////////
void CMainFrame::OnFileSaveAs() 
{
	TRACE0("\nMainFrm.cpp : OnFileSaveAs\n" );
	FILE_REQ_FOLDER_INFO	projFRD;
	ZeroMemory( &projFRD, sizeof(projFRD) );
	projFRD.opt = SAVE_OP;
	_tcscpy( projFRD.DlgTitle, _T("Save Project As") );
	if( !FileRequestDlg( &projFRD, FILE_CATEGORY_PROJECT ) )
		return;

	CString	fn( projFRD.FolderPath );
	fn = fn + "\\" + projFRD.FileName;

	char	szFileName[MAX_PATH];

#ifdef _UNICODE
	WideCharToMultiByte(CP_ACP,                 // code page
						0,		                // dwFlags
						fn,						// lpWideCharStr
						-1,                     // cchWideCharStr
						szFileName,				// lpMultiByteStr
						sizeof(szFileName),		// cchMultiByte
						NULL,                   // lpDefaultChar
						NULL					// lpUsedDefaultChar
					);        
#else
	strcpy( szFileName, (char*)(LPCTSTR)fn );
#endif

	CGS_SaveProjectAs( projFRD.CompleteFileName );
	AfxGetApp()->AddToRecentFileList( projFRD.CompleteFileName );

}//end of CMainFrame::OnFileSaveAs
////////////////////////////////////////////////////////////////////////////////////////////////
void CMainFrame::OnFileSave() 
{
	TRACE0("\nMainFrm.cpp : OnFileSave\n" );
	if( CGS_GetValDbl(EDIT_PROJECT_NEEDS_FILENAME) )
		OnFileSaveAs();
	else
		CGS_SaveProject();

}//end of CMainFrame::OnFileSave
////////////////////////////////////////////////////////////////////////////////////////////////
void CMainFrame::OnRefreshAttPoly() 
{
//	OnTxtgfxPolygon();
	m_pDlgPoly->DoValueUpdate();	
}//end of CMainFrame::OnRefreshAttPoly() 
/////////////////////////////////////////////////////////////////////////////////////////////
void CMainFrame::OnRefreshAttPic() 
{
//	OnTxtgfxImport();
	m_pDlgImport->DoValueUpdate();	
}//end of CMainFrame::OnRefreshAttPic()
////////////////////////////////////////////////////////////////////////////////////////////////
// Command interface for updating attribute box info
void CMainFrame::OnRefreshAttBox() 
{
//	OnTxtgfxBox();
	m_pDlgBox->DoValueUpdate();
	
}//end of CMainFrame::OnRefreshAttBox
////////////////////////////////////////////////////////////////////////////////////////////////
void CMainFrame::OnRefreshAttCurve() 
{
//	OnTxtgfxCurv();
	m_pDlgCurv->DoValueUpdate();
	
}//end of CMainFrame::OnRefreshAttCurve() 
////////////////////////////////////////////////////////////////////////////////////////////////
void CMainFrame::OnRefreshAttCapture() 
{
	m_dlgBarBot.GetCaptureDlgPtr()->DoValueUpdate();
	
}//end of CMainFrame::OnRefreshAttCapture
////////////////////////////////////////////////////////////////////////////////////////////////
void CMainFrame::OnUncheckAlpha() 
{
	
}//end of CMainFrame::OnUncheckAlpha() 
////////////////////////////////////////////////////////////////////////////////////////////////
void CMainFrame::OnRefreshAttFace() 
{
	m_dlgBarBot.GetAttribDlgPtr()->GetFaceDlgPtr()->DoValueUpdate();	
	m_dlgBarBot.GetAttribDlgPtr()->GetFaceDlgPtr()->UnCheckAlphaButton();
}//end of CMainFrame::OnRefreshAttFace
////////////////////////////////////////////////////////////////////////////////////////////////
void CMainFrame::OnRefreshAttOutline1() 
{
	m_dlgBarBot.GetAttribDlgPtr()->GetOutline1DlgPtr()->DoValueUpdate();
	m_dlgBarBot.GetAttribDlgPtr()->GetOutline1DlgPtr()->UnCheckAlphaButton();
}//end of CMainFrame::OnRefreshAttOutline1
////////////////////////////////////////////////////////////////////////////////////////////////
void CMainFrame::OnRefreshAttOutline2() 
{
	m_dlgBarBot.GetAttribDlgPtr()->GetOutline2DlgPtr()->DoValueUpdate();
	m_dlgBarBot.GetAttribDlgPtr()->GetOutline2DlgPtr()->UnCheckAlphaButton();
}//end of CMainFrame::OnRefreshAttOutline2
////////////////////////////////////////////////////////////////////////////////////////////////
void CMainFrame::OnRefreshAttShadow() 
{
	m_dlgBarBot.GetAttribDlgPtr()->GetShadowDlgPtr()->DoValueUpdate();
	m_dlgBarBot.GetAttribDlgPtr()->GetShadowDlgPtr()->UnCheckAlphaButton();
}//end of CMainFrame::OnRefreshAttShadow
////////////////////////////////////////////////////////////////////////////////////////////////
void CMainFrame::OnRefreshAttCast() 
{
	m_dlgBarBot.GetAttribDlgPtr()->GetCastDlgPtr()->DoValueUpdate();
	m_dlgBarBot.GetAttribDlgPtr()->GetCastDlgPtr()->UnCheckAlphaButton();
}//end of CMainFrame::OnRefreshAttCast
////////////////////////////////////////////////////////////////////////////////////////////////
void CMainFrame::OnRefreshAttLine() 
{
//	OnTxtgfxLine();
	m_pDlgLine->DoValueUpdate();
}//end of CMainFrame::OnRefreshAttLine
////////////////////////////////////////////////////////////////////////////////////////////////
void CMainFrame::OnRefreshAttOval() 
{
//	OnTxtgfxOval();
	m_pDlgOval->DoValueUpdate();
}//end of CMainFrame::OnRefreshAttOval
////////////////////////////////////////////////////////////////////////////////////////////////
void CMainFrame::OnRefreshAttText() 
{
//	OnTxtgfxText();
	m_pDlgText->DoValueUpdate();
}//end of CMainFrame::OnRefreshAttText
////////////////////////////////////////////////////////////////////////////////////////////////
void CMainFrame::OnRefreshEffect() 
{
	m_dlgBarBot.GetEffectDlgPtr()->DoValueUpdate();
	
}//end of CMainFrame::OnRefreshEffect
////////////////////////////////////////////////////////////////////////////////////////////////
void CMainFrame::OnRefreshBaseline() 
{
	m_dlgBarBot.GetBaselinePtr()->DoValueUpdate();
	
}//end of CMainFrame::OnRefreshBaseline() 
////////////////////////////////////////////////////////////////////////////////////////////////
void CMainFrame::OnRefreshPage() 
{
//	CRect rcStcBox;
//	CStatic* pStcBox = (CStatic*)m_dlgBarLeft.m_pDlgPage->GetDlgItem(IDC_LIST_BOX);
//	if( pStcBox == NULL )
//		return( (LRESULT)1 ); // error

	m_dlgBarLeft.m_pDlgPage->DoValueUpdate();	

}//end of CMainFrame::OnRefreshPage
////////////////////////////////////////////////////////////////////////////////////////////////
void CMainFrame::OnRefreshAttFill() 
{
//	OnTxtgfxFill();
	m_pDlgFill->DoValueUpdate();
	
}//end of CMainFrame::OnRefreshAttFill
////////////////////////////////////////////////////////////////////////////////////////////////
void CMainFrame::OnCommReceiver() 
{
#if	_COMM
	CreateCommReciverDlg(AfxGetApp()->m_hInstance, AfxGetMainWnd()->m_hWnd);
#endif
	
}//end of CMainFrame::OnCommReceiver
////////////////////////////////////////////////////////////////////////////////////////////////
void CMainFrame::OnCommSender() 
{
#if	_COMM
	CreateCommSenderDlg(AfxGetApp()->m_hInstance, AfxGetMainWnd()->m_hWnd);
#endif	
}//end of CMainFrame::OnCommSender
////////////////////////////////////////////////////////////////////////////////////////////////
void CMainFrame::OnDownload() 
{
#if	_COMM
	CreateCommDownloadDlg(AfxGetApp()->m_hInstance, AfxGetMainWnd()->m_hWnd);
#endif	
}//end of CMainFrame::OnDownload
////////////////////////////////////////////////////////////////////////////////////////////////
void CMainFrame::OnHostFinder() 
{
#if	_COMM
	CreateCommFinderDlg(AfxGetApp()->m_hInstance, AfxGetMainWnd()->m_hWnd);
#endif
}//end of CMainFrame::OnHostFinder
////////////////////////////////////////////////////////////////////////////////////////////////
void CMainFrame::OnModem() 
{
#if	_COMM
	CreateCommModemDlg(AfxGetApp()->m_hInstance, AfxGetMainWnd()->m_hWnd);
#endif	
}//end of CMainFrame::OnModem()
////////////////////////////////////////////////////////////////////////////////////////////////
VOID CMainFrame::VdoSetupTitleMachine()
{
	CTitleVdoSetup dlgVdoSetup;
	
	int nRet = -1;
	nRet = dlgVdoSetup.DoModal(); // Create and show the dialog box
	// Handle the return value from DoModal
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
	};//end of switch	
}//end of CMainFrame::VdoSetupTitleMachine()
////////////////////////////////////////////////////////////////////////////////////////////////////
VOID CMainFrame::VdoSetupVideoMachine()
{
	CVMVdoSetup dlgVdoSetup;
	
	int nRet = -1;
	nRet = dlgVdoSetup.DoModal(); // Create and show the dialog box
	// Handle the return value from DoModal
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
	};//end of switch	

}//end of CMainFrame::VdoSetupVideoMachine()
////////////////////////////////////////////////////////////////////////////////////////
void CMainFrame::OnFileMruFile1() 
{
	// TODO: Add your command handler code here
	TRACE0("CMainFrame::OnFileMruFile1()\n");
}//end of CMainFrame::OnFileMruFile1
////////////////////////////////////////////////////////////////////////////////////////
void CMainFrame::OnUpdateFileMruFile1(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	TRACE0("MainFrm.cpp - CMainFrame::OnUpdateFileMruFile1()\n");
}//end of CMainFrame::OnUpdateFileMruFile1
////////////////////////////////////////////////////////////////////////////////////////
void CMainFrame::OnFileMruProj1() 
{
	// TODO: Add your command handler code here
	TRACE0("MainFrm.cpp - CMainFrame::OnFileMruProj1()\n");
}//end of CMainFrame::OnFileMruProj1
////////////////////////////////////////////////////////////////////////////////////////
void CMainFrame::OnUpdateFileMruProj1(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	TRACE0("MainFrm.cpp - CMainFrame::OnUpdateFileMruProj1()\n");
}//end of CMainFrame::OnUpdateFileMruProj1
////////////////////////////////////////////////////////////////////////////////////////
void CMainFrame::OnFileTabSetup() 
{
	TRACE0("MainFrm.cpp - CMainFrame::OnFileTabSetup()\n");

	m_dlgTabSetup.Create( IDD_TAB_SETUP );

}//end of CMainFrame::OnFileTabSetup
////////////////////////////////////////////////////////////////////////////////////////
void CMainFrame::OnClose() 
{
	TRACE0("MainFrm.cpp - CMainFrame::OnClose()\n");
	int		rc;
	if( CGS_GetValDbl(EDIT_PROJECT_MODIFIED) ) // if current project has been modified
	{
		rc = ACGMessageBox( m_hWnd, _T("M0000"), _T("INFO"), MB_YESNOCANCEL | MB_ICONQUESTION );
		switch( rc )
		{
		case IDYES:
			if( CGS_GetValDbl(EDIT_PROJECT_NEEDS_FILENAME) )
				OnFileSaveAs();
			else
				OnFileSave();
			break;
		case IDNO:
			break;
		case IDCANCEL:
			return; // do nothing
			break;
		}//end of swtich - rc
	}//end of if - projec modified

	CMDIFrameWnd::OnClose();
}//end of CMainFrame::OnClose
////////////////////////////////////////////////////////////////////////////////////////
void CMainFrame::OnFilePreference() 
{
	CDlgPrefer dlg;
	
	int nRet = -1;
	nRet = dlg.DoModal(); // Create and show the dialog box
	
	switch( nRet ) // Handle the return value from DoModal
	{
	case -1: 
		AfxMessageBox(_T("Dialog box could not be created!"));	  
		break;
	case IDABORT:
		  // Do something		  
		break;
	case IDOK:
		{
/******  save for reference - on Unicode to Multi Byte
			char szProjPath[MAX_PATH];
			char szGafxPath[MAX_PATH];
			char szExptPath[MAX_PATH];

			UnicodeToMultiByte( CP_ACP, (TCHAR*)(LPCTSTR)dlg.m_strProjPath, szProjPath );
			UnicodeToMultiByte( CP_ACP, (TCHAR*)(LPCTSTR)dlg.m_strGafxPath, szGafxPath );
			UnicodeToMultiByte( CP_ACP, (TCHAR*)(LPCTSTR)dlg.m_strExptPath, szExptPath );

			WideCharToMultiByte( CP_ACP, 0, dlg.m_strProjPath, -1, szProjPath, sizeof(szProjPath), NULL, NULL	);
			WideCharToMultiByte( CP_ACP, 0, dlg.m_strGafxPath, -1, szGafxPath, sizeof(szGafxPath), NULL, NULL	);
			WideCharToMultiByte( CP_ACP, 0, dlg.m_strExptPath, -1, szExptPath, sizeof(szExptPath), NULL, NULL	);
*******  save for reference - on Unicode to Multi Byte */
		}
		  // Do something		  
		break;
	case IDCANCEL:
		  // Do something		  
		break;
	default:
		  // Do something		  
		break;
	};//end of switch		
}//end of CMainFrame::OnFilePreference

void CMainFrame::OnFilePrint() 
{
	// TODO: Add your command handler code here
	
}
////////////////////////////////////////////////////////////////////////////////////////////////////
void CMainFrame::OnFileImportText() 
{
	TRACE0("\nMainFrm.cpp : OnFileImportText\n" );

	int		rc;
	if( CGS_GetValDbl(EDIT_PROJECT_MODIFIED) ) // if current project has been modified
	{
		rc = ACGMessageBox( m_hWnd, _T("M0000"), _T("INFO"), MB_YESNOCANCEL | MB_ICONQUESTION );
		switch( rc )
		{
		case IDYES:
			if( CGS_GetValDbl(EDIT_PROJECT_NEEDS_FILENAME) )
				OnFileSaveAs();
			else
				OnFileSave();
			break;
		case IDNO:
			break;
		case IDCANCEL:
			return; // do nothing
			break;
		}//end of swtich - rc
	}//end of if - projec modified

	FILE_REQ_FOLDER_INFO	textFRD;
	ZeroMemory( &textFRD, sizeof(textFRD) );
	textFRD.opt = OPEN_OP;
	textFRD.nFileType = FILE_CATEGORY_TEXT;
	CGS_GetFileCategoryPathInfo( &textFRD );

	_tcscpy( textFRD.DlgTitle, _T("Open Text") );
	if( !FileRequestDlg( &textFRD, FILE_CATEGORY_TEXT ) ) // open file fail
		return;

	TRACE0("\nMainFrm.cpp : AddToRecentFileList\n" );
	AfxGetApp()->AddToRecentFileList( textFRD.CompleteFileName );

	char	szFileName[MAX_PATH];
	UnicodeToMultiByte( CP_ACP, textFRD.CompleteFileName, szFileName );

	CGS_ImportTextFileAtCursor( szFileName );

}//end of CMainFrame::OnFileImportText
///////////////////////////////////////////////////////////////////////////////////////////////
void CMainFrame::OnClipCopy() 
{
	TRACE0("\nMainFrm.cpp : OnClipCopy\n" );
	CGS_Action( CGSA_COPY_TEXT_TO_CLIPBOARD );
}//end of OnClipCopy
///////////////////////////////////////////////////////////////////////////////////////////////
void CMainFrame::OnClipPaste() 
{
	TRACE0("\nMainFrm.cpp : OnClipPaste\n" );
	CGS_Action( CGSA_PASTE_TEXT_FROM_CLIPBOARD );
}//end of OnClipPaste
///////////////////////////////////////////////////////////////////////////////////////////////
void CMainFrame::OnFileSelectScanner() 
{
	TRACE0("\nMainFrm.cpp : OnFileSelectScanner\n" );

	InitTwain();

	// SM userselect, or standard SM based user interface to Source's
	// - open dsm
	// - show user the data sources found by the SM
	//   allow user to pick a particular Source
	// - close the SM
	if( TWOpenDSM(this->m_hWnd) == TRUE )
	{
		TWSelectDS();
		TWCloseDSM (NULL);
		if( !TWIsDSMOpen() )
		{
			// Do something
		}
	}//end of if
}//end of OnFileSelectScanner
///////////////////////////////////////////////////////////////////////////////////////////////
void CMainFrame::OnFileScanImage() 
{
	TRACE0("\nMainFrm.cpp : OnFileScanImage\n" );
					
	TW_INT16 Flag = 0;
	HMENU   hmenu = ::GetMenu(this->m_hWnd);

	InitTwain();

	//Setup dsID for default Source                             
	if( !TWIsDSOpen() )
	{
		dsID.Id = 0;
		dsID.ProductName[0] = 0;
		appID.Id = 0;   
	}
	//  1 Disable/CloseDS/CloseDSM
	//  3 Do Not Disable - only if ShowUI=TRUE
	Flag = 1;
	if( TWAcquire(this->m_hWnd, 8, Flag) )
	{
		// TO DO : SHOW ERROR
	}

}//end of OnFileScanImage
/////////////////////////////////////////////////////////////////////////////////////////////////////////
VOID CMainFrame::InitTwain()
{
	TW_IDENTITY AppIdentity;

	// Set up the info about the application that will pass to the SM in this call.
	AppIdentity.Id = 0; 				// init to 0, but Source Manager will assign real value
	AppIdentity.Version.MajorNum = 1;
	AppIdentity.Version.MinorNum = 003;
	AppIdentity.Version.Language = TWLG_USA;
	AppIdentity.Version.Country  = TWCY_USA;
	lstrcpy( (LPTSTR)AppIdentity.Version.Info,  _T("TWAIN_32 Alpha 1.0.0.3  06/28/2000"));
	lstrcpy( (LPTSTR)AppIdentity.ProductName,   _T("Alpha CG"));

	AppIdentity.ProtocolMajor = 1;//TWON_PROTOCOLMAJOR;
	AppIdentity.ProtocolMinor = 0;//TWON_PROTOCOLMINOR;
	AppIdentity.SupportedGroups =  DG_IMAGE | DG_CONTROL;
	lstrcpy( (LPTSTR)AppIdentity.Manufacturer,  _T("InnoVision, Inc.") );
	lstrcpy( (LPTSTR)AppIdentity.ProductFamily, _T("Alpha CG") );

	//TWAIN initialization
	TWInitialize(&AppIdentity, this->m_hWnd);
}//end of CMainFrame::InitTwain()
/////////////////////////////////////////////////////////////////////////////////////////////////////////
BOOL CMainFrame::PreTranslateMessage(MSG* pMsg) 
{
	ProcessTWMessage((LPMSG)pMsg, this->m_hWnd);
	return CMDIFrameWnd::PreTranslateMessage(pMsg);
}//end of CMainFrame::PreTranslateMessage
/////////////////////////////////////////////////////////////////////////////////////////////////////////
// Testing purpose for Jim
// NOTES:   1). delete any bit maps laying around
//          2). delete any palettes laying around
VOID CMainFrame::CleanUpApp()
{	
	if(_ghDIB) // Free any previous DIB image
	{
		GlobalFree(_ghDIB);
		_ghDIB = NULL;
	}

	if( hbm )
		DeleteObject(hbm);

	hbm = NULL;
	if( hDibPal )
		DeleteObject(hDibPal);

	hDibPal = NULL;
	return;

}//end of CMainFrame::CleanUpApp()
//////////////////////////////////////////////////////////////////////////////////////////
// This function save the bitmap in a file.
// INPUT : HGLOBAL _hDIB - handle of dib section
BOOL CMainFrame::SaveScanedImage(HGLOBAL _hDIB)
{
	HWND hWnd = this->m_hWnd;
	HINSTANCE hInst = AfxGetApp()->m_hInstance;

	BITMAPFILEHEADER bfh;
	BITMAPINFOHEADER *pBIH = NULL;

	HANDLE	hf	= NULL;
	UINT	i	= 0, cbString = 0;

	// Initialize all structures	
	memset(&bfh, 0, sizeof(BITMAPFILEHEADER));
	ASSERT(hWnd); // expect a valid HWND
	
	if(_hDIB)
	{
		FILE_REQ_FOLDER_INFO	imgFRD;
		ZeroMemory( &imgFRD, sizeof(imgFRD) );
		imgFRD.opt = SAVE_OP;
		_tcscpy( imgFRD.DlgTitle, _T("Save Image As") );
		if( !FileRequestDlg( &imgFRD, FILE_CATEGORY_BITMAP ) )
			return( 0 ); //error

		// Get the user to provide the destination name
		hf = CreateFile( imgFRD.CompleteFileName, 
						 GENERIC_WRITE, 0, 
						 (LPSECURITY_ATTRIBUTES)NULL,
						 CREATE_ALWAYS,
						 FILE_ATTRIBUTE_NORMAL,
						 (HANDLE)NULL
					);
		if( hf )
		{
			// Get a pointer to the beginning of the DIB
			pBIH = (BITMAPINFOHEADER*)GlobalLock(_hDIB);
			if(pBIH)
			{
				DWORD dwBytesWritten = 0l;

				// Fill in the Bitmap File Header
				bfh.bfType = ( (WORD) ('M' << 8) | 'B');
				
				//	Calculate the size of the bitmap including the palette
				bfh.bfSize = sizeof(BITMAPFILEHEADER) + sizeof(BITMAPINFOHEADER) +
					((((pBIH->biWidth * pBIH->biBitCount + 31)/32) * 4) * pBIH->biHeight)
						+ pBIH->biClrUsed * sizeof(RGBQUAD);
				bfh.bfReserved1 = 0;
				bfh.bfReserved2 = 0;
				
				//	Offset to actual bits is after palette
				bfh.bfOffBits = sizeof(BITMAPFILEHEADER) + sizeof(BITMAPINFOHEADER)
					+ pBIH->biClrUsed * sizeof(RGBQUAD);

				ASSERT(bfh.bfSize > sizeof(BITMAPFILEHEADER));

				//	Write the results
				WriteFile(hf, &bfh, sizeof(BITMAPFILEHEADER), &dwBytesWritten, NULL);
				WriteFile(hf, pBIH, bfh.bfSize-sizeof(BITMAPFILEHEADER), &dwBytesWritten, NULL);
				
				GlobalUnlock(_hDIB); // Done now
			}//end of if - pBIH
			CloseHandle(hf);
		}//end of if - hf
	}//end of if - _hDIB

	return( 0 );
}//end of SaveSacnedImage
/////////////////////////////////////////////////////////////////////////////////////////
void CMainFrame::OnTimer(UINT nIDEvent) 
{
	TRACE0("MainFrm.cpp - CMainFrame::OnTimer\n" );

	switch( nIDEvent )
	{
	case LD_PIC_TIMER:
		KillTimer( LD_PIC_TIMER );
		LoadPictureDlg();
		break;
	case TOP_WND_TIMER:
		KillTimer( TOP_WND_TIMER );
		::SetForegroundWindow( AfxGetMainWnd()->m_hWnd );
		break;
	}//end of switch - nIDEvent
		
	CMDIFrameWnd::OnTimer(nIDEvent);
}//end of CMainFrame::OnTimer
/////////////////////////////////////////////////////////////////////////////////////////
void CMainFrame::OnEditCharMap() 
{
	CCharMap dlgCharMap;
	
	int nRet = -1;
	nRet = dlgCharMap.DoModal(); // Create and show the dialog box
	// Handle the return value from DoModal
	switch( nRet )
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
	};//end of switch	
		
}//end of CMainFrame::OnEditCharMap
/////////////////////////////////////////////////////////////////////////////////////////
void CMainFrame::OnEditFontLocator() 
{
	CFontLocator	dlgFont;

	int rv = -1;
	rv = dlgFont.DoModal();
	switch( rv )
	{
	case -1:
		AfxMessageBox(_T("Dialog box could not be created!"));	  
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
	}//end of switch - rv
}//end of CMainFrame::OnEditFontLocator() 
/////////////////////////////////////////////////////////////////////////////////////////
// Do the same thing as OnTxtgfxImport() that load the picture
void CMainFrame::OnFileImportGfx() 
{
	OnAddObjImport();		
}//end of CMainFrame::OnFileImportGfx()
/////////////////////////////////////////////////////////////////////////////////////////
void CMainFrame::OnFileExportPage() 
{
	FILE_REQ_FOLDER_INFO	exPgFRD;

	ZeroMemory( &exPgFRD, sizeof( exPgFRD ) );

	exPgFRD.nFileType = FILE_CATEGORY_EXPORT_PAGE;
	//TRACE THIS...
	CGS_GetFileCategoryPathInfo( &exPgFRD );

	_tcscpy( exPgFRD.DlgTitle, _T("Export Page") );
	exPgFRD.opt = SAVE_OP;
	if( !FileRequestDlg( &exPgFRD, FILE_CATEGORY_EXPORT_PAGE ) )
		return;

	CGS_SetFileCategoryPathInfo( &exPgFRD );
	CString		strPath( exPgFRD.CompleteFileName );	

	CAcgMsgBox	dlg;	// +++ start export page waiting dialog	
	dlg.GetCGSExportPageParam( strPath, exPgFRD.nFileExt - 1 );
	dlg.GetStrIndex( "WAIT_TITLE", "WAIT_MSG_1", "WAIT_TEXT" );
	dlg.SetFunctionState( FN_EXPORT_PAGE );
	switch( dlg.DoModal() )
	{
	case IDCANCEL:
		//jrs 01-05-10 beeps removed
		//MessageBeep( 1 );
		//MessageBeep( 1 );
		//MessageBeep( 1 );
		break;
	}//end of switch
}//end of CMainFrame::OnFileExportPage() 
/////////////////////////////////////////////////////////////////////////////////////////
void CMainFrame::OnFileExportProject() 
{
	FILE_REQ_FOLDER_INFO	exProjFRD;

	ZeroMemory( &exProjFRD, sizeof( exProjFRD ) );

	exProjFRD.nFileType = FILE_CATEGORY_EXPORT_PAGE;
	CGS_GetFileCategoryPathInfo( &exProjFRD );

	_tcscpy( exProjFRD.DlgTitle, _T("Export Project") );
	exProjFRD.opt = SAVE_OP;
	if( !FileRequestDlg( &exProjFRD, FILE_CATEGORY_EXPORT_PAGE ) )
		return;

	CGS_SetFileCategoryPathInfo( &exProjFRD );
	CString		strPath( exProjFRD.CompleteFileName );	

	CAcgMsgBox	dlg;	// +++ start export page waiting dialog	
	dlg.GetCGSExportPageParam( strPath, exProjFRD.nFileExt - 1 );
	dlg.GetStrIndex( "WAIT_TITLE", "WAIT_MSG_1", "WAIT_TEXT" );
	dlg.SetFunctionState( FN_EXPORT_PROJ );
	switch( dlg.DoModal() )
	{
	case IDCANCEL:
		//jrs 01-05-10 beeps removed
		//MessageBeep( 0xFFFFFFFF );
		//MessageBeep( 0xFFFFFFFF );
		//MessageBeep( 0xFFFFFFFF );
		break;
	}//end of switch
	
}//end of CMainFrame::OnFileExportProject() 
/////////////////////////////////////////////////////////////////////////////////////////
// Magnifier - Normal
void CMainFrame::OnAddObjMag() 
{
	
}//end of CMainFrame::OnAddObjMag() 
/////////////////////////////////////////////////////////////////////////////////////////
// Magnifier - Minus
void CMainFrame::OnAddObjMagMinus() 
{
	
}//end of CMainFrame::OnObjMagMinus
/////////////////////////////////////////////////////////////////////////////////////////
// Magnifier - Plus
void CMainFrame::OnAddObjMagPlus() 
{
	
}//end of CMainFrame::OnAddObjMagPlus
/////////////////////////////////////////////////////////////////////////////////////////
void CMainFrame::OnHelpTopics() 
{
 	char fn[MAX_PATH];
 	CGS_GetValStr( HELP_FILENAME, fn );
 	::WinHelp( NULL, fn, HELP_FINDER, 0 );
}//end of CMainFrame::OnHelpTopics() 
/////////////////////////////////////////////////////////////////////////////////////////
void CMainFrame::OnProgramSetting() 
{
	// TODO: Add your command handler code here
	CProgSetting	dlg;

	int rv = -1;
	rv = dlg.DoModal();
	switch( rv )
	{
	case -1:
		AfxMessageBox(_T("Program Setting dialog box could not be created!"));	  
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
	}//end of switch - rv
	
}//end of CMainFrame::OnProgramSetting
/////////////////////////////////////////////////////////////////////////////////////////
void CMainFrame::OnLnClear() 
{
	TRACE0( "\nMainFrm.cpp : CGS_Action( CGSA_LINE_CLEAR )" );
	CGS_Action( CGSA_LINE_CLEAR );	
	
}//end of CMainFrame::OnLnClear
/////////////////////////////////////////////////////////////////////////////////////////
void CMainFrame::OnLnDelete() 
{
	TRACE0( "\nMainFrm.cpp : CGS_Action( CGSA_LINE_DELETE )" );
	CGS_Action( CGSA_LINE_DELETE );
	
}//end of CMainFrame::OnLnDelete
/////////////////////////////////////////////////////////////////////////////////////////
void CMainFrame::OnLnInsertAfter() 
{
	TRACE0( "\nMainFrm.cpp : CGS_Action( CGSA_LINE_INSERT_AFTER )" );
	CGS_Action( CGSA_LINE_INSERT_AFTER );
	
}//end of CMainFrame::OnLnInsertAfter
/////////////////////////////////////////////////////////////////////////////////////////
void CMainFrame::OnLnInsertBefore() 
{
	TRACE0( "\nMainFrm.cpp : CGS_Action( CGSA_LINE_INSERT_BEFORE )" );
	CGS_Action( CGSA_LINE_INSERT_BEFORE );
	
}//end of CMainFrame::OnLnInsertBefore
/////////////////////////////////////////////////////////////////////////////////////////
void CMainFrame::OnLnJustCenter() 
{
	TRACE0( "\nMainFrm.cpp : CGS_Action( CGSA_LINE_JUSTIFY_CENTER )" );
	CGS_Action( CGSA_LINE_JUSTIFY_CENTER );
	
}//end of CMainFrame::OnLnJustCenter
/////////////////////////////////////////////////////////////////////////////////////////
void CMainFrame::OnLnJustFlush() 
{
	TRACE0( "\nMainFrm.cpp : CGS_Action( CGSA_LINE_JUSTIFY_FLUSH )" );
	CGS_Action( CGSA_LINE_JUSTIFY_FLUSH );
	
}//end of CMainFrame::OnLnJustFlush
/////////////////////////////////////////////////////////////////////////////////////////
void CMainFrame::OnLnJustLeft() 
{
	TRACE0( "\nMainFrm.cpp : CGS_Action( CGSA_LINE_JUSTIFY_LEFT )" );
	CGS_Action( CGSA_LINE_JUSTIFY_LEFT );
	
}//end of CMainFrame::OnLnJustLeft
/////////////////////////////////////////////////////////////////////////////////////////
void CMainFrame::OnLnJustRight() 
{
	TRACE0( "\nMainFrm.cpp : CGS_Action( CGSA_LINE_JUSTIFY_RIGHT )" );
	CGS_Action( CGSA_LINE_JUSTIFY_RIGHT );
	
}//end of CMainFrame::OnLnJustRight
/////////////////////////////////////////////////////////////////////////////////////////
void CMainFrame::OnStyleCopy() 
{
	CGS_Action( CGSA_COPY_STYLE );
	
}// end of CMainFrame::OnStyleCopy
/////////////////////////////////////////////////////////////////////////////////////////
void CMainFrame::OnStylePaste() 
{
	CGS_Action( CGSA_PASTE_STYLE );
	
}// end of CMainFrame::OnStylePaste
/////////////////////////////////////////////////////////////////////////////////////////
void CMainFrame::OnStyleReset() 
{
	CGS_Action( CGSA_RECALL_DEFAULT_STYLE );
	
}// end of CMainFrame::OnStyleReset
/////////////////////////////////////////////////////////////////////////////////////////
void CMainFrame::OnStyleSaveToBin() 
{
	CGS_Action( CGSA_SAVE_STYLE_PRESET );
	
}// end of CMainFrame::OnStyleSaveToBin()
/////////////////////////////////////////////////////////////////////////////////////////
void CMainFrame::OnFkeyF1() 
{
	CGS_NotifyKeyDownSpecial( (DWORD)0x0, 0x70, 0 );
#if GERMAN_VER
		OnHelpTopics();
#else
		CGS_Action( CGSA_RECALL_DEFAULT_STYLE );
#endif
}// end of CMainFrame::OnFkeyF1() 
//////////////////////////////////////////////////////////////////////////////////////////////////////
void CMainFrame::OnFkeyF10() 
{
	CGS_NotifyKeyDownSpecial( (DWORD)0x0, 0x79, 0 );

#if GERMAN_VER
		CGS_Action( CGSA_RECALL_DEFAULT_STYLE );
#else		
		OnHelpTopics();
#endif
}// end of CMainFrame::OnFkeyF10 
//////////////////////////////////////////////////////////////////////////////////////////////////////
void CMainFrame::OnFkeyF11() 
{
	CGS_NotifyKeyDownSpecial( (DWORD)0x0, 0x7A, 0 );
}// end of CMainFrame::OnFkeyF11
//////////////////////////////////////////////////////////////////////////////////////////////////////
void CMainFrame::OnFkeyF12() 
{
	CGS_NotifyKeyDownSpecial( (DWORD)0x0, 0x70, 0 );
	
}// end of CMainFrame::OnFkeyF12
//////////////////////////////////////////////////////////////////////////////////////////////////////
void CMainFrame::OnFkeyF2() 
{
	TRACE0("MainFrm.cpp - CMainFrame::OnFkeyF2()\n");
	CGS_NotifyKeyDownSpecial( (DWORD)0x0, 0x71, 0 );
	
}// end of CMainFrame::OnFkeyF2
//////////////////////////////////////////////////////////////////////////////////////////////////////
void CMainFrame::OnFkeyF3() 
{
	OnStyleCopy();
	CGS_NotifyKeyDownSpecial( (DWORD)0x0, 0x72, 0 );
	
}// end of CMainFrame::OnFkeyF3
//////////////////////////////////////////////////////////////////////////////////////////////////////
void CMainFrame::OnFkeyF4() 
{
	OnStylePaste();
	CGS_NotifyKeyDownSpecial( (DWORD)0x0, 0x73, 0 );
	
}// end of CMainFrame::OnFkeyF4
//////////////////////////////////////////////////////////////////////////////////////////////////////
void CMainFrame::OnFkeyF5() 
{
	CGS_NotifyKeyDownSpecial( (DWORD)0x0, 0x74, 0 );
	
}// end of CMainFrame::OnFkeyF5
//////////////////////////////////////////////////////////////////////////////////////////////////////
void CMainFrame::OnFkeyF6() 
{
	CGS_NotifyKeyDownSpecial( (DWORD)0x0, 0x75, 0 );
	
}// end of CMainFrame::OnFkeyF6
//////////////////////////////////////////////////////////////////////////////////////////////////////
void CMainFrame::OnFkeyF7() 
{
	CGS_NotifyKeyDownSpecial( (DWORD)0x0, 0x76, 0 );
	
}// end of CMainFrame::OnFkeyF7
//////////////////////////////////////////////////////////////////////////////////////////////////////
void CMainFrame::OnFkeyF8() 
{
	CGS_NotifyKeyDownSpecial( (DWORD)0x0, 0x77, 0 );
	OnPgAddPic();	
}// end of CMainFrame::OnFkeyF8
//////////////////////////////////////////////////////////////////////////////////////////////////////
void CMainFrame::OnFkeyF9() 
{
	CGS_NotifyKeyDownSpecial( (DWORD)0x0, 0x78, 0 );
	
}// end of CMainFrame::OnFkeyF9
//////////////////////////////////////////////////////////////////////////////////////////////////////
void CMainFrame::OnEdRedo() 
{
	CGS_EditUndo();
	
}//end of CMainFrame::OnEdRedo() 
//////////////////////////////////////////////////////////////////////////////////////////////////////
void CMainFrame::OnEdUndo() 
{
	CGS_EditRedo();
	
}//end of CMainFrame::OnEdUndo() 
//////////////////////////////////////////////////////////////////////////////////////////////////////
void CMainFrame::OnPasteInPosition() 
{
	CGS_Action( CGSA_PASTE_TEXT_ORIGINAL_POSITION );
	
}//end of CMainFrame::OnPasteInPosition() 
//////////////////////////////////////////////////////////////////////////////////////////////////////
void CMainFrame::OnSetPageScrollPos() 
{
	m_dlgBarLeft.m_pDlgPage->DoSetScrollPos();
}//end of CMainFrame::OnSetPageScrollPos()
//////////////////////////////////////////////////////////////////////////////////////////////////////
void CMainFrame::OnSetBinTopScrollPos() 
{
	m_dlgBarBinTop.DoSetTopScrollPos();
}// end of CMainFrame::OnSetBinTopScrollPos()
//////////////////////////////////////////////////////////////////////////////////////////////////////
void CMainFrame::OnSetBinBotScrollPos() 
{
	m_dlgBarBinTop.DoSetBotScrollPos();
}// end of CMainFrame::OnSetBinBotScrollPos()
