#if !defined(AFX_DLGSELECT_H__B0BA5466_7627_4C77_A3AB_74010EF2A618__INCLUDED_)
#define AFX_DLGSELECT_H__B0BA5466_7627_4C77_A3AB_74010EF2A618__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// DlgSelect.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CDlgSelect dialog

class CDlgSelect : public CDialog
{
// Construction
public:
	VOID InitDlgItemTextNTooltip();
	CDlgSelect(CWnd* pParent = NULL);   // standard constructor
	~CDlgSelect();

// Dialog Data
	//{{AFX_DATA(CDlgSelect)
	enum { IDD = IDD_PAGE_SELECTION };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDlgSelect)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CDlgSelect)
	virtual void OnOK();
	virtual void OnCancel();
	virtual BOOL OnInitDialog();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
private:
	HFONT* m_hFont;
	DWORD m_numTxt;
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DLGSELECT_H__B0BA5466_7627_4C77_A3AB_74010EF2A618__INCLUDED_)
