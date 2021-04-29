/* this ALWAYS GENERATED file contains the definitions for the interfaces */


/* File created by MIDL compiler version 3.01.75 */
/* at Tue Nov 23 05:02:17 1999
 */
/* Compiler settings for color.idl:
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

#ifndef __color_h__
#define __color_h__

#ifdef __cplusplus
extern "C"{
#endif 

/* Forward Declarations */ 

#ifndef __IPlayColor_FWD_DEFINED__
#define __IPlayColor_FWD_DEFINED__
typedef interface IPlayColor IPlayColor;
#endif 	/* __IPlayColor_FWD_DEFINED__ */


/* header files for imported files */
#include "wtypes.h"
#include "unknwn.h"
#include "objidl.h"

void __RPC_FAR * __RPC_USER MIDL_user_allocate(size_t);
void __RPC_USER MIDL_user_free( void __RPC_FAR * ); 

/****************************************
 * Generated header for interface: __MIDL_itf_color_0000
 * at Tue Nov 23 05:02:17 1999
 * using MIDL 3.01.75
 ****************************************/
/* [local] */ 



interface IGXIntBitmap;
typedef 
enum tagEPlayColorSpace
    {	PlayColor_RGB	= 0,
	PlayColor_HSV	= PlayColor_RGB + 1,
	PlayColor_YUV	= PlayColor_HSV + 1
    }	EPlayColorSpace;

typedef 
enum tagEPlayColorSpread
    {	PlayColor_Solid	= 0,
	PlayColor_Linear	= PlayColor_Solid + 1,
	PlayColor_CornerPoint	= PlayColor_Linear + 1,
	PlayColor_Circular	= PlayColor_CornerPoint + 1,
	PlayColor_BevelBox	= PlayColor_Circular + 1,
	PlayColor_2SideHorz	= PlayColor_BevelBox + 1,
	PlayColor_2SideVert	= PlayColor_2SideHorz + 1,
	PlayColor_4Side	= PlayColor_2SideVert + 1
    }	EPlayColorSpread;



extern RPC_IF_HANDLE __MIDL_itf_color_0000_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_color_0000_v0_0_s_ifspec;

#ifndef __IPlayColor_INTERFACE_DEFINED__
#define __IPlayColor_INTERFACE_DEFINED__

/****************************************
 * Generated header for interface: IPlayColor
 * at Tue Nov 23 05:02:17 1999
 * using MIDL 3.01.75
 ****************************************/
/* [unique][uuid][object][local] */ 



EXTERN_C const IID IID_IPlayColor;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    interface DECLSPEC_UUID("8335e451-ab3b-11ce-8468-0000b468276b")
    IPlayColor : public IPersistStorage
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE SetColorSpread( 
            /* [in] */ EPlayColorSpread ColorSpread) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetColorSpread( 
            /* [out] */ EPlayColorSpread __RPC_FAR *pColorSpread) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetColorSpace( 
            /* [in] */ EPlayColorSpace ColorSpace) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetColorSpace( 
            /* [out] */ EPlayColorSpace __RPC_FAR *pColorSpace) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE InsertColor( 
            DWORD r,
            DWORD g,
            DWORD b,
            float pos) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetColor( 
            unsigned int index,
            DWORD r,
            DWORD g,
            DWORD b) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetColor( 
            unsigned int index,
            /* [out] */ DWORD __RPC_FAR *pr,
            /* [out] */ DWORD __RPC_FAR *pg,
            /* [out] */ DWORD __RPC_FAR *pb) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetColorPos( 
            unsigned int index,
            /* [out] */ float __RPC_FAR *pPos) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetColorPos( 
            unsigned int index,
            float Pos,
            unsigned int __RPC_FAR *pNewIndex) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE DeleteColor( 
            unsigned int index) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetNumColors( 
            /* [out] */ unsigned int __RPC_FAR *pMaxIndex) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetRotation( 
            /* [out] */ float __RPC_FAR *pRotation) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetRotation( 
            /* [in] */ float Rotation) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetColorCenter( 
            float __RPC_FAR *float_x,
            float __RPC_FAR *float_y) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetColorCenter( 
            float float_x,
            float float_y) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Clone( 
            /* [out] */ IPlayColor __RPC_FAR *__RPC_FAR *ppColor) = 0;
        
        virtual BOOL STDMETHODCALLTYPE Compare( 
            /* [in] */ IPlayColor __RPC_FAR *pColor) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Render( 
            /* [in] */ IGXIntBitmap __RPC_FAR *pGXIB) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetRawRGB( 
            unsigned int index,
            /* [out] */ DWORD __RPC_FAR *pr,
            /* [out] */ DWORD __RPC_FAR *pg,
            /* [out] */ DWORD __RPC_FAR *pb) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IPlayColorVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            IPlayColor __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            IPlayColor __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            IPlayColor __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetClassID )( 
            IPlayColor __RPC_FAR * This,
            /* [out] */ CLSID __RPC_FAR *pClassID);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *IsDirty )( 
            IPlayColor __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *InitNew )( 
            IPlayColor __RPC_FAR * This,
            /* [unique][in] */ IStorage __RPC_FAR *pStg);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Load )( 
            IPlayColor __RPC_FAR * This,
            /* [unique][in] */ IStorage __RPC_FAR *pStg);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Save )( 
            IPlayColor __RPC_FAR * This,
            /* [unique][in] */ IStorage __RPC_FAR *pStgSave,
            /* [in] */ BOOL fSameAsLoad);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SaveCompleted )( 
            IPlayColor __RPC_FAR * This,
            /* [unique][in] */ IStorage __RPC_FAR *pStgNew);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *HandsOffStorage )( 
            IPlayColor __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetColorSpread )( 
            IPlayColor __RPC_FAR * This,
            /* [in] */ EPlayColorSpread ColorSpread);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetColorSpread )( 
            IPlayColor __RPC_FAR * This,
            /* [out] */ EPlayColorSpread __RPC_FAR *pColorSpread);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetColorSpace )( 
            IPlayColor __RPC_FAR * This,
            /* [in] */ EPlayColorSpace ColorSpace);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetColorSpace )( 
            IPlayColor __RPC_FAR * This,
            /* [out] */ EPlayColorSpace __RPC_FAR *pColorSpace);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *InsertColor )( 
            IPlayColor __RPC_FAR * This,
            DWORD r,
            DWORD g,
            DWORD b,
            float pos);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetColor )( 
            IPlayColor __RPC_FAR * This,
            unsigned int index,
            DWORD r,
            DWORD g,
            DWORD b);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetColor )( 
            IPlayColor __RPC_FAR * This,
            unsigned int index,
            /* [out] */ DWORD __RPC_FAR *pr,
            /* [out] */ DWORD __RPC_FAR *pg,
            /* [out] */ DWORD __RPC_FAR *pb);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetColorPos )( 
            IPlayColor __RPC_FAR * This,
            unsigned int index,
            /* [out] */ float __RPC_FAR *pPos);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetColorPos )( 
            IPlayColor __RPC_FAR * This,
            unsigned int index,
            float Pos,
            unsigned int __RPC_FAR *pNewIndex);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *DeleteColor )( 
            IPlayColor __RPC_FAR * This,
            unsigned int index);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetNumColors )( 
            IPlayColor __RPC_FAR * This,
            /* [out] */ unsigned int __RPC_FAR *pMaxIndex);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetRotation )( 
            IPlayColor __RPC_FAR * This,
            /* [out] */ float __RPC_FAR *pRotation);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetRotation )( 
            IPlayColor __RPC_FAR * This,
            /* [in] */ float Rotation);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetColorCenter )( 
            IPlayColor __RPC_FAR * This,
            float __RPC_FAR *float_x,
            float __RPC_FAR *float_y);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetColorCenter )( 
            IPlayColor __RPC_FAR * This,
            float float_x,
            float float_y);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Clone )( 
            IPlayColor __RPC_FAR * This,
            /* [out] */ IPlayColor __RPC_FAR *__RPC_FAR *ppColor);
        
        BOOL ( STDMETHODCALLTYPE __RPC_FAR *Compare )( 
            IPlayColor __RPC_FAR * This,
            /* [in] */ IPlayColor __RPC_FAR *pColor);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Render )( 
            IPlayColor __RPC_FAR * This,
            /* [in] */ IGXIntBitmap __RPC_FAR *pGXIB);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetRawRGB )( 
            IPlayColor __RPC_FAR * This,
            unsigned int index,
            /* [out] */ DWORD __RPC_FAR *pr,
            /* [out] */ DWORD __RPC_FAR *pg,
            /* [out] */ DWORD __RPC_FAR *pb);
        
        END_INTERFACE
    } IPlayColorVtbl;

    interface IPlayColor
    {
        CONST_VTBL struct IPlayColorVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IPlayColor_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IPlayColor_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IPlayColor_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IPlayColor_GetClassID(This,pClassID)	\
    (This)->lpVtbl -> GetClassID(This,pClassID)


#define IPlayColor_IsDirty(This)	\
    (This)->lpVtbl -> IsDirty(This)

#define IPlayColor_InitNew(This,pStg)	\
    (This)->lpVtbl -> InitNew(This,pStg)

#define IPlayColor_Load(This,pStg)	\
    (This)->lpVtbl -> Load(This,pStg)

#define IPlayColor_Save(This,pStgSave,fSameAsLoad)	\
    (This)->lpVtbl -> Save(This,pStgSave,fSameAsLoad)

#define IPlayColor_SaveCompleted(This,pStgNew)	\
    (This)->lpVtbl -> SaveCompleted(This,pStgNew)

#define IPlayColor_HandsOffStorage(This)	\
    (This)->lpVtbl -> HandsOffStorage(This)


#define IPlayColor_SetColorSpread(This,ColorSpread)	\
    (This)->lpVtbl -> SetColorSpread(This,ColorSpread)

#define IPlayColor_GetColorSpread(This,pColorSpread)	\
    (This)->lpVtbl -> GetColorSpread(This,pColorSpread)

#define IPlayColor_SetColorSpace(This,ColorSpace)	\
    (This)->lpVtbl -> SetColorSpace(This,ColorSpace)

#define IPlayColor_GetColorSpace(This,pColorSpace)	\
    (This)->lpVtbl -> GetColorSpace(This,pColorSpace)

#define IPlayColor_InsertColor(This,r,g,b,pos)	\
    (This)->lpVtbl -> InsertColor(This,r,g,b,pos)

#define IPlayColor_SetColor(This,index,r,g,b)	\
    (This)->lpVtbl -> SetColor(This,index,r,g,b)

#define IPlayColor_GetColor(This,index,pr,pg,pb)	\
    (This)->lpVtbl -> GetColor(This,index,pr,pg,pb)

#define IPlayColor_GetColorPos(This,index,pPos)	\
    (This)->lpVtbl -> GetColorPos(This,index,pPos)

#define IPlayColor_SetColorPos(This,index,Pos,pNewIndex)	\
    (This)->lpVtbl -> SetColorPos(This,index,Pos,pNewIndex)

#define IPlayColor_DeleteColor(This,index)	\
    (This)->lpVtbl -> DeleteColor(This,index)

#define IPlayColor_GetNumColors(This,pMaxIndex)	\
    (This)->lpVtbl -> GetNumColors(This,pMaxIndex)

#define IPlayColor_GetRotation(This,pRotation)	\
    (This)->lpVtbl -> GetRotation(This,pRotation)

#define IPlayColor_SetRotation(This,Rotation)	\
    (This)->lpVtbl -> SetRotation(This,Rotation)

#define IPlayColor_GetColorCenter(This,float_x,float_y)	\
    (This)->lpVtbl -> GetColorCenter(This,float_x,float_y)

#define IPlayColor_SetColorCenter(This,float_x,float_y)	\
    (This)->lpVtbl -> SetColorCenter(This,float_x,float_y)

#define IPlayColor_Clone(This,ppColor)	\
    (This)->lpVtbl -> Clone(This,ppColor)

#define IPlayColor_Compare(This,pColor)	\
    (This)->lpVtbl -> Compare(This,pColor)

#define IPlayColor_Render(This,pGXIB)	\
    (This)->lpVtbl -> Render(This,pGXIB)

#define IPlayColor_GetRawRGB(This,index,pr,pg,pb)	\
    (This)->lpVtbl -> GetRawRGB(This,index,pr,pg,pb)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE IPlayColor_SetColorSpread_Proxy( 
    IPlayColor __RPC_FAR * This,
    /* [in] */ EPlayColorSpread ColorSpread);


void __RPC_STUB IPlayColor_SetColorSpread_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IPlayColor_GetColorSpread_Proxy( 
    IPlayColor __RPC_FAR * This,
    /* [out] */ EPlayColorSpread __RPC_FAR *pColorSpread);


void __RPC_STUB IPlayColor_GetColorSpread_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IPlayColor_SetColorSpace_Proxy( 
    IPlayColor __RPC_FAR * This,
    /* [in] */ EPlayColorSpace ColorSpace);


void __RPC_STUB IPlayColor_SetColorSpace_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IPlayColor_GetColorSpace_Proxy( 
    IPlayColor __RPC_FAR * This,
    /* [out] */ EPlayColorSpace __RPC_FAR *pColorSpace);


void __RPC_STUB IPlayColor_GetColorSpace_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IPlayColor_InsertColor_Proxy( 
    IPlayColor __RPC_FAR * This,
    DWORD r,
    DWORD g,
    DWORD b,
    float pos);


void __RPC_STUB IPlayColor_InsertColor_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IPlayColor_SetColor_Proxy( 
    IPlayColor __RPC_FAR * This,
    unsigned int index,
    DWORD r,
    DWORD g,
    DWORD b);


void __RPC_STUB IPlayColor_SetColor_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IPlayColor_GetColor_Proxy( 
    IPlayColor __RPC_FAR * This,
    unsigned int index,
    /* [out] */ DWORD __RPC_FAR *pr,
    /* [out] */ DWORD __RPC_FAR *pg,
    /* [out] */ DWORD __RPC_FAR *pb);


void __RPC_STUB IPlayColor_GetColor_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IPlayColor_GetColorPos_Proxy( 
    IPlayColor __RPC_FAR * This,
    unsigned int index,
    /* [out] */ float __RPC_FAR *pPos);


void __RPC_STUB IPlayColor_GetColorPos_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IPlayColor_SetColorPos_Proxy( 
    IPlayColor __RPC_FAR * This,
    unsigned int index,
    float Pos,
    unsigned int __RPC_FAR *pNewIndex);


void __RPC_STUB IPlayColor_SetColorPos_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IPlayColor_DeleteColor_Proxy( 
    IPlayColor __RPC_FAR * This,
    unsigned int index);


void __RPC_STUB IPlayColor_DeleteColor_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IPlayColor_GetNumColors_Proxy( 
    IPlayColor __RPC_FAR * This,
    /* [out] */ unsigned int __RPC_FAR *pMaxIndex);


void __RPC_STUB IPlayColor_GetNumColors_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IPlayColor_GetRotation_Proxy( 
    IPlayColor __RPC_FAR * This,
    /* [out] */ float __RPC_FAR *pRotation);


void __RPC_STUB IPlayColor_GetRotation_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IPlayColor_SetRotation_Proxy( 
    IPlayColor __RPC_FAR * This,
    /* [in] */ float Rotation);


void __RPC_STUB IPlayColor_SetRotation_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IPlayColor_GetColorCenter_Proxy( 
    IPlayColor __RPC_FAR * This,
    float __RPC_FAR *float_x,
    float __RPC_FAR *float_y);


void __RPC_STUB IPlayColor_GetColorCenter_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IPlayColor_SetColorCenter_Proxy( 
    IPlayColor __RPC_FAR * This,
    float float_x,
    float float_y);


void __RPC_STUB IPlayColor_SetColorCenter_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IPlayColor_Clone_Proxy( 
    IPlayColor __RPC_FAR * This,
    /* [out] */ IPlayColor __RPC_FAR *__RPC_FAR *ppColor);


void __RPC_STUB IPlayColor_Clone_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


BOOL STDMETHODCALLTYPE IPlayColor_Compare_Proxy( 
    IPlayColor __RPC_FAR * This,
    /* [in] */ IPlayColor __RPC_FAR *pColor);


void __RPC_STUB IPlayColor_Compare_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IPlayColor_Render_Proxy( 
    IPlayColor __RPC_FAR * This,
    /* [in] */ IGXIntBitmap __RPC_FAR *pGXIB);


void __RPC_STUB IPlayColor_Render_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IPlayColor_GetRawRGB_Proxy( 
    IPlayColor __RPC_FAR * This,
    unsigned int index,
    /* [out] */ DWORD __RPC_FAR *pr,
    /* [out] */ DWORD __RPC_FAR *pg,
    /* [out] */ DWORD __RPC_FAR *pb);


void __RPC_STUB IPlayColor_GetRawRGB_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IPlayColor_INTERFACE_DEFINED__ */


/* Additional Prototypes for ALL interfaces */

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif
