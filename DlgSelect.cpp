// DlgSelect.cpp : implementation file
//

#include "stdafx.h"
#include "cgui.h"
#include "DlgSelect.h"
#include "Global.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

extern TCHAR	UILang_UIFont[256];
extern int		UILang_UIFontSize;

/////////////////////////////////////////////////////////////////////////////
// CDlgSelect dialog


CDlgSelect::CDlgSelect(CWnd* pParent /*=NULL*/): CDialog(CDlgSelect::IDD, pParent)
{
	//{{AFX_DATA_INIT(CDlgSelect)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	m_hFont = NULL;
}
CDlgSelect::~CDlgSelect()
{
	for( DWORD i = 0; i < m_numTxt; i++ )
	{
		if( m_hFont[i] != NULL )
			DeleteObject( (HGDIOBJ)m_hFont[i] );
	}
	if( m_hFont != NULL )
		delete [] m_hFont;
}

void CDlgSelect::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDlgSelect)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CDlgSelect, CDialog)
	//{{AFX_MSG_MAP(CDlgSelect)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDlgSelect message handlers
/////////////////////////////////////////////////////////////////////////////
void CDlgSelect::OnOK() 
{	
	// capture OK message
}//end of CDlgSelect::OnOK
/////////////////////////////////////////////////////////////////////////////
void CDlgSelect::OnCancel() 
{
	// capture cancel message
}//end of CDlgSelect::OnCancel() 
/////////////////////////////////////////////////////////////////////////////
VOID CDlgSelect::InitDlgItemTextNTooltip()
{
	IN_TEXT_DATA* txtData = NULL;
	TCHAR	sep[] = _T("\"");
	TCHAR*	ptID;
	TCHAR*	ptTT;
	TCHAR*	ptEnd;

	m_numTxt = LoadTextFromCtl( "\\Util\\DlgSelect.ctl", "[Text String]", &txtData );
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
		if( NULL != _tcsstr( txtData[i].szTT, _T("IDC_GP_OBJECT") ) )
			txtData[i].idTT = IDC_GP_OBJECT;
		else
			if( NULL != _tcsstr( txtData[i].szTT, _T("IDC_GP_VIEW") ) )
				txtData[i].idTT = IDC_GP_VIEW;
		else
			if( NULL != _tcsstr( txtData[i].szTT, _T("IDC_BT_PREV") ) )
				txtData[i].idTT = IDC_BT_PREV;
		else
			if( NULL != _tcsstr( txtData[i].szTT, _T("IDC_BT_NEXT") ) )
				txtData[i].idTT = IDC_BT_NEXT;
		else
			if( NULL != _tcsstr( txtData[i].szTT, _T("IDC_BT_SEL_ALL") ) )
				txtData[i].idTT = IDC_BT_SEL_ALL;
		else
			if( NULL != _tcsstr( txtData[i].szTT, _T("IDC_BT_SEL_TEXT") ) )
				txtData[i].idTT = IDC_BT_SEL_TEXT;
		else
			if( NULL != _tcsstr( txtData[i].szTT, _T("IDC_BT_SEL_GRAPHIC") ) )
				txtData[i].idTT = IDC_BT_SEL_GRAPHIC;
		else
			if( NULL != _tcsstr( txtData[i].szTT, _T("IDC_BT_UN_SEL_ALL") ) )
				txtData[i].idTT = IDC_BT_UN_SEL_ALL;
		else
			if( NULL != _tcsstr( txtData[i].szTT, _T("IDC_CK_SELECT") ) )
				txtData[i].idTT = IDC_CK_SELECT;
		else
			if( NULL != _tcsstr( txtData[i].szTT, _T("IDC_CK_HIDE_SEL_OBJ") ) )
				txtData[i].idTT = IDC_CK_HIDE_SEL_OBJ;
		else
			if( NULL != _tcsstr( txtData[i].szTT, _T("IDC_CK_HIDE_GRAPHIC_OBJ") ) )
				txtData[i].idTT = IDC_CK_HIDE_GRAPHIC_OBJ;
		else
			if( NULL != _tcsstr( txtData[i].szTT, _T("IDC_CK_HIDE_LAYER_OBJ") ) )
				txtData[i].idTT = IDC_CK_HIDE_LAYER_OBJ;
		else
			if( NULL != _tcsstr( txtData[i].szTT, _T("IDC_CK_HIDE_TEXT_OBJ") ) )
				txtData[i].idTT = IDC_CK_HIDE_TEXT_OBJ;

		SetDlgItemText( txtData[i].idTT, (LPCTSTR)ptTT );
		m_hFont[i] = ChangeControlFont( GetDlgItem(txtData[i].idTT)->m_hWnd, NULL, UILang_UIFont,0, UILang_UIFontSize, FW_NORMAL);

	}//end of for

	free( txtData );
}//end of CDlgSelect::InitDlgItemTextNTooltip()
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
BOOL CDlgSelect::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	InitDlgItemTextNTooltip();
	
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}//end of CDlgSelect::OnInitDialog
