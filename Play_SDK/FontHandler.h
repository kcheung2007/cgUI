/************************************************************************
*
*	Copyright (c) Play Incorporated, 1998 - Play Confidential
*
*	File:		FontHandler.h
*	Contents:	Declaration of the CPlayFontWindowHandler Class.
*
*	Date :		Oct. 20, 1998
*	Programmer:	Hitesh K. Patel
*
*	Modifications :		Oct. 20, 1998		Created			H. Patel
*************************************************************************/

#ifndef __FontHandler_H__
#define __FontHandler_H__

#include <windows.h>
#include "combase.h"
#include "PlayUI1.h"
#include "playclsid.h"

// Button's IDs
#define NORMAL_BUTTON		0x001
#define BOLD_BUTTON			0x004
#define ITALIC_BUTTON		0x002
#define UNDERLINE_BUTTON	0x008
#define SIZE_LIST			0x010
#define FONT_LIST			0x020

//----------------------------------------------------------------------------------------------
// Declaration for Font Window Handler
//----------------------------------------------------------------------------------------------

class CPlayFontWindowHandler : public IPlayFontWindowHandler
{
public:
	CPlayFontWindowHandler() {m_cRef = 1;} ;
	virtual ~CPlayFontWindowHandler() {} ;

	HRESULT STDMETHODCALLTYPE QueryInterface( REFIID iid, void **ppv )
	{
		HRESULT hr;

		if ( IsEqualGUID( iid, IID_IUnknown ) || IsEqualGUID( iid, IID_IPlayFontWindowHandler ) )
		{
			*ppv = (IPlayFontWindowHandler *)this;
			AddRef();
			hr = S_OK;
		}
		else
		{
			*ppv = NULL;
			hr = E_NOINTERFACE;
		}

		return( hr );
	};

    long m_cRef;

    virtual ULONG STDMETHODCALLTYPE AddRef()
	{
		return(InterlockedIncrement(&m_cRef));
	};

	virtual ULONG STDMETHODCALLTYPE Release()  
	{
		int c = InterlockedDecrement( &m_cRef );
		if ( !c )
			delete this;
	
		return(c);
	};

	// Pure Virtual Functions
	virtual HRESULT __stdcall OnClose () { return (E_NOTIMPL); };
	virtual HRESULT __stdcall OnFontChange (LPSTR pszName, int *pSize, DWORD *pdwStyle)
	{ 
		return (E_NOTIMPL);
	};

};

//----------------------------------------------------------------------------------------------
#endif // __FontHandler_H__