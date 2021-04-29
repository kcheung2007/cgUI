/* COPYRIGHT NOTICE:
********************************************************
*  Copyright (c) 2000 InnoVision Technology, Inc.      *
*  All rights reserved.                                *
*  PROPRIETARY AND CONFIDENTIAL                        *
*  DO NOT DISTRIBUTE                                   *
********************************************************
*/
// ImgPalBin.cpp : implementation file
//

#include "stdafx.h"
#include "cgui.h"
#include "PalDlg.h"
#include "ImgPalBin.h"
#include "ACGS_Inc\\UI_BinMgr.h" //JRS 00-03-08

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CImgPalBin

CImgPalBin::CImgPalBin()
{
}

CImgPalBin::~CImgPalBin()
{
}


BEGIN_MESSAGE_MAP(CImgPalBin, CEdit)
	//{{AFX_MSG_MAP(CImgPalBin)
	ON_WM_LBUTTONDOWN()
	ON_WM_PAINT()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CImgPalBin message handlers
////////////////////////////////////////////////////////////////////////////////////////////////
void CImgPalBin::OnLButtonDown(UINT nFlags, CPoint pt) 
{
	TRACE2("ImgPalBin.cpp : CImgPalBin::OnLButtonDown x = %d, y = %d\n", pt.x, pt.y );
	CPalDlg* pPalDlg = (CPalDlg*)GetParent();

	CGS_BinSelect( UIBIN_PALETTE_MENU, ABMC_DEFAULT, pt.x, pt.y ); // CHECK
	int index = CGS_BinGetSelectedIndex( UIBIN_PALETTE_MENU );
	CGS_BinGetItemData( UIBIN_PALETTE_MENU, index, &pPalDlg->m_aColorBox );

	switch( pPalDlg->m_Action )
	{
	case IDC_BT_PAL_COPY: // Do copy
		{
		CGS_BinSetItemData( UIBIN_PALETTE_MENU, index, &pPalDlg->m_tmpColorBox );
		memcpy( &pPalDlg->m_aColorBox, &pPalDlg->m_tmpColorBox, sizeof( ALPHA_COLOR_BOX ) );
		pPalDlg->m_Action = 0;
		}
		break;
	case IDC_BT_PAL_SWAP: // Do swap
		{
		CGS_BinSetItemData( UIBIN_PALETTE_MENU, pPalDlg->m_SwapIndex, &pPalDlg->m_aColorBox );
		CGS_BinSetItemData( UIBIN_PALETTE_MENU, index, &pPalDlg->m_tmpColorBox );
		memcpy( &pPalDlg->m_aColorBox, &pPalDlg->m_tmpColorBox, sizeof( ALPHA_COLOR_BOX ) );
		pPalDlg->m_Action = 0;
		}
		break;
	default:
		{
		//get the index 0..n of the currently selected item in the bin (i.e. the current colorbox)
		HWND hCtrl = pPalDlg->GetDlgItem( IDC_PAL_CUR_COLOR )->m_hWnd;
		CGS_RenderColorboxToWindow( &pPalDlg->m_aColorBox, (DWORD)hCtrl,0 );
		hCtrl = pPalDlg->GetDlgItem( IDC_SPREAD_COLOR )->m_hWnd;
		CGS_RenderColorboxAsSpreadBarToWindow( &pPalDlg->m_aColorBox, (DWORD)hCtrl );
		}
		break;
	}//end of switch

	pPalDlg->DrawBaseColorBox( );
	pPalDlg->DrawTagFromDib();	
	pPalDlg->InitButtonState();
	pPalDlg->InitHorizScrollBar();
	CEdit::OnLButtonDown(nFlags, pt);
}//end of CImgPalBin::OnLButtonDown
////////////////////////////////////////////////////////////////////////////////////////////////
void CImgPalBin::OnPaint() 
{
	CPaintDC dc(this); // device context for painting
	
	TRACE0("ImgPalBin.cpp : CImgPalBin::OnPaint \n" );

	CPalDlg* pPalDlg = (CPalDlg*)GetParent();

	pPalDlg->DrawBaseColorBox( );
	pPalDlg->DrawTagFromDib();

	HWND hCtrl = pPalDlg->GetDlgItem( IDC_PAL_CUR_COLOR )->m_hWnd;
	CGS_RenderColorboxToWindow( &pPalDlg->m_aColorBox, (DWORD)hCtrl,0);
	hCtrl = pPalDlg->GetDlgItem( IDC_SPREAD_COLOR )->m_hWnd;
	CGS_RenderColorboxAsSpreadBarToWindow( &pPalDlg->m_aColorBox, (DWORD)hCtrl );
	CGS_BinRefresh( UIBIN_PALETTE_MENU );
}//end of CImgPalBin::OnPaint()
