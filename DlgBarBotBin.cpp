// DlgBarBox.cpp : implementation file
//

#include "stdafx.h"
#include "cgUI.h"
#include "DlgBarBotBin.h"
#include "MainFrm.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDlgBarBinBot dialog

#define		WM_INITDLGBAR_BOX		WM_USER + WM_USER_BOX

BEGIN_MESSAGE_MAP(CDlgBarBinBot, CDialogBar)
	//{{AFX_MSG_MAP(CDlgBarBinBot)
	ON_WM_CREATE()
	ON_MESSAGE( WM_INITDLGBAR_BOX, InitDialogBarHandler )
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

//////////////////////////////////////////////////////////////////////////////
CDlgBarBinBot::CDlgBarBinBot()
{
}//end of constructor

CDlgBarBinBot::~CDlgBarBinBot()
{
}//end of destructor


void CDlgBarBinBot::DoDataExchange(CDataExchange* pDX)
{
	// TODO: Add your specialized code here and/or call the base class
	CDialogBar::DoDataExchange(pDX);
}//end of CDlgBarBinBot::DoDataExchange

/////////////////////////////////////////////////////////////////////////////
// CDlgBarBinBot message handlers
/////////////////////////////////////////////////////////////////////////////
void CDlgBarBinBot::OnInitDialogBar() 
{
	
}//end of CDlgBarBinBot::OnInitDialogBar
/////////////////////////////////////////////////////////////////////////////
int CDlgBarBinBot::OnCreate(LPCREATESTRUCT lpCreateStruct) 
{
	TRACE0("DlgBarBox.cpp : OnCreate - dialog box\n");
	if (CDialogBar::OnCreate(lpCreateStruct) == -1)
		return -1;
	
	// TODO: Add your specialized creation code here
	// Post WM_INITDIALOGBAR message here to dialog bar
	PostMessage(WM_INITDLGBAR_BOX , 0 , 0 );
	
	return 0;
}//end of CDlgBarBinBot::OnCreate
///////////////////////////////////////////////////////////////////////////////////
void CDlgBarBinBot::InitDialogBarHandler(WORD wParam, DWORD lParam)
{
	TRACE0("DlgBarBox.cpp : InitDialogBarHandler\n");
	UpdateData(FALSE);
	OnInitDialogBar() ;
}//end of CDlgBarBot::InitDialogBarHandler

///////////////////////////////////////////////////////////////////////////////////

