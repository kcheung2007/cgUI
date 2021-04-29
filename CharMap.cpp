// CharMap.cpp : implementation file
//

#include "stdafx.h"
#include "cgui.h"
#include "CharMap.h"
#include "ImgCharMap.h"
#include "Global.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CCharMap dialog

extern TCHAR UILang_UIFont[256];
extern int	 UILang_UIFontSize;

CCharMap::CCharMap(CWnd* pParent /*=NULL*/)	: CDialog(CCharMap::IDD, pParent)
{
	//{{AFX_DATA_INIT(CCharMap)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT

	m_hFont = NULL;
}

CCharMap::~CCharMap()
{
	for( DWORD i = 0; i < m_numTxt; i++ )
	{
		if( m_hFont[i] != NULL )
			DeleteObject( (HGDIOBJ)m_hFont[i] );
	}
	if( m_hFont != NULL )
		delete [] m_hFont;
}

void CCharMap::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CCharMap)
	DDX_Control(pDX, IDC_SB_CHAR_MAP, m_vsbCharMap);
	DDX_Control(pDX, IDC_BT_UP, m_btUp);
	DDX_Control(pDX, IDC_BT_RIGHT, m_btRight);
	DDX_Control(pDX, IDC_BT_LEFT, m_btLeft);
	DDX_Control(pDX, IDC_BT_DOWN, m_btDown);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CCharMap, CDialog)
	//{{AFX_MSG_MAP(CCharMap)
	ON_BN_CLICKED(IDC_BT_BACKSPACE, OnBtBackspace)
	ON_BN_CLICKED(IDC_BT_DELETE, OnBtDelete)
	ON_BN_CLICKED(IDC_BT_ENTER, OnBtEnter)
	ON_BN_CLICKED(IDC_BT_LEFT, OnBtLeft)
	ON_BN_CLICKED(IDC_BT_RIGHT, OnBtRight)
	ON_BN_CLICKED(IDC_BT_UP, OnBtUp)
	ON_BN_CLICKED(IDC_BT_DOWN, OnBtDown)
	ON_WM_VSCROLL()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CCharMap message handlers
/////////////////////////////////////////////////////////////////////////////
// NOTE : The size of character map dialog is fixed to 480 x 80 dlg units.
BOOL CCharMap::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: Add extra initialization here
	const int x = 120;	// x position for 1024 x 768 only
	const int y = 575;	// y position for 1024 x 768 only
	SetWindowPos( NULL, 120, 575, 0, 0, SWP_NOSIZE );

	m_imgCharMap.SubclassDlgItem( IDC_LIST_CHAR_MAP, this );
	
	//++++++++++++++++++ Initial radio button and Icon
	HINSTANCE hInst = AfxGetApp()->m_hInstance;
	m_btUp.SetIcon( (HICON)::LoadImage( hInst,MAKEINTRESOURCE(IDI_DIR_UP), IMAGE_ICON, 16, 16, 0) );
	m_btDown.SetIcon( (HICON)::LoadImage( hInst,MAKEINTRESOURCE(IDI_DIR_DOWN), IMAGE_ICON, 16, 16, 0) );
	m_btLeft.SetIcon( (HICON)::LoadImage( hInst,MAKEINTRESOURCE(IDI_DIR_LEFT), IMAGE_ICON, 16, 16, 0) );
	m_btRight.SetIcon( (HICON)::LoadImage( hInst,MAKEINTRESOURCE(IDI_DIR_RIGHT), IMAGE_ICON, 16, 16, 0) );

	//++++++++++++++++++ Initial vertical scroll bar
	m_vsbCharMap.SetScrollRange( 1, 128 );	// default range 0 .. 127
	m_vsbCharMap.SetScrollPos( 1 );			// default position

	InitDlgItemText();

	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}//end of CCharMap::OnInitDialog
/////////////////////////////////////////////////////////////////////////////
void CCharMap::OnBtBackspace() 
{
	// TODO: Add your control notification handler code here
	
}//end of CCharMap::OnBtBackspace
/////////////////////////////////////////////////////////////////////////////
void CCharMap::OnBtDelete() 
{
	// TODO: Add your control notification handler code here
	
}//end of CCharMap::OnBtDelete
/////////////////////////////////////////////////////////////////////////////
void CCharMap::OnBtEnter() 
{
	// TODO: Add your control notification handler code here
	
}//end of CCharMap::OnBtEnter
/////////////////////////////////////////////////////////////////////////////
void CCharMap::OnBtLeft() 
{
	// TODO: Add your control notification handler code here
	
}//end of CCharMap::OnBtLeft
/////////////////////////////////////////////////////////////////////////////
void CCharMap::OnBtRight() 
{
	// TODO: Add your control notification handler code here
	
}//end of CCharMap::OnBtRight
/////////////////////////////////////////////////////////////////////////////
void CCharMap::OnBtUp() 
{
	// TODO: Add your control notification handler code here
	
}//end of CCharMap::OnBtUp
/////////////////////////////////////////////////////////////////////////////
void CCharMap::OnBtDown() 
{
	// TODO: Add your control notification handler code here
	
}//end of CCharMap::OnBtDown
/////////////////////////////////////////////////////////////////////////////
void CCharMap::OnOK() 
{
	CDialog::OnOK();
}//end of CCharMap::OnOK
/////////////////////////////////////////////////////////////////////////////
void CCharMap::OnCancel() 
{
	CDialog::OnCancel();
}//end of CCharMap::OnCancel
/////////////////////////////////////////////////////////////////////////////
void CCharMap::OnVScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar) 
{
	// TODO: Add your message handler code here and/or call default
	int nCurPos = pScrollBar->GetScrollPos();
	switch( nSBCode )
	{
	case SB_TOP:			// Scroll to far top.
		nCurPos = 1;
		break;
	case SB_LINEUP:			// Scroll one line up.
		nCurPos--;
		break;
	case SB_LINEDOWN:		// Scroll one line down.
		nCurPos++;
		break;
	case SB_PAGEUP:			// Scroll one page up.
		nCurPos -= 100;
		break;
	case SB_PAGEDOWN:		// Scroll one page down.
		nCurPos += 10;
		break;
	case SB_BOTTOM:			// Scroll to far bottom.
		nCurPos = 1000;
		break;
	case SB_THUMBPOSITION:	// Scroll to absolute position. 
	case SB_THUMBTRACK:		// Drag scroll box to specified position. 
		nCurPos = nPos;
		break;
	case SB_ENDSCROLL:		// End scroll
		TRACE0( "CharMap.cpp : OnVScroll - End scroll\n" );
		break;
	}//end of switch - nSBCode

	nCurPos = ( nCurPos < 1 ) ? 1 : nCurPos;
	nCurPos = ( 128 < nCurPos ) ? 128 : nCurPos;

	pScrollBar->SetScrollPos(nCurPos);

	if( pScrollBar == (CScrollBar*)GetDlgItem(IDC_SB_CHAR_MAP) )
	{	
		;// call CharMapScrollPos( nCurPos );
	}
	
	CDialog::OnVScroll(nSBCode, nPos, pScrollBar);
}//end of CCharMap::OnVScroll
/////////////////////////////////////////////////////////////////////////////
VOID CCharMap::InitDlgItemText()
{
	IN_TEXT_DATA* txtData = NULL;
	TCHAR	sep[] = _T("\"");
	TCHAR*	ptID;
	TCHAR*	ptTT;
	TCHAR*	ptEnd;

	m_numTxt = LoadTextFromCtl( "\\Util\\CharMap.ctl", "[Tooltip]", &txtData );
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
		
		if( NULL != _tcsstr( txtData[i].szTT, _T("IDD_DLG_CHAR_MAP") ))
		{
			txtData[i].idTT = IDD_DLG_CHAR_MAP;
			SetWindowText( (LPCTSTR)ptTT );
			goto SkipText;
		}
		else
			if( NULL != _tcsstr( txtData[i].szTT, _T("IDC_BT_BACKSPACE") ))
				txtData[i].idTT = IDC_BT_BACKSPACE;
		else
			if( NULL != _tcsstr( txtData[i].szTT, _T("IDC_BT_DELETE") ))
				txtData[i].idTT = IDC_BT_DELETE;
		else
			if( NULL != _tcsstr( txtData[i].szTT, _T("IDC_BT_ENTER") ))
				txtData[i].idTT = IDC_BT_ENTER;
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
}//end of CCharMap::InitDlgItemText()
