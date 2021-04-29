#if !defined(AFX_TABSETUP_H__7B4E6DE0_5F47_4944_80AE_4854D0F5C8CB__INCLUDED_)
#define AFX_TABSETUP_H__7B4E6DE0_5F47_4944_80AE_4854D0F5C8CB__INCLUDED_

#include "TabValue.h"	// Added by ClassView
#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// TabSetup.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CTabSetup dialog

class CTabSetup : public CDialog
{
// Construction
public:
	VOID InitDlgItemText();
	CTabSetup(CWnd* pParent = NULL);   // standard constructor
	~CTabSetup();
	CTabValue m_curTabVal;
	CTabValue m_initTabVal[10];

// Dialog Data
	//{{AFX_DATA(CTabSetup)
	enum { IDD = IDD_TAB_SETUP };
	CButton	m_rbTab10;
	CButton	m_rbTab9;
	CButton	m_rbTab8;
	CButton	m_rbTab7;
	CButton	m_rbTab6;
	CButton	m_rbTab5;
	CButton	m_rbTab4;
	CButton	m_rbTab3;
	CButton	m_rbTab2;
	CButton	m_rbTab1;
	CButton	m_rbRight;
	CButton	m_rbLeft;
	CButton	m_rbDecimal;
	CButton	m_rbCenter;
	CEdit	m_edPos;
	CButton	m_btReset;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CTabSetup)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CTabSetup)
	virtual void OnOK();
	virtual BOOL OnInitDialog();
	afx_msg void OnRbTab1();
	afx_msg void OnRbTab2();
	afx_msg void OnRbTab3();
	afx_msg void OnRbTab4();
	afx_msg void OnRbTab5();
	afx_msg void OnRbTab6();
	afx_msg void OnRbTab7();
	afx_msg void OnRbTab8();
	afx_msg void OnRbAlignLeft();
	afx_msg void OnRbAlignCenter();
	afx_msg void OnRbAlignRight();
	afx_msg void OnRbAlignDecimal();
	virtual void OnCancel();
	afx_msg void OnDeltaposSpnPos(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnBtReset();
	afx_msg void OnRbTab10();
	afx_msg void OnRbTab9();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
private:
	DWORD m_numTxt;
	HFONT* m_hFont;
	VOID SetTabValToCore();
	VOID UpdateTabSetupDlg( CTabValue* pTabValObj );
	VOID SetTabValObj( DWORD nTab, CTabValue* pTabValObj );
	VOID SetDlgPosition();
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_TABSETUP_H__7B4E6DE0_5F47_4944_80AE_4854D0F5C8CB__INCLUDED_)
