#if !defined(AFX_MFCAX_H__BE20B044_E4AE_11D3_BF70_005004648BC2__INCLUDED_)
#define AFX_MFCAX_H__BE20B044_E4AE_11D3_BF70_005004648BC2__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// Machine generated IDispatch wrapper class(es) created by Microsoft Visual C++

// NOTE: Do not modify the contents of this file.  If this class is regenerated by
//  Microsoft Visual C++, your modifications will be overwritten.

/////////////////////////////////////////////////////////////////////////////
// CMfcAX wrapper class

class CMfcAX : public CWnd
{
protected:
	DECLARE_DYNCREATE(CMfcAX)
public:
	CLSID const& GetClsid()
	{
		static CLSID const clsid
			= { 0xbe20b033, 0xe4ae, 0x11d3, { 0xbf, 0x70, 0x0, 0x50, 0x4, 0x64, 0x8b, 0xc2 } };
		return clsid;
	}
	virtual BOOL Create(LPCTSTR lpszClassName,
		LPCTSTR lpszWindowName, DWORD dwStyle,
		const RECT& rect,
		CWnd* pParentWnd, UINT nID,
		CCreateContext* pContext = NULL)
	{ return CreateControl(GetClsid(), lpszWindowName, dwStyle, rect, pParentWnd, nID); }

    BOOL Create(LPCTSTR lpszWindowName, DWORD dwStyle,
		const RECT& rect, CWnd* pParentWnd, UINT nID,
		CFile* pPersist = NULL, BOOL bStorage = FALSE,
		BSTR bstrLicKey = NULL)
	{ return CreateControl(GetClsid(), lpszWindowName, dwStyle, rect, pParentWnd, nID,
		pPersist, bStorage, bstrLicKey); }

// Attributes
public:

// Operations
public:
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MFCAX_H__BE20B044_E4AE_11D3_BF70_005004648BC2__INCLUDED_)
