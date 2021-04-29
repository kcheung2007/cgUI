/* this ALWAYS GENERATED file contains the definitions for the interfaces */


/* File created by MIDL compiler version 3.01.75 */
/* at Tue Nov 23 05:02:12 1999
 */
/* Compiler settings for plyctl.idl:
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

#ifndef __plyctl_h__
#define __plyctl_h__

#ifdef __cplusplus
extern "C"{
#endif 

/* Forward Declarations */ 

#ifndef __IPlayControl_FWD_DEFINED__
#define __IPlayControl_FWD_DEFINED__
typedef interface IPlayControl IPlayControl;
#endif 	/* __IPlayControl_FWD_DEFINED__ */


#ifndef __IPlayControlBitmaps_FWD_DEFINED__
#define __IPlayControlBitmaps_FWD_DEFINED__
typedef interface IPlayControlBitmaps IPlayControlBitmaps;
#endif 	/* __IPlayControlBitmaps_FWD_DEFINED__ */


#ifndef __IPlayPopupAdviseSink_FWD_DEFINED__
#define __IPlayPopupAdviseSink_FWD_DEFINED__
typedef interface IPlayPopupAdviseSink IPlayPopupAdviseSink;
#endif 	/* __IPlayPopupAdviseSink_FWD_DEFINED__ */


#ifndef __IPlayPopup_FWD_DEFINED__
#define __IPlayPopup_FWD_DEFINED__
typedef interface IPlayPopup IPlayPopup;
#endif 	/* __IPlayPopup_FWD_DEFINED__ */


#ifndef __IPlayPopup2_FWD_DEFINED__
#define __IPlayPopup2_FWD_DEFINED__
typedef interface IPlayPopup2 IPlayPopup2;
#endif 	/* __IPlayPopup2_FWD_DEFINED__ */


#ifndef __IPlayMessageBox_FWD_DEFINED__
#define __IPlayMessageBox_FWD_DEFINED__
typedef interface IPlayMessageBox IPlayMessageBox;
#endif 	/* __IPlayMessageBox_FWD_DEFINED__ */


#ifndef __IPlayMessageBox2_FWD_DEFINED__
#define __IPlayMessageBox2_FWD_DEFINED__
typedef interface IPlayMessageBox2 IPlayMessageBox2;
#endif 	/* __IPlayMessageBox2_FWD_DEFINED__ */


/* header files for imported files */
#include "unknwn.h"
#include "pcadvs.h"
#include "gxlate.h"

void __RPC_FAR * __RPC_USER MIDL_user_allocate(size_t);
void __RPC_USER MIDL_user_free( void __RPC_FAR * ); 

#ifndef __IPlayControl_INTERFACE_DEFINED__
#define __IPlayControl_INTERFACE_DEFINED__

/****************************************
 * Generated header for interface: IPlayControl
 * at Tue Nov 23 05:02:12 1999
 * using MIDL 3.01.75
 ****************************************/
/* [uuid][object][local] */ 



EXTERN_C const IID IID_IPlayControl;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    interface DECLSPEC_UUID("8335e421-ab3b-11ce-8468-0000b468276b")
    IPlayControl : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE SetLinkCtrl( 
            IPlayControl __RPC_FAR *ptcLinkCtrl,
            DWORD dwLinkType) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetAttr( 
            DWORD dwAttr,
            DWORD dwValue) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetAttr( 
            DWORD dwAttr,
            DWORD __RPC_FAR *pValue) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SaveAttributes( 
            IStorage __RPC_FAR *pStg) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE LoadAttributes( 
            IStorage __RPC_FAR *pStg) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE EnableRepaint( 
            long bEnable) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE AddToParent( 
            HWND hWndParent,
            int x,
            int y) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetSize( 
            DWORD dwAttrSize,
            SIZE __RPC_FAR *pSize) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SuggestSize( 
            DWORD dwAttrSuggest,
            SIZE __RPC_FAR *pSize) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetPosition( 
            POINT __RPC_FAR *pPosition) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetPosition( 
            POINT __RPC_FAR *pPosition) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetRect( 
            RECT __RPC_FAR *pRect) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Advise( 
            IPCtrlAdviseSink __RPC_FAR *pAdvise) = 0;
        
        virtual long STDMETHODCALLTYPE GetState( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetState( 
            long iState,
            long iMask) = 0;
        
        virtual long STDMETHODCALLTYPE GetValLong( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetValLong( 
            long iValue) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetValFloat( 
            double __RPC_FAR *dValue) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetValFloat( 
            double dValue) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetValStr( 
            /* [string] */ LPSTR pszValue,
            long cMaxChars) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetValStr( 
            LPSTR pszValue) = 0;
        
        virtual long STDMETHODCALLTYPE GetCtrlType( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Repaint( 
            RECT __RPC_FAR *prcPaint,
            unsigned long bForceUpdate) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Remove( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetCustomBitmaps( 
            DWORD dwIncluded,
            int nBitmaps,
            IGXIntBitmap __RPC_FAR *__RPC_FAR *pparyBitmaps) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE DrawToDIB( 
            LPVOID pBMIH,
            BYTE __RPC_FAR *pBits,
            RECT __RPC_FAR *pUpdRect,
            POINT __RPC_FAR *pUpdOfs) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IPlayControlVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            IPlayControl __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            IPlayControl __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            IPlayControl __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetLinkCtrl )( 
            IPlayControl __RPC_FAR * This,
            IPlayControl __RPC_FAR *ptcLinkCtrl,
            DWORD dwLinkType);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetAttr )( 
            IPlayControl __RPC_FAR * This,
            DWORD dwAttr,
            DWORD dwValue);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetAttr )( 
            IPlayControl __RPC_FAR * This,
            DWORD dwAttr,
            DWORD __RPC_FAR *pValue);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SaveAttributes )( 
            IPlayControl __RPC_FAR * This,
            IStorage __RPC_FAR *pStg);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *LoadAttributes )( 
            IPlayControl __RPC_FAR * This,
            IStorage __RPC_FAR *pStg);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *EnableRepaint )( 
            IPlayControl __RPC_FAR * This,
            long bEnable);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *AddToParent )( 
            IPlayControl __RPC_FAR * This,
            HWND hWndParent,
            int x,
            int y);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetSize )( 
            IPlayControl __RPC_FAR * This,
            DWORD dwAttrSize,
            SIZE __RPC_FAR *pSize);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SuggestSize )( 
            IPlayControl __RPC_FAR * This,
            DWORD dwAttrSuggest,
            SIZE __RPC_FAR *pSize);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetPosition )( 
            IPlayControl __RPC_FAR * This,
            POINT __RPC_FAR *pPosition);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetPosition )( 
            IPlayControl __RPC_FAR * This,
            POINT __RPC_FAR *pPosition);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetRect )( 
            IPlayControl __RPC_FAR * This,
            RECT __RPC_FAR *pRect);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Advise )( 
            IPlayControl __RPC_FAR * This,
            IPCtrlAdviseSink __RPC_FAR *pAdvise);
        
        long ( STDMETHODCALLTYPE __RPC_FAR *GetState )( 
            IPlayControl __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetState )( 
            IPlayControl __RPC_FAR * This,
            long iState,
            long iMask);
        
        long ( STDMETHODCALLTYPE __RPC_FAR *GetValLong )( 
            IPlayControl __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetValLong )( 
            IPlayControl __RPC_FAR * This,
            long iValue);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetValFloat )( 
            IPlayControl __RPC_FAR * This,
            double __RPC_FAR *dValue);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetValFloat )( 
            IPlayControl __RPC_FAR * This,
            double dValue);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetValStr )( 
            IPlayControl __RPC_FAR * This,
            /* [string] */ LPSTR pszValue,
            long cMaxChars);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetValStr )( 
            IPlayControl __RPC_FAR * This,
            LPSTR pszValue);
        
        long ( STDMETHODCALLTYPE __RPC_FAR *GetCtrlType )( 
            IPlayControl __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Repaint )( 
            IPlayControl __RPC_FAR * This,
            RECT __RPC_FAR *prcPaint,
            unsigned long bForceUpdate);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Remove )( 
            IPlayControl __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetCustomBitmaps )( 
            IPlayControl __RPC_FAR * This,
            DWORD dwIncluded,
            int nBitmaps,
            IGXIntBitmap __RPC_FAR *__RPC_FAR *pparyBitmaps);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *DrawToDIB )( 
            IPlayControl __RPC_FAR * This,
            LPVOID pBMIH,
            BYTE __RPC_FAR *pBits,
            RECT __RPC_FAR *pUpdRect,
            POINT __RPC_FAR *pUpdOfs);
        
        END_INTERFACE
    } IPlayControlVtbl;

    interface IPlayControl
    {
        CONST_VTBL struct IPlayControlVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IPlayControl_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IPlayControl_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IPlayControl_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IPlayControl_SetLinkCtrl(This,ptcLinkCtrl,dwLinkType)	\
    (This)->lpVtbl -> SetLinkCtrl(This,ptcLinkCtrl,dwLinkType)

#define IPlayControl_SetAttr(This,dwAttr,dwValue)	\
    (This)->lpVtbl -> SetAttr(This,dwAttr,dwValue)

#define IPlayControl_GetAttr(This,dwAttr,pValue)	\
    (This)->lpVtbl -> GetAttr(This,dwAttr,pValue)

#define IPlayControl_SaveAttributes(This,pStg)	\
    (This)->lpVtbl -> SaveAttributes(This,pStg)

#define IPlayControl_LoadAttributes(This,pStg)	\
    (This)->lpVtbl -> LoadAttributes(This,pStg)

#define IPlayControl_EnableRepaint(This,bEnable)	\
    (This)->lpVtbl -> EnableRepaint(This,bEnable)

#define IPlayControl_AddToParent(This,hWndParent,x,y)	\
    (This)->lpVtbl -> AddToParent(This,hWndParent,x,y)

#define IPlayControl_GetSize(This,dwAttrSize,pSize)	\
    (This)->lpVtbl -> GetSize(This,dwAttrSize,pSize)

#define IPlayControl_SuggestSize(This,dwAttrSuggest,pSize)	\
    (This)->lpVtbl -> SuggestSize(This,dwAttrSuggest,pSize)

#define IPlayControl_GetPosition(This,pPosition)	\
    (This)->lpVtbl -> GetPosition(This,pPosition)

#define IPlayControl_SetPosition(This,pPosition)	\
    (This)->lpVtbl -> SetPosition(This,pPosition)

#define IPlayControl_GetRect(This,pRect)	\
    (This)->lpVtbl -> GetRect(This,pRect)

#define IPlayControl_Advise(This,pAdvise)	\
    (This)->lpVtbl -> Advise(This,pAdvise)

#define IPlayControl_GetState(This)	\
    (This)->lpVtbl -> GetState(This)

#define IPlayControl_SetState(This,iState,iMask)	\
    (This)->lpVtbl -> SetState(This,iState,iMask)

#define IPlayControl_GetValLong(This)	\
    (This)->lpVtbl -> GetValLong(This)

#define IPlayControl_SetValLong(This,iValue)	\
    (This)->lpVtbl -> SetValLong(This,iValue)

#define IPlayControl_GetValFloat(This,dValue)	\
    (This)->lpVtbl -> GetValFloat(This,dValue)

#define IPlayControl_SetValFloat(This,dValue)	\
    (This)->lpVtbl -> SetValFloat(This,dValue)

#define IPlayControl_GetValStr(This,pszValue,cMaxChars)	\
    (This)->lpVtbl -> GetValStr(This,pszValue,cMaxChars)

#define IPlayControl_SetValStr(This,pszValue)	\
    (This)->lpVtbl -> SetValStr(This,pszValue)

#define IPlayControl_GetCtrlType(This)	\
    (This)->lpVtbl -> GetCtrlType(This)

#define IPlayControl_Repaint(This,prcPaint,bForceUpdate)	\
    (This)->lpVtbl -> Repaint(This,prcPaint,bForceUpdate)

#define IPlayControl_Remove(This)	\
    (This)->lpVtbl -> Remove(This)

#define IPlayControl_SetCustomBitmaps(This,dwIncluded,nBitmaps,pparyBitmaps)	\
    (This)->lpVtbl -> SetCustomBitmaps(This,dwIncluded,nBitmaps,pparyBitmaps)

#define IPlayControl_DrawToDIB(This,pBMIH,pBits,pUpdRect,pUpdOfs)	\
    (This)->lpVtbl -> DrawToDIB(This,pBMIH,pBits,pUpdRect,pUpdOfs)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE IPlayControl_SetLinkCtrl_Proxy( 
    IPlayControl __RPC_FAR * This,
    IPlayControl __RPC_FAR *ptcLinkCtrl,
    DWORD dwLinkType);


void __RPC_STUB IPlayControl_SetLinkCtrl_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IPlayControl_SetAttr_Proxy( 
    IPlayControl __RPC_FAR * This,
    DWORD dwAttr,
    DWORD dwValue);


void __RPC_STUB IPlayControl_SetAttr_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IPlayControl_GetAttr_Proxy( 
    IPlayControl __RPC_FAR * This,
    DWORD dwAttr,
    DWORD __RPC_FAR *pValue);


void __RPC_STUB IPlayControl_GetAttr_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IPlayControl_SaveAttributes_Proxy( 
    IPlayControl __RPC_FAR * This,
    IStorage __RPC_FAR *pStg);


void __RPC_STUB IPlayControl_SaveAttributes_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IPlayControl_LoadAttributes_Proxy( 
    IPlayControl __RPC_FAR * This,
    IStorage __RPC_FAR *pStg);


void __RPC_STUB IPlayControl_LoadAttributes_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IPlayControl_EnableRepaint_Proxy( 
    IPlayControl __RPC_FAR * This,
    long bEnable);


void __RPC_STUB IPlayControl_EnableRepaint_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IPlayControl_AddToParent_Proxy( 
    IPlayControl __RPC_FAR * This,
    HWND hWndParent,
    int x,
    int y);


void __RPC_STUB IPlayControl_AddToParent_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IPlayControl_GetSize_Proxy( 
    IPlayControl __RPC_FAR * This,
    DWORD dwAttrSize,
    SIZE __RPC_FAR *pSize);


void __RPC_STUB IPlayControl_GetSize_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IPlayControl_SuggestSize_Proxy( 
    IPlayControl __RPC_FAR * This,
    DWORD dwAttrSuggest,
    SIZE __RPC_FAR *pSize);


void __RPC_STUB IPlayControl_SuggestSize_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IPlayControl_GetPosition_Proxy( 
    IPlayControl __RPC_FAR * This,
    POINT __RPC_FAR *pPosition);


void __RPC_STUB IPlayControl_GetPosition_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IPlayControl_SetPosition_Proxy( 
    IPlayControl __RPC_FAR * This,
    POINT __RPC_FAR *pPosition);


void __RPC_STUB IPlayControl_SetPosition_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IPlayControl_GetRect_Proxy( 
    IPlayControl __RPC_FAR * This,
    RECT __RPC_FAR *pRect);


void __RPC_STUB IPlayControl_GetRect_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IPlayControl_Advise_Proxy( 
    IPlayControl __RPC_FAR * This,
    IPCtrlAdviseSink __RPC_FAR *pAdvise);


void __RPC_STUB IPlayControl_Advise_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


long STDMETHODCALLTYPE IPlayControl_GetState_Proxy( 
    IPlayControl __RPC_FAR * This);


void __RPC_STUB IPlayControl_GetState_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IPlayControl_SetState_Proxy( 
    IPlayControl __RPC_FAR * This,
    long iState,
    long iMask);


void __RPC_STUB IPlayControl_SetState_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


long STDMETHODCALLTYPE IPlayControl_GetValLong_Proxy( 
    IPlayControl __RPC_FAR * This);


void __RPC_STUB IPlayControl_GetValLong_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IPlayControl_SetValLong_Proxy( 
    IPlayControl __RPC_FAR * This,
    long iValue);


void __RPC_STUB IPlayControl_SetValLong_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IPlayControl_GetValFloat_Proxy( 
    IPlayControl __RPC_FAR * This,
    double __RPC_FAR *dValue);


void __RPC_STUB IPlayControl_GetValFloat_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IPlayControl_SetValFloat_Proxy( 
    IPlayControl __RPC_FAR * This,
    double dValue);


void __RPC_STUB IPlayControl_SetValFloat_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IPlayControl_GetValStr_Proxy( 
    IPlayControl __RPC_FAR * This,
    /* [string] */ LPSTR pszValue,
    long cMaxChars);


void __RPC_STUB IPlayControl_GetValStr_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IPlayControl_SetValStr_Proxy( 
    IPlayControl __RPC_FAR * This,
    LPSTR pszValue);


void __RPC_STUB IPlayControl_SetValStr_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


long STDMETHODCALLTYPE IPlayControl_GetCtrlType_Proxy( 
    IPlayControl __RPC_FAR * This);


void __RPC_STUB IPlayControl_GetCtrlType_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IPlayControl_Repaint_Proxy( 
    IPlayControl __RPC_FAR * This,
    RECT __RPC_FAR *prcPaint,
    unsigned long bForceUpdate);


void __RPC_STUB IPlayControl_Repaint_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IPlayControl_Remove_Proxy( 
    IPlayControl __RPC_FAR * This);


void __RPC_STUB IPlayControl_Remove_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IPlayControl_SetCustomBitmaps_Proxy( 
    IPlayControl __RPC_FAR * This,
    DWORD dwIncluded,
    int nBitmaps,
    IGXIntBitmap __RPC_FAR *__RPC_FAR *pparyBitmaps);


void __RPC_STUB IPlayControl_SetCustomBitmaps_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IPlayControl_DrawToDIB_Proxy( 
    IPlayControl __RPC_FAR * This,
    LPVOID pBMIH,
    BYTE __RPC_FAR *pBits,
    RECT __RPC_FAR *pUpdRect,
    POINT __RPC_FAR *pUpdOfs);


void __RPC_STUB IPlayControl_DrawToDIB_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IPlayControl_INTERFACE_DEFINED__ */


#ifndef __IPlayControlBitmaps_INTERFACE_DEFINED__
#define __IPlayControlBitmaps_INTERFACE_DEFINED__

/****************************************
 * Generated header for interface: IPlayControlBitmaps
 * at Tue Nov 23 05:02:12 1999
 * using MIDL 3.01.75
 ****************************************/
/* [uuid][object][local] */ 



EXTERN_C const IID IID_IPlayControlBitmaps;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    interface DECLSPEC_UUID("8335e437-ab3b-11ce-8468-0000b468276b")
    IPlayControlBitmaps : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE SetBitmap( 
            DWORD dwBMType,
            LPSTR filename) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IPlayControlBitmapsVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            IPlayControlBitmaps __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            IPlayControlBitmaps __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            IPlayControlBitmaps __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetBitmap )( 
            IPlayControlBitmaps __RPC_FAR * This,
            DWORD dwBMType,
            LPSTR filename);
        
        END_INTERFACE
    } IPlayControlBitmapsVtbl;

    interface IPlayControlBitmaps
    {
        CONST_VTBL struct IPlayControlBitmapsVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IPlayControlBitmaps_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IPlayControlBitmaps_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IPlayControlBitmaps_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IPlayControlBitmaps_SetBitmap(This,dwBMType,filename)	\
    (This)->lpVtbl -> SetBitmap(This,dwBMType,filename)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE IPlayControlBitmaps_SetBitmap_Proxy( 
    IPlayControlBitmaps __RPC_FAR * This,
    DWORD dwBMType,
    LPSTR filename);


void __RPC_STUB IPlayControlBitmaps_SetBitmap_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IPlayControlBitmaps_INTERFACE_DEFINED__ */


/****************************************
 * Generated header for interface: __MIDL_itf_plyctl_0096
 * at Tue Nov 23 05:02:12 1999
 * using MIDL 3.01.75
 ****************************************/
/* [local] */ 





extern RPC_IF_HANDLE __MIDL_itf_plyctl_0096_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_plyctl_0096_v0_0_s_ifspec;

#ifndef __IPlayPopupAdviseSink_INTERFACE_DEFINED__
#define __IPlayPopupAdviseSink_INTERFACE_DEFINED__

/****************************************
 * Generated header for interface: IPlayPopupAdviseSink
 * at Tue Nov 23 05:02:12 1999
 * using MIDL 3.01.75
 ****************************************/
/* [uuid][object][local] */ 



EXTERN_C const IID IID_IPlayPopupAdviseSink;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    interface DECLSPEC_UUID("8335e428-ab3b-11ce-8468-0000b468276b")
    IPlayPopupAdviseSink : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE OnSelection( 
            IPlayPopup __RPC_FAR *pPopup,
            int index) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE IsValid( 
            IPlayPopup __RPC_FAR *pPopup,
            int index) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IPlayPopupAdviseSinkVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            IPlayPopupAdviseSink __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            IPlayPopupAdviseSink __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            IPlayPopupAdviseSink __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *OnSelection )( 
            IPlayPopupAdviseSink __RPC_FAR * This,
            IPlayPopup __RPC_FAR *pPopup,
            int index);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *IsValid )( 
            IPlayPopupAdviseSink __RPC_FAR * This,
            IPlayPopup __RPC_FAR *pPopup,
            int index);
        
        END_INTERFACE
    } IPlayPopupAdviseSinkVtbl;

    interface IPlayPopupAdviseSink
    {
        CONST_VTBL struct IPlayPopupAdviseSinkVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IPlayPopupAdviseSink_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IPlayPopupAdviseSink_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IPlayPopupAdviseSink_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IPlayPopupAdviseSink_OnSelection(This,pPopup,index)	\
    (This)->lpVtbl -> OnSelection(This,pPopup,index)

#define IPlayPopupAdviseSink_IsValid(This,pPopup,index)	\
    (This)->lpVtbl -> IsValid(This,pPopup,index)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE IPlayPopupAdviseSink_OnSelection_Proxy( 
    IPlayPopupAdviseSink __RPC_FAR * This,
    IPlayPopup __RPC_FAR *pPopup,
    int index);


void __RPC_STUB IPlayPopupAdviseSink_OnSelection_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IPlayPopupAdviseSink_IsValid_Proxy( 
    IPlayPopupAdviseSink __RPC_FAR * This,
    IPlayPopup __RPC_FAR *pPopup,
    int index);


void __RPC_STUB IPlayPopupAdviseSink_IsValid_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IPlayPopupAdviseSink_INTERFACE_DEFINED__ */


#ifndef __IPlayPopup_INTERFACE_DEFINED__
#define __IPlayPopup_INTERFACE_DEFINED__

/****************************************
 * Generated header for interface: IPlayPopup
 * at Tue Nov 23 05:02:12 1999
 * using MIDL 3.01.75
 ****************************************/
/* [uuid][object][local] */ 



EXTERN_C const IID IID_IPlayPopup;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    interface DECLSPEC_UUID("8335e424-ab3b-11ce-8468-0000b468276b")
    IPlayPopup : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE AddString( 
            /* [string] */ LPSTR pszSelection,
            int nPos) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE CopyString( 
            int nPos,
            /* [string] */ LPSTR pszCopyDest,
            int nMaxChars) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE DelString( 
            int nPos) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE DoPopup( 
            int x,
            int y,
            int __RPC_FAR *pnResult) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetAttr( 
            ULONG dwAttr,
            DWORD dwValue) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetAttr( 
            ULONG dwAttr,
            DWORD __RPC_FAR *pdwValue) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Advise( 
            IPlayPopupAdviseSink __RPC_FAR *piAdviseSink) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE LinkPopup( 
            IPlayPopup __RPC_FAR *piPopup) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IPlayPopupVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            IPlayPopup __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            IPlayPopup __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            IPlayPopup __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *AddString )( 
            IPlayPopup __RPC_FAR * This,
            /* [string] */ LPSTR pszSelection,
            int nPos);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *CopyString )( 
            IPlayPopup __RPC_FAR * This,
            int nPos,
            /* [string] */ LPSTR pszCopyDest,
            int nMaxChars);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *DelString )( 
            IPlayPopup __RPC_FAR * This,
            int nPos);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *DoPopup )( 
            IPlayPopup __RPC_FAR * This,
            int x,
            int y,
            int __RPC_FAR *pnResult);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetAttr )( 
            IPlayPopup __RPC_FAR * This,
            ULONG dwAttr,
            DWORD dwValue);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetAttr )( 
            IPlayPopup __RPC_FAR * This,
            ULONG dwAttr,
            DWORD __RPC_FAR *pdwValue);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Advise )( 
            IPlayPopup __RPC_FAR * This,
            IPlayPopupAdviseSink __RPC_FAR *piAdviseSink);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *LinkPopup )( 
            IPlayPopup __RPC_FAR * This,
            IPlayPopup __RPC_FAR *piPopup);
        
        END_INTERFACE
    } IPlayPopupVtbl;

    interface IPlayPopup
    {
        CONST_VTBL struct IPlayPopupVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IPlayPopup_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IPlayPopup_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IPlayPopup_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IPlayPopup_AddString(This,pszSelection,nPos)	\
    (This)->lpVtbl -> AddString(This,pszSelection,nPos)

#define IPlayPopup_CopyString(This,nPos,pszCopyDest,nMaxChars)	\
    (This)->lpVtbl -> CopyString(This,nPos,pszCopyDest,nMaxChars)

#define IPlayPopup_DelString(This,nPos)	\
    (This)->lpVtbl -> DelString(This,nPos)

#define IPlayPopup_DoPopup(This,x,y,pnResult)	\
    (This)->lpVtbl -> DoPopup(This,x,y,pnResult)

#define IPlayPopup_SetAttr(This,dwAttr,dwValue)	\
    (This)->lpVtbl -> SetAttr(This,dwAttr,dwValue)

#define IPlayPopup_GetAttr(This,dwAttr,pdwValue)	\
    (This)->lpVtbl -> GetAttr(This,dwAttr,pdwValue)

#define IPlayPopup_Advise(This,piAdviseSink)	\
    (This)->lpVtbl -> Advise(This,piAdviseSink)

#define IPlayPopup_LinkPopup(This,piPopup)	\
    (This)->lpVtbl -> LinkPopup(This,piPopup)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE IPlayPopup_AddString_Proxy( 
    IPlayPopup __RPC_FAR * This,
    /* [string] */ LPSTR pszSelection,
    int nPos);


void __RPC_STUB IPlayPopup_AddString_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IPlayPopup_CopyString_Proxy( 
    IPlayPopup __RPC_FAR * This,
    int nPos,
    /* [string] */ LPSTR pszCopyDest,
    int nMaxChars);


void __RPC_STUB IPlayPopup_CopyString_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IPlayPopup_DelString_Proxy( 
    IPlayPopup __RPC_FAR * This,
    int nPos);


void __RPC_STUB IPlayPopup_DelString_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IPlayPopup_DoPopup_Proxy( 
    IPlayPopup __RPC_FAR * This,
    int x,
    int y,
    int __RPC_FAR *pnResult);


void __RPC_STUB IPlayPopup_DoPopup_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IPlayPopup_SetAttr_Proxy( 
    IPlayPopup __RPC_FAR * This,
    ULONG dwAttr,
    DWORD dwValue);


void __RPC_STUB IPlayPopup_SetAttr_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IPlayPopup_GetAttr_Proxy( 
    IPlayPopup __RPC_FAR * This,
    ULONG dwAttr,
    DWORD __RPC_FAR *pdwValue);


void __RPC_STUB IPlayPopup_GetAttr_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IPlayPopup_Advise_Proxy( 
    IPlayPopup __RPC_FAR * This,
    IPlayPopupAdviseSink __RPC_FAR *piAdviseSink);


void __RPC_STUB IPlayPopup_Advise_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IPlayPopup_LinkPopup_Proxy( 
    IPlayPopup __RPC_FAR * This,
    IPlayPopup __RPC_FAR *piPopup);


void __RPC_STUB IPlayPopup_LinkPopup_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IPlayPopup_INTERFACE_DEFINED__ */


#ifndef __IPlayPopup2_INTERFACE_DEFINED__
#define __IPlayPopup2_INTERFACE_DEFINED__

/****************************************
 * Generated header for interface: IPlayPopup2
 * at Tue Nov 23 05:02:12 1999
 * using MIDL 3.01.75
 ****************************************/
/* [uuid][object][local] */ 



EXTERN_C const IID IID_IPlayPopup2;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    interface DECLSPEC_UUID("8335e609-ab3b-11ce-8468-0000b468276b")
    IPlayPopup2 : public IPlayPopup
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE SetMutuallyExclusive( 
            int nDefault) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE ToggleState( 
            int nSelection) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetToggleState( 
            int nSelection,
            BOOL bState) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetToggleState( 
            int nSelection,
            BOOL __RPC_FAR *bResult) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetCheckMark( 
            BOOL bOn) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE DisableChoice( 
            int nSelection,
            BOOL bOn) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE EnableCheckmark( 
            int nSelection,
            BOOL bOn) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IPlayPopup2Vtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            IPlayPopup2 __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            IPlayPopup2 __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            IPlayPopup2 __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *AddString )( 
            IPlayPopup2 __RPC_FAR * This,
            /* [string] */ LPSTR pszSelection,
            int nPos);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *CopyString )( 
            IPlayPopup2 __RPC_FAR * This,
            int nPos,
            /* [string] */ LPSTR pszCopyDest,
            int nMaxChars);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *DelString )( 
            IPlayPopup2 __RPC_FAR * This,
            int nPos);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *DoPopup )( 
            IPlayPopup2 __RPC_FAR * This,
            int x,
            int y,
            int __RPC_FAR *pnResult);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetAttr )( 
            IPlayPopup2 __RPC_FAR * This,
            ULONG dwAttr,
            DWORD dwValue);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetAttr )( 
            IPlayPopup2 __RPC_FAR * This,
            ULONG dwAttr,
            DWORD __RPC_FAR *pdwValue);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Advise )( 
            IPlayPopup2 __RPC_FAR * This,
            IPlayPopupAdviseSink __RPC_FAR *piAdviseSink);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *LinkPopup )( 
            IPlayPopup2 __RPC_FAR * This,
            IPlayPopup __RPC_FAR *piPopup);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetMutuallyExclusive )( 
            IPlayPopup2 __RPC_FAR * This,
            int nDefault);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *ToggleState )( 
            IPlayPopup2 __RPC_FAR * This,
            int nSelection);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetToggleState )( 
            IPlayPopup2 __RPC_FAR * This,
            int nSelection,
            BOOL bState);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetToggleState )( 
            IPlayPopup2 __RPC_FAR * This,
            int nSelection,
            BOOL __RPC_FAR *bResult);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetCheckMark )( 
            IPlayPopup2 __RPC_FAR * This,
            BOOL bOn);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *DisableChoice )( 
            IPlayPopup2 __RPC_FAR * This,
            int nSelection,
            BOOL bOn);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *EnableCheckmark )( 
            IPlayPopup2 __RPC_FAR * This,
            int nSelection,
            BOOL bOn);
        
        END_INTERFACE
    } IPlayPopup2Vtbl;

    interface IPlayPopup2
    {
        CONST_VTBL struct IPlayPopup2Vtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IPlayPopup2_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IPlayPopup2_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IPlayPopup2_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IPlayPopup2_AddString(This,pszSelection,nPos)	\
    (This)->lpVtbl -> AddString(This,pszSelection,nPos)

#define IPlayPopup2_CopyString(This,nPos,pszCopyDest,nMaxChars)	\
    (This)->lpVtbl -> CopyString(This,nPos,pszCopyDest,nMaxChars)

#define IPlayPopup2_DelString(This,nPos)	\
    (This)->lpVtbl -> DelString(This,nPos)

#define IPlayPopup2_DoPopup(This,x,y,pnResult)	\
    (This)->lpVtbl -> DoPopup(This,x,y,pnResult)

#define IPlayPopup2_SetAttr(This,dwAttr,dwValue)	\
    (This)->lpVtbl -> SetAttr(This,dwAttr,dwValue)

#define IPlayPopup2_GetAttr(This,dwAttr,pdwValue)	\
    (This)->lpVtbl -> GetAttr(This,dwAttr,pdwValue)

#define IPlayPopup2_Advise(This,piAdviseSink)	\
    (This)->lpVtbl -> Advise(This,piAdviseSink)

#define IPlayPopup2_LinkPopup(This,piPopup)	\
    (This)->lpVtbl -> LinkPopup(This,piPopup)


#define IPlayPopup2_SetMutuallyExclusive(This,nDefault)	\
    (This)->lpVtbl -> SetMutuallyExclusive(This,nDefault)

#define IPlayPopup2_ToggleState(This,nSelection)	\
    (This)->lpVtbl -> ToggleState(This,nSelection)

#define IPlayPopup2_SetToggleState(This,nSelection,bState)	\
    (This)->lpVtbl -> SetToggleState(This,nSelection,bState)

#define IPlayPopup2_GetToggleState(This,nSelection,bResult)	\
    (This)->lpVtbl -> GetToggleState(This,nSelection,bResult)

#define IPlayPopup2_SetCheckMark(This,bOn)	\
    (This)->lpVtbl -> SetCheckMark(This,bOn)

#define IPlayPopup2_DisableChoice(This,nSelection,bOn)	\
    (This)->lpVtbl -> DisableChoice(This,nSelection,bOn)

#define IPlayPopup2_EnableCheckmark(This,nSelection,bOn)	\
    (This)->lpVtbl -> EnableCheckmark(This,nSelection,bOn)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE IPlayPopup2_SetMutuallyExclusive_Proxy( 
    IPlayPopup2 __RPC_FAR * This,
    int nDefault);


void __RPC_STUB IPlayPopup2_SetMutuallyExclusive_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IPlayPopup2_ToggleState_Proxy( 
    IPlayPopup2 __RPC_FAR * This,
    int nSelection);


void __RPC_STUB IPlayPopup2_ToggleState_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IPlayPopup2_SetToggleState_Proxy( 
    IPlayPopup2 __RPC_FAR * This,
    int nSelection,
    BOOL bState);


void __RPC_STUB IPlayPopup2_SetToggleState_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IPlayPopup2_GetToggleState_Proxy( 
    IPlayPopup2 __RPC_FAR * This,
    int nSelection,
    BOOL __RPC_FAR *bResult);


void __RPC_STUB IPlayPopup2_GetToggleState_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IPlayPopup2_SetCheckMark_Proxy( 
    IPlayPopup2 __RPC_FAR * This,
    BOOL bOn);


void __RPC_STUB IPlayPopup2_SetCheckMark_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IPlayPopup2_DisableChoice_Proxy( 
    IPlayPopup2 __RPC_FAR * This,
    int nSelection,
    BOOL bOn);


void __RPC_STUB IPlayPopup2_DisableChoice_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IPlayPopup2_EnableCheckmark_Proxy( 
    IPlayPopup2 __RPC_FAR * This,
    int nSelection,
    BOOL bOn);


void __RPC_STUB IPlayPopup2_EnableCheckmark_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IPlayPopup2_INTERFACE_DEFINED__ */


#ifndef __IPlayMessageBox_INTERFACE_DEFINED__
#define __IPlayMessageBox_INTERFACE_DEFINED__

/****************************************
 * Generated header for interface: IPlayMessageBox
 * at Tue Nov 23 05:02:12 1999
 * using MIDL 3.01.75
 ****************************************/
/* [uuid][object][local] */ 



EXTERN_C const IID IID_IPlayMessageBox;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    interface DECLSPEC_UUID("8335e431-ab3b-11ce-8468-0000b468276b")
    IPlayMessageBox : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE DoMessageBox( 
            int x,
            int y,
            DWORD dwMask,
            DWORD __RPC_FAR *pResult) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetMessage( 
            LPSTR pszFmt,
            ...) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetMessageV( 
            LPSTR pszFmt,
            LPSTR vaArgList) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetButtonText( 
            DWORD dwButton,
            LPSTR pText) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IPlayMessageBoxVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            IPlayMessageBox __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            IPlayMessageBox __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            IPlayMessageBox __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *DoMessageBox )( 
            IPlayMessageBox __RPC_FAR * This,
            int x,
            int y,
            DWORD dwMask,
            DWORD __RPC_FAR *pResult);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetMessage )( 
            IPlayMessageBox __RPC_FAR * This,
            LPSTR pszFmt,
            ...);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetMessageV )( 
            IPlayMessageBox __RPC_FAR * This,
            LPSTR pszFmt,
            LPSTR vaArgList);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetButtonText )( 
            IPlayMessageBox __RPC_FAR * This,
            DWORD dwButton,
            LPSTR pText);
        
        END_INTERFACE
    } IPlayMessageBoxVtbl;

    interface IPlayMessageBox
    {
        CONST_VTBL struct IPlayMessageBoxVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IPlayMessageBox_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IPlayMessageBox_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IPlayMessageBox_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IPlayMessageBox_DoMessageBox(This,x,y,dwMask,pResult)	\
    (This)->lpVtbl -> DoMessageBox(This,x,y,dwMask,pResult)

#define IPlayMessageBox_SetMessage(This,pszFmt,...)	\
    (This)->lpVtbl -> SetMessage(This,pszFmt,...)

#define IPlayMessageBox_SetMessageV(This,pszFmt,vaArgList)	\
    (This)->lpVtbl -> SetMessageV(This,pszFmt,vaArgList)

#define IPlayMessageBox_SetButtonText(This,dwButton,pText)	\
    (This)->lpVtbl -> SetButtonText(This,dwButton,pText)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE IPlayMessageBox_DoMessageBox_Proxy( 
    IPlayMessageBox __RPC_FAR * This,
    int x,
    int y,
    DWORD dwMask,
    DWORD __RPC_FAR *pResult);


void __RPC_STUB IPlayMessageBox_DoMessageBox_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IPlayMessageBox_SetMessage_Proxy( 
    IPlayMessageBox __RPC_FAR * This,
    LPSTR pszFmt,
    ...);


void __RPC_STUB IPlayMessageBox_SetMessage_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IPlayMessageBox_SetMessageV_Proxy( 
    IPlayMessageBox __RPC_FAR * This,
    LPSTR pszFmt,
    LPSTR vaArgList);


void __RPC_STUB IPlayMessageBox_SetMessageV_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IPlayMessageBox_SetButtonText_Proxy( 
    IPlayMessageBox __RPC_FAR * This,
    DWORD dwButton,
    LPSTR pText);


void __RPC_STUB IPlayMessageBox_SetButtonText_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IPlayMessageBox_INTERFACE_DEFINED__ */


#ifndef __IPlayMessageBox2_INTERFACE_DEFINED__
#define __IPlayMessageBox2_INTERFACE_DEFINED__

/****************************************
 * Generated header for interface: IPlayMessageBox2
 * at Tue Nov 23 05:02:12 1999
 * using MIDL 3.01.75
 ****************************************/
/* [uuid][object][local] */ 



EXTERN_C const IID IID_IPlayMessageBox2;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    interface DECLSPEC_UUID("8335e438-ab3b-11ce-8468-0000b468276b")
    IPlayMessageBox2 : public IPlayMessageBox
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE DoMessageBox2( 
            HWND hWndOwner,
            int x,
            int y,
            DWORD dwMask,
            DWORD __RPC_FAR *pResult) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IPlayMessageBox2Vtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            IPlayMessageBox2 __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            IPlayMessageBox2 __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            IPlayMessageBox2 __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *DoMessageBox )( 
            IPlayMessageBox2 __RPC_FAR * This,
            int x,
            int y,
            DWORD dwMask,
            DWORD __RPC_FAR *pResult);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetMessage )( 
            IPlayMessageBox2 __RPC_FAR * This,
            LPSTR pszFmt,
            ...);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetMessageV )( 
            IPlayMessageBox2 __RPC_FAR * This,
            LPSTR pszFmt,
            LPSTR vaArgList);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetButtonText )( 
            IPlayMessageBox2 __RPC_FAR * This,
            DWORD dwButton,
            LPSTR pText);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *DoMessageBox2 )( 
            IPlayMessageBox2 __RPC_FAR * This,
            HWND hWndOwner,
            int x,
            int y,
            DWORD dwMask,
            DWORD __RPC_FAR *pResult);
        
        END_INTERFACE
    } IPlayMessageBox2Vtbl;

    interface IPlayMessageBox2
    {
        CONST_VTBL struct IPlayMessageBox2Vtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IPlayMessageBox2_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IPlayMessageBox2_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IPlayMessageBox2_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IPlayMessageBox2_DoMessageBox(This,x,y,dwMask,pResult)	\
    (This)->lpVtbl -> DoMessageBox(This,x,y,dwMask,pResult)

#define IPlayMessageBox2_SetMessage(This,pszFmt,...)	\
    (This)->lpVtbl -> SetMessage(This,pszFmt,...)

#define IPlayMessageBox2_SetMessageV(This,pszFmt,vaArgList)	\
    (This)->lpVtbl -> SetMessageV(This,pszFmt,vaArgList)

#define IPlayMessageBox2_SetButtonText(This,dwButton,pText)	\
    (This)->lpVtbl -> SetButtonText(This,dwButton,pText)


#define IPlayMessageBox2_DoMessageBox2(This,hWndOwner,x,y,dwMask,pResult)	\
    (This)->lpVtbl -> DoMessageBox2(This,hWndOwner,x,y,dwMask,pResult)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE IPlayMessageBox2_DoMessageBox2_Proxy( 
    IPlayMessageBox2 __RPC_FAR * This,
    HWND hWndOwner,
    int x,
    int y,
    DWORD dwMask,
    DWORD __RPC_FAR *pResult);


void __RPC_STUB IPlayMessageBox2_DoMessageBox2_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IPlayMessageBox2_INTERFACE_DEFINED__ */


/* Additional Prototypes for ALL interfaces */

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif
