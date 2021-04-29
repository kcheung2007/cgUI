#if !defined(AFX_DLGCAPTURE_H__2A53CB71_C54D_11D3_BFDB_005004648BC2__INCLUDED_)
#define AFX_DLGCAPTURE_H__2A53CB71_C54D_11D3_BFDB_005004648BC2__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// DlgCapture.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CDlgCapture dialog

class CDlgCapture : public CDialog
{
// Construction
public:
	VOID DoValueUpdate();
	VOID InitDlgItemTextNTooltip();
	virtual BOOL PreTranslateMessage(MSG* pMsg);
	CDlgCapture(CWnd* pParent = NULL);   // standard constructor
	~CDlgCapture();

// Dialog Data
	//{{AFX_DATA(CDlgCapture)
	enum { IDD = IDD_PAGE_CAPTURE };
	CComboBox	m_cbCapType;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDlgCapture)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	VOID InitComboString( LPTSTR ptFn, LPTSTR ptSection, CComboBox* ptCombo );
	CToolTipCtrl m_tooltip;

	// Generated message map functions
	//{{AFX_MSG(CDlgCapture)
	virtual BOOL OnInitDialog();
	afx_msg void OnSelchangeCbCaptureType();
	afx_msg void OnDeltaposSpnCapRate(NMHDR* pNMHDR, LRESULT* pResult);
	virtual void OnOK();
	virtual void OnCancel();
	afx_msg void OnBtGrab();
	afx_msg void OnBtMultiGrab();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
private:
	DWORD  m_numTxt;
	HFONT* m_hFont;
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DLGCAPTURE_H__2A53CB71_C54D_11D3_BFDB_005004648BC2__INCLUDED_)
