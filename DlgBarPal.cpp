/* COPYRIGHT NOTICE:
********************************************************
*  Copyright (c) 2000 InnoVision Technology, Inc.      *
*  All rights reserved.                                *
*  PROPRIETARY AND CONFIDENTIAL                        *
*  DO NOT DISTRIBUTE                                   *
********************************************************
*/
// DlgBarPal.cpp : implementation file
//

#include "stdafx.h"
#include "cgUI.h"
#include "DlgBarPal.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDlgBarPal dialog


#define		WM_INITDLGBAR_PAL		WM_USER + WM_USER_PAL

BEGIN_MESSAGE_MAP(CDlgBarPal, CDialogBar)
	//{{AFX_MSG_MAP(CDlgBarPal)
	ON_MESSAGE( WM_INITDLGBAR_PAL, InitDialogBarHandler )
	ON_WM_CREATE()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

//////////////////////////////////////////////////////////////////////////////
CDlgBarPal::CDlgBarPal()
{
}//end of constructor

CDlgBarPal::~CDlgBarPal()
{
}//end of destructor


void CDlgBarPal::DoDataExchange(CDataExchange* pDX)
{
	// TODO: Add your specialized code here and/or call the base class
	CDialogBar::DoDataExchange(pDX);
}//end of CDlgBarPal::DoDataExchange

/////////////////////////////////////////////////////////////////////////////
// CDlgBarPal message handlers
/////////////////////////////////////////////////////////////////////////////
BOOL CDlgBarPal::OnInitDialogBar() 
{
	return( 1 );
}//end of CDlgBarPal::OnInitDialogBar
/////////////////////////////////////////////////////////////////////////////
int CDlgBarPal::OnCreate(LPCREATESTRUCT lpCreateStruct) 
{
	if (CDialogBar::OnCreate(lpCreateStruct) == -1)
		return -1;
	
	// TODO: Add your specialized creation code here
	// Post WM_INITDIALOGBAR message here to dialog bar
	PostMessage(WM_INITDLGBAR_PAL , 0 , 0 );
	
	return 0;
}//end of CDlgBarPal::OnCreate
///////////////////////////////////////////////////////////////////////////////////
LRESULT CDlgBarPal::InitDialogBarHandler(WPARAM wParam, LPARAM lParam)
{
	UpdateData(FALSE);
	OnInitDialogBar() ;

    return( 0 );
}//end of CDlgBarPal::InitDialogBarHandler


/////////////////////////////////////////////////////////////////////////////
// CDlgBarPal message handlers
