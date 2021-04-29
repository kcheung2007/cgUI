/* this ALWAYS GENERATED file contains the definitions for the interfaces */


/* File created by MIDL compiler version 3.01.75 */
/* at Tue Nov 23 05:28:30 1999
 */
/* Compiler settings for EffectCompiler.idl:
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

#ifndef __EffectCompiler_h__
#define __EffectCompiler_h__

#ifdef __cplusplus
extern "C"{
#endif 

/* Forward Declarations */ 

#ifndef __IEffectCompiler_FWD_DEFINED__
#define __IEffectCompiler_FWD_DEFINED__
typedef interface IEffectCompiler IEffectCompiler;
#endif 	/* __IEffectCompiler_FWD_DEFINED__ */


/* header files for imported files */
#include "unknwn.h"

void __RPC_FAR * __RPC_USER MIDL_user_allocate(size_t);
void __RPC_USER MIDL_user_free( void __RPC_FAR * ); 

/****************************************
 * Generated header for interface: __MIDL_itf_EffectCompiler_0000
 * at Tue Nov 23 05:28:30 1999
 * using MIDL 3.01.75
 ****************************************/
/* [local] */ 


#define NOMINMAX
#include "CompilerInfo.h"
/*
typedef struct  _ProcessData
    {
    unsigned char __RPC_FAR *mainAlpha;
    unsigned char __RPC_FAR *graphicAlpha;
    unsigned char __RPC_FAR *warpAlphaProgram;
    unsigned char __RPC_FAR *warpAlphaPreview;
    unsigned char __RPC_FAR *warpAlphaAux1;
    unsigned char RGBHasAlpha;
    unsigned char __RPC_FAR *rgbBuffer;
    double __RPC_FAR *uBufferProgram;
    double __RPC_FAR *uBufferPreview;
    double __RPC_FAR *uBufferAux1;
    double __RPC_FAR *vBufferProgram;
    double __RPC_FAR *vBufferPreview;
    double __RPC_FAR *vBufferAux1;
    }	ProcessData;

typedef struct _ProcessData __RPC_FAR *ProcessDataPtr;

typedef struct  _CompileInfo
    {
    long VerInfo;
    long videomode;
    unsigned char filename[ 260 ];
    unsigned char playliststorage[ 260 ];
    unsigned long fields;
    unsigned long rows;
    unsigned long columns;
    unsigned char istransition;
    unsigned char chromashadowactive;
    unsigned char chromaoffatend;
    unsigned long warpsourcenum1;
    unsigned long warpsourcenum2;
    unsigned long warpsourcenum3;
    double uscale;
    double vscale;
    double uoffset;
    double voffset;
    double precision;
    short iconw;
    short iconh;
    short icond;
    long effectcompiletype;
    unsigned short sourceindex;
    unsigned char emitWEstream1;
    unsigned char emitFEstream1;
    unsigned char emitWEstream2;
    unsigned char emitFEstream2;
    unsigned char emitWEstream3;
    unsigned char emitFEstream3;
    unsigned char emitGraphics;
    unsigned char emitMainAlpha;
    unsigned char emitWarp;
    }	CompileInfo;

typedef struct _CompileInfo __RPC_FAR *CompileInfoPtr;

*/


extern RPC_IF_HANDLE __MIDL_itf_EffectCompiler_0000_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_EffectCompiler_0000_v0_0_s_ifspec;

#ifndef __IEffectCompiler_INTERFACE_DEFINED__
#define __IEffectCompiler_INTERFACE_DEFINED__

/****************************************
 * Generated header for interface: IEffectCompiler
 * at Tue Nov 23 05:28:30 1999
 * using MIDL 3.01.75
 ****************************************/
/* [uuid][object] */ 



EXTERN_C const IID IID_IEffectCompiler;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    interface DECLSPEC_UUID("26D7A080-eb96-11d2-B1A5-00A076A0999C")
    IEffectCompiler : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE InitializeEffect( 
            /* [in] */ CompileInfoPtr data) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE ProcessField( 
            /* [in] */ ProcessDataPtr pd) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE EffectDone( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE AbortEffect( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE EmitGraphics( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE EmitMainAlpha( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE EmitWarp( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetCurrentStreamLength( 
            int BoardID,
            int BoardIndex,
            int StreamIndex) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IEffectCompilerVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            IEffectCompiler __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            IEffectCompiler __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            IEffectCompiler __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *InitializeEffect )( 
            IEffectCompiler __RPC_FAR * This,
            /* [in] */ CompileInfoPtr data);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *ProcessField )( 
            IEffectCompiler __RPC_FAR * This,
            /* [in] */ ProcessDataPtr pd);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *EffectDone )( 
            IEffectCompiler __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *AbortEffect )( 
            IEffectCompiler __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *EmitGraphics )( 
            IEffectCompiler __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *EmitMainAlpha )( 
            IEffectCompiler __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *EmitWarp )( 
            IEffectCompiler __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetCurrentStreamLength )( 
            IEffectCompiler __RPC_FAR * This,
            int BoardID,
            int BoardIndex,
            int StreamIndex);
        
        END_INTERFACE
    } IEffectCompilerVtbl;

    interface IEffectCompiler
    {
        CONST_VTBL struct IEffectCompilerVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IEffectCompiler_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IEffectCompiler_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IEffectCompiler_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IEffectCompiler_InitializeEffect(This,data)	\
    (This)->lpVtbl -> InitializeEffect(This,data)

#define IEffectCompiler_ProcessField(This,pd)	\
    (This)->lpVtbl -> ProcessField(This,pd)

#define IEffectCompiler_EffectDone(This)	\
    (This)->lpVtbl -> EffectDone(This)

#define IEffectCompiler_AbortEffect(This)	\
    (This)->lpVtbl -> AbortEffect(This)

#define IEffectCompiler_EmitGraphics(This)	\
    (This)->lpVtbl -> EmitGraphics(This)

#define IEffectCompiler_EmitMainAlpha(This)	\
    (This)->lpVtbl -> EmitMainAlpha(This)

#define IEffectCompiler_EmitWarp(This)	\
    (This)->lpVtbl -> EmitWarp(This)

#define IEffectCompiler_GetCurrentStreamLength(This,BoardID,BoardIndex,StreamIndex)	\
    (This)->lpVtbl -> GetCurrentStreamLength(This,BoardID,BoardIndex,StreamIndex)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE IEffectCompiler_InitializeEffect_Proxy( 
    IEffectCompiler __RPC_FAR * This,
    /* [in] */ CompileInfoPtr data);


void __RPC_STUB IEffectCompiler_InitializeEffect_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IEffectCompiler_ProcessField_Proxy( 
    IEffectCompiler __RPC_FAR * This,
    /* [in] */ ProcessDataPtr pd);


void __RPC_STUB IEffectCompiler_ProcessField_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IEffectCompiler_EffectDone_Proxy( 
    IEffectCompiler __RPC_FAR * This);


void __RPC_STUB IEffectCompiler_EffectDone_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IEffectCompiler_AbortEffect_Proxy( 
    IEffectCompiler __RPC_FAR * This);


void __RPC_STUB IEffectCompiler_AbortEffect_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IEffectCompiler_EmitGraphics_Proxy( 
    IEffectCompiler __RPC_FAR * This);


void __RPC_STUB IEffectCompiler_EmitGraphics_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IEffectCompiler_EmitMainAlpha_Proxy( 
    IEffectCompiler __RPC_FAR * This);


void __RPC_STUB IEffectCompiler_EmitMainAlpha_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IEffectCompiler_EmitWarp_Proxy( 
    IEffectCompiler __RPC_FAR * This);


void __RPC_STUB IEffectCompiler_EmitWarp_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IEffectCompiler_GetCurrentStreamLength_Proxy( 
    IEffectCompiler __RPC_FAR * This,
    int BoardID,
    int BoardIndex,
    int StreamIndex);


void __RPC_STUB IEffectCompiler_GetCurrentStreamLength_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IEffectCompiler_INTERFACE_DEFINED__ */


/* Additional Prototypes for ALL interfaces */

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif
