/////////////////////////////////////
#include "StdAfx.h"
#include "ACGS_Inc\\acg_opts.h"

#define		GERMAN_VER		0 // F1 - help, F10 - Style Reset

#if LITE_VERSION
	//---------------------------------------------
	//LITE PROGRAM VERSION - some features disabled
	#define		LITE_TOOLBAR	1 // vertical toolbar

	const BOOL	PRESET     = 0;
	const BOOL	CAPTURE    = 0;
	const BOOL	EFFECT	   = 0;
	const BOOL	BASELINE   = 0;
	const BOOL	ATTRIBUTE  = 1;
	const BOOL  SELECTION  = 0;
	const BOOL  VIEW       = 0;
	const BOOL	TEMPLATE   = 0;
	const BOOL	SHOW_PAGE  = 1;
	const BOOL	SHOW_LAYER = 0;

	const UINT	BAR_NUMTAB    = 8;  // total number of tabs
	const UINT	BAR_MAXTEXT	  = 20; // max. characters for tabs string

	const BOOL  HIDE_TEXT_ATTRIB = 1; // hide some controls of text attribute dlg
	const BOOL  HIDE_BASE_LINE   = 0; // hide some controls of baseline dlg
	const BOOL  HIDE_FACE_ATTRIB = 1; // hide some controls of face attribute dlg
	//-------------------------------------------
#else
	//-------------------------------------------
	//FULL PROGRAM VERSION - all features enabled
	
	#define		LITE_TOOLBAR	0 // vertical toolbar

	const BOOL	PRESET     = 0;
	const BOOL	CAPTURE    = 1;
	const BOOL	EFFECT	   = 1;
	const BOOL	BASELINE   = 1;
	const BOOL	ATTRIBUTE  = 1;
	const BOOL  SELECTION  = 1;
	const BOOL  VIEW       = 1;
	const BOOL	TEMPLATE   = 1;
	const BOOL	SHOW_PAGE  = 1;
	const BOOL	SHOW_LAYER = 1;

	const UINT	BAR_NUMTAB    = 8;  // total number of tabs
	const UINT	BAR_MAXTEXT	  = 20; // max. characters for tabs string

	const BOOL  HIDE_TEXT_ATTRIB = 0; // hide some controls of text attribute dlg
	const BOOL  HIDE_BASE_LINE   = 0; // hide some controls of baseline dlg
	const BOOL  HIDE_FACE_ATTRIB = 0; // hide some controls of face attribute dlg
	//-------------------------------------------
#endif //LITE_VERSION

#ifdef _DEBUG
const DWORD	MENU_TYPE = IDR_KENT_MENU;
#else
const DWORD	MENU_TYPE = IDR_CGUITYPE;
#endif