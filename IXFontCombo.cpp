/* COPYRIGHT NOTICE:
********************************************************
********************************************************
*/
// FontBox.cpp : implementation file
//

#include "Stdafx.h"
#include "resource.h"
#include "ACGS_Inc\\CGServerDll.h"
#include "IXFontCombo.h"
#include "Global.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

// should not be changed unless image IDB_GLYPH is changed
#define ICON_WIDTH 15 


/////////////////////////////////////////////////////////////////////////////
// CIXFontCombo
////////////////////////////////////////////////////////////////////////////////
CIXFontCombo::CIXFontCombo()
{
	// Load printer icon
	m_imgList.Create(IDB_PRINTER,15,1,RGB(255,0,255));
}//end of constructor
////////////////////////////////////////////////////////////////////////////////
CIXFontCombo::~CIXFontCombo()
{
}// end of destructor

BEGIN_MESSAGE_MAP(CIXFontCombo, CComboBox)
	//{{AFX_MSG_MAP(CIXFontCombo)
	ON_WM_CREATE()
	ON_WM_DESTROY()
	ON_CONTROL_REFLECT(CBN_KILLFOCUS, OnKillfocus)
	ON_CONTROL_REFLECT(CBN_SETFOCUS, OnSetfocus)
	ON_CONTROL_REFLECT(CBN_CLOSEUP, OnCloseUp)
	ON_WM_TIMER()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CIXFontCombo message handlers
/////////////////////////////////////////////////////////////////////////////
// Overridables for onwerdraw combos
void CIXFontCombo::DeleteItem( LPDELETEITEMSTRUCT ) 
{
}// end of CIXFontCombo::DeleteItem
/////////////////////////////////////////////////////////////////////////////
// Overridables for onwerdraw combos
void CIXFontCombo::MeasureItem( LPMEASUREITEMSTRUCT ) 
{
}//end of CIXFontCombo::MeasureItem
/////////////////////////////////////////////////////////////////////////////
// Initialize fonts for combo
int CIXFontCombo::OnCreate( LPCREATESTRUCT lpCreateStruct ) 
{
	if( CComboBox::OnCreate(lpCreateStruct) == -1 )
		return -1;

	Initialize();

	return 0;
}//end of CIXFontCombo::OnCreate
////////////////////////////////////////////////////////////////////////////////
// Owner draw to render bitmap and font name
void CIXFontCombo::DrawItem(LPDRAWITEMSTRUCT lpDrawItemStruct) 
{
	ASSERT(lpDrawItemStruct->CtlType == ODT_COMBOBOX); // We've gotta be a combo

	if( lpDrawItemStruct->itemID == 0xffffffff ) // prevent invalid call from system
		return;

	CDC *pDC = CDC::FromHandle( lpDrawItemStruct->hDC ); // get a DC
	
	ASSERT( pDC ); // Attached failed
	
	CRect rc( lpDrawItemStruct->rcItem );
		
	if( lpDrawItemStruct->itemState & ODS_FOCUS ) // Draw focus rectangle
		pDC->DrawFocusRect( rc );
		
	int nIndexDC = pDC->SaveDC(); // Save off context attributes

	CBrush brushFill;
	
	// Draw selection state
	if( lpDrawItemStruct->itemState & ODS_SELECTED )
	{
		brushFill.CreateSolidBrush( ::GetSysColor(COLOR_HIGHLIGHT) );
		pDC->SetTextColor( ::GetSysColor(COLOR_HIGHLIGHTTEXT) );
	}
	else
		brushFill.CreateSolidBrush( pDC->GetBkColor() );

	pDC->SetBkMode( TRANSPARENT );
	pDC->FillRect( rc, &brushFill );

	CString strCurFont, strNextFont;
	GetLBText( lpDrawItemStruct->itemID, strCurFont );

	CIXFontObj* pFontObj;
	m_mapFonts.Lookup( strCurFont, pFontObj );

	ASSERT(pFontObj != NULL);
	DWORD dwData = pFontObj->GetFlags();
	
	// Render Bitmaps
/** save - disable the icon next to text
	if( dwData & TRUETYPE_FONT )
		m_imgList.Draw( pDC,1, CPoint(rc.left,rc.top), ILD_TRANSPARENT );
	if( dwData & PRINTER_FONT )
		m_imgList.Draw( pDC,0, CPoint(rc.left,rc.top), ILD_TRANSPARENT );

	int nX = rc.left; // Save for lines
	rc.left += ICON_WIDTH + 2; // Text Position
** save - disable the icon next to text***/	

	int nX = rc.left;	// Save for lines
	rc.left += 5;		// Text Position

	pDC->TextOut( rc.left, rc.top, strCurFont );
	
	if( GetItemData(lpDrawItemStruct->itemID) ) // GetItemData - return font in use
	{
		GetLBText( lpDrawItemStruct->itemID+1,strNextFont );

		CIXFontObj* pFontObjNext;
		m_mapFonts.Lookup( strNextFont,pFontObjNext );

		if( !GetItemData(lpDrawItemStruct->itemID+1) )
		{
			// ++++++++ Draw font MRU separator
			TEXTMETRIC tm;
			pDC->GetTextMetrics(&tm);

			pDC->MoveTo(nX,rc.top+tm.tmHeight);
			pDC->LineTo(rc.right,rc.top+tm.tmHeight);

			pDC->MoveTo(nX,rc.top+tm.tmHeight+2);
			pDC->LineTo(rc.right,rc.top+tm.tmHeight+2);
		}//end of if - GetItemData - Next item
	}//end of if - GetItemData - return font in use
	
	pDC->RestoreDC(nIndexDC); // Restore State of context
}//end of CIXFontCombo::DrawItem
////////////////////////////////////////////////////////////////////////////////
void CIXFontCombo::OnDestroy() 
{
	POSITION pos = m_mapFonts.GetStartPosition();
	
	while( pos )
	{
		CString		strKey;
		CIXFontObj*	pFontObj;
		m_mapFonts.GetNextAssoc(pos,strKey,pFontObj);
		delete pFontObj;
	}//end of while

	CComboBox::OnDestroy();
}//end of CIXFontCombo::OnDestroy

////////////////////////////////////////////////////////////////////////////////
void CIXFontCombo::OnKillfocus() 
{
	SetCurrentFont();
}//end of CIXFontCombo::OnKillfocus
////////////////////////////////////////////////////////////////////////////////
// Save the original font
void CIXFontCombo::OnSetfocus() 
{
	GetWindowText(m_strFontSave);	
}//end of CIXFontCombo::OnSetfocus
////////////////////////////////////////////////////////////////////////////////
// Change font in edit box is a known font otherwise reject and restore orginal
void CIXFontCombo::SetCurrentFont()
{
	CString strSelFont;
	int nSel = GetCurSel();

	if( nSel == CB_ERR )
	{
		GetWindowText(strSelFont);
		nSel = FindStringExact(-1,strSelFont);		
		if( nSel == CB_ERR )
			SetWindowText(m_strFontSave);
	}// end of if
}//end of CIXFontCombo::SetCurrentFont
////////////////////////////////////////////////////////////////////////////////
void CIXFontCombo::OnCloseUp()
{
	int		nSel;	
	CString strFont;	

	SetCurrentFont();
	nSel = GetCurSel();
	if( nSel != CB_ERR )
		GetLBText( nSel, strFont );

	char	szFont[MAX_PATH];
	UnicodeToMultiByte( CP_ACP, (LPTSTR)(LPCTSTR)strFont, szFont );
/*
	WideCharToMultiByte(CP_ACP,                 // code page
						0,		                // dwFlags
						strFont,				// lpWideCharStr
						-1,                     // cchWideCharStr
						szFont,					// lpMultiByteStr
						sizeof(szFont),			// cchMultiByte
						NULL,                   // lpDefaultChar
						NULL					// lpUsedDefaultChar
					);                  
*/
	CGS_SetValStr( EDIT_OBJ_TYPEFACE, szFont );

	m_wndTip.ShowWindow( SW_HIDE );
	AfxGetMainWnd()->SetFocus();
}//end of CIXFontCombo::OnCloseUp
////////////////////////////////////////////////////////////////////////////////
void CIXFontCombo::Initialize()
{
	TRACE0( "IXFontCombo.cpp - Initial font combo box. m_wndTip create.\n" );
	m_wndTip.Create(this);
	
	CString		strDefault = ""; // Set default font name - may read from project		

// save for reference
//	EnumSystemFonts();

	int nFont;
	char** fontList;

	TCHAR wsz[MAX_PATH];

	CGS_GetSystemFontList( &nFont, &fontList );
	for( int i = 0; i < nFont; i++ )
	{
		MultiByteToUnicode( CP_ACP, fontList[i], wsz );
//		MultiByteToWideChar(CP_ACP, MB_PRECOMPOSED, fontList[i], -1, wsz, MAX_PATH);
		AddFont( wsz, TRUETYPE_FONT );
		AddString( wsz );
	}
	// Set timer. Its the only way we know when a selection has changed - use for tip window
	SetTimer(1, 250, NULL);

}//end of CIXFontCombo::Initialize
////////////////////////////////////////////////////////////////////////////////
void CIXFontCombo::AddFont(CString strName, DWORD dwFlags)
//void CIXFontCombo::AddFont(LPTSTR strName, DWORD dwFlags)
{
	CIXFontObj* pFontObj;	

	// Check fonts not aleady in the array
	if( !m_mapFonts.Lookup(strName,pFontObj) )
		m_mapFonts.SetAt(strName,new CIXFontObj(dwFlags));
}// end of CIXFontCombo::AddFont

////////////////////////////////////////////////////////////////////////////////
// Time up
void CIXFontCombo::OnTimer( UINT nIDEvent ) 
{	
	CWnd* pDropWnd = NULL;
	if( GetDroppedState() ) // Is combo open
	{
		int nSel = GetCurSel();
		if( nSel != -1 )
		{
			CString str;
			GetLBText( nSel, str );

			int nHeight = GetItemHeight(0) * ((nSel - GetTopIndex()) + 1)  - GetItemHeight(0);
			if( GetDroppedState() )
				pDropWnd = GetCapture();

			CRect rec;
			pDropWnd->GetWindowRect( rec );

			CPoint pt( rec.left - 1, rec.top + nHeight );
			m_wndTip.ShowTips( pt, str );
		}//end of if
	}//end of if
		
	CComboBox::OnTimer(nIDEvent);
}//end of CIXFontCombo::OnTimer
///////////////////////////////////////////////////////////////////////////////////////////
VOID CIXFontCombo::SetNonSysFont(CString font)
{	
	SetWindowText( font );
}//end of CIXFontCombo::SetNonSysFont
