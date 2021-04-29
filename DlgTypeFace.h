#if !defined(AFX_DLGTYPEFACE_H__838348E0_191D_47FD_BBEB_A4B867FA1435__INCLUDED_)
#define AFX_DLGTYPEFACE_H__838348E0_191D_47FD_BBEB_A4B867FA1435__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// DlgTypeFace.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CDlgTypeFace dialog

class CDlgTypeFace : public CDialog
{
// Construction
public:
	VOID InitDlgItemText();
	CDlgTypeFace(CWnd* pParent = NULL);   // standard constructor
	~CDlgTypeFace();

// Dialog Data
	//{{AFX_DATA(CDlgTypeFace)
	enum { IDD = IDD_TYPE_FACE_OPT };
	CEdit	m_ctlEdUdlSize;
	CEdit	m_ctlEdUdlOffset;
	CEdit	m_ctlEdSupSize;
	CEdit	m_ctlEdSupOffset;
	CEdit	m_ctlEdSubSize;
	CEdit	m_ctlEdSubOffset;
	CEdit	m_ctlEdSmallCapHi;
	CEdit	m_ctlEdItalicAngle;
	CButton	m_btPal;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDlgTypeFace)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CDlgTypeFace)
	virtual BOOL OnInitDialog();
	afx_msg void OnDeltaposSpnItalicAngle(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnDeltaposSpnSmallCapHeight(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnDeltaposSpnSubOffset(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnDeltaposSpnSubSize(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnDeltaposSpnSuperOffset(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnDeltaposSpnSuperSize(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnDeltaposSpnUnderlneOffset(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnDeltaposSpnUnderlneSize(NMHDR* pNMHDR, LRESULT* pResult);
	virtual void OnOK();
	afx_msg void OnBtPalette();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
private:
	DWORD	m_numTxt;
	HFONT*	m_hFont;
	INT		m_edItalicAngle;
	INT		m_edSmallCapHi;
	INT		m_edSupSize;
	INT		m_edSupOffset;
	INT		m_edSubSize;
	INT		m_edSubOffset;
	INT		m_edUdlSize;
	INT		m_edUdlOffset;
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DLGTYPEFACE_H__838348E0_191D_47FD_BBEB_A4B867FA1435__INCLUDED_)
