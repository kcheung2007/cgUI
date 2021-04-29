/* COPYRIGHT NOTICE:
********************************************************
*  Copyright (c) 2000 InnoVision Technology, Inc.      *
*  All rights reserved.                                *
*  PROPRIETARY AND CONFIDENTIAL                        *
*  DO NOT DISTRIBUTE                                   *
********************************************************
*/
// DlgPage.cpp : implementation file
//

#include "stdafx.h"
#include "cgUI.h"
#include "DlgPage.h"
#include "Global.h"
#include "AcgMsgBox.h"
#include "FileReq.h"

#include "ACGS_Inc\\UI_BinMgr.h" //in ACGS_Inc folder (JRS)


#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

extern DWORD	g_CodePage;
/////////////////////////////////////////////////////////////////////////////
// CPageNum - SubClass of Edit Control
// For capture the tab and enter event inside the edit control
/////////////////////////////////////////////////////////////////////////////
CPageNum::CPageNum()
{
}

CPageNum::~CPageNum()
{
}


BEGIN_MESSAGE_MAP(CPageNum, CEdit)
	//{{AFX_MSG_MAP(CPageNum)
	ON_WM_CHAR()
	ON_WM_MOUSEMOVE()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CPageNum message handlers
/////////////////////////////////////////////////////////////////////////////
void CPageNum::OnChar(UINT nChar, UINT nRepCnt, UINT nFlags) 
{
//save for ref.	
//	TRACE0( "DlgPage.cpp : CPageNum::OnChar\n" );
	CEdit::OnChar(nChar, nRepCnt, nFlags);
}//end of CPageNum::OnChar
/////////////////////////////////////////////////////////////////////////////
void CPageNum::OnMouseMove(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
	TRACE0( "MOVE MOVE\n" );
	CEdit::OnMouseMove(nFlags, point);

//	AfxGetMainWnd()->SetFocus();
}// End of CPageNum - SubClass of Edit control
/////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////
// CPgImgBox
CPgImgBox::CPgImgBox()
{
}

CPgImgBox::~CPgImgBox()
{
}

BEGIN_MESSAGE_MAP(CPgImgBox, CEdit)
	//{{AFX_MSG_MAP(CPgImgBox)
	ON_WM_MOUSEMOVE()
	ON_WM_LBUTTONDOWN()
	ON_WM_PAINT() //JRS
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

//OnPaint added by JRS
void CPgImgBox::OnPaint() 
{
	CPaintDC dc(this); // device context for painting
	
	//JRS ADD
	CGS_BinRefresh(UIBIN_PAGE);
	AfxGetMainWnd()->SetFocus();
	// Do not call CEdit::OnPaint() for painting messages
}
/////////////////////////////////////////////////////////////////////////////
void CPgImgBox::OnMouseMove(UINT nFlags, CPoint pt) 
{
	// TODO: Add your message handler code here and/or call default
	TRACE2( "DlgPage.cpp : CPgImgBox::OnMouseMove - x = %d, y = %d\n", pt.x, pt.y );
	CEdit::OnMouseMove(nFlags, pt);
	
}//end of OnMouseMove
/////////////////////////////////////////////////////////////////////////////
void CPgImgBox::OnLButtonDown(UINT nFlags, CPoint pt) 
{	
	TRACE2( "DlgPage.cpp : CPgImgBox::OnLButtonDown - x = %d, y = %d\n", pt.x, pt.y );
	CGS_BinSelect(UIBIN_PAGE, ABMC_DEFAULT, pt.x, pt.y); //JRS - CHECK: problem here
	CEdit::OnLButtonDown(nFlags, pt);
	TRACE0( "DlgPage.cpp : Before set focus\n" );
	AfxGetMainWnd()->SetFocus();
}//end of OnLButtonDown

// CPgImgBox message handlers
/////////////////////////////////////////////////////////////////////////////


/////////////////////////////////////////////////////////////////////////////
// CDlgPage dialog
/////////////////////////////////////////////////////////////////////////////
// Define range of scroll bar
#define TOP_RANGE		1
#define BOTTOM_RANGE	1000
#define PAGE_RANGE		100

CDlgPage::CDlgPage(CWnd* pParent /*=NULL*/)	: CDialog(CDlgPage::IDD, pParent)
{
	//{{AFX_DATA_INIT(CDlgPage)
	m_edPgNum = 1;
	//}}AFX_DATA_INIT
}

void CDlgPage::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDlgPage)
	DDX_Control(pDX, IDC_BT_NEW_PAGE, m_btNewPage);
	DDX_Control(pDX, IDC_BT_EXPORT_PAGE, m_btExportPage);
	DDX_Control(pDX, IDC_STC_PAGE_TOTAL, m_stcPgTotal);
	DDX_Control(pDX, IDC_CB_PAGE_TYPE, m_cbPgType);
	DDX_Control(pDX, IDC_VSB_PGBOX, m_vsbList);
	DDX_Text(pDX, IDC_ED_PAGE_NUM, m_edPgNum);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CDlgPage, CDialog)
	//{{AFX_MSG_MAP(CDlgPage)
	ON_WM_VSCROLL()
	ON_CBN_SELCHANGE(IDC_CB_PAGE_TYPE, OnSelchangeCbPageType)
	ON_BN_CLICKED(IDC_BT_NEW_PAGE, OnBtNewPage)
	ON_BN_CLICKED(IDC_BT_EXPORT_PAGE, OnBtExportPage)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDlgPage message handlers

/////////////////////////////////////////////////////////////////////////////
BOOL CDlgPage::OnInitDialog() 
{
	CDialog::OnInitDialog();
		
//	m_stcPgTotal.SetWindowText( _T("100") );// default total page
	SetDlgItemInt( IDC_STC_PAGE_TOTAL, (int)CGS_GetValDbl(EDIT_PROJECT_TOT_PAGES), 0 );
	m_vsbList.SetScrollRange( 1, 1000 );	// default range
//	m_vsbList.SetScrollPos( 2 );			// default position

	// Initial combo box and select Crawl
	InitComboString( _T("\\Util\\DlgPage.ctl"), _T("[Combo String]"), &m_cbPgType );

	// Initial page number edit box
	m_edPgNum = 10; // default - read from outside function
	m_ctlPgNumEd.SubclassDlgItem( IDC_ED_PAGE_NUM, this );
	m_ctlPgDlgImg.SubclassDlgItem( IDC_LIST_BOX, this );

	HINSTANCE hInst = AfxGetApp()->m_hInstance;
	m_btNewPage.SetIcon( (HICON)::LoadImage( hInst,MAKEINTRESOURCE(IDI_NEW_PAGE), IMAGE_ICON, 16, 16, 0) );
	m_btExportPage.SetIcon( (HICON)::LoadImage( hInst,MAKEINTRESOURCE(IDI_EXPORT_PAGE), IMAGE_ICON, 16, 16, 0) );
/*
	CRect rcListBox;
	m_ctlPgDlgImg.GetWindowRect( &rcListBox );
	m_vsbList.SetWindowPos( &wndTop, rcListBox.right, rcListBox.top, 0, 0, SWP_NOSIZE | SWP_SHOWWINDOW );
*/	
	// End of adding extra initialization here
	CGS_BinOpen(
		UIBIN_PAGE,
		m_ctlPgDlgImg.m_hWnd,
		NULL,
		IXReg_RedrawPageBinThumbTrack //01-04-13 i.e. UI_RedrawPageBinThumbTrack function for core to call to tell UI to redraw thumb track position e.g. void UI_RedrawPageBinThumbTrack(double ScrollPos_01);
		);

	CGS_BinRegisterGetStringDlgCallback(UIBIN_PAGE,DoPageLabelDlg); //JRS
		
	// Create the ToolTip control.
	m_tooltip.Create(this);
	m_tooltip.Activate(TRUE);
	InitDlgItemTextNTooltip();

	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}//end of CDlgPage::OnInitDialog
/////////////////////////////////////////////////////////////////////////////
void CDlgPage::OnVScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar) 
{
	// TODO: Add your message handler code here and/or call default
	ASSERT(pScrollBar != NULL);

	int nCurPos = pScrollBar->GetScrollPos();
	switch( nSBCode )
	{
	case SB_TOP:			// Scroll to far top.
		nCurPos = TOP_RANGE;
		break;
	case SB_LINEUP:			// Scroll one line up.
		CGS_BinScrollLineUp( UIBIN_PAGE );
		nCurPos = (int)(CGS_BinGetScroll(UIBIN_PAGE) * 1000.0);
		break;
	case SB_LINEDOWN:		// Scroll one line down.
		CGS_BinScrollLineDown( UIBIN_PAGE );
		nCurPos = (int)(CGS_BinGetScroll(UIBIN_PAGE) * 1000.0);
		break;
	case SB_PAGEUP:			// Scroll one page up.
		CGS_BinScrollPageUp( UIBIN_PAGE );
		nCurPos = (int)(CGS_BinGetScroll(UIBIN_PAGE) * 1000.0);
		break;
	case SB_PAGEDOWN:		// Scroll one page down.
		CGS_BinScrollPageDown( UIBIN_PAGE );
		nCurPos = (int)(CGS_BinGetScroll(UIBIN_PAGE) * 1000.0);
		break;
	case SB_BOTTOM:			// Scroll to far bottom.
		nCurPos = BOTTOM_RANGE;
		break;
	case SB_THUMBPOSITION:	// Scroll to absolute position. 
	case SB_THUMBTRACK:		// Drag scroll box to specified position. 
		nCurPos = nPos;
		break;
	case SB_ENDSCROLL:		// End scroll
		TRACE0( "DlgPage.cpp : OnVScroll - End scroll\n" );
		break;
	}//end of switch - nSBCode

	nCurPos = ( nCurPos      < TOP_RANGE ) ? TOP_RANGE    : nCurPos;
	nCurPos = ( BOTTOM_RANGE < nCurPos )   ? BOTTOM_RANGE : nCurPos;

	pScrollBar->SetScrollPos(nCurPos);

	CGS_BinSetScroll(UIBIN_PAGE,(double) ((double)nCurPos) / (1000.0f) ); //JRS

	// End of adding your message handler code here and/or call default	
	CDialog::OnVScroll(nSBCode, nPos, pScrollBar);
}//end of CDlgPage::OnVScroll
/////////////////////////////////////////////////////////////////////////////
// Quick solution on sending message to child window that disable scroll bar.
// Should have a better way to do it. Look for it later.
void CDlgPage::OnSelchangeCbPageType() 
{	
	switch( m_cbPgType.GetCurSel() )
	{
	case 0: // still
		IXReg_ScrollBarEnableProc( 0, 0 );
//save		AfxGetMainWnd()->SendMessage( WM_COMMAND, ID_PAGE_TYPE_STILL, 0 );
		break;
	case 1: // roll
		IXReg_ScrollBarEnableProc( 0, 1 );
//save		AfxGetMainWnd()->SendMessage( WM_COMMAND, ID_PAGE_TYPE_CRAWL, 0 );		
		break;
	case 2: // crawl
		IXReg_ScrollBarEnableProc( 1, 0 );
//save		AfxGetMainWnd()->SendMessage( WM_COMMAND, ID_PAGE_TYPE_ROLL, 0 );
		break;
	}//end of switch	

	AfxGetMainWnd()->SetFocus();
}//end of CDlgPage::OnSelchangeCbPageType
/////////////////////////////////////////////////////////////////////////////
void CDlgPage::OnOK() 
{	// Required for intercepting Enter key event (OK)
	DWORD pgNum = GetDlgItemInt( IDC_ED_PAGE_NUM, NULL, 0 );
	if( pgNum != m_edPgNum )
	{
		m_edPgNum = pgNum;
		TRACE1( "DlgPage.cpp : CDlgPage::OnOK - m_edPgNum = %d\n", m_edPgNum );
	}

	AfxGetMainWnd()->SetFocus();
}//end of CDlgPage::OnOK
/////////////////////////////////////////////////////////////////////////////
void CDlgPage::OnCancel() 
{	
	// capture cancel message
}//end of CDlgPage::OnCancel
/////////////////////////////////////////////////////////////////////////////
VOID CDlgPage::InitComboString( LPTSTR ptFn, LPTSTR ptSection, CComboBox* ptCombo )
{
	IN_TEXT_DATA* txtData = NULL;
	TCHAR	sep[] = _T("\"");
	TCHAR*	ptID;
	TCHAR*	ptTT;
	TCHAR*	ptEnd;

	CHAR	fn[MAX_PATH];
	CHAR	section[MAX_PATH];

	UnicodeToMultiByte( g_CodePage, ptFn, fn );
	UnicodeToMultiByte( g_CodePage, ptSection, section );
//save	WideCharToMultiByte( g_CodePage, 0, ptFn, -1, fn,	sizeof(fn), NULL, NULL	);
//save	WideCharToMultiByte( g_CodePage, 0, ptSection, -1, section, sizeof(section), NULL, NULL );
	DWORD numTxt = LoadTextFromCtl( fn, section, &txtData );
	if( numTxt == 0 )
		return;

//	DWORD numTxt = LoadTextFromCtl( (CHAR*)ptFn, (CHAR*)ptSection, &txtData );

	for( DWORD i = 0; i < numTxt; i++ )
	{
		ptID   = _tcstok( txtData[i].szTT, sep );
		ptTT   = _tcstok( NULL, sep );
		ptEnd  = _tcstok( NULL, sep );
		if( ptEnd != 0 )
			*ptEnd = '\0';

		ptCombo->AddString( (LPCTSTR)ptTT );
	}//end of for

	ptCombo->SetCurSel( (int)CGS_GetValDbl(PAGE_TYPE) );

	free( txtData );
}//end of InitComboString
///////////////////////////////////////////////////////////////////////////////////////////////
VOID CDlgPage::DoValueUpdate()
{
/* save for reference
	int pageType;

	int r = (int)CGS_GetValDbl(PAGE_TYPE); //<<< --- did not return the right value
	switch( r )
	{
	case CGS_STILL_PAGE_TYPE:
		pageType = 0;
		break;
	case CGS_ROLL_PAGE_TYPE:
		pageType = 1;
		break;
	case CGS_CRAWL_PAGE_TYPE:
		pageType = 2;
		break;
	}//end of switch
** save for reference ***/

	m_cbPgType.SetCurSel( (int)CGS_GetValDbl(PAGE_TYPE) ); // read page type from core	

//  wait for confirm
//	int nPages = 200; //read total page from core - assume is 200
//	char buf[5];
//	_itoa( nPages, buf, 10 );
//	m_stcPgTotal.SetWindowText( buf );	// default total page

//	m_edPgNum = 2; // read the current selected page number from core - assume is 2
//	SetDlgItemInt( IDC_ED_PAGE_NUM, m_edPgNum );

	AfxGetMainWnd()->SetFocus();
}//end of CDlgPage::DoValueUpdate()
///////////////////////////////////////////////////////////////////////////////////////////////
void CDlgPage::OnBtNewPage() 
{
	CGS_Action( CGSA_APPEND_PAGE );
	AfxGetMainWnd()->SetFocus();
}//end of CDlgPage::OnBtNewPage
///////////////////////////////////////////////////////////////////////////////////////////////
void CDlgPage::OnBtExportPage() 
{
	AfxGetMainWnd()->SendMessage( WM_COMMAND, ID_FILE_EXPORT_PAGE, 0 );
	AfxGetMainWnd()->SetFocus();
}//end of CDlgPage::OnBtExportPage
///////////////////////////////////////////////////////////////////////////////////////////////
BOOL CDlgPage::PreTranslateMessage(MSG* pMsg)
{
	// Let the ToolTip process this message.
	m_tooltip.RelayEvent(pMsg);

	return CDialog::PreTranslateMessage(pMsg);	// CG: This was added by the ToolTips component.
}//end of CDlgPage::PreTranslateMessage
///////////////////////////////////////////////////////////////////////////////////////////////
VOID CDlgPage::InitDlgItemTextNTooltip()
{
	IN_TEXT_DATA* txtData = NULL;
	TCHAR	sep[] = _T("\"");
	TCHAR*	ptID;
	TCHAR*	ptTT;
	TCHAR*	ptEnd;

	DWORD numTxt = LoadTextFromCtl( "\\Util\\DlgPage.ctl", "[Tooltip]", &txtData );
	if( numTxt == 0 )
		return;

	for( DWORD i = 0; i < numTxt; i++ )
	{
		ptID   = _tcstok( txtData[i].szTT, sep );
		ptTT   = _tcstok( NULL, sep );
		ptEnd  = _tcstok( NULL, sep );
		if( ptEnd != 0 )
			*ptEnd = '\0';
			
		if( NULL != _tcsstr( txtData[i].szTT, _T("IDC_BT_NEW_PAGE") ) )
			txtData[i].idTT = IDC_BT_NEW_PAGE;
		else
			if( NULL != _tcsstr( txtData[i].szTT, _T("IDC_BT_EXPORT_PAGE") ) )
				txtData[i].idTT = IDC_BT_EXPORT_PAGE;

		_tcscpy( txtData[i].szTT, (TCHAR*)txtData[i].szTT );
		if( NULL != GetDlgItem(txtData[i].idTT) )
			m_tooltip.AddTool( GetDlgItem(txtData[i].idTT), (_TCHAR*)ptTT);
	}//end of for

	free( txtData );
}//end of CDlgPage::InitDlgItemTextNTooltip()
//////////////////////////////////////////////////////////////////////////////////////////////////
// Resize the scroll bar control and list control when users resize the whole app
BOOL CDlgPage::ReSizeControl(CRect rcClient)
{
	const int dCXBox  = 2;	 // delta adjustment
	const int dCYBox  = 118; 
	const int dCYPage = 30;	

	CRect rcPage; // page dialog
	GetClientRect( rcPage );
	SetWindowPos( NULL, 0, 0, rcPage.Width(), rcClient.Height()-dCYPage, SWP_NOMOVE | SWP_NOZORDER );

	CRect rcVSBar; // scroll bar control on page dialog
	CScrollBar* pVSBar = (CScrollBar*)GetDlgItem(IDC_VSB_PGBOX);
	if( pVSBar == NULL )
		return( (LRESULT)1 ); // error
	pVSBar->GetClientRect( rcVSBar );
	pVSBar->SetWindowPos( NULL, 0, 0, rcVSBar.Width(), rcClient.Height()-dCYBox, SWP_NOMOVE | SWP_NOZORDER );

	CRect rcStcBox; // list control on page dialog
	CStatic* pStcBox = (CStatic*)GetDlgItem(IDC_LIST_BOX);
	if( pStcBox == NULL )
		return( (LRESULT)1 ); // error
	pStcBox->GetClientRect( rcStcBox );
	pStcBox->SetWindowPos( NULL, 0, 0, rcPage.Width() - rcVSBar.Width() - dCXBox, rcClient.Height() - dCYBox,
							SWP_NOMOVE |  SWP_NOZORDER );

	return( 0 );
}//end of CDlgPage::ReSizeControl(CRect rcClient)
//////////////////////////////////////////////////////////////////////////////////////////
VOID CDlgPage::DoSetScrollPos()
{
	TRACE0( "DlgPage.cpp : CDlgPage::DoSetScrollPos()" );
	m_vsbList.SetScrollPos( (DWORD)(CGS_BinGetScroll(UIBIN_PAGE) * BOTTOM_RANGE), 1 );
}//end of CDlgPage::DoSetScrollPos()
