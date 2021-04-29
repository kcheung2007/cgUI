/* this ALWAYS GENERATED file contains the definitions for the interfaces */


/* File created by MIDL compiler version 3.01.75 */
/* at Tue Nov 23 05:02:13 1999
 */
/* Compiler settings for plytxt.idl:
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

#ifndef __plytxt_h__
#define __plytxt_h__

#ifdef __cplusplus
extern "C"{
#endif 

/* Forward Declarations */ 

#ifndef __IPlayFontInfo_FWD_DEFINED__
#define __IPlayFontInfo_FWD_DEFINED__
typedef interface IPlayFontInfo IPlayFontInfo;
#endif 	/* __IPlayFontInfo_FWD_DEFINED__ */


#ifndef __IPlayText_FWD_DEFINED__
#define __IPlayText_FWD_DEFINED__
typedef interface IPlayText IPlayText;
#endif 	/* __IPlayText_FWD_DEFINED__ */


#ifndef __IPlayEditText_FWD_DEFINED__
#define __IPlayEditText_FWD_DEFINED__
typedef interface IPlayEditText IPlayEditText;
#endif 	/* __IPlayEditText_FWD_DEFINED__ */


/* header files for imported files */
#include "unknwn.h"
#include "gxlate.h"

void __RPC_FAR * __RPC_USER MIDL_user_allocate(size_t);
void __RPC_USER MIDL_user_free( void __RPC_FAR * ); 

#ifndef __IPlayFontInfo_INTERFACE_DEFINED__
#define __IPlayFontInfo_INTERFACE_DEFINED__

/****************************************
 * Generated header for interface: IPlayFontInfo
 * at Tue Nov 23 05:02:13 1999
 * using MIDL 3.01.75
 ****************************************/
/* [uuid][object][local] */ 



EXTERN_C const IID IID_IPlayFontInfo;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    interface DECLSPEC_UUID("8335e426-ab3b-11ce-8468-0000b468276b")
    IPlayFontInfo : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE GetName( 
            /* [string][out] */ LPSTR pszName) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetSizes( 
            DWORD __RPC_FAR *plaSize,
            DWORD lTableSize) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetStyles( 
            DWORD __RPC_FAR *plStyles) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetExtendedStyles( 
            DWORD __RPC_FAR *plExtStyles) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IPlayFontInfoVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            IPlayFontInfo __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            IPlayFontInfo __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            IPlayFontInfo __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetName )( 
            IPlayFontInfo __RPC_FAR * This,
            /* [string][out] */ LPSTR pszName);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetSizes )( 
            IPlayFontInfo __RPC_FAR * This,
            DWORD __RPC_FAR *plaSize,
            DWORD lTableSize);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetStyles )( 
            IPlayFontInfo __RPC_FAR * This,
            DWORD __RPC_FAR *plStyles);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetExtendedStyles )( 
            IPlayFontInfo __RPC_FAR * This,
            DWORD __RPC_FAR *plExtStyles);
        
        END_INTERFACE
    } IPlayFontInfoVtbl;

    interface IPlayFontInfo
    {
        CONST_VTBL struct IPlayFontInfoVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IPlayFontInfo_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IPlayFontInfo_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IPlayFontInfo_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IPlayFontInfo_GetName(This,pszName)	\
    (This)->lpVtbl -> GetName(This,pszName)

#define IPlayFontInfo_GetSizes(This,plaSize,lTableSize)	\
    (This)->lpVtbl -> GetSizes(This,plaSize,lTableSize)

#define IPlayFontInfo_GetStyles(This,plStyles)	\
    (This)->lpVtbl -> GetStyles(This,plStyles)

#define IPlayFontInfo_GetExtendedStyles(This,plExtStyles)	\
    (This)->lpVtbl -> GetExtendedStyles(This,plExtStyles)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE IPlayFontInfo_GetName_Proxy( 
    IPlayFontInfo __RPC_FAR * This,
    /* [string][out] */ LPSTR pszName);


void __RPC_STUB IPlayFontInfo_GetName_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IPlayFontInfo_GetSizes_Proxy( 
    IPlayFontInfo __RPC_FAR * This,
    DWORD __RPC_FAR *plaSize,
    DWORD lTableSize);


void __RPC_STUB IPlayFontInfo_GetSizes_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IPlayFontInfo_GetStyles_Proxy( 
    IPlayFontInfo __RPC_FAR * This,
    DWORD __RPC_FAR *plStyles);


void __RPC_STUB IPlayFontInfo_GetStyles_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IPlayFontInfo_GetExtendedStyles_Proxy( 
    IPlayFontInfo __RPC_FAR * This,
    DWORD __RPC_FAR *plExtStyles);


void __RPC_STUB IPlayFontInfo_GetExtendedStyles_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IPlayFontInfo_INTERFACE_DEFINED__ */


#ifndef __IPlayText_INTERFACE_DEFINED__
#define __IPlayText_INTERFACE_DEFINED__

/****************************************
 * Generated header for interface: IPlayText
 * at Tue Nov 23 05:02:13 1999
 * using MIDL 3.01.75
 ****************************************/
/* [uuid][object][local] */ 



EXTERN_C const IID IID_IPlayText;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    interface DECLSPEC_UUID("8335e425-ab3b-11ce-8468-0000b468276b")
    IPlayText : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE EnumFonts( 
            IEnumUnknown __RPC_FAR *__RPC_FAR *ppiEnumUnk) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetText( 
            /* [string][in] */ LPSTR pszText) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetFont( 
            /* [string][in] */ LPSTR pszFontname,
            DWORD dwSize,
            DWORD dwStyle) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetExtendedStyle( 
            DWORD dwStyle,
            DWORD dwValue) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE QueryFontInfo( 
            IPlayFontInfo __RPC_FAR *__RPC_FAR *ppiFontInfo) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetSize( 
            /* [out] */ SIZE __RPC_FAR *pSize) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetPartialSize( 
            /* [in] */ DWORD start,
            /* [in] */ DWORD len,
            /* [out] */ SIZE __RPC_FAR *pSize) = 0;
        
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
        
        virtual HRESULT STDMETHODCALLTYPE GetText( 
            /* [out] */ DWORD __RPC_FAR *pdwReqBufSize,
            /* [string][out] */ LPSTR pszBuffer,
            DWORD dwBufSize) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IPlayTextVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            IPlayText __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            IPlayText __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            IPlayText __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *EnumFonts )( 
            IPlayText __RPC_FAR * This,
            IEnumUnknown __RPC_FAR *__RPC_FAR *ppiEnumUnk);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetText )( 
            IPlayText __RPC_FAR * This,
            /* [string][in] */ LPSTR pszText);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetFont )( 
            IPlayText __RPC_FAR * This,
            /* [string][in] */ LPSTR pszFontname,
            DWORD dwSize,
            DWORD dwStyle);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetExtendedStyle )( 
            IPlayText __RPC_FAR * This,
            DWORD dwStyle,
            DWORD dwValue);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryFontInfo )( 
            IPlayText __RPC_FAR * This,
            IPlayFontInfo __RPC_FAR *__RPC_FAR *ppiFontInfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetSize )( 
            IPlayText __RPC_FAR * This,
            /* [out] */ SIZE __RPC_FAR *pSize);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetPartialSize )( 
            IPlayText __RPC_FAR * This,
            /* [in] */ DWORD start,
            /* [in] */ DWORD len,
            /* [out] */ SIZE __RPC_FAR *pSize);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *ForceGenerate )( 
            IPlayText __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetColor )( 
            IPlayText __RPC_FAR * This,
            DWORD dwColor);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetTransparency )( 
            IPlayText __RPC_FAR * This,
            DWORD dwTrans);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *DrawToDC )( 
            IPlayText __RPC_FAR * This,
            HDC hDC,
            ULONG dx,
            ULONG dy);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *DrawToBitmap )( 
            IPlayText __RPC_FAR * This,
            IGXIntBitmap __RPC_FAR *piBitmap,
            ULONG dx,
            ULONG dy);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *DrawToDIB )( 
            IPlayText __RPC_FAR * This,
            LPVOID pBMIH,
            unsigned char __RPC_FAR *pBits,
            ULONG dx,
            ULONG dy);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *ReleaseMask )( 
            IPlayText __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetText )( 
            IPlayText __RPC_FAR * This,
            /* [out] */ DWORD __RPC_FAR *pdwReqBufSize,
            /* [string][out] */ LPSTR pszBuffer,
            DWORD dwBufSize);
        
        END_INTERFACE
    } IPlayTextVtbl;

    interface IPlayText
    {
        CONST_VTBL struct IPlayTextVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IPlayText_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IPlayText_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IPlayText_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IPlayText_EnumFonts(This,ppiEnumUnk)	\
    (This)->lpVtbl -> EnumFonts(This,ppiEnumUnk)

#define IPlayText_SetText(This,pszText)	\
    (This)->lpVtbl -> SetText(This,pszText)

#define IPlayText_SetFont(This,pszFontname,dwSize,dwStyle)	\
    (This)->lpVtbl -> SetFont(This,pszFontname,dwSize,dwStyle)

#define IPlayText_SetExtendedStyle(This,dwStyle,dwValue)	\
    (This)->lpVtbl -> SetExtendedStyle(This,dwStyle,dwValue)

#define IPlayText_QueryFontInfo(This,ppiFontInfo)	\
    (This)->lpVtbl -> QueryFontInfo(This,ppiFontInfo)

#define IPlayText_GetSize(This,pSize)	\
    (This)->lpVtbl -> GetSize(This,pSize)

#define IPlayText_GetPartialSize(This,start,len,pSize)	\
    (This)->lpVtbl -> GetPartialSize(This,start,len,pSize)

#define IPlayText_ForceGenerate(This)	\
    (This)->lpVtbl -> ForceGenerate(This)

#define IPlayText_SetColor(This,dwColor)	\
    (This)->lpVtbl -> SetColor(This,dwColor)

#define IPlayText_SetTransparency(This,dwTrans)	\
    (This)->lpVtbl -> SetTransparency(This,dwTrans)

#define IPlayText_DrawToDC(This,hDC,dx,dy)	\
    (This)->lpVtbl -> DrawToDC(This,hDC,dx,dy)

#define IPlayText_DrawToBitmap(This,piBitmap,dx,dy)	\
    (This)->lpVtbl -> DrawToBitmap(This,piBitmap,dx,dy)

#define IPlayText_DrawToDIB(This,pBMIH,pBits,dx,dy)	\
    (This)->lpVtbl -> DrawToDIB(This,pBMIH,pBits,dx,dy)

#define IPlayText_ReleaseMask(This)	\
    (This)->lpVtbl -> ReleaseMask(This)

#define IPlayText_GetText(This,pdwReqBufSize,pszBuffer,dwBufSize)	\
    (This)->lpVtbl -> GetText(This,pdwReqBufSize,pszBuffer,dwBufSize)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE IPlayText_EnumFonts_Proxy( 
    IPlayText __RPC_FAR * This,
    IEnumUnknown __RPC_FAR *__RPC_FAR *ppiEnumUnk);


void __RPC_STUB IPlayText_EnumFonts_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IPlayText_SetText_Proxy( 
    IPlayText __RPC_FAR * This,
    /* [string][in] */ LPSTR pszText);


void __RPC_STUB IPlayText_SetText_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IPlayText_SetFont_Proxy( 
    IPlayText __RPC_FAR * This,
    /* [string][in] */ LPSTR pszFontname,
    DWORD dwSize,
    DWORD dwStyle);


void __RPC_STUB IPlayText_SetFont_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IPlayText_SetExtendedStyle_Proxy( 
    IPlayText __RPC_FAR * This,
    DWORD dwStyle,
    DWORD dwValue);


void __RPC_STUB IPlayText_SetExtendedStyle_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IPlayText_QueryFontInfo_Proxy( 
    IPlayText __RPC_FAR * This,
    IPlayFontInfo __RPC_FAR *__RPC_FAR *ppiFontInfo);


void __RPC_STUB IPlayText_QueryFontInfo_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IPlayText_GetSize_Proxy( 
    IPlayText __RPC_FAR * This,
    /* [out] */ SIZE __RPC_FAR *pSize);


void __RPC_STUB IPlayText_GetSize_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IPlayText_GetPartialSize_Proxy( 
    IPlayText __RPC_FAR * This,
    /* [in] */ DWORD start,
    /* [in] */ DWORD len,
    /* [out] */ SIZE __RPC_FAR *pSize);


void __RPC_STUB IPlayText_GetPartialSize_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IPlayText_ForceGenerate_Proxy( 
    IPlayText __RPC_FAR * This);


void __RPC_STUB IPlayText_ForceGenerate_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IPlayText_SetColor_Proxy( 
    IPlayText __RPC_FAR * This,
    DWORD dwColor);


void __RPC_STUB IPlayText_SetColor_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IPlayText_SetTransparency_Proxy( 
    IPlayText __RPC_FAR * This,
    DWORD dwTrans);


void __RPC_STUB IPlayText_SetTransparency_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IPlayText_DrawToDC_Proxy( 
    IPlayText __RPC_FAR * This,
    HDC hDC,
    ULONG dx,
    ULONG dy);


void __RPC_STUB IPlayText_DrawToDC_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IPlayText_DrawToBitmap_Proxy( 
    IPlayText __RPC_FAR * This,
    IGXIntBitmap __RPC_FAR *piBitmap,
    ULONG dx,
    ULONG dy);


void __RPC_STUB IPlayText_DrawToBitmap_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IPlayText_DrawToDIB_Proxy( 
    IPlayText __RPC_FAR * This,
    LPVOID pBMIH,
    unsigned char __RPC_FAR *pBits,
    ULONG dx,
    ULONG dy);


void __RPC_STUB IPlayText_DrawToDIB_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IPlayText_ReleaseMask_Proxy( 
    IPlayText __RPC_FAR * This);


void __RPC_STUB IPlayText_ReleaseMask_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IPlayText_GetText_Proxy( 
    IPlayText __RPC_FAR * This,
    /* [out] */ DWORD __RPC_FAR *pdwReqBufSize,
    /* [string][out] */ LPSTR pszBuffer,
    DWORD dwBufSize);


void __RPC_STUB IPlayText_GetText_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IPlayText_INTERFACE_DEFINED__ */


#ifndef __IPlayEditText_INTERFACE_DEFINED__
#define __IPlayEditText_INTERFACE_DEFINED__

/****************************************
 * Generated header for interface: IPlayEditText
 * at Tue Nov 23 05:02:13 1999
 * using MIDL 3.01.75
 ****************************************/
/* [uuid][object][local] */ 



EXTERN_C const IID IID_IPlayEditText;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    interface DECLSPEC_UUID("8335e402-ab3b-11ce-8468-0000b468276b")
    IPlayEditText : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE PutInWindow( 
            HWND hWnd,
            int x,
            int y,
            int width,
            int height) = 0;
        
        virtual BOOL STDMETHODCALLTYPE SetMaxCharacters( 
            DWORD dwNumChars) = 0;
        
        virtual BOOL STDMETHODCALLTYPE SetSize( 
            SIZE __RPC_FAR *szText) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetTextAttributes( 
            LPSTR pszFontName,
            short fontSize,
            short fontStyle) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetColor( 
            DWORD dwNormalColor,
            DWORD dwHighColor,
            DWORD dwExciteColor,
            DWORD dwGhostColor) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetText( 
            LPSTR pszText) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetText( 
            LPSTR pszText,
            DWORD dwNumChars) = 0;
        
        virtual BOOL STDMETHODCALLTYPE SetCaret( 
            DWORD dwLocation) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetEditType( 
            DWORD dwType) = 0;
        
        virtual void STDMETHODCALLTYPE UpdateRect( 
            BITMAPINFOHEADER __RPC_FAR *pHeader,
            BYTE __RPC_FAR *pBits,
            RECT __RPC_FAR *pClip,
            POINT __RPC_FAR *pOfs) = 0;
        
        virtual void STDMETHODCALLTYPE ExciteMe( 
            BOOL bTurnOn) = 0;
        
        virtual void STDMETHODCALLTYPE GhostMe( 
            BOOL bTurnOn) = 0;
        
        virtual void STDMETHODCALLTYPE GetSize( 
            SIZE __RPC_FAR *sz) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Reposition( 
            int x,
            int y,
            int width,
            int height) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetTextAttributes( 
            LPSTR pszFontName,
            DWORD numChars,
            short __RPC_FAR *fontSize,
            short __RPC_FAR *fontStyle) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetTextColors( 
            DWORD __RPC_FAR *dwNormalColor,
            DWORD __RPC_FAR *dwHighColor,
            DWORD __RPC_FAR *dwExciteColor) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetShowingText( 
            DWORD dwPosition,
            BOOL bStart) = 0;
        
        virtual DWORD STDMETHODCALLTYPE GetTextLength( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE DrawToDC( 
            HDC hDC,
            long x,
            long y) = 0;
        
        virtual void STDMETHODCALLTYPE InvalidateCache( void) = 0;
        
        virtual void STDMETHODCALLTYPE DisableMe( 
            BOOL bTurnOn) = 0;
        
        virtual void STDMETHODCALLTYPE MakeCache( 
            BITMAPINFOHEADER __RPC_FAR *pHeader,
            BYTE __RPC_FAR *pBits,
            POINT __RPC_FAR *pOfs) = 0;
        
        virtual void STDMETHODCALLTYPE DrawToDIB( 
            BITMAPINFOHEADER __RPC_FAR *pHeader,
            BYTE __RPC_FAR *pBits,
            POINT __RPC_FAR *pOfs) = 0;
        
        virtual DWORD STDMETHODCALLTYPE GetTextPixelLength( void) = 0;
        
        virtual DWORD STDMETHODCALLTYPE GetTextPixelLengthShowing( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Select( 
            BOOL bSelect,
            DWORD dwOption) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IPlayEditTextVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            IPlayEditText __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            IPlayEditText __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            IPlayEditText __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *PutInWindow )( 
            IPlayEditText __RPC_FAR * This,
            HWND hWnd,
            int x,
            int y,
            int width,
            int height);
        
        BOOL ( STDMETHODCALLTYPE __RPC_FAR *SetMaxCharacters )( 
            IPlayEditText __RPC_FAR * This,
            DWORD dwNumChars);
        
        BOOL ( STDMETHODCALLTYPE __RPC_FAR *SetSize )( 
            IPlayEditText __RPC_FAR * This,
            SIZE __RPC_FAR *szText);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetTextAttributes )( 
            IPlayEditText __RPC_FAR * This,
            LPSTR pszFontName,
            short fontSize,
            short fontStyle);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetColor )( 
            IPlayEditText __RPC_FAR * This,
            DWORD dwNormalColor,
            DWORD dwHighColor,
            DWORD dwExciteColor,
            DWORD dwGhostColor);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetText )( 
            IPlayEditText __RPC_FAR * This,
            LPSTR pszText);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetText )( 
            IPlayEditText __RPC_FAR * This,
            LPSTR pszText,
            DWORD dwNumChars);
        
        BOOL ( STDMETHODCALLTYPE __RPC_FAR *SetCaret )( 
            IPlayEditText __RPC_FAR * This,
            DWORD dwLocation);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetEditType )( 
            IPlayEditText __RPC_FAR * This,
            DWORD dwType);
        
        void ( STDMETHODCALLTYPE __RPC_FAR *UpdateRect )( 
            IPlayEditText __RPC_FAR * This,
            BITMAPINFOHEADER __RPC_FAR *pHeader,
            BYTE __RPC_FAR *pBits,
            RECT __RPC_FAR *pClip,
            POINT __RPC_FAR *pOfs);
        
        void ( STDMETHODCALLTYPE __RPC_FAR *ExciteMe )( 
            IPlayEditText __RPC_FAR * This,
            BOOL bTurnOn);
        
        void ( STDMETHODCALLTYPE __RPC_FAR *GhostMe )( 
            IPlayEditText __RPC_FAR * This,
            BOOL bTurnOn);
        
        void ( STDMETHODCALLTYPE __RPC_FAR *GetSize )( 
            IPlayEditText __RPC_FAR * This,
            SIZE __RPC_FAR *sz);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Reposition )( 
            IPlayEditText __RPC_FAR * This,
            int x,
            int y,
            int width,
            int height);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTextAttributes )( 
            IPlayEditText __RPC_FAR * This,
            LPSTR pszFontName,
            DWORD numChars,
            short __RPC_FAR *fontSize,
            short __RPC_FAR *fontStyle);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTextColors )( 
            IPlayEditText __RPC_FAR * This,
            DWORD __RPC_FAR *dwNormalColor,
            DWORD __RPC_FAR *dwHighColor,
            DWORD __RPC_FAR *dwExciteColor);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetShowingText )( 
            IPlayEditText __RPC_FAR * This,
            DWORD dwPosition,
            BOOL bStart);
        
        DWORD ( STDMETHODCALLTYPE __RPC_FAR *GetTextLength )( 
            IPlayEditText __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *DrawToDC )( 
            IPlayEditText __RPC_FAR * This,
            HDC hDC,
            long x,
            long y);
        
        void ( STDMETHODCALLTYPE __RPC_FAR *InvalidateCache )( 
            IPlayEditText __RPC_FAR * This);
        
        void ( STDMETHODCALLTYPE __RPC_FAR *DisableMe )( 
            IPlayEditText __RPC_FAR * This,
            BOOL bTurnOn);
        
        void ( STDMETHODCALLTYPE __RPC_FAR *MakeCache )( 
            IPlayEditText __RPC_FAR * This,
            BITMAPINFOHEADER __RPC_FAR *pHeader,
            BYTE __RPC_FAR *pBits,
            POINT __RPC_FAR *pOfs);
        
        void ( STDMETHODCALLTYPE __RPC_FAR *DrawToDIB )( 
            IPlayEditText __RPC_FAR * This,
            BITMAPINFOHEADER __RPC_FAR *pHeader,
            BYTE __RPC_FAR *pBits,
            POINT __RPC_FAR *pOfs);
        
        DWORD ( STDMETHODCALLTYPE __RPC_FAR *GetTextPixelLength )( 
            IPlayEditText __RPC_FAR * This);
        
        DWORD ( STDMETHODCALLTYPE __RPC_FAR *GetTextPixelLengthShowing )( 
            IPlayEditText __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Select )( 
            IPlayEditText __RPC_FAR * This,
            BOOL bSelect,
            DWORD dwOption);
        
        END_INTERFACE
    } IPlayEditTextVtbl;

    interface IPlayEditText
    {
        CONST_VTBL struct IPlayEditTextVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IPlayEditText_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IPlayEditText_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IPlayEditText_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IPlayEditText_PutInWindow(This,hWnd,x,y,width,height)	\
    (This)->lpVtbl -> PutInWindow(This,hWnd,x,y,width,height)

#define IPlayEditText_SetMaxCharacters(This,dwNumChars)	\
    (This)->lpVtbl -> SetMaxCharacters(This,dwNumChars)

#define IPlayEditText_SetSize(This,szText)	\
    (This)->lpVtbl -> SetSize(This,szText)

#define IPlayEditText_SetTextAttributes(This,pszFontName,fontSize,fontStyle)	\
    (This)->lpVtbl -> SetTextAttributes(This,pszFontName,fontSize,fontStyle)

#define IPlayEditText_SetColor(This,dwNormalColor,dwHighColor,dwExciteColor,dwGhostColor)	\
    (This)->lpVtbl -> SetColor(This,dwNormalColor,dwHighColor,dwExciteColor,dwGhostColor)

#define IPlayEditText_SetText(This,pszText)	\
    (This)->lpVtbl -> SetText(This,pszText)

#define IPlayEditText_GetText(This,pszText,dwNumChars)	\
    (This)->lpVtbl -> GetText(This,pszText,dwNumChars)

#define IPlayEditText_SetCaret(This,dwLocation)	\
    (This)->lpVtbl -> SetCaret(This,dwLocation)

#define IPlayEditText_SetEditType(This,dwType)	\
    (This)->lpVtbl -> SetEditType(This,dwType)

#define IPlayEditText_UpdateRect(This,pHeader,pBits,pClip,pOfs)	\
    (This)->lpVtbl -> UpdateRect(This,pHeader,pBits,pClip,pOfs)

#define IPlayEditText_ExciteMe(This,bTurnOn)	\
    (This)->lpVtbl -> ExciteMe(This,bTurnOn)

#define IPlayEditText_GhostMe(This,bTurnOn)	\
    (This)->lpVtbl -> GhostMe(This,bTurnOn)

#define IPlayEditText_GetSize(This,sz)	\
    (This)->lpVtbl -> GetSize(This,sz)

#define IPlayEditText_Reposition(This,x,y,width,height)	\
    (This)->lpVtbl -> Reposition(This,x,y,width,height)

#define IPlayEditText_GetTextAttributes(This,pszFontName,numChars,fontSize,fontStyle)	\
    (This)->lpVtbl -> GetTextAttributes(This,pszFontName,numChars,fontSize,fontStyle)

#define IPlayEditText_GetTextColors(This,dwNormalColor,dwHighColor,dwExciteColor)	\
    (This)->lpVtbl -> GetTextColors(This,dwNormalColor,dwHighColor,dwExciteColor)

#define IPlayEditText_SetShowingText(This,dwPosition,bStart)	\
    (This)->lpVtbl -> SetShowingText(This,dwPosition,bStart)

#define IPlayEditText_GetTextLength(This)	\
    (This)->lpVtbl -> GetTextLength(This)

#define IPlayEditText_DrawToDC(This,hDC,x,y)	\
    (This)->lpVtbl -> DrawToDC(This,hDC,x,y)

#define IPlayEditText_InvalidateCache(This)	\
    (This)->lpVtbl -> InvalidateCache(This)

#define IPlayEditText_DisableMe(This,bTurnOn)	\
    (This)->lpVtbl -> DisableMe(This,bTurnOn)

#define IPlayEditText_MakeCache(This,pHeader,pBits,pOfs)	\
    (This)->lpVtbl -> MakeCache(This,pHeader,pBits,pOfs)

#define IPlayEditText_DrawToDIB(This,pHeader,pBits,pOfs)	\
    (This)->lpVtbl -> DrawToDIB(This,pHeader,pBits,pOfs)

#define IPlayEditText_GetTextPixelLength(This)	\
    (This)->lpVtbl -> GetTextPixelLength(This)

#define IPlayEditText_GetTextPixelLengthShowing(This)	\
    (This)->lpVtbl -> GetTextPixelLengthShowing(This)

#define IPlayEditText_Select(This,bSelect,dwOption)	\
    (This)->lpVtbl -> Select(This,bSelect,dwOption)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE IPlayEditText_PutInWindow_Proxy( 
    IPlayEditText __RPC_FAR * This,
    HWND hWnd,
    int x,
    int y,
    int width,
    int height);


void __RPC_STUB IPlayEditText_PutInWindow_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


BOOL STDMETHODCALLTYPE IPlayEditText_SetMaxCharacters_Proxy( 
    IPlayEditText __RPC_FAR * This,
    DWORD dwNumChars);


void __RPC_STUB IPlayEditText_SetMaxCharacters_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


BOOL STDMETHODCALLTYPE IPlayEditText_SetSize_Proxy( 
    IPlayEditText __RPC_FAR * This,
    SIZE __RPC_FAR *szText);


void __RPC_STUB IPlayEditText_SetSize_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IPlayEditText_SetTextAttributes_Proxy( 
    IPlayEditText __RPC_FAR * This,
    LPSTR pszFontName,
    short fontSize,
    short fontStyle);


void __RPC_STUB IPlayEditText_SetTextAttributes_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IPlayEditText_SetColor_Proxy( 
    IPlayEditText __RPC_FAR * This,
    DWORD dwNormalColor,
    DWORD dwHighColor,
    DWORD dwExciteColor,
    DWORD dwGhostColor);


void __RPC_STUB IPlayEditText_SetColor_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IPlayEditText_SetText_Proxy( 
    IPlayEditText __RPC_FAR * This,
    LPSTR pszText);


void __RPC_STUB IPlayEditText_SetText_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IPlayEditText_GetText_Proxy( 
    IPlayEditText __RPC_FAR * This,
    LPSTR pszText,
    DWORD dwNumChars);


void __RPC_STUB IPlayEditText_GetText_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


BOOL STDMETHODCALLTYPE IPlayEditText_SetCaret_Proxy( 
    IPlayEditText __RPC_FAR * This,
    DWORD dwLocation);


void __RPC_STUB IPlayEditText_SetCaret_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IPlayEditText_SetEditType_Proxy( 
    IPlayEditText __RPC_FAR * This,
    DWORD dwType);


void __RPC_STUB IPlayEditText_SetEditType_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


void STDMETHODCALLTYPE IPlayEditText_UpdateRect_Proxy( 
    IPlayEditText __RPC_FAR * This,
    BITMAPINFOHEADER __RPC_FAR *pHeader,
    BYTE __RPC_FAR *pBits,
    RECT __RPC_FAR *pClip,
    POINT __RPC_FAR *pOfs);


void __RPC_STUB IPlayEditText_UpdateRect_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


void STDMETHODCALLTYPE IPlayEditText_ExciteMe_Proxy( 
    IPlayEditText __RPC_FAR * This,
    BOOL bTurnOn);


void __RPC_STUB IPlayEditText_ExciteMe_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


void STDMETHODCALLTYPE IPlayEditText_GhostMe_Proxy( 
    IPlayEditText __RPC_FAR * This,
    BOOL bTurnOn);


void __RPC_STUB IPlayEditText_GhostMe_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


void STDMETHODCALLTYPE IPlayEditText_GetSize_Proxy( 
    IPlayEditText __RPC_FAR * This,
    SIZE __RPC_FAR *sz);


void __RPC_STUB IPlayEditText_GetSize_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IPlayEditText_Reposition_Proxy( 
    IPlayEditText __RPC_FAR * This,
    int x,
    int y,
    int width,
    int height);


void __RPC_STUB IPlayEditText_Reposition_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IPlayEditText_GetTextAttributes_Proxy( 
    IPlayEditText __RPC_FAR * This,
    LPSTR pszFontName,
    DWORD numChars,
    short __RPC_FAR *fontSize,
    short __RPC_FAR *fontStyle);


void __RPC_STUB IPlayEditText_GetTextAttributes_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IPlayEditText_GetTextColors_Proxy( 
    IPlayEditText __RPC_FAR * This,
    DWORD __RPC_FAR *dwNormalColor,
    DWORD __RPC_FAR *dwHighColor,
    DWORD __RPC_FAR *dwExciteColor);


void __RPC_STUB IPlayEditText_GetTextColors_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IPlayEditText_SetShowingText_Proxy( 
    IPlayEditText __RPC_FAR * This,
    DWORD dwPosition,
    BOOL bStart);


void __RPC_STUB IPlayEditText_SetShowingText_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


DWORD STDMETHODCALLTYPE IPlayEditText_GetTextLength_Proxy( 
    IPlayEditText __RPC_FAR * This);


void __RPC_STUB IPlayEditText_GetTextLength_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IPlayEditText_DrawToDC_Proxy( 
    IPlayEditText __RPC_FAR * This,
    HDC hDC,
    long x,
    long y);


void __RPC_STUB IPlayEditText_DrawToDC_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


void STDMETHODCALLTYPE IPlayEditText_InvalidateCache_Proxy( 
    IPlayEditText __RPC_FAR * This);


void __RPC_STUB IPlayEditText_InvalidateCache_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


void STDMETHODCALLTYPE IPlayEditText_DisableMe_Proxy( 
    IPlayEditText __RPC_FAR * This,
    BOOL bTurnOn);


void __RPC_STUB IPlayEditText_DisableMe_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


void STDMETHODCALLTYPE IPlayEditText_MakeCache_Proxy( 
    IPlayEditText __RPC_FAR * This,
    BITMAPINFOHEADER __RPC_FAR *pHeader,
    BYTE __RPC_FAR *pBits,
    POINT __RPC_FAR *pOfs);


void __RPC_STUB IPlayEditText_MakeCache_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


void STDMETHODCALLTYPE IPlayEditText_DrawToDIB_Proxy( 
    IPlayEditText __RPC_FAR * This,
    BITMAPINFOHEADER __RPC_FAR *pHeader,
    BYTE __RPC_FAR *pBits,
    POINT __RPC_FAR *pOfs);


void __RPC_STUB IPlayEditText_DrawToDIB_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


DWORD STDMETHODCALLTYPE IPlayEditText_GetTextPixelLength_Proxy( 
    IPlayEditText __RPC_FAR * This);


void __RPC_STUB IPlayEditText_GetTextPixelLength_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


DWORD STDMETHODCALLTYPE IPlayEditText_GetTextPixelLengthShowing_Proxy( 
    IPlayEditText __RPC_FAR * This);


void __RPC_STUB IPlayEditText_GetTextPixelLengthShowing_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IPlayEditText_Select_Proxy( 
    IPlayEditText __RPC_FAR * This,
    BOOL bSelect,
    DWORD dwOption);


void __RPC_STUB IPlayEditText_Select_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IPlayEditText_INTERFACE_DEFINED__ */


/* Additional Prototypes for ALL interfaces */

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif
