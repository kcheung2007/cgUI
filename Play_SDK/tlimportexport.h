/* this ALWAYS GENERATED file contains the definitions for the interfaces */


/* File created by MIDL compiler version 3.01.75 */
/* at Tue Nov 23 05:28:36 1999
 */
/* Compiler settings for tlimportexport.idl:
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

#ifndef __tlimportexport_h__
#define __tlimportexport_h__

#ifdef __cplusplus
extern "C"{
#endif 

/* Forward Declarations */ 

#ifndef __IPlayTLImpExp_FWD_DEFINED__
#define __IPlayTLImpExp_FWD_DEFINED__
typedef interface IPlayTLImpExp IPlayTLImpExp;
#endif 	/* __IPlayTLImpExp_FWD_DEFINED__ */


#ifndef __IPlayTLIETrackEnum_FWD_DEFINED__
#define __IPlayTLIETrackEnum_FWD_DEFINED__
typedef interface IPlayTLIETrackEnum IPlayTLIETrackEnum;
#endif 	/* __IPlayTLIETrackEnum_FWD_DEFINED__ */


#ifndef __IPlayTLIEGroupEnum_FWD_DEFINED__
#define __IPlayTLIEGroupEnum_FWD_DEFINED__
typedef interface IPlayTLIEGroupEnum IPlayTLIEGroupEnum;
#endif 	/* __IPlayTLIEGroupEnum_FWD_DEFINED__ */


#ifndef __IPlayTLIEEventEnum_FWD_DEFINED__
#define __IPlayTLIEEventEnum_FWD_DEFINED__
typedef interface IPlayTLIEEventEnum IPlayTLIEEventEnum;
#endif 	/* __IPlayTLIEEventEnum_FWD_DEFINED__ */


#ifndef __IPlayTLIEGroup_FWD_DEFINED__
#define __IPlayTLIEGroup_FWD_DEFINED__
typedef interface IPlayTLIEGroup IPlayTLIEGroup;
#endif 	/* __IPlayTLIEGroup_FWD_DEFINED__ */


#ifndef __IPlayTLIETrack_FWD_DEFINED__
#define __IPlayTLIETrack_FWD_DEFINED__
typedef interface IPlayTLIETrack IPlayTLIETrack;
#endif 	/* __IPlayTLIETrack_FWD_DEFINED__ */


#ifndef __IPlayTLIEEvent_FWD_DEFINED__
#define __IPlayTLIEEvent_FWD_DEFINED__
typedef interface IPlayTLIEEvent IPlayTLIEEvent;
#endif 	/* __IPlayTLIEEvent_FWD_DEFINED__ */


/* header files for imported files */
#include "objidl.h"
#include "plylst.h"

void __RPC_FAR * __RPC_USER MIDL_user_allocate(size_t);
void __RPC_USER MIDL_user_free( void __RPC_FAR * ); 

/****************************************
 * Generated header for interface: __MIDL_itf_tlimportexport_0000
 * at Tue Nov 23 05:28:36 1999
 * using MIDL 3.01.75
 ****************************************/
/* [local] */ 













extern RPC_IF_HANDLE __MIDL_itf_tlimportexport_0000_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_tlimportexport_0000_v0_0_s_ifspec;

#ifndef __IPlayTLImpExp_INTERFACE_DEFINED__
#define __IPlayTLImpExp_INTERFACE_DEFINED__

/****************************************
 * Generated header for interface: IPlayTLImpExp
 * at Tue Nov 23 05:28:36 1999
 * using MIDL 3.01.75
 ****************************************/
/* [local][uuid][object] */ 


typedef /* [public][public][public][public][public] */ 
enum __MIDL_IPlayTLImpExp_0001
    {	CG_Unknown	= -1,
	CG_601	= 0,
	CG_Effect	= CG_601 + 1,
	CG_FrameStore	= CG_Effect + 1,
	CG_GPI	= CG_FrameStore + 1,
	CG_LinearClip	= CG_GPI + 1,
	CG_Live	= CG_LinearClip + 1,
	CG_Matte	= CG_Live + 1,
	CG_MediaClip	= CG_Matte + 1,
	CG_Transition	= CG_MediaClip + 1
    }	CG_TYPE;

typedef /* [public][public][public][public] */ 
enum __MIDL_IPlayTLImpExp_0002
    {	CE_Unknown	= -1,
	CE_Video	= 0,
	CE_Audio1	= CE_Video + 1,
	CE_Audio2	= CE_Audio1 + 1,
	CE_Audio3	= CE_Audio2 + 1,
	CE_Audio4	= CE_Audio3 + 1,
	CE_AudioLevel	= CE_Audio4 + 1,
	CE_AudioPan	= CE_AudioLevel + 1,
	CE_Alpha	= CE_AudioPan + 1,
	CE_DSK	= CE_Alpha + 1,
	CE_FX	= CE_DSK + 1,
	CE_GPI1	= CE_FX + 1,
	CE_GPI2	= CE_GPI1 + 1,
	CE_GPI3	= CE_GPI2 + 1,
	CE_GPI4	= CE_GPI3 + 1
    }	CE_TYPE;

typedef /* [public][public][public][public][public] */ struct  __MIDL_IPlayTLImpExp_0003
    {
    DWORD dwStartTime;
    DWORD dwLength;
    DWORD dwSourceStartTime;
    }	EVENTINFO;

typedef /* [public][public][public] */ struct  __MIDL_IPlayTLImpExp_0004
    {
    DWORD dwSize;
    CG_TYPE Type;
    DWORD dwNumGroupEvents;
    EVENTINFO __RPC_FAR *__RPC_FAR *GroupEvents;
    DWORD dwOptions;
    DWORD dwVideoTrackA;
    DWORD dwVideoTrackB;
    COLORREF dwColor;
    wchar_t ReelFileName[ 255 ];
    DWORD dwGPIAction;
    DWORD dwGPIChannel;
    DWORD dwWipeNumber;
    }	GROUPINFO;


EXTERN_C const IID IID_IPlayTLImpExp;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    interface DECLSPEC_UUID("8335e745-ab3b-11ce-8468-0000b468276b")
    IPlayTLImpExp : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE ClearTimeline( void) = 0;
        
        virtual DWORD STDMETHODCALLTYPE GetTimelineLength( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetTimelineTimeInfo( 
            /* [in] */ DWORD dwStartTime,
            /* [in] */ DWORD dwEndTime,
            /* [in] */ DWORD dwTimeMode) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetVideoTrack( 
            /* [in] */ DWORD dwVideoTrack,
            /* [out] */ IPlayTLIETrack __RPC_FAR *__RPC_FAR *ppTrack) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE CreateGroup( 
            /* [in] */ int iGroupType,
            /* [in] */ GROUPINFO __RPC_FAR *pCreateGroupInfo,
            /* [out] */ IPlayTLIEGroup __RPC_FAR *__RPC_FAR *ppGroup) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE CreateMatte( 
            /* [in] */ DWORD dwStart,
            /* [in] */ DWORD dwLength,
            /* [in] */ DWORD dwRGBColor,
            /* [in] */ DWORD dwVideoTrack,
            /* [out] */ IPlayTLIEGroup __RPC_FAR *__RPC_FAR *ppGroup) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE CreateLinearClip( 
            /* [in] */ DWORD dwNumGroupEvents,
            /* [in] */ EVENTINFO __RPC_FAR *__RPC_FAR *GroupEvents,
            /* [in] */ DWORD dwComponents,
            /* [in][string] */ const OLECHAR __RPC_FAR *pszReelName,
            /* [in] */ DWORD dwVideoTrack,
            /* [out] */ IPlayTLIEGroup __RPC_FAR *__RPC_FAR *ppGroup) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE CreateFrameStore( 
            /* [in] */ DWORD dwStart,
            /* [in] */ DWORD dwLength,
            /* [in] */ DWORD dwVideoTrack,
            /* [in][string] */ const OLECHAR __RPC_FAR *pszFileName,
            /* [out] */ IPlayTLIEGroup __RPC_FAR *__RPC_FAR *ppGroup) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE CreateDissolve( 
            /* [in] */ DWORD dwStart,
            /* [in] */ DWORD dwLength,
            /* [in] */ DWORD dwSourceTrack,
            /* [in] */ DWORD dwDestTrack,
            /* [out] */ IPlayTLIEGroup __RPC_FAR *__RPC_FAR *ppGroup) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE CreateWipe( 
            /* [in] */ DWORD dwStart,
            /* [in] */ DWORD dwLength,
            /* [in] */ DWORD dwSourceTrack,
            /* [in] */ DWORD dwDestTrack,
            /* [in] */ DWORD dwWipeType,
            /* [out] */ IPlayTLIEGroup __RPC_FAR *__RPC_FAR *ppGroup) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Create601( 
            /* [in] */ DWORD dwStart,
            /* [in] */ DWORD dwLength,
            /* [in] */ DWORD dwVideoTrack,
            /* [in][string] */ const OLECHAR __RPC_FAR *pszFileName,
            /* [out] */ IPlayTLIEGroup __RPC_FAR *__RPC_FAR *ppGroup) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE CreateLive( 
            /* [in] */ DWORD dwStart,
            /* [in] */ DWORD dwLength,
            /* [in] */ DWORD dwSource,
            /* [out] */ IPlayTLIEGroup __RPC_FAR *__RPC_FAR *ppGroup) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE CreateGPI( 
            /* [in] */ DWORD dwStart,
            /* [in] */ DWORD dwLength,
            /* [in] */ DWORD dwGPIPort,
            /* [in] */ DWORD dwGPIAction,
            /* [out] */ IPlayTLIEGroup __RPC_FAR *__RPC_FAR *ppGroup) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetEnumTracks( 
            /* [out] */ IPlayTLIETrackEnum __RPC_FAR *__RPC_FAR *ppIEnum) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetEnumGroups( 
            /* [out] */ IPlayTLIEGroupEnum __RPC_FAR *__RPC_FAR *ppIEnum) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IPlayTLImpExpVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            IPlayTLImpExp __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            IPlayTLImpExp __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            IPlayTLImpExp __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *ClearTimeline )( 
            IPlayTLImpExp __RPC_FAR * This);
        
        DWORD ( STDMETHODCALLTYPE __RPC_FAR *GetTimelineLength )( 
            IPlayTLImpExp __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetTimelineTimeInfo )( 
            IPlayTLImpExp __RPC_FAR * This,
            /* [in] */ DWORD dwStartTime,
            /* [in] */ DWORD dwEndTime,
            /* [in] */ DWORD dwTimeMode);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetVideoTrack )( 
            IPlayTLImpExp __RPC_FAR * This,
            /* [in] */ DWORD dwVideoTrack,
            /* [out] */ IPlayTLIETrack __RPC_FAR *__RPC_FAR *ppTrack);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *CreateGroup )( 
            IPlayTLImpExp __RPC_FAR * This,
            /* [in] */ int iGroupType,
            /* [in] */ GROUPINFO __RPC_FAR *pCreateGroupInfo,
            /* [out] */ IPlayTLIEGroup __RPC_FAR *__RPC_FAR *ppGroup);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *CreateMatte )( 
            IPlayTLImpExp __RPC_FAR * This,
            /* [in] */ DWORD dwStart,
            /* [in] */ DWORD dwLength,
            /* [in] */ DWORD dwRGBColor,
            /* [in] */ DWORD dwVideoTrack,
            /* [out] */ IPlayTLIEGroup __RPC_FAR *__RPC_FAR *ppGroup);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *CreateLinearClip )( 
            IPlayTLImpExp __RPC_FAR * This,
            /* [in] */ DWORD dwNumGroupEvents,
            /* [in] */ EVENTINFO __RPC_FAR *__RPC_FAR *GroupEvents,
            /* [in] */ DWORD dwComponents,
            /* [in][string] */ const OLECHAR __RPC_FAR *pszReelName,
            /* [in] */ DWORD dwVideoTrack,
            /* [out] */ IPlayTLIEGroup __RPC_FAR *__RPC_FAR *ppGroup);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *CreateFrameStore )( 
            IPlayTLImpExp __RPC_FAR * This,
            /* [in] */ DWORD dwStart,
            /* [in] */ DWORD dwLength,
            /* [in] */ DWORD dwVideoTrack,
            /* [in][string] */ const OLECHAR __RPC_FAR *pszFileName,
            /* [out] */ IPlayTLIEGroup __RPC_FAR *__RPC_FAR *ppGroup);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *CreateDissolve )( 
            IPlayTLImpExp __RPC_FAR * This,
            /* [in] */ DWORD dwStart,
            /* [in] */ DWORD dwLength,
            /* [in] */ DWORD dwSourceTrack,
            /* [in] */ DWORD dwDestTrack,
            /* [out] */ IPlayTLIEGroup __RPC_FAR *__RPC_FAR *ppGroup);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *CreateWipe )( 
            IPlayTLImpExp __RPC_FAR * This,
            /* [in] */ DWORD dwStart,
            /* [in] */ DWORD dwLength,
            /* [in] */ DWORD dwSourceTrack,
            /* [in] */ DWORD dwDestTrack,
            /* [in] */ DWORD dwWipeType,
            /* [out] */ IPlayTLIEGroup __RPC_FAR *__RPC_FAR *ppGroup);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Create601 )( 
            IPlayTLImpExp __RPC_FAR * This,
            /* [in] */ DWORD dwStart,
            /* [in] */ DWORD dwLength,
            /* [in] */ DWORD dwVideoTrack,
            /* [in][string] */ const OLECHAR __RPC_FAR *pszFileName,
            /* [out] */ IPlayTLIEGroup __RPC_FAR *__RPC_FAR *ppGroup);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *CreateLive )( 
            IPlayTLImpExp __RPC_FAR * This,
            /* [in] */ DWORD dwStart,
            /* [in] */ DWORD dwLength,
            /* [in] */ DWORD dwSource,
            /* [out] */ IPlayTLIEGroup __RPC_FAR *__RPC_FAR *ppGroup);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *CreateGPI )( 
            IPlayTLImpExp __RPC_FAR * This,
            /* [in] */ DWORD dwStart,
            /* [in] */ DWORD dwLength,
            /* [in] */ DWORD dwGPIPort,
            /* [in] */ DWORD dwGPIAction,
            /* [out] */ IPlayTLIEGroup __RPC_FAR *__RPC_FAR *ppGroup);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetEnumTracks )( 
            IPlayTLImpExp __RPC_FAR * This,
            /* [out] */ IPlayTLIETrackEnum __RPC_FAR *__RPC_FAR *ppIEnum);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetEnumGroups )( 
            IPlayTLImpExp __RPC_FAR * This,
            /* [out] */ IPlayTLIEGroupEnum __RPC_FAR *__RPC_FAR *ppIEnum);
        
        END_INTERFACE
    } IPlayTLImpExpVtbl;

    interface IPlayTLImpExp
    {
        CONST_VTBL struct IPlayTLImpExpVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IPlayTLImpExp_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IPlayTLImpExp_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IPlayTLImpExp_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IPlayTLImpExp_ClearTimeline(This)	\
    (This)->lpVtbl -> ClearTimeline(This)

#define IPlayTLImpExp_GetTimelineLength(This)	\
    (This)->lpVtbl -> GetTimelineLength(This)

#define IPlayTLImpExp_SetTimelineTimeInfo(This,dwStartTime,dwEndTime,dwTimeMode)	\
    (This)->lpVtbl -> SetTimelineTimeInfo(This,dwStartTime,dwEndTime,dwTimeMode)

#define IPlayTLImpExp_GetVideoTrack(This,dwVideoTrack,ppTrack)	\
    (This)->lpVtbl -> GetVideoTrack(This,dwVideoTrack,ppTrack)

#define IPlayTLImpExp_CreateGroup(This,iGroupType,pCreateGroupInfo,ppGroup)	\
    (This)->lpVtbl -> CreateGroup(This,iGroupType,pCreateGroupInfo,ppGroup)

#define IPlayTLImpExp_CreateMatte(This,dwStart,dwLength,dwRGBColor,dwVideoTrack,ppGroup)	\
    (This)->lpVtbl -> CreateMatte(This,dwStart,dwLength,dwRGBColor,dwVideoTrack,ppGroup)

#define IPlayTLImpExp_CreateLinearClip(This,dwNumGroupEvents,GroupEvents,dwComponents,pszReelName,dwVideoTrack,ppGroup)	\
    (This)->lpVtbl -> CreateLinearClip(This,dwNumGroupEvents,GroupEvents,dwComponents,pszReelName,dwVideoTrack,ppGroup)

#define IPlayTLImpExp_CreateFrameStore(This,dwStart,dwLength,dwVideoTrack,pszFileName,ppGroup)	\
    (This)->lpVtbl -> CreateFrameStore(This,dwStart,dwLength,dwVideoTrack,pszFileName,ppGroup)

#define IPlayTLImpExp_CreateDissolve(This,dwStart,dwLength,dwSourceTrack,dwDestTrack,ppGroup)	\
    (This)->lpVtbl -> CreateDissolve(This,dwStart,dwLength,dwSourceTrack,dwDestTrack,ppGroup)

#define IPlayTLImpExp_CreateWipe(This,dwStart,dwLength,dwSourceTrack,dwDestTrack,dwWipeType,ppGroup)	\
    (This)->lpVtbl -> CreateWipe(This,dwStart,dwLength,dwSourceTrack,dwDestTrack,dwWipeType,ppGroup)

#define IPlayTLImpExp_Create601(This,dwStart,dwLength,dwVideoTrack,pszFileName,ppGroup)	\
    (This)->lpVtbl -> Create601(This,dwStart,dwLength,dwVideoTrack,pszFileName,ppGroup)

#define IPlayTLImpExp_CreateLive(This,dwStart,dwLength,dwSource,ppGroup)	\
    (This)->lpVtbl -> CreateLive(This,dwStart,dwLength,dwSource,ppGroup)

#define IPlayTLImpExp_CreateGPI(This,dwStart,dwLength,dwGPIPort,dwGPIAction,ppGroup)	\
    (This)->lpVtbl -> CreateGPI(This,dwStart,dwLength,dwGPIPort,dwGPIAction,ppGroup)

#define IPlayTLImpExp_GetEnumTracks(This,ppIEnum)	\
    (This)->lpVtbl -> GetEnumTracks(This,ppIEnum)

#define IPlayTLImpExp_GetEnumGroups(This,ppIEnum)	\
    (This)->lpVtbl -> GetEnumGroups(This,ppIEnum)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE IPlayTLImpExp_ClearTimeline_Proxy( 
    IPlayTLImpExp __RPC_FAR * This);


void __RPC_STUB IPlayTLImpExp_ClearTimeline_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


DWORD STDMETHODCALLTYPE IPlayTLImpExp_GetTimelineLength_Proxy( 
    IPlayTLImpExp __RPC_FAR * This);


void __RPC_STUB IPlayTLImpExp_GetTimelineLength_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IPlayTLImpExp_SetTimelineTimeInfo_Proxy( 
    IPlayTLImpExp __RPC_FAR * This,
    /* [in] */ DWORD dwStartTime,
    /* [in] */ DWORD dwEndTime,
    /* [in] */ DWORD dwTimeMode);


void __RPC_STUB IPlayTLImpExp_SetTimelineTimeInfo_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IPlayTLImpExp_GetVideoTrack_Proxy( 
    IPlayTLImpExp __RPC_FAR * This,
    /* [in] */ DWORD dwVideoTrack,
    /* [out] */ IPlayTLIETrack __RPC_FAR *__RPC_FAR *ppTrack);


void __RPC_STUB IPlayTLImpExp_GetVideoTrack_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IPlayTLImpExp_CreateGroup_Proxy( 
    IPlayTLImpExp __RPC_FAR * This,
    /* [in] */ int iGroupType,
    /* [in] */ GROUPINFO __RPC_FAR *pCreateGroupInfo,
    /* [out] */ IPlayTLIEGroup __RPC_FAR *__RPC_FAR *ppGroup);


void __RPC_STUB IPlayTLImpExp_CreateGroup_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IPlayTLImpExp_CreateMatte_Proxy( 
    IPlayTLImpExp __RPC_FAR * This,
    /* [in] */ DWORD dwStart,
    /* [in] */ DWORD dwLength,
    /* [in] */ DWORD dwRGBColor,
    /* [in] */ DWORD dwVideoTrack,
    /* [out] */ IPlayTLIEGroup __RPC_FAR *__RPC_FAR *ppGroup);


void __RPC_STUB IPlayTLImpExp_CreateMatte_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IPlayTLImpExp_CreateLinearClip_Proxy( 
    IPlayTLImpExp __RPC_FAR * This,
    /* [in] */ DWORD dwNumGroupEvents,
    /* [in] */ EVENTINFO __RPC_FAR *__RPC_FAR *GroupEvents,
    /* [in] */ DWORD dwComponents,
    /* [in][string] */ const OLECHAR __RPC_FAR *pszReelName,
    /* [in] */ DWORD dwVideoTrack,
    /* [out] */ IPlayTLIEGroup __RPC_FAR *__RPC_FAR *ppGroup);


void __RPC_STUB IPlayTLImpExp_CreateLinearClip_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IPlayTLImpExp_CreateFrameStore_Proxy( 
    IPlayTLImpExp __RPC_FAR * This,
    /* [in] */ DWORD dwStart,
    /* [in] */ DWORD dwLength,
    /* [in] */ DWORD dwVideoTrack,
    /* [in][string] */ const OLECHAR __RPC_FAR *pszFileName,
    /* [out] */ IPlayTLIEGroup __RPC_FAR *__RPC_FAR *ppGroup);


void __RPC_STUB IPlayTLImpExp_CreateFrameStore_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IPlayTLImpExp_CreateDissolve_Proxy( 
    IPlayTLImpExp __RPC_FAR * This,
    /* [in] */ DWORD dwStart,
    /* [in] */ DWORD dwLength,
    /* [in] */ DWORD dwSourceTrack,
    /* [in] */ DWORD dwDestTrack,
    /* [out] */ IPlayTLIEGroup __RPC_FAR *__RPC_FAR *ppGroup);


void __RPC_STUB IPlayTLImpExp_CreateDissolve_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IPlayTLImpExp_CreateWipe_Proxy( 
    IPlayTLImpExp __RPC_FAR * This,
    /* [in] */ DWORD dwStart,
    /* [in] */ DWORD dwLength,
    /* [in] */ DWORD dwSourceTrack,
    /* [in] */ DWORD dwDestTrack,
    /* [in] */ DWORD dwWipeType,
    /* [out] */ IPlayTLIEGroup __RPC_FAR *__RPC_FAR *ppGroup);


void __RPC_STUB IPlayTLImpExp_CreateWipe_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IPlayTLImpExp_Create601_Proxy( 
    IPlayTLImpExp __RPC_FAR * This,
    /* [in] */ DWORD dwStart,
    /* [in] */ DWORD dwLength,
    /* [in] */ DWORD dwVideoTrack,
    /* [in][string] */ const OLECHAR __RPC_FAR *pszFileName,
    /* [out] */ IPlayTLIEGroup __RPC_FAR *__RPC_FAR *ppGroup);


void __RPC_STUB IPlayTLImpExp_Create601_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IPlayTLImpExp_CreateLive_Proxy( 
    IPlayTLImpExp __RPC_FAR * This,
    /* [in] */ DWORD dwStart,
    /* [in] */ DWORD dwLength,
    /* [in] */ DWORD dwSource,
    /* [out] */ IPlayTLIEGroup __RPC_FAR *__RPC_FAR *ppGroup);


void __RPC_STUB IPlayTLImpExp_CreateLive_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IPlayTLImpExp_CreateGPI_Proxy( 
    IPlayTLImpExp __RPC_FAR * This,
    /* [in] */ DWORD dwStart,
    /* [in] */ DWORD dwLength,
    /* [in] */ DWORD dwGPIPort,
    /* [in] */ DWORD dwGPIAction,
    /* [out] */ IPlayTLIEGroup __RPC_FAR *__RPC_FAR *ppGroup);


void __RPC_STUB IPlayTLImpExp_CreateGPI_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IPlayTLImpExp_GetEnumTracks_Proxy( 
    IPlayTLImpExp __RPC_FAR * This,
    /* [out] */ IPlayTLIETrackEnum __RPC_FAR *__RPC_FAR *ppIEnum);


void __RPC_STUB IPlayTLImpExp_GetEnumTracks_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IPlayTLImpExp_GetEnumGroups_Proxy( 
    IPlayTLImpExp __RPC_FAR * This,
    /* [out] */ IPlayTLIEGroupEnum __RPC_FAR *__RPC_FAR *ppIEnum);


void __RPC_STUB IPlayTLImpExp_GetEnumGroups_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IPlayTLImpExp_INTERFACE_DEFINED__ */


#ifndef __IPlayTLIETrackEnum_INTERFACE_DEFINED__
#define __IPlayTLIETrackEnum_INTERFACE_DEFINED__

/****************************************
 * Generated header for interface: IPlayTLIETrackEnum
 * at Tue Nov 23 05:28:36 1999
 * using MIDL 3.01.75
 ****************************************/
/* [local][uuid][object] */ 



EXTERN_C const IID IID_IPlayTLIETrackEnum;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    interface DECLSPEC_UUID("8335e749-ab3b-11ce-8468-0000b468276b")
    IPlayTLIETrackEnum : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE Next( 
            /* [in] */ ULONG celt,
            /* [out] */ IPlayTLIETrack __RPC_FAR *__RPC_FAR *rgelt,
            /* [out] */ ULONG __RPC_FAR *pceltFetched) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Skip( 
            /* [in] */ ULONG celt) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Reset( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Clone( 
            /* [out] */ IPlayTLIETrackEnum __RPC_FAR *__RPC_FAR *ppenum) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IPlayTLIETrackEnumVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            IPlayTLIETrackEnum __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            IPlayTLIETrackEnum __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            IPlayTLIETrackEnum __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Next )( 
            IPlayTLIETrackEnum __RPC_FAR * This,
            /* [in] */ ULONG celt,
            /* [out] */ IPlayTLIETrack __RPC_FAR *__RPC_FAR *rgelt,
            /* [out] */ ULONG __RPC_FAR *pceltFetched);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Skip )( 
            IPlayTLIETrackEnum __RPC_FAR * This,
            /* [in] */ ULONG celt);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Reset )( 
            IPlayTLIETrackEnum __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Clone )( 
            IPlayTLIETrackEnum __RPC_FAR * This,
            /* [out] */ IPlayTLIETrackEnum __RPC_FAR *__RPC_FAR *ppenum);
        
        END_INTERFACE
    } IPlayTLIETrackEnumVtbl;

    interface IPlayTLIETrackEnum
    {
        CONST_VTBL struct IPlayTLIETrackEnumVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IPlayTLIETrackEnum_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IPlayTLIETrackEnum_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IPlayTLIETrackEnum_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IPlayTLIETrackEnum_Next(This,celt,rgelt,pceltFetched)	\
    (This)->lpVtbl -> Next(This,celt,rgelt,pceltFetched)

#define IPlayTLIETrackEnum_Skip(This,celt)	\
    (This)->lpVtbl -> Skip(This,celt)

#define IPlayTLIETrackEnum_Reset(This)	\
    (This)->lpVtbl -> Reset(This)

#define IPlayTLIETrackEnum_Clone(This,ppenum)	\
    (This)->lpVtbl -> Clone(This,ppenum)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE IPlayTLIETrackEnum_Next_Proxy( 
    IPlayTLIETrackEnum __RPC_FAR * This,
    /* [in] */ ULONG celt,
    /* [out] */ IPlayTLIETrack __RPC_FAR *__RPC_FAR *rgelt,
    /* [out] */ ULONG __RPC_FAR *pceltFetched);


void __RPC_STUB IPlayTLIETrackEnum_Next_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IPlayTLIETrackEnum_Skip_Proxy( 
    IPlayTLIETrackEnum __RPC_FAR * This,
    /* [in] */ ULONG celt);


void __RPC_STUB IPlayTLIETrackEnum_Skip_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IPlayTLIETrackEnum_Reset_Proxy( 
    IPlayTLIETrackEnum __RPC_FAR * This);


void __RPC_STUB IPlayTLIETrackEnum_Reset_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IPlayTLIETrackEnum_Clone_Proxy( 
    IPlayTLIETrackEnum __RPC_FAR * This,
    /* [out] */ IPlayTLIETrackEnum __RPC_FAR *__RPC_FAR *ppenum);


void __RPC_STUB IPlayTLIETrackEnum_Clone_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IPlayTLIETrackEnum_INTERFACE_DEFINED__ */


#ifndef __IPlayTLIEGroupEnum_INTERFACE_DEFINED__
#define __IPlayTLIEGroupEnum_INTERFACE_DEFINED__

/****************************************
 * Generated header for interface: IPlayTLIEGroupEnum
 * at Tue Nov 23 05:28:36 1999
 * using MIDL 3.01.75
 ****************************************/
/* [local][uuid][object] */ 



EXTERN_C const IID IID_IPlayTLIEGroupEnum;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    interface DECLSPEC_UUID("8335e747-ab3b-11ce-8468-0000b468276b")
    IPlayTLIEGroupEnum : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE Next( 
            /* [in] */ ULONG celt,
            /* [out] */ IPlayTLIEGroup __RPC_FAR *__RPC_FAR *rgelt,
            /* [out] */ ULONG __RPC_FAR *pceltFetched) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Skip( 
            /* [in] */ ULONG celt) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Reset( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Clone( 
            /* [out] */ IPlayTLIEGroupEnum __RPC_FAR *__RPC_FAR *ppenum) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IPlayTLIEGroupEnumVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            IPlayTLIEGroupEnum __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            IPlayTLIEGroupEnum __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            IPlayTLIEGroupEnum __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Next )( 
            IPlayTLIEGroupEnum __RPC_FAR * This,
            /* [in] */ ULONG celt,
            /* [out] */ IPlayTLIEGroup __RPC_FAR *__RPC_FAR *rgelt,
            /* [out] */ ULONG __RPC_FAR *pceltFetched);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Skip )( 
            IPlayTLIEGroupEnum __RPC_FAR * This,
            /* [in] */ ULONG celt);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Reset )( 
            IPlayTLIEGroupEnum __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Clone )( 
            IPlayTLIEGroupEnum __RPC_FAR * This,
            /* [out] */ IPlayTLIEGroupEnum __RPC_FAR *__RPC_FAR *ppenum);
        
        END_INTERFACE
    } IPlayTLIEGroupEnumVtbl;

    interface IPlayTLIEGroupEnum
    {
        CONST_VTBL struct IPlayTLIEGroupEnumVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IPlayTLIEGroupEnum_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IPlayTLIEGroupEnum_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IPlayTLIEGroupEnum_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IPlayTLIEGroupEnum_Next(This,celt,rgelt,pceltFetched)	\
    (This)->lpVtbl -> Next(This,celt,rgelt,pceltFetched)

#define IPlayTLIEGroupEnum_Skip(This,celt)	\
    (This)->lpVtbl -> Skip(This,celt)

#define IPlayTLIEGroupEnum_Reset(This)	\
    (This)->lpVtbl -> Reset(This)

#define IPlayTLIEGroupEnum_Clone(This,ppenum)	\
    (This)->lpVtbl -> Clone(This,ppenum)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE IPlayTLIEGroupEnum_Next_Proxy( 
    IPlayTLIEGroupEnum __RPC_FAR * This,
    /* [in] */ ULONG celt,
    /* [out] */ IPlayTLIEGroup __RPC_FAR *__RPC_FAR *rgelt,
    /* [out] */ ULONG __RPC_FAR *pceltFetched);


void __RPC_STUB IPlayTLIEGroupEnum_Next_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IPlayTLIEGroupEnum_Skip_Proxy( 
    IPlayTLIEGroupEnum __RPC_FAR * This,
    /* [in] */ ULONG celt);


void __RPC_STUB IPlayTLIEGroupEnum_Skip_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IPlayTLIEGroupEnum_Reset_Proxy( 
    IPlayTLIEGroupEnum __RPC_FAR * This);


void __RPC_STUB IPlayTLIEGroupEnum_Reset_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IPlayTLIEGroupEnum_Clone_Proxy( 
    IPlayTLIEGroupEnum __RPC_FAR * This,
    /* [out] */ IPlayTLIEGroupEnum __RPC_FAR *__RPC_FAR *ppenum);


void __RPC_STUB IPlayTLIEGroupEnum_Clone_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IPlayTLIEGroupEnum_INTERFACE_DEFINED__ */


#ifndef __IPlayTLIEEventEnum_INTERFACE_DEFINED__
#define __IPlayTLIEEventEnum_INTERFACE_DEFINED__

/****************************************
 * Generated header for interface: IPlayTLIEEventEnum
 * at Tue Nov 23 05:28:36 1999
 * using MIDL 3.01.75
 ****************************************/
/* [local][uuid][object] */ 



EXTERN_C const IID IID_IPlayTLIEEventEnum;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    interface DECLSPEC_UUID("8335e74b-ab3b-11ce-8468-0000b468276b")
    IPlayTLIEEventEnum : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE Next( 
            /* [in] */ ULONG celt,
            /* [out] */ IPlayTLIEEvent __RPC_FAR *__RPC_FAR *rgelt,
            /* [out] */ ULONG __RPC_FAR *pceltFetched) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Skip( 
            /* [in] */ ULONG celt) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Reset( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Clone( 
            /* [out] */ IPlayTLIEEventEnum __RPC_FAR *__RPC_FAR *ppenum) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IPlayTLIEEventEnumVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            IPlayTLIEEventEnum __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            IPlayTLIEEventEnum __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            IPlayTLIEEventEnum __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Next )( 
            IPlayTLIEEventEnum __RPC_FAR * This,
            /* [in] */ ULONG celt,
            /* [out] */ IPlayTLIEEvent __RPC_FAR *__RPC_FAR *rgelt,
            /* [out] */ ULONG __RPC_FAR *pceltFetched);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Skip )( 
            IPlayTLIEEventEnum __RPC_FAR * This,
            /* [in] */ ULONG celt);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Reset )( 
            IPlayTLIEEventEnum __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Clone )( 
            IPlayTLIEEventEnum __RPC_FAR * This,
            /* [out] */ IPlayTLIEEventEnum __RPC_FAR *__RPC_FAR *ppenum);
        
        END_INTERFACE
    } IPlayTLIEEventEnumVtbl;

    interface IPlayTLIEEventEnum
    {
        CONST_VTBL struct IPlayTLIEEventEnumVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IPlayTLIEEventEnum_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IPlayTLIEEventEnum_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IPlayTLIEEventEnum_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IPlayTLIEEventEnum_Next(This,celt,rgelt,pceltFetched)	\
    (This)->lpVtbl -> Next(This,celt,rgelt,pceltFetched)

#define IPlayTLIEEventEnum_Skip(This,celt)	\
    (This)->lpVtbl -> Skip(This,celt)

#define IPlayTLIEEventEnum_Reset(This)	\
    (This)->lpVtbl -> Reset(This)

#define IPlayTLIEEventEnum_Clone(This,ppenum)	\
    (This)->lpVtbl -> Clone(This,ppenum)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE IPlayTLIEEventEnum_Next_Proxy( 
    IPlayTLIEEventEnum __RPC_FAR * This,
    /* [in] */ ULONG celt,
    /* [out] */ IPlayTLIEEvent __RPC_FAR *__RPC_FAR *rgelt,
    /* [out] */ ULONG __RPC_FAR *pceltFetched);


void __RPC_STUB IPlayTLIEEventEnum_Next_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IPlayTLIEEventEnum_Skip_Proxy( 
    IPlayTLIEEventEnum __RPC_FAR * This,
    /* [in] */ ULONG celt);


void __RPC_STUB IPlayTLIEEventEnum_Skip_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IPlayTLIEEventEnum_Reset_Proxy( 
    IPlayTLIEEventEnum __RPC_FAR * This);


void __RPC_STUB IPlayTLIEEventEnum_Reset_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IPlayTLIEEventEnum_Clone_Proxy( 
    IPlayTLIEEventEnum __RPC_FAR * This,
    /* [out] */ IPlayTLIEEventEnum __RPC_FAR *__RPC_FAR *ppenum);


void __RPC_STUB IPlayTLIEEventEnum_Clone_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IPlayTLIEEventEnum_INTERFACE_DEFINED__ */


#ifndef __IPlayTLIEGroup_INTERFACE_DEFINED__
#define __IPlayTLIEGroup_INTERFACE_DEFINED__

/****************************************
 * Generated header for interface: IPlayTLIEGroup
 * at Tue Nov 23 05:28:36 1999
 * using MIDL 3.01.75
 ****************************************/
/* [local][uuid][object] */ 



EXTERN_C const IID IID_IPlayTLIEGroup;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    interface DECLSPEC_UUID("8335e746-ab3b-11ce-8468-0000b468276b")
    IPlayTLIEGroup : public IUnknown
    {
    public:
        virtual CG_TYPE STDMETHODCALLTYPE GetType( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Delete( void) = 0;
        
        virtual DWORD STDMETHODCALLTYPE GetStartTime( void) = 0;
        
        virtual DWORD STDMETHODCALLTYPE GetEndTime( void) = 0;
        
        virtual DWORD STDMETHODCALLTYPE GetSourceStartTime( void) = 0;
        
        virtual DWORD STDMETHODCALLTYPE GetSourceEndTime( void) = 0;
        
        virtual DWORD STDMETHODCALLTYPE GetLength( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE AddEvent( 
            /* [in] */ CE_TYPE eventType,
            /* [in] */ DWORD dwStart,
            /* [in] */ DWORD dwLength,
            /* [in] */ DWORD dwSourceStart,
            /* [in] */ DWORD dwInfo) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetVideoEvent( 
            IPlayTLIEEvent __RPC_FAR *__RPC_FAR *ppEvent) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Move( 
            /* [in] */ long dwDeltaFrame) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE MoveTo( 
            /* [in] */ DWORD dwFrame) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE MoveSource( 
            /* [in] */ long dwDeltaFrames) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE MoveSourceTo( 
            /* [in] */ DWORD dwFrame) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE ChangeVideoTrack( 
            /* [in] */ DWORD dwVideoTrack) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE ChangeVideoTrackAndMove( 
            /* [in] */ DWORD dwVideoTrack,
            /* [in] */ long dwDeltaFrames) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE ChangeVideoTrackAndMoveTo( 
            /* [in] */ DWORD dwVideoTrack,
            /* [in] */ DWORD dwFrames) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetAudioLevel( 
            /* [in] */ DWORD dwAudioChannel,
            /* [out] */ ITrnPlayList __RPC_FAR *__RPC_FAR *ppList) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetAudioPan( 
            /* [in] */ DWORD dwAudioChannel,
            /* [out] */ ITrnPlayList __RPC_FAR *__RPC_FAR *ppList) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetAudioLevel( 
            /* [in] */ DWORD dwAudioChannel,
            /* [out] */ ITrnPlayList __RPC_FAR *__RPC_FAR *ppList) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetAudioPan( 
            /* [in] */ DWORD dwAudioChannel,
            /* [out] */ ITrnPlayList __RPC_FAR *__RPC_FAR *ppList) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE QueryGroupInfo( 
            /* [out] */ GROUPINFO __RPC_FAR *pQueryGroupInfo) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Split( 
            /* [in] */ DWORD dwTime,
            /* [out] */ IPlayTLIEGroup __RPC_FAR *__RPC_FAR *ppGroup) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Merge( 
            /* [in] */ IPlayTLIEGroup __RPC_FAR *pGroup) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetEnumEvents( 
            /* [out] */ IPlayTLIEEventEnum __RPC_FAR *__RPC_FAR *ppIEnum) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IPlayTLIEGroupVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            IPlayTLIEGroup __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            IPlayTLIEGroup __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            IPlayTLIEGroup __RPC_FAR * This);
        
        CG_TYPE ( STDMETHODCALLTYPE __RPC_FAR *GetType )( 
            IPlayTLIEGroup __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Delete )( 
            IPlayTLIEGroup __RPC_FAR * This);
        
        DWORD ( STDMETHODCALLTYPE __RPC_FAR *GetStartTime )( 
            IPlayTLIEGroup __RPC_FAR * This);
        
        DWORD ( STDMETHODCALLTYPE __RPC_FAR *GetEndTime )( 
            IPlayTLIEGroup __RPC_FAR * This);
        
        DWORD ( STDMETHODCALLTYPE __RPC_FAR *GetSourceStartTime )( 
            IPlayTLIEGroup __RPC_FAR * This);
        
        DWORD ( STDMETHODCALLTYPE __RPC_FAR *GetSourceEndTime )( 
            IPlayTLIEGroup __RPC_FAR * This);
        
        DWORD ( STDMETHODCALLTYPE __RPC_FAR *GetLength )( 
            IPlayTLIEGroup __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *AddEvent )( 
            IPlayTLIEGroup __RPC_FAR * This,
            /* [in] */ CE_TYPE eventType,
            /* [in] */ DWORD dwStart,
            /* [in] */ DWORD dwLength,
            /* [in] */ DWORD dwSourceStart,
            /* [in] */ DWORD dwInfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetVideoEvent )( 
            IPlayTLIEGroup __RPC_FAR * This,
            IPlayTLIEEvent __RPC_FAR *__RPC_FAR *ppEvent);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Move )( 
            IPlayTLIEGroup __RPC_FAR * This,
            /* [in] */ long dwDeltaFrame);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *MoveTo )( 
            IPlayTLIEGroup __RPC_FAR * This,
            /* [in] */ DWORD dwFrame);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *MoveSource )( 
            IPlayTLIEGroup __RPC_FAR * This,
            /* [in] */ long dwDeltaFrames);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *MoveSourceTo )( 
            IPlayTLIEGroup __RPC_FAR * This,
            /* [in] */ DWORD dwFrame);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *ChangeVideoTrack )( 
            IPlayTLIEGroup __RPC_FAR * This,
            /* [in] */ DWORD dwVideoTrack);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *ChangeVideoTrackAndMove )( 
            IPlayTLIEGroup __RPC_FAR * This,
            /* [in] */ DWORD dwVideoTrack,
            /* [in] */ long dwDeltaFrames);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *ChangeVideoTrackAndMoveTo )( 
            IPlayTLIEGroup __RPC_FAR * This,
            /* [in] */ DWORD dwVideoTrack,
            /* [in] */ DWORD dwFrames);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetAudioLevel )( 
            IPlayTLIEGroup __RPC_FAR * This,
            /* [in] */ DWORD dwAudioChannel,
            /* [out] */ ITrnPlayList __RPC_FAR *__RPC_FAR *ppList);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetAudioPan )( 
            IPlayTLIEGroup __RPC_FAR * This,
            /* [in] */ DWORD dwAudioChannel,
            /* [out] */ ITrnPlayList __RPC_FAR *__RPC_FAR *ppList);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetAudioLevel )( 
            IPlayTLIEGroup __RPC_FAR * This,
            /* [in] */ DWORD dwAudioChannel,
            /* [out] */ ITrnPlayList __RPC_FAR *__RPC_FAR *ppList);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetAudioPan )( 
            IPlayTLIEGroup __RPC_FAR * This,
            /* [in] */ DWORD dwAudioChannel,
            /* [out] */ ITrnPlayList __RPC_FAR *__RPC_FAR *ppList);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryGroupInfo )( 
            IPlayTLIEGroup __RPC_FAR * This,
            /* [out] */ GROUPINFO __RPC_FAR *pQueryGroupInfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Split )( 
            IPlayTLIEGroup __RPC_FAR * This,
            /* [in] */ DWORD dwTime,
            /* [out] */ IPlayTLIEGroup __RPC_FAR *__RPC_FAR *ppGroup);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Merge )( 
            IPlayTLIEGroup __RPC_FAR * This,
            /* [in] */ IPlayTLIEGroup __RPC_FAR *pGroup);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetEnumEvents )( 
            IPlayTLIEGroup __RPC_FAR * This,
            /* [out] */ IPlayTLIEEventEnum __RPC_FAR *__RPC_FAR *ppIEnum);
        
        END_INTERFACE
    } IPlayTLIEGroupVtbl;

    interface IPlayTLIEGroup
    {
        CONST_VTBL struct IPlayTLIEGroupVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IPlayTLIEGroup_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IPlayTLIEGroup_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IPlayTLIEGroup_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IPlayTLIEGroup_GetType(This)	\
    (This)->lpVtbl -> GetType(This)

#define IPlayTLIEGroup_Delete(This)	\
    (This)->lpVtbl -> Delete(This)

#define IPlayTLIEGroup_GetStartTime(This)	\
    (This)->lpVtbl -> GetStartTime(This)

#define IPlayTLIEGroup_GetEndTime(This)	\
    (This)->lpVtbl -> GetEndTime(This)

#define IPlayTLIEGroup_GetSourceStartTime(This)	\
    (This)->lpVtbl -> GetSourceStartTime(This)

#define IPlayTLIEGroup_GetSourceEndTime(This)	\
    (This)->lpVtbl -> GetSourceEndTime(This)

#define IPlayTLIEGroup_GetLength(This)	\
    (This)->lpVtbl -> GetLength(This)

#define IPlayTLIEGroup_AddEvent(This,eventType,dwStart,dwLength,dwSourceStart,dwInfo)	\
    (This)->lpVtbl -> AddEvent(This,eventType,dwStart,dwLength,dwSourceStart,dwInfo)

#define IPlayTLIEGroup_GetVideoEvent(This,ppEvent)	\
    (This)->lpVtbl -> GetVideoEvent(This,ppEvent)

#define IPlayTLIEGroup_Move(This,dwDeltaFrame)	\
    (This)->lpVtbl -> Move(This,dwDeltaFrame)

#define IPlayTLIEGroup_MoveTo(This,dwFrame)	\
    (This)->lpVtbl -> MoveTo(This,dwFrame)

#define IPlayTLIEGroup_MoveSource(This,dwDeltaFrames)	\
    (This)->lpVtbl -> MoveSource(This,dwDeltaFrames)

#define IPlayTLIEGroup_MoveSourceTo(This,dwFrame)	\
    (This)->lpVtbl -> MoveSourceTo(This,dwFrame)

#define IPlayTLIEGroup_ChangeVideoTrack(This,dwVideoTrack)	\
    (This)->lpVtbl -> ChangeVideoTrack(This,dwVideoTrack)

#define IPlayTLIEGroup_ChangeVideoTrackAndMove(This,dwVideoTrack,dwDeltaFrames)	\
    (This)->lpVtbl -> ChangeVideoTrackAndMove(This,dwVideoTrack,dwDeltaFrames)

#define IPlayTLIEGroup_ChangeVideoTrackAndMoveTo(This,dwVideoTrack,dwFrames)	\
    (This)->lpVtbl -> ChangeVideoTrackAndMoveTo(This,dwVideoTrack,dwFrames)

#define IPlayTLIEGroup_GetAudioLevel(This,dwAudioChannel,ppList)	\
    (This)->lpVtbl -> GetAudioLevel(This,dwAudioChannel,ppList)

#define IPlayTLIEGroup_GetAudioPan(This,dwAudioChannel,ppList)	\
    (This)->lpVtbl -> GetAudioPan(This,dwAudioChannel,ppList)

#define IPlayTLIEGroup_SetAudioLevel(This,dwAudioChannel,ppList)	\
    (This)->lpVtbl -> SetAudioLevel(This,dwAudioChannel,ppList)

#define IPlayTLIEGroup_SetAudioPan(This,dwAudioChannel,ppList)	\
    (This)->lpVtbl -> SetAudioPan(This,dwAudioChannel,ppList)

#define IPlayTLIEGroup_QueryGroupInfo(This,pQueryGroupInfo)	\
    (This)->lpVtbl -> QueryGroupInfo(This,pQueryGroupInfo)

#define IPlayTLIEGroup_Split(This,dwTime,ppGroup)	\
    (This)->lpVtbl -> Split(This,dwTime,ppGroup)

#define IPlayTLIEGroup_Merge(This,pGroup)	\
    (This)->lpVtbl -> Merge(This,pGroup)

#define IPlayTLIEGroup_GetEnumEvents(This,ppIEnum)	\
    (This)->lpVtbl -> GetEnumEvents(This,ppIEnum)

#endif /* COBJMACROS */


#endif 	/* C style interface */



CG_TYPE STDMETHODCALLTYPE IPlayTLIEGroup_GetType_Proxy( 
    IPlayTLIEGroup __RPC_FAR * This);


void __RPC_STUB IPlayTLIEGroup_GetType_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IPlayTLIEGroup_Delete_Proxy( 
    IPlayTLIEGroup __RPC_FAR * This);


void __RPC_STUB IPlayTLIEGroup_Delete_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


DWORD STDMETHODCALLTYPE IPlayTLIEGroup_GetStartTime_Proxy( 
    IPlayTLIEGroup __RPC_FAR * This);


void __RPC_STUB IPlayTLIEGroup_GetStartTime_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


DWORD STDMETHODCALLTYPE IPlayTLIEGroup_GetEndTime_Proxy( 
    IPlayTLIEGroup __RPC_FAR * This);


void __RPC_STUB IPlayTLIEGroup_GetEndTime_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


DWORD STDMETHODCALLTYPE IPlayTLIEGroup_GetSourceStartTime_Proxy( 
    IPlayTLIEGroup __RPC_FAR * This);


void __RPC_STUB IPlayTLIEGroup_GetSourceStartTime_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


DWORD STDMETHODCALLTYPE IPlayTLIEGroup_GetSourceEndTime_Proxy( 
    IPlayTLIEGroup __RPC_FAR * This);


void __RPC_STUB IPlayTLIEGroup_GetSourceEndTime_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


DWORD STDMETHODCALLTYPE IPlayTLIEGroup_GetLength_Proxy( 
    IPlayTLIEGroup __RPC_FAR * This);


void __RPC_STUB IPlayTLIEGroup_GetLength_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IPlayTLIEGroup_AddEvent_Proxy( 
    IPlayTLIEGroup __RPC_FAR * This,
    /* [in] */ CE_TYPE eventType,
    /* [in] */ DWORD dwStart,
    /* [in] */ DWORD dwLength,
    /* [in] */ DWORD dwSourceStart,
    /* [in] */ DWORD dwInfo);


void __RPC_STUB IPlayTLIEGroup_AddEvent_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IPlayTLIEGroup_GetVideoEvent_Proxy( 
    IPlayTLIEGroup __RPC_FAR * This,
    IPlayTLIEEvent __RPC_FAR *__RPC_FAR *ppEvent);


void __RPC_STUB IPlayTLIEGroup_GetVideoEvent_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IPlayTLIEGroup_Move_Proxy( 
    IPlayTLIEGroup __RPC_FAR * This,
    /* [in] */ long dwDeltaFrame);


void __RPC_STUB IPlayTLIEGroup_Move_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IPlayTLIEGroup_MoveTo_Proxy( 
    IPlayTLIEGroup __RPC_FAR * This,
    /* [in] */ DWORD dwFrame);


void __RPC_STUB IPlayTLIEGroup_MoveTo_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IPlayTLIEGroup_MoveSource_Proxy( 
    IPlayTLIEGroup __RPC_FAR * This,
    /* [in] */ long dwDeltaFrames);


void __RPC_STUB IPlayTLIEGroup_MoveSource_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IPlayTLIEGroup_MoveSourceTo_Proxy( 
    IPlayTLIEGroup __RPC_FAR * This,
    /* [in] */ DWORD dwFrame);


void __RPC_STUB IPlayTLIEGroup_MoveSourceTo_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IPlayTLIEGroup_ChangeVideoTrack_Proxy( 
    IPlayTLIEGroup __RPC_FAR * This,
    /* [in] */ DWORD dwVideoTrack);


void __RPC_STUB IPlayTLIEGroup_ChangeVideoTrack_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IPlayTLIEGroup_ChangeVideoTrackAndMove_Proxy( 
    IPlayTLIEGroup __RPC_FAR * This,
    /* [in] */ DWORD dwVideoTrack,
    /* [in] */ long dwDeltaFrames);


void __RPC_STUB IPlayTLIEGroup_ChangeVideoTrackAndMove_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IPlayTLIEGroup_ChangeVideoTrackAndMoveTo_Proxy( 
    IPlayTLIEGroup __RPC_FAR * This,
    /* [in] */ DWORD dwVideoTrack,
    /* [in] */ DWORD dwFrames);


void __RPC_STUB IPlayTLIEGroup_ChangeVideoTrackAndMoveTo_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IPlayTLIEGroup_GetAudioLevel_Proxy( 
    IPlayTLIEGroup __RPC_FAR * This,
    /* [in] */ DWORD dwAudioChannel,
    /* [out] */ ITrnPlayList __RPC_FAR *__RPC_FAR *ppList);


void __RPC_STUB IPlayTLIEGroup_GetAudioLevel_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IPlayTLIEGroup_GetAudioPan_Proxy( 
    IPlayTLIEGroup __RPC_FAR * This,
    /* [in] */ DWORD dwAudioChannel,
    /* [out] */ ITrnPlayList __RPC_FAR *__RPC_FAR *ppList);


void __RPC_STUB IPlayTLIEGroup_GetAudioPan_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IPlayTLIEGroup_SetAudioLevel_Proxy( 
    IPlayTLIEGroup __RPC_FAR * This,
    /* [in] */ DWORD dwAudioChannel,
    /* [out] */ ITrnPlayList __RPC_FAR *__RPC_FAR *ppList);


void __RPC_STUB IPlayTLIEGroup_SetAudioLevel_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IPlayTLIEGroup_SetAudioPan_Proxy( 
    IPlayTLIEGroup __RPC_FAR * This,
    /* [in] */ DWORD dwAudioChannel,
    /* [out] */ ITrnPlayList __RPC_FAR *__RPC_FAR *ppList);


void __RPC_STUB IPlayTLIEGroup_SetAudioPan_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IPlayTLIEGroup_QueryGroupInfo_Proxy( 
    IPlayTLIEGroup __RPC_FAR * This,
    /* [out] */ GROUPINFO __RPC_FAR *pQueryGroupInfo);


void __RPC_STUB IPlayTLIEGroup_QueryGroupInfo_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IPlayTLIEGroup_Split_Proxy( 
    IPlayTLIEGroup __RPC_FAR * This,
    /* [in] */ DWORD dwTime,
    /* [out] */ IPlayTLIEGroup __RPC_FAR *__RPC_FAR *ppGroup);


void __RPC_STUB IPlayTLIEGroup_Split_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IPlayTLIEGroup_Merge_Proxy( 
    IPlayTLIEGroup __RPC_FAR * This,
    /* [in] */ IPlayTLIEGroup __RPC_FAR *pGroup);


void __RPC_STUB IPlayTLIEGroup_Merge_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IPlayTLIEGroup_GetEnumEvents_Proxy( 
    IPlayTLIEGroup __RPC_FAR * This,
    /* [out] */ IPlayTLIEEventEnum __RPC_FAR *__RPC_FAR *ppIEnum);


void __RPC_STUB IPlayTLIEGroup_GetEnumEvents_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IPlayTLIEGroup_INTERFACE_DEFINED__ */


#ifndef __IPlayTLIETrack_INTERFACE_DEFINED__
#define __IPlayTLIETrack_INTERFACE_DEFINED__

/****************************************
 * Generated header for interface: IPlayTLIETrack
 * at Tue Nov 23 05:28:36 1999
 * using MIDL 3.01.75
 ****************************************/
/* [local][uuid][object] */ 



EXTERN_C const IID IID_IPlayTLIETrack;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    interface DECLSPEC_UUID("8335e748-ab3b-11ce-8468-0000b468276b")
    IPlayTLIETrack : public IUnknown
    {
    public:
        virtual DWORD STDMETHODCALLTYPE GetLength( void) = 0;
        
        virtual CE_TYPE STDMETHODCALLTYPE GetType( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetEnumEvents( 
            /* [out] */ IPlayTLIEEventEnum __RPC_FAR *__RPC_FAR *ppIEnum) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IPlayTLIETrackVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            IPlayTLIETrack __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            IPlayTLIETrack __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            IPlayTLIETrack __RPC_FAR * This);
        
        DWORD ( STDMETHODCALLTYPE __RPC_FAR *GetLength )( 
            IPlayTLIETrack __RPC_FAR * This);
        
        CE_TYPE ( STDMETHODCALLTYPE __RPC_FAR *GetType )( 
            IPlayTLIETrack __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetEnumEvents )( 
            IPlayTLIETrack __RPC_FAR * This,
            /* [out] */ IPlayTLIEEventEnum __RPC_FAR *__RPC_FAR *ppIEnum);
        
        END_INTERFACE
    } IPlayTLIETrackVtbl;

    interface IPlayTLIETrack
    {
        CONST_VTBL struct IPlayTLIETrackVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IPlayTLIETrack_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IPlayTLIETrack_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IPlayTLIETrack_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IPlayTLIETrack_GetLength(This)	\
    (This)->lpVtbl -> GetLength(This)

#define IPlayTLIETrack_GetType(This)	\
    (This)->lpVtbl -> GetType(This)

#define IPlayTLIETrack_GetEnumEvents(This,ppIEnum)	\
    (This)->lpVtbl -> GetEnumEvents(This,ppIEnum)

#endif /* COBJMACROS */


#endif 	/* C style interface */



DWORD STDMETHODCALLTYPE IPlayTLIETrack_GetLength_Proxy( 
    IPlayTLIETrack __RPC_FAR * This);


void __RPC_STUB IPlayTLIETrack_GetLength_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


CE_TYPE STDMETHODCALLTYPE IPlayTLIETrack_GetType_Proxy( 
    IPlayTLIETrack __RPC_FAR * This);


void __RPC_STUB IPlayTLIETrack_GetType_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IPlayTLIETrack_GetEnumEvents_Proxy( 
    IPlayTLIETrack __RPC_FAR * This,
    /* [out] */ IPlayTLIEEventEnum __RPC_FAR *__RPC_FAR *ppIEnum);


void __RPC_STUB IPlayTLIETrack_GetEnumEvents_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IPlayTLIETrack_INTERFACE_DEFINED__ */


#ifndef __IPlayTLIEEvent_INTERFACE_DEFINED__
#define __IPlayTLIEEvent_INTERFACE_DEFINED__

/****************************************
 * Generated header for interface: IPlayTLIEEvent
 * at Tue Nov 23 05:28:36 1999
 * using MIDL 3.01.75
 ****************************************/
/* [local][uuid][object] */ 



EXTERN_C const IID IID_IPlayTLIEEvent;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    interface DECLSPEC_UUID("8335e74a-ab3b-11ce-8468-0000b468276b")
    IPlayTLIEEvent : public IUnknown
    {
    public:
        virtual DWORD STDMETHODCALLTYPE GetStartTime( void) = 0;
        
        virtual DWORD STDMETHODCALLTYPE GetEndTime( void) = 0;
        
        virtual DWORD STDMETHODCALLTYPE GetLength( void) = 0;
        
        virtual DWORD STDMETHODCALLTYPE GetSourceStartTime( void) = 0;
        
        virtual DWORD STDMETHODCALLTYPE GetSourceEndTime( void) = 0;
        
        virtual DWORD STDMETHODCALLTYPE MoveTo( 
            /* [in] */ DWORD dwTime) = 0;
        
        virtual DWORD STDMETHODCALLTYPE Move( 
            /* [in] */ long dwShiftTime) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetTrack( 
            /* [out] */ IPlayTLIETrack __RPC_FAR *__RPC_FAR *ppTrack) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetGroup( 
            /* [out] */ IPlayTLIEGroup __RPC_FAR *__RPC_FAR *ppGroup) = 0;
        
        virtual CE_TYPE STDMETHODCALLTYPE GetType( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetAudioLevel( 
            /* [out] */ ITrnPlayList __RPC_FAR *__RPC_FAR *ppList) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetAudioPan( 
            /* [out] */ ITrnPlayList __RPC_FAR *__RPC_FAR *ppList) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetAudioLevel( 
            /* [in] */ ITrnPlayList __RPC_FAR *ppList) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetAudioPan( 
            /* [in] */ ITrnPlayList __RPC_FAR *ppList) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IPlayTLIEEventVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            IPlayTLIEEvent __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            IPlayTLIEEvent __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            IPlayTLIEEvent __RPC_FAR * This);
        
        DWORD ( STDMETHODCALLTYPE __RPC_FAR *GetStartTime )( 
            IPlayTLIEEvent __RPC_FAR * This);
        
        DWORD ( STDMETHODCALLTYPE __RPC_FAR *GetEndTime )( 
            IPlayTLIEEvent __RPC_FAR * This);
        
        DWORD ( STDMETHODCALLTYPE __RPC_FAR *GetLength )( 
            IPlayTLIEEvent __RPC_FAR * This);
        
        DWORD ( STDMETHODCALLTYPE __RPC_FAR *GetSourceStartTime )( 
            IPlayTLIEEvent __RPC_FAR * This);
        
        DWORD ( STDMETHODCALLTYPE __RPC_FAR *GetSourceEndTime )( 
            IPlayTLIEEvent __RPC_FAR * This);
        
        DWORD ( STDMETHODCALLTYPE __RPC_FAR *MoveTo )( 
            IPlayTLIEEvent __RPC_FAR * This,
            /* [in] */ DWORD dwTime);
        
        DWORD ( STDMETHODCALLTYPE __RPC_FAR *Move )( 
            IPlayTLIEEvent __RPC_FAR * This,
            /* [in] */ long dwShiftTime);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTrack )( 
            IPlayTLIEEvent __RPC_FAR * This,
            /* [out] */ IPlayTLIETrack __RPC_FAR *__RPC_FAR *ppTrack);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetGroup )( 
            IPlayTLIEEvent __RPC_FAR * This,
            /* [out] */ IPlayTLIEGroup __RPC_FAR *__RPC_FAR *ppGroup);
        
        CE_TYPE ( STDMETHODCALLTYPE __RPC_FAR *GetType )( 
            IPlayTLIEEvent __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetAudioLevel )( 
            IPlayTLIEEvent __RPC_FAR * This,
            /* [out] */ ITrnPlayList __RPC_FAR *__RPC_FAR *ppList);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetAudioPan )( 
            IPlayTLIEEvent __RPC_FAR * This,
            /* [out] */ ITrnPlayList __RPC_FAR *__RPC_FAR *ppList);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetAudioLevel )( 
            IPlayTLIEEvent __RPC_FAR * This,
            /* [in] */ ITrnPlayList __RPC_FAR *ppList);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetAudioPan )( 
            IPlayTLIEEvent __RPC_FAR * This,
            /* [in] */ ITrnPlayList __RPC_FAR *ppList);
        
        END_INTERFACE
    } IPlayTLIEEventVtbl;

    interface IPlayTLIEEvent
    {
        CONST_VTBL struct IPlayTLIEEventVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IPlayTLIEEvent_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IPlayTLIEEvent_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IPlayTLIEEvent_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IPlayTLIEEvent_GetStartTime(This)	\
    (This)->lpVtbl -> GetStartTime(This)

#define IPlayTLIEEvent_GetEndTime(This)	\
    (This)->lpVtbl -> GetEndTime(This)

#define IPlayTLIEEvent_GetLength(This)	\
    (This)->lpVtbl -> GetLength(This)

#define IPlayTLIEEvent_GetSourceStartTime(This)	\
    (This)->lpVtbl -> GetSourceStartTime(This)

#define IPlayTLIEEvent_GetSourceEndTime(This)	\
    (This)->lpVtbl -> GetSourceEndTime(This)

#define IPlayTLIEEvent_MoveTo(This,dwTime)	\
    (This)->lpVtbl -> MoveTo(This,dwTime)

#define IPlayTLIEEvent_Move(This,dwShiftTime)	\
    (This)->lpVtbl -> Move(This,dwShiftTime)

#define IPlayTLIEEvent_GetTrack(This,ppTrack)	\
    (This)->lpVtbl -> GetTrack(This,ppTrack)

#define IPlayTLIEEvent_GetGroup(This,ppGroup)	\
    (This)->lpVtbl -> GetGroup(This,ppGroup)

#define IPlayTLIEEvent_GetType(This)	\
    (This)->lpVtbl -> GetType(This)

#define IPlayTLIEEvent_GetAudioLevel(This,ppList)	\
    (This)->lpVtbl -> GetAudioLevel(This,ppList)

#define IPlayTLIEEvent_GetAudioPan(This,ppList)	\
    (This)->lpVtbl -> GetAudioPan(This,ppList)

#define IPlayTLIEEvent_SetAudioLevel(This,ppList)	\
    (This)->lpVtbl -> SetAudioLevel(This,ppList)

#define IPlayTLIEEvent_SetAudioPan(This,ppList)	\
    (This)->lpVtbl -> SetAudioPan(This,ppList)

#endif /* COBJMACROS */


#endif 	/* C style interface */



DWORD STDMETHODCALLTYPE IPlayTLIEEvent_GetStartTime_Proxy( 
    IPlayTLIEEvent __RPC_FAR * This);


void __RPC_STUB IPlayTLIEEvent_GetStartTime_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


DWORD STDMETHODCALLTYPE IPlayTLIEEvent_GetEndTime_Proxy( 
    IPlayTLIEEvent __RPC_FAR * This);


void __RPC_STUB IPlayTLIEEvent_GetEndTime_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


DWORD STDMETHODCALLTYPE IPlayTLIEEvent_GetLength_Proxy( 
    IPlayTLIEEvent __RPC_FAR * This);


void __RPC_STUB IPlayTLIEEvent_GetLength_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


DWORD STDMETHODCALLTYPE IPlayTLIEEvent_GetSourceStartTime_Proxy( 
    IPlayTLIEEvent __RPC_FAR * This);


void __RPC_STUB IPlayTLIEEvent_GetSourceStartTime_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


DWORD STDMETHODCALLTYPE IPlayTLIEEvent_GetSourceEndTime_Proxy( 
    IPlayTLIEEvent __RPC_FAR * This);


void __RPC_STUB IPlayTLIEEvent_GetSourceEndTime_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


DWORD STDMETHODCALLTYPE IPlayTLIEEvent_MoveTo_Proxy( 
    IPlayTLIEEvent __RPC_FAR * This,
    /* [in] */ DWORD dwTime);


void __RPC_STUB IPlayTLIEEvent_MoveTo_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


DWORD STDMETHODCALLTYPE IPlayTLIEEvent_Move_Proxy( 
    IPlayTLIEEvent __RPC_FAR * This,
    /* [in] */ long dwShiftTime);


void __RPC_STUB IPlayTLIEEvent_Move_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IPlayTLIEEvent_GetTrack_Proxy( 
    IPlayTLIEEvent __RPC_FAR * This,
    /* [out] */ IPlayTLIETrack __RPC_FAR *__RPC_FAR *ppTrack);


void __RPC_STUB IPlayTLIEEvent_GetTrack_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IPlayTLIEEvent_GetGroup_Proxy( 
    IPlayTLIEEvent __RPC_FAR * This,
    /* [out] */ IPlayTLIEGroup __RPC_FAR *__RPC_FAR *ppGroup);


void __RPC_STUB IPlayTLIEEvent_GetGroup_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


CE_TYPE STDMETHODCALLTYPE IPlayTLIEEvent_GetType_Proxy( 
    IPlayTLIEEvent __RPC_FAR * This);


void __RPC_STUB IPlayTLIEEvent_GetType_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IPlayTLIEEvent_GetAudioLevel_Proxy( 
    IPlayTLIEEvent __RPC_FAR * This,
    /* [out] */ ITrnPlayList __RPC_FAR *__RPC_FAR *ppList);


void __RPC_STUB IPlayTLIEEvent_GetAudioLevel_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IPlayTLIEEvent_GetAudioPan_Proxy( 
    IPlayTLIEEvent __RPC_FAR * This,
    /* [out] */ ITrnPlayList __RPC_FAR *__RPC_FAR *ppList);


void __RPC_STUB IPlayTLIEEvent_GetAudioPan_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IPlayTLIEEvent_SetAudioLevel_Proxy( 
    IPlayTLIEEvent __RPC_FAR * This,
    /* [in] */ ITrnPlayList __RPC_FAR *ppList);


void __RPC_STUB IPlayTLIEEvent_SetAudioLevel_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IPlayTLIEEvent_SetAudioPan_Proxy( 
    IPlayTLIEEvent __RPC_FAR * This,
    /* [in] */ ITrnPlayList __RPC_FAR *ppList);


void __RPC_STUB IPlayTLIEEvent_SetAudioPan_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IPlayTLIEEvent_INTERFACE_DEFINED__ */


/* Additional Prototypes for ALL interfaces */

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif
