// cgUIDoc.h : interface of the CCgUIDoc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_CGUIDOC_H__F12BAE2C_C546_11D3_BFDB_005004648BC2__INCLUDED_)
#define AFX_CGUIDOC_H__F12BAE2C_C546_11D3_BFDB_005004648BC2__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class CCgUIDoc : public CDocument
{
protected: // create from serialization only
	CCgUIDoc();
	DECLARE_DYNCREATE(CCgUIDoc)

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CCgUIDoc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CCgUIDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CCgUIDoc)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CGUIDOC_H__F12BAE2C_C546_11D3_BFDB_005004648BC2__INCLUDED_)
