// cgUI.h : main header file for the CGUI application
//

#if !defined(AFX_CGUI_H__F12BAE24_C546_11D3_BFDB_005004648BC2__INCLUDED_)
#define AFX_CGUI_H__F12BAE24_C546_11D3_BFDB_005004648BC2__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "ACGS_Inc\\CGServerDll.h"
#include "resource.h"       // main symbols
#include "IXMruManager.h"	// Added by ClassView

#define		WM_USER_BOTTOM	0x01	// user message
#define		WM_USER_LEFT	0x02
#define		WM_USER_TXT		0x03
#define		WM_USER_PAL		0x04
#define		WM_USER_LNE		0x05
#define		WM_USER_BOX		0x06
#define		WM_USER_CIR		0x07
#define		WM_USER_FBG		0x08
#define		WM_USER_GRD		0x09

#define		WM_RESIZE_LEFT_BAR	(WM_USER + 0x30)
#define		WM_RESIZE_RTOP_BIN	(WM_USER + 0x31)
#define		WM_RESIZE_RBOT_BIN	(WM_USER + 0x32)

/////////////////////////////////////////////////////////////////////////////
// CCgUIApp:
// See cgUI.cpp for the implementation of this class
//

class CCgUIApp : public CWinApp
{
public:
	VOID SetAppPath( CString );
	CCgUIApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CCgUIApp)
	public:
	virtual BOOL InitInstance();
	virtual BOOL InitApplication();
	virtual int ExitInstance();
	virtual int Run();
	virtual void AddToRecentFileList(LPCTSTR lpszPathName);
	virtual BOOL OnCmdMsg(UINT nID, int nCode, void* pExtra, AFX_CMDHANDLERINFO* pHandlerInfo);
	//}}AFX_VIRTUAL

// Implementation
	//{{AFX_MSG(CCgUIApp)
	afx_msg void OnAppAbout();
	afx_msg void OnFilePageSetup();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
private:
protected:
	CIXMruManager m_ixFileMgr;
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CGUI_H__F12BAE24_C546_11D3_BFDB_005004648BC2__INCLUDED_)
