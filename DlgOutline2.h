#if !defined(AFX_DLGOUTLINE2_H__AA6EBB65_D383_11D3_BF4E_005004648BC2__INCLUDED_)
#define AFX_DLGOUTLINE2_H__AA6EBB65_D383_11D3_BF4E_005004648BC2__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// DlgOutline2.h : header file
//
#include "AlphaDlg.h"
/////////////////////////////////////////////////////////////////////////////
// CDlgOutline2 dialog

class CDlgOutline2 : public CDialog
{
// Construction
public:
	VOID UnCheckAlphaButton();
	VOID DoValueUpdate();
	virtual BOOL PreTranslateMessage(MSG* pMsg);
	CDlgOutline2(CWnd* pParent = NULL);   // standard constructor
	~CDlgOutline2();

// Dialog Data
	//{{AFX_DATA(CDlgOutline2)
	enum { IDD = IDD_PG_OUTLINE_2 };
	CButton	m_ckOL2Enable;
//	CStatic	m_stcOutLn2CK;
	CButton	m_ckOutLn2;
	CStatic	m_stcYOffset;
	CStatic	m_stcXOffset;
	CStatic	m_stcSize;
	CStatic	m_stcFeather;
	CButton	m_btTranPal;
	CButton	m_btTranImp;
	CButton	m_btTranAlpha;
	CButton	m_btColPal;
	CButton	m_btColImp;
	DWORD	m_edOL2Trans;
	DWORD	m_edFeather;
	DWORD	m_edSize;
	DWORD	m_edXOffset;
	DWORD	m_edYOffset;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDlgOutline2)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	CToolTipCtrl m_tooltip;

	// Generated message map functions
	//{{AFX_MSG(CDlgOutline2)
	virtual void OnOK();
	virtual void OnCancel();
	virtual BOOL OnInitDialog();
	afx_msg void OnDeltaposSpnTrans(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnDeltaposSpnOl2Feather(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnDeltaposSpnOl2Size(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnDeltaposSpnOl2XOffset(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnDeltaposSpnOl2YOffset(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnBtColImpOl2();
	afx_msg void OnBtColorPal();
	afx_msg void OnBtTransAlphaOl2();
	afx_msg void OnBtTransImpOl2();
	afx_msg void OnBtTransPalOl2();
	afx_msg void OnPaint();
	afx_msg void OnCkOl2Enable();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
private:
	CAlphaDlg* m_pDlg;
	HFONT* m_hFont;
	DWORD m_numTxt;
	BOOL m_bAlpha;
	VOID InitStaticIcon();
	VOID InitEditSpinControl();
	VOID InitButtonIcon();
	VOID InitDlgItemTextNTooltip();
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DLGOUTLINE2_H__AA6EBB65_D383_11D3_BF4E_005004648BC2__INCLUDED_)
