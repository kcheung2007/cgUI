/* COPYRIGHT NOTICE:
********************************************************
*  Copyright (c) 2000 InnoVision Technology, Inc.      *
*  All rights reserved.                                *
*  PROPRIETARY AND CONFIDENTIAL                        *
*  DO NOT DISTRIBUTE                                   *
********************************************************
*/
// DlgBarFbg.cpp : implementation file
//

#include "stdafx.h"
#include "cgUI.h"
#include "DlgBarFbg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDlgBarFbg dialog


#define		WM_INITDLGBAR_FBG		WM_USER + WM_USER_FBG

BEGIN_MESSAGE_MAP(CDlgBarFbg, CDialogBar)
	//{{AFX_MSG_MAP(CDlgBarFbg)
	ON_MESSAGE( WM_INITDLGBAR_FBG, InitDialogBarHandler )
	ON_WM_CREATE()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

//////////////////////////////////////////////////////////////////////////////
CDlgBarFbg::CDlgBarFbg()
{
}//end of constructor

CDlgBarFbg::~CDlgBarFbg()
{
}//end of destructor


void CDlgBarFbg::DoDataExchange(CDataExchange* pDX)
{
	// TODO: Add your specialized code here and/or call the base class
	CDialogBar::DoDataExchange(pDX);
}//end of CDlgBarFbg::DoDataExchange

/////////////////////////////////////////////////////////////////////////////
// CDlgBarFbg message handlers
/////////////////////////////////////////////////////////////////////////////
BOOL CDlgBarFbg::OnInitDialogBar() 
{
	return( 1 );
}//end of CDlgBarFbg::OnInitDialogBar
/////////////////////////////////////////////////////////////////////////////
int CDlgBarFbg::OnCreate(LPCREATESTRUCT lpCreateStruct) 
{
	if (CDialogBar::OnCreate(lpCreateStruct) == -1)
		return -1;
	
	// TODO: Add your specialized creation code here
	// Post WM_INITDIALOGBAR message here to dialog bar
	PostMessage(WM_INITDLGBAR_FBG , 0 , 0 );
	
	return 0;
}//end of CDlgBarFbg::OnCreate
///////////////////////////////////////////////////////////////////////////////////
LRESULT CDlgBarFbg::InitDialogBarHandler(WPARAM wParam, LPARAM lParam)
{
	UpdateData(FALSE);
	OnInitDialogBar() ;

    return( 0 );
}//end of CDlgBarFbg::InitDialogBarHandler
