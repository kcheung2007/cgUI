/* COPYRIGHT NOTICE:
********************************************************
*  Copyright (c) 2000 InnoVision Technology, Inc.      *
*  All rights reserved.                                *
*  PROPRIETARY AND CONFIDENTIAL                        *
*  DO NOT DISTRIBUTE                                   *
********************************************************
*/
// PalSliderCtrl.cpp : implementation file
//

#include "stdafx.h"
#include "cgui.h"
#include "PalDlg.h"
#include "PalSliderCtrl.h"
#include "ACGS_Inc\\UI_BinMgr.h" //JRS 00-03-08


//BEGIN JRS NEW -----------------------------------------------
#include "ACGS_Inc\\CGServerDll.h"
//Draw the spread bar above triangle area - CGS_RenderColorboxAsSpreadBarToWindow(void *ColorBox,DWORD Hwnd)
//Draw the colorbox to a window - CGS_RenderColorboxToWindow(void *ColorBox,DWORD Hwnd,0)
//END JRS NEW -----------------------------------------------


#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

#define		TAG_HEIGHT			9	// height of tag
#define		TAG_HALF_WIDTH		4	// 1/2 width of tag, equal side triangle

/////////////////////////////////////////////////////////////////////////////
// CPalSliderCtrl

CPalSliderCtrl::CPalSliderCtrl()
{
	TRACE0("PalSliderCtrl.cpp - Constructor\n" );
	m_lockTag = -1;
}

CPalSliderCtrl::~CPalSliderCtrl()
{
}


BEGIN_MESSAGE_MAP(CPalSliderCtrl, CEdit)
	//{{AFX_MSG_MAP(CPalSliderCtrl)
	ON_WM_LBUTTONDOWN()
	ON_WM_MOUSEMOVE()
	ON_WM_PAINT()
	ON_WM_RBUTTONDOWN()
	ON_WM_LBUTTONUP()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CPalSliderCtrl message handlers

void CPalSliderCtrl::OnLButtonDown(UINT nFlags, CPoint pt) 
{
	// TODO: Add your message handler code here and/or call default
	TRACE0("PalSliderCtrl.cpp - OnLButtonDown\n" );
	CPalDlg* pPalDlg = (CPalDlg*)GetParent();

 	INT	iTag = GetSelectedTag( pt.x );
 	if(  iTag != -1 )
 	{
 		m_lockTag = iTag; // lock
 		pPalDlg->m_aColorBox.details.spread.current_tab_index = iTag;
 	}
 	//else - no change on the tag lock state
	
	pPalDlg->DrawTagFromDib();
	pPalDlg->DrawBaseColorBox();
	pPalDlg->InitHorizScrollBar();
	
	CEdit::OnLButtonDown(nFlags, pt);
}//end of CPalSliderCtrl::OnLButtonDown
/////////////////////////////////////////////////////////////////////////////
void CPalSliderCtrl::OnMouseMove(UINT nFlags, CPoint pt) 
{	
	TRACE0("CPalSliderCtrl::OnMouseMove\n");
	CPalDlg* pPalDlg = (CPalDlg*)GetParent();

	if( nFlags == MK_LBUTTON )
	{
		MovingTag( pt.x, nFlags );
		if( pPalDlg->GetPaletteState() == ID_FORMAT_PAL )
		{
			int index = CGS_BinGetSelectedIndex( UIBIN_PALETTE_MENU );		// get color box index
			CGS_BinSetItemData( UIBIN_PALETTE_MENU, index, &pPalDlg->m_aColorBox );	// copy color box back to core
		}
		else
			CGS_SetDataItem( pPalDlg->GetTextModeIndex(), &pPalDlg->m_aColorBox );
	}//end of if - MK_LBUTTON   

	CEdit::OnMouseMove(nFlags, pt);
}//end of CPalSliderCtrl::OnMouseMove
/////////////////////////////////////////////////////////////////////////////
void CPalSliderCtrl::OnPaint() 
{
	CPaintDC dc(this); // device context for painting
	
	CPalDlg* pPalDlg = (CPalDlg*)GetParent();
	pPalDlg->DrawTagFromDib();

	TRACE0("PalSliderCtrl.cpp - OnPaint\n" );
}//end of CPalSliderCtrl::OnPaint
/////////////////////////////////////////////////////////////////////////////
void CPalSliderCtrl::OnRButtonDown(UINT nFlags, CPoint pt) 
{
	// TODO: Add your message handler code here and/or call default
	TRACE0("PalSliderCtrl.cpp - OnRButtonDown\n" );
	CEdit::OnRButtonDown(nFlags, pt);
}//end of CPalSliderCtrl::OnRButtonDown
////////////////////////////////////////////////////////////////////////////////////////////////////
INT CPalSliderCtrl::GetSelectedTag(INT x)
{
	CPalDlg* pPalDlg = (CPalDlg*)GetParent();
 	double	dw   = (double)TAG_HALF_WIDTH/(pPalDlg->m_SpreadWidth);
 	double	xMos = (double)x/(pPalDlg->m_SpreadWidth);
 	double	xTag;	
 	int		i = 0;
 
 	int		numTag = pPalDlg->m_aColorBox.details.spread.spread_tabs_total;
 	int		rv = -1; // default - error
 
 	for( i = 0; i < numTag; i++ )
 	{
 		xTag = pPalDlg->m_aColorBox.details.spread.spread_tab_position[i];
 		if( ((xTag - dw) < xMos) && (xMos < (xTag + dw)) )
 			return( i );
 	}//end of for
 
 	return( -1 );
}//end of CPalSliderCtrl::GetSelectedTag
/////////////////////////////////////////////////////////////////////////////////////////////
// INPUT : INT x - current x position of mouse pointer
// INPUT : UINT flag - MK_LBUTTON message
// WIN32 style was given up and need to be very careful on future development...
// REMEMBER : All mouse messages should check the lock state. 
// 1) Get the current selected color palette from color panel.
// 2) Get total number of tags from the selected color palette.
// 3) Lock the tag ??
// 4) Assign the current tag position of the selected color palette.
// 5) Save the current color of the selected tag. It is neccessary for the mulitple 
//    tag on the same position but different color attribute.
// 6) Drawa the whole tag data structure... Keep up the tag position.
// 7) Sort the tag positino for core function.
// 8) Re-gain the current selected tag. After sortnig, the tag position may change.
// 9) Redraw everythings...
VOID CPalSliderCtrl::MovingTag(INT xPos, UINT flag)
{
	INT			iTag;
	INT			numTag;
	COLORREF	tColor; // selected tag color
	float		tPos;	//tag position
	CPalDlg*	pPalDlg = (CPalDlg*)GetParent();

	if( flag == MK_LBUTTON )
	{
		tPos = (float)(xPos/(double)pPalDlg->m_SpreadWidth);
		if( 1 < tPos )
			tPos = 1;

		numTag = pPalDlg->m_aColorBox.details.spread.spread_tabs_total;

		if( m_lockTag != -1 )
			iTag = m_lockTag;
		else
			return;

		pPalDlg->m_aColorBox.details.spread.spread_tab_position[iTag] = (float)tPos;
		tColor = pPalDlg->m_aColorBox.details.spread.color[iTag];

		SortTag( );

		for( int i = 0; i < numTag; i++ ) // reset the current selected tag
		{
			if( pPalDlg->m_aColorBox.details.spread.spread_tab_position[i] == tPos )
			{
				if( tColor == pPalDlg->m_aColorBox.details.spread.color[i] )
					m_lockTag = pPalDlg->m_aColorBox.details.spread.current_tab_index = i;
			}

			if( pPalDlg->m_aColorBox.details.spread.spread_tab_position[i] == tPos && tPos == 1 )
			{
				m_lockTag = pPalDlg->m_aColorBox.details.spread.current_tab_index = i;
				break;
			}
		}//end of for

		pPalDlg->DrawTagFromDib();
		pPalDlg->DrawBaseColorBox();
		pPalDlg->DrawSpreadColorBox();
		pPalDlg->DrawColorBoxWnd();

	}//end of if - most outer
}//end of CPalSliderCtrl::MovingTag
////////////////////////////////////////////////////////////////////////////////////////////
VOID CPalSliderCtrl::SortTag()
{
	CPalDlg*	pPalDlg = (CPalDlg*)GetParent();
	INT i, j, gap;

	INT numTag = pPalDlg->m_aColorBox.details.spread.spread_tabs_total;
	
	for( gap = numTag/2; 0 < gap; gap /=2 )
		for( i = gap; i < numTag; i++ )
			for( j = i - gap; 0 <= j; j -= gap )
			{
				if( CompTag( j, j+gap ) <= 0 )
					break;
				DoSwap( j, j+gap );
			}//end of for
}//end of CPalSliderCtrl::SortTag()
////////////////////////////////////////////////////////////////////////////////////////////
INT CPalSliderCtrl::CompTag(INT j, INT k)
{
	CPalDlg*	pPalDlg = (CPalDlg*)GetParent();

	if(   pPalDlg->m_aColorBox.details.spread.spread_tab_position[j]
		< pPalDlg->m_aColorBox.details.spread.spread_tab_position[k] )
		return( -1 );
	else
		if(   pPalDlg->m_aColorBox.details.spread.spread_tab_position[k]
			< pPalDlg->m_aColorBox.details.spread.spread_tab_position[j] )
			return( 1 );
		else
			return( 0 );

}//end of CPalSliderCtrl::CompTag
////////////////////////////////////////////////////////////////////////////////////////////
VOID CPalSliderCtrl::DoSwap(INT j, INT k)
{
	CPalDlg*	pPalDlg = (CPalDlg*)GetParent();

	COLORREF	tmpColor;
	float		tmpPos;

	tmpColor = pPalDlg->m_aColorBox.details.spread.color[j];
	tmpPos   = pPalDlg->m_aColorBox.details.spread.spread_tab_position[j];

	pPalDlg->m_aColorBox.details.spread.color[j] = 	pPalDlg->m_aColorBox.details.spread.color[k];
	pPalDlg->m_aColorBox.details.spread.spread_tab_position[j] = pPalDlg->m_aColorBox.details.spread.spread_tab_position[k];

	pPalDlg->m_aColorBox.details.spread.color[k] = tmpColor;
	pPalDlg->m_aColorBox.details.spread.spread_tab_position[k] = tmpPos;
}//end of CPalSliderCtrl::DoSwap
////////////////////////////////////////////////////////////////////////////////////////////
void CPalSliderCtrl::OnLButtonUp(UINT nFlags, CPoint point) 
{
	TRACE0("CPalSliderCtrl::OnLButtonUp\n");
	m_lockTag = -1;

	CEdit::OnLButtonUp(nFlags, point);
}//end of CPalSliderCtrl::OnLButtonUp
