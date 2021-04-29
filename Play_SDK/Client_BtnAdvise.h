/*===========================================================================

    Copyright (c) 1995, 1997 by Play Incorporated                                      
	PLAY CONFIDENTIAL                                                        
    All Specifications subject to change.                                    
	                                                                          
	FILE:           Client_BtnAdvise.h

	MODIFICATIONS:  Nov 14, 1995	tpabon 		created
					01/27/97		R. Hooper	modified filenames for use with
												version C.0.25 ClientShell.exe
												sample program, and provided
												quit button functionality.

============================================================================= */
#ifndef _CLIENT_BTNADVISE_H
#define _CLIENT_BTNADVISE_H

#include "uiclib.h"


class CBtnShellAdvise : public CPCtrlAdviseSink {
public:
    CBtnShellAdvise() {m_count = 1;};
    ~CBtnShellAdvise() {};
    HRESULT STDMETHODCALLTYPE QueryInterface( REFIID iid, void **ppv )
        {
            HRESULT hr;

            if ( IsEqualGUID( iid, IID_IUnknown ) ) {
                *ppv = (IUnknown *)this;
                AddRef();
                hr = S_OK;
			}
			else if (IsEqualGUID( iid, IID_IPCtrlAdviseSink )) {
                *ppv = (IPCtrlAdviseSink *)this;
                AddRef();
                hr = S_OK;
            }
			else {
                *ppv = NULL;
                hr = E_NOINTERFACE;
            }

            return( hr );
        };
    
	ULONG STDMETHODCALLTYPE AddRef()
		{return(++m_count);};

    ULONG STDMETHODCALLTYPE Release()
		{
			if (--m_count)
				return m_count;
			else {
				delete this;
				return 0;
			}
		};

	enum Action {
		Close
	};

	void SetAction (Action action) {m_action = action;};
	void SetWindow (HWND hwnd) {m_hwnd = hwnd;};

private:
	int m_count;
    HRESULT __stdcall OnCtlUp( IPlayControl *pPlayCtl );

	Action	m_action;
	HWND	m_hwnd;
};


#endif



