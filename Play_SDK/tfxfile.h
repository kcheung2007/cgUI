/* this ALWAYS GENERATED file contains the definitions for the interfaces */


/* File created by MIDL compiler version 3.01.75 */
/* at Tue Nov 23 05:28:36 1999
 */
/* Compiler settings for tfxfile.idl:
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

#ifndef __tfxfile_h__
#define __tfxfile_h__

#ifdef __cplusplus
extern "C"{
#endif 

/* Forward Declarations */ 

#ifndef __ITrnEffectFile_FWD_DEFINED__
#define __ITrnEffectFile_FWD_DEFINED__
typedef interface ITrnEffectFile ITrnEffectFile;
#endif 	/* __ITrnEffectFile_FWD_DEFINED__ */


#ifndef __ITrnEffectInput_FWD_DEFINED__
#define __ITrnEffectInput_FWD_DEFINED__
typedef interface ITrnEffectInput ITrnEffectInput;
#endif 	/* __ITrnEffectInput_FWD_DEFINED__ */


#ifndef __ITrnEffectTransition_FWD_DEFINED__
#define __ITrnEffectTransition_FWD_DEFINED__
typedef interface ITrnEffectTransition ITrnEffectTransition;
#endif 	/* __ITrnEffectTransition_FWD_DEFINED__ */


#ifndef __ITrnEffectTransform_FWD_DEFINED__
#define __ITrnEffectTransform_FWD_DEFINED__
typedef interface ITrnEffectTransform ITrnEffectTransform;
#endif 	/* __ITrnEffectTransform_FWD_DEFINED__ */


#ifndef __ITrnEffectMixing_FWD_DEFINED__
#define __ITrnEffectMixing_FWD_DEFINED__
typedef interface ITrnEffectMixing ITrnEffectMixing;
#endif 	/* __ITrnEffectMixing_FWD_DEFINED__ */


#ifndef __ITrnEffectLayering_FWD_DEFINED__
#define __ITrnEffectLayering_FWD_DEFINED__
typedef interface ITrnEffectLayering ITrnEffectLayering;
#endif 	/* __ITrnEffectLayering_FWD_DEFINED__ */


#ifndef __ITrnEffectSoundEffect_FWD_DEFINED__
#define __ITrnEffectSoundEffect_FWD_DEFINED__
typedef interface ITrnEffectSoundEffect ITrnEffectSoundEffect;
#endif 	/* __ITrnEffectSoundEffect_FWD_DEFINED__ */


#ifndef __ITrnEffectEvent_FWD_DEFINED__
#define __ITrnEffectEvent_FWD_DEFINED__
typedef interface ITrnEffectEvent ITrnEffectEvent;
#endif 	/* __ITrnEffectEvent_FWD_DEFINED__ */


/* header files for imported files */
#include "wtypes.h"
#include "unknwn.h"
#include "objidl.h"
#include "autoct.h"
#include "trnity.h"

void __RPC_FAR * __RPC_USER MIDL_user_allocate(size_t);
void __RPC_USER MIDL_user_free( void __RPC_FAR * ); 

/****************************************
 * Generated header for interface: __MIDL_itf_tfxfile_0000
 * at Tue Nov 23 05:28:36 1999
 * using MIDL 3.01.75
 ****************************************/
/* [local] */ 


#define PLAY_3D_DVE_ID           0x00000005
#define PLAY_SWITCHER_ID         0x00000003
#define PLAY_COMPOSITE_INPUT_ID2 0x80000003
#define PLAY_COMPOSITE_INPUT_ID1 0x80000002
#define PLAY_SERIAL_D1_INPUT_ID  0x80000001
#define TFX_E_TOOMANYITEMS       0xE8030001
#define TFX_E_ITEMALREADYEXISTS  0xE8030002
#define TFX_E_ITEMNOTFOUND       0xE8030003
#define TFX_MAX_BUSSES           16
#define TFX_MAX_LAYERS           8










extern RPC_IF_HANDLE __MIDL_itf_tfxfile_0000_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_tfxfile_0000_v0_0_s_ifspec;

#ifndef __ITrnEffectFile_INTERFACE_DEFINED__
#define __ITrnEffectFile_INTERFACE_DEFINED__

/****************************************
 * Generated header for interface: ITrnEffectFile
 * at Tue Nov 23 05:28:36 1999
 * using MIDL 3.01.75
 ****************************************/
/* [unique][uuid][object][local] */ 


typedef 
enum tagETFXattributes
    {	TFXtransition	= 0x1,
	TFXchroma0	= 0x2,
	TFXchroma1	= 0x4,
	TFXchroma2	= 0x8,
	TFXchromaOff	= 0x10,
	TFXUSAlpha	= 0x20,
	TFXDSAlpha	= 0x40,
	TFXgraphics	= 0x80,
	TFXgallery	= 0x100,
	TFXPAL	= 0x200,
	TFXAnyRes	= 0x400,
	TFXNoReverse	= 0x800,
	TFXViewFx	= 0x1000,
	TFXchromaMask	= TFXchroma0 | TFXchroma1 | TFXchroma2,
	TFXchromaShift	= 1
    }	ETFXattributes;


EXTERN_C const IID IID_ITrnEffectFile;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    interface DECLSPEC_UUID("8335e5d3-ab3b-11ce-8468-0000b468276b")
    ITrnEffectFile : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE Create( 
            /* [string][in] */ const OLECHAR __RPC_FAR *pFileName) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Open( 
            /* [string][in] */ const OLECHAR __RPC_FAR *pFileName) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetRootStorage( 
            /* [out] */ IStorage __RPC_FAR *__RPC_FAR *ppStg) = 0;
        
        virtual DWORD STDMETHODCALLTYPE GetDuration( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetDuration( 
            /* [in] */ DWORD dweDurationFields) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetAttributes( 
            DWORD attr) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE ClearAttributes( 
            DWORD attr) = 0;
        
        virtual DWORD STDMETHODCALLTYPE GetAttributes( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE CreateNewInput( 
            /* [out] */ ITrnEffectInput __RPC_FAR *__RPC_FAR *ppInput) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE EnumInputs( 
            /* [out] */ IEnumUnknown __RPC_FAR *__RPC_FAR *ppEnumUnk) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE CreateNewTransition( 
            /* [out] */ ITrnEffectTransition __RPC_FAR *__RPC_FAR *ppTransition) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE EnumTransitions( 
            /* [out] */ IEnumUnknown __RPC_FAR *__RPC_FAR *ppEnumUnk) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE CreateNewTransform( 
            /* [out] */ ITrnEffectTransform __RPC_FAR *__RPC_FAR *ppTransform) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE EnumTransforms( 
            /* [out] */ IEnumUnknown __RPC_FAR *__RPC_FAR *ppEnumUnk) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE CreateMixing( 
            /* [out] */ ITrnEffectMixing __RPC_FAR *__RPC_FAR *ppMixing) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetMixing( 
            /* [out] */ ITrnEffectMixing __RPC_FAR *__RPC_FAR *ppMixing) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE CreateLayering( 
            /* [out] */ ITrnEffectLayering __RPC_FAR *__RPC_FAR *ppLayering) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetLayering( 
            /* [out] */ ITrnEffectLayering __RPC_FAR *__RPC_FAR *ppLayering) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE CreateNewSoundEffect( 
            /* [out] */ ITrnEffectSoundEffect __RPC_FAR *__RPC_FAR *ppSound) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE EnumSoundEffects( 
            /* [out] */ IEnumUnknown __RPC_FAR *__RPC_FAR *ppEnumUnk) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE CreateNewEvent( 
            /* [out] */ ITrnEffectEvent __RPC_FAR *__RPC_FAR *ppEvent) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE EnumEvents( 
            /* [out] */ IEnumUnknown __RPC_FAR *__RPC_FAR *ppEnumUnk) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetGraphics( 
            /* [out] */ ITrnGraphicsEffect __RPC_FAR *__RPC_FAR *ppGraphics) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE CreateGraphics( 
            /* [in] */ BOOL CreateAlways,
            /* [out] */ ITrnGraphicsEffect __RPC_FAR *__RPC_FAR *ppGraphics) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetFileName( 
            /* [in] */ unsigned int cbBuffSize,
            /* [out] */ OLECHAR __RPC_FAR *pBuffer) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Save( void) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct ITrnEffectFileVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            ITrnEffectFile __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            ITrnEffectFile __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            ITrnEffectFile __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Create )( 
            ITrnEffectFile __RPC_FAR * This,
            /* [string][in] */ const OLECHAR __RPC_FAR *pFileName);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Open )( 
            ITrnEffectFile __RPC_FAR * This,
            /* [string][in] */ const OLECHAR __RPC_FAR *pFileName);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetRootStorage )( 
            ITrnEffectFile __RPC_FAR * This,
            /* [out] */ IStorage __RPC_FAR *__RPC_FAR *ppStg);
        
        DWORD ( STDMETHODCALLTYPE __RPC_FAR *GetDuration )( 
            ITrnEffectFile __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetDuration )( 
            ITrnEffectFile __RPC_FAR * This,
            /* [in] */ DWORD dweDurationFields);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetAttributes )( 
            ITrnEffectFile __RPC_FAR * This,
            DWORD attr);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *ClearAttributes )( 
            ITrnEffectFile __RPC_FAR * This,
            DWORD attr);
        
        DWORD ( STDMETHODCALLTYPE __RPC_FAR *GetAttributes )( 
            ITrnEffectFile __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *CreateNewInput )( 
            ITrnEffectFile __RPC_FAR * This,
            /* [out] */ ITrnEffectInput __RPC_FAR *__RPC_FAR *ppInput);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *EnumInputs )( 
            ITrnEffectFile __RPC_FAR * This,
            /* [out] */ IEnumUnknown __RPC_FAR *__RPC_FAR *ppEnumUnk);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *CreateNewTransition )( 
            ITrnEffectFile __RPC_FAR * This,
            /* [out] */ ITrnEffectTransition __RPC_FAR *__RPC_FAR *ppTransition);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *EnumTransitions )( 
            ITrnEffectFile __RPC_FAR * This,
            /* [out] */ IEnumUnknown __RPC_FAR *__RPC_FAR *ppEnumUnk);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *CreateNewTransform )( 
            ITrnEffectFile __RPC_FAR * This,
            /* [out] */ ITrnEffectTransform __RPC_FAR *__RPC_FAR *ppTransform);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *EnumTransforms )( 
            ITrnEffectFile __RPC_FAR * This,
            /* [out] */ IEnumUnknown __RPC_FAR *__RPC_FAR *ppEnumUnk);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *CreateMixing )( 
            ITrnEffectFile __RPC_FAR * This,
            /* [out] */ ITrnEffectMixing __RPC_FAR *__RPC_FAR *ppMixing);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetMixing )( 
            ITrnEffectFile __RPC_FAR * This,
            /* [out] */ ITrnEffectMixing __RPC_FAR *__RPC_FAR *ppMixing);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *CreateLayering )( 
            ITrnEffectFile __RPC_FAR * This,
            /* [out] */ ITrnEffectLayering __RPC_FAR *__RPC_FAR *ppLayering);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetLayering )( 
            ITrnEffectFile __RPC_FAR * This,
            /* [out] */ ITrnEffectLayering __RPC_FAR *__RPC_FAR *ppLayering);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *CreateNewSoundEffect )( 
            ITrnEffectFile __RPC_FAR * This,
            /* [out] */ ITrnEffectSoundEffect __RPC_FAR *__RPC_FAR *ppSound);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *EnumSoundEffects )( 
            ITrnEffectFile __RPC_FAR * This,
            /* [out] */ IEnumUnknown __RPC_FAR *__RPC_FAR *ppEnumUnk);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *CreateNewEvent )( 
            ITrnEffectFile __RPC_FAR * This,
            /* [out] */ ITrnEffectEvent __RPC_FAR *__RPC_FAR *ppEvent);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *EnumEvents )( 
            ITrnEffectFile __RPC_FAR * This,
            /* [out] */ IEnumUnknown __RPC_FAR *__RPC_FAR *ppEnumUnk);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetGraphics )( 
            ITrnEffectFile __RPC_FAR * This,
            /* [out] */ ITrnGraphicsEffect __RPC_FAR *__RPC_FAR *ppGraphics);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *CreateGraphics )( 
            ITrnEffectFile __RPC_FAR * This,
            /* [in] */ BOOL CreateAlways,
            /* [out] */ ITrnGraphicsEffect __RPC_FAR *__RPC_FAR *ppGraphics);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetFileName )( 
            ITrnEffectFile __RPC_FAR * This,
            /* [in] */ unsigned int cbBuffSize,
            /* [out] */ OLECHAR __RPC_FAR *pBuffer);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Save )( 
            ITrnEffectFile __RPC_FAR * This);
        
        END_INTERFACE
    } ITrnEffectFileVtbl;

    interface ITrnEffectFile
    {
        CONST_VTBL struct ITrnEffectFileVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ITrnEffectFile_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define ITrnEffectFile_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define ITrnEffectFile_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define ITrnEffectFile_Create(This,pFileName)	\
    (This)->lpVtbl -> Create(This,pFileName)

#define ITrnEffectFile_Open(This,pFileName)	\
    (This)->lpVtbl -> Open(This,pFileName)

#define ITrnEffectFile_GetRootStorage(This,ppStg)	\
    (This)->lpVtbl -> GetRootStorage(This,ppStg)

#define ITrnEffectFile_GetDuration(This)	\
    (This)->lpVtbl -> GetDuration(This)

#define ITrnEffectFile_SetDuration(This,dweDurationFields)	\
    (This)->lpVtbl -> SetDuration(This,dweDurationFields)

#define ITrnEffectFile_SetAttributes(This,attr)	\
    (This)->lpVtbl -> SetAttributes(This,attr)

#define ITrnEffectFile_ClearAttributes(This,attr)	\
    (This)->lpVtbl -> ClearAttributes(This,attr)

#define ITrnEffectFile_GetAttributes(This)	\
    (This)->lpVtbl -> GetAttributes(This)

#define ITrnEffectFile_CreateNewInput(This,ppInput)	\
    (This)->lpVtbl -> CreateNewInput(This,ppInput)

#define ITrnEffectFile_EnumInputs(This,ppEnumUnk)	\
    (This)->lpVtbl -> EnumInputs(This,ppEnumUnk)

#define ITrnEffectFile_CreateNewTransition(This,ppTransition)	\
    (This)->lpVtbl -> CreateNewTransition(This,ppTransition)

#define ITrnEffectFile_EnumTransitions(This,ppEnumUnk)	\
    (This)->lpVtbl -> EnumTransitions(This,ppEnumUnk)

#define ITrnEffectFile_CreateNewTransform(This,ppTransform)	\
    (This)->lpVtbl -> CreateNewTransform(This,ppTransform)

#define ITrnEffectFile_EnumTransforms(This,ppEnumUnk)	\
    (This)->lpVtbl -> EnumTransforms(This,ppEnumUnk)

#define ITrnEffectFile_CreateMixing(This,ppMixing)	\
    (This)->lpVtbl -> CreateMixing(This,ppMixing)

#define ITrnEffectFile_GetMixing(This,ppMixing)	\
    (This)->lpVtbl -> GetMixing(This,ppMixing)

#define ITrnEffectFile_CreateLayering(This,ppLayering)	\
    (This)->lpVtbl -> CreateLayering(This,ppLayering)

#define ITrnEffectFile_GetLayering(This,ppLayering)	\
    (This)->lpVtbl -> GetLayering(This,ppLayering)

#define ITrnEffectFile_CreateNewSoundEffect(This,ppSound)	\
    (This)->lpVtbl -> CreateNewSoundEffect(This,ppSound)

#define ITrnEffectFile_EnumSoundEffects(This,ppEnumUnk)	\
    (This)->lpVtbl -> EnumSoundEffects(This,ppEnumUnk)

#define ITrnEffectFile_CreateNewEvent(This,ppEvent)	\
    (This)->lpVtbl -> CreateNewEvent(This,ppEvent)

#define ITrnEffectFile_EnumEvents(This,ppEnumUnk)	\
    (This)->lpVtbl -> EnumEvents(This,ppEnumUnk)

#define ITrnEffectFile_GetGraphics(This,ppGraphics)	\
    (This)->lpVtbl -> GetGraphics(This,ppGraphics)

#define ITrnEffectFile_CreateGraphics(This,CreateAlways,ppGraphics)	\
    (This)->lpVtbl -> CreateGraphics(This,CreateAlways,ppGraphics)

#define ITrnEffectFile_GetFileName(This,cbBuffSize,pBuffer)	\
    (This)->lpVtbl -> GetFileName(This,cbBuffSize,pBuffer)

#define ITrnEffectFile_Save(This)	\
    (This)->lpVtbl -> Save(This)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE ITrnEffectFile_Create_Proxy( 
    ITrnEffectFile __RPC_FAR * This,
    /* [string][in] */ const OLECHAR __RPC_FAR *pFileName);


void __RPC_STUB ITrnEffectFile_Create_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE ITrnEffectFile_Open_Proxy( 
    ITrnEffectFile __RPC_FAR * This,
    /* [string][in] */ const OLECHAR __RPC_FAR *pFileName);


void __RPC_STUB ITrnEffectFile_Open_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE ITrnEffectFile_GetRootStorage_Proxy( 
    ITrnEffectFile __RPC_FAR * This,
    /* [out] */ IStorage __RPC_FAR *__RPC_FAR *ppStg);


void __RPC_STUB ITrnEffectFile_GetRootStorage_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


DWORD STDMETHODCALLTYPE ITrnEffectFile_GetDuration_Proxy( 
    ITrnEffectFile __RPC_FAR * This);


void __RPC_STUB ITrnEffectFile_GetDuration_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE ITrnEffectFile_SetDuration_Proxy( 
    ITrnEffectFile __RPC_FAR * This,
    /* [in] */ DWORD dweDurationFields);


void __RPC_STUB ITrnEffectFile_SetDuration_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE ITrnEffectFile_SetAttributes_Proxy( 
    ITrnEffectFile __RPC_FAR * This,
    DWORD attr);


void __RPC_STUB ITrnEffectFile_SetAttributes_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE ITrnEffectFile_ClearAttributes_Proxy( 
    ITrnEffectFile __RPC_FAR * This,
    DWORD attr);


void __RPC_STUB ITrnEffectFile_ClearAttributes_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


DWORD STDMETHODCALLTYPE ITrnEffectFile_GetAttributes_Proxy( 
    ITrnEffectFile __RPC_FAR * This);


void __RPC_STUB ITrnEffectFile_GetAttributes_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE ITrnEffectFile_CreateNewInput_Proxy( 
    ITrnEffectFile __RPC_FAR * This,
    /* [out] */ ITrnEffectInput __RPC_FAR *__RPC_FAR *ppInput);


void __RPC_STUB ITrnEffectFile_CreateNewInput_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE ITrnEffectFile_EnumInputs_Proxy( 
    ITrnEffectFile __RPC_FAR * This,
    /* [out] */ IEnumUnknown __RPC_FAR *__RPC_FAR *ppEnumUnk);


void __RPC_STUB ITrnEffectFile_EnumInputs_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE ITrnEffectFile_CreateNewTransition_Proxy( 
    ITrnEffectFile __RPC_FAR * This,
    /* [out] */ ITrnEffectTransition __RPC_FAR *__RPC_FAR *ppTransition);


void __RPC_STUB ITrnEffectFile_CreateNewTransition_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE ITrnEffectFile_EnumTransitions_Proxy( 
    ITrnEffectFile __RPC_FAR * This,
    /* [out] */ IEnumUnknown __RPC_FAR *__RPC_FAR *ppEnumUnk);


void __RPC_STUB ITrnEffectFile_EnumTransitions_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE ITrnEffectFile_CreateNewTransform_Proxy( 
    ITrnEffectFile __RPC_FAR * This,
    /* [out] */ ITrnEffectTransform __RPC_FAR *__RPC_FAR *ppTransform);


void __RPC_STUB ITrnEffectFile_CreateNewTransform_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE ITrnEffectFile_EnumTransforms_Proxy( 
    ITrnEffectFile __RPC_FAR * This,
    /* [out] */ IEnumUnknown __RPC_FAR *__RPC_FAR *ppEnumUnk);


void __RPC_STUB ITrnEffectFile_EnumTransforms_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE ITrnEffectFile_CreateMixing_Proxy( 
    ITrnEffectFile __RPC_FAR * This,
    /* [out] */ ITrnEffectMixing __RPC_FAR *__RPC_FAR *ppMixing);


void __RPC_STUB ITrnEffectFile_CreateMixing_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE ITrnEffectFile_GetMixing_Proxy( 
    ITrnEffectFile __RPC_FAR * This,
    /* [out] */ ITrnEffectMixing __RPC_FAR *__RPC_FAR *ppMixing);


void __RPC_STUB ITrnEffectFile_GetMixing_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE ITrnEffectFile_CreateLayering_Proxy( 
    ITrnEffectFile __RPC_FAR * This,
    /* [out] */ ITrnEffectLayering __RPC_FAR *__RPC_FAR *ppLayering);


void __RPC_STUB ITrnEffectFile_CreateLayering_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE ITrnEffectFile_GetLayering_Proxy( 
    ITrnEffectFile __RPC_FAR * This,
    /* [out] */ ITrnEffectLayering __RPC_FAR *__RPC_FAR *ppLayering);


void __RPC_STUB ITrnEffectFile_GetLayering_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE ITrnEffectFile_CreateNewSoundEffect_Proxy( 
    ITrnEffectFile __RPC_FAR * This,
    /* [out] */ ITrnEffectSoundEffect __RPC_FAR *__RPC_FAR *ppSound);


void __RPC_STUB ITrnEffectFile_CreateNewSoundEffect_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE ITrnEffectFile_EnumSoundEffects_Proxy( 
    ITrnEffectFile __RPC_FAR * This,
    /* [out] */ IEnumUnknown __RPC_FAR *__RPC_FAR *ppEnumUnk);


void __RPC_STUB ITrnEffectFile_EnumSoundEffects_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE ITrnEffectFile_CreateNewEvent_Proxy( 
    ITrnEffectFile __RPC_FAR * This,
    /* [out] */ ITrnEffectEvent __RPC_FAR *__RPC_FAR *ppEvent);


void __RPC_STUB ITrnEffectFile_CreateNewEvent_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE ITrnEffectFile_EnumEvents_Proxy( 
    ITrnEffectFile __RPC_FAR * This,
    /* [out] */ IEnumUnknown __RPC_FAR *__RPC_FAR *ppEnumUnk);


void __RPC_STUB ITrnEffectFile_EnumEvents_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE ITrnEffectFile_GetGraphics_Proxy( 
    ITrnEffectFile __RPC_FAR * This,
    /* [out] */ ITrnGraphicsEffect __RPC_FAR *__RPC_FAR *ppGraphics);


void __RPC_STUB ITrnEffectFile_GetGraphics_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE ITrnEffectFile_CreateGraphics_Proxy( 
    ITrnEffectFile __RPC_FAR * This,
    /* [in] */ BOOL CreateAlways,
    /* [out] */ ITrnGraphicsEffect __RPC_FAR *__RPC_FAR *ppGraphics);


void __RPC_STUB ITrnEffectFile_CreateGraphics_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE ITrnEffectFile_GetFileName_Proxy( 
    ITrnEffectFile __RPC_FAR * This,
    /* [in] */ unsigned int cbBuffSize,
    /* [out] */ OLECHAR __RPC_FAR *pBuffer);


void __RPC_STUB ITrnEffectFile_GetFileName_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE ITrnEffectFile_Save_Proxy( 
    ITrnEffectFile __RPC_FAR * This);


void __RPC_STUB ITrnEffectFile_Save_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __ITrnEffectFile_INTERFACE_DEFINED__ */


#ifndef __ITrnEffectInput_INTERFACE_DEFINED__
#define __ITrnEffectInput_INTERFACE_DEFINED__

/****************************************
 * Generated header for interface: ITrnEffectInput
 * at Tue Nov 23 05:28:36 1999
 * using MIDL 3.01.75
 ****************************************/
/* [unique][uuid][object][local] */ 



EXTERN_C const IID IID_ITrnEffectInput;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    interface DECLSPEC_UUID("8335e5d4-ab3b-11ce-8468-0000b468276b")
    ITrnEffectInput : public IUnknown
    {
    public:
        virtual DWORD STDMETHODCALLTYPE GetIndex( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetDescription( 
            /* [out] */ IStream __RPC_FAR *__RPC_FAR *ppDescStream) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetAnimData( 
            /* [in] */ DWORD ModuleId,
            /* [out] */ IStream __RPC_FAR *__RPC_FAR *ppAnimStream) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetAnimData( 
            /* [in] */ DWORD ModuleId,
            /* [out] */ IStream __RPC_FAR *__RPC_FAR *ppAnimStream) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetTimingData( 
            /* [in] */ DWORD ModuleId,
            /* [in] */ STrnPlayList __RPC_FAR *pPlayList,
            /* [out] */ DWORD __RPC_FAR *pOffset) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetTimingData( 
            /* [in] */ DWORD ModuleId,
            /* [in] */ STrnPlayList __RPC_FAR *pPlayList,
            /* [in] */ DWORD Offset) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct ITrnEffectInputVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            ITrnEffectInput __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            ITrnEffectInput __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            ITrnEffectInput __RPC_FAR * This);
        
        DWORD ( STDMETHODCALLTYPE __RPC_FAR *GetIndex )( 
            ITrnEffectInput __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetDescription )( 
            ITrnEffectInput __RPC_FAR * This,
            /* [out] */ IStream __RPC_FAR *__RPC_FAR *ppDescStream);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetAnimData )( 
            ITrnEffectInput __RPC_FAR * This,
            /* [in] */ DWORD ModuleId,
            /* [out] */ IStream __RPC_FAR *__RPC_FAR *ppAnimStream);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetAnimData )( 
            ITrnEffectInput __RPC_FAR * This,
            /* [in] */ DWORD ModuleId,
            /* [out] */ IStream __RPC_FAR *__RPC_FAR *ppAnimStream);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTimingData )( 
            ITrnEffectInput __RPC_FAR * This,
            /* [in] */ DWORD ModuleId,
            /* [in] */ STrnPlayList __RPC_FAR *pPlayList,
            /* [out] */ DWORD __RPC_FAR *pOffset);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetTimingData )( 
            ITrnEffectInput __RPC_FAR * This,
            /* [in] */ DWORD ModuleId,
            /* [in] */ STrnPlayList __RPC_FAR *pPlayList,
            /* [in] */ DWORD Offset);
        
        END_INTERFACE
    } ITrnEffectInputVtbl;

    interface ITrnEffectInput
    {
        CONST_VTBL struct ITrnEffectInputVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ITrnEffectInput_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define ITrnEffectInput_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define ITrnEffectInput_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define ITrnEffectInput_GetIndex(This)	\
    (This)->lpVtbl -> GetIndex(This)

#define ITrnEffectInput_GetDescription(This,ppDescStream)	\
    (This)->lpVtbl -> GetDescription(This,ppDescStream)

#define ITrnEffectInput_GetAnimData(This,ModuleId,ppAnimStream)	\
    (This)->lpVtbl -> GetAnimData(This,ModuleId,ppAnimStream)

#define ITrnEffectInput_SetAnimData(This,ModuleId,ppAnimStream)	\
    (This)->lpVtbl -> SetAnimData(This,ModuleId,ppAnimStream)

#define ITrnEffectInput_GetTimingData(This,ModuleId,pPlayList,pOffset)	\
    (This)->lpVtbl -> GetTimingData(This,ModuleId,pPlayList,pOffset)

#define ITrnEffectInput_SetTimingData(This,ModuleId,pPlayList,Offset)	\
    (This)->lpVtbl -> SetTimingData(This,ModuleId,pPlayList,Offset)

#endif /* COBJMACROS */


#endif 	/* C style interface */



DWORD STDMETHODCALLTYPE ITrnEffectInput_GetIndex_Proxy( 
    ITrnEffectInput __RPC_FAR * This);


void __RPC_STUB ITrnEffectInput_GetIndex_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE ITrnEffectInput_GetDescription_Proxy( 
    ITrnEffectInput __RPC_FAR * This,
    /* [out] */ IStream __RPC_FAR *__RPC_FAR *ppDescStream);


void __RPC_STUB ITrnEffectInput_GetDescription_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE ITrnEffectInput_GetAnimData_Proxy( 
    ITrnEffectInput __RPC_FAR * This,
    /* [in] */ DWORD ModuleId,
    /* [out] */ IStream __RPC_FAR *__RPC_FAR *ppAnimStream);


void __RPC_STUB ITrnEffectInput_GetAnimData_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE ITrnEffectInput_SetAnimData_Proxy( 
    ITrnEffectInput __RPC_FAR * This,
    /* [in] */ DWORD ModuleId,
    /* [out] */ IStream __RPC_FAR *__RPC_FAR *ppAnimStream);


void __RPC_STUB ITrnEffectInput_SetAnimData_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE ITrnEffectInput_GetTimingData_Proxy( 
    ITrnEffectInput __RPC_FAR * This,
    /* [in] */ DWORD ModuleId,
    /* [in] */ STrnPlayList __RPC_FAR *pPlayList,
    /* [out] */ DWORD __RPC_FAR *pOffset);


void __RPC_STUB ITrnEffectInput_GetTimingData_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE ITrnEffectInput_SetTimingData_Proxy( 
    ITrnEffectInput __RPC_FAR * This,
    /* [in] */ DWORD ModuleId,
    /* [in] */ STrnPlayList __RPC_FAR *pPlayList,
    /* [in] */ DWORD Offset);


void __RPC_STUB ITrnEffectInput_SetTimingData_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __ITrnEffectInput_INTERFACE_DEFINED__ */


#ifndef __ITrnEffectTransition_INTERFACE_DEFINED__
#define __ITrnEffectTransition_INTERFACE_DEFINED__

/****************************************
 * Generated header for interface: ITrnEffectTransition
 * at Tue Nov 23 05:28:36 1999
 * using MIDL 3.01.75
 ****************************************/
/* [unique][uuid][object][local] */ 



EXTERN_C const IID IID_ITrnEffectTransition;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    interface DECLSPEC_UUID("8335e5d5-ab3b-11ce-8468-0000b468276b")
    ITrnEffectTransition : public IUnknown
    {
    public:
        virtual DWORD STDMETHODCALLTYPE GetIndex( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetOffset( 
            /* [out] */ DWORD __RPC_FAR *pdwOffsetFields) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetOffset( 
            /* [in] */ DWORD dwOffsetFields) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetDescription( 
            /* [out] */ IStream __RPC_FAR *__RPC_FAR *ppDescStream) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetBusConfiguration( 
            /* [in] */ DWORD dwcbTableSize,
            /* [out] */ DWORD __RPC_FAR *pBusTable) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetBusConfiguration( 
            /* [in] */ DWORD dwcbTableSize,
            /* [in] */ DWORD __RPC_FAR *pBusTable) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct ITrnEffectTransitionVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            ITrnEffectTransition __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            ITrnEffectTransition __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            ITrnEffectTransition __RPC_FAR * This);
        
        DWORD ( STDMETHODCALLTYPE __RPC_FAR *GetIndex )( 
            ITrnEffectTransition __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetOffset )( 
            ITrnEffectTransition __RPC_FAR * This,
            /* [out] */ DWORD __RPC_FAR *pdwOffsetFields);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetOffset )( 
            ITrnEffectTransition __RPC_FAR * This,
            /* [in] */ DWORD dwOffsetFields);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetDescription )( 
            ITrnEffectTransition __RPC_FAR * This,
            /* [out] */ IStream __RPC_FAR *__RPC_FAR *ppDescStream);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetBusConfiguration )( 
            ITrnEffectTransition __RPC_FAR * This,
            /* [in] */ DWORD dwcbTableSize,
            /* [out] */ DWORD __RPC_FAR *pBusTable);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetBusConfiguration )( 
            ITrnEffectTransition __RPC_FAR * This,
            /* [in] */ DWORD dwcbTableSize,
            /* [in] */ DWORD __RPC_FAR *pBusTable);
        
        END_INTERFACE
    } ITrnEffectTransitionVtbl;

    interface ITrnEffectTransition
    {
        CONST_VTBL struct ITrnEffectTransitionVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ITrnEffectTransition_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define ITrnEffectTransition_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define ITrnEffectTransition_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define ITrnEffectTransition_GetIndex(This)	\
    (This)->lpVtbl -> GetIndex(This)

#define ITrnEffectTransition_GetOffset(This,pdwOffsetFields)	\
    (This)->lpVtbl -> GetOffset(This,pdwOffsetFields)

#define ITrnEffectTransition_SetOffset(This,dwOffsetFields)	\
    (This)->lpVtbl -> SetOffset(This,dwOffsetFields)

#define ITrnEffectTransition_GetDescription(This,ppDescStream)	\
    (This)->lpVtbl -> GetDescription(This,ppDescStream)

#define ITrnEffectTransition_GetBusConfiguration(This,dwcbTableSize,pBusTable)	\
    (This)->lpVtbl -> GetBusConfiguration(This,dwcbTableSize,pBusTable)

#define ITrnEffectTransition_SetBusConfiguration(This,dwcbTableSize,pBusTable)	\
    (This)->lpVtbl -> SetBusConfiguration(This,dwcbTableSize,pBusTable)

#endif /* COBJMACROS */


#endif 	/* C style interface */



DWORD STDMETHODCALLTYPE ITrnEffectTransition_GetIndex_Proxy( 
    ITrnEffectTransition __RPC_FAR * This);


void __RPC_STUB ITrnEffectTransition_GetIndex_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE ITrnEffectTransition_GetOffset_Proxy( 
    ITrnEffectTransition __RPC_FAR * This,
    /* [out] */ DWORD __RPC_FAR *pdwOffsetFields);


void __RPC_STUB ITrnEffectTransition_GetOffset_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE ITrnEffectTransition_SetOffset_Proxy( 
    ITrnEffectTransition __RPC_FAR * This,
    /* [in] */ DWORD dwOffsetFields);


void __RPC_STUB ITrnEffectTransition_SetOffset_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE ITrnEffectTransition_GetDescription_Proxy( 
    ITrnEffectTransition __RPC_FAR * This,
    /* [out] */ IStream __RPC_FAR *__RPC_FAR *ppDescStream);


void __RPC_STUB ITrnEffectTransition_GetDescription_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE ITrnEffectTransition_GetBusConfiguration_Proxy( 
    ITrnEffectTransition __RPC_FAR * This,
    /* [in] */ DWORD dwcbTableSize,
    /* [out] */ DWORD __RPC_FAR *pBusTable);


void __RPC_STUB ITrnEffectTransition_GetBusConfiguration_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE ITrnEffectTransition_SetBusConfiguration_Proxy( 
    ITrnEffectTransition __RPC_FAR * This,
    /* [in] */ DWORD dwcbTableSize,
    /* [in] */ DWORD __RPC_FAR *pBusTable);


void __RPC_STUB ITrnEffectTransition_SetBusConfiguration_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __ITrnEffectTransition_INTERFACE_DEFINED__ */


#ifndef __ITrnEffectTransform_INTERFACE_DEFINED__
#define __ITrnEffectTransform_INTERFACE_DEFINED__

/****************************************
 * Generated header for interface: ITrnEffectTransform
 * at Tue Nov 23 05:28:36 1999
 * using MIDL 3.01.75
 ****************************************/
/* [unique][uuid][object][local] */ 



EXTERN_C const IID IID_ITrnEffectTransform;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    interface DECLSPEC_UUID("8335e5d6-ab3b-11ce-8468-0000b468276b")
    ITrnEffectTransform : public IUnknown
    {
    public:
        virtual DWORD STDMETHODCALLTYPE GetIndex( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetDescription( 
            /* [out] */ IStream __RPC_FAR *__RPC_FAR *ppDescStream) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetSource( 
            /* [out] */ DWORD __RPC_FAR *pdwSourceNum) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetSource( 
            /* [in] */ DWORD dwSourceNum) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetAnimData( 
            /* [in] */ DWORD ModuleId,
            /* [out] */ IStream __RPC_FAR *__RPC_FAR *ppStream) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetAnimData( 
            /* [in] */ DWORD ModuleId,
            /* [out] */ IStream __RPC_FAR *__RPC_FAR *ppStream) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetTimingData( 
            /* [in] */ DWORD ModuleId,
            /* [in] */ STrnPlayList __RPC_FAR *pPlayList,
            /* [out] */ DWORD __RPC_FAR *pOffset) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetTimingData( 
            /* [in] */ DWORD ModuleId,
            /* [in] */ STrnPlayList __RPC_FAR *pPlayList,
            /* [in] */ DWORD Offset) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE EnumModuleIds( 
            /* [out][in] */ DWORD __RPC_FAR *pListLength,
            /* [out] */ DWORD __RPC_FAR *pModuleList) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct ITrnEffectTransformVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            ITrnEffectTransform __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            ITrnEffectTransform __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            ITrnEffectTransform __RPC_FAR * This);
        
        DWORD ( STDMETHODCALLTYPE __RPC_FAR *GetIndex )( 
            ITrnEffectTransform __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetDescription )( 
            ITrnEffectTransform __RPC_FAR * This,
            /* [out] */ IStream __RPC_FAR *__RPC_FAR *ppDescStream);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetSource )( 
            ITrnEffectTransform __RPC_FAR * This,
            /* [out] */ DWORD __RPC_FAR *pdwSourceNum);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetSource )( 
            ITrnEffectTransform __RPC_FAR * This,
            /* [in] */ DWORD dwSourceNum);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetAnimData )( 
            ITrnEffectTransform __RPC_FAR * This,
            /* [in] */ DWORD ModuleId,
            /* [out] */ IStream __RPC_FAR *__RPC_FAR *ppStream);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetAnimData )( 
            ITrnEffectTransform __RPC_FAR * This,
            /* [in] */ DWORD ModuleId,
            /* [out] */ IStream __RPC_FAR *__RPC_FAR *ppStream);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTimingData )( 
            ITrnEffectTransform __RPC_FAR * This,
            /* [in] */ DWORD ModuleId,
            /* [in] */ STrnPlayList __RPC_FAR *pPlayList,
            /* [out] */ DWORD __RPC_FAR *pOffset);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetTimingData )( 
            ITrnEffectTransform __RPC_FAR * This,
            /* [in] */ DWORD ModuleId,
            /* [in] */ STrnPlayList __RPC_FAR *pPlayList,
            /* [in] */ DWORD Offset);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *EnumModuleIds )( 
            ITrnEffectTransform __RPC_FAR * This,
            /* [out][in] */ DWORD __RPC_FAR *pListLength,
            /* [out] */ DWORD __RPC_FAR *pModuleList);
        
        END_INTERFACE
    } ITrnEffectTransformVtbl;

    interface ITrnEffectTransform
    {
        CONST_VTBL struct ITrnEffectTransformVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ITrnEffectTransform_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define ITrnEffectTransform_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define ITrnEffectTransform_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define ITrnEffectTransform_GetIndex(This)	\
    (This)->lpVtbl -> GetIndex(This)

#define ITrnEffectTransform_GetDescription(This,ppDescStream)	\
    (This)->lpVtbl -> GetDescription(This,ppDescStream)

#define ITrnEffectTransform_GetSource(This,pdwSourceNum)	\
    (This)->lpVtbl -> GetSource(This,pdwSourceNum)

#define ITrnEffectTransform_SetSource(This,dwSourceNum)	\
    (This)->lpVtbl -> SetSource(This,dwSourceNum)

#define ITrnEffectTransform_GetAnimData(This,ModuleId,ppStream)	\
    (This)->lpVtbl -> GetAnimData(This,ModuleId,ppStream)

#define ITrnEffectTransform_SetAnimData(This,ModuleId,ppStream)	\
    (This)->lpVtbl -> SetAnimData(This,ModuleId,ppStream)

#define ITrnEffectTransform_GetTimingData(This,ModuleId,pPlayList,pOffset)	\
    (This)->lpVtbl -> GetTimingData(This,ModuleId,pPlayList,pOffset)

#define ITrnEffectTransform_SetTimingData(This,ModuleId,pPlayList,Offset)	\
    (This)->lpVtbl -> SetTimingData(This,ModuleId,pPlayList,Offset)

#define ITrnEffectTransform_EnumModuleIds(This,pListLength,pModuleList)	\
    (This)->lpVtbl -> EnumModuleIds(This,pListLength,pModuleList)

#endif /* COBJMACROS */


#endif 	/* C style interface */



DWORD STDMETHODCALLTYPE ITrnEffectTransform_GetIndex_Proxy( 
    ITrnEffectTransform __RPC_FAR * This);


void __RPC_STUB ITrnEffectTransform_GetIndex_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE ITrnEffectTransform_GetDescription_Proxy( 
    ITrnEffectTransform __RPC_FAR * This,
    /* [out] */ IStream __RPC_FAR *__RPC_FAR *ppDescStream);


void __RPC_STUB ITrnEffectTransform_GetDescription_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE ITrnEffectTransform_GetSource_Proxy( 
    ITrnEffectTransform __RPC_FAR * This,
    /* [out] */ DWORD __RPC_FAR *pdwSourceNum);


void __RPC_STUB ITrnEffectTransform_GetSource_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE ITrnEffectTransform_SetSource_Proxy( 
    ITrnEffectTransform __RPC_FAR * This,
    /* [in] */ DWORD dwSourceNum);


void __RPC_STUB ITrnEffectTransform_SetSource_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE ITrnEffectTransform_GetAnimData_Proxy( 
    ITrnEffectTransform __RPC_FAR * This,
    /* [in] */ DWORD ModuleId,
    /* [out] */ IStream __RPC_FAR *__RPC_FAR *ppStream);


void __RPC_STUB ITrnEffectTransform_GetAnimData_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE ITrnEffectTransform_SetAnimData_Proxy( 
    ITrnEffectTransform __RPC_FAR * This,
    /* [in] */ DWORD ModuleId,
    /* [out] */ IStream __RPC_FAR *__RPC_FAR *ppStream);


void __RPC_STUB ITrnEffectTransform_SetAnimData_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE ITrnEffectTransform_GetTimingData_Proxy( 
    ITrnEffectTransform __RPC_FAR * This,
    /* [in] */ DWORD ModuleId,
    /* [in] */ STrnPlayList __RPC_FAR *pPlayList,
    /* [out] */ DWORD __RPC_FAR *pOffset);


void __RPC_STUB ITrnEffectTransform_GetTimingData_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE ITrnEffectTransform_SetTimingData_Proxy( 
    ITrnEffectTransform __RPC_FAR * This,
    /* [in] */ DWORD ModuleId,
    /* [in] */ STrnPlayList __RPC_FAR *pPlayList,
    /* [in] */ DWORD Offset);


void __RPC_STUB ITrnEffectTransform_SetTimingData_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE ITrnEffectTransform_EnumModuleIds_Proxy( 
    ITrnEffectTransform __RPC_FAR * This,
    /* [out][in] */ DWORD __RPC_FAR *pListLength,
    /* [out] */ DWORD __RPC_FAR *pModuleList);


void __RPC_STUB ITrnEffectTransform_EnumModuleIds_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __ITrnEffectTransform_INTERFACE_DEFINED__ */


#ifndef __ITrnEffectMixing_INTERFACE_DEFINED__
#define __ITrnEffectMixing_INTERFACE_DEFINED__

/****************************************
 * Generated header for interface: ITrnEffectMixing
 * at Tue Nov 23 05:28:36 1999
 * using MIDL 3.01.75
 ****************************************/
/* [unique][uuid][object][local] */ 



EXTERN_C const IID IID_ITrnEffectMixing;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    interface DECLSPEC_UUID("8335e5d7-ab3b-11ce-8468-0000b468276b")
    ITrnEffectMixing : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE GetAnimData( 
            /* [in] */ DWORD ModuleId,
            /* [out] */ IStream __RPC_FAR *__RPC_FAR *ppStream) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetAnimData( 
            /* [in] */ DWORD ModuleId,
            /* [out] */ IStream __RPC_FAR *__RPC_FAR *ppStream) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetTimingData( 
            /* [in] */ DWORD ModuleId,
            /* [in] */ STrnPlayList __RPC_FAR *pPlayList,
            /* [out] */ DWORD __RPC_FAR *pOffset) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetTimingData( 
            /* [in] */ DWORD ModuleId,
            /* [in] */ STrnPlayList __RPC_FAR *pPlayList,
            /* [in] */ DWORD Offset) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE EnumModuleIds( 
            /* [out][in] */ DWORD __RPC_FAR *pListLength,
            /* [out] */ DWORD __RPC_FAR *pModuleList) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct ITrnEffectMixingVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            ITrnEffectMixing __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            ITrnEffectMixing __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            ITrnEffectMixing __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetAnimData )( 
            ITrnEffectMixing __RPC_FAR * This,
            /* [in] */ DWORD ModuleId,
            /* [out] */ IStream __RPC_FAR *__RPC_FAR *ppStream);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetAnimData )( 
            ITrnEffectMixing __RPC_FAR * This,
            /* [in] */ DWORD ModuleId,
            /* [out] */ IStream __RPC_FAR *__RPC_FAR *ppStream);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTimingData )( 
            ITrnEffectMixing __RPC_FAR * This,
            /* [in] */ DWORD ModuleId,
            /* [in] */ STrnPlayList __RPC_FAR *pPlayList,
            /* [out] */ DWORD __RPC_FAR *pOffset);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetTimingData )( 
            ITrnEffectMixing __RPC_FAR * This,
            /* [in] */ DWORD ModuleId,
            /* [in] */ STrnPlayList __RPC_FAR *pPlayList,
            /* [in] */ DWORD Offset);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *EnumModuleIds )( 
            ITrnEffectMixing __RPC_FAR * This,
            /* [out][in] */ DWORD __RPC_FAR *pListLength,
            /* [out] */ DWORD __RPC_FAR *pModuleList);
        
        END_INTERFACE
    } ITrnEffectMixingVtbl;

    interface ITrnEffectMixing
    {
        CONST_VTBL struct ITrnEffectMixingVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ITrnEffectMixing_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define ITrnEffectMixing_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define ITrnEffectMixing_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define ITrnEffectMixing_GetAnimData(This,ModuleId,ppStream)	\
    (This)->lpVtbl -> GetAnimData(This,ModuleId,ppStream)

#define ITrnEffectMixing_SetAnimData(This,ModuleId,ppStream)	\
    (This)->lpVtbl -> SetAnimData(This,ModuleId,ppStream)

#define ITrnEffectMixing_GetTimingData(This,ModuleId,pPlayList,pOffset)	\
    (This)->lpVtbl -> GetTimingData(This,ModuleId,pPlayList,pOffset)

#define ITrnEffectMixing_SetTimingData(This,ModuleId,pPlayList,Offset)	\
    (This)->lpVtbl -> SetTimingData(This,ModuleId,pPlayList,Offset)

#define ITrnEffectMixing_EnumModuleIds(This,pListLength,pModuleList)	\
    (This)->lpVtbl -> EnumModuleIds(This,pListLength,pModuleList)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE ITrnEffectMixing_GetAnimData_Proxy( 
    ITrnEffectMixing __RPC_FAR * This,
    /* [in] */ DWORD ModuleId,
    /* [out] */ IStream __RPC_FAR *__RPC_FAR *ppStream);


void __RPC_STUB ITrnEffectMixing_GetAnimData_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE ITrnEffectMixing_SetAnimData_Proxy( 
    ITrnEffectMixing __RPC_FAR * This,
    /* [in] */ DWORD ModuleId,
    /* [out] */ IStream __RPC_FAR *__RPC_FAR *ppStream);


void __RPC_STUB ITrnEffectMixing_SetAnimData_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE ITrnEffectMixing_GetTimingData_Proxy( 
    ITrnEffectMixing __RPC_FAR * This,
    /* [in] */ DWORD ModuleId,
    /* [in] */ STrnPlayList __RPC_FAR *pPlayList,
    /* [out] */ DWORD __RPC_FAR *pOffset);


void __RPC_STUB ITrnEffectMixing_GetTimingData_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE ITrnEffectMixing_SetTimingData_Proxy( 
    ITrnEffectMixing __RPC_FAR * This,
    /* [in] */ DWORD ModuleId,
    /* [in] */ STrnPlayList __RPC_FAR *pPlayList,
    /* [in] */ DWORD Offset);


void __RPC_STUB ITrnEffectMixing_SetTimingData_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE ITrnEffectMixing_EnumModuleIds_Proxy( 
    ITrnEffectMixing __RPC_FAR * This,
    /* [out][in] */ DWORD __RPC_FAR *pListLength,
    /* [out] */ DWORD __RPC_FAR *pModuleList);


void __RPC_STUB ITrnEffectMixing_EnumModuleIds_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __ITrnEffectMixing_INTERFACE_DEFINED__ */


#ifndef __ITrnEffectLayering_INTERFACE_DEFINED__
#define __ITrnEffectLayering_INTERFACE_DEFINED__

/****************************************
 * Generated header for interface: ITrnEffectLayering
 * at Tue Nov 23 05:28:36 1999
 * using MIDL 3.01.75
 ****************************************/
/* [unique][uuid][object][local] */ 


typedef 
enum tagETrnDvePriority
    {	KP_None	= 0,
	KP_Background	= 0x1,
	KP_ForegroundLT	= 0x2,
	KP_ForegroundGE	= 0x4,
	KP_Foreground	= 0xfe,
	KP_Foreground3	= 0x8,
	KP_Foreground4	= 0x10,
	KP_Foreground5	= 0x20,
	KP_Foreground6	= 0x40,
	KP_Foreground7	= 0x80
    }	ETrnDvePriority;

typedef 
enum tagETrnBusIndex
    {	BI_ABalpha	= 0,
	BI_MCalpha	= BI_ABalpha + 1,
	BI_Cbus	= BI_MCalpha + 1,
	BI_Bbus	= BI_Cbus + 1,
	BI_Abus	= BI_Bbus + 1
    }	ETrnBusIndex;


EXTERN_C const IID IID_ITrnEffectLayering;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    interface DECLSPEC_UUID("8335e5d8-ab3b-11ce-8468-0000b468276b")
    ITrnEffectLayering : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE GetAnimData( 
            /* [in] */ DWORD ModuleId,
            /* [in] */ DWORD dwBuffSize,
            /* [out] */ void __RPC_FAR *pTable) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetAnimDataStream( 
            /* [in] */ DWORD ModuleId,
            /* [out] */ IStream __RPC_FAR *__RPC_FAR *ppStream) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetLayerEntry( 
            /* [in] */ DWORD ModuleId,
            /* [in] */ DWORD TableNumber,
            /* [in] */ DWORD LayerNumber,
            /* [in] */ DWORD BoardNum,
            /* [in] */ ETrnBusIndex BusIndex,
            /* [in] */ DWORD KeyPriorityMask) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetTimingData( 
            /* [in] */ DWORD ModuleId,
            /* [in] */ STrnPlayList __RPC_FAR *pPlayList,
            /* [out] */ DWORD __RPC_FAR *pOffset) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetTimingData( 
            /* [in] */ DWORD ModuleId,
            /* [in] */ STrnPlayList __RPC_FAR *pPlayList,
            /* [in] */ DWORD Offset) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE EnumModuleIds( 
            /* [out][in] */ DWORD __RPC_FAR *pListLength,
            /* [out] */ DWORD __RPC_FAR *pModuleList) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct ITrnEffectLayeringVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            ITrnEffectLayering __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            ITrnEffectLayering __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            ITrnEffectLayering __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetAnimData )( 
            ITrnEffectLayering __RPC_FAR * This,
            /* [in] */ DWORD ModuleId,
            /* [in] */ DWORD dwBuffSize,
            /* [out] */ void __RPC_FAR *pTable);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetAnimDataStream )( 
            ITrnEffectLayering __RPC_FAR * This,
            /* [in] */ DWORD ModuleId,
            /* [out] */ IStream __RPC_FAR *__RPC_FAR *ppStream);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetLayerEntry )( 
            ITrnEffectLayering __RPC_FAR * This,
            /* [in] */ DWORD ModuleId,
            /* [in] */ DWORD TableNumber,
            /* [in] */ DWORD LayerNumber,
            /* [in] */ DWORD BoardNum,
            /* [in] */ ETrnBusIndex BusIndex,
            /* [in] */ DWORD KeyPriorityMask);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTimingData )( 
            ITrnEffectLayering __RPC_FAR * This,
            /* [in] */ DWORD ModuleId,
            /* [in] */ STrnPlayList __RPC_FAR *pPlayList,
            /* [out] */ DWORD __RPC_FAR *pOffset);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetTimingData )( 
            ITrnEffectLayering __RPC_FAR * This,
            /* [in] */ DWORD ModuleId,
            /* [in] */ STrnPlayList __RPC_FAR *pPlayList,
            /* [in] */ DWORD Offset);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *EnumModuleIds )( 
            ITrnEffectLayering __RPC_FAR * This,
            /* [out][in] */ DWORD __RPC_FAR *pListLength,
            /* [out] */ DWORD __RPC_FAR *pModuleList);
        
        END_INTERFACE
    } ITrnEffectLayeringVtbl;

    interface ITrnEffectLayering
    {
        CONST_VTBL struct ITrnEffectLayeringVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ITrnEffectLayering_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define ITrnEffectLayering_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define ITrnEffectLayering_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define ITrnEffectLayering_GetAnimData(This,ModuleId,dwBuffSize,pTable)	\
    (This)->lpVtbl -> GetAnimData(This,ModuleId,dwBuffSize,pTable)

#define ITrnEffectLayering_GetAnimDataStream(This,ModuleId,ppStream)	\
    (This)->lpVtbl -> GetAnimDataStream(This,ModuleId,ppStream)

#define ITrnEffectLayering_SetLayerEntry(This,ModuleId,TableNumber,LayerNumber,BoardNum,BusIndex,KeyPriorityMask)	\
    (This)->lpVtbl -> SetLayerEntry(This,ModuleId,TableNumber,LayerNumber,BoardNum,BusIndex,KeyPriorityMask)

#define ITrnEffectLayering_GetTimingData(This,ModuleId,pPlayList,pOffset)	\
    (This)->lpVtbl -> GetTimingData(This,ModuleId,pPlayList,pOffset)

#define ITrnEffectLayering_SetTimingData(This,ModuleId,pPlayList,Offset)	\
    (This)->lpVtbl -> SetTimingData(This,ModuleId,pPlayList,Offset)

#define ITrnEffectLayering_EnumModuleIds(This,pListLength,pModuleList)	\
    (This)->lpVtbl -> EnumModuleIds(This,pListLength,pModuleList)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE ITrnEffectLayering_GetAnimData_Proxy( 
    ITrnEffectLayering __RPC_FAR * This,
    /* [in] */ DWORD ModuleId,
    /* [in] */ DWORD dwBuffSize,
    /* [out] */ void __RPC_FAR *pTable);


void __RPC_STUB ITrnEffectLayering_GetAnimData_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE ITrnEffectLayering_GetAnimDataStream_Proxy( 
    ITrnEffectLayering __RPC_FAR * This,
    /* [in] */ DWORD ModuleId,
    /* [out] */ IStream __RPC_FAR *__RPC_FAR *ppStream);


void __RPC_STUB ITrnEffectLayering_GetAnimDataStream_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE ITrnEffectLayering_SetLayerEntry_Proxy( 
    ITrnEffectLayering __RPC_FAR * This,
    /* [in] */ DWORD ModuleId,
    /* [in] */ DWORD TableNumber,
    /* [in] */ DWORD LayerNumber,
    /* [in] */ DWORD BoardNum,
    /* [in] */ ETrnBusIndex BusIndex,
    /* [in] */ DWORD KeyPriorityMask);


void __RPC_STUB ITrnEffectLayering_SetLayerEntry_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE ITrnEffectLayering_GetTimingData_Proxy( 
    ITrnEffectLayering __RPC_FAR * This,
    /* [in] */ DWORD ModuleId,
    /* [in] */ STrnPlayList __RPC_FAR *pPlayList,
    /* [out] */ DWORD __RPC_FAR *pOffset);


void __RPC_STUB ITrnEffectLayering_GetTimingData_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE ITrnEffectLayering_SetTimingData_Proxy( 
    ITrnEffectLayering __RPC_FAR * This,
    /* [in] */ DWORD ModuleId,
    /* [in] */ STrnPlayList __RPC_FAR *pPlayList,
    /* [in] */ DWORD Offset);


void __RPC_STUB ITrnEffectLayering_SetTimingData_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE ITrnEffectLayering_EnumModuleIds_Proxy( 
    ITrnEffectLayering __RPC_FAR * This,
    /* [out][in] */ DWORD __RPC_FAR *pListLength,
    /* [out] */ DWORD __RPC_FAR *pModuleList);


void __RPC_STUB ITrnEffectLayering_EnumModuleIds_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __ITrnEffectLayering_INTERFACE_DEFINED__ */


#ifndef __ITrnEffectSoundEffect_INTERFACE_DEFINED__
#define __ITrnEffectSoundEffect_INTERFACE_DEFINED__

/****************************************
 * Generated header for interface: ITrnEffectSoundEffect
 * at Tue Nov 23 05:28:36 1999
 * using MIDL 3.01.75
 ****************************************/
/* [unique][uuid][object][local] */ 



EXTERN_C const IID IID_ITrnEffectSoundEffect;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    interface DECLSPEC_UUID("8335e5d9-ab3b-11ce-8468-0000b468276b")
    ITrnEffectSoundEffect : public IUnknown
    {
    public:
        virtual DWORD STDMETHODCALLTYPE GetIndex( void) = 0;
        
        virtual DWORD STDMETHODCALLTYPE GetOffset( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetDescription( 
            /* [out] */ IStream __RPC_FAR *__RPC_FAR *ppDescStream) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetOffset( 
            /* [in] */ DWORD dwOffsetFields) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetAnimData( 
            /* [out] */ IStream __RPC_FAR *__RPC_FAR *ppStream) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetAnimData( 
            /* [string][in] */ const OLECHAR __RPC_FAR *pFileName) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct ITrnEffectSoundEffectVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            ITrnEffectSoundEffect __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            ITrnEffectSoundEffect __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            ITrnEffectSoundEffect __RPC_FAR * This);
        
        DWORD ( STDMETHODCALLTYPE __RPC_FAR *GetIndex )( 
            ITrnEffectSoundEffect __RPC_FAR * This);
        
        DWORD ( STDMETHODCALLTYPE __RPC_FAR *GetOffset )( 
            ITrnEffectSoundEffect __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetDescription )( 
            ITrnEffectSoundEffect __RPC_FAR * This,
            /* [out] */ IStream __RPC_FAR *__RPC_FAR *ppDescStream);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetOffset )( 
            ITrnEffectSoundEffect __RPC_FAR * This,
            /* [in] */ DWORD dwOffsetFields);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetAnimData )( 
            ITrnEffectSoundEffect __RPC_FAR * This,
            /* [out] */ IStream __RPC_FAR *__RPC_FAR *ppStream);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetAnimData )( 
            ITrnEffectSoundEffect __RPC_FAR * This,
            /* [string][in] */ const OLECHAR __RPC_FAR *pFileName);
        
        END_INTERFACE
    } ITrnEffectSoundEffectVtbl;

    interface ITrnEffectSoundEffect
    {
        CONST_VTBL struct ITrnEffectSoundEffectVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ITrnEffectSoundEffect_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define ITrnEffectSoundEffect_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define ITrnEffectSoundEffect_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define ITrnEffectSoundEffect_GetIndex(This)	\
    (This)->lpVtbl -> GetIndex(This)

#define ITrnEffectSoundEffect_GetOffset(This)	\
    (This)->lpVtbl -> GetOffset(This)

#define ITrnEffectSoundEffect_GetDescription(This,ppDescStream)	\
    (This)->lpVtbl -> GetDescription(This,ppDescStream)

#define ITrnEffectSoundEffect_SetOffset(This,dwOffsetFields)	\
    (This)->lpVtbl -> SetOffset(This,dwOffsetFields)

#define ITrnEffectSoundEffect_GetAnimData(This,ppStream)	\
    (This)->lpVtbl -> GetAnimData(This,ppStream)

#define ITrnEffectSoundEffect_SetAnimData(This,pFileName)	\
    (This)->lpVtbl -> SetAnimData(This,pFileName)

#endif /* COBJMACROS */


#endif 	/* C style interface */



DWORD STDMETHODCALLTYPE ITrnEffectSoundEffect_GetIndex_Proxy( 
    ITrnEffectSoundEffect __RPC_FAR * This);


void __RPC_STUB ITrnEffectSoundEffect_GetIndex_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


DWORD STDMETHODCALLTYPE ITrnEffectSoundEffect_GetOffset_Proxy( 
    ITrnEffectSoundEffect __RPC_FAR * This);


void __RPC_STUB ITrnEffectSoundEffect_GetOffset_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE ITrnEffectSoundEffect_GetDescription_Proxy( 
    ITrnEffectSoundEffect __RPC_FAR * This,
    /* [out] */ IStream __RPC_FAR *__RPC_FAR *ppDescStream);


void __RPC_STUB ITrnEffectSoundEffect_GetDescription_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE ITrnEffectSoundEffect_SetOffset_Proxy( 
    ITrnEffectSoundEffect __RPC_FAR * This,
    /* [in] */ DWORD dwOffsetFields);


void __RPC_STUB ITrnEffectSoundEffect_SetOffset_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE ITrnEffectSoundEffect_GetAnimData_Proxy( 
    ITrnEffectSoundEffect __RPC_FAR * This,
    /* [out] */ IStream __RPC_FAR *__RPC_FAR *ppStream);


void __RPC_STUB ITrnEffectSoundEffect_GetAnimData_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE ITrnEffectSoundEffect_SetAnimData_Proxy( 
    ITrnEffectSoundEffect __RPC_FAR * This,
    /* [string][in] */ const OLECHAR __RPC_FAR *pFileName);


void __RPC_STUB ITrnEffectSoundEffect_SetAnimData_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __ITrnEffectSoundEffect_INTERFACE_DEFINED__ */


#ifndef __ITrnEffectEvent_INTERFACE_DEFINED__
#define __ITrnEffectEvent_INTERFACE_DEFINED__

/****************************************
 * Generated header for interface: ITrnEffectEvent
 * at Tue Nov 23 05:28:36 1999
 * using MIDL 3.01.75
 ****************************************/
/* [unique][uuid][object][local] */ 



EXTERN_C const IID IID_ITrnEffectEvent;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    interface DECLSPEC_UUID("8335e5da-ab3b-11ce-8468-0000b468276b")
    ITrnEffectEvent : public IUnknown
    {
    public:
        virtual DWORD STDMETHODCALLTYPE GetIndex( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetDescription( 
            /* [out] */ IStream __RPC_FAR *__RPC_FAR *ppDescStream) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct ITrnEffectEventVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            ITrnEffectEvent __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            ITrnEffectEvent __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            ITrnEffectEvent __RPC_FAR * This);
        
        DWORD ( STDMETHODCALLTYPE __RPC_FAR *GetIndex )( 
            ITrnEffectEvent __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetDescription )( 
            ITrnEffectEvent __RPC_FAR * This,
            /* [out] */ IStream __RPC_FAR *__RPC_FAR *ppDescStream);
        
        END_INTERFACE
    } ITrnEffectEventVtbl;

    interface ITrnEffectEvent
    {
        CONST_VTBL struct ITrnEffectEventVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ITrnEffectEvent_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define ITrnEffectEvent_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define ITrnEffectEvent_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define ITrnEffectEvent_GetIndex(This)	\
    (This)->lpVtbl -> GetIndex(This)

#define ITrnEffectEvent_GetDescription(This,ppDescStream)	\
    (This)->lpVtbl -> GetDescription(This,ppDescStream)

#endif /* COBJMACROS */


#endif 	/* C style interface */



DWORD STDMETHODCALLTYPE ITrnEffectEvent_GetIndex_Proxy( 
    ITrnEffectEvent __RPC_FAR * This);


void __RPC_STUB ITrnEffectEvent_GetIndex_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE ITrnEffectEvent_GetDescription_Proxy( 
    ITrnEffectEvent __RPC_FAR * This,
    /* [out] */ IStream __RPC_FAR *__RPC_FAR *ppDescStream);


void __RPC_STUB ITrnEffectEvent_GetDescription_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __ITrnEffectEvent_INTERFACE_DEFINED__ */


/* Additional Prototypes for ALL interfaces */

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif
