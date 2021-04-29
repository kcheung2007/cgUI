#if !defined(AFX_CHARMAP_H__5995B8BB_7E0C_4078_B85B_43AEFE8D9E96__INCLUDED_)
#define AFX_CHARMAP_H__5995B8BB_7E0C_4078_B85B_43AEFE8D9E96__INCLUDED_

#include "ImgCharMap.h"	// Added by ClassView
#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// CharMap.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CCharMap dialog

class CCharMap : public CDialog
{
// Construction
public:
	VOID InitDlgItemText();
	CCharMap(CWnd* pParent = NULL);   // standard constructor
	~CCharMap();

// Dialog Data
	//{{AFX_DATA(CCharMap)
	enum { IDD = IDD_DLG_CHAR_MAP };
	CScrollBar	m_vsbCharMap;
	CButton	m_btUp;
	CButton	m_btRight;
	CButton	m_btLeft;
	CButton	m_btDown;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CCharMap)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CCharMap)
	virtual BOOL OnInitDialog();
	afx_msg void OnBtBackspace();
	afx_msg void OnBtDelete();
	afx_msg void OnBtEnter();
	afx_msg void OnBtLeft();
	afx_msg void OnBtRight();
	afx_msg void OnBtUp();
	afx_msg void OnBtDown();
	virtual void OnOK();
	virtual void OnCancel();
	afx_msg void OnVScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
private:
	DWORD m_numTxt;
	HFONT* m_hFont;
	CImgCharMap m_imgCharMap;
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CHARMAP_H__5995B8BB_7E0C_4078_B85B_43AEFE8D9E96__INCLUDED_)
