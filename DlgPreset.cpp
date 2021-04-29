/* COPYRIGHT NOTICE:
********************************************************
*  Copyright (c) 2000 InnoVision Technology, Inc.      *
*  All rights reserved.                                *
*  PROPRIETARY AND CONFIDENTIAL                        *
*  DO NOT DISTRIBUTE                                   *
********************************************************
*/
// DlgPreset.cpp : implementation file
//

#include "stdafx.h"
#include "cgUI.h"
#include "DlgPreset.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

#define		VMIN_POS		0
#define		VMAX_POS		1000 // decide the value later
#define		HEIGHT_PICON	100  // decide the actual value later

/////////////////////////////////////////////////////////////////////////////
// CDlgPreset dialog


CDlgPreset::CDlgPreset(CWnd* pParent /*=NULL*/) : CDialog(CDlgPreset::IDD, pParent)
{
	//{{AFX_DATA_INIT(CDlgPreset)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT

	m_VSPos = 0; // initial vert scroll Position ??
}// end of constructor


void CDlgPreset::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDlgPreset)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CDlgPreset, CDialog)
	//{{AFX_MSG_MAP(CDlgPreset)
	ON_WM_VSCROLL()
	ON_WM_LBUTTONDOWN()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDlgPreset message handlers
/////////////////////////////////////////////////////////////////////////////
BOOL CDlgPreset::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// Start adding extra initialization here
	SCROLLINFO	si;
	si.fMask	= SIF_PAGE | SIF_RANGE | SIF_POS;
	si.nMin		= VMIN_POS;
	si.nMax		= VMAX_POS; // 1000 ??
	si.nPos		= m_VSPos;
	si.nPage	= HEIGHT_PICON; // should = height of picon

	SetScrollInfo( SB_VERT, &si, 1 );

	// End adding extra initialization
	
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}//end of CDlgPreset::OnInitDialog
/////////////////////////////////////////////////////////////////////////////
void CDlgPreset::OnVScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar) 
{
	// Start adding your message handler code here and/or call default
	switch( nSBCode )
	{
	case SB_TOP: // Scroll to top. 
		m_VSPos = VMIN_POS;
		TRACE1( "DlgPreset.cpp : OnVScroll - Scroll to Top - %d\n", nPos );
		break;
	case SB_BOTTOM: // Scroll to Bottom
		m_VSPos = VMAX_POS;
		TRACE1( "DlgPreset.cpp : OnVScroll - Scroll to Bottom - %d\n", nPos );
		break;
	case SB_LINEDOWN: // Scroll one line down
		m_VSPos += HEIGHT_PICON;
		m_VSPos = min( m_VSPos, VMAX_POS );
		TRACE1( "DlgPreset.cpp : OnVScroll - Scroll one line down - %d\n", nPos );
		break;
	case SB_LINEUP: // Scroll one line up.
		m_VSPos -= HEIGHT_PICON;
		m_VSPos = max( VMIN_POS, m_VSPos );
		TRACE1( "DlgPreset.cpp : OnVScroll - Scroll one line up - %d\n", nPos );
		break;
	case SB_PAGEDOWN: // Scroll one page down.
		m_VSPos += HEIGHT_PICON;
		m_VSPos = min( m_VSPos, VMAX_POS );
		TRACE1( "DlgPreset.cpp : OnVScroll - Scroll one page down - %d\n", nPos );
		break;
	case SB_PAGEUP: // Scroll one page up.
		m_VSPos -= HEIGHT_PICON;
		m_VSPos = max( VMIN_POS, m_VSPos );
		TRACE1( "DlgPreset.cpp : OnVScroll - Scroll one page up - %d\n", nPos );
		break;
	case SB_THUMBPOSITION:	// Scroll to the absolute position. 
							// The current position is provided in nPos.
		m_VSPos = nPos;
		TRACE1( "DlgPreset.cpp : OnVScroll - Scroll to the absolute position - %d\n", nPos );
		break;
	case SB_THUMBTRACK: // Drag scroll box to specified position. 
						// The current position is provided in nPos.
		m_VSPos = nPos;
		TRACE1( "DlgPreset.cpp : OnVScroll - Drag scroll box to specified position - %d\n", nPos );
		break;
	case SB_ENDSCROLL: // End scroll
		TRACE2( "DlgPreset.cpp : OnVScroll - End scroll - nPos = %d, m_VSPos = %d\n", nPos, m_VSPos );
		break;
	}//end of switch - nSBCode

	SetScrollPos( SB_VERT, m_VSPos, 1 );

	// End adding your message handler code here and/or call default
	CDialog::OnVScroll(nSBCode, nPos, pScrollBar);
}//end of CDlgPreset::OnVScroll
/////////////////////////////////////////////////////////////////////////////
void CDlgPreset::OnLButtonDown(UINT nFlags, CPoint point) 
{
	// Start add your message handler code here and/or call default
	switch( nFlags )
	{
	case MK_CONTROL: // CTRL key is down.
		break;
	case MK_RBUTTON: // right mouse button is down.
		break;
	case MK_SHIFT:   // SHIFT key is down. 
		break;
	}//end of switch - nFilags

	TRACE3( "DlgPreset.cpp : OnLButtonDown - button %d, x %d, y %d\n", nFlags, point.x, point.y );
	// End add your message handler code here and/or call default
	
	CDialog::OnLButtonDown(nFlags, point);
}//end of CDlgPreset::OnLButtonDown
