/* this ALWAYS GENERATED file contains the definitions for the interfaces */


/* File created by MIDL compiler version 3.01.75 */
/* at Tue Nov 23 05:02:11 1999
 */
/* Compiler settings for picons.idl:
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

#ifndef __picons_h__
#define __picons_h__

#ifdef __cplusplus
extern "C"{
#endif 

/* Forward Declarations */ 

#ifndef __IGXStorageUtils_FWD_DEFINED__
#define __IGXStorageUtils_FWD_DEFINED__
typedef interface IGXStorageUtils IGXStorageUtils;
#endif 	/* __IGXStorageUtils_FWD_DEFINED__ */


/* header files for imported files */
#include "gxlate.h"

void __RPC_FAR * __RPC_USER MIDL_user_allocate(size_t);
void __RPC_USER MIDL_user_free( void __RPC_FAR * ); 

/****************************************
 * Generated header for interface: __MIDL_itf_picons_0000
 * at Tue Nov 23 05:02:11 1999
 * using MIDL 3.01.75
 ****************************************/
/* [local] */ 


typedef 
enum tagPiconOpt
    {	NoOpt	= 0,
	AddSprockets	= 0x1
    }	PiconOpt;

typedef 
enum tagPiconSize
    {	Picon_20x15	= 0x1,
	Picon_32x24	= 0x2,
	Picon_64x48	= 0x4,
	Picon_96x72	= 0x8,
	Picon_128x96	= 0x10
    }	PiconSize;



extern RPC_IF_HANDLE __MIDL_itf_picons_0000_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_picons_0000_v0_0_s_ifspec;

#ifndef __IGXStorageUtils_INTERFACE_DEFINED__
#define __IGXStorageUtils_INTERFACE_DEFINED__

/****************************************
 * Generated header for interface: IGXStorageUtils
 * at Tue Nov 23 05:02:11 1999
 * using MIDL 3.01.75
 ****************************************/
/* [local][uuid][object] */ 



EXTERN_C const IID IID_IGXStorageUtils;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    interface DECLSPEC_UUID("8335e6c7-ab3b-11ce-8468-0000b468276b")
    IGXStorageUtils : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE SavePiconToStorage( 
            /* [in] */ IStorage __RPC_FAR *Stg,
            /* [in] */ IGXIntBitmap2 __RPC_FAR *pIBmp,
            /* [in] */ PiconOpt Opt) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SavePiconToFile( 
            /* [in] */ LPTSTR FileName,
            /* [in] */ IGXIntBitmap2 __RPC_FAR *pIBmp,
            /* [in] */ PiconOpt Opt) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE LoadPiconFromStorage( 
            /* [in] */ IStorage __RPC_FAR *Stg,
            /* [in] */ PiconSize PSize,
            /* [out] */ IGXIntBitmap2 __RPC_FAR *__RPC_FAR *pIBmp) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE LoadPiconFromFile( 
            /* [in] */ LPTSTR FileName,
            /* [in] */ PiconSize PSize,
            /* [out] */ IGXIntBitmap2 __RPC_FAR *__RPC_FAR *pIBmp) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetPiconSizeDimensions( 
            /* [in] */ PiconSize PSize,
            /* [out] */ DWORD __RPC_FAR *Width,
            /* [out] */ DWORD __RPC_FAR *Height) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE AddOverlay( 
            IGXIntBitmap2 __RPC_FAR *pBmpIn,
            IGXIntBitmap2 __RPC_FAR *__RPC_FAR *pBmpOut,
            PiconOpt Opt,
            PiconSize PSize) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IGXStorageUtilsVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            IGXStorageUtils __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            IGXStorageUtils __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            IGXStorageUtils __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SavePiconToStorage )( 
            IGXStorageUtils __RPC_FAR * This,
            /* [in] */ IStorage __RPC_FAR *Stg,
            /* [in] */ IGXIntBitmap2 __RPC_FAR *pIBmp,
            /* [in] */ PiconOpt Opt);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SavePiconToFile )( 
            IGXStorageUtils __RPC_FAR * This,
            /* [in] */ LPTSTR FileName,
            /* [in] */ IGXIntBitmap2 __RPC_FAR *pIBmp,
            /* [in] */ PiconOpt Opt);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *LoadPiconFromStorage )( 
            IGXStorageUtils __RPC_FAR * This,
            /* [in] */ IStorage __RPC_FAR *Stg,
            /* [in] */ PiconSize PSize,
            /* [out] */ IGXIntBitmap2 __RPC_FAR *__RPC_FAR *pIBmp);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *LoadPiconFromFile )( 
            IGXStorageUtils __RPC_FAR * This,
            /* [in] */ LPTSTR FileName,
            /* [in] */ PiconSize PSize,
            /* [out] */ IGXIntBitmap2 __RPC_FAR *__RPC_FAR *pIBmp);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetPiconSizeDimensions )( 
            IGXStorageUtils __RPC_FAR * This,
            /* [in] */ PiconSize PSize,
            /* [out] */ DWORD __RPC_FAR *Width,
            /* [out] */ DWORD __RPC_FAR *Height);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *AddOverlay )( 
            IGXStorageUtils __RPC_FAR * This,
            IGXIntBitmap2 __RPC_FAR *pBmpIn,
            IGXIntBitmap2 __RPC_FAR *__RPC_FAR *pBmpOut,
            PiconOpt Opt,
            PiconSize PSize);
        
        END_INTERFACE
    } IGXStorageUtilsVtbl;

    interface IGXStorageUtils
    {
        CONST_VTBL struct IGXStorageUtilsVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IGXStorageUtils_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IGXStorageUtils_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IGXStorageUtils_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IGXStorageUtils_SavePiconToStorage(This,Stg,pIBmp,Opt)	\
    (This)->lpVtbl -> SavePiconToStorage(This,Stg,pIBmp,Opt)

#define IGXStorageUtils_SavePiconToFile(This,FileName,pIBmp,Opt)	\
    (This)->lpVtbl -> SavePiconToFile(This,FileName,pIBmp,Opt)

#define IGXStorageUtils_LoadPiconFromStorage(This,Stg,PSize,pIBmp)	\
    (This)->lpVtbl -> LoadPiconFromStorage(This,Stg,PSize,pIBmp)

#define IGXStorageUtils_LoadPiconFromFile(This,FileName,PSize,pIBmp)	\
    (This)->lpVtbl -> LoadPiconFromFile(This,FileName,PSize,pIBmp)

#define IGXStorageUtils_GetPiconSizeDimensions(This,PSize,Width,Height)	\
    (This)->lpVtbl -> GetPiconSizeDimensions(This,PSize,Width,Height)

#define IGXStorageUtils_AddOverlay(This,pBmpIn,pBmpOut,Opt,PSize)	\
    (This)->lpVtbl -> AddOverlay(This,pBmpIn,pBmpOut,Opt,PSize)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE IGXStorageUtils_SavePiconToStorage_Proxy( 
    IGXStorageUtils __RPC_FAR * This,
    /* [in] */ IStorage __RPC_FAR *Stg,
    /* [in] */ IGXIntBitmap2 __RPC_FAR *pIBmp,
    /* [in] */ PiconOpt Opt);


void __RPC_STUB IGXStorageUtils_SavePiconToStorage_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IGXStorageUtils_SavePiconToFile_Proxy( 
    IGXStorageUtils __RPC_FAR * This,
    /* [in] */ LPTSTR FileName,
    /* [in] */ IGXIntBitmap2 __RPC_FAR *pIBmp,
    /* [in] */ PiconOpt Opt);


void __RPC_STUB IGXStorageUtils_SavePiconToFile_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IGXStorageUtils_LoadPiconFromStorage_Proxy( 
    IGXStorageUtils __RPC_FAR * This,
    /* [in] */ IStorage __RPC_FAR *Stg,
    /* [in] */ PiconSize PSize,
    /* [out] */ IGXIntBitmap2 __RPC_FAR *__RPC_FAR *pIBmp);


void __RPC_STUB IGXStorageUtils_LoadPiconFromStorage_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IGXStorageUtils_LoadPiconFromFile_Proxy( 
    IGXStorageUtils __RPC_FAR * This,
    /* [in] */ LPTSTR FileName,
    /* [in] */ PiconSize PSize,
    /* [out] */ IGXIntBitmap2 __RPC_FAR *__RPC_FAR *pIBmp);


void __RPC_STUB IGXStorageUtils_LoadPiconFromFile_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IGXStorageUtils_GetPiconSizeDimensions_Proxy( 
    IGXStorageUtils __RPC_FAR * This,
    /* [in] */ PiconSize PSize,
    /* [out] */ DWORD __RPC_FAR *Width,
    /* [out] */ DWORD __RPC_FAR *Height);


void __RPC_STUB IGXStorageUtils_GetPiconSizeDimensions_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IGXStorageUtils_AddOverlay_Proxy( 
    IGXStorageUtils __RPC_FAR * This,
    IGXIntBitmap2 __RPC_FAR *pBmpIn,
    IGXIntBitmap2 __RPC_FAR *__RPC_FAR *pBmpOut,
    PiconOpt Opt,
    PiconSize PSize);


void __RPC_STUB IGXStorageUtils_AddOverlay_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IGXStorageUtils_INTERFACE_DEFINED__ */


/* Additional Prototypes for ALL interfaces */

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif
