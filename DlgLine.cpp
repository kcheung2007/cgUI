/* COPYRIGHT NOTICE:
********************************************************
********************************************************
*/
// DlgLine.cpp : implementation file
//

#include "stdafx.h"
#include "cgui.h"
#include "DlgLine.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDlgLine dialog


CDlgLine::CDlgLine(CWnd* pParent /*=NULL*/)
	: CDialog(CDlgLine::IDD, pParent)
{
	//{{AFX_DATA_INIT(CDlgLine)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void CDlgLine::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDlgLine)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CDlgLine, CDialog)
	//{{AFX_MSG_MAP(CDlgLine)
		// NOTE: the ClassWizard will add message map macros here
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDlgLine message handlers
