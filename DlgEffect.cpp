/* COPYRIGHT NOTICE:
********************************************************
********************************************************
*/
// DlgEffect.cpp : implementation file
//

#include "stdafx.h"
#include "cgUI.h"
#include "Global.h"
#include "DlgEffect.h"
#include "DlgSelEffect.h"
#include "ACGS_Inc\\CGServerDll.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDlgEffect dialog
extern TCHAR UILang_UIFont[256];
extern int	 UILang_UIFontSize;

CDlgEffect::CDlgEffect(CWnd* pParent /*=NULL*/)	: CDialog(CDlgEffect::IDD, pParent)
{
	//{{AFX_DATA_INIT(CDlgEffect)
	m_dwEdMm = 0;
	m_dwEdSc = 0;
	m_dwEdFm = 0;
	m_dwEdSpeed = 0;
	m_dwEdStart = 0;
	m_dwEdEnd = 0;
	//}}AFX_DATA_INIT
	m_hFont = NULL;
}

CDlgEffect::~CDlgEffect()
{
	for( DWORD i = 0; i < m_numTxt; i++ )
	{
		if( m_hFont[i] != NULL )
			DeleteObject( (HGDIOBJ)m_hFont[i] );
	}
	if( m_hFont != NULL )
		delete [] m_hFont;
}
void CDlgEffect::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDlgEffect)
	DDX_Text(pDX, IDC_ED_MM, m_dwEdMm);
	DDV_MinMaxDWord(pDX, m_dwEdMm, 0, 99);
	DDX_Text(pDX, IDC_ED_SC, m_dwEdSc);
	DDV_MinMaxDWord(pDX, m_dwEdSc, 0, 59);
	DDX_Text(pDX, IDC_ED_FM, m_dwEdFm);
	DDV_MinMaxDWord(pDX, m_dwEdFm, 0, 29);
	DDX_Text(pDX, IDC_ED_SPD, m_dwEdSpeed);
	DDV_MinMaxDWord(pDX, m_dwEdSpeed, 0, 9);
	DDX_Text(pDX, IDC_ED_START_PG, m_dwEdStart);
	DDX_Text(pDX, IDC_ED_END_PG, m_dwEdEnd);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CDlgEffect, CDialog)
	//{{AFX_MSG_MAP(CDlgEffect)
	ON_BN_CLICKED(IDC_BT_PLAY_PROJ, OnBtPlayProj)
	ON_BN_CLICKED(IDC_BT_TAKE, OnBtTake)
	ON_BN_CLICKED(IDC_BT_FADE_VDO, OnBtFadeToVdo)
	ON_BN_CLICKED(IDC_BT_LIVE_VDO, OnBtLiveVdo)
	ON_BN_CLICKED(IDC_RB_ALL_PAGE, OnRbAllPage)
	ON_BN_CLICKED(IDC_RB_PAGE, OnRbPage)
	ON_NOTIFY(UDN_DELTAPOS, IDC_SPN_FM, OnDeltaposSpnFm)
	ON_NOTIFY(UDN_DELTAPOS, IDC_SPN_MM, OnDeltaposSpnMm)
	ON_NOTIFY(UDN_DELTAPOS, IDC_SPN_SC, OnDeltaposSpnSc)
	ON_NOTIFY(UDN_DELTAPOS, IDC_SPN_SPEED, OnDeltaposSpnSpeed)
	ON_BN_CLICKED(IDC_STC_PIC, OnStcPicClick)
	ON_BN_CLICKED(IDC_BT_STOP_PLAY, OnBtStopPlay)
	ON_WM_PAINT()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDlgEffect message handlers
/////////////////////////////////////////////////////////////////////////////
void CDlgEffect::OnOK() 
{
//	Route the OK message that close the dialog
	TRACE0("DlgEffect.cpp : CDlgEffect::OnOk\n");
	TRACE3("\tm_dwEdMm = %d, m_dwEdSc = %d, m_dwEdFm = %d\n", m_dwEdMm, m_dwEdSc, m_dwEdFm );
	TRACE2("\tm_dwEdStart = %d, m_dwEdEnd = %d\n", m_dwEdStart, m_dwEdEnd );

	DWORD	edValue = GetDlgItemInt( IDC_ED_MM, NULL, 0 );
	if( edValue != m_dwEdMm )
	{
		m_dwEdMm = edValue;
		TRACE(_T("\t m_dwEdMm = %d\n"), m_dwEdMm );
		CGS_SetValDbl(PAGE_EFFECT_HOLD_MINUTES, m_dwEdMm);
	}
	edValue = GetDlgItemInt( IDC_ED_SC, NULL, 0 );
	if( edValue != m_dwEdSc )
	{
		m_dwEdSc = edValue;
		TRACE(_T("\t m_dwEdSc = %d\n"), m_dwEdSc );
		CGS_SetValDbl(PAGE_EFFECT_HOLD_SECONDS, m_dwEdSc);
	}
	edValue = GetDlgItemInt( IDC_ED_FM, NULL, 0 );
	if( edValue != m_dwEdFm )
	{
		m_dwEdFm = edValue;
		TRACE(_T("\t m_dwEdFm = %d\n"), m_dwEdFm );
		CGS_SetValDbl(PAGE_EFFECT_HOLD_FRAMES, m_dwEdFm);
	}

	edValue = GetDlgItemInt( IDC_ED_START_PG, NULL, 0 ); // starting page
	if( edValue != m_dwEdFm )
	{
		m_dwEdStart = edValue;
		TRACE(_T("\t m_dwEdStart = %d\n"), m_dwEdStart );
	}

	edValue = GetDlgItemInt( IDC_ED_END_PG, NULL, 0 ); // starting page
	if( edValue != m_dwEdEnd )
	{
		m_dwEdEnd = edValue;
		TRACE(_T("\t m_dwEdStart = %d\n"), m_dwEdEnd );
	}

	AfxGetMainWnd()->SetFocus();

}//end of CDlgEffect::OnOK()
/////////////////////////////////////////////////////////////////////////////
void CDlgEffect::OnCancel() 
{
	// capture cancel message
}//end of CDlgEffect::OnCancel()
/////////////////////////////////////////////////////////////////////////////
BOOL CDlgEffect::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: Add extra initialization here	
	// ++++++++++++++++++++++++++++++++++++++++++++ Initial spin control
	CSpinButtonCtrl* pSpin = (CSpinButtonCtrl*)GetDlgItem( IDC_SPN_MM );
	pSpin->SetRange( 0, 99 );
	//save for ref.	pSpin->SetPos((int) (m_dSpin * 10.0));
	pSpin = (CSpinButtonCtrl*)GetDlgItem( IDC_SPN_SC );
	pSpin->SetRange( 0, 59 );
	pSpin = (CSpinButtonCtrl*)GetDlgItem( IDC_SPN_FM );
	pSpin->SetRange( 0, 29 );
	pSpin = (CSpinButtonCtrl*)GetDlgItem( IDC_SPN_SPEED );
	pSpin->SetRange( 0, 9 );

	//+++++++++++++++++++++++++++++++++++++++++++++ Initial Edit control
	CEdit* pEdCtrl = (CEdit*)GetDlgItem( IDC_ED_MM );
	pEdCtrl->SetLimitText( 2 ); // 2 characters of 99
	SetDlgItemInt(IDC_ED_MM, (int)CGS_GetValDbl(PAGE_EFFECT_HOLD_MINUTES), 0 );
	pEdCtrl = (CEdit*)GetDlgItem( IDC_ED_SC );
	pEdCtrl->SetLimitText( 2 ); // 2 characters of 59
	SetDlgItemInt(IDC_ED_SC, (int)CGS_GetValDbl(PAGE_EFFECT_HOLD_SECONDS), 0 );
	pEdCtrl = (CEdit*)GetDlgItem( IDC_ED_FM );
	pEdCtrl->SetLimitText( 2 ); // 2 characters of 29
	SetDlgItemInt(IDC_ED_FM, (int)CGS_GetValDbl(PAGE_EFFECT_HOLD_FRAMES), 0 );
	pEdCtrl = (CEdit*)GetDlgItem( IDC_ED_SPD );
	pEdCtrl->SetLimitText( 1 ); // 1 characters of 9
	SetDlgItemInt(IDC_ED_SPD, (int)CGS_GetValDbl(PAGE_IN_EFFECT_SPEED), 0 );

	//+++++++++++++++++++++++++++++++++++++++++++++++ Initial radio button
	CheckRadioButton( IDC_RB_ALL_PAGE, IDC_RB_PAGE, IDC_RB_ALL_PAGE );

	// ++++++++++++++++++++++++++++++++++++++++ Create the ToolTip control
	m_tooltip.Create(this);
	m_tooltip.Activate(TRUE);

	InitDlgItemTextNTooltip(); // seting both tooltip and dialog item text

	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}//end of CDlgEffect::OnInitDialog

////////////////////////////////////////////////////////////////////////////////////////
void CDlgEffect::OnBtPlayProj() 
{
	TRACE0( "DlgEffect.cpp : OnBtPlayProj - button click\n" );

	CGS_Action( CGSA_PLAYER_PLAY_PROJECT );
}//end of CDlgEffect::OnBtPlayProj
////////////////////////////////////////////////////////////////////////////////////////
void CDlgEffect::OnBtStopPlay() 
{
	CGS_Action( CGSA_PLAYER_CANCEL_PLAYBACK );
	
}//end of CDlgEffect::OnBtStopPlay() 
////////////////////////////////////////////////////////////////////////////////////////
void CDlgEffect::OnBtTake() 
{
	CGS_Action( CGSA_PLAYER_SINGLE_STEP );
}//end of CDlgEffect::OnBtTake
////////////////////////////////////////////////////////////////////////////////////////
void CDlgEffect::OnBtFadeToVdo() 
{
	CGS_Action( CGSA_PLAYER_FADE_TOGGLE );
}//end of CDlgEffect::OnBtFadeToVdo
////////////////////////////////////////////////////////////////////////////////////////
void CDlgEffect::OnBtLiveVdo() 
{
	CGS_Action( CGSA_PLAYER_SHOW_LIVE_VIDEO );
}//end of CDlgEffect::OnBtLiveVdo
////////////////////////////////////////////////////////////////////////////////////////
// All pages radio buttom was selected, disable the starting/ending page edit box
void CDlgEffect::OnRbAllPage() 
{	
	CEdit* pEdCtrl = (CEdit*)GetDlgItem( IDC_ED_START_PG );
	pEdCtrl->EnableWindow( 0 ); // disable edit box

	pEdCtrl = (CEdit*)GetDlgItem( IDC_ED_END_PG );
	pEdCtrl->EnableWindow( 0 ); // disable edit box
}//end of CDlgEffect::OnRbAllPage
////////////////////////////////////////////////////////////////////////////////////////
// Page range radio button was selected, enable the starting/ending page edit box
void CDlgEffect::OnRbPage() 
{	
	CEdit* pEdCtrl = (CEdit*)GetDlgItem( IDC_ED_START_PG );
	pEdCtrl->EnableWindow( 1 ); // disable edit box

	pEdCtrl = (CEdit*)GetDlgItem( IDC_ED_END_PG );
	pEdCtrl->EnableWindow( 1 ); // disable edit box
}//end of CDlgEffect::OnRbPage
////////////////////////////////////////////////////////////////////////////////////////
// Set Focus Only
void CDlgEffect::OnDeltaposSpnFm(NMHDR* pNMHDR, LRESULT* pResult) 
{
	NM_UPDOWN* pNMUpDown = (NM_UPDOWN*)pNMHDR;
	// TODO: Add your control notification handler code here
	int val = pNMUpDown->iPos+pNMUpDown->iDelta;
	CGS_SetValDbl(PAGE_EFFECT_HOLD_FRAMES, max(0,val) );
	AfxGetMainWnd()->SetFocus();
	*pResult = 0;
}//end of CDlgEffect::OnDeltaposSpnFm
////////////////////////////////////////////////////////////////////////////////////////
// Set Focus Only
void CDlgEffect::OnDeltaposSpnMm(NMHDR* pNMHDR, LRESULT* pResult) 
{
	NM_UPDOWN* pNMUpDown = (NM_UPDOWN*)pNMHDR;
	// TODO: Add your control notification handler code here
	int val = pNMUpDown->iPos+pNMUpDown->iDelta;
	CGS_SetValDbl(PAGE_EFFECT_HOLD_MINUTES, max(0,val) );
	AfxGetMainWnd()->SetFocus();
	*pResult = 0;
}//end of CDlgEffect::OnDeltaposSpnMm
////////////////////////////////////////////////////////////////////////////////////////
// Set Focus Only
void CDlgEffect::OnDeltaposSpnSc(NMHDR* pNMHDR, LRESULT* pResult) 
{
	NM_UPDOWN* pNMUpDown = (NM_UPDOWN*)pNMHDR;
	// TODO: Add your control notification handler code here
	int val = pNMUpDown->iPos+pNMUpDown->iDelta;
	CGS_SetValDbl(PAGE_EFFECT_HOLD_SECONDS, max(0,val));
	AfxGetMainWnd()->SetFocus();
	*pResult = 0;
}//end of CDlgEffect::OnDeltaposSpnSc
////////////////////////////////////////////////////////////////////////////////////////
// Set Focus Only
void CDlgEffect::OnDeltaposSpnSpeed(NMHDR* pNMHDR, LRESULT* pResult) 
{
	NM_UPDOWN* pNMUpDown = (NM_UPDOWN*)pNMHDR;
	// TODO: Add your control notification handler code here
	int val = pNMUpDown->iPos+pNMUpDown->iDelta;
	CGS_SetValDbl(PAGE_IN_EFFECT_SPEED, max(0,val));
	AfxGetMainWnd()->SetFocus();
	*pResult = 0;
}//end of CDlgEffect::OnDeltaposSpnSpeed
//////////////////////////////////////////////////////////////////////////////////////////////
BOOL CDlgEffect::PreTranslateMessage(MSG* pMsg)
{
	// Let the ToolTip process this message.
	m_tooltip.RelayEvent(pMsg);

	return CDialog::PreTranslateMessage(pMsg);	// CG: This was added by the ToolTips component.
}
//////////////////////////////////////////////////////////////////////////////////////////////
// Set the dialog item text and tooltip control. Do in this way for reducing multiple 
// looping call. And maintain the flexibility.
VOID CDlgEffect::InitDlgItemTextNTooltip()
{
	IN_TEXT_DATA* txtData = NULL;
	TCHAR	sep[] = _T("\"");
	TCHAR*	ptID;
	TCHAR*	ptTT;
	TCHAR*	ptEnd;

	m_numTxt = LoadTextFromCtl( "\\Util\\DlgEffect.ctl", "[Tooltip]", &txtData );
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

		if( NULL != _tcsstr( txtData[i].szTT, _T("IDC_STC_HOLD_TIME") ) )
			txtData[i].idTT = IDC_STC_HOLD_TIME;
		else
			if( NULL != _tcsstr( txtData[i].szTT, _T("IDC_STC_SPEED") ) )
				txtData[i].idTT = IDC_STC_SPEED;
		else
			if( NULL != _tcsstr( txtData[i].szTT, _T("IDC_ED_MM") ) )
			{
				txtData[i].idTT = IDC_ED_MM;
				goto SKIP_TEXT;
			}
		else
			if( NULL != _tcsstr( txtData[i].szTT, _T("IDC_ED_SC") ) )
			{
				txtData[i].idTT = IDC_ED_SC;
				goto SKIP_TEXT;
			}
		else
			if( NULL != _tcsstr( txtData[i].szTT, _T("IDC_ED_FM") ) )
			{
				txtData[i].idTT = IDC_ED_FM;
				goto SKIP_TEXT;
			}
		else
			if( NULL != _tcsstr( txtData[i].szTT, _T("IDC_ED_SPD") ) )
			{
				txtData[i].idTT = IDC_ED_SPD;
				goto SKIP_TEXT;
			}
		else
			if( NULL != _tcsstr( txtData[i].szTT, _T("IDC_ED_START_PG") ) )
			{
				txtData[i].idTT = IDC_ED_START_PG;
				goto SKIP_TEXT;
			}
		else
			if( NULL != _tcsstr( txtData[i].szTT, _T("IDC_ED_END_PG") ) )
			{
				txtData[i].idTT = IDC_ED_END_PG;
				goto SKIP_TEXT;
			}
		else
			if( NULL != _tcsstr( txtData[i].szTT, _T("IDC_BT_PLAY_PROJ") ) )
				txtData[i].idTT = IDC_BT_PLAY_PROJ;
		else
			if( NULL != _tcsstr( txtData[i].szTT, _T("IDC_BT_STOP_PLAY") ) )
				txtData[i].idTT = IDC_BT_STOP_PLAY;
		else
			if( NULL != _tcsstr( txtData[i].szTT, _T("IDC_BT_TAKE") ) )
				txtData[i].idTT = IDC_BT_TAKE;
		else
			if( NULL != _tcsstr( txtData[i].szTT, _T("IDC_BT_FADE_VDO") ) )
				txtData[i].idTT = IDC_BT_FADE_VDO;
		else
			if( NULL != _tcsstr( txtData[i].szTT, _T("IDC_BT_LIVE_VDO") ) )
				txtData[i].idTT = IDC_BT_LIVE_VDO;
		else
			if( NULL != _tcsstr( txtData[i].szTT, _T("IDC_CK_GPI") ) )
				txtData[i].idTT = IDC_CK_GPI;
		else
			if( NULL != _tcsstr( txtData[i].szTT, _T("IDC_CK_LOOP") ) )
				txtData[i].idTT = IDC_CK_LOOP;
		else
			if( NULL != _tcsstr( txtData[i].szTT, _T("IDC_RB_ALL_PAGE") ) )
				txtData[i].idTT = IDC_RB_ALL_PAGE;
		else
			if( NULL != _tcsstr( txtData[i].szTT, _T("IDC_RB_PAGE") ) )
				txtData[i].idTT = IDC_RB_PAGE;

		SetDlgItemText( txtData[i].idTT, (LPCTSTR)ptTT );
		m_hFont[i] = ChangeControlFont( GetDlgItem(txtData[i].idTT)->m_hWnd, NULL, UILang_UIFont,0, UILang_UIFontSize, FW_NORMAL);

SKIP_TEXT:
		_tcscpy( txtData[i].szTT, (TCHAR*)txtData[i].szTT );
		if( NULL != GetDlgItem(txtData[i].idTT) )
			m_tooltip.AddTool( GetDlgItem(txtData[i].idTT), (TCHAR*)ptTT);
	}//end of for

//	delete txtData;
	free( txtData );
}//end of CDlgEffect::InitDlgItemTextNTooltip
//////////////////////////////////////////////////////////////////////////////////////////////////////////
VOID CDlgEffect::DoValueUpdate()
{
#if  EFFECT //#if EFFECT  added by JRS 00-12-20, was crashing if EFFECT was disabled and select a font
	SetDlgItemInt(IDC_ED_MM, (int)CGS_GetValDbl(PAGE_EFFECT_HOLD_MINUTES), 0 );
	SetDlgItemInt(IDC_ED_SC, (int)CGS_GetValDbl(PAGE_EFFECT_HOLD_SECONDS), 0 );
	SetDlgItemInt(IDC_ED_FM, (int)CGS_GetValDbl(PAGE_EFFECT_HOLD_FRAMES),  0 );
	SetDlgItemInt(IDC_ED_SPD,(int)CGS_GetValDbl(PAGE_IN_EFFECT_SPEED),     0 );

#endif
}//end of CDlgEffect::DoValueUpdate()
///////////////////////////////////////////////////////////////////////////////////////////////////
// When the picon was click, all action done here
void CDlgEffect::OnStcPicClick() 
{
	int nRet = -1;
	CDlgSelEffect dlg;
	
	nRet = dlg.DoModal();   
    switch ( nRet )	// Handle the return value from DoModal
    {
    case -1: 
		AfxMessageBox(_T("Dialog box could not be created!"));
        break;
    case IDABORT:
        // Do something
        break;
    case IDOK:
        UpdateAllValue();
        break;
    case IDCANCEL:
        // Do something
        break;
    default:
        // Do something
        break;
    };	

}//end of CDlgEffect::OnStcPicClick() 
////////////////////////////////////////////////////////////////////////////////////////
VOID CDlgEffect::UpdateAllValue()
{
	//Update Edit control
	SetDlgItemInt(IDC_ED_MM, (int)CGS_GetValDbl(PAGE_EFFECT_HOLD_MINUTES), 0 );
	SetDlgItemInt(IDC_ED_SC, (int)CGS_GetValDbl(PAGE_EFFECT_HOLD_SECONDS), 0 );
	SetDlgItemInt(IDC_ED_FM, (int)CGS_GetValDbl(PAGE_EFFECT_HOLD_FRAMES),  0 );
	SetDlgItemInt(IDC_ED_SPD,(int)CGS_GetValDbl(PAGE_IN_EFFECT_SPEED),     0 );
}//end of CDlgEffect::UpdateAllValue()
////////////////////////////////////////////////////////////////////////////////////////
void CDlgEffect::OnPaint() 
{
	CPaintDC dc(this); // device context for painting
	CGS_EditUpdateCurEffectPicon( (DWORD)GetDlgItem(IDC_STC_PIC)->m_hWnd, 2 );
}//end of void CDlgEffect::OnPaint() 
