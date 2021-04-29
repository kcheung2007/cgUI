/* this ALWAYS GENERATED file contains the definitions for the interfaces */


/* File created by MIDL compiler version 3.01.75 */
/* at Tue Nov 23 05:02:11 1999
 */
/* Compiler settings for pcadvs.idl:
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

#ifndef __pcadvs_h__
#define __pcadvs_h__

#ifdef __cplusplus
extern "C"{
#endif 

/* Forward Declarations */ 

#ifndef __IPCtrlAdviseSink_FWD_DEFINED__
#define __IPCtrlAdviseSink_FWD_DEFINED__
typedef interface IPCtrlAdviseSink IPCtrlAdviseSink;
#endif 	/* __IPCtrlAdviseSink_FWD_DEFINED__ */


#ifndef __IPCtrlAdviseSink2_FWD_DEFINED__
#define __IPCtrlAdviseSink2_FWD_DEFINED__
typedef interface IPCtrlAdviseSink2 IPCtrlAdviseSink2;
#endif 	/* __IPCtrlAdviseSink2_FWD_DEFINED__ */


/* header files for imported files */
#include "unknwn.h"
#include "plyctl.h"

void __RPC_FAR * __RPC_USER MIDL_user_allocate(size_t);
void __RPC_USER MIDL_user_free( void __RPC_FAR * ); 

#ifndef __IPCtrlAdviseSink_INTERFACE_DEFINED__
#define __IPCtrlAdviseSink_INTERFACE_DEFINED__

/****************************************
 * Generated header for interface: IPCtrlAdviseSink
 * at Tue Nov 23 05:02:11 1999
 * using MIDL 3.01.75
 ****************************************/
/* [uuid][object][local] */ 



EXTERN_C const IID IID_IPCtrlAdviseSink;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    interface DECLSPEC_UUID("8335e422-ab3b-11ce-8468-0000b468276b")
    IPCtrlAdviseSink : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE OnCtlDown( 
            /* [in] */ IPlayControl __RPC_FAR *pPlayCtl) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE OnCtlMove( 
            /* [in] */ IPlayControl __RPC_FAR *pPlayCtl) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE OnCtlUp( 
            /* [in] */ IPlayControl __RPC_FAR *pPlayCtl) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE OnLBtnUp( 
            /* [in] */ IPlayControl __RPC_FAR *pPlayCtl) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE OnLBtnDown( 
            /* [in] */ IPlayControl __RPC_FAR *pPlayCtl) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE OnRBtnUp( 
            /* [in] */ IPlayControl __RPC_FAR *pPlayCtl) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE OnRBtnDown( 
            /* [in] */ IPlayControl __RPC_FAR *pPlayCtl) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE OnMouseMove( 
            /* [in] */ IPlayControl __RPC_FAR *pPlayCtl,
            WPARAM wParam,
            LPARAM lParam) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE OnDropFiles( 
            /* [in] */ IPlayControl __RPC_FAR *pPlayCtl,
            WPARAM wParam,
            LPARAM lParam) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IPCtrlAdviseSinkVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            IPCtrlAdviseSink __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            IPCtrlAdviseSink __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            IPCtrlAdviseSink __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *OnCtlDown )( 
            IPCtrlAdviseSink __RPC_FAR * This,
            /* [in] */ IPlayControl __RPC_FAR *pPlayCtl);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *OnCtlMove )( 
            IPCtrlAdviseSink __RPC_FAR * This,
            /* [in] */ IPlayControl __RPC_FAR *pPlayCtl);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *OnCtlUp )( 
            IPCtrlAdviseSink __RPC_FAR * This,
            /* [in] */ IPlayControl __RPC_FAR *pPlayCtl);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *OnLBtnUp )( 
            IPCtrlAdviseSink __RPC_FAR * This,
            /* [in] */ IPlayControl __RPC_FAR *pPlayCtl);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *OnLBtnDown )( 
            IPCtrlAdviseSink __RPC_FAR * This,
            /* [in] */ IPlayControl __RPC_FAR *pPlayCtl);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *OnRBtnUp )( 
            IPCtrlAdviseSink __RPC_FAR * This,
            /* [in] */ IPlayControl __RPC_FAR *pPlayCtl);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *OnRBtnDown )( 
            IPCtrlAdviseSink __RPC_FAR * This,
            /* [in] */ IPlayControl __RPC_FAR *pPlayCtl);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *OnMouseMove )( 
            IPCtrlAdviseSink __RPC_FAR * This,
            /* [in] */ IPlayControl __RPC_FAR *pPlayCtl,
            WPARAM wParam,
            LPARAM lParam);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *OnDropFiles )( 
            IPCtrlAdviseSink __RPC_FAR * This,
            /* [in] */ IPlayControl __RPC_FAR *pPlayCtl,
            WPARAM wParam,
            LPARAM lParam);
        
        END_INTERFACE
    } IPCtrlAdviseSinkVtbl;

    interface IPCtrlAdviseSink
    {
        CONST_VTBL struct IPCtrlAdviseSinkVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IPCtrlAdviseSink_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IPCtrlAdviseSink_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IPCtrlAdviseSink_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IPCtrlAdviseSink_OnCtlDown(This,pPlayCtl)	\
    (This)->lpVtbl -> OnCtlDown(This,pPlayCtl)

#define IPCtrlAdviseSink_OnCtlMove(This,pPlayCtl)	\
    (This)->lpVtbl -> OnCtlMove(This,pPlayCtl)

#define IPCtrlAdviseSink_OnCtlUp(This,pPlayCtl)	\
    (This)->lpVtbl -> OnCtlUp(This,pPlayCtl)

#define IPCtrlAdviseSink_OnLBtnUp(This,pPlayCtl)	\
    (This)->lpVtbl -> OnLBtnUp(This,pPlayCtl)

#define IPCtrlAdviseSink_OnLBtnDown(This,pPlayCtl)	\
    (This)->lpVtbl -> OnLBtnDown(This,pPlayCtl)

#define IPCtrlAdviseSink_OnRBtnUp(This,pPlayCtl)	\
    (This)->lpVtbl -> OnRBtnUp(This,pPlayCtl)

#define IPCtrlAdviseSink_OnRBtnDown(This,pPlayCtl)	\
    (This)->lpVtbl -> OnRBtnDown(This,pPlayCtl)

#define IPCtrlAdviseSink_OnMouseMove(This,pPlayCtl,wParam,lParam)	\
    (This)->lpVtbl -> OnMouseMove(This,pPlayCtl,wParam,lParam)

#define IPCtrlAdviseSink_OnDropFiles(This,pPlayCtl,wParam,lParam)	\
    (This)->lpVtbl -> OnDropFiles(This,pPlayCtl,wParam,lParam)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE IPCtrlAdviseSink_OnCtlDown_Proxy( 
    IPCtrlAdviseSink __RPC_FAR * This,
    /* [in] */ IPlayControl __RPC_FAR *pPlayCtl);


void __RPC_STUB IPCtrlAdviseSink_OnCtlDown_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IPCtrlAdviseSink_OnCtlMove_Proxy( 
    IPCtrlAdviseSink __RPC_FAR * This,
    /* [in] */ IPlayControl __RPC_FAR *pPlayCtl);


void __RPC_STUB IPCtrlAdviseSink_OnCtlMove_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IPCtrlAdviseSink_OnCtlUp_Proxy( 
    IPCtrlAdviseSink __RPC_FAR * This,
    /* [in] */ IPlayControl __RPC_FAR *pPlayCtl);


void __RPC_STUB IPCtrlAdviseSink_OnCtlUp_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IPCtrlAdviseSink_OnLBtnUp_Proxy( 
    IPCtrlAdviseSink __RPC_FAR * This,
    /* [in] */ IPlayControl __RPC_FAR *pPlayCtl);


void __RPC_STUB IPCtrlAdviseSink_OnLBtnUp_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IPCtrlAdviseSink_OnLBtnDown_Proxy( 
    IPCtrlAdviseSink __RPC_FAR * This,
    /* [in] */ IPlayControl __RPC_FAR *pPlayCtl);


void __RPC_STUB IPCtrlAdviseSink_OnLBtnDown_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IPCtrlAdviseSink_OnRBtnUp_Proxy( 
    IPCtrlAdviseSink __RPC_FAR * This,
    /* [in] */ IPlayControl __RPC_FAR *pPlayCtl);


void __RPC_STUB IPCtrlAdviseSink_OnRBtnUp_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IPCtrlAdviseSink_OnRBtnDown_Proxy( 
    IPCtrlAdviseSink __RPC_FAR * This,
    /* [in] */ IPlayControl __RPC_FAR *pPlayCtl);


void __RPC_STUB IPCtrlAdviseSink_OnRBtnDown_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IPCtrlAdviseSink_OnMouseMove_Proxy( 
    IPCtrlAdviseSink __RPC_FAR * This,
    /* [in] */ IPlayControl __RPC_FAR *pPlayCtl,
    WPARAM wParam,
    LPARAM lParam);


void __RPC_STUB IPCtrlAdviseSink_OnMouseMove_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IPCtrlAdviseSink_OnDropFiles_Proxy( 
    IPCtrlAdviseSink __RPC_FAR * This,
    /* [in] */ IPlayControl __RPC_FAR *pPlayCtl,
    WPARAM wParam,
    LPARAM lParam);


void __RPC_STUB IPCtrlAdviseSink_OnDropFiles_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IPCtrlAdviseSink_INTERFACE_DEFINED__ */


#ifndef __IPCtrlAdviseSink2_INTERFACE_DEFINED__
#define __IPCtrlAdviseSink2_INTERFACE_DEFINED__

/****************************************
 * Generated header for interface: IPCtrlAdviseSink2
 * at Tue Nov 23 05:02:11 1999
 * using MIDL 3.01.75
 ****************************************/
/* [uuid][object][local] */ 



EXTERN_C const IID IID_IPCtrlAdviseSink2;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    interface DECLSPEC_UUID("8335e608-ab3b-11ce-8468-0000b468276b")
    IPCtrlAdviseSink2 : public IPCtrlAdviseSink
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE OnCtlCancel( 
            /* [in] */ IPlayControl __RPC_FAR *pPlayCtl) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IPCtrlAdviseSink2Vtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            IPCtrlAdviseSink2 __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            IPCtrlAdviseSink2 __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            IPCtrlAdviseSink2 __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *OnCtlDown )( 
            IPCtrlAdviseSink2 __RPC_FAR * This,
            /* [in] */ IPlayControl __RPC_FAR *pPlayCtl);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *OnCtlMove )( 
            IPCtrlAdviseSink2 __RPC_FAR * This,
            /* [in] */ IPlayControl __RPC_FAR *pPlayCtl);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *OnCtlUp )( 
            IPCtrlAdviseSink2 __RPC_FAR * This,
            /* [in] */ IPlayControl __RPC_FAR *pPlayCtl);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *OnLBtnUp )( 
            IPCtrlAdviseSink2 __RPC_FAR * This,
            /* [in] */ IPlayControl __RPC_FAR *pPlayCtl);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *OnLBtnDown )( 
            IPCtrlAdviseSink2 __RPC_FAR * This,
            /* [in] */ IPlayControl __RPC_FAR *pPlayCtl);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *OnRBtnUp )( 
            IPCtrlAdviseSink2 __RPC_FAR * This,
            /* [in] */ IPlayControl __RPC_FAR *pPlayCtl);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *OnRBtnDown )( 
            IPCtrlAdviseSink2 __RPC_FAR * This,
            /* [in] */ IPlayControl __RPC_FAR *pPlayCtl);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *OnMouseMove )( 
            IPCtrlAdviseSink2 __RPC_FAR * This,
            /* [in] */ IPlayControl __RPC_FAR *pPlayCtl,
            WPARAM wParam,
            LPARAM lParam);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *OnDropFiles )( 
            IPCtrlAdviseSink2 __RPC_FAR * This,
            /* [in] */ IPlayControl __RPC_FAR *pPlayCtl,
            WPARAM wParam,
            LPARAM lParam);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *OnCtlCancel )( 
            IPCtrlAdviseSink2 __RPC_FAR * This,
            /* [in] */ IPlayControl __RPC_FAR *pPlayCtl);
        
        END_INTERFACE
    } IPCtrlAdviseSink2Vtbl;

    interface IPCtrlAdviseSink2
    {
        CONST_VTBL struct IPCtrlAdviseSink2Vtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IPCtrlAdviseSink2_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IPCtrlAdviseSink2_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IPCtrlAdviseSink2_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IPCtrlAdviseSink2_OnCtlDown(This,pPlayCtl)	\
    (This)->lpVtbl -> OnCtlDown(This,pPlayCtl)

#define IPCtrlAdviseSink2_OnCtlMove(This,pPlayCtl)	\
    (This)->lpVtbl -> OnCtlMove(This,pPlayCtl)

#define IPCtrlAdviseSink2_OnCtlUp(This,pPlayCtl)	\
    (This)->lpVtbl -> OnCtlUp(This,pPlayCtl)

#define IPCtrlAdviseSink2_OnLBtnUp(This,pPlayCtl)	\
    (This)->lpVtbl -> OnLBtnUp(This,pPlayCtl)

#define IPCtrlAdviseSink2_OnLBtnDown(This,pPlayCtl)	\
    (This)->lpVtbl -> OnLBtnDown(This,pPlayCtl)

#define IPCtrlAdviseSink2_OnRBtnUp(This,pPlayCtl)	\
    (This)->lpVtbl -> OnRBtnUp(This,pPlayCtl)

#define IPCtrlAdviseSink2_OnRBtnDown(This,pPlayCtl)	\
    (This)->lpVtbl -> OnRBtnDown(This,pPlayCtl)

#define IPCtrlAdviseSink2_OnMouseMove(This,pPlayCtl,wParam,lParam)	\
    (This)->lpVtbl -> OnMouseMove(This,pPlayCtl,wParam,lParam)

#define IPCtrlAdviseSink2_OnDropFiles(This,pPlayCtl,wParam,lParam)	\
    (This)->lpVtbl -> OnDropFiles(This,pPlayCtl,wParam,lParam)


#define IPCtrlAdviseSink2_OnCtlCancel(This,pPlayCtl)	\
    (This)->lpVtbl -> OnCtlCancel(This,pPlayCtl)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE IPCtrlAdviseSink2_OnCtlCancel_Proxy( 
    IPCtrlAdviseSink2 __RPC_FAR * This,
    /* [in] */ IPlayControl __RPC_FAR *pPlayCtl);


void __RPC_STUB IPCtrlAdviseSink2_OnCtlCancel_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IPCtrlAdviseSink2_INTERFACE_DEFINED__ */


/* Additional Prototypes for ALL interfaces */

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif
