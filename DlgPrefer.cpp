// DlgPrefer.cpp : implementation file
//

#include "stdafx.h"
#include "cgui.h"
#include "DlgPrefer.h"
#include "browsefolder.h"
#include "DlgGetPath.h"
#include "Global.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

extern _TCHAR	UILang_UIFont[256];
extern int		UILang_UIFontSize;

/////////////////////////////////////////////////////////////////////////////
// CDlgPrefer dialog

CDlgPrefer::CDlgPrefer(CWnd* pParent /*=NULL*/) : CDialog(CDlgPrefer::IDD, pParent)
{
	//{{AFX_DATA_INIT(CDlgPrefer)
	//}}AFX_DATA_INIT
	m_hFont = NULL;
}

CDlgPrefer::~CDlgPrefer()
{
	for( DWORD i = 0; i < m_numTxt; i++ )
	{
		if( m_hFont[i] != NULL )
			DeleteObject( (HGDIOBJ)m_hFont[i] );
	}
	if( m_hFont != NULL )
		delete [] m_hFont;
}

void CDlgPrefer::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDlgPrefer)
	DDX_Control(pDX, IDC_BT_BROWSE3, m_btBrowse3);
	DDX_Control(pDX, IDC_BT_BROWSE2, m_btBrowse2);
	DDX_Control(pDX, IDC_BT_BROWSE1, m_btBrowse1);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CDlgPrefer, CDialog)
	//{{AFX_MSG_MAP(CDlgPrefer)
	ON_BN_CLICKED(IDC_BT_BROWSE1, OnBtBrowse1)
	ON_BN_CLICKED(IDC_BT_BROWSE2, OnBtBrowse2)
	ON_BN_CLICKED(IDC_BT_BROWSE3, OnBtBrowse3)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

//////////////////////////////////////////////////////////////////////////////////////////////////
// CDlgPrefer message handlers
void CDlgPrefer::OnBtBrowse1() 
{
	CDlgGetPath dlgPath( this );
//	dlgPath.SetTitle( _T("Blar..") );
//	dlgPath.m_sTopNote = _T("Blar blar blar...");
	switch ( dlgPath.DoModal() )   
	{   
	case -1:     
		AfxMessageBox(_T("Dialog box could not be created!"));
      break;
    case IDABORT:
      // Do something
       break;
    case IDOK:
		SetDlgItemText( IDC_ED_PROJ, dlgPath.GetPath() );
       break;
    case IDCANCEL:
      // Do something
       break;
    default:
      // Do something
      break;
   }//end of switch
}// end of CDlgPrefer::OnBtBrowse1
//////////////////////////////////////////////////////////////////////////////////////////////////
void CDlgPrefer::OnBtBrowse2() 
{
	CDlgGetPath dlgPath( this );
//	dlgPath.SetTitle( _T("Blar..") );
//	dlgPath.m_sTopNote = _T("Blar blar blar...");
	switch ( dlgPath.DoModal() )   
	{   
	case -1:     
		AfxMessageBox(_T("Dialog box could not be created!"));
      break;
    case IDABORT:
      // Do something
       break;
    case IDOK:
		SetDlgItemText( IDC_ED_GRAF, dlgPath.GetPath() );
       break;
    case IDCANCEL:
      // Do something
       break;
    default:
      // Do something
      break;
   }//end of switch

}// end of CDlgPrefer::OnBtBrowse2
//////////////////////////////////////////////////////////////////////////////////////////////////
void CDlgPrefer::OnBtBrowse3() 
{ 
	
	CDlgGetPath dlgPath( this );
//	dlgPath.SetTitle( _T("Blar..") );
//	dlgPath.m_sTopNote = _T("Blar blar blar...");
	switch ( dlgPath.DoModal() )   
	{   
	case -1:     
		AfxMessageBox(_T("Dialog box could not be created!"));
      break;
    case IDABORT:
      // Do something
       break;
    case IDOK:
		SetDlgItemText( IDC_ED_PG_EXPORT, dlgPath.GetPath() );
       break;
    case IDCANCEL:
      // Do something
       break;
    default:
      // Do something
      break;
   }//end of switch
	
}// end of CDlgPrefer::OnBtBrowse3
//////////////////////////////////////////////////////////////////////////////////////////////////
BOOL CDlgPrefer::OnInitDialog() 
{
	CDialog::OnInitDialog();

	InitDlgItemText();

	HICON hIcon = (HICON)::LoadImage( AfxGetApp()->m_hInstance, MAKEINTRESOURCE(IDI_OPEN), IMAGE_ICON, 16, 16, 0 );
	m_btBrowse1.SetIcon( hIcon );
	m_btBrowse2.SetIcon( hIcon );
	m_btBrowse3.SetIcon( hIcon );
	
	// TO DO : Read the default folder path and set it to the edit control
	FILE_REQ_FOLDER_INFO	preferFRD;
	ZeroMemory( &preferFRD, sizeof( preferFRD ) );

	preferFRD.nFileType = FILE_CATEGORY_PROJECT;
	CGS_GetFileCategoryPathInfo( &preferFRD );
	SetDlgItemText( IDC_ED_PROJ, preferFRD.FolderPath );

	preferFRD.nFileType = FILE_CATEGORY_PICTURE;
	CGS_GetFileCategoryPathInfo( &preferFRD );
	SetDlgItemText( IDC_ED_GRAF, preferFRD.FolderPath );

	preferFRD.nFileType = FILE_CATEGORY_EXPORT_PAGE;
	CGS_GetFileCategoryPathInfo( &preferFRD );
	SetDlgItemText( IDC_ED_PG_EXPORT, preferFRD.FolderPath );

	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}// end of CDlgPrefer::OnInitDialog
//////////////////////////////////////////////////////////////////////////////////////////////////
void CDlgPrefer::OnOK() 
{	
	TCHAR	szPath[MAX_PATH];
	FILE_REQ_FOLDER_INFO	frq;

	ZeroMemory( &frq, sizeof( frq ) );
	GetDlgItemText( IDC_ED_PROJ, szPath, MAX_PATH );
	frq.nFileType = FILE_CATEGORY_PROJECT;
	_tcscpy( frq.FolderPath, szPath );
	CGS_SetFileCategoryPathInfo( &frq );
	
	ZeroMemory( &frq, sizeof( frq ) );
	GetDlgItemText( IDC_ED_GRAF, szPath, MAX_PATH );
	frq.nFileType = FILE_CATEGORY_PICTURE;
	_tcscpy( frq.FolderPath, szPath );
	CGS_SetFileCategoryPathInfo( &frq );

	ZeroMemory( &frq, sizeof( frq ) );
	GetDlgItemText( IDC_ED_PG_EXPORT, szPath, MAX_PATH );
	frq.nFileType = FILE_CATEGORY_EXPORT_PAGE;
	_tcscpy( frq.FolderPath, szPath );
	CGS_SetFileCategoryPathInfo( &frq );

	CDialog::OnOK();
}//end of CDlgPrefer::OnOK
///////////////////////////////////////////////////////////////////////////////////////
VOID CDlgPrefer::InitDlgItemText()
{
	IN_TEXT_DATA* txtData = NULL;
	TCHAR	sep[] = _T("\"");
	TCHAR*	ptID;
	TCHAR*	ptTT;
	TCHAR*	ptEnd;

	m_numTxt = LoadTextFromCtl( "\\Util\\DlgPrefer.ctl", "[Tooltip]", &txtData );
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
		
		if( NULL != _tcsstr( txtData[i].szTT, _T("IDD_DLG_PREFER") ))
		{
			txtData[i].idTT = IDD_DLG_PREFER;
			SetWindowText( (LPCTSTR)ptTT );
			goto SkipText;
		}
		else
			if( NULL != _tcsstr( txtData[i].szTT, _T("IDC_STC_FOLDER") ))
				txtData[i].idTT = IDC_STC_FOLDER;
		else
			if( NULL != _tcsstr( txtData[i].szTT, _T("IDC_STC_PROJECT") ))
				txtData[i].idTT = IDC_STC_PROJECT;
		else
			if( NULL != _tcsstr( txtData[i].szTT, _T("IDC_STC_GRAPHIC") ))
				txtData[i].idTT = IDC_STC_GRAPHIC;
		else
			if( NULL != _tcsstr( txtData[i].szTT, _T("IDC_STC_PAGE_EXP") ))
				txtData[i].idTT = IDC_STC_PAGE_EXP;
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
}//end of CDlgPrefer::InitDlgItemText()
