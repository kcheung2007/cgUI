// PgTemplate.cpp : implementation file
//

#include "stdafx.h"
#include "cgui.h"
#include "PgTemplate.h"
#include "FileReq.h"
#include "Global.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CPgTemplate dialog


CPgTemplate::CPgTemplate(CWnd* pParent /*=NULL*/) : CDialog(CPgTemplate::IDD, pParent)
{
	//{{AFX_DATA_INIT(CPgTemplate)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	m_hFont = NULL;
}

CPgTemplate::~CPgTemplate()
{
	for( DWORD i = 0; i < m_numTxt; i++ )
	{
		if( m_hFont[i] != NULL )
			DeleteObject( (HGDIOBJ)m_hFont[i] );
	}
	if( m_hFont != NULL )
		delete [] m_hFont;
}//end of destructor

void CPgTemplate::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CPgTemplate)
	DDX_Control(pDX, IDC_BT_SAVE_TEMPLATE, m_btSaveTemplate);
	DDX_Control(pDX, IDC_VSB_VERT, m_vScrollBar);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CPgTemplate, CDialog)
	//{{AFX_MSG_MAP(CPgTemplate)
	ON_WM_VSCROLL()
	ON_BN_CLICKED(IDC_BT_SAVE_TEMPLATE, OnBtSaveTemplate)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CPgTemplate message handlers
/////////////////////////////////////////////////////////////////////////////
void CPgTemplate::OnOK() 
{	
	// capture OK message
}//end of CPgTemplate::OnOK() 
/////////////////////////////////////////////////////////////////////////////
void CPgTemplate::OnCancel() 
{
	// capture cancel message
}//end of CPgTemplate::OnCancel() 
/////////////////////////////////////////////////////////////////////////////
BOOL CPgTemplate::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	m_vScrollBar.SetScrollRange( 1, 1000 ); //default range
	m_btSaveTemplate.SetIcon( (HICON)::LoadImage( AfxGetApp()->m_hInstance,MAKEINTRESOURCE(IDI_EXPORT_PAGE), IMAGE_ICON, 16, 16, 0) );

	// Create the ToolTip control.
	m_tooltip.Create(this);
	m_tooltip.Activate(TRUE);

	InitDlgItemTextNTooltip();

	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}//end of CPgTemplate::OnInitDialog() 
/////////////////////////////////////////////////////////////////////////////
void CPgTemplate::OnVScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar) 
{
	ASSERT(pScrollBar != NULL);

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
		TRACE0( "DlgPage.cpp : OnVScroll - End scroll\n" );
		break;
	}//end of switch - nSBCode

	nCurPos = ( nCurPos < 1 ) ? 1 : nCurPos;
	nCurPos = ( 1000 < nCurPos ) ? 1000 : nCurPos;

	pScrollBar->SetScrollPos(nCurPos);

//  TO DO : Pass value to core logic, eg followed
//	CGS_BinScroll(UIBIN_PAGE,(double) ((double)nCurPos) / (1000.0f) ); 
	
	CDialog::OnVScroll(nSBCode, nPos, pScrollBar);
}//end of CPgTemplate::OnVScroll
/////////////////////////////////////////////////////////////////////////////
void CPgTemplate::OnBtSaveTemplate() 
{
	FILE_REQ_FOLDER_INFO	tmpFRD; // Get from core
	ZeroMemory( &tmpFRD, sizeof(tmpFRD) );

	tmpFRD.nFileType = FILE_CATEGORY_TEMPLATE;
	CGS_GetFileCategoryPathInfo( &tmpFRD );

	tmpFRD.opt = SAVE_OP;
	_tcscpy( tmpFRD.DlgTitle, _T("Save Template") );
	if( !FileRequestDlg(&tmpFRD, FILE_CATEGORY_TEMPLATE) )
		return;

//  TO DO : Pass value to core logic, eg followed
//	CGS_ApplyPictureTextureMap( tmpFRD.CompleteFileName, EDIT_OBJ_FACE_COLORSCHEME );

	AfxGetMainWnd()->SetFocus();	
}//end of CPgTemplate::OnBtSaveTemplate
/////////////////////////////////////////////////////////////////////////////
BOOL CPgTemplate::PreTranslateMessage(MSG* pMsg)
{
	// Let the ToolTip process this message.
	m_tooltip.RelayEvent(pMsg);

	return CDialog::PreTranslateMessage(pMsg);	// CG: This was added by the ToolTips component.
}//end of CPgTemplate::PreTranslateMessage(MSG* pMsg)
/////////////////////////////////////////////////////////////////////////////
VOID CPgTemplate::InitDlgItemTextNTooltip()
{
	HFONT hFont = NULL;
	IN_TEXT_DATA* txtData = NULL;
	TCHAR	sep[] = _T("\"");
	TCHAR*	ptID;
	TCHAR*	ptTT;
	TCHAR*	ptEnd;

	m_numTxt = LoadTextFromCtl( "\\Util\\DlgTemplate.ctl", "[Tooltip]", &txtData );
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

		if( NULL != _tcsstr( txtData[i].szTT, _T("IDC_BT_SAVE_TEMPLATE") ) )
			txtData[i].idTT = IDC_BT_SAVE_TEMPLATE;
		else
			if( NULL != _tcsstr( txtData[i].szTT, _T("IDC_VSB_VERT") ) )
				txtData[i].idTT = IDC_VSB_VERT;

/*** set text only
		SetDlgItemText( txtData[i].idTT, (LPCTSTR)ptTT );
		m_hFont[i] = ChangeControlFont( GetDlgItem(txtData[i].idTT)->m_hWnd, NULL, UILang_UIFont,0, UILang_UIFontSize, FW_NORMAL);
SKIP_TEXT:
*** set text only ***/
		_tcscpy( txtData[i].szTT, (TCHAR*)txtData[i].szTT );
		if( NULL != GetDlgItem(txtData[i].idTT) )
			m_tooltip.AddTool( GetDlgItem(txtData[i].idTT), (_TCHAR*)ptTT);
	}//end of for

	free( txtData );

}//end of CPgTemplate::InitDlgItemTextNTooltip()
