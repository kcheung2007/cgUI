#if !defined(AFX_PROGSETTING_H__D48ADEFE_D22F_4AA0_ACC0_B393D49B4CFA__INCLUDED_)
#define AFX_PROGSETTING_H__D48ADEFE_D22F_4AA0_ACC0_B393D49B4CFA__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// ProgSetting.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CProgSetting dialog

class CProgSetting : public CDialog
{
// Construction
public:
	CProgSetting(CWnd* pParent = NULL);   // standard constructor
	~CProgSetting();

// Dialog Data
	//{{AFX_DATA(CProgSetting)
	enum { IDD = IDD_DLG_PROG_SETTING };
	CButton	m_ckLastProj;
	CButton	m_ckStyleSet;
	CComboBox	m_cbKeyboard;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CProgSetting)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CProgSetting)
	virtual BOOL OnInitDialog();
	virtual void OnOK();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
private:
	HFONT* m_hFont;
	DWORD m_numTxt;

	VOID InitComboString( LPTSTR ptFn, LPTSTR ptSection, CComboBox* ptCombo );
	VOID InitDlgItemText();
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_PROGSETTING_H__D48ADEFE_D22F_4AA0_ACC0_B393D49B4CFA__INCLUDED_)
