// RMPopup.cpp : implementation file
//

#include "stdafx.h"
#include "cgui.h"
#include "RMPopup.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CRMPopup dialog


CRMPopup::CRMPopup(CWnd* pParent /*=NULL*/)
	: CDialog(CRMPopup::IDD, pParent)
{
	//{{AFX_DATA_INIT(CRMPopup)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void CRMPopup::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CRMPopup)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CRMPopup, CDialog)
	//{{AFX_MSG_MAP(CRMPopup)
		// NOTE: the ClassWizard will add message map macros here
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CRMPopup message handlers
