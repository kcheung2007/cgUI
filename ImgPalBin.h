#if !defined(AFX_IMGPALBIN_H__7C7CADB1_E3ED_11D3_BF6F_005004648BC2__INCLUDED_)
#define AFX_IMGPALBIN_H__7C7CADB1_E3ED_11D3_BF6F_005004648BC2__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// ImgPalBin.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CImgPalBin window

class CImgPalBin : public CEdit
{
// Construction
public:
	CImgPalBin();

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CImgPalBin)
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CImgPalBin();

	// Generated message map functions
protected:
	//{{AFX_MSG(CImgPalBin)
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnPaint();
	//}}AFX_MSG

	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_IMGPALBIN_H__7C7CADB1_E3ED_11D3_BF6F_005004648BC2__INCLUDED_)
