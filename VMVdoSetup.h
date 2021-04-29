#if !defined(AFX_VMVDOSETUP_H__13F90B72_FA51_468F_BE7F_8F8BEFF54D1A__INCLUDED_)
#define AFX_VMVDOSETUP_H__13F90B72_FA51_468F_BE7F_8F8BEFF54D1A__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// VMVdoSetup.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CVMVdoSetup dialog

class CVMVdoSetup : public CDialog
{
// Construction
public:
	CVMVdoSetup(CWnd* pParent = NULL);   // standard constructor
	~CVMVdoSetup();

// Dialog Data
	//{{AFX_DATA(CVMVdoSetup)
	enum { IDD = IDD_VM_VDO_SETUP };
	CButton	m_ckDefringe;
	CButton	m_ckAntiFlicker;
	CComboBox	m_cbVMPreview;
	CComboBox	m_cbVMOverlay;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CVMVdoSetup)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CVMVdoSetup)
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

#endif // !defined(AFX_VMVDOSETUP_H__13F90B72_FA51_468F_BE7F_8F8BEFF54D1A__INCLUDED_)
