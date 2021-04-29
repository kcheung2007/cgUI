/* COPYRIGHT NOTICE:
********************************************************
*  Copyright (c) 2000 InnoVision Technology, Inc.      *
*  All rights reserved.                                *
*  PROPRIETARY AND CONFIDENTIAL                        *
*  DO NOT DISTRIBUTE                                   *
********************************************************
*/
// DlgCapture.cpp : implementation file
//

#include "stdafx.h"
#include "cgUI.h"
#include "DlgCapPic.h"
#include "DlgCapture.h"
#include "Global.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDlgCapture dialog
extern TCHAR UILang_UIFont[256];
extern int	 UILang_UIFontSize;
extern DWORD g_CodePage;
/////////////////////////////////////////////////////////////////////////////
CDlgCapture::CDlgCapture(CWnd* pParent /*=NULL*/): CDialog(CDlgCapture::IDD, pParent)
{
	//{{AFX_DATA_INIT(CDlgCapture)
	//}}AFX_DATA_INIT
	m_hFont = NULL;
}

CDlgCapture::~CDlgCapture()
{
	for( DWORD i = 0; i < m_numTxt; i++ )
	{
		if( m_hFont[i] != NULL )
			DeleteObject( (HGDIOBJ)m_hFont[i] );
	}
	if( m_hFont != NULL )
		delete [] m_hFont;
}
/////////////////////////////////////////////////////////////////////////////
void CDlgCapture::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDlgCapture)
	DDX_Control(pDX, IDC_CB_CAPTURE_TYPE, m_cbCapType);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CDlgCapture, CDialog)
	//{{AFX_MSG_MAP(CDlgCapture)
	ON_CBN_SELCHANGE(IDC_CB_CAPTURE_TYPE, OnSelchangeCbCaptureType)
	ON_BN_CLICKED(IDC_BT_GRAB, OnBtGrab)
	ON_BN_CLICKED(IDC_BT_MULTI_GRAB, OnBtMultiGrab)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDlgCapture message handlers

BOOL CDlgCapture::OnInitDialog() 
{
	TRACE0("DlgCapture.cpp : CDlgCapture::OnInitDialog()\n" );
	CDialog::OnInitDialog();
	
	//+++++++++++++++++++++++++++++++++++++++++++++ Initial Combom box
	InitComboString( _T("\\Util\\DlgCapture.ctl"), _T("[Combo String]"), &m_cbCapType );

	//++++++++++++++++++++++++++++++++++++++ Create the ToolTip control.
	m_tooltip.Create(this);
	m_tooltip.Activate(TRUE);

	InitDlgItemTextNTooltip(); // seting both tooltip and dialog item text

	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}//end of CDlgCapture::OnInitDialog
//////////////////////////////////////////////////////////////////////////////////////
void CDlgCapture::OnSelchangeCbCaptureType() 
{
	TRACE0("DlgCapture.cpp : OnSelchangeCbCaptureType\n" );
	switch( m_cbCapType.GetCurSel() )
	{
	case 0: // Interpolated Frame
		TRACE0("\t Interpolated Frame\n" );
		break;
	case 1: // Both Fields
		TRACE0("\t Both Fields\n" );
		break;
	case 2: // Even Field
		TRACE0("\t Even Field\n" );
		break;
	case 3: // Odd Field
		TRACE0("\t Odd Field\n" );
		break;
	}//end of switch	

	AfxGetMainWnd()->SetFocus();	
}//end of CDlgCapture::OnSelchangeCbCaptureType
/////////////////////////////////////////////////////////////////////////////////////
void CDlgCapture::OnOK() 
{
	// capture OK message
}//end of CDialog::OnOK
/////////////////////////////////////////////////////////////////////////////////////////
void CDlgCapture::OnCancel() 
{
	// capture cancel message
}//end of CDialog::OnCancel
/////////////////////////////////////////////////////////////////////////////////////////
BOOL CDlgCapture::PreTranslateMessage(MSG* pMsg)
{
	m_tooltip.RelayEvent(pMsg);

	return CDialog::PreTranslateMessage(pMsg);	// CG: This was added by the ToolTips component.
}//end of CDlgCapture::PreTranslateMessage
/////////////////////////////////////////////////////////////////////////////////////////
VOID CDlgCapture::InitDlgItemTextNTooltip()
{
	IN_TEXT_DATA* txtData = NULL;
	TCHAR	sep[] = _T("\"");
	TCHAR*	ptID;
	TCHAR*	ptTT;
	TCHAR*	ptEnd;

	m_numTxt = LoadTextFromCtl( "\\Util\\DlgCapture.ctl", "[Tooltip]", &txtData );
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

		if( NULL != _tcsstr( txtData[i].szTT, _T("IDC_STC_CAP_TYPE") ) )
			txtData[i].idTT = IDC_STC_CAP_TYPE;
		else
			if( NULL != _tcsstr( txtData[i].szTT, _T("IDC_BT_GRAB") ) )
				txtData[i].idTT = IDC_BT_GRAB;
		else
			if( NULL != _tcsstr( txtData[i].szTT, _T("IDC_BT_MULTI_GRAB") ) )
				txtData[i].idTT = IDC_BT_MULTI_GRAB;
		else
			if( NULL != _tcsstr( txtData[i].szTT, _T("IDC_CB_CAPTURE_TYPE") ) )
				txtData[i].idTT = IDC_CB_CAPTURE_TYPE;

		SetDlgItemText( txtData[i].idTT, (LPCTSTR)ptTT );
		m_hFont[i] = ChangeControlFont( GetDlgItem(txtData[i].idTT)->m_hWnd, NULL, UILang_UIFont,0, UILang_UIFontSize, FW_NORMAL);

//SKIP_TEXT:
		_tcscpy( txtData[i].szTT, (TCHAR*)txtData[i].szTT );
		if( NULL != GetDlgItem(txtData[i].idTT) )
			m_tooltip.AddTool( GetDlgItem(txtData[i].idTT), (TCHAR*)ptTT);
	}//end of for

	free( txtData );

}//end of CDlgCapture::InitDlgItemTextNTooltip()
///////////////////////////////////////////////////////////////////////////////////////////////
void CDlgCapture::OnBtGrab() 
{
	// TODO: Add your control notification handler code here
	CDlgCapPic dlgCapPic;
  
	dlgCapPic.SetGrabType( 0 );
	// Create and show the dialog box
	int nRet = -1;
	nRet = dlgCapPic.DoModal();
	// Handle the return value from DoModal
	switch ( nRet )
	{
	case -1: 
		AfxMessageBox(_T("Dialog box could not be created!"));	  
		break;
	case IDABORT:
		  // Do something		  
		break;
	case IDOK:
		  // Do something		  
		break;
	case IDCANCEL:
		  // Do something		  
		break;
	default:
		  // Do something		  
		break;
	};//end of switch
	
}//end of CDlgCapture::OnBtGrab() 
///////////////////////////////////////////////////////////////////////////////////////////////
void CDlgCapture::OnBtMultiGrab() 
{
	// TODO: Add your control notification handler code here
	CDlgCapPic dlgCapPic;
  
	dlgCapPic.SetGrabType( 1 );
	// Create and show the dialog box
	int nRet = -1;
	nRet = dlgCapPic.DoModal();
	// Handle the return value from DoModal
	switch ( nRet )
	{
	case -1: 
		AfxMessageBox(_T("Dialog box could not be created!"));
		break;
	case IDABORT:
		  // Do something		  
		break;
	case IDOK:
		  // Do something		  
		break;
	case IDCANCEL:
		  // Do something		  
		break;
	default:
		  // Do something		  
		break;
	};//end of switch
	
}//end of CDlgCapture::OnBtMultiGrab()
//////////////////////////////////////////////////////////////////////////////////////////////
VOID CDlgCapture::InitComboString( LPTSTR ptFn, LPTSTR ptSection, CComboBox* ptCombo )
{
	IN_TEXT_DATA* txtData = NULL;
	TCHAR	sep[] = _T("\"");
	TCHAR*	ptID;
	TCHAR*	ptTT;
	TCHAR*	ptEnd;

// check point
	CHAR		fn[MAX_PATH];
	CHAR		section[MAX_PATH];

	UnicodeToMultiByte( g_CodePage, ptFn, fn );
	UnicodeToMultiByte( g_CodePage, ptSection, section );
//save	WideCharToMultiByte( g_CodePage, 0, ptFn, -1, fn,	sizeof(fn), NULL, NULL	);
//save	WideCharToMultiByte( g_CodePage, 0, ptSection, -1, section, sizeof(section), NULL, NULL );
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
}//end of CDlgCapture::InitComboString()
/////////////////////////////////////////////////////////////////////////////////////////////////
VOID CDlgCapture::DoValueUpdate()
{
	TRACE0("DlgCature.cpp : CDlgCapture::DoValueUpdate()\n");
}//end of CDlgCapture::DoValueUpdate()
