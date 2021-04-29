#if !defined(AFX_ATTRIBCURVE_H__9AB3D70F_3E80_4E77_9FDD_CBF45B6F240B__INCLUDED_)
#define AFX_ATTRIBCURVE_H__9AB3D70F_3E80_4E77_9FDD_CBF45B6F240B__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// AttribCurve.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CAttribCurve dialog

class CAttribCurve : public CDialog
{
// Construction
public:
	virtual BOOL PreTranslateMessage(MSG* pMsg);
	VOID DeleteAttribCurve();
	VOID DoValueUpdate();
	CAttribCurve(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CAttribCurve)
	enum { IDD = IDD_ATTRIB_CURVE };
	CEdit	m_ctlEdY;
	CEdit	m_ctlEdX;
	CEdit	m_ctlEdVertex;
	CEdit	m_ctlEdThick;
	CEdit	m_ctlEdRound;
	CEdit	m_ctlEdRotate;
	CEdit	m_ctlEdPriority;
	CEdit	m_ctlEdLength;
	CEdit	m_ctlEdBevel;
	CStatic	m_stcY;
	CStatic	m_stcX;
	CStatic	m_stcVertices;
	CStatic	m_stcThick;
	CStatic	m_stcRoundness;
	CStatic	m_stcRotate;
	CStatic	m_stcLength;
	CStatic	m_stcBevel;
	CButton	m_btSaveStyle;
	CButton	m_btPlus;
	CButton	m_btMinus;
	CButton	m_btLock;
	CButton	m_btF;
	CButton	m_btB;
	CButton	m_btAdvance;
	double	m_edBevel;
	double	m_edLength;
	double	m_edPriority;
	double	m_edRotate;
	double	m_edRoundness;
	double	m_edThick;
	double	m_edVertices;
	double	m_edX;
	double	m_edY;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAttribCurve)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	CToolTipCtrl m_tooltip;

	// Generated message map functions
	//{{AFX_MSG(CAttribCurve)
	virtual void OnOK();
	virtual void OnCancel();
	afx_msg void OnBtSaveStyle();
	afx_msg void OnBtAdvance();
	afx_msg void OnBtCLock();
	afx_msg void OnBtCF();
	afx_msg void OnBtCPlus();
	afx_msg void OnBtCMinus();
	afx_msg void OnBtCB();
	virtual BOOL OnInitDialog();
	afx_msg void OnDeltaposSpnCBevel(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnDeltaposSpnCLength(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnDeltaposSpnCPriority(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnDeltaposSpnCRotate(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnDeltaposSpnCRoundness(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnDeltaposSpnCThick(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnDeltaposSpnCVertices(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnDeltaposSpnCX(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnDeltaposSpnCY(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnPaint();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
private:
	VOID InitDlgItemTextNTooltip();
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_ATTRIBCURVE_H__9AB3D70F_3E80_4E77_9FDD_CBF45B6F240B__INCLUDED_)
