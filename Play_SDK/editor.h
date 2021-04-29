/* this ALWAYS GENERATED file contains the definitions for the interfaces */


/* File created by MIDL compiler version 3.01.75 */
/* at Tue Nov 23 05:28:29 1999
 */
/* Compiler settings for editor.idl:
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

#ifndef __editor_h__
#define __editor_h__

#ifdef __cplusplus
extern "C"{
#endif 

/* Forward Declarations */ 

#ifndef __IEditorTape_FWD_DEFINED__
#define __IEditorTape_FWD_DEFINED__
typedef interface IEditorTape IEditorTape;
#endif 	/* __IEditorTape_FWD_DEFINED__ */


#ifndef __IPlayEditorApp_FWD_DEFINED__
#define __IPlayEditorApp_FWD_DEFINED__
typedef interface IPlayEditorApp IPlayEditorApp;
#endif 	/* __IPlayEditorApp_FWD_DEFINED__ */


#ifndef __IPlayEditorInterface_FWD_DEFINED__
#define __IPlayEditorInterface_FWD_DEFINED__
typedef interface IPlayEditorInterface IPlayEditorInterface;
#endif 	/* __IPlayEditorInterface_FWD_DEFINED__ */


/* header files for imported files */
#include "gxlate.h"

void __RPC_FAR * __RPC_USER MIDL_user_allocate(size_t);
void __RPC_USER MIDL_user_free( void __RPC_FAR * ); 

/****************************************
 * Generated header for interface: __MIDL_itf_editor_0000
 * at Tue Nov 23 05:28:29 1999
 * using MIDL 3.01.75
 ****************************************/
/* [local] */ 



interface IPlayPanel;

interface IEditorDevice;

interface IPlayProperties;


extern RPC_IF_HANDLE __MIDL_itf_editor_0000_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_editor_0000_v0_0_s_ifspec;

#ifndef __IEditorTape_INTERFACE_DEFINED__
#define __IEditorTape_INTERFACE_DEFINED__

/****************************************
 * Generated header for interface: IEditorTape
 * at Tue Nov 23 05:28:29 1999
 * using MIDL 3.01.75
 ****************************************/
/* [uuid][object][local] */ 



EXTERN_C const IID IID_IEditorTape;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    interface DECLSPEC_UUID("8335e628-ab3b-11ce-8468-0000b468276b")
    IEditorTape : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE AddEditControls( 
            IPlayPanel __RPC_FAR *pPanel) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetProperties( 
            IPlayProperties __RPC_FAR *__RPC_FAR *ppProps) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetName( 
            LPSTR pszName,
            DWORD dwMaxChars) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetColor( 
            DWORD color) = 0;
        
        virtual DWORD STDMETHODCALLTYPE GetColor( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE EnableRecord( 
            BOOL bEnable) = 0;
        
        virtual BOOL STDMETHODCALLTYPE IsRecordable( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetName( 
            /* [string][in] */ LPSTR pszName) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IEditorTapeVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            IEditorTape __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            IEditorTape __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            IEditorTape __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *AddEditControls )( 
            IEditorTape __RPC_FAR * This,
            IPlayPanel __RPC_FAR *pPanel);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetProperties )( 
            IEditorTape __RPC_FAR * This,
            IPlayProperties __RPC_FAR *__RPC_FAR *ppProps);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetName )( 
            IEditorTape __RPC_FAR * This,
            LPSTR pszName,
            DWORD dwMaxChars);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetColor )( 
            IEditorTape __RPC_FAR * This,
            DWORD color);
        
        DWORD ( STDMETHODCALLTYPE __RPC_FAR *GetColor )( 
            IEditorTape __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *EnableRecord )( 
            IEditorTape __RPC_FAR * This,
            BOOL bEnable);
        
        BOOL ( STDMETHODCALLTYPE __RPC_FAR *IsRecordable )( 
            IEditorTape __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetName )( 
            IEditorTape __RPC_FAR * This,
            /* [string][in] */ LPSTR pszName);
        
        END_INTERFACE
    } IEditorTapeVtbl;

    interface IEditorTape
    {
        CONST_VTBL struct IEditorTapeVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IEditorTape_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IEditorTape_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IEditorTape_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IEditorTape_AddEditControls(This,pPanel)	\
    (This)->lpVtbl -> AddEditControls(This,pPanel)

#define IEditorTape_GetProperties(This,ppProps)	\
    (This)->lpVtbl -> GetProperties(This,ppProps)

#define IEditorTape_GetName(This,pszName,dwMaxChars)	\
    (This)->lpVtbl -> GetName(This,pszName,dwMaxChars)

#define IEditorTape_SetColor(This,color)	\
    (This)->lpVtbl -> SetColor(This,color)

#define IEditorTape_GetColor(This)	\
    (This)->lpVtbl -> GetColor(This)

#define IEditorTape_EnableRecord(This,bEnable)	\
    (This)->lpVtbl -> EnableRecord(This,bEnable)

#define IEditorTape_IsRecordable(This)	\
    (This)->lpVtbl -> IsRecordable(This)

#define IEditorTape_SetName(This,pszName)	\
    (This)->lpVtbl -> SetName(This,pszName)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE IEditorTape_AddEditControls_Proxy( 
    IEditorTape __RPC_FAR * This,
    IPlayPanel __RPC_FAR *pPanel);


void __RPC_STUB IEditorTape_AddEditControls_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IEditorTape_GetProperties_Proxy( 
    IEditorTape __RPC_FAR * This,
    IPlayProperties __RPC_FAR *__RPC_FAR *ppProps);


void __RPC_STUB IEditorTape_GetProperties_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IEditorTape_GetName_Proxy( 
    IEditorTape __RPC_FAR * This,
    LPSTR pszName,
    DWORD dwMaxChars);


void __RPC_STUB IEditorTape_GetName_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IEditorTape_SetColor_Proxy( 
    IEditorTape __RPC_FAR * This,
    DWORD color);


void __RPC_STUB IEditorTape_SetColor_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


DWORD STDMETHODCALLTYPE IEditorTape_GetColor_Proxy( 
    IEditorTape __RPC_FAR * This);


void __RPC_STUB IEditorTape_GetColor_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IEditorTape_EnableRecord_Proxy( 
    IEditorTape __RPC_FAR * This,
    BOOL bEnable);


void __RPC_STUB IEditorTape_EnableRecord_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


BOOL STDMETHODCALLTYPE IEditorTape_IsRecordable_Proxy( 
    IEditorTape __RPC_FAR * This);


void __RPC_STUB IEditorTape_IsRecordable_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IEditorTape_SetName_Proxy( 
    IEditorTape __RPC_FAR * This,
    /* [string][in] */ LPSTR pszName);


void __RPC_STUB IEditorTape_SetName_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IEditorTape_INTERFACE_DEFINED__ */


#ifndef __IPlayEditorApp_INTERFACE_DEFINED__
#define __IPlayEditorApp_INTERFACE_DEFINED__

/****************************************
 * Generated header for interface: IPlayEditorApp
 * at Tue Nov 23 05:28:29 1999
 * using MIDL 3.01.75
 ****************************************/
/* [uuid][object][local] */ 



EXTERN_C const IID IID_IPlayEditorApp;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    interface DECLSPEC_UUID("8335e62b-ab3b-11ce-8468-0000b468276b")
    IPlayEditorApp : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE Initialize( 
            BOOL bCreateUserInterface) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetErrorText( 
            LPSTR pszText,
            long lBufSize) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IPlayEditorAppVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            IPlayEditorApp __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            IPlayEditorApp __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            IPlayEditorApp __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Initialize )( 
            IPlayEditorApp __RPC_FAR * This,
            BOOL bCreateUserInterface);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetErrorText )( 
            IPlayEditorApp __RPC_FAR * This,
            LPSTR pszText,
            long lBufSize);
        
        END_INTERFACE
    } IPlayEditorAppVtbl;

    interface IPlayEditorApp
    {
        CONST_VTBL struct IPlayEditorAppVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IPlayEditorApp_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IPlayEditorApp_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IPlayEditorApp_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IPlayEditorApp_Initialize(This,bCreateUserInterface)	\
    (This)->lpVtbl -> Initialize(This,bCreateUserInterface)

#define IPlayEditorApp_GetErrorText(This,pszText,lBufSize)	\
    (This)->lpVtbl -> GetErrorText(This,pszText,lBufSize)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE IPlayEditorApp_Initialize_Proxy( 
    IPlayEditorApp __RPC_FAR * This,
    BOOL bCreateUserInterface);


void __RPC_STUB IPlayEditorApp_Initialize_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IPlayEditorApp_GetErrorText_Proxy( 
    IPlayEditorApp __RPC_FAR * This,
    LPSTR pszText,
    long lBufSize);


void __RPC_STUB IPlayEditorApp_GetErrorText_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IPlayEditorApp_INTERFACE_DEFINED__ */


#ifndef __IPlayEditorInterface_INTERFACE_DEFINED__
#define __IPlayEditorInterface_INTERFACE_DEFINED__

/****************************************
 * Generated header for interface: IPlayEditorInterface
 * at Tue Nov 23 05:28:29 1999
 * using MIDL 3.01.75
 ****************************************/
/* [uuid][object][local] */ 



EXTERN_C const IID IID_IPlayEditorInterface;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    interface DECLSPEC_UUID("8335e62c-ab3b-11ce-8468-0000b468276b")
    IPlayEditorInterface : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE ShowPosition( 
            /* [out][in] */ IEditorDevice __RPC_FAR *pDev,
            /* [in] */ DWORD dwTime) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE ShowInPoint( 
            /* [in] */ DWORD dwTime) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE ShowOutPoint( 
            /* [in] */ DWORD dwTime) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE ShowDuration( 
            /* [in] */ DWORD dwDur) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE ShowTapeName( 
            LPSTR pszName) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE EnableInterface( 
            BOOL bEnable) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE ShowTBarPosition( 
            DWORD field,
            DWORD scale) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE ShowColorSettings( 
            int iC1,
            int iC2,
            int iC3) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetEffectPicon( 
            SPlayBitMap __RPC_FAR *pPBM,
            HRESULT hr) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IPlayEditorInterfaceVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            IPlayEditorInterface __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            IPlayEditorInterface __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            IPlayEditorInterface __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *ShowPosition )( 
            IPlayEditorInterface __RPC_FAR * This,
            /* [out][in] */ IEditorDevice __RPC_FAR *pDev,
            /* [in] */ DWORD dwTime);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *ShowInPoint )( 
            IPlayEditorInterface __RPC_FAR * This,
            /* [in] */ DWORD dwTime);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *ShowOutPoint )( 
            IPlayEditorInterface __RPC_FAR * This,
            /* [in] */ DWORD dwTime);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *ShowDuration )( 
            IPlayEditorInterface __RPC_FAR * This,
            /* [in] */ DWORD dwDur);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *ShowTapeName )( 
            IPlayEditorInterface __RPC_FAR * This,
            LPSTR pszName);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *EnableInterface )( 
            IPlayEditorInterface __RPC_FAR * This,
            BOOL bEnable);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *ShowTBarPosition )( 
            IPlayEditorInterface __RPC_FAR * This,
            DWORD field,
            DWORD scale);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *ShowColorSettings )( 
            IPlayEditorInterface __RPC_FAR * This,
            int iC1,
            int iC2,
            int iC3);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetEffectPicon )( 
            IPlayEditorInterface __RPC_FAR * This,
            SPlayBitMap __RPC_FAR *pPBM,
            HRESULT hr);
        
        END_INTERFACE
    } IPlayEditorInterfaceVtbl;

    interface IPlayEditorInterface
    {
        CONST_VTBL struct IPlayEditorInterfaceVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IPlayEditorInterface_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IPlayEditorInterface_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IPlayEditorInterface_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IPlayEditorInterface_ShowPosition(This,pDev,dwTime)	\
    (This)->lpVtbl -> ShowPosition(This,pDev,dwTime)

#define IPlayEditorInterface_ShowInPoint(This,dwTime)	\
    (This)->lpVtbl -> ShowInPoint(This,dwTime)

#define IPlayEditorInterface_ShowOutPoint(This,dwTime)	\
    (This)->lpVtbl -> ShowOutPoint(This,dwTime)

#define IPlayEditorInterface_ShowDuration(This,dwDur)	\
    (This)->lpVtbl -> ShowDuration(This,dwDur)

#define IPlayEditorInterface_ShowTapeName(This,pszName)	\
    (This)->lpVtbl -> ShowTapeName(This,pszName)

#define IPlayEditorInterface_EnableInterface(This,bEnable)	\
    (This)->lpVtbl -> EnableInterface(This,bEnable)

#define IPlayEditorInterface_ShowTBarPosition(This,field,scale)	\
    (This)->lpVtbl -> ShowTBarPosition(This,field,scale)

#define IPlayEditorInterface_ShowColorSettings(This,iC1,iC2,iC3)	\
    (This)->lpVtbl -> ShowColorSettings(This,iC1,iC2,iC3)

#define IPlayEditorInterface_SetEffectPicon(This,pPBM,hr)	\
    (This)->lpVtbl -> SetEffectPicon(This,pPBM,hr)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE IPlayEditorInterface_ShowPosition_Proxy( 
    IPlayEditorInterface __RPC_FAR * This,
    /* [out][in] */ IEditorDevice __RPC_FAR *pDev,
    /* [in] */ DWORD dwTime);


void __RPC_STUB IPlayEditorInterface_ShowPosition_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IPlayEditorInterface_ShowInPoint_Proxy( 
    IPlayEditorInterface __RPC_FAR * This,
    /* [in] */ DWORD dwTime);


void __RPC_STUB IPlayEditorInterface_ShowInPoint_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IPlayEditorInterface_ShowOutPoint_Proxy( 
    IPlayEditorInterface __RPC_FAR * This,
    /* [in] */ DWORD dwTime);


void __RPC_STUB IPlayEditorInterface_ShowOutPoint_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IPlayEditorInterface_ShowDuration_Proxy( 
    IPlayEditorInterface __RPC_FAR * This,
    /* [in] */ DWORD dwDur);


void __RPC_STUB IPlayEditorInterface_ShowDuration_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IPlayEditorInterface_ShowTapeName_Proxy( 
    IPlayEditorInterface __RPC_FAR * This,
    LPSTR pszName);


void __RPC_STUB IPlayEditorInterface_ShowTapeName_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IPlayEditorInterface_EnableInterface_Proxy( 
    IPlayEditorInterface __RPC_FAR * This,
    BOOL bEnable);


void __RPC_STUB IPlayEditorInterface_EnableInterface_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IPlayEditorInterface_ShowTBarPosition_Proxy( 
    IPlayEditorInterface __RPC_FAR * This,
    DWORD field,
    DWORD scale);


void __RPC_STUB IPlayEditorInterface_ShowTBarPosition_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IPlayEditorInterface_ShowColorSettings_Proxy( 
    IPlayEditorInterface __RPC_FAR * This,
    int iC1,
    int iC2,
    int iC3);


void __RPC_STUB IPlayEditorInterface_ShowColorSettings_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IPlayEditorInterface_SetEffectPicon_Proxy( 
    IPlayEditorInterface __RPC_FAR * This,
    SPlayBitMap __RPC_FAR *pPBM,
    HRESULT hr);


void __RPC_STUB IPlayEditorInterface_SetEffectPicon_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IPlayEditorInterface_INTERFACE_DEFINED__ */


/* Additional Prototypes for ALL interfaces */

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif
