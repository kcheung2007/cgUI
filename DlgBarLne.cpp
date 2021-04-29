/* COPYRIGHT NOTICE:
********************************************************
*  Copyright (c) 2000 InnoVision Technology, Inc.      *
*  All rights reserved.                                *
*  PROPRIETARY AND CONFIDENTIAL                        *
*  DO NOT DISTRIBUTE                                   *
********************************************************
*/
// DlgBarLne.cpp : implementation file
//

#include "stdafx.h"
#include "cgUI.h"
#include "DlgBarLne.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDlgBarLne dialog


#define		WM_INITDLGBAR_LNE		WM_USER + WM_USER_LNE

BEGIN_MESSAGE_MAP(CDlgBarLne, CDialogBar)
	//{{AFX_MSG_MAP(CDlgBarLne)
	ON_MESSAGE( WM_INITDLGBAR_LNE, InitDialogBarHandler )
	ON_WM_CREATE()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

//////////////////////////////////////////////////////////////////////////////
CDlgBarLne::CDlgBarLne()
{
}//end of constructor

CDlgBarLne::~CDlgBarLne()
{
}//end of destructor


void CDlgBarLne::DoDataExchange(CDataExchange* pDX)
{
	// TODO: Add your specialized code here and/or call the base class
	CDialogBar::DoDataExchange(pDX);
}//end of CDlgBarLne::DoDataExchange

/////////////////////////////////////////////////////////////////////////////
// CDlgBarLne message handlers
/////////////////////////////////////////////////////////////////////////////
BOOL CDlgBarLne::OnInitDialogBar() 
{
/**
	CreateAttribPage(); // create tab control with property page

	//++++++++++++++++++ start owner draw combo box font
	m_ocbFont.SubclassDlgItem(IDC_CB_FONT,this);
	m_ocbFont.Initialize();

	//++++++++++++++++++ Initial radio button and bitmap
    m_rbBold.SetIcon( ::LoadIcon(AfxGetApp()->m_hInstance, MAKEINTRESOURCE(IDI_BOLD)) );
	m_rbItalic.SetIcon( ::LoadIcon(AfxGetApp()->m_hInstance, MAKEINTRESOURCE(IDI_ITALIC)) );
	m_rbUnderline.SetIcon( ::LoadIcon(AfxGetApp()->m_hInstance, MAKEINTRESOURCE(IDI_UNDERLINE)) );	
	//TO DO : read the button state from somewhere
	int state = 1;
	m_rbBold.SetCheck( state );

	m_stcHeight.ModifyStyle(0, SS_ICON);
	HICON rv = m_stcHeight.SetIcon( (HICON)::LoadImage(  AfxGetApp()->m_hInstance,
						MAKEINTRESOURCE(IDI_FONT_HEIGHT),
						IMAGE_ICON,
						16,
						16,
						0) );
	

	// ++++++++++++++++++++++++++++++++++++++++++++ Initial spin control
	CSpinButtonCtrl* pSpin = (CSpinButtonCtrl*)GetDlgItem( IDC_SPN_WIDTH );
	pSpin->SetRange( 5, 999 );
	//save for ref.	pSpin->SetPos((int) (m_dSpin * 10.0));
	pSpin = (CSpinButtonCtrl*)GetDlgItem( IDC_SPN_HEIGHT );
	pSpin->SetRange( 5, 500 );
	pSpin = (CSpinButtonCtrl*)GetDlgItem( IDC_SPN_SPACE );
	pSpin->SetRange( -64, 64 );
	pSpin = (CSpinButtonCtrl*)GetDlgItem( IDC_SPN_PRIORITY );
	pSpin->SetRange( 0, 255 );

	//+++++++++++++++++++++++++++++++++++++++++++++ Initial Edit control
	CEdit* pEdCtrl = (CEdit*)GetDlgItem( IDC_ED_WIDTH );
	pEdCtrl->SetLimitText( 3 ); // 3 characters of 999
	pEdCtrl = (CEdit*)GetDlgItem( IDC_ED_HEIGHT );
	pEdCtrl->SetLimitText( 3 ); // 3 characters of 500
	pEdCtrl = (CEdit*)GetDlgItem( IDC_ED_SPACE );
	pEdCtrl->SetLimitText( 3 ); // 3 characters of -64 .. +64 
	pEdCtrl = (CEdit*)GetDlgItem( IDC_ED_PRIORITY );
	pEdCtrl->SetLimitText( 3 ); // 3 characters of 255 
**/
	return( 1 );
}//end of CDlgBarLne::OnInitDialogBar
/////////////////////////////////////////////////////////////////////////////
int CDlgBarLne::OnCreate(LPCREATESTRUCT lpCreateStruct) 
{
	if (CDialogBar::OnCreate(lpCreateStruct) == -1)
		return -1;
	
	// TODO: Add your specialized creation code here
	// Post WM_INITDIALOGBAR message here to dialog bar
	PostMessage(WM_INITDLGBAR_LNE , 0 , 0 );
	
	return 0;
}//end of CDlgBarLne::OnCreate
///////////////////////////////////////////////////////////////////////////////////
LRESULT CDlgBarLne::InitDialogBarHandler(WPARAM wParam, LPARAM lParam)
{
	UpdateData(FALSE);
	OnInitDialogBar() ;

    return( 0 );
}//end of CDlgBarLne::InitDialogBarHandler


/////////////////////////////////////////////////////////////////////////////
// CDlgBarLne message handlers
