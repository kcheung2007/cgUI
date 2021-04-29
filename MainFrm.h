// MainFrm.h : interface of the CMainFrame class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_MAINFRM_H__F12BAE28_C546_11D3_BFDB_005004648BC2__INCLUDED_)
#define AFX_MAINFRM_H__F12BAE28_C546_11D3_BFDB_005004648BC2__INCLUDED_

#include "DlgBarBottom.h"	// Added by ClassView
#include "DlgBarLeft.h"
#include "DlgBarTopBin.h"
#include "DlgBarCir.h"
#include "DlgBarFbg.h"
#include "DlgBarGrd.h"
#include "DlgBarLne.h"
#include "DlgBarPal.h"
#include "DlgPage.h"
#include "PageSetupDLg.h"	// Added by ClassView
#include "DlgLine.h"	// Added by ClassView
#include "AttribImport.h"
#include "TabSetup.h"	// Added by ClassView

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

extern	TCHAR   g_szAppPath[_MAX_PATH];

const int MAX_LIST = 16; // max. number of file list for both file and project type
const int MAX_FILE = 8;
const int MAX_PROJ = 8;

struct MENU_DATA
{
	TCHAR szSearch[50];
	TCHAR szDisplay[50];
};

class CMainFrame : public CMDIFrameWnd
{
	DECLARE_DYNAMIC(CMainFrame)
public:
	CMainFrame();

// Attributes
public:
	MENU_DATA* m_pMainMenu;
	MENU_DATA* m_pSubMenu;
	
// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMainFrame)
	public:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	virtual BOOL PreTranslateMessage(MSG* pMsg);
	//}}AFX_VIRTUAL

// Implementation
public:
	BOOL SaveScanedImage( HGLOBAL _hDIB );
	VOID CleanUpApp();
	VOID InitTwain();
	CTabSetup m_dlgTabSetup;
	VOID AddFileNameToMenu( DWORD startID, CString, UINT posMenu );
	INT FindMenuItemPos( CMenu *Menu, LPCTSTR MenuString );
	VOID ChangeFileMenuText();

	VOID CleanAttribDlgs();
	void CreateTxtGfxToolbar();
	void DockControlBarBottomOf( CControlBar* pBottomOf, CControlBar *pBar );
	VOID SetToolbarTipText( UINT nID, CString& strTip);
	BOOL OnDynamicTipText(UINT id, NMHDR* pNMHDR, LRESULT* pResult);
	void CreateDlgBarPal();
	void CreateDlgBarGrd();
	void CreateDlgBarFbg();
	void CreateDlgBarCir();
	void CreateDlgBarTopBin();
	void CreateDlgBarBottom();
	void CreateDlgBarLeft();
	void CreateMainToolbar();
	void DockControlBarLeftOf(CControlBar* Bar,CControlBar* LeftOf);
	virtual ~CMainFrame();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:  // control bar embedded members
	CToolBar		m_wndToolBar;
	CToolBar		m_wndPanelBar;
	CToolBar		m_wndTxtGfxBar;

// Generated message map functions
protected:	
	CPageSetupDlg	m_cbPSType;
	CDlgBarLeft		m_dlgBarLeft;
	CDlgBarBot		m_dlgBarBot;
	CDlgBarBinTop	m_dlgBarBinTop;
	CDlgBarCir		m_dlgBarCir;
	CDlgBarFbg		m_dlgBarFbg;
	CDlgBarGrd		m_dlgBarGrd;
	CDlgBarLne		m_dlgBarLne;
	CDlgBarPal		m_dlgBarPal;
				
	//{{AFX_MSG(CMainFrame)
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnFmtLeft();
	afx_msg void OnFmtCenter();
	afx_msg void OnFmtRight();
	afx_msg void OnFmtJustify();
	afx_msg void OnFmtTop();
	afx_msg void OnFmtMiddle();
	afx_msg void OnFmtBottom();
	afx_msg void OnViewPanelBar();
	afx_msg void OnUpdateViewPanelBar(CCmdUI* pCmdUI);
	afx_msg void OnSize(UINT nType, int cx, int cy);
	afx_msg void OnFmtGrid();
	afx_msg void OnAddObjBox();
	afx_msg void OnAddObjFill();
	afx_msg void OnAddObjLine();
	afx_msg void OnAddObjOval();
	afx_msg void OnAddObjText();
	afx_msg void OnAddObjImport();
	afx_msg void OnFormatPal();
	afx_msg void OnFormatPtr();
	afx_msg void OnFileOpen();
	afx_msg void OnVdoSetUp();
	afx_msg void OnPgAddPic();
	afx_msg void OnPgClearAll();
	afx_msg void OnPgClearText();
	afx_msg void OnPgWordWrap();
	afx_msg void OnPgClearGraphic();
	afx_msg void OnPgSpellCheck();
	afx_msg void OnLoadNewMenu();
	afx_msg void OnFileSave();
	afx_msg void OnRefreshAttBox();
	afx_msg void OnRefreshAttCapture();
	afx_msg void OnRefreshAttFace();
	afx_msg void OnRefreshAttLine();
	afx_msg void OnRefreshAttOutline1();
	afx_msg void OnRefreshAttOutline2();
	afx_msg void OnRefreshAttOval();
	afx_msg void OnRefreshAttShadow();
	afx_msg void OnRefreshAttCast();
	afx_msg void OnRefreshAttText();
	afx_msg void OnRefreshEffect();
	afx_msg void OnRefreshPage();
	afx_msg void OnRefreshAttFill();
	afx_msg void OnCommReceiver();
	afx_msg void OnCommSender();
	afx_msg void OnDownload();
	afx_msg void OnHostFinder();
	afx_msg void OnModem();
	afx_msg void OnFileNew();
	afx_msg void OnFileMruFile1();
	afx_msg void OnUpdateFileMruFile1(CCmdUI* pCmdUI);
	afx_msg void OnFileMruProj1();
	afx_msg void OnUpdateFileMruProj1(CCmdUI* pCmdUI);
	afx_msg void OnFileSaveAs();
	afx_msg void OnFmtUndo();
	afx_msg void OnFmtRedo();
	afx_msg void OnFileTabSetup();
	afx_msg void OnClose();
	afx_msg void OnFilePreference();
	afx_msg void OnFilePrint();
	afx_msg void OnFileImportText();
	afx_msg void OnClipCopy();
	afx_msg void OnClipPaste();
	afx_msg void OnViewToolbar();
	afx_msg void OnUpdateViewToolbar(CCmdUI* pCmdUI);
	afx_msg void OnFileSelectScanner();
	afx_msg void OnFileScanImage();
	afx_msg void OnTimer(UINT nIDEvent);
	afx_msg void OnEditCharMap();
	afx_msg void OnEditFontLocator();
	afx_msg void OnRefreshBaseline();
	afx_msg void OnUncheckAlpha();
	afx_msg void OnFileImportGfx();
	afx_msg void OnFileExportPage();
	afx_msg void OnFileExportProject();
	afx_msg void OnAddObjMag();
	afx_msg void OnAddObjMagMinus();
	afx_msg void OnAddObjMagPlus();
	afx_msg void OnHelpTopics();
	afx_msg void OnProgramSetting();
	afx_msg void OnLnClear();
	afx_msg void OnLnDelete();
	afx_msg void OnLnInsertAfter();
	afx_msg void OnLnInsertBefore();
	afx_msg void OnLnJustCenter();
	afx_msg void OnLnJustFlush();
	afx_msg void OnLnJustLeft();
	afx_msg void OnLnJustRight();
	afx_msg void OnStyleCopy();
	afx_msg void OnStylePaste();
	afx_msg void OnStyleReset();
	afx_msg void OnStyleSaveToBin();
	afx_msg void OnFkeyF1();
	afx_msg void OnFkeyF10();
	afx_msg void OnFkeyF11();
	afx_msg void OnFkeyF12();
	afx_msg void OnFkeyF2();
	afx_msg void OnFkeyF3();
	afx_msg void OnFkeyF4();
	afx_msg void OnFkeyF5();
	afx_msg void OnFkeyF6();
	afx_msg void OnFkeyF7();
	afx_msg void OnFkeyF8();
	afx_msg void OnFkeyF9();
	afx_msg void OnPageCenter();
	afx_msg void OnPageCopy();
	afx_msg void OnPageCut();
	afx_msg void OnPageDuplicate();
	afx_msg void OnPageFlush();
	afx_msg void OnPageInNewAfter();
	afx_msg void OnPageInNewBefore();
	afx_msg void OnPageLeft();
	afx_msg void OnPagePasteAfter();
	afx_msg void OnPagePasteBefore();
	afx_msg void OnPageRight();
	afx_msg void OnEdRedo();
	afx_msg void OnEdUndo();
	afx_msg void OnPasteInPosition();
	afx_msg void OnAddObjPolygon();
	afx_msg void OnAddObjCurve();
	afx_msg void OnRefreshAttCurve();
	afx_msg void OnRefreshAttPoly();
	afx_msg void OnRefreshAttPic();
	afx_msg void OnSetPageScrollPos();
	afx_msg void OnSetBinTopScrollPos();
	afx_msg void OnSetBinBotScrollPos();
	//}}AFX_MSG
	afx_msg LRESULT OnResizeLeftBar(WPARAM wParam, LPARAM lParam);
	afx_msg LRESULT OnResizeTopBin(WPARAM wParam, LPARAM lParam);
	afx_msg LRESULT OnTWXferDone(WPARAM wParam, LPARAM lParam);
	DECLARE_MESSAGE_MAP()
private:
	UINT m_LdPicTimer;
	INT m_winW;
	INT m_winH;

	VOID VdoSetupVideoMachine();
	DWORD m_vdoSetupType;
	VOID VdoSetupTitleMachine();
	DWORD m_nSubm;
	DWORD m_nMenu;
	VOID LoadMenuText();
	VOID LoadPictureDlg();
	
	CAttribLine*	m_pDlgLine;
	CAttribCurve*	m_pDlgCurv;
	CAttribPolygon* m_pDlgPoly;
	CAttribText*	m_pDlgText;
	CAttribBox*		m_pDlgBox;
	CAttribFill*	m_pDlgFill;
	CAttribOval*	m_pDlgOval;
	CAttribImport*	m_pDlgImport;

	DWORD			m_numTip;
	IN_TEXT_DATA*	m_ttData;
	BOOL			m_bPanelBar;
	BOOL			m_bToolBar;
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MAINFRM_H__F12BAE28_C546_11D3_BFDB_005004648BC2__INCLUDED_)
