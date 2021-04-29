// EffectBin.cpp : implementation file
//

#include "stdafx.h"
#include "cgui.h"
#include "ACGS_Inc\\UI_BinMgr.h"
#include "EffectBin.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CEffectBin

CEffectBin::CEffectBin()
{
}

CEffectBin::~CEffectBin()
{
}


BEGIN_MESSAGE_MAP(CEffectBin, CEdit)
	//{{AFX_MSG_MAP(CEffectBin)
	ON_WM_PAINT()
	ON_WM_LBUTTONDOWN()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

//////////////////////////////////////////////////////////////////////////////////
// CEffectBin message handlers
//////////////////////////////////////////////////////////////////////////////////
void CEffectBin::OnPaint() 
{
	CPaintDC dc(this); // device context for painting
	CGS_BinRefresh( UIBIN_EFFECT );
}//end of CEffectBin::OnPaint()
//////////////////////////////////////////////////////////////////////////////////
void CEffectBin::OnLButtonDown(UINT nFlags, CPoint pt) 
{
	TRACE2("EffectBin.cpp : CEffectBin::OnLButtonDown x = %d, y = %d\n", pt.x, pt.y );	
	CGS_BinSelect(UIBIN_EFFECT, ABMC_DEFAULT, pt.x, pt.y); //JRS - CHECK: problem here

	CEdit::OnLButtonDown(nFlags, pt);
	GetParent()->SendMessage( WM_COMMAND, IDOK );
}//end of CEffectBin::OnLButtonDown
