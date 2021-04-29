// DlgCast2.cpp : implementation file
//

#include "stdafx.h"
#include "cgui.h"
#include "DlgCast2.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDlgCast2 dialog


CDlgCast2::CDlgCast2(CWnd* pParent /*=NULL*/)
	: CDialog(CDlgCast2::IDD, pParent)
{
	//{{AFX_DATA_INIT(CDlgCast2)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void CDlgCast2::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDlgCast2)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CDlgCast2, CDialog)
	//{{AFX_MSG_MAP(CDlgCast2)
		// NOTE: the ClassWizard will add message map macros here
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDlgCast2 message handlers
