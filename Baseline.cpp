// Baseline.cpp : implementation file
//

#include "stdafx.h"
#include "cgui.h"
#include "Baseline.h"
#include "Global.h"
#include "switch.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

extern TCHAR	UILang_UIFont[256];
extern int		UILang_UIFontSize;

/////////////////////////////////////////////////////////////////////////////
// CDlgBaselne dialog


CDlgBaselne::CDlgBaselne(CWnd* pParent /*=NULL*/) : CDialog(CDlgBaselne::IDD, pParent)
{
	//{{AFX_DATA_INIT(CDlgBaselne)
	m_dbCirAspect   = 0.0;
	m_dbCirRadius   = 0.0;
	m_dbCurvCtrl    = 0;
	m_dbLineSpace   = 0;
	m_dbLeftMargin  = 0;
	m_dbRightMargin = 0;
	m_dbRotate      = 0;
	m_edlX          = 0;
	m_edlY          = 0;
	//}}AFX_DATA_INIT
	m_hFont = NULL;
}

CDlgBaselne::~CDlgBaselne()
{
	for( DWORD i = 0; i < m_numTxt; i++ )
	{
		if( m_hFont[i] != NULL )
			DeleteObject( (HGDIOBJ)m_hFont[i] );
	}

	if( m_hFont != NULL )
		delete [] m_hFont;
}

void CDlgBaselne::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDlgBaselne)
	DDX_Control(pDX, IDC_SPN_Y, m_spnY);
	DDX_Control(pDX, IDC_SPN_X, m_spnX);
	DDX_Control(pDX, IDC_SPN_CURVE_CTRL, m_spnCurvCtrl);
	DDX_Control(pDX, IDC_RB_TOP_RIGHT, m_rbTopRight);
	DDX_Control(pDX, IDC_RB_TOP_DOWN, m_rbTopDown);
	DDX_Control(pDX, IDC_RB_RIGHT, m_rbRight);
	DDX_Control(pDX, IDC_RB_LINE, m_rbLine);
	DDX_Control(pDX, IDC_RB_LEFT, m_rbLeft);
	DDX_Control(pDX, IDC_RB_JUSTIFY, m_rbJustify);
	DDX_Control(pDX, IDC_RB_CURVE, m_rbCurve);
	DDX_Control(pDX, IDC_RB_CIRCLE, m_rbCircle);
	DDX_Control(pDX, IDC_RB_CENTER, m_rbCenter);
	DDX_Control(pDX, IDC_RB_BOTTOM_UP, m_rbBottomUp);
	DDX_Control(pDX, IDC_RB_AUTO, m_rbAuto);
	DDX_Control(pDX, IDC_SPN_RADIUS, m_spnCirRadius);
	DDX_Control(pDX, IDC_SPN_ASPECT, m_spnCirAspect);
	DDX_Control(pDX, IDC_RB_IN, m_rbIn);
	DDX_Control(pDX, IDC_RB_OUT, m_rbOut);
	DDX_Control(pDX, IDC_STC_ALIGN_CIR, m_stcAlignCir);
	DDX_Control(pDX, IDC_STC_CIR_ASPECT, m_stcCirAspect);
	DDX_Control(pDX, IDC_STC_CIR_RADIUS, m_stcCirRadius);
	DDX_Control(pDX, IDC_STC_CURVE_POINT, m_stcCurvPoint);
	DDX_Control(pDX, IDC_GP_CURVE_CTRL, m_gpCurvCtrl);
	DDX_Control(pDX, IDC_GP_CIRCLE_CTRL, m_gpCirCtrl);
	DDX_Control(pDX, IDC_ED_Y, m_edY);
	DDX_Control(pDX, IDC_ED_X, m_edX);
	DDX_Control(pDX, IDC_ED_ROTATION, m_edRotation);
	DDX_Control(pDX, IDC_ED_MARGIN_RIGHT, m_edMarginRight);
	DDX_Control(pDX, IDC_ED_MARGIN_LEFT, m_edMarginLeft);
	DDX_Control(pDX, IDC_ED_LNE_SPACE, m_edLneSpace);
	DDX_Control(pDX, IDC_ED_CURVE_CTRL, m_edCurvCtrl);
	DDX_Control(pDX, IDC_ED_CIR_RADIUS, m_edCirRadius);
	DDX_Control(pDX, IDC_ED_CIR_ASPECT, m_edCirAspect);
	DDX_Text(pDX, IDC_ED_CIR_ASPECT, m_dbCirAspect);
	DDX_Text(pDX, IDC_ED_CIR_RADIUS, m_dbCirRadius);
	DDX_Text(pDX, IDC_ED_CURVE_CTRL, m_dbCurvCtrl);
	DDX_Text(pDX, IDC_ED_LNE_SPACE, m_dbLineSpace);
	DDX_Text(pDX, IDC_ED_MARGIN_LEFT, m_dbLeftMargin);
	DDX_Text(pDX, IDC_ED_MARGIN_RIGHT, m_dbRightMargin);
	DDX_Text(pDX, IDC_ED_ROTATION, m_dbRotate);
	DDX_Text(pDX, IDC_ED_X, m_edlX);
	DDX_Text(pDX, IDC_ED_Y, m_edlY);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CDlgBaselne, CDialog)
	//{{AFX_MSG_MAP(CDlgBaselne)
	ON_BN_CLICKED(IDC_RB_LINE, OnRbLine)
	ON_BN_CLICKED(IDC_RB_CURVE, OnRbCurve)
	ON_BN_CLICKED(IDC_RB_CIRCLE, OnRbCircle)
	ON_BN_CLICKED(IDC_RB_LEFT, OnRbLeft)
	ON_BN_CLICKED(IDC_RB_CENTER, OnRbCenter)
	ON_BN_CLICKED(IDC_RB_RIGHT, OnRbRight)
	ON_BN_CLICKED(IDC_RB_JUSTIFY, OnRbJustify)
	ON_BN_CLICKED(IDC_RB_AUTO, OnRbAuto)
	ON_BN_CLICKED(IDC_RB_TOP_RIGHT, OnRbTopRight)
	ON_BN_CLICKED(IDC_RB_BOTTOM_UP, OnRbBottomUp)
	ON_BN_CLICKED(IDC_RB_TOP_DOWN, OnRbTopDown)
	ON_BN_CLICKED(IDC_BT_CHAR_PLUS, OnBtCharPlus)
	ON_BN_CLICKED(IDC_BT_CHAR_MINUS, OnBtCharMinus)
	ON_BN_CLICKED(IDC_RB_OUT, OnRbOut)
	ON_BN_CLICKED(IDC_RB_IN, OnRbIn)
	ON_BN_CLICKED(IDC_BT_DEFAULT, OnBtDefault)
	ON_NOTIFY(UDN_DELTAPOS, IDC_SPN_ASPECT, OnDeltaposSpnAspect)
	ON_NOTIFY(UDN_DELTAPOS, IDC_SPN_CURVE_CTRL, OnDeltaposSpnCurveCtrl)
	ON_NOTIFY(UDN_DELTAPOS, IDC_SPN_LNE_SPACE, OnDeltaposSpnLneSpace)
	ON_NOTIFY(UDN_DELTAPOS, IDC_SPN_MARGIN_LEFT, OnDeltaposSpnMarginLeft)
	ON_NOTIFY(UDN_DELTAPOS, IDC_SPN_MARGIN_RIGHT, OnDeltaposSpnMarginRight)
	ON_NOTIFY(UDN_DELTAPOS, IDC_SPN_RADIUS, OnDeltaposSpnRadius)
	ON_NOTIFY(UDN_DELTAPOS, IDC_SPN_ROTATION, OnDeltaposSpnRotation)
	ON_NOTIFY(UDN_DELTAPOS, IDC_SPN_X, OnDeltaposSpnX)
	ON_NOTIFY(UDN_DELTAPOS, IDC_SPN_Y, OnDeltaposSpnY)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDlgBaselne message handlers
/////////////////////////////////////////////////////////////////////////////
BOOL CDlgBaselne::OnInitDialog() 
{
	CDialog::OnInitDialog();

	//+++++++++++++++++++++++++++++++++++++ Initial radio button
	// load image
	HINSTANCE hInst = AfxGetApp()->m_hInstance;
	m_rbAuto.SetIcon( (HICON)::LoadImage( hInst,MAKEINTRESOURCE(IDI_TYPE_AUTO), IMAGE_ICON, 16, 16, 0) );
	m_rbBottomUp.SetIcon( (HICON)::LoadImage( hInst,MAKEINTRESOURCE(IDI_TYPE_UP), IMAGE_ICON, 16, 16, 0) );
	m_rbCenter.SetIcon( (HICON)::LoadImage( hInst,MAKEINTRESOURCE(IDI_J_CENTER), IMAGE_ICON, 16, 16, 0) );
	m_rbCircle.SetIcon( (HICON)::LoadImage( hInst,MAKEINTRESOURCE(IDI_BL_CIRCLE), IMAGE_ICON, 16, 16, 0) );
	m_rbCurve.SetIcon( (HICON)::LoadImage( hInst,MAKEINTRESOURCE(IDI_BL_CURVE), IMAGE_ICON, 16, 16, 0) );
	m_rbIn.SetIcon( (HICON)::LoadImage( hInst,MAKEINTRESOURCE(IDI_BL_ALIGN_TOP), IMAGE_ICON, 16, 16, 0) );
	m_rbOut.SetIcon( (HICON)::LoadImage( hInst,MAKEINTRESOURCE(IDI_BL_ALIGN_BOT), IMAGE_ICON, 16, 16, 0) );
	m_rbJustify.SetIcon( (HICON)::LoadImage( hInst,MAKEINTRESOURCE(IDI_J_JUSTIFY), IMAGE_ICON, 16, 16, 0) );
	m_rbLeft.SetIcon( (HICON)::LoadImage( hInst,MAKEINTRESOURCE(IDI_J_LEFT), IMAGE_ICON, 16, 16, 0) );
	m_rbLine.SetIcon( (HICON)::LoadImage( hInst,MAKEINTRESOURCE(IDI_BL_DEFAULT), IMAGE_ICON, 16, 16, 0) );
	m_rbRight.SetIcon( (HICON)::LoadImage( hInst,MAKEINTRESOURCE(IDI_J_RIGHT), IMAGE_ICON, 16, 16, 0) );
	m_rbTopDown.SetIcon( (HICON)::LoadImage( hInst,MAKEINTRESOURCE(IDI_TYPE_DOWN), IMAGE_ICON, 16, 16, 0) );
	m_rbTopRight.SetIcon( (HICON)::LoadImage( hInst,MAKEINTRESOURCE(IDI_TYPE_TO_RIGHT), IMAGE_ICON, 16, 16, 0) );

	// Read value from core, then set value
	CheckRadioButton( IDC_RB_LINE, IDC_RB_CIRCLE,   IDC_RB_LINE );
	DisableBaselineCircleGroup();	// assume line select
	DisableBaselineCurveGroup();	// assume line select
	CheckRadioButton( IDC_RB_LEFT, IDC_RB_JUSTIFY,  IDC_RB_LEFT );
	CheckRadioButton( IDC_RB_AUTO, IDC_RB_TOP_DOWN, IDC_RB_AUTO );

	//+++++++++++++++++++++++++++++++++++++ Initial spin control
	CSpinButtonCtrl* pSpin = (CSpinButtonCtrl*)GetDlgItem( IDC_SPN_X );
	pSpin->SetRange32( -100, 99999 );
	//save for ref.	pSpin->SetPos((int) (m_dSpin * 10.0));
	pSpin = (CSpinButtonCtrl*)GetDlgItem( IDC_SPN_Y );
	pSpin->SetRange32( -100, 99999 );
	pSpin = (CSpinButtonCtrl*)GetDlgItem( IDC_SPN_ROTATION );
	pSpin->SetRange( 0, 359 );
	pSpin = (CSpinButtonCtrl*)GetDlgItem( IDC_SPN_LNE_SPACE );
	pSpin->SetRange( -200, 200 );
	pSpin = (CSpinButtonCtrl*)GetDlgItem( IDC_SPN_MARGIN_LEFT );
	pSpin->SetRange( -10, 90 );
	pSpin = (CSpinButtonCtrl*)GetDlgItem( IDC_SPN_MARGIN_RIGHT );
	pSpin->SetRange( 10, 300 );
	pSpin = (CSpinButtonCtrl*)GetDlgItem( IDC_SPN_CURVE_CTRL );
	pSpin->SetRange( 4, 20 );
	pSpin = (CSpinButtonCtrl*)GetDlgItem( IDC_SPN_RADIUS );
	pSpin->SetRange( 5, 100 );
	pSpin = (CSpinButtonCtrl*)GetDlgItem( IDC_SPN_ASPECT );
	pSpin->SetRange( 0, 10 );

	// +++++++++++++++++++++++++++++++++++++++++++++++ Initial Edit control
	CEdit* pEdCtrl = (CEdit*)GetDlgItem( IDC_ED_X );
	pEdCtrl->SetLimitText( 7 ); // 5 characters of -100 .. 99999.00
//	SetDlgItemInt(IDC_ED_X, (int)CGS_GetValDbl(EDIT_WORD_WRAP_MODE), 0 );
	pEdCtrl = (CEdit*)GetDlgItem( IDC_ED_Y );
	pEdCtrl->SetLimitText( 7 ); // 5 characters of -100 .. 99999.00
//	SetDlgItemInt(IDC_ED_Y, (int)CGS_GetValDbl( ID ), 0 );
	pEdCtrl = (CEdit*)GetDlgItem( IDC_ED_ROTATION );
	pEdCtrl->SetLimitText( 5 ); // 5 characters of 0 .. 359.0
//	SetDlgItemInt(IDC_ED_ROTATION, (int)CGS_GetValDbl(EDIT_WORD_WRAP_MODE), 0 );
	pEdCtrl = (CEdit*)GetDlgItem( IDC_ED_LNE_SPACE );
	pEdCtrl->SetLimitText( 6 ); // 6 characters of -200.5 .. 200
//	SetDlgItemInt(IDC_ED_LNE_SPACE, (int)CGS_GetValDbl(EDIT_WORD_WRAP_MODE), 0 );
	pEdCtrl = (CEdit*)GetDlgItem( IDC_ED_MARGIN_LEFT );
	pEdCtrl->SetLimitText( 5 ); // 5 characters of -10.0 .. 90.0
//	SetDlgItemInt(IDC_ED_MARGIN_LEFT, (int)CGS_GetValDbl(EDIT_WORD_WRAP_MODE), 0 );
	pEdCtrl = (CEdit*)GetDlgItem( IDC_ED_MARGIN_RIGHT );
	pEdCtrl->SetLimitText( 5 ); // 5 characters of -10.0 .. 90.0
//	SetDlgItemInt(IDC_ED_MARGIN_RIGHT, (int)CGS_GetValDbl(EDIT_WORD_WRAP_MODE), 0 );
	pEdCtrl = (CEdit*)GetDlgItem( IDC_ED_CURVE_CTRL );
	pEdCtrl->SetLimitText( 4 ); // 4 characters of 4.0 .. 20.0
//	SetDlgItemInt(IDC_ED_CURVE_CTRL, (int)CGS_GetValDbl(EDIT_WORD_WRAP_MODE), 0 );
	pEdCtrl = (CEdit*)GetDlgItem( IDC_ED_CIR_RADIUS );
	pEdCtrl->SetLimitText( 5 ); // 5 characters of 5 .. 100.0
//	SetDlgItemInt(IDC_ED_CIR_RADIUS, (int)CGS_GetValDbl(EDIT_WORD_WRAP_MODE), 0 );
	pEdCtrl = (CEdit*)GetDlgItem( IDC_ED_CIR_ASPECT );
	pEdCtrl->SetLimitText( 4 ); // 4 characters of 0.1 .. 10.0
//	SetDlgItemInt(IDC_ED_CIR_ASPECT, (int)CGS_GetValDbl(EDIT_WORD_WRAP_MODE), 0 );	

	// Create the ToolTip control.
	m_tooltip.Create(this);
	m_tooltip.Activate(TRUE);

	InitDlgItemTextNTooltip();  // seting both tooltip and dialog item text
	ControlOption();			// set control option - hide or show

	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}//end of CDlgBaselne::OnInitDialog() 
/////////////////////////////////////////////////////////////////////////////
// On the radio button line was clicked.
void CDlgBaselne::OnRbLine() 
{
	DisableBaselineCircleGroup();
	DisableBaselineCurveGroup();

	AfxGetMainWnd()->SetFocus();
}//end of CDlgBaselne::OnRbLine()
/////////////////////////////////////////////////////////////////////////////
void CDlgBaselne::OnRbCurve() 
{
	EnableBaselineCurveGroup();
	DisableBaselineCircleGroup();

	AfxGetMainWnd()->SetFocus();	
}//end of CDlgBaselne::OnRbCurve() 
/////////////////////////////////////////////////////////////////////////////
void CDlgBaselne::OnRbCircle() 
{
	EnableBaselineCircleGroup();
	DisableBaselineCurveGroup();

	AfxGetMainWnd()->SetFocus();
}//end of CDlgBaselne::OnRbCircle
/////////////////////////////////////////////////////////////////////////////
void CDlgBaselne::OnRbLeft() 
{
	CGS_Action(CGSA_LINE_JUSTIFY_LEFT);
	AfxGetMainWnd()->SetFocus();
}//end of CDlgBaselne::OnRbLeft
/////////////////////////////////////////////////////////////////////////////
void CDlgBaselne::OnRbCenter() 
{
	CGS_Action(CGSA_LINE_JUSTIFY_CENTER);
	AfxGetMainWnd()->SetFocus();
}//end of CDlgBaselne::OnRbCenter
/////////////////////////////////////////////////////////////////////////////
void CDlgBaselne::OnRbRight() 
{
	CGS_Action(CGSA_LINE_JUSTIFY_RIGHT);
	AfxGetMainWnd()->SetFocus();
}//end of CDlgBaselne::OnRbRight
/////////////////////////////////////////////////////////////////////////////
void CDlgBaselne::OnRbJustify() 
{
	CGS_Action(CGSA_LINE_JUSTIFY_FLUSH);
	AfxGetMainWnd()->SetFocus();
}//end of CDlgBaselne::OnRbJustify
/////////////////////////////////////////////////////////////////////////////
void CDlgBaselne::OnRbAuto() 
{
	AfxGetMainWnd()->SetFocus();
}//end of CDlgBaselne::OnRbAuto
/////////////////////////////////////////////////////////////////////////////
void CDlgBaselne::OnRbTopRight() 
{
	AfxGetMainWnd()->SetFocus();
}//end of CDlgBaselne::OnRbTopRight
/////////////////////////////////////////////////////////////////////////////
void CDlgBaselne::OnRbBottomUp() 
{
	AfxGetMainWnd()->SetFocus();
}//end of CDlgBaselne::OnRbBottomUp
/////////////////////////////////////////////////////////////////////////////
void CDlgBaselne::OnRbTopDown() 
{
	AfxGetMainWnd()->SetFocus();
}//end of CDlgBaselne::OnRbTopDown
/////////////////////////////////////////////////////////////////////////////
void CDlgBaselne::OnBtCharPlus() 
{
	AfxGetMainWnd()->SetFocus();
}//end of CDlgBaselne::OnBtCharPlus
/////////////////////////////////////////////////////////////////////////////
void CDlgBaselne::OnBtCharMinus() 
{
	AfxGetMainWnd()->SetFocus();
}//end of CDlgBaselne::OnBtCharMinus
/////////////////////////////////////////////////////////////////////////////
void CDlgBaselne::OnRbOut() 
{
	AfxGetMainWnd()->SetFocus();
}//end of CDlgBaselne::OnRbOut
/////////////////////////////////////////////////////////////////////////////
void CDlgBaselne::OnRbIn() 
{
	AfxGetMainWnd()->SetFocus();
}//end of CDlgBaselne::OnRbIn
/////////////////////////////////////////////////////////////////////////////
void CDlgBaselne::OnBtDefault() 
{
	AfxGetMainWnd()->SetFocus();
}//end of CDlgBaselne::OnBtDefault
/////////////////////////////////////////////////////////////////////////////
// When the spin control on Aspect edit box was changed.
void CDlgBaselne::OnDeltaposSpnAspect(NMHDR* pNMHDR, LRESULT* pResult) 
{
	NM_UPDOWN* pNMUpDown = (NM_UPDOWN*)pNMHDR;

	char	buf[MAX_PATH];
	m_edCirAspect.GetLine( 0, (LPTSTR)buf, MAX_PATH );	// get edit control value

	// Convert the control value + the increment
	double val = atof( buf ) + (double)pNMUpDown->iDelta/10.0;
//	CGS_GetSpinControlNextValue( PAGE_TOP_MARGIN, pNMUpDown->iDelta, &val );

	val = val < 10.00 ? val : 10; // range checking
	val = val < 0.1   ? 0.1 : val;

	// Conver the double value to string for display
	DoubleToAlphaString( val, 1, (LPTSTR)buf );	// 1 means one digit after decimal point
	char* pSubStr = strstr( buf, ".0" );		// strip the floating part if 25.0
	if( pSubStr != NULL )						// ie: display 25 only
		*pSubStr = '\0';
	m_edCirAspect.SetWindowText( (LPTSTR)buf );
	
	*pResult = 0;

	AfxGetMainWnd()->SetFocus();
}//end of CDlgBaselne::OnDeltaposSpnAspect
/////////////////////////////////////////////////////////////////////////////
// When the spin control on Curve control edit box was changed.
void CDlgBaselne::OnDeltaposSpnCurveCtrl(NMHDR* pNMHDR, LRESULT* pResult) 
{
	NM_UPDOWN* pNMUpDown = (NM_UPDOWN*)pNMHDR;

	char	buf[MAX_PATH];
	m_edCurvCtrl.GetLine( 0, (LPTSTR)buf, MAX_PATH );		// get edit control value

	// Convert the control value + the increment
	double val = atof( buf ) + pNMUpDown->iDelta;
//	CGS_GetSpinControlNextValue( PAGE_TOP_MARGIN, pNMUpDown->iDelta, &val );

	val = val < 20 ? val : 20; // range checking
	val = val < 4  ? 4   : val;

	// Conver the double value to string for display
	DoubleToAlphaString( val, 1, (LPTSTR)buf );	// 1 means one digit after decimal point
	char* pSubStr = strstr( buf, ".0" );		// strip the floating part if 25.0
	if( pSubStr != NULL )						// ie: display 25 only
		*pSubStr = '\0';
	m_edCurvCtrl.SetWindowText( (LPTSTR)buf );	
	*pResult = 0;

	AfxGetMainWnd()->SetFocus();
}//end of CDlgBaselne::OnDeltaposSpnCurveCtrl
/////////////////////////////////////////////////////////////////////////////
void CDlgBaselne::OnDeltaposSpnLneSpace(NMHDR* pNMHDR, LRESULT* pResult) 
{
	NM_UPDOWN* pNMUpDown = (NM_UPDOWN*)pNMHDR;

	char	buf[MAX_PATH];
	m_edLneSpace.GetLine( 0, (LPTSTR)buf, MAX_PATH );

	double val = atof( buf ) + pNMUpDown->iDelta;
//	CGS_GetSpinControlNextValue( PAGE_TOP_MARGIN, pNMUpDown->iDelta, &val );

	val = val <  200 ? val  : 200; // range checking
	val = val < -200 ? -200 : val;

	DoubleToAlphaString( val, 1, (LPTSTR)buf );
	char* pSubStr = strstr( buf, ".0" );
	if( pSubStr != NULL )
		*pSubStr = '\0';
	m_edLneSpace.SetWindowText( (LPTSTR)buf );	
	*pResult = 0;

	AfxGetMainWnd()->SetFocus();
}//end of CDlgBaselne::OnDeltaposSpnLneSpace
/////////////////////////////////////////////////////////////////////////////
void CDlgBaselne::OnDeltaposSpnMarginLeft(NMHDR* pNMHDR, LRESULT* pResult) 
{
	NM_UPDOWN* pNMUpDown = (NM_UPDOWN*)pNMHDR;
	
	char	buf[MAX_PATH];
	m_edMarginLeft.GetLine( 0, (LPTSTR)buf, MAX_PATH );

	double val = atof( buf ) + pNMUpDown->iDelta;
//	CGS_GetSpinControlNextValue( PAGE_TOP_MARGIN, pNMUpDown->iDelta, &val );

	val = val <  90 ? val : 90; // range checking
	val = val < -10 ? -10 : val;

	DoubleToAlphaString( val, 1, (LPTSTR)buf );
	char* pSubStr = strstr( buf, ".0" );
	if( pSubStr != NULL )
		*pSubStr = '\0';
	m_edMarginLeft.SetWindowText( (LPTSTR)buf );	
	
	*pResult = 0;

	AfxGetMainWnd()->SetFocus();
}//end of CDlgBaselne::OnDeltaposSpnMarginLeft
/////////////////////////////////////////////////////////////////////////////
void CDlgBaselne::OnDeltaposSpnMarginRight(NMHDR* pNMHDR, LRESULT* pResult) 
{
	NM_UPDOWN* pNMUpDown = (NM_UPDOWN*)pNMHDR;
	
	char	buf[MAX_PATH];
	m_edMarginRight.GetLine( 0, (LPTSTR)buf, MAX_PATH );

	double val = atof( buf ) + pNMUpDown->iDelta;
//	CGS_GetSpinControlNextValue( PAGE_TOP_MARGIN, pNMUpDown->iDelta, &val );

	val = val < 300 ? val : 300; // range checking
	val = val < 10  ? 10  : val;

	DoubleToAlphaString( val, 1, (LPTSTR)buf );
	char* pSubStr = strstr( buf, ".0" );
	if( pSubStr != NULL )
		*pSubStr = '\0';
	m_edMarginRight.SetWindowText( (LPTSTR)buf );	
	
	*pResult = 0;

	AfxGetMainWnd()->SetFocus();
}//end of CDlgBaselne::OnDeltaposSpnMarginRight
/////////////////////////////////////////////////////////////////////////////
void CDlgBaselne::OnDeltaposSpnRadius(NMHDR* pNMHDR, LRESULT* pResult) 
{
	NM_UPDOWN* pNMUpDown = (NM_UPDOWN*)pNMHDR;
	
	char	buf[MAX_PATH];
	m_edCirRadius.GetLine( 0, (LPTSTR)buf, MAX_PATH );

	double val = atof( buf ) + pNMUpDown->iDelta;
//	CGS_GetSpinControlNextValue( PAGE_TOP_MARGIN, pNMUpDown->iDelta, &val );

	val = val < 100 ? val : 100; // range checking
	val = val < 5   ? 5   : val;

	DoubleToAlphaString( val, 1, (LPTSTR)buf );
	char* pSubStr = strstr( buf, ".0" );
	if( pSubStr != NULL )
		*pSubStr = '\0';
	m_edCirRadius.SetWindowText( (LPTSTR)buf );
	
	*pResult = 0;

	AfxGetMainWnd()->SetFocus();
}//end of CDlgBaselne::OnDeltaposSpnRadius
/////////////////////////////////////////////////////////////////////////////
void CDlgBaselne::OnDeltaposSpnRotation(NMHDR* pNMHDR, LRESULT* pResult) 
{
	NM_UPDOWN* pNMUpDown = (NM_UPDOWN*)pNMHDR;
	
	char	buf[MAX_PATH];
	m_edRotation.GetLine( 0, (LPTSTR)buf, MAX_PATH );

	double val = atof( buf ) + pNMUpDown->iDelta;
//	CGS_GetSpinControlNextValue( PAGE_TOP_MARGIN, pNMUpDown->iDelta, &val );

	val = val < 359 ? val : 359; // range checking
	val = val < 0   ? 0   : val;

	DoubleToAlphaString( val, 1, (LPTSTR)buf );
	char* pSubStr = strstr( buf, ".0" );
	if( pSubStr != NULL )
		*pSubStr = '\0';
	m_edRotation.SetWindowText( (LPTSTR)buf );
	
	*pResult = 0;

	AfxGetMainWnd()->SetFocus();
}//end of CDlgBaselne::OnDeltaposSpnRotation
/////////////////////////////////////////////////////////////////////////////
void CDlgBaselne::OnDeltaposSpnX(NMHDR* pNMHDR, LRESULT* pResult) 
{
	NM_UPDOWN* pNMUpDown = (NM_UPDOWN*)pNMHDR;
	char	buf[MAX_PATH];
	m_edX.GetLine( 0, (LPTSTR)buf, MAX_PATH );	// get edit control value

	// Convert the control value + the increment
	double val = atof( buf ) + (double)pNMUpDown->iDelta;
//	CGS_GetSpinControlNextValue( PAGE_TOP_MARGIN, pNMUpDown->iDelta, &val );

	val = val < 99999 ? val : 99999; // range checking
	val = val < -500   ? -500 : val;

	// Conver the double value to string for display
	DoubleToAlphaString( val, 1, (LPTSTR)buf );	// 1 means one digit after decimal point
	char* pSubStr = strstr( buf, ".0" );		// strip the floating part if 25.0
	if( pSubStr != NULL )						// ie: display 25 only
		*pSubStr = '\0';
	m_edX.SetWindowText( (LPTSTR)buf );
	
	*pResult = 0;

	AfxGetMainWnd()->SetFocus();
}//end of CDlgBaselne::OnDeltaposSpnX
/////////////////////////////////////////////////////////////////////////////
void CDlgBaselne::OnDeltaposSpnY(NMHDR* pNMHDR, LRESULT* pResult) 
{
	NM_UPDOWN* pNMUpDown = (NM_UPDOWN*)pNMHDR;
	char	buf[MAX_PATH];
	m_edY.GetLine( 0, (LPTSTR)buf, MAX_PATH );	// get edit control value

	// Convert the control value + the increment
	double val = atof( buf ) + (double)pNMUpDown->iDelta;
//	CGS_GetSpinControlNextValue( PAGE_TOP_MARGIN, pNMUpDown->iDelta, &val );

	val = val < 99999 ? val : 99999; // range checking
	val = val < -500   ? -500 : val;

	// Conver the double value to string for display
	DoubleToAlphaString( val, 1, (LPTSTR)buf );	// 1 means one digit after decimal point
	char* pSubStr = strstr( buf, ".0" );		// strip the floating part if 25.0
	if( pSubStr != NULL )						// ie: display 25 only
		*pSubStr = '\0';
	m_edY.SetWindowText( (LPTSTR)buf );
	
	*pResult = 0;

	AfxGetMainWnd()->SetFocus();
}//end of CDlgBaselne::OnDeltaposSpnY
/////////////////////////////////////////////////////////////////////////////
VOID CDlgBaselne::EnableBaselineCurveGroup()
{
	m_gpCurvCtrl.EnableWindow( 1 );
	m_stcCurvPoint.EnableWindow( 1 );
	m_edCurvCtrl.EnableWindow( 1 );
	m_spnCurvCtrl.EnableWindow( 1 );
}//end of CDlgBaselne::EnableBaselineCurveGroup()
/////////////////////////////////////////////////////////////////////////////
VOID CDlgBaselne::DisableBaselineCurveGroup()
{
	m_gpCurvCtrl.EnableWindow( 0 );
	m_stcCurvPoint.EnableWindow( 0 );
	m_edCurvCtrl.EnableWindow( 0 );	
	m_spnCurvCtrl.EnableWindow( 0 );
}//end of CDlgBaselne::DisableBaselineCurveGroup()
/////////////////////////////////////////////////////////////////////////////
VOID CDlgBaselne::EnableBaselineCircleGroup()
{
	m_gpCirCtrl.EnableWindow( 1 );
	m_stcAlignCir.EnableWindow( 1 );
	m_stcCirAspect.EnableWindow( 1 );
	m_stcCirRadius.EnableWindow( 1 );
	m_spnCirAspect.EnableWindow( 1 );
	m_spnCirRadius.EnableWindow( 1 );
	m_edCirRadius.EnableWindow( 1 );
	m_edCirAspect.EnableWindow( 1 );
	m_rbIn.EnableWindow( 1 );
	m_rbOut.EnableWindow( 1 );
}//end of CDlgBaselne::EnableBaselineCircleGroup()
/////////////////////////////////////////////////////////////////////////////
VOID CDlgBaselne::DisableBaselineCircleGroup()
{
	m_gpCirCtrl.EnableWindow( 0 );
	m_stcAlignCir.EnableWindow( 0 );
	m_stcCirAspect.EnableWindow( 0 );
	m_stcCirRadius.EnableWindow( 0 );
	m_spnCirAspect.EnableWindow( 0 );
	m_spnCirRadius.EnableWindow( 0 );
	m_edCirRadius.EnableWindow( 0 );
	m_edCirAspect.EnableWindow( 0 );
	m_rbIn.EnableWindow( 0 );
	m_rbOut.EnableWindow( 0 );
}//end of CDlgBaselne::DisableBaselineCircleGroup()
/////////////////////////////////////////////////////////////////////////////
void CDlgBaselne::OnCancel() 
{
	// capture cancel message
}//end of OnCancel
/////////////////////////////////////////////////////////////////////////////
void CDlgBaselne::OnOK() 
{
#ifndef _UNICODE
	TCHAR	buf[MAX_PATH];
	double  edValue;

	long edLong = GetDlgItemInt( IDC_ED_X, NULL, 0 );
	if( edLong != m_edlX )
	{
		m_edlX = edLong;
		TRACE(_T("\t m_edlX = %d\n"), m_edlX );
		// TO DO :set core value
	}

	edLong = GetDlgItemInt( IDC_ED_Y, NULL, 0 );
	if( edLong != m_edlY )
	{
		m_edlY = edLong;
		TRACE(_T("\t m_edlY = %d\n"), m_edlY );
		// TO DO :set core value
	}
	
	m_edRotation.GetLine( 0, (LPTSTR)buf, MAX_PATH );
	edValue = atof( buf );
	if( edValue != m_dbRotate )
	{
		m_dbRotate = edValue;
		// TO DO : Set core
	}

	m_edLneSpace.GetLine( 0, (LPTSTR)buf, MAX_PATH );
	edValue = atof( buf );
	if( edValue != m_dbLineSpace )
	{
		m_dbLineSpace = edValue;
		// TO DO : set core
	}

	m_edMarginLeft.GetLine( 0, (LPTSTR)buf, MAX_PATH );
	edValue = atof( buf );
	if( edValue != m_dbLeftMargin )
	{
		m_dbLeftMargin = edValue;
		// TO DO : Set core
	}

	m_edMarginRight.GetLine( 0, (LPTSTR)buf, MAX_PATH );
	edValue = atof( buf );
	if( edValue != m_dbRightMargin )
	{
		m_dbRightMargin = edValue;
		// TO DO : Set Core
	}

	m_edCurvCtrl.GetLine( 0, (LPTSTR)buf, MAX_PATH );
	edValue = atof( buf );
	if( edValue != m_dbCurvCtrl )
	{
		m_dbCurvCtrl = edValue;
		// TO DO : Set Core
	}

	m_edCirRadius.GetLine( 0, (LPTSTR)buf, MAX_PATH );
	edValue = atof( buf );
	if( edValue != m_dbCirRadius )
	{
		m_dbCirRadius = edValue;
		// TO DO : Set Core
	}

	m_edCirAspect.GetLine( 0, (LPTSTR)buf, MAX_PATH );
	edValue = atof( buf );
	if( edValue != m_dbCirAspect )
	{
		m_dbCirAspect = edValue;
		// TO DO : Set core
	}
#endif
	AfxGetMainWnd()->SetFocus();

}//end of OnOK
/////////////////////////////////////////////////////////////////////////////////
VOID CDlgBaselne::DoValueUpdate()
{
	MessageBox( _T("Do the update"), _T("ketnest"), MB_OK );
}//end of CDlgBaselne::DoValueUpdate()
/////////////////////////////////////////////////////////////////////////////////
BOOL CDlgBaselne::PreTranslateMessage(MSG* pMsg)
{
	// CG: The following block was added by the ToolTips component.
	{
		// Let the ToolTip process this message.
		m_tooltip.RelayEvent(pMsg);
	}
	return CDialog::PreTranslateMessage(pMsg);	// CG: This was added by the ToolTips component.
}// end of CDlgBaselne::PreTranslateMessage(MSG* pMsg)
/////////////////////////////////////////////////////////////////////////////////
VOID CDlgBaselne::InitDlgItemTextNTooltip()
{
	IN_TEXT_DATA* txtData = NULL;
	TCHAR	sep[] = _T("\"");
	TCHAR*	ptID;
	TCHAR*	ptTT;
	TCHAR*	ptEnd;

	m_numTxt = LoadTextFromCtl( "\\Util\\DlgBaseline.ctl", "[Tooltip]", &txtData );
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
		if( NULL != _tcsstr( txtData[i].szTT, _T("IDC_RB_LINE") ) )
			txtData[i].idTT = IDC_RB_LINE;
		else
			if( NULL != _tcsstr( txtData[i].szTT, _T("IDC_RB_CURVE") ) )
				txtData[i].idTT = IDC_RB_CURVE;
		else
			if( NULL != _tcsstr( txtData[i].szTT, _T("IDC_STC_CIR_RADIUS") ) )
				txtData[i].idTT = IDC_STC_CIR_RADIUS;
		else
			if( NULL != _tcsstr( txtData[i].szTT, _T("IDC_STC_CIR_ASPECT") ) )
				txtData[i].idTT = IDC_STC_CIR_ASPECT;
		else
			if( NULL != _tcsstr( txtData[i].szTT, _T("IDC_RB_CIRCLE") ) )
				txtData[i].idTT = IDC_RB_CIRCLE;
		else
			if( NULL != _tcsstr( txtData[i].szTT, _T("IDC_RB_LEFT") ) )
				txtData[i].idTT = IDC_RB_LEFT;
		else
			if( NULL != _tcsstr( txtData[i].szTT, _T("IDC_RB_CENTER") ) )
				txtData[i].idTT = IDC_RB_CENTER;
		else
			if( NULL != _tcsstr( txtData[i].szTT, _T("IDC_RB_RIGHT") ) )
				txtData[i].idTT = IDC_RB_RIGHT;
		else
			if( NULL != _tcsstr( txtData[i].szTT, _T("IDC_RB_JUSTIFY") ) )
				txtData[i].idTT = IDC_RB_JUSTIFY;
		else
			if( NULL != _tcsstr( txtData[i].szTT, _T("IDC_RB_AUTO") ) )
				txtData[i].idTT = IDC_RB_AUTO;
		else
			if( NULL != _tcsstr( txtData[i].szTT, _T("IDC_RB_TOP_RIGHT") ) )
				txtData[i].idTT = IDC_RB_TOP_RIGHT;
		else
			if( NULL != _tcsstr( txtData[i].szTT, _T("IDC_RB_BOTTOM_UP") ) )
				txtData[i].idTT = IDC_RB_BOTTOM_UP;
		else
			if( NULL != _tcsstr( txtData[i].szTT, _T("IDC_RB_TOP_DOWN") ) )
				txtData[i].idTT = IDC_RB_TOP_DOWN;
		else
			if( NULL != _tcsstr( txtData[i].szTT, _T("IDC_RB_OUT") ) )
				txtData[i].idTT = IDC_RB_OUT;
		else
			if( NULL != _tcsstr( txtData[i].szTT, _T("IDC_RB_IN") ) )
				txtData[i].idTT = IDC_RB_IN;
		else
			if( NULL != _tcsstr( txtData[i].szTT, _T("IDC_BT_DEFAULT") ) )
				txtData[i].idTT = IDC_BT_DEFAULT;
		else
			if( NULL != _tcsstr( txtData[i].szTT, _T("IDC_GP_BASELINE") ) )
				txtData[i].idTT = IDC_GP_BASELINE;
		else
			if( NULL != _tcsstr( txtData[i].szTT, _T("IDC_GP_JUSTIFIY") ) )
				txtData[i].idTT = IDC_GP_JUSTIFIY;
		else
			if( NULL != _tcsstr( txtData[i].szTT, _T("IDC_GP_TYPING_DIR") ) )
				txtData[i].idTT = IDC_GP_TYPING_DIR;
		else
			if( NULL != _tcsstr( txtData[i].szTT, _T("IDC_GP_LINE_MARGIN") ) )
				txtData[i].idTT = IDC_GP_LINE_MARGIN;
		else
			if( NULL != _tcsstr( txtData[i].szTT, _T("IDC_STC_ALIGN_CIR") ) )
				txtData[i].idTT = IDC_STC_ALIGN_CIR;
		else
			if( NULL != _tcsstr( txtData[i].szTT, _T("IDC_GP_CURVE_CTRL") ) )
				txtData[i].idTT = IDC_GP_CURVE_CTRL;
		else
			if( NULL != _tcsstr( txtData[i].szTT, _T("IDC_GP_CIRCLE_CTRL") ) )
				txtData[i].idTT = IDC_GP_CIRCLE_CTRL;
		else
			if( NULL != _tcsstr( txtData[i].szTT, _T("IDC_STC_POSITION") ) )
				txtData[i].idTT = IDC_STC_POSITION;
		else
			if( NULL != _tcsstr( txtData[i].szTT, _T("IDC_CK_LOCK_POS") ) )
				txtData[i].idTT = IDC_CK_LOCK_POS;
		else
			if( NULL != _tcsstr( txtData[i].szTT, _T("IDC_STC_ROTATION") ) )
				txtData[i].idTT = IDC_STC_ROTATION;
		else
			if( NULL != _tcsstr( txtData[i].szTT, _T("IDC_STC_LINE_SPACE") ) )
				txtData[i].idTT = IDC_STC_LINE_SPACE;
		else
			if( NULL != _tcsstr( txtData[i].szTT, _T("IDC_STC_CHAR_SPACE") ) )
				txtData[i].idTT = IDC_STC_CHAR_SPACE;
		else
			if( NULL != _tcsstr( txtData[i].szTT, _T("IDC_STC_MARGIN_LEFT") ) )
				txtData[i].idTT = IDC_STC_MARGIN_LEFT;
		else
			if( NULL != _tcsstr( txtData[i].szTT, _T("IDC_STC_MARGIN_RIGHT") ) )
				txtData[i].idTT = IDC_STC_MARGIN_RIGHT;
		else
			if( NULL != _tcsstr( txtData[i].szTT, _T("IDC_CHK_CONSTRAIN") ) )
				txtData[i].idTT = IDC_CHK_CONSTRAIN;
		else
			if( NULL != _tcsstr( txtData[i].szTT, _T("IDC_STC_CURVE_POINT") ) )
				txtData[i].idTT = IDC_STC_CURVE_POINT;
		else
			if( NULL != _tcsstr( txtData[i].szTT, _T("IDC_ED_X") ) )
			{
				txtData[i].idTT = IDC_ED_X;
				goto SKIP_TEXT;
			}
		else
			if( NULL != _tcsstr( txtData[i].szTT, _T("IDC_ED_Y") ) )
			{
				txtData[i].idTT = IDC_ED_Y;
				goto SKIP_TEXT;
			}
		else
			if( NULL != _tcsstr( txtData[i].szTT, _T("IDC_ED_ROTATION") ) )
			{
				txtData[i].idTT = IDC_ED_ROTATION;
				goto SKIP_TEXT;
			}
		else
			if( NULL != _tcsstr( txtData[i].szTT, _T("IDC_ED_LNE_SPACE") ) )
			{
				txtData[i].idTT = IDC_ED_LNE_SPACE;
				goto SKIP_TEXT;
			}
		else
			if( NULL != _tcsstr( txtData[i].szTT, _T("IDC_ED_MARGIN_LEFT") ) )
			{
				txtData[i].idTT = IDC_ED_MARGIN_LEFT;
				goto SKIP_TEXT;
			}
		else
			if( NULL != _tcsstr( txtData[i].szTT, _T("IDC_ED_MARGIN_RIGHT") ) )
			{
				txtData[i].idTT = IDC_ED_MARGIN_RIGHT;
				goto SKIP_TEXT;
			}
		else
			if( NULL != _tcsstr( txtData[i].szTT, _T("IDC_ED_CURVE_CTRL") ) )
			{
				txtData[i].idTT = IDC_ED_CURVE_CTRL;
				goto SKIP_TEXT;
			}
		else
			if( NULL != _tcsstr( txtData[i].szTT, _T("IDC_ED_CIR_RADIUS") ) )
			{
				txtData[i].idTT = IDC_ED_CIR_RADIUS;
				goto SKIP_TEXT;
			}
		else
			if( NULL != _tcsstr( txtData[i].szTT, _T("IDC_ED_CIR_ASPECT") ) )
			{
				txtData[i].idTT = IDC_ED_CIR_ASPECT;
				goto SKIP_TEXT;
			}

		SetDlgItemText( txtData[i].idTT, (LPCTSTR)ptTT );
		m_hFont[i] = ChangeControlFont( GetDlgItem(txtData[i].idTT)->m_hWnd, /*hFont*/NULL, UILang_UIFont,0, UILang_UIFontSize, FW_NORMAL);
SKIP_TEXT:
		_tcscpy( txtData[i].szTT, (TCHAR*)txtData[i].szTT );
		if( NULL != GetDlgItem(txtData[i].idTT) )
			m_tooltip.AddTool( GetDlgItem(txtData[i].idTT), (_TCHAR*)ptTT);
	}//end of for

	free( txtData );
}//end of CDlgBaselne::InitDlgItemTextNTooltip()
//////////////////////////////////////////////////////////////////////////////////////////////
VOID CDlgBaselne::ControlOption()
{
	if( HIDE_BASE_LINE ) // define the option flag here
	{
		m_gpCurvCtrl.ShowWindow( SW_HIDE );
		m_stcCurvPoint.ShowWindow( SW_HIDE );
		m_spnCurvCtrl.ShowWindow( SW_HIDE );
		m_edCurvCtrl.ShowWindow( SW_HIDE );

		m_gpCirCtrl.ShowWindow( SW_HIDE );
		m_stcCirRadius.ShowWindow( SW_HIDE );
		m_stcCirAspect.ShowWindow( SW_HIDE );
		m_stcAlignCir.ShowWindow( SW_HIDE );
		m_edCirRadius.ShowWindow( SW_HIDE );
		m_spnCirRadius.ShowWindow( SW_HIDE );
		m_edCirAspect.ShowWindow( SW_HIDE );
		m_spnCirAspect.ShowWindow( SW_HIDE );
		m_rbOut.ShowWindow( SW_HIDE );
		m_rbIn.ShowWindow( SW_HIDE );

		m_rbCircle.ShowWindow( SW_HIDE );
		m_rbCurve.ShowWindow( SW_HIDE );
	}//end of option flag - for Japanese review

}//end of CDlgBaselne::ControlOption()
