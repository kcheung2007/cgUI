#if !defined(AFX_DLGPRESET_H__2A53CB74_C54D_11D3_BFDB_005004648BC2__INCLUDED_)
#define AFX_DLGPRESET_H__2A53CB74_C54D_11D3_BFDB_005004648BC2__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// DlgPreset.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CDlgPreset dialog

class CDlgPreset : public CDialog
{
// Construction
public:
	CDlgPreset(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CDlgPreset)
	enum { IDD = IDD_PAGE_PRESET };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDlgPreset)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CDlgPreset)
	afx_msg void OnVScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar);
	virtual BOOL OnInitDialog();
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
private:
	INT m_VSPos;
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DLGPRESET_H__2A53CB74_C54D_11D3_BFDB_005004648BC2__INCLUDED_)
