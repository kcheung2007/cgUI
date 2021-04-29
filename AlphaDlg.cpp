// AlphaDlg.cpp : implementation file
//

#include "stdafx.h"
#include "cgui.h"
#include "AlphaDlg.h"
#include "Global.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

extern	DWORD	g_CodePage;
extern	TCHAR   g_szAppPath[_MAX_PATH];
/////////////////////////////////////////////////////////////////////////////
// CAlphaDlg dialog
/////////////////////////////////////////////////////////////////////////////
CAlphaDlg::CAlphaDlg(CWnd* pParent /*=NULL*/): CDialog(CAlphaDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CAlphaDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void CAlphaDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CAlphaDlg)
	DDX_Control(pDX, IDOK, m_btOK);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CAlphaDlg, CDialog)
	//{{AFX_MSG_MAP(CAlphaDlg)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CAlphaDlg message handlers
/////////////////////////////////////////////////////////////////////////////
BOOL CAlphaDlg::OnInitDialog() 
{
	CHAR	fn[MAX_PATH];
	CHAR	buf[MAX_PATH];	
	CHAR	strPath[MAX_PATH];

	CDialog::OnInitDialog();
	
	CWnd* pRightBar = AfxGetMainWnd()->GetDlgItem( IDD_DLGBAR_BINTOP );
	CWnd* pLowBin   = pRightBar->GetDlgItem( IDC_LIST_BOT_BIN );

	CRect	rc;
	pLowBin->GetWindowRect( &rc );

	MoveWindow( rc.left-rc.Width(), rc.top, rc.Width(), rc.Height(), 1 );
	GetWindowRect( &rc );
	m_btOK.SetWindowPos( NULL, 0, 0, rc.Width()-5, rc.Height()-20, SWP_SHOWWINDOW );

// set text string
	UnicodeToMultiByte( g_CodePage, g_szAppPath, strPath );
	strcpy( fn, strPath );
	strcat( fn, "\\Util\\message.ctl" );
	acgReadLine( (LPCSTR)fn, "M0001", buf ); // parse title

	TCHAR	swMsg[MAX_PATH];
	MultiByteToUnicode( g_CodePage, buf, swMsg );
	CString msgStr( swMsg );
	int index = msgStr.FindOneOf( _T("\"") );
	msgStr = msgStr.Mid( index+1 );
	index = msgStr.FindOneOf( _T("\"") );
	msgStr.SetAt( index, _T('\0') );
	msgStr.Replace( _T('_'), _T('\n') );

	m_btOK.SetWindowText( msgStr );

	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}//end of CAlphaDlg::OnInitDialog
/////////////////////////////////////////////////////////////////////////////
void CAlphaDlg::OnOK() 
{
	AfxGetMainWnd()->SetFocus();
}//end of OnOK
/////////////////////////////////////////////////////////////////////////////
