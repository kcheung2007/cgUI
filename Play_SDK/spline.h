/* this ALWAYS GENERATED file contains the definitions for the interfaces */


/* File created by MIDL compiler version 3.01.75 */
/* at Tue Nov 23 05:02:17 1999
 */
/* Compiler settings for spline.idl:
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

#ifndef __spline_h__
#define __spline_h__

#ifdef __cplusplus
extern "C"{
#endif 

/* Forward Declarations */ 

#ifndef __IPlaySpline_FWD_DEFINED__
#define __IPlaySpline_FWD_DEFINED__
typedef interface IPlaySpline IPlaySpline;
#endif 	/* __IPlaySpline_FWD_DEFINED__ */


/* header files for imported files */
#include "objidl.h"

void __RPC_FAR * __RPC_USER MIDL_user_allocate(size_t);
void __RPC_USER MIDL_user_free( void __RPC_FAR * ); 

#ifndef __IPlaySpline_INTERFACE_DEFINED__
#define __IPlaySpline_INTERFACE_DEFINED__

/****************************************
 * Generated header for interface: IPlaySpline
 * at Tue Nov 23 05:02:17 1999
 * using MIDL 3.01.75
 ****************************************/
/* [uuid][object][local] */ 


typedef 
enum tagESplineAttribute
    {	SASplineType	= 0,
	SASplineTension	= 1,
	SASplineInterpolation	= 2
    }	ESplineAttribute;

typedef 
enum tagESplineType
    {	PSMNaturalCubic	= 0,
	PSMBlending	= 1
    }	ESplineType;

typedef 
enum tagESplineInterpolator
    {	SILinear	= 0,
	SICubic	= 2,
	SIBezier	= 3,
	SIHold	= 4
    }	ESplineInterpolator;

typedef struct  tagSSplinePoint
    {
    double dValue;
    double dTime;
    double dTension;
    long lFlags;
    double c[ 6 ];
    }	SSplinePoint;


EXTERN_C const IID IID_IPlaySpline;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    interface DECLSPEC_UUID("8335e621-ab3b-11ce-8468-0000b468276b")
    IPlaySpline : public IUnknown
    {
    public:
        virtual long STDMETHODCALLTYPE QueryNumPoints( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE QueryKeyValueByIndex( 
            long index,
            long reserved,
            double __RPC_FAR *pdTime,
            double __RPC_FAR *dpValue) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetAttr( 
            long lAttribute,
            long indexOfKey,
            double value) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetAttr( 
            long lAttribute,
            long indexOfKey,
            double __RPC_FAR *pValue) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE AddKey( 
            double dTime,
            double dValue,
            long __RPC_FAR *index) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE MoveKey( 
            double dOldTime,
            double dNewTime,
            long __RPC_FAR *index) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE FindKeyIndex( 
            double dTime,
            long __RPC_FAR *pIndex,
            double __RPC_FAR *pdTrueTime) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE RemoveKeyByIndex( 
            long index) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE RemoveKeyAtTime( 
            double dTime) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetValue( 
            long reserved,
            double dTime,
            double __RPC_FAR *pdValue) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Clone( 
            IPlaySpline __RPC_FAR *__RPC_FAR *ppSpline) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetSplinePoints( 
            SSplinePoint __RPC_FAR *pSpline,
            DWORD dwTime) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IPlaySplineVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            IPlaySpline __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            IPlaySpline __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            IPlaySpline __RPC_FAR * This);
        
        long ( STDMETHODCALLTYPE __RPC_FAR *QueryNumPoints )( 
            IPlaySpline __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryKeyValueByIndex )( 
            IPlaySpline __RPC_FAR * This,
            long index,
            long reserved,
            double __RPC_FAR *pdTime,
            double __RPC_FAR *dpValue);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetAttr )( 
            IPlaySpline __RPC_FAR * This,
            long lAttribute,
            long indexOfKey,
            double value);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetAttr )( 
            IPlaySpline __RPC_FAR * This,
            long lAttribute,
            long indexOfKey,
            double __RPC_FAR *pValue);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *AddKey )( 
            IPlaySpline __RPC_FAR * This,
            double dTime,
            double dValue,
            long __RPC_FAR *index);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *MoveKey )( 
            IPlaySpline __RPC_FAR * This,
            double dOldTime,
            double dNewTime,
            long __RPC_FAR *index);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *FindKeyIndex )( 
            IPlaySpline __RPC_FAR * This,
            double dTime,
            long __RPC_FAR *pIndex,
            double __RPC_FAR *pdTrueTime);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *RemoveKeyByIndex )( 
            IPlaySpline __RPC_FAR * This,
            long index);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *RemoveKeyAtTime )( 
            IPlaySpline __RPC_FAR * This,
            double dTime);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetValue )( 
            IPlaySpline __RPC_FAR * This,
            long reserved,
            double dTime,
            double __RPC_FAR *pdValue);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Clone )( 
            IPlaySpline __RPC_FAR * This,
            IPlaySpline __RPC_FAR *__RPC_FAR *ppSpline);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetSplinePoints )( 
            IPlaySpline __RPC_FAR * This,
            SSplinePoint __RPC_FAR *pSpline,
            DWORD dwTime);
        
        END_INTERFACE
    } IPlaySplineVtbl;

    interface IPlaySpline
    {
        CONST_VTBL struct IPlaySplineVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IPlaySpline_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IPlaySpline_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IPlaySpline_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IPlaySpline_QueryNumPoints(This)	\
    (This)->lpVtbl -> QueryNumPoints(This)

#define IPlaySpline_QueryKeyValueByIndex(This,index,reserved,pdTime,dpValue)	\
    (This)->lpVtbl -> QueryKeyValueByIndex(This,index,reserved,pdTime,dpValue)

#define IPlaySpline_SetAttr(This,lAttribute,indexOfKey,value)	\
    (This)->lpVtbl -> SetAttr(This,lAttribute,indexOfKey,value)

#define IPlaySpline_GetAttr(This,lAttribute,indexOfKey,pValue)	\
    (This)->lpVtbl -> GetAttr(This,lAttribute,indexOfKey,pValue)

#define IPlaySpline_AddKey(This,dTime,dValue,index)	\
    (This)->lpVtbl -> AddKey(This,dTime,dValue,index)

#define IPlaySpline_MoveKey(This,dOldTime,dNewTime,index)	\
    (This)->lpVtbl -> MoveKey(This,dOldTime,dNewTime,index)

#define IPlaySpline_FindKeyIndex(This,dTime,pIndex,pdTrueTime)	\
    (This)->lpVtbl -> FindKeyIndex(This,dTime,pIndex,pdTrueTime)

#define IPlaySpline_RemoveKeyByIndex(This,index)	\
    (This)->lpVtbl -> RemoveKeyByIndex(This,index)

#define IPlaySpline_RemoveKeyAtTime(This,dTime)	\
    (This)->lpVtbl -> RemoveKeyAtTime(This,dTime)

#define IPlaySpline_GetValue(This,reserved,dTime,pdValue)	\
    (This)->lpVtbl -> GetValue(This,reserved,dTime,pdValue)

#define IPlaySpline_Clone(This,ppSpline)	\
    (This)->lpVtbl -> Clone(This,ppSpline)

#define IPlaySpline_GetSplinePoints(This,pSpline,dwTime)	\
    (This)->lpVtbl -> GetSplinePoints(This,pSpline,dwTime)

#endif /* COBJMACROS */


#endif 	/* C style interface */



long STDMETHODCALLTYPE IPlaySpline_QueryNumPoints_Proxy( 
    IPlaySpline __RPC_FAR * This);


void __RPC_STUB IPlaySpline_QueryNumPoints_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IPlaySpline_QueryKeyValueByIndex_Proxy( 
    IPlaySpline __RPC_FAR * This,
    long index,
    long reserved,
    double __RPC_FAR *pdTime,
    double __RPC_FAR *dpValue);


void __RPC_STUB IPlaySpline_QueryKeyValueByIndex_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IPlaySpline_SetAttr_Proxy( 
    IPlaySpline __RPC_FAR * This,
    long lAttribute,
    long indexOfKey,
    double value);


void __RPC_STUB IPlaySpline_SetAttr_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IPlaySpline_GetAttr_Proxy( 
    IPlaySpline __RPC_FAR * This,
    long lAttribute,
    long indexOfKey,
    double __RPC_FAR *pValue);


void __RPC_STUB IPlaySpline_GetAttr_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IPlaySpline_AddKey_Proxy( 
    IPlaySpline __RPC_FAR * This,
    double dTime,
    double dValue,
    long __RPC_FAR *index);


void __RPC_STUB IPlaySpline_AddKey_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IPlaySpline_MoveKey_Proxy( 
    IPlaySpline __RPC_FAR * This,
    double dOldTime,
    double dNewTime,
    long __RPC_FAR *index);


void __RPC_STUB IPlaySpline_MoveKey_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IPlaySpline_FindKeyIndex_Proxy( 
    IPlaySpline __RPC_FAR * This,
    double dTime,
    long __RPC_FAR *pIndex,
    double __RPC_FAR *pdTrueTime);


void __RPC_STUB IPlaySpline_FindKeyIndex_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IPlaySpline_RemoveKeyByIndex_Proxy( 
    IPlaySpline __RPC_FAR * This,
    long index);


void __RPC_STUB IPlaySpline_RemoveKeyByIndex_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IPlaySpline_RemoveKeyAtTime_Proxy( 
    IPlaySpline __RPC_FAR * This,
    double dTime);


void __RPC_STUB IPlaySpline_RemoveKeyAtTime_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IPlaySpline_GetValue_Proxy( 
    IPlaySpline __RPC_FAR * This,
    long reserved,
    double dTime,
    double __RPC_FAR *pdValue);


void __RPC_STUB IPlaySpline_GetValue_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IPlaySpline_Clone_Proxy( 
    IPlaySpline __RPC_FAR * This,
    IPlaySpline __RPC_FAR *__RPC_FAR *ppSpline);


void __RPC_STUB IPlaySpline_Clone_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IPlaySpline_GetSplinePoints_Proxy( 
    IPlaySpline __RPC_FAR * This,
    SSplinePoint __RPC_FAR *pSpline,
    DWORD dwTime);


void __RPC_STUB IPlaySpline_GetSplinePoints_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IPlaySpline_INTERFACE_DEFINED__ */


/* Additional Prototypes for ALL interfaces */

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif
