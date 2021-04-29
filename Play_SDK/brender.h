/* this ALWAYS GENERATED file contains the definitions for the interfaces */


/* File created by MIDL compiler version 3.01.75 */
/* at Tue Nov 23 05:02:07 1999
 */
/* Compiler settings for brender.idl:
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

#ifndef __brender_h__
#define __brender_h__

#ifdef __cplusplus
extern "C"{
#endif 

/* Forward Declarations */ 

#ifndef __IBumpMapScene_FWD_DEFINED__
#define __IBumpMapScene_FWD_DEFINED__
typedef interface IBumpMapScene IBumpMapScene;
#endif 	/* __IBumpMapScene_FWD_DEFINED__ */


#ifndef __IBumpMapRenderer_FWD_DEFINED__
#define __IBumpMapRenderer_FWD_DEFINED__
typedef interface IBumpMapRenderer IBumpMapRenderer;
#endif 	/* __IBumpMapRenderer_FWD_DEFINED__ */


#ifndef __IBumpMapRenderer2_FWD_DEFINED__
#define __IBumpMapRenderer2_FWD_DEFINED__
typedef interface IBumpMapRenderer2 IBumpMapRenderer2;
#endif 	/* __IBumpMapRenderer2_FWD_DEFINED__ */


/* header files for imported files */
#include "unknwn.h"

void __RPC_FAR * __RPC_USER MIDL_user_allocate(size_t);
void __RPC_USER MIDL_user_free( void __RPC_FAR * ); 

/****************************************
 * Generated header for interface: __MIDL_itf_brender_0000
 * at Tue Nov 23 05:02:07 1999
 * using MIDL 3.01.75
 ****************************************/
/* [local] */ 


extern const CLSID CLSID_CBumpMapScene;
#define DECLARE_CLSID_CBUMPMAPSCENE \
   const CLSID CLSID_CBumpMapScene = { 0xc500597b,0xab3b,0x11ce,{0x84,0x68,0x00,0x00,0xb4,0x68,0x27,0x6b} }
extern const CLSID CLSID_CBumpMapRenderer;
#define DECLARE_CLSID_CBUMPMAPRENDERER \
   const CLSID CLSID_CBumpMapRenderer = { 0xc500597c,0xab3b,0x11ce,{0x84,0x68,0x00,0x00,0xb4,0x68,0x27,0x6b} } 
extern const IID IID_IBumpMapScene;
#define DECLARE_IID_IBUMPMAPSCENE \
   const CLSID IID_IBumpMapScene = { 0x8335e618,0xab3b,0x11ce,{0x84,0x68,0x00,0x00,0xb4,0x68,0x27,0x6b} }
extern const IID IID_IBumpMapRenderer;
#define DECLARE_IID_IBUMPMAPRENDERER \
   const CLSID IID_IBumpMapRenderer = { 0x8335e619,0xab3b,0x11ce,{0x84,0x68,0x00,0x00,0xb4,0x68,0x27,0x6b} }


extern RPC_IF_HANDLE __MIDL_itf_brender_0000_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_brender_0000_v0_0_s_ifspec;

#ifndef __IBumpMapScene_INTERFACE_DEFINED__
#define __IBumpMapScene_INTERFACE_DEFINED__

/****************************************
 * Generated header for interface: IBumpMapScene
 * at Tue Nov 23 05:02:07 1999
 * using MIDL 3.01.75
 ****************************************/
/* [uuid][object][local] */ 



EXTERN_C const IID IID_IBumpMapScene;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    interface DECLSPEC_UUID("8335e618-ab3b-11ce-8468-0000b468276b")
    IBumpMapScene : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE SetSize( 
            long w,
            long h) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE MakeEllipsoid( 
            long dx,
            long dy,
            long w,
            long h) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE MakeHCylinder( 
            long dx,
            long dy,
            long w,
            long h) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE MakeRoundRect( 
            long dx,
            long dy,
            long w,
            long h,
            long edge) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE MakeRoundRectDip( 
            long dx,
            long dy,
            long w,
            long h,
            long edge,
            long bottom) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE MakeFlatDip( 
            long dx,
            long dy,
            long w,
            long h,
            long edge,
            long bottom) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE MakeRaisedRect( 
            long dx,
            long dy,
            long w,
            long h,
            long edge,
            long top) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE MakeFlatRect( 
            long dx,
            long dy,
            long w,
            long h) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE RoughenRect( 
            long dx,
            long dy,
            long w,
            long h,
            long rough) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE BrushedRect( 
            long dx,
            long dy,
            long w,
            long h,
            long rough) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE ClearRect( 
            long dx,
            long dy,
            long w,
            long h) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE HorizRipple( 
            long dx,
            long dy,
            long w,
            long h,
            long ampl,
            long periods) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE RippleEllipse( 
            long dx,
            long dy,
            long w,
            long h,
            long periods,
            long ampl) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE MakeEllipseDent( 
            long dx,
            long dy,
            long w,
            long h,
            long edge) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE MakeVBelt( 
            long dx,
            long dy,
            long w,
            long h,
            long edge,
            long bottom) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IBumpMapSceneVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            IBumpMapScene __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            IBumpMapScene __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            IBumpMapScene __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetSize )( 
            IBumpMapScene __RPC_FAR * This,
            long w,
            long h);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *MakeEllipsoid )( 
            IBumpMapScene __RPC_FAR * This,
            long dx,
            long dy,
            long w,
            long h);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *MakeHCylinder )( 
            IBumpMapScene __RPC_FAR * This,
            long dx,
            long dy,
            long w,
            long h);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *MakeRoundRect )( 
            IBumpMapScene __RPC_FAR * This,
            long dx,
            long dy,
            long w,
            long h,
            long edge);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *MakeRoundRectDip )( 
            IBumpMapScene __RPC_FAR * This,
            long dx,
            long dy,
            long w,
            long h,
            long edge,
            long bottom);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *MakeFlatDip )( 
            IBumpMapScene __RPC_FAR * This,
            long dx,
            long dy,
            long w,
            long h,
            long edge,
            long bottom);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *MakeRaisedRect )( 
            IBumpMapScene __RPC_FAR * This,
            long dx,
            long dy,
            long w,
            long h,
            long edge,
            long top);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *MakeFlatRect )( 
            IBumpMapScene __RPC_FAR * This,
            long dx,
            long dy,
            long w,
            long h);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *RoughenRect )( 
            IBumpMapScene __RPC_FAR * This,
            long dx,
            long dy,
            long w,
            long h,
            long rough);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *BrushedRect )( 
            IBumpMapScene __RPC_FAR * This,
            long dx,
            long dy,
            long w,
            long h,
            long rough);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *ClearRect )( 
            IBumpMapScene __RPC_FAR * This,
            long dx,
            long dy,
            long w,
            long h);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *HorizRipple )( 
            IBumpMapScene __RPC_FAR * This,
            long dx,
            long dy,
            long w,
            long h,
            long ampl,
            long periods);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *RippleEllipse )( 
            IBumpMapScene __RPC_FAR * This,
            long dx,
            long dy,
            long w,
            long h,
            long periods,
            long ampl);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *MakeEllipseDent )( 
            IBumpMapScene __RPC_FAR * This,
            long dx,
            long dy,
            long w,
            long h,
            long edge);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *MakeVBelt )( 
            IBumpMapScene __RPC_FAR * This,
            long dx,
            long dy,
            long w,
            long h,
            long edge,
            long bottom);
        
        END_INTERFACE
    } IBumpMapSceneVtbl;

    interface IBumpMapScene
    {
        CONST_VTBL struct IBumpMapSceneVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IBumpMapScene_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IBumpMapScene_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IBumpMapScene_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IBumpMapScene_SetSize(This,w,h)	\
    (This)->lpVtbl -> SetSize(This,w,h)

#define IBumpMapScene_MakeEllipsoid(This,dx,dy,w,h)	\
    (This)->lpVtbl -> MakeEllipsoid(This,dx,dy,w,h)

#define IBumpMapScene_MakeHCylinder(This,dx,dy,w,h)	\
    (This)->lpVtbl -> MakeHCylinder(This,dx,dy,w,h)

#define IBumpMapScene_MakeRoundRect(This,dx,dy,w,h,edge)	\
    (This)->lpVtbl -> MakeRoundRect(This,dx,dy,w,h,edge)

#define IBumpMapScene_MakeRoundRectDip(This,dx,dy,w,h,edge,bottom)	\
    (This)->lpVtbl -> MakeRoundRectDip(This,dx,dy,w,h,edge,bottom)

#define IBumpMapScene_MakeFlatDip(This,dx,dy,w,h,edge,bottom)	\
    (This)->lpVtbl -> MakeFlatDip(This,dx,dy,w,h,edge,bottom)

#define IBumpMapScene_MakeRaisedRect(This,dx,dy,w,h,edge,top)	\
    (This)->lpVtbl -> MakeRaisedRect(This,dx,dy,w,h,edge,top)

#define IBumpMapScene_MakeFlatRect(This,dx,dy,w,h)	\
    (This)->lpVtbl -> MakeFlatRect(This,dx,dy,w,h)

#define IBumpMapScene_RoughenRect(This,dx,dy,w,h,rough)	\
    (This)->lpVtbl -> RoughenRect(This,dx,dy,w,h,rough)

#define IBumpMapScene_BrushedRect(This,dx,dy,w,h,rough)	\
    (This)->lpVtbl -> BrushedRect(This,dx,dy,w,h,rough)

#define IBumpMapScene_ClearRect(This,dx,dy,w,h)	\
    (This)->lpVtbl -> ClearRect(This,dx,dy,w,h)

#define IBumpMapScene_HorizRipple(This,dx,dy,w,h,ampl,periods)	\
    (This)->lpVtbl -> HorizRipple(This,dx,dy,w,h,ampl,periods)

#define IBumpMapScene_RippleEllipse(This,dx,dy,w,h,periods,ampl)	\
    (This)->lpVtbl -> RippleEllipse(This,dx,dy,w,h,periods,ampl)

#define IBumpMapScene_MakeEllipseDent(This,dx,dy,w,h,edge)	\
    (This)->lpVtbl -> MakeEllipseDent(This,dx,dy,w,h,edge)

#define IBumpMapScene_MakeVBelt(This,dx,dy,w,h,edge,bottom)	\
    (This)->lpVtbl -> MakeVBelt(This,dx,dy,w,h,edge,bottom)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE IBumpMapScene_SetSize_Proxy( 
    IBumpMapScene __RPC_FAR * This,
    long w,
    long h);


void __RPC_STUB IBumpMapScene_SetSize_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IBumpMapScene_MakeEllipsoid_Proxy( 
    IBumpMapScene __RPC_FAR * This,
    long dx,
    long dy,
    long w,
    long h);


void __RPC_STUB IBumpMapScene_MakeEllipsoid_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IBumpMapScene_MakeHCylinder_Proxy( 
    IBumpMapScene __RPC_FAR * This,
    long dx,
    long dy,
    long w,
    long h);


void __RPC_STUB IBumpMapScene_MakeHCylinder_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IBumpMapScene_MakeRoundRect_Proxy( 
    IBumpMapScene __RPC_FAR * This,
    long dx,
    long dy,
    long w,
    long h,
    long edge);


void __RPC_STUB IBumpMapScene_MakeRoundRect_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IBumpMapScene_MakeRoundRectDip_Proxy( 
    IBumpMapScene __RPC_FAR * This,
    long dx,
    long dy,
    long w,
    long h,
    long edge,
    long bottom);


void __RPC_STUB IBumpMapScene_MakeRoundRectDip_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IBumpMapScene_MakeFlatDip_Proxy( 
    IBumpMapScene __RPC_FAR * This,
    long dx,
    long dy,
    long w,
    long h,
    long edge,
    long bottom);


void __RPC_STUB IBumpMapScene_MakeFlatDip_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IBumpMapScene_MakeRaisedRect_Proxy( 
    IBumpMapScene __RPC_FAR * This,
    long dx,
    long dy,
    long w,
    long h,
    long edge,
    long top);


void __RPC_STUB IBumpMapScene_MakeRaisedRect_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IBumpMapScene_MakeFlatRect_Proxy( 
    IBumpMapScene __RPC_FAR * This,
    long dx,
    long dy,
    long w,
    long h);


void __RPC_STUB IBumpMapScene_MakeFlatRect_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IBumpMapScene_RoughenRect_Proxy( 
    IBumpMapScene __RPC_FAR * This,
    long dx,
    long dy,
    long w,
    long h,
    long rough);


void __RPC_STUB IBumpMapScene_RoughenRect_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IBumpMapScene_BrushedRect_Proxy( 
    IBumpMapScene __RPC_FAR * This,
    long dx,
    long dy,
    long w,
    long h,
    long rough);


void __RPC_STUB IBumpMapScene_BrushedRect_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IBumpMapScene_ClearRect_Proxy( 
    IBumpMapScene __RPC_FAR * This,
    long dx,
    long dy,
    long w,
    long h);


void __RPC_STUB IBumpMapScene_ClearRect_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IBumpMapScene_HorizRipple_Proxy( 
    IBumpMapScene __RPC_FAR * This,
    long dx,
    long dy,
    long w,
    long h,
    long ampl,
    long periods);


void __RPC_STUB IBumpMapScene_HorizRipple_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IBumpMapScene_RippleEllipse_Proxy( 
    IBumpMapScene __RPC_FAR * This,
    long dx,
    long dy,
    long w,
    long h,
    long periods,
    long ampl);


void __RPC_STUB IBumpMapScene_RippleEllipse_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IBumpMapScene_MakeEllipseDent_Proxy( 
    IBumpMapScene __RPC_FAR * This,
    long dx,
    long dy,
    long w,
    long h,
    long edge);


void __RPC_STUB IBumpMapScene_MakeEllipseDent_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IBumpMapScene_MakeVBelt_Proxy( 
    IBumpMapScene __RPC_FAR * This,
    long dx,
    long dy,
    long w,
    long h,
    long edge,
    long bottom);


void __RPC_STUB IBumpMapScene_MakeVBelt_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IBumpMapScene_INTERFACE_DEFINED__ */


#ifndef __IBumpMapRenderer_INTERFACE_DEFINED__
#define __IBumpMapRenderer_INTERFACE_DEFINED__

/****************************************
 * Generated header for interface: IBumpMapRenderer
 * at Tue Nov 23 05:02:07 1999
 * using MIDL 3.01.75
 ****************************************/
/* [uuid][object][local] */ 



EXTERN_C const IID IID_IBumpMapRenderer;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    interface DECLSPEC_UUID("8335e619-ab3b-11ce-8468-0000b468276b")
    IBumpMapRenderer : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE SetLight( 
            long __RPC_FAR *plLV) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Render( 
            LPVOID pBMIH,
            BYTE __RPC_FAR *pBits,
            long dx,
            long dy,
            IBumpMapScene __RPC_FAR *pScn,
            COLORREF color) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE RenderOnDIB( 
            LPVOID pBMIH,
            BYTE __RPC_FAR *pBits,
            long dx,
            long dy,
            IBumpMapScene __RPC_FAR *pScn,
            long bBlank) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Ellipsoid( 
            LPVOID pBMIH,
            BYTE __RPC_FAR *pBits,
            long dx,
            long dy,
            long w,
            long h,
            COLORREF color) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetDiffuseLevels( 
            long ambient,
            long diffuse) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetSpecularLevels( 
            long spec,
            long power) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE RoundoffRect( 
            LPVOID pvBMIH,
            BYTE __RPC_FAR *pBits,
            long dx,
            long dy,
            long w,
            long h,
            DWORD color,
            long edge,
            long topdenom,
            RECT __RPC_FAR *prcClip) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE RoundoffRectRough( 
            LPVOID pvBMIH,
            BYTE __RPC_FAR *pBits,
            long dx,
            long dy,
            long w,
            long h,
            DWORD color,
            long edge,
            long rough,
            RECT __RPC_FAR *prcClip) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE RoundoffRectRoughCached( 
            LPVOID pvBMIH,
            BYTE __RPC_FAR *pBits,
            long dx,
            long dy,
            long w,
            long h,
            DWORD color,
            long edge,
            long rough,
            RECT __RPC_FAR *prcClip,
            DWORD dwRendererHandle) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE RoundoffRectDIB( 
            LPVOID pvDestBMIH,
            BYTE __RPC_FAR *pDestBits,
            LPVOID pvSrcBMIH,
            BYTE __RPC_FAR *pSrcBits,
            long dx,
            long dy,
            long w,
            long h,
            long edge) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE MakeDentedFrame( 
            LPVOID pvDestBMIH,
            BYTE __RPC_FAR *pDestBits,
            long dx,
            long dy,
            long w,
            long h,
            long edge,
            long bottom,
            RECT __RPC_FAR *prcClip) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE MakeDentedFrameCached( 
            LPVOID pvDestBMIH,
            BYTE __RPC_FAR *pDestBits,
            long dx,
            long dy,
            long w,
            long h,
            long edge,
            long bottom,
            RECT __RPC_FAR *prcClip,
            DWORD dwRendererHandle) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE RoundoffRectRoughDIB( 
            LPVOID pvDestBMIH,
            BYTE __RPC_FAR *pDestBits,
            LPVOID pvSrcBMIH,
            BYTE __RPC_FAR *pSrcBits,
            long dx,
            long dy,
            long w,
            long h,
            DWORD color,
            long edge,
            long rough) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE MakeDentedFrame2( 
            LPVOID pvDestBMIH,
            BYTE __RPC_FAR *pDestBits,
            long dx,
            long dy,
            long w,
            long h,
            long edge,
            long curveradius,
            long bottom,
            DWORD clrIn,
            DWORD clrOut,
            long roughIn,
            long roughOut,
            RECT __RPC_FAR *prcClip,
            BOOL raised,
            DWORD dwRendererHandle) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SmoothIntersection( 
            LPVOID pvDestBMIH,
            BYTE __RPC_FAR *pDestBits,
            RECT __RPC_FAR *theRect,
            long edgeNum,
            long quadrant,
            DWORD color,
            DWORD rough,
            BOOL raised,
            DWORD dwRendererHandle) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetGlobalRenderer( 
            IBumpMapRenderer __RPC_FAR *__RPC_FAR *ppRenderer) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE NewRendererHandle( 
            /* [out] */ DWORD __RPC_FAR *pHandle,
            long width,
            long height) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE HandleValid( 
            DWORD handle,
            BOOL valid) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE RenderFromCache( 
            LPVOID pvDestBMIH,
            BYTE __RPC_FAR *pDestBits,
            DWORD handle,
            RECT __RPC_FAR *updRect) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IBumpMapRendererVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            IBumpMapRenderer __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            IBumpMapRenderer __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            IBumpMapRenderer __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetLight )( 
            IBumpMapRenderer __RPC_FAR * This,
            long __RPC_FAR *plLV);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Render )( 
            IBumpMapRenderer __RPC_FAR * This,
            LPVOID pBMIH,
            BYTE __RPC_FAR *pBits,
            long dx,
            long dy,
            IBumpMapScene __RPC_FAR *pScn,
            COLORREF color);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *RenderOnDIB )( 
            IBumpMapRenderer __RPC_FAR * This,
            LPVOID pBMIH,
            BYTE __RPC_FAR *pBits,
            long dx,
            long dy,
            IBumpMapScene __RPC_FAR *pScn,
            long bBlank);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Ellipsoid )( 
            IBumpMapRenderer __RPC_FAR * This,
            LPVOID pBMIH,
            BYTE __RPC_FAR *pBits,
            long dx,
            long dy,
            long w,
            long h,
            COLORREF color);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetDiffuseLevels )( 
            IBumpMapRenderer __RPC_FAR * This,
            long ambient,
            long diffuse);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetSpecularLevels )( 
            IBumpMapRenderer __RPC_FAR * This,
            long spec,
            long power);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *RoundoffRect )( 
            IBumpMapRenderer __RPC_FAR * This,
            LPVOID pvBMIH,
            BYTE __RPC_FAR *pBits,
            long dx,
            long dy,
            long w,
            long h,
            DWORD color,
            long edge,
            long topdenom,
            RECT __RPC_FAR *prcClip);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *RoundoffRectRough )( 
            IBumpMapRenderer __RPC_FAR * This,
            LPVOID pvBMIH,
            BYTE __RPC_FAR *pBits,
            long dx,
            long dy,
            long w,
            long h,
            DWORD color,
            long edge,
            long rough,
            RECT __RPC_FAR *prcClip);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *RoundoffRectRoughCached )( 
            IBumpMapRenderer __RPC_FAR * This,
            LPVOID pvBMIH,
            BYTE __RPC_FAR *pBits,
            long dx,
            long dy,
            long w,
            long h,
            DWORD color,
            long edge,
            long rough,
            RECT __RPC_FAR *prcClip,
            DWORD dwRendererHandle);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *RoundoffRectDIB )( 
            IBumpMapRenderer __RPC_FAR * This,
            LPVOID pvDestBMIH,
            BYTE __RPC_FAR *pDestBits,
            LPVOID pvSrcBMIH,
            BYTE __RPC_FAR *pSrcBits,
            long dx,
            long dy,
            long w,
            long h,
            long edge);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *MakeDentedFrame )( 
            IBumpMapRenderer __RPC_FAR * This,
            LPVOID pvDestBMIH,
            BYTE __RPC_FAR *pDestBits,
            long dx,
            long dy,
            long w,
            long h,
            long edge,
            long bottom,
            RECT __RPC_FAR *prcClip);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *MakeDentedFrameCached )( 
            IBumpMapRenderer __RPC_FAR * This,
            LPVOID pvDestBMIH,
            BYTE __RPC_FAR *pDestBits,
            long dx,
            long dy,
            long w,
            long h,
            long edge,
            long bottom,
            RECT __RPC_FAR *prcClip,
            DWORD dwRendererHandle);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *RoundoffRectRoughDIB )( 
            IBumpMapRenderer __RPC_FAR * This,
            LPVOID pvDestBMIH,
            BYTE __RPC_FAR *pDestBits,
            LPVOID pvSrcBMIH,
            BYTE __RPC_FAR *pSrcBits,
            long dx,
            long dy,
            long w,
            long h,
            DWORD color,
            long edge,
            long rough);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *MakeDentedFrame2 )( 
            IBumpMapRenderer __RPC_FAR * This,
            LPVOID pvDestBMIH,
            BYTE __RPC_FAR *pDestBits,
            long dx,
            long dy,
            long w,
            long h,
            long edge,
            long curveradius,
            long bottom,
            DWORD clrIn,
            DWORD clrOut,
            long roughIn,
            long roughOut,
            RECT __RPC_FAR *prcClip,
            BOOL raised,
            DWORD dwRendererHandle);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SmoothIntersection )( 
            IBumpMapRenderer __RPC_FAR * This,
            LPVOID pvDestBMIH,
            BYTE __RPC_FAR *pDestBits,
            RECT __RPC_FAR *theRect,
            long edgeNum,
            long quadrant,
            DWORD color,
            DWORD rough,
            BOOL raised,
            DWORD dwRendererHandle);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetGlobalRenderer )( 
            IBumpMapRenderer __RPC_FAR * This,
            IBumpMapRenderer __RPC_FAR *__RPC_FAR *ppRenderer);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *NewRendererHandle )( 
            IBumpMapRenderer __RPC_FAR * This,
            /* [out] */ DWORD __RPC_FAR *pHandle,
            long width,
            long height);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *HandleValid )( 
            IBumpMapRenderer __RPC_FAR * This,
            DWORD handle,
            BOOL valid);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *RenderFromCache )( 
            IBumpMapRenderer __RPC_FAR * This,
            LPVOID pvDestBMIH,
            BYTE __RPC_FAR *pDestBits,
            DWORD handle,
            RECT __RPC_FAR *updRect);
        
        END_INTERFACE
    } IBumpMapRendererVtbl;

    interface IBumpMapRenderer
    {
        CONST_VTBL struct IBumpMapRendererVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IBumpMapRenderer_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IBumpMapRenderer_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IBumpMapRenderer_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IBumpMapRenderer_SetLight(This,plLV)	\
    (This)->lpVtbl -> SetLight(This,plLV)

#define IBumpMapRenderer_Render(This,pBMIH,pBits,dx,dy,pScn,color)	\
    (This)->lpVtbl -> Render(This,pBMIH,pBits,dx,dy,pScn,color)

#define IBumpMapRenderer_RenderOnDIB(This,pBMIH,pBits,dx,dy,pScn,bBlank)	\
    (This)->lpVtbl -> RenderOnDIB(This,pBMIH,pBits,dx,dy,pScn,bBlank)

#define IBumpMapRenderer_Ellipsoid(This,pBMIH,pBits,dx,dy,w,h,color)	\
    (This)->lpVtbl -> Ellipsoid(This,pBMIH,pBits,dx,dy,w,h,color)

#define IBumpMapRenderer_SetDiffuseLevels(This,ambient,diffuse)	\
    (This)->lpVtbl -> SetDiffuseLevels(This,ambient,diffuse)

#define IBumpMapRenderer_SetSpecularLevels(This,spec,power)	\
    (This)->lpVtbl -> SetSpecularLevels(This,spec,power)

#define IBumpMapRenderer_RoundoffRect(This,pvBMIH,pBits,dx,dy,w,h,color,edge,topdenom,prcClip)	\
    (This)->lpVtbl -> RoundoffRect(This,pvBMIH,pBits,dx,dy,w,h,color,edge,topdenom,prcClip)

#define IBumpMapRenderer_RoundoffRectRough(This,pvBMIH,pBits,dx,dy,w,h,color,edge,rough,prcClip)	\
    (This)->lpVtbl -> RoundoffRectRough(This,pvBMIH,pBits,dx,dy,w,h,color,edge,rough,prcClip)

#define IBumpMapRenderer_RoundoffRectRoughCached(This,pvBMIH,pBits,dx,dy,w,h,color,edge,rough,prcClip,dwRendererHandle)	\
    (This)->lpVtbl -> RoundoffRectRoughCached(This,pvBMIH,pBits,dx,dy,w,h,color,edge,rough,prcClip,dwRendererHandle)

#define IBumpMapRenderer_RoundoffRectDIB(This,pvDestBMIH,pDestBits,pvSrcBMIH,pSrcBits,dx,dy,w,h,edge)	\
    (This)->lpVtbl -> RoundoffRectDIB(This,pvDestBMIH,pDestBits,pvSrcBMIH,pSrcBits,dx,dy,w,h,edge)

#define IBumpMapRenderer_MakeDentedFrame(This,pvDestBMIH,pDestBits,dx,dy,w,h,edge,bottom,prcClip)	\
    (This)->lpVtbl -> MakeDentedFrame(This,pvDestBMIH,pDestBits,dx,dy,w,h,edge,bottom,prcClip)

#define IBumpMapRenderer_MakeDentedFrameCached(This,pvDestBMIH,pDestBits,dx,dy,w,h,edge,bottom,prcClip,dwRendererHandle)	\
    (This)->lpVtbl -> MakeDentedFrameCached(This,pvDestBMIH,pDestBits,dx,dy,w,h,edge,bottom,prcClip,dwRendererHandle)

#define IBumpMapRenderer_RoundoffRectRoughDIB(This,pvDestBMIH,pDestBits,pvSrcBMIH,pSrcBits,dx,dy,w,h,color,edge,rough)	\
    (This)->lpVtbl -> RoundoffRectRoughDIB(This,pvDestBMIH,pDestBits,pvSrcBMIH,pSrcBits,dx,dy,w,h,color,edge,rough)

#define IBumpMapRenderer_MakeDentedFrame2(This,pvDestBMIH,pDestBits,dx,dy,w,h,edge,curveradius,bottom,clrIn,clrOut,roughIn,roughOut,prcClip,raised,dwRendererHandle)	\
    (This)->lpVtbl -> MakeDentedFrame2(This,pvDestBMIH,pDestBits,dx,dy,w,h,edge,curveradius,bottom,clrIn,clrOut,roughIn,roughOut,prcClip,raised,dwRendererHandle)

#define IBumpMapRenderer_SmoothIntersection(This,pvDestBMIH,pDestBits,theRect,edgeNum,quadrant,color,rough,raised,dwRendererHandle)	\
    (This)->lpVtbl -> SmoothIntersection(This,pvDestBMIH,pDestBits,theRect,edgeNum,quadrant,color,rough,raised,dwRendererHandle)

#define IBumpMapRenderer_SetGlobalRenderer(This,ppRenderer)	\
    (This)->lpVtbl -> SetGlobalRenderer(This,ppRenderer)

#define IBumpMapRenderer_NewRendererHandle(This,pHandle,width,height)	\
    (This)->lpVtbl -> NewRendererHandle(This,pHandle,width,height)

#define IBumpMapRenderer_HandleValid(This,handle,valid)	\
    (This)->lpVtbl -> HandleValid(This,handle,valid)

#define IBumpMapRenderer_RenderFromCache(This,pvDestBMIH,pDestBits,handle,updRect)	\
    (This)->lpVtbl -> RenderFromCache(This,pvDestBMIH,pDestBits,handle,updRect)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE IBumpMapRenderer_SetLight_Proxy( 
    IBumpMapRenderer __RPC_FAR * This,
    long __RPC_FAR *plLV);


void __RPC_STUB IBumpMapRenderer_SetLight_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IBumpMapRenderer_Render_Proxy( 
    IBumpMapRenderer __RPC_FAR * This,
    LPVOID pBMIH,
    BYTE __RPC_FAR *pBits,
    long dx,
    long dy,
    IBumpMapScene __RPC_FAR *pScn,
    COLORREF color);


void __RPC_STUB IBumpMapRenderer_Render_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IBumpMapRenderer_RenderOnDIB_Proxy( 
    IBumpMapRenderer __RPC_FAR * This,
    LPVOID pBMIH,
    BYTE __RPC_FAR *pBits,
    long dx,
    long dy,
    IBumpMapScene __RPC_FAR *pScn,
    long bBlank);


void __RPC_STUB IBumpMapRenderer_RenderOnDIB_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IBumpMapRenderer_Ellipsoid_Proxy( 
    IBumpMapRenderer __RPC_FAR * This,
    LPVOID pBMIH,
    BYTE __RPC_FAR *pBits,
    long dx,
    long dy,
    long w,
    long h,
    COLORREF color);


void __RPC_STUB IBumpMapRenderer_Ellipsoid_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IBumpMapRenderer_SetDiffuseLevels_Proxy( 
    IBumpMapRenderer __RPC_FAR * This,
    long ambient,
    long diffuse);


void __RPC_STUB IBumpMapRenderer_SetDiffuseLevels_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IBumpMapRenderer_SetSpecularLevels_Proxy( 
    IBumpMapRenderer __RPC_FAR * This,
    long spec,
    long power);


void __RPC_STUB IBumpMapRenderer_SetSpecularLevels_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IBumpMapRenderer_RoundoffRect_Proxy( 
    IBumpMapRenderer __RPC_FAR * This,
    LPVOID pvBMIH,
    BYTE __RPC_FAR *pBits,
    long dx,
    long dy,
    long w,
    long h,
    DWORD color,
    long edge,
    long topdenom,
    RECT __RPC_FAR *prcClip);


void __RPC_STUB IBumpMapRenderer_RoundoffRect_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IBumpMapRenderer_RoundoffRectRough_Proxy( 
    IBumpMapRenderer __RPC_FAR * This,
    LPVOID pvBMIH,
    BYTE __RPC_FAR *pBits,
    long dx,
    long dy,
    long w,
    long h,
    DWORD color,
    long edge,
    long rough,
    RECT __RPC_FAR *prcClip);


void __RPC_STUB IBumpMapRenderer_RoundoffRectRough_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IBumpMapRenderer_RoundoffRectRoughCached_Proxy( 
    IBumpMapRenderer __RPC_FAR * This,
    LPVOID pvBMIH,
    BYTE __RPC_FAR *pBits,
    long dx,
    long dy,
    long w,
    long h,
    DWORD color,
    long edge,
    long rough,
    RECT __RPC_FAR *prcClip,
    DWORD dwRendererHandle);


void __RPC_STUB IBumpMapRenderer_RoundoffRectRoughCached_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IBumpMapRenderer_RoundoffRectDIB_Proxy( 
    IBumpMapRenderer __RPC_FAR * This,
    LPVOID pvDestBMIH,
    BYTE __RPC_FAR *pDestBits,
    LPVOID pvSrcBMIH,
    BYTE __RPC_FAR *pSrcBits,
    long dx,
    long dy,
    long w,
    long h,
    long edge);


void __RPC_STUB IBumpMapRenderer_RoundoffRectDIB_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IBumpMapRenderer_MakeDentedFrame_Proxy( 
    IBumpMapRenderer __RPC_FAR * This,
    LPVOID pvDestBMIH,
    BYTE __RPC_FAR *pDestBits,
    long dx,
    long dy,
    long w,
    long h,
    long edge,
    long bottom,
    RECT __RPC_FAR *prcClip);


void __RPC_STUB IBumpMapRenderer_MakeDentedFrame_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IBumpMapRenderer_MakeDentedFrameCached_Proxy( 
    IBumpMapRenderer __RPC_FAR * This,
    LPVOID pvDestBMIH,
    BYTE __RPC_FAR *pDestBits,
    long dx,
    long dy,
    long w,
    long h,
    long edge,
    long bottom,
    RECT __RPC_FAR *prcClip,
    DWORD dwRendererHandle);


void __RPC_STUB IBumpMapRenderer_MakeDentedFrameCached_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IBumpMapRenderer_RoundoffRectRoughDIB_Proxy( 
    IBumpMapRenderer __RPC_FAR * This,
    LPVOID pvDestBMIH,
    BYTE __RPC_FAR *pDestBits,
    LPVOID pvSrcBMIH,
    BYTE __RPC_FAR *pSrcBits,
    long dx,
    long dy,
    long w,
    long h,
    DWORD color,
    long edge,
    long rough);


void __RPC_STUB IBumpMapRenderer_RoundoffRectRoughDIB_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IBumpMapRenderer_MakeDentedFrame2_Proxy( 
    IBumpMapRenderer __RPC_FAR * This,
    LPVOID pvDestBMIH,
    BYTE __RPC_FAR *pDestBits,
    long dx,
    long dy,
    long w,
    long h,
    long edge,
    long curveradius,
    long bottom,
    DWORD clrIn,
    DWORD clrOut,
    long roughIn,
    long roughOut,
    RECT __RPC_FAR *prcClip,
    BOOL raised,
    DWORD dwRendererHandle);


void __RPC_STUB IBumpMapRenderer_MakeDentedFrame2_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IBumpMapRenderer_SmoothIntersection_Proxy( 
    IBumpMapRenderer __RPC_FAR * This,
    LPVOID pvDestBMIH,
    BYTE __RPC_FAR *pDestBits,
    RECT __RPC_FAR *theRect,
    long edgeNum,
    long quadrant,
    DWORD color,
    DWORD rough,
    BOOL raised,
    DWORD dwRendererHandle);


void __RPC_STUB IBumpMapRenderer_SmoothIntersection_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IBumpMapRenderer_SetGlobalRenderer_Proxy( 
    IBumpMapRenderer __RPC_FAR * This,
    IBumpMapRenderer __RPC_FAR *__RPC_FAR *ppRenderer);


void __RPC_STUB IBumpMapRenderer_SetGlobalRenderer_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IBumpMapRenderer_NewRendererHandle_Proxy( 
    IBumpMapRenderer __RPC_FAR * This,
    /* [out] */ DWORD __RPC_FAR *pHandle,
    long width,
    long height);


void __RPC_STUB IBumpMapRenderer_NewRendererHandle_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IBumpMapRenderer_HandleValid_Proxy( 
    IBumpMapRenderer __RPC_FAR * This,
    DWORD handle,
    BOOL valid);


void __RPC_STUB IBumpMapRenderer_HandleValid_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IBumpMapRenderer_RenderFromCache_Proxy( 
    IBumpMapRenderer __RPC_FAR * This,
    LPVOID pvDestBMIH,
    BYTE __RPC_FAR *pDestBits,
    DWORD handle,
    RECT __RPC_FAR *updRect);


void __RPC_STUB IBumpMapRenderer_RenderFromCache_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IBumpMapRenderer_INTERFACE_DEFINED__ */


#ifndef __IBumpMapRenderer2_INTERFACE_DEFINED__
#define __IBumpMapRenderer2_INTERFACE_DEFINED__

/****************************************
 * Generated header for interface: IBumpMapRenderer2
 * at Tue Nov 23 05:02:07 1999
 * using MIDL 3.01.75
 ****************************************/
/* [uuid][object][local] */ 



EXTERN_C const IID IID_IBumpMapRenderer2;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    interface DECLSPEC_UUID("8335e606-ab3b-11ce-8468-0000b468276b")
    IBumpMapRenderer2 : public IBumpMapRenderer
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE InvertEllipsoid( 
            LPVOID pBMIH,
            BYTE __RPC_FAR *pBites,
            long dx,
            long dy,
            long w,
            long h,
            COLORREF color) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IBumpMapRenderer2Vtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            IBumpMapRenderer2 __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            IBumpMapRenderer2 __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            IBumpMapRenderer2 __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetLight )( 
            IBumpMapRenderer2 __RPC_FAR * This,
            long __RPC_FAR *plLV);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Render )( 
            IBumpMapRenderer2 __RPC_FAR * This,
            LPVOID pBMIH,
            BYTE __RPC_FAR *pBits,
            long dx,
            long dy,
            IBumpMapScene __RPC_FAR *pScn,
            COLORREF color);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *RenderOnDIB )( 
            IBumpMapRenderer2 __RPC_FAR * This,
            LPVOID pBMIH,
            BYTE __RPC_FAR *pBits,
            long dx,
            long dy,
            IBumpMapScene __RPC_FAR *pScn,
            long bBlank);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Ellipsoid )( 
            IBumpMapRenderer2 __RPC_FAR * This,
            LPVOID pBMIH,
            BYTE __RPC_FAR *pBits,
            long dx,
            long dy,
            long w,
            long h,
            COLORREF color);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetDiffuseLevels )( 
            IBumpMapRenderer2 __RPC_FAR * This,
            long ambient,
            long diffuse);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetSpecularLevels )( 
            IBumpMapRenderer2 __RPC_FAR * This,
            long spec,
            long power);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *RoundoffRect )( 
            IBumpMapRenderer2 __RPC_FAR * This,
            LPVOID pvBMIH,
            BYTE __RPC_FAR *pBits,
            long dx,
            long dy,
            long w,
            long h,
            DWORD color,
            long edge,
            long topdenom,
            RECT __RPC_FAR *prcClip);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *RoundoffRectRough )( 
            IBumpMapRenderer2 __RPC_FAR * This,
            LPVOID pvBMIH,
            BYTE __RPC_FAR *pBits,
            long dx,
            long dy,
            long w,
            long h,
            DWORD color,
            long edge,
            long rough,
            RECT __RPC_FAR *prcClip);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *RoundoffRectRoughCached )( 
            IBumpMapRenderer2 __RPC_FAR * This,
            LPVOID pvBMIH,
            BYTE __RPC_FAR *pBits,
            long dx,
            long dy,
            long w,
            long h,
            DWORD color,
            long edge,
            long rough,
            RECT __RPC_FAR *prcClip,
            DWORD dwRendererHandle);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *RoundoffRectDIB )( 
            IBumpMapRenderer2 __RPC_FAR * This,
            LPVOID pvDestBMIH,
            BYTE __RPC_FAR *pDestBits,
            LPVOID pvSrcBMIH,
            BYTE __RPC_FAR *pSrcBits,
            long dx,
            long dy,
            long w,
            long h,
            long edge);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *MakeDentedFrame )( 
            IBumpMapRenderer2 __RPC_FAR * This,
            LPVOID pvDestBMIH,
            BYTE __RPC_FAR *pDestBits,
            long dx,
            long dy,
            long w,
            long h,
            long edge,
            long bottom,
            RECT __RPC_FAR *prcClip);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *MakeDentedFrameCached )( 
            IBumpMapRenderer2 __RPC_FAR * This,
            LPVOID pvDestBMIH,
            BYTE __RPC_FAR *pDestBits,
            long dx,
            long dy,
            long w,
            long h,
            long edge,
            long bottom,
            RECT __RPC_FAR *prcClip,
            DWORD dwRendererHandle);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *RoundoffRectRoughDIB )( 
            IBumpMapRenderer2 __RPC_FAR * This,
            LPVOID pvDestBMIH,
            BYTE __RPC_FAR *pDestBits,
            LPVOID pvSrcBMIH,
            BYTE __RPC_FAR *pSrcBits,
            long dx,
            long dy,
            long w,
            long h,
            DWORD color,
            long edge,
            long rough);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *MakeDentedFrame2 )( 
            IBumpMapRenderer2 __RPC_FAR * This,
            LPVOID pvDestBMIH,
            BYTE __RPC_FAR *pDestBits,
            long dx,
            long dy,
            long w,
            long h,
            long edge,
            long curveradius,
            long bottom,
            DWORD clrIn,
            DWORD clrOut,
            long roughIn,
            long roughOut,
            RECT __RPC_FAR *prcClip,
            BOOL raised,
            DWORD dwRendererHandle);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SmoothIntersection )( 
            IBumpMapRenderer2 __RPC_FAR * This,
            LPVOID pvDestBMIH,
            BYTE __RPC_FAR *pDestBits,
            RECT __RPC_FAR *theRect,
            long edgeNum,
            long quadrant,
            DWORD color,
            DWORD rough,
            BOOL raised,
            DWORD dwRendererHandle);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetGlobalRenderer )( 
            IBumpMapRenderer2 __RPC_FAR * This,
            IBumpMapRenderer __RPC_FAR *__RPC_FAR *ppRenderer);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *NewRendererHandle )( 
            IBumpMapRenderer2 __RPC_FAR * This,
            /* [out] */ DWORD __RPC_FAR *pHandle,
            long width,
            long height);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *HandleValid )( 
            IBumpMapRenderer2 __RPC_FAR * This,
            DWORD handle,
            BOOL valid);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *RenderFromCache )( 
            IBumpMapRenderer2 __RPC_FAR * This,
            LPVOID pvDestBMIH,
            BYTE __RPC_FAR *pDestBits,
            DWORD handle,
            RECT __RPC_FAR *updRect);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *InvertEllipsoid )( 
            IBumpMapRenderer2 __RPC_FAR * This,
            LPVOID pBMIH,
            BYTE __RPC_FAR *pBites,
            long dx,
            long dy,
            long w,
            long h,
            COLORREF color);
        
        END_INTERFACE
    } IBumpMapRenderer2Vtbl;

    interface IBumpMapRenderer2
    {
        CONST_VTBL struct IBumpMapRenderer2Vtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IBumpMapRenderer2_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IBumpMapRenderer2_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IBumpMapRenderer2_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IBumpMapRenderer2_SetLight(This,plLV)	\
    (This)->lpVtbl -> SetLight(This,plLV)

#define IBumpMapRenderer2_Render(This,pBMIH,pBits,dx,dy,pScn,color)	\
    (This)->lpVtbl -> Render(This,pBMIH,pBits,dx,dy,pScn,color)

#define IBumpMapRenderer2_RenderOnDIB(This,pBMIH,pBits,dx,dy,pScn,bBlank)	\
    (This)->lpVtbl -> RenderOnDIB(This,pBMIH,pBits,dx,dy,pScn,bBlank)

#define IBumpMapRenderer2_Ellipsoid(This,pBMIH,pBits,dx,dy,w,h,color)	\
    (This)->lpVtbl -> Ellipsoid(This,pBMIH,pBits,dx,dy,w,h,color)

#define IBumpMapRenderer2_SetDiffuseLevels(This,ambient,diffuse)	\
    (This)->lpVtbl -> SetDiffuseLevels(This,ambient,diffuse)

#define IBumpMapRenderer2_SetSpecularLevels(This,spec,power)	\
    (This)->lpVtbl -> SetSpecularLevels(This,spec,power)

#define IBumpMapRenderer2_RoundoffRect(This,pvBMIH,pBits,dx,dy,w,h,color,edge,topdenom,prcClip)	\
    (This)->lpVtbl -> RoundoffRect(This,pvBMIH,pBits,dx,dy,w,h,color,edge,topdenom,prcClip)

#define IBumpMapRenderer2_RoundoffRectRough(This,pvBMIH,pBits,dx,dy,w,h,color,edge,rough,prcClip)	\
    (This)->lpVtbl -> RoundoffRectRough(This,pvBMIH,pBits,dx,dy,w,h,color,edge,rough,prcClip)

#define IBumpMapRenderer2_RoundoffRectRoughCached(This,pvBMIH,pBits,dx,dy,w,h,color,edge,rough,prcClip,dwRendererHandle)	\
    (This)->lpVtbl -> RoundoffRectRoughCached(This,pvBMIH,pBits,dx,dy,w,h,color,edge,rough,prcClip,dwRendererHandle)

#define IBumpMapRenderer2_RoundoffRectDIB(This,pvDestBMIH,pDestBits,pvSrcBMIH,pSrcBits,dx,dy,w,h,edge)	\
    (This)->lpVtbl -> RoundoffRectDIB(This,pvDestBMIH,pDestBits,pvSrcBMIH,pSrcBits,dx,dy,w,h,edge)

#define IBumpMapRenderer2_MakeDentedFrame(This,pvDestBMIH,pDestBits,dx,dy,w,h,edge,bottom,prcClip)	\
    (This)->lpVtbl -> MakeDentedFrame(This,pvDestBMIH,pDestBits,dx,dy,w,h,edge,bottom,prcClip)

#define IBumpMapRenderer2_MakeDentedFrameCached(This,pvDestBMIH,pDestBits,dx,dy,w,h,edge,bottom,prcClip,dwRendererHandle)	\
    (This)->lpVtbl -> MakeDentedFrameCached(This,pvDestBMIH,pDestBits,dx,dy,w,h,edge,bottom,prcClip,dwRendererHandle)

#define IBumpMapRenderer2_RoundoffRectRoughDIB(This,pvDestBMIH,pDestBits,pvSrcBMIH,pSrcBits,dx,dy,w,h,color,edge,rough)	\
    (This)->lpVtbl -> RoundoffRectRoughDIB(This,pvDestBMIH,pDestBits,pvSrcBMIH,pSrcBits,dx,dy,w,h,color,edge,rough)

#define IBumpMapRenderer2_MakeDentedFrame2(This,pvDestBMIH,pDestBits,dx,dy,w,h,edge,curveradius,bottom,clrIn,clrOut,roughIn,roughOut,prcClip,raised,dwRendererHandle)	\
    (This)->lpVtbl -> MakeDentedFrame2(This,pvDestBMIH,pDestBits,dx,dy,w,h,edge,curveradius,bottom,clrIn,clrOut,roughIn,roughOut,prcClip,raised,dwRendererHandle)

#define IBumpMapRenderer2_SmoothIntersection(This,pvDestBMIH,pDestBits,theRect,edgeNum,quadrant,color,rough,raised,dwRendererHandle)	\
    (This)->lpVtbl -> SmoothIntersection(This,pvDestBMIH,pDestBits,theRect,edgeNum,quadrant,color,rough,raised,dwRendererHandle)

#define IBumpMapRenderer2_SetGlobalRenderer(This,ppRenderer)	\
    (This)->lpVtbl -> SetGlobalRenderer(This,ppRenderer)

#define IBumpMapRenderer2_NewRendererHandle(This,pHandle,width,height)	\
    (This)->lpVtbl -> NewRendererHandle(This,pHandle,width,height)

#define IBumpMapRenderer2_HandleValid(This,handle,valid)	\
    (This)->lpVtbl -> HandleValid(This,handle,valid)

#define IBumpMapRenderer2_RenderFromCache(This,pvDestBMIH,pDestBits,handle,updRect)	\
    (This)->lpVtbl -> RenderFromCache(This,pvDestBMIH,pDestBits,handle,updRect)


#define IBumpMapRenderer2_InvertEllipsoid(This,pBMIH,pBites,dx,dy,w,h,color)	\
    (This)->lpVtbl -> InvertEllipsoid(This,pBMIH,pBites,dx,dy,w,h,color)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE IBumpMapRenderer2_InvertEllipsoid_Proxy( 
    IBumpMapRenderer2 __RPC_FAR * This,
    LPVOID pBMIH,
    BYTE __RPC_FAR *pBites,
    long dx,
    long dy,
    long w,
    long h,
    COLORREF color);


void __RPC_STUB IBumpMapRenderer2_InvertEllipsoid_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IBumpMapRenderer2_INTERFACE_DEFINED__ */


/* Additional Prototypes for ALL interfaces */

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif
