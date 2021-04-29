// AttribPolygon.cpp : implementation file
//

#include "stdafx.h"
#include "cgui.h"
#include "AttribPolygon.h"
#include "Global.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CAttribPolygon dialog
CAttribPolygon::CAttribPolygon(CWnd* pParent ) : CDialog(CAttribPolygon::IDD, pParent)
{
	//{{AFX_DATA_INIT(CAttribPolygon)
	m_edBevel		= 0;
	m_edLength		= 0;
	m_edPriority	= 0;
	m_edRotate		= 0;
	m_edRoundness	= 0;
	m_edThick		= 0;
	m_edVertices	= 0;
	m_edX = 0;
	m_edY = 0;
	//}}AFX_DATA_INIT
}


void CAttribPolygon::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CAttribPolygon)
	DDX_Control(pDX, IDC_ED_P_ROUNDNESS, m_ctlEdRoundness);
	DDX_Control(pDX, IDC_ED_P_Y, m_ctlEdY);
	DDX_Control(pDX, IDC_ED_P_X, m_ctlEdX);
	DDX_Control(pDX, IDC_ED_P_VERTICES, m_ctlEdVertex);
	DDX_Control(pDX, IDC_ED_P_THICK, m_ctlEdThick);
	DDX_Control(pDX, IDC_ED_P_ROTATION, m_ctlEdRotate);
	DDX_Control(pDX, IDC_ED_P_PRIORITY, m_ctlEdPriority);
	DDX_Control(pDX, IDC_ED_P_LENGTH, m_ctlEdLength);
	DDX_Control(pDX, IDC_ED_P_BEVEL, m_ctlEdBevel);
	DDX_Control(pDX, IDC_STC_P_Y, m_stcY);
	DDX_Control(pDX, IDC_STC_P_X, m_stcX);
	DDX_Control(pDX, IDC_STC_P_VERTICES, m_stcVertices);
	DDX_Control(pDX, IDC_STC_P_THICK, m_stcThick);
	DDX_Control(pDX, IDC_STC_P_ROUNDNESS, m_stcRoundness);
	DDX_Control(pDX, IDC_STC_P_ROTATION, m_stcRotate);
	DDX_Control(pDX, IDC_STC_P_LENGTH, m_stcLength);
	DDX_Control(pDX, IDC_STC_P_BEVEL, m_stcBevel);
	DDX_Control(pDX, IDC_CK_POLY_FILL, m_ckPolyFill);
	DDX_Control(pDX, IDC_BT_SAVE_STYLE, m_btSaveStyle);
	DDX_Control(pDX, IDC_BT_P_PLUS, m_btPlus);
	DDX_Control(pDX, IDC_BT_P_MINUS, m_btMinus);
	DDX_Control(pDX, IDC_BT_P_LOCK, m_btLock);
	DDX_Control(pDX, IDC_BT_P_F, m_btF);
	DDX_Control(pDX, IDC_BT_P_B, m_btB);
	DDX_Control(pDX, IDC_BT_ADVANCE, m_btAdvance);
	DDX_Text(pDX, IDC_ED_P_BEVEL, m_edBevel);
	DDX_Text(pDX, IDC_ED_P_LENGTH, m_edLength);
	DDX_Text(pDX, IDC_ED_P_PRIORITY, m_edPriority);
	DDX_Text(pDX, IDC_ED_P_ROTATION, m_edRotate);
	DDX_Text(pDX, IDC_ED_P_ROUNDNESS, m_edRoundness);
	DDX_Text(pDX, IDC_ED_P_THICK, m_edThick);
	DDX_Text(pDX, IDC_ED_P_VERTICES, m_edVertices);
	DDX_Text(pDX, IDC_ED_P_X, m_edX);
	DDX_Text(pDX, IDC_ED_P_Y, m_edY);
	//}}AFX_DATA_MAP
}//end of CAttribPolygon::DoDataExchange

BEGIN_MESSAGE_MAP(CAttribPolygon, CDialog)
	//{{AFX_MSG_MAP(CAttribPolygon)
	ON_BN_CLICKED(IDC_BT_SAVE_STYLE, OnBtSaveStyle)
	ON_BN_CLICKED(IDC_BT_ADVANCE, OnBtAdvance)
	ON_BN_CLICKED(IDC_BT_P_LOCK, OnBtPLock)
	ON_BN_CLICKED(IDC_BT_P_F, OnBtPF)
	ON_BN_CLICKED(IDC_BT_P_PLUS, OnBtPPlus)
	ON_BN_CLICKED(IDC_BT_P_MINUS, OnBtPMinus)
	ON_BN_CLICKED(IDC_BT_P_B, OnBtPB)
	ON_NOTIFY(UDN_DELTAPOS, IDC_SPN_P_BEVEL, OnDeltaposSpnPBevel)
	ON_NOTIFY(UDN_DELTAPOS, IDC_SPN_P_LENGTH, OnDeltaposSpnPLength)
	ON_NOTIFY(UDN_DELTAPOS, IDC_SPN_P_PRIORITY, OnDeltaposSpnPPriority)
	ON_NOTIFY(UDN_DELTAPOS, IDC_SPN_P_ROTATE, OnDeltaposSpnPRotate)
	ON_NOTIFY(UDN_DELTAPOS, IDC_SPN_P_ROUNDNESS, OnDeltaposSpnPRoundness)
	ON_NOTIFY(UDN_DELTAPOS, IDC_SPN_P_THICK, OnDeltaposSpnPThick)
	ON_NOTIFY(UDN_DELTAPOS, IDC_SPN_P_VERTICES, OnDeltaposSpnPVertices)
	ON_NOTIFY(UDN_DELTAPOS, IDC_SPN_P_X, OnDeltaposSpnPX)
	ON_NOTIFY(UDN_DELTAPOS, IDC_SPN_P_Y, OnDeltaposSpnPY)
	ON_WM_PAINT()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CAttribPolygon message handlers
void CAttribPolygon::OnOK() 
{
	_TCHAR	buf[MAX_PATH];
	double  edValue;

	GetDlgItemText( IDC_ED_P_LENGTH, buf, MAX_PATH );
	edValue = atof( buf );
	if( edValue != m_edLength )
	{
		m_edLength = edValue;
		TRACE(_T("\t m_edLength = %f\n"), m_edLength );
		CGS_SetValDbl( EDIT_OBJ_STROKE_LENGTH, (double)m_edLength );
	}
	GetDlgItemText( IDC_ED_P_THICK, buf, MAX_PATH );
	edValue = atof( buf );
	if( edValue != m_edThick )
	{
		m_edThick = edValue;
		TRACE(_T("\t m_edThick = %f\n"), m_edThick );
		CGS_SetValDbl( EDIT_OBJ_STROKE_THICKNESS, (double)m_edThick );
	}
	GetDlgItemText( IDC_ED_P_ROTATION, buf, MAX_PATH );
	edValue = atof( buf );
	if( edValue != m_edRotate )
	{
		m_edRotate = edValue;
		TRACE(_T("\t m_edRotate = %f\n"), m_edRotate );
		CGS_SetValDbl( EDIT_OBJ_ROTATION, (double)m_edRotate );
	}
	GetDlgItemText( IDC_ED_P_VERTICES, buf, MAX_PATH );
	edValue = atof( buf );
	if( edValue != m_edVertices )
	{
		m_edVertices = (DWORD)edValue;
		TRACE(_T("\t m_edVertices = %f\n"), m_edVertices );
		CGS_SetValDbl( EDIT_OBJ_VERTEX_COUNT, (double)m_edVertices );
	}
	GetDlgItemText( IDC_ED_P_ROUNDNESS, buf, MAX_PATH );
	edValue = atof( buf );
	if( edValue != m_edRoundness )
	{
		m_edRoundness = edValue;
		TRACE(_T("\t m_edRoundness = %f\n"), m_edRoundness );
		CGS_SetValDbl( EDIT_OBJ_ROUNDNESS, m_edRoundness );
	}
	GetDlgItemText( IDC_ED_P_BEVEL, buf, MAX_PATH );
	edValue = atof( buf );
	if( edValue != m_edBevel )
	{
		m_edBevel = edValue;
		TRACE(_T("\t m_edBevel = %d\n"), m_edBevel );
		CGS_SetValDbl( EDIT_OBJ_BEVEL_SIZE, m_edBevel );
	}
	GetDlgItemText( IDC_ED_T_PRIORITY, buf, MAX_PATH );
	edValue = atof( buf );
	if( edValue != m_edPriority )
	{
		m_edPriority = edValue;
		TRACE(_T("\t m_edPriority = %d\n"), m_edPriority );
		CGS_SetValDbl( EDIT_OBJ_PRIORITY, (double)m_edPriority );
	}

	AfxGetMainWnd()->SetFocus();	
}//end of CAttribPolygon::OnOK() 
/////////////////////////////////////////////////////////////////////////////
void CAttribPolygon::OnCancel() 
{
//	CDialog::OnCancel();
}//end of CAttribPolygon::OnCancel() 
/////////////////////////////////////////////////////////////////////////////
VOID CAttribPolygon::DeleteAttribPoly()
{
	DestroyWindow();
}//end of CAttribPolygon::DeleteAttribPoly()
/////////////////////////////////////////////////////////////////////////////
void CAttribPolygon::OnBtSaveStyle() 
{
	AfxGetMainWnd()->SetFocus();
}//end of CAttribPolygon::OnBtSaveStyle() 
/////////////////////////////////////////////////////////////////////////////
void CAttribPolygon::OnBtAdvance() 
{
	AfxGetMainWnd()->SetFocus();
}//end of CAttribPolygon::OnBtAdvance()
/////////////////////////////////////////////////////////////////////////////
void CAttribPolygon::OnBtPLock() 
{
	m_LockState ^= 1;
	CGS_SetValDbl( EDIT_LOCK_ATTRIBUTES, m_LockState );
	AfxGetMainWnd()->SetFocus();
}//end of CAttribPolygon::OnBtPLock()
/////////////////////////////////////////////////////////////////////////////
void CAttribPolygon::OnBtPF() 
{
	AfxGetMainWnd()->SetFocus();
}//end of CAttribPolygon::OnBtPF()
/////////////////////////////////////////////////////////////////////////////
void CAttribPolygon::OnBtPPlus() 
{
	int edValue = GetDlgItemInt( IDC_ED_P_PRIORITY, NULL, 0 ) + 1;
	if( edValue < 256 )
	{
		CGS_SetValDbl( EDIT_OBJ_PRIORITY, (double)edValue );
		SetDlgItemInt( IDC_ED_P_PRIORITY, edValue, 1 );
	}

	AfxGetMainWnd()->SetFocus();
}//end of CAttribPolygon::OnBtPPlus()
/////////////////////////////////////////////////////////////////////////////
void CAttribPolygon::OnBtPMinus() 
{
	AfxGetMainWnd()->SetFocus();
}//end of CAttribPolygon::OnBtPMinus()
/////////////////////////////////////////////////////////////////////////////
void CAttribPolygon::OnBtPB() 
{
	AfxGetMainWnd()->SetFocus();
}//end of CAttribPolygon::OnBtPB() 
/////////////////////////////////////////////////////////////////////////////
void CAttribPolygon::OnDeltaposSpnPBevel(NMHDR* pNMHDR, LRESULT* pResult) 
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
}// end of CAttribPolygon::OnDeltaposSpnPBevel
////////////////////////////////////////////////////////////////////////////////////////
void CAttribPolygon::OnDeltaposSpnPLength(NMHDR* pNMHDR, LRESULT* pResult) 
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
}// end of CAttribPolygon::OnDeltaposSpnPLength
////////////////////////////////////////////////////////////////////////////////////////
void CAttribPolygon::OnDeltaposSpnPPriority(NMHDR* pNMHDR, LRESULT* pResult) 
{
	NM_UPDOWN* pNMUpDown = (NM_UPDOWN*)pNMHDR;

	int val = pNMUpDown->iPos+pNMUpDown->iDelta;
	CGS_SetValDbl( EDIT_OBJ_PRIORITY, max(0, val) );
	AfxGetMainWnd()->SetFocus();
	*pResult = 0;
}// end of CAttribPolygon::OnDeltaposSpnPPriority
////////////////////////////////////////////////////////////////////////////////////////
void CAttribPolygon::OnDeltaposSpnPRotate(NMHDR* pNMHDR, LRESULT* pResult) 
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

}// end of CAttribPolygon::OnDeltaposSpnPRotate
////////////////////////////////////////////////////////////////////////////////////////
void CAttribPolygon::OnDeltaposSpnPRoundness(NMHDR* pNMHDR, LRESULT* pResult) 
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
}// end of CAttribPolygon::OnDeltaposSpnPRoundness
////////////////////////////////////////////////////////////////////////////////////////
void CAttribPolygon::OnDeltaposSpnPThick(NMHDR* pNMHDR, LRESULT* pResult) 
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
}// end of CAttribPolygon::OnDeltaposSpnPThick
////////////////////////////////////////////////////////////////////////////////////////
void CAttribPolygon::OnDeltaposSpnPVertices(NMHDR* pNMHDR, LRESULT* pResult) 
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
}// end of CAttribPolygon::OnDeltaposSpnPVertices
////////////////////////////////////////////////////////////////////////////////////////
void CAttribPolygon::OnDeltaposSpnPX(NMHDR* pNMHDR, LRESULT* pResult) 
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
}// end of CAttribPolygon::OnDeltaposSpnPX
////////////////////////////////////////////////////////////////////////////////////////
void CAttribPolygon::OnDeltaposSpnPY(NMHDR* pNMHDR, LRESULT* pResult) 
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
}// end of CAttribPolygon::OnDeltaposSpnPY
////////////////////////////////////////////////////////////////////////////////////////
void CAttribPolygon::OnPaint() 
{
	CPaintDC dc(this); // device context for painting
	CGS_CurAttrSample_OnPaint( (DWORD)GetDlgItem( IDC_FRM_P_PREVIEW )->m_hWnd );
}//end of CAttribPolygon::OnPaint() 
////////////////////////////////////////////////////////////////////////////////////////
BOOL CAttribPolygon::PreTranslateMessage(MSG* pMsg)
{
	m_tooltip.RelayEvent(pMsg);
	return CDialog::PreTranslateMessage(pMsg);	// CG: This was added by the ToolTips component.
}//end of  CAttribPolygon::PreTranslateMessage
////////////////////////////////////////////////////////////////////////////////////////
BOOL CAttribPolygon::OnInitDialog()
{
	CDialog::OnInitDialog();	// CG: This was added by the ToolTips component.

	//++++++++++++++++++ Initial radio button and Icon
	m_btB.SetIcon( (HICON)::LoadImage( AfxGetApp()->m_hInstance, MAKEINTRESOURCE(IDI_BACK_GRD), IMAGE_ICON, 16, 16, 0) );
	m_btF.SetIcon( (HICON)::LoadImage( AfxGetApp()->m_hInstance, MAKEINTRESOURCE(IDI_FORE_GRD), IMAGE_ICON, 16, 16, 0) );
	m_btLock.SetIcon( (HICON)::LoadImage( AfxGetApp()->m_hInstance,	MAKEINTRESOURCE(IDI_LOCK), IMAGE_ICON, 16, 16, 0) );
	m_btMinus.SetIcon( (HICON)::LoadImage( AfxGetApp()->m_hInstance, MAKEINTRESOURCE(IDI_BACK_MINUS), IMAGE_ICON, 16, 16, 0) );
	m_btPlus.SetIcon( (HICON)::LoadImage( AfxGetApp()->m_hInstance,	MAKEINTRESOURCE(IDI_FORE_PLUS), IMAGE_ICON, 16, 16, 0) );
	m_btAdvance.SetIcon(  (HICON)::LoadImage( AfxGetApp()->m_hInstance, MAKEINTRESOURCE(IDI_ADVANCE),      IMAGE_ICON, 16, 16, 0) );		
	m_btSaveStyle.SetIcon( (HICON)::LoadImage( AfxGetApp()->m_hInstance, MAKEINTRESOURCE(IDI_SAVE_STYLE),   IMAGE_ICON, 16, 16, 0) );

	// ++++++++++++++++++++++++++++++++++++++++++++ Initial spin control
	CSpinButtonCtrl* pSpin = (CSpinButtonCtrl*)GetDlgItem( IDC_SPN_P_LENGTH );
	pSpin->SetRange( 1, 3000 );
	//save for ref.	pSpin->SetPos((int) (m_dSpin * 10.0));
	pSpin = (CSpinButtonCtrl*)GetDlgItem( IDC_SPN_P_THICK );
	pSpin->SetRange( 1, 64 );
	pSpin = (CSpinButtonCtrl*)GetDlgItem( IDC_SPN_P_ROUNDNESS );
	pSpin->SetRange( 0, 100 );
	pSpin = (CSpinButtonCtrl*)GetDlgItem( IDC_SPN_P_PRIORITY );
	pSpin->SetRange( 0, 255 );
	pSpin = (CSpinButtonCtrl*)GetDlgItem( IDC_SPN_P_ROTATE );
	pSpin->SetRange( 0, 359 );
	pSpin = (CSpinButtonCtrl*)GetDlgItem( IDC_SPN_P_BEVEL );
	pSpin->SetRange( 0, 64 );
	pSpin = (CSpinButtonCtrl*)GetDlgItem( IDC_SPN_P_VERTICES );
	pSpin->SetRange( 3, 32 );
	pSpin = (CSpinButtonCtrl*)GetDlgItem( IDC_SPN_P_X );
	pSpin->SetRange( -3000, 3000 );
	pSpin = (CSpinButtonCtrl*)GetDlgItem( IDC_SPN_P_Y );
	pSpin->SetRange( -3000, 3000 );

	//+++++++++++++++++++++++++++++++++++++++++++++ Initial Edit control
	_TCHAR buf[MAX_PATH];

	CEdit* pEdCtrl = (CEdit*)GetDlgItem( IDC_ED_P_THICK );
	pEdCtrl->SetLimitText( 2 ); // 2 characters of 64
	DoubleToAlphaString( CGS_GetValDbl(EDIT_OBJ_STROKE_THICKNESS), 1, buf );
	char* pSubStr = strstr( buf, ".0" );		// strip the floating part if 25.0
	if( pSubStr != NULL )						// ie: display 25 only
		*pSubStr = '\0';
	SetDlgItemText(IDC_ED_P_THICK, buf );

	pEdCtrl = (CEdit*)GetDlgItem( IDC_ED_P_LENGTH );
	pEdCtrl->SetLimitText( 7 ); // 7 characters of 3000.00
	DoubleToAlphaString( CGS_GetValDbl(EDIT_OBJ_STROKE_LENGTH), 1, buf );
	pSubStr = strstr( buf, ".0" );		// strip the floating part if 25.0
	if( pSubStr != NULL )				// ie: display 25 only
		*pSubStr = '\0';
	SetDlgItemText(IDC_ED_P_LENGTH, buf );
	
	pEdCtrl = (CEdit*)GetDlgItem( IDC_ED_P_ROUNDNESS );
	pEdCtrl->SetLimitText( 3 ); // 3 characters of 100
	DoubleToAlphaString( CGS_GetValDbl(EDIT_OBJ_ROUNDNESS), 1, buf );
	pSubStr = strstr( buf, ".0" );		// strip the floating part if 25.0
	if( pSubStr != NULL )				// ie: display 25 only
		*pSubStr = '\0';
	SetDlgItemText(IDC_ED_P_ROUNDNESS, buf );
	
	pEdCtrl = (CEdit*)GetDlgItem( IDC_ED_P_PRIORITY );
	pEdCtrl->SetLimitText( 3 ); // 3 characters of 255 
	DoubleToAlphaString( CGS_GetValDbl(EDIT_OBJ_PRIORITY), 1, buf );
	pSubStr = strstr( buf, ".0" );		// strip the floating part if 25.0
	if( pSubStr != NULL )				// ie: display 25 only
		*pSubStr = '\0';
	SetDlgItemText(IDC_ED_P_PRIORITY, buf );
	
	pEdCtrl = (CEdit*)GetDlgItem( IDC_ED_P_VERTICES );
	pEdCtrl->SetLimitText( 2 ); // 2 characters of 32
	DoubleToAlphaString( CGS_GetValDbl(EDIT_OBJ_VERTEX_COUNT), 1, buf );
	pSubStr = strstr( buf, ".0" );		// strip the floating part if 25.0
	if( pSubStr != NULL )				// ie: display 25 only
		*pSubStr = '\0';
	SetDlgItemText(IDC_ED_P_VERTICES, buf );
	
	pEdCtrl = (CEdit*)GetDlgItem( IDC_ED_P_BEVEL );
	pEdCtrl->SetLimitText( 2 ); // 2 characters of 64
	DoubleToAlphaString( CGS_GetValDbl(EDIT_OBJ_BEVEL_SIZE), 1, buf );
	pSubStr = strstr( buf, ".0" );		// strip the floating part if 25.0
	if( pSubStr != NULL )				// ie: display 25 only
		*pSubStr = '\0';
	SetDlgItemText(IDC_ED_P_BEVEL, buf );
	
	pEdCtrl = (CEdit*)GetDlgItem( IDC_ED_P_ROTATION );
	pEdCtrl->SetLimitText( 6 ); // 3 characters of 359.99
	DoubleToAlphaString( CGS_GetValDbl(EDIT_OBJ_ROTATION), 1, buf );
	pSubStr = strstr( buf, ".0" );		// strip the floating part if 25.0
	if( pSubStr != NULL )				// ie: display 25 only
		*pSubStr = '\0';
	SetDlgItemText(IDC_ED_P_ROTATION, buf );
	
	pEdCtrl = (CEdit*)GetDlgItem( IDC_ED_P_X );
	pEdCtrl->SetLimitText( 8 ); // 8 characters of -3000.00
	DoubleToAlphaString( CGS_GetValDbl(EDIT_OBJ_X_POSITION_ABS), 1, buf );
	pSubStr = strstr( buf, ".0" );		// strip the floating part if 25.0
	if( pSubStr != NULL )				// ie: display 25 only
		*pSubStr = '\0';
	SetDlgItemText(IDC_ED_P_X, buf );
	
	pEdCtrl = (CEdit*)GetDlgItem( IDC_ED_P_Y );
	pEdCtrl->SetLimitText( 8 ); // 8 characters of -3000.00
	DoubleToAlphaString( CGS_GetValDbl(EDIT_OBJ_Y_POSITION_ABS), 1, buf );
	pSubStr = strstr( buf, ".0" );		// strip the floating part if
	if( pSubStr != NULL )				// ie: display 25 only
		*pSubStr = '\0';
	SetDlgItemText(IDC_ED_P_Y, buf );

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
	
	m_tooltip.Create(this); // Create the ToolTip control.
	m_tooltip.Activate(TRUE);

	InitDlgItemTextNTooltip();

	return TRUE;	// CG: This was added by the ToolTips component.
}//end of CAttribPolygon::OnInitDialog()
/////////////////////////////////////////////////////////////////////////////////////////
VOID CAttribPolygon::InitDlgItemTextNTooltip()
{
	IN_TEXT_DATA* txtData = NULL;
	TCHAR	sep[] = _T("\"");
	TCHAR*	ptID;
	TCHAR*	ptTT;
	TCHAR*	ptEnd;

	DWORD numTxt = LoadTextFromCtl( "\\Util\\DlgPolygon.ctl", "[Tooltip]", &txtData );
	if( numTxt == 0 )
		return;

	for( DWORD i = 0; i < numTxt; i++ )
	{
		ptID   = _tcstok( txtData[i].szTT, sep );
		ptTT   = _tcstok( NULL, sep );
		ptEnd  = _tcstok( NULL, sep );
		if( ptEnd != 0 )
			*ptEnd = '\0';
			
		if( NULL != _tcsstr( txtData[i].szTT, _T("IDC_ED_P_PRIORITY") ) )
			txtData[i].idTT = IDC_ED_P_PRIORITY;
		else
			if( NULL != _tcsstr( txtData[i].szTT, _T("IDC_ED_P_BEVEL") ) )
				txtData[i].idTT = IDC_ED_P_BEVEL;
		else
			if( NULL != _tcsstr( txtData[i].szTT, _T("IDC_ED_P_ROUNDNESS") ) )
				txtData[i].idTT = IDC_ED_P_ROUNDNESS;
		else
			if( NULL != _tcsstr( txtData[i].szTT, _T("IDC_ED_P_THICK") ) )
				txtData[i].idTT = IDC_ED_P_THICK;
		else
			if( NULL != _tcsstr( txtData[i].szTT, _T("IDC_ED_P_ROTATION") ) )
				txtData[i].idTT = IDC_ED_P_ROTATION;
		else
			if( NULL != _tcsstr( txtData[i].szTT, _T("IDC_ED_P_VERTICES") ) )
				txtData[i].idTT = IDC_ED_P_VERTICES;
		else
			if( NULL != _tcsstr( txtData[i].szTT, _T("IDC_ED_P_LENGTH") ) )
				txtData[i].idTT = IDC_ED_P_LENGTH;
		else
			if( NULL != _tcsstr( txtData[i].szTT, _T("IDC_ED_P_X") ) )
				txtData[i].idTT = IDC_ED_P_X;
		else
			if( NULL != _tcsstr( txtData[i].szTT, _T("IDC_ED_P_Y") ) )
				txtData[i].idTT = IDC_ED_P_Y;
		else
			if( NULL != _tcsstr( txtData[i].szTT, _T("IDC_BT_P_B") ) )
				txtData[i].idTT = IDC_BT_P_B;
		else
			if( NULL != _tcsstr( txtData[i].szTT, _T("IDC_BT_P_MINUS") ) )
				txtData[i].idTT = IDC_BT_P_MINUS;
		else
			if( NULL != _tcsstr( txtData[i].szTT, _T("IDC_BT_P_PLUS") ) )
				txtData[i].idTT = IDC_BT_P_PLUS;
		else
			if( NULL != _tcsstr( txtData[i].szTT, _T("IDC_BT_P_F") ) )
				txtData[i].idTT = IDC_BT_P_F;
		else
			if( NULL != _tcsstr( txtData[i].szTT, _T("IDC_BT_P_LOCK") ) )
				txtData[i].idTT = IDC_BT_P_LOCK;
		else
			if( NULL != _tcsstr( txtData[i].szTT, _T("IDC_FRM_P_PREVIEW") ) )
				txtData[i].idTT = IDC_FRM_P_PREVIEW;
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
}//end of CAttribPolygon::InitDlgItemTextNTooltip()
//////////////////////////////////////////////////////////////////////////////////////
VOID CAttribPolygon::DoValueUpdate()
{
	TRACE0("AttribPolygon.cpp : CAttribPolygon::DoValueUpdate()\n");
}//end of CAttribPolygon::DoValueUpdate()
