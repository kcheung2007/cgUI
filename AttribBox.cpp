/* COPYRIGHT NOTICE:
********************************************************
*  Copyright (c) 2000 InnoVision Technology, Inc.      *
*  All rights reserved.                                *
*  PROPRIETARY AND CONFIDENTIAL                        *
*  DO NOT DISTRIBUTE                                   *
********************************************************
*/
// AttribBox.cpp : implementation file
//

#include "stdafx.h"
#include "cgui.h"
#include "AttribBox.h"
#include "Global.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

///////////////////////////////////////////////////////////////////////////////////////
// CAttribBox dialog
///////////////////////////////////////////////////////////////////////////////////////
CAttribBox::CAttribBox(CWnd* pParent /*=NULL*/)	: CDialog(CAttribBox::IDD, pParent)
{
	//{{AFX_DATA_INIT(CAttribBox)
	m_edBevel	= 0;
	m_edHeight	= 0;
	m_edPriority= 0;
	m_edRotate	= 0;
	m_edWidth	= 0;
	m_edX		= 0;
	m_edY		= 0;
	m_edRound	= 0;
	m_edVPercent= 0;
	//}}AFX_DATA_INIT
}
///////////////////////////////////////////////////////////////////////////////////////
void CAttribBox::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CAttribBox)
	DDX_Control(pDX, IDC_ED_ROUNDNESS, m_ctlEdRound);
	DDX_Control(pDX, IDC_ED_B_Y, m_ctlEdY);
	DDX_Control(pDX, IDC_ED_B_X, m_ctlEdX);
	DDX_Control(pDX, IDC_ED_B_WIDTH, m_ctlEdWidth);
	DDX_Control(pDX, IDC_ED_B_ROTATION, m_ctlEdRotate);
	DDX_Control(pDX, IDC_ED_B_PRIORITY, m_ctlEdPriority);
	DDX_Control(pDX, IDC_ED_B_HEIGHT, m_ctlEdHeight);
	DDX_Control(pDX, IDC_ED_B_BEVEL, m_ctlEdBevel);
	DDX_Control(pDX, IDC_BT_ADVANCE, m_btAdvance);
	DDX_Control(pDX, IDC_BT_SAVE_STYLE, m_btSaveStyle);
	DDX_Control(pDX, IDC_STC_V_PERCENT, m_stcVPercent);
	DDX_Control(pDX, IDC_STC_ROUNDNESS, m_stcRoundness);
	DDX_Control(pDX, IDC_STC_B_Y, m_stcY);
	DDX_Control(pDX, IDC_STC_B_X, m_stcX);
	DDX_Control(pDX, IDC_STC_B_WIDTH, m_stcWidth);
	DDX_Control(pDX, IDC_STC_B_ROTATION, m_stcRotate);
	DDX_Control(pDX, IDC_STC_B_HEIGHT, m_stcHeight);
	DDX_Control(pDX, IDC_STC_B_BEVEL, m_stcBevel);
	DDX_Control(pDX, IDC_BT_B_PLUS, m_btPlus);
	DDX_Control(pDX, IDC_BT_B_MINUS, m_btMinus);
	DDX_Control(pDX, IDC_BT_B_LOCK, m_btLock);
	DDX_Control(pDX, IDC_BT_B_F, m_btF);
	DDX_Control(pDX, IDC_BT_B_B, m_btB);
	DDX_Text(pDX, IDC_ED_B_BEVEL, m_edBevel);
	DDX_Text(pDX, IDC_ED_B_HEIGHT, m_edHeight);
	DDX_Text(pDX, IDC_ED_B_PRIORITY, m_edPriority);
	DDX_Text(pDX, IDC_ED_B_ROTATION, m_edRotate);
	DDX_Text(pDX, IDC_ED_B_WIDTH, m_edWidth);
	DDX_Text(pDX, IDC_ED_B_X, m_edX);
	DDX_Text(pDX, IDC_ED_B_Y, m_edY);
	DDX_Text(pDX, IDC_ED_ROUNDNESS, m_edRound);
	DDX_Text(pDX, IDC_ED_V_PERCENT, m_edVPercent);
	//}}AFX_DATA_MAP
}

///////////////////////////////////////////////////////////////////////////////////////
BEGIN_MESSAGE_MAP(CAttribBox, CDialog)
	//{{AFX_MSG_MAP(CAttribBox)
	ON_BN_CLICKED(IDC_BT_B_B, OnBtBB)
	ON_BN_CLICKED(IDC_BT_B_F, OnBtBF)
	ON_BN_CLICKED(IDC_BT_B_LOCK, OnBtBLock)
	ON_BN_CLICKED(IDC_BT_B_MINUS, OnBtBMinus)
	ON_BN_CLICKED(IDC_BT_B_PLUS, OnBtBPlus)
	ON_NOTIFY(UDN_DELTAPOS, IDC_SPN_B_BEVEL, OnDeltaposSpnBBevel)
	ON_NOTIFY(UDN_DELTAPOS, IDC_SPN_B_HEIGHT, OnDeltaposSpnBHeight)
	ON_NOTIFY(UDN_DELTAPOS, IDC_SPN_B_PRIORITY, OnDeltaposSpnBPriority)
	ON_NOTIFY(UDN_DELTAPOS, IDC_SPN_B_ROTATE, OnDeltaposSpnBRotate)
	ON_NOTIFY(UDN_DELTAPOS, IDC_SPN_B_WIDTH, OnDeltaposSpnBWidth)
	ON_NOTIFY(UDN_DELTAPOS, IDC_SPN_B_X, OnDeltaposSpnBX)
	ON_NOTIFY(UDN_DELTAPOS, IDC_SPN_B_Y, OnDeltaposSpnBY)
	ON_NOTIFY(UDN_DELTAPOS, IDC_SPN_ROUNDNESS, OnDeltaposSpnRoundness)
//	ON_NOTIFY(UDN_DELTAPOS, IDC_SPN_V_PERCENT, OnDeltaposSpnVPercent)
	ON_WM_PAINT()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

///////////////////////////////////////////////////////////////////////////////////////
// CAttribBox message handlers
///////////////////////////////////////////////////////////////////////////////////////
VOID CAttribBox::DeleteAttribBox()
{
	DestroyWindow();

}//end of CAttribBox::DeleteAttribBox()
///////////////////////////////////////////////////////////////////////////////////////
void CAttribBox::OnOK() 
{
	_TCHAR	buf[MAX_PATH];
	double  edValue;

	GetDlgItemText( IDC_ED_B_HEIGHT, buf, MAX_PATH );
	edValue = atof( buf );
	if( edValue != m_edHeight )
	{
		m_edHeight = edValue;
		TRACE(_T("\t m_edHeight = %d\n"), m_edHeight );
		CGS_SetValDbl( EDIT_OBJ_HEIGHT_ABS, (double)m_edHeight );
	}
	GetDlgItemText( IDC_ED_ROUNDNESS, buf, MAX_PATH );
	edValue = atof( buf );
	if( edValue != m_edRound )
	{
		m_edRound = edValue;
		TRACE(_T("\t m_edRound = %d\n"), m_edRound );
		CGS_SetValDbl( EDIT_OBJ_ROUNDNESS, (double)m_edRound );
	}
	GetDlgItemText( IDC_ED_B_ROTATION, buf, MAX_PATH );
	edValue = atof( buf );
	if( edValue != m_edRotate )
	{
		m_edRotate = edValue;
		TRACE(_T("\t m_edRotate = %d\n"), m_edRotate );
		CGS_SetValDbl( EDIT_OBJ_ROTATION, (double)m_edRotate );
	}
	GetDlgItemText( IDC_ED_B_WIDTH, buf, MAX_PATH );
	edValue = atof( buf );
	if( edValue != m_edWidth )
	{
		m_edWidth = edValue;
		TRACE(_T("\t m_edWidth = %d\n"), m_edWidth );
		CGS_SetValDbl( EDIT_OBJ_WIDTH_ABS, (double)m_edWidth );
	}
	GetDlgItemText( IDC_ED_B_BEVEL, buf, MAX_PATH );
	edValue = atof( buf );
	if( edValue != m_edBevel )
	{
		m_edBevel = edValue;
		TRACE(_T("\t m_edBevel = %d\n"), m_edBevel );
		CGS_SetValDbl( EDIT_OBJ_BEVEL_SIZE, (double)m_edBevel );
	}
	GetDlgItemText( IDC_ED_B_PRIORITY, buf, MAX_PATH );
	edValue = atof( buf );
	if( edValue != m_edPriority )
	{
		m_edPriority = edValue;
		TRACE(_T("\t m_edPriority = %d\n"), m_edPriority );
		CGS_SetValDbl( EDIT_OBJ_PRIORITY, (double)m_edPriority );
	}
	GetDlgItemText( IDC_ED_B_X, buf, MAX_PATH );
	edValue = atof( buf );
	if( edValue != m_edX )
	{
		m_edX = edValue;
		TRACE(_T("\t m_edX = %d\n"), m_edX );
		CGS_SetValDbl( EDIT_OBJ_X_POSITION_ABS, (double)m_edX );
	}
	GetDlgItemText( IDC_ED_B_Y, buf, MAX_PATH );
	edValue = atof( buf );
	if( edValue != m_edY )
	{
		m_edY = edValue;
		TRACE(_T("\t m_edY = %d\n"), m_edY );
		CGS_SetValDbl( EDIT_OBJ_Y_POSITION_ABS, (double)m_edY );
	}

	AfxGetMainWnd()->SetFocus();		
//	CDialog::OnOK();
}//end of CAttribBox::OnOK() 
///////////////////////////////////////////////////////////////////////////////////////
void CAttribBox::OnCancel() 
{
	// capture cancel message
}//end of CAttribBox::OnCancel() 
///////////////////////////////////////////////////////////////////////////////////////

BOOL CAttribBox::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	HINSTANCE hInst = AfxGetApp()->m_hInstance;
	//++++++++++++++++++ Initial radio button and Icon
	m_btB.SetIcon( (HICON)::LoadImage( hInst,MAKEINTRESOURCE(IDI_BACK_GRD), IMAGE_ICON, 16, 16, 0) );
	m_btF.SetIcon( (HICON)::LoadImage( hInst,MAKEINTRESOURCE(IDI_FORE_GRD), IMAGE_ICON, 16, 16, 0) );
	m_btLock.SetIcon( (HICON)::LoadImage( hInst,MAKEINTRESOURCE(IDI_LOCK), IMAGE_ICON, 16, 16, 0) );
	m_btMinus.SetIcon( (HICON)::LoadImage( hInst,MAKEINTRESOURCE(IDI_BACK_MINUS), IMAGE_ICON, 16, 16, 0) );
	m_btPlus.SetIcon( (HICON)::LoadImage( hInst,MAKEINTRESOURCE(IDI_FORE_PLUS), IMAGE_ICON, 16, 16, 0) );
	m_btAdvance.SetIcon( (HICON)::LoadImage( hInst, MAKEINTRESOURCE(IDI_ADVANCE),      IMAGE_ICON, 16, 16, 0) );		
	m_btSaveStyle.SetIcon( (HICON)::LoadImage( hInst, MAKEINTRESOURCE(IDI_SAVE_STYLE),   IMAGE_ICON, 16, 16, 0) );

	// ++++++++++++++++++++++++++++++++++++++++++++ Initial spin control
	CSpinButtonCtrl* pSpin = (CSpinButtonCtrl*)GetDlgItem( IDC_SPN_B_HEIGHT );
	pSpin->SetRange( 1, 3000 );
	//save for ref.	pSpin->SetPos((int) (m_dSpin * 10.0));
	pSpin = (CSpinButtonCtrl*)GetDlgItem( IDC_SPN_B_WIDTH );
	pSpin->SetRange( 1, 3000 );
	pSpin = (CSpinButtonCtrl*)GetDlgItem( IDC_SPN_ROUNDNESS );
	pSpin->SetRange( 0, 100 );
	pSpin = (CSpinButtonCtrl*)GetDlgItem( IDC_SPN_B_PRIORITY );
	pSpin->SetRange( 0, 255 );
	pSpin = (CSpinButtonCtrl*)GetDlgItem( IDC_SPN_B_ROTATE );
	pSpin->SetRange( 0, 359 );
	pSpin = (CSpinButtonCtrl*)GetDlgItem( IDC_SPN_B_BEVEL );
	pSpin->SetRange( 0, 64 );
//	pSpin = (CSpinButtonCtrl*)GetDlgItem( IDC_SPN_V_PERCENT );
//	pSpin->SetRange( 0, 100 );
	pSpin = (CSpinButtonCtrl*)GetDlgItem( IDC_SPN_B_X );
	pSpin->SetRange( -3000, 3000 );
	pSpin = (CSpinButtonCtrl*)GetDlgItem( IDC_SPN_B_Y );
	pSpin->SetRange( -3000, 3000 );

	//+++++++++++++++++++++++++++++++++++++++++++++ Initial Edit control
	_TCHAR buf[MAX_PATH];

	CEdit* pEdCtrl = (CEdit*)GetDlgItem( IDC_ED_B_WIDTH );
	pEdCtrl->SetLimitText( 7 ); // 7 characters of 3000.99
	DoubleToAlphaString( CGS_GetValDbl(EDIT_OBJ_WIDTH_ABS), 1, buf );
	char* pSubStr = strstr( buf, ".0" );		// strip the floating part if 25.0
	if( pSubStr != NULL )						// ie: display 25 only
		*pSubStr = '\0';
	SetDlgItemText(IDC_ED_B_WIDTH, buf );

	pEdCtrl = (CEdit*)GetDlgItem( IDC_ED_B_HEIGHT );	
	pEdCtrl->SetLimitText( 7 ); // 7 characters of 3000.99
	DoubleToAlphaString( CGS_GetValDbl(EDIT_OBJ_HEIGHT_ABS), 1, buf );
	pSubStr = strstr( buf, ".0" );		// strip the floating part if 25.0
	if( pSubStr != NULL )				// ie: display 25 only
		*pSubStr = '\0';
	SetDlgItemText(IDC_ED_B_HEIGHT, buf );
	
	pEdCtrl = (CEdit*)GetDlgItem( IDC_ED_ROUNDNESS );	
	pEdCtrl->SetLimitText( 3 ); // 3 characters of 100
	DoubleToAlphaString( CGS_GetValDbl(EDIT_OBJ_ROUNDNESS), 1, buf );
	pSubStr = strstr( buf, ".0" );		// strip the floating part if 25.0
	if( pSubStr != NULL )				// ie: display 25 only
		*pSubStr = '\0';
	SetDlgItemText(IDC_ED_ROUNDNESS, buf );
	
	pEdCtrl = (CEdit*)GetDlgItem( IDC_ED_B_PRIORITY );	
	pEdCtrl->SetLimitText( 3 ); // 3 characters of 255
	DoubleToAlphaString( CGS_GetValDbl(EDIT_OBJ_PRIORITY), 1, buf );
	pSubStr = strstr( buf, ".0" );		// strip the floating part if 25.0
	if( pSubStr != NULL )				// ie: display 25 only
		*pSubStr = '\0';
	SetDlgItemText(IDC_ED_B_PRIORITY, buf );
//	pEdCtrl = (CEdit*)GetDlgItem( IDC_ED_V_PERCENT );
//	pEdCtrl->SetLimitText( 3 ); // 3 characters of 100
	
	pEdCtrl = (CEdit*)GetDlgItem( IDC_ED_B_BEVEL );
	pEdCtrl->SetLimitText( 2 ); // 2 characters of 64
	DoubleToAlphaString( CGS_GetValDbl(EDIT_OBJ_BEVEL_SIZE), 1, buf );
	pSubStr = strstr( buf, ".0" );		// strip the floating part if 25.0
	if( pSubStr != NULL )				// ie: display 25 only
		*pSubStr = '\0';
	SetDlgItemText(IDC_ED_B_BEVEL, buf );
	
	pEdCtrl = (CEdit*)GetDlgItem( IDC_ED_B_ROTATION );
	pEdCtrl->SetLimitText( 5 ); // 3 characters of 359.99
	DoubleToAlphaString( CGS_GetValDbl(EDIT_OBJ_ROTATION), 1, buf );
	pSubStr = strstr( buf, ".0" );		// strip the floating part if 25.0
	if( pSubStr != NULL )				// ie: display 25 only
		*pSubStr = '\0';
	SetDlgItemText(IDC_ED_B_ROTATION, buf );
	
	pEdCtrl = (CEdit*)GetDlgItem( IDC_ED_B_X );
	pEdCtrl->SetLimitText( 8 ); // 8 characters of -3000.00
	DoubleToAlphaString( CGS_GetValDbl(EDIT_OBJ_X_POSITION_ABS), 1, buf );
	pSubStr = strstr( buf, ".0" );		// strip the floating part if 25.0
	if( pSubStr != NULL )				// ie: display 25 only
		*pSubStr = '\0';
	SetDlgItemText(IDC_ED_B_X, buf );
	
	pEdCtrl = (CEdit*)GetDlgItem( IDC_ED_B_Y );
	pEdCtrl->SetLimitText( 8 ); // 4 characters of -3000.00
	DoubleToAlphaString( CGS_GetValDbl(EDIT_OBJ_Y_POSITION_ABS), 1, buf );
	pSubStr = strstr( buf, ".0" );		// strip the floating part if 25.0
	if( pSubStr != NULL )				// ie: display 25 only
		*pSubStr = '\0';
	SetDlgItemText(IDC_ED_B_Y, buf );

	//+++++++++++++++++++++++++++++++++++++++++++++ Initial Static Icon
	m_stcWidth.ModifyStyle( 0, SS_ICON );
	m_stcWidth.SetIcon( (HICON)::LoadImage(hInst,MAKEINTRESOURCE(IDI_FONT_WIDTH),IMAGE_ICON, 16, 16, 0 ) );
	m_stcHeight.ModifyStyle( 0, SS_ICON );
	m_stcHeight.SetIcon( (HICON)::LoadImage(hInst,MAKEINTRESOURCE(IDI_FONT_HEIGHT),	IMAGE_ICON, 16, 16, 0 ) );
	m_stcBevel.ModifyStyle( 0, SS_ICON );
	m_stcBevel.SetIcon( (HICON)::LoadImage(hInst,MAKEINTRESOURCE(IDI_BEVEL),IMAGE_ICON, 16, 16, 0 ) );
	m_stcVPercent.ModifyStyle( 0, SS_ICON );
	m_stcVPercent.SetIcon( (HICON)::LoadImage(hInst,MAKEINTRESOURCE(IDI_V_PERCENT),IMAGE_ICON, 16, 16, 0 ) );
	m_stcRotate.ModifyStyle( 0, SS_ICON );
	m_stcRotate.SetIcon( (HICON)::LoadImage(hInst,MAKEINTRESOURCE(IDI_ROTATE),IMAGE_ICON, 16, 16, 0 ) );
	m_stcRoundness.ModifyStyle( 0, SS_ICON );
	m_stcRoundness.SetIcon( (HICON)::LoadImage(hInst,MAKEINTRESOURCE(IDI_H_PERCENT),IMAGE_ICON, 16, 16, 0 ) );
	
	//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ Create the ToolTip control.
	m_tooltip.Create(this);
	m_tooltip.Activate(TRUE);

	InitDlgItemTextNTooltip();

	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}//end of CAttribBox::OnInitDialog
///////////////////////////////////////////////////////////////////////////////////////////////////
BOOL CAttribBox::PreTranslateMessage(MSG* pMsg)
{
	// Let the ToolTip process this message.
	m_tooltip.RelayEvent(pMsg);

	return CDialog::PreTranslateMessage(pMsg);	// CG: This was added by the ToolTips component.
}//end of CAttribBox::PreTranslateMessage
///////////////////////////////////////////////////////////////////////////////////////////////////
VOID CAttribBox::InitDlgItemTextNTooltip()
{
	IN_TEXT_DATA* txtData = NULL;
	TCHAR	sep[] = _T("\"");
	TCHAR*	ptID;
	TCHAR*	ptTT;
	TCHAR*	ptEnd;

	DWORD numTxt = LoadTextFromCtl( "\\Util\\DlgBox.ctl", "[Tooltip]", &txtData );
	if( numTxt == 0 )
		return;

	for( DWORD i = 0; i < numTxt; i++ )
	{
		ptID   = _tcstok( txtData[i].szTT, sep );
		ptTT   = _tcstok( NULL, sep );
		ptEnd  = _tcstok( NULL, sep );
		if( ptEnd != 0 )
			*ptEnd = '\0';
			
		if( NULL != _tcsstr( txtData[i].szTT, _T("IDC_ED_B_PRIORITY") ) )
			txtData[i].idTT = IDC_ED_B_PRIORITY;
		else
			if( NULL != _tcsstr( txtData[i].szTT, _T("IDC_ED_B_BEVEL") ) )
				txtData[i].idTT = IDC_ED_B_BEVEL;
		else
			if( NULL != _tcsstr( txtData[i].szTT, _T("IDC_ED_ROUNDNESS") ) )
				txtData[i].idTT = IDC_ED_ROUNDNESS;
		else
			if( NULL != _tcsstr( txtData[i].szTT, _T("IDC_ED_B_WIDTH") ) )
				txtData[i].idTT = IDC_ED_B_WIDTH;
		else
			if( NULL != _tcsstr( txtData[i].szTT, _T("IDC_ED_B_ROTATION") ) )
				txtData[i].idTT = IDC_ED_B_ROTATION;
		else
			if( NULL != _tcsstr( txtData[i].szTT, _T("IDC_ED_V_PERCENT") ) )
				txtData[i].idTT = IDC_ED_V_PERCENT;
		else
			if( NULL != _tcsstr( txtData[i].szTT, _T("IDC_ED_B_HEIGHT") ) )
				txtData[i].idTT = IDC_ED_B_HEIGHT;
		else
			if( NULL != _tcsstr( txtData[i].szTT, _T("IDC_ED_B_X") ) )
				txtData[i].idTT = IDC_ED_B_X;
		else
			if( NULL != _tcsstr( txtData[i].szTT, _T("IDC_ED_B_Y") ) )
				txtData[i].idTT = IDC_ED_B_Y;
		else
			if( NULL != _tcsstr( txtData[i].szTT, _T("IDC_BT_B_B") ) )
				txtData[i].idTT = IDC_BT_B_B;
		else
			if( NULL != _tcsstr( txtData[i].szTT, _T("IDC_BT_B_MINUS") ) )
				txtData[i].idTT = IDC_BT_B_MINUS;
		else
			if( NULL != _tcsstr( txtData[i].szTT, _T("IDC_BT_B_PLUS") ) )
				txtData[i].idTT = IDC_BT_B_PLUS;
		else
			if( NULL != _tcsstr( txtData[i].szTT, _T("IDC_BT_B_F") ) )
				txtData[i].idTT = IDC_BT_B_F;
		else
			if( NULL != _tcsstr( txtData[i].szTT, _T("IDC_BT_B_LOCK") ) )
				txtData[i].idTT = IDC_BT_B_LOCK;
		else
			if( NULL != _tcsstr( txtData[i].szTT, _T("IDC_FRM_B_PREVIEW") ) )
				txtData[i].idTT = IDC_FRM_B_PREVIEW;
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
}//end of CAttribBox::InitDlgItemTextNTooltip()
///////////////////////////////////////////////////////////////////////////////////////////////////
void CAttribBox::OnBtBB() 
{
	// TODO: Add your control notification handler code here
	AfxGetMainWnd()->SetFocus();
}//end of CAttribBox::OnBtBB
///////////////////////////////////////////////////////////////////////////////////////////////////
void CAttribBox::OnBtBF() 
{
	// TODO: Add your control notification handler code here
	AfxGetMainWnd()->SetFocus();
}//end of CAttribBox::OnBtBF
///////////////////////////////////////////////////////////////////////////////////////////////////
void CAttribBox::OnBtBLock() 
{
	// TODO: Add your control notification handler code here
	AfxGetMainWnd()->SetFocus();
}//end of CAttribBox::OnBtBLock
///////////////////////////////////////////////////////////////////////////////////////////////////
void CAttribBox::OnBtBMinus() 
{
	// TODO: Add your control notification handler code here
	AfxGetMainWnd()->SetFocus();
}//end of CAttribBox::OnBtBMinus
///////////////////////////////////////////////////////////////////////////////////////////////////
void CAttribBox::OnBtBPlus() 
{
	// TODO: Add your control notification handler code here
	AfxGetMainWnd()->SetFocus();
}//end of CAttribBox::OnBtBPlus
///////////////////////////////////////////////////////////////////////////////////////////////////
void CAttribBox::OnDeltaposSpnBBevel(NMHDR* pNMHDR, LRESULT* pResult) 
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
}//end of CAttribBox::OnDeltaposSpnBBevel
///////////////////////////////////////////////////////////////////////////////////////////////////
void CAttribBox::OnDeltaposSpnBHeight(NMHDR* pNMHDR, LRESULT* pResult) 
{
	NM_UPDOWN* pNMUpDown = (NM_UPDOWN*)pNMHDR;
	char	buf[MAX_PATH];
	m_ctlEdHeight.GetLine( 0, (LPTSTR)buf, MAX_PATH );	// get edit control value

	// Convert the control value + the increment
	double val = atof( buf ) + (double)pNMUpDown->iDelta;
	val = val < 3000 ? val : 3000; // range checking
	val = val < 1    ? 1   : val;

	CGS_SetValDbl( EDIT_OBJ_HEIGHT_ABS, val );

	// Conver the double value to string for display
	DoubleToAlphaString( val, 1, (LPTSTR)buf );	// 1 means one digit after decimal point
	char* pSubStr = strstr( buf, ".0" );		// strip the floating part if 25.0
	if( pSubStr != NULL )						// ie: display 25 only
		*pSubStr = '\0';
	m_ctlEdHeight.SetWindowText( (LPTSTR)buf );

	AfxGetMainWnd()->SetFocus();
	*pResult = 0;
}//end of CAttribBox::OnDeltaposSpnBHeight
///////////////////////////////////////////////////////////////////////////////////////////////////
void CAttribBox::OnDeltaposSpnBPriority(NMHDR* pNMHDR, LRESULT* pResult) 
{
	NM_UPDOWN* pNMUpDown = (NM_UPDOWN*)pNMHDR;
	int val = pNMUpDown->iPos+pNMUpDown->iDelta;
	CGS_SetValDbl( EDIT_OBJ_PRIORITY, max(0, val) );

	AfxGetMainWnd()->SetFocus();
	*pResult = 0;
}//end of CAttribBox::OnDeltaposSpnBPriority
///////////////////////////////////////////////////////////////////////////////////////////////////
void CAttribBox::OnDeltaposSpnBRotate(NMHDR* pNMHDR, LRESULT* pResult) 
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
}//end of CAttribBox::OnDeltaposSpnBRotate
///////////////////////////////////////////////////////////////////////////////////////////////////
void CAttribBox::OnDeltaposSpnBWidth(NMHDR* pNMHDR, LRESULT* pResult) 
{
	NM_UPDOWN* pNMUpDown = (NM_UPDOWN*)pNMHDR;
	char	buf[MAX_PATH];
	m_ctlEdWidth.GetLine( 0, (LPTSTR)buf, MAX_PATH );	// get edit control value

	// Convert the control value + the increment
	double val = atof( buf ) + (double)pNMUpDown->iDelta;
	val = val < 3000 ? val : 3000; // range checking
	val = val < 0    ? 0   : val;

	CGS_SetValDbl( EDIT_OBJ_WIDTH_ABS, val );

	// Conver the double value to string for display
	DoubleToAlphaString( val, 1, (LPTSTR)buf );	// 1 means one digit after decimal point
	char* pSubStr = strstr( buf, ".0" );		// strip the floating part if 25.0
	if( pSubStr != NULL )						// ie: display 25 only
		*pSubStr = '\0';
	m_ctlEdWidth.SetWindowText( (LPTSTR)buf );

	AfxGetMainWnd()->SetFocus();
	*pResult = 0;
}//end of CAttribBox::OnDeltaposSpnBWidth
///////////////////////////////////////////////////////////////////////////////////////////////////
void CAttribBox::OnDeltaposSpnBX(NMHDR* pNMHDR, LRESULT* pResult) 
{
	NM_UPDOWN* pNMUpDown = (NM_UPDOWN*)pNMHDR;
	char	buf[MAX_PATH];
	m_ctlEdX.GetLine( 0, (LPTSTR)buf, MAX_PATH );	// get edit control value

	// Convert the control value + the increment
	double val = atof( buf ) + (double)pNMUpDown->iDelta;
	val = val <  3000 ?   val : 3000; // range checking
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
}//end of CAttribBox::OnDeltaposSpnBX
///////////////////////////////////////////////////////////////////////////////////////////////////
void CAttribBox::OnDeltaposSpnBY(NMHDR* pNMHDR, LRESULT* pResult) 
{
	NM_UPDOWN* pNMUpDown = (NM_UPDOWN*)pNMHDR;
	char	buf[MAX_PATH];
	m_ctlEdY.GetLine( 0, (LPTSTR)buf, MAX_PATH );	// get edit control value

	// Convert the control value + the increment
	double val = atof( buf ) + (double)pNMUpDown->iDelta;
	val = val <  3000 ? val   : 3000; // range checking
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
}//end of CAttribBox::OnDeltaposSpnBY
///////////////////////////////////////////////////////////////////////////////////////////////////
void CAttribBox::OnDeltaposSpnRoundness(NMHDR* pNMHDR, LRESULT* pResult) 
{
	NM_UPDOWN* pNMUpDown = (NM_UPDOWN*)pNMHDR;
	char	buf[MAX_PATH];
	m_ctlEdRound.GetLine( 0, (LPTSTR)buf, MAX_PATH );	// get edit control value

	// Convert the control value + the increment
	double val = atof( buf ) + (double)pNMUpDown->iDelta;
	val = val < 100 ? val : 100; // range checking
	val = val < 1   ? 1   : val;

	CGS_SetValDbl( EDIT_OBJ_ROUNDNESS, val );

	// Conver the double value to string for display
	DoubleToAlphaString( val, 1, (LPTSTR)buf );	// 1 means one digit after decimal point
	char* pSubStr = strstr( buf, ".0" );		// strip the floating part if 25.0
	if( pSubStr != NULL )						// ie: display 25 only
		*pSubStr = '\0';
	m_ctlEdRound.SetWindowText( (LPTSTR)buf );

	AfxGetMainWnd()->SetFocus();
	*pResult = 0;
}//end of CAttribBox::OnDeltaposSpnRoundness
///////////////////////////////////////////////////////////////////////////////////////////////////
/***
void CAttribBox::OnDeltaposSpnVPercent(NMHDR* pNMHDR, LRESULT* pResult) 
{
	NM_UPDOWN* pNMUpDown = (NM_UPDOWN*)pNMHDR;
	// TODO: Add your control notification handler code here
	AfxGetMainWnd()->SetFocus();
	*pResult = 0;
}//end of CAttribBox::OnDeltaposSpnVPercent
***/
///////////////////////////////////////////////////////////////////////////////////////////////////
VOID CAttribBox::DoValueUpdate()
{
	TRACE0("AttribBox.cpp : CAttribBox::DoValueUpdate()\n");
}//end of CAttribBox::DoValueUpdate()
///////////////////////////////////////////////////////////////////////////////////////////////////
void CAttribBox::OnPaint() 
{
	CPaintDC dc(this); // device context for painting
	CGS_CurAttrSample_OnPaint( (DWORD)GetDlgItem( IDC_FRM_B_PREVIEW )->m_hWnd );
}//end of CAttribBox::OnPaint() 
