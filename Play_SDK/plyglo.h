/* this ALWAYS GENERATED file contains the definitions for the interfaces */


/* File created by MIDL compiler version 3.01.75 */
/* at Tue Nov 23 05:02:12 1999
 */
/* Compiler settings for plyglo.idl:
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

#ifndef __plyglo_h__
#define __plyglo_h__

#ifdef __cplusplus
extern "C"{
#endif 

/* Forward Declarations */ 

#ifndef __IPlayGlow_FWD_DEFINED__
#define __IPlayGlow_FWD_DEFINED__
typedef interface IPlayGlow IPlayGlow;
#endif 	/* __IPlayGlow_FWD_DEFINED__ */


/* header files for imported files */
#include "unknwn.h"
#include "gxlate.h"

void __RPC_FAR * __RPC_USER MIDL_user_allocate(size_t);
void __RPC_USER MIDL_user_free( void __RPC_FAR * ); 

#ifndef __IPlayGlow_INTERFACE_DEFINED__
#define __IPlayGlow_INTERFACE_DEFINED__

/****************************************
 * Generated header for interface: IPlayGlow
 * at Tue Nov 23 05:02:12 1999
 * using MIDL 3.01.75
 ****************************************/
/* [uuid][object][local] */ 



EXTERN_C const IID IID_IPlayGlow;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    interface DECLSPEC_UUID("8335e427-ab3b-11ce-8468-0000b468276b")
    IPlayGlow : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE SetSize( 
            /* [in] */ SIZE __RPC_FAR *psizeOuter,
            /* [in] */ ULONG lInner) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetSize( 
            /* [out] */ SIZE __RPC_FAR *psizeOuter,
            /* [out] */ ULONG __RPC_FAR *plInner) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetRect( 
            int dx,
            int dy,
            int w,
            int h,
            DWORD dwTrans) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE ForceGenerate( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetColor( 
            DWORD dwColor) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetTransparency( 
            DWORD dwTrans) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE DrawToDC( 
            HDC hDC,
            ULONG dx,
            ULONG dy) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE DrawToBitmap( 
            IGXIntBitmap __RPC_FAR *piBitmap,
            ULONG dx,
            ULONG dy) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE DrawToDIB( 
            LPVOID pBMIH,
            unsigned char __RPC_FAR *pBits,
            ULONG dx,
            ULONG dy) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE ReleaseMask( void) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IPlayGlowVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            IPlayGlow __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            IPlayGlow __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            IPlayGlow __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetSize )( 
            IPlayGlow __RPC_FAR * This,
            /* [in] */ SIZE __RPC_FAR *psizeOuter,
            /* [in] */ ULONG lInner);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetSize )( 
            IPlayGlow __RPC_FAR * This,
            /* [out] */ SIZE __RPC_FAR *psizeOuter,
            /* [out] */ ULONG __RPC_FAR *plInner);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetRect )( 
            IPlayGlow __RPC_FAR * This,
            int dx,
            int dy,
            int w,
            int h,
            DWORD dwTrans);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *ForceGenerate )( 
            IPlayGlow __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetColor )( 
            IPlayGlow __RPC_FAR * This,
            DWORD dwColor);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetTransparency )( 
            IPlayGlow __RPC_FAR * This,
            DWORD dwTrans);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *DrawToDC )( 
            IPlayGlow __RPC_FAR * This,
            HDC hDC,
            ULONG dx,
            ULONG dy);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *DrawToBitmap )( 
            IPlayGlow __RPC_FAR * This,
            IGXIntBitmap __RPC_FAR *piBitmap,
            ULONG dx,
            ULONG dy);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *DrawToDIB )( 
            IPlayGlow __RPC_FAR * This,
            LPVOID pBMIH,
            unsigned char __RPC_FAR *pBits,
            ULONG dx,
            ULONG dy);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *ReleaseMask )( 
            IPlayGlow __RPC_FAR * This);
        
        END_INTERFACE
    } IPlayGlowVtbl;

    interface IPlayGlow
    {
        CONST_VTBL struct IPlayGlowVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IPlayGlow_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IPlayGlow_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IPlayGlow_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IPlayGlow_SetSize(This,psizeOuter,lInner)	\
    (This)->lpVtbl -> SetSize(This,psizeOuter,lInner)

#define IPlayGlow_GetSize(This,psizeOuter,plInner)	\
    (This)->lpVtbl -> GetSize(This,psizeOuter,plInner)

#define IPlayGlow_SetRect(This,dx,dy,w,h,dwTrans)	\
    (This)->lpVtbl -> SetRect(This,dx,dy,w,h,dwTrans)

#define IPlayGlow_ForceGenerate(This)	\
    (This)->lpVtbl -> ForceGenerate(This)

#define IPlayGlow_SetColor(This,dwColor)	\
    (This)->lpVtbl -> SetColor(This,dwColor)

#define IPlayGlow_SetTransparency(This,dwTrans)	\
    (This)->lpVtbl -> SetTransparency(This,dwTrans)

#define IPlayGlow_DrawToDC(This,hDC,dx,dy)	\
    (This)->lpVtbl -> DrawToDC(This,hDC,dx,dy)

#define IPlayGlow_DrawToBitmap(This,piBitmap,dx,dy)	\
    (This)->lpVtbl -> DrawToBitmap(This,piBitmap,dx,dy)

#define IPlayGlow_DrawToDIB(This,pBMIH,pBits,dx,dy)	\
    (This)->lpVtbl -> DrawToDIB(This,pBMIH,pBits,dx,dy)

#define IPlayGlow_ReleaseMask(This)	\
    (This)->lpVtbl -> ReleaseMask(This)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE IPlayGlow_SetSize_Proxy( 
    IPlayGlow __RPC_FAR * This,
    /* [in] */ SIZE __RPC_FAR *psizeOuter,
    /* [in] */ ULONG lInner);


void __RPC_STUB IPlayGlow_SetSize_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IPlayGlow_GetSize_Proxy( 
    IPlayGlow __RPC_FAR * This,
    /* [out] */ SIZE __RPC_FAR *psizeOuter,
    /* [out] */ ULONG __RPC_FAR *plInner);


void __RPC_STUB IPlayGlow_GetSize_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IPlayGlow_SetRect_Proxy( 
    IPlayGlow __RPC_FAR * This,
    int dx,
    int dy,
    int w,
    int h,
    DWORD dwTrans);


void __RPC_STUB IPlayGlow_SetRect_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IPlayGlow_ForceGenerate_Proxy( 
    IPlayGlow __RPC_FAR * This);


void __RPC_STUB IPlayGlow_ForceGenerate_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IPlayGlow_SetColor_Proxy( 
    IPlayGlow __RPC_FAR * This,
    DWORD dwColor);


void __RPC_STUB IPlayGlow_SetColor_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IPlayGlow_SetTransparency_Proxy( 
    IPlayGlow __RPC_FAR * This,
    DWORD dwTrans);


void __RPC_STUB IPlayGlow_SetTransparency_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IPlayGlow_DrawToDC_Proxy( 
    IPlayGlow __RPC_FAR * This,
    HDC hDC,
    ULONG dx,
    ULONG dy);


void __RPC_STUB IPlayGlow_DrawToDC_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IPlayGlow_DrawToBitmap_Proxy( 
    IPlayGlow __RPC_FAR * This,
    IGXIntBitmap __RPC_FAR *piBitmap,
    ULONG dx,
    ULONG dy);


void __RPC_STUB IPlayGlow_DrawToBitmap_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IPlayGlow_DrawToDIB_Proxy( 
    IPlayGlow __RPC_FAR * This,
    LPVOID pBMIH,
    unsigned char __RPC_FAR *pBits,
    ULONG dx,
    ULONG dy);


void __RPC_STUB IPlayGlow_DrawToDIB_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IPlayGlow_ReleaseMask_Proxy( 
    IPlayGlow __RPC_FAR * This);


void __RPC_STUB IPlayGlow_ReleaseMask_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IPlayGlow_INTERFACE_DEFINED__ */


/* Additional Prototypes for ALL interfaces */

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif
