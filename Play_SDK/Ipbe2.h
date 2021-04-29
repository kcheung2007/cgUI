//=============================================================================
// IPBE2.h
// Copyright 1998 Play Incorporated
//
// Created 1998 by Stephan Schaem
//=============================================================================
#ifndef IPBE2_H
#define IPBE2_H

#include <PlayInc.h>
#include <ipos2.h>
#include <ipgl2.h>

// PBE2 server implementation (See corresponding interface)
extern "C" const GUID CLSID_PCV2;
extern "C" const GUID CLSID_PIC2;
extern "C" const GUID CLSID_PBN2;
extern "C" const GUID CLSID_PBE2;
extern "C" const GUID CLSID_PBE2_DETAILVIEW;
extern "C" const GUID CLSID_PBE2_GRIDVIEW;
extern "C" const GUID CLSID_PBE2_LISTVIEW;
extern "C" const GUID CLSID_PBE2_CLIPVIEW;

extern IUnknown* __stdcall g_CLSID_PCV2();
extern IUnknown* __stdcall g_CLSID_PIC2();
extern IUnknown* __stdcall g_CLSID_PBN2();
extern IUnknown* __stdcall g_CLSID_PBE2();
extern IUnknown* __stdcall g_CLSID_PBE2_DETAILVIEW();
extern IUnknown* __stdcall g_CLSID_PBE2_LISTVIEW();
extern IUnknown* __stdcall g_CLSID_PBE2_GRIDVIEW();
extern IUnknown* __stdcall g_CLSID_PBE2_CLIPVIEW();

// -- IPCV2 --------------------------------------------------------------------
extern "C" const GUID IID_IPCV2;

enum F_PCV2_SETUP_FIELD {
	F_PCV2_SETUP_FIELD_ROWWEIGHT,			// A given weigth, to use as reference
	F_PCV2_SETUP_FIELD_ROWWIDTH,			// Width of a row in pixel
	F_PCV2_SETUP_FIELD_ROWHEIGHT,			// Height of a row in pixel
	F_PCV2_SETUP_FIELD_COLUMNSPACING,		// Spacing betwen columns in pixel
	F_PCV2_SETUP_FIELD_FLAGS,				// See: F_PCV2_SETUP_FLAGS
	F_PCV2_SETUP_FIELD_BKGDLI,				// First DLI in generated DL, and do not belong to any column
	F_PCV2_SETUP_FIELD_ORIGIN,				// XY position of first column cell in DL
};
enum PCV2_SETUP_FIELD {
	PCV2_SETUP_FIELD_ROWWEIGHT		= BIT(F_PCV2_SETUP_FIELD_ROWWEIGHT),
	PCV2_SETUP_FIELD_ROWWIDTH		= BIT(F_PCV2_SETUP_FIELD_ROWWIDTH),
	PCV2_SETUP_FIELD_ROWHEIGHT		= BIT(F_PCV2_SETUP_FIELD_ROWHEIGHT),
	PCV2_SETUP_FIELD_COLUMNSPACING	= BIT(F_PCV2_SETUP_FIELD_COLUMNSPACING),
	PCV2_SETUP_FIELD_FLAGS			= BIT(F_PCV2_SETUP_FIELD_FLAGS),
	PCV2_SETUP_FIELD_BKGDLI			= BIT(F_PCV2_SETUP_FIELD_BKGDLI),
	PCV2_SETUP_FIELD_ORIGIN			= BIT(F_PCV2_SETUP_FIELD_ORIGIN),
};

enum F_PCV2_SETUP_FLAGS {
	F_PCV2_SETUP_FLAGS_AUTOWEIGHT,			// The weight is calculated from the sum of the column weight
};
enum PCV2_SETUP_FLAGS {
	PCV2_SETUP_FLAGS_AUTOWEIGHT		= BIT(F_PCV2_SETUP_FLAGS_AUTOWEIGHT),
};

typedef struct {
	long	field;							// see PCV2_SETUP_FIELD
	long	flags;							// see PCV2_SETUP_FLAGS
	float	rowweight;
	long	rowwidth;
	long	rowheight;
	long	colspace;
	PGLDLI	bkgdli;
	long	orgnx, orgny;
} PCV2_SETUP;

enum F_PCV2_COLUMN_SETUP_FIELD {
	F_PCV2_COLUMN_SETUP_FIELD_NAME,			// This cell name
	F_PCV2_COLUMN_SETUP_FIELD_WEIGHT,		// weight related to the row weight
	F_PCV2_COLUMN_SETUP_FIELD_FLAGS,		// See: F_PCV2_COLUMN_FLAGS
	F_PCV2_COLUMN_SETUP_FIELD_DLI,			// Display list to assign  to cell
	F_PCV2_COLUMN_SETUP_FIELD_SPACING,		// Spacing of item in cell
};
enum PCV2_COLUMN_SETUP_FIELD {
	PCV2_COLUMN_SETUP_FIELD_NAME	= BIT(F_PCV2_COLUMN_SETUP_FIELD_NAME),
	PCV2_COLUMN_SETUP_FIELD_WEIGHT	= BIT(F_PCV2_COLUMN_SETUP_FIELD_WEIGHT),
	PCV2_COLUMN_SETUP_FIELD_FLAGS	= BIT(F_PCV2_COLUMN_SETUP_FIELD_FLAGS),
	PCV2_COLUMN_SETUP_FIELD_DLI		= BIT(F_PCV2_COLUMN_SETUP_FIELD_DLI),
	PCV2_COLUMN_SETUP_FIELD_SPACING	= BIT(F_PCV2_COLUMN_SETUP_FIELD_SPACING),
};

enum F_PCV2_COLUMN_SETUP_FLAGS {
	F_PCV2_COLUMN_SETUP_FLAGS_TEXTWRAP,		// Text will be wrap to next row (VS clipped to right edge)
	F_PCV2_COLUMN_SETUP_FLAGS_RIGHTALIGN,
	F_PCV2_COLUMN_SETUP_FLAGS_BOTTOMALIGN,
	F_PCV2_COLUMN_SETUP_FLAGS_LEFTALIGN,
	F_PCV2_COLUMN_SETUP_FLAGS_TOPALIGN,
};
enum PCV2_COLUMN_SETUP_FLAGS {
	PCV2_COLUMN_SETUP_FLAGS_TEXTWRAP	= BIT(F_PCV2_COLUMN_SETUP_FLAGS_TEXTWRAP),
	PCV2_COLUMN_SETUP_FLAGS_RIGHTALIGN	= BIT(F_PCV2_COLUMN_SETUP_FLAGS_RIGHTALIGN),
	PCV2_COLUMN_SETUP_FLAGS_BOTTOMALIGN	= BIT(F_PCV2_COLUMN_SETUP_FLAGS_BOTTOMALIGN),
	PCV2_COLUMN_SETUP_FLAGS_LEFTALIGN	= BIT(F_PCV2_COLUMN_SETUP_FLAGS_LEFTALIGN),
	PCV2_COLUMN_SETUP_FLAGS_TOPALIGN	= BIT(F_PCV2_COLUMN_SETUP_FLAGS_TOPALIGN),
	PCV2_COLUMN_SETUP_FLAGS_VERTCENTER	= (BIT(F_PCV2_COLUMN_SETUP_FLAGS_TOPALIGN) | BIT(F_PCV2_COLUMN_SETUP_FLAGS_BOTTOMALIGN)),
	PCV2_COLUMN_SETUP_FLAGS_HORZCENTER	= (BIT(F_PCV2_COLUMN_SETUP_FLAGS_LEFTALIGN) | BIT(F_PCV2_COLUMN_SETUP_FLAGS_RIGHTALIGN)),
};

typedef struct {							
	long	field;							// see PCV2_COLUMN_FIELD
	long	flags;							// see PCV2_COLUMN_FLAGS
	char*	name;
	float	weight;
	PGLDLI*	dli;
	PGLRECT	spacing;
	long	xpos;							// This value is returned by GetColumnSetup()
} PCV2_COLUMN_SETUP;

enum HR_IPCV2 {
	HR_IPCV2_WARNING = 0x00000000,
	HR_IPCV2_ERROR   = 0x80000000,
	HR_IPCV2_ERROR_COLUMN_OVERWEIGHT,		// The row is not 'fat' enought to add this column
	HR_IPCV2_ERROR_MAXCOLUMN,				// Max number of column reached
	HR_IPCV2_ERROR_ALLOCATING_COLUMN,		// Memory manager did not instantiate object
};

struct IPCV2 : public IUnknown { // Play Column View
	virtual HRESULT __stdcall Setup(PCV2_SETUP*)=0;
	virtual HRESULT __stdcall Reset()=0;
	virtual HRESULT __stdcall AddColumn(HANDLE* hColumn)=0;
	virtual HRESULT __stdcall RemoveColumn(HANDLE hColumn)=0;
	virtual HRESULT __stdcall MoveColumn(HANDLE hColumn, long Xpos)=0;
	virtual HRESULT __stdcall SizeColumn(HANDLE hColumn, float Weight)=0;
	virtual HRESULT __stdcall SetupColumn(HANDLE hColumn, PCV2_COLUMN_SETUP*)=0;
	virtual HRESULT __stdcall GetColumn(HANDLE* hColumn, long Xpos)=0;
	virtual void	__stdcall GetColumnSetup(HANDLE hColumn, PCV2_COLUMN_SETUP*)=0;
	virtual HRESULT __stdcall GenerateRow(PGLDL*)=0;
	virtual HRESULT __stdcall GenerateTitle(PGLDL*, IPGL2* pgl, HANDLE font, long h)=0;
	virtual HRESULT __stdcall GenerateGrid(PGLDL*, long h)=0;
};

// -- IPIC2 --------------------------------------------------------------------
extern "C" const GUID IID_IPIC2;

enum F_IPIC2_GETICON_FLAG {
	F_IPIC2_GETICON_FLAG_TIME,				// User provide the last modified time of file
	F_IPIC2_GETICON_FLAG_NOCACHE,			// Do not cache this icon
};
enum IPIC2_GETICON_FLAG {
	IPIC2_GETICON_FLAG_TIME		= BIT(F_IPIC2_GETICON_FLAG_TIME),
	IPIC2_GETICON_FLAG_NOCACHE	= BIT(F_IPIC2_GETICON_FLAG_NOCACHE),
};

enum HR_IPIC2 {
	HR_IPIC2_WARNING = 0x00000000,
	HR_IPIC2_WARNING_PATH_CREATED,
	HR_IPIC2_WARNING_FIRSTENTRY,
	HR_IPIC2_WARNING_CACHING_FAILED,
	HR_IPIC2_WARNING_ICON_CREATED,
	HR_IPIC2_ERROR = 0x80000000,
	HR_IPIC2_ERROR_INSTANTIATING_GXLATE,
	HR_IPIC2_ERROR_INSTANTIATING_ST,
	HR_IPIC2_ERROR_INSTANTIATING_GL,
	HR_IPIC2_ERROR_LOADING_FILE,
	HR_IPIC2_ERROR_OPENING_PST,
	HR_IPIC2_ERROR_OPENING_PICON,
	HR_IPIC2_ERROR_GETING_MODULEHANDLE,
	HR_IPIC2_ERROR_EXTRACTING_ICON,
	HR_IPIC2_ERROR_CREATING_COMPATIBLEDC,
	HR_IPIC2_ERROR_CREATING_DIBSECTION,
	HR_IPIC2_ERROR_SELECTING_ITEM,
	HR_IPIC2_ERROR_DRAWICON,
	HR_IPIC2_ERROR_OPENING_STORAGE,
	HR_IPIC2_ERROR_OPENING_STREAM,
	HR_IPIC2_ERROR_CREATING_STORAGE,
	HR_IPIC2_ERROR_CREATING_STREAM,
	HR_IPIC2_ERROR_STREAM_WRITE,
	HR_IPIC2_ERROR_IPERSISTFILE_GETFILE,
	HR_IPIC2_ERROR_INSTANTIATING_SHELLLINK,
	HR_IPIC2_ERROR_QUERING_IPERSISTFILE,
	HR_IPIC2_ERROR_IPERSISTFILE_LOADING,
	HR_IPIC2_ERROR_INVALID_PARAMETER,
	HR_IPIC2_ERROR_UNRESOLVED_LINK,
	HR_IPIC2_ERROR_UNSUPPORTED_EXTENSION,
	HR_IPIC2_ERROR_CREATING_ICON,
	HR_IPIC2_ERROR_INVALID_CACHE_STATE,
	HR_IPIC2_ERROR_OLD_ICON,
	HR_IPIC2_ERROR_CLONING_ICON,
	HR_IPIC2_ERROR_INSTANTIATING_GLR,
};

struct IPIC2 : public IUnknown { // Play Icon Cache
	virtual HRESULT __stdcall Initialize()=0;
	virtual HRESULT __stdcall FlushCache()=0;
	virtual HRESULT __stdcall BuildLocation(char*, long depth, long w, long h)=0;
	virtual HRESULT __stdcall CleanCache()=0;
	virtual HRESULT __stdcall ReleaseHold()=0;
	virtual HRESULT __stdcall GetIcon(IPCT2* pct, PGLBITMAP* image, bool* unique)=0;
};


// -- IPBN2_ITEM --------------------------------------------------------------
extern "C" const GUID IID_IPBN2_ITEM;

struct IPBN2;

enum F_PBN2_ITEM_FLAG {
	F_PBN2_ITEM_FLAG_VISIBLE,				// (READ ONLY) The item can be seen by the user 
	F_PBN2_ITEM_FLAG_INRANGE,				// (READ ONLY) The item is in close range, but do not imply visibility
	F_PBN2_ITEM_FLAG_HIDEN,					// The item rendering is not hiden, as been turn off
	F_PBN2_ITEM_FLAG_NOREFRESH,				// The item rendering as been turn off
};
enum PBN2_ITEM_FLAG {
	PBN2_ITEM_FLAG_VISIBLE		= BIT(F_PBN2_ITEM_FLAG_VISIBLE),
	PBN2_ITEM_FLAG_INRANGE		= BIT(F_PBN2_ITEM_FLAG_INRANGE),			
	PBN2_ITEM_FLAG_HIDEN		= BIT(F_PBN2_ITEM_FLAG_HIDEN),				
	PBN2_ITEM_FLAG_NOREFRESH	= BIT(F_PBN2_ITEM_FLAG_NOREFRESH),
};

typedef struct {
	long	x, y;
	long	w, h;
	void*	udata;
} PBN2_ITEM_INFO;

enum HR_IPBN2_ITEM {
	HR_IPBN2_ITEM_WARNING = 0x00000000,
	HR_IPBN2_ITEM_ERROR = 0xE8270000,
};

struct IPBN2_ITEM : public IUnknown { // Bin Item
	virtual HRESULT __stdcall Prev(IPBN2_ITEM** item)=0;
	virtual HRESULT __stdcall Next(IPBN2_ITEM** item)=0;
	virtual void	__stdcall Refresh()=0;
	virtual void	__stdcall SetDL(PGLDL* dl, long w, long h, PGLRECTI* rect)=0;
	virtual void	__stdcall SetUserData(void* udata)=0;
	virtual void	__stdcall GetInfo(PBN2_ITEM_INFO* info)=0;
	virtual long	__stdcall Flags(long on, long off)=0;
	virtual void	__stdcall SetPosition(long x, long y)=0;
	virtual long	__stdcall GetFlags()=0;
	virtual void*	__stdcall GetUserData()=0;
};


// -- IPBN2 --------------------------------------------------------------------
extern "C" const GUID IID_IPBN2;


enum F_PBN2_SETUP {
	F_PBN2_SETUP_FIELD_ITEMSPACING,			// Override default of 4:4:4:4 pixel spacing
	F_PBN2_SETUP_FIELD_EDGESPACING,			// Override default 0:0:0:0 pixel spacing
	F_PBN2_SETUP_FIELD_BACKGROUND,			// Background image
};
enum PBN2_SETUP_FIELD {
	PBN2_SETUP_FIELD_ITEMSPACING	= BIT(F_PBN2_SETUP_FIELD_ITEMSPACING),			
	PBN2_SETUP_FIELD_EDGESPACING	= BIT(F_PBN2_SETUP_FIELD_EDGESPACING),
	PBN2_SETUP_FIELD_BACKGROUND		= BIT(F_PBN2_SETUP_FIELD_BACKGROUND),
};

typedef struct {							
	long	field;							// See: F_PBN2_SETUP_FIELD
	PGLRECT	ispace;
	PGLRECT	espace;
	PGLDLI	bkgdli;
} PBN2_SETUP;

typedef struct {
	long	x, y;							// Offset of vrect in vsrect
	PGLRECT	vrect;							// Size of the view
	PGLRECT	vsrect;							// Size of the Virtual Space
	PGLRECT	brect;							// Size of used virtual Space (bounding rect on items)
} PBN2_VIEW_INFO;

enum F_PBN2_FLAG {
	F_PBN2_FLAG_MULTIPLESELECT,				// Turn on multiple selection support
	F_PBN2_FLAG_VERTICAL,					// Items are added & wrap vertically
	F_PBN2_FLAG_AUTOARANGE,					// Recalculate organization on resize
	F_PBN2_FLAG_FIXEDBKG,					// With this flag, the background will not scroll
	F_PBN2_FLAG_NOREFRESH,					// The rendering as been turn off
};
enum PBN2_FLAG {
	PBN2_FLAG_MULTIPLESELECT	= BIT(F_PBN2_FLAG_MULTIPLESELECT),
	PBN2_FLAG_VERTICAL			= BIT(F_PBN2_FLAG_VERTICAL),		
	PBN2_FLAG_AUTOARANGE		= BIT(F_PBN2_FLAG_AUTOARANGE),
	PBN2_FLAG_FIXEDBKG			= BIT(F_PBN2_FLAG_FIXEDBKG),			
	PBN2_FLAG_NOREFRESH			= BIT(F_PBN2_FLAG_NOREFRESH),
};

enum HR_IPBN2 {
	HR_IPBN2_WARNING = 0x00000000,
	HR_IPBN2_ERROR = 0xE8270000,
};

struct IPBN2 : public IUnknown { // Bin

	// Base functions
	virtual HRESULT __stdcall Init(IPDS2*, PGLRECT* cliprect)=0;
	virtual HRESULT __stdcall Setup(PBN2_SETUP* setup)=0;
	virtual HRESULT __stdcall Flags(long on, long off)=0;

	// View related functions
	virtual HRESULT __stdcall SetViewOffset(long x, long y)=0;
	virtual HRESULT __stdcall SetViewSize(long w, long h)=0;
	virtual HRESULT __stdcall SetVirtualRect(PGLRECT* rect)=0;
	virtual HRESULT __stdcall GetViewInfo(PBN2_VIEW_INFO* info)=0;
	virtual HRESULT __stdcall SetViewHeader(PGLDL* , long w, long h)=0;
	virtual HRESULT __stdcall SetViewGrid(PGLDL* , long w, long h)=0;
	virtual void	__stdcall AutoArrange(bool area)=0;

	// Item related functions
	virtual HRESULT __stdcall FirstItem(IPBN2_ITEM** item)=0;
	virtual HRESULT __stdcall GetItem(IPBN2_ITEM** item, long x, long y)=0;
	virtual HRESULT __stdcall AddItem(IPBN2_ITEM** item, long w, long h, PGLRECTI* space, PGLDL* dl, long state, void *udata)=0;
	virtual void	__stdcall RemoveAllItem()=0;
	virtual void	__stdcall RemoveItem(IPBN2_ITEM* item)=0;
};

// -- IPBE2_ITEM --------------------------------------------------------------------
extern "C" const GUID IID_IPBE2_ITEM;

struct IPBE2;

enum F_PBE2_ITEM_FLAG {
	F_PBE2_ITEM_FLAG_HIDE,					// Dont show this item
};
enum PBE2_ITEM_FLAG {
	PBE2_ITEM_FLAG_HIDE		= BIT(F_PBE2_ITEM_FLAG_HIDE),
};

enum F_PBE2_ITEM_ATTR {						// Item attributes
	F_PBE2_ITEM_ATTR_SHOWNAME,				// This item should have its name displayed
};
enum PBE2_ITEM_ATTR {
	PBE2_ITEM_ATTR_SHOWNAME	= BIT(F_PBE2_ITEM_ATTR_SHOWNAME),
};

enum F_PBE2_ITEM_INFO_FIELD {
	F_PBE2_ITEM_INFO_FIELD_POS,				// Position of item in bin view
	F_PBE2_ITEM_INFO_FIELD_UID,				// Unique id for this item
	F_PBE2_ITEM_INFO_FIELD_ICON,			// Icon
	F_PBE2_ITEM_INFO_FIELD_ATTR,			// See: F_PBE2_ITEM_ATTR  
	F_PBE2_ITEM_INFO_FIELD_PCT,				// PCT container associated with this item, and its item reference.
};
enum PBE2_ITEM_INFO_FIELD {
	PBE2_ITEM_INFO_FIELD_POS	= BIT(F_PBE2_ITEM_INFO_FIELD_POS),
	PBE2_ITEM_INFO_FIELD_UID	= BIT(F_PBE2_ITEM_INFO_FIELD_UID),
	PBE2_ITEM_INFO_FIELD_ICON	= BIT(F_PBE2_ITEM_INFO_FIELD_ICON),
	PBE2_ITEM_INFO_FIELD_ATTR	= BIT(F_PBE2_ITEM_INFO_FIELD_ATTR),
	PBE2_ITEM_INFO_FIELD_PCT	= BIT(F_PBE2_ITEM_INFO_FIELD_PCT),
};

typedef struct {
	long	field;							// see: F_PBE2_ITEM_INFO_FIELD
	long	xp, yp;
	long	uid;
	PGLBITMAP	icon;
	long	attr;							// See: F_PBE2_ITEM_ATTR  
	IPCT2*	pct;							// See: F_PBE2_ITEM_INFO_PCT
	long	pctref;							// See: F_PBE2_ITEM_INFO_PCT
} PBE2_ITEM_INFO;

enum HR_IPBE2_ITEM {
	HR_IPBE2_ITEM_WARNING = 0x00000000,
	HR_IPBE2_ITEM_NOACTION,					// The selection/hiliting request caused no action to be performed
	HR_IPBE2_ITEM_ERROR = 0xE0000000,
};

struct IPBE2_ITEM : public IUnknown { // Bin Explorer Item
	virtual HRESULT __stdcall GetInfo(PBE2_ITEM_INFO* info)=0;
	virtual	HRESULT __stdcall GetIcon(PGLBITMAP*, long flags)=0;
	virtual HRESULT __stdcall Delete()=0;
	virtual HRESULT __stdcall Rename()=0;
	virtual HRESULT __stdcall Flags(long on, long off)=0;
	virtual HRESULT __stdcall Next(IPBE2_ITEM** item)=0;
	virtual HRESULT __stdcall Prev(IPBE2_ITEM** item)=0;
	virtual HRESULT __stdcall Refresh(bool icon)=0;
	virtual HRESULT __stdcall Rename(char* newname)=0;
	virtual HRESULT __stdcall Select()=0;
	virtual HRESULT __stdcall Deselect()=0;
	virtual HRESULT __stdcall Hilite()=0;
	virtual HRESULT __stdcall Unhilite()=0;
};

// -- IPBE2_LOCATION --------------------------------------------------------------------
extern "C" const GUID IID_IPBE2_LOCATION;

enum HR_IPBE2_LOCATION {
	HR_IPBE2_LOCATION_WARNING = 0x00000000,
	HR_IPBE2_LOCATION_ERROR = 0xE0000000,
};

struct IPBE2_LOCATION : public IUnknown { // Bin Explorer Location
	virtual HRESULT	__stdcall GetDisplayName(char* name, long count)=0;
	virtual HRESULT	__stdcall GetIPCT2(IPCT2** pct)=0;
	virtual void	__stdcall UpdateIcon(IPBE2_ITEM* item)=0;
	virtual void	__stdcall StopUpdates()=0;

	// Item Related functions
	virtual HRESULT __stdcall FirstItem(IPBE2_ITEM** item)=0;
	virtual HRESULT	__stdcall GetItem(IPBE2_ITEM** item, ulong uid)=0;
	virtual HRESULT	__stdcall GetItem(IPBE2_ITEM** item, long ref)=0;
	virtual HRESULT __stdcall GetItem(IPBE2_ITEM** item, char* name)=0;
	virtual HRESULT __stdcall GetItemSelected(IPBE2_ITEM*** item, long* count)=0;
	virtual void	__stdcall SelectAll()=0;
	virtual void	__stdcall SelectNone()=0;
	virtual void	__stdcall InvertSelection()=0;
};

// -- IPBE2_VIEW --------------------------------------------------------------
extern "C" const GUID IID_IPBE2_VIEW;
struct IPBE2_VIEW;

typedef struct {
	PGLCOLOR	background;
	PGLCOLOR	selection;
	PGLCOLOR	highlight;
	PGLCOLOR	text;
} PBE2_SCHEME;

typedef struct  {
	long	iconw, iconh;
	long	sortstyle;
	long	viewstyle;						// See: PBE2_VIEWSTYLE (Ultimatly this should be a classid)
	GUID	viewclass;
	
	PGLBITMAP*	link;						// Provide the symbol for a link
	PBE2_SCHEME	scheme;
	
	struct {
		char	showpiconname;
		char	showid;
		char	showlink;
	} overlay;

} PBE2_PROFILE;

enum IPBE2_VIEW_ELEMENT  {
	IPBE2_VIEW_ELEMENT_NONE,
	IPBE2_VIEW_ELEMENT_UNDEFINED,
	IPBE2_VIEW_ELEMENT_ICON,
	IPBE2_VIEW_ELEMENT_DISPLAYNAME,
	IPBE2_VIEW_ELEMENT_CUSTOM = 0x80,
};

typedef struct {
	PGLRECTI	space;						// 'Kerning' information for item
	short		w, h;						// The space this item take
	PGLDL		dl;							// Display list
	long		udata;						// 'User' data, NOTE: This can be used for resource tracking
	IPBE2_VIEW*	view;						// Viewer that created this PBE2_DL PGLDL
} PBE2_DL;

enum IPBE2_VIEW_TYPE {
	IPBE2_VIEW_TYPE_NORMAL,
	IPBE2_VIEW_TYPE_HIGHLIGHT,
	IPBE2_VIEW_TYPE_SELECTED,
	IPBE2_VIEW_TYPE_DRAG,
};

struct IPBE2_VIEW_NOTIFY {
	virtual HRESULT	__stdcall Change(IPBE2_ITEM* item, PBE2_DL* newdl, PGLRECT* rect, long rcount) {return 0;};
	virtual HRESULT	__stdcall StartEdit(IPBE2_ITEM* item) {return 0;};
	virtual HRESULT	__stdcall EndEdit(IPBE2_ITEM* item) {return 0;};
};

struct IPBE2_VIEW : public IUnknown {
	virtual HRESULT	__stdcall Init(IPGL2*, IPBN2*, IPBE2_VIEW_NOTIFY*)=0;
	virtual HRESULT	__stdcall SetPref(PBE2_PROFILE*)=0;
	virtual HRESULT	__stdcall CreateDL(IPBE2_ITEM*, PBE2_DL*, IPBE2_VIEW_TYPE)=0;
	virtual HRESULT	__stdcall UpdateDL(IPBE2_ITEM*, PBE2_DL*, IPBE2_VIEW_TYPE, PGLRECT** rect, long* count)=0;
	virtual HRESULT	__stdcall DestroyDL(PBE2_DL*)=0;
	virtual HRESULT	__stdcall Dimension(IPBE2_ITEM*, PBE2_DL*, IPBE2_VIEW_TYPE)=0;
	virtual HRESULT	__stdcall GetElement(IPBE2_ITEM*, PBE2_DL*, IPBE2_VIEW_ELEMENT* element, long x, long y)=0;
	virtual HRESULT	__stdcall EditElement(IPBE2_ITEM*, PBE2_DL*, IPBE2_VIEW_ELEMENT element, long x, long y)=0;
	virtual HRESULT	__stdcall GetHint(IPBE2_ITEM*, char* string, long count)=0;
};

// -- IPBE2 --------------------------------------------------------------------
extern "C" const GUID IID_IPBE2;

typedef HRESULT (__stdcall PBE2_VISIBILITY)(IPBE2_ITEM*, void *);

// -- IMPORT --------------------------

enum PBE2_IMPORT_MODE {
	PBE2_IMPORT_MODE_DEFAULT,				// Any of the following that fit the situation
	PBE2_IMPORT_MODE_COPY,					// Copy operation requested by owner
	PBE2_IMPORT_MODE_MOVE,					// Move operation requested by owner
	PBE2_IMPORT_MODE_LINK,					// Link operation requested by owner
};

enum PBE2_IMPORT_TYPE {
	PBE2_IMPORT_TYPE_ASCIPATH,				// The item data is a pointer to an acsi path
	PBE2_IMPORT_TYPE_IUNKNOW,				// COM interface , see iid
};

typedef struct {
	PBE2_IMPORT_MODE mode;					// See: PBE2_IMPORT
	long	type;							// See PBE2_IMPORT_TYPE
	GUID	iid;							// The prefered interface
} PBE2_IMPORT_INFO;

struct PBE2_IMPORT {
	virtual HRESULT __stdcall GetInfo(PBE2_IMPORT_INFO*)=0;		// This import item description
	virtual HRESULT __stdcall GetData(void*	data)=0;			// This import item data
};

// -- CLIENT NOTIFICATION -------------

struct PBE2_NOTIFY {
	virtual HRESULT __stdcall Added(IPBE2_ITEM**, long count){return 0;};		// 1+ items beying Added
	virtual HRESULT __stdcall Removed(IPBE2_ITEM**, long count){return 0;};		// 1+ items beying Removed
	virtual HRESULT __stdcall Selected(IPBE2_ITEM**, long count){return 0;};	// 1+ items beying Selected
	virtual HRESULT __stdcall Deselected(IPBE2_ITEM**, long count){return 0;};	// 1+ items beying Delesected
	virtual HRESULT __stdcall Draged(IPBE2_ITEM**, long count){return 0;};		// 1+ items beying Dragged
	virtual HRESULT __stdcall Executed(IPBE2_ITEM**, long count){return 0;};	// 1+ items to be Executed
	virtual HRESULT __stdcall Exported(IPBE2_ITEM**, long count){return 0;};	// 1+ items to be Exported
	virtual HRESULT __stdcall NewLocation(IPBE2_LOCATION* loc){return 0;};		// The bin now browsing this object
	virtual HRESULT __stdcall Pan(){return 0;};									// The virtual view as moved
	virtual HRESULT __stdcall NewVirtualSize(){return 0;};						// The bin virtual size as changed
	virtual HRESULT __stdcall UserPrompt(POS2_PROMPT*){return 0;};				// Visual info/request
};

// -- SETUP ---------------------------

enum F_PBE2_SETUP_FIELD {
	F_PBE2_SETUP_FIELD_SORTSTYLE,			// See: PBE2_SORTSTYLE
	F_PBE2_SETUP_FIELD_VIEWSTYLE,			// See: PBE2_VIEWSTYLE
	F_PBE2_SETUP_FIELD_INITIALUID,			// Initial UID
	F_PBE2_SETUP_FIELD_NOTIFY,				// User call backs functions
	F_PBE2_SETUP_FIELD_VISIBILITY,			// Custom function to test visibility of an item
	F_PBE2_SETUP_FIELD_BKGIMG,				// use this image VS dark grey
	F_PBE2_SETUP_FIELD_ICONSIZE,			// User provide the icon width & icon height
	F_PBE2_SETUP_FIELD_VIEWSTRING,			// HACKORAMA...
	F_PBE2_SETUP_FIELD_FONT,				// Use this to change the default of "Verdana 15 black" 
};
enum PBE2_SETUP_FIELD {
	PBE2_SETUP_FIELD_SORTSTYLE		= BIT(F_PBE2_SETUP_FIELD_SORTSTYLE),			
	PBE2_SETUP_FIELD_VIEWSTYLE		= BIT(F_PBE2_SETUP_FIELD_VIEWSTYLE),			
	PBE2_SETUP_FIELD_INITIALUID		= BIT(F_PBE2_SETUP_FIELD_INITIALUID),			
	PBE2_SETUP_FIELD_NOTIFY			= BIT(F_PBE2_SETUP_FIELD_NOTIFY),
	PBE2_SETUP_FIELD_VISIBILITY		= BIT(F_PBE2_SETUP_FIELD_VISIBILITY),			
	PBE2_SETUP_FIELD_BKGIMG			= BIT(F_PBE2_SETUP_FIELD_BKGIMG),				
	PBE2_SETUP_FIELD_ICONSIZE		= BIT(F_PBE2_SETUP_FIELD_ICONSIZE),			
	PBE2_SETUP_FIELD_VIEWSTRING		= BIT(F_PBE2_SETUP_FIELD_VIEWSTRING),			
	PBE2_SETUP_FIELD_FONT			= BIT(F_PBE2_SETUP_FIELD_FONT),			
};

typedef struct {
	long	field;							// see: F_PBE2_SETUP_FIELD
	long	sortstyle;						// See: F_PBE2_SETUP_SORTSTYLE
	long	viewstyle;						// See: F_PBE2_SETUP_VIEWSTYLE
	long	iuid;							// See: F_PBE2_SETUP_INITIALUID
	PBE2_NOTIFY* notify;					// See: PBE2_NOTIFY for implementation
	PBE2_VISIBILITY* isvisible;
	void*	ivuserdata;
	PGLDLI	bkgimg;
	long	iconw, iconh;
	char*	viewstring;						// Hack for menu first name

	struct {
		char*	name;
		long	tyle;
		long	size;
	} font;

} PBE2_SETUP;

// ------------------------------------

enum F_PBE2_FLAG {
	F_PBE2_FLAG_ONLYIMAGE,					// Show only images & folder
	F_PBE2_FLAG_SHOWLINK,					// Show link indicator on 'shortcut'
	F_PBE2_FLAG_IMAGENANE,					// Show name on file with image type icon
	F_PBE2_FLAG_AUTOARANGE,					// Recalculate organization on resize
	F_PBE2_FLAG_MULTIPLESELECT,				// Turn on multiple selection support
	F_PBE2_FLAG_VERTICAL,					// Items are added & wrap vertically
	F_PBE2_FLAG_NUMBERING,					// Turn on on icon numbering
	F_PBE2_FLAG_DESCENDSORT,				// Revert sort order
	F_PBE2_FLAG_FIXEDBKG,					// The background will not scroll with the content
	F_PBE2_FLAG_ENABLEHINTS,				// Enable the display of hints popups
	F_PBE2_FLAG__HIDENAME,					// Display name starting with an _ will not be shown
};
enum PBE2_FLAG {
	PBE2_FLAG_ONLYIMAGE			= BIT(F_PBE2_FLAG_ONLYIMAGE),		
	PBE2_FLAG_SHOWLINK			= BIT(F_PBE2_FLAG_SHOWLINK),		
	PBE2_FLAG_IMAGENANE			= BIT(F_PBE2_FLAG_IMAGENANE),		
	PBE2_FLAG_AUTOARANGE		= BIT(F_PBE2_FLAG_AUTOARANGE),		
	PBE2_FLAG_MULTIPLESELECT	= BIT(F_PBE2_FLAG_MULTIPLESELECT),	
	PBE2_FLAG_VERTICAL			= BIT(F_PBE2_FLAG_VERTICAL),		
	PBE2_FLAG_NUMBERING			= BIT(F_PBE2_FLAG_NUMBERING),		
	PBE2_FLAG_DESCENDSORT		= BIT(F_PBE2_FLAG_DESCENDSORT),		
	PBE2_FLAG_FIXEDBKG			= BIT(F_PBE2_FLAG_FIXEDBKG),		
	PBE2_FLAG_ENABLEHINTS		= BIT(F_PBE2_FLAG_ENABLEHINTS),		
	PBE2_FLAG__HIDENAME			= BIT(F_PBE2_FLAG__HIDENAME),		
};

enum PBE2_VIEWSTYLE {						// The generic file system oriented viewer (always available)
	PBE2_VIEWSTYLE_ICON,					// Full size icon ordered depending on various flags. See: F_PBE2_FLAG
	PBE2_VIEWSTYLE_DETAILED,				// Row mode with various colums detailing item
	PBE2_VIEWSTYLE_LIST,					// Showed by small icon & name ordered depending on various flags. See: F_PBE2_FLAG
	PBE2_VIEWSTYLE_CLIP,					// NAB quicky, a preset DETAILED view for clips *.clp
};

enum PBE2_SORTSTYLE {						// Build it file system based sorting methode
	PBE2_SORTSTYLE_NONE,					// The order is 'random', curent version still sort by first letter
	PBE2_SORTSTYLE_NAME,					// Sorted by name, case independant, folder firt.
	PBE2_SORTSTYLE_SIZE,					// Sort by size (support 2^64 size), fall back to PBE2_SORTSTYLE_NAME on equal size
	PBE2_SORTSTYLE_TYPE,					// Sort by filename extension, fall back to PBE2_SORTSTYLE_NAME on equal size
	PBE2_SORTSTYLE_DATE,					// Sort by mofifyed date, fall back to PBE2_SORTSTYLE_NAME on equal size
};

typedef struct {							// Basic information on the current Bin Explorer state
	IPCT2*	pct;							// The current browsed pct
	long	itemcount;						// Total Number of (visible & hiden) items (include folders)
	long	foldercount;					// Total Number of (visible & hiden) folder in the current location
	long	historycount;					// Number of entry in the location history buffer
	long	historypos;						// The current view index in that history list
} PBE2_INFO;

enum F_PBE2_POKE_TYPE {						// This should go away with the implementation of PlayInput
	F_PBE2_POKE_TYPE_LMB,					// Left mouse button
	F_PBE2_POKE_TYPE_RMB,					// Right mouse button
	F_PBE2_POKE_TYPE_UP,					// Button up (default to bown)
	F_PBE2_POKE_TYPE_DBC,					// Double click (default to single click)
	F_PBE2_POKE_TYPE_TIMER,					// Timer
	F_PBE2_POKE_TYPE_SHIFT,					// Shift modifyer
	F_PBE2_POKE_TYPE_CTRL,					// Control modifyer
};
enum PBE2_POKE_TYPE {
	PBE2_POKE_TYPE_LMB			= BIT(F_PBE2_POKE_TYPE_LMB),	
	PBE2_POKE_TYPE_RMB			= BIT(F_PBE2_POKE_TYPE_RMB),	
	PBE2_POKE_TYPE_UP			= BIT(F_PBE2_POKE_TYPE_UP),		
	PBE2_POKE_TYPE_DBC			= BIT(F_PBE2_POKE_TYPE_DBC),
	PBE2_POKE_TYPE_TIMER		= BIT(F_PBE2_POKE_TYPE_TIMER),	
	PBE2_POKE_TYPE_SHIFT		= BIT(F_PBE2_POKE_TYPE_SHIFT),	
	PBE2_POKE_TYPE_CTRL			= BIT(F_PBE2_POKE_TYPE_CTRL),	
};

enum HR_IPBE2 {
	HR_IPBE2_WARNING = 0x08260000,
	HR_IPBE2_WARNING_LASTENTRY,
	HR_IPBE2_WARNING_FIRSTENTRY,
	HR_IPBE2_ERROR = 0xE8260000,

	HR_IPBE2_ERROR_INSTANTIATING_IPIC2,
	HR_IPBE2_ERROR_INSTANTIATING_IPGL2,
	HR_IPBE2_ERROR_INSTANTIATING_IPST,
	HR_IPBE2_ERROR_INSTANTIATING_IPBN2,
	HR_IPBE2_ERROR_INSTANTIATING_IPCT2,
	HR_IPBE2_ERROR_INSTANTIATING_IPCTM2,
	HR_IPBE2_ERROR_INSTANTIATING_IPGLR2,
	HR_IPBE2_ERROR_INITIALIZING_BN,
	HR_IPBE2_ERROR_INITIALIZING_IC,
	HR_IPBE2_ERROR_OPENING_PST,
	HR_IPBE2_ERROR_SCANING_LOCATION,
	
	/*	HR_IPBE2_ERROR_OPENING_LOCATION,
	HR_IPBE2_ERROR_GETTING_LINK,
	HR_IPBE2_ERROR_GETTING_MODULEHANDLE,
	HR_IPBE2_ERROR_CREATING_DC,
	HR_IPBE2_ERROR_CREATING_DIBSECTION,
	HR_IPBE2_ERROR_SELECTING_ITEM,
	HR_IPBE2_ERROR_DRAWING_ICON,
	HR_IPBE2_ERROR_GETTING_GETDISPLAYNAMEOF,
	HR_IPBE2_ERROR_ILLEGAL_STATE,
	HR_IPBE2_ERROR_CREATING_FOLDER,
	HR_IPBE2_ERROR_NO_ITEM,
	HR_IPBE2_ERROR_CREATING_FONT,
	HR_IPBE2_ERROR_SCANNING_LOCATION,
	HR_IPBE2_ERROR_LOADING_DEFAULT,
	HR_IPBE2_ERROR_GETTING_DSLAYER,
	HR_IPBE2_ERROR_GETING_DESKTOPFOLDER,
	HR_IPBE2_ERROR_CREATING_ITEM,
	HR_IPBE2_ERROR_NO_PARENT,
	*/
};

struct IPBE2 : public IUnknown { // Play Bin Explorer

	virtual HRESULT __stdcall Init(IPDS2* pds, PGLRECT* cliprect, PBE2_NOTIFY* notify)=0;
	virtual HRESULT __stdcall Setup(PBE2_SETUP* setup)=0;
	virtual long	__stdcall Flags(long on, long off)=0;
	virtual HRESULT __stdcall GetInfo(PBE2_INFO* info)=0;
	virtual void	__stdcall RemoveAllItems()=0;
	virtual HRESULT __stdcall NewFolder(char* name)=0;
	virtual void	__stdcall RefreshItems()=0;

	// Event related functions
	virtual void	__stdcall Poke(long x, long y, long type)=0;
	virtual void	__stdcall Timer()=0;

	// Navigation related functions
	virtual HRESULT __stdcall SetLocation(char* name)=0;
	virtual HRESULT __stdcall SetLocation(IPCT2* pct)=0;
	virtual HRESULT __stdcall SetLocation(IPBE2_LOCATION* location)=0;
	virtual HRESULT __stdcall Scan()=0;
	virtual HRESULT __stdcall Parent()=0;
	virtual HRESULT __stdcall Back()=0;
	virtual HRESULT __stdcall Forth()=0;
	virtual	HRESULT __stdcall ClearHistory()=0;
	virtual HRESULT __stdcall GetLocations(IPBE2_LOCATION** locations, long* count)=0;
	virtual HRESULT __stdcall GetNextLocations(IPBE2_LOCATION** locations, long* count)=0;
	virtual HRESULT __stdcall GetPrevLocations(IPBE2_LOCATION** locations, long* count)=0;

	// View related functions
	virtual HRESULT __stdcall SetVirtualOffset(long x, long y)=0;
	virtual HRESULT __stdcall SetVirtualSize(PGLRECT* rect)=0;
	virtual HRESULT __stdcall GetVirtualInfo(PBN2_VIEW_INFO* info)=0;
	virtual HRESULT __stdcall SetViewSize(long x, long y)=0;

	// Import related functions
	virtual	HRESULT	__stdcall ImportCreate(HANDLE* drag, char* name)=0;			// name should be am IPCT
	virtual	HRESULT	__stdcall ImportDrag(HANDLE drag, long xp, long yp)=0;
	virtual	HRESULT	__stdcall ImportDrop(HANDLE drag, long mode)=0;
	virtual	HRESULT	__stdcall ImportDestroy(HANDLE drag)=0;

	// Configuration related functions
	virtual HRESULT	__stdcall Load()=0;
	virtual HRESULT	__stdcall Save()=0;
};

#endif
