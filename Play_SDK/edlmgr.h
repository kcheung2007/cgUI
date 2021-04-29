/* this ALWAYS GENERATED file contains the definitions for the interfaces */


/* File created by MIDL compiler version 3.01.75 */
/* at Mon Jul 26 11:38:55 1999
 */
/* Compiler settings for edlmgr.idl:
    Os (OptLev=s), W1, Zp8, env=Win32, ms_ext, c_ext
    error checks: none
*/
//@@MIDL_FILE_HEADING(  )
#include "rpc.h"
#include "rpcndr.h"
#ifndef COM_NO_WINDOWS_H
#include "windows.h"
#include "ole2.h"
#endif /*COM_NO_WINDOWS_H*/

#ifndef __edlmgr_h__
#define __edlmgr_h__

#ifdef __cplusplus
extern "C"{
#endif 

/* Forward Declarations */ 

#ifndef __ICEdlManager_FWD_DEFINED__
#define __ICEdlManager_FWD_DEFINED__
typedef interface ICEdlManager ICEdlManager;
#endif 	/* __ICEdlManager_FWD_DEFINED__ */


#ifndef ___ICEdlManagerEvents_FWD_DEFINED__
#define ___ICEdlManagerEvents_FWD_DEFINED__
typedef interface _ICEdlManagerEvents _ICEdlManagerEvents;
#endif 	/* ___ICEdlManagerEvents_FWD_DEFINED__ */


#ifndef __CEdlManager_FWD_DEFINED__
#define __CEdlManager_FWD_DEFINED__

#ifdef __cplusplus
typedef class CEdlManager CEdlManager;
#else
typedef struct CEdlManager CEdlManager;
#endif /* __cplusplus */

#endif 	/* __CEdlManager_FWD_DEFINED__ */


/* header files for imported files */
#include "oaidl.h"
#include "ocidl.h"

void __RPC_FAR * __RPC_USER MIDL_user_allocate(size_t);
void __RPC_USER MIDL_user_free( void __RPC_FAR * ); 

#ifndef __ICEdlManager_INTERFACE_DEFINED__
#define __ICEdlManager_INTERFACE_DEFINED__

/****************************************
 * Generated header for interface: ICEdlManager
 * at Mon Jul 26 11:38:55 1999
 * using MIDL 3.01.75
 ****************************************/
/* [unique][helpstring][uuid][object] */ 



EXTERN_C const IID IID_ICEdlManager;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    interface DECLSPEC_UUID("31FDC9C0-3892-11D3-B409-0060081C257E")
    ICEdlManager : public IUnknown
    {
    public:
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE Init( void) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE Read( 
            /* [in] */ BSTR filename,
            /* [in] */ IUnknown __RPC_FAR *pUnk) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE Write( 
            /* [in] */ BSTR filename,
            /* [in] */ BSTR type,
            /* [in] */ IUnknown __RPC_FAR *pUnk) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct ICEdlManagerVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            ICEdlManager __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            ICEdlManager __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            ICEdlManager __RPC_FAR * This);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Init )( 
            ICEdlManager __RPC_FAR * This);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Read )( 
            ICEdlManager __RPC_FAR * This,
            /* [in] */ BSTR filename,
            /* [in] */ IUnknown __RPC_FAR *pUnk);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Write )( 
            ICEdlManager __RPC_FAR * This,
            /* [in] */ BSTR filename,
            /* [in] */ BSTR type,
            /* [in] */ IUnknown __RPC_FAR *pUnk);
        
        END_INTERFACE
    } ICEdlManagerVtbl;

    interface ICEdlManager
    {
        CONST_VTBL struct ICEdlManagerVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ICEdlManager_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define ICEdlManager_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define ICEdlManager_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define ICEdlManager_Init(This)	\
    (This)->lpVtbl -> Init(This)

#define ICEdlManager_Read(This,filename,pUnk)	\
    (This)->lpVtbl -> Read(This,filename,pUnk)

#define ICEdlManager_Write(This,filename,type,pUnk)	\
    (This)->lpVtbl -> Write(This,filename,type,pUnk)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [helpstring] */ HRESULT STDMETHODCALLTYPE ICEdlManager_Init_Proxy( 
    ICEdlManager __RPC_FAR * This);


void __RPC_STUB ICEdlManager_Init_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring] */ HRESULT STDMETHODCALLTYPE ICEdlManager_Read_Proxy( 
    ICEdlManager __RPC_FAR * This,
    /* [in] */ BSTR filename,
    /* [in] */ IUnknown __RPC_FAR *pUnk);


void __RPC_STUB ICEdlManager_Read_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring] */ HRESULT STDMETHODCALLTYPE ICEdlManager_Write_Proxy( 
    ICEdlManager __RPC_FAR * This,
    /* [in] */ BSTR filename,
    /* [in] */ BSTR type,
    /* [in] */ IUnknown __RPC_FAR *pUnk);


void __RPC_STUB ICEdlManager_Write_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __ICEdlManager_INTERFACE_DEFINED__ */



#ifndef __EDLMGRLib_LIBRARY_DEFINED__
#define __EDLMGRLib_LIBRARY_DEFINED__

/****************************************
 * Generated header for library: EDLMGRLib
 * at Mon Jul 26 11:38:55 1999
 * using MIDL 3.01.75
 ****************************************/
/* [helpstring][version][uuid] */ 



EXTERN_C const IID LIBID_EDLMGRLib;

#ifndef ___ICEdlManagerEvents_DISPINTERFACE_DEFINED__
#define ___ICEdlManagerEvents_DISPINTERFACE_DEFINED__

/****************************************
 * Generated header for dispinterface: _ICEdlManagerEvents
 * at Mon Jul 26 11:38:55 1999
 * using MIDL 3.01.75
 ****************************************/
/* [helpstring][uuid] */ 



EXTERN_C const IID DIID__ICEdlManagerEvents;

#if defined(__cplusplus) && !defined(CINTERFACE)

    interface DECLSPEC_UUID("31FDC9C2-3892-11D3-B409-0060081C257E")
    _ICEdlManagerEvents : public IDispatch
    {
    };
    
#else 	/* C style interface */

    typedef struct _ICEdlManagerEventsVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            _ICEdlManagerEvents __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            _ICEdlManagerEvents __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            _ICEdlManagerEvents __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfoCount )( 
            _ICEdlManagerEvents __RPC_FAR * This,
            /* [out] */ UINT __RPC_FAR *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfo )( 
            _ICEdlManagerEvents __RPC_FAR * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo __RPC_FAR *__RPC_FAR *ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetIDsOfNames )( 
            _ICEdlManagerEvents __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR __RPC_FAR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID __RPC_FAR *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Invoke )( 
            _ICEdlManagerEvents __RPC_FAR * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS __RPC_FAR *pDispParams,
            /* [out] */ VARIANT __RPC_FAR *pVarResult,
            /* [out] */ EXCEPINFO __RPC_FAR *pExcepInfo,
            /* [out] */ UINT __RPC_FAR *puArgErr);
        
        END_INTERFACE
    } _ICEdlManagerEventsVtbl;

    interface _ICEdlManagerEvents
    {
        CONST_VTBL struct _ICEdlManagerEventsVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define _ICEdlManagerEvents_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define _ICEdlManagerEvents_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define _ICEdlManagerEvents_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define _ICEdlManagerEvents_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define _ICEdlManagerEvents_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define _ICEdlManagerEvents_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define _ICEdlManagerEvents_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)

#endif /* COBJMACROS */


#endif 	/* C style interface */


#endif 	/* ___ICEdlManagerEvents_DISPINTERFACE_DEFINED__ */


#ifdef __cplusplus
EXTERN_C const CLSID CLSID_CEdlManager;

class DECLSPEC_UUID("31FDC9C1-3892-11D3-B409-0060081C257E")
CEdlManager;
#endif
#endif /* __EDLMGRLib_LIBRARY_DEFINED__ */

/* Additional Prototypes for ALL interfaces */

unsigned long             __RPC_USER  BSTR_UserSize(     unsigned long __RPC_FAR *, unsigned long            , BSTR __RPC_FAR * ); 
unsigned char __RPC_FAR * __RPC_USER  BSTR_UserMarshal(  unsigned long __RPC_FAR *, unsigned char __RPC_FAR *, BSTR __RPC_FAR * ); 
unsigned char __RPC_FAR * __RPC_USER  BSTR_UserUnmarshal(unsigned long __RPC_FAR *, unsigned char __RPC_FAR *, BSTR __RPC_FAR * ); 
void                      __RPC_USER  BSTR_UserFree(     unsigned long __RPC_FAR *, BSTR __RPC_FAR * ); 

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif
