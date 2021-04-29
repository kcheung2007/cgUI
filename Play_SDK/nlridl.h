/* this ALWAYS GENERATED file contains the definitions for the interfaces */


/* File created by MIDL compiler version 3.01.75 */
/* at Tue Nov 23 05:28:32 1999
 */
/* Compiler settings for nlridl.idl:
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

#ifndef __nlridl_h__
#define __nlridl_h__

#ifdef __cplusplus
extern "C"{
#endif 

/* Forward Declarations */ 

#ifndef __ITrnNLRClipConflictDetector_FWD_DEFINED__
#define __ITrnNLRClipConflictDetector_FWD_DEFINED__
typedef interface ITrnNLRClipConflictDetector ITrnNLRClipConflictDetector;
#endif 	/* __ITrnNLRClipConflictDetector_FWD_DEFINED__ */


#ifndef __ITrnNLRManager_FWD_DEFINED__
#define __ITrnNLRManager_FWD_DEFINED__
typedef interface ITrnNLRManager ITrnNLRManager;
#endif 	/* __ITrnNLRManager_FWD_DEFINED__ */


#ifndef __ITrnNLRManager2_FWD_DEFINED__
#define __ITrnNLRManager2_FWD_DEFINED__
typedef interface ITrnNLRManager2 ITrnNLRManager2;
#endif 	/* __ITrnNLRManager2_FWD_DEFINED__ */


#ifndef __ITrnNonLinearRecorder_FWD_DEFINED__
#define __ITrnNonLinearRecorder_FWD_DEFINED__
typedef interface ITrnNonLinearRecorder ITrnNonLinearRecorder;
#endif 	/* __ITrnNonLinearRecorder_FWD_DEFINED__ */


#ifndef __ITrnNonLinearRecorder2Advise_FWD_DEFINED__
#define __ITrnNonLinearRecorder2Advise_FWD_DEFINED__
typedef interface ITrnNonLinearRecorder2Advise ITrnNonLinearRecorder2Advise;
#endif 	/* __ITrnNonLinearRecorder2Advise_FWD_DEFINED__ */


#ifndef __ITrnNonLinearRecorder2_FWD_DEFINED__
#define __ITrnNonLinearRecorder2_FWD_DEFINED__
typedef interface ITrnNonLinearRecorder2 ITrnNonLinearRecorder2;
#endif 	/* __ITrnNonLinearRecorder2_FWD_DEFINED__ */


#ifndef __ITrnMediaClip_FWD_DEFINED__
#define __ITrnMediaClip_FWD_DEFINED__
typedef interface ITrnMediaClip ITrnMediaClip;
#endif 	/* __ITrnMediaClip_FWD_DEFINED__ */


#ifndef __ITrnMediaClip2_FWD_DEFINED__
#define __ITrnMediaClip2_FWD_DEFINED__
typedef interface ITrnMediaClip2 ITrnMediaClip2;
#endif 	/* __ITrnMediaClip2_FWD_DEFINED__ */


#ifndef __ITrnNonLinearDiskRecorder_FWD_DEFINED__
#define __ITrnNonLinearDiskRecorder_FWD_DEFINED__
typedef interface ITrnNonLinearDiskRecorder ITrnNonLinearDiskRecorder;
#endif 	/* __ITrnNonLinearDiskRecorder_FWD_DEFINED__ */


#ifndef __IEnumSTrnVolumeInfo_FWD_DEFINED__
#define __IEnumSTrnVolumeInfo_FWD_DEFINED__
typedef interface IEnumSTrnVolumeInfo IEnumSTrnVolumeInfo;
#endif 	/* __IEnumSTrnVolumeInfo_FWD_DEFINED__ */


#ifndef __IEnumSTrnClipInfo_FWD_DEFINED__
#define __IEnumSTrnClipInfo_FWD_DEFINED__
typedef interface IEnumSTrnClipInfo IEnumSTrnClipInfo;
#endif 	/* __IEnumSTrnClipInfo_FWD_DEFINED__ */


#ifndef __ITrnVideoCompressionCODEC_FWD_DEFINED__
#define __ITrnVideoCompressionCODEC_FWD_DEFINED__
typedef interface ITrnVideoCompressionCODEC ITrnVideoCompressionCODEC;
#endif 	/* __ITrnVideoCompressionCODEC_FWD_DEFINED__ */


/* header files for imported files */
#include "wtypes.h"
#include "unknwn.h"
#include "objidl.h"
#include "autoct.h"
#include "trnity.h"
#include "smedia.h"
#include "simplevid.h"

void __RPC_FAR * __RPC_USER MIDL_user_allocate(size_t);
void __RPC_USER MIDL_user_free( void __RPC_FAR * ); 

/****************************************
 * Generated header for interface: __MIDL_itf_nlridl_0000
 * at Tue Nov 23 05:28:32 1999
 * using MIDL 3.01.75
 ****************************************/
/* [local] */ 














extern RPC_IF_HANDLE __MIDL_itf_nlridl_0000_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_nlridl_0000_v0_0_s_ifspec;

#ifndef __ITrnNLRClipConflictDetector_INTERFACE_DEFINED__
#define __ITrnNLRClipConflictDetector_INTERFACE_DEFINED__

/****************************************
 * Generated header for interface: ITrnNLRClipConflictDetector
 * at Tue Nov 23 05:28:32 1999
 * using MIDL 3.01.75
 ****************************************/
/* [unique][uuid][object][local] */ 



EXTERN_C const IID IID_ITrnNLRClipConflictDetector;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    interface DECLSPEC_UUID("8335e460-ab3b-11ce-8468-0000b468276b")
    ITrnNLRClipConflictDetector : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE ProposedNLRForClip( 
            ITrnNonLinearRecorder __RPC_FAR *pTrnNLR,
            DWORD flags) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct ITrnNLRClipConflictDetectorVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            ITrnNLRClipConflictDetector __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            ITrnNLRClipConflictDetector __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            ITrnNLRClipConflictDetector __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *ProposedNLRForClip )( 
            ITrnNLRClipConflictDetector __RPC_FAR * This,
            ITrnNonLinearRecorder __RPC_FAR *pTrnNLR,
            DWORD flags);
        
        END_INTERFACE
    } ITrnNLRClipConflictDetectorVtbl;

    interface ITrnNLRClipConflictDetector
    {
        CONST_VTBL struct ITrnNLRClipConflictDetectorVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ITrnNLRClipConflictDetector_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define ITrnNLRClipConflictDetector_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define ITrnNLRClipConflictDetector_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define ITrnNLRClipConflictDetector_ProposedNLRForClip(This,pTrnNLR,flags)	\
    (This)->lpVtbl -> ProposedNLRForClip(This,pTrnNLR,flags)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE ITrnNLRClipConflictDetector_ProposedNLRForClip_Proxy( 
    ITrnNLRClipConflictDetector __RPC_FAR * This,
    ITrnNonLinearRecorder __RPC_FAR *pTrnNLR,
    DWORD flags);


void __RPC_STUB ITrnNLRClipConflictDetector_ProposedNLRForClip_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __ITrnNLRClipConflictDetector_INTERFACE_DEFINED__ */


/****************************************
 * Generated header for interface: __MIDL_itf_nlridl_0252
 * at Tue Nov 23 05:28:32 1999
 * using MIDL 3.01.75
 ****************************************/
/* [local] */ 


#define OBJREF_NLR_CLIPMEM(n) OBJREF_SIMPLE_VIDEO_ADDON(n,Play.ClipMem)
#define OBJREF_NLR_TIMEMACHINE(n) OBJREF_SIMPLE_VIDEO_ADDON(n,Play.TimeMachine)
#define OBJREF_CLIPMEM_CLIP(n,m) OBJREF_NLR_CLIPMEM(n) L"!" L#m
#define OBJREF_TIMEMACHINE_CLIP(n,m) OBJREF_NLR_TIMEMACHINE(n)  L"!" L#m


extern RPC_IF_HANDLE __MIDL_itf_nlridl_0252_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_nlridl_0252_v0_0_s_ifspec;

#ifndef __ITrnNLRManager_INTERFACE_DEFINED__
#define __ITrnNLRManager_INTERFACE_DEFINED__

/****************************************
 * Generated header for interface: ITrnNLRManager
 * at Tue Nov 23 05:28:32 1999
 * using MIDL 3.01.75
 ****************************************/
/* [unique][uuid][object][local] */ 



EXTERN_C const IID IID_ITrnNLRManager;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    interface DECLSPEC_UUID("8335e461-ab3b-11ce-8468-0000b468276b")
    ITrnNLRManager : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE QueryNumNLRs( 
            /* [out] */ DWORD __RPC_FAR *numNLRs) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE QueryUIDSize( 
            /* [out] */ DWORD __RPC_FAR *uidSize) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GenerateClipUID( 
            /* [in] */ DWORD uidLen,
            /* [string][out] */ OLECHAR __RPC_FAR *pClipUID) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE EnumClipInstances( 
            /* [string][in] */ const OLECHAR __RPC_FAR *pClipUID,
            /* [out] */ IEnumUnknown __RPC_FAR *__RPC_FAR *pEnum) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE EnumNLRs( 
            /* [out] */ IEnumUnknown __RPC_FAR *__RPC_FAR *pEnum) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE CreateClip( 
            /* [string][in] */ const OLECHAR __RPC_FAR *pClipUID,
            /* [in] */ DWORD createFlags,
            /* [in] */ DWORD compressionRatio,
            /* [in] */ DWORD compressionType,
            /* [in] */ DWORD initialFramesRequested,
            /* [out] */ DWORD __RPC_FAR *initialFramesAllocated,
            /* [in] */ ITrnNLRClipConflictDetector __RPC_FAR *pTrnCCD,
            /* [out] */ ITrnMediaClip __RPC_FAR *__RPC_FAR *pClip) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE OpenClip( 
            /* [string][in] */ const OLECHAR __RPC_FAR *pClipUID,
            /* [in] */ DWORD openFlags,
            /* [in] */ ITrnNLRClipConflictDetector __RPC_FAR *pTrnCCD,
            /* [out] */ ITrnMediaClip __RPC_FAR *__RPC_FAR *pClip) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE DeleteClip( 
            /* [in] */ const OLECHAR __RPC_FAR *pClipUID,
            /* [in] */ DWORD flags) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE FlushDirtyFileSystems( void) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct ITrnNLRManagerVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            ITrnNLRManager __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            ITrnNLRManager __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            ITrnNLRManager __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryNumNLRs )( 
            ITrnNLRManager __RPC_FAR * This,
            /* [out] */ DWORD __RPC_FAR *numNLRs);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryUIDSize )( 
            ITrnNLRManager __RPC_FAR * This,
            /* [out] */ DWORD __RPC_FAR *uidSize);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GenerateClipUID )( 
            ITrnNLRManager __RPC_FAR * This,
            /* [in] */ DWORD uidLen,
            /* [string][out] */ OLECHAR __RPC_FAR *pClipUID);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *EnumClipInstances )( 
            ITrnNLRManager __RPC_FAR * This,
            /* [string][in] */ const OLECHAR __RPC_FAR *pClipUID,
            /* [out] */ IEnumUnknown __RPC_FAR *__RPC_FAR *pEnum);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *EnumNLRs )( 
            ITrnNLRManager __RPC_FAR * This,
            /* [out] */ IEnumUnknown __RPC_FAR *__RPC_FAR *pEnum);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *CreateClip )( 
            ITrnNLRManager __RPC_FAR * This,
            /* [string][in] */ const OLECHAR __RPC_FAR *pClipUID,
            /* [in] */ DWORD createFlags,
            /* [in] */ DWORD compressionRatio,
            /* [in] */ DWORD compressionType,
            /* [in] */ DWORD initialFramesRequested,
            /* [out] */ DWORD __RPC_FAR *initialFramesAllocated,
            /* [in] */ ITrnNLRClipConflictDetector __RPC_FAR *pTrnCCD,
            /* [out] */ ITrnMediaClip __RPC_FAR *__RPC_FAR *pClip);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *OpenClip )( 
            ITrnNLRManager __RPC_FAR * This,
            /* [string][in] */ const OLECHAR __RPC_FAR *pClipUID,
            /* [in] */ DWORD openFlags,
            /* [in] */ ITrnNLRClipConflictDetector __RPC_FAR *pTrnCCD,
            /* [out] */ ITrnMediaClip __RPC_FAR *__RPC_FAR *pClip);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *DeleteClip )( 
            ITrnNLRManager __RPC_FAR * This,
            /* [in] */ const OLECHAR __RPC_FAR *pClipUID,
            /* [in] */ DWORD flags);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *FlushDirtyFileSystems )( 
            ITrnNLRManager __RPC_FAR * This);
        
        END_INTERFACE
    } ITrnNLRManagerVtbl;

    interface ITrnNLRManager
    {
        CONST_VTBL struct ITrnNLRManagerVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ITrnNLRManager_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define ITrnNLRManager_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define ITrnNLRManager_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define ITrnNLRManager_QueryNumNLRs(This,numNLRs)	\
    (This)->lpVtbl -> QueryNumNLRs(This,numNLRs)

#define ITrnNLRManager_QueryUIDSize(This,uidSize)	\
    (This)->lpVtbl -> QueryUIDSize(This,uidSize)

#define ITrnNLRManager_GenerateClipUID(This,uidLen,pClipUID)	\
    (This)->lpVtbl -> GenerateClipUID(This,uidLen,pClipUID)

#define ITrnNLRManager_EnumClipInstances(This,pClipUID,pEnum)	\
    (This)->lpVtbl -> EnumClipInstances(This,pClipUID,pEnum)

#define ITrnNLRManager_EnumNLRs(This,pEnum)	\
    (This)->lpVtbl -> EnumNLRs(This,pEnum)

#define ITrnNLRManager_CreateClip(This,pClipUID,createFlags,compressionRatio,compressionType,initialFramesRequested,initialFramesAllocated,pTrnCCD,pClip)	\
    (This)->lpVtbl -> CreateClip(This,pClipUID,createFlags,compressionRatio,compressionType,initialFramesRequested,initialFramesAllocated,pTrnCCD,pClip)

#define ITrnNLRManager_OpenClip(This,pClipUID,openFlags,pTrnCCD,pClip)	\
    (This)->lpVtbl -> OpenClip(This,pClipUID,openFlags,pTrnCCD,pClip)

#define ITrnNLRManager_DeleteClip(This,pClipUID,flags)	\
    (This)->lpVtbl -> DeleteClip(This,pClipUID,flags)

#define ITrnNLRManager_FlushDirtyFileSystems(This)	\
    (This)->lpVtbl -> FlushDirtyFileSystems(This)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE ITrnNLRManager_QueryNumNLRs_Proxy( 
    ITrnNLRManager __RPC_FAR * This,
    /* [out] */ DWORD __RPC_FAR *numNLRs);


void __RPC_STUB ITrnNLRManager_QueryNumNLRs_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE ITrnNLRManager_QueryUIDSize_Proxy( 
    ITrnNLRManager __RPC_FAR * This,
    /* [out] */ DWORD __RPC_FAR *uidSize);


void __RPC_STUB ITrnNLRManager_QueryUIDSize_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE ITrnNLRManager_GenerateClipUID_Proxy( 
    ITrnNLRManager __RPC_FAR * This,
    /* [in] */ DWORD uidLen,
    /* [string][out] */ OLECHAR __RPC_FAR *pClipUID);


void __RPC_STUB ITrnNLRManager_GenerateClipUID_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE ITrnNLRManager_EnumClipInstances_Proxy( 
    ITrnNLRManager __RPC_FAR * This,
    /* [string][in] */ const OLECHAR __RPC_FAR *pClipUID,
    /* [out] */ IEnumUnknown __RPC_FAR *__RPC_FAR *pEnum);


void __RPC_STUB ITrnNLRManager_EnumClipInstances_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE ITrnNLRManager_EnumNLRs_Proxy( 
    ITrnNLRManager __RPC_FAR * This,
    /* [out] */ IEnumUnknown __RPC_FAR *__RPC_FAR *pEnum);


void __RPC_STUB ITrnNLRManager_EnumNLRs_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE ITrnNLRManager_CreateClip_Proxy( 
    ITrnNLRManager __RPC_FAR * This,
    /* [string][in] */ const OLECHAR __RPC_FAR *pClipUID,
    /* [in] */ DWORD createFlags,
    /* [in] */ DWORD compressionRatio,
    /* [in] */ DWORD compressionType,
    /* [in] */ DWORD initialFramesRequested,
    /* [out] */ DWORD __RPC_FAR *initialFramesAllocated,
    /* [in] */ ITrnNLRClipConflictDetector __RPC_FAR *pTrnCCD,
    /* [out] */ ITrnMediaClip __RPC_FAR *__RPC_FAR *pClip);


void __RPC_STUB ITrnNLRManager_CreateClip_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE ITrnNLRManager_OpenClip_Proxy( 
    ITrnNLRManager __RPC_FAR * This,
    /* [string][in] */ const OLECHAR __RPC_FAR *pClipUID,
    /* [in] */ DWORD openFlags,
    /* [in] */ ITrnNLRClipConflictDetector __RPC_FAR *pTrnCCD,
    /* [out] */ ITrnMediaClip __RPC_FAR *__RPC_FAR *pClip);


void __RPC_STUB ITrnNLRManager_OpenClip_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE ITrnNLRManager_DeleteClip_Proxy( 
    ITrnNLRManager __RPC_FAR * This,
    /* [in] */ const OLECHAR __RPC_FAR *pClipUID,
    /* [in] */ DWORD flags);


void __RPC_STUB ITrnNLRManager_DeleteClip_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE ITrnNLRManager_FlushDirtyFileSystems_Proxy( 
    ITrnNLRManager __RPC_FAR * This);


void __RPC_STUB ITrnNLRManager_FlushDirtyFileSystems_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __ITrnNLRManager_INTERFACE_DEFINED__ */


#ifndef __ITrnNLRManager2_INTERFACE_DEFINED__
#define __ITrnNLRManager2_INTERFACE_DEFINED__

/****************************************
 * Generated header for interface: ITrnNLRManager2
 * at Tue Nov 23 05:28:32 1999
 * using MIDL 3.01.75
 ****************************************/
/* [unique][uuid][object][local] */ 



EXTERN_C const IID IID_ITrnNLRManager2;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    interface DECLSPEC_UUID("8335e7e2-ab3b-11ce-8468-0000b468276b")
    ITrnNLRManager2 : public ITrnNLRManager
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE AddNLR( 
            /* [in] */ ITrnNonLinearRecorder __RPC_FAR *pNLR) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE RemoveNLR( 
            /* [in] */ ITrnNonLinearRecorder __RPC_FAR *pNLR) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct ITrnNLRManager2Vtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            ITrnNLRManager2 __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            ITrnNLRManager2 __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            ITrnNLRManager2 __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryNumNLRs )( 
            ITrnNLRManager2 __RPC_FAR * This,
            /* [out] */ DWORD __RPC_FAR *numNLRs);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryUIDSize )( 
            ITrnNLRManager2 __RPC_FAR * This,
            /* [out] */ DWORD __RPC_FAR *uidSize);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GenerateClipUID )( 
            ITrnNLRManager2 __RPC_FAR * This,
            /* [in] */ DWORD uidLen,
            /* [string][out] */ OLECHAR __RPC_FAR *pClipUID);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *EnumClipInstances )( 
            ITrnNLRManager2 __RPC_FAR * This,
            /* [string][in] */ const OLECHAR __RPC_FAR *pClipUID,
            /* [out] */ IEnumUnknown __RPC_FAR *__RPC_FAR *pEnum);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *EnumNLRs )( 
            ITrnNLRManager2 __RPC_FAR * This,
            /* [out] */ IEnumUnknown __RPC_FAR *__RPC_FAR *pEnum);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *CreateClip )( 
            ITrnNLRManager2 __RPC_FAR * This,
            /* [string][in] */ const OLECHAR __RPC_FAR *pClipUID,
            /* [in] */ DWORD createFlags,
            /* [in] */ DWORD compressionRatio,
            /* [in] */ DWORD compressionType,
            /* [in] */ DWORD initialFramesRequested,
            /* [out] */ DWORD __RPC_FAR *initialFramesAllocated,
            /* [in] */ ITrnNLRClipConflictDetector __RPC_FAR *pTrnCCD,
            /* [out] */ ITrnMediaClip __RPC_FAR *__RPC_FAR *pClip);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *OpenClip )( 
            ITrnNLRManager2 __RPC_FAR * This,
            /* [string][in] */ const OLECHAR __RPC_FAR *pClipUID,
            /* [in] */ DWORD openFlags,
            /* [in] */ ITrnNLRClipConflictDetector __RPC_FAR *pTrnCCD,
            /* [out] */ ITrnMediaClip __RPC_FAR *__RPC_FAR *pClip);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *DeleteClip )( 
            ITrnNLRManager2 __RPC_FAR * This,
            /* [in] */ const OLECHAR __RPC_FAR *pClipUID,
            /* [in] */ DWORD flags);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *FlushDirtyFileSystems )( 
            ITrnNLRManager2 __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *AddNLR )( 
            ITrnNLRManager2 __RPC_FAR * This,
            /* [in] */ ITrnNonLinearRecorder __RPC_FAR *pNLR);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *RemoveNLR )( 
            ITrnNLRManager2 __RPC_FAR * This,
            /* [in] */ ITrnNonLinearRecorder __RPC_FAR *pNLR);
        
        END_INTERFACE
    } ITrnNLRManager2Vtbl;

    interface ITrnNLRManager2
    {
        CONST_VTBL struct ITrnNLRManager2Vtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ITrnNLRManager2_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define ITrnNLRManager2_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define ITrnNLRManager2_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define ITrnNLRManager2_QueryNumNLRs(This,numNLRs)	\
    (This)->lpVtbl -> QueryNumNLRs(This,numNLRs)

#define ITrnNLRManager2_QueryUIDSize(This,uidSize)	\
    (This)->lpVtbl -> QueryUIDSize(This,uidSize)

#define ITrnNLRManager2_GenerateClipUID(This,uidLen,pClipUID)	\
    (This)->lpVtbl -> GenerateClipUID(This,uidLen,pClipUID)

#define ITrnNLRManager2_EnumClipInstances(This,pClipUID,pEnum)	\
    (This)->lpVtbl -> EnumClipInstances(This,pClipUID,pEnum)

#define ITrnNLRManager2_EnumNLRs(This,pEnum)	\
    (This)->lpVtbl -> EnumNLRs(This,pEnum)

#define ITrnNLRManager2_CreateClip(This,pClipUID,createFlags,compressionRatio,compressionType,initialFramesRequested,initialFramesAllocated,pTrnCCD,pClip)	\
    (This)->lpVtbl -> CreateClip(This,pClipUID,createFlags,compressionRatio,compressionType,initialFramesRequested,initialFramesAllocated,pTrnCCD,pClip)

#define ITrnNLRManager2_OpenClip(This,pClipUID,openFlags,pTrnCCD,pClip)	\
    (This)->lpVtbl -> OpenClip(This,pClipUID,openFlags,pTrnCCD,pClip)

#define ITrnNLRManager2_DeleteClip(This,pClipUID,flags)	\
    (This)->lpVtbl -> DeleteClip(This,pClipUID,flags)

#define ITrnNLRManager2_FlushDirtyFileSystems(This)	\
    (This)->lpVtbl -> FlushDirtyFileSystems(This)


#define ITrnNLRManager2_AddNLR(This,pNLR)	\
    (This)->lpVtbl -> AddNLR(This,pNLR)

#define ITrnNLRManager2_RemoveNLR(This,pNLR)	\
    (This)->lpVtbl -> RemoveNLR(This,pNLR)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE ITrnNLRManager2_AddNLR_Proxy( 
    ITrnNLRManager2 __RPC_FAR * This,
    /* [in] */ ITrnNonLinearRecorder __RPC_FAR *pNLR);


void __RPC_STUB ITrnNLRManager2_AddNLR_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE ITrnNLRManager2_RemoveNLR_Proxy( 
    ITrnNLRManager2 __RPC_FAR * This,
    /* [in] */ ITrnNonLinearRecorder __RPC_FAR *pNLR);


void __RPC_STUB ITrnNLRManager2_RemoveNLR_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __ITrnNLRManager2_INTERFACE_DEFINED__ */


#ifndef __ITrnNonLinearRecorder_INTERFACE_DEFINED__
#define __ITrnNonLinearRecorder_INTERFACE_DEFINED__

/****************************************
 * Generated header for interface: ITrnNonLinearRecorder
 * at Tue Nov 23 05:28:32 1999
 * using MIDL 3.01.75
 ****************************************/
/* [unique][uuid][object][local] */ 


typedef 
enum tagETrnNLRType
    {	NTInternalRAM	= 0,
	NTInternalDisk	= NTInternalRAM + 1,
	NTExternal	= NTInternalDisk + 1
    }	ETrnNLRType;

typedef struct  tagSTrnNLECapabilities
    {
    DWORD dwSizeOf;
    DWORD ccbNameBuffer;
    unsigned char __RPC_FAR *pNameBuffer;
    WORD numAudioChannelsRec;
    WORD numAudioChannelsPlay;
    WORD numVideoChannelsRec;
    WORD numVideoChannelsPlay;
    WORD numAlphaChannelsRec;
    WORD numAlphaChannelsPlay;
    WORD numAudioBits;
    WORD numAudioSamplesPerSecond;
    BOOL bIndependentAudio;
    DWORD nativeFormats;
    DWORD convertableFormats;
    ETrnNLRType nlrType;
    CLSID nlrCLSID;
    EVidSource physSources[ 4 ];
    }	STrnNLECapabilities;


EXTERN_C const IID IID_ITrnNonLinearRecorder;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    interface DECLSPEC_UUID("8335e3d4-ab3b-11ce-8468-0000b468276b")
    ITrnNonLinearRecorder : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE QueryCapabilitiesEx( 
            STrnNLECapabilities __RPC_FAR *pECaps) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE EnumClips( 
            /* [out] */ IEnumUnknown __RPC_FAR *__RPC_FAR *pEnum) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE OpenClip( 
            /* [string][in] */ const OLECHAR __RPC_FAR *pClipUID,
            /* [in] */ DWORD openFlags,
            /* [in] */ REFIID riid,
            /* [out] */ void __RPC_FAR *__RPC_FAR *ppvClip) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE CreateClip( 
            /* [string][in] */ const OLECHAR __RPC_FAR *pClipUID,
            /* [in] */ DWORD createFlags,
            /* [in] */ DWORD compressionRatio,
            /* [in] */ DWORD compressionType,
            /* [in] */ DWORD initialFramesRequested,
            /* [out] */ DWORD __RPC_FAR *initialFramesAllocated,
            /* [in] */ REFIID riid,
            /* [out] */ void __RPC_FAR *__RPC_FAR *ppvClip) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE DeleteClip( 
            /* [in] */ const OLECHAR __RPC_FAR *pClipUID) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct ITrnNonLinearRecorderVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            ITrnNonLinearRecorder __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            ITrnNonLinearRecorder __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            ITrnNonLinearRecorder __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryCapabilitiesEx )( 
            ITrnNonLinearRecorder __RPC_FAR * This,
            STrnNLECapabilities __RPC_FAR *pECaps);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *EnumClips )( 
            ITrnNonLinearRecorder __RPC_FAR * This,
            /* [out] */ IEnumUnknown __RPC_FAR *__RPC_FAR *pEnum);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *OpenClip )( 
            ITrnNonLinearRecorder __RPC_FAR * This,
            /* [string][in] */ const OLECHAR __RPC_FAR *pClipUID,
            /* [in] */ DWORD openFlags,
            /* [in] */ REFIID riid,
            /* [out] */ void __RPC_FAR *__RPC_FAR *ppvClip);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *CreateClip )( 
            ITrnNonLinearRecorder __RPC_FAR * This,
            /* [string][in] */ const OLECHAR __RPC_FAR *pClipUID,
            /* [in] */ DWORD createFlags,
            /* [in] */ DWORD compressionRatio,
            /* [in] */ DWORD compressionType,
            /* [in] */ DWORD initialFramesRequested,
            /* [out] */ DWORD __RPC_FAR *initialFramesAllocated,
            /* [in] */ REFIID riid,
            /* [out] */ void __RPC_FAR *__RPC_FAR *ppvClip);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *DeleteClip )( 
            ITrnNonLinearRecorder __RPC_FAR * This,
            /* [in] */ const OLECHAR __RPC_FAR *pClipUID);
        
        END_INTERFACE
    } ITrnNonLinearRecorderVtbl;

    interface ITrnNonLinearRecorder
    {
        CONST_VTBL struct ITrnNonLinearRecorderVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ITrnNonLinearRecorder_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define ITrnNonLinearRecorder_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define ITrnNonLinearRecorder_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define ITrnNonLinearRecorder_QueryCapabilitiesEx(This,pECaps)	\
    (This)->lpVtbl -> QueryCapabilitiesEx(This,pECaps)

#define ITrnNonLinearRecorder_EnumClips(This,pEnum)	\
    (This)->lpVtbl -> EnumClips(This,pEnum)

#define ITrnNonLinearRecorder_OpenClip(This,pClipUID,openFlags,riid,ppvClip)	\
    (This)->lpVtbl -> OpenClip(This,pClipUID,openFlags,riid,ppvClip)

#define ITrnNonLinearRecorder_CreateClip(This,pClipUID,createFlags,compressionRatio,compressionType,initialFramesRequested,initialFramesAllocated,riid,ppvClip)	\
    (This)->lpVtbl -> CreateClip(This,pClipUID,createFlags,compressionRatio,compressionType,initialFramesRequested,initialFramesAllocated,riid,ppvClip)

#define ITrnNonLinearRecorder_DeleteClip(This,pClipUID)	\
    (This)->lpVtbl -> DeleteClip(This,pClipUID)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE ITrnNonLinearRecorder_QueryCapabilitiesEx_Proxy( 
    ITrnNonLinearRecorder __RPC_FAR * This,
    STrnNLECapabilities __RPC_FAR *pECaps);


void __RPC_STUB ITrnNonLinearRecorder_QueryCapabilitiesEx_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE ITrnNonLinearRecorder_EnumClips_Proxy( 
    ITrnNonLinearRecorder __RPC_FAR * This,
    /* [out] */ IEnumUnknown __RPC_FAR *__RPC_FAR *pEnum);


void __RPC_STUB ITrnNonLinearRecorder_EnumClips_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE ITrnNonLinearRecorder_OpenClip_Proxy( 
    ITrnNonLinearRecorder __RPC_FAR * This,
    /* [string][in] */ const OLECHAR __RPC_FAR *pClipUID,
    /* [in] */ DWORD openFlags,
    /* [in] */ REFIID riid,
    /* [out] */ void __RPC_FAR *__RPC_FAR *ppvClip);


void __RPC_STUB ITrnNonLinearRecorder_OpenClip_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE ITrnNonLinearRecorder_CreateClip_Proxy( 
    ITrnNonLinearRecorder __RPC_FAR * This,
    /* [string][in] */ const OLECHAR __RPC_FAR *pClipUID,
    /* [in] */ DWORD createFlags,
    /* [in] */ DWORD compressionRatio,
    /* [in] */ DWORD compressionType,
    /* [in] */ DWORD initialFramesRequested,
    /* [out] */ DWORD __RPC_FAR *initialFramesAllocated,
    /* [in] */ REFIID riid,
    /* [out] */ void __RPC_FAR *__RPC_FAR *ppvClip);


void __RPC_STUB ITrnNonLinearRecorder_CreateClip_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE ITrnNonLinearRecorder_DeleteClip_Proxy( 
    ITrnNonLinearRecorder __RPC_FAR * This,
    /* [in] */ const OLECHAR __RPC_FAR *pClipUID);


void __RPC_STUB ITrnNonLinearRecorder_DeleteClip_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __ITrnNonLinearRecorder_INTERFACE_DEFINED__ */


#ifndef __ITrnNonLinearRecorder2Advise_INTERFACE_DEFINED__
#define __ITrnNonLinearRecorder2Advise_INTERFACE_DEFINED__

/****************************************
 * Generated header for interface: ITrnNonLinearRecorder2Advise
 * at Tue Nov 23 05:28:32 1999
 * using MIDL 3.01.75
 ****************************************/
/* [unique][uuid][object][local] */ 



EXTERN_C const IID IID_ITrnNonLinearRecorder2Advise;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    interface DECLSPEC_UUID("8335e405-ab3b-11ce-8468-0000b468276b")
    ITrnNonLinearRecorder2Advise : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE ClipCreated( 
            /* [in] */ ITrnMediaClip2 __RPC_FAR *pClip) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE ClipDeleted( 
            /* [in] */ const OLECHAR __RPC_FAR *pClipUID) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE ClipOpenned( 
            /* [in] */ ITrnMediaClip2 __RPC_FAR *pClip) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE ClipClosed( 
            /* [in] */ ITrnMediaClip2 __RPC_FAR *pClip) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct ITrnNonLinearRecorder2AdviseVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            ITrnNonLinearRecorder2Advise __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            ITrnNonLinearRecorder2Advise __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            ITrnNonLinearRecorder2Advise __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *ClipCreated )( 
            ITrnNonLinearRecorder2Advise __RPC_FAR * This,
            /* [in] */ ITrnMediaClip2 __RPC_FAR *pClip);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *ClipDeleted )( 
            ITrnNonLinearRecorder2Advise __RPC_FAR * This,
            /* [in] */ const OLECHAR __RPC_FAR *pClipUID);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *ClipOpenned )( 
            ITrnNonLinearRecorder2Advise __RPC_FAR * This,
            /* [in] */ ITrnMediaClip2 __RPC_FAR *pClip);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *ClipClosed )( 
            ITrnNonLinearRecorder2Advise __RPC_FAR * This,
            /* [in] */ ITrnMediaClip2 __RPC_FAR *pClip);
        
        END_INTERFACE
    } ITrnNonLinearRecorder2AdviseVtbl;

    interface ITrnNonLinearRecorder2Advise
    {
        CONST_VTBL struct ITrnNonLinearRecorder2AdviseVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ITrnNonLinearRecorder2Advise_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define ITrnNonLinearRecorder2Advise_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define ITrnNonLinearRecorder2Advise_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define ITrnNonLinearRecorder2Advise_ClipCreated(This,pClip)	\
    (This)->lpVtbl -> ClipCreated(This,pClip)

#define ITrnNonLinearRecorder2Advise_ClipDeleted(This,pClipUID)	\
    (This)->lpVtbl -> ClipDeleted(This,pClipUID)

#define ITrnNonLinearRecorder2Advise_ClipOpenned(This,pClip)	\
    (This)->lpVtbl -> ClipOpenned(This,pClip)

#define ITrnNonLinearRecorder2Advise_ClipClosed(This,pClip)	\
    (This)->lpVtbl -> ClipClosed(This,pClip)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE ITrnNonLinearRecorder2Advise_ClipCreated_Proxy( 
    ITrnNonLinearRecorder2Advise __RPC_FAR * This,
    /* [in] */ ITrnMediaClip2 __RPC_FAR *pClip);


void __RPC_STUB ITrnNonLinearRecorder2Advise_ClipCreated_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE ITrnNonLinearRecorder2Advise_ClipDeleted_Proxy( 
    ITrnNonLinearRecorder2Advise __RPC_FAR * This,
    /* [in] */ const OLECHAR __RPC_FAR *pClipUID);


void __RPC_STUB ITrnNonLinearRecorder2Advise_ClipDeleted_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE ITrnNonLinearRecorder2Advise_ClipOpenned_Proxy( 
    ITrnNonLinearRecorder2Advise __RPC_FAR * This,
    /* [in] */ ITrnMediaClip2 __RPC_FAR *pClip);


void __RPC_STUB ITrnNonLinearRecorder2Advise_ClipOpenned_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE ITrnNonLinearRecorder2Advise_ClipClosed_Proxy( 
    ITrnNonLinearRecorder2Advise __RPC_FAR * This,
    /* [in] */ ITrnMediaClip2 __RPC_FAR *pClip);


void __RPC_STUB ITrnNonLinearRecorder2Advise_ClipClosed_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __ITrnNonLinearRecorder2Advise_INTERFACE_DEFINED__ */


#ifndef __ITrnNonLinearRecorder2_INTERFACE_DEFINED__
#define __ITrnNonLinearRecorder2_INTERFACE_DEFINED__

/****************************************
 * Generated header for interface: ITrnNonLinearRecorder2
 * at Tue Nov 23 05:28:32 1999
 * using MIDL 3.01.75
 ****************************************/
/* [unique][uuid][object][local] */ 



EXTERN_C const IID IID_ITrnNonLinearRecorder2;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    interface DECLSPEC_UUID("8335e406-ab3b-11ce-8468-0000b468276b")
    ITrnNonLinearRecorder2 : public ITrnNonLinearRecorder
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE CreateSubClip( 
            /* [in] */ ITrnMediaClip __RPC_FAR *pParentClip,
            /* [string][in] */ const OLECHAR __RPC_FAR *pClipUID,
            /* [in] */ DWORD inPoint,
            /* [in] */ DWORD duration,
            /* [in] */ REFIID riid,
            /* [out] */ void __RPC_FAR *__RPC_FAR *ppvClip) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE CloseClip( 
            /* [in] */ IUnknown __RPC_FAR *pClip) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE QueryInternalInterface( 
            REFIID riid,
            long index,
            void __RPC_FAR *__RPC_FAR *ppv) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Advise( 
            /* [in] */ ITrnNonLinearRecorder2Advise __RPC_FAR *pAdvise) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE UnAdvise( 
            /* [in] */ ITrnNonLinearRecorder2Advise __RPC_FAR *pAdvise) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct ITrnNonLinearRecorder2Vtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            ITrnNonLinearRecorder2 __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            ITrnNonLinearRecorder2 __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            ITrnNonLinearRecorder2 __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryCapabilitiesEx )( 
            ITrnNonLinearRecorder2 __RPC_FAR * This,
            STrnNLECapabilities __RPC_FAR *pECaps);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *EnumClips )( 
            ITrnNonLinearRecorder2 __RPC_FAR * This,
            /* [out] */ IEnumUnknown __RPC_FAR *__RPC_FAR *pEnum);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *OpenClip )( 
            ITrnNonLinearRecorder2 __RPC_FAR * This,
            /* [string][in] */ const OLECHAR __RPC_FAR *pClipUID,
            /* [in] */ DWORD openFlags,
            /* [in] */ REFIID riid,
            /* [out] */ void __RPC_FAR *__RPC_FAR *ppvClip);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *CreateClip )( 
            ITrnNonLinearRecorder2 __RPC_FAR * This,
            /* [string][in] */ const OLECHAR __RPC_FAR *pClipUID,
            /* [in] */ DWORD createFlags,
            /* [in] */ DWORD compressionRatio,
            /* [in] */ DWORD compressionType,
            /* [in] */ DWORD initialFramesRequested,
            /* [out] */ DWORD __RPC_FAR *initialFramesAllocated,
            /* [in] */ REFIID riid,
            /* [out] */ void __RPC_FAR *__RPC_FAR *ppvClip);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *DeleteClip )( 
            ITrnNonLinearRecorder2 __RPC_FAR * This,
            /* [in] */ const OLECHAR __RPC_FAR *pClipUID);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *CreateSubClip )( 
            ITrnNonLinearRecorder2 __RPC_FAR * This,
            /* [in] */ ITrnMediaClip __RPC_FAR *pParentClip,
            /* [string][in] */ const OLECHAR __RPC_FAR *pClipUID,
            /* [in] */ DWORD inPoint,
            /* [in] */ DWORD duration,
            /* [in] */ REFIID riid,
            /* [out] */ void __RPC_FAR *__RPC_FAR *ppvClip);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *CloseClip )( 
            ITrnNonLinearRecorder2 __RPC_FAR * This,
            /* [in] */ IUnknown __RPC_FAR *pClip);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInternalInterface )( 
            ITrnNonLinearRecorder2 __RPC_FAR * This,
            REFIID riid,
            long index,
            void __RPC_FAR *__RPC_FAR *ppv);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Advise )( 
            ITrnNonLinearRecorder2 __RPC_FAR * This,
            /* [in] */ ITrnNonLinearRecorder2Advise __RPC_FAR *pAdvise);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *UnAdvise )( 
            ITrnNonLinearRecorder2 __RPC_FAR * This,
            /* [in] */ ITrnNonLinearRecorder2Advise __RPC_FAR *pAdvise);
        
        END_INTERFACE
    } ITrnNonLinearRecorder2Vtbl;

    interface ITrnNonLinearRecorder2
    {
        CONST_VTBL struct ITrnNonLinearRecorder2Vtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ITrnNonLinearRecorder2_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define ITrnNonLinearRecorder2_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define ITrnNonLinearRecorder2_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define ITrnNonLinearRecorder2_QueryCapabilitiesEx(This,pECaps)	\
    (This)->lpVtbl -> QueryCapabilitiesEx(This,pECaps)

#define ITrnNonLinearRecorder2_EnumClips(This,pEnum)	\
    (This)->lpVtbl -> EnumClips(This,pEnum)

#define ITrnNonLinearRecorder2_OpenClip(This,pClipUID,openFlags,riid,ppvClip)	\
    (This)->lpVtbl -> OpenClip(This,pClipUID,openFlags,riid,ppvClip)

#define ITrnNonLinearRecorder2_CreateClip(This,pClipUID,createFlags,compressionRatio,compressionType,initialFramesRequested,initialFramesAllocated,riid,ppvClip)	\
    (This)->lpVtbl -> CreateClip(This,pClipUID,createFlags,compressionRatio,compressionType,initialFramesRequested,initialFramesAllocated,riid,ppvClip)

#define ITrnNonLinearRecorder2_DeleteClip(This,pClipUID)	\
    (This)->lpVtbl -> DeleteClip(This,pClipUID)


#define ITrnNonLinearRecorder2_CreateSubClip(This,pParentClip,pClipUID,inPoint,duration,riid,ppvClip)	\
    (This)->lpVtbl -> CreateSubClip(This,pParentClip,pClipUID,inPoint,duration,riid,ppvClip)

#define ITrnNonLinearRecorder2_CloseClip(This,pClip)	\
    (This)->lpVtbl -> CloseClip(This,pClip)

#define ITrnNonLinearRecorder2_QueryInternalInterface(This,riid,index,ppv)	\
    (This)->lpVtbl -> QueryInternalInterface(This,riid,index,ppv)

#define ITrnNonLinearRecorder2_Advise(This,pAdvise)	\
    (This)->lpVtbl -> Advise(This,pAdvise)

#define ITrnNonLinearRecorder2_UnAdvise(This,pAdvise)	\
    (This)->lpVtbl -> UnAdvise(This,pAdvise)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE ITrnNonLinearRecorder2_CreateSubClip_Proxy( 
    ITrnNonLinearRecorder2 __RPC_FAR * This,
    /* [in] */ ITrnMediaClip __RPC_FAR *pParentClip,
    /* [string][in] */ const OLECHAR __RPC_FAR *pClipUID,
    /* [in] */ DWORD inPoint,
    /* [in] */ DWORD duration,
    /* [in] */ REFIID riid,
    /* [out] */ void __RPC_FAR *__RPC_FAR *ppvClip);


void __RPC_STUB ITrnNonLinearRecorder2_CreateSubClip_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE ITrnNonLinearRecorder2_CloseClip_Proxy( 
    ITrnNonLinearRecorder2 __RPC_FAR * This,
    /* [in] */ IUnknown __RPC_FAR *pClip);


void __RPC_STUB ITrnNonLinearRecorder2_CloseClip_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE ITrnNonLinearRecorder2_QueryInternalInterface_Proxy( 
    ITrnNonLinearRecorder2 __RPC_FAR * This,
    REFIID riid,
    long index,
    void __RPC_FAR *__RPC_FAR *ppv);


void __RPC_STUB ITrnNonLinearRecorder2_QueryInternalInterface_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE ITrnNonLinearRecorder2_Advise_Proxy( 
    ITrnNonLinearRecorder2 __RPC_FAR * This,
    /* [in] */ ITrnNonLinearRecorder2Advise __RPC_FAR *pAdvise);


void __RPC_STUB ITrnNonLinearRecorder2_Advise_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE ITrnNonLinearRecorder2_UnAdvise_Proxy( 
    ITrnNonLinearRecorder2 __RPC_FAR * This,
    /* [in] */ ITrnNonLinearRecorder2Advise __RPC_FAR *pAdvise);


void __RPC_STUB ITrnNonLinearRecorder2_UnAdvise_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __ITrnNonLinearRecorder2_INTERFACE_DEFINED__ */


#ifndef __ITrnMediaClip_INTERFACE_DEFINED__
#define __ITrnMediaClip_INTERFACE_DEFINED__

/****************************************
 * Generated header for interface: ITrnMediaClip
 * at Tue Nov 23 05:28:32 1999
 * using MIDL 3.01.75
 ****************************************/
/* [unique][uuid][object][local] */ 


#define CLIP_NAME_LENGTH 80
typedef 
enum tagETrnClipFlags
    {	CFWritable	= 1
    }	ETrnClipFlags;

typedef struct  tagSTrnClipInfo
    {
    DWORD dwSizeof;
    DWORD dwClipId;
    OLECHAR szClipName[ 80 ];
    DWORD length;
    LARGE_INTEGER storageSize;
    DWORD components;
    EPlayFrameType format;
    FILETIME mTime;
    FILETIME cTime;
    DWORD dwFlags;
    }	STrnClipInfo;


EXTERN_C const IID IID_ITrnMediaClip;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    interface DECLSPEC_UUID("8335e3ec-ab3b-11ce-8468-0000b468276b")
    ITrnMediaClip : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE QueryClipInfo( 
            STrnClipInfo __RPC_FAR *pInfo) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE ReadFrame( 
            DWORD frameNumber,
            STrnRect __RPC_FAR *pSourceRect,
            ETrnFrameAccessMode sourceMode,
            STrnRect __RPC_FAR *pDestRect,
            SPlayBitMap __RPC_FAR *pBitMap,
            ETrnFrameAccessMode destMode) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE WriteFrame( 
            DWORD frameNumber,
            STrnRect __RPC_FAR *pDestRect,
            ETrnFrameAccessMode destMode,
            STrnRect __RPC_FAR *pSourceRect,
            SPlayBitMap __RPC_FAR *pBitMap,
            ETrnFrameAccessMode sourceMode) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE CopyFrom( 
            /* [in] */ DWORD whichComponents,
            /* [in] */ ITrnMediaClip __RPC_FAR *pSourceClip,
            /* [in] */ DWORD sourceOffset,
            /* [in] */ DWORD sourceLength,
            /* [in] */ DWORD destinationOffset) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE WriteToStream( 
            /* [in] */ unsigned int startingOffset,
            /* [in] */ unsigned int framesToWrite,
            /* [in] */ unsigned int granularity,
            /* [in] */ IStream __RPC_FAR *pStream) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE ReadFromStream( 
            /* [in] */ unsigned int startingOffset,
            /* [in] */ unsigned int framesToRead,
            /* [in] */ unsigned int granularity,
            /* [in] */ IStream __RPC_FAR *pStream) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Play( 
            /* [in] */ const STrnTimeType __RPC_FAR *pTime,
            /* [in] */ DWORD whichComponents,
            /* [in] */ STrnPlayList __RPC_FAR *pList) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Record( 
            /* [in] */ const STrnTimeType __RPC_FAR *pTime,
            /* [in] */ DWORD whichComponents,
            /* [in] */ DWORD offsetFromStart,
            /* [in] */ DWORD numFields,
            /* [in] */ EVidSource sourceToRecord) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE UpdateClip( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE QueryClipUID( 
            /* [out][in] */ DWORD __RPC_FAR *bufSize,
            /* [out] */ OLECHAR __RPC_FAR *pUID) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE DeleteSelf( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE QueryInternalInterface( 
            REFIID riid,
            long index,
            void __RPC_FAR *__RPC_FAR *ppv) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct ITrnMediaClipVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            ITrnMediaClip __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            ITrnMediaClip __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            ITrnMediaClip __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryClipInfo )( 
            ITrnMediaClip __RPC_FAR * This,
            STrnClipInfo __RPC_FAR *pInfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *ReadFrame )( 
            ITrnMediaClip __RPC_FAR * This,
            DWORD frameNumber,
            STrnRect __RPC_FAR *pSourceRect,
            ETrnFrameAccessMode sourceMode,
            STrnRect __RPC_FAR *pDestRect,
            SPlayBitMap __RPC_FAR *pBitMap,
            ETrnFrameAccessMode destMode);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *WriteFrame )( 
            ITrnMediaClip __RPC_FAR * This,
            DWORD frameNumber,
            STrnRect __RPC_FAR *pDestRect,
            ETrnFrameAccessMode destMode,
            STrnRect __RPC_FAR *pSourceRect,
            SPlayBitMap __RPC_FAR *pBitMap,
            ETrnFrameAccessMode sourceMode);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *CopyFrom )( 
            ITrnMediaClip __RPC_FAR * This,
            /* [in] */ DWORD whichComponents,
            /* [in] */ ITrnMediaClip __RPC_FAR *pSourceClip,
            /* [in] */ DWORD sourceOffset,
            /* [in] */ DWORD sourceLength,
            /* [in] */ DWORD destinationOffset);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *WriteToStream )( 
            ITrnMediaClip __RPC_FAR * This,
            /* [in] */ unsigned int startingOffset,
            /* [in] */ unsigned int framesToWrite,
            /* [in] */ unsigned int granularity,
            /* [in] */ IStream __RPC_FAR *pStream);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *ReadFromStream )( 
            ITrnMediaClip __RPC_FAR * This,
            /* [in] */ unsigned int startingOffset,
            /* [in] */ unsigned int framesToRead,
            /* [in] */ unsigned int granularity,
            /* [in] */ IStream __RPC_FAR *pStream);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Play )( 
            ITrnMediaClip __RPC_FAR * This,
            /* [in] */ const STrnTimeType __RPC_FAR *pTime,
            /* [in] */ DWORD whichComponents,
            /* [in] */ STrnPlayList __RPC_FAR *pList);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Record )( 
            ITrnMediaClip __RPC_FAR * This,
            /* [in] */ const STrnTimeType __RPC_FAR *pTime,
            /* [in] */ DWORD whichComponents,
            /* [in] */ DWORD offsetFromStart,
            /* [in] */ DWORD numFields,
            /* [in] */ EVidSource sourceToRecord);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *UpdateClip )( 
            ITrnMediaClip __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryClipUID )( 
            ITrnMediaClip __RPC_FAR * This,
            /* [out][in] */ DWORD __RPC_FAR *bufSize,
            /* [out] */ OLECHAR __RPC_FAR *pUID);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *DeleteSelf )( 
            ITrnMediaClip __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInternalInterface )( 
            ITrnMediaClip __RPC_FAR * This,
            REFIID riid,
            long index,
            void __RPC_FAR *__RPC_FAR *ppv);
        
        END_INTERFACE
    } ITrnMediaClipVtbl;

    interface ITrnMediaClip
    {
        CONST_VTBL struct ITrnMediaClipVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ITrnMediaClip_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define ITrnMediaClip_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define ITrnMediaClip_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define ITrnMediaClip_QueryClipInfo(This,pInfo)	\
    (This)->lpVtbl -> QueryClipInfo(This,pInfo)

#define ITrnMediaClip_ReadFrame(This,frameNumber,pSourceRect,sourceMode,pDestRect,pBitMap,destMode)	\
    (This)->lpVtbl -> ReadFrame(This,frameNumber,pSourceRect,sourceMode,pDestRect,pBitMap,destMode)

#define ITrnMediaClip_WriteFrame(This,frameNumber,pDestRect,destMode,pSourceRect,pBitMap,sourceMode)	\
    (This)->lpVtbl -> WriteFrame(This,frameNumber,pDestRect,destMode,pSourceRect,pBitMap,sourceMode)

#define ITrnMediaClip_CopyFrom(This,whichComponents,pSourceClip,sourceOffset,sourceLength,destinationOffset)	\
    (This)->lpVtbl -> CopyFrom(This,whichComponents,pSourceClip,sourceOffset,sourceLength,destinationOffset)

#define ITrnMediaClip_WriteToStream(This,startingOffset,framesToWrite,granularity,pStream)	\
    (This)->lpVtbl -> WriteToStream(This,startingOffset,framesToWrite,granularity,pStream)

#define ITrnMediaClip_ReadFromStream(This,startingOffset,framesToRead,granularity,pStream)	\
    (This)->lpVtbl -> ReadFromStream(This,startingOffset,framesToRead,granularity,pStream)

#define ITrnMediaClip_Play(This,pTime,whichComponents,pList)	\
    (This)->lpVtbl -> Play(This,pTime,whichComponents,pList)

#define ITrnMediaClip_Record(This,pTime,whichComponents,offsetFromStart,numFields,sourceToRecord)	\
    (This)->lpVtbl -> Record(This,pTime,whichComponents,offsetFromStart,numFields,sourceToRecord)

#define ITrnMediaClip_UpdateClip(This)	\
    (This)->lpVtbl -> UpdateClip(This)

#define ITrnMediaClip_QueryClipUID(This,bufSize,pUID)	\
    (This)->lpVtbl -> QueryClipUID(This,bufSize,pUID)

#define ITrnMediaClip_DeleteSelf(This)	\
    (This)->lpVtbl -> DeleteSelf(This)

#define ITrnMediaClip_QueryInternalInterface(This,riid,index,ppv)	\
    (This)->lpVtbl -> QueryInternalInterface(This,riid,index,ppv)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE ITrnMediaClip_QueryClipInfo_Proxy( 
    ITrnMediaClip __RPC_FAR * This,
    STrnClipInfo __RPC_FAR *pInfo);


void __RPC_STUB ITrnMediaClip_QueryClipInfo_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE ITrnMediaClip_ReadFrame_Proxy( 
    ITrnMediaClip __RPC_FAR * This,
    DWORD frameNumber,
    STrnRect __RPC_FAR *pSourceRect,
    ETrnFrameAccessMode sourceMode,
    STrnRect __RPC_FAR *pDestRect,
    SPlayBitMap __RPC_FAR *pBitMap,
    ETrnFrameAccessMode destMode);


void __RPC_STUB ITrnMediaClip_ReadFrame_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE ITrnMediaClip_WriteFrame_Proxy( 
    ITrnMediaClip __RPC_FAR * This,
    DWORD frameNumber,
    STrnRect __RPC_FAR *pDestRect,
    ETrnFrameAccessMode destMode,
    STrnRect __RPC_FAR *pSourceRect,
    SPlayBitMap __RPC_FAR *pBitMap,
    ETrnFrameAccessMode sourceMode);


void __RPC_STUB ITrnMediaClip_WriteFrame_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE ITrnMediaClip_CopyFrom_Proxy( 
    ITrnMediaClip __RPC_FAR * This,
    /* [in] */ DWORD whichComponents,
    /* [in] */ ITrnMediaClip __RPC_FAR *pSourceClip,
    /* [in] */ DWORD sourceOffset,
    /* [in] */ DWORD sourceLength,
    /* [in] */ DWORD destinationOffset);


void __RPC_STUB ITrnMediaClip_CopyFrom_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE ITrnMediaClip_WriteToStream_Proxy( 
    ITrnMediaClip __RPC_FAR * This,
    /* [in] */ unsigned int startingOffset,
    /* [in] */ unsigned int framesToWrite,
    /* [in] */ unsigned int granularity,
    /* [in] */ IStream __RPC_FAR *pStream);


void __RPC_STUB ITrnMediaClip_WriteToStream_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE ITrnMediaClip_ReadFromStream_Proxy( 
    ITrnMediaClip __RPC_FAR * This,
    /* [in] */ unsigned int startingOffset,
    /* [in] */ unsigned int framesToRead,
    /* [in] */ unsigned int granularity,
    /* [in] */ IStream __RPC_FAR *pStream);


void __RPC_STUB ITrnMediaClip_ReadFromStream_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE ITrnMediaClip_Play_Proxy( 
    ITrnMediaClip __RPC_FAR * This,
    /* [in] */ const STrnTimeType __RPC_FAR *pTime,
    /* [in] */ DWORD whichComponents,
    /* [in] */ STrnPlayList __RPC_FAR *pList);


void __RPC_STUB ITrnMediaClip_Play_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE ITrnMediaClip_Record_Proxy( 
    ITrnMediaClip __RPC_FAR * This,
    /* [in] */ const STrnTimeType __RPC_FAR *pTime,
    /* [in] */ DWORD whichComponents,
    /* [in] */ DWORD offsetFromStart,
    /* [in] */ DWORD numFields,
    /* [in] */ EVidSource sourceToRecord);


void __RPC_STUB ITrnMediaClip_Record_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE ITrnMediaClip_UpdateClip_Proxy( 
    ITrnMediaClip __RPC_FAR * This);


void __RPC_STUB ITrnMediaClip_UpdateClip_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE ITrnMediaClip_QueryClipUID_Proxy( 
    ITrnMediaClip __RPC_FAR * This,
    /* [out][in] */ DWORD __RPC_FAR *bufSize,
    /* [out] */ OLECHAR __RPC_FAR *pUID);


void __RPC_STUB ITrnMediaClip_QueryClipUID_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE ITrnMediaClip_DeleteSelf_Proxy( 
    ITrnMediaClip __RPC_FAR * This);


void __RPC_STUB ITrnMediaClip_DeleteSelf_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE ITrnMediaClip_QueryInternalInterface_Proxy( 
    ITrnMediaClip __RPC_FAR * This,
    REFIID riid,
    long index,
    void __RPC_FAR *__RPC_FAR *ppv);


void __RPC_STUB ITrnMediaClip_QueryInternalInterface_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __ITrnMediaClip_INTERFACE_DEFINED__ */


#ifndef __ITrnMediaClip2_INTERFACE_DEFINED__
#define __ITrnMediaClip2_INTERFACE_DEFINED__

/****************************************
 * Generated header for interface: ITrnMediaClip2
 * at Tue Nov 23 05:28:32 1999
 * using MIDL 3.01.75
 ****************************************/
/* [unique][uuid][object][local] */ 


typedef ULONG STrnAudioSample;

typedef /* [public][public][public] */ struct  __MIDL_ITrnMediaClip2_0001
    {
    STrnAudioSample left;
    STrnAudioSample right;
    }	STrnStereoSample;

typedef /* [public][public][public] */ 
enum __MIDL_ITrnMediaClip2_0002
    {	ESName	= 0,
	ESDisplayName	= ESName + 1,
	ESVideoComponentName	= ESDisplayName + 1,
	ESAlphaComponentName	= ESVideoComponentName + 1,
	ESAudio12ComponentName	= ESAlphaComponentName + 1,
	ESAudio34ComponentName	= ESAudio12ComponentName + 1,
	ESAuthorName	= ESAudio34ComponentName + 1,
	ESProjectName	= ESAuthorName + 1,
	ESTapeName	= ESProjectName + 1,
	ESComments	= ESTapeName + 1
    }	EInfoString;

typedef /* [public][public][public] */ 
enum __MIDL_ITrnMediaClip2_0003
    {	ELComponents	= 0,
	ELVideoRoute	= ELComponents + 1,
	ELAlphaRoute	= ELVideoRoute + 1,
	ELAudio12Route	= ELAlphaRoute + 1,
	ELAudio34Route	= ELAudio12Route + 1,
	ELVideoSource1	= ELAudio34Route + 1,
	ELVideoSource2	= ELVideoSource1 + 1,
	ELPhysSource1	= ELVideoSource2 + 1,
	ELPhysSource2	= ELPhysSource1 + 1,
	ELVideoLength	= ELPhysSource2 + 1,
	ELCurrentFrame	= ELVideoLength + 1,
	ELFramesAllocated	= ELCurrentFrame + 1,
	ELAlphaLength	= ELFramesAllocated + 1,
	ELAudio12Length	= ELAlphaLength + 1,
	ELAudio34Length	= ELAudio12Length + 1,
	ELCompressionRatio	= ELAudio34Length + 1,
	ELCompressionQuality	= ELCompressionRatio + 1,
	ELTapeStartPoint	= ELCompressionQuality + 1,
	ELTapeEndPoint	= ELTapeStartPoint + 1,
	ELFrameWidth	= ELTapeEndPoint + 1,
	ELFrameHeight	= ELFrameWidth + 1,
	ELHandles	= ELFrameHeight + 1
    }	EInfoLong;

typedef /* [public][public][public] */ 
enum __MIDL_ITrnMediaClip2_0004
    {	EDVideoRate	= 0,
	EDAudioRate	= EDVideoRate + 1,
	EDVideoSize	= EDAudioRate + 1,
	EDAlphaSize	= EDVideoSize + 1,
	EDAudio12Size	= EDAlphaSize + 1,
	EDAudio34Size	= EDAudio12Size + 1
    }	EInfoDouble;


EXTERN_C const IID IID_ITrnMediaClip2;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    interface DECLSPEC_UUID("8335e407-ab3b-11ce-8468-0000b468276b")
    ITrnMediaClip2 : public ITrnMediaClip
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE WriteInternalToStream( 
            /* [in] */ unsigned int startingOffset,
            /* [in] */ unsigned int framesToWrite,
            /* [in] */ unsigned int granularity,
            /* [in] */ IStream __RPC_FAR *pStream) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE ReadInternalFromStream( 
            /* [in] */ unsigned int startingOffset,
            /* [in] */ unsigned int framesToRead,
            /* [in] */ unsigned int granularity,
            /* [in] */ IStream __RPC_FAR *pStream) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetDisplayName( 
            /* [out] */ LPOLESTR __RPC_FAR *ppszDisplayName) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetClipStream( 
            /* [in] */ DWORD streamId,
            /* [in] */ DWORD dwOpenMode,
            /* [in] */ REFIID riid,
            /* [out] */ void __RPC_FAR *__RPC_FAR *ppv) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetClipRouting( 
            DWORD dwComponent,
            DWORD dwDest) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE ReadAudioFromStream( 
            /* [in] */ DWORD startingSample,
            /* [in] */ DWORD sampleCount,
            /* [in] */ DWORD channel,
            /* [in] */ IStream __RPC_FAR *pStream) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE PutField( 
            /* [in] */ unsigned int fieldNumber,
            /* [in] */ DWORD fieldSize,
            /* [in] */ LPVOID pBuffer) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetField( 
            /* [in] */ unsigned int fieldNumber,
            /* [out] */ DWORD __RPC_FAR *pFieldSize,
            /* [in] */ LPVOID pBuffer) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE WriteAudioToStream( 
            /* [in] */ DWORD startingSample,
            /* [in] */ DWORD samplesToWrite,
            /* [in] */ DWORD channel,
            /* [in] */ IStream __RPC_FAR *pStream) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE PutAudio( 
            /* [in] */ DWORD startSample,
            /* [in] */ DWORD sampleCount,
            /* [in] */ DWORD channel,
            /* [in] */ STrnStereoSample __RPC_FAR *pBuffer) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetAudio( 
            /* [in] */ DWORD startSample,
            /* [in] */ DWORD sampleCount,
            /* [in] */ DWORD channel,
            /* [in] */ STrnStereoSample __RPC_FAR *pBuffer) = 0;
        
        virtual DWORD STDMETHODCALLTYPE GetAudioFieldPosition( 
            /* [in] */ DWORD field) = 0;
        
        virtual DWORD STDMETHODCALLTYPE GetAudioFieldLength( 
            /* [in] */ DWORD field) = 0;
        
        virtual DWORD STDMETHODCALLTYPE GetSampleRate( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE DuplicateFrame( 
            /* [in] */ DWORD dwCount) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetFrameFormat( 
            /* [out] */ DWORD __RPC_FAR *dwHeight,
            /* [out] */ EPlayFrameType __RPC_FAR *dwFormat) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE StartRecord( 
            /* [in] */ const STrnTimeType __RPC_FAR *pTime,
            /* [in] */ DWORD whichComponents,
            /* [in] */ DWORD offsetFromStart,
            /* [in] */ EVidSource sourceToRecord) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE EndRecord( 
            /* [in] */ const STrnTimeType __RPC_FAR *pTime) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetInfoString( 
            /* [in] */ EInfoString type,
            /* [out] */ OLECHAR __RPC_FAR *buffer,
            /* [in] */ DWORD dwBufferSize) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetInfoString( 
            /* [in] */ EInfoString type,
            /* [in] */ OLECHAR __RPC_FAR *buffer) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetInfoLong( 
            /* [in] */ EInfoLong type,
            /* [out] */ LONG __RPC_FAR *buffer) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetInfoLong( 
            /* [in] */ EInfoLong type,
            /* [in] */ LONG buffer) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetInfoDouble( 
            /* [in] */ EInfoDouble type,
            /* [out] */ double __RPC_FAR *buffer) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetInfoDouble( 
            /* [in] */ EInfoDouble type,
            /* [in] */ double buffer) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct ITrnMediaClip2Vtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            ITrnMediaClip2 __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            ITrnMediaClip2 __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            ITrnMediaClip2 __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryClipInfo )( 
            ITrnMediaClip2 __RPC_FAR * This,
            STrnClipInfo __RPC_FAR *pInfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *ReadFrame )( 
            ITrnMediaClip2 __RPC_FAR * This,
            DWORD frameNumber,
            STrnRect __RPC_FAR *pSourceRect,
            ETrnFrameAccessMode sourceMode,
            STrnRect __RPC_FAR *pDestRect,
            SPlayBitMap __RPC_FAR *pBitMap,
            ETrnFrameAccessMode destMode);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *WriteFrame )( 
            ITrnMediaClip2 __RPC_FAR * This,
            DWORD frameNumber,
            STrnRect __RPC_FAR *pDestRect,
            ETrnFrameAccessMode destMode,
            STrnRect __RPC_FAR *pSourceRect,
            SPlayBitMap __RPC_FAR *pBitMap,
            ETrnFrameAccessMode sourceMode);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *CopyFrom )( 
            ITrnMediaClip2 __RPC_FAR * This,
            /* [in] */ DWORD whichComponents,
            /* [in] */ ITrnMediaClip __RPC_FAR *pSourceClip,
            /* [in] */ DWORD sourceOffset,
            /* [in] */ DWORD sourceLength,
            /* [in] */ DWORD destinationOffset);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *WriteToStream )( 
            ITrnMediaClip2 __RPC_FAR * This,
            /* [in] */ unsigned int startingOffset,
            /* [in] */ unsigned int framesToWrite,
            /* [in] */ unsigned int granularity,
            /* [in] */ IStream __RPC_FAR *pStream);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *ReadFromStream )( 
            ITrnMediaClip2 __RPC_FAR * This,
            /* [in] */ unsigned int startingOffset,
            /* [in] */ unsigned int framesToRead,
            /* [in] */ unsigned int granularity,
            /* [in] */ IStream __RPC_FAR *pStream);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Play )( 
            ITrnMediaClip2 __RPC_FAR * This,
            /* [in] */ const STrnTimeType __RPC_FAR *pTime,
            /* [in] */ DWORD whichComponents,
            /* [in] */ STrnPlayList __RPC_FAR *pList);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Record )( 
            ITrnMediaClip2 __RPC_FAR * This,
            /* [in] */ const STrnTimeType __RPC_FAR *pTime,
            /* [in] */ DWORD whichComponents,
            /* [in] */ DWORD offsetFromStart,
            /* [in] */ DWORD numFields,
            /* [in] */ EVidSource sourceToRecord);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *UpdateClip )( 
            ITrnMediaClip2 __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryClipUID )( 
            ITrnMediaClip2 __RPC_FAR * This,
            /* [out][in] */ DWORD __RPC_FAR *bufSize,
            /* [out] */ OLECHAR __RPC_FAR *pUID);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *DeleteSelf )( 
            ITrnMediaClip2 __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInternalInterface )( 
            ITrnMediaClip2 __RPC_FAR * This,
            REFIID riid,
            long index,
            void __RPC_FAR *__RPC_FAR *ppv);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *WriteInternalToStream )( 
            ITrnMediaClip2 __RPC_FAR * This,
            /* [in] */ unsigned int startingOffset,
            /* [in] */ unsigned int framesToWrite,
            /* [in] */ unsigned int granularity,
            /* [in] */ IStream __RPC_FAR *pStream);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *ReadInternalFromStream )( 
            ITrnMediaClip2 __RPC_FAR * This,
            /* [in] */ unsigned int startingOffset,
            /* [in] */ unsigned int framesToRead,
            /* [in] */ unsigned int granularity,
            /* [in] */ IStream __RPC_FAR *pStream);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetDisplayName )( 
            ITrnMediaClip2 __RPC_FAR * This,
            /* [out] */ LPOLESTR __RPC_FAR *ppszDisplayName);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetClipStream )( 
            ITrnMediaClip2 __RPC_FAR * This,
            /* [in] */ DWORD streamId,
            /* [in] */ DWORD dwOpenMode,
            /* [in] */ REFIID riid,
            /* [out] */ void __RPC_FAR *__RPC_FAR *ppv);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetClipRouting )( 
            ITrnMediaClip2 __RPC_FAR * This,
            DWORD dwComponent,
            DWORD dwDest);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *ReadAudioFromStream )( 
            ITrnMediaClip2 __RPC_FAR * This,
            /* [in] */ DWORD startingSample,
            /* [in] */ DWORD sampleCount,
            /* [in] */ DWORD channel,
            /* [in] */ IStream __RPC_FAR *pStream);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *PutField )( 
            ITrnMediaClip2 __RPC_FAR * This,
            /* [in] */ unsigned int fieldNumber,
            /* [in] */ DWORD fieldSize,
            /* [in] */ LPVOID pBuffer);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetField )( 
            ITrnMediaClip2 __RPC_FAR * This,
            /* [in] */ unsigned int fieldNumber,
            /* [out] */ DWORD __RPC_FAR *pFieldSize,
            /* [in] */ LPVOID pBuffer);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *WriteAudioToStream )( 
            ITrnMediaClip2 __RPC_FAR * This,
            /* [in] */ DWORD startingSample,
            /* [in] */ DWORD samplesToWrite,
            /* [in] */ DWORD channel,
            /* [in] */ IStream __RPC_FAR *pStream);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *PutAudio )( 
            ITrnMediaClip2 __RPC_FAR * This,
            /* [in] */ DWORD startSample,
            /* [in] */ DWORD sampleCount,
            /* [in] */ DWORD channel,
            /* [in] */ STrnStereoSample __RPC_FAR *pBuffer);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetAudio )( 
            ITrnMediaClip2 __RPC_FAR * This,
            /* [in] */ DWORD startSample,
            /* [in] */ DWORD sampleCount,
            /* [in] */ DWORD channel,
            /* [in] */ STrnStereoSample __RPC_FAR *pBuffer);
        
        DWORD ( STDMETHODCALLTYPE __RPC_FAR *GetAudioFieldPosition )( 
            ITrnMediaClip2 __RPC_FAR * This,
            /* [in] */ DWORD field);
        
        DWORD ( STDMETHODCALLTYPE __RPC_FAR *GetAudioFieldLength )( 
            ITrnMediaClip2 __RPC_FAR * This,
            /* [in] */ DWORD field);
        
        DWORD ( STDMETHODCALLTYPE __RPC_FAR *GetSampleRate )( 
            ITrnMediaClip2 __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *DuplicateFrame )( 
            ITrnMediaClip2 __RPC_FAR * This,
            /* [in] */ DWORD dwCount);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetFrameFormat )( 
            ITrnMediaClip2 __RPC_FAR * This,
            /* [out] */ DWORD __RPC_FAR *dwHeight,
            /* [out] */ EPlayFrameType __RPC_FAR *dwFormat);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *StartRecord )( 
            ITrnMediaClip2 __RPC_FAR * This,
            /* [in] */ const STrnTimeType __RPC_FAR *pTime,
            /* [in] */ DWORD whichComponents,
            /* [in] */ DWORD offsetFromStart,
            /* [in] */ EVidSource sourceToRecord);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *EndRecord )( 
            ITrnMediaClip2 __RPC_FAR * This,
            /* [in] */ const STrnTimeType __RPC_FAR *pTime);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetInfoString )( 
            ITrnMediaClip2 __RPC_FAR * This,
            /* [in] */ EInfoString type,
            /* [out] */ OLECHAR __RPC_FAR *buffer,
            /* [in] */ DWORD dwBufferSize);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetInfoString )( 
            ITrnMediaClip2 __RPC_FAR * This,
            /* [in] */ EInfoString type,
            /* [in] */ OLECHAR __RPC_FAR *buffer);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetInfoLong )( 
            ITrnMediaClip2 __RPC_FAR * This,
            /* [in] */ EInfoLong type,
            /* [out] */ LONG __RPC_FAR *buffer);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetInfoLong )( 
            ITrnMediaClip2 __RPC_FAR * This,
            /* [in] */ EInfoLong type,
            /* [in] */ LONG buffer);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetInfoDouble )( 
            ITrnMediaClip2 __RPC_FAR * This,
            /* [in] */ EInfoDouble type,
            /* [out] */ double __RPC_FAR *buffer);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetInfoDouble )( 
            ITrnMediaClip2 __RPC_FAR * This,
            /* [in] */ EInfoDouble type,
            /* [in] */ double buffer);
        
        END_INTERFACE
    } ITrnMediaClip2Vtbl;

    interface ITrnMediaClip2
    {
        CONST_VTBL struct ITrnMediaClip2Vtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ITrnMediaClip2_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define ITrnMediaClip2_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define ITrnMediaClip2_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define ITrnMediaClip2_QueryClipInfo(This,pInfo)	\
    (This)->lpVtbl -> QueryClipInfo(This,pInfo)

#define ITrnMediaClip2_ReadFrame(This,frameNumber,pSourceRect,sourceMode,pDestRect,pBitMap,destMode)	\
    (This)->lpVtbl -> ReadFrame(This,frameNumber,pSourceRect,sourceMode,pDestRect,pBitMap,destMode)

#define ITrnMediaClip2_WriteFrame(This,frameNumber,pDestRect,destMode,pSourceRect,pBitMap,sourceMode)	\
    (This)->lpVtbl -> WriteFrame(This,frameNumber,pDestRect,destMode,pSourceRect,pBitMap,sourceMode)

#define ITrnMediaClip2_CopyFrom(This,whichComponents,pSourceClip,sourceOffset,sourceLength,destinationOffset)	\
    (This)->lpVtbl -> CopyFrom(This,whichComponents,pSourceClip,sourceOffset,sourceLength,destinationOffset)

#define ITrnMediaClip2_WriteToStream(This,startingOffset,framesToWrite,granularity,pStream)	\
    (This)->lpVtbl -> WriteToStream(This,startingOffset,framesToWrite,granularity,pStream)

#define ITrnMediaClip2_ReadFromStream(This,startingOffset,framesToRead,granularity,pStream)	\
    (This)->lpVtbl -> ReadFromStream(This,startingOffset,framesToRead,granularity,pStream)

#define ITrnMediaClip2_Play(This,pTime,whichComponents,pList)	\
    (This)->lpVtbl -> Play(This,pTime,whichComponents,pList)

#define ITrnMediaClip2_Record(This,pTime,whichComponents,offsetFromStart,numFields,sourceToRecord)	\
    (This)->lpVtbl -> Record(This,pTime,whichComponents,offsetFromStart,numFields,sourceToRecord)

#define ITrnMediaClip2_UpdateClip(This)	\
    (This)->lpVtbl -> UpdateClip(This)

#define ITrnMediaClip2_QueryClipUID(This,bufSize,pUID)	\
    (This)->lpVtbl -> QueryClipUID(This,bufSize,pUID)

#define ITrnMediaClip2_DeleteSelf(This)	\
    (This)->lpVtbl -> DeleteSelf(This)

#define ITrnMediaClip2_QueryInternalInterface(This,riid,index,ppv)	\
    (This)->lpVtbl -> QueryInternalInterface(This,riid,index,ppv)


#define ITrnMediaClip2_WriteInternalToStream(This,startingOffset,framesToWrite,granularity,pStream)	\
    (This)->lpVtbl -> WriteInternalToStream(This,startingOffset,framesToWrite,granularity,pStream)

#define ITrnMediaClip2_ReadInternalFromStream(This,startingOffset,framesToRead,granularity,pStream)	\
    (This)->lpVtbl -> ReadInternalFromStream(This,startingOffset,framesToRead,granularity,pStream)

#define ITrnMediaClip2_GetDisplayName(This,ppszDisplayName)	\
    (This)->lpVtbl -> GetDisplayName(This,ppszDisplayName)

#define ITrnMediaClip2_GetClipStream(This,streamId,dwOpenMode,riid,ppv)	\
    (This)->lpVtbl -> GetClipStream(This,streamId,dwOpenMode,riid,ppv)

#define ITrnMediaClip2_SetClipRouting(This,dwComponent,dwDest)	\
    (This)->lpVtbl -> SetClipRouting(This,dwComponent,dwDest)

#define ITrnMediaClip2_ReadAudioFromStream(This,startingSample,sampleCount,channel,pStream)	\
    (This)->lpVtbl -> ReadAudioFromStream(This,startingSample,sampleCount,channel,pStream)

#define ITrnMediaClip2_PutField(This,fieldNumber,fieldSize,pBuffer)	\
    (This)->lpVtbl -> PutField(This,fieldNumber,fieldSize,pBuffer)

#define ITrnMediaClip2_GetField(This,fieldNumber,pFieldSize,pBuffer)	\
    (This)->lpVtbl -> GetField(This,fieldNumber,pFieldSize,pBuffer)

#define ITrnMediaClip2_WriteAudioToStream(This,startingSample,samplesToWrite,channel,pStream)	\
    (This)->lpVtbl -> WriteAudioToStream(This,startingSample,samplesToWrite,channel,pStream)

#define ITrnMediaClip2_PutAudio(This,startSample,sampleCount,channel,pBuffer)	\
    (This)->lpVtbl -> PutAudio(This,startSample,sampleCount,channel,pBuffer)

#define ITrnMediaClip2_GetAudio(This,startSample,sampleCount,channel,pBuffer)	\
    (This)->lpVtbl -> GetAudio(This,startSample,sampleCount,channel,pBuffer)

#define ITrnMediaClip2_GetAudioFieldPosition(This,field)	\
    (This)->lpVtbl -> GetAudioFieldPosition(This,field)

#define ITrnMediaClip2_GetAudioFieldLength(This,field)	\
    (This)->lpVtbl -> GetAudioFieldLength(This,field)

#define ITrnMediaClip2_GetSampleRate(This)	\
    (This)->lpVtbl -> GetSampleRate(This)

#define ITrnMediaClip2_DuplicateFrame(This,dwCount)	\
    (This)->lpVtbl -> DuplicateFrame(This,dwCount)

#define ITrnMediaClip2_GetFrameFormat(This,dwHeight,dwFormat)	\
    (This)->lpVtbl -> GetFrameFormat(This,dwHeight,dwFormat)

#define ITrnMediaClip2_StartRecord(This,pTime,whichComponents,offsetFromStart,sourceToRecord)	\
    (This)->lpVtbl -> StartRecord(This,pTime,whichComponents,offsetFromStart,sourceToRecord)

#define ITrnMediaClip2_EndRecord(This,pTime)	\
    (This)->lpVtbl -> EndRecord(This,pTime)

#define ITrnMediaClip2_GetInfoString(This,type,buffer,dwBufferSize)	\
    (This)->lpVtbl -> GetInfoString(This,type,buffer,dwBufferSize)

#define ITrnMediaClip2_SetInfoString(This,type,buffer)	\
    (This)->lpVtbl -> SetInfoString(This,type,buffer)

#define ITrnMediaClip2_GetInfoLong(This,type,buffer)	\
    (This)->lpVtbl -> GetInfoLong(This,type,buffer)

#define ITrnMediaClip2_SetInfoLong(This,type,buffer)	\
    (This)->lpVtbl -> SetInfoLong(This,type,buffer)

#define ITrnMediaClip2_GetInfoDouble(This,type,buffer)	\
    (This)->lpVtbl -> GetInfoDouble(This,type,buffer)

#define ITrnMediaClip2_SetInfoDouble(This,type,buffer)	\
    (This)->lpVtbl -> SetInfoDouble(This,type,buffer)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE ITrnMediaClip2_WriteInternalToStream_Proxy( 
    ITrnMediaClip2 __RPC_FAR * This,
    /* [in] */ unsigned int startingOffset,
    /* [in] */ unsigned int framesToWrite,
    /* [in] */ unsigned int granularity,
    /* [in] */ IStream __RPC_FAR *pStream);


void __RPC_STUB ITrnMediaClip2_WriteInternalToStream_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE ITrnMediaClip2_ReadInternalFromStream_Proxy( 
    ITrnMediaClip2 __RPC_FAR * This,
    /* [in] */ unsigned int startingOffset,
    /* [in] */ unsigned int framesToRead,
    /* [in] */ unsigned int granularity,
    /* [in] */ IStream __RPC_FAR *pStream);


void __RPC_STUB ITrnMediaClip2_ReadInternalFromStream_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE ITrnMediaClip2_GetDisplayName_Proxy( 
    ITrnMediaClip2 __RPC_FAR * This,
    /* [out] */ LPOLESTR __RPC_FAR *ppszDisplayName);


void __RPC_STUB ITrnMediaClip2_GetDisplayName_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE ITrnMediaClip2_GetClipStream_Proxy( 
    ITrnMediaClip2 __RPC_FAR * This,
    /* [in] */ DWORD streamId,
    /* [in] */ DWORD dwOpenMode,
    /* [in] */ REFIID riid,
    /* [out] */ void __RPC_FAR *__RPC_FAR *ppv);


void __RPC_STUB ITrnMediaClip2_GetClipStream_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE ITrnMediaClip2_SetClipRouting_Proxy( 
    ITrnMediaClip2 __RPC_FAR * This,
    DWORD dwComponent,
    DWORD dwDest);


void __RPC_STUB ITrnMediaClip2_SetClipRouting_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE ITrnMediaClip2_ReadAudioFromStream_Proxy( 
    ITrnMediaClip2 __RPC_FAR * This,
    /* [in] */ DWORD startingSample,
    /* [in] */ DWORD sampleCount,
    /* [in] */ DWORD channel,
    /* [in] */ IStream __RPC_FAR *pStream);


void __RPC_STUB ITrnMediaClip2_ReadAudioFromStream_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE ITrnMediaClip2_PutField_Proxy( 
    ITrnMediaClip2 __RPC_FAR * This,
    /* [in] */ unsigned int fieldNumber,
    /* [in] */ DWORD fieldSize,
    /* [in] */ LPVOID pBuffer);


void __RPC_STUB ITrnMediaClip2_PutField_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE ITrnMediaClip2_GetField_Proxy( 
    ITrnMediaClip2 __RPC_FAR * This,
    /* [in] */ unsigned int fieldNumber,
    /* [out] */ DWORD __RPC_FAR *pFieldSize,
    /* [in] */ LPVOID pBuffer);


void __RPC_STUB ITrnMediaClip2_GetField_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE ITrnMediaClip2_WriteAudioToStream_Proxy( 
    ITrnMediaClip2 __RPC_FAR * This,
    /* [in] */ DWORD startingSample,
    /* [in] */ DWORD samplesToWrite,
    /* [in] */ DWORD channel,
    /* [in] */ IStream __RPC_FAR *pStream);


void __RPC_STUB ITrnMediaClip2_WriteAudioToStream_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE ITrnMediaClip2_PutAudio_Proxy( 
    ITrnMediaClip2 __RPC_FAR * This,
    /* [in] */ DWORD startSample,
    /* [in] */ DWORD sampleCount,
    /* [in] */ DWORD channel,
    /* [in] */ STrnStereoSample __RPC_FAR *pBuffer);


void __RPC_STUB ITrnMediaClip2_PutAudio_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE ITrnMediaClip2_GetAudio_Proxy( 
    ITrnMediaClip2 __RPC_FAR * This,
    /* [in] */ DWORD startSample,
    /* [in] */ DWORD sampleCount,
    /* [in] */ DWORD channel,
    /* [in] */ STrnStereoSample __RPC_FAR *pBuffer);


void __RPC_STUB ITrnMediaClip2_GetAudio_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


DWORD STDMETHODCALLTYPE ITrnMediaClip2_GetAudioFieldPosition_Proxy( 
    ITrnMediaClip2 __RPC_FAR * This,
    /* [in] */ DWORD field);


void __RPC_STUB ITrnMediaClip2_GetAudioFieldPosition_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


DWORD STDMETHODCALLTYPE ITrnMediaClip2_GetAudioFieldLength_Proxy( 
    ITrnMediaClip2 __RPC_FAR * This,
    /* [in] */ DWORD field);


void __RPC_STUB ITrnMediaClip2_GetAudioFieldLength_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


DWORD STDMETHODCALLTYPE ITrnMediaClip2_GetSampleRate_Proxy( 
    ITrnMediaClip2 __RPC_FAR * This);


void __RPC_STUB ITrnMediaClip2_GetSampleRate_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE ITrnMediaClip2_DuplicateFrame_Proxy( 
    ITrnMediaClip2 __RPC_FAR * This,
    /* [in] */ DWORD dwCount);


void __RPC_STUB ITrnMediaClip2_DuplicateFrame_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE ITrnMediaClip2_GetFrameFormat_Proxy( 
    ITrnMediaClip2 __RPC_FAR * This,
    /* [out] */ DWORD __RPC_FAR *dwHeight,
    /* [out] */ EPlayFrameType __RPC_FAR *dwFormat);


void __RPC_STUB ITrnMediaClip2_GetFrameFormat_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE ITrnMediaClip2_StartRecord_Proxy( 
    ITrnMediaClip2 __RPC_FAR * This,
    /* [in] */ const STrnTimeType __RPC_FAR *pTime,
    /* [in] */ DWORD whichComponents,
    /* [in] */ DWORD offsetFromStart,
    /* [in] */ EVidSource sourceToRecord);


void __RPC_STUB ITrnMediaClip2_StartRecord_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE ITrnMediaClip2_EndRecord_Proxy( 
    ITrnMediaClip2 __RPC_FAR * This,
    /* [in] */ const STrnTimeType __RPC_FAR *pTime);


void __RPC_STUB ITrnMediaClip2_EndRecord_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE ITrnMediaClip2_GetInfoString_Proxy( 
    ITrnMediaClip2 __RPC_FAR * This,
    /* [in] */ EInfoString type,
    /* [out] */ OLECHAR __RPC_FAR *buffer,
    /* [in] */ DWORD dwBufferSize);


void __RPC_STUB ITrnMediaClip2_GetInfoString_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE ITrnMediaClip2_SetInfoString_Proxy( 
    ITrnMediaClip2 __RPC_FAR * This,
    /* [in] */ EInfoString type,
    /* [in] */ OLECHAR __RPC_FAR *buffer);


void __RPC_STUB ITrnMediaClip2_SetInfoString_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE ITrnMediaClip2_GetInfoLong_Proxy( 
    ITrnMediaClip2 __RPC_FAR * This,
    /* [in] */ EInfoLong type,
    /* [out] */ LONG __RPC_FAR *buffer);


void __RPC_STUB ITrnMediaClip2_GetInfoLong_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE ITrnMediaClip2_SetInfoLong_Proxy( 
    ITrnMediaClip2 __RPC_FAR * This,
    /* [in] */ EInfoLong type,
    /* [in] */ LONG buffer);


void __RPC_STUB ITrnMediaClip2_SetInfoLong_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE ITrnMediaClip2_GetInfoDouble_Proxy( 
    ITrnMediaClip2 __RPC_FAR * This,
    /* [in] */ EInfoDouble type,
    /* [out] */ double __RPC_FAR *buffer);


void __RPC_STUB ITrnMediaClip2_GetInfoDouble_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE ITrnMediaClip2_SetInfoDouble_Proxy( 
    ITrnMediaClip2 __RPC_FAR * This,
    /* [in] */ EInfoDouble type,
    /* [in] */ double buffer);


void __RPC_STUB ITrnMediaClip2_SetInfoDouble_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __ITrnMediaClip2_INTERFACE_DEFINED__ */


#ifndef __ITrnNonLinearDiskRecorder_INTERFACE_DEFINED__
#define __ITrnNonLinearDiskRecorder_INTERFACE_DEFINED__

/****************************************
 * Generated header for interface: ITrnNonLinearDiskRecorder
 * at Tue Nov 23 05:28:32 1999
 * using MIDL 3.01.75
 ****************************************/
/* [unique][uuid][object][local] */ 


typedef 
enum tagETrnSizeUnit
    {	SUBytes	= 0,
	SUKBytes	= SUBytes + 1,
	SUMBytes	= SUKBytes + 1,
	SUGBytes	= SUMBytes + 1,
	SUFields	= 0x100,
	SUFrames	= SUFields + 1
    }	ETrnSizeUnit;

typedef 
enum tagETrnDDRVolumeFlags
    {	DVFDefault	= 1,
	DVFIncomplete	= 2
    }	ETrnDDRVolumeFlags;

typedef struct  tagSTrnVolumeInfo
    {
    DWORD dwSizeof;
    DWORD dwVolumeId;
    OLECHAR szVolumeName[ 80 ];
    DWORD dwVolumeFlags;
    DWORD dwComponents;
    ETrnSizeUnit tsuSizeUnit;
    LONGLONG qwVolumeSize;
    LONGLONG qwVolumeSpace;
    }	STrnVolumeInfo;

typedef struct  tagSTrnVolumeInfo2
    {
    DWORD dwSizeof;
    DWORD dwVolumeId;
    OLECHAR szVolumeName[ 80 ];
    DWORD dwVolumeFlags;
    DWORD dwComponents;
    ETrnSizeUnit tsuSizeUnit;
    LONGLONG qwVolumeSize;
    LONGLONG qwVolumeSpace;
    LONGLONG qwVolumeVideoSpace;
    LONGLONG qwVolumeAudioSpace;
    LONGLONG qwVolumeVideoSize;
    LONGLONG qwVolumeAudioSize;
    }	STrnVolumeInfo2;

typedef 
enum ETrnVolumeUpdateFlags
    {	VUFSetName	= 1,
	VUFSetFlags	= 2
    }	ETrnVolumeUpdateFlags;


enum __MIDL_ITrnNonLinearDiskRecorder_0001
    {	TMSTREAMID_VIDEO	= 0,
	TMSTREAMID_ALPHA	= TMSTREAMID_VIDEO + 1,
	TMSTREAMID_AUDIO12	= TMSTREAMID_ALPHA + 1,
	TMSTREAMID_AUDIO34	= TMSTREAMID_AUDIO12 + 1,
	TMSTREAMID_AUDIO56	= TMSTREAMID_AUDIO34 + 1,
	TMSTREAMID_AUDIO78	= TMSTREAMID_AUDIO56 + 1,
	TMSTREAMID_USERBASE	= 1000
    };

EXTERN_C const IID IID_ITrnNonLinearDiskRecorder;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    interface DECLSPEC_UUID("8335e7e5-ab3b-11ce-8468-0000b468276b")
    ITrnNonLinearDiskRecorder : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE Reset( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE EnumVolumes( 
            /* [out] */ IEnumSTrnVolumeInfo __RPC_FAR *__RPC_FAR *ppEnum) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE UpdateVolumeInfo( 
            /* [in] */ STrnVolumeInfo __RPC_FAR *pInfo,
            /* [in] */ DWORD flags) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE EnumClips( 
            /* [in] */ DWORD volumeId,
            /* [out] */ IEnumSTrnClipInfo __RPC_FAR *__RPC_FAR *ppEnum) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetClipStream( 
            /* [in] */ DWORD volumeId,
            /* [in] */ DWORD clipId,
            /* [in] */ DWORD streamId,
            /* [in] */ DWORD dwOpenMode,
            /* [in] */ REFIID riid,
            /* [out] */ void __RPC_FAR *__RPC_FAR *ppv) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE UpdateFileSystem( 
            DWORD volumeId) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetClipInfo( 
            /* [in] */ OLECHAR __RPC_FAR *pwszClipName,
            /* [out] */ STrnClipInfo __RPC_FAR *pInfo) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE RenameClip( 
            /* [string][in] */ const OLECHAR __RPC_FAR *pszOldClipName,
            /* [string][in] */ const OLECHAR __RPC_FAR *pszNewClipName) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetVolumeInfo( 
            /* [in] */ DWORD volumeId,
            /* [out] */ STrnVolumeInfo __RPC_FAR *pInfo) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct ITrnNonLinearDiskRecorderVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            ITrnNonLinearDiskRecorder __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            ITrnNonLinearDiskRecorder __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            ITrnNonLinearDiskRecorder __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Reset )( 
            ITrnNonLinearDiskRecorder __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *EnumVolumes )( 
            ITrnNonLinearDiskRecorder __RPC_FAR * This,
            /* [out] */ IEnumSTrnVolumeInfo __RPC_FAR *__RPC_FAR *ppEnum);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *UpdateVolumeInfo )( 
            ITrnNonLinearDiskRecorder __RPC_FAR * This,
            /* [in] */ STrnVolumeInfo __RPC_FAR *pInfo,
            /* [in] */ DWORD flags);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *EnumClips )( 
            ITrnNonLinearDiskRecorder __RPC_FAR * This,
            /* [in] */ DWORD volumeId,
            /* [out] */ IEnumSTrnClipInfo __RPC_FAR *__RPC_FAR *ppEnum);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetClipStream )( 
            ITrnNonLinearDiskRecorder __RPC_FAR * This,
            /* [in] */ DWORD volumeId,
            /* [in] */ DWORD clipId,
            /* [in] */ DWORD streamId,
            /* [in] */ DWORD dwOpenMode,
            /* [in] */ REFIID riid,
            /* [out] */ void __RPC_FAR *__RPC_FAR *ppv);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *UpdateFileSystem )( 
            ITrnNonLinearDiskRecorder __RPC_FAR * This,
            DWORD volumeId);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetClipInfo )( 
            ITrnNonLinearDiskRecorder __RPC_FAR * This,
            /* [in] */ OLECHAR __RPC_FAR *pwszClipName,
            /* [out] */ STrnClipInfo __RPC_FAR *pInfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *RenameClip )( 
            ITrnNonLinearDiskRecorder __RPC_FAR * This,
            /* [string][in] */ const OLECHAR __RPC_FAR *pszOldClipName,
            /* [string][in] */ const OLECHAR __RPC_FAR *pszNewClipName);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetVolumeInfo )( 
            ITrnNonLinearDiskRecorder __RPC_FAR * This,
            /* [in] */ DWORD volumeId,
            /* [out] */ STrnVolumeInfo __RPC_FAR *pInfo);
        
        END_INTERFACE
    } ITrnNonLinearDiskRecorderVtbl;

    interface ITrnNonLinearDiskRecorder
    {
        CONST_VTBL struct ITrnNonLinearDiskRecorderVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ITrnNonLinearDiskRecorder_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define ITrnNonLinearDiskRecorder_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define ITrnNonLinearDiskRecorder_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define ITrnNonLinearDiskRecorder_Reset(This)	\
    (This)->lpVtbl -> Reset(This)

#define ITrnNonLinearDiskRecorder_EnumVolumes(This,ppEnum)	\
    (This)->lpVtbl -> EnumVolumes(This,ppEnum)

#define ITrnNonLinearDiskRecorder_UpdateVolumeInfo(This,pInfo,flags)	\
    (This)->lpVtbl -> UpdateVolumeInfo(This,pInfo,flags)

#define ITrnNonLinearDiskRecorder_EnumClips(This,volumeId,ppEnum)	\
    (This)->lpVtbl -> EnumClips(This,volumeId,ppEnum)

#define ITrnNonLinearDiskRecorder_GetClipStream(This,volumeId,clipId,streamId,dwOpenMode,riid,ppv)	\
    (This)->lpVtbl -> GetClipStream(This,volumeId,clipId,streamId,dwOpenMode,riid,ppv)

#define ITrnNonLinearDiskRecorder_UpdateFileSystem(This,volumeId)	\
    (This)->lpVtbl -> UpdateFileSystem(This,volumeId)

#define ITrnNonLinearDiskRecorder_GetClipInfo(This,pwszClipName,pInfo)	\
    (This)->lpVtbl -> GetClipInfo(This,pwszClipName,pInfo)

#define ITrnNonLinearDiskRecorder_RenameClip(This,pszOldClipName,pszNewClipName)	\
    (This)->lpVtbl -> RenameClip(This,pszOldClipName,pszNewClipName)

#define ITrnNonLinearDiskRecorder_GetVolumeInfo(This,volumeId,pInfo)	\
    (This)->lpVtbl -> GetVolumeInfo(This,volumeId,pInfo)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE ITrnNonLinearDiskRecorder_Reset_Proxy( 
    ITrnNonLinearDiskRecorder __RPC_FAR * This);


void __RPC_STUB ITrnNonLinearDiskRecorder_Reset_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE ITrnNonLinearDiskRecorder_EnumVolumes_Proxy( 
    ITrnNonLinearDiskRecorder __RPC_FAR * This,
    /* [out] */ IEnumSTrnVolumeInfo __RPC_FAR *__RPC_FAR *ppEnum);


void __RPC_STUB ITrnNonLinearDiskRecorder_EnumVolumes_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE ITrnNonLinearDiskRecorder_UpdateVolumeInfo_Proxy( 
    ITrnNonLinearDiskRecorder __RPC_FAR * This,
    /* [in] */ STrnVolumeInfo __RPC_FAR *pInfo,
    /* [in] */ DWORD flags);


void __RPC_STUB ITrnNonLinearDiskRecorder_UpdateVolumeInfo_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE ITrnNonLinearDiskRecorder_EnumClips_Proxy( 
    ITrnNonLinearDiskRecorder __RPC_FAR * This,
    /* [in] */ DWORD volumeId,
    /* [out] */ IEnumSTrnClipInfo __RPC_FAR *__RPC_FAR *ppEnum);


void __RPC_STUB ITrnNonLinearDiskRecorder_EnumClips_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE ITrnNonLinearDiskRecorder_GetClipStream_Proxy( 
    ITrnNonLinearDiskRecorder __RPC_FAR * This,
    /* [in] */ DWORD volumeId,
    /* [in] */ DWORD clipId,
    /* [in] */ DWORD streamId,
    /* [in] */ DWORD dwOpenMode,
    /* [in] */ REFIID riid,
    /* [out] */ void __RPC_FAR *__RPC_FAR *ppv);


void __RPC_STUB ITrnNonLinearDiskRecorder_GetClipStream_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE ITrnNonLinearDiskRecorder_UpdateFileSystem_Proxy( 
    ITrnNonLinearDiskRecorder __RPC_FAR * This,
    DWORD volumeId);


void __RPC_STUB ITrnNonLinearDiskRecorder_UpdateFileSystem_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE ITrnNonLinearDiskRecorder_GetClipInfo_Proxy( 
    ITrnNonLinearDiskRecorder __RPC_FAR * This,
    /* [in] */ OLECHAR __RPC_FAR *pwszClipName,
    /* [out] */ STrnClipInfo __RPC_FAR *pInfo);


void __RPC_STUB ITrnNonLinearDiskRecorder_GetClipInfo_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE ITrnNonLinearDiskRecorder_RenameClip_Proxy( 
    ITrnNonLinearDiskRecorder __RPC_FAR * This,
    /* [string][in] */ const OLECHAR __RPC_FAR *pszOldClipName,
    /* [string][in] */ const OLECHAR __RPC_FAR *pszNewClipName);


void __RPC_STUB ITrnNonLinearDiskRecorder_RenameClip_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE ITrnNonLinearDiskRecorder_GetVolumeInfo_Proxy( 
    ITrnNonLinearDiskRecorder __RPC_FAR * This,
    /* [in] */ DWORD volumeId,
    /* [out] */ STrnVolumeInfo __RPC_FAR *pInfo);


void __RPC_STUB ITrnNonLinearDiskRecorder_GetVolumeInfo_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __ITrnNonLinearDiskRecorder_INTERFACE_DEFINED__ */


#ifndef __IEnumSTrnVolumeInfo_INTERFACE_DEFINED__
#define __IEnumSTrnVolumeInfo_INTERFACE_DEFINED__

/****************************************
 * Generated header for interface: IEnumSTrnVolumeInfo
 * at Tue Nov 23 05:28:32 1999
 * using MIDL 3.01.75
 ****************************************/
/* [unique][uuid][object][local] */ 



EXTERN_C const IID IID_IEnumSTrnVolumeInfo;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    interface DECLSPEC_UUID("8335e456-ab3b-11ce-8468-0000b468276b")
    IEnumSTrnVolumeInfo : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE Next( 
            /* [in] */ ULONG celt,
            /* [out] */ STrnVolumeInfo __RPC_FAR *rgelt,
            /* [out] */ ULONG __RPC_FAR *pceltFetched) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Skip( 
            /* [in] */ ULONG celt) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Reset( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Clone( 
            /* [out] */ IEnumSTrnVolumeInfo __RPC_FAR *__RPC_FAR *ppenum) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IEnumSTrnVolumeInfoVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            IEnumSTrnVolumeInfo __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            IEnumSTrnVolumeInfo __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            IEnumSTrnVolumeInfo __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Next )( 
            IEnumSTrnVolumeInfo __RPC_FAR * This,
            /* [in] */ ULONG celt,
            /* [out] */ STrnVolumeInfo __RPC_FAR *rgelt,
            /* [out] */ ULONG __RPC_FAR *pceltFetched);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Skip )( 
            IEnumSTrnVolumeInfo __RPC_FAR * This,
            /* [in] */ ULONG celt);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Reset )( 
            IEnumSTrnVolumeInfo __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Clone )( 
            IEnumSTrnVolumeInfo __RPC_FAR * This,
            /* [out] */ IEnumSTrnVolumeInfo __RPC_FAR *__RPC_FAR *ppenum);
        
        END_INTERFACE
    } IEnumSTrnVolumeInfoVtbl;

    interface IEnumSTrnVolumeInfo
    {
        CONST_VTBL struct IEnumSTrnVolumeInfoVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IEnumSTrnVolumeInfo_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IEnumSTrnVolumeInfo_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IEnumSTrnVolumeInfo_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IEnumSTrnVolumeInfo_Next(This,celt,rgelt,pceltFetched)	\
    (This)->lpVtbl -> Next(This,celt,rgelt,pceltFetched)

#define IEnumSTrnVolumeInfo_Skip(This,celt)	\
    (This)->lpVtbl -> Skip(This,celt)

#define IEnumSTrnVolumeInfo_Reset(This)	\
    (This)->lpVtbl -> Reset(This)

#define IEnumSTrnVolumeInfo_Clone(This,ppenum)	\
    (This)->lpVtbl -> Clone(This,ppenum)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE IEnumSTrnVolumeInfo_Next_Proxy( 
    IEnumSTrnVolumeInfo __RPC_FAR * This,
    /* [in] */ ULONG celt,
    /* [out] */ STrnVolumeInfo __RPC_FAR *rgelt,
    /* [out] */ ULONG __RPC_FAR *pceltFetched);


void __RPC_STUB IEnumSTrnVolumeInfo_Next_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IEnumSTrnVolumeInfo_Skip_Proxy( 
    IEnumSTrnVolumeInfo __RPC_FAR * This,
    /* [in] */ ULONG celt);


void __RPC_STUB IEnumSTrnVolumeInfo_Skip_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IEnumSTrnVolumeInfo_Reset_Proxy( 
    IEnumSTrnVolumeInfo __RPC_FAR * This);


void __RPC_STUB IEnumSTrnVolumeInfo_Reset_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IEnumSTrnVolumeInfo_Clone_Proxy( 
    IEnumSTrnVolumeInfo __RPC_FAR * This,
    /* [out] */ IEnumSTrnVolumeInfo __RPC_FAR *__RPC_FAR *ppenum);


void __RPC_STUB IEnumSTrnVolumeInfo_Clone_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IEnumSTrnVolumeInfo_INTERFACE_DEFINED__ */


#ifndef __IEnumSTrnClipInfo_INTERFACE_DEFINED__
#define __IEnumSTrnClipInfo_INTERFACE_DEFINED__

/****************************************
 * Generated header for interface: IEnumSTrnClipInfo
 * at Tue Nov 23 05:28:32 1999
 * using MIDL 3.01.75
 ****************************************/
/* [unique][uuid][object][local] */ 



EXTERN_C const IID IID_IEnumSTrnClipInfo;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    interface DECLSPEC_UUID("8335e7ea-ab3b-11ce-8468-0000b468276b")
    IEnumSTrnClipInfo : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE Next( 
            /* [in] */ ULONG celt,
            /* [out] */ STrnClipInfo __RPC_FAR *rgelt,
            /* [out] */ ULONG __RPC_FAR *pceltFetched) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Skip( 
            /* [in] */ ULONG celt) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Reset( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Clone( 
            /* [out] */ IEnumSTrnClipInfo __RPC_FAR *__RPC_FAR *ppenum) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IEnumSTrnClipInfoVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            IEnumSTrnClipInfo __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            IEnumSTrnClipInfo __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            IEnumSTrnClipInfo __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Next )( 
            IEnumSTrnClipInfo __RPC_FAR * This,
            /* [in] */ ULONG celt,
            /* [out] */ STrnClipInfo __RPC_FAR *rgelt,
            /* [out] */ ULONG __RPC_FAR *pceltFetched);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Skip )( 
            IEnumSTrnClipInfo __RPC_FAR * This,
            /* [in] */ ULONG celt);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Reset )( 
            IEnumSTrnClipInfo __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Clone )( 
            IEnumSTrnClipInfo __RPC_FAR * This,
            /* [out] */ IEnumSTrnClipInfo __RPC_FAR *__RPC_FAR *ppenum);
        
        END_INTERFACE
    } IEnumSTrnClipInfoVtbl;

    interface IEnumSTrnClipInfo
    {
        CONST_VTBL struct IEnumSTrnClipInfoVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IEnumSTrnClipInfo_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IEnumSTrnClipInfo_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IEnumSTrnClipInfo_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IEnumSTrnClipInfo_Next(This,celt,rgelt,pceltFetched)	\
    (This)->lpVtbl -> Next(This,celt,rgelt,pceltFetched)

#define IEnumSTrnClipInfo_Skip(This,celt)	\
    (This)->lpVtbl -> Skip(This,celt)

#define IEnumSTrnClipInfo_Reset(This)	\
    (This)->lpVtbl -> Reset(This)

#define IEnumSTrnClipInfo_Clone(This,ppenum)	\
    (This)->lpVtbl -> Clone(This,ppenum)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE IEnumSTrnClipInfo_Next_Proxy( 
    IEnumSTrnClipInfo __RPC_FAR * This,
    /* [in] */ ULONG celt,
    /* [out] */ STrnClipInfo __RPC_FAR *rgelt,
    /* [out] */ ULONG __RPC_FAR *pceltFetched);


void __RPC_STUB IEnumSTrnClipInfo_Next_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IEnumSTrnClipInfo_Skip_Proxy( 
    IEnumSTrnClipInfo __RPC_FAR * This,
    /* [in] */ ULONG celt);


void __RPC_STUB IEnumSTrnClipInfo_Skip_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IEnumSTrnClipInfo_Reset_Proxy( 
    IEnumSTrnClipInfo __RPC_FAR * This);


void __RPC_STUB IEnumSTrnClipInfo_Reset_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IEnumSTrnClipInfo_Clone_Proxy( 
    IEnumSTrnClipInfo __RPC_FAR * This,
    /* [out] */ IEnumSTrnClipInfo __RPC_FAR *__RPC_FAR *ppenum);


void __RPC_STUB IEnumSTrnClipInfo_Clone_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IEnumSTrnClipInfo_INTERFACE_DEFINED__ */


#ifndef __ITrnVideoCompressionCODEC_INTERFACE_DEFINED__
#define __ITrnVideoCompressionCODEC_INTERFACE_DEFINED__

/****************************************
 * Generated header for interface: ITrnVideoCompressionCODEC
 * at Tue Nov 23 05:28:32 1999
 * using MIDL 3.01.75
 ****************************************/
/* [unique][uuid][object][local] */ 


typedef 
enum tagETrnCompressionTechnology
    {	CTWavelet	= 0,
	CTJPEG	= CTWavelet + 1,
	CTMPEG	= CTJPEG + 1,
	CTHardwareAccelerated	= 0x80000000
    }	ETrnCompressionTechnology;

typedef struct  tagSTrnCODECInfo
    {
    DWORD dwSizeof;
    DWORD dwInputFrameTypes;
    DWORD dwOutputFrameTypes;
    DWORD dwCODECType;
    }	STrnCODECInfo;

typedef 
enum tagETrnCompressionQualityRating
    {	CQRBitsPerPixel	= 0,
	CQRQualityLevel	= CQRBitsPerPixel + 1,
	CQRCODECInfo	= CQRQualityLevel + 1
    }	ETrnCompressionQualityRating;


EXTERN_C const IID IID_ITrnVideoCompressionCODEC;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    interface DECLSPEC_UUID("8335e3f2-ab3b-11ce-8468-0000b468276b")
    ITrnVideoCompressionCODEC : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE GetCODECInfo( 
            /* [out][in] */ STrnCODECInfo __RPC_FAR *pInfo) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetCompression( 
            /* [in] */ ETrnCompressionQualityRating dwQuality,
            /* [in] */ DWORD dwLevel,
            /* [out][in] */ LPVOID __RPC_FAR *ppCODECInfo,
            /* [out] */ DWORD __RPC_FAR *pcbCODECInfo) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetCompression( 
            /* [out] */ LPVOID __RPC_FAR *ppCODECInfo,
            /* [out] */ DWORD __RPC_FAR *pcbCODECInfo) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE CompressField( 
            /* [in] */ DWORD dwHeight,
            /* [in] */ DWORD dwWidth,
            /* [in] */ DWORD dwStride,
            /* [in] */ EPlayFrameType dwPixelFormat,
            /* [in] */ LPVOID pImage,
            /* [in] */ LPVOID pBuffer,
            /* [in] */ LPVOID pCODECInfo,
            /* [out] */ DWORD __RPC_FAR *pcbCompSize) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE DecompressField( 
            /* [in] */ LPVOID pBuffer,
            /* [in] */ DWORD dwBufferSize,
            /* [in] */ DWORD dwWidth,
            /* [in] */ DWORD dwHeight,
            /* [in] */ EPlayFrameType dwPixelFormat,
            /* [in] */ LPVOID pImage,
            /* [out] */ LPVOID __RPC_FAR *ppCODECInfo,
            /* [out] */ DWORD __RPC_FAR *pcbCODECInfo) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct ITrnVideoCompressionCODECVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            ITrnVideoCompressionCODEC __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            ITrnVideoCompressionCODEC __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            ITrnVideoCompressionCODEC __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetCODECInfo )( 
            ITrnVideoCompressionCODEC __RPC_FAR * This,
            /* [out][in] */ STrnCODECInfo __RPC_FAR *pInfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetCompression )( 
            ITrnVideoCompressionCODEC __RPC_FAR * This,
            /* [in] */ ETrnCompressionQualityRating dwQuality,
            /* [in] */ DWORD dwLevel,
            /* [out][in] */ LPVOID __RPC_FAR *ppCODECInfo,
            /* [out] */ DWORD __RPC_FAR *pcbCODECInfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetCompression )( 
            ITrnVideoCompressionCODEC __RPC_FAR * This,
            /* [out] */ LPVOID __RPC_FAR *ppCODECInfo,
            /* [out] */ DWORD __RPC_FAR *pcbCODECInfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *CompressField )( 
            ITrnVideoCompressionCODEC __RPC_FAR * This,
            /* [in] */ DWORD dwHeight,
            /* [in] */ DWORD dwWidth,
            /* [in] */ DWORD dwStride,
            /* [in] */ EPlayFrameType dwPixelFormat,
            /* [in] */ LPVOID pImage,
            /* [in] */ LPVOID pBuffer,
            /* [in] */ LPVOID pCODECInfo,
            /* [out] */ DWORD __RPC_FAR *pcbCompSize);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *DecompressField )( 
            ITrnVideoCompressionCODEC __RPC_FAR * This,
            /* [in] */ LPVOID pBuffer,
            /* [in] */ DWORD dwBufferSize,
            /* [in] */ DWORD dwWidth,
            /* [in] */ DWORD dwHeight,
            /* [in] */ EPlayFrameType dwPixelFormat,
            /* [in] */ LPVOID pImage,
            /* [out] */ LPVOID __RPC_FAR *ppCODECInfo,
            /* [out] */ DWORD __RPC_FAR *pcbCODECInfo);
        
        END_INTERFACE
    } ITrnVideoCompressionCODECVtbl;

    interface ITrnVideoCompressionCODEC
    {
        CONST_VTBL struct ITrnVideoCompressionCODECVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ITrnVideoCompressionCODEC_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define ITrnVideoCompressionCODEC_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define ITrnVideoCompressionCODEC_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define ITrnVideoCompressionCODEC_GetCODECInfo(This,pInfo)	\
    (This)->lpVtbl -> GetCODECInfo(This,pInfo)

#define ITrnVideoCompressionCODEC_SetCompression(This,dwQuality,dwLevel,ppCODECInfo,pcbCODECInfo)	\
    (This)->lpVtbl -> SetCompression(This,dwQuality,dwLevel,ppCODECInfo,pcbCODECInfo)

#define ITrnVideoCompressionCODEC_GetCompression(This,ppCODECInfo,pcbCODECInfo)	\
    (This)->lpVtbl -> GetCompression(This,ppCODECInfo,pcbCODECInfo)

#define ITrnVideoCompressionCODEC_CompressField(This,dwHeight,dwWidth,dwStride,dwPixelFormat,pImage,pBuffer,pCODECInfo,pcbCompSize)	\
    (This)->lpVtbl -> CompressField(This,dwHeight,dwWidth,dwStride,dwPixelFormat,pImage,pBuffer,pCODECInfo,pcbCompSize)

#define ITrnVideoCompressionCODEC_DecompressField(This,pBuffer,dwBufferSize,dwWidth,dwHeight,dwPixelFormat,pImage,ppCODECInfo,pcbCODECInfo)	\
    (This)->lpVtbl -> DecompressField(This,pBuffer,dwBufferSize,dwWidth,dwHeight,dwPixelFormat,pImage,ppCODECInfo,pcbCODECInfo)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE ITrnVideoCompressionCODEC_GetCODECInfo_Proxy( 
    ITrnVideoCompressionCODEC __RPC_FAR * This,
    /* [out][in] */ STrnCODECInfo __RPC_FAR *pInfo);


void __RPC_STUB ITrnVideoCompressionCODEC_GetCODECInfo_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE ITrnVideoCompressionCODEC_SetCompression_Proxy( 
    ITrnVideoCompressionCODEC __RPC_FAR * This,
    /* [in] */ ETrnCompressionQualityRating dwQuality,
    /* [in] */ DWORD dwLevel,
    /* [out][in] */ LPVOID __RPC_FAR *ppCODECInfo,
    /* [out] */ DWORD __RPC_FAR *pcbCODECInfo);


void __RPC_STUB ITrnVideoCompressionCODEC_SetCompression_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE ITrnVideoCompressionCODEC_GetCompression_Proxy( 
    ITrnVideoCompressionCODEC __RPC_FAR * This,
    /* [out] */ LPVOID __RPC_FAR *ppCODECInfo,
    /* [out] */ DWORD __RPC_FAR *pcbCODECInfo);


void __RPC_STUB ITrnVideoCompressionCODEC_GetCompression_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE ITrnVideoCompressionCODEC_CompressField_Proxy( 
    ITrnVideoCompressionCODEC __RPC_FAR * This,
    /* [in] */ DWORD dwHeight,
    /* [in] */ DWORD dwWidth,
    /* [in] */ DWORD dwStride,
    /* [in] */ EPlayFrameType dwPixelFormat,
    /* [in] */ LPVOID pImage,
    /* [in] */ LPVOID pBuffer,
    /* [in] */ LPVOID pCODECInfo,
    /* [out] */ DWORD __RPC_FAR *pcbCompSize);


void __RPC_STUB ITrnVideoCompressionCODEC_CompressField_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE ITrnVideoCompressionCODEC_DecompressField_Proxy( 
    ITrnVideoCompressionCODEC __RPC_FAR * This,
    /* [in] */ LPVOID pBuffer,
    /* [in] */ DWORD dwBufferSize,
    /* [in] */ DWORD dwWidth,
    /* [in] */ DWORD dwHeight,
    /* [in] */ EPlayFrameType dwPixelFormat,
    /* [in] */ LPVOID pImage,
    /* [out] */ LPVOID __RPC_FAR *ppCODECInfo,
    /* [out] */ DWORD __RPC_FAR *pcbCODECInfo);


void __RPC_STUB ITrnVideoCompressionCODEC_DecompressField_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __ITrnVideoCompressionCODEC_INTERFACE_DEFINED__ */


/* Additional Prototypes for ALL interfaces */

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif
