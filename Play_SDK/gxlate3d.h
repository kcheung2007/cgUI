/* this ALWAYS GENERATED file contains the definitions for the interfaces */


/* File created by MIDL compiler version 3.01.75 */
/* at Tue Nov 23 05:02:16 1999
 */
/* Compiler settings for gxlate3d.idl:
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

#ifndef __gxlate3d_h__
#define __gxlate3d_h__

#ifdef __cplusplus
extern "C"{
#endif 

/* Forward Declarations */ 

#ifndef __IGX3DEnumTrans_FWD_DEFINED__
#define __IGX3DEnumTrans_FWD_DEFINED__
typedef interface IGX3DEnumTrans IGX3DEnumTrans;
#endif 	/* __IGX3DEnumTrans_FWD_DEFINED__ */


#ifndef __IGX3DEnumObjects_FWD_DEFINED__
#define __IGX3DEnumObjects_FWD_DEFINED__
typedef interface IGX3DEnumObjects IGX3DEnumObjects;
#endif 	/* __IGX3DEnumObjects_FWD_DEFINED__ */


#ifndef __IGX3DEnumPolygons_FWD_DEFINED__
#define __IGX3DEnumPolygons_FWD_DEFINED__
typedef interface IGX3DEnumPolygons IGX3DEnumPolygons;
#endif 	/* __IGX3DEnumPolygons_FWD_DEFINED__ */


#ifndef __IGX3DEnumVertices_FWD_DEFINED__
#define __IGX3DEnumVertices_FWD_DEFINED__
typedef interface IGX3DEnumVertices IGX3DEnumVertices;
#endif 	/* __IGX3DEnumVertices_FWD_DEFINED__ */


#ifndef __IGX3DEnumNormals_FWD_DEFINED__
#define __IGX3DEnumNormals_FWD_DEFINED__
typedef interface IGX3DEnumNormals IGX3DEnumNormals;
#endif 	/* __IGX3DEnumNormals_FWD_DEFINED__ */


#ifndef __IGX3DEnumSurfaces_FWD_DEFINED__
#define __IGX3DEnumSurfaces_FWD_DEFINED__
typedef interface IGX3DEnumSurfaces IGX3DEnumSurfaces;
#endif 	/* __IGX3DEnumSurfaces_FWD_DEFINED__ */


#ifndef __IGX3DEnumSurfaceMaps_FWD_DEFINED__
#define __IGX3DEnumSurfaceMaps_FWD_DEFINED__
typedef interface IGX3DEnumSurfaceMaps IGX3DEnumSurfaceMaps;
#endif 	/* __IGX3DEnumSurfaceMaps_FWD_DEFINED__ */


#ifndef __IGX3DScene_FWD_DEFINED__
#define __IGX3DScene_FWD_DEFINED__
typedef interface IGX3DScene IGX3DScene;
#endif 	/* __IGX3DScene_FWD_DEFINED__ */


#ifndef __IGX3DObject_FWD_DEFINED__
#define __IGX3DObject_FWD_DEFINED__
typedef interface IGX3DObject IGX3DObject;
#endif 	/* __IGX3DObject_FWD_DEFINED__ */


#ifndef __IGX3DSurface_FWD_DEFINED__
#define __IGX3DSurface_FWD_DEFINED__
typedef interface IGX3DSurface IGX3DSurface;
#endif 	/* __IGX3DSurface_FWD_DEFINED__ */


#ifndef __IGX3DSurfaceMap_FWD_DEFINED__
#define __IGX3DSurfaceMap_FWD_DEFINED__
typedef interface IGX3DSurfaceMap IGX3DSurfaceMap;
#endif 	/* __IGX3DSurfaceMap_FWD_DEFINED__ */


#ifndef __IGX3DTransFact_FWD_DEFINED__
#define __IGX3DTransFact_FWD_DEFINED__
typedef interface IGX3DTransFact IGX3DTransFact;
#endif 	/* __IGX3DTransFact_FWD_DEFINED__ */


#ifndef __IGX3DTranslator_FWD_DEFINED__
#define __IGX3DTranslator_FWD_DEFINED__
typedef interface IGX3DTranslator IGX3DTranslator;
#endif 	/* __IGX3DTranslator_FWD_DEFINED__ */


#ifndef __IGX3DClientIO_FWD_DEFINED__
#define __IGX3DClientIO_FWD_DEFINED__
typedef interface IGX3DClientIO IGX3DClientIO;
#endif 	/* __IGX3DClientIO_FWD_DEFINED__ */


#ifndef __IGX3DProgress_FWD_DEFINED__
#define __IGX3DProgress_FWD_DEFINED__
typedef interface IGX3DProgress IGX3DProgress;
#endif 	/* __IGX3DProgress_FWD_DEFINED__ */


/* header files for imported files */
#include "objidl.h"

void __RPC_FAR * __RPC_USER MIDL_user_allocate(size_t);
void __RPC_USER MIDL_user_free( void __RPC_FAR * ); 

/****************************************
 * Generated header for interface: __MIDL_itf_gxlate3d_0000
 * at Tue Nov 23 05:02:16 1999
 * using MIDL 3.01.75
 ****************************************/
/* [local] */ 



















extern RPC_IF_HANDLE __MIDL_itf_gxlate3d_0000_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_gxlate3d_0000_v0_0_s_ifspec;

#ifndef __IGX3DTypes_INTERFACE_DEFINED__
#define __IGX3DTypes_INTERFACE_DEFINED__

/****************************************
 * Generated header for interface: IGX3DTypes
 * at Tue Nov 23 05:02:16 1999
 * using MIDL 3.01.75
 ****************************************/
/* [auto_handle][unique][uuid] */ 


typedef 
enum tagESurfaceMapType
    {	MT_TEXTURE	= 0x1,
	MT_REFLECTION	= 0x2,
	MT_BUMP	= 0x4,
	MT_OPACITY	= 0x8,
	MT_TRANSPARENCY	= 0x10,
	MT_SPECULAR	= 0x20,
	MT_DIFFUSE	= 0x40,
	MT_SELFILLUM	= 0x80,
	MT_SHININESS	= 0x100
    }	EMapType;

typedef 
enum tagESurfaceMapMode
    {	MM_DEFAULT	= 0,
	MM_PLANAR_X	= 0x1,
	MM_PLANAR_Y	= 0x2,
	MM_PLANAR_Z	= 0x4,
	MM_CYLINDRICAL	= 0x8,
	MM_SPHERICAL	= 0x10,
	MM_CUBIC	= 0x20,
	MM_SHRINKWRAP	= 0x40
    }	EMapMode;

typedef 
enum tagESurfaceMapImage
    {	MI_SINGLE	= 0x1,
	MI_MULTI	= 0x2,
	MI_SEQUENCE	= 0x4
    }	EMapImage;

typedef struct  tag3DCoords
    {
    double x;
    double y;
    double z;
    }	GXCoords;

typedef GXCoords GXVertex;

typedef struct  tagPolygon
    {
    DWORD VertexCount;
    DWORD __RPC_FAR *VertexIndices;
    DWORD SurfaceIndex;
    }	GXPolygon;

typedef struct  tagRGBTriple
    {
    float r;
    float g;
    float b;
    }	GXRGBTriple;

typedef struct  tagSurfaceAttributes
    {
    unsigned char Name[ 128 ];
    GXRGBTriple Specular;
    GXRGBTriple Diffuse;
    GXRGBTriple Ambient;
    double Reflectivity;
    double Transparency;
    double Glossiness;
    double Luminosity;
    double RefractionIdx;
    double Absorption;
    double ReflectionBlur;
    BYTE TwoSided;
    ULONG TotalVerts;
    ULONG TotalPolys;
    }	GXSurfaceAttrib;

typedef struct  tagSurfaceMapAttributes
    {
    BYTE FileName[ 260 ];
    EMapType Type;
    EMapMode Mode;
    EMapImage Image;
    float Percent;
    double OffsetU;
    double OffsetV;
    double SpanU;
    double SpanV;
    double OriginU;
    double OriginV;
    double ScaleU;
    double ScaleV;
    double Width;
    double Height;
    BYTE MirrorU;
    BYTE MirrorV;
    BYTE TileU;
    BYTE TileV;
    }	GXMapAttrib;

typedef GXCoords GXNormal;



extern RPC_IF_HANDLE IGX3DTypes_v0_0_c_ifspec;
extern RPC_IF_HANDLE IGX3DTypes_v0_0_s_ifspec;
#endif /* __IGX3DTypes_INTERFACE_DEFINED__ */

#ifndef __IGX3DEnumTrans_INTERFACE_DEFINED__
#define __IGX3DEnumTrans_INTERFACE_DEFINED__

/****************************************
 * Generated header for interface: IGX3DEnumTrans
 * at Tue Nov 23 05:02:16 1999
 * using MIDL 3.01.75
 ****************************************/
/* [uuid][object] */ 



EXTERN_C const IID IID_IGX3DEnumTrans;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    interface DECLSPEC_UUID("8335e671-ab3b-11ce-8468-0000b468276b")
    IGX3DEnumTrans : public IUnknown
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
            /* [out] */ IGX3DEnumTrans __RPC_FAR *__RPC_FAR *ppenum) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IGX3DEnumTransVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            IGX3DEnumTrans __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            IGX3DEnumTrans __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            IGX3DEnumTrans __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Next )( 
            IGX3DEnumTrans __RPC_FAR * This,
            /* [in] */ DWORD fileTypeSize,
            /* [in] */ DWORD fileDescripSize,
            /* [out] */ unsigned char __RPC_FAR *szFileTypeName,
            /* [out] */ unsigned char __RPC_FAR *szFileDescrip);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Skip )( 
            IGX3DEnumTrans __RPC_FAR * This,
            /* [in] */ ULONG celt);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Reset )( 
            IGX3DEnumTrans __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Clone )( 
            IGX3DEnumTrans __RPC_FAR * This,
            /* [out] */ IGX3DEnumTrans __RPC_FAR *__RPC_FAR *ppenum);
        
        END_INTERFACE
    } IGX3DEnumTransVtbl;

    interface IGX3DEnumTrans
    {
        CONST_VTBL struct IGX3DEnumTransVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IGX3DEnumTrans_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IGX3DEnumTrans_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IGX3DEnumTrans_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IGX3DEnumTrans_Next(This,fileTypeSize,fileDescripSize,szFileTypeName,szFileDescrip)	\
    (This)->lpVtbl -> Next(This,fileTypeSize,fileDescripSize,szFileTypeName,szFileDescrip)

#define IGX3DEnumTrans_Skip(This,celt)	\
    (This)->lpVtbl -> Skip(This,celt)

#define IGX3DEnumTrans_Reset(This)	\
    (This)->lpVtbl -> Reset(This)

#define IGX3DEnumTrans_Clone(This,ppenum)	\
    (This)->lpVtbl -> Clone(This,ppenum)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE IGX3DEnumTrans_Next_Proxy( 
    IGX3DEnumTrans __RPC_FAR * This,
    /* [in] */ DWORD fileTypeSize,
    /* [in] */ DWORD fileDescripSize,
    /* [out] */ unsigned char __RPC_FAR *szFileTypeName,
    /* [out] */ unsigned char __RPC_FAR *szFileDescrip);


void __RPC_STUB IGX3DEnumTrans_Next_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IGX3DEnumTrans_Skip_Proxy( 
    IGX3DEnumTrans __RPC_FAR * This,
    /* [in] */ ULONG celt);


void __RPC_STUB IGX3DEnumTrans_Skip_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IGX3DEnumTrans_Reset_Proxy( 
    IGX3DEnumTrans __RPC_FAR * This);


void __RPC_STUB IGX3DEnumTrans_Reset_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IGX3DEnumTrans_Clone_Proxy( 
    IGX3DEnumTrans __RPC_FAR * This,
    /* [out] */ IGX3DEnumTrans __RPC_FAR *__RPC_FAR *ppenum);


void __RPC_STUB IGX3DEnumTrans_Clone_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IGX3DEnumTrans_INTERFACE_DEFINED__ */


#ifndef __IGX3DEnumObjects_INTERFACE_DEFINED__
#define __IGX3DEnumObjects_INTERFACE_DEFINED__

/****************************************
 * Generated header for interface: IGX3DEnumObjects
 * at Tue Nov 23 05:02:16 1999
 * using MIDL 3.01.75
 ****************************************/
/* [uuid][object] */ 



EXTERN_C const IID IID_IGX3DEnumObjects;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    interface DECLSPEC_UUID("8335e678-ab3b-11ce-8468-0000b468276b")
    IGX3DEnumObjects : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE Next( 
            /* [in] */ ULONG celt,
            /* [out] */ IGX3DObject __RPC_FAR *__RPC_FAR *pIGXObj,
            /* [out] */ ULONG __RPC_FAR *pceltFetched) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Skip( 
            /* [in] */ ULONG celt) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Reset( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Clone( 
            /* [out] */ IGX3DEnumObjects __RPC_FAR *__RPC_FAR *ppenum) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IGX3DEnumObjectsVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            IGX3DEnumObjects __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            IGX3DEnumObjects __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            IGX3DEnumObjects __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Next )( 
            IGX3DEnumObjects __RPC_FAR * This,
            /* [in] */ ULONG celt,
            /* [out] */ IGX3DObject __RPC_FAR *__RPC_FAR *pIGXObj,
            /* [out] */ ULONG __RPC_FAR *pceltFetched);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Skip )( 
            IGX3DEnumObjects __RPC_FAR * This,
            /* [in] */ ULONG celt);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Reset )( 
            IGX3DEnumObjects __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Clone )( 
            IGX3DEnumObjects __RPC_FAR * This,
            /* [out] */ IGX3DEnumObjects __RPC_FAR *__RPC_FAR *ppenum);
        
        END_INTERFACE
    } IGX3DEnumObjectsVtbl;

    interface IGX3DEnumObjects
    {
        CONST_VTBL struct IGX3DEnumObjectsVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IGX3DEnumObjects_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IGX3DEnumObjects_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IGX3DEnumObjects_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IGX3DEnumObjects_Next(This,celt,pIGXObj,pceltFetched)	\
    (This)->lpVtbl -> Next(This,celt,pIGXObj,pceltFetched)

#define IGX3DEnumObjects_Skip(This,celt)	\
    (This)->lpVtbl -> Skip(This,celt)

#define IGX3DEnumObjects_Reset(This)	\
    (This)->lpVtbl -> Reset(This)

#define IGX3DEnumObjects_Clone(This,ppenum)	\
    (This)->lpVtbl -> Clone(This,ppenum)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE IGX3DEnumObjects_Next_Proxy( 
    IGX3DEnumObjects __RPC_FAR * This,
    /* [in] */ ULONG celt,
    /* [out] */ IGX3DObject __RPC_FAR *__RPC_FAR *pIGXObj,
    /* [out] */ ULONG __RPC_FAR *pceltFetched);


void __RPC_STUB IGX3DEnumObjects_Next_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IGX3DEnumObjects_Skip_Proxy( 
    IGX3DEnumObjects __RPC_FAR * This,
    /* [in] */ ULONG celt);


void __RPC_STUB IGX3DEnumObjects_Skip_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IGX3DEnumObjects_Reset_Proxy( 
    IGX3DEnumObjects __RPC_FAR * This);


void __RPC_STUB IGX3DEnumObjects_Reset_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IGX3DEnumObjects_Clone_Proxy( 
    IGX3DEnumObjects __RPC_FAR * This,
    /* [out] */ IGX3DEnumObjects __RPC_FAR *__RPC_FAR *ppenum);


void __RPC_STUB IGX3DEnumObjects_Clone_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IGX3DEnumObjects_INTERFACE_DEFINED__ */


#ifndef __IGX3DEnumPolygons_INTERFACE_DEFINED__
#define __IGX3DEnumPolygons_INTERFACE_DEFINED__

/****************************************
 * Generated header for interface: IGX3DEnumPolygons
 * at Tue Nov 23 05:02:16 1999
 * using MIDL 3.01.75
 ****************************************/
/* [uuid][object] */ 



EXTERN_C const IID IID_IGX3DEnumPolygons;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    interface DECLSPEC_UUID("8335e679-ab3b-11ce-8468-0000b468276b")
    IGX3DEnumPolygons : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE Next( 
            /* [in] */ ULONG celt,
            /* [out] */ GXPolygon __RPC_FAR *__RPC_FAR *pGXPoly,
            /* [out] */ ULONG __RPC_FAR *pceltFetched) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Skip( 
            /* [in] */ ULONG celt) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Reset( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Clone( 
            /* [out] */ IGX3DEnumPolygons __RPC_FAR *__RPC_FAR *ppenum) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IGX3DEnumPolygonsVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            IGX3DEnumPolygons __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            IGX3DEnumPolygons __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            IGX3DEnumPolygons __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Next )( 
            IGX3DEnumPolygons __RPC_FAR * This,
            /* [in] */ ULONG celt,
            /* [out] */ GXPolygon __RPC_FAR *__RPC_FAR *pGXPoly,
            /* [out] */ ULONG __RPC_FAR *pceltFetched);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Skip )( 
            IGX3DEnumPolygons __RPC_FAR * This,
            /* [in] */ ULONG celt);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Reset )( 
            IGX3DEnumPolygons __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Clone )( 
            IGX3DEnumPolygons __RPC_FAR * This,
            /* [out] */ IGX3DEnumPolygons __RPC_FAR *__RPC_FAR *ppenum);
        
        END_INTERFACE
    } IGX3DEnumPolygonsVtbl;

    interface IGX3DEnumPolygons
    {
        CONST_VTBL struct IGX3DEnumPolygonsVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IGX3DEnumPolygons_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IGX3DEnumPolygons_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IGX3DEnumPolygons_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IGX3DEnumPolygons_Next(This,celt,pGXPoly,pceltFetched)	\
    (This)->lpVtbl -> Next(This,celt,pGXPoly,pceltFetched)

#define IGX3DEnumPolygons_Skip(This,celt)	\
    (This)->lpVtbl -> Skip(This,celt)

#define IGX3DEnumPolygons_Reset(This)	\
    (This)->lpVtbl -> Reset(This)

#define IGX3DEnumPolygons_Clone(This,ppenum)	\
    (This)->lpVtbl -> Clone(This,ppenum)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE IGX3DEnumPolygons_Next_Proxy( 
    IGX3DEnumPolygons __RPC_FAR * This,
    /* [in] */ ULONG celt,
    /* [out] */ GXPolygon __RPC_FAR *__RPC_FAR *pGXPoly,
    /* [out] */ ULONG __RPC_FAR *pceltFetched);


void __RPC_STUB IGX3DEnumPolygons_Next_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IGX3DEnumPolygons_Skip_Proxy( 
    IGX3DEnumPolygons __RPC_FAR * This,
    /* [in] */ ULONG celt);


void __RPC_STUB IGX3DEnumPolygons_Skip_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IGX3DEnumPolygons_Reset_Proxy( 
    IGX3DEnumPolygons __RPC_FAR * This);


void __RPC_STUB IGX3DEnumPolygons_Reset_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IGX3DEnumPolygons_Clone_Proxy( 
    IGX3DEnumPolygons __RPC_FAR * This,
    /* [out] */ IGX3DEnumPolygons __RPC_FAR *__RPC_FAR *ppenum);


void __RPC_STUB IGX3DEnumPolygons_Clone_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IGX3DEnumPolygons_INTERFACE_DEFINED__ */


#ifndef __IGX3DEnumVertices_INTERFACE_DEFINED__
#define __IGX3DEnumVertices_INTERFACE_DEFINED__

/****************************************
 * Generated header for interface: IGX3DEnumVertices
 * at Tue Nov 23 05:02:16 1999
 * using MIDL 3.01.75
 ****************************************/
/* [uuid][object] */ 



EXTERN_C const IID IID_IGX3DEnumVertices;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    interface DECLSPEC_UUID("8335e67a-ab3b-11ce-8468-0000b468276b")
    IGX3DEnumVertices : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE Next( 
            /* [in] */ ULONG celt,
            /* [out] */ GXVertex __RPC_FAR *__RPC_FAR *pGXVertex,
            /* [out] */ ULONG __RPC_FAR *pceltFetched) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Skip( 
            /* [in] */ ULONG celt) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Reset( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Clone( 
            /* [out] */ IGX3DEnumVertices __RPC_FAR *__RPC_FAR *ppenum) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IGX3DEnumVerticesVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            IGX3DEnumVertices __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            IGX3DEnumVertices __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            IGX3DEnumVertices __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Next )( 
            IGX3DEnumVertices __RPC_FAR * This,
            /* [in] */ ULONG celt,
            /* [out] */ GXVertex __RPC_FAR *__RPC_FAR *pGXVertex,
            /* [out] */ ULONG __RPC_FAR *pceltFetched);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Skip )( 
            IGX3DEnumVertices __RPC_FAR * This,
            /* [in] */ ULONG celt);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Reset )( 
            IGX3DEnumVertices __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Clone )( 
            IGX3DEnumVertices __RPC_FAR * This,
            /* [out] */ IGX3DEnumVertices __RPC_FAR *__RPC_FAR *ppenum);
        
        END_INTERFACE
    } IGX3DEnumVerticesVtbl;

    interface IGX3DEnumVertices
    {
        CONST_VTBL struct IGX3DEnumVerticesVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IGX3DEnumVertices_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IGX3DEnumVertices_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IGX3DEnumVertices_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IGX3DEnumVertices_Next(This,celt,pGXVertex,pceltFetched)	\
    (This)->lpVtbl -> Next(This,celt,pGXVertex,pceltFetched)

#define IGX3DEnumVertices_Skip(This,celt)	\
    (This)->lpVtbl -> Skip(This,celt)

#define IGX3DEnumVertices_Reset(This)	\
    (This)->lpVtbl -> Reset(This)

#define IGX3DEnumVertices_Clone(This,ppenum)	\
    (This)->lpVtbl -> Clone(This,ppenum)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE IGX3DEnumVertices_Next_Proxy( 
    IGX3DEnumVertices __RPC_FAR * This,
    /* [in] */ ULONG celt,
    /* [out] */ GXVertex __RPC_FAR *__RPC_FAR *pGXVertex,
    /* [out] */ ULONG __RPC_FAR *pceltFetched);


void __RPC_STUB IGX3DEnumVertices_Next_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IGX3DEnumVertices_Skip_Proxy( 
    IGX3DEnumVertices __RPC_FAR * This,
    /* [in] */ ULONG celt);


void __RPC_STUB IGX3DEnumVertices_Skip_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IGX3DEnumVertices_Reset_Proxy( 
    IGX3DEnumVertices __RPC_FAR * This);


void __RPC_STUB IGX3DEnumVertices_Reset_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IGX3DEnumVertices_Clone_Proxy( 
    IGX3DEnumVertices __RPC_FAR * This,
    /* [out] */ IGX3DEnumVertices __RPC_FAR *__RPC_FAR *ppenum);


void __RPC_STUB IGX3DEnumVertices_Clone_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IGX3DEnumVertices_INTERFACE_DEFINED__ */


#ifndef __IGX3DEnumNormals_INTERFACE_DEFINED__
#define __IGX3DEnumNormals_INTERFACE_DEFINED__

/****************************************
 * Generated header for interface: IGX3DEnumNormals
 * at Tue Nov 23 05:02:16 1999
 * using MIDL 3.01.75
 ****************************************/
/* [uuid][object] */ 



EXTERN_C const IID IID_IGX3DEnumNormals;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    interface DECLSPEC_UUID("8335e67d-ab3b-11ce-8468-0000b468276b")
    IGX3DEnumNormals : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE Next( 
            /* [in] */ ULONG celt,
            /* [out] */ GXNormal __RPC_FAR *__RPC_FAR *pGXNormal,
            /* [out] */ ULONG __RPC_FAR *pceltFetched) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Skip( 
            /* [in] */ ULONG celt) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Reset( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Clone( 
            /* [out] */ IGX3DEnumNormals __RPC_FAR *__RPC_FAR *ppenum) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IGX3DEnumNormalsVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            IGX3DEnumNormals __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            IGX3DEnumNormals __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            IGX3DEnumNormals __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Next )( 
            IGX3DEnumNormals __RPC_FAR * This,
            /* [in] */ ULONG celt,
            /* [out] */ GXNormal __RPC_FAR *__RPC_FAR *pGXNormal,
            /* [out] */ ULONG __RPC_FAR *pceltFetched);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Skip )( 
            IGX3DEnumNormals __RPC_FAR * This,
            /* [in] */ ULONG celt);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Reset )( 
            IGX3DEnumNormals __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Clone )( 
            IGX3DEnumNormals __RPC_FAR * This,
            /* [out] */ IGX3DEnumNormals __RPC_FAR *__RPC_FAR *ppenum);
        
        END_INTERFACE
    } IGX3DEnumNormalsVtbl;

    interface IGX3DEnumNormals
    {
        CONST_VTBL struct IGX3DEnumNormalsVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IGX3DEnumNormals_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IGX3DEnumNormals_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IGX3DEnumNormals_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IGX3DEnumNormals_Next(This,celt,pGXNormal,pceltFetched)	\
    (This)->lpVtbl -> Next(This,celt,pGXNormal,pceltFetched)

#define IGX3DEnumNormals_Skip(This,celt)	\
    (This)->lpVtbl -> Skip(This,celt)

#define IGX3DEnumNormals_Reset(This)	\
    (This)->lpVtbl -> Reset(This)

#define IGX3DEnumNormals_Clone(This,ppenum)	\
    (This)->lpVtbl -> Clone(This,ppenum)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE IGX3DEnumNormals_Next_Proxy( 
    IGX3DEnumNormals __RPC_FAR * This,
    /* [in] */ ULONG celt,
    /* [out] */ GXNormal __RPC_FAR *__RPC_FAR *pGXNormal,
    /* [out] */ ULONG __RPC_FAR *pceltFetched);


void __RPC_STUB IGX3DEnumNormals_Next_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IGX3DEnumNormals_Skip_Proxy( 
    IGX3DEnumNormals __RPC_FAR * This,
    /* [in] */ ULONG celt);


void __RPC_STUB IGX3DEnumNormals_Skip_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IGX3DEnumNormals_Reset_Proxy( 
    IGX3DEnumNormals __RPC_FAR * This);


void __RPC_STUB IGX3DEnumNormals_Reset_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IGX3DEnumNormals_Clone_Proxy( 
    IGX3DEnumNormals __RPC_FAR * This,
    /* [out] */ IGX3DEnumNormals __RPC_FAR *__RPC_FAR *ppenum);


void __RPC_STUB IGX3DEnumNormals_Clone_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IGX3DEnumNormals_INTERFACE_DEFINED__ */


#ifndef __IGX3DEnumSurfaces_INTERFACE_DEFINED__
#define __IGX3DEnumSurfaces_INTERFACE_DEFINED__

/****************************************
 * Generated header for interface: IGX3DEnumSurfaces
 * at Tue Nov 23 05:02:16 1999
 * using MIDL 3.01.75
 ****************************************/
/* [uuid][object] */ 



EXTERN_C const IID IID_IGX3DEnumSurfaces;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    interface DECLSPEC_UUID("8335e67b-ab3b-11ce-8468-0000b468276b")
    IGX3DEnumSurfaces : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE Next( 
            /* [in] */ ULONG celt,
            /* [out] */ IGX3DSurface __RPC_FAR *__RPC_FAR *pIGXSurface,
            /* [out] */ ULONG __RPC_FAR *pceltFetched) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Skip( 
            /* [in] */ ULONG celt) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Reset( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Clone( 
            /* [out] */ IGX3DEnumSurfaces __RPC_FAR *__RPC_FAR *ppenum) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IGX3DEnumSurfacesVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            IGX3DEnumSurfaces __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            IGX3DEnumSurfaces __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            IGX3DEnumSurfaces __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Next )( 
            IGX3DEnumSurfaces __RPC_FAR * This,
            /* [in] */ ULONG celt,
            /* [out] */ IGX3DSurface __RPC_FAR *__RPC_FAR *pIGXSurface,
            /* [out] */ ULONG __RPC_FAR *pceltFetched);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Skip )( 
            IGX3DEnumSurfaces __RPC_FAR * This,
            /* [in] */ ULONG celt);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Reset )( 
            IGX3DEnumSurfaces __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Clone )( 
            IGX3DEnumSurfaces __RPC_FAR * This,
            /* [out] */ IGX3DEnumSurfaces __RPC_FAR *__RPC_FAR *ppenum);
        
        END_INTERFACE
    } IGX3DEnumSurfacesVtbl;

    interface IGX3DEnumSurfaces
    {
        CONST_VTBL struct IGX3DEnumSurfacesVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IGX3DEnumSurfaces_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IGX3DEnumSurfaces_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IGX3DEnumSurfaces_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IGX3DEnumSurfaces_Next(This,celt,pIGXSurface,pceltFetched)	\
    (This)->lpVtbl -> Next(This,celt,pIGXSurface,pceltFetched)

#define IGX3DEnumSurfaces_Skip(This,celt)	\
    (This)->lpVtbl -> Skip(This,celt)

#define IGX3DEnumSurfaces_Reset(This)	\
    (This)->lpVtbl -> Reset(This)

#define IGX3DEnumSurfaces_Clone(This,ppenum)	\
    (This)->lpVtbl -> Clone(This,ppenum)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE IGX3DEnumSurfaces_Next_Proxy( 
    IGX3DEnumSurfaces __RPC_FAR * This,
    /* [in] */ ULONG celt,
    /* [out] */ IGX3DSurface __RPC_FAR *__RPC_FAR *pIGXSurface,
    /* [out] */ ULONG __RPC_FAR *pceltFetched);


void __RPC_STUB IGX3DEnumSurfaces_Next_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IGX3DEnumSurfaces_Skip_Proxy( 
    IGX3DEnumSurfaces __RPC_FAR * This,
    /* [in] */ ULONG celt);


void __RPC_STUB IGX3DEnumSurfaces_Skip_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IGX3DEnumSurfaces_Reset_Proxy( 
    IGX3DEnumSurfaces __RPC_FAR * This);


void __RPC_STUB IGX3DEnumSurfaces_Reset_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IGX3DEnumSurfaces_Clone_Proxy( 
    IGX3DEnumSurfaces __RPC_FAR * This,
    /* [out] */ IGX3DEnumSurfaces __RPC_FAR *__RPC_FAR *ppenum);


void __RPC_STUB IGX3DEnumSurfaces_Clone_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IGX3DEnumSurfaces_INTERFACE_DEFINED__ */


#ifndef __IGX3DEnumSurfaceMaps_INTERFACE_DEFINED__
#define __IGX3DEnumSurfaceMaps_INTERFACE_DEFINED__

/****************************************
 * Generated header for interface: IGX3DEnumSurfaceMaps
 * at Tue Nov 23 05:02:16 1999
 * using MIDL 3.01.75
 ****************************************/
/* [uuid][object] */ 



EXTERN_C const IID IID_IGX3DEnumSurfaceMaps;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    interface DECLSPEC_UUID("8335e67c-ab3b-11ce-8468-0000b468276b")
    IGX3DEnumSurfaceMaps : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE Next( 
            /* [in] */ ULONG celt,
            /* [out] */ IGX3DSurfaceMap __RPC_FAR *__RPC_FAR *pIGXSurfaceMap,
            /* [out] */ ULONG __RPC_FAR *pceltFetched) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Skip( 
            /* [in] */ ULONG celt) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Reset( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Clone( 
            /* [out] */ IGX3DEnumSurfaceMaps __RPC_FAR *__RPC_FAR *ppenum) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IGX3DEnumSurfaceMapsVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            IGX3DEnumSurfaceMaps __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            IGX3DEnumSurfaceMaps __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            IGX3DEnumSurfaceMaps __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Next )( 
            IGX3DEnumSurfaceMaps __RPC_FAR * This,
            /* [in] */ ULONG celt,
            /* [out] */ IGX3DSurfaceMap __RPC_FAR *__RPC_FAR *pIGXSurfaceMap,
            /* [out] */ ULONG __RPC_FAR *pceltFetched);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Skip )( 
            IGX3DEnumSurfaceMaps __RPC_FAR * This,
            /* [in] */ ULONG celt);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Reset )( 
            IGX3DEnumSurfaceMaps __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Clone )( 
            IGX3DEnumSurfaceMaps __RPC_FAR * This,
            /* [out] */ IGX3DEnumSurfaceMaps __RPC_FAR *__RPC_FAR *ppenum);
        
        END_INTERFACE
    } IGX3DEnumSurfaceMapsVtbl;

    interface IGX3DEnumSurfaceMaps
    {
        CONST_VTBL struct IGX3DEnumSurfaceMapsVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IGX3DEnumSurfaceMaps_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IGX3DEnumSurfaceMaps_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IGX3DEnumSurfaceMaps_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IGX3DEnumSurfaceMaps_Next(This,celt,pIGXSurfaceMap,pceltFetched)	\
    (This)->lpVtbl -> Next(This,celt,pIGXSurfaceMap,pceltFetched)

#define IGX3DEnumSurfaceMaps_Skip(This,celt)	\
    (This)->lpVtbl -> Skip(This,celt)

#define IGX3DEnumSurfaceMaps_Reset(This)	\
    (This)->lpVtbl -> Reset(This)

#define IGX3DEnumSurfaceMaps_Clone(This,ppenum)	\
    (This)->lpVtbl -> Clone(This,ppenum)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE IGX3DEnumSurfaceMaps_Next_Proxy( 
    IGX3DEnumSurfaceMaps __RPC_FAR * This,
    /* [in] */ ULONG celt,
    /* [out] */ IGX3DSurfaceMap __RPC_FAR *__RPC_FAR *pIGXSurfaceMap,
    /* [out] */ ULONG __RPC_FAR *pceltFetched);


void __RPC_STUB IGX3DEnumSurfaceMaps_Next_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IGX3DEnumSurfaceMaps_Skip_Proxy( 
    IGX3DEnumSurfaceMaps __RPC_FAR * This,
    /* [in] */ ULONG celt);


void __RPC_STUB IGX3DEnumSurfaceMaps_Skip_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IGX3DEnumSurfaceMaps_Reset_Proxy( 
    IGX3DEnumSurfaceMaps __RPC_FAR * This);


void __RPC_STUB IGX3DEnumSurfaceMaps_Reset_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IGX3DEnumSurfaceMaps_Clone_Proxy( 
    IGX3DEnumSurfaceMaps __RPC_FAR * This,
    /* [out] */ IGX3DEnumSurfaceMaps __RPC_FAR *__RPC_FAR *ppenum);


void __RPC_STUB IGX3DEnumSurfaceMaps_Clone_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IGX3DEnumSurfaceMaps_INTERFACE_DEFINED__ */


#ifndef __IGX3DScene_INTERFACE_DEFINED__
#define __IGX3DScene_INTERFACE_DEFINED__

/****************************************
 * Generated header for interface: IGX3DScene
 * at Tue Nov 23 05:02:16 1999
 * using MIDL 3.01.75
 ****************************************/
/* [local][uuid][object] */ 



EXTERN_C const IID IID_IGX3DScene;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    interface DECLSPEC_UUID("8335e676-ab3b-11ce-8468-0000b468276b")
    IGX3DScene : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE Create3DScene( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE AllocObjectArray( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE AllocSurfaceArray( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE AllocSurfaceMapArray( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetMaxObjects( 
            /* [in] */ DWORD MaxObj) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetObjectCount( 
            /* [out] */ DWORD __RPC_FAR *OCount) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetEnumObjects( 
            /* [out] */ IGX3DEnumObjects __RPC_FAR *__RPC_FAR *pIGXObj) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetObjectList( 
            /* [out] */ IGX3DObject __RPC_FAR *__RPC_FAR *__RPC_FAR *GXObj) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE InsertObject( 
            /* [in] */ IGX3DObject __RPC_FAR *GXObj) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetMaxSurfaces( 
            /* [in] */ DWORD SCount) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetSurfaceCount( 
            /* [in] */ DWORD __RPC_FAR *SCount) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetEnumSurfaces( 
            /* [out] */ IGX3DEnumSurfaces __RPC_FAR *__RPC_FAR *pEnumSurf) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetSurfaceList( 
            /* [out] */ IGX3DSurface __RPC_FAR *__RPC_FAR *__RPC_FAR *SList) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE InsertSurface( 
            /* [in] */ IGX3DSurface __RPC_FAR *Surf,
            /* [out] */ DWORD __RPC_FAR *SIndex) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetMaxSurfaceMaps( 
            /* [in] */ DWORD MCount) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetSurfaceMapCount( 
            /* [in] */ DWORD __RPC_FAR *MCount) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetEnumSurfaceMaps( 
            /* [out] */ IGX3DEnumSurfaceMaps __RPC_FAR *__RPC_FAR *pEnumMap) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetSurfaceMapList( 
            /* [out] */ IGX3DSurfaceMap __RPC_FAR *__RPC_FAR *__RPC_FAR *MList) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE InsertSurfaceMap( 
            /* [in] */ IGX3DSurfaceMap __RPC_FAR *SMap,
            /* [out] */ DWORD __RPC_FAR *MIndex) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetWorldScale( 
            /* [in] */ GXCoords __RPC_FAR *Scale) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetWorldScale( 
            /* [out] */ GXCoords __RPC_FAR *Scale) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE NormalizeScene( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE CombineObjects( 
            /* [out] */ IGX3DScene __RPC_FAR *__RPC_FAR *pIGXScene) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IGX3DSceneVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            IGX3DScene __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            IGX3DScene __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            IGX3DScene __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Create3DScene )( 
            IGX3DScene __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *AllocObjectArray )( 
            IGX3DScene __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *AllocSurfaceArray )( 
            IGX3DScene __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *AllocSurfaceMapArray )( 
            IGX3DScene __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetMaxObjects )( 
            IGX3DScene __RPC_FAR * This,
            /* [in] */ DWORD MaxObj);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetObjectCount )( 
            IGX3DScene __RPC_FAR * This,
            /* [out] */ DWORD __RPC_FAR *OCount);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetEnumObjects )( 
            IGX3DScene __RPC_FAR * This,
            /* [out] */ IGX3DEnumObjects __RPC_FAR *__RPC_FAR *pIGXObj);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetObjectList )( 
            IGX3DScene __RPC_FAR * This,
            /* [out] */ IGX3DObject __RPC_FAR *__RPC_FAR *__RPC_FAR *GXObj);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *InsertObject )( 
            IGX3DScene __RPC_FAR * This,
            /* [in] */ IGX3DObject __RPC_FAR *GXObj);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetMaxSurfaces )( 
            IGX3DScene __RPC_FAR * This,
            /* [in] */ DWORD SCount);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetSurfaceCount )( 
            IGX3DScene __RPC_FAR * This,
            /* [in] */ DWORD __RPC_FAR *SCount);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetEnumSurfaces )( 
            IGX3DScene __RPC_FAR * This,
            /* [out] */ IGX3DEnumSurfaces __RPC_FAR *__RPC_FAR *pEnumSurf);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetSurfaceList )( 
            IGX3DScene __RPC_FAR * This,
            /* [out] */ IGX3DSurface __RPC_FAR *__RPC_FAR *__RPC_FAR *SList);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *InsertSurface )( 
            IGX3DScene __RPC_FAR * This,
            /* [in] */ IGX3DSurface __RPC_FAR *Surf,
            /* [out] */ DWORD __RPC_FAR *SIndex);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetMaxSurfaceMaps )( 
            IGX3DScene __RPC_FAR * This,
            /* [in] */ DWORD MCount);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetSurfaceMapCount )( 
            IGX3DScene __RPC_FAR * This,
            /* [in] */ DWORD __RPC_FAR *MCount);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetEnumSurfaceMaps )( 
            IGX3DScene __RPC_FAR * This,
            /* [out] */ IGX3DEnumSurfaceMaps __RPC_FAR *__RPC_FAR *pEnumMap);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetSurfaceMapList )( 
            IGX3DScene __RPC_FAR * This,
            /* [out] */ IGX3DSurfaceMap __RPC_FAR *__RPC_FAR *__RPC_FAR *MList);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *InsertSurfaceMap )( 
            IGX3DScene __RPC_FAR * This,
            /* [in] */ IGX3DSurfaceMap __RPC_FAR *SMap,
            /* [out] */ DWORD __RPC_FAR *MIndex);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetWorldScale )( 
            IGX3DScene __RPC_FAR * This,
            /* [in] */ GXCoords __RPC_FAR *Scale);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetWorldScale )( 
            IGX3DScene __RPC_FAR * This,
            /* [out] */ GXCoords __RPC_FAR *Scale);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *NormalizeScene )( 
            IGX3DScene __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *CombineObjects )( 
            IGX3DScene __RPC_FAR * This,
            /* [out] */ IGX3DScene __RPC_FAR *__RPC_FAR *pIGXScene);
        
        END_INTERFACE
    } IGX3DSceneVtbl;

    interface IGX3DScene
    {
        CONST_VTBL struct IGX3DSceneVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IGX3DScene_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IGX3DScene_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IGX3DScene_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IGX3DScene_Create3DScene(This)	\
    (This)->lpVtbl -> Create3DScene(This)

#define IGX3DScene_AllocObjectArray(This)	\
    (This)->lpVtbl -> AllocObjectArray(This)

#define IGX3DScene_AllocSurfaceArray(This)	\
    (This)->lpVtbl -> AllocSurfaceArray(This)

#define IGX3DScene_AllocSurfaceMapArray(This)	\
    (This)->lpVtbl -> AllocSurfaceMapArray(This)

#define IGX3DScene_SetMaxObjects(This,MaxObj)	\
    (This)->lpVtbl -> SetMaxObjects(This,MaxObj)

#define IGX3DScene_GetObjectCount(This,OCount)	\
    (This)->lpVtbl -> GetObjectCount(This,OCount)

#define IGX3DScene_GetEnumObjects(This,pIGXObj)	\
    (This)->lpVtbl -> GetEnumObjects(This,pIGXObj)

#define IGX3DScene_GetObjectList(This,GXObj)	\
    (This)->lpVtbl -> GetObjectList(This,GXObj)

#define IGX3DScene_InsertObject(This,GXObj)	\
    (This)->lpVtbl -> InsertObject(This,GXObj)

#define IGX3DScene_SetMaxSurfaces(This,SCount)	\
    (This)->lpVtbl -> SetMaxSurfaces(This,SCount)

#define IGX3DScene_GetSurfaceCount(This,SCount)	\
    (This)->lpVtbl -> GetSurfaceCount(This,SCount)

#define IGX3DScene_GetEnumSurfaces(This,pEnumSurf)	\
    (This)->lpVtbl -> GetEnumSurfaces(This,pEnumSurf)

#define IGX3DScene_GetSurfaceList(This,SList)	\
    (This)->lpVtbl -> GetSurfaceList(This,SList)

#define IGX3DScene_InsertSurface(This,Surf,SIndex)	\
    (This)->lpVtbl -> InsertSurface(This,Surf,SIndex)

#define IGX3DScene_SetMaxSurfaceMaps(This,MCount)	\
    (This)->lpVtbl -> SetMaxSurfaceMaps(This,MCount)

#define IGX3DScene_GetSurfaceMapCount(This,MCount)	\
    (This)->lpVtbl -> GetSurfaceMapCount(This,MCount)

#define IGX3DScene_GetEnumSurfaceMaps(This,pEnumMap)	\
    (This)->lpVtbl -> GetEnumSurfaceMaps(This,pEnumMap)

#define IGX3DScene_GetSurfaceMapList(This,MList)	\
    (This)->lpVtbl -> GetSurfaceMapList(This,MList)

#define IGX3DScene_InsertSurfaceMap(This,SMap,MIndex)	\
    (This)->lpVtbl -> InsertSurfaceMap(This,SMap,MIndex)

#define IGX3DScene_SetWorldScale(This,Scale)	\
    (This)->lpVtbl -> SetWorldScale(This,Scale)

#define IGX3DScene_GetWorldScale(This,Scale)	\
    (This)->lpVtbl -> GetWorldScale(This,Scale)

#define IGX3DScene_NormalizeScene(This)	\
    (This)->lpVtbl -> NormalizeScene(This)

#define IGX3DScene_CombineObjects(This,pIGXScene)	\
    (This)->lpVtbl -> CombineObjects(This,pIGXScene)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE IGX3DScene_Create3DScene_Proxy( 
    IGX3DScene __RPC_FAR * This);


void __RPC_STUB IGX3DScene_Create3DScene_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IGX3DScene_AllocObjectArray_Proxy( 
    IGX3DScene __RPC_FAR * This);


void __RPC_STUB IGX3DScene_AllocObjectArray_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IGX3DScene_AllocSurfaceArray_Proxy( 
    IGX3DScene __RPC_FAR * This);


void __RPC_STUB IGX3DScene_AllocSurfaceArray_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IGX3DScene_AllocSurfaceMapArray_Proxy( 
    IGX3DScene __RPC_FAR * This);


void __RPC_STUB IGX3DScene_AllocSurfaceMapArray_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IGX3DScene_SetMaxObjects_Proxy( 
    IGX3DScene __RPC_FAR * This,
    /* [in] */ DWORD MaxObj);


void __RPC_STUB IGX3DScene_SetMaxObjects_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IGX3DScene_GetObjectCount_Proxy( 
    IGX3DScene __RPC_FAR * This,
    /* [out] */ DWORD __RPC_FAR *OCount);


void __RPC_STUB IGX3DScene_GetObjectCount_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IGX3DScene_GetEnumObjects_Proxy( 
    IGX3DScene __RPC_FAR * This,
    /* [out] */ IGX3DEnumObjects __RPC_FAR *__RPC_FAR *pIGXObj);


void __RPC_STUB IGX3DScene_GetEnumObjects_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IGX3DScene_GetObjectList_Proxy( 
    IGX3DScene __RPC_FAR * This,
    /* [out] */ IGX3DObject __RPC_FAR *__RPC_FAR *__RPC_FAR *GXObj);


void __RPC_STUB IGX3DScene_GetObjectList_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IGX3DScene_InsertObject_Proxy( 
    IGX3DScene __RPC_FAR * This,
    /* [in] */ IGX3DObject __RPC_FAR *GXObj);


void __RPC_STUB IGX3DScene_InsertObject_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IGX3DScene_SetMaxSurfaces_Proxy( 
    IGX3DScene __RPC_FAR * This,
    /* [in] */ DWORD SCount);


void __RPC_STUB IGX3DScene_SetMaxSurfaces_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IGX3DScene_GetSurfaceCount_Proxy( 
    IGX3DScene __RPC_FAR * This,
    /* [in] */ DWORD __RPC_FAR *SCount);


void __RPC_STUB IGX3DScene_GetSurfaceCount_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IGX3DScene_GetEnumSurfaces_Proxy( 
    IGX3DScene __RPC_FAR * This,
    /* [out] */ IGX3DEnumSurfaces __RPC_FAR *__RPC_FAR *pEnumSurf);


void __RPC_STUB IGX3DScene_GetEnumSurfaces_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IGX3DScene_GetSurfaceList_Proxy( 
    IGX3DScene __RPC_FAR * This,
    /* [out] */ IGX3DSurface __RPC_FAR *__RPC_FAR *__RPC_FAR *SList);


void __RPC_STUB IGX3DScene_GetSurfaceList_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IGX3DScene_InsertSurface_Proxy( 
    IGX3DScene __RPC_FAR * This,
    /* [in] */ IGX3DSurface __RPC_FAR *Surf,
    /* [out] */ DWORD __RPC_FAR *SIndex);


void __RPC_STUB IGX3DScene_InsertSurface_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IGX3DScene_SetMaxSurfaceMaps_Proxy( 
    IGX3DScene __RPC_FAR * This,
    /* [in] */ DWORD MCount);


void __RPC_STUB IGX3DScene_SetMaxSurfaceMaps_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IGX3DScene_GetSurfaceMapCount_Proxy( 
    IGX3DScene __RPC_FAR * This,
    /* [in] */ DWORD __RPC_FAR *MCount);


void __RPC_STUB IGX3DScene_GetSurfaceMapCount_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IGX3DScene_GetEnumSurfaceMaps_Proxy( 
    IGX3DScene __RPC_FAR * This,
    /* [out] */ IGX3DEnumSurfaceMaps __RPC_FAR *__RPC_FAR *pEnumMap);


void __RPC_STUB IGX3DScene_GetEnumSurfaceMaps_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IGX3DScene_GetSurfaceMapList_Proxy( 
    IGX3DScene __RPC_FAR * This,
    /* [out] */ IGX3DSurfaceMap __RPC_FAR *__RPC_FAR *__RPC_FAR *MList);


void __RPC_STUB IGX3DScene_GetSurfaceMapList_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IGX3DScene_InsertSurfaceMap_Proxy( 
    IGX3DScene __RPC_FAR * This,
    /* [in] */ IGX3DSurfaceMap __RPC_FAR *SMap,
    /* [out] */ DWORD __RPC_FAR *MIndex);


void __RPC_STUB IGX3DScene_InsertSurfaceMap_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IGX3DScene_SetWorldScale_Proxy( 
    IGX3DScene __RPC_FAR * This,
    /* [in] */ GXCoords __RPC_FAR *Scale);


void __RPC_STUB IGX3DScene_SetWorldScale_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IGX3DScene_GetWorldScale_Proxy( 
    IGX3DScene __RPC_FAR * This,
    /* [out] */ GXCoords __RPC_FAR *Scale);


void __RPC_STUB IGX3DScene_GetWorldScale_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IGX3DScene_NormalizeScene_Proxy( 
    IGX3DScene __RPC_FAR * This);


void __RPC_STUB IGX3DScene_NormalizeScene_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IGX3DScene_CombineObjects_Proxy( 
    IGX3DScene __RPC_FAR * This,
    /* [out] */ IGX3DScene __RPC_FAR *__RPC_FAR *pIGXScene);


void __RPC_STUB IGX3DScene_CombineObjects_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IGX3DScene_INTERFACE_DEFINED__ */


#ifndef __IGX3DObject_INTERFACE_DEFINED__
#define __IGX3DObject_INTERFACE_DEFINED__

/****************************************
 * Generated header for interface: IGX3DObject
 * at Tue Nov 23 05:02:16 1999
 * using MIDL 3.01.75
 ****************************************/
/* [local][uuid][object] */ 



EXTERN_C const IID IID_IGX3DObject;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    interface DECLSPEC_UUID("8335e677-ab3b-11ce-8468-0000b468276b")
    IGX3DObject : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE Create3DObject( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE AllocVertexArray( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE AllocPolygonArray( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetMaxPolygons( 
            /* [in] */ DWORD PCount) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetPolygonCount( 
            /* [out] */ DWORD __RPC_FAR *PCount) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetEnumPolygons( 
            /* [out] */ IGX3DEnumPolygons __RPC_FAR *__RPC_FAR *pEnumPoly) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetPolygonList( 
            /* [out] */ GXPolygon __RPC_FAR *__RPC_FAR *__RPC_FAR *PList) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE InsertPolygonV( 
            /* [in] */ WORD VCount,
            /* [in] */ GXVertex __RPC_FAR *__RPC_FAR *VList) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE InsertPolygonI( 
            /* [in] */ DWORD VCount,
            /* [in] */ BYTE BytesPerIndex,
            /* [in] */ BYTE __RPC_FAR *VidxList,
            /* [in] */ DWORD SIndex) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetMaxVertices( 
            /* [in] */ DWORD VCount) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetVertexCount( 
            /* [out] */ DWORD __RPC_FAR *VCount) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetEnumVertices( 
            /* [out] */ IGX3DEnumVertices __RPC_FAR *__RPC_FAR *pEnumVert) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetVertexList( 
            /* [out] */ GXVertex __RPC_FAR *__RPC_FAR *__RPC_FAR *VList) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE InsertVertex( 
            /* [in] */ GXVertex Vert,
            /* [out] */ DWORD __RPC_FAR *VIndex) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetWorldScale( 
            /* [in] */ GXCoords __RPC_FAR *Scale) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetWorldAngle( 
            /* [in] */ GXCoords __RPC_FAR *Angle) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetWorldPosition( 
            /* [in] */ GXCoords __RPC_FAR *Position) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetObjectName( 
            /* [in] */ unsigned char __RPC_FAR *ObjName) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetWorldScale( 
            /* [out] */ GXCoords __RPC_FAR *Scale) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetWorldAngle( 
            /* [out] */ GXCoords __RPC_FAR *Angle) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetWorldPosition( 
            /* [out] */ GXCoords __RPC_FAR *Position) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetObjectName( 
            /* [out] */ unsigned char __RPC_FAR *ObjName) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetParentIndex( 
            /* [out] */ DWORD __RPC_FAR *PIndex) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetParentIndex( 
            /* [in] */ DWORD PIndex) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetMaxCoords( 
            /* [out] */ GXCoords __RPC_FAR *MaxCoords) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetMinCoords( 
            /* [out] */ GXCoords __RPC_FAR *MinCoords) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetMaxNormals( 
            /* [in] */ DWORD NCount) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetNormalCount( 
            /* [out] */ DWORD __RPC_FAR *NCount) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetEnumNormals( 
            /* [out] */ IGX3DEnumNormals __RPC_FAR *__RPC_FAR *pEnumNormal) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetNormalList( 
            /* [out] */ GXNormal __RPC_FAR *__RPC_FAR *__RPC_FAR *NList) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE InsertNormal( 
            /* [in] */ GXNormal Norm,
            /* [out] */ DWORD __RPC_FAR *NIndex) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IGX3DObjectVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            IGX3DObject __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            IGX3DObject __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            IGX3DObject __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Create3DObject )( 
            IGX3DObject __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *AllocVertexArray )( 
            IGX3DObject __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *AllocPolygonArray )( 
            IGX3DObject __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetMaxPolygons )( 
            IGX3DObject __RPC_FAR * This,
            /* [in] */ DWORD PCount);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetPolygonCount )( 
            IGX3DObject __RPC_FAR * This,
            /* [out] */ DWORD __RPC_FAR *PCount);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetEnumPolygons )( 
            IGX3DObject __RPC_FAR * This,
            /* [out] */ IGX3DEnumPolygons __RPC_FAR *__RPC_FAR *pEnumPoly);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetPolygonList )( 
            IGX3DObject __RPC_FAR * This,
            /* [out] */ GXPolygon __RPC_FAR *__RPC_FAR *__RPC_FAR *PList);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *InsertPolygonV )( 
            IGX3DObject __RPC_FAR * This,
            /* [in] */ WORD VCount,
            /* [in] */ GXVertex __RPC_FAR *__RPC_FAR *VList);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *InsertPolygonI )( 
            IGX3DObject __RPC_FAR * This,
            /* [in] */ DWORD VCount,
            /* [in] */ BYTE BytesPerIndex,
            /* [in] */ BYTE __RPC_FAR *VidxList,
            /* [in] */ DWORD SIndex);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetMaxVertices )( 
            IGX3DObject __RPC_FAR * This,
            /* [in] */ DWORD VCount);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetVertexCount )( 
            IGX3DObject __RPC_FAR * This,
            /* [out] */ DWORD __RPC_FAR *VCount);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetEnumVertices )( 
            IGX3DObject __RPC_FAR * This,
            /* [out] */ IGX3DEnumVertices __RPC_FAR *__RPC_FAR *pEnumVert);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetVertexList )( 
            IGX3DObject __RPC_FAR * This,
            /* [out] */ GXVertex __RPC_FAR *__RPC_FAR *__RPC_FAR *VList);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *InsertVertex )( 
            IGX3DObject __RPC_FAR * This,
            /* [in] */ GXVertex Vert,
            /* [out] */ DWORD __RPC_FAR *VIndex);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetWorldScale )( 
            IGX3DObject __RPC_FAR * This,
            /* [in] */ GXCoords __RPC_FAR *Scale);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetWorldAngle )( 
            IGX3DObject __RPC_FAR * This,
            /* [in] */ GXCoords __RPC_FAR *Angle);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetWorldPosition )( 
            IGX3DObject __RPC_FAR * This,
            /* [in] */ GXCoords __RPC_FAR *Position);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetObjectName )( 
            IGX3DObject __RPC_FAR * This,
            /* [in] */ unsigned char __RPC_FAR *ObjName);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetWorldScale )( 
            IGX3DObject __RPC_FAR * This,
            /* [out] */ GXCoords __RPC_FAR *Scale);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetWorldAngle )( 
            IGX3DObject __RPC_FAR * This,
            /* [out] */ GXCoords __RPC_FAR *Angle);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetWorldPosition )( 
            IGX3DObject __RPC_FAR * This,
            /* [out] */ GXCoords __RPC_FAR *Position);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetObjectName )( 
            IGX3DObject __RPC_FAR * This,
            /* [out] */ unsigned char __RPC_FAR *ObjName);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetParentIndex )( 
            IGX3DObject __RPC_FAR * This,
            /* [out] */ DWORD __RPC_FAR *PIndex);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetParentIndex )( 
            IGX3DObject __RPC_FAR * This,
            /* [in] */ DWORD PIndex);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetMaxCoords )( 
            IGX3DObject __RPC_FAR * This,
            /* [out] */ GXCoords __RPC_FAR *MaxCoords);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetMinCoords )( 
            IGX3DObject __RPC_FAR * This,
            /* [out] */ GXCoords __RPC_FAR *MinCoords);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetMaxNormals )( 
            IGX3DObject __RPC_FAR * This,
            /* [in] */ DWORD NCount);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetNormalCount )( 
            IGX3DObject __RPC_FAR * This,
            /* [out] */ DWORD __RPC_FAR *NCount);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetEnumNormals )( 
            IGX3DObject __RPC_FAR * This,
            /* [out] */ IGX3DEnumNormals __RPC_FAR *__RPC_FAR *pEnumNormal);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetNormalList )( 
            IGX3DObject __RPC_FAR * This,
            /* [out] */ GXNormal __RPC_FAR *__RPC_FAR *__RPC_FAR *NList);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *InsertNormal )( 
            IGX3DObject __RPC_FAR * This,
            /* [in] */ GXNormal Norm,
            /* [out] */ DWORD __RPC_FAR *NIndex);
        
        END_INTERFACE
    } IGX3DObjectVtbl;

    interface IGX3DObject
    {
        CONST_VTBL struct IGX3DObjectVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IGX3DObject_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IGX3DObject_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IGX3DObject_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IGX3DObject_Create3DObject(This)	\
    (This)->lpVtbl -> Create3DObject(This)

#define IGX3DObject_AllocVertexArray(This)	\
    (This)->lpVtbl -> AllocVertexArray(This)

#define IGX3DObject_AllocPolygonArray(This)	\
    (This)->lpVtbl -> AllocPolygonArray(This)

#define IGX3DObject_SetMaxPolygons(This,PCount)	\
    (This)->lpVtbl -> SetMaxPolygons(This,PCount)

#define IGX3DObject_GetPolygonCount(This,PCount)	\
    (This)->lpVtbl -> GetPolygonCount(This,PCount)

#define IGX3DObject_GetEnumPolygons(This,pEnumPoly)	\
    (This)->lpVtbl -> GetEnumPolygons(This,pEnumPoly)

#define IGX3DObject_GetPolygonList(This,PList)	\
    (This)->lpVtbl -> GetPolygonList(This,PList)

#define IGX3DObject_InsertPolygonV(This,VCount,VList)	\
    (This)->lpVtbl -> InsertPolygonV(This,VCount,VList)

#define IGX3DObject_InsertPolygonI(This,VCount,BytesPerIndex,VidxList,SIndex)	\
    (This)->lpVtbl -> InsertPolygonI(This,VCount,BytesPerIndex,VidxList,SIndex)

#define IGX3DObject_SetMaxVertices(This,VCount)	\
    (This)->lpVtbl -> SetMaxVertices(This,VCount)

#define IGX3DObject_GetVertexCount(This,VCount)	\
    (This)->lpVtbl -> GetVertexCount(This,VCount)

#define IGX3DObject_GetEnumVertices(This,pEnumVert)	\
    (This)->lpVtbl -> GetEnumVertices(This,pEnumVert)

#define IGX3DObject_GetVertexList(This,VList)	\
    (This)->lpVtbl -> GetVertexList(This,VList)

#define IGX3DObject_InsertVertex(This,Vert,VIndex)	\
    (This)->lpVtbl -> InsertVertex(This,Vert,VIndex)

#define IGX3DObject_SetWorldScale(This,Scale)	\
    (This)->lpVtbl -> SetWorldScale(This,Scale)

#define IGX3DObject_SetWorldAngle(This,Angle)	\
    (This)->lpVtbl -> SetWorldAngle(This,Angle)

#define IGX3DObject_SetWorldPosition(This,Position)	\
    (This)->lpVtbl -> SetWorldPosition(This,Position)

#define IGX3DObject_SetObjectName(This,ObjName)	\
    (This)->lpVtbl -> SetObjectName(This,ObjName)

#define IGX3DObject_GetWorldScale(This,Scale)	\
    (This)->lpVtbl -> GetWorldScale(This,Scale)

#define IGX3DObject_GetWorldAngle(This,Angle)	\
    (This)->lpVtbl -> GetWorldAngle(This,Angle)

#define IGX3DObject_GetWorldPosition(This,Position)	\
    (This)->lpVtbl -> GetWorldPosition(This,Position)

#define IGX3DObject_GetObjectName(This,ObjName)	\
    (This)->lpVtbl -> GetObjectName(This,ObjName)

#define IGX3DObject_GetParentIndex(This,PIndex)	\
    (This)->lpVtbl -> GetParentIndex(This,PIndex)

#define IGX3DObject_SetParentIndex(This,PIndex)	\
    (This)->lpVtbl -> SetParentIndex(This,PIndex)

#define IGX3DObject_GetMaxCoords(This,MaxCoords)	\
    (This)->lpVtbl -> GetMaxCoords(This,MaxCoords)

#define IGX3DObject_GetMinCoords(This,MinCoords)	\
    (This)->lpVtbl -> GetMinCoords(This,MinCoords)

#define IGX3DObject_SetMaxNormals(This,NCount)	\
    (This)->lpVtbl -> SetMaxNormals(This,NCount)

#define IGX3DObject_GetNormalCount(This,NCount)	\
    (This)->lpVtbl -> GetNormalCount(This,NCount)

#define IGX3DObject_GetEnumNormals(This,pEnumNormal)	\
    (This)->lpVtbl -> GetEnumNormals(This,pEnumNormal)

#define IGX3DObject_GetNormalList(This,NList)	\
    (This)->lpVtbl -> GetNormalList(This,NList)

#define IGX3DObject_InsertNormal(This,Norm,NIndex)	\
    (This)->lpVtbl -> InsertNormal(This,Norm,NIndex)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE IGX3DObject_Create3DObject_Proxy( 
    IGX3DObject __RPC_FAR * This);


void __RPC_STUB IGX3DObject_Create3DObject_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IGX3DObject_AllocVertexArray_Proxy( 
    IGX3DObject __RPC_FAR * This);


void __RPC_STUB IGX3DObject_AllocVertexArray_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IGX3DObject_AllocPolygonArray_Proxy( 
    IGX3DObject __RPC_FAR * This);


void __RPC_STUB IGX3DObject_AllocPolygonArray_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IGX3DObject_SetMaxPolygons_Proxy( 
    IGX3DObject __RPC_FAR * This,
    /* [in] */ DWORD PCount);


void __RPC_STUB IGX3DObject_SetMaxPolygons_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IGX3DObject_GetPolygonCount_Proxy( 
    IGX3DObject __RPC_FAR * This,
    /* [out] */ DWORD __RPC_FAR *PCount);


void __RPC_STUB IGX3DObject_GetPolygonCount_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IGX3DObject_GetEnumPolygons_Proxy( 
    IGX3DObject __RPC_FAR * This,
    /* [out] */ IGX3DEnumPolygons __RPC_FAR *__RPC_FAR *pEnumPoly);


void __RPC_STUB IGX3DObject_GetEnumPolygons_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IGX3DObject_GetPolygonList_Proxy( 
    IGX3DObject __RPC_FAR * This,
    /* [out] */ GXPolygon __RPC_FAR *__RPC_FAR *__RPC_FAR *PList);


void __RPC_STUB IGX3DObject_GetPolygonList_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IGX3DObject_InsertPolygonV_Proxy( 
    IGX3DObject __RPC_FAR * This,
    /* [in] */ WORD VCount,
    /* [in] */ GXVertex __RPC_FAR *__RPC_FAR *VList);


void __RPC_STUB IGX3DObject_InsertPolygonV_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IGX3DObject_InsertPolygonI_Proxy( 
    IGX3DObject __RPC_FAR * This,
    /* [in] */ DWORD VCount,
    /* [in] */ BYTE BytesPerIndex,
    /* [in] */ BYTE __RPC_FAR *VidxList,
    /* [in] */ DWORD SIndex);


void __RPC_STUB IGX3DObject_InsertPolygonI_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IGX3DObject_SetMaxVertices_Proxy( 
    IGX3DObject __RPC_FAR * This,
    /* [in] */ DWORD VCount);


void __RPC_STUB IGX3DObject_SetMaxVertices_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IGX3DObject_GetVertexCount_Proxy( 
    IGX3DObject __RPC_FAR * This,
    /* [out] */ DWORD __RPC_FAR *VCount);


void __RPC_STUB IGX3DObject_GetVertexCount_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IGX3DObject_GetEnumVertices_Proxy( 
    IGX3DObject __RPC_FAR * This,
    /* [out] */ IGX3DEnumVertices __RPC_FAR *__RPC_FAR *pEnumVert);


void __RPC_STUB IGX3DObject_GetEnumVertices_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IGX3DObject_GetVertexList_Proxy( 
    IGX3DObject __RPC_FAR * This,
    /* [out] */ GXVertex __RPC_FAR *__RPC_FAR *__RPC_FAR *VList);


void __RPC_STUB IGX3DObject_GetVertexList_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IGX3DObject_InsertVertex_Proxy( 
    IGX3DObject __RPC_FAR * This,
    /* [in] */ GXVertex Vert,
    /* [out] */ DWORD __RPC_FAR *VIndex);


void __RPC_STUB IGX3DObject_InsertVertex_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IGX3DObject_SetWorldScale_Proxy( 
    IGX3DObject __RPC_FAR * This,
    /* [in] */ GXCoords __RPC_FAR *Scale);


void __RPC_STUB IGX3DObject_SetWorldScale_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IGX3DObject_SetWorldAngle_Proxy( 
    IGX3DObject __RPC_FAR * This,
    /* [in] */ GXCoords __RPC_FAR *Angle);


void __RPC_STUB IGX3DObject_SetWorldAngle_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IGX3DObject_SetWorldPosition_Proxy( 
    IGX3DObject __RPC_FAR * This,
    /* [in] */ GXCoords __RPC_FAR *Position);


void __RPC_STUB IGX3DObject_SetWorldPosition_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IGX3DObject_SetObjectName_Proxy( 
    IGX3DObject __RPC_FAR * This,
    /* [in] */ unsigned char __RPC_FAR *ObjName);


void __RPC_STUB IGX3DObject_SetObjectName_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IGX3DObject_GetWorldScale_Proxy( 
    IGX3DObject __RPC_FAR * This,
    /* [out] */ GXCoords __RPC_FAR *Scale);


void __RPC_STUB IGX3DObject_GetWorldScale_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IGX3DObject_GetWorldAngle_Proxy( 
    IGX3DObject __RPC_FAR * This,
    /* [out] */ GXCoords __RPC_FAR *Angle);


void __RPC_STUB IGX3DObject_GetWorldAngle_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IGX3DObject_GetWorldPosition_Proxy( 
    IGX3DObject __RPC_FAR * This,
    /* [out] */ GXCoords __RPC_FAR *Position);


void __RPC_STUB IGX3DObject_GetWorldPosition_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IGX3DObject_GetObjectName_Proxy( 
    IGX3DObject __RPC_FAR * This,
    /* [out] */ unsigned char __RPC_FAR *ObjName);


void __RPC_STUB IGX3DObject_GetObjectName_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IGX3DObject_GetParentIndex_Proxy( 
    IGX3DObject __RPC_FAR * This,
    /* [out] */ DWORD __RPC_FAR *PIndex);


void __RPC_STUB IGX3DObject_GetParentIndex_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IGX3DObject_SetParentIndex_Proxy( 
    IGX3DObject __RPC_FAR * This,
    /* [in] */ DWORD PIndex);


void __RPC_STUB IGX3DObject_SetParentIndex_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IGX3DObject_GetMaxCoords_Proxy( 
    IGX3DObject __RPC_FAR * This,
    /* [out] */ GXCoords __RPC_FAR *MaxCoords);


void __RPC_STUB IGX3DObject_GetMaxCoords_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IGX3DObject_GetMinCoords_Proxy( 
    IGX3DObject __RPC_FAR * This,
    /* [out] */ GXCoords __RPC_FAR *MinCoords);


void __RPC_STUB IGX3DObject_GetMinCoords_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IGX3DObject_SetMaxNormals_Proxy( 
    IGX3DObject __RPC_FAR * This,
    /* [in] */ DWORD NCount);


void __RPC_STUB IGX3DObject_SetMaxNormals_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IGX3DObject_GetNormalCount_Proxy( 
    IGX3DObject __RPC_FAR * This,
    /* [out] */ DWORD __RPC_FAR *NCount);


void __RPC_STUB IGX3DObject_GetNormalCount_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IGX3DObject_GetEnumNormals_Proxy( 
    IGX3DObject __RPC_FAR * This,
    /* [out] */ IGX3DEnumNormals __RPC_FAR *__RPC_FAR *pEnumNormal);


void __RPC_STUB IGX3DObject_GetEnumNormals_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IGX3DObject_GetNormalList_Proxy( 
    IGX3DObject __RPC_FAR * This,
    /* [out] */ GXNormal __RPC_FAR *__RPC_FAR *__RPC_FAR *NList);


void __RPC_STUB IGX3DObject_GetNormalList_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IGX3DObject_InsertNormal_Proxy( 
    IGX3DObject __RPC_FAR * This,
    /* [in] */ GXNormal Norm,
    /* [out] */ DWORD __RPC_FAR *NIndex);


void __RPC_STUB IGX3DObject_InsertNormal_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IGX3DObject_INTERFACE_DEFINED__ */


#ifndef __IGX3DSurface_INTERFACE_DEFINED__
#define __IGX3DSurface_INTERFACE_DEFINED__

/****************************************
 * Generated header for interface: IGX3DSurface
 * at Tue Nov 23 05:02:16 1999
 * using MIDL 3.01.75
 ****************************************/
/* [local][uuid][object] */ 



EXTERN_C const IID IID_IGX3DSurface;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    interface DECLSPEC_UUID("8335e67e-ab3b-11ce-8468-0000b468276b")
    IGX3DSurface : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE GetAttributes( 
            /* [out] */ GXSurfaceAttrib __RPC_FAR *SurfaceAttrib) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetAttributes( 
            /* [in] */ GXSurfaceAttrib __RPC_FAR *SurfaceAttrib) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetMapCount( 
            /* [out] */ DWORD __RPC_FAR *MCount) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetMapIndices( 
            /* [out] */ DWORD __RPC_FAR *__RPC_FAR *MapIndexList) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE InsertMapIndex( 
            /* [in] */ DWORD MIndex) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IGX3DSurfaceVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            IGX3DSurface __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            IGX3DSurface __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            IGX3DSurface __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetAttributes )( 
            IGX3DSurface __RPC_FAR * This,
            /* [out] */ GXSurfaceAttrib __RPC_FAR *SurfaceAttrib);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetAttributes )( 
            IGX3DSurface __RPC_FAR * This,
            /* [in] */ GXSurfaceAttrib __RPC_FAR *SurfaceAttrib);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetMapCount )( 
            IGX3DSurface __RPC_FAR * This,
            /* [out] */ DWORD __RPC_FAR *MCount);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetMapIndices )( 
            IGX3DSurface __RPC_FAR * This,
            /* [out] */ DWORD __RPC_FAR *__RPC_FAR *MapIndexList);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *InsertMapIndex )( 
            IGX3DSurface __RPC_FAR * This,
            /* [in] */ DWORD MIndex);
        
        END_INTERFACE
    } IGX3DSurfaceVtbl;

    interface IGX3DSurface
    {
        CONST_VTBL struct IGX3DSurfaceVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IGX3DSurface_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IGX3DSurface_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IGX3DSurface_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IGX3DSurface_GetAttributes(This,SurfaceAttrib)	\
    (This)->lpVtbl -> GetAttributes(This,SurfaceAttrib)

#define IGX3DSurface_SetAttributes(This,SurfaceAttrib)	\
    (This)->lpVtbl -> SetAttributes(This,SurfaceAttrib)

#define IGX3DSurface_GetMapCount(This,MCount)	\
    (This)->lpVtbl -> GetMapCount(This,MCount)

#define IGX3DSurface_GetMapIndices(This,MapIndexList)	\
    (This)->lpVtbl -> GetMapIndices(This,MapIndexList)

#define IGX3DSurface_InsertMapIndex(This,MIndex)	\
    (This)->lpVtbl -> InsertMapIndex(This,MIndex)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE IGX3DSurface_GetAttributes_Proxy( 
    IGX3DSurface __RPC_FAR * This,
    /* [out] */ GXSurfaceAttrib __RPC_FAR *SurfaceAttrib);


void __RPC_STUB IGX3DSurface_GetAttributes_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IGX3DSurface_SetAttributes_Proxy( 
    IGX3DSurface __RPC_FAR * This,
    /* [in] */ GXSurfaceAttrib __RPC_FAR *SurfaceAttrib);


void __RPC_STUB IGX3DSurface_SetAttributes_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IGX3DSurface_GetMapCount_Proxy( 
    IGX3DSurface __RPC_FAR * This,
    /* [out] */ DWORD __RPC_FAR *MCount);


void __RPC_STUB IGX3DSurface_GetMapCount_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IGX3DSurface_GetMapIndices_Proxy( 
    IGX3DSurface __RPC_FAR * This,
    /* [out] */ DWORD __RPC_FAR *__RPC_FAR *MapIndexList);


void __RPC_STUB IGX3DSurface_GetMapIndices_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IGX3DSurface_InsertMapIndex_Proxy( 
    IGX3DSurface __RPC_FAR * This,
    /* [in] */ DWORD MIndex);


void __RPC_STUB IGX3DSurface_InsertMapIndex_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IGX3DSurface_INTERFACE_DEFINED__ */


#ifndef __IGX3DSurfaceMap_INTERFACE_DEFINED__
#define __IGX3DSurfaceMap_INTERFACE_DEFINED__

/****************************************
 * Generated header for interface: IGX3DSurfaceMap
 * at Tue Nov 23 05:02:16 1999
 * using MIDL 3.01.75
 ****************************************/
/* [local][uuid][object] */ 



EXTERN_C const IID IID_IGX3DSurfaceMap;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    interface DECLSPEC_UUID("8335e67f-ab3b-11ce-8468-0000b468276b")
    IGX3DSurfaceMap : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE InitializeAttributes( 
            /* [out] */ GXMapAttrib __RPC_FAR *MapAttrib) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetAttributes( 
            /* [out] */ GXMapAttrib __RPC_FAR *MapAttrib) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetAttributes( 
            /* [in] */ GXMapAttrib __RPC_FAR *MapAttrib) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IGX3DSurfaceMapVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            IGX3DSurfaceMap __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            IGX3DSurfaceMap __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            IGX3DSurfaceMap __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *InitializeAttributes )( 
            IGX3DSurfaceMap __RPC_FAR * This,
            /* [out] */ GXMapAttrib __RPC_FAR *MapAttrib);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetAttributes )( 
            IGX3DSurfaceMap __RPC_FAR * This,
            /* [out] */ GXMapAttrib __RPC_FAR *MapAttrib);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetAttributes )( 
            IGX3DSurfaceMap __RPC_FAR * This,
            /* [in] */ GXMapAttrib __RPC_FAR *MapAttrib);
        
        END_INTERFACE
    } IGX3DSurfaceMapVtbl;

    interface IGX3DSurfaceMap
    {
        CONST_VTBL struct IGX3DSurfaceMapVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IGX3DSurfaceMap_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IGX3DSurfaceMap_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IGX3DSurfaceMap_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IGX3DSurfaceMap_InitializeAttributes(This,MapAttrib)	\
    (This)->lpVtbl -> InitializeAttributes(This,MapAttrib)

#define IGX3DSurfaceMap_GetAttributes(This,MapAttrib)	\
    (This)->lpVtbl -> GetAttributes(This,MapAttrib)

#define IGX3DSurfaceMap_SetAttributes(This,MapAttrib)	\
    (This)->lpVtbl -> SetAttributes(This,MapAttrib)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE IGX3DSurfaceMap_InitializeAttributes_Proxy( 
    IGX3DSurfaceMap __RPC_FAR * This,
    /* [out] */ GXMapAttrib __RPC_FAR *MapAttrib);


void __RPC_STUB IGX3DSurfaceMap_InitializeAttributes_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IGX3DSurfaceMap_GetAttributes_Proxy( 
    IGX3DSurfaceMap __RPC_FAR * This,
    /* [out] */ GXMapAttrib __RPC_FAR *MapAttrib);


void __RPC_STUB IGX3DSurfaceMap_GetAttributes_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IGX3DSurfaceMap_SetAttributes_Proxy( 
    IGX3DSurfaceMap __RPC_FAR * This,
    /* [in] */ GXMapAttrib __RPC_FAR *MapAttrib);


void __RPC_STUB IGX3DSurfaceMap_SetAttributes_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IGX3DSurfaceMap_INTERFACE_DEFINED__ */


#ifndef __IGX3DTransFact_INTERFACE_DEFINED__
#define __IGX3DTransFact_INTERFACE_DEFINED__

/****************************************
 * Generated header for interface: IGX3DTransFact
 * at Tue Nov 23 05:02:16 1999
 * using MIDL 3.01.75
 ****************************************/
/* [local][uuid][object] */ 



EXTERN_C const IID IID_IGX3DTransFact;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    interface DECLSPEC_UUID("8335e672-ab3b-11ce-8468-0000b468276b")
    IGX3DTransFact : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE GetFileType( 
            /* [in][string] */ unsigned char __RPC_FAR *pszFileName,
            /* [in] */ DWORD fileTypeSize,
            /* [out] */ unsigned char __RPC_FAR *szFileTypeName,
            /* [out] */ IGX3DTranslator __RPC_FAR *__RPC_FAR *ppXlator) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE LoadFile( 
            /* [in][string] */ unsigned char __RPC_FAR *pszFileName,
            /* [out] */ IGX3DScene __RPC_FAR *__RPC_FAR *pIGXScene,
            /* [in] */ IGX3DProgress __RPC_FAR *Progress) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SaveFile( 
            /* [in][string] */ unsigned char __RPC_FAR *pszFileName,
            /* [in] */ IGX3DScene __RPC_FAR *pIGXScene,
            /* [in] */ IGX3DProgress __RPC_FAR *Progress) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetEnumLoaders( 
            /* [out] */ IGX3DEnumTrans __RPC_FAR *__RPC_FAR *ppIenum) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetEnumSavers( 
            /* [out] */ IGX3DEnumTrans __RPC_FAR *__RPC_FAR *ppIenum) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IGX3DTransFactVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            IGX3DTransFact __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            IGX3DTransFact __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            IGX3DTransFact __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetFileType )( 
            IGX3DTransFact __RPC_FAR * This,
            /* [in][string] */ unsigned char __RPC_FAR *pszFileName,
            /* [in] */ DWORD fileTypeSize,
            /* [out] */ unsigned char __RPC_FAR *szFileTypeName,
            /* [out] */ IGX3DTranslator __RPC_FAR *__RPC_FAR *ppXlator);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *LoadFile )( 
            IGX3DTransFact __RPC_FAR * This,
            /* [in][string] */ unsigned char __RPC_FAR *pszFileName,
            /* [out] */ IGX3DScene __RPC_FAR *__RPC_FAR *pIGXScene,
            /* [in] */ IGX3DProgress __RPC_FAR *Progress);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SaveFile )( 
            IGX3DTransFact __RPC_FAR * This,
            /* [in][string] */ unsigned char __RPC_FAR *pszFileName,
            /* [in] */ IGX3DScene __RPC_FAR *pIGXScene,
            /* [in] */ IGX3DProgress __RPC_FAR *Progress);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetEnumLoaders )( 
            IGX3DTransFact __RPC_FAR * This,
            /* [out] */ IGX3DEnumTrans __RPC_FAR *__RPC_FAR *ppIenum);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetEnumSavers )( 
            IGX3DTransFact __RPC_FAR * This,
            /* [out] */ IGX3DEnumTrans __RPC_FAR *__RPC_FAR *ppIenum);
        
        END_INTERFACE
    } IGX3DTransFactVtbl;

    interface IGX3DTransFact
    {
        CONST_VTBL struct IGX3DTransFactVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IGX3DTransFact_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IGX3DTransFact_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IGX3DTransFact_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IGX3DTransFact_GetFileType(This,pszFileName,fileTypeSize,szFileTypeName,ppXlator)	\
    (This)->lpVtbl -> GetFileType(This,pszFileName,fileTypeSize,szFileTypeName,ppXlator)

#define IGX3DTransFact_LoadFile(This,pszFileName,pIGXScene,Progress)	\
    (This)->lpVtbl -> LoadFile(This,pszFileName,pIGXScene,Progress)

#define IGX3DTransFact_SaveFile(This,pszFileName,pIGXScene,Progress)	\
    (This)->lpVtbl -> SaveFile(This,pszFileName,pIGXScene,Progress)

#define IGX3DTransFact_GetEnumLoaders(This,ppIenum)	\
    (This)->lpVtbl -> GetEnumLoaders(This,ppIenum)

#define IGX3DTransFact_GetEnumSavers(This,ppIenum)	\
    (This)->lpVtbl -> GetEnumSavers(This,ppIenum)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE IGX3DTransFact_GetFileType_Proxy( 
    IGX3DTransFact __RPC_FAR * This,
    /* [in][string] */ unsigned char __RPC_FAR *pszFileName,
    /* [in] */ DWORD fileTypeSize,
    /* [out] */ unsigned char __RPC_FAR *szFileTypeName,
    /* [out] */ IGX3DTranslator __RPC_FAR *__RPC_FAR *ppXlator);


void __RPC_STUB IGX3DTransFact_GetFileType_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IGX3DTransFact_LoadFile_Proxy( 
    IGX3DTransFact __RPC_FAR * This,
    /* [in][string] */ unsigned char __RPC_FAR *pszFileName,
    /* [out] */ IGX3DScene __RPC_FAR *__RPC_FAR *pIGXScene,
    /* [in] */ IGX3DProgress __RPC_FAR *Progress);


void __RPC_STUB IGX3DTransFact_LoadFile_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IGX3DTransFact_SaveFile_Proxy( 
    IGX3DTransFact __RPC_FAR * This,
    /* [in][string] */ unsigned char __RPC_FAR *pszFileName,
    /* [in] */ IGX3DScene __RPC_FAR *pIGXScene,
    /* [in] */ IGX3DProgress __RPC_FAR *Progress);


void __RPC_STUB IGX3DTransFact_SaveFile_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IGX3DTransFact_GetEnumLoaders_Proxy( 
    IGX3DTransFact __RPC_FAR * This,
    /* [out] */ IGX3DEnumTrans __RPC_FAR *__RPC_FAR *ppIenum);


void __RPC_STUB IGX3DTransFact_GetEnumLoaders_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IGX3DTransFact_GetEnumSavers_Proxy( 
    IGX3DTransFact __RPC_FAR * This,
    /* [out] */ IGX3DEnumTrans __RPC_FAR *__RPC_FAR *ppIenum);


void __RPC_STUB IGX3DTransFact_GetEnumSavers_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IGX3DTransFact_INTERFACE_DEFINED__ */


#ifndef __IGX3DTranslator_INTERFACE_DEFINED__
#define __IGX3DTranslator_INTERFACE_DEFINED__

/****************************************
 * Generated header for interface: IGX3DTranslator
 * at Tue Nov 23 05:02:16 1999
 * using MIDL 3.01.75
 ****************************************/
/* [local][uuid][object] */ 



EXTERN_C const IID IID_IGX3DTranslator;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    interface DECLSPEC_UUID("8335e673-ab3b-11ce-8468-0000b468276b")
    IGX3DTranslator : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE CanILoad( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE CanISave( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE ValidateFile( 
            /* [in][string] */ unsigned char __RPC_FAR *pszFileName) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE LoadFile( 
            /* [in][string] */ unsigned char __RPC_FAR *pszFileName,
            /* [out] */ IGX3DScene __RPC_FAR *__RPC_FAR *pIGXScene,
            /* [in] */ IGX3DProgress __RPC_FAR *Progress) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SaveFile( 
            /* [in][string] */ unsigned char __RPC_FAR *pszFileName,
            /* [in] */ IGX3DScene __RPC_FAR *pIGXScene,
            /* [in] */ IGX3DProgress __RPC_FAR *Progress) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IGX3DTranslatorVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            IGX3DTranslator __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            IGX3DTranslator __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            IGX3DTranslator __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *CanILoad )( 
            IGX3DTranslator __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *CanISave )( 
            IGX3DTranslator __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *ValidateFile )( 
            IGX3DTranslator __RPC_FAR * This,
            /* [in][string] */ unsigned char __RPC_FAR *pszFileName);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *LoadFile )( 
            IGX3DTranslator __RPC_FAR * This,
            /* [in][string] */ unsigned char __RPC_FAR *pszFileName,
            /* [out] */ IGX3DScene __RPC_FAR *__RPC_FAR *pIGXScene,
            /* [in] */ IGX3DProgress __RPC_FAR *Progress);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SaveFile )( 
            IGX3DTranslator __RPC_FAR * This,
            /* [in][string] */ unsigned char __RPC_FAR *pszFileName,
            /* [in] */ IGX3DScene __RPC_FAR *pIGXScene,
            /* [in] */ IGX3DProgress __RPC_FAR *Progress);
        
        END_INTERFACE
    } IGX3DTranslatorVtbl;

    interface IGX3DTranslator
    {
        CONST_VTBL struct IGX3DTranslatorVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IGX3DTranslator_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IGX3DTranslator_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IGX3DTranslator_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IGX3DTranslator_CanILoad(This)	\
    (This)->lpVtbl -> CanILoad(This)

#define IGX3DTranslator_CanISave(This)	\
    (This)->lpVtbl -> CanISave(This)

#define IGX3DTranslator_ValidateFile(This,pszFileName)	\
    (This)->lpVtbl -> ValidateFile(This,pszFileName)

#define IGX3DTranslator_LoadFile(This,pszFileName,pIGXScene,Progress)	\
    (This)->lpVtbl -> LoadFile(This,pszFileName,pIGXScene,Progress)

#define IGX3DTranslator_SaveFile(This,pszFileName,pIGXScene,Progress)	\
    (This)->lpVtbl -> SaveFile(This,pszFileName,pIGXScene,Progress)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE IGX3DTranslator_CanILoad_Proxy( 
    IGX3DTranslator __RPC_FAR * This);


void __RPC_STUB IGX3DTranslator_CanILoad_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IGX3DTranslator_CanISave_Proxy( 
    IGX3DTranslator __RPC_FAR * This);


void __RPC_STUB IGX3DTranslator_CanISave_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IGX3DTranslator_ValidateFile_Proxy( 
    IGX3DTranslator __RPC_FAR * This,
    /* [in][string] */ unsigned char __RPC_FAR *pszFileName);


void __RPC_STUB IGX3DTranslator_ValidateFile_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IGX3DTranslator_LoadFile_Proxy( 
    IGX3DTranslator __RPC_FAR * This,
    /* [in][string] */ unsigned char __RPC_FAR *pszFileName,
    /* [out] */ IGX3DScene __RPC_FAR *__RPC_FAR *pIGXScene,
    /* [in] */ IGX3DProgress __RPC_FAR *Progress);


void __RPC_STUB IGX3DTranslator_LoadFile_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IGX3DTranslator_SaveFile_Proxy( 
    IGX3DTranslator __RPC_FAR * This,
    /* [in][string] */ unsigned char __RPC_FAR *pszFileName,
    /* [in] */ IGX3DScene __RPC_FAR *pIGXScene,
    /* [in] */ IGX3DProgress __RPC_FAR *Progress);


void __RPC_STUB IGX3DTranslator_SaveFile_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IGX3DTranslator_INTERFACE_DEFINED__ */


#ifndef __IGX3DClientIO_INTERFACE_DEFINED__
#define __IGX3DClientIO_INTERFACE_DEFINED__

/****************************************
 * Generated header for interface: IGX3DClientIO
 * at Tue Nov 23 05:02:16 1999
 * using MIDL 3.01.75
 ****************************************/
/* [local][uuid][object] */ 


typedef 
enum tagGXSeekOrig
    {	gxSEEK_START	= 0,
	gxSEEK_END	= gxSEEK_START + 1,
	gxSEEK_CURRENT	= gxSEEK_END + 1
    }	GXSeekOrig;

typedef 
enum tagGXEEndianess
    {	gxUNKNOWN	= 0,
	gxINTEL	= gxUNKNOWN + 1,
	gxMOTOROLA	= gxINTEL + 1
    }	GXEEndianess;


EXTERN_C const IID IID_IGX3DClientIO;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    interface DECLSPEC_UUID("8335e675-ab3b-11ce-8468-0000b468276b")
    IGX3DClientIO : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE IsValid( void) = 0;
        
        virtual void STDMETHODCALLTYPE GetMediaEndianess( 
            /* [out] */ GXEEndianess __RPC_FAR *end) = 0;
        
        virtual void STDMETHODCALLTYPE SetMediaEndianess( 
            /* [in] */ GXEEndianess end) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Open( 
            /* [in] */ unsigned char __RPC_FAR *pszFileName,
            /* [in] */ DWORD mode) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Close( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Tell( 
            /* [in] */ DWORD __RPC_FAR *Offset) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Seek( 
            /* [in] */ DWORD Offset,
            /* [in] */ WORD Origin) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE ReadByte( 
            /* [out] */ BYTE __RPC_FAR *Value) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE ReadWord( 
            /* [out] */ WORD __RPC_FAR *Value) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE ReadDWord( 
            /* [out] */ DWORD __RPC_FAR *Value) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE ReadFloat( 
            /* [out] */ float __RPC_FAR *Value) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE ReadDouble( 
            /* [out] */ double __RPC_FAR *Value) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE ReadBuffer( 
            /* [out] */ BYTE __RPC_FAR *Buffer,
            /* [in] */ DWORD __RPC_FAR *Count) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE WriteByte( 
            /* [in] */ BYTE __RPC_FAR *Value) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE WriteWord( 
            /* [in] */ WORD __RPC_FAR *Value) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE WriteDWord( 
            /* [in] */ DWORD __RPC_FAR *Value) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE WriteFloat( 
            /* [in] */ float __RPC_FAR *Value) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE WriteDouble( 
            /* [in] */ double __RPC_FAR *Value) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE WriteBuffer( 
            /* [in] */ BYTE __RPC_FAR *Buffer,
            /* [in] */ DWORD __RPC_FAR *Count) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IGX3DClientIOVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            IGX3DClientIO __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            IGX3DClientIO __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            IGX3DClientIO __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *IsValid )( 
            IGX3DClientIO __RPC_FAR * This);
        
        void ( STDMETHODCALLTYPE __RPC_FAR *GetMediaEndianess )( 
            IGX3DClientIO __RPC_FAR * This,
            /* [out] */ GXEEndianess __RPC_FAR *end);
        
        void ( STDMETHODCALLTYPE __RPC_FAR *SetMediaEndianess )( 
            IGX3DClientIO __RPC_FAR * This,
            /* [in] */ GXEEndianess end);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Open )( 
            IGX3DClientIO __RPC_FAR * This,
            /* [in] */ unsigned char __RPC_FAR *pszFileName,
            /* [in] */ DWORD mode);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Close )( 
            IGX3DClientIO __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Tell )( 
            IGX3DClientIO __RPC_FAR * This,
            /* [in] */ DWORD __RPC_FAR *Offset);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Seek )( 
            IGX3DClientIO __RPC_FAR * This,
            /* [in] */ DWORD Offset,
            /* [in] */ WORD Origin);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *ReadByte )( 
            IGX3DClientIO __RPC_FAR * This,
            /* [out] */ BYTE __RPC_FAR *Value);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *ReadWord )( 
            IGX3DClientIO __RPC_FAR * This,
            /* [out] */ WORD __RPC_FAR *Value);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *ReadDWord )( 
            IGX3DClientIO __RPC_FAR * This,
            /* [out] */ DWORD __RPC_FAR *Value);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *ReadFloat )( 
            IGX3DClientIO __RPC_FAR * This,
            /* [out] */ float __RPC_FAR *Value);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *ReadDouble )( 
            IGX3DClientIO __RPC_FAR * This,
            /* [out] */ double __RPC_FAR *Value);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *ReadBuffer )( 
            IGX3DClientIO __RPC_FAR * This,
            /* [out] */ BYTE __RPC_FAR *Buffer,
            /* [in] */ DWORD __RPC_FAR *Count);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *WriteByte )( 
            IGX3DClientIO __RPC_FAR * This,
            /* [in] */ BYTE __RPC_FAR *Value);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *WriteWord )( 
            IGX3DClientIO __RPC_FAR * This,
            /* [in] */ WORD __RPC_FAR *Value);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *WriteDWord )( 
            IGX3DClientIO __RPC_FAR * This,
            /* [in] */ DWORD __RPC_FAR *Value);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *WriteFloat )( 
            IGX3DClientIO __RPC_FAR * This,
            /* [in] */ float __RPC_FAR *Value);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *WriteDouble )( 
            IGX3DClientIO __RPC_FAR * This,
            /* [in] */ double __RPC_FAR *Value);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *WriteBuffer )( 
            IGX3DClientIO __RPC_FAR * This,
            /* [in] */ BYTE __RPC_FAR *Buffer,
            /* [in] */ DWORD __RPC_FAR *Count);
        
        END_INTERFACE
    } IGX3DClientIOVtbl;

    interface IGX3DClientIO
    {
        CONST_VTBL struct IGX3DClientIOVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IGX3DClientIO_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IGX3DClientIO_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IGX3DClientIO_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IGX3DClientIO_IsValid(This)	\
    (This)->lpVtbl -> IsValid(This)

#define IGX3DClientIO_GetMediaEndianess(This,end)	\
    (This)->lpVtbl -> GetMediaEndianess(This,end)

#define IGX3DClientIO_SetMediaEndianess(This,end)	\
    (This)->lpVtbl -> SetMediaEndianess(This,end)

#define IGX3DClientIO_Open(This,pszFileName,mode)	\
    (This)->lpVtbl -> Open(This,pszFileName,mode)

#define IGX3DClientIO_Close(This)	\
    (This)->lpVtbl -> Close(This)

#define IGX3DClientIO_Tell(This,Offset)	\
    (This)->lpVtbl -> Tell(This,Offset)

#define IGX3DClientIO_Seek(This,Offset,Origin)	\
    (This)->lpVtbl -> Seek(This,Offset,Origin)

#define IGX3DClientIO_ReadByte(This,Value)	\
    (This)->lpVtbl -> ReadByte(This,Value)

#define IGX3DClientIO_ReadWord(This,Value)	\
    (This)->lpVtbl -> ReadWord(This,Value)

#define IGX3DClientIO_ReadDWord(This,Value)	\
    (This)->lpVtbl -> ReadDWord(This,Value)

#define IGX3DClientIO_ReadFloat(This,Value)	\
    (This)->lpVtbl -> ReadFloat(This,Value)

#define IGX3DClientIO_ReadDouble(This,Value)	\
    (This)->lpVtbl -> ReadDouble(This,Value)

#define IGX3DClientIO_ReadBuffer(This,Buffer,Count)	\
    (This)->lpVtbl -> ReadBuffer(This,Buffer,Count)

#define IGX3DClientIO_WriteByte(This,Value)	\
    (This)->lpVtbl -> WriteByte(This,Value)

#define IGX3DClientIO_WriteWord(This,Value)	\
    (This)->lpVtbl -> WriteWord(This,Value)

#define IGX3DClientIO_WriteDWord(This,Value)	\
    (This)->lpVtbl -> WriteDWord(This,Value)

#define IGX3DClientIO_WriteFloat(This,Value)	\
    (This)->lpVtbl -> WriteFloat(This,Value)

#define IGX3DClientIO_WriteDouble(This,Value)	\
    (This)->lpVtbl -> WriteDouble(This,Value)

#define IGX3DClientIO_WriteBuffer(This,Buffer,Count)	\
    (This)->lpVtbl -> WriteBuffer(This,Buffer,Count)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE IGX3DClientIO_IsValid_Proxy( 
    IGX3DClientIO __RPC_FAR * This);


void __RPC_STUB IGX3DClientIO_IsValid_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


void STDMETHODCALLTYPE IGX3DClientIO_GetMediaEndianess_Proxy( 
    IGX3DClientIO __RPC_FAR * This,
    /* [out] */ GXEEndianess __RPC_FAR *end);


void __RPC_STUB IGX3DClientIO_GetMediaEndianess_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


void STDMETHODCALLTYPE IGX3DClientIO_SetMediaEndianess_Proxy( 
    IGX3DClientIO __RPC_FAR * This,
    /* [in] */ GXEEndianess end);


void __RPC_STUB IGX3DClientIO_SetMediaEndianess_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IGX3DClientIO_Open_Proxy( 
    IGX3DClientIO __RPC_FAR * This,
    /* [in] */ unsigned char __RPC_FAR *pszFileName,
    /* [in] */ DWORD mode);


void __RPC_STUB IGX3DClientIO_Open_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IGX3DClientIO_Close_Proxy( 
    IGX3DClientIO __RPC_FAR * This);


void __RPC_STUB IGX3DClientIO_Close_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IGX3DClientIO_Tell_Proxy( 
    IGX3DClientIO __RPC_FAR * This,
    /* [in] */ DWORD __RPC_FAR *Offset);


void __RPC_STUB IGX3DClientIO_Tell_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IGX3DClientIO_Seek_Proxy( 
    IGX3DClientIO __RPC_FAR * This,
    /* [in] */ DWORD Offset,
    /* [in] */ WORD Origin);


void __RPC_STUB IGX3DClientIO_Seek_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IGX3DClientIO_ReadByte_Proxy( 
    IGX3DClientIO __RPC_FAR * This,
    /* [out] */ BYTE __RPC_FAR *Value);


void __RPC_STUB IGX3DClientIO_ReadByte_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IGX3DClientIO_ReadWord_Proxy( 
    IGX3DClientIO __RPC_FAR * This,
    /* [out] */ WORD __RPC_FAR *Value);


void __RPC_STUB IGX3DClientIO_ReadWord_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IGX3DClientIO_ReadDWord_Proxy( 
    IGX3DClientIO __RPC_FAR * This,
    /* [out] */ DWORD __RPC_FAR *Value);


void __RPC_STUB IGX3DClientIO_ReadDWord_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IGX3DClientIO_ReadFloat_Proxy( 
    IGX3DClientIO __RPC_FAR * This,
    /* [out] */ float __RPC_FAR *Value);


void __RPC_STUB IGX3DClientIO_ReadFloat_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IGX3DClientIO_ReadDouble_Proxy( 
    IGX3DClientIO __RPC_FAR * This,
    /* [out] */ double __RPC_FAR *Value);


void __RPC_STUB IGX3DClientIO_ReadDouble_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IGX3DClientIO_ReadBuffer_Proxy( 
    IGX3DClientIO __RPC_FAR * This,
    /* [out] */ BYTE __RPC_FAR *Buffer,
    /* [in] */ DWORD __RPC_FAR *Count);


void __RPC_STUB IGX3DClientIO_ReadBuffer_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IGX3DClientIO_WriteByte_Proxy( 
    IGX3DClientIO __RPC_FAR * This,
    /* [in] */ BYTE __RPC_FAR *Value);


void __RPC_STUB IGX3DClientIO_WriteByte_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IGX3DClientIO_WriteWord_Proxy( 
    IGX3DClientIO __RPC_FAR * This,
    /* [in] */ WORD __RPC_FAR *Value);


void __RPC_STUB IGX3DClientIO_WriteWord_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IGX3DClientIO_WriteDWord_Proxy( 
    IGX3DClientIO __RPC_FAR * This,
    /* [in] */ DWORD __RPC_FAR *Value);


void __RPC_STUB IGX3DClientIO_WriteDWord_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IGX3DClientIO_WriteFloat_Proxy( 
    IGX3DClientIO __RPC_FAR * This,
    /* [in] */ float __RPC_FAR *Value);


void __RPC_STUB IGX3DClientIO_WriteFloat_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IGX3DClientIO_WriteDouble_Proxy( 
    IGX3DClientIO __RPC_FAR * This,
    /* [in] */ double __RPC_FAR *Value);


void __RPC_STUB IGX3DClientIO_WriteDouble_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IGX3DClientIO_WriteBuffer_Proxy( 
    IGX3DClientIO __RPC_FAR * This,
    /* [in] */ BYTE __RPC_FAR *Buffer,
    /* [in] */ DWORD __RPC_FAR *Count);


void __RPC_STUB IGX3DClientIO_WriteBuffer_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IGX3DClientIO_INTERFACE_DEFINED__ */


#ifndef __IGX3DProgress_INTERFACE_DEFINED__
#define __IGX3DProgress_INTERFACE_DEFINED__

/****************************************
 * Generated header for interface: IGX3DProgress
 * at Tue Nov 23 05:02:16 1999
 * using MIDL 3.01.75
 ****************************************/
/* [local][uuid][object] */ 


typedef struct  tagGXSTrnProgress
    {
    BYTE __RPC_FAR *Description;
    DWORD currentRow;
    DWORD maxRow;
    DWORD currentPass;
    DWORD maxPass;
    }	GXSTrnProgress;


EXTERN_C const IID IID_IGX3DProgress;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    interface DECLSPEC_UUID("8335e674-ab3b-11ce-8468-0000b468276b")
    IGX3DProgress : public IUnknown
    {
    public:
        virtual void STDMETHODCALLTYPE StartOperation( void) = 0;
        
        virtual void STDMETHODCALLTYPE EndOperation( void) = 0;
        
        virtual void STDMETHODCALLTYPE SetMaxPasses( 
            DWORD maxPass) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE ProgressNotify( 
            /* [in] */ GXSTrnProgress __RPC_FAR *progress) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IGX3DProgressVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            IGX3DProgress __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            IGX3DProgress __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            IGX3DProgress __RPC_FAR * This);
        
        void ( STDMETHODCALLTYPE __RPC_FAR *StartOperation )( 
            IGX3DProgress __RPC_FAR * This);
        
        void ( STDMETHODCALLTYPE __RPC_FAR *EndOperation )( 
            IGX3DProgress __RPC_FAR * This);
        
        void ( STDMETHODCALLTYPE __RPC_FAR *SetMaxPasses )( 
            IGX3DProgress __RPC_FAR * This,
            DWORD maxPass);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *ProgressNotify )( 
            IGX3DProgress __RPC_FAR * This,
            /* [in] */ GXSTrnProgress __RPC_FAR *progress);
        
        END_INTERFACE
    } IGX3DProgressVtbl;

    interface IGX3DProgress
    {
        CONST_VTBL struct IGX3DProgressVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IGX3DProgress_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IGX3DProgress_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IGX3DProgress_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IGX3DProgress_StartOperation(This)	\
    (This)->lpVtbl -> StartOperation(This)

#define IGX3DProgress_EndOperation(This)	\
    (This)->lpVtbl -> EndOperation(This)

#define IGX3DProgress_SetMaxPasses(This,maxPass)	\
    (This)->lpVtbl -> SetMaxPasses(This,maxPass)

#define IGX3DProgress_ProgressNotify(This,progress)	\
    (This)->lpVtbl -> ProgressNotify(This,progress)

#endif /* COBJMACROS */


#endif 	/* C style interface */



void STDMETHODCALLTYPE IGX3DProgress_StartOperation_Proxy( 
    IGX3DProgress __RPC_FAR * This);


void __RPC_STUB IGX3DProgress_StartOperation_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


void STDMETHODCALLTYPE IGX3DProgress_EndOperation_Proxy( 
    IGX3DProgress __RPC_FAR * This);


void __RPC_STUB IGX3DProgress_EndOperation_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


void STDMETHODCALLTYPE IGX3DProgress_SetMaxPasses_Proxy( 
    IGX3DProgress __RPC_FAR * This,
    DWORD maxPass);


void __RPC_STUB IGX3DProgress_SetMaxPasses_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IGX3DProgress_ProgressNotify_Proxy( 
    IGX3DProgress __RPC_FAR * This,
    /* [in] */ GXSTrnProgress __RPC_FAR *progress);


void __RPC_STUB IGX3DProgress_ProgressNotify_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IGX3DProgress_INTERFACE_DEFINED__ */


/* Additional Prototypes for ALL interfaces */

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif
