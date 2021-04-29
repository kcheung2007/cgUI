// ImgCharMap.cpp : implementation file
//

#include "stdafx.h"
#include "cgui.h"
#include "ImgCharMap.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CImgCharMap

CImgCharMap::CImgCharMap()
{
}

CImgCharMap::~CImgCharMap()
{
}


BEGIN_MESSAGE_MAP(CImgCharMap, CEdit)
	//{{AFX_MSG_MAP(CImgCharMap)
	ON_WM_LBUTTONDOWN()
	ON_WM_PAINT()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CImgCharMap message handlers
/////////////////////////////////////////////////////////////////////////////
void CImgCharMap::OnLButtonDown(UINT nFlags, CPoint pt) 
{
	// TODO: Add your message handler code here and/or call default
	TRACE2("ImagCharMap.cpp : CImgCharMap::OnLButtonDown x = %d, y = %d\n", pt.x, pt.y );
	CEdit::OnLButtonDown(nFlags, pt);
}//end of CImgCharMap::OnLButtonDown
/////////////////////////////////////////////////////////////////////////////
void CImgCharMap::OnPaint() 
{
	CPaintDC dc(this); // device context for painting
	
	// TO DO : CharMatRepaint();
	
	// Do not call CEdit::OnPaint() for painting messages
}//end of CImgCharMap::OnPaint
