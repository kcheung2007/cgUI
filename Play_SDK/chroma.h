/* this ALWAYS GENERATED file contains the definitions for the interfaces */


/* File created by MIDL compiler version 3.01.75 */
/* at Tue Nov 23 05:28:27 1999
 */
/* Compiler settings for chroma.idl:
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

#ifndef __chroma_h__
#define __chroma_h__

#ifdef __cplusplus
extern "C"{
#endif 

/* Forward Declarations */ 

#ifndef __IChromaKeyFactory_FWD_DEFINED__
#define __IChromaKeyFactory_FWD_DEFINED__
typedef interface IChromaKeyFactory IChromaKeyFactory;
#endif 	/* __IChromaKeyFactory_FWD_DEFINED__ */


/* header files for imported files */
#include "unknwn.h"
#include "gxlate.h"
#include "trnity.h"

void __RPC_FAR * __RPC_USER MIDL_user_allocate(size_t);
void __RPC_USER MIDL_user_free( void __RPC_FAR * ); 

#ifndef __IChromaKeyFactory_INTERFACE_DEFINED__
#define __IChromaKeyFactory_INTERFACE_DEFINED__

/****************************************
 * Generated header for interface: IChromaKeyFactory
 * at Tue Nov 23 05:28:27 1999
 * using MIDL 3.01.75
 ****************************************/
/* [uuid][object][local] */ 



EXTERN_C const IID IID_IChromaKeyFactory;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    interface DECLSPEC_UUID("8335e42a-ab3b-11ce-8468-0000b468276b")
    IChromaKeyFactory : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE SetKeyFrame( 
            SPlayBitMap __RPC_FAR *pBM) = 0;
        
        virtual DWORD STDMETHODCALLTYPE GetNumMethods( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetMethodName( 
            DWORD dwMethod,
            LPSTR pszDesc,
            DWORD dwBytes) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE CanMethodMakeKey( 
            ULONG uKeyMode,
            ULONG uMixType) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetMethod( 
            DWORD dwMethod) = 0;
        
        virtual DWORD STDMETHODCALLTYPE GetMethod( void) = 0;
        
        virtual DWORD STDMETHODCALLTYPE GetNumParams( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetParamName( 
            DWORD dwParam,
            LPSTR pszDesc,
            DWORD dwBytes) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetParamRange( 
            DWORD dwParam,
            long __RPC_FAR *pdwLow,
            long __RPC_FAR *pdwHigh) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetParameter( 
            DWORD dwParam,
            long dwVal) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetParameter( 
            DWORD dwParam,
            long __RPC_FAR *pdwVal) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetKeyTable( 
            /* [in] */ DWORD dwDesiredTable,
            /* [out] */ BYTE __RPC_FAR *__RPC_FAR *ppTable,
            /* [out] */ DWORD __RPC_FAR *pdwSize) = 0;
        
        virtual DWORD STDMETHODCALLTYPE GetMatteColor( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SaveSettings( 
            IStorage __RPC_FAR *pStg) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE RestoreSettings( 
            IStorage __RPC_FAR *pStg) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetInputPrecorrection( 
            ITrnInputModule __RPC_FAR *pInput) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE InvertTable( 
            BOOL bInvert) = 0;
        
        virtual BOOL STDMETHODCALLTYPE IsInverted( void) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IChromaKeyFactoryVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            IChromaKeyFactory __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            IChromaKeyFactory __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            IChromaKeyFactory __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetKeyFrame )( 
            IChromaKeyFactory __RPC_FAR * This,
            SPlayBitMap __RPC_FAR *pBM);
        
        DWORD ( STDMETHODCALLTYPE __RPC_FAR *GetNumMethods )( 
            IChromaKeyFactory __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetMethodName )( 
            IChromaKeyFactory __RPC_FAR * This,
            DWORD dwMethod,
            LPSTR pszDesc,
            DWORD dwBytes);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *CanMethodMakeKey )( 
            IChromaKeyFactory __RPC_FAR * This,
            ULONG uKeyMode,
            ULONG uMixType);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetMethod )( 
            IChromaKeyFactory __RPC_FAR * This,
            DWORD dwMethod);
        
        DWORD ( STDMETHODCALLTYPE __RPC_FAR *GetMethod )( 
            IChromaKeyFactory __RPC_FAR * This);
        
        DWORD ( STDMETHODCALLTYPE __RPC_FAR *GetNumParams )( 
            IChromaKeyFactory __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetParamName )( 
            IChromaKeyFactory __RPC_FAR * This,
            DWORD dwParam,
            LPSTR pszDesc,
            DWORD dwBytes);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetParamRange )( 
            IChromaKeyFactory __RPC_FAR * This,
            DWORD dwParam,
            long __RPC_FAR *pdwLow,
            long __RPC_FAR *pdwHigh);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetParameter )( 
            IChromaKeyFactory __RPC_FAR * This,
            DWORD dwParam,
            long dwVal);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetParameter )( 
            IChromaKeyFactory __RPC_FAR * This,
            DWORD dwParam,
            long __RPC_FAR *pdwVal);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetKeyTable )( 
            IChromaKeyFactory __RPC_FAR * This,
            /* [in] */ DWORD dwDesiredTable,
            /* [out] */ BYTE __RPC_FAR *__RPC_FAR *ppTable,
            /* [out] */ DWORD __RPC_FAR *pdwSize);
        
        DWORD ( STDMETHODCALLTYPE __RPC_FAR *GetMatteColor )( 
            IChromaKeyFactory __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SaveSettings )( 
            IChromaKeyFactory __RPC_FAR * This,
            IStorage __RPC_FAR *pStg);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *RestoreSettings )( 
            IChromaKeyFactory __RPC_FAR * This,
            IStorage __RPC_FAR *pStg);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetInputPrecorrection )( 
            IChromaKeyFactory __RPC_FAR * This,
            ITrnInputModule __RPC_FAR *pInput);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *InvertTable )( 
            IChromaKeyFactory __RPC_FAR * This,
            BOOL bInvert);
        
        BOOL ( STDMETHODCALLTYPE __RPC_FAR *IsInverted )( 
            IChromaKeyFactory __RPC_FAR * This);
        
        END_INTERFACE
    } IChromaKeyFactoryVtbl;

    interface IChromaKeyFactory
    {
        CONST_VTBL struct IChromaKeyFactoryVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IChromaKeyFactory_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IChromaKeyFactory_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IChromaKeyFactory_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IChromaKeyFactory_SetKeyFrame(This,pBM)	\
    (This)->lpVtbl -> SetKeyFrame(This,pBM)

#define IChromaKeyFactory_GetNumMethods(This)	\
    (This)->lpVtbl -> GetNumMethods(This)

#define IChromaKeyFactory_GetMethodName(This,dwMethod,pszDesc,dwBytes)	\
    (This)->lpVtbl -> GetMethodName(This,dwMethod,pszDesc,dwBytes)

#define IChromaKeyFactory_CanMethodMakeKey(This,uKeyMode,uMixType)	\
    (This)->lpVtbl -> CanMethodMakeKey(This,uKeyMode,uMixType)

#define IChromaKeyFactory_SetMethod(This,dwMethod)	\
    (This)->lpVtbl -> SetMethod(This,dwMethod)

#define IChromaKeyFactory_GetMethod(This)	\
    (This)->lpVtbl -> GetMethod(This)

#define IChromaKeyFactory_GetNumParams(This)	\
    (This)->lpVtbl -> GetNumParams(This)

#define IChromaKeyFactory_GetParamName(This,dwParam,pszDesc,dwBytes)	\
    (This)->lpVtbl -> GetParamName(This,dwParam,pszDesc,dwBytes)

#define IChromaKeyFactory_GetParamRange(This,dwParam,pdwLow,pdwHigh)	\
    (This)->lpVtbl -> GetParamRange(This,dwParam,pdwLow,pdwHigh)

#define IChromaKeyFactory_SetParameter(This,dwParam,dwVal)	\
    (This)->lpVtbl -> SetParameter(This,dwParam,dwVal)

#define IChromaKeyFactory_GetParameter(This,dwParam,pdwVal)	\
    (This)->lpVtbl -> GetParameter(This,dwParam,pdwVal)

#define IChromaKeyFactory_GetKeyTable(This,dwDesiredTable,ppTable,pdwSize)	\
    (This)->lpVtbl -> GetKeyTable(This,dwDesiredTable,ppTable,pdwSize)

#define IChromaKeyFactory_GetMatteColor(This)	\
    (This)->lpVtbl -> GetMatteColor(This)

#define IChromaKeyFactory_SaveSettings(This,pStg)	\
    (This)->lpVtbl -> SaveSettings(This,pStg)

#define IChromaKeyFactory_RestoreSettings(This,pStg)	\
    (This)->lpVtbl -> RestoreSettings(This,pStg)

#define IChromaKeyFactory_SetInputPrecorrection(This,pInput)	\
    (This)->lpVtbl -> SetInputPrecorrection(This,pInput)

#define IChromaKeyFactory_InvertTable(This,bInvert)	\
    (This)->lpVtbl -> InvertTable(This,bInvert)

#define IChromaKeyFactory_IsInverted(This)	\
    (This)->lpVtbl -> IsInverted(This)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE IChromaKeyFactory_SetKeyFrame_Proxy( 
    IChromaKeyFactory __RPC_FAR * This,
    SPlayBitMap __RPC_FAR *pBM);


void __RPC_STUB IChromaKeyFactory_SetKeyFrame_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


DWORD STDMETHODCALLTYPE IChromaKeyFactory_GetNumMethods_Proxy( 
    IChromaKeyFactory __RPC_FAR * This);


void __RPC_STUB IChromaKeyFactory_GetNumMethods_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IChromaKeyFactory_GetMethodName_Proxy( 
    IChromaKeyFactory __RPC_FAR * This,
    DWORD dwMethod,
    LPSTR pszDesc,
    DWORD dwBytes);


void __RPC_STUB IChromaKeyFactory_GetMethodName_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IChromaKeyFactory_CanMethodMakeKey_Proxy( 
    IChromaKeyFactory __RPC_FAR * This,
    ULONG uKeyMode,
    ULONG uMixType);


void __RPC_STUB IChromaKeyFactory_CanMethodMakeKey_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IChromaKeyFactory_SetMethod_Proxy( 
    IChromaKeyFactory __RPC_FAR * This,
    DWORD dwMethod);


void __RPC_STUB IChromaKeyFactory_SetMethod_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


DWORD STDMETHODCALLTYPE IChromaKeyFactory_GetMethod_Proxy( 
    IChromaKeyFactory __RPC_FAR * This);


void __RPC_STUB IChromaKeyFactory_GetMethod_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


DWORD STDMETHODCALLTYPE IChromaKeyFactory_GetNumParams_Proxy( 
    IChromaKeyFactory __RPC_FAR * This);


void __RPC_STUB IChromaKeyFactory_GetNumParams_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IChromaKeyFactory_GetParamName_Proxy( 
    IChromaKeyFactory __RPC_FAR * This,
    DWORD dwParam,
    LPSTR pszDesc,
    DWORD dwBytes);


void __RPC_STUB IChromaKeyFactory_GetParamName_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IChromaKeyFactory_GetParamRange_Proxy( 
    IChromaKeyFactory __RPC_FAR * This,
    DWORD dwParam,
    long __RPC_FAR *pdwLow,
    long __RPC_FAR *pdwHigh);


void __RPC_STUB IChromaKeyFactory_GetParamRange_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IChromaKeyFactory_SetParameter_Proxy( 
    IChromaKeyFactory __RPC_FAR * This,
    DWORD dwParam,
    long dwVal);


void __RPC_STUB IChromaKeyFactory_SetParameter_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IChromaKeyFactory_GetParameter_Proxy( 
    IChromaKeyFactory __RPC_FAR * This,
    DWORD dwParam,
    long __RPC_FAR *pdwVal);


void __RPC_STUB IChromaKeyFactory_GetParameter_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IChromaKeyFactory_GetKeyTable_Proxy( 
    IChromaKeyFactory __RPC_FAR * This,
    /* [in] */ DWORD dwDesiredTable,
    /* [out] */ BYTE __RPC_FAR *__RPC_FAR *ppTable,
    /* [out] */ DWORD __RPC_FAR *pdwSize);


void __RPC_STUB IChromaKeyFactory_GetKeyTable_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


DWORD STDMETHODCALLTYPE IChromaKeyFactory_GetMatteColor_Proxy( 
    IChromaKeyFactory __RPC_FAR * This);


void __RPC_STUB IChromaKeyFactory_GetMatteColor_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IChromaKeyFactory_SaveSettings_Proxy( 
    IChromaKeyFactory __RPC_FAR * This,
    IStorage __RPC_FAR *pStg);


void __RPC_STUB IChromaKeyFactory_SaveSettings_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IChromaKeyFactory_RestoreSettings_Proxy( 
    IChromaKeyFactory __RPC_FAR * This,
    IStorage __RPC_FAR *pStg);


void __RPC_STUB IChromaKeyFactory_RestoreSettings_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IChromaKeyFactory_SetInputPrecorrection_Proxy( 
    IChromaKeyFactory __RPC_FAR * This,
    ITrnInputModule __RPC_FAR *pInput);


void __RPC_STUB IChromaKeyFactory_SetInputPrecorrection_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IChromaKeyFactory_InvertTable_Proxy( 
    IChromaKeyFactory __RPC_FAR * This,
    BOOL bInvert);


void __RPC_STUB IChromaKeyFactory_InvertTable_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


BOOL STDMETHODCALLTYPE IChromaKeyFactory_IsInverted_Proxy( 
    IChromaKeyFactory __RPC_FAR * This);


void __RPC_STUB IChromaKeyFactory_IsInverted_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IChromaKeyFactory_INTERFACE_DEFINED__ */


/* Additional Prototypes for ALL interfaces */

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif
