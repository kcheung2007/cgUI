// IXMruManager.cpp : implementation file
//

#include "stdafx.h"
#include "cgui.h"
#include "MainFrm.h"
#include "IXMruManager.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CIXMruManager

IMPLEMENT_DYNCREATE(CIXMruManager, CCmdTarget)

CIXMruManager::CIXMruManager()
{
}

CIXMruManager::~CIXMruManager()
{
	while( !m_listRfl.IsEmpty() )
	{
		CIXRecentFileList* pRfl = (CIXRecentFileList*)m_listRfl.RemoveHead();
		pRfl->WriteList();
		delete pRfl;
	}
}//end of destructor

BEGIN_MESSAGE_MAP(CIXMruManager, CCmdTarget)
	//{{AFX_MSG_MAP(CIXMruManager)
		// NOTE - the ClassWizard will add and remove mapping macros here.
	//}}AFX_MSG_MAP
	// MRU - most recently used file menu
	ON_UPDATE_COMMAND_UI_RANGE(ID_FILE_MRU_FILE1, ID_FILE_MRU_PROJ8, OnUpdateRecentFileMenu)
	ON_COMMAND_EX_RANGE(ID_FILE_MRU_FILE1, ID_FILE_MRU_PROJ8, OnOpenRecentFile)
END_MESSAGE_MAP()

//////////////////////////////////////////////////////////////////////////////////////////
// CIXMruManager message handlers
//////////////////////////////////////////////////////////////////////////////////////////
// Add the recent file or project list to the MRU manager
// INPUT  : DWORD nBaseID - base command ID
// INPUT  :	LPCTSTR lpszSection - registry key name
// INPUT  :	LPCTSTR lpszEntryFormat - registry value name
// INPUT  :	MRUFILEFN pMruFn - filter function
// INPUT  :	DWORD nMaxMRU - max num menu entries
// INPUT  :	BOOL bNoLoad - don't load from reg (rarely used)
// INPUT  :	int nMaxDispLen - display length
// INPUT  :	DWORD nStart - starting ID
DWORD CIXMruManager::Add(DWORD nBaseID, LPCTSTR lpszSection,LPCTSTR lpszEntryFormat, MRUFILEFN pMruFn, DWORD nMaxMRU, BOOL bNoLoad,int nMaxDispLen,DWORD nStart)
{
	CIXRecentFileList* pRfl = new CIXRecentFileList(nBaseID, lpszSection, lpszEntryFormat, pMruFn, nMaxMRU, nMaxDispLen, nStart);
	if( !bNoLoad )
		pRfl->ReadList();		// load from registry

	m_listRfl.AddTail( pRfl );	// add to my list

	return(DWORD)pRfl;
}//end of CIXMruManager::Add
//////////////////////////////////////////////////////////////////////////////////////////
BOOL CIXMruManager::Remove( DWORD dwRfl )
{
	POSITION pos = m_listRfl.Find((void*)dwRfl);
	if( pos ) 
	{
		m_listRfl.RemoveAt(pos);
		return( 1 );
	}
	return( 0 );
}//end of CIXMruManager::Remove()
//////////////////////////////////////////////////////////////////////////////////////////
// Update recent file menu - convert menuitem to sequence of items with each file name.
VOID CIXMruManager::OnUpdateRecentFileMenu(CCmdUI *pCmdUI)
{
	TRACE0("IXMruManager.cpp - CIXMruManager::OnUpdateRecentFileMenu\n");
	CIXRecentFileList* pRfl = FindRecentFileList(pCmdUI->m_nID);	
	if( pRfl ) 
	{
		pCmdUI->Enable( (0 < pRfl->GetSize()) );
		pRfl->UpdateMenu( pCmdUI ); // implement MFC update
	} else 
		pCmdUI->ContinueRouting();

}//end of CIXMruManager::OnUpdateRecentFileMenu
//////////////////////////////////////////////////////////////////////////////////////////
// Custom message map - When the project was selected from the Recent Project menu item
// INPUT  : DWORD nID - Command ID
BOOL CIXMruManager::OnOpenRecentFile(UINT nID)
{
	TRACE1("IXMruManager.cpp - CIXMruManager::OnOpenRecentFile - nID = %d\n", nID );

	if( CGS_GetValDbl(EDIT_PROJECT_MODIFIED) ) // if current project has been modified
	{
		INT rc = ACGMessageBox( AfxGetMainWnd()->m_hWnd, _T("M0000"), _T("INFO"), MB_YESNOCANCEL | MB_ICONQUESTION );
		switch( rc )
		{
		case IDYES:
			if( CGS_GetValDbl(EDIT_PROJECT_NEEDS_FILENAME) )
				AfxGetMainWnd()->SendMessage( WM_COMMAND, ID_FILE_SAVE_AS, 0 );
			else
				AfxGetMainWnd()->SendMessage( WM_COMMAND, ID_FILE_SAVE, 0 );
			break;
		case IDNO:
			break;
		case IDCANCEL:
			return( 0 ); // do nothing
			break;
		}//end of swtich - rc
	}//end of if - projec modified

	CIXRecentFileList* pRfl = FindRecentFileList(nID);
	if( pRfl ) 
	{
		int nIndex = nID - pRfl->m_nBaseID; // index of file name in list
		ASSERT((*pRfl)[nIndex].GetLength() != 0);
		TRACE2("CIXMruManager: open file (%d) '%s'.\n", nIndex + 1,(LPCTSTR)(*pRfl)[nIndex]);

		// try to open it!
		char	szFileName[MAX_PATH];
		UnicodeToMultiByte( CP_ACP, (LPTSTR)(LPCTSTR)(*pRfl)[nIndex], szFileName );
/*
		WideCharToMultiByte(CP_ACP,                  // code page
							0,		                 // dwFlags
							(LPCTSTR)(*pRfl)[nIndex],// lpWideCharStr
							-1,                      // cchWideCharStr
							szFileName,				 // lpMultiByteStr
							sizeof(szFileName),		 // cchMultiByte
							NULL,                    // lpDefaultChar
							NULL					 // lpUsedDefaultChar
						);   
*/
		CGS_LoadProject( szFileName );

		return TRUE;
	}
	return( 0 );
}//end of CIXMruManager::OnOpenRecentFile
//////////////////////////////////////////////////////////////////////////////////////////
// Add a file name to one of the mru lists. Return FALSE if it doesn't belong.
// INPUT : LPCTSTR pPathName - Path Name
BOOL CIXMruManager::AddToRecentFileList(LPCTSTR pPathName)
{
	POSITION pos = m_listRfl.GetHeadPosition();
	while( pos )
	{
		CIXRecentFileList* pRfl = (CIXRecentFileList*)m_listRfl.GetNext(pos);
		if( pRfl->IsFileOrProj(pPathName) )
		{ // does it belong here?
			pRfl->Add(pPathName);
			return TRUE;
		}
	}
	return FALSE;

}//end of CIXMruManager::AddToRecentFileList
//////////////////////////////////////////////////////////////////////////////////////////
// INPUT : DWORD nID - command id
CIXRecentFileList* CIXMruManager::FindRecentFileList(DWORD nID)
{
	POSITION pos = m_listRfl.GetHeadPosition();
	while( pos ) 
	{
		CIXRecentFileList* pRfl = (CIXRecentFileList*)m_listRfl.GetNext(pos);
		if( pRfl->m_nBaseID <= nID && nID < pRfl->m_nBaseID + pRfl->GetSize() )
			return( pRfl ); // pointer to name of file list
	}//end of while - pos
	return( NULL );
}//end of CIXMruManager::FindRecentFileList

////////////////////////////////////////////////////////////////////////////////////////////
//IMPLEMENT_DYNAMIC(CIXRecentFileList, CRecentFileList)
////////////////////////////////////////////////////////////////////////////////////////////
CIXRecentFileList::CIXRecentFileList(DWORD nBaseID, LPCTSTR lpszSection, LPCTSTR lpszEntryFormat, MRUFILEFN pMruFn,	int nMaxMRU, int nMaxDispLen, DWORD nStart)
		: CRecentFileList(nStart, lpszSection, lpszEntryFormat, nMaxMRU)
{
		m_nBaseID = nBaseID;
		m_pMruFn = pMruFn;
}

CIXRecentFileList::~CIXRecentFileList()
{
}

////////////////////////////////////////////////////////////////////////////////////////////////
// Check if file name belongs in specific list (Project or Non-Project) : call callback fn.
BOOL CIXRecentFileList::IsFileOrProj(LPCTSTR pPathName)
{
	return m_pMruFn && (*m_pMruFn)(pPathName);
}//end of CIXRecentFileList::IsFileOrProj

///////////////////////////////////////////////////////////////////////////////////////////////////
// Update the menu dynamically. If the menu is really a submenu, MFC can't handle it.
// So fake out MFC by temporarily setting m_pMenu = m_pSubMenu.
void CIXRecentFileList::UpdateMenu(CCmdUI* pCmdUI)
{
	TRACE0("CIXRecentFileList::UpdateMenu\n" );

	CMenu* pMenu = pCmdUI->m_pMenu;
	if( pCmdUI->m_pSubMenu )
		pCmdUI->m_pMenu = pCmdUI->m_pSubMenu;

	CRecentFileList::UpdateMenu(pCmdUI);

	if( pCmdUI->m_pSubMenu )
		pCmdUI->m_pMenu = pMenu;

}//end of CIXRecentFileList::UpdateMenu
