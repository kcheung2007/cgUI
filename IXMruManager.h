#if !defined(AFX_IXMRUMANAGER_H__6483616E_8C91_4E80_AF72_990D1C0BBBA4__INCLUDED_)
#define AFX_IXMRUMANAGER_H__6483616E_8C91_4E80_AF72_990D1C0BBBA4__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include <afxadv.h>

// IXMruManager.h : header file
//

// Callback function to test whether file belongs to a particular MRU file list
typedef BOOL (CALLBACK* MRUFILEFN)(LPCTSTR);

//////////////////////////////////////////////////////////////////////////////
// Modified CRecentFileList adds ID range
class CIXRecentFileList : public CRecentFileList 
{
public:
	DWORD		m_nBaseID;		 // base command ID
	MRUFILEFN	m_pMruFn;		 // function to test filename

	CIXRecentFileList(	DWORD		nBaseID,	
						LPCTSTR		lpszSection, 
						LPCTSTR		lpszEntryFormat,
						MRUFILEFN	pMruFn,
						int			nMaxMRU = 4,
						int			nMaxDispLen = AFX_ABBREV_FILENAME_LEN,
						DWORD		nStart = 0
					);

	~CIXRecentFileList();

	virtual void UpdateMenu(CCmdUI* pCmdUI);
	virtual BOOL IsFileOrProj(LPCTSTR lpszPathName);
};

/////////////////////////////////////////////////////////////////////////////
// IXMruManager command target

class CIXMruManager : public CCmdTarget
{
	DECLARE_DYNCREATE(CIXMruManager)

	CIXMruManager();           // protected constructor used by dynamic creation
	virtual ~CIXMruManager();

// Attributes
public:

// Operations
public:
	CIXRecentFileList* FindRecentFileList(DWORD nID);
	BOOL	AddToRecentFileList(LPCTSTR lpszPathName);
	BOOL	OnOpenRecentFile(UINT nID);
	VOID	OnUpdateRecentFileMenu(CCmdUI* pCmdUI);
	BOOL	Remove(DWORD dwRfl);
	DWORD	Add(DWORD nBaseID, LPCTSTR lpszSection,LPCTSTR lpszEntryFormat, MRUFILEFN pMruFn, DWORD nMaxMRU = 16, BOOL bNoLoad = 0,int nMaxDispLen = AFX_ABBREV_FILENAME_LEN, DWORD nStart = 0);

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CIXMruManager)
	//}}AFX_VIRTUAL

// Implementation
protected:
	CPtrList	m_listRfl;	// list of pointer to CIXRecentFileList

	// Generated message map functions
	//{{AFX_MSG(CIXMruManager)
		// NOTE - the ClassWizard will add and remove member functions here.
	//}}AFX_MSG

	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_IXMRUMANAGER_H__6483616E_8C91_4E80_AF72_990D1C0BBBA4__INCLUDED_)
