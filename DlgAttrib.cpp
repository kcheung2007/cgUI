/* COPYRIGHT NOTICE:
********************************************************
*  Copyright (c) 2000 InnoVision Technology, Inc.      *
*  All rights reserved.                                *
*  PROPRIETARY AND CONFIDENTIAL                        *
*  DO NOT DISTRIBUTE                                   *
********************************************************
*/
// DlgAttrib.cpp : implementation file
//

#include "stdafx.h"
#include "cgui.h"
#include "DlgAttrib.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDlgAttrib dialog
/////////////////////////////////////////////////////////////////////////////

extern _TCHAR	UILang_UIFont[256];
extern int		UILang_UIFontSize;
extern DWORD	g_dwAttrib;	

CDlgAttrib::CDlgAttrib(CWnd* pParent /*=NULL*/)	: CDialog(CDlgAttrib::IDD, pParent)
{
	//{{AFX_DATA_INIT(CDlgAttrib)
	//}}AFX_DATA_INIT
	for( int i = 0; i < ATT_NUMTAB; i++ )
		m_szTab[i][0] = NULL;

	m_hFont = NULL;
}
/////////////////////////////////////////////////////////////////////////////
CDlgAttrib::~CDlgAttrib()
{
	TRACE0("DlgAttrib.cpp : ~CDlgAttrib() - Destructor +++++\n");

	if( m_hFont != NULL )
		DeleteObject( (HGDIOBJ)m_hFont );

	if( m_pDlgCast != NULL )
		delete m_pDlgCast;

	if( m_pDlgFace != NULL )
		delete m_pDlgFace;
	
	if( m_pDlgOutline1 != NULL )
		delete m_pDlgOutline1;

	if( m_pDlgOutline2 != NULL )
		delete m_pDlgOutline2;

	if( m_pDlgShadow != NULL )
		delete m_pDlgShadow;
/*
	if( m_pAttText != NULL )
		delete m_pAttText;

	if( m_pAttLine != NULL )
		delete m_pAttLine;

	if( m_pAttBox != NULL )
		delete m_pAttBox;

	if( m_pAttOval != NULL )
		delete m_pAttOval;

	if( m_pAttFill != NULL )
		delete m_pAttFill;
*/
}//end of destructor
/////////////////////////////////////////////////////////////////////////////
void CDlgAttrib::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDlgAttrib)
	DDX_Control(pDX, IDC_TAB_ATTRIB, m_ctlAttribTab);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CDlgAttrib, CDialog)
	//{{AFX_MSG_MAP(CDlgAttrib)
	ON_NOTIFY(NM_CLICK, IDC_TAB_ATTRIB, OnClickTabAttrib)
	ON_NOTIFY(NM_RCLICK, IDC_TAB_ATTRIB, OnRclickTabAttrib)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDlgAttrib message handlers

BOOL CDlgAttrib::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: Add extra initialization here
	CreateAttribPage(); // create tab control with property page

	AfxGetMainWnd()->SendMessage( WM_COMMAND, ID_TXTGFX_TEXT, 0 );

	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}//end of OnInitDialog() 
////////////////////////////////////////////////////////////////////////////////////////////
void CDlgAttrib::OnCancel() 
{
	// capture cancel message
}//end of CDlgAttrib::OnCancel() 
////////////////////////////////////////////////////////////////////////////////////////////
void CDlgAttrib::OnOK() 
{
	// capture OK message
}//end of CDlgAttrib::OnOK() 
////////////////////////////////////////////////////////////////////////////////////////////
void CDlgAttrib::CreateAttribPage()
{
	TRACE0("CDlgAttrib::CreateAttribPage()\n");

	RECT	rcTab;
	CPoint	pt;

	LoadTabString( ); // load tab string into local variable
	m_hFont = ChangeControlFont( GetDlgItem(IDC_TAB_ATTRIB)->m_hWnd, NULL, UILang_UIFont,0, UILang_UIFontSize, FW_NORMAL);

	m_ctlAttribTab.GetItemRect( 0, &rcTab );
	pt.x = 3; // pixel
	pt.y = rcTab.bottom + 5; // pixel
	m_ctlAttribTab.SetTopLeftCorner( pt );

	//create image list	
// save for reference	m_imageAttribTab.Create(IDB_ATTRIB_IMAGE, 12, 0, RGB(0,0,0) );
// save for reference	m_ctlAttribTab.SetImageList( &m_imageAttribTab );

	//create face page
	m_pDlgFace = new CDlgFace;
	m_pDlgFace->Create(IDD_PG_FACE, &m_ctlAttribTab );

	if( m_szTab[0][0] == NULL ) // load string fail
		m_ctlAttribTab.AddTab( m_pDlgFace, _T("Face"), 0 ); // should load from file
	else
		m_ctlAttribTab.AddTab( m_pDlgFace, (_TCHAR*)m_szTab[0], 0 ); // should load from file
	
	//create outline 1 page
	m_pDlgOutline1 = new CDlgOutline1;
	m_pDlgOutline1->Create(IDD_PG_OUTLINE_1, &m_ctlAttribTab );

	if( m_szTab[1][0] == NULL ) // load string fail
		m_ctlAttribTab.AddTab( m_pDlgOutline1, _T("Outline 1"), 1 ); // should load from file
	else
		m_ctlAttribTab.AddTab( m_pDlgOutline1, (_TCHAR*)m_szTab[1], 1 ); // should load from file

	//create outline 2 page
	m_pDlgOutline2 = new CDlgOutline2;
	m_pDlgOutline2->Create(IDD_PG_OUTLINE_2, &m_ctlAttribTab );
	if( m_szTab[2][0] == NULL ) // load string fail
		m_ctlAttribTab.AddTab( m_pDlgOutline2, _T("Outline 2"), 2 ); // should load from file
	else
		m_ctlAttribTab.AddTab( m_pDlgOutline2, (_TCHAR*)m_szTab[2], 2 ); // should load from file

	//create Shadow page
	m_pDlgShadow = new CDlgShadow;
	m_pDlgShadow->Create(IDD_PG_SHADOW, &m_ctlAttribTab );
	if( m_szTab[3][0] == NULL ) // load string fail
		m_ctlAttribTab.AddTab( m_pDlgShadow, _T("Shadow 1"), 3 ); // should load from file
	else
		m_ctlAttribTab.AddTab( m_pDlgShadow, (_TCHAR*)m_szTab[3], 3 ); // should load from file

	//create Cast page
	m_pDlgCast = new CDlgCast;
	m_pDlgCast->Create(IDD_PG_CAST, &m_ctlAttribTab );
	if( m_szTab[4][0] == NULL ) // load string fail
		m_ctlAttribTab.AddTab( m_pDlgCast, _T("Shadow 2"), 4 ); // should load from file
	else
		m_ctlAttribTab.AddTab( m_pDlgCast, (_TCHAR*)m_szTab[4], 4 ); // should load from file

	AfxGetMainWnd()->SetFocus(); // must set focus here because of the last creation

}//end of CDlgAttrib::CreateAttribPage()
/////////////////////////////////////////////////////////////////////////////
// Loading string sequence MUST match with the sequence of creating Tab.
VOID CDlgAttrib::LoadTabString( )
{
	HFONT hFont = NULL;
	IN_TEXT_DATA* txtData = NULL;
	TCHAR	sep[] = _T("\"");
	TCHAR*	ptID;
	TCHAR*	ptTT;
	TCHAR*	ptEnd;

	DWORD numTxt = LoadTextFromCtl( "\\Util\\TabString.ctl", "[Attrib Tab String]", &txtData );
	if( numTxt == 0 )
		return;

	for( DWORD i = 0; i < ATT_NUMTAB; i++ )
	{
		ptID   = _tcstok( txtData[i].szTT, sep );
		ptTT   = _tcstok( NULL, sep );
		ptEnd  = _tcstok( NULL, sep );
		if( ptEnd != 0 )
			*ptEnd = '\0';

		if( NULL != _tcsstr( txtData[i].szTT, _T("FACE") ) )
			_tcscpy( m_szTab[0], (TCHAR*)ptTT );
		else
			if( NULL != _tcsstr( txtData[i].szTT, _T("OUTLINE_1") ) )
				_tcscpy( m_szTab[1], (TCHAR*)ptTT );
		else
			if( NULL != _tcsstr( txtData[i].szTT, _T("OUTLINE_2") ) )
				_tcscpy( m_szTab[2], (TCHAR*)ptTT );
		else
			if( NULL != _tcsstr( txtData[i].szTT, _T("SHADOW") ) )
				_tcscpy( m_szTab[3], (TCHAR*)ptTT );
		else
			if( NULL != _tcsstr( txtData[i].szTT, _T("CAST") ) )
				_tcscpy( m_szTab[4], (TCHAR*)ptTT );
	}//end of for

	free( txtData );
}//end of CDlgAttrib::LoadTabString()
//////////////////////////////////////////////////////////////////////////////////////////////
CDlgFace* CDlgAttrib::GetFaceDlgPtr()
{
	return( m_pDlgFace );
}//end of CDlgAttrib::GetFaceDlgPtr()
//////////////////////////////////////////////////////////////////////////////////////////////
CDlgCast* CDlgAttrib::GetCastDlgPtr()
{
	return( m_pDlgCast );
}//end of CDlgAttrib::GetCastDlgPtr()
//////////////////////////////////////////////////////////////////////////////////////////////
CDlgShadow* CDlgAttrib::GetShadowDlgPtr()
{
	return( m_pDlgShadow );
}//end of CDlgAttrib::GetShadowDlgPtr()
//////////////////////////////////////////////////////////////////////////////////////////////
CDlgOutline1* CDlgAttrib::GetOutline1DlgPtr()
{
	return( m_pDlgOutline1 );
}//end of CDlgAttrib::GetOutline1DlgPtr()
//////////////////////////////////////////////////////////////////////////////////////////////
CDlgOutline2* CDlgAttrib::GetOutline2DlgPtr()
{
	return( m_pDlgOutline2 );
}//end of CDlgAttrib::GetOutline2DlgPtr()
//////////////////////////////////////////////////////////////////////////////////////////////
void CDlgAttrib::OnClickTabAttrib(NMHDR* pNMHDR, LRESULT* pResult) 
{
	TRACE0("DlgAttrib.cpp - CDlgAttrib::OnClickTabAttrib\n");
	if( pNMHDR->code == NM_DBLCLK )
		m_ctlAttribTab.EnableTab( m_ctlAttribTab.GetIndexMouseOver(), 1 );
	*pResult = 0;
}//end of CDlgAttrib::OnClickTabAttrib
//////////////////////////////////////////////////////////////////////////////////////////////
void CDlgAttrib::OnRclickTabAttrib(NMHDR* pNMHDR, LRESULT* pResult) 
{
	TRACE0("DlgAttrib.cpp - CDlgAttrib::OnRClickTabAttrib\n");
	TRACE1("\tIndex Mouse Over = %d\n", m_ctlAttribTab.GetIndexMouseOver());
		
	*pResult = 0;
}//end of CDlgAttrib::OnRclickTabAttrib

