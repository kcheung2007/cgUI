/***
*
*  PlayUI
*  Copyright (C) Play Incorporated, 1995 - confidential
*
*  PRELIMINARY - ALL SPECIFICATIONS SUBJECT TO CHANGE
*
*  File:       PlayUIhlp.h
*
*  Contents:   misc. macros for use by IPlayUIXXX object clients
*
*  History:    Nov 15, 1995  tpabon created
*			   Mar 21, 1996  tpabon added pure virtual "handler" classes
*              Jul  3, 1997  tpabon added OleSaveFile OleLoadFile
*
******************************************************************************/

#ifndef _PlayUIhlp_h
#define _PlayUIhlp_h

#include <ole2.h>
#include <PlayUI1.h>
#include <Play_sdk\playclsid.h>

#define BINOP_PROPERTIES		0x0001
#define BINOP_RENAME			0x0002
#define BINOP_DELETE			0x0004
#define BINOP_NEWFOLDER			0x0008
#define BINOP_UNDO				0x0010
#define BINOP_REDO				0x0020
#define BINOP_KBSC				0x0040
#define BINOP_SHORTCUTARROW		0x0080
#define BINOP_PICON_SIZE		0x0100
#define BINOP_SAVE_LAYOUT		0x0200
#define BINOP_DISP_HIDDEN_NAMES	0x0400
#define BINOP_DISP_NAMES		0x0800


#ifdef __cplusplus


class CPlayUIBinHandler : public IPlayUIBinHandler
{
public:
    CPlayUIBinHandler() {m_cRef = 1;} ;
    ~CPlayUIBinHandler() {} ;

    HRESULT STDMETHODCALLTYPE QueryInterface( REFIID iid, void **ppv )
        {
            HRESULT hr;

            if ( IsEqualGUID( iid, IID_IUnknown ) ||
                 IsEqualGUID( iid, IID_IPlayUIBinHandler )    )
            {
                *ppv = (IPlayUIBinHandler *)this;
                AddRef();
                hr = S_OK;
            } else
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

    STDMETHOD(OnSelect)(
        IPlayUIBinItem* pItem)
		{return E_NOTIMPL;};

    STDMETHOD(OnLBtnDblClk)(
        IPlayUIBinItem* pItem)
		{return E_NOTIMPL;};

    virtual HRESULT __stdcall OnItemProperties( 
        IPlayUIBinItem __RPC_FAR *pBinItem,
        LPCSTR pFilename)
		{return E_NOTIMPL;};

    virtual HRESULT STDMETHODCALLTYPE OnItemRename( 
        IPlayUIBinItem __RPC_FAR *pBinItem,
        LPSTR pstrOldName,
        LPSTR pstrNewName)
		{return E_NOTIMPL;};
    
    virtual HRESULT STDMETHODCALLTYPE OnItemDelete( 
        IPlayUIBinItem __RPC_FAR *pBinItem)
		{return E_NOTIMPL;};
    
    virtual HRESULT STDMETHODCALLTYPE OnItemMove( 
        IPlayUIBinItem __RPC_FAR *pBinItem,
        LPSTR pstrOldName,
        LPSTR pstrNewName)
		{return E_NOTIMPL;};
    
    virtual HRESULT STDMETHODCALLTYPE OnItemCopy( 
        IPlayUIBinItem __RPC_FAR *pBinItem,
        LPSTR pstrNewName)
		{return E_NOTIMPL;};

    virtual HRESULT STDMETHODCALLTYPE OnLoad( 
        LPCSTR pstrLoadingBin,
        ITEMIDLIST __RPC_FAR *pIDL,
        ULONG ulAttr)
		{return E_NOTIMPL;};

    virtual HRESULT STDMETHODCALLTYPE OnClose( void)
		{return E_NOTIMPL;};
};


class CPlayUI1ManagerHandler : public IPlayUI1ManagerHandler
{
public:
    CPlayUI1ManagerHandler() {m_cRef = 1;} ;
    ~CPlayUI1ManagerHandler() {} ;

    HRESULT STDMETHODCALLTYPE QueryInterface( REFIID iid, void **ppv )
        {
            HRESULT hr;

            if ( IsEqualGUID( iid, IID_IUnknown ) )
            {
                *ppv = (IUnknown *)this;
                AddRef();
                hr = S_OK;
            } else
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

    virtual HRESULT STDMETHODCALLTYPE OnTLPreLoad( 
        IPlayTimeLine __RPC_FAR *pTimeLine,
        IStorage __RPC_FAR *pStg)
		{return E_NOTIMPL;};
    
    virtual HRESULT STDMETHODCALLTYPE OnTLPostLoad( 
        IPlayTimeLine __RPC_FAR *pTimeLine,
        IStorage __RPC_FAR *pStg)
		{return E_NOTIMPL;};
    
    virtual HRESULT STDMETHODCALLTYPE OnTLPreViewRemoval( 
        IPlayTimeLine __RPC_FAR *pTimeLine)
		{return E_NOTIMPL;};
    
    virtual HRESULT STDMETHODCALLTYPE OnTLPostViewRemoval( 
        IPlayTimeLine __RPC_FAR *pTimeLine)
		{return E_NOTIMPL;};
    
    virtual HRESULT STDMETHODCALLTYPE OnTLPreSave( 
        IPlayTimeLine __RPC_FAR *pTimeLine,
        IStorage __RPC_FAR *pStg)
		{return E_NOTIMPL;};
    
    virtual HRESULT STDMETHODCALLTYPE OnTLPostSave( 
        IPlayTimeLine __RPC_FAR *pTimeLine,
        IStorage __RPC_FAR *pStg)
		{return E_NOTIMPL;};

    virtual HRESULT STDMETHODCALLTYPE OnAppActivate( 
        BOOL bActive)
		{return E_NOTIMPL;};

    virtual HRESULT STDMETHODCALLTYPE OnLoadLayout( 
        IStorage __RPC_FAR *pStg)
		{return E_NOTIMPL;};
};


#endif

#endif // _PlayUIhlp_h
