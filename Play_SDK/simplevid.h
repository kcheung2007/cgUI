/* this ALWAYS GENERATED file contains the definitions for the interfaces */


/* File created by MIDL compiler version 3.01.75 */
/* at Tue Nov 23 05:28:34 1999
 */
/* Compiler settings for simplevid.idl:
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

#ifndef __simplevid_h__
#define __simplevid_h__

#ifdef __cplusplus
extern "C"{
#endif 

/* Forward Declarations */ 

#ifndef __IVidAsyncAdvise_FWD_DEFINED__
#define __IVidAsyncAdvise_FWD_DEFINED__
typedef interface IVidAsyncAdvise IVidAsyncAdvise;
#endif 	/* __IVidAsyncAdvise_FWD_DEFINED__ */


#ifndef __IVidSource_FWD_DEFINED__
#define __IVidSource_FWD_DEFINED__
typedef interface IVidSource IVidSource;
#endif 	/* __IVidSource_FWD_DEFINED__ */


#ifndef __IVidLiveSource_FWD_DEFINED__
#define __IVidLiveSource_FWD_DEFINED__
typedef interface IVidLiveSource IVidLiveSource;
#endif 	/* __IVidLiveSource_FWD_DEFINED__ */


#ifndef __IVidLiveSource2_FWD_DEFINED__
#define __IVidLiveSource2_FWD_DEFINED__
typedef interface IVidLiveSource2 IVidLiveSource2;
#endif 	/* __IVidLiveSource2_FWD_DEFINED__ */


#ifndef __IVidMatteSource_FWD_DEFINED__
#define __IVidMatteSource_FWD_DEFINED__
typedef interface IVidMatteSource IVidMatteSource;
#endif 	/* __IVidMatteSource_FWD_DEFINED__ */


#ifndef __IVidFramestoreSource_FWD_DEFINED__
#define __IVidFramestoreSource_FWD_DEFINED__
typedef interface IVidFramestoreSource IVidFramestoreSource;
#endif 	/* __IVidFramestoreSource_FWD_DEFINED__ */


#ifndef __IVidEffect_FWD_DEFINED__
#define __IVidEffect_FWD_DEFINED__
typedef interface IVidEffect IVidEffect;
#endif 	/* __IVidEffect_FWD_DEFINED__ */


#ifndef __IVidEffect2_FWD_DEFINED__
#define __IVidEffect2_FWD_DEFINED__
typedef interface IVidEffect2 IVidEffect2;
#endif 	/* __IVidEffect2_FWD_DEFINED__ */


#ifndef __IVidAdviseSink2_FWD_DEFINED__
#define __IVidAdviseSink2_FWD_DEFINED__
typedef interface IVidAdviseSink2 IVidAdviseSink2;
#endif 	/* __IVidAdviseSink2_FWD_DEFINED__ */


#ifndef __IVidAdviseSink3_FWD_DEFINED__
#define __IVidAdviseSink3_FWD_DEFINED__
typedef interface IVidAdviseSink3 IVidAdviseSink3;
#endif 	/* __IVidAdviseSink3_FWD_DEFINED__ */


#ifndef __IVidAdviseSink4_FWD_DEFINED__
#define __IVidAdviseSink4_FWD_DEFINED__
typedef interface IVidAdviseSink4 IVidAdviseSink4;
#endif 	/* __IVidAdviseSink4_FWD_DEFINED__ */


#ifndef __IVidSimpleVideo_FWD_DEFINED__
#define __IVidSimpleVideo_FWD_DEFINED__
typedef interface IVidSimpleVideo IVidSimpleVideo;
#endif 	/* __IVidSimpleVideo_FWD_DEFINED__ */


#ifndef __IVidSimpleVideo2_FWD_DEFINED__
#define __IVidSimpleVideo2_FWD_DEFINED__
typedef interface IVidSimpleVideo2 IVidSimpleVideo2;
#endif 	/* __IVidSimpleVideo2_FWD_DEFINED__ */


#ifndef __IVidSimpleVideoAddOn_FWD_DEFINED__
#define __IVidSimpleVideoAddOn_FWD_DEFINED__
typedef interface IVidSimpleVideoAddOn IVidSimpleVideoAddOn;
#endif 	/* __IVidSimpleVideoAddOn_FWD_DEFINED__ */


#ifndef __ITrnPiconFactory_FWD_DEFINED__
#define __ITrnPiconFactory_FWD_DEFINED__
typedef interface ITrnPiconFactory ITrnPiconFactory;
#endif 	/* __ITrnPiconFactory_FWD_DEFINED__ */


/* header files for imported files */
#include "wtypes.h"
#include "unknwn.h"
#include "objidl.h"
#include "trnity.h"
#include "tfxfile.h"

void __RPC_FAR * __RPC_USER MIDL_user_allocate(size_t);
void __RPC_USER MIDL_user_free( void __RPC_FAR * ); 

/****************************************
 * Generated header for interface: __MIDL_itf_simplevid_0000
 * at Tue Nov 23 05:28:34 1999
 * using MIDL 3.01.75
 ****************************************/
/* [local] */ 









typedef 
enum tagEVidSource
    {	VSPgmOut	= 0,
	VSChan1	= VSPgmOut + 1,
	VSChan2	= VSChan1 + 1,
	VSChan3	= VSChan2 + 1,
	VSChan4	= VSChan3 + 1,
	VSChan5	= VSChan4 + 1,
	VSChan6	= VSChan5 + 1,
	VSChan7	= VSChan6 + 1,
	VSChan8	= VSChan7 + 1,
	VSBlack	= 100,
	VSMatte1	= VSBlack + 1,
	VSMatte2	= VSMatte1 + 1,
	VSFrame1	= 200,
	VSFrame2	= VSFrame1 + 1,
	VSClip1	= 300,
	VSClip2	= VSClip1 + 1,
	VSBusSource1	= 400
    }	EVidSource;

#define VSBusSource(b) EVidSource(VSBusSource1+(b))
typedef 
enum tagEVidBus
    {	VBGraphics	= -2,
	VBSystemOut	= -1,
	VBProgram	= 0,
	VBPreset	= VBProgram + 1,
	VBKey	= VBPreset + 1,
	VBKeyPreset	= VBKey + 1,
	VBDSK	= VBKeyPreset + 1,
	VBDSKPreset	= VBDSK + 1,
	VBAux1	= VBDSKPreset + 1,
	VBAux2	= VBAux1 + 1,
	VBAux3	= VBAux2 + 1,
	VBAux4	= VBAux3 + 1,
	VBAux5	= VBAux4 + 1,
	VBAux6	= VBAux5 + 1,
	VBAux7	= VBAux6 + 1,
	VBAlpha1	= VBAux7 + 1,
	VBAlpha1Preset	= VBAlpha1 + 1,
	VBAlpha2	= VBAlpha1Preset + 1,
	VBAlpha2Preset	= VBAlpha2 + 1,
	VBNoBus	= 0xff
    }	EVidBus;

typedef 
enum tagEVidMixerMode
    {	MMNormal	= 0,
	MMChromaKey	= MMNormal + 1,
	MMAntiColor	= MMChromaKey + 1,
	MMAntiColorAdd	= MMAntiColor + 1,
	MMLumaKey	= MMAntiColorAdd + 1,
	MMExternalKey	= MMLumaKey + 1
    }	EVidMixerMode;



extern RPC_IF_HANDLE __MIDL_itf_simplevid_0000_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_simplevid_0000_v0_0_s_ifspec;

#ifndef __IVidAsyncAdvise_INTERFACE_DEFINED__
#define __IVidAsyncAdvise_INTERFACE_DEFINED__

/****************************************
 * Generated header for interface: IVidAsyncAdvise
 * at Tue Nov 23 05:28:34 1999
 * using MIDL 3.01.75
 ****************************************/
/* [unique][uuid][object][local] */ 


typedef 
enum tagEVidOperation
    {	VOLoaded	= 0,
	VOSaved	= VOLoaded + 1,
	VOGrabbed	= VOSaved + 1
    }	EVidOperation;


EXTERN_C const IID IID_IVidAsyncAdvise;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    interface DECLSPEC_UUID("8335e5ec-ab3b-11ce-8468-0000b468276b")
    IVidAsyncAdvise : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE OnOperationComplete( 
            /* [in] */ EVidSource whichSource,
            /* [in] */ DWORD objectId,
            /* [in] */ EVidOperation whatOp,
            /* [in] */ HRESULT result) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IVidAsyncAdviseVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            IVidAsyncAdvise __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            IVidAsyncAdvise __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            IVidAsyncAdvise __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *OnOperationComplete )( 
            IVidAsyncAdvise __RPC_FAR * This,
            /* [in] */ EVidSource whichSource,
            /* [in] */ DWORD objectId,
            /* [in] */ EVidOperation whatOp,
            /* [in] */ HRESULT result);
        
        END_INTERFACE
    } IVidAsyncAdviseVtbl;

    interface IVidAsyncAdvise
    {
        CONST_VTBL struct IVidAsyncAdviseVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IVidAsyncAdvise_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IVidAsyncAdvise_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IVidAsyncAdvise_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IVidAsyncAdvise_OnOperationComplete(This,whichSource,objectId,whatOp,result)	\
    (This)->lpVtbl -> OnOperationComplete(This,whichSource,objectId,whatOp,result)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE IVidAsyncAdvise_OnOperationComplete_Proxy( 
    IVidAsyncAdvise __RPC_FAR * This,
    /* [in] */ EVidSource whichSource,
    /* [in] */ DWORD objectId,
    /* [in] */ EVidOperation whatOp,
    /* [in] */ HRESULT result);


void __RPC_STUB IVidAsyncAdvise_OnOperationComplete_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IVidAsyncAdvise_INTERFACE_DEFINED__ */


#ifndef __IVidSource_INTERFACE_DEFINED__
#define __IVidSource_INTERFACE_DEFINED__

/****************************************
 * Generated header for interface: IVidSource
 * at Tue Nov 23 05:28:34 1999
 * using MIDL 3.01.75
 ****************************************/
/* [unique][uuid][object][local] */ 



EXTERN_C const IID IID_IVidSource;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    interface DECLSPEC_UUID("8335e5ef-ab3b-11ce-8468-0000b468276b")
    IVidSource : public IUnknown
    {
    public:
        virtual EVidSource STDMETHODCALLTYPE QuerySourceId( void) = 0;
        
        virtual EVidSource STDMETHODCALLTYPE QuerySourceType( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE QueryInternalInterface( 
            /* [in] */ REFIID riid,
            /* [out] */ void __RPC_FAR *__RPC_FAR *ppvObj) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IVidSourceVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            IVidSource __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            IVidSource __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            IVidSource __RPC_FAR * This);
        
        EVidSource ( STDMETHODCALLTYPE __RPC_FAR *QuerySourceId )( 
            IVidSource __RPC_FAR * This);
        
        EVidSource ( STDMETHODCALLTYPE __RPC_FAR *QuerySourceType )( 
            IVidSource __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInternalInterface )( 
            IVidSource __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [out] */ void __RPC_FAR *__RPC_FAR *ppvObj);
        
        END_INTERFACE
    } IVidSourceVtbl;

    interface IVidSource
    {
        CONST_VTBL struct IVidSourceVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IVidSource_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IVidSource_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IVidSource_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IVidSource_QuerySourceId(This)	\
    (This)->lpVtbl -> QuerySourceId(This)

#define IVidSource_QuerySourceType(This)	\
    (This)->lpVtbl -> QuerySourceType(This)

#define IVidSource_QueryInternalInterface(This,riid,ppvObj)	\
    (This)->lpVtbl -> QueryInternalInterface(This,riid,ppvObj)

#endif /* COBJMACROS */


#endif 	/* C style interface */



EVidSource STDMETHODCALLTYPE IVidSource_QuerySourceId_Proxy( 
    IVidSource __RPC_FAR * This);


void __RPC_STUB IVidSource_QuerySourceId_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


EVidSource STDMETHODCALLTYPE IVidSource_QuerySourceType_Proxy( 
    IVidSource __RPC_FAR * This);


void __RPC_STUB IVidSource_QuerySourceType_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVidSource_QueryInternalInterface_Proxy( 
    IVidSource __RPC_FAR * This,
    /* [in] */ REFIID riid,
    /* [out] */ void __RPC_FAR *__RPC_FAR *ppvObj);


void __RPC_STUB IVidSource_QueryInternalInterface_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IVidSource_INTERFACE_DEFINED__ */


#ifndef __IVidLiveSource_INTERFACE_DEFINED__
#define __IVidLiveSource_INTERFACE_DEFINED__

/****************************************
 * Generated header for interface: IVidLiveSource
 * at Tue Nov 23 05:28:34 1999
 * using MIDL 3.01.75
 ****************************************/
/* [unique][uuid][object][local] */ 



EXTERN_C const IID IID_IVidLiveSource;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    interface DECLSPEC_UUID("8335e5e7-ab3b-11ce-8468-0000b468276b")
    IVidLiveSource : public IVidSource
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE SetStrobe( 
            /* [in] */ STrnTimeType __RPC_FAR *pTime,
            /* [in] */ DWORD strobeRate,
            /* [in] */ DWORD strobePhase) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SaveFrameStream( 
            /* [in] */ STrnTimeType __RPC_FAR *pTime,
            /* [in] */ IStream __RPC_FAR *pStream,
            /* [out] */ DWORD __RPC_FAR *pObjectId,
            /* [in] */ IVidAsyncAdvise __RPC_FAR *pAdvise) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SaveFrameMemory( 
            /* [in] */ STrnTimeType __RPC_FAR *pTime,
            /* [in] */ SPlayBitMap __RPC_FAR *pFrameStore,
            /* [out] */ DWORD __RPC_FAR *pObjectId,
            /* [in] */ IVidAsyncAdvise __RPC_FAR *pAdvise) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE LoadEffect( 
            /* [in] */ ITrnEffectFile __RPC_FAR *pTfxFile,
            /* [in] */ ITrnEffectInput __RPC_FAR *pTfxInput,
            /* [out] */ DWORD __RPC_FAR *pObjectId,
            /* [in] */ IVidAsyncAdvise __RPC_FAR *pAdivse) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE LoadEffectIndexed( 
            /* [in] */ ITrnEffectFile __RPC_FAR *pTfxFile,
            /* [in] */ unsigned int index,
            /* [out] */ DWORD __RPC_FAR *pObjectId,
            /* [in] */ IVidAsyncAdvise __RPC_FAR *pAdivse) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IVidLiveSourceVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            IVidLiveSource __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            IVidLiveSource __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            IVidLiveSource __RPC_FAR * This);
        
        EVidSource ( STDMETHODCALLTYPE __RPC_FAR *QuerySourceId )( 
            IVidLiveSource __RPC_FAR * This);
        
        EVidSource ( STDMETHODCALLTYPE __RPC_FAR *QuerySourceType )( 
            IVidLiveSource __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInternalInterface )( 
            IVidLiveSource __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [out] */ void __RPC_FAR *__RPC_FAR *ppvObj);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetStrobe )( 
            IVidLiveSource __RPC_FAR * This,
            /* [in] */ STrnTimeType __RPC_FAR *pTime,
            /* [in] */ DWORD strobeRate,
            /* [in] */ DWORD strobePhase);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SaveFrameStream )( 
            IVidLiveSource __RPC_FAR * This,
            /* [in] */ STrnTimeType __RPC_FAR *pTime,
            /* [in] */ IStream __RPC_FAR *pStream,
            /* [out] */ DWORD __RPC_FAR *pObjectId,
            /* [in] */ IVidAsyncAdvise __RPC_FAR *pAdvise);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SaveFrameMemory )( 
            IVidLiveSource __RPC_FAR * This,
            /* [in] */ STrnTimeType __RPC_FAR *pTime,
            /* [in] */ SPlayBitMap __RPC_FAR *pFrameStore,
            /* [out] */ DWORD __RPC_FAR *pObjectId,
            /* [in] */ IVidAsyncAdvise __RPC_FAR *pAdvise);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *LoadEffect )( 
            IVidLiveSource __RPC_FAR * This,
            /* [in] */ ITrnEffectFile __RPC_FAR *pTfxFile,
            /* [in] */ ITrnEffectInput __RPC_FAR *pTfxInput,
            /* [out] */ DWORD __RPC_FAR *pObjectId,
            /* [in] */ IVidAsyncAdvise __RPC_FAR *pAdivse);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *LoadEffectIndexed )( 
            IVidLiveSource __RPC_FAR * This,
            /* [in] */ ITrnEffectFile __RPC_FAR *pTfxFile,
            /* [in] */ unsigned int index,
            /* [out] */ DWORD __RPC_FAR *pObjectId,
            /* [in] */ IVidAsyncAdvise __RPC_FAR *pAdivse);
        
        END_INTERFACE
    } IVidLiveSourceVtbl;

    interface IVidLiveSource
    {
        CONST_VTBL struct IVidLiveSourceVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IVidLiveSource_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IVidLiveSource_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IVidLiveSource_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IVidLiveSource_QuerySourceId(This)	\
    (This)->lpVtbl -> QuerySourceId(This)

#define IVidLiveSource_QuerySourceType(This)	\
    (This)->lpVtbl -> QuerySourceType(This)

#define IVidLiveSource_QueryInternalInterface(This,riid,ppvObj)	\
    (This)->lpVtbl -> QueryInternalInterface(This,riid,ppvObj)


#define IVidLiveSource_SetStrobe(This,pTime,strobeRate,strobePhase)	\
    (This)->lpVtbl -> SetStrobe(This,pTime,strobeRate,strobePhase)

#define IVidLiveSource_SaveFrameStream(This,pTime,pStream,pObjectId,pAdvise)	\
    (This)->lpVtbl -> SaveFrameStream(This,pTime,pStream,pObjectId,pAdvise)

#define IVidLiveSource_SaveFrameMemory(This,pTime,pFrameStore,pObjectId,pAdvise)	\
    (This)->lpVtbl -> SaveFrameMemory(This,pTime,pFrameStore,pObjectId,pAdvise)

#define IVidLiveSource_LoadEffect(This,pTfxFile,pTfxInput,pObjectId,pAdivse)	\
    (This)->lpVtbl -> LoadEffect(This,pTfxFile,pTfxInput,pObjectId,pAdivse)

#define IVidLiveSource_LoadEffectIndexed(This,pTfxFile,index,pObjectId,pAdivse)	\
    (This)->lpVtbl -> LoadEffectIndexed(This,pTfxFile,index,pObjectId,pAdivse)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE IVidLiveSource_SetStrobe_Proxy( 
    IVidLiveSource __RPC_FAR * This,
    /* [in] */ STrnTimeType __RPC_FAR *pTime,
    /* [in] */ DWORD strobeRate,
    /* [in] */ DWORD strobePhase);


void __RPC_STUB IVidLiveSource_SetStrobe_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVidLiveSource_SaveFrameStream_Proxy( 
    IVidLiveSource __RPC_FAR * This,
    /* [in] */ STrnTimeType __RPC_FAR *pTime,
    /* [in] */ IStream __RPC_FAR *pStream,
    /* [out] */ DWORD __RPC_FAR *pObjectId,
    /* [in] */ IVidAsyncAdvise __RPC_FAR *pAdvise);


void __RPC_STUB IVidLiveSource_SaveFrameStream_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVidLiveSource_SaveFrameMemory_Proxy( 
    IVidLiveSource __RPC_FAR * This,
    /* [in] */ STrnTimeType __RPC_FAR *pTime,
    /* [in] */ SPlayBitMap __RPC_FAR *pFrameStore,
    /* [out] */ DWORD __RPC_FAR *pObjectId,
    /* [in] */ IVidAsyncAdvise __RPC_FAR *pAdvise);


void __RPC_STUB IVidLiveSource_SaveFrameMemory_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVidLiveSource_LoadEffect_Proxy( 
    IVidLiveSource __RPC_FAR * This,
    /* [in] */ ITrnEffectFile __RPC_FAR *pTfxFile,
    /* [in] */ ITrnEffectInput __RPC_FAR *pTfxInput,
    /* [out] */ DWORD __RPC_FAR *pObjectId,
    /* [in] */ IVidAsyncAdvise __RPC_FAR *pAdivse);


void __RPC_STUB IVidLiveSource_LoadEffect_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVidLiveSource_LoadEffectIndexed_Proxy( 
    IVidLiveSource __RPC_FAR * This,
    /* [in] */ ITrnEffectFile __RPC_FAR *pTfxFile,
    /* [in] */ unsigned int index,
    /* [out] */ DWORD __RPC_FAR *pObjectId,
    /* [in] */ IVidAsyncAdvise __RPC_FAR *pAdivse);


void __RPC_STUB IVidLiveSource_LoadEffectIndexed_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IVidLiveSource_INTERFACE_DEFINED__ */


#ifndef __IVidLiveSource2_INTERFACE_DEFINED__
#define __IVidLiveSource2_INTERFACE_DEFINED__

/****************************************
 * Generated header for interface: IVidLiveSource2
 * at Tue Nov 23 05:28:34 1999
 * using MIDL 3.01.75
 ****************************************/
/* [unique][uuid][object][local] */ 



EXTERN_C const IID IID_IVidLiveSource2;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    interface DECLSPEC_UUID("8335e444-ab3b-11ce-8468-0000b468276b")
    IVidLiveSource2 : public IVidLiveSource
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE QueryStrobe( 
            DWORD __RPC_FAR *pRate,
            DWORD __RPC_FAR *pPhase,
            DWORD __RPC_FAR *pSysTime) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IVidLiveSource2Vtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            IVidLiveSource2 __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            IVidLiveSource2 __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            IVidLiveSource2 __RPC_FAR * This);
        
        EVidSource ( STDMETHODCALLTYPE __RPC_FAR *QuerySourceId )( 
            IVidLiveSource2 __RPC_FAR * This);
        
        EVidSource ( STDMETHODCALLTYPE __RPC_FAR *QuerySourceType )( 
            IVidLiveSource2 __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInternalInterface )( 
            IVidLiveSource2 __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [out] */ void __RPC_FAR *__RPC_FAR *ppvObj);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetStrobe )( 
            IVidLiveSource2 __RPC_FAR * This,
            /* [in] */ STrnTimeType __RPC_FAR *pTime,
            /* [in] */ DWORD strobeRate,
            /* [in] */ DWORD strobePhase);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SaveFrameStream )( 
            IVidLiveSource2 __RPC_FAR * This,
            /* [in] */ STrnTimeType __RPC_FAR *pTime,
            /* [in] */ IStream __RPC_FAR *pStream,
            /* [out] */ DWORD __RPC_FAR *pObjectId,
            /* [in] */ IVidAsyncAdvise __RPC_FAR *pAdvise);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SaveFrameMemory )( 
            IVidLiveSource2 __RPC_FAR * This,
            /* [in] */ STrnTimeType __RPC_FAR *pTime,
            /* [in] */ SPlayBitMap __RPC_FAR *pFrameStore,
            /* [out] */ DWORD __RPC_FAR *pObjectId,
            /* [in] */ IVidAsyncAdvise __RPC_FAR *pAdvise);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *LoadEffect )( 
            IVidLiveSource2 __RPC_FAR * This,
            /* [in] */ ITrnEffectFile __RPC_FAR *pTfxFile,
            /* [in] */ ITrnEffectInput __RPC_FAR *pTfxInput,
            /* [out] */ DWORD __RPC_FAR *pObjectId,
            /* [in] */ IVidAsyncAdvise __RPC_FAR *pAdivse);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *LoadEffectIndexed )( 
            IVidLiveSource2 __RPC_FAR * This,
            /* [in] */ ITrnEffectFile __RPC_FAR *pTfxFile,
            /* [in] */ unsigned int index,
            /* [out] */ DWORD __RPC_FAR *pObjectId,
            /* [in] */ IVidAsyncAdvise __RPC_FAR *pAdivse);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryStrobe )( 
            IVidLiveSource2 __RPC_FAR * This,
            DWORD __RPC_FAR *pRate,
            DWORD __RPC_FAR *pPhase,
            DWORD __RPC_FAR *pSysTime);
        
        END_INTERFACE
    } IVidLiveSource2Vtbl;

    interface IVidLiveSource2
    {
        CONST_VTBL struct IVidLiveSource2Vtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IVidLiveSource2_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IVidLiveSource2_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IVidLiveSource2_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IVidLiveSource2_QuerySourceId(This)	\
    (This)->lpVtbl -> QuerySourceId(This)

#define IVidLiveSource2_QuerySourceType(This)	\
    (This)->lpVtbl -> QuerySourceType(This)

#define IVidLiveSource2_QueryInternalInterface(This,riid,ppvObj)	\
    (This)->lpVtbl -> QueryInternalInterface(This,riid,ppvObj)


#define IVidLiveSource2_SetStrobe(This,pTime,strobeRate,strobePhase)	\
    (This)->lpVtbl -> SetStrobe(This,pTime,strobeRate,strobePhase)

#define IVidLiveSource2_SaveFrameStream(This,pTime,pStream,pObjectId,pAdvise)	\
    (This)->lpVtbl -> SaveFrameStream(This,pTime,pStream,pObjectId,pAdvise)

#define IVidLiveSource2_SaveFrameMemory(This,pTime,pFrameStore,pObjectId,pAdvise)	\
    (This)->lpVtbl -> SaveFrameMemory(This,pTime,pFrameStore,pObjectId,pAdvise)

#define IVidLiveSource2_LoadEffect(This,pTfxFile,pTfxInput,pObjectId,pAdivse)	\
    (This)->lpVtbl -> LoadEffect(This,pTfxFile,pTfxInput,pObjectId,pAdivse)

#define IVidLiveSource2_LoadEffectIndexed(This,pTfxFile,index,pObjectId,pAdivse)	\
    (This)->lpVtbl -> LoadEffectIndexed(This,pTfxFile,index,pObjectId,pAdivse)


#define IVidLiveSource2_QueryStrobe(This,pRate,pPhase,pSysTime)	\
    (This)->lpVtbl -> QueryStrobe(This,pRate,pPhase,pSysTime)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE IVidLiveSource2_QueryStrobe_Proxy( 
    IVidLiveSource2 __RPC_FAR * This,
    DWORD __RPC_FAR *pRate,
    DWORD __RPC_FAR *pPhase,
    DWORD __RPC_FAR *pSysTime);


void __RPC_STUB IVidLiveSource2_QueryStrobe_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IVidLiveSource2_INTERFACE_DEFINED__ */


#ifndef __IVidMatteSource_INTERFACE_DEFINED__
#define __IVidMatteSource_INTERFACE_DEFINED__

/****************************************
 * Generated header for interface: IVidMatteSource
 * at Tue Nov 23 05:28:34 1999
 * using MIDL 3.01.75
 ****************************************/
/* [unique][uuid][object][local] */ 



EXTERN_C const IID IID_IVidMatteSource;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    interface DECLSPEC_UUID("8335e5e8-ab3b-11ce-8468-0000b468276b")
    IVidMatteSource : public IVidSource
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE SetMatteColor( 
            /* [in] */ STrnTimeType __RPC_FAR *pTime,
            /* [in] */ DWORD color) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IVidMatteSourceVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            IVidMatteSource __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            IVidMatteSource __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            IVidMatteSource __RPC_FAR * This);
        
        EVidSource ( STDMETHODCALLTYPE __RPC_FAR *QuerySourceId )( 
            IVidMatteSource __RPC_FAR * This);
        
        EVidSource ( STDMETHODCALLTYPE __RPC_FAR *QuerySourceType )( 
            IVidMatteSource __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInternalInterface )( 
            IVidMatteSource __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [out] */ void __RPC_FAR *__RPC_FAR *ppvObj);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetMatteColor )( 
            IVidMatteSource __RPC_FAR * This,
            /* [in] */ STrnTimeType __RPC_FAR *pTime,
            /* [in] */ DWORD color);
        
        END_INTERFACE
    } IVidMatteSourceVtbl;

    interface IVidMatteSource
    {
        CONST_VTBL struct IVidMatteSourceVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IVidMatteSource_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IVidMatteSource_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IVidMatteSource_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IVidMatteSource_QuerySourceId(This)	\
    (This)->lpVtbl -> QuerySourceId(This)

#define IVidMatteSource_QuerySourceType(This)	\
    (This)->lpVtbl -> QuerySourceType(This)

#define IVidMatteSource_QueryInternalInterface(This,riid,ppvObj)	\
    (This)->lpVtbl -> QueryInternalInterface(This,riid,ppvObj)


#define IVidMatteSource_SetMatteColor(This,pTime,color)	\
    (This)->lpVtbl -> SetMatteColor(This,pTime,color)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE IVidMatteSource_SetMatteColor_Proxy( 
    IVidMatteSource __RPC_FAR * This,
    /* [in] */ STrnTimeType __RPC_FAR *pTime,
    /* [in] */ DWORD color);


void __RPC_STUB IVidMatteSource_SetMatteColor_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IVidMatteSource_INTERFACE_DEFINED__ */


#ifndef __IVidFramestoreSource_INTERFACE_DEFINED__
#define __IVidFramestoreSource_INTERFACE_DEFINED__

/****************************************
 * Generated header for interface: IVidFramestoreSource
 * at Tue Nov 23 05:28:34 1999
 * using MIDL 3.01.75
 ****************************************/
/* [unique][uuid][object][local] */ 



EXTERN_C const IID IID_IVidFramestoreSource;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    interface DECLSPEC_UUID("8335e5e9-ab3b-11ce-8468-0000b468276b")
    IVidFramestoreSource : public IVidSource
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE LoadFrameStoreStream( 
            /* [in] */ IStream __RPC_FAR *pStream,
            /* [out] */ DWORD __RPC_FAR *pObjectId,
            /* [in] */ IVidAsyncAdvise __RPC_FAR *pAdvise) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE LoadFrameStoreMemory( 
            /* [in] */ SPlayBitMap __RPC_FAR *pFrameStore,
            /* [out] */ DWORD __RPC_FAR *pObjectId,
            /* [in] */ IVidAsyncAdvise __RPC_FAR *pAdvise) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SaveFrameStoreStream( 
            /* [in] */ IStream __RPC_FAR *pStream,
            /* [out] */ DWORD __RPC_FAR *pObjectId,
            /* [in] */ IVidAsyncAdvise __RPC_FAR *pAdvise) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SaveFrameStoreMemory( 
            /* [in] */ SPlayBitMap __RPC_FAR *pFrameStore,
            /* [out] */ DWORD __RPC_FAR *pObjectId,
            /* [in] */ IVidAsyncAdvise __RPC_FAR *pAdvise) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GrabLiveFrame( 
            /* [in] */ STrnTimeType __RPC_FAR *pTime,
            /* [in] */ EVidSource sourceToFreeze,
            /* [out] */ DWORD __RPC_FAR *pObjectId,
            /* [in] */ IVidAsyncAdvise __RPC_FAR *pAdvise) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IVidFramestoreSourceVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            IVidFramestoreSource __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            IVidFramestoreSource __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            IVidFramestoreSource __RPC_FAR * This);
        
        EVidSource ( STDMETHODCALLTYPE __RPC_FAR *QuerySourceId )( 
            IVidFramestoreSource __RPC_FAR * This);
        
        EVidSource ( STDMETHODCALLTYPE __RPC_FAR *QuerySourceType )( 
            IVidFramestoreSource __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInternalInterface )( 
            IVidFramestoreSource __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [out] */ void __RPC_FAR *__RPC_FAR *ppvObj);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *LoadFrameStoreStream )( 
            IVidFramestoreSource __RPC_FAR * This,
            /* [in] */ IStream __RPC_FAR *pStream,
            /* [out] */ DWORD __RPC_FAR *pObjectId,
            /* [in] */ IVidAsyncAdvise __RPC_FAR *pAdvise);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *LoadFrameStoreMemory )( 
            IVidFramestoreSource __RPC_FAR * This,
            /* [in] */ SPlayBitMap __RPC_FAR *pFrameStore,
            /* [out] */ DWORD __RPC_FAR *pObjectId,
            /* [in] */ IVidAsyncAdvise __RPC_FAR *pAdvise);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SaveFrameStoreStream )( 
            IVidFramestoreSource __RPC_FAR * This,
            /* [in] */ IStream __RPC_FAR *pStream,
            /* [out] */ DWORD __RPC_FAR *pObjectId,
            /* [in] */ IVidAsyncAdvise __RPC_FAR *pAdvise);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SaveFrameStoreMemory )( 
            IVidFramestoreSource __RPC_FAR * This,
            /* [in] */ SPlayBitMap __RPC_FAR *pFrameStore,
            /* [out] */ DWORD __RPC_FAR *pObjectId,
            /* [in] */ IVidAsyncAdvise __RPC_FAR *pAdvise);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GrabLiveFrame )( 
            IVidFramestoreSource __RPC_FAR * This,
            /* [in] */ STrnTimeType __RPC_FAR *pTime,
            /* [in] */ EVidSource sourceToFreeze,
            /* [out] */ DWORD __RPC_FAR *pObjectId,
            /* [in] */ IVidAsyncAdvise __RPC_FAR *pAdvise);
        
        END_INTERFACE
    } IVidFramestoreSourceVtbl;

    interface IVidFramestoreSource
    {
        CONST_VTBL struct IVidFramestoreSourceVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IVidFramestoreSource_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IVidFramestoreSource_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IVidFramestoreSource_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IVidFramestoreSource_QuerySourceId(This)	\
    (This)->lpVtbl -> QuerySourceId(This)

#define IVidFramestoreSource_QuerySourceType(This)	\
    (This)->lpVtbl -> QuerySourceType(This)

#define IVidFramestoreSource_QueryInternalInterface(This,riid,ppvObj)	\
    (This)->lpVtbl -> QueryInternalInterface(This,riid,ppvObj)


#define IVidFramestoreSource_LoadFrameStoreStream(This,pStream,pObjectId,pAdvise)	\
    (This)->lpVtbl -> LoadFrameStoreStream(This,pStream,pObjectId,pAdvise)

#define IVidFramestoreSource_LoadFrameStoreMemory(This,pFrameStore,pObjectId,pAdvise)	\
    (This)->lpVtbl -> LoadFrameStoreMemory(This,pFrameStore,pObjectId,pAdvise)

#define IVidFramestoreSource_SaveFrameStoreStream(This,pStream,pObjectId,pAdvise)	\
    (This)->lpVtbl -> SaveFrameStoreStream(This,pStream,pObjectId,pAdvise)

#define IVidFramestoreSource_SaveFrameStoreMemory(This,pFrameStore,pObjectId,pAdvise)	\
    (This)->lpVtbl -> SaveFrameStoreMemory(This,pFrameStore,pObjectId,pAdvise)

#define IVidFramestoreSource_GrabLiveFrame(This,pTime,sourceToFreeze,pObjectId,pAdvise)	\
    (This)->lpVtbl -> GrabLiveFrame(This,pTime,sourceToFreeze,pObjectId,pAdvise)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE IVidFramestoreSource_LoadFrameStoreStream_Proxy( 
    IVidFramestoreSource __RPC_FAR * This,
    /* [in] */ IStream __RPC_FAR *pStream,
    /* [out] */ DWORD __RPC_FAR *pObjectId,
    /* [in] */ IVidAsyncAdvise __RPC_FAR *pAdvise);


void __RPC_STUB IVidFramestoreSource_LoadFrameStoreStream_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVidFramestoreSource_LoadFrameStoreMemory_Proxy( 
    IVidFramestoreSource __RPC_FAR * This,
    /* [in] */ SPlayBitMap __RPC_FAR *pFrameStore,
    /* [out] */ DWORD __RPC_FAR *pObjectId,
    /* [in] */ IVidAsyncAdvise __RPC_FAR *pAdvise);


void __RPC_STUB IVidFramestoreSource_LoadFrameStoreMemory_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVidFramestoreSource_SaveFrameStoreStream_Proxy( 
    IVidFramestoreSource __RPC_FAR * This,
    /* [in] */ IStream __RPC_FAR *pStream,
    /* [out] */ DWORD __RPC_FAR *pObjectId,
    /* [in] */ IVidAsyncAdvise __RPC_FAR *pAdvise);


void __RPC_STUB IVidFramestoreSource_SaveFrameStoreStream_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVidFramestoreSource_SaveFrameStoreMemory_Proxy( 
    IVidFramestoreSource __RPC_FAR * This,
    /* [in] */ SPlayBitMap __RPC_FAR *pFrameStore,
    /* [out] */ DWORD __RPC_FAR *pObjectId,
    /* [in] */ IVidAsyncAdvise __RPC_FAR *pAdvise);


void __RPC_STUB IVidFramestoreSource_SaveFrameStoreMemory_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVidFramestoreSource_GrabLiveFrame_Proxy( 
    IVidFramestoreSource __RPC_FAR * This,
    /* [in] */ STrnTimeType __RPC_FAR *pTime,
    /* [in] */ EVidSource sourceToFreeze,
    /* [out] */ DWORD __RPC_FAR *pObjectId,
    /* [in] */ IVidAsyncAdvise __RPC_FAR *pAdvise);


void __RPC_STUB IVidFramestoreSource_GrabLiveFrame_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IVidFramestoreSource_INTERFACE_DEFINED__ */


#ifndef __IVidEffect_INTERFACE_DEFINED__
#define __IVidEffect_INTERFACE_DEFINED__

/****************************************
 * Generated header for interface: IVidEffect
 * at Tue Nov 23 05:28:34 1999
 * using MIDL 3.01.75
 ****************************************/
/* [unique][uuid][object][local] */ 


typedef 
enum tagEVEStopFlags
    {	VEUndoEffect	= 1,
	VEDoEffect	= 2
    }	EVEStopFlags;


EXTERN_C const IID IID_IVidEffect;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    interface DECLSPEC_UUID("8335e41c-ab3b-11ce-8468-0000b468276b")
    IVidEffect : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE SaveAs( 
            /* [in] */ const unsigned char __RPC_FAR *pszFileName) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Play( 
            /* [in] */ STrnTimeType __RPC_FAR *pTime,
            /* [in] */ BOOL takeResources) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Clone( 
            /* [out] */ IVidEffect __RPC_FAR *__RPC_FAR *ppNewEffect) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Stop( 
            /* [in] */ STrnTimeType __RPC_FAR *pTime,
            /* [in] */ DWORD stopFlags) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE LockForUpdate( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Unlock( void) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IVidEffectVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            IVidEffect __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            IVidEffect __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            IVidEffect __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SaveAs )( 
            IVidEffect __RPC_FAR * This,
            /* [in] */ const unsigned char __RPC_FAR *pszFileName);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Play )( 
            IVidEffect __RPC_FAR * This,
            /* [in] */ STrnTimeType __RPC_FAR *pTime,
            /* [in] */ BOOL takeResources);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Clone )( 
            IVidEffect __RPC_FAR * This,
            /* [out] */ IVidEffect __RPC_FAR *__RPC_FAR *ppNewEffect);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Stop )( 
            IVidEffect __RPC_FAR * This,
            /* [in] */ STrnTimeType __RPC_FAR *pTime,
            /* [in] */ DWORD stopFlags);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *LockForUpdate )( 
            IVidEffect __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Unlock )( 
            IVidEffect __RPC_FAR * This);
        
        END_INTERFACE
    } IVidEffectVtbl;

    interface IVidEffect
    {
        CONST_VTBL struct IVidEffectVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IVidEffect_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IVidEffect_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IVidEffect_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IVidEffect_SaveAs(This,pszFileName)	\
    (This)->lpVtbl -> SaveAs(This,pszFileName)

#define IVidEffect_Play(This,pTime,takeResources)	\
    (This)->lpVtbl -> Play(This,pTime,takeResources)

#define IVidEffect_Clone(This,ppNewEffect)	\
    (This)->lpVtbl -> Clone(This,ppNewEffect)

#define IVidEffect_Stop(This,pTime,stopFlags)	\
    (This)->lpVtbl -> Stop(This,pTime,stopFlags)

#define IVidEffect_LockForUpdate(This)	\
    (This)->lpVtbl -> LockForUpdate(This)

#define IVidEffect_Unlock(This)	\
    (This)->lpVtbl -> Unlock(This)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE IVidEffect_SaveAs_Proxy( 
    IVidEffect __RPC_FAR * This,
    /* [in] */ const unsigned char __RPC_FAR *pszFileName);


void __RPC_STUB IVidEffect_SaveAs_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVidEffect_Play_Proxy( 
    IVidEffect __RPC_FAR * This,
    /* [in] */ STrnTimeType __RPC_FAR *pTime,
    /* [in] */ BOOL takeResources);


void __RPC_STUB IVidEffect_Play_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVidEffect_Clone_Proxy( 
    IVidEffect __RPC_FAR * This,
    /* [out] */ IVidEffect __RPC_FAR *__RPC_FAR *ppNewEffect);


void __RPC_STUB IVidEffect_Clone_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVidEffect_Stop_Proxy( 
    IVidEffect __RPC_FAR * This,
    /* [in] */ STrnTimeType __RPC_FAR *pTime,
    /* [in] */ DWORD stopFlags);


void __RPC_STUB IVidEffect_Stop_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVidEffect_LockForUpdate_Proxy( 
    IVidEffect __RPC_FAR * This);


void __RPC_STUB IVidEffect_LockForUpdate_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVidEffect_Unlock_Proxy( 
    IVidEffect __RPC_FAR * This);


void __RPC_STUB IVidEffect_Unlock_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IVidEffect_INTERFACE_DEFINED__ */


#ifndef __IVidEffect2_INTERFACE_DEFINED__
#define __IVidEffect2_INTERFACE_DEFINED__

/****************************************
 * Generated header for interface: IVidEffect2
 * at Tue Nov 23 05:28:34 1999
 * using MIDL 3.01.75
 ****************************************/
/* [unique][uuid][object][local] */ 



EXTERN_C const IID IID_IVidEffect2;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    interface DECLSPEC_UUID("8335e455-ab3b-11ce-8468-0000b468276b")
    IVidEffect2 : public IVidEffect
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE EffectStatus( void) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IVidEffect2Vtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            IVidEffect2 __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            IVidEffect2 __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            IVidEffect2 __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SaveAs )( 
            IVidEffect2 __RPC_FAR * This,
            /* [in] */ const unsigned char __RPC_FAR *pszFileName);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Play )( 
            IVidEffect2 __RPC_FAR * This,
            /* [in] */ STrnTimeType __RPC_FAR *pTime,
            /* [in] */ BOOL takeResources);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Clone )( 
            IVidEffect2 __RPC_FAR * This,
            /* [out] */ IVidEffect __RPC_FAR *__RPC_FAR *ppNewEffect);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Stop )( 
            IVidEffect2 __RPC_FAR * This,
            /* [in] */ STrnTimeType __RPC_FAR *pTime,
            /* [in] */ DWORD stopFlags);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *LockForUpdate )( 
            IVidEffect2 __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Unlock )( 
            IVidEffect2 __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *EffectStatus )( 
            IVidEffect2 __RPC_FAR * This);
        
        END_INTERFACE
    } IVidEffect2Vtbl;

    interface IVidEffect2
    {
        CONST_VTBL struct IVidEffect2Vtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IVidEffect2_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IVidEffect2_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IVidEffect2_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IVidEffect2_SaveAs(This,pszFileName)	\
    (This)->lpVtbl -> SaveAs(This,pszFileName)

#define IVidEffect2_Play(This,pTime,takeResources)	\
    (This)->lpVtbl -> Play(This,pTime,takeResources)

#define IVidEffect2_Clone(This,ppNewEffect)	\
    (This)->lpVtbl -> Clone(This,ppNewEffect)

#define IVidEffect2_Stop(This,pTime,stopFlags)	\
    (This)->lpVtbl -> Stop(This,pTime,stopFlags)

#define IVidEffect2_LockForUpdate(This)	\
    (This)->lpVtbl -> LockForUpdate(This)

#define IVidEffect2_Unlock(This)	\
    (This)->lpVtbl -> Unlock(This)


#define IVidEffect2_EffectStatus(This)	\
    (This)->lpVtbl -> EffectStatus(This)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE IVidEffect2_EffectStatus_Proxy( 
    IVidEffect2 __RPC_FAR * This);


void __RPC_STUB IVidEffect2_EffectStatus_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IVidEffect2_INTERFACE_DEFINED__ */


#ifndef __IVidAdviseSink2_INTERFACE_DEFINED__
#define __IVidAdviseSink2_INTERFACE_DEFINED__

/****************************************
 * Generated header for interface: IVidAdviseSink2
 * at Tue Nov 23 05:28:34 1999
 * using MIDL 3.01.75
 ****************************************/
/* [unique][uuid][object][local] */ 


typedef struct  tagSVidRouteInfo
    {
    EVidBus whichBus;
    EVidSource whichSource;
    }	SVidRouteInfo;

typedef 
enum tagEVidEffectAction
    {	EAStarted	= 0,
	EAFinished	= EAStarted + 1,
	EAUnDone	= EAFinished + 1,
	EAStartBlocked	= EAUnDone + 1,
	EAAborted	= EAStartBlocked + 1,
	EAUnloaded	= EAAborted + 1,
	EALocked	= EAUnloaded + 1,
	EAUnlocked	= EALocked + 1,
	EALockFailed	= EAUnlocked + 1,
	EAResourceChange	= EALockFailed + 1
    }	EVidEffectAction;


EXTERN_C const IID IID_IVidAdviseSink2;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    interface DECLSPEC_UUID("8335e42c-ab3b-11ce-8468-0000b468276b")
    IVidAdviseSink2 : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE OnRoutingChange( 
            /* [in] */ unsigned int numUpdates,
            /* [in] */ SVidRouteInfo __RPC_FAR *pUpdates) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE OnModeChange( 
            /* [in] */ EVidMixerMode mode) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE OnEffectLoad( 
            /* [in] */ DWORD objectId) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE OnInputEffectLoad( 
            /* [in] */ DWORD objectId,
            /* [in] */ ITrnEffectFile __RPC_FAR *pTfxFile,
            /* [in] */ ITrnEffectInput __RPC_FAR *pTfxInput) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE OnEffectUnload( 
            /* [in] */ DWORD objectId) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE OnFramestoreComplete( 
            /* [in] */ EVidSource whichSource,
            /* [in] */ DWORD objectId,
            /* [in] */ EVidOperation whatOp) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE OnAsyncError( 
            /* [in] */ DWORD objectId,
            /* [in] */ HRESULT loadResult) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE OnEffectAction( 
            /* [in] */ DWORD objectId,
            /* [in] */ EVidEffectAction action) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE OnLoadConflict( 
            /* [in] */ DWORD newObjectId,
            /* [in] */ DWORD oldObjectId,
            /* [in] */ BOOL resourceWasTaken) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IVidAdviseSink2Vtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            IVidAdviseSink2 __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            IVidAdviseSink2 __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            IVidAdviseSink2 __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *OnRoutingChange )( 
            IVidAdviseSink2 __RPC_FAR * This,
            /* [in] */ unsigned int numUpdates,
            /* [in] */ SVidRouteInfo __RPC_FAR *pUpdates);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *OnModeChange )( 
            IVidAdviseSink2 __RPC_FAR * This,
            /* [in] */ EVidMixerMode mode);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *OnEffectLoad )( 
            IVidAdviseSink2 __RPC_FAR * This,
            /* [in] */ DWORD objectId);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *OnInputEffectLoad )( 
            IVidAdviseSink2 __RPC_FAR * This,
            /* [in] */ DWORD objectId,
            /* [in] */ ITrnEffectFile __RPC_FAR *pTfxFile,
            /* [in] */ ITrnEffectInput __RPC_FAR *pTfxInput);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *OnEffectUnload )( 
            IVidAdviseSink2 __RPC_FAR * This,
            /* [in] */ DWORD objectId);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *OnFramestoreComplete )( 
            IVidAdviseSink2 __RPC_FAR * This,
            /* [in] */ EVidSource whichSource,
            /* [in] */ DWORD objectId,
            /* [in] */ EVidOperation whatOp);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *OnAsyncError )( 
            IVidAdviseSink2 __RPC_FAR * This,
            /* [in] */ DWORD objectId,
            /* [in] */ HRESULT loadResult);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *OnEffectAction )( 
            IVidAdviseSink2 __RPC_FAR * This,
            /* [in] */ DWORD objectId,
            /* [in] */ EVidEffectAction action);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *OnLoadConflict )( 
            IVidAdviseSink2 __RPC_FAR * This,
            /* [in] */ DWORD newObjectId,
            /* [in] */ DWORD oldObjectId,
            /* [in] */ BOOL resourceWasTaken);
        
        END_INTERFACE
    } IVidAdviseSink2Vtbl;

    interface IVidAdviseSink2
    {
        CONST_VTBL struct IVidAdviseSink2Vtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IVidAdviseSink2_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IVidAdviseSink2_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IVidAdviseSink2_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IVidAdviseSink2_OnRoutingChange(This,numUpdates,pUpdates)	\
    (This)->lpVtbl -> OnRoutingChange(This,numUpdates,pUpdates)

#define IVidAdviseSink2_OnModeChange(This,mode)	\
    (This)->lpVtbl -> OnModeChange(This,mode)

#define IVidAdviseSink2_OnEffectLoad(This,objectId)	\
    (This)->lpVtbl -> OnEffectLoad(This,objectId)

#define IVidAdviseSink2_OnInputEffectLoad(This,objectId,pTfxFile,pTfxInput)	\
    (This)->lpVtbl -> OnInputEffectLoad(This,objectId,pTfxFile,pTfxInput)

#define IVidAdviseSink2_OnEffectUnload(This,objectId)	\
    (This)->lpVtbl -> OnEffectUnload(This,objectId)

#define IVidAdviseSink2_OnFramestoreComplete(This,whichSource,objectId,whatOp)	\
    (This)->lpVtbl -> OnFramestoreComplete(This,whichSource,objectId,whatOp)

#define IVidAdviseSink2_OnAsyncError(This,objectId,loadResult)	\
    (This)->lpVtbl -> OnAsyncError(This,objectId,loadResult)

#define IVidAdviseSink2_OnEffectAction(This,objectId,action)	\
    (This)->lpVtbl -> OnEffectAction(This,objectId,action)

#define IVidAdviseSink2_OnLoadConflict(This,newObjectId,oldObjectId,resourceWasTaken)	\
    (This)->lpVtbl -> OnLoadConflict(This,newObjectId,oldObjectId,resourceWasTaken)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE IVidAdviseSink2_OnRoutingChange_Proxy( 
    IVidAdviseSink2 __RPC_FAR * This,
    /* [in] */ unsigned int numUpdates,
    /* [in] */ SVidRouteInfo __RPC_FAR *pUpdates);


void __RPC_STUB IVidAdviseSink2_OnRoutingChange_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVidAdviseSink2_OnModeChange_Proxy( 
    IVidAdviseSink2 __RPC_FAR * This,
    /* [in] */ EVidMixerMode mode);


void __RPC_STUB IVidAdviseSink2_OnModeChange_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVidAdviseSink2_OnEffectLoad_Proxy( 
    IVidAdviseSink2 __RPC_FAR * This,
    /* [in] */ DWORD objectId);


void __RPC_STUB IVidAdviseSink2_OnEffectLoad_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVidAdviseSink2_OnInputEffectLoad_Proxy( 
    IVidAdviseSink2 __RPC_FAR * This,
    /* [in] */ DWORD objectId,
    /* [in] */ ITrnEffectFile __RPC_FAR *pTfxFile,
    /* [in] */ ITrnEffectInput __RPC_FAR *pTfxInput);


void __RPC_STUB IVidAdviseSink2_OnInputEffectLoad_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVidAdviseSink2_OnEffectUnload_Proxy( 
    IVidAdviseSink2 __RPC_FAR * This,
    /* [in] */ DWORD objectId);


void __RPC_STUB IVidAdviseSink2_OnEffectUnload_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVidAdviseSink2_OnFramestoreComplete_Proxy( 
    IVidAdviseSink2 __RPC_FAR * This,
    /* [in] */ EVidSource whichSource,
    /* [in] */ DWORD objectId,
    /* [in] */ EVidOperation whatOp);


void __RPC_STUB IVidAdviseSink2_OnFramestoreComplete_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVidAdviseSink2_OnAsyncError_Proxy( 
    IVidAdviseSink2 __RPC_FAR * This,
    /* [in] */ DWORD objectId,
    /* [in] */ HRESULT loadResult);


void __RPC_STUB IVidAdviseSink2_OnAsyncError_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVidAdviseSink2_OnEffectAction_Proxy( 
    IVidAdviseSink2 __RPC_FAR * This,
    /* [in] */ DWORD objectId,
    /* [in] */ EVidEffectAction action);


void __RPC_STUB IVidAdviseSink2_OnEffectAction_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVidAdviseSink2_OnLoadConflict_Proxy( 
    IVidAdviseSink2 __RPC_FAR * This,
    /* [in] */ DWORD newObjectId,
    /* [in] */ DWORD oldObjectId,
    /* [in] */ BOOL resourceWasTaken);


void __RPC_STUB IVidAdviseSink2_OnLoadConflict_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IVidAdviseSink2_INTERFACE_DEFINED__ */


#ifndef __IVidAdviseSink3_INTERFACE_DEFINED__
#define __IVidAdviseSink3_INTERFACE_DEFINED__

/****************************************
 * Generated header for interface: IVidAdviseSink3
 * at Tue Nov 23 05:28:34 1999
 * using MIDL 3.01.75
 ****************************************/
/* [unique][uuid][object][local] */ 


typedef 
enum tagEVidSourceAction
    {	SACreated	= 0,
	SADeleted	= SACreated + 1,
	SALive	= SADeleted + 1,
	SAStrobe	= SALive + 1,
	SAFreeze	= SAStrobe + 1,
	SASignalState	= 0x80000000,
	SASignalDetect	= 1,
	SASignalSync	= 2,
	SASignalFramed	= 4
    }	EVidSourceAction;


EXTERN_C const IID IID_IVidAdviseSink3;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    interface DECLSPEC_UUID("8335e40e-ab3b-11ce-8468-0000b468276b")
    IVidAdviseSink3 : public IVidAdviseSink2
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE OnSourceAction( 
            /* [in] */ EVidSource whichSource,
            /* [in] */ EVidSource sourceType,
            /* [in] */ EVidSourceAction action) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE OnEvent( 
            /* [in] */ DWORD dwSystemTime,
            /* [in] */ DWORD dwEvent) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE OnSetPreview( 
            /* [in] */ EVidBus previewBus) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IVidAdviseSink3Vtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            IVidAdviseSink3 __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            IVidAdviseSink3 __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            IVidAdviseSink3 __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *OnRoutingChange )( 
            IVidAdviseSink3 __RPC_FAR * This,
            /* [in] */ unsigned int numUpdates,
            /* [in] */ SVidRouteInfo __RPC_FAR *pUpdates);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *OnModeChange )( 
            IVidAdviseSink3 __RPC_FAR * This,
            /* [in] */ EVidMixerMode mode);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *OnEffectLoad )( 
            IVidAdviseSink3 __RPC_FAR * This,
            /* [in] */ DWORD objectId);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *OnInputEffectLoad )( 
            IVidAdviseSink3 __RPC_FAR * This,
            /* [in] */ DWORD objectId,
            /* [in] */ ITrnEffectFile __RPC_FAR *pTfxFile,
            /* [in] */ ITrnEffectInput __RPC_FAR *pTfxInput);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *OnEffectUnload )( 
            IVidAdviseSink3 __RPC_FAR * This,
            /* [in] */ DWORD objectId);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *OnFramestoreComplete )( 
            IVidAdviseSink3 __RPC_FAR * This,
            /* [in] */ EVidSource whichSource,
            /* [in] */ DWORD objectId,
            /* [in] */ EVidOperation whatOp);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *OnAsyncError )( 
            IVidAdviseSink3 __RPC_FAR * This,
            /* [in] */ DWORD objectId,
            /* [in] */ HRESULT loadResult);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *OnEffectAction )( 
            IVidAdviseSink3 __RPC_FAR * This,
            /* [in] */ DWORD objectId,
            /* [in] */ EVidEffectAction action);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *OnLoadConflict )( 
            IVidAdviseSink3 __RPC_FAR * This,
            /* [in] */ DWORD newObjectId,
            /* [in] */ DWORD oldObjectId,
            /* [in] */ BOOL resourceWasTaken);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *OnSourceAction )( 
            IVidAdviseSink3 __RPC_FAR * This,
            /* [in] */ EVidSource whichSource,
            /* [in] */ EVidSource sourceType,
            /* [in] */ EVidSourceAction action);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *OnEvent )( 
            IVidAdviseSink3 __RPC_FAR * This,
            /* [in] */ DWORD dwSystemTime,
            /* [in] */ DWORD dwEvent);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *OnSetPreview )( 
            IVidAdviseSink3 __RPC_FAR * This,
            /* [in] */ EVidBus previewBus);
        
        END_INTERFACE
    } IVidAdviseSink3Vtbl;

    interface IVidAdviseSink3
    {
        CONST_VTBL struct IVidAdviseSink3Vtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IVidAdviseSink3_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IVidAdviseSink3_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IVidAdviseSink3_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IVidAdviseSink3_OnRoutingChange(This,numUpdates,pUpdates)	\
    (This)->lpVtbl -> OnRoutingChange(This,numUpdates,pUpdates)

#define IVidAdviseSink3_OnModeChange(This,mode)	\
    (This)->lpVtbl -> OnModeChange(This,mode)

#define IVidAdviseSink3_OnEffectLoad(This,objectId)	\
    (This)->lpVtbl -> OnEffectLoad(This,objectId)

#define IVidAdviseSink3_OnInputEffectLoad(This,objectId,pTfxFile,pTfxInput)	\
    (This)->lpVtbl -> OnInputEffectLoad(This,objectId,pTfxFile,pTfxInput)

#define IVidAdviseSink3_OnEffectUnload(This,objectId)	\
    (This)->lpVtbl -> OnEffectUnload(This,objectId)

#define IVidAdviseSink3_OnFramestoreComplete(This,whichSource,objectId,whatOp)	\
    (This)->lpVtbl -> OnFramestoreComplete(This,whichSource,objectId,whatOp)

#define IVidAdviseSink3_OnAsyncError(This,objectId,loadResult)	\
    (This)->lpVtbl -> OnAsyncError(This,objectId,loadResult)

#define IVidAdviseSink3_OnEffectAction(This,objectId,action)	\
    (This)->lpVtbl -> OnEffectAction(This,objectId,action)

#define IVidAdviseSink3_OnLoadConflict(This,newObjectId,oldObjectId,resourceWasTaken)	\
    (This)->lpVtbl -> OnLoadConflict(This,newObjectId,oldObjectId,resourceWasTaken)


#define IVidAdviseSink3_OnSourceAction(This,whichSource,sourceType,action)	\
    (This)->lpVtbl -> OnSourceAction(This,whichSource,sourceType,action)

#define IVidAdviseSink3_OnEvent(This,dwSystemTime,dwEvent)	\
    (This)->lpVtbl -> OnEvent(This,dwSystemTime,dwEvent)

#define IVidAdviseSink3_OnSetPreview(This,previewBus)	\
    (This)->lpVtbl -> OnSetPreview(This,previewBus)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE IVidAdviseSink3_OnSourceAction_Proxy( 
    IVidAdviseSink3 __RPC_FAR * This,
    /* [in] */ EVidSource whichSource,
    /* [in] */ EVidSource sourceType,
    /* [in] */ EVidSourceAction action);


void __RPC_STUB IVidAdviseSink3_OnSourceAction_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVidAdviseSink3_OnEvent_Proxy( 
    IVidAdviseSink3 __RPC_FAR * This,
    /* [in] */ DWORD dwSystemTime,
    /* [in] */ DWORD dwEvent);


void __RPC_STUB IVidAdviseSink3_OnEvent_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVidAdviseSink3_OnSetPreview_Proxy( 
    IVidAdviseSink3 __RPC_FAR * This,
    /* [in] */ EVidBus previewBus);


void __RPC_STUB IVidAdviseSink3_OnSetPreview_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IVidAdviseSink3_INTERFACE_DEFINED__ */


#ifndef __IVidAdviseSink4_INTERFACE_DEFINED__
#define __IVidAdviseSink4_INTERFACE_DEFINED__

/****************************************
 * Generated header for interface: IVidAdviseSink4
 * at Tue Nov 23 05:28:34 1999
 * using MIDL 3.01.75
 ****************************************/
/* [unique][uuid][object][local] */ 



EXTERN_C const IID IID_IVidAdviseSink4;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    interface DECLSPEC_UUID("8335e443-ab3b-11ce-8468-0000b468276b")
    IVidAdviseSink4 : public IVidAdviseSink3
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE OnSetSystemMode( 
            /* [in] */ DWORD sysMode) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IVidAdviseSink4Vtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            IVidAdviseSink4 __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            IVidAdviseSink4 __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            IVidAdviseSink4 __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *OnRoutingChange )( 
            IVidAdviseSink4 __RPC_FAR * This,
            /* [in] */ unsigned int numUpdates,
            /* [in] */ SVidRouteInfo __RPC_FAR *pUpdates);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *OnModeChange )( 
            IVidAdviseSink4 __RPC_FAR * This,
            /* [in] */ EVidMixerMode mode);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *OnEffectLoad )( 
            IVidAdviseSink4 __RPC_FAR * This,
            /* [in] */ DWORD objectId);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *OnInputEffectLoad )( 
            IVidAdviseSink4 __RPC_FAR * This,
            /* [in] */ DWORD objectId,
            /* [in] */ ITrnEffectFile __RPC_FAR *pTfxFile,
            /* [in] */ ITrnEffectInput __RPC_FAR *pTfxInput);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *OnEffectUnload )( 
            IVidAdviseSink4 __RPC_FAR * This,
            /* [in] */ DWORD objectId);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *OnFramestoreComplete )( 
            IVidAdviseSink4 __RPC_FAR * This,
            /* [in] */ EVidSource whichSource,
            /* [in] */ DWORD objectId,
            /* [in] */ EVidOperation whatOp);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *OnAsyncError )( 
            IVidAdviseSink4 __RPC_FAR * This,
            /* [in] */ DWORD objectId,
            /* [in] */ HRESULT loadResult);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *OnEffectAction )( 
            IVidAdviseSink4 __RPC_FAR * This,
            /* [in] */ DWORD objectId,
            /* [in] */ EVidEffectAction action);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *OnLoadConflict )( 
            IVidAdviseSink4 __RPC_FAR * This,
            /* [in] */ DWORD newObjectId,
            /* [in] */ DWORD oldObjectId,
            /* [in] */ BOOL resourceWasTaken);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *OnSourceAction )( 
            IVidAdviseSink4 __RPC_FAR * This,
            /* [in] */ EVidSource whichSource,
            /* [in] */ EVidSource sourceType,
            /* [in] */ EVidSourceAction action);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *OnEvent )( 
            IVidAdviseSink4 __RPC_FAR * This,
            /* [in] */ DWORD dwSystemTime,
            /* [in] */ DWORD dwEvent);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *OnSetPreview )( 
            IVidAdviseSink4 __RPC_FAR * This,
            /* [in] */ EVidBus previewBus);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *OnSetSystemMode )( 
            IVidAdviseSink4 __RPC_FAR * This,
            /* [in] */ DWORD sysMode);
        
        END_INTERFACE
    } IVidAdviseSink4Vtbl;

    interface IVidAdviseSink4
    {
        CONST_VTBL struct IVidAdviseSink4Vtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IVidAdviseSink4_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IVidAdviseSink4_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IVidAdviseSink4_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IVidAdviseSink4_OnRoutingChange(This,numUpdates,pUpdates)	\
    (This)->lpVtbl -> OnRoutingChange(This,numUpdates,pUpdates)

#define IVidAdviseSink4_OnModeChange(This,mode)	\
    (This)->lpVtbl -> OnModeChange(This,mode)

#define IVidAdviseSink4_OnEffectLoad(This,objectId)	\
    (This)->lpVtbl -> OnEffectLoad(This,objectId)

#define IVidAdviseSink4_OnInputEffectLoad(This,objectId,pTfxFile,pTfxInput)	\
    (This)->lpVtbl -> OnInputEffectLoad(This,objectId,pTfxFile,pTfxInput)

#define IVidAdviseSink4_OnEffectUnload(This,objectId)	\
    (This)->lpVtbl -> OnEffectUnload(This,objectId)

#define IVidAdviseSink4_OnFramestoreComplete(This,whichSource,objectId,whatOp)	\
    (This)->lpVtbl -> OnFramestoreComplete(This,whichSource,objectId,whatOp)

#define IVidAdviseSink4_OnAsyncError(This,objectId,loadResult)	\
    (This)->lpVtbl -> OnAsyncError(This,objectId,loadResult)

#define IVidAdviseSink4_OnEffectAction(This,objectId,action)	\
    (This)->lpVtbl -> OnEffectAction(This,objectId,action)

#define IVidAdviseSink4_OnLoadConflict(This,newObjectId,oldObjectId,resourceWasTaken)	\
    (This)->lpVtbl -> OnLoadConflict(This,newObjectId,oldObjectId,resourceWasTaken)


#define IVidAdviseSink4_OnSourceAction(This,whichSource,sourceType,action)	\
    (This)->lpVtbl -> OnSourceAction(This,whichSource,sourceType,action)

#define IVidAdviseSink4_OnEvent(This,dwSystemTime,dwEvent)	\
    (This)->lpVtbl -> OnEvent(This,dwSystemTime,dwEvent)

#define IVidAdviseSink4_OnSetPreview(This,previewBus)	\
    (This)->lpVtbl -> OnSetPreview(This,previewBus)


#define IVidAdviseSink4_OnSetSystemMode(This,sysMode)	\
    (This)->lpVtbl -> OnSetSystemMode(This,sysMode)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE IVidAdviseSink4_OnSetSystemMode_Proxy( 
    IVidAdviseSink4 __RPC_FAR * This,
    /* [in] */ DWORD sysMode);


void __RPC_STUB IVidAdviseSink4_OnSetSystemMode_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IVidAdviseSink4_INTERFACE_DEFINED__ */


/****************************************
 * Generated header for interface: __MIDL_itf_simplevid_0218
 * at Tue Nov 23 05:28:34 1999
 * using MIDL 3.01.75
 ****************************************/
/* [local] */ 


#define OBJREF_SIMPLE_VIDEO(n) OBJREF_TRINITY_ADDON(n,Play.SimpleVideo)
#define OBJREF_SIMPLE_VIDEO_ADDON(n,m) OBJREF_SIMPLE_VIDEO(n) L"!" L#m


extern RPC_IF_HANDLE __MIDL_itf_simplevid_0218_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_simplevid_0218_v0_0_s_ifspec;

#ifndef __IVidSimpleVideo_INTERFACE_DEFINED__
#define __IVidSimpleVideo_INTERFACE_DEFINED__

/****************************************
 * Generated header for interface: IVidSimpleVideo
 * at Tue Nov 23 05:28:34 1999
 * using MIDL 3.01.75
 ****************************************/
/* [unique][uuid][object][local] */ 


typedef /* [public] */ 
enum __MIDL_IVidSimpleVideo_0001
    {	LOTakeResources	= 1,
	LOGfxLayer0	= 2,
	LOGfxLayer1	= 4,
	LOGfxLayer2	= 8
    }	EVidLoadOptions;


EXTERN_C const IID IID_IVidSimpleVideo;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    interface DECLSPEC_UUID("8335e42d-ab3b-11ce-8468-0000b468276b")
    IVidSimpleVideo : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE QueryInternalInterface( 
            /* [in] */ REFIID riid,
            /* [in] */ DWORD index,
            /* [out] */ void __RPC_FAR *__RPC_FAR *ppvObj) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE EnumVideoSources( 
            /* [out] */ IEnumUnknown __RPC_FAR *__RPC_FAR *ppEnum) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Advise( 
            /* [in] */ IVidAdviseSink2 __RPC_FAR *pAdv) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE UnAdvise( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE LoadEffect( 
            /* [in] */ ITrnEffectFile __RPC_FAR *pTfxFile,
            /* [in] */ DWORD dwLoadOptions,
            /* [out] */ DWORD __RPC_FAR *pObjectId,
            /* [in] */ IVidAsyncAdvise __RPC_FAR *pAdvise) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE UnloadEffect( 
            /* [in] */ DWORD objectId) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetEffectInstance( 
            /* [in] */ DWORD objectId,
            /* [out] */ IVidEffect __RPC_FAR *__RPC_FAR *ppEffect) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE CreateViewEffect( 
            DWORD numViews,
            DWORD numViewports,
            DWORD numBitmaps,
            DWORD sizeBitmaps,
            BOOL takeNeededResources,
            IVidEffect __RPC_FAR *__RPC_FAR *ppNewEffect) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE CreateClipSource( 
            /* [in] */ IUnknown __RPC_FAR *pClip,
            /* [out] */ EVidSource __RPC_FAR *pNewSourceId) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE DeleteClipSource( 
            /* [in] */ EVidSource whichSource) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE CreateFramestoreSource( 
            /* [out] */ EVidSource __RPC_FAR *pNewSourceId,
            /* [out] */ IVidFramestoreSource __RPC_FAR *__RPC_FAR *ppNewSource) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE DeleteFramestoreSource( 
            /* [in] */ EVidSource whichSource) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SelectBusSource( 
            /* [in] */ STrnTimeType __RPC_FAR *pTime,
            /* [in] */ EVidBus whichBus,
            /* [in] */ EVidSource whichSource) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE CutBusses( 
            /* [in] */ STrnTimeType __RPC_FAR *pTime,
            /* [in] */ EVidBus whichBus1,
            /* [in] */ EVidBus whichBus2) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE QueryBusSource( 
            /* [in] */ EVidBus whichBus,
            /* [out] */ EVidSource __RPC_FAR *pWhichSource) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetPreviewSource( 
            /* [in] */ STrnTimeType __RPC_FAR *pTime,
            /* [in] */ EVidBus whichBus) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetMixerMode( 
            /* [in] */ STrnTimeType __RPC_FAR *pTime,
            /* [in] */ DWORD whichMode) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE QueryMixerMode( 
            /* [out] */ EVidMixerMode __RPC_FAR *pMode) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE LoadKeyerTable( 
            /* [in] */ unsigned int tableIdx,
            /* [in] */ void __RPC_FAR *pTable,
            /* [in] */ DWORD dwTableSize) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SelectKeyerTable( 
            /* [in] */ STrnTimeType __RPC_FAR *pTime,
            /* [in] */ unsigned int index) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE UnAdvise2( 
            /* [in] */ IVidAdviseSink2 __RPC_FAR *pAdv) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IVidSimpleVideoVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            IVidSimpleVideo __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            IVidSimpleVideo __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            IVidSimpleVideo __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInternalInterface )( 
            IVidSimpleVideo __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [in] */ DWORD index,
            /* [out] */ void __RPC_FAR *__RPC_FAR *ppvObj);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *EnumVideoSources )( 
            IVidSimpleVideo __RPC_FAR * This,
            /* [out] */ IEnumUnknown __RPC_FAR *__RPC_FAR *ppEnum);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Advise )( 
            IVidSimpleVideo __RPC_FAR * This,
            /* [in] */ IVidAdviseSink2 __RPC_FAR *pAdv);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *UnAdvise )( 
            IVidSimpleVideo __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *LoadEffect )( 
            IVidSimpleVideo __RPC_FAR * This,
            /* [in] */ ITrnEffectFile __RPC_FAR *pTfxFile,
            /* [in] */ DWORD dwLoadOptions,
            /* [out] */ DWORD __RPC_FAR *pObjectId,
            /* [in] */ IVidAsyncAdvise __RPC_FAR *pAdvise);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *UnloadEffect )( 
            IVidSimpleVideo __RPC_FAR * This,
            /* [in] */ DWORD objectId);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetEffectInstance )( 
            IVidSimpleVideo __RPC_FAR * This,
            /* [in] */ DWORD objectId,
            /* [out] */ IVidEffect __RPC_FAR *__RPC_FAR *ppEffect);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *CreateViewEffect )( 
            IVidSimpleVideo __RPC_FAR * This,
            DWORD numViews,
            DWORD numViewports,
            DWORD numBitmaps,
            DWORD sizeBitmaps,
            BOOL takeNeededResources,
            IVidEffect __RPC_FAR *__RPC_FAR *ppNewEffect);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *CreateClipSource )( 
            IVidSimpleVideo __RPC_FAR * This,
            /* [in] */ IUnknown __RPC_FAR *pClip,
            /* [out] */ EVidSource __RPC_FAR *pNewSourceId);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *DeleteClipSource )( 
            IVidSimpleVideo __RPC_FAR * This,
            /* [in] */ EVidSource whichSource);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *CreateFramestoreSource )( 
            IVidSimpleVideo __RPC_FAR * This,
            /* [out] */ EVidSource __RPC_FAR *pNewSourceId,
            /* [out] */ IVidFramestoreSource __RPC_FAR *__RPC_FAR *ppNewSource);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *DeleteFramestoreSource )( 
            IVidSimpleVideo __RPC_FAR * This,
            /* [in] */ EVidSource whichSource);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SelectBusSource )( 
            IVidSimpleVideo __RPC_FAR * This,
            /* [in] */ STrnTimeType __RPC_FAR *pTime,
            /* [in] */ EVidBus whichBus,
            /* [in] */ EVidSource whichSource);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *CutBusses )( 
            IVidSimpleVideo __RPC_FAR * This,
            /* [in] */ STrnTimeType __RPC_FAR *pTime,
            /* [in] */ EVidBus whichBus1,
            /* [in] */ EVidBus whichBus2);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryBusSource )( 
            IVidSimpleVideo __RPC_FAR * This,
            /* [in] */ EVidBus whichBus,
            /* [out] */ EVidSource __RPC_FAR *pWhichSource);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetPreviewSource )( 
            IVidSimpleVideo __RPC_FAR * This,
            /* [in] */ STrnTimeType __RPC_FAR *pTime,
            /* [in] */ EVidBus whichBus);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetMixerMode )( 
            IVidSimpleVideo __RPC_FAR * This,
            /* [in] */ STrnTimeType __RPC_FAR *pTime,
            /* [in] */ DWORD whichMode);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryMixerMode )( 
            IVidSimpleVideo __RPC_FAR * This,
            /* [out] */ EVidMixerMode __RPC_FAR *pMode);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *LoadKeyerTable )( 
            IVidSimpleVideo __RPC_FAR * This,
            /* [in] */ unsigned int tableIdx,
            /* [in] */ void __RPC_FAR *pTable,
            /* [in] */ DWORD dwTableSize);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SelectKeyerTable )( 
            IVidSimpleVideo __RPC_FAR * This,
            /* [in] */ STrnTimeType __RPC_FAR *pTime,
            /* [in] */ unsigned int index);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *UnAdvise2 )( 
            IVidSimpleVideo __RPC_FAR * This,
            /* [in] */ IVidAdviseSink2 __RPC_FAR *pAdv);
        
        END_INTERFACE
    } IVidSimpleVideoVtbl;

    interface IVidSimpleVideo
    {
        CONST_VTBL struct IVidSimpleVideoVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IVidSimpleVideo_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IVidSimpleVideo_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IVidSimpleVideo_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IVidSimpleVideo_QueryInternalInterface(This,riid,index,ppvObj)	\
    (This)->lpVtbl -> QueryInternalInterface(This,riid,index,ppvObj)

#define IVidSimpleVideo_EnumVideoSources(This,ppEnum)	\
    (This)->lpVtbl -> EnumVideoSources(This,ppEnum)

#define IVidSimpleVideo_Advise(This,pAdv)	\
    (This)->lpVtbl -> Advise(This,pAdv)

#define IVidSimpleVideo_UnAdvise(This)	\
    (This)->lpVtbl -> UnAdvise(This)

#define IVidSimpleVideo_LoadEffect(This,pTfxFile,dwLoadOptions,pObjectId,pAdvise)	\
    (This)->lpVtbl -> LoadEffect(This,pTfxFile,dwLoadOptions,pObjectId,pAdvise)

#define IVidSimpleVideo_UnloadEffect(This,objectId)	\
    (This)->lpVtbl -> UnloadEffect(This,objectId)

#define IVidSimpleVideo_GetEffectInstance(This,objectId,ppEffect)	\
    (This)->lpVtbl -> GetEffectInstance(This,objectId,ppEffect)

#define IVidSimpleVideo_CreateViewEffect(This,numViews,numViewports,numBitmaps,sizeBitmaps,takeNeededResources,ppNewEffect)	\
    (This)->lpVtbl -> CreateViewEffect(This,numViews,numViewports,numBitmaps,sizeBitmaps,takeNeededResources,ppNewEffect)

#define IVidSimpleVideo_CreateClipSource(This,pClip,pNewSourceId)	\
    (This)->lpVtbl -> CreateClipSource(This,pClip,pNewSourceId)

#define IVidSimpleVideo_DeleteClipSource(This,whichSource)	\
    (This)->lpVtbl -> DeleteClipSource(This,whichSource)

#define IVidSimpleVideo_CreateFramestoreSource(This,pNewSourceId,ppNewSource)	\
    (This)->lpVtbl -> CreateFramestoreSource(This,pNewSourceId,ppNewSource)

#define IVidSimpleVideo_DeleteFramestoreSource(This,whichSource)	\
    (This)->lpVtbl -> DeleteFramestoreSource(This,whichSource)

#define IVidSimpleVideo_SelectBusSource(This,pTime,whichBus,whichSource)	\
    (This)->lpVtbl -> SelectBusSource(This,pTime,whichBus,whichSource)

#define IVidSimpleVideo_CutBusses(This,pTime,whichBus1,whichBus2)	\
    (This)->lpVtbl -> CutBusses(This,pTime,whichBus1,whichBus2)

#define IVidSimpleVideo_QueryBusSource(This,whichBus,pWhichSource)	\
    (This)->lpVtbl -> QueryBusSource(This,whichBus,pWhichSource)

#define IVidSimpleVideo_SetPreviewSource(This,pTime,whichBus)	\
    (This)->lpVtbl -> SetPreviewSource(This,pTime,whichBus)

#define IVidSimpleVideo_SetMixerMode(This,pTime,whichMode)	\
    (This)->lpVtbl -> SetMixerMode(This,pTime,whichMode)

#define IVidSimpleVideo_QueryMixerMode(This,pMode)	\
    (This)->lpVtbl -> QueryMixerMode(This,pMode)

#define IVidSimpleVideo_LoadKeyerTable(This,tableIdx,pTable,dwTableSize)	\
    (This)->lpVtbl -> LoadKeyerTable(This,tableIdx,pTable,dwTableSize)

#define IVidSimpleVideo_SelectKeyerTable(This,pTime,index)	\
    (This)->lpVtbl -> SelectKeyerTable(This,pTime,index)

#define IVidSimpleVideo_UnAdvise2(This,pAdv)	\
    (This)->lpVtbl -> UnAdvise2(This,pAdv)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE IVidSimpleVideo_QueryInternalInterface_Proxy( 
    IVidSimpleVideo __RPC_FAR * This,
    /* [in] */ REFIID riid,
    /* [in] */ DWORD index,
    /* [out] */ void __RPC_FAR *__RPC_FAR *ppvObj);


void __RPC_STUB IVidSimpleVideo_QueryInternalInterface_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVidSimpleVideo_EnumVideoSources_Proxy( 
    IVidSimpleVideo __RPC_FAR * This,
    /* [out] */ IEnumUnknown __RPC_FAR *__RPC_FAR *ppEnum);


void __RPC_STUB IVidSimpleVideo_EnumVideoSources_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVidSimpleVideo_Advise_Proxy( 
    IVidSimpleVideo __RPC_FAR * This,
    /* [in] */ IVidAdviseSink2 __RPC_FAR *pAdv);


void __RPC_STUB IVidSimpleVideo_Advise_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVidSimpleVideo_UnAdvise_Proxy( 
    IVidSimpleVideo __RPC_FAR * This);


void __RPC_STUB IVidSimpleVideo_UnAdvise_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVidSimpleVideo_LoadEffect_Proxy( 
    IVidSimpleVideo __RPC_FAR * This,
    /* [in] */ ITrnEffectFile __RPC_FAR *pTfxFile,
    /* [in] */ DWORD dwLoadOptions,
    /* [out] */ DWORD __RPC_FAR *pObjectId,
    /* [in] */ IVidAsyncAdvise __RPC_FAR *pAdvise);


void __RPC_STUB IVidSimpleVideo_LoadEffect_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVidSimpleVideo_UnloadEffect_Proxy( 
    IVidSimpleVideo __RPC_FAR * This,
    /* [in] */ DWORD objectId);


void __RPC_STUB IVidSimpleVideo_UnloadEffect_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVidSimpleVideo_GetEffectInstance_Proxy( 
    IVidSimpleVideo __RPC_FAR * This,
    /* [in] */ DWORD objectId,
    /* [out] */ IVidEffect __RPC_FAR *__RPC_FAR *ppEffect);


void __RPC_STUB IVidSimpleVideo_GetEffectInstance_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVidSimpleVideo_CreateViewEffect_Proxy( 
    IVidSimpleVideo __RPC_FAR * This,
    DWORD numViews,
    DWORD numViewports,
    DWORD numBitmaps,
    DWORD sizeBitmaps,
    BOOL takeNeededResources,
    IVidEffect __RPC_FAR *__RPC_FAR *ppNewEffect);


void __RPC_STUB IVidSimpleVideo_CreateViewEffect_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVidSimpleVideo_CreateClipSource_Proxy( 
    IVidSimpleVideo __RPC_FAR * This,
    /* [in] */ IUnknown __RPC_FAR *pClip,
    /* [out] */ EVidSource __RPC_FAR *pNewSourceId);


void __RPC_STUB IVidSimpleVideo_CreateClipSource_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVidSimpleVideo_DeleteClipSource_Proxy( 
    IVidSimpleVideo __RPC_FAR * This,
    /* [in] */ EVidSource whichSource);


void __RPC_STUB IVidSimpleVideo_DeleteClipSource_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVidSimpleVideo_CreateFramestoreSource_Proxy( 
    IVidSimpleVideo __RPC_FAR * This,
    /* [out] */ EVidSource __RPC_FAR *pNewSourceId,
    /* [out] */ IVidFramestoreSource __RPC_FAR *__RPC_FAR *ppNewSource);


void __RPC_STUB IVidSimpleVideo_CreateFramestoreSource_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVidSimpleVideo_DeleteFramestoreSource_Proxy( 
    IVidSimpleVideo __RPC_FAR * This,
    /* [in] */ EVidSource whichSource);


void __RPC_STUB IVidSimpleVideo_DeleteFramestoreSource_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVidSimpleVideo_SelectBusSource_Proxy( 
    IVidSimpleVideo __RPC_FAR * This,
    /* [in] */ STrnTimeType __RPC_FAR *pTime,
    /* [in] */ EVidBus whichBus,
    /* [in] */ EVidSource whichSource);


void __RPC_STUB IVidSimpleVideo_SelectBusSource_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVidSimpleVideo_CutBusses_Proxy( 
    IVidSimpleVideo __RPC_FAR * This,
    /* [in] */ STrnTimeType __RPC_FAR *pTime,
    /* [in] */ EVidBus whichBus1,
    /* [in] */ EVidBus whichBus2);


void __RPC_STUB IVidSimpleVideo_CutBusses_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVidSimpleVideo_QueryBusSource_Proxy( 
    IVidSimpleVideo __RPC_FAR * This,
    /* [in] */ EVidBus whichBus,
    /* [out] */ EVidSource __RPC_FAR *pWhichSource);


void __RPC_STUB IVidSimpleVideo_QueryBusSource_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVidSimpleVideo_SetPreviewSource_Proxy( 
    IVidSimpleVideo __RPC_FAR * This,
    /* [in] */ STrnTimeType __RPC_FAR *pTime,
    /* [in] */ EVidBus whichBus);


void __RPC_STUB IVidSimpleVideo_SetPreviewSource_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVidSimpleVideo_SetMixerMode_Proxy( 
    IVidSimpleVideo __RPC_FAR * This,
    /* [in] */ STrnTimeType __RPC_FAR *pTime,
    /* [in] */ DWORD whichMode);


void __RPC_STUB IVidSimpleVideo_SetMixerMode_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVidSimpleVideo_QueryMixerMode_Proxy( 
    IVidSimpleVideo __RPC_FAR * This,
    /* [out] */ EVidMixerMode __RPC_FAR *pMode);


void __RPC_STUB IVidSimpleVideo_QueryMixerMode_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVidSimpleVideo_LoadKeyerTable_Proxy( 
    IVidSimpleVideo __RPC_FAR * This,
    /* [in] */ unsigned int tableIdx,
    /* [in] */ void __RPC_FAR *pTable,
    /* [in] */ DWORD dwTableSize);


void __RPC_STUB IVidSimpleVideo_LoadKeyerTable_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVidSimpleVideo_SelectKeyerTable_Proxy( 
    IVidSimpleVideo __RPC_FAR * This,
    /* [in] */ STrnTimeType __RPC_FAR *pTime,
    /* [in] */ unsigned int index);


void __RPC_STUB IVidSimpleVideo_SelectKeyerTable_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVidSimpleVideo_UnAdvise2_Proxy( 
    IVidSimpleVideo __RPC_FAR * This,
    /* [in] */ IVidAdviseSink2 __RPC_FAR *pAdv);


void __RPC_STUB IVidSimpleVideo_UnAdvise2_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IVidSimpleVideo_INTERFACE_DEFINED__ */


#ifndef __IVidSimpleVideo2_INTERFACE_DEFINED__
#define __IVidSimpleVideo2_INTERFACE_DEFINED__

/****************************************
 * Generated header for interface: IVidSimpleVideo2
 * at Tue Nov 23 05:28:34 1999
 * using MIDL 3.01.75
 ****************************************/
/* [unique][uuid][object][local] */ 


typedef 
enum tagEVidSystemFlags
    {	EVSFKeyOut	= 1
    }	EVidSystemFlags;


EXTERN_C const IID IID_IVidSimpleVideo2;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    interface DECLSPEC_UUID("8335e42f-ab3b-11ce-8468-0000b468276b")
    IVidSimpleVideo2 : public IVidSimpleVideo
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE QueryPreviewSource( 
            /* [out] */ EVidBus __RPC_FAR *pWhichBus) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetSystemMode( 
            STrnTimeType __RPC_FAR *pTime,
            DWORD sysMode,
            DWORD modesMask) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetSystemMode( 
            DWORD __RPC_FAR *pSysMode) = 0;
        
        virtual EVidSource STDMETHODCALLTYPE ClassifySource( 
            EVidSource whichSource) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IVidSimpleVideo2Vtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            IVidSimpleVideo2 __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            IVidSimpleVideo2 __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            IVidSimpleVideo2 __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInternalInterface )( 
            IVidSimpleVideo2 __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [in] */ DWORD index,
            /* [out] */ void __RPC_FAR *__RPC_FAR *ppvObj);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *EnumVideoSources )( 
            IVidSimpleVideo2 __RPC_FAR * This,
            /* [out] */ IEnumUnknown __RPC_FAR *__RPC_FAR *ppEnum);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Advise )( 
            IVidSimpleVideo2 __RPC_FAR * This,
            /* [in] */ IVidAdviseSink2 __RPC_FAR *pAdv);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *UnAdvise )( 
            IVidSimpleVideo2 __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *LoadEffect )( 
            IVidSimpleVideo2 __RPC_FAR * This,
            /* [in] */ ITrnEffectFile __RPC_FAR *pTfxFile,
            /* [in] */ DWORD dwLoadOptions,
            /* [out] */ DWORD __RPC_FAR *pObjectId,
            /* [in] */ IVidAsyncAdvise __RPC_FAR *pAdvise);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *UnloadEffect )( 
            IVidSimpleVideo2 __RPC_FAR * This,
            /* [in] */ DWORD objectId);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetEffectInstance )( 
            IVidSimpleVideo2 __RPC_FAR * This,
            /* [in] */ DWORD objectId,
            /* [out] */ IVidEffect __RPC_FAR *__RPC_FAR *ppEffect);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *CreateViewEffect )( 
            IVidSimpleVideo2 __RPC_FAR * This,
            DWORD numViews,
            DWORD numViewports,
            DWORD numBitmaps,
            DWORD sizeBitmaps,
            BOOL takeNeededResources,
            IVidEffect __RPC_FAR *__RPC_FAR *ppNewEffect);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *CreateClipSource )( 
            IVidSimpleVideo2 __RPC_FAR * This,
            /* [in] */ IUnknown __RPC_FAR *pClip,
            /* [out] */ EVidSource __RPC_FAR *pNewSourceId);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *DeleteClipSource )( 
            IVidSimpleVideo2 __RPC_FAR * This,
            /* [in] */ EVidSource whichSource);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *CreateFramestoreSource )( 
            IVidSimpleVideo2 __RPC_FAR * This,
            /* [out] */ EVidSource __RPC_FAR *pNewSourceId,
            /* [out] */ IVidFramestoreSource __RPC_FAR *__RPC_FAR *ppNewSource);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *DeleteFramestoreSource )( 
            IVidSimpleVideo2 __RPC_FAR * This,
            /* [in] */ EVidSource whichSource);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SelectBusSource )( 
            IVidSimpleVideo2 __RPC_FAR * This,
            /* [in] */ STrnTimeType __RPC_FAR *pTime,
            /* [in] */ EVidBus whichBus,
            /* [in] */ EVidSource whichSource);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *CutBusses )( 
            IVidSimpleVideo2 __RPC_FAR * This,
            /* [in] */ STrnTimeType __RPC_FAR *pTime,
            /* [in] */ EVidBus whichBus1,
            /* [in] */ EVidBus whichBus2);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryBusSource )( 
            IVidSimpleVideo2 __RPC_FAR * This,
            /* [in] */ EVidBus whichBus,
            /* [out] */ EVidSource __RPC_FAR *pWhichSource);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetPreviewSource )( 
            IVidSimpleVideo2 __RPC_FAR * This,
            /* [in] */ STrnTimeType __RPC_FAR *pTime,
            /* [in] */ EVidBus whichBus);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetMixerMode )( 
            IVidSimpleVideo2 __RPC_FAR * This,
            /* [in] */ STrnTimeType __RPC_FAR *pTime,
            /* [in] */ DWORD whichMode);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryMixerMode )( 
            IVidSimpleVideo2 __RPC_FAR * This,
            /* [out] */ EVidMixerMode __RPC_FAR *pMode);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *LoadKeyerTable )( 
            IVidSimpleVideo2 __RPC_FAR * This,
            /* [in] */ unsigned int tableIdx,
            /* [in] */ void __RPC_FAR *pTable,
            /* [in] */ DWORD dwTableSize);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SelectKeyerTable )( 
            IVidSimpleVideo2 __RPC_FAR * This,
            /* [in] */ STrnTimeType __RPC_FAR *pTime,
            /* [in] */ unsigned int index);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *UnAdvise2 )( 
            IVidSimpleVideo2 __RPC_FAR * This,
            /* [in] */ IVidAdviseSink2 __RPC_FAR *pAdv);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryPreviewSource )( 
            IVidSimpleVideo2 __RPC_FAR * This,
            /* [out] */ EVidBus __RPC_FAR *pWhichBus);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetSystemMode )( 
            IVidSimpleVideo2 __RPC_FAR * This,
            STrnTimeType __RPC_FAR *pTime,
            DWORD sysMode,
            DWORD modesMask);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetSystemMode )( 
            IVidSimpleVideo2 __RPC_FAR * This,
            DWORD __RPC_FAR *pSysMode);
        
        EVidSource ( STDMETHODCALLTYPE __RPC_FAR *ClassifySource )( 
            IVidSimpleVideo2 __RPC_FAR * This,
            EVidSource whichSource);
        
        END_INTERFACE
    } IVidSimpleVideo2Vtbl;

    interface IVidSimpleVideo2
    {
        CONST_VTBL struct IVidSimpleVideo2Vtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IVidSimpleVideo2_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IVidSimpleVideo2_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IVidSimpleVideo2_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IVidSimpleVideo2_QueryInternalInterface(This,riid,index,ppvObj)	\
    (This)->lpVtbl -> QueryInternalInterface(This,riid,index,ppvObj)

#define IVidSimpleVideo2_EnumVideoSources(This,ppEnum)	\
    (This)->lpVtbl -> EnumVideoSources(This,ppEnum)

#define IVidSimpleVideo2_Advise(This,pAdv)	\
    (This)->lpVtbl -> Advise(This,pAdv)

#define IVidSimpleVideo2_UnAdvise(This)	\
    (This)->lpVtbl -> UnAdvise(This)

#define IVidSimpleVideo2_LoadEffect(This,pTfxFile,dwLoadOptions,pObjectId,pAdvise)	\
    (This)->lpVtbl -> LoadEffect(This,pTfxFile,dwLoadOptions,pObjectId,pAdvise)

#define IVidSimpleVideo2_UnloadEffect(This,objectId)	\
    (This)->lpVtbl -> UnloadEffect(This,objectId)

#define IVidSimpleVideo2_GetEffectInstance(This,objectId,ppEffect)	\
    (This)->lpVtbl -> GetEffectInstance(This,objectId,ppEffect)

#define IVidSimpleVideo2_CreateViewEffect(This,numViews,numViewports,numBitmaps,sizeBitmaps,takeNeededResources,ppNewEffect)	\
    (This)->lpVtbl -> CreateViewEffect(This,numViews,numViewports,numBitmaps,sizeBitmaps,takeNeededResources,ppNewEffect)

#define IVidSimpleVideo2_CreateClipSource(This,pClip,pNewSourceId)	\
    (This)->lpVtbl -> CreateClipSource(This,pClip,pNewSourceId)

#define IVidSimpleVideo2_DeleteClipSource(This,whichSource)	\
    (This)->lpVtbl -> DeleteClipSource(This,whichSource)

#define IVidSimpleVideo2_CreateFramestoreSource(This,pNewSourceId,ppNewSource)	\
    (This)->lpVtbl -> CreateFramestoreSource(This,pNewSourceId,ppNewSource)

#define IVidSimpleVideo2_DeleteFramestoreSource(This,whichSource)	\
    (This)->lpVtbl -> DeleteFramestoreSource(This,whichSource)

#define IVidSimpleVideo2_SelectBusSource(This,pTime,whichBus,whichSource)	\
    (This)->lpVtbl -> SelectBusSource(This,pTime,whichBus,whichSource)

#define IVidSimpleVideo2_CutBusses(This,pTime,whichBus1,whichBus2)	\
    (This)->lpVtbl -> CutBusses(This,pTime,whichBus1,whichBus2)

#define IVidSimpleVideo2_QueryBusSource(This,whichBus,pWhichSource)	\
    (This)->lpVtbl -> QueryBusSource(This,whichBus,pWhichSource)

#define IVidSimpleVideo2_SetPreviewSource(This,pTime,whichBus)	\
    (This)->lpVtbl -> SetPreviewSource(This,pTime,whichBus)

#define IVidSimpleVideo2_SetMixerMode(This,pTime,whichMode)	\
    (This)->lpVtbl -> SetMixerMode(This,pTime,whichMode)

#define IVidSimpleVideo2_QueryMixerMode(This,pMode)	\
    (This)->lpVtbl -> QueryMixerMode(This,pMode)

#define IVidSimpleVideo2_LoadKeyerTable(This,tableIdx,pTable,dwTableSize)	\
    (This)->lpVtbl -> LoadKeyerTable(This,tableIdx,pTable,dwTableSize)

#define IVidSimpleVideo2_SelectKeyerTable(This,pTime,index)	\
    (This)->lpVtbl -> SelectKeyerTable(This,pTime,index)

#define IVidSimpleVideo2_UnAdvise2(This,pAdv)	\
    (This)->lpVtbl -> UnAdvise2(This,pAdv)


#define IVidSimpleVideo2_QueryPreviewSource(This,pWhichBus)	\
    (This)->lpVtbl -> QueryPreviewSource(This,pWhichBus)

#define IVidSimpleVideo2_SetSystemMode(This,pTime,sysMode,modesMask)	\
    (This)->lpVtbl -> SetSystemMode(This,pTime,sysMode,modesMask)

#define IVidSimpleVideo2_GetSystemMode(This,pSysMode)	\
    (This)->lpVtbl -> GetSystemMode(This,pSysMode)

#define IVidSimpleVideo2_ClassifySource(This,whichSource)	\
    (This)->lpVtbl -> ClassifySource(This,whichSource)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE IVidSimpleVideo2_QueryPreviewSource_Proxy( 
    IVidSimpleVideo2 __RPC_FAR * This,
    /* [out] */ EVidBus __RPC_FAR *pWhichBus);


void __RPC_STUB IVidSimpleVideo2_QueryPreviewSource_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVidSimpleVideo2_SetSystemMode_Proxy( 
    IVidSimpleVideo2 __RPC_FAR * This,
    STrnTimeType __RPC_FAR *pTime,
    DWORD sysMode,
    DWORD modesMask);


void __RPC_STUB IVidSimpleVideo2_SetSystemMode_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVidSimpleVideo2_GetSystemMode_Proxy( 
    IVidSimpleVideo2 __RPC_FAR * This,
    DWORD __RPC_FAR *pSysMode);


void __RPC_STUB IVidSimpleVideo2_GetSystemMode_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


EVidSource STDMETHODCALLTYPE IVidSimpleVideo2_ClassifySource_Proxy( 
    IVidSimpleVideo2 __RPC_FAR * This,
    EVidSource whichSource);


void __RPC_STUB IVidSimpleVideo2_ClassifySource_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IVidSimpleVideo2_INTERFACE_DEFINED__ */


#ifndef __IVidSimpleVideoAddOn_INTERFACE_DEFINED__
#define __IVidSimpleVideoAddOn_INTERFACE_DEFINED__

/****************************************
 * Generated header for interface: IVidSimpleVideoAddOn
 * at Tue Nov 23 05:28:34 1999
 * using MIDL 3.01.75
 ****************************************/
/* [unique][uuid][object][local] */ 



EXTERN_C const IID IID_IVidSimpleVideoAddOn;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    interface DECLSPEC_UUID("8335e40d-ab3b-11ce-8468-0000b468276b")
    IVidSimpleVideoAddOn : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE Connect( 
            ITrnConnection __RPC_FAR *pTC,
            ITrnVideoSystem __RPC_FAR *pVS,
            IVidSimpleVideo __RPC_FAR *pSV,
            ETrnVideoEncodingFormats fmt,
            DWORD listenSocket) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IVidSimpleVideoAddOnVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            IVidSimpleVideoAddOn __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            IVidSimpleVideoAddOn __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            IVidSimpleVideoAddOn __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Connect )( 
            IVidSimpleVideoAddOn __RPC_FAR * This,
            ITrnConnection __RPC_FAR *pTC,
            ITrnVideoSystem __RPC_FAR *pVS,
            IVidSimpleVideo __RPC_FAR *pSV,
            ETrnVideoEncodingFormats fmt,
            DWORD listenSocket);
        
        END_INTERFACE
    } IVidSimpleVideoAddOnVtbl;

    interface IVidSimpleVideoAddOn
    {
        CONST_VTBL struct IVidSimpleVideoAddOnVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IVidSimpleVideoAddOn_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IVidSimpleVideoAddOn_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IVidSimpleVideoAddOn_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IVidSimpleVideoAddOn_Connect(This,pTC,pVS,pSV,fmt,listenSocket)	\
    (This)->lpVtbl -> Connect(This,pTC,pVS,pSV,fmt,listenSocket)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE IVidSimpleVideoAddOn_Connect_Proxy( 
    IVidSimpleVideoAddOn __RPC_FAR * This,
    ITrnConnection __RPC_FAR *pTC,
    ITrnVideoSystem __RPC_FAR *pVS,
    IVidSimpleVideo __RPC_FAR *pSV,
    ETrnVideoEncodingFormats fmt,
    DWORD listenSocket);


void __RPC_STUB IVidSimpleVideoAddOn_Connect_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IVidSimpleVideoAddOn_INTERFACE_DEFINED__ */


#ifndef __ITrnPiconFactory_INTERFACE_DEFINED__
#define __ITrnPiconFactory_INTERFACE_DEFINED__

/****************************************
 * Generated header for interface: ITrnPiconFactory
 * at Tue Nov 23 05:28:34 1999
 * using MIDL 3.01.75
 ****************************************/
/* [uuid][unique][object][local] */ 



EXTERN_C const IID IID_ITrnPiconFactory;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    interface DECLSPEC_UUID("8335e496-ab3b-11ce-8468-0000b468276b")
    ITrnPiconFactory : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE Initialize( 
            IVidSimpleVideo __RPC_FAR *pSVid) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE UnInitialize( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE QueryNumFrameSets( 
            LONG __RPC_FAR *plNum) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE QuerySetDescription( 
            LONG lSet,
            LPSTR buffer,
            LONG cbBuffer) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE LoadStandardFrames( 
            STrnTimeType __RPC_FAR *pTime,
            LONG set) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE ClearPicon( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GrabPicon( 
            STrnTimeType __RPC_FAR *pTime,
            BOOL bSynchronous) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetPicon( 
            IGXIntBitmap __RPC_FAR *__RPC_FAR *ppBitmap) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct ITrnPiconFactoryVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            ITrnPiconFactory __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            ITrnPiconFactory __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            ITrnPiconFactory __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Initialize )( 
            ITrnPiconFactory __RPC_FAR * This,
            IVidSimpleVideo __RPC_FAR *pSVid);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *UnInitialize )( 
            ITrnPiconFactory __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryNumFrameSets )( 
            ITrnPiconFactory __RPC_FAR * This,
            LONG __RPC_FAR *plNum);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QuerySetDescription )( 
            ITrnPiconFactory __RPC_FAR * This,
            LONG lSet,
            LPSTR buffer,
            LONG cbBuffer);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *LoadStandardFrames )( 
            ITrnPiconFactory __RPC_FAR * This,
            STrnTimeType __RPC_FAR *pTime,
            LONG set);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *ClearPicon )( 
            ITrnPiconFactory __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GrabPicon )( 
            ITrnPiconFactory __RPC_FAR * This,
            STrnTimeType __RPC_FAR *pTime,
            BOOL bSynchronous);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetPicon )( 
            ITrnPiconFactory __RPC_FAR * This,
            IGXIntBitmap __RPC_FAR *__RPC_FAR *ppBitmap);
        
        END_INTERFACE
    } ITrnPiconFactoryVtbl;

    interface ITrnPiconFactory
    {
        CONST_VTBL struct ITrnPiconFactoryVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ITrnPiconFactory_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define ITrnPiconFactory_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define ITrnPiconFactory_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define ITrnPiconFactory_Initialize(This,pSVid)	\
    (This)->lpVtbl -> Initialize(This,pSVid)

#define ITrnPiconFactory_UnInitialize(This)	\
    (This)->lpVtbl -> UnInitialize(This)

#define ITrnPiconFactory_QueryNumFrameSets(This,plNum)	\
    (This)->lpVtbl -> QueryNumFrameSets(This,plNum)

#define ITrnPiconFactory_QuerySetDescription(This,lSet,buffer,cbBuffer)	\
    (This)->lpVtbl -> QuerySetDescription(This,lSet,buffer,cbBuffer)

#define ITrnPiconFactory_LoadStandardFrames(This,pTime,set)	\
    (This)->lpVtbl -> LoadStandardFrames(This,pTime,set)

#define ITrnPiconFactory_ClearPicon(This)	\
    (This)->lpVtbl -> ClearPicon(This)

#define ITrnPiconFactory_GrabPicon(This,pTime,bSynchronous)	\
    (This)->lpVtbl -> GrabPicon(This,pTime,bSynchronous)

#define ITrnPiconFactory_GetPicon(This,ppBitmap)	\
    (This)->lpVtbl -> GetPicon(This,ppBitmap)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE ITrnPiconFactory_Initialize_Proxy( 
    ITrnPiconFactory __RPC_FAR * This,
    IVidSimpleVideo __RPC_FAR *pSVid);


void __RPC_STUB ITrnPiconFactory_Initialize_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE ITrnPiconFactory_UnInitialize_Proxy( 
    ITrnPiconFactory __RPC_FAR * This);


void __RPC_STUB ITrnPiconFactory_UnInitialize_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE ITrnPiconFactory_QueryNumFrameSets_Proxy( 
    ITrnPiconFactory __RPC_FAR * This,
    LONG __RPC_FAR *plNum);


void __RPC_STUB ITrnPiconFactory_QueryNumFrameSets_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE ITrnPiconFactory_QuerySetDescription_Proxy( 
    ITrnPiconFactory __RPC_FAR * This,
    LONG lSet,
    LPSTR buffer,
    LONG cbBuffer);


void __RPC_STUB ITrnPiconFactory_QuerySetDescription_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE ITrnPiconFactory_LoadStandardFrames_Proxy( 
    ITrnPiconFactory __RPC_FAR * This,
    STrnTimeType __RPC_FAR *pTime,
    LONG set);


void __RPC_STUB ITrnPiconFactory_LoadStandardFrames_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE ITrnPiconFactory_ClearPicon_Proxy( 
    ITrnPiconFactory __RPC_FAR * This);


void __RPC_STUB ITrnPiconFactory_ClearPicon_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE ITrnPiconFactory_GrabPicon_Proxy( 
    ITrnPiconFactory __RPC_FAR * This,
    STrnTimeType __RPC_FAR *pTime,
    BOOL bSynchronous);


void __RPC_STUB ITrnPiconFactory_GrabPicon_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE ITrnPiconFactory_GetPicon_Proxy( 
    ITrnPiconFactory __RPC_FAR * This,
    IGXIntBitmap __RPC_FAR *__RPC_FAR *ppBitmap);


void __RPC_STUB ITrnPiconFactory_GetPicon_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __ITrnPiconFactory_INTERFACE_DEFINED__ */


/* Additional Prototypes for ALL interfaces */

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif
