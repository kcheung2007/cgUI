#if !defined(AFX_DLGOUTLINE1_H__AA6EBB64_D383_11D3_BF4E_005004648BC2__INCLUDED_)
#define AFX_DLGOUTLINE1_H__AA6EBB64_D383_11D3_BF4E_005004648BC2__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// DlgOutline1.h : header file
//

#include "AlphaDlg.h"
/////////////////////////////////////////////////////////////////////////////
// CDlgOutline1 dialog

class CDlgOutline1 : public CDialog
{
// Construction
public:
	VOID UnCheckAlphaButton();
	VOID DoValueUpdate();
	virtual BOOL PreTranslateMessage(MSG* pMsg);
	CDlgOutline1(CWnd* pParent = NULL);   // standard constructor
	~CDlgOutline1();

// Dialog Data
	//{{AFX_DATA(CDlgOutline1)
	enum { IDD = IDD_PG_OUTLINE_1 };
	CButton	m_ckOL1Enable;
//	CStatic	m_stcOutLn1CK;
	CButton	m_ckOutLn1;
	CStatic	m_stcYOffset;
	CStatic	m_stcXOffset;
	CStatic	m_stcSize;
	CStatic	m_stcFeather;
	CButton	m_btTranPal;
	CButton	m_btTranImp;
	CButton	m_btTranAlpha;
	CButton	m_btColPal;
	CButton	m_btColImp;
	DWORD	m_edOLTrans;
	DWORD	m_edFeather;
	DWORD	m_edSize;
	DWORD	m_edXOffset;
	DWORD	m_edYOffset;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDlgOutline1)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	CToolTipCtrl m_tooltip;
	// Generated message map functions
	//{{AFX_MSG(CDlgOutline1)
	virtual void OnOK();
	virtual void OnCancel();
	virtual BOOL OnInitDialog();
	afx_msg void OnDeltaposSpnTrans(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnDeltaposSpnOl1Feather(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnDeltaposSpnOl1Size(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnDeltaposSpnOl1XOffset(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnDeltaposSpnOl1YOffset(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnBtColImpOl();
	afx_msg void OnBtColorPal();
	afx_msg void OnBtTransAlphaOl();
	afx_msg void OnBtTransImpOl();
	afx_msg void OnBtTransPalOl();
	afx_msg void OnPaint();
	afx_msg void OnCkOl1Enable();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
private:
	CAlphaDlg* m_pDlg;
	DWORD m_numTxt;
	HFONT* m_hFont;
	BOOL m_bAlpha;
	VOID InitStaticIcon();
	VOID InitEditSpinControl();
	VOID InitButtonIcon();
	VOID InitDlgItemTextNTooltip();
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DLGOUTLINE1_H__AA6EBB64_D383_11D3_BF4E_005004648BC2__INCLUDED_)
