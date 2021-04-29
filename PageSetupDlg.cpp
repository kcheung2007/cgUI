/* COPYRIGHT NOTICE:
********************************************************
*  Copyright (c) 2000 InnoVision Technology, Inc.      *
*  All rights reserved.                                *
*  PROPRIETARY AND CONFIDENTIAL                        *
*  DO NOT DISTRIBUTE                                   *
********************************************************
CGS_FUNC void CGS_ResolutionMgrMenuEntryInit(void);
CGS_FUNC void CGS_ResolutionMgrGetMenuVals(int *pModeListIndex,char *pModeName,int *ModeWidth,int *ModeHeight);
CGS_FUNC void CGS_ResolutionMgrGetModeListItemCount(int *ListItemCount);
CGS_FUNC void CGS_ResolutionMgrGetModeListItemName(int ListItem,char *ItemName);
CGS_FUNC void CGS_ResolutionMgrSetNewWidth(int Width);//call CGS_ResolutionMgrGetMenuVals() after this to get updated values
CGS_FUNC void CGS_ResolutionMgrSetNewHeight(int Height);//call CGS_ResolutionMgrGetMenuVals() after this to get updated values
CGS_FUNC void CGS_ResolutionMgrSetNewMode(int ModeIndex);//after UI calls this, UI should call CGS_ResolutionMgrGetMenuVals() to get class managed updated settings
CGS_FUNC void CGS_ResolutionMgrAcceptNewMode(void);//call when user selects OK


*/
// PageSetupDlg.cpp : implementation file
//

#include "stdafx.h"
#include "cgui.h"
#include "ACGS_Inc\\CGServerDll.h"
#include "PageSetupDlg.h"
#include "Global.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CPageSetupDlg dialog
extern TCHAR UILang_UIFont[256];
extern int	 UILang_UIFontSize;

CPageSetupDlg::CPageSetupDlg(CWnd* pParent /*=NULL*/) : CDialog(CPageSetupDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CPageSetupDlg)
	//}}AFX_DATA_INIT
	TRACE0("PageSetupDlg.cpp :  Constructor\n" );
	m_hFont  = NULL;
	m_numTxt = 0;
	m_hFont  = NULL;
}

CPageSetupDlg::~CPageSetupDlg()
{
	if( m_hFont != NULL )
	{
		for( DWORD i = 0; i < m_numTxt; i++ )
		{
			if( m_hFont[i] != NULL )
				DeleteObject( (HGDIOBJ)m_hFont[i] );

			m_hFont[i] = NULL;
		}
		if( m_hFont != NULL )
		{
			delete [] m_hFont;
			m_hFont = NULL;
		}
	}//end of if - m_hFont

}
void CPageSetupDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CPageSetupDlg)
	DDX_Control(pDX, IDC_OK, m_btOK);
	DDX_Control(pDX, IDC_ED_VERT_SPACE, m_edVertSpace);
	DDX_Control(pDX, IDC_ED_VERT_OFFSET, m_edVertOffset);
	DDX_Control(pDX, IDC_ED_VERT, m_edVert);
	DDX_Control(pDX, IDC_ED_TOP, m_edTop);
	DDX_Control(pDX, IDC_ED_STA, m_edSTA);
	DDX_Control(pDX, IDC_ED_SP_WIDTH, m_edSpWidth);
	DDX_Control(pDX, IDC_ED_SP_HEIGHT, m_edSpHeight);
	DDX_Control(pDX, IDC_ED_RIGHT, m_edRight);
	DDX_Control(pDX, IDC_ED_LEFT, m_edLeft);
	DDX_Control(pDX, IDC_ED_HORI_SPACE, m_edHoriSpace);
	DDX_Control(pDX, IDC_ED_HORI_OFFSET, m_edHoriOffset);
	DDX_Control(pDX, IDC_ED_HORI, m_edHori);
	DDX_Control(pDX, IDC_ED_BOTTOM, m_edBottom);
	DDX_Control(pDX, IDC_CK_SAFE_ACTION, m_ckSafeAction);
	DDX_Control(pDX, IDC_CK_CENTER_POINT, m_ckCenterPt);
	DDX_Control(pDX, IDC_CK_VERT, m_ckVert);
	DDX_Control(pDX, IDC_CK_SNAP_GRID, m_ckSnapGrid);
	DDX_Control(pDX, IDC_CK_SHOW_GRIDS, m_ckShowGrid);
	DDX_Control(pDX, IDC_CK_SAFE_TITLE_INDICATOR, m_ckSafeTitle);
	DDX_Control(pDX, IDC_CK_HORI, m_ckHoriz);
	DDX_Control(pDX, IDC_CB_RESOLUTION, m_cbPSRes);
	DDX_Control(pDX, IDC_CB_TYPE, m_cbPSType);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CPageSetupDlg, CDialog)
	//{{AFX_MSG_MAP(CPageSetupDlg)
	ON_BN_CLICKED(IDOK, OnOk)
	ON_BN_CLICKED(IDC_BT_STA, OnBtSTADefault)
	ON_BN_CLICKED(IDC_BT_PM, OnBtPMDefault)
	ON_BN_CLICKED(IDC_BT_ST, OnBtSTDefault)
	ON_BN_CLICKED(IDC_BT_GRID, OnBtGridDefault)
	ON_CBN_SELCHANGE(IDC_CB_TYPE, OnSelchangeCbType)
	ON_EN_KILLFOCUS(IDC_ED_SP_HEIGHT, OnKillfocusEdSpHeight)
	ON_EN_KILLFOCUS(IDC_ED_SP_WIDTH, OnKillfocusEdSpWidth)
	ON_BN_CLICKED(IDC_OK, OnIXOk)
	ON_CBN_SELCHANGE(IDC_CB_RESOLUTION, OnSelchangeCbResolution)
	ON_BN_CLICKED(IDC_CK_HORI, OnCkHori)
	ON_BN_CLICKED(IDC_CK_SAFE_ACTION, OnCkSafeAction)
	ON_BN_CLICKED(IDC_CK_SAFE_TITLE_INDICATOR, OnCkSafeTitleIndicator)
	ON_BN_CLICKED(IDC_CK_SHOW_GRIDS, OnCkShowGrids)
	ON_BN_CLICKED(IDC_CK_SNAP_GRID, OnCkSnapGrid)
	ON_BN_CLICKED(IDC_CK_VERT, OnCkVert)
	ON_EN_KILLFOCUS(IDC_ED_BOTTOM, OnKillfocusEdBottom)
	ON_EN_KILLFOCUS(IDC_ED_HORI, OnKillfocusEdHori)
	ON_EN_KILLFOCUS(IDC_ED_HORI_OFFSET, OnKillfocusEdHoriOffset)
	ON_EN_KILLFOCUS(IDC_ED_HORI_SPACE, OnKillfocusEdHoriSpace)
	ON_EN_KILLFOCUS(IDC_ED_LEFT, OnKillfocusEdLeft)
	ON_EN_KILLFOCUS(IDC_ED_RIGHT, OnKillfocusEdRight)
	ON_EN_KILLFOCUS(IDC_ED_STA, OnKillfocusEdSta)
	ON_EN_KILLFOCUS(IDC_ED_TOP, OnKillfocusEdTop)
	ON_EN_KILLFOCUS(IDC_ED_VERT, OnKillfocusEdVert)
	ON_EN_KILLFOCUS(IDC_ED_VERT_OFFSET, OnKillfocusEdVertOffset)
	ON_EN_KILLFOCUS(IDC_ED_VERT_SPACE, OnKillfocusEdVertSpace)
	ON_NOTIFY(UDN_DELTAPOS, IDC_SPN_PS_BOTTOM, OnDeltaposSpnPsBottom)
	ON_NOTIFY(UDN_DELTAPOS, IDC_SPN_PS_HORI, OnDeltaposSpnPsHori)
	ON_NOTIFY(UDN_DELTAPOS, IDC_SPN_PS_HORI_OFFSET, OnDeltaposSpnPsHoriOffset)
	ON_NOTIFY(UDN_DELTAPOS, IDC_SPN_PS_HORI_SPACE, OnDeltaposSpnPsHoriSpace)
	ON_NOTIFY(UDN_DELTAPOS, IDC_SPN_PS_LEFT, OnDeltaposSpnPsLeft)
	ON_NOTIFY(UDN_DELTAPOS, IDC_SPN_PS_RES_HEIGHT, OnDeltaposSpnPsResHeight)
	ON_NOTIFY(UDN_DELTAPOS, IDC_SPN_PS_RES_WIDTH, OnDeltaposSpnPsResWidth)
	ON_NOTIFY(UDN_DELTAPOS, IDC_SPN_PS_RIGHT, OnDeltaposSpnPsRight)
	ON_NOTIFY(UDN_DELTAPOS, IDC_SPN_PS_STA, OnDeltaposSpnPsSta)
	ON_NOTIFY(UDN_DELTAPOS, IDC_SPN_PS_TOP, OnDeltaposSpnPsTop)
	ON_NOTIFY(UDN_DELTAPOS, IDC_SPN_PS_VERT, OnDeltaposSpnPsVert)
	ON_NOTIFY(UDN_DELTAPOS, IDC_SPN_PS_VERT_OFFSET, OnDeltaposSpnPsVertOffset)
	ON_NOTIFY(UDN_DELTAPOS, IDC_SPN_PS_VERT_SPACE, OnDeltaposSpnPsVertSpace)
	ON_BN_CLICKED(IDC_RB_4_3, OnRb43)
	ON_BN_CLICKED(IDC_RB_16_9, OnRb169)
	ON_BN_CLICKED(IDCANCEL, OnCancel)
	ON_WM_CREATE()
	ON_BN_CLICKED(IDC_RB_SQR_PIXEL, OnRbSqrPixel)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CPageSetupDlg message handlers
/////////////////////////////////////////////////////////////////////////////
void CPageSetupDlg::OnOk() 
{
	CWnd* pEdWnd = GetFocus(); //++++++++++++++= Handle the focus
	if( *pEdWnd == m_edSTA )
		m_edHori.SetFocus();
	else
		if( *pEdWnd == m_edHori )
			m_edVert.SetFocus();
	else
		if( *pEdWnd == m_edVert )
			m_edTop.SetFocus();
	else
		if( *pEdWnd == m_edTop )
			m_edLeft.SetFocus();
	else
		if( *pEdWnd == m_edLeft )
			m_edBottom.SetFocus();
	else
		if( *pEdWnd == m_edBottom )
			m_edRight.SetFocus();
	else
		if( *pEdWnd == m_edRight )
			m_edHoriSpace.SetFocus();
	else
		if( *pEdWnd == m_edHoriSpace )
			m_edHoriOffset.SetFocus();
	else
		if( *pEdWnd == m_edHoriOffset )
			m_edVertSpace.SetFocus();
	else
		if( *pEdWnd == m_edVertSpace )
			m_edVertOffset.SetFocus();
	else
		if( *pEdWnd == m_edVertOffset )
			m_edSpWidth.SetFocus();
	else
		if( *pEdWnd == m_edSpWidth )
			m_edSpHeight.SetFocus();
	else
		if( *pEdWnd == m_edSpHeight )
			m_edSTA.SetFocus();

}//end of CPageSetupDlg::OnBtOk
/////////////////////////////////////////////////////////////////////////////
void CPageSetupDlg::OnCancel() 
{
	CDialog::OnCancel();
}//end of CPageSetupDlg::OnBtCancel
/////////////////////////////////////////////////////////////////////////////
void CPageSetupDlg::OnBtSTADefault() 
{
	// TODO: Add your control notification handler code here
	
}//end of CPageSetupDlg::OnBtSTADefault
/////////////////////////////////////////////////////////////////////////////
void CPageSetupDlg::OnBtPMDefault() 
{
	// TODO: Add your control notification handler code here
	
}//end of CPageSetupDlg::OnBtPMDefault
/////////////////////////////////////////////////////////////////////////////
void CPageSetupDlg::OnBtSTDefault() 
{
	// TODO: Add your control notification handler code here
	
}//end of CPageSetupDlg::OnBtSTDefault
/////////////////////////////////////////////////////////////////////////////
void CPageSetupDlg::OnBtGridDefault() 
{
	// TODO: Add your control notification handler code here
	
}//end of CPageSetupDlg::OnBtGridDefault
/////////////////////////////////////////////////////////////////////////////
BOOL CPageSetupDlg::OnInitDialog() 
{
	CDialog::OnInitDialog();
	TRACE0("PageSetupDlg.cpp :  CPageSetupDlg::OnInitDialog\n" );

	InitDlgItemText();
	InitTypeCombo();
	InitResolutionCombo();
	InitSpinControl();
	InitEditControl();
	InitCheckBoxControl(); // Include radio button

	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}//end of CPageSetupDlg::OnInitDialog
/////////////////////////////////////////////////////////////////////////////
void CPageSetupDlg::OnSelchangeCbType() 
{
	switch( m_cbPSType.GetCurSel() )
	{
	case 0:
		IXReg_ScrollBarEnableProc( 0, 0 );
		break;
	case 1:
		IXReg_ScrollBarEnableProc( 1, 0 );
		break;
	case 2:
		IXReg_ScrollBarEnableProc( 0, 1 );
		break;
	}//end of switch
}//end of CPageSetupDlg::OnSelchangeCbType
/////////////////////////////////////////////////////////////////////////////
VOID CPageSetupDlg::InitTypeCombo()
{
	m_cbPSType.AddString( _T("Still") );	
	m_cbPSType.AddString( _T("Roll") );
	m_cbPSType.AddString( _T("Crawl") );
	m_cbPSType.SetCurSel( 0 );

}//end of CPageSetupDlg::InitTypeCombo()
/////////////////////////////////////////////////////////////////////////////
// Call CGS_ResolutionMgrMenuEntryInit to initial the manager frist. Then
// Call CGS_ResolutionMgrGetModeListItemCount to get the items count.
// Call CGS_ResolutionMgrGetModeListItemName to get a list of item name.
// Add the item name to combo box.
VOID CPageSetupDlg::InitResolutionCombo()
{
	int		nItem;
	char	ItemName[MAX_PATH];
	TCHAR	swRes[MAX_PATH];

	CGS_ResolutionMgrMenuEntryInit();
	CGS_ResolutionMgrGetModeListItemCount( &nItem );

	for( int i = 0; i < nItem; i++ )
	{
		CGS_ResolutionMgrGetModeListItemName( i, ItemName );
		MultiByteToUnicode( CP_ACP, ItemName, swRes );
//		MultiByteToWideChar(CP_ACP, MB_PRECOMPOSED, ItemName, -1, swRes, MAX_PATH);
		m_cbPSRes.AddString( swRes );
	}//end of for - adding item to combo box

	UpdateResItemsGroup();
}//end of InitResolutionCombo
/////////////////////////////////////////////////////////////////////////////
// TO DO : Check for integer style or not. If not integer style, delete it.
VOID CPageSetupDlg::InitSpinControl()
{
	CSpinButtonCtrl* pSpin = (CSpinButtonCtrl*)GetDlgItem( IDC_SPN_PS_STA );
	pSpin->SetRange( 0, 100 );
	//save for ref.	pSpin->SetPos((int) (m_dSpin * 10.0));
	pSpin = (CSpinButtonCtrl*)GetDlgItem( IDC_SPN_PS_HORI );
	pSpin->SetRange( -100, 100 );
	pSpin = (CSpinButtonCtrl*)GetDlgItem( IDC_SPN_PS_VERT );
	pSpin->SetRange( -100, 100 );
	pSpin = (CSpinButtonCtrl*)GetDlgItem( IDC_SPN_PS_TOP );
	pSpin->SetRange( 0, 100 );
	pSpin = (CSpinButtonCtrl*)GetDlgItem( IDC_SPN_PS_LEFT );
	pSpin->SetRange( 0, 100 );
	pSpin = (CSpinButtonCtrl*)GetDlgItem( IDC_SPN_PS_BOTTOM );
	pSpin->SetRange( 0, 100 );
	pSpin = (CSpinButtonCtrl*)GetDlgItem( IDC_SPN_PS_RIGHT );
	pSpin->SetRange( 0, 100 );
	pSpin = (CSpinButtonCtrl*)GetDlgItem( IDC_SPN_PS_HORI_SPACE );
	pSpin->SetRange( 0, 256 );
	pSpin = (CSpinButtonCtrl*)GetDlgItem( IDC_SPN_PS_HORI_OFFSET );
	pSpin->SetRange( -256, 256 );
	pSpin = (CSpinButtonCtrl*)GetDlgItem( IDC_SPN_PS_VERT_SPACE );
	pSpin->SetRange( 0, 256 );
	pSpin = (CSpinButtonCtrl*)GetDlgItem( IDC_SPN_PS_VERT_OFFSET );
	pSpin->SetRange( -256, 256 );
	pSpin = (CSpinButtonCtrl*)GetDlgItem( IDC_SPN_PS_RES_WIDTH );
	pSpin->SetRange( 0, 2000 );
	pSpin = (CSpinButtonCtrl*)GetDlgItem( IDC_SPN_PS_RES_HEIGHT );
	pSpin->SetRange( 0, 2000 );
}//end of CPageSetupDlg::InitSpinControl()
/////////////////////////////////////////////////////////////////////////////
VOID CPageSetupDlg::InitEditControl()
{
	CEdit* pEdCtrl = (CEdit*)GetDlgItem( IDC_ED_STA );
	pEdCtrl->SetLimitText( 3 ); // 3 characters of 0 .. 100 %
//??	SetDlgItemInt(IDC_ED_STA, (int)CGS_GetValDbl(EDIT_WORD_WRAP_MODE), 0 );

	pEdCtrl = (CEdit*)GetDlgItem( IDC_ED_HORI );
	pEdCtrl->SetLimitText( 7 ); // 7 characters of -100.00 .. 100.00 %
//??	SetDlgItemInt(IDC_ED_HORI, (int)CGS_GetValDbl( ID ), 0 );

	pEdCtrl = (CEdit*)GetDlgItem( IDC_ED_VERT );
	pEdCtrl->SetLimitText( 7 ); // 7 characters of -100.00 .. 100.00 %
//??	SetDlgItemInt(IDC_ED_VERT, (int)CGS_GetValDbl( ID ), 0 );

	pEdCtrl = (CEdit*)GetDlgItem( IDC_ED_TOP );
	pEdCtrl->SetLimitText( 6 ); // 6 characters of 0 .. 100.00 %
	SetDlgItemInt(IDC_ED_TOP, (int)CGS_GetValDbl( PAGE_TOP_MARGIN ), 0 );

	pEdCtrl = (CEdit*)GetDlgItem( IDC_ED_LEFT );
	pEdCtrl->SetLimitText( 6 ); // 6 characters of 0 .. 100.00 %
	SetDlgItemInt(IDC_ED_LEFT, (int)CGS_GetValDbl( PAGE_LEFT_MARGIN ), 0 );

	pEdCtrl = (CEdit*)GetDlgItem( IDC_ED_BOTTOM );
	pEdCtrl->SetLimitText( 6 ); // 6 characters of 0 .. 100.00 %
	SetDlgItemInt(IDC_ED_BOTTOM, (int)CGS_GetValDbl( PAGE_BOTTOM_MARGIN ), 0 );

	pEdCtrl = (CEdit*)GetDlgItem( IDC_ED_RIGHT );
	pEdCtrl->SetLimitText( 6 ); // 6 characters of 0 .. 100.00 %
	SetDlgItemInt(IDC_ED_RIGHT, (int)CGS_GetValDbl( PAGE_RIGHT_MARGIN ), 0 );
	
	pEdCtrl = (CEdit*)GetDlgItem( IDC_ED_HORI_SPACE );
	pEdCtrl->SetLimitText( 3 ); // 3 characters of 0 .. 256
	SetDlgItemInt(IDC_ED_HORI_SPACE, (int)CGS_GetValDbl( EDIT_HORIZ_GRID_SPACING ), 0 );
	pEdCtrl = (CEdit*)GetDlgItem( IDC_ED_HORI_OFFSET );
	pEdCtrl->SetLimitText( 4 ); // 4 characters of -256 .. 256
	SetDlgItemInt(IDC_ED_HORI_OFFSET, (int)CGS_GetValDbl( EDIT_HORIZ_GRID_OFFSET ), 0 );
	pEdCtrl = (CEdit*)GetDlgItem( IDC_ED_VERT_SPACE );
	pEdCtrl->SetLimitText( 3 ); // 3 characters of 0 .. 256
	SetDlgItemInt(IDC_ED_VERT_SPACE, (int)CGS_GetValDbl( EDIT_VERT_GRID_SPACING ), 0 );
	pEdCtrl = (CEdit*)GetDlgItem( IDC_ED_VERT_OFFSET );
	pEdCtrl->SetLimitText( 4 ); // 4 characters of -256 .. 256
	SetDlgItemInt(IDC_ED_VERT_OFFSET, (int)CGS_GetValDbl( EDIT_VERT_GRID_OFFSET ), 0 );

	pEdCtrl = (CEdit*)GetDlgItem( IDC_ED_SP_WIDTH );
	pEdCtrl->SetLimitText( 4 ); // 3 characters of 2000
	pEdCtrl = (CEdit*)GetDlgItem( IDC_ED_SP_HEIGHT );
	pEdCtrl->SetLimitText( 4 ); // 3 characters of 2000

}//end of CPageSetupDlg::InitEditControl()
/////////////////////////////////////////////////////////////////////////////
VOID CPageSetupDlg::InitDlgItemText()
{
	IN_TEXT_DATA* txtData = NULL;
	TCHAR	sep[] = _T("\"");
	TCHAR*	ptID;
	TCHAR*	ptTT;
	TCHAR*	ptEnd;
	HFONT	hFont = NULL;

	m_numTxt = LoadTextFromCtl( "\\Util\\PgSetupDlg.ctl", "[Tooltip]", &txtData );
	if( m_numTxt == 0 )
		return;

	m_hFont = new HFONT[m_numTxt];

	for( DWORD i = 0; i < m_numTxt; i++ )
	{
		ptID   = _tcstok( txtData[i].szTT, sep );
		ptTT   = _tcstok( NULL, sep );
		ptEnd  = _tcstok( NULL, sep );
		if( ptEnd != 0 )
			*ptEnd = '\0';

		m_hFont[i] = NULL; // initial
		if( NULL != _tcsstr( txtData[i].szTT, _T("IDD_PAGE_SETUP_DLG") ) )
		{
			txtData[i].idTT = IDD_PAGE_SETUP_DLG;			
			m_hFont[i] = ChangeControlFont( m_hWnd, NULL, UILang_UIFont,0, UILang_UIFontSize, FW_NORMAL);
			SetWindowText( (LPCTSTR)ptTT );
		}
		else
			if( NULL != _tcsstr( txtData[i].szTT, _T("IDC_GP_PAGE_TYPE") ) )
				txtData[i].idTT = IDC_GP_PAGE_TYPE;
		else
			if( NULL != _tcsstr( txtData[i].szTT, _T("IDC_GP_PAGE_CENTER_OFFSET") ) )
				txtData[i].idTT = IDC_GP_PAGE_CENTER_OFFSET;
		else
			if( NULL != _tcsstr( txtData[i].szTT, _T("IDC_GP_MARGIN") ) )
				txtData[i].idTT = IDC_GP_MARGIN;
		else
			if( NULL != _tcsstr( txtData[i].szTT, _T("IDC_GP_GRIDS") ) )
				txtData[i].idTT = IDC_GP_GRIDS;
		else
			if( NULL != _tcsstr( txtData[i].szTT, _T("IDC_GP_RESOLUTION") ) )
				txtData[i].idTT = IDC_GP_RESOLUTION;
		else
			if( NULL != _tcsstr( txtData[i].szTT, _T("IDC_CB_TYPE") ) )
				txtData[i].idTT = IDC_CB_TYPE;
		else
			if( NULL != _tcsstr( txtData[i].szTT, _T("IDC_CB_RESOLUTION") ) )
				txtData[i].idTT = IDC_CB_RESOLUTION;
		else
			if( NULL != _tcsstr( txtData[i].szTT, _T("IDC_CK_SAFE_TITLE_INDICATOR") ) )
				txtData[i].idTT = IDC_CK_SAFE_TITLE_INDICATOR;
		else
			if( NULL != _tcsstr( txtData[i].szTT, _T("IDC_CK_SAFE_ACTION") ) )
				txtData[i].idTT = IDC_CK_SAFE_ACTION;
		else
			if( NULL != _tcsstr( txtData[i].szTT, _T("IDC_CK_CENTER_POINT") ) )
				txtData[i].idTT = IDC_CK_CENTER_POINT;
		else
			if( NULL != _tcsstr( txtData[i].szTT, _T("IDC_CK_HORI") ) )
				txtData[i].idTT = IDC_CK_HORI;
		else
			if( NULL != _tcsstr( txtData[i].szTT, _T("IDC_CK_VERT") ) )
				txtData[i].idTT = IDC_CK_VERT;
		else
			if( NULL != _tcsstr( txtData[i].szTT, _T("IDC_CK_SHOW_GRIDS") ) )
				txtData[i].idTT = IDC_CK_SHOW_GRIDS;
		else
			if( NULL != _tcsstr( txtData[i].szTT, _T("IDC_CK_SNAP_GRID") ) )
				txtData[i].idTT = IDC_CK_SNAP_GRID;
		else
			if( NULL != _tcsstr( txtData[i].szTT, _T("IDC_BT_STA") ) )
				txtData[i].idTT = IDC_BT_STA;
		else
			if( NULL != _tcsstr( txtData[i].szTT, _T("IDC_BT_PM") ) )
				txtData[i].idTT = IDC_BT_PM;
		else
			if( NULL != _tcsstr( txtData[i].szTT, _T("IDC_BT_GRID") ) )
				txtData[i].idTT = IDC_BT_GRID;
		else
			if( NULL != _tcsstr( txtData[i].szTT, _T("IDC_STC_SAFE_AREA") ) )
				txtData[i].idTT = IDC_STC_SAFE_AREA;
		else
			if( NULL != _tcsstr( txtData[i].szTT, _T("IDC_RB_SQR_PIXEL") ) )
				txtData[i].idTT = IDC_RB_SQR_PIXEL;
		else
			if( NULL != _tcsstr( txtData[i].szTT, _T("IDC_STC_HORI") ) )
				txtData[i].idTT = IDC_STC_HORI;
		else
			if( NULL != _tcsstr( txtData[i].szTT, _T("IDC_STC_VERT") ) )
				txtData[i].idTT = IDC_STC_VERT;
		else
			if( NULL != _tcsstr( txtData[i].szTT, _T("IDC_STC_TOP") ) )
				txtData[i].idTT = IDC_STC_TOP;
		else
			if( NULL != _tcsstr( txtData[i].szTT, _T("IDC_STC_LEFT") ) )
				txtData[i].idTT = IDC_STC_LEFT;
		else
			if( NULL != _tcsstr( txtData[i].szTT, _T("IDC_STC_BOTTOM") ) )
				txtData[i].idTT = IDC_STC_BOTTOM;
		else
			if( NULL != _tcsstr( txtData[i].szTT, _T("IDC_STC_RIGHT") ) )
				txtData[i].idTT = IDC_STC_RIGHT;
		else
			if( NULL != _tcsstr( txtData[i].szTT, _T("IDC_STC_SPACING") ) )
				txtData[i].idTT = IDC_STC_SPACING;
		else
			if( NULL != _tcsstr( txtData[i].szTT, _T("IDC_STC_OFFSET") ) )
				txtData[i].idTT = IDC_STC_OFFSET;
		else
			if( NULL != _tcsstr( txtData[i].szTT, _T("IDC_STC_WIDTH") ) )
				txtData[i].idTT = IDC_STC_WIDTH;
		else
			if( NULL != _tcsstr( txtData[i].szTT, _T("IDC_STC_HEIGHT") ) )
				txtData[i].idTT = IDC_STC_HEIGHT;
		else
			if( NULL != _tcsstr( txtData[i].szTT, _T("IDC_STC_ASPECT_RATIO") ) )
				txtData[i].idTT = IDC_STC_ASPECT_RATIO;
		else
			if( NULL != _tcsstr( txtData[i].szTT, _T("IDC_OK") ) )
				txtData[i].idTT = IDC_OK;
		else
			if( NULL != _tcsstr( txtData[i].szTT, _T("IDCANCEL") ) )
				txtData[i].idTT = IDCANCEL;

		SetDlgItemText( txtData[i].idTT, (LPCTSTR)ptTT );

		if( txtData[i].idTT != IDD_PAGE_SETUP_DLG )
			m_hFont[i] = ChangeControlFont( GetDlgItem(txtData[i].idTT)->m_hWnd, NULL, UILang_UIFont,0, UILang_UIFontSize, FW_NORMAL);
	}//end of for

	free( txtData );

}//end of CPageSetupDlg::InitDlgItemText()
///////////////////////////////////////////////////////////////////////////////////////////////
// Initial Check box control but also include radio button
VOID CPageSetupDlg::InitCheckBoxControl()
{
	m_bHoriz = (BOOL)CGS_GetValDbl( EDIT_HORIZ_GRID_ENABLE );
	m_bVert = (BOOL)CGS_GetValDbl( EDIT_VERT_GRID_ENABLE );
	m_bSafeTitle = (BOOL)CGS_GetValDbl( EDIT_SAFE_TITLE_ENABLE );
	m_bSafeAction = (BOOL)CGS_GetValDbl( EDIT_SAFE_ACTION_ENABLE );
	m_bCenterPt = (BOOL)CGS_GetValDbl( EDIT_CENTERPOINT_ENABLE );
	m_bShowGrid = (BOOL)CGS_GetValDbl( EDIT_SHOW_GRID_ENABLE );
	m_bSnapGrid = (BOOL)CGS_GetValDbl( EDIT_AUTO_GRID_SNAP_ENABLE );

	m_ckHoriz.SetCheck( m_bHoriz );
	m_ckVert.SetCheck( m_bVert );
	m_ckSafeTitle.SetCheck( m_bSafeTitle );
	m_ckSafeAction.SetCheck( m_bSafeAction );
	m_ckCenterPt.SetCheck( m_bCenterPt );
	m_ckShowGrid.SetCheck( m_bShowGrid );
	m_ckSnapGrid.SetCheck( m_bSnapGrid );

	// TO DO : Initial radio button - read value then
	CheckRadioButton( IDC_RB_4_3, IDC_RB_SQR_PIXEL, IDC_RB_16_9 );

}//end of CPageSetupDlg::InitCheckBoxControl()
///////////////////////////////////////////////////////////////////////////////////////////////
void CPageSetupDlg::OnSelchangeCbResolution() 
{
	TRACE0( "PageSetupDlg.cpp - OnSelchangeCbResolution\n" );

	CGS_ResolutionMgrSetNewMode( m_cbPSRes.GetCurSel() );	
	UpdateResItemsGroup();
}//end of CPageSetupDlg::OnSelchangeCbResolution
///////////////////////////////////////////////////////////////////////////////////////////////
void CPageSetupDlg::OnKillfocusEdSpHeight() 
{
	TRACE0("PageSetupDlg.cpp - OnKillfocusEdSpHeight()\n" );

	CGS_ResolutionMgrSetNewHeight( GetDlgItemInt(IDC_ED_SP_HEIGHT, NULL, 0) );
	UpdateResItemsGroup();
}//end of CPageSetupDlg::OnKillfocusEdSpHeight() 
///////////////////////////////////////////////////////////////////////////////////////////////
void CPageSetupDlg::OnKillfocusEdSpWidth() 
{
	TRACE0("PageSetupDlg.cpp - OnKillfocusEdSpWidth()\n" );

	CGS_ResolutionMgrSetNewWidth( GetDlgItemInt(IDC_ED_SP_WIDTH, NULL, 0) );
	UpdateResItemsGroup();

}//end of CPageSetupDlg::OnKillfocusEdSpWidth
///////////////////////////////////////////////////////////////////////////////////////////////
VOID CPageSetupDlg::UpdateResItemsGroup()
{
	int  rv = 0;
	int  nItem;
	int  width;
	int  height;
	char ItemName[MAX_PATH];

	CGS_ResolutionMgrGetMenuVals( &nItem, ItemName, &width, &height );

	if( CB_ERR == m_cbPSRes.SetCurSel( nItem ) )
		MessageBox( _T("Error in selecting combo box item"), _T("Message"), MB_OK );

	SetDlgItemInt( IDC_ED_SP_WIDTH,  width,  0 );
	SetDlgItemInt( IDC_ED_SP_HEIGHT, height, 0 );	

}//end of CPageSetupDlg::UpdateResItemsGroup()
///////////////////////////////////////////////////////////////////////////////////////////////
void CPageSetupDlg::OnIXOk() 
{
	CGS_ResolutionMgrAcceptNewMode();
	AfxGetMainWnd()->RedrawWindow( NULL, NULL, RDW_INVALIDATE | RDW_UPDATENOW | RDW_ERASE | RDW_ALLCHILDREN );

	CDialog::OnOK();
}//end of OnIXOk
///////////////////////////////////////////////////////////////////////////////////////////////
void CPageSetupDlg::OnCkHori() 
{
	m_ckHoriz.SetCheck( m_bHoriz ^= 1 );
	CGS_SetValDbl( EDIT_HORIZ_GRID_ENABLE, (double)m_bHoriz );

}//end of CPageSetupDlg::OnCkHori
///////////////////////////////////////////////////////////////////////////////////////////////
void CPageSetupDlg::OnCkSafeAction() 
{
	m_ckSafeAction.SetCheck( m_bSafeAction ^= 1  );	
	CGS_SetValDbl( EDIT_SAFE_ACTION_ENABLE, (double)m_bSafeAction );

}//end of CPageSetupDlg::OnCkSafeAction
///////////////////////////////////////////////////////////////////////////////////////////////
void CPageSetupDlg::OnCkSafeTitleIndicator() 
{
	m_ckSafeTitle.SetCheck( m_bSafeTitle ^= 1 );
	CGS_SetValDbl( EDIT_SAFE_TITLE_ENABLE, (double)m_bSafeTitle );
}//end of CPageSetupDlg::OnCkSafeTitleIndicator
///////////////////////////////////////////////////////////////////////////////////////////////
void CPageSetupDlg::OnCkShowGrids() 
{
	m_ckShowGrid.SetCheck( m_bShowGrid ^= 1 );
	CGS_SetValDbl( EDIT_SHOW_GRID_ENABLE, (double)m_bShowGrid );
	
}//end of CPageSetupDlg::OnCkShowGrids
///////////////////////////////////////////////////////////////////////////////////////////////
void CPageSetupDlg::OnCkSnapGrid() 
{
	m_ckSnapGrid.SetCheck( m_bSnapGrid ^= 1 );
	CGS_SetValDbl( EDIT_AUTO_GRID_SNAP_ENABLE, (double)m_bSnapGrid );
	
}//end of CPageSetupDlg::OnCkSnapGrid
///////////////////////////////////////////////////////////////////////////////////////////////
void CPageSetupDlg::OnCkVert() 
{
	m_ckVert.SetCheck( m_bVert ^= 1 );
	CGS_SetValDbl( EDIT_VERT_GRID_ENABLE, (double)m_bVert );
}//end of CPageSetupDlg::OnCkVert
///////////////////////////////////////////////////////////////////////////////////////////////
void CPageSetupDlg::OnKillfocusEdTop() 
{
	TRACE0("PageSetupDlg.cpp - OnKillfocusEdTop()\n" );

//check point
	char	buf[MAX_PATH];
	m_edTop.GetLine( 0, (LPTSTR)buf, MAX_PATH );

	double tmp = atof( buf );
	CGS_SetValDbl( PAGE_TOP_MARGIN, atof( buf ) );
	
}//end of CPageSetupDlg::OnKillfocusEdTop
///////////////////////////////////////////////////////////////////////////////////////////////
void CPageSetupDlg::OnKillfocusEdBottom() 
{
	TRACE0("PageSetupDlg.cpp - OnKillfocusEdBottom()\n" );

	char	buf[MAX_PATH];
	m_edBottom.GetLine( 0, (LPTSTR)buf, MAX_PATH );

//	double tmp = atof( buf );
	CGS_SetValDbl( PAGE_BOTTOM_MARGIN, atof( buf ) );
	
}//end of CPageSetupDlg::OnKillfocusEdBottom
///////////////////////////////////////////////////////////////////////////////////////////////
void CPageSetupDlg::OnKillfocusEdLeft() 
{
	TRACE0("PageSetupDlg.cpp - OnKillfocusEdLeft()\n" );

	char	buf[MAX_PATH];
	m_edLeft.GetLine( 0, (LPTSTR)buf, MAX_PATH );

//	double tmp = atof( buf );
	CGS_SetValDbl( PAGE_LEFT_MARGIN, atof( buf ) );
	
}//end of CPageSetupDlg::OnKillfocusEdLeft
///////////////////////////////////////////////////////////////////////////////////////////////
void CPageSetupDlg::OnKillfocusEdRight() 
{
	TRACE0("PageSetupDlg.cpp - OnKillfocusEdRight()\n" );

	char	buf[MAX_PATH];
	m_edRight.GetLine( 0, (LPTSTR)buf, MAX_PATH );

//	double tmp = atof( buf );
	CGS_SetValDbl( PAGE_RIGHT_MARGIN, atof( buf ) );

}//end of CPageSetupDlg::OnKillfocusEdRight
///////////////////////////////////////////////////////////////////////////////////////////////
void CPageSetupDlg::OnKillfocusEdHori() 
{
	char	buf[MAX_PATH];
	m_edHori.GetLine( 0, (LPTSTR)buf, MAX_PATH );

	double tmp = atof( buf );
	
}//end of CPageSetupDlg::OnKillfocusEdHori
///////////////////////////////////////////////////////////////////////////////////////////////
void CPageSetupDlg::OnKillfocusEdVert() 
{
	char	buf[MAX_PATH];
	m_edVert.GetLine( 0, (LPTSTR)buf, MAX_PATH );

	double tmp = atof( buf );
//	CGS_SetValDbl( EDIT_VERT_OFFSET, atof(buf) );
	
}//end of CPageSetupDlg::OnKillfocusEdVert
///////////////////////////////////////////////////////////////////////////////////////////////
void CPageSetupDlg::OnKillfocusEdSta() 
{
	// TODO: Add your control notification handler code here
	
}//end of CPageSetupDlg::OnKillfocusEdSta
///////////////////////////////////////////////////////////////////////////////////////////////
void CPageSetupDlg::OnKillfocusEdVertOffset() 
{
	char	buf[MAX_PATH];
	m_edVertOffset.GetLine( 0, (LPTSTR)buf, MAX_PATH );
	CGS_SetValDbl( EDIT_VERT_GRID_OFFSET, atof(buf) );
	
}//end of CPageSetupDlg::OnKillfocusEdVertOffset
///////////////////////////////////////////////////////////////////////////////////////////////
void CPageSetupDlg::OnKillfocusEdVertSpace() 
{
	CGS_SetValDbl( EDIT_VERT_GRID_SPACING, GetDlgItemInt(IDC_ED_VERT_SPACE, NULL, 0) );
	
}//end of CPageSetupDlg::OnKillfocusEdVertSpace
///////////////////////////////////////////////////////////////////////////////////////////////
void CPageSetupDlg::OnKillfocusEdHoriOffset() 
{
	char	buf[MAX_PATH];
	m_edVertOffset.GetLine( 0, (LPTSTR)buf, MAX_PATH );
	CGS_SetValDbl( EDIT_HORIZ_GRID_OFFSET, atof(buf) );	
	
}//end of CPageSetupDlg::OnKillfocusEdHoriOffset
///////////////////////////////////////////////////////////////////////////////////////////////
void CPageSetupDlg::OnKillfocusEdHoriSpace() 
{
	CGS_SetValDbl( EDIT_HORIZ_GRID_SPACING, GetDlgItemInt(IDC_ED_HORI_SPACE, NULL, 0) );
}//end of CPageSetupDlg::OnKillfocusEdHoriSpace
///////////////////////////////////////////////////////////////////////////////////////////////
void CPageSetupDlg::OnDeltaposSpnPsTop(NMHDR* pNMHDR, LRESULT* pResult) 
{
	TRACE0("PageSetupDlg.cpp - OnDeltaposSpnPsTop()\n" );
	NM_UPDOWN* pNMUpDown = (NM_UPDOWN*)pNMHDR;

//check point
	char	buf[MAX_PATH];
	m_edTop.GetLine( 0, (LPTSTR)buf, MAX_PATH );

	double val = atof( buf ) + pNMUpDown->iDelta;
	CGS_GetSpinControlNextValue( PAGE_TOP_MARGIN, pNMUpDown->iDelta, &val );

	val = val < 100 ? val : 100; // range checking
	val = val < 0   ? 0   : val;

	DoubleToAlphaString( val, 2, (LPTSTR)buf );
	m_edTop.SetWindowText( (LPTSTR)buf );
	
	*pResult = 0;
}//end of CPageSetupDlg::OnDeltaposSpnPsTop
///////////////////////////////////////////////////////////////////////////////////////////////
void CPageSetupDlg::OnDeltaposSpnPsBottom(NMHDR* pNMHDR, LRESULT* pResult) 
{
	TRACE0("PageSetupDlg.cpp - OnDeltaposSpnPsBottom()\n" );
	NM_UPDOWN* pNMUpDown = (NM_UPDOWN*)pNMHDR;

	// TODO: Add your control notification handler code here
//check point
	char	buf[MAX_PATH];
	m_edBottom.GetLine( 0, (LPTSTR)buf, MAX_PATH );

	double val = atof( buf ) + pNMUpDown->iDelta;
	CGS_GetSpinControlNextValue( PAGE_BOTTOM_MARGIN, pNMUpDown->iDelta, &val );

	val = val < 100 ? val : 100; // range checking
	val = val < 0   ? 0   : val;

	DoubleToAlphaString( val, 2, (LPTSTR)buf );
	m_edBottom.SetWindowText( (LPTSTR)buf );
	
	*pResult = 0;
}//end of CPageSetupDlg::OnDeltaposSpnPsBottom
///////////////////////////////////////////////////////////////////////////////////////////////
void CPageSetupDlg::OnDeltaposSpnPsLeft(NMHDR* pNMHDR, LRESULT* pResult) 
{
	TRACE0("PageSetupDlg.cpp - OnDeltaposSpnPsLeft()\n" );
	NM_UPDOWN* pNMUpDown = (NM_UPDOWN*)pNMHDR;
	
	// TODO: Add your control notification handler code here
//check point
	char	buf[MAX_PATH];
	m_edLeft.GetLine( 0, (LPTSTR)buf, MAX_PATH );

	double val = atof( buf ) + pNMUpDown->iDelta;
	CGS_GetSpinControlNextValue( PAGE_LEFT_MARGIN, pNMUpDown->iDelta, &val );

	val = val < 100 ? val : 100; // range checking
	val = val < 0   ? 0   : val;

	DoubleToAlphaString( val, 2, (LPTSTR)buf );
	m_edLeft.SetWindowText( (LPTSTR)buf );
	
	*pResult = 0;
}//end of CPageSetupDlg::OnDeltaposSpnPsLeft
///////////////////////////////////////////////////////////////////////////////////////////////
void CPageSetupDlg::OnDeltaposSpnPsRight(NMHDR* pNMHDR, LRESULT* pResult) 
{
	TRACE0("PageSetupDlg.cpp - OnDeltaposSpnPsRight()\n" );
	NM_UPDOWN* pNMUpDown = (NM_UPDOWN*)pNMHDR;
	
	// TODO: Add your control notification handler code here
	char	buf[MAX_PATH];
	m_edRight.GetLine( 0, (LPTSTR)buf, MAX_PATH );

	double val = atof( buf ) + pNMUpDown->iDelta;
	CGS_GetSpinControlNextValue( PAGE_RIGHT_MARGIN, pNMUpDown->iDelta, &val );

	val = val < 100 ? val : 100; // range checking
	val = val < 0   ? 0   : val;

	DoubleToAlphaString( val, 2, (LPTSTR)buf );
	m_edRight.SetWindowText( (LPTSTR)buf );
	
	*pResult = 0;
}//end of CPageSetupDlg::OnDeltaposSpnPsRight
///////////////////////////////////////////////////////////////////////////////////////////////
void CPageSetupDlg::OnDeltaposSpnPsHori(NMHDR* pNMHDR, LRESULT* pResult) 
{
	NM_UPDOWN* pNMUpDown = (NM_UPDOWN*)pNMHDR;
	// TODO: Add your control notification handler code here
	
	*pResult = 0;
}//end of CPageSetupDlg::OnDeltaposSpnPsHori
///////////////////////////////////////////////////////////////////////////////////////////////
void CPageSetupDlg::OnDeltaposSpnPsHoriOffset(NMHDR* pNMHDR, LRESULT* pResult) 
{
	NM_UPDOWN* pNMUpDown = (NM_UPDOWN*)pNMHDR;
	// TODO: Add your control notification handler code here
	
	*pResult = 0;
}//end of CPageSetupDlg::OnDeltaposSpnPsHoriOffset
///////////////////////////////////////////////////////////////////////////////////////////////
void CPageSetupDlg::OnDeltaposSpnPsHoriSpace(NMHDR* pNMHDR, LRESULT* pResult) 
{
	NM_UPDOWN* pNMUpDown = (NM_UPDOWN*)pNMHDR;
	// TODO: Add your control notification handler code here
	
	*pResult = 0;
}//end of CPageSetupDlg::OnDeltaposSpnPsHoriSpace
///////////////////////////////////////////////////////////////////////////////////////////////
void CPageSetupDlg::OnDeltaposSpnPsResHeight(NMHDR* pNMHDR, LRESULT* pResult) 
{
	NM_UPDOWN* pNMUpDown = (NM_UPDOWN*)pNMHDR;
	// TODO: Add your control notification handler code here
	
	*pResult = 0;
}//end of CPageSetupDlg::OnDeltaposSpnPsResHeight
///////////////////////////////////////////////////////////////////////////////////////////////
void CPageSetupDlg::OnDeltaposSpnPsResWidth(NMHDR* pNMHDR, LRESULT* pResult) 
{
	NM_UPDOWN* pNMUpDown = (NM_UPDOWN*)pNMHDR;
	// TODO: Add your control notification handler code here
	
	*pResult = 0;
}//end of CPageSetupDlg::OnDeltaposSpnPsResWidth
///////////////////////////////////////////////////////////////////////////////////////////////
void CPageSetupDlg::OnDeltaposSpnPsSta(NMHDR* pNMHDR, LRESULT* pResult) 
{
	NM_UPDOWN* pNMUpDown = (NM_UPDOWN*)pNMHDR;
	// TODO: Add your control notification handler code here
	
	*pResult = 0;
}//end of CPageSetupDlg::OnDeltaposSpnPsSta
///////////////////////////////////////////////////////////////////////////////////////////////
void CPageSetupDlg::OnDeltaposSpnPsVert(NMHDR* pNMHDR, LRESULT* pResult) 
{
	NM_UPDOWN* pNMUpDown = (NM_UPDOWN*)pNMHDR;
	// TODO: Add your control notification handler code here
	
	*pResult = 0;
}//end of CPageSetupDlg::OnDeltaposSpnPsVert
///////////////////////////////////////////////////////////////////////////////////////////////
void CPageSetupDlg::OnDeltaposSpnPsVertOffset(NMHDR* pNMHDR, LRESULT* pResult) 
{
	NM_UPDOWN* pNMUpDown = (NM_UPDOWN*)pNMHDR;
	// TODO: Add your control notification handler code here
	
	*pResult = 0;
}//end of CPageSetupDlg::OnDeltaposSpnPsVertOffset
///////////////////////////////////////////////////////////////////////////////////////////////
void CPageSetupDlg::OnDeltaposSpnPsVertSpace(NMHDR* pNMHDR, LRESULT* pResult) 
{
	NM_UPDOWN* pNMUpDown = (NM_UPDOWN*)pNMHDR;
	// TODO: Add your control notification handler code here
	
	*pResult = 0;
}//end of CPageSetupDlg::OnDeltaposSpnPsVertSpace
///////////////////////////////////////////////////////////////////////////////////////////////
void CPageSetupDlg::OnRb43() 
{
	
}//end of CPageSetupDlg::OnRb43
///////////////////////////////////////////////////////////////////////////////////////////////
void CPageSetupDlg::OnRb169() 
{
	
}//end of CPageSetupDlg::OnRb169
///////////////////////////////////////////////////////////////////////////////////////////////
void CPageSetupDlg::OnRbSqrPixel() 
{
	
}//end of CPageSetupDlg::OnRbSqrPixel
