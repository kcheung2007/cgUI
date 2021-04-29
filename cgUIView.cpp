/* COPYRIGHT NOTICE:
********************************************************
*  Copyright (c) 2000 InnoVision Technology, Inc.      *
*  All rights reserved.                                *
*  PROPRIETARY AND CONFIDENTIAL                        *
*  DO NOT DISTRIBUTE                                   *
********************************************************
*/
// cgUIView.cpp : implementation of the CCgUIView class
//

#include "stdafx.h"
#include "cgUI.h"

#include "cgUIDoc.h"
#include "cgUIView.h"
#include "FileReq.h"
#include "WinUser.h"
#include "Global.h"
#include "ChildFrm.h"
#include "switch.h"

#define		DB_CLICK_TIEMR		0x101

#define		IME_IN_CANDIDATE	0x01
#define		IME_IN_COMPOSITION	0x02
#define		IME_SIGNAL_GET_STR	0x40
#define		IME_GET_RESULT_STR	0x80

#define		K_ESC				0x01
#define		K_ENTER				0x1C
#define		K_SPACE				0x39
#define		K_HOME				0x147 // Debugger values
#define		K_UP				0x148
#define		K_PGUP				0x149
#define		K_LEFT				0x14B
#define		K_RIGHT				0x14D
#define		K_END				0x14F
#define		K_DOWN				0x150
#define		K_PGDOWN			0x151

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

extern	CURSOR_HANDLE	g_hCursor;
extern  _TCHAR			UILang_UIFont[256];
extern  int				UILang_UIFontSize;
extern	CChildFrame*	g_ChildFrame;
/////////////////////////////////////////////////////////////////////////////
// CCgUIView

IMPLEMENT_DYNCREATE(CCgUIView, CView)

BEGIN_MESSAGE_MAP(CCgUIView, CView)
	//{{AFX_MSG_MAP(CCgUIView)
	ON_WM_CHAR()
	ON_WM_KEYDOWN()
	ON_WM_CONTEXTMENU()
	ON_COMMAND(ID_OPT_ONE, OnOptOne)
	ON_COMMAND(ID_OPT_TWO, OnOptTwo)
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
	ON_WM_MOUSEMOVE()
	ON_COMMAND(ID_FILE_SAVE, OnFileSave)
	ON_COMMAND(ID_FILE_SAVE_AS, OnFileSaveAs)
	ON_WM_ERASEBKGND()
	ON_WM_KILLFOCUS()
	ON_WM_LBUTTONDBLCLK()
	ON_WM_TIMER()
	ON_WM_SETCURSOR()
	//}}AFX_MSG_MAP

END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CCgUIView construction/destruction

CCgUIView::CCgUIView()
{
	// TODO: add construction code here
	m_IMEState  = 0;	
	m_spaceFlag = 0; // normal state
	m_bHitEnter = 0;
	m_bDbClick  = 0;
}//end of constructor

CCgUIView::~CCgUIView()
{
	delete [] m_pPopMenu;
}//end of destructor

/////////////////////////////////////////////////////////////////////////////
// CCgUIView drawing

void CCgUIView::OnDraw(CDC* pDC)
{
	CCgUIDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);

	// TODO: add draw code for native data here
	TRACE0( "cgUIView.cpp : CCgUIView::OnDraw\n" );
	CGS_EditWindowPaint();
}//end of CCgUIView::OnDraw

/////////////////////////////////////////////////////////////////////////////
// CCgUIView diagnostics

#ifdef _DEBUG
void CCgUIView::AssertValid() const
{
	CView::AssertValid();
}

void CCgUIView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CCgUIDoc* CCgUIView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CCgUIDoc)));
	return (CCgUIDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CCgUIView message handlers
///////////////////////////////////////////////////////////////////////////////////////////
// Put all requires information here. For first time and one-time initialization 
// that requires information about the document after the view is first attached to the document, 
// but before the view is initially displayed.
// CGS_EarlyInit() and CGS_LateInit() are tight together.
void CCgUIView::OnInitialUpdate() 
{
	CView::OnInitialUpdate();
	
	TRACE0("cgUIView.cpp : CCgUIView::OnInitialUpdate\n");

	HWND hWnd = g_ChildFrame->GetMDIFrame()->m_hWndMDIClient; // Back ground hWnd

	CGS_EarlyInit(	(DWORD)1,
					(DWORD)AfxGetApp()->m_hInstance, // hInstance of App
					(DWORD)AfxGetMainWnd()->m_hWnd,	 // hWnd of main Wnd
					(CHAR*)NULL );

	// pass handle of frame and handle of back ground window
	CGS_LateInit( (DWORD)g_ChildFrame->m_hWnd, (DWORD)hWnd ); 

	CGS_UIRegisterShowObjectProperitesMenu( IXReg_ShowObjPropertiesMenu );
	CGS_RegisterNotifyUIAttributeChange( IXReg_UpdateIXGUI );//JRS 00-03-28 re-enabled this call
	CGS_RegisterUIScrollBarEnableProc( IXReg_ScrollBarEnableProc );
	CGS_RegisterCGSetsEditWindowHorizScrollPosProc( IXReg_UpdateVertScrollBar );
	CGS_RegisterCGSetsEditWindowVertScrollPosProc( IXReg_UpdateHorzScrollBar );
	CGS_RegisterMousePointerModeProc( IXReg_SetMousePointerMode );

	LoadPopMenuText();
}//end of CCgUIView::OnInitialUpdate

/////////////////////////////////////////////////////////////////////////////
// Get the final character code - exclude all function keys and keypad keys.
void CCgUIView::OnChar(UINT nChar, UINT nRepCnt, UINT nFlags)  //JRS 00-03-28 whole func
{
	TRACE3( "cgUIView.cpp : OnChar() - nChar %x, nRepCnt %x, nFlag %x\n", nChar, nRepCnt, nFlags );

	int KeyStateFlags=0;
	
	if(GetKeyState(VK_SHIFT)& 0x80)
		KeyStateFlags|=CGS_SHIFT_KEY_DOWN;
	if(GetKeyState(VK_CONTROL)& 0x80)
		KeyStateFlags|=CGS_CONTROL_KEY_DOWN;

	CGS_NotifyKBChar( (DWORD)m_hWnd, nChar, KeyStateFlags );
	CView::OnChar(nChar, nRepCnt, nFlags);
}//end of CCgUIView::OnChar

/////////////////////////////////////////////////////////////////////////////
// Get all key down code - include all function keys, keypad keys & arrow keys 
// Must get all pre-defined combination keys.
// FOR IME processing :
// System only send key down message to WM_KEYDOWN, no WM_CHAR message is sent.
// Therefore we need to put the CGS_NotifyKBChar() here for non-English System
// to capture spacebar and display space charact.
void CCgUIView::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags) //JRS 00-03-28  whole func
{
	TRACE0( "cgUIView.cpp : OnKeyDown() ----------------------\n" );
	TRACE3( "		nChar %x, nRepCnt %x, nFlag %x\n", nChar, nRepCnt, nFlags );

	if( m_IMEState )			// only handle key in when entering the IME state
		HandleKeyIn( nFlags );	// keep the english version work.

	if( GetKeyState(VK_SHIFT) & 0x80 && (GetKeyState(nChar) & 0x80) )
		CGS_NotifyKeyDownSpecial( (DWORD)m_hWnd, nChar, CGS_SHIFT_KEY_DOWN );
	else
		if( GetKeyState(VK_CONTROL) & 0x80 && (GetKeyState(nChar) & 0x80))
			CGS_NotifyKeyDownSpecial( (DWORD)m_hWnd, nChar, CGS_CONTROL_KEY_DOWN );
	else
	{	
		CGS_NotifyKeyDownSpecial( (DWORD)m_hWnd, nChar, 0 );

		// special section for IME processing
		int KeyStateFlags=0;	
		if(GetKeyState(VK_SHIFT)& 0x80)
			KeyStateFlags|=CGS_SHIFT_KEY_DOWN;
		if(GetKeyState(VK_CONTROL)& 0x80)
			KeyStateFlags|=CGS_CONTROL_KEY_DOWN;

		// VK_PROCESSKEY - IME process key - 0x39 - US scan code
		if( (nChar == VK_PROCESSKEY) && !m_IMEState && (nFlags == 0x39) ) 
			CGS_NotifyKBChar( (DWORD)m_hWnd, VK_SPACE, KeyStateFlags );
		// end of special section for IME processing
	}//end of else

	CView::OnKeyDown(nChar, nRepCnt, nFlags);
}//end of CCgUIView::OnKeyDown
///////////////////////////////////////////////////////////////////////////////////////////
// Pop up the context menu
// Predefined Menu types are IDR_POP_COLOR_BIN, IDR_POP_LAYER_LIST, IDR_POP_PAGE_OPT,
// IDR_POP_PAGE_LIST, IDR_POP_PG_N_OBJ, IDR_POP_STYLE_BIN.
void CCgUIView::OnContextMenu(CWnd* pWnd, CPoint point) 
{
	TRACE2("cgUIView.cpp : CCgUIView::OnContextMenu - x = %d, y = %d\n", point.x, point.y );

	CRect	rc;
	GetClientRect( &rc );
	ClientToScreen( &rc );

	if( rc.PtInRect(point) )
	{
		// call core function to get the popup menu type
		PopUpMenu( IDR_POP_COLOR_BIN, point); // assume the popup menu is Layer list
		
	}//end of if	

}//end of CCgUIView::OnContextMenu
///////////////////////////////////////////////////////////////////////////////////////////
// Testing purpose only
void CCgUIView::OnOptOne() 
{
m_dbClickTimer = SetTimer( DB_CLICK_TIEMR, 2000, 0 );
}
///////////////////////////////////////////////////////////////////////////////////////////
// Testing purpose only
void CCgUIView::OnOptTwo() 
{
//	IXReg_DisplayTemplateMessageBox();
}
///////////////////////////////////////////////////////////////////////////////////////////
void CCgUIView::OnLButtonDblClk(UINT nFlags, CPoint point) 
{
/*REMOVED by JRS 00-11-18
	m_bDbClick = 1;
	m_dbClickTimer = SetTimer( DB_CLICK_TIEMR, 250, 0 );
*/
	CView::OnLButtonDblClk(nFlags, point);
}//end of CCgUIView::OnLButtonDblClk
///////////////////////////////////////////////////////////////////////////////////////////
void CCgUIView::OnLButtonDown(UINT nFlags, CPoint pt) 
{
	TRACE3("cgUIView.cpp : CCgUIView::OnLButtonDown - x = %d, y = %d  NFlags = %d\n", pt.x, pt.y,nFlags );	

	DWORD	kbFlag = nFlags & (MK_CONTROL | MK_SHIFT);
//-----------------------------------------------------------------------------------------
//JRS 00-11-17  The windows kb flags must be translated into platform-independent CGS flags!!!
	DWORD CGS_KB_Flags=0;
	if(nFlags & MK_CONTROL)
		CGS_KB_Flags |= CGS_CONTROL_KEY_DOWN;
	if(nFlags & MK_SHIFT)
		CGS_KB_Flags |= CGS_SHIFT_KEY_DOWN;
//-----------------------------------------------------------------------------------------
	CGS_NotifyEditMouseDown( pt.x, pt.y, CGS_KB_Flags);

	SetCapture();

	if( m_bDbClick )// simulate triple click event
	{		
//		m_bDbClick = IXDoTripleClick();//DISABLED BY JRS 00-11-18
	}
	// End of Adding your message handler code here and/or call default
	CView::OnLButtonDown(nFlags, pt);
}//end of CCgUIView::OnLButtonDown
///////////////////////////////////////////////////////////////////////////////////////////
void CCgUIView::OnLButtonUp(UINT nFlags, CPoint pt) 
{
	TRACE3("cgUIView.cpp : CCgUIView::OnLButtonUp - x = %d, y = %d, nFlags = %d\n", pt.x, pt.y, nFlags );	

	DWORD	kbFlag = nFlags & (MK_CONTROL | MK_SHIFT);	
//-----------------------------------------------------------------------------------------
//JRS 00-11-17  The windows kb flags MUST be translated into platform-independent CGS flags!!!
	DWORD CGS_KB_Flags=0;
	if(nFlags & MK_CONTROL)
		CGS_KB_Flags |= CGS_CONTROL_KEY_DOWN;
	if(nFlags & MK_SHIFT)
		CGS_KB_Flags |= CGS_SHIFT_KEY_DOWN;
//-----------------------------------------------------------------------------------------

	CGS_NotifyEditMouseUp( pt.x, pt.y, CGS_KB_Flags);
	ReleaseCapture();
	// End of Adding your message handler code here and/or call default
	CView::OnLButtonUp(nFlags, pt);
}//end of CCgUIView::OnLButtonUp
///////////////////////////////////////////////////////////////////////////////////////////
void CCgUIView::OnMouseMove(UINT nFlags, CPoint pt) 
{
//	TRACE2("cgUIView.cpp : CCgUIView::OnMouseMove - x = %d, y = %d\n", pt.x, pt.y );	
	//CGS_NotifyEditMouseMove( pt.x, pt.y, 0 );

	DWORD	kbFlag = nFlags & (MK_CONTROL | MK_SHIFT);

//-----------------------------------------------------------------------------------------
//JRS 00-11-17  The windows kb flags MUST be translated into platform-independent CGS flags!!!
	DWORD CGS_KB_Flags=0;
	if(nFlags & MK_CONTROL)
		CGS_KB_Flags |= CGS_CONTROL_KEY_DOWN;
	if(nFlags & MK_SHIFT)
		CGS_KB_Flags |= CGS_SHIFT_KEY_DOWN;
//-----------------------------------------------------------------------------------------
	if( nFlags & MK_LBUTTON )
	{
		TRACE3("cgUIView.cpp : CCgUIView::OnMouseMove & Left Button down - x = %d, y = %d, nFlags = %d\n", pt.x, pt.y, nFlags );	
		CGS_NotifyEditMouseDrag( pt.x, pt.y, CGS_KB_Flags);
	}

	// End of Adding your message handler code here and/or call default
	CView::OnMouseMove(nFlags, pt);
}//end of CCgUIView::OnMouseMove
//////////////////////////////////////////////////////////////////////////////////////////////
// File open is handle in Mainframe.cpp
void CCgUIView::OnFileSave() 
{
 	TRACE0("\t CCgUIView.cpp : OnFileSave\n" );

//	AfxGetMainWnd()->SendMessage( WM_COMMAND, ID_FILE_SAVE, 0 );

	if( CGS_GetValDbl(EDIT_PROJECT_NEEDS_FILENAME) )
		OnFileSaveAs();
	else
		CGS_SaveProject();

}//end of CCgUIView::OnFileSave
//////////////////////////////////////////////////////////////////////////////////////////////
// This handle all requirement for Save As function. 
// Full path + File name is passed into CGS function for folder structure as Jim described.
// Full path + File name + File ext is required to add to the project list.
// File open is handle in Mainframe.cpp
void CCgUIView::OnFileSaveAs() 
{
 	TRACE0("\t CCgUIView.cpp : OnFileSaveAs\n" );	

	FILE_REQ_FOLDER_INFO	projFRD;
	ZeroMemory( &projFRD, sizeof(projFRD) );
	projFRD.opt = SAVE_OP;
	
	//----------------------------------------------------------------------------
	//added jrs 01-05-11 need to fill this local struct with current folder info - 
	projFRD.nFileType = FILE_CATEGORY_PROJECT;//specify the type of folder info needed
	CGS_GetFileCategoryPathInfo( &projFRD );//load the current info into fields of local struct
	//----------------------------------------------------------------------------

	_tcscpy( projFRD.DlgTitle, _T("Save Project As") );

	if( !FileRequestDlg( &projFRD, FILE_CATEGORY_PROJECT ) )
		return;

	CString	fn( projFRD.FolderPath );
	fn = fn + "\\" + projFRD.FileName;

	char	szFileName[MAX_PATH];

#ifdef _UNICODE
	WideCharToMultiByte(CP_ACP,                 // code page
						0,		                // dwFlags
						fn,						// lpWideCharStr
						-1,                     // cchWideCharStr
						szFileName,				// lpMultiByteStr
						sizeof(szFileName),		// cchMultiByte
						NULL,                   // lpDefaultChar
						NULL					// lpUsedDefaultChar
					);        
#else
	strcpy( szFileName, (char*)(LPCTSTR)fn );
#endif

	CGS_SaveProjectAs( projFRD.CompleteFileName );
	AfxGetApp()->AddToRecentFileList( projFRD.CompleteFileName );
//	TRACE0("\t CCgUIView.cpp : AddToRecentFileList\n" );	

}//end of CCgUIView::OnFileSaveAs
//////////////////////////////////////////////////////////////////////////////////////////////
VOID CCgUIView::CGUI_SendImeCompStrToCore(HIMC hImc)
{
	int		UnicodeStrLen;
	int		AttributeCount;
	WCHAR*	pImeUnicodeStr = NULL;
	BYTE*	pAttributeArray = NULL;    

	//GET COMPOSITION STRING -------------------------------------------------------------
	//get the CHARACTER count for string (unicode)
	UnicodeStrLen = ImmGetCompositionStringW( hImc, GCS_COMPSTR, NULL, 0 ); 
	KentDebugLog( "Unicode Str Length", UnicodeStrLen );
#ifdef _DEBUG
	if( UnicodeStrLen < 0 )
	{
		MessageBox( _T("Unicode String Length < 0 "), _T("Error"), MB_OK );
		return;
	}
#endif

	// Allocate string length + 1 items (must allocate 1 extra for null terminator!)
	pImeUnicodeStr = (WCHAR*)malloc( (UnicodeStrLen + 1) * sizeof( WCHAR ) ); 
	//get the string (unicode) - UnicodeStrLen + 1 => include NULL terminator
	ImmGetCompositionStringW( hImc, GCS_COMPSTR, pImeUnicodeStr, UnicodeStrLen + 1 ); 	

	//ensure null termination
	pImeUnicodeStr[ UnicodeStrLen ] = 0;
	char szTemp[MAX_PATH];
	ZeroMemory( szTemp, MAX_PATH );
	WideCharToMultiByte(CP_ACP,             // code page
						0,		            // dwFlags
						pImeUnicodeStr,		// lpWideCharStr
						-1,                 // cchWideCharStr
						szTemp,				// lpMultiByteStr
						sizeof(szTemp),		// cchMultiByte
						NULL,               // lpDefaultChar
						NULL		 		// lpUsedDefaultChar
					);        

	KentDebugLog( szTemp, UnicodeStrLen );
	

	//GET MATCHING ATTRIBUTE ARRAY FOR STRING --------------------------------------------
	AttributeCount = ImmGetCompositionStringW( hImc, GCS_COMPATTR, NULL, 0); //unicode !
#ifdef _DEBUG
	if( UnicodeStrLen < 0 )
	{
		MessageBox( _T("Attribute Count < 0 "), _T("Error"), MB_OK );
		return;
	}
#endif

	//allocate one item per wide character in string (plus 1 to handle empty string case)
	pAttributeArray = (BYTE*) malloc( (AttributeCount + 1 ) * sizeof( BYTE ) ); 
	ImmGetCompositionStringW( hImc, GCS_COMPATTR, pAttributeArray, AttributeCount ); //unicode !

	//GET IME LOGICAL CURSOR POSITION -----------------------------------------------------
	m_ImeCurPos = ImmGetCompositionStringW( hImc, GCS_CURSORPOS, NULL, 0 ); //unicode !
#ifdef _DEBUG
	if( m_ImeCurPos < 0 )
	{
		MessageBox( _T("IME Cursor position < 0 "), _T("Error"), MB_OK );
		return;
	}
#endif

	//Send data to Alpha CG editor --------------------------------------------------------
	TRACE1("\t ++ CGS_ImeUpdateString ++ m_ImeCurPos = %d\n", m_ImeCurPos );
	CGS_ImeUpdateString( (DWORD)pImeUnicodeStr, UnicodeStrLen, (DWORD)pAttributeArray, m_ImeCurPos );

	//FREE RESOURCES ----------------------------------------------------------------------
	if( pImeUnicodeStr )
		free( pImeUnicodeStr );

	if( pAttributeArray )
		free( pAttributeArray );
	
}//end of CCgUIView::CGUI_SendImeCompStrToCore(HIMC hImc)
//////////////////////////////////////////////////////////////////////////////////////////////
VOID CCgUIView::CGUI_SendImeFinalResultStrToCore(HIMC hIMC)
{
	int		UnicodeStrLen;
	int		ImeCursorPos;
	WCHAR*	pImeUnicodeStr = NULL;
	
	//get the CHARACTER count for final RESTULT string (unicode)
	UnicodeStrLen = ImmGetCompositionStringW( hIMC, GCS_RESULTSTR, NULL, 0 ); 
#ifdef _DEBUG
	if( UnicodeStrLen < 0 )
	{
		MessageBox( _T("Unicode String Length < 0 "), _T("Error"), MB_OK );
		return;
	}
#endif

	// Allocate string length + 1 items (must allocate 1 extra for null terminator!)
	pImeUnicodeStr = (WCHAR*) malloc( (UnicodeStrLen + 1) * sizeof( WCHAR ) ); 

	//get the result string (unicode)
	ImmGetCompositionStringW( hIMC, GCS_RESULTSTR, pImeUnicodeStr, UnicodeStrLen + 1 ); 

	//ensure null termination
	pImeUnicodeStr[ UnicodeStrLen ] = 0;

	//GET IME LOGICAL CURSOR POSITION -----------------------------------------------------
	ImeCursorPos = ImmGetCompositionStringW( hIMC, GCS_CURSORPOS, NULL, 0 ); //unicode !
#ifdef _DEBUG
	if( ImeCursorPos < 0 )
	{
		MessageBox( _T("IME Cursor position < 0 "), _T("Error"), MB_OK );
		return;
	}
#endif

	//Send data to Alpha CG editor --------------------------------------------------------
	TRACE1(" \t ++ CGS_ImeUpdateString ++ m_ImeCurPos = %d\n", m_ImeCurPos );
	CGS_ImeUpdateString( (DWORD)pImeUnicodeStr, UnicodeStrLen, NULL, ImeCursorPos );

	//FREE RESOURCES ----------------------------------------------------------------------
	if(pImeUnicodeStr)
		free(pImeUnicodeStr);

}//end of CCgUIView::CGUI_SendImeFinalResultStrToCore(HIMC hImc)
//////////////////////////////////////////////////////////////////////////////////////////////
// Set the candidate window position, then open the candidate window
VOID CCgUIView::ImeUIOpenCandidate(HWND hWnd, LPARAM lParam)
{		
	HIMC			hImc;
	CANDIDATEFORM	candForm;
	POINT			pt;
	DWORD			W = 60;
	DWORD			H = 100;
	
	CGS_ImeGetCandidateEditWindowAnchorXY( (DWORD)&pt.x, (DWORD)&pt.y, H, W );
	candForm.dwIndex = 0;
	candForm.dwStyle = CFS_CANDIDATEPOS;
	candForm.ptCurrentPos = pt;

	hImc = ImmGetContext(m_hWnd);
	ImmSetCandidateWindow( hImc, &candForm );
	ImmReleaseContext( m_hWnd, hImc );

	m_IMEState |= IME_IN_CANDIDATE; // set the IME state
	TRACE1("ImeUIOpenCandidate - m_IMEState |= IME_IN_CANDIDATE, m_IMEState = %d\n", m_IMEState );

}//end of CCgUIView::ImeUIOpenCandidate(HWND hWnd, LPARAM lParam)
//////////////////////////////////////////////////////////////////////////////////////////////
VOID CCgUIView::ImeUICloseCandidate(HWND hWnd, LPARAM lParam)
{
	m_IMEState &= ~IME_IN_CANDIDATE;

}//end of CCgUIView::ImeUICloseCandidate(HWND hWnd, LPARAM lParam)
//////////////////////////////////////////////////////////////////////////////////////////////
// Parsing all keyboard input (scan code). 
// If the scan code is 0 - 9, and in candidate mode, signal will get the final string.
// After that check is IME in signal get string state and scan code in not 0 - 9?
// YES - Signal the IME manager to get the string.
// NO  - Still in input mode, wait for non(0 - 9) key in.
VOID CCgUIView::HandleKeyIn(DWORD nFlags)
{
	switch( nFlags )
	{
	case K_ENTER:
		m_bHitEnter = 1;
		if( m_IMEState & IME_SIGNAL_GET_STR )
			m_IMEState &= ~IME_SIGNAL_GET_STR; // reset state
		break;
	case K_ESC:
	case K_LEFT:
	case K_RIGHT:
	case K_HOME:
	case K_END:
	case K_UP:
	case K_DOWN:
	case K_PGUP:
	case K_PGDOWN:	
		m_IMEState |= IME_SIGNAL_GET_STR;
		break;
	case K_SPACE:
		TRACE0("\t\t Space bar hit - IME_SIGNAL_GET_STR\n" );
		if( m_spaceFlag )
			m_IMEState |= IME_SIGNAL_GET_STR;
		break;
	default:
		m_bHitEnter = 0;
		if( ((0x01 < nFlags) && (nFlags < 0x0C)) && (m_IMEState & IME_IN_CANDIDATE) )
			m_IMEState |= IME_SIGNAL_GET_STR;

		if( (m_IMEState & IME_SIGNAL_GET_STR) && !((0x01 < nFlags) && (nFlags < 0x0C)) )
			m_IMEState |= IME_GET_RESULT_STR;

	}//end of switch
}//end of CCgUIView::HandleKeyIn(DWORD wParam)
/////////////////////////////////////////////////////////////////////////////////////////
VOID CCgUIView::ImeUIStartComposition(WPARAM wParam, LPARAM lParam)
{		
	if( m_IMEState & IME_IN_COMPOSITION )
	{
		TRACE0("++ CGS_ImeEndComposition ++\n" );
		CGS_ImeEndComposition();
		m_spaceFlag = 0;
	}

	m_IMEState |= IME_IN_COMPOSITION;  // set IME state

	HIMC hImc = ImmGetContext(m_hWnd);
	CGS_ImeStartComposition(); // signal start state
	m_spaceFlag = 1;
	CGUI_SendImeCompStrToCore( hImc );
	ImmReleaseContext( m_hWnd, hImc );

}//end of CCgUIView::ImeUIStartComposition
/////////////////////////////////////////////////////////////////////////////////////////
VOID CCgUIView::ImeUIComposition(WPARAM wParam, LPARAM lParam)
{
	HIMC hImc = ImmGetContext(m_hWnd);
	CGUI_SendImeCompStrToCore( hImc );
	ImmReleaseContext( m_hWnd, hImc );

}//end of CCgUIView::ImeUIComposition
/////////////////////////////////////////////////////////////////////////////////////////
VOID CCgUIView::ImeUIEndComposition(WPARAM wParam, LPARAM lParam)
{
	m_IMEState &= ~IME_IN_COMPOSITION; // unset the IME State

	HIMC hImc = ImmGetContext(m_hWnd);
	CGUI_SendImeFinalResultStrToCore( hImc );
	ImmReleaseContext( m_hWnd, hImc );
	TRACE1("++ CGS_ImeEndComposition ++ m_ImeCurPos = %d\n", m_ImeCurPos );
	CGS_ImeEndComposition(); // signal end state
	m_spaceFlag = 0;

//	TRACE1("CCgUIView::ImeUIEndComposition - m_ImeCurPos = %d", m_ImeCurPos );
}//end of CCgUIView::ImeUIEndComposition
//////////////////////////////////////////////////////////////////////////////////////////////
// Handle all candidate notification. 
VOID CCgUIView::ImeCandidateNotify(UINT msg, WPARAM wParam, LPARAM lParam)
{			
	switch( wParam )
	{
	case IMN_OPENCANDIDATE:		
		TRACE2( "\t++ CCgUIView::OnChildNotify - IMN_OPENCANDIDATE, wParam = %d, lParam = %d\n", wParam, lParam );
		ImeUIOpenCandidate( m_hWnd, lParam );
		break;
	case IMN_CLOSECANDIDATE:
		TRACE2( "\t++ CCgUIView::OnChildNotify - IMN_CLOSECANDIDATE, wParam = %d, lParam = %d\n", wParam, lParam );
		ImeUICloseCandidate( m_hWnd, lParam );
		break;
	case IMN_CHANGECANDIDATE:
		TRACE2( "\t++ CCgUIView::OnChildNotify - IMN_CHANGECANDIDATE, wParam = %d, lParam = %d\n", wParam, lParam );
		break;
	case IMN_SETOPENSTATUS:
		TRACE2( "\t++ CCgUIView::OnChildNotify - IMN_SETOPENSTATUS, wParam = %d, lParam = %d\n", wParam, lParam );				
		break;
	case IMN_CLOSESTATUSWINDOW:
		TRACE2( "\t++ CCgUIView::OnChildNotify - IMN_CLOSESTATUSWINDOW, wParam = %d, lParam = %d\n", wParam, lParam );
		break;
	case IMN_GUIDELINE:
		TRACE2( "\t++ CCgUIView::OnChildNotify - IMN_GUIDELINE, wParam = %d, lParam = %d\n", wParam, lParam );
		break;
	case IMN_OPENSTATUSWINDOW:
		TRACE2( "\t++ CCgUIView::OnChildNotify - IMN_OPENSTATUSWINDOW, wParam = %d, lParam = %d\n", wParam, lParam );
		break;
	case IMN_SETCANDIDATEPOS:
		TRACE2( "\t++ CCgUIView::OnChildNotify - IMN_SETCANDIDATEPOS, wParam = %d, lParam = %d\n", wParam, lParam );
		break;
	case IMN_SETCOMPOSITIONFONT:
		TRACE2( "\t++ CCgUIView::OnChildNotify - IMN_SETCOMPOSITIONFONT, wParam = %d, lParam = %d\n", wParam, lParam );
		break;
	case IMN_SETCOMPOSITIONWINDOW:
		TRACE2( "\t++ CCgUIView::OnChildNotify - IMN_SETCOMPOSITIONWINDOW, wParam = %d, lParam = %d\n", wParam, lParam );
		break;
	case IMN_SETCONVERSIONMODE:
		TRACE2( "\t++ CCgUIView::OnChildNotify - IMN_SETCONVERSIONMODE, wParam = %d, lParam = %d\n", wParam, lParam );
		break;
	case IMN_SETSENTENCEMODE:
		TRACE2( "\t++ CCgUIView::OnChildNotify - IMN_SETSENTENCEMODE, wParam = %d, lParam = %d\n", wParam, lParam );
		break;
	case IMN_SETSTATUSWINDOWPOS:
		TRACE2( "\t++ CCgUIView::OnChildNotify - IMN_SETSTATUSWINDOWPOS, wParam = %d, lParam = %d\n", wParam, lParam );
		break;
	}//end of switch - wParam
}//end of CCgUIView::ImeCandidateNotify
//////////////////////////////////////////////////////////////////////////////////////////////
// New logic handling which no longer fix in MS IME message handling was create on 09-08-2000. 
// The reason for this creation is made Jim happy :) 
LRESULT CCgUIView::DefWindowProc(UINT message, WPARAM wParam, LPARAM lParam) 
{
	HIMC	hImc;
	switch( message )
	{
	case WM_KEYDOWN:
		TRACE2( "++ CCgUIView::OnChildNotify - WM_KEYDOWN, wParam = %d, lParam = %d\n", wParam, lParam );
		TRACE1( "\t++ m_IMEState = %d\n", m_IMEState );
		if( m_IMEState & IME_GET_RESULT_STR )
		{
			hImc = ImmGetContext(m_hWnd);
			CGUI_SendImeFinalResultStrToCore( hImc );
				
			ImmReleaseContext( m_hWnd, hImc );
			TRACE0("++ Force end of composition - CGS_ImeEndComposition ++\n" );
			CGS_ImeEndComposition(); // signal end state
			m_spaceFlag = 0;

			m_IMEState &= ~IME_GET_RESULT_STR; // unset IME state
			m_IMEState &= ~IME_IN_COMPOSITION;

			m_IMEState |= IME_IN_COMPOSITION;  // set IME state
			HIMC hImc = ImmGetContext(m_hWnd);
			TRACE0("++ Force start of composition - CGS_ImeStartComposition ++\n" );
			CGS_ImeStartComposition(); // signal start state
			m_spaceFlag = 1;
			CGUI_SendImeCompStrToCore( hImc );
			ImmReleaseContext( m_hWnd, hImc );

			TRACE1("WM_KEYDOWN - m_ImeCurPos = %d\n", m_ImeCurPos );
		}//end of if - IME_GET_RESULT_STR
		break;
	case WM_CHAR:
		TRACE2( "\t++ CCgUIView::OnChildNotify - WM_CHAR, wParam = %d, lParam = %d\n", wParam, lParam );
		break;
	case WM_IME_KEYDOWN:
		TRACE2( "\t++ CCgUIView::OnChildNotify - WM_IME_KEYDOWN, wParam = %d, lParam = %d\n", wParam, lParam );
		break;
	case WM_IME_CHAR:
		TRACE2( "\t++ CCgUIView::OnChildNotify - WM_IME_CHAR, wParam = %d, lParam = %d\n", wParam, lParam );
		return( 1 );
	case WM_IME_SELECT:
		TRACE2( "\t++ CCgUIView::OnChildNotify - WM_IME_SELECT, wParam = %d, lParam = %d\n", wParam, lParam );
		break;
	case WM_INPUTLANGCHANGE:
		TRACE2( "\t++ CCgUIView::OnChildNotify - WM_INPUTLANGCHANGE, wParam = %d, lParam = %d\n", wParam, lParam );
		CGS_NotifyInputLanguageChange( wParam, lParam );
		break;
	case WM_IME_NOTIFY:
		TRACE2( "\t++ CCgUIView::OnChildNotify - WM_IME_NOTIFY, wParam = %d, lParam = %d\n", wParam, lParam );
		ImeCandidateNotify(message, wParam, lParam);
		break;
	case WM_IME_SETCONTEXT:
		TRACE2( "\t++ CCgUIView::OnChildNotify - WM_IME_SETCONTEXT, wParam = %d, lParam = %d\n", wParam, lParam );
		lParam = 0;
		break;
	case WM_IME_CONTROL:
		TRACE2( "\t++ CCgUIView::OnChildNotify - WM_IME_CONTROL, wParam = %d, lParam = %d\n", wParam, lParam );
		break;
	case WM_IME_STARTCOMPOSITION:
		TRACE2( "\t++ CCgUIView::OnChildNotify - WM_IME_STARTCOMPOSITION, wParam = %d, lParam = %d\n", wParam, lParam );		
		lParam = 0;
		ImeUIStartComposition( wParam, 0 );
		break;
	case WM_IME_COMPOSITION:
		TRACE2( "\t++ CCgUIView::OnChildNotify - WM_IME_COMPOSITION, wParam = %d, lParam = %d\n", wParam, lParam );
		lParam = 0;
		ImeUIComposition( wParam, 0 );
		break;
	case WM_IME_ENDCOMPOSITION:
		TRACE2( "\t++ CCgUIView::OnChildNotify - WM_IME_ENDCOMPOSITION, wParam = %d, lParam = %d\n", wParam, lParam );			
		lParam = 0;
		ImeUIEndComposition(wParam, lParam);
		break;
	}//end of switch - message
	
	return CView::DefWindowProc(message, wParam, lParam);
}//end of CCgUIView::DefWindowProc

//////////////////////////////////////////////////////////////////////////////////////////
// Erase the clip box background only
BOOL CCgUIView::OnEraseBkgnd(CDC* pDC) 
{
	CRect rc;
	pDC->GetClipBox( rc ); // get region to update
	::InvalidateRect( m_hWnd, rc, 0 );
	CGS_EditWindowPaint();

	return( 0 );
//	return CView::OnEraseBkgnd(pDC);
}//end of CCgUIView::OnEraseBkgnd
//////////////////////////////////////////////////////////////////////////////////////////
void CCgUIView::OnKillFocus(CWnd* pNewWnd) 
{
	CView::OnKillFocus(pNewWnd);

//	TRACE0( "++++>> CCgUIView::OnKillFocus <<++++++\n" );
/* save for future reference
	HIMC hImc = ImmGetContext(m_hWnd);
	ImmNotifyIME( hImc, NI_COMPOSITIONSTR, CPS_COMPLETE, 0 );
	ImmSetOpenStatus( hImc, 0 );
	ImmReleaseContext( m_hWnd, hImc );
* save for future reference ***/
//	SendMessage( WM_IME_NOTIFY, IMN_CLOSESTATUSWINDOW, 0 );
}//end of CCgUIView::OnKillFocus
//////////////////////////////////////////////////////////////////////////////////////////////
void CCgUIView::OnTimer(UINT nIDEvent) 
{	
	TRACE0( "cgUIView.cpp - CCgUIView::OnTimer\n" );
	KillTimer( m_dbClickTimer );	
	m_bDbClick = 0;
	CView::OnTimer(nIDEvent);
}//end of CCgUIView::OnTimer
//////////////////////////////////////////////////////////////////////////////////////////////
BOOL CCgUIView::OnSetCursor(CWnd* pWnd, UINT nHitTest, UINT message) 
{
	TRACE2( "CCgUIView::OnSetCursor - HitTest = %d, Msg = %d\n", nHitTest, message );
	IXReg_SetMousePointerMode( (int)CGS_GetValDbl(EDIT_MOUSE_POINTER_TYPE) );

	return( 1 );
}//end of CCgUIView::OnSetCursor
//////////////////////////////////////////////////////////////////////////////////////////////
// Handle popup menu when right mouse button was clicked.
// INPUT : DWORD popMenuID - return popup menu type from core
// INPUT : CPoint point - mouse position that locat the pop up menu
VOID CCgUIView::PopUpMenu(DWORD popMenuID, CPoint point)
{		
	CMenu	menu;
	menu.LoadMenu( popMenuID );
   
	switch( popMenuID )
	{
	case IDR_POP_COLOR_BIN:
		menu.GetSubMenu( 0 )->ModifyMenu( 0, MF_BYPOSITION, 0, m_pPopMenu[0].szDisplay );
		menu.GetSubMenu( 0 )->ModifyMenu( 1, MF_BYPOSITION, 0, m_pPopMenu[1].szDisplay );
		// append new pop up menu item here
		menu.GetSubMenu( 0 )->TrackPopupMenu( TPM_LEFTALIGN | TPM_RIGHTBUTTON, point.x, point.y, this );
		break;
	case IDR_POP_LAYER_LIST:
		menu.GetSubMenu( 0 )->ModifyMenu( 0, MF_BYPOSITION, 0, m_pPopMenu[0].szDisplay );
		menu.GetSubMenu( 0 )->ModifyMenu( 1, MF_BYPOSITION, 0, m_pPopMenu[1].szDisplay );
		// append new pop up menu item here
		menu.GetSubMenu( 0 )->TrackPopupMenu( TPM_LEFTALIGN | TPM_RIGHTBUTTON, point.x, point.y, this );
		break;
	case IDR_POP_PAGE_LIST:
		menu.GetSubMenu( 0 )->ModifyMenu( 0, MF_BYPOSITION, 0, m_pPopMenu[0].szDisplay );
		menu.GetSubMenu( 0 )->ModifyMenu( 1, MF_BYPOSITION, 0, m_pPopMenu[1].szDisplay );
		// append new pop up menu item here
		menu.GetSubMenu( 0 )->TrackPopupMenu( TPM_LEFTALIGN | TPM_RIGHTBUTTON, point.x, point.y, this );
		break;
	case IDR_POP_PAGE_OPT:
		menu.GetSubMenu( 0 )->ModifyMenu( 0, MF_BYPOSITION, 0, m_pPopMenu[0].szDisplay );
		menu.GetSubMenu( 0 )->ModifyMenu( 1, MF_BYPOSITION, 0, m_pPopMenu[1].szDisplay );
		// append new pop up menu item here
		menu.GetSubMenu( 0 )->TrackPopupMenu( TPM_LEFTALIGN | TPM_RIGHTBUTTON, point.x, point.y, this );
		break;
	case IDR_POP_PG_N_OBJ:
		menu.GetSubMenu( 0 )->ModifyMenu( 0, MF_BYPOSITION, 0, m_pPopMenu[0].szDisplay );
		menu.GetSubMenu( 0 )->ModifyMenu( 1, MF_BYPOSITION, 0, m_pPopMenu[1].szDisplay );
		menu.GetSubMenu( 0 )->TrackPopupMenu( TPM_LEFTALIGN | TPM_RIGHTBUTTON, point.x, point.y, this );
		break;
	case IDR_POP_STYLE_BIN:
		menu.GetSubMenu( 0 )->ModifyMenu( 0, MF_BYPOSITION, 0, m_pPopMenu[0].szDisplay );
		menu.GetSubMenu( 0 )->ModifyMenu( 1, MF_BYPOSITION, 0, m_pPopMenu[1].szDisplay );
		menu.GetSubMenu( 0 )->TrackPopupMenu( TPM_LEFTALIGN | TPM_RIGHTBUTTON, point.x, point.y, this );
		break;
	}//end of switch - popMenuID

}//end of CCgUIView::PopUpMenu
//////////////////////////////////////////////////////////////////////////////////
VOID CCgUIView::LoadPopMenuText()
{
	IN_TEXT_DATA* txtMenu = NULL;

	_TCHAR	sep[] = _T("\"");
	_TCHAR*	ptID;
	_TCHAR*	ptTT;
	_TCHAR*	ptEnd;

	// get number of menu item
	m_nItem = LoadTextFromCtl( "\\Util\\PopMenu.ctl", "[Menu]",    &txtMenu );
	if( m_nItem == 0 )
		return;

	m_pPopMenu = new POP_MENU_DATA[m_nItem];

	int j = 0;
	for( DWORD i = 0; i < m_nItem; i++ )
	{
		ptID   = _tcstok( txtMenu[i].szTT, sep );		
		ptTT   = _tcstok( NULL, sep );
		ptEnd  = _tcstok( NULL, sep );
		if( ptEnd != 0 )
			*ptEnd = '\0';
			
		_tcscpy( m_pPopMenu[i].szSearch,  ptID );
		_tcscpy( m_pPopMenu[i].szDisplay, ptTT );
	}//end of for

	free( txtMenu );

}//end of CCgUIView::LoadPopMenuText()
