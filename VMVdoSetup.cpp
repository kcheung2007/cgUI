// VMVdoSetup.cpp : implementation file
//

#include "stdafx.h"
#include "cgui.h"
#include "VMVdoSetup.h"
#include "Global.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CVMVdoSetup dialog
extern TCHAR	UILang_UIFont[256];
extern int		UILang_UIFontSize;
extern DWORD	g_CodePage;

CVMVdoSetup::CVMVdoSetup(CWnd* pParent /*=NULL*/) : CDialog(CVMVdoSetup::IDD, pParent)
{
	//{{AFX_DATA_INIT(CVMVdoSetup)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}

CVMVdoSetup::~CVMVdoSetup()
{
	for( DWORD i = 0; i < m_numTxt; i++ )
	{
		if( m_hFont[i] != NULL )
			DeleteObject( (HGDIOBJ)m_hFont[i] );

		m_hFont[i] = NULL;
	}
	if( m_hFont != NULL )
		delete [] m_hFont;
}
void CVMVdoSetup::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CVMVdoSetup)
	DDX_Control(pDX, IDC_CK_VDO_DEFRINGE, m_ckDefringe);
	DDX_Control(pDX, IDC_CK_ANTI_FLICKER, m_ckAntiFlicker);
	DDX_Control(pDX, IDC_CB_VDO_PREVIEW, m_cbVMPreview);
	DDX_Control(pDX, IDC_CB_VDO_OVERLAY, m_cbVMOverlay);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CVMVdoSetup, CDialog)
	//{{AFX_MSG_MAP(CVMVdoSetup)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CVMVdoSetup message handlers
BOOL CVMVdoSetup::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: Add extra initialization here
	HFONT hFont = NULL;

	InitDlgItemText();
	InitComboString( _T("\\Util\\VMVdoSetup.ctl"), _T("[Vdo Overlay]"), &m_cbVMOverlay );
	InitComboString( _T("\\Util\\VMVdoSetup.ctl"), _T("[Vdo Preview]"), &m_cbVMPreview );

	
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}//end of CVMVdoSetup::OnInitDialog
/////////////////////////////////////////////////////////////////////////////
VOID CVMVdoSetup::InitDlgItemText()
{
	IN_TEXT_DATA* txtData = NULL;
	TCHAR	sep[] = _T("\"");
	TCHAR*	ptID;
	TCHAR*	ptTT;
	TCHAR*	ptEnd;

	m_numTxt = LoadTextFromCtl( "\\Util\\VMVdoSetup.ctl", "[Tooltip]", &txtData );
	if( m_numTxt == 0 )
		return;

	m_hFont = new HFONT[m_numTxt];
	for( DWORD i = 0; i < m_numTxt; i++ )
	{
		ptID   = _tcstok( txtData[i].szTT, sep );
		ptTT   = _tcstok( NULL, sep );
		ptEnd  = _tcstok( NULL, sep );
		if( ptEnd != 0 )
			*ptEnd = '\0';

		if( NULL != _tcsstr( txtData[i].szTT, _T("IDD_VM_VDO_SETUP") ) )
		{
			m_hFont[i] = ChangeControlFont( m_hWnd, NULL, UILang_UIFont,0, UILang_UIFontSize, FW_NORMAL);
			SetWindowText( (LPCTSTR)ptTT );
		}
		else
			if( NULL != _tcsstr( txtData[i].szTT, _T("IDC_STC_VDO_OVERLAY") ) )
			{
				m_hFont[i] = ChangeControlFont( GetDlgItem(IDC_STC_VDO_OVERLAY)->m_hWnd, NULL, UILang_UIFont,0, UILang_UIFontSize, FW_NORMAL);
				SetDlgItemText( IDC_STC_VDO_OVERLAY, (LPCTSTR)ptTT );
			}
		else
			if( NULL != _tcsstr( txtData[i].szTT, _T("IDC_STC_VDO_PREVIEW") ) )
			{
				m_hFont[i] = ChangeControlFont( GetDlgItem(IDC_STC_VDO_PREVIEW)->m_hWnd, NULL, UILang_UIFont,0, UILang_UIFontSize, FW_NORMAL);
				SetDlgItemText( IDC_STC_VDO_PREVIEW, (LPCTSTR)ptTT );
			}
		else
			if( NULL != _tcsstr( txtData[i].szTT, _T("IDC_CK_VDO_DEFRINGE") ) )
			{
				m_hFont[i] = ChangeControlFont( GetDlgItem(IDC_CK_VDO_DEFRINGE)->m_hWnd, NULL, UILang_UIFont,0, UILang_UIFontSize, FW_NORMAL);
				SetDlgItemText( IDC_CK_VDO_DEFRINGE, (LPCTSTR)ptTT );
			}
		else
			if( NULL != _tcsstr( txtData[i].szTT, _T("IDC_CK_ANTI_FLICKER") ) )
			{
				m_hFont[i] = ChangeControlFont( GetDlgItem(IDC_CK_ANTI_FLICKER)->m_hWnd, NULL, UILang_UIFont,0, UILang_UIFontSize, FW_NORMAL);
				SetDlgItemText( IDC_CK_ANTI_FLICKER, (LPCTSTR)ptTT );
			}
		else
			if( NULL != _tcsstr( txtData[i].szTT, _T("IDOK") ) )
			{
				m_hFont[i] = ChangeControlFont( GetDlgItem(IDOK)->m_hWnd, NULL, UILang_UIFont,0, UILang_UIFontSize, FW_NORMAL);
				SetDlgItemText( IDOK, (LPCTSTR)ptTT );
			}
		else
			if( NULL != _tcsstr( txtData[i].szTT, _T("IDCANCEL") ) )
			{
				m_hFont[i] = ChangeControlFont( GetDlgItem(IDCANCEL)->m_hWnd, NULL, UILang_UIFont,0, UILang_UIFontSize, FW_NORMAL);
				SetDlgItemText( IDCANCEL, (LPCTSTR)ptTT );
			}
		else
			m_hFont[i] = NULL; // in case none of them fix
	}//end of for

	free( txtData );

}//end of CVMVdoSetup::InitDlgItemText()
///////////////////////////////////////////////////////////////////////////////////////////////////
VOID CVMVdoSetup::InitComboString(LPTSTR ptFn, LPTSTR ptSection, CComboBox *ptCombo)
{
	IN_TEXT_DATA* txtData = NULL;
	TCHAR	sep[] = _T("\"");
	TCHAR*	ptID;
	TCHAR*	ptTT;
	TCHAR*	ptEnd;

	CHAR		fn[MAX_PATH];
	CHAR		section[MAX_PATH];

	UnicodeToMultiByte( CP_ACP, ptFn, fn );
	UnicodeToMultiByte( CP_ACP, ptSection, section );
	DWORD numTxt = LoadTextFromCtl( fn, section, &txtData );
	if( numTxt == 0 )
		return;

	for( DWORD i = 0; i < numTxt; i++ )
	{
		ptID   = _tcstok( txtData[i].szTT, sep );
		ptTT   = _tcstok( NULL, sep );
		ptEnd  = _tcstok( NULL, sep );
		if( ptEnd != 0 )
			*ptEnd = '\0';

		ptCombo->AddString( (LPCTSTR)ptTT );		
	}//end of for
	ptCombo->SetCurSel( 0 );

	free( txtData );
}//end of CVMVdoSetup::InitComboString
///////////////////////////////////////////////////////////////////////////////////////////////////
// CHECK the combo box selection first and Check box 
VOID CVMVdoSetup::OnOK()
{
	CDialog::OnOK();
}//end of CVMVdoSetup::OnOK() 
