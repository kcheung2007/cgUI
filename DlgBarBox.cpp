// DlgBarBox.cpp : implementation file
//

#include "stdafx.h"
#include "cgUI.h"
#include "DlgBarBox.h"
#include "MainFrm.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDlgBarBox dialog

#define		WM_INITDLGBAR_BOX		WM_USER + WM_USER_BOX

BEGIN_MESSAGE_MAP(CDlgBarBox, CDialogBar)
	//{{AFX_MSG_MAP(CDlgBarBox)
	ON_WM_CREATE()
	ON_MESSAGE( WM_INITDLGBAR_BOX, InitDialogBarHandler )
	ON_WM_MOVE()
	ON_WM_LBUTTONDBLCLK()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

//////////////////////////////////////////////////////////////////////////////
CDlgBarBox::CDlgBarBox()
{
}//end of constructor

CDlgBarBox::~CDlgBarBox()
{
}//end of destructor


void CDlgBarBox::DoDataExchange(CDataExchange* pDX)
{
	// TODO: Add your specialized code here and/or call the base class
	CDialogBar::DoDataExchange(pDX);
}//end of CDlgBarBox::DoDataExchange

/////////////////////////////////////////////////////////////////////////////
// CDlgBarBox message handlers
/////////////////////////////////////////////////////////////////////////////
void CDlgBarBox::OnInitDialogBar() 
{
	
}//end of CDlgBarBox::OnInitDialogBar
/////////////////////////////////////////////////////////////////////////////
int CDlgBarBox::OnCreate(LPCREATESTRUCT lpCreateStruct) 
{
	TRACE0("DlgBarBox.cpp : OnCreate - dialog box\n");
	if (CDialogBar::OnCreate(lpCreateStruct) == -1)
		return -1;
	
	// TODO: Add your specialized creation code here
	// Post WM_INITDIALOGBAR message here to dialog bar
	PostMessage(WM_INITDLGBAR_BOX , 0 , 0 );
	
	return 0;
}//end of CDlgBarBox::OnCreate
///////////////////////////////////////////////////////////////////////////////////
void CDlgBarBox::InitDialogBarHandler(WORD wParam, DWORD lParam)
{
	TRACE0("DlgBarBox.cpp : InitDialogBarHandler\n");
	UpdateData(FALSE);
	OnInitDialogBar() ;
}//end of CDlgBarBot::InitDialogBarHandler


void CDlgBarBox::OnMove(int x, int y) 
{
	CDialogBar::OnMove(x, y);

	// TODO: Add your message handler code here


	TRACE0("DlgBarBox.cpp : OnMove\n");
}



void CDlgBarBox::OnLButtonDblClk(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
	TRACE0("DlgBarBox.cpp : OnLButtonDblClk\n");
	CDialogBar::OnLButtonDblClk(nFlags, point);
}
