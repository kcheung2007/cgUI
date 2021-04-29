/* COPYRIGHT NOTICE:
********************************************************
********************************************************
*/
// TipWnd.cpp : implementation file
//

#include "stdafx.h"
#include "IXTipWnd.h"
#include "Global.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

#define		FONT_HEIGHT		-18 // window spec :(

/////////////////////////////////////////////////////////////////////////////
// CIXTipWnd
extern TCHAR	UILang_UIFont[256];
extern int		UILang_UIFontSize;


CIXTipWnd::CIXTipWnd()
{
	TRACE0("IXTipWnd.cpp : CIXTipWnd - constructor\n" );
}

CIXTipWnd::~CIXTipWnd()
{
	TRACE0("IXTipWnd.cpp : CIXTipWnd - Destructor\n" );
}

////////////////////////////////////////////////////////////////////////////////
// Create Tip window for displaying font
BOOL CIXTipWnd::Create(CWnd* pParent)
{
	TRACE0("IXTipWnd.cpp : CIXTipWnd::Create\n" );

//	HFONT	hFont = NULL;
	BOOL rv = CWnd::CreateEx( 0, 
							AfxRegisterWndClass(0),
							NULL,
							WS_BORDER|WS_POPUP,
							0,
							0,0,0,
							NULL,
							(HMENU)0);

//	ChangeControlFont( this->m_hWnd, hFont, UILang_UIFont,0, UILang_UIFontSize, FW_NORMAL);
	return( rv );
}//end of CIXTipWnd::Create

BEGIN_MESSAGE_MAP(CIXTipWnd, CWnd)
	//{{AFX_MSG_MAP(CIXTipWnd)
	ON_WM_ERASEBKGND()
	ON_WM_PAINT()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()


/////////////////////////////////////////////////////////////////////////////
// CIXTipWnd message handlers
////////////////////////////////////////////////////////////////////////////////
BOOL CIXTipWnd::OnEraseBkgnd(CDC* pDC) 
{
	TRACE0("IXTipWnd.cpp : CIXTipWnd::OnEraseBkgnd\n" );
	CBrush brush(GetSysColor(COLOR_INFOBK));
	CRect rc;
	pDC->GetClipBox( rc );
	CBrush* pOldBrush = pDC->SelectObject( &brush );
	pDC->PatBlt( rc.left, rc.top, rc.Width(), rc.Height(), PATCOPY );
	pDC->SelectObject( pOldBrush );
	return( 1 );
}//end of CIXTipWnd::OnEraseBkgnd
////////////////////////////////////////////////////////////////////////////////
void CIXTipWnd::ShowTips( CPoint pt, const CString& str )
{
	TRACE0("IXTipWnd.cpp : CIXTipWnd::ShowTips\n" );

	CSize sz;
	// Create new font if the selection has changed
	if( m_strFont != str )
	{
		CDC* pDC = GetDC();
		m_strFont = str;
		LOGFONT lf;
		ZeroMemory( &lf,sizeof(lf) );

		lf.lfCharSet = DEFAULT_CHARSET;
		lf.lfHeight = FONT_HEIGHT;

		lstrcpy(lf.lfFaceName,m_strFont);
//		_mbscpy( (UCHAR*)lf.lfFaceName, (UCHAR*)(LPCTSTR)m_strFont);
				
		m_font.DeleteObject(); // Delete old font
		m_font.CreateFontIndirect(&lf);
		
		CFont* pFont = pDC->SelectObject(&m_font);		
		sz = pDC->GetTextExtent(m_strFont); // Font demensions on screen 
		
		sz.cx += 8; // space round the font - modify here
		sz.cy += 8;

		pDC->SelectObject(pFont);
		ReleaseDC(pDC);

		TRACE2( "CIXTipWnd::ShowTips - x = %d, y = %d\n", &pt.x-sz.cx, &pt.y );
		SetWindowPos( 0,pt.x - sz.cx, pt.y,sz.cx,sz.cy,SWP_SHOWWINDOW | SWP_NOACTIVATE );

		RedrawWindow(); // Force immediate redraw
	}//end of if

}// end of CIXTipWnd::ShowTips
////////////////////////////////////////////////////////////////////////////////////////
void CIXTipWnd::OnPaint() 
{
	CPaintDC dc(this); // device context for painting
	
	dc.SelectObject(&m_font);
	CRect rc;
	GetClientRect(rc);

//	dc.DrawText(m_strFont,rc,DT_SINGLELINE|DT_VCENTER|DT_CENTER);
	dc.DrawText( (LPCTSTR)m_strFont, m_strFont.GetLength(), rc,DT_SINGLELINE|DT_VCENTER|DT_CENTER);
	// Do not call CWnd::OnPaint() for painting messages
}// end of CIXTipWnd::OnPaint
