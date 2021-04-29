#if !defined(AFX_PALSLIDERCTRL_H__5D718491_E4CA_11D3_BF70_005004648BC2__INCLUDED_)
#define AFX_PALSLIDERCTRL_H__5D718491_E4CA_11D3_BF70_005004648BC2__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// PalSliderCtrl.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CPalSliderCtrl window

class CPalSliderCtrl : public CEdit
{
// Construction
public:
	CPalSliderCtrl();

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CPalSliderCtrl)
	protected:
	//}}AFX_VIRTUAL

// Implementation
public:
	VOID SortTag();

	DWORD *PalDibSectionPtr;
	virtual ~CPalSliderCtrl();


	// Generated message map functions
protected:
	//{{AFX_MSG(CPalSliderCtrl)
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg void OnPaint();
	afx_msg void OnRButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	//}}AFX_MSG

	DECLARE_MESSAGE_MAP()
private:
	VOID DoSwap( INT j, INT k );
	INT CompTag( INT j, INT k );	
	VOID MovingTag( INT x, UINT flag );
	INT m_lockTag;
	INT GetSelectedTag( INT x );
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_PALSLIDERCTRL_H__5D718491_E4CA_11D3_BF70_005004648BC2__INCLUDED_)
