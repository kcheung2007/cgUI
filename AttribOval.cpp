/* COPYRIGHT NOTICE:
********************************************************
*  Copyright (c) 2000 InnoVision Technology, Inc.      *
*  All rights reserved.                                *
*  PROPRIETARY AND CONFIDENTIAL                        *
*  DO NOT DISTRIBUTE                                   *
********************************************************
*/
// AttribOval.cpp : implementation file
//

#include "stdafx.h"
#include "cgui.h"
#include "AttribOval.h"
#include "Global.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CAttribOval dialog


CAttribOval::CAttribOval(CWnd* pParent /*=NULL*/) : CDialog(CAttribOval::IDD, pParent)
{
	//{{AFX_DATA_INIT(CAttribOval)
	m_edRoundness	= 0;
	m_edBevel		= 0;
	m_edSize		= 0;
	m_edPriority	= 0;
	m_edRotate		= 0;
	m_edWidth		= 0;
	m_edX = 0;
	m_edY = 0;
	m_edVPercent = 0;
	//}}AFX_DATA_INIT
}


void CAttribOval::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CAttribOval)
	DDX_Control(pDX, IDC_ED_V_PERCENT, m_ctlEdVPercent);
	DDX_Control(pDX, IDC_ED_O_Y, m_ctlEdY);
	DDX_Control(pDX, IDC_ED_O_X, m_ctlEdX);
	DDX_Control(pDX, IDC_ED_O_WIDTH, m_ctlEdWidth);
	DDX_Control(pDX, IDC_ED_O_SIZE, m_ctlEdSize);
	DDX_Control(pDX, IDC_ED_O_ROUNDNESS, m_ctlEdRoundness);
	DDX_Control(pDX, IDC_ED_O_ROTATION, m_ctlEdRotate);
	DDX_Control(pDX, IDC_ED_O_PRIORITY, m_ctlEdPriority);
	DDX_Control(pDX, IDC_ED_O_BEVEL, m_ctlEdBevel);
	DDX_Control(pDX, IDC_BT_SAVE_STYLE, m_btSaveStyle);
	DDX_Control(pDX, IDC_BT_ADVANCE, m_btAdvance);
	DDX_Control(pDX, IDC_STC_V_PERCENT, m_stcVPercent);
	DDX_Control(pDX, IDC_STC_O_Y, m_stcY);
	DDX_Control(pDX, IDC_STC_O_X, m_stcX);
	DDX_Control(pDX, IDC_STC_O_WIDTH, m_stcWidth);
	DDX_Control(pDX, IDC_STC_O_ROTATION, m_stcRotate);
	DDX_Control(pDX, IDC_STC_O_SIZE, m_stcSize);
	DDX_Control(pDX, IDC_STC_O_BEVEL, m_stcBevel);
	DDX_Control(pDX, IDC_STC_ROUNDNESS, m_stcRoundness);
	DDX_Control(pDX, IDC_BT_O_PLUS, m_btPlus);
	DDX_Control(pDX, IDC_BT_O_MINUS, m_btMinus);
	DDX_Control(pDX, IDC_BT_O_LOCK, m_btLock);
	DDX_Control(pDX, IDC_BT_O_F, m_btF);
	DDX_Control(pDX, IDC_BT_O_B, m_btB);
	DDX_Text(pDX, IDC_ED_O_ROUNDNESS, m_edRoundness);
	DDX_Text(pDX, IDC_ED_O_BEVEL, m_edBevel);
	DDX_Text(pDX, IDC_ED_O_SIZE, m_edSize);
	DDX_Text(pDX, IDC_ED_O_PRIORITY, m_edPriority);
	DDX_Text(pDX, IDC_ED_O_ROTATION, m_edRotate);
	DDX_Text(pDX, IDC_ED_O_WIDTH, m_edWidth);
	DDX_Text(pDX, IDC_ED_O_X, m_edX);
	DDX_Text(pDX, IDC_ED_O_Y, m_edY);
	DDX_Text(pDX, IDC_ED_V_PERCENT, m_edVPercent);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CAttribOval, CDialog)
	//{{AFX_MSG_MAP(CAttribOval)
	ON_BN_CLICKED(IDC_BT_O_B, OnBtOB)
	ON_BN_CLICKED(IDC_BT_O_F, OnBtOF)
	ON_BN_CLICKED(IDC_BT_O_LOCK, OnBtOLock)
	ON_BN_CLICKED(IDC_BT_O_MINUS, OnBtOMinus)
	ON_BN_CLICKED(IDC_BT_O_PLUS, OnBtOPlus)
	ON_NOTIFY(UDN_DELTAPOS, IDC_SPN_O_BEVEL, OnDeltaposSpnOBevel)
	ON_NOTIFY(UDN_DELTAPOS, IDC_SPN_O_PRIORITY, OnDeltaposSpnOPriority)
	ON_NOTIFY(UDN_DELTAPOS, IDC_SPN_O_ROTATE, OnDeltaposSpnORotate)
	ON_NOTIFY(UDN_DELTAPOS, IDC_SPN_O_X, OnDeltaposSpnOX)
	ON_NOTIFY(UDN_DELTAPOS, IDC_SPN_O_Y, OnDeltaposSpnOY)
	ON_WM_PAINT()
	ON_NOTIFY(UDN_DELTAPOS, IDC_SPN_ROUNDNESS, OnDeltaposSpnRoundness)
	ON_NOTIFY(UDN_DELTAPOS, IDC_SPN_O_SIZE, OnDeltaposSpnOSize)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

///////////////////////////////////////////////////////////////////////////////////////
// CAttribOval message handlers
///////////////////////////////////////////////////////////////////////////////////////
void CAttribOval::OnOK() 
{
	_TCHAR	buf[MAX_PATH];
	double  edValue;

	GetDlgItemText( IDC_ED_O_SIZE, buf, MAX_PATH );
	edValue = atof( buf );
	if( edValue != m_edSize )
	{
		m_edSize = edValue;
		TRACE(_T("\tm_edSize = %d\n"), m_edSize );
		CGS_SetValDbl( EDIT_OBJ_SIZE, (double)m_edSize );
	}

	GetDlgItemText( IDC_ED_O_ROUNDNESS, buf, MAX_PATH );
	edValue = atof( buf );
	if( edValue != m_edRoundness )
	{
		m_edRoundness = edValue;
		TRACE(_T("\t m_edRoundness = %d\n"), m_edRoundness );
		CGS_SetValDbl( EDIT_OBJ_ROUNDNESS, (double)m_edRoundness );
	}

	GetDlgItemText( IDC_ED_O_ROTATION, buf, MAX_PATH );
	edValue = atof( buf );
	if( edValue != m_edRotate )
	{
		m_edRotate = edValue;
		TRACE(_T("\tm_edRotate = %d\n"), m_edRotate );
		CGS_SetValDbl( EDIT_OBJ_ROTATION, (double)m_edRotate );
	}
	GetDlgItemText( IDC_ED_O_X, buf, MAX_PATH );
	edValue = atof( buf );
	if( edValue != m_edX )
	{
		m_edX = edValue;
		TRACE(_T("\tm_edX = %d\n"), m_edX );
		CGS_SetValDbl( EDIT_OBJ_X_POSITION_ABS, (double)m_edX );
	}
	GetDlgItemText( IDC_ED_O_Y, buf, MAX_PATH );
	edValue = atof( buf );
	if( edValue != m_edY )
	{
		m_edY = edValue;
		TRACE(_T("\t m_edY = %d\n"), m_edY );
		CGS_SetValDbl( EDIT_OBJ_Y_POSITION_ABS, (double)m_edY );
	}
	GetDlgItemText( IDC_ED_O_BEVEL, buf, MAX_PATH );
	edValue = atof( buf );
	if( edValue != m_edBevel )
	{
		m_edBevel = edValue;
		TRACE(_T("\tm_edBevel = %d\n"), m_edBevel );
		CGS_SetValDbl( EDIT_OBJ_BEVEL_SIZE, (double)m_edBevel );
	}
	GetDlgItemText( IDC_ED_O_PRIORITY, buf, MAX_PATH );
	edValue = atof( buf );
	if( edValue != m_edPriority )
	{
		m_edPriority = edValue;
		TRACE(_T("\tm_edPriority = %d\n"), m_edPriority );
		CGS_SetValDbl( EDIT_OBJ_PRIORITY, (double)m_edPriority );
	}

	AfxGetMainWnd()->SetFocus();	

}//end of CDialog::OnOK();
///////////////////////////////////////////////////////////////////////////////////////
void CAttribOval::OnCancel() 
{
	// capture cancel message
}//end of CDialog::OnCancel();
///////////////////////////////////////////////////////////////////////////////////////
BOOL CAttribOval::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	//++++++++++++++++++ Initial radio button and Icon
	m_btB.SetIcon( (HICON)::LoadImage( AfxGetApp()->m_hInstance, MAKEINTRESOURCE(IDI_BACK_GRD), IMAGE_ICON, 16, 16, 0) );
	m_btF.SetIcon( (HICON)::LoadImage( AfxGetApp()->m_hInstance, MAKEINTRESOURCE(IDI_FORE_GRD), IMAGE_ICON, 16, 16, 0) );
	m_btLock.SetIcon( (HICON)::LoadImage( AfxGetApp()->m_hInstance,	MAKEINTRESOURCE(IDI_LOCK), IMAGE_ICON, 16, 16, 0) );
	m_btMinus.SetIcon( (HICON)::LoadImage( AfxGetApp()->m_hInstance,MAKEINTRESOURCE(IDI_BACK_MINUS), IMAGE_ICON, 16, 16, 0) );
	m_btPlus.SetIcon( (HICON)::LoadImage( AfxGetApp()->m_hInstance,	MAKEINTRESOURCE(IDI_FORE_PLUS), IMAGE_ICON, 16, 16, 0) );
	m_btAdvance.SetIcon( (HICON)::LoadImage( AfxGetApp()->m_hInstance, MAKEINTRESOURCE(IDI_ADVANCE),      IMAGE_ICON, 16, 16, 0) );		
	m_btSaveStyle.SetIcon( (HICON)::LoadImage( AfxGetApp()->m_hInstance, MAKEINTRESOURCE(IDI_SAVE_STYLE),   IMAGE_ICON, 16, 16, 0) );

	// ++++++++++++++++++++++++++++++++++++++++++++ Initial spin control
	CSpinButtonCtrl* pSpin = (CSpinButtonCtrl*)GetDlgItem( IDC_SPN_O_SIZE );
	pSpin->SetRange( 1, 3000 );
	//save for ref.	pSpin->SetPos((int) (m_dSpin * 10.0));
//	pSpin = (CSpinButtonCtrl*)GetDlgItem( IDC_SPN_O_WIDTH );
//	pSpin->SetRange( 1, 3000 );
	pSpin = (CSpinButtonCtrl*)GetDlgItem( IDC_SPN_ROUNDNESS );
	pSpin->SetRange( 0, 100 );
	pSpin = (CSpinButtonCtrl*)GetDlgItem( IDC_SPN_O_PRIORITY );
	pSpin->SetRange( 0, 255 );
	pSpin = (CSpinButtonCtrl*)GetDlgItem( IDC_SPN_O_ROTATE );
	pSpin->SetRange( 0, 359 );
	pSpin = (CSpinButtonCtrl*)GetDlgItem( IDC_SPN_O_BEVEL );
	pSpin->SetRange( 0, 64 );
//	pSpin = (CSpinButtonCtrl*)GetDlgItem( IDC_SPN_V_PERCENT );
//	pSpin->SetRange( 0, 100 );
	pSpin = (CSpinButtonCtrl*)GetDlgItem( IDC_SPN_O_X );
	pSpin->SetRange( -3000, 3000 );
	pSpin = (CSpinButtonCtrl*)GetDlgItem( IDC_SPN_O_Y );
	pSpin->SetRange( -3000, 3000 );

	//+++++++++++++++++++++++++++++++++++++++++++++ Initial Edit control
	_TCHAR buf[MAX_PATH];
	CEdit* pEdCtrl = (CEdit*)GetDlgItem( IDC_ED_O_SIZE );
	pEdCtrl->SetLimitText( 7 ); // 7 characters of 3000.00
	DoubleToAlphaString( CGS_GetValDbl(EDIT_OBJ_SIZE), 1, buf );
	char* pSubStr = strstr( buf, ".0" );		// strip the floating part if 25.0
	if( pSubStr != NULL )						// ie: display 25 only
		*pSubStr = '\0';
	SetDlgItemText(IDC_ED_O_SIZE, buf );

	pEdCtrl = (CEdit*)GetDlgItem( IDC_ED_O_ROUNDNESS );
	pEdCtrl->SetLimitText( 3 ); // 3 characters of 100
	DoubleToAlphaString( CGS_GetValDbl(EDIT_OBJ_ROUNDNESS), 1, buf );
	pSubStr = strstr( buf, ".0" );		// strip the floating part if 25.0
	if( pSubStr != NULL )				// ie: display 25 only
		*pSubStr = '\0';
	SetDlgItemText(IDC_ED_O_ROUNDNESS, buf );

	pEdCtrl = (CEdit*)GetDlgItem( IDC_ED_O_PRIORITY );
	pEdCtrl->SetLimitText( 3 ); // 3 characters of 255 
	DoubleToAlphaString( CGS_GetValDbl(EDIT_OBJ_PRIORITY), 1, buf );
	pSubStr = strstr( buf, ".0" );		// strip the floating part if 25.0
	if( pSubStr != NULL )				// ie: display 25 only
		*pSubStr = '\0';
	SetDlgItemText(IDC_ED_O_PRIORITY, buf );

	pEdCtrl = (CEdit*)GetDlgItem( IDC_ED_O_BEVEL );
	pEdCtrl->SetLimitText( 2 ); // 2 characters of 64
	DoubleToAlphaString( CGS_GetValDbl(EDIT_OBJ_BEVEL_SIZE), 1, buf );
	pSubStr = strstr( buf, ".0" );		// strip the floating part if 25.0
	if( pSubStr != NULL )				// ie: display 25 only
		*pSubStr = '\0';
	SetDlgItemText(IDC_ED_O_BEVEL, buf );

	pEdCtrl = (CEdit*)GetDlgItem( IDC_ED_O_ROTATION );
	pEdCtrl->SetLimitText( 6 ); // 3 characters of 359.99
	DoubleToAlphaString( CGS_GetValDbl(EDIT_OBJ_ROTATION), 1, buf );
	pSubStr = strstr( buf, ".0" );		// strip the floating part if 25.0
	if( pSubStr != NULL )				// ie: display 25 only
		*pSubStr = '\0';
	SetDlgItemText(IDC_ED_O_ROTATION, buf );

	pEdCtrl = (CEdit*)GetDlgItem( IDC_ED_O_X );
	pEdCtrl->SetLimitText( 8 ); // 8 characters of -3000.99
	DoubleToAlphaString( CGS_GetValDbl(EDIT_OBJ_X_POSITION_ABS), 1, buf );
	pSubStr = strstr( buf, ".0" );		// strip the floating part if 25.0
	if( pSubStr != NULL )				// ie: display 25 only
		*pSubStr = '\0';
	SetDlgItemText(IDC_ED_O_X, buf );

	pEdCtrl = (CEdit*)GetDlgItem( IDC_ED_O_Y );
	pEdCtrl->SetLimitText( 8 ); // 8 characters of -3000.99
	DoubleToAlphaString( CGS_GetValDbl(EDIT_OBJ_Y_POSITION_ABS), 1, buf );
	pSubStr = strstr( buf, ".0" );		// strip the floating part if 25.0
	if( pSubStr != NULL )				// ie: display 25 only
		*pSubStr = '\0';
	SetDlgItemText(IDC_ED_O_Y, buf );

	//+++++++++++++++++++++++++++++++++++++++++++++ Initial Static Icon
	m_stcWidth.ModifyStyle( 0, SS_ICON );
	m_stcWidth.SetIcon( (HICON)::LoadImage( AfxGetApp()->m_hInstance,MAKEINTRESOURCE( IDI_FONT_WIDTH ),IMAGE_ICON, 16, 16, 0 ) );
	m_stcSize.ModifyStyle( 0, SS_ICON );
	m_stcSize.SetIcon( (HICON)::LoadImage( AfxGetApp()->m_hInstance,MAKEINTRESOURCE( IDI_FONT_HEIGHT ),	IMAGE_ICON, 16, 16, 0 ) );
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
}//end of CAttribOval::OnInitDialog
//////////////////////////////////////////////////////////////////////////////////////////
VOID CAttribOval::DeleteAttribOval()
{
	DestroyWindow();
}//end of CAttribOval::DeleteAttribOval()
//////////////////////////////////////////////////////////////////////////////////////////
BOOL CAttribOval::PreTranslateMessage(MSG* pMsg)
{
	// Let the ToolTip process this message.
	m_tooltip.RelayEvent(pMsg);
	return CDialog::PreTranslateMessage(pMsg);	// CG: This was added by the ToolTips component.
}//end of CAttribOval::PreTranslateMessage
//////////////////////////////////////////////////////////////////////////////////////////
VOID CAttribOval::InitDlgItemTextNTooltip()
{
	IN_TEXT_DATA* txtData = NULL;
	TCHAR	sep[] = _T("\"");
	TCHAR*	ptID;
	TCHAR*	ptTT;
	TCHAR*	ptEnd;

	DWORD numTxt = LoadTextFromCtl( "\\Util\\DlgOval.ctl", "[Tooltip]", &txtData );
	if( numTxt == 0 )
		return;

	for( DWORD i = 0; i < numTxt; i++ )
	{
		ptID   = _tcstok( txtData[i].szTT, sep );
		ptTT   = _tcstok( NULL, sep );
		ptEnd  = _tcstok( NULL, sep );
		if( ptEnd != 0 )
			*ptEnd = '\0';
			
		if( NULL != _tcsstr( txtData[i].szTT, _T("IDC_ED_O_PRIORITY") ) )
			txtData[i].idTT = IDC_ED_O_PRIORITY;
		else
			if( NULL != _tcsstr( txtData[i].szTT, _T("IDC_ED_O_BEVEL") ) )
				txtData[i].idTT = IDC_ED_O_BEVEL;
		else
			if( NULL != _tcsstr( txtData[i].szTT, _T("IDC_ED_O_ROUNDNESS") ) )
				txtData[i].idTT = IDC_ED_O_ROUNDNESS;
		else
			if( NULL != _tcsstr( txtData[i].szTT, _T("IDC_ED_O_WIDTH") ) )
				txtData[i].idTT = IDC_ED_O_WIDTH;
		else
			if( NULL != _tcsstr( txtData[i].szTT, _T("IDC_ED_O_ROTATION") ) )
				txtData[i].idTT = IDC_ED_O_ROTATION;
		else
			if( NULL != _tcsstr( txtData[i].szTT, _T("IDC_ED_V_PERCENT") ) )
				txtData[i].idTT = IDC_ED_V_PERCENT;
		else
			if( NULL != _tcsstr( txtData[i].szTT, _T("IDC_ED_O_SIZE") ) )
				txtData[i].idTT = IDC_ED_O_SIZE;
		else
			if( NULL != _tcsstr( txtData[i].szTT, _T("IDC_ED_O_X") ) )
				txtData[i].idTT = IDC_ED_O_X;
		else
			if( NULL != _tcsstr( txtData[i].szTT, _T("IDC_ED_O_Y") ) )
				txtData[i].idTT = IDC_ED_O_Y;
		else
			if( NULL != _tcsstr( txtData[i].szTT, _T("IDC_BT_O_B") ) )
				txtData[i].idTT = IDC_BT_O_B;
		else
			if( NULL != _tcsstr( txtData[i].szTT, _T("IDC_BT_O_MINUS") ) )
				txtData[i].idTT = IDC_BT_O_MINUS;
		else
			if( NULL != _tcsstr( txtData[i].szTT, _T("IDC_BT_O_PLUS") ) )
				txtData[i].idTT = IDC_BT_O_PLUS;
		else
			if( NULL != _tcsstr( txtData[i].szTT, _T("IDC_BT_O_F") ) )
				txtData[i].idTT = IDC_BT_O_F;
		else
			if( NULL != _tcsstr( txtData[i].szTT, _T("IDC_BT_O_LOCK") ) )
				txtData[i].idTT = IDC_BT_O_LOCK;
		else
			if( NULL != _tcsstr( txtData[i].szTT, _T("IDC_FRM_O_PREVIEW") ) )
				txtData[i].idTT = IDC_FRM_O_PREVIEW;
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
}//end of CAttribOval::InitDlgItemTextNTooltip()
//////////////////////////////////////////////////////////////////////////////////////////
void CAttribOval::OnBtOB() 
{
	// TODO: Add your control notification handler code here
	AfxGetMainWnd()->SetFocus();
}//end of CAttribOval::OnBtOB
//////////////////////////////////////////////////////////////////////////////////////////
void CAttribOval::OnBtOF() 
{
	// TODO: Add your control notification handler code here
	AfxGetMainWnd()->SetFocus();
}//end of CAttribOval::OnBtOF
//////////////////////////////////////////////////////////////////////////////////////////
void CAttribOval::OnBtOLock() 
{
	// TODO: Add your control notification handler code here
	AfxGetMainWnd()->SetFocus();
}//end of CAttribOval::OnBtOLock
//////////////////////////////////////////////////////////////////////////////////////////
void CAttribOval::OnBtOMinus() 
{
	// TODO: Add your control notification handler code here
	AfxGetMainWnd()->SetFocus();
}//end of CAttribOval::OnBtOMinus
//////////////////////////////////////////////////////////////////////////////////////////
void CAttribOval::OnBtOPlus() 
{
	// TODO: Add your control notification handler code here
	AfxGetMainWnd()->SetFocus();
}//end of CAttribOval::OnBtOPlus
//////////////////////////////////////////////////////////////////////////////////////////
/****
void CAttribOval::OnDeltaposSpnHPercent(NMHDR* pNMHDR, LRESULT* pResult) 
{
	NM_UPDOWN* pNMUpDown = (NM_UPDOWN*)pNMHDR;

	AfxGetMainWnd()->SetFocus();
	*pResult = 0;
}//end of CAttribOval::OnDeltaposSpnHPercent
****/
//////////////////////////////////////////////////////////////////////////////////////////
void CAttribOval::OnDeltaposSpnOBevel(NMHDR* pNMHDR, LRESULT* pResult) 
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
}//end of CAttribOval::OnDeltaposSpnOBevel
//////////////////////////////////////////////////////////////////////////////////////////
void CAttribOval::OnDeltaposSpnOSize(NMHDR* pNMHDR, LRESULT* pResult) 
{
	NM_UPDOWN* pNMUpDown = (NM_UPDOWN*)pNMHDR;
	char	buf[MAX_PATH];
	m_ctlEdSize.GetLine( 0, (LPTSTR)buf, MAX_PATH );	// get edit control value

	// Convert the control value + the increment
	double val = atof( buf ) + (double)pNMUpDown->iDelta;
	val = val < 3000 ? val : 3000; // range checking
	val = val < 1    ? 1   : val;

	CGS_SetValDbl( EDIT_OBJ_SIZE, val );

	// Conver the double value to string for display
	DoubleToAlphaString( val, 1, (LPTSTR)buf );	// 1 means one digit after decimal point
	char* pSubStr = strstr( buf, ".0" );		// strip the floating part if 25.0
	if( pSubStr != NULL )						// ie: display 25 only
		*pSubStr = '\0';
	m_ctlEdSize.SetWindowText( (LPTSTR)buf );

	AfxGetMainWnd()->SetFocus();
	*pResult = 0;}//end of CAttribOval::OnDeltaposSpnOSize
//////////////////////////////////////////////////////////////////////////////////////////
void CAttribOval::OnDeltaposSpnOPriority(NMHDR* pNMHDR, LRESULT* pResult) 
{
	NM_UPDOWN* pNMUpDown = (NM_UPDOWN*)pNMHDR;
	int val = pNMUpDown->iPos+pNMUpDown->iDelta;
	CGS_SetValDbl( EDIT_OBJ_PRIORITY, max(0, val) );

	AfxGetMainWnd()->SetFocus();
	*pResult = 0;
}//end of CAttribOval::OnDeltaposSpnOPriority
//////////////////////////////////////////////////////////////////////////////////////////
void CAttribOval::OnDeltaposSpnORotate(NMHDR* pNMHDR, LRESULT* pResult) 
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
}//end of CAttribOval::OnDeltaposSpnORotate
//////////////////////////////////////////////////////////////////////////////////////////
/*****************
void CAttribOval::OnDeltaposSpnOWidth(NMHDR* pNMHDR, LRESULT* pResult) 
{
	NM_UPDOWN* pNMUpDown = (NM_UPDOWN*)pNMHDR;
	char	buf[MAX_PATH];
	m_ctlEdWidth.GetLine( 0, (LPTSTR)buf, MAX_PATH );	// get edit control value

	// Convert the control value + the increment
	double val = atof( buf ) + (double)pNMUpDown->iDelta;
	val = val < 999 ? val : 999; // range checking
	val = val < 5   ? 5   : val;

	CGS_SetValDbl( EDIT_OBJ_WIDTH_ABS, val );

	// Conver the double value to string for display
	DoubleToAlphaString( val, 1, (LPTSTR)buf );	// 1 means one digit after decimal point
	char* pSubStr = strstr( buf, ".0" );		// strip the floating part if 25.0
	if( pSubStr != NULL )						// ie: display 25 only
		*pSubStr = '\0';
	m_ctlEdWidth.SetWindowText( (LPTSTR)buf );

	AfxGetMainWnd()->SetFocus();
	*pResult = 0;
}//end of CAttribOval::OnDeltaposSpnOWidth
**************/
//////////////////////////////////////////////////////////////////////////////////////////
void CAttribOval::OnDeltaposSpnOX(NMHDR* pNMHDR, LRESULT* pResult) 
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
}//end of CAttribOval::OnDeltaposSpnOX
//////////////////////////////////////////////////////////////////////////////////////////
void CAttribOval::OnDeltaposSpnOY(NMHDR* pNMHDR, LRESULT* pResult) 
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
}//end of CAttribOval::OnDeltaposSpnOY
//////////////////////////////////////////////////////////////////////////////////////////
void CAttribOval::OnDeltaposSpnRoundness(NMHDR* pNMHDR, LRESULT* pResult) 
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
}//end of CAttribOval::OnDeltaposSpnRoundness
//////////////////////////////////////////////////////////////////////////////////////////
VOID CAttribOval::DoValueUpdate()
{
	TRACE0("AttribOval.cpp : CAttribOval::DoValueUpdate()\n");
}//end of CAttribOval::DoValueUpdate()
//////////////////////////////////////////////////////////////////////////////////////////
void CAttribOval::OnPaint() 
{
	CPaintDC dc(this); // device context for painting
	
	CGS_CurAttrSample_OnPaint( (DWORD)GetDlgItem( IDC_FRM_O_PREVIEW )->m_hWnd );	
	// Do not call CDialog::OnPaint() for painting messages
}//end of CAttribOval::OnPaint() 

