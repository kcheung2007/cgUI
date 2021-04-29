/* COPYRIGHT NOTICE:
********************************************************
*  Copyright (c) 2000 InnoVision Technology, Inc.      *
*  All rights reserved.                                *
*  PROPRIETARY AND CONFIDENTIAL                        *
*  DO NOT DISTRIBUTE                                   *
********************************************************
*/
// DlgBarLeft.cpp : implementation file
//

#include "stdafx.h"
#include "cgUI.h"
#include "switch.h"
#include "DlgBarLeft.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDlgBarLeft dialog
////////////////////////////////////////////////////////////////////////////

#define		WM_INITDLGBAR_LEFT		WM_USER + WM_USER_LEFT

BEGIN_MESSAGE_MAP(CDlgBarLeft, CDialogBar)
	//{{AFX_MSG_MAP(CDlgBarLeft)
	ON_WM_CREATE()
	ON_MESSAGE( WM_INITDLGBAR_LEFT, InitDialogBarHandler )
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

//////////////////////////////////////////////////////////////////////////////
CDlgBarLeft::CDlgBarLeft()
{
	m_pDlgPage  = NULL;
	m_pDlgLayer = NULL;
}//end of constructor

CDlgBarLeft::~CDlgBarLeft()
{
	// Free page objects
	if( m_pDlgPage != NULL )
		delete m_pDlgPage;

	if( m_pDlgLayer != NULL )
		delete m_pDlgLayer;

}//end of destructor


void CDlgBarLeft::DoDataExchange(CDataExchange* pDX)
{
	// TODO: Add your specialized code here and/or call the base class
	DDX_Control(pDX, IDC_TAB_LEFT, m_ctlTab);
	CDialogBar::DoDataExchange(pDX);
}//end of CDlgBarLeft::DoDataExchange

/////////////////////////////////////////////////////////////////////////////
// CDlgBarLeft message handlers
/////////////////////////////////////////////////////////////////////////////
BOOL CDlgBarLeft::OnInitDialogBar() 
{
	if( SHOW_PAGE )
	{
		m_pDlgPage = new CDlgPage;
		m_pDlgPage->Create(IDD_PAGE_PAGE, &m_ctlTab );
		m_ctlTab.AddTab( m_pDlgPage, _T("Page"), 0 ); // should load from file
	}//end of - SHOW_PAGE

	if( SHOW_LAYER )
	{
		m_pDlgLayer = new CDlgLayer;
		m_pDlgLayer->Create(IDD_PAGE_LAYER, &m_ctlTab );
		m_ctlTab.AddTab( m_pDlgLayer, _T("Layer"), 1 ); // should load from file
	}//end of 

	AfxGetMainWnd()->SendMessage( WM_RESIZE_LEFT_BAR, 0, 0 );
	return( 1 );
}//end of CDlgBarLeft::OnInitDialogBar
/////////////////////////////////////////////////////////////////////////////
int CDlgBarLeft::OnCreate(LPCREATESTRUCT lpCreateStruct) 
{
	if (CDialogBar::OnCreate(lpCreateStruct) == -1)
		return -1;
	
	// Post WM_INITDIALOGBAR message here to initial dialog bar
	PostMessage(WM_INITDLGBAR_LEFT , 0 , 0 );
	
	return 0;
}//end of CDlgBarLeft::OnCreate
///////////////////////////////////////////////////////////////////////////////////
// For the BIG Boss does the update
LRESULT CDlgBarLeft::InitDialogBarHandler(WPARAM wParam, LPARAM lParam)
{
	UpdateData(FALSE);
	OnInitDialogBar() ;

    return( 0 );
}//end of CDlgBarBot::InitDialogBarHandler


