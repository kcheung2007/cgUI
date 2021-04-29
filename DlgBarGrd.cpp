/* COPYRIGHT NOTICE:
********************************************************
*  Copyright (c) 2000 InnoVision Technology, Inc.      *
*  All rights reserved.                                *
*  PROPRIETARY AND CONFIDENTIAL                        *
*  DO NOT DISTRIBUTE                                   *
********************************************************
*/
// DlgBarGrd.cpp : implementation file
//

#include "stdafx.h"
#include "cgUI.h"
#include "DlgBarGrd.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDlgBarGrd dialog


#define		WM_INITDLGBAR_GRD		WM_USER + WM_USER_GRD

BEGIN_MESSAGE_MAP(CDlgBarGrd, CDialogBar)
	//{{AFX_MSG_MAP(CDlgBarGrd)
	ON_MESSAGE( WM_INITDLGBAR_GRD, InitDialogBarHandler )
	ON_WM_CREATE()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

//////////////////////////////////////////////////////////////////////////////
CDlgBarGrd::CDlgBarGrd()
{
}//end of constructor

CDlgBarGrd::~CDlgBarGrd()
{
}//end of destructor


void CDlgBarGrd::DoDataExchange(CDataExchange* pDX)
{
	// TODO: Add your specialized code here and/or call the base class
	CDialogBar::DoDataExchange(pDX);
}//end of CDlgBarGrd::DoDataExchange

/////////////////////////////////////////////////////////////////////////////
// CDlgBarGrd message handlers
/////////////////////////////////////////////////////////////////////////////
BOOL CDlgBarGrd::OnInitDialogBar() 
{
	return( 1 );
}//end of CDlgBarGrd::OnInitDialogBar
/////////////////////////////////////////////////////////////////////////////
int CDlgBarGrd::OnCreate(LPCREATESTRUCT lpCreateStruct) 
{
	if (CDialogBar::OnCreate(lpCreateStruct) == -1)
		return -1;
	
	// TODO: Add your specialized creation code here
	// Post WM_INITDIALOGBAR message here to dialog bar
	PostMessage(WM_INITDLGBAR_GRD , 0 , 0 );
	
	return 0;
}//end of CDlgBarGrd::OnCreate
///////////////////////////////////////////////////////////////////////////////////
LRESULT CDlgBarGrd::InitDialogBarHandler(WPARAM wParam, LPARAM lParam)
{
	UpdateData(FALSE);
	OnInitDialogBar() ;

    return( 0 );
}//end of CDlgBarGrd::InitDialogBarHandler

/////////////////////////////////////////////////////////////////////////////
// CDlgBarGrd message handlers
