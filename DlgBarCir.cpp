/* COPYRIGHT NOTICE:
********************************************************
*  Copyright (c) 2000 InnoVision Technology, Inc.      *
*  All rights reserved.                                *
*  PROPRIETARY AND CONFIDENTIAL                        *
*  DO NOT DISTRIBUTE                                   *
********************************************************
*/
// DlgBarCir.cpp : implementation file
//

#include "stdafx.h"
#include "cgUI.h"
#include "DlgBarCir.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDlgBarCir dialog


#define		WM_INITDLGBAR_CIR		WM_USER + WM_USER_CIR

BEGIN_MESSAGE_MAP(CDlgBarCir, CDialogBar)
	//{{AFX_MSG_MAP(CDlgBarCir)
	ON_MESSAGE( WM_INITDLGBAR_CIR, InitDialogBarHandler )
	ON_WM_CREATE()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

//////////////////////////////////////////////////////////////////////////////
CDlgBarCir::CDlgBarCir()
{
}//end of constructor

CDlgBarCir::~CDlgBarCir()
{
}//end of destructor


void CDlgBarCir::DoDataExchange(CDataExchange* pDX)
{
	// TODO: Add your specialized code here and/or call the base class
	CDialogBar::DoDataExchange(pDX);
}//end of CDlgBarCir::DoDataExchange

/////////////////////////////////////////////////////////////////////////////
// CDlgBarCir message handlers
/////////////////////////////////////////////////////////////////////////////
BOOL CDlgBarCir::OnInitDialogBar() 
{
	return( 1 );
}//end of CDlgBarCir::OnInitDialogBar
/////////////////////////////////////////////////////////////////////////////
int CDlgBarCir::OnCreate(LPCREATESTRUCT lpCreateStruct) 
{
	if (CDialogBar::OnCreate(lpCreateStruct) == -1)
		return -1;
	
	// TODO: Add your specialized creation code here
	// Post WM_INITDIALOGBAR message here to dialog bar
	PostMessage(WM_INITDLGBAR_CIR , 0 , 0 );
	
	return 0;
}//end of CDlgBarCir::OnCreate
///////////////////////////////////////////////////////////////////////////////////
LRESULT CDlgBarCir::InitDialogBarHandler(WPARAM wParam, LPARAM lParam)
{
	UpdateData(FALSE);
	OnInitDialogBar() ;

    return( 0 );
}//end of CDlgBarCir::InitDialogBarHandler
