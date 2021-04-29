/* this ALWAYS GENERATED file contains the definitions for the interfaces */


/* File created by MIDL compiler version 3.01.75 */
/* at Tue Nov 23 05:02:06 1999
 */
/* Compiler settings for seglist.idl:
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

#ifndef __seglist_h__
#define __seglist_h__

#ifdef __cplusplus
extern "C"{
#endif 

/* Forward Declarations */ 

#ifndef __IValidSegmentList_FWD_DEFINED__
#define __IValidSegmentList_FWD_DEFINED__
typedef interface IValidSegmentList IValidSegmentList;
#endif 	/* __IValidSegmentList_FWD_DEFINED__ */


#ifndef __IValidSegmentList2_FWD_DEFINED__
#define __IValidSegmentList2_FWD_DEFINED__
typedef interface IValidSegmentList2 IValidSegmentList2;
#endif 	/* __IValidSegmentList2_FWD_DEFINED__ */


/* header files for imported files */
#include "unknwn.h"

void __RPC_FAR * __RPC_USER MIDL_user_allocate(size_t);
void __RPC_USER MIDL_user_free( void __RPC_FAR * ); 

#ifndef __IValidSegmentList_INTERFACE_DEFINED__
#define __IValidSegmentList_INTERFACE_DEFINED__

/****************************************
 * Generated header for interface: IValidSegmentList
 * at Tue Nov 23 05:02:06 1999
 * using MIDL 3.01.75
 ****************************************/
/* [uuid][object][local] */ 



EXTERN_C const IID IID_IValidSegmentList;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    interface DECLSPEC_UUID("8335e626-ab3b-11ce-8468-0000b468276b")
    IValidSegmentList : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE GetInvalidInterval( 
            /* [in] */ long startTime,
            /* [out] */ long __RPC_FAR *actualStart,
            /* [out] */ long __RPC_FAR *actualLength) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE InvalidateInterval( 
            /* [in] */ long startTime,
            /* [in] */ long length) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE ValidateInterval( 
            /* [in] */ long startTime,
            /* [in] */ long length) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetSurroundingInvalidInterval( 
            /* [in] */ long startTime,
            /* [out] */ long __RPC_FAR *actualStart,
            /* [out] */ long __RPC_FAR *actualLength) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IValidSegmentListVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            IValidSegmentList __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            IValidSegmentList __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            IValidSegmentList __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetInvalidInterval )( 
            IValidSegmentList __RPC_FAR * This,
            /* [in] */ long startTime,
            /* [out] */ long __RPC_FAR *actualStart,
            /* [out] */ long __RPC_FAR *actualLength);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *InvalidateInterval )( 
            IValidSegmentList __RPC_FAR * This,
            /* [in] */ long startTime,
            /* [in] */ long length);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *ValidateInterval )( 
            IValidSegmentList __RPC_FAR * This,
            /* [in] */ long startTime,
            /* [in] */ long length);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetSurroundingInvalidInterval )( 
            IValidSegmentList __RPC_FAR * This,
            /* [in] */ long startTime,
            /* [out] */ long __RPC_FAR *actualStart,
            /* [out] */ long __RPC_FAR *actualLength);
        
        END_INTERFACE
    } IValidSegmentListVtbl;

    interface IValidSegmentList
    {
        CONST_VTBL struct IValidSegmentListVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IValidSegmentList_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IValidSegmentList_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IValidSegmentList_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IValidSegmentList_GetInvalidInterval(This,startTime,actualStart,actualLength)	\
    (This)->lpVtbl -> GetInvalidInterval(This,startTime,actualStart,actualLength)

#define IValidSegmentList_InvalidateInterval(This,startTime,length)	\
    (This)->lpVtbl -> InvalidateInterval(This,startTime,length)

#define IValidSegmentList_ValidateInterval(This,startTime,length)	\
    (This)->lpVtbl -> ValidateInterval(This,startTime,length)

#define IValidSegmentList_GetSurroundingInvalidInterval(This,startTime,actualStart,actualLength)	\
    (This)->lpVtbl -> GetSurroundingInvalidInterval(This,startTime,actualStart,actualLength)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE IValidSegmentList_GetInvalidInterval_Proxy( 
    IValidSegmentList __RPC_FAR * This,
    /* [in] */ long startTime,
    /* [out] */ long __RPC_FAR *actualStart,
    /* [out] */ long __RPC_FAR *actualLength);


void __RPC_STUB IValidSegmentList_GetInvalidInterval_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IValidSegmentList_InvalidateInterval_Proxy( 
    IValidSegmentList __RPC_FAR * This,
    /* [in] */ long startTime,
    /* [in] */ long length);


void __RPC_STUB IValidSegmentList_InvalidateInterval_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IValidSegmentList_ValidateInterval_Proxy( 
    IValidSegmentList __RPC_FAR * This,
    /* [in] */ long startTime,
    /* [in] */ long length);


void __RPC_STUB IValidSegmentList_ValidateInterval_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IValidSegmentList_GetSurroundingInvalidInterval_Proxy( 
    IValidSegmentList __RPC_FAR * This,
    /* [in] */ long startTime,
    /* [out] */ long __RPC_FAR *actualStart,
    /* [out] */ long __RPC_FAR *actualLength);


void __RPC_STUB IValidSegmentList_GetSurroundingInvalidInterval_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IValidSegmentList_INTERFACE_DEFINED__ */


#ifndef __IValidSegmentList2_INTERFACE_DEFINED__
#define __IValidSegmentList2_INTERFACE_DEFINED__

/****************************************
 * Generated header for interface: IValidSegmentList2
 * at Tue Nov 23 05:02:06 1999
 * using MIDL 3.01.75
 ****************************************/
/* [uuid][object][local] */ 



EXTERN_C const IID IID_IValidSegmentList2;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    interface DECLSPEC_UUID("8335e61a-ab3b-11ce-8468-0000b468276b")
    IValidSegmentList2 : public IValidSegmentList
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE GetInvalidIntervalMask( 
            /* [in] */ long startTime,
            /* [in] */ ULONG interestMask,
            /* [in] */ ULONG endIntervalMask,
            /* [out] */ long __RPC_FAR *actualStart,
            /* [out] */ long __RPC_FAR *actualLength,
            /* [out] */ ULONG __RPC_FAR *mask) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE InvalidateIntervalMask( 
            /* [in] */ long startTime,
            /* [in] */ long length,
            /* [in] */ ULONG mask) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE ValidateIntervalMask( 
            /* [in] */ long startTime,
            /* [in] */ long length,
            /* [in] */ ULONG mask) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetSurroundingInvalidIntervalMask( 
            /* [in] */ long startTime,
            /* [in] */ ULONG interestMask,
            /* [out] */ long __RPC_FAR *actualStart,
            /* [out] */ long __RPC_FAR *actualLength,
            /* [out] */ ULONG __RPC_FAR *mask) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetValidMaskAtTime( 
            /* [in] */ long time,
            /* [out] */ ULONG __RPC_FAR *mask) = 0;
        
        virtual DWORD STDMETHODCALLTYPE QueryNumMasks( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetValidMaskAtIndex( 
            /* [in] */ long index,
            /* [out] */ ULONG __RPC_FAR *mask,
            /* [out] */ LONG __RPC_FAR *plTime) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Clone( 
            /* [out] */ IValidSegmentList2 __RPC_FAR *__RPC_FAR *ppSegList) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE ORValidAreas( 
            /* [in] */ IValidSegmentList2 __RPC_FAR *pSegList) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE ANDValidAreas( 
            /* [in] */ IValidSegmentList2 __RPC_FAR *pSegList) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IValidSegmentList2Vtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            IValidSegmentList2 __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            IValidSegmentList2 __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            IValidSegmentList2 __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetInvalidInterval )( 
            IValidSegmentList2 __RPC_FAR * This,
            /* [in] */ long startTime,
            /* [out] */ long __RPC_FAR *actualStart,
            /* [out] */ long __RPC_FAR *actualLength);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *InvalidateInterval )( 
            IValidSegmentList2 __RPC_FAR * This,
            /* [in] */ long startTime,
            /* [in] */ long length);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *ValidateInterval )( 
            IValidSegmentList2 __RPC_FAR * This,
            /* [in] */ long startTime,
            /* [in] */ long length);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetSurroundingInvalidInterval )( 
            IValidSegmentList2 __RPC_FAR * This,
            /* [in] */ long startTime,
            /* [out] */ long __RPC_FAR *actualStart,
            /* [out] */ long __RPC_FAR *actualLength);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetInvalidIntervalMask )( 
            IValidSegmentList2 __RPC_FAR * This,
            /* [in] */ long startTime,
            /* [in] */ ULONG interestMask,
            /* [in] */ ULONG endIntervalMask,
            /* [out] */ long __RPC_FAR *actualStart,
            /* [out] */ long __RPC_FAR *actualLength,
            /* [out] */ ULONG __RPC_FAR *mask);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *InvalidateIntervalMask )( 
            IValidSegmentList2 __RPC_FAR * This,
            /* [in] */ long startTime,
            /* [in] */ long length,
            /* [in] */ ULONG mask);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *ValidateIntervalMask )( 
            IValidSegmentList2 __RPC_FAR * This,
            /* [in] */ long startTime,
            /* [in] */ long length,
            /* [in] */ ULONG mask);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetSurroundingInvalidIntervalMask )( 
            IValidSegmentList2 __RPC_FAR * This,
            /* [in] */ long startTime,
            /* [in] */ ULONG interestMask,
            /* [out] */ long __RPC_FAR *actualStart,
            /* [out] */ long __RPC_FAR *actualLength,
            /* [out] */ ULONG __RPC_FAR *mask);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetValidMaskAtTime )( 
            IValidSegmentList2 __RPC_FAR * This,
            /* [in] */ long time,
            /* [out] */ ULONG __RPC_FAR *mask);
        
        DWORD ( STDMETHODCALLTYPE __RPC_FAR *QueryNumMasks )( 
            IValidSegmentList2 __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetValidMaskAtIndex )( 
            IValidSegmentList2 __RPC_FAR * This,
            /* [in] */ long index,
            /* [out] */ ULONG __RPC_FAR *mask,
            /* [out] */ LONG __RPC_FAR *plTime);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Clone )( 
            IValidSegmentList2 __RPC_FAR * This,
            /* [out] */ IValidSegmentList2 __RPC_FAR *__RPC_FAR *ppSegList);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *ORValidAreas )( 
            IValidSegmentList2 __RPC_FAR * This,
            /* [in] */ IValidSegmentList2 __RPC_FAR *pSegList);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *ANDValidAreas )( 
            IValidSegmentList2 __RPC_FAR * This,
            /* [in] */ IValidSegmentList2 __RPC_FAR *pSegList);
        
        END_INTERFACE
    } IValidSegmentList2Vtbl;

    interface IValidSegmentList2
    {
        CONST_VTBL struct IValidSegmentList2Vtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IValidSegmentList2_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IValidSegmentList2_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IValidSegmentList2_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IValidSegmentList2_GetInvalidInterval(This,startTime,actualStart,actualLength)	\
    (This)->lpVtbl -> GetInvalidInterval(This,startTime,actualStart,actualLength)

#define IValidSegmentList2_InvalidateInterval(This,startTime,length)	\
    (This)->lpVtbl -> InvalidateInterval(This,startTime,length)

#define IValidSegmentList2_ValidateInterval(This,startTime,length)	\
    (This)->lpVtbl -> ValidateInterval(This,startTime,length)

#define IValidSegmentList2_GetSurroundingInvalidInterval(This,startTime,actualStart,actualLength)	\
    (This)->lpVtbl -> GetSurroundingInvalidInterval(This,startTime,actualStart,actualLength)


#define IValidSegmentList2_GetInvalidIntervalMask(This,startTime,interestMask,endIntervalMask,actualStart,actualLength,mask)	\
    (This)->lpVtbl -> GetInvalidIntervalMask(This,startTime,interestMask,endIntervalMask,actualStart,actualLength,mask)

#define IValidSegmentList2_InvalidateIntervalMask(This,startTime,length,mask)	\
    (This)->lpVtbl -> InvalidateIntervalMask(This,startTime,length,mask)

#define IValidSegmentList2_ValidateIntervalMask(This,startTime,length,mask)	\
    (This)->lpVtbl -> ValidateIntervalMask(This,startTime,length,mask)

#define IValidSegmentList2_GetSurroundingInvalidIntervalMask(This,startTime,interestMask,actualStart,actualLength,mask)	\
    (This)->lpVtbl -> GetSurroundingInvalidIntervalMask(This,startTime,interestMask,actualStart,actualLength,mask)

#define IValidSegmentList2_GetValidMaskAtTime(This,time,mask)	\
    (This)->lpVtbl -> GetValidMaskAtTime(This,time,mask)

#define IValidSegmentList2_QueryNumMasks(This)	\
    (This)->lpVtbl -> QueryNumMasks(This)

#define IValidSegmentList2_GetValidMaskAtIndex(This,index,mask,plTime)	\
    (This)->lpVtbl -> GetValidMaskAtIndex(This,index,mask,plTime)

#define IValidSegmentList2_Clone(This,ppSegList)	\
    (This)->lpVtbl -> Clone(This,ppSegList)

#define IValidSegmentList2_ORValidAreas(This,pSegList)	\
    (This)->lpVtbl -> ORValidAreas(This,pSegList)

#define IValidSegmentList2_ANDValidAreas(This,pSegList)	\
    (This)->lpVtbl -> ANDValidAreas(This,pSegList)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE IValidSegmentList2_GetInvalidIntervalMask_Proxy( 
    IValidSegmentList2 __RPC_FAR * This,
    /* [in] */ long startTime,
    /* [in] */ ULONG interestMask,
    /* [in] */ ULONG endIntervalMask,
    /* [out] */ long __RPC_FAR *actualStart,
    /* [out] */ long __RPC_FAR *actualLength,
    /* [out] */ ULONG __RPC_FAR *mask);


void __RPC_STUB IValidSegmentList2_GetInvalidIntervalMask_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IValidSegmentList2_InvalidateIntervalMask_Proxy( 
    IValidSegmentList2 __RPC_FAR * This,
    /* [in] */ long startTime,
    /* [in] */ long length,
    /* [in] */ ULONG mask);


void __RPC_STUB IValidSegmentList2_InvalidateIntervalMask_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IValidSegmentList2_ValidateIntervalMask_Proxy( 
    IValidSegmentList2 __RPC_FAR * This,
    /* [in] */ long startTime,
    /* [in] */ long length,
    /* [in] */ ULONG mask);


void __RPC_STUB IValidSegmentList2_ValidateIntervalMask_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IValidSegmentList2_GetSurroundingInvalidIntervalMask_Proxy( 
    IValidSegmentList2 __RPC_FAR * This,
    /* [in] */ long startTime,
    /* [in] */ ULONG interestMask,
    /* [out] */ long __RPC_FAR *actualStart,
    /* [out] */ long __RPC_FAR *actualLength,
    /* [out] */ ULONG __RPC_FAR *mask);


void __RPC_STUB IValidSegmentList2_GetSurroundingInvalidIntervalMask_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IValidSegmentList2_GetValidMaskAtTime_Proxy( 
    IValidSegmentList2 __RPC_FAR * This,
    /* [in] */ long time,
    /* [out] */ ULONG __RPC_FAR *mask);


void __RPC_STUB IValidSegmentList2_GetValidMaskAtTime_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


DWORD STDMETHODCALLTYPE IValidSegmentList2_QueryNumMasks_Proxy( 
    IValidSegmentList2 __RPC_FAR * This);


void __RPC_STUB IValidSegmentList2_QueryNumMasks_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IValidSegmentList2_GetValidMaskAtIndex_Proxy( 
    IValidSegmentList2 __RPC_FAR * This,
    /* [in] */ long index,
    /* [out] */ ULONG __RPC_FAR *mask,
    /* [out] */ LONG __RPC_FAR *plTime);


void __RPC_STUB IValidSegmentList2_GetValidMaskAtIndex_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IValidSegmentList2_Clone_Proxy( 
    IValidSegmentList2 __RPC_FAR * This,
    /* [out] */ IValidSegmentList2 __RPC_FAR *__RPC_FAR *ppSegList);


void __RPC_STUB IValidSegmentList2_Clone_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IValidSegmentList2_ORValidAreas_Proxy( 
    IValidSegmentList2 __RPC_FAR * This,
    /* [in] */ IValidSegmentList2 __RPC_FAR *pSegList);


void __RPC_STUB IValidSegmentList2_ORValidAreas_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IValidSegmentList2_ANDValidAreas_Proxy( 
    IValidSegmentList2 __RPC_FAR * This,
    /* [in] */ IValidSegmentList2 __RPC_FAR *pSegList);


void __RPC_STUB IValidSegmentList2_ANDValidAreas_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IValidSegmentList2_INTERFACE_DEFINED__ */


/* Additional Prototypes for ALL interfaces */

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif
