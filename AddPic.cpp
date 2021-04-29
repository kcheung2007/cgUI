/* COPYRIGHT NOTICE:
********************************************************
*  Copyright (c) 2000 InnoVision Technology, Inc.      *
*  All rights reserved.                                *
*  PROPRIETARY AND CONFIDENTIAL                        *
*  DO NOT DISTRIBUTE                                   *
********************************************************
*/

// AddPic.cpp : implementation file
//

#include "stdafx.h"
#include "cgui.h"
#include "AddPic.h"
#include "Global.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CAddPic dialog
extern _TCHAR	UILang_UIFont[256];
extern int		UILang_UIFontSize;
extern _TCHAR	g_szFile[MAX_PATH];
extern _TCHAR	g_szSize[MAX_PATH];


CAddPic::CAddPic(CWnd* pParent /*=NULL*/) : CDialog(CAddPic::IDD, pParent)
{
	//{{AFX_DATA_INIT(CAddPic)
	//}}AFX_DATA_INIT
	m_hFont = NULL;
}
CAddPic::~CAddPic()
{
	for( DWORD i = 0; i < m_numTxt; i++ )
	{
		if( m_hFont[i] != NULL )
			DeleteObject( (HGDIOBJ)m_hFont[i] );
	}

	if( m_hFont != NULL )
		delete [] m_hFont;
}

void CAddPic::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CAddPic)
	DDX_Control(pDX, IDC_ED_ED_WIN_SIZE, m_edWinSize);
	DDX_Control(pDX, IDC_RB_UR, m_rbUpperRight);
	DDX_Control(pDX, IDC_RB_UM, m_rbUpperCenter);
	DDX_Control(pDX, IDC_RB_UL, m_rbUpperLeft);
	DDX_Control(pDX, IDC_RB_MR, m_rbMiddleRight);
	DDX_Control(pDX, IDC_RB_ML, m_rbMiddleLeft);
	DDX_Control(pDX, IDC_RB_CC, m_rbMiddleCenter);
	DDX_Control(pDX, IDC_RB_BR, m_rbBottomRight);
	DDX_Control(pDX, IDC_RB_BM, m_rbBottomCenter);
	DDX_Control(pDX, IDC_RB_BL, m_rbBottomLeft);
	DDX_Control(pDX, IDC_CK_PRESERVE_ASPECT, m_ckPreAspect);
	DDX_Control(pDX, IDC_CK_BLACK_TRIM, m_ckBlackTrim);
	DDX_Control(pDX, IDC_CK_A_CH_INVERT, m_ckAChInvert);
	DDX_Control(pDX, IDC_CK_A_CH_INCLUDE, m_ckAChInclude);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CAddPic, CDialog)
	//{{AFX_MSG_MAP(CAddPic)
	ON_WM_PAINT()
	ON_NOTIFY(UDN_DELTAPOS, IDC_SPN_ED_WIN, OnDeltaposSpnEdWin)
	ON_EN_SETFOCUS(IDC_ED_ED_WIN_SIZE, OnSetfocusEdEdWinSize)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CAddPic message handlers
/////////////////////////////////////////////////////////////////////////////
BOOL CAddPic::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: Add extra initialization here
	InitDlgItemText();
	InitPictureInfo();
	
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}//end of CAddPic::OnInitDialog
/////////////////////////////////////////////////////////////////////////////
VOID CAddPic::InitDlgItemText()
{
	IN_TEXT_DATA* txtData = NULL;
	TCHAR	sep[] = _T("\"");
	TCHAR*	ptID;
	TCHAR*	ptTT;
	TCHAR*	ptEnd;
	DWORD	i;

	m_numTxt = LoadTextFromCtl( "\\Util\\DlgAddPic.ctl", "[Tooltip]", &txtData );
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

		if( NULL != _tcsstr( txtData[i].szTT, _T("IDD_PIC_LOAD_OPT") ) )
		{
			txtData[i].idTT = IDD_PIC_LOAD_OPT;			
			m_hFont[i] = ChangeControlFont( m_hWnd, /*m_hFont[i]*/NULL, UILang_UIFont,0, UILang_UIFontSize, FW_NORMAL);
			SetWindowText( (LPCTSTR)ptTT );
		}
		else
			if( NULL != _tcsstr( txtData[i].szTT, _T("IDC_STC_FILE") ) )
				txtData[i].idTT = IDC_STC_FILE;
		else
			if( NULL != _tcsstr( txtData[i].szTT, _T("IDC_STC_ORIG_SIZE") ) )
				txtData[i].idTT = IDC_STC_ORIG_SIZE;
		else
			if( NULL != _tcsstr( txtData[i].szTT, _T("IDC_GP_LD_SIZE") ) )
				txtData[i].idTT = IDC_GP_LD_SIZE;
		else
			if( NULL != _tcsstr( txtData[i].szTT, _T("IDC_RB_ORIG_SIZE") ) )
				txtData[i].idTT = IDC_RB_ORIG_SIZE;
		else
			if( NULL != _tcsstr( txtData[i].szTT, _T("IDC_RB_FIT_ED_WIN") ) )
				txtData[i].idTT = IDC_RB_FIT_ED_WIN;
		else
			if( NULL != _tcsstr( txtData[i].szTT, _T("IDC_STC_ED_WIN_SIZE") ) )
				txtData[i].idTT = IDC_STC_ED_WIN_SIZE;
		else
			if( NULL != _tcsstr( txtData[i].szTT, _T("IDC_CK_A_CH_INCLUDE") ) )
				txtData[i].idTT = IDC_CK_A_CH_INCLUDE;
		else
			if( NULL != _tcsstr( txtData[i].szTT, _T("IDC_CK_A_CH_INVERT") ) )
				txtData[i].idTT = IDC_CK_A_CH_INVERT;
		else
			if( NULL != _tcsstr( txtData[i].szTT, _T("IDC_CK_BLACK_TRIM") ) )
				txtData[i].idTT = IDC_CK_BLACK_TRIM;
		else
			if( NULL != _tcsstr( txtData[i].szTT, _T("IDC_GP_POSITION") ) )
				txtData[i].idTT = IDC_GP_POSITION;
		else
			if( NULL != _tcsstr( txtData[i].szTT, _T("IDOK") ) )
				txtData[i].idTT = IDOK;
		else
			if( NULL != _tcsstr( txtData[i].szTT, _T("IDCANCEL") ) )
				txtData[i].idTT = IDCANCEL;

		SetDlgItemText( txtData[i].idTT, (LPCTSTR)ptTT );

		if( txtData[i].idTT != IDD_PIC_LOAD_OPT )
			m_hFont[i] = ChangeControlFont( GetDlgItem(txtData[i].idTT)->m_hWnd, NULL/*m_hFont[i]*/, UILang_UIFont,0, UILang_UIFontSize, FW_NORMAL);			
	}//end of for

	free( txtData );

}//end of CAddPic::InitDlgItemText()
/////////////////////////////////////////////////////////////////////////////
// Set the picture file name and file size and assume the file name and file
// size is valid. No error checking here.
VOID CAddPic::InitPictureInfo()
{
	CGS_GetPictureLoadOptions( g_szFile, &m_ploi );

	SetDlgItemText( IDC_STC_FILE_NAME,      m_ploi.inFileName );
	SetDlgItemText( IDC_STC_FILE_ORIG_SIZE, m_ploi.inOriginalSizeString );

	// +++++++++++++++++++++++++++++ initial load options	
	switch( m_ploi.inoutLoadSizeOption )
	{
	case PIC_LOAD_SIZE_ORIGINAL:
		CheckRadioButton( IDC_RB_ORIG_SIZE, IDC_RB_ED_WIN_SIZE, IDC_RB_ORIG_SIZE );
		break;
	case PIC_LOAD_SIZE_FIT:
		CheckRadioButton( IDC_RB_ORIG_SIZE, IDC_RB_ED_WIN_SIZE, IDC_RB_FIT_ED_WIN );
		break;
	case PIC_LOAD_SIZE_PERCENT:
		CheckRadioButton( IDC_RB_ORIG_SIZE, IDC_RB_ED_WIN_SIZE, IDC_RB_ED_WIN_SIZE );
		break;
	}//end of switch - inoutLoadSizeOption
	CheckDlgButton( IDC_CK_PRESERVE_ASPECT, m_ploi.inoutPreserveImageAspect );

	//--------------------
	if( !m_ploi.inEnableControl_IncludeAlphaChannel )
		m_ckAChInclude.EnableWindow( 0 ); // disable it
	else
	{
		m_ckAChInclude.SetCheck( m_ploi.inoutIncludeAlphaChannel );
	}

	if( !m_ploi.inEnableControl_InvertAlphaChannel )
		m_ckAChInvert.EnableWindow( 0 ); // disable it
	else
	{
		m_ckAChInvert.SetCheck( m_ploi.inoutInvertAlphaChannel );
	}

	if( !m_ploi.inEnableControl_BlackTrim )
		m_ckBlackTrim.EnableWindow( 0 ); // disable it
	else
	{
		m_ckBlackTrim.SetCheck( m_ploi.inoutBlackTrim );
	}
	
	// ++++++++++++++++++++++ initial Position
	CheckRadioButton( IDC_RB_UL, IDC_RB_BR, IDC_RB_UL+m_ploi.inoutPositionSector_0_8 );



	CSpinButtonCtrl* pSpin = (CSpinButtonCtrl*)GetDlgItem( IDC_SPN_ED_WIN );
	pSpin->SetRange( 0, 100 );
	//save for ref.	pSpin->SetPos((int) (m_dSpin * 10.0));

	_TCHAR buf[MAX_PATH];
	CEdit* pEdCtrl = (CEdit*)GetDlgItem( IDC_ED_ED_WIN_SIZE );
	pEdCtrl->SetLimitText( 5 ); // 5 characters of 0..100.0 %
	DoubleToAlphaString( m_ploi.inoutPercentZoom, 1, buf );

	SetDlgItemText(IDC_ED_ED_WIN_SIZE, buf );

}//end of CAddPic::InitPictureInfo()
/////////////////////////////////////////////////////////////////////////////
void CAddPic::OnPaint() 
{
	CPaintDC dc(this); // device context for painting

	// Draw the picture by calling CGS_GetPictureInfo. 
	// Assume the file name and file size exit, because the file was opened by
	// File request dialog. If the picture is not a valid format. Should not call
	// this function.... No error checking on the file name and file size.
	char dummy[MAX_PATH];
	CWnd* pPic = GetDlgItem( IDC_STC_FRAME );
	CGS_GetPictureInfo( g_szFile, pPic->m_hWnd, BORDER, dummy );
	
	// Do not call CDialog::OnPaint() for painting messages
}//end of CAddPic::OnPaint()
/////////////////////////////////////////////////////////////////////////////
void CAddPic::OnDeltaposSpnEdWin(NMHDR* pNMHDR, LRESULT* pResult) 
{
	TRACE0("AddPic.cpp.cpp - CAddPic::OnDeltaposSpnEdWin()\n" );
	CheckRadioButton( IDC_RB_ORIG_SIZE, IDC_RB_ED_WIN_SIZE, IDC_RB_ED_WIN_SIZE );

	NM_UPDOWN* pNMUpDown = (NM_UPDOWN*)pNMHDR;

	_TCHAR	buf[MAX_PATH];

	m_edWinSize.GetLine( 0, (LPTSTR)buf, MAX_PATH );
//	GetDlgItemText( IDC_ED_ED_WIN_SIZE, buf, MAX_PATH );

	double val = atof( buf ) + pNMUpDown->iDelta;

	val = val < 100 ? val : 100; // range checking
	val = val < 0   ? 0   : val;

	DoubleToAlphaString( val, 1, (LPTSTR)(LPCTSTR)buf );

	m_edWinSize.SetWindowText( (LPTSTR)(LPCTSTR)buf );
	
	*pResult = 0;
}//end of CAddPic::OnDeltaposSpnEdWin
////////////////////////////////////////////////////////////////////////////////////
void CAddPic::OnSetfocusEdEdWinSize() 
{
	CheckRadioButton( IDC_RB_ORIG_SIZE, IDC_RB_ED_WIN_SIZE, IDC_RB_ED_WIN_SIZE );
}//end of CAddPic::OnSetfocusEdEdWinSize
////////////////////////////////////////////////////////////////////////////////////
void CAddPic::OnOK() 
{
	m_ploi.inoutLoadSizeOption = GetCheckedRadioButton(IDC_RB_ORIG_SIZE, IDC_RB_ED_WIN_SIZE) - IDC_RB_ORIG_SIZE;

	_TCHAR	buf[MAX_PATH];
	m_edWinSize.GetLine( 0, (LPTSTR)buf, MAX_PATH );
	m_ploi.inoutPercentZoom = atof( buf );
	m_ploi.inoutPreserveImageAspect = m_ckPreAspect.GetCheck();
	m_ploi.inoutIncludeAlphaChannel = m_ckAChInclude.GetCheck();
	m_ploi.inoutInvertAlphaChannel  = m_ckAChInvert.GetCheck();
	m_ploi.inoutBlackTrim           = m_ckBlackTrim.GetCheck();
	m_ploi.inoutPositionSector_0_8  = GetCheckedRadioButton(IDC_RB_UL, IDC_RB_BR) - IDC_RB_UL;

	CGS_AcceptLoadPictureOptions( m_ploi.inFileName, &m_ploi );
	CDialog::OnOK();
}//end of OnOK
