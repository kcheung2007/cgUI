// TabSetup.cpp : implementation file
//

#include "stdafx.h"
#include "afxpriv.h"
#include "cgui.h"
#include "TabSetup.h"
#include "TabValue.h"
#include "ACGS_Inc\\CGServerDll.h"
#include "Global.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CTabSetup dialog
extern _TCHAR	UILang_UIFont[256];
extern int		UILang_UIFontSize;

CTabSetup::CTabSetup(CWnd* pParent /*=NULL*/) : CDialog(CTabSetup::IDD, pParent)
{
	//{{AFX_DATA_INIT(CTabSetup)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT

	m_hFont = NULL;
}//end of CTabSetup::CTabSetup
///////////////////////////////////////////////////////////////////////////////
CTabSetup::~CTabSetup()
{
	if( m_hFont != NULL )
	{
		for( DWORD i = 0; i < m_numTxt; i++ )
		{
			if( m_hFont[i] )
				DeleteObject( (HGDIOBJ)m_hFont[i] );
		}

		delete [] m_hFont;
	}//end of if 
}//end of CTabSetup::CTabSetup
///////////////////////////////////////////////////////////////////////////////
void CTabSetup::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CTabSetup)
	DDX_Control(pDX, IDC_RB_TAB10, m_rbTab10);
	DDX_Control(pDX, IDC_RB_TAB9, m_rbTab9);
	DDX_Control(pDX, IDC_RB_TAB8, m_rbTab8);
	DDX_Control(pDX, IDC_RB_TAB7, m_rbTab7);
	DDX_Control(pDX, IDC_RB_TAB6, m_rbTab6);
	DDX_Control(pDX, IDC_RB_TAB5, m_rbTab5);
	DDX_Control(pDX, IDC_RB_TAB4, m_rbTab4);
	DDX_Control(pDX, IDC_RB_TAB3, m_rbTab3);
	DDX_Control(pDX, IDC_RB_TAB2, m_rbTab2);
	DDX_Control(pDX, IDC_RB_TAB1, m_rbTab1);
	DDX_Control(pDX, IDC_RB_ALIGN_RIGHT, m_rbRight);
	DDX_Control(pDX, IDC_RB_ALIGN_LEFT, m_rbLeft);
	DDX_Control(pDX, IDC_RB_ALIGN_DECIMAL, m_rbDecimal);
	DDX_Control(pDX, IDC_RB_ALIGN_CENTER, m_rbCenter);
	DDX_Control(pDX, IDC_ED_POS, m_edPos);
	DDX_Control(pDX, IDC_BT_RESET, m_btReset);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CTabSetup, CDialog)
	//{{AFX_MSG_MAP(CTabSetup)
	ON_BN_CLICKED(IDC_RB_TAB1, OnRbTab1)
	ON_BN_CLICKED(IDC_RB_TAB2, OnRbTab2)
	ON_BN_CLICKED(IDC_RB_TAB3, OnRbTab3)
	ON_BN_CLICKED(IDC_RB_TAB4, OnRbTab4)
	ON_BN_CLICKED(IDC_RB_TAB5, OnRbTab5)
	ON_BN_CLICKED(IDC_RB_TAB6, OnRbTab6)
	ON_BN_CLICKED(IDC_RB_TAB7, OnRbTab7)
	ON_BN_CLICKED(IDC_RB_TAB8, OnRbTab8)
	ON_BN_CLICKED(IDC_RB_TAB9, OnRbTab9)
	ON_BN_CLICKED(IDC_RB_TAB10, OnRbTab10)
	ON_BN_CLICKED(IDC_RB_ALIGN_LEFT, OnRbAlignLeft)
	ON_BN_CLICKED(IDC_RB_ALIGN_CENTER, OnRbAlignCenter)
	ON_BN_CLICKED(IDC_RB_ALIGN_RIGHT, OnRbAlignRight)
	ON_BN_CLICKED(IDC_RB_ALIGN_DECIMAL, OnRbAlignDecimal)
	ON_NOTIFY(UDN_DELTAPOS, IDC_SPN_POS, OnDeltaposSpnPos)
	ON_BN_CLICKED(IDC_BT_RESET, OnBtReset)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

///////////////////////////////////////////////////////////////////////////////////////
// CTabSetup message handlers
///////////////////////////////////////////////////////////////////////////////////////
// Exit point, but not cancel button
void CTabSetup::OnOK() 
{
	TRACE0("TabSetup.cpp : OnOK\n");

	CGS_TabMenuExit();
	DestroyWindow();
}//end of CTabSetup::OnOK() 
//////////////////////////////////////////////////////////////////////////////////////
VOID CTabSetup::SetTabValObj(DWORD nTab, CTabValue *pTabValObj)
{
	DWORD	offset = 10; // offset between PAGE_TAB_0_PERCENT & PAGE_TAB_0_ALIGN

	double	pos		= CGS_GetValDbl( nTab );
	DWORD	alig	= (DWORD)CGS_GetValDbl( nTab + offset );

	pTabValObj->SetTabNum( nTab - PAGE_TAB_0_PERCENT ); 
	pTabValObj->SetAlignType( alig );
	pTabValObj->SetTabPos( pos );

}//end of CTabSetup::SetTabValObj
///////////////////////////////////////////////////////////////////////////////////////
VOID CTabSetup::UpdateTabSetupDlg(CTabValue *pTabValObj)
{
	CheckRadioButton( IDC_RB_TAB1, IDC_RB_TAB10, pTabValObj->GetTabNum() + IDC_RB_TAB1 );
	CheckRadioButton( IDC_RB_ALIGN_LEFT, IDC_RB_ALIGN_DECIMAL, pTabValObj->GetAlignType() +IDC_RB_ALIGN_LEFT );

	_TCHAR Buf[MAX_PATH];
	DoubleToAlphaString( pTabValObj->GetTabPos(), 2, Buf );
	m_edPos.SetWindowText( Buf );
}//end of CTabSetup::UpdateTabSetupDlg
///////////////////////////////////////////////////////////////////////////////////////
// Read all value from core, save into data object, set the GUI
BOOL CTabSetup::OnInitDialog() 
{
	CDialog::OnInitDialog();

	InitDlgItemText();

	CGS_TabMenuEnter( NULL );
	SetDlgPosition();

	for( int i = PAGE_TAB_0_PERCENT; i < PAGE_TAB_9_PERCENT+1; i++ )
		SetTabValObj( i, &m_initTabVal[i - PAGE_TAB_0_PERCENT] );

	SetTabValObj( PAGE_TAB_0_PERCENT, &m_curTabVal  );
	UpdateTabSetupDlg( &m_initTabVal[0] );

	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}//end of CTabSetup::OnInitDialog
//////////////////////////////////////////////////////////////////////////////////////
VOID CTabSetup::SetDlgPosition()
{
	int	dY = 15; // delta adjustment

	CenterWindow();

	CRect rcMain;
	AfxGetMainWnd()->GetWindowRect( rcMain );

	CRect rcDlg;
	GetWindowRect( rcDlg );

	int x = rcMain.bottom - rcDlg.bottom - dY; // dY is delta adjustment
	rcDlg.top += x;
	rcDlg.bottom += x;

	MoveWindow( &rcDlg, 1 );
}//end of CTabSetup::SetDlgPosition()
//////////////////////////////////////////////////////////////////////////////////////
// 1) Get the data of tab one from core, save to current tab object.
// 2) Update the GUI. Then ... waite for other input
void CTabSetup::OnRbTab1() 
{
	SetTabValObj( PAGE_TAB_0_PERCENT, &m_curTabVal );
	UpdateTabSetupDlg( &m_curTabVal );

	CGS_TabMenuSetCurrentTab( 0 );// highlight
	CGS_TabMenuRefreshWorkspace(); // call after every user change
}//end of CTabSetup::OnRbTab1
//////////////////////////////////////////////////////////////////////////////////////
// 1) Get the data of tab 2 from core, save to current tab object.
// 2) Update the GUI. Then ... waite for other input
void CTabSetup::OnRbTab2() 
{
	SetTabValObj( PAGE_TAB_1_PERCENT, &m_curTabVal );
	UpdateTabSetupDlg( &m_curTabVal );
	CGS_TabMenuSetCurrentTab( 1 );// highlight
	CGS_TabMenuRefreshWorkspace(); // call after every user change
}//end of CTabSetup::OnRbTab2
//////////////////////////////////////////////////////////////////////////////////////
// 1) Get the data of tab 3 from core, save to current tab object.
// 2) Update the GUI. Then ... waite for other input
void CTabSetup::OnRbTab3() 
{
	SetTabValObj( PAGE_TAB_2_PERCENT, &m_curTabVal );
	UpdateTabSetupDlg( &m_curTabVal );
	CGS_TabMenuSetCurrentTab( 2 );// highlight
	CGS_TabMenuRefreshWorkspace(); // call after every user change
}//end of CTabSetup::OnRbTab3
//////////////////////////////////////////////////////////////////////////////////////
// 1) Get the data of tab 4 from core, save to current tab object.
// 2) Update the GUI. Then ... waite for other input
void CTabSetup::OnRbTab4() 
{
	SetTabValObj( PAGE_TAB_3_PERCENT, &m_curTabVal );
	UpdateTabSetupDlg( &m_curTabVal );
	CGS_TabMenuSetCurrentTab( 3 );// highlight
	CGS_TabMenuRefreshWorkspace(); // call after every user change
}//end of CTabSetup::OnRbTab4
//////////////////////////////////////////////////////////////////////////////////////
// 1) Get the data of tab 5 from core, save to current tab object.
// 2) Update the GUI. Then ... waite for other input
void CTabSetup::OnRbTab5() 
{
	SetTabValObj( PAGE_TAB_4_PERCENT, &m_curTabVal );
	UpdateTabSetupDlg( &m_curTabVal );
	CGS_TabMenuSetCurrentTab( 4 );// highlight
	CGS_TabMenuRefreshWorkspace(); // call after every user change
}//end of CTabSetup::OnRbTab5
//////////////////////////////////////////////////////////////////////////////////////
// 1) Get the data of tab 6 from core, save to current tab object.
// 2) Update the GUI. Then ... waite for other input
void CTabSetup::OnRbTab6() 
{
	SetTabValObj( PAGE_TAB_5_PERCENT, &m_curTabVal );
	UpdateTabSetupDlg( &m_curTabVal );
	CGS_TabMenuSetCurrentTab( 5 );// highlight
	CGS_TabMenuRefreshWorkspace(); // call after every user change
}//end of CTabSetup::OnRbTab6
//////////////////////////////////////////////////////////////////////////////////////
// 1) Get the data of tab 7 from core, save to current tab object.
// 2) Update the GUI. Then ... waite for other input
void CTabSetup::OnRbTab7() 
{
	SetTabValObj( PAGE_TAB_6_PERCENT, &m_curTabVal );
	UpdateTabSetupDlg( &m_curTabVal );
	CGS_TabMenuSetCurrentTab( 6 );// highlight
	CGS_TabMenuRefreshWorkspace(); // call after every user change
}//end of CTabSetup::OnRbTab7
//////////////////////////////////////////////////////////////////////////////////////
// 1) Get the data of tab 8 from core, save to current tab object.
// 2) Update the GUI. Then ... waite for other input
void CTabSetup::OnRbTab8() 
{
	SetTabValObj( PAGE_TAB_7_PERCENT, &m_curTabVal );
	UpdateTabSetupDlg( &m_curTabVal );
	CGS_TabMenuSetCurrentTab( 7 );// highlight
	CGS_TabMenuRefreshWorkspace(); // call after every user change
}//end of CTabSetup::OnRbTab8
//////////////////////////////////////////////////////////////////////////////////////
void CTabSetup::OnRbTab9() 
{
	SetTabValObj( PAGE_TAB_8_PERCENT, &m_curTabVal );
	UpdateTabSetupDlg( &m_curTabVal );
	CGS_TabMenuSetCurrentTab( 8 );// highlight
	CGS_TabMenuRefreshWorkspace(); // call after every user change
}//end of CTabSetup::OnRbTab9
//////////////////////////////////////////////////////////////////////////////////////
void CTabSetup::OnRbTab10() 
{
	SetTabValObj( PAGE_TAB_9_PERCENT, &m_curTabVal );
	UpdateTabSetupDlg( &m_curTabVal );
	CGS_TabMenuSetCurrentTab( 9 );// highlight
	CGS_TabMenuRefreshWorkspace(); // call after every user change
}// end of CTabSetup::OnRbTab10()
//////////////////////////////////////////////////////////////////////////////////////
void CTabSetup::OnRbAlignLeft() 
{
	m_curTabVal.SetAlignType( CGS_TAB_ALIGN_LEFT );

	SetTabValToCore();
	CGS_TabMenuRefreshWorkspace(); // call after every user change
}//end of CTabSetup::OnRbAlignLeft
//////////////////////////////////////////////////////////////////////////////////////
void CTabSetup::OnRbAlignCenter() 
{
	m_curTabVal.SetAlignType( CGS_TAB_ALIGN_CENTER );

	SetTabValToCore();
	CGS_TabMenuRefreshWorkspace(); // call after every user change
}//end of CTabSetup::OnRbAlignCenter
//////////////////////////////////////////////////////////////////////////////////////
void CTabSetup::OnRbAlignRight() 
{
	m_curTabVal.SetAlignType( CGS_TAB_ALIGN_RIGHT );

	SetTabValToCore();
	CGS_TabMenuRefreshWorkspace(); // call after every user change
}//end of CTabSetup::OnRbAlignRight
//////////////////////////////////////////////////////////////////////////////////////
void CTabSetup::OnRbAlignDecimal() 
{
	m_curTabVal.SetAlignType( CGS_TAB_ALIGN_DECIMAL );

	SetTabValToCore();
	CGS_TabMenuRefreshWorkspace(); // call after every user change
}//end of CTabSetup::OnRbAlignDecimal
//////////////////////////////////////////////////////////////////////////////////////
// Set core from saved data object, update GUI
void CTabSetup::OnCancel() 
{
	for( int i = PAGE_TAB_9_PERCENT; -1 < i - PAGE_TAB_0_PERCENT; i-- )
	{
		memcpy( &m_curTabVal, &m_initTabVal[i - PAGE_TAB_0_PERCENT], sizeof(m_curTabVal) );
		SetTabValToCore();
	}
	UpdateTabSetupDlg( &m_initTabVal[0] );
	CGS_TabMenuSetCurrentTab( 0 );// highlight
	CGS_TabMenuRefreshWorkspace(); // call after every user change

}//end of CTabSetup::OnCancel
//////////////////////////////////////////////////////////////////////////////////////
void CTabSetup::OnDeltaposSpnPos(NMHDR* pNMHDR, LRESULT* pResult) 
{
	NM_UPDOWN* pNMUpDown = (NM_UPDOWN*)pNMHDR;
	// TODO: Add your control notification handler code here
	_TCHAR	buf[MAX_PATH];

	double val = m_curTabVal.GetTabPos() - pNMUpDown->iDelta;

	CGS_GetSpinControlNextValue( m_curTabVal.GetTabNum() + PAGE_TAB_0_PERCENT, - pNMUpDown->iDelta, &val );

	val = val < 100 ? val : 100; // range checking
	val = val < 0   ? 0   : val;

	m_curTabVal.SetTabPos( val );
	DoubleToAlphaString( val, 2, buf );
	m_edPos.SetWindowText( buf );

	SetTabValToCore();
	CGS_TabMenuRefreshWorkspace(); // call after every user change

	*pResult = 0;
}//end of CTabSetup::OnDeltaposSpnPos
//////////////////////////////////////////////////////////////////////////////////////
// Write the tab value to the core
// PAGE_TAB_0_PERCENT - 
// PAGE_TAB_0_ALIGN -
// CGS_TAB_ALIGN_LEFT -
VOID CTabSetup::SetTabValToCore()
{
	CGS_SetValDbl( m_curTabVal.GetTabNum() + PAGE_TAB_0_PERCENT, m_curTabVal.GetTabPos() );
	CGS_SetValDbl( m_curTabVal.GetTabNum() + PAGE_TAB_0_ALIGN, m_curTabVal.GetAlignType() );

}//end of CTabSetup::SetTabValToCore()
//////////////////////////////////////////////////////////////////////////////////////
void CTabSetup::OnBtReset() 
{
	CGS_TabMenuResetAll();
	
}//end of CTabSetup::OnBtReset
//////////////////////////////////////////////////////////////////////////////////////
VOID CTabSetup::InitDlgItemText()
{
	IN_TEXT_DATA* txtData = NULL;
	TCHAR	sep[] = _T("\"");
	TCHAR*	ptID;
	TCHAR*	ptTT;
	TCHAR*	ptEnd;

	m_numTxt = LoadTextFromCtl( "\\Util\\TabSetup.ctl", "[Tooltip]", &txtData );
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
		
		if( NULL != _tcsstr( txtData[i].szTT, _T("IDD_TAB_SETUP") ))
		{
			m_hFont[i] = ChangeControlFont( m_hWnd, NULL, UILang_UIFont,0, UILang_UIFontSize, FW_NORMAL);
			SetWindowText( (TCHAR*)ptTT );
		}
		else
			if( NULL != _tcsstr( txtData[i].szTT, _T("IDC_STC_ALIGN") ))
			{
				m_hFont[i] = ChangeControlFont( GetDlgItem(IDC_STC_ALIGN)->m_hWnd, NULL, UILang_UIFont,0, UILang_UIFontSize, FW_NORMAL);
				SetDlgItemText( IDC_STC_ALIGN, (TCHAR*)ptTT );
			}
		else
			if( NULL != _tcsstr( txtData[i].szTT, _T("IDC_RB_ALIGN_LEFT") ))
			{
				m_hFont[i] = ChangeControlFont( GetDlgItem(IDC_RB_ALIGN_LEFT)->m_hWnd, NULL, UILang_UIFont,0, UILang_UIFontSize, FW_NORMAL);
				SetDlgItemText( IDC_RB_ALIGN_LEFT, (TCHAR*)ptTT );
			}
		else
			if( NULL != _tcsstr( txtData[i].szTT, _T("IDC_RB_ALIGN_CENTER") ))
			{
				m_hFont[i] = ChangeControlFont( GetDlgItem(IDC_RB_ALIGN_CENTER)->m_hWnd, NULL, UILang_UIFont,0, UILang_UIFontSize, FW_NORMAL);
				SetDlgItemText( IDC_RB_ALIGN_CENTER, (TCHAR*)ptTT );
			}
		else
			if( NULL != _tcsstr( txtData[i].szTT, _T("IDC_RB_ALIGN_RIGHT") ))
			{
				m_hFont[i] = ChangeControlFont( GetDlgItem(IDC_RB_ALIGN_RIGHT)->m_hWnd, NULL, UILang_UIFont,0, UILang_UIFontSize, FW_NORMAL);
				SetDlgItemText( IDC_RB_ALIGN_RIGHT, (TCHAR*)ptTT );
			}
		else
			if( NULL != _tcsstr( txtData[i].szTT, _T("IDC_RB_ALIGN_DECIMAL") ))
			{
				m_hFont[i] = ChangeControlFont( GetDlgItem(IDC_RB_ALIGN_DECIMAL)->m_hWnd, NULL, UILang_UIFont,0, UILang_UIFontSize, FW_NORMAL);
				SetDlgItemText( IDC_RB_ALIGN_DECIMAL, (TCHAR*)ptTT );
			}
		else
			if( NULL != _tcsstr( txtData[i].szTT, _T("IDC_STC_POSITION") ))
			{
				m_hFont[i] = ChangeControlFont( GetDlgItem(IDC_STC_POSITION)->m_hWnd, NULL, UILang_UIFont,0, UILang_UIFontSize, FW_NORMAL);
				SetDlgItemText( IDC_STC_POSITION, (TCHAR*)ptTT );
			}
		else
			if( NULL != _tcsstr( txtData[i].szTT, _T("IDC_BT_RESET") ))
			{
				m_hFont[i] = ChangeControlFont( GetDlgItem(IDC_BT_RESET)->m_hWnd, NULL, UILang_UIFont,0, UILang_UIFontSize, FW_NORMAL);
				SetDlgItemText( IDC_BT_RESET, (TCHAR*)ptTT );
			}
		else
			if( NULL != _tcsstr( txtData[i].szTT, _T("IDOK") ))
			{
				m_hFont[i] = ChangeControlFont( GetDlgItem(IDOK)->m_hWnd, NULL, UILang_UIFont,0, UILang_UIFontSize, FW_NORMAL);
				SetDlgItemText( IDOK, (TCHAR*)ptTT );
			}
		else
			if( NULL != _tcsstr( txtData[i].szTT, _T("IDCANCEL") ))
			{
				m_hFont[i] = ChangeControlFont( GetDlgItem(IDCANCEL)->m_hWnd, NULL, UILang_UIFont,0, UILang_UIFontSize, FW_NORMAL);
				SetDlgItemText( IDCANCEL, (TCHAR*)ptTT );
			}
	}//end of for

	free( txtData );

}//end of CTabSetup::InitDlgItemText()
