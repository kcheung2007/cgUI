/* this ALWAYS GENERATED file contains the definitions for the interfaces */


/* File created by MIDL compiler version 3.01.75 */
/* at Tue Nov 23 05:02:10 1999
 */
/* Compiler settings for bitmaplib.idl:
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

#ifndef __bitmaplib_h__
#define __bitmaplib_h__

#ifdef __cplusplus
extern "C"{
#endif 

/* Forward Declarations */ 

#ifndef __IPlayBitmapLibrary_FWD_DEFINED__
#define __IPlayBitmapLibrary_FWD_DEFINED__
typedef interface IPlayBitmapLibrary IPlayBitmapLibrary;
#endif 	/* __IPlayBitmapLibrary_FWD_DEFINED__ */


/* header files for imported files */
#include "unknwn.h"
#include "gxlate.h"
#include "pcbitmap.h"

void __RPC_FAR * __RPC_USER MIDL_user_allocate(size_t);
void __RPC_USER MIDL_user_free( void __RPC_FAR * ); 

#ifndef __IPlayBitmapLibrary_INTERFACE_DEFINED__
#define __IPlayBitmapLibrary_INTERFACE_DEFINED__

/****************************************
 * Generated header for interface: IPlayBitmapLibrary
 * at Tue Nov 23 05:02:10 1999
 * using MIDL 3.01.75
 ****************************************/
/* [uuid][object][local] */ 



EXTERN_C const IID IID_IPlayBitmapLibrary;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    interface DECLSPEC_UUID("8335e434-ab3b-11ce-8468-0000b468276b")
    IPlayBitmapLibrary : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE GetBitmap( 
            LPSTR pszFilename,
            IGXIntBitmap __RPC_FAR *__RPC_FAR *ppBitmap,
            IPlayCompressedBitmap __RPC_FAR *__RPC_FAR *ppPCBM) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE AddRefBitmap( 
            LPSTR pszFilename) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE ReleaseBitmap( 
            LPSTR pszFilename) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE RefreshBitmap( 
            LPSTR pszFilename) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetSequenceBitmap( 
            LPSTR pszDirName,
            LONG index,
            IPlayCompressedBitmap __RPC_FAR *__RPC_FAR *ppPCBM) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE QuerySequenceLength( 
            LPSTR pszDirName,
            LONG __RPC_FAR *pLength) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE AddRefSequence( 
            LPSTR pszDirName) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE ReleaseSequence( 
            LPSTR pszDirName) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE RefreshSequence( 
            LPSTR pszDirName) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IPlayBitmapLibraryVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            IPlayBitmapLibrary __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            IPlayBitmapLibrary __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            IPlayBitmapLibrary __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetBitmap )( 
            IPlayBitmapLibrary __RPC_FAR * This,
            LPSTR pszFilename,
            IGXIntBitmap __RPC_FAR *__RPC_FAR *ppBitmap,
            IPlayCompressedBitmap __RPC_FAR *__RPC_FAR *ppPCBM);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *AddRefBitmap )( 
            IPlayBitmapLibrary __RPC_FAR * This,
            LPSTR pszFilename);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *ReleaseBitmap )( 
            IPlayBitmapLibrary __RPC_FAR * This,
            LPSTR pszFilename);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *RefreshBitmap )( 
            IPlayBitmapLibrary __RPC_FAR * This,
            LPSTR pszFilename);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetSequenceBitmap )( 
            IPlayBitmapLibrary __RPC_FAR * This,
            LPSTR pszDirName,
            LONG index,
            IPlayCompressedBitmap __RPC_FAR *__RPC_FAR *ppPCBM);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QuerySequenceLength )( 
            IPlayBitmapLibrary __RPC_FAR * This,
            LPSTR pszDirName,
            LONG __RPC_FAR *pLength);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *AddRefSequence )( 
            IPlayBitmapLibrary __RPC_FAR * This,
            LPSTR pszDirName);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *ReleaseSequence )( 
            IPlayBitmapLibrary __RPC_FAR * This,
            LPSTR pszDirName);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *RefreshSequence )( 
            IPlayBitmapLibrary __RPC_FAR * This,
            LPSTR pszDirName);
        
        END_INTERFACE
    } IPlayBitmapLibraryVtbl;

    interface IPlayBitmapLibrary
    {
        CONST_VTBL struct IPlayBitmapLibraryVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IPlayBitmapLibrary_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IPlayBitmapLibrary_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IPlayBitmapLibrary_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IPlayBitmapLibrary_GetBitmap(This,pszFilename,ppBitmap,ppPCBM)	\
    (This)->lpVtbl -> GetBitmap(This,pszFilename,ppBitmap,ppPCBM)

#define IPlayBitmapLibrary_AddRefBitmap(This,pszFilename)	\
    (This)->lpVtbl -> AddRefBitmap(This,pszFilename)

#define IPlayBitmapLibrary_ReleaseBitmap(This,pszFilename)	\
    (This)->lpVtbl -> ReleaseBitmap(This,pszFilename)

#define IPlayBitmapLibrary_RefreshBitmap(This,pszFilename)	\
    (This)->lpVtbl -> RefreshBitmap(This,pszFilename)

#define IPlayBitmapLibrary_GetSequenceBitmap(This,pszDirName,index,ppPCBM)	\
    (This)->lpVtbl -> GetSequenceBitmap(This,pszDirName,index,ppPCBM)

#define IPlayBitmapLibrary_QuerySequenceLength(This,pszDirName,pLength)	\
    (This)->lpVtbl -> QuerySequenceLength(This,pszDirName,pLength)

#define IPlayBitmapLibrary_AddRefSequence(This,pszDirName)	\
    (This)->lpVtbl -> AddRefSequence(This,pszDirName)

#define IPlayBitmapLibrary_ReleaseSequence(This,pszDirName)	\
    (This)->lpVtbl -> ReleaseSequence(This,pszDirName)

#define IPlayBitmapLibrary_RefreshSequence(This,pszDirName)	\
    (This)->lpVtbl -> RefreshSequence(This,pszDirName)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE IPlayBitmapLibrary_GetBitmap_Proxy( 
    IPlayBitmapLibrary __RPC_FAR * This,
    LPSTR pszFilename,
    IGXIntBitmap __RPC_FAR *__RPC_FAR *ppBitmap,
    IPlayCompressedBitmap __RPC_FAR *__RPC_FAR *ppPCBM);


void __RPC_STUB IPlayBitmapLibrary_GetBitmap_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IPlayBitmapLibrary_AddRefBitmap_Proxy( 
    IPlayBitmapLibrary __RPC_FAR * This,
    LPSTR pszFilename);


void __RPC_STUB IPlayBitmapLibrary_AddRefBitmap_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IPlayBitmapLibrary_ReleaseBitmap_Proxy( 
    IPlayBitmapLibrary __RPC_FAR * This,
    LPSTR pszFilename);


void __RPC_STUB IPlayBitmapLibrary_ReleaseBitmap_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IPlayBitmapLibrary_RefreshBitmap_Proxy( 
    IPlayBitmapLibrary __RPC_FAR * This,
    LPSTR pszFilename);


void __RPC_STUB IPlayBitmapLibrary_RefreshBitmap_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IPlayBitmapLibrary_GetSequenceBitmap_Proxy( 
    IPlayBitmapLibrary __RPC_FAR * This,
    LPSTR pszDirName,
    LONG index,
    IPlayCompressedBitmap __RPC_FAR *__RPC_FAR *ppPCBM);


void __RPC_STUB IPlayBitmapLibrary_GetSequenceBitmap_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IPlayBitmapLibrary_QuerySequenceLength_Proxy( 
    IPlayBitmapLibrary __RPC_FAR * This,
    LPSTR pszDirName,
    LONG __RPC_FAR *pLength);


void __RPC_STUB IPlayBitmapLibrary_QuerySequenceLength_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IPlayBitmapLibrary_AddRefSequence_Proxy( 
    IPlayBitmapLibrary __RPC_FAR * This,
    LPSTR pszDirName);


void __RPC_STUB IPlayBitmapLibrary_AddRefSequence_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IPlayBitmapLibrary_ReleaseSequence_Proxy( 
    IPlayBitmapLibrary __RPC_FAR * This,
    LPSTR pszDirName);


void __RPC_STUB IPlayBitmapLibrary_ReleaseSequence_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IPlayBitmapLibrary_RefreshSequence_Proxy( 
    IPlayBitmapLibrary __RPC_FAR * This,
    LPSTR pszDirName);


void __RPC_STUB IPlayBitmapLibrary_RefreshSequence_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IPlayBitmapLibrary_INTERFACE_DEFINED__ */


/* Additional Prototypes for ALL interfaces */

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif
