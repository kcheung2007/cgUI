/* COPYRIGHT NOTICE:
********************************************************
*  Copyright (c) 2000 InnoVision Technology, Inc.      *
*  All rights reserved.                                *
*  PROPRIETARY AND CONFIDENTIAL                        *
*  DO NOT DISTRIBUTE                                   *
********************************************************
*/
// DlgBarTxt.cpp : implementation file
//

#include "stdafx.h"
#include "cgUI.h"
#include "DlgAttrib.h"
#include "DlgBarTopBin.h"
//#include "Global.h"
#include "ACGS_Inc\\UI_BinMgr.h" //in ACGS_Inc folder


#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDlgBarBinTop dialog

#define		WM_INITDLGBAR_TXT		WM_USER + WM_USER_TXT

extern	DWORD	g_dwAttrib;
extern	DWORD	g_dwTab;

BEGIN_MESSAGE_MAP(CDlgBarBinTop, CDialogBar)
	//{{AFX_MSG_MAP(CDlgBarBinTop)
	ON_WM_CREATE()
	ON_MESSAGE( WM_INITDLGBAR_TXT, InitDialogBarHandler )
	ON_WM_VSCROLL()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

//////////////////////////////////////////////////////////////////////////////
CDlgBarBinTop::CDlgBarBinTop()
{
}//end of constructor

CDlgBarBinTop::~CDlgBarBinTop()
{
}//end of destructor

//////////////////////////////////////////////////////////////////////////////
void CDlgBarBinTop::DoDataExchange(CDataExchange* pDX)
{
	// TODO: Add your specialized code here and/or call the base class
	CDialogBar::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_VSB_TOPBIN, m_vsbTop);
	DDX_Control(pDX, IDC_VSB_BOTBIN, m_vsbBot);
}//end of CDlgBarBinTop::DoDataExchange

/////////////////////////////////////////////////////////////////////////////
// CDlgBarBinTop message handlers
/////////////////////////////////////////////////////////////////////////////
BOOL CDlgBarBinTop::OnInitDialogBar() 
{
	TRACE0( "DlgBarTopBin.cpp : CDlgBarBinTop::OnInitDialogBar()\n");
	m_ctlTopBin.SubclassDlgItem( IDC_LIST_TOP_BIN, this );
	m_ctlBotBin.SubclassDlgItem( IDC_LIST_BOT_BIN, this );

	m_vsbTop.SetScrollRange( 1, 1000 );	// default range
	m_vsbTop.SetScrollPos( 1 );			// default position

	m_vsbBot.SetScrollRange( 1, 1000 );	// default range
	m_vsbBot.SetScrollPos( 1 );			// default position
TRACE0("++++++++++++ BIn Open +++++++++++++++++++++++\n");

	//Core creates a bin object so UI can have abstracted method 
	//for display, access and control of project's color palette data
	CGS_BinOpen(	UIBIN_PALETTE,
					m_ctlBotBin.m_hWnd,
					NULL,
					IXReg_RedrawPaletteThumbTrack //01-04-13 i.e. UI_RedrawPageBinThumbTrack function for core to call to tell UI to redraw thumb track position e.g. void UI_RedrawPageBinThumbTrack(double ScrollPos_01);
				);

	CGS_BinOpen(	UIBIN_FONT_PRESET,
					m_ctlTopBin.m_hWnd,
					NULL,
					IXReg_RedrawFontPresetThumbTrack //01-04-13 i.e. UI_RedrawPageBinThumbTrack function for core to call to tell UI to redraw thumb track position e.g. void UI_RedrawPageBinThumbTrack(double ScrollPos_01);
				);

	return( 1 );
}//end of CDlgBarBinTop::OnInitDialogBar
/////////////////////////////////////////////////////////////////////////////
int CDlgBarBinTop::OnCreate(LPCREATESTRUCT lpCreateStruct) 
{
	if (CDialogBar::OnCreate(lpCreateStruct) == -1)
		return -1;
	
	// TODO: Add your specialized creation code here
	// Post WM_INITDIALOGBAR message here to dialog bar
	PostMessage(WM_INITDLGBAR_TXT , 0 , 0 );
	
	return 0;
}//end of CDlgBarBinTop::OnCreate
///////////////////////////////////////////////////////////////////////////////////
LRESULT CDlgBarBinTop::InitDialogBarHandler(WPARAM wParam, LPARAM lParam)
{
	UpdateData(FALSE);
	OnInitDialogBar();

    return( 0 );
}//end of CDlgBarBot::InitDialogBarHandler
/////////////////////////////////////////////////////////////////////////////
// Vertical Scroll bar of top bin - font preset
VOID CDlgBarBinTop::VTopBinScroll(UINT nSBCode, UINT nPos, CScrollBar *pScrollBar)
{		
	int nCurPos = pScrollBar->GetScrollPos();

	switch( nSBCode )
	{
	case SB_TOP:			// Scroll to far top.
		nCurPos = 1;
		break;
	case SB_LINEUP:			// Scroll one line up.
		CGS_BinScrollLineUp( UIBIN_FONT_PRESET );
		nCurPos = (int)(CGS_BinGetScroll( UIBIN_FONT_PRESET ) * 1000.0);
		break;
	case SB_LINEDOWN:		// Scroll one line down.
		CGS_BinScrollLineDown( UIBIN_FONT_PRESET );
		nCurPos = (int)(CGS_BinGetScroll( UIBIN_FONT_PRESET ) * 1000.0);
		break;
	case SB_PAGEUP:			// Scroll one page up.
		CGS_BinScrollPageUp( UIBIN_FONT_PRESET );
		nCurPos = (int)(CGS_BinGetScroll( UIBIN_FONT_PRESET ) * 1000.0);
		break;
	case SB_PAGEDOWN:		// Scroll one page down.
		CGS_BinScrollPageDown( UIBIN_FONT_PRESET );
		nCurPos = (int)(CGS_BinGetScroll( UIBIN_FONT_PRESET ) * 1000.0);
		break;
	case SB_BOTTOM:			// Scroll to far bottom.
		nCurPos = 1000;
		break;
	case SB_THUMBPOSITION:	// Scroll to absolute position. 
	case SB_THUMBTRACK:		// Drag scroll box to specified position. 
		nCurPos = nPos;
		break;
	case SB_ENDSCROLL:		// End scroll
		TRACE0( "DlgBarTopBin.cpp : OnVScroll - End scroll\n" );
		break;
	}//end of switch - nSBCode//JRS ADD

	nCurPos = ( nCurPos < 1 ) ? 1 : nCurPos;
	nCurPos = ( 1000 < nCurPos ) ? 1000 : nCurPos;
	pScrollBar->SetScrollPos(nCurPos);

	CGS_BinSetScroll( UIBIN_FONT_PRESET,(double)((double)nCurPos)/(1000.0f) );//JRS 00-04-09
}// end of CDlgBarBinTop::VTopBinScroll
///////////////////////////////////////////////////////////////////////////////////
// Vertical Scroll bar of bottom bin - palette
VOID CDlgBarBinTop::VBotBinScroll(UINT nSBCode, UINT nPos, CScrollBar *pScrollBar)
{
	int nCurPos = pScrollBar->GetScrollPos();

	switch( nSBCode )
	{
	case SB_TOP:			// Scroll to far top.
		nCurPos = 1;
		break;
	case SB_LINEUP:			// Scroll one line up.
		CGS_BinScrollLineUp( UIBIN_PALETTE );
		nCurPos = (int)(CGS_BinGetScroll( UIBIN_PALETTE ) * 1000.0);
		break;
	case SB_LINEDOWN:		// Scroll one line down.
		CGS_BinScrollLineDown( UIBIN_PALETTE );
		nCurPos = (int)(CGS_BinGetScroll( UIBIN_PALETTE ) * 1000.0);
		break;
	case SB_PAGEUP:			// Scroll one page up.
		CGS_BinScrollPageUp( UIBIN_PALETTE );
		nCurPos = (int)(CGS_BinGetScroll( UIBIN_PALETTE ) * 1000.0);
		break;
	case SB_PAGEDOWN:		// Scroll one page down.
		CGS_BinScrollPageDown( UIBIN_PALETTE );
		nCurPos = (int)(CGS_BinGetScroll( UIBIN_PALETTE ) * 1000.0);
		break;
	case SB_BOTTOM:			// Scroll to far bottom.
		nCurPos = 1000;
		break;
	case SB_THUMBPOSITION:	// Scroll to absolute position. 
	case SB_THUMBTRACK:		// Drag scroll box to specified position. 
		nCurPos = nPos;
		break;
	case SB_ENDSCROLL:		// End scroll
		TRACE0( "DlgBarTopBin.cpp : OnVScroll - End scroll\n" );
		break;
	}//end of switch - nSBCode//JRS ADD
		

	nCurPos = ( nCurPos < 1 ) ? 1 : nCurPos;
	nCurPos = ( 1000 < nCurPos ) ? 1000 : nCurPos;
	pScrollBar->SetScrollPos(nCurPos);

	CGS_BinSetScroll( UIBIN_PALETTE,(double)((double)nCurPos)/(1000.0f) );

}//end of CDlgBarBinTop::VBotBinScroll
///////////////////////////////////////////////////////////////////////////////////
void CDlgBarBinTop::OnVScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar) 
{
	ASSERT(pScrollBar != NULL);
	int nCurPos = pScrollBar->GetScrollPos();

	if( pScrollBar == (CScrollBar*)GetDlgItem(IDC_VSB_TOPBIN) )
		VTopBinScroll( nSBCode, nPos, pScrollBar);
	
	if( pScrollBar == (CScrollBar*)GetDlgItem(IDC_VSB_BOTBIN) )
		VBotBinScroll( nSBCode, nPos, pScrollBar);

	CDialogBar::OnVScroll(nSBCode, nPos, pScrollBar);
}//end of CDlgBarBinTop::OnVScroll
///////////////////////////////////////////////////////////////////////////////////
VOID CDlgBarBinTop::DoSetTopScrollPos()
{
	TRACE0( "DlgBarTopBin.cpp : CDlgBarBinTop::DoSetTopScrollPos()" );
	m_vsbTop.SetScrollPos( (DWORD)(CGS_BinGetScroll(UIBIN_PALETTE) * 1000), 1 );
}// end of CDlgBarBinTop::DoSetTopScrollPos()
///////////////////////////////////////////////////////////////////////////////////
VOID CDlgBarBinTop::DoSetBotScrollPos()
{
	TRACE0( "DlgBarTopBin.cpp : CDlgBarBinTop::DoSetBotScrollPos()" );
	m_vsbBot.SetScrollPos( (DWORD)(CGS_BinGetScroll(UIBIN_PALETTE) * 1000), 1 );
}// end of CDlgBarBinTop::DoSetBotScrollPos()


/////////////////////////////////////////////////////////////////////////////
// CImgTopBin
/////////////////////////////////////////////////////////////////////////////
CImgTopBin::CImgTopBin()
{
}

CImgTopBin::~CImgTopBin()
{
}


BEGIN_MESSAGE_MAP(CImgTopBin, CEdit)
	//{{AFX_MSG_MAP(CImgTopBin)
	ON_WM_LBUTTONDOWN()
	ON_WM_PAINT()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CImgTopBin message handlers
/////////////////////////////////////////////////////////////////////////////
void CImgTopBin::OnLButtonDown(UINT nFlags, CPoint pt) 
{
	// TODO: Add your message handler code here and/or call default
	TRACE2("DlgBarTopBin.cpp : CImgTopBin::OnLButtonDown x = %d, y = %d\n", pt.x, pt.y );
/*
	CGS_BinSelect( UIBIN_FONT_PRESET, 
	0,
	//g_dwAttrib, 
	pt.x, pt.y ); //JRS 00-04-09
*/
  
	CEdit::OnLButtonDown(nFlags, pt);

	// TO DO : Jimmy

	AfxGetMainWnd()->SetFocus();
}//end of CImgTopBin::OnLButtonDown


/////////////////////////////////////////////////////////////////////////////
// CImgBotBin
CImgBotBin::CImgBotBin()
{
	TRACE0("DlgBarTopBin.cpp : CImgBotBin - Constructor\n");
}

CImgBotBin::~CImgBotBin()
{
}


BEGIN_MESSAGE_MAP(CImgBotBin, CEdit)
	//{{AFX_MSG_MAP(CImgBotBin)
	ON_WM_LBUTTONDOWN()
	ON_WM_PAINT()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CImgBotBin message handlers
void CImgBotBin::OnLButtonDown(UINT nFlags, CPoint pt) 
{	
	TRACE2("DlgBarTopBin.cpp : CImgBotBin::OnLButtonDown x = %d, y = %d\n", pt.x, pt.y );
	
//	CGS_BinSelect( UIBIN_PALETTE, ABMC_FACE_COLOR, pt.x, pt.y );
//	CGS_BinSelect( UIBIN_PALETTE, ABMC_OUTLINE1_COLOR, pt.x, pt.y );
//	CGS_BinSelect( UIBIN_PALETTE, ABMC_OUTLINE2_COLOR, pt.x, pt.y );
//	CGS_BinSelect( UIBIN_PALETTE, ABMC_SHADOW1_COLOR, pt.x, pt.y );

	CGS_BinSelect( UIBIN_PALETTE, g_dwAttrib, pt.x, pt.y );

	switch( g_dwAttrib ) // reset the attrib from Alpha box to Color Box
	{
	case ABMC_FACE_ALPHA:
		g_dwAttrib = ABMC_FACE_COLOR;
		break;
	case ABMC_OUTLINE1_ALPHA:
		g_dwAttrib = ABMC_OUTLINE1_COLOR;
		break;
	case ABMC_OUTLINE2_ALPHA:
		g_dwAttrib = ABMC_OUTLINE2_COLOR;
		break;
	case ABMC_SHADOW1_ALPHA:
		g_dwAttrib = ABMC_SHADOW1_COLOR;
		break;
	}//end of switch

	TRACE1("DlgBarTopBin.cpp : CImgBotBin::OnLButtonDown g_dwAttrib = %d\n", g_dwAttrib );

	CEdit::OnLButtonDown(nFlags, pt);
	AfxGetMainWnd()->SetFocus();
}//end of CImgBotBin::OnLButtonDown
/////////////////////////////////////////////////////////////////////////////
void CImgBotBin::OnPaint() 
{
	CPaintDC dc(this); // device context for painting
		
	//JRS ADD
	CGS_BinRefresh(UIBIN_PALETTE);
	
	// Do not call CEdit::OnPaint() for painting messages
}//end of CImgBotBin::OnPaint()
/////////////////////////////////////////////////////////////////////////////
void CImgTopBin::OnPaint() 
{
	CPaintDC dc(this); // device context for painting
	
	//JRS ADD
	CGS_BinRefresh(UIBIN_FONT_PRESET);
	
	// Do not call CEdit::OnPaint() for painting messages
}//end of CImgTopBin::OnPaint()