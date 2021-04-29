/* COPYRIGHT NOTICE:
********************************************************
*  Copyright (c) 2000 InnoVision Technology, Inc.      *
*  All rights reserved.                                *
*  PROPRIETARY AND CONFIDENTIAL                        *
*  DO NOT DISTRIBUTE                                   *
********************************************************
*/
// DlgBarBottom.cpp : implementation file
//

#include "stdafx.h"
#include "cgUI.h"
#include "DlgBarBottom.h"


#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

#define		TAB_ATTRIBUTE		0	// position
#define		TAB_BASELINE		1 
#define		TAB_SELECTION		2
#define		TAB_EFFECT			3
#define		TAB_CAPTURE			4
#define		TAB_PRESET			5
#define		TAB_TEMPLATE		6
#define		TAB_VIEW			7

/////////////////////////////////////////////////////////////////////////////
// CDlgBarBot dialog
/////////////////////////////////////////////////////////////////////////////
#define		WM_INITDIALOGBAR		WM_USER + WM_USER_BOTTOM

extern TCHAR UILang_UIFont[256];
extern int	 UILang_UIFontSize;

BEGIN_MESSAGE_MAP(CDlgBarBot,  CDialogBar)
	//{{AFX_MSG_MAP(CDlgBarBot)
	ON_MESSAGE(WM_INITDIALOGBAR , InitDialogBarHandler )
	ON_WM_CREATE()
	ON_WM_DESTROY()
	ON_WM_MOVE()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

//////////////////////////////////////////////////////////////////////////////
CDlgBarBot::CDlgBarBot()
{
	m_pDlgPreset  = NULL;
	m_pDlgBaseln  = NULL;
	m_pDlgEffect  = NULL;
	m_pDlgCapture = NULL;
	m_pDlgAttrib  = NULL;
	m_pDlgSelect  = NULL;
	m_pDlgView	  = NULL;
	m_pDlgTemplate= NULL;

	for( int i = 0; i < BAR_NUMTAB; i++ )
		m_szTab[i][0] = NULL;

	m_hFont = NULL;
}//end of constructor

CDlgBarBot::~CDlgBarBot()
{
	TRACE0("DlgBarBottom : ~CDlgBarBot() - Destructor wake up... \n");
	// Free page objects
	if( m_hFont != NULL )
		DeleteObject( (HGDIOBJ)m_hFont );

	if( m_pDlgPreset != NULL )
	{
		delete m_pDlgPreset;
		m_pDlgPreset = NULL;
	}

	if( m_pDlgTemplate != NULL )
	{
		delete m_pDlgTemplate;
		m_pDlgTemplate = NULL;
	}

	if( m_pDlgBaseln != NULL )
	{
		delete m_pDlgBaseln;
		m_pDlgBaseln = NULL;
	}

	if( m_pDlgEffect != NULL )
	{
		delete m_pDlgEffect;
		m_pDlgEffect = NULL;
	}

	if( m_pDlgCapture != NULL )
	{
		delete m_pDlgCapture;
		m_pDlgCapture = NULL;
	}

	if( m_pDlgAttrib != NULL )
	{
		delete m_pDlgAttrib;
		m_pDlgAttrib = NULL;
	}

	if( m_pDlgSelect != NULL )
	{
		delete m_pDlgSelect;
		m_pDlgSelect = NULL;
	}

	if( m_pDlgView != NULL )
	{
		delete m_pDlgView;
		m_pDlgView = NULL;
	}
}//end of destructor

//////////////////////////////////////////////////////////////////////////////////
// Manualy added entry ON_MESSAGE(WM_INITDIALOGBAR , InitDialogBarHandler)
// as there is no automatic adding from Class Wizard
//////////////////////////////////////////////////////////////////////////////////
// CDlgBarBot message handlers
int CDlgBarBot::OnCreate(LPCREATESTRUCT lpCreateStruct) 
{
		if (CDialogBar::OnCreate(lpCreateStruct) == -1)
		return -1;
 	
	// TODO: Add specialized creation code here

	// Post WM_INITDIALOGBAR message here to dialog bar
	PostMessage(WM_INITDIALOGBAR , 0 , 0 );
	return 0;
}//end of CDlgBarBot::OnCreate

///////////////////////////////////////////////////////////////////////////////////
LRESULT CDlgBarBot::InitDialogBarHandler(WPARAM wParam, LPARAM lParam)
{
	UpdateData(FALSE);
	OnInitDialogBar() ;

    return( 0 );
}//end of CDlgBarBot::InitDialogBarHandler

///////////////////////////////////////////////////////////////////////////////////
void CDlgBarBot::OnInitDialogBar()
{
	RECT	rcTab;
	CPoint	pt;

	LoadTabString( ); // load tab string into local variable
	m_hFont = ChangeControlFont( GetDlgItem(IDC_TAB_BOTTOM)->m_hWnd, NULL, UILang_UIFont,0, UILang_UIFontSize, FW_NORMAL);

	m_ctlTab.GetItemRect( 0, &rcTab );
	pt.x = 3; // pixel
	pt.y = rcTab.bottom + 5; // pixel
	m_ctlTab.SetTopLeftCorner( pt );

	//create image list	
//save for ref.	m_imageListTab.Create(IDB_TABCTRL_IMAGE, 12, 0, RGB(0,0,0) );
//save for ref. m_ctlTab.SetImageList( &m_imageListTab );
	
	if( ATTRIBUTE ) //create Attribute page
	{
		m_pDlgAttrib = new CDlgAttrib;
		m_pDlgAttrib->Create(IDD_PAGE_ATTRIB, &m_ctlTab );

		if( m_szTab[TAB_ATTRIBUTE][0] == NULL ) // load string fail
			m_ctlTab.AddTab( m_pDlgAttrib, _T("Attribte"), 0 ); // default
		else
			m_ctlTab.AddTab( m_pDlgAttrib, (_TCHAR*)m_szTab[TAB_ATTRIBUTE], TAB_ATTRIBUTE ); // read from file
	}
	
	if( BASELINE ) //create baseline page
	{
		m_pDlgBaseln = new CDlgBaselne;
		m_pDlgBaseln->Create(IDD_PAGE_BASELINE, &m_ctlTab );

		if( m_szTab[TAB_BASELINE][0] == NULL ) // load string fail
			m_ctlTab.AddTab( m_pDlgBaseln, _T("Baseline"), 1 ); // default
		else
			m_ctlTab.AddTab( m_pDlgBaseln, (_TCHAR*)m_szTab[TAB_BASELINE], TAB_BASELINE ); // read from file
	}

	if( SELECTION ) //create baseline page
	{
		m_pDlgSelect = new CDlgSelect;
		m_pDlgSelect->Create(IDD_PAGE_SELECTION, &m_ctlTab );

		if( m_szTab[TAB_SELECTION][0] == NULL ) // load string fail
			m_ctlTab.AddTab( m_pDlgSelect, _T("Selection"), 1 ); // default
		else
			m_ctlTab.AddTab( m_pDlgSelect, (_TCHAR*)m_szTab[TAB_SELECTION], TAB_SELECTION ); // read from file
	}
	
	if( EFFECT ) //create Effect page
	{
		m_pDlgEffect = new CDlgEffect;
		m_pDlgEffect->Create(IDD_PAGE_EFFECT, &m_ctlTab );

		if( m_szTab[TAB_EFFECT][0] == NULL ) // load string fail
			m_ctlTab.AddTab( m_pDlgEffect, _T("Effect"), 1 ); // default
		else
			m_ctlTab.AddTab( m_pDlgEffect, (_TCHAR*)m_szTab[TAB_EFFECT], TAB_EFFECT ); // read from file
	}
	
	if( CAPTURE ) //create Capture page
	{
		m_pDlgCapture = new CDlgCapture;
		m_pDlgCapture->Create(IDD_PAGE_CAPTURE, &m_ctlTab );

		if( m_szTab[TAB_CAPTURE][0] == NULL ) // load string fail
			m_ctlTab.AddTab( m_pDlgCapture, _T("Capture"), 1 ); // default
		else
			m_ctlTab.AddTab( m_pDlgCapture, (_TCHAR*)m_szTab[TAB_CAPTURE], TAB_CAPTURE ); //read from file
	}
	
	if( PRESET ) //create preset page
	{
		m_pDlgPreset = new CDlgPreset;
		m_pDlgPreset->Create(IDD_PAGE_PRESET, &m_ctlTab );

		if( m_szTab[TAB_PRESET][0] == NULL ) // load string fail
			m_ctlTab.AddTab( m_pDlgPreset, _T("Preset"), 1 ); // default
		else
			m_ctlTab.AddTab( m_pDlgPreset, (_TCHAR*)m_szTab[TAB_PRESET], TAB_PRESET ); // should load from file	
	}

	if( TEMPLATE ) //create template page
	{
		m_pDlgTemplate = new CPgTemplate;
		m_pDlgTemplate->Create(IDD_PAGE_TEMPLATES, &m_ctlTab );

		if( m_szTab[TAB_TEMPLATE][0] == NULL ) // load string fail
			m_ctlTab.AddTab( m_pDlgTemplate, _T("Template"), 1 ); // default
		else
			m_ctlTab.AddTab( m_pDlgTemplate, (_TCHAR*)m_szTab[TAB_TEMPLATE], TAB_TEMPLATE ); // should load from file	
	}

	if( VIEW )
	{
		m_pDlgView = new CDlgView;
		m_pDlgView->Create(IDD_PAGE_VIEW, &m_ctlTab );

		if( m_szTab[TAB_VIEW][0] == NULL ) // load string fail
			m_ctlTab.AddTab( m_pDlgView, _T("View"), 1 ); // default
		else
			m_ctlTab.AddTab( m_pDlgView, (_TCHAR*)m_szTab[TAB_VIEW], TAB_VIEW ); // should load from file	
	}

	AfxGetMainWnd()->SetFocus(); // must set focus here because of the last creation
}//end of CDlgBarBot::OnInitDialogBar()

/////////////////////////////////////////////////////////////////////////////
// CDlgBarBot message handlers
/////////////////////////////////////////////////////////////////////////////
void CDlgBarBot::DoDataExchange(CDataExchange* pDX) 
{
	// TODO: Add your specialized code here and/or call the base class
	DDX_Control(pDX, IDC_TAB_BOTTOM, m_ctlTab);
	CDialogBar::DoDataExchange(pDX);
}
/////////////////////////////////////////////////////////////////////////////
// NOTE : Attemp to free page objects here, but warning message occur:
// Calling DestroyWindow in CDialog::~CDialog -- OnDestroy or PostNcDestroy 
// in derived class will not be called. ???? 
void CDlgBarBot::OnDestroy() 
{
	TRACE0("DlgBarBottom : OnDestroy() - On Destroy now ... \n");
	CDialogBar::OnDestroy();
	
	// TODO: Add your message handler code here
}//end of CDlgBarBot::OnDestroy
/////////////////////////////////////////////////////////////////////////////
// May need this section for redraw issue
void CDlgBarBot::OnMove(int x, int y) 
{
	CDialogBar::OnMove(x, y);
	
	// Start adding your message handler code here
	TRACE0("DlgBarBottom : OnMove()\n");
// save next two line for future - solving redraw issue
//	if( !IsFloating() )
//		RedrawWindow( NULL, NULL, RDW_INVALIDATE | RDW_UPDATENOW | RDW_ERASE ); 
}//end of CDlgBarBot::OnMove
/////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////
// Loading string sequence MUST match with the sequence of creating Tab.
VOID CDlgBarBot::LoadTabString( )
{
	HFONT hFont = NULL;
	IN_TEXT_DATA* txtData = NULL;
	TCHAR	sep[] = _T("\"");
	TCHAR*	ptID;
	TCHAR*	ptTT;
	TCHAR*	ptEnd;

	DWORD numTxt = LoadTextFromCtl( "\\Util\\TabString.ctl", "[Bar Tab String]", &txtData );
	if( numTxt == 0 )
		return;

	for( DWORD i = 0; i < BAR_NUMTAB; i++ )
	{
		ptID   = _tcstok( txtData[i].szTT, sep );
		ptTT   = _tcstok( NULL, sep );
		ptEnd  = _tcstok( NULL, sep );
		if( ptEnd != 0 )
			*ptEnd = '\0';

		if( NULL != _tcsstr( txtData[i].szTT, _T("ATTRIBUTE") ) )
			_tcscpy( m_szTab[TAB_ATTRIBUTE], (TCHAR*)ptTT );
		else
			if( NULL != _tcsstr( txtData[i].szTT, _T("EFFECT") ) )
				_tcscpy( m_szTab[TAB_EFFECT], (TCHAR*)ptTT );
		else
			if( NULL != _tcsstr( txtData[i].szTT, _T("CAPTURE") ) )
				_tcscpy( m_szTab[TAB_CAPTURE], (TCHAR*)ptTT );
		else
			if( NULL != _tcsstr( txtData[i].szTT, _T("PRESET") ) )
				_tcscpy( m_szTab[TAB_PRESET], (TCHAR*)ptTT );
		else
			if( NULL != _tcsstr( txtData[i].szTT, _T("BASELINE") ) )
				_tcscpy( m_szTab[TAB_BASELINE], (TCHAR*)ptTT );
		else
			if( NULL != _tcsstr( txtData[i].szTT, _T("SELECTION") ) )
				_tcscpy( m_szTab[TAB_SELECTION], (TCHAR*)ptTT );
		else
			if( NULL != _tcsstr( txtData[i].szTT, _T("VIEW") ) )
				_tcscpy( m_szTab[TAB_VIEW], (TCHAR*)ptTT );
		else
			if( NULL != _tcsstr( txtData[i].szTT, _T("TEMPLATE") ) )
				_tcscpy( m_szTab[TAB_TEMPLATE], (TCHAR*)ptTT );
	}//end of for

	free( txtData );
}//end of CDlgBarBot::LoadTabString()
//////////////////////////////////////////////////////////////////////////////////////////////
CDlgAttrib* CDlgBarBot::GetAttribDlgPtr()
{
	return( m_pDlgAttrib );
}//end of CDlgBarBot::GetAttribDlgPtr()
//////////////////////////////////////////////////////////////////////////////////////////////
CDlgEffect* CDlgBarBot::GetEffectDlgPtr()
{
	return( m_pDlgEffect );
}//end of CDlgBarBot::GetEffectDlgPtr()
//////////////////////////////////////////////////////////////////////////////////////////////
CDlgCapture* CDlgBarBot::GetCaptureDlgPtr()
{
	return( m_pDlgCapture );
}//end of CDlgBarBot::GetCaptureDlgPtr()
//////////////////////////////////////////////////////////////////////////////////////////////
CDlgBaselne* CDlgBarBot::GetBaselinePtr()
{
	return( m_pDlgBaseln );
}//end of CDlgBarBot::GetBaselinePtr()
//////////////////////////////////////////////////////////////////////////////////////////////
CDlgSelect* CDlgBarBot::GetSelectDlgPtr()
{
	return( m_pDlgSelect );
}//end of CDlgBarBot::GetSelectDlgPtr()
