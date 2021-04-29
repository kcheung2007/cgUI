/* COPYRIGHT NOTICE:
********************************************************
********************************************************
*/
// IXTabCtrl.cpp : implementation file
//

#include "stdafx.h"
#include "IXTabCtrl.h"
#include "ACGS_Inc\\UI_BinMgrContextFlags.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

extern DWORD	g_dwTab;

/////////////////////////////////////////////////////////////////////////////
// CIXTabCtrl

CIXTabCtrl::CIXTabCtrl()
{
	m_iSelectedTab = 0;		// default tab index
	m_ptTabs.x = 3;			// starting x pos of page dialog in tab control
	m_ptTabs.y = 28;		// starting y pos of page dialog in tab control

	// default tab color
	m_crSelected  = 0x00FF0000;
	m_crDisabled  = 0x00FFFFFF;
	m_crNormal	  = 0x0;
	m_crMouseOver = 0x00888888;

	m_bColorSelected  = 1;
	m_bColorDisabled  = 1;
	m_bColorNormal    = 1;
	m_bColorMouseOver = 1;

	m_iIndexMouseOver = -1;

	m_bMouseOver = 0;
}//end of constructor

CIXTabCtrl::~CIXTabCtrl()
{
	m_arrayStatusTab.RemoveAll();
}//end of destructor


BEGIN_MESSAGE_MAP(CIXTabCtrl, CTabCtrl)
	//{{AFX_MSG_MAP(CIXTabCtrl)
	ON_NOTIFY_REFLECT(TCN_SELCHANGE, OnSelchange)
	ON_NOTIFY_REFLECT(TCN_SELCHANGING, OnSelchanging)
	ON_WM_MOUSEMOVE()
	ON_WM_TIMER()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

//////////////////////////////////////////////////////////////////////////////////
// CIXTabCtrl message handlers
//////////////////////////////////////////////////////////////////////////////////
// For tabbed dialog ONLY, set the starting position of the dialog (page).
VOID CIXTabCtrl::SetTopLeftCorner(CPoint pt)
{
	m_ptTabs.x = pt.x;
	m_ptTabs.y = pt.y;
}//end of CIXTabCtrl::SetTopLeftCorner
//////////////////////////////////////////////////////////////////////////////////
VOID CIXTabCtrl::SetMouseOverColor(COLORREF cr) 
{
	m_bColorMouseOver = 1;
	m_crMouseOver = cr;
}//end of CIXTabCtrl::SetMouseOverColor

//////////////////////////////////////////////////////////////////////////////////
VOID CIXTabCtrl::SetDisabledColor(COLORREF cr) 
{
	m_bColorDisabled = 1;
	m_crDisabled = cr;
}//end of CIXTabCtrl::SetDisabledColor

//////////////////////////////////////////////////////////////////////////////////
VOID CIXTabCtrl::SetSelectedColor(COLORREF cr)
{
	m_bColorSelected = 1;
	m_crSelected = cr;
}//end of CIXTabCtrl::SetSelectedColor

//////////////////////////////////////////////////////////////////////////////////
VOID CIXTabCtrl::SetNormalColor(COLORREF cr)
{
	m_bColorNormal = 1;
	m_crNormal = cr;
}//end of CIXTabCtrl::SetNormalColor

//////////////////////////////////////////////////////////////////////////////////
// Adding Tab ONLY - an added dialog (page) should create before and pass the pWnd
// to this function.
// INPUT : CWnd* pWnd - pointer to the dialog.
// INPUT : LPTSTR lpszCaption - Tab caption.
// INPUT : INT iImage - index of tab image from image list.
VOID CIXTabCtrl::AddTab(CWnd* pWnd, LPTSTR lpszCaption, INT iImage)
{
	TRACE0("CIXTabCtrl::AddTab\n");

	ASSERT_VALID(pWnd);

	TCITEM item;
	item.mask    = TCIF_TEXT | TCIF_PARAM | TCIF_IMAGE;
	item.lParam  = (LPARAM) pWnd;
	item.pszText = lpszCaption;
	item.iImage  = iImage;

	INT iIndex = m_arrayStatusTab.GetSize();
	InsertItem( iIndex, &item );

	pWnd->SetWindowPos( NULL, m_ptTabs.x, m_ptTabs.y , 0, 0, SWP_FRAMECHANGED|SWP_NOSIZE|SWP_NOZORDER );
	pWnd->ShowWindow( iIndex ? SW_HIDE : SW_SHOW );

	m_arrayStatusTab.Add( 1 ); // enable initial status
}//end of CIXTabCtrl::AddTab
//////////////////////////////////////////////////////////////////////////////////
// INPUT : INT iIndex - index of Tab
// INPUT : BOOL bEnable - state of enable or disable 
VOID CIXTabCtrl::EnableTab(INT iIndex, BOOL bEnable)
{
	TRACE0("CIXTabCtrl::EnableTab\n");

	ASSERT(iIndex < m_arrayStatusTab.GetSize());
	
	if( m_arrayStatusTab[iIndex] != bEnable ) // Change the status
	{
		m_arrayStatusTab[iIndex] = bEnable;

		//++++++++ redraw Tab
		CRect rcTab;
		GetItemRect( iIndex, &rcTab );
		InvalidateRect( rcTab );
	}

}//end of CIXTabCtrl::EnableTab
//////////////////////////////////////////////////////////////////////////////////
// ++ NOT for disable the tab in certain version
VOID CIXTabCtrl::DeleteAllTabs()
{
	TRACE0("CIXTabCtrl::DeleteAllTabs\n");
/** comment out on 10-13-00
	m_arrayStatusTab.RemoveAll();	
	DeleteAllItems();
** comment out on 10-13-00*/
}//end of CIXTabCtrl::DeleteAllTabs
//////////////////////////////////////////////////////////////////////////////////
// ++ NOT for disable the tab in certain version
VOID CIXTabCtrl::DeleteTab(INT iIndex)
{
	TRACE0("CIXTabCtrl::DeleteTab\n");
/** comment out on 10-13-00
	ASSERT(iIndex < m_arrayStatusTab.GetSize());

	m_arrayStatusTab.RemoveAt(iIndex);

	DeleteItem(iIndex);
* comment out on 10-13-00 */
}//end of CIXTabCtrl::DeleteTab

//////////////////////////////////////////////////////////////////////////////////
BOOL CIXTabCtrl::IsTabEnabled(INT iIndex)
{	
	TRACE0("CIXTabCtrl::IsTabEnabled\n");
	ASSERT(iIndex < m_arrayStatusTab.GetSize()); // handle the error later
	
	return( m_arrayStatusTab[iIndex] );
}//end of CIXTabCtrl::IsTabEnabled

//////////////////////////////////////////////////////////////////////////////////
// For testing purpose, NOT implement yet. DON'T MODIFY
BOOL CIXTabCtrl::SelectTab(INT iIndex)
{
	TRACE0("CIXTabCtrl::SelectTab\n");
/** comment out on 10-13-00
	TRACE0("IXTabCtrl.cpp : CIXTabCtrl::SelectTab\n");
	ASSERT(iIndex < m_arrayStatusTab.GetSize());

	if( GetCurSel() == iIndex )
		return( 1 );
	
	if( m_arrayStatusTab[iIndex] ) // check if the tab is enabled 
	{
		TCITEM item;
		CWnd* pWnd;
		item.mask = TCIF_PARAM;

		GetItem(GetCurSel(), &item);
		pWnd = reinterpret_cast<CWnd*> (item.lParam);
		ASSERT_VALID(pWnd);
		pWnd->ShowWindow(SW_HIDE);

		SetCurSel(iIndex);
		GetItem(iIndex, &item);
		pWnd = reinterpret_cast<CWnd*> (item.lParam);
		ASSERT_VALID(pWnd);
		pWnd->ShowWindow(SW_SHOW);

		return( 1 );
	}//end of if
** comment out on 10-13-00*/
	return( 0 );
}//end of CIXTabCtrl::SelectTab
//////////////////////////////////////////////////////////////////////////////////
VOID CIXTabCtrl::OnSelchange(NMHDR* pNMHDR, LRESULT* pResult) 
{	
	TRACE0("CIXTabCtrl::OnSelchange\n");
	INT iNewTab = GetCurSel();

	if( !IsTabEnabled(iNewTab) )
	{
		SetCurSel(m_iSelectedTab);
	}
	else
	{
		TCITEM item;
		CWnd* pWnd;

		item.mask = TCIF_PARAM;
		
		//+++++++++++++++++++++ hide the current tab
		GetItem(m_iSelectedTab, &item);
		pWnd = reinterpret_cast<CWnd*> (item.lParam);
		ASSERT_VALID(pWnd);
		pWnd->ShowWindow(SW_HIDE);

		//+++++++++++++++++++++ show the selected tab 
		GetItem(iNewTab, &item);
		pWnd = reinterpret_cast<CWnd*> (item.lParam);
		ASSERT_VALID(pWnd);
		pWnd->ShowWindow(SW_SHOW);

//	CGS_BinSelect( UIBIN_PALETTE, ABMC_FACE_COLOR, pt.x, pt.y );
//	CGS_BinSelect( UIBIN_PALETTE, ABMC_OUTLINE1_COLOR, pt.x, pt.y );
//	CGS_BinSelect( UIBIN_PALETTE, ABMC_OUTLINE2_COLOR, pt.x, pt.y );
//	CGS_BinSelect( UIBIN_PALETTE, ABMC_SHADOW1_COLOR, pt.x, pt.y );

		switch( iNewTab )
		{
		case 0:
			g_dwTab = ABMC_FACE_COLOR;
			break;
		case 1:
			g_dwTab = ABMC_OUTLINE1_COLOR;
			break;
		case 2:
			g_dwTab = ABMC_OUTLINE2_COLOR;
			break;
		case 3:
			g_dwTab = ABMC_SHADOW1_COLOR;
			break;
		case 4:
			g_dwTab = ABMC_SHADOW2_COLOR;
			break;
		}//end of switch

	}//end of else

	*pResult = 0;

	AfxGetMainWnd()->SetFocus();
}//end of CIXTabCtrl::OnSelchange

//////////////////////////////////////////////////////////////////////////////////
VOID CIXTabCtrl::OnSelchanging(NMHDR* pNMHDR, LRESULT* pResult) 
{
	TRACE0("CIXTabCtrl::OnSelchanging\n");
	m_iSelectedTab = GetCurSel();
	*pResult = 0;
	
}//end of CIXTabCtrl::OnSelchanging

//////////////////////////////////////////////////////////////////////////////////
VOID CIXTabCtrl::PreSubclassWindow() 
{
	CTabCtrl::PreSubclassWindow();
	ModifyStyle(0, TCS_OWNERDRAWFIXED);
}//end of CIXTabCtrl::PreSubclassWindow

//////////////////////////////////////////////////////////////////////////////////////
VOID CIXTabCtrl::DrawItem(LPDRAWITEMSTRUCT lpDrawItemStruct) 
{	
	TRACE0("CIXTabCtrl::DrawItem\n");
	CRect rect = lpDrawItemStruct->rcItem;
	rect.top += ::GetSystemMetrics(SM_CYEDGE);

	INT nTabIndex = lpDrawItemStruct->itemID;
	
	if( nTabIndex < 0 ) 
		return;

	BOOL bSelected = (nTabIndex == GetCurSel());

	COLORREF crSelected = m_bColorSelected ? m_crSelected : GetSysColor(COLOR_BTNTEXT);
	COLORREF crNormal   = m_bColorNormal   ? m_crNormal   : GetSysColor(COLOR_BTNTEXT);
	COLORREF crDisabled = m_bColorDisabled ? m_crDisabled : GetSysColor(COLOR_GRAYTEXT);

	TCHAR	label[64];
	TC_ITEM item;
	item.mask		= TCIF_TEXT|TCIF_IMAGE;
	item.pszText	= label; // always has garbage
	item.cchTextMax = 63;    	
	if( !GetItem(nTabIndex, &item) )
		return;

	CDC* pDC = CDC::FromHandle(lpDrawItemStruct->hDC);
	if( !pDC )
		return;

	INT nSavedDC = pDC->SaveDC();

	CRect rcTab;
	POINT pt;

	GetItemRect( nTabIndex, &rcTab );
	GetCursorPos( &pt );
	ScreenToClient( &pt );

	if( rcTab.PtInRect(pt) )
		m_iIndexMouseOver = nTabIndex;

	pDC->SetBkMode(TRANSPARENT);
	pDC->FillSolidRect( rect, ::GetSysColor(COLOR_BTNFACE) );

	//++++++++++++++++++++++++++++ Draw the image on Tab ++
	CImageList* pImageList = GetImageList();
	if( pImageList && item.iImage >= 0 ) 
	{
		rect.left += pDC->GetTextExtent( " " ).cx;

		IMAGEINFO info;
		pImageList->GetImageInfo(item.iImage, &info);
		CRect ImageRect(info.rcImage);
		INT nYpos = rect.top;

		pImageList->Draw(pDC, item.iImage, CPoint(rect.left, nYpos), ILD_TRANSPARENT);
		rect.left += ImageRect.Width();
	}//end of if 

	if( !IsTabEnabled(nTabIndex) ) // tab not enable
	{
		pDC->SetTextColor(crDisabled);
		rect.top -= ::GetSystemMetrics(SM_CYEDGE);
		pDC->DrawText(label, rect, DT_SINGLELINE|DT_VCENTER|DT_CENTER);
	}
	else
	{
		if( bSelected ) // selected item
			pDC->SetTextColor( crSelected );
		else 
		{	// other item
			if( m_bColorMouseOver && nTabIndex == m_iIndexMouseOver )
				pDC->SetTextColor( m_crMouseOver );
			else
				pDC->SetTextColor( crNormal );
		}// end of else - other item

		rect.top -= ::GetSystemMetrics(SM_CYEDGE);
		pDC->DrawText(label, rect, DT_SINGLELINE|DT_VCENTER|DT_CENTER);
	}//end of else - tab enable

	pDC->RestoreDC( nSavedDC );
}//end of CIXTabCtrl::DrawItem

/////////////////////////////////////////////////////////////////////////////////
// HANDLE mouse move event
VOID CIXTabCtrl::OnMouseMove(UINT nFlags, CPoint point) 
{
//	TRACE0("CIXTabCtrl::OnMouseMove\n");
	if( m_bColorMouseOver ) // change the color of tab control
	{
		SetTimer( 1,10,NULL ); // check mouse event
		if( m_iIndexMouseOver != -1 )
		{
			CRect rcTab;
			GetItemRect( m_iIndexMouseOver, rcTab );
			if( !rcTab.PtInRect(point) )
			{
				CRect rectOldItem;
				GetItemRect(m_iIndexMouseOver, rectOldItem);
				m_iIndexMouseOver = -1;
				InvalidateRect(rectOldItem);
				return;
			}//end of if
		}//end of if
	
		if( !m_bMouseOver )
		{
			TCHITTESTINFO hitTest;

			m_bMouseOver = 1;
			hitTest.pt = point;

			INT iItem = HitTest( &hitTest ); // index of tab
			TRACE1("\tCIXTabCtrl::OnMouseMove - Hit Test = %d\n", iItem );
			if( iItem != -1 && m_arrayStatusTab[iItem] )
			{
				RECT rcTab;
				GetItemRect(iItem, &rcTab);

				InvalidateRect(&rcTab);
			}//end of if
		}//end of if - not mouse over
	}// end of if - change color of tab control
	
	CTabCtrl::OnMouseMove(nFlags, point);
}//end of CIXTabCtrl::OnMouseMove
//////////////////////////////////////////////////////////////////////////////
// Lazy way, should improve by capture mouse leave message
VOID CIXTabCtrl::OnTimer(UINT nIDEvent) 
{
	POINT pt;
	GetCursorPos(&pt);
	CRect rcTab, rectScreen;

	GetItemRect(m_iIndexMouseOver, rcTab);
	rectScreen = rcTab;
	ClientToScreen(rectScreen);
	
	// If mouse leaves, show normal
	if( !rectScreen.PtInRect(pt) )
	{
		KillTimer( 1 );
		m_bMouseOver = 0;
		m_iIndexMouseOver = -1;
		InvalidateRect(rcTab);
	}

	CTabCtrl::OnTimer(nIDEvent);
}//end of CIXTabCtrl::OnTimer
////////////////////////////////////////////////////////////////////////////////////////
INT CIXTabCtrl::GetIndexMouseOver()
{
	return( m_iIndexMouseOver );
}//end of CIXTabCtrl::GetIndexMouseOver()
