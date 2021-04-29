/* COPYRIGHT NOTICE:
********************************************************
*  Copyright (c) 2000 InnoVision Technology, Inc.      *
*  All rights reserved.                                *
*  PROPRIETARY AND CONFIDENTIAL                        *
*  DO NOT DISTRIBUTE                                   *
********************************************************
*/
// ChildFrm.cpp : implementation of the CChildFrame class
//

#include "stdafx.h"
#include "cgUI.h"
#include "ChildFrm.h"
#include "DlgPage.h"
#include "ACGS_Inc\\CGServerDll.h"
#include "Global.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

#define		CX_CHILD_WND	0x146
#define		CY_CHILD_WND	0xF6

extern		CChildFrame*	g_ChildFrame;
extern		CURSOR_HANDLE	g_hCursor;
/////////////////////////////////////////////////////////////////////////////
// CChildFrame

IMPLEMENT_DYNCREATE(CChildFrame, CMDIChildWnd)

BEGIN_MESSAGE_MAP(CChildFrame, CMDIChildWnd)
	//{{AFX_MSG_MAP(CChildFrame)
	ON_COMMAND(ID_PAGE_TYPE_CRAWL, OnPageTypeCrawl)
	ON_COMMAND(ID_PAGE_TYPE_ROLL, OnPageTypeRoll)
	ON_COMMAND(ID_PAGE_TYPE_STILL, OnPageTypeStill)
	ON_UPDATE_COMMAND_UI(ID_PAGE_TYPE_CRAWL, OnUpdatePageTypeCrawl)
	ON_UPDATE_COMMAND_UI(ID_PAGE_TYPE_ROLL, OnUpdatePageTypeRoll)
	ON_UPDATE_COMMAND_UI(ID_PAGE_TYPE_STILL, OnUpdatePageTypeStill)
	ON_WM_SHOWWINDOW()
	ON_WM_VSCROLL()
	ON_WM_HSCROLL()
	ON_WM_CREATE()
	ON_WM_SIZE()
	//}}AFX_MSG_MAP
	ON_WM_SYSCOMMAND()
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CChildFrame construction/destruction

CChildFrame::CChildFrame()
{	
	TRACE0( "CChildFrame - Constructor\n" );
	m_bStill = 1;	// default check mark on the menu
	m_bRoll  = 0;	// default uncheck
	m_bCrawl = 0;   // default uncheck

}//end of constructor

CChildFrame::~CChildFrame()
{
}//end of destructor

////////////////////////////////////////////////////////////////////////////
// Change the child window attribute here
BOOL CChildFrame::PreCreateWindow(CREATESTRUCT& cs)
{
	TRACE0( "ChildFrm.cpp : CChildFrame - PreCreateWindow \n" );

	cs.style	 |= WS_HSCROLL | WS_VSCROLL;
	cs.style	 &= ~(WS_CAPTION | WS_MINIMIZEBOX | WS_MAXIMIZEBOX | WS_THICKFRAME );
	cs.dwExStyle |= WS_EX_DLGMODALFRAME;
	
// End Modify the Window class or styles here by modifying the CREATESTRUCT cs
	if( !CMDIChildWnd::PreCreateWindow(cs) )
		return FALSE;

	return TRUE;
}//end of CChildFrame::PreCreateWindow



/////////////////////////////////////////////////////////////////////////////
// CChildFrame diagnostics

#ifdef _DEBUG
void CChildFrame::AssertValid() const
{
	CMDIChildWnd::AssertValid();
}

void CChildFrame::Dump(CDumpContext& dc) const
{
	CMDIChildWnd::Dump(dc);
}

#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CChildFrame message handlers
/////////////////////////////////////////////////////////////////////////////
// m_bCrawl, m_bRoll & m_bStill are exclusive to each other
void CChildFrame::OnPageTypeCrawl() 
{
	TRACE0( "ChildFrm.cpp : CChildFrame::OnPageTypeCrawl\n" );
	m_bCrawl = 1;
	m_bRoll  = 0;
	m_bStill = 0;
	ShowScrollBar( SB_VERT, 0 );
	ShowScrollBar( SB_HORZ, 1 );

	CGS_SetValDbl( PAGE_TYPE, CGS_CRAWL_PAGE_TYPE );
}//end of CChildFrame::OnPageTypeCrawl
/////////////////////////////////////////////////////////////////////////////
void CChildFrame::OnPageTypeRoll() 
{
	TRACE0( "ChildFrm.cpp : CChildFrame::OnPageTypeRoll\n" );
	m_bCrawl = 0;
	m_bRoll  = 1;
	m_bStill = 0;
	ShowScrollBar( SB_VERT, 1 );
	ShowScrollBar( SB_HORZ, 0 );

	CGS_SetValDbl( PAGE_TYPE, CGS_ROLL_PAGE_TYPE );
}//end of CChildFrame::OnPageTypeRoll
/////////////////////////////////////////////////////////////////////////////
void CChildFrame::OnPageTypeStill() 
{
	TRACE0( "ChildFrm.cpp : CChildFrame::OnPageTypeStill\n" );
	m_bCrawl = 0;
	m_bRoll  = 0;
	m_bStill = 1;
	ShowScrollBar( SB_HORZ, 0 );
	ShowScrollBar( SB_VERT, 0 );

	CGS_SetValDbl( PAGE_TYPE, CGS_STILL_PAGE_TYPE );
}//end of CChildFrame::OnPageTypeStill
/////////////////////////////////////////////////////////////////////////////
void CChildFrame::OnUpdatePageTypeCrawl(CCmdUI* pCmdUI) 
{
	TRACE0( "ChildFrm.cpp : CChildFrame::OnUpdatePageTypeCrawl\n" );
	pCmdUI->SetCheck( m_bCrawl );	

	// read all scroll variables from somewhere and then initialize it
	SCROLLINFO	si;
	si.fMask	= SIF_PAGE | SIF_RANGE | SIF_POS;
	si.nMin		= 0;	// min - load from outside function
	si.nMax		= 1000; // max - 1000 ?? load from outside function
	si.nPos		= m_hsPos = 10; // cur pos - 10 ?? load from outside function
	si.nPage	= 100;  // 100?? load from outside function

	SetScrollInfo( SB_HORZ, &si, 1 );

}//end of CChildFrame::OnUpdatePageTypeCrawl
/////////////////////////////////////////////////////////////////////////////
void CChildFrame::OnUpdatePageTypeRoll(CCmdUI* pCmdUI) 
{
	TRACE0( "ChildFrm.cpp : CChildFrame::OnUpdatePageTypeRoll\n" );
	pCmdUI->SetCheck( m_bRoll );

	// read all scroll variables from somewhere and then initialize it
	SCROLLINFO	si;
	si.fMask	= SIF_PAGE | SIF_RANGE | SIF_POS;
	si.nMin		= 0;	// min - load from outside function
	si.nMax		= 1000; // max - 1000 ?? load from outside function
	si.nPos		= m_vsPos = 10; // cur pos - 10 ?? load from outside function
	si.nPage	= 100;  // 100?? load from outside function

	SetScrollInfo( SB_VERT, &si, 1 );	

}//end of CChildFrame::OnUpdatePageTypeRoll
/////////////////////////////////////////////////////////////////////////////
void CChildFrame::OnUpdatePageTypeStill(CCmdUI* pCmdUI) 
{
	TRACE0( "ChildFrm.cpp : CChildFrame::OnUpdatePageTypeStill\n" );
	pCmdUI->SetCheck( m_bStill );
}//end of CChildFrame::OnUpdatePageTypeStill
/////////////////////////////////////////////////////////////////////////////
void CChildFrame::OnShowWindow(BOOL bShow, UINT nStatus) 
{
	CMDIChildWnd::OnShowWindow(bShow, nStatus);
	
	// TODO: Add your message handler code here
//	ShowWindow( SW_SHOWMAXIMIZED );
	ShowScrollBar( SB_HORZ, 0 );
	ShowScrollBar( SB_VERT, 0 );

	CRect rcClient;
	::GetClientRect( GetMDIFrame()->m_hWndMDIClient, rcClient );

	TRACE1( "ChildFrm.cpp : CChildFrame::OnShowWindow - bShow %d\n", bShow );
	//TRACE2( "\tCChildFrame::OnShowWindow - cx = %d, cy = %d\n", rcClient.Width, rcClient.Height );
}//end of CChildFrame::OnShowWindow

/////////////////////////////////////////////////////////////////////////////
// This section implement in Jim's way but not the standard Event driven.
// End user may not able to set the scroll position.
void CChildFrame::OnVScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar) 
{
	TRACE2( "ChildFrm.cpp : CChildFrame::OnVScroll nSBCode = %d, nPos = %d\n",nSBCode, nPos );
	switch( nSBCode )
	{
	case SB_TOP: // Scroll to top. 
		m_vsPos = 0; // defined from outside function/variable
		TRACE1( "DlgPreset.cpp : OnVScroll - Scroll to Top - %d\n", nPos );
		break;
	case SB_BOTTOM: // Scroll to Bottom
		m_vsPos = 1000; // defined from outside function/variable
		TRACE1( "DlgPreset.cpp : OnVScroll - Scroll to Bottom - %d\n", nPos );
		break;
	case SB_LINEDOWN: // Scroll one line down
		m_vsPos += 10; // defined from outside function/variable
		m_vsPos = min( m_vsPos, 1000 ); // 1000 - max value
		TRACE1( "DlgPreset.cpp : OnVScroll - Scroll one line down - %d\n", nPos );

		CGS_DocScrollNextLine( 1 );
		break;
	case SB_LINEUP: // Scroll one line up.
		m_vsPos -= 10; // defined from outside function/variable
		m_vsPos = max( 0, m_vsPos ); // 0 - min value
		TRACE1( "DlgPreset.cpp : OnVScroll - Scroll one line up - %d\n", nPos );

		CGS_DocScrollPrevLine( 1 );
		break;
	case SB_PAGEDOWN: // Scroll one page down.
		m_vsPos += 100; // defined from outside function/variable
		m_vsPos = min( m_vsPos, 1000 ); // 1000 - max value
		TRACE1( "DlgPreset.cpp : OnVScroll - Scroll one page down - %d\n", nPos );

		CGS_DocScrollNextPage( 1 );
		break;
	case SB_PAGEUP: // Scroll one page up.
		m_vsPos -= 100; // defined from outside function/variable
		m_vsPos = max( 0, m_vsPos ); // 0 - min value
		TRACE1( "DlgPreset.cpp : OnVScroll - Scroll one page up - %d\n", nPos );

		CGS_DocScrollPrevPage( 1 );
		break;
	case SB_THUMBPOSITION:	// Scroll to the absolute position. 
							// The current position is provided in nPos.
		m_vsPos = nPos;
		TRACE1( "DlgPreset.cpp : OnVScroll - Scroll to the absolute position - %d\n", nPos );
		break;
	case SB_THUMBTRACK: // Drag scroll box to specified position. 
						// The current position is provided in nPos.
		m_vsPos = nPos;
		TRACE1( "DlgPreset.cpp : OnVScroll - Drag scroll box to specified position - %d\n", nPos );
		break;
//	case IX_THUMBTRACK:
		// TO DO : Custom update
		// 
//		break;
	case SB_ENDSCROLL: // End scroll
		TRACE2( "DlgPreset.cpp : OnVScroll - End scroll - nPos = %d, m_vsPos = %d\n", nPos, m_vsPos );
		break;	
	}//end of switch - nSBCode

	SetScrollPos( SB_VERT, m_vsPos, 1 );

	CGS_SetDocVScrollPos( (float)(m_vsPos/1000.0) );
	// End adding your message handler code here and/or call default
	CMDIChildWnd::OnVScroll(nSBCode, nPos, pScrollBar);
}//end of CChildFrame::OnVScroll
////////////////////////////////////////////////////////////////////////////////////////
void CChildFrame::OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar) 
{
	// TODO: Add your message handler code here and/or call default
	TRACE0( "ChildFrm.cpp : CChildFrame::OnHScroll\n" );
	switch( nSBCode )
	{
	case SB_TOP: // Scroll to top. 
		m_hsPos = 0; // defined from outside function/variable
		TRACE1( "DlgPreset.cpp : OnVScroll - Scroll to Top - %d\n", nPos );
		break;
	case SB_BOTTOM: // Scroll to Bottom
		m_hsPos = 1000; // defined from outside function/variable
		TRACE1( "DlgPreset.cpp : OnVScroll - Scroll to Bottom - %d\n", nPos );
		break;
	case SB_LINEDOWN: // Scroll one line down
		m_hsPos += 10; // defined from outside function/variable
		m_hsPos = min( m_hsPos, 1000 ); // 1000 - max value
		TRACE1( "DlgPreset.cpp : OnVScroll - Scroll one line down - %d\n", nPos );

		CGS_DocScrollNextLine( 0 );
		break;
	case SB_LINEUP: // Scroll one line up.
		m_hsPos -= 10; // defined from outside function/variable
		m_hsPos = max( 0, m_hsPos ); // 0 - min value
		TRACE1( "DlgPreset.cpp : OnVScroll - Scroll one line up - %d\n", nPos );

		CGS_DocScrollPrevLine( 0 );
		break;
	case SB_PAGEDOWN: // Scroll one page down.
		m_hsPos += 100; // defined from outside function/variable
		m_hsPos = min( m_hsPos, 1000 ); // 1000 - max value
		TRACE1( "DlgPreset.cpp : OnVScroll - Scroll one page down - %d\n", nPos );

		CGS_DocScrollNextPage( 0 );
		break;
	case SB_PAGEUP: // Scroll one page up.
		m_hsPos -= 100; // defined from outside function/variable
		m_hsPos = max( 0, m_hsPos ); // 0 - min value
		TRACE1( "DlgPreset.cpp : OnVScroll - Scroll one page up - %d\n", nPos );

		CGS_DocScrollPrevLine( 0 );
		break;
	case SB_THUMBPOSITION:	// Scroll to the absolute position. 
							// The current position is provided in nPos.		
		m_hsPos = nPos; // get from core
		TRACE1( "DlgPreset.cpp : OnVScroll - Scroll to the absolute position - %d\n", nPos );
		break;
	case SB_THUMBTRACK: // Drag scroll box to specified position. 
						// The current position is provided in nPos.
		m_hsPos = nPos;
		TRACE1( "DlgPreset.cpp : OnVScroll - Drag scroll box to specified position - %d\n", nPos );
		break;
	case SB_ENDSCROLL: // End scroll
		TRACE2( "DlgPreset.cpp : OnVScroll - End scroll - nPos = %d, m_hsPos = %d\n", nPos, m_hsPos );
		break;
	}//end of switch - nSBCode

	SetScrollPos( SB_HORZ, m_hsPos, 1 );

	CGS_SetDocHScrollPos( (float)m_hsPos/1000 );

	// End adding your message handler code here and/or call default
	CMDIChildWnd::OnHScroll(nSBCode, nPos, pScrollBar);
}//end of CChildFrame::OnHScroll
////////////////////////////////////////////////////////////////////////////////////////
// This function diable the close and restore button when the child window is not
// maximize. If the child window is maximize, it disable the close and restore button.
// However, a user can still close the child frame window by clicking close button. 
int CChildFrame::OnCreate(LPCREATESTRUCT lpCreateStruct) 
{
	g_ChildFrame = this;

	TRACE0( "ChildFrm.cpp : CChildFrame::OnCreate\n" );
	if (CMDIChildWnd::OnCreate(lpCreateStruct) == -1)
		return -1;
	
	// TODO: Add your specialized creation code here
	CMenu *pSysMenu = GetSystemMenu(FALSE); 
	ASSERT(pSysMenu != NULL);

	// remove/disable close button and restore button
	VERIFY(pSysMenu->RemoveMenu(SC_CLOSE, MF_BYCOMMAND));
	VERIFY(pSysMenu->RemoveMenu(SC_RESTORE, MF_BYCOMMAND));
	
	return 0;
}//end of CChildFrame::OnCreate
////////////////////////////////////////////////////////////////////////////////////////
/***
void CChildFrame::OnSysCommand(UINT nID, LPARAM lParam)
{
	TRACE0( "ChildFrm.cpp : CChildFrame::OnSysCommand\n" );
	switch( nID )
	{
	case SC_CLOSE:	// by pass the close button message
		return;
	case SC_RESTORE:// by pass the restore button message 
		return;
	}//end of switch

    CMDIChildWnd::OnSysCommand(nID, lParam);
}//end of CChildFrame::OnSysCommand
***/
////////////////////////////////////////////////////////////////////////////////////////
void CChildFrame::OnSize(UINT nType, int cx, int cy) 
{
	CMDIChildWnd::OnSize(nType, cx, cy);
	
	// TODO: Add your message handler code here
	TRACE3("ChildFrm.cpp : OnSize - nType = %d, cx = %d, cy = %d\n", nType, cx, cy );
	CRect rcClient;
    GetClientRect(rcClient);   
	TRACE2("\tcx = %d, cy = %d\n", rcClient.right-rcClient.left, rcClient.bottom-rcClient.top );
	
}//end of CChildFrame::OnSize
////////////////////////////////////////////////////////////////////////////////////////
VOID CChildFrame::SetVertPos(double vPos)
{
	m_vsPos = (INT)vPos;
}//end of CChildFrame::SetVertPos
////////////////////////////////////////////////////////////////////////////////////////
VOID CChildFrame::SetHorzPos(double hPos)
{
	m_hsPos = (INT)hPos;
}//end of CChildFrame::SetHorzPos


