// DlgShadow1.cpp : implementation file
//

#include "stdafx.h"
#include "cgui.h"
#include "DlgShadow1.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDlgShadow1 dialog


CDlgShadow1::CDlgShadow1(CWnd* pParent /*=NULL*/)
	: CDialog(CDlgShadow1::IDD, pParent)
{
	//{{AFX_DATA_INIT(CDlgShadow1)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void CDlgShadow1::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDlgShadow1)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CDlgShadow1, CDialog)
	//{{AFX_MSG_MAP(CDlgShadow1)
		// NOTE: the ClassWizard will add message map macros here
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDlgShadow1 message handlers
