#if !defined(AFX_ACGMSGBOX_H__9BC5A7C3_4911_4F57_B209_280649C59C02__INCLUDED_)
#define AFX_ACGMSGBOX_H__9BC5A7C3_4911_4F57_B209_280649C59C02__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// AcgMsgBox.h : header file
//

#define		FN_EXPORT_PAGE		0x500
#define		FN_EXPORT_PROJ		0x501

/////////////////////////////////////////////////////////////////////////////
// CAcgMsgBox dialog

class CAcgMsgBox : public CDialog
{
// Construction
public:
	DWORD GetFunctionState();
	VOID SetFunctionState( DWORD funcID );
	VOID GetCGSExportPageParam( CString path, DWORD fileFormat );
	VOID GetStrIndex( CString title, CString msg, CString butText );
	CAcgMsgBox(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CAcgMsgBox)
	enum { IDD = IDD_DLG_MESG };
	CStatic	m_ctlMsg1;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAcgMsgBox)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CAcgMsgBox)
	virtual void OnCancel();
	virtual BOOL OnInitDialog();
	afx_msg void OnTimer(UINT nIDEvent);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
private:
	BOOL m_bContinue;
	DWORD m_funcID;
	DWORD   m_expFormat;
	CString m_expPath;
	CString m_strMsg;
	CString m_strTitle;
	CString m_strButText;
	UINT	m_ctlTimer;
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_ACGMSGBOX_H__9BC5A7C3_4911_4F57_B209_280649C59C02__INCLUDED_)
