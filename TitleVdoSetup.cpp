/* COPYRIGHT NOTICE:
********************************************************
*  Copyright (c) 2000 InnoVision Technology, Inc.      *
*  All rights reserved.                                *
*  PROPRIETARY AND CONFIDENTIAL                        *
*  DO NOT DISTRIBUTE                                   *
********************************************************
*/
// TitleVdoSetup.cpp : implementation file
//

#include "stdafx.h"
#include "cgui.h"
#include "Global.h"
#include "TitleVdoSetup.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CTitleVdoSetup dialog
extern TCHAR	UILang_UIFont[256];
extern int		UILang_UIFontSize;
extern DWORD g_CodePage;
CTitleVdoSetup::CTitleVdoSetup(CWnd* pParent /*=NULL*/) : CDialog(CTitleVdoSetup::IDD, pParent)
{
	//{{AFX_DATA_INIT(CTitleVdoSetup)
	m_edBright		= 0;
	m_edContrast	= 0;
	m_edHDelau		= 0;
	//}}AFX_DATA_INIT
	m_hFontBright	 = NULL;
	m_hFontConstrast = NULL;
	m_hFontDelay	 = NULL;
}
CTitleVdoSetup::~CTitleVdoSetup()
{
	if( m_hFontBright )
		DeleteObject( (HGDIOBJ)m_hFontBright );	
	if( m_hFontConstrast )
	DeleteObject( (HGDIOBJ)m_hFontConstrast );
	if( m_hFontDelay )
		DeleteObject( (HGDIOBJ)m_hFontDelay );

	for( DWORD i = 0; i < m_numTxt; i++ )
	{
		if( m_hFont[i] )
			DeleteObject( (HGDIOBJ)m_hFont[i] );
	}
	if( m_hFont != NULL )
		delete [] m_hFont;
}

void CTitleVdoSetup::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CTitleVdoSetup)
	DDX_Control(pDX, IDC_ED_HDELAY, m_ctlEdHDelay);
	DDX_Control(pDX, IDC_ED_CONSTRAST, m_ctlEdContrast);
	DDX_Control(pDX, IDC_ED_BRIGHT, m_ctlEdBright);
	DDX_Control(pDX, IDC_HSD_HDELAY, m_sdrHDelay);
	DDX_Control(pDX, IDC_HSD_CONTRAST, m_sdrContrast);
	DDX_Control(pDX, IDC_HSD_BRIGHT, m_sdrBright);
	DDX_Control(pDX, IDC_CB_OUT_MODE, m_cbMode);
	DDX_Control(pDX, IDC_CB_OUT_GPIPORT, m_cbGPIPort);
	DDX_Control(pDX, IDC_CB_OUT_FORMAT, m_cbOutFormat);
	DDX_Control(pDX, IDC_CB_IN_FORMAT, m_cbInFormat);
	DDX_Text(pDX, IDC_ED_BRIGHT, m_edBright);
	DDX_Text(pDX, IDC_ED_CONSTRAST, m_edContrast);
	DDX_Text(pDX, IDC_ED_HDELAY, m_edHDelau);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CTitleVdoSetup, CDialog)
	//{{AFX_MSG_MAP(CTitleVdoSetup)
	ON_NOTIFY(UDN_DELTAPOS, IDC_SPN_BRIGHT, OnDeltaposSpnBright)
	ON_NOTIFY(UDN_DELTAPOS, IDC_SPN_CONSTRAST, OnDeltaposSpnConstrast)
	ON_NOTIFY(UDN_DELTAPOS, IDC_SPN_HDELAY, OnDeltaposSpnHdelay)
	ON_BN_CLICKED(IDC_BT_DEFAULT, OnBtDefault)
	ON_EN_CHANGE(IDC_ED_BRIGHT, OnChangeEdBright)
	ON_EN_CHANGE(IDC_ED_CONSTRAST, OnChangeEdConstrast)
	ON_EN_CHANGE(IDC_ED_HDELAY, OnChangeEdHdelay)
	ON_WM_HSCROLL()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CTitleVdoSetup message handlers
/////////////////////////////////////////////////////////////////////////////
BOOL CTitleVdoSetup::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	HFONT hFont = NULL;

	InitDlgItemText();

	// TODO: Add extra initialization here
	InitComboString( _T("\\Util\\VdoSetup.ctl"), _T("[Vdo In Format]"), &m_cbInFormat );
	InitComboString( _T("\\Util\\VdoSetup.ctl"), _T("[Vdo Out Format]"), &m_cbOutFormat );
	InitComboString( _T("\\Util\\VdoSetup.ctl"), _T("[Vdo Mode]"), &m_cbMode );
	InitComboString( _T("\\Util\\VdoSetup.ctl"), _T("[Vdo GPI Port]"), &m_cbGPIPort );

	// ++++++++++++++++++++++++++++++++++++++++++++ Initial spin control
	CSpinButtonCtrl* pSpin = (CSpinButtonCtrl*)GetDlgItem( IDC_SPN_BRIGHT );
	pSpin->SetRange( -128, 128 );
	pSpin = (CSpinButtonCtrl*)GetDlgItem( IDC_SPN_CONSTRAST );
	pSpin->SetRange( -128, 128 );
	pSpin = (CSpinButtonCtrl*)GetDlgItem( IDC_SPN_HDELAY );
	pSpin->SetRange( -128, 128 );

	//+++++++++++++++++++++++++++++++++++++++++++++ Initial Edit control
	m_hFontBright = ChangeControlFont( GetDlgItem( IDC_ED_BRIGHT )->m_hWnd,    hFont, UILang_UIFont,0, UILang_UIFontSize, FW_NORMAL);
	m_hFontConstrast = ChangeControlFont( GetDlgItem( IDC_ED_CONSTRAST )->m_hWnd, hFont, UILang_UIFont,0, UILang_UIFontSize, FW_NORMAL);
	m_hFontDelay = ChangeControlFont( GetDlgItem( IDC_ED_HDELAY )->m_hWnd,    hFont, UILang_UIFont,0, UILang_UIFontSize, FW_NORMAL);

	CEdit* pEdCtrl = (CEdit*)GetDlgItem( IDC_ED_BRIGHT );
	pEdCtrl->SetLimitText( 4 ); // 4 characters of -128
	pEdCtrl = (CEdit*)GetDlgItem( IDC_ED_CONSTRAST );
	pEdCtrl->SetLimitText( 4 ); // 4 characters of -128
	pEdCtrl = (CEdit*)GetDlgItem( IDC_ED_HDELAY );
	pEdCtrl->SetLimitText( 4 ); // 4 characters of -128

	//+++++++++++++++++++++++++++++++++++++++++++++++ Initial radio button
	CheckRadioButton( IDC_RB_NTSC, IDC_RB_PAL, IDC_RB_NTSC );

//++++++++++++++++++++++++++++++++++++++++++++++ Initial Slider control
	m_sdrBright.SetRange( -128, 128, 1 );
	m_sdrContrast.SetRange( -128, 128, 1 );
	m_sdrHDelay.SetRange( -128, 128, 1 );
	m_sdrBright.SetPos( 0 );
	m_sdrContrast.SetPos( 0 );
	m_sdrHDelay.SetPos( 0 );
	m_sdrBright.SetTicFreq( 16 );
	m_sdrContrast.SetTicFreq( 16 );
	m_sdrHDelay.SetTicFreq( 16 );
	
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}//end of CTitleVdoSetup::OnInitDialog
/////////////////////////////////////////////////////////////////////////////
//VOID CTitleVdoSetup::InitComboString()
VOID CTitleVdoSetup::InitComboString( LPTSTR ptFn, LPTSTR ptSection, CComboBox* ptCombo )
{
	IN_TEXT_DATA* txtData = NULL;
	TCHAR	sep[] = _T("\"");
	TCHAR*	ptID;
	TCHAR*	ptTT;
	TCHAR*	ptEnd;

	CHAR		fn[MAX_PATH];
	CHAR		section[MAX_PATH];

	UnicodeToMultiByte( CP_ACP, ptFn, fn );
	UnicodeToMultiByte( CP_ACP, ptSection, section );
	DWORD numTxt = LoadTextFromCtl( fn, section, &txtData );
	if( numTxt == 0 )
		return;

	for( DWORD i = 0; i < numTxt; i++ )
	{
		ptID   = _tcstok( txtData[i].szTT, sep );
		ptTT   = _tcstok( NULL, sep );
		ptEnd  = _tcstok( NULL, sep );
		if( ptEnd != 0 )
			*ptEnd = '\0';

		ptCombo->AddString( (LPCTSTR)ptTT );		
	}//end of for
	ptCombo->SetCurSel( 0 );

	free( txtData );
}//end of CTitleVdoSetup::InitComboString()
/////////////////////////////////////////////////////////////////////////////
void CTitleVdoSetup::OnDeltaposSpnBright(NMHDR* pNMHDR, LRESULT* pResult) 
{
	NM_UPDOWN* pNMUpDown = (NM_UPDOWN*)pNMHDR;
	m_sdrBright.SetPos( pNMUpDown->iPos );
	*pResult = 0;
}//end of CTitleVdoSetup::OnDeltaposSpnBright
/////////////////////////////////////////////////////////////////////////////
void CTitleVdoSetup::OnDeltaposSpnConstrast(NMHDR* pNMHDR, LRESULT* pResult) 
{
	NM_UPDOWN* pNMUpDown = (NM_UPDOWN*)pNMHDR;
	
	*pResult = 0;
}//end of CTitleVdoSetup::OnDeltaposSpnConstrast
/////////////////////////////////////////////////////////////////////////////
void CTitleVdoSetup::OnDeltaposSpnHdelay(NMHDR* pNMHDR, LRESULT* pResult) 
{
	NM_UPDOWN* pNMUpDown = (NM_UPDOWN*)pNMHDR;
	// TODO: Add your control notification handler code here
	
	*pResult = 0;
}//end of CTitleVdoSetup::OnDeltaposSpnHdelay
/////////////////////////////////////////////////////////////////////////////
void CTitleVdoSetup::OnBtDefault() 
{
	// TODO: Add your control notification handler code here
	
}//end of CTitleVdoSetup::OnBtDefault
/////////////////////////////////////////////////////////////////////////////
// CHECK the selection change on the combo box
void CTitleVdoSetup::OnOK() 
{
	CDialog::OnOK();

}//end of CTitleVdoSetup::OnOK() 
/////////////////////////////////////////////////////////////////////////////
void CTitleVdoSetup::OnCancel() 
{
	CDialog::OnCancel();
}//end of CTitleVdoSetup::OnCancel
/////////////////////////////////////////////////////////////////////////////
void CTitleVdoSetup::OnChangeEdBright() 
{
	TCHAR buf[4];
	if( !IsWindow(m_ctlEdBright.m_hWnd) )
		return;

	m_ctlEdBright.GetLine( 0, buf, 4 );
	m_sdrBright.SetPos( _ttoi( buf ) );
   	
}//end of CTitleVdoSetup::OnChangeEdBright
/////////////////////////////////////////////////////////////////////////////
void CTitleVdoSetup::OnChangeEdConstrast() 
{
	// TODO: Add your control notification handler code here
	TCHAR buf[4];
	if( !IsWindow(m_ctlEdContrast.m_hWnd) )
		return;

	m_ctlEdContrast.GetLine( 0, buf, 4 );
	m_sdrContrast.SetPos( _ttoi( buf ) );
	
}//end of CTitleVdoSetup::OnChangeEdConstrast
/////////////////////////////////////////////////////////////////////////////
void CTitleVdoSetup::OnChangeEdHdelay() 
{
	// TODO: Add your control notification handler code here
	TCHAR buf[4];
	if( !IsWindow(m_ctlEdHDelay.m_hWnd) )
		return;

	m_ctlEdHDelay.GetLine( 0, buf, 4 );
	m_sdrHDelay.SetPos( _ttoi( buf ) );
	
}//end of CTitleVdoSetup::OnChangeEdHdelay
/////////////////////////////////////////////////////////////////////////////
void CTitleVdoSetup::OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar) 
{
	// TODO: Add your message handler code here and/or call default
	ASSERT(pScrollBar != NULL);

	TRACE1( "TitleVdoSetup.cpp : OnHScroll - nPos = %d\n", nPos );
	if( pScrollBar == (CScrollBar*)GetDlgItem(IDC_HSD_BRIGHT) )
		SetDlgItemInt(IDC_ED_BRIGHT, m_sdrBright.GetPos(), 1 );
	else
		if( pScrollBar == (CScrollBar*)GetDlgItem(IDC_HSD_CONTRAST) )
			SetDlgItemInt(IDC_ED_CONSTRAST, m_sdrContrast.GetPos(), 1 );
	else
		if( pScrollBar == (CScrollBar*)GetDlgItem(IDC_HSD_HDELAY) )
			SetDlgItemInt(IDC_ED_HDELAY, m_sdrHDelay.GetPos(), 1 );
		
	CDialog::OnHScroll(nSBCode, nPos, pScrollBar);
}//end of CTitleVdoSetup::OnHScroll
//////////////////////////////////////////////////////////////////////////////////
VOID CTitleVdoSetup::InitDlgItemText()
{
	IN_TEXT_DATA* txtData = NULL;
	TCHAR	sep[] = _T("\"");
	TCHAR*	ptID;
	TCHAR*	ptTT;
	TCHAR*	ptEnd;

	m_numTxt = LoadTextFromCtl( "\\Util\\VdoSetup.ctl", "[Tooltip]", &txtData );
	if( m_numTxt == 0 )
		return;

	m_hFont = new HFONT[m_numTxt];
	for( DWORD i = 0; i < m_numTxt; i++ )
	{
		m_hFont[i] = NULL; // initial m_hFont
		ptID   = _tcstok( txtData[i].szTT, sep );
		ptTT   = _tcstok( NULL, sep );
		ptEnd  = _tcstok( NULL, sep );
		if( ptEnd != 0 )
			*ptEnd = '\0';
		
		if( NULL != _tcsstr( txtData[i].szTT, _T("IDD_TITLE_VDO_SETUP") ))
		{
			m_hFont[i] = ChangeControlFont( m_hWnd, NULL, UILang_UIFont,0, UILang_UIFontSize, FW_NORMAL);
			SetWindowText( (TCHAR*)ptTT );
		}
		else
			if( NULL != _tcsstr( txtData[i].szTT, _T("IDC_STC_VDO_INPUT") ))
			{
				m_hFont[i] = ChangeControlFont( GetDlgItem(IDC_STC_VDO_INPUT)->m_hWnd, NULL, UILang_UIFont,0, UILang_UIFontSize, FW_NORMAL);
				SetDlgItemText( IDC_STC_VDO_INPUT, (TCHAR*)ptTT );
			}
		else
			if( NULL != _tcsstr( txtData[i].szTT, _T("IDC_VIDEO_OUTPUT_STATIC") ))
			{
				m_hFont[i] = ChangeControlFont( GetDlgItem(IDC_VIDEO_OUTPUT_STATIC)->m_hWnd, NULL, UILang_UIFont,0, UILang_UIFontSize, FW_NORMAL);
				SetDlgItemText( IDC_VIDEO_OUTPUT_STATIC, (TCHAR*)ptTT );
			}
		else
			if( NULL != _tcsstr( txtData[i].szTT, _T("IDC_STC_VDO_FORMAT") ))
			{
				m_hFont[i] = ChangeControlFont( GetDlgItem(IDC_STC_VDO_FORMAT)->m_hWnd, NULL, UILang_UIFont,0, UILang_UIFontSize, FW_NORMAL);
				SetDlgItemText( IDC_STC_VDO_FORMAT, (TCHAR*)ptTT );
			}
		else
			if( NULL != _tcsstr( txtData[i].szTT, _T("IDC_STC_BRIGHT") ))
			{
				m_hFont[i] = ChangeControlFont( GetDlgItem(IDC_STC_BRIGHT)->m_hWnd, NULL, UILang_UIFont,0, UILang_UIFontSize, FW_NORMAL);
				SetDlgItemText( IDC_STC_BRIGHT, (TCHAR*)ptTT );
			}
		else
			if( NULL != _tcsstr( txtData[i].szTT, _T("IDC_STC_CONTRAST") ))
			{
				m_hFont[i] = ChangeControlFont( GetDlgItem(IDC_STC_CONTRAST)->m_hWnd, NULL, UILang_UIFont,0, UILang_UIFontSize, FW_NORMAL);
				SetDlgItemText( IDC_STC_CONTRAST, (TCHAR*)ptTT );
			}
		else
			if( NULL != _tcsstr( txtData[i].szTT, _T("IDC_STC_H_DELAY") ))
			{
				m_hFont[i] = ChangeControlFont( GetDlgItem(IDC_STC_H_DELAY)->m_hWnd, NULL, UILang_UIFont,0, UILang_UIFontSize, FW_NORMAL);
				SetDlgItemText( IDC_STC_H_DELAY, (TCHAR*)ptTT );
			}
		else
			if( NULL != _tcsstr( txtData[i].szTT, _T("IDC_STC_FORMAT") ))
			{
				m_hFont[i] = ChangeControlFont( GetDlgItem(IDC_STC_FORMAT)->m_hWnd, NULL, UILang_UIFont,0, UILang_UIFontSize, FW_NORMAL);
				SetDlgItemText( IDC_STC_FORMAT, (TCHAR*)ptTT );
			}
		else
			if( NULL != _tcsstr( txtData[i].szTT, _T("IDC_STC_MODE") ))
			{
				m_hFont[i] = ChangeControlFont( GetDlgItem(IDC_STC_MODE)->m_hWnd, NULL, UILang_UIFont,0, UILang_UIFontSize, FW_NORMAL);
				SetDlgItemText( IDC_STC_MODE, (TCHAR*)ptTT );
			}
		else
			if( NULL != _tcsstr( txtData[i].szTT, _T("IDC_STC_GPIPORT") ))
			{
				m_hFont[i] = ChangeControlFont( GetDlgItem(IDC_STC_GPIPORT)->m_hWnd, NULL, UILang_UIFont,0, UILang_UIFontSize, FW_NORMAL);
				SetDlgItemText( IDC_STC_GPIPORT, (TCHAR*)ptTT );
			}
		else
			if( NULL != _tcsstr( txtData[i].szTT, _T("IDC_BT_DEFAULT") ))
			{
				m_hFont[i] = ChangeControlFont( GetDlgItem(IDC_BT_DEFAULT)->m_hWnd, NULL, UILang_UIFont,0, UILang_UIFontSize, FW_NORMAL);
				SetDlgItemText( IDC_BT_DEFAULT, (TCHAR*)ptTT );
			}
		else
			if( NULL != _tcsstr( txtData[i].szTT, _T("IDC_CK_FLICKER") ))
			{
				m_hFont[i] = ChangeControlFont( GetDlgItem(IDC_CK_FLICKER)->m_hWnd, NULL, UILang_UIFont,0, UILang_UIFontSize, FW_NORMAL);
				SetDlgItemText( IDC_CK_FLICKER, (TCHAR*)ptTT );
			}
		else
			if( NULL != _tcsstr( txtData[i].szTT, _T("IDOK") ))
			{
				m_hFont[i] = ChangeControlFont( GetDlgItem(IDOK)->m_hWnd, NULL, UILang_UIFont,0, UILang_UIFontSize, FW_NORMAL);
				SetDlgItemText( IDOK, (TCHAR*)ptTT );
			}
		else
			if( NULL != _tcsstr( txtData[i].szTT, _T("IDCANCEL") ))
			{
				m_hFont[i] = ChangeControlFont( GetDlgItem(IDCANCEL)->m_hWnd, NULL, UILang_UIFont,0, UILang_UIFontSize, FW_NORMAL);
				SetDlgItemText( IDCANCEL, (TCHAR*)ptTT );
			}
	}//end of for

	free( txtData );

}//end of CTitleVdoSetup::InitDlgItemText()
