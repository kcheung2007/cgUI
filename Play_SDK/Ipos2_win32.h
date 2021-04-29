//=============================================================================
// IPOS2_Win32.h
// Copyright 1999 Play Incorporated
//
// Created 1999 by Stephan Schaem
//=============================================================================
#ifndef	IPOS2_WIN32_H
#define	IPOS2_WIN32_H

#include <windows.h>
#include <shlobj.h>
#include <ipgl2.h>

// -- IPDS2_WIN32 --------------------------------------------------------------------
extern "C" const GUID IID_IPDS2_WIN32;

struct IPDS2_WIN32 : public IUnknown {
	virtual HRESULT __stdcall Initialize(HANDLE hwnd, long, PGLRECT *, long, long, long)=0;
	virtual HRESULT __stdcall SetPalette(char *palette)=0;

	virtual HRESULT __stdcall WindowMoved(void)=0;
	virtual HRESULT __stdcall WindowSized(void)=0;
	virtual HRESULT __stdcall VideoModeChanged()=0;
};

// -- IPOS2_WIN32 -------------------------------------------------------------

enum F_IPOS2_WIN32_SETUP {
	F_IPOS2_WIN32_SETUP_INSTANCE,
	F_IPOS2_WIN32_SETUP_CMDLINE,
};

typedef struct {
	long	field;					// See: F_IPOS2_WIN32_INFO
	HANDLE	instance;
	char*	cmdline;
} IPOS2_WIN32_SETUP;

struct IPOS2_WIN32 : public IUnknown {
	virtual HRESULT __stdcall Setup(IPOS2_WIN32_SETUP* setup)=0;	
};


// -- IPCT2_WIN32 -------------------------------------------------------------
extern "C" const GUID IID_IPCT2_WIN32;

struct IPCT2_WIN32 : public IUnknown {
	virtual HRESULT __stdcall GetUNCPath(char* path)=0;
	virtual HRESULT __stdcall GetLNKPath(char* path)=0;
	virtual HRESULT __stdcall GetITEMIDLIST(LPITEMIDLIST itemidlist)=0;
};


// --- IPlayInputManager_Win32 ------------------------------------------------
extern "C" const GUID	CLSID_PlayInputManager_Win32;
extern "C" const GUID	IID_IPlayInputManager_Win32;

extern IUnknown* STDMETHODCALLTYPE g_CLSID_PlayInputManager_Win32 (VOID);

// Forward delcarations for required interfaces
interface IPlayKeyboard;
interface IPlayMouse;

interface IPlayInputManager_Win32 : public IUnknown
{
	virtual HRESULT STDMETHODCALLTYPE GetKeyboard (
		IN	HWND				hWnd,			// WIN32 Window handle
		IN	BOOL				MultiThreaded,	// If FALSE, Client responsible for event-generation
		OUT	IPlayKeyboard**		ppKeyboard) = 0;

	virtual HRESULT STDMETHODCALLTYPE GetMouse (
		IN	HWND				hWnd,			// WIN32 Window handle
		IN	BOOL				MultiThreaded,	// If FALSE, Client responsible for event-generation
		OUT	IPlayMouse**		ppMouse) = 0;
};

#endif