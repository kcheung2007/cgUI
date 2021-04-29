// DlgShadow2.cpp : implementation file
//

#include "stdafx.h"
#include "cgui.h"
#include "DlgShadow2.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDlgShadow2 dialog


CDlgShadow2::CDlgShadow2(CWnd* pParent /*=NULL*/)
	: CDialog(CDlgShadow2::IDD, pParent)
{
	//{{AFX_DATA_INIT(CDlgShadow2)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void CDlgShadow2::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDlgShadow2)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CDlgShadow2, CDialog)
	//{{AFX_MSG_MAP(CDlgShadow2)
		// NOTE: the ClassWizard will add message map macros here
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDlgShadow2 message handlers
