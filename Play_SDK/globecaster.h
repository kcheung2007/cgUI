/* this ALWAYS GENERATED file contains the definitions for the interfaces */


/* File created by MIDL compiler version 3.01.75 */
/* at Tue Nov 23 05:28:31 1999
 */
/* Compiler settings for globecaster.idl:
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

#ifndef __globecaster_h__
#define __globecaster_h__

#ifdef __cplusplus
extern "C"{
#endif 

/* Forward Declarations */ 

#ifndef __ITrnMultiCaster_FWD_DEFINED__
#define __ITrnMultiCaster_FWD_DEFINED__
typedef interface ITrnMultiCaster ITrnMultiCaster;
#endif 	/* __ITrnMultiCaster_FWD_DEFINED__ */


/* header files for imported files */
#include "wtypes.h"
#include "unknwn.h"
#include "objidl.h"
#include "gxlate.h"
#include "trnity.h"

void __RPC_FAR * __RPC_USER MIDL_user_allocate(size_t);
void __RPC_USER MIDL_user_free( void __RPC_FAR * ); 

/****************************************
 * Generated header for interface: __MIDL_itf_globecaster_0000
 * at Tue Nov 23 05:28:31 1999
 * using MIDL 3.01.75
 ****************************************/
/* [local] */ 


typedef 
enum tagETrnGlobeCasterFormat
    {	UYVY	= 1,
	HH_UYVY	= UYVY + 1,
	YV12	= HH_UYVY + 1,
	HH_YV12	= YV12 + 1,
	YVU9	= HH_YV12 + 1,
	HH_YVU9	= YVU9 + 1,
	BI_RGB_24	= HH_YVU9 + 1,
	HH_BI_RGB_24	= BI_RGB_24 + 1,
	BI_RGB_16	= HH_BI_RGB_24 + 1,
	HH_BI_RGB_16	= BI_RGB_16 + 1
    }	ETrnGlobeCasterFormat;



extern RPC_IF_HANDLE __MIDL_itf_globecaster_0000_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_globecaster_0000_v0_0_s_ifspec;

#ifndef __ITrnMultiCaster_INTERFACE_DEFINED__
#define __ITrnMultiCaster_INTERFACE_DEFINED__

/****************************************
 * Generated header for interface: ITrnMultiCaster
 * at Tue Nov 23 05:28:31 1999
 * using MIDL 3.01.75
 ****************************************/
/* [unique][uuid][object][local] */ 



EXTERN_C const IID IID_ITrnMultiCaster;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    interface DECLSPEC_UUID("8335e7e8-ab3b-11ce-8468-0000b468276b")
    ITrnMultiCaster : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE DoMulticastParamDlg( 
            /* [in] */ HWND hWndParent) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Start( 
            /* [in] */ unsigned int uiGrabSource,
            /* [in] */ STrnRect __RPC_FAR *pSourceRect,
            /* [in] */ ETrnGlobeCasterFormat eFormat,
            /* [in] */ WORD wWidth,
            /* [in] */ WORD wHeight,
            /* [in] */ WORD wFieldsPerGrab,
            /* [out] */ DWORD __RPC_FAR *pdwConnectionId) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Stop( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE QueryImageFormat( 
            /* [out][in] */ BITMAPINFOHEADER __RPC_FAR *pBmi,
            /* [out][in] */ EPlayFrameType __RPC_FAR *pFormat) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Advise( 
            /* [in] */ ITrnClipAdviseSink __RPC_FAR *pAdvise,
            /* [in] */ BYTE __RPC_FAR *__RPC_FAR *pClientBuffer,
            /* [out] */ SPlayBitMap __RPC_FAR *__RPC_FAR *ppClipSPlayBitMap,
            /* [out] */ BOOL __RPC_FAR *__RPC_FAR *ppbQueuedToSend) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct ITrnMultiCasterVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            ITrnMultiCaster __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            ITrnMultiCaster __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            ITrnMultiCaster __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *DoMulticastParamDlg )( 
            ITrnMultiCaster __RPC_FAR * This,
            /* [in] */ HWND hWndParent);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Start )( 
            ITrnMultiCaster __RPC_FAR * This,
            /* [in] */ unsigned int uiGrabSource,
            /* [in] */ STrnRect __RPC_FAR *pSourceRect,
            /* [in] */ ETrnGlobeCasterFormat eFormat,
            /* [in] */ WORD wWidth,
            /* [in] */ WORD wHeight,
            /* [in] */ WORD wFieldsPerGrab,
            /* [out] */ DWORD __RPC_FAR *pdwConnectionId);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Stop )( 
            ITrnMultiCaster __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryImageFormat )( 
            ITrnMultiCaster __RPC_FAR * This,
            /* [out][in] */ BITMAPINFOHEADER __RPC_FAR *pBmi,
            /* [out][in] */ EPlayFrameType __RPC_FAR *pFormat);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Advise )( 
            ITrnMultiCaster __RPC_FAR * This,
            /* [in] */ ITrnClipAdviseSink __RPC_FAR *pAdvise,
            /* [in] */ BYTE __RPC_FAR *__RPC_FAR *pClientBuffer,
            /* [out] */ SPlayBitMap __RPC_FAR *__RPC_FAR *ppClipSPlayBitMap,
            /* [out] */ BOOL __RPC_FAR *__RPC_FAR *ppbQueuedToSend);
        
        END_INTERFACE
    } ITrnMultiCasterVtbl;

    interface ITrnMultiCaster
    {
        CONST_VTBL struct ITrnMultiCasterVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ITrnMultiCaster_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define ITrnMultiCaster_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define ITrnMultiCaster_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define ITrnMultiCaster_DoMulticastParamDlg(This,hWndParent)	\
    (This)->lpVtbl -> DoMulticastParamDlg(This,hWndParent)

#define ITrnMultiCaster_Start(This,uiGrabSource,pSourceRect,eFormat,wWidth,wHeight,wFieldsPerGrab,pdwConnectionId)	\
    (This)->lpVtbl -> Start(This,uiGrabSource,pSourceRect,eFormat,wWidth,wHeight,wFieldsPerGrab,pdwConnectionId)

#define ITrnMultiCaster_Stop(This)	\
    (This)->lpVtbl -> Stop(This)

#define ITrnMultiCaster_QueryImageFormat(This,pBmi,pFormat)	\
    (This)->lpVtbl -> QueryImageFormat(This,pBmi,pFormat)

#define ITrnMultiCaster_Advise(This,pAdvise,pClientBuffer,ppClipSPlayBitMap,ppbQueuedToSend)	\
    (This)->lpVtbl -> Advise(This,pAdvise,pClientBuffer,ppClipSPlayBitMap,ppbQueuedToSend)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE ITrnMultiCaster_DoMulticastParamDlg_Proxy( 
    ITrnMultiCaster __RPC_FAR * This,
    /* [in] */ HWND hWndParent);


void __RPC_STUB ITrnMultiCaster_DoMulticastParamDlg_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE ITrnMultiCaster_Start_Proxy( 
    ITrnMultiCaster __RPC_FAR * This,
    /* [in] */ unsigned int uiGrabSource,
    /* [in] */ STrnRect __RPC_FAR *pSourceRect,
    /* [in] */ ETrnGlobeCasterFormat eFormat,
    /* [in] */ WORD wWidth,
    /* [in] */ WORD wHeight,
    /* [in] */ WORD wFieldsPerGrab,
    /* [out] */ DWORD __RPC_FAR *pdwConnectionId);


void __RPC_STUB ITrnMultiCaster_Start_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE ITrnMultiCaster_Stop_Proxy( 
    ITrnMultiCaster __RPC_FAR * This);


void __RPC_STUB ITrnMultiCaster_Stop_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE ITrnMultiCaster_QueryImageFormat_Proxy( 
    ITrnMultiCaster __RPC_FAR * This,
    /* [out][in] */ BITMAPINFOHEADER __RPC_FAR *pBmi,
    /* [out][in] */ EPlayFrameType __RPC_FAR *pFormat);


void __RPC_STUB ITrnMultiCaster_QueryImageFormat_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE ITrnMultiCaster_Advise_Proxy( 
    ITrnMultiCaster __RPC_FAR * This,
    /* [in] */ ITrnClipAdviseSink __RPC_FAR *pAdvise,
    /* [in] */ BYTE __RPC_FAR *__RPC_FAR *pClientBuffer,
    /* [out] */ SPlayBitMap __RPC_FAR *__RPC_FAR *ppClipSPlayBitMap,
    /* [out] */ BOOL __RPC_FAR *__RPC_FAR *ppbQueuedToSend);


void __RPC_STUB ITrnMultiCaster_Advise_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __ITrnMultiCaster_INTERFACE_DEFINED__ */


/* Additional Prototypes for ALL interfaces */

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif
