// PgAnnot.cpp : implementation file
//

#include "stdafx.h"
#include "cgui.h"
#include "PgAnnot.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CPgAnnot dialog


CPgAnnot::CPgAnnot(CWnd* pParent /*=NULL*/)
	: CDialog(CPgAnnot::IDD, pParent)
{
	//{{AFX_DATA_INIT(CPgAnnot)
	m_strPgTxt = _T("");
	//}}AFX_DATA_INIT
}


void CPgAnnot::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CPgAnnot)
	DDX_Control(pDX, IDC_ED_ANNOT, m_edPgTxt);
	DDX_Text(pDX, IDC_ED_ANNOT, m_strPgTxt);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CPgAnnot, CDialog)
	//{{AFX_MSG_MAP(CPgAnnot)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

//////////////////////////////////////////////////////////////////////////////////////////////
// CPgAnnot message handlers
//////////////////////////////////////////////////////////////////////////////////////////////
char* CPgAnnot::GetPgAnnotation()
{
	return( (char*)(LPCTSTR)m_strPgTxt );
}//end of CPgAnnot::GetPgAnnotation()
//////////////////////////////////////////////////////////////////////////////////////////////
VOID CPgAnnot::SetAnnotString(char *pStr)
{
	m_strPgTxt = pStr;
}//end of CPgAnnot::SetAnnotString(char *pStr)
//////////////////////////////////////////////////////////////////////////////////////////////
BOOL CPgAnnot::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	m_edPgTxt.SetWindowText( m_strPgTxt );
	
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}//end of CPgAnnot::OnInitDialog
