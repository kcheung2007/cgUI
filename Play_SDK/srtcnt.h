/* this ALWAYS GENERATED file contains the definitions for the interfaces */


/* File created by MIDL compiler version 3.01.75 */
/* at Tue Nov 23 05:28:35 1999
 */
/* Compiler settings for srtcnt.idl:
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

#ifndef __srtcnt_h__
#define __srtcnt_h__

#ifdef __cplusplus
extern "C"{
#endif 

/* Forward Declarations */ 

#ifndef __ISortedContainer_FWD_DEFINED__
#define __ISortedContainer_FWD_DEFINED__
typedef interface ISortedContainer ISortedContainer;
#endif 	/* __ISortedContainer_FWD_DEFINED__ */


#ifndef __IContainedObject_FWD_DEFINED__
#define __IContainedObject_FWD_DEFINED__
typedef interface IContainedObject IContainedObject;
#endif 	/* __IContainedObject_FWD_DEFINED__ */


/* header files for imported files */
#include "unknwn.h"

void __RPC_FAR * __RPC_USER MIDL_user_allocate(size_t);
void __RPC_USER MIDL_user_free( void __RPC_FAR * ); 

/****************************************
 * Generated header for interface: __MIDL_itf_srtcnt_0000
 * at Tue Nov 23 05:28:35 1999
 * using MIDL 3.01.75
 ****************************************/
/* [local] */ 





extern RPC_IF_HANDLE __MIDL_itf_srtcnt_0000_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_srtcnt_0000_v0_0_s_ifspec;

#ifndef __ISortedContainer_INTERFACE_DEFINED__
#define __ISortedContainer_INTERFACE_DEFINED__

/****************************************
 * Generated header for interface: ISortedContainer
 * at Tue Nov 23 05:28:35 1999
 * using MIDL 3.01.75
 ****************************************/
/* [uuid][object][local] */ 



EXTERN_C const IID IID_ISortedContainer;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    interface DECLSPEC_UUID("8335e629-ab3b-11ce-8468-0000b468276b")
    ISortedContainer : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE AddObject( 
            /* [in] */ IUnknown __RPC_FAR *pObject,
            /* [in] */ long lPosition) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE RemoveObject( 
            /* [in] */ IUnknown __RPC_FAR *pObject,
            /* [in] */ long lPosition) = 0;
        
        virtual DWORD STDMETHODCALLTYPE QueryNumObjects( void) = 0;
        
        virtual IUnknown __RPC_FAR *STDMETHODCALLTYPE GetObject( 
            long index) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE EnumMembers( 
            IEnumUnknown __RPC_FAR *__RPC_FAR *ppEnumUnk) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Sort( 
            int ( STDMETHODCALLTYPE __RPC_FAR *compare )( 
                IUnknown __RPC_FAR *elem1,
                IUnknown __RPC_FAR *elem2)) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct ISortedContainerVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            ISortedContainer __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            ISortedContainer __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            ISortedContainer __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *AddObject )( 
            ISortedContainer __RPC_FAR * This,
            /* [in] */ IUnknown __RPC_FAR *pObject,
            /* [in] */ long lPosition);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *RemoveObject )( 
            ISortedContainer __RPC_FAR * This,
            /* [in] */ IUnknown __RPC_FAR *pObject,
            /* [in] */ long lPosition);
        
        DWORD ( STDMETHODCALLTYPE __RPC_FAR *QueryNumObjects )( 
            ISortedContainer __RPC_FAR * This);
        
        IUnknown __RPC_FAR *( STDMETHODCALLTYPE __RPC_FAR *GetObject )( 
            ISortedContainer __RPC_FAR * This,
            long index);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *EnumMembers )( 
            ISortedContainer __RPC_FAR * This,
            IEnumUnknown __RPC_FAR *__RPC_FAR *ppEnumUnk);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Sort )( 
            ISortedContainer __RPC_FAR * This,
            int ( STDMETHODCALLTYPE __RPC_FAR *compare )( 
                IUnknown __RPC_FAR *elem1,
                IUnknown __RPC_FAR *elem2));
        
        END_INTERFACE
    } ISortedContainerVtbl;

    interface ISortedContainer
    {
        CONST_VTBL struct ISortedContainerVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ISortedContainer_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define ISortedContainer_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define ISortedContainer_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define ISortedContainer_AddObject(This,pObject,lPosition)	\
    (This)->lpVtbl -> AddObject(This,pObject,lPosition)

#define ISortedContainer_RemoveObject(This,pObject,lPosition)	\
    (This)->lpVtbl -> RemoveObject(This,pObject,lPosition)

#define ISortedContainer_QueryNumObjects(This)	\
    (This)->lpVtbl -> QueryNumObjects(This)

#define ISortedContainer_GetObject(This,index)	\
    (This)->lpVtbl -> GetObject(This,index)

#define ISortedContainer_EnumMembers(This,ppEnumUnk)	\
    (This)->lpVtbl -> EnumMembers(This,ppEnumUnk)

#define ISortedContainer_Sort(This,compare)	\
    (This)->lpVtbl -> Sort(This,compare)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE ISortedContainer_AddObject_Proxy( 
    ISortedContainer __RPC_FAR * This,
    /* [in] */ IUnknown __RPC_FAR *pObject,
    /* [in] */ long lPosition);


void __RPC_STUB ISortedContainer_AddObject_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE ISortedContainer_RemoveObject_Proxy( 
    ISortedContainer __RPC_FAR * This,
    /* [in] */ IUnknown __RPC_FAR *pObject,
    /* [in] */ long lPosition);


void __RPC_STUB ISortedContainer_RemoveObject_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


DWORD STDMETHODCALLTYPE ISortedContainer_QueryNumObjects_Proxy( 
    ISortedContainer __RPC_FAR * This);


void __RPC_STUB ISortedContainer_QueryNumObjects_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


IUnknown __RPC_FAR *STDMETHODCALLTYPE ISortedContainer_GetObject_Proxy( 
    ISortedContainer __RPC_FAR * This,
    long index);


void __RPC_STUB ISortedContainer_GetObject_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE ISortedContainer_EnumMembers_Proxy( 
    ISortedContainer __RPC_FAR * This,
    IEnumUnknown __RPC_FAR *__RPC_FAR *ppEnumUnk);


void __RPC_STUB ISortedContainer_EnumMembers_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE ISortedContainer_Sort_Proxy( 
    ISortedContainer __RPC_FAR * This,
    int ( STDMETHODCALLTYPE __RPC_FAR *compare )( 
        IUnknown __RPC_FAR *elem1,
        IUnknown __RPC_FAR *elem2));


void __RPC_STUB ISortedContainer_Sort_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __ISortedContainer_INTERFACE_DEFINED__ */


#ifndef __IContainedObject_INTERFACE_DEFINED__
#define __IContainedObject_INTERFACE_DEFINED__

/****************************************
 * Generated header for interface: IContainedObject
 * at Tue Nov 23 05:28:35 1999
 * using MIDL 3.01.75
 ****************************************/
/* [uuid][object][local] */ 



EXTERN_C const IID IID_IContainedObject;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    interface DECLSPEC_UUID("8335e62f-ab3b-11ce-8468-0000b468276b")
    IContainedObject : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE OnAddToContainer( 
            IUnknown __RPC_FAR *pUnk) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE OnRemoveFromContainer( 
            IUnknown __RPC_FAR *pUnk) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetContainer( 
            DWORD dwIndex,
            IUnknown __RPC_FAR *__RPC_FAR *pUnk) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE QueryOuterInterface( 
            REFIID riid,
            void __RPC_FAR *__RPC_FAR *ppv) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE QueryContainerInterfaces( 
            DWORD dwSkip,
            REFIID riid,
            void __RPC_FAR *__RPC_FAR *ppv) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IContainedObjectVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            IContainedObject __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            IContainedObject __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            IContainedObject __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *OnAddToContainer )( 
            IContainedObject __RPC_FAR * This,
            IUnknown __RPC_FAR *pUnk);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *OnRemoveFromContainer )( 
            IContainedObject __RPC_FAR * This,
            IUnknown __RPC_FAR *pUnk);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetContainer )( 
            IContainedObject __RPC_FAR * This,
            DWORD dwIndex,
            IUnknown __RPC_FAR *__RPC_FAR *pUnk);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryOuterInterface )( 
            IContainedObject __RPC_FAR * This,
            REFIID riid,
            void __RPC_FAR *__RPC_FAR *ppv);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryContainerInterfaces )( 
            IContainedObject __RPC_FAR * This,
            DWORD dwSkip,
            REFIID riid,
            void __RPC_FAR *__RPC_FAR *ppv);
        
        END_INTERFACE
    } IContainedObjectVtbl;

    interface IContainedObject
    {
        CONST_VTBL struct IContainedObjectVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IContainedObject_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IContainedObject_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IContainedObject_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IContainedObject_OnAddToContainer(This,pUnk)	\
    (This)->lpVtbl -> OnAddToContainer(This,pUnk)

#define IContainedObject_OnRemoveFromContainer(This,pUnk)	\
    (This)->lpVtbl -> OnRemoveFromContainer(This,pUnk)

#define IContainedObject_GetContainer(This,dwIndex,pUnk)	\
    (This)->lpVtbl -> GetContainer(This,dwIndex,pUnk)

#define IContainedObject_QueryOuterInterface(This,riid,ppv)	\
    (This)->lpVtbl -> QueryOuterInterface(This,riid,ppv)

#define IContainedObject_QueryContainerInterfaces(This,dwSkip,riid,ppv)	\
    (This)->lpVtbl -> QueryContainerInterfaces(This,dwSkip,riid,ppv)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE IContainedObject_OnAddToContainer_Proxy( 
    IContainedObject __RPC_FAR * This,
    IUnknown __RPC_FAR *pUnk);


void __RPC_STUB IContainedObject_OnAddToContainer_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IContainedObject_OnRemoveFromContainer_Proxy( 
    IContainedObject __RPC_FAR * This,
    IUnknown __RPC_FAR *pUnk);


void __RPC_STUB IContainedObject_OnRemoveFromContainer_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IContainedObject_GetContainer_Proxy( 
    IContainedObject __RPC_FAR * This,
    DWORD dwIndex,
    IUnknown __RPC_FAR *__RPC_FAR *pUnk);


void __RPC_STUB IContainedObject_GetContainer_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IContainedObject_QueryOuterInterface_Proxy( 
    IContainedObject __RPC_FAR * This,
    REFIID riid,
    void __RPC_FAR *__RPC_FAR *ppv);


void __RPC_STUB IContainedObject_QueryOuterInterface_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IContainedObject_QueryContainerInterfaces_Proxy( 
    IContainedObject __RPC_FAR * This,
    DWORD dwSkip,
    REFIID riid,
    void __RPC_FAR *__RPC_FAR *ppv);


void __RPC_STUB IContainedObject_QueryContainerInterfaces_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IContainedObject_INTERFACE_DEFINED__ */


/* Additional Prototypes for ALL interfaces */

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif
