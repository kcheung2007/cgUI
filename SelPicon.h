#if !defined(AFX_SELPICON_H__B35533B8_73CC_4A9D_81AE_FEA25578FCCC__INCLUDED_)
#define AFX_SELPICON_H__B35533B8_73CC_4A9D_81AE_FEA25578FCCC__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// SelPicon.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CSelPicon dialog

class CSelPicon : public CDialog
{
// Construction
public:
	virtual BOOL PreTranslateMessage(MSG* pMsg);
	CSelPicon(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CSelPicon)
	enum { IDD = IDD_DLG_ICON_SELECT };
	CButton	m_btRight;
	CButton	m_btLeft;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CSelPicon)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	CToolTipCtrl m_tooltip;

	// Generated message map functions
	//{{AFX_MSG(CSelPicon)
	afx_msg void OnMoveLeft();
	afx_msg void OnMoveRight();
	afx_msg void OnRbSelect();
	afx_msg void OnRbSelectAll();
	afx_msg void OnRbSelectClear();
	afx_msg void OnRbSelectGfx();
	afx_msg void OnRbSelectText();
	afx_msg void OnRbUnselect();
	virtual BOOL OnInitDialog();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
private:
	VOID InitDlgItemText();
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SELPICON_H__B35533B8_73CC_4A9D_81AE_FEA25578FCCC__INCLUDED_)
