#if !defined(AFX_ATTRIBIMPORT_H__9BDE4549_4D07_4345_B864_503A5C070A7D__INCLUDED_)
#define AFX_ATTRIBIMPORT_H__9BDE4549_4D07_4345_B864_503A5C070A7D__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// AttribImport.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CAttribImport dialog

class CAttribImport : public CDialog
{
// Construction
public:
	VOID DoValueUpdate();
	virtual BOOL PreTranslateMessage(MSG* pMsg);
	VOID	DeleteAttribImport();
	CAttribImport(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CAttribImport)
	enum { IDD = IDD_ATTRIB_IMPORT };
	CEdit	m_ctlEdWidthPercent;
	CEdit	m_ctlEdHeightPercent;
	CEdit	m_ctlEdY;
	CEdit	m_ctlEdX;
	CEdit	m_ctlEdWidth;
	CEdit	m_ctlEdRotate;
	CEdit	m_ctlEdPriority;
	CEdit	m_ctlEdHeight;
	CEdit	m_ctlEdBevel;
	CButton	m_btAdvance;
	CButton	m_btSaveStyle;
	CStatic	m_stcVPercent;
	CStatic	m_stcHPercent;
	CStatic	m_stcY;
	CStatic	m_stcX;
	CStatic	m_stcWidth;
	CStatic	m_stcRotate;
	CStatic	m_stcHeight;
	CStatic	m_stcBevel;
	CButton	m_btPlus;
	CButton	m_btMinus;
	CButton	m_btLock;
	CButton	m_btF;
	CButton	m_btB;
	double	m_edBevel;
	double	m_edHeight;
	double	m_edPriority;
	double	m_edRotate;
	double	m_edWidth;
	double	m_edX;
	double	m_edY;
	double	m_edWidthPercent;
	double	m_edHeightPercent;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAttribImport)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	CToolTipCtrl m_tooltip;

	// Generated message map functions
	//{{AFX_MSG(CAttribImport)
	virtual BOOL OnInitDialog();
	virtual void OnCancel();
	virtual void OnOK();
	afx_msg void OnBtGB();
	afx_msg void OnBtGF();
	afx_msg void OnBtGLock();
	afx_msg void OnBtGMinus();
	afx_msg void OnBtGPlus();
	afx_msg void OnDeltaposSpnGBevel(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnDeltaposSpnGHeight(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnDeltaposSpnGPriority(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnDeltaposSpnGRotate(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnDeltaposSpnGWidth(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnDeltaposSpnGX(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnDeltaposSpnGY(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnDeltaposSpnWidthPercent(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnDeltaposSpnHeightPercent(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnBtSaveStyle();
	afx_msg void OnBtAdvance();
	afx_msg void OnPaint();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
private:
	VOID InitDlgItemTextNTooltip();
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_ATTRIBIMPORT_H__9BDE4549_4D07_4345_B864_503A5C070A7D__INCLUDED_)
