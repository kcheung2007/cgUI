/* this ALWAYS GENERATED file contains the definitions for the interfaces */


/* File created by MIDL compiler version 3.01.75 */
/* at Tue Nov 23 05:28:37 1999
 */
/* Compiler settings for trnity.idl:
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

#ifndef __trnity_h__
#define __trnity_h__

#ifdef __cplusplus
extern "C"{
#endif 

/* Forward Declarations */ 

#ifndef __ITrnItemContainer_FWD_DEFINED__
#define __ITrnItemContainer_FWD_DEFINED__
typedef interface ITrnItemContainer ITrnItemContainer;
#endif 	/* __ITrnItemContainer_FWD_DEFINED__ */


#ifndef __ITrnVideoSystemFactory_FWD_DEFINED__
#define __ITrnVideoSystemFactory_FWD_DEFINED__
typedef interface ITrnVideoSystemFactory ITrnVideoSystemFactory;
#endif 	/* __ITrnVideoSystemFactory_FWD_DEFINED__ */


#ifndef __ITrnVideoSystemFactory2_FWD_DEFINED__
#define __ITrnVideoSystemFactory2_FWD_DEFINED__
typedef interface ITrnVideoSystemFactory2 ITrnVideoSystemFactory2;
#endif 	/* __ITrnVideoSystemFactory2_FWD_DEFINED__ */


#ifndef __ITrnModule_FWD_DEFINED__
#define __ITrnModule_FWD_DEFINED__
typedef interface ITrnModule ITrnModule;
#endif 	/* __ITrnModule_FWD_DEFINED__ */


#ifndef __ITrnModule2_FWD_DEFINED__
#define __ITrnModule2_FWD_DEFINED__
typedef interface ITrnModule2 ITrnModule2;
#endif 	/* __ITrnModule2_FWD_DEFINED__ */


#ifndef __ITrnDiagnostics_FWD_DEFINED__
#define __ITrnDiagnostics_FWD_DEFINED__
typedef interface ITrnDiagnostics ITrnDiagnostics;
#endif 	/* __ITrnDiagnostics_FWD_DEFINED__ */


#ifndef __ITrnDiagnostics2_FWD_DEFINED__
#define __ITrnDiagnostics2_FWD_DEFINED__
typedef interface ITrnDiagnostics2 ITrnDiagnostics2;
#endif 	/* __ITrnDiagnostics2_FWD_DEFINED__ */


#ifndef __ITrnVideoSystem_FWD_DEFINED__
#define __ITrnVideoSystem_FWD_DEFINED__
typedef interface ITrnVideoSystem ITrnVideoSystem;
#endif 	/* __ITrnVideoSystem_FWD_DEFINED__ */


#ifndef __ITrnModuleProxy_FWD_DEFINED__
#define __ITrnModuleProxy_FWD_DEFINED__
typedef interface ITrnModuleProxy ITrnModuleProxy;
#endif 	/* __ITrnModuleProxy_FWD_DEFINED__ */


#ifndef __ITrnCoreAddOn_FWD_DEFINED__
#define __ITrnCoreAddOn_FWD_DEFINED__
typedef interface ITrnCoreAddOn ITrnCoreAddOn;
#endif 	/* __ITrnCoreAddOn_FWD_DEFINED__ */


#ifndef __ITrnPropertySet_FWD_DEFINED__
#define __ITrnPropertySet_FWD_DEFINED__
typedef interface ITrnPropertySet ITrnPropertySet;
#endif 	/* __ITrnPropertySet_FWD_DEFINED__ */


#ifndef __ITrnPropertiesArchive_FWD_DEFINED__
#define __ITrnPropertiesArchive_FWD_DEFINED__
typedef interface ITrnPropertiesArchive ITrnPropertiesArchive;
#endif 	/* __ITrnPropertiesArchive_FWD_DEFINED__ */


#ifndef __ITrnInputModule_FWD_DEFINED__
#define __ITrnInputModule_FWD_DEFINED__
typedef interface ITrnInputModule ITrnInputModule;
#endif 	/* __ITrnInputModule_FWD_DEFINED__ */


#ifndef __ITrnInputModule2_FWD_DEFINED__
#define __ITrnInputModule2_FWD_DEFINED__
typedef interface ITrnInputModule2 ITrnInputModule2;
#endif 	/* __ITrnInputModule2_FWD_DEFINED__ */


#ifndef __ITrnProcessor_FWD_DEFINED__
#define __ITrnProcessor_FWD_DEFINED__
typedef interface ITrnProcessor ITrnProcessor;
#endif 	/* __ITrnProcessor_FWD_DEFINED__ */


#ifndef __ITrnD1Output_FWD_DEFINED__
#define __ITrnD1Output_FWD_DEFINED__
typedef interface ITrnD1Output ITrnD1Output;
#endif 	/* __ITrnD1Output_FWD_DEFINED__ */


#ifndef __ITrnClipAdviseSink_FWD_DEFINED__
#define __ITrnClipAdviseSink_FWD_DEFINED__
typedef interface ITrnClipAdviseSink ITrnClipAdviseSink;
#endif 	/* __ITrnClipAdviseSink_FWD_DEFINED__ */


#ifndef __ITrnClipGrab_FWD_DEFINED__
#define __ITrnClipGrab_FWD_DEFINED__
typedef interface ITrnClipGrab ITrnClipGrab;
#endif 	/* __ITrnClipGrab_FWD_DEFINED__ */


#ifndef __ITrnClipGrab2_FWD_DEFINED__
#define __ITrnClipGrab2_FWD_DEFINED__
typedef interface ITrnClipGrab2 ITrnClipGrab2;
#endif 	/* __ITrnClipGrab2_FWD_DEFINED__ */


#ifndef __ITrnVideoPath_FWD_DEFINED__
#define __ITrnVideoPath_FWD_DEFINED__
typedef interface ITrnVideoPath ITrnVideoPath;
#endif 	/* __ITrnVideoPath_FWD_DEFINED__ */


#ifndef __ITrnEffectsProcessor_FWD_DEFINED__
#define __ITrnEffectsProcessor_FWD_DEFINED__
typedef interface ITrnEffectsProcessor ITrnEffectsProcessor;
#endif 	/* __ITrnEffectsProcessor_FWD_DEFINED__ */


#ifndef __ITrnStillStore_FWD_DEFINED__
#define __ITrnStillStore_FWD_DEFINED__
typedef interface ITrnStillStore ITrnStillStore;
#endif 	/* __ITrnStillStore_FWD_DEFINED__ */


#ifndef __ITrnVideoEncoder_FWD_DEFINED__
#define __ITrnVideoEncoder_FWD_DEFINED__
typedef interface ITrnVideoEncoder ITrnVideoEncoder;
#endif 	/* __ITrnVideoEncoder_FWD_DEFINED__ */


#ifndef __ITrnCompositeEncoder1_FWD_DEFINED__
#define __ITrnCompositeEncoder1_FWD_DEFINED__
typedef interface ITrnCompositeEncoder1 ITrnCompositeEncoder1;
#endif 	/* __ITrnCompositeEncoder1_FWD_DEFINED__ */


#ifndef __ITrnDownstreamProcessor_FWD_DEFINED__
#define __ITrnDownstreamProcessor_FWD_DEFINED__
typedef interface ITrnDownstreamProcessor ITrnDownstreamProcessor;
#endif 	/* __ITrnDownstreamProcessor_FWD_DEFINED__ */


#ifndef __ITrnVideoRouter_FWD_DEFINED__
#define __ITrnVideoRouter_FWD_DEFINED__
typedef interface ITrnVideoRouter ITrnVideoRouter;
#endif 	/* __ITrnVideoRouter_FWD_DEFINED__ */


#ifndef __ITrnVideoSwitcher_FWD_DEFINED__
#define __ITrnVideoSwitcher_FWD_DEFINED__
typedef interface ITrnVideoSwitcher ITrnVideoSwitcher;
#endif 	/* __ITrnVideoSwitcher_FWD_DEFINED__ */


#ifndef __ITrnKeyPriorityCompositor_FWD_DEFINED__
#define __ITrnKeyPriorityCompositor_FWD_DEFINED__
typedef interface ITrnKeyPriorityCompositor ITrnKeyPriorityCompositor;
#endif 	/* __ITrnKeyPriorityCompositor_FWD_DEFINED__ */


#ifndef __ITrnChromaKeyer_FWD_DEFINED__
#define __ITrnChromaKeyer_FWD_DEFINED__
typedef interface ITrnChromaKeyer ITrnChromaKeyer;
#endif 	/* __ITrnChromaKeyer_FWD_DEFINED__ */


#ifndef __ITrnRecursiveEffectsGenerator_FWD_DEFINED__
#define __ITrnRecursiveEffectsGenerator_FWD_DEFINED__
typedef interface ITrnRecursiveEffectsGenerator ITrnRecursiveEffectsGenerator;
#endif 	/* __ITrnRecursiveEffectsGenerator_FWD_DEFINED__ */


#ifndef __ITrnGraphicsBuffer_FWD_DEFINED__
#define __ITrnGraphicsBuffer_FWD_DEFINED__
typedef interface ITrnGraphicsBuffer ITrnGraphicsBuffer;
#endif 	/* __ITrnGraphicsBuffer_FWD_DEFINED__ */


#ifndef __ITrnGraphicsEffect_FWD_DEFINED__
#define __ITrnGraphicsEffect_FWD_DEFINED__
typedef interface ITrnGraphicsEffect ITrnGraphicsEffect;
#endif 	/* __ITrnGraphicsEffect_FWD_DEFINED__ */


#ifndef __ITrnControlAdviseSink_FWD_DEFINED__
#define __ITrnControlAdviseSink_FWD_DEFINED__
typedef interface ITrnControlAdviseSink ITrnControlAdviseSink;
#endif 	/* __ITrnControlAdviseSink_FWD_DEFINED__ */


#ifndef __ITrnEnumControls_FWD_DEFINED__
#define __ITrnEnumControls_FWD_DEFINED__
typedef interface ITrnEnumControls ITrnEnumControls;
#endif 	/* __ITrnEnumControls_FWD_DEFINED__ */


#ifndef __ITrnExternalControlPanel_FWD_DEFINED__
#define __ITrnExternalControlPanel_FWD_DEFINED__
typedef interface ITrnExternalControlPanel ITrnExternalControlPanel;
#endif 	/* __ITrnExternalControlPanel_FWD_DEFINED__ */


#ifndef __ITrnSerialAdviseSink_FWD_DEFINED__
#define __ITrnSerialAdviseSink_FWD_DEFINED__
typedef interface ITrnSerialAdviseSink ITrnSerialAdviseSink;
#endif 	/* __ITrnSerialAdviseSink_FWD_DEFINED__ */


#ifndef __ITrnSerialPort_FWD_DEFINED__
#define __ITrnSerialPort_FWD_DEFINED__
typedef interface ITrnSerialPort ITrnSerialPort;
#endif 	/* __ITrnSerialPort_FWD_DEFINED__ */


#ifndef __ITrnTimeCodeReader_FWD_DEFINED__
#define __ITrnTimeCodeReader_FWD_DEFINED__
typedef interface ITrnTimeCodeReader ITrnTimeCodeReader;
#endif 	/* __ITrnTimeCodeReader_FWD_DEFINED__ */


#ifndef __ITrnTimeCodeGenerator_FWD_DEFINED__
#define __ITrnTimeCodeGenerator_FWD_DEFINED__
typedef interface ITrnTimeCodeGenerator ITrnTimeCodeGenerator;
#endif 	/* __ITrnTimeCodeGenerator_FWD_DEFINED__ */


#ifndef __ITrnTimeCodeAdviseSink_FWD_DEFINED__
#define __ITrnTimeCodeAdviseSink_FWD_DEFINED__
typedef interface ITrnTimeCodeAdviseSink ITrnTimeCodeAdviseSink;
#endif 	/* __ITrnTimeCodeAdviseSink_FWD_DEFINED__ */


#ifndef __ITrnGPIInputOutput_FWD_DEFINED__
#define __ITrnGPIInputOutput_FWD_DEFINED__
typedef interface ITrnGPIInputOutput ITrnGPIInputOutput;
#endif 	/* __ITrnGPIInputOutput_FWD_DEFINED__ */


#ifndef __ITrnSimpleAudioInput_FWD_DEFINED__
#define __ITrnSimpleAudioInput_FWD_DEFINED__
typedef interface ITrnSimpleAudioInput ITrnSimpleAudioInput;
#endif 	/* __ITrnSimpleAudioInput_FWD_DEFINED__ */


#ifndef __ITrnSimpleAudioAdviseSink_FWD_DEFINED__
#define __ITrnSimpleAudioAdviseSink_FWD_DEFINED__
typedef interface ITrnSimpleAudioAdviseSink ITrnSimpleAudioAdviseSink;
#endif 	/* __ITrnSimpleAudioAdviseSink_FWD_DEFINED__ */


#ifndef __ITrnSimpleAudio_FWD_DEFINED__
#define __ITrnSimpleAudio_FWD_DEFINED__
typedef interface ITrnSimpleAudio ITrnSimpleAudio;
#endif 	/* __ITrnSimpleAudio_FWD_DEFINED__ */


#ifndef __ITrnBASAudioInput_FWD_DEFINED__
#define __ITrnBASAudioInput_FWD_DEFINED__
typedef interface ITrnBASAudioInput ITrnBASAudioInput;
#endif 	/* __ITrnBASAudioInput_FWD_DEFINED__ */


/* header files for imported files */
#include "wtypes.h"
#include "unknwn.h"
#include "objidl.h"
#include "oleidl.h"
#include "autoct.h"
#include "trnoem.h"
#include "gxlate.h"

void __RPC_FAR * __RPC_USER MIDL_user_allocate(size_t);
void __RPC_USER MIDL_user_free( void __RPC_FAR * ); 

/****************************************
 * Generated header for interface: __MIDL_itf_trnity_0000
 * at Tue Nov 23 05:28:37 1999
 * using MIDL 3.01.75
 ****************************************/
/* [local] */ 































#define OBJREF_TRINITY_FACTORY     L"clsid:c5005872-ab3b-11ce-8468-0000b468276b:"
#define OBJREF_TRINITY_SYSTEM(n)   OBJREF_TRINITY_FACTORY L"!" L#n
#define OBJREF_TRINITY_ADDON(n,m)  OBJREF_TRINITY_SYSTEM(n) L"!" L#m


extern RPC_IF_HANDLE __MIDL_itf_trnity_0000_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_trnity_0000_v0_0_s_ifspec;

#ifndef __ITrnItemContainer_INTERFACE_DEFINED__
#define __ITrnItemContainer_INTERFACE_DEFINED__

/****************************************
 * Generated header for interface: ITrnItemContainer
 * at Tue Nov 23 05:28:37 1999
 * using MIDL 3.01.75
 ****************************************/
/* [unique][uuid][object][local] */ 



EXTERN_C const IID IID_ITrnItemContainer;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    interface DECLSPEC_UUID("8335e7eb-ab3b-11ce-8468-0000b468276b")
    ITrnItemContainer : public IOleItemContainer
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE GetMoniker( 
            /* [in] */ IUnknown __RPC_FAR *pItem,
            /* [in] */ DWORD dwWhichMoniker,
            /* [out] */ IMoniker __RPC_FAR *__RPC_FAR *ppMk) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct ITrnItemContainerVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            ITrnItemContainer __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            ITrnItemContainer __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            ITrnItemContainer __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *ParseDisplayName )( 
            ITrnItemContainer __RPC_FAR * This,
            /* [unique][in] */ IBindCtx __RPC_FAR *pbc,
            /* [in] */ LPOLESTR pszDisplayName,
            /* [out] */ ULONG __RPC_FAR *pchEaten,
            /* [out] */ IMoniker __RPC_FAR *__RPC_FAR *ppmkOut);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *EnumObjects )( 
            ITrnItemContainer __RPC_FAR * This,
            /* [in] */ DWORD grfFlags,
            /* [out] */ IEnumUnknown __RPC_FAR *__RPC_FAR *ppenum);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *LockContainer )( 
            ITrnItemContainer __RPC_FAR * This,
            /* [in] */ BOOL fLock);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetObject )( 
            ITrnItemContainer __RPC_FAR * This,
            /* [in] */ LPOLESTR pszItem,
            /* [in] */ DWORD dwSpeedNeeded,
            /* [unique][in] */ IBindCtx __RPC_FAR *pbc,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetObjectStorage )( 
            ITrnItemContainer __RPC_FAR * This,
            /* [in] */ LPOLESTR pszItem,
            /* [unique][in] */ IBindCtx __RPC_FAR *pbc,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvStorage);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *IsRunning )( 
            ITrnItemContainer __RPC_FAR * This,
            /* [in] */ LPOLESTR pszItem);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetMoniker )( 
            ITrnItemContainer __RPC_FAR * This,
            /* [in] */ IUnknown __RPC_FAR *pItem,
            /* [in] */ DWORD dwWhichMoniker,
            /* [out] */ IMoniker __RPC_FAR *__RPC_FAR *ppMk);
        
        END_INTERFACE
    } ITrnItemContainerVtbl;

    interface ITrnItemContainer
    {
        CONST_VTBL struct ITrnItemContainerVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ITrnItemContainer_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define ITrnItemContainer_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define ITrnItemContainer_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define ITrnItemContainer_ParseDisplayName(This,pbc,pszDisplayName,pchEaten,ppmkOut)	\
    (This)->lpVtbl -> ParseDisplayName(This,pbc,pszDisplayName,pchEaten,ppmkOut)


#define ITrnItemContainer_EnumObjects(This,grfFlags,ppenum)	\
    (This)->lpVtbl -> EnumObjects(This,grfFlags,ppenum)

#define ITrnItemContainer_LockContainer(This,fLock)	\
    (This)->lpVtbl -> LockContainer(This,fLock)


#define ITrnItemContainer_GetObject(This,pszItem,dwSpeedNeeded,pbc,riid,ppvObject)	\
    (This)->lpVtbl -> GetObject(This,pszItem,dwSpeedNeeded,pbc,riid,ppvObject)

#define ITrnItemContainer_GetObjectStorage(This,pszItem,pbc,riid,ppvStorage)	\
    (This)->lpVtbl -> GetObjectStorage(This,pszItem,pbc,riid,ppvStorage)

#define ITrnItemContainer_IsRunning(This,pszItem)	\
    (This)->lpVtbl -> IsRunning(This,pszItem)


#define ITrnItemContainer_GetMoniker(This,pItem,dwWhichMoniker,ppMk)	\
    (This)->lpVtbl -> GetMoniker(This,pItem,dwWhichMoniker,ppMk)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE ITrnItemContainer_GetMoniker_Proxy( 
    ITrnItemContainer __RPC_FAR * This,
    /* [in] */ IUnknown __RPC_FAR *pItem,
    /* [in] */ DWORD dwWhichMoniker,
    /* [out] */ IMoniker __RPC_FAR *__RPC_FAR *ppMk);


void __RPC_STUB ITrnItemContainer_GetMoniker_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __ITrnItemContainer_INTERFACE_DEFINED__ */


#ifndef __ITrnVideoTypes_INTERFACE_DEFINED__
#define __ITrnVideoTypes_INTERFACE_DEFINED__

/****************************************
 * Generated header for interface: ITrnVideoTypes
 * at Tue Nov 23 05:28:37 1999
 * using MIDL 3.01.75
 ****************************************/
/* [auto_handle][unique][uuid] */ 


typedef 
enum tagETrnVideoTransmissionFormats
    {	VTFAnaComposite	= 1,
	VTFAnaSVideo	= 2,
	VTFAnaYUV	= 4,
	VTFAnaRGB	= 8,
	VTFDigComposite	= 16,
	VTFDigD2	= VTFDigComposite,
	VTFDigComposite10	= 32,
	VTFDigD3	= VTFDigComposite10,
	VTFDigYUV	= 64,
	VTFDigD1	= VTFDigYUV,
	VTFDigYUV10	= 128,
	VTFDigD5	= VTFDigYUV10,
	VTFDigDV	= 256,
	VTFAnaRGBNoSync	= 512,
	VTFAnaLuma	= 1024,
	VTFAnaLumaNoSync	= 2048,
	VTFAlpha	= 4096,
	VTFAlphaNoSync	= 8192,
	VTFPassThru	= 0x80000000
    }	ETrnVideoTransmissionFormats;

typedef 
enum tagETrnVideoEncodingFormats
    {	VEFNTSC	= 1,
	VEFPAL	= 2,
	VEFPALM	= 4,
	VEFSECAM	= 8
    }	ETrnVideoEncodingFormats;

typedef 
enum tagETrnContentComponents
    {	CCVideo	= 1,
	CCAudio1	= 2,
	CCAudio2	= 4,
	CCAudio3	= 8,
	CCAudio4	= 16,
	CCAudio	= CCAudio1 | CCAudio2 | CCAudio3 | CCAudio4,
	CCAlpha	= 32
    }	ETrnContentComponents;

typedef 
enum tagETrnRemapModes
    {	RMNormal	= 1,
	RMPallette	= 2,
	RMCorrector	= 4,
	RMPseudoColor	= 8,
	RMColorMap	= 16
    }	ETrnRemapModes;

typedef struct  tagSTrnRect
    {
    WORD left;
    WORD top;
    WORD right;
    WORD bottom;
    }	STrnRect;

typedef 
enum tagETrnFrameAccessMode
    {	FAMAllLines	= 0,
	FAMEvenLines	= FAMAllLines + 1,
	FAMOddLines	= FAMEvenLines + 1,
	FAMNatural	= FAMOddLines + 1
    }	ETrnFrameAccessMode;

typedef struct  tagSTrnRectGrid
    {
    STrnRect Bounds;
    WORD GridX;
    WORD GridY;
    }	STrnRectGrid;

typedef struct  tagSTrnRectGridLimits
    {
    WORD MinLeft;
    WORD MaxLeft;
    WORD MinRight;
    WORD MaxRight;
    WORD GridX;
    WORD MinTop;
    WORD MaxTop;
    WORD MinBot;
    WORD MaxBot;
    WORD GridY;
    }	STrnRectGridLimits;

typedef 
enum tagETrnKPMode
    {	KPMForeground	= 1,
	KPMBackground	= 2,
	KPMLumaThreshold	= 4,
	KPMChromaKey	= 8,
	KPMAlphaThreshold	= 16
    }	ETrnKPMode;

typedef 
enum tagETrnRouterSource
    {	InModule1	= 1,
	InModule2	= InModule1 + 1,
	InModule3	= InModule2 + 1,
	InModule4	= InModule3 + 1,
	InModule5	= InModule4 + 1,
	InModule6	= InModule5 + 1,
	InModule7	= InModule6 + 1,
	InOutModuleMux	= InModule7 + 1,
	SystemOut	= InOutModuleMux + 1
    }	ETrnRouterSource;

typedef 
enum tagETrnCGGrabSource
    {	GSRouter	= 0,
	GSRouterAlpha	= 0x100,
	GSBusA	= 0x200,
	GSBusB	= 0x300,
	GSBusC	= 0x400,
	GSAlpha1	= 0x500,
	GSAlpha2	= 0x600,
	GSDynamic	= 0x700
    }	ETrnCGGrabSource;



extern RPC_IF_HANDLE ITrnVideoTypes_v0_0_c_ifspec;
extern RPC_IF_HANDLE ITrnVideoTypes_v0_0_s_ifspec;
#endif /* __ITrnVideoTypes_INTERFACE_DEFINED__ */

#ifndef __ITrnVideoSystemFactory_INTERFACE_DEFINED__
#define __ITrnVideoSystemFactory_INTERFACE_DEFINED__

/****************************************
 * Generated header for interface: ITrnVideoSystemFactory
 * at Tue Nov 23 05:28:37 1999
 * using MIDL 3.01.75
 ****************************************/
/* [unique][uuid][object][local] */ 



EXTERN_C const IID IID_ITrnVideoSystemFactory;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    interface DECLSPEC_UUID("8335e3e9-ab3b-11ce-8468-0000b468276b")
    ITrnVideoSystemFactory : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE Create( 
            /* [in] */ DWORD systemIndex,
            /* [out] */ ITrnVideoSystem __RPC_FAR *__RPC_FAR *pVidSys) = 0;
        
        virtual DWORD STDMETHODCALLTYPE QueryNumAttachedSystems( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE QuerySystemInfo( 
            /* [in] */ DWORD systemIndex,
            /* [in] */ DWORD systemNameSize,
            /* [out] */ unsigned char __RPC_FAR *pSystemName) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE CreateConnection( 
            /* [in] */ DWORD systemIndex,
            /* [out] */ ITrnConnection __RPC_FAR *__RPC_FAR *pConn) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct ITrnVideoSystemFactoryVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            ITrnVideoSystemFactory __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            ITrnVideoSystemFactory __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            ITrnVideoSystemFactory __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Create )( 
            ITrnVideoSystemFactory __RPC_FAR * This,
            /* [in] */ DWORD systemIndex,
            /* [out] */ ITrnVideoSystem __RPC_FAR *__RPC_FAR *pVidSys);
        
        DWORD ( STDMETHODCALLTYPE __RPC_FAR *QueryNumAttachedSystems )( 
            ITrnVideoSystemFactory __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QuerySystemInfo )( 
            ITrnVideoSystemFactory __RPC_FAR * This,
            /* [in] */ DWORD systemIndex,
            /* [in] */ DWORD systemNameSize,
            /* [out] */ unsigned char __RPC_FAR *pSystemName);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *CreateConnection )( 
            ITrnVideoSystemFactory __RPC_FAR * This,
            /* [in] */ DWORD systemIndex,
            /* [out] */ ITrnConnection __RPC_FAR *__RPC_FAR *pConn);
        
        END_INTERFACE
    } ITrnVideoSystemFactoryVtbl;

    interface ITrnVideoSystemFactory
    {
        CONST_VTBL struct ITrnVideoSystemFactoryVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ITrnVideoSystemFactory_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define ITrnVideoSystemFactory_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define ITrnVideoSystemFactory_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define ITrnVideoSystemFactory_Create(This,systemIndex,pVidSys)	\
    (This)->lpVtbl -> Create(This,systemIndex,pVidSys)

#define ITrnVideoSystemFactory_QueryNumAttachedSystems(This)	\
    (This)->lpVtbl -> QueryNumAttachedSystems(This)

#define ITrnVideoSystemFactory_QuerySystemInfo(This,systemIndex,systemNameSize,pSystemName)	\
    (This)->lpVtbl -> QuerySystemInfo(This,systemIndex,systemNameSize,pSystemName)

#define ITrnVideoSystemFactory_CreateConnection(This,systemIndex,pConn)	\
    (This)->lpVtbl -> CreateConnection(This,systemIndex,pConn)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE ITrnVideoSystemFactory_Create_Proxy( 
    ITrnVideoSystemFactory __RPC_FAR * This,
    /* [in] */ DWORD systemIndex,
    /* [out] */ ITrnVideoSystem __RPC_FAR *__RPC_FAR *pVidSys);


void __RPC_STUB ITrnVideoSystemFactory_Create_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


DWORD STDMETHODCALLTYPE ITrnVideoSystemFactory_QueryNumAttachedSystems_Proxy( 
    ITrnVideoSystemFactory __RPC_FAR * This);


void __RPC_STUB ITrnVideoSystemFactory_QueryNumAttachedSystems_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE ITrnVideoSystemFactory_QuerySystemInfo_Proxy( 
    ITrnVideoSystemFactory __RPC_FAR * This,
    /* [in] */ DWORD systemIndex,
    /* [in] */ DWORD systemNameSize,
    /* [out] */ unsigned char __RPC_FAR *pSystemName);


void __RPC_STUB ITrnVideoSystemFactory_QuerySystemInfo_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE ITrnVideoSystemFactory_CreateConnection_Proxy( 
    ITrnVideoSystemFactory __RPC_FAR * This,
    /* [in] */ DWORD systemIndex,
    /* [out] */ ITrnConnection __RPC_FAR *__RPC_FAR *pConn);


void __RPC_STUB ITrnVideoSystemFactory_CreateConnection_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __ITrnVideoSystemFactory_INTERFACE_DEFINED__ */


#ifndef __ITrnVideoSystemFactory2_INTERFACE_DEFINED__
#define __ITrnVideoSystemFactory2_INTERFACE_DEFINED__

/****************************************
 * Generated header for interface: ITrnVideoSystemFactory2
 * at Tue Nov 23 05:28:37 1999
 * using MIDL 3.01.75
 ****************************************/
/* [unique][uuid][object][local] */ 



EXTERN_C const IID IID_ITrnVideoSystemFactory2;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    interface DECLSPEC_UUID("8335e63e-ab3b-11ce-8468-0000b468276b")
    ITrnVideoSystemFactory2 : public ITrnVideoSystemFactory
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE CreateConnectionEx( 
            /* [in] */ DWORD systemIndex,
            /* [in] */ DWORD dwOptions,
            /* [out] */ ITrnConnection __RPC_FAR *__RPC_FAR *pConn) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetConnectionStatus( 
            /* [in] */ DWORD systemIndex) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct ITrnVideoSystemFactory2Vtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            ITrnVideoSystemFactory2 __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            ITrnVideoSystemFactory2 __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            ITrnVideoSystemFactory2 __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Create )( 
            ITrnVideoSystemFactory2 __RPC_FAR * This,
            /* [in] */ DWORD systemIndex,
            /* [out] */ ITrnVideoSystem __RPC_FAR *__RPC_FAR *pVidSys);
        
        DWORD ( STDMETHODCALLTYPE __RPC_FAR *QueryNumAttachedSystems )( 
            ITrnVideoSystemFactory2 __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QuerySystemInfo )( 
            ITrnVideoSystemFactory2 __RPC_FAR * This,
            /* [in] */ DWORD systemIndex,
            /* [in] */ DWORD systemNameSize,
            /* [out] */ unsigned char __RPC_FAR *pSystemName);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *CreateConnection )( 
            ITrnVideoSystemFactory2 __RPC_FAR * This,
            /* [in] */ DWORD systemIndex,
            /* [out] */ ITrnConnection __RPC_FAR *__RPC_FAR *pConn);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *CreateConnectionEx )( 
            ITrnVideoSystemFactory2 __RPC_FAR * This,
            /* [in] */ DWORD systemIndex,
            /* [in] */ DWORD dwOptions,
            /* [out] */ ITrnConnection __RPC_FAR *__RPC_FAR *pConn);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetConnectionStatus )( 
            ITrnVideoSystemFactory2 __RPC_FAR * This,
            /* [in] */ DWORD systemIndex);
        
        END_INTERFACE
    } ITrnVideoSystemFactory2Vtbl;

    interface ITrnVideoSystemFactory2
    {
        CONST_VTBL struct ITrnVideoSystemFactory2Vtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ITrnVideoSystemFactory2_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define ITrnVideoSystemFactory2_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define ITrnVideoSystemFactory2_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define ITrnVideoSystemFactory2_Create(This,systemIndex,pVidSys)	\
    (This)->lpVtbl -> Create(This,systemIndex,pVidSys)

#define ITrnVideoSystemFactory2_QueryNumAttachedSystems(This)	\
    (This)->lpVtbl -> QueryNumAttachedSystems(This)

#define ITrnVideoSystemFactory2_QuerySystemInfo(This,systemIndex,systemNameSize,pSystemName)	\
    (This)->lpVtbl -> QuerySystemInfo(This,systemIndex,systemNameSize,pSystemName)

#define ITrnVideoSystemFactory2_CreateConnection(This,systemIndex,pConn)	\
    (This)->lpVtbl -> CreateConnection(This,systemIndex,pConn)


#define ITrnVideoSystemFactory2_CreateConnectionEx(This,systemIndex,dwOptions,pConn)	\
    (This)->lpVtbl -> CreateConnectionEx(This,systemIndex,dwOptions,pConn)

#define ITrnVideoSystemFactory2_GetConnectionStatus(This,systemIndex)	\
    (This)->lpVtbl -> GetConnectionStatus(This,systemIndex)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE ITrnVideoSystemFactory2_CreateConnectionEx_Proxy( 
    ITrnVideoSystemFactory2 __RPC_FAR * This,
    /* [in] */ DWORD systemIndex,
    /* [in] */ DWORD dwOptions,
    /* [out] */ ITrnConnection __RPC_FAR *__RPC_FAR *pConn);


void __RPC_STUB ITrnVideoSystemFactory2_CreateConnectionEx_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE ITrnVideoSystemFactory2_GetConnectionStatus_Proxy( 
    ITrnVideoSystemFactory2 __RPC_FAR * This,
    /* [in] */ DWORD systemIndex);


void __RPC_STUB ITrnVideoSystemFactory2_GetConnectionStatus_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __ITrnVideoSystemFactory2_INTERFACE_DEFINED__ */


#ifndef __ITrnModule_INTERFACE_DEFINED__
#define __ITrnModule_INTERFACE_DEFINED__

/****************************************
 * Generated header for interface: ITrnModule
 * at Tue Nov 23 05:28:37 1999
 * using MIDL 3.01.75
 ****************************************/
/* [unique][uuid][object][local] */ 



EXTERN_C const IID IID_ITrnModule;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    interface DECLSPEC_UUID("8335e3e2-ab3b-11ce-8468-0000b468276b")
    ITrnModule : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE QueryProductID( 
            /* [in] */ DWORD bufferSize,
            /* [out] */ DWORD __RPC_FAR *pDeviceId,
            /* [string][out] */ unsigned char __RPC_FAR *pDeviceName) = 0;
        
        virtual DWORD STDMETHODCALLTYPE QuerySlot( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE QueryController( 
            /* [out] */ ITrnAutomationController __RPC_FAR *__RPC_FAR *ppController) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct ITrnModuleVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            ITrnModule __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            ITrnModule __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            ITrnModule __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryProductID )( 
            ITrnModule __RPC_FAR * This,
            /* [in] */ DWORD bufferSize,
            /* [out] */ DWORD __RPC_FAR *pDeviceId,
            /* [string][out] */ unsigned char __RPC_FAR *pDeviceName);
        
        DWORD ( STDMETHODCALLTYPE __RPC_FAR *QuerySlot )( 
            ITrnModule __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryController )( 
            ITrnModule __RPC_FAR * This,
            /* [out] */ ITrnAutomationController __RPC_FAR *__RPC_FAR *ppController);
        
        END_INTERFACE
    } ITrnModuleVtbl;

    interface ITrnModule
    {
        CONST_VTBL struct ITrnModuleVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ITrnModule_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define ITrnModule_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define ITrnModule_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define ITrnModule_QueryProductID(This,bufferSize,pDeviceId,pDeviceName)	\
    (This)->lpVtbl -> QueryProductID(This,bufferSize,pDeviceId,pDeviceName)

#define ITrnModule_QuerySlot(This)	\
    (This)->lpVtbl -> QuerySlot(This)

#define ITrnModule_QueryController(This,ppController)	\
    (This)->lpVtbl -> QueryController(This,ppController)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE ITrnModule_QueryProductID_Proxy( 
    ITrnModule __RPC_FAR * This,
    /* [in] */ DWORD bufferSize,
    /* [out] */ DWORD __RPC_FAR *pDeviceId,
    /* [string][out] */ unsigned char __RPC_FAR *pDeviceName);


void __RPC_STUB ITrnModule_QueryProductID_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


DWORD STDMETHODCALLTYPE ITrnModule_QuerySlot_Proxy( 
    ITrnModule __RPC_FAR * This);


void __RPC_STUB ITrnModule_QuerySlot_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE ITrnModule_QueryController_Proxy( 
    ITrnModule __RPC_FAR * This,
    /* [out] */ ITrnAutomationController __RPC_FAR *__RPC_FAR *ppController);


void __RPC_STUB ITrnModule_QueryController_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __ITrnModule_INTERFACE_DEFINED__ */


#ifndef __ITrnModule2_INTERFACE_DEFINED__
#define __ITrnModule2_INTERFACE_DEFINED__

/****************************************
 * Generated header for interface: ITrnModule2
 * at Tue Nov 23 05:28:37 1999
 * using MIDL 3.01.75
 ****************************************/
/* [unique][uuid][object][local] */ 


typedef 
enum tagETrnModuleFlags
    {	MFVideoBackPanel	= 1,
	MFVideoBackPanelIO	= 2
    }	ETrnModuleFlags;

typedef struct  tagSTrnModuleCharacteristics
    {
    DWORD dwSizeof;
    unsigned int physBus;
    unsigned int physSlot;
    unsigned int logBus;
    unsigned int logSlot;
    unsigned int sizeRAM;
    GUID controlModel;
    DWORD flags;
    }	STrnModuleCharacteristics;


EXTERN_C const IID IID_ITrnModule2;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    interface DECLSPEC_UUID("8335e408-ab3b-11ce-8468-0000b468276b")
    ITrnModule2 : public ITrnModule
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE QueryModuleCharacteristics( 
            /* [in] */ STrnModuleCharacteristics __RPC_FAR *pMC) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct ITrnModule2Vtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            ITrnModule2 __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            ITrnModule2 __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            ITrnModule2 __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryProductID )( 
            ITrnModule2 __RPC_FAR * This,
            /* [in] */ DWORD bufferSize,
            /* [out] */ DWORD __RPC_FAR *pDeviceId,
            /* [string][out] */ unsigned char __RPC_FAR *pDeviceName);
        
        DWORD ( STDMETHODCALLTYPE __RPC_FAR *QuerySlot )( 
            ITrnModule2 __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryController )( 
            ITrnModule2 __RPC_FAR * This,
            /* [out] */ ITrnAutomationController __RPC_FAR *__RPC_FAR *ppController);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryModuleCharacteristics )( 
            ITrnModule2 __RPC_FAR * This,
            /* [in] */ STrnModuleCharacteristics __RPC_FAR *pMC);
        
        END_INTERFACE
    } ITrnModule2Vtbl;

    interface ITrnModule2
    {
        CONST_VTBL struct ITrnModule2Vtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ITrnModule2_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define ITrnModule2_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define ITrnModule2_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define ITrnModule2_QueryProductID(This,bufferSize,pDeviceId,pDeviceName)	\
    (This)->lpVtbl -> QueryProductID(This,bufferSize,pDeviceId,pDeviceName)

#define ITrnModule2_QuerySlot(This)	\
    (This)->lpVtbl -> QuerySlot(This)

#define ITrnModule2_QueryController(This,ppController)	\
    (This)->lpVtbl -> QueryController(This,ppController)


#define ITrnModule2_QueryModuleCharacteristics(This,pMC)	\
    (This)->lpVtbl -> QueryModuleCharacteristics(This,pMC)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE ITrnModule2_QueryModuleCharacteristics_Proxy( 
    ITrnModule2 __RPC_FAR * This,
    /* [in] */ STrnModuleCharacteristics __RPC_FAR *pMC);


void __RPC_STUB ITrnModule2_QueryModuleCharacteristics_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __ITrnModule2_INTERFACE_DEFINED__ */


#ifndef __ITrnDiagnostics_INTERFACE_DEFINED__
#define __ITrnDiagnostics_INTERFACE_DEFINED__

/****************************************
 * Generated header for interface: ITrnDiagnostics
 * at Tue Nov 23 05:28:37 1999
 * using MIDL 3.01.75
 ****************************************/
/* [unique][uuid][object][local] */ 



EXTERN_C const IID IID_ITrnDiagnostics;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    interface DECLSPEC_UUID("8335e3e8-ab3b-11ce-8468-0000b468276b")
    ITrnDiagnostics : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE GetConnection( 
            /* [out] */ ITrnConnection __RPC_FAR *__RPC_FAR *ppConnection) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Echo( 
            WORD blockSize,
            BYTE __RPC_FAR *pInBuffer,
            BYTE __RPC_FAR *pOutBuffer) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetModuleBaseAddress( 
            DWORD __RPC_FAR *pBaseAddr) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE ReadModuleMemory( 
            DWORD sourceAddress,
            DWORD alignment,
            DWORD size,
            LPVOID pBuffer) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE WriteModuleMemory( 
            DWORD destAddress,
            DWORD alignment,
            DWORD size,
            LPVOID pBuffer) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct ITrnDiagnosticsVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            ITrnDiagnostics __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            ITrnDiagnostics __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            ITrnDiagnostics __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetConnection )( 
            ITrnDiagnostics __RPC_FAR * This,
            /* [out] */ ITrnConnection __RPC_FAR *__RPC_FAR *ppConnection);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Echo )( 
            ITrnDiagnostics __RPC_FAR * This,
            WORD blockSize,
            BYTE __RPC_FAR *pInBuffer,
            BYTE __RPC_FAR *pOutBuffer);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetModuleBaseAddress )( 
            ITrnDiagnostics __RPC_FAR * This,
            DWORD __RPC_FAR *pBaseAddr);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *ReadModuleMemory )( 
            ITrnDiagnostics __RPC_FAR * This,
            DWORD sourceAddress,
            DWORD alignment,
            DWORD size,
            LPVOID pBuffer);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *WriteModuleMemory )( 
            ITrnDiagnostics __RPC_FAR * This,
            DWORD destAddress,
            DWORD alignment,
            DWORD size,
            LPVOID pBuffer);
        
        END_INTERFACE
    } ITrnDiagnosticsVtbl;

    interface ITrnDiagnostics
    {
        CONST_VTBL struct ITrnDiagnosticsVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ITrnDiagnostics_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define ITrnDiagnostics_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define ITrnDiagnostics_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define ITrnDiagnostics_GetConnection(This,ppConnection)	\
    (This)->lpVtbl -> GetConnection(This,ppConnection)

#define ITrnDiagnostics_Echo(This,blockSize,pInBuffer,pOutBuffer)	\
    (This)->lpVtbl -> Echo(This,blockSize,pInBuffer,pOutBuffer)

#define ITrnDiagnostics_GetModuleBaseAddress(This,pBaseAddr)	\
    (This)->lpVtbl -> GetModuleBaseAddress(This,pBaseAddr)

#define ITrnDiagnostics_ReadModuleMemory(This,sourceAddress,alignment,size,pBuffer)	\
    (This)->lpVtbl -> ReadModuleMemory(This,sourceAddress,alignment,size,pBuffer)

#define ITrnDiagnostics_WriteModuleMemory(This,destAddress,alignment,size,pBuffer)	\
    (This)->lpVtbl -> WriteModuleMemory(This,destAddress,alignment,size,pBuffer)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE ITrnDiagnostics_GetConnection_Proxy( 
    ITrnDiagnostics __RPC_FAR * This,
    /* [out] */ ITrnConnection __RPC_FAR *__RPC_FAR *ppConnection);


void __RPC_STUB ITrnDiagnostics_GetConnection_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE ITrnDiagnostics_Echo_Proxy( 
    ITrnDiagnostics __RPC_FAR * This,
    WORD blockSize,
    BYTE __RPC_FAR *pInBuffer,
    BYTE __RPC_FAR *pOutBuffer);


void __RPC_STUB ITrnDiagnostics_Echo_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE ITrnDiagnostics_GetModuleBaseAddress_Proxy( 
    ITrnDiagnostics __RPC_FAR * This,
    DWORD __RPC_FAR *pBaseAddr);


void __RPC_STUB ITrnDiagnostics_GetModuleBaseAddress_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE ITrnDiagnostics_ReadModuleMemory_Proxy( 
    ITrnDiagnostics __RPC_FAR * This,
    DWORD sourceAddress,
    DWORD alignment,
    DWORD size,
    LPVOID pBuffer);


void __RPC_STUB ITrnDiagnostics_ReadModuleMemory_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE ITrnDiagnostics_WriteModuleMemory_Proxy( 
    ITrnDiagnostics __RPC_FAR * This,
    DWORD destAddress,
    DWORD alignment,
    DWORD size,
    LPVOID pBuffer);


void __RPC_STUB ITrnDiagnostics_WriteModuleMemory_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __ITrnDiagnostics_INTERFACE_DEFINED__ */


#ifndef __ITrnDiagnostics2_INTERFACE_DEFINED__
#define __ITrnDiagnostics2_INTERFACE_DEFINED__

/****************************************
 * Generated header for interface: ITrnDiagnostics2
 * at Tue Nov 23 05:28:37 1999
 * using MIDL 3.01.75
 ****************************************/
/* [unique][uuid][object][local] */ 



EXTERN_C const IID IID_ITrnDiagnostics2;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    interface DECLSPEC_UUID("8335e415-ab3b-11ce-8468-0000b468276b")
    ITrnDiagnostics2 : public ITrnDiagnostics
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE ReInitialize( void) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct ITrnDiagnostics2Vtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            ITrnDiagnostics2 __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            ITrnDiagnostics2 __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            ITrnDiagnostics2 __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetConnection )( 
            ITrnDiagnostics2 __RPC_FAR * This,
            /* [out] */ ITrnConnection __RPC_FAR *__RPC_FAR *ppConnection);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Echo )( 
            ITrnDiagnostics2 __RPC_FAR * This,
            WORD blockSize,
            BYTE __RPC_FAR *pInBuffer,
            BYTE __RPC_FAR *pOutBuffer);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetModuleBaseAddress )( 
            ITrnDiagnostics2 __RPC_FAR * This,
            DWORD __RPC_FAR *pBaseAddr);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *ReadModuleMemory )( 
            ITrnDiagnostics2 __RPC_FAR * This,
            DWORD sourceAddress,
            DWORD alignment,
            DWORD size,
            LPVOID pBuffer);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *WriteModuleMemory )( 
            ITrnDiagnostics2 __RPC_FAR * This,
            DWORD destAddress,
            DWORD alignment,
            DWORD size,
            LPVOID pBuffer);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *ReInitialize )( 
            ITrnDiagnostics2 __RPC_FAR * This);
        
        END_INTERFACE
    } ITrnDiagnostics2Vtbl;

    interface ITrnDiagnostics2
    {
        CONST_VTBL struct ITrnDiagnostics2Vtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ITrnDiagnostics2_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define ITrnDiagnostics2_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define ITrnDiagnostics2_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define ITrnDiagnostics2_GetConnection(This,ppConnection)	\
    (This)->lpVtbl -> GetConnection(This,ppConnection)

#define ITrnDiagnostics2_Echo(This,blockSize,pInBuffer,pOutBuffer)	\
    (This)->lpVtbl -> Echo(This,blockSize,pInBuffer,pOutBuffer)

#define ITrnDiagnostics2_GetModuleBaseAddress(This,pBaseAddr)	\
    (This)->lpVtbl -> GetModuleBaseAddress(This,pBaseAddr)

#define ITrnDiagnostics2_ReadModuleMemory(This,sourceAddress,alignment,size,pBuffer)	\
    (This)->lpVtbl -> ReadModuleMemory(This,sourceAddress,alignment,size,pBuffer)

#define ITrnDiagnostics2_WriteModuleMemory(This,destAddress,alignment,size,pBuffer)	\
    (This)->lpVtbl -> WriteModuleMemory(This,destAddress,alignment,size,pBuffer)


#define ITrnDiagnostics2_ReInitialize(This)	\
    (This)->lpVtbl -> ReInitialize(This)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE ITrnDiagnostics2_ReInitialize_Proxy( 
    ITrnDiagnostics2 __RPC_FAR * This);


void __RPC_STUB ITrnDiagnostics2_ReInitialize_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __ITrnDiagnostics2_INTERFACE_DEFINED__ */


#ifndef __ITrnVideoSystem_INTERFACE_DEFINED__
#define __ITrnVideoSystem_INTERFACE_DEFINED__

/****************************************
 * Generated header for interface: ITrnVideoSystem
 * at Tue Nov 23 05:28:37 1999
 * using MIDL 3.01.75
 ****************************************/
/* [unique][uuid][object][local] */ 


typedef 
enum tagETrnVSElementType
    {	VEMainBusDevice	= 0,
	VEInputModule	= VEMainBusDevice + 1,
	VEDSInOutModule	= VEInputModule + 1,
	VESerialPort	= VEDSInOutModule + 1,
	VEAudioMixer	= VESerialPort + 1,
	VEControlPanel	= VEAudioMixer + 1,
	VERouter	= VEControlPanel + 1,
	VESwitcher	= VERouter + 1
    }	ETrnVSElementType;

typedef struct  tagTrnSystemInfo
    {
    unsigned char __RPC_FAR *pszSystemName;
    DWORD cchSystemName;
    DWORD dwCoordType;
    DWORD dwCoordBuild;
    DWORD dwConnectionType;
    DWORD dwConnectionVersion;
    ETrnVideoEncodingFormats efSystemFormat;
    }	STrnSystemInfo;

typedef struct  tagSTrnBuildErrorInfo
    {
    HRESULT m_createResult;
    DWORD m_lastSocket;
    DWORD m_lastCommand;
    }	STrnBuildErrorInfo;


EXTERN_C const IID IID_ITrnVideoSystem;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    interface DECLSPEC_UUID("8335e3d3-ab3b-11ce-8468-0000b468276b")
    ITrnVideoSystem : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE QuerySystemInfo( 
            /* [out] */ STrnSystemInfo __RPC_FAR *pInfo) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE QueryController( 
            /* [out] */ ITrnAutomationController __RPC_FAR *__RPC_FAR *ppController) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE EnumElements( 
            /* [in] */ ETrnVSElementType vtype,
            /* [out] */ IEnumUnknown __RPC_FAR *__RPC_FAR *ppenum) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE CreateAddOn( 
            REFCLSID rclsid,
            LPUNKNOWN pUnkOuter,
            DWORD dwClsContext,
            REFIID riid,
            LPVOID __RPC_FAR *ppv) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE QueryBuildErrorInfo( 
            ETrnVSElementType vtype,
            unsigned int slot,
            unsigned int count,
            unsigned int __RPC_FAR *countOut,
            STrnBuildErrorInfo __RPC_FAR *pErrorInfo) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct ITrnVideoSystemVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            ITrnVideoSystem __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            ITrnVideoSystem __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            ITrnVideoSystem __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QuerySystemInfo )( 
            ITrnVideoSystem __RPC_FAR * This,
            /* [out] */ STrnSystemInfo __RPC_FAR *pInfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryController )( 
            ITrnVideoSystem __RPC_FAR * This,
            /* [out] */ ITrnAutomationController __RPC_FAR *__RPC_FAR *ppController);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *EnumElements )( 
            ITrnVideoSystem __RPC_FAR * This,
            /* [in] */ ETrnVSElementType vtype,
            /* [out] */ IEnumUnknown __RPC_FAR *__RPC_FAR *ppenum);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *CreateAddOn )( 
            ITrnVideoSystem __RPC_FAR * This,
            REFCLSID rclsid,
            LPUNKNOWN pUnkOuter,
            DWORD dwClsContext,
            REFIID riid,
            LPVOID __RPC_FAR *ppv);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryBuildErrorInfo )( 
            ITrnVideoSystem __RPC_FAR * This,
            ETrnVSElementType vtype,
            unsigned int slot,
            unsigned int count,
            unsigned int __RPC_FAR *countOut,
            STrnBuildErrorInfo __RPC_FAR *pErrorInfo);
        
        END_INTERFACE
    } ITrnVideoSystemVtbl;

    interface ITrnVideoSystem
    {
        CONST_VTBL struct ITrnVideoSystemVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ITrnVideoSystem_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define ITrnVideoSystem_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define ITrnVideoSystem_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define ITrnVideoSystem_QuerySystemInfo(This,pInfo)	\
    (This)->lpVtbl -> QuerySystemInfo(This,pInfo)

#define ITrnVideoSystem_QueryController(This,ppController)	\
    (This)->lpVtbl -> QueryController(This,ppController)

#define ITrnVideoSystem_EnumElements(This,vtype,ppenum)	\
    (This)->lpVtbl -> EnumElements(This,vtype,ppenum)

#define ITrnVideoSystem_CreateAddOn(This,rclsid,pUnkOuter,dwClsContext,riid,ppv)	\
    (This)->lpVtbl -> CreateAddOn(This,rclsid,pUnkOuter,dwClsContext,riid,ppv)

#define ITrnVideoSystem_QueryBuildErrorInfo(This,vtype,slot,count,countOut,pErrorInfo)	\
    (This)->lpVtbl -> QueryBuildErrorInfo(This,vtype,slot,count,countOut,pErrorInfo)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE ITrnVideoSystem_QuerySystemInfo_Proxy( 
    ITrnVideoSystem __RPC_FAR * This,
    /* [out] */ STrnSystemInfo __RPC_FAR *pInfo);


void __RPC_STUB ITrnVideoSystem_QuerySystemInfo_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE ITrnVideoSystem_QueryController_Proxy( 
    ITrnVideoSystem __RPC_FAR * This,
    /* [out] */ ITrnAutomationController __RPC_FAR *__RPC_FAR *ppController);


void __RPC_STUB ITrnVideoSystem_QueryController_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE ITrnVideoSystem_EnumElements_Proxy( 
    ITrnVideoSystem __RPC_FAR * This,
    /* [in] */ ETrnVSElementType vtype,
    /* [out] */ IEnumUnknown __RPC_FAR *__RPC_FAR *ppenum);


void __RPC_STUB ITrnVideoSystem_EnumElements_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE ITrnVideoSystem_CreateAddOn_Proxy( 
    ITrnVideoSystem __RPC_FAR * This,
    REFCLSID rclsid,
    LPUNKNOWN pUnkOuter,
    DWORD dwClsContext,
    REFIID riid,
    LPVOID __RPC_FAR *ppv);


void __RPC_STUB ITrnVideoSystem_CreateAddOn_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE ITrnVideoSystem_QueryBuildErrorInfo_Proxy( 
    ITrnVideoSystem __RPC_FAR * This,
    ETrnVSElementType vtype,
    unsigned int slot,
    unsigned int count,
    unsigned int __RPC_FAR *countOut,
    STrnBuildErrorInfo __RPC_FAR *pErrorInfo);


void __RPC_STUB ITrnVideoSystem_QueryBuildErrorInfo_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __ITrnVideoSystem_INTERFACE_DEFINED__ */


#ifndef __ITrnModuleProxy_INTERFACE_DEFINED__
#define __ITrnModuleProxy_INTERFACE_DEFINED__

/****************************************
 * Generated header for interface: ITrnModuleProxy
 * at Tue Nov 23 05:28:37 1999
 * using MIDL 3.01.75
 ****************************************/
/* [unique][uuid][object][local] */ 



EXTERN_C const IID IID_ITrnModuleProxy;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    interface DECLSPEC_UUID("8335e419-ab3b-11ce-8468-0000b468276b")
    ITrnModuleProxy : public ITrnConnectionClient
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE Connect( 
            /* [in] */ ITrnConnection __RPC_FAR *pConnection,
            /* [in] */ ITrnAutomationController __RPC_FAR *pController,
            /* [in] */ DWORD socketNum,
            /* [in] */ DWORD slotNumber,
            /* [in] */ DWORD moduleId,
            /* [in] */ HKEY hkModuleKey,
            /* [in] */ HKEY hkSystemKey) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct ITrnModuleProxyVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            ITrnModuleProxy __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            ITrnModuleProxy __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            ITrnModuleProxy __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *OnAsyncReceive )( 
            ITrnModuleProxy __RPC_FAR * This,
            /* [in] */ LPVOID pBuffer,
            /* [in] */ DWORD socketNumber,
            /* [in] */ BOOL repeated);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *OnAsyncMessage )( 
            ITrnModuleProxy __RPC_FAR * This,
            /* [in] */ PSTrnMessageHeader pBuffer,
            /* [in] */ BOOL repeated);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *OnAsyncError )( 
            ITrnModuleProxy __RPC_FAR * This,
            /* [in] */ LPVOID pBuffer,
            /* [in] */ DWORD socketNumber,
            /* [in] */ DWORD ErrCode);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetupSyncImageBlock )( 
            ITrnModuleProxy __RPC_FAR * This,
            /* [in] */ DWORD socketNumber,
            /* [in] */ DWORD offset,
            /* [in] */ DWORD remainder,
            /* [out][in] */ LPDWORD blockSize);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Connect )( 
            ITrnModuleProxy __RPC_FAR * This,
            /* [in] */ ITrnConnection __RPC_FAR *pConnection,
            /* [in] */ ITrnAutomationController __RPC_FAR *pController,
            /* [in] */ DWORD socketNum,
            /* [in] */ DWORD slotNumber,
            /* [in] */ DWORD moduleId,
            /* [in] */ HKEY hkModuleKey,
            /* [in] */ HKEY hkSystemKey);
        
        END_INTERFACE
    } ITrnModuleProxyVtbl;

    interface ITrnModuleProxy
    {
        CONST_VTBL struct ITrnModuleProxyVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ITrnModuleProxy_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define ITrnModuleProxy_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define ITrnModuleProxy_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define ITrnModuleProxy_OnAsyncReceive(This,pBuffer,socketNumber,repeated)	\
    (This)->lpVtbl -> OnAsyncReceive(This,pBuffer,socketNumber,repeated)

#define ITrnModuleProxy_OnAsyncMessage(This,pBuffer,repeated)	\
    (This)->lpVtbl -> OnAsyncMessage(This,pBuffer,repeated)

#define ITrnModuleProxy_OnAsyncError(This,pBuffer,socketNumber,ErrCode)	\
    (This)->lpVtbl -> OnAsyncError(This,pBuffer,socketNumber,ErrCode)

#define ITrnModuleProxy_SetupSyncImageBlock(This,socketNumber,offset,remainder,blockSize)	\
    (This)->lpVtbl -> SetupSyncImageBlock(This,socketNumber,offset,remainder,blockSize)


#define ITrnModuleProxy_Connect(This,pConnection,pController,socketNum,slotNumber,moduleId,hkModuleKey,hkSystemKey)	\
    (This)->lpVtbl -> Connect(This,pConnection,pController,socketNum,slotNumber,moduleId,hkModuleKey,hkSystemKey)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE ITrnModuleProxy_Connect_Proxy( 
    ITrnModuleProxy __RPC_FAR * This,
    /* [in] */ ITrnConnection __RPC_FAR *pConnection,
    /* [in] */ ITrnAutomationController __RPC_FAR *pController,
    /* [in] */ DWORD socketNum,
    /* [in] */ DWORD slotNumber,
    /* [in] */ DWORD moduleId,
    /* [in] */ HKEY hkModuleKey,
    /* [in] */ HKEY hkSystemKey);


void __RPC_STUB ITrnModuleProxy_Connect_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __ITrnModuleProxy_INTERFACE_DEFINED__ */


#ifndef __ITrnCoreAddOn_INTERFACE_DEFINED__
#define __ITrnCoreAddOn_INTERFACE_DEFINED__

/****************************************
 * Generated header for interface: ITrnCoreAddOn
 * at Tue Nov 23 05:28:37 1999
 * using MIDL 3.01.75
 ****************************************/
/* [unique][uuid][object][local] */ 



EXTERN_C const IID IID_ITrnCoreAddOn;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    interface DECLSPEC_UUID("8335e3f7-ab3b-11ce-8468-0000b468276b")
    ITrnCoreAddOn : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE Connect( 
            /* [in] */ ITrnVideoSystem __RPC_FAR *pSystem,
            /* [in] */ ITrnAutomationController __RPC_FAR *pController,
            /* [in] */ ITrnConnection __RPC_FAR *pConnection) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct ITrnCoreAddOnVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            ITrnCoreAddOn __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            ITrnCoreAddOn __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            ITrnCoreAddOn __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Connect )( 
            ITrnCoreAddOn __RPC_FAR * This,
            /* [in] */ ITrnVideoSystem __RPC_FAR *pSystem,
            /* [in] */ ITrnAutomationController __RPC_FAR *pController,
            /* [in] */ ITrnConnection __RPC_FAR *pConnection);
        
        END_INTERFACE
    } ITrnCoreAddOnVtbl;

    interface ITrnCoreAddOn
    {
        CONST_VTBL struct ITrnCoreAddOnVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ITrnCoreAddOn_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define ITrnCoreAddOn_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define ITrnCoreAddOn_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define ITrnCoreAddOn_Connect(This,pSystem,pController,pConnection)	\
    (This)->lpVtbl -> Connect(This,pSystem,pController,pConnection)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE ITrnCoreAddOn_Connect_Proxy( 
    ITrnCoreAddOn __RPC_FAR * This,
    /* [in] */ ITrnVideoSystem __RPC_FAR *pSystem,
    /* [in] */ ITrnAutomationController __RPC_FAR *pController,
    /* [in] */ ITrnConnection __RPC_FAR *pConnection);


void __RPC_STUB ITrnCoreAddOn_Connect_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __ITrnCoreAddOn_INTERFACE_DEFINED__ */


#ifndef __ITrnPropertySet_INTERFACE_DEFINED__
#define __ITrnPropertySet_INTERFACE_DEFINED__

/****************************************
 * Generated header for interface: ITrnPropertySet
 * at Tue Nov 23 05:28:37 1999
 * using MIDL 3.01.75
 ****************************************/
/* [unique][uuid][object][local] */ 


typedef int ETrnProperty;

typedef struct  tagSTrnProperty
    {
    ETrnProperty propName;
    LONG propValue;
    }	STrnProperty;

typedef 
enum tagETrnPropertyFlags
    {	IPFDefault	= 0,
	IPFReadOnly	= 1,
	IPFAnimate	= 2,
	IPFNoSave	= 4,
	IPFContent	= 8,
	IPFDerived	= 16,
	IPFCalibration	= 32,
	IPFUndefined	= 64
    }	ETrnPropertyFlags;

typedef struct  tagSTrnPropertyInfo
    {
    ETrnProperty propName;
    ETrnPropertyFlags propFlags;
    LONG lowerLimit;
    LONG upperLimit;
    LONG nominalValue;
    LONG uiScaleNum;
    LONG uiScaleDenom;
    }	STrnPropertyInfo;


EXTERN_C const IID IID_ITrnPropertySet;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    interface DECLSPEC_UUID("8335e401-ab3b-11ce-8468-0000b468276b")
    ITrnPropertySet : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE QueryNumProps( 
            unsigned int __RPC_FAR *pNumProps) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE EnumProperties( 
            /* [in] */ unsigned int startingIndex,
            /* [in] */ unsigned int numToReturn,
            /* [out] */ STrnProperty __RPC_FAR *pProps,
            /* [out] */ STrnPropertyInfo __RPC_FAR *pPropInfo) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE AddProps( 
            /* [in] */ unsigned int numProps,
            /* [in] */ STrnPropertyInfo __RPC_FAR *pPropInfo) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE QueryPropertyInfo( 
            /* [in] */ ETrnProperty prop,
            /* [out] */ STrnPropertyInfo __RPC_FAR *pInfo) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE QueryPropertyValue( 
            /* [in] */ ETrnProperty prop,
            /* [out] */ LONG __RPC_FAR *pValue) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE QueryProperties( 
            /* [in] */ unsigned int numProps,
            /* [out][in] */ STrnProperty __RPC_FAR *pProps) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE QueryPropertiesInfo( 
            /* [in] */ unsigned int numProps,
            /* [out][in] */ STrnPropertyInfo __RPC_FAR *pPropInfo) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetProperties( 
            /* [in] */ unsigned int numProperties,
            /* [in] */ STrnProperty __RPC_FAR *pProps) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetProperty( 
            /* [in] */ STrnTimeType __RPC_FAR *pTime,
            /* [in] */ ETrnProperty prop,
            /* [in] */ STrnPlayList __RPC_FAR *pPl) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Merge( 
            /* [in] */ ITrnPropertySet __RPC_FAR *pPropsToMerge,
            /* [in] */ ETrnPropertyFlags filterFlags) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct ITrnPropertySetVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            ITrnPropertySet __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            ITrnPropertySet __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            ITrnPropertySet __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryNumProps )( 
            ITrnPropertySet __RPC_FAR * This,
            unsigned int __RPC_FAR *pNumProps);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *EnumProperties )( 
            ITrnPropertySet __RPC_FAR * This,
            /* [in] */ unsigned int startingIndex,
            /* [in] */ unsigned int numToReturn,
            /* [out] */ STrnProperty __RPC_FAR *pProps,
            /* [out] */ STrnPropertyInfo __RPC_FAR *pPropInfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *AddProps )( 
            ITrnPropertySet __RPC_FAR * This,
            /* [in] */ unsigned int numProps,
            /* [in] */ STrnPropertyInfo __RPC_FAR *pPropInfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryPropertyInfo )( 
            ITrnPropertySet __RPC_FAR * This,
            /* [in] */ ETrnProperty prop,
            /* [out] */ STrnPropertyInfo __RPC_FAR *pInfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryPropertyValue )( 
            ITrnPropertySet __RPC_FAR * This,
            /* [in] */ ETrnProperty prop,
            /* [out] */ LONG __RPC_FAR *pValue);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryProperties )( 
            ITrnPropertySet __RPC_FAR * This,
            /* [in] */ unsigned int numProps,
            /* [out][in] */ STrnProperty __RPC_FAR *pProps);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryPropertiesInfo )( 
            ITrnPropertySet __RPC_FAR * This,
            /* [in] */ unsigned int numProps,
            /* [out][in] */ STrnPropertyInfo __RPC_FAR *pPropInfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetProperties )( 
            ITrnPropertySet __RPC_FAR * This,
            /* [in] */ unsigned int numProperties,
            /* [in] */ STrnProperty __RPC_FAR *pProps);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetProperty )( 
            ITrnPropertySet __RPC_FAR * This,
            /* [in] */ STrnTimeType __RPC_FAR *pTime,
            /* [in] */ ETrnProperty prop,
            /* [in] */ STrnPlayList __RPC_FAR *pPl);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Merge )( 
            ITrnPropertySet __RPC_FAR * This,
            /* [in] */ ITrnPropertySet __RPC_FAR *pPropsToMerge,
            /* [in] */ ETrnPropertyFlags filterFlags);
        
        END_INTERFACE
    } ITrnPropertySetVtbl;

    interface ITrnPropertySet
    {
        CONST_VTBL struct ITrnPropertySetVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ITrnPropertySet_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define ITrnPropertySet_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define ITrnPropertySet_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define ITrnPropertySet_QueryNumProps(This,pNumProps)	\
    (This)->lpVtbl -> QueryNumProps(This,pNumProps)

#define ITrnPropertySet_EnumProperties(This,startingIndex,numToReturn,pProps,pPropInfo)	\
    (This)->lpVtbl -> EnumProperties(This,startingIndex,numToReturn,pProps,pPropInfo)

#define ITrnPropertySet_AddProps(This,numProps,pPropInfo)	\
    (This)->lpVtbl -> AddProps(This,numProps,pPropInfo)

#define ITrnPropertySet_QueryPropertyInfo(This,prop,pInfo)	\
    (This)->lpVtbl -> QueryPropertyInfo(This,prop,pInfo)

#define ITrnPropertySet_QueryPropertyValue(This,prop,pValue)	\
    (This)->lpVtbl -> QueryPropertyValue(This,prop,pValue)

#define ITrnPropertySet_QueryProperties(This,numProps,pProps)	\
    (This)->lpVtbl -> QueryProperties(This,numProps,pProps)

#define ITrnPropertySet_QueryPropertiesInfo(This,numProps,pPropInfo)	\
    (This)->lpVtbl -> QueryPropertiesInfo(This,numProps,pPropInfo)

#define ITrnPropertySet_SetProperties(This,numProperties,pProps)	\
    (This)->lpVtbl -> SetProperties(This,numProperties,pProps)

#define ITrnPropertySet_SetProperty(This,pTime,prop,pPl)	\
    (This)->lpVtbl -> SetProperty(This,pTime,prop,pPl)

#define ITrnPropertySet_Merge(This,pPropsToMerge,filterFlags)	\
    (This)->lpVtbl -> Merge(This,pPropsToMerge,filterFlags)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE ITrnPropertySet_QueryNumProps_Proxy( 
    ITrnPropertySet __RPC_FAR * This,
    unsigned int __RPC_FAR *pNumProps);


void __RPC_STUB ITrnPropertySet_QueryNumProps_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE ITrnPropertySet_EnumProperties_Proxy( 
    ITrnPropertySet __RPC_FAR * This,
    /* [in] */ unsigned int startingIndex,
    /* [in] */ unsigned int numToReturn,
    /* [out] */ STrnProperty __RPC_FAR *pProps,
    /* [out] */ STrnPropertyInfo __RPC_FAR *pPropInfo);


void __RPC_STUB ITrnPropertySet_EnumProperties_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE ITrnPropertySet_AddProps_Proxy( 
    ITrnPropertySet __RPC_FAR * This,
    /* [in] */ unsigned int numProps,
    /* [in] */ STrnPropertyInfo __RPC_FAR *pPropInfo);


void __RPC_STUB ITrnPropertySet_AddProps_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE ITrnPropertySet_QueryPropertyInfo_Proxy( 
    ITrnPropertySet __RPC_FAR * This,
    /* [in] */ ETrnProperty prop,
    /* [out] */ STrnPropertyInfo __RPC_FAR *pInfo);


void __RPC_STUB ITrnPropertySet_QueryPropertyInfo_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE ITrnPropertySet_QueryPropertyValue_Proxy( 
    ITrnPropertySet __RPC_FAR * This,
    /* [in] */ ETrnProperty prop,
    /* [out] */ LONG __RPC_FAR *pValue);


void __RPC_STUB ITrnPropertySet_QueryPropertyValue_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE ITrnPropertySet_QueryProperties_Proxy( 
    ITrnPropertySet __RPC_FAR * This,
    /* [in] */ unsigned int numProps,
    /* [out][in] */ STrnProperty __RPC_FAR *pProps);


void __RPC_STUB ITrnPropertySet_QueryProperties_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE ITrnPropertySet_QueryPropertiesInfo_Proxy( 
    ITrnPropertySet __RPC_FAR * This,
    /* [in] */ unsigned int numProps,
    /* [out][in] */ STrnPropertyInfo __RPC_FAR *pPropInfo);


void __RPC_STUB ITrnPropertySet_QueryPropertiesInfo_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE ITrnPropertySet_SetProperties_Proxy( 
    ITrnPropertySet __RPC_FAR * This,
    /* [in] */ unsigned int numProperties,
    /* [in] */ STrnProperty __RPC_FAR *pProps);


void __RPC_STUB ITrnPropertySet_SetProperties_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE ITrnPropertySet_SetProperty_Proxy( 
    ITrnPropertySet __RPC_FAR * This,
    /* [in] */ STrnTimeType __RPC_FAR *pTime,
    /* [in] */ ETrnProperty prop,
    /* [in] */ STrnPlayList __RPC_FAR *pPl);


void __RPC_STUB ITrnPropertySet_SetProperty_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE ITrnPropertySet_Merge_Proxy( 
    ITrnPropertySet __RPC_FAR * This,
    /* [in] */ ITrnPropertySet __RPC_FAR *pPropsToMerge,
    /* [in] */ ETrnPropertyFlags filterFlags);


void __RPC_STUB ITrnPropertySet_Merge_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __ITrnPropertySet_INTERFACE_DEFINED__ */


#ifndef __ITrnPropertiesArchive_INTERFACE_DEFINED__
#define __ITrnPropertiesArchive_INTERFACE_DEFINED__

/****************************************
 * Generated header for interface: ITrnPropertiesArchive
 * at Tue Nov 23 05:28:37 1999
 * using MIDL 3.01.75
 ****************************************/
/* [unique][uuid][object][local] */ 


typedef 
enum tagETrnPropsArchiveFlags
    {	AFProtected	= 1,
	AFModified	= 2
    }	ETrnPropsArchiveFlags;


EXTERN_C const IID IID_ITrnPropertiesArchive;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    interface DECLSPEC_UUID("8335e403-ab3b-11ce-8468-0000b468276b")
    ITrnPropertiesArchive : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE Open( 
            const unsigned char __RPC_FAR *pszArchiveName) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Create( 
            const unsigned char __RPC_FAR *pszArchiveName) = 0;
        
        virtual ULONG STDMETHODCALLTYPE QueryNumPropertySets( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE QuerySetName( 
            unsigned int setIndex,
            OLECHAR __RPC_FAR *pwszBuffer,
            unsigned int ccBuffer) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Load( 
            ITrnPropertySet __RPC_FAR *pSetToLoad,
            OLECHAR __RPC_FAR *pwszSetName,
            DWORD __RPC_FAR *pdwPropsFlags) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Save( 
            ITrnPropertySet __RPC_FAR *pSetToSave,
            OLECHAR __RPC_FAR *pwszSetName,
            ETrnPropsArchiveFlags arcFlags,
            ETrnPropertyFlags filterFlags) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Delete( 
            OLECHAR __RPC_FAR *pwszSetName) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct ITrnPropertiesArchiveVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            ITrnPropertiesArchive __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            ITrnPropertiesArchive __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            ITrnPropertiesArchive __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Open )( 
            ITrnPropertiesArchive __RPC_FAR * This,
            const unsigned char __RPC_FAR *pszArchiveName);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Create )( 
            ITrnPropertiesArchive __RPC_FAR * This,
            const unsigned char __RPC_FAR *pszArchiveName);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *QueryNumPropertySets )( 
            ITrnPropertiesArchive __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QuerySetName )( 
            ITrnPropertiesArchive __RPC_FAR * This,
            unsigned int setIndex,
            OLECHAR __RPC_FAR *pwszBuffer,
            unsigned int ccBuffer);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Load )( 
            ITrnPropertiesArchive __RPC_FAR * This,
            ITrnPropertySet __RPC_FAR *pSetToLoad,
            OLECHAR __RPC_FAR *pwszSetName,
            DWORD __RPC_FAR *pdwPropsFlags);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Save )( 
            ITrnPropertiesArchive __RPC_FAR * This,
            ITrnPropertySet __RPC_FAR *pSetToSave,
            OLECHAR __RPC_FAR *pwszSetName,
            ETrnPropsArchiveFlags arcFlags,
            ETrnPropertyFlags filterFlags);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Delete )( 
            ITrnPropertiesArchive __RPC_FAR * This,
            OLECHAR __RPC_FAR *pwszSetName);
        
        END_INTERFACE
    } ITrnPropertiesArchiveVtbl;

    interface ITrnPropertiesArchive
    {
        CONST_VTBL struct ITrnPropertiesArchiveVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ITrnPropertiesArchive_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define ITrnPropertiesArchive_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define ITrnPropertiesArchive_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define ITrnPropertiesArchive_Open(This,pszArchiveName)	\
    (This)->lpVtbl -> Open(This,pszArchiveName)

#define ITrnPropertiesArchive_Create(This,pszArchiveName)	\
    (This)->lpVtbl -> Create(This,pszArchiveName)

#define ITrnPropertiesArchive_QueryNumPropertySets(This)	\
    (This)->lpVtbl -> QueryNumPropertySets(This)

#define ITrnPropertiesArchive_QuerySetName(This,setIndex,pwszBuffer,ccBuffer)	\
    (This)->lpVtbl -> QuerySetName(This,setIndex,pwszBuffer,ccBuffer)

#define ITrnPropertiesArchive_Load(This,pSetToLoad,pwszSetName,pdwPropsFlags)	\
    (This)->lpVtbl -> Load(This,pSetToLoad,pwszSetName,pdwPropsFlags)

#define ITrnPropertiesArchive_Save(This,pSetToSave,pwszSetName,arcFlags,filterFlags)	\
    (This)->lpVtbl -> Save(This,pSetToSave,pwszSetName,arcFlags,filterFlags)

#define ITrnPropertiesArchive_Delete(This,pwszSetName)	\
    (This)->lpVtbl -> Delete(This,pwszSetName)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE ITrnPropertiesArchive_Open_Proxy( 
    ITrnPropertiesArchive __RPC_FAR * This,
    const unsigned char __RPC_FAR *pszArchiveName);


void __RPC_STUB ITrnPropertiesArchive_Open_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE ITrnPropertiesArchive_Create_Proxy( 
    ITrnPropertiesArchive __RPC_FAR * This,
    const unsigned char __RPC_FAR *pszArchiveName);


void __RPC_STUB ITrnPropertiesArchive_Create_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


ULONG STDMETHODCALLTYPE ITrnPropertiesArchive_QueryNumPropertySets_Proxy( 
    ITrnPropertiesArchive __RPC_FAR * This);


void __RPC_STUB ITrnPropertiesArchive_QueryNumPropertySets_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE ITrnPropertiesArchive_QuerySetName_Proxy( 
    ITrnPropertiesArchive __RPC_FAR * This,
    unsigned int setIndex,
    OLECHAR __RPC_FAR *pwszBuffer,
    unsigned int ccBuffer);


void __RPC_STUB ITrnPropertiesArchive_QuerySetName_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE ITrnPropertiesArchive_Load_Proxy( 
    ITrnPropertiesArchive __RPC_FAR * This,
    ITrnPropertySet __RPC_FAR *pSetToLoad,
    OLECHAR __RPC_FAR *pwszSetName,
    DWORD __RPC_FAR *pdwPropsFlags);


void __RPC_STUB ITrnPropertiesArchive_Load_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE ITrnPropertiesArchive_Save_Proxy( 
    ITrnPropertiesArchive __RPC_FAR * This,
    ITrnPropertySet __RPC_FAR *pSetToSave,
    OLECHAR __RPC_FAR *pwszSetName,
    ETrnPropsArchiveFlags arcFlags,
    ETrnPropertyFlags filterFlags);


void __RPC_STUB ITrnPropertiesArchive_Save_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE ITrnPropertiesArchive_Delete_Proxy( 
    ITrnPropertiesArchive __RPC_FAR * This,
    OLECHAR __RPC_FAR *pwszSetName);


void __RPC_STUB ITrnPropertiesArchive_Delete_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __ITrnPropertiesArchive_INTERFACE_DEFINED__ */


#ifndef __ITrnInputModule_INTERFACE_DEFINED__
#define __ITrnInputModule_INTERFACE_DEFINED__

/****************************************
 * Generated header for interface: ITrnInputModule
 * at Tue Nov 23 05:28:37 1999
 * using MIDL 3.01.75
 ****************************************/
/* [unique][uuid][object][local] */ 



EXTERN_C const IID IID_ITrnInputModule;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    interface DECLSPEC_UUID("8335e3dc-ab3b-11ce-8468-0000b468276b")
    ITrnInputModule : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE QueryPropsArchive( 
            ITrnPropertiesArchive __RPC_FAR *__RPC_FAR *ppPropsArchive) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE QueryPropSetName( 
            OLECHAR __RPC_FAR *pwszSetNameBuffer,
            unsigned int ccBuffSize,
            DWORD __RPC_FAR *pdwFlags) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE LoadProperties( 
            OLECHAR __RPC_FAR *pwszSetName,
            DWORD __RPC_FAR *pdwPropsFlags) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SaveProperties( 
            OLECHAR __RPC_FAR *pwszSetName,
            ETrnPropertyFlags filterFlags) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE LoadMapTable( 
            DWORD MapIndex,
            DWORD TableSize,
            /* [size_is][in] */ BYTE __RPC_FAR *Table) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct ITrnInputModuleVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            ITrnInputModule __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            ITrnInputModule __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            ITrnInputModule __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryPropsArchive )( 
            ITrnInputModule __RPC_FAR * This,
            ITrnPropertiesArchive __RPC_FAR *__RPC_FAR *ppPropsArchive);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryPropSetName )( 
            ITrnInputModule __RPC_FAR * This,
            OLECHAR __RPC_FAR *pwszSetNameBuffer,
            unsigned int ccBuffSize,
            DWORD __RPC_FAR *pdwFlags);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *LoadProperties )( 
            ITrnInputModule __RPC_FAR * This,
            OLECHAR __RPC_FAR *pwszSetName,
            DWORD __RPC_FAR *pdwPropsFlags);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SaveProperties )( 
            ITrnInputModule __RPC_FAR * This,
            OLECHAR __RPC_FAR *pwszSetName,
            ETrnPropertyFlags filterFlags);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *LoadMapTable )( 
            ITrnInputModule __RPC_FAR * This,
            DWORD MapIndex,
            DWORD TableSize,
            /* [size_is][in] */ BYTE __RPC_FAR *Table);
        
        END_INTERFACE
    } ITrnInputModuleVtbl;

    interface ITrnInputModule
    {
        CONST_VTBL struct ITrnInputModuleVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ITrnInputModule_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define ITrnInputModule_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define ITrnInputModule_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define ITrnInputModule_QueryPropsArchive(This,ppPropsArchive)	\
    (This)->lpVtbl -> QueryPropsArchive(This,ppPropsArchive)

#define ITrnInputModule_QueryPropSetName(This,pwszSetNameBuffer,ccBuffSize,pdwFlags)	\
    (This)->lpVtbl -> QueryPropSetName(This,pwszSetNameBuffer,ccBuffSize,pdwFlags)

#define ITrnInputModule_LoadProperties(This,pwszSetName,pdwPropsFlags)	\
    (This)->lpVtbl -> LoadProperties(This,pwszSetName,pdwPropsFlags)

#define ITrnInputModule_SaveProperties(This,pwszSetName,filterFlags)	\
    (This)->lpVtbl -> SaveProperties(This,pwszSetName,filterFlags)

#define ITrnInputModule_LoadMapTable(This,MapIndex,TableSize,Table)	\
    (This)->lpVtbl -> LoadMapTable(This,MapIndex,TableSize,Table)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE ITrnInputModule_QueryPropsArchive_Proxy( 
    ITrnInputModule __RPC_FAR * This,
    ITrnPropertiesArchive __RPC_FAR *__RPC_FAR *ppPropsArchive);


void __RPC_STUB ITrnInputModule_QueryPropsArchive_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE ITrnInputModule_QueryPropSetName_Proxy( 
    ITrnInputModule __RPC_FAR * This,
    OLECHAR __RPC_FAR *pwszSetNameBuffer,
    unsigned int ccBuffSize,
    DWORD __RPC_FAR *pdwFlags);


void __RPC_STUB ITrnInputModule_QueryPropSetName_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE ITrnInputModule_LoadProperties_Proxy( 
    ITrnInputModule __RPC_FAR * This,
    OLECHAR __RPC_FAR *pwszSetName,
    DWORD __RPC_FAR *pdwPropsFlags);


void __RPC_STUB ITrnInputModule_LoadProperties_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE ITrnInputModule_SaveProperties_Proxy( 
    ITrnInputModule __RPC_FAR * This,
    OLECHAR __RPC_FAR *pwszSetName,
    ETrnPropertyFlags filterFlags);


void __RPC_STUB ITrnInputModule_SaveProperties_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE ITrnInputModule_LoadMapTable_Proxy( 
    ITrnInputModule __RPC_FAR * This,
    DWORD MapIndex,
    DWORD TableSize,
    /* [size_is][in] */ BYTE __RPC_FAR *Table);


void __RPC_STUB ITrnInputModule_LoadMapTable_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __ITrnInputModule_INTERFACE_DEFINED__ */


#ifndef __ITrnInputModule2_INTERFACE_DEFINED__
#define __ITrnInputModule2_INTERFACE_DEFINED__

/****************************************
 * Generated header for interface: ITrnInputModule2
 * at Tue Nov 23 05:28:37 1999
 * using MIDL 3.01.75
 ****************************************/
/* [unique][uuid][object][local] */ 



EXTERN_C const IID IID_ITrnInputModule2;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    interface DECLSPEC_UUID("8335e413-ab3b-11ce-8468-0000b468276b")
    ITrnInputModule2 : public ITrnInputModule
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE ColorCorrectorReady( void) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct ITrnInputModule2Vtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            ITrnInputModule2 __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            ITrnInputModule2 __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            ITrnInputModule2 __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryPropsArchive )( 
            ITrnInputModule2 __RPC_FAR * This,
            ITrnPropertiesArchive __RPC_FAR *__RPC_FAR *ppPropsArchive);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryPropSetName )( 
            ITrnInputModule2 __RPC_FAR * This,
            OLECHAR __RPC_FAR *pwszSetNameBuffer,
            unsigned int ccBuffSize,
            DWORD __RPC_FAR *pdwFlags);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *LoadProperties )( 
            ITrnInputModule2 __RPC_FAR * This,
            OLECHAR __RPC_FAR *pwszSetName,
            DWORD __RPC_FAR *pdwPropsFlags);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SaveProperties )( 
            ITrnInputModule2 __RPC_FAR * This,
            OLECHAR __RPC_FAR *pwszSetName,
            ETrnPropertyFlags filterFlags);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *LoadMapTable )( 
            ITrnInputModule2 __RPC_FAR * This,
            DWORD MapIndex,
            DWORD TableSize,
            /* [size_is][in] */ BYTE __RPC_FAR *Table);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *ColorCorrectorReady )( 
            ITrnInputModule2 __RPC_FAR * This);
        
        END_INTERFACE
    } ITrnInputModule2Vtbl;

    interface ITrnInputModule2
    {
        CONST_VTBL struct ITrnInputModule2Vtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ITrnInputModule2_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define ITrnInputModule2_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define ITrnInputModule2_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define ITrnInputModule2_QueryPropsArchive(This,ppPropsArchive)	\
    (This)->lpVtbl -> QueryPropsArchive(This,ppPropsArchive)

#define ITrnInputModule2_QueryPropSetName(This,pwszSetNameBuffer,ccBuffSize,pdwFlags)	\
    (This)->lpVtbl -> QueryPropSetName(This,pwszSetNameBuffer,ccBuffSize,pdwFlags)

#define ITrnInputModule2_LoadProperties(This,pwszSetName,pdwPropsFlags)	\
    (This)->lpVtbl -> LoadProperties(This,pwszSetName,pdwPropsFlags)

#define ITrnInputModule2_SaveProperties(This,pwszSetName,filterFlags)	\
    (This)->lpVtbl -> SaveProperties(This,pwszSetName,filterFlags)

#define ITrnInputModule2_LoadMapTable(This,MapIndex,TableSize,Table)	\
    (This)->lpVtbl -> LoadMapTable(This,MapIndex,TableSize,Table)


#define ITrnInputModule2_ColorCorrectorReady(This)	\
    (This)->lpVtbl -> ColorCorrectorReady(This)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE ITrnInputModule2_ColorCorrectorReady_Proxy( 
    ITrnInputModule2 __RPC_FAR * This);


void __RPC_STUB ITrnInputModule2_ColorCorrectorReady_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __ITrnInputModule2_INTERFACE_DEFINED__ */


#ifndef __ITrnProcessor_INTERFACE_DEFINED__
#define __ITrnProcessor_INTERFACE_DEFINED__

/****************************************
 * Generated header for interface: ITrnProcessor
 * at Tue Nov 23 05:28:37 1999
 * using MIDL 3.01.75
 ****************************************/
/* [unique][uuid][object][local] */ 


typedef struct  tagSTrnPCapabilities
    {
    BOOL BigEndian;
    SHORT VideoDepth;
    SHORT Delay;
    BOOL RouterInput;
    BOOL AlphaIn;
    BOOL AlphaOut1;
    BOOL AlphaOut2;
    BOOL ABusOut;
    BOOL BBusOut;
    BOOL CBusOut;
    ETrnVideoTransmissionFormats NativeFormat;
    DWORD KeyPriorityModes;
    }	STrnPCapabilities;


EXTERN_C const IID IID_ITrnProcessor;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    interface DECLSPEC_UUID("8335e3df-ab3b-11ce-8468-0000b468276b")
    ITrnProcessor : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE QueryCapabilities( 
            /* [out] */ STrnPCapabilities __RPC_FAR *pCaps) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct ITrnProcessorVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            ITrnProcessor __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            ITrnProcessor __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            ITrnProcessor __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryCapabilities )( 
            ITrnProcessor __RPC_FAR * This,
            /* [out] */ STrnPCapabilities __RPC_FAR *pCaps);
        
        END_INTERFACE
    } ITrnProcessorVtbl;

    interface ITrnProcessor
    {
        CONST_VTBL struct ITrnProcessorVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ITrnProcessor_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define ITrnProcessor_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define ITrnProcessor_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define ITrnProcessor_QueryCapabilities(This,pCaps)	\
    (This)->lpVtbl -> QueryCapabilities(This,pCaps)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE ITrnProcessor_QueryCapabilities_Proxy( 
    ITrnProcessor __RPC_FAR * This,
    /* [out] */ STrnPCapabilities __RPC_FAR *pCaps);


void __RPC_STUB ITrnProcessor_QueryCapabilities_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __ITrnProcessor_INTERFACE_DEFINED__ */


#ifndef __ITrnD1Output_INTERFACE_DEFINED__
#define __ITrnD1Output_INTERFACE_DEFINED__

/****************************************
 * Generated header for interface: ITrnD1Output
 * at Tue Nov 23 05:28:37 1999
 * using MIDL 3.01.75
 ****************************************/
/* [unique][uuid][object][local] */ 


typedef 
enum tagETrnD1OutputMode
    {	D1OModeFreeze	= 0,
	D1OModeLive	= D1OModeFreeze + 1
    }	ETrnD1OutputMode;


EXTERN_C const IID IID_ITrnD1Output;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    interface DECLSPEC_UUID("8335e5db-ab3b-11ce-8468-0000b468276b")
    ITrnD1Output : public ITrnProcessor
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE SetMode( 
            ETrnD1OutputMode whichMode) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE QueryMode( 
            ETrnD1OutputMode __RPC_FAR *pWhichMode) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE LoadFrameStoreStream( 
            /* [in] */ IStream __RPC_FAR *pStream,
            DWORD length) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE LoadFrameStoreFile( 
            HANDLE hFile,
            DWORD length) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE LoadFrameStoreFileMapping( 
            HANDLE hFileMapping,
            DWORD offset,
            DWORD length) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE LoadFrameStoreMemory( 
            LPVOID pImage,
            DWORD length) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct ITrnD1OutputVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            ITrnD1Output __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            ITrnD1Output __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            ITrnD1Output __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryCapabilities )( 
            ITrnD1Output __RPC_FAR * This,
            /* [out] */ STrnPCapabilities __RPC_FAR *pCaps);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetMode )( 
            ITrnD1Output __RPC_FAR * This,
            ETrnD1OutputMode whichMode);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryMode )( 
            ITrnD1Output __RPC_FAR * This,
            ETrnD1OutputMode __RPC_FAR *pWhichMode);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *LoadFrameStoreStream )( 
            ITrnD1Output __RPC_FAR * This,
            /* [in] */ IStream __RPC_FAR *pStream,
            DWORD length);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *LoadFrameStoreFile )( 
            ITrnD1Output __RPC_FAR * This,
            HANDLE hFile,
            DWORD length);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *LoadFrameStoreFileMapping )( 
            ITrnD1Output __RPC_FAR * This,
            HANDLE hFileMapping,
            DWORD offset,
            DWORD length);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *LoadFrameStoreMemory )( 
            ITrnD1Output __RPC_FAR * This,
            LPVOID pImage,
            DWORD length);
        
        END_INTERFACE
    } ITrnD1OutputVtbl;

    interface ITrnD1Output
    {
        CONST_VTBL struct ITrnD1OutputVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ITrnD1Output_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define ITrnD1Output_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define ITrnD1Output_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define ITrnD1Output_QueryCapabilities(This,pCaps)	\
    (This)->lpVtbl -> QueryCapabilities(This,pCaps)


#define ITrnD1Output_SetMode(This,whichMode)	\
    (This)->lpVtbl -> SetMode(This,whichMode)

#define ITrnD1Output_QueryMode(This,pWhichMode)	\
    (This)->lpVtbl -> QueryMode(This,pWhichMode)

#define ITrnD1Output_LoadFrameStoreStream(This,pStream,length)	\
    (This)->lpVtbl -> LoadFrameStoreStream(This,pStream,length)

#define ITrnD1Output_LoadFrameStoreFile(This,hFile,length)	\
    (This)->lpVtbl -> LoadFrameStoreFile(This,hFile,length)

#define ITrnD1Output_LoadFrameStoreFileMapping(This,hFileMapping,offset,length)	\
    (This)->lpVtbl -> LoadFrameStoreFileMapping(This,hFileMapping,offset,length)

#define ITrnD1Output_LoadFrameStoreMemory(This,pImage,length)	\
    (This)->lpVtbl -> LoadFrameStoreMemory(This,pImage,length)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE ITrnD1Output_SetMode_Proxy( 
    ITrnD1Output __RPC_FAR * This,
    ETrnD1OutputMode whichMode);


void __RPC_STUB ITrnD1Output_SetMode_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE ITrnD1Output_QueryMode_Proxy( 
    ITrnD1Output __RPC_FAR * This,
    ETrnD1OutputMode __RPC_FAR *pWhichMode);


void __RPC_STUB ITrnD1Output_QueryMode_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE ITrnD1Output_LoadFrameStoreStream_Proxy( 
    ITrnD1Output __RPC_FAR * This,
    /* [in] */ IStream __RPC_FAR *pStream,
    DWORD length);


void __RPC_STUB ITrnD1Output_LoadFrameStoreStream_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE ITrnD1Output_LoadFrameStoreFile_Proxy( 
    ITrnD1Output __RPC_FAR * This,
    HANDLE hFile,
    DWORD length);


void __RPC_STUB ITrnD1Output_LoadFrameStoreFile_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE ITrnD1Output_LoadFrameStoreFileMapping_Proxy( 
    ITrnD1Output __RPC_FAR * This,
    HANDLE hFileMapping,
    DWORD offset,
    DWORD length);


void __RPC_STUB ITrnD1Output_LoadFrameStoreFileMapping_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE ITrnD1Output_LoadFrameStoreMemory_Proxy( 
    ITrnD1Output __RPC_FAR * This,
    LPVOID pImage,
    DWORD length);


void __RPC_STUB ITrnD1Output_LoadFrameStoreMemory_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __ITrnD1Output_INTERFACE_DEFINED__ */


#ifndef __ITrnClipAdviseSink_INTERFACE_DEFINED__
#define __ITrnClipAdviseSink_INTERFACE_DEFINED__

/****************************************
 * Generated header for interface: ITrnClipAdviseSink
 * at Tue Nov 23 05:28:37 1999
 * using MIDL 3.01.75
 ****************************************/
/* [unique][uuid][object][local] */ 



EXTERN_C const IID IID_ITrnClipAdviseSink;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    interface DECLSPEC_UUID("8335e3d6-ab3b-11ce-8468-0000b468276b")
    ITrnClipAdviseSink : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE OnClipUpdate( 
            DWORD connectionId) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE OnClipError( 
            DWORD connectionId,
            HRESULT error) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct ITrnClipAdviseSinkVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            ITrnClipAdviseSink __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            ITrnClipAdviseSink __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            ITrnClipAdviseSink __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *OnClipUpdate )( 
            ITrnClipAdviseSink __RPC_FAR * This,
            DWORD connectionId);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *OnClipError )( 
            ITrnClipAdviseSink __RPC_FAR * This,
            DWORD connectionId,
            HRESULT error);
        
        END_INTERFACE
    } ITrnClipAdviseSinkVtbl;

    interface ITrnClipAdviseSink
    {
        CONST_VTBL struct ITrnClipAdviseSinkVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ITrnClipAdviseSink_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define ITrnClipAdviseSink_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define ITrnClipAdviseSink_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define ITrnClipAdviseSink_OnClipUpdate(This,connectionId)	\
    (This)->lpVtbl -> OnClipUpdate(This,connectionId)

#define ITrnClipAdviseSink_OnClipError(This,connectionId,error)	\
    (This)->lpVtbl -> OnClipError(This,connectionId,error)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE ITrnClipAdviseSink_OnClipUpdate_Proxy( 
    ITrnClipAdviseSink __RPC_FAR * This,
    DWORD connectionId);


void __RPC_STUB ITrnClipAdviseSink_OnClipUpdate_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE ITrnClipAdviseSink_OnClipError_Proxy( 
    ITrnClipAdviseSink __RPC_FAR * This,
    DWORD connectionId,
    HRESULT error);


void __RPC_STUB ITrnClipAdviseSink_OnClipError_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __ITrnClipAdviseSink_INTERFACE_DEFINED__ */


#ifndef __ITrnClipGrab_INTERFACE_DEFINED__
#define __ITrnClipGrab_INTERFACE_DEFINED__

/****************************************
 * Generated header for interface: ITrnClipGrab
 * at Tue Nov 23 05:28:37 1999
 * using MIDL 3.01.75
 ****************************************/
/* [unique][uuid][object][local] */ 


typedef struct  tagSTrnCGCapabilities
    {
    DWORD formatsSupported;
    DWORD sourcesSupported;
    BOOL canDitherToPalette;
    BOOL canShrink;
    BOOL canBorder;
    BOOL canGrabAlpha;
    WORD minInterval;
    }	STrnCGCapabilities;


enum __MIDL_ITrnClipGrab_0001
    {	GrabIDAllGrabs	= 0xdeaddead
    };

EXTERN_C const IID IID_ITrnClipGrab;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    interface DECLSPEC_UUID("8335e3d2-ab3b-11ce-8468-0000b468276b")
    ITrnClipGrab : public ITrnProcessor
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE QueryCapabilitiesEx( 
            /* [out] */ STrnPCapabilities __RPC_FAR *pCaps,
            /* [out] */ STrnCGCapabilities __RPC_FAR *pECaps) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GrabImage( 
            unsigned int source,
            STrnRect __RPC_FAR *pSourceRect,
            ETrnFrameAccessMode sourceMode,
            SPlayBitMap __RPC_FAR *pDest,
            STrnRect __RPC_FAR *pDestRect,
            ETrnFrameAccessMode destMode) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GrabImageEx( 
            unsigned int source,
            STrnRect __RPC_FAR *pSourceRect,
            ETrnFrameAccessMode sourceMode,
            SPlayBitMap __RPC_FAR *pDest,
            STrnRect __RPC_FAR *pDestRect,
            ETrnFrameAccessMode destMode,
            STrnTimeType __RPC_FAR *pTime,
            WORD ratel,
            ITrnClipAdviseSink __RPC_FAR *pAdvise,
            DWORD __RPC_FAR *pConnectionId) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE StopGrab( 
            DWORD connectionId) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct ITrnClipGrabVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            ITrnClipGrab __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            ITrnClipGrab __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            ITrnClipGrab __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryCapabilities )( 
            ITrnClipGrab __RPC_FAR * This,
            /* [out] */ STrnPCapabilities __RPC_FAR *pCaps);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryCapabilitiesEx )( 
            ITrnClipGrab __RPC_FAR * This,
            /* [out] */ STrnPCapabilities __RPC_FAR *pCaps,
            /* [out] */ STrnCGCapabilities __RPC_FAR *pECaps);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GrabImage )( 
            ITrnClipGrab __RPC_FAR * This,
            unsigned int source,
            STrnRect __RPC_FAR *pSourceRect,
            ETrnFrameAccessMode sourceMode,
            SPlayBitMap __RPC_FAR *pDest,
            STrnRect __RPC_FAR *pDestRect,
            ETrnFrameAccessMode destMode);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GrabImageEx )( 
            ITrnClipGrab __RPC_FAR * This,
            unsigned int source,
            STrnRect __RPC_FAR *pSourceRect,
            ETrnFrameAccessMode sourceMode,
            SPlayBitMap __RPC_FAR *pDest,
            STrnRect __RPC_FAR *pDestRect,
            ETrnFrameAccessMode destMode,
            STrnTimeType __RPC_FAR *pTime,
            WORD ratel,
            ITrnClipAdviseSink __RPC_FAR *pAdvise,
            DWORD __RPC_FAR *pConnectionId);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *StopGrab )( 
            ITrnClipGrab __RPC_FAR * This,
            DWORD connectionId);
        
        END_INTERFACE
    } ITrnClipGrabVtbl;

    interface ITrnClipGrab
    {
        CONST_VTBL struct ITrnClipGrabVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ITrnClipGrab_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define ITrnClipGrab_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define ITrnClipGrab_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define ITrnClipGrab_QueryCapabilities(This,pCaps)	\
    (This)->lpVtbl -> QueryCapabilities(This,pCaps)


#define ITrnClipGrab_QueryCapabilitiesEx(This,pCaps,pECaps)	\
    (This)->lpVtbl -> QueryCapabilitiesEx(This,pCaps,pECaps)

#define ITrnClipGrab_GrabImage(This,source,pSourceRect,sourceMode,pDest,pDestRect,destMode)	\
    (This)->lpVtbl -> GrabImage(This,source,pSourceRect,sourceMode,pDest,pDestRect,destMode)

#define ITrnClipGrab_GrabImageEx(This,source,pSourceRect,sourceMode,pDest,pDestRect,destMode,pTime,ratel,pAdvise,pConnectionId)	\
    (This)->lpVtbl -> GrabImageEx(This,source,pSourceRect,sourceMode,pDest,pDestRect,destMode,pTime,ratel,pAdvise,pConnectionId)

#define ITrnClipGrab_StopGrab(This,connectionId)	\
    (This)->lpVtbl -> StopGrab(This,connectionId)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE ITrnClipGrab_QueryCapabilitiesEx_Proxy( 
    ITrnClipGrab __RPC_FAR * This,
    /* [out] */ STrnPCapabilities __RPC_FAR *pCaps,
    /* [out] */ STrnCGCapabilities __RPC_FAR *pECaps);


void __RPC_STUB ITrnClipGrab_QueryCapabilitiesEx_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE ITrnClipGrab_GrabImage_Proxy( 
    ITrnClipGrab __RPC_FAR * This,
    unsigned int source,
    STrnRect __RPC_FAR *pSourceRect,
    ETrnFrameAccessMode sourceMode,
    SPlayBitMap __RPC_FAR *pDest,
    STrnRect __RPC_FAR *pDestRect,
    ETrnFrameAccessMode destMode);


void __RPC_STUB ITrnClipGrab_GrabImage_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE ITrnClipGrab_GrabImageEx_Proxy( 
    ITrnClipGrab __RPC_FAR * This,
    unsigned int source,
    STrnRect __RPC_FAR *pSourceRect,
    ETrnFrameAccessMode sourceMode,
    SPlayBitMap __RPC_FAR *pDest,
    STrnRect __RPC_FAR *pDestRect,
    ETrnFrameAccessMode destMode,
    STrnTimeType __RPC_FAR *pTime,
    WORD ratel,
    ITrnClipAdviseSink __RPC_FAR *pAdvise,
    DWORD __RPC_FAR *pConnectionId);


void __RPC_STUB ITrnClipGrab_GrabImageEx_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE ITrnClipGrab_StopGrab_Proxy( 
    ITrnClipGrab __RPC_FAR * This,
    DWORD connectionId);


void __RPC_STUB ITrnClipGrab_StopGrab_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __ITrnClipGrab_INTERFACE_DEFINED__ */


#ifndef __ITrnClipGrab2_INTERFACE_DEFINED__
#define __ITrnClipGrab2_INTERFACE_DEFINED__

/****************************************
 * Generated header for interface: ITrnClipGrab2
 * at Tue Nov 23 05:28:37 1999
 * using MIDL 3.01.75
 ****************************************/
/* [unique][uuid][object][local] */ 



EXTERN_C const IID IID_ITrnClipGrab2;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    interface DECLSPEC_UUID("8335e497-ab3b-11ce-8468-0000b468276b")
    ITrnClipGrab2 : public ITrnClipGrab
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE Enable( 
            BOOL fEnabled) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct ITrnClipGrab2Vtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            ITrnClipGrab2 __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            ITrnClipGrab2 __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            ITrnClipGrab2 __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryCapabilities )( 
            ITrnClipGrab2 __RPC_FAR * This,
            /* [out] */ STrnPCapabilities __RPC_FAR *pCaps);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryCapabilitiesEx )( 
            ITrnClipGrab2 __RPC_FAR * This,
            /* [out] */ STrnPCapabilities __RPC_FAR *pCaps,
            /* [out] */ STrnCGCapabilities __RPC_FAR *pECaps);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GrabImage )( 
            ITrnClipGrab2 __RPC_FAR * This,
            unsigned int source,
            STrnRect __RPC_FAR *pSourceRect,
            ETrnFrameAccessMode sourceMode,
            SPlayBitMap __RPC_FAR *pDest,
            STrnRect __RPC_FAR *pDestRect,
            ETrnFrameAccessMode destMode);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GrabImageEx )( 
            ITrnClipGrab2 __RPC_FAR * This,
            unsigned int source,
            STrnRect __RPC_FAR *pSourceRect,
            ETrnFrameAccessMode sourceMode,
            SPlayBitMap __RPC_FAR *pDest,
            STrnRect __RPC_FAR *pDestRect,
            ETrnFrameAccessMode destMode,
            STrnTimeType __RPC_FAR *pTime,
            WORD ratel,
            ITrnClipAdviseSink __RPC_FAR *pAdvise,
            DWORD __RPC_FAR *pConnectionId);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *StopGrab )( 
            ITrnClipGrab2 __RPC_FAR * This,
            DWORD connectionId);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Enable )( 
            ITrnClipGrab2 __RPC_FAR * This,
            BOOL fEnabled);
        
        END_INTERFACE
    } ITrnClipGrab2Vtbl;

    interface ITrnClipGrab2
    {
        CONST_VTBL struct ITrnClipGrab2Vtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ITrnClipGrab2_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define ITrnClipGrab2_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define ITrnClipGrab2_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define ITrnClipGrab2_QueryCapabilities(This,pCaps)	\
    (This)->lpVtbl -> QueryCapabilities(This,pCaps)


#define ITrnClipGrab2_QueryCapabilitiesEx(This,pCaps,pECaps)	\
    (This)->lpVtbl -> QueryCapabilitiesEx(This,pCaps,pECaps)

#define ITrnClipGrab2_GrabImage(This,source,pSourceRect,sourceMode,pDest,pDestRect,destMode)	\
    (This)->lpVtbl -> GrabImage(This,source,pSourceRect,sourceMode,pDest,pDestRect,destMode)

#define ITrnClipGrab2_GrabImageEx(This,source,pSourceRect,sourceMode,pDest,pDestRect,destMode,pTime,ratel,pAdvise,pConnectionId)	\
    (This)->lpVtbl -> GrabImageEx(This,source,pSourceRect,sourceMode,pDest,pDestRect,destMode,pTime,ratel,pAdvise,pConnectionId)

#define ITrnClipGrab2_StopGrab(This,connectionId)	\
    (This)->lpVtbl -> StopGrab(This,connectionId)


#define ITrnClipGrab2_Enable(This,fEnabled)	\
    (This)->lpVtbl -> Enable(This,fEnabled)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE ITrnClipGrab2_Enable_Proxy( 
    ITrnClipGrab2 __RPC_FAR * This,
    BOOL fEnabled);


void __RPC_STUB ITrnClipGrab2_Enable_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __ITrnClipGrab2_INTERFACE_DEFINED__ */


#ifndef __ITrnVideoPath_INTERFACE_DEFINED__
#define __ITrnVideoPath_INTERFACE_DEFINED__

/****************************************
 * Generated header for interface: ITrnVideoPath
 * at Tue Nov 23 05:28:37 1999
 * using MIDL 3.01.75
 ****************************************/
/* [unique][uuid][object][local] */ 


typedef struct  tagSTrnEPKPTable
    {
    unsigned char Index;
    unsigned char KP[ 7 ];
    }	STrnEPKPTable;


EXTERN_C const IID IID_ITrnVideoPath;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    interface DECLSPEC_UUID("8335e5eb-ab3b-11ce-8468-0000b468276b")
    ITrnVideoPath : public ITrnProcessor
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE SetStrobe( 
            /* [in] */ STrnTimeType __RPC_FAR *pTime,
            /* [in] */ DWORD frequency) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetMatteColor( 
            /* [in] */ STrnTimeType __RPC_FAR *pTime,
            /* [in] */ DWORD color) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE ActivateMatte( 
            /* [in] */ STrnTimeType __RPC_FAR *pTime) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetKeyPriorityTable( 
            WORD KPIndex,
            /* [in] */ STrnEPKPTable __RPC_FAR *pTable) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE ActivateKeyPriorityTable( 
            /* [in] */ STrnTimeType __RPC_FAR *pTime,
            WORD KPIndex) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE QueryKeyPriorityTable( 
            WORD KPIndex,
            /* [out] */ STrnEPKPTable __RPC_FAR *pTable) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct ITrnVideoPathVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            ITrnVideoPath __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            ITrnVideoPath __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            ITrnVideoPath __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryCapabilities )( 
            ITrnVideoPath __RPC_FAR * This,
            /* [out] */ STrnPCapabilities __RPC_FAR *pCaps);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetStrobe )( 
            ITrnVideoPath __RPC_FAR * This,
            /* [in] */ STrnTimeType __RPC_FAR *pTime,
            /* [in] */ DWORD frequency);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetMatteColor )( 
            ITrnVideoPath __RPC_FAR * This,
            /* [in] */ STrnTimeType __RPC_FAR *pTime,
            /* [in] */ DWORD color);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *ActivateMatte )( 
            ITrnVideoPath __RPC_FAR * This,
            /* [in] */ STrnTimeType __RPC_FAR *pTime);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetKeyPriorityTable )( 
            ITrnVideoPath __RPC_FAR * This,
            WORD KPIndex,
            /* [in] */ STrnEPKPTable __RPC_FAR *pTable);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *ActivateKeyPriorityTable )( 
            ITrnVideoPath __RPC_FAR * This,
            /* [in] */ STrnTimeType __RPC_FAR *pTime,
            WORD KPIndex);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryKeyPriorityTable )( 
            ITrnVideoPath __RPC_FAR * This,
            WORD KPIndex,
            /* [out] */ STrnEPKPTable __RPC_FAR *pTable);
        
        END_INTERFACE
    } ITrnVideoPathVtbl;

    interface ITrnVideoPath
    {
        CONST_VTBL struct ITrnVideoPathVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ITrnVideoPath_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define ITrnVideoPath_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define ITrnVideoPath_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define ITrnVideoPath_QueryCapabilities(This,pCaps)	\
    (This)->lpVtbl -> QueryCapabilities(This,pCaps)


#define ITrnVideoPath_SetStrobe(This,pTime,frequency)	\
    (This)->lpVtbl -> SetStrobe(This,pTime,frequency)

#define ITrnVideoPath_SetMatteColor(This,pTime,color)	\
    (This)->lpVtbl -> SetMatteColor(This,pTime,color)

#define ITrnVideoPath_ActivateMatte(This,pTime)	\
    (This)->lpVtbl -> ActivateMatte(This,pTime)

#define ITrnVideoPath_SetKeyPriorityTable(This,KPIndex,pTable)	\
    (This)->lpVtbl -> SetKeyPriorityTable(This,KPIndex,pTable)

#define ITrnVideoPath_ActivateKeyPriorityTable(This,pTime,KPIndex)	\
    (This)->lpVtbl -> ActivateKeyPriorityTable(This,pTime,KPIndex)

#define ITrnVideoPath_QueryKeyPriorityTable(This,KPIndex,pTable)	\
    (This)->lpVtbl -> QueryKeyPriorityTable(This,KPIndex,pTable)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE ITrnVideoPath_SetStrobe_Proxy( 
    ITrnVideoPath __RPC_FAR * This,
    /* [in] */ STrnTimeType __RPC_FAR *pTime,
    /* [in] */ DWORD frequency);


void __RPC_STUB ITrnVideoPath_SetStrobe_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE ITrnVideoPath_SetMatteColor_Proxy( 
    ITrnVideoPath __RPC_FAR * This,
    /* [in] */ STrnTimeType __RPC_FAR *pTime,
    /* [in] */ DWORD color);


void __RPC_STUB ITrnVideoPath_SetMatteColor_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE ITrnVideoPath_ActivateMatte_Proxy( 
    ITrnVideoPath __RPC_FAR * This,
    /* [in] */ STrnTimeType __RPC_FAR *pTime);


void __RPC_STUB ITrnVideoPath_ActivateMatte_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE ITrnVideoPath_SetKeyPriorityTable_Proxy( 
    ITrnVideoPath __RPC_FAR * This,
    WORD KPIndex,
    /* [in] */ STrnEPKPTable __RPC_FAR *pTable);


void __RPC_STUB ITrnVideoPath_SetKeyPriorityTable_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE ITrnVideoPath_ActivateKeyPriorityTable_Proxy( 
    ITrnVideoPath __RPC_FAR * This,
    /* [in] */ STrnTimeType __RPC_FAR *pTime,
    WORD KPIndex);


void __RPC_STUB ITrnVideoPath_ActivateKeyPriorityTable_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE ITrnVideoPath_QueryKeyPriorityTable_Proxy( 
    ITrnVideoPath __RPC_FAR * This,
    WORD KPIndex,
    /* [out] */ STrnEPKPTable __RPC_FAR *pTable);


void __RPC_STUB ITrnVideoPath_QueryKeyPriorityTable_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __ITrnVideoPath_INTERFACE_DEFINED__ */


#ifndef __ITrnEffectsProcessor_INTERFACE_DEFINED__
#define __ITrnEffectsProcessor_INTERFACE_DEFINED__

/****************************************
 * Generated header for interface: ITrnEffectsProcessor
 * at Tue Nov 23 05:28:37 1999
 * using MIDL 3.01.75
 ****************************************/
/* [unique][uuid][object][local] */ 


typedef struct  tagSTrnEPCapabilities
    {
    WORD nBuffers;
    STrnRectGridLimits ActiveRange;
    BOOL canStrobe;
    BOOL canFreeze;
    BOOL canMatte;
    BOOL canBlack;
    }	STrnEPCapabilities;

typedef 
enum tagEEPRunMode
    {	EPRMRun	= 0,
	EPRMFreeze	= 1,
	EPRMMatte	= 2
    }	EEPRunMode;

typedef 
enum tagEEPRunItems
    {	EPRIanims	= 0x1,
	EPRIstrobe	= 0x2,
	EPRIrunmode	= 0x4
    }	EEPRunItems;


EXTERN_C const IID IID_ITrnEffectsProcessor;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    interface DECLSPEC_UUID("8335e3e0-ab3b-11ce-8468-0000b468276b")
    ITrnEffectsProcessor : public ITrnVideoPath
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE QueryCapabilitiesEx( 
            /* [out] */ STrnPCapabilities __RPC_FAR *pCaps,
            /* [out] */ STrnEPCapabilities __RPC_FAR *pECaps) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE LoadAnimStream( 
            /* [in] */ IStream __RPC_FAR *pStream,
            DWORD length,
            DWORD __RPC_FAR *pAnimId) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE LoadAnimFile( 
            HANDLE hFile,
            DWORD length,
            DWORD __RPC_FAR *pAnimId) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE LoadAnimFileMapping( 
            HANDLE hFileMapping,
            DWORD offset,
            DWORD length,
            DWORD __RPC_FAR *pAnimId) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE LoadAnimMemory( 
            LPVOID pImage,
            DWORD length,
            DWORD __RPC_FAR *pAnimId) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE ReleaseAnim( 
            DWORD AnimId) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE PlayAnim( 
            DWORD AnimId,
            /* [in] */ STrnTimeType __RPC_FAR *pTime,
            /* [in] */ STrnPlayList __RPC_FAR *pList) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE ActivatePassThrough( 
            /* [in] */ STrnTimeType __RPC_FAR *pTime,
            /* [in] */ DWORD KeepMask) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetLumaThreshold( 
            DWORD luma) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct ITrnEffectsProcessorVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            ITrnEffectsProcessor __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            ITrnEffectsProcessor __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            ITrnEffectsProcessor __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryCapabilities )( 
            ITrnEffectsProcessor __RPC_FAR * This,
            /* [out] */ STrnPCapabilities __RPC_FAR *pCaps);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetStrobe )( 
            ITrnEffectsProcessor __RPC_FAR * This,
            /* [in] */ STrnTimeType __RPC_FAR *pTime,
            /* [in] */ DWORD frequency);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetMatteColor )( 
            ITrnEffectsProcessor __RPC_FAR * This,
            /* [in] */ STrnTimeType __RPC_FAR *pTime,
            /* [in] */ DWORD color);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *ActivateMatte )( 
            ITrnEffectsProcessor __RPC_FAR * This,
            /* [in] */ STrnTimeType __RPC_FAR *pTime);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetKeyPriorityTable )( 
            ITrnEffectsProcessor __RPC_FAR * This,
            WORD KPIndex,
            /* [in] */ STrnEPKPTable __RPC_FAR *pTable);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *ActivateKeyPriorityTable )( 
            ITrnEffectsProcessor __RPC_FAR * This,
            /* [in] */ STrnTimeType __RPC_FAR *pTime,
            WORD KPIndex);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryKeyPriorityTable )( 
            ITrnEffectsProcessor __RPC_FAR * This,
            WORD KPIndex,
            /* [out] */ STrnEPKPTable __RPC_FAR *pTable);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryCapabilitiesEx )( 
            ITrnEffectsProcessor __RPC_FAR * This,
            /* [out] */ STrnPCapabilities __RPC_FAR *pCaps,
            /* [out] */ STrnEPCapabilities __RPC_FAR *pECaps);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *LoadAnimStream )( 
            ITrnEffectsProcessor __RPC_FAR * This,
            /* [in] */ IStream __RPC_FAR *pStream,
            DWORD length,
            DWORD __RPC_FAR *pAnimId);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *LoadAnimFile )( 
            ITrnEffectsProcessor __RPC_FAR * This,
            HANDLE hFile,
            DWORD length,
            DWORD __RPC_FAR *pAnimId);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *LoadAnimFileMapping )( 
            ITrnEffectsProcessor __RPC_FAR * This,
            HANDLE hFileMapping,
            DWORD offset,
            DWORD length,
            DWORD __RPC_FAR *pAnimId);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *LoadAnimMemory )( 
            ITrnEffectsProcessor __RPC_FAR * This,
            LPVOID pImage,
            DWORD length,
            DWORD __RPC_FAR *pAnimId);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *ReleaseAnim )( 
            ITrnEffectsProcessor __RPC_FAR * This,
            DWORD AnimId);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *PlayAnim )( 
            ITrnEffectsProcessor __RPC_FAR * This,
            DWORD AnimId,
            /* [in] */ STrnTimeType __RPC_FAR *pTime,
            /* [in] */ STrnPlayList __RPC_FAR *pList);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *ActivatePassThrough )( 
            ITrnEffectsProcessor __RPC_FAR * This,
            /* [in] */ STrnTimeType __RPC_FAR *pTime,
            /* [in] */ DWORD KeepMask);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetLumaThreshold )( 
            ITrnEffectsProcessor __RPC_FAR * This,
            DWORD luma);
        
        END_INTERFACE
    } ITrnEffectsProcessorVtbl;

    interface ITrnEffectsProcessor
    {
        CONST_VTBL struct ITrnEffectsProcessorVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ITrnEffectsProcessor_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define ITrnEffectsProcessor_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define ITrnEffectsProcessor_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define ITrnEffectsProcessor_QueryCapabilities(This,pCaps)	\
    (This)->lpVtbl -> QueryCapabilities(This,pCaps)


#define ITrnEffectsProcessor_SetStrobe(This,pTime,frequency)	\
    (This)->lpVtbl -> SetStrobe(This,pTime,frequency)

#define ITrnEffectsProcessor_SetMatteColor(This,pTime,color)	\
    (This)->lpVtbl -> SetMatteColor(This,pTime,color)

#define ITrnEffectsProcessor_ActivateMatte(This,pTime)	\
    (This)->lpVtbl -> ActivateMatte(This,pTime)

#define ITrnEffectsProcessor_SetKeyPriorityTable(This,KPIndex,pTable)	\
    (This)->lpVtbl -> SetKeyPriorityTable(This,KPIndex,pTable)

#define ITrnEffectsProcessor_ActivateKeyPriorityTable(This,pTime,KPIndex)	\
    (This)->lpVtbl -> ActivateKeyPriorityTable(This,pTime,KPIndex)

#define ITrnEffectsProcessor_QueryKeyPriorityTable(This,KPIndex,pTable)	\
    (This)->lpVtbl -> QueryKeyPriorityTable(This,KPIndex,pTable)


#define ITrnEffectsProcessor_QueryCapabilitiesEx(This,pCaps,pECaps)	\
    (This)->lpVtbl -> QueryCapabilitiesEx(This,pCaps,pECaps)

#define ITrnEffectsProcessor_LoadAnimStream(This,pStream,length,pAnimId)	\
    (This)->lpVtbl -> LoadAnimStream(This,pStream,length,pAnimId)

#define ITrnEffectsProcessor_LoadAnimFile(This,hFile,length,pAnimId)	\
    (This)->lpVtbl -> LoadAnimFile(This,hFile,length,pAnimId)

#define ITrnEffectsProcessor_LoadAnimFileMapping(This,hFileMapping,offset,length,pAnimId)	\
    (This)->lpVtbl -> LoadAnimFileMapping(This,hFileMapping,offset,length,pAnimId)

#define ITrnEffectsProcessor_LoadAnimMemory(This,pImage,length,pAnimId)	\
    (This)->lpVtbl -> LoadAnimMemory(This,pImage,length,pAnimId)

#define ITrnEffectsProcessor_ReleaseAnim(This,AnimId)	\
    (This)->lpVtbl -> ReleaseAnim(This,AnimId)

#define ITrnEffectsProcessor_PlayAnim(This,AnimId,pTime,pList)	\
    (This)->lpVtbl -> PlayAnim(This,AnimId,pTime,pList)

#define ITrnEffectsProcessor_ActivatePassThrough(This,pTime,KeepMask)	\
    (This)->lpVtbl -> ActivatePassThrough(This,pTime,KeepMask)

#define ITrnEffectsProcessor_SetLumaThreshold(This,luma)	\
    (This)->lpVtbl -> SetLumaThreshold(This,luma)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE ITrnEffectsProcessor_QueryCapabilitiesEx_Proxy( 
    ITrnEffectsProcessor __RPC_FAR * This,
    /* [out] */ STrnPCapabilities __RPC_FAR *pCaps,
    /* [out] */ STrnEPCapabilities __RPC_FAR *pECaps);


void __RPC_STUB ITrnEffectsProcessor_QueryCapabilitiesEx_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE ITrnEffectsProcessor_LoadAnimStream_Proxy( 
    ITrnEffectsProcessor __RPC_FAR * This,
    /* [in] */ IStream __RPC_FAR *pStream,
    DWORD length,
    DWORD __RPC_FAR *pAnimId);


void __RPC_STUB ITrnEffectsProcessor_LoadAnimStream_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE ITrnEffectsProcessor_LoadAnimFile_Proxy( 
    ITrnEffectsProcessor __RPC_FAR * This,
    HANDLE hFile,
    DWORD length,
    DWORD __RPC_FAR *pAnimId);


void __RPC_STUB ITrnEffectsProcessor_LoadAnimFile_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE ITrnEffectsProcessor_LoadAnimFileMapping_Proxy( 
    ITrnEffectsProcessor __RPC_FAR * This,
    HANDLE hFileMapping,
    DWORD offset,
    DWORD length,
    DWORD __RPC_FAR *pAnimId);


void __RPC_STUB ITrnEffectsProcessor_LoadAnimFileMapping_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE ITrnEffectsProcessor_LoadAnimMemory_Proxy( 
    ITrnEffectsProcessor __RPC_FAR * This,
    LPVOID pImage,
    DWORD length,
    DWORD __RPC_FAR *pAnimId);


void __RPC_STUB ITrnEffectsProcessor_LoadAnimMemory_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE ITrnEffectsProcessor_ReleaseAnim_Proxy( 
    ITrnEffectsProcessor __RPC_FAR * This,
    DWORD AnimId);


void __RPC_STUB ITrnEffectsProcessor_ReleaseAnim_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE ITrnEffectsProcessor_PlayAnim_Proxy( 
    ITrnEffectsProcessor __RPC_FAR * This,
    DWORD AnimId,
    /* [in] */ STrnTimeType __RPC_FAR *pTime,
    /* [in] */ STrnPlayList __RPC_FAR *pList);


void __RPC_STUB ITrnEffectsProcessor_PlayAnim_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE ITrnEffectsProcessor_ActivatePassThrough_Proxy( 
    ITrnEffectsProcessor __RPC_FAR * This,
    /* [in] */ STrnTimeType __RPC_FAR *pTime,
    /* [in] */ DWORD KeepMask);


void __RPC_STUB ITrnEffectsProcessor_ActivatePassThrough_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE ITrnEffectsProcessor_SetLumaThreshold_Proxy( 
    ITrnEffectsProcessor __RPC_FAR * This,
    DWORD luma);


void __RPC_STUB ITrnEffectsProcessor_SetLumaThreshold_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __ITrnEffectsProcessor_INTERFACE_DEFINED__ */


#ifndef __ITrnStillStore_INTERFACE_DEFINED__
#define __ITrnStillStore_INTERFACE_DEFINED__

/****************************************
 * Generated header for interface: ITrnStillStore
 * at Tue Nov 23 05:28:37 1999
 * using MIDL 3.01.75
 ****************************************/
/* [unique][uuid][object][local] */ 



EXTERN_C const IID IID_ITrnStillStore;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    interface DECLSPEC_UUID("8335e5ea-ab3b-11ce-8468-0000b468276b")
    ITrnStillStore : public ITrnVideoPath
    {
    public:
        virtual DWORD STDMETHODCALLTYPE QueryFrameStoreSize( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GrabFrame( 
            DWORD dwBuffIdx,
            LPVOID pBuffer) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE AllocFrameBuffer( 
            /* [out] */ DWORD __RPC_FAR *pdwBuffIdx,
            /* [out] */ DWORD __RPC_FAR *pdwBuffAddr) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE FreeFrameBuffer( 
            /* [in] */ DWORD dwBuffIdx) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE PrepareWrite( 
            /* [in] */ DWORD dwBuffIdx) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE ShowFrameBuffer( 
            /* [in] */ STrnTimeType __RPC_FAR *pTime,
            /* [in] */ DWORD dwBuffidx) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE DisplayFrame( 
            DWORD dwBuffIdx,
            LPVOID pBuffer) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct ITrnStillStoreVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            ITrnStillStore __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            ITrnStillStore __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            ITrnStillStore __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryCapabilities )( 
            ITrnStillStore __RPC_FAR * This,
            /* [out] */ STrnPCapabilities __RPC_FAR *pCaps);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetStrobe )( 
            ITrnStillStore __RPC_FAR * This,
            /* [in] */ STrnTimeType __RPC_FAR *pTime,
            /* [in] */ DWORD frequency);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetMatteColor )( 
            ITrnStillStore __RPC_FAR * This,
            /* [in] */ STrnTimeType __RPC_FAR *pTime,
            /* [in] */ DWORD color);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *ActivateMatte )( 
            ITrnStillStore __RPC_FAR * This,
            /* [in] */ STrnTimeType __RPC_FAR *pTime);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetKeyPriorityTable )( 
            ITrnStillStore __RPC_FAR * This,
            WORD KPIndex,
            /* [in] */ STrnEPKPTable __RPC_FAR *pTable);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *ActivateKeyPriorityTable )( 
            ITrnStillStore __RPC_FAR * This,
            /* [in] */ STrnTimeType __RPC_FAR *pTime,
            WORD KPIndex);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryKeyPriorityTable )( 
            ITrnStillStore __RPC_FAR * This,
            WORD KPIndex,
            /* [out] */ STrnEPKPTable __RPC_FAR *pTable);
        
        DWORD ( STDMETHODCALLTYPE __RPC_FAR *QueryFrameStoreSize )( 
            ITrnStillStore __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GrabFrame )( 
            ITrnStillStore __RPC_FAR * This,
            DWORD dwBuffIdx,
            LPVOID pBuffer);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *AllocFrameBuffer )( 
            ITrnStillStore __RPC_FAR * This,
            /* [out] */ DWORD __RPC_FAR *pdwBuffIdx,
            /* [out] */ DWORD __RPC_FAR *pdwBuffAddr);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *FreeFrameBuffer )( 
            ITrnStillStore __RPC_FAR * This,
            /* [in] */ DWORD dwBuffIdx);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *PrepareWrite )( 
            ITrnStillStore __RPC_FAR * This,
            /* [in] */ DWORD dwBuffIdx);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *ShowFrameBuffer )( 
            ITrnStillStore __RPC_FAR * This,
            /* [in] */ STrnTimeType __RPC_FAR *pTime,
            /* [in] */ DWORD dwBuffidx);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *DisplayFrame )( 
            ITrnStillStore __RPC_FAR * This,
            DWORD dwBuffIdx,
            LPVOID pBuffer);
        
        END_INTERFACE
    } ITrnStillStoreVtbl;

    interface ITrnStillStore
    {
        CONST_VTBL struct ITrnStillStoreVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ITrnStillStore_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define ITrnStillStore_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define ITrnStillStore_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define ITrnStillStore_QueryCapabilities(This,pCaps)	\
    (This)->lpVtbl -> QueryCapabilities(This,pCaps)


#define ITrnStillStore_SetStrobe(This,pTime,frequency)	\
    (This)->lpVtbl -> SetStrobe(This,pTime,frequency)

#define ITrnStillStore_SetMatteColor(This,pTime,color)	\
    (This)->lpVtbl -> SetMatteColor(This,pTime,color)

#define ITrnStillStore_ActivateMatte(This,pTime)	\
    (This)->lpVtbl -> ActivateMatte(This,pTime)

#define ITrnStillStore_SetKeyPriorityTable(This,KPIndex,pTable)	\
    (This)->lpVtbl -> SetKeyPriorityTable(This,KPIndex,pTable)

#define ITrnStillStore_ActivateKeyPriorityTable(This,pTime,KPIndex)	\
    (This)->lpVtbl -> ActivateKeyPriorityTable(This,pTime,KPIndex)

#define ITrnStillStore_QueryKeyPriorityTable(This,KPIndex,pTable)	\
    (This)->lpVtbl -> QueryKeyPriorityTable(This,KPIndex,pTable)


#define ITrnStillStore_QueryFrameStoreSize(This)	\
    (This)->lpVtbl -> QueryFrameStoreSize(This)

#define ITrnStillStore_GrabFrame(This,dwBuffIdx,pBuffer)	\
    (This)->lpVtbl -> GrabFrame(This,dwBuffIdx,pBuffer)

#define ITrnStillStore_AllocFrameBuffer(This,pdwBuffIdx,pdwBuffAddr)	\
    (This)->lpVtbl -> AllocFrameBuffer(This,pdwBuffIdx,pdwBuffAddr)

#define ITrnStillStore_FreeFrameBuffer(This,dwBuffIdx)	\
    (This)->lpVtbl -> FreeFrameBuffer(This,dwBuffIdx)

#define ITrnStillStore_PrepareWrite(This,dwBuffIdx)	\
    (This)->lpVtbl -> PrepareWrite(This,dwBuffIdx)

#define ITrnStillStore_ShowFrameBuffer(This,pTime,dwBuffidx)	\
    (This)->lpVtbl -> ShowFrameBuffer(This,pTime,dwBuffidx)

#define ITrnStillStore_DisplayFrame(This,dwBuffIdx,pBuffer)	\
    (This)->lpVtbl -> DisplayFrame(This,dwBuffIdx,pBuffer)

#endif /* COBJMACROS */


#endif 	/* C style interface */



DWORD STDMETHODCALLTYPE ITrnStillStore_QueryFrameStoreSize_Proxy( 
    ITrnStillStore __RPC_FAR * This);


void __RPC_STUB ITrnStillStore_QueryFrameStoreSize_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE ITrnStillStore_GrabFrame_Proxy( 
    ITrnStillStore __RPC_FAR * This,
    DWORD dwBuffIdx,
    LPVOID pBuffer);


void __RPC_STUB ITrnStillStore_GrabFrame_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE ITrnStillStore_AllocFrameBuffer_Proxy( 
    ITrnStillStore __RPC_FAR * This,
    /* [out] */ DWORD __RPC_FAR *pdwBuffIdx,
    /* [out] */ DWORD __RPC_FAR *pdwBuffAddr);


void __RPC_STUB ITrnStillStore_AllocFrameBuffer_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE ITrnStillStore_FreeFrameBuffer_Proxy( 
    ITrnStillStore __RPC_FAR * This,
    /* [in] */ DWORD dwBuffIdx);


void __RPC_STUB ITrnStillStore_FreeFrameBuffer_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE ITrnStillStore_PrepareWrite_Proxy( 
    ITrnStillStore __RPC_FAR * This,
    /* [in] */ DWORD dwBuffIdx);


void __RPC_STUB ITrnStillStore_PrepareWrite_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE ITrnStillStore_ShowFrameBuffer_Proxy( 
    ITrnStillStore __RPC_FAR * This,
    /* [in] */ STrnTimeType __RPC_FAR *pTime,
    /* [in] */ DWORD dwBuffidx);


void __RPC_STUB ITrnStillStore_ShowFrameBuffer_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE ITrnStillStore_DisplayFrame_Proxy( 
    ITrnStillStore __RPC_FAR * This,
    DWORD dwBuffIdx,
    LPVOID pBuffer);


void __RPC_STUB ITrnStillStore_DisplayFrame_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __ITrnStillStore_INTERFACE_DEFINED__ */


#ifndef __ITrnVideoEncoder_INTERFACE_DEFINED__
#define __ITrnVideoEncoder_INTERFACE_DEFINED__

/****************************************
 * Generated header for interface: ITrnVideoEncoder
 * at Tue Nov 23 05:28:37 1999
 * using MIDL 3.01.75
 ****************************************/
/* [unique][uuid][object][local] */ 


typedef 
enum tagETrnGenlockMode
    {	GMFreeRun	= 0,
	GMGenLock	= GMFreeRun + 1,
	GMAuto	= GMGenLock + 1,
	GMNotLocked	= GMAuto + 1
    }	ETrnGenlockMode;

typedef 
enum tagETrnEncoderModes
    {	EMNormalMode	= 0,
	EMPreviewGenlock	= 1,
	EMPreviewAlpha	= 2,
	EMColorBars	= 3,
	EMModRamp	= 4,
	EMExclusiveModeMask	= 15,
	EMAlphaSync	= 256,
	EMExtClock	= 512,
	EMMixinModes	= EMAlphaSync + EMExtClock
    }	ETrnEncoderModes;


EXTERN_C const IID IID_ITrnVideoEncoder;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    interface DECLSPEC_UUID("8335e3f9-ab3b-11ce-8468-0000b468276b")
    ITrnVideoEncoder : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE QueryPropsArchive( 
            ITrnPropertiesArchive __RPC_FAR *__RPC_FAR *ppPropsArchive) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE QueryPropSetName( 
            OLECHAR __RPC_FAR *pwszSetNameBuffer,
            unsigned int ccBuffSize,
            DWORD __RPC_FAR *pdwPropsFlags) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE LoadProperties( 
            OLECHAR __RPC_FAR *pwszSetName,
            DWORD __RPC_FAR *pdwPropsFlags) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SaveProperties( 
            OLECHAR __RPC_FAR *pwszSetName,
            ETrnPropertyFlags filterFlags) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct ITrnVideoEncoderVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            ITrnVideoEncoder __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            ITrnVideoEncoder __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            ITrnVideoEncoder __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryPropsArchive )( 
            ITrnVideoEncoder __RPC_FAR * This,
            ITrnPropertiesArchive __RPC_FAR *__RPC_FAR *ppPropsArchive);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryPropSetName )( 
            ITrnVideoEncoder __RPC_FAR * This,
            OLECHAR __RPC_FAR *pwszSetNameBuffer,
            unsigned int ccBuffSize,
            DWORD __RPC_FAR *pdwPropsFlags);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *LoadProperties )( 
            ITrnVideoEncoder __RPC_FAR * This,
            OLECHAR __RPC_FAR *pwszSetName,
            DWORD __RPC_FAR *pdwPropsFlags);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SaveProperties )( 
            ITrnVideoEncoder __RPC_FAR * This,
            OLECHAR __RPC_FAR *pwszSetName,
            ETrnPropertyFlags filterFlags);
        
        END_INTERFACE
    } ITrnVideoEncoderVtbl;

    interface ITrnVideoEncoder
    {
        CONST_VTBL struct ITrnVideoEncoderVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ITrnVideoEncoder_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define ITrnVideoEncoder_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define ITrnVideoEncoder_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define ITrnVideoEncoder_QueryPropsArchive(This,ppPropsArchive)	\
    (This)->lpVtbl -> QueryPropsArchive(This,ppPropsArchive)

#define ITrnVideoEncoder_QueryPropSetName(This,pwszSetNameBuffer,ccBuffSize,pdwPropsFlags)	\
    (This)->lpVtbl -> QueryPropSetName(This,pwszSetNameBuffer,ccBuffSize,pdwPropsFlags)

#define ITrnVideoEncoder_LoadProperties(This,pwszSetName,pdwPropsFlags)	\
    (This)->lpVtbl -> LoadProperties(This,pwszSetName,pdwPropsFlags)

#define ITrnVideoEncoder_SaveProperties(This,pwszSetName,filterFlags)	\
    (This)->lpVtbl -> SaveProperties(This,pwszSetName,filterFlags)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE ITrnVideoEncoder_QueryPropsArchive_Proxy( 
    ITrnVideoEncoder __RPC_FAR * This,
    ITrnPropertiesArchive __RPC_FAR *__RPC_FAR *ppPropsArchive);


void __RPC_STUB ITrnVideoEncoder_QueryPropsArchive_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE ITrnVideoEncoder_QueryPropSetName_Proxy( 
    ITrnVideoEncoder __RPC_FAR * This,
    OLECHAR __RPC_FAR *pwszSetNameBuffer,
    unsigned int ccBuffSize,
    DWORD __RPC_FAR *pdwPropsFlags);


void __RPC_STUB ITrnVideoEncoder_QueryPropSetName_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE ITrnVideoEncoder_LoadProperties_Proxy( 
    ITrnVideoEncoder __RPC_FAR * This,
    OLECHAR __RPC_FAR *pwszSetName,
    DWORD __RPC_FAR *pdwPropsFlags);


void __RPC_STUB ITrnVideoEncoder_LoadProperties_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE ITrnVideoEncoder_SaveProperties_Proxy( 
    ITrnVideoEncoder __RPC_FAR * This,
    OLECHAR __RPC_FAR *pwszSetName,
    ETrnPropertyFlags filterFlags);


void __RPC_STUB ITrnVideoEncoder_SaveProperties_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __ITrnVideoEncoder_INTERFACE_DEFINED__ */


#ifndef __ITrnCompositeEncoder1_INTERFACE_DEFINED__
#define __ITrnCompositeEncoder1_INTERFACE_DEFINED__

/****************************************
 * Generated header for interface: ITrnCompositeEncoder1
 * at Tue Nov 23 05:28:37 1999
 * using MIDL 3.01.75
 ****************************************/
/* [unique][uuid][object][local] */ 



EXTERN_C const IID IID_ITrnCompositeEncoder1;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    interface DECLSPEC_UUID("8335e3fa-ab3b-11ce-8468-0000b468276b")
    ITrnCompositeEncoder1 : public ITrnVideoEncoder
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE LoadMapTable( 
            /* [in] */ DWORD MapIndex,
            /* [size_is][in] */ BYTE __RPC_FAR *pTable) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct ITrnCompositeEncoder1Vtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            ITrnCompositeEncoder1 __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            ITrnCompositeEncoder1 __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            ITrnCompositeEncoder1 __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryPropsArchive )( 
            ITrnCompositeEncoder1 __RPC_FAR * This,
            ITrnPropertiesArchive __RPC_FAR *__RPC_FAR *ppPropsArchive);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryPropSetName )( 
            ITrnCompositeEncoder1 __RPC_FAR * This,
            OLECHAR __RPC_FAR *pwszSetNameBuffer,
            unsigned int ccBuffSize,
            DWORD __RPC_FAR *pdwPropsFlags);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *LoadProperties )( 
            ITrnCompositeEncoder1 __RPC_FAR * This,
            OLECHAR __RPC_FAR *pwszSetName,
            DWORD __RPC_FAR *pdwPropsFlags);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SaveProperties )( 
            ITrnCompositeEncoder1 __RPC_FAR * This,
            OLECHAR __RPC_FAR *pwszSetName,
            ETrnPropertyFlags filterFlags);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *LoadMapTable )( 
            ITrnCompositeEncoder1 __RPC_FAR * This,
            /* [in] */ DWORD MapIndex,
            /* [size_is][in] */ BYTE __RPC_FAR *pTable);
        
        END_INTERFACE
    } ITrnCompositeEncoder1Vtbl;

    interface ITrnCompositeEncoder1
    {
        CONST_VTBL struct ITrnCompositeEncoder1Vtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ITrnCompositeEncoder1_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define ITrnCompositeEncoder1_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define ITrnCompositeEncoder1_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define ITrnCompositeEncoder1_QueryPropsArchive(This,ppPropsArchive)	\
    (This)->lpVtbl -> QueryPropsArchive(This,ppPropsArchive)

#define ITrnCompositeEncoder1_QueryPropSetName(This,pwszSetNameBuffer,ccBuffSize,pdwPropsFlags)	\
    (This)->lpVtbl -> QueryPropSetName(This,pwszSetNameBuffer,ccBuffSize,pdwPropsFlags)

#define ITrnCompositeEncoder1_LoadProperties(This,pwszSetName,pdwPropsFlags)	\
    (This)->lpVtbl -> LoadProperties(This,pwszSetName,pdwPropsFlags)

#define ITrnCompositeEncoder1_SaveProperties(This,pwszSetName,filterFlags)	\
    (This)->lpVtbl -> SaveProperties(This,pwszSetName,filterFlags)


#define ITrnCompositeEncoder1_LoadMapTable(This,MapIndex,pTable)	\
    (This)->lpVtbl -> LoadMapTable(This,MapIndex,pTable)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE ITrnCompositeEncoder1_LoadMapTable_Proxy( 
    ITrnCompositeEncoder1 __RPC_FAR * This,
    /* [in] */ DWORD MapIndex,
    /* [size_is][in] */ BYTE __RPC_FAR *pTable);


void __RPC_STUB ITrnCompositeEncoder1_LoadMapTable_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __ITrnCompositeEncoder1_INTERFACE_DEFINED__ */


#ifndef __ITrnDownstreamProcessor_INTERFACE_DEFINED__
#define __ITrnDownstreamProcessor_INTERFACE_DEFINED__

/****************************************
 * Generated header for interface: ITrnDownstreamProcessor
 * at Tue Nov 23 05:28:37 1999
 * using MIDL 3.01.75
 ****************************************/
/* [unique][uuid][object][local] */ 


typedef struct  tagSTrnDSCapabilities
    {
    BOOL MasterReference;
    BOOL MasterExtIn;
    BOOL SyncDetect;
    BOOL ExtVideoIn;
    BOOL ExtAlphaIn;
    DWORD InputFormats;
    BOOL WritableFrame;
    BOOL ReadableFrame;
    }	STrnDSCapabilities;


EXTERN_C const IID IID_ITrnDownstreamProcessor;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    interface DECLSPEC_UUID("8335e3de-ab3b-11ce-8468-0000b468276b")
    ITrnDownstreamProcessor : public ITrnProcessor
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE QueryCapabilitiesEx( 
            /* [out] */ STrnPCapabilities __RPC_FAR *pCaps,
            /* [out] */ STrnDSCapabilities __RPC_FAR *pECaps) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE ActivatePassThrough( 
            /* [in] */ STrnTimeType __RPC_FAR *pTime) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct ITrnDownstreamProcessorVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            ITrnDownstreamProcessor __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            ITrnDownstreamProcessor __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            ITrnDownstreamProcessor __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryCapabilities )( 
            ITrnDownstreamProcessor __RPC_FAR * This,
            /* [out] */ STrnPCapabilities __RPC_FAR *pCaps);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryCapabilitiesEx )( 
            ITrnDownstreamProcessor __RPC_FAR * This,
            /* [out] */ STrnPCapabilities __RPC_FAR *pCaps,
            /* [out] */ STrnDSCapabilities __RPC_FAR *pECaps);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *ActivatePassThrough )( 
            ITrnDownstreamProcessor __RPC_FAR * This,
            /* [in] */ STrnTimeType __RPC_FAR *pTime);
        
        END_INTERFACE
    } ITrnDownstreamProcessorVtbl;

    interface ITrnDownstreamProcessor
    {
        CONST_VTBL struct ITrnDownstreamProcessorVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ITrnDownstreamProcessor_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define ITrnDownstreamProcessor_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define ITrnDownstreamProcessor_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define ITrnDownstreamProcessor_QueryCapabilities(This,pCaps)	\
    (This)->lpVtbl -> QueryCapabilities(This,pCaps)


#define ITrnDownstreamProcessor_QueryCapabilitiesEx(This,pCaps,pECaps)	\
    (This)->lpVtbl -> QueryCapabilitiesEx(This,pCaps,pECaps)

#define ITrnDownstreamProcessor_ActivatePassThrough(This,pTime)	\
    (This)->lpVtbl -> ActivatePassThrough(This,pTime)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE ITrnDownstreamProcessor_QueryCapabilitiesEx_Proxy( 
    ITrnDownstreamProcessor __RPC_FAR * This,
    /* [out] */ STrnPCapabilities __RPC_FAR *pCaps,
    /* [out] */ STrnDSCapabilities __RPC_FAR *pECaps);


void __RPC_STUB ITrnDownstreamProcessor_QueryCapabilitiesEx_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE ITrnDownstreamProcessor_ActivatePassThrough_Proxy( 
    ITrnDownstreamProcessor __RPC_FAR * This,
    /* [in] */ STrnTimeType __RPC_FAR *pTime);


void __RPC_STUB ITrnDownstreamProcessor_ActivatePassThrough_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __ITrnDownstreamProcessor_INTERFACE_DEFINED__ */


#ifndef __ITrnVideoRouter_INTERFACE_DEFINED__
#define __ITrnVideoRouter_INTERFACE_DEFINED__

/****************************************
 * Generated header for interface: ITrnVideoRouter
 * at Tue Nov 23 05:28:37 1999
 * using MIDL 3.01.75
 ****************************************/
/* [unique][uuid][object][local] */ 


typedef struct  tagSTrnRTRCapabilities
    {
    WORD usInputs;
    WORD usOutputs;
    WORD usMultiOut;
    WORD usDepth;
    BOOL bAlphaRouting;
    BOOL bAlphaIndependent;
    WORD usAlphaInputs;
    WORD usAlphaOutputs;
    WORD usAlphaMultiOut;
    WORD usAlphaDepth;
    }	STrnRTRCapabilities;

typedef 
enum tagETrnIOMuxSource
    {	InOutModule1	= 0,
	InOutModule2	= InOutModule1 + 1,
	InOutModule3	= InOutModule2 + 1
    }	ETrnIOMuxSource;


EXTERN_C const IID IID_ITrnVideoRouter;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    interface DECLSPEC_UUID("8335e3dd-ab3b-11ce-8468-0000b468276b")
    ITrnVideoRouter : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE QueryCapabilities( 
            /* [out] */ STrnRTRCapabilities __RPC_FAR *pCaps) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE ActivateYUVRoute( 
            /* [in] */ STrnTimeType __RPC_FAR *pTime,
            ETrnRouterSource source,
            WORD dest) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE ActivateAlphaRoute( 
            /* [in] */ STrnTimeType __RPC_FAR *pTime,
            ETrnRouterSource source,
            WORD dest) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetInOutModuleMux( 
            ETrnIOMuxSource source) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SwapRoutes( 
            /* [in] */ STrnTimeType __RPC_FAR *pTime,
            /* [in] */ DWORD Output1,
            /* [in] */ DWORD Output2) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE QueryVideoRoutes( 
            /* [out] */ WORD __RPC_FAR *pSources) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE QueryAlphaRoutes( 
            /* [out] */ WORD __RPC_FAR *pSources) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct ITrnVideoRouterVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            ITrnVideoRouter __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            ITrnVideoRouter __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            ITrnVideoRouter __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryCapabilities )( 
            ITrnVideoRouter __RPC_FAR * This,
            /* [out] */ STrnRTRCapabilities __RPC_FAR *pCaps);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *ActivateYUVRoute )( 
            ITrnVideoRouter __RPC_FAR * This,
            /* [in] */ STrnTimeType __RPC_FAR *pTime,
            ETrnRouterSource source,
            WORD dest);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *ActivateAlphaRoute )( 
            ITrnVideoRouter __RPC_FAR * This,
            /* [in] */ STrnTimeType __RPC_FAR *pTime,
            ETrnRouterSource source,
            WORD dest);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetInOutModuleMux )( 
            ITrnVideoRouter __RPC_FAR * This,
            ETrnIOMuxSource source);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SwapRoutes )( 
            ITrnVideoRouter __RPC_FAR * This,
            /* [in] */ STrnTimeType __RPC_FAR *pTime,
            /* [in] */ DWORD Output1,
            /* [in] */ DWORD Output2);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryVideoRoutes )( 
            ITrnVideoRouter __RPC_FAR * This,
            /* [out] */ WORD __RPC_FAR *pSources);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryAlphaRoutes )( 
            ITrnVideoRouter __RPC_FAR * This,
            /* [out] */ WORD __RPC_FAR *pSources);
        
        END_INTERFACE
    } ITrnVideoRouterVtbl;

    interface ITrnVideoRouter
    {
        CONST_VTBL struct ITrnVideoRouterVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ITrnVideoRouter_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define ITrnVideoRouter_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define ITrnVideoRouter_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define ITrnVideoRouter_QueryCapabilities(This,pCaps)	\
    (This)->lpVtbl -> QueryCapabilities(This,pCaps)

#define ITrnVideoRouter_ActivateYUVRoute(This,pTime,source,dest)	\
    (This)->lpVtbl -> ActivateYUVRoute(This,pTime,source,dest)

#define ITrnVideoRouter_ActivateAlphaRoute(This,pTime,source,dest)	\
    (This)->lpVtbl -> ActivateAlphaRoute(This,pTime,source,dest)

#define ITrnVideoRouter_SetInOutModuleMux(This,source)	\
    (This)->lpVtbl -> SetInOutModuleMux(This,source)

#define ITrnVideoRouter_SwapRoutes(This,pTime,Output1,Output2)	\
    (This)->lpVtbl -> SwapRoutes(This,pTime,Output1,Output2)

#define ITrnVideoRouter_QueryVideoRoutes(This,pSources)	\
    (This)->lpVtbl -> QueryVideoRoutes(This,pSources)

#define ITrnVideoRouter_QueryAlphaRoutes(This,pSources)	\
    (This)->lpVtbl -> QueryAlphaRoutes(This,pSources)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE ITrnVideoRouter_QueryCapabilities_Proxy( 
    ITrnVideoRouter __RPC_FAR * This,
    /* [out] */ STrnRTRCapabilities __RPC_FAR *pCaps);


void __RPC_STUB ITrnVideoRouter_QueryCapabilities_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE ITrnVideoRouter_ActivateYUVRoute_Proxy( 
    ITrnVideoRouter __RPC_FAR * This,
    /* [in] */ STrnTimeType __RPC_FAR *pTime,
    ETrnRouterSource source,
    WORD dest);


void __RPC_STUB ITrnVideoRouter_ActivateYUVRoute_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE ITrnVideoRouter_ActivateAlphaRoute_Proxy( 
    ITrnVideoRouter __RPC_FAR * This,
    /* [in] */ STrnTimeType __RPC_FAR *pTime,
    ETrnRouterSource source,
    WORD dest);


void __RPC_STUB ITrnVideoRouter_ActivateAlphaRoute_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE ITrnVideoRouter_SetInOutModuleMux_Proxy( 
    ITrnVideoRouter __RPC_FAR * This,
    ETrnIOMuxSource source);


void __RPC_STUB ITrnVideoRouter_SetInOutModuleMux_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE ITrnVideoRouter_SwapRoutes_Proxy( 
    ITrnVideoRouter __RPC_FAR * This,
    /* [in] */ STrnTimeType __RPC_FAR *pTime,
    /* [in] */ DWORD Output1,
    /* [in] */ DWORD Output2);


void __RPC_STUB ITrnVideoRouter_SwapRoutes_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE ITrnVideoRouter_QueryVideoRoutes_Proxy( 
    ITrnVideoRouter __RPC_FAR * This,
    /* [out] */ WORD __RPC_FAR *pSources);


void __RPC_STUB ITrnVideoRouter_QueryVideoRoutes_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE ITrnVideoRouter_QueryAlphaRoutes_Proxy( 
    ITrnVideoRouter __RPC_FAR * This,
    /* [out] */ WORD __RPC_FAR *pSources);


void __RPC_STUB ITrnVideoRouter_QueryAlphaRoutes_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __ITrnVideoRouter_INTERFACE_DEFINED__ */


#ifndef __ITrnVideoSwitcher_INTERFACE_DEFINED__
#define __ITrnVideoSwitcher_INTERFACE_DEFINED__

/****************************************
 * Generated header for interface: ITrnVideoSwitcher
 * at Tue Nov 23 05:28:37 1999
 * using MIDL 3.01.75
 ****************************************/
/* [unique][uuid][object][local] */ 


typedef 
enum tagETrnSWPreviewSource
    {	PSABus	= 0,
	PSBBus	= 1,
	PSMainMixer	= 2,
	PSGraphics	= 3,
	PSCBus	= 3,
	PSDSMixer	= 4
    }	ETrnSWPreviewSource;

typedef 
enum tagETrnSWMainAlphaMode
    {	MAFixed	= 0,
	MAFIFO	= 1,
	MAChromaCLUT	= 2,
	MAExternal	= 3
    }	ETrnSWMainAlphaMode;

typedef 
enum tagETrnSWMainVideoMode
    {	MVColor	= 0,
	MVMonochrome	= MVColor + 1
    }	ETrnSWMainVideoMode;

typedef 
enum tagETrnSWDSAlphaMode
    {	DAFixed	= 0,
	DAFIFO	= 1,
	DAMainAlphaOut	= 2,
	DAExternal	= 3
    }	ETrnSWDSAlphaMode;

typedef 
enum tagETrnSWDSVideoMode
    {	DVCGIndex	= 0,
	DVColor	= DVCGIndex + 1,
	DVMonochrome	= DVColor + 1
    }	ETrnSWDSVideoMode;


EXTERN_C const IID IID_ITrnVideoSwitcher;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    interface DECLSPEC_UUID("8335e3e1-ab3b-11ce-8468-0000b468276b")
    ITrnVideoSwitcher : public ITrnProcessor
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE SelectPreviewSource( 
            /* [in] */ STrnTimeType __RPC_FAR *pTime,
            ETrnSWPreviewSource source) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetMainAlphaMode( 
            /* [in] */ STrnTimeType __RPC_FAR *pTime,
            /* [in] */ ETrnSWMainAlphaMode alphaMode) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE QueryMainAlphaMode( 
            /* [out] */ ETrnSWMainAlphaMode __RPC_FAR *pMode) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetMainAlpha( 
            /* [in] */ STrnTimeType __RPC_FAR *pTime,
            /* [in] */ STrnPlayList __RPC_FAR *pPlayList) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetMainVideoMode( 
            /* [in] */ STrnTimeType __RPC_FAR *pTime,
            /* [in] */ ETrnSWMainVideoMode aBusMode,
            /* [in] */ ETrnSWMainVideoMode bBusMode) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE QueryMainVideoMode( 
            /* [out] */ ETrnSWMainVideoMode __RPC_FAR *pABusMode,
            /* [out] */ ETrnSWMainVideoMode __RPC_FAR *pBBusMode) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetDSAlphaMode( 
            /* [in] */ STrnTimeType __RPC_FAR *pTime,
            /* [in] */ ETrnSWDSAlphaMode alphaMode) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE QueryDSAlphaMode( 
            /* [out] */ ETrnSWDSAlphaMode __RPC_FAR *pMode) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetDSAlpha( 
            /* [in] */ STrnTimeType __RPC_FAR *pTime,
            /* [in] */ STrnPlayList __RPC_FAR *pPlayList) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetDSVideoMode( 
            /* [in] */ STrnTimeType __RPC_FAR *pTime,
            ETrnSWDSVideoMode cBusMode) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE QueryDSVideoMode( 
            /* [out] */ ETrnSWDSVideoMode __RPC_FAR *pMode) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE LoadAnimStream( 
            /* [in] */ IStream __RPC_FAR *pStream,
            DWORD length,
            DWORD __RPC_FAR *pAnimId) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE LoadAnimFile( 
            HANDLE hFile,
            DWORD length,
            DWORD __RPC_FAR *pAnimId) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE LoadAnimFileMapping( 
            HANDLE hFileMapping,
            DWORD offset,
            DWORD length,
            DWORD __RPC_FAR *pAnimId) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE LoadAnimMemory( 
            LPVOID pImage,
            DWORD length,
            DWORD __RPC_FAR *pAnimId) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE ReleaseAnim( 
            DWORD AnimId) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE PlayAnim( 
            DWORD animId,
            /* [in] */ STrnTimeType __RPC_FAR *pTime,
            /* [in] */ STrnPlayList __RPC_FAR *pList) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GrabAnimFrame( 
            DWORD animId,
            WORD frameIndex,
            /* [in] */ STrnRect __RPC_FAR *pSourceRect,
            /* [out] */ SPlayBitMap __RPC_FAR *pBitMap,
            /* [in] */ STrnRect __RPC_FAR *pDestRect) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE UpdateAnimFrame( 
            DWORD animId,
            WORD frameIndex,
            /* [in] */ STrnRect __RPC_FAR *pDestRect,
            /* [in] */ SPlayBitMap __RPC_FAR *pBitMap,
            /* [in] */ STrnRect __RPC_FAR *pSourceRect) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE EnterPassiveState( 
            /* [in] */ const STrnTimeType __RPC_FAR *pTime) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct ITrnVideoSwitcherVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            ITrnVideoSwitcher __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            ITrnVideoSwitcher __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            ITrnVideoSwitcher __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryCapabilities )( 
            ITrnVideoSwitcher __RPC_FAR * This,
            /* [out] */ STrnPCapabilities __RPC_FAR *pCaps);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SelectPreviewSource )( 
            ITrnVideoSwitcher __RPC_FAR * This,
            /* [in] */ STrnTimeType __RPC_FAR *pTime,
            ETrnSWPreviewSource source);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetMainAlphaMode )( 
            ITrnVideoSwitcher __RPC_FAR * This,
            /* [in] */ STrnTimeType __RPC_FAR *pTime,
            /* [in] */ ETrnSWMainAlphaMode alphaMode);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryMainAlphaMode )( 
            ITrnVideoSwitcher __RPC_FAR * This,
            /* [out] */ ETrnSWMainAlphaMode __RPC_FAR *pMode);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetMainAlpha )( 
            ITrnVideoSwitcher __RPC_FAR * This,
            /* [in] */ STrnTimeType __RPC_FAR *pTime,
            /* [in] */ STrnPlayList __RPC_FAR *pPlayList);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetMainVideoMode )( 
            ITrnVideoSwitcher __RPC_FAR * This,
            /* [in] */ STrnTimeType __RPC_FAR *pTime,
            /* [in] */ ETrnSWMainVideoMode aBusMode,
            /* [in] */ ETrnSWMainVideoMode bBusMode);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryMainVideoMode )( 
            ITrnVideoSwitcher __RPC_FAR * This,
            /* [out] */ ETrnSWMainVideoMode __RPC_FAR *pABusMode,
            /* [out] */ ETrnSWMainVideoMode __RPC_FAR *pBBusMode);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetDSAlphaMode )( 
            ITrnVideoSwitcher __RPC_FAR * This,
            /* [in] */ STrnTimeType __RPC_FAR *pTime,
            /* [in] */ ETrnSWDSAlphaMode alphaMode);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryDSAlphaMode )( 
            ITrnVideoSwitcher __RPC_FAR * This,
            /* [out] */ ETrnSWDSAlphaMode __RPC_FAR *pMode);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetDSAlpha )( 
            ITrnVideoSwitcher __RPC_FAR * This,
            /* [in] */ STrnTimeType __RPC_FAR *pTime,
            /* [in] */ STrnPlayList __RPC_FAR *pPlayList);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetDSVideoMode )( 
            ITrnVideoSwitcher __RPC_FAR * This,
            /* [in] */ STrnTimeType __RPC_FAR *pTime,
            ETrnSWDSVideoMode cBusMode);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryDSVideoMode )( 
            ITrnVideoSwitcher __RPC_FAR * This,
            /* [out] */ ETrnSWDSVideoMode __RPC_FAR *pMode);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *LoadAnimStream )( 
            ITrnVideoSwitcher __RPC_FAR * This,
            /* [in] */ IStream __RPC_FAR *pStream,
            DWORD length,
            DWORD __RPC_FAR *pAnimId);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *LoadAnimFile )( 
            ITrnVideoSwitcher __RPC_FAR * This,
            HANDLE hFile,
            DWORD length,
            DWORD __RPC_FAR *pAnimId);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *LoadAnimFileMapping )( 
            ITrnVideoSwitcher __RPC_FAR * This,
            HANDLE hFileMapping,
            DWORD offset,
            DWORD length,
            DWORD __RPC_FAR *pAnimId);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *LoadAnimMemory )( 
            ITrnVideoSwitcher __RPC_FAR * This,
            LPVOID pImage,
            DWORD length,
            DWORD __RPC_FAR *pAnimId);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *ReleaseAnim )( 
            ITrnVideoSwitcher __RPC_FAR * This,
            DWORD AnimId);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *PlayAnim )( 
            ITrnVideoSwitcher __RPC_FAR * This,
            DWORD animId,
            /* [in] */ STrnTimeType __RPC_FAR *pTime,
            /* [in] */ STrnPlayList __RPC_FAR *pList);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GrabAnimFrame )( 
            ITrnVideoSwitcher __RPC_FAR * This,
            DWORD animId,
            WORD frameIndex,
            /* [in] */ STrnRect __RPC_FAR *pSourceRect,
            /* [out] */ SPlayBitMap __RPC_FAR *pBitMap,
            /* [in] */ STrnRect __RPC_FAR *pDestRect);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *UpdateAnimFrame )( 
            ITrnVideoSwitcher __RPC_FAR * This,
            DWORD animId,
            WORD frameIndex,
            /* [in] */ STrnRect __RPC_FAR *pDestRect,
            /* [in] */ SPlayBitMap __RPC_FAR *pBitMap,
            /* [in] */ STrnRect __RPC_FAR *pSourceRect);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *EnterPassiveState )( 
            ITrnVideoSwitcher __RPC_FAR * This,
            /* [in] */ const STrnTimeType __RPC_FAR *pTime);
        
        END_INTERFACE
    } ITrnVideoSwitcherVtbl;

    interface ITrnVideoSwitcher
    {
        CONST_VTBL struct ITrnVideoSwitcherVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ITrnVideoSwitcher_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define ITrnVideoSwitcher_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define ITrnVideoSwitcher_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define ITrnVideoSwitcher_QueryCapabilities(This,pCaps)	\
    (This)->lpVtbl -> QueryCapabilities(This,pCaps)


#define ITrnVideoSwitcher_SelectPreviewSource(This,pTime,source)	\
    (This)->lpVtbl -> SelectPreviewSource(This,pTime,source)

#define ITrnVideoSwitcher_SetMainAlphaMode(This,pTime,alphaMode)	\
    (This)->lpVtbl -> SetMainAlphaMode(This,pTime,alphaMode)

#define ITrnVideoSwitcher_QueryMainAlphaMode(This,pMode)	\
    (This)->lpVtbl -> QueryMainAlphaMode(This,pMode)

#define ITrnVideoSwitcher_SetMainAlpha(This,pTime,pPlayList)	\
    (This)->lpVtbl -> SetMainAlpha(This,pTime,pPlayList)

#define ITrnVideoSwitcher_SetMainVideoMode(This,pTime,aBusMode,bBusMode)	\
    (This)->lpVtbl -> SetMainVideoMode(This,pTime,aBusMode,bBusMode)

#define ITrnVideoSwitcher_QueryMainVideoMode(This,pABusMode,pBBusMode)	\
    (This)->lpVtbl -> QueryMainVideoMode(This,pABusMode,pBBusMode)

#define ITrnVideoSwitcher_SetDSAlphaMode(This,pTime,alphaMode)	\
    (This)->lpVtbl -> SetDSAlphaMode(This,pTime,alphaMode)

#define ITrnVideoSwitcher_QueryDSAlphaMode(This,pMode)	\
    (This)->lpVtbl -> QueryDSAlphaMode(This,pMode)

#define ITrnVideoSwitcher_SetDSAlpha(This,pTime,pPlayList)	\
    (This)->lpVtbl -> SetDSAlpha(This,pTime,pPlayList)

#define ITrnVideoSwitcher_SetDSVideoMode(This,pTime,cBusMode)	\
    (This)->lpVtbl -> SetDSVideoMode(This,pTime,cBusMode)

#define ITrnVideoSwitcher_QueryDSVideoMode(This,pMode)	\
    (This)->lpVtbl -> QueryDSVideoMode(This,pMode)

#define ITrnVideoSwitcher_LoadAnimStream(This,pStream,length,pAnimId)	\
    (This)->lpVtbl -> LoadAnimStream(This,pStream,length,pAnimId)

#define ITrnVideoSwitcher_LoadAnimFile(This,hFile,length,pAnimId)	\
    (This)->lpVtbl -> LoadAnimFile(This,hFile,length,pAnimId)

#define ITrnVideoSwitcher_LoadAnimFileMapping(This,hFileMapping,offset,length,pAnimId)	\
    (This)->lpVtbl -> LoadAnimFileMapping(This,hFileMapping,offset,length,pAnimId)

#define ITrnVideoSwitcher_LoadAnimMemory(This,pImage,length,pAnimId)	\
    (This)->lpVtbl -> LoadAnimMemory(This,pImage,length,pAnimId)

#define ITrnVideoSwitcher_ReleaseAnim(This,AnimId)	\
    (This)->lpVtbl -> ReleaseAnim(This,AnimId)

#define ITrnVideoSwitcher_PlayAnim(This,animId,pTime,pList)	\
    (This)->lpVtbl -> PlayAnim(This,animId,pTime,pList)

#define ITrnVideoSwitcher_GrabAnimFrame(This,animId,frameIndex,pSourceRect,pBitMap,pDestRect)	\
    (This)->lpVtbl -> GrabAnimFrame(This,animId,frameIndex,pSourceRect,pBitMap,pDestRect)

#define ITrnVideoSwitcher_UpdateAnimFrame(This,animId,frameIndex,pDestRect,pBitMap,pSourceRect)	\
    (This)->lpVtbl -> UpdateAnimFrame(This,animId,frameIndex,pDestRect,pBitMap,pSourceRect)

#define ITrnVideoSwitcher_EnterPassiveState(This,pTime)	\
    (This)->lpVtbl -> EnterPassiveState(This,pTime)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE ITrnVideoSwitcher_SelectPreviewSource_Proxy( 
    ITrnVideoSwitcher __RPC_FAR * This,
    /* [in] */ STrnTimeType __RPC_FAR *pTime,
    ETrnSWPreviewSource source);


void __RPC_STUB ITrnVideoSwitcher_SelectPreviewSource_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE ITrnVideoSwitcher_SetMainAlphaMode_Proxy( 
    ITrnVideoSwitcher __RPC_FAR * This,
    /* [in] */ STrnTimeType __RPC_FAR *pTime,
    /* [in] */ ETrnSWMainAlphaMode alphaMode);


void __RPC_STUB ITrnVideoSwitcher_SetMainAlphaMode_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE ITrnVideoSwitcher_QueryMainAlphaMode_Proxy( 
    ITrnVideoSwitcher __RPC_FAR * This,
    /* [out] */ ETrnSWMainAlphaMode __RPC_FAR *pMode);


void __RPC_STUB ITrnVideoSwitcher_QueryMainAlphaMode_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE ITrnVideoSwitcher_SetMainAlpha_Proxy( 
    ITrnVideoSwitcher __RPC_FAR * This,
    /* [in] */ STrnTimeType __RPC_FAR *pTime,
    /* [in] */ STrnPlayList __RPC_FAR *pPlayList);


void __RPC_STUB ITrnVideoSwitcher_SetMainAlpha_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE ITrnVideoSwitcher_SetMainVideoMode_Proxy( 
    ITrnVideoSwitcher __RPC_FAR * This,
    /* [in] */ STrnTimeType __RPC_FAR *pTime,
    /* [in] */ ETrnSWMainVideoMode aBusMode,
    /* [in] */ ETrnSWMainVideoMode bBusMode);


void __RPC_STUB ITrnVideoSwitcher_SetMainVideoMode_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE ITrnVideoSwitcher_QueryMainVideoMode_Proxy( 
    ITrnVideoSwitcher __RPC_FAR * This,
    /* [out] */ ETrnSWMainVideoMode __RPC_FAR *pABusMode,
    /* [out] */ ETrnSWMainVideoMode __RPC_FAR *pBBusMode);


void __RPC_STUB ITrnVideoSwitcher_QueryMainVideoMode_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE ITrnVideoSwitcher_SetDSAlphaMode_Proxy( 
    ITrnVideoSwitcher __RPC_FAR * This,
    /* [in] */ STrnTimeType __RPC_FAR *pTime,
    /* [in] */ ETrnSWDSAlphaMode alphaMode);


void __RPC_STUB ITrnVideoSwitcher_SetDSAlphaMode_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE ITrnVideoSwitcher_QueryDSAlphaMode_Proxy( 
    ITrnVideoSwitcher __RPC_FAR * This,
    /* [out] */ ETrnSWDSAlphaMode __RPC_FAR *pMode);


void __RPC_STUB ITrnVideoSwitcher_QueryDSAlphaMode_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE ITrnVideoSwitcher_SetDSAlpha_Proxy( 
    ITrnVideoSwitcher __RPC_FAR * This,
    /* [in] */ STrnTimeType __RPC_FAR *pTime,
    /* [in] */ STrnPlayList __RPC_FAR *pPlayList);


void __RPC_STUB ITrnVideoSwitcher_SetDSAlpha_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE ITrnVideoSwitcher_SetDSVideoMode_Proxy( 
    ITrnVideoSwitcher __RPC_FAR * This,
    /* [in] */ STrnTimeType __RPC_FAR *pTime,
    ETrnSWDSVideoMode cBusMode);


void __RPC_STUB ITrnVideoSwitcher_SetDSVideoMode_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE ITrnVideoSwitcher_QueryDSVideoMode_Proxy( 
    ITrnVideoSwitcher __RPC_FAR * This,
    /* [out] */ ETrnSWDSVideoMode __RPC_FAR *pMode);


void __RPC_STUB ITrnVideoSwitcher_QueryDSVideoMode_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE ITrnVideoSwitcher_LoadAnimStream_Proxy( 
    ITrnVideoSwitcher __RPC_FAR * This,
    /* [in] */ IStream __RPC_FAR *pStream,
    DWORD length,
    DWORD __RPC_FAR *pAnimId);


void __RPC_STUB ITrnVideoSwitcher_LoadAnimStream_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE ITrnVideoSwitcher_LoadAnimFile_Proxy( 
    ITrnVideoSwitcher __RPC_FAR * This,
    HANDLE hFile,
    DWORD length,
    DWORD __RPC_FAR *pAnimId);


void __RPC_STUB ITrnVideoSwitcher_LoadAnimFile_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE ITrnVideoSwitcher_LoadAnimFileMapping_Proxy( 
    ITrnVideoSwitcher __RPC_FAR * This,
    HANDLE hFileMapping,
    DWORD offset,
    DWORD length,
    DWORD __RPC_FAR *pAnimId);


void __RPC_STUB ITrnVideoSwitcher_LoadAnimFileMapping_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE ITrnVideoSwitcher_LoadAnimMemory_Proxy( 
    ITrnVideoSwitcher __RPC_FAR * This,
    LPVOID pImage,
    DWORD length,
    DWORD __RPC_FAR *pAnimId);


void __RPC_STUB ITrnVideoSwitcher_LoadAnimMemory_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE ITrnVideoSwitcher_ReleaseAnim_Proxy( 
    ITrnVideoSwitcher __RPC_FAR * This,
    DWORD AnimId);


void __RPC_STUB ITrnVideoSwitcher_ReleaseAnim_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE ITrnVideoSwitcher_PlayAnim_Proxy( 
    ITrnVideoSwitcher __RPC_FAR * This,
    DWORD animId,
    /* [in] */ STrnTimeType __RPC_FAR *pTime,
    /* [in] */ STrnPlayList __RPC_FAR *pList);


void __RPC_STUB ITrnVideoSwitcher_PlayAnim_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE ITrnVideoSwitcher_GrabAnimFrame_Proxy( 
    ITrnVideoSwitcher __RPC_FAR * This,
    DWORD animId,
    WORD frameIndex,
    /* [in] */ STrnRect __RPC_FAR *pSourceRect,
    /* [out] */ SPlayBitMap __RPC_FAR *pBitMap,
    /* [in] */ STrnRect __RPC_FAR *pDestRect);


void __RPC_STUB ITrnVideoSwitcher_GrabAnimFrame_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE ITrnVideoSwitcher_UpdateAnimFrame_Proxy( 
    ITrnVideoSwitcher __RPC_FAR * This,
    DWORD animId,
    WORD frameIndex,
    /* [in] */ STrnRect __RPC_FAR *pDestRect,
    /* [in] */ SPlayBitMap __RPC_FAR *pBitMap,
    /* [in] */ STrnRect __RPC_FAR *pSourceRect);


void __RPC_STUB ITrnVideoSwitcher_UpdateAnimFrame_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE ITrnVideoSwitcher_EnterPassiveState_Proxy( 
    ITrnVideoSwitcher __RPC_FAR * This,
    /* [in] */ const STrnTimeType __RPC_FAR *pTime);


void __RPC_STUB ITrnVideoSwitcher_EnterPassiveState_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __ITrnVideoSwitcher_INTERFACE_DEFINED__ */


#ifndef __ITrnKeyPriorityCompositor_INTERFACE_DEFINED__
#define __ITrnKeyPriorityCompositor_INTERFACE_DEFINED__

/****************************************
 * Generated header for interface: ITrnKeyPriorityCompositor
 * at Tue Nov 23 05:28:37 1999
 * using MIDL 3.01.75
 ****************************************/
/* [unique][uuid][object][local] */ 


typedef struct  tagSTrnSWKPTable
    {
    unsigned char Index;
    unsigned char L1_Enables;
    unsigned char L2_Enables;
    unsigned char DefaultKP;
    unsigned char KP[ 8 ];
    unsigned char BusControl[ 5 ];
    unsigned char Filler[ 3 ];
    }	STrnSWKPTable;


EXTERN_C const IID IID_ITrnKeyPriorityCompositor;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    interface DECLSPEC_UUID("8335e3f3-ab3b-11ce-8468-0000b468276b")
    ITrnKeyPriorityCompositor : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE SetKeyPriorityTable( 
            WORD KPIndex,
            /* [in] */ STrnSWKPTable __RPC_FAR *pTable) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE ActivateKeyPriorityTable( 
            /* [in] */ STrnTimeType __RPC_FAR *pTime,
            WORD KPIndex) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE QueryKeyPriorityTable( 
            WORD KPIndex,
            /* [out] */ STrnSWKPTable __RPC_FAR *pTable) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct ITrnKeyPriorityCompositorVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            ITrnKeyPriorityCompositor __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            ITrnKeyPriorityCompositor __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            ITrnKeyPriorityCompositor __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetKeyPriorityTable )( 
            ITrnKeyPriorityCompositor __RPC_FAR * This,
            WORD KPIndex,
            /* [in] */ STrnSWKPTable __RPC_FAR *pTable);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *ActivateKeyPriorityTable )( 
            ITrnKeyPriorityCompositor __RPC_FAR * This,
            /* [in] */ STrnTimeType __RPC_FAR *pTime,
            WORD KPIndex);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryKeyPriorityTable )( 
            ITrnKeyPriorityCompositor __RPC_FAR * This,
            WORD KPIndex,
            /* [out] */ STrnSWKPTable __RPC_FAR *pTable);
        
        END_INTERFACE
    } ITrnKeyPriorityCompositorVtbl;

    interface ITrnKeyPriorityCompositor
    {
        CONST_VTBL struct ITrnKeyPriorityCompositorVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ITrnKeyPriorityCompositor_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define ITrnKeyPriorityCompositor_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define ITrnKeyPriorityCompositor_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define ITrnKeyPriorityCompositor_SetKeyPriorityTable(This,KPIndex,pTable)	\
    (This)->lpVtbl -> SetKeyPriorityTable(This,KPIndex,pTable)

#define ITrnKeyPriorityCompositor_ActivateKeyPriorityTable(This,pTime,KPIndex)	\
    (This)->lpVtbl -> ActivateKeyPriorityTable(This,pTime,KPIndex)

#define ITrnKeyPriorityCompositor_QueryKeyPriorityTable(This,KPIndex,pTable)	\
    (This)->lpVtbl -> QueryKeyPriorityTable(This,KPIndex,pTable)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE ITrnKeyPriorityCompositor_SetKeyPriorityTable_Proxy( 
    ITrnKeyPriorityCompositor __RPC_FAR * This,
    WORD KPIndex,
    /* [in] */ STrnSWKPTable __RPC_FAR *pTable);


void __RPC_STUB ITrnKeyPriorityCompositor_SetKeyPriorityTable_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE ITrnKeyPriorityCompositor_ActivateKeyPriorityTable_Proxy( 
    ITrnKeyPriorityCompositor __RPC_FAR * This,
    /* [in] */ STrnTimeType __RPC_FAR *pTime,
    WORD KPIndex);


void __RPC_STUB ITrnKeyPriorityCompositor_ActivateKeyPriorityTable_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE ITrnKeyPriorityCompositor_QueryKeyPriorityTable_Proxy( 
    ITrnKeyPriorityCompositor __RPC_FAR * This,
    WORD KPIndex,
    /* [out] */ STrnSWKPTable __RPC_FAR *pTable);


void __RPC_STUB ITrnKeyPriorityCompositor_QueryKeyPriorityTable_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __ITrnKeyPriorityCompositor_INTERFACE_DEFINED__ */


#ifndef __ITrnChromaKeyer_INTERFACE_DEFINED__
#define __ITrnChromaKeyer_INTERFACE_DEFINED__

/****************************************
 * Generated header for interface: ITrnChromaKeyer
 * at Tue Nov 23 05:28:37 1999
 * using MIDL 3.01.75
 ****************************************/
/* [unique][uuid][object][local] */ 


typedef 
enum tagETrnChromaKeyMode
    {	CKMLuma	= 0,
	CKMLumaAB	= 1,
	CKMChroma	= 2,
	CKMChromaLuma	= 3
    }	ETrnChromaKeyMode;

typedef 
enum tagETrnChromaKeyMethod
    {	CKTmix	= 1,
	CKTaddmix	= 2,
	CKTaddadd	= 3
    }	ETrnChromaKeyMethod;


EXTERN_C const IID IID_ITrnChromaKeyer;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    interface DECLSPEC_UUID("8335e3f4-ab3b-11ce-8468-0000b468276b")
    ITrnChromaKeyer : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE LoadChromaKeyLUT( 
            WORD LUTIndex,
            DWORD LUTSize,
            /* [size_is][in] */ BYTE __RPC_FAR *pLUTData) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE ActivateChromaKey( 
            /* [in] */ STrnTimeType __RPC_FAR *pTime,
            /* [in] */ ETrnChromaKeyMode keyerMode,
            /* [in] */ ETrnChromaKeyMethod keyMethod,
            /* [in] */ DWORD LUTIndex,
            /* [in] */ DWORD keyColor) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct ITrnChromaKeyerVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            ITrnChromaKeyer __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            ITrnChromaKeyer __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            ITrnChromaKeyer __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *LoadChromaKeyLUT )( 
            ITrnChromaKeyer __RPC_FAR * This,
            WORD LUTIndex,
            DWORD LUTSize,
            /* [size_is][in] */ BYTE __RPC_FAR *pLUTData);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *ActivateChromaKey )( 
            ITrnChromaKeyer __RPC_FAR * This,
            /* [in] */ STrnTimeType __RPC_FAR *pTime,
            /* [in] */ ETrnChromaKeyMode keyerMode,
            /* [in] */ ETrnChromaKeyMethod keyMethod,
            /* [in] */ DWORD LUTIndex,
            /* [in] */ DWORD keyColor);
        
        END_INTERFACE
    } ITrnChromaKeyerVtbl;

    interface ITrnChromaKeyer
    {
        CONST_VTBL struct ITrnChromaKeyerVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ITrnChromaKeyer_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define ITrnChromaKeyer_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define ITrnChromaKeyer_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define ITrnChromaKeyer_LoadChromaKeyLUT(This,LUTIndex,LUTSize,pLUTData)	\
    (This)->lpVtbl -> LoadChromaKeyLUT(This,LUTIndex,LUTSize,pLUTData)

#define ITrnChromaKeyer_ActivateChromaKey(This,pTime,keyerMode,keyMethod,LUTIndex,keyColor)	\
    (This)->lpVtbl -> ActivateChromaKey(This,pTime,keyerMode,keyMethod,LUTIndex,keyColor)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE ITrnChromaKeyer_LoadChromaKeyLUT_Proxy( 
    ITrnChromaKeyer __RPC_FAR * This,
    WORD LUTIndex,
    DWORD LUTSize,
    /* [size_is][in] */ BYTE __RPC_FAR *pLUTData);


void __RPC_STUB ITrnChromaKeyer_LoadChromaKeyLUT_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE ITrnChromaKeyer_ActivateChromaKey_Proxy( 
    ITrnChromaKeyer __RPC_FAR * This,
    /* [in] */ STrnTimeType __RPC_FAR *pTime,
    /* [in] */ ETrnChromaKeyMode keyerMode,
    /* [in] */ ETrnChromaKeyMethod keyMethod,
    /* [in] */ DWORD LUTIndex,
    /* [in] */ DWORD keyColor);


void __RPC_STUB ITrnChromaKeyer_ActivateChromaKey_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __ITrnChromaKeyer_INTERFACE_DEFINED__ */


#ifndef __ITrnRecursiveEffectsGenerator_INTERFACE_DEFINED__
#define __ITrnRecursiveEffectsGenerator_INTERFACE_DEFINED__

/****************************************
 * Generated header for interface: ITrnRecursiveEffectsGenerator
 * at Tue Nov 23 05:28:37 1999
 * using MIDL 3.01.75
 ****************************************/
/* [unique][uuid][object][local] */ 



EXTERN_C const IID IID_ITrnRecursiveEffectsGenerator;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    interface DECLSPEC_UUID("8335e3f5-ab3b-11ce-8468-0000b468276b")
    ITrnRecursiveEffectsGenerator : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE SetRecursiveMode( 
            /* [in] */ STrnTimeType __RPC_FAR *pTime,
            WORD RecursiveMode) = 0;
        
        virtual WORD STDMETHODCALLTYPE QueryRecursiveMode( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE QueryRecursiveOffsetRange( 
            /* [out] */ STrnRectGrid __RPC_FAR *pOffsetRange) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetRecursiveOffset( 
            /* [in] */ STrnTimeType __RPC_FAR *pTime,
            SHORT x,
            SHORT y) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE QueryRecursiveOffset( 
            /* [out] */ SHORT __RPC_FAR *px,
            /* [out] */ SHORT __RPC_FAR *py) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetRecursiveEnable( 
            /* [in] */ STrnTimeType __RPC_FAR *pTime,
            /* [in] */ STrnPlayList __RPC_FAR *pList) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct ITrnRecursiveEffectsGeneratorVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            ITrnRecursiveEffectsGenerator __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            ITrnRecursiveEffectsGenerator __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            ITrnRecursiveEffectsGenerator __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetRecursiveMode )( 
            ITrnRecursiveEffectsGenerator __RPC_FAR * This,
            /* [in] */ STrnTimeType __RPC_FAR *pTime,
            WORD RecursiveMode);
        
        WORD ( STDMETHODCALLTYPE __RPC_FAR *QueryRecursiveMode )( 
            ITrnRecursiveEffectsGenerator __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryRecursiveOffsetRange )( 
            ITrnRecursiveEffectsGenerator __RPC_FAR * This,
            /* [out] */ STrnRectGrid __RPC_FAR *pOffsetRange);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetRecursiveOffset )( 
            ITrnRecursiveEffectsGenerator __RPC_FAR * This,
            /* [in] */ STrnTimeType __RPC_FAR *pTime,
            SHORT x,
            SHORT y);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryRecursiveOffset )( 
            ITrnRecursiveEffectsGenerator __RPC_FAR * This,
            /* [out] */ SHORT __RPC_FAR *px,
            /* [out] */ SHORT __RPC_FAR *py);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetRecursiveEnable )( 
            ITrnRecursiveEffectsGenerator __RPC_FAR * This,
            /* [in] */ STrnTimeType __RPC_FAR *pTime,
            /* [in] */ STrnPlayList __RPC_FAR *pList);
        
        END_INTERFACE
    } ITrnRecursiveEffectsGeneratorVtbl;

    interface ITrnRecursiveEffectsGenerator
    {
        CONST_VTBL struct ITrnRecursiveEffectsGeneratorVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ITrnRecursiveEffectsGenerator_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define ITrnRecursiveEffectsGenerator_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define ITrnRecursiveEffectsGenerator_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define ITrnRecursiveEffectsGenerator_SetRecursiveMode(This,pTime,RecursiveMode)	\
    (This)->lpVtbl -> SetRecursiveMode(This,pTime,RecursiveMode)

#define ITrnRecursiveEffectsGenerator_QueryRecursiveMode(This)	\
    (This)->lpVtbl -> QueryRecursiveMode(This)

#define ITrnRecursiveEffectsGenerator_QueryRecursiveOffsetRange(This,pOffsetRange)	\
    (This)->lpVtbl -> QueryRecursiveOffsetRange(This,pOffsetRange)

#define ITrnRecursiveEffectsGenerator_SetRecursiveOffset(This,pTime,x,y)	\
    (This)->lpVtbl -> SetRecursiveOffset(This,pTime,x,y)

#define ITrnRecursiveEffectsGenerator_QueryRecursiveOffset(This,px,py)	\
    (This)->lpVtbl -> QueryRecursiveOffset(This,px,py)

#define ITrnRecursiveEffectsGenerator_SetRecursiveEnable(This,pTime,pList)	\
    (This)->lpVtbl -> SetRecursiveEnable(This,pTime,pList)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE ITrnRecursiveEffectsGenerator_SetRecursiveMode_Proxy( 
    ITrnRecursiveEffectsGenerator __RPC_FAR * This,
    /* [in] */ STrnTimeType __RPC_FAR *pTime,
    WORD RecursiveMode);


void __RPC_STUB ITrnRecursiveEffectsGenerator_SetRecursiveMode_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


WORD STDMETHODCALLTYPE ITrnRecursiveEffectsGenerator_QueryRecursiveMode_Proxy( 
    ITrnRecursiveEffectsGenerator __RPC_FAR * This);


void __RPC_STUB ITrnRecursiveEffectsGenerator_QueryRecursiveMode_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE ITrnRecursiveEffectsGenerator_QueryRecursiveOffsetRange_Proxy( 
    ITrnRecursiveEffectsGenerator __RPC_FAR * This,
    /* [out] */ STrnRectGrid __RPC_FAR *pOffsetRange);


void __RPC_STUB ITrnRecursiveEffectsGenerator_QueryRecursiveOffsetRange_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE ITrnRecursiveEffectsGenerator_SetRecursiveOffset_Proxy( 
    ITrnRecursiveEffectsGenerator __RPC_FAR * This,
    /* [in] */ STrnTimeType __RPC_FAR *pTime,
    SHORT x,
    SHORT y);


void __RPC_STUB ITrnRecursiveEffectsGenerator_SetRecursiveOffset_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE ITrnRecursiveEffectsGenerator_QueryRecursiveOffset_Proxy( 
    ITrnRecursiveEffectsGenerator __RPC_FAR * This,
    /* [out] */ SHORT __RPC_FAR *px,
    /* [out] */ SHORT __RPC_FAR *py);


void __RPC_STUB ITrnRecursiveEffectsGenerator_QueryRecursiveOffset_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE ITrnRecursiveEffectsGenerator_SetRecursiveEnable_Proxy( 
    ITrnRecursiveEffectsGenerator __RPC_FAR * This,
    /* [in] */ STrnTimeType __RPC_FAR *pTime,
    /* [in] */ STrnPlayList __RPC_FAR *pList);


void __RPC_STUB ITrnRecursiveEffectsGenerator_SetRecursiveEnable_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __ITrnRecursiveEffectsGenerator_INTERFACE_DEFINED__ */


#ifndef __ITrnGraphicsBuffer_INTERFACE_DEFINED__
#define __ITrnGraphicsBuffer_INTERFACE_DEFINED__

/****************************************
 * Generated header for interface: ITrnGraphicsBuffer
 * at Tue Nov 23 05:28:37 1999
 * using MIDL 3.01.75
 ****************************************/
/* [unique][uuid][object][local] */ 


typedef 
enum tagETrnDisplayTypes
    {	DISPLAY_MAINALPHA	= 0x4080,
	DISPLAY_ALPHA	= 0x2040,
	DISPLAY_D1	= 0x8a30
    }	ETrnDisplayTypes;

typedef 
enum tagETrnViewPortParams
    {	VIEWPORT_DYTOP	= 0,
	VIEWPORT_DXLEFT	= 1,
	VIEWPORT_DYHEIGHT	= 2,
	VIEWPORT_DXWIDTH	= 3,
	VIEWPORT_RYOFFSET	= 4,
	VIEWPORT_RXOFFSET	= 5,
	VIEWPORT_NUMPARAMS	= 6
    }	ETrnViewPortParams;


EXTERN_C const IID IID_ITrnGraphicsBuffer;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    interface DECLSPEC_UUID("8335e5de-ab3b-11ce-8468-0000b468276b")
    ITrnGraphicsBuffer : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE CreateView( 
            DWORD viewMode,
            DWORD __RPC_FAR *pViewHandle) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE DeleteView( 
            DWORD viewHandle) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE CreateViewPort( 
            DWORD viewHandle,
            STrnRect __RPC_FAR *pRect,
            DWORD __RPC_FAR *pPortHandle) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE DeleteViewPort( 
            DWORD portHandle) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE CreateBitMap( 
            DWORD portHandle,
            unsigned int width,
            unsigned int height,
            DWORD __RPC_FAR *pBitMapHandle) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE DeleteBitMap( 
            DWORD BitMapHandle) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetViewPortLayering( 
            DWORD viewHandle,
            unsigned int nPorts,
            DWORD __RPC_FAR *pViewPorts) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetViewPortBitMap( 
            DWORD portHandle,
            DWORD BitMapHandle) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetViewPortClipRect( 
            DWORD portHandle,
            STrnRect __RPC_FAR *pRect) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE ShowViews( 
            STrnTimeType __RPC_FAR *pTime,
            unsigned int nViews,
            DWORD __RPC_FAR *pViewHandles) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetViewPortParameter( 
            DWORD portHandle,
            DWORD parameter,
            DWORD __RPC_FAR *pParameter) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE AnimateViewPortParameter( 
            STrnTimeType __RPC_FAR *pTime,
            STrnPlayList __RPC_FAR *pList,
            DWORD portHandle,
            DWORD parameter) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE UpdateBitMap( 
            DWORD bitmapHandle,
            STrnRect __RPC_FAR *pDestRect,
            BYTE __RPC_FAR *pSourceBitmap) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct ITrnGraphicsBufferVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            ITrnGraphicsBuffer __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            ITrnGraphicsBuffer __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            ITrnGraphicsBuffer __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *CreateView )( 
            ITrnGraphicsBuffer __RPC_FAR * This,
            DWORD viewMode,
            DWORD __RPC_FAR *pViewHandle);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *DeleteView )( 
            ITrnGraphicsBuffer __RPC_FAR * This,
            DWORD viewHandle);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *CreateViewPort )( 
            ITrnGraphicsBuffer __RPC_FAR * This,
            DWORD viewHandle,
            STrnRect __RPC_FAR *pRect,
            DWORD __RPC_FAR *pPortHandle);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *DeleteViewPort )( 
            ITrnGraphicsBuffer __RPC_FAR * This,
            DWORD portHandle);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *CreateBitMap )( 
            ITrnGraphicsBuffer __RPC_FAR * This,
            DWORD portHandle,
            unsigned int width,
            unsigned int height,
            DWORD __RPC_FAR *pBitMapHandle);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *DeleteBitMap )( 
            ITrnGraphicsBuffer __RPC_FAR * This,
            DWORD BitMapHandle);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetViewPortLayering )( 
            ITrnGraphicsBuffer __RPC_FAR * This,
            DWORD viewHandle,
            unsigned int nPorts,
            DWORD __RPC_FAR *pViewPorts);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetViewPortBitMap )( 
            ITrnGraphicsBuffer __RPC_FAR * This,
            DWORD portHandle,
            DWORD BitMapHandle);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetViewPortClipRect )( 
            ITrnGraphicsBuffer __RPC_FAR * This,
            DWORD portHandle,
            STrnRect __RPC_FAR *pRect);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *ShowViews )( 
            ITrnGraphicsBuffer __RPC_FAR * This,
            STrnTimeType __RPC_FAR *pTime,
            unsigned int nViews,
            DWORD __RPC_FAR *pViewHandles);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetViewPortParameter )( 
            ITrnGraphicsBuffer __RPC_FAR * This,
            DWORD portHandle,
            DWORD parameter,
            DWORD __RPC_FAR *pParameter);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *AnimateViewPortParameter )( 
            ITrnGraphicsBuffer __RPC_FAR * This,
            STrnTimeType __RPC_FAR *pTime,
            STrnPlayList __RPC_FAR *pList,
            DWORD portHandle,
            DWORD parameter);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *UpdateBitMap )( 
            ITrnGraphicsBuffer __RPC_FAR * This,
            DWORD bitmapHandle,
            STrnRect __RPC_FAR *pDestRect,
            BYTE __RPC_FAR *pSourceBitmap);
        
        END_INTERFACE
    } ITrnGraphicsBufferVtbl;

    interface ITrnGraphicsBuffer
    {
        CONST_VTBL struct ITrnGraphicsBufferVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ITrnGraphicsBuffer_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define ITrnGraphicsBuffer_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define ITrnGraphicsBuffer_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define ITrnGraphicsBuffer_CreateView(This,viewMode,pViewHandle)	\
    (This)->lpVtbl -> CreateView(This,viewMode,pViewHandle)

#define ITrnGraphicsBuffer_DeleteView(This,viewHandle)	\
    (This)->lpVtbl -> DeleteView(This,viewHandle)

#define ITrnGraphicsBuffer_CreateViewPort(This,viewHandle,pRect,pPortHandle)	\
    (This)->lpVtbl -> CreateViewPort(This,viewHandle,pRect,pPortHandle)

#define ITrnGraphicsBuffer_DeleteViewPort(This,portHandle)	\
    (This)->lpVtbl -> DeleteViewPort(This,portHandle)

#define ITrnGraphicsBuffer_CreateBitMap(This,portHandle,width,height,pBitMapHandle)	\
    (This)->lpVtbl -> CreateBitMap(This,portHandle,width,height,pBitMapHandle)

#define ITrnGraphicsBuffer_DeleteBitMap(This,BitMapHandle)	\
    (This)->lpVtbl -> DeleteBitMap(This,BitMapHandle)

#define ITrnGraphicsBuffer_SetViewPortLayering(This,viewHandle,nPorts,pViewPorts)	\
    (This)->lpVtbl -> SetViewPortLayering(This,viewHandle,nPorts,pViewPorts)

#define ITrnGraphicsBuffer_SetViewPortBitMap(This,portHandle,BitMapHandle)	\
    (This)->lpVtbl -> SetViewPortBitMap(This,portHandle,BitMapHandle)

#define ITrnGraphicsBuffer_SetViewPortClipRect(This,portHandle,pRect)	\
    (This)->lpVtbl -> SetViewPortClipRect(This,portHandle,pRect)

#define ITrnGraphicsBuffer_ShowViews(This,pTime,nViews,pViewHandles)	\
    (This)->lpVtbl -> ShowViews(This,pTime,nViews,pViewHandles)

#define ITrnGraphicsBuffer_GetViewPortParameter(This,portHandle,parameter,pParameter)	\
    (This)->lpVtbl -> GetViewPortParameter(This,portHandle,parameter,pParameter)

#define ITrnGraphicsBuffer_AnimateViewPortParameter(This,pTime,pList,portHandle,parameter)	\
    (This)->lpVtbl -> AnimateViewPortParameter(This,pTime,pList,portHandle,parameter)

#define ITrnGraphicsBuffer_UpdateBitMap(This,bitmapHandle,pDestRect,pSourceBitmap)	\
    (This)->lpVtbl -> UpdateBitMap(This,bitmapHandle,pDestRect,pSourceBitmap)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE ITrnGraphicsBuffer_CreateView_Proxy( 
    ITrnGraphicsBuffer __RPC_FAR * This,
    DWORD viewMode,
    DWORD __RPC_FAR *pViewHandle);


void __RPC_STUB ITrnGraphicsBuffer_CreateView_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE ITrnGraphicsBuffer_DeleteView_Proxy( 
    ITrnGraphicsBuffer __RPC_FAR * This,
    DWORD viewHandle);


void __RPC_STUB ITrnGraphicsBuffer_DeleteView_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE ITrnGraphicsBuffer_CreateViewPort_Proxy( 
    ITrnGraphicsBuffer __RPC_FAR * This,
    DWORD viewHandle,
    STrnRect __RPC_FAR *pRect,
    DWORD __RPC_FAR *pPortHandle);


void __RPC_STUB ITrnGraphicsBuffer_CreateViewPort_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE ITrnGraphicsBuffer_DeleteViewPort_Proxy( 
    ITrnGraphicsBuffer __RPC_FAR * This,
    DWORD portHandle);


void __RPC_STUB ITrnGraphicsBuffer_DeleteViewPort_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE ITrnGraphicsBuffer_CreateBitMap_Proxy( 
    ITrnGraphicsBuffer __RPC_FAR * This,
    DWORD portHandle,
    unsigned int width,
    unsigned int height,
    DWORD __RPC_FAR *pBitMapHandle);


void __RPC_STUB ITrnGraphicsBuffer_CreateBitMap_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE ITrnGraphicsBuffer_DeleteBitMap_Proxy( 
    ITrnGraphicsBuffer __RPC_FAR * This,
    DWORD BitMapHandle);


void __RPC_STUB ITrnGraphicsBuffer_DeleteBitMap_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE ITrnGraphicsBuffer_SetViewPortLayering_Proxy( 
    ITrnGraphicsBuffer __RPC_FAR * This,
    DWORD viewHandle,
    unsigned int nPorts,
    DWORD __RPC_FAR *pViewPorts);


void __RPC_STUB ITrnGraphicsBuffer_SetViewPortLayering_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE ITrnGraphicsBuffer_SetViewPortBitMap_Proxy( 
    ITrnGraphicsBuffer __RPC_FAR * This,
    DWORD portHandle,
    DWORD BitMapHandle);


void __RPC_STUB ITrnGraphicsBuffer_SetViewPortBitMap_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE ITrnGraphicsBuffer_SetViewPortClipRect_Proxy( 
    ITrnGraphicsBuffer __RPC_FAR * This,
    DWORD portHandle,
    STrnRect __RPC_FAR *pRect);


void __RPC_STUB ITrnGraphicsBuffer_SetViewPortClipRect_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE ITrnGraphicsBuffer_ShowViews_Proxy( 
    ITrnGraphicsBuffer __RPC_FAR * This,
    STrnTimeType __RPC_FAR *pTime,
    unsigned int nViews,
    DWORD __RPC_FAR *pViewHandles);


void __RPC_STUB ITrnGraphicsBuffer_ShowViews_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE ITrnGraphicsBuffer_GetViewPortParameter_Proxy( 
    ITrnGraphicsBuffer __RPC_FAR * This,
    DWORD portHandle,
    DWORD parameter,
    DWORD __RPC_FAR *pParameter);


void __RPC_STUB ITrnGraphicsBuffer_GetViewPortParameter_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE ITrnGraphicsBuffer_AnimateViewPortParameter_Proxy( 
    ITrnGraphicsBuffer __RPC_FAR * This,
    STrnTimeType __RPC_FAR *pTime,
    STrnPlayList __RPC_FAR *pList,
    DWORD portHandle,
    DWORD parameter);


void __RPC_STUB ITrnGraphicsBuffer_AnimateViewPortParameter_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE ITrnGraphicsBuffer_UpdateBitMap_Proxy( 
    ITrnGraphicsBuffer __RPC_FAR * This,
    DWORD bitmapHandle,
    STrnRect __RPC_FAR *pDestRect,
    BYTE __RPC_FAR *pSourceBitmap);


void __RPC_STUB ITrnGraphicsBuffer_UpdateBitMap_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __ITrnGraphicsBuffer_INTERFACE_DEFINED__ */


#ifndef __ITrnGraphicsEffect_INTERFACE_DEFINED__
#define __ITrnGraphicsEffect_INTERFACE_DEFINED__

/****************************************
 * Generated header for interface: ITrnGraphicsEffect
 * at Tue Nov 23 05:28:37 1999
 * using MIDL 3.01.75
 ****************************************/
/* [unique][uuid][object][local] */ 



EXTERN_C const IID IID_ITrnGraphicsEffect;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    interface DECLSPEC_UUID("8335e5e6-ab3b-11ce-8468-0000b468276b")
    ITrnGraphicsEffect : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE LoadFromStorage( 
            /* [in] */ IStorage __RPC_FAR *pStg) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SaveToStorage( 
            /* [in] */ IStorage __RPC_FAR *pStg) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE TransferToTrinity( 
            /* [in] */ ITrnGraphicsBuffer __RPC_FAR *pGrph,
            /* [in] */ STrnTimeType __RPC_FAR *pTime) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE ReturnViewHandles( 
            /* [in] */ DWORD numEntries,
            /* [out] */ DWORD __RPC_FAR *handleArray,
            /* [out] */ DWORD __RPC_FAR *numReturned) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE ReturnViewPortHandles( 
            /* [in] */ DWORD numEntries,
            /* [out] */ DWORD __RPC_FAR *handleArray,
            /* [out] */ DWORD __RPC_FAR *numReturned) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE ReturnBitmapHandles( 
            /* [in] */ DWORD numEntries,
            /* [out] */ DWORD __RPC_FAR *handleArray,
            /* [out] */ DWORD __RPC_FAR *numReturned) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetControllingPlayList( 
            /* [out] */ STrnPlayList __RPC_FAR *pL) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct ITrnGraphicsEffectVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            ITrnGraphicsEffect __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            ITrnGraphicsEffect __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            ITrnGraphicsEffect __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *LoadFromStorage )( 
            ITrnGraphicsEffect __RPC_FAR * This,
            /* [in] */ IStorage __RPC_FAR *pStg);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SaveToStorage )( 
            ITrnGraphicsEffect __RPC_FAR * This,
            /* [in] */ IStorage __RPC_FAR *pStg);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *TransferToTrinity )( 
            ITrnGraphicsEffect __RPC_FAR * This,
            /* [in] */ ITrnGraphicsBuffer __RPC_FAR *pGrph,
            /* [in] */ STrnTimeType __RPC_FAR *pTime);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *ReturnViewHandles )( 
            ITrnGraphicsEffect __RPC_FAR * This,
            /* [in] */ DWORD numEntries,
            /* [out] */ DWORD __RPC_FAR *handleArray,
            /* [out] */ DWORD __RPC_FAR *numReturned);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *ReturnViewPortHandles )( 
            ITrnGraphicsEffect __RPC_FAR * This,
            /* [in] */ DWORD numEntries,
            /* [out] */ DWORD __RPC_FAR *handleArray,
            /* [out] */ DWORD __RPC_FAR *numReturned);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *ReturnBitmapHandles )( 
            ITrnGraphicsEffect __RPC_FAR * This,
            /* [in] */ DWORD numEntries,
            /* [out] */ DWORD __RPC_FAR *handleArray,
            /* [out] */ DWORD __RPC_FAR *numReturned);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetControllingPlayList )( 
            ITrnGraphicsEffect __RPC_FAR * This,
            /* [out] */ STrnPlayList __RPC_FAR *pL);
        
        END_INTERFACE
    } ITrnGraphicsEffectVtbl;

    interface ITrnGraphicsEffect
    {
        CONST_VTBL struct ITrnGraphicsEffectVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ITrnGraphicsEffect_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define ITrnGraphicsEffect_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define ITrnGraphicsEffect_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define ITrnGraphicsEffect_LoadFromStorage(This,pStg)	\
    (This)->lpVtbl -> LoadFromStorage(This,pStg)

#define ITrnGraphicsEffect_SaveToStorage(This,pStg)	\
    (This)->lpVtbl -> SaveToStorage(This,pStg)

#define ITrnGraphicsEffect_TransferToTrinity(This,pGrph,pTime)	\
    (This)->lpVtbl -> TransferToTrinity(This,pGrph,pTime)

#define ITrnGraphicsEffect_ReturnViewHandles(This,numEntries,handleArray,numReturned)	\
    (This)->lpVtbl -> ReturnViewHandles(This,numEntries,handleArray,numReturned)

#define ITrnGraphicsEffect_ReturnViewPortHandles(This,numEntries,handleArray,numReturned)	\
    (This)->lpVtbl -> ReturnViewPortHandles(This,numEntries,handleArray,numReturned)

#define ITrnGraphicsEffect_ReturnBitmapHandles(This,numEntries,handleArray,numReturned)	\
    (This)->lpVtbl -> ReturnBitmapHandles(This,numEntries,handleArray,numReturned)

#define ITrnGraphicsEffect_GetControllingPlayList(This,pL)	\
    (This)->lpVtbl -> GetControllingPlayList(This,pL)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE ITrnGraphicsEffect_LoadFromStorage_Proxy( 
    ITrnGraphicsEffect __RPC_FAR * This,
    /* [in] */ IStorage __RPC_FAR *pStg);


void __RPC_STUB ITrnGraphicsEffect_LoadFromStorage_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE ITrnGraphicsEffect_SaveToStorage_Proxy( 
    ITrnGraphicsEffect __RPC_FAR * This,
    /* [in] */ IStorage __RPC_FAR *pStg);


void __RPC_STUB ITrnGraphicsEffect_SaveToStorage_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE ITrnGraphicsEffect_TransferToTrinity_Proxy( 
    ITrnGraphicsEffect __RPC_FAR * This,
    /* [in] */ ITrnGraphicsBuffer __RPC_FAR *pGrph,
    /* [in] */ STrnTimeType __RPC_FAR *pTime);


void __RPC_STUB ITrnGraphicsEffect_TransferToTrinity_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE ITrnGraphicsEffect_ReturnViewHandles_Proxy( 
    ITrnGraphicsEffect __RPC_FAR * This,
    /* [in] */ DWORD numEntries,
    /* [out] */ DWORD __RPC_FAR *handleArray,
    /* [out] */ DWORD __RPC_FAR *numReturned);


void __RPC_STUB ITrnGraphicsEffect_ReturnViewHandles_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE ITrnGraphicsEffect_ReturnViewPortHandles_Proxy( 
    ITrnGraphicsEffect __RPC_FAR * This,
    /* [in] */ DWORD numEntries,
    /* [out] */ DWORD __RPC_FAR *handleArray,
    /* [out] */ DWORD __RPC_FAR *numReturned);


void __RPC_STUB ITrnGraphicsEffect_ReturnViewPortHandles_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE ITrnGraphicsEffect_ReturnBitmapHandles_Proxy( 
    ITrnGraphicsEffect __RPC_FAR * This,
    /* [in] */ DWORD numEntries,
    /* [out] */ DWORD __RPC_FAR *handleArray,
    /* [out] */ DWORD __RPC_FAR *numReturned);


void __RPC_STUB ITrnGraphicsEffect_ReturnBitmapHandles_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE ITrnGraphicsEffect_GetControllingPlayList_Proxy( 
    ITrnGraphicsEffect __RPC_FAR * This,
    /* [out] */ STrnPlayList __RPC_FAR *pL);


void __RPC_STUB ITrnGraphicsEffect_GetControllingPlayList_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __ITrnGraphicsEffect_INTERFACE_DEFINED__ */


#ifndef __ITrnControlAdviseSink_INTERFACE_DEFINED__
#define __ITrnControlAdviseSink_INTERFACE_DEFINED__

/****************************************
 * Generated header for interface: ITrnControlAdviseSink
 * at Tue Nov 23 05:28:37 1999
 * using MIDL 3.01.75
 ****************************************/
/* [unique][uuid][object][local] */ 



EXTERN_C const IID IID_ITrnControlAdviseSink;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    interface DECLSPEC_UUID("8335e3d7-ab3b-11ce-8468-0000b468276b")
    ITrnControlAdviseSink : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE OnControlChanged( 
            WORD ControlId,
            SHORT ControlValue) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct ITrnControlAdviseSinkVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            ITrnControlAdviseSink __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            ITrnControlAdviseSink __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            ITrnControlAdviseSink __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *OnControlChanged )( 
            ITrnControlAdviseSink __RPC_FAR * This,
            WORD ControlId,
            SHORT ControlValue);
        
        END_INTERFACE
    } ITrnControlAdviseSinkVtbl;

    interface ITrnControlAdviseSink
    {
        CONST_VTBL struct ITrnControlAdviseSinkVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ITrnControlAdviseSink_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define ITrnControlAdviseSink_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define ITrnControlAdviseSink_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define ITrnControlAdviseSink_OnControlChanged(This,ControlId,ControlValue)	\
    (This)->lpVtbl -> OnControlChanged(This,ControlId,ControlValue)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE ITrnControlAdviseSink_OnControlChanged_Proxy( 
    ITrnControlAdviseSink __RPC_FAR * This,
    WORD ControlId,
    SHORT ControlValue);


void __RPC_STUB ITrnControlAdviseSink_OnControlChanged_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __ITrnControlAdviseSink_INTERFACE_DEFINED__ */


#ifndef __ITrnEnumControls_INTERFACE_DEFINED__
#define __ITrnEnumControls_INTERFACE_DEFINED__

/****************************************
 * Generated header for interface: ITrnEnumControls
 * at Tue Nov 23 05:28:37 1999
 * using MIDL 3.01.75
 ****************************************/
/* [unique][uuid][object][local] */ 


typedef 
enum tagETrnCPControlType
    {	CTMomentary	= 0,
	CTLatching	= CTMomentary + 1,
	CTPositionSensor	= CTLatching + 1,
	CTEncoder	= CTPositionSensor + 1,
	CTVelocitySensor	= CTEncoder + 1,
	CTLight	= CTVelocitySensor + 1,
	CTTextDisplay	= CTLight + 1,
	CTBitmapDisplay	= CTTextDisplay + 1
    }	ETrnCPControlType;

typedef struct  tagSTrnCPControlDescriptor
    {
    WORD ControlId;
    ETrnCPControlType Type;
    SHORT LowRange;
    SHORT HighRange;
    WORD NumColors;
    WORD NumLines;
    WORD NumColumns;
    DWORD Flags;
    }	STrnCPControlDescriptor;


EXTERN_C const IID IID_ITrnEnumControls;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    interface DECLSPEC_UUID("8335e3d9-ab3b-11ce-8468-0000b468276b")
    ITrnEnumControls : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE Next( 
            /* [in] */ DWORD celt,
            /* [in] */ STrnCPControlDescriptor __RPC_FAR *rgelt,
            /* [out] */ DWORD __RPC_FAR *pceltFetched) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Skip( 
            /* [in] */ DWORD celt) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Reset( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Clone( 
            /* [out] */ ITrnEnumControls __RPC_FAR *__RPC_FAR *ppenum) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct ITrnEnumControlsVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            ITrnEnumControls __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            ITrnEnumControls __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            ITrnEnumControls __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Next )( 
            ITrnEnumControls __RPC_FAR * This,
            /* [in] */ DWORD celt,
            /* [in] */ STrnCPControlDescriptor __RPC_FAR *rgelt,
            /* [out] */ DWORD __RPC_FAR *pceltFetched);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Skip )( 
            ITrnEnumControls __RPC_FAR * This,
            /* [in] */ DWORD celt);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Reset )( 
            ITrnEnumControls __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Clone )( 
            ITrnEnumControls __RPC_FAR * This,
            /* [out] */ ITrnEnumControls __RPC_FAR *__RPC_FAR *ppenum);
        
        END_INTERFACE
    } ITrnEnumControlsVtbl;

    interface ITrnEnumControls
    {
        CONST_VTBL struct ITrnEnumControlsVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ITrnEnumControls_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define ITrnEnumControls_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define ITrnEnumControls_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define ITrnEnumControls_Next(This,celt,rgelt,pceltFetched)	\
    (This)->lpVtbl -> Next(This,celt,rgelt,pceltFetched)

#define ITrnEnumControls_Skip(This,celt)	\
    (This)->lpVtbl -> Skip(This,celt)

#define ITrnEnumControls_Reset(This)	\
    (This)->lpVtbl -> Reset(This)

#define ITrnEnumControls_Clone(This,ppenum)	\
    (This)->lpVtbl -> Clone(This,ppenum)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE ITrnEnumControls_Next_Proxy( 
    ITrnEnumControls __RPC_FAR * This,
    /* [in] */ DWORD celt,
    /* [in] */ STrnCPControlDescriptor __RPC_FAR *rgelt,
    /* [out] */ DWORD __RPC_FAR *pceltFetched);


void __RPC_STUB ITrnEnumControls_Next_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE ITrnEnumControls_Skip_Proxy( 
    ITrnEnumControls __RPC_FAR * This,
    /* [in] */ DWORD celt);


void __RPC_STUB ITrnEnumControls_Skip_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE ITrnEnumControls_Reset_Proxy( 
    ITrnEnumControls __RPC_FAR * This);


void __RPC_STUB ITrnEnumControls_Reset_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE ITrnEnumControls_Clone_Proxy( 
    ITrnEnumControls __RPC_FAR * This,
    /* [out] */ ITrnEnumControls __RPC_FAR *__RPC_FAR *ppenum);


void __RPC_STUB ITrnEnumControls_Clone_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __ITrnEnumControls_INTERFACE_DEFINED__ */


#ifndef __ITrnExternalControlPanel_INTERFACE_DEFINED__
#define __ITrnExternalControlPanel_INTERFACE_DEFINED__

/****************************************
 * Generated header for interface: ITrnExternalControlPanel
 * at Tue Nov 23 05:28:37 1999
 * using MIDL 3.01.75
 ****************************************/
/* [unique][uuid][object][local] */ 



EXTERN_C const IID IID_ITrnExternalControlPanel;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    interface DECLSPEC_UUID("8335e3d8-ab3b-11ce-8468-0000b468276b")
    ITrnExternalControlPanel : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE EnumElements( 
            /* [out] */ ITrnEnumControls __RPC_FAR *__RPC_FAR *ppenum) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Advise( 
            /* [in] */ ITrnControlAdviseSink __RPC_FAR *AdvSink,
            /* [out] */ DWORD __RPC_FAR *pConnectionId) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE UnAdvise( 
            /* [in] */ DWORD ConnectionId) = 0;
        
        virtual BOOL STDMETHODCALLTYPE SetLightState( 
            /* [in] */ STrnTimeType __RPC_FAR *pTime,
            WORD LightID,
            WORD LightValue,
            WORD LightColor) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE QueryControlState( 
            WORD ControlId,
            /* [out] */ SHORT __RPC_FAR *pControlValue) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetTextDisplay( 
            /* [in] */ STrnTimeType __RPC_FAR *pTime,
            WORD DisplayId,
            /* [string][in] */ const unsigned char __RPC_FAR *pText) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct ITrnExternalControlPanelVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            ITrnExternalControlPanel __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            ITrnExternalControlPanel __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            ITrnExternalControlPanel __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *EnumElements )( 
            ITrnExternalControlPanel __RPC_FAR * This,
            /* [out] */ ITrnEnumControls __RPC_FAR *__RPC_FAR *ppenum);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Advise )( 
            ITrnExternalControlPanel __RPC_FAR * This,
            /* [in] */ ITrnControlAdviseSink __RPC_FAR *AdvSink,
            /* [out] */ DWORD __RPC_FAR *pConnectionId);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *UnAdvise )( 
            ITrnExternalControlPanel __RPC_FAR * This,
            /* [in] */ DWORD ConnectionId);
        
        BOOL ( STDMETHODCALLTYPE __RPC_FAR *SetLightState )( 
            ITrnExternalControlPanel __RPC_FAR * This,
            /* [in] */ STrnTimeType __RPC_FAR *pTime,
            WORD LightID,
            WORD LightValue,
            WORD LightColor);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryControlState )( 
            ITrnExternalControlPanel __RPC_FAR * This,
            WORD ControlId,
            /* [out] */ SHORT __RPC_FAR *pControlValue);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetTextDisplay )( 
            ITrnExternalControlPanel __RPC_FAR * This,
            /* [in] */ STrnTimeType __RPC_FAR *pTime,
            WORD DisplayId,
            /* [string][in] */ const unsigned char __RPC_FAR *pText);
        
        END_INTERFACE
    } ITrnExternalControlPanelVtbl;

    interface ITrnExternalControlPanel
    {
        CONST_VTBL struct ITrnExternalControlPanelVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ITrnExternalControlPanel_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define ITrnExternalControlPanel_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define ITrnExternalControlPanel_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define ITrnExternalControlPanel_EnumElements(This,ppenum)	\
    (This)->lpVtbl -> EnumElements(This,ppenum)

#define ITrnExternalControlPanel_Advise(This,AdvSink,pConnectionId)	\
    (This)->lpVtbl -> Advise(This,AdvSink,pConnectionId)

#define ITrnExternalControlPanel_UnAdvise(This,ConnectionId)	\
    (This)->lpVtbl -> UnAdvise(This,ConnectionId)

#define ITrnExternalControlPanel_SetLightState(This,pTime,LightID,LightValue,LightColor)	\
    (This)->lpVtbl -> SetLightState(This,pTime,LightID,LightValue,LightColor)

#define ITrnExternalControlPanel_QueryControlState(This,ControlId,pControlValue)	\
    (This)->lpVtbl -> QueryControlState(This,ControlId,pControlValue)

#define ITrnExternalControlPanel_SetTextDisplay(This,pTime,DisplayId,pText)	\
    (This)->lpVtbl -> SetTextDisplay(This,pTime,DisplayId,pText)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE ITrnExternalControlPanel_EnumElements_Proxy( 
    ITrnExternalControlPanel __RPC_FAR * This,
    /* [out] */ ITrnEnumControls __RPC_FAR *__RPC_FAR *ppenum);


void __RPC_STUB ITrnExternalControlPanel_EnumElements_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE ITrnExternalControlPanel_Advise_Proxy( 
    ITrnExternalControlPanel __RPC_FAR * This,
    /* [in] */ ITrnControlAdviseSink __RPC_FAR *AdvSink,
    /* [out] */ DWORD __RPC_FAR *pConnectionId);


void __RPC_STUB ITrnExternalControlPanel_Advise_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE ITrnExternalControlPanel_UnAdvise_Proxy( 
    ITrnExternalControlPanel __RPC_FAR * This,
    /* [in] */ DWORD ConnectionId);


void __RPC_STUB ITrnExternalControlPanel_UnAdvise_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


BOOL STDMETHODCALLTYPE ITrnExternalControlPanel_SetLightState_Proxy( 
    ITrnExternalControlPanel __RPC_FAR * This,
    /* [in] */ STrnTimeType __RPC_FAR *pTime,
    WORD LightID,
    WORD LightValue,
    WORD LightColor);


void __RPC_STUB ITrnExternalControlPanel_SetLightState_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE ITrnExternalControlPanel_QueryControlState_Proxy( 
    ITrnExternalControlPanel __RPC_FAR * This,
    WORD ControlId,
    /* [out] */ SHORT __RPC_FAR *pControlValue);


void __RPC_STUB ITrnExternalControlPanel_QueryControlState_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE ITrnExternalControlPanel_SetTextDisplay_Proxy( 
    ITrnExternalControlPanel __RPC_FAR * This,
    /* [in] */ STrnTimeType __RPC_FAR *pTime,
    WORD DisplayId,
    /* [string][in] */ const unsigned char __RPC_FAR *pText);


void __RPC_STUB ITrnExternalControlPanel_SetTextDisplay_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __ITrnExternalControlPanel_INTERFACE_DEFINED__ */


#ifndef __ITrnSerialAdviseSink_INTERFACE_DEFINED__
#define __ITrnSerialAdviseSink_INTERFACE_DEFINED__

/****************************************
 * Generated header for interface: ITrnSerialAdviseSink
 * at Tue Nov 23 05:28:37 1999
 * using MIDL 3.01.75
 ****************************************/
/* [unique][uuid][object][local] */ 



EXTERN_C const IID IID_ITrnSerialAdviseSink;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    interface DECLSPEC_UUID("8335e3db-ab3b-11ce-8468-0000b468276b")
    ITrnSerialAdviseSink : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE OnReceivedMsg( 
            DWORD commandId,
            WORD dataLen,
            /* [size_is][in] */ unsigned char __RPC_FAR *pData) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct ITrnSerialAdviseSinkVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            ITrnSerialAdviseSink __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            ITrnSerialAdviseSink __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            ITrnSerialAdviseSink __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *OnReceivedMsg )( 
            ITrnSerialAdviseSink __RPC_FAR * This,
            DWORD commandId,
            WORD dataLen,
            /* [size_is][in] */ unsigned char __RPC_FAR *pData);
        
        END_INTERFACE
    } ITrnSerialAdviseSinkVtbl;

    interface ITrnSerialAdviseSink
    {
        CONST_VTBL struct ITrnSerialAdviseSinkVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ITrnSerialAdviseSink_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define ITrnSerialAdviseSink_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define ITrnSerialAdviseSink_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define ITrnSerialAdviseSink_OnReceivedMsg(This,commandId,dataLen,pData)	\
    (This)->lpVtbl -> OnReceivedMsg(This,commandId,dataLen,pData)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE ITrnSerialAdviseSink_OnReceivedMsg_Proxy( 
    ITrnSerialAdviseSink __RPC_FAR * This,
    DWORD commandId,
    WORD dataLen,
    /* [size_is][in] */ unsigned char __RPC_FAR *pData);


void __RPC_STUB ITrnSerialAdviseSink_OnReceivedMsg_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __ITrnSerialAdviseSink_INTERFACE_DEFINED__ */


#ifndef __ITrnSerialPort_INTERFACE_DEFINED__
#define __ITrnSerialPort_INTERFACE_DEFINED__

/****************************************
 * Generated header for interface: ITrnSerialPort
 * at Tue Nov 23 05:28:37 1999
 * using MIDL 3.01.75
 ****************************************/
/* [unique][uuid][object][local] */ 


typedef 
enum tagETrnSerialFlags
    {	SFpooled	= 1,
	SFoddField	= 2
    }	ETrnSerialFlags;

typedef struct  tagSTrnSPTimeType
    {
    STrnTimeType StartTime;
    DWORD Flags;
    DWORD Frequency;
    }	STrnSPTimeType;

typedef 
enum tagETrnSPParityMode
    {	SPPNone	= 0,
	SPPOdd	= SPPNone + 1,
	SPPEven	= SPPOdd + 1,
	SPPMark	= SPPEven + 1,
	SPPSpace	= SPPMark + 1
    }	ETrnSPParityMode;

typedef 
enum tagETrnStopBits
    {	SBOneStopBit	= 0,
	SBOnePtFiveStopBit	= SBOneStopBit + 1,
	SBTwoStopBit	= SBOnePtFiveStopBit + 1,
	SBNineSixteenthsStopBit	= SBTwoStopBit + 1
    }	ETrnStopBits;

typedef struct  tagSTrnSPConfiguration
    {
    DWORD baudRate;
    DWORD parity;
    DWORD bitsPerChar;
    DWORD stopBits;
    }	STrnSPConfiguration;


EXTERN_C const IID IID_ITrnSerialPort;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    interface DECLSPEC_UUID("8335e3da-ab3b-11ce-8468-0000b468276b")
    ITrnSerialPort : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE OpenPort( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE ClosePort( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Advise( 
            /* [in] */ ITrnSerialAdviseSink __RPC_FAR *pAdvSink,
            /* [out] */ DWORD __RPC_FAR *pConnectionId) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE UnAdvise( 
            /* [in] */ DWORD connectionId) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE QueryPortParameters( 
            /* [out] */ STrnSPConfiguration __RPC_FAR *pConfig) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetPortParameters( 
            /* [in] */ STrnSPConfiguration __RPC_FAR *pConfig) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SendMsg( 
            /* [in] */ DWORD msgLength,
            /* [in] */ unsigned char __RPC_FAR *pMessage,
            /* [in] */ STrnSPTimeType __RPC_FAR *pSendTime,
            /* [out] */ DWORD __RPC_FAR *pCommandId) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE CancelMsg( 
            DWORD id) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE FlushAllMsgs( void) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct ITrnSerialPortVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            ITrnSerialPort __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            ITrnSerialPort __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            ITrnSerialPort __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *OpenPort )( 
            ITrnSerialPort __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *ClosePort )( 
            ITrnSerialPort __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Advise )( 
            ITrnSerialPort __RPC_FAR * This,
            /* [in] */ ITrnSerialAdviseSink __RPC_FAR *pAdvSink,
            /* [out] */ DWORD __RPC_FAR *pConnectionId);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *UnAdvise )( 
            ITrnSerialPort __RPC_FAR * This,
            /* [in] */ DWORD connectionId);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryPortParameters )( 
            ITrnSerialPort __RPC_FAR * This,
            /* [out] */ STrnSPConfiguration __RPC_FAR *pConfig);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetPortParameters )( 
            ITrnSerialPort __RPC_FAR * This,
            /* [in] */ STrnSPConfiguration __RPC_FAR *pConfig);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SendMsg )( 
            ITrnSerialPort __RPC_FAR * This,
            /* [in] */ DWORD msgLength,
            /* [in] */ unsigned char __RPC_FAR *pMessage,
            /* [in] */ STrnSPTimeType __RPC_FAR *pSendTime,
            /* [out] */ DWORD __RPC_FAR *pCommandId);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *CancelMsg )( 
            ITrnSerialPort __RPC_FAR * This,
            DWORD id);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *FlushAllMsgs )( 
            ITrnSerialPort __RPC_FAR * This);
        
        END_INTERFACE
    } ITrnSerialPortVtbl;

    interface ITrnSerialPort
    {
        CONST_VTBL struct ITrnSerialPortVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ITrnSerialPort_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define ITrnSerialPort_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define ITrnSerialPort_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define ITrnSerialPort_OpenPort(This)	\
    (This)->lpVtbl -> OpenPort(This)

#define ITrnSerialPort_ClosePort(This)	\
    (This)->lpVtbl -> ClosePort(This)

#define ITrnSerialPort_Advise(This,pAdvSink,pConnectionId)	\
    (This)->lpVtbl -> Advise(This,pAdvSink,pConnectionId)

#define ITrnSerialPort_UnAdvise(This,connectionId)	\
    (This)->lpVtbl -> UnAdvise(This,connectionId)

#define ITrnSerialPort_QueryPortParameters(This,pConfig)	\
    (This)->lpVtbl -> QueryPortParameters(This,pConfig)

#define ITrnSerialPort_SetPortParameters(This,pConfig)	\
    (This)->lpVtbl -> SetPortParameters(This,pConfig)

#define ITrnSerialPort_SendMsg(This,msgLength,pMessage,pSendTime,pCommandId)	\
    (This)->lpVtbl -> SendMsg(This,msgLength,pMessage,pSendTime,pCommandId)

#define ITrnSerialPort_CancelMsg(This,id)	\
    (This)->lpVtbl -> CancelMsg(This,id)

#define ITrnSerialPort_FlushAllMsgs(This)	\
    (This)->lpVtbl -> FlushAllMsgs(This)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE ITrnSerialPort_OpenPort_Proxy( 
    ITrnSerialPort __RPC_FAR * This);


void __RPC_STUB ITrnSerialPort_OpenPort_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE ITrnSerialPort_ClosePort_Proxy( 
    ITrnSerialPort __RPC_FAR * This);


void __RPC_STUB ITrnSerialPort_ClosePort_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE ITrnSerialPort_Advise_Proxy( 
    ITrnSerialPort __RPC_FAR * This,
    /* [in] */ ITrnSerialAdviseSink __RPC_FAR *pAdvSink,
    /* [out] */ DWORD __RPC_FAR *pConnectionId);


void __RPC_STUB ITrnSerialPort_Advise_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE ITrnSerialPort_UnAdvise_Proxy( 
    ITrnSerialPort __RPC_FAR * This,
    /* [in] */ DWORD connectionId);


void __RPC_STUB ITrnSerialPort_UnAdvise_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE ITrnSerialPort_QueryPortParameters_Proxy( 
    ITrnSerialPort __RPC_FAR * This,
    /* [out] */ STrnSPConfiguration __RPC_FAR *pConfig);


void __RPC_STUB ITrnSerialPort_QueryPortParameters_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE ITrnSerialPort_SetPortParameters_Proxy( 
    ITrnSerialPort __RPC_FAR * This,
    /* [in] */ STrnSPConfiguration __RPC_FAR *pConfig);


void __RPC_STUB ITrnSerialPort_SetPortParameters_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE ITrnSerialPort_SendMsg_Proxy( 
    ITrnSerialPort __RPC_FAR * This,
    /* [in] */ DWORD msgLength,
    /* [in] */ unsigned char __RPC_FAR *pMessage,
    /* [in] */ STrnSPTimeType __RPC_FAR *pSendTime,
    /* [out] */ DWORD __RPC_FAR *pCommandId);


void __RPC_STUB ITrnSerialPort_SendMsg_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE ITrnSerialPort_CancelMsg_Proxy( 
    ITrnSerialPort __RPC_FAR * This,
    DWORD id);


void __RPC_STUB ITrnSerialPort_CancelMsg_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE ITrnSerialPort_FlushAllMsgs_Proxy( 
    ITrnSerialPort __RPC_FAR * This);


void __RPC_STUB ITrnSerialPort_FlushAllMsgs_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __ITrnSerialPort_INTERFACE_DEFINED__ */


#ifndef __ITrnTimeCodeReader_INTERFACE_DEFINED__
#define __ITrnTimeCodeReader_INTERFACE_DEFINED__

/****************************************
 * Generated header for interface: ITrnTimeCodeReader
 * at Tue Nov 23 05:28:37 1999
 * using MIDL 3.01.75
 ****************************************/
/* [unique][uuid][object][local] */ 



EXTERN_C const IID IID_ITrnTimeCodeReader;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    interface DECLSPEC_UUID("8335e3ef-ab3b-11ce-8468-0000b468276b")
    ITrnTimeCodeReader : public IUnknown
    {
    public:
    };
    
#else 	/* C style interface */

    typedef struct ITrnTimeCodeReaderVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            ITrnTimeCodeReader __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            ITrnTimeCodeReader __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            ITrnTimeCodeReader __RPC_FAR * This);
        
        END_INTERFACE
    } ITrnTimeCodeReaderVtbl;

    interface ITrnTimeCodeReader
    {
        CONST_VTBL struct ITrnTimeCodeReaderVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ITrnTimeCodeReader_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define ITrnTimeCodeReader_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define ITrnTimeCodeReader_Release(This)	\
    (This)->lpVtbl -> Release(This)


#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __ITrnTimeCodeReader_INTERFACE_DEFINED__ */


#ifndef __ITrnTimeCodeGenerator_INTERFACE_DEFINED__
#define __ITrnTimeCodeGenerator_INTERFACE_DEFINED__

/****************************************
 * Generated header for interface: ITrnTimeCodeGenerator
 * at Tue Nov 23 05:28:37 1999
 * using MIDL 3.01.75
 ****************************************/
/* [unique][uuid][object][local] */ 



EXTERN_C const IID IID_ITrnTimeCodeGenerator;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    interface DECLSPEC_UUID("8335e3f0-ab3b-11ce-8468-0000b468276b")
    ITrnTimeCodeGenerator : public IUnknown
    {
    public:
    };
    
#else 	/* C style interface */

    typedef struct ITrnTimeCodeGeneratorVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            ITrnTimeCodeGenerator __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            ITrnTimeCodeGenerator __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            ITrnTimeCodeGenerator __RPC_FAR * This);
        
        END_INTERFACE
    } ITrnTimeCodeGeneratorVtbl;

    interface ITrnTimeCodeGenerator
    {
        CONST_VTBL struct ITrnTimeCodeGeneratorVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ITrnTimeCodeGenerator_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define ITrnTimeCodeGenerator_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define ITrnTimeCodeGenerator_Release(This)	\
    (This)->lpVtbl -> Release(This)


#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __ITrnTimeCodeGenerator_INTERFACE_DEFINED__ */


#ifndef __ITrnTimeCodeAdviseSink_INTERFACE_DEFINED__
#define __ITrnTimeCodeAdviseSink_INTERFACE_DEFINED__

/****************************************
 * Generated header for interface: ITrnTimeCodeAdviseSink
 * at Tue Nov 23 05:28:37 1999
 * using MIDL 3.01.75
 ****************************************/
/* [unique][uuid][object][local] */ 



EXTERN_C const IID IID_ITrnTimeCodeAdviseSink;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    interface DECLSPEC_UUID("8335e3f1-ab3b-11ce-8468-0000b468276b")
    ITrnTimeCodeAdviseSink : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE OnTimeCodeData( 
            DWORD dwCookie,
            ULONG timeCode) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct ITrnTimeCodeAdviseSinkVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            ITrnTimeCodeAdviseSink __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            ITrnTimeCodeAdviseSink __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            ITrnTimeCodeAdviseSink __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *OnTimeCodeData )( 
            ITrnTimeCodeAdviseSink __RPC_FAR * This,
            DWORD dwCookie,
            ULONG timeCode);
        
        END_INTERFACE
    } ITrnTimeCodeAdviseSinkVtbl;

    interface ITrnTimeCodeAdviseSink
    {
        CONST_VTBL struct ITrnTimeCodeAdviseSinkVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ITrnTimeCodeAdviseSink_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define ITrnTimeCodeAdviseSink_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define ITrnTimeCodeAdviseSink_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define ITrnTimeCodeAdviseSink_OnTimeCodeData(This,dwCookie,timeCode)	\
    (This)->lpVtbl -> OnTimeCodeData(This,dwCookie,timeCode)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE ITrnTimeCodeAdviseSink_OnTimeCodeData_Proxy( 
    ITrnTimeCodeAdviseSink __RPC_FAR * This,
    DWORD dwCookie,
    ULONG timeCode);


void __RPC_STUB ITrnTimeCodeAdviseSink_OnTimeCodeData_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __ITrnTimeCodeAdviseSink_INTERFACE_DEFINED__ */


#ifndef __ITrnGPIInputOutput_INTERFACE_DEFINED__
#define __ITrnGPIInputOutput_INTERFACE_DEFINED__

/****************************************
 * Generated header for interface: ITrnGPIInputOutput
 * at Tue Nov 23 05:28:37 1999
 * using MIDL 3.01.75
 ****************************************/
/* [unique][uuid][object][local] */ 


typedef 
enum tagETrnOutputAction
    {	OASetInactive	= 0,
	OASetActive	= OASetInactive + 1,
	OAPulseInactive	= OASetActive + 1,
	OAPulseActive	= OAPulseInactive + 1
    }	ETrnOutputAction;


EXTERN_C const IID IID_ITrnGPIInputOutput;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    interface DECLSPEC_UUID("8335e5d2-ab3b-11ce-8468-0000b468276b")
    ITrnGPIInputOutput : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE QueryNumPins( 
            DWORD __RPC_FAR *pdwNumPins) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE QueryPinState( 
            DWORD __RPC_FAR *pdwPinStateMask) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetConfiguration( 
            DWORD dwOutputPinMask,
            DWORD dwInvertedPinMask) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE QueryConfiguration( 
            DWORD __RPC_FAR *pdwOutputPinMask,
            DWORD __RPC_FAR *pdwInvertedPinMask) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetGPIPreRoll( 
            DWORD dwPinIndex,
            unsigned int preRollInFields) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE QueryGPIPreRoll( 
            DWORD dwPinIndex,
            unsigned int __RPC_FAR *puPreRoll) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetOutput( 
            STrnTimeType __RPC_FAR *pTime,
            ETrnOutputAction action,
            DWORD dwPinIndex,
            unsigned int duration) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE FireEventOnGPI( 
            DWORD dwInputPinIndex,
            DWORD dwEventNumber) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE TriggerTrackOnGPI( 
            DWORD dwInputPinIndex,
            DWORD dwTrackNumber) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetInputCallback( 
            /* [in] */ DWORD dwPinIndex,
            /* [in] */ ITrnEventAdviseSink __RPC_FAR *pAdvise,
            /* [in] */ DWORD dwClientInfo,
            /* [out] */ DWORD __RPC_FAR *pdwEventId) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE CancelCallback( 
            /* [in] */ ITrnEventAdviseSink __RPC_FAR *pAdvise) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct ITrnGPIInputOutputVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            ITrnGPIInputOutput __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            ITrnGPIInputOutput __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            ITrnGPIInputOutput __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryNumPins )( 
            ITrnGPIInputOutput __RPC_FAR * This,
            DWORD __RPC_FAR *pdwNumPins);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryPinState )( 
            ITrnGPIInputOutput __RPC_FAR * This,
            DWORD __RPC_FAR *pdwPinStateMask);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetConfiguration )( 
            ITrnGPIInputOutput __RPC_FAR * This,
            DWORD dwOutputPinMask,
            DWORD dwInvertedPinMask);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryConfiguration )( 
            ITrnGPIInputOutput __RPC_FAR * This,
            DWORD __RPC_FAR *pdwOutputPinMask,
            DWORD __RPC_FAR *pdwInvertedPinMask);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetGPIPreRoll )( 
            ITrnGPIInputOutput __RPC_FAR * This,
            DWORD dwPinIndex,
            unsigned int preRollInFields);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryGPIPreRoll )( 
            ITrnGPIInputOutput __RPC_FAR * This,
            DWORD dwPinIndex,
            unsigned int __RPC_FAR *puPreRoll);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetOutput )( 
            ITrnGPIInputOutput __RPC_FAR * This,
            STrnTimeType __RPC_FAR *pTime,
            ETrnOutputAction action,
            DWORD dwPinIndex,
            unsigned int duration);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *FireEventOnGPI )( 
            ITrnGPIInputOutput __RPC_FAR * This,
            DWORD dwInputPinIndex,
            DWORD dwEventNumber);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *TriggerTrackOnGPI )( 
            ITrnGPIInputOutput __RPC_FAR * This,
            DWORD dwInputPinIndex,
            DWORD dwTrackNumber);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetInputCallback )( 
            ITrnGPIInputOutput __RPC_FAR * This,
            /* [in] */ DWORD dwPinIndex,
            /* [in] */ ITrnEventAdviseSink __RPC_FAR *pAdvise,
            /* [in] */ DWORD dwClientInfo,
            /* [out] */ DWORD __RPC_FAR *pdwEventId);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *CancelCallback )( 
            ITrnGPIInputOutput __RPC_FAR * This,
            /* [in] */ ITrnEventAdviseSink __RPC_FAR *pAdvise);
        
        END_INTERFACE
    } ITrnGPIInputOutputVtbl;

    interface ITrnGPIInputOutput
    {
        CONST_VTBL struct ITrnGPIInputOutputVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ITrnGPIInputOutput_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define ITrnGPIInputOutput_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define ITrnGPIInputOutput_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define ITrnGPIInputOutput_QueryNumPins(This,pdwNumPins)	\
    (This)->lpVtbl -> QueryNumPins(This,pdwNumPins)

#define ITrnGPIInputOutput_QueryPinState(This,pdwPinStateMask)	\
    (This)->lpVtbl -> QueryPinState(This,pdwPinStateMask)

#define ITrnGPIInputOutput_SetConfiguration(This,dwOutputPinMask,dwInvertedPinMask)	\
    (This)->lpVtbl -> SetConfiguration(This,dwOutputPinMask,dwInvertedPinMask)

#define ITrnGPIInputOutput_QueryConfiguration(This,pdwOutputPinMask,pdwInvertedPinMask)	\
    (This)->lpVtbl -> QueryConfiguration(This,pdwOutputPinMask,pdwInvertedPinMask)

#define ITrnGPIInputOutput_SetGPIPreRoll(This,dwPinIndex,preRollInFields)	\
    (This)->lpVtbl -> SetGPIPreRoll(This,dwPinIndex,preRollInFields)

#define ITrnGPIInputOutput_QueryGPIPreRoll(This,dwPinIndex,puPreRoll)	\
    (This)->lpVtbl -> QueryGPIPreRoll(This,dwPinIndex,puPreRoll)

#define ITrnGPIInputOutput_SetOutput(This,pTime,action,dwPinIndex,duration)	\
    (This)->lpVtbl -> SetOutput(This,pTime,action,dwPinIndex,duration)

#define ITrnGPIInputOutput_FireEventOnGPI(This,dwInputPinIndex,dwEventNumber)	\
    (This)->lpVtbl -> FireEventOnGPI(This,dwInputPinIndex,dwEventNumber)

#define ITrnGPIInputOutput_TriggerTrackOnGPI(This,dwInputPinIndex,dwTrackNumber)	\
    (This)->lpVtbl -> TriggerTrackOnGPI(This,dwInputPinIndex,dwTrackNumber)

#define ITrnGPIInputOutput_SetInputCallback(This,dwPinIndex,pAdvise,dwClientInfo,pdwEventId)	\
    (This)->lpVtbl -> SetInputCallback(This,dwPinIndex,pAdvise,dwClientInfo,pdwEventId)

#define ITrnGPIInputOutput_CancelCallback(This,pAdvise)	\
    (This)->lpVtbl -> CancelCallback(This,pAdvise)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE ITrnGPIInputOutput_QueryNumPins_Proxy( 
    ITrnGPIInputOutput __RPC_FAR * This,
    DWORD __RPC_FAR *pdwNumPins);


void __RPC_STUB ITrnGPIInputOutput_QueryNumPins_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE ITrnGPIInputOutput_QueryPinState_Proxy( 
    ITrnGPIInputOutput __RPC_FAR * This,
    DWORD __RPC_FAR *pdwPinStateMask);


void __RPC_STUB ITrnGPIInputOutput_QueryPinState_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE ITrnGPIInputOutput_SetConfiguration_Proxy( 
    ITrnGPIInputOutput __RPC_FAR * This,
    DWORD dwOutputPinMask,
    DWORD dwInvertedPinMask);


void __RPC_STUB ITrnGPIInputOutput_SetConfiguration_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE ITrnGPIInputOutput_QueryConfiguration_Proxy( 
    ITrnGPIInputOutput __RPC_FAR * This,
    DWORD __RPC_FAR *pdwOutputPinMask,
    DWORD __RPC_FAR *pdwInvertedPinMask);


void __RPC_STUB ITrnGPIInputOutput_QueryConfiguration_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE ITrnGPIInputOutput_SetGPIPreRoll_Proxy( 
    ITrnGPIInputOutput __RPC_FAR * This,
    DWORD dwPinIndex,
    unsigned int preRollInFields);


void __RPC_STUB ITrnGPIInputOutput_SetGPIPreRoll_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE ITrnGPIInputOutput_QueryGPIPreRoll_Proxy( 
    ITrnGPIInputOutput __RPC_FAR * This,
    DWORD dwPinIndex,
    unsigned int __RPC_FAR *puPreRoll);


void __RPC_STUB ITrnGPIInputOutput_QueryGPIPreRoll_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE ITrnGPIInputOutput_SetOutput_Proxy( 
    ITrnGPIInputOutput __RPC_FAR * This,
    STrnTimeType __RPC_FAR *pTime,
    ETrnOutputAction action,
    DWORD dwPinIndex,
    unsigned int duration);


void __RPC_STUB ITrnGPIInputOutput_SetOutput_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE ITrnGPIInputOutput_FireEventOnGPI_Proxy( 
    ITrnGPIInputOutput __RPC_FAR * This,
    DWORD dwInputPinIndex,
    DWORD dwEventNumber);


void __RPC_STUB ITrnGPIInputOutput_FireEventOnGPI_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE ITrnGPIInputOutput_TriggerTrackOnGPI_Proxy( 
    ITrnGPIInputOutput __RPC_FAR * This,
    DWORD dwInputPinIndex,
    DWORD dwTrackNumber);


void __RPC_STUB ITrnGPIInputOutput_TriggerTrackOnGPI_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE ITrnGPIInputOutput_SetInputCallback_Proxy( 
    ITrnGPIInputOutput __RPC_FAR * This,
    /* [in] */ DWORD dwPinIndex,
    /* [in] */ ITrnEventAdviseSink __RPC_FAR *pAdvise,
    /* [in] */ DWORD dwClientInfo,
    /* [out] */ DWORD __RPC_FAR *pdwEventId);


void __RPC_STUB ITrnGPIInputOutput_SetInputCallback_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE ITrnGPIInputOutput_CancelCallback_Proxy( 
    ITrnGPIInputOutput __RPC_FAR * This,
    /* [in] */ ITrnEventAdviseSink __RPC_FAR *pAdvise);


void __RPC_STUB ITrnGPIInputOutput_CancelCallback_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __ITrnGPIInputOutput_INTERFACE_DEFINED__ */


/****************************************
 * Generated header for interface: __MIDL_itf_trnity_0184
 * at Tue Nov 23 05:28:37 1999
 * using MIDL 3.01.75
 ****************************************/
/* [local] */ 






typedef 
enum tagETrnSpecialAudioLevels
    {	NegativeInfinity	= -10000
    }	ETrnSpecialAudioLevels;

typedef struct  tagSTrnGainCapabilities
    {
    long gainMin;
    long gainMax;
    long gainDefault;
    }	STrnGainCapabilities;



extern RPC_IF_HANDLE __MIDL_itf_trnity_0184_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_trnity_0184_v0_0_s_ifspec;

#ifndef __ITrnSimpleAudioInput_INTERFACE_DEFINED__
#define __ITrnSimpleAudioInput_INTERFACE_DEFINED__

/****************************************
 * Generated header for interface: ITrnSimpleAudioInput
 * at Tue Nov 23 05:28:37 1999
 * using MIDL 3.01.75
 ****************************************/
/* [unique][uuid][object][local] */ 


typedef 
enum tagETrnEQFilterTypes
    {	FiltFlat	= 1,
	FiltNotch	= 2,
	FiltLowShelf	= 4,
	FiltHighShelf	= 8,
	FiltPeak	= 16
    }	ETrnEQFilterTypes;

typedef 
enum tagETrnACParamType
    {	ACFader	= 0,
	ACPan	= ACFader + 1,
	ACPanLeftOutputNbr	= ACPan + 1,
	ACPanRightOutputNbr	= ACPanLeftOutputNbr + 1,
	ACGain	= ACPanRightOutputNbr + 1,
	ACFXSend	= ACGain + 1,
	ACEQGain	= ACFXSend + 1,
	ACEQCenter	= ACEQGain + 1,
	ACEQQFactor	= ACEQCenter + 1,
	ACEQFilterType	= ACEQQFactor + 1,
	ACDelay	= ACEQFilterType + 1,
	ACClipIndication	= ACDelay + 1,
	ACSteroMode	= ACClipIndication + 1,
	ACSteroPair	= ACSteroMode + 1,
	ACCrossPoint	= ACSteroPair + 1,
	ACFaderLinear	= ACCrossPoint + 1
    }	ETrnACParamType;

typedef struct  tagSTrnACEQBandCapabilities
    {
    STrnGainCapabilities gain;
    DWORD centerMin;
    DWORD centerMax;
    DWORD centerDefault;
    DWORD qFactorMin;
    DWORD qFactorMax;
    DWORD qFactorDefault;
    ETrnEQFilterTypes filterTypeMask;
    ETrnEQFilterTypes filterTypeDefault;
    ETrnEQFilterTypes variableQMask;
    ETrnEQFilterTypes variableGainMask;
    ETrnEQFilterTypes variableCenterMask;
    }	STrnACEQBandCapabilities;

typedef struct  tagSTrnACCapabilities
    {
    DWORD numEQBands;
    STrnGainCapabilities gain;
    DWORD numPans;
    DWORD panMin;
    DWORD panMax;
    DWORD panGranularity;
    DWORD delayMin;
    DWORD delayMax;
    DWORD delayGranularity;
    long inputOperatingLevel;
    DWORD nFXSends;
    }	STrnACCapabilities;


EXTERN_C const IID IID_ITrnSimpleAudioInput;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    interface DECLSPEC_UUID("8335e630-ab3b-11ce-8468-0000b468276b")
    ITrnSimpleAudioInput : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE QueryQRange( 
            /* [in] */ DWORD BandIndex,
            /* [out] */ LONG __RPC_FAR *pdwUpperLimit,
            /* [out] */ LONG __RPC_FAR *pdwLowerLimit) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE QueryQValue( 
            /* [in] */ DWORD BandIndex,
            /* [in] */ LONG QIndex,
            /* [out] */ DWORD __RPC_FAR *pdwQ) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE QueryCenterFreqRange( 
            /* [in] */ DWORD BandIndex,
            /* [out] */ LONG __RPC_FAR *pdwUpperLimit,
            /* [out] */ LONG __RPC_FAR *pdwLowerLimit) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE QueryCenterFreqValue( 
            /* [in] */ DWORD BandIndex,
            /* [in] */ LONG CenterFreqIndex,
            /* [out] */ DWORD __RPC_FAR *pdwCenterFreq) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE QueryChannelNum( 
            /* [out] */ DWORD __RPC_FAR *pChannelNum) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE QueryChannelEQBandCaps( 
            /* [in] */ DWORD band,
            /* [out] */ STrnACEQBandCapabilities __RPC_FAR *pCaps) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE QueryChannelVolumeCaps( 
            /* [in] */ DWORD index,
            /* [out] */ STrnGainCapabilities __RPC_FAR *pCaps) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE QueryChannelFXSendCaps( 
            /* [in] */ DWORD index,
            /* [out] */ STrnGainCapabilities __RPC_FAR *pCaps) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE QueryChannelCaps( 
            /* [out] */ STrnACCapabilities __RPC_FAR *pCaps) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE QueryLevel( 
            /* [in] */ ETrnACParamType whichParm,
            /* [in] */ DWORD index,
            /* [out] */ DWORD __RPC_FAR *pLevel) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetParameter( 
            /* [in] */ ETrnACParamType whichParm,
            /* [in] */ DWORD index,
            /* [in] */ STrnTimeType __RPC_FAR *pTime,
            /* [in] */ STrnPlayList __RPC_FAR *pList) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetMute( 
            /* [in] */ STrnTimeType __RPC_FAR *pTime,
            /* [in] */ BOOL mute) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetSolo( 
            /* [in] */ STrnTimeType __RPC_FAR *pTime,
            /* [in] */ BOOL solo) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE ConvertLinearToDB( 
            /* [in] */ long linearValue,
            /* [out] */ long __RPC_FAR *decibelValue) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE ConvertDBToLinear( 
            /* [in] */ long decibelValue,
            /* [out] */ long __RPC_FAR *linearValue) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct ITrnSimpleAudioInputVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            ITrnSimpleAudioInput __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            ITrnSimpleAudioInput __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            ITrnSimpleAudioInput __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryQRange )( 
            ITrnSimpleAudioInput __RPC_FAR * This,
            /* [in] */ DWORD BandIndex,
            /* [out] */ LONG __RPC_FAR *pdwUpperLimit,
            /* [out] */ LONG __RPC_FAR *pdwLowerLimit);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryQValue )( 
            ITrnSimpleAudioInput __RPC_FAR * This,
            /* [in] */ DWORD BandIndex,
            /* [in] */ LONG QIndex,
            /* [out] */ DWORD __RPC_FAR *pdwQ);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryCenterFreqRange )( 
            ITrnSimpleAudioInput __RPC_FAR * This,
            /* [in] */ DWORD BandIndex,
            /* [out] */ LONG __RPC_FAR *pdwUpperLimit,
            /* [out] */ LONG __RPC_FAR *pdwLowerLimit);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryCenterFreqValue )( 
            ITrnSimpleAudioInput __RPC_FAR * This,
            /* [in] */ DWORD BandIndex,
            /* [in] */ LONG CenterFreqIndex,
            /* [out] */ DWORD __RPC_FAR *pdwCenterFreq);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryChannelNum )( 
            ITrnSimpleAudioInput __RPC_FAR * This,
            /* [out] */ DWORD __RPC_FAR *pChannelNum);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryChannelEQBandCaps )( 
            ITrnSimpleAudioInput __RPC_FAR * This,
            /* [in] */ DWORD band,
            /* [out] */ STrnACEQBandCapabilities __RPC_FAR *pCaps);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryChannelVolumeCaps )( 
            ITrnSimpleAudioInput __RPC_FAR * This,
            /* [in] */ DWORD index,
            /* [out] */ STrnGainCapabilities __RPC_FAR *pCaps);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryChannelFXSendCaps )( 
            ITrnSimpleAudioInput __RPC_FAR * This,
            /* [in] */ DWORD index,
            /* [out] */ STrnGainCapabilities __RPC_FAR *pCaps);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryChannelCaps )( 
            ITrnSimpleAudioInput __RPC_FAR * This,
            /* [out] */ STrnACCapabilities __RPC_FAR *pCaps);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryLevel )( 
            ITrnSimpleAudioInput __RPC_FAR * This,
            /* [in] */ ETrnACParamType whichParm,
            /* [in] */ DWORD index,
            /* [out] */ DWORD __RPC_FAR *pLevel);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetParameter )( 
            ITrnSimpleAudioInput __RPC_FAR * This,
            /* [in] */ ETrnACParamType whichParm,
            /* [in] */ DWORD index,
            /* [in] */ STrnTimeType __RPC_FAR *pTime,
            /* [in] */ STrnPlayList __RPC_FAR *pList);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetMute )( 
            ITrnSimpleAudioInput __RPC_FAR * This,
            /* [in] */ STrnTimeType __RPC_FAR *pTime,
            /* [in] */ BOOL mute);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetSolo )( 
            ITrnSimpleAudioInput __RPC_FAR * This,
            /* [in] */ STrnTimeType __RPC_FAR *pTime,
            /* [in] */ BOOL solo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *ConvertLinearToDB )( 
            ITrnSimpleAudioInput __RPC_FAR * This,
            /* [in] */ long linearValue,
            /* [out] */ long __RPC_FAR *decibelValue);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *ConvertDBToLinear )( 
            ITrnSimpleAudioInput __RPC_FAR * This,
            /* [in] */ long decibelValue,
            /* [out] */ long __RPC_FAR *linearValue);
        
        END_INTERFACE
    } ITrnSimpleAudioInputVtbl;

    interface ITrnSimpleAudioInput
    {
        CONST_VTBL struct ITrnSimpleAudioInputVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ITrnSimpleAudioInput_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define ITrnSimpleAudioInput_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define ITrnSimpleAudioInput_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define ITrnSimpleAudioInput_QueryQRange(This,BandIndex,pdwUpperLimit,pdwLowerLimit)	\
    (This)->lpVtbl -> QueryQRange(This,BandIndex,pdwUpperLimit,pdwLowerLimit)

#define ITrnSimpleAudioInput_QueryQValue(This,BandIndex,QIndex,pdwQ)	\
    (This)->lpVtbl -> QueryQValue(This,BandIndex,QIndex,pdwQ)

#define ITrnSimpleAudioInput_QueryCenterFreqRange(This,BandIndex,pdwUpperLimit,pdwLowerLimit)	\
    (This)->lpVtbl -> QueryCenterFreqRange(This,BandIndex,pdwUpperLimit,pdwLowerLimit)

#define ITrnSimpleAudioInput_QueryCenterFreqValue(This,BandIndex,CenterFreqIndex,pdwCenterFreq)	\
    (This)->lpVtbl -> QueryCenterFreqValue(This,BandIndex,CenterFreqIndex,pdwCenterFreq)

#define ITrnSimpleAudioInput_QueryChannelNum(This,pChannelNum)	\
    (This)->lpVtbl -> QueryChannelNum(This,pChannelNum)

#define ITrnSimpleAudioInput_QueryChannelEQBandCaps(This,band,pCaps)	\
    (This)->lpVtbl -> QueryChannelEQBandCaps(This,band,pCaps)

#define ITrnSimpleAudioInput_QueryChannelVolumeCaps(This,index,pCaps)	\
    (This)->lpVtbl -> QueryChannelVolumeCaps(This,index,pCaps)

#define ITrnSimpleAudioInput_QueryChannelFXSendCaps(This,index,pCaps)	\
    (This)->lpVtbl -> QueryChannelFXSendCaps(This,index,pCaps)

#define ITrnSimpleAudioInput_QueryChannelCaps(This,pCaps)	\
    (This)->lpVtbl -> QueryChannelCaps(This,pCaps)

#define ITrnSimpleAudioInput_QueryLevel(This,whichParm,index,pLevel)	\
    (This)->lpVtbl -> QueryLevel(This,whichParm,index,pLevel)

#define ITrnSimpleAudioInput_SetParameter(This,whichParm,index,pTime,pList)	\
    (This)->lpVtbl -> SetParameter(This,whichParm,index,pTime,pList)

#define ITrnSimpleAudioInput_SetMute(This,pTime,mute)	\
    (This)->lpVtbl -> SetMute(This,pTime,mute)

#define ITrnSimpleAudioInput_SetSolo(This,pTime,solo)	\
    (This)->lpVtbl -> SetSolo(This,pTime,solo)

#define ITrnSimpleAudioInput_ConvertLinearToDB(This,linearValue,decibelValue)	\
    (This)->lpVtbl -> ConvertLinearToDB(This,linearValue,decibelValue)

#define ITrnSimpleAudioInput_ConvertDBToLinear(This,decibelValue,linearValue)	\
    (This)->lpVtbl -> ConvertDBToLinear(This,decibelValue,linearValue)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE ITrnSimpleAudioInput_QueryQRange_Proxy( 
    ITrnSimpleAudioInput __RPC_FAR * This,
    /* [in] */ DWORD BandIndex,
    /* [out] */ LONG __RPC_FAR *pdwUpperLimit,
    /* [out] */ LONG __RPC_FAR *pdwLowerLimit);


void __RPC_STUB ITrnSimpleAudioInput_QueryQRange_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE ITrnSimpleAudioInput_QueryQValue_Proxy( 
    ITrnSimpleAudioInput __RPC_FAR * This,
    /* [in] */ DWORD BandIndex,
    /* [in] */ LONG QIndex,
    /* [out] */ DWORD __RPC_FAR *pdwQ);


void __RPC_STUB ITrnSimpleAudioInput_QueryQValue_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE ITrnSimpleAudioInput_QueryCenterFreqRange_Proxy( 
    ITrnSimpleAudioInput __RPC_FAR * This,
    /* [in] */ DWORD BandIndex,
    /* [out] */ LONG __RPC_FAR *pdwUpperLimit,
    /* [out] */ LONG __RPC_FAR *pdwLowerLimit);


void __RPC_STUB ITrnSimpleAudioInput_QueryCenterFreqRange_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE ITrnSimpleAudioInput_QueryCenterFreqValue_Proxy( 
    ITrnSimpleAudioInput __RPC_FAR * This,
    /* [in] */ DWORD BandIndex,
    /* [in] */ LONG CenterFreqIndex,
    /* [out] */ DWORD __RPC_FAR *pdwCenterFreq);


void __RPC_STUB ITrnSimpleAudioInput_QueryCenterFreqValue_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE ITrnSimpleAudioInput_QueryChannelNum_Proxy( 
    ITrnSimpleAudioInput __RPC_FAR * This,
    /* [out] */ DWORD __RPC_FAR *pChannelNum);


void __RPC_STUB ITrnSimpleAudioInput_QueryChannelNum_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE ITrnSimpleAudioInput_QueryChannelEQBandCaps_Proxy( 
    ITrnSimpleAudioInput __RPC_FAR * This,
    /* [in] */ DWORD band,
    /* [out] */ STrnACEQBandCapabilities __RPC_FAR *pCaps);


void __RPC_STUB ITrnSimpleAudioInput_QueryChannelEQBandCaps_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE ITrnSimpleAudioInput_QueryChannelVolumeCaps_Proxy( 
    ITrnSimpleAudioInput __RPC_FAR * This,
    /* [in] */ DWORD index,
    /* [out] */ STrnGainCapabilities __RPC_FAR *pCaps);


void __RPC_STUB ITrnSimpleAudioInput_QueryChannelVolumeCaps_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE ITrnSimpleAudioInput_QueryChannelFXSendCaps_Proxy( 
    ITrnSimpleAudioInput __RPC_FAR * This,
    /* [in] */ DWORD index,
    /* [out] */ STrnGainCapabilities __RPC_FAR *pCaps);


void __RPC_STUB ITrnSimpleAudioInput_QueryChannelFXSendCaps_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE ITrnSimpleAudioInput_QueryChannelCaps_Proxy( 
    ITrnSimpleAudioInput __RPC_FAR * This,
    /* [out] */ STrnACCapabilities __RPC_FAR *pCaps);


void __RPC_STUB ITrnSimpleAudioInput_QueryChannelCaps_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE ITrnSimpleAudioInput_QueryLevel_Proxy( 
    ITrnSimpleAudioInput __RPC_FAR * This,
    /* [in] */ ETrnACParamType whichParm,
    /* [in] */ DWORD index,
    /* [out] */ DWORD __RPC_FAR *pLevel);


void __RPC_STUB ITrnSimpleAudioInput_QueryLevel_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE ITrnSimpleAudioInput_SetParameter_Proxy( 
    ITrnSimpleAudioInput __RPC_FAR * This,
    /* [in] */ ETrnACParamType whichParm,
    /* [in] */ DWORD index,
    /* [in] */ STrnTimeType __RPC_FAR *pTime,
    /* [in] */ STrnPlayList __RPC_FAR *pList);


void __RPC_STUB ITrnSimpleAudioInput_SetParameter_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE ITrnSimpleAudioInput_SetMute_Proxy( 
    ITrnSimpleAudioInput __RPC_FAR * This,
    /* [in] */ STrnTimeType __RPC_FAR *pTime,
    /* [in] */ BOOL mute);


void __RPC_STUB ITrnSimpleAudioInput_SetMute_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE ITrnSimpleAudioInput_SetSolo_Proxy( 
    ITrnSimpleAudioInput __RPC_FAR * This,
    /* [in] */ STrnTimeType __RPC_FAR *pTime,
    /* [in] */ BOOL solo);


void __RPC_STUB ITrnSimpleAudioInput_SetSolo_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE ITrnSimpleAudioInput_ConvertLinearToDB_Proxy( 
    ITrnSimpleAudioInput __RPC_FAR * This,
    /* [in] */ long linearValue,
    /* [out] */ long __RPC_FAR *decibelValue);


void __RPC_STUB ITrnSimpleAudioInput_ConvertLinearToDB_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE ITrnSimpleAudioInput_ConvertDBToLinear_Proxy( 
    ITrnSimpleAudioInput __RPC_FAR * This,
    /* [in] */ long decibelValue,
    /* [out] */ long __RPC_FAR *linearValue);


void __RPC_STUB ITrnSimpleAudioInput_ConvertDBToLinear_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __ITrnSimpleAudioInput_INTERFACE_DEFINED__ */


/****************************************
 * Generated header for interface: __MIDL_itf_trnity_0185
 * at Tue Nov 23 05:28:37 1999
 * using MIDL 3.01.75
 ****************************************/
/* [local] */ 


typedef struct  tagSTrnTaggedAudioUpdate
    {
    DWORD dest;
    DWORD index;
    DWORD whichParam;
    DWORD level;
    }	STrnTaggedAudioUpdate;

typedef struct  tagSTrnTaggedAudioUpdatePacket
    {
    DWORD nTaggedAudioUpdates;
    DWORD reserved;
    STrnTaggedAudioUpdate pTaggedAudioUpdate[ 1 ];
    }	STrnTaggedAudioUpdatePacket;



extern RPC_IF_HANDLE __MIDL_itf_trnity_0185_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_trnity_0185_v0_0_s_ifspec;

#ifndef __ITrnSimpleAudioAdviseSink_INTERFACE_DEFINED__
#define __ITrnSimpleAudioAdviseSink_INTERFACE_DEFINED__

/****************************************
 * Generated header for interface: ITrnSimpleAudioAdviseSink
 * at Tue Nov 23 05:28:37 1999
 * using MIDL 3.01.75
 ****************************************/
/* [unique][uuid][object][local] */ 



EXTERN_C const IID IID_ITrnSimpleAudioAdviseSink;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    interface DECLSPEC_UUID("8335e631-ab3b-11ce-8468-0000b468276b")
    ITrnSimpleAudioAdviseSink : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE OnAudioMixerUpdate( 
            /* [in] */ STrnTaggedAudioUpdatePacket __RPC_FAR *pTaggedAudioUpdatePacket) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct ITrnSimpleAudioAdviseSinkVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            ITrnSimpleAudioAdviseSink __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            ITrnSimpleAudioAdviseSink __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            ITrnSimpleAudioAdviseSink __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *OnAudioMixerUpdate )( 
            ITrnSimpleAudioAdviseSink __RPC_FAR * This,
            /* [in] */ STrnTaggedAudioUpdatePacket __RPC_FAR *pTaggedAudioUpdatePacket);
        
        END_INTERFACE
    } ITrnSimpleAudioAdviseSinkVtbl;

    interface ITrnSimpleAudioAdviseSink
    {
        CONST_VTBL struct ITrnSimpleAudioAdviseSinkVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ITrnSimpleAudioAdviseSink_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define ITrnSimpleAudioAdviseSink_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define ITrnSimpleAudioAdviseSink_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define ITrnSimpleAudioAdviseSink_OnAudioMixerUpdate(This,pTaggedAudioUpdatePacket)	\
    (This)->lpVtbl -> OnAudioMixerUpdate(This,pTaggedAudioUpdatePacket)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE ITrnSimpleAudioAdviseSink_OnAudioMixerUpdate_Proxy( 
    ITrnSimpleAudioAdviseSink __RPC_FAR * This,
    /* [in] */ STrnTaggedAudioUpdatePacket __RPC_FAR *pTaggedAudioUpdatePacket);


void __RPC_STUB ITrnSimpleAudioAdviseSink_OnAudioMixerUpdate_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __ITrnSimpleAudioAdviseSink_INTERFACE_DEFINED__ */


#ifndef __ITrnSimpleAudio_INTERFACE_DEFINED__
#define __ITrnSimpleAudio_INTERFACE_DEFINED__

/****************************************
 * Generated header for interface: ITrnSimpleAudio
 * at Tue Nov 23 05:28:37 1999
 * using MIDL 3.01.75
 ****************************************/
/* [unique][uuid][object][local] */ 


typedef 
enum tagETrnAMParamType
    {	AMMeterScale	= 0,
	AMFader	= AMMeterScale + 1,
	AMMonitor	= AMFader + 1,
	AMMeterData	= AMMonitor + 1,
	AMMeterPeak	= AMMeterData + 1
    }	ETrnAMParamType;

typedef struct  tagSTrnAMCapabilities
    {
    DWORD nPgmOuts;
    DWORD nMonitorOuts;
    DWORD nMeters;
    DWORD nInputs;
    DWORD nFXReturns;
    DWORD nBits;
    DWORD nSamples;
    }	STrnAMCapabilities;

typedef 
enum tagEMonMeter
    {	MMonitor	= 0,
	MMeter	= 1
    }	EMonMeter;

typedef 
enum tagEMeteringScale
    {	MSVu	= 0,
	MSPpm	= 1
    }	EMeteringScale;

typedef struct  tagSTrnMeteringScaleCapabilties
    {
    long min;
    long max;
    DWORD nSegments;
    DWORD zeroSegment;
    }	STrnMeteringScaleCapabilties;

typedef 
enum tagEMonMeterSwitchPositions
    {	MMSoloBus	= 0,
	MMSendBus	= MMSoloBus + 1,
	MMProgramBus	= MMSendBus + 1
    }	EMonMeterSwitchPositions;


EXTERN_C const IID IID_ITrnSimpleAudio;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    interface DECLSPEC_UUID("8335e632-ab3b-11ce-8468-0000b468276b")
    ITrnSimpleAudio : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE Advise( 
            /* [in] */ ITrnSimpleAudioAdviseSink __RPC_FAR *AdvSink,
            /* [out] */ DWORD __RPC_FAR *pConnectionId) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE UnAdvise( 
            /* [in] */ DWORD ConnectionId) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE QueryFaderCaps( 
            /* [in] */ DWORD index,
            /* [out] */ STrnGainCapabilities __RPC_FAR *pCaps) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE QueryMonitorCaps( 
            /* [in] */ DWORD index,
            /* [out] */ STrnGainCapabilities __RPC_FAR *pCaps) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE QueryMeterCaps( 
            /* [in] */ DWORD index,
            /* [out] */ STrnMeteringScaleCapabilties __RPC_FAR *pCaps) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE QueryCapabilities( 
            /* [out] */ STrnAMCapabilities __RPC_FAR *pCaps) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE EnumInputs( 
            /* [out] */ IEnumUnknown __RPC_FAR *__RPC_FAR *ppenum) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE QueryLevel( 
            /* [in] */ ETrnAMParamType whichParam,
            /* [in] */ DWORD index,
            /* [out] */ DWORD __RPC_FAR *pLevel) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetParameter( 
            /* [in] */ ETrnAMParamType whichParam,
            /* [in] */ DWORD index,
            /* [in] */ STrnTimeType __RPC_FAR *pTime,
            /* [in] */ STrnPlayList __RPC_FAR *pList) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetMonitorOrMeterSwitch( 
            /* [in] */ EMonMeter monitorOrMeter,
            /* [in] */ DWORD monitorOrMeterIndex,
            /* [in] */ EMonMeterSwitchPositions switchPosition,
            /* [in] */ STrnTimeType __RPC_FAR *pTime) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetMonitorMute( 
            /* [in] */ STrnTimeType __RPC_FAR *pTime,
            /* [in] */ DWORD index,
            /* [in] */ BOOL mute) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct ITrnSimpleAudioVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            ITrnSimpleAudio __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            ITrnSimpleAudio __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            ITrnSimpleAudio __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Advise )( 
            ITrnSimpleAudio __RPC_FAR * This,
            /* [in] */ ITrnSimpleAudioAdviseSink __RPC_FAR *AdvSink,
            /* [out] */ DWORD __RPC_FAR *pConnectionId);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *UnAdvise )( 
            ITrnSimpleAudio __RPC_FAR * This,
            /* [in] */ DWORD ConnectionId);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryFaderCaps )( 
            ITrnSimpleAudio __RPC_FAR * This,
            /* [in] */ DWORD index,
            /* [out] */ STrnGainCapabilities __RPC_FAR *pCaps);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryMonitorCaps )( 
            ITrnSimpleAudio __RPC_FAR * This,
            /* [in] */ DWORD index,
            /* [out] */ STrnGainCapabilities __RPC_FAR *pCaps);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryMeterCaps )( 
            ITrnSimpleAudio __RPC_FAR * This,
            /* [in] */ DWORD index,
            /* [out] */ STrnMeteringScaleCapabilties __RPC_FAR *pCaps);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryCapabilities )( 
            ITrnSimpleAudio __RPC_FAR * This,
            /* [out] */ STrnAMCapabilities __RPC_FAR *pCaps);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *EnumInputs )( 
            ITrnSimpleAudio __RPC_FAR * This,
            /* [out] */ IEnumUnknown __RPC_FAR *__RPC_FAR *ppenum);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryLevel )( 
            ITrnSimpleAudio __RPC_FAR * This,
            /* [in] */ ETrnAMParamType whichParam,
            /* [in] */ DWORD index,
            /* [out] */ DWORD __RPC_FAR *pLevel);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetParameter )( 
            ITrnSimpleAudio __RPC_FAR * This,
            /* [in] */ ETrnAMParamType whichParam,
            /* [in] */ DWORD index,
            /* [in] */ STrnTimeType __RPC_FAR *pTime,
            /* [in] */ STrnPlayList __RPC_FAR *pList);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetMonitorOrMeterSwitch )( 
            ITrnSimpleAudio __RPC_FAR * This,
            /* [in] */ EMonMeter monitorOrMeter,
            /* [in] */ DWORD monitorOrMeterIndex,
            /* [in] */ EMonMeterSwitchPositions switchPosition,
            /* [in] */ STrnTimeType __RPC_FAR *pTime);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetMonitorMute )( 
            ITrnSimpleAudio __RPC_FAR * This,
            /* [in] */ STrnTimeType __RPC_FAR *pTime,
            /* [in] */ DWORD index,
            /* [in] */ BOOL mute);
        
        END_INTERFACE
    } ITrnSimpleAudioVtbl;

    interface ITrnSimpleAudio
    {
        CONST_VTBL struct ITrnSimpleAudioVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ITrnSimpleAudio_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define ITrnSimpleAudio_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define ITrnSimpleAudio_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define ITrnSimpleAudio_Advise(This,AdvSink,pConnectionId)	\
    (This)->lpVtbl -> Advise(This,AdvSink,pConnectionId)

#define ITrnSimpleAudio_UnAdvise(This,ConnectionId)	\
    (This)->lpVtbl -> UnAdvise(This,ConnectionId)

#define ITrnSimpleAudio_QueryFaderCaps(This,index,pCaps)	\
    (This)->lpVtbl -> QueryFaderCaps(This,index,pCaps)

#define ITrnSimpleAudio_QueryMonitorCaps(This,index,pCaps)	\
    (This)->lpVtbl -> QueryMonitorCaps(This,index,pCaps)

#define ITrnSimpleAudio_QueryMeterCaps(This,index,pCaps)	\
    (This)->lpVtbl -> QueryMeterCaps(This,index,pCaps)

#define ITrnSimpleAudio_QueryCapabilities(This,pCaps)	\
    (This)->lpVtbl -> QueryCapabilities(This,pCaps)

#define ITrnSimpleAudio_EnumInputs(This,ppenum)	\
    (This)->lpVtbl -> EnumInputs(This,ppenum)

#define ITrnSimpleAudio_QueryLevel(This,whichParam,index,pLevel)	\
    (This)->lpVtbl -> QueryLevel(This,whichParam,index,pLevel)

#define ITrnSimpleAudio_SetParameter(This,whichParam,index,pTime,pList)	\
    (This)->lpVtbl -> SetParameter(This,whichParam,index,pTime,pList)

#define ITrnSimpleAudio_SetMonitorOrMeterSwitch(This,monitorOrMeter,monitorOrMeterIndex,switchPosition,pTime)	\
    (This)->lpVtbl -> SetMonitorOrMeterSwitch(This,monitorOrMeter,monitorOrMeterIndex,switchPosition,pTime)

#define ITrnSimpleAudio_SetMonitorMute(This,pTime,index,mute)	\
    (This)->lpVtbl -> SetMonitorMute(This,pTime,index,mute)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE ITrnSimpleAudio_Advise_Proxy( 
    ITrnSimpleAudio __RPC_FAR * This,
    /* [in] */ ITrnSimpleAudioAdviseSink __RPC_FAR *AdvSink,
    /* [out] */ DWORD __RPC_FAR *pConnectionId);


void __RPC_STUB ITrnSimpleAudio_Advise_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE ITrnSimpleAudio_UnAdvise_Proxy( 
    ITrnSimpleAudio __RPC_FAR * This,
    /* [in] */ DWORD ConnectionId);


void __RPC_STUB ITrnSimpleAudio_UnAdvise_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE ITrnSimpleAudio_QueryFaderCaps_Proxy( 
    ITrnSimpleAudio __RPC_FAR * This,
    /* [in] */ DWORD index,
    /* [out] */ STrnGainCapabilities __RPC_FAR *pCaps);


void __RPC_STUB ITrnSimpleAudio_QueryFaderCaps_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE ITrnSimpleAudio_QueryMonitorCaps_Proxy( 
    ITrnSimpleAudio __RPC_FAR * This,
    /* [in] */ DWORD index,
    /* [out] */ STrnGainCapabilities __RPC_FAR *pCaps);


void __RPC_STUB ITrnSimpleAudio_QueryMonitorCaps_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE ITrnSimpleAudio_QueryMeterCaps_Proxy( 
    ITrnSimpleAudio __RPC_FAR * This,
    /* [in] */ DWORD index,
    /* [out] */ STrnMeteringScaleCapabilties __RPC_FAR *pCaps);


void __RPC_STUB ITrnSimpleAudio_QueryMeterCaps_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE ITrnSimpleAudio_QueryCapabilities_Proxy( 
    ITrnSimpleAudio __RPC_FAR * This,
    /* [out] */ STrnAMCapabilities __RPC_FAR *pCaps);


void __RPC_STUB ITrnSimpleAudio_QueryCapabilities_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE ITrnSimpleAudio_EnumInputs_Proxy( 
    ITrnSimpleAudio __RPC_FAR * This,
    /* [out] */ IEnumUnknown __RPC_FAR *__RPC_FAR *ppenum);


void __RPC_STUB ITrnSimpleAudio_EnumInputs_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE ITrnSimpleAudio_QueryLevel_Proxy( 
    ITrnSimpleAudio __RPC_FAR * This,
    /* [in] */ ETrnAMParamType whichParam,
    /* [in] */ DWORD index,
    /* [out] */ DWORD __RPC_FAR *pLevel);


void __RPC_STUB ITrnSimpleAudio_QueryLevel_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE ITrnSimpleAudio_SetParameter_Proxy( 
    ITrnSimpleAudio __RPC_FAR * This,
    /* [in] */ ETrnAMParamType whichParam,
    /* [in] */ DWORD index,
    /* [in] */ STrnTimeType __RPC_FAR *pTime,
    /* [in] */ STrnPlayList __RPC_FAR *pList);


void __RPC_STUB ITrnSimpleAudio_SetParameter_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE ITrnSimpleAudio_SetMonitorOrMeterSwitch_Proxy( 
    ITrnSimpleAudio __RPC_FAR * This,
    /* [in] */ EMonMeter monitorOrMeter,
    /* [in] */ DWORD monitorOrMeterIndex,
    /* [in] */ EMonMeterSwitchPositions switchPosition,
    /* [in] */ STrnTimeType __RPC_FAR *pTime);


void __RPC_STUB ITrnSimpleAudio_SetMonitorOrMeterSwitch_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE ITrnSimpleAudio_SetMonitorMute_Proxy( 
    ITrnSimpleAudio __RPC_FAR * This,
    /* [in] */ STrnTimeType __RPC_FAR *pTime,
    /* [in] */ DWORD index,
    /* [in] */ BOOL mute);


void __RPC_STUB ITrnSimpleAudio_SetMonitorMute_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __ITrnSimpleAudio_INTERFACE_DEFINED__ */


#ifndef __ITrnBASAudioInput_INTERFACE_DEFINED__
#define __ITrnBASAudioInput_INTERFACE_DEFINED__

/****************************************
 * Generated header for interface: ITrnBASAudioInput
 * at Tue Nov 23 05:28:37 1999
 * using MIDL 3.01.75
 ****************************************/
/* [unique][uuid][object][local] */ 


typedef 
enum tagETrnBASReturnCapabilities
    {	RCInput	= 0x1,
	RCReturn	= 0x10,
	RCInputOrReturn	= RCInput | RCReturn
    }	ETrnBASReturnCapabilities;

typedef 
enum tagETrnBASLevelBoostCapabilities
    {	BCLineLevel	= 0x1,
	BCMicLevel	= 0x10,
	BCLineOrMicLevel	= BCLineLevel | BCMicLevel
    }	ETrnBASLevelBoostCapabilities;

typedef 
enum tagETrnBASACParamType
    {	BASACIsReturn	= 0,
	BASACIsMicLevel	= BASACIsReturn + 1
    }	ETrnBASACParamType;

typedef struct  tasSTrnBASACCapabilities
    {
    ETrnBASReturnCapabilities returnCapabilityMask;
    ETrnBASLevelBoostCapabilities inputLevelBoostCapability;
    }	STrnBASACCapabilities;


EXTERN_C const IID IID_ITrnBASAudioInput;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    interface DECLSPEC_UUID("8335e633-ab3b-11ce-8468-0000b468276b")
    ITrnBASAudioInput : public ITrnSimpleAudioInput
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE QueryBASChannelCaps( 
            /* [in] */ DWORD channel,
            /* [out] */ STrnBASACCapabilities __RPC_FAR *pCaps) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE QueryBASLevel( 
            /* [in] */ ETrnBASACParamType whichParm,
            /* [out] */ DWORD __RPC_FAR *pLevel) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetBASParameter( 
            /* [in] */ ETrnBASACParamType whichParm,
            /* [in] */ STrnTimeType __RPC_FAR *pTime,
            /* [in] */ STrnPlayList __RPC_FAR *pList) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct ITrnBASAudioInputVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            ITrnBASAudioInput __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            ITrnBASAudioInput __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            ITrnBASAudioInput __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryQRange )( 
            ITrnBASAudioInput __RPC_FAR * This,
            /* [in] */ DWORD BandIndex,
            /* [out] */ LONG __RPC_FAR *pdwUpperLimit,
            /* [out] */ LONG __RPC_FAR *pdwLowerLimit);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryQValue )( 
            ITrnBASAudioInput __RPC_FAR * This,
            /* [in] */ DWORD BandIndex,
            /* [in] */ LONG QIndex,
            /* [out] */ DWORD __RPC_FAR *pdwQ);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryCenterFreqRange )( 
            ITrnBASAudioInput __RPC_FAR * This,
            /* [in] */ DWORD BandIndex,
            /* [out] */ LONG __RPC_FAR *pdwUpperLimit,
            /* [out] */ LONG __RPC_FAR *pdwLowerLimit);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryCenterFreqValue )( 
            ITrnBASAudioInput __RPC_FAR * This,
            /* [in] */ DWORD BandIndex,
            /* [in] */ LONG CenterFreqIndex,
            /* [out] */ DWORD __RPC_FAR *pdwCenterFreq);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryChannelNum )( 
            ITrnBASAudioInput __RPC_FAR * This,
            /* [out] */ DWORD __RPC_FAR *pChannelNum);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryChannelEQBandCaps )( 
            ITrnBASAudioInput __RPC_FAR * This,
            /* [in] */ DWORD band,
            /* [out] */ STrnACEQBandCapabilities __RPC_FAR *pCaps);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryChannelVolumeCaps )( 
            ITrnBASAudioInput __RPC_FAR * This,
            /* [in] */ DWORD index,
            /* [out] */ STrnGainCapabilities __RPC_FAR *pCaps);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryChannelFXSendCaps )( 
            ITrnBASAudioInput __RPC_FAR * This,
            /* [in] */ DWORD index,
            /* [out] */ STrnGainCapabilities __RPC_FAR *pCaps);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryChannelCaps )( 
            ITrnBASAudioInput __RPC_FAR * This,
            /* [out] */ STrnACCapabilities __RPC_FAR *pCaps);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryLevel )( 
            ITrnBASAudioInput __RPC_FAR * This,
            /* [in] */ ETrnACParamType whichParm,
            /* [in] */ DWORD index,
            /* [out] */ DWORD __RPC_FAR *pLevel);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetParameter )( 
            ITrnBASAudioInput __RPC_FAR * This,
            /* [in] */ ETrnACParamType whichParm,
            /* [in] */ DWORD index,
            /* [in] */ STrnTimeType __RPC_FAR *pTime,
            /* [in] */ STrnPlayList __RPC_FAR *pList);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetMute )( 
            ITrnBASAudioInput __RPC_FAR * This,
            /* [in] */ STrnTimeType __RPC_FAR *pTime,
            /* [in] */ BOOL mute);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetSolo )( 
            ITrnBASAudioInput __RPC_FAR * This,
            /* [in] */ STrnTimeType __RPC_FAR *pTime,
            /* [in] */ BOOL solo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *ConvertLinearToDB )( 
            ITrnBASAudioInput __RPC_FAR * This,
            /* [in] */ long linearValue,
            /* [out] */ long __RPC_FAR *decibelValue);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *ConvertDBToLinear )( 
            ITrnBASAudioInput __RPC_FAR * This,
            /* [in] */ long decibelValue,
            /* [out] */ long __RPC_FAR *linearValue);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryBASChannelCaps )( 
            ITrnBASAudioInput __RPC_FAR * This,
            /* [in] */ DWORD channel,
            /* [out] */ STrnBASACCapabilities __RPC_FAR *pCaps);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryBASLevel )( 
            ITrnBASAudioInput __RPC_FAR * This,
            /* [in] */ ETrnBASACParamType whichParm,
            /* [out] */ DWORD __RPC_FAR *pLevel);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetBASParameter )( 
            ITrnBASAudioInput __RPC_FAR * This,
            /* [in] */ ETrnBASACParamType whichParm,
            /* [in] */ STrnTimeType __RPC_FAR *pTime,
            /* [in] */ STrnPlayList __RPC_FAR *pList);
        
        END_INTERFACE
    } ITrnBASAudioInputVtbl;

    interface ITrnBASAudioInput
    {
        CONST_VTBL struct ITrnBASAudioInputVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ITrnBASAudioInput_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define ITrnBASAudioInput_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define ITrnBASAudioInput_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define ITrnBASAudioInput_QueryQRange(This,BandIndex,pdwUpperLimit,pdwLowerLimit)	\
    (This)->lpVtbl -> QueryQRange(This,BandIndex,pdwUpperLimit,pdwLowerLimit)

#define ITrnBASAudioInput_QueryQValue(This,BandIndex,QIndex,pdwQ)	\
    (This)->lpVtbl -> QueryQValue(This,BandIndex,QIndex,pdwQ)

#define ITrnBASAudioInput_QueryCenterFreqRange(This,BandIndex,pdwUpperLimit,pdwLowerLimit)	\
    (This)->lpVtbl -> QueryCenterFreqRange(This,BandIndex,pdwUpperLimit,pdwLowerLimit)

#define ITrnBASAudioInput_QueryCenterFreqValue(This,BandIndex,CenterFreqIndex,pdwCenterFreq)	\
    (This)->lpVtbl -> QueryCenterFreqValue(This,BandIndex,CenterFreqIndex,pdwCenterFreq)

#define ITrnBASAudioInput_QueryChannelNum(This,pChannelNum)	\
    (This)->lpVtbl -> QueryChannelNum(This,pChannelNum)

#define ITrnBASAudioInput_QueryChannelEQBandCaps(This,band,pCaps)	\
    (This)->lpVtbl -> QueryChannelEQBandCaps(This,band,pCaps)

#define ITrnBASAudioInput_QueryChannelVolumeCaps(This,index,pCaps)	\
    (This)->lpVtbl -> QueryChannelVolumeCaps(This,index,pCaps)

#define ITrnBASAudioInput_QueryChannelFXSendCaps(This,index,pCaps)	\
    (This)->lpVtbl -> QueryChannelFXSendCaps(This,index,pCaps)

#define ITrnBASAudioInput_QueryChannelCaps(This,pCaps)	\
    (This)->lpVtbl -> QueryChannelCaps(This,pCaps)

#define ITrnBASAudioInput_QueryLevel(This,whichParm,index,pLevel)	\
    (This)->lpVtbl -> QueryLevel(This,whichParm,index,pLevel)

#define ITrnBASAudioInput_SetParameter(This,whichParm,index,pTime,pList)	\
    (This)->lpVtbl -> SetParameter(This,whichParm,index,pTime,pList)

#define ITrnBASAudioInput_SetMute(This,pTime,mute)	\
    (This)->lpVtbl -> SetMute(This,pTime,mute)

#define ITrnBASAudioInput_SetSolo(This,pTime,solo)	\
    (This)->lpVtbl -> SetSolo(This,pTime,solo)

#define ITrnBASAudioInput_ConvertLinearToDB(This,linearValue,decibelValue)	\
    (This)->lpVtbl -> ConvertLinearToDB(This,linearValue,decibelValue)

#define ITrnBASAudioInput_ConvertDBToLinear(This,decibelValue,linearValue)	\
    (This)->lpVtbl -> ConvertDBToLinear(This,decibelValue,linearValue)


#define ITrnBASAudioInput_QueryBASChannelCaps(This,channel,pCaps)	\
    (This)->lpVtbl -> QueryBASChannelCaps(This,channel,pCaps)

#define ITrnBASAudioInput_QueryBASLevel(This,whichParm,pLevel)	\
    (This)->lpVtbl -> QueryBASLevel(This,whichParm,pLevel)

#define ITrnBASAudioInput_SetBASParameter(This,whichParm,pTime,pList)	\
    (This)->lpVtbl -> SetBASParameter(This,whichParm,pTime,pList)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE ITrnBASAudioInput_QueryBASChannelCaps_Proxy( 
    ITrnBASAudioInput __RPC_FAR * This,
    /* [in] */ DWORD channel,
    /* [out] */ STrnBASACCapabilities __RPC_FAR *pCaps);


void __RPC_STUB ITrnBASAudioInput_QueryBASChannelCaps_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE ITrnBASAudioInput_QueryBASLevel_Proxy( 
    ITrnBASAudioInput __RPC_FAR * This,
    /* [in] */ ETrnBASACParamType whichParm,
    /* [out] */ DWORD __RPC_FAR *pLevel);


void __RPC_STUB ITrnBASAudioInput_QueryBASLevel_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE ITrnBASAudioInput_SetBASParameter_Proxy( 
    ITrnBASAudioInput __RPC_FAR * This,
    /* [in] */ ETrnBASACParamType whichParm,
    /* [in] */ STrnTimeType __RPC_FAR *pTime,
    /* [in] */ STrnPlayList __RPC_FAR *pList);


void __RPC_STUB ITrnBASAudioInput_SetBASParameter_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __ITrnBASAudioInput_INTERFACE_DEFINED__ */


/* Additional Prototypes for ALL interfaces */

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif
