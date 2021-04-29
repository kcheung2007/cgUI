/* COPYRIGHT NOTICE:
********************************************************
*  Copyright (c) 2000 InnoVision Technology, Inc.      *
*  All rights reserved.                                *
*  PROPRIETARY AND CONFIDENTIAL                        *
*  DO NOT DISTRIBUTE                                   *
********************************************************
*/
// AttribText.cpp : implementation file
//

#include "stdafx.h"
#include "cgui.h"
#include "AttribText.h"
#include "ACGS_Inc\\CGServerDll.h"
#include "FontLocator.h"
#include "DlgTypeFace.h"
#include "switch.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif


extern TCHAR	UILang_UIFont[256];
extern int		UILang_UIFontSize;

/////////////////////////////////////////////////////////////////////////////
// CAttribText dialog


CAttribText::CAttribText(CWnd* pParent /*=NULL*/) : CDialog(CAttribText::IDD, pParent)
{
	//{{AFX_DATA_INIT(CAttribText)
	m_edBevel    = 0;
	m_edHeight   = 0;
	m_edKern     = 0;
	m_edPriority = 0;
	m_edRotate   = 0;
	m_edSpace    = 0;
	m_edWidth    = 0;
	m_edX		 = 0;
	m_edY		 = 0;
	//}}AFX_DATA_INIT
}

CAttribText::~CAttribText()
{
}

void CAttribText::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CAttribText)
	DDX_Control(pDX, IDC_BT_SAVE_STYLE, m_btSaveStyle);
	DDX_Control(pDX, IDC_ED_T_WIDTH, m_ctlEdWidth);
	DDX_Control(pDX, IDC_ED_T_SPACE, m_ctlEdSpace);
	DDX_Control(pDX, IDC_ED_T_KERNING, m_ctlEdKern);
	DDX_Control(pDX, IDC_ED_T_HEIGHT, m_ctlEdHeight);
	DDX_Control(pDX, IDC_SPN_T_BEVEL, m_spnBevel);
	DDX_Control(pDX, IDC_ED_T_BEVEL, m_ctlEdBevel);
	DDX_Control(pDX, IDC_SPN_T_PRIORITY, m_spnPriority);
	DDX_Control(pDX, IDC_SPN_T_Y, m_spnY);
	DDX_Control(pDX, IDC_SPN_T_X, m_spnX);
	DDX_Control(pDX, IDC_ED_T_PRIORITY, m_ctlEdPriority);
	DDX_Control(pDX, IDC_ED_T_Y, m_ctlEdY);
	DDX_Control(pDX, IDC_ED_T_X, m_ctlEdX);
	DDX_Control(pDX, IDC_SPN_T_ROTATE, m_spnRotate);
	DDX_Control(pDX, IDC_ED_T_ROTATION, m_ctlEdRotate);
	DDX_Control(pDX, IDC_BT_ADVANCE, m_btAdvance);
	DDX_Control(pDX, IDC_BT_FONT_LIST, m_btFontList);
	DDX_Control(pDX, IDC_BT_SUBSCRIPT, m_btSubScript);
	DDX_Control(pDX, IDC_BT_SUPERSCRIPT, m_btSuperScript);
	DDX_Control(pDX, IDC_STC_T_Y, m_stcY);
	DDX_Control(pDX, IDC_STC_T_X, m_stcX);
	DDX_Control(pDX, IDC_STC_T_WIDTH, m_stcWidth);
	DDX_Control(pDX, IDC_STC_T_SPACE, m_stcSpace);
	DDX_Control(pDX, IDC_STC_T_ROTATION, m_stcRotate);
	DDX_Control(pDX, IDC_STC_T_KERNING, m_stcKern);
	DDX_Control(pDX, IDC_STC_T_HEIGHT, m_stcHeight);
	DDX_Control(pDX, IDC_STC_T_BEVEL, m_stcBevel);
	DDX_Control(pDX, IDC_RB_T_UNDERLNE, m_rbUnderLne);
	DDX_Control(pDX, IDC_RB_T_ITALIC, m_rbItalic);
	DDX_Control(pDX, IDC_RB_T_BOLD, m_rbBold);
	DDX_Control(pDX, IDC_RB_T_SMALL_CAP, m_rbSmallCap);
	DDX_Control(pDX, IDC_BT_T_PLUS, m_btPlus);
	DDX_Control(pDX, IDC_BT_T_MINUS, m_btMinus);
	DDX_Control(pDX, IDC_BT_T_LOCK, m_btLock);
	DDX_Control(pDX, IDC_BT_T_F, m_btForeGrd);
	DDX_Control(pDX, IDC_BT_T_B, m_btBackGrd);
	DDX_Text(pDX, IDC_ED_T_BEVEL, m_edBevel);
	DDX_Text(pDX, IDC_ED_T_HEIGHT, m_edHeight);
	DDX_Text(pDX, IDC_ED_T_KERNING, m_edKern);
	DDX_Text(pDX, IDC_ED_T_PRIORITY, m_edPriority);
	DDX_Text(pDX, IDC_ED_T_ROTATION, m_edRotate);
	DDX_Text(pDX, IDC_ED_T_SPACE, m_edSpace);
	DDX_Text(pDX, IDC_ED_T_WIDTH, m_edWidth);
	DDX_Text(pDX, IDC_ED_T_X, m_edX);
	DDX_Text(pDX, IDC_ED_T_Y, m_edY);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CAttribText, CDialog)
	//{{AFX_MSG_MAP(CAttribText)
	ON_BN_CLICKED(IDC_BT_T_B, OnBtTBackGrd)
	ON_BN_CLICKED(IDC_BT_T_F, OnBtTForeGrd)
	ON_BN_CLICKED(IDC_BT_T_LOCK, OnBtTLock)
	ON_BN_CLICKED(IDC_BT_T_MINUS, OnBtTMinus)
	ON_BN_CLICKED(IDC_BT_T_PLUS, OnBtTPlus)
	ON_BN_CLICKED(IDC_RB_T_BOLD, OnRbTBold)
	ON_BN_CLICKED(IDC_RB_T_ITALIC, OnRbTItalic)
	ON_BN_CLICKED(IDC_RB_T_UNDERLNE, OnRbTUnderlne)
	ON_NOTIFY(UDN_DELTAPOS, IDC_SPN_T_BEVEL, OnDeltaposSpnTBevel)
	ON_NOTIFY(UDN_DELTAPOS, IDC_SPN_T_HEIGHT, OnDeltaposSpnTHeight)
	ON_NOTIFY(UDN_DELTAPOS, IDC_SPN_T_KERN, OnDeltaposSpnTKern)
	ON_NOTIFY(UDN_DELTAPOS, IDC_SPN_T_PRIORITY, OnDeltaposSpnTPriority)
	ON_NOTIFY(UDN_DELTAPOS, IDC_SPN_T_ROTATE, OnDeltaposSpnTRotate)
	ON_NOTIFY(UDN_DELTAPOS, IDC_SPN_T_SPACING, OnDeltaposSpnTSpacing)
	ON_NOTIFY(UDN_DELTAPOS, IDC_SPN_T_WIDTH, OnDeltaposSpnTWidth)
	ON_NOTIFY(UDN_DELTAPOS, IDC_SPN_T_X, OnDeltaposSpnTX)
	ON_NOTIFY(UDN_DELTAPOS, IDC_SPN_T_Y, OnDeltaposSpnTY)
	ON_BN_CLICKED(IDC_RB_T_SMALL_CAP, OnRbTSmallCap)
	ON_WM_PAINT()
	ON_EN_CHANGE(IDC_ED_T_SPACE, OnChangeEdTSpace)
	ON_BN_CLICKED(IDC_BT_SUPERSCRIPT, OnSuperscript)
	ON_BN_CLICKED(IDC_BT_SUBSCRIPT, OnSubscript)
	ON_BN_CLICKED(IDC_BT_FONT_LIST, OnBtFontList)
	ON_BN_CLICKED(IDC_BT_ADVANCE, OnBtAdvance)
	ON_BN_CLICKED(IDC_BT_SAVE_STYLE, OnBtSaveStyle)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CAttribText message handlers

void CAttribText::OnOK() 
{
	_TCHAR	buf[MAX_PATH];
	double  edValue;
	DWORD	edVal;

	GetDlgItemText( IDC_ED_T_HEIGHT, buf, MAX_PATH );
	edValue = atof( buf );
	if( edValue != m_edHeight )
	{
		m_edHeight = edValue;
		TRACE(_T("\t m_edHeight = %f\n"), m_edHeight );
		CGS_SetValDbl( EDIT_OBJ_SIZE, (double)m_edHeight );
	}

	GetDlgItemText( IDC_ED_T_SPACE, buf, MAX_PATH );
	edValue = atof( buf );
	if( edValue != m_edSpace )
	{
		m_edSpace = edValue;
		TRACE(_T("\t m_edSpace = %f\n"), m_edSpace );
		CGS_SetValDbl( EDIT_OBJ_CHAR_SPACING, (double)m_edSpace );
	}

	GetDlgItemText( IDC_ED_T_ROTATION, buf, MAX_PATH );
	edValue = atof( buf );
	if( edValue != m_edRotate )
	{
		m_edRotate = edValue;
		TRACE(_T("\t m_edRotate = %f\n"), m_edRotate );
		CGS_SetValDbl( EDIT_OBJ_ROTATION, (double)m_edRotate );
	}
	GetDlgItemText( IDC_ED_T_WIDTH, buf, MAX_PATH );
	edValue = atof( buf );
	if( edValue != m_edWidth )
	{
		m_edWidth = edValue;
		TRACE(_T("\t m_edWidth = %f\n"), m_edWidth );
		CGS_SetValDbl( EDIT_OBJ_WIDTH_PERCENT, (double)m_edWidth );
	}
	GetDlgItemText( IDC_ED_T_KERNING, buf, MAX_PATH );
	edValue = atof( buf );
	if( edValue != m_edKern )
	{
		m_edKern = edValue;
		TRACE(_T("\t m_edKern = %f\n"), m_edKern );
		CGS_SetValDbl( EDIT_OBJ_CHAR_KERNING, (double)m_edKern );
	}

    edVal = GetDlgItemInt( IDC_ED_T_BEVEL, NULL, 0 );
	if( edVal != m_edBevel )
	{
		m_edBevel = edVal;
		TRACE(_T("\t m_edBevel = %d\n"), m_edBevel );
	}
	edVal = GetDlgItemInt( IDC_ED_T_PRIORITY, NULL, 0 );
	if( edVal != m_edPriority )
	{
		m_edPriority = edVal;
		TRACE(_T("\t m_edPriority = %d\n"), m_edPriority );
		CGS_SetValDbl( EDIT_OBJ_PRIORITY, (double)m_edPriority );
	}
	AfxGetMainWnd()->SetFocus();	
}//end of CDialog::OnOK();
/////////////////////////////////////////////////////////////////////////////////////////////////
void CAttribText::OnCancel() 
{
	// capture cancel message
}//end of CDialog::OnCancel();
/////////////////////////////////////////////////////////////////////////////////////////////////
BOOL CAttribText::OnInitDialog() 
{
	CDialog::OnInitDialog();
		
	HWND hCtrl = GetDlgItem( IDC_CB_T_FONT )->m_hWnd;
	
	InitFontCombo();
	InitRadioButtom();
	InitEditSpinControl();
	InitStaticIcon();
	
	ControlOption(); // show or hide some of the control

	// ++++++++++++++++++++++++++++++++++++++++ Create the ToolTip control.
	m_tooltip.Create(this);
	m_tooltip.Activate(TRUE);

	InitDlgItemTextNTooltip(); // seting both tooltip and dialog item text
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}//end of OnInitDialog()
/////////////////////////////////////////////////////////////////////////////////////
BOOL CAttribText::PreTranslateMessage(MSG* pMsg)
{
	m_tooltip.RelayEvent(pMsg);
	return CDialog::PreTranslateMessage(pMsg);	// CG: This was added by the ToolTips component.
}//end of CAttribText::PreTranslateMessage
////////////////////////////////////////////////////////////////////////////////////////////
// There is no static text in this dialog. Therefore, reduce the un-neccessary code for
// increasing perforemance.
VOID CAttribText::InitDlgItemTextNTooltip()
{
	IN_TEXT_DATA* txtData = NULL;
	TCHAR	sep[] = _T("\"");
	TCHAR*	ptID;
	TCHAR*	ptTT;
	TCHAR*	ptEnd;

	DWORD numTxt = LoadTextFromCtl( "\\Util\\DlgText.ctl", "[Tooltip]", &txtData );
	if( numTxt == 0 )
		return;

	for( DWORD i = 0; i < numTxt; i++ )
	{
		ptID   = _tcstok( txtData[i].szTT, sep );
		ptTT   = _tcstok( NULL, sep );
		ptEnd  = _tcstok( NULL, sep );
		if( ptEnd != 0 )
			*ptEnd = '\0';
			
		if( NULL != _tcsstr( txtData[i].szTT, _T("IDC_CB_T_FONT") ) )
			txtData[i].idTT = IDC_CB_T_FONT;
		else
			if( NULL != _tcsstr( txtData[i].szTT, _T("IDC_RB_T_BOLD") ) )
				txtData[i].idTT = IDC_RB_T_BOLD;
		else
			if( NULL != _tcsstr( txtData[i].szTT, _T("IDC_RB_T_ITALIC") ) )
				txtData[i].idTT = IDC_RB_T_ITALIC;
		else
			if( NULL != _tcsstr( txtData[i].szTT, _T("IDC_RB_T_UNDERLNE") ) )
				txtData[i].idTT = IDC_RB_T_UNDERLNE;
		else
			if( NULL != _tcsstr( txtData[i].szTT, _T("IDC_ED_T_PRIORITY") ) )
				txtData[i].idTT = IDC_ED_T_PRIORITY;
		else
			if( NULL != _tcsstr( txtData[i].szTT, _T("IDC_ED_T_BEVEL") ) )
				txtData[i].idTT = IDC_ED_T_BEVEL;
		else
			if( NULL != _tcsstr( txtData[i].szTT, _T("IDC_ED_T_KERNING") ) )
				txtData[i].idTT = IDC_ED_T_KERNING;
		else
			if( NULL != _tcsstr( txtData[i].szTT, _T("IDC_ED_T_WIDTH") ) )
				txtData[i].idTT = IDC_ED_T_WIDTH;
		else
			if( NULL != _tcsstr( txtData[i].szTT, _T("IDC_ED_T_ROTATION") ) )
				txtData[i].idTT = IDC_ED_T_ROTATION;
		else
			if( NULL != _tcsstr( txtData[i].szTT, _T("IDC_ED_T_SPACE") ) )
				txtData[i].idTT = IDC_ED_T_SPACE;
		else
			if( NULL != _tcsstr( txtData[i].szTT, _T("IDC_ED_T_HEIGHT") ) )
				txtData[i].idTT = IDC_ED_T_HEIGHT;
		else
			if( NULL != _tcsstr( txtData[i].szTT, _T("IDC_ED_T_X") ) )
				txtData[i].idTT = IDC_ED_T_X;
		else
			if( NULL != _tcsstr( txtData[i].szTT, _T("IDC_ED_T_Y") ) )
				txtData[i].idTT = IDC_ED_T_Y;
		else
			if( NULL != _tcsstr( txtData[i].szTT, _T("IDC_BT_T_B") ) )
				txtData[i].idTT = IDC_BT_T_B;
		else
			if( NULL != _tcsstr( txtData[i].szTT, _T("IDC_RB_T_SMALL_CAP") ) )
				txtData[i].idTT = IDC_RB_T_SMALL_CAP;
		else
			if( NULL != _tcsstr( txtData[i].szTT, _T("IDC_BT_SUPERSCRIPT") ) )
				txtData[i].idTT = IDC_BT_SUPERSCRIPT;
		else
			if( NULL != _tcsstr( txtData[i].szTT, _T("IDC_BT_SUBSCRIPT") ) )
				txtData[i].idTT = IDC_BT_SUBSCRIPT;
		else
			if( NULL != _tcsstr( txtData[i].szTT, _T("IDC_BT_T_MINUS") ) )
				txtData[i].idTT = IDC_BT_T_MINUS;
		else
			if( NULL != _tcsstr( txtData[i].szTT, _T("IDC_BT_T_PLUS") ) )
				txtData[i].idTT = IDC_BT_T_PLUS;
		else
			if( NULL != _tcsstr( txtData[i].szTT, _T("IDC_BT_T_F") ) )
				txtData[i].idTT = IDC_BT_T_F;
		else
			if( NULL != _tcsstr( txtData[i].szTT, _T("IDC_BT_T_LOCK") ) )
				txtData[i].idTT = IDC_BT_T_LOCK;
		else
			if( NULL != _tcsstr( txtData[i].szTT, _T("IDC_FRM_T_PREVIEW") ) )
				txtData[i].idTT = IDC_FRM_T_PREVIEW;
		else
			if( NULL != _tcsstr( txtData[i].szTT, _T("IDC_BT_FONT_LIST") ) )
				txtData[i].idTT = IDC_BT_FONT_LIST;
		else
			if( NULL != _tcsstr( txtData[i].szTT, _T("IDC_BT_ADVANCE") ) )
				txtData[i].idTT = IDC_BT_ADVANCE;
		else
			if( NULL != _tcsstr( txtData[i].szTT, _T("IDC_BT_SAVE_STYLE") ) )
				txtData[i].idTT = IDC_BT_SAVE_STYLE;			

		_tcscpy( txtData[i].szTT, (TCHAR*)txtData[i].szTT );
		if( NULL != GetDlgItem(txtData[i].idTT) )
			m_tooltip.AddTool( GetDlgItem(txtData[i].idTT), (_TCHAR*)ptTT);
	}//end of for

	free( txtData );
}//end of CDlgAttrib::InitDlgItemTextNTooltip()
////////////////////////////////////////////////////////////////////////////////////////////
void CAttribText::OnBtTBackGrd() 
{
	CGS_Action( CGSA_PRIORITY_SEND_TO_BACK );
	AfxGetMainWnd()->SetFocus();
}//end of CAttribText::OnBtTBackGrd
////////////////////////////////////////////////////////////////////////////////////////////
void CAttribText::OnBtTForeGrd() 
{
	CGS_Action( CGSA_PRIORITY_SEND_TO_FRONT );
	AfxGetMainWnd()->SetFocus();
}//end of CAttribText::OnBtTForeGrd
////////////////////////////////////////////////////////////////////////////////////////////
void CAttribText::OnBtTLock() 
{
	m_LockState ^= 1;
	CGS_SetValDbl( EDIT_LOCK_ATTRIBUTES, m_LockState );
	AfxGetMainWnd()->SetFocus();
}//end of CAttribText::OnBtTLock
////////////////////////////////////////////////////////////////////////////////////////////
void CAttribText::OnBtTMinus() 
{
	CGS_Action( CGSA_PRIORITY_SEND_FORWARD_ONE );
	AfxGetMainWnd()->SetFocus();
}//end of CAttribText::OnBtTMinus
////////////////////////////////////////////////////////////////////////////////////////////
void CAttribText::OnBtTPlus() 
{
	CGS_Action( CGSA_PRIORITY_SEND_BACKWARD_ONE );
	AfxGetMainWnd()->SetFocus();
}//end of CAttribText::OnBtTPlus
////////////////////////////////////////////////////////////////////////////////////////////
void CAttribText::OnRbTBold() 
{
	// TODO: Add your control notification handler code here
	m_rbBold.SetCheck( m_bBoldState ^= 1 );
	CGS_SetValDbl( EDIT_OBJ_BOLD_ENABLE, (double)m_bBoldState );
	AfxGetMainWnd()->SetFocus();
}//end of CAttribText::OnRbTBold
////////////////////////////////////////////////////////////////////////////////////////////
void CAttribText::OnRbTItalic() 
{
	// TODO: Add your control notification handler code here
	m_rbItalic.SetCheck( m_bItalicState ^= 1 );
	CGS_SetValDbl( EDIT_OBJ_ITALIC_ENABLE, (double)m_bItalicState );
	AfxGetMainWnd()->SetFocus();
}//end of CAttribText::OnRbTItalic
////////////////////////////////////////////////////////////////////////////////////////////
void CAttribText::OnRbTSmallCap() 
{
	// TODO: Add your control notification handler code here
	m_rbSmallCap.SetCheck( m_bSmallCapState ^= 1 );
	CGS_SetValDbl( EDIT_OBJ_SMALL_CAPS_ENABLE, (double)m_bSmallCapState );
	AfxGetMainWnd()->SetFocus();
	
}//end of CAttribText::OnRbTSmallCap
////////////////////////////////////////////////////////////////////////////////////////////
void CAttribText::OnRbTUnderlne() 
{	
	m_rbUnderLne.SetCheck( m_bULState ^= 1 );
	CGS_SetValDbl( EDIT_OBJ_UNDERLINE_ENABLE, (double)m_bULState );
	AfxGetMainWnd()->SetFocus();
}//end of CAttribText::OnRbTUnderlne
////////////////////////////////////////////////////////////////////////////////////////////
void CAttribText::OnDeltaposSpnTBevel(NMHDR* pNMHDR, LRESULT* pResult) 
{
	NM_UPDOWN* pNMUpDown = (NM_UPDOWN*)pNMHDR;
	// TODO: Add your control notification handler code here
	TRACE0("AttribText.cpp : CAttribText::OnDeltaposSpnTBevel\n");
	AfxGetMainWnd()->SetFocus();
	*pResult = 0;
}//end of CAttribText::OnDeltaposSpnTBevel
////////////////////////////////////////////////////////////////////////////////////////////
void CAttribText::OnDeltaposSpnTHeight(NMHDR* pNMHDR, LRESULT* pResult) 
{
	NM_UPDOWN* pNMUpDown = (NM_UPDOWN*)pNMHDR;
	char	buf[MAX_PATH];
	m_ctlEdHeight.GetLine( 0, (LPTSTR)buf, MAX_PATH );	// get edit control value

	// Convert the control value + the increment
	double val = atof( buf ) + (double)pNMUpDown->iDelta;
	val = val < 999 ? val : 999; // range checking
	val = val < 5   ? 5   : val;

	CGS_SetValDbl( EDIT_OBJ_SIZE, val );

	// Conver the double value to string for display
	DoubleToAlphaString( val, 1, (LPTSTR)buf );	// 1 means one digit after decimal point
	char* pSubStr = strstr( buf, ".0" );		// strip the floating part if 25.0
	if( pSubStr != NULL )						// ie: display 25 only
		*pSubStr = '\0';
	m_ctlEdHeight.SetWindowText( (LPTSTR)buf );

	AfxGetMainWnd()->SetFocus();
	*pResult = 0;
}//end of CAttribText::OnDeltaposSpnTHeight
////////////////////////////////////////////////////////////////////////////////////////////
void CAttribText::OnDeltaposSpnTKern(NMHDR* pNMHDR, LRESULT* pResult) 
{
	NM_UPDOWN* pNMUpDown = (NM_UPDOWN*)pNMHDR;
	char	buf[MAX_PATH];
	m_ctlEdKern.GetLine( 0, (LPTSTR)buf, MAX_PATH );	// get edit control value

	// Convert the control value + the increment
	double val = atof( buf ) + (double)pNMUpDown->iDelta;
	CGS_SetValDbl( EDIT_OBJ_CHAR_KERNING, val );

	val = val <  64 ? val : 64; // range checking
	val = val < -64 ? -64 : val;

	// Conver the double value to string for display
	DoubleToAlphaString( val, 1, (LPTSTR)buf );	// 1 means one digit after decimal point
/*** save
	char* pSubStr = strstr( buf, ".0" );		// strip the floating part if 25.0
	if( pSubStr != NULL )						// ie: display 25 only
		*pSubStr = '\0';
***/
	m_ctlEdKern.SetWindowText( (LPTSTR)buf );

	AfxGetMainWnd()->SetFocus();
	*pResult = 0;
}//end of CAttribText::OnDeltaposSpnTKern
////////////////////////////////////////////////////////////////////////////////////////////
void CAttribText::OnDeltaposSpnTPriority(NMHDR* pNMHDR, LRESULT* pResult) 
{
	NM_UPDOWN* pNMUpDown = (NM_UPDOWN*)pNMHDR;

	int val = pNMUpDown->iPos+pNMUpDown->iDelta;
	CGS_SetValDbl( EDIT_OBJ_PRIORITY, min(255, max(0, val)) );//jrs 01-05-13 added min 255 to cap at max val
	AfxGetMainWnd()->SetFocus();
	*pResult = 0;
}//end of CAttribText::OnDeltaposSpnTPriority
////////////////////////////////////////////////////////////////////////////////////////////
void CAttribText::OnDeltaposSpnTRotate(NMHDR* pNMHDR, LRESULT* pResult) 
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
}//end of CAttribText::OnDeltaposSpnTRotate
////////////////////////////////////////////////////////////////////////////////////////////
void CAttribText::OnDeltaposSpnTSpacing(NMHDR* pNMHDR, LRESULT* pResult) 
{
	NM_UPDOWN* pNMUpDown = (NM_UPDOWN*)pNMHDR;
	char	buf[MAX_PATH];
	m_ctlEdSpace.GetLine( 0, (LPTSTR)buf, MAX_PATH );	// get edit control value

	// Convert the control value + the increment
	double val = atof( buf ) + (double)pNMUpDown->iDelta;
	val = val <  64 ? val : 64; // range checking
	val = val < -64 ? -64 : val;

	CGS_SetValDbl( EDIT_OBJ_CHAR_SPACING, val );

	// Conver the double value to string for display
	DoubleToAlphaString( val, 1, (LPTSTR)buf );	// 1 means one digit after decimal point
	char* pSubStr = strstr( buf, ".0" );		// strip the floating part if 25.0
	if( pSubStr != NULL )						// ie: display 25 only
		*pSubStr = '\0';
	m_ctlEdSpace.SetWindowText( (LPTSTR)buf );

	AfxGetMainWnd()->SetFocus();
	*pResult = 0;
}//end of CAttribText::OnDeltaposSpnTSpacing
////////////////////////////////////////////////////////////////////////////////////////////
void CAttribText::OnDeltaposSpnTWidth(NMHDR* pNMHDR, LRESULT* pResult) 
{
	NM_UPDOWN* pNMUpDown = (NM_UPDOWN*)pNMHDR;
	char	buf[MAX_PATH];
	m_ctlEdWidth.GetLine( 0, (LPTSTR)buf, MAX_PATH );	// get edit control value

	// Convert the control value + the increment
	double val = atof( buf ) + (double)pNMUpDown->iDelta;
	val = val < 500 ? val : 500; // range checking
	val = val < 5   ? 5   : val;

	CGS_SetValDbl( EDIT_OBJ_WIDTH_PERCENT, val );

	// Conver the double value to string for display
	DoubleToAlphaString( val, 1, (LPTSTR)buf );	// 1 means one digit after decimal point
	char* pSubStr = strstr( buf, ".0" );		// strip the floating part if 25.0
	if( pSubStr != NULL )						// ie: display 25 only
		*pSubStr = '\0';
	m_ctlEdWidth.SetWindowText( (LPTSTR)buf );

	AfxGetMainWnd()->SetFocus();
	*pResult = 0;
}//end of CAttribText::OnDeltaposSpnTWidth
////////////////////////////////////////////////////////////////////////////////////////////
void CAttribText::OnDeltaposSpnTX(NMHDR* pNMHDR, LRESULT* pResult) 
{
	NM_UPDOWN* pNMUpDown = (NM_UPDOWN*)pNMHDR;
	char	buf[MAX_PATH];
	m_ctlEdX.GetLine( 0, (LPTSTR)buf, MAX_PATH );	// get edit control value

	// Convert the control value + the increment
	double val = atof( buf ) + (double)pNMUpDown->iDelta;
	CGS_SetValDbl( EDIT_OBJ_X_POSITION_ABS, val );

	val = val <  2000 ? val   : 2000; // range checking
	val = val < -2000 ? -2000 : val;

	// Conver the double value to string for display
	DoubleToAlphaString( val, 1, (LPTSTR)buf );	// 1 means one digit after decimal point
	char* pSubStr = strstr( buf, ".0" );		// strip the floating part if 25.0
	if( pSubStr != NULL )						// ie: display 25 only
		*pSubStr = '\0';
	m_ctlEdX.SetWindowText( (LPTSTR)buf );

	AfxGetMainWnd()->SetFocus();
	*pResult = 0;
}//end of CAttribText::OnDeltaposSpnTX
////////////////////////////////////////////////////////////////////////////////////////////
void CAttribText::OnDeltaposSpnTY(NMHDR* pNMHDR, LRESULT* pResult) 
{
	NM_UPDOWN* pNMUpDown = (NM_UPDOWN*)pNMHDR;
	char	buf[MAX_PATH];
	m_ctlEdY.GetLine( 0, (LPTSTR)buf, MAX_PATH );	// get edit control value

	// Convert the control value + the increment
	double val = atof( buf ) + (double)pNMUpDown->iDelta;
	CGS_SetValDbl( EDIT_OBJ_Y_POSITION_ABS, val );

	val = val <  2000 ? val   : 2000; // range checking
	val = val < -2000 ? -2000 : val;

	// Conver the double value to string for display
	DoubleToAlphaString( val, 1, (LPTSTR)buf );	// 1 means one digit after decimal point
	char* pSubStr = strstr( buf, ".0" );		// strip the floating part if 25.0
	if( pSubStr != NULL )						// ie: display 25 only
		*pSubStr = '\0';
	m_ctlEdY.SetWindowText( (LPTSTR)buf );

	AfxGetMainWnd()->SetFocus();
	*pResult = 0;
}//end of CAttribText::OnDeltaposSpnTY
////////////////////////////////////////////////////////////////////////////////////////////
VOID CAttribText::DeleteAttribText()
{
	DestroyWindow();
}//end of CAttribText::DeleteAttribText()
////////////////////////////////////////////////////////////////////////////////////////////
// Initial the font combo box - Read all supported font from CORE and then add into combo
// box. Get the current font setting from CORE and select it. If fail reading from CORE,
// select Arial and set Arial font to CORE.
VOID CAttribText::InitFontCombo()
{
//check point
	char	szFont[MAX_PATH];
	TCHAR	swFont[MAX_PATH];

	m_ocbFont.SubclassDlgItem(IDC_CB_T_FONT,this);
	m_ocbFont.Initialize();

	CGS_GetValStr( EDIT_OBJ_TYPEFACE, szFont );

	MultiByteToUnicode( CP_ACP, szFont, swFont );
	int strIndex = m_ocbFont.SelectString( 0, swFont );
	if( strIndex == CB_ERR )
	{
		m_ocbFont.AddFont( swFont, TRUETYPE_FONT );
		m_ocbFont.AddString( swFont );
		strIndex = m_ocbFont.SelectString( 0, swFont );
	}

	m_ocbFont.SetCurSel( strIndex );

}//end of CAttribText::InitFontCombo()
////////////////////////////////////////////////////////////////////////////////////////////
// Initial all radio button state and icon - Read from CORE and set the state
VOID CAttribText::InitRadioButtom()
{
	//++++++++++++++++++ Initial radio button and Icon		
	m_btSubScript.SetIcon(   (HICON)::LoadImage( AfxGetApp()->m_hInstance, MAKEINTRESOURCE(IDI_SUB_SCRIPT),   IMAGE_ICON, 8, 8, 0) );
	m_btSuperScript.SetIcon( (HICON)::LoadImage( AfxGetApp()->m_hInstance, MAKEINTRESOURCE(IDI_SUPER_SCRIPT), IMAGE_ICON, 8, 8, 0) );
	m_btBackGrd.SetIcon(     (HICON)::LoadImage( AfxGetApp()->m_hInstance, MAKEINTRESOURCE(IDI_BACK_GRD),     IMAGE_ICON, 16, 16, 0) );
	m_btForeGrd.SetIcon(     (HICON)::LoadImage( AfxGetApp()->m_hInstance, MAKEINTRESOURCE(IDI_FORE_GRD),     IMAGE_ICON, 16, 16, 0) );
	m_btLock.SetIcon(        (HICON)::LoadImage( AfxGetApp()->m_hInstance, MAKEINTRESOURCE(IDI_LOCK),         IMAGE_ICON, 16, 16, 0) );
	m_btMinus.SetIcon(       (HICON)::LoadImage( AfxGetApp()->m_hInstance, MAKEINTRESOURCE(IDI_BACK_MINUS),   IMAGE_ICON, 16, 16, 0) );
	m_btPlus.SetIcon(		 (HICON)::LoadImage( AfxGetApp()->m_hInstance, MAKEINTRESOURCE(IDI_FORE_PLUS),    IMAGE_ICON, 16, 16, 0) );
	m_rbBold.SetIcon(        (HICON)::LoadImage( AfxGetApp()->m_hInstance, MAKEINTRESOURCE(IDI_BOLD),         IMAGE_ICON, 16, 16, 0) );
	m_rbItalic.SetIcon(      (HICON)::LoadImage( AfxGetApp()->m_hInstance, MAKEINTRESOURCE(IDI_ITALIC),       IMAGE_ICON, 16, 16, 0) );
	m_rbUnderLne.SetIcon(    (HICON)::LoadImage( AfxGetApp()->m_hInstance, MAKEINTRESOURCE(IDI_UNDERLNE),     IMAGE_ICON, 16, 16, 0) );
	m_rbSmallCap.SetIcon(    (HICON)::LoadImage( AfxGetApp()->m_hInstance, MAKEINTRESOURCE(IDI_SMALLCAP),     IMAGE_ICON, 16, 16, 0) );
	m_btFontList.SetIcon(    (HICON)::LoadImage( AfxGetApp()->m_hInstance, MAKEINTRESOURCE(IDI_TT_FONT),      IMAGE_ICON, 16, 16, 0) );	
	m_btAdvance.SetIcon(     (HICON)::LoadImage( AfxGetApp()->m_hInstance, MAKEINTRESOURCE(IDI_ADVANCE),      IMAGE_ICON, 16, 16, 0) );		
	m_btSaveStyle.SetIcon(   (HICON)::LoadImage( AfxGetApp()->m_hInstance, MAKEINTRESOURCE(IDI_SAVE_STYLE),   IMAGE_ICON, 16, 16, 0) );
	
	//+++++++++++++++++++++++++++++++++++++++++++++ Initial radio button state
	m_bBoldState        = (int)CGS_GetValDbl( EDIT_OBJ_BOLD_ENABLE );
	m_bULState          = (int)CGS_GetValDbl( EDIT_OBJ_UNDERLINE_ENABLE );	
	m_bItalicState      = (int)CGS_GetValDbl( EDIT_OBJ_ITALIC_ENABLE );
	m_bSmallCapState    = (int)CGS_GetValDbl( EDIT_OBJ_SMALL_CAPS_ENABLE );
	m_LockState			= (int)CGS_GetValDbl( EDIT_LOCK_ATTRIBUTES );
//	m_bSubScriptState   = (int)CGS_GetValDbl( EDIT_OBJ_SMALL_CAPS_ENABLE );
//	m_bSuperScriptState = (int)CGS_GetValDbl( EDIT_OBJ_SMALL_CAPS_ENABLE );
	m_bSubScriptState   = 0;
	m_bSuperScriptState = 0;

	m_rbBold.SetCheck( m_bBoldState );
	m_rbUnderLne.SetCheck( m_bULState );
	m_rbItalic.SetCheck( m_bItalicState );
	m_rbSmallCap.SetCheck( m_bSmallCapState );
	m_btSubScript.SetCheck( m_bSubScriptState );
	m_btSuperScript.SetCheck( m_bSuperScriptState );
}//end of CAttribText::InitRadioButtom()
//////////////////////////////////////////////////////////////////////////////////////////////
// Initial all spin control and edit box control. Read value from CORE and set the edit text
VOID CAttribText::InitEditSpinControl()
{
	// ++++++++++++++++++++++++++++++++++++++++++++ Initial spin control
	CSpinButtonCtrl* pSpin = (CSpinButtonCtrl*)GetDlgItem( IDC_SPN_T_HEIGHT );
	pSpin->SetRange( 5, 999 );
	//save for ref.	pSpin->SetPos((int) (m_dSpin * 10.0));
	pSpin = (CSpinButtonCtrl*)GetDlgItem( IDC_SPN_T_WIDTH );
	pSpin->SetRange( 5, 500 );
	pSpin = (CSpinButtonCtrl*)GetDlgItem( IDC_SPN_T_SPACING );
	pSpin->SetRange( -64, 64 );
	pSpin = (CSpinButtonCtrl*)GetDlgItem( IDC_SPN_T_PRIORITY );
	pSpin->SetRange( 0, 255 );
	pSpin = (CSpinButtonCtrl*)GetDlgItem( IDC_SPN_T_ROTATE );
	pSpin->SetRange( 0, 359 );
	pSpin = (CSpinButtonCtrl*)GetDlgItem( IDC_SPN_T_BEVEL );
	pSpin->SetRange( 0, 32 );
	pSpin = (CSpinButtonCtrl*)GetDlgItem( IDC_SPN_T_KERN );
	pSpin->SetRange( -64, 64 );
	pSpin = (CSpinButtonCtrl*)GetDlgItem( IDC_SPN_T_X );
	pSpin->SetRange( -2000, 2000 );
	pSpin = (CSpinButtonCtrl*)GetDlgItem( IDC_SPN_T_Y );
	pSpin->SetRange( -2000, 2000 );

	//+++++++++++++++++++++++++++++++++++++++++++++ Initial Edit control
	_TCHAR buf[MAX_PATH];
	CEdit* pEdCtrl = (CEdit*)GetDlgItem( IDC_ED_T_WIDTH );
	pEdCtrl->SetLimitText( 5 ); // 5 characters of 500.0
	DoubleToAlphaString( CGS_GetValDbl(EDIT_OBJ_WIDTH_PERCENT), 1, buf );
/*
	char* pSubStr = strstr( buf, ".0" );		// strip the floating part if 25.0
	if( pSubStr != NULL )						// ie: display 25 only
		*pSubStr = '\0';
*/	SetDlgItemText(IDC_ED_T_WIDTH, buf );

	pEdCtrl = (CEdit*)GetDlgItem( IDC_ED_T_HEIGHT );
	pEdCtrl->SetLimitText( 5 ); // 5 characters of 999.0
	DoubleToAlphaString( CGS_GetValDbl(EDIT_OBJ_SIZE), 1, buf );
/*	pSubStr = strstr( buf, ".0" );		// strip the floating part if 25.0
	if( pSubStr != NULL )				// ie: display 25 only
		*pSubStr = '\0';
*/	SetDlgItemText(IDC_ED_T_HEIGHT, buf );
	
	pEdCtrl = (CEdit*)GetDlgItem( IDC_ED_T_SPACE );
	pEdCtrl->SetLimitText( 5 ); // 3 characters of -64.0 .. +64.0
	DoubleToAlphaString( CGS_GetValDbl(EDIT_OBJ_CHAR_SPACING), 1, buf );
/*	pSubStr = strstr( buf, ".0" );		// strip the floating part if 25.0
	if( pSubStr != NULL )				// ie: display 25 only
		*pSubStr = '\0';
*/	SetDlgItemText(IDC_ED_T_SPACE, buf );

	pEdCtrl = (CEdit*)GetDlgItem( IDC_ED_T_PRIORITY );
	pEdCtrl->SetLimitText( 3 ); // 3 characters of 255
	DoubleToAlphaString( CGS_GetValDbl(EDIT_OBJ_PRIORITY), 1, buf );
/*	pSubStr = strstr( buf, ".0" );		// strip the floating part if 25.0
	if( pSubStr != NULL )				// ie: display 25 only
		*pSubStr = '\0';
*/	SetDlgItemText(IDC_ED_T_PRIORITY, buf );

	pEdCtrl = (CEdit*)GetDlgItem( IDC_ED_T_KERNING );
	pEdCtrl->SetLimitText( 5 ); // 4 characters of -64.0 .. 64.0
	DoubleToAlphaString( CGS_GetValDbl(EDIT_OBJ_CHAR_KERNING), 1, buf );
/*	pSubStr = strstr( buf, ".0" );		// strip the floating part if 25.0
	if( pSubStr != NULL )				// ie: display 25 only
		*pSubStr = '\0';
*/	SetDlgItemText(IDC_ED_T_KERNING, buf );

	pEdCtrl = (CEdit*)GetDlgItem( IDC_ED_T_BEVEL );
	pEdCtrl->SetLimitText( 2 ); // 2 characters of 32
	DoubleToAlphaString( CGS_GetValDbl(EDIT_OBJ_BEVEL_SIZE), 1, buf );
/*	pSubStr = strstr( buf, ".0" );		// strip the floating part if 25.0
	if( pSubStr != NULL )				// ie: display 25 only
		*pSubStr = '\0';
*/	SetDlgItemText(IDC_ED_T_BEVEL, buf );

	pEdCtrl = (CEdit*)GetDlgItem( IDC_ED_T_ROTATION );
	pEdCtrl->SetLimitText( 5 ); // 5 characters of 359.5
	DoubleToAlphaString( CGS_GetValDbl(EDIT_OBJ_ROTATION), 1, buf );
/*	pSubStr = strstr( buf, ".0" );		// strip the floating part if 25.0
	if( pSubStr != NULL )						// ie: display 25 only
		*pSubStr = '\0';
*/	SetDlgItemText(IDC_ED_T_ROTATION, buf );
	
	pEdCtrl = (CEdit*)GetDlgItem( IDC_ED_T_X );
	pEdCtrl->SetLimitText( 7 ); // 5 characters of -3000.0
	DoubleToAlphaString( CGS_GetValDbl(EDIT_OBJ_X_POSITION_ABS), 1, buf );
/*	pSubStr = strstr( buf, ".0" );		// strip the floating part if 25.0
	if( pSubStr != NULL )						// ie: display 25 only
		*pSubStr = '\0';
*/	SetDlgItemText(IDC_ED_T_X, buf );

	pEdCtrl = (CEdit*)GetDlgItem( IDC_ED_T_Y );
	pEdCtrl->SetLimitText( 7 ); // 5 characters of -3000.0
	DoubleToAlphaString( CGS_GetValDbl(EDIT_OBJ_Y_POSITION_ABS), 1, buf );
/*	pSubStr = strstr( buf, ".0" );		// strip the floating part if 25.0
	if( pSubStr != NULL )						// ie: display 25 only
		*pSubStr = '\0';
*/	SetDlgItemText(IDC_ED_T_Y, buf );

}//end of CAttribText::InitEditSpinControl()
//////////////////////////////////////////////////////////////////////////////////////////////
VOID CAttribText::InitStaticIcon()
{
	m_stcWidth.ModifyStyle( 0, SS_ICON );
	m_stcWidth.SetIcon( (HICON)::LoadImage( AfxGetApp()->m_hInstance,
							MAKEINTRESOURCE( IDI_FONT_WIDTH ),IMAGE_ICON, 16, 16, 0 ) );
	m_stcHeight.ModifyStyle( 0, SS_ICON );
	m_stcHeight.SetIcon( (HICON)::LoadImage( AfxGetApp()->m_hInstance,
							MAKEINTRESOURCE( IDI_FONT_HEIGHT ),	IMAGE_ICON, 16, 16, 0 ) );
	m_stcBevel.ModifyStyle( 0, SS_ICON );
	m_stcBevel.SetIcon( (HICON)::LoadImage( AfxGetApp()->m_hInstance,
							MAKEINTRESOURCE( IDI_BEVEL ),IMAGE_ICON, 16, 16, 0 ) );
	m_stcKern.ModifyStyle( 0, SS_ICON );
	m_stcKern.SetIcon( (HICON)::LoadImage( AfxGetApp()->m_hInstance,
							MAKEINTRESOURCE( IDI_KERN ),IMAGE_ICON, 16, 16, 0 ) );
	m_stcRotate.ModifyStyle( 0, SS_ICON );
	m_stcRotate.SetIcon( (HICON)::LoadImage( AfxGetApp()->m_hInstance,
							MAKEINTRESOURCE( IDI_ROTATE ),IMAGE_ICON, 16, 16, 0 ) );
	m_stcSpace.ModifyStyle( 0, SS_ICON );
	m_stcSpace.SetIcon( (HICON)::LoadImage( AfxGetApp()->m_hInstance,
							MAKEINTRESOURCE( IDI_SPACE ),IMAGE_ICON, 16, 16, 0 ) );

}//end of CAttribText::InitStaticIcon()
///////////////////////////////////////////////////////////////////////////////////////////////
VOID CAttribText::DoValueUpdate()
{
	TRACE0("AttribText.cpp : CAttribText::DoValueUpdate()\n");
	_TCHAR buf[MAX_PATH];

	DoubleToAlphaString( CGS_GetValDbl(EDIT_OBJ_CHAR_SPACING), 1, buf );
	SetDlgItemText(IDC_ED_T_SPACE, buf );
	DoubleToAlphaString( CGS_GetValDbl(EDIT_OBJ_ROTATION), 1, buf );
	SetDlgItemText(IDC_ED_T_ROTATION, buf );
	DoubleToAlphaString( CGS_GetValDbl(EDIT_OBJ_SIZE), 1, buf );
	SetDlgItemText(IDC_ED_T_HEIGHT, buf );
	DoubleToAlphaString( CGS_GetValDbl(EDIT_OBJ_WIDTH_PERCENT), 1, buf );
	SetDlgItemText(IDC_ED_T_WIDTH, buf );
	DoubleToAlphaString( CGS_GetValDbl(EDIT_OBJ_CHAR_KERNING), 1, buf );
	SetDlgItemText(IDC_ED_T_KERNING, buf );
	DoubleToAlphaString( CGS_GetValDbl(EDIT_OBJ_PRIORITY), 1, buf );
	SetDlgItemText(IDC_ED_T_PRIORITY, buf );

	// TO DO : hook up with other	
/**
	DoubleToAlphaString( CGS_GetValDbl(EDIT_OBJ_KERNING), 1, buf );
	SetDlgItemText(IDC_ED_T_KERNING, buf );
	DoubleToAlphaString( CGS_GetValDbl(EDIT_OBJ_BEVEL), 1, buf );
	SetDlgItemText(IDC_ED_T_BEVEL, buf );
	DoubleToAlphaString( CGS_GetValDbl(EDIT_OBJ_PRIORITY), 1, buf );
	SetDlgItemText(IDC_ED_T_X, buf );
	DoubleToAlphaString( CGS_GetValDbl(EDIT_OBJ_PRIORITY), 1, buf );
	SetDlgItemText(IDC_ED_T_Y, buf );
**/
//	SetDlgItemInt(IDC_ED_T_PRIORITY, (INT)CGS_GetValDbl(EDIT_OBJ_PRIORITY), 0 );
//	SetDlgItemInt(IDC_ED_T_BEVEL, (INT)CGS_GetValDbl(EDIT_OBJ_BEVEL), 0 );

// check point
	char	szFont[80];
	TCHAR	swFont[MAX_PATH];
	
	CGS_GetValStr( EDIT_OBJ_TYPEFACE, szFont );
	MultiByteToUnicode( CP_ACP, szFont, swFont );
/***
#ifdef _UNICODE
	MultiByteToWideChar(CP_ACP, MB_PRECOMPOSED, szFont, -1, swFont, MAX_PATH);
#else
	_mbscpy( (_TUCHAR*)swFont, (_TUCHAR*)szFont );
#endif
***/
	int strIndex = m_ocbFont.SelectString( 0, swFont );
	if( strIndex == CB_ERR )
	{
		m_ocbFont.AddFont( swFont, TRUETYPE_FONT );
		m_ocbFont.AddString( swFont );
		strIndex = m_ocbFont.SelectString( 0, swFont );
	}
	
	m_ocbFont.SetCurSel( strIndex );

	//+++++++++++++++++++++++++++++++++++++++++++++ Initial radio button state
	m_bBoldState        = (int)CGS_GetValDbl( EDIT_OBJ_BOLD_ENABLE );
	m_bULState          = (int)CGS_GetValDbl( EDIT_OBJ_UNDERLINE_ENABLE );	
	m_bItalicState      = (int)CGS_GetValDbl( EDIT_OBJ_ITALIC_ENABLE );
	m_bSmallCapState    = (int)CGS_GetValDbl( EDIT_OBJ_SMALL_CAPS_ENABLE );
//	m_bSubScriptState   = (int)CGS_GetValDbl( EDIT_OBJ_SMALL_CAPS_ENABLE );
//	m_bSuperScriptState = (int)CGS_GetValDbl( EDIT_OBJ_SMALL_CAPS_ENABLE );

	m_rbBold.SetCheck( m_bBoldState );
	m_rbUnderLne.SetCheck( m_bULState );
	m_rbItalic.SetCheck( m_bItalicState );
	m_rbSmallCap.SetCheck( m_bSmallCapState );
	m_btSubScript.SetCheck( m_bSubScriptState );
	m_btSuperScript.SetCheck( m_bSuperScriptState );

//	CGS_EditUpdateCurAttrSample( (DWORD)GetDlgItem( IDC_FRM_T_PREVIEW )->m_hWnd );

	AfxGetMainWnd()->SetFocus();
}//end of CAttribText::DoValueUpdate()
///////////////////////////////////////////////////////////////////////////////////////////////
void CAttribText::OnPaint() 
{
	CPaintDC dc(this); // device context for painting
	
//	CGS_EditUpdateCurAttrSample( (DWORD)GetDlgItem( IDC_FRM_T_PREVIEW )->m_hWnd );
	CGS_CurAttrSample_OnPaint( (DWORD)GetDlgItem( IDC_FRM_T_PREVIEW )->m_hWnd );
}//end of CAttribText::OnPaint()
///////////////////////////////////////////////////////////////////////////////////////////////
void CAttribText::OnChangeEdTSpace() 
{
	TRACE0("AttribText.cpp : CAttribText::OnChangeEdTSpace\n");
}//end of CAttribText::OnChangeEdTSpace
///////////////////////////////////////////////////////////////////////////////////////////////
void CAttribText::OnSuperscript() 
{
	TRACE0("AttribText.cpp : CAttribText::OnSuperscript\n");
	m_btSuperScript.SetCheck( m_bSuperScriptState ^= 1 );
	m_bSubScriptState = m_bSuperScriptState ? 0 : m_bSubScriptState;
	m_btSubScript.SetCheck( m_bSubScriptState );

//	CGS_SetValDbl( EDIT_OBJ_BOLD_ENABLE, (double)m_bBoldState );
//	CGS_SetValDbl( EDIT_OBJ_BOLD_ENABLE, (double)m_bBoldState );
	
	AfxGetMainWnd()->SetFocus();
}//end of CAttribText::OnSuperscript() 
///////////////////////////////////////////////////////////////////////////////////////////////
void CAttribText::OnSubscript() 
{
	TRACE0("AttribText.cpp : CAttribText::OnSubscript\n");
	m_btSubScript.SetCheck( m_bSubScriptState ^= 1 );
	m_bSuperScriptState = m_bSubScriptState ? 0 : m_bSuperScriptState;
	m_btSuperScript.SetCheck( m_bSuperScriptState );

//	CGS_SetValDbl( EDIT_OBJ_BOLD_ENABLE, (double)m_bBoldState );
	AfxGetMainWnd()->SetFocus();
}//end of CAttribText::OnSubscript()
///////////////////////////////////////////////////////////////////////////////////////////////
void CAttribText::OnBtFontList() 
{
	CFontLocator	dlgFont;

	int rv = -1;
	rv = dlgFont.DoModal();
	switch( rv )
	{
	case -1:
		AfxMessageBox(_T("Dialog box could not be created!"));	  
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
	}//end of switch - rv		
}//end of CAttribText::OnBtFontList() 
///////////////////////////////////////////////////////////////////////////////////////////////
void CAttribText::OnBtAdvance() 
{
	CDlgTypeFace dlgTypeFace;
	int rv = -1;
	rv = dlgTypeFace.DoModal();
	switch( rv )
	{
	case -1:
		AfxMessageBox(_T("Dialog box could not be created!"));	  
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
	}//end of switch - rv		
}//end of CAttribText::OnBtAdvance() 
///////////////////////////////////////////////////////////////////////////////////////////////
VOID CAttribText::ControlOption()
{
	if( HIDE_TEXT_ATTRIB ) // define the option flag here
	{
		m_ctlEdRotate.ShowWindow( SW_HIDE );
		m_spnRotate.ShowWindow( SW_HIDE );
		m_stcRotate.ShowWindow( SW_HIDE );

		m_ctlEdBevel.ShowWindow( SW_HIDE );
		m_spnBevel.ShowWindow( SW_HIDE );
		m_stcBevel.ShowWindow( SW_HIDE );

		m_ctlEdX.ShowWindow( SW_HIDE );
		m_spnX.ShowWindow( SW_HIDE );
		m_stcX.ShowWindow( SW_HIDE );

		m_ctlEdY.ShowWindow( SW_HIDE );
		m_spnY.ShowWindow( SW_HIDE );
		m_stcY.ShowWindow( SW_HIDE );

		m_ctlEdPriority.ShowWindow( SW_HIDE );
		m_spnPriority.ShowWindow( SW_HIDE );

		m_rbSmallCap.ShowWindow( SW_HIDE );
		m_btSubScript.ShowWindow( SW_HIDE );
		m_btSuperScript.ShowWindow( SW_HIDE );
	}//end of option flag - for Japanese review

}//end of CAttribText::ControlOption()
////////////////////////////////////////////////////////////////////////////////////////
void CAttribText::OnBtSaveStyle() 
{
	TRACE0("\nAttribText.cpp : CAttribText::OnBtSaveStyle()");
	CGS_Action( CGSA_SAVE_STYLE_PRESET );
}//end of CAttribText::OnBtSaveStyle() 
