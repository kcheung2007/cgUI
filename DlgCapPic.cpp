/* COPYRIGHT NOTICE:
********************************************************
*  Copyright (c) 2000 InnoVision Technology, Inc.      *
*  All rights reserved.                                *
*  PROPRIETARY AND CONFIDENTIAL                        *
*  DO NOT DISTRIBUTE                                   *
********************************************************
*/
// DlgCapPic.cpp : implementation file
//

#include "stdafx.h"
#include "cgui.h"
#include "DlgCapPic.h"
#include "Global.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDlgCapPic dialog

extern _TCHAR	UILang_UIFont[256];
extern int		UILang_UIFontSize;

CDlgCapPic::CDlgCapPic(CWnd* pParent /*=NULL*/) : CDialog(CDlgCapPic::IDD, pParent)
{
	//{{AFX_DATA_INIT(CDlgCapPic)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	m_hFont = NULL;
}

CDlgCapPic::~CDlgCapPic()
{
	for( DWORD i = 0; i < m_numTxt; i++ )
	{
		if( m_hFont[i] != NULL )
			DeleteObject( (HGDIOBJ)m_hFont[i] );
	}
	if( m_hFont != NULL )
		delete [] m_hFont;

}
void CDlgCapPic::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDlgCapPic)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CDlgCapPic, CDialog)
	//{{AFX_MSG_MAP(CDlgCapPic)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDlgCapPic message handlers
/////////////////////////////////////////////////////////////////////////////
void CDlgCapPic::OnOK() 
{
	CDialog::OnOK();
}//end of OnOK
/////////////////////////////////////////////////////////////////////////////
VOID CDlgCapPic::SetGrabType(BOOL type)
{
	m_GrabType = type;
}//end of CDlgCapPic::SetGrabType
/////////////////////////////////////////////////////////////////////////////
BOOL CDlgCapPic::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: Add extra initialization here
	InitDlgItemText();
	
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}//end of CDlgCapPic::OnInitDialog
/////////////////////////////////////////////////////////////////////////////
VOID CDlgCapPic::InitDlgItemText()
{
	IN_TEXT_DATA* txtData = NULL;
	TCHAR	sep[] = _T("\"");
	TCHAR*	ptID;
	TCHAR*	ptTT;
	TCHAR*	ptEnd;

	m_numTxt = LoadTextFromCtl( "\\Util\\DlgCapPic.ctl", "[Tooltip]", &txtData );
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

		if( NULL != _tcsstr( txtData[i].szTT, _T("IDD_DLG_CAP_PICONS") ) )
		{
			txtData[i].idTT = IDD_DLG_CAP_PICONS;
			m_hFont[i] = ChangeControlFont( m_hWnd, NULL, UILang_UIFont,0, UILang_UIFontSize, FW_NORMAL);
			SetWindowText( (LPCTSTR)ptTT );
		}
		else
			if( NULL != _tcsstr( txtData[i].szTT, _T("IDC_BT_EXPORT") ) )
				txtData[i].idTT = IDC_BT_EXPORT;
		else
			if( NULL != _tcsstr( txtData[i].szTT, _T("IDOK") ) )
				txtData[i].idTT = IDOK;
		else
			if( NULL != _tcsstr( txtData[i].szTT, _T("IDC_RB_TO_DISK") ) )
				txtData[i].idTT = IDC_RB_TO_DISK;
		else
			if( NULL != _tcsstr( txtData[i].szTT, _T("IDC_RB_TO_TITLE_PAGE") ) )
				txtData[i].idTT = IDC_RB_TO_TITLE_PAGE;
		
		if( txtData[i].idTT != IDD_DLG_CAP_PICONS )
		{
			m_hFont[i] = ChangeControlFont( GetDlgItem(txtData[i].idTT)->m_hWnd, NULL, UILang_UIFont,0, UILang_UIFontSize, FW_NORMAL);
			SetDlgItemText( txtData[i].idTT, (LPCTSTR)ptTT );			
		}
	}//end of for

	free( txtData );

}//end of CDlgCapPic::InitDlgItemText()
