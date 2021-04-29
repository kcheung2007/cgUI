/* this ALWAYS GENERATED file contains the definitions for the interfaces */


/* File created by MIDL compiler version 3.01.75 */
/* at Tue Nov 23 05:02:10 1999
 */
/* Compiler settings for pcbitmap.idl:
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

#ifndef __pcbitmap_h__
#define __pcbitmap_h__

#ifdef __cplusplus
extern "C"{
#endif 

/* Forward Declarations */ 

#ifndef __IPlayCompressedBitmap_FWD_DEFINED__
#define __IPlayCompressedBitmap_FWD_DEFINED__
typedef interface IPlayCompressedBitmap IPlayCompressedBitmap;
#endif 	/* __IPlayCompressedBitmap_FWD_DEFINED__ */


/* header files for imported files */
#include "gxlate.h"

void __RPC_FAR * __RPC_USER MIDL_user_allocate(size_t);
void __RPC_USER MIDL_user_free( void __RPC_FAR * ); 

#ifndef __IPlayCompressedBitmap_INTERFACE_DEFINED__
#define __IPlayCompressedBitmap_INTERFACE_DEFINED__

/****************************************
 * Generated header for interface: IPlayCompressedBitmap
 * at Tue Nov 23 05:02:10 1999
 * using MIDL 3.01.75
 ****************************************/
/* [uuid][object][local] */ 



EXTERN_C const IID IID_IPlayCompressedBitmap;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    interface DECLSPEC_UUID("8335e435-ab3b-11ce-8468-0000b468276b")
    IPlayCompressedBitmap : public IUnknown
    {
    public:
        virtual DWORD STDMETHODCALLTYPE QuerySupportedFrameTypes( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Compress( 
            IGXIntBitmap __RPC_FAR *pIBM) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Decompress( 
            IGXIntBitmap __RPC_FAR *__RPC_FAR *ppIBM) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE DoComposite( 
            SPlayBitMap __RPC_FAR *pSPBMDest,
            LONG dx,
            LONG dy,
            LONG sx,
            LONG sy,
            LONG cw,
            LONG ch,
            DWORD dwColor) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE QueryInfo( 
            LONG __RPC_FAR *plWidth,
            LONG __RPC_FAR *plHeight,
            EPlayFrameType __RPC_FAR *peType) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IPlayCompressedBitmapVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            IPlayCompressedBitmap __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            IPlayCompressedBitmap __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            IPlayCompressedBitmap __RPC_FAR * This);
        
        DWORD ( STDMETHODCALLTYPE __RPC_FAR *QuerySupportedFrameTypes )( 
            IPlayCompressedBitmap __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Compress )( 
            IPlayCompressedBitmap __RPC_FAR * This,
            IGXIntBitmap __RPC_FAR *pIBM);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Decompress )( 
            IPlayCompressedBitmap __RPC_FAR * This,
            IGXIntBitmap __RPC_FAR *__RPC_FAR *ppIBM);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *DoComposite )( 
            IPlayCompressedBitmap __RPC_FAR * This,
            SPlayBitMap __RPC_FAR *pSPBMDest,
            LONG dx,
            LONG dy,
            LONG sx,
            LONG sy,
            LONG cw,
            LONG ch,
            DWORD dwColor);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInfo )( 
            IPlayCompressedBitmap __RPC_FAR * This,
            LONG __RPC_FAR *plWidth,
            LONG __RPC_FAR *plHeight,
            EPlayFrameType __RPC_FAR *peType);
        
        END_INTERFACE
    } IPlayCompressedBitmapVtbl;

    interface IPlayCompressedBitmap
    {
        CONST_VTBL struct IPlayCompressedBitmapVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IPlayCompressedBitmap_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IPlayCompressedBitmap_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IPlayCompressedBitmap_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IPlayCompressedBitmap_QuerySupportedFrameTypes(This)	\
    (This)->lpVtbl -> QuerySupportedFrameTypes(This)

#define IPlayCompressedBitmap_Compress(This,pIBM)	\
    (This)->lpVtbl -> Compress(This,pIBM)

#define IPlayCompressedBitmap_Decompress(This,ppIBM)	\
    (This)->lpVtbl -> Decompress(This,ppIBM)

#define IPlayCompressedBitmap_DoComposite(This,pSPBMDest,dx,dy,sx,sy,cw,ch,dwColor)	\
    (This)->lpVtbl -> DoComposite(This,pSPBMDest,dx,dy,sx,sy,cw,ch,dwColor)

#define IPlayCompressedBitmap_QueryInfo(This,plWidth,plHeight,peType)	\
    (This)->lpVtbl -> QueryInfo(This,plWidth,plHeight,peType)

#endif /* COBJMACROS */


#endif 	/* C style interface */



DWORD STDMETHODCALLTYPE IPlayCompressedBitmap_QuerySupportedFrameTypes_Proxy( 
    IPlayCompressedBitmap __RPC_FAR * This);


void __RPC_STUB IPlayCompressedBitmap_QuerySupportedFrameTypes_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IPlayCompressedBitmap_Compress_Proxy( 
    IPlayCompressedBitmap __RPC_FAR * This,
    IGXIntBitmap __RPC_FAR *pIBM);


void __RPC_STUB IPlayCompressedBitmap_Compress_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IPlayCompressedBitmap_Decompress_Proxy( 
    IPlayCompressedBitmap __RPC_FAR * This,
    IGXIntBitmap __RPC_FAR *__RPC_FAR *ppIBM);


void __RPC_STUB IPlayCompressedBitmap_Decompress_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IPlayCompressedBitmap_DoComposite_Proxy( 
    IPlayCompressedBitmap __RPC_FAR * This,
    SPlayBitMap __RPC_FAR *pSPBMDest,
    LONG dx,
    LONG dy,
    LONG sx,
    LONG sy,
    LONG cw,
    LONG ch,
    DWORD dwColor);


void __RPC_STUB IPlayCompressedBitmap_DoComposite_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IPlayCompressedBitmap_QueryInfo_Proxy( 
    IPlayCompressedBitmap __RPC_FAR * This,
    LONG __RPC_FAR *plWidth,
    LONG __RPC_FAR *plHeight,
    EPlayFrameType __RPC_FAR *peType);


void __RPC_STUB IPlayCompressedBitmap_QueryInfo_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IPlayCompressedBitmap_INTERFACE_DEFINED__ */


/* Additional Prototypes for ALL interfaces */

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif
