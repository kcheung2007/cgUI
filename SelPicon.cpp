// SelPicon.cpp : implementation file
//

#include "stdafx.h"
#include "cgui.h"
#include "SelPicon.h"
#include "Global.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CSelPicon dialog
extern _TCHAR	UILang_UIFont[256];
extern int		UILang_UIFontSize;

CSelPicon::CSelPicon(CWnd* pParent /*=NULL*/) : CDialog(CSelPicon::IDD, pParent)
{
	//{{AFX_DATA_INIT(CSelPicon)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void CSelPicon::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CSelPicon)
	DDX_Control(pDX, IDC_MOVE_RIGHT, m_btRight);
	DDX_Control(pDX, IDC_MOVE_LEFT, m_btLeft);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CSelPicon, CDialog)
	//{{AFX_MSG_MAP(CSelPicon)
	ON_BN_CLICKED(IDC_MOVE_LEFT, OnMoveLeft)
	ON_BN_CLICKED(IDC_MOVE_RIGHT, OnMoveRight)
	ON_BN_CLICKED(IDC_RB_SELECT, OnRbSelect)
	ON_BN_CLICKED(IDC_RB_SELECT_ALL, OnRbSelectAll)
	ON_BN_CLICKED(IDC_RB_SELECT_CLEAR, OnRbSelectClear)
	ON_BN_CLICKED(IDC_RB_SELECT_GFX, OnRbSelectGfx)
	ON_BN_CLICKED(IDC_RB_SELECT_TEXT, OnRbSelectText)
	ON_BN_CLICKED(IDC_RB_UNSELECT, OnRbUnselect)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CSelPicon message handlers

void CSelPicon::OnMoveLeft() 
{
	// TODO: Add your control notification handler code here
	
}

void CSelPicon::OnMoveRight() 
{
	// TODO: Add your control notification handler code here
	
}

void CSelPicon::OnRbSelect() 
{
	// TODO: Add your control notification handler code here
	
}

void CSelPicon::OnRbSelectAll() 
{
	// TODO: Add your control notification handler code here
	
}

void CSelPicon::OnRbSelectClear() 
{
	// TODO: Add your control notification handler code here
	
}

void CSelPicon::OnRbSelectGfx() 
{
	// TODO: Add your control notification handler code here
	
}

void CSelPicon::OnRbSelectText() 
{
	// TODO: Add your control notification handler code here
	
}

void CSelPicon::OnRbUnselect() 
{
	// TODO: Add your control notification handler code here
	
}

BOOL CSelPicon::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: Add extra initialization here
	//++++++++++++++++++++++++++++++++++++++++Create the ToolTip control.
	m_tooltip.Create(this);
	m_tooltip.Activate(TRUE);

	InitDlgItemText();

	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

BOOL CSelPicon::PreTranslateMessage(MSG* pMsg)
{
	// CG: The following block was added by the ToolTips component.
	{
		// Let the ToolTip process this message.
		m_tooltip.RelayEvent(pMsg);
	}
	return CDialog::PreTranslateMessage(pMsg);	// CG: This was added by the ToolTips component.
}



VOID CSelPicon::InitDlgItemText()
{
	IN_TEXT_DATA* txtData = NULL;
	TCHAR	sep[] = _T("\"");
	TCHAR*	ptID;
	TCHAR*	ptTT;
	TCHAR*	ptEnd;
	HFONT	hFont = NULL;

	DWORD numTxt = LoadTextFromCtl( "\\Util\\SelPicon.ctl", "[Tooltip]", &txtData );
	if( numTxt == 0 )
		return;

	for( DWORD i = 0; i < numTxt; i++ )
	{
		ptID   = _tcstok( txtData[i].szTT, sep );
		ptTT   = _tcstok( NULL, sep );
		ptEnd  = _tcstok( NULL, sep );
		if( ptEnd != 0 )
			*ptEnd = '\0';

		if( NULL != _tcsstr( txtData[i].szTT, _T("IDD_DLG_ICON_SELECT") ) )
		{
			txtData[i].idTT = IDD_DLG_ICON_SELECT;			
			ChangeControlFont( m_hWnd, hFont, UILang_UIFont,0, UILang_UIFontSize, FW_NORMAL);
			SetWindowText( (LPCTSTR)ptTT );
		}
		else
			if( NULL != _tcsstr( txtData[i].szTT, _T("IDC_RB_UNSELECT") ) )
				txtData[i].idTT = IDC_RB_UNSELECT;
		else
			if( NULL != _tcsstr( txtData[i].szTT, _T("IDC_RB_SELECT_ALL") ) )
				txtData[i].idTT = IDC_RB_SELECT_ALL;
		else
			if( NULL != _tcsstr( txtData[i].szTT, _T("IDC_RB_SELECT_GFX") ) )
				txtData[i].idTT = IDC_RB_SELECT_GFX;
		else
			if( NULL != _tcsstr( txtData[i].szTT, _T("IDC_RB_SELECT_TEXT") ) )
				txtData[i].idTT = IDC_RB_SELECT_TEXT;
		else
			if( NULL != _tcsstr( txtData[i].szTT, _T("IDC_RB_SELECT_CLEAR") ) )
				txtData[i].idTT = IDC_RB_SELECT_CLEAR;
		else
			if( NULL != _tcsstr( txtData[i].szTT, _T("IDC_RB_SELECT") ) )
				txtData[i].idTT = IDC_RB_SELECT;
		else
			if( NULL != _tcsstr( txtData[i].szTT, _T("IDOK") ) )
				txtData[i].idTT = IDOK;
		else
			if( NULL != _tcsstr( txtData[i].szTT, _T("IDCANCEL") ) )
				txtData[i].idTT = IDCANCEL;

		SetDlgItemText( txtData[i].idTT, (LPCTSTR)ptTT );

		if( txtData[i].idTT != IDD_DLG_ICON_SELECT )
			ChangeControlFont( GetDlgItem(txtData[i].idTT)->m_hWnd, hFont, UILang_UIFont,0, UILang_UIFontSize, FW_NORMAL);
	}//end of for

	free( txtData );
}//end of CSelPicon::InitDlgItemText()
