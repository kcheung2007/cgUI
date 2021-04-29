#if !defined(AFX_IMGCHARMAP_H__DA945929_FA58_4344_9BDE_E9B0AD6D758A__INCLUDED_)
#define AFX_IMGCHARMAP_H__DA945929_FA58_4344_9BDE_E9B0AD6D758A__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// ImgCharMap.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CImgCharMap window

class CImgCharMap : public CEdit
{
// Construction
public:
	CImgCharMap();

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CImgCharMap)
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CImgCharMap();

	// Generated message map functions
protected:
	//{{AFX_MSG(CImgCharMap)
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnPaint();
	//}}AFX_MSG

	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_IMGCHARMAP_H__DA945929_FA58_4344_9BDE_E9B0AD6D758A__INCLUDED_)
