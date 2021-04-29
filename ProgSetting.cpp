// ProgSetting.cpp : implementation file
//

#include "stdafx.h"
#include "cgui.h"
#include "ProgSetting.h"
#include "Global.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

extern _TCHAR	UILang_UIFont[256];
extern int		UILang_UIFontSize;
extern DWORD	g_CodePage;

/////////////////////////////////////////////////////////////////////////////
// CProgSetting dialog


CProgSetting::CProgSetting(CWnd* pParent /*=NULL*/)	: CDialog(CProgSetting::IDD, pParent)
{
	//{{AFX_DATA_INIT(CProgSetting)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	m_hFont = NULL;
}

CProgSetting::~CProgSetting()
{
	for( DWORD i = 0; i < m_numTxt; i++ )
	{
		if( m_hFont[i] != NULL )
			DeleteObject( (HGDIOBJ)m_hFont[i] );
	}
	if( m_hFont != NULL )
		delete [] m_hFont;
}

void CProgSetting::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CProgSetting)
	DDX_Control(pDX, IDC_CK_STYLE_SETTING, m_ckLastProj);
	DDX_Control(pDX, IDC_CK_LAST_PROJECT, m_ckStyleSet);
	DDX_Control(pDX, IDC_CB_KEYBOARD, m_cbKeyboard);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CProgSetting, CDialog)
	//{{AFX_MSG_MAP(CProgSetting)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CProgSetting message handlers

BOOL CProgSetting::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	HFONT hFont = NULL;

	InitDlgItemText();
	InitComboString( _T("\\Util\\DlgProgSetting.ctl"), _T("[Keyboards]"), &m_cbKeyboard );	
	m_cbKeyboard.SetCurSel( CGS_GetValInt(STATUS_PROGRAM_KEYBOARD) );
	m_ckStyleSet.SetCheck( CGS_GetValInt(STATUS_PROGRAM_RECALL_LAST_STYLE) );
	m_ckLastProj.SetCheck( CGS_GetValInt(STATUS_PROGRAM_RELOAD_LAST_PROJECT) );
	
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}//end of CProgSetting::OnInitDialog()

///////////////////////////////////////////////////////////////////////////////////////
VOID CProgSetting::InitDlgItemText()
{
	IN_TEXT_DATA* txtData = NULL;
	TCHAR	sep[] = _T("\"");
	TCHAR*	ptID;
	TCHAR*	ptTT;
	TCHAR*	ptEnd;

	m_numTxt = LoadTextFromCtl( "\\Util\\DlgProgSetting.ctl", "[Tooltip]", &txtData );
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
		
		if( NULL != _tcsstr( txtData[i].szTT, _T("IDD_DLG_PROG_SETTING") ))
		{
			txtData[i].idTT = IDD_DLG_PREFER;
			SetWindowText( (LPCTSTR)ptTT );
			goto SkipText;
		}
		else
			if( NULL != _tcsstr( txtData[i].szTT, _T("IDC_STC_KEYBOARD") ))
				txtData[i].idTT = IDC_STC_KEYBOARD;
		else
			if( NULL != _tcsstr( txtData[i].szTT, _T("IDC_STC_STARTUP") ))
				txtData[i].idTT = IDC_STC_STARTUP;
		else
			if( NULL != _tcsstr( txtData[i].szTT, _T("IDC_CK_STYLE_SETTING") ))
				txtData[i].idTT = IDC_CK_STYLE_SETTING;
		else
			if( NULL != _tcsstr( txtData[i].szTT, _T("IDC_CK_LAST_PROJECT") ))
				txtData[i].idTT = IDC_CK_LAST_PROJECT;
		else
			if( NULL != _tcsstr( txtData[i].szTT, _T("IDOK") ))
				txtData[i].idTT = IDOK;
		else
			if( NULL != _tcsstr( txtData[i].szTT, _T("IDCANCEL") ))
				txtData[i].idTT = IDCANCEL;

		SetDlgItemText( txtData[i].idTT, (LPCTSTR)ptTT );
SkipText:
		m_hFont[i] = ChangeControlFont( m_hWnd, NULL, UILang_UIFont,0, UILang_UIFontSize, FW_NORMAL);
	}//end of for

	free( txtData );
}//end of CProgSetting::InitDlgItemText()

//////////////////////////////////////////////////////////////////////////////////////////////////
//WAS
// CGS_KEYBOARD_AUTO		0
// CGS_KEYBOARD_ARABIC1		1
// CGS_KEYBOARD_ARABIC2		2
// CGS_KEYBOARD_CHINESE		3
// CGS_KEYBOARD_FARSI		4
// CGS_KEYBOARD_INDIC		5
// CGS_KEYBOARD_JAPANESE	6
// CGS_KEYBOARD_KOREAN		7
// CGS_KEYBOARD_THAI		8
// CGS_KEYBOARD_VIETNAMESE	9
/*NOW post 01-01-30 
#define CGS_KEYBOARD_AUTO 0
#define CGS_KEYBOARD_ARABIC1 1
#define CGS_KEYBOARD_CHINESE 2
#define CGS_KEYBOARD_FARSI1 3
#define CGS_KEYBOARD_FARSI2 4
#define CGS_KEYBOARD_INDIC 5
#define CGS_KEYBOARD_JAPANESE 6
#define CGS_KEYBOARD_KOREAN 7
#define CGS_KEYBOARD_THAI 8
#define CGS_KEYBOARD_VIETNAMESE 9
*/
// The sequence in ProgSetting.ctl file ++MUST++ match with the CGS_ValDefs.h file.
VOID CProgSetting::InitComboString(LPTSTR ptFn, LPTSTR ptSection, CComboBox *ptCombo)
{
	IN_TEXT_DATA* txtData = NULL;
	TCHAR	sep[] = _T("\"");
	TCHAR*	ptID;
	TCHAR*	ptTT;
	TCHAR*	ptEnd;

	CHAR	fn[MAX_PATH];
	CHAR	section[MAX_PATH];

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
}//end of CProgSetting::InitComboString
//////////////////////////////////////////////////////////////////////////////////////////////////
void CProgSetting::OnOK() 
{
	CGS_SetValInt( STATUS_PROGRAM_KEYBOARD, m_cbKeyboard.GetCurSel() );
	CGS_SetValInt( STATUS_PROGRAM_RECALL_LAST_STYLE, m_ckStyleSet.GetCheck() );
	CGS_SetValInt( STATUS_PROGRAM_RELOAD_LAST_PROJECT, m_ckLastProj.GetCheck() );
	CDialog::OnOK();
}//end of CProgSetting::OnOK
