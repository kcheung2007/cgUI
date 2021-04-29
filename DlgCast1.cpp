// DlgCast1.cpp : implementation file
//

#include "stdafx.h"
#include "cgui.h"
#include "DlgCast1.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDlgCast1 dialog


CDlgCast1::CDlgCast1(CWnd* pParent /*=NULL*/)
	: CDialog(CDlgCast1::IDD, pParent)
{
	//{{AFX_DATA_INIT(CDlgCast1)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void CDlgCast1::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDlgCast1)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CDlgCast1, CDialog)
	//{{AFX_MSG_MAP(CDlgCast1)
		// NOTE: the ClassWizard will add message map macros here
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDlgCast1 message handlers
