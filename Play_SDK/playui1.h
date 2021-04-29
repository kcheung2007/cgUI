/* this ALWAYS GENERATED file contains the definitions for the interfaces */


/* File created by MIDL compiler version 3.01.75 */
/* at Tue Nov 23 05:02:14 1999
 */
/* Compiler settings for playui1.idl:
    Oi (OptLev=i0), W1, Zp8, env=Win32, ms_ext, c_ext
    error checks: none
*/
//@@MIDL_FILE_HEADING(  )
#include "rpc.h"
#include "rpcndr.h"
#ifndef COM_NO_WINDOWS_H
#include "windows.h"
#include "ole2.h"
#endif /*COM_NO_WINDOWS_H*/

#ifndef __playui1_h__
#define __playui1_h__

#ifdef __cplusplus
extern "C"{
#endif 

/* Forward Declarations */ 

#ifndef __IPlayUI1Window_FWD_DEFINED__
#define __IPlayUI1Window_FWD_DEFINED__
typedef interface IPlayUI1Window IPlayUI1Window;
#endif 	/* __IPlayUI1Window_FWD_DEFINED__ */


#ifndef __IPlayUI1WindowHandler_FWD_DEFINED__
#define __IPlayUI1WindowHandler_FWD_DEFINED__
typedef interface IPlayUI1WindowHandler IPlayUI1WindowHandler;
#endif 	/* __IPlayUI1WindowHandler_FWD_DEFINED__ */


#ifndef __IPlayUIBinItem_FWD_DEFINED__
#define __IPlayUIBinItem_FWD_DEFINED__
typedef interface IPlayUIBinItem IPlayUIBinItem;
#endif 	/* __IPlayUIBinItem_FWD_DEFINED__ */


#ifndef __IPlayUIBinWindow_FWD_DEFINED__
#define __IPlayUIBinWindow_FWD_DEFINED__
typedef interface IPlayUIBinWindow IPlayUIBinWindow;
#endif 	/* __IPlayUIBinWindow_FWD_DEFINED__ */


#ifndef __IPlayUIBinWindow2_FWD_DEFINED__
#define __IPlayUIBinWindow2_FWD_DEFINED__
typedef interface IPlayUIBinWindow2 IPlayUIBinWindow2;
#endif 	/* __IPlayUIBinWindow2_FWD_DEFINED__ */


#ifndef __IPlayUIBinHandler_FWD_DEFINED__
#define __IPlayUIBinHandler_FWD_DEFINED__
typedef interface IPlayUIBinHandler IPlayUIBinHandler;
#endif 	/* __IPlayUIBinHandler_FWD_DEFINED__ */


#ifndef __IPlayUI1Manager_FWD_DEFINED__
#define __IPlayUI1Manager_FWD_DEFINED__
typedef interface IPlayUI1Manager IPlayUI1Manager;
#endif 	/* __IPlayUI1Manager_FWD_DEFINED__ */


#ifndef __IPlayUI1Manager2_FWD_DEFINED__
#define __IPlayUI1Manager2_FWD_DEFINED__
typedef interface IPlayUI1Manager2 IPlayUI1Manager2;
#endif 	/* __IPlayUI1Manager2_FWD_DEFINED__ */


#ifndef __IPlayUI1ManagerHandler_FWD_DEFINED__
#define __IPlayUI1ManagerHandler_FWD_DEFINED__
typedef interface IPlayUI1ManagerHandler IPlayUI1ManagerHandler;
#endif 	/* __IPlayUI1ManagerHandler_FWD_DEFINED__ */


#ifndef __IPlayUI1ManagerHandler2_FWD_DEFINED__
#define __IPlayUI1ManagerHandler2_FWD_DEFINED__
typedef interface IPlayUI1ManagerHandler2 IPlayUI1ManagerHandler2;
#endif 	/* __IPlayUI1ManagerHandler2_FWD_DEFINED__ */


#ifndef __IPlayUI1ColorWindow_FWD_DEFINED__
#define __IPlayUI1ColorWindow_FWD_DEFINED__
typedef interface IPlayUI1ColorWindow IPlayUI1ColorWindow;
#endif 	/* __IPlayUI1ColorWindow_FWD_DEFINED__ */


#ifndef __IPlayUI1ColorWndHandler_FWD_DEFINED__
#define __IPlayUI1ColorWndHandler_FWD_DEFINED__
typedef interface IPlayUI1ColorWndHandler IPlayUI1ColorWndHandler;
#endif 	/* __IPlayUI1ColorWndHandler_FWD_DEFINED__ */


#ifndef __IPlayFontWindow_FWD_DEFINED__
#define __IPlayFontWindow_FWD_DEFINED__
typedef interface IPlayFontWindow IPlayFontWindow;
#endif 	/* __IPlayFontWindow_FWD_DEFINED__ */


#ifndef __IPlayFontWindowHandler_FWD_DEFINED__
#define __IPlayFontWindowHandler_FWD_DEFINED__
typedef interface IPlayFontWindowHandler IPlayFontWindowHandler;
#endif 	/* __IPlayFontWindowHandler_FWD_DEFINED__ */


/* header files for imported files */
#include "oleidl.h"
#include "color.h"

void __RPC_FAR * __RPC_USER MIDL_user_allocate(size_t);
void __RPC_USER MIDL_user_free( void __RPC_FAR * ); 

/****************************************
 * Generated header for interface: __MIDL_itf_playui1_0000
 * at Tue Nov 23 05:02:14 1999
 * using MIDL 3.01.75
 ****************************************/
/* [local] */ 


interface IPlayProperties;













#include <shlobj.h>
/*
typedef struct  _SHITEMID
    {
    USHORT cb;
    BYTE abID[ 1 ];
    }	SHITEMID;

typedef SHITEMID __RPC_FAR *LPSHITEMID;

typedef const SHITEMID __RPC_FAR *LPCSHITEMID;

typedef struct  _ITEMIDLIST
    {
    SHITEMID mkid;
    }	ITEMIDLIST;

typedef ITEMIDLIST __RPC_FAR *LPITEMIDLIST;

typedef const ITEMIDLIST __RPC_FAR *LPCITEMIDLIST;

*/
typedef struct  _PlayUI_LayoutWnd
    {
    int maxWidth;
    int maxHeight;
    int minWidth;
    int minHeight;
    CLSID clsid;
    }	PlayUI_LayoutWnd;

/*
typedef int ( __stdcall __RPC_FAR *FARPROC )( void);

*/


extern RPC_IF_HANDLE __MIDL_itf_playui1_0000_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_playui1_0000_v0_0_s_ifspec;

#ifndef __IPlayUI1Window_INTERFACE_DEFINED__
#define __IPlayUI1Window_INTERFACE_DEFINED__

/****************************************
 * Generated header for interface: IPlayUI1Window
 * at Tue Nov 23 05:02:14 1999
 * using MIDL 3.01.75
 ****************************************/
/* [unique][uuid][object][local] */ 



EXTERN_C const IID IID_IPlayUI1Window;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    interface DECLSPEC_UUID("8335e440-ab3b-11ce-8468-0000b468276b")
    IPlayUI1Window : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE GetHandle( 
            HWND __RPC_FAR *phWnd) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetWndProc( 
            FARPROC pWndProc) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetHandler( 
            IPlayUI1WindowHandler __RPC_FAR *pHandler) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetIPlayProperties( 
            /* [in] */ IPlayProperties __RPC_FAR *pProps) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetIPlayProperties( 
            /* [out] */ IPlayProperties __RPC_FAR *__RPC_FAR *ppProps) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetPropLong( 
            /* [string][in] */ LPSTR pszProperty,
            /* [out] */ LONG __RPC_FAR *plVal) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetPropLong( 
            /* [string][in] */ LPSTR pszProperty,
            /* [in] */ LONG lValue,
            /* [in] */ LONG flags) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetPropString( 
            /* [string][in] */ LPSTR pszProperty,
            /* [string][out] */ LPSTR pszBuffer,
            /* [in] */ ULONG uBufSize) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetPropString( 
            /* [string][in] */ LPSTR pszProperty,
            /* [string][in] */ LPSTR pszValue,
            /* [in] */ LONG flags) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetDropTarget( 
            /* [in] */ IDropTarget __RPC_FAR *pDropTarget) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE DefDragEnter( 
            /* [in][unique] */ IDataObject __RPC_FAR *pDataObj,
            /* [in] */ DWORD grfKeyState,
            /* [in] */ POINTL ptl,
            /* [in][out] */ DWORD __RPC_FAR *pdwEffect) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE DefDragOver( 
            /* [in] */ DWORD grfKeyState,
            /* [in] */ POINTL pt,
            /* [in][out] */ DWORD __RPC_FAR *pdwEffect) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE DefDrop( 
            /* [in][unique] */ IDataObject __RPC_FAR *pDataObj,
            /* [in] */ DWORD grfKeyState,
            /* [in] */ POINTL pt,
            /* [in][out] */ DWORD __RPC_FAR *pdwEffect) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetManager( 
            /* [out] */ IPlayUI1Manager __RPC_FAR *__RPC_FAR *ppManager) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Show( 
            /* [in] */ int show) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Init( 
            HWND hwndParent,
            int x,
            int y,
            int nWidth,
            int nHeight) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IPlayUI1WindowVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            IPlayUI1Window __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            IPlayUI1Window __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            IPlayUI1Window __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetHandle )( 
            IPlayUI1Window __RPC_FAR * This,
            HWND __RPC_FAR *phWnd);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetWndProc )( 
            IPlayUI1Window __RPC_FAR * This,
            FARPROC pWndProc);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetHandler )( 
            IPlayUI1Window __RPC_FAR * This,
            IPlayUI1WindowHandler __RPC_FAR *pHandler);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetIPlayProperties )( 
            IPlayUI1Window __RPC_FAR * This,
            /* [in] */ IPlayProperties __RPC_FAR *pProps);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetIPlayProperties )( 
            IPlayUI1Window __RPC_FAR * This,
            /* [out] */ IPlayProperties __RPC_FAR *__RPC_FAR *ppProps);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetPropLong )( 
            IPlayUI1Window __RPC_FAR * This,
            /* [string][in] */ LPSTR pszProperty,
            /* [out] */ LONG __RPC_FAR *plVal);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetPropLong )( 
            IPlayUI1Window __RPC_FAR * This,
            /* [string][in] */ LPSTR pszProperty,
            /* [in] */ LONG lValue,
            /* [in] */ LONG flags);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetPropString )( 
            IPlayUI1Window __RPC_FAR * This,
            /* [string][in] */ LPSTR pszProperty,
            /* [string][out] */ LPSTR pszBuffer,
            /* [in] */ ULONG uBufSize);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetPropString )( 
            IPlayUI1Window __RPC_FAR * This,
            /* [string][in] */ LPSTR pszProperty,
            /* [string][in] */ LPSTR pszValue,
            /* [in] */ LONG flags);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetDropTarget )( 
            IPlayUI1Window __RPC_FAR * This,
            /* [in] */ IDropTarget __RPC_FAR *pDropTarget);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *DefDragEnter )( 
            IPlayUI1Window __RPC_FAR * This,
            /* [in][unique] */ IDataObject __RPC_FAR *pDataObj,
            /* [in] */ DWORD grfKeyState,
            /* [in] */ POINTL ptl,
            /* [in][out] */ DWORD __RPC_FAR *pdwEffect);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *DefDragOver )( 
            IPlayUI1Window __RPC_FAR * This,
            /* [in] */ DWORD grfKeyState,
            /* [in] */ POINTL pt,
            /* [in][out] */ DWORD __RPC_FAR *pdwEffect);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *DefDrop )( 
            IPlayUI1Window __RPC_FAR * This,
            /* [in][unique] */ IDataObject __RPC_FAR *pDataObj,
            /* [in] */ DWORD grfKeyState,
            /* [in] */ POINTL pt,
            /* [in][out] */ DWORD __RPC_FAR *pdwEffect);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetManager )( 
            IPlayUI1Window __RPC_FAR * This,
            /* [out] */ IPlayUI1Manager __RPC_FAR *__RPC_FAR *ppManager);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Show )( 
            IPlayUI1Window __RPC_FAR * This,
            /* [in] */ int show);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Init )( 
            IPlayUI1Window __RPC_FAR * This,
            HWND hwndParent,
            int x,
            int y,
            int nWidth,
            int nHeight);
        
        END_INTERFACE
    } IPlayUI1WindowVtbl;

    interface IPlayUI1Window
    {
        CONST_VTBL struct IPlayUI1WindowVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IPlayUI1Window_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IPlayUI1Window_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IPlayUI1Window_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IPlayUI1Window_GetHandle(This,phWnd)	\
    (This)->lpVtbl -> GetHandle(This,phWnd)

#define IPlayUI1Window_SetWndProc(This,pWndProc)	\
    (This)->lpVtbl -> SetWndProc(This,pWndProc)

#define IPlayUI1Window_SetHandler(This,pHandler)	\
    (This)->lpVtbl -> SetHandler(This,pHandler)

#define IPlayUI1Window_SetIPlayProperties(This,pProps)	\
    (This)->lpVtbl -> SetIPlayProperties(This,pProps)

#define IPlayUI1Window_GetIPlayProperties(This,ppProps)	\
    (This)->lpVtbl -> GetIPlayProperties(This,ppProps)

#define IPlayUI1Window_GetPropLong(This,pszProperty,plVal)	\
    (This)->lpVtbl -> GetPropLong(This,pszProperty,plVal)

#define IPlayUI1Window_SetPropLong(This,pszProperty,lValue,flags)	\
    (This)->lpVtbl -> SetPropLong(This,pszProperty,lValue,flags)

#define IPlayUI1Window_GetPropString(This,pszProperty,pszBuffer,uBufSize)	\
    (This)->lpVtbl -> GetPropString(This,pszProperty,pszBuffer,uBufSize)

#define IPlayUI1Window_SetPropString(This,pszProperty,pszValue,flags)	\
    (This)->lpVtbl -> SetPropString(This,pszProperty,pszValue,flags)

#define IPlayUI1Window_SetDropTarget(This,pDropTarget)	\
    (This)->lpVtbl -> SetDropTarget(This,pDropTarget)

#define IPlayUI1Window_DefDragEnter(This,pDataObj,grfKeyState,ptl,pdwEffect)	\
    (This)->lpVtbl -> DefDragEnter(This,pDataObj,grfKeyState,ptl,pdwEffect)

#define IPlayUI1Window_DefDragOver(This,grfKeyState,pt,pdwEffect)	\
    (This)->lpVtbl -> DefDragOver(This,grfKeyState,pt,pdwEffect)

#define IPlayUI1Window_DefDrop(This,pDataObj,grfKeyState,pt,pdwEffect)	\
    (This)->lpVtbl -> DefDrop(This,pDataObj,grfKeyState,pt,pdwEffect)

#define IPlayUI1Window_GetManager(This,ppManager)	\
    (This)->lpVtbl -> GetManager(This,ppManager)

#define IPlayUI1Window_Show(This,show)	\
    (This)->lpVtbl -> Show(This,show)

#define IPlayUI1Window_Init(This,hwndParent,x,y,nWidth,nHeight)	\
    (This)->lpVtbl -> Init(This,hwndParent,x,y,nWidth,nHeight)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE IPlayUI1Window_GetHandle_Proxy( 
    IPlayUI1Window __RPC_FAR * This,
    HWND __RPC_FAR *phWnd);


void __RPC_STUB IPlayUI1Window_GetHandle_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IPlayUI1Window_SetWndProc_Proxy( 
    IPlayUI1Window __RPC_FAR * This,
    FARPROC pWndProc);


void __RPC_STUB IPlayUI1Window_SetWndProc_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IPlayUI1Window_SetHandler_Proxy( 
    IPlayUI1Window __RPC_FAR * This,
    IPlayUI1WindowHandler __RPC_FAR *pHandler);


void __RPC_STUB IPlayUI1Window_SetHandler_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IPlayUI1Window_SetIPlayProperties_Proxy( 
    IPlayUI1Window __RPC_FAR * This,
    /* [in] */ IPlayProperties __RPC_FAR *pProps);


void __RPC_STUB IPlayUI1Window_SetIPlayProperties_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IPlayUI1Window_GetIPlayProperties_Proxy( 
    IPlayUI1Window __RPC_FAR * This,
    /* [out] */ IPlayProperties __RPC_FAR *__RPC_FAR *ppProps);


void __RPC_STUB IPlayUI1Window_GetIPlayProperties_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IPlayUI1Window_GetPropLong_Proxy( 
    IPlayUI1Window __RPC_FAR * This,
    /* [string][in] */ LPSTR pszProperty,
    /* [out] */ LONG __RPC_FAR *plVal);


void __RPC_STUB IPlayUI1Window_GetPropLong_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IPlayUI1Window_SetPropLong_Proxy( 
    IPlayUI1Window __RPC_FAR * This,
    /* [string][in] */ LPSTR pszProperty,
    /* [in] */ LONG lValue,
    /* [in] */ LONG flags);


void __RPC_STUB IPlayUI1Window_SetPropLong_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IPlayUI1Window_GetPropString_Proxy( 
    IPlayUI1Window __RPC_FAR * This,
    /* [string][in] */ LPSTR pszProperty,
    /* [string][out] */ LPSTR pszBuffer,
    /* [in] */ ULONG uBufSize);


void __RPC_STUB IPlayUI1Window_GetPropString_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IPlayUI1Window_SetPropString_Proxy( 
    IPlayUI1Window __RPC_FAR * This,
    /* [string][in] */ LPSTR pszProperty,
    /* [string][in] */ LPSTR pszValue,
    /* [in] */ LONG flags);


void __RPC_STUB IPlayUI1Window_SetPropString_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IPlayUI1Window_SetDropTarget_Proxy( 
    IPlayUI1Window __RPC_FAR * This,
    /* [in] */ IDropTarget __RPC_FAR *pDropTarget);


void __RPC_STUB IPlayUI1Window_SetDropTarget_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IPlayUI1Window_DefDragEnter_Proxy( 
    IPlayUI1Window __RPC_FAR * This,
    /* [in][unique] */ IDataObject __RPC_FAR *pDataObj,
    /* [in] */ DWORD grfKeyState,
    /* [in] */ POINTL ptl,
    /* [in][out] */ DWORD __RPC_FAR *pdwEffect);


void __RPC_STUB IPlayUI1Window_DefDragEnter_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IPlayUI1Window_DefDragOver_Proxy( 
    IPlayUI1Window __RPC_FAR * This,
    /* [in] */ DWORD grfKeyState,
    /* [in] */ POINTL pt,
    /* [in][out] */ DWORD __RPC_FAR *pdwEffect);


void __RPC_STUB IPlayUI1Window_DefDragOver_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IPlayUI1Window_DefDrop_Proxy( 
    IPlayUI1Window __RPC_FAR * This,
    /* [in][unique] */ IDataObject __RPC_FAR *pDataObj,
    /* [in] */ DWORD grfKeyState,
    /* [in] */ POINTL pt,
    /* [in][out] */ DWORD __RPC_FAR *pdwEffect);


void __RPC_STUB IPlayUI1Window_DefDrop_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IPlayUI1Window_GetManager_Proxy( 
    IPlayUI1Window __RPC_FAR * This,
    /* [out] */ IPlayUI1Manager __RPC_FAR *__RPC_FAR *ppManager);


void __RPC_STUB IPlayUI1Window_GetManager_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IPlayUI1Window_Show_Proxy( 
    IPlayUI1Window __RPC_FAR * This,
    /* [in] */ int show);


void __RPC_STUB IPlayUI1Window_Show_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IPlayUI1Window_Init_Proxy( 
    IPlayUI1Window __RPC_FAR * This,
    HWND hwndParent,
    int x,
    int y,
    int nWidth,
    int nHeight);


void __RPC_STUB IPlayUI1Window_Init_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IPlayUI1Window_INTERFACE_DEFINED__ */


#ifndef __IPlayUI1WindowHandler_INTERFACE_DEFINED__
#define __IPlayUI1WindowHandler_INTERFACE_DEFINED__

/****************************************
 * Generated header for interface: IPlayUI1WindowHandler
 * at Tue Nov 23 05:02:14 1999
 * using MIDL 3.01.75
 ****************************************/
/* [unique][uuid][object][local] */ 



EXTERN_C const IID IID_IPlayUI1WindowHandler;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    interface DECLSPEC_UUID("8335e44f-ab3b-11ce-8468-0000b468276b")
    IPlayUI1WindowHandler : public IUnknown
    {
    public:
        virtual LRESULT STDMETHODCALLTYPE OnMouseMove( 
            UINT keys,
            POINT pt) = 0;
        
        virtual LRESULT STDMETHODCALLTYPE OnLButtonDown( 
            UINT keys,
            POINT pt) = 0;
        
        virtual LRESULT STDMETHODCALLTYPE OnMButtonDown( 
            UINT keys,
            POINT pt) = 0;
        
        virtual LRESULT STDMETHODCALLTYPE OnRButtonDown( 
            UINT keys,
            POINT pt) = 0;
        
        virtual LRESULT STDMETHODCALLTYPE OnLButtonDblClk( 
            UINT keys,
            POINT pt) = 0;
        
        virtual LRESULT STDMETHODCALLTYPE OnMButtonDblClk( 
            UINT keys,
            POINT pt) = 0;
        
        virtual LRESULT STDMETHODCALLTYPE OnRButtonDblClk( 
            UINT keys,
            POINT pt) = 0;
        
        virtual LRESULT STDMETHODCALLTYPE OnKeyDown( 
            int nVirtKey,
            LONG keyData) = 0;
        
        virtual LRESULT STDMETHODCALLTYPE OnKeyUp( 
            int nVirtKey,
            LONG keyData) = 0;
        
        virtual LRESULT STDMETHODCALLTYPE OnWindowClose( void) = 0;
        
        virtual LRESULT STDMETHODCALLTYPE OnPaint( 
            HDC hdc) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IPlayUI1WindowHandlerVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            IPlayUI1WindowHandler __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            IPlayUI1WindowHandler __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            IPlayUI1WindowHandler __RPC_FAR * This);
        
        LRESULT ( STDMETHODCALLTYPE __RPC_FAR *OnMouseMove )( 
            IPlayUI1WindowHandler __RPC_FAR * This,
            UINT keys,
            POINT pt);
        
        LRESULT ( STDMETHODCALLTYPE __RPC_FAR *OnLButtonDown )( 
            IPlayUI1WindowHandler __RPC_FAR * This,
            UINT keys,
            POINT pt);
        
        LRESULT ( STDMETHODCALLTYPE __RPC_FAR *OnMButtonDown )( 
            IPlayUI1WindowHandler __RPC_FAR * This,
            UINT keys,
            POINT pt);
        
        LRESULT ( STDMETHODCALLTYPE __RPC_FAR *OnRButtonDown )( 
            IPlayUI1WindowHandler __RPC_FAR * This,
            UINT keys,
            POINT pt);
        
        LRESULT ( STDMETHODCALLTYPE __RPC_FAR *OnLButtonDblClk )( 
            IPlayUI1WindowHandler __RPC_FAR * This,
            UINT keys,
            POINT pt);
        
        LRESULT ( STDMETHODCALLTYPE __RPC_FAR *OnMButtonDblClk )( 
            IPlayUI1WindowHandler __RPC_FAR * This,
            UINT keys,
            POINT pt);
        
        LRESULT ( STDMETHODCALLTYPE __RPC_FAR *OnRButtonDblClk )( 
            IPlayUI1WindowHandler __RPC_FAR * This,
            UINT keys,
            POINT pt);
        
        LRESULT ( STDMETHODCALLTYPE __RPC_FAR *OnKeyDown )( 
            IPlayUI1WindowHandler __RPC_FAR * This,
            int nVirtKey,
            LONG keyData);
        
        LRESULT ( STDMETHODCALLTYPE __RPC_FAR *OnKeyUp )( 
            IPlayUI1WindowHandler __RPC_FAR * This,
            int nVirtKey,
            LONG keyData);
        
        LRESULT ( STDMETHODCALLTYPE __RPC_FAR *OnWindowClose )( 
            IPlayUI1WindowHandler __RPC_FAR * This);
        
        LRESULT ( STDMETHODCALLTYPE __RPC_FAR *OnPaint )( 
            IPlayUI1WindowHandler __RPC_FAR * This,
            HDC hdc);
        
        END_INTERFACE
    } IPlayUI1WindowHandlerVtbl;

    interface IPlayUI1WindowHandler
    {
        CONST_VTBL struct IPlayUI1WindowHandlerVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IPlayUI1WindowHandler_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IPlayUI1WindowHandler_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IPlayUI1WindowHandler_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IPlayUI1WindowHandler_OnMouseMove(This,keys,pt)	\
    (This)->lpVtbl -> OnMouseMove(This,keys,pt)

#define IPlayUI1WindowHandler_OnLButtonDown(This,keys,pt)	\
    (This)->lpVtbl -> OnLButtonDown(This,keys,pt)

#define IPlayUI1WindowHandler_OnMButtonDown(This,keys,pt)	\
    (This)->lpVtbl -> OnMButtonDown(This,keys,pt)

#define IPlayUI1WindowHandler_OnRButtonDown(This,keys,pt)	\
    (This)->lpVtbl -> OnRButtonDown(This,keys,pt)

#define IPlayUI1WindowHandler_OnLButtonDblClk(This,keys,pt)	\
    (This)->lpVtbl -> OnLButtonDblClk(This,keys,pt)

#define IPlayUI1WindowHandler_OnMButtonDblClk(This,keys,pt)	\
    (This)->lpVtbl -> OnMButtonDblClk(This,keys,pt)

#define IPlayUI1WindowHandler_OnRButtonDblClk(This,keys,pt)	\
    (This)->lpVtbl -> OnRButtonDblClk(This,keys,pt)

#define IPlayUI1WindowHandler_OnKeyDown(This,nVirtKey,keyData)	\
    (This)->lpVtbl -> OnKeyDown(This,nVirtKey,keyData)

#define IPlayUI1WindowHandler_OnKeyUp(This,nVirtKey,keyData)	\
    (This)->lpVtbl -> OnKeyUp(This,nVirtKey,keyData)

#define IPlayUI1WindowHandler_OnWindowClose(This)	\
    (This)->lpVtbl -> OnWindowClose(This)

#define IPlayUI1WindowHandler_OnPaint(This,hdc)	\
    (This)->lpVtbl -> OnPaint(This,hdc)

#endif /* COBJMACROS */


#endif 	/* C style interface */



LRESULT STDMETHODCALLTYPE IPlayUI1WindowHandler_OnMouseMove_Proxy( 
    IPlayUI1WindowHandler __RPC_FAR * This,
    UINT keys,
    POINT pt);


void __RPC_STUB IPlayUI1WindowHandler_OnMouseMove_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


LRESULT STDMETHODCALLTYPE IPlayUI1WindowHandler_OnLButtonDown_Proxy( 
    IPlayUI1WindowHandler __RPC_FAR * This,
    UINT keys,
    POINT pt);


void __RPC_STUB IPlayUI1WindowHandler_OnLButtonDown_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


LRESULT STDMETHODCALLTYPE IPlayUI1WindowHandler_OnMButtonDown_Proxy( 
    IPlayUI1WindowHandler __RPC_FAR * This,
    UINT keys,
    POINT pt);


void __RPC_STUB IPlayUI1WindowHandler_OnMButtonDown_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


LRESULT STDMETHODCALLTYPE IPlayUI1WindowHandler_OnRButtonDown_Proxy( 
    IPlayUI1WindowHandler __RPC_FAR * This,
    UINT keys,
    POINT pt);


void __RPC_STUB IPlayUI1WindowHandler_OnRButtonDown_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


LRESULT STDMETHODCALLTYPE IPlayUI1WindowHandler_OnLButtonDblClk_Proxy( 
    IPlayUI1WindowHandler __RPC_FAR * This,
    UINT keys,
    POINT pt);


void __RPC_STUB IPlayUI1WindowHandler_OnLButtonDblClk_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


LRESULT STDMETHODCALLTYPE IPlayUI1WindowHandler_OnMButtonDblClk_Proxy( 
    IPlayUI1WindowHandler __RPC_FAR * This,
    UINT keys,
    POINT pt);


void __RPC_STUB IPlayUI1WindowHandler_OnMButtonDblClk_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


LRESULT STDMETHODCALLTYPE IPlayUI1WindowHandler_OnRButtonDblClk_Proxy( 
    IPlayUI1WindowHandler __RPC_FAR * This,
    UINT keys,
    POINT pt);


void __RPC_STUB IPlayUI1WindowHandler_OnRButtonDblClk_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


LRESULT STDMETHODCALLTYPE IPlayUI1WindowHandler_OnKeyDown_Proxy( 
    IPlayUI1WindowHandler __RPC_FAR * This,
    int nVirtKey,
    LONG keyData);


void __RPC_STUB IPlayUI1WindowHandler_OnKeyDown_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


LRESULT STDMETHODCALLTYPE IPlayUI1WindowHandler_OnKeyUp_Proxy( 
    IPlayUI1WindowHandler __RPC_FAR * This,
    int nVirtKey,
    LONG keyData);


void __RPC_STUB IPlayUI1WindowHandler_OnKeyUp_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


LRESULT STDMETHODCALLTYPE IPlayUI1WindowHandler_OnWindowClose_Proxy( 
    IPlayUI1WindowHandler __RPC_FAR * This);


void __RPC_STUB IPlayUI1WindowHandler_OnWindowClose_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


LRESULT STDMETHODCALLTYPE IPlayUI1WindowHandler_OnPaint_Proxy( 
    IPlayUI1WindowHandler __RPC_FAR * This,
    HDC hdc);


void __RPC_STUB IPlayUI1WindowHandler_OnPaint_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IPlayUI1WindowHandler_INTERFACE_DEFINED__ */


#ifndef __IPlayUIBinItem_INTERFACE_DEFINED__
#define __IPlayUIBinItem_INTERFACE_DEFINED__

/****************************************
 * Generated header for interface: IPlayUIBinItem
 * at Tue Nov 23 05:02:14 1999
 * using MIDL 3.01.75
 ****************************************/
/* [unique][uuid][object][local] */ 



EXTERN_C const IID IID_IPlayUIBinItem;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    interface DECLSPEC_UUID("8335e411-ab3b-11ce-8468-0000b468276b")
    IPlayUIBinItem : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE Create( 
            IGXIntBitmap __RPC_FAR *pIBM,
            IStorage __RPC_FAR *pStg) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE CreateFromFile( 
            LPSTR pFilename) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetPicon( 
            IGXIntBitmap __RPC_FAR *pIBM) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetPicon( 
            DWORD highLight,
            IGXIntBitmap __RPC_FAR *__RPC_FAR *ppIBM) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetTitle( 
            LPSTR lpstrLabel) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetTitle( 
            LPSTR pstrLabel) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetFilename( 
            LPSTR lpstrLabel) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetFilename( 
            LPSTR pstrLabel) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetSubject( 
            LPSTR lpstr) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetSubject( 
            LPSTR pstr) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetAuthor( 
            LPSTR lpstr) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetAuthor( 
            LPSTR pstr) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetKeywords( 
            LPSTR lpstr) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetKeywords( 
            LPSTR pstr) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetComments( 
            LPSTR pstr) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetComments( 
            LPSTR pstr) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetItemIDList( 
            ITEMIDLIST __RPC_FAR *__RPC_FAR *ppIDL) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE CreateFromItemIDList( 
            LPCITEMIDLIST pIDL) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE DoDragDrop( 
            /* [string][out] */ LPSTR pstrPath,
            /* [out] */ IPlayUI1Window __RPC_FAR *__RPC_FAR *ppWnd,
            /* [out] */ POINT __RPC_FAR *pPt) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE DoDragDropEffect( 
            /* [string][out] */ LPSTR pstrPath,
            /* [out] */ IPlayUI1Window __RPC_FAR *__RPC_FAR *ppWnd,
            /* [out] */ POINT __RPC_FAR *pPt,
            ULONG uldropAttr) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IPlayUIBinItemVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            IPlayUIBinItem __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            IPlayUIBinItem __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            IPlayUIBinItem __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Create )( 
            IPlayUIBinItem __RPC_FAR * This,
            IGXIntBitmap __RPC_FAR *pIBM,
            IStorage __RPC_FAR *pStg);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *CreateFromFile )( 
            IPlayUIBinItem __RPC_FAR * This,
            LPSTR pFilename);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetPicon )( 
            IPlayUIBinItem __RPC_FAR * This,
            IGXIntBitmap __RPC_FAR *pIBM);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetPicon )( 
            IPlayUIBinItem __RPC_FAR * This,
            DWORD highLight,
            IGXIntBitmap __RPC_FAR *__RPC_FAR *ppIBM);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetTitle )( 
            IPlayUIBinItem __RPC_FAR * This,
            LPSTR lpstrLabel);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTitle )( 
            IPlayUIBinItem __RPC_FAR * This,
            LPSTR pstrLabel);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetFilename )( 
            IPlayUIBinItem __RPC_FAR * This,
            LPSTR lpstrLabel);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetFilename )( 
            IPlayUIBinItem __RPC_FAR * This,
            LPSTR pstrLabel);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetSubject )( 
            IPlayUIBinItem __RPC_FAR * This,
            LPSTR lpstr);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetSubject )( 
            IPlayUIBinItem __RPC_FAR * This,
            LPSTR pstr);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetAuthor )( 
            IPlayUIBinItem __RPC_FAR * This,
            LPSTR lpstr);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetAuthor )( 
            IPlayUIBinItem __RPC_FAR * This,
            LPSTR pstr);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetKeywords )( 
            IPlayUIBinItem __RPC_FAR * This,
            LPSTR lpstr);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetKeywords )( 
            IPlayUIBinItem __RPC_FAR * This,
            LPSTR pstr);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetComments )( 
            IPlayUIBinItem __RPC_FAR * This,
            LPSTR pstr);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetComments )( 
            IPlayUIBinItem __RPC_FAR * This,
            LPSTR pstr);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetItemIDList )( 
            IPlayUIBinItem __RPC_FAR * This,
            ITEMIDLIST __RPC_FAR *__RPC_FAR *ppIDL);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *CreateFromItemIDList )( 
            IPlayUIBinItem __RPC_FAR * This,
            LPCITEMIDLIST pIDL);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *DoDragDrop )( 
            IPlayUIBinItem __RPC_FAR * This,
            /* [string][out] */ LPSTR pstrPath,
            /* [out] */ IPlayUI1Window __RPC_FAR *__RPC_FAR *ppWnd,
            /* [out] */ POINT __RPC_FAR *pPt);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *DoDragDropEffect )( 
            IPlayUIBinItem __RPC_FAR * This,
            /* [string][out] */ LPSTR pstrPath,
            /* [out] */ IPlayUI1Window __RPC_FAR *__RPC_FAR *ppWnd,
            /* [out] */ POINT __RPC_FAR *pPt,
            ULONG uldropAttr);
        
        END_INTERFACE
    } IPlayUIBinItemVtbl;

    interface IPlayUIBinItem
    {
        CONST_VTBL struct IPlayUIBinItemVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IPlayUIBinItem_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IPlayUIBinItem_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IPlayUIBinItem_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IPlayUIBinItem_Create(This,pIBM,pStg)	\
    (This)->lpVtbl -> Create(This,pIBM,pStg)

#define IPlayUIBinItem_CreateFromFile(This,pFilename)	\
    (This)->lpVtbl -> CreateFromFile(This,pFilename)

#define IPlayUIBinItem_SetPicon(This,pIBM)	\
    (This)->lpVtbl -> SetPicon(This,pIBM)

#define IPlayUIBinItem_GetPicon(This,highLight,ppIBM)	\
    (This)->lpVtbl -> GetPicon(This,highLight,ppIBM)

#define IPlayUIBinItem_SetTitle(This,lpstrLabel)	\
    (This)->lpVtbl -> SetTitle(This,lpstrLabel)

#define IPlayUIBinItem_GetTitle(This,pstrLabel)	\
    (This)->lpVtbl -> GetTitle(This,pstrLabel)

#define IPlayUIBinItem_SetFilename(This,lpstrLabel)	\
    (This)->lpVtbl -> SetFilename(This,lpstrLabel)

#define IPlayUIBinItem_GetFilename(This,pstrLabel)	\
    (This)->lpVtbl -> GetFilename(This,pstrLabel)

#define IPlayUIBinItem_SetSubject(This,lpstr)	\
    (This)->lpVtbl -> SetSubject(This,lpstr)

#define IPlayUIBinItem_GetSubject(This,pstr)	\
    (This)->lpVtbl -> GetSubject(This,pstr)

#define IPlayUIBinItem_SetAuthor(This,lpstr)	\
    (This)->lpVtbl -> SetAuthor(This,lpstr)

#define IPlayUIBinItem_GetAuthor(This,pstr)	\
    (This)->lpVtbl -> GetAuthor(This,pstr)

#define IPlayUIBinItem_SetKeywords(This,lpstr)	\
    (This)->lpVtbl -> SetKeywords(This,lpstr)

#define IPlayUIBinItem_GetKeywords(This,pstr)	\
    (This)->lpVtbl -> GetKeywords(This,pstr)

#define IPlayUIBinItem_SetComments(This,pstr)	\
    (This)->lpVtbl -> SetComments(This,pstr)

#define IPlayUIBinItem_GetComments(This,pstr)	\
    (This)->lpVtbl -> GetComments(This,pstr)

#define IPlayUIBinItem_GetItemIDList(This,ppIDL)	\
    (This)->lpVtbl -> GetItemIDList(This,ppIDL)

#define IPlayUIBinItem_CreateFromItemIDList(This,pIDL)	\
    (This)->lpVtbl -> CreateFromItemIDList(This,pIDL)

#define IPlayUIBinItem_DoDragDrop(This,pstrPath,ppWnd,pPt)	\
    (This)->lpVtbl -> DoDragDrop(This,pstrPath,ppWnd,pPt)

#define IPlayUIBinItem_DoDragDropEffect(This,pstrPath,ppWnd,pPt,uldropAttr)	\
    (This)->lpVtbl -> DoDragDropEffect(This,pstrPath,ppWnd,pPt,uldropAttr)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE IPlayUIBinItem_Create_Proxy( 
    IPlayUIBinItem __RPC_FAR * This,
    IGXIntBitmap __RPC_FAR *pIBM,
    IStorage __RPC_FAR *pStg);


void __RPC_STUB IPlayUIBinItem_Create_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IPlayUIBinItem_CreateFromFile_Proxy( 
    IPlayUIBinItem __RPC_FAR * This,
    LPSTR pFilename);


void __RPC_STUB IPlayUIBinItem_CreateFromFile_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IPlayUIBinItem_SetPicon_Proxy( 
    IPlayUIBinItem __RPC_FAR * This,
    IGXIntBitmap __RPC_FAR *pIBM);


void __RPC_STUB IPlayUIBinItem_SetPicon_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IPlayUIBinItem_GetPicon_Proxy( 
    IPlayUIBinItem __RPC_FAR * This,
    DWORD highLight,
    IGXIntBitmap __RPC_FAR *__RPC_FAR *ppIBM);


void __RPC_STUB IPlayUIBinItem_GetPicon_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IPlayUIBinItem_SetTitle_Proxy( 
    IPlayUIBinItem __RPC_FAR * This,
    LPSTR lpstrLabel);


void __RPC_STUB IPlayUIBinItem_SetTitle_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IPlayUIBinItem_GetTitle_Proxy( 
    IPlayUIBinItem __RPC_FAR * This,
    LPSTR pstrLabel);


void __RPC_STUB IPlayUIBinItem_GetTitle_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IPlayUIBinItem_SetFilename_Proxy( 
    IPlayUIBinItem __RPC_FAR * This,
    LPSTR lpstrLabel);


void __RPC_STUB IPlayUIBinItem_SetFilename_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IPlayUIBinItem_GetFilename_Proxy( 
    IPlayUIBinItem __RPC_FAR * This,
    LPSTR pstrLabel);


void __RPC_STUB IPlayUIBinItem_GetFilename_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IPlayUIBinItem_SetSubject_Proxy( 
    IPlayUIBinItem __RPC_FAR * This,
    LPSTR lpstr);


void __RPC_STUB IPlayUIBinItem_SetSubject_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IPlayUIBinItem_GetSubject_Proxy( 
    IPlayUIBinItem __RPC_FAR * This,
    LPSTR pstr);


void __RPC_STUB IPlayUIBinItem_GetSubject_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IPlayUIBinItem_SetAuthor_Proxy( 
    IPlayUIBinItem __RPC_FAR * This,
    LPSTR lpstr);


void __RPC_STUB IPlayUIBinItem_SetAuthor_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IPlayUIBinItem_GetAuthor_Proxy( 
    IPlayUIBinItem __RPC_FAR * This,
    LPSTR pstr);


void __RPC_STUB IPlayUIBinItem_GetAuthor_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IPlayUIBinItem_SetKeywords_Proxy( 
    IPlayUIBinItem __RPC_FAR * This,
    LPSTR lpstr);


void __RPC_STUB IPlayUIBinItem_SetKeywords_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IPlayUIBinItem_GetKeywords_Proxy( 
    IPlayUIBinItem __RPC_FAR * This,
    LPSTR pstr);


void __RPC_STUB IPlayUIBinItem_GetKeywords_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IPlayUIBinItem_SetComments_Proxy( 
    IPlayUIBinItem __RPC_FAR * This,
    LPSTR pstr);


void __RPC_STUB IPlayUIBinItem_SetComments_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IPlayUIBinItem_GetComments_Proxy( 
    IPlayUIBinItem __RPC_FAR * This,
    LPSTR pstr);


void __RPC_STUB IPlayUIBinItem_GetComments_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IPlayUIBinItem_GetItemIDList_Proxy( 
    IPlayUIBinItem __RPC_FAR * This,
    ITEMIDLIST __RPC_FAR *__RPC_FAR *ppIDL);


void __RPC_STUB IPlayUIBinItem_GetItemIDList_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IPlayUIBinItem_CreateFromItemIDList_Proxy( 
    IPlayUIBinItem __RPC_FAR * This,
    LPCITEMIDLIST pIDL);


void __RPC_STUB IPlayUIBinItem_CreateFromItemIDList_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IPlayUIBinItem_DoDragDrop_Proxy( 
    IPlayUIBinItem __RPC_FAR * This,
    /* [string][out] */ LPSTR pstrPath,
    /* [out] */ IPlayUI1Window __RPC_FAR *__RPC_FAR *ppWnd,
    /* [out] */ POINT __RPC_FAR *pPt);


void __RPC_STUB IPlayUIBinItem_DoDragDrop_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IPlayUIBinItem_DoDragDropEffect_Proxy( 
    IPlayUIBinItem __RPC_FAR * This,
    /* [string][out] */ LPSTR pstrPath,
    /* [out] */ IPlayUI1Window __RPC_FAR *__RPC_FAR *ppWnd,
    /* [out] */ POINT __RPC_FAR *pPt,
    ULONG uldropAttr);


void __RPC_STUB IPlayUIBinItem_DoDragDropEffect_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IPlayUIBinItem_INTERFACE_DEFINED__ */


#ifndef __IPlayUIBinWindow_INTERFACE_DEFINED__
#define __IPlayUIBinWindow_INTERFACE_DEFINED__

/****************************************
 * Generated header for interface: IPlayUIBinWindow
 * at Tue Nov 23 05:02:14 1999
 * using MIDL 3.01.75
 ****************************************/
/* [unique][uuid][object][local] */ 



EXTERN_C const IID IID_IPlayUIBinWindow;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    interface DECLSPEC_UUID("8335e412-ab3b-11ce-8468-0000b468276b")
    IPlayUIBinWindow : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE Back( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Parent( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Home( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Load( 
            LPSTR lpstrBin) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetPath( 
            LPSTR pstrBinPath) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Save( 
            LPSTR lpstrFilenme) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetHome( 
            LPSTR lpstrBin) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetHome( 
            LPSTR pstrBin) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE AddItem( 
            IPlayUIBinItem __RPC_FAR *pBinItem) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE RemoveItem( 
            IPlayUIBinItem __RPC_FAR *pBinItem) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SelectItem( 
            IPlayUIBinItem __RPC_FAR *pBinItem) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE EnableItem( 
            IPlayUIBinItem __RPC_FAR *pBinItem,
            BOOL bEnable) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetHandler( 
            IPlayUIBinHandler __RPC_FAR *pHandler) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE LoadFromIDList( 
            ITEMIDLIST __RPC_FAR *pidl) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Forward( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetFilePicon( 
            LPSTR dirString,
            LPSTR filename,
            DWORD highlight,
            IGXIntBitmap __RPC_FAR *__RPC_FAR *ppIBM) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE toggleGUI( 
            int GUI) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetBinWndOptions( 
            ULONG options) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Search( 
            LPSTR searchPath,
            LPSTR filetype,
            LPSTR folderPath) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE BuildSubBins( 
            LPSTR pathString) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IPlayUIBinWindowVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            IPlayUIBinWindow __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            IPlayUIBinWindow __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            IPlayUIBinWindow __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Back )( 
            IPlayUIBinWindow __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Parent )( 
            IPlayUIBinWindow __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Home )( 
            IPlayUIBinWindow __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Load )( 
            IPlayUIBinWindow __RPC_FAR * This,
            LPSTR lpstrBin);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetPath )( 
            IPlayUIBinWindow __RPC_FAR * This,
            LPSTR pstrBinPath);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Save )( 
            IPlayUIBinWindow __RPC_FAR * This,
            LPSTR lpstrFilenme);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetHome )( 
            IPlayUIBinWindow __RPC_FAR * This,
            LPSTR lpstrBin);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetHome )( 
            IPlayUIBinWindow __RPC_FAR * This,
            LPSTR pstrBin);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *AddItem )( 
            IPlayUIBinWindow __RPC_FAR * This,
            IPlayUIBinItem __RPC_FAR *pBinItem);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *RemoveItem )( 
            IPlayUIBinWindow __RPC_FAR * This,
            IPlayUIBinItem __RPC_FAR *pBinItem);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SelectItem )( 
            IPlayUIBinWindow __RPC_FAR * This,
            IPlayUIBinItem __RPC_FAR *pBinItem);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *EnableItem )( 
            IPlayUIBinWindow __RPC_FAR * This,
            IPlayUIBinItem __RPC_FAR *pBinItem,
            BOOL bEnable);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetHandler )( 
            IPlayUIBinWindow __RPC_FAR * This,
            IPlayUIBinHandler __RPC_FAR *pHandler);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *LoadFromIDList )( 
            IPlayUIBinWindow __RPC_FAR * This,
            ITEMIDLIST __RPC_FAR *pidl);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Forward )( 
            IPlayUIBinWindow __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetFilePicon )( 
            IPlayUIBinWindow __RPC_FAR * This,
            LPSTR dirString,
            LPSTR filename,
            DWORD highlight,
            IGXIntBitmap __RPC_FAR *__RPC_FAR *ppIBM);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *toggleGUI )( 
            IPlayUIBinWindow __RPC_FAR * This,
            int GUI);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetBinWndOptions )( 
            IPlayUIBinWindow __RPC_FAR * This,
            ULONG options);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Search )( 
            IPlayUIBinWindow __RPC_FAR * This,
            LPSTR searchPath,
            LPSTR filetype,
            LPSTR folderPath);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *BuildSubBins )( 
            IPlayUIBinWindow __RPC_FAR * This,
            LPSTR pathString);
        
        END_INTERFACE
    } IPlayUIBinWindowVtbl;

    interface IPlayUIBinWindow
    {
        CONST_VTBL struct IPlayUIBinWindowVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IPlayUIBinWindow_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IPlayUIBinWindow_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IPlayUIBinWindow_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IPlayUIBinWindow_Back(This)	\
    (This)->lpVtbl -> Back(This)

#define IPlayUIBinWindow_Parent(This)	\
    (This)->lpVtbl -> Parent(This)

#define IPlayUIBinWindow_Home(This)	\
    (This)->lpVtbl -> Home(This)

#define IPlayUIBinWindow_Load(This,lpstrBin)	\
    (This)->lpVtbl -> Load(This,lpstrBin)

#define IPlayUIBinWindow_GetPath(This,pstrBinPath)	\
    (This)->lpVtbl -> GetPath(This,pstrBinPath)

#define IPlayUIBinWindow_Save(This,lpstrFilenme)	\
    (This)->lpVtbl -> Save(This,lpstrFilenme)

#define IPlayUIBinWindow_SetHome(This,lpstrBin)	\
    (This)->lpVtbl -> SetHome(This,lpstrBin)

#define IPlayUIBinWindow_GetHome(This,pstrBin)	\
    (This)->lpVtbl -> GetHome(This,pstrBin)

#define IPlayUIBinWindow_AddItem(This,pBinItem)	\
    (This)->lpVtbl -> AddItem(This,pBinItem)

#define IPlayUIBinWindow_RemoveItem(This,pBinItem)	\
    (This)->lpVtbl -> RemoveItem(This,pBinItem)

#define IPlayUIBinWindow_SelectItem(This,pBinItem)	\
    (This)->lpVtbl -> SelectItem(This,pBinItem)

#define IPlayUIBinWindow_EnableItem(This,pBinItem,bEnable)	\
    (This)->lpVtbl -> EnableItem(This,pBinItem,bEnable)

#define IPlayUIBinWindow_SetHandler(This,pHandler)	\
    (This)->lpVtbl -> SetHandler(This,pHandler)

#define IPlayUIBinWindow_LoadFromIDList(This,pidl)	\
    (This)->lpVtbl -> LoadFromIDList(This,pidl)

#define IPlayUIBinWindow_Forward(This)	\
    (This)->lpVtbl -> Forward(This)

#define IPlayUIBinWindow_GetFilePicon(This,dirString,filename,highlight,ppIBM)	\
    (This)->lpVtbl -> GetFilePicon(This,dirString,filename,highlight,ppIBM)

#define IPlayUIBinWindow_toggleGUI(This,GUI)	\
    (This)->lpVtbl -> toggleGUI(This,GUI)

#define IPlayUIBinWindow_SetBinWndOptions(This,options)	\
    (This)->lpVtbl -> SetBinWndOptions(This,options)

#define IPlayUIBinWindow_Search(This,searchPath,filetype,folderPath)	\
    (This)->lpVtbl -> Search(This,searchPath,filetype,folderPath)

#define IPlayUIBinWindow_BuildSubBins(This,pathString)	\
    (This)->lpVtbl -> BuildSubBins(This,pathString)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE IPlayUIBinWindow_Back_Proxy( 
    IPlayUIBinWindow __RPC_FAR * This);


void __RPC_STUB IPlayUIBinWindow_Back_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IPlayUIBinWindow_Parent_Proxy( 
    IPlayUIBinWindow __RPC_FAR * This);


void __RPC_STUB IPlayUIBinWindow_Parent_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IPlayUIBinWindow_Home_Proxy( 
    IPlayUIBinWindow __RPC_FAR * This);


void __RPC_STUB IPlayUIBinWindow_Home_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IPlayUIBinWindow_Load_Proxy( 
    IPlayUIBinWindow __RPC_FAR * This,
    LPSTR lpstrBin);


void __RPC_STUB IPlayUIBinWindow_Load_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IPlayUIBinWindow_GetPath_Proxy( 
    IPlayUIBinWindow __RPC_FAR * This,
    LPSTR pstrBinPath);


void __RPC_STUB IPlayUIBinWindow_GetPath_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IPlayUIBinWindow_Save_Proxy( 
    IPlayUIBinWindow __RPC_FAR * This,
    LPSTR lpstrFilenme);


void __RPC_STUB IPlayUIBinWindow_Save_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IPlayUIBinWindow_SetHome_Proxy( 
    IPlayUIBinWindow __RPC_FAR * This,
    LPSTR lpstrBin);


void __RPC_STUB IPlayUIBinWindow_SetHome_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IPlayUIBinWindow_GetHome_Proxy( 
    IPlayUIBinWindow __RPC_FAR * This,
    LPSTR pstrBin);


void __RPC_STUB IPlayUIBinWindow_GetHome_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IPlayUIBinWindow_AddItem_Proxy( 
    IPlayUIBinWindow __RPC_FAR * This,
    IPlayUIBinItem __RPC_FAR *pBinItem);


void __RPC_STUB IPlayUIBinWindow_AddItem_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IPlayUIBinWindow_RemoveItem_Proxy( 
    IPlayUIBinWindow __RPC_FAR * This,
    IPlayUIBinItem __RPC_FAR *pBinItem);


void __RPC_STUB IPlayUIBinWindow_RemoveItem_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IPlayUIBinWindow_SelectItem_Proxy( 
    IPlayUIBinWindow __RPC_FAR * This,
    IPlayUIBinItem __RPC_FAR *pBinItem);


void __RPC_STUB IPlayUIBinWindow_SelectItem_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IPlayUIBinWindow_EnableItem_Proxy( 
    IPlayUIBinWindow __RPC_FAR * This,
    IPlayUIBinItem __RPC_FAR *pBinItem,
    BOOL bEnable);


void __RPC_STUB IPlayUIBinWindow_EnableItem_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IPlayUIBinWindow_SetHandler_Proxy( 
    IPlayUIBinWindow __RPC_FAR * This,
    IPlayUIBinHandler __RPC_FAR *pHandler);


void __RPC_STUB IPlayUIBinWindow_SetHandler_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IPlayUIBinWindow_LoadFromIDList_Proxy( 
    IPlayUIBinWindow __RPC_FAR * This,
    ITEMIDLIST __RPC_FAR *pidl);


void __RPC_STUB IPlayUIBinWindow_LoadFromIDList_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IPlayUIBinWindow_Forward_Proxy( 
    IPlayUIBinWindow __RPC_FAR * This);


void __RPC_STUB IPlayUIBinWindow_Forward_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IPlayUIBinWindow_GetFilePicon_Proxy( 
    IPlayUIBinWindow __RPC_FAR * This,
    LPSTR dirString,
    LPSTR filename,
    DWORD highlight,
    IGXIntBitmap __RPC_FAR *__RPC_FAR *ppIBM);


void __RPC_STUB IPlayUIBinWindow_GetFilePicon_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IPlayUIBinWindow_toggleGUI_Proxy( 
    IPlayUIBinWindow __RPC_FAR * This,
    int GUI);


void __RPC_STUB IPlayUIBinWindow_toggleGUI_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IPlayUIBinWindow_SetBinWndOptions_Proxy( 
    IPlayUIBinWindow __RPC_FAR * This,
    ULONG options);


void __RPC_STUB IPlayUIBinWindow_SetBinWndOptions_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IPlayUIBinWindow_Search_Proxy( 
    IPlayUIBinWindow __RPC_FAR * This,
    LPSTR searchPath,
    LPSTR filetype,
    LPSTR folderPath);


void __RPC_STUB IPlayUIBinWindow_Search_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IPlayUIBinWindow_BuildSubBins_Proxy( 
    IPlayUIBinWindow __RPC_FAR * This,
    LPSTR pathString);


void __RPC_STUB IPlayUIBinWindow_BuildSubBins_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IPlayUIBinWindow_INTERFACE_DEFINED__ */


#ifndef __IPlayUIBinWindow2_INTERFACE_DEFINED__
#define __IPlayUIBinWindow2_INTERFACE_DEFINED__

/****************************************
 * Generated header for interface: IPlayUIBinWindow2
 * at Tue Nov 23 05:02:14 1999
 * using MIDL 3.01.75
 ****************************************/
/* [unique][uuid][object][local] */ 



EXTERN_C const IID IID_IPlayUIBinWindow2;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    interface DECLSPEC_UUID("8335e7e6-ab3b-11ce-8468-0000b468276b")
    IPlayUIBinWindow2 : public IPlayUIBinWindow
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE InitPBE( 
            /* [in] */ unsigned char __RPC_FAR *startpath) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE LoadItem( 
            /* [in] */ unsigned long nItem) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetItemCount( 
            /* [out] */ unsigned long __RPC_FAR *nItem) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetIDRange( 
            /* [in] */ unsigned long nStart,
            /* [in] */ unsigned long nStop) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IPlayUIBinWindow2Vtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            IPlayUIBinWindow2 __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            IPlayUIBinWindow2 __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            IPlayUIBinWindow2 __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Back )( 
            IPlayUIBinWindow2 __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Parent )( 
            IPlayUIBinWindow2 __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Home )( 
            IPlayUIBinWindow2 __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Load )( 
            IPlayUIBinWindow2 __RPC_FAR * This,
            LPSTR lpstrBin);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetPath )( 
            IPlayUIBinWindow2 __RPC_FAR * This,
            LPSTR pstrBinPath);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Save )( 
            IPlayUIBinWindow2 __RPC_FAR * This,
            LPSTR lpstrFilenme);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetHome )( 
            IPlayUIBinWindow2 __RPC_FAR * This,
            LPSTR lpstrBin);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetHome )( 
            IPlayUIBinWindow2 __RPC_FAR * This,
            LPSTR pstrBin);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *AddItem )( 
            IPlayUIBinWindow2 __RPC_FAR * This,
            IPlayUIBinItem __RPC_FAR *pBinItem);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *RemoveItem )( 
            IPlayUIBinWindow2 __RPC_FAR * This,
            IPlayUIBinItem __RPC_FAR *pBinItem);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SelectItem )( 
            IPlayUIBinWindow2 __RPC_FAR * This,
            IPlayUIBinItem __RPC_FAR *pBinItem);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *EnableItem )( 
            IPlayUIBinWindow2 __RPC_FAR * This,
            IPlayUIBinItem __RPC_FAR *pBinItem,
            BOOL bEnable);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetHandler )( 
            IPlayUIBinWindow2 __RPC_FAR * This,
            IPlayUIBinHandler __RPC_FAR *pHandler);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *LoadFromIDList )( 
            IPlayUIBinWindow2 __RPC_FAR * This,
            ITEMIDLIST __RPC_FAR *pidl);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Forward )( 
            IPlayUIBinWindow2 __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetFilePicon )( 
            IPlayUIBinWindow2 __RPC_FAR * This,
            LPSTR dirString,
            LPSTR filename,
            DWORD highlight,
            IGXIntBitmap __RPC_FAR *__RPC_FAR *ppIBM);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *toggleGUI )( 
            IPlayUIBinWindow2 __RPC_FAR * This,
            int GUI);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetBinWndOptions )( 
            IPlayUIBinWindow2 __RPC_FAR * This,
            ULONG options);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Search )( 
            IPlayUIBinWindow2 __RPC_FAR * This,
            LPSTR searchPath,
            LPSTR filetype,
            LPSTR folderPath);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *BuildSubBins )( 
            IPlayUIBinWindow2 __RPC_FAR * This,
            LPSTR pathString);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *InitPBE )( 
            IPlayUIBinWindow2 __RPC_FAR * This,
            /* [in] */ unsigned char __RPC_FAR *startpath);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *LoadItem )( 
            IPlayUIBinWindow2 __RPC_FAR * This,
            /* [in] */ unsigned long nItem);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetItemCount )( 
            IPlayUIBinWindow2 __RPC_FAR * This,
            /* [out] */ unsigned long __RPC_FAR *nItem);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetIDRange )( 
            IPlayUIBinWindow2 __RPC_FAR * This,
            /* [in] */ unsigned long nStart,
            /* [in] */ unsigned long nStop);
        
        END_INTERFACE
    } IPlayUIBinWindow2Vtbl;

    interface IPlayUIBinWindow2
    {
        CONST_VTBL struct IPlayUIBinWindow2Vtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IPlayUIBinWindow2_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IPlayUIBinWindow2_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IPlayUIBinWindow2_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IPlayUIBinWindow2_Back(This)	\
    (This)->lpVtbl -> Back(This)

#define IPlayUIBinWindow2_Parent(This)	\
    (This)->lpVtbl -> Parent(This)

#define IPlayUIBinWindow2_Home(This)	\
    (This)->lpVtbl -> Home(This)

#define IPlayUIBinWindow2_Load(This,lpstrBin)	\
    (This)->lpVtbl -> Load(This,lpstrBin)

#define IPlayUIBinWindow2_GetPath(This,pstrBinPath)	\
    (This)->lpVtbl -> GetPath(This,pstrBinPath)

#define IPlayUIBinWindow2_Save(This,lpstrFilenme)	\
    (This)->lpVtbl -> Save(This,lpstrFilenme)

#define IPlayUIBinWindow2_SetHome(This,lpstrBin)	\
    (This)->lpVtbl -> SetHome(This,lpstrBin)

#define IPlayUIBinWindow2_GetHome(This,pstrBin)	\
    (This)->lpVtbl -> GetHome(This,pstrBin)

#define IPlayUIBinWindow2_AddItem(This,pBinItem)	\
    (This)->lpVtbl -> AddItem(This,pBinItem)

#define IPlayUIBinWindow2_RemoveItem(This,pBinItem)	\
    (This)->lpVtbl -> RemoveItem(This,pBinItem)

#define IPlayUIBinWindow2_SelectItem(This,pBinItem)	\
    (This)->lpVtbl -> SelectItem(This,pBinItem)

#define IPlayUIBinWindow2_EnableItem(This,pBinItem,bEnable)	\
    (This)->lpVtbl -> EnableItem(This,pBinItem,bEnable)

#define IPlayUIBinWindow2_SetHandler(This,pHandler)	\
    (This)->lpVtbl -> SetHandler(This,pHandler)

#define IPlayUIBinWindow2_LoadFromIDList(This,pidl)	\
    (This)->lpVtbl -> LoadFromIDList(This,pidl)

#define IPlayUIBinWindow2_Forward(This)	\
    (This)->lpVtbl -> Forward(This)

#define IPlayUIBinWindow2_GetFilePicon(This,dirString,filename,highlight,ppIBM)	\
    (This)->lpVtbl -> GetFilePicon(This,dirString,filename,highlight,ppIBM)

#define IPlayUIBinWindow2_toggleGUI(This,GUI)	\
    (This)->lpVtbl -> toggleGUI(This,GUI)

#define IPlayUIBinWindow2_SetBinWndOptions(This,options)	\
    (This)->lpVtbl -> SetBinWndOptions(This,options)

#define IPlayUIBinWindow2_Search(This,searchPath,filetype,folderPath)	\
    (This)->lpVtbl -> Search(This,searchPath,filetype,folderPath)

#define IPlayUIBinWindow2_BuildSubBins(This,pathString)	\
    (This)->lpVtbl -> BuildSubBins(This,pathString)


#define IPlayUIBinWindow2_InitPBE(This,startpath)	\
    (This)->lpVtbl -> InitPBE(This,startpath)

#define IPlayUIBinWindow2_LoadItem(This,nItem)	\
    (This)->lpVtbl -> LoadItem(This,nItem)

#define IPlayUIBinWindow2_GetItemCount(This,nItem)	\
    (This)->lpVtbl -> GetItemCount(This,nItem)

#define IPlayUIBinWindow2_SetIDRange(This,nStart,nStop)	\
    (This)->lpVtbl -> SetIDRange(This,nStart,nStop)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE IPlayUIBinWindow2_InitPBE_Proxy( 
    IPlayUIBinWindow2 __RPC_FAR * This,
    /* [in] */ unsigned char __RPC_FAR *startpath);


void __RPC_STUB IPlayUIBinWindow2_InitPBE_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IPlayUIBinWindow2_LoadItem_Proxy( 
    IPlayUIBinWindow2 __RPC_FAR * This,
    /* [in] */ unsigned long nItem);


void __RPC_STUB IPlayUIBinWindow2_LoadItem_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IPlayUIBinWindow2_GetItemCount_Proxy( 
    IPlayUIBinWindow2 __RPC_FAR * This,
    /* [out] */ unsigned long __RPC_FAR *nItem);


void __RPC_STUB IPlayUIBinWindow2_GetItemCount_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IPlayUIBinWindow2_SetIDRange_Proxy( 
    IPlayUIBinWindow2 __RPC_FAR * This,
    /* [in] */ unsigned long nStart,
    /* [in] */ unsigned long nStop);


void __RPC_STUB IPlayUIBinWindow2_SetIDRange_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IPlayUIBinWindow2_INTERFACE_DEFINED__ */


#ifndef __IPlayUIBinHandler_INTERFACE_DEFINED__
#define __IPlayUIBinHandler_INTERFACE_DEFINED__

/****************************************
 * Generated header for interface: IPlayUIBinHandler
 * at Tue Nov 23 05:02:14 1999
 * using MIDL 3.01.75
 ****************************************/
/* [unique][uuid][object][local] */ 



EXTERN_C const IID IID_IPlayUIBinHandler;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    interface DECLSPEC_UUID("8335e414-ab3b-11ce-8468-0000b468276b")
    IPlayUIBinHandler : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE OnSelect( 
            IPlayUIBinItem __RPC_FAR *pBinItem) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE OnLBtnDblClk( 
            IPlayUIBinItem __RPC_FAR *pBinItem) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE OnItemProperties( 
            IPlayUIBinItem __RPC_FAR *pBinItem,
            LPCSTR pFilename) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE OnItemRename( 
            IPlayUIBinItem __RPC_FAR *pBinItem,
            LPSTR pstrOldName,
            LPSTR pstrNewName) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE OnItemDelete( 
            IPlayUIBinItem __RPC_FAR *pBinItem) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE OnItemMove( 
            IPlayUIBinItem __RPC_FAR *pBinItem,
            LPSTR pstrOldName,
            LPSTR pstrNewName) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE OnItemCopy( 
            IPlayUIBinItem __RPC_FAR *pBinItem,
            LPSTR pstrNewName) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE OnLoad( 
            LPCSTR pstrLoadingBin,
            ITEMIDLIST __RPC_FAR *pIDL,
            ULONG ulAttr) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE OnClose( void) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IPlayUIBinHandlerVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            IPlayUIBinHandler __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            IPlayUIBinHandler __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            IPlayUIBinHandler __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *OnSelect )( 
            IPlayUIBinHandler __RPC_FAR * This,
            IPlayUIBinItem __RPC_FAR *pBinItem);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *OnLBtnDblClk )( 
            IPlayUIBinHandler __RPC_FAR * This,
            IPlayUIBinItem __RPC_FAR *pBinItem);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *OnItemProperties )( 
            IPlayUIBinHandler __RPC_FAR * This,
            IPlayUIBinItem __RPC_FAR *pBinItem,
            LPCSTR pFilename);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *OnItemRename )( 
            IPlayUIBinHandler __RPC_FAR * This,
            IPlayUIBinItem __RPC_FAR *pBinItem,
            LPSTR pstrOldName,
            LPSTR pstrNewName);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *OnItemDelete )( 
            IPlayUIBinHandler __RPC_FAR * This,
            IPlayUIBinItem __RPC_FAR *pBinItem);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *OnItemMove )( 
            IPlayUIBinHandler __RPC_FAR * This,
            IPlayUIBinItem __RPC_FAR *pBinItem,
            LPSTR pstrOldName,
            LPSTR pstrNewName);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *OnItemCopy )( 
            IPlayUIBinHandler __RPC_FAR * This,
            IPlayUIBinItem __RPC_FAR *pBinItem,
            LPSTR pstrNewName);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *OnLoad )( 
            IPlayUIBinHandler __RPC_FAR * This,
            LPCSTR pstrLoadingBin,
            ITEMIDLIST __RPC_FAR *pIDL,
            ULONG ulAttr);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *OnClose )( 
            IPlayUIBinHandler __RPC_FAR * This);
        
        END_INTERFACE
    } IPlayUIBinHandlerVtbl;

    interface IPlayUIBinHandler
    {
        CONST_VTBL struct IPlayUIBinHandlerVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IPlayUIBinHandler_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IPlayUIBinHandler_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IPlayUIBinHandler_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IPlayUIBinHandler_OnSelect(This,pBinItem)	\
    (This)->lpVtbl -> OnSelect(This,pBinItem)

#define IPlayUIBinHandler_OnLBtnDblClk(This,pBinItem)	\
    (This)->lpVtbl -> OnLBtnDblClk(This,pBinItem)

#define IPlayUIBinHandler_OnItemProperties(This,pBinItem,pFilename)	\
    (This)->lpVtbl -> OnItemProperties(This,pBinItem,pFilename)

#define IPlayUIBinHandler_OnItemRename(This,pBinItem,pstrOldName,pstrNewName)	\
    (This)->lpVtbl -> OnItemRename(This,pBinItem,pstrOldName,pstrNewName)

#define IPlayUIBinHandler_OnItemDelete(This,pBinItem)	\
    (This)->lpVtbl -> OnItemDelete(This,pBinItem)

#define IPlayUIBinHandler_OnItemMove(This,pBinItem,pstrOldName,pstrNewName)	\
    (This)->lpVtbl -> OnItemMove(This,pBinItem,pstrOldName,pstrNewName)

#define IPlayUIBinHandler_OnItemCopy(This,pBinItem,pstrNewName)	\
    (This)->lpVtbl -> OnItemCopy(This,pBinItem,pstrNewName)

#define IPlayUIBinHandler_OnLoad(This,pstrLoadingBin,pIDL,ulAttr)	\
    (This)->lpVtbl -> OnLoad(This,pstrLoadingBin,pIDL,ulAttr)

#define IPlayUIBinHandler_OnClose(This)	\
    (This)->lpVtbl -> OnClose(This)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE IPlayUIBinHandler_OnSelect_Proxy( 
    IPlayUIBinHandler __RPC_FAR * This,
    IPlayUIBinItem __RPC_FAR *pBinItem);


void __RPC_STUB IPlayUIBinHandler_OnSelect_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IPlayUIBinHandler_OnLBtnDblClk_Proxy( 
    IPlayUIBinHandler __RPC_FAR * This,
    IPlayUIBinItem __RPC_FAR *pBinItem);


void __RPC_STUB IPlayUIBinHandler_OnLBtnDblClk_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IPlayUIBinHandler_OnItemProperties_Proxy( 
    IPlayUIBinHandler __RPC_FAR * This,
    IPlayUIBinItem __RPC_FAR *pBinItem,
    LPCSTR pFilename);


void __RPC_STUB IPlayUIBinHandler_OnItemProperties_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IPlayUIBinHandler_OnItemRename_Proxy( 
    IPlayUIBinHandler __RPC_FAR * This,
    IPlayUIBinItem __RPC_FAR *pBinItem,
    LPSTR pstrOldName,
    LPSTR pstrNewName);


void __RPC_STUB IPlayUIBinHandler_OnItemRename_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IPlayUIBinHandler_OnItemDelete_Proxy( 
    IPlayUIBinHandler __RPC_FAR * This,
    IPlayUIBinItem __RPC_FAR *pBinItem);


void __RPC_STUB IPlayUIBinHandler_OnItemDelete_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IPlayUIBinHandler_OnItemMove_Proxy( 
    IPlayUIBinHandler __RPC_FAR * This,
    IPlayUIBinItem __RPC_FAR *pBinItem,
    LPSTR pstrOldName,
    LPSTR pstrNewName);


void __RPC_STUB IPlayUIBinHandler_OnItemMove_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IPlayUIBinHandler_OnItemCopy_Proxy( 
    IPlayUIBinHandler __RPC_FAR * This,
    IPlayUIBinItem __RPC_FAR *pBinItem,
    LPSTR pstrNewName);


void __RPC_STUB IPlayUIBinHandler_OnItemCopy_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IPlayUIBinHandler_OnLoad_Proxy( 
    IPlayUIBinHandler __RPC_FAR * This,
    LPCSTR pstrLoadingBin,
    ITEMIDLIST __RPC_FAR *pIDL,
    ULONG ulAttr);


void __RPC_STUB IPlayUIBinHandler_OnLoad_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IPlayUIBinHandler_OnClose_Proxy( 
    IPlayUIBinHandler __RPC_FAR * This);


void __RPC_STUB IPlayUIBinHandler_OnClose_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IPlayUIBinHandler_INTERFACE_DEFINED__ */


/****************************************
 * Generated header for interface: __MIDL_itf_playui1_0088
 * at Tue Nov 23 05:02:14 1999
 * using MIDL 3.01.75
 ****************************************/
/* [local] */ 


interface IPlayTimeLine;


extern RPC_IF_HANDLE __MIDL_itf_playui1_0088_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_playui1_0088_v0_0_s_ifspec;

#ifndef __IPlayUI1Manager_INTERFACE_DEFINED__
#define __IPlayUI1Manager_INTERFACE_DEFINED__

/****************************************
 * Generated header for interface: IPlayUI1Manager
 * at Tue Nov 23 05:02:14 1999
 * using MIDL 3.01.75
 ****************************************/
/* [unique][uuid][object][local] */ 



EXTERN_C const IID IID_IPlayUI1Manager;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    interface DECLSPEC_UUID("8335e459-ab3b-11ce-8468-0000b468276b")
    IPlayUI1Manager : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE Load( 
            /* [in] */ LPSTR pFilename) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Save( 
            /* [in] */ LPSTR pFilename) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetManagerHandler( 
            /* [in] */ IPlayUI1ManagerHandler __RPC_FAR *pHandler) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetManagerHandler( 
            /* [out] */ IPlayUI1ManagerHandler __RPC_FAR *__RPC_FAR *ppHandler) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetBinHandler( 
            /* [in] */ IPlayUIBinHandler __RPC_FAR *pHandler) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetBinHandler( 
            /* [out] */ IPlayUIBinHandler __RPC_FAR *__RPC_FAR *ppHandler) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetTimeline0( 
            /* [in] */ void __RPC_FAR *pTLine) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetTimeline0( 
            /* [out] */ void __RPC_FAR *__RPC_FAR *ppTLine) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetTitle( 
            /* [in] */ LPSTR title) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetIcon( 
            /* [in] */ HICON hIcon) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetRequiredWnd( 
            /* [in] */ PlayUI_LayoutWnd layoutWnd,
            /* [out] */ IPlayUI1Window __RPC_FAR *__RPC_FAR *ppWindow) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE ExcludeWndType( 
            /* [in] */ CLSID clsidWndType) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetPropertyWnd( 
            /* [in] */ IPlayUI1Window __RPC_FAR *pWindow) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE DoPropertyWnd( 
            /* [out] */ IPlayUI1Window __RPC_FAR *__RPC_FAR *ppWindow) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE RemoveWnd( 
            /* [in] */ IPlayUI1Window __RPC_FAR *pWindow) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetKBWndProc( 
            FARPROC pWndProc) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetTimeline( 
            /* [in] */ IPlayTimeLine __RPC_FAR *pTLine) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetTimeline( 
            /* [out] */ IPlayTimeLine __RPC_FAR *__RPC_FAR *ppTLine) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE UseLayout( 
            /* [string][in] */ LPSTR pstr) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SimpleHelp( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Help( 
            /* [in] */ int appidApplicationID,
            /* [in] */ int istInvocationType,
            /* [in] */ LPSTR lpstrMessage,
            /* [in] */ LPVOID pvExtraParms) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetSaveType( 
            /* [string][in] */ LPCSTR pstrExtension) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetSaveType( 
            /* [string][out] */ LPSTR pstrExtension) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE DoColorWnd( 
            IPlayColor __RPC_FAR *pColor,
            IPlayUI1ColorWndHandler __RPC_FAR *pHandler,
            BOOL bGradient) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE DoFontWnd( 
            /* [string][in] */ LPSTR pszFontName,
            /* [in] */ int iSize,
            /* [in] */ DWORD dwStyle,
            /* [in] */ IPlayFontWindowHandler __RPC_FAR *pHandler) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE DoVirtualBinWnd( 
            /* [out] */ IPlayUIBinWindow __RPC_FAR *pBinWnd) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetColorWnd( 
            /* [out] */ IPlayUI1ColorWindow __RPC_FAR *__RPC_FAR *ppColorWnd) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetFontWnd( 
            /* [out] */ IPlayFontWindow __RPC_FAR *__RPC_FAR *ppFontWnd) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE DoColorWndNew( 
            IPlayColor __RPC_FAR *pColor,
            IPlayUI1ColorWndHandler __RPC_FAR *pHandler,
            BOOL bGradient,
            /* [string][in] */ LPSTR TitleString) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IPlayUI1ManagerVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            IPlayUI1Manager __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            IPlayUI1Manager __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            IPlayUI1Manager __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Load )( 
            IPlayUI1Manager __RPC_FAR * This,
            /* [in] */ LPSTR pFilename);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Save )( 
            IPlayUI1Manager __RPC_FAR * This,
            /* [in] */ LPSTR pFilename);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetManagerHandler )( 
            IPlayUI1Manager __RPC_FAR * This,
            /* [in] */ IPlayUI1ManagerHandler __RPC_FAR *pHandler);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetManagerHandler )( 
            IPlayUI1Manager __RPC_FAR * This,
            /* [out] */ IPlayUI1ManagerHandler __RPC_FAR *__RPC_FAR *ppHandler);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetBinHandler )( 
            IPlayUI1Manager __RPC_FAR * This,
            /* [in] */ IPlayUIBinHandler __RPC_FAR *pHandler);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetBinHandler )( 
            IPlayUI1Manager __RPC_FAR * This,
            /* [out] */ IPlayUIBinHandler __RPC_FAR *__RPC_FAR *ppHandler);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetTimeline0 )( 
            IPlayUI1Manager __RPC_FAR * This,
            /* [in] */ void __RPC_FAR *pTLine);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTimeline0 )( 
            IPlayUI1Manager __RPC_FAR * This,
            /* [out] */ void __RPC_FAR *__RPC_FAR *ppTLine);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetTitle )( 
            IPlayUI1Manager __RPC_FAR * This,
            /* [in] */ LPSTR title);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetIcon )( 
            IPlayUI1Manager __RPC_FAR * This,
            /* [in] */ HICON hIcon);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetRequiredWnd )( 
            IPlayUI1Manager __RPC_FAR * This,
            /* [in] */ PlayUI_LayoutWnd layoutWnd,
            /* [out] */ IPlayUI1Window __RPC_FAR *__RPC_FAR *ppWindow);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *ExcludeWndType )( 
            IPlayUI1Manager __RPC_FAR * This,
            /* [in] */ CLSID clsidWndType);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetPropertyWnd )( 
            IPlayUI1Manager __RPC_FAR * This,
            /* [in] */ IPlayUI1Window __RPC_FAR *pWindow);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *DoPropertyWnd )( 
            IPlayUI1Manager __RPC_FAR * This,
            /* [out] */ IPlayUI1Window __RPC_FAR *__RPC_FAR *ppWindow);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *RemoveWnd )( 
            IPlayUI1Manager __RPC_FAR * This,
            /* [in] */ IPlayUI1Window __RPC_FAR *pWindow);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetKBWndProc )( 
            IPlayUI1Manager __RPC_FAR * This,
            FARPROC pWndProc);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetTimeline )( 
            IPlayUI1Manager __RPC_FAR * This,
            /* [in] */ IPlayTimeLine __RPC_FAR *pTLine);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTimeline )( 
            IPlayUI1Manager __RPC_FAR * This,
            /* [out] */ IPlayTimeLine __RPC_FAR *__RPC_FAR *ppTLine);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *UseLayout )( 
            IPlayUI1Manager __RPC_FAR * This,
            /* [string][in] */ LPSTR pstr);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SimpleHelp )( 
            IPlayUI1Manager __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Help )( 
            IPlayUI1Manager __RPC_FAR * This,
            /* [in] */ int appidApplicationID,
            /* [in] */ int istInvocationType,
            /* [in] */ LPSTR lpstrMessage,
            /* [in] */ LPVOID pvExtraParms);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetSaveType )( 
            IPlayUI1Manager __RPC_FAR * This,
            /* [string][in] */ LPCSTR pstrExtension);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetSaveType )( 
            IPlayUI1Manager __RPC_FAR * This,
            /* [string][out] */ LPSTR pstrExtension);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *DoColorWnd )( 
            IPlayUI1Manager __RPC_FAR * This,
            IPlayColor __RPC_FAR *pColor,
            IPlayUI1ColorWndHandler __RPC_FAR *pHandler,
            BOOL bGradient);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *DoFontWnd )( 
            IPlayUI1Manager __RPC_FAR * This,
            /* [string][in] */ LPSTR pszFontName,
            /* [in] */ int iSize,
            /* [in] */ DWORD dwStyle,
            /* [in] */ IPlayFontWindowHandler __RPC_FAR *pHandler);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *DoVirtualBinWnd )( 
            IPlayUI1Manager __RPC_FAR * This,
            /* [out] */ IPlayUIBinWindow __RPC_FAR *pBinWnd);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetColorWnd )( 
            IPlayUI1Manager __RPC_FAR * This,
            /* [out] */ IPlayUI1ColorWindow __RPC_FAR *__RPC_FAR *ppColorWnd);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetFontWnd )( 
            IPlayUI1Manager __RPC_FAR * This,
            /* [out] */ IPlayFontWindow __RPC_FAR *__RPC_FAR *ppFontWnd);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *DoColorWndNew )( 
            IPlayUI1Manager __RPC_FAR * This,
            IPlayColor __RPC_FAR *pColor,
            IPlayUI1ColorWndHandler __RPC_FAR *pHandler,
            BOOL bGradient,
            /* [string][in] */ LPSTR TitleString);
        
        END_INTERFACE
    } IPlayUI1ManagerVtbl;

    interface IPlayUI1Manager
    {
        CONST_VTBL struct IPlayUI1ManagerVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IPlayUI1Manager_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IPlayUI1Manager_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IPlayUI1Manager_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IPlayUI1Manager_Load(This,pFilename)	\
    (This)->lpVtbl -> Load(This,pFilename)

#define IPlayUI1Manager_Save(This,pFilename)	\
    (This)->lpVtbl -> Save(This,pFilename)

#define IPlayUI1Manager_SetManagerHandler(This,pHandler)	\
    (This)->lpVtbl -> SetManagerHandler(This,pHandler)

#define IPlayUI1Manager_GetManagerHandler(This,ppHandler)	\
    (This)->lpVtbl -> GetManagerHandler(This,ppHandler)

#define IPlayUI1Manager_SetBinHandler(This,pHandler)	\
    (This)->lpVtbl -> SetBinHandler(This,pHandler)

#define IPlayUI1Manager_GetBinHandler(This,ppHandler)	\
    (This)->lpVtbl -> GetBinHandler(This,ppHandler)

#define IPlayUI1Manager_SetTimeline0(This,pTLine)	\
    (This)->lpVtbl -> SetTimeline0(This,pTLine)

#define IPlayUI1Manager_GetTimeline0(This,ppTLine)	\
    (This)->lpVtbl -> GetTimeline0(This,ppTLine)

#define IPlayUI1Manager_SetTitle(This,title)	\
    (This)->lpVtbl -> SetTitle(This,title)

#define IPlayUI1Manager_SetIcon(This,hIcon)	\
    (This)->lpVtbl -> SetIcon(This,hIcon)

#define IPlayUI1Manager_SetRequiredWnd(This,layoutWnd,ppWindow)	\
    (This)->lpVtbl -> SetRequiredWnd(This,layoutWnd,ppWindow)

#define IPlayUI1Manager_ExcludeWndType(This,clsidWndType)	\
    (This)->lpVtbl -> ExcludeWndType(This,clsidWndType)

#define IPlayUI1Manager_SetPropertyWnd(This,pWindow)	\
    (This)->lpVtbl -> SetPropertyWnd(This,pWindow)

#define IPlayUI1Manager_DoPropertyWnd(This,ppWindow)	\
    (This)->lpVtbl -> DoPropertyWnd(This,ppWindow)

#define IPlayUI1Manager_RemoveWnd(This,pWindow)	\
    (This)->lpVtbl -> RemoveWnd(This,pWindow)

#define IPlayUI1Manager_SetKBWndProc(This,pWndProc)	\
    (This)->lpVtbl -> SetKBWndProc(This,pWndProc)

#define IPlayUI1Manager_SetTimeline(This,pTLine)	\
    (This)->lpVtbl -> SetTimeline(This,pTLine)

#define IPlayUI1Manager_GetTimeline(This,ppTLine)	\
    (This)->lpVtbl -> GetTimeline(This,ppTLine)

#define IPlayUI1Manager_UseLayout(This,pstr)	\
    (This)->lpVtbl -> UseLayout(This,pstr)

#define IPlayUI1Manager_SimpleHelp(This)	\
    (This)->lpVtbl -> SimpleHelp(This)

#define IPlayUI1Manager_Help(This,appidApplicationID,istInvocationType,lpstrMessage,pvExtraParms)	\
    (This)->lpVtbl -> Help(This,appidApplicationID,istInvocationType,lpstrMessage,pvExtraParms)

#define IPlayUI1Manager_SetSaveType(This,pstrExtension)	\
    (This)->lpVtbl -> SetSaveType(This,pstrExtension)

#define IPlayUI1Manager_GetSaveType(This,pstrExtension)	\
    (This)->lpVtbl -> GetSaveType(This,pstrExtension)

#define IPlayUI1Manager_DoColorWnd(This,pColor,pHandler,bGradient)	\
    (This)->lpVtbl -> DoColorWnd(This,pColor,pHandler,bGradient)

#define IPlayUI1Manager_DoFontWnd(This,pszFontName,iSize,dwStyle,pHandler)	\
    (This)->lpVtbl -> DoFontWnd(This,pszFontName,iSize,dwStyle,pHandler)

#define IPlayUI1Manager_DoVirtualBinWnd(This,pBinWnd)	\
    (This)->lpVtbl -> DoVirtualBinWnd(This,pBinWnd)

#define IPlayUI1Manager_GetColorWnd(This,ppColorWnd)	\
    (This)->lpVtbl -> GetColorWnd(This,ppColorWnd)

#define IPlayUI1Manager_GetFontWnd(This,ppFontWnd)	\
    (This)->lpVtbl -> GetFontWnd(This,ppFontWnd)

#define IPlayUI1Manager_DoColorWndNew(This,pColor,pHandler,bGradient,TitleString)	\
    (This)->lpVtbl -> DoColorWndNew(This,pColor,pHandler,bGradient,TitleString)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE IPlayUI1Manager_Load_Proxy( 
    IPlayUI1Manager __RPC_FAR * This,
    /* [in] */ LPSTR pFilename);


void __RPC_STUB IPlayUI1Manager_Load_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IPlayUI1Manager_Save_Proxy( 
    IPlayUI1Manager __RPC_FAR * This,
    /* [in] */ LPSTR pFilename);


void __RPC_STUB IPlayUI1Manager_Save_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IPlayUI1Manager_SetManagerHandler_Proxy( 
    IPlayUI1Manager __RPC_FAR * This,
    /* [in] */ IPlayUI1ManagerHandler __RPC_FAR *pHandler);


void __RPC_STUB IPlayUI1Manager_SetManagerHandler_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IPlayUI1Manager_GetManagerHandler_Proxy( 
    IPlayUI1Manager __RPC_FAR * This,
    /* [out] */ IPlayUI1ManagerHandler __RPC_FAR *__RPC_FAR *ppHandler);


void __RPC_STUB IPlayUI1Manager_GetManagerHandler_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IPlayUI1Manager_SetBinHandler_Proxy( 
    IPlayUI1Manager __RPC_FAR * This,
    /* [in] */ IPlayUIBinHandler __RPC_FAR *pHandler);


void __RPC_STUB IPlayUI1Manager_SetBinHandler_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IPlayUI1Manager_GetBinHandler_Proxy( 
    IPlayUI1Manager __RPC_FAR * This,
    /* [out] */ IPlayUIBinHandler __RPC_FAR *__RPC_FAR *ppHandler);


void __RPC_STUB IPlayUI1Manager_GetBinHandler_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IPlayUI1Manager_SetTimeline0_Proxy( 
    IPlayUI1Manager __RPC_FAR * This,
    /* [in] */ void __RPC_FAR *pTLine);


void __RPC_STUB IPlayUI1Manager_SetTimeline0_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IPlayUI1Manager_GetTimeline0_Proxy( 
    IPlayUI1Manager __RPC_FAR * This,
    /* [out] */ void __RPC_FAR *__RPC_FAR *ppTLine);


void __RPC_STUB IPlayUI1Manager_GetTimeline0_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IPlayUI1Manager_SetTitle_Proxy( 
    IPlayUI1Manager __RPC_FAR * This,
    /* [in] */ LPSTR title);


void __RPC_STUB IPlayUI1Manager_SetTitle_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IPlayUI1Manager_SetIcon_Proxy( 
    IPlayUI1Manager __RPC_FAR * This,
    /* [in] */ HICON hIcon);


void __RPC_STUB IPlayUI1Manager_SetIcon_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IPlayUI1Manager_SetRequiredWnd_Proxy( 
    IPlayUI1Manager __RPC_FAR * This,
    /* [in] */ PlayUI_LayoutWnd layoutWnd,
    /* [out] */ IPlayUI1Window __RPC_FAR *__RPC_FAR *ppWindow);


void __RPC_STUB IPlayUI1Manager_SetRequiredWnd_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IPlayUI1Manager_ExcludeWndType_Proxy( 
    IPlayUI1Manager __RPC_FAR * This,
    /* [in] */ CLSID clsidWndType);


void __RPC_STUB IPlayUI1Manager_ExcludeWndType_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IPlayUI1Manager_SetPropertyWnd_Proxy( 
    IPlayUI1Manager __RPC_FAR * This,
    /* [in] */ IPlayUI1Window __RPC_FAR *pWindow);


void __RPC_STUB IPlayUI1Manager_SetPropertyWnd_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IPlayUI1Manager_DoPropertyWnd_Proxy( 
    IPlayUI1Manager __RPC_FAR * This,
    /* [out] */ IPlayUI1Window __RPC_FAR *__RPC_FAR *ppWindow);


void __RPC_STUB IPlayUI1Manager_DoPropertyWnd_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IPlayUI1Manager_RemoveWnd_Proxy( 
    IPlayUI1Manager __RPC_FAR * This,
    /* [in] */ IPlayUI1Window __RPC_FAR *pWindow);


void __RPC_STUB IPlayUI1Manager_RemoveWnd_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IPlayUI1Manager_SetKBWndProc_Proxy( 
    IPlayUI1Manager __RPC_FAR * This,
    FARPROC pWndProc);


void __RPC_STUB IPlayUI1Manager_SetKBWndProc_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IPlayUI1Manager_SetTimeline_Proxy( 
    IPlayUI1Manager __RPC_FAR * This,
    /* [in] */ IPlayTimeLine __RPC_FAR *pTLine);


void __RPC_STUB IPlayUI1Manager_SetTimeline_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IPlayUI1Manager_GetTimeline_Proxy( 
    IPlayUI1Manager __RPC_FAR * This,
    /* [out] */ IPlayTimeLine __RPC_FAR *__RPC_FAR *ppTLine);


void __RPC_STUB IPlayUI1Manager_GetTimeline_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IPlayUI1Manager_UseLayout_Proxy( 
    IPlayUI1Manager __RPC_FAR * This,
    /* [string][in] */ LPSTR pstr);


void __RPC_STUB IPlayUI1Manager_UseLayout_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IPlayUI1Manager_SimpleHelp_Proxy( 
    IPlayUI1Manager __RPC_FAR * This);


void __RPC_STUB IPlayUI1Manager_SimpleHelp_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IPlayUI1Manager_Help_Proxy( 
    IPlayUI1Manager __RPC_FAR * This,
    /* [in] */ int appidApplicationID,
    /* [in] */ int istInvocationType,
    /* [in] */ LPSTR lpstrMessage,
    /* [in] */ LPVOID pvExtraParms);


void __RPC_STUB IPlayUI1Manager_Help_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IPlayUI1Manager_SetSaveType_Proxy( 
    IPlayUI1Manager __RPC_FAR * This,
    /* [string][in] */ LPCSTR pstrExtension);


void __RPC_STUB IPlayUI1Manager_SetSaveType_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IPlayUI1Manager_GetSaveType_Proxy( 
    IPlayUI1Manager __RPC_FAR * This,
    /* [string][out] */ LPSTR pstrExtension);


void __RPC_STUB IPlayUI1Manager_GetSaveType_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IPlayUI1Manager_DoColorWnd_Proxy( 
    IPlayUI1Manager __RPC_FAR * This,
    IPlayColor __RPC_FAR *pColor,
    IPlayUI1ColorWndHandler __RPC_FAR *pHandler,
    BOOL bGradient);


void __RPC_STUB IPlayUI1Manager_DoColorWnd_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IPlayUI1Manager_DoFontWnd_Proxy( 
    IPlayUI1Manager __RPC_FAR * This,
    /* [string][in] */ LPSTR pszFontName,
    /* [in] */ int iSize,
    /* [in] */ DWORD dwStyle,
    /* [in] */ IPlayFontWindowHandler __RPC_FAR *pHandler);


void __RPC_STUB IPlayUI1Manager_DoFontWnd_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IPlayUI1Manager_DoVirtualBinWnd_Proxy( 
    IPlayUI1Manager __RPC_FAR * This,
    /* [out] */ IPlayUIBinWindow __RPC_FAR *pBinWnd);


void __RPC_STUB IPlayUI1Manager_DoVirtualBinWnd_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IPlayUI1Manager_GetColorWnd_Proxy( 
    IPlayUI1Manager __RPC_FAR * This,
    /* [out] */ IPlayUI1ColorWindow __RPC_FAR *__RPC_FAR *ppColorWnd);


void __RPC_STUB IPlayUI1Manager_GetColorWnd_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IPlayUI1Manager_GetFontWnd_Proxy( 
    IPlayUI1Manager __RPC_FAR * This,
    /* [out] */ IPlayFontWindow __RPC_FAR *__RPC_FAR *ppFontWnd);


void __RPC_STUB IPlayUI1Manager_GetFontWnd_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IPlayUI1Manager_DoColorWndNew_Proxy( 
    IPlayUI1Manager __RPC_FAR * This,
    IPlayColor __RPC_FAR *pColor,
    IPlayUI1ColorWndHandler __RPC_FAR *pHandler,
    BOOL bGradient,
    /* [string][in] */ LPSTR TitleString);


void __RPC_STUB IPlayUI1Manager_DoColorWndNew_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IPlayUI1Manager_INTERFACE_DEFINED__ */


#ifndef __IPlayUI1Manager2_INTERFACE_DEFINED__
#define __IPlayUI1Manager2_INTERFACE_DEFINED__

/****************************************
 * Generated header for interface: IPlayUI1Manager2
 * at Tue Nov 23 05:02:14 1999
 * using MIDL 3.01.75
 ****************************************/
/* [unique][uuid][object][local] */ 



EXTERN_C const IID IID_IPlayUI1Manager2;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    interface DECLSPEC_UUID("8335e458-ab3b-11ce-8468-0000b468276b")
    IPlayUI1Manager2 : public IPlayUI1Manager
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE EnumWindows( 
            IEnumUnknown __RPC_FAR *__RPC_FAR *ppEnum) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE EnumBinWindows( 
            IEnumUnknown __RPC_FAR *__RPC_FAR *ppEnum) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE AddWindowType( 
            LPSTR name,
            REFCLSID clsid) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE AllowWindowCreation( 
            REFCLSID clsid,
            BOOL bAllow) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IPlayUI1Manager2Vtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            IPlayUI1Manager2 __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            IPlayUI1Manager2 __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            IPlayUI1Manager2 __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Load )( 
            IPlayUI1Manager2 __RPC_FAR * This,
            /* [in] */ LPSTR pFilename);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Save )( 
            IPlayUI1Manager2 __RPC_FAR * This,
            /* [in] */ LPSTR pFilename);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetManagerHandler )( 
            IPlayUI1Manager2 __RPC_FAR * This,
            /* [in] */ IPlayUI1ManagerHandler __RPC_FAR *pHandler);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetManagerHandler )( 
            IPlayUI1Manager2 __RPC_FAR * This,
            /* [out] */ IPlayUI1ManagerHandler __RPC_FAR *__RPC_FAR *ppHandler);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetBinHandler )( 
            IPlayUI1Manager2 __RPC_FAR * This,
            /* [in] */ IPlayUIBinHandler __RPC_FAR *pHandler);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetBinHandler )( 
            IPlayUI1Manager2 __RPC_FAR * This,
            /* [out] */ IPlayUIBinHandler __RPC_FAR *__RPC_FAR *ppHandler);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetTimeline0 )( 
            IPlayUI1Manager2 __RPC_FAR * This,
            /* [in] */ void __RPC_FAR *pTLine);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTimeline0 )( 
            IPlayUI1Manager2 __RPC_FAR * This,
            /* [out] */ void __RPC_FAR *__RPC_FAR *ppTLine);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetTitle )( 
            IPlayUI1Manager2 __RPC_FAR * This,
            /* [in] */ LPSTR title);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetIcon )( 
            IPlayUI1Manager2 __RPC_FAR * This,
            /* [in] */ HICON hIcon);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetRequiredWnd )( 
            IPlayUI1Manager2 __RPC_FAR * This,
            /* [in] */ PlayUI_LayoutWnd layoutWnd,
            /* [out] */ IPlayUI1Window __RPC_FAR *__RPC_FAR *ppWindow);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *ExcludeWndType )( 
            IPlayUI1Manager2 __RPC_FAR * This,
            /* [in] */ CLSID clsidWndType);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetPropertyWnd )( 
            IPlayUI1Manager2 __RPC_FAR * This,
            /* [in] */ IPlayUI1Window __RPC_FAR *pWindow);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *DoPropertyWnd )( 
            IPlayUI1Manager2 __RPC_FAR * This,
            /* [out] */ IPlayUI1Window __RPC_FAR *__RPC_FAR *ppWindow);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *RemoveWnd )( 
            IPlayUI1Manager2 __RPC_FAR * This,
            /* [in] */ IPlayUI1Window __RPC_FAR *pWindow);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetKBWndProc )( 
            IPlayUI1Manager2 __RPC_FAR * This,
            FARPROC pWndProc);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetTimeline )( 
            IPlayUI1Manager2 __RPC_FAR * This,
            /* [in] */ IPlayTimeLine __RPC_FAR *pTLine);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTimeline )( 
            IPlayUI1Manager2 __RPC_FAR * This,
            /* [out] */ IPlayTimeLine __RPC_FAR *__RPC_FAR *ppTLine);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *UseLayout )( 
            IPlayUI1Manager2 __RPC_FAR * This,
            /* [string][in] */ LPSTR pstr);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SimpleHelp )( 
            IPlayUI1Manager2 __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Help )( 
            IPlayUI1Manager2 __RPC_FAR * This,
            /* [in] */ int appidApplicationID,
            /* [in] */ int istInvocationType,
            /* [in] */ LPSTR lpstrMessage,
            /* [in] */ LPVOID pvExtraParms);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetSaveType )( 
            IPlayUI1Manager2 __RPC_FAR * This,
            /* [string][in] */ LPCSTR pstrExtension);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetSaveType )( 
            IPlayUI1Manager2 __RPC_FAR * This,
            /* [string][out] */ LPSTR pstrExtension);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *DoColorWnd )( 
            IPlayUI1Manager2 __RPC_FAR * This,
            IPlayColor __RPC_FAR *pColor,
            IPlayUI1ColorWndHandler __RPC_FAR *pHandler,
            BOOL bGradient);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *DoFontWnd )( 
            IPlayUI1Manager2 __RPC_FAR * This,
            /* [string][in] */ LPSTR pszFontName,
            /* [in] */ int iSize,
            /* [in] */ DWORD dwStyle,
            /* [in] */ IPlayFontWindowHandler __RPC_FAR *pHandler);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *DoVirtualBinWnd )( 
            IPlayUI1Manager2 __RPC_FAR * This,
            /* [out] */ IPlayUIBinWindow __RPC_FAR *pBinWnd);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetColorWnd )( 
            IPlayUI1Manager2 __RPC_FAR * This,
            /* [out] */ IPlayUI1ColorWindow __RPC_FAR *__RPC_FAR *ppColorWnd);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetFontWnd )( 
            IPlayUI1Manager2 __RPC_FAR * This,
            /* [out] */ IPlayFontWindow __RPC_FAR *__RPC_FAR *ppFontWnd);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *DoColorWndNew )( 
            IPlayUI1Manager2 __RPC_FAR * This,
            IPlayColor __RPC_FAR *pColor,
            IPlayUI1ColorWndHandler __RPC_FAR *pHandler,
            BOOL bGradient,
            /* [string][in] */ LPSTR TitleString);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *EnumWindows )( 
            IPlayUI1Manager2 __RPC_FAR * This,
            IEnumUnknown __RPC_FAR *__RPC_FAR *ppEnum);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *EnumBinWindows )( 
            IPlayUI1Manager2 __RPC_FAR * This,
            IEnumUnknown __RPC_FAR *__RPC_FAR *ppEnum);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *AddWindowType )( 
            IPlayUI1Manager2 __RPC_FAR * This,
            LPSTR name,
            REFCLSID clsid);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *AllowWindowCreation )( 
            IPlayUI1Manager2 __RPC_FAR * This,
            REFCLSID clsid,
            BOOL bAllow);
        
        END_INTERFACE
    } IPlayUI1Manager2Vtbl;

    interface IPlayUI1Manager2
    {
        CONST_VTBL struct IPlayUI1Manager2Vtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IPlayUI1Manager2_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IPlayUI1Manager2_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IPlayUI1Manager2_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IPlayUI1Manager2_Load(This,pFilename)	\
    (This)->lpVtbl -> Load(This,pFilename)

#define IPlayUI1Manager2_Save(This,pFilename)	\
    (This)->lpVtbl -> Save(This,pFilename)

#define IPlayUI1Manager2_SetManagerHandler(This,pHandler)	\
    (This)->lpVtbl -> SetManagerHandler(This,pHandler)

#define IPlayUI1Manager2_GetManagerHandler(This,ppHandler)	\
    (This)->lpVtbl -> GetManagerHandler(This,ppHandler)

#define IPlayUI1Manager2_SetBinHandler(This,pHandler)	\
    (This)->lpVtbl -> SetBinHandler(This,pHandler)

#define IPlayUI1Manager2_GetBinHandler(This,ppHandler)	\
    (This)->lpVtbl -> GetBinHandler(This,ppHandler)

#define IPlayUI1Manager2_SetTimeline0(This,pTLine)	\
    (This)->lpVtbl -> SetTimeline0(This,pTLine)

#define IPlayUI1Manager2_GetTimeline0(This,ppTLine)	\
    (This)->lpVtbl -> GetTimeline0(This,ppTLine)

#define IPlayUI1Manager2_SetTitle(This,title)	\
    (This)->lpVtbl -> SetTitle(This,title)

#define IPlayUI1Manager2_SetIcon(This,hIcon)	\
    (This)->lpVtbl -> SetIcon(This,hIcon)

#define IPlayUI1Manager2_SetRequiredWnd(This,layoutWnd,ppWindow)	\
    (This)->lpVtbl -> SetRequiredWnd(This,layoutWnd,ppWindow)

#define IPlayUI1Manager2_ExcludeWndType(This,clsidWndType)	\
    (This)->lpVtbl -> ExcludeWndType(This,clsidWndType)

#define IPlayUI1Manager2_SetPropertyWnd(This,pWindow)	\
    (This)->lpVtbl -> SetPropertyWnd(This,pWindow)

#define IPlayUI1Manager2_DoPropertyWnd(This,ppWindow)	\
    (This)->lpVtbl -> DoPropertyWnd(This,ppWindow)

#define IPlayUI1Manager2_RemoveWnd(This,pWindow)	\
    (This)->lpVtbl -> RemoveWnd(This,pWindow)

#define IPlayUI1Manager2_SetKBWndProc(This,pWndProc)	\
    (This)->lpVtbl -> SetKBWndProc(This,pWndProc)

#define IPlayUI1Manager2_SetTimeline(This,pTLine)	\
    (This)->lpVtbl -> SetTimeline(This,pTLine)

#define IPlayUI1Manager2_GetTimeline(This,ppTLine)	\
    (This)->lpVtbl -> GetTimeline(This,ppTLine)

#define IPlayUI1Manager2_UseLayout(This,pstr)	\
    (This)->lpVtbl -> UseLayout(This,pstr)

#define IPlayUI1Manager2_SimpleHelp(This)	\
    (This)->lpVtbl -> SimpleHelp(This)

#define IPlayUI1Manager2_Help(This,appidApplicationID,istInvocationType,lpstrMessage,pvExtraParms)	\
    (This)->lpVtbl -> Help(This,appidApplicationID,istInvocationType,lpstrMessage,pvExtraParms)

#define IPlayUI1Manager2_SetSaveType(This,pstrExtension)	\
    (This)->lpVtbl -> SetSaveType(This,pstrExtension)

#define IPlayUI1Manager2_GetSaveType(This,pstrExtension)	\
    (This)->lpVtbl -> GetSaveType(This,pstrExtension)

#define IPlayUI1Manager2_DoColorWnd(This,pColor,pHandler,bGradient)	\
    (This)->lpVtbl -> DoColorWnd(This,pColor,pHandler,bGradient)

#define IPlayUI1Manager2_DoFontWnd(This,pszFontName,iSize,dwStyle,pHandler)	\
    (This)->lpVtbl -> DoFontWnd(This,pszFontName,iSize,dwStyle,pHandler)

#define IPlayUI1Manager2_DoVirtualBinWnd(This,pBinWnd)	\
    (This)->lpVtbl -> DoVirtualBinWnd(This,pBinWnd)

#define IPlayUI1Manager2_GetColorWnd(This,ppColorWnd)	\
    (This)->lpVtbl -> GetColorWnd(This,ppColorWnd)

#define IPlayUI1Manager2_GetFontWnd(This,ppFontWnd)	\
    (This)->lpVtbl -> GetFontWnd(This,ppFontWnd)

#define IPlayUI1Manager2_DoColorWndNew(This,pColor,pHandler,bGradient,TitleString)	\
    (This)->lpVtbl -> DoColorWndNew(This,pColor,pHandler,bGradient,TitleString)


#define IPlayUI1Manager2_EnumWindows(This,ppEnum)	\
    (This)->lpVtbl -> EnumWindows(This,ppEnum)

#define IPlayUI1Manager2_EnumBinWindows(This,ppEnum)	\
    (This)->lpVtbl -> EnumBinWindows(This,ppEnum)

#define IPlayUI1Manager2_AddWindowType(This,name,clsid)	\
    (This)->lpVtbl -> AddWindowType(This,name,clsid)

#define IPlayUI1Manager2_AllowWindowCreation(This,clsid,bAllow)	\
    (This)->lpVtbl -> AllowWindowCreation(This,clsid,bAllow)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE IPlayUI1Manager2_EnumWindows_Proxy( 
    IPlayUI1Manager2 __RPC_FAR * This,
    IEnumUnknown __RPC_FAR *__RPC_FAR *ppEnum);


void __RPC_STUB IPlayUI1Manager2_EnumWindows_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IPlayUI1Manager2_EnumBinWindows_Proxy( 
    IPlayUI1Manager2 __RPC_FAR * This,
    IEnumUnknown __RPC_FAR *__RPC_FAR *ppEnum);


void __RPC_STUB IPlayUI1Manager2_EnumBinWindows_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IPlayUI1Manager2_AddWindowType_Proxy( 
    IPlayUI1Manager2 __RPC_FAR * This,
    LPSTR name,
    REFCLSID clsid);


void __RPC_STUB IPlayUI1Manager2_AddWindowType_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IPlayUI1Manager2_AllowWindowCreation_Proxy( 
    IPlayUI1Manager2 __RPC_FAR * This,
    REFCLSID clsid,
    BOOL bAllow);


void __RPC_STUB IPlayUI1Manager2_AllowWindowCreation_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IPlayUI1Manager2_INTERFACE_DEFINED__ */


#ifndef __IPlayUI1ManagerHandler_INTERFACE_DEFINED__
#define __IPlayUI1ManagerHandler_INTERFACE_DEFINED__

/****************************************
 * Generated header for interface: IPlayUI1ManagerHandler
 * at Tue Nov 23 05:02:14 1999
 * using MIDL 3.01.75
 ****************************************/
/* [unique][uuid][object][local] */ 



EXTERN_C const IID IID_IPlayUI1ManagerHandler;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    interface DECLSPEC_UUID("8335e45a-ab3b-11ce-8468-0000b468276b")
    IPlayUI1ManagerHandler : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE OnTLPreLoad( 
            IPlayTimeLine __RPC_FAR *pTimeLine,
            LPSTR filename,
            IStorage __RPC_FAR *pStg) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE OnTLPostLoad( 
            IPlayTimeLine __RPC_FAR *pTimeLine,
            LPSTR filename,
            IStorage __RPC_FAR *pStg) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE OnTLPreViewRemoval( 
            IPlayTimeLine __RPC_FAR *pTimeLine) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE OnTLPostViewRemoval( 
            IPlayTimeLine __RPC_FAR *pTimeLine) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE OnTLPreSave( 
            IPlayTimeLine __RPC_FAR *pTimeLine,
            IStorage __RPC_FAR *pStg) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE OnTLPostSave( 
            IPlayTimeLine __RPC_FAR *pTimeLine,
            IStorage __RPC_FAR *pStg) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE OnAppActivate( 
            BOOL bActive) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IPlayUI1ManagerHandlerVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            IPlayUI1ManagerHandler __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            IPlayUI1ManagerHandler __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            IPlayUI1ManagerHandler __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *OnTLPreLoad )( 
            IPlayUI1ManagerHandler __RPC_FAR * This,
            IPlayTimeLine __RPC_FAR *pTimeLine,
            LPSTR filename,
            IStorage __RPC_FAR *pStg);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *OnTLPostLoad )( 
            IPlayUI1ManagerHandler __RPC_FAR * This,
            IPlayTimeLine __RPC_FAR *pTimeLine,
            LPSTR filename,
            IStorage __RPC_FAR *pStg);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *OnTLPreViewRemoval )( 
            IPlayUI1ManagerHandler __RPC_FAR * This,
            IPlayTimeLine __RPC_FAR *pTimeLine);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *OnTLPostViewRemoval )( 
            IPlayUI1ManagerHandler __RPC_FAR * This,
            IPlayTimeLine __RPC_FAR *pTimeLine);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *OnTLPreSave )( 
            IPlayUI1ManagerHandler __RPC_FAR * This,
            IPlayTimeLine __RPC_FAR *pTimeLine,
            IStorage __RPC_FAR *pStg);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *OnTLPostSave )( 
            IPlayUI1ManagerHandler __RPC_FAR * This,
            IPlayTimeLine __RPC_FAR *pTimeLine,
            IStorage __RPC_FAR *pStg);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *OnAppActivate )( 
            IPlayUI1ManagerHandler __RPC_FAR * This,
            BOOL bActive);
        
        END_INTERFACE
    } IPlayUI1ManagerHandlerVtbl;

    interface IPlayUI1ManagerHandler
    {
        CONST_VTBL struct IPlayUI1ManagerHandlerVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IPlayUI1ManagerHandler_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IPlayUI1ManagerHandler_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IPlayUI1ManagerHandler_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IPlayUI1ManagerHandler_OnTLPreLoad(This,pTimeLine,filename,pStg)	\
    (This)->lpVtbl -> OnTLPreLoad(This,pTimeLine,filename,pStg)

#define IPlayUI1ManagerHandler_OnTLPostLoad(This,pTimeLine,filename,pStg)	\
    (This)->lpVtbl -> OnTLPostLoad(This,pTimeLine,filename,pStg)

#define IPlayUI1ManagerHandler_OnTLPreViewRemoval(This,pTimeLine)	\
    (This)->lpVtbl -> OnTLPreViewRemoval(This,pTimeLine)

#define IPlayUI1ManagerHandler_OnTLPostViewRemoval(This,pTimeLine)	\
    (This)->lpVtbl -> OnTLPostViewRemoval(This,pTimeLine)

#define IPlayUI1ManagerHandler_OnTLPreSave(This,pTimeLine,pStg)	\
    (This)->lpVtbl -> OnTLPreSave(This,pTimeLine,pStg)

#define IPlayUI1ManagerHandler_OnTLPostSave(This,pTimeLine,pStg)	\
    (This)->lpVtbl -> OnTLPostSave(This,pTimeLine,pStg)

#define IPlayUI1ManagerHandler_OnAppActivate(This,bActive)	\
    (This)->lpVtbl -> OnAppActivate(This,bActive)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE IPlayUI1ManagerHandler_OnTLPreLoad_Proxy( 
    IPlayUI1ManagerHandler __RPC_FAR * This,
    IPlayTimeLine __RPC_FAR *pTimeLine,
    LPSTR filename,
    IStorage __RPC_FAR *pStg);


void __RPC_STUB IPlayUI1ManagerHandler_OnTLPreLoad_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IPlayUI1ManagerHandler_OnTLPostLoad_Proxy( 
    IPlayUI1ManagerHandler __RPC_FAR * This,
    IPlayTimeLine __RPC_FAR *pTimeLine,
    LPSTR filename,
    IStorage __RPC_FAR *pStg);


void __RPC_STUB IPlayUI1ManagerHandler_OnTLPostLoad_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IPlayUI1ManagerHandler_OnTLPreViewRemoval_Proxy( 
    IPlayUI1ManagerHandler __RPC_FAR * This,
    IPlayTimeLine __RPC_FAR *pTimeLine);


void __RPC_STUB IPlayUI1ManagerHandler_OnTLPreViewRemoval_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IPlayUI1ManagerHandler_OnTLPostViewRemoval_Proxy( 
    IPlayUI1ManagerHandler __RPC_FAR * This,
    IPlayTimeLine __RPC_FAR *pTimeLine);


void __RPC_STUB IPlayUI1ManagerHandler_OnTLPostViewRemoval_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IPlayUI1ManagerHandler_OnTLPreSave_Proxy( 
    IPlayUI1ManagerHandler __RPC_FAR * This,
    IPlayTimeLine __RPC_FAR *pTimeLine,
    IStorage __RPC_FAR *pStg);


void __RPC_STUB IPlayUI1ManagerHandler_OnTLPreSave_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IPlayUI1ManagerHandler_OnTLPostSave_Proxy( 
    IPlayUI1ManagerHandler __RPC_FAR * This,
    IPlayTimeLine __RPC_FAR *pTimeLine,
    IStorage __RPC_FAR *pStg);


void __RPC_STUB IPlayUI1ManagerHandler_OnTLPostSave_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IPlayUI1ManagerHandler_OnAppActivate_Proxy( 
    IPlayUI1ManagerHandler __RPC_FAR * This,
    BOOL bActive);


void __RPC_STUB IPlayUI1ManagerHandler_OnAppActivate_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IPlayUI1ManagerHandler_INTERFACE_DEFINED__ */


#ifndef __IPlayUI1ManagerHandler2_INTERFACE_DEFINED__
#define __IPlayUI1ManagerHandler2_INTERFACE_DEFINED__

/****************************************
 * Generated header for interface: IPlayUI1ManagerHandler2
 * at Tue Nov 23 05:02:14 1999
 * using MIDL 3.01.75
 ****************************************/
/* [unique][uuid][object][local] */ 



EXTERN_C const IID IID_IPlayUI1ManagerHandler2;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    interface DECLSPEC_UUID("8335e457-ab3b-11ce-8468-0000b468276b")
    IPlayUI1ManagerHandler2 : public IPlayUI1ManagerHandler
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE OnShowWindow( 
            IPlayUI1Window __RPC_FAR *pWnd,
            BOOL bShow,
            DWORD dwReason) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE OnPreLoadLayout( 
            IPlayUI1Manager2 __RPC_FAR *pManager,
            LPSTR pszLayoutFile) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE OnPostLoadLayout( 
            IPlayUI1Manager2 __RPC_FAR *pManager,
            LPSTR pszLayoutFile) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IPlayUI1ManagerHandler2Vtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            IPlayUI1ManagerHandler2 __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            IPlayUI1ManagerHandler2 __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            IPlayUI1ManagerHandler2 __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *OnTLPreLoad )( 
            IPlayUI1ManagerHandler2 __RPC_FAR * This,
            IPlayTimeLine __RPC_FAR *pTimeLine,
            LPSTR filename,
            IStorage __RPC_FAR *pStg);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *OnTLPostLoad )( 
            IPlayUI1ManagerHandler2 __RPC_FAR * This,
            IPlayTimeLine __RPC_FAR *pTimeLine,
            LPSTR filename,
            IStorage __RPC_FAR *pStg);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *OnTLPreViewRemoval )( 
            IPlayUI1ManagerHandler2 __RPC_FAR * This,
            IPlayTimeLine __RPC_FAR *pTimeLine);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *OnTLPostViewRemoval )( 
            IPlayUI1ManagerHandler2 __RPC_FAR * This,
            IPlayTimeLine __RPC_FAR *pTimeLine);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *OnTLPreSave )( 
            IPlayUI1ManagerHandler2 __RPC_FAR * This,
            IPlayTimeLine __RPC_FAR *pTimeLine,
            IStorage __RPC_FAR *pStg);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *OnTLPostSave )( 
            IPlayUI1ManagerHandler2 __RPC_FAR * This,
            IPlayTimeLine __RPC_FAR *pTimeLine,
            IStorage __RPC_FAR *pStg);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *OnAppActivate )( 
            IPlayUI1ManagerHandler2 __RPC_FAR * This,
            BOOL bActive);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *OnShowWindow )( 
            IPlayUI1ManagerHandler2 __RPC_FAR * This,
            IPlayUI1Window __RPC_FAR *pWnd,
            BOOL bShow,
            DWORD dwReason);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *OnPreLoadLayout )( 
            IPlayUI1ManagerHandler2 __RPC_FAR * This,
            IPlayUI1Manager2 __RPC_FAR *pManager,
            LPSTR pszLayoutFile);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *OnPostLoadLayout )( 
            IPlayUI1ManagerHandler2 __RPC_FAR * This,
            IPlayUI1Manager2 __RPC_FAR *pManager,
            LPSTR pszLayoutFile);
        
        END_INTERFACE
    } IPlayUI1ManagerHandler2Vtbl;

    interface IPlayUI1ManagerHandler2
    {
        CONST_VTBL struct IPlayUI1ManagerHandler2Vtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IPlayUI1ManagerHandler2_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IPlayUI1ManagerHandler2_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IPlayUI1ManagerHandler2_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IPlayUI1ManagerHandler2_OnTLPreLoad(This,pTimeLine,filename,pStg)	\
    (This)->lpVtbl -> OnTLPreLoad(This,pTimeLine,filename,pStg)

#define IPlayUI1ManagerHandler2_OnTLPostLoad(This,pTimeLine,filename,pStg)	\
    (This)->lpVtbl -> OnTLPostLoad(This,pTimeLine,filename,pStg)

#define IPlayUI1ManagerHandler2_OnTLPreViewRemoval(This,pTimeLine)	\
    (This)->lpVtbl -> OnTLPreViewRemoval(This,pTimeLine)

#define IPlayUI1ManagerHandler2_OnTLPostViewRemoval(This,pTimeLine)	\
    (This)->lpVtbl -> OnTLPostViewRemoval(This,pTimeLine)

#define IPlayUI1ManagerHandler2_OnTLPreSave(This,pTimeLine,pStg)	\
    (This)->lpVtbl -> OnTLPreSave(This,pTimeLine,pStg)

#define IPlayUI1ManagerHandler2_OnTLPostSave(This,pTimeLine,pStg)	\
    (This)->lpVtbl -> OnTLPostSave(This,pTimeLine,pStg)

#define IPlayUI1ManagerHandler2_OnAppActivate(This,bActive)	\
    (This)->lpVtbl -> OnAppActivate(This,bActive)


#define IPlayUI1ManagerHandler2_OnShowWindow(This,pWnd,bShow,dwReason)	\
    (This)->lpVtbl -> OnShowWindow(This,pWnd,bShow,dwReason)

#define IPlayUI1ManagerHandler2_OnPreLoadLayout(This,pManager,pszLayoutFile)	\
    (This)->lpVtbl -> OnPreLoadLayout(This,pManager,pszLayoutFile)

#define IPlayUI1ManagerHandler2_OnPostLoadLayout(This,pManager,pszLayoutFile)	\
    (This)->lpVtbl -> OnPostLoadLayout(This,pManager,pszLayoutFile)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE IPlayUI1ManagerHandler2_OnShowWindow_Proxy( 
    IPlayUI1ManagerHandler2 __RPC_FAR * This,
    IPlayUI1Window __RPC_FAR *pWnd,
    BOOL bShow,
    DWORD dwReason);


void __RPC_STUB IPlayUI1ManagerHandler2_OnShowWindow_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IPlayUI1ManagerHandler2_OnPreLoadLayout_Proxy( 
    IPlayUI1ManagerHandler2 __RPC_FAR * This,
    IPlayUI1Manager2 __RPC_FAR *pManager,
    LPSTR pszLayoutFile);


void __RPC_STUB IPlayUI1ManagerHandler2_OnPreLoadLayout_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IPlayUI1ManagerHandler2_OnPostLoadLayout_Proxy( 
    IPlayUI1ManagerHandler2 __RPC_FAR * This,
    IPlayUI1Manager2 __RPC_FAR *pManager,
    LPSTR pszLayoutFile);


void __RPC_STUB IPlayUI1ManagerHandler2_OnPostLoadLayout_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IPlayUI1ManagerHandler2_INTERFACE_DEFINED__ */


#ifndef __IPlayUI1ColorWindow_INTERFACE_DEFINED__
#define __IPlayUI1ColorWindow_INTERFACE_DEFINED__

/****************************************
 * Generated header for interface: IPlayUI1ColorWindow
 * at Tue Nov 23 05:02:14 1999
 * using MIDL 3.01.75
 ****************************************/
/* [unique][uuid][object][local] */ 



EXTERN_C const IID IID_IPlayUI1ColorWindow;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    interface DECLSPEC_UUID("8335e450-ab3b-11ce-8468-0000b468276b")
    IPlayUI1ColorWindow : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE SetColor( 
            IPlayColor __RPC_FAR *pcolor) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetHandler( 
            IPlayUI1ColorWndHandler __RPC_FAR *pHandler) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IPlayUI1ColorWindowVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            IPlayUI1ColorWindow __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            IPlayUI1ColorWindow __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            IPlayUI1ColorWindow __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetColor )( 
            IPlayUI1ColorWindow __RPC_FAR * This,
            IPlayColor __RPC_FAR *pcolor);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetHandler )( 
            IPlayUI1ColorWindow __RPC_FAR * This,
            IPlayUI1ColorWndHandler __RPC_FAR *pHandler);
        
        END_INTERFACE
    } IPlayUI1ColorWindowVtbl;

    interface IPlayUI1ColorWindow
    {
        CONST_VTBL struct IPlayUI1ColorWindowVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IPlayUI1ColorWindow_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IPlayUI1ColorWindow_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IPlayUI1ColorWindow_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IPlayUI1ColorWindow_SetColor(This,pcolor)	\
    (This)->lpVtbl -> SetColor(This,pcolor)

#define IPlayUI1ColorWindow_SetHandler(This,pHandler)	\
    (This)->lpVtbl -> SetHandler(This,pHandler)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE IPlayUI1ColorWindow_SetColor_Proxy( 
    IPlayUI1ColorWindow __RPC_FAR * This,
    IPlayColor __RPC_FAR *pcolor);


void __RPC_STUB IPlayUI1ColorWindow_SetColor_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IPlayUI1ColorWindow_SetHandler_Proxy( 
    IPlayUI1ColorWindow __RPC_FAR * This,
    IPlayUI1ColorWndHandler __RPC_FAR *pHandler);


void __RPC_STUB IPlayUI1ColorWindow_SetHandler_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IPlayUI1ColorWindow_INTERFACE_DEFINED__ */


#ifndef __IPlayUI1ColorWndHandler_INTERFACE_DEFINED__
#define __IPlayUI1ColorWndHandler_INTERFACE_DEFINED__

/****************************************
 * Generated header for interface: IPlayUI1ColorWndHandler
 * at Tue Nov 23 05:02:14 1999
 * using MIDL 3.01.75
 ****************************************/
/* [unique][uuid][object][local] */ 



EXTERN_C const IID IID_IPlayUI1ColorWndHandler;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    interface DECLSPEC_UUID("8335e452-ab3b-11ce-8468-0000b468276b")
    IPlayUI1ColorWndHandler : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE OnClose( 
            IPlayColor __RPC_FAR *pcolor) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE OnColorChange( 
            IPlayColor __RPC_FAR *pcolor) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE OnTypeChange( 
            IPlayColor __RPC_FAR *pcolor,
            EPlayColorSpread type) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IPlayUI1ColorWndHandlerVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            IPlayUI1ColorWndHandler __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            IPlayUI1ColorWndHandler __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            IPlayUI1ColorWndHandler __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *OnClose )( 
            IPlayUI1ColorWndHandler __RPC_FAR * This,
            IPlayColor __RPC_FAR *pcolor);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *OnColorChange )( 
            IPlayUI1ColorWndHandler __RPC_FAR * This,
            IPlayColor __RPC_FAR *pcolor);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *OnTypeChange )( 
            IPlayUI1ColorWndHandler __RPC_FAR * This,
            IPlayColor __RPC_FAR *pcolor,
            EPlayColorSpread type);
        
        END_INTERFACE
    } IPlayUI1ColorWndHandlerVtbl;

    interface IPlayUI1ColorWndHandler
    {
        CONST_VTBL struct IPlayUI1ColorWndHandlerVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IPlayUI1ColorWndHandler_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IPlayUI1ColorWndHandler_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IPlayUI1ColorWndHandler_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IPlayUI1ColorWndHandler_OnClose(This,pcolor)	\
    (This)->lpVtbl -> OnClose(This,pcolor)

#define IPlayUI1ColorWndHandler_OnColorChange(This,pcolor)	\
    (This)->lpVtbl -> OnColorChange(This,pcolor)

#define IPlayUI1ColorWndHandler_OnTypeChange(This,pcolor,type)	\
    (This)->lpVtbl -> OnTypeChange(This,pcolor,type)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE IPlayUI1ColorWndHandler_OnClose_Proxy( 
    IPlayUI1ColorWndHandler __RPC_FAR * This,
    IPlayColor __RPC_FAR *pcolor);


void __RPC_STUB IPlayUI1ColorWndHandler_OnClose_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IPlayUI1ColorWndHandler_OnColorChange_Proxy( 
    IPlayUI1ColorWndHandler __RPC_FAR * This,
    IPlayColor __RPC_FAR *pcolor);


void __RPC_STUB IPlayUI1ColorWndHandler_OnColorChange_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IPlayUI1ColorWndHandler_OnTypeChange_Proxy( 
    IPlayUI1ColorWndHandler __RPC_FAR * This,
    IPlayColor __RPC_FAR *pcolor,
    EPlayColorSpread type);


void __RPC_STUB IPlayUI1ColorWndHandler_OnTypeChange_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IPlayUI1ColorWndHandler_INTERFACE_DEFINED__ */


#ifndef __IPlayFontWindow_INTERFACE_DEFINED__
#define __IPlayFontWindow_INTERFACE_DEFINED__

/****************************************
 * Generated header for interface: IPlayFontWindow
 * at Tue Nov 23 05:02:14 1999
 * using MIDL 3.01.75
 ****************************************/
/* [unique][uuid][object][local] */ 



EXTERN_C const IID IID_IPlayFontWindow;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    interface DECLSPEC_UUID("8335e7e3-ab3b-11ce-8468-0000b468276b")
    IPlayFontWindow : public IUnknown
    {
    public:
        virtual HRESULT __stdcall SetFontType( 
            /* [in] */ DWORD dwType) = 0;
        
        virtual HRESULT __stdcall SetFont( 
            /* [string] */ LPSTR szName,
            /* [in] */ DWORD dwSize,
            /* [in] */ DWORD dwStyle) = 0;
        
        virtual HRESULT __stdcall GetFontName( 
            /* [string] */ LPSTR pszValue,
            long cMaxChar) = 0;
        
        virtual HRESULT __stdcall GetFontSize( 
            /* [out] */ long __RPC_FAR *plValue) = 0;
        
        virtual HRESULT __stdcall GetFontStyle( 
            /* [out] */ DWORD __RPC_FAR *pdwValue) = 0;
        
        virtual HRESULT __stdcall SetHandler( 
            /* [in] */ IPlayFontWindowHandler __RPC_FAR *pHandler) = 0;
        
        virtual HRESULT __stdcall Enable( 
            /* [in] */ DWORD dwControl,
            /* [in] */ BOOL bEnableFlag) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IPlayFontWindowVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            IPlayFontWindow __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            IPlayFontWindow __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            IPlayFontWindow __RPC_FAR * This);
        
        HRESULT ( __stdcall __RPC_FAR *SetFontType )( 
            IPlayFontWindow __RPC_FAR * This,
            /* [in] */ DWORD dwType);
        
        HRESULT ( __stdcall __RPC_FAR *SetFont )( 
            IPlayFontWindow __RPC_FAR * This,
            /* [string] */ LPSTR szName,
            /* [in] */ DWORD dwSize,
            /* [in] */ DWORD dwStyle);
        
        HRESULT ( __stdcall __RPC_FAR *GetFontName )( 
            IPlayFontWindow __RPC_FAR * This,
            /* [string] */ LPSTR pszValue,
            long cMaxChar);
        
        HRESULT ( __stdcall __RPC_FAR *GetFontSize )( 
            IPlayFontWindow __RPC_FAR * This,
            /* [out] */ long __RPC_FAR *plValue);
        
        HRESULT ( __stdcall __RPC_FAR *GetFontStyle )( 
            IPlayFontWindow __RPC_FAR * This,
            /* [out] */ DWORD __RPC_FAR *pdwValue);
        
        HRESULT ( __stdcall __RPC_FAR *SetHandler )( 
            IPlayFontWindow __RPC_FAR * This,
            /* [in] */ IPlayFontWindowHandler __RPC_FAR *pHandler);
        
        HRESULT ( __stdcall __RPC_FAR *Enable )( 
            IPlayFontWindow __RPC_FAR * This,
            /* [in] */ DWORD dwControl,
            /* [in] */ BOOL bEnableFlag);
        
        END_INTERFACE
    } IPlayFontWindowVtbl;

    interface IPlayFontWindow
    {
        CONST_VTBL struct IPlayFontWindowVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IPlayFontWindow_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IPlayFontWindow_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IPlayFontWindow_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IPlayFontWindow_SetFontType(This,dwType)	\
    (This)->lpVtbl -> SetFontType(This,dwType)

#define IPlayFontWindow_SetFont(This,szName,dwSize,dwStyle)	\
    (This)->lpVtbl -> SetFont(This,szName,dwSize,dwStyle)

#define IPlayFontWindow_GetFontName(This,pszValue,cMaxChar)	\
    (This)->lpVtbl -> GetFontName(This,pszValue,cMaxChar)

#define IPlayFontWindow_GetFontSize(This,plValue)	\
    (This)->lpVtbl -> GetFontSize(This,plValue)

#define IPlayFontWindow_GetFontStyle(This,pdwValue)	\
    (This)->lpVtbl -> GetFontStyle(This,pdwValue)

#define IPlayFontWindow_SetHandler(This,pHandler)	\
    (This)->lpVtbl -> SetHandler(This,pHandler)

#define IPlayFontWindow_Enable(This,dwControl,bEnableFlag)	\
    (This)->lpVtbl -> Enable(This,dwControl,bEnableFlag)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT __stdcall IPlayFontWindow_SetFontType_Proxy( 
    IPlayFontWindow __RPC_FAR * This,
    /* [in] */ DWORD dwType);


void __RPC_STUB IPlayFontWindow_SetFontType_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT __stdcall IPlayFontWindow_SetFont_Proxy( 
    IPlayFontWindow __RPC_FAR * This,
    /* [string] */ LPSTR szName,
    /* [in] */ DWORD dwSize,
    /* [in] */ DWORD dwStyle);


void __RPC_STUB IPlayFontWindow_SetFont_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT __stdcall IPlayFontWindow_GetFontName_Proxy( 
    IPlayFontWindow __RPC_FAR * This,
    /* [string] */ LPSTR pszValue,
    long cMaxChar);


void __RPC_STUB IPlayFontWindow_GetFontName_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT __stdcall IPlayFontWindow_GetFontSize_Proxy( 
    IPlayFontWindow __RPC_FAR * This,
    /* [out] */ long __RPC_FAR *plValue);


void __RPC_STUB IPlayFontWindow_GetFontSize_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT __stdcall IPlayFontWindow_GetFontStyle_Proxy( 
    IPlayFontWindow __RPC_FAR * This,
    /* [out] */ DWORD __RPC_FAR *pdwValue);


void __RPC_STUB IPlayFontWindow_GetFontStyle_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT __stdcall IPlayFontWindow_SetHandler_Proxy( 
    IPlayFontWindow __RPC_FAR * This,
    /* [in] */ IPlayFontWindowHandler __RPC_FAR *pHandler);


void __RPC_STUB IPlayFontWindow_SetHandler_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT __stdcall IPlayFontWindow_Enable_Proxy( 
    IPlayFontWindow __RPC_FAR * This,
    /* [in] */ DWORD dwControl,
    /* [in] */ BOOL bEnableFlag);


void __RPC_STUB IPlayFontWindow_Enable_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IPlayFontWindow_INTERFACE_DEFINED__ */


#ifndef __IPlayFontWindowHandler_INTERFACE_DEFINED__
#define __IPlayFontWindowHandler_INTERFACE_DEFINED__

/****************************************
 * Generated header for interface: IPlayFontWindowHandler
 * at Tue Nov 23 05:02:14 1999
 * using MIDL 3.01.75
 ****************************************/
/* [unique][uuid][object][local] */ 



EXTERN_C const IID IID_IPlayFontWindowHandler;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    interface DECLSPEC_UUID("8335e7e4-ab3b-11ce-8468-0000b468276b")
    IPlayFontWindowHandler : public IUnknown
    {
    public:
        virtual HRESULT __stdcall OnClose( void) = 0;
        
        virtual HRESULT __stdcall OnFontChange( 
            /* [string] */ LPSTR pszName,
            /* [out] */ int __RPC_FAR *pSize,
            /* [out] */ DWORD __RPC_FAR *pdwStyle) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IPlayFontWindowHandlerVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            IPlayFontWindowHandler __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            IPlayFontWindowHandler __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            IPlayFontWindowHandler __RPC_FAR * This);
        
        HRESULT ( __stdcall __RPC_FAR *OnClose )( 
            IPlayFontWindowHandler __RPC_FAR * This);
        
        HRESULT ( __stdcall __RPC_FAR *OnFontChange )( 
            IPlayFontWindowHandler __RPC_FAR * This,
            /* [string] */ LPSTR pszName,
            /* [out] */ int __RPC_FAR *pSize,
            /* [out] */ DWORD __RPC_FAR *pdwStyle);
        
        END_INTERFACE
    } IPlayFontWindowHandlerVtbl;

    interface IPlayFontWindowHandler
    {
        CONST_VTBL struct IPlayFontWindowHandlerVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IPlayFontWindowHandler_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IPlayFontWindowHandler_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IPlayFontWindowHandler_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IPlayFontWindowHandler_OnClose(This)	\
    (This)->lpVtbl -> OnClose(This)

#define IPlayFontWindowHandler_OnFontChange(This,pszName,pSize,pdwStyle)	\
    (This)->lpVtbl -> OnFontChange(This,pszName,pSize,pdwStyle)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT __stdcall IPlayFontWindowHandler_OnClose_Proxy( 
    IPlayFontWindowHandler __RPC_FAR * This);


void __RPC_STUB IPlayFontWindowHandler_OnClose_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT __stdcall IPlayFontWindowHandler_OnFontChange_Proxy( 
    IPlayFontWindowHandler __RPC_FAR * This,
    /* [string] */ LPSTR pszName,
    /* [out] */ int __RPC_FAR *pSize,
    /* [out] */ DWORD __RPC_FAR *pdwStyle);


void __RPC_STUB IPlayFontWindowHandler_OnFontChange_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IPlayFontWindowHandler_INTERFACE_DEFINED__ */


/* Additional Prototypes for ALL interfaces */

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif
