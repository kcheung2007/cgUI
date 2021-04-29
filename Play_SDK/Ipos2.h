//=============================================================================
// IPOS2.h
// Copyright 1999 Play Incorporated
//
// Created 1999 by Stephan Schaem
//=============================================================================
#ifndef IPOS2_H
#define IPOS2_H

#include <PlayInc.h>
#include <ToolBox.h>
#include <ipst2.h>
#include <ipgl2.h>

extern HRESULT CoCreateLocalInstance(REFCLSID clsid, REFIID iid, void** ppv);

extern "C" const GUID CLSID_PCT2;				// Implement IPCT2 for root browsing, and IPCTM2
extern "C" const GUID CLSID_PCT2_PST2;
extern "C" const GUID CLSID_PCT2_MSFS;
extern "C" const GUID CLSID_PCT2_MSSF;
extern "C" const GUID CLSID_PCT2_GXLATE;

extern IUnknown* __stdcall g_CLSID_PCT2();
extern IUnknown* __stdcall g_CLSID_PCT2_PST2();
extern IUnknown* __stdcall g_CLSID_PCT2_MSFS();
extern IUnknown* __stdcall g_CLSID_PCT2_MSSF();
extern IUnknown* __stdcall g_CLSID_PCT2_GXLATE();

// -- IPOS2 --------------------------------------------------------------------
extern "C" const GUID IID_IPOS2;
extern "C" const GUID IID_IPOS2_WIN32;

// ------------------------------------
extern "C" const GUID IID_IPP2;

struct IPP2 : public IUnknown {
	virtual HRESULT __stdcall GetPicon(PGLBITMAP* picon, bool* unique)=0;
	virtual HRESULT __stdcall GetVersion(__int64* version)=0;
};

// ------------------------------------
enum POS2_PROMPT_STYLE {
	POS2_PROMPT_INFORM,						// str[0] is the user message, str[1] represent 'close'
	POS2_PROMPT_REQUEST,					// str[0] is the user message, str[1], str[2] represent 'true'/'false'
};

typedef struct {
	long	style;							// See: POS2_PROMPT_STYLE
	long	result;							// Defined by the prompt style
	char*	str[8];							// Defined by the prompt style
} POS2_PROMPT;

struct POS2_USERPROMPT {
	virtual HRESULT __stdcall Prompt(POS2_PROMPT*)=0;
};

// -- IPCT2_ST --------------------------------------------------------------------
extern "C" const GUID IID_IPCT2_ST;

struct IPCT2_ST : public IUnknown {
	virtual HRESULT __stdcall Init(IPST2* pst)=0;
};

// -- IPCT2 --------------------------------------------------------------------
extern "C" const GUID IID_IPCT2;
extern "C" const GUID IID_IPCTM2;
extern "C" const GUID IID_IPCTN2;

struct	IPCT2;
	
#define PCT_MAX_DISPLAYNAME		256			// Including null terminator
#define PCT_MAX_PATHNAME		256			// Including null terminator
	
#define IPCT2_TYPE_UNRESOLVED	0			// The type determination need analisys
#define IPCT2_TYPE_UNKNOWN		0			// The type cannot be resolved

// A service that transform those class & type into a display name is required

enum IPCT2_CLSTYPE {						// Common class type
	IPCT2_CLSTYPE_UNRESOLVED,	
	IPCT2_CLSTYPE_UNKNOWN,
	IPCT2_CLSTYPE_ROOT,
	IPCT2_CLSTYPE_DRIVE,
	IPCT2_CLSTYPE_FOLDER,
	IPCT2_CLSTYPE_ITEM,
	IPCT2_CLSTYPE_CUSTOM = 0x8000,			// For private implementation usage
};

enum IPCT2_SUBTYPE_DRIVE {					// Common drive type
	IPCT2_SUBTYPE_DRIVE_UNRESOLVED,
	IPCT2_SUBTYPE_DRIVE_UNKNOWN,
	IPCT2_SUBTYPE_DRIVE_HARDDISK,
	IPCT2_SUBTYPE_DRIVE_FLOPPY,
	IPCT2_SUBTYPE_DRIVE_CD,
	IPCT2_SUBTYPE_DRIVE_CDR,
	IPCT2_SUBTYPE_DRIVE_CDRW,
	IPCT2_SUBTYPE_DRIVE_DVD,
	IPCT2_SUBTYPE_DRIVE_RAM,
	IPCT2_SUBTYPE_DRIVE_REMOVABLE,
	IPCT2_SUBTYPE_DRIVE_ZIP,
	IPCT2_SUBTYPE_DRIVE_CUSTOM = 0x8000,
};

enum IPCT2_SUBTYPE_FOLDER {					// Common folder type
	IPCT2_SUBTYPE_FOLDER_UNRESOLVED,
	IPCT2_SUBTYPE_FOLDER_UNKNOWN,
	IPCT2_SUBTYPE_FOLDER_VIRTUAL,
	IPCT2_SUBTYPE_FOLDER_FILE,
	IPCT2_SUBTYPE_FOLDER_CUSTOM = 0x8000,
};

enum IPCT2_SUBTYPE_ITEM {					// Common item type
	IPCT2_SUBTYPE_ITEM_UNRESOLVED,
	IPCT2_SUBTYPE_ITEM_UNKNOWN,
	IPCT2_SUBTYPE_ITEM_VIRTUAL,
	IPCT2_SUBTYPE_ITEM_FILE,
	IPCT2_SUBTYPE_ITEM_CUSTOM = 0x8000,
};

enum F_IPCT2_ATTR {							// IO attributes (file system basic)
	F_IPCT2_ATTR_HIDEN,						// This pct is not suposed to be displayed
	F_IPCT2_ATTR_PICON,						// This item might support a picon (Thru the IPP2 interface)
	F_IPCT2_ATTR_OFFLINE,					// IO operation are not available at this time
	F_IPCT2_ATTR_CONTAINER,					// This pct may contain childs
	F_IPCT2_ATTR_LINK,						// This pct is a reference to another item (Share the same instance of IPRIO)
	F_IPCT2_ATTR_READONLY,
	F_IPCT2_ATTR_ARCHIVE,
};
enum IPCT2_ATTR {
	IPCT2_ATTR_HIDEN		= BIT(F_IPCT2_ATTR_HIDEN),		
	IPCT2_ATTR_PICON		= BIT(F_IPCT2_ATTR_PICON),		
	IPCT2_ATTR_OFFLINE		= BIT(F_IPCT2_ATTR_OFFLINE),	
	IPCT2_ATTR_CONTAINER	= BIT(F_IPCT2_ATTR_CONTAINER),	
	IPCT2_ATTR_LINK			= BIT(F_IPCT2_ATTR_LINK),		
	IPCT2_ATTR_READONLY		= BIT(F_IPCT2_ATTR_READONLY),
	IPCT2_ATTR_ARCHIVE		= BIT(F_IPCT2_ATTR_ARCHIVE),
};

enum F_IPCT2_CAP {							// Supported Capabilities 
	F_IPCT2_CAP_OPEN,						// Open() Supported
	F_IPCT2_CAP_CREATE,						// Create() Supported
	F_IPCT2_CAP_ENUM,						// Child() Supported
	F_IPCT2_CAP_REMOVE,						// Remove() Supported
	F_IPCT2_CAP_RENAME,						// SetDisplayName() Supported
};
enum IPCT2_CAP {
	IPCT2_CAP_OPEN		= BIT(F_IPCT2_CAP_OPEN),		
	IPCT2_CAP_CREATE	= BIT(F_IPCT2_CAP_CREATE),	
	IPCT2_CAP_ENUM		= BIT(F_IPCT2_CAP_ENUM),		
	IPCT2_CAP_REMOVE	= BIT(F_IPCT2_CAP_REMOVE),	
	IPCT2_CAP_RENAME	= BIT(F_IPCT2_CAP_RENAME),	
};

enum F_IPCT2_INFO_FIELD {
	F_IPCT2_INFO_FIELD_DISPLAYNAME,			// Display name requested
	F_IPCT2_INFO_FIELD_TIME,				// Creation & modifyed time 
	F_IPCT2_INFO_FIELD_SIZE,				// byte size of item
	F_IPCT2_INFO_FIELD_ATTR,				// See: F_IPCT2_ATTR
	F_IPCT2_INFO_FIELD_PCTSTRING,			// Persisting name for this object
	F_IPCT2_INFO_FIELD_TYPE,				// Main & Sub type describtion
	F_IPCT2_INFO_FIELD_CAP,					// See: F_IPCT2_CAP
	F_IPCT2_INFO_FIELD_VIEWER,				// Return a CLASS and/or IUnknown interface for the prefered viewer
	F_IPCT2_INFO_FIELD_FREESPACE,			// 
	F_IPCT2_INFO_FIELD_TYPENAME,
};
enum IPCT2_INFO_FIELD {
	IPCT2_INFO_FIELD_DISPLAYNAME	= BIT(F_IPCT2_INFO_FIELD_DISPLAYNAME),
	IPCT2_INFO_FIELD_TIME			= BIT(F_IPCT2_INFO_FIELD_TIME),	
	IPCT2_INFO_FIELD_SIZE			= BIT(F_IPCT2_INFO_FIELD_SIZE),	
	IPCT2_INFO_FIELD_ATTR			= BIT(F_IPCT2_INFO_FIELD_ATTR),
	IPCT2_INFO_FIELD_PCTSTRING		= BIT(F_IPCT2_INFO_FIELD_PCTSTRING),
	IPCT2_INFO_FIELD_TYPE			= BIT(F_IPCT2_INFO_FIELD_TYPE),
	IPCT2_INFO_FIELD_CAP			= BIT(F_IPCT2_INFO_FIELD_CAP),	
	IPCT2_INFO_FIELD_VIEWER			= BIT(F_IPCT2_INFO_FIELD_VIEWER),	
	IPCT2_INFO_FIELD_FREESPACE		= BIT(F_IPCT2_INFO_FIELD_FREESPACE),
	IPCT2_INFO_FIELD_TYPENAME		= BIT(F_IPCT2_INFO_FIELD_TYPENAME),
};

enum F_IPCT2_CREATE {
	F_IPCT2_CREATE_FILE,					// This PCT will have a PIO associated
	F_IPCT2_CREATE_FOLDER,					// This PCT will have childreen PCT associated
};
enum IPCT2_CREATE {
	IPCT2_CREATE_FILE		= BIT(F_IPCT2_CREATE_FILE),
	IPCT2_CREATE_FOLDER		= BIT(F_IPCT2_CREATE_FOLDER),
};

typedef struct {
	long	field;							// see: IPCT2_INFO_FIELD
	long	cap;							// See: F_IPCT2_CAP
	char*	displayname;					// If null, a pointer is provided that is only valid for the lifetime of the pct.
	long	dnlenght;
	long	attr;							// See: F_IPCT2_ATTR
	struct {								// The prefered viewer for this object, also used as default for child pct with no preference of their own
		GUID		clsid;
		IUnknown*	iunk;
	} viewer;								// See: F_IPCT2_INFO_FIELD_VIEWER
	char**	pctstring;						// Persisting name for this object
	short	clstype, subtype;				// See: F_IPCT2_CLSTYPE, F_IPCT2_SUBTYPE_*
	__int64	createtime, modifytime;			// see: F_IPCT2_INFO_FIELD_TIME
	__int64	size;							// byte size of item
	__int64	freespace;
} IPCT2_INFO;

struct IPCTN2_NOTIFY  {						// PCT notification
	virtual HRESULT __stdcall Unknown(IPCT2* pct) {return 0;};							// This PCT as somehow changed, anything could have happened
	virtual HRESULT __stdcall Create(IPCT2* pct, long* references, long count) {return 0;};	// Those PCT have been added
	virtual	HRESULT __stdcall Delete(IPCT2* pct, long* references, long count) {return 0;};	// Those PCT have been removed
	virtual HRESULT __stdcall State(IPCT2* pct, long* references, long count) {return 0;};	// This PCT state as changed
};

enum HR_IPCT2 {
	HR_IPCT2_WARNING = 0x00000000,
	HR_IPCT2_ERROR = 0x80000000,
	HR_IPCT2_ERROR_OUT_OF_ITEM,				// In response to Child() or Parent() enumeration
	HR_IPCT2_ERROR_ITEM_DONT_EXIST,			// In response to Open()
	HR_IPCT2_ERROR_NO_PARENT,				// In response to Parent()
	HR_IPCT2_ERROR_ON_ROOT,					// In response to Parent()
};

struct IPCT2 : public IUnknown {
	// Basic operations
	virtual HRESULT __stdcall Open(IPCT2** pct, const char* displayname)=0;
	virtual HRESULT __stdcall Create(IPCT2** pct, char* displayname, long flag)=0;
	virtual HRESULT __stdcall Info(IPCT2_INFO* info)=0;
	// References based operations
	virtual HRESULT __stdcall Open(IPCT2** pct, long reference)=0;
	virtual HRESULT __stdcall Child(long* reference, long index, long* count)=0;
	virtual HRESULT __stdcall Parent(long* reference, long index, long* count)=0;
	virtual HRESULT __stdcall Unreference(long reference)=0;
	virtual HRESULT __stdcall Remove(long reference, POS2_USERPROMPT*)=0;
	virtual HRESULT __stdcall SetDisplayName(long reference, char* name)=0;
	virtual HRESULT __stdcall GetDisplayName(long reference, char* name)=0;
	virtual HRESULT __stdcall ChildInfo(long reference, IPCT2_INFO*)=0;
	virtual HRESULT __stdcall OpenTarget(IPCT2** pct, long reference)=0;
};

struct IPCTN2 : public IUnknown {
	virtual HRESULT __stdcall SetNotify(IPCTN2_NOTIFY* notify)=0;
	virtual HRESULT __stdcall Execute()=0;
};

struct IPCTM2 : public IUnknown {
	virtual HRESULT __stdcall CreateInstance(IPCT2** pct, char* pctstring)=0;
	virtual HRESULT __stdcall Register(GUID clsid, char* displayname)=0;
	virtual HRESULT __stdcall UnRegister(GUID clsid)=0;
	virtual HRESULT __stdcall DisplayName(char** displayname, short	clstype, short subtype)=0;
};

#endif
