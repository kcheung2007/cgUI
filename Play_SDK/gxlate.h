/* this ALWAYS GENERATED file contains the definitions for the interfaces */


/* File created by MIDL compiler version 3.01.75 */
/* at Tue Nov 23 05:02:08 1999
 */
/* Compiler settings for gxlate.idl:
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

#ifndef __gxlate_h__
#define __gxlate_h__

#ifdef __cplusplus
extern "C"{
#endif 

/* Forward Declarations */ 

#ifndef __IEnumTranslators_FWD_DEFINED__
#define __IEnumTranslators_FWD_DEFINED__
typedef interface IEnumTranslators IEnumTranslators;
#endif 	/* __IEnumTranslators_FWD_DEFINED__ */


#ifndef __IEnumTranslators2_FWD_DEFINED__
#define __IEnumTranslators2_FWD_DEFINED__
typedef interface IEnumTranslators2 IEnumTranslators2;
#endif 	/* __IEnumTranslators2_FWD_DEFINED__ */


#ifndef __IEnumCompressors_FWD_DEFINED__
#define __IEnumCompressors_FWD_DEFINED__
typedef interface IEnumCompressors IEnumCompressors;
#endif 	/* __IEnumCompressors_FWD_DEFINED__ */


#ifndef __IEnumCompressors2_FWD_DEFINED__
#define __IEnumCompressors2_FWD_DEFINED__
typedef interface IEnumCompressors2 IEnumCompressors2;
#endif 	/* __IEnumCompressors2_FWD_DEFINED__ */


#ifndef __IGXGlobalOpts_FWD_DEFINED__
#define __IGXGlobalOpts_FWD_DEFINED__
typedef interface IGXGlobalOpts IGXGlobalOpts;
#endif 	/* __IGXGlobalOpts_FWD_DEFINED__ */


#ifndef __IGXTransFact_FWD_DEFINED__
#define __IGXTransFact_FWD_DEFINED__
typedef interface IGXTransFact IGXTransFact;
#endif 	/* __IGXTransFact_FWD_DEFINED__ */


#ifndef __IGXTransFact2_FWD_DEFINED__
#define __IGXTransFact2_FWD_DEFINED__
typedef interface IGXTransFact2 IGXTransFact2;
#endif 	/* __IGXTransFact2_FWD_DEFINED__ */


#ifndef __IGXTransFact3_FWD_DEFINED__
#define __IGXTransFact3_FWD_DEFINED__
typedef interface IGXTransFact3 IGXTransFact3;
#endif 	/* __IGXTransFact3_FWD_DEFINED__ */


#ifndef __IGXTransFact4_FWD_DEFINED__
#define __IGXTransFact4_FWD_DEFINED__
typedef interface IGXTransFact4 IGXTransFact4;
#endif 	/* __IGXTransFact4_FWD_DEFINED__ */


#ifndef __IGXProgressAdviseSink_FWD_DEFINED__
#define __IGXProgressAdviseSink_FWD_DEFINED__
typedef interface IGXProgressAdviseSink IGXProgressAdviseSink;
#endif 	/* __IGXProgressAdviseSink_FWD_DEFINED__ */


#ifndef __IGXClientIO_FWD_DEFINED__
#define __IGXClientIO_FWD_DEFINED__
typedef interface IGXClientIO IGXClientIO;
#endif 	/* __IGXClientIO_FWD_DEFINED__ */


#ifndef __IGXStreamIO_FWD_DEFINED__
#define __IGXStreamIO_FWD_DEFINED__
typedef interface IGXStreamIO IGXStreamIO;
#endif 	/* __IGXStreamIO_FWD_DEFINED__ */


#ifndef __IGXMemClientIO_FWD_DEFINED__
#define __IGXMemClientIO_FWD_DEFINED__
typedef interface IGXMemClientIO IGXMemClientIO;
#endif 	/* __IGXMemClientIO_FWD_DEFINED__ */


#ifndef __IGXTranslator_FWD_DEFINED__
#define __IGXTranslator_FWD_DEFINED__
typedef interface IGXTranslator IGXTranslator;
#endif 	/* __IGXTranslator_FWD_DEFINED__ */


#ifndef __IGXTranslator2_FWD_DEFINED__
#define __IGXTranslator2_FWD_DEFINED__
typedef interface IGXTranslator2 IGXTranslator2;
#endif 	/* __IGXTranslator2_FWD_DEFINED__ */


#ifndef __IGXTranslator3_FWD_DEFINED__
#define __IGXTranslator3_FWD_DEFINED__
typedef interface IGXTranslator3 IGXTranslator3;
#endif 	/* __IGXTranslator3_FWD_DEFINED__ */


#ifndef __IGXTranslator4_FWD_DEFINED__
#define __IGXTranslator4_FWD_DEFINED__
typedef interface IGXTranslator4 IGXTranslator4;
#endif 	/* __IGXTranslator4_FWD_DEFINED__ */


#ifndef __IGXAbsBitmap_FWD_DEFINED__
#define __IGXAbsBitmap_FWD_DEFINED__
typedef interface IGXAbsBitmap IGXAbsBitmap;
#endif 	/* __IGXAbsBitmap_FWD_DEFINED__ */


#ifndef __IGXAbsBitmap2_FWD_DEFINED__
#define __IGXAbsBitmap2_FWD_DEFINED__
typedef interface IGXAbsBitmap2 IGXAbsBitmap2;
#endif 	/* __IGXAbsBitmap2_FWD_DEFINED__ */


#ifndef __IGXIntBitmap_FWD_DEFINED__
#define __IGXIntBitmap_FWD_DEFINED__
typedef interface IGXIntBitmap IGXIntBitmap;
#endif 	/* __IGXIntBitmap_FWD_DEFINED__ */


#ifndef __IGXIntBitmap2_FWD_DEFINED__
#define __IGXIntBitmap2_FWD_DEFINED__
typedef interface IGXIntBitmap2 IGXIntBitmap2;
#endif 	/* __IGXIntBitmap2_FWD_DEFINED__ */


#ifndef __IGXBasicImageProcess_FWD_DEFINED__
#define __IGXBasicImageProcess_FWD_DEFINED__
typedef interface IGXBasicImageProcess IGXBasicImageProcess;
#endif 	/* __IGXBasicImageProcess_FWD_DEFINED__ */


#ifndef __IGXBasicImageProcess2_FWD_DEFINED__
#define __IGXBasicImageProcess2_FWD_DEFINED__
typedef interface IGXBasicImageProcess2 IGXBasicImageProcess2;
#endif 	/* __IGXBasicImageProcess2_FWD_DEFINED__ */


#ifndef __IGXBasicImageProcess3_FWD_DEFINED__
#define __IGXBasicImageProcess3_FWD_DEFINED__
typedef interface IGXBasicImageProcess3 IGXBasicImageProcess3;
#endif 	/* __IGXBasicImageProcess3_FWD_DEFINED__ */


#ifndef __IGXBasicImageProcess4_FWD_DEFINED__
#define __IGXBasicImageProcess4_FWD_DEFINED__
typedef interface IGXBasicImageProcess4 IGXBasicImageProcess4;
#endif 	/* __IGXBasicImageProcess4_FWD_DEFINED__ */


#ifndef __IGXBasicImageProcess5_FWD_DEFINED__
#define __IGXBasicImageProcess5_FWD_DEFINED__
typedef interface IGXBasicImageProcess5 IGXBasicImageProcess5;
#endif 	/* __IGXBasicImageProcess5_FWD_DEFINED__ */


#ifndef __IGXMovie_FWD_DEFINED__
#define __IGXMovie_FWD_DEFINED__
typedef interface IGXMovie IGXMovie;
#endif 	/* __IGXMovie_FWD_DEFINED__ */


#ifndef __IGXMovieAudio_FWD_DEFINED__
#define __IGXMovieAudio_FWD_DEFINED__
typedef interface IGXMovieAudio IGXMovieAudio;
#endif 	/* __IGXMovieAudio_FWD_DEFINED__ */


#ifndef __IGXLateUtils_FWD_DEFINED__
#define __IGXLateUtils_FWD_DEFINED__
typedef interface IGXLateUtils IGXLateUtils;
#endif 	/* __IGXLateUtils_FWD_DEFINED__ */


#ifndef __IGXLateOptionsUI_FWD_DEFINED__
#define __IGXLateOptionsUI_FWD_DEFINED__
typedef interface IGXLateOptionsUI IGXLateOptionsUI;
#endif 	/* __IGXLateOptionsUI_FWD_DEFINED__ */


#ifndef __IGXOptionsCallback_FWD_DEFINED__
#define __IGXOptionsCallback_FWD_DEFINED__
typedef interface IGXOptionsCallback IGXOptionsCallback;
#endif 	/* __IGXOptionsCallback_FWD_DEFINED__ */


/* header files for imported files */
#include "objidl.h"

void __RPC_FAR * __RPC_USER MIDL_user_allocate(size_t);
void __RPC_USER MIDL_user_free( void __RPC_FAR * ); 

/****************************************
 * Generated header for interface: __MIDL_itf_gxlate_0000
 * at Tue Nov 23 05:02:08 1999
 * using MIDL 3.01.75
 ****************************************/
/* [local] */ 


















extern RPC_IF_HANDLE __MIDL_itf_gxlate_0000_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_gxlate_0000_v0_0_s_ifspec;

#ifndef __IGXTypes_INTERFACE_DEFINED__
#define __IGXTypes_INTERFACE_DEFINED__

/****************************************
 * Generated header for interface: IGXTypes
 * at Tue Nov 23 05:02:08 1999
 * using MIDL 3.01.75
 ****************************************/
/* [auto_handle][unique][uuid] */ 


typedef 
enum tagEPlayFrameType
    {	FTALPHA8	= 0x1,
	FTALPHA10	= 0x2,
	FT422YUV8	= 0x4,
	FT4224YUVA8	= 0x8,
	FT422YUV10	= 0x10,
	FT4224YUVA10	= 0x20,
	FT444YUV8	= 0x40,
	FT4444YUVA8	= 0x80,
	FT444YUV10	= 0x100,
	FT4444YUVA10	= 0x200,
	FTRGB8	= 0x400,
	FTRGBA8	= 0x800,
	FTRGB10	= 0x1000,
	FTRGBA10	= 0x2000,
	FT256Palette8	= 0x4000,
	FT65KRGB16	= 0x8000,
	FT16Palette4	= 0x10000,
	FT422YUV8p	= 0x20000,
	FT4224YUVA8p	= 0x40000,
	FTADV601	= 0x100000
    }	EPlayFrameType;

typedef 
enum tagECompressFlag
    {	CF_QUALITY	= 0x1,
	CF_TEMPORAL	= 0x2,
	CF_SCALE	= 0x4
    }	ECompressFlag;

typedef 
enum tagEBitDepths
    {	BD_1	= 0x1,
	BD_2	= 0x2,
	BD_4	= 0x4,
	BD_8	= 0x8,
	BD_16	= 0x10,
	BD_24	= 0x20,
	BD_32	= 0x40,
	BD_7	= 0x80,
	BD_15	= 0x100,
	BD_ALPHA	= 0x80000000
    }	EBitFlag;

typedef struct  tagBitDepthEnum
    {
    EBitFlag BitDepth;
    LPTSTR Name;
    }	BitDepthEnum;

typedef 
enum tagEGXColorSpace
    {	COLOR_UNKNOWN	= 0,
	RGB	= 1,
	YUV	= 2,
	CMYK	= 4,
	GREY	= 8,
	HSV	= 16
    }	EGXColorSpace;

typedef 
enum tagEQuantSpeed
    {	GXSLOW	= 0,
	GXFAST	= 1
    }	EQuantSpeed;

typedef struct tagBITMAPINFOHEADER BITMAPINFOHEADER;

typedef struct tagRGBQUAD RGBQUAD;

typedef struct tagBITMAPINFO BITMAPINFO;

typedef struct  tagSPlaySPBmp
    {
    BITMAPINFOHEADER __RPC_FAR *imageHeader;
    EPlayFrameType pixelFormat;
    BYTE __RPC_FAR *pixelData;
    }	SPlayBitMap;

typedef 
enum tagCanSetCompression
    {	cscNo	= 0,
	cscYes	= cscNo + 1,
	cscCodec	= cscYes + 1,
	cscOwnConfig	= cscCodec + 1
    }	CanSetCompression;

#pragma pack(push,2)
typedef struct  tagFileNameMatchOptions
    {
    DWORD Size;
    BOOL ExtMustMatch;
    BOOL P1NoCase;
    BOOL P3Important;
    BOOL P3NoCase;
    BOOL P3AsText;
    BOOL UseFileNameMatching;
    }	FileNameMatchOptions;

#pragma pack(pop)
#pragma pack(push,2)
typedef struct  tagPlayXlatorOpt
    {
    DWORD Size;
    WORD QualityFactor;
    DWORD FrameRateRate;
    DWORD FrameRateScale;
    DWORD LoadScaleNumerator;
    DWORD LoadScaleDenominator;
    WORD DefaultColorCol1;
    WORD DefaultColorCol2;
    WORD DefaultColorCol3;
    WORD AlphaColorCol1;
    WORD AlphaColorCol2;
    WORD AlphaColorCol3;
    BOOL ApplyAlphaToNonAlphaDest;
    BOOL ApplyAlphaToAlphaDest;
    FileNameMatchOptions FNameMatchOpt;
    DWORD Compressor;
    double LoadFrameNumber;
    CanSetCompression SetCompression;
    DWORD ID;
    }	PlayXlatorOpt;

#pragma pack(pop)
#define SIZE_1_PlayXlatorOpt 82
#define SIZE_2_PlayXlatorOpt 90
typedef 
enum tagELayerAttribute
    {	LA_NAME	= 1,
	LA_XOFF	= 2,
	LA_YOFF	= 3,
	LA_BLENDMODE	= 4,
	LA_OPACITY	= 5
    }	ELayerAttribute;

typedef 
enum tagEBlendModeKey
    {	BMK_NORMAL	= 0,
	BMK_DARKEN	= 1,
	BMK_LIGHTEN	= 2,
	BMK_HUE	= 3,
	BMK_SATURATION	= 4,
	BMK_COLOR	= 5,
	BMK_LUMINOSITY	= 6,
	BMK_MULTIPLY	= 7,
	BMK_SCREEN	= 8,
	BMK_DISSOLVE	= 9,
	BMK_OVERLAY	= 10,
	BMK_HARDLIGHT	= 11,
	BMK_SOFTLIGHT	= 12,
	BMK_DIFFERENCE	= 13
    }	EBlendModeKey;



extern RPC_IF_HANDLE IGXTypes_v0_0_c_ifspec;
extern RPC_IF_HANDLE IGXTypes_v0_0_s_ifspec;
#endif /* __IGXTypes_INTERFACE_DEFINED__ */

#ifndef __IEnumTranslators_INTERFACE_DEFINED__
#define __IEnumTranslators_INTERFACE_DEFINED__

/****************************************
 * Generated header for interface: IEnumTranslators
 * at Tue Nov 23 05:02:08 1999
 * using MIDL 3.01.75
 ****************************************/
/* [uuid][object] */ 



EXTERN_C const IID IID_IEnumTranslators;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    interface DECLSPEC_UUID("8335e5f1-ab3b-11ce-8468-0000b468276b")
    IEnumTranslators : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE Next( 
            /* [in] */ DWORD fileTypeSize,
            /* [in] */ DWORD fileDescripSize,
            /* [out] */ unsigned char __RPC_FAR *szFileTypeName,
            /* [out] */ unsigned char __RPC_FAR *szFileDescrip) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Skip( 
            /* [in] */ ULONG celt) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Reset( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Clone( 
            /* [out] */ IEnumTranslators __RPC_FAR *__RPC_FAR *ppenum) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IEnumTranslatorsVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            IEnumTranslators __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            IEnumTranslators __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            IEnumTranslators __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Next )( 
            IEnumTranslators __RPC_FAR * This,
            /* [in] */ DWORD fileTypeSize,
            /* [in] */ DWORD fileDescripSize,
            /* [out] */ unsigned char __RPC_FAR *szFileTypeName,
            /* [out] */ unsigned char __RPC_FAR *szFileDescrip);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Skip )( 
            IEnumTranslators __RPC_FAR * This,
            /* [in] */ ULONG celt);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Reset )( 
            IEnumTranslators __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Clone )( 
            IEnumTranslators __RPC_FAR * This,
            /* [out] */ IEnumTranslators __RPC_FAR *__RPC_FAR *ppenum);
        
        END_INTERFACE
    } IEnumTranslatorsVtbl;

    interface IEnumTranslators
    {
        CONST_VTBL struct IEnumTranslatorsVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IEnumTranslators_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IEnumTranslators_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IEnumTranslators_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IEnumTranslators_Next(This,fileTypeSize,fileDescripSize,szFileTypeName,szFileDescrip)	\
    (This)->lpVtbl -> Next(This,fileTypeSize,fileDescripSize,szFileTypeName,szFileDescrip)

#define IEnumTranslators_Skip(This,celt)	\
    (This)->lpVtbl -> Skip(This,celt)

#define IEnumTranslators_Reset(This)	\
    (This)->lpVtbl -> Reset(This)

#define IEnumTranslators_Clone(This,ppenum)	\
    (This)->lpVtbl -> Clone(This,ppenum)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE IEnumTranslators_Next_Proxy( 
    IEnumTranslators __RPC_FAR * This,
    /* [in] */ DWORD fileTypeSize,
    /* [in] */ DWORD fileDescripSize,
    /* [out] */ unsigned char __RPC_FAR *szFileTypeName,
    /* [out] */ unsigned char __RPC_FAR *szFileDescrip);


void __RPC_STUB IEnumTranslators_Next_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IEnumTranslators_Skip_Proxy( 
    IEnumTranslators __RPC_FAR * This,
    /* [in] */ ULONG celt);


void __RPC_STUB IEnumTranslators_Skip_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IEnumTranslators_Reset_Proxy( 
    IEnumTranslators __RPC_FAR * This);


void __RPC_STUB IEnumTranslators_Reset_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IEnumTranslators_Clone_Proxy( 
    IEnumTranslators __RPC_FAR * This,
    /* [out] */ IEnumTranslators __RPC_FAR *__RPC_FAR *ppenum);


void __RPC_STUB IEnumTranslators_Clone_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IEnumTranslators_INTERFACE_DEFINED__ */


#ifndef __IEnumTranslators2_INTERFACE_DEFINED__
#define __IEnumTranslators2_INTERFACE_DEFINED__

/****************************************
 * Generated header for interface: IEnumTranslators2
 * at Tue Nov 23 05:02:08 1999
 * using MIDL 3.01.75
 ****************************************/
/* [local][uuid][object] */ 



EXTERN_C const IID IID_IEnumTranslators2;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    interface DECLSPEC_UUID("8335e6ba-ab3b-11ce-8468-0000b468276b")
    IEnumTranslators2 : public IEnumTranslators
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE Next( 
            /* [in] */ DWORD dwFileTypeSize,
            /* [in] */ DWORD dwFileDescripSize,
            /* [out] */ unsigned char __RPC_FAR *szFileTypeName,
            /* [out] */ unsigned char __RPC_FAR *szFileDescrip,
            /* [out] */ DWORD __RPC_FAR *pdwID) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Clone( 
            /* [out] */ IEnumTranslators2 __RPC_FAR *__RPC_FAR *ppenum) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IEnumTranslators2Vtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            IEnumTranslators2 __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            IEnumTranslators2 __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            IEnumTranslators2 __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Next )( 
            IEnumTranslators2 __RPC_FAR * This,
            /* [in] */ DWORD fileTypeSize,
            /* [in] */ DWORD fileDescripSize,
            /* [out] */ unsigned char __RPC_FAR *szFileTypeName,
            /* [out] */ unsigned char __RPC_FAR *szFileDescrip);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Skip )( 
            IEnumTranslators2 __RPC_FAR * This,
            /* [in] */ ULONG celt);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Reset )( 
            IEnumTranslators2 __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Clone )( 
            IEnumTranslators2 __RPC_FAR * This,
            /* [out] */ IEnumTranslators __RPC_FAR *__RPC_FAR *ppenum);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Next )( 
            IEnumTranslators2 __RPC_FAR * This,
            /* [in] */ DWORD dwFileTypeSize,
            /* [in] */ DWORD dwFileDescripSize,
            /* [out] */ unsigned char __RPC_FAR *szFileTypeName,
            /* [out] */ unsigned char __RPC_FAR *szFileDescrip,
            /* [out] */ DWORD __RPC_FAR *pdwID);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Clone )( 
            IEnumTranslators2 __RPC_FAR * This,
            /* [out] */ IEnumTranslators2 __RPC_FAR *__RPC_FAR *ppenum);
        
        END_INTERFACE
    } IEnumTranslators2Vtbl;

    interface IEnumTranslators2
    {
        CONST_VTBL struct IEnumTranslators2Vtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IEnumTranslators2_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IEnumTranslators2_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IEnumTranslators2_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IEnumTranslators2_Next(This,fileTypeSize,fileDescripSize,szFileTypeName,szFileDescrip)	\
    (This)->lpVtbl -> Next(This,fileTypeSize,fileDescripSize,szFileTypeName,szFileDescrip)

#define IEnumTranslators2_Skip(This,celt)	\
    (This)->lpVtbl -> Skip(This,celt)

#define IEnumTranslators2_Reset(This)	\
    (This)->lpVtbl -> Reset(This)

#define IEnumTranslators2_Clone(This,ppenum)	\
    (This)->lpVtbl -> Clone(This,ppenum)


#define IEnumTranslators2_Next(This,dwFileTypeSize,dwFileDescripSize,szFileTypeName,szFileDescrip,pdwID)	\
    (This)->lpVtbl -> Next(This,dwFileTypeSize,dwFileDescripSize,szFileTypeName,szFileDescrip,pdwID)

#define IEnumTranslators2_Clone(This,ppenum)	\
    (This)->lpVtbl -> Clone(This,ppenum)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE IEnumTranslators2_Next_Proxy( 
    IEnumTranslators2 __RPC_FAR * This,
    /* [in] */ DWORD dwFileTypeSize,
    /* [in] */ DWORD dwFileDescripSize,
    /* [out] */ unsigned char __RPC_FAR *szFileTypeName,
    /* [out] */ unsigned char __RPC_FAR *szFileDescrip,
    /* [out] */ DWORD __RPC_FAR *pdwID);


void __RPC_STUB IEnumTranslators2_Next_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IEnumTranslators2_Clone_Proxy( 
    IEnumTranslators2 __RPC_FAR * This,
    /* [out] */ IEnumTranslators2 __RPC_FAR *__RPC_FAR *ppenum);


void __RPC_STUB IEnumTranslators2_Clone_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IEnumTranslators2_INTERFACE_DEFINED__ */


/****************************************
 * Generated header for interface: __MIDL_itf_gxlate_0056
 * at Tue Nov 23 05:02:08 1999
 * using MIDL 3.01.75
 ****************************************/
/* [local] */ 


#define MIN_ENUM_COMP_NAME_LEN 16
#define MIN_ENUM_COMP_DESC_LEN 128


extern RPC_IF_HANDLE __MIDL_itf_gxlate_0056_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_gxlate_0056_v0_0_s_ifspec;

#ifndef __IEnumCompressors_INTERFACE_DEFINED__
#define __IEnumCompressors_INTERFACE_DEFINED__

/****************************************
 * Generated header for interface: IEnumCompressors
 * at Tue Nov 23 05:02:08 1999
 * using MIDL 3.01.75
 ****************************************/
/* [uuid][object] */ 



EXTERN_C const IID IID_IEnumCompressors;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    interface DECLSPEC_UUID("8335e69b-ab3b-11ce-8468-0000b468276b")
    IEnumCompressors : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE Next( 
            /* [out] */ BYTE __RPC_FAR *CompName,
            /* [out] */ BYTE __RPC_FAR *CompDescrip,
            /* [out] */ ECompressFlag __RPC_FAR *CompFlags,
            /* [out] */ DWORD __RPC_FAR *CompBits,
            /* [out] */ DWORD __RPC_FAR *CompCode) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Skip( 
            /* [in] */ ULONG celt) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Reset( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Clone( 
            /* [out] */ IEnumCompressors __RPC_FAR *__RPC_FAR *ppenum) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IEnumCompressorsVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            IEnumCompressors __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            IEnumCompressors __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            IEnumCompressors __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Next )( 
            IEnumCompressors __RPC_FAR * This,
            /* [out] */ BYTE __RPC_FAR *CompName,
            /* [out] */ BYTE __RPC_FAR *CompDescrip,
            /* [out] */ ECompressFlag __RPC_FAR *CompFlags,
            /* [out] */ DWORD __RPC_FAR *CompBits,
            /* [out] */ DWORD __RPC_FAR *CompCode);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Skip )( 
            IEnumCompressors __RPC_FAR * This,
            /* [in] */ ULONG celt);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Reset )( 
            IEnumCompressors __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Clone )( 
            IEnumCompressors __RPC_FAR * This,
            /* [out] */ IEnumCompressors __RPC_FAR *__RPC_FAR *ppenum);
        
        END_INTERFACE
    } IEnumCompressorsVtbl;

    interface IEnumCompressors
    {
        CONST_VTBL struct IEnumCompressorsVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IEnumCompressors_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IEnumCompressors_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IEnumCompressors_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IEnumCompressors_Next(This,CompName,CompDescrip,CompFlags,CompBits,CompCode)	\
    (This)->lpVtbl -> Next(This,CompName,CompDescrip,CompFlags,CompBits,CompCode)

#define IEnumCompressors_Skip(This,celt)	\
    (This)->lpVtbl -> Skip(This,celt)

#define IEnumCompressors_Reset(This)	\
    (This)->lpVtbl -> Reset(This)

#define IEnumCompressors_Clone(This,ppenum)	\
    (This)->lpVtbl -> Clone(This,ppenum)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE IEnumCompressors_Next_Proxy( 
    IEnumCompressors __RPC_FAR * This,
    /* [out] */ BYTE __RPC_FAR *CompName,
    /* [out] */ BYTE __RPC_FAR *CompDescrip,
    /* [out] */ ECompressFlag __RPC_FAR *CompFlags,
    /* [out] */ DWORD __RPC_FAR *CompBits,
    /* [out] */ DWORD __RPC_FAR *CompCode);


void __RPC_STUB IEnumCompressors_Next_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IEnumCompressors_Skip_Proxy( 
    IEnumCompressors __RPC_FAR * This,
    /* [in] */ ULONG celt);


void __RPC_STUB IEnumCompressors_Skip_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IEnumCompressors_Reset_Proxy( 
    IEnumCompressors __RPC_FAR * This);


void __RPC_STUB IEnumCompressors_Reset_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IEnumCompressors_Clone_Proxy( 
    IEnumCompressors __RPC_FAR * This,
    /* [out] */ IEnumCompressors __RPC_FAR *__RPC_FAR *ppenum);


void __RPC_STUB IEnumCompressors_Clone_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IEnumCompressors_INTERFACE_DEFINED__ */


#ifndef __IEnumCompressors2_INTERFACE_DEFINED__
#define __IEnumCompressors2_INTERFACE_DEFINED__

/****************************************
 * Generated header for interface: IEnumCompressors2
 * at Tue Nov 23 05:02:08 1999
 * using MIDL 3.01.75
 ****************************************/
/* [uuid][object] */ 



EXTERN_C const IID IID_IEnumCompressors2;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    interface DECLSPEC_UUID("8335e6c2-ab3b-11ce-8468-0000b468276b")
    IEnumCompressors2 : public IEnumCompressors
    {
    public:
        virtual HRESULT __stdcall Initialize( 
            /* [in] */ BYTE __RPC_FAR *__RPC_FAR *CNames,
            /* [in] */ BYTE __RPC_FAR *__RPC_FAR *CDescriptions,
            /* [in] */ ECompressFlag __RPC_FAR *CFlags,
            /* [in] */ DWORD __RPC_FAR *CBits,
            /* [in] */ DWORD __RPC_FAR *CIds,
            /* [in] */ DWORD CCount) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IEnumCompressors2Vtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            IEnumCompressors2 __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            IEnumCompressors2 __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            IEnumCompressors2 __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Next )( 
            IEnumCompressors2 __RPC_FAR * This,
            /* [out] */ BYTE __RPC_FAR *CompName,
            /* [out] */ BYTE __RPC_FAR *CompDescrip,
            /* [out] */ ECompressFlag __RPC_FAR *CompFlags,
            /* [out] */ DWORD __RPC_FAR *CompBits,
            /* [out] */ DWORD __RPC_FAR *CompCode);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Skip )( 
            IEnumCompressors2 __RPC_FAR * This,
            /* [in] */ ULONG celt);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Reset )( 
            IEnumCompressors2 __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Clone )( 
            IEnumCompressors2 __RPC_FAR * This,
            /* [out] */ IEnumCompressors __RPC_FAR *__RPC_FAR *ppenum);
        
        HRESULT ( __stdcall __RPC_FAR *Initialize )( 
            IEnumCompressors2 __RPC_FAR * This,
            /* [in] */ BYTE __RPC_FAR *__RPC_FAR *CNames,
            /* [in] */ BYTE __RPC_FAR *__RPC_FAR *CDescriptions,
            /* [in] */ ECompressFlag __RPC_FAR *CFlags,
            /* [in] */ DWORD __RPC_FAR *CBits,
            /* [in] */ DWORD __RPC_FAR *CIds,
            /* [in] */ DWORD CCount);
        
        END_INTERFACE
    } IEnumCompressors2Vtbl;

    interface IEnumCompressors2
    {
        CONST_VTBL struct IEnumCompressors2Vtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IEnumCompressors2_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IEnumCompressors2_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IEnumCompressors2_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IEnumCompressors2_Next(This,CompName,CompDescrip,CompFlags,CompBits,CompCode)	\
    (This)->lpVtbl -> Next(This,CompName,CompDescrip,CompFlags,CompBits,CompCode)

#define IEnumCompressors2_Skip(This,celt)	\
    (This)->lpVtbl -> Skip(This,celt)

#define IEnumCompressors2_Reset(This)	\
    (This)->lpVtbl -> Reset(This)

#define IEnumCompressors2_Clone(This,ppenum)	\
    (This)->lpVtbl -> Clone(This,ppenum)


#define IEnumCompressors2_Initialize(This,CNames,CDescriptions,CFlags,CBits,CIds,CCount)	\
    (This)->lpVtbl -> Initialize(This,CNames,CDescriptions,CFlags,CBits,CIds,CCount)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT __stdcall IEnumCompressors2_Initialize_Proxy( 
    IEnumCompressors2 __RPC_FAR * This,
    /* [in] */ BYTE __RPC_FAR *__RPC_FAR *CNames,
    /* [in] */ BYTE __RPC_FAR *__RPC_FAR *CDescriptions,
    /* [in] */ ECompressFlag __RPC_FAR *CFlags,
    /* [in] */ DWORD __RPC_FAR *CBits,
    /* [in] */ DWORD __RPC_FAR *CIds,
    /* [in] */ DWORD CCount);


void __RPC_STUB IEnumCompressors2_Initialize_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IEnumCompressors2_INTERFACE_DEFINED__ */


#ifndef __IGXGlobalOpts_INTERFACE_DEFINED__
#define __IGXGlobalOpts_INTERFACE_DEFINED__

/****************************************
 * Generated header for interface: IGXGlobalOpts
 * at Tue Nov 23 05:02:08 1999
 * using MIDL 3.01.75
 ****************************************/
/* [local][uuid][object] */ 



EXTERN_C const IID IID_IGXGlobalOpts;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    interface DECLSPEC_UUID("8335e600-ab3b-11ce-8468-0000b468276b")
    IGXGlobalOpts : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE SetQuantizeSpeed( 
            /* [in] */ EQuantSpeed speed) = 0;
        
        virtual void STDMETHODCALLTYPE GetQuantizeSpeed( 
            /* [out] */ EQuantSpeed __RPC_FAR *speed) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetDither( 
            /* [in] */ BOOL dither) = 0;
        
        virtual void STDMETHODCALLTYPE GetDither( 
            /* [out] */ BOOL __RPC_FAR *dither) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetUserPalette( 
            /* [in] */ PALETTEENTRY __RPC_FAR *pal,
            /* [in] */ WORD numentries) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE UseSystemPalette( void) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IGXGlobalOptsVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            IGXGlobalOpts __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            IGXGlobalOpts __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            IGXGlobalOpts __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetQuantizeSpeed )( 
            IGXGlobalOpts __RPC_FAR * This,
            /* [in] */ EQuantSpeed speed);
        
        void ( STDMETHODCALLTYPE __RPC_FAR *GetQuantizeSpeed )( 
            IGXGlobalOpts __RPC_FAR * This,
            /* [out] */ EQuantSpeed __RPC_FAR *speed);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetDither )( 
            IGXGlobalOpts __RPC_FAR * This,
            /* [in] */ BOOL dither);
        
        void ( STDMETHODCALLTYPE __RPC_FAR *GetDither )( 
            IGXGlobalOpts __RPC_FAR * This,
            /* [out] */ BOOL __RPC_FAR *dither);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetUserPalette )( 
            IGXGlobalOpts __RPC_FAR * This,
            /* [in] */ PALETTEENTRY __RPC_FAR *pal,
            /* [in] */ WORD numentries);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *UseSystemPalette )( 
            IGXGlobalOpts __RPC_FAR * This);
        
        END_INTERFACE
    } IGXGlobalOptsVtbl;

    interface IGXGlobalOpts
    {
        CONST_VTBL struct IGXGlobalOptsVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IGXGlobalOpts_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IGXGlobalOpts_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IGXGlobalOpts_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IGXGlobalOpts_SetQuantizeSpeed(This,speed)	\
    (This)->lpVtbl -> SetQuantizeSpeed(This,speed)

#define IGXGlobalOpts_GetQuantizeSpeed(This,speed)	\
    (This)->lpVtbl -> GetQuantizeSpeed(This,speed)

#define IGXGlobalOpts_SetDither(This,dither)	\
    (This)->lpVtbl -> SetDither(This,dither)

#define IGXGlobalOpts_GetDither(This,dither)	\
    (This)->lpVtbl -> GetDither(This,dither)

#define IGXGlobalOpts_SetUserPalette(This,pal,numentries)	\
    (This)->lpVtbl -> SetUserPalette(This,pal,numentries)

#define IGXGlobalOpts_UseSystemPalette(This)	\
    (This)->lpVtbl -> UseSystemPalette(This)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE IGXGlobalOpts_SetQuantizeSpeed_Proxy( 
    IGXGlobalOpts __RPC_FAR * This,
    /* [in] */ EQuantSpeed speed);


void __RPC_STUB IGXGlobalOpts_SetQuantizeSpeed_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


void STDMETHODCALLTYPE IGXGlobalOpts_GetQuantizeSpeed_Proxy( 
    IGXGlobalOpts __RPC_FAR * This,
    /* [out] */ EQuantSpeed __RPC_FAR *speed);


void __RPC_STUB IGXGlobalOpts_GetQuantizeSpeed_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IGXGlobalOpts_SetDither_Proxy( 
    IGXGlobalOpts __RPC_FAR * This,
    /* [in] */ BOOL dither);


void __RPC_STUB IGXGlobalOpts_SetDither_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


void STDMETHODCALLTYPE IGXGlobalOpts_GetDither_Proxy( 
    IGXGlobalOpts __RPC_FAR * This,
    /* [out] */ BOOL __RPC_FAR *dither);


void __RPC_STUB IGXGlobalOpts_GetDither_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IGXGlobalOpts_SetUserPalette_Proxy( 
    IGXGlobalOpts __RPC_FAR * This,
    /* [in] */ PALETTEENTRY __RPC_FAR *pal,
    /* [in] */ WORD numentries);


void __RPC_STUB IGXGlobalOpts_SetUserPalette_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IGXGlobalOpts_UseSystemPalette_Proxy( 
    IGXGlobalOpts __RPC_FAR * This);


void __RPC_STUB IGXGlobalOpts_UseSystemPalette_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IGXGlobalOpts_INTERFACE_DEFINED__ */


#ifndef __IGXTransFact_INTERFACE_DEFINED__
#define __IGXTransFact_INTERFACE_DEFINED__

/****************************************
 * Generated header for interface: IGXTransFact
 * at Tue Nov 23 05:02:08 1999
 * using MIDL 3.01.75
 ****************************************/
/* [local][uuid][object] */ 



EXTERN_C const IID IID_IGXTransFact;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    interface DECLSPEC_UUID("8335e5f2-ab3b-11ce-8468-0000b468276b")
    IGXTransFact : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE GetFileType( 
            /* [in][string] */ unsigned char __RPC_FAR *pszFileName,
            /* [in] */ DWORD fileTypeSize,
            /* [out] */ unsigned char __RPC_FAR *szFileTypeName,
            /* [out] */ IGXTranslator __RPC_FAR *__RPC_FAR *ppXlator) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetFileXlator( 
            /* [in][string] */ unsigned char __RPC_FAR *szFileTypeName,
            /* [out] */ IGXTranslator __RPC_FAR *__RPC_FAR *ppXlator) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE LoadFile( 
            /* [in][string] */ unsigned char __RPC_FAR *pszFileName,
            /* [in] */ EPlayFrameType format,
            /* [out] */ IGXIntBitmap __RPC_FAR *__RPC_FAR *pIBmp,
            /* [in] */ IGXProgressAdviseSink __RPC_FAR *progress,
            /* [out] */ IGXTranslator __RPC_FAR *__RPC_FAR *pITrans) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SaveFile( 
            /* [in][string] */ unsigned char __RPC_FAR *pszFileName,
            /* [in] */ IGXIntBitmap __RPC_FAR *pIBmp,
            /* [in] */ IGXProgressAdviseSink __RPC_FAR *progress) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetEnumLoaders( 
            /* [out] */ IEnumTranslators __RPC_FAR *__RPC_FAR *ppIenum) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetEnumSavers( 
            /* [out] */ IEnumTranslators __RPC_FAR *__RPC_FAR *ppIenum) = 0;
        
        virtual void STDMETHODCALLTYPE SetClientIO( 
            /* [in] */ IGXClientIO __RPC_FAR *pClientIO) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IGXTransFactVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            IGXTransFact __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            IGXTransFact __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            IGXTransFact __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetFileType )( 
            IGXTransFact __RPC_FAR * This,
            /* [in][string] */ unsigned char __RPC_FAR *pszFileName,
            /* [in] */ DWORD fileTypeSize,
            /* [out] */ unsigned char __RPC_FAR *szFileTypeName,
            /* [out] */ IGXTranslator __RPC_FAR *__RPC_FAR *ppXlator);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetFileXlator )( 
            IGXTransFact __RPC_FAR * This,
            /* [in][string] */ unsigned char __RPC_FAR *szFileTypeName,
            /* [out] */ IGXTranslator __RPC_FAR *__RPC_FAR *ppXlator);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *LoadFile )( 
            IGXTransFact __RPC_FAR * This,
            /* [in][string] */ unsigned char __RPC_FAR *pszFileName,
            /* [in] */ EPlayFrameType format,
            /* [out] */ IGXIntBitmap __RPC_FAR *__RPC_FAR *pIBmp,
            /* [in] */ IGXProgressAdviseSink __RPC_FAR *progress,
            /* [out] */ IGXTranslator __RPC_FAR *__RPC_FAR *pITrans);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SaveFile )( 
            IGXTransFact __RPC_FAR * This,
            /* [in][string] */ unsigned char __RPC_FAR *pszFileName,
            /* [in] */ IGXIntBitmap __RPC_FAR *pIBmp,
            /* [in] */ IGXProgressAdviseSink __RPC_FAR *progress);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetEnumLoaders )( 
            IGXTransFact __RPC_FAR * This,
            /* [out] */ IEnumTranslators __RPC_FAR *__RPC_FAR *ppIenum);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetEnumSavers )( 
            IGXTransFact __RPC_FAR * This,
            /* [out] */ IEnumTranslators __RPC_FAR *__RPC_FAR *ppIenum);
        
        void ( STDMETHODCALLTYPE __RPC_FAR *SetClientIO )( 
            IGXTransFact __RPC_FAR * This,
            /* [in] */ IGXClientIO __RPC_FAR *pClientIO);
        
        END_INTERFACE
    } IGXTransFactVtbl;

    interface IGXTransFact
    {
        CONST_VTBL struct IGXTransFactVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IGXTransFact_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IGXTransFact_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IGXTransFact_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IGXTransFact_GetFileType(This,pszFileName,fileTypeSize,szFileTypeName,ppXlator)	\
    (This)->lpVtbl -> GetFileType(This,pszFileName,fileTypeSize,szFileTypeName,ppXlator)

#define IGXTransFact_GetFileXlator(This,szFileTypeName,ppXlator)	\
    (This)->lpVtbl -> GetFileXlator(This,szFileTypeName,ppXlator)

#define IGXTransFact_LoadFile(This,pszFileName,format,pIBmp,progress,pITrans)	\
    (This)->lpVtbl -> LoadFile(This,pszFileName,format,pIBmp,progress,pITrans)

#define IGXTransFact_SaveFile(This,pszFileName,pIBmp,progress)	\
    (This)->lpVtbl -> SaveFile(This,pszFileName,pIBmp,progress)

#define IGXTransFact_GetEnumLoaders(This,ppIenum)	\
    (This)->lpVtbl -> GetEnumLoaders(This,ppIenum)

#define IGXTransFact_GetEnumSavers(This,ppIenum)	\
    (This)->lpVtbl -> GetEnumSavers(This,ppIenum)

#define IGXTransFact_SetClientIO(This,pClientIO)	\
    (This)->lpVtbl -> SetClientIO(This,pClientIO)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE IGXTransFact_GetFileType_Proxy( 
    IGXTransFact __RPC_FAR * This,
    /* [in][string] */ unsigned char __RPC_FAR *pszFileName,
    /* [in] */ DWORD fileTypeSize,
    /* [out] */ unsigned char __RPC_FAR *szFileTypeName,
    /* [out] */ IGXTranslator __RPC_FAR *__RPC_FAR *ppXlator);


void __RPC_STUB IGXTransFact_GetFileType_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IGXTransFact_GetFileXlator_Proxy( 
    IGXTransFact __RPC_FAR * This,
    /* [in][string] */ unsigned char __RPC_FAR *szFileTypeName,
    /* [out] */ IGXTranslator __RPC_FAR *__RPC_FAR *ppXlator);


void __RPC_STUB IGXTransFact_GetFileXlator_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IGXTransFact_LoadFile_Proxy( 
    IGXTransFact __RPC_FAR * This,
    /* [in][string] */ unsigned char __RPC_FAR *pszFileName,
    /* [in] */ EPlayFrameType format,
    /* [out] */ IGXIntBitmap __RPC_FAR *__RPC_FAR *pIBmp,
    /* [in] */ IGXProgressAdviseSink __RPC_FAR *progress,
    /* [out] */ IGXTranslator __RPC_FAR *__RPC_FAR *pITrans);


void __RPC_STUB IGXTransFact_LoadFile_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IGXTransFact_SaveFile_Proxy( 
    IGXTransFact __RPC_FAR * This,
    /* [in][string] */ unsigned char __RPC_FAR *pszFileName,
    /* [in] */ IGXIntBitmap __RPC_FAR *pIBmp,
    /* [in] */ IGXProgressAdviseSink __RPC_FAR *progress);


void __RPC_STUB IGXTransFact_SaveFile_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IGXTransFact_GetEnumLoaders_Proxy( 
    IGXTransFact __RPC_FAR * This,
    /* [out] */ IEnumTranslators __RPC_FAR *__RPC_FAR *ppIenum);


void __RPC_STUB IGXTransFact_GetEnumLoaders_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IGXTransFact_GetEnumSavers_Proxy( 
    IGXTransFact __RPC_FAR * This,
    /* [out] */ IEnumTranslators __RPC_FAR *__RPC_FAR *ppIenum);


void __RPC_STUB IGXTransFact_GetEnumSavers_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


void STDMETHODCALLTYPE IGXTransFact_SetClientIO_Proxy( 
    IGXTransFact __RPC_FAR * This,
    /* [in] */ IGXClientIO __RPC_FAR *pClientIO);


void __RPC_STUB IGXTransFact_SetClientIO_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IGXTransFact_INTERFACE_DEFINED__ */


#ifndef __IGXTransFact2_INTERFACE_DEFINED__
#define __IGXTransFact2_INTERFACE_DEFINED__

/****************************************
 * Generated header for interface: IGXTransFact2
 * at Tue Nov 23 05:02:08 1999
 * using MIDL 3.01.75
 ****************************************/
/* [local][uuid][object] */ 



EXTERN_C const IID IID_IGXTransFact2;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    interface DECLSPEC_UUID("8335e604-ab3b-11ce-8468-0000b468276b")
    IGXTransFact2 : public IGXTransFact
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE SetFrameNumber( 
            /* [in] */ DWORD frameNumber) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE QueryFrameNumber( 
            /* [out] */ DWORD __RPC_FAR *frameNumber) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE QueryImageHeader( 
            /* [in][string] */ unsigned char __RPC_FAR *pszFileName,
            /* [out] */ BITMAPINFOHEADER __RPC_FAR *pBmi,
            /* [out] */ EPlayFrameType __RPC_FAR *format) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE QueryNumberFrames( 
            /* [string][in] */ unsigned char __RPC_FAR *pszFileName,
            /* [out] */ DWORD __RPC_FAR *numFrames) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE QueryFrameRate( 
            /* [string][in] */ unsigned char __RPC_FAR *pszFileName,
            /* [out] */ DWORD __RPC_FAR *Scale,
            /* [out] */ DWORD __RPC_FAR *Rate) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetFrameRate( 
            /* [in] */ DWORD Scale,
            /* [in] */ DWORD Rate) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE UpdateFrameRate( 
            /* [string][in] */ unsigned char __RPC_FAR *pszFileName,
            /* [in] */ DWORD Scale,
            /* [in] */ DWORD Rate) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetFileType( 
            /* [in][string] */ unsigned char __RPC_FAR *pszFileName,
            /* [in] */ DWORD fileTypeSize,
            /* [out] */ unsigned char __RPC_FAR *szFileTypeName,
            /* [out] */ IGXTranslator2 __RPC_FAR *__RPC_FAR *ppXlator2) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetFileXlator( 
            /* [in][string] */ unsigned char __RPC_FAR *szFileTypeName,
            /* [out] */ IGXTranslator2 __RPC_FAR *__RPC_FAR *ppXlator2) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE LoadFile( 
            /* [in][string] */ unsigned char __RPC_FAR *pszFileName,
            /* [in] */ EPlayFrameType format,
            /* [out] */ IGXIntBitmap __RPC_FAR *__RPC_FAR *pIBmp,
            /* [in] */ IGXProgressAdviseSink __RPC_FAR *progress,
            /* [out] */ IGXTranslator2 __RPC_FAR *__RPC_FAR *pITrans2) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IGXTransFact2Vtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            IGXTransFact2 __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            IGXTransFact2 __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            IGXTransFact2 __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetFileType )( 
            IGXTransFact2 __RPC_FAR * This,
            /* [in][string] */ unsigned char __RPC_FAR *pszFileName,
            /* [in] */ DWORD fileTypeSize,
            /* [out] */ unsigned char __RPC_FAR *szFileTypeName,
            /* [out] */ IGXTranslator __RPC_FAR *__RPC_FAR *ppXlator);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetFileXlator )( 
            IGXTransFact2 __RPC_FAR * This,
            /* [in][string] */ unsigned char __RPC_FAR *szFileTypeName,
            /* [out] */ IGXTranslator __RPC_FAR *__RPC_FAR *ppXlator);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *LoadFile )( 
            IGXTransFact2 __RPC_FAR * This,
            /* [in][string] */ unsigned char __RPC_FAR *pszFileName,
            /* [in] */ EPlayFrameType format,
            /* [out] */ IGXIntBitmap __RPC_FAR *__RPC_FAR *pIBmp,
            /* [in] */ IGXProgressAdviseSink __RPC_FAR *progress,
            /* [out] */ IGXTranslator __RPC_FAR *__RPC_FAR *pITrans);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SaveFile )( 
            IGXTransFact2 __RPC_FAR * This,
            /* [in][string] */ unsigned char __RPC_FAR *pszFileName,
            /* [in] */ IGXIntBitmap __RPC_FAR *pIBmp,
            /* [in] */ IGXProgressAdviseSink __RPC_FAR *progress);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetEnumLoaders )( 
            IGXTransFact2 __RPC_FAR * This,
            /* [out] */ IEnumTranslators __RPC_FAR *__RPC_FAR *ppIenum);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetEnumSavers )( 
            IGXTransFact2 __RPC_FAR * This,
            /* [out] */ IEnumTranslators __RPC_FAR *__RPC_FAR *ppIenum);
        
        void ( STDMETHODCALLTYPE __RPC_FAR *SetClientIO )( 
            IGXTransFact2 __RPC_FAR * This,
            /* [in] */ IGXClientIO __RPC_FAR *pClientIO);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetFrameNumber )( 
            IGXTransFact2 __RPC_FAR * This,
            /* [in] */ DWORD frameNumber);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryFrameNumber )( 
            IGXTransFact2 __RPC_FAR * This,
            /* [out] */ DWORD __RPC_FAR *frameNumber);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryImageHeader )( 
            IGXTransFact2 __RPC_FAR * This,
            /* [in][string] */ unsigned char __RPC_FAR *pszFileName,
            /* [out] */ BITMAPINFOHEADER __RPC_FAR *pBmi,
            /* [out] */ EPlayFrameType __RPC_FAR *format);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryNumberFrames )( 
            IGXTransFact2 __RPC_FAR * This,
            /* [string][in] */ unsigned char __RPC_FAR *pszFileName,
            /* [out] */ DWORD __RPC_FAR *numFrames);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryFrameRate )( 
            IGXTransFact2 __RPC_FAR * This,
            /* [string][in] */ unsigned char __RPC_FAR *pszFileName,
            /* [out] */ DWORD __RPC_FAR *Scale,
            /* [out] */ DWORD __RPC_FAR *Rate);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetFrameRate )( 
            IGXTransFact2 __RPC_FAR * This,
            /* [in] */ DWORD Scale,
            /* [in] */ DWORD Rate);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *UpdateFrameRate )( 
            IGXTransFact2 __RPC_FAR * This,
            /* [string][in] */ unsigned char __RPC_FAR *pszFileName,
            /* [in] */ DWORD Scale,
            /* [in] */ DWORD Rate);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetFileType )( 
            IGXTransFact2 __RPC_FAR * This,
            /* [in][string] */ unsigned char __RPC_FAR *pszFileName,
            /* [in] */ DWORD fileTypeSize,
            /* [out] */ unsigned char __RPC_FAR *szFileTypeName,
            /* [out] */ IGXTranslator2 __RPC_FAR *__RPC_FAR *ppXlator2);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetFileXlator )( 
            IGXTransFact2 __RPC_FAR * This,
            /* [in][string] */ unsigned char __RPC_FAR *szFileTypeName,
            /* [out] */ IGXTranslator2 __RPC_FAR *__RPC_FAR *ppXlator2);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *LoadFile )( 
            IGXTransFact2 __RPC_FAR * This,
            /* [in][string] */ unsigned char __RPC_FAR *pszFileName,
            /* [in] */ EPlayFrameType format,
            /* [out] */ IGXIntBitmap __RPC_FAR *__RPC_FAR *pIBmp,
            /* [in] */ IGXProgressAdviseSink __RPC_FAR *progress,
            /* [out] */ IGXTranslator2 __RPC_FAR *__RPC_FAR *pITrans2);
        
        END_INTERFACE
    } IGXTransFact2Vtbl;

    interface IGXTransFact2
    {
        CONST_VTBL struct IGXTransFact2Vtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IGXTransFact2_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IGXTransFact2_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IGXTransFact2_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IGXTransFact2_GetFileType(This,pszFileName,fileTypeSize,szFileTypeName,ppXlator)	\
    (This)->lpVtbl -> GetFileType(This,pszFileName,fileTypeSize,szFileTypeName,ppXlator)

#define IGXTransFact2_GetFileXlator(This,szFileTypeName,ppXlator)	\
    (This)->lpVtbl -> GetFileXlator(This,szFileTypeName,ppXlator)

#define IGXTransFact2_LoadFile(This,pszFileName,format,pIBmp,progress,pITrans)	\
    (This)->lpVtbl -> LoadFile(This,pszFileName,format,pIBmp,progress,pITrans)

#define IGXTransFact2_SaveFile(This,pszFileName,pIBmp,progress)	\
    (This)->lpVtbl -> SaveFile(This,pszFileName,pIBmp,progress)

#define IGXTransFact2_GetEnumLoaders(This,ppIenum)	\
    (This)->lpVtbl -> GetEnumLoaders(This,ppIenum)

#define IGXTransFact2_GetEnumSavers(This,ppIenum)	\
    (This)->lpVtbl -> GetEnumSavers(This,ppIenum)

#define IGXTransFact2_SetClientIO(This,pClientIO)	\
    (This)->lpVtbl -> SetClientIO(This,pClientIO)


#define IGXTransFact2_SetFrameNumber(This,frameNumber)	\
    (This)->lpVtbl -> SetFrameNumber(This,frameNumber)

#define IGXTransFact2_QueryFrameNumber(This,frameNumber)	\
    (This)->lpVtbl -> QueryFrameNumber(This,frameNumber)

#define IGXTransFact2_QueryImageHeader(This,pszFileName,pBmi,format)	\
    (This)->lpVtbl -> QueryImageHeader(This,pszFileName,pBmi,format)

#define IGXTransFact2_QueryNumberFrames(This,pszFileName,numFrames)	\
    (This)->lpVtbl -> QueryNumberFrames(This,pszFileName,numFrames)

#define IGXTransFact2_QueryFrameRate(This,pszFileName,Scale,Rate)	\
    (This)->lpVtbl -> QueryFrameRate(This,pszFileName,Scale,Rate)

#define IGXTransFact2_SetFrameRate(This,Scale,Rate)	\
    (This)->lpVtbl -> SetFrameRate(This,Scale,Rate)

#define IGXTransFact2_UpdateFrameRate(This,pszFileName,Scale,Rate)	\
    (This)->lpVtbl -> UpdateFrameRate(This,pszFileName,Scale,Rate)

#define IGXTransFact2_GetFileType(This,pszFileName,fileTypeSize,szFileTypeName,ppXlator2)	\
    (This)->lpVtbl -> GetFileType(This,pszFileName,fileTypeSize,szFileTypeName,ppXlator2)

#define IGXTransFact2_GetFileXlator(This,szFileTypeName,ppXlator2)	\
    (This)->lpVtbl -> GetFileXlator(This,szFileTypeName,ppXlator2)

#define IGXTransFact2_LoadFile(This,pszFileName,format,pIBmp,progress,pITrans2)	\
    (This)->lpVtbl -> LoadFile(This,pszFileName,format,pIBmp,progress,pITrans2)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE IGXTransFact2_SetFrameNumber_Proxy( 
    IGXTransFact2 __RPC_FAR * This,
    /* [in] */ DWORD frameNumber);


void __RPC_STUB IGXTransFact2_SetFrameNumber_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IGXTransFact2_QueryFrameNumber_Proxy( 
    IGXTransFact2 __RPC_FAR * This,
    /* [out] */ DWORD __RPC_FAR *frameNumber);


void __RPC_STUB IGXTransFact2_QueryFrameNumber_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IGXTransFact2_QueryImageHeader_Proxy( 
    IGXTransFact2 __RPC_FAR * This,
    /* [in][string] */ unsigned char __RPC_FAR *pszFileName,
    /* [out] */ BITMAPINFOHEADER __RPC_FAR *pBmi,
    /* [out] */ EPlayFrameType __RPC_FAR *format);


void __RPC_STUB IGXTransFact2_QueryImageHeader_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IGXTransFact2_QueryNumberFrames_Proxy( 
    IGXTransFact2 __RPC_FAR * This,
    /* [string][in] */ unsigned char __RPC_FAR *pszFileName,
    /* [out] */ DWORD __RPC_FAR *numFrames);


void __RPC_STUB IGXTransFact2_QueryNumberFrames_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IGXTransFact2_QueryFrameRate_Proxy( 
    IGXTransFact2 __RPC_FAR * This,
    /* [string][in] */ unsigned char __RPC_FAR *pszFileName,
    /* [out] */ DWORD __RPC_FAR *Scale,
    /* [out] */ DWORD __RPC_FAR *Rate);


void __RPC_STUB IGXTransFact2_QueryFrameRate_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IGXTransFact2_SetFrameRate_Proxy( 
    IGXTransFact2 __RPC_FAR * This,
    /* [in] */ DWORD Scale,
    /* [in] */ DWORD Rate);


void __RPC_STUB IGXTransFact2_SetFrameRate_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IGXTransFact2_UpdateFrameRate_Proxy( 
    IGXTransFact2 __RPC_FAR * This,
    /* [string][in] */ unsigned char __RPC_FAR *pszFileName,
    /* [in] */ DWORD Scale,
    /* [in] */ DWORD Rate);


void __RPC_STUB IGXTransFact2_UpdateFrameRate_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IGXTransFact2_GetFileType_Proxy( 
    IGXTransFact2 __RPC_FAR * This,
    /* [in][string] */ unsigned char __RPC_FAR *pszFileName,
    /* [in] */ DWORD fileTypeSize,
    /* [out] */ unsigned char __RPC_FAR *szFileTypeName,
    /* [out] */ IGXTranslator2 __RPC_FAR *__RPC_FAR *ppXlator2);


void __RPC_STUB IGXTransFact2_GetFileType_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IGXTransFact2_GetFileXlator_Proxy( 
    IGXTransFact2 __RPC_FAR * This,
    /* [in][string] */ unsigned char __RPC_FAR *szFileTypeName,
    /* [out] */ IGXTranslator2 __RPC_FAR *__RPC_FAR *ppXlator2);


void __RPC_STUB IGXTransFact2_GetFileXlator_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IGXTransFact2_LoadFile_Proxy( 
    IGXTransFact2 __RPC_FAR * This,
    /* [in][string] */ unsigned char __RPC_FAR *pszFileName,
    /* [in] */ EPlayFrameType format,
    /* [out] */ IGXIntBitmap __RPC_FAR *__RPC_FAR *pIBmp,
    /* [in] */ IGXProgressAdviseSink __RPC_FAR *progress,
    /* [out] */ IGXTranslator2 __RPC_FAR *__RPC_FAR *pITrans2);


void __RPC_STUB IGXTransFact2_LoadFile_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IGXTransFact2_INTERFACE_DEFINED__ */


#ifndef __IGXTransFact3_INTERFACE_DEFINED__
#define __IGXTransFact3_INTERFACE_DEFINED__

/****************************************
 * Generated header for interface: IGXTransFact3
 * at Tue Nov 23 05:02:08 1999
 * using MIDL 3.01.75
 ****************************************/
/* [local][uuid][object] */ 



EXTERN_C const IID IID_IGXTransFact3;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    interface DECLSPEC_UUID("8335e6b9-ab3b-11ce-8468-0000b468276b")
    IGXTransFact3 : public IGXTransFact2
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE GetFileType( 
            /* [in][string] */ unsigned char __RPC_FAR *pszFileName,
            /* [in] */ DWORD fileTypeSize,
            /* [out] */ unsigned char __RPC_FAR *szFileTypeName,
            /* [out] */ IGXTranslator3 __RPC_FAR *__RPC_FAR *ppXlator3) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetFileXlator( 
            /* [in] */ DWORD dwID,
            /* [out] */ IGXTranslator3 __RPC_FAR *__RPC_FAR *ppXlator3) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE LoadFile( 
            /* [in][string] */ unsigned char __RPC_FAR *pszFileName,
            /* [in] */ EPlayFrameType format,
            /* [out] */ IGXIntBitmap __RPC_FAR *__RPC_FAR *pIBmp,
            /* [in] */ IGXProgressAdviseSink __RPC_FAR *progress,
            /* [out] */ IGXTranslator3 __RPC_FAR *__RPC_FAR *pITrans3) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetEnumLoaders( 
            /* [out] */ IEnumTranslators2 __RPC_FAR *__RPC_FAR *ppIenum,
            /* [out] */ DWORD __RPC_FAR *pdwMaxTypeSize,
            /* [out] */ DWORD __RPC_FAR *pdwMaxDescripSize) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetEnumSavers( 
            /* [out] */ IEnumTranslators2 __RPC_FAR *__RPC_FAR *ppIenum,
            /* [out] */ DWORD __RPC_FAR *pdwMaxTypeSize,
            /* [out] */ DWORD __RPC_FAR *pdwMaxDescripSize) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE UseBruteForce2Find( 
            /* [in] */ BOOL bUseBruteForce) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetEnumStillLoaders( 
            /* [out] */ IEnumTranslators2 __RPC_FAR *__RPC_FAR *ppIenum,
            /* [out] */ DWORD __RPC_FAR *pdwMaxTypeSize,
            /* [out] */ DWORD __RPC_FAR *pdwMaxDescripSize) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetEnumStillSavers( 
            /* [out] */ IEnumTranslators2 __RPC_FAR *__RPC_FAR *ppIenum,
            /* [out] */ DWORD __RPC_FAR *pdwMaxTypeSize,
            /* [out] */ DWORD __RPC_FAR *pdwMaxDescripSize) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetEnumMovieLoaders( 
            /* [out] */ IEnumTranslators2 __RPC_FAR *__RPC_FAR *ppIenum,
            /* [out] */ DWORD __RPC_FAR *pdwMaxTypeSize,
            /* [out] */ DWORD __RPC_FAR *pdwMaxDescripSize) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetEnumMovieSavers( 
            /* [out] */ IEnumTranslators2 __RPC_FAR *__RPC_FAR *ppIenum,
            /* [out] */ DWORD __RPC_FAR *pdwMaxTypeSize,
            /* [out] */ DWORD __RPC_FAR *pdwMaxDescripSize) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IGXTransFact3Vtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            IGXTransFact3 __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            IGXTransFact3 __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            IGXTransFact3 __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetFileType )( 
            IGXTransFact3 __RPC_FAR * This,
            /* [in][string] */ unsigned char __RPC_FAR *pszFileName,
            /* [in] */ DWORD fileTypeSize,
            /* [out] */ unsigned char __RPC_FAR *szFileTypeName,
            /* [out] */ IGXTranslator __RPC_FAR *__RPC_FAR *ppXlator);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetFileXlator )( 
            IGXTransFact3 __RPC_FAR * This,
            /* [in][string] */ unsigned char __RPC_FAR *szFileTypeName,
            /* [out] */ IGXTranslator __RPC_FAR *__RPC_FAR *ppXlator);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *LoadFile )( 
            IGXTransFact3 __RPC_FAR * This,
            /* [in][string] */ unsigned char __RPC_FAR *pszFileName,
            /* [in] */ EPlayFrameType format,
            /* [out] */ IGXIntBitmap __RPC_FAR *__RPC_FAR *pIBmp,
            /* [in] */ IGXProgressAdviseSink __RPC_FAR *progress,
            /* [out] */ IGXTranslator __RPC_FAR *__RPC_FAR *pITrans);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SaveFile )( 
            IGXTransFact3 __RPC_FAR * This,
            /* [in][string] */ unsigned char __RPC_FAR *pszFileName,
            /* [in] */ IGXIntBitmap __RPC_FAR *pIBmp,
            /* [in] */ IGXProgressAdviseSink __RPC_FAR *progress);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetEnumLoaders )( 
            IGXTransFact3 __RPC_FAR * This,
            /* [out] */ IEnumTranslators __RPC_FAR *__RPC_FAR *ppIenum);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetEnumSavers )( 
            IGXTransFact3 __RPC_FAR * This,
            /* [out] */ IEnumTranslators __RPC_FAR *__RPC_FAR *ppIenum);
        
        void ( STDMETHODCALLTYPE __RPC_FAR *SetClientIO )( 
            IGXTransFact3 __RPC_FAR * This,
            /* [in] */ IGXClientIO __RPC_FAR *pClientIO);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetFrameNumber )( 
            IGXTransFact3 __RPC_FAR * This,
            /* [in] */ DWORD frameNumber);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryFrameNumber )( 
            IGXTransFact3 __RPC_FAR * This,
            /* [out] */ DWORD __RPC_FAR *frameNumber);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryImageHeader )( 
            IGXTransFact3 __RPC_FAR * This,
            /* [in][string] */ unsigned char __RPC_FAR *pszFileName,
            /* [out] */ BITMAPINFOHEADER __RPC_FAR *pBmi,
            /* [out] */ EPlayFrameType __RPC_FAR *format);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryNumberFrames )( 
            IGXTransFact3 __RPC_FAR * This,
            /* [string][in] */ unsigned char __RPC_FAR *pszFileName,
            /* [out] */ DWORD __RPC_FAR *numFrames);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryFrameRate )( 
            IGXTransFact3 __RPC_FAR * This,
            /* [string][in] */ unsigned char __RPC_FAR *pszFileName,
            /* [out] */ DWORD __RPC_FAR *Scale,
            /* [out] */ DWORD __RPC_FAR *Rate);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetFrameRate )( 
            IGXTransFact3 __RPC_FAR * This,
            /* [in] */ DWORD Scale,
            /* [in] */ DWORD Rate);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *UpdateFrameRate )( 
            IGXTransFact3 __RPC_FAR * This,
            /* [string][in] */ unsigned char __RPC_FAR *pszFileName,
            /* [in] */ DWORD Scale,
            /* [in] */ DWORD Rate);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetFileType )( 
            IGXTransFact3 __RPC_FAR * This,
            /* [in][string] */ unsigned char __RPC_FAR *pszFileName,
            /* [in] */ DWORD fileTypeSize,
            /* [out] */ unsigned char __RPC_FAR *szFileTypeName,
            /* [out] */ IGXTranslator2 __RPC_FAR *__RPC_FAR *ppXlator2);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetFileXlator )( 
            IGXTransFact3 __RPC_FAR * This,
            /* [in][string] */ unsigned char __RPC_FAR *szFileTypeName,
            /* [out] */ IGXTranslator2 __RPC_FAR *__RPC_FAR *ppXlator2);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *LoadFile )( 
            IGXTransFact3 __RPC_FAR * This,
            /* [in][string] */ unsigned char __RPC_FAR *pszFileName,
            /* [in] */ EPlayFrameType format,
            /* [out] */ IGXIntBitmap __RPC_FAR *__RPC_FAR *pIBmp,
            /* [in] */ IGXProgressAdviseSink __RPC_FAR *progress,
            /* [out] */ IGXTranslator2 __RPC_FAR *__RPC_FAR *pITrans2);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetFileType )( 
            IGXTransFact3 __RPC_FAR * This,
            /* [in][string] */ unsigned char __RPC_FAR *pszFileName,
            /* [in] */ DWORD fileTypeSize,
            /* [out] */ unsigned char __RPC_FAR *szFileTypeName,
            /* [out] */ IGXTranslator3 __RPC_FAR *__RPC_FAR *ppXlator3);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetFileXlator )( 
            IGXTransFact3 __RPC_FAR * This,
            /* [in] */ DWORD dwID,
            /* [out] */ IGXTranslator3 __RPC_FAR *__RPC_FAR *ppXlator3);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *LoadFile )( 
            IGXTransFact3 __RPC_FAR * This,
            /* [in][string] */ unsigned char __RPC_FAR *pszFileName,
            /* [in] */ EPlayFrameType format,
            /* [out] */ IGXIntBitmap __RPC_FAR *__RPC_FAR *pIBmp,
            /* [in] */ IGXProgressAdviseSink __RPC_FAR *progress,
            /* [out] */ IGXTranslator3 __RPC_FAR *__RPC_FAR *pITrans3);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetEnumLoaders )( 
            IGXTransFact3 __RPC_FAR * This,
            /* [out] */ IEnumTranslators2 __RPC_FAR *__RPC_FAR *ppIenum,
            /* [out] */ DWORD __RPC_FAR *pdwMaxTypeSize,
            /* [out] */ DWORD __RPC_FAR *pdwMaxDescripSize);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetEnumSavers )( 
            IGXTransFact3 __RPC_FAR * This,
            /* [out] */ IEnumTranslators2 __RPC_FAR *__RPC_FAR *ppIenum,
            /* [out] */ DWORD __RPC_FAR *pdwMaxTypeSize,
            /* [out] */ DWORD __RPC_FAR *pdwMaxDescripSize);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *UseBruteForce2Find )( 
            IGXTransFact3 __RPC_FAR * This,
            /* [in] */ BOOL bUseBruteForce);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetEnumStillLoaders )( 
            IGXTransFact3 __RPC_FAR * This,
            /* [out] */ IEnumTranslators2 __RPC_FAR *__RPC_FAR *ppIenum,
            /* [out] */ DWORD __RPC_FAR *pdwMaxTypeSize,
            /* [out] */ DWORD __RPC_FAR *pdwMaxDescripSize);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetEnumStillSavers )( 
            IGXTransFact3 __RPC_FAR * This,
            /* [out] */ IEnumTranslators2 __RPC_FAR *__RPC_FAR *ppIenum,
            /* [out] */ DWORD __RPC_FAR *pdwMaxTypeSize,
            /* [out] */ DWORD __RPC_FAR *pdwMaxDescripSize);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetEnumMovieLoaders )( 
            IGXTransFact3 __RPC_FAR * This,
            /* [out] */ IEnumTranslators2 __RPC_FAR *__RPC_FAR *ppIenum,
            /* [out] */ DWORD __RPC_FAR *pdwMaxTypeSize,
            /* [out] */ DWORD __RPC_FAR *pdwMaxDescripSize);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetEnumMovieSavers )( 
            IGXTransFact3 __RPC_FAR * This,
            /* [out] */ IEnumTranslators2 __RPC_FAR *__RPC_FAR *ppIenum,
            /* [out] */ DWORD __RPC_FAR *pdwMaxTypeSize,
            /* [out] */ DWORD __RPC_FAR *pdwMaxDescripSize);
        
        END_INTERFACE
    } IGXTransFact3Vtbl;

    interface IGXTransFact3
    {
        CONST_VTBL struct IGXTransFact3Vtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IGXTransFact3_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IGXTransFact3_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IGXTransFact3_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IGXTransFact3_GetFileType(This,pszFileName,fileTypeSize,szFileTypeName,ppXlator)	\
    (This)->lpVtbl -> GetFileType(This,pszFileName,fileTypeSize,szFileTypeName,ppXlator)

#define IGXTransFact3_GetFileXlator(This,szFileTypeName,ppXlator)	\
    (This)->lpVtbl -> GetFileXlator(This,szFileTypeName,ppXlator)

#define IGXTransFact3_LoadFile(This,pszFileName,format,pIBmp,progress,pITrans)	\
    (This)->lpVtbl -> LoadFile(This,pszFileName,format,pIBmp,progress,pITrans)

#define IGXTransFact3_SaveFile(This,pszFileName,pIBmp,progress)	\
    (This)->lpVtbl -> SaveFile(This,pszFileName,pIBmp,progress)

#define IGXTransFact3_GetEnumLoaders(This,ppIenum)	\
    (This)->lpVtbl -> GetEnumLoaders(This,ppIenum)

#define IGXTransFact3_GetEnumSavers(This,ppIenum)	\
    (This)->lpVtbl -> GetEnumSavers(This,ppIenum)

#define IGXTransFact3_SetClientIO(This,pClientIO)	\
    (This)->lpVtbl -> SetClientIO(This,pClientIO)


#define IGXTransFact3_SetFrameNumber(This,frameNumber)	\
    (This)->lpVtbl -> SetFrameNumber(This,frameNumber)

#define IGXTransFact3_QueryFrameNumber(This,frameNumber)	\
    (This)->lpVtbl -> QueryFrameNumber(This,frameNumber)

#define IGXTransFact3_QueryImageHeader(This,pszFileName,pBmi,format)	\
    (This)->lpVtbl -> QueryImageHeader(This,pszFileName,pBmi,format)

#define IGXTransFact3_QueryNumberFrames(This,pszFileName,numFrames)	\
    (This)->lpVtbl -> QueryNumberFrames(This,pszFileName,numFrames)

#define IGXTransFact3_QueryFrameRate(This,pszFileName,Scale,Rate)	\
    (This)->lpVtbl -> QueryFrameRate(This,pszFileName,Scale,Rate)

#define IGXTransFact3_SetFrameRate(This,Scale,Rate)	\
    (This)->lpVtbl -> SetFrameRate(This,Scale,Rate)

#define IGXTransFact3_UpdateFrameRate(This,pszFileName,Scale,Rate)	\
    (This)->lpVtbl -> UpdateFrameRate(This,pszFileName,Scale,Rate)

#define IGXTransFact3_GetFileType(This,pszFileName,fileTypeSize,szFileTypeName,ppXlator2)	\
    (This)->lpVtbl -> GetFileType(This,pszFileName,fileTypeSize,szFileTypeName,ppXlator2)

#define IGXTransFact3_GetFileXlator(This,szFileTypeName,ppXlator2)	\
    (This)->lpVtbl -> GetFileXlator(This,szFileTypeName,ppXlator2)

#define IGXTransFact3_LoadFile(This,pszFileName,format,pIBmp,progress,pITrans2)	\
    (This)->lpVtbl -> LoadFile(This,pszFileName,format,pIBmp,progress,pITrans2)


#define IGXTransFact3_GetFileType(This,pszFileName,fileTypeSize,szFileTypeName,ppXlator3)	\
    (This)->lpVtbl -> GetFileType(This,pszFileName,fileTypeSize,szFileTypeName,ppXlator3)

#define IGXTransFact3_GetFileXlator(This,dwID,ppXlator3)	\
    (This)->lpVtbl -> GetFileXlator(This,dwID,ppXlator3)

#define IGXTransFact3_LoadFile(This,pszFileName,format,pIBmp,progress,pITrans3)	\
    (This)->lpVtbl -> LoadFile(This,pszFileName,format,pIBmp,progress,pITrans3)

#define IGXTransFact3_GetEnumLoaders(This,ppIenum,pdwMaxTypeSize,pdwMaxDescripSize)	\
    (This)->lpVtbl -> GetEnumLoaders(This,ppIenum,pdwMaxTypeSize,pdwMaxDescripSize)

#define IGXTransFact3_GetEnumSavers(This,ppIenum,pdwMaxTypeSize,pdwMaxDescripSize)	\
    (This)->lpVtbl -> GetEnumSavers(This,ppIenum,pdwMaxTypeSize,pdwMaxDescripSize)

#define IGXTransFact3_UseBruteForce2Find(This,bUseBruteForce)	\
    (This)->lpVtbl -> UseBruteForce2Find(This,bUseBruteForce)

#define IGXTransFact3_GetEnumStillLoaders(This,ppIenum,pdwMaxTypeSize,pdwMaxDescripSize)	\
    (This)->lpVtbl -> GetEnumStillLoaders(This,ppIenum,pdwMaxTypeSize,pdwMaxDescripSize)

#define IGXTransFact3_GetEnumStillSavers(This,ppIenum,pdwMaxTypeSize,pdwMaxDescripSize)	\
    (This)->lpVtbl -> GetEnumStillSavers(This,ppIenum,pdwMaxTypeSize,pdwMaxDescripSize)

#define IGXTransFact3_GetEnumMovieLoaders(This,ppIenum,pdwMaxTypeSize,pdwMaxDescripSize)	\
    (This)->lpVtbl -> GetEnumMovieLoaders(This,ppIenum,pdwMaxTypeSize,pdwMaxDescripSize)

#define IGXTransFact3_GetEnumMovieSavers(This,ppIenum,pdwMaxTypeSize,pdwMaxDescripSize)	\
    (This)->lpVtbl -> GetEnumMovieSavers(This,ppIenum,pdwMaxTypeSize,pdwMaxDescripSize)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE IGXTransFact3_GetFileType_Proxy( 
    IGXTransFact3 __RPC_FAR * This,
    /* [in][string] */ unsigned char __RPC_FAR *pszFileName,
    /* [in] */ DWORD fileTypeSize,
    /* [out] */ unsigned char __RPC_FAR *szFileTypeName,
    /* [out] */ IGXTranslator3 __RPC_FAR *__RPC_FAR *ppXlator3);


void __RPC_STUB IGXTransFact3_GetFileType_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IGXTransFact3_GetFileXlator_Proxy( 
    IGXTransFact3 __RPC_FAR * This,
    /* [in] */ DWORD dwID,
    /* [out] */ IGXTranslator3 __RPC_FAR *__RPC_FAR *ppXlator3);


void __RPC_STUB IGXTransFact3_GetFileXlator_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IGXTransFact3_LoadFile_Proxy( 
    IGXTransFact3 __RPC_FAR * This,
    /* [in][string] */ unsigned char __RPC_FAR *pszFileName,
    /* [in] */ EPlayFrameType format,
    /* [out] */ IGXIntBitmap __RPC_FAR *__RPC_FAR *pIBmp,
    /* [in] */ IGXProgressAdviseSink __RPC_FAR *progress,
    /* [out] */ IGXTranslator3 __RPC_FAR *__RPC_FAR *pITrans3);


void __RPC_STUB IGXTransFact3_LoadFile_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IGXTransFact3_GetEnumLoaders_Proxy( 
    IGXTransFact3 __RPC_FAR * This,
    /* [out] */ IEnumTranslators2 __RPC_FAR *__RPC_FAR *ppIenum,
    /* [out] */ DWORD __RPC_FAR *pdwMaxTypeSize,
    /* [out] */ DWORD __RPC_FAR *pdwMaxDescripSize);


void __RPC_STUB IGXTransFact3_GetEnumLoaders_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IGXTransFact3_GetEnumSavers_Proxy( 
    IGXTransFact3 __RPC_FAR * This,
    /* [out] */ IEnumTranslators2 __RPC_FAR *__RPC_FAR *ppIenum,
    /* [out] */ DWORD __RPC_FAR *pdwMaxTypeSize,
    /* [out] */ DWORD __RPC_FAR *pdwMaxDescripSize);


void __RPC_STUB IGXTransFact3_GetEnumSavers_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IGXTransFact3_UseBruteForce2Find_Proxy( 
    IGXTransFact3 __RPC_FAR * This,
    /* [in] */ BOOL bUseBruteForce);


void __RPC_STUB IGXTransFact3_UseBruteForce2Find_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IGXTransFact3_GetEnumStillLoaders_Proxy( 
    IGXTransFact3 __RPC_FAR * This,
    /* [out] */ IEnumTranslators2 __RPC_FAR *__RPC_FAR *ppIenum,
    /* [out] */ DWORD __RPC_FAR *pdwMaxTypeSize,
    /* [out] */ DWORD __RPC_FAR *pdwMaxDescripSize);


void __RPC_STUB IGXTransFact3_GetEnumStillLoaders_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IGXTransFact3_GetEnumStillSavers_Proxy( 
    IGXTransFact3 __RPC_FAR * This,
    /* [out] */ IEnumTranslators2 __RPC_FAR *__RPC_FAR *ppIenum,
    /* [out] */ DWORD __RPC_FAR *pdwMaxTypeSize,
    /* [out] */ DWORD __RPC_FAR *pdwMaxDescripSize);


void __RPC_STUB IGXTransFact3_GetEnumStillSavers_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IGXTransFact3_GetEnumMovieLoaders_Proxy( 
    IGXTransFact3 __RPC_FAR * This,
    /* [out] */ IEnumTranslators2 __RPC_FAR *__RPC_FAR *ppIenum,
    /* [out] */ DWORD __RPC_FAR *pdwMaxTypeSize,
    /* [out] */ DWORD __RPC_FAR *pdwMaxDescripSize);


void __RPC_STUB IGXTransFact3_GetEnumMovieLoaders_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IGXTransFact3_GetEnumMovieSavers_Proxy( 
    IGXTransFact3 __RPC_FAR * This,
    /* [out] */ IEnumTranslators2 __RPC_FAR *__RPC_FAR *ppIenum,
    /* [out] */ DWORD __RPC_FAR *pdwMaxTypeSize,
    /* [out] */ DWORD __RPC_FAR *pdwMaxDescripSize);


void __RPC_STUB IGXTransFact3_GetEnumMovieSavers_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IGXTransFact3_INTERFACE_DEFINED__ */


#ifndef __IGXTransFact4_INTERFACE_DEFINED__
#define __IGXTransFact4_INTERFACE_DEFINED__

/****************************************
 * Generated header for interface: IGXTransFact4
 * at Tue Nov 23 05:02:08 1999
 * using MIDL 3.01.75
 ****************************************/
/* [local][uuid][object] */ 


typedef 
enum tagTranslatorType
    {	TYPENULL	= 0,
	TYPELOAD	= 0x1,
	TYPESAVE	= 0x2,
	TYPELOADSAVE	= TYPELOAD | TYPESAVE
    }	TranslatorType;


EXTERN_C const IID IID_IGXTransFact4;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    interface DECLSPEC_UUID("8335e6bc-ab3b-11ce-8468-0000b468276b")
    IGXTransFact4 : public IGXTransFact3
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE GetFileType( 
            /* [in][string] */ LPTSTR pszFileName,
            /* [in] */ DWORD fileTypeSize,
            /* [out] */ LPTSTR szFileTypeName,
            /* [out] */ IGXTranslator4 __RPC_FAR *__RPC_FAR *ppXlator4,
            /* [in] */ TranslatorType Type) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetFileXlator( 
            /* [in] */ DWORD dwID,
            /* [out] */ IGXTranslator4 __RPC_FAR *__RPC_FAR *ppXlator4) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE LoadFile( 
            /* [in][string] */ LPTSTR pszFileName,
            /* [in] */ EPlayFrameType format,
            /* [out] */ IGXIntBitmap2 __RPC_FAR *__RPC_FAR *pIBmp,
            /* [in] */ IGXProgressAdviseSink __RPC_FAR *progress,
            /* [out] */ IGXTranslator4 __RPC_FAR *__RPC_FAR *pITrans4,
            /* [in] */ TranslatorType Type) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE LoadFileToBuffer( 
            /* [in][string] */ LPTSTR pszFileName,
            /* [in] */ EPlayFrameType format,
            /* [out] */ IGXIntBitmap2 __RPC_FAR *__RPC_FAR *ppIBmp,
            /* [in] */ IGXProgressAdviseSink __RPC_FAR *progress,
            /* [out] */ IGXTranslator4 __RPC_FAR *__RPC_FAR *pITrans4,
            /* [in] */ BITMAPINFOHEADER __RPC_FAR *imageHeader,
            /* [in][string] */ unsigned char __RPC_FAR *buffer,
            /* [in] */ DWORD __RPC_FAR *size,
            /* [in] */ TranslatorType Type) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetAlphaColor( 
            /* [in] */ WORD col1,
            /* [in] */ WORD col2,
            /* [in] */ WORD col3) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetDefaultImageColor( 
            /* [in] */ WORD col1,
            /* [in] */ WORD col2,
            /* [in] */ WORD col3) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetFileMatchOptions( 
            /* [in] */ FileNameMatchOptions __RPC_FAR *Opt) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetFileMatchOptions( 
            /* [in] */ FileNameMatchOptions __RPC_FAR *Opt) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE ConfigDialogExecute( 
            /* [in][string] */ LPTSTR pszFileName,
            /* [in] */ IGXOptionsCallback __RPC_FAR *Callback) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE LoadConfigFromStream( 
            /* [in] */ IStream __RPC_FAR *stream) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SaveConfigToStream( 
            /* [in] */ IStream __RPC_FAR *stream) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SaveConfigToBuffer( 
            /* [in] */ PlayXlatorOpt __RPC_FAR *Opt) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE LoadConfigFromBuffer( 
            /* [in] */ PlayXlatorOpt __RPC_FAR *Opt) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetDefaultCompressionLevel( 
            /* [in] */ WORD compressLevel) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetDefaultCompressionLevel( 
            /* [out] */ WORD __RPC_FAR *compressLevel) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetDefaultFrameRate( 
            /* [out] */ DWORD __RPC_FAR *Scale,
            /* [out] */ DWORD __RPC_FAR *Rate) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetDefaultFrameRate( 
            /* [in] */ DWORD Scale,
            /* [in] */ DWORD Rate) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetDefaultLoadScale( 
            /* [in] */ DWORD dwNumerator,
            /* [in] */ DWORD dwDenominator) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetDefaultLoadScale( 
            /* [out] */ DWORD __RPC_FAR *dwNumerator,
            /* [out] */ DWORD __RPC_FAR *dwDenominator) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IGXTransFact4Vtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            IGXTransFact4 __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            IGXTransFact4 __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            IGXTransFact4 __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetFileType )( 
            IGXTransFact4 __RPC_FAR * This,
            /* [in][string] */ unsigned char __RPC_FAR *pszFileName,
            /* [in] */ DWORD fileTypeSize,
            /* [out] */ unsigned char __RPC_FAR *szFileTypeName,
            /* [out] */ IGXTranslator __RPC_FAR *__RPC_FAR *ppXlator);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetFileXlator )( 
            IGXTransFact4 __RPC_FAR * This,
            /* [in][string] */ unsigned char __RPC_FAR *szFileTypeName,
            /* [out] */ IGXTranslator __RPC_FAR *__RPC_FAR *ppXlator);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *LoadFile )( 
            IGXTransFact4 __RPC_FAR * This,
            /* [in][string] */ unsigned char __RPC_FAR *pszFileName,
            /* [in] */ EPlayFrameType format,
            /* [out] */ IGXIntBitmap __RPC_FAR *__RPC_FAR *pIBmp,
            /* [in] */ IGXProgressAdviseSink __RPC_FAR *progress,
            /* [out] */ IGXTranslator __RPC_FAR *__RPC_FAR *pITrans);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SaveFile )( 
            IGXTransFact4 __RPC_FAR * This,
            /* [in][string] */ unsigned char __RPC_FAR *pszFileName,
            /* [in] */ IGXIntBitmap __RPC_FAR *pIBmp,
            /* [in] */ IGXProgressAdviseSink __RPC_FAR *progress);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetEnumLoaders )( 
            IGXTransFact4 __RPC_FAR * This,
            /* [out] */ IEnumTranslators __RPC_FAR *__RPC_FAR *ppIenum);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetEnumSavers )( 
            IGXTransFact4 __RPC_FAR * This,
            /* [out] */ IEnumTranslators __RPC_FAR *__RPC_FAR *ppIenum);
        
        void ( STDMETHODCALLTYPE __RPC_FAR *SetClientIO )( 
            IGXTransFact4 __RPC_FAR * This,
            /* [in] */ IGXClientIO __RPC_FAR *pClientIO);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetFrameNumber )( 
            IGXTransFact4 __RPC_FAR * This,
            /* [in] */ DWORD frameNumber);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryFrameNumber )( 
            IGXTransFact4 __RPC_FAR * This,
            /* [out] */ DWORD __RPC_FAR *frameNumber);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryImageHeader )( 
            IGXTransFact4 __RPC_FAR * This,
            /* [in][string] */ unsigned char __RPC_FAR *pszFileName,
            /* [out] */ BITMAPINFOHEADER __RPC_FAR *pBmi,
            /* [out] */ EPlayFrameType __RPC_FAR *format);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryNumberFrames )( 
            IGXTransFact4 __RPC_FAR * This,
            /* [string][in] */ unsigned char __RPC_FAR *pszFileName,
            /* [out] */ DWORD __RPC_FAR *numFrames);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryFrameRate )( 
            IGXTransFact4 __RPC_FAR * This,
            /* [string][in] */ unsigned char __RPC_FAR *pszFileName,
            /* [out] */ DWORD __RPC_FAR *Scale,
            /* [out] */ DWORD __RPC_FAR *Rate);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetFrameRate )( 
            IGXTransFact4 __RPC_FAR * This,
            /* [in] */ DWORD Scale,
            /* [in] */ DWORD Rate);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *UpdateFrameRate )( 
            IGXTransFact4 __RPC_FAR * This,
            /* [string][in] */ unsigned char __RPC_FAR *pszFileName,
            /* [in] */ DWORD Scale,
            /* [in] */ DWORD Rate);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetFileType )( 
            IGXTransFact4 __RPC_FAR * This,
            /* [in][string] */ unsigned char __RPC_FAR *pszFileName,
            /* [in] */ DWORD fileTypeSize,
            /* [out] */ unsigned char __RPC_FAR *szFileTypeName,
            /* [out] */ IGXTranslator2 __RPC_FAR *__RPC_FAR *ppXlator2);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetFileXlator )( 
            IGXTransFact4 __RPC_FAR * This,
            /* [in][string] */ unsigned char __RPC_FAR *szFileTypeName,
            /* [out] */ IGXTranslator2 __RPC_FAR *__RPC_FAR *ppXlator2);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *LoadFile )( 
            IGXTransFact4 __RPC_FAR * This,
            /* [in][string] */ unsigned char __RPC_FAR *pszFileName,
            /* [in] */ EPlayFrameType format,
            /* [out] */ IGXIntBitmap __RPC_FAR *__RPC_FAR *pIBmp,
            /* [in] */ IGXProgressAdviseSink __RPC_FAR *progress,
            /* [out] */ IGXTranslator2 __RPC_FAR *__RPC_FAR *pITrans2);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetFileType )( 
            IGXTransFact4 __RPC_FAR * This,
            /* [in][string] */ unsigned char __RPC_FAR *pszFileName,
            /* [in] */ DWORD fileTypeSize,
            /* [out] */ unsigned char __RPC_FAR *szFileTypeName,
            /* [out] */ IGXTranslator3 __RPC_FAR *__RPC_FAR *ppXlator3);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetFileXlator )( 
            IGXTransFact4 __RPC_FAR * This,
            /* [in] */ DWORD dwID,
            /* [out] */ IGXTranslator3 __RPC_FAR *__RPC_FAR *ppXlator3);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *LoadFile )( 
            IGXTransFact4 __RPC_FAR * This,
            /* [in][string] */ unsigned char __RPC_FAR *pszFileName,
            /* [in] */ EPlayFrameType format,
            /* [out] */ IGXIntBitmap __RPC_FAR *__RPC_FAR *pIBmp,
            /* [in] */ IGXProgressAdviseSink __RPC_FAR *progress,
            /* [out] */ IGXTranslator3 __RPC_FAR *__RPC_FAR *pITrans3);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetEnumLoaders )( 
            IGXTransFact4 __RPC_FAR * This,
            /* [out] */ IEnumTranslators2 __RPC_FAR *__RPC_FAR *ppIenum,
            /* [out] */ DWORD __RPC_FAR *pdwMaxTypeSize,
            /* [out] */ DWORD __RPC_FAR *pdwMaxDescripSize);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetEnumSavers )( 
            IGXTransFact4 __RPC_FAR * This,
            /* [out] */ IEnumTranslators2 __RPC_FAR *__RPC_FAR *ppIenum,
            /* [out] */ DWORD __RPC_FAR *pdwMaxTypeSize,
            /* [out] */ DWORD __RPC_FAR *pdwMaxDescripSize);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *UseBruteForce2Find )( 
            IGXTransFact4 __RPC_FAR * This,
            /* [in] */ BOOL bUseBruteForce);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetEnumStillLoaders )( 
            IGXTransFact4 __RPC_FAR * This,
            /* [out] */ IEnumTranslators2 __RPC_FAR *__RPC_FAR *ppIenum,
            /* [out] */ DWORD __RPC_FAR *pdwMaxTypeSize,
            /* [out] */ DWORD __RPC_FAR *pdwMaxDescripSize);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetEnumStillSavers )( 
            IGXTransFact4 __RPC_FAR * This,
            /* [out] */ IEnumTranslators2 __RPC_FAR *__RPC_FAR *ppIenum,
            /* [out] */ DWORD __RPC_FAR *pdwMaxTypeSize,
            /* [out] */ DWORD __RPC_FAR *pdwMaxDescripSize);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetEnumMovieLoaders )( 
            IGXTransFact4 __RPC_FAR * This,
            /* [out] */ IEnumTranslators2 __RPC_FAR *__RPC_FAR *ppIenum,
            /* [out] */ DWORD __RPC_FAR *pdwMaxTypeSize,
            /* [out] */ DWORD __RPC_FAR *pdwMaxDescripSize);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetEnumMovieSavers )( 
            IGXTransFact4 __RPC_FAR * This,
            /* [out] */ IEnumTranslators2 __RPC_FAR *__RPC_FAR *ppIenum,
            /* [out] */ DWORD __RPC_FAR *pdwMaxTypeSize,
            /* [out] */ DWORD __RPC_FAR *pdwMaxDescripSize);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetFileType )( 
            IGXTransFact4 __RPC_FAR * This,
            /* [in][string] */ LPTSTR pszFileName,
            /* [in] */ DWORD fileTypeSize,
            /* [out] */ LPTSTR szFileTypeName,
            /* [out] */ IGXTranslator4 __RPC_FAR *__RPC_FAR *ppXlator4,
            /* [in] */ TranslatorType Type);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetFileXlator )( 
            IGXTransFact4 __RPC_FAR * This,
            /* [in] */ DWORD dwID,
            /* [out] */ IGXTranslator4 __RPC_FAR *__RPC_FAR *ppXlator4);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *LoadFile )( 
            IGXTransFact4 __RPC_FAR * This,
            /* [in][string] */ LPTSTR pszFileName,
            /* [in] */ EPlayFrameType format,
            /* [out] */ IGXIntBitmap2 __RPC_FAR *__RPC_FAR *pIBmp,
            /* [in] */ IGXProgressAdviseSink __RPC_FAR *progress,
            /* [out] */ IGXTranslator4 __RPC_FAR *__RPC_FAR *pITrans4,
            /* [in] */ TranslatorType Type);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *LoadFileToBuffer )( 
            IGXTransFact4 __RPC_FAR * This,
            /* [in][string] */ LPTSTR pszFileName,
            /* [in] */ EPlayFrameType format,
            /* [out] */ IGXIntBitmap2 __RPC_FAR *__RPC_FAR *ppIBmp,
            /* [in] */ IGXProgressAdviseSink __RPC_FAR *progress,
            /* [out] */ IGXTranslator4 __RPC_FAR *__RPC_FAR *pITrans4,
            /* [in] */ BITMAPINFOHEADER __RPC_FAR *imageHeader,
            /* [in][string] */ unsigned char __RPC_FAR *buffer,
            /* [in] */ DWORD __RPC_FAR *size,
            /* [in] */ TranslatorType Type);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetAlphaColor )( 
            IGXTransFact4 __RPC_FAR * This,
            /* [in] */ WORD col1,
            /* [in] */ WORD col2,
            /* [in] */ WORD col3);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetDefaultImageColor )( 
            IGXTransFact4 __RPC_FAR * This,
            /* [in] */ WORD col1,
            /* [in] */ WORD col2,
            /* [in] */ WORD col3);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetFileMatchOptions )( 
            IGXTransFact4 __RPC_FAR * This,
            /* [in] */ FileNameMatchOptions __RPC_FAR *Opt);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetFileMatchOptions )( 
            IGXTransFact4 __RPC_FAR * This,
            /* [in] */ FileNameMatchOptions __RPC_FAR *Opt);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *ConfigDialogExecute )( 
            IGXTransFact4 __RPC_FAR * This,
            /* [in][string] */ LPTSTR pszFileName,
            /* [in] */ IGXOptionsCallback __RPC_FAR *Callback);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *LoadConfigFromStream )( 
            IGXTransFact4 __RPC_FAR * This,
            /* [in] */ IStream __RPC_FAR *stream);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SaveConfigToStream )( 
            IGXTransFact4 __RPC_FAR * This,
            /* [in] */ IStream __RPC_FAR *stream);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SaveConfigToBuffer )( 
            IGXTransFact4 __RPC_FAR * This,
            /* [in] */ PlayXlatorOpt __RPC_FAR *Opt);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *LoadConfigFromBuffer )( 
            IGXTransFact4 __RPC_FAR * This,
            /* [in] */ PlayXlatorOpt __RPC_FAR *Opt);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetDefaultCompressionLevel )( 
            IGXTransFact4 __RPC_FAR * This,
            /* [in] */ WORD compressLevel);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetDefaultCompressionLevel )( 
            IGXTransFact4 __RPC_FAR * This,
            /* [out] */ WORD __RPC_FAR *compressLevel);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetDefaultFrameRate )( 
            IGXTransFact4 __RPC_FAR * This,
            /* [out] */ DWORD __RPC_FAR *Scale,
            /* [out] */ DWORD __RPC_FAR *Rate);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetDefaultFrameRate )( 
            IGXTransFact4 __RPC_FAR * This,
            /* [in] */ DWORD Scale,
            /* [in] */ DWORD Rate);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetDefaultLoadScale )( 
            IGXTransFact4 __RPC_FAR * This,
            /* [in] */ DWORD dwNumerator,
            /* [in] */ DWORD dwDenominator);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetDefaultLoadScale )( 
            IGXTransFact4 __RPC_FAR * This,
            /* [out] */ DWORD __RPC_FAR *dwNumerator,
            /* [out] */ DWORD __RPC_FAR *dwDenominator);
        
        END_INTERFACE
    } IGXTransFact4Vtbl;

    interface IGXTransFact4
    {
        CONST_VTBL struct IGXTransFact4Vtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IGXTransFact4_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IGXTransFact4_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IGXTransFact4_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IGXTransFact4_GetFileType(This,pszFileName,fileTypeSize,szFileTypeName,ppXlator)	\
    (This)->lpVtbl -> GetFileType(This,pszFileName,fileTypeSize,szFileTypeName,ppXlator)

#define IGXTransFact4_GetFileXlator(This,szFileTypeName,ppXlator)	\
    (This)->lpVtbl -> GetFileXlator(This,szFileTypeName,ppXlator)

#define IGXTransFact4_LoadFile(This,pszFileName,format,pIBmp,progress,pITrans)	\
    (This)->lpVtbl -> LoadFile(This,pszFileName,format,pIBmp,progress,pITrans)

#define IGXTransFact4_SaveFile(This,pszFileName,pIBmp,progress)	\
    (This)->lpVtbl -> SaveFile(This,pszFileName,pIBmp,progress)

#define IGXTransFact4_GetEnumLoaders(This,ppIenum)	\
    (This)->lpVtbl -> GetEnumLoaders(This,ppIenum)

#define IGXTransFact4_GetEnumSavers(This,ppIenum)	\
    (This)->lpVtbl -> GetEnumSavers(This,ppIenum)

#define IGXTransFact4_SetClientIO(This,pClientIO)	\
    (This)->lpVtbl -> SetClientIO(This,pClientIO)


#define IGXTransFact4_SetFrameNumber(This,frameNumber)	\
    (This)->lpVtbl -> SetFrameNumber(This,frameNumber)

#define IGXTransFact4_QueryFrameNumber(This,frameNumber)	\
    (This)->lpVtbl -> QueryFrameNumber(This,frameNumber)

#define IGXTransFact4_QueryImageHeader(This,pszFileName,pBmi,format)	\
    (This)->lpVtbl -> QueryImageHeader(This,pszFileName,pBmi,format)

#define IGXTransFact4_QueryNumberFrames(This,pszFileName,numFrames)	\
    (This)->lpVtbl -> QueryNumberFrames(This,pszFileName,numFrames)

#define IGXTransFact4_QueryFrameRate(This,pszFileName,Scale,Rate)	\
    (This)->lpVtbl -> QueryFrameRate(This,pszFileName,Scale,Rate)

#define IGXTransFact4_SetFrameRate(This,Scale,Rate)	\
    (This)->lpVtbl -> SetFrameRate(This,Scale,Rate)

#define IGXTransFact4_UpdateFrameRate(This,pszFileName,Scale,Rate)	\
    (This)->lpVtbl -> UpdateFrameRate(This,pszFileName,Scale,Rate)

#define IGXTransFact4_GetFileType(This,pszFileName,fileTypeSize,szFileTypeName,ppXlator2)	\
    (This)->lpVtbl -> GetFileType(This,pszFileName,fileTypeSize,szFileTypeName,ppXlator2)

#define IGXTransFact4_GetFileXlator(This,szFileTypeName,ppXlator2)	\
    (This)->lpVtbl -> GetFileXlator(This,szFileTypeName,ppXlator2)

#define IGXTransFact4_LoadFile(This,pszFileName,format,pIBmp,progress,pITrans2)	\
    (This)->lpVtbl -> LoadFile(This,pszFileName,format,pIBmp,progress,pITrans2)


#define IGXTransFact4_GetFileType(This,pszFileName,fileTypeSize,szFileTypeName,ppXlator3)	\
    (This)->lpVtbl -> GetFileType(This,pszFileName,fileTypeSize,szFileTypeName,ppXlator3)

#define IGXTransFact4_GetFileXlator(This,dwID,ppXlator3)	\
    (This)->lpVtbl -> GetFileXlator(This,dwID,ppXlator3)

#define IGXTransFact4_LoadFile(This,pszFileName,format,pIBmp,progress,pITrans3)	\
    (This)->lpVtbl -> LoadFile(This,pszFileName,format,pIBmp,progress,pITrans3)

#define IGXTransFact4_GetEnumLoaders(This,ppIenum,pdwMaxTypeSize,pdwMaxDescripSize)	\
    (This)->lpVtbl -> GetEnumLoaders(This,ppIenum,pdwMaxTypeSize,pdwMaxDescripSize)

#define IGXTransFact4_GetEnumSavers(This,ppIenum,pdwMaxTypeSize,pdwMaxDescripSize)	\
    (This)->lpVtbl -> GetEnumSavers(This,ppIenum,pdwMaxTypeSize,pdwMaxDescripSize)

#define IGXTransFact4_UseBruteForce2Find(This,bUseBruteForce)	\
    (This)->lpVtbl -> UseBruteForce2Find(This,bUseBruteForce)

#define IGXTransFact4_GetEnumStillLoaders(This,ppIenum,pdwMaxTypeSize,pdwMaxDescripSize)	\
    (This)->lpVtbl -> GetEnumStillLoaders(This,ppIenum,pdwMaxTypeSize,pdwMaxDescripSize)

#define IGXTransFact4_GetEnumStillSavers(This,ppIenum,pdwMaxTypeSize,pdwMaxDescripSize)	\
    (This)->lpVtbl -> GetEnumStillSavers(This,ppIenum,pdwMaxTypeSize,pdwMaxDescripSize)

#define IGXTransFact4_GetEnumMovieLoaders(This,ppIenum,pdwMaxTypeSize,pdwMaxDescripSize)	\
    (This)->lpVtbl -> GetEnumMovieLoaders(This,ppIenum,pdwMaxTypeSize,pdwMaxDescripSize)

#define IGXTransFact4_GetEnumMovieSavers(This,ppIenum,pdwMaxTypeSize,pdwMaxDescripSize)	\
    (This)->lpVtbl -> GetEnumMovieSavers(This,ppIenum,pdwMaxTypeSize,pdwMaxDescripSize)


#define IGXTransFact4_GetFileType(This,pszFileName,fileTypeSize,szFileTypeName,ppXlator4,Type)	\
    (This)->lpVtbl -> GetFileType(This,pszFileName,fileTypeSize,szFileTypeName,ppXlator4,Type)

#define IGXTransFact4_GetFileXlator(This,dwID,ppXlator4)	\
    (This)->lpVtbl -> GetFileXlator(This,dwID,ppXlator4)

#define IGXTransFact4_LoadFile(This,pszFileName,format,pIBmp,progress,pITrans4,Type)	\
    (This)->lpVtbl -> LoadFile(This,pszFileName,format,pIBmp,progress,pITrans4,Type)

#define IGXTransFact4_LoadFileToBuffer(This,pszFileName,format,ppIBmp,progress,pITrans4,imageHeader,buffer,size,Type)	\
    (This)->lpVtbl -> LoadFileToBuffer(This,pszFileName,format,ppIBmp,progress,pITrans4,imageHeader,buffer,size,Type)

#define IGXTransFact4_SetAlphaColor(This,col1,col2,col3)	\
    (This)->lpVtbl -> SetAlphaColor(This,col1,col2,col3)

#define IGXTransFact4_SetDefaultImageColor(This,col1,col2,col3)	\
    (This)->lpVtbl -> SetDefaultImageColor(This,col1,col2,col3)

#define IGXTransFact4_SetFileMatchOptions(This,Opt)	\
    (This)->lpVtbl -> SetFileMatchOptions(This,Opt)

#define IGXTransFact4_GetFileMatchOptions(This,Opt)	\
    (This)->lpVtbl -> GetFileMatchOptions(This,Opt)

#define IGXTransFact4_ConfigDialogExecute(This,pszFileName,Callback)	\
    (This)->lpVtbl -> ConfigDialogExecute(This,pszFileName,Callback)

#define IGXTransFact4_LoadConfigFromStream(This,stream)	\
    (This)->lpVtbl -> LoadConfigFromStream(This,stream)

#define IGXTransFact4_SaveConfigToStream(This,stream)	\
    (This)->lpVtbl -> SaveConfigToStream(This,stream)

#define IGXTransFact4_SaveConfigToBuffer(This,Opt)	\
    (This)->lpVtbl -> SaveConfigToBuffer(This,Opt)

#define IGXTransFact4_LoadConfigFromBuffer(This,Opt)	\
    (This)->lpVtbl -> LoadConfigFromBuffer(This,Opt)

#define IGXTransFact4_SetDefaultCompressionLevel(This,compressLevel)	\
    (This)->lpVtbl -> SetDefaultCompressionLevel(This,compressLevel)

#define IGXTransFact4_GetDefaultCompressionLevel(This,compressLevel)	\
    (This)->lpVtbl -> GetDefaultCompressionLevel(This,compressLevel)

#define IGXTransFact4_GetDefaultFrameRate(This,Scale,Rate)	\
    (This)->lpVtbl -> GetDefaultFrameRate(This,Scale,Rate)

#define IGXTransFact4_SetDefaultFrameRate(This,Scale,Rate)	\
    (This)->lpVtbl -> SetDefaultFrameRate(This,Scale,Rate)

#define IGXTransFact4_SetDefaultLoadScale(This,dwNumerator,dwDenominator)	\
    (This)->lpVtbl -> SetDefaultLoadScale(This,dwNumerator,dwDenominator)

#define IGXTransFact4_GetDefaultLoadScale(This,dwNumerator,dwDenominator)	\
    (This)->lpVtbl -> GetDefaultLoadScale(This,dwNumerator,dwDenominator)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE IGXTransFact4_GetFileType_Proxy( 
    IGXTransFact4 __RPC_FAR * This,
    /* [in][string] */ LPTSTR pszFileName,
    /* [in] */ DWORD fileTypeSize,
    /* [out] */ LPTSTR szFileTypeName,
    /* [out] */ IGXTranslator4 __RPC_FAR *__RPC_FAR *ppXlator4,
    /* [in] */ TranslatorType Type);


void __RPC_STUB IGXTransFact4_GetFileType_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IGXTransFact4_GetFileXlator_Proxy( 
    IGXTransFact4 __RPC_FAR * This,
    /* [in] */ DWORD dwID,
    /* [out] */ IGXTranslator4 __RPC_FAR *__RPC_FAR *ppXlator4);


void __RPC_STUB IGXTransFact4_GetFileXlator_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IGXTransFact4_LoadFile_Proxy( 
    IGXTransFact4 __RPC_FAR * This,
    /* [in][string] */ LPTSTR pszFileName,
    /* [in] */ EPlayFrameType format,
    /* [out] */ IGXIntBitmap2 __RPC_FAR *__RPC_FAR *pIBmp,
    /* [in] */ IGXProgressAdviseSink __RPC_FAR *progress,
    /* [out] */ IGXTranslator4 __RPC_FAR *__RPC_FAR *pITrans4,
    /* [in] */ TranslatorType Type);


void __RPC_STUB IGXTransFact4_LoadFile_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IGXTransFact4_LoadFileToBuffer_Proxy( 
    IGXTransFact4 __RPC_FAR * This,
    /* [in][string] */ LPTSTR pszFileName,
    /* [in] */ EPlayFrameType format,
    /* [out] */ IGXIntBitmap2 __RPC_FAR *__RPC_FAR *ppIBmp,
    /* [in] */ IGXProgressAdviseSink __RPC_FAR *progress,
    /* [out] */ IGXTranslator4 __RPC_FAR *__RPC_FAR *pITrans4,
    /* [in] */ BITMAPINFOHEADER __RPC_FAR *imageHeader,
    /* [in][string] */ unsigned char __RPC_FAR *buffer,
    /* [in] */ DWORD __RPC_FAR *size,
    /* [in] */ TranslatorType Type);


void __RPC_STUB IGXTransFact4_LoadFileToBuffer_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IGXTransFact4_SetAlphaColor_Proxy( 
    IGXTransFact4 __RPC_FAR * This,
    /* [in] */ WORD col1,
    /* [in] */ WORD col2,
    /* [in] */ WORD col3);


void __RPC_STUB IGXTransFact4_SetAlphaColor_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IGXTransFact4_SetDefaultImageColor_Proxy( 
    IGXTransFact4 __RPC_FAR * This,
    /* [in] */ WORD col1,
    /* [in] */ WORD col2,
    /* [in] */ WORD col3);


void __RPC_STUB IGXTransFact4_SetDefaultImageColor_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IGXTransFact4_SetFileMatchOptions_Proxy( 
    IGXTransFact4 __RPC_FAR * This,
    /* [in] */ FileNameMatchOptions __RPC_FAR *Opt);


void __RPC_STUB IGXTransFact4_SetFileMatchOptions_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IGXTransFact4_GetFileMatchOptions_Proxy( 
    IGXTransFact4 __RPC_FAR * This,
    /* [in] */ FileNameMatchOptions __RPC_FAR *Opt);


void __RPC_STUB IGXTransFact4_GetFileMatchOptions_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IGXTransFact4_ConfigDialogExecute_Proxy( 
    IGXTransFact4 __RPC_FAR * This,
    /* [in][string] */ LPTSTR pszFileName,
    /* [in] */ IGXOptionsCallback __RPC_FAR *Callback);


void __RPC_STUB IGXTransFact4_ConfigDialogExecute_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IGXTransFact4_LoadConfigFromStream_Proxy( 
    IGXTransFact4 __RPC_FAR * This,
    /* [in] */ IStream __RPC_FAR *stream);


void __RPC_STUB IGXTransFact4_LoadConfigFromStream_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IGXTransFact4_SaveConfigToStream_Proxy( 
    IGXTransFact4 __RPC_FAR * This,
    /* [in] */ IStream __RPC_FAR *stream);


void __RPC_STUB IGXTransFact4_SaveConfigToStream_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IGXTransFact4_SaveConfigToBuffer_Proxy( 
    IGXTransFact4 __RPC_FAR * This,
    /* [in] */ PlayXlatorOpt __RPC_FAR *Opt);


void __RPC_STUB IGXTransFact4_SaveConfigToBuffer_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IGXTransFact4_LoadConfigFromBuffer_Proxy( 
    IGXTransFact4 __RPC_FAR * This,
    /* [in] */ PlayXlatorOpt __RPC_FAR *Opt);


void __RPC_STUB IGXTransFact4_LoadConfigFromBuffer_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IGXTransFact4_SetDefaultCompressionLevel_Proxy( 
    IGXTransFact4 __RPC_FAR * This,
    /* [in] */ WORD compressLevel);


void __RPC_STUB IGXTransFact4_SetDefaultCompressionLevel_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IGXTransFact4_GetDefaultCompressionLevel_Proxy( 
    IGXTransFact4 __RPC_FAR * This,
    /* [out] */ WORD __RPC_FAR *compressLevel);


void __RPC_STUB IGXTransFact4_GetDefaultCompressionLevel_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IGXTransFact4_GetDefaultFrameRate_Proxy( 
    IGXTransFact4 __RPC_FAR * This,
    /* [out] */ DWORD __RPC_FAR *Scale,
    /* [out] */ DWORD __RPC_FAR *Rate);


void __RPC_STUB IGXTransFact4_GetDefaultFrameRate_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IGXTransFact4_SetDefaultFrameRate_Proxy( 
    IGXTransFact4 __RPC_FAR * This,
    /* [in] */ DWORD Scale,
    /* [in] */ DWORD Rate);


void __RPC_STUB IGXTransFact4_SetDefaultFrameRate_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IGXTransFact4_SetDefaultLoadScale_Proxy( 
    IGXTransFact4 __RPC_FAR * This,
    /* [in] */ DWORD dwNumerator,
    /* [in] */ DWORD dwDenominator);


void __RPC_STUB IGXTransFact4_SetDefaultLoadScale_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IGXTransFact4_GetDefaultLoadScale_Proxy( 
    IGXTransFact4 __RPC_FAR * This,
    /* [out] */ DWORD __RPC_FAR *dwNumerator,
    /* [out] */ DWORD __RPC_FAR *dwDenominator);


void __RPC_STUB IGXTransFact4_GetDefaultLoadScale_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IGXTransFact4_INTERFACE_DEFINED__ */


#ifndef __IGXProgressAdviseSink_INTERFACE_DEFINED__
#define __IGXProgressAdviseSink_INTERFACE_DEFINED__

/****************************************
 * Generated header for interface: IGXProgressAdviseSink
 * at Tue Nov 23 05:02:08 1999
 * using MIDL 3.01.75
 ****************************************/
/* [local][uuid][object] */ 


typedef struct  tagSTrnProgress
    {
    DWORD currentRow;
    DWORD maxRow;
    DWORD currentPass;
    DWORD maxPass;
    }	STrnProgress;


EXTERN_C const IID IID_IGXProgressAdviseSink;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    interface DECLSPEC_UUID("8335e5f3-ab3b-11ce-8468-0000b468276b")
    IGXProgressAdviseSink : public IUnknown
    {
    public:
        virtual void STDMETHODCALLTYPE StartOperation( void) = 0;
        
        virtual void STDMETHODCALLTYPE EndOperation( void) = 0;
        
        virtual void STDMETHODCALLTYPE SetMaxPasses( 
            DWORD maxPass) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE ProgressNotify( 
            /* [in] */ STrnProgress __RPC_FAR *progress) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IGXProgressAdviseSinkVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            IGXProgressAdviseSink __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            IGXProgressAdviseSink __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            IGXProgressAdviseSink __RPC_FAR * This);
        
        void ( STDMETHODCALLTYPE __RPC_FAR *StartOperation )( 
            IGXProgressAdviseSink __RPC_FAR * This);
        
        void ( STDMETHODCALLTYPE __RPC_FAR *EndOperation )( 
            IGXProgressAdviseSink __RPC_FAR * This);
        
        void ( STDMETHODCALLTYPE __RPC_FAR *SetMaxPasses )( 
            IGXProgressAdviseSink __RPC_FAR * This,
            DWORD maxPass);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *ProgressNotify )( 
            IGXProgressAdviseSink __RPC_FAR * This,
            /* [in] */ STrnProgress __RPC_FAR *progress);
        
        END_INTERFACE
    } IGXProgressAdviseSinkVtbl;

    interface IGXProgressAdviseSink
    {
        CONST_VTBL struct IGXProgressAdviseSinkVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IGXProgressAdviseSink_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IGXProgressAdviseSink_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IGXProgressAdviseSink_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IGXProgressAdviseSink_StartOperation(This)	\
    (This)->lpVtbl -> StartOperation(This)

#define IGXProgressAdviseSink_EndOperation(This)	\
    (This)->lpVtbl -> EndOperation(This)

#define IGXProgressAdviseSink_SetMaxPasses(This,maxPass)	\
    (This)->lpVtbl -> SetMaxPasses(This,maxPass)

#define IGXProgressAdviseSink_ProgressNotify(This,progress)	\
    (This)->lpVtbl -> ProgressNotify(This,progress)

#endif /* COBJMACROS */


#endif 	/* C style interface */



void STDMETHODCALLTYPE IGXProgressAdviseSink_StartOperation_Proxy( 
    IGXProgressAdviseSink __RPC_FAR * This);


void __RPC_STUB IGXProgressAdviseSink_StartOperation_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


void STDMETHODCALLTYPE IGXProgressAdviseSink_EndOperation_Proxy( 
    IGXProgressAdviseSink __RPC_FAR * This);


void __RPC_STUB IGXProgressAdviseSink_EndOperation_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


void STDMETHODCALLTYPE IGXProgressAdviseSink_SetMaxPasses_Proxy( 
    IGXProgressAdviseSink __RPC_FAR * This,
    DWORD maxPass);


void __RPC_STUB IGXProgressAdviseSink_SetMaxPasses_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IGXProgressAdviseSink_ProgressNotify_Proxy( 
    IGXProgressAdviseSink __RPC_FAR * This,
    /* [in] */ STrnProgress __RPC_FAR *progress);


void __RPC_STUB IGXProgressAdviseSink_ProgressNotify_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IGXProgressAdviseSink_INTERFACE_DEFINED__ */


#ifndef __IGXClientIO_INTERFACE_DEFINED__
#define __IGXClientIO_INTERFACE_DEFINED__

/****************************************
 * Generated header for interface: IGXClientIO
 * at Tue Nov 23 05:02:08 1999
 * using MIDL 3.01.75
 ****************************************/
/* [local][uuid][object] */ 


typedef 
enum tagSeekOrig
    {	PlaySEEK_START	= 0,
	PlaySEEK_END	= PlaySEEK_START + 1,
	PlaySEEK_CURRENT	= PlaySEEK_END + 1
    }	SeekOrig;

typedef 
enum tagEEndianess
    {	UNKNOWN	= 0,
	INTEL	= UNKNOWN + 1,
	MOTOROLA	= INTEL + 1
    }	EEndianess;


EXTERN_C const IID IID_IGXClientIO;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    interface DECLSPEC_UUID("8335e5f4-ab3b-11ce-8468-0000b468276b")
    IGXClientIO : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE FileOpen( 
            /* [in] */ unsigned char __RPC_FAR *pszFileName,
            /* [in] */ DWORD mode) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE FileClose( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE IsValid( void) = 0;
        
        virtual void STDMETHODCALLTYPE GetMediaEndianess( 
            /* [out] */ EEndianess __RPC_FAR *end) = 0;
        
        virtual void STDMETHODCALLTYPE SetMediaEndianess( 
            /* [in] */ EEndianess end) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Seek( 
            /* [in] */ LONG distance,
            /* [in] */ SeekOrig dir) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE ReadByte( 
            /* [out] */ BYTE __RPC_FAR *b) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE ReadWord( 
            /* [out] */ WORD __RPC_FAR *w) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE ReadDWord( 
            /* [out] */ DWORD __RPC_FAR *dw) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE ReadBuffer( 
            /* [out] */ BYTE __RPC_FAR *buf,
            /* [in] */ DWORD __RPC_FAR *count) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE WriteByte( 
            /* [in] */ BYTE b) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE WriteWord( 
            /* [in] */ WORD w) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE WriteDWord( 
            /* [in] */ DWORD dw) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE WriteBuffer( 
            /* [in] */ BYTE __RPC_FAR *buf,
            /* [in] */ DWORD __RPC_FAR *count) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE QuerySize( 
            /* [out] */ DWORD __RPC_FAR *Size) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE QueryOffset( 
            /* [out] */ DWORD __RPC_FAR *Offset) = 0;
        
        virtual void STDMETHODCALLTYPE FlushIO( void) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IGXClientIOVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            IGXClientIO __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            IGXClientIO __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            IGXClientIO __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *FileOpen )( 
            IGXClientIO __RPC_FAR * This,
            /* [in] */ unsigned char __RPC_FAR *pszFileName,
            /* [in] */ DWORD mode);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *FileClose )( 
            IGXClientIO __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *IsValid )( 
            IGXClientIO __RPC_FAR * This);
        
        void ( STDMETHODCALLTYPE __RPC_FAR *GetMediaEndianess )( 
            IGXClientIO __RPC_FAR * This,
            /* [out] */ EEndianess __RPC_FAR *end);
        
        void ( STDMETHODCALLTYPE __RPC_FAR *SetMediaEndianess )( 
            IGXClientIO __RPC_FAR * This,
            /* [in] */ EEndianess end);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Seek )( 
            IGXClientIO __RPC_FAR * This,
            /* [in] */ LONG distance,
            /* [in] */ SeekOrig dir);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *ReadByte )( 
            IGXClientIO __RPC_FAR * This,
            /* [out] */ BYTE __RPC_FAR *b);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *ReadWord )( 
            IGXClientIO __RPC_FAR * This,
            /* [out] */ WORD __RPC_FAR *w);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *ReadDWord )( 
            IGXClientIO __RPC_FAR * This,
            /* [out] */ DWORD __RPC_FAR *dw);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *ReadBuffer )( 
            IGXClientIO __RPC_FAR * This,
            /* [out] */ BYTE __RPC_FAR *buf,
            /* [in] */ DWORD __RPC_FAR *count);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *WriteByte )( 
            IGXClientIO __RPC_FAR * This,
            /* [in] */ BYTE b);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *WriteWord )( 
            IGXClientIO __RPC_FAR * This,
            /* [in] */ WORD w);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *WriteDWord )( 
            IGXClientIO __RPC_FAR * This,
            /* [in] */ DWORD dw);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *WriteBuffer )( 
            IGXClientIO __RPC_FAR * This,
            /* [in] */ BYTE __RPC_FAR *buf,
            /* [in] */ DWORD __RPC_FAR *count);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QuerySize )( 
            IGXClientIO __RPC_FAR * This,
            /* [out] */ DWORD __RPC_FAR *Size);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryOffset )( 
            IGXClientIO __RPC_FAR * This,
            /* [out] */ DWORD __RPC_FAR *Offset);
        
        void ( STDMETHODCALLTYPE __RPC_FAR *FlushIO )( 
            IGXClientIO __RPC_FAR * This);
        
        END_INTERFACE
    } IGXClientIOVtbl;

    interface IGXClientIO
    {
        CONST_VTBL struct IGXClientIOVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IGXClientIO_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IGXClientIO_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IGXClientIO_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IGXClientIO_FileOpen(This,pszFileName,mode)	\
    (This)->lpVtbl -> FileOpen(This,pszFileName,mode)

#define IGXClientIO_FileClose(This)	\
    (This)->lpVtbl -> FileClose(This)

#define IGXClientIO_IsValid(This)	\
    (This)->lpVtbl -> IsValid(This)

#define IGXClientIO_GetMediaEndianess(This,end)	\
    (This)->lpVtbl -> GetMediaEndianess(This,end)

#define IGXClientIO_SetMediaEndianess(This,end)	\
    (This)->lpVtbl -> SetMediaEndianess(This,end)

#define IGXClientIO_Seek(This,distance,dir)	\
    (This)->lpVtbl -> Seek(This,distance,dir)

#define IGXClientIO_ReadByte(This,b)	\
    (This)->lpVtbl -> ReadByte(This,b)

#define IGXClientIO_ReadWord(This,w)	\
    (This)->lpVtbl -> ReadWord(This,w)

#define IGXClientIO_ReadDWord(This,dw)	\
    (This)->lpVtbl -> ReadDWord(This,dw)

#define IGXClientIO_ReadBuffer(This,buf,count)	\
    (This)->lpVtbl -> ReadBuffer(This,buf,count)

#define IGXClientIO_WriteByte(This,b)	\
    (This)->lpVtbl -> WriteByte(This,b)

#define IGXClientIO_WriteWord(This,w)	\
    (This)->lpVtbl -> WriteWord(This,w)

#define IGXClientIO_WriteDWord(This,dw)	\
    (This)->lpVtbl -> WriteDWord(This,dw)

#define IGXClientIO_WriteBuffer(This,buf,count)	\
    (This)->lpVtbl -> WriteBuffer(This,buf,count)

#define IGXClientIO_QuerySize(This,Size)	\
    (This)->lpVtbl -> QuerySize(This,Size)

#define IGXClientIO_QueryOffset(This,Offset)	\
    (This)->lpVtbl -> QueryOffset(This,Offset)

#define IGXClientIO_FlushIO(This)	\
    (This)->lpVtbl -> FlushIO(This)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE IGXClientIO_FileOpen_Proxy( 
    IGXClientIO __RPC_FAR * This,
    /* [in] */ unsigned char __RPC_FAR *pszFileName,
    /* [in] */ DWORD mode);


void __RPC_STUB IGXClientIO_FileOpen_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IGXClientIO_FileClose_Proxy( 
    IGXClientIO __RPC_FAR * This);


void __RPC_STUB IGXClientIO_FileClose_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IGXClientIO_IsValid_Proxy( 
    IGXClientIO __RPC_FAR * This);


void __RPC_STUB IGXClientIO_IsValid_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


void STDMETHODCALLTYPE IGXClientIO_GetMediaEndianess_Proxy( 
    IGXClientIO __RPC_FAR * This,
    /* [out] */ EEndianess __RPC_FAR *end);


void __RPC_STUB IGXClientIO_GetMediaEndianess_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


void STDMETHODCALLTYPE IGXClientIO_SetMediaEndianess_Proxy( 
    IGXClientIO __RPC_FAR * This,
    /* [in] */ EEndianess end);


void __RPC_STUB IGXClientIO_SetMediaEndianess_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IGXClientIO_Seek_Proxy( 
    IGXClientIO __RPC_FAR * This,
    /* [in] */ LONG distance,
    /* [in] */ SeekOrig dir);


void __RPC_STUB IGXClientIO_Seek_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IGXClientIO_ReadByte_Proxy( 
    IGXClientIO __RPC_FAR * This,
    /* [out] */ BYTE __RPC_FAR *b);


void __RPC_STUB IGXClientIO_ReadByte_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IGXClientIO_ReadWord_Proxy( 
    IGXClientIO __RPC_FAR * This,
    /* [out] */ WORD __RPC_FAR *w);


void __RPC_STUB IGXClientIO_ReadWord_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IGXClientIO_ReadDWord_Proxy( 
    IGXClientIO __RPC_FAR * This,
    /* [out] */ DWORD __RPC_FAR *dw);


void __RPC_STUB IGXClientIO_ReadDWord_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IGXClientIO_ReadBuffer_Proxy( 
    IGXClientIO __RPC_FAR * This,
    /* [out] */ BYTE __RPC_FAR *buf,
    /* [in] */ DWORD __RPC_FAR *count);


void __RPC_STUB IGXClientIO_ReadBuffer_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IGXClientIO_WriteByte_Proxy( 
    IGXClientIO __RPC_FAR * This,
    /* [in] */ BYTE b);


void __RPC_STUB IGXClientIO_WriteByte_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IGXClientIO_WriteWord_Proxy( 
    IGXClientIO __RPC_FAR * This,
    /* [in] */ WORD w);


void __RPC_STUB IGXClientIO_WriteWord_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IGXClientIO_WriteDWord_Proxy( 
    IGXClientIO __RPC_FAR * This,
    /* [in] */ DWORD dw);


void __RPC_STUB IGXClientIO_WriteDWord_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IGXClientIO_WriteBuffer_Proxy( 
    IGXClientIO __RPC_FAR * This,
    /* [in] */ BYTE __RPC_FAR *buf,
    /* [in] */ DWORD __RPC_FAR *count);


void __RPC_STUB IGXClientIO_WriteBuffer_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IGXClientIO_QuerySize_Proxy( 
    IGXClientIO __RPC_FAR * This,
    /* [out] */ DWORD __RPC_FAR *Size);


void __RPC_STUB IGXClientIO_QuerySize_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IGXClientIO_QueryOffset_Proxy( 
    IGXClientIO __RPC_FAR * This,
    /* [out] */ DWORD __RPC_FAR *Offset);


void __RPC_STUB IGXClientIO_QueryOffset_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


void STDMETHODCALLTYPE IGXClientIO_FlushIO_Proxy( 
    IGXClientIO __RPC_FAR * This);


void __RPC_STUB IGXClientIO_FlushIO_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IGXClientIO_INTERFACE_DEFINED__ */


#ifndef __IGXStreamIO_INTERFACE_DEFINED__
#define __IGXStreamIO_INTERFACE_DEFINED__

/****************************************
 * Generated header for interface: IGXStreamIO
 * at Tue Nov 23 05:02:08 1999
 * using MIDL 3.01.75
 ****************************************/
/* [local][uuid][object] */ 



EXTERN_C const IID IID_IGXStreamIO;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    interface DECLSPEC_UUID("d38c4cc0-01c0-11d0-98b2-002018311f37")
    IGXStreamIO : public IGXClientIO
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE SetStorage( 
            IStorage __RPC_FAR *pStorage) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IGXStreamIOVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            IGXStreamIO __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            IGXStreamIO __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            IGXStreamIO __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *FileOpen )( 
            IGXStreamIO __RPC_FAR * This,
            /* [in] */ unsigned char __RPC_FAR *pszFileName,
            /* [in] */ DWORD mode);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *FileClose )( 
            IGXStreamIO __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *IsValid )( 
            IGXStreamIO __RPC_FAR * This);
        
        void ( STDMETHODCALLTYPE __RPC_FAR *GetMediaEndianess )( 
            IGXStreamIO __RPC_FAR * This,
            /* [out] */ EEndianess __RPC_FAR *end);
        
        void ( STDMETHODCALLTYPE __RPC_FAR *SetMediaEndianess )( 
            IGXStreamIO __RPC_FAR * This,
            /* [in] */ EEndianess end);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Seek )( 
            IGXStreamIO __RPC_FAR * This,
            /* [in] */ LONG distance,
            /* [in] */ SeekOrig dir);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *ReadByte )( 
            IGXStreamIO __RPC_FAR * This,
            /* [out] */ BYTE __RPC_FAR *b);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *ReadWord )( 
            IGXStreamIO __RPC_FAR * This,
            /* [out] */ WORD __RPC_FAR *w);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *ReadDWord )( 
            IGXStreamIO __RPC_FAR * This,
            /* [out] */ DWORD __RPC_FAR *dw);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *ReadBuffer )( 
            IGXStreamIO __RPC_FAR * This,
            /* [out] */ BYTE __RPC_FAR *buf,
            /* [in] */ DWORD __RPC_FAR *count);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *WriteByte )( 
            IGXStreamIO __RPC_FAR * This,
            /* [in] */ BYTE b);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *WriteWord )( 
            IGXStreamIO __RPC_FAR * This,
            /* [in] */ WORD w);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *WriteDWord )( 
            IGXStreamIO __RPC_FAR * This,
            /* [in] */ DWORD dw);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *WriteBuffer )( 
            IGXStreamIO __RPC_FAR * This,
            /* [in] */ BYTE __RPC_FAR *buf,
            /* [in] */ DWORD __RPC_FAR *count);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QuerySize )( 
            IGXStreamIO __RPC_FAR * This,
            /* [out] */ DWORD __RPC_FAR *Size);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryOffset )( 
            IGXStreamIO __RPC_FAR * This,
            /* [out] */ DWORD __RPC_FAR *Offset);
        
        void ( STDMETHODCALLTYPE __RPC_FAR *FlushIO )( 
            IGXStreamIO __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetStorage )( 
            IGXStreamIO __RPC_FAR * This,
            IStorage __RPC_FAR *pStorage);
        
        END_INTERFACE
    } IGXStreamIOVtbl;

    interface IGXStreamIO
    {
        CONST_VTBL struct IGXStreamIOVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IGXStreamIO_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IGXStreamIO_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IGXStreamIO_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IGXStreamIO_FileOpen(This,pszFileName,mode)	\
    (This)->lpVtbl -> FileOpen(This,pszFileName,mode)

#define IGXStreamIO_FileClose(This)	\
    (This)->lpVtbl -> FileClose(This)

#define IGXStreamIO_IsValid(This)	\
    (This)->lpVtbl -> IsValid(This)

#define IGXStreamIO_GetMediaEndianess(This,end)	\
    (This)->lpVtbl -> GetMediaEndianess(This,end)

#define IGXStreamIO_SetMediaEndianess(This,end)	\
    (This)->lpVtbl -> SetMediaEndianess(This,end)

#define IGXStreamIO_Seek(This,distance,dir)	\
    (This)->lpVtbl -> Seek(This,distance,dir)

#define IGXStreamIO_ReadByte(This,b)	\
    (This)->lpVtbl -> ReadByte(This,b)

#define IGXStreamIO_ReadWord(This,w)	\
    (This)->lpVtbl -> ReadWord(This,w)

#define IGXStreamIO_ReadDWord(This,dw)	\
    (This)->lpVtbl -> ReadDWord(This,dw)

#define IGXStreamIO_ReadBuffer(This,buf,count)	\
    (This)->lpVtbl -> ReadBuffer(This,buf,count)

#define IGXStreamIO_WriteByte(This,b)	\
    (This)->lpVtbl -> WriteByte(This,b)

#define IGXStreamIO_WriteWord(This,w)	\
    (This)->lpVtbl -> WriteWord(This,w)

#define IGXStreamIO_WriteDWord(This,dw)	\
    (This)->lpVtbl -> WriteDWord(This,dw)

#define IGXStreamIO_WriteBuffer(This,buf,count)	\
    (This)->lpVtbl -> WriteBuffer(This,buf,count)

#define IGXStreamIO_QuerySize(This,Size)	\
    (This)->lpVtbl -> QuerySize(This,Size)

#define IGXStreamIO_QueryOffset(This,Offset)	\
    (This)->lpVtbl -> QueryOffset(This,Offset)

#define IGXStreamIO_FlushIO(This)	\
    (This)->lpVtbl -> FlushIO(This)


#define IGXStreamIO_SetStorage(This,pStorage)	\
    (This)->lpVtbl -> SetStorage(This,pStorage)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE IGXStreamIO_SetStorage_Proxy( 
    IGXStreamIO __RPC_FAR * This,
    IStorage __RPC_FAR *pStorage);


void __RPC_STUB IGXStreamIO_SetStorage_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IGXStreamIO_INTERFACE_DEFINED__ */


#ifndef __IGXMemClientIO_INTERFACE_DEFINED__
#define __IGXMemClientIO_INTERFACE_DEFINED__

/****************************************
 * Generated header for interface: IGXMemClientIO
 * at Tue Nov 23 05:02:08 1999
 * using MIDL 3.01.75
 ****************************************/
/* [local][uuid][object] */ 



EXTERN_C const IID IID_IGXMemClientIO;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    interface DECLSPEC_UUID("8335e6c1-ab3b-11ce-8468-0000b468276b")
    IGXMemClientIO : public IGXClientIO
    {
    public:
        virtual void STDMETHODCALLTYPE SuggestSize( 
            /* [in] */ DWORD length) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetBuffer( 
            /* [out] */ BYTE __RPC_FAR *__RPC_FAR *buf,
            /* [out] */ DWORD __RPC_FAR *length) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE UseBuffer( 
            /* [in] */ BYTE __RPC_FAR *buf,
            /* [in] */ DWORD length,
            /* [in] */ DWORD used) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IGXMemClientIOVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            IGXMemClientIO __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            IGXMemClientIO __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            IGXMemClientIO __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *FileOpen )( 
            IGXMemClientIO __RPC_FAR * This,
            /* [in] */ unsigned char __RPC_FAR *pszFileName,
            /* [in] */ DWORD mode);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *FileClose )( 
            IGXMemClientIO __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *IsValid )( 
            IGXMemClientIO __RPC_FAR * This);
        
        void ( STDMETHODCALLTYPE __RPC_FAR *GetMediaEndianess )( 
            IGXMemClientIO __RPC_FAR * This,
            /* [out] */ EEndianess __RPC_FAR *end);
        
        void ( STDMETHODCALLTYPE __RPC_FAR *SetMediaEndianess )( 
            IGXMemClientIO __RPC_FAR * This,
            /* [in] */ EEndianess end);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Seek )( 
            IGXMemClientIO __RPC_FAR * This,
            /* [in] */ LONG distance,
            /* [in] */ SeekOrig dir);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *ReadByte )( 
            IGXMemClientIO __RPC_FAR * This,
            /* [out] */ BYTE __RPC_FAR *b);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *ReadWord )( 
            IGXMemClientIO __RPC_FAR * This,
            /* [out] */ WORD __RPC_FAR *w);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *ReadDWord )( 
            IGXMemClientIO __RPC_FAR * This,
            /* [out] */ DWORD __RPC_FAR *dw);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *ReadBuffer )( 
            IGXMemClientIO __RPC_FAR * This,
            /* [out] */ BYTE __RPC_FAR *buf,
            /* [in] */ DWORD __RPC_FAR *count);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *WriteByte )( 
            IGXMemClientIO __RPC_FAR * This,
            /* [in] */ BYTE b);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *WriteWord )( 
            IGXMemClientIO __RPC_FAR * This,
            /* [in] */ WORD w);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *WriteDWord )( 
            IGXMemClientIO __RPC_FAR * This,
            /* [in] */ DWORD dw);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *WriteBuffer )( 
            IGXMemClientIO __RPC_FAR * This,
            /* [in] */ BYTE __RPC_FAR *buf,
            /* [in] */ DWORD __RPC_FAR *count);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QuerySize )( 
            IGXMemClientIO __RPC_FAR * This,
            /* [out] */ DWORD __RPC_FAR *Size);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryOffset )( 
            IGXMemClientIO __RPC_FAR * This,
            /* [out] */ DWORD __RPC_FAR *Offset);
        
        void ( STDMETHODCALLTYPE __RPC_FAR *FlushIO )( 
            IGXMemClientIO __RPC_FAR * This);
        
        void ( STDMETHODCALLTYPE __RPC_FAR *SuggestSize )( 
            IGXMemClientIO __RPC_FAR * This,
            /* [in] */ DWORD length);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetBuffer )( 
            IGXMemClientIO __RPC_FAR * This,
            /* [out] */ BYTE __RPC_FAR *__RPC_FAR *buf,
            /* [out] */ DWORD __RPC_FAR *length);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *UseBuffer )( 
            IGXMemClientIO __RPC_FAR * This,
            /* [in] */ BYTE __RPC_FAR *buf,
            /* [in] */ DWORD length,
            /* [in] */ DWORD used);
        
        END_INTERFACE
    } IGXMemClientIOVtbl;

    interface IGXMemClientIO
    {
        CONST_VTBL struct IGXMemClientIOVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IGXMemClientIO_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IGXMemClientIO_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IGXMemClientIO_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IGXMemClientIO_FileOpen(This,pszFileName,mode)	\
    (This)->lpVtbl -> FileOpen(This,pszFileName,mode)

#define IGXMemClientIO_FileClose(This)	\
    (This)->lpVtbl -> FileClose(This)

#define IGXMemClientIO_IsValid(This)	\
    (This)->lpVtbl -> IsValid(This)

#define IGXMemClientIO_GetMediaEndianess(This,end)	\
    (This)->lpVtbl -> GetMediaEndianess(This,end)

#define IGXMemClientIO_SetMediaEndianess(This,end)	\
    (This)->lpVtbl -> SetMediaEndianess(This,end)

#define IGXMemClientIO_Seek(This,distance,dir)	\
    (This)->lpVtbl -> Seek(This,distance,dir)

#define IGXMemClientIO_ReadByte(This,b)	\
    (This)->lpVtbl -> ReadByte(This,b)

#define IGXMemClientIO_ReadWord(This,w)	\
    (This)->lpVtbl -> ReadWord(This,w)

#define IGXMemClientIO_ReadDWord(This,dw)	\
    (This)->lpVtbl -> ReadDWord(This,dw)

#define IGXMemClientIO_ReadBuffer(This,buf,count)	\
    (This)->lpVtbl -> ReadBuffer(This,buf,count)

#define IGXMemClientIO_WriteByte(This,b)	\
    (This)->lpVtbl -> WriteByte(This,b)

#define IGXMemClientIO_WriteWord(This,w)	\
    (This)->lpVtbl -> WriteWord(This,w)

#define IGXMemClientIO_WriteDWord(This,dw)	\
    (This)->lpVtbl -> WriteDWord(This,dw)

#define IGXMemClientIO_WriteBuffer(This,buf,count)	\
    (This)->lpVtbl -> WriteBuffer(This,buf,count)

#define IGXMemClientIO_QuerySize(This,Size)	\
    (This)->lpVtbl -> QuerySize(This,Size)

#define IGXMemClientIO_QueryOffset(This,Offset)	\
    (This)->lpVtbl -> QueryOffset(This,Offset)

#define IGXMemClientIO_FlushIO(This)	\
    (This)->lpVtbl -> FlushIO(This)


#define IGXMemClientIO_SuggestSize(This,length)	\
    (This)->lpVtbl -> SuggestSize(This,length)

#define IGXMemClientIO_GetBuffer(This,buf,length)	\
    (This)->lpVtbl -> GetBuffer(This,buf,length)

#define IGXMemClientIO_UseBuffer(This,buf,length,used)	\
    (This)->lpVtbl -> UseBuffer(This,buf,length,used)

#endif /* COBJMACROS */


#endif 	/* C style interface */



void STDMETHODCALLTYPE IGXMemClientIO_SuggestSize_Proxy( 
    IGXMemClientIO __RPC_FAR * This,
    /* [in] */ DWORD length);


void __RPC_STUB IGXMemClientIO_SuggestSize_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IGXMemClientIO_GetBuffer_Proxy( 
    IGXMemClientIO __RPC_FAR * This,
    /* [out] */ BYTE __RPC_FAR *__RPC_FAR *buf,
    /* [out] */ DWORD __RPC_FAR *length);


void __RPC_STUB IGXMemClientIO_GetBuffer_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IGXMemClientIO_UseBuffer_Proxy( 
    IGXMemClientIO __RPC_FAR * This,
    /* [in] */ BYTE __RPC_FAR *buf,
    /* [in] */ DWORD length,
    /* [in] */ DWORD used);


void __RPC_STUB IGXMemClientIO_UseBuffer_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IGXMemClientIO_INTERFACE_DEFINED__ */


#ifndef __IGXTranslator_INTERFACE_DEFINED__
#define __IGXTranslator_INTERFACE_DEFINED__

/****************************************
 * Generated header for interface: IGXTranslator
 * at Tue Nov 23 05:02:08 1999
 * using MIDL 3.01.75
 ****************************************/
/* [local][uuid][object] */ 



EXTERN_C const IID IID_IGXTranslator;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    interface DECLSPEC_UUID("8335e5f5-ab3b-11ce-8468-0000b468276b")
    IGXTranslator : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE ValidateFile( 
            /* [in][string] */ unsigned char __RPC_FAR *pszFileName) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE CanILoad( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE CanISave( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetXlatorName( 
            /* [in] */ DWORD fileTypeSize,
            /* [out] */ unsigned char __RPC_FAR *szFileTypeName) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetXlatorDescription( 
            /* [in] */ DWORD fileDescripSize,
            /* [out] */ unsigned char __RPC_FAR *szFileDescripName) = 0;
        
        virtual void STDMETHODCALLTYPE SetClientIO( 
            /* [in] */ IGXClientIO __RPC_FAR *pClientIO) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE LoadFile( 
            /* [in][string] */ unsigned char __RPC_FAR *pszFileName,
            /* [in] */ EPlayFrameType format,
            /* [out] */ IGXIntBitmap __RPC_FAR *__RPC_FAR *ppIBmp,
            /* [in] */ IGXProgressAdviseSink __RPC_FAR *progress) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SaveFile( 
            /* [in][string] */ unsigned char __RPC_FAR *pszFileName,
            /* [in] */ IGXIntBitmap __RPC_FAR *pIBmp,
            /* [in] */ IGXProgressAdviseSink __RPC_FAR *progress) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IGXTranslatorVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            IGXTranslator __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            IGXTranslator __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            IGXTranslator __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *ValidateFile )( 
            IGXTranslator __RPC_FAR * This,
            /* [in][string] */ unsigned char __RPC_FAR *pszFileName);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *CanILoad )( 
            IGXTranslator __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *CanISave )( 
            IGXTranslator __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetXlatorName )( 
            IGXTranslator __RPC_FAR * This,
            /* [in] */ DWORD fileTypeSize,
            /* [out] */ unsigned char __RPC_FAR *szFileTypeName);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetXlatorDescription )( 
            IGXTranslator __RPC_FAR * This,
            /* [in] */ DWORD fileDescripSize,
            /* [out] */ unsigned char __RPC_FAR *szFileDescripName);
        
        void ( STDMETHODCALLTYPE __RPC_FAR *SetClientIO )( 
            IGXTranslator __RPC_FAR * This,
            /* [in] */ IGXClientIO __RPC_FAR *pClientIO);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *LoadFile )( 
            IGXTranslator __RPC_FAR * This,
            /* [in][string] */ unsigned char __RPC_FAR *pszFileName,
            /* [in] */ EPlayFrameType format,
            /* [out] */ IGXIntBitmap __RPC_FAR *__RPC_FAR *ppIBmp,
            /* [in] */ IGXProgressAdviseSink __RPC_FAR *progress);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SaveFile )( 
            IGXTranslator __RPC_FAR * This,
            /* [in][string] */ unsigned char __RPC_FAR *pszFileName,
            /* [in] */ IGXIntBitmap __RPC_FAR *pIBmp,
            /* [in] */ IGXProgressAdviseSink __RPC_FAR *progress);
        
        END_INTERFACE
    } IGXTranslatorVtbl;

    interface IGXTranslator
    {
        CONST_VTBL struct IGXTranslatorVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IGXTranslator_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IGXTranslator_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IGXTranslator_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IGXTranslator_ValidateFile(This,pszFileName)	\
    (This)->lpVtbl -> ValidateFile(This,pszFileName)

#define IGXTranslator_CanILoad(This)	\
    (This)->lpVtbl -> CanILoad(This)

#define IGXTranslator_CanISave(This)	\
    (This)->lpVtbl -> CanISave(This)

#define IGXTranslator_GetXlatorName(This,fileTypeSize,szFileTypeName)	\
    (This)->lpVtbl -> GetXlatorName(This,fileTypeSize,szFileTypeName)

#define IGXTranslator_GetXlatorDescription(This,fileDescripSize,szFileDescripName)	\
    (This)->lpVtbl -> GetXlatorDescription(This,fileDescripSize,szFileDescripName)

#define IGXTranslator_SetClientIO(This,pClientIO)	\
    (This)->lpVtbl -> SetClientIO(This,pClientIO)

#define IGXTranslator_LoadFile(This,pszFileName,format,ppIBmp,progress)	\
    (This)->lpVtbl -> LoadFile(This,pszFileName,format,ppIBmp,progress)

#define IGXTranslator_SaveFile(This,pszFileName,pIBmp,progress)	\
    (This)->lpVtbl -> SaveFile(This,pszFileName,pIBmp,progress)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE IGXTranslator_ValidateFile_Proxy( 
    IGXTranslator __RPC_FAR * This,
    /* [in][string] */ unsigned char __RPC_FAR *pszFileName);


void __RPC_STUB IGXTranslator_ValidateFile_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IGXTranslator_CanILoad_Proxy( 
    IGXTranslator __RPC_FAR * This);


void __RPC_STUB IGXTranslator_CanILoad_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IGXTranslator_CanISave_Proxy( 
    IGXTranslator __RPC_FAR * This);


void __RPC_STUB IGXTranslator_CanISave_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IGXTranslator_GetXlatorName_Proxy( 
    IGXTranslator __RPC_FAR * This,
    /* [in] */ DWORD fileTypeSize,
    /* [out] */ unsigned char __RPC_FAR *szFileTypeName);


void __RPC_STUB IGXTranslator_GetXlatorName_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IGXTranslator_GetXlatorDescription_Proxy( 
    IGXTranslator __RPC_FAR * This,
    /* [in] */ DWORD fileDescripSize,
    /* [out] */ unsigned char __RPC_FAR *szFileDescripName);


void __RPC_STUB IGXTranslator_GetXlatorDescription_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


void STDMETHODCALLTYPE IGXTranslator_SetClientIO_Proxy( 
    IGXTranslator __RPC_FAR * This,
    /* [in] */ IGXClientIO __RPC_FAR *pClientIO);


void __RPC_STUB IGXTranslator_SetClientIO_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IGXTranslator_LoadFile_Proxy( 
    IGXTranslator __RPC_FAR * This,
    /* [in][string] */ unsigned char __RPC_FAR *pszFileName,
    /* [in] */ EPlayFrameType format,
    /* [out] */ IGXIntBitmap __RPC_FAR *__RPC_FAR *ppIBmp,
    /* [in] */ IGXProgressAdviseSink __RPC_FAR *progress);


void __RPC_STUB IGXTranslator_LoadFile_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IGXTranslator_SaveFile_Proxy( 
    IGXTranslator __RPC_FAR * This,
    /* [in][string] */ unsigned char __RPC_FAR *pszFileName,
    /* [in] */ IGXIntBitmap __RPC_FAR *pIBmp,
    /* [in] */ IGXProgressAdviseSink __RPC_FAR *progress);


void __RPC_STUB IGXTranslator_SaveFile_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IGXTranslator_INTERFACE_DEFINED__ */


#ifndef __IGXTranslator2_INTERFACE_DEFINED__
#define __IGXTranslator2_INTERFACE_DEFINED__

/****************************************
 * Generated header for interface: IGXTranslator2
 * at Tue Nov 23 05:02:08 1999
 * using MIDL 3.01.75
 ****************************************/
/* [local][uuid][object] */ 



EXTERN_C const IID IID_IGXTranslator2;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    interface DECLSPEC_UUID("8335e605-ab3b-11ce-8468-0000b468276b")
    IGXTranslator2 : public IGXTranslator
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE SetFrameNumber( 
            /* [in] */ DWORD frameNumber) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE QueryFrameNumber( 
            /* [out] */ DWORD __RPC_FAR *frameNumber) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE QueryImageHeader( 
            /* [in][string] */ unsigned char __RPC_FAR *pszFileName,
            /* [out] */ BITMAPINFOHEADER __RPC_FAR *pBmi,
            /* [out] */ EPlayFrameType __RPC_FAR *format) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE QueryNumberFrames( 
            /* [string][in] */ unsigned char __RPC_FAR *pszFileName,
            /* [out] */ DWORD __RPC_FAR *numFrames) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE QueryFrameRate( 
            /* [string][in] */ unsigned char __RPC_FAR *pszFileName,
            /* [out] */ DWORD __RPC_FAR *Scale,
            /* [out] */ DWORD __RPC_FAR *Rate) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetFrameRate( 
            /* [in] */ DWORD Scale,
            /* [in] */ DWORD Rate) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE UpdateFrameRate( 
            /* [string][in] */ unsigned char __RPC_FAR *pszFileName,
            /* [in] */ DWORD Scale,
            /* [in] */ DWORD Rate) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetEnumCompressors( 
            /* [out] */ IEnumCompressors __RPC_FAR *__RPC_FAR *ppIenum) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetCompressor( 
            /* [in] */ DWORD CompCode) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetCompressor( 
            /* [out] */ DWORD __RPC_FAR *CompCode) = 0;
        
        virtual REFCLSID STDMETHODCALLTYPE QueryCLSID( void) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IGXTranslator2Vtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            IGXTranslator2 __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            IGXTranslator2 __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            IGXTranslator2 __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *ValidateFile )( 
            IGXTranslator2 __RPC_FAR * This,
            /* [in][string] */ unsigned char __RPC_FAR *pszFileName);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *CanILoad )( 
            IGXTranslator2 __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *CanISave )( 
            IGXTranslator2 __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetXlatorName )( 
            IGXTranslator2 __RPC_FAR * This,
            /* [in] */ DWORD fileTypeSize,
            /* [out] */ unsigned char __RPC_FAR *szFileTypeName);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetXlatorDescription )( 
            IGXTranslator2 __RPC_FAR * This,
            /* [in] */ DWORD fileDescripSize,
            /* [out] */ unsigned char __RPC_FAR *szFileDescripName);
        
        void ( STDMETHODCALLTYPE __RPC_FAR *SetClientIO )( 
            IGXTranslator2 __RPC_FAR * This,
            /* [in] */ IGXClientIO __RPC_FAR *pClientIO);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *LoadFile )( 
            IGXTranslator2 __RPC_FAR * This,
            /* [in][string] */ unsigned char __RPC_FAR *pszFileName,
            /* [in] */ EPlayFrameType format,
            /* [out] */ IGXIntBitmap __RPC_FAR *__RPC_FAR *ppIBmp,
            /* [in] */ IGXProgressAdviseSink __RPC_FAR *progress);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SaveFile )( 
            IGXTranslator2 __RPC_FAR * This,
            /* [in][string] */ unsigned char __RPC_FAR *pszFileName,
            /* [in] */ IGXIntBitmap __RPC_FAR *pIBmp,
            /* [in] */ IGXProgressAdviseSink __RPC_FAR *progress);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetFrameNumber )( 
            IGXTranslator2 __RPC_FAR * This,
            /* [in] */ DWORD frameNumber);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryFrameNumber )( 
            IGXTranslator2 __RPC_FAR * This,
            /* [out] */ DWORD __RPC_FAR *frameNumber);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryImageHeader )( 
            IGXTranslator2 __RPC_FAR * This,
            /* [in][string] */ unsigned char __RPC_FAR *pszFileName,
            /* [out] */ BITMAPINFOHEADER __RPC_FAR *pBmi,
            /* [out] */ EPlayFrameType __RPC_FAR *format);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryNumberFrames )( 
            IGXTranslator2 __RPC_FAR * This,
            /* [string][in] */ unsigned char __RPC_FAR *pszFileName,
            /* [out] */ DWORD __RPC_FAR *numFrames);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryFrameRate )( 
            IGXTranslator2 __RPC_FAR * This,
            /* [string][in] */ unsigned char __RPC_FAR *pszFileName,
            /* [out] */ DWORD __RPC_FAR *Scale,
            /* [out] */ DWORD __RPC_FAR *Rate);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetFrameRate )( 
            IGXTranslator2 __RPC_FAR * This,
            /* [in] */ DWORD Scale,
            /* [in] */ DWORD Rate);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *UpdateFrameRate )( 
            IGXTranslator2 __RPC_FAR * This,
            /* [string][in] */ unsigned char __RPC_FAR *pszFileName,
            /* [in] */ DWORD Scale,
            /* [in] */ DWORD Rate);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetEnumCompressors )( 
            IGXTranslator2 __RPC_FAR * This,
            /* [out] */ IEnumCompressors __RPC_FAR *__RPC_FAR *ppIenum);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetCompressor )( 
            IGXTranslator2 __RPC_FAR * This,
            /* [in] */ DWORD CompCode);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetCompressor )( 
            IGXTranslator2 __RPC_FAR * This,
            /* [out] */ DWORD __RPC_FAR *CompCode);
        
        REFCLSID ( STDMETHODCALLTYPE __RPC_FAR *QueryCLSID )( 
            IGXTranslator2 __RPC_FAR * This);
        
        END_INTERFACE
    } IGXTranslator2Vtbl;

    interface IGXTranslator2
    {
        CONST_VTBL struct IGXTranslator2Vtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IGXTranslator2_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IGXTranslator2_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IGXTranslator2_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IGXTranslator2_ValidateFile(This,pszFileName)	\
    (This)->lpVtbl -> ValidateFile(This,pszFileName)

#define IGXTranslator2_CanILoad(This)	\
    (This)->lpVtbl -> CanILoad(This)

#define IGXTranslator2_CanISave(This)	\
    (This)->lpVtbl -> CanISave(This)

#define IGXTranslator2_GetXlatorName(This,fileTypeSize,szFileTypeName)	\
    (This)->lpVtbl -> GetXlatorName(This,fileTypeSize,szFileTypeName)

#define IGXTranslator2_GetXlatorDescription(This,fileDescripSize,szFileDescripName)	\
    (This)->lpVtbl -> GetXlatorDescription(This,fileDescripSize,szFileDescripName)

#define IGXTranslator2_SetClientIO(This,pClientIO)	\
    (This)->lpVtbl -> SetClientIO(This,pClientIO)

#define IGXTranslator2_LoadFile(This,pszFileName,format,ppIBmp,progress)	\
    (This)->lpVtbl -> LoadFile(This,pszFileName,format,ppIBmp,progress)

#define IGXTranslator2_SaveFile(This,pszFileName,pIBmp,progress)	\
    (This)->lpVtbl -> SaveFile(This,pszFileName,pIBmp,progress)


#define IGXTranslator2_SetFrameNumber(This,frameNumber)	\
    (This)->lpVtbl -> SetFrameNumber(This,frameNumber)

#define IGXTranslator2_QueryFrameNumber(This,frameNumber)	\
    (This)->lpVtbl -> QueryFrameNumber(This,frameNumber)

#define IGXTranslator2_QueryImageHeader(This,pszFileName,pBmi,format)	\
    (This)->lpVtbl -> QueryImageHeader(This,pszFileName,pBmi,format)

#define IGXTranslator2_QueryNumberFrames(This,pszFileName,numFrames)	\
    (This)->lpVtbl -> QueryNumberFrames(This,pszFileName,numFrames)

#define IGXTranslator2_QueryFrameRate(This,pszFileName,Scale,Rate)	\
    (This)->lpVtbl -> QueryFrameRate(This,pszFileName,Scale,Rate)

#define IGXTranslator2_SetFrameRate(This,Scale,Rate)	\
    (This)->lpVtbl -> SetFrameRate(This,Scale,Rate)

#define IGXTranslator2_UpdateFrameRate(This,pszFileName,Scale,Rate)	\
    (This)->lpVtbl -> UpdateFrameRate(This,pszFileName,Scale,Rate)

#define IGXTranslator2_GetEnumCompressors(This,ppIenum)	\
    (This)->lpVtbl -> GetEnumCompressors(This,ppIenum)

#define IGXTranslator2_SetCompressor(This,CompCode)	\
    (This)->lpVtbl -> SetCompressor(This,CompCode)

#define IGXTranslator2_GetCompressor(This,CompCode)	\
    (This)->lpVtbl -> GetCompressor(This,CompCode)

#define IGXTranslator2_QueryCLSID(This)	\
    (This)->lpVtbl -> QueryCLSID(This)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE IGXTranslator2_SetFrameNumber_Proxy( 
    IGXTranslator2 __RPC_FAR * This,
    /* [in] */ DWORD frameNumber);


void __RPC_STUB IGXTranslator2_SetFrameNumber_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IGXTranslator2_QueryFrameNumber_Proxy( 
    IGXTranslator2 __RPC_FAR * This,
    /* [out] */ DWORD __RPC_FAR *frameNumber);


void __RPC_STUB IGXTranslator2_QueryFrameNumber_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IGXTranslator2_QueryImageHeader_Proxy( 
    IGXTranslator2 __RPC_FAR * This,
    /* [in][string] */ unsigned char __RPC_FAR *pszFileName,
    /* [out] */ BITMAPINFOHEADER __RPC_FAR *pBmi,
    /* [out] */ EPlayFrameType __RPC_FAR *format);


void __RPC_STUB IGXTranslator2_QueryImageHeader_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IGXTranslator2_QueryNumberFrames_Proxy( 
    IGXTranslator2 __RPC_FAR * This,
    /* [string][in] */ unsigned char __RPC_FAR *pszFileName,
    /* [out] */ DWORD __RPC_FAR *numFrames);


void __RPC_STUB IGXTranslator2_QueryNumberFrames_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IGXTranslator2_QueryFrameRate_Proxy( 
    IGXTranslator2 __RPC_FAR * This,
    /* [string][in] */ unsigned char __RPC_FAR *pszFileName,
    /* [out] */ DWORD __RPC_FAR *Scale,
    /* [out] */ DWORD __RPC_FAR *Rate);


void __RPC_STUB IGXTranslator2_QueryFrameRate_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IGXTranslator2_SetFrameRate_Proxy( 
    IGXTranslator2 __RPC_FAR * This,
    /* [in] */ DWORD Scale,
    /* [in] */ DWORD Rate);


void __RPC_STUB IGXTranslator2_SetFrameRate_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IGXTranslator2_UpdateFrameRate_Proxy( 
    IGXTranslator2 __RPC_FAR * This,
    /* [string][in] */ unsigned char __RPC_FAR *pszFileName,
    /* [in] */ DWORD Scale,
    /* [in] */ DWORD Rate);


void __RPC_STUB IGXTranslator2_UpdateFrameRate_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IGXTranslator2_GetEnumCompressors_Proxy( 
    IGXTranslator2 __RPC_FAR * This,
    /* [out] */ IEnumCompressors __RPC_FAR *__RPC_FAR *ppIenum);


void __RPC_STUB IGXTranslator2_GetEnumCompressors_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IGXTranslator2_SetCompressor_Proxy( 
    IGXTranslator2 __RPC_FAR * This,
    /* [in] */ DWORD CompCode);


void __RPC_STUB IGXTranslator2_SetCompressor_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IGXTranslator2_GetCompressor_Proxy( 
    IGXTranslator2 __RPC_FAR * This,
    /* [out] */ DWORD __RPC_FAR *CompCode);


void __RPC_STUB IGXTranslator2_GetCompressor_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


REFCLSID STDMETHODCALLTYPE IGXTranslator2_QueryCLSID_Proxy( 
    IGXTranslator2 __RPC_FAR * This);


void __RPC_STUB IGXTranslator2_QueryCLSID_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IGXTranslator2_INTERFACE_DEFINED__ */


#ifndef __IGXTranslator3_INTERFACE_DEFINED__
#define __IGXTranslator3_INTERFACE_DEFINED__

/****************************************
 * Generated header for interface: IGXTranslator3
 * at Tue Nov 23 05:02:08 1999
 * using MIDL 3.01.75
 ****************************************/
/* [local][uuid][object] */ 



EXTERN_C const IID IID_IGXTranslator3;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    interface DECLSPEC_UUID("8335e6b8-ab3b-11ce-8468-0000b468276b")
    IGXTranslator3 : public IGXTranslator2
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE SetLoadScale( 
            /* [in] */ DWORD dwNumerator,
            /* [in] */ DWORD dwDenominator) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE QueryNumberLayers( 
            /* [in][string] */ unsigned char __RPC_FAR *pszFileName,
            /* [out] */ DWORD __RPC_FAR *pdwNumLayers) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE QueryLayer( 
            /* [in][string] */ unsigned char __RPC_FAR *pszFileName,
            /* [in] */ DWORD dwLayerNumber,
            /* [out] */ BITMAPINFOHEADER __RPC_FAR *pBmi,
            /* [out] */ EPlayFrameType __RPC_FAR *format) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE LoadLayer( 
            /* [in][string] */ unsigned char __RPC_FAR *pszFileName,
            /* [in] */ DWORD dwLayerNumber,
            /* [in] */ EPlayFrameType format,
            /* [out] */ IGXIntBitmap __RPC_FAR *__RPC_FAR *ppIBmp,
            /* [in] */ IGXProgressAdviseSink __RPC_FAR *progress) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetLayerAttribute( 
            /* [in] */ ELayerAttribute eAttribute,
            /* [in] */ DWORD dwBufferSize,
            /* [out] */ void __RPC_FAR *pBuffer) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetLayerAttribute( 
            /* [in] */ ELayerAttribute eAttribute,
            /* [in] */ void __RPC_FAR *pBuffer) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE CanISaveLayers( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE BeginLayeredSave( 
            /* [in][string] */ unsigned char __RPC_FAR *pszFileName,
            /* [in] */ DWORD nNumLayers,
            /* [in] */ IGXProgressAdviseSink __RPC_FAR *progress) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SaveLayer( 
            /* [in] */ IGXIntBitmap __RPC_FAR *pIBmp,
            /* [in] */ IGXProgressAdviseSink __RPC_FAR *progress) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE EndLayeredSave( 
            /* [in] */ IGXIntBitmap __RPC_FAR *pIBmp,
            /* [in] */ IGXProgressAdviseSink __RPC_FAR *progress) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetXlatorID( 
            /* [out] */ DWORD __RPC_FAR *pdwID) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IGXTranslator3Vtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            IGXTranslator3 __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            IGXTranslator3 __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            IGXTranslator3 __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *ValidateFile )( 
            IGXTranslator3 __RPC_FAR * This,
            /* [in][string] */ unsigned char __RPC_FAR *pszFileName);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *CanILoad )( 
            IGXTranslator3 __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *CanISave )( 
            IGXTranslator3 __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetXlatorName )( 
            IGXTranslator3 __RPC_FAR * This,
            /* [in] */ DWORD fileTypeSize,
            /* [out] */ unsigned char __RPC_FAR *szFileTypeName);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetXlatorDescription )( 
            IGXTranslator3 __RPC_FAR * This,
            /* [in] */ DWORD fileDescripSize,
            /* [out] */ unsigned char __RPC_FAR *szFileDescripName);
        
        void ( STDMETHODCALLTYPE __RPC_FAR *SetClientIO )( 
            IGXTranslator3 __RPC_FAR * This,
            /* [in] */ IGXClientIO __RPC_FAR *pClientIO);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *LoadFile )( 
            IGXTranslator3 __RPC_FAR * This,
            /* [in][string] */ unsigned char __RPC_FAR *pszFileName,
            /* [in] */ EPlayFrameType format,
            /* [out] */ IGXIntBitmap __RPC_FAR *__RPC_FAR *ppIBmp,
            /* [in] */ IGXProgressAdviseSink __RPC_FAR *progress);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SaveFile )( 
            IGXTranslator3 __RPC_FAR * This,
            /* [in][string] */ unsigned char __RPC_FAR *pszFileName,
            /* [in] */ IGXIntBitmap __RPC_FAR *pIBmp,
            /* [in] */ IGXProgressAdviseSink __RPC_FAR *progress);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetFrameNumber )( 
            IGXTranslator3 __RPC_FAR * This,
            /* [in] */ DWORD frameNumber);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryFrameNumber )( 
            IGXTranslator3 __RPC_FAR * This,
            /* [out] */ DWORD __RPC_FAR *frameNumber);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryImageHeader )( 
            IGXTranslator3 __RPC_FAR * This,
            /* [in][string] */ unsigned char __RPC_FAR *pszFileName,
            /* [out] */ BITMAPINFOHEADER __RPC_FAR *pBmi,
            /* [out] */ EPlayFrameType __RPC_FAR *format);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryNumberFrames )( 
            IGXTranslator3 __RPC_FAR * This,
            /* [string][in] */ unsigned char __RPC_FAR *pszFileName,
            /* [out] */ DWORD __RPC_FAR *numFrames);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryFrameRate )( 
            IGXTranslator3 __RPC_FAR * This,
            /* [string][in] */ unsigned char __RPC_FAR *pszFileName,
            /* [out] */ DWORD __RPC_FAR *Scale,
            /* [out] */ DWORD __RPC_FAR *Rate);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetFrameRate )( 
            IGXTranslator3 __RPC_FAR * This,
            /* [in] */ DWORD Scale,
            /* [in] */ DWORD Rate);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *UpdateFrameRate )( 
            IGXTranslator3 __RPC_FAR * This,
            /* [string][in] */ unsigned char __RPC_FAR *pszFileName,
            /* [in] */ DWORD Scale,
            /* [in] */ DWORD Rate);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetEnumCompressors )( 
            IGXTranslator3 __RPC_FAR * This,
            /* [out] */ IEnumCompressors __RPC_FAR *__RPC_FAR *ppIenum);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetCompressor )( 
            IGXTranslator3 __RPC_FAR * This,
            /* [in] */ DWORD CompCode);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetCompressor )( 
            IGXTranslator3 __RPC_FAR * This,
            /* [out] */ DWORD __RPC_FAR *CompCode);
        
        REFCLSID ( STDMETHODCALLTYPE __RPC_FAR *QueryCLSID )( 
            IGXTranslator3 __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetLoadScale )( 
            IGXTranslator3 __RPC_FAR * This,
            /* [in] */ DWORD dwNumerator,
            /* [in] */ DWORD dwDenominator);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryNumberLayers )( 
            IGXTranslator3 __RPC_FAR * This,
            /* [in][string] */ unsigned char __RPC_FAR *pszFileName,
            /* [out] */ DWORD __RPC_FAR *pdwNumLayers);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryLayer )( 
            IGXTranslator3 __RPC_FAR * This,
            /* [in][string] */ unsigned char __RPC_FAR *pszFileName,
            /* [in] */ DWORD dwLayerNumber,
            /* [out] */ BITMAPINFOHEADER __RPC_FAR *pBmi,
            /* [out] */ EPlayFrameType __RPC_FAR *format);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *LoadLayer )( 
            IGXTranslator3 __RPC_FAR * This,
            /* [in][string] */ unsigned char __RPC_FAR *pszFileName,
            /* [in] */ DWORD dwLayerNumber,
            /* [in] */ EPlayFrameType format,
            /* [out] */ IGXIntBitmap __RPC_FAR *__RPC_FAR *ppIBmp,
            /* [in] */ IGXProgressAdviseSink __RPC_FAR *progress);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetLayerAttribute )( 
            IGXTranslator3 __RPC_FAR * This,
            /* [in] */ ELayerAttribute eAttribute,
            /* [in] */ DWORD dwBufferSize,
            /* [out] */ void __RPC_FAR *pBuffer);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetLayerAttribute )( 
            IGXTranslator3 __RPC_FAR * This,
            /* [in] */ ELayerAttribute eAttribute,
            /* [in] */ void __RPC_FAR *pBuffer);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *CanISaveLayers )( 
            IGXTranslator3 __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *BeginLayeredSave )( 
            IGXTranslator3 __RPC_FAR * This,
            /* [in][string] */ unsigned char __RPC_FAR *pszFileName,
            /* [in] */ DWORD nNumLayers,
            /* [in] */ IGXProgressAdviseSink __RPC_FAR *progress);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SaveLayer )( 
            IGXTranslator3 __RPC_FAR * This,
            /* [in] */ IGXIntBitmap __RPC_FAR *pIBmp,
            /* [in] */ IGXProgressAdviseSink __RPC_FAR *progress);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *EndLayeredSave )( 
            IGXTranslator3 __RPC_FAR * This,
            /* [in] */ IGXIntBitmap __RPC_FAR *pIBmp,
            /* [in] */ IGXProgressAdviseSink __RPC_FAR *progress);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetXlatorID )( 
            IGXTranslator3 __RPC_FAR * This,
            /* [out] */ DWORD __RPC_FAR *pdwID);
        
        END_INTERFACE
    } IGXTranslator3Vtbl;

    interface IGXTranslator3
    {
        CONST_VTBL struct IGXTranslator3Vtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IGXTranslator3_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IGXTranslator3_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IGXTranslator3_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IGXTranslator3_ValidateFile(This,pszFileName)	\
    (This)->lpVtbl -> ValidateFile(This,pszFileName)

#define IGXTranslator3_CanILoad(This)	\
    (This)->lpVtbl -> CanILoad(This)

#define IGXTranslator3_CanISave(This)	\
    (This)->lpVtbl -> CanISave(This)

#define IGXTranslator3_GetXlatorName(This,fileTypeSize,szFileTypeName)	\
    (This)->lpVtbl -> GetXlatorName(This,fileTypeSize,szFileTypeName)

#define IGXTranslator3_GetXlatorDescription(This,fileDescripSize,szFileDescripName)	\
    (This)->lpVtbl -> GetXlatorDescription(This,fileDescripSize,szFileDescripName)

#define IGXTranslator3_SetClientIO(This,pClientIO)	\
    (This)->lpVtbl -> SetClientIO(This,pClientIO)

#define IGXTranslator3_LoadFile(This,pszFileName,format,ppIBmp,progress)	\
    (This)->lpVtbl -> LoadFile(This,pszFileName,format,ppIBmp,progress)

#define IGXTranslator3_SaveFile(This,pszFileName,pIBmp,progress)	\
    (This)->lpVtbl -> SaveFile(This,pszFileName,pIBmp,progress)


#define IGXTranslator3_SetFrameNumber(This,frameNumber)	\
    (This)->lpVtbl -> SetFrameNumber(This,frameNumber)

#define IGXTranslator3_QueryFrameNumber(This,frameNumber)	\
    (This)->lpVtbl -> QueryFrameNumber(This,frameNumber)

#define IGXTranslator3_QueryImageHeader(This,pszFileName,pBmi,format)	\
    (This)->lpVtbl -> QueryImageHeader(This,pszFileName,pBmi,format)

#define IGXTranslator3_QueryNumberFrames(This,pszFileName,numFrames)	\
    (This)->lpVtbl -> QueryNumberFrames(This,pszFileName,numFrames)

#define IGXTranslator3_QueryFrameRate(This,pszFileName,Scale,Rate)	\
    (This)->lpVtbl -> QueryFrameRate(This,pszFileName,Scale,Rate)

#define IGXTranslator3_SetFrameRate(This,Scale,Rate)	\
    (This)->lpVtbl -> SetFrameRate(This,Scale,Rate)

#define IGXTranslator3_UpdateFrameRate(This,pszFileName,Scale,Rate)	\
    (This)->lpVtbl -> UpdateFrameRate(This,pszFileName,Scale,Rate)

#define IGXTranslator3_GetEnumCompressors(This,ppIenum)	\
    (This)->lpVtbl -> GetEnumCompressors(This,ppIenum)

#define IGXTranslator3_SetCompressor(This,CompCode)	\
    (This)->lpVtbl -> SetCompressor(This,CompCode)

#define IGXTranslator3_GetCompressor(This,CompCode)	\
    (This)->lpVtbl -> GetCompressor(This,CompCode)

#define IGXTranslator3_QueryCLSID(This)	\
    (This)->lpVtbl -> QueryCLSID(This)


#define IGXTranslator3_SetLoadScale(This,dwNumerator,dwDenominator)	\
    (This)->lpVtbl -> SetLoadScale(This,dwNumerator,dwDenominator)

#define IGXTranslator3_QueryNumberLayers(This,pszFileName,pdwNumLayers)	\
    (This)->lpVtbl -> QueryNumberLayers(This,pszFileName,pdwNumLayers)

#define IGXTranslator3_QueryLayer(This,pszFileName,dwLayerNumber,pBmi,format)	\
    (This)->lpVtbl -> QueryLayer(This,pszFileName,dwLayerNumber,pBmi,format)

#define IGXTranslator3_LoadLayer(This,pszFileName,dwLayerNumber,format,ppIBmp,progress)	\
    (This)->lpVtbl -> LoadLayer(This,pszFileName,dwLayerNumber,format,ppIBmp,progress)

#define IGXTranslator3_GetLayerAttribute(This,eAttribute,dwBufferSize,pBuffer)	\
    (This)->lpVtbl -> GetLayerAttribute(This,eAttribute,dwBufferSize,pBuffer)

#define IGXTranslator3_SetLayerAttribute(This,eAttribute,pBuffer)	\
    (This)->lpVtbl -> SetLayerAttribute(This,eAttribute,pBuffer)

#define IGXTranslator3_CanISaveLayers(This)	\
    (This)->lpVtbl -> CanISaveLayers(This)

#define IGXTranslator3_BeginLayeredSave(This,pszFileName,nNumLayers,progress)	\
    (This)->lpVtbl -> BeginLayeredSave(This,pszFileName,nNumLayers,progress)

#define IGXTranslator3_SaveLayer(This,pIBmp,progress)	\
    (This)->lpVtbl -> SaveLayer(This,pIBmp,progress)

#define IGXTranslator3_EndLayeredSave(This,pIBmp,progress)	\
    (This)->lpVtbl -> EndLayeredSave(This,pIBmp,progress)

#define IGXTranslator3_GetXlatorID(This,pdwID)	\
    (This)->lpVtbl -> GetXlatorID(This,pdwID)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE IGXTranslator3_SetLoadScale_Proxy( 
    IGXTranslator3 __RPC_FAR * This,
    /* [in] */ DWORD dwNumerator,
    /* [in] */ DWORD dwDenominator);


void __RPC_STUB IGXTranslator3_SetLoadScale_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IGXTranslator3_QueryNumberLayers_Proxy( 
    IGXTranslator3 __RPC_FAR * This,
    /* [in][string] */ unsigned char __RPC_FAR *pszFileName,
    /* [out] */ DWORD __RPC_FAR *pdwNumLayers);


void __RPC_STUB IGXTranslator3_QueryNumberLayers_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IGXTranslator3_QueryLayer_Proxy( 
    IGXTranslator3 __RPC_FAR * This,
    /* [in][string] */ unsigned char __RPC_FAR *pszFileName,
    /* [in] */ DWORD dwLayerNumber,
    /* [out] */ BITMAPINFOHEADER __RPC_FAR *pBmi,
    /* [out] */ EPlayFrameType __RPC_FAR *format);


void __RPC_STUB IGXTranslator3_QueryLayer_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IGXTranslator3_LoadLayer_Proxy( 
    IGXTranslator3 __RPC_FAR * This,
    /* [in][string] */ unsigned char __RPC_FAR *pszFileName,
    /* [in] */ DWORD dwLayerNumber,
    /* [in] */ EPlayFrameType format,
    /* [out] */ IGXIntBitmap __RPC_FAR *__RPC_FAR *ppIBmp,
    /* [in] */ IGXProgressAdviseSink __RPC_FAR *progress);


void __RPC_STUB IGXTranslator3_LoadLayer_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IGXTranslator3_GetLayerAttribute_Proxy( 
    IGXTranslator3 __RPC_FAR * This,
    /* [in] */ ELayerAttribute eAttribute,
    /* [in] */ DWORD dwBufferSize,
    /* [out] */ void __RPC_FAR *pBuffer);


void __RPC_STUB IGXTranslator3_GetLayerAttribute_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IGXTranslator3_SetLayerAttribute_Proxy( 
    IGXTranslator3 __RPC_FAR * This,
    /* [in] */ ELayerAttribute eAttribute,
    /* [in] */ void __RPC_FAR *pBuffer);


void __RPC_STUB IGXTranslator3_SetLayerAttribute_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IGXTranslator3_CanISaveLayers_Proxy( 
    IGXTranslator3 __RPC_FAR * This);


void __RPC_STUB IGXTranslator3_CanISaveLayers_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IGXTranslator3_BeginLayeredSave_Proxy( 
    IGXTranslator3 __RPC_FAR * This,
    /* [in][string] */ unsigned char __RPC_FAR *pszFileName,
    /* [in] */ DWORD nNumLayers,
    /* [in] */ IGXProgressAdviseSink __RPC_FAR *progress);


void __RPC_STUB IGXTranslator3_BeginLayeredSave_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IGXTranslator3_SaveLayer_Proxy( 
    IGXTranslator3 __RPC_FAR * This,
    /* [in] */ IGXIntBitmap __RPC_FAR *pIBmp,
    /* [in] */ IGXProgressAdviseSink __RPC_FAR *progress);


void __RPC_STUB IGXTranslator3_SaveLayer_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IGXTranslator3_EndLayeredSave_Proxy( 
    IGXTranslator3 __RPC_FAR * This,
    /* [in] */ IGXIntBitmap __RPC_FAR *pIBmp,
    /* [in] */ IGXProgressAdviseSink __RPC_FAR *progress);


void __RPC_STUB IGXTranslator3_EndLayeredSave_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IGXTranslator3_GetXlatorID_Proxy( 
    IGXTranslator3 __RPC_FAR * This,
    /* [out] */ DWORD __RPC_FAR *pdwID);


void __RPC_STUB IGXTranslator3_GetXlatorID_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IGXTranslator3_INTERFACE_DEFINED__ */


#ifndef __IGXTranslator4_INTERFACE_DEFINED__
#define __IGXTranslator4_INTERFACE_DEFINED__

/****************************************
 * Generated header for interface: IGXTranslator4
 * at Tue Nov 23 05:02:08 1999
 * using MIDL 3.01.75
 ****************************************/
/* [local][uuid][object] */ 


typedef 
enum tagSetClientIOFlag
    {	NoRedirectIO	= 0x1,
	RedirectIO	= 0x2,
	UsesTemporary	= 0x4
    }	SetClientIOFlag;


EXTERN_C const IID IID_IGXTranslator4;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    interface DECLSPEC_UUID("8335e6bb-ab3b-11ce-8468-0000b468276b")
    IGXTranslator4 : public IGXTranslator3
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE LoadFileToBuffer( 
            /* [in][string] */ LPTSTR pszFileName,
            /* [in] */ EPlayFrameType format,
            /* [out] */ IGXIntBitmap2 __RPC_FAR *__RPC_FAR *ppIBmp,
            /* [in] */ IGXProgressAdviseSink __RPC_FAR *progress,
            /* [in] */ BITMAPINFOHEADER __RPC_FAR *imageHeader,
            /* [in][string] */ unsigned char __RPC_FAR *buffer,
            /* [in] */ DWORD __RPC_FAR *size) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE LoadFile( 
            /* [in][string] */ LPTSTR pszFileName,
            /* [in] */ EPlayFrameType format,
            /* [out] */ IGXIntBitmap2 __RPC_FAR *__RPC_FAR *ppIBmp,
            /* [in] */ IGXProgressAdviseSink __RPC_FAR *progress) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SaveFile( 
            /* [in][string] */ LPTSTR pszFileName,
            /* [in] */ IGXIntBitmap2 __RPC_FAR *pIBmp,
            /* [in] */ IGXProgressAdviseSink __RPC_FAR *progress) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetAlphaColor( 
            /* [in] */ WORD col1,
            /* [in] */ WORD col2,
            /* [in] */ WORD col3) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetDefaultImageColor( 
            /* [in] */ WORD col1,
            /* [in] */ WORD col2,
            /* [in] */ WORD col3) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE LoadConfigFromStream( 
            /* [in] */ IStream __RPC_FAR *stream) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SaveConfigToStream( 
            /* [in] */ IStream __RPC_FAR *stream) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SaveConfigToBuffer( 
            /* [in] */ PlayXlatorOpt __RPC_FAR *Opt) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE LoadConfigFromBuffer( 
            /* [in] */ PlayXlatorOpt __RPC_FAR *Opt) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE ConfigDialogExecute( 
            /* [in][string] */ LPTSTR pszFileName,
            /* [in] */ IGXIntBitmap2 __RPC_FAR *pIBmp,
            /* [in] */ BOOL ReadOnly,
            /* [in] */ IGXOptionsCallback __RPC_FAR *Callback) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetLastLoadFileName( 
            /* [out][string] */ LPTSTR __RPC_FAR *FileName) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetMasterLoadFileName( 
            /* [out][string] */ LPTSTR __RPC_FAR *FileName) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetFileMatchOptions( 
            /* [in] */ FileNameMatchOptions __RPC_FAR *Opt) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetFileMatchOptions( 
            /* [in] */ FileNameMatchOptions __RPC_FAR *Opt) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetEnumCompressors( 
            /* [out] */ IEnumCompressors2 __RPC_FAR *__RPC_FAR *ppIenum) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE UseEnumCompressors( 
            /* [in] */ BOOL Flag) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE CanSetClientIO( 
            /* [out] */ SetClientIOFlag __RPC_FAR *Flag) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE CanCompressorBeChanged( 
            /* [out] */ BOOL __RPC_FAR *Flag) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE QueryNumberLayers( 
            /* [in][string] */ LPTSTR pszFileName,
            /* [out] */ DWORD __RPC_FAR *pdwNumLayers) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE QueryLayer( 
            /* [in][string] */ LPTSTR pszFileName,
            /* [in] */ DWORD dwLayerNumber,
            /* [out] */ BITMAPINFOHEADER __RPC_FAR *pBmi,
            /* [out] */ EPlayFrameType __RPC_FAR *format) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE LoadLayer( 
            /* [in][string] */ LPTSTR pszFileName,
            /* [in] */ DWORD dwLayerNumber,
            /* [in] */ EPlayFrameType format,
            /* [out] */ IGXIntBitmap2 __RPC_FAR *__RPC_FAR *ppIBmp,
            /* [in] */ IGXProgressAdviseSink __RPC_FAR *progress) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE BeginLayeredSave( 
            /* [in][string] */ LPTSTR pszFileName,
            /* [in] */ DWORD nNumLayers,
            /* [in] */ IGXProgressAdviseSink __RPC_FAR *progress) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SaveLayer( 
            /* [in] */ IGXIntBitmap2 __RPC_FAR *pIBmp,
            /* [in] */ IGXProgressAdviseSink __RPC_FAR *progress) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE EndLayeredSave( 
            /* [in] */ IGXIntBitmap2 __RPC_FAR *pIBmp,
            /* [in] */ IGXProgressAdviseSink __RPC_FAR *progress) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE CanBeBruteForced( 
            /* [out] */ BOOL __RPC_FAR *Flag) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetCompressionRatio( 
            /* [in][string] */ LPTSTR pszFileName,
            /* [out] */ float __RPC_FAR *Ratio) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetSizeofImageData( 
            /* [in][string] */ LPTSTR pszFileName,
            /* [out] */ DWORD __RPC_FAR *SizeofImageData) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE DoesInterlacedFrames( 
            /* [out] */ BOOL __RPC_FAR *Interlace) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IGXTranslator4Vtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            IGXTranslator4 __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            IGXTranslator4 __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            IGXTranslator4 __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *ValidateFile )( 
            IGXTranslator4 __RPC_FAR * This,
            /* [in][string] */ unsigned char __RPC_FAR *pszFileName);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *CanILoad )( 
            IGXTranslator4 __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *CanISave )( 
            IGXTranslator4 __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetXlatorName )( 
            IGXTranslator4 __RPC_FAR * This,
            /* [in] */ DWORD fileTypeSize,
            /* [out] */ unsigned char __RPC_FAR *szFileTypeName);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetXlatorDescription )( 
            IGXTranslator4 __RPC_FAR * This,
            /* [in] */ DWORD fileDescripSize,
            /* [out] */ unsigned char __RPC_FAR *szFileDescripName);
        
        void ( STDMETHODCALLTYPE __RPC_FAR *SetClientIO )( 
            IGXTranslator4 __RPC_FAR * This,
            /* [in] */ IGXClientIO __RPC_FAR *pClientIO);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *LoadFile )( 
            IGXTranslator4 __RPC_FAR * This,
            /* [in][string] */ unsigned char __RPC_FAR *pszFileName,
            /* [in] */ EPlayFrameType format,
            /* [out] */ IGXIntBitmap __RPC_FAR *__RPC_FAR *ppIBmp,
            /* [in] */ IGXProgressAdviseSink __RPC_FAR *progress);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SaveFile )( 
            IGXTranslator4 __RPC_FAR * This,
            /* [in][string] */ unsigned char __RPC_FAR *pszFileName,
            /* [in] */ IGXIntBitmap __RPC_FAR *pIBmp,
            /* [in] */ IGXProgressAdviseSink __RPC_FAR *progress);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetFrameNumber )( 
            IGXTranslator4 __RPC_FAR * This,
            /* [in] */ DWORD frameNumber);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryFrameNumber )( 
            IGXTranslator4 __RPC_FAR * This,
            /* [out] */ DWORD __RPC_FAR *frameNumber);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryImageHeader )( 
            IGXTranslator4 __RPC_FAR * This,
            /* [in][string] */ unsigned char __RPC_FAR *pszFileName,
            /* [out] */ BITMAPINFOHEADER __RPC_FAR *pBmi,
            /* [out] */ EPlayFrameType __RPC_FAR *format);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryNumberFrames )( 
            IGXTranslator4 __RPC_FAR * This,
            /* [string][in] */ unsigned char __RPC_FAR *pszFileName,
            /* [out] */ DWORD __RPC_FAR *numFrames);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryFrameRate )( 
            IGXTranslator4 __RPC_FAR * This,
            /* [string][in] */ unsigned char __RPC_FAR *pszFileName,
            /* [out] */ DWORD __RPC_FAR *Scale,
            /* [out] */ DWORD __RPC_FAR *Rate);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetFrameRate )( 
            IGXTranslator4 __RPC_FAR * This,
            /* [in] */ DWORD Scale,
            /* [in] */ DWORD Rate);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *UpdateFrameRate )( 
            IGXTranslator4 __RPC_FAR * This,
            /* [string][in] */ unsigned char __RPC_FAR *pszFileName,
            /* [in] */ DWORD Scale,
            /* [in] */ DWORD Rate);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetEnumCompressors )( 
            IGXTranslator4 __RPC_FAR * This,
            /* [out] */ IEnumCompressors __RPC_FAR *__RPC_FAR *ppIenum);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetCompressor )( 
            IGXTranslator4 __RPC_FAR * This,
            /* [in] */ DWORD CompCode);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetCompressor )( 
            IGXTranslator4 __RPC_FAR * This,
            /* [out] */ DWORD __RPC_FAR *CompCode);
        
        REFCLSID ( STDMETHODCALLTYPE __RPC_FAR *QueryCLSID )( 
            IGXTranslator4 __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetLoadScale )( 
            IGXTranslator4 __RPC_FAR * This,
            /* [in] */ DWORD dwNumerator,
            /* [in] */ DWORD dwDenominator);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryNumberLayers )( 
            IGXTranslator4 __RPC_FAR * This,
            /* [in][string] */ unsigned char __RPC_FAR *pszFileName,
            /* [out] */ DWORD __RPC_FAR *pdwNumLayers);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryLayer )( 
            IGXTranslator4 __RPC_FAR * This,
            /* [in][string] */ unsigned char __RPC_FAR *pszFileName,
            /* [in] */ DWORD dwLayerNumber,
            /* [out] */ BITMAPINFOHEADER __RPC_FAR *pBmi,
            /* [out] */ EPlayFrameType __RPC_FAR *format);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *LoadLayer )( 
            IGXTranslator4 __RPC_FAR * This,
            /* [in][string] */ unsigned char __RPC_FAR *pszFileName,
            /* [in] */ DWORD dwLayerNumber,
            /* [in] */ EPlayFrameType format,
            /* [out] */ IGXIntBitmap __RPC_FAR *__RPC_FAR *ppIBmp,
            /* [in] */ IGXProgressAdviseSink __RPC_FAR *progress);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetLayerAttribute )( 
            IGXTranslator4 __RPC_FAR * This,
            /* [in] */ ELayerAttribute eAttribute,
            /* [in] */ DWORD dwBufferSize,
            /* [out] */ void __RPC_FAR *pBuffer);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetLayerAttribute )( 
            IGXTranslator4 __RPC_FAR * This,
            /* [in] */ ELayerAttribute eAttribute,
            /* [in] */ void __RPC_FAR *pBuffer);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *CanISaveLayers )( 
            IGXTranslator4 __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *BeginLayeredSave )( 
            IGXTranslator4 __RPC_FAR * This,
            /* [in][string] */ unsigned char __RPC_FAR *pszFileName,
            /* [in] */ DWORD nNumLayers,
            /* [in] */ IGXProgressAdviseSink __RPC_FAR *progress);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SaveLayer )( 
            IGXTranslator4 __RPC_FAR * This,
            /* [in] */ IGXIntBitmap __RPC_FAR *pIBmp,
            /* [in] */ IGXProgressAdviseSink __RPC_FAR *progress);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *EndLayeredSave )( 
            IGXTranslator4 __RPC_FAR * This,
            /* [in] */ IGXIntBitmap __RPC_FAR *pIBmp,
            /* [in] */ IGXProgressAdviseSink __RPC_FAR *progress);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetXlatorID )( 
            IGXTranslator4 __RPC_FAR * This,
            /* [out] */ DWORD __RPC_FAR *pdwID);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *LoadFileToBuffer )( 
            IGXTranslator4 __RPC_FAR * This,
            /* [in][string] */ LPTSTR pszFileName,
            /* [in] */ EPlayFrameType format,
            /* [out] */ IGXIntBitmap2 __RPC_FAR *__RPC_FAR *ppIBmp,
            /* [in] */ IGXProgressAdviseSink __RPC_FAR *progress,
            /* [in] */ BITMAPINFOHEADER __RPC_FAR *imageHeader,
            /* [in][string] */ unsigned char __RPC_FAR *buffer,
            /* [in] */ DWORD __RPC_FAR *size);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *LoadFile )( 
            IGXTranslator4 __RPC_FAR * This,
            /* [in][string] */ LPTSTR pszFileName,
            /* [in] */ EPlayFrameType format,
            /* [out] */ IGXIntBitmap2 __RPC_FAR *__RPC_FAR *ppIBmp,
            /* [in] */ IGXProgressAdviseSink __RPC_FAR *progress);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SaveFile )( 
            IGXTranslator4 __RPC_FAR * This,
            /* [in][string] */ LPTSTR pszFileName,
            /* [in] */ IGXIntBitmap2 __RPC_FAR *pIBmp,
            /* [in] */ IGXProgressAdviseSink __RPC_FAR *progress);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetAlphaColor )( 
            IGXTranslator4 __RPC_FAR * This,
            /* [in] */ WORD col1,
            /* [in] */ WORD col2,
            /* [in] */ WORD col3);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetDefaultImageColor )( 
            IGXTranslator4 __RPC_FAR * This,
            /* [in] */ WORD col1,
            /* [in] */ WORD col2,
            /* [in] */ WORD col3);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *LoadConfigFromStream )( 
            IGXTranslator4 __RPC_FAR * This,
            /* [in] */ IStream __RPC_FAR *stream);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SaveConfigToStream )( 
            IGXTranslator4 __RPC_FAR * This,
            /* [in] */ IStream __RPC_FAR *stream);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SaveConfigToBuffer )( 
            IGXTranslator4 __RPC_FAR * This,
            /* [in] */ PlayXlatorOpt __RPC_FAR *Opt);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *LoadConfigFromBuffer )( 
            IGXTranslator4 __RPC_FAR * This,
            /* [in] */ PlayXlatorOpt __RPC_FAR *Opt);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *ConfigDialogExecute )( 
            IGXTranslator4 __RPC_FAR * This,
            /* [in][string] */ LPTSTR pszFileName,
            /* [in] */ IGXIntBitmap2 __RPC_FAR *pIBmp,
            /* [in] */ BOOL ReadOnly,
            /* [in] */ IGXOptionsCallback __RPC_FAR *Callback);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetLastLoadFileName )( 
            IGXTranslator4 __RPC_FAR * This,
            /* [out][string] */ LPTSTR __RPC_FAR *FileName);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetMasterLoadFileName )( 
            IGXTranslator4 __RPC_FAR * This,
            /* [out][string] */ LPTSTR __RPC_FAR *FileName);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetFileMatchOptions )( 
            IGXTranslator4 __RPC_FAR * This,
            /* [in] */ FileNameMatchOptions __RPC_FAR *Opt);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetFileMatchOptions )( 
            IGXTranslator4 __RPC_FAR * This,
            /* [in] */ FileNameMatchOptions __RPC_FAR *Opt);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetEnumCompressors )( 
            IGXTranslator4 __RPC_FAR * This,
            /* [out] */ IEnumCompressors2 __RPC_FAR *__RPC_FAR *ppIenum);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *UseEnumCompressors )( 
            IGXTranslator4 __RPC_FAR * This,
            /* [in] */ BOOL Flag);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *CanSetClientIO )( 
            IGXTranslator4 __RPC_FAR * This,
            /* [out] */ SetClientIOFlag __RPC_FAR *Flag);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *CanCompressorBeChanged )( 
            IGXTranslator4 __RPC_FAR * This,
            /* [out] */ BOOL __RPC_FAR *Flag);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryNumberLayers )( 
            IGXTranslator4 __RPC_FAR * This,
            /* [in][string] */ LPTSTR pszFileName,
            /* [out] */ DWORD __RPC_FAR *pdwNumLayers);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryLayer )( 
            IGXTranslator4 __RPC_FAR * This,
            /* [in][string] */ LPTSTR pszFileName,
            /* [in] */ DWORD dwLayerNumber,
            /* [out] */ BITMAPINFOHEADER __RPC_FAR *pBmi,
            /* [out] */ EPlayFrameType __RPC_FAR *format);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *LoadLayer )( 
            IGXTranslator4 __RPC_FAR * This,
            /* [in][string] */ LPTSTR pszFileName,
            /* [in] */ DWORD dwLayerNumber,
            /* [in] */ EPlayFrameType format,
            /* [out] */ IGXIntBitmap2 __RPC_FAR *__RPC_FAR *ppIBmp,
            /* [in] */ IGXProgressAdviseSink __RPC_FAR *progress);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *BeginLayeredSave )( 
            IGXTranslator4 __RPC_FAR * This,
            /* [in][string] */ LPTSTR pszFileName,
            /* [in] */ DWORD nNumLayers,
            /* [in] */ IGXProgressAdviseSink __RPC_FAR *progress);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SaveLayer )( 
            IGXTranslator4 __RPC_FAR * This,
            /* [in] */ IGXIntBitmap2 __RPC_FAR *pIBmp,
            /* [in] */ IGXProgressAdviseSink __RPC_FAR *progress);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *EndLayeredSave )( 
            IGXTranslator4 __RPC_FAR * This,
            /* [in] */ IGXIntBitmap2 __RPC_FAR *pIBmp,
            /* [in] */ IGXProgressAdviseSink __RPC_FAR *progress);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *CanBeBruteForced )( 
            IGXTranslator4 __RPC_FAR * This,
            /* [out] */ BOOL __RPC_FAR *Flag);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetCompressionRatio )( 
            IGXTranslator4 __RPC_FAR * This,
            /* [in][string] */ LPTSTR pszFileName,
            /* [out] */ float __RPC_FAR *Ratio);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetSizeofImageData )( 
            IGXTranslator4 __RPC_FAR * This,
            /* [in][string] */ LPTSTR pszFileName,
            /* [out] */ DWORD __RPC_FAR *SizeofImageData);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *DoesInterlacedFrames )( 
            IGXTranslator4 __RPC_FAR * This,
            /* [out] */ BOOL __RPC_FAR *Interlace);
        
        END_INTERFACE
    } IGXTranslator4Vtbl;

    interface IGXTranslator4
    {
        CONST_VTBL struct IGXTranslator4Vtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IGXTranslator4_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IGXTranslator4_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IGXTranslator4_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IGXTranslator4_ValidateFile(This,pszFileName)	\
    (This)->lpVtbl -> ValidateFile(This,pszFileName)

#define IGXTranslator4_CanILoad(This)	\
    (This)->lpVtbl -> CanILoad(This)

#define IGXTranslator4_CanISave(This)	\
    (This)->lpVtbl -> CanISave(This)

#define IGXTranslator4_GetXlatorName(This,fileTypeSize,szFileTypeName)	\
    (This)->lpVtbl -> GetXlatorName(This,fileTypeSize,szFileTypeName)

#define IGXTranslator4_GetXlatorDescription(This,fileDescripSize,szFileDescripName)	\
    (This)->lpVtbl -> GetXlatorDescription(This,fileDescripSize,szFileDescripName)

#define IGXTranslator4_SetClientIO(This,pClientIO)	\
    (This)->lpVtbl -> SetClientIO(This,pClientIO)

#define IGXTranslator4_LoadFile(This,pszFileName,format,ppIBmp,progress)	\
    (This)->lpVtbl -> LoadFile(This,pszFileName,format,ppIBmp,progress)

#define IGXTranslator4_SaveFile(This,pszFileName,pIBmp,progress)	\
    (This)->lpVtbl -> SaveFile(This,pszFileName,pIBmp,progress)


#define IGXTranslator4_SetFrameNumber(This,frameNumber)	\
    (This)->lpVtbl -> SetFrameNumber(This,frameNumber)

#define IGXTranslator4_QueryFrameNumber(This,frameNumber)	\
    (This)->lpVtbl -> QueryFrameNumber(This,frameNumber)

#define IGXTranslator4_QueryImageHeader(This,pszFileName,pBmi,format)	\
    (This)->lpVtbl -> QueryImageHeader(This,pszFileName,pBmi,format)

#define IGXTranslator4_QueryNumberFrames(This,pszFileName,numFrames)	\
    (This)->lpVtbl -> QueryNumberFrames(This,pszFileName,numFrames)

#define IGXTranslator4_QueryFrameRate(This,pszFileName,Scale,Rate)	\
    (This)->lpVtbl -> QueryFrameRate(This,pszFileName,Scale,Rate)

#define IGXTranslator4_SetFrameRate(This,Scale,Rate)	\
    (This)->lpVtbl -> SetFrameRate(This,Scale,Rate)

#define IGXTranslator4_UpdateFrameRate(This,pszFileName,Scale,Rate)	\
    (This)->lpVtbl -> UpdateFrameRate(This,pszFileName,Scale,Rate)

#define IGXTranslator4_GetEnumCompressors(This,ppIenum)	\
    (This)->lpVtbl -> GetEnumCompressors(This,ppIenum)

#define IGXTranslator4_SetCompressor(This,CompCode)	\
    (This)->lpVtbl -> SetCompressor(This,CompCode)

#define IGXTranslator4_GetCompressor(This,CompCode)	\
    (This)->lpVtbl -> GetCompressor(This,CompCode)

#define IGXTranslator4_QueryCLSID(This)	\
    (This)->lpVtbl -> QueryCLSID(This)


#define IGXTranslator4_SetLoadScale(This,dwNumerator,dwDenominator)	\
    (This)->lpVtbl -> SetLoadScale(This,dwNumerator,dwDenominator)

#define IGXTranslator4_QueryNumberLayers(This,pszFileName,pdwNumLayers)	\
    (This)->lpVtbl -> QueryNumberLayers(This,pszFileName,pdwNumLayers)

#define IGXTranslator4_QueryLayer(This,pszFileName,dwLayerNumber,pBmi,format)	\
    (This)->lpVtbl -> QueryLayer(This,pszFileName,dwLayerNumber,pBmi,format)

#define IGXTranslator4_LoadLayer(This,pszFileName,dwLayerNumber,format,ppIBmp,progress)	\
    (This)->lpVtbl -> LoadLayer(This,pszFileName,dwLayerNumber,format,ppIBmp,progress)

#define IGXTranslator4_GetLayerAttribute(This,eAttribute,dwBufferSize,pBuffer)	\
    (This)->lpVtbl -> GetLayerAttribute(This,eAttribute,dwBufferSize,pBuffer)

#define IGXTranslator4_SetLayerAttribute(This,eAttribute,pBuffer)	\
    (This)->lpVtbl -> SetLayerAttribute(This,eAttribute,pBuffer)

#define IGXTranslator4_CanISaveLayers(This)	\
    (This)->lpVtbl -> CanISaveLayers(This)

#define IGXTranslator4_BeginLayeredSave(This,pszFileName,nNumLayers,progress)	\
    (This)->lpVtbl -> BeginLayeredSave(This,pszFileName,nNumLayers,progress)

#define IGXTranslator4_SaveLayer(This,pIBmp,progress)	\
    (This)->lpVtbl -> SaveLayer(This,pIBmp,progress)

#define IGXTranslator4_EndLayeredSave(This,pIBmp,progress)	\
    (This)->lpVtbl -> EndLayeredSave(This,pIBmp,progress)

#define IGXTranslator4_GetXlatorID(This,pdwID)	\
    (This)->lpVtbl -> GetXlatorID(This,pdwID)


#define IGXTranslator4_LoadFileToBuffer(This,pszFileName,format,ppIBmp,progress,imageHeader,buffer,size)	\
    (This)->lpVtbl -> LoadFileToBuffer(This,pszFileName,format,ppIBmp,progress,imageHeader,buffer,size)

#define IGXTranslator4_LoadFile(This,pszFileName,format,ppIBmp,progress)	\
    (This)->lpVtbl -> LoadFile(This,pszFileName,format,ppIBmp,progress)

#define IGXTranslator4_SaveFile(This,pszFileName,pIBmp,progress)	\
    (This)->lpVtbl -> SaveFile(This,pszFileName,pIBmp,progress)

#define IGXTranslator4_SetAlphaColor(This,col1,col2,col3)	\
    (This)->lpVtbl -> SetAlphaColor(This,col1,col2,col3)

#define IGXTranslator4_SetDefaultImageColor(This,col1,col2,col3)	\
    (This)->lpVtbl -> SetDefaultImageColor(This,col1,col2,col3)

#define IGXTranslator4_LoadConfigFromStream(This,stream)	\
    (This)->lpVtbl -> LoadConfigFromStream(This,stream)

#define IGXTranslator4_SaveConfigToStream(This,stream)	\
    (This)->lpVtbl -> SaveConfigToStream(This,stream)

#define IGXTranslator4_SaveConfigToBuffer(This,Opt)	\
    (This)->lpVtbl -> SaveConfigToBuffer(This,Opt)

#define IGXTranslator4_LoadConfigFromBuffer(This,Opt)	\
    (This)->lpVtbl -> LoadConfigFromBuffer(This,Opt)

#define IGXTranslator4_ConfigDialogExecute(This,pszFileName,pIBmp,ReadOnly,Callback)	\
    (This)->lpVtbl -> ConfigDialogExecute(This,pszFileName,pIBmp,ReadOnly,Callback)

#define IGXTranslator4_GetLastLoadFileName(This,FileName)	\
    (This)->lpVtbl -> GetLastLoadFileName(This,FileName)

#define IGXTranslator4_GetMasterLoadFileName(This,FileName)	\
    (This)->lpVtbl -> GetMasterLoadFileName(This,FileName)

#define IGXTranslator4_SetFileMatchOptions(This,Opt)	\
    (This)->lpVtbl -> SetFileMatchOptions(This,Opt)

#define IGXTranslator4_GetFileMatchOptions(This,Opt)	\
    (This)->lpVtbl -> GetFileMatchOptions(This,Opt)

#define IGXTranslator4_GetEnumCompressors(This,ppIenum)	\
    (This)->lpVtbl -> GetEnumCompressors(This,ppIenum)

#define IGXTranslator4_UseEnumCompressors(This,Flag)	\
    (This)->lpVtbl -> UseEnumCompressors(This,Flag)

#define IGXTranslator4_CanSetClientIO(This,Flag)	\
    (This)->lpVtbl -> CanSetClientIO(This,Flag)

#define IGXTranslator4_CanCompressorBeChanged(This,Flag)	\
    (This)->lpVtbl -> CanCompressorBeChanged(This,Flag)

#define IGXTranslator4_QueryNumberLayers(This,pszFileName,pdwNumLayers)	\
    (This)->lpVtbl -> QueryNumberLayers(This,pszFileName,pdwNumLayers)

#define IGXTranslator4_QueryLayer(This,pszFileName,dwLayerNumber,pBmi,format)	\
    (This)->lpVtbl -> QueryLayer(This,pszFileName,dwLayerNumber,pBmi,format)

#define IGXTranslator4_LoadLayer(This,pszFileName,dwLayerNumber,format,ppIBmp,progress)	\
    (This)->lpVtbl -> LoadLayer(This,pszFileName,dwLayerNumber,format,ppIBmp,progress)

#define IGXTranslator4_BeginLayeredSave(This,pszFileName,nNumLayers,progress)	\
    (This)->lpVtbl -> BeginLayeredSave(This,pszFileName,nNumLayers,progress)

#define IGXTranslator4_SaveLayer(This,pIBmp,progress)	\
    (This)->lpVtbl -> SaveLayer(This,pIBmp,progress)

#define IGXTranslator4_EndLayeredSave(This,pIBmp,progress)	\
    (This)->lpVtbl -> EndLayeredSave(This,pIBmp,progress)

#define IGXTranslator4_CanBeBruteForced(This,Flag)	\
    (This)->lpVtbl -> CanBeBruteForced(This,Flag)

#define IGXTranslator4_GetCompressionRatio(This,pszFileName,Ratio)	\
    (This)->lpVtbl -> GetCompressionRatio(This,pszFileName,Ratio)

#define IGXTranslator4_GetSizeofImageData(This,pszFileName,SizeofImageData)	\
    (This)->lpVtbl -> GetSizeofImageData(This,pszFileName,SizeofImageData)

#define IGXTranslator4_DoesInterlacedFrames(This,Interlace)	\
    (This)->lpVtbl -> DoesInterlacedFrames(This,Interlace)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE IGXTranslator4_LoadFileToBuffer_Proxy( 
    IGXTranslator4 __RPC_FAR * This,
    /* [in][string] */ LPTSTR pszFileName,
    /* [in] */ EPlayFrameType format,
    /* [out] */ IGXIntBitmap2 __RPC_FAR *__RPC_FAR *ppIBmp,
    /* [in] */ IGXProgressAdviseSink __RPC_FAR *progress,
    /* [in] */ BITMAPINFOHEADER __RPC_FAR *imageHeader,
    /* [in][string] */ unsigned char __RPC_FAR *buffer,
    /* [in] */ DWORD __RPC_FAR *size);


void __RPC_STUB IGXTranslator4_LoadFileToBuffer_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IGXTranslator4_LoadFile_Proxy( 
    IGXTranslator4 __RPC_FAR * This,
    /* [in][string] */ LPTSTR pszFileName,
    /* [in] */ EPlayFrameType format,
    /* [out] */ IGXIntBitmap2 __RPC_FAR *__RPC_FAR *ppIBmp,
    /* [in] */ IGXProgressAdviseSink __RPC_FAR *progress);


void __RPC_STUB IGXTranslator4_LoadFile_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IGXTranslator4_SaveFile_Proxy( 
    IGXTranslator4 __RPC_FAR * This,
    /* [in][string] */ LPTSTR pszFileName,
    /* [in] */ IGXIntBitmap2 __RPC_FAR *pIBmp,
    /* [in] */ IGXProgressAdviseSink __RPC_FAR *progress);


void __RPC_STUB IGXTranslator4_SaveFile_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IGXTranslator4_SetAlphaColor_Proxy( 
    IGXTranslator4 __RPC_FAR * This,
    /* [in] */ WORD col1,
    /* [in] */ WORD col2,
    /* [in] */ WORD col3);


void __RPC_STUB IGXTranslator4_SetAlphaColor_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IGXTranslator4_SetDefaultImageColor_Proxy( 
    IGXTranslator4 __RPC_FAR * This,
    /* [in] */ WORD col1,
    /* [in] */ WORD col2,
    /* [in] */ WORD col3);


void __RPC_STUB IGXTranslator4_SetDefaultImageColor_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IGXTranslator4_LoadConfigFromStream_Proxy( 
    IGXTranslator4 __RPC_FAR * This,
    /* [in] */ IStream __RPC_FAR *stream);


void __RPC_STUB IGXTranslator4_LoadConfigFromStream_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IGXTranslator4_SaveConfigToStream_Proxy( 
    IGXTranslator4 __RPC_FAR * This,
    /* [in] */ IStream __RPC_FAR *stream);


void __RPC_STUB IGXTranslator4_SaveConfigToStream_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IGXTranslator4_SaveConfigToBuffer_Proxy( 
    IGXTranslator4 __RPC_FAR * This,
    /* [in] */ PlayXlatorOpt __RPC_FAR *Opt);


void __RPC_STUB IGXTranslator4_SaveConfigToBuffer_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IGXTranslator4_LoadConfigFromBuffer_Proxy( 
    IGXTranslator4 __RPC_FAR * This,
    /* [in] */ PlayXlatorOpt __RPC_FAR *Opt);


void __RPC_STUB IGXTranslator4_LoadConfigFromBuffer_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IGXTranslator4_ConfigDialogExecute_Proxy( 
    IGXTranslator4 __RPC_FAR * This,
    /* [in][string] */ LPTSTR pszFileName,
    /* [in] */ IGXIntBitmap2 __RPC_FAR *pIBmp,
    /* [in] */ BOOL ReadOnly,
    /* [in] */ IGXOptionsCallback __RPC_FAR *Callback);


void __RPC_STUB IGXTranslator4_ConfigDialogExecute_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IGXTranslator4_GetLastLoadFileName_Proxy( 
    IGXTranslator4 __RPC_FAR * This,
    /* [out][string] */ LPTSTR __RPC_FAR *FileName);


void __RPC_STUB IGXTranslator4_GetLastLoadFileName_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IGXTranslator4_GetMasterLoadFileName_Proxy( 
    IGXTranslator4 __RPC_FAR * This,
    /* [out][string] */ LPTSTR __RPC_FAR *FileName);


void __RPC_STUB IGXTranslator4_GetMasterLoadFileName_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IGXTranslator4_SetFileMatchOptions_Proxy( 
    IGXTranslator4 __RPC_FAR * This,
    /* [in] */ FileNameMatchOptions __RPC_FAR *Opt);


void __RPC_STUB IGXTranslator4_SetFileMatchOptions_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IGXTranslator4_GetFileMatchOptions_Proxy( 
    IGXTranslator4 __RPC_FAR * This,
    /* [in] */ FileNameMatchOptions __RPC_FAR *Opt);


void __RPC_STUB IGXTranslator4_GetFileMatchOptions_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IGXTranslator4_GetEnumCompressors_Proxy( 
    IGXTranslator4 __RPC_FAR * This,
    /* [out] */ IEnumCompressors2 __RPC_FAR *__RPC_FAR *ppIenum);


void __RPC_STUB IGXTranslator4_GetEnumCompressors_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IGXTranslator4_UseEnumCompressors_Proxy( 
    IGXTranslator4 __RPC_FAR * This,
    /* [in] */ BOOL Flag);


void __RPC_STUB IGXTranslator4_UseEnumCompressors_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IGXTranslator4_CanSetClientIO_Proxy( 
    IGXTranslator4 __RPC_FAR * This,
    /* [out] */ SetClientIOFlag __RPC_FAR *Flag);


void __RPC_STUB IGXTranslator4_CanSetClientIO_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IGXTranslator4_CanCompressorBeChanged_Proxy( 
    IGXTranslator4 __RPC_FAR * This,
    /* [out] */ BOOL __RPC_FAR *Flag);


void __RPC_STUB IGXTranslator4_CanCompressorBeChanged_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IGXTranslator4_QueryNumberLayers_Proxy( 
    IGXTranslator4 __RPC_FAR * This,
    /* [in][string] */ LPTSTR pszFileName,
    /* [out] */ DWORD __RPC_FAR *pdwNumLayers);


void __RPC_STUB IGXTranslator4_QueryNumberLayers_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IGXTranslator4_QueryLayer_Proxy( 
    IGXTranslator4 __RPC_FAR * This,
    /* [in][string] */ LPTSTR pszFileName,
    /* [in] */ DWORD dwLayerNumber,
    /* [out] */ BITMAPINFOHEADER __RPC_FAR *pBmi,
    /* [out] */ EPlayFrameType __RPC_FAR *format);


void __RPC_STUB IGXTranslator4_QueryLayer_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IGXTranslator4_LoadLayer_Proxy( 
    IGXTranslator4 __RPC_FAR * This,
    /* [in][string] */ LPTSTR pszFileName,
    /* [in] */ DWORD dwLayerNumber,
    /* [in] */ EPlayFrameType format,
    /* [out] */ IGXIntBitmap2 __RPC_FAR *__RPC_FAR *ppIBmp,
    /* [in] */ IGXProgressAdviseSink __RPC_FAR *progress);


void __RPC_STUB IGXTranslator4_LoadLayer_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IGXTranslator4_BeginLayeredSave_Proxy( 
    IGXTranslator4 __RPC_FAR * This,
    /* [in][string] */ LPTSTR pszFileName,
    /* [in] */ DWORD nNumLayers,
    /* [in] */ IGXProgressAdviseSink __RPC_FAR *progress);


void __RPC_STUB IGXTranslator4_BeginLayeredSave_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IGXTranslator4_SaveLayer_Proxy( 
    IGXTranslator4 __RPC_FAR * This,
    /* [in] */ IGXIntBitmap2 __RPC_FAR *pIBmp,
    /* [in] */ IGXProgressAdviseSink __RPC_FAR *progress);


void __RPC_STUB IGXTranslator4_SaveLayer_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IGXTranslator4_EndLayeredSave_Proxy( 
    IGXTranslator4 __RPC_FAR * This,
    /* [in] */ IGXIntBitmap2 __RPC_FAR *pIBmp,
    /* [in] */ IGXProgressAdviseSink __RPC_FAR *progress);


void __RPC_STUB IGXTranslator4_EndLayeredSave_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IGXTranslator4_CanBeBruteForced_Proxy( 
    IGXTranslator4 __RPC_FAR * This,
    /* [out] */ BOOL __RPC_FAR *Flag);


void __RPC_STUB IGXTranslator4_CanBeBruteForced_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IGXTranslator4_GetCompressionRatio_Proxy( 
    IGXTranslator4 __RPC_FAR * This,
    /* [in][string] */ LPTSTR pszFileName,
    /* [out] */ float __RPC_FAR *Ratio);


void __RPC_STUB IGXTranslator4_GetCompressionRatio_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IGXTranslator4_GetSizeofImageData_Proxy( 
    IGXTranslator4 __RPC_FAR * This,
    /* [in][string] */ LPTSTR pszFileName,
    /* [out] */ DWORD __RPC_FAR *SizeofImageData);


void __RPC_STUB IGXTranslator4_GetSizeofImageData_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IGXTranslator4_DoesInterlacedFrames_Proxy( 
    IGXTranslator4 __RPC_FAR * This,
    /* [out] */ BOOL __RPC_FAR *Interlace);


void __RPC_STUB IGXTranslator4_DoesInterlacedFrames_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IGXTranslator4_INTERFACE_DEFINED__ */


#ifndef __IGXAbsBitmap_INTERFACE_DEFINED__
#define __IGXAbsBitmap_INTERFACE_DEFINED__

/****************************************
 * Generated header for interface: IGXAbsBitmap
 * at Tue Nov 23 05:02:08 1999
 * using MIDL 3.01.75
 ****************************************/
/* [local][uuid][object] */ 



EXTERN_C const IID IID_IGXAbsBitmap;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    interface DECLSPEC_UUID("8335e5f6-ab3b-11ce-8468-0000b468276b")
    IGXAbsBitmap : public IUnknown
    {
    public:
        virtual void STDMETHODCALLTYPE GetBitDepths( 
            /* [out] */ DWORD __RPC_FAR *depthMask) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetBitDepth( 
            /* [in] */ DWORD depth) = 0;
        
        virtual void STDMETHODCALLTYPE GetColorSpaces( 
            /* [out] */ DWORD __RPC_FAR *colorSpaces) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetColorSpace( 
            /* [in] */ EGXColorSpace color) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE PaletteBased( void) = 0;
        
        virtual void STDMETHODCALLTYPE PaletteBitDepths( 
            /* [out] */ DWORD __RPC_FAR *paletteMask) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE DoesCompression( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE CompressionLossy( void) = 0;
        
        virtual void STDMETHODCALLTYPE NumCompressionSteps( 
            /* [out] */ WORD __RPC_FAR *compressSteps) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetCompressionLevel( 
            /* [in] */ WORD compressLevel) = 0;
        
        virtual void STDMETHODCALLTYPE GetCompressionLevel( 
            /* [out] */ WORD __RPC_FAR *compressLevel) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IGXAbsBitmapVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            IGXAbsBitmap __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            IGXAbsBitmap __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            IGXAbsBitmap __RPC_FAR * This);
        
        void ( STDMETHODCALLTYPE __RPC_FAR *GetBitDepths )( 
            IGXAbsBitmap __RPC_FAR * This,
            /* [out] */ DWORD __RPC_FAR *depthMask);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetBitDepth )( 
            IGXAbsBitmap __RPC_FAR * This,
            /* [in] */ DWORD depth);
        
        void ( STDMETHODCALLTYPE __RPC_FAR *GetColorSpaces )( 
            IGXAbsBitmap __RPC_FAR * This,
            /* [out] */ DWORD __RPC_FAR *colorSpaces);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetColorSpace )( 
            IGXAbsBitmap __RPC_FAR * This,
            /* [in] */ EGXColorSpace color);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *PaletteBased )( 
            IGXAbsBitmap __RPC_FAR * This);
        
        void ( STDMETHODCALLTYPE __RPC_FAR *PaletteBitDepths )( 
            IGXAbsBitmap __RPC_FAR * This,
            /* [out] */ DWORD __RPC_FAR *paletteMask);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *DoesCompression )( 
            IGXAbsBitmap __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *CompressionLossy )( 
            IGXAbsBitmap __RPC_FAR * This);
        
        void ( STDMETHODCALLTYPE __RPC_FAR *NumCompressionSteps )( 
            IGXAbsBitmap __RPC_FAR * This,
            /* [out] */ WORD __RPC_FAR *compressSteps);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetCompressionLevel )( 
            IGXAbsBitmap __RPC_FAR * This,
            /* [in] */ WORD compressLevel);
        
        void ( STDMETHODCALLTYPE __RPC_FAR *GetCompressionLevel )( 
            IGXAbsBitmap __RPC_FAR * This,
            /* [out] */ WORD __RPC_FAR *compressLevel);
        
        END_INTERFACE
    } IGXAbsBitmapVtbl;

    interface IGXAbsBitmap
    {
        CONST_VTBL struct IGXAbsBitmapVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IGXAbsBitmap_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IGXAbsBitmap_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IGXAbsBitmap_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IGXAbsBitmap_GetBitDepths(This,depthMask)	\
    (This)->lpVtbl -> GetBitDepths(This,depthMask)

#define IGXAbsBitmap_SetBitDepth(This,depth)	\
    (This)->lpVtbl -> SetBitDepth(This,depth)

#define IGXAbsBitmap_GetColorSpaces(This,colorSpaces)	\
    (This)->lpVtbl -> GetColorSpaces(This,colorSpaces)

#define IGXAbsBitmap_SetColorSpace(This,color)	\
    (This)->lpVtbl -> SetColorSpace(This,color)

#define IGXAbsBitmap_PaletteBased(This)	\
    (This)->lpVtbl -> PaletteBased(This)

#define IGXAbsBitmap_PaletteBitDepths(This,paletteMask)	\
    (This)->lpVtbl -> PaletteBitDepths(This,paletteMask)

#define IGXAbsBitmap_DoesCompression(This)	\
    (This)->lpVtbl -> DoesCompression(This)

#define IGXAbsBitmap_CompressionLossy(This)	\
    (This)->lpVtbl -> CompressionLossy(This)

#define IGXAbsBitmap_NumCompressionSteps(This,compressSteps)	\
    (This)->lpVtbl -> NumCompressionSteps(This,compressSteps)

#define IGXAbsBitmap_SetCompressionLevel(This,compressLevel)	\
    (This)->lpVtbl -> SetCompressionLevel(This,compressLevel)

#define IGXAbsBitmap_GetCompressionLevel(This,compressLevel)	\
    (This)->lpVtbl -> GetCompressionLevel(This,compressLevel)

#endif /* COBJMACROS */


#endif 	/* C style interface */



void STDMETHODCALLTYPE IGXAbsBitmap_GetBitDepths_Proxy( 
    IGXAbsBitmap __RPC_FAR * This,
    /* [out] */ DWORD __RPC_FAR *depthMask);


void __RPC_STUB IGXAbsBitmap_GetBitDepths_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IGXAbsBitmap_SetBitDepth_Proxy( 
    IGXAbsBitmap __RPC_FAR * This,
    /* [in] */ DWORD depth);


void __RPC_STUB IGXAbsBitmap_SetBitDepth_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


void STDMETHODCALLTYPE IGXAbsBitmap_GetColorSpaces_Proxy( 
    IGXAbsBitmap __RPC_FAR * This,
    /* [out] */ DWORD __RPC_FAR *colorSpaces);


void __RPC_STUB IGXAbsBitmap_GetColorSpaces_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IGXAbsBitmap_SetColorSpace_Proxy( 
    IGXAbsBitmap __RPC_FAR * This,
    /* [in] */ EGXColorSpace color);


void __RPC_STUB IGXAbsBitmap_SetColorSpace_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IGXAbsBitmap_PaletteBased_Proxy( 
    IGXAbsBitmap __RPC_FAR * This);


void __RPC_STUB IGXAbsBitmap_PaletteBased_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


void STDMETHODCALLTYPE IGXAbsBitmap_PaletteBitDepths_Proxy( 
    IGXAbsBitmap __RPC_FAR * This,
    /* [out] */ DWORD __RPC_FAR *paletteMask);


void __RPC_STUB IGXAbsBitmap_PaletteBitDepths_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IGXAbsBitmap_DoesCompression_Proxy( 
    IGXAbsBitmap __RPC_FAR * This);


void __RPC_STUB IGXAbsBitmap_DoesCompression_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IGXAbsBitmap_CompressionLossy_Proxy( 
    IGXAbsBitmap __RPC_FAR * This);


void __RPC_STUB IGXAbsBitmap_CompressionLossy_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


void STDMETHODCALLTYPE IGXAbsBitmap_NumCompressionSteps_Proxy( 
    IGXAbsBitmap __RPC_FAR * This,
    /* [out] */ WORD __RPC_FAR *compressSteps);


void __RPC_STUB IGXAbsBitmap_NumCompressionSteps_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IGXAbsBitmap_SetCompressionLevel_Proxy( 
    IGXAbsBitmap __RPC_FAR * This,
    /* [in] */ WORD compressLevel);


void __RPC_STUB IGXAbsBitmap_SetCompressionLevel_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


void STDMETHODCALLTYPE IGXAbsBitmap_GetCompressionLevel_Proxy( 
    IGXAbsBitmap __RPC_FAR * This,
    /* [out] */ WORD __RPC_FAR *compressLevel);


void __RPC_STUB IGXAbsBitmap_GetCompressionLevel_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IGXAbsBitmap_INTERFACE_DEFINED__ */


#ifndef __IGXAbsBitmap2_INTERFACE_DEFINED__
#define __IGXAbsBitmap2_INTERFACE_DEFINED__

/****************************************
 * Generated header for interface: IGXAbsBitmap2
 * at Tue Nov 23 05:02:08 1999
 * using MIDL 3.01.75
 ****************************************/
/* [local][uuid][object] */ 



EXTERN_C const IID IID_IGXAbsBitmap2;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    interface DECLSPEC_UUID("8335e60b-ab3b-11ce-8468-0000b468276b")
    IGXAbsBitmap2 : public IGXAbsBitmap
    {
    public:
        virtual BOOL STDMETHODCALLTYPE IsMovieFile( void) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IGXAbsBitmap2Vtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            IGXAbsBitmap2 __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            IGXAbsBitmap2 __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            IGXAbsBitmap2 __RPC_FAR * This);
        
        void ( STDMETHODCALLTYPE __RPC_FAR *GetBitDepths )( 
            IGXAbsBitmap2 __RPC_FAR * This,
            /* [out] */ DWORD __RPC_FAR *depthMask);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetBitDepth )( 
            IGXAbsBitmap2 __RPC_FAR * This,
            /* [in] */ DWORD depth);
        
        void ( STDMETHODCALLTYPE __RPC_FAR *GetColorSpaces )( 
            IGXAbsBitmap2 __RPC_FAR * This,
            /* [out] */ DWORD __RPC_FAR *colorSpaces);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetColorSpace )( 
            IGXAbsBitmap2 __RPC_FAR * This,
            /* [in] */ EGXColorSpace color);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *PaletteBased )( 
            IGXAbsBitmap2 __RPC_FAR * This);
        
        void ( STDMETHODCALLTYPE __RPC_FAR *PaletteBitDepths )( 
            IGXAbsBitmap2 __RPC_FAR * This,
            /* [out] */ DWORD __RPC_FAR *paletteMask);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *DoesCompression )( 
            IGXAbsBitmap2 __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *CompressionLossy )( 
            IGXAbsBitmap2 __RPC_FAR * This);
        
        void ( STDMETHODCALLTYPE __RPC_FAR *NumCompressionSteps )( 
            IGXAbsBitmap2 __RPC_FAR * This,
            /* [out] */ WORD __RPC_FAR *compressSteps);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetCompressionLevel )( 
            IGXAbsBitmap2 __RPC_FAR * This,
            /* [in] */ WORD compressLevel);
        
        void ( STDMETHODCALLTYPE __RPC_FAR *GetCompressionLevel )( 
            IGXAbsBitmap2 __RPC_FAR * This,
            /* [out] */ WORD __RPC_FAR *compressLevel);
        
        BOOL ( STDMETHODCALLTYPE __RPC_FAR *IsMovieFile )( 
            IGXAbsBitmap2 __RPC_FAR * This);
        
        END_INTERFACE
    } IGXAbsBitmap2Vtbl;

    interface IGXAbsBitmap2
    {
        CONST_VTBL struct IGXAbsBitmap2Vtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IGXAbsBitmap2_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IGXAbsBitmap2_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IGXAbsBitmap2_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IGXAbsBitmap2_GetBitDepths(This,depthMask)	\
    (This)->lpVtbl -> GetBitDepths(This,depthMask)

#define IGXAbsBitmap2_SetBitDepth(This,depth)	\
    (This)->lpVtbl -> SetBitDepth(This,depth)

#define IGXAbsBitmap2_GetColorSpaces(This,colorSpaces)	\
    (This)->lpVtbl -> GetColorSpaces(This,colorSpaces)

#define IGXAbsBitmap2_SetColorSpace(This,color)	\
    (This)->lpVtbl -> SetColorSpace(This,color)

#define IGXAbsBitmap2_PaletteBased(This)	\
    (This)->lpVtbl -> PaletteBased(This)

#define IGXAbsBitmap2_PaletteBitDepths(This,paletteMask)	\
    (This)->lpVtbl -> PaletteBitDepths(This,paletteMask)

#define IGXAbsBitmap2_DoesCompression(This)	\
    (This)->lpVtbl -> DoesCompression(This)

#define IGXAbsBitmap2_CompressionLossy(This)	\
    (This)->lpVtbl -> CompressionLossy(This)

#define IGXAbsBitmap2_NumCompressionSteps(This,compressSteps)	\
    (This)->lpVtbl -> NumCompressionSteps(This,compressSteps)

#define IGXAbsBitmap2_SetCompressionLevel(This,compressLevel)	\
    (This)->lpVtbl -> SetCompressionLevel(This,compressLevel)

#define IGXAbsBitmap2_GetCompressionLevel(This,compressLevel)	\
    (This)->lpVtbl -> GetCompressionLevel(This,compressLevel)


#define IGXAbsBitmap2_IsMovieFile(This)	\
    (This)->lpVtbl -> IsMovieFile(This)

#endif /* COBJMACROS */


#endif 	/* C style interface */



BOOL STDMETHODCALLTYPE IGXAbsBitmap2_IsMovieFile_Proxy( 
    IGXAbsBitmap2 __RPC_FAR * This);


void __RPC_STUB IGXAbsBitmap2_IsMovieFile_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IGXAbsBitmap2_INTERFACE_DEFINED__ */


#ifndef __IGXIntBitmap_INTERFACE_DEFINED__
#define __IGXIntBitmap_INTERFACE_DEFINED__

/****************************************
 * Generated header for interface: IGXIntBitmap
 * at Tue Nov 23 05:02:08 1999
 * using MIDL 3.01.75
 ****************************************/
/* [local][uuid][object] */ 



EXTERN_C const IID IID_IGXIntBitmap;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    interface DECLSPEC_UUID("8335e5f7-ab3b-11ce-8468-0000b468276b")
    IGXIntBitmap : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE AllocateSpace( 
            /* [in] */ DWORD width,
            /* [in] */ DWORD height,
            /* [in] */ EPlayFrameType ftype) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE AttachSpace( 
            /* [in] */ BITMAPINFOHEADER __RPC_FAR *imageHeader,
            /* [in] */ EPlayFrameType pixelFormat,
            /* [in] */ BYTE __RPC_FAR *pixelData) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE CloneBitmap( 
            /* [out] */ IGXIntBitmap __RPC_FAR *__RPC_FAR *pIGXBmp) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE WriteFrameStore( 
            /* [in] */ const unsigned char __RPC_FAR *pFSName,
            /* [in] */ IGXProgressAdviseSink __RPC_FAR *progress) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE ReadFrameStore( 
            /* [in] */ const unsigned char __RPC_FAR *pFSName,
            /* [in] */ IGXProgressAdviseSink __RPC_FAR *progress) = 0;
        
        virtual void STDMETHODCALLTYPE GetSPlayBitMap( 
            /* [out] */ SPlayBitMap __RPC_FAR *__RPC_FAR *pSPBmp) = 0;
        
        virtual void STDMETHODCALLTYPE GetHeaderSize( 
            /* [out] */ DWORD __RPC_FAR *size) = 0;
        
        virtual void STDMETHODCALLTYPE GetBitmapSize( 
            /* [out] */ DWORD __RPC_FAR *size) = 0;
        
        virtual void STDMETHODCALLTYPE GetTranslator( 
            /* [out] */ IGXTranslator __RPC_FAR *__RPC_FAR *pTrans) = 0;
        
        virtual void STDMETHODCALLTYPE SetTranslator( 
            /* [in] */ IGXTranslator __RPC_FAR *pTrans) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE TranslateMem2Mem( 
            /* [in] */ EPlayFrameType dstFmt,
            /* [out] */ IGXIntBitmap __RPC_FAR *__RPC_FAR *ppDstBmp,
            /* [in] */ IGXProgressAdviseSink __RPC_FAR *progress) = 0;
        
        virtual void STDMETHODCALLTYPE GetYUVPaletteSize( 
            /* [out] */ DWORD __RPC_FAR *pPalSize) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetYUVPalette( 
            /* [out] */ BYTE __RPC_FAR *pYUVPal) = 0;
        
        virtual void STDMETHODCALLTYPE GetRowBytes( 
            /* [out] */ LONG __RPC_FAR *numBytes) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE InsertAlpha( 
            /* [in] */ IGXIntBitmap __RPC_FAR *Alpha) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IGXIntBitmapVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            IGXIntBitmap __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            IGXIntBitmap __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            IGXIntBitmap __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *AllocateSpace )( 
            IGXIntBitmap __RPC_FAR * This,
            /* [in] */ DWORD width,
            /* [in] */ DWORD height,
            /* [in] */ EPlayFrameType ftype);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *AttachSpace )( 
            IGXIntBitmap __RPC_FAR * This,
            /* [in] */ BITMAPINFOHEADER __RPC_FAR *imageHeader,
            /* [in] */ EPlayFrameType pixelFormat,
            /* [in] */ BYTE __RPC_FAR *pixelData);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *CloneBitmap )( 
            IGXIntBitmap __RPC_FAR * This,
            /* [out] */ IGXIntBitmap __RPC_FAR *__RPC_FAR *pIGXBmp);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *WriteFrameStore )( 
            IGXIntBitmap __RPC_FAR * This,
            /* [in] */ const unsigned char __RPC_FAR *pFSName,
            /* [in] */ IGXProgressAdviseSink __RPC_FAR *progress);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *ReadFrameStore )( 
            IGXIntBitmap __RPC_FAR * This,
            /* [in] */ const unsigned char __RPC_FAR *pFSName,
            /* [in] */ IGXProgressAdviseSink __RPC_FAR *progress);
        
        void ( STDMETHODCALLTYPE __RPC_FAR *GetSPlayBitMap )( 
            IGXIntBitmap __RPC_FAR * This,
            /* [out] */ SPlayBitMap __RPC_FAR *__RPC_FAR *pSPBmp);
        
        void ( STDMETHODCALLTYPE __RPC_FAR *GetHeaderSize )( 
            IGXIntBitmap __RPC_FAR * This,
            /* [out] */ DWORD __RPC_FAR *size);
        
        void ( STDMETHODCALLTYPE __RPC_FAR *GetBitmapSize )( 
            IGXIntBitmap __RPC_FAR * This,
            /* [out] */ DWORD __RPC_FAR *size);
        
        void ( STDMETHODCALLTYPE __RPC_FAR *GetTranslator )( 
            IGXIntBitmap __RPC_FAR * This,
            /* [out] */ IGXTranslator __RPC_FAR *__RPC_FAR *pTrans);
        
        void ( STDMETHODCALLTYPE __RPC_FAR *SetTranslator )( 
            IGXIntBitmap __RPC_FAR * This,
            /* [in] */ IGXTranslator __RPC_FAR *pTrans);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *TranslateMem2Mem )( 
            IGXIntBitmap __RPC_FAR * This,
            /* [in] */ EPlayFrameType dstFmt,
            /* [out] */ IGXIntBitmap __RPC_FAR *__RPC_FAR *ppDstBmp,
            /* [in] */ IGXProgressAdviseSink __RPC_FAR *progress);
        
        void ( STDMETHODCALLTYPE __RPC_FAR *GetYUVPaletteSize )( 
            IGXIntBitmap __RPC_FAR * This,
            /* [out] */ DWORD __RPC_FAR *pPalSize);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetYUVPalette )( 
            IGXIntBitmap __RPC_FAR * This,
            /* [out] */ BYTE __RPC_FAR *pYUVPal);
        
        void ( STDMETHODCALLTYPE __RPC_FAR *GetRowBytes )( 
            IGXIntBitmap __RPC_FAR * This,
            /* [out] */ LONG __RPC_FAR *numBytes);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *InsertAlpha )( 
            IGXIntBitmap __RPC_FAR * This,
            /* [in] */ IGXIntBitmap __RPC_FAR *Alpha);
        
        END_INTERFACE
    } IGXIntBitmapVtbl;

    interface IGXIntBitmap
    {
        CONST_VTBL struct IGXIntBitmapVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IGXIntBitmap_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IGXIntBitmap_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IGXIntBitmap_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IGXIntBitmap_AllocateSpace(This,width,height,ftype)	\
    (This)->lpVtbl -> AllocateSpace(This,width,height,ftype)

#define IGXIntBitmap_AttachSpace(This,imageHeader,pixelFormat,pixelData)	\
    (This)->lpVtbl -> AttachSpace(This,imageHeader,pixelFormat,pixelData)

#define IGXIntBitmap_CloneBitmap(This,pIGXBmp)	\
    (This)->lpVtbl -> CloneBitmap(This,pIGXBmp)

#define IGXIntBitmap_WriteFrameStore(This,pFSName,progress)	\
    (This)->lpVtbl -> WriteFrameStore(This,pFSName,progress)

#define IGXIntBitmap_ReadFrameStore(This,pFSName,progress)	\
    (This)->lpVtbl -> ReadFrameStore(This,pFSName,progress)

#define IGXIntBitmap_GetSPlayBitMap(This,pSPBmp)	\
    (This)->lpVtbl -> GetSPlayBitMap(This,pSPBmp)

#define IGXIntBitmap_GetHeaderSize(This,size)	\
    (This)->lpVtbl -> GetHeaderSize(This,size)

#define IGXIntBitmap_GetBitmapSize(This,size)	\
    (This)->lpVtbl -> GetBitmapSize(This,size)

#define IGXIntBitmap_GetTranslator(This,pTrans)	\
    (This)->lpVtbl -> GetTranslator(This,pTrans)

#define IGXIntBitmap_SetTranslator(This,pTrans)	\
    (This)->lpVtbl -> SetTranslator(This,pTrans)

#define IGXIntBitmap_TranslateMem2Mem(This,dstFmt,ppDstBmp,progress)	\
    (This)->lpVtbl -> TranslateMem2Mem(This,dstFmt,ppDstBmp,progress)

#define IGXIntBitmap_GetYUVPaletteSize(This,pPalSize)	\
    (This)->lpVtbl -> GetYUVPaletteSize(This,pPalSize)

#define IGXIntBitmap_GetYUVPalette(This,pYUVPal)	\
    (This)->lpVtbl -> GetYUVPalette(This,pYUVPal)

#define IGXIntBitmap_GetRowBytes(This,numBytes)	\
    (This)->lpVtbl -> GetRowBytes(This,numBytes)

#define IGXIntBitmap_InsertAlpha(This,Alpha)	\
    (This)->lpVtbl -> InsertAlpha(This,Alpha)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE IGXIntBitmap_AllocateSpace_Proxy( 
    IGXIntBitmap __RPC_FAR * This,
    /* [in] */ DWORD width,
    /* [in] */ DWORD height,
    /* [in] */ EPlayFrameType ftype);


void __RPC_STUB IGXIntBitmap_AllocateSpace_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IGXIntBitmap_AttachSpace_Proxy( 
    IGXIntBitmap __RPC_FAR * This,
    /* [in] */ BITMAPINFOHEADER __RPC_FAR *imageHeader,
    /* [in] */ EPlayFrameType pixelFormat,
    /* [in] */ BYTE __RPC_FAR *pixelData);


void __RPC_STUB IGXIntBitmap_AttachSpace_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IGXIntBitmap_CloneBitmap_Proxy( 
    IGXIntBitmap __RPC_FAR * This,
    /* [out] */ IGXIntBitmap __RPC_FAR *__RPC_FAR *pIGXBmp);


void __RPC_STUB IGXIntBitmap_CloneBitmap_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IGXIntBitmap_WriteFrameStore_Proxy( 
    IGXIntBitmap __RPC_FAR * This,
    /* [in] */ const unsigned char __RPC_FAR *pFSName,
    /* [in] */ IGXProgressAdviseSink __RPC_FAR *progress);


void __RPC_STUB IGXIntBitmap_WriteFrameStore_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IGXIntBitmap_ReadFrameStore_Proxy( 
    IGXIntBitmap __RPC_FAR * This,
    /* [in] */ const unsigned char __RPC_FAR *pFSName,
    /* [in] */ IGXProgressAdviseSink __RPC_FAR *progress);


void __RPC_STUB IGXIntBitmap_ReadFrameStore_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


void STDMETHODCALLTYPE IGXIntBitmap_GetSPlayBitMap_Proxy( 
    IGXIntBitmap __RPC_FAR * This,
    /* [out] */ SPlayBitMap __RPC_FAR *__RPC_FAR *pSPBmp);


void __RPC_STUB IGXIntBitmap_GetSPlayBitMap_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


void STDMETHODCALLTYPE IGXIntBitmap_GetHeaderSize_Proxy( 
    IGXIntBitmap __RPC_FAR * This,
    /* [out] */ DWORD __RPC_FAR *size);


void __RPC_STUB IGXIntBitmap_GetHeaderSize_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


void STDMETHODCALLTYPE IGXIntBitmap_GetBitmapSize_Proxy( 
    IGXIntBitmap __RPC_FAR * This,
    /* [out] */ DWORD __RPC_FAR *size);


void __RPC_STUB IGXIntBitmap_GetBitmapSize_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


void STDMETHODCALLTYPE IGXIntBitmap_GetTranslator_Proxy( 
    IGXIntBitmap __RPC_FAR * This,
    /* [out] */ IGXTranslator __RPC_FAR *__RPC_FAR *pTrans);


void __RPC_STUB IGXIntBitmap_GetTranslator_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


void STDMETHODCALLTYPE IGXIntBitmap_SetTranslator_Proxy( 
    IGXIntBitmap __RPC_FAR * This,
    /* [in] */ IGXTranslator __RPC_FAR *pTrans);


void __RPC_STUB IGXIntBitmap_SetTranslator_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IGXIntBitmap_TranslateMem2Mem_Proxy( 
    IGXIntBitmap __RPC_FAR * This,
    /* [in] */ EPlayFrameType dstFmt,
    /* [out] */ IGXIntBitmap __RPC_FAR *__RPC_FAR *ppDstBmp,
    /* [in] */ IGXProgressAdviseSink __RPC_FAR *progress);


void __RPC_STUB IGXIntBitmap_TranslateMem2Mem_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


void STDMETHODCALLTYPE IGXIntBitmap_GetYUVPaletteSize_Proxy( 
    IGXIntBitmap __RPC_FAR * This,
    /* [out] */ DWORD __RPC_FAR *pPalSize);


void __RPC_STUB IGXIntBitmap_GetYUVPaletteSize_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IGXIntBitmap_GetYUVPalette_Proxy( 
    IGXIntBitmap __RPC_FAR * This,
    /* [out] */ BYTE __RPC_FAR *pYUVPal);


void __RPC_STUB IGXIntBitmap_GetYUVPalette_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


void STDMETHODCALLTYPE IGXIntBitmap_GetRowBytes_Proxy( 
    IGXIntBitmap __RPC_FAR * This,
    /* [out] */ LONG __RPC_FAR *numBytes);


void __RPC_STUB IGXIntBitmap_GetRowBytes_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IGXIntBitmap_InsertAlpha_Proxy( 
    IGXIntBitmap __RPC_FAR * This,
    /* [in] */ IGXIntBitmap __RPC_FAR *Alpha);


void __RPC_STUB IGXIntBitmap_InsertAlpha_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IGXIntBitmap_INTERFACE_DEFINED__ */


#ifndef __IGXIntBitmap2_INTERFACE_DEFINED__
#define __IGXIntBitmap2_INTERFACE_DEFINED__

/****************************************
 * Generated header for interface: IGXIntBitmap2
 * at Tue Nov 23 05:02:08 1999
 * using MIDL 3.01.75
 ****************************************/
/* [local][uuid][object] */ 


typedef 
enum tagClipboardType
    {	cbNoData	= 0,
	cbValidBitmap	= 0x1,
	cbValidText	= 0x2
    }	ClipboardType;

typedef 
enum tagInfoAttribute
    {	iaInvalidAttr	= 0,
	iaAttributesChanged	= 0x1,
	iaOrigFileSize	= 0x81,
	iaOrigImageSize	= 0x82,
	iaBitmapInfoHeader	= 0x83,
	iaLastModifiedTime	= 0x84,
	iaCreatedTime	= 0x85,
	iaLastModifiedBy	= 0x86,
	iaCreatedBy	= 0x87,
	iaNumberFrames	= 0x88,
	iaFormatVersion	= 0x89,
	iaJobTime	= 0x103,
	iaJobResetTime	= 0x104,
	iaJobStart	= 0x105,
	iaJobStop	= 0x106
    }	InfoAttribute;

typedef struct  tagAttributeVar
    {
    union 
        {
        LARGE_INTEGER FS;
        LPTSTR __RPC_FAR *StrRtn;
        LARGE_INTEGER lgAttr;
        DWORD dwAttr;
        WORD wAttr;
        BYTE bAttr;
        BOOL lAttr;
        FILETIME Time;
        EPlayFrameType FType;
        }	;
    }	AttributeVar;


EXTERN_C const IID IID_IGXIntBitmap2;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    interface DECLSPEC_UUID("8335e6bd-ab3b-11ce-8468-0000b468276b")
    IGXIntBitmap2 : public IGXIntBitmap
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE TranslateMem2Buffer( 
            /* [in] */ EPlayFrameType dstFmt,
            /* [out] */ IGXIntBitmap2 __RPC_FAR *__RPC_FAR *ppDstBmp,
            /* [in] */ IGXProgressAdviseSink __RPC_FAR *progress,
            /* [in] */ BITMAPINFOHEADER __RPC_FAR *imageHeader,
            /* [in][string] */ unsigned char __RPC_FAR *buffer,
            /* [in] */ DWORD __RPC_FAR *size) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE TranslateMem2Mem( 
            /* [in] */ EPlayFrameType dstFmt,
            /* [out] */ IGXIntBitmap2 __RPC_FAR *__RPC_FAR *ppDstBmp,
            /* [in] */ IGXProgressAdviseSink __RPC_FAR *progress) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE CloneBitmap( 
            /* [out] */ IGXIntBitmap2 __RPC_FAR *__RPC_FAR *pIGXBmp) = 0;
        
        virtual void STDMETHODCALLTYPE GetTranslator( 
            /* [out] */ IGXTranslator4 __RPC_FAR *__RPC_FAR *pTrans) = 0;
        
        virtual void STDMETHODCALLTYPE SetTranslator( 
            /* [in] */ IGXTranslator4 __RPC_FAR *pTrans) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE AttachSpace( 
            /* [in] */ BITMAPINFOHEADER __RPC_FAR *imageHeader,
            /* [in] */ EPlayFrameType pixelFormat,
            /* [in] */ BYTE __RPC_FAR *pixelData,
            /* [in] */ DWORD pixelDataSize,
            /* [in] */ BOOL DefaultHeader) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE BuildPreProcessCtrl( 
            /* [in] */ SPlayBitMap __RPC_FAR *spbmp,
            /* [in] */ EPlayFrameType format,
            /* [in] */ void __RPC_FAR *hdr,
            /* [out] */ void __RPC_FAR *__RPC_FAR *pre) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetPreProcessPalette( 
            /* [in] */ void __RPC_FAR *pre,
            /* [out] */ void __RPC_FAR *__RPC_FAR *pal) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE CopyToClipboard( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE CopyFromClipboard( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE ValidBitmapOnClipboard( 
            ClipboardType __RPC_FAR *Flag) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetImageOptions( 
            /* [in] */ PlayXlatorOpt __RPC_FAR *Opt) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetAttr( 
            /* [in] */ InfoAttribute Attr,
            /* [in] */ AttributeVar __RPC_FAR *Value) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetAttr( 
            /* [in] */ InfoAttribute Attr,
            /* [out] */ AttributeVar __RPC_FAR *Value) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IGXIntBitmap2Vtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            IGXIntBitmap2 __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            IGXIntBitmap2 __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            IGXIntBitmap2 __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *AllocateSpace )( 
            IGXIntBitmap2 __RPC_FAR * This,
            /* [in] */ DWORD width,
            /* [in] */ DWORD height,
            /* [in] */ EPlayFrameType ftype);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *AttachSpace )( 
            IGXIntBitmap2 __RPC_FAR * This,
            /* [in] */ BITMAPINFOHEADER __RPC_FAR *imageHeader,
            /* [in] */ EPlayFrameType pixelFormat,
            /* [in] */ BYTE __RPC_FAR *pixelData);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *CloneBitmap )( 
            IGXIntBitmap2 __RPC_FAR * This,
            /* [out] */ IGXIntBitmap __RPC_FAR *__RPC_FAR *pIGXBmp);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *WriteFrameStore )( 
            IGXIntBitmap2 __RPC_FAR * This,
            /* [in] */ const unsigned char __RPC_FAR *pFSName,
            /* [in] */ IGXProgressAdviseSink __RPC_FAR *progress);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *ReadFrameStore )( 
            IGXIntBitmap2 __RPC_FAR * This,
            /* [in] */ const unsigned char __RPC_FAR *pFSName,
            /* [in] */ IGXProgressAdviseSink __RPC_FAR *progress);
        
        void ( STDMETHODCALLTYPE __RPC_FAR *GetSPlayBitMap )( 
            IGXIntBitmap2 __RPC_FAR * This,
            /* [out] */ SPlayBitMap __RPC_FAR *__RPC_FAR *pSPBmp);
        
        void ( STDMETHODCALLTYPE __RPC_FAR *GetHeaderSize )( 
            IGXIntBitmap2 __RPC_FAR * This,
            /* [out] */ DWORD __RPC_FAR *size);
        
        void ( STDMETHODCALLTYPE __RPC_FAR *GetBitmapSize )( 
            IGXIntBitmap2 __RPC_FAR * This,
            /* [out] */ DWORD __RPC_FAR *size);
        
        void ( STDMETHODCALLTYPE __RPC_FAR *GetTranslator )( 
            IGXIntBitmap2 __RPC_FAR * This,
            /* [out] */ IGXTranslator __RPC_FAR *__RPC_FAR *pTrans);
        
        void ( STDMETHODCALLTYPE __RPC_FAR *SetTranslator )( 
            IGXIntBitmap2 __RPC_FAR * This,
            /* [in] */ IGXTranslator __RPC_FAR *pTrans);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *TranslateMem2Mem )( 
            IGXIntBitmap2 __RPC_FAR * This,
            /* [in] */ EPlayFrameType dstFmt,
            /* [out] */ IGXIntBitmap __RPC_FAR *__RPC_FAR *ppDstBmp,
            /* [in] */ IGXProgressAdviseSink __RPC_FAR *progress);
        
        void ( STDMETHODCALLTYPE __RPC_FAR *GetYUVPaletteSize )( 
            IGXIntBitmap2 __RPC_FAR * This,
            /* [out] */ DWORD __RPC_FAR *pPalSize);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetYUVPalette )( 
            IGXIntBitmap2 __RPC_FAR * This,
            /* [out] */ BYTE __RPC_FAR *pYUVPal);
        
        void ( STDMETHODCALLTYPE __RPC_FAR *GetRowBytes )( 
            IGXIntBitmap2 __RPC_FAR * This,
            /* [out] */ LONG __RPC_FAR *numBytes);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *InsertAlpha )( 
            IGXIntBitmap2 __RPC_FAR * This,
            /* [in] */ IGXIntBitmap __RPC_FAR *Alpha);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *TranslateMem2Buffer )( 
            IGXIntBitmap2 __RPC_FAR * This,
            /* [in] */ EPlayFrameType dstFmt,
            /* [out] */ IGXIntBitmap2 __RPC_FAR *__RPC_FAR *ppDstBmp,
            /* [in] */ IGXProgressAdviseSink __RPC_FAR *progress,
            /* [in] */ BITMAPINFOHEADER __RPC_FAR *imageHeader,
            /* [in][string] */ unsigned char __RPC_FAR *buffer,
            /* [in] */ DWORD __RPC_FAR *size);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *TranslateMem2Mem )( 
            IGXIntBitmap2 __RPC_FAR * This,
            /* [in] */ EPlayFrameType dstFmt,
            /* [out] */ IGXIntBitmap2 __RPC_FAR *__RPC_FAR *ppDstBmp,
            /* [in] */ IGXProgressAdviseSink __RPC_FAR *progress);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *CloneBitmap )( 
            IGXIntBitmap2 __RPC_FAR * This,
            /* [out] */ IGXIntBitmap2 __RPC_FAR *__RPC_FAR *pIGXBmp);
        
        void ( STDMETHODCALLTYPE __RPC_FAR *GetTranslator )( 
            IGXIntBitmap2 __RPC_FAR * This,
            /* [out] */ IGXTranslator4 __RPC_FAR *__RPC_FAR *pTrans);
        
        void ( STDMETHODCALLTYPE __RPC_FAR *SetTranslator )( 
            IGXIntBitmap2 __RPC_FAR * This,
            /* [in] */ IGXTranslator4 __RPC_FAR *pTrans);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *AttachSpace )( 
            IGXIntBitmap2 __RPC_FAR * This,
            /* [in] */ BITMAPINFOHEADER __RPC_FAR *imageHeader,
            /* [in] */ EPlayFrameType pixelFormat,
            /* [in] */ BYTE __RPC_FAR *pixelData,
            /* [in] */ DWORD pixelDataSize,
            /* [in] */ BOOL DefaultHeader);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *BuildPreProcessCtrl )( 
            IGXIntBitmap2 __RPC_FAR * This,
            /* [in] */ SPlayBitMap __RPC_FAR *spbmp,
            /* [in] */ EPlayFrameType format,
            /* [in] */ void __RPC_FAR *hdr,
            /* [out] */ void __RPC_FAR *__RPC_FAR *pre);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetPreProcessPalette )( 
            IGXIntBitmap2 __RPC_FAR * This,
            /* [in] */ void __RPC_FAR *pre,
            /* [out] */ void __RPC_FAR *__RPC_FAR *pal);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *CopyToClipboard )( 
            IGXIntBitmap2 __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *CopyFromClipboard )( 
            IGXIntBitmap2 __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *ValidBitmapOnClipboard )( 
            IGXIntBitmap2 __RPC_FAR * This,
            ClipboardType __RPC_FAR *Flag);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetImageOptions )( 
            IGXIntBitmap2 __RPC_FAR * This,
            /* [in] */ PlayXlatorOpt __RPC_FAR *Opt);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetAttr )( 
            IGXIntBitmap2 __RPC_FAR * This,
            /* [in] */ InfoAttribute Attr,
            /* [in] */ AttributeVar __RPC_FAR *Value);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetAttr )( 
            IGXIntBitmap2 __RPC_FAR * This,
            /* [in] */ InfoAttribute Attr,
            /* [out] */ AttributeVar __RPC_FAR *Value);
        
        END_INTERFACE
    } IGXIntBitmap2Vtbl;

    interface IGXIntBitmap2
    {
        CONST_VTBL struct IGXIntBitmap2Vtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IGXIntBitmap2_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IGXIntBitmap2_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IGXIntBitmap2_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IGXIntBitmap2_AllocateSpace(This,width,height,ftype)	\
    (This)->lpVtbl -> AllocateSpace(This,width,height,ftype)

#define IGXIntBitmap2_AttachSpace(This,imageHeader,pixelFormat,pixelData)	\
    (This)->lpVtbl -> AttachSpace(This,imageHeader,pixelFormat,pixelData)

#define IGXIntBitmap2_CloneBitmap(This,pIGXBmp)	\
    (This)->lpVtbl -> CloneBitmap(This,pIGXBmp)

#define IGXIntBitmap2_WriteFrameStore(This,pFSName,progress)	\
    (This)->lpVtbl -> WriteFrameStore(This,pFSName,progress)

#define IGXIntBitmap2_ReadFrameStore(This,pFSName,progress)	\
    (This)->lpVtbl -> ReadFrameStore(This,pFSName,progress)

#define IGXIntBitmap2_GetSPlayBitMap(This,pSPBmp)	\
    (This)->lpVtbl -> GetSPlayBitMap(This,pSPBmp)

#define IGXIntBitmap2_GetHeaderSize(This,size)	\
    (This)->lpVtbl -> GetHeaderSize(This,size)

#define IGXIntBitmap2_GetBitmapSize(This,size)	\
    (This)->lpVtbl -> GetBitmapSize(This,size)

#define IGXIntBitmap2_GetTranslator(This,pTrans)	\
    (This)->lpVtbl -> GetTranslator(This,pTrans)

#define IGXIntBitmap2_SetTranslator(This,pTrans)	\
    (This)->lpVtbl -> SetTranslator(This,pTrans)

#define IGXIntBitmap2_TranslateMem2Mem(This,dstFmt,ppDstBmp,progress)	\
    (This)->lpVtbl -> TranslateMem2Mem(This,dstFmt,ppDstBmp,progress)

#define IGXIntBitmap2_GetYUVPaletteSize(This,pPalSize)	\
    (This)->lpVtbl -> GetYUVPaletteSize(This,pPalSize)

#define IGXIntBitmap2_GetYUVPalette(This,pYUVPal)	\
    (This)->lpVtbl -> GetYUVPalette(This,pYUVPal)

#define IGXIntBitmap2_GetRowBytes(This,numBytes)	\
    (This)->lpVtbl -> GetRowBytes(This,numBytes)

#define IGXIntBitmap2_InsertAlpha(This,Alpha)	\
    (This)->lpVtbl -> InsertAlpha(This,Alpha)


#define IGXIntBitmap2_TranslateMem2Buffer(This,dstFmt,ppDstBmp,progress,imageHeader,buffer,size)	\
    (This)->lpVtbl -> TranslateMem2Buffer(This,dstFmt,ppDstBmp,progress,imageHeader,buffer,size)

#define IGXIntBitmap2_TranslateMem2Mem(This,dstFmt,ppDstBmp,progress)	\
    (This)->lpVtbl -> TranslateMem2Mem(This,dstFmt,ppDstBmp,progress)

#define IGXIntBitmap2_CloneBitmap(This,pIGXBmp)	\
    (This)->lpVtbl -> CloneBitmap(This,pIGXBmp)

#define IGXIntBitmap2_GetTranslator(This,pTrans)	\
    (This)->lpVtbl -> GetTranslator(This,pTrans)

#define IGXIntBitmap2_SetTranslator(This,pTrans)	\
    (This)->lpVtbl -> SetTranslator(This,pTrans)

#define IGXIntBitmap2_AttachSpace(This,imageHeader,pixelFormat,pixelData,pixelDataSize,DefaultHeader)	\
    (This)->lpVtbl -> AttachSpace(This,imageHeader,pixelFormat,pixelData,pixelDataSize,DefaultHeader)

#define IGXIntBitmap2_BuildPreProcessCtrl(This,spbmp,format,hdr,pre)	\
    (This)->lpVtbl -> BuildPreProcessCtrl(This,spbmp,format,hdr,pre)

#define IGXIntBitmap2_GetPreProcessPalette(This,pre,pal)	\
    (This)->lpVtbl -> GetPreProcessPalette(This,pre,pal)

#define IGXIntBitmap2_CopyToClipboard(This)	\
    (This)->lpVtbl -> CopyToClipboard(This)

#define IGXIntBitmap2_CopyFromClipboard(This)	\
    (This)->lpVtbl -> CopyFromClipboard(This)

#define IGXIntBitmap2_ValidBitmapOnClipboard(This,Flag)	\
    (This)->lpVtbl -> ValidBitmapOnClipboard(This,Flag)

#define IGXIntBitmap2_SetImageOptions(This,Opt)	\
    (This)->lpVtbl -> SetImageOptions(This,Opt)

#define IGXIntBitmap2_SetAttr(This,Attr,Value)	\
    (This)->lpVtbl -> SetAttr(This,Attr,Value)

#define IGXIntBitmap2_GetAttr(This,Attr,Value)	\
    (This)->lpVtbl -> GetAttr(This,Attr,Value)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE IGXIntBitmap2_TranslateMem2Buffer_Proxy( 
    IGXIntBitmap2 __RPC_FAR * This,
    /* [in] */ EPlayFrameType dstFmt,
    /* [out] */ IGXIntBitmap2 __RPC_FAR *__RPC_FAR *ppDstBmp,
    /* [in] */ IGXProgressAdviseSink __RPC_FAR *progress,
    /* [in] */ BITMAPINFOHEADER __RPC_FAR *imageHeader,
    /* [in][string] */ unsigned char __RPC_FAR *buffer,
    /* [in] */ DWORD __RPC_FAR *size);


void __RPC_STUB IGXIntBitmap2_TranslateMem2Buffer_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IGXIntBitmap2_TranslateMem2Mem_Proxy( 
    IGXIntBitmap2 __RPC_FAR * This,
    /* [in] */ EPlayFrameType dstFmt,
    /* [out] */ IGXIntBitmap2 __RPC_FAR *__RPC_FAR *ppDstBmp,
    /* [in] */ IGXProgressAdviseSink __RPC_FAR *progress);


void __RPC_STUB IGXIntBitmap2_TranslateMem2Mem_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IGXIntBitmap2_CloneBitmap_Proxy( 
    IGXIntBitmap2 __RPC_FAR * This,
    /* [out] */ IGXIntBitmap2 __RPC_FAR *__RPC_FAR *pIGXBmp);


void __RPC_STUB IGXIntBitmap2_CloneBitmap_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


void STDMETHODCALLTYPE IGXIntBitmap2_GetTranslator_Proxy( 
    IGXIntBitmap2 __RPC_FAR * This,
    /* [out] */ IGXTranslator4 __RPC_FAR *__RPC_FAR *pTrans);


void __RPC_STUB IGXIntBitmap2_GetTranslator_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


void STDMETHODCALLTYPE IGXIntBitmap2_SetTranslator_Proxy( 
    IGXIntBitmap2 __RPC_FAR * This,
    /* [in] */ IGXTranslator4 __RPC_FAR *pTrans);


void __RPC_STUB IGXIntBitmap2_SetTranslator_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IGXIntBitmap2_AttachSpace_Proxy( 
    IGXIntBitmap2 __RPC_FAR * This,
    /* [in] */ BITMAPINFOHEADER __RPC_FAR *imageHeader,
    /* [in] */ EPlayFrameType pixelFormat,
    /* [in] */ BYTE __RPC_FAR *pixelData,
    /* [in] */ DWORD pixelDataSize,
    /* [in] */ BOOL DefaultHeader);


void __RPC_STUB IGXIntBitmap2_AttachSpace_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IGXIntBitmap2_BuildPreProcessCtrl_Proxy( 
    IGXIntBitmap2 __RPC_FAR * This,
    /* [in] */ SPlayBitMap __RPC_FAR *spbmp,
    /* [in] */ EPlayFrameType format,
    /* [in] */ void __RPC_FAR *hdr,
    /* [out] */ void __RPC_FAR *__RPC_FAR *pre);


void __RPC_STUB IGXIntBitmap2_BuildPreProcessCtrl_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IGXIntBitmap2_GetPreProcessPalette_Proxy( 
    IGXIntBitmap2 __RPC_FAR * This,
    /* [in] */ void __RPC_FAR *pre,
    /* [out] */ void __RPC_FAR *__RPC_FAR *pal);


void __RPC_STUB IGXIntBitmap2_GetPreProcessPalette_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IGXIntBitmap2_CopyToClipboard_Proxy( 
    IGXIntBitmap2 __RPC_FAR * This);


void __RPC_STUB IGXIntBitmap2_CopyToClipboard_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IGXIntBitmap2_CopyFromClipboard_Proxy( 
    IGXIntBitmap2 __RPC_FAR * This);


void __RPC_STUB IGXIntBitmap2_CopyFromClipboard_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IGXIntBitmap2_ValidBitmapOnClipboard_Proxy( 
    IGXIntBitmap2 __RPC_FAR * This,
    ClipboardType __RPC_FAR *Flag);


void __RPC_STUB IGXIntBitmap2_ValidBitmapOnClipboard_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IGXIntBitmap2_SetImageOptions_Proxy( 
    IGXIntBitmap2 __RPC_FAR * This,
    /* [in] */ PlayXlatorOpt __RPC_FAR *Opt);


void __RPC_STUB IGXIntBitmap2_SetImageOptions_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IGXIntBitmap2_SetAttr_Proxy( 
    IGXIntBitmap2 __RPC_FAR * This,
    /* [in] */ InfoAttribute Attr,
    /* [in] */ AttributeVar __RPC_FAR *Value);


void __RPC_STUB IGXIntBitmap2_SetAttr_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IGXIntBitmap2_GetAttr_Proxy( 
    IGXIntBitmap2 __RPC_FAR * This,
    /* [in] */ InfoAttribute Attr,
    /* [out] */ AttributeVar __RPC_FAR *Value);


void __RPC_STUB IGXIntBitmap2_GetAttr_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IGXIntBitmap2_INTERFACE_DEFINED__ */


#ifndef __IGXBasicImageProcess_INTERFACE_DEFINED__
#define __IGXBasicImageProcess_INTERFACE_DEFINED__

/****************************************
 * Generated header for interface: IGXBasicImageProcess
 * at Tue Nov 23 05:02:08 1999
 * using MIDL 3.01.75
 ****************************************/
/* [local][uuid][object] */ 



EXTERN_C const IID IID_IGXBasicImageProcess;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    interface DECLSPEC_UUID("8335e5f8-ab3b-11ce-8468-0000b468276b")
    IGXBasicImageProcess : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE InsertAlpha( 
            /* [in] */ IGXIntBitmap __RPC_FAR *RGBABmp,
            /* [in] */ IGXIntBitmap __RPC_FAR *Alpha) = 0;
        
        virtual void STDMETHODCALLTYPE Convert2YUV( 
            BYTE __RPC_FAR *dest,
            BOOL destAlpha,
            BYTE __RPC_FAR *source,
            BOOL sourceAlpha,
            int w) = 0;
        
        virtual void STDMETHODCALLTYPE Convert2RGB( 
            BYTE __RPC_FAR *dest,
            BOOL destAlpha,
            BYTE __RPC_FAR *source,
            BOOL sourceAlpha,
            int w) = 0;
        
        virtual void STDMETHODCALLTYPE PaletteRGB2YUV( 
            BYTE __RPC_FAR *source,
            BYTE __RPC_FAR *dest,
            DWORD width) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IGXBasicImageProcessVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            IGXBasicImageProcess __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            IGXBasicImageProcess __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            IGXBasicImageProcess __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *InsertAlpha )( 
            IGXBasicImageProcess __RPC_FAR * This,
            /* [in] */ IGXIntBitmap __RPC_FAR *RGBABmp,
            /* [in] */ IGXIntBitmap __RPC_FAR *Alpha);
        
        void ( STDMETHODCALLTYPE __RPC_FAR *Convert2YUV )( 
            IGXBasicImageProcess __RPC_FAR * This,
            BYTE __RPC_FAR *dest,
            BOOL destAlpha,
            BYTE __RPC_FAR *source,
            BOOL sourceAlpha,
            int w);
        
        void ( STDMETHODCALLTYPE __RPC_FAR *Convert2RGB )( 
            IGXBasicImageProcess __RPC_FAR * This,
            BYTE __RPC_FAR *dest,
            BOOL destAlpha,
            BYTE __RPC_FAR *source,
            BOOL sourceAlpha,
            int w);
        
        void ( STDMETHODCALLTYPE __RPC_FAR *PaletteRGB2YUV )( 
            IGXBasicImageProcess __RPC_FAR * This,
            BYTE __RPC_FAR *source,
            BYTE __RPC_FAR *dest,
            DWORD width);
        
        END_INTERFACE
    } IGXBasicImageProcessVtbl;

    interface IGXBasicImageProcess
    {
        CONST_VTBL struct IGXBasicImageProcessVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IGXBasicImageProcess_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IGXBasicImageProcess_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IGXBasicImageProcess_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IGXBasicImageProcess_InsertAlpha(This,RGBABmp,Alpha)	\
    (This)->lpVtbl -> InsertAlpha(This,RGBABmp,Alpha)

#define IGXBasicImageProcess_Convert2YUV(This,dest,destAlpha,source,sourceAlpha,w)	\
    (This)->lpVtbl -> Convert2YUV(This,dest,destAlpha,source,sourceAlpha,w)

#define IGXBasicImageProcess_Convert2RGB(This,dest,destAlpha,source,sourceAlpha,w)	\
    (This)->lpVtbl -> Convert2RGB(This,dest,destAlpha,source,sourceAlpha,w)

#define IGXBasicImageProcess_PaletteRGB2YUV(This,source,dest,width)	\
    (This)->lpVtbl -> PaletteRGB2YUV(This,source,dest,width)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE IGXBasicImageProcess_InsertAlpha_Proxy( 
    IGXBasicImageProcess __RPC_FAR * This,
    /* [in] */ IGXIntBitmap __RPC_FAR *RGBABmp,
    /* [in] */ IGXIntBitmap __RPC_FAR *Alpha);


void __RPC_STUB IGXBasicImageProcess_InsertAlpha_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


void STDMETHODCALLTYPE IGXBasicImageProcess_Convert2YUV_Proxy( 
    IGXBasicImageProcess __RPC_FAR * This,
    BYTE __RPC_FAR *dest,
    BOOL destAlpha,
    BYTE __RPC_FAR *source,
    BOOL sourceAlpha,
    int w);


void __RPC_STUB IGXBasicImageProcess_Convert2YUV_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


void STDMETHODCALLTYPE IGXBasicImageProcess_Convert2RGB_Proxy( 
    IGXBasicImageProcess __RPC_FAR * This,
    BYTE __RPC_FAR *dest,
    BOOL destAlpha,
    BYTE __RPC_FAR *source,
    BOOL sourceAlpha,
    int w);


void __RPC_STUB IGXBasicImageProcess_Convert2RGB_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


void STDMETHODCALLTYPE IGXBasicImageProcess_PaletteRGB2YUV_Proxy( 
    IGXBasicImageProcess __RPC_FAR * This,
    BYTE __RPC_FAR *source,
    BYTE __RPC_FAR *dest,
    DWORD width);


void __RPC_STUB IGXBasicImageProcess_PaletteRGB2YUV_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IGXBasicImageProcess_INTERFACE_DEFINED__ */


#ifndef __IGXBasicImageProcess2_INTERFACE_DEFINED__
#define __IGXBasicImageProcess2_INTERFACE_DEFINED__

/****************************************
 * Generated header for interface: IGXBasicImageProcess2
 * at Tue Nov 23 05:02:08 1999
 * using MIDL 3.01.75
 ****************************************/
/* [local][uuid][object] */ 



EXTERN_C const IID IID_IGXBasicImageProcess2;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    interface DECLSPEC_UUID("8335e60a-ab3b-11ce-8468-0000b468276b")
    IGXBasicImageProcess2 : public IGXBasicImageProcess
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE ShrinkRGB24( 
            IGXIntBitmap __RPC_FAR *origBmp,
            IGXIntBitmap __RPC_FAR *__RPC_FAR *dstBmp,
            WORD width,
            WORD height) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IGXBasicImageProcess2Vtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            IGXBasicImageProcess2 __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            IGXBasicImageProcess2 __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            IGXBasicImageProcess2 __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *InsertAlpha )( 
            IGXBasicImageProcess2 __RPC_FAR * This,
            /* [in] */ IGXIntBitmap __RPC_FAR *RGBABmp,
            /* [in] */ IGXIntBitmap __RPC_FAR *Alpha);
        
        void ( STDMETHODCALLTYPE __RPC_FAR *Convert2YUV )( 
            IGXBasicImageProcess2 __RPC_FAR * This,
            BYTE __RPC_FAR *dest,
            BOOL destAlpha,
            BYTE __RPC_FAR *source,
            BOOL sourceAlpha,
            int w);
        
        void ( STDMETHODCALLTYPE __RPC_FAR *Convert2RGB )( 
            IGXBasicImageProcess2 __RPC_FAR * This,
            BYTE __RPC_FAR *dest,
            BOOL destAlpha,
            BYTE __RPC_FAR *source,
            BOOL sourceAlpha,
            int w);
        
        void ( STDMETHODCALLTYPE __RPC_FAR *PaletteRGB2YUV )( 
            IGXBasicImageProcess2 __RPC_FAR * This,
            BYTE __RPC_FAR *source,
            BYTE __RPC_FAR *dest,
            DWORD width);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *ShrinkRGB24 )( 
            IGXBasicImageProcess2 __RPC_FAR * This,
            IGXIntBitmap __RPC_FAR *origBmp,
            IGXIntBitmap __RPC_FAR *__RPC_FAR *dstBmp,
            WORD width,
            WORD height);
        
        END_INTERFACE
    } IGXBasicImageProcess2Vtbl;

    interface IGXBasicImageProcess2
    {
        CONST_VTBL struct IGXBasicImageProcess2Vtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IGXBasicImageProcess2_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IGXBasicImageProcess2_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IGXBasicImageProcess2_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IGXBasicImageProcess2_InsertAlpha(This,RGBABmp,Alpha)	\
    (This)->lpVtbl -> InsertAlpha(This,RGBABmp,Alpha)

#define IGXBasicImageProcess2_Convert2YUV(This,dest,destAlpha,source,sourceAlpha,w)	\
    (This)->lpVtbl -> Convert2YUV(This,dest,destAlpha,source,sourceAlpha,w)

#define IGXBasicImageProcess2_Convert2RGB(This,dest,destAlpha,source,sourceAlpha,w)	\
    (This)->lpVtbl -> Convert2RGB(This,dest,destAlpha,source,sourceAlpha,w)

#define IGXBasicImageProcess2_PaletteRGB2YUV(This,source,dest,width)	\
    (This)->lpVtbl -> PaletteRGB2YUV(This,source,dest,width)


#define IGXBasicImageProcess2_ShrinkRGB24(This,origBmp,dstBmp,width,height)	\
    (This)->lpVtbl -> ShrinkRGB24(This,origBmp,dstBmp,width,height)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE IGXBasicImageProcess2_ShrinkRGB24_Proxy( 
    IGXBasicImageProcess2 __RPC_FAR * This,
    IGXIntBitmap __RPC_FAR *origBmp,
    IGXIntBitmap __RPC_FAR *__RPC_FAR *dstBmp,
    WORD width,
    WORD height);


void __RPC_STUB IGXBasicImageProcess2_ShrinkRGB24_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IGXBasicImageProcess2_INTERFACE_DEFINED__ */


#ifndef __IGXBasicImageProcess3_INTERFACE_DEFINED__
#define __IGXBasicImageProcess3_INTERFACE_DEFINED__

/****************************************
 * Generated header for interface: IGXBasicImageProcess3
 * at Tue Nov 23 05:02:08 1999
 * using MIDL 3.01.75
 ****************************************/
/* [local][uuid][object] */ 



EXTERN_C const IID IID_IGXBasicImageProcess3;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    interface DECLSPEC_UUID("8335e6a7-ab3b-11ce-8468-0000b468276b")
    IGXBasicImageProcess3 : public IGXBasicImageProcess2
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE FieldFreeze( 
            IGXIntBitmap __RPC_FAR *srcBmp,
            IGXIntBitmap __RPC_FAR *__RPC_FAR *dstBmp,
            BYTE Field) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IGXBasicImageProcess3Vtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            IGXBasicImageProcess3 __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            IGXBasicImageProcess3 __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            IGXBasicImageProcess3 __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *InsertAlpha )( 
            IGXBasicImageProcess3 __RPC_FAR * This,
            /* [in] */ IGXIntBitmap __RPC_FAR *RGBABmp,
            /* [in] */ IGXIntBitmap __RPC_FAR *Alpha);
        
        void ( STDMETHODCALLTYPE __RPC_FAR *Convert2YUV )( 
            IGXBasicImageProcess3 __RPC_FAR * This,
            BYTE __RPC_FAR *dest,
            BOOL destAlpha,
            BYTE __RPC_FAR *source,
            BOOL sourceAlpha,
            int w);
        
        void ( STDMETHODCALLTYPE __RPC_FAR *Convert2RGB )( 
            IGXBasicImageProcess3 __RPC_FAR * This,
            BYTE __RPC_FAR *dest,
            BOOL destAlpha,
            BYTE __RPC_FAR *source,
            BOOL sourceAlpha,
            int w);
        
        void ( STDMETHODCALLTYPE __RPC_FAR *PaletteRGB2YUV )( 
            IGXBasicImageProcess3 __RPC_FAR * This,
            BYTE __RPC_FAR *source,
            BYTE __RPC_FAR *dest,
            DWORD width);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *ShrinkRGB24 )( 
            IGXBasicImageProcess3 __RPC_FAR * This,
            IGXIntBitmap __RPC_FAR *origBmp,
            IGXIntBitmap __RPC_FAR *__RPC_FAR *dstBmp,
            WORD width,
            WORD height);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *FieldFreeze )( 
            IGXBasicImageProcess3 __RPC_FAR * This,
            IGXIntBitmap __RPC_FAR *srcBmp,
            IGXIntBitmap __RPC_FAR *__RPC_FAR *dstBmp,
            BYTE Field);
        
        END_INTERFACE
    } IGXBasicImageProcess3Vtbl;

    interface IGXBasicImageProcess3
    {
        CONST_VTBL struct IGXBasicImageProcess3Vtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IGXBasicImageProcess3_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IGXBasicImageProcess3_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IGXBasicImageProcess3_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IGXBasicImageProcess3_InsertAlpha(This,RGBABmp,Alpha)	\
    (This)->lpVtbl -> InsertAlpha(This,RGBABmp,Alpha)

#define IGXBasicImageProcess3_Convert2YUV(This,dest,destAlpha,source,sourceAlpha,w)	\
    (This)->lpVtbl -> Convert2YUV(This,dest,destAlpha,source,sourceAlpha,w)

#define IGXBasicImageProcess3_Convert2RGB(This,dest,destAlpha,source,sourceAlpha,w)	\
    (This)->lpVtbl -> Convert2RGB(This,dest,destAlpha,source,sourceAlpha,w)

#define IGXBasicImageProcess3_PaletteRGB2YUV(This,source,dest,width)	\
    (This)->lpVtbl -> PaletteRGB2YUV(This,source,dest,width)


#define IGXBasicImageProcess3_ShrinkRGB24(This,origBmp,dstBmp,width,height)	\
    (This)->lpVtbl -> ShrinkRGB24(This,origBmp,dstBmp,width,height)


#define IGXBasicImageProcess3_FieldFreeze(This,srcBmp,dstBmp,Field)	\
    (This)->lpVtbl -> FieldFreeze(This,srcBmp,dstBmp,Field)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE IGXBasicImageProcess3_FieldFreeze_Proxy( 
    IGXBasicImageProcess3 __RPC_FAR * This,
    IGXIntBitmap __RPC_FAR *srcBmp,
    IGXIntBitmap __RPC_FAR *__RPC_FAR *dstBmp,
    BYTE Field);


void __RPC_STUB IGXBasicImageProcess3_FieldFreeze_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IGXBasicImageProcess3_INTERFACE_DEFINED__ */


#ifndef __IGXBasicImageProcess4_INTERFACE_DEFINED__
#define __IGXBasicImageProcess4_INTERFACE_DEFINED__

/****************************************
 * Generated header for interface: IGXBasicImageProcess4
 * at Tue Nov 23 05:02:08 1999
 * using MIDL 3.01.75
 ****************************************/
/* [local][uuid][object] */ 


typedef 
enum tagScaleType
    {	ST_DEFAULT_SCALE	= 0,
	ST_ASPECT	= 1,
	ST_FILTER	= 2
    }	ScaleType;


EXTERN_C const IID IID_IGXBasicImageProcess4;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    interface DECLSPEC_UUID("8335e6a6-ab3b-11ce-8468-0000b468276b")
    IGXBasicImageProcess4 : public IGXBasicImageProcess3
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE Scale( 
            /* [in] */ IGXIntBitmap __RPC_FAR *srcBmp,
            /* [out] */ IGXIntBitmap __RPC_FAR *__RPC_FAR *dstBmp,
            /* [in] */ DWORD Width,
            /* [in] */ DWORD Height,
            /* [in] */ ScaleType Flags) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IGXBasicImageProcess4Vtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            IGXBasicImageProcess4 __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            IGXBasicImageProcess4 __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            IGXBasicImageProcess4 __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *InsertAlpha )( 
            IGXBasicImageProcess4 __RPC_FAR * This,
            /* [in] */ IGXIntBitmap __RPC_FAR *RGBABmp,
            /* [in] */ IGXIntBitmap __RPC_FAR *Alpha);
        
        void ( STDMETHODCALLTYPE __RPC_FAR *Convert2YUV )( 
            IGXBasicImageProcess4 __RPC_FAR * This,
            BYTE __RPC_FAR *dest,
            BOOL destAlpha,
            BYTE __RPC_FAR *source,
            BOOL sourceAlpha,
            int w);
        
        void ( STDMETHODCALLTYPE __RPC_FAR *Convert2RGB )( 
            IGXBasicImageProcess4 __RPC_FAR * This,
            BYTE __RPC_FAR *dest,
            BOOL destAlpha,
            BYTE __RPC_FAR *source,
            BOOL sourceAlpha,
            int w);
        
        void ( STDMETHODCALLTYPE __RPC_FAR *PaletteRGB2YUV )( 
            IGXBasicImageProcess4 __RPC_FAR * This,
            BYTE __RPC_FAR *source,
            BYTE __RPC_FAR *dest,
            DWORD width);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *ShrinkRGB24 )( 
            IGXBasicImageProcess4 __RPC_FAR * This,
            IGXIntBitmap __RPC_FAR *origBmp,
            IGXIntBitmap __RPC_FAR *__RPC_FAR *dstBmp,
            WORD width,
            WORD height);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *FieldFreeze )( 
            IGXBasicImageProcess4 __RPC_FAR * This,
            IGXIntBitmap __RPC_FAR *srcBmp,
            IGXIntBitmap __RPC_FAR *__RPC_FAR *dstBmp,
            BYTE Field);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Scale )( 
            IGXBasicImageProcess4 __RPC_FAR * This,
            /* [in] */ IGXIntBitmap __RPC_FAR *srcBmp,
            /* [out] */ IGXIntBitmap __RPC_FAR *__RPC_FAR *dstBmp,
            /* [in] */ DWORD Width,
            /* [in] */ DWORD Height,
            /* [in] */ ScaleType Flags);
        
        END_INTERFACE
    } IGXBasicImageProcess4Vtbl;

    interface IGXBasicImageProcess4
    {
        CONST_VTBL struct IGXBasicImageProcess4Vtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IGXBasicImageProcess4_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IGXBasicImageProcess4_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IGXBasicImageProcess4_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IGXBasicImageProcess4_InsertAlpha(This,RGBABmp,Alpha)	\
    (This)->lpVtbl -> InsertAlpha(This,RGBABmp,Alpha)

#define IGXBasicImageProcess4_Convert2YUV(This,dest,destAlpha,source,sourceAlpha,w)	\
    (This)->lpVtbl -> Convert2YUV(This,dest,destAlpha,source,sourceAlpha,w)

#define IGXBasicImageProcess4_Convert2RGB(This,dest,destAlpha,source,sourceAlpha,w)	\
    (This)->lpVtbl -> Convert2RGB(This,dest,destAlpha,source,sourceAlpha,w)

#define IGXBasicImageProcess4_PaletteRGB2YUV(This,source,dest,width)	\
    (This)->lpVtbl -> PaletteRGB2YUV(This,source,dest,width)


#define IGXBasicImageProcess4_ShrinkRGB24(This,origBmp,dstBmp,width,height)	\
    (This)->lpVtbl -> ShrinkRGB24(This,origBmp,dstBmp,width,height)


#define IGXBasicImageProcess4_FieldFreeze(This,srcBmp,dstBmp,Field)	\
    (This)->lpVtbl -> FieldFreeze(This,srcBmp,dstBmp,Field)


#define IGXBasicImageProcess4_Scale(This,srcBmp,dstBmp,Width,Height,Flags)	\
    (This)->lpVtbl -> Scale(This,srcBmp,dstBmp,Width,Height,Flags)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE IGXBasicImageProcess4_Scale_Proxy( 
    IGXBasicImageProcess4 __RPC_FAR * This,
    /* [in] */ IGXIntBitmap __RPC_FAR *srcBmp,
    /* [out] */ IGXIntBitmap __RPC_FAR *__RPC_FAR *dstBmp,
    /* [in] */ DWORD Width,
    /* [in] */ DWORD Height,
    /* [in] */ ScaleType Flags);


void __RPC_STUB IGXBasicImageProcess4_Scale_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IGXBasicImageProcess4_INTERFACE_DEFINED__ */


#ifndef __IGXBasicImageProcess5_INTERFACE_DEFINED__
#define __IGXBasicImageProcess5_INTERFACE_DEFINED__

/****************************************
 * Generated header for interface: IGXBasicImageProcess5
 * at Tue Nov 23 05:02:08 1999
 * using MIDL 3.01.75
 ****************************************/
/* [local][uuid][object] */ 



EXTERN_C const IID IID_IGXBasicImageProcess5;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    interface DECLSPEC_UUID("8335e6c3-ab3b-11ce-8468-0000b468276b")
    IGXBasicImageProcess5 : public IGXBasicImageProcess4
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE SetImageOptions( 
            /* [in] */ PlayXlatorOpt __RPC_FAR *Opt) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Scale( 
            /* [in] */ IGXIntBitmap2 __RPC_FAR *srcBmp,
            /* [out] */ IGXIntBitmap2 __RPC_FAR *__RPC_FAR *dstBmp,
            /* [in] */ DWORD Width,
            /* [in] */ DWORD Height,
            /* [in] */ ScaleType Flags) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Overlay( 
            /* [in] */ IGXIntBitmap2 __RPC_FAR *BottomBmp,
            /* [in] */ IGXIntBitmap2 __RPC_FAR *TopBmp) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IGXBasicImageProcess5Vtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            IGXBasicImageProcess5 __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            IGXBasicImageProcess5 __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            IGXBasicImageProcess5 __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *InsertAlpha )( 
            IGXBasicImageProcess5 __RPC_FAR * This,
            /* [in] */ IGXIntBitmap __RPC_FAR *RGBABmp,
            /* [in] */ IGXIntBitmap __RPC_FAR *Alpha);
        
        void ( STDMETHODCALLTYPE __RPC_FAR *Convert2YUV )( 
            IGXBasicImageProcess5 __RPC_FAR * This,
            BYTE __RPC_FAR *dest,
            BOOL destAlpha,
            BYTE __RPC_FAR *source,
            BOOL sourceAlpha,
            int w);
        
        void ( STDMETHODCALLTYPE __RPC_FAR *Convert2RGB )( 
            IGXBasicImageProcess5 __RPC_FAR * This,
            BYTE __RPC_FAR *dest,
            BOOL destAlpha,
            BYTE __RPC_FAR *source,
            BOOL sourceAlpha,
            int w);
        
        void ( STDMETHODCALLTYPE __RPC_FAR *PaletteRGB2YUV )( 
            IGXBasicImageProcess5 __RPC_FAR * This,
            BYTE __RPC_FAR *source,
            BYTE __RPC_FAR *dest,
            DWORD width);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *ShrinkRGB24 )( 
            IGXBasicImageProcess5 __RPC_FAR * This,
            IGXIntBitmap __RPC_FAR *origBmp,
            IGXIntBitmap __RPC_FAR *__RPC_FAR *dstBmp,
            WORD width,
            WORD height);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *FieldFreeze )( 
            IGXBasicImageProcess5 __RPC_FAR * This,
            IGXIntBitmap __RPC_FAR *srcBmp,
            IGXIntBitmap __RPC_FAR *__RPC_FAR *dstBmp,
            BYTE Field);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Scale )( 
            IGXBasicImageProcess5 __RPC_FAR * This,
            /* [in] */ IGXIntBitmap __RPC_FAR *srcBmp,
            /* [out] */ IGXIntBitmap __RPC_FAR *__RPC_FAR *dstBmp,
            /* [in] */ DWORD Width,
            /* [in] */ DWORD Height,
            /* [in] */ ScaleType Flags);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetImageOptions )( 
            IGXBasicImageProcess5 __RPC_FAR * This,
            /* [in] */ PlayXlatorOpt __RPC_FAR *Opt);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Scale )( 
            IGXBasicImageProcess5 __RPC_FAR * This,
            /* [in] */ IGXIntBitmap2 __RPC_FAR *srcBmp,
            /* [out] */ IGXIntBitmap2 __RPC_FAR *__RPC_FAR *dstBmp,
            /* [in] */ DWORD Width,
            /* [in] */ DWORD Height,
            /* [in] */ ScaleType Flags);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Overlay )( 
            IGXBasicImageProcess5 __RPC_FAR * This,
            /* [in] */ IGXIntBitmap2 __RPC_FAR *BottomBmp,
            /* [in] */ IGXIntBitmap2 __RPC_FAR *TopBmp);
        
        END_INTERFACE
    } IGXBasicImageProcess5Vtbl;

    interface IGXBasicImageProcess5
    {
        CONST_VTBL struct IGXBasicImageProcess5Vtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IGXBasicImageProcess5_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IGXBasicImageProcess5_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IGXBasicImageProcess5_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IGXBasicImageProcess5_InsertAlpha(This,RGBABmp,Alpha)	\
    (This)->lpVtbl -> InsertAlpha(This,RGBABmp,Alpha)

#define IGXBasicImageProcess5_Convert2YUV(This,dest,destAlpha,source,sourceAlpha,w)	\
    (This)->lpVtbl -> Convert2YUV(This,dest,destAlpha,source,sourceAlpha,w)

#define IGXBasicImageProcess5_Convert2RGB(This,dest,destAlpha,source,sourceAlpha,w)	\
    (This)->lpVtbl -> Convert2RGB(This,dest,destAlpha,source,sourceAlpha,w)

#define IGXBasicImageProcess5_PaletteRGB2YUV(This,source,dest,width)	\
    (This)->lpVtbl -> PaletteRGB2YUV(This,source,dest,width)


#define IGXBasicImageProcess5_ShrinkRGB24(This,origBmp,dstBmp,width,height)	\
    (This)->lpVtbl -> ShrinkRGB24(This,origBmp,dstBmp,width,height)


#define IGXBasicImageProcess5_FieldFreeze(This,srcBmp,dstBmp,Field)	\
    (This)->lpVtbl -> FieldFreeze(This,srcBmp,dstBmp,Field)


#define IGXBasicImageProcess5_Scale(This,srcBmp,dstBmp,Width,Height,Flags)	\
    (This)->lpVtbl -> Scale(This,srcBmp,dstBmp,Width,Height,Flags)


#define IGXBasicImageProcess5_SetImageOptions(This,Opt)	\
    (This)->lpVtbl -> SetImageOptions(This,Opt)

#define IGXBasicImageProcess5_Scale(This,srcBmp,dstBmp,Width,Height,Flags)	\
    (This)->lpVtbl -> Scale(This,srcBmp,dstBmp,Width,Height,Flags)

#define IGXBasicImageProcess5_Overlay(This,BottomBmp,TopBmp)	\
    (This)->lpVtbl -> Overlay(This,BottomBmp,TopBmp)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE IGXBasicImageProcess5_SetImageOptions_Proxy( 
    IGXBasicImageProcess5 __RPC_FAR * This,
    /* [in] */ PlayXlatorOpt __RPC_FAR *Opt);


void __RPC_STUB IGXBasicImageProcess5_SetImageOptions_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IGXBasicImageProcess5_Scale_Proxy( 
    IGXBasicImageProcess5 __RPC_FAR * This,
    /* [in] */ IGXIntBitmap2 __RPC_FAR *srcBmp,
    /* [out] */ IGXIntBitmap2 __RPC_FAR *__RPC_FAR *dstBmp,
    /* [in] */ DWORD Width,
    /* [in] */ DWORD Height,
    /* [in] */ ScaleType Flags);


void __RPC_STUB IGXBasicImageProcess5_Scale_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IGXBasicImageProcess5_Overlay_Proxy( 
    IGXBasicImageProcess5 __RPC_FAR * This,
    /* [in] */ IGXIntBitmap2 __RPC_FAR *BottomBmp,
    /* [in] */ IGXIntBitmap2 __RPC_FAR *TopBmp);


void __RPC_STUB IGXBasicImageProcess5_Overlay_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IGXBasicImageProcess5_INTERFACE_DEFINED__ */


#ifndef __IGXMovie_INTERFACE_DEFINED__
#define __IGXMovie_INTERFACE_DEFINED__

/****************************************
 * Generated header for interface: IGXMovie
 * at Tue Nov 23 05:02:08 1999
 * using MIDL 3.01.75
 ****************************************/
/* [local][uuid][object] */ 



EXTERN_C const IID IID_IGXMovie;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    interface DECLSPEC_UUID("3cbaa060-0ffd-11d0-98bc-002018311f37")
    IGXMovie : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE GetImageHolder( 
            /* [out] */ IGXIntBitmap __RPC_FAR *__RPC_FAR *pIBmp) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE UncompressFile( 
            /* [in] */ unsigned char __RPC_FAR *pszDest,
            /* [in] */ unsigned char __RPC_FAR *pszSource,
            /* [in] */ IGXProgressAdviseSink __RPC_FAR *progress) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE CompressFile( 
            /* [in] */ unsigned char __RPC_FAR *pszDest,
            /* [in] */ unsigned char __RPC_FAR *pszSource,
            /* [in] */ IGXProgressAdviseSink __RPC_FAR *progress) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE CompressFileWithAudio( 
            /* [in] */ unsigned char __RPC_FAR *pszDest,
            /* [in] */ unsigned char __RPC_FAR *pszSource,
            /* [in] */ unsigned char __RPC_FAR *pszSourceAudio,
            /* [in] */ IGXProgressAdviseSink __RPC_FAR *progress) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IGXMovieVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            IGXMovie __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            IGXMovie __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            IGXMovie __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetImageHolder )( 
            IGXMovie __RPC_FAR * This,
            /* [out] */ IGXIntBitmap __RPC_FAR *__RPC_FAR *pIBmp);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *UncompressFile )( 
            IGXMovie __RPC_FAR * This,
            /* [in] */ unsigned char __RPC_FAR *pszDest,
            /* [in] */ unsigned char __RPC_FAR *pszSource,
            /* [in] */ IGXProgressAdviseSink __RPC_FAR *progress);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *CompressFile )( 
            IGXMovie __RPC_FAR * This,
            /* [in] */ unsigned char __RPC_FAR *pszDest,
            /* [in] */ unsigned char __RPC_FAR *pszSource,
            /* [in] */ IGXProgressAdviseSink __RPC_FAR *progress);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *CompressFileWithAudio )( 
            IGXMovie __RPC_FAR * This,
            /* [in] */ unsigned char __RPC_FAR *pszDest,
            /* [in] */ unsigned char __RPC_FAR *pszSource,
            /* [in] */ unsigned char __RPC_FAR *pszSourceAudio,
            /* [in] */ IGXProgressAdviseSink __RPC_FAR *progress);
        
        END_INTERFACE
    } IGXMovieVtbl;

    interface IGXMovie
    {
        CONST_VTBL struct IGXMovieVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IGXMovie_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IGXMovie_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IGXMovie_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IGXMovie_GetImageHolder(This,pIBmp)	\
    (This)->lpVtbl -> GetImageHolder(This,pIBmp)

#define IGXMovie_UncompressFile(This,pszDest,pszSource,progress)	\
    (This)->lpVtbl -> UncompressFile(This,pszDest,pszSource,progress)

#define IGXMovie_CompressFile(This,pszDest,pszSource,progress)	\
    (This)->lpVtbl -> CompressFile(This,pszDest,pszSource,progress)

#define IGXMovie_CompressFileWithAudio(This,pszDest,pszSource,pszSourceAudio,progress)	\
    (This)->lpVtbl -> CompressFileWithAudio(This,pszDest,pszSource,pszSourceAudio,progress)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE IGXMovie_GetImageHolder_Proxy( 
    IGXMovie __RPC_FAR * This,
    /* [out] */ IGXIntBitmap __RPC_FAR *__RPC_FAR *pIBmp);


void __RPC_STUB IGXMovie_GetImageHolder_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IGXMovie_UncompressFile_Proxy( 
    IGXMovie __RPC_FAR * This,
    /* [in] */ unsigned char __RPC_FAR *pszDest,
    /* [in] */ unsigned char __RPC_FAR *pszSource,
    /* [in] */ IGXProgressAdviseSink __RPC_FAR *progress);


void __RPC_STUB IGXMovie_UncompressFile_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IGXMovie_CompressFile_Proxy( 
    IGXMovie __RPC_FAR * This,
    /* [in] */ unsigned char __RPC_FAR *pszDest,
    /* [in] */ unsigned char __RPC_FAR *pszSource,
    /* [in] */ IGXProgressAdviseSink __RPC_FAR *progress);


void __RPC_STUB IGXMovie_CompressFile_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IGXMovie_CompressFileWithAudio_Proxy( 
    IGXMovie __RPC_FAR * This,
    /* [in] */ unsigned char __RPC_FAR *pszDest,
    /* [in] */ unsigned char __RPC_FAR *pszSource,
    /* [in] */ unsigned char __RPC_FAR *pszSourceAudio,
    /* [in] */ IGXProgressAdviseSink __RPC_FAR *progress);


void __RPC_STUB IGXMovie_CompressFileWithAudio_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IGXMovie_INTERFACE_DEFINED__ */


#ifndef __IGXMovieAudio_INTERFACE_DEFINED__
#define __IGXMovieAudio_INTERFACE_DEFINED__

/****************************************
 * Generated header for interface: IGXMovieAudio
 * at Tue Nov 23 05:02:08 1999
 * using MIDL 3.01.75
 ****************************************/
/* [local][uuid][object] */ 



EXTERN_C const IID IID_IGXMovieAudio;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    interface DECLSPEC_UUID("8335e6c4-ab3b-11ce-8468-0000b468276b")
    IGXMovieAudio : public IUnknown
    {
    public:
    };
    
#else 	/* C style interface */

    typedef struct IGXMovieAudioVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            IGXMovieAudio __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            IGXMovieAudio __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            IGXMovieAudio __RPC_FAR * This);
        
        END_INTERFACE
    } IGXMovieAudioVtbl;

    interface IGXMovieAudio
    {
        CONST_VTBL struct IGXMovieAudioVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IGXMovieAudio_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IGXMovieAudio_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IGXMovieAudio_Release(This)	\
    (This)->lpVtbl -> Release(This)


#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IGXMovieAudio_INTERFACE_DEFINED__ */


#ifndef __IGXLateUtils_INTERFACE_DEFINED__
#define __IGXLateUtils_INTERFACE_DEFINED__

/****************************************
 * Generated header for interface: IGXLateUtils
 * at Tue Nov 23 05:02:08 1999
 * using MIDL 3.01.75
 ****************************************/
/* [local][uuid][object] */ 



EXTERN_C const IID IID_IGXLateUtils;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    interface DECLSPEC_UUID("8335e6be-ab3b-11ce-8468-0000b468276b")
    IGXLateUtils : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE IsMMX( 
            /* [out] */ BOOL __RPC_FAR *MMX) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetSqnceFileName( 
            /* [in][string] */ LPTSTR Filename,
            /* [out] */ DWORD __RPC_FAR *step) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetNumberSqnceSteps( 
            /* [out] */ DWORD __RPC_FAR *Steps) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetSqnceFileName( 
            /* [in] */ DWORD step,
            /* [out][string] */ LPTSTR __RPC_FAR *Filename) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetFileMatchOptions( 
            /* [in] */ FileNameMatchOptions __RPC_FAR *Opt) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE EnumerateBitDepths( 
            /* [out] */ BitDepthEnum __RPC_FAR *__RPC_FAR *BitDepthList,
            /* [out] */ DWORD __RPC_FAR *Count,
            /* [out] */ DWORD __RPC_FAR *LongestLen) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IGXLateUtilsVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            IGXLateUtils __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            IGXLateUtils __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            IGXLateUtils __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *IsMMX )( 
            IGXLateUtils __RPC_FAR * This,
            /* [out] */ BOOL __RPC_FAR *MMX);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetSqnceFileName )( 
            IGXLateUtils __RPC_FAR * This,
            /* [in][string] */ LPTSTR Filename,
            /* [out] */ DWORD __RPC_FAR *step);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetNumberSqnceSteps )( 
            IGXLateUtils __RPC_FAR * This,
            /* [out] */ DWORD __RPC_FAR *Steps);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetSqnceFileName )( 
            IGXLateUtils __RPC_FAR * This,
            /* [in] */ DWORD step,
            /* [out][string] */ LPTSTR __RPC_FAR *Filename);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetFileMatchOptions )( 
            IGXLateUtils __RPC_FAR * This,
            /* [in] */ FileNameMatchOptions __RPC_FAR *Opt);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *EnumerateBitDepths )( 
            IGXLateUtils __RPC_FAR * This,
            /* [out] */ BitDepthEnum __RPC_FAR *__RPC_FAR *BitDepthList,
            /* [out] */ DWORD __RPC_FAR *Count,
            /* [out] */ DWORD __RPC_FAR *LongestLen);
        
        END_INTERFACE
    } IGXLateUtilsVtbl;

    interface IGXLateUtils
    {
        CONST_VTBL struct IGXLateUtilsVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IGXLateUtils_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IGXLateUtils_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IGXLateUtils_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IGXLateUtils_IsMMX(This,MMX)	\
    (This)->lpVtbl -> IsMMX(This,MMX)

#define IGXLateUtils_SetSqnceFileName(This,Filename,step)	\
    (This)->lpVtbl -> SetSqnceFileName(This,Filename,step)

#define IGXLateUtils_GetNumberSqnceSteps(This,Steps)	\
    (This)->lpVtbl -> GetNumberSqnceSteps(This,Steps)

#define IGXLateUtils_GetSqnceFileName(This,step,Filename)	\
    (This)->lpVtbl -> GetSqnceFileName(This,step,Filename)

#define IGXLateUtils_SetFileMatchOptions(This,Opt)	\
    (This)->lpVtbl -> SetFileMatchOptions(This,Opt)

#define IGXLateUtils_EnumerateBitDepths(This,BitDepthList,Count,LongestLen)	\
    (This)->lpVtbl -> EnumerateBitDepths(This,BitDepthList,Count,LongestLen)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE IGXLateUtils_IsMMX_Proxy( 
    IGXLateUtils __RPC_FAR * This,
    /* [out] */ BOOL __RPC_FAR *MMX);


void __RPC_STUB IGXLateUtils_IsMMX_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IGXLateUtils_SetSqnceFileName_Proxy( 
    IGXLateUtils __RPC_FAR * This,
    /* [in][string] */ LPTSTR Filename,
    /* [out] */ DWORD __RPC_FAR *step);


void __RPC_STUB IGXLateUtils_SetSqnceFileName_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IGXLateUtils_GetNumberSqnceSteps_Proxy( 
    IGXLateUtils __RPC_FAR * This,
    /* [out] */ DWORD __RPC_FAR *Steps);


void __RPC_STUB IGXLateUtils_GetNumberSqnceSteps_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IGXLateUtils_GetSqnceFileName_Proxy( 
    IGXLateUtils __RPC_FAR * This,
    /* [in] */ DWORD step,
    /* [out][string] */ LPTSTR __RPC_FAR *Filename);


void __RPC_STUB IGXLateUtils_GetSqnceFileName_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IGXLateUtils_SetFileMatchOptions_Proxy( 
    IGXLateUtils __RPC_FAR * This,
    /* [in] */ FileNameMatchOptions __RPC_FAR *Opt);


void __RPC_STUB IGXLateUtils_SetFileMatchOptions_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IGXLateUtils_EnumerateBitDepths_Proxy( 
    IGXLateUtils __RPC_FAR * This,
    /* [out] */ BitDepthEnum __RPC_FAR *__RPC_FAR *BitDepthList,
    /* [out] */ DWORD __RPC_FAR *Count,
    /* [out] */ DWORD __RPC_FAR *LongestLen);


void __RPC_STUB IGXLateUtils_EnumerateBitDepths_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IGXLateUtils_INTERFACE_DEFINED__ */


#ifndef __IGXLateOptionsUI_INTERFACE_DEFINED__
#define __IGXLateOptionsUI_INTERFACE_DEFINED__

/****************************************
 * Generated header for interface: IGXLateOptionsUI
 * at Tue Nov 23 05:02:08 1999
 * using MIDL 3.01.75
 ****************************************/
/* [local][uuid][object] */ 


typedef 
enum tagUIPanels
    {	UIPanel_Compression	= 0x1,
	UIPanel_ImageAttribute	= 0x2,
	UIPanel_Name	= 0x4,
	UIPanel_ImageColor	= 0x8,
	UIPanel_Preview	= 0x10,
	UIPanel_FileName	= 0x20
    }	UIPanels;

typedef 
enum tagUIPanelOverride
    {	UIPanelOvr_QualityOn	= 0x1
    }	UIPanelOverride;


EXTERN_C const IID IID_IGXLateOptionsUI;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    interface DECLSPEC_UUID("8335e6bf-ab3b-11ce-8468-0000b468276b")
    IGXLateOptionsUI : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE SetPanelName( 
            /* [out][string] */ LPTSTR Filename) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetReadOnly( 
            /* [in] */ BOOL Flag) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Execute( 
            /* [in] */ IGXTranslator4 __RPC_FAR *Xlator,
            /* [in] */ IGXIntBitmap2 __RPC_FAR *pBmp,
            /* [in] */ IGXOptionsCallback __RPC_FAR *Callback) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetConfigData( 
            /* [in] */ PlayXlatorOpt __RPC_FAR *Opt) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetPanels( 
            /* [in] */ UIPanels Flag) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE OverrideFlags( 
            /* [in] */ UIPanelOverride Flag) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetPreviewWindowSize( 
            /* [in] */ DWORD width,
            /* [in] */ DWORD height) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetCallbackTimerInterval( 
            /* [in] */ DWORD milliSecs) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IGXLateOptionsUIVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            IGXLateOptionsUI __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            IGXLateOptionsUI __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            IGXLateOptionsUI __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetPanelName )( 
            IGXLateOptionsUI __RPC_FAR * This,
            /* [out][string] */ LPTSTR Filename);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetReadOnly )( 
            IGXLateOptionsUI __RPC_FAR * This,
            /* [in] */ BOOL Flag);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Execute )( 
            IGXLateOptionsUI __RPC_FAR * This,
            /* [in] */ IGXTranslator4 __RPC_FAR *Xlator,
            /* [in] */ IGXIntBitmap2 __RPC_FAR *pBmp,
            /* [in] */ IGXOptionsCallback __RPC_FAR *Callback);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetConfigData )( 
            IGXLateOptionsUI __RPC_FAR * This,
            /* [in] */ PlayXlatorOpt __RPC_FAR *Opt);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetPanels )( 
            IGXLateOptionsUI __RPC_FAR * This,
            /* [in] */ UIPanels Flag);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *OverrideFlags )( 
            IGXLateOptionsUI __RPC_FAR * This,
            /* [in] */ UIPanelOverride Flag);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetPreviewWindowSize )( 
            IGXLateOptionsUI __RPC_FAR * This,
            /* [in] */ DWORD width,
            /* [in] */ DWORD height);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetCallbackTimerInterval )( 
            IGXLateOptionsUI __RPC_FAR * This,
            /* [in] */ DWORD milliSecs);
        
        END_INTERFACE
    } IGXLateOptionsUIVtbl;

    interface IGXLateOptionsUI
    {
        CONST_VTBL struct IGXLateOptionsUIVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IGXLateOptionsUI_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IGXLateOptionsUI_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IGXLateOptionsUI_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IGXLateOptionsUI_SetPanelName(This,Filename)	\
    (This)->lpVtbl -> SetPanelName(This,Filename)

#define IGXLateOptionsUI_SetReadOnly(This,Flag)	\
    (This)->lpVtbl -> SetReadOnly(This,Flag)

#define IGXLateOptionsUI_Execute(This,Xlator,pBmp,Callback)	\
    (This)->lpVtbl -> Execute(This,Xlator,pBmp,Callback)

#define IGXLateOptionsUI_SetConfigData(This,Opt)	\
    (This)->lpVtbl -> SetConfigData(This,Opt)

#define IGXLateOptionsUI_SetPanels(This,Flag)	\
    (This)->lpVtbl -> SetPanels(This,Flag)

#define IGXLateOptionsUI_OverrideFlags(This,Flag)	\
    (This)->lpVtbl -> OverrideFlags(This,Flag)

#define IGXLateOptionsUI_SetPreviewWindowSize(This,width,height)	\
    (This)->lpVtbl -> SetPreviewWindowSize(This,width,height)

#define IGXLateOptionsUI_SetCallbackTimerInterval(This,milliSecs)	\
    (This)->lpVtbl -> SetCallbackTimerInterval(This,milliSecs)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE IGXLateOptionsUI_SetPanelName_Proxy( 
    IGXLateOptionsUI __RPC_FAR * This,
    /* [out][string] */ LPTSTR Filename);


void __RPC_STUB IGXLateOptionsUI_SetPanelName_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IGXLateOptionsUI_SetReadOnly_Proxy( 
    IGXLateOptionsUI __RPC_FAR * This,
    /* [in] */ BOOL Flag);


void __RPC_STUB IGXLateOptionsUI_SetReadOnly_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IGXLateOptionsUI_Execute_Proxy( 
    IGXLateOptionsUI __RPC_FAR * This,
    /* [in] */ IGXTranslator4 __RPC_FAR *Xlator,
    /* [in] */ IGXIntBitmap2 __RPC_FAR *pBmp,
    /* [in] */ IGXOptionsCallback __RPC_FAR *Callback);


void __RPC_STUB IGXLateOptionsUI_Execute_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IGXLateOptionsUI_SetConfigData_Proxy( 
    IGXLateOptionsUI __RPC_FAR * This,
    /* [in] */ PlayXlatorOpt __RPC_FAR *Opt);


void __RPC_STUB IGXLateOptionsUI_SetConfigData_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IGXLateOptionsUI_SetPanels_Proxy( 
    IGXLateOptionsUI __RPC_FAR * This,
    /* [in] */ UIPanels Flag);


void __RPC_STUB IGXLateOptionsUI_SetPanels_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IGXLateOptionsUI_OverrideFlags_Proxy( 
    IGXLateOptionsUI __RPC_FAR * This,
    /* [in] */ UIPanelOverride Flag);


void __RPC_STUB IGXLateOptionsUI_OverrideFlags_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IGXLateOptionsUI_SetPreviewWindowSize_Proxy( 
    IGXLateOptionsUI __RPC_FAR * This,
    /* [in] */ DWORD width,
    /* [in] */ DWORD height);


void __RPC_STUB IGXLateOptionsUI_SetPreviewWindowSize_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IGXLateOptionsUI_SetCallbackTimerInterval_Proxy( 
    IGXLateOptionsUI __RPC_FAR * This,
    /* [in] */ DWORD milliSecs);


void __RPC_STUB IGXLateOptionsUI_SetCallbackTimerInterval_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IGXLateOptionsUI_INTERFACE_DEFINED__ */


#ifndef __IGXOptionsCallback_INTERFACE_DEFINED__
#define __IGXOptionsCallback_INTERFACE_DEFINED__

/****************************************
 * Generated header for interface: IGXOptionsCallback
 * at Tue Nov 23 05:02:08 1999
 * using MIDL 3.01.75
 ****************************************/
/* [local][uuid][object] */ 



EXTERN_C const IID IID_IGXOptionsCallback;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    interface DECLSPEC_UUID("8335e6c0-ab3b-11ce-8468-0000b468276b")
    IGXOptionsCallback : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE CompressionChanged( 
            /* [in] */ PlayXlatorOpt __RPC_FAR *Opt) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE FileMatchNameChanged( 
            /* [in] */ PlayXlatorOpt __RPC_FAR *Opt) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE AlphaImageColorChanged( 
            /* [in] */ PlayXlatorOpt __RPC_FAR *Opt) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetImageStats( 
            /* [out] */ DWORD __RPC_FAR *FileSize,
            /* [out] */ DWORD __RPC_FAR *TimeToDisplay) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IGXOptionsCallbackVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            IGXOptionsCallback __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            IGXOptionsCallback __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            IGXOptionsCallback __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *CompressionChanged )( 
            IGXOptionsCallback __RPC_FAR * This,
            /* [in] */ PlayXlatorOpt __RPC_FAR *Opt);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *FileMatchNameChanged )( 
            IGXOptionsCallback __RPC_FAR * This,
            /* [in] */ PlayXlatorOpt __RPC_FAR *Opt);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *AlphaImageColorChanged )( 
            IGXOptionsCallback __RPC_FAR * This,
            /* [in] */ PlayXlatorOpt __RPC_FAR *Opt);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetImageStats )( 
            IGXOptionsCallback __RPC_FAR * This,
            /* [out] */ DWORD __RPC_FAR *FileSize,
            /* [out] */ DWORD __RPC_FAR *TimeToDisplay);
        
        END_INTERFACE
    } IGXOptionsCallbackVtbl;

    interface IGXOptionsCallback
    {
        CONST_VTBL struct IGXOptionsCallbackVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IGXOptionsCallback_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IGXOptionsCallback_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IGXOptionsCallback_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IGXOptionsCallback_CompressionChanged(This,Opt)	\
    (This)->lpVtbl -> CompressionChanged(This,Opt)

#define IGXOptionsCallback_FileMatchNameChanged(This,Opt)	\
    (This)->lpVtbl -> FileMatchNameChanged(This,Opt)

#define IGXOptionsCallback_AlphaImageColorChanged(This,Opt)	\
    (This)->lpVtbl -> AlphaImageColorChanged(This,Opt)

#define IGXOptionsCallback_GetImageStats(This,FileSize,TimeToDisplay)	\
    (This)->lpVtbl -> GetImageStats(This,FileSize,TimeToDisplay)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE IGXOptionsCallback_CompressionChanged_Proxy( 
    IGXOptionsCallback __RPC_FAR * This,
    /* [in] */ PlayXlatorOpt __RPC_FAR *Opt);


void __RPC_STUB IGXOptionsCallback_CompressionChanged_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IGXOptionsCallback_FileMatchNameChanged_Proxy( 
    IGXOptionsCallback __RPC_FAR * This,
    /* [in] */ PlayXlatorOpt __RPC_FAR *Opt);


void __RPC_STUB IGXOptionsCallback_FileMatchNameChanged_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IGXOptionsCallback_AlphaImageColorChanged_Proxy( 
    IGXOptionsCallback __RPC_FAR * This,
    /* [in] */ PlayXlatorOpt __RPC_FAR *Opt);


void __RPC_STUB IGXOptionsCallback_AlphaImageColorChanged_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IGXOptionsCallback_GetImageStats_Proxy( 
    IGXOptionsCallback __RPC_FAR * This,
    /* [out] */ DWORD __RPC_FAR *FileSize,
    /* [out] */ DWORD __RPC_FAR *TimeToDisplay);


void __RPC_STUB IGXOptionsCallback_GetImageStats_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IGXOptionsCallback_INTERFACE_DEFINED__ */


/* Additional Prototypes for ALL interfaces */

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif
