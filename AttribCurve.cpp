// AttribCurve.cpp : implementation file
//

#include "stdafx.h"
#include "cgui.h"
#include "AttribCurve.h"
#include "Global.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CAttribCurve dialog

CAttribCurve::CAttribCurve(CWnd* pParent ) : CDialog(CAttribCurve::IDD, pParent)
{
	//{{AFX_DATA_INIT(CAttribCurve)
	m_edBevel		= 0;
	m_edLength		= 0;
	m_edPriority	= 0;
	m_edRotate		= 0;
	m_edRoundness	= 0;
	m_edThick		= 0;
	m_edVertices	= 0;
	m_edX			= 0;
	m_edY			= 0;
	//}}AFX_DATA_INIT
}

void CAttribCurve::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CAttribCurve)
	DDX_Control(pDX, IDC_ED_C_Y, m_ctlEdY);
	DDX_Control(pDX, IDC_ED_C_X, m_ctlEdX);
	DDX_Control(pDX, IDC_ED_C_VERTICES, m_ctlEdVertex);
	DDX_Control(pDX, IDC_ED_C_THICK, m_ctlEdThick);
	DDX_Control(pDX, IDC_ED_C_ROUNDNESS, m_ctlEdRound);
	DDX_Control(pDX, IDC_ED_C_ROTATION, m_ctlEdRotate);
	DDX_Control(pDX, IDC_ED_C_PRIORITY, m_ctlEdPriority);
	DDX_Control(pDX, IDC_ED_C_LENGTH, m_ctlEdLength);
	DDX_Control(pDX, IDC_ED_C_BEVEL, m_ctlEdBevel);
	DDX_Control(pDX, IDC_STC_C_Y, m_stcY);
	DDX_Control(pDX, IDC_STC_C_X, m_stcX);
	DDX_Control(pDX, IDC_STC_C_VERTICES, m_stcVertices);
	DDX_Control(pDX, IDC_STC_C_THICK, m_stcThick);
	DDX_Control(pDX, IDC_STC_C_ROUNDNESS, m_stcRoundness);
	DDX_Control(pDX, IDC_STC_C_ROTATION, m_stcRotate);
	DDX_Control(pDX, IDC_STC_C_LENGTH, m_stcLength);
	DDX_Control(pDX, IDC_STC_C_BEVEL, m_stcBevel);
	DDX_Control(pDX, IDC_BT_SAVE_STYLE, m_btSaveStyle);
	DDX_Control(pDX, IDC_BT_C_PLUS, m_btPlus);
	DDX_Control(pDX, IDC_BT_C_MINUS, m_btMinus);
	DDX_Control(pDX, IDC_BT_C_LOCK, m_btLock);
	DDX_Control(pDX, IDC_BT_C_F, m_btF);
	DDX_Control(pDX, IDC_BT_C_B, m_btB);
	DDX_Control(pDX, IDC_BT_ADVANCE, m_btAdvance);
	DDX_Text(pDX, IDC_ED_C_BEVEL, m_edBevel);
	DDX_Text(pDX, IDC_ED_C_LENGTH, m_edLength);
	DDX_Text(pDX, IDC_ED_C_PRIORITY, m_edPriority);
	DDX_Text(pDX, IDC_ED_C_ROTATION, m_edRotate);
	DDX_Text(pDX, IDC_ED_C_ROUNDNESS, m_edRoundness);
	DDX_Text(pDX, IDC_ED_C_THICK, m_edThick);
	DDX_Text(pDX, IDC_ED_C_VERTICES, m_edVertices);
	DDX_Text(pDX, IDC_ED_C_X, m_edX);
	DDX_Text(pDX, IDC_ED_C_Y, m_edY);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CAttribCurve, CDialog)
	//{{AFX_MSG_MAP(CAttribCurve)
	ON_BN_CLICKED(IDC_BT_SAVE_STYLE, OnBtSaveStyle)
	ON_BN_CLICKED(IDC_BT_ADVANCE, OnBtAdvance)
	ON_BN_CLICKED(IDC_BT_C_LOCK, OnBtCLock)
	ON_BN_CLICKED(IDC_BT_C_F, OnBtCF)
	ON_BN_CLICKED(IDC_BT_C_PLUS, OnBtCPlus)
	ON_BN_CLICKED(IDC_BT_C_MINUS, OnBtCMinus)
	ON_BN_CLICKED(IDC_BT_C_B, OnBtCB)
	ON_NOTIFY(UDN_DELTAPOS, IDC_SPN_C_BEVEL, OnDeltaposSpnCBevel)
	ON_NOTIFY(UDN_DELTAPOS, IDC_SPN_C_LENGTH, OnDeltaposSpnCLength)
	ON_NOTIFY(UDN_DELTAPOS, IDC_SPN_C_PRIORITY, OnDeltaposSpnCPriority)
	ON_NOTIFY(UDN_DELTAPOS, IDC_SPN_C_ROTATE, OnDeltaposSpnCRotate)
	ON_NOTIFY(UDN_DELTAPOS, IDC_SPN_C_ROUNDNESS, OnDeltaposSpnCRoundness)
	ON_NOTIFY(UDN_DELTAPOS, IDC_SPN_C_THICK, OnDeltaposSpnCThick)
	ON_NOTIFY(UDN_DELTAPOS, IDC_SPN_C_VERTICES, OnDeltaposSpnCVertices)
	ON_NOTIFY(UDN_DELTAPOS, IDC_SPN_C_X, OnDeltaposSpnCX)
	ON_NOTIFY(UDN_DELTAPOS, IDC_SPN_C_Y, OnDeltaposSpnCY)
	ON_WM_PAINT()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

////////////////////////////////////////////////////////////////////////////////////
// CAttribCurve message handlers
void CAttribCurve::OnOK() 
{	
	_TCHAR	buf[MAX_PATH];
	double  edValue;

	GetDlgItemText( IDC_ED_C_LENGTH, buf, MAX_PATH );
	edValue = atof( buf );
	if( edValue != m_edLength )
	{
		m_edLength = edValue;
		TRACE(_T("\t m_edLength = %f\n"), m_edLength );
		CGS_SetValDbl( EDIT_OBJ_STROKE_LENGTH, (double)m_edLength );
	}
	GetDlgItemText( IDC_ED_C_THICK, buf, MAX_PATH );
	edValue = atof( buf );
	if( edValue != m_edThick )
	{
		m_edThick = edValue;
		TRACE(_T("\t m_edThick = %f\n"), m_edThick );
		CGS_SetValDbl( EDIT_OBJ_STROKE_THICKNESS, (double)m_edThick );
	}
	GetDlgItemText( IDC_ED_C_ROTATION, buf, MAX_PATH );
	edValue = atof( buf );
	if( edValue != m_edRotate )
	{
		m_edRotate = edValue;
		TRACE(_T("\t m_edRotate = %f\n"), m_edRotate );
		CGS_SetValDbl( EDIT_OBJ_ROTATION, (double)m_edRotate );
	}
	GetDlgItemText( IDC_ED_C_VERTICES, buf, MAX_PATH );
	edValue = atof( buf );
	if( edValue != m_edVertices )
	{
		m_edVertices = (DWORD)edValue;
		TRACE(_T("\t m_edVertices = %f\n"), m_edVertices );
		CGS_SetValDbl( EDIT_OBJ_VERTEX_COUNT, (double)m_edVertices );
	}
	GetDlgItemText( IDC_ED_C_ROUNDNESS, buf, MAX_PATH );
	edValue = atof( buf );
	if( edValue != m_edRoundness )
	{
		m_edRoundness = edValue;
		TRACE(_T("\t m_edRoundness = %f\n"), m_edRoundness );
		CGS_SetValDbl( EDIT_OBJ_ROUNDNESS, m_edRoundness );
	}
	GetDlgItemText( IDC_ED_C_BEVEL, buf, MAX_PATH );
	edValue = atof( buf );
	if( edValue != m_edBevel )
	{
		m_edBevel = edValue;
		TRACE(_T("\t m_edBevel = %d\n"), m_edBevel );
		CGS_SetValDbl( EDIT_OBJ_BEVEL_SIZE, m_edBevel );
	}
	GetDlgItemText( IDC_ED_C_PRIORITY, buf, MAX_PATH );
	edValue = atof( buf );
	if( edValue != m_edPriority )
	{
		m_edPriority = edValue;
		TRACE(_T("\t m_edPriority = %d\n"), m_edPriority );
		CGS_SetValDbl( EDIT_OBJ_PRIORITY, (double)m_edPriority );
	}

	AfxGetMainWnd()->SetFocus();	

}//end of CAttribCurve::OnOK() 
////////////////////////////////////////////////////////////////////////////////////
void CAttribCurve::OnCancel() 
{
//	CDialog::OnCancel();
}//end of CAttribCurve::OnCancel() 
////////////////////////////////////////////////////////////////////////////////////
VOID CAttribCurve::DoValueUpdate()
{
	TRACE0("AttribCurve.cpp : Do Value Update\n");

}//end of CAttribCurve::DoValueUpdate()
////////////////////////////////////////////////////////////////////////////////////
VOID CAttribCurve::DeleteAttribCurve()
{
	DestroyWindow();
}//end of CAttribCurve::DeleteAttribCurve()
////////////////////////////////////////////////////////////////////////////////////
void CAttribCurve::OnBtSaveStyle() 
{
	AfxGetMainWnd()->SetFocus();	
}//end of CAttribCurve::OnBtSaveStyle()
////////////////////////////////////////////////////////////////////////////////////
void CAttribCurve::OnBtAdvance() 
{
	AfxGetMainWnd()->SetFocus();
}//end of CAttribCurve::OnBtAdvance()
////////////////////////////////////////////////////////////////////////////////////
void CAttribCurve::OnBtCLock() 
{
	AfxGetMainWnd()->SetFocus();
}//end of CAttribCurve::OnBtCLock() 
////////////////////////////////////////////////////////////////////////////////////
void CAttribCurve::OnBtCF() 
{
	AfxGetMainWnd()->SetFocus();
}//end of CAttribCurve::OnBtCF() 
////////////////////////////////////////////////////////////////////////////////////
void CAttribCurve::OnBtCPlus() 
{
	AfxGetMainWnd()->SetFocus();
}//end of CAttribCurve::OnBtCPlus() 
////////////////////////////////////////////////////////////////////////////////////
void CAttribCurve::OnBtCMinus() 
{
	AfxGetMainWnd()->SetFocus();
}//end of CAttribCurve::OnBtCMinus() 
////////////////////////////////////////////////////////////////////////////////////
void CAttribCurve::OnBtCB() 
{
	AfxGetMainWnd()->SetFocus();
}//end of CAttribCurve::OnBtCB()
////////////////////////////////////////////////////////////////////////////////////
BOOL CAttribCurve::OnInitDialog() 
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
	CSpinButtonCtrl* pSpin = (CSpinButtonCtrl*)GetDlgItem( IDC_SPN_C_LENGTH );
	pSpin->SetRange( 1, 3000 );
	//save for ref.	pSpin->SetPos((int) (m_dSpin * 10.0));
	pSpin = (CSpinButtonCtrl*)GetDlgItem( IDC_SPN_C_THICK );
	pSpin->SetRange( 1, 64 );
	pSpin = (CSpinButtonCtrl*)GetDlgItem( IDC_SPN_C_ROUNDNESS );
	pSpin->SetRange( 0, 100 );
	pSpin = (CSpinButtonCtrl*)GetDlgItem( IDC_SPN_C_PRIORITY );
	pSpin->SetRange( 0, 255 );
	pSpin = (CSpinButtonCtrl*)GetDlgItem( IDC_SPN_C_ROTATE );
	pSpin->SetRange( 0, 359 );
	pSpin = (CSpinButtonCtrl*)GetDlgItem( IDC_SPN_C_BEVEL );
	pSpin->SetRange( 0, 64 );
	pSpin = (CSpinButtonCtrl*)GetDlgItem( IDC_SPN_C_VERTICES );
	pSpin->SetRange( 3, 32 );
	pSpin = (CSpinButtonCtrl*)GetDlgItem( IDC_SPN_C_X );
	pSpin->SetRange( -3000, 3000 );
	pSpin = (CSpinButtonCtrl*)GetDlgItem( IDC_SPN_C_Y );
	pSpin->SetRange( -3000, 3000 );

	//+++++++++++++++++++++++++++++++++++++++++++++ Initial Edit control
	_TCHAR buf[MAX_PATH];

	CEdit* pEdCtrl = (CEdit*)GetDlgItem( IDC_ED_C_THICK );
	pEdCtrl->SetLimitText( 2 ); // 2 characters of 64
	DoubleToAlphaString( CGS_GetValDbl(EDIT_OBJ_STROKE_THICKNESS), 1, buf );
	char* pSubStr = strstr( buf, ".0" );		// strip the floating part if 25.0
	if( pSubStr != NULL )						// ie: display 25 only
		*pSubStr = '\0';
	SetDlgItemText(IDC_ED_C_THICK, buf );

	pEdCtrl = (CEdit*)GetDlgItem( IDC_ED_C_LENGTH );
	pEdCtrl->SetLimitText( 7 ); // 7 characters of 3000.99
	DoubleToAlphaString( CGS_GetValDbl(EDIT_OBJ_STROKE_LENGTH), 1, buf );
	pSubStr = strstr( buf, ".0" );		// strip the floating part if 25.0
	if( pSubStr != NULL )				// ie: display 25 only
		*pSubStr = '\0';
	SetDlgItemText(IDC_ED_C_LENGTH, buf );
	
	pEdCtrl = (CEdit*)GetDlgItem( IDC_ED_C_ROUNDNESS );
	pEdCtrl->SetLimitText( 3 ); // 3 characters of 100
	DoubleToAlphaString( CGS_GetValDbl(EDIT_OBJ_ROUNDNESS), 1, buf );
	pSubStr = strstr( buf, ".0" );		// strip the floating part if 25.0
	if( pSubStr != NULL )				// ie: display 25 only
		*pSubStr = '\0';
	SetDlgItemText(IDC_ED_C_ROUNDNESS, buf );
	
	pEdCtrl = (CEdit*)GetDlgItem( IDC_ED_C_PRIORITY );
	pEdCtrl->SetLimitText( 3 ); // 3 characters of 255 
	DoubleToAlphaString( CGS_GetValDbl(EDIT_OBJ_PRIORITY), 1, buf );
	pSubStr = strstr( buf, ".0" );		// strip the floating part if 25.0
	if( pSubStr != NULL )				// ie: display 25 only
		*pSubStr = '\0';
	SetDlgItemText(IDC_ED_C_PRIORITY, buf );
	
	pEdCtrl = (CEdit*)GetDlgItem( IDC_ED_C_VERTICES );
	pEdCtrl->SetLimitText( 2 ); // 2 characters of 32
	DoubleToAlphaString( CGS_GetValDbl(EDIT_OBJ_VERTEX_COUNT), 1, buf );
	pSubStr = strstr( buf, ".0" );		// strip the floating part if 25.0
	if( pSubStr != NULL )				// ie: display 25 only
		*pSubStr = '\0';
	SetDlgItemText(IDC_ED_C_VERTICES, buf );
	
	pEdCtrl = (CEdit*)GetDlgItem( IDC_ED_C_BEVEL );
	pEdCtrl->SetLimitText( 2 ); // 2 characters of 64
	DoubleToAlphaString( CGS_GetValDbl(EDIT_OBJ_BEVEL_SIZE), 1, buf );
	pSubStr = strstr( buf, ".0" );		// strip the floating part if 25.0
	if( pSubStr != NULL )				// ie: display 25 only
		*pSubStr = '\0';
	SetDlgItemText(IDC_ED_C_BEVEL, buf );
	
	pEdCtrl = (CEdit*)GetDlgItem( IDC_ED_C_ROTATION );
	pEdCtrl->SetLimitText( 5 ); // 3 characters of 359.00
	DoubleToAlphaString( CGS_GetValDbl(EDIT_OBJ_ROTATION), 1, buf );
	pSubStr = strstr( buf, ".0" );		// strip the floating part if 25.0
	if( pSubStr != NULL )				// ie: display 25 only
		*pSubStr = '\0';
	SetDlgItemText(IDC_ED_C_ROTATION, buf );
	
	pEdCtrl = (CEdit*)GetDlgItem( IDC_ED_C_X );
	pEdCtrl->SetLimitText( 8 ); // 8 characters of -3000.99
	DoubleToAlphaString( CGS_GetValDbl(EDIT_OBJ_X_POSITION_ABS), 1, buf );
	pSubStr = strstr( buf, ".0" );		// strip the floating part if 25.0
	if( pSubStr != NULL )				// ie: display 25 only
		*pSubStr = '\0';
	SetDlgItemText(IDC_ED_C_X, buf );
		
	pEdCtrl = (CEdit*)GetDlgItem( IDC_ED_C_Y );
	pEdCtrl->SetLimitText( 8 ); // 8 characters of -3000.00
	DoubleToAlphaString( CGS_GetValDbl(EDIT_OBJ_Y_POSITION_ABS), 1, buf );
	pSubStr = strstr( buf, ".0" );		// strip the floating part if 25.0
	if( pSubStr != NULL )				// ie: display 25 only
		*pSubStr = '\0';
	SetDlgItemText(IDC_ED_C_Y, buf );

	//+++++++++++++++++++++++++++++++++++++++++++++ Initial Static Icon
	m_stcThick.ModifyStyle( 0, SS_ICON );
	m_stcThick.SetIcon( (HICON)::LoadImage( AfxGetApp()->m_hInstance,MAKEINTRESOURCE( IDI_FONT_WIDTH ),IMAGE_ICON, 16, 16, 0 ) );
	m_stcLength.ModifyStyle( 0, SS_ICON );
	m_stcLength.SetIcon( (HICON)::LoadImage( AfxGetApp()->m_hInstance,MAKEINTRESOURCE( IDI_FONT_HEIGHT ),	IMAGE_ICON, 16, 16, 0 ) );
	m_stcBevel.ModifyStyle( 0, SS_ICON );
	m_stcBevel.SetIcon( (HICON)::LoadImage( AfxGetApp()->m_hInstance,MAKEINTRESOURCE( IDI_BEVEL ),IMAGE_ICON, 16, 16, 0 ) );
	m_stcVertices.ModifyStyle( 0, SS_ICON );
	m_stcVertices.SetIcon( (HICON)::LoadImage( AfxGetApp()->m_hInstance,MAKEINTRESOURCE( IDI_V_PERCENT ),IMAGE_ICON, 16, 16, 0 ) );
	m_stcRotate.ModifyStyle( 0, SS_ICON );
	m_stcRotate.SetIcon( (HICON)::LoadImage( AfxGetApp()->m_hInstance,MAKEINTRESOURCE( IDI_ROTATE ),IMAGE_ICON, 16, 16, 0 ) );
	m_stcRoundness.ModifyStyle( 0, SS_ICON );
	m_stcRoundness.SetIcon( (HICON)::LoadImage( AfxGetApp()->m_hInstance,MAKEINTRESOURCE( IDI_H_PERCENT ),IMAGE_ICON, 16, 16, 0 ) );
		
	m_tooltip.Create(this);	// Create the ToolTip control.
	m_tooltip.Activate(TRUE);

	InitDlgItemTextNTooltip();

	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}//end of CAttribCurve::OnInitDialog() 
///////////////////////////////////////////////////////////////////////////////////////
void CAttribCurve::OnDeltaposSpnCBevel(NMHDR* pNMHDR, LRESULT* pResult) 
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
}//end of CAttribCurve::OnDeltaposSpnCBevel
///////////////////////////////////////////////////////////////////////////////////////
void CAttribCurve::OnDeltaposSpnCLength(NMHDR* pNMHDR, LRESULT* pResult) 
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
}//end of CAttribCurve::OnDeltaposSpnCLength
///////////////////////////////////////////////////////////////////////////////////////
void CAttribCurve::OnDeltaposSpnCPriority(NMHDR* pNMHDR, LRESULT* pResult) 
{
	NM_UPDOWN* pNMUpDown = (NM_UPDOWN*)pNMHDR;
	char	buf[MAX_PATH];
	m_ctlEdRotate.GetLine( 0, (LPTSTR)buf, MAX_PATH );	// get edit control value

	// Convert the control value + the increment
	double val = atof( buf ) + (double)pNMUpDown->iDelta;
	val = val < 255 ? val : 255; // range checking
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
}//end of CAttribCurve::OnDeltaposSpnCPriority
///////////////////////////////////////////////////////////////////////////////////////
void CAttribCurve::OnDeltaposSpnCRotate(NMHDR* pNMHDR, LRESULT* pResult) 
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
}//end of CAttribCurve::OnDeltaposSpnCRotate
///////////////////////////////////////////////////////////////////////////////////////
void CAttribCurve::OnDeltaposSpnCRoundness(NMHDR* pNMHDR, LRESULT* pResult) 
{
	NM_UPDOWN* pNMUpDown = (NM_UPDOWN*)pNMHDR;
	char	buf[MAX_PATH];
	m_ctlEdRound.GetLine( 0, (LPTSTR)buf, MAX_PATH );	// get edit control value

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
	m_ctlEdRound.SetWindowText( (LPTSTR)buf );

	AfxGetMainWnd()->SetFocus();
	*pResult = 0;
}//end of CAttribCurve::OnDeltaposSpnCRoundness
///////////////////////////////////////////////////////////////////////////////////////
void CAttribCurve::OnDeltaposSpnCThick(NMHDR* pNMHDR, LRESULT* pResult) 
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
}//end of CAttribCurve::OnDeltaposSpnCThick
///////////////////////////////////////////////////////////////////////////////////////
void CAttribCurve::OnDeltaposSpnCVertices(NMHDR* pNMHDR, LRESULT* pResult) 
{
	NM_UPDOWN* pNMUpDown = (NM_UPDOWN*)pNMHDR;
	char	buf[MAX_PATH];
	m_ctlEdVertex.GetLine( 0, (LPTSTR)buf, MAX_PATH );	// get edit control value

	// Convert the control value + the increment
	double val = atof( buf ) + (double)pNMUpDown->iDelta;
	val = val < 32 ? val : 32; // range checking
	val = val < 3  ? 3   : val;

	CGS_SetValDbl( EDIT_OBJ_VERTEX_COUNT, val );

	// Conver the double value to string for display
	DoubleToAlphaString( val, 1, (LPTSTR)buf );	// 1 means one digit after decimal point
	char* pSubStr = strstr( buf, ".0" );		// strip the floating part if 25.0
	if( pSubStr != NULL )						// ie: display 25 only
		*pSubStr = '\0';
	m_ctlEdVertex.SetWindowText( (LPTSTR)buf );

	AfxGetMainWnd()->SetFocus();
	*pResult = 0;
}//end of CAttribCurve::OnDeltaposSpnCVertices
///////////////////////////////////////////////////////////////////////////////////////
void CAttribCurve::OnDeltaposSpnCX(NMHDR* pNMHDR, LRESULT* pResult) 
{
	NM_UPDOWN* pNMUpDown = (NM_UPDOWN*)pNMHDR;
	char	buf[MAX_PATH];
	m_ctlEdX.GetLine( 0, (LPTSTR)buf, MAX_PATH );	// get edit control value

	// Convert the control value + the increment
	double val = atof( buf ) + (double)pNMUpDown->iDelta;
	val = val < 3000  ? val   : 3000; // range checking
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
}//end of CAttribCurve::OnDeltaposSpnCX
///////////////////////////////////////////////////////////////////////////////////////
void CAttribCurve::OnDeltaposSpnCY(NMHDR* pNMHDR, LRESULT* pResult) 
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
}//end of CAttribCurve::OnDeltaposSpnCY
///////////////////////////////////////////////////////////////////////////////////////
BOOL CAttribCurve::PreTranslateMessage(MSG* pMsg)
{
	m_tooltip.RelayEvent(pMsg);
	return CDialog::PreTranslateMessage(pMsg);	// CG: This was added by the ToolTips component.
}//end of CAttribCurve::PreTranslateMessage(MSG* pMsg)
///////////////////////////////////////////////////////////////////////////////////////
VOID CAttribCurve::InitDlgItemTextNTooltip()
{
	IN_TEXT_DATA* txtData = NULL;
	TCHAR	sep[] = _T("\"");
	TCHAR*	ptID;
	TCHAR*	ptTT;
	TCHAR*	ptEnd;

	DWORD numTxt = LoadTextFromCtl( "\\Util\\DlgCurve.ctl", "[Tooltip]", &txtData );
	if( numTxt == 0 )
		return;

	for( DWORD i = 0; i < numTxt; i++ )
	{
		ptID   = _tcstok( txtData[i].szTT, sep );
		ptTT   = _tcstok( NULL, sep );
		ptEnd  = _tcstok( NULL, sep );
		if( ptEnd != 0 )
			*ptEnd = '\0';
			
		if( NULL != _tcsstr( txtData[i].szTT, _T("IDC_ED_C_PRIORITY") ) )
			txtData[i].idTT = IDC_ED_C_PRIORITY;
		else
			if( NULL != _tcsstr( txtData[i].szTT, _T("IDC_ED_C_BEVEL") ) )
				txtData[i].idTT = IDC_ED_C_BEVEL;
		else
			if( NULL != _tcsstr( txtData[i].szTT, _T("IDC_ED_C_ROUNDNESS") ) )
				txtData[i].idTT = IDC_ED_C_ROUNDNESS;
		else
			if( NULL != _tcsstr( txtData[i].szTT, _T("IDC_ED_C_THICK") ) )
				txtData[i].idTT = IDC_ED_C_THICK;
		else
			if( NULL != _tcsstr( txtData[i].szTT, _T("IDC_ED_C_ROTATION") ) )
				txtData[i].idTT = IDC_ED_C_ROTATION;
		else
			if( NULL != _tcsstr( txtData[i].szTT, _T("IDC_ED_C_VERTICES") ) )
				txtData[i].idTT = IDC_ED_C_VERTICES;
		else
			if( NULL != _tcsstr( txtData[i].szTT, _T("IDC_ED_C_LENGTH") ) )
				txtData[i].idTT = IDC_ED_C_LENGTH;
		else
			if( NULL != _tcsstr( txtData[i].szTT, _T("IDC_ED_C_X") ) )
				txtData[i].idTT = IDC_ED_C_X;
		else
			if( NULL != _tcsstr( txtData[i].szTT, _T("IDC_ED_C_Y") ) )
				txtData[i].idTT = IDC_ED_C_Y;
		else
			if( NULL != _tcsstr( txtData[i].szTT, _T("IDC_BT_C_B") ) )
				txtData[i].idTT = IDC_BT_C_B;
		else
			if( NULL != _tcsstr( txtData[i].szTT, _T("IDC_BT_C_MINUS") ) )
				txtData[i].idTT = IDC_BT_C_MINUS;
		else
			if( NULL != _tcsstr( txtData[i].szTT, _T("IDC_BT_C_PLUS") ) )
				txtData[i].idTT = IDC_BT_C_PLUS;
		else
			if( NULL != _tcsstr( txtData[i].szTT, _T("IDC_BT_C_F") ) )
				txtData[i].idTT = IDC_BT_C_F;
		else
			if( NULL != _tcsstr( txtData[i].szTT, _T("IDC_BT_C_LOCK") ) )
				txtData[i].idTT = IDC_BT_C_LOCK;
		else
			if( NULL != _tcsstr( txtData[i].szTT, _T("IDC_FRM_C_PREVIEW") ) )
				txtData[i].idTT = IDC_FRM_C_PREVIEW;
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

}//end of CAttribCurve::InitDlgItemTextNTooltip()
/////////////////////////////////////////////////////////////////////////////////////////
void CAttribCurve::OnPaint() 
{
	CPaintDC dc(this); // device context for painting
	CGS_CurAttrSample_OnPaint( (DWORD)GetDlgItem( IDC_FRM_C_PREVIEW )->m_hWnd );		
}//end of CAttribCurve::OnPaint() 
