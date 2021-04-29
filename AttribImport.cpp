/* COPYRIGHT NOTICE:
********************************************************
*  Copyright (c) 2000 InnoVision Technology, Inc.      *
*  All rights reserved.                                *
*  PROPRIETARY AND CONFIDENTIAL                        *
*  DO NOT DISTRIBUTE                                   *
********************************************************
*/
// AttribImport.cpp : implementation file
//

#include "stdafx.h"
#include "cgui.h"
#include "Global.h"
#include "AttribImport.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CAttribImport dialog

CAttribImport::CAttribImport(CWnd* pParent /*=NULL*/) : CDialog(CAttribImport::IDD, pParent)
{
	//{{AFX_DATA_INIT(CAttribImport)
	m_edBevel		  = 0;
	m_edHeight		  = 0;
	m_edPriority	  = 0;
	m_edRotate		  = 0;
	m_edWidth		  = 0;
	m_edX			  = 0;
	m_edY			  = 0;
	m_edWidthPercent  = 0;
	m_edHeightPercent = 0;
	//}}AFX_DATA_INIT
}

void CAttribImport::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CAttribImport)
	DDX_Control(pDX, IDC_ED_WIDTH_PERCENT, m_ctlEdWidthPercent);
	DDX_Control(pDX, IDC_ED_HEIGHT_PERCENT, m_ctlEdHeightPercent);
	DDX_Control(pDX, IDC_ED_G_Y, m_ctlEdY);
	DDX_Control(pDX, IDC_ED_G_X, m_ctlEdX);
	DDX_Control(pDX, IDC_ED_G_WIDTH, m_ctlEdWidth);
	DDX_Control(pDX, IDC_ED_G_ROTATION, m_ctlEdRotate);
	DDX_Control(pDX, IDC_ED_G_PRIORITY, m_ctlEdPriority);
	DDX_Control(pDX, IDC_ED_G_HEIGHT, m_ctlEdHeight);
	DDX_Control(pDX, IDC_ED_G_BEVEL, m_ctlEdBevel);
	DDX_Control(pDX, IDC_BT_ADVANCE, m_btAdvance);
	DDX_Control(pDX, IDC_BT_SAVE_STYLE, m_btSaveStyle);
	DDX_Control(pDX, IDC_STC_V_PERCENT, m_stcVPercent);
	DDX_Control(pDX, IDC_STC_H_PERCENT, m_stcHPercent);
	DDX_Control(pDX, IDC_STC_G_Y, m_stcY);
	DDX_Control(pDX, IDC_STC_G_X, m_stcX);
	DDX_Control(pDX, IDC_STC_G_WIDTH, m_stcWidth);
	DDX_Control(pDX, IDC_STC_G_ROTATION, m_stcRotate);
	DDX_Control(pDX, IDC_STC_G_HEIGHT, m_stcHeight);
	DDX_Control(pDX, IDC_STC_G_BEVEL, m_stcBevel);
	DDX_Control(pDX, IDC_BT_G_PLUS, m_btPlus);
	DDX_Control(pDX, IDC_BT_G_MINUS, m_btMinus);
	DDX_Control(pDX, IDC_BT_G_LOCK, m_btLock);
	DDX_Control(pDX, IDC_BT_G_F, m_btF);
	DDX_Control(pDX, IDC_BT_G_B, m_btB);
	DDX_Text(pDX, IDC_ED_G_BEVEL, m_edBevel);
	DDX_Text(pDX, IDC_ED_G_HEIGHT, m_edHeight);
	DDX_Text(pDX, IDC_ED_G_PRIORITY, m_edPriority);
	DDX_Text(pDX, IDC_ED_G_ROTATION, m_edRotate);
	DDX_Text(pDX, IDC_ED_G_WIDTH, m_edWidth);
	DDX_Text(pDX, IDC_ED_G_X, m_edX);
	DDX_Text(pDX, IDC_ED_G_Y, m_edY);
	DDX_Text(pDX, IDC_ED_WIDTH_PERCENT, m_edWidthPercent);
	DDX_Text(pDX, IDC_ED_HEIGHT_PERCENT, m_edHeightPercent);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CAttribImport, CDialog)
	//{{AFX_MSG_MAP(CAttribImport)
	ON_BN_CLICKED(IDC_BT_G_B, OnBtGB)
	ON_BN_CLICKED(IDC_BT_G_F, OnBtGF)
	ON_BN_CLICKED(IDC_BT_G_LOCK, OnBtGLock)
	ON_BN_CLICKED(IDC_BT_G_MINUS, OnBtGMinus)
	ON_BN_CLICKED(IDC_BT_G_PLUS, OnBtGPlus)
	ON_NOTIFY(UDN_DELTAPOS, IDC_SPN_G_BEVEL, OnDeltaposSpnGBevel)
	ON_NOTIFY(UDN_DELTAPOS, IDC_SPN_G_HEIGHT, OnDeltaposSpnGHeight)
	ON_NOTIFY(UDN_DELTAPOS, IDC_SPN_G_PRIORITY, OnDeltaposSpnGPriority)
	ON_NOTIFY(UDN_DELTAPOS, IDC_SPN_G_ROTATE, OnDeltaposSpnGRotate)
	ON_NOTIFY(UDN_DELTAPOS, IDC_SPN_G_WIDTH, OnDeltaposSpnGWidth)
	ON_NOTIFY(UDN_DELTAPOS, IDC_SPN_G_X, OnDeltaposSpnGX)
	ON_NOTIFY(UDN_DELTAPOS, IDC_SPN_G_Y, OnDeltaposSpnGY)
	ON_NOTIFY(UDN_DELTAPOS, IDC_SPN_WIDTH_PERCENT, OnDeltaposSpnWidthPercent)
	ON_NOTIFY(UDN_DELTAPOS, IDC_SPN_HEIGHT_PERCENT, OnDeltaposSpnHeightPercent)
	ON_BN_CLICKED(IDC_BT_SAVE_STYLE, OnBtSaveStyle)
	ON_BN_CLICKED(IDC_BT_ADVANCE, OnBtAdvance)
	ON_WM_PAINT()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CAttribImport message handlers

BOOL CAttribImport::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	//++++++++++++++++++ Initial radio button and Icon
	m_btB.SetIcon( (HICON)::LoadImage( AfxGetApp()->m_hInstance,MAKEINTRESOURCE(IDI_BACK_GRD), IMAGE_ICON, 16, 16, 0) );
	m_btF.SetIcon( (HICON)::LoadImage( AfxGetApp()->m_hInstance,MAKEINTRESOURCE(IDI_FORE_GRD), IMAGE_ICON, 16, 16, 0) );
	m_btAdvance.SetIcon( (HICON)::LoadImage( AfxGetApp()->m_hInstance, MAKEINTRESOURCE(IDI_ADVANCE), IMAGE_ICON, 16, 16, 0) );		
	m_btSaveStyle.SetIcon( (HICON)::LoadImage( AfxGetApp()->m_hInstance, MAKEINTRESOURCE(IDI_SAVE_STYLE), IMAGE_ICON, 16, 16, 0) );
	m_btLock.SetIcon( (HICON)::LoadImage( AfxGetApp()->m_hInstance,MAKEINTRESOURCE(IDI_LOCK), IMAGE_ICON, 16, 16, 0) );
	m_btMinus.SetIcon( (HICON)::LoadImage( AfxGetApp()->m_hInstance,MAKEINTRESOURCE(IDI_BACK_MINUS), IMAGE_ICON, 16, 16, 0) );
	m_btPlus.SetIcon( (HICON)::LoadImage( AfxGetApp()->m_hInstance,	MAKEINTRESOURCE(IDI_FORE_PLUS), IMAGE_ICON, 16, 16, 0) );

	// ++++++++++++++++++++++++++++++++++++++++++++ Initial spin control
	CSpinButtonCtrl* pSpin = (CSpinButtonCtrl*)GetDlgItem( IDC_SPN_G_HEIGHT );
	pSpin->SetRange( 1, 3000 );
	//save for ref.	pSpin->SetPos((int) (m_dSpin * 10.0));
	pSpin = (CSpinButtonCtrl*)GetDlgItem( IDC_SPN_G_WIDTH );
	pSpin->SetRange( 1, 3000 );
	pSpin = (CSpinButtonCtrl*)GetDlgItem( IDC_SPN_WIDTH_PERCENT );
	pSpin->SetRange( 1, 500 );
	pSpin = (CSpinButtonCtrl*)GetDlgItem( IDC_SPN_G_PRIORITY );
	pSpin->SetRange( 0, 255 );
	pSpin = (CSpinButtonCtrl*)GetDlgItem( IDC_SPN_G_ROTATE );
	pSpin->SetRange( 0, 359 );
	pSpin = (CSpinButtonCtrl*)GetDlgItem( IDC_SPN_G_BEVEL );
	pSpin->SetRange( 0, 64 );
	pSpin = (CSpinButtonCtrl*)GetDlgItem( IDC_SPN_HEIGHT_PERCENT );
	pSpin->SetRange( 1, 500 );
	pSpin = (CSpinButtonCtrl*)GetDlgItem( IDC_SPN_G_X );
	pSpin->SetRange( -3000, 3000 );
	pSpin = (CSpinButtonCtrl*)GetDlgItem( IDC_SPN_G_Y );
	pSpin->SetRange( -3000, 3000 );

	//+++++++++++++++++++++++++++++++++++++++++++++ Initial Edit control
	_TCHAR buf[MAX_PATH];

	CEdit* pEdCtrl = (CEdit*)GetDlgItem( IDC_ED_G_WIDTH );
	pEdCtrl->SetLimitText( 7 ); // 7 characters of 3000.00
	DoubleToAlphaString( CGS_GetValDbl(EDIT_OBJ_WIDTH_ABS), 1, buf );
	char* pSubStr = strstr( buf, ".0" );// strip the floating part if 25.0
	if( pSubStr != NULL )				// ie: display 25 only
		*pSubStr = '\0';
	SetDlgItemText(IDC_ED_G_WIDTH, buf );

	pEdCtrl = (CEdit*)GetDlgItem( IDC_ED_G_HEIGHT );
	pEdCtrl->SetLimitText( 7 ); // 6 characters of 3000.00
	DoubleToAlphaString( CGS_GetValDbl(EDIT_OBJ_HEIGHT_ABS), 1, buf );
	pSubStr = strstr( buf, ".0" );		// strip the floating part if 25.0
	if( pSubStr != NULL )				// ie: display 25 only
		*pSubStr = '\0';
	SetDlgItemText(IDC_ED_G_HEIGHT, buf );
	
	pEdCtrl = (CEdit*)GetDlgItem( IDC_ED_WIDTH_PERCENT );
	pEdCtrl->SetLimitText( 6 ); // 6 characters of 500.99
	DoubleToAlphaString( CGS_GetValDbl(EDIT_OBJ_HEIGHT_PERCENT), 1, buf );
	pSubStr = strstr( buf, ".0" );		// strip the floating part if 25.0
	if( pSubStr != NULL )				// ie: display 25 only
		*pSubStr = '\0';
	SetDlgItemText(IDC_ED_WIDTH_PERCENT, buf );
	
	pEdCtrl = (CEdit*)GetDlgItem( IDC_ED_G_PRIORITY );
	pEdCtrl->SetLimitText( 3 ); // 3 characters of 255 
	DoubleToAlphaString( CGS_GetValDbl(EDIT_OBJ_PRIORITY), 1, buf );
	pSubStr = strstr( buf, ".0" );		// strip the floating part if 25.0
	if( pSubStr != NULL )				// ie: display 25 only
		*pSubStr = '\0';
	SetDlgItemText(IDC_ED_G_PRIORITY, buf );	
	
	pEdCtrl = (CEdit*)GetDlgItem( IDC_ED_HEIGHT_PERCENT );
	pEdCtrl->SetLimitText( 6 ); // 6 characters of 500.99
	DoubleToAlphaString( CGS_GetValDbl(EDIT_OBJ_WIDTH_PERCENT), 1, buf );
	pSubStr = strstr( buf, ".0" );		// strip the floating part if 25.0
	if( pSubStr != NULL )				// ie: display 25 only
		*pSubStr = '\0';
	SetDlgItemText(IDC_ED_HEIGHT_PERCENT, buf );
	
	pEdCtrl = (CEdit*)GetDlgItem( IDC_ED_G_BEVEL );
	pEdCtrl->SetLimitText( 2 ); // 2 characters of 64
	DoubleToAlphaString( CGS_GetValDbl(EDIT_OBJ_BEVEL_SIZE), 1, buf );
	pSubStr = strstr( buf, ".0" );		// strip the floating part if 25.0
	if( pSubStr != NULL )				// ie: display 25 only
		*pSubStr = '\0';
	SetDlgItemText(IDC_ED_G_BEVEL, buf );
	
	pEdCtrl = (CEdit*)GetDlgItem( IDC_ED_G_ROTATION );
	pEdCtrl->SetLimitText( 6 ); // 6 characters of 359.00
	DoubleToAlphaString( CGS_GetValDbl(EDIT_OBJ_ROTATION), 1, buf );
	pSubStr = strstr( buf, ".0" );		// strip the floating part if 25.0
	if( pSubStr != NULL )				// ie: display 25 only
		*pSubStr = '\0';
	SetDlgItemText(IDC_ED_G_ROTATION, buf );
	
	pEdCtrl = (CEdit*)GetDlgItem( IDC_ED_G_X );
	pEdCtrl->SetLimitText( 8 ); // 8 characters of -3000.00
	DoubleToAlphaString( CGS_GetValDbl(EDIT_OBJ_X_POSITION_ABS), 1, buf );
	pSubStr = strstr( buf, ".0" );		// strip the floating part if 25.0
	if( pSubStr != NULL )				// ie: display 25 only
		*pSubStr = '\0';
	SetDlgItemText(IDC_ED_G_X, buf );
	
	pEdCtrl = (CEdit*)GetDlgItem( IDC_ED_G_Y );
	pEdCtrl->SetLimitText( 8 ); // 8 characters of -3000.00
	DoubleToAlphaString( CGS_GetValDbl(EDIT_OBJ_Y_POSITION_ABS), 1, buf );
	pSubStr = strstr( buf, ".0" );		// strip the floating part if 25.0
	if( pSubStr != NULL )				// ie: display 25 only
		*pSubStr = '\0';
	SetDlgItemText(IDC_ED_G_Y, buf );

	//+++++++++++++++++++++++++++++++++++++++++++++ Initial Static Icon
	m_stcWidth.ModifyStyle( 0, SS_ICON );
	m_stcWidth.SetIcon( (HICON)::LoadImage( AfxGetApp()->m_hInstance,MAKEINTRESOURCE( IDI_FONT_WIDTH ),IMAGE_ICON, 16, 16, 0 ) );
	m_stcHeight.ModifyStyle( 0, SS_ICON );
	m_stcHeight.SetIcon( (HICON)::LoadImage( AfxGetApp()->m_hInstance,MAKEINTRESOURCE( IDI_FONT_HEIGHT ),	IMAGE_ICON, 16, 16, 0 ) );
	m_stcBevel.ModifyStyle( 0, SS_ICON );
	m_stcBevel.SetIcon( (HICON)::LoadImage( AfxGetApp()->m_hInstance,MAKEINTRESOURCE( IDI_BEVEL ),IMAGE_ICON, 16, 16, 0 ) );
	m_stcVPercent.ModifyStyle( 0, SS_ICON );
	m_stcVPercent.SetIcon( (HICON)::LoadImage( AfxGetApp()->m_hInstance,MAKEINTRESOURCE( IDI_V_PERCENT ),IMAGE_ICON, 16, 16, 0 ) );
	m_stcRotate.ModifyStyle( 0, SS_ICON );
	m_stcRotate.SetIcon( (HICON)::LoadImage( AfxGetApp()->m_hInstance,MAKEINTRESOURCE( IDI_ROTATE ),IMAGE_ICON, 16, 16, 0 ) );
	m_stcHPercent.ModifyStyle( 0, SS_ICON );
	m_stcHPercent.SetIcon( (HICON)::LoadImage( AfxGetApp()->m_hInstance,MAKEINTRESOURCE( IDI_H_PERCENT ),IMAGE_ICON, 16, 16, 0 ) );
	
	//+++++++++++++++++++++++++++++++++++++++++++++++++++++ Create the ToolTip control.
	m_tooltip.Create(this);
	m_tooltip.Activate(TRUE);

	InitDlgItemTextNTooltip();

	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}//end of CAttribImport::OnInitDialog
//////////////////////////////////////////////////////////////////////////////////////////////
VOID CAttribImport::DeleteAttribImport()
{
	DestroyWindow();
}//end of CAttribImport::DeleteAttribImport()
//////////////////////////////////////////////////////////////////////////////////////////////
void CAttribImport::OnCancel() 
{
	// capture cancel message
}//end of CAttribImport::OnCancel
//////////////////////////////////////////////////////////////////////////////////////////////
void CAttribImport::OnOK() 
{
	_TCHAR	buf[MAX_PATH];
	double  edValue;

	GetDlgItemText( IDC_ED_G_HEIGHT, buf, MAX_PATH );
	edValue = atof( buf );
	if( edValue != m_edHeight )
	{
		m_edHeight = edValue;
		TRACE(_T("\t m_edHeight = %d\n"), m_edHeight );
		CGS_SetValDbl( EDIT_OBJ_HEIGHT_ABS, (double)m_edHeight );
	}
	GetDlgItemText( IDC_ED_WIDTH_PERCENT, buf, MAX_PATH );
	edValue = atof( buf );
	if( edValue != m_edWidthPercent )
	{
		m_edWidthPercent = edValue;
		TRACE(_T("\t  m_edWidthPercent = %d\n"), m_edWidthPercent );
		CGS_SetValDbl( EDIT_OBJ_WIDTH_PERCENT, (double)m_edWidthPercent );
	}
	GetDlgItemText( IDC_ED_G_ROTATION, buf, MAX_PATH );
	edValue = atof( buf );
	if( edValue != m_edRotate )
	{
		m_edRotate = edValue;
		TRACE(_T("\t m_edRotate = %d\n"), m_edRotate );
		CGS_SetValDbl( EDIT_OBJ_ROTATION, (double)m_edRotate );
	}
	GetDlgItemText( IDC_ED_G_WIDTH, buf, MAX_PATH );
	edValue = atof( buf );
	if( edValue != m_edWidth )
	{
		m_edWidth = edValue;
		TRACE(_T("\t m_edWidth = %d\n"), m_edWidth );
		CGS_SetValDbl( EDIT_OBJ_WIDTH_ABS, (double)m_edWidth );
	}
	GetDlgItemText( IDC_ED_HEIGHT_PERCENT, buf, MAX_PATH );
	edValue = atof( buf );
	if( edValue != m_edHeightPercent )
	{
		m_edHeightPercent = edValue;
		TRACE(_T("\t  m_edHeightPercent = %d\n"), m_edHeightPercent );
		CGS_SetValDbl( EDIT_OBJ_HEIGHT_PERCENT, (double)m_edHeightPercent );
	}
	GetDlgItemText( IDC_ED_G_BEVEL, buf, MAX_PATH );
	edValue = atof( buf );
	if( edValue != m_edBevel )
	{
		m_edBevel = edValue;
		TRACE(_T("\t m_edBevel = %d\n"), m_edBevel );
		CGS_SetValDbl( EDIT_OBJ_BEVEL_SIZE, (double)m_edBevel );
	}
	GetDlgItemText( IDC_ED_G_PRIORITY, buf, MAX_PATH );
	edValue = atof( buf );
	if( edValue != m_edPriority )
	{
		m_edPriority = edValue;
		TRACE(_T("\t m_edPriority = %d\n"), m_edPriority );
		CGS_SetValDbl( EDIT_OBJ_PRIORITY, (double)m_edPriority );
	}
	GetDlgItemText( IDC_ED_G_X, buf, MAX_PATH );
	edValue = atof( buf );
	if( edValue != m_edX )
	{
		m_edX = edValue;
		TRACE(_T("\t m_edX = %d\n"), m_edX );
		CGS_SetValDbl( EDIT_OBJ_X_POSITION_ABS, (double)m_edX );
	}
	GetDlgItemText( IDC_ED_G_Y, buf, MAX_PATH );
	edValue = atof( buf );	
	if( edValue != m_edY )
	{
		m_edY = edValue;
		TRACE(_T("\t m_edY = %d\n"), m_edY );
		CGS_SetValDbl( EDIT_OBJ_Y_POSITION_ABS, (double)m_edY );
	}

	AfxGetMainWnd()->SetFocus();	
}//end of CAttribImport::OnOK
//////////////////////////////////////////////////////////////////////////////////////////////
BOOL CAttribImport::PreTranslateMessage(MSG* pMsg)
{
	// Let the ToolTip process this message.
	m_tooltip.RelayEvent(pMsg);

	return CDialog::PreTranslateMessage(pMsg);	// CG: This was added by the ToolTips component.
}//end of CAttribImport::PreTranslateMessage
//////////////////////////////////////////////////////////////////////////////////////////////
VOID CAttribImport::InitDlgItemTextNTooltip()
{
	IN_TEXT_DATA* txtData = NULL;
	TCHAR	sep[] = _T("\"");
	TCHAR*	ptID;
	TCHAR*	ptTT;
	TCHAR*	ptEnd;

	DWORD numTxt = LoadTextFromCtl( "\\Util\\DlgImport.ctl", "[Tooltip]", &txtData );
	if( numTxt == 0 )
		return;

	for( DWORD i = 0; i < numTxt; i++ )
	{
		ptID   = _tcstok( txtData[i].szTT, sep );
		ptTT   = _tcstok( NULL, sep );
		ptEnd  = _tcstok( NULL, sep );
		if( ptEnd != 0 )
			*ptEnd = '\0';
			
		if( NULL != _tcsstr( txtData[i].szTT, _T("IDC_ED_G_PRIORITY") ) )
			txtData[i].idTT = IDC_ED_G_PRIORITY;
		else
			if( NULL != _tcsstr( txtData[i].szTT, _T("IDC_ED_G_BEVEL") ) )
				txtData[i].idTT = IDC_ED_G_BEVEL;
		else
			if( NULL != _tcsstr( txtData[i].szTT, _T("IDC_ED_H_PERCENT") ) )
				txtData[i].idTT = IDC_ED_H_PERCENT;
		else
			if( NULL != _tcsstr( txtData[i].szTT, _T("IDC_ED_G_WIDTH") ) )
				txtData[i].idTT = IDC_ED_G_WIDTH;
		else
			if( NULL != _tcsstr( txtData[i].szTT, _T("IDC_ED_G_ROTATION") ) )
				txtData[i].idTT = IDC_ED_G_ROTATION;
		else
			if( NULL != _tcsstr( txtData[i].szTT, _T("IDC_ED_V_PERCENT") ) )
				txtData[i].idTT = IDC_ED_V_PERCENT;
		else
			if( NULL != _tcsstr( txtData[i].szTT, _T("IDC_ED_G_HEIGHT") ) )
				txtData[i].idTT = IDC_ED_G_HEIGHT;
		else
			if( NULL != _tcsstr( txtData[i].szTT, _T("IDC_ED_G_X") ) )
				txtData[i].idTT = IDC_ED_G_X;
		else
			if( NULL != _tcsstr( txtData[i].szTT, _T("IDC_ED_G_Y") ) )
				txtData[i].idTT = IDC_ED_G_Y;
		else
			if( NULL != _tcsstr( txtData[i].szTT, _T("IDC_BT_G_B") ) )
				txtData[i].idTT = IDC_BT_G_B;
		else
			if( NULL != _tcsstr( txtData[i].szTT, _T("IDC_BT_G_MINUS") ) )
				txtData[i].idTT = IDC_BT_G_MINUS;
		else
			if( NULL != _tcsstr( txtData[i].szTT, _T("IDC_BT_G_PLUS") ) )
				txtData[i].idTT = IDC_BT_G_PLUS;
		else
			if( NULL != _tcsstr( txtData[i].szTT, _T("IDC_BT_G_F") ) )
				txtData[i].idTT = IDC_BT_G_F;
		else
			if( NULL != _tcsstr( txtData[i].szTT, _T("IDC_BT_G_LOCK") ) )
				txtData[i].idTT = IDC_BT_G_LOCK;
		else
			if( NULL != _tcsstr( txtData[i].szTT, _T("IDC_FRM_G_PREVIEW") ) )
				txtData[i].idTT = IDC_FRM_G_PREVIEW;
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
}//end of CAttribImport::InitDlgItemTextNTooltip()
//////////////////////////////////////////////////////////////////////////////////////////////
void CAttribImport::OnBtGB() 
{

	AfxGetMainWnd()->SetFocus();
}//end of CAttribImport::OnBtGB
//////////////////////////////////////////////////////////////////////////////////////////////
void CAttribImport::OnBtGF() 
{

	AfxGetMainWnd()->SetFocus();
}//end of CAttribImport::OnBtGF
//////////////////////////////////////////////////////////////////////////////////////////////
void CAttribImport::OnBtGLock() 
{

	AfxGetMainWnd()->SetFocus();
}//end of CAttribImport::OnBtGLock
//////////////////////////////////////////////////////////////////////////////////////////////
void CAttribImport::OnBtGMinus() 
{
	AfxGetMainWnd()->SetFocus();
}//end of CAttribImport::OnBtGMinus
//////////////////////////////////////////////////////////////////////////////////////////////
void CAttribImport::OnBtGPlus() 
{

	AfxGetMainWnd()->SetFocus();
}//end of CAttribImport::OnBtGPlus
//////////////////////////////////////////////////////////////////////////////////////////////
void CAttribImport::OnBtSaveStyle() 
{
	AfxGetMainWnd()->SetFocus();	
}//end of CAttribImport::OnBtSaveStyle() 
//////////////////////////////////////////////////////////////////////////////////////////////
void CAttribImport::OnBtAdvance() 
{
	AfxGetMainWnd()->SetFocus();	
}//end of CAttribImport::OnBtAdvance() 
//////////////////////////////////////////////////////////////////////////////////////////////
void CAttribImport::OnDeltaposSpnGBevel(NMHDR* pNMHDR, LRESULT* pResult) 
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
}//end of CAttribImport::OnDeltaposSpnGBevel
//////////////////////////////////////////////////////////////////////////////////////////////
void CAttribImport::OnDeltaposSpnGHeight(NMHDR* pNMHDR, LRESULT* pResult) 
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
}//end of CAttribImport::OnDeltaposSpnGHeight
//////////////////////////////////////////////////////////////////////////////////////////////
void CAttribImport::OnDeltaposSpnGPriority(NMHDR* pNMHDR, LRESULT* pResult) 
{
	NM_UPDOWN* pNMUpDown = (NM_UPDOWN*)pNMHDR;
	int val = pNMUpDown->iPos+pNMUpDown->iDelta;
	CGS_SetValDbl( EDIT_OBJ_PRIORITY, max(0, val) );

	AfxGetMainWnd()->SetFocus();
	*pResult = 0;
}//end of CAttribImport::OnDeltaposSpnGPriority
//////////////////////////////////////////////////////////////////////////////////////////////
void CAttribImport::OnDeltaposSpnGRotate(NMHDR* pNMHDR, LRESULT* pResult) 
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
}//end of CAttribImport::OnDeltaposSpnGRotate
//////////////////////////////////////////////////////////////////////////////////////////////
void CAttribImport::OnDeltaposSpnGWidth(NMHDR* pNMHDR, LRESULT* pResult) 
{
	NM_UPDOWN* pNMUpDown = (NM_UPDOWN*)pNMHDR;
	char	buf[MAX_PATH];
	m_ctlEdWidth.GetLine( 0, (LPTSTR)buf, MAX_PATH );	// get edit control value

	// Convert the control value + the increment
	double val = atof( buf ) + (double)pNMUpDown->iDelta;
	val = val < 3000 ? val : 3000; // range checking
	val = val < 1    ? 1   : val;

	CGS_SetValDbl( EDIT_OBJ_WIDTH_ABS, val );

	// Conver the double value to string for display
	DoubleToAlphaString( val, 1, (LPTSTR)buf );	// 1 means one digit after decimal point
	char* pSubStr = strstr( buf, ".0" );		// strip the floating part if 25.0
	if( pSubStr != NULL )						// ie: display 25 only
		*pSubStr = '\0';
	m_ctlEdWidth.SetWindowText( (LPTSTR)buf );

	AfxGetMainWnd()->SetFocus();
	*pResult = 0;
}//end of CAttribImport::OnDeltaposSpnGWidth
//////////////////////////////////////////////////////////////////////////////////////////////
void CAttribImport::OnDeltaposSpnGX(NMHDR* pNMHDR, LRESULT* pResult) 
{
	NM_UPDOWN* pNMUpDown = (NM_UPDOWN*)pNMHDR;
	char	buf[MAX_PATH];
	m_ctlEdX.GetLine( 0, (LPTSTR)buf, MAX_PATH );	// get edit control value

	// Convert the control value + the increment
	double val = atof( buf ) + (double)pNMUpDown->iDelta;
	val = val <  3000 ?  val  : 3000; // range checking
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
}//end of CAttribImport::OnDeltaposSpnGX
//////////////////////////////////////////////////////////////////////////////////////////////
void CAttribImport::OnDeltaposSpnGY(NMHDR* pNMHDR, LRESULT* pResult) 
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
}//end of CAttribImport::OnDeltaposSpnGY
//////////////////////////////////////////////////////////////////////////////////////////////
void CAttribImport::OnDeltaposSpnWidthPercent(NMHDR* pNMHDR, LRESULT* pResult) 
{
	NM_UPDOWN* pNMUpDown = (NM_UPDOWN*)pNMHDR;
	char	buf[MAX_PATH];
	m_ctlEdWidthPercent.GetLine( 0, (LPTSTR)buf, MAX_PATH );	// get edit control value

	// Convert the control value + the increment
	double val = atof( buf ) + (double)pNMUpDown->iDelta;
	val = val < 500 ? val : 500; // range checking
	val = val < 1   ? 1   : val;

	CGS_SetValDbl( EDIT_OBJ_WIDTH_PERCENT, val );

	// Conver the double value to string for display
	DoubleToAlphaString( val, 1, (LPTSTR)buf );	// 1 means one digit after decimal point
	char* pSubStr = strstr( buf, ".0" );		// strip the floating part if 25.0
	if( pSubStr != NULL )						// ie: display 25 only
		*pSubStr = '\0';
	m_ctlEdWidthPercent.SetWindowText( (LPTSTR)buf );

	AfxGetMainWnd()->SetFocus();
	*pResult = 0;

}//end of CAttribImport::OnDeltaposSpnWidthPercent
//////////////////////////////////////////////////////////////////////////////////////////////
void CAttribImport::OnDeltaposSpnHeightPercent(NMHDR* pNMHDR, LRESULT* pResult) 
{
	NM_UPDOWN* pNMUpDown = (NM_UPDOWN*)pNMHDR;
	char	buf[MAX_PATH];
	m_ctlEdHeightPercent.GetLine( 0, (LPTSTR)buf, MAX_PATH );	// get edit control value

	// Convert the control value + the increment
	double val = atof( buf ) + (double)pNMUpDown->iDelta;
	val = val < 500 ? val : 500; // range checking
	val = val < 1   ? 1   : val;

	CGS_SetValDbl( EDIT_OBJ_HEIGHT_PERCENT, val );

	// Conver the double value to string for display
	DoubleToAlphaString( val, 1, (LPTSTR)buf );	// 1 means one digit after decimal point
	char* pSubStr = strstr( buf, ".0" );		// strip the floating part if 25.0
	if( pSubStr != NULL )						// ie: display 25 only
		*pSubStr = '\0';
	m_ctlEdHeightPercent.SetWindowText( (LPTSTR)buf );

	AfxGetMainWnd()->SetFocus();
	*pResult = 0;

}//end of CAttribImport::OnDeltaposSpnHeightPercent
//////////////////////////////////////////////////////////////////////////////////////////////
void CAttribImport::OnPaint() 
{
	CPaintDC dc(this); // device context for painting
	CGS_CurAttrSample_OnPaint( (DWORD)GetDlgItem( IDC_FRM_G_PREVIEW )->m_hWnd );
}// end of CAttribImport::OnPaint() 
//////////////////////////////////////////////////////////////////////////////////////////////
VOID CAttribImport::DoValueUpdate()
{

}//end of CAttribImport::DoValueUpdate()
