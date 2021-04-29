/* COPYRIGHT NOTICE:
********************************************************
*  Copyright (c) 2000 InnoVision Technology, Inc.      *
*  All rights reserved.                                *
*  PROPRIETARY AND CONFIDENTIAL                        *
*  DO NOT DISTRIBUTE                                   *
********************************************************
*/
// AttribLine.cpp : implementation file
//

#include "stdafx.h"
#include "cgui.h"
#include "AttribLine.h"
#include "Global.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CAttribLine dialog

CAttribLine::CAttribLine(CWnd* pParent /*=NULL*/) : CDialog(CAttribLine::IDD, pParent)
{
	//{{AFX_DATA_INIT(CAttribLine)
	m_edBevel	 = 0;
	m_edLength	 = 0;
	m_edPriority = 0;
	m_edRotate	 = 0;
	m_edThick	 = 0;
	m_edX		 = 0;
	m_edY		 = 0;
	m_edVPercent = 0;
	m_edRoundness= 0.0;
	//}}AFX_DATA_INIT
}


void CAttribLine::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CAttribLine)
	DDX_Control(pDX, IDC_ED_ROUNDNESS, m_ctlEdRoundness);
	DDX_Control(pDX, IDC_ED_L_Y, m_ctlEdY);
	DDX_Control(pDX, IDC_ED_L_X, m_ctlEdX);
	DDX_Control(pDX, IDC_ED_L_THICK, m_ctlEdThick);
	DDX_Control(pDX, IDC_ED_L_ROTATION, m_ctlEdRotate);
	DDX_Control(pDX, IDC_ED_L_PRIORITY, m_ctlEdPriority);
	DDX_Control(pDX, IDC_ED_L_LENGTH, m_ctlEdLength);
	DDX_Control(pDX, IDC_ED_L_BEVEL, m_ctlEdBevel);
	DDX_Control(pDX, IDC_BT_SAVE_STYLE, m_btSaveStyle);
	DDX_Control(pDX, IDC_BT_ADVANCE, m_btAdvance);
	DDX_Control(pDX, IDC_STC_V_PERCENT, m_stcVPercent);
	DDX_Control(pDX, IDC_STC_L_Y, m_stcY);
	DDX_Control(pDX, IDC_STC_L_X, m_stcX);
	DDX_Control(pDX, IDC_STC_L_THICK, m_stcThick);
	DDX_Control(pDX, IDC_STC_L_ROTATION, m_stcRotate);
	DDX_Control(pDX, IDC_STC_L_LENGTH, m_stcLength);
	DDX_Control(pDX, IDC_STC_L_BEVEL, m_stcBevel);
	DDX_Control(pDX, IDC_STC_ROUNDNESS, m_stcRoundness);
	DDX_Control(pDX, IDC_BT_L_PLUS, m_btPlus);
	DDX_Control(pDX, IDC_BT_L_MINUS, m_btMinus);
	DDX_Control(pDX, IDC_BT_L_LOCK, m_btLock);
	DDX_Control(pDX, IDC_BT_L_F, m_btF);
	DDX_Control(pDX, IDC_BT_L_B, m_btB);
	DDX_Text(pDX, IDC_ED_L_BEVEL, m_edBevel);
	DDX_Text(pDX, IDC_ED_L_LENGTH, m_edLength);
	DDX_Text(pDX, IDC_ED_L_PRIORITY, m_edPriority);
	DDX_Text(pDX, IDC_ED_L_ROTATION, m_edRotate);
	DDX_Text(pDX, IDC_ED_L_THICK, m_edThick);
	DDX_Text(pDX, IDC_ED_L_X, m_edX);
	DDX_Text(pDX, IDC_ED_L_Y, m_edY);
	DDX_Text(pDX, IDC_ED_V_PERCENT, m_edVPercent);
	DDX_Text(pDX, IDC_ED_ROUNDNESS, m_edRoundness);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CAttribLine, CDialog)
	//{{AFX_MSG_MAP(CAttribLine)
	ON_BN_CLICKED(IDC_BT_L_B, OnBtLB)
	ON_BN_CLICKED(IDC_BT_L_F, OnBtLF)
	ON_BN_CLICKED(IDC_BT_L_LOCK, OnBtLLock)
	ON_BN_CLICKED(IDC_BT_L_MINUS, OnBtLMinus)
	ON_BN_CLICKED(IDC_BT_L_PLUS, OnBtLPlus)
	ON_NOTIFY(UDN_DELTAPOS, IDC_SPN_ROUNDNESS, OnDeltaposSpnRoundness)
	ON_NOTIFY(UDN_DELTAPOS, IDC_SPN_L_BEVEL, OnDeltaposSpnLBevel)
	ON_NOTIFY(UDN_DELTAPOS, IDC_SPN_L_LENGTH, OnDeltaposSpnLLength)
	ON_NOTIFY(UDN_DELTAPOS, IDC_SPN_L_PRIORITY, OnDeltaposSpnLPriority)
	ON_NOTIFY(UDN_DELTAPOS, IDC_SPN_L_ROTATE, OnDeltaposSpnLRotate)
	ON_NOTIFY(UDN_DELTAPOS, IDC_SPN_L_THICK, OnDeltaposSpnLThick)
	ON_NOTIFY(UDN_DELTAPOS, IDC_SPN_L_X, OnDeltaposSpnLX)
	ON_NOTIFY(UDN_DELTAPOS, IDC_SPN_L_Y, OnDeltaposSpnLY)
//	ON_NOTIFY(UDN_DELTAPOS, IDC_SPN_V_PERCENT, OnDeltaposSpnVPercent)
	ON_WM_PAINT()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

///////////////////////////////////////////////////////////////////////////////////////////
// CAttribLine message handlers
///////////////////////////////////////////////////////////////////////////////////////////
VOID CAttribLine::DeleteAttribLine()
{
	DestroyWindow();
}//end of CAttribLine::DeleteAttribLine()
///////////////////////////////////////////////////////////////////////////////////////////
BOOL CAttribLine::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	//++++++++++++++++++ Initial radio button and Icon
	m_btB.SetIcon( (HICON)::LoadImage( AfxGetApp()->m_hInstance, MAKEINTRESOURCE(IDI_BACK_GRD), IMAGE_ICON, 16, 16, 0) );
	m_btF.SetIcon( (HICON)::LoadImage( AfxGetApp()->m_hInstance, MAKEINTRESOURCE(IDI_FORE_GRD), IMAGE_ICON, 16, 16, 0) );
	m_btLock.SetIcon( (HICON)::LoadImage( AfxGetApp()->m_hInstance,	MAKEINTRESOURCE(IDI_LOCK), IMAGE_ICON, 16, 16, 0) );
	m_btMinus.SetIcon( (HICON)::LoadImage( AfxGetApp()->m_hInstance, MAKEINTRESOURCE(IDI_BACK_MINUS), IMAGE_ICON, 16, 16, 0) );
	m_btPlus.SetIcon( (HICON)::LoadImage( AfxGetApp()->m_hInstance,	MAKEINTRESOURCE(IDI_FORE_PLUS), IMAGE_ICON, 16, 16, 0) );
	m_btAdvance.SetIcon(  (HICON)::LoadImage( AfxGetApp()->m_hInstance, MAKEINTRESOURCE(IDI_ADVANCE),      IMAGE_ICON, 16, 16, 0) );		
	m_btSaveStyle.SetIcon( (HICON)::LoadImage( AfxGetApp()->m_hInstance, MAKEINTRESOURCE(IDI_SAVE_STYLE),   IMAGE_ICON, 16, 16, 0) );

	// ++++++++++++++++++++++++++++++++++++++++++++ Initial spin control
	CSpinButtonCtrl* pSpin = (CSpinButtonCtrl*)GetDlgItem( IDC_SPN_L_LENGTH );
	pSpin->SetRange( 1, 3000 );
	//save for ref.	pSpin->SetPos((int) (m_dSpin * 10.0));
	pSpin = (CSpinButtonCtrl*)GetDlgItem( IDC_SPN_L_THICK );
	pSpin->SetRange( 1, 64 );
	pSpin = (CSpinButtonCtrl*)GetDlgItem( IDC_SPN_ROUNDNESS );
	pSpin->SetRange( 0, 100 );
	pSpin = (CSpinButtonCtrl*)GetDlgItem( IDC_SPN_L_PRIORITY );
	pSpin->SetRange( 0, 255 );
	pSpin = (CSpinButtonCtrl*)GetDlgItem( IDC_SPN_L_ROTATE );
	pSpin->SetRange( 0, 359 );
	pSpin = (CSpinButtonCtrl*)GetDlgItem( IDC_SPN_L_BEVEL );
	pSpin->SetRange( 0, 64 );
//	pSpin = (CSpinButtonCtrl*)GetDlgItem( IDC_SPN_V_PERCENT );
//	pSpin->SetRange( 0, 100 );
	pSpin = (CSpinButtonCtrl*)GetDlgItem( IDC_SPN_L_X );
	pSpin->SetRange( -3000, 3000 );
	pSpin = (CSpinButtonCtrl*)GetDlgItem( IDC_SPN_L_Y );
	pSpin->SetRange( -3000, 3000 );

	//+++++++++++++++++++++++++++++++++++++++++++++ Initial Edit control
	_TCHAR buf[MAX_PATH];
	CEdit* pEdCtrl = (CEdit*)GetDlgItem( IDC_ED_L_THICK );
	pEdCtrl->SetLimitText( 2 ); // 2 characters of 64
	DoubleToAlphaString( CGS_GetValDbl(EDIT_OBJ_STROKE_THICKNESS), 1, buf );
	char* pSubStr = strstr( buf, ".0" );		// strip the floating part if 25.0
	if( pSubStr != NULL )						// ie: display 25 only
		*pSubStr = '\0';
	SetDlgItemText(IDC_ED_L_THICK, buf );

	pEdCtrl = (CEdit*)GetDlgItem( IDC_ED_L_LENGTH );
	pEdCtrl->SetLimitText( 7 ); // 7 characters of 3000.00
	DoubleToAlphaString( CGS_GetValDbl(EDIT_OBJ_STROKE_LENGTH), 1, buf );
	pSubStr = strstr( buf, ".0" );		// strip the floating part if 25.0
	if( pSubStr != NULL )				// ie: display 25 only
		*pSubStr = '\0';
	SetDlgItemText(IDC_ED_L_LENGTH, buf );
	
	pEdCtrl = (CEdit*)GetDlgItem( IDC_ED_ROUNDNESS );
	pEdCtrl->SetLimitText( 3 ); // 3 characters of 100
	DoubleToAlphaString( CGS_GetValDbl(EDIT_OBJ_ROUNDNESS), 1, buf );
	pSubStr = strstr( buf, ".0" );		// strip the floating part if 25.0
	if( pSubStr != NULL )				// ie: display 25 only
		*pSubStr = '\0';
	SetDlgItemText(IDC_ED_ROUNDNESS, buf );
	
	pEdCtrl = (CEdit*)GetDlgItem( IDC_ED_L_PRIORITY );
	pEdCtrl->SetLimitText( 3 ); // 3 characters of 255 
	DoubleToAlphaString( CGS_GetValDbl(EDIT_OBJ_PRIORITY), 1, buf );
	pSubStr = strstr( buf, ".0" );		// strip the floating part if 25.0
	if( pSubStr != NULL )				// ie: display 25 only
		*pSubStr = '\0';
	SetDlgItemText(IDC_ED_L_PRIORITY, buf );
	
	pEdCtrl = (CEdit*)GetDlgItem( IDC_ED_L_BEVEL );
	pEdCtrl->SetLimitText( 2 ); // 2 characters of 64
	DoubleToAlphaString( CGS_GetValDbl(EDIT_OBJ_BEVEL_SIZE), 1, buf );
	pSubStr = strstr( buf, ".0" );		// strip the floating part if 25.0
	if( pSubStr != NULL )				// ie: display 25 only
		*pSubStr = '\0';
	SetDlgItemText(IDC_ED_L_BEVEL, buf );
	
	pEdCtrl = (CEdit*)GetDlgItem( IDC_ED_L_ROTATION );
	pEdCtrl->SetLimitText( 6 ); // 6 characters of 359.99
	DoubleToAlphaString( CGS_GetValDbl(EDIT_OBJ_ROTATION), 1, buf );
	pSubStr = strstr( buf, ".0" );		// strip the floating part if 25.0
	if( pSubStr != NULL )				// ie: display 25 only
		*pSubStr = '\0';
	SetDlgItemText(IDC_ED_L_ROTATION, buf );
	
	pEdCtrl = (CEdit*)GetDlgItem( IDC_ED_L_X );
	pEdCtrl->SetLimitText( 8 ); // 8 characters of -3000.99
	DoubleToAlphaString( CGS_GetValDbl(EDIT_OBJ_X_POSITION_ABS), 1, buf );
	pSubStr = strstr( buf, ".0" );		// strip the floating part if 25.0
	if( pSubStr != NULL )				// ie: display 25 only
		*pSubStr = '\0';
	SetDlgItemText(IDC_ED_L_X, buf );
	
	pEdCtrl = (CEdit*)GetDlgItem( IDC_ED_L_Y );
	pEdCtrl->SetLimitText( 8 ); // 8 characters of -3000.00
	DoubleToAlphaString( CGS_GetValDbl(EDIT_OBJ_Y_POSITION_ABS), 1, buf );
	pSubStr = strstr( buf, ".0" );		// strip the floating part if 25.0
	if( pSubStr != NULL )				// ie: display 25 only
		*pSubStr = '\0';
	SetDlgItemText(IDC_ED_L_Y, buf );

	//+++++++++++++++++++++++++++++++++++++++++++++ Initial Static Icon
	m_stcThick.ModifyStyle( 0, SS_ICON );
	m_stcThick.SetIcon( (HICON)::LoadImage( AfxGetApp()->m_hInstance,MAKEINTRESOURCE( IDI_FONT_WIDTH ),IMAGE_ICON, 16, 16, 0 ) );
	m_stcLength.ModifyStyle( 0, SS_ICON );
	m_stcLength.SetIcon( (HICON)::LoadImage( AfxGetApp()->m_hInstance,MAKEINTRESOURCE( IDI_FONT_HEIGHT ),	IMAGE_ICON, 16, 16, 0 ) );
	m_stcBevel.ModifyStyle( 0, SS_ICON );
	m_stcBevel.SetIcon( (HICON)::LoadImage( AfxGetApp()->m_hInstance,MAKEINTRESOURCE( IDI_BEVEL ),IMAGE_ICON, 16, 16, 0 ) );
	m_stcVPercent.ModifyStyle( 0, SS_ICON );
	m_stcVPercent.SetIcon( (HICON)::LoadImage( AfxGetApp()->m_hInstance,MAKEINTRESOURCE( IDI_V_PERCENT ),IMAGE_ICON, 16, 16, 0 ) );
	m_stcRotate.ModifyStyle( 0, SS_ICON );
	m_stcRotate.SetIcon( (HICON)::LoadImage( AfxGetApp()->m_hInstance,MAKEINTRESOURCE( IDI_ROTATE ),IMAGE_ICON, 16, 16, 0 ) );
	m_stcRoundness.ModifyStyle( 0, SS_ICON );
	m_stcRoundness.SetIcon( (HICON)::LoadImage( AfxGetApp()->m_hInstance,MAKEINTRESOURCE( IDI_H_PERCENT ),IMAGE_ICON, 16, 16, 0 ) );
	
	// ++++++++++++++++++++++++++++++++++++++++++++++++++ Create the ToolTip control.
	m_tooltip.Create(this);
	m_tooltip.Activate(TRUE);

	InitDlgItemTextNTooltip();

	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}//end of CAttribLine::OnInitDialog
///////////////////////////////////////////////////////////////////////////////////////////
BOOL CAttribLine::PreTranslateMessage(MSG* pMsg)
{
	// Let the ToolTip process this message.
	m_tooltip.RelayEvent(pMsg);

	return CDialog::PreTranslateMessage(pMsg);	// CG: This was added by the ToolTips component.
}//end of CAttribLine::PreTranslateMessage
///////////////////////////////////////////////////////////////////////////////////////////
VOID CAttribLine::InitDlgItemTextNTooltip()
{
	IN_TEXT_DATA* txtData = NULL;
	TCHAR	sep[] = _T("\"");
	TCHAR*	ptID;
	TCHAR*	ptTT;
	TCHAR*	ptEnd;

	DWORD numTxt = LoadTextFromCtl( "\\Util\\DlgLine.ctl", "[Tooltip]", &txtData );
	if( numTxt == 0 )
		return;

	for( DWORD i = 0; i < numTxt; i++ )
	{
		ptID   = _tcstok( txtData[i].szTT, sep );
		ptTT   = _tcstok( NULL, sep );
		ptEnd  = _tcstok( NULL, sep );
		if( ptEnd != 0 )
			*ptEnd = '\0';
			
		if( NULL != _tcsstr( txtData[i].szTT, _T("IDC_ED_L_PRIORITY") ) )
			txtData[i].idTT = IDC_ED_L_PRIORITY;
		else
			if( NULL != _tcsstr( txtData[i].szTT, _T("IDC_ED_L_BEVEL") ) )
				txtData[i].idTT = IDC_ED_L_BEVEL;
		else
			if( NULL != _tcsstr( txtData[i].szTT, _T("IDC_ED_ROUNDNESS") ) )
				txtData[i].idTT = IDC_ED_ROUNDNESS;
		else
			if( NULL != _tcsstr( txtData[i].szTT, _T("IDC_ED_L_THICK") ) )
				txtData[i].idTT = IDC_ED_L_THICK;
		else
			if( NULL != _tcsstr( txtData[i].szTT, _T("IDC_ED_L_ROTATION") ) )
				txtData[i].idTT = IDC_ED_L_ROTATION;
		else
			if( NULL != _tcsstr( txtData[i].szTT, _T("IDC_ED_V_PERCENT") ) )
				txtData[i].idTT = IDC_ED_V_PERCENT;
		else
			if( NULL != _tcsstr( txtData[i].szTT, _T("IDC_ED_L_LENGTH") ) )
				txtData[i].idTT = IDC_ED_L_LENGTH;
		else
			if( NULL != _tcsstr( txtData[i].szTT, _T("IDC_ED_L_X") ) )
				txtData[i].idTT = IDC_ED_L_X;
		else
			if( NULL != _tcsstr( txtData[i].szTT, _T("IDC_ED_L_Y") ) )
				txtData[i].idTT = IDC_ED_L_Y;
		else
			if( NULL != _tcsstr( txtData[i].szTT, _T("IDC_BT_L_B") ) )
				txtData[i].idTT = IDC_BT_L_B;
		else
			if( NULL != _tcsstr( txtData[i].szTT, _T("IDC_BT_L_MINUS") ) )
				txtData[i].idTT = IDC_BT_L_MINUS;
		else
			if( NULL != _tcsstr( txtData[i].szTT, _T("IDC_BT_L_PLUS") ) )
				txtData[i].idTT = IDC_BT_L_PLUS;
		else
			if( NULL != _tcsstr( txtData[i].szTT, _T("IDC_BT_L_F") ) )
				txtData[i].idTT = IDC_BT_L_F;
		else
			if( NULL != _tcsstr( txtData[i].szTT, _T("IDC_BT_L_LOCK") ) )
				txtData[i].idTT = IDC_BT_L_LOCK;
		else
			if( NULL != _tcsstr( txtData[i].szTT, _T("IDC_FRM_L_PREVIEW") ) )
				txtData[i].idTT = IDC_FRM_L_PREVIEW;
		else
			if( NULL != _tcsstr( txtData[i].szTT, _T("IDC_BT_SAVE_STYLE") ) )
				txtData[i].idTT = IDC_BT_SAVE_STYLE;
		else
			if( NULL != _tcsstr( txtData[i].szTT, _T("IDC_BT_ADVANCE") ) )
				txtData[i].idTT = IDC_BT_ADVANCE;

		_tcscpy( txtData[i].szTT, (TCHAR*)txtData[i].szTT );
		if( NULL != GetDlgItem(txtData[i].idTT) )
			m_tooltip.AddTool( GetDlgItem(txtData[i].idTT), (_TCHAR*)ptTT);
	}//end of for

	free( txtData );
}//end of CAttribLine::InitDlgItemTextNTooltip()
///////////////////////////////////////////////////////////////////////////////////////////
void CAttribLine::OnBtLB() 
{
	// TODO: Add your control notification handler code here
	AfxGetMainWnd()->SetFocus();
}//end of CAttribLine::OnBtLB
///////////////////////////////////////////////////////////////////////////////////////////
void CAttribLine::OnBtLF() 
{
	// TODO: Add your control notification handler code here
	AfxGetMainWnd()->SetFocus();
}//end of CAttribLine::OnBtLF
///////////////////////////////////////////////////////////////////////////////////////////
void CAttribLine::OnBtLLock() 
{
	// TODO: Add your control notification handler code here
	AfxGetMainWnd()->SetFocus();
}//end of CAttribLine::OnBtLLock
///////////////////////////////////////////////////////////////////////////////////////////
void CAttribLine::OnBtLMinus() 
{
	// TODO: Add your control notification handler code here
	AfxGetMainWnd()->SetFocus();
}//end of CAttribLine::OnBtLMinus
///////////////////////////////////////////////////////////////////////////////////////////
void CAttribLine::OnBtLPlus() 
{
	// TODO: Add your control notification handler code here
	AfxGetMainWnd()->SetFocus();
}//end of CAttribLine::OnBtLPlus
///////////////////////////////////////////////////////////////////////////////////////////
void CAttribLine::OnDeltaposSpnRoundness(NMHDR* pNMHDR, LRESULT* pResult) 
{
	NM_UPDOWN* pNMUpDown = (NM_UPDOWN*)pNMHDR;
	char	buf[MAX_PATH];
	m_ctlEdRoundness.GetLine( 0, (LPTSTR)buf, MAX_PATH );	// get edit control value

	// Convert the control value + the increment
	double val = atof( buf ) + (double)pNMUpDown->iDelta;
	val = val < 100 ? val : 100; // range checking
	val = val < 0   ? 0   : val;

	CGS_SetValDbl( EDIT_OBJ_ROUNDNESS, val );

	// Conver the double value to string for display
	DoubleToAlphaString( val, 1, (LPTSTR)buf );	// 1 means one digit after decimal point
	char* pSubStr = strstr( buf, ".0" );		// strip the floating part if 25.0
	if( pSubStr != NULL )						// ie: display 25 only
		*pSubStr = '\0';
	m_ctlEdRoundness.SetWindowText( (LPTSTR)buf );

	AfxGetMainWnd()->SetFocus();
	*pResult = 0;
}//end of CAttribLine::OnDeltaposSpnRoundness
///////////////////////////////////////////////////////////////////////////////////////////
void CAttribLine::OnDeltaposSpnLBevel(NMHDR* pNMHDR, LRESULT* pResult) 
{
	NM_UPDOWN* pNMUpDown = (NM_UPDOWN*)pNMHDR;
	char	buf[MAX_PATH];
	m_ctlEdBevel.GetLine( 0, (LPTSTR)buf, MAX_PATH );	// get edit control value

	// Convert the control value + the increment
	double val = atof( buf ) + (double)pNMUpDown->iDelta;
	val = val < 64 ? val : 64; // range checking
	val = val < 0  ? 0   : val;

	CGS_SetValDbl( EDIT_OBJ_BEVEL_SIZE, val );

	// Conver the double value to string for display
	DoubleToAlphaString( val, 1, (LPTSTR)buf );	// 1 means one digit after decimal point
	char* pSubStr = strstr( buf, ".0" );		// strip the floating part if 25.0
	if( pSubStr != NULL )						// ie: display 25 only
		*pSubStr = '\0';
	m_ctlEdBevel.SetWindowText( (LPTSTR)buf );

	AfxGetMainWnd()->SetFocus();
	*pResult = 0;
}//end of CAttribLine::OnDeltaposSpnLBevel
///////////////////////////////////////////////////////////////////////////////////////////
void CAttribLine::OnDeltaposSpnLLength(NMHDR* pNMHDR, LRESULT* pResult) 
{
	NM_UPDOWN* pNMUpDown = (NM_UPDOWN*)pNMHDR;
	char	buf[MAX_PATH];
	m_ctlEdLength.GetLine( 0, (LPTSTR)buf, MAX_PATH );	// get edit control value

	// Convert the control value + the increment
	double val = atof( buf ) + (double)pNMUpDown->iDelta;
	val = val < 3000 ? val : 3000; // range checking
	val = val < 1    ? 1   : val;

	CGS_SetValDbl( EDIT_OBJ_STROKE_LENGTH, val );

	// Conver the double value to string for display
	DoubleToAlphaString( val, 1, (LPTSTR)buf );	// 1 means one digit after decimal point
	char* pSubStr = strstr( buf, ".0" );		// strip the floating part if 25.0
	if( pSubStr != NULL )						// ie: display 25 only
		*pSubStr = '\0';
	m_ctlEdLength.SetWindowText( (LPTSTR)buf );

	AfxGetMainWnd()->SetFocus();
	*pResult = 0;
}//end of CAttribLine::OnDeltaposSpnLLength
///////////////////////////////////////////////////////////////////////////////////////////
void CAttribLine::OnDeltaposSpnLPriority(NMHDR* pNMHDR, LRESULT* pResult) 
{
	NM_UPDOWN* pNMUpDown = (NM_UPDOWN*)pNMHDR;
	int val = pNMUpDown->iPos+pNMUpDown->iDelta;
	CGS_SetValDbl( EDIT_OBJ_PRIORITY, max(0, val) );

	AfxGetMainWnd()->SetFocus();
	*pResult = 0;
}//end of CAttribLine::OnDeltaposSpnLPriority
///////////////////////////////////////////////////////////////////////////////////////////
void CAttribLine::OnDeltaposSpnLRotate(NMHDR* pNMHDR, LRESULT* pResult) 
{
	NM_UPDOWN* pNMUpDown = (NM_UPDOWN*)pNMHDR;
	char	buf[MAX_PATH];
	m_ctlEdRotate.GetLine( 0, (LPTSTR)buf, MAX_PATH );	// get edit control value

	// Convert the control value + the increment
	double val = atof( buf ) + (double)pNMUpDown->iDelta;
	val = val < 360 ? val : 360; // range checking
	val = val < 0   ? 0   : val;

	CGS_SetValDbl( EDIT_OBJ_ROTATION, val );

	// Conver the double value to string for display
	DoubleToAlphaString( val, 1, (LPTSTR)buf );	// 1 means one digit after decimal point
	char* pSubStr = strstr( buf, ".0" );		// strip the floating part if 25.0
	if( pSubStr != NULL )						// ie: display 25 only
		*pSubStr = '\0';
	m_ctlEdRotate.SetWindowText( (LPTSTR)buf );

	AfxGetMainWnd()->SetFocus();
	*pResult = 0;
}//end of CAttribLine::OnDeltaposSpnLRotate
///////////////////////////////////////////////////////////////////////////////////////////
void CAttribLine::OnDeltaposSpnLThick(NMHDR* pNMHDR, LRESULT* pResult) 
{
	NM_UPDOWN* pNMUpDown = (NM_UPDOWN*)pNMHDR;
	char	buf[MAX_PATH];
	m_ctlEdThick.GetLine( 0, (LPTSTR)buf, MAX_PATH );	// get edit control value

	// Convert the control value + the increment
	double val = atof( buf ) + (double)pNMUpDown->iDelta;
	val = val < 64 ? val : 64; // range checking
	val = val < 1  ? 1   : val;

	CGS_SetValDbl( EDIT_OBJ_STROKE_THICKNESS, val );

	// Conver the double value to string for display
	DoubleToAlphaString( val, 1, (LPTSTR)buf );	// 1 means one digit after decimal point
	char* pSubStr = strstr( buf, ".0" );		// strip the floating part if 25.0
	if( pSubStr != NULL )						// ie: display 25 only
		*pSubStr = '\0';
	m_ctlEdThick.SetWindowText( (LPTSTR)buf );

	AfxGetMainWnd()->SetFocus();
	*pResult = 0;
}//end of CAttribLine::OnDeltaposSpnLThick
///////////////////////////////////////////////////////////////////////////////////////////
void CAttribLine::OnDeltaposSpnLX(NMHDR* pNMHDR, LRESULT* pResult) 
{
	NM_UPDOWN* pNMUpDown = (NM_UPDOWN*)pNMHDR;
	char	buf[MAX_PATH];
	m_ctlEdX.GetLine( 0, (LPTSTR)buf, MAX_PATH );	// get edit control value

	// Convert the control value + the increment
	double val = atof( buf ) + (double)pNMUpDown->iDelta;
	val = val <  3000 ? val   : 3000; // range checking
	val = val < -3000 ? -3000 : val;

	CGS_SetValDbl( EDIT_OBJ_X_POSITION_ABS, val );

	// Conver the double value to string for display
	DoubleToAlphaString( val, 1, (LPTSTR)buf );	// 1 means one digit after decimal point
	char* pSubStr = strstr( buf, ".0" );		// strip the floating part if 25.0
	if( pSubStr != NULL )						// ie: display 25 only
		*pSubStr = '\0';
	m_ctlEdX.SetWindowText( (LPTSTR)buf );

	AfxGetMainWnd()->SetFocus();
	*pResult = 0;
}//end of CAttribLine::OnDeltaposSpnLX
///////////////////////////////////////////////////////////////////////////////////////////
void CAttribLine::OnDeltaposSpnLY(NMHDR* pNMHDR, LRESULT* pResult) 
{
	NM_UPDOWN* pNMUpDown = (NM_UPDOWN*)pNMHDR;
	char	buf[MAX_PATH];
	m_ctlEdY.GetLine( 0, (LPTSTR)buf, MAX_PATH );	// get edit control value

	// Convert the control value + the increment
	double val = atof( buf ) + (double)pNMUpDown->iDelta;
	val = val <  3000 ?  val  : 3000; // range checking
	val = val < -3000 ? -3000 : val;

	CGS_SetValDbl( EDIT_OBJ_Y_POSITION_ABS, val );

	// Conver the double value to string for display
	DoubleToAlphaString( val, 1, (LPTSTR)buf );	// 1 means one digit after decimal point
	char* pSubStr = strstr( buf, ".0" );		// strip the floating part if 25.0
	if( pSubStr != NULL )						// ie: display 25 only
		*pSubStr = '\0';
	m_ctlEdY.SetWindowText( (LPTSTR)buf );

	AfxGetMainWnd()->SetFocus();
	*pResult = 0;
}//end of CAttribLine::OnDeltaposSpnLY
///////////////////////////////////////////////////////////////////////////////////////////
/****
void CAttribLine::OnDeltaposSpnVPercent(NMHDR* pNMHDR, LRESULT* pResult) 
{
	NM_UPDOWN* pNMUpDown = (NM_UPDOWN*)pNMHDR;
	// TODO: Add your control notification handler code here
	AfxGetMainWnd()->SetFocus();
	*pResult = 0;
}//end of CAttribLine::OnDeltaposSpnVPercent
***/
///////////////////////////////////////////////////////////////////////////////////////////
VOID CAttribLine::DoValueUpdate()
{
	TRACE0("AttribLine.cpp : CAttribLine::DoValueUpdate()\n");
}//end of CAttribLine::DoValueUpdate()
///////////////////////////////////////////////////////////////////////////////////////////
void CAttribLine::OnOK() 
{
	DWORD	edValue = GetDlgItemInt( IDC_ED_L_LENGTH, NULL, 0 );
	if( edValue != m_edLength )
	{
		m_edLength = edValue;
		TRACE(_T("\t m_edLength = %d\n"), m_edLength );
		CGS_SetValDbl( EDIT_OBJ_STROKE_LENGTH, (double)m_edLength );
	}
	edValue = GetDlgItemInt( IDC_ED_L_THICK, NULL, 0 );
	if( edValue != m_edThick )
	{
		m_edThick = edValue;
		TRACE(_T("\t m_edThick = %d\n"), m_edThick );
		CGS_SetValDbl( EDIT_OBJ_STROKE_THICKNESS, (double)m_edThick );
	}
	edValue = GetDlgItemInt( IDC_ED_ROUNDNESS, NULL, 0 );
	if( edValue != m_edRoundness )
	{
		m_edRoundness = edValue;
		TRACE(_T("\t m_edRoundness = %d\n"), m_edRoundness );
		CGS_SetValDbl( EDIT_OBJ_ROUNDNESS, (double)m_edRoundness );
	}
	edValue = GetDlgItemInt( IDC_ED_L_ROTATION, NULL, 0 );
	if( edValue != m_edRotate )
	{
		m_edRotate = edValue;
		TRACE(_T("\t m_edRotate = %d\n"), m_edRotate );
		CGS_SetValDbl( EDIT_OBJ_ROTATION, (double)m_edRotate );
	}
	edValue = GetDlgItemInt( IDC_ED_L_BEVEL, NULL, 0 );
	if( edValue != m_edBevel )
	{
		m_edBevel = edValue;
		TRACE(_T("\t m_edBevel = %d\n"), m_edBevel );
		CGS_SetValDbl( EDIT_OBJ_BEVEL_SIZE, (double)m_edBevel );
	}
	edValue = GetDlgItemInt( IDC_ED_L_PRIORITY, NULL, 0 );
	if( edValue != m_edPriority )
	{
		m_edPriority = edValue;
		TRACE(_T("\t m_edPriority = %d\n"), m_edPriority );
		CGS_SetValDbl( EDIT_OBJ_PRIORITY, (double)m_edPriority );
	}
	edValue = GetDlgItemInt( IDC_ED_L_X, NULL, 0 );
	if( edValue != m_edX )
	{
		m_edX = edValue;
		TRACE(_T("\t m_edX = %d\n"), m_edX );
		CGS_SetValDbl( EDIT_OBJ_X_POSITION_ABS, (double)m_edX );
	}
	edValue = GetDlgItemInt( IDC_ED_L_Y, NULL, 0 );
	if( edValue != m_edY )
	{
		m_edY = edValue;
		TRACE(_T("\t m_edY = %d\n"), m_edY );
		CGS_SetValDbl( EDIT_OBJ_Y_POSITION_ABS, (double)m_edY );
	}

	AfxGetMainWnd()->SetFocus();	

}//end of CAttribLine::OnOK() 
///////////////////////////////////////////////////////////////////////////////////////////
void CAttribLine::OnCancel() 
{
	// capture cancel message
}//end of CAttribLine::OnCancel() 
///////////////////////////////////////////////////////////////////////////////////////////
void CAttribLine::OnPaint() 
{
	CPaintDC dc(this); // device context for painting
	
	CGS_CurAttrSample_OnPaint( (DWORD)GetDlgItem( IDC_FRM_L_PREVIEW )->m_hWnd );	
	// Do not call CDialog::OnPaint() for painting messages
}//end of CAttribLine::OnPaint()
