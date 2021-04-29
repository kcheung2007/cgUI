// DlgSelEffect.cpp : implementation file
//

#include "stdafx.h"
#include "cgui.h"
#include "Global.h"
#include "ACGS_Inc\\UI_BinMgr.h"
#include "DlgSelEffect.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDlgSelEffect dialog
extern _TCHAR	UILang_UIFont[256];
extern int		UILang_UIFontSize;

CDlgSelEffect::CDlgSelEffect(CWnd* pParent /*=NULL*/) : CDialog(CDlgSelEffect::IDD, pParent)
{
	//{{AFX_DATA_INIT(CDlgSelEffect)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	m_hFont = NULL;
}
CDlgSelEffect::~CDlgSelEffect()
{
	for( DWORD i = 0; i < m_numTxt; i++ )
	{
		if( m_hFont[i] != NULL )
			DeleteObject( (HGDIOBJ)m_hFont[i] );
	}
	if( m_hFont != NULL )
		delete [] m_hFont;
}
void CDlgSelEffect::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDlgSelEffect)	
	DDX_Control(pDX, IDC_VSB_WINBIN, m_vsbEffectBin);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CDlgSelEffect, CDialog)
	//{{AFX_MSG_MAP(CDlgSelEffect)
	ON_WM_VSCROLL()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

////////////////////////////////////////////////////////////////////////////////////////
// CDlgSelEffect message handlers

BOOL CDlgSelEffect::OnInitDialog() 
{
	CDialog::OnInitDialog();

	InitDlgItemText();
	
	m_ctlEffectBin.SubclassDlgItem( IDC_LST_BINWIN, this );
	m_vsbEffectBin.SetScrollRange( 1, 1000 );	// default range
	m_vsbEffectBin.SetScrollPos( 1 );			// default position

	CGS_BinOpen(
		UIBIN_EFFECT,
		m_ctlEffectBin.m_hWnd,
		NULL,
		NULL //01-04-13 i.e. UI_RedrawPageBinThumbTrack function for core to call to tell UI to redraw thumb track position e.g. void UI_RedrawPageBinThumbTrack(double ScrollPos_01);
		);
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}//end of CDlgSelEffect::OnInitDialog
////////////////////////////////////////////////////////////////////////////////////////
void CDlgSelEffect::OnVScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar) 
{
	ASSERT(pScrollBar != NULL);

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
		TRACE0( "DlgSelEffect.cpp : OnVScroll - End scroll\n" );
		break;
	}//end of switch - nSBCode

	nCurPos = ( nCurPos < 1 ) ? 1 : nCurPos;
	nCurPos = ( 1000 < nCurPos ) ? 1000 : nCurPos;

	pScrollBar->SetScrollPos(nCurPos);
	TRACE2( "DlgSelEffect.cpp : nCurPos = %d, nPos = %d\n", nCurPos, nPos );
	
	CGS_BinSetScroll(UIBIN_EFFECT,(double) ((double)nCurPos) / (1000.0f) ); //JRS
	
	CDialog::OnVScroll(nSBCode, nPos, pScrollBar);
}//end of CDlgSelEffect::OnVScroll
/////////////////////////////////////////////////////////////////////////////////////////////
VOID CDlgSelEffect::InitDlgItemText()
{
	IN_TEXT_DATA* txtData = NULL;
	TCHAR	sep[] = _T("\"");
	TCHAR*	ptID;
	TCHAR*	ptTT;
	TCHAR*	ptEnd;
	DWORD	i;

	m_numTxt = LoadTextFromCtl( "\\Util\\DlgSelEffect.ctl", "[Text String]", &txtData );
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

		if( NULL != _tcsstr( txtData[i].szTT, _T("IDD_SEL_EFFECT") ) )
		{
			txtData[i].idTT = IDD_SEL_EFFECT;
			SetWindowText( (LPCTSTR)ptTT );
			goto SkipText;
		}
		else
			if( NULL != _tcsstr( txtData[i].szTT, _T("IDOK") ) )
				txtData[i].idTT = IDOK;

		SetDlgItemText( (INT)txtData[i].idTT, (LPCTSTR)ptTT );
SkipText:
		m_hFont[i] = ChangeControlFont( m_hWnd, NULL, UILang_UIFont,0, UILang_UIFontSize, FW_NORMAL);
	}//end of for

	free( txtData );

}//end of CDlgSelEffect::InitDlgItemText()
/////////////////////////////////////////////////////////////////////////////////////////////
void CDlgSelEffect::OnOK() 
{
	// TODO: Add extra validation here
	
	CDialog::OnOK();
}//end of void CDlgSelEffect::OnOK() 

