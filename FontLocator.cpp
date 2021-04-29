// FontLocator.cpp : implementation file
//

#include "stdafx.h"
#include "cgui.h"
#include "FontLocator.h"
#include "Global.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

#define		SX		4
#define		SY		3
#define		CELL_W	160
#define		CELL_H	45

/////////////////////////////////////////////////////////////////////////////
// CFontLocator dialog
extern _TCHAR	UILang_UIFont[256];
extern int		UILang_UIFontSize;

CFontLocator::CFontLocator(CWnd* pParent /*=NULL*/)	: CDialog(CFontLocator::IDD, pParent)
{
	//{{AFX_DATA_INIT(CFontLocator)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	m_hFont = NULL;
}

CFontLocator::~CFontLocator()
{
	for( DWORD i = 0; i < m_numTxt; i++ )
	{
		if( m_hFont[i] != NULL )
			DeleteObject( (HGDIOBJ)m_hFont[i] );
	}
	if( m_hFont != NULL )
		delete [] m_hFont;
}


void CFontLocator::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CFontLocator)
	DDX_Control(pDX, IDC_VSB_FONT, m_vsbFont);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CFontLocator, CDialog)
	//{{AFX_MSG_MAP(CFontLocator)
	ON_WM_PAINT()
	ON_WM_VSCROLL()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CFontLocator message handlers
/////////////////////////////////////////////////////////////////////////////
BOOL CFontLocator::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	GetDlgItem( IDC_FRM_FONT )->GetClientRect( &m_rcFrm );
	this->GetClientRect( &m_rcDlg );

	//++++++++++++++++++ Initial vertical scroll bar
	m_vsbFont.SetScrollRange( 1, 1000 );	// default range 0 .. 1000
	m_vsbFont.SetScrollPos( 1 );			// default position
	
	InitDlgItemText();

	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}//end of CFontLocator::OnInitDialog()
/////////////////////////////////////////////////////////////////////////////
void CFontLocator::OnPaint() 
{
	CPaintDC dc(this); // device context for painting

// save for test purpose
	CRect	rc;
	rc.top = SY;
	rc.left = SX;

	CBrush brush(RGB(255, 255, 255));	
	dc.FillRect( &rc, &brush );

	dc.MoveTo( SX + CELL_W, SY );
	dc.LineTo( SX + CELL_W, m_rcFrm.bottom );

	CString str("Text Out");
	for( int i = 0; i < 8; i++ )
	{
		m_rcCell.top = SY + (i * CELL_H);
		m_rcCell.left = SX;
		m_rcCell.bottom = SY + ( (i+1) * 45 );
		m_rcCell.right = 160;
		
		dc.DrawText( str, m_rcCell, DT_SINGLELINE|DT_VCENTER|DT_CENTER );
	}//end of for
// end of save for test purpose

}//end of CFontLocator::OnPaint
/////////////////////////////////////////////////////////////////////////////
void CFontLocator::OnVScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar) 
{
	int nCurPos = pScrollBar->GetScrollPos();
	switch( nSBCode )
	{
	case SB_TOP:			// Scroll to far top.
		nCurPos = 1;
		break;
	case SB_LINEUP:			// Scroll one line up.
		nCurPos--;
		break;
	case SB_LINEDOWN:		// Scroll one line down.
		nCurPos++;
		break;
	case SB_PAGEUP:			// Scroll one page up.
		nCurPos -= 100;
		break;
	case SB_PAGEDOWN:		// Scroll one page down.
		nCurPos += 10;
		break;
	case SB_BOTTOM:			// Scroll to far bottom.
		nCurPos = 1000;
		break;
	case SB_THUMBPOSITION:	// Scroll to absolute position. 
	case SB_THUMBTRACK:		// Drag scroll box to specified position. 
		nCurPos = nPos;
		break;
	case SB_ENDSCROLL:		// End scroll
		TRACE0( "CharMap.cpp : OnVScroll - End scroll\n" );
		break;
	}//end of switch - nSBCode

	nCurPos = ( nCurPos < 1 ) ? 1 : nCurPos;
	nCurPos = ( 1000 < nCurPos ) ? 1000 : nCurPos;

	pScrollBar->SetScrollPos(nCurPos);

	if( pScrollBar == (CScrollBar*)GetDlgItem(IDC_VSB_FONT) )
	{	
		;// call FontLocatorScrollPos( nCurPos );
	}
	
	CDialog::OnVScroll(nSBCode, nPos, pScrollBar);
}//end of CFontLocator::OnVScroll
/////////////////////////////////////////////////////////////////////////////
VOID CFontLocator::InitDlgItemText()
{
	IN_TEXT_DATA* txtData = NULL;
	TCHAR	sep[] = _T("\"");
	TCHAR*	ptID;
	TCHAR*	ptTT;
	TCHAR*	ptEnd;
	DWORD	i;

	m_numTxt = LoadTextFromCtl( "\\Util\\FontLocator.ctl", "[Text String]", &txtData );
	if( m_numTxt == 0 )
		return;

	m_hFont = new HFONT[m_numTxt];
	for( i = 0; i < m_numTxt; i++ )
	{
		m_hFont[i] = NULL; // initial m_hFont
		ptID   = _tcstok( txtData[i].szTT, sep );
		ptTT   = _tcstok( NULL, sep );
		ptEnd  = _tcstok( NULL, sep );
		if( ptEnd != 0 )
			*ptEnd = '\0';

		if( NULL != _tcsstr( txtData[i].szTT, _T("IDD_FONT_LOCATOR") ) )
		{
			txtData[i].idTT = IDD_FONT_LOCATOR;			
			m_hFont[i] = ChangeControlFont( m_hWnd, NULL, UILang_UIFont,0, UILang_UIFontSize, FW_NORMAL);
			SetWindowText( (LPCTSTR)ptTT );
		}
		else
			if( NULL != _tcsstr( txtData[i].szTT, _T("IDC_STC_VIEW") ) )
				txtData[i].idTT = IDC_STC_VIEW;
		else
			if( NULL != _tcsstr( txtData[i].szTT, _T("IDC_CK_SERIF_FONT") ) )
				txtData[i].idTT = IDC_CK_SERIF_FONT;
		else
			if( NULL != _tcsstr( txtData[i].szTT, _T("IDC_CK_SANS_SERIF_FONT") ) )
				txtData[i].idTT = IDC_CK_SANS_SERIF_FONT;
		else
			if( NULL != _tcsstr( txtData[i].szTT, _T("IDC_CK_SYMBOL_FONT") ) )
				txtData[i].idTT = IDC_CK_SYMBOL_FONT;
		else
			if( NULL != _tcsstr( txtData[i].szTT, _T("IDOK") ) )
				txtData[i].idTT = IDOK;
		else
			if( NULL != _tcsstr( txtData[i].szTT, _T("IDCANCEL") ) )
				txtData[i].idTT = IDCANCEL;

		SetDlgItemText( (INT)txtData[i].idTT, (LPCTSTR)ptTT );

		if( txtData[i].idTT != IDD_FONT_LOCATOR )
			m_hFont[i] = ChangeControlFont( GetDlgItem(txtData[i].idTT)->m_hWnd, NULL/*m_hFont[i]*/, UILang_UIFont,0, UILang_UIFontSize, FW_NORMAL);			
	}//end of for

	free( txtData );
}//end of CFontLocator::InitDlgItemText()
