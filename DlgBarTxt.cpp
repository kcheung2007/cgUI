// DlgBarTxt.cpp : implementation file
//

#include "stdafx.h"
#include "cgUI.h"
#include "DlgBarTxt.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDlgBarTxt dialog

#define		WM_INITDLGBAR_TXT		WM_USER + WM_USER_TXT

BEGIN_MESSAGE_MAP(CDlgBarTxt, CDialogBar)
	//{{AFX_MSG_MAP(CDlgBarTxt)
	ON_MESSAGE( WM_INITDLGBAR_TXT, InitDialogBarHandler )
	ON_WM_CREATE()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

//////////////////////////////////////////////////////////////////////////////
CDlgBarTxt::CDlgBarTxt()
{
}//end of constructor

CDlgBarTxt::~CDlgBarTxt()
{
}//end of destructor


void CDlgBarTxt::DoDataExchange(CDataExchange* pDX)
{
	// TODO: Add your specialized code here and/or call the base class
	CDialogBar::DoDataExchange(pDX);
}//end of CDlgBarTxt::DoDataExchange

/////////////////////////////////////////////////////////////////////////////
// CDlgBarTxt message handlers
/////////////////////////////////////////////////////////////////////////////
BOOL CDlgBarTxt::OnInitDialogBar() 
{
	return( 1 );
}//end of CDlgBarTxt::OnInitDialogBar
/////////////////////////////////////////////////////////////////////////////
int CDlgBarTxt::OnCreate(LPCREATESTRUCT lpCreateStruct) 
{
	if (CDialogBar::OnCreate(lpCreateStruct) == -1)
		return -1;
	
	// TODO: Add your specialized creation code here
	// Post WM_INITDIALOGBAR message here to dialog bar
	PostMessage(WM_INITDLGBAR_TXT , 0 , 0 );
	
	return 0;
}//end of CDlgBarTxt::OnCreate
///////////////////////////////////////////////////////////////////////////////////
void CDlgBarTxt::InitDialogBarHandler(WORD wParam, DWORD lParam)
{
	UpdateData(FALSE);
	OnInitDialogBar() ;
}//end of CDlgBarBot::InitDialogBarHandler
