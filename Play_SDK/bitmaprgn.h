/* this ALWAYS GENERATED file contains the definitions for the interfaces */


/* File created by MIDL compiler version 3.01.75 */
/* at Tue Nov 23 05:02:09 1999
 */
/* Compiler settings for bitmaprgn.idl:
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

#ifndef __bitmaprgn_h__
#define __bitmaprgn_h__

#ifdef __cplusplus
extern "C"{
#endif 

/* Forward Declarations */ 

#ifndef __IPlayBitmapRegion_FWD_DEFINED__
#define __IPlayBitmapRegion_FWD_DEFINED__
typedef interface IPlayBitmapRegion IPlayBitmapRegion;
#endif 	/* __IPlayBitmapRegion_FWD_DEFINED__ */


/* header files for imported files */
#include "gxlate.h"

void __RPC_FAR * __RPC_USER MIDL_user_allocate(size_t);
void __RPC_USER MIDL_user_free( void __RPC_FAR * ); 

#ifndef __IPlayBitmapRegion_INTERFACE_DEFINED__
#define __IPlayBitmapRegion_INTERFACE_DEFINED__

/****************************************
 * Generated header for interface: IPlayBitmapRegion
 * at Tue Nov 23 05:02:09 1999
 * using MIDL 3.01.75
 ****************************************/
/* [uuid][object][local] */ 



EXTERN_C const IID IID_IPlayBitmapRegion;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    interface DECLSPEC_UUID("8335e436-ab3b-11ce-8468-0000b468276b")
    IPlayBitmapRegion : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE UseBitmap( 
            SPlayBitMap __RPC_FAR *pSPBM) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE UseRegionData( 
            LPVOID pRgnData) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE MakeRegion( 
            LPVOID pXform,
            HRGN __RPC_FAR *phRgn) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE MakeStretchedRegion( 
            LPVOID pXform,
            long w,
            long h,
            long stretchX,
            long stretchY,
            HRGN __RPC_FAR *phRgn) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetBoundingRect( 
            LPVOID pRect) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetOriginalSize( 
            long __RPC_FAR *plWidth,
            long __RPC_FAR *plHeight) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IPlayBitmapRegionVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            IPlayBitmapRegion __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            IPlayBitmapRegion __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            IPlayBitmapRegion __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *UseBitmap )( 
            IPlayBitmapRegion __RPC_FAR * This,
            SPlayBitMap __RPC_FAR *pSPBM);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *UseRegionData )( 
            IPlayBitmapRegion __RPC_FAR * This,
            LPVOID pRgnData);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *MakeRegion )( 
            IPlayBitmapRegion __RPC_FAR * This,
            LPVOID pXform,
            HRGN __RPC_FAR *phRgn);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *MakeStretchedRegion )( 
            IPlayBitmapRegion __RPC_FAR * This,
            LPVOID pXform,
            long w,
            long h,
            long stretchX,
            long stretchY,
            HRGN __RPC_FAR *phRgn);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetBoundingRect )( 
            IPlayBitmapRegion __RPC_FAR * This,
            LPVOID pRect);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetOriginalSize )( 
            IPlayBitmapRegion __RPC_FAR * This,
            long __RPC_FAR *plWidth,
            long __RPC_FAR *plHeight);
        
        END_INTERFACE
    } IPlayBitmapRegionVtbl;

    interface IPlayBitmapRegion
    {
        CONST_VTBL struct IPlayBitmapRegionVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IPlayBitmapRegion_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IPlayBitmapRegion_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IPlayBitmapRegion_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IPlayBitmapRegion_UseBitmap(This,pSPBM)	\
    (This)->lpVtbl -> UseBitmap(This,pSPBM)

#define IPlayBitmapRegion_UseRegionData(This,pRgnData)	\
    (This)->lpVtbl -> UseRegionData(This,pRgnData)

#define IPlayBitmapRegion_MakeRegion(This,pXform,phRgn)	\
    (This)->lpVtbl -> MakeRegion(This,pXform,phRgn)

#define IPlayBitmapRegion_MakeStretchedRegion(This,pXform,w,h,stretchX,stretchY,phRgn)	\
    (This)->lpVtbl -> MakeStretchedRegion(This,pXform,w,h,stretchX,stretchY,phRgn)

#define IPlayBitmapRegion_GetBoundingRect(This,pRect)	\
    (This)->lpVtbl -> GetBoundingRect(This,pRect)

#define IPlayBitmapRegion_GetOriginalSize(This,plWidth,plHeight)	\
    (This)->lpVtbl -> GetOriginalSize(This,plWidth,plHeight)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE IPlayBitmapRegion_UseBitmap_Proxy( 
    IPlayBitmapRegion __RPC_FAR * This,
    SPlayBitMap __RPC_FAR *pSPBM);


void __RPC_STUB IPlayBitmapRegion_UseBitmap_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IPlayBitmapRegion_UseRegionData_Proxy( 
    IPlayBitmapRegion __RPC_FAR * This,
    LPVOID pRgnData);


void __RPC_STUB IPlayBitmapRegion_UseRegionData_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IPlayBitmapRegion_MakeRegion_Proxy( 
    IPlayBitmapRegion __RPC_FAR * This,
    LPVOID pXform,
    HRGN __RPC_FAR *phRgn);


void __RPC_STUB IPlayBitmapRegion_MakeRegion_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IPlayBitmapRegion_MakeStretchedRegion_Proxy( 
    IPlayBitmapRegion __RPC_FAR * This,
    LPVOID pXform,
    long w,
    long h,
    long stretchX,
    long stretchY,
    HRGN __RPC_FAR *phRgn);


void __RPC_STUB IPlayBitmapRegion_MakeStretchedRegion_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IPlayBitmapRegion_GetBoundingRect_Proxy( 
    IPlayBitmapRegion __RPC_FAR * This,
    LPVOID pRect);


void __RPC_STUB IPlayBitmapRegion_GetBoundingRect_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IPlayBitmapRegion_GetOriginalSize_Proxy( 
    IPlayBitmapRegion __RPC_FAR * This,
    long __RPC_FAR *plWidth,
    long __RPC_FAR *plHeight);


void __RPC_STUB IPlayBitmapRegion_GetOriginalSize_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IPlayBitmapRegion_INTERFACE_DEFINED__ */


/* Additional Prototypes for ALL interfaces */

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif
