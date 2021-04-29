#if !defined(AFX_SPELLCHECK_H__EEAB2D67_7C9C_40C1_827C_EDC69E0ECB6C__INCLUDED_)
#define AFX_SPELLCHECK_H__EEAB2D67_7C9C_40C1_827C_EDC69E0ECB6C__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// SpellCheck.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CSpellCheck dialog

class CSpellCheck : public CDialog
{
// Construction
public:
	CSpellCheck(CWnd* pParent = NULL);   // standard constructor
	~CSpellCheck();

// Dialog Data
	//{{AFX_DATA(CSpellCheck)
	enum { IDD = IDD_DLG_SPELL_CHECKER };
	CButton	m_btOK;
	CButton	m_btCancel;
	CStatic	m_stcDoneMsg;
	CStatic	m_stcAlterSpell;
	CStatic	m_stcOrigWord;
	CStatic	m_stcChangeTo;
	CListBox	m_lbAlterSpell;
	CString	m_edChangeTo;
	CString	m_edOrigWord;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CSpellCheck)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CSpellCheck)
	afx_msg void OnBtAdd();
	afx_msg void OnBtIgnore();
	afx_msg void OnBtReplace();
	afx_msg void OnDblclkLbAlterSpell();
	virtual BOOL OnInitDialog();
	virtual void OnCancel();
	virtual void OnOK();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
private:
	HFONT* m_hFont;
	DWORD m_numTxt;
	BOOL m_Done;
	VOID InitDlgItemText();
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SPELLCHECK_H__EEAB2D67_7C9C_40C1_827C_EDC69E0ECB6C__INCLUDED_)
