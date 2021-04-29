/* COPYRIGHT NOTICE:
********************************************************
*  Copyright (c) 2000 InnoVision Technology, Inc.      *
*  All rights reserved.                                *
*  PROPRIETARY AND CONFIDENTIAL                        *
*  DO NOT DISTRIBUTE                                   *
********************************************************
*/
// SpellCheck.cpp : implementation file
//

#include "stdafx.h"
#include "cgui.h"
#include "Global.h"
#include "SpellCheck.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CSpellCheck dialog
extern _TCHAR	UILang_UIFont[256];
extern int		UILang_UIFontSize;


CSpellCheck::CSpellCheck(CWnd* pParent /*=NULL*/) : CDialog(CSpellCheck::IDD, pParent)
{
	//{{AFX_DATA_INIT(CSpellCheck)
	m_edChangeTo = _T("");
	m_edOrigWord = _T("");
	//}}AFX_DATA_INIT
	m_Done  = 0;
	m_hFont = NULL;
}
CSpellCheck::~CSpellCheck()
{
	for( DWORD i = 0; i < m_numTxt; i++ )
	{
		if( m_hFont[i] )
			DeleteObject( (HGDIOBJ)m_hFont[i] );
	}

	if( m_hFont != NULL )
		delete [] m_hFont;

}

void CSpellCheck::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CSpellCheck)
	DDX_Control(pDX, IDOK, m_btOK);
	DDX_Control(pDX, IDCANCEL, m_btCancel);
	DDX_Control(pDX, IDC_STC_DONE_MSG, m_stcDoneMsg);
	DDX_Control(pDX, IDC_STC_ALTER_SPELL, m_stcAlterSpell);
	DDX_Control(pDX, IDC_STC_ORIGINAL_WORD, m_stcOrigWord);
	DDX_Control(pDX, IDC_STC_CHANGE_TO, m_stcChangeTo);
	DDX_Control(pDX, IDC_LB_ALTER_SPELL, m_lbAlterSpell);
	DDX_Text(pDX, IDC_ED_CHANGE_TO, m_edChangeTo);
	DDX_Text(pDX, IDC_ED_ORIGINAL_WORD, m_edOrigWord);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CSpellCheck, CDialog)
	//{{AFX_MSG_MAP(CSpellCheck)
	ON_BN_CLICKED(IDC_BT_ADD, OnBtAdd)
	ON_BN_CLICKED(IDC_BT_IGNORE, OnBtIgnore)
	ON_BN_CLICKED(IDC_BT_REPLACE, OnBtReplace)
	ON_LBN_DBLCLK(IDC_LB_ALTER_SPELL, OnDblclkLbAlterSpell)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////////////////
// CSpellCheck message handlers
/////////////////////////////////////////////////////////////////////////////////////////
void CSpellCheck::OnBtAdd() 
{
	// Tesing purpose only
	m_Done = 1; 
	m_btCancel.EnableWindow( 0 );
	if( m_Done )
	{
		m_stcDoneMsg.ShowWindow( SW_SHOW );
		m_btOK.EnableWindow( 1 );
	}
	// end of testing 
	
}//end of CSpellCheck::OnBtAdd
/////////////////////////////////////////////////////////////////////////////////////////
void CSpellCheck::OnBtIgnore() 
{
	// TODO: Add your control notification handler code here

	
}//end of CSpellCheck::OnBtIgnore
/////////////////////////////////////////////////////////////////////////////////////////
void CSpellCheck::OnBtReplace() 
{
	// TODO: Add your control notification handler code here
	
}//end of CSpellCheck::OnBtReplace
/////////////////////////////////////////////////////////////////////////////////////////
void CSpellCheck::OnDblclkLbAlterSpell() 
{
	// TODO: Add your control notification handler code here
	
}//end of CSpellCheck::OnDblclkLbAlterSpell() 
/////////////////////////////////////////////////////////////////////////////////////////
BOOL CSpellCheck::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: Add extra initialization here
	InitDlgItemText();
	m_btOK.EnableWindow( 0 );
	m_btCancel.EnableWindow( 1 );
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}//end of CSpellCheck::OnInitDialog
/////////////////////////////////////////////////////////////////////////////////////////
VOID CSpellCheck::InitDlgItemText()
{
	IN_TEXT_DATA* txtData = NULL;
	TCHAR	sep[] = _T("\"");
	TCHAR*	ptID;
	TCHAR*	ptTT;
	TCHAR*	ptEnd;

	m_numTxt = LoadTextFromCtl( "\\Util\\SpellCheck.ctl", "[Tooltip]", &txtData );
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
		
		if( NULL != _tcsstr( txtData[i].szTT, _T("IDD_DLG_SPELL_CHECKER") ))
		{
			txtData[i].idTT = IDD_DLG_SPELL_CHECKER;
			SetWindowText( (LPCTSTR)ptTT );
			goto SkipText;
		}
		else
			if( NULL != _tcsstr( txtData[i].szTT, _T("IDC_STC_ORIGINAL_WORD") ))
				txtData[i].idTT = IDC_STC_ORIGINAL_WORD;
		else
			if( NULL != _tcsstr( txtData[i].szTT, _T("IDC_STC_CHANGE_TO") ))
				txtData[i].idTT = IDC_STC_CHANGE_TO;
		else
			if( NULL != _tcsstr( txtData[i].szTT, _T("IDC_STC_ALTER_SPELL") ))
				txtData[i].idTT = IDC_STC_ALTER_SPELL;
		else
			if( NULL != _tcsstr( txtData[i].szTT, _T("IDC_BT_REPLACE") ))
				txtData[i].idTT = IDC_BT_REPLACE;
		else
			if( NULL != _tcsstr( txtData[i].szTT, _T("IDC_BT_IGNORE") ))
				txtData[i].idTT = IDC_BT_IGNORE;
		else
			if( NULL != _tcsstr( txtData[i].szTT, _T("IDC_BT_ADD") ))
				txtData[i].idTT = IDC_BT_ADD;
		else
			if( NULL != _tcsstr( txtData[i].szTT, _T("IDCANCEL") ))
				txtData[i].idTT = IDCANCEL;
		else
			if( NULL != _tcsstr( txtData[i].szTT, _T("IDOK") ))
				txtData[i].idTT = IDOK;
		else
			if( NULL != _tcsstr( txtData[i].szTT, _T("IDC_STC_DONE_MSG") ))
				txtData[i].idTT = IDC_STC_DONE_MSG;

		SetDlgItemText( txtData[i].idTT, (LPCTSTR)ptTT );
SkipText:
		m_hFont[i] = ChangeControlFont( m_hWnd, NULL, UILang_UIFont,0, UILang_UIFontSize, FW_NORMAL);
	}//end of for

	free( txtData );

}//end of CSpellCheck::InitDlgItemText()
/////////////////////////////////////////////////////////////////////////////////////////
void CSpellCheck::OnCancel() 
{
	CDialog::OnCancel();
}//end of OnCancel
/////////////////////////////////////////////////////////////////////////////////////////
void CSpellCheck::OnOK() 
{
	CDialog::OnOK();
}//end of OnOK
