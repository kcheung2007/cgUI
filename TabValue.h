#if !defined(AFX_TABVALUE_H__82DD435E_79A7_4F6F_947C_9083C3A387E7__INCLUDED_)
#define AFX_TABVALUE_H__82DD435E_79A7_4F6F_947C_9083C3A387E7__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// TabValue.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CTabValue window

class CTabValue : public CWnd
{
// Construction
public:
	CTabValue();

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CTabValue)
	//}}AFX_VIRTUAL

// Implementation
public:
	VOID	SetAlignType( DWORD type );
	VOID	SetTabNum( UINT tab );
	VOID	SetTabPos( double pos );
	double	GetTabPos();
	DWORD	GetAlignType();
	DWORD	GetTabNum();
	virtual ~CTabValue();
/*
	double m_tabPos;
	DWORD  m_alignType;
	DWORD  m_tabNum;
*/
	// Generated message map functions
protected:
	//{{AFX_MSG(CTabValue)
		// NOTE - the ClassWizard will add and remove member functions here.
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
private:
	double m_tabPos;
	DWORD  m_alignType;
	DWORD  m_tabNum;
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_TABVALUE_H__82DD435E_79A7_4F6F_947C_9083C3A387E7__INCLUDED_)
