/* this ALWAYS GENERATED file contains the definitions for the interfaces */


/* File created by MIDL compiler version 3.01.75 */
/* at Tue Nov 23 05:02:15 1999
 */
/* Compiler settings for stdbg.idl:
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

#ifndef __stdbg_h__
#define __stdbg_h__

#ifdef __cplusplus
extern "C"{
#endif 

/* Forward Declarations */ 

#ifndef __IPlayStdBackground_FWD_DEFINED__
#define __IPlayStdBackground_FWD_DEFINED__
typedef interface IPlayStdBackground IPlayStdBackground;
#endif 	/* __IPlayStdBackground_FWD_DEFINED__ */


/* header files for imported files */
#include "unknwn.h"

void __RPC_FAR * __RPC_USER MIDL_user_allocate(size_t);
void __RPC_USER MIDL_user_free( void __RPC_FAR * ); 

#ifndef __IPlayStdBackground_INTERFACE_DEFINED__
#define __IPlayStdBackground_INTERFACE_DEFINED__

/****************************************
 * Generated header for interface: IPlayStdBackground
 * at Tue Nov 23 05:02:15 1999
 * using MIDL 3.01.75
 ****************************************/
/* [uuid][object][local] */ 



EXTERN_C const IID IID_IPlayStdBackground;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    interface DECLSPEC_UUID("8335e429-ab3b-11ce-8468-0000b468276b")
    IPlayStdBackground : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE IsStdSupported( 
            DWORD dwStdBitmapID) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetBitmapDescription( 
            DWORD dwStdBitmapID,
            LPSTR pszBuffer,
            DWORD dwMaxChars) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetBitmap( 
            DWORD dwStdBitmapID,
            LPVOID __RPC_FAR *ppBMIH,
            unsigned char __RPC_FAR *__RPC_FAR *ppBits) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IPlayStdBackgroundVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            IPlayStdBackground __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            IPlayStdBackground __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            IPlayStdBackground __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *IsStdSupported )( 
            IPlayStdBackground __RPC_FAR * This,
            DWORD dwStdBitmapID);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetBitmapDescription )( 
            IPlayStdBackground __RPC_FAR * This,
            DWORD dwStdBitmapID,
            LPSTR pszBuffer,
            DWORD dwMaxChars);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetBitmap )( 
            IPlayStdBackground __RPC_FAR * This,
            DWORD dwStdBitmapID,
            LPVOID __RPC_FAR *ppBMIH,
            unsigned char __RPC_FAR *__RPC_FAR *ppBits);
        
        END_INTERFACE
    } IPlayStdBackgroundVtbl;

    interface IPlayStdBackground
    {
        CONST_VTBL struct IPlayStdBackgroundVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IPlayStdBackground_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IPlayStdBackground_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IPlayStdBackground_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IPlayStdBackground_IsStdSupported(This,dwStdBitmapID)	\
    (This)->lpVtbl -> IsStdSupported(This,dwStdBitmapID)

#define IPlayStdBackground_GetBitmapDescription(This,dwStdBitmapID,pszBuffer,dwMaxChars)	\
    (This)->lpVtbl -> GetBitmapDescription(This,dwStdBitmapID,pszBuffer,dwMaxChars)

#define IPlayStdBackground_GetBitmap(This,dwStdBitmapID,ppBMIH,ppBits)	\
    (This)->lpVtbl -> GetBitmap(This,dwStdBitmapID,ppBMIH,ppBits)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE IPlayStdBackground_IsStdSupported_Proxy( 
    IPlayStdBackground __RPC_FAR * This,
    DWORD dwStdBitmapID);


void __RPC_STUB IPlayStdBackground_IsStdSupported_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IPlayStdBackground_GetBitmapDescription_Proxy( 
    IPlayStdBackground __RPC_FAR * This,
    DWORD dwStdBitmapID,
    LPSTR pszBuffer,
    DWORD dwMaxChars);


void __RPC_STUB IPlayStdBackground_GetBitmapDescription_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IPlayStdBackground_GetBitmap_Proxy( 
    IPlayStdBackground __RPC_FAR * This,
    DWORD dwStdBitmapID,
    LPVOID __RPC_FAR *ppBMIH,
    unsigned char __RPC_FAR *__RPC_FAR *ppBits);


void __RPC_STUB IPlayStdBackground_GetBitmap_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IPlayStdBackground_INTERFACE_DEFINED__ */


/* Additional Prototypes for ALL interfaces */

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif
