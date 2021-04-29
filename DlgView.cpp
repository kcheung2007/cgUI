// DlgView.cpp : implementation file
//

#include "stdafx.h"
#include "cgui.h"
#include "DlgView.h"
#include "Global.h"
#include "PageSetupDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDlgView dialog
extern _TCHAR	UILang_UIFont[256];
extern int		UILang_UIFontSize;

CDlgView::CDlgView(CWnd* pParent /*=NULL*/)	: CDialog(CDlgView::IDD, pParent)
{
	//{{AFX_DATA_INIT(CDlgView)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	m_hFont = NULL;
}

CDlgView::~CDlgView()
{
	for( DWORD i = 0; i < m_numTxt; i++ )
	{
		if( m_hFont[i] != NULL )
			DeleteObject( (HGDIOBJ)m_hFont[i] );
	}
	if( m_hFont != NULL )
		delete [] m_hFont;
}

void CDlgView::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDlgView)
	DDX_Control(pDX, IDC_SPN_MON_GAMMA, m_spnGamma);
	DDX_Control(pDX, IDC_EDMON_GARMMA, m_ctlEdGamma);
	DDX_Control(pDX, IDC_CK_TAB, m_ckTab);
	DDX_Control(pDX, IDC_CK_SHOW_A_CHANNEL, m_ckShowAChannel);
	DDX_Control(pDX, IDC_CK_SEL_BOX, m_ckSelBox);
	DDX_Control(pDX, IDC_CK_SAFE_TITLE, m_ckSafeTtile);
	DDX_Control(pDX, IDC_CK_SAFE_ACTION, m_ckSafeAct);
	DDX_Control(pDX, IDC_CK_MONITOR_GAMMA, m_ckMonGamma);
	DDX_Control(pDX, IDC_CK_LNE_MARGIN, m_ckLneMargin);
	DDX_Control(pDX, IDC_CK_GRIDS, m_ckGrid);
	DDX_Control(pDX, IDC_CK_CENTER_POINT, m_ckCenterPoint);
	DDX_Control(pDX, IDC_CK_BASELINE, m_ckBaseline);
	DDX_Control(pDX, IDC_CK_ASPECT_CORRECTION, m_ckAspectCorrect);
	DDX_Control(pDX, IDC_BT_TAB, m_btTab);
	DDX_Control(pDX, IDC_BT_SETTING, m_btSetting);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CDlgView, CDialog)
	//{{AFX_MSG_MAP(CDlgView)
	ON_BN_CLICKED(IDC_BT_TAB, OnBtTab)
	ON_BN_CLICKED(IDC_BT_SETTING, OnBtSetting)
	ON_NOTIFY(UDN_DELTAPOS, IDC_SPN_MON_GAMMA, OnDeltaposSpnMonGamma)
	ON_BN_CLICKED(IDC_CK_SAFE_TITLE, OnCkSafeTitle)
	ON_BN_CLICKED(IDC_CK_SAFE_ACTION, OnCkSafeAction)
	ON_BN_CLICKED(IDC_CK_CENTER_POINT, OnCkCenterPoint)
	ON_BN_CLICKED(IDC_CK_TAB, OnCkTab)
	ON_BN_CLICKED(IDC_CK_GRIDS, OnCkGrids)
	ON_BN_CLICKED(IDC_CK_SEL_BOX, OnCkSelBox)
	ON_BN_CLICKED(IDC_CK_LNE_MARGIN, OnCkLneMargin)
	ON_BN_CLICKED(IDC_CK_BASELINE, OnCkBaseline)
	ON_BN_CLICKED(IDC_CK_ASPECT_CORRECTION, OnCkAspectCorrection)
	ON_BN_CLICKED(IDC_CK_SHOW_A_CHANNEL, OnCkShowAChannel)
	ON_BN_CLICKED(IDC_CK_MONITOR_GAMMA, OnCkMonitorGamma)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDlgView message handlers

BOOL CDlgView::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	//+++++++++++++++++++++++++++++++++++++ Initial spin control
	CSpinButtonCtrl* pSpin = (CSpinButtonCtrl*)GetDlgItem( IDC_SPN_MON_GAMMA );
	pSpin->SetRange32( 0, 3 );

	// +++++++++++++++++++++++++++++++++++++++++++++++ Initial Edit control
	CEdit* pEdCtrl = (CEdit*)GetDlgItem( IDC_EDMON_GARMMA );
	pEdCtrl->SetLimitText( 3 ); // 3 characters of 0.3 .. 3.0
	pEdCtrl->SetWindowText( "0.3" ); // Read from core - do initialize

	InitDlgItemText();
	
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}// end of CDlgView::OnInitDialog
/////////////////////////////////////////////////////////////////////////////
VOID CDlgView::InitDlgItemText()
{
	IN_TEXT_DATA* txtData = NULL;
	TCHAR	sep[] = _T("\"");
	TCHAR*	ptID;
	TCHAR*	ptTT;
	TCHAR*	ptEnd;
	DWORD	i;

	m_numTxt = LoadTextFromCtl( "\\Util\\DlgView.ctl", "[Text String]", &txtData );
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

		if( NULL != _tcsstr( txtData[i].szTT, _T("IDC_EDMON_GARMMA") ) )
			txtData[i].idTT = IDC_EDMON_GARMMA;
		else
			if( NULL != _tcsstr( txtData[i].szTT, _T("IDC_CK_TAB") ) )
				txtData[i].idTT = IDC_CK_TAB;
		else
			if( NULL != _tcsstr( txtData[i].szTT, _T("IDC_CK_SHOW_A_CHANNEL") ) )
				txtData[i].idTT = IDC_CK_SHOW_A_CHANNEL;
		else
			if( NULL != _tcsstr( txtData[i].szTT, _T("IDC_CK_SEL_BOX") ) )
				txtData[i].idTT = IDC_CK_SEL_BOX;
		else
			if( NULL != _tcsstr( txtData[i].szTT, _T("IDC_CK_SAFE_TITLE") ) )
				txtData[i].idTT = IDC_CK_SAFE_TITLE;
		else
			if( NULL != _tcsstr( txtData[i].szTT, _T("IDC_CK_SAFE_ACTION") ) )
				txtData[i].idTT = IDC_CK_SAFE_ACTION;
		else
			if( NULL != _tcsstr( txtData[i].szTT, _T("IDC_CK_MONITOR_GAMMA") ) )
				txtData[i].idTT = IDC_CK_MONITOR_GAMMA;
		else
			if( NULL != _tcsstr( txtData[i].szTT, _T("IDC_CK_LNE_MARGIN") ) )
				txtData[i].idTT = IDC_CK_LNE_MARGIN;
		else
			if( NULL != _tcsstr( txtData[i].szTT, _T("IDC_CK_GRIDS") ) )
				txtData[i].idTT = IDC_CK_GRIDS;
		else
			if( NULL != _tcsstr( txtData[i].szTT, _T("IDC_CK_CENTER_POINT") ) )
				txtData[i].idTT = IDC_CK_CENTER_POINT;
		else
			if( NULL != _tcsstr( txtData[i].szTT, _T("IDC_CK_BASELINE") ) )
				txtData[i].idTT = IDC_CK_BASELINE;
		else
			if( NULL != _tcsstr( txtData[i].szTT, _T("IDC_CK_ASPECT_CORRECTION") ) )
				txtData[i].idTT = IDC_CK_ASPECT_CORRECTION;
		else
			if( NULL != _tcsstr( txtData[i].szTT, _T("IDC_BT_TAB") ) )
				txtData[i].idTT = IDC_BT_TAB;
		else
			if( NULL != _tcsstr( txtData[i].szTT, _T("IDC_BT_SETTING") ) )
				txtData[i].idTT = IDC_BT_SETTING;
		else
			if( NULL != _tcsstr( txtData[i].szTT, _T("IDC_GP_INDICATOR") ) )
				txtData[i].idTT = IDC_GP_INDICATOR;
		else
			if( NULL != _tcsstr( txtData[i].szTT, _T("IDC_GP_PAGE_VIEW") ) )
				txtData[i].idTT = IDC_GP_PAGE_VIEW;

		SetDlgItemText( (INT)txtData[i].idTT, (LPCTSTR)ptTT );

		if( txtData[i].idTT != IDD_FONT_LOCATOR )
			m_hFont[i] = ChangeControlFont( GetDlgItem(txtData[i].idTT)->m_hWnd, NULL/*m_hFont[i]*/, UILang_UIFont,0, UILang_UIFontSize, FW_NORMAL);			
	}//end of for

	free( txtData );

}//end of CDlgView::InitDlgItemText()
//////////////////////////////////////////////////////////////////////////////////////////////
// Keep it simple. Send message to the fram object. 
// Tab dialog is a modaless dialog that require create and destroy...
void CDlgView::OnBtTab() 
{
	AfxGetMainWnd()->SendMessage( WM_COMMAND, ID_FILE_TAB_SETUP, 0 );
}//end of CDlgView::OnBtTab
//////////////////////////////////////////////////////////////////////////////////////////////
void CDlgView::OnBtSetting() 
{
	CPageSetupDlg pgSetupDlg;
	int nRet = pgSetupDlg.DoModal();

	switch ( nRet )   
	{   
	case -1:     
		AfxMessageBox(_T("Dialog box could not be created!"));
      break;
    case IDABORT:
      // Do something
       break;
    case IDOK:
       // Do something
       break;
    case IDCANCEL:
      // Do something
       break;
    default:
      // Do something
      break;
   }//end of switch	
}//end of CDlgView::OnBtSetting() 
//////////////////////////////////////////////////////////////////////////////////////////////
void CDlgView::OnDeltaposSpnMonGamma(NMHDR* pNMHDR, LRESULT* pResult) 
{
	NM_UPDOWN* pNMUpDown = (NM_UPDOWN*)pNMHDR;

	char	buf[MAX_PATH];
	m_ctlEdGamma.GetLine( 0, (LPTSTR)buf, MAX_PATH );	// get edit control value

	// Convert the control value + the increment
	double val = atof( buf ) + (double)pNMUpDown->iDelta/10.0;
//	CGS_GetSpinControlNextValue( PAGE_TOP_MARGIN, pNMUpDown->iDelta, &val );

	val = val < 3.0 ? val : 3.0; // range checking
	val = val < 0.3 ? 0.3 : val;

	// Conver the double value to string for display
	DoubleToAlphaString( val, 1, (LPTSTR)buf );	// 1 means one digit after decimal point
	char* pSubStr = strstr( buf, ".0" );		// strip the floating part if 25.0
	if( pSubStr != NULL )						// ie: display 25 only
		*pSubStr = '\0';
	m_ctlEdGamma.SetWindowText( (LPTSTR)buf );
	
	*pResult = 0;
}//end of CDlgView::OnDeltaposSpnMonGamma
////////////////////////////////////////////////////////////////////////////////////////////
// Capture cancel message
void CDlgView::OnCancel() 
{	
	// Dummy function to capture cancel message
}//end of CDlgView::OnCancel() 
////////////////////////////////////////////////////////////////////////////////////////////
void CDlgView::OnOK() 
{	// capture OK message
}//end of CDlgView::OnOK() 
////////////////////////////////////////////////////////////////////////////////////////////
void CDlgView::OnCkSafeTitle() 
{
//	Call core function - set the internal state
//	Update the edit screen
}//end of CDlgView::OnCkSafeTitle()
////////////////////////////////////////////////////////////////////////////////////////////
void CDlgView::OnCkSafeAction() 
{
//	Call core function - set the internal state
//	Update the edit screen
	
}//end of CDlgView::OnCkSafeAction()
////////////////////////////////////////////////////////////////////////////////////////////
void CDlgView::OnCkCenterPoint() 
{
//	Call core function - set the internal state
//	Update the edit screen
	
}//end of CDlgView::OnCkCenterPoint()
////////////////////////////////////////////////////////////////////////////////////////////
void CDlgView::OnCkTab() 
{
//	Call core function - set the internal state
//	Update the edit screen
	
}//end of CDlgView::OnCkTab()
////////////////////////////////////////////////////////////////////////////////////////////
void CDlgView::OnCkGrids() 
{
//	Call core function - set the internal state
//	Update the edit screen
	
}//end of CDlgView::OnCkGrids()
////////////////////////////////////////////////////////////////////////////////////////////
void CDlgView::OnCkSelBox() 
{
//	Call core function - set the internal state
//	Update the edit screen
	
}//end of CDlgView::OnCkSelBox()
////////////////////////////////////////////////////////////////////////////////////////////
void CDlgView::OnCkLneMargin() 
{
//	Call core function - set the internal state
//	Update the edit screen
	
}//end of CDlgView::OnCkLneMargin()
////////////////////////////////////////////////////////////////////////////////////////////
void CDlgView::OnCkBaseline() 
{
//	Call core function - set the internal state
//	Update the edit screen
	
}//end of CDlgView::OnCkBaseline()
////////////////////////////////////////////////////////////////////////////////////////////
void CDlgView::OnCkAspectCorrection() 
{
//	Call core function - set the internal state
//	Update the edit screen
	
}//end of CDlgView::OnCkAspectCorrection()
////////////////////////////////////////////////////////////////////////////////////////////
void CDlgView::OnCkShowAChannel() 
{
//	Call core function - set the internal state
//	Update the edit screen
	
}//end of CDlgView::OnCkShowAChannel()
////////////////////////////////////////////////////////////////////////////////////////////
void CDlgView::OnCkMonitorGamma() 
{
//	Call core function - set the internal state
//	Update the edit screen
	
}//end of CDlgView::OnCkMonitorGamma()
////////////////////////////////////////////////////////////////////////////////////////////