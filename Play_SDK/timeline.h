/* this ALWAYS GENERATED file contains the definitions for the interfaces */


/* File created by MIDL compiler version 3.01.75 */
/* at Tue Nov 23 05:02:07 1999
 */
/* Compiler settings for timeline.idl:
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

#ifndef __timeline_h__
#define __timeline_h__

#ifdef __cplusplus
extern "C"{
#endif 

/* Forward Declarations */ 

#ifndef __IPlayTLFunctionItem_FWD_DEFINED__
#define __IPlayTLFunctionItem_FWD_DEFINED__
typedef interface IPlayTLFunctionItem IPlayTLFunctionItem;
#endif 	/* __IPlayTLFunctionItem_FWD_DEFINED__ */


#ifndef __IPlayTLCommon_FWD_DEFINED__
#define __IPlayTLCommon_FWD_DEFINED__
typedef interface IPlayTLCommon IPlayTLCommon;
#endif 	/* __IPlayTLCommon_FWD_DEFINED__ */


#ifndef __IPlayTLGroup_FWD_DEFINED__
#define __IPlayTLGroup_FWD_DEFINED__
typedef interface IPlayTLGroup IPlayTLGroup;
#endif 	/* __IPlayTLGroup_FWD_DEFINED__ */


#ifndef __IPlayTLGroupPrivate_FWD_DEFINED__
#define __IPlayTLGroupPrivate_FWD_DEFINED__
typedef interface IPlayTLGroupPrivate IPlayTLGroupPrivate;
#endif 	/* __IPlayTLGroupPrivate_FWD_DEFINED__ */


#ifndef __IPlayTimeLine_FWD_DEFINED__
#define __IPlayTimeLine_FWD_DEFINED__
typedef interface IPlayTimeLine IPlayTimeLine;
#endif 	/* __IPlayTimeLine_FWD_DEFINED__ */


#ifndef __IPlayTLTrack_FWD_DEFINED__
#define __IPlayTLTrack_FWD_DEFINED__
typedef interface IPlayTLTrack IPlayTLTrack;
#endif 	/* __IPlayTLTrack_FWD_DEFINED__ */


#ifndef __IPlayTLValueTrack_FWD_DEFINED__
#define __IPlayTLValueTrack_FWD_DEFINED__
typedef interface IPlayTLValueTrack IPlayTLValueTrack;
#endif 	/* __IPlayTLValueTrack_FWD_DEFINED__ */


#ifndef __IPlayTLEvent_FWD_DEFINED__
#define __IPlayTLEvent_FWD_DEFINED__
typedef interface IPlayTLEvent IPlayTLEvent;
#endif 	/* __IPlayTLEvent_FWD_DEFINED__ */


#ifndef __IPlayTLValueEvent_FWD_DEFINED__
#define __IPlayTLValueEvent_FWD_DEFINED__
typedef interface IPlayTLValueEvent IPlayTLValueEvent;
#endif 	/* __IPlayTLValueEvent_FWD_DEFINED__ */


#ifndef __IPlayTLView_FWD_DEFINED__
#define __IPlayTLView_FWD_DEFINED__
typedef interface IPlayTLView IPlayTLView;
#endif 	/* __IPlayTLView_FWD_DEFINED__ */


#ifndef __IPlayTLViewPrivate_FWD_DEFINED__
#define __IPlayTLViewPrivate_FWD_DEFINED__
typedef interface IPlayTLViewPrivate IPlayTLViewPrivate;
#endif 	/* __IPlayTLViewPrivate_FWD_DEFINED__ */


#ifndef __IPlayTLTrackPrivate_FWD_DEFINED__
#define __IPlayTLTrackPrivate_FWD_DEFINED__
typedef interface IPlayTLTrackPrivate IPlayTLTrackPrivate;
#endif 	/* __IPlayTLTrackPrivate_FWD_DEFINED__ */


#ifndef __IPlayTLEventPrivate_FWD_DEFINED__
#define __IPlayTLEventPrivate_FWD_DEFINED__
typedef interface IPlayTLEventPrivate IPlayTLEventPrivate;
#endif 	/* __IPlayTLEventPrivate_FWD_DEFINED__ */


#ifndef __IPlayTLAdviser_FWD_DEFINED__
#define __IPlayTLAdviser_FWD_DEFINED__
typedef interface IPlayTLAdviser IPlayTLAdviser;
#endif 	/* __IPlayTLAdviser_FWD_DEFINED__ */


#ifndef __IPlayTLAdviser2_FWD_DEFINED__
#define __IPlayTLAdviser2_FWD_DEFINED__
typedef interface IPlayTLAdviser2 IPlayTLAdviser2;
#endif 	/* __IPlayTLAdviser2_FWD_DEFINED__ */


#ifndef __IPlayLButtonAdviseSink_FWD_DEFINED__
#define __IPlayLButtonAdviseSink_FWD_DEFINED__
typedef interface IPlayLButtonAdviseSink IPlayLButtonAdviseSink;
#endif 	/* __IPlayLButtonAdviseSink_FWD_DEFINED__ */


#ifndef __IPlayTLManagerAdviser_FWD_DEFINED__
#define __IPlayTLManagerAdviser_FWD_DEFINED__
typedef interface IPlayTLManagerAdviser IPlayTLManagerAdviser;
#endif 	/* __IPlayTLManagerAdviser_FWD_DEFINED__ */


#ifndef __IPlayTLCloneAppObject_FWD_DEFINED__
#define __IPlayTLCloneAppObject_FWD_DEFINED__
typedef interface IPlayTLCloneAppObject IPlayTLCloneAppObject;
#endif 	/* __IPlayTLCloneAppObject_FWD_DEFINED__ */


/* header files for imported files */
#include "objidl.h"
#include "spline.h"
#include "gxlate.h"
#include "plyctl.h"

void __RPC_FAR * __RPC_USER MIDL_user_allocate(size_t);
void __RPC_USER MIDL_user_free( void __RPC_FAR * ); 

/****************************************
 * Generated header for interface: __MIDL_itf_timeline_0000
 * at Tue Nov 23 05:02:07 1999
 * using MIDL 3.01.75
 ****************************************/
/* [local] */ 



interface IValidSegmentList2;












interface IValidSegmentList;


extern RPC_IF_HANDLE __MIDL_itf_timeline_0000_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_timeline_0000_v0_0_s_ifspec;

#ifndef __IPlayTLFunctionItem_INTERFACE_DEFINED__
#define __IPlayTLFunctionItem_INTERFACE_DEFINED__

/****************************************
 * Generated header for interface: IPlayTLFunctionItem
 * at Tue Nov 23 05:02:07 1999
 * using MIDL 3.01.75
 ****************************************/
/* [uuid][object][local] */ 



EXTERN_C const IID IID_IPlayTLFunctionItem;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    interface DECLSPEC_UUID("8335e61e-ab3b-11ce-8468-0000b468276b")
    IPlayTLFunctionItem : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE Invoke( 
            /* [out] */ IPlayTLFunctionItem __RPC_FAR *__RPC_FAR *ppUndoItem,
            IValidSegmentList2 __RPC_FAR *pSegList) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetName( 
            /* [string][out] */ LPSTR pszName,
            DWORD dwMaxChars) = 0;
        
        virtual DWORD STDMETHODCALLTYPE GetSize( void) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IPlayTLFunctionItemVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            IPlayTLFunctionItem __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            IPlayTLFunctionItem __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            IPlayTLFunctionItem __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Invoke )( 
            IPlayTLFunctionItem __RPC_FAR * This,
            /* [out] */ IPlayTLFunctionItem __RPC_FAR *__RPC_FAR *ppUndoItem,
            IValidSegmentList2 __RPC_FAR *pSegList);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetName )( 
            IPlayTLFunctionItem __RPC_FAR * This,
            /* [string][out] */ LPSTR pszName,
            DWORD dwMaxChars);
        
        DWORD ( STDMETHODCALLTYPE __RPC_FAR *GetSize )( 
            IPlayTLFunctionItem __RPC_FAR * This);
        
        END_INTERFACE
    } IPlayTLFunctionItemVtbl;

    interface IPlayTLFunctionItem
    {
        CONST_VTBL struct IPlayTLFunctionItemVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IPlayTLFunctionItem_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IPlayTLFunctionItem_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IPlayTLFunctionItem_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IPlayTLFunctionItem_Invoke(This,ppUndoItem,pSegList)	\
    (This)->lpVtbl -> Invoke(This,ppUndoItem,pSegList)

#define IPlayTLFunctionItem_GetName(This,pszName,dwMaxChars)	\
    (This)->lpVtbl -> GetName(This,pszName,dwMaxChars)

#define IPlayTLFunctionItem_GetSize(This)	\
    (This)->lpVtbl -> GetSize(This)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE IPlayTLFunctionItem_Invoke_Proxy( 
    IPlayTLFunctionItem __RPC_FAR * This,
    /* [out] */ IPlayTLFunctionItem __RPC_FAR *__RPC_FAR *ppUndoItem,
    IValidSegmentList2 __RPC_FAR *pSegList);


void __RPC_STUB IPlayTLFunctionItem_Invoke_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IPlayTLFunctionItem_GetName_Proxy( 
    IPlayTLFunctionItem __RPC_FAR * This,
    /* [string][out] */ LPSTR pszName,
    DWORD dwMaxChars);


void __RPC_STUB IPlayTLFunctionItem_GetName_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


DWORD STDMETHODCALLTYPE IPlayTLFunctionItem_GetSize_Proxy( 
    IPlayTLFunctionItem __RPC_FAR * This);


void __RPC_STUB IPlayTLFunctionItem_GetSize_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IPlayTLFunctionItem_INTERFACE_DEFINED__ */


#ifndef __IPlayTLCommon_INTERFACE_DEFINED__
#define __IPlayTLCommon_INTERFACE_DEFINED__

/****************************************
 * Generated header for interface: IPlayTLCommon
 * at Tue Nov 23 05:02:07 1999
 * using MIDL 3.01.75
 ****************************************/
/* [local][uuid][object] */ 



EXTERN_C const IID IID_IPlayTLCommon;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    interface DECLSPEC_UUID("8335e61b-ab3b-11ce-8468-0000b468276b")
    IPlayTLCommon : public IUnknown
    {
    public:
        virtual DWORD STDMETHODCALLTYPE GetID( void) = 0;
        
        virtual HRESULT __stdcall GetAppData( 
            LPVOID __RPC_FAR *ppData,
            DWORD __RPC_FAR *pNumBytes) = 0;
        
        virtual HRESULT __stdcall SetAppData( 
            LPVOID pData,
            DWORD numBytes) = 0;
        
        virtual IUnknown __RPC_FAR *STDMETHODCALLTYPE GetAppObject( void) = 0;
        
        virtual HRESULT __stdcall SetAppObject( 
            IUnknown __RPC_FAR *pObject) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IPlayTLCommonVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            IPlayTLCommon __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            IPlayTLCommon __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            IPlayTLCommon __RPC_FAR * This);
        
        DWORD ( STDMETHODCALLTYPE __RPC_FAR *GetID )( 
            IPlayTLCommon __RPC_FAR * This);
        
        HRESULT ( __stdcall __RPC_FAR *GetAppData )( 
            IPlayTLCommon __RPC_FAR * This,
            LPVOID __RPC_FAR *ppData,
            DWORD __RPC_FAR *pNumBytes);
        
        HRESULT ( __stdcall __RPC_FAR *SetAppData )( 
            IPlayTLCommon __RPC_FAR * This,
            LPVOID pData,
            DWORD numBytes);
        
        IUnknown __RPC_FAR *( STDMETHODCALLTYPE __RPC_FAR *GetAppObject )( 
            IPlayTLCommon __RPC_FAR * This);
        
        HRESULT ( __stdcall __RPC_FAR *SetAppObject )( 
            IPlayTLCommon __RPC_FAR * This,
            IUnknown __RPC_FAR *pObject);
        
        END_INTERFACE
    } IPlayTLCommonVtbl;

    interface IPlayTLCommon
    {
        CONST_VTBL struct IPlayTLCommonVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IPlayTLCommon_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IPlayTLCommon_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IPlayTLCommon_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IPlayTLCommon_GetID(This)	\
    (This)->lpVtbl -> GetID(This)

#define IPlayTLCommon_GetAppData(This,ppData,pNumBytes)	\
    (This)->lpVtbl -> GetAppData(This,ppData,pNumBytes)

#define IPlayTLCommon_SetAppData(This,pData,numBytes)	\
    (This)->lpVtbl -> SetAppData(This,pData,numBytes)

#define IPlayTLCommon_GetAppObject(This)	\
    (This)->lpVtbl -> GetAppObject(This)

#define IPlayTLCommon_SetAppObject(This,pObject)	\
    (This)->lpVtbl -> SetAppObject(This,pObject)

#endif /* COBJMACROS */


#endif 	/* C style interface */



DWORD STDMETHODCALLTYPE IPlayTLCommon_GetID_Proxy( 
    IPlayTLCommon __RPC_FAR * This);


void __RPC_STUB IPlayTLCommon_GetID_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT __stdcall IPlayTLCommon_GetAppData_Proxy( 
    IPlayTLCommon __RPC_FAR * This,
    LPVOID __RPC_FAR *ppData,
    DWORD __RPC_FAR *pNumBytes);


void __RPC_STUB IPlayTLCommon_GetAppData_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT __stdcall IPlayTLCommon_SetAppData_Proxy( 
    IPlayTLCommon __RPC_FAR * This,
    LPVOID pData,
    DWORD numBytes);


void __RPC_STUB IPlayTLCommon_SetAppData_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


IUnknown __RPC_FAR *STDMETHODCALLTYPE IPlayTLCommon_GetAppObject_Proxy( 
    IPlayTLCommon __RPC_FAR * This);


void __RPC_STUB IPlayTLCommon_GetAppObject_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT __stdcall IPlayTLCommon_SetAppObject_Proxy( 
    IPlayTLCommon __RPC_FAR * This,
    IUnknown __RPC_FAR *pObject);


void __RPC_STUB IPlayTLCommon_SetAppObject_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IPlayTLCommon_INTERFACE_DEFINED__ */


#ifndef __IPlayTLGroup_INTERFACE_DEFINED__
#define __IPlayTLGroup_INTERFACE_DEFINED__

/****************************************
 * Generated header for interface: IPlayTLGroup
 * at Tue Nov 23 05:02:07 1999
 * using MIDL 3.01.75
 ****************************************/
/* [local][uuid][object] */ 



EXTERN_C const IID IID_IPlayTLGroup;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    interface DECLSPEC_UUID("8335e61c-ab3b-11ce-8468-0000b468276b")
    IPlayTLGroup : public IPlayTLCommon
    {
    public:
        virtual IPlayTLGroup __RPC_FAR *STDMETHODCALLTYPE GetNextGroup( void) = 0;
        
        virtual IPlayTLGroup __RPC_FAR *STDMETHODCALLTYPE GetPreviousGroup( void) = 0;
        
        virtual IPlayTLEvent __RPC_FAR *STDMETHODCALLTYPE GetRootMember( 
            DWORD dwIndex) = 0;
        
        virtual DWORD STDMETHODCALLTYPE GetNumberRootMembers( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE AddMember( 
            IPlayTLEvent __RPC_FAR *pEvent) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE RemoveMember( 
            IPlayTLEvent __RPC_FAR *pEvent) = 0;
        
        virtual BOOL STDMETHODCALLTYPE IntersectsInterval( 
            DWORD dwIn,
            DWORD dwOut) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE ConnectEvents( 
            IPlayTimeLine __RPC_FAR *timeline) = 0;
        
        virtual IGXIntBitmap __RPC_FAR *STDMETHODCALLTYPE GetPicon( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetPicon( 
            IGXIntBitmap __RPC_FAR *pPicon) = 0;
        
        virtual DWORD STDMETHODCALLTYPE GetUserDWORD( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetUserDWORD( 
            DWORD dwUser) = 0;
        
        virtual IPlayTimeLine __RPC_FAR *STDMETHODCALLTYPE GetTimeLine( void) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IPlayTLGroupVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            IPlayTLGroup __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            IPlayTLGroup __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            IPlayTLGroup __RPC_FAR * This);
        
        DWORD ( STDMETHODCALLTYPE __RPC_FAR *GetID )( 
            IPlayTLGroup __RPC_FAR * This);
        
        HRESULT ( __stdcall __RPC_FAR *GetAppData )( 
            IPlayTLGroup __RPC_FAR * This,
            LPVOID __RPC_FAR *ppData,
            DWORD __RPC_FAR *pNumBytes);
        
        HRESULT ( __stdcall __RPC_FAR *SetAppData )( 
            IPlayTLGroup __RPC_FAR * This,
            LPVOID pData,
            DWORD numBytes);
        
        IUnknown __RPC_FAR *( STDMETHODCALLTYPE __RPC_FAR *GetAppObject )( 
            IPlayTLGroup __RPC_FAR * This);
        
        HRESULT ( __stdcall __RPC_FAR *SetAppObject )( 
            IPlayTLGroup __RPC_FAR * This,
            IUnknown __RPC_FAR *pObject);
        
        IPlayTLGroup __RPC_FAR *( STDMETHODCALLTYPE __RPC_FAR *GetNextGroup )( 
            IPlayTLGroup __RPC_FAR * This);
        
        IPlayTLGroup __RPC_FAR *( STDMETHODCALLTYPE __RPC_FAR *GetPreviousGroup )( 
            IPlayTLGroup __RPC_FAR * This);
        
        IPlayTLEvent __RPC_FAR *( STDMETHODCALLTYPE __RPC_FAR *GetRootMember )( 
            IPlayTLGroup __RPC_FAR * This,
            DWORD dwIndex);
        
        DWORD ( STDMETHODCALLTYPE __RPC_FAR *GetNumberRootMembers )( 
            IPlayTLGroup __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *AddMember )( 
            IPlayTLGroup __RPC_FAR * This,
            IPlayTLEvent __RPC_FAR *pEvent);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *RemoveMember )( 
            IPlayTLGroup __RPC_FAR * This,
            IPlayTLEvent __RPC_FAR *pEvent);
        
        BOOL ( STDMETHODCALLTYPE __RPC_FAR *IntersectsInterval )( 
            IPlayTLGroup __RPC_FAR * This,
            DWORD dwIn,
            DWORD dwOut);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *ConnectEvents )( 
            IPlayTLGroup __RPC_FAR * This,
            IPlayTimeLine __RPC_FAR *timeline);
        
        IGXIntBitmap __RPC_FAR *( STDMETHODCALLTYPE __RPC_FAR *GetPicon )( 
            IPlayTLGroup __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetPicon )( 
            IPlayTLGroup __RPC_FAR * This,
            IGXIntBitmap __RPC_FAR *pPicon);
        
        DWORD ( STDMETHODCALLTYPE __RPC_FAR *GetUserDWORD )( 
            IPlayTLGroup __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetUserDWORD )( 
            IPlayTLGroup __RPC_FAR * This,
            DWORD dwUser);
        
        IPlayTimeLine __RPC_FAR *( STDMETHODCALLTYPE __RPC_FAR *GetTimeLine )( 
            IPlayTLGroup __RPC_FAR * This);
        
        END_INTERFACE
    } IPlayTLGroupVtbl;

    interface IPlayTLGroup
    {
        CONST_VTBL struct IPlayTLGroupVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IPlayTLGroup_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IPlayTLGroup_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IPlayTLGroup_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IPlayTLGroup_GetID(This)	\
    (This)->lpVtbl -> GetID(This)

#define IPlayTLGroup_GetAppData(This,ppData,pNumBytes)	\
    (This)->lpVtbl -> GetAppData(This,ppData,pNumBytes)

#define IPlayTLGroup_SetAppData(This,pData,numBytes)	\
    (This)->lpVtbl -> SetAppData(This,pData,numBytes)

#define IPlayTLGroup_GetAppObject(This)	\
    (This)->lpVtbl -> GetAppObject(This)

#define IPlayTLGroup_SetAppObject(This,pObject)	\
    (This)->lpVtbl -> SetAppObject(This,pObject)


#define IPlayTLGroup_GetNextGroup(This)	\
    (This)->lpVtbl -> GetNextGroup(This)

#define IPlayTLGroup_GetPreviousGroup(This)	\
    (This)->lpVtbl -> GetPreviousGroup(This)

#define IPlayTLGroup_GetRootMember(This,dwIndex)	\
    (This)->lpVtbl -> GetRootMember(This,dwIndex)

#define IPlayTLGroup_GetNumberRootMembers(This)	\
    (This)->lpVtbl -> GetNumberRootMembers(This)

#define IPlayTLGroup_AddMember(This,pEvent)	\
    (This)->lpVtbl -> AddMember(This,pEvent)

#define IPlayTLGroup_RemoveMember(This,pEvent)	\
    (This)->lpVtbl -> RemoveMember(This,pEvent)

#define IPlayTLGroup_IntersectsInterval(This,dwIn,dwOut)	\
    (This)->lpVtbl -> IntersectsInterval(This,dwIn,dwOut)

#define IPlayTLGroup_ConnectEvents(This,timeline)	\
    (This)->lpVtbl -> ConnectEvents(This,timeline)

#define IPlayTLGroup_GetPicon(This)	\
    (This)->lpVtbl -> GetPicon(This)

#define IPlayTLGroup_SetPicon(This,pPicon)	\
    (This)->lpVtbl -> SetPicon(This,pPicon)

#define IPlayTLGroup_GetUserDWORD(This)	\
    (This)->lpVtbl -> GetUserDWORD(This)

#define IPlayTLGroup_SetUserDWORD(This,dwUser)	\
    (This)->lpVtbl -> SetUserDWORD(This,dwUser)

#define IPlayTLGroup_GetTimeLine(This)	\
    (This)->lpVtbl -> GetTimeLine(This)

#endif /* COBJMACROS */


#endif 	/* C style interface */



IPlayTLGroup __RPC_FAR *STDMETHODCALLTYPE IPlayTLGroup_GetNextGroup_Proxy( 
    IPlayTLGroup __RPC_FAR * This);


void __RPC_STUB IPlayTLGroup_GetNextGroup_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


IPlayTLGroup __RPC_FAR *STDMETHODCALLTYPE IPlayTLGroup_GetPreviousGroup_Proxy( 
    IPlayTLGroup __RPC_FAR * This);


void __RPC_STUB IPlayTLGroup_GetPreviousGroup_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


IPlayTLEvent __RPC_FAR *STDMETHODCALLTYPE IPlayTLGroup_GetRootMember_Proxy( 
    IPlayTLGroup __RPC_FAR * This,
    DWORD dwIndex);


void __RPC_STUB IPlayTLGroup_GetRootMember_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


DWORD STDMETHODCALLTYPE IPlayTLGroup_GetNumberRootMembers_Proxy( 
    IPlayTLGroup __RPC_FAR * This);


void __RPC_STUB IPlayTLGroup_GetNumberRootMembers_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IPlayTLGroup_AddMember_Proxy( 
    IPlayTLGroup __RPC_FAR * This,
    IPlayTLEvent __RPC_FAR *pEvent);


void __RPC_STUB IPlayTLGroup_AddMember_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IPlayTLGroup_RemoveMember_Proxy( 
    IPlayTLGroup __RPC_FAR * This,
    IPlayTLEvent __RPC_FAR *pEvent);


void __RPC_STUB IPlayTLGroup_RemoveMember_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


BOOL STDMETHODCALLTYPE IPlayTLGroup_IntersectsInterval_Proxy( 
    IPlayTLGroup __RPC_FAR * This,
    DWORD dwIn,
    DWORD dwOut);


void __RPC_STUB IPlayTLGroup_IntersectsInterval_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IPlayTLGroup_ConnectEvents_Proxy( 
    IPlayTLGroup __RPC_FAR * This,
    IPlayTimeLine __RPC_FAR *timeline);


void __RPC_STUB IPlayTLGroup_ConnectEvents_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


IGXIntBitmap __RPC_FAR *STDMETHODCALLTYPE IPlayTLGroup_GetPicon_Proxy( 
    IPlayTLGroup __RPC_FAR * This);


void __RPC_STUB IPlayTLGroup_GetPicon_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IPlayTLGroup_SetPicon_Proxy( 
    IPlayTLGroup __RPC_FAR * This,
    IGXIntBitmap __RPC_FAR *pPicon);


void __RPC_STUB IPlayTLGroup_SetPicon_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


DWORD STDMETHODCALLTYPE IPlayTLGroup_GetUserDWORD_Proxy( 
    IPlayTLGroup __RPC_FAR * This);


void __RPC_STUB IPlayTLGroup_GetUserDWORD_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IPlayTLGroup_SetUserDWORD_Proxy( 
    IPlayTLGroup __RPC_FAR * This,
    DWORD dwUser);


void __RPC_STUB IPlayTLGroup_SetUserDWORD_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


IPlayTimeLine __RPC_FAR *STDMETHODCALLTYPE IPlayTLGroup_GetTimeLine_Proxy( 
    IPlayTLGroup __RPC_FAR * This);


void __RPC_STUB IPlayTLGroup_GetTimeLine_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IPlayTLGroup_INTERFACE_DEFINED__ */


#ifndef __IPlayTLGroupPrivate_INTERFACE_DEFINED__
#define __IPlayTLGroupPrivate_INTERFACE_DEFINED__

/****************************************
 * Generated header for interface: IPlayTLGroupPrivate
 * at Tue Nov 23 05:02:07 1999
 * using MIDL 3.01.75
 ****************************************/
/* [local][uuid][object] */ 



EXTERN_C const IID IID_IPlayTLGroupPrivate;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    interface DECLSPEC_UUID("8335e61d-ab3b-11ce-8468-0000b468276b")
    IPlayTLGroupPrivate : public IPlayTLGroup
    {
    public:
        virtual HRESULT __stdcall SetGroupID( 
            DWORD dwID) = 0;
        
        virtual HRESULT __stdcall SetNextGroup( 
            IPlayTLGroup __RPC_FAR *pNextGroup) = 0;
        
        virtual HRESULT __stdcall SetPreviousGroup( 
            IPlayTLGroup __RPC_FAR *pPrevGroup) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IPlayTLGroupPrivateVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            IPlayTLGroupPrivate __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            IPlayTLGroupPrivate __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            IPlayTLGroupPrivate __RPC_FAR * This);
        
        DWORD ( STDMETHODCALLTYPE __RPC_FAR *GetID )( 
            IPlayTLGroupPrivate __RPC_FAR * This);
        
        HRESULT ( __stdcall __RPC_FAR *GetAppData )( 
            IPlayTLGroupPrivate __RPC_FAR * This,
            LPVOID __RPC_FAR *ppData,
            DWORD __RPC_FAR *pNumBytes);
        
        HRESULT ( __stdcall __RPC_FAR *SetAppData )( 
            IPlayTLGroupPrivate __RPC_FAR * This,
            LPVOID pData,
            DWORD numBytes);
        
        IUnknown __RPC_FAR *( STDMETHODCALLTYPE __RPC_FAR *GetAppObject )( 
            IPlayTLGroupPrivate __RPC_FAR * This);
        
        HRESULT ( __stdcall __RPC_FAR *SetAppObject )( 
            IPlayTLGroupPrivate __RPC_FAR * This,
            IUnknown __RPC_FAR *pObject);
        
        IPlayTLGroup __RPC_FAR *( STDMETHODCALLTYPE __RPC_FAR *GetNextGroup )( 
            IPlayTLGroupPrivate __RPC_FAR * This);
        
        IPlayTLGroup __RPC_FAR *( STDMETHODCALLTYPE __RPC_FAR *GetPreviousGroup )( 
            IPlayTLGroupPrivate __RPC_FAR * This);
        
        IPlayTLEvent __RPC_FAR *( STDMETHODCALLTYPE __RPC_FAR *GetRootMember )( 
            IPlayTLGroupPrivate __RPC_FAR * This,
            DWORD dwIndex);
        
        DWORD ( STDMETHODCALLTYPE __RPC_FAR *GetNumberRootMembers )( 
            IPlayTLGroupPrivate __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *AddMember )( 
            IPlayTLGroupPrivate __RPC_FAR * This,
            IPlayTLEvent __RPC_FAR *pEvent);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *RemoveMember )( 
            IPlayTLGroupPrivate __RPC_FAR * This,
            IPlayTLEvent __RPC_FAR *pEvent);
        
        BOOL ( STDMETHODCALLTYPE __RPC_FAR *IntersectsInterval )( 
            IPlayTLGroupPrivate __RPC_FAR * This,
            DWORD dwIn,
            DWORD dwOut);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *ConnectEvents )( 
            IPlayTLGroupPrivate __RPC_FAR * This,
            IPlayTimeLine __RPC_FAR *timeline);
        
        IGXIntBitmap __RPC_FAR *( STDMETHODCALLTYPE __RPC_FAR *GetPicon )( 
            IPlayTLGroupPrivate __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetPicon )( 
            IPlayTLGroupPrivate __RPC_FAR * This,
            IGXIntBitmap __RPC_FAR *pPicon);
        
        DWORD ( STDMETHODCALLTYPE __RPC_FAR *GetUserDWORD )( 
            IPlayTLGroupPrivate __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetUserDWORD )( 
            IPlayTLGroupPrivate __RPC_FAR * This,
            DWORD dwUser);
        
        IPlayTimeLine __RPC_FAR *( STDMETHODCALLTYPE __RPC_FAR *GetTimeLine )( 
            IPlayTLGroupPrivate __RPC_FAR * This);
        
        HRESULT ( __stdcall __RPC_FAR *SetGroupID )( 
            IPlayTLGroupPrivate __RPC_FAR * This,
            DWORD dwID);
        
        HRESULT ( __stdcall __RPC_FAR *SetNextGroup )( 
            IPlayTLGroupPrivate __RPC_FAR * This,
            IPlayTLGroup __RPC_FAR *pNextGroup);
        
        HRESULT ( __stdcall __RPC_FAR *SetPreviousGroup )( 
            IPlayTLGroupPrivate __RPC_FAR * This,
            IPlayTLGroup __RPC_FAR *pPrevGroup);
        
        END_INTERFACE
    } IPlayTLGroupPrivateVtbl;

    interface IPlayTLGroupPrivate
    {
        CONST_VTBL struct IPlayTLGroupPrivateVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IPlayTLGroupPrivate_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IPlayTLGroupPrivate_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IPlayTLGroupPrivate_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IPlayTLGroupPrivate_GetID(This)	\
    (This)->lpVtbl -> GetID(This)

#define IPlayTLGroupPrivate_GetAppData(This,ppData,pNumBytes)	\
    (This)->lpVtbl -> GetAppData(This,ppData,pNumBytes)

#define IPlayTLGroupPrivate_SetAppData(This,pData,numBytes)	\
    (This)->lpVtbl -> SetAppData(This,pData,numBytes)

#define IPlayTLGroupPrivate_GetAppObject(This)	\
    (This)->lpVtbl -> GetAppObject(This)

#define IPlayTLGroupPrivate_SetAppObject(This,pObject)	\
    (This)->lpVtbl -> SetAppObject(This,pObject)


#define IPlayTLGroupPrivate_GetNextGroup(This)	\
    (This)->lpVtbl -> GetNextGroup(This)

#define IPlayTLGroupPrivate_GetPreviousGroup(This)	\
    (This)->lpVtbl -> GetPreviousGroup(This)

#define IPlayTLGroupPrivate_GetRootMember(This,dwIndex)	\
    (This)->lpVtbl -> GetRootMember(This,dwIndex)

#define IPlayTLGroupPrivate_GetNumberRootMembers(This)	\
    (This)->lpVtbl -> GetNumberRootMembers(This)

#define IPlayTLGroupPrivate_AddMember(This,pEvent)	\
    (This)->lpVtbl -> AddMember(This,pEvent)

#define IPlayTLGroupPrivate_RemoveMember(This,pEvent)	\
    (This)->lpVtbl -> RemoveMember(This,pEvent)

#define IPlayTLGroupPrivate_IntersectsInterval(This,dwIn,dwOut)	\
    (This)->lpVtbl -> IntersectsInterval(This,dwIn,dwOut)

#define IPlayTLGroupPrivate_ConnectEvents(This,timeline)	\
    (This)->lpVtbl -> ConnectEvents(This,timeline)

#define IPlayTLGroupPrivate_GetPicon(This)	\
    (This)->lpVtbl -> GetPicon(This)

#define IPlayTLGroupPrivate_SetPicon(This,pPicon)	\
    (This)->lpVtbl -> SetPicon(This,pPicon)

#define IPlayTLGroupPrivate_GetUserDWORD(This)	\
    (This)->lpVtbl -> GetUserDWORD(This)

#define IPlayTLGroupPrivate_SetUserDWORD(This,dwUser)	\
    (This)->lpVtbl -> SetUserDWORD(This,dwUser)

#define IPlayTLGroupPrivate_GetTimeLine(This)	\
    (This)->lpVtbl -> GetTimeLine(This)


#define IPlayTLGroupPrivate_SetGroupID(This,dwID)	\
    (This)->lpVtbl -> SetGroupID(This,dwID)

#define IPlayTLGroupPrivate_SetNextGroup(This,pNextGroup)	\
    (This)->lpVtbl -> SetNextGroup(This,pNextGroup)

#define IPlayTLGroupPrivate_SetPreviousGroup(This,pPrevGroup)	\
    (This)->lpVtbl -> SetPreviousGroup(This,pPrevGroup)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT __stdcall IPlayTLGroupPrivate_SetGroupID_Proxy( 
    IPlayTLGroupPrivate __RPC_FAR * This,
    DWORD dwID);


void __RPC_STUB IPlayTLGroupPrivate_SetGroupID_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT __stdcall IPlayTLGroupPrivate_SetNextGroup_Proxy( 
    IPlayTLGroupPrivate __RPC_FAR * This,
    IPlayTLGroup __RPC_FAR *pNextGroup);


void __RPC_STUB IPlayTLGroupPrivate_SetNextGroup_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT __stdcall IPlayTLGroupPrivate_SetPreviousGroup_Proxy( 
    IPlayTLGroupPrivate __RPC_FAR * This,
    IPlayTLGroup __RPC_FAR *pPrevGroup);


void __RPC_STUB IPlayTLGroupPrivate_SetPreviousGroup_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IPlayTLGroupPrivate_INTERFACE_DEFINED__ */


#ifndef __IPlayTimeLine_INTERFACE_DEFINED__
#define __IPlayTimeLine_INTERFACE_DEFINED__

/****************************************
 * Generated header for interface: IPlayTimeLine
 * at Tue Nov 23 05:02:07 1999
 * using MIDL 3.01.75
 ****************************************/
/* [local][uuid][object] */ 


typedef 
enum tagETimeCodeMode
    {	TCMNonDropFrame	= 0,
	TCMDropFrame	= 1,
	TCMPAL	= 2,
	TCMFilm	= 3
    }	ETimeCodeMode;


EXTERN_C const IID IID_IPlayTimeLine;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    interface DECLSPEC_UUID("8335e60f-ab3b-11ce-8468-0000b468276b")
    IPlayTimeLine : public IUnknown
    {
    public:
        virtual HRESULT __stdcall AddTrack( 
            IPlayTLTrack __RPC_FAR *pTrack,
            long nPos) = 0;
        
        virtual HRESULT __stdcall RemoveTrack( 
            IPlayTLTrack __RPC_FAR *__RPC_FAR *pTrack,
            DWORD dwID) = 0;
        
        virtual IPlayTLAdviser __RPC_FAR *STDMETHODCALLTYPE GetAdviser( void) = 0;
        
        virtual HRESULT __stdcall SetAdviser( 
            IPlayTLAdviser __RPC_FAR *pAdviser) = 0;
        
        virtual long __stdcall GetNumberTracks( void) = 0;
        
        virtual IPlayTLTrack __RPC_FAR *STDMETHODCALLTYPE GetTrack( void) = 0;
        
        virtual HRESULT __stdcall AddView( 
            IPlayTLView __RPC_FAR *ppView) = 0;
        
        virtual HRESULT __stdcall RemoveView( 
            IPlayTLView __RPC_FAR *__RPC_FAR *ppView,
            DWORD dwViewID) = 0;
        
        virtual long __stdcall GetNumberViews( void) = 0;
        
        virtual IPlayTLView __RPC_FAR *STDMETHODCALLTYPE GetView( void) = 0;
        
        virtual HRESULT __stdcall GetAppData( 
            LPVOID __RPC_FAR *ppData,
            DWORD __RPC_FAR *pNumBytes) = 0;
        
        virtual HRESULT __stdcall SetAppData( 
            LPVOID pData,
            DWORD numBytes) = 0;
        
        virtual IUnknown __RPC_FAR *STDMETHODCALLTYPE GetAppObject( void) = 0;
        
        virtual HRESULT __stdcall SetAppObject( 
            IUnknown __RPC_FAR *pObject) = 0;
        
        virtual HRESULT __stdcall SelectEvent( 
            IPlayTLEvent __RPC_FAR *pEvent,
            BOOL bMultiple) = 0;
        
        virtual HRESULT __stdcall UnselectEvent( 
            IPlayTLEvent __RPC_FAR *pEvent) = 0;
        
        virtual HRESULT __stdcall UnselectAll( void) = 0;
        
        virtual IPlayTLEvent __RPC_FAR *__stdcall GetSelectedEvent( 
            IPlayTLEvent __RPC_FAR *prevEvent) = 0;
        
        virtual HRESULT __stdcall UpdateTrack( 
            IPlayTLTrack __RPC_FAR *pTrack,
            DWORD startTime,
            DWORD endTime) = 0;
        
        virtual HRESULT __stdcall SetPositionBarTime( 
            DWORD dwTime) = 0;
        
        virtual DWORD __stdcall GetPositionBarTime( void) = 0;
        
        virtual DWORD __stdcall CreateGroup( 
            IPlayTLEvent __RPC_FAR *pEvent) = 0;
        
        virtual HRESULT __stdcall DeleteGroup( 
            DWORD dwId) = 0;
        
        virtual IPlayTLGroup __RPC_FAR *STDMETHODCALLTYPE GetGroup( 
            DWORD dwId) = 0;
        
        virtual IPlayTLGroup __RPC_FAR *STDMETHODCALLTYPE GetFirstGroup( void) = 0;
        
        virtual DWORD STDMETHODCALLTYPE GetNumberGroups( void) = 0;
        
        virtual IPlayTLCommon __RPC_FAR *STDMETHODCALLTYPE GetItem( 
            DWORD dwId) = 0;
        
        virtual DWORD STDMETHODCALLTYPE GenerateID( void) = 0;
        
        virtual BOOL STDMETHODCALLTYPE IsSelected( 
            IPlayTLEvent __RPC_FAR *pEvent) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetQuietMode( 
            BOOL bQuiet) = 0;
        
        virtual BOOL STDMETHODCALLTYPE GetQuietMode( void) = 0;
        
        virtual IPlayTLTrack __RPC_FAR *STDMETHODCALLTYPE GetLastTrack( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE AddTrack2( 
            IPlayTLTrack __RPC_FAR *pTrack,
            IPlayTLTrack __RPC_FAR *pOther,
            DWORD dwFlag) = 0;
        
        virtual IPlayTLEvent __RPC_FAR *STDMETHODCALLTYPE FindEventID( 
            DWORD dwID) = 0;
        
        virtual void STDMETHODCALLTYPE ConnectEvents( 
            IPlayTLTrack __RPC_FAR *pTrack) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Save( 
            IStorage __RPC_FAR *pStg) = 0;
        
        virtual IPlayTLTrack __RPC_FAR *STDMETHODCALLTYPE FindTrackUserDWORD( 
            DWORD dwUserDWORD) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetInitialZoom( 
            DWORD dwStartTime,
            DWORD dwEndTime) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE ChangeLabel( 
            IPlayTLTrack __RPC_FAR *pTrack) = 0;
        
        virtual void STDMETHODCALLTYPE RemoveTrackFromDB( 
            IPlayTLTrack __RPC_FAR *pTrack) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetRippleMode( 
            BOOL bOn) = 0;
        
        virtual BOOL STDMETHODCALLTYPE GetRippleMode( void) = 0;
        
        virtual void STDMETHODCALLTYPE TellViews( 
            IPlayTLTrack __RPC_FAR *pPrevious,
            IPlayTLTrack __RPC_FAR *pNewTrack) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetPicon( 
            IGXIntBitmap __RPC_FAR *pPicon) = 0;
        
        virtual IGXIntBitmap __RPC_FAR *STDMETHODCALLTYPE GetPicon( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetTimeLineOffset( 
            DWORD dwTime) = 0;
        
        virtual DWORD STDMETHODCALLTYPE GetTimeLineOffset( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetRollMode( 
            BOOL bOn) = 0;
        
        virtual BOOL STDMETHODCALLTYPE GetRollMode( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetFieldMode( 
            BOOL bOn) = 0;
        
        virtual BOOL STDMETHODCALLTYPE GetFieldMode( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE ForceUnselect( 
            IPlayTLEvent __RPC_FAR *pEvent) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetStartTime( 
            DWORD dwStartTime) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetEndTime( 
            DWORD dwEndTime) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetTimeCodeMode( 
            ETimeCodeMode eMode) = 0;
        
        virtual ETimeCodeMode STDMETHODCALLTYPE GetTimeCodeMode( void) = 0;
        
        virtual BOOL STDMETHODCALLTYPE IsMoving( 
            IPlayTLEvent __RPC_FAR *pEvent) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetValidSegmentMask( 
            DWORD dwMask) = 0;
        
        virtual DWORD STDMETHODCALLTYPE GetValidSegmentMask( void) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IPlayTimeLineVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            IPlayTimeLine __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            IPlayTimeLine __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            IPlayTimeLine __RPC_FAR * This);
        
        HRESULT ( __stdcall __RPC_FAR *AddTrack )( 
            IPlayTimeLine __RPC_FAR * This,
            IPlayTLTrack __RPC_FAR *pTrack,
            long nPos);
        
        HRESULT ( __stdcall __RPC_FAR *RemoveTrack )( 
            IPlayTimeLine __RPC_FAR * This,
            IPlayTLTrack __RPC_FAR *__RPC_FAR *pTrack,
            DWORD dwID);
        
        IPlayTLAdviser __RPC_FAR *( STDMETHODCALLTYPE __RPC_FAR *GetAdviser )( 
            IPlayTimeLine __RPC_FAR * This);
        
        HRESULT ( __stdcall __RPC_FAR *SetAdviser )( 
            IPlayTimeLine __RPC_FAR * This,
            IPlayTLAdviser __RPC_FAR *pAdviser);
        
        long ( __stdcall __RPC_FAR *GetNumberTracks )( 
            IPlayTimeLine __RPC_FAR * This);
        
        IPlayTLTrack __RPC_FAR *( STDMETHODCALLTYPE __RPC_FAR *GetTrack )( 
            IPlayTimeLine __RPC_FAR * This);
        
        HRESULT ( __stdcall __RPC_FAR *AddView )( 
            IPlayTimeLine __RPC_FAR * This,
            IPlayTLView __RPC_FAR *ppView);
        
        HRESULT ( __stdcall __RPC_FAR *RemoveView )( 
            IPlayTimeLine __RPC_FAR * This,
            IPlayTLView __RPC_FAR *__RPC_FAR *ppView,
            DWORD dwViewID);
        
        long ( __stdcall __RPC_FAR *GetNumberViews )( 
            IPlayTimeLine __RPC_FAR * This);
        
        IPlayTLView __RPC_FAR *( STDMETHODCALLTYPE __RPC_FAR *GetView )( 
            IPlayTimeLine __RPC_FAR * This);
        
        HRESULT ( __stdcall __RPC_FAR *GetAppData )( 
            IPlayTimeLine __RPC_FAR * This,
            LPVOID __RPC_FAR *ppData,
            DWORD __RPC_FAR *pNumBytes);
        
        HRESULT ( __stdcall __RPC_FAR *SetAppData )( 
            IPlayTimeLine __RPC_FAR * This,
            LPVOID pData,
            DWORD numBytes);
        
        IUnknown __RPC_FAR *( STDMETHODCALLTYPE __RPC_FAR *GetAppObject )( 
            IPlayTimeLine __RPC_FAR * This);
        
        HRESULT ( __stdcall __RPC_FAR *SetAppObject )( 
            IPlayTimeLine __RPC_FAR * This,
            IUnknown __RPC_FAR *pObject);
        
        HRESULT ( __stdcall __RPC_FAR *SelectEvent )( 
            IPlayTimeLine __RPC_FAR * This,
            IPlayTLEvent __RPC_FAR *pEvent,
            BOOL bMultiple);
        
        HRESULT ( __stdcall __RPC_FAR *UnselectEvent )( 
            IPlayTimeLine __RPC_FAR * This,
            IPlayTLEvent __RPC_FAR *pEvent);
        
        HRESULT ( __stdcall __RPC_FAR *UnselectAll )( 
            IPlayTimeLine __RPC_FAR * This);
        
        IPlayTLEvent __RPC_FAR *( __stdcall __RPC_FAR *GetSelectedEvent )( 
            IPlayTimeLine __RPC_FAR * This,
            IPlayTLEvent __RPC_FAR *prevEvent);
        
        HRESULT ( __stdcall __RPC_FAR *UpdateTrack )( 
            IPlayTimeLine __RPC_FAR * This,
            IPlayTLTrack __RPC_FAR *pTrack,
            DWORD startTime,
            DWORD endTime);
        
        HRESULT ( __stdcall __RPC_FAR *SetPositionBarTime )( 
            IPlayTimeLine __RPC_FAR * This,
            DWORD dwTime);
        
        DWORD ( __stdcall __RPC_FAR *GetPositionBarTime )( 
            IPlayTimeLine __RPC_FAR * This);
        
        DWORD ( __stdcall __RPC_FAR *CreateGroup )( 
            IPlayTimeLine __RPC_FAR * This,
            IPlayTLEvent __RPC_FAR *pEvent);
        
        HRESULT ( __stdcall __RPC_FAR *DeleteGroup )( 
            IPlayTimeLine __RPC_FAR * This,
            DWORD dwId);
        
        IPlayTLGroup __RPC_FAR *( STDMETHODCALLTYPE __RPC_FAR *GetGroup )( 
            IPlayTimeLine __RPC_FAR * This,
            DWORD dwId);
        
        IPlayTLGroup __RPC_FAR *( STDMETHODCALLTYPE __RPC_FAR *GetFirstGroup )( 
            IPlayTimeLine __RPC_FAR * This);
        
        DWORD ( STDMETHODCALLTYPE __RPC_FAR *GetNumberGroups )( 
            IPlayTimeLine __RPC_FAR * This);
        
        IPlayTLCommon __RPC_FAR *( STDMETHODCALLTYPE __RPC_FAR *GetItem )( 
            IPlayTimeLine __RPC_FAR * This,
            DWORD dwId);
        
        DWORD ( STDMETHODCALLTYPE __RPC_FAR *GenerateID )( 
            IPlayTimeLine __RPC_FAR * This);
        
        BOOL ( STDMETHODCALLTYPE __RPC_FAR *IsSelected )( 
            IPlayTimeLine __RPC_FAR * This,
            IPlayTLEvent __RPC_FAR *pEvent);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetQuietMode )( 
            IPlayTimeLine __RPC_FAR * This,
            BOOL bQuiet);
        
        BOOL ( STDMETHODCALLTYPE __RPC_FAR *GetQuietMode )( 
            IPlayTimeLine __RPC_FAR * This);
        
        IPlayTLTrack __RPC_FAR *( STDMETHODCALLTYPE __RPC_FAR *GetLastTrack )( 
            IPlayTimeLine __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *AddTrack2 )( 
            IPlayTimeLine __RPC_FAR * This,
            IPlayTLTrack __RPC_FAR *pTrack,
            IPlayTLTrack __RPC_FAR *pOther,
            DWORD dwFlag);
        
        IPlayTLEvent __RPC_FAR *( STDMETHODCALLTYPE __RPC_FAR *FindEventID )( 
            IPlayTimeLine __RPC_FAR * This,
            DWORD dwID);
        
        void ( STDMETHODCALLTYPE __RPC_FAR *ConnectEvents )( 
            IPlayTimeLine __RPC_FAR * This,
            IPlayTLTrack __RPC_FAR *pTrack);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Save )( 
            IPlayTimeLine __RPC_FAR * This,
            IStorage __RPC_FAR *pStg);
        
        IPlayTLTrack __RPC_FAR *( STDMETHODCALLTYPE __RPC_FAR *FindTrackUserDWORD )( 
            IPlayTimeLine __RPC_FAR * This,
            DWORD dwUserDWORD);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetInitialZoom )( 
            IPlayTimeLine __RPC_FAR * This,
            DWORD dwStartTime,
            DWORD dwEndTime);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *ChangeLabel )( 
            IPlayTimeLine __RPC_FAR * This,
            IPlayTLTrack __RPC_FAR *pTrack);
        
        void ( STDMETHODCALLTYPE __RPC_FAR *RemoveTrackFromDB )( 
            IPlayTimeLine __RPC_FAR * This,
            IPlayTLTrack __RPC_FAR *pTrack);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetRippleMode )( 
            IPlayTimeLine __RPC_FAR * This,
            BOOL bOn);
        
        BOOL ( STDMETHODCALLTYPE __RPC_FAR *GetRippleMode )( 
            IPlayTimeLine __RPC_FAR * This);
        
        void ( STDMETHODCALLTYPE __RPC_FAR *TellViews )( 
            IPlayTimeLine __RPC_FAR * This,
            IPlayTLTrack __RPC_FAR *pPrevious,
            IPlayTLTrack __RPC_FAR *pNewTrack);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetPicon )( 
            IPlayTimeLine __RPC_FAR * This,
            IGXIntBitmap __RPC_FAR *pPicon);
        
        IGXIntBitmap __RPC_FAR *( STDMETHODCALLTYPE __RPC_FAR *GetPicon )( 
            IPlayTimeLine __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetTimeLineOffset )( 
            IPlayTimeLine __RPC_FAR * This,
            DWORD dwTime);
        
        DWORD ( STDMETHODCALLTYPE __RPC_FAR *GetTimeLineOffset )( 
            IPlayTimeLine __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetRollMode )( 
            IPlayTimeLine __RPC_FAR * This,
            BOOL bOn);
        
        BOOL ( STDMETHODCALLTYPE __RPC_FAR *GetRollMode )( 
            IPlayTimeLine __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetFieldMode )( 
            IPlayTimeLine __RPC_FAR * This,
            BOOL bOn);
        
        BOOL ( STDMETHODCALLTYPE __RPC_FAR *GetFieldMode )( 
            IPlayTimeLine __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *ForceUnselect )( 
            IPlayTimeLine __RPC_FAR * This,
            IPlayTLEvent __RPC_FAR *pEvent);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetStartTime )( 
            IPlayTimeLine __RPC_FAR * This,
            DWORD dwStartTime);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetEndTime )( 
            IPlayTimeLine __RPC_FAR * This,
            DWORD dwEndTime);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetTimeCodeMode )( 
            IPlayTimeLine __RPC_FAR * This,
            ETimeCodeMode eMode);
        
        ETimeCodeMode ( STDMETHODCALLTYPE __RPC_FAR *GetTimeCodeMode )( 
            IPlayTimeLine __RPC_FAR * This);
        
        BOOL ( STDMETHODCALLTYPE __RPC_FAR *IsMoving )( 
            IPlayTimeLine __RPC_FAR * This,
            IPlayTLEvent __RPC_FAR *pEvent);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetValidSegmentMask )( 
            IPlayTimeLine __RPC_FAR * This,
            DWORD dwMask);
        
        DWORD ( STDMETHODCALLTYPE __RPC_FAR *GetValidSegmentMask )( 
            IPlayTimeLine __RPC_FAR * This);
        
        END_INTERFACE
    } IPlayTimeLineVtbl;

    interface IPlayTimeLine
    {
        CONST_VTBL struct IPlayTimeLineVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IPlayTimeLine_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IPlayTimeLine_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IPlayTimeLine_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IPlayTimeLine_AddTrack(This,pTrack,nPos)	\
    (This)->lpVtbl -> AddTrack(This,pTrack,nPos)

#define IPlayTimeLine_RemoveTrack(This,pTrack,dwID)	\
    (This)->lpVtbl -> RemoveTrack(This,pTrack,dwID)

#define IPlayTimeLine_GetAdviser(This)	\
    (This)->lpVtbl -> GetAdviser(This)

#define IPlayTimeLine_SetAdviser(This,pAdviser)	\
    (This)->lpVtbl -> SetAdviser(This,pAdviser)

#define IPlayTimeLine_GetNumberTracks(This)	\
    (This)->lpVtbl -> GetNumberTracks(This)

#define IPlayTimeLine_GetTrack(This)	\
    (This)->lpVtbl -> GetTrack(This)

#define IPlayTimeLine_AddView(This,ppView)	\
    (This)->lpVtbl -> AddView(This,ppView)

#define IPlayTimeLine_RemoveView(This,ppView,dwViewID)	\
    (This)->lpVtbl -> RemoveView(This,ppView,dwViewID)

#define IPlayTimeLine_GetNumberViews(This)	\
    (This)->lpVtbl -> GetNumberViews(This)

#define IPlayTimeLine_GetView(This)	\
    (This)->lpVtbl -> GetView(This)

#define IPlayTimeLine_GetAppData(This,ppData,pNumBytes)	\
    (This)->lpVtbl -> GetAppData(This,ppData,pNumBytes)

#define IPlayTimeLine_SetAppData(This,pData,numBytes)	\
    (This)->lpVtbl -> SetAppData(This,pData,numBytes)

#define IPlayTimeLine_GetAppObject(This)	\
    (This)->lpVtbl -> GetAppObject(This)

#define IPlayTimeLine_SetAppObject(This,pObject)	\
    (This)->lpVtbl -> SetAppObject(This,pObject)

#define IPlayTimeLine_SelectEvent(This,pEvent,bMultiple)	\
    (This)->lpVtbl -> SelectEvent(This,pEvent,bMultiple)

#define IPlayTimeLine_UnselectEvent(This,pEvent)	\
    (This)->lpVtbl -> UnselectEvent(This,pEvent)

#define IPlayTimeLine_UnselectAll(This)	\
    (This)->lpVtbl -> UnselectAll(This)

#define IPlayTimeLine_GetSelectedEvent(This,prevEvent)	\
    (This)->lpVtbl -> GetSelectedEvent(This,prevEvent)

#define IPlayTimeLine_UpdateTrack(This,pTrack,startTime,endTime)	\
    (This)->lpVtbl -> UpdateTrack(This,pTrack,startTime,endTime)

#define IPlayTimeLine_SetPositionBarTime(This,dwTime)	\
    (This)->lpVtbl -> SetPositionBarTime(This,dwTime)

#define IPlayTimeLine_GetPositionBarTime(This)	\
    (This)->lpVtbl -> GetPositionBarTime(This)

#define IPlayTimeLine_CreateGroup(This,pEvent)	\
    (This)->lpVtbl -> CreateGroup(This,pEvent)

#define IPlayTimeLine_DeleteGroup(This,dwId)	\
    (This)->lpVtbl -> DeleteGroup(This,dwId)

#define IPlayTimeLine_GetGroup(This,dwId)	\
    (This)->lpVtbl -> GetGroup(This,dwId)

#define IPlayTimeLine_GetFirstGroup(This)	\
    (This)->lpVtbl -> GetFirstGroup(This)

#define IPlayTimeLine_GetNumberGroups(This)	\
    (This)->lpVtbl -> GetNumberGroups(This)

#define IPlayTimeLine_GetItem(This,dwId)	\
    (This)->lpVtbl -> GetItem(This,dwId)

#define IPlayTimeLine_GenerateID(This)	\
    (This)->lpVtbl -> GenerateID(This)

#define IPlayTimeLine_IsSelected(This,pEvent)	\
    (This)->lpVtbl -> IsSelected(This,pEvent)

#define IPlayTimeLine_SetQuietMode(This,bQuiet)	\
    (This)->lpVtbl -> SetQuietMode(This,bQuiet)

#define IPlayTimeLine_GetQuietMode(This)	\
    (This)->lpVtbl -> GetQuietMode(This)

#define IPlayTimeLine_GetLastTrack(This)	\
    (This)->lpVtbl -> GetLastTrack(This)

#define IPlayTimeLine_AddTrack2(This,pTrack,pOther,dwFlag)	\
    (This)->lpVtbl -> AddTrack2(This,pTrack,pOther,dwFlag)

#define IPlayTimeLine_FindEventID(This,dwID)	\
    (This)->lpVtbl -> FindEventID(This,dwID)

#define IPlayTimeLine_ConnectEvents(This,pTrack)	\
    (This)->lpVtbl -> ConnectEvents(This,pTrack)

#define IPlayTimeLine_Save(This,pStg)	\
    (This)->lpVtbl -> Save(This,pStg)

#define IPlayTimeLine_FindTrackUserDWORD(This,dwUserDWORD)	\
    (This)->lpVtbl -> FindTrackUserDWORD(This,dwUserDWORD)

#define IPlayTimeLine_SetInitialZoom(This,dwStartTime,dwEndTime)	\
    (This)->lpVtbl -> SetInitialZoom(This,dwStartTime,dwEndTime)

#define IPlayTimeLine_ChangeLabel(This,pTrack)	\
    (This)->lpVtbl -> ChangeLabel(This,pTrack)

#define IPlayTimeLine_RemoveTrackFromDB(This,pTrack)	\
    (This)->lpVtbl -> RemoveTrackFromDB(This,pTrack)

#define IPlayTimeLine_SetRippleMode(This,bOn)	\
    (This)->lpVtbl -> SetRippleMode(This,bOn)

#define IPlayTimeLine_GetRippleMode(This)	\
    (This)->lpVtbl -> GetRippleMode(This)

#define IPlayTimeLine_TellViews(This,pPrevious,pNewTrack)	\
    (This)->lpVtbl -> TellViews(This,pPrevious,pNewTrack)

#define IPlayTimeLine_SetPicon(This,pPicon)	\
    (This)->lpVtbl -> SetPicon(This,pPicon)

#define IPlayTimeLine_GetPicon(This)	\
    (This)->lpVtbl -> GetPicon(This)

#define IPlayTimeLine_SetTimeLineOffset(This,dwTime)	\
    (This)->lpVtbl -> SetTimeLineOffset(This,dwTime)

#define IPlayTimeLine_GetTimeLineOffset(This)	\
    (This)->lpVtbl -> GetTimeLineOffset(This)

#define IPlayTimeLine_SetRollMode(This,bOn)	\
    (This)->lpVtbl -> SetRollMode(This,bOn)

#define IPlayTimeLine_GetRollMode(This)	\
    (This)->lpVtbl -> GetRollMode(This)

#define IPlayTimeLine_SetFieldMode(This,bOn)	\
    (This)->lpVtbl -> SetFieldMode(This,bOn)

#define IPlayTimeLine_GetFieldMode(This)	\
    (This)->lpVtbl -> GetFieldMode(This)

#define IPlayTimeLine_ForceUnselect(This,pEvent)	\
    (This)->lpVtbl -> ForceUnselect(This,pEvent)

#define IPlayTimeLine_SetStartTime(This,dwStartTime)	\
    (This)->lpVtbl -> SetStartTime(This,dwStartTime)

#define IPlayTimeLine_SetEndTime(This,dwEndTime)	\
    (This)->lpVtbl -> SetEndTime(This,dwEndTime)

#define IPlayTimeLine_SetTimeCodeMode(This,eMode)	\
    (This)->lpVtbl -> SetTimeCodeMode(This,eMode)

#define IPlayTimeLine_GetTimeCodeMode(This)	\
    (This)->lpVtbl -> GetTimeCodeMode(This)

#define IPlayTimeLine_IsMoving(This,pEvent)	\
    (This)->lpVtbl -> IsMoving(This,pEvent)

#define IPlayTimeLine_SetValidSegmentMask(This,dwMask)	\
    (This)->lpVtbl -> SetValidSegmentMask(This,dwMask)

#define IPlayTimeLine_GetValidSegmentMask(This)	\
    (This)->lpVtbl -> GetValidSegmentMask(This)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT __stdcall IPlayTimeLine_AddTrack_Proxy( 
    IPlayTimeLine __RPC_FAR * This,
    IPlayTLTrack __RPC_FAR *pTrack,
    long nPos);


void __RPC_STUB IPlayTimeLine_AddTrack_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT __stdcall IPlayTimeLine_RemoveTrack_Proxy( 
    IPlayTimeLine __RPC_FAR * This,
    IPlayTLTrack __RPC_FAR *__RPC_FAR *pTrack,
    DWORD dwID);


void __RPC_STUB IPlayTimeLine_RemoveTrack_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


IPlayTLAdviser __RPC_FAR *STDMETHODCALLTYPE IPlayTimeLine_GetAdviser_Proxy( 
    IPlayTimeLine __RPC_FAR * This);


void __RPC_STUB IPlayTimeLine_GetAdviser_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT __stdcall IPlayTimeLine_SetAdviser_Proxy( 
    IPlayTimeLine __RPC_FAR * This,
    IPlayTLAdviser __RPC_FAR *pAdviser);


void __RPC_STUB IPlayTimeLine_SetAdviser_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


long __stdcall IPlayTimeLine_GetNumberTracks_Proxy( 
    IPlayTimeLine __RPC_FAR * This);


void __RPC_STUB IPlayTimeLine_GetNumberTracks_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


IPlayTLTrack __RPC_FAR *STDMETHODCALLTYPE IPlayTimeLine_GetTrack_Proxy( 
    IPlayTimeLine __RPC_FAR * This);


void __RPC_STUB IPlayTimeLine_GetTrack_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT __stdcall IPlayTimeLine_AddView_Proxy( 
    IPlayTimeLine __RPC_FAR * This,
    IPlayTLView __RPC_FAR *ppView);


void __RPC_STUB IPlayTimeLine_AddView_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT __stdcall IPlayTimeLine_RemoveView_Proxy( 
    IPlayTimeLine __RPC_FAR * This,
    IPlayTLView __RPC_FAR *__RPC_FAR *ppView,
    DWORD dwViewID);


void __RPC_STUB IPlayTimeLine_RemoveView_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


long __stdcall IPlayTimeLine_GetNumberViews_Proxy( 
    IPlayTimeLine __RPC_FAR * This);


void __RPC_STUB IPlayTimeLine_GetNumberViews_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


IPlayTLView __RPC_FAR *STDMETHODCALLTYPE IPlayTimeLine_GetView_Proxy( 
    IPlayTimeLine __RPC_FAR * This);


void __RPC_STUB IPlayTimeLine_GetView_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT __stdcall IPlayTimeLine_GetAppData_Proxy( 
    IPlayTimeLine __RPC_FAR * This,
    LPVOID __RPC_FAR *ppData,
    DWORD __RPC_FAR *pNumBytes);


void __RPC_STUB IPlayTimeLine_GetAppData_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT __stdcall IPlayTimeLine_SetAppData_Proxy( 
    IPlayTimeLine __RPC_FAR * This,
    LPVOID pData,
    DWORD numBytes);


void __RPC_STUB IPlayTimeLine_SetAppData_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


IUnknown __RPC_FAR *STDMETHODCALLTYPE IPlayTimeLine_GetAppObject_Proxy( 
    IPlayTimeLine __RPC_FAR * This);


void __RPC_STUB IPlayTimeLine_GetAppObject_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT __stdcall IPlayTimeLine_SetAppObject_Proxy( 
    IPlayTimeLine __RPC_FAR * This,
    IUnknown __RPC_FAR *pObject);


void __RPC_STUB IPlayTimeLine_SetAppObject_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT __stdcall IPlayTimeLine_SelectEvent_Proxy( 
    IPlayTimeLine __RPC_FAR * This,
    IPlayTLEvent __RPC_FAR *pEvent,
    BOOL bMultiple);


void __RPC_STUB IPlayTimeLine_SelectEvent_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT __stdcall IPlayTimeLine_UnselectEvent_Proxy( 
    IPlayTimeLine __RPC_FAR * This,
    IPlayTLEvent __RPC_FAR *pEvent);


void __RPC_STUB IPlayTimeLine_UnselectEvent_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT __stdcall IPlayTimeLine_UnselectAll_Proxy( 
    IPlayTimeLine __RPC_FAR * This);


void __RPC_STUB IPlayTimeLine_UnselectAll_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


IPlayTLEvent __RPC_FAR *__stdcall IPlayTimeLine_GetSelectedEvent_Proxy( 
    IPlayTimeLine __RPC_FAR * This,
    IPlayTLEvent __RPC_FAR *prevEvent);


void __RPC_STUB IPlayTimeLine_GetSelectedEvent_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT __stdcall IPlayTimeLine_UpdateTrack_Proxy( 
    IPlayTimeLine __RPC_FAR * This,
    IPlayTLTrack __RPC_FAR *pTrack,
    DWORD startTime,
    DWORD endTime);


void __RPC_STUB IPlayTimeLine_UpdateTrack_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT __stdcall IPlayTimeLine_SetPositionBarTime_Proxy( 
    IPlayTimeLine __RPC_FAR * This,
    DWORD dwTime);


void __RPC_STUB IPlayTimeLine_SetPositionBarTime_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


DWORD __stdcall IPlayTimeLine_GetPositionBarTime_Proxy( 
    IPlayTimeLine __RPC_FAR * This);


void __RPC_STUB IPlayTimeLine_GetPositionBarTime_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


DWORD __stdcall IPlayTimeLine_CreateGroup_Proxy( 
    IPlayTimeLine __RPC_FAR * This,
    IPlayTLEvent __RPC_FAR *pEvent);


void __RPC_STUB IPlayTimeLine_CreateGroup_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT __stdcall IPlayTimeLine_DeleteGroup_Proxy( 
    IPlayTimeLine __RPC_FAR * This,
    DWORD dwId);


void __RPC_STUB IPlayTimeLine_DeleteGroup_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


IPlayTLGroup __RPC_FAR *STDMETHODCALLTYPE IPlayTimeLine_GetGroup_Proxy( 
    IPlayTimeLine __RPC_FAR * This,
    DWORD dwId);


void __RPC_STUB IPlayTimeLine_GetGroup_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


IPlayTLGroup __RPC_FAR *STDMETHODCALLTYPE IPlayTimeLine_GetFirstGroup_Proxy( 
    IPlayTimeLine __RPC_FAR * This);


void __RPC_STUB IPlayTimeLine_GetFirstGroup_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


DWORD STDMETHODCALLTYPE IPlayTimeLine_GetNumberGroups_Proxy( 
    IPlayTimeLine __RPC_FAR * This);


void __RPC_STUB IPlayTimeLine_GetNumberGroups_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


IPlayTLCommon __RPC_FAR *STDMETHODCALLTYPE IPlayTimeLine_GetItem_Proxy( 
    IPlayTimeLine __RPC_FAR * This,
    DWORD dwId);


void __RPC_STUB IPlayTimeLine_GetItem_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


DWORD STDMETHODCALLTYPE IPlayTimeLine_GenerateID_Proxy( 
    IPlayTimeLine __RPC_FAR * This);


void __RPC_STUB IPlayTimeLine_GenerateID_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


BOOL STDMETHODCALLTYPE IPlayTimeLine_IsSelected_Proxy( 
    IPlayTimeLine __RPC_FAR * This,
    IPlayTLEvent __RPC_FAR *pEvent);


void __RPC_STUB IPlayTimeLine_IsSelected_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IPlayTimeLine_SetQuietMode_Proxy( 
    IPlayTimeLine __RPC_FAR * This,
    BOOL bQuiet);


void __RPC_STUB IPlayTimeLine_SetQuietMode_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


BOOL STDMETHODCALLTYPE IPlayTimeLine_GetQuietMode_Proxy( 
    IPlayTimeLine __RPC_FAR * This);


void __RPC_STUB IPlayTimeLine_GetQuietMode_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


IPlayTLTrack __RPC_FAR *STDMETHODCALLTYPE IPlayTimeLine_GetLastTrack_Proxy( 
    IPlayTimeLine __RPC_FAR * This);


void __RPC_STUB IPlayTimeLine_GetLastTrack_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IPlayTimeLine_AddTrack2_Proxy( 
    IPlayTimeLine __RPC_FAR * This,
    IPlayTLTrack __RPC_FAR *pTrack,
    IPlayTLTrack __RPC_FAR *pOther,
    DWORD dwFlag);


void __RPC_STUB IPlayTimeLine_AddTrack2_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


IPlayTLEvent __RPC_FAR *STDMETHODCALLTYPE IPlayTimeLine_FindEventID_Proxy( 
    IPlayTimeLine __RPC_FAR * This,
    DWORD dwID);


void __RPC_STUB IPlayTimeLine_FindEventID_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


void STDMETHODCALLTYPE IPlayTimeLine_ConnectEvents_Proxy( 
    IPlayTimeLine __RPC_FAR * This,
    IPlayTLTrack __RPC_FAR *pTrack);


void __RPC_STUB IPlayTimeLine_ConnectEvents_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IPlayTimeLine_Save_Proxy( 
    IPlayTimeLine __RPC_FAR * This,
    IStorage __RPC_FAR *pStg);


void __RPC_STUB IPlayTimeLine_Save_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


IPlayTLTrack __RPC_FAR *STDMETHODCALLTYPE IPlayTimeLine_FindTrackUserDWORD_Proxy( 
    IPlayTimeLine __RPC_FAR * This,
    DWORD dwUserDWORD);


void __RPC_STUB IPlayTimeLine_FindTrackUserDWORD_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IPlayTimeLine_SetInitialZoom_Proxy( 
    IPlayTimeLine __RPC_FAR * This,
    DWORD dwStartTime,
    DWORD dwEndTime);


void __RPC_STUB IPlayTimeLine_SetInitialZoom_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IPlayTimeLine_ChangeLabel_Proxy( 
    IPlayTimeLine __RPC_FAR * This,
    IPlayTLTrack __RPC_FAR *pTrack);


void __RPC_STUB IPlayTimeLine_ChangeLabel_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


void STDMETHODCALLTYPE IPlayTimeLine_RemoveTrackFromDB_Proxy( 
    IPlayTimeLine __RPC_FAR * This,
    IPlayTLTrack __RPC_FAR *pTrack);


void __RPC_STUB IPlayTimeLine_RemoveTrackFromDB_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IPlayTimeLine_SetRippleMode_Proxy( 
    IPlayTimeLine __RPC_FAR * This,
    BOOL bOn);


void __RPC_STUB IPlayTimeLine_SetRippleMode_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


BOOL STDMETHODCALLTYPE IPlayTimeLine_GetRippleMode_Proxy( 
    IPlayTimeLine __RPC_FAR * This);


void __RPC_STUB IPlayTimeLine_GetRippleMode_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


void STDMETHODCALLTYPE IPlayTimeLine_TellViews_Proxy( 
    IPlayTimeLine __RPC_FAR * This,
    IPlayTLTrack __RPC_FAR *pPrevious,
    IPlayTLTrack __RPC_FAR *pNewTrack);


void __RPC_STUB IPlayTimeLine_TellViews_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IPlayTimeLine_SetPicon_Proxy( 
    IPlayTimeLine __RPC_FAR * This,
    IGXIntBitmap __RPC_FAR *pPicon);


void __RPC_STUB IPlayTimeLine_SetPicon_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


IGXIntBitmap __RPC_FAR *STDMETHODCALLTYPE IPlayTimeLine_GetPicon_Proxy( 
    IPlayTimeLine __RPC_FAR * This);


void __RPC_STUB IPlayTimeLine_GetPicon_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IPlayTimeLine_SetTimeLineOffset_Proxy( 
    IPlayTimeLine __RPC_FAR * This,
    DWORD dwTime);


void __RPC_STUB IPlayTimeLine_SetTimeLineOffset_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


DWORD STDMETHODCALLTYPE IPlayTimeLine_GetTimeLineOffset_Proxy( 
    IPlayTimeLine __RPC_FAR * This);


void __RPC_STUB IPlayTimeLine_GetTimeLineOffset_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IPlayTimeLine_SetRollMode_Proxy( 
    IPlayTimeLine __RPC_FAR * This,
    BOOL bOn);


void __RPC_STUB IPlayTimeLine_SetRollMode_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


BOOL STDMETHODCALLTYPE IPlayTimeLine_GetRollMode_Proxy( 
    IPlayTimeLine __RPC_FAR * This);


void __RPC_STUB IPlayTimeLine_GetRollMode_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IPlayTimeLine_SetFieldMode_Proxy( 
    IPlayTimeLine __RPC_FAR * This,
    BOOL bOn);


void __RPC_STUB IPlayTimeLine_SetFieldMode_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


BOOL STDMETHODCALLTYPE IPlayTimeLine_GetFieldMode_Proxy( 
    IPlayTimeLine __RPC_FAR * This);


void __RPC_STUB IPlayTimeLine_GetFieldMode_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IPlayTimeLine_ForceUnselect_Proxy( 
    IPlayTimeLine __RPC_FAR * This,
    IPlayTLEvent __RPC_FAR *pEvent);


void __RPC_STUB IPlayTimeLine_ForceUnselect_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IPlayTimeLine_SetStartTime_Proxy( 
    IPlayTimeLine __RPC_FAR * This,
    DWORD dwStartTime);


void __RPC_STUB IPlayTimeLine_SetStartTime_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IPlayTimeLine_SetEndTime_Proxy( 
    IPlayTimeLine __RPC_FAR * This,
    DWORD dwEndTime);


void __RPC_STUB IPlayTimeLine_SetEndTime_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IPlayTimeLine_SetTimeCodeMode_Proxy( 
    IPlayTimeLine __RPC_FAR * This,
    ETimeCodeMode eMode);


void __RPC_STUB IPlayTimeLine_SetTimeCodeMode_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


ETimeCodeMode STDMETHODCALLTYPE IPlayTimeLine_GetTimeCodeMode_Proxy( 
    IPlayTimeLine __RPC_FAR * This);


void __RPC_STUB IPlayTimeLine_GetTimeCodeMode_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


BOOL STDMETHODCALLTYPE IPlayTimeLine_IsMoving_Proxy( 
    IPlayTimeLine __RPC_FAR * This,
    IPlayTLEvent __RPC_FAR *pEvent);


void __RPC_STUB IPlayTimeLine_IsMoving_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IPlayTimeLine_SetValidSegmentMask_Proxy( 
    IPlayTimeLine __RPC_FAR * This,
    DWORD dwMask);


void __RPC_STUB IPlayTimeLine_SetValidSegmentMask_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


DWORD STDMETHODCALLTYPE IPlayTimeLine_GetValidSegmentMask_Proxy( 
    IPlayTimeLine __RPC_FAR * This);


void __RPC_STUB IPlayTimeLine_GetValidSegmentMask_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IPlayTimeLine_INTERFACE_DEFINED__ */


#ifndef __IPlayTLTrack_INTERFACE_DEFINED__
#define __IPlayTLTrack_INTERFACE_DEFINED__

/****************************************
 * Generated header for interface: IPlayTLTrack
 * at Tue Nov 23 05:02:07 1999
 * using MIDL 3.01.75
 ****************************************/
/* [local][uuid][object] */ 



EXTERN_C const IID IID_IPlayTLTrack;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    interface DECLSPEC_UUID("8335e610-ab3b-11ce-8468-0000b468276b")
    IPlayTLTrack : public IPlayTLCommon
    {
    public:
        virtual HRESULT __stdcall AddEvent( 
            IPlayTLEvent __RPC_FAR *pEvent) = 0;
        
        virtual HRESULT __stdcall RemoveEvent( 
            IPlayTLEvent __RPC_FAR *__RPC_FAR *ppEvent,
            DWORD dwTime) = 0;
        
        virtual HRESULT __stdcall MoveEvent( 
            IPlayTLEvent __RPC_FAR *pEvent,
            long timeDiff) = 0;
        
        virtual IPlayTLEvent __RPC_FAR *STDMETHODCALLTYPE GetEvent( 
            DWORD dwTime) = 0;
        
        virtual IPlayTLEvent __RPC_FAR *STDMETHODCALLTYPE GetClosestEvent( 
            DWORD dwTime) = 0;
        
        virtual IPlayTLEvent __RPC_FAR *STDMETHODCALLTYPE GetLastEvent( void) = 0;
        
        virtual DWORD __stdcall GetFreeTime( 
            DWORD dwTime,
            DWORD __RPC_FAR *startFree,
            DWORD __RPC_FAR *endFree) = 0;
        
        virtual HRESULT __stdcall AddChildTrack( 
            IPlayTLTrack __RPC_FAR *pChild,
            long nPos) = 0;
        
        virtual HRESULT __stdcall RemoveChildTrack( 
            IPlayTLTrack __RPC_FAR *__RPC_FAR *ppChild,
            DWORD dwID) = 0;
        
        virtual IPlayTLTrack __RPC_FAR *STDMETHODCALLTYPE GetChildTrack( void) = 0;
        
        virtual IPlayTLTrack __RPC_FAR *STDMETHODCALLTYPE GetParentTrack( void) = 0;
        
        virtual IPlayTLTrack __RPC_FAR *STDMETHODCALLTYPE GetNextTrack( void) = 0;
        
        virtual IPlayTLTrack __RPC_FAR *STDMETHODCALLTYPE GetPreviousTrack( void) = 0;
        
        virtual IPlayTimeLine __RPC_FAR *STDMETHODCALLTYPE GetTimeLine( void) = 0;
        
        virtual HRESULT __stdcall GetLabel( 
            LPSTR pszLabel,
            DWORD numBytes) = 0;
        
        virtual HRESULT __stdcall SetLabel( 
            LPSTR pszLabel) = 0;
        
        virtual DWORD __stdcall GetTrackType( void) = 0;
        
        virtual BOOL __stdcall EventsCollide( 
            IPlayTLEvent __RPC_FAR *pEvent) = 0;
        
        virtual HRESULT __stdcall SetUserDWORD( 
            DWORD dwUserDWORD) = 0;
        
        virtual DWORD __stdcall GetUserDWORD( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Delete( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetRippleMode( 
            BOOL bOn) = 0;
        
        virtual BOOL STDMETHODCALLTYPE GetRippleMode( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE ToggleRippleMode( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetEventInterpolateType( 
            IPlayTLEvent __RPC_FAR *pEvent,
            DWORD dwType) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetDefaultTrackHeight( 
            long lHeight) = 0;
        
        virtual long STDMETHODCALLTYPE GetDefaultTrackHeight( void) = 0;
        
        virtual IPlayTLTrack __RPC_FAR *__stdcall Clone( void) = 0;
        
        virtual IPlayTLTrack __RPC_FAR *__stdcall ClonePartial( 
            long lStartTime,
            long lEndTime) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IPlayTLTrackVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            IPlayTLTrack __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            IPlayTLTrack __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            IPlayTLTrack __RPC_FAR * This);
        
        DWORD ( STDMETHODCALLTYPE __RPC_FAR *GetID )( 
            IPlayTLTrack __RPC_FAR * This);
        
        HRESULT ( __stdcall __RPC_FAR *GetAppData )( 
            IPlayTLTrack __RPC_FAR * This,
            LPVOID __RPC_FAR *ppData,
            DWORD __RPC_FAR *pNumBytes);
        
        HRESULT ( __stdcall __RPC_FAR *SetAppData )( 
            IPlayTLTrack __RPC_FAR * This,
            LPVOID pData,
            DWORD numBytes);
        
        IUnknown __RPC_FAR *( STDMETHODCALLTYPE __RPC_FAR *GetAppObject )( 
            IPlayTLTrack __RPC_FAR * This);
        
        HRESULT ( __stdcall __RPC_FAR *SetAppObject )( 
            IPlayTLTrack __RPC_FAR * This,
            IUnknown __RPC_FAR *pObject);
        
        HRESULT ( __stdcall __RPC_FAR *AddEvent )( 
            IPlayTLTrack __RPC_FAR * This,
            IPlayTLEvent __RPC_FAR *pEvent);
        
        HRESULT ( __stdcall __RPC_FAR *RemoveEvent )( 
            IPlayTLTrack __RPC_FAR * This,
            IPlayTLEvent __RPC_FAR *__RPC_FAR *ppEvent,
            DWORD dwTime);
        
        HRESULT ( __stdcall __RPC_FAR *MoveEvent )( 
            IPlayTLTrack __RPC_FAR * This,
            IPlayTLEvent __RPC_FAR *pEvent,
            long timeDiff);
        
        IPlayTLEvent __RPC_FAR *( STDMETHODCALLTYPE __RPC_FAR *GetEvent )( 
            IPlayTLTrack __RPC_FAR * This,
            DWORD dwTime);
        
        IPlayTLEvent __RPC_FAR *( STDMETHODCALLTYPE __RPC_FAR *GetClosestEvent )( 
            IPlayTLTrack __RPC_FAR * This,
            DWORD dwTime);
        
        IPlayTLEvent __RPC_FAR *( STDMETHODCALLTYPE __RPC_FAR *GetLastEvent )( 
            IPlayTLTrack __RPC_FAR * This);
        
        DWORD ( __stdcall __RPC_FAR *GetFreeTime )( 
            IPlayTLTrack __RPC_FAR * This,
            DWORD dwTime,
            DWORD __RPC_FAR *startFree,
            DWORD __RPC_FAR *endFree);
        
        HRESULT ( __stdcall __RPC_FAR *AddChildTrack )( 
            IPlayTLTrack __RPC_FAR * This,
            IPlayTLTrack __RPC_FAR *pChild,
            long nPos);
        
        HRESULT ( __stdcall __RPC_FAR *RemoveChildTrack )( 
            IPlayTLTrack __RPC_FAR * This,
            IPlayTLTrack __RPC_FAR *__RPC_FAR *ppChild,
            DWORD dwID);
        
        IPlayTLTrack __RPC_FAR *( STDMETHODCALLTYPE __RPC_FAR *GetChildTrack )( 
            IPlayTLTrack __RPC_FAR * This);
        
        IPlayTLTrack __RPC_FAR *( STDMETHODCALLTYPE __RPC_FAR *GetParentTrack )( 
            IPlayTLTrack __RPC_FAR * This);
        
        IPlayTLTrack __RPC_FAR *( STDMETHODCALLTYPE __RPC_FAR *GetNextTrack )( 
            IPlayTLTrack __RPC_FAR * This);
        
        IPlayTLTrack __RPC_FAR *( STDMETHODCALLTYPE __RPC_FAR *GetPreviousTrack )( 
            IPlayTLTrack __RPC_FAR * This);
        
        IPlayTimeLine __RPC_FAR *( STDMETHODCALLTYPE __RPC_FAR *GetTimeLine )( 
            IPlayTLTrack __RPC_FAR * This);
        
        HRESULT ( __stdcall __RPC_FAR *GetLabel )( 
            IPlayTLTrack __RPC_FAR * This,
            LPSTR pszLabel,
            DWORD numBytes);
        
        HRESULT ( __stdcall __RPC_FAR *SetLabel )( 
            IPlayTLTrack __RPC_FAR * This,
            LPSTR pszLabel);
        
        DWORD ( __stdcall __RPC_FAR *GetTrackType )( 
            IPlayTLTrack __RPC_FAR * This);
        
        BOOL ( __stdcall __RPC_FAR *EventsCollide )( 
            IPlayTLTrack __RPC_FAR * This,
            IPlayTLEvent __RPC_FAR *pEvent);
        
        HRESULT ( __stdcall __RPC_FAR *SetUserDWORD )( 
            IPlayTLTrack __RPC_FAR * This,
            DWORD dwUserDWORD);
        
        DWORD ( __stdcall __RPC_FAR *GetUserDWORD )( 
            IPlayTLTrack __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Delete )( 
            IPlayTLTrack __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetRippleMode )( 
            IPlayTLTrack __RPC_FAR * This,
            BOOL bOn);
        
        BOOL ( STDMETHODCALLTYPE __RPC_FAR *GetRippleMode )( 
            IPlayTLTrack __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *ToggleRippleMode )( 
            IPlayTLTrack __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetEventInterpolateType )( 
            IPlayTLTrack __RPC_FAR * This,
            IPlayTLEvent __RPC_FAR *pEvent,
            DWORD dwType);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetDefaultTrackHeight )( 
            IPlayTLTrack __RPC_FAR * This,
            long lHeight);
        
        long ( STDMETHODCALLTYPE __RPC_FAR *GetDefaultTrackHeight )( 
            IPlayTLTrack __RPC_FAR * This);
        
        IPlayTLTrack __RPC_FAR *( __stdcall __RPC_FAR *Clone )( 
            IPlayTLTrack __RPC_FAR * This);
        
        IPlayTLTrack __RPC_FAR *( __stdcall __RPC_FAR *ClonePartial )( 
            IPlayTLTrack __RPC_FAR * This,
            long lStartTime,
            long lEndTime);
        
        END_INTERFACE
    } IPlayTLTrackVtbl;

    interface IPlayTLTrack
    {
        CONST_VTBL struct IPlayTLTrackVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IPlayTLTrack_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IPlayTLTrack_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IPlayTLTrack_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IPlayTLTrack_GetID(This)	\
    (This)->lpVtbl -> GetID(This)

#define IPlayTLTrack_GetAppData(This,ppData,pNumBytes)	\
    (This)->lpVtbl -> GetAppData(This,ppData,pNumBytes)

#define IPlayTLTrack_SetAppData(This,pData,numBytes)	\
    (This)->lpVtbl -> SetAppData(This,pData,numBytes)

#define IPlayTLTrack_GetAppObject(This)	\
    (This)->lpVtbl -> GetAppObject(This)

#define IPlayTLTrack_SetAppObject(This,pObject)	\
    (This)->lpVtbl -> SetAppObject(This,pObject)


#define IPlayTLTrack_AddEvent(This,pEvent)	\
    (This)->lpVtbl -> AddEvent(This,pEvent)

#define IPlayTLTrack_RemoveEvent(This,ppEvent,dwTime)	\
    (This)->lpVtbl -> RemoveEvent(This,ppEvent,dwTime)

#define IPlayTLTrack_MoveEvent(This,pEvent,timeDiff)	\
    (This)->lpVtbl -> MoveEvent(This,pEvent,timeDiff)

#define IPlayTLTrack_GetEvent(This,dwTime)	\
    (This)->lpVtbl -> GetEvent(This,dwTime)

#define IPlayTLTrack_GetClosestEvent(This,dwTime)	\
    (This)->lpVtbl -> GetClosestEvent(This,dwTime)

#define IPlayTLTrack_GetLastEvent(This)	\
    (This)->lpVtbl -> GetLastEvent(This)

#define IPlayTLTrack_GetFreeTime(This,dwTime,startFree,endFree)	\
    (This)->lpVtbl -> GetFreeTime(This,dwTime,startFree,endFree)

#define IPlayTLTrack_AddChildTrack(This,pChild,nPos)	\
    (This)->lpVtbl -> AddChildTrack(This,pChild,nPos)

#define IPlayTLTrack_RemoveChildTrack(This,ppChild,dwID)	\
    (This)->lpVtbl -> RemoveChildTrack(This,ppChild,dwID)

#define IPlayTLTrack_GetChildTrack(This)	\
    (This)->lpVtbl -> GetChildTrack(This)

#define IPlayTLTrack_GetParentTrack(This)	\
    (This)->lpVtbl -> GetParentTrack(This)

#define IPlayTLTrack_GetNextTrack(This)	\
    (This)->lpVtbl -> GetNextTrack(This)

#define IPlayTLTrack_GetPreviousTrack(This)	\
    (This)->lpVtbl -> GetPreviousTrack(This)

#define IPlayTLTrack_GetTimeLine(This)	\
    (This)->lpVtbl -> GetTimeLine(This)

#define IPlayTLTrack_GetLabel(This,pszLabel,numBytes)	\
    (This)->lpVtbl -> GetLabel(This,pszLabel,numBytes)

#define IPlayTLTrack_SetLabel(This,pszLabel)	\
    (This)->lpVtbl -> SetLabel(This,pszLabel)

#define IPlayTLTrack_GetTrackType(This)	\
    (This)->lpVtbl -> GetTrackType(This)

#define IPlayTLTrack_EventsCollide(This,pEvent)	\
    (This)->lpVtbl -> EventsCollide(This,pEvent)

#define IPlayTLTrack_SetUserDWORD(This,dwUserDWORD)	\
    (This)->lpVtbl -> SetUserDWORD(This,dwUserDWORD)

#define IPlayTLTrack_GetUserDWORD(This)	\
    (This)->lpVtbl -> GetUserDWORD(This)

#define IPlayTLTrack_Delete(This)	\
    (This)->lpVtbl -> Delete(This)

#define IPlayTLTrack_SetRippleMode(This,bOn)	\
    (This)->lpVtbl -> SetRippleMode(This,bOn)

#define IPlayTLTrack_GetRippleMode(This)	\
    (This)->lpVtbl -> GetRippleMode(This)

#define IPlayTLTrack_ToggleRippleMode(This)	\
    (This)->lpVtbl -> ToggleRippleMode(This)

#define IPlayTLTrack_SetEventInterpolateType(This,pEvent,dwType)	\
    (This)->lpVtbl -> SetEventInterpolateType(This,pEvent,dwType)

#define IPlayTLTrack_SetDefaultTrackHeight(This,lHeight)	\
    (This)->lpVtbl -> SetDefaultTrackHeight(This,lHeight)

#define IPlayTLTrack_GetDefaultTrackHeight(This)	\
    (This)->lpVtbl -> GetDefaultTrackHeight(This)

#define IPlayTLTrack_Clone(This)	\
    (This)->lpVtbl -> Clone(This)

#define IPlayTLTrack_ClonePartial(This,lStartTime,lEndTime)	\
    (This)->lpVtbl -> ClonePartial(This,lStartTime,lEndTime)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT __stdcall IPlayTLTrack_AddEvent_Proxy( 
    IPlayTLTrack __RPC_FAR * This,
    IPlayTLEvent __RPC_FAR *pEvent);


void __RPC_STUB IPlayTLTrack_AddEvent_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT __stdcall IPlayTLTrack_RemoveEvent_Proxy( 
    IPlayTLTrack __RPC_FAR * This,
    IPlayTLEvent __RPC_FAR *__RPC_FAR *ppEvent,
    DWORD dwTime);


void __RPC_STUB IPlayTLTrack_RemoveEvent_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT __stdcall IPlayTLTrack_MoveEvent_Proxy( 
    IPlayTLTrack __RPC_FAR * This,
    IPlayTLEvent __RPC_FAR *pEvent,
    long timeDiff);


void __RPC_STUB IPlayTLTrack_MoveEvent_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


IPlayTLEvent __RPC_FAR *STDMETHODCALLTYPE IPlayTLTrack_GetEvent_Proxy( 
    IPlayTLTrack __RPC_FAR * This,
    DWORD dwTime);


void __RPC_STUB IPlayTLTrack_GetEvent_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


IPlayTLEvent __RPC_FAR *STDMETHODCALLTYPE IPlayTLTrack_GetClosestEvent_Proxy( 
    IPlayTLTrack __RPC_FAR * This,
    DWORD dwTime);


void __RPC_STUB IPlayTLTrack_GetClosestEvent_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


IPlayTLEvent __RPC_FAR *STDMETHODCALLTYPE IPlayTLTrack_GetLastEvent_Proxy( 
    IPlayTLTrack __RPC_FAR * This);


void __RPC_STUB IPlayTLTrack_GetLastEvent_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


DWORD __stdcall IPlayTLTrack_GetFreeTime_Proxy( 
    IPlayTLTrack __RPC_FAR * This,
    DWORD dwTime,
    DWORD __RPC_FAR *startFree,
    DWORD __RPC_FAR *endFree);


void __RPC_STUB IPlayTLTrack_GetFreeTime_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT __stdcall IPlayTLTrack_AddChildTrack_Proxy( 
    IPlayTLTrack __RPC_FAR * This,
    IPlayTLTrack __RPC_FAR *pChild,
    long nPos);


void __RPC_STUB IPlayTLTrack_AddChildTrack_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT __stdcall IPlayTLTrack_RemoveChildTrack_Proxy( 
    IPlayTLTrack __RPC_FAR * This,
    IPlayTLTrack __RPC_FAR *__RPC_FAR *ppChild,
    DWORD dwID);


void __RPC_STUB IPlayTLTrack_RemoveChildTrack_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


IPlayTLTrack __RPC_FAR *STDMETHODCALLTYPE IPlayTLTrack_GetChildTrack_Proxy( 
    IPlayTLTrack __RPC_FAR * This);


void __RPC_STUB IPlayTLTrack_GetChildTrack_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


IPlayTLTrack __RPC_FAR *STDMETHODCALLTYPE IPlayTLTrack_GetParentTrack_Proxy( 
    IPlayTLTrack __RPC_FAR * This);


void __RPC_STUB IPlayTLTrack_GetParentTrack_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


IPlayTLTrack __RPC_FAR *STDMETHODCALLTYPE IPlayTLTrack_GetNextTrack_Proxy( 
    IPlayTLTrack __RPC_FAR * This);


void __RPC_STUB IPlayTLTrack_GetNextTrack_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


IPlayTLTrack __RPC_FAR *STDMETHODCALLTYPE IPlayTLTrack_GetPreviousTrack_Proxy( 
    IPlayTLTrack __RPC_FAR * This);


void __RPC_STUB IPlayTLTrack_GetPreviousTrack_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


IPlayTimeLine __RPC_FAR *STDMETHODCALLTYPE IPlayTLTrack_GetTimeLine_Proxy( 
    IPlayTLTrack __RPC_FAR * This);


void __RPC_STUB IPlayTLTrack_GetTimeLine_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT __stdcall IPlayTLTrack_GetLabel_Proxy( 
    IPlayTLTrack __RPC_FAR * This,
    LPSTR pszLabel,
    DWORD numBytes);


void __RPC_STUB IPlayTLTrack_GetLabel_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT __stdcall IPlayTLTrack_SetLabel_Proxy( 
    IPlayTLTrack __RPC_FAR * This,
    LPSTR pszLabel);


void __RPC_STUB IPlayTLTrack_SetLabel_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


DWORD __stdcall IPlayTLTrack_GetTrackType_Proxy( 
    IPlayTLTrack __RPC_FAR * This);


void __RPC_STUB IPlayTLTrack_GetTrackType_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


BOOL __stdcall IPlayTLTrack_EventsCollide_Proxy( 
    IPlayTLTrack __RPC_FAR * This,
    IPlayTLEvent __RPC_FAR *pEvent);


void __RPC_STUB IPlayTLTrack_EventsCollide_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT __stdcall IPlayTLTrack_SetUserDWORD_Proxy( 
    IPlayTLTrack __RPC_FAR * This,
    DWORD dwUserDWORD);


void __RPC_STUB IPlayTLTrack_SetUserDWORD_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


DWORD __stdcall IPlayTLTrack_GetUserDWORD_Proxy( 
    IPlayTLTrack __RPC_FAR * This);


void __RPC_STUB IPlayTLTrack_GetUserDWORD_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IPlayTLTrack_Delete_Proxy( 
    IPlayTLTrack __RPC_FAR * This);


void __RPC_STUB IPlayTLTrack_Delete_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IPlayTLTrack_SetRippleMode_Proxy( 
    IPlayTLTrack __RPC_FAR * This,
    BOOL bOn);


void __RPC_STUB IPlayTLTrack_SetRippleMode_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


BOOL STDMETHODCALLTYPE IPlayTLTrack_GetRippleMode_Proxy( 
    IPlayTLTrack __RPC_FAR * This);


void __RPC_STUB IPlayTLTrack_GetRippleMode_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IPlayTLTrack_ToggleRippleMode_Proxy( 
    IPlayTLTrack __RPC_FAR * This);


void __RPC_STUB IPlayTLTrack_ToggleRippleMode_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IPlayTLTrack_SetEventInterpolateType_Proxy( 
    IPlayTLTrack __RPC_FAR * This,
    IPlayTLEvent __RPC_FAR *pEvent,
    DWORD dwType);


void __RPC_STUB IPlayTLTrack_SetEventInterpolateType_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IPlayTLTrack_SetDefaultTrackHeight_Proxy( 
    IPlayTLTrack __RPC_FAR * This,
    long lHeight);


void __RPC_STUB IPlayTLTrack_SetDefaultTrackHeight_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


long STDMETHODCALLTYPE IPlayTLTrack_GetDefaultTrackHeight_Proxy( 
    IPlayTLTrack __RPC_FAR * This);


void __RPC_STUB IPlayTLTrack_GetDefaultTrackHeight_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


IPlayTLTrack __RPC_FAR *__stdcall IPlayTLTrack_Clone_Proxy( 
    IPlayTLTrack __RPC_FAR * This);


void __RPC_STUB IPlayTLTrack_Clone_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


IPlayTLTrack __RPC_FAR *__stdcall IPlayTLTrack_ClonePartial_Proxy( 
    IPlayTLTrack __RPC_FAR * This,
    long lStartTime,
    long lEndTime);


void __RPC_STUB IPlayTLTrack_ClonePartial_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IPlayTLTrack_INTERFACE_DEFINED__ */


#ifndef __IPlayTLValueTrack_INTERFACE_DEFINED__
#define __IPlayTLValueTrack_INTERFACE_DEFINED__

/****************************************
 * Generated header for interface: IPlayTLValueTrack
 * at Tue Nov 23 05:02:07 1999
 * using MIDL 3.01.75
 ****************************************/
/* [local][uuid][object] */ 



EXTERN_C const IID IID_IPlayTLValueTrack;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    interface DECLSPEC_UUID("8335e611-ab3b-11ce-8468-0000b468276b")
    IPlayTLValueTrack : public IUnknown
    {
    public:
        virtual double __stdcall GetMaxValue( void) = 0;
        
        virtual double __stdcall GetMinValue( void) = 0;
        
        virtual HRESULT __stdcall SetMaxValue( 
            double dMax) = 0;
        
        virtual HRESULT __stdcall SetMinValue( 
            double dMax) = 0;
        
        virtual HRESULT __stdcall GetValue( 
            DWORD dwTime,
            double __RPC_FAR *value) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE ChangeValueAtTime( 
            DWORD dwTime,
            double newValue) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE MoveEventInSpline( 
            DWORD dwOldTime,
            DWORD dwNewTime,
            double value) = 0;
        
        virtual HRESULT __stdcall CalcCurrentMinMax( void) = 0;
        
        virtual double __stdcall GetCurrentMaxValue( void) = 0;
        
        virtual double __stdcall GetCurrentMinValue( void) = 0;
        
        virtual HRESULT __stdcall QuietChangeValueAtTime( 
            DWORD dwTime,
            double newValue,
            BOOL RecalcScale) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IPlayTLValueTrackVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            IPlayTLValueTrack __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            IPlayTLValueTrack __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            IPlayTLValueTrack __RPC_FAR * This);
        
        double ( __stdcall __RPC_FAR *GetMaxValue )( 
            IPlayTLValueTrack __RPC_FAR * This);
        
        double ( __stdcall __RPC_FAR *GetMinValue )( 
            IPlayTLValueTrack __RPC_FAR * This);
        
        HRESULT ( __stdcall __RPC_FAR *SetMaxValue )( 
            IPlayTLValueTrack __RPC_FAR * This,
            double dMax);
        
        HRESULT ( __stdcall __RPC_FAR *SetMinValue )( 
            IPlayTLValueTrack __RPC_FAR * This,
            double dMax);
        
        HRESULT ( __stdcall __RPC_FAR *GetValue )( 
            IPlayTLValueTrack __RPC_FAR * This,
            DWORD dwTime,
            double __RPC_FAR *value);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *ChangeValueAtTime )( 
            IPlayTLValueTrack __RPC_FAR * This,
            DWORD dwTime,
            double newValue);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *MoveEventInSpline )( 
            IPlayTLValueTrack __RPC_FAR * This,
            DWORD dwOldTime,
            DWORD dwNewTime,
            double value);
        
        HRESULT ( __stdcall __RPC_FAR *CalcCurrentMinMax )( 
            IPlayTLValueTrack __RPC_FAR * This);
        
        double ( __stdcall __RPC_FAR *GetCurrentMaxValue )( 
            IPlayTLValueTrack __RPC_FAR * This);
        
        double ( __stdcall __RPC_FAR *GetCurrentMinValue )( 
            IPlayTLValueTrack __RPC_FAR * This);
        
        HRESULT ( __stdcall __RPC_FAR *QuietChangeValueAtTime )( 
            IPlayTLValueTrack __RPC_FAR * This,
            DWORD dwTime,
            double newValue,
            BOOL RecalcScale);
        
        END_INTERFACE
    } IPlayTLValueTrackVtbl;

    interface IPlayTLValueTrack
    {
        CONST_VTBL struct IPlayTLValueTrackVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IPlayTLValueTrack_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IPlayTLValueTrack_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IPlayTLValueTrack_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IPlayTLValueTrack_GetMaxValue(This)	\
    (This)->lpVtbl -> GetMaxValue(This)

#define IPlayTLValueTrack_GetMinValue(This)	\
    (This)->lpVtbl -> GetMinValue(This)

#define IPlayTLValueTrack_SetMaxValue(This,dMax)	\
    (This)->lpVtbl -> SetMaxValue(This,dMax)

#define IPlayTLValueTrack_SetMinValue(This,dMax)	\
    (This)->lpVtbl -> SetMinValue(This,dMax)

#define IPlayTLValueTrack_GetValue(This,dwTime,value)	\
    (This)->lpVtbl -> GetValue(This,dwTime,value)

#define IPlayTLValueTrack_ChangeValueAtTime(This,dwTime,newValue)	\
    (This)->lpVtbl -> ChangeValueAtTime(This,dwTime,newValue)

#define IPlayTLValueTrack_MoveEventInSpline(This,dwOldTime,dwNewTime,value)	\
    (This)->lpVtbl -> MoveEventInSpline(This,dwOldTime,dwNewTime,value)

#define IPlayTLValueTrack_CalcCurrentMinMax(This)	\
    (This)->lpVtbl -> CalcCurrentMinMax(This)

#define IPlayTLValueTrack_GetCurrentMaxValue(This)	\
    (This)->lpVtbl -> GetCurrentMaxValue(This)

#define IPlayTLValueTrack_GetCurrentMinValue(This)	\
    (This)->lpVtbl -> GetCurrentMinValue(This)

#define IPlayTLValueTrack_QuietChangeValueAtTime(This,dwTime,newValue,RecalcScale)	\
    (This)->lpVtbl -> QuietChangeValueAtTime(This,dwTime,newValue,RecalcScale)

#endif /* COBJMACROS */


#endif 	/* C style interface */



double __stdcall IPlayTLValueTrack_GetMaxValue_Proxy( 
    IPlayTLValueTrack __RPC_FAR * This);


void __RPC_STUB IPlayTLValueTrack_GetMaxValue_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


double __stdcall IPlayTLValueTrack_GetMinValue_Proxy( 
    IPlayTLValueTrack __RPC_FAR * This);


void __RPC_STUB IPlayTLValueTrack_GetMinValue_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT __stdcall IPlayTLValueTrack_SetMaxValue_Proxy( 
    IPlayTLValueTrack __RPC_FAR * This,
    double dMax);


void __RPC_STUB IPlayTLValueTrack_SetMaxValue_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT __stdcall IPlayTLValueTrack_SetMinValue_Proxy( 
    IPlayTLValueTrack __RPC_FAR * This,
    double dMax);


void __RPC_STUB IPlayTLValueTrack_SetMinValue_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT __stdcall IPlayTLValueTrack_GetValue_Proxy( 
    IPlayTLValueTrack __RPC_FAR * This,
    DWORD dwTime,
    double __RPC_FAR *value);


void __RPC_STUB IPlayTLValueTrack_GetValue_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IPlayTLValueTrack_ChangeValueAtTime_Proxy( 
    IPlayTLValueTrack __RPC_FAR * This,
    DWORD dwTime,
    double newValue);


void __RPC_STUB IPlayTLValueTrack_ChangeValueAtTime_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IPlayTLValueTrack_MoveEventInSpline_Proxy( 
    IPlayTLValueTrack __RPC_FAR * This,
    DWORD dwOldTime,
    DWORD dwNewTime,
    double value);


void __RPC_STUB IPlayTLValueTrack_MoveEventInSpline_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT __stdcall IPlayTLValueTrack_CalcCurrentMinMax_Proxy( 
    IPlayTLValueTrack __RPC_FAR * This);


void __RPC_STUB IPlayTLValueTrack_CalcCurrentMinMax_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


double __stdcall IPlayTLValueTrack_GetCurrentMaxValue_Proxy( 
    IPlayTLValueTrack __RPC_FAR * This);


void __RPC_STUB IPlayTLValueTrack_GetCurrentMaxValue_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


double __stdcall IPlayTLValueTrack_GetCurrentMinValue_Proxy( 
    IPlayTLValueTrack __RPC_FAR * This);


void __RPC_STUB IPlayTLValueTrack_GetCurrentMinValue_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT __stdcall IPlayTLValueTrack_QuietChangeValueAtTime_Proxy( 
    IPlayTLValueTrack __RPC_FAR * This,
    DWORD dwTime,
    double newValue,
    BOOL RecalcScale);


void __RPC_STUB IPlayTLValueTrack_QuietChangeValueAtTime_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IPlayTLValueTrack_INTERFACE_DEFINED__ */


#ifndef __IPlayTLEvent_INTERFACE_DEFINED__
#define __IPlayTLEvent_INTERFACE_DEFINED__

/****************************************
 * Generated header for interface: IPlayTLEvent
 * at Tue Nov 23 05:02:07 1999
 * using MIDL 3.01.75
 ****************************************/
/* [local][uuid][object] */ 



EXTERN_C const IID IID_IPlayTLEvent;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    interface DECLSPEC_UUID("8335e612-ab3b-11ce-8468-0000b468276b")
    IPlayTLEvent : public IPlayTLCommon
    {
    public:
        virtual DWORD __stdcall GetStartTime( void) = 0;
        
        virtual HRESULT __stdcall SetStartTime( 
            DWORD dwTime) = 0;
        
        virtual DWORD __stdcall GetEndTime( void) = 0;
        
        virtual HRESULT __stdcall SetEndTime( 
            DWORD dwTime) = 0;
        
        virtual DWORD __stdcall GetLength( void) = 0;
        
        virtual HRESULT __stdcall SetLength( 
            DWORD dwTime) = 0;
        
        virtual DWORD __stdcall GetEventType( void) = 0;
        
        virtual HRESULT __stdcall SetColor( 
            DWORD dwColor) = 0;
        
        virtual DWORD __stdcall GetColor( void) = 0;
        
        virtual IPlayTLTrack __RPC_FAR *STDMETHODCALLTYPE GetTrack( void) = 0;
        
        virtual IPlayTLEvent __RPC_FAR *STDMETHODCALLTYPE GetNextEvent( void) = 0;
        
        virtual IPlayTLEvent __RPC_FAR *STDMETHODCALLTYPE GetPreviousEvent( void) = 0;
        
        virtual HRESULT __stdcall SetUserDWORD( 
            DWORD dwUserDWORD) = 0;
        
        virtual DWORD __stdcall GetUserDWORD( void) = 0;
        
        virtual IPlayTLEvent __RPC_FAR *STDMETHODCALLTYPE GetParentEvent( void) = 0;
        
        virtual IPlayTLEvent __RPC_FAR *STDMETHODCALLTYPE GetChildEvent( 
            long lIndex) = 0;
        
        virtual IPlayTLEvent __RPC_FAR *STDMETHODCALLTYPE GetFirstEventNextLevel( void) = 0;
        
        virtual IPlayTLEvent __RPC_FAR *STDMETHODCALLTYPE GetFirstEventPreviousLevel( void) = 0;
        
        virtual IPlayTLEvent __RPC_FAR *STDMETHODCALLTYPE GetNextEventSameLevel( void) = 0;
        
        virtual IPlayTLEvent __RPC_FAR *STDMETHODCALLTYPE GetPreviousEventSameLevel( void) = 0;
        
        virtual long STDMETHODCALLTYPE GetChildLevel( void) = 0;
        
        virtual HRESULT __stdcall SetChildEvent( 
            IPlayTLEvent __RPC_FAR *pChildEvent,
            long lIndex,
            DWORD dwFlag) = 0;
        
        virtual DWORD STDMETHODCALLTYPE GetGroupID( void) = 0;
        
        virtual IPlayTLEvent __RPC_FAR *STDMETHODCALLTYPE GetPreviousGroupMember( void) = 0;
        
        virtual IPlayTLEvent __RPC_FAR *STDMETHODCALLTYPE GetNextGroupMember( void) = 0;
        
        virtual DWORD STDMETHODCALLTYPE GetSourceIn( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetSourceIn( 
            DWORD dwTime) = 0;
        
        virtual IPlayTLEvent __RPC_FAR *STDMETHODCALLTYPE GetFirstChildEvent( void) = 0;
        
        virtual void STDMETHODCALLTYPE DieChildrenDie( 
            BOOL bDoYouMeanIt) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetGroup( 
            DWORD dwGroupID) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetPicon( 
            IGXIntBitmap __RPC_FAR *picture) = 0;
        
        virtual IGXIntBitmap __RPC_FAR *STDMETHODCALLTYPE GetPicon( void) = 0;
        
        virtual BOOL STDMETHODCALLTYPE GetClipRoll( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetClipRoll( 
            BOOL bOn) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE EnableStartHandle( 
            BOOL bOn) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE EnableEndHandle( 
            BOOL bOn) = 0;
        
        virtual BOOL STDMETHODCALLTYPE IsStartHandleEnabled( void) = 0;
        
        virtual BOOL STDMETHODCALLTYPE IsEndHandleEnabled( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetLabel( 
            LPSTR pszLabel) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetLabel( 
            LPSTR pszLabel,
            DWORD cbBuffer) = 0;
        
        virtual IPlayTLEvent __RPC_FAR *__stdcall Clone( void) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IPlayTLEventVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            IPlayTLEvent __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            IPlayTLEvent __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            IPlayTLEvent __RPC_FAR * This);
        
        DWORD ( STDMETHODCALLTYPE __RPC_FAR *GetID )( 
            IPlayTLEvent __RPC_FAR * This);
        
        HRESULT ( __stdcall __RPC_FAR *GetAppData )( 
            IPlayTLEvent __RPC_FAR * This,
            LPVOID __RPC_FAR *ppData,
            DWORD __RPC_FAR *pNumBytes);
        
        HRESULT ( __stdcall __RPC_FAR *SetAppData )( 
            IPlayTLEvent __RPC_FAR * This,
            LPVOID pData,
            DWORD numBytes);
        
        IUnknown __RPC_FAR *( STDMETHODCALLTYPE __RPC_FAR *GetAppObject )( 
            IPlayTLEvent __RPC_FAR * This);
        
        HRESULT ( __stdcall __RPC_FAR *SetAppObject )( 
            IPlayTLEvent __RPC_FAR * This,
            IUnknown __RPC_FAR *pObject);
        
        DWORD ( __stdcall __RPC_FAR *GetStartTime )( 
            IPlayTLEvent __RPC_FAR * This);
        
        HRESULT ( __stdcall __RPC_FAR *SetStartTime )( 
            IPlayTLEvent __RPC_FAR * This,
            DWORD dwTime);
        
        DWORD ( __stdcall __RPC_FAR *GetEndTime )( 
            IPlayTLEvent __RPC_FAR * This);
        
        HRESULT ( __stdcall __RPC_FAR *SetEndTime )( 
            IPlayTLEvent __RPC_FAR * This,
            DWORD dwTime);
        
        DWORD ( __stdcall __RPC_FAR *GetLength )( 
            IPlayTLEvent __RPC_FAR * This);
        
        HRESULT ( __stdcall __RPC_FAR *SetLength )( 
            IPlayTLEvent __RPC_FAR * This,
            DWORD dwTime);
        
        DWORD ( __stdcall __RPC_FAR *GetEventType )( 
            IPlayTLEvent __RPC_FAR * This);
        
        HRESULT ( __stdcall __RPC_FAR *SetColor )( 
            IPlayTLEvent __RPC_FAR * This,
            DWORD dwColor);
        
        DWORD ( __stdcall __RPC_FAR *GetColor )( 
            IPlayTLEvent __RPC_FAR * This);
        
        IPlayTLTrack __RPC_FAR *( STDMETHODCALLTYPE __RPC_FAR *GetTrack )( 
            IPlayTLEvent __RPC_FAR * This);
        
        IPlayTLEvent __RPC_FAR *( STDMETHODCALLTYPE __RPC_FAR *GetNextEvent )( 
            IPlayTLEvent __RPC_FAR * This);
        
        IPlayTLEvent __RPC_FAR *( STDMETHODCALLTYPE __RPC_FAR *GetPreviousEvent )( 
            IPlayTLEvent __RPC_FAR * This);
        
        HRESULT ( __stdcall __RPC_FAR *SetUserDWORD )( 
            IPlayTLEvent __RPC_FAR * This,
            DWORD dwUserDWORD);
        
        DWORD ( __stdcall __RPC_FAR *GetUserDWORD )( 
            IPlayTLEvent __RPC_FAR * This);
        
        IPlayTLEvent __RPC_FAR *( STDMETHODCALLTYPE __RPC_FAR *GetParentEvent )( 
            IPlayTLEvent __RPC_FAR * This);
        
        IPlayTLEvent __RPC_FAR *( STDMETHODCALLTYPE __RPC_FAR *GetChildEvent )( 
            IPlayTLEvent __RPC_FAR * This,
            long lIndex);
        
        IPlayTLEvent __RPC_FAR *( STDMETHODCALLTYPE __RPC_FAR *GetFirstEventNextLevel )( 
            IPlayTLEvent __RPC_FAR * This);
        
        IPlayTLEvent __RPC_FAR *( STDMETHODCALLTYPE __RPC_FAR *GetFirstEventPreviousLevel )( 
            IPlayTLEvent __RPC_FAR * This);
        
        IPlayTLEvent __RPC_FAR *( STDMETHODCALLTYPE __RPC_FAR *GetNextEventSameLevel )( 
            IPlayTLEvent __RPC_FAR * This);
        
        IPlayTLEvent __RPC_FAR *( STDMETHODCALLTYPE __RPC_FAR *GetPreviousEventSameLevel )( 
            IPlayTLEvent __RPC_FAR * This);
        
        long ( STDMETHODCALLTYPE __RPC_FAR *GetChildLevel )( 
            IPlayTLEvent __RPC_FAR * This);
        
        HRESULT ( __stdcall __RPC_FAR *SetChildEvent )( 
            IPlayTLEvent __RPC_FAR * This,
            IPlayTLEvent __RPC_FAR *pChildEvent,
            long lIndex,
            DWORD dwFlag);
        
        DWORD ( STDMETHODCALLTYPE __RPC_FAR *GetGroupID )( 
            IPlayTLEvent __RPC_FAR * This);
        
        IPlayTLEvent __RPC_FAR *( STDMETHODCALLTYPE __RPC_FAR *GetPreviousGroupMember )( 
            IPlayTLEvent __RPC_FAR * This);
        
        IPlayTLEvent __RPC_FAR *( STDMETHODCALLTYPE __RPC_FAR *GetNextGroupMember )( 
            IPlayTLEvent __RPC_FAR * This);
        
        DWORD ( STDMETHODCALLTYPE __RPC_FAR *GetSourceIn )( 
            IPlayTLEvent __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetSourceIn )( 
            IPlayTLEvent __RPC_FAR * This,
            DWORD dwTime);
        
        IPlayTLEvent __RPC_FAR *( STDMETHODCALLTYPE __RPC_FAR *GetFirstChildEvent )( 
            IPlayTLEvent __RPC_FAR * This);
        
        void ( STDMETHODCALLTYPE __RPC_FAR *DieChildrenDie )( 
            IPlayTLEvent __RPC_FAR * This,
            BOOL bDoYouMeanIt);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetGroup )( 
            IPlayTLEvent __RPC_FAR * This,
            DWORD dwGroupID);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetPicon )( 
            IPlayTLEvent __RPC_FAR * This,
            IGXIntBitmap __RPC_FAR *picture);
        
        IGXIntBitmap __RPC_FAR *( STDMETHODCALLTYPE __RPC_FAR *GetPicon )( 
            IPlayTLEvent __RPC_FAR * This);
        
        BOOL ( STDMETHODCALLTYPE __RPC_FAR *GetClipRoll )( 
            IPlayTLEvent __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetClipRoll )( 
            IPlayTLEvent __RPC_FAR * This,
            BOOL bOn);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *EnableStartHandle )( 
            IPlayTLEvent __RPC_FAR * This,
            BOOL bOn);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *EnableEndHandle )( 
            IPlayTLEvent __RPC_FAR * This,
            BOOL bOn);
        
        BOOL ( STDMETHODCALLTYPE __RPC_FAR *IsStartHandleEnabled )( 
            IPlayTLEvent __RPC_FAR * This);
        
        BOOL ( STDMETHODCALLTYPE __RPC_FAR *IsEndHandleEnabled )( 
            IPlayTLEvent __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetLabel )( 
            IPlayTLEvent __RPC_FAR * This,
            LPSTR pszLabel);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetLabel )( 
            IPlayTLEvent __RPC_FAR * This,
            LPSTR pszLabel,
            DWORD cbBuffer);
        
        IPlayTLEvent __RPC_FAR *( __stdcall __RPC_FAR *Clone )( 
            IPlayTLEvent __RPC_FAR * This);
        
        END_INTERFACE
    } IPlayTLEventVtbl;

    interface IPlayTLEvent
    {
        CONST_VTBL struct IPlayTLEventVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IPlayTLEvent_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IPlayTLEvent_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IPlayTLEvent_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IPlayTLEvent_GetID(This)	\
    (This)->lpVtbl -> GetID(This)

#define IPlayTLEvent_GetAppData(This,ppData,pNumBytes)	\
    (This)->lpVtbl -> GetAppData(This,ppData,pNumBytes)

#define IPlayTLEvent_SetAppData(This,pData,numBytes)	\
    (This)->lpVtbl -> SetAppData(This,pData,numBytes)

#define IPlayTLEvent_GetAppObject(This)	\
    (This)->lpVtbl -> GetAppObject(This)

#define IPlayTLEvent_SetAppObject(This,pObject)	\
    (This)->lpVtbl -> SetAppObject(This,pObject)


#define IPlayTLEvent_GetStartTime(This)	\
    (This)->lpVtbl -> GetStartTime(This)

#define IPlayTLEvent_SetStartTime(This,dwTime)	\
    (This)->lpVtbl -> SetStartTime(This,dwTime)

#define IPlayTLEvent_GetEndTime(This)	\
    (This)->lpVtbl -> GetEndTime(This)

#define IPlayTLEvent_SetEndTime(This,dwTime)	\
    (This)->lpVtbl -> SetEndTime(This,dwTime)

#define IPlayTLEvent_GetLength(This)	\
    (This)->lpVtbl -> GetLength(This)

#define IPlayTLEvent_SetLength(This,dwTime)	\
    (This)->lpVtbl -> SetLength(This,dwTime)

#define IPlayTLEvent_GetEventType(This)	\
    (This)->lpVtbl -> GetEventType(This)

#define IPlayTLEvent_SetColor(This,dwColor)	\
    (This)->lpVtbl -> SetColor(This,dwColor)

#define IPlayTLEvent_GetColor(This)	\
    (This)->lpVtbl -> GetColor(This)

#define IPlayTLEvent_GetTrack(This)	\
    (This)->lpVtbl -> GetTrack(This)

#define IPlayTLEvent_GetNextEvent(This)	\
    (This)->lpVtbl -> GetNextEvent(This)

#define IPlayTLEvent_GetPreviousEvent(This)	\
    (This)->lpVtbl -> GetPreviousEvent(This)

#define IPlayTLEvent_SetUserDWORD(This,dwUserDWORD)	\
    (This)->lpVtbl -> SetUserDWORD(This,dwUserDWORD)

#define IPlayTLEvent_GetUserDWORD(This)	\
    (This)->lpVtbl -> GetUserDWORD(This)

#define IPlayTLEvent_GetParentEvent(This)	\
    (This)->lpVtbl -> GetParentEvent(This)

#define IPlayTLEvent_GetChildEvent(This,lIndex)	\
    (This)->lpVtbl -> GetChildEvent(This,lIndex)

#define IPlayTLEvent_GetFirstEventNextLevel(This)	\
    (This)->lpVtbl -> GetFirstEventNextLevel(This)

#define IPlayTLEvent_GetFirstEventPreviousLevel(This)	\
    (This)->lpVtbl -> GetFirstEventPreviousLevel(This)

#define IPlayTLEvent_GetNextEventSameLevel(This)	\
    (This)->lpVtbl -> GetNextEventSameLevel(This)

#define IPlayTLEvent_GetPreviousEventSameLevel(This)	\
    (This)->lpVtbl -> GetPreviousEventSameLevel(This)

#define IPlayTLEvent_GetChildLevel(This)	\
    (This)->lpVtbl -> GetChildLevel(This)

#define IPlayTLEvent_SetChildEvent(This,pChildEvent,lIndex,dwFlag)	\
    (This)->lpVtbl -> SetChildEvent(This,pChildEvent,lIndex,dwFlag)

#define IPlayTLEvent_GetGroupID(This)	\
    (This)->lpVtbl -> GetGroupID(This)

#define IPlayTLEvent_GetPreviousGroupMember(This)	\
    (This)->lpVtbl -> GetPreviousGroupMember(This)

#define IPlayTLEvent_GetNextGroupMember(This)	\
    (This)->lpVtbl -> GetNextGroupMember(This)

#define IPlayTLEvent_GetSourceIn(This)	\
    (This)->lpVtbl -> GetSourceIn(This)

#define IPlayTLEvent_SetSourceIn(This,dwTime)	\
    (This)->lpVtbl -> SetSourceIn(This,dwTime)

#define IPlayTLEvent_GetFirstChildEvent(This)	\
    (This)->lpVtbl -> GetFirstChildEvent(This)

#define IPlayTLEvent_DieChildrenDie(This,bDoYouMeanIt)	\
    (This)->lpVtbl -> DieChildrenDie(This,bDoYouMeanIt)

#define IPlayTLEvent_SetGroup(This,dwGroupID)	\
    (This)->lpVtbl -> SetGroup(This,dwGroupID)

#define IPlayTLEvent_SetPicon(This,picture)	\
    (This)->lpVtbl -> SetPicon(This,picture)

#define IPlayTLEvent_GetPicon(This)	\
    (This)->lpVtbl -> GetPicon(This)

#define IPlayTLEvent_GetClipRoll(This)	\
    (This)->lpVtbl -> GetClipRoll(This)

#define IPlayTLEvent_SetClipRoll(This,bOn)	\
    (This)->lpVtbl -> SetClipRoll(This,bOn)

#define IPlayTLEvent_EnableStartHandle(This,bOn)	\
    (This)->lpVtbl -> EnableStartHandle(This,bOn)

#define IPlayTLEvent_EnableEndHandle(This,bOn)	\
    (This)->lpVtbl -> EnableEndHandle(This,bOn)

#define IPlayTLEvent_IsStartHandleEnabled(This)	\
    (This)->lpVtbl -> IsStartHandleEnabled(This)

#define IPlayTLEvent_IsEndHandleEnabled(This)	\
    (This)->lpVtbl -> IsEndHandleEnabled(This)

#define IPlayTLEvent_SetLabel(This,pszLabel)	\
    (This)->lpVtbl -> SetLabel(This,pszLabel)

#define IPlayTLEvent_GetLabel(This,pszLabel,cbBuffer)	\
    (This)->lpVtbl -> GetLabel(This,pszLabel,cbBuffer)

#define IPlayTLEvent_Clone(This)	\
    (This)->lpVtbl -> Clone(This)

#endif /* COBJMACROS */


#endif 	/* C style interface */



DWORD __stdcall IPlayTLEvent_GetStartTime_Proxy( 
    IPlayTLEvent __RPC_FAR * This);


void __RPC_STUB IPlayTLEvent_GetStartTime_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT __stdcall IPlayTLEvent_SetStartTime_Proxy( 
    IPlayTLEvent __RPC_FAR * This,
    DWORD dwTime);


void __RPC_STUB IPlayTLEvent_SetStartTime_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


DWORD __stdcall IPlayTLEvent_GetEndTime_Proxy( 
    IPlayTLEvent __RPC_FAR * This);


void __RPC_STUB IPlayTLEvent_GetEndTime_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT __stdcall IPlayTLEvent_SetEndTime_Proxy( 
    IPlayTLEvent __RPC_FAR * This,
    DWORD dwTime);


void __RPC_STUB IPlayTLEvent_SetEndTime_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


DWORD __stdcall IPlayTLEvent_GetLength_Proxy( 
    IPlayTLEvent __RPC_FAR * This);


void __RPC_STUB IPlayTLEvent_GetLength_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT __stdcall IPlayTLEvent_SetLength_Proxy( 
    IPlayTLEvent __RPC_FAR * This,
    DWORD dwTime);


void __RPC_STUB IPlayTLEvent_SetLength_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


DWORD __stdcall IPlayTLEvent_GetEventType_Proxy( 
    IPlayTLEvent __RPC_FAR * This);


void __RPC_STUB IPlayTLEvent_GetEventType_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT __stdcall IPlayTLEvent_SetColor_Proxy( 
    IPlayTLEvent __RPC_FAR * This,
    DWORD dwColor);


void __RPC_STUB IPlayTLEvent_SetColor_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


DWORD __stdcall IPlayTLEvent_GetColor_Proxy( 
    IPlayTLEvent __RPC_FAR * This);


void __RPC_STUB IPlayTLEvent_GetColor_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


IPlayTLTrack __RPC_FAR *STDMETHODCALLTYPE IPlayTLEvent_GetTrack_Proxy( 
    IPlayTLEvent __RPC_FAR * This);


void __RPC_STUB IPlayTLEvent_GetTrack_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


IPlayTLEvent __RPC_FAR *STDMETHODCALLTYPE IPlayTLEvent_GetNextEvent_Proxy( 
    IPlayTLEvent __RPC_FAR * This);


void __RPC_STUB IPlayTLEvent_GetNextEvent_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


IPlayTLEvent __RPC_FAR *STDMETHODCALLTYPE IPlayTLEvent_GetPreviousEvent_Proxy( 
    IPlayTLEvent __RPC_FAR * This);


void __RPC_STUB IPlayTLEvent_GetPreviousEvent_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT __stdcall IPlayTLEvent_SetUserDWORD_Proxy( 
    IPlayTLEvent __RPC_FAR * This,
    DWORD dwUserDWORD);


void __RPC_STUB IPlayTLEvent_SetUserDWORD_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


DWORD __stdcall IPlayTLEvent_GetUserDWORD_Proxy( 
    IPlayTLEvent __RPC_FAR * This);


void __RPC_STUB IPlayTLEvent_GetUserDWORD_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


IPlayTLEvent __RPC_FAR *STDMETHODCALLTYPE IPlayTLEvent_GetParentEvent_Proxy( 
    IPlayTLEvent __RPC_FAR * This);


void __RPC_STUB IPlayTLEvent_GetParentEvent_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


IPlayTLEvent __RPC_FAR *STDMETHODCALLTYPE IPlayTLEvent_GetChildEvent_Proxy( 
    IPlayTLEvent __RPC_FAR * This,
    long lIndex);


void __RPC_STUB IPlayTLEvent_GetChildEvent_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


IPlayTLEvent __RPC_FAR *STDMETHODCALLTYPE IPlayTLEvent_GetFirstEventNextLevel_Proxy( 
    IPlayTLEvent __RPC_FAR * This);


void __RPC_STUB IPlayTLEvent_GetFirstEventNextLevel_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


IPlayTLEvent __RPC_FAR *STDMETHODCALLTYPE IPlayTLEvent_GetFirstEventPreviousLevel_Proxy( 
    IPlayTLEvent __RPC_FAR * This);


void __RPC_STUB IPlayTLEvent_GetFirstEventPreviousLevel_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


IPlayTLEvent __RPC_FAR *STDMETHODCALLTYPE IPlayTLEvent_GetNextEventSameLevel_Proxy( 
    IPlayTLEvent __RPC_FAR * This);


void __RPC_STUB IPlayTLEvent_GetNextEventSameLevel_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


IPlayTLEvent __RPC_FAR *STDMETHODCALLTYPE IPlayTLEvent_GetPreviousEventSameLevel_Proxy( 
    IPlayTLEvent __RPC_FAR * This);


void __RPC_STUB IPlayTLEvent_GetPreviousEventSameLevel_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


long STDMETHODCALLTYPE IPlayTLEvent_GetChildLevel_Proxy( 
    IPlayTLEvent __RPC_FAR * This);


void __RPC_STUB IPlayTLEvent_GetChildLevel_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT __stdcall IPlayTLEvent_SetChildEvent_Proxy( 
    IPlayTLEvent __RPC_FAR * This,
    IPlayTLEvent __RPC_FAR *pChildEvent,
    long lIndex,
    DWORD dwFlag);


void __RPC_STUB IPlayTLEvent_SetChildEvent_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


DWORD STDMETHODCALLTYPE IPlayTLEvent_GetGroupID_Proxy( 
    IPlayTLEvent __RPC_FAR * This);


void __RPC_STUB IPlayTLEvent_GetGroupID_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


IPlayTLEvent __RPC_FAR *STDMETHODCALLTYPE IPlayTLEvent_GetPreviousGroupMember_Proxy( 
    IPlayTLEvent __RPC_FAR * This);


void __RPC_STUB IPlayTLEvent_GetPreviousGroupMember_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


IPlayTLEvent __RPC_FAR *STDMETHODCALLTYPE IPlayTLEvent_GetNextGroupMember_Proxy( 
    IPlayTLEvent __RPC_FAR * This);


void __RPC_STUB IPlayTLEvent_GetNextGroupMember_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


DWORD STDMETHODCALLTYPE IPlayTLEvent_GetSourceIn_Proxy( 
    IPlayTLEvent __RPC_FAR * This);


void __RPC_STUB IPlayTLEvent_GetSourceIn_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IPlayTLEvent_SetSourceIn_Proxy( 
    IPlayTLEvent __RPC_FAR * This,
    DWORD dwTime);


void __RPC_STUB IPlayTLEvent_SetSourceIn_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


IPlayTLEvent __RPC_FAR *STDMETHODCALLTYPE IPlayTLEvent_GetFirstChildEvent_Proxy( 
    IPlayTLEvent __RPC_FAR * This);


void __RPC_STUB IPlayTLEvent_GetFirstChildEvent_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


void STDMETHODCALLTYPE IPlayTLEvent_DieChildrenDie_Proxy( 
    IPlayTLEvent __RPC_FAR * This,
    BOOL bDoYouMeanIt);


void __RPC_STUB IPlayTLEvent_DieChildrenDie_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IPlayTLEvent_SetGroup_Proxy( 
    IPlayTLEvent __RPC_FAR * This,
    DWORD dwGroupID);


void __RPC_STUB IPlayTLEvent_SetGroup_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IPlayTLEvent_SetPicon_Proxy( 
    IPlayTLEvent __RPC_FAR * This,
    IGXIntBitmap __RPC_FAR *picture);


void __RPC_STUB IPlayTLEvent_SetPicon_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


IGXIntBitmap __RPC_FAR *STDMETHODCALLTYPE IPlayTLEvent_GetPicon_Proxy( 
    IPlayTLEvent __RPC_FAR * This);


void __RPC_STUB IPlayTLEvent_GetPicon_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


BOOL STDMETHODCALLTYPE IPlayTLEvent_GetClipRoll_Proxy( 
    IPlayTLEvent __RPC_FAR * This);


void __RPC_STUB IPlayTLEvent_GetClipRoll_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IPlayTLEvent_SetClipRoll_Proxy( 
    IPlayTLEvent __RPC_FAR * This,
    BOOL bOn);


void __RPC_STUB IPlayTLEvent_SetClipRoll_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IPlayTLEvent_EnableStartHandle_Proxy( 
    IPlayTLEvent __RPC_FAR * This,
    BOOL bOn);


void __RPC_STUB IPlayTLEvent_EnableStartHandle_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IPlayTLEvent_EnableEndHandle_Proxy( 
    IPlayTLEvent __RPC_FAR * This,
    BOOL bOn);


void __RPC_STUB IPlayTLEvent_EnableEndHandle_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


BOOL STDMETHODCALLTYPE IPlayTLEvent_IsStartHandleEnabled_Proxy( 
    IPlayTLEvent __RPC_FAR * This);


void __RPC_STUB IPlayTLEvent_IsStartHandleEnabled_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


BOOL STDMETHODCALLTYPE IPlayTLEvent_IsEndHandleEnabled_Proxy( 
    IPlayTLEvent __RPC_FAR * This);


void __RPC_STUB IPlayTLEvent_IsEndHandleEnabled_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IPlayTLEvent_SetLabel_Proxy( 
    IPlayTLEvent __RPC_FAR * This,
    LPSTR pszLabel);


void __RPC_STUB IPlayTLEvent_SetLabel_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IPlayTLEvent_GetLabel_Proxy( 
    IPlayTLEvent __RPC_FAR * This,
    LPSTR pszLabel,
    DWORD cbBuffer);


void __RPC_STUB IPlayTLEvent_GetLabel_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


IPlayTLEvent __RPC_FAR *__stdcall IPlayTLEvent_Clone_Proxy( 
    IPlayTLEvent __RPC_FAR * This);


void __RPC_STUB IPlayTLEvent_Clone_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IPlayTLEvent_INTERFACE_DEFINED__ */


#ifndef __IPlayTLValueEvent_INTERFACE_DEFINED__
#define __IPlayTLValueEvent_INTERFACE_DEFINED__

/****************************************
 * Generated header for interface: IPlayTLValueEvent
 * at Tue Nov 23 05:02:07 1999
 * using MIDL 3.01.75
 ****************************************/
/* [local][uuid][object] */ 



EXTERN_C const IID IID_IPlayTLValueEvent;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    interface DECLSPEC_UUID("8335e613-ab3b-11ce-8468-0000b468276b")
    IPlayTLValueEvent : public IUnknown
    {
    public:
        virtual HRESULT __stdcall SetValue( 
            double dValue) = 0;
        
        virtual double __stdcall GetValue( void) = 0;
        
        virtual HRESULT __stdcall SetInterpolateType( 
            DWORD dwType) = 0;
        
        virtual DWORD __stdcall GetInterpolateType( void) = 0;
        
        virtual HRESULT __stdcall QuietSetValue( 
            double dValue,
            BOOL RecalcScale) = 0;
        
        virtual HRESULT __stdcall GetSplinePoints( 
            SSplinePoint __RPC_FAR *ppSpline) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IPlayTLValueEventVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            IPlayTLValueEvent __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            IPlayTLValueEvent __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            IPlayTLValueEvent __RPC_FAR * This);
        
        HRESULT ( __stdcall __RPC_FAR *SetValue )( 
            IPlayTLValueEvent __RPC_FAR * This,
            double dValue);
        
        double ( __stdcall __RPC_FAR *GetValue )( 
            IPlayTLValueEvent __RPC_FAR * This);
        
        HRESULT ( __stdcall __RPC_FAR *SetInterpolateType )( 
            IPlayTLValueEvent __RPC_FAR * This,
            DWORD dwType);
        
        DWORD ( __stdcall __RPC_FAR *GetInterpolateType )( 
            IPlayTLValueEvent __RPC_FAR * This);
        
        HRESULT ( __stdcall __RPC_FAR *QuietSetValue )( 
            IPlayTLValueEvent __RPC_FAR * This,
            double dValue,
            BOOL RecalcScale);
        
        HRESULT ( __stdcall __RPC_FAR *GetSplinePoints )( 
            IPlayTLValueEvent __RPC_FAR * This,
            SSplinePoint __RPC_FAR *ppSpline);
        
        END_INTERFACE
    } IPlayTLValueEventVtbl;

    interface IPlayTLValueEvent
    {
        CONST_VTBL struct IPlayTLValueEventVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IPlayTLValueEvent_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IPlayTLValueEvent_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IPlayTLValueEvent_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IPlayTLValueEvent_SetValue(This,dValue)	\
    (This)->lpVtbl -> SetValue(This,dValue)

#define IPlayTLValueEvent_GetValue(This)	\
    (This)->lpVtbl -> GetValue(This)

#define IPlayTLValueEvent_SetInterpolateType(This,dwType)	\
    (This)->lpVtbl -> SetInterpolateType(This,dwType)

#define IPlayTLValueEvent_GetInterpolateType(This)	\
    (This)->lpVtbl -> GetInterpolateType(This)

#define IPlayTLValueEvent_QuietSetValue(This,dValue,RecalcScale)	\
    (This)->lpVtbl -> QuietSetValue(This,dValue,RecalcScale)

#define IPlayTLValueEvent_GetSplinePoints(This,ppSpline)	\
    (This)->lpVtbl -> GetSplinePoints(This,ppSpline)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT __stdcall IPlayTLValueEvent_SetValue_Proxy( 
    IPlayTLValueEvent __RPC_FAR * This,
    double dValue);


void __RPC_STUB IPlayTLValueEvent_SetValue_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


double __stdcall IPlayTLValueEvent_GetValue_Proxy( 
    IPlayTLValueEvent __RPC_FAR * This);


void __RPC_STUB IPlayTLValueEvent_GetValue_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT __stdcall IPlayTLValueEvent_SetInterpolateType_Proxy( 
    IPlayTLValueEvent __RPC_FAR * This,
    DWORD dwType);


void __RPC_STUB IPlayTLValueEvent_SetInterpolateType_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


DWORD __stdcall IPlayTLValueEvent_GetInterpolateType_Proxy( 
    IPlayTLValueEvent __RPC_FAR * This);


void __RPC_STUB IPlayTLValueEvent_GetInterpolateType_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT __stdcall IPlayTLValueEvent_QuietSetValue_Proxy( 
    IPlayTLValueEvent __RPC_FAR * This,
    double dValue,
    BOOL RecalcScale);


void __RPC_STUB IPlayTLValueEvent_QuietSetValue_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT __stdcall IPlayTLValueEvent_GetSplinePoints_Proxy( 
    IPlayTLValueEvent __RPC_FAR * This,
    SSplinePoint __RPC_FAR *ppSpline);


void __RPC_STUB IPlayTLValueEvent_GetSplinePoints_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IPlayTLValueEvent_INTERFACE_DEFINED__ */


#ifndef __IPlayTLView_INTERFACE_DEFINED__
#define __IPlayTLView_INTERFACE_DEFINED__

/****************************************
 * Generated header for interface: IPlayTLView
 * at Tue Nov 23 05:02:07 1999
 * using MIDL 3.01.75
 ****************************************/
/* [local][uuid][object] */ 



EXTERN_C const IID IID_IPlayTLView;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    interface DECLSPEC_UUID("8335e614-ab3b-11ce-8468-0000b468276b")
    IPlayTLView : public IUnknown
    {
    public:
        virtual IPlayTimeLine __RPC_FAR *STDMETHODCALLTYPE GetTimeLine( void) = 0;
        
        virtual HRESULT __stdcall SetTimeLine( 
            IPlayTimeLine __RPC_FAR *pLine) = 0;
        
        virtual IPlayTLView __RPC_FAR *STDMETHODCALLTYPE GetNextView( void) = 0;
        
        virtual IPlayTLView __RPC_FAR *STDMETHODCALLTYPE GetPreviousView( void) = 0;
        
        virtual DWORD STDMETHODCALLTYPE GetID( void) = 0;
        
        virtual HRESULT __stdcall UpdateTrackTimes( 
            IPlayTLTrack __RPC_FAR *pTrack,
            DWORD start,
            DWORD end) = 0;
        
        virtual void __stdcall PositionBar( 
            DWORD dwTime,
            BOOL drawTime) = 0;
        
        virtual HRESULT __stdcall Die( void) = 0;
        
        virtual HRESULT __stdcall RemoveMyself( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetStartTime( 
            DWORD dwStartTime) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetEndTime( 
            DWORD dwEndTime) = 0;
        
        virtual void STDMETHODCALLTYPE ChangeLabel( 
            IPlayTLTrack __RPC_FAR *pTrack) = 0;
        
        virtual void STDMETHODCALLTYPE DrawTimebar( void) = 0;
        
        virtual void STDMETHODCALLTYPE SetTimeOffset( 
            DWORD dwOffset) = 0;
        
        virtual DWORD STDMETHODCALLTYPE GetTimeOffset( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetFieldMode( 
            BOOL bOn) = 0;
        
        virtual BOOL STDMETHODCALLTYPE GetFieldMode( void) = 0;
        
        virtual DWORD STDMETHODCALLTYPE GetStartTime( void) = 0;
        
        virtual DWORD STDMETHODCALLTYPE GetEndTime( void) = 0;
        
        virtual BOOL STDMETHODCALLTYPE IsMoving( 
            IPlayTLEvent __RPC_FAR *pEvent) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetStartAndEndTimes( 
            DWORD dwStartTime,
            DWORD dwEndTime) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE ScrollView( 
            DWORD dwStartTime,
            DWORD dwEndTime) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE UpdateAllTracks( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE OpenTrack( 
            IPlayTLTrack __RPC_FAR *pTrack) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE CloseTrack( 
            IPlayTLTrack __RPC_FAR *pTrack) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IPlayTLViewVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            IPlayTLView __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            IPlayTLView __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            IPlayTLView __RPC_FAR * This);
        
        IPlayTimeLine __RPC_FAR *( STDMETHODCALLTYPE __RPC_FAR *GetTimeLine )( 
            IPlayTLView __RPC_FAR * This);
        
        HRESULT ( __stdcall __RPC_FAR *SetTimeLine )( 
            IPlayTLView __RPC_FAR * This,
            IPlayTimeLine __RPC_FAR *pLine);
        
        IPlayTLView __RPC_FAR *( STDMETHODCALLTYPE __RPC_FAR *GetNextView )( 
            IPlayTLView __RPC_FAR * This);
        
        IPlayTLView __RPC_FAR *( STDMETHODCALLTYPE __RPC_FAR *GetPreviousView )( 
            IPlayTLView __RPC_FAR * This);
        
        DWORD ( STDMETHODCALLTYPE __RPC_FAR *GetID )( 
            IPlayTLView __RPC_FAR * This);
        
        HRESULT ( __stdcall __RPC_FAR *UpdateTrackTimes )( 
            IPlayTLView __RPC_FAR * This,
            IPlayTLTrack __RPC_FAR *pTrack,
            DWORD start,
            DWORD end);
        
        void ( __stdcall __RPC_FAR *PositionBar )( 
            IPlayTLView __RPC_FAR * This,
            DWORD dwTime,
            BOOL drawTime);
        
        HRESULT ( __stdcall __RPC_FAR *Die )( 
            IPlayTLView __RPC_FAR * This);
        
        HRESULT ( __stdcall __RPC_FAR *RemoveMyself )( 
            IPlayTLView __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetStartTime )( 
            IPlayTLView __RPC_FAR * This,
            DWORD dwStartTime);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetEndTime )( 
            IPlayTLView __RPC_FAR * This,
            DWORD dwEndTime);
        
        void ( STDMETHODCALLTYPE __RPC_FAR *ChangeLabel )( 
            IPlayTLView __RPC_FAR * This,
            IPlayTLTrack __RPC_FAR *pTrack);
        
        void ( STDMETHODCALLTYPE __RPC_FAR *DrawTimebar )( 
            IPlayTLView __RPC_FAR * This);
        
        void ( STDMETHODCALLTYPE __RPC_FAR *SetTimeOffset )( 
            IPlayTLView __RPC_FAR * This,
            DWORD dwOffset);
        
        DWORD ( STDMETHODCALLTYPE __RPC_FAR *GetTimeOffset )( 
            IPlayTLView __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetFieldMode )( 
            IPlayTLView __RPC_FAR * This,
            BOOL bOn);
        
        BOOL ( STDMETHODCALLTYPE __RPC_FAR *GetFieldMode )( 
            IPlayTLView __RPC_FAR * This);
        
        DWORD ( STDMETHODCALLTYPE __RPC_FAR *GetStartTime )( 
            IPlayTLView __RPC_FAR * This);
        
        DWORD ( STDMETHODCALLTYPE __RPC_FAR *GetEndTime )( 
            IPlayTLView __RPC_FAR * This);
        
        BOOL ( STDMETHODCALLTYPE __RPC_FAR *IsMoving )( 
            IPlayTLView __RPC_FAR * This,
            IPlayTLEvent __RPC_FAR *pEvent);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetStartAndEndTimes )( 
            IPlayTLView __RPC_FAR * This,
            DWORD dwStartTime,
            DWORD dwEndTime);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *ScrollView )( 
            IPlayTLView __RPC_FAR * This,
            DWORD dwStartTime,
            DWORD dwEndTime);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *UpdateAllTracks )( 
            IPlayTLView __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *OpenTrack )( 
            IPlayTLView __RPC_FAR * This,
            IPlayTLTrack __RPC_FAR *pTrack);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *CloseTrack )( 
            IPlayTLView __RPC_FAR * This,
            IPlayTLTrack __RPC_FAR *pTrack);
        
        END_INTERFACE
    } IPlayTLViewVtbl;

    interface IPlayTLView
    {
        CONST_VTBL struct IPlayTLViewVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IPlayTLView_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IPlayTLView_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IPlayTLView_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IPlayTLView_GetTimeLine(This)	\
    (This)->lpVtbl -> GetTimeLine(This)

#define IPlayTLView_SetTimeLine(This,pLine)	\
    (This)->lpVtbl -> SetTimeLine(This,pLine)

#define IPlayTLView_GetNextView(This)	\
    (This)->lpVtbl -> GetNextView(This)

#define IPlayTLView_GetPreviousView(This)	\
    (This)->lpVtbl -> GetPreviousView(This)

#define IPlayTLView_GetID(This)	\
    (This)->lpVtbl -> GetID(This)

#define IPlayTLView_UpdateTrackTimes(This,pTrack,start,end)	\
    (This)->lpVtbl -> UpdateTrackTimes(This,pTrack,start,end)

#define IPlayTLView_PositionBar(This,dwTime,drawTime)	\
    (This)->lpVtbl -> PositionBar(This,dwTime,drawTime)

#define IPlayTLView_Die(This)	\
    (This)->lpVtbl -> Die(This)

#define IPlayTLView_RemoveMyself(This)	\
    (This)->lpVtbl -> RemoveMyself(This)

#define IPlayTLView_SetStartTime(This,dwStartTime)	\
    (This)->lpVtbl -> SetStartTime(This,dwStartTime)

#define IPlayTLView_SetEndTime(This,dwEndTime)	\
    (This)->lpVtbl -> SetEndTime(This,dwEndTime)

#define IPlayTLView_ChangeLabel(This,pTrack)	\
    (This)->lpVtbl -> ChangeLabel(This,pTrack)

#define IPlayTLView_DrawTimebar(This)	\
    (This)->lpVtbl -> DrawTimebar(This)

#define IPlayTLView_SetTimeOffset(This,dwOffset)	\
    (This)->lpVtbl -> SetTimeOffset(This,dwOffset)

#define IPlayTLView_GetTimeOffset(This)	\
    (This)->lpVtbl -> GetTimeOffset(This)

#define IPlayTLView_SetFieldMode(This,bOn)	\
    (This)->lpVtbl -> SetFieldMode(This,bOn)

#define IPlayTLView_GetFieldMode(This)	\
    (This)->lpVtbl -> GetFieldMode(This)

#define IPlayTLView_GetStartTime(This)	\
    (This)->lpVtbl -> GetStartTime(This)

#define IPlayTLView_GetEndTime(This)	\
    (This)->lpVtbl -> GetEndTime(This)

#define IPlayTLView_IsMoving(This,pEvent)	\
    (This)->lpVtbl -> IsMoving(This,pEvent)

#define IPlayTLView_SetStartAndEndTimes(This,dwStartTime,dwEndTime)	\
    (This)->lpVtbl -> SetStartAndEndTimes(This,dwStartTime,dwEndTime)

#define IPlayTLView_ScrollView(This,dwStartTime,dwEndTime)	\
    (This)->lpVtbl -> ScrollView(This,dwStartTime,dwEndTime)

#define IPlayTLView_UpdateAllTracks(This)	\
    (This)->lpVtbl -> UpdateAllTracks(This)

#define IPlayTLView_OpenTrack(This,pTrack)	\
    (This)->lpVtbl -> OpenTrack(This,pTrack)

#define IPlayTLView_CloseTrack(This,pTrack)	\
    (This)->lpVtbl -> CloseTrack(This,pTrack)

#endif /* COBJMACROS */


#endif 	/* C style interface */



IPlayTimeLine __RPC_FAR *STDMETHODCALLTYPE IPlayTLView_GetTimeLine_Proxy( 
    IPlayTLView __RPC_FAR * This);


void __RPC_STUB IPlayTLView_GetTimeLine_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT __stdcall IPlayTLView_SetTimeLine_Proxy( 
    IPlayTLView __RPC_FAR * This,
    IPlayTimeLine __RPC_FAR *pLine);


void __RPC_STUB IPlayTLView_SetTimeLine_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


IPlayTLView __RPC_FAR *STDMETHODCALLTYPE IPlayTLView_GetNextView_Proxy( 
    IPlayTLView __RPC_FAR * This);


void __RPC_STUB IPlayTLView_GetNextView_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


IPlayTLView __RPC_FAR *STDMETHODCALLTYPE IPlayTLView_GetPreviousView_Proxy( 
    IPlayTLView __RPC_FAR * This);


void __RPC_STUB IPlayTLView_GetPreviousView_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


DWORD STDMETHODCALLTYPE IPlayTLView_GetID_Proxy( 
    IPlayTLView __RPC_FAR * This);


void __RPC_STUB IPlayTLView_GetID_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT __stdcall IPlayTLView_UpdateTrackTimes_Proxy( 
    IPlayTLView __RPC_FAR * This,
    IPlayTLTrack __RPC_FAR *pTrack,
    DWORD start,
    DWORD end);


void __RPC_STUB IPlayTLView_UpdateTrackTimes_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


void __stdcall IPlayTLView_PositionBar_Proxy( 
    IPlayTLView __RPC_FAR * This,
    DWORD dwTime,
    BOOL drawTime);


void __RPC_STUB IPlayTLView_PositionBar_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT __stdcall IPlayTLView_Die_Proxy( 
    IPlayTLView __RPC_FAR * This);


void __RPC_STUB IPlayTLView_Die_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT __stdcall IPlayTLView_RemoveMyself_Proxy( 
    IPlayTLView __RPC_FAR * This);


void __RPC_STUB IPlayTLView_RemoveMyself_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IPlayTLView_SetStartTime_Proxy( 
    IPlayTLView __RPC_FAR * This,
    DWORD dwStartTime);


void __RPC_STUB IPlayTLView_SetStartTime_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IPlayTLView_SetEndTime_Proxy( 
    IPlayTLView __RPC_FAR * This,
    DWORD dwEndTime);


void __RPC_STUB IPlayTLView_SetEndTime_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


void STDMETHODCALLTYPE IPlayTLView_ChangeLabel_Proxy( 
    IPlayTLView __RPC_FAR * This,
    IPlayTLTrack __RPC_FAR *pTrack);


void __RPC_STUB IPlayTLView_ChangeLabel_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


void STDMETHODCALLTYPE IPlayTLView_DrawTimebar_Proxy( 
    IPlayTLView __RPC_FAR * This);


void __RPC_STUB IPlayTLView_DrawTimebar_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


void STDMETHODCALLTYPE IPlayTLView_SetTimeOffset_Proxy( 
    IPlayTLView __RPC_FAR * This,
    DWORD dwOffset);


void __RPC_STUB IPlayTLView_SetTimeOffset_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


DWORD STDMETHODCALLTYPE IPlayTLView_GetTimeOffset_Proxy( 
    IPlayTLView __RPC_FAR * This);


void __RPC_STUB IPlayTLView_GetTimeOffset_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IPlayTLView_SetFieldMode_Proxy( 
    IPlayTLView __RPC_FAR * This,
    BOOL bOn);


void __RPC_STUB IPlayTLView_SetFieldMode_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


BOOL STDMETHODCALLTYPE IPlayTLView_GetFieldMode_Proxy( 
    IPlayTLView __RPC_FAR * This);


void __RPC_STUB IPlayTLView_GetFieldMode_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


DWORD STDMETHODCALLTYPE IPlayTLView_GetStartTime_Proxy( 
    IPlayTLView __RPC_FAR * This);


void __RPC_STUB IPlayTLView_GetStartTime_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


DWORD STDMETHODCALLTYPE IPlayTLView_GetEndTime_Proxy( 
    IPlayTLView __RPC_FAR * This);


void __RPC_STUB IPlayTLView_GetEndTime_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


BOOL STDMETHODCALLTYPE IPlayTLView_IsMoving_Proxy( 
    IPlayTLView __RPC_FAR * This,
    IPlayTLEvent __RPC_FAR *pEvent);


void __RPC_STUB IPlayTLView_IsMoving_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IPlayTLView_SetStartAndEndTimes_Proxy( 
    IPlayTLView __RPC_FAR * This,
    DWORD dwStartTime,
    DWORD dwEndTime);


void __RPC_STUB IPlayTLView_SetStartAndEndTimes_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IPlayTLView_ScrollView_Proxy( 
    IPlayTLView __RPC_FAR * This,
    DWORD dwStartTime,
    DWORD dwEndTime);


void __RPC_STUB IPlayTLView_ScrollView_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IPlayTLView_UpdateAllTracks_Proxy( 
    IPlayTLView __RPC_FAR * This);


void __RPC_STUB IPlayTLView_UpdateAllTracks_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IPlayTLView_OpenTrack_Proxy( 
    IPlayTLView __RPC_FAR * This,
    IPlayTLTrack __RPC_FAR *pTrack);


void __RPC_STUB IPlayTLView_OpenTrack_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IPlayTLView_CloseTrack_Proxy( 
    IPlayTLView __RPC_FAR * This,
    IPlayTLTrack __RPC_FAR *pTrack);


void __RPC_STUB IPlayTLView_CloseTrack_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IPlayTLView_INTERFACE_DEFINED__ */


#ifndef __IPlayTLViewPrivate_INTERFACE_DEFINED__
#define __IPlayTLViewPrivate_INTERFACE_DEFINED__

/****************************************
 * Generated header for interface: IPlayTLViewPrivate
 * at Tue Nov 23 05:02:07 1999
 * using MIDL 3.01.75
 ****************************************/
/* [local][uuid][object] */ 



EXTERN_C const IID IID_IPlayTLViewPrivate;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    interface DECLSPEC_UUID("8335e615-ab3b-11ce-8468-0000b468276b")
    IPlayTLViewPrivate : public IUnknown
    {
    public:
        virtual HRESULT __stdcall SetManagerAdviser( 
            IPlayTLManagerAdviser __RPC_FAR *pAdviser) = 0;
        
        virtual IPlayTLManagerAdviser __RPC_FAR *__stdcall GetManagerAdviser( void) = 0;
        
        virtual HRESULT __stdcall NewTrack( 
            IPlayTLTrack __RPC_FAR *prevTrack,
            IPlayTLTrack __RPC_FAR *pTrack) = 0;
        
        virtual HRESULT __stdcall DeleteTrack( 
            IPlayTLTrack __RPC_FAR *pTrack) = 0;
        
        virtual HRESULT __stdcall SetNextView( 
            IPlayTLView __RPC_FAR *pView) = 0;
        
        virtual HRESULT __stdcall SetPreviousView( 
            IPlayTLView __RPC_FAR *pView) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IPlayTLViewPrivateVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            IPlayTLViewPrivate __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            IPlayTLViewPrivate __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            IPlayTLViewPrivate __RPC_FAR * This);
        
        HRESULT ( __stdcall __RPC_FAR *SetManagerAdviser )( 
            IPlayTLViewPrivate __RPC_FAR * This,
            IPlayTLManagerAdviser __RPC_FAR *pAdviser);
        
        IPlayTLManagerAdviser __RPC_FAR *( __stdcall __RPC_FAR *GetManagerAdviser )( 
            IPlayTLViewPrivate __RPC_FAR * This);
        
        HRESULT ( __stdcall __RPC_FAR *NewTrack )( 
            IPlayTLViewPrivate __RPC_FAR * This,
            IPlayTLTrack __RPC_FAR *prevTrack,
            IPlayTLTrack __RPC_FAR *pTrack);
        
        HRESULT ( __stdcall __RPC_FAR *DeleteTrack )( 
            IPlayTLViewPrivate __RPC_FAR * This,
            IPlayTLTrack __RPC_FAR *pTrack);
        
        HRESULT ( __stdcall __RPC_FAR *SetNextView )( 
            IPlayTLViewPrivate __RPC_FAR * This,
            IPlayTLView __RPC_FAR *pView);
        
        HRESULT ( __stdcall __RPC_FAR *SetPreviousView )( 
            IPlayTLViewPrivate __RPC_FAR * This,
            IPlayTLView __RPC_FAR *pView);
        
        END_INTERFACE
    } IPlayTLViewPrivateVtbl;

    interface IPlayTLViewPrivate
    {
        CONST_VTBL struct IPlayTLViewPrivateVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IPlayTLViewPrivate_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IPlayTLViewPrivate_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IPlayTLViewPrivate_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IPlayTLViewPrivate_SetManagerAdviser(This,pAdviser)	\
    (This)->lpVtbl -> SetManagerAdviser(This,pAdviser)

#define IPlayTLViewPrivate_GetManagerAdviser(This)	\
    (This)->lpVtbl -> GetManagerAdviser(This)

#define IPlayTLViewPrivate_NewTrack(This,prevTrack,pTrack)	\
    (This)->lpVtbl -> NewTrack(This,prevTrack,pTrack)

#define IPlayTLViewPrivate_DeleteTrack(This,pTrack)	\
    (This)->lpVtbl -> DeleteTrack(This,pTrack)

#define IPlayTLViewPrivate_SetNextView(This,pView)	\
    (This)->lpVtbl -> SetNextView(This,pView)

#define IPlayTLViewPrivate_SetPreviousView(This,pView)	\
    (This)->lpVtbl -> SetPreviousView(This,pView)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT __stdcall IPlayTLViewPrivate_SetManagerAdviser_Proxy( 
    IPlayTLViewPrivate __RPC_FAR * This,
    IPlayTLManagerAdviser __RPC_FAR *pAdviser);


void __RPC_STUB IPlayTLViewPrivate_SetManagerAdviser_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


IPlayTLManagerAdviser __RPC_FAR *__stdcall IPlayTLViewPrivate_GetManagerAdviser_Proxy( 
    IPlayTLViewPrivate __RPC_FAR * This);


void __RPC_STUB IPlayTLViewPrivate_GetManagerAdviser_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT __stdcall IPlayTLViewPrivate_NewTrack_Proxy( 
    IPlayTLViewPrivate __RPC_FAR * This,
    IPlayTLTrack __RPC_FAR *prevTrack,
    IPlayTLTrack __RPC_FAR *pTrack);


void __RPC_STUB IPlayTLViewPrivate_NewTrack_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT __stdcall IPlayTLViewPrivate_DeleteTrack_Proxy( 
    IPlayTLViewPrivate __RPC_FAR * This,
    IPlayTLTrack __RPC_FAR *pTrack);


void __RPC_STUB IPlayTLViewPrivate_DeleteTrack_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT __stdcall IPlayTLViewPrivate_SetNextView_Proxy( 
    IPlayTLViewPrivate __RPC_FAR * This,
    IPlayTLView __RPC_FAR *pView);


void __RPC_STUB IPlayTLViewPrivate_SetNextView_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT __stdcall IPlayTLViewPrivate_SetPreviousView_Proxy( 
    IPlayTLViewPrivate __RPC_FAR * This,
    IPlayTLView __RPC_FAR *pView);


void __RPC_STUB IPlayTLViewPrivate_SetPreviousView_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IPlayTLViewPrivate_INTERFACE_DEFINED__ */


#ifndef __IPlayTLTrackPrivate_INTERFACE_DEFINED__
#define __IPlayTLTrackPrivate_INTERFACE_DEFINED__

/****************************************
 * Generated header for interface: IPlayTLTrackPrivate
 * at Tue Nov 23 05:02:07 1999
 * using MIDL 3.01.75
 ****************************************/
/* [local][uuid][object] */ 



EXTERN_C const IID IID_IPlayTLTrackPrivate;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    interface DECLSPEC_UUID("8335e616-ab3b-11ce-8468-0000b468276b")
    IPlayTLTrackPrivate : public IPlayTLTrack
    {
    public:
        virtual HRESULT __stdcall SetParentTrack( 
            IPlayTLTrack __RPC_FAR *pParent) = 0;
        
        virtual HRESULT __stdcall SetNextTrack( 
            IPlayTLTrack __RPC_FAR *pTrack) = 0;
        
        virtual HRESULT __stdcall SetPreviousTrack( 
            IPlayTLTrack __RPC_FAR *pTrack) = 0;
        
        virtual HRESULT __stdcall SetTimeLine( 
            IPlayTimeLine __RPC_FAR *pTimeLine) = 0;
        
        virtual HRESULT __stdcall SetID( 
            DWORD dwId) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IPlayTLTrackPrivateVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            IPlayTLTrackPrivate __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            IPlayTLTrackPrivate __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            IPlayTLTrackPrivate __RPC_FAR * This);
        
        DWORD ( STDMETHODCALLTYPE __RPC_FAR *GetID )( 
            IPlayTLTrackPrivate __RPC_FAR * This);
        
        HRESULT ( __stdcall __RPC_FAR *GetAppData )( 
            IPlayTLTrackPrivate __RPC_FAR * This,
            LPVOID __RPC_FAR *ppData,
            DWORD __RPC_FAR *pNumBytes);
        
        HRESULT ( __stdcall __RPC_FAR *SetAppData )( 
            IPlayTLTrackPrivate __RPC_FAR * This,
            LPVOID pData,
            DWORD numBytes);
        
        IUnknown __RPC_FAR *( STDMETHODCALLTYPE __RPC_FAR *GetAppObject )( 
            IPlayTLTrackPrivate __RPC_FAR * This);
        
        HRESULT ( __stdcall __RPC_FAR *SetAppObject )( 
            IPlayTLTrackPrivate __RPC_FAR * This,
            IUnknown __RPC_FAR *pObject);
        
        HRESULT ( __stdcall __RPC_FAR *AddEvent )( 
            IPlayTLTrackPrivate __RPC_FAR * This,
            IPlayTLEvent __RPC_FAR *pEvent);
        
        HRESULT ( __stdcall __RPC_FAR *RemoveEvent )( 
            IPlayTLTrackPrivate __RPC_FAR * This,
            IPlayTLEvent __RPC_FAR *__RPC_FAR *ppEvent,
            DWORD dwTime);
        
        HRESULT ( __stdcall __RPC_FAR *MoveEvent )( 
            IPlayTLTrackPrivate __RPC_FAR * This,
            IPlayTLEvent __RPC_FAR *pEvent,
            long timeDiff);
        
        IPlayTLEvent __RPC_FAR *( STDMETHODCALLTYPE __RPC_FAR *GetEvent )( 
            IPlayTLTrackPrivate __RPC_FAR * This,
            DWORD dwTime);
        
        IPlayTLEvent __RPC_FAR *( STDMETHODCALLTYPE __RPC_FAR *GetClosestEvent )( 
            IPlayTLTrackPrivate __RPC_FAR * This,
            DWORD dwTime);
        
        IPlayTLEvent __RPC_FAR *( STDMETHODCALLTYPE __RPC_FAR *GetLastEvent )( 
            IPlayTLTrackPrivate __RPC_FAR * This);
        
        DWORD ( __stdcall __RPC_FAR *GetFreeTime )( 
            IPlayTLTrackPrivate __RPC_FAR * This,
            DWORD dwTime,
            DWORD __RPC_FAR *startFree,
            DWORD __RPC_FAR *endFree);
        
        HRESULT ( __stdcall __RPC_FAR *AddChildTrack )( 
            IPlayTLTrackPrivate __RPC_FAR * This,
            IPlayTLTrack __RPC_FAR *pChild,
            long nPos);
        
        HRESULT ( __stdcall __RPC_FAR *RemoveChildTrack )( 
            IPlayTLTrackPrivate __RPC_FAR * This,
            IPlayTLTrack __RPC_FAR *__RPC_FAR *ppChild,
            DWORD dwID);
        
        IPlayTLTrack __RPC_FAR *( STDMETHODCALLTYPE __RPC_FAR *GetChildTrack )( 
            IPlayTLTrackPrivate __RPC_FAR * This);
        
        IPlayTLTrack __RPC_FAR *( STDMETHODCALLTYPE __RPC_FAR *GetParentTrack )( 
            IPlayTLTrackPrivate __RPC_FAR * This);
        
        IPlayTLTrack __RPC_FAR *( STDMETHODCALLTYPE __RPC_FAR *GetNextTrack )( 
            IPlayTLTrackPrivate __RPC_FAR * This);
        
        IPlayTLTrack __RPC_FAR *( STDMETHODCALLTYPE __RPC_FAR *GetPreviousTrack )( 
            IPlayTLTrackPrivate __RPC_FAR * This);
        
        IPlayTimeLine __RPC_FAR *( STDMETHODCALLTYPE __RPC_FAR *GetTimeLine )( 
            IPlayTLTrackPrivate __RPC_FAR * This);
        
        HRESULT ( __stdcall __RPC_FAR *GetLabel )( 
            IPlayTLTrackPrivate __RPC_FAR * This,
            LPSTR pszLabel,
            DWORD numBytes);
        
        HRESULT ( __stdcall __RPC_FAR *SetLabel )( 
            IPlayTLTrackPrivate __RPC_FAR * This,
            LPSTR pszLabel);
        
        DWORD ( __stdcall __RPC_FAR *GetTrackType )( 
            IPlayTLTrackPrivate __RPC_FAR * This);
        
        BOOL ( __stdcall __RPC_FAR *EventsCollide )( 
            IPlayTLTrackPrivate __RPC_FAR * This,
            IPlayTLEvent __RPC_FAR *pEvent);
        
        HRESULT ( __stdcall __RPC_FAR *SetUserDWORD )( 
            IPlayTLTrackPrivate __RPC_FAR * This,
            DWORD dwUserDWORD);
        
        DWORD ( __stdcall __RPC_FAR *GetUserDWORD )( 
            IPlayTLTrackPrivate __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Delete )( 
            IPlayTLTrackPrivate __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetRippleMode )( 
            IPlayTLTrackPrivate __RPC_FAR * This,
            BOOL bOn);
        
        BOOL ( STDMETHODCALLTYPE __RPC_FAR *GetRippleMode )( 
            IPlayTLTrackPrivate __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *ToggleRippleMode )( 
            IPlayTLTrackPrivate __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetEventInterpolateType )( 
            IPlayTLTrackPrivate __RPC_FAR * This,
            IPlayTLEvent __RPC_FAR *pEvent,
            DWORD dwType);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetDefaultTrackHeight )( 
            IPlayTLTrackPrivate __RPC_FAR * This,
            long lHeight);
        
        long ( STDMETHODCALLTYPE __RPC_FAR *GetDefaultTrackHeight )( 
            IPlayTLTrackPrivate __RPC_FAR * This);
        
        IPlayTLTrack __RPC_FAR *( __stdcall __RPC_FAR *Clone )( 
            IPlayTLTrackPrivate __RPC_FAR * This);
        
        IPlayTLTrack __RPC_FAR *( __stdcall __RPC_FAR *ClonePartial )( 
            IPlayTLTrackPrivate __RPC_FAR * This,
            long lStartTime,
            long lEndTime);
        
        HRESULT ( __stdcall __RPC_FAR *SetParentTrack )( 
            IPlayTLTrackPrivate __RPC_FAR * This,
            IPlayTLTrack __RPC_FAR *pParent);
        
        HRESULT ( __stdcall __RPC_FAR *SetNextTrack )( 
            IPlayTLTrackPrivate __RPC_FAR * This,
            IPlayTLTrack __RPC_FAR *pTrack);
        
        HRESULT ( __stdcall __RPC_FAR *SetPreviousTrack )( 
            IPlayTLTrackPrivate __RPC_FAR * This,
            IPlayTLTrack __RPC_FAR *pTrack);
        
        HRESULT ( __stdcall __RPC_FAR *SetTimeLine )( 
            IPlayTLTrackPrivate __RPC_FAR * This,
            IPlayTimeLine __RPC_FAR *pTimeLine);
        
        HRESULT ( __stdcall __RPC_FAR *SetID )( 
            IPlayTLTrackPrivate __RPC_FAR * This,
            DWORD dwId);
        
        END_INTERFACE
    } IPlayTLTrackPrivateVtbl;

    interface IPlayTLTrackPrivate
    {
        CONST_VTBL struct IPlayTLTrackPrivateVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IPlayTLTrackPrivate_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IPlayTLTrackPrivate_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IPlayTLTrackPrivate_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IPlayTLTrackPrivate_GetID(This)	\
    (This)->lpVtbl -> GetID(This)

#define IPlayTLTrackPrivate_GetAppData(This,ppData,pNumBytes)	\
    (This)->lpVtbl -> GetAppData(This,ppData,pNumBytes)

#define IPlayTLTrackPrivate_SetAppData(This,pData,numBytes)	\
    (This)->lpVtbl -> SetAppData(This,pData,numBytes)

#define IPlayTLTrackPrivate_GetAppObject(This)	\
    (This)->lpVtbl -> GetAppObject(This)

#define IPlayTLTrackPrivate_SetAppObject(This,pObject)	\
    (This)->lpVtbl -> SetAppObject(This,pObject)


#define IPlayTLTrackPrivate_AddEvent(This,pEvent)	\
    (This)->lpVtbl -> AddEvent(This,pEvent)

#define IPlayTLTrackPrivate_RemoveEvent(This,ppEvent,dwTime)	\
    (This)->lpVtbl -> RemoveEvent(This,ppEvent,dwTime)

#define IPlayTLTrackPrivate_MoveEvent(This,pEvent,timeDiff)	\
    (This)->lpVtbl -> MoveEvent(This,pEvent,timeDiff)

#define IPlayTLTrackPrivate_GetEvent(This,dwTime)	\
    (This)->lpVtbl -> GetEvent(This,dwTime)

#define IPlayTLTrackPrivate_GetClosestEvent(This,dwTime)	\
    (This)->lpVtbl -> GetClosestEvent(This,dwTime)

#define IPlayTLTrackPrivate_GetLastEvent(This)	\
    (This)->lpVtbl -> GetLastEvent(This)

#define IPlayTLTrackPrivate_GetFreeTime(This,dwTime,startFree,endFree)	\
    (This)->lpVtbl -> GetFreeTime(This,dwTime,startFree,endFree)

#define IPlayTLTrackPrivate_AddChildTrack(This,pChild,nPos)	\
    (This)->lpVtbl -> AddChildTrack(This,pChild,nPos)

#define IPlayTLTrackPrivate_RemoveChildTrack(This,ppChild,dwID)	\
    (This)->lpVtbl -> RemoveChildTrack(This,ppChild,dwID)

#define IPlayTLTrackPrivate_GetChildTrack(This)	\
    (This)->lpVtbl -> GetChildTrack(This)

#define IPlayTLTrackPrivate_GetParentTrack(This)	\
    (This)->lpVtbl -> GetParentTrack(This)

#define IPlayTLTrackPrivate_GetNextTrack(This)	\
    (This)->lpVtbl -> GetNextTrack(This)

#define IPlayTLTrackPrivate_GetPreviousTrack(This)	\
    (This)->lpVtbl -> GetPreviousTrack(This)

#define IPlayTLTrackPrivate_GetTimeLine(This)	\
    (This)->lpVtbl -> GetTimeLine(This)

#define IPlayTLTrackPrivate_GetLabel(This,pszLabel,numBytes)	\
    (This)->lpVtbl -> GetLabel(This,pszLabel,numBytes)

#define IPlayTLTrackPrivate_SetLabel(This,pszLabel)	\
    (This)->lpVtbl -> SetLabel(This,pszLabel)

#define IPlayTLTrackPrivate_GetTrackType(This)	\
    (This)->lpVtbl -> GetTrackType(This)

#define IPlayTLTrackPrivate_EventsCollide(This,pEvent)	\
    (This)->lpVtbl -> EventsCollide(This,pEvent)

#define IPlayTLTrackPrivate_SetUserDWORD(This,dwUserDWORD)	\
    (This)->lpVtbl -> SetUserDWORD(This,dwUserDWORD)

#define IPlayTLTrackPrivate_GetUserDWORD(This)	\
    (This)->lpVtbl -> GetUserDWORD(This)

#define IPlayTLTrackPrivate_Delete(This)	\
    (This)->lpVtbl -> Delete(This)

#define IPlayTLTrackPrivate_SetRippleMode(This,bOn)	\
    (This)->lpVtbl -> SetRippleMode(This,bOn)

#define IPlayTLTrackPrivate_GetRippleMode(This)	\
    (This)->lpVtbl -> GetRippleMode(This)

#define IPlayTLTrackPrivate_ToggleRippleMode(This)	\
    (This)->lpVtbl -> ToggleRippleMode(This)

#define IPlayTLTrackPrivate_SetEventInterpolateType(This,pEvent,dwType)	\
    (This)->lpVtbl -> SetEventInterpolateType(This,pEvent,dwType)

#define IPlayTLTrackPrivate_SetDefaultTrackHeight(This,lHeight)	\
    (This)->lpVtbl -> SetDefaultTrackHeight(This,lHeight)

#define IPlayTLTrackPrivate_GetDefaultTrackHeight(This)	\
    (This)->lpVtbl -> GetDefaultTrackHeight(This)

#define IPlayTLTrackPrivate_Clone(This)	\
    (This)->lpVtbl -> Clone(This)

#define IPlayTLTrackPrivate_ClonePartial(This,lStartTime,lEndTime)	\
    (This)->lpVtbl -> ClonePartial(This,lStartTime,lEndTime)


#define IPlayTLTrackPrivate_SetParentTrack(This,pParent)	\
    (This)->lpVtbl -> SetParentTrack(This,pParent)

#define IPlayTLTrackPrivate_SetNextTrack(This,pTrack)	\
    (This)->lpVtbl -> SetNextTrack(This,pTrack)

#define IPlayTLTrackPrivate_SetPreviousTrack(This,pTrack)	\
    (This)->lpVtbl -> SetPreviousTrack(This,pTrack)

#define IPlayTLTrackPrivate_SetTimeLine(This,pTimeLine)	\
    (This)->lpVtbl -> SetTimeLine(This,pTimeLine)

#define IPlayTLTrackPrivate_SetID(This,dwId)	\
    (This)->lpVtbl -> SetID(This,dwId)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT __stdcall IPlayTLTrackPrivate_SetParentTrack_Proxy( 
    IPlayTLTrackPrivate __RPC_FAR * This,
    IPlayTLTrack __RPC_FAR *pParent);


void __RPC_STUB IPlayTLTrackPrivate_SetParentTrack_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT __stdcall IPlayTLTrackPrivate_SetNextTrack_Proxy( 
    IPlayTLTrackPrivate __RPC_FAR * This,
    IPlayTLTrack __RPC_FAR *pTrack);


void __RPC_STUB IPlayTLTrackPrivate_SetNextTrack_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT __stdcall IPlayTLTrackPrivate_SetPreviousTrack_Proxy( 
    IPlayTLTrackPrivate __RPC_FAR * This,
    IPlayTLTrack __RPC_FAR *pTrack);


void __RPC_STUB IPlayTLTrackPrivate_SetPreviousTrack_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT __stdcall IPlayTLTrackPrivate_SetTimeLine_Proxy( 
    IPlayTLTrackPrivate __RPC_FAR * This,
    IPlayTimeLine __RPC_FAR *pTimeLine);


void __RPC_STUB IPlayTLTrackPrivate_SetTimeLine_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT __stdcall IPlayTLTrackPrivate_SetID_Proxy( 
    IPlayTLTrackPrivate __RPC_FAR * This,
    DWORD dwId);


void __RPC_STUB IPlayTLTrackPrivate_SetID_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IPlayTLTrackPrivate_INTERFACE_DEFINED__ */


#ifndef __IPlayTLEventPrivate_INTERFACE_DEFINED__
#define __IPlayTLEventPrivate_INTERFACE_DEFINED__

/****************************************
 * Generated header for interface: IPlayTLEventPrivate
 * at Tue Nov 23 05:02:07 1999
 * using MIDL 3.01.75
 ****************************************/
/* [local][uuid][object] */ 



EXTERN_C const IID IID_IPlayTLEventPrivate;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    interface DECLSPEC_UUID("8335e617-ab3b-11ce-8468-0000b468276b")
    IPlayTLEventPrivate : public IPlayTLEvent
    {
    public:
        virtual HRESULT __stdcall SetNextEvent( 
            IPlayTLEvent __RPC_FAR *pEvent) = 0;
        
        virtual HRESULT __stdcall SetPreviousEvent( 
            IPlayTLEvent __RPC_FAR *pEvent) = 0;
        
        virtual HRESULT __stdcall SetTrack( 
            IPlayTLTrack __RPC_FAR *pTrack) = 0;
        
        virtual HRESULT __stdcall SetParentEvent( 
            IPlayTLEvent __RPC_FAR *pParentEvent) = 0;
        
        virtual HRESULT __stdcall SetFirstEventNextLevel( 
            IPlayTLEvent __RPC_FAR *pFirstEvent) = 0;
        
        virtual HRESULT __stdcall SetFirstEventPreviousLevel( 
            IPlayTLEvent __RPC_FAR *pFirstEvent) = 0;
        
        virtual HRESULT __stdcall SetNextEventSameLevel( 
            IPlayTLEvent __RPC_FAR *pNextEvent) = 0;
        
        virtual HRESULT __stdcall SetPreviousEventSameLevel( 
            IPlayTLEvent __RPC_FAR *pPrevEvent) = 0;
        
        virtual HRESULT __stdcall SetChildLevel( 
            long lLevel) = 0;
        
        virtual HRESULT __stdcall SetFirstChildEvent( 
            IPlayTLEvent __RPC_FAR *pChildEvent) = 0;
        
        virtual HRESULT __stdcall SetNextGroupMember( 
            IPlayTLEvent __RPC_FAR *pEvent) = 0;
        
        virtual HRESULT __stdcall SetPreviousGroupMember( 
            IPlayTLEvent __RPC_FAR *pEvent) = 0;
        
        virtual HRESULT __stdcall SetGroupID( 
            DWORD dwGroupID) = 0;
        
        virtual HRESULT __stdcall SetID( 
            DWORD dwId) = 0;
        
        virtual HRESULT __stdcall HookUpLinks( 
            IPlayTimeLine __RPC_FAR *pTimeLine) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IPlayTLEventPrivateVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            IPlayTLEventPrivate __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            IPlayTLEventPrivate __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            IPlayTLEventPrivate __RPC_FAR * This);
        
        DWORD ( STDMETHODCALLTYPE __RPC_FAR *GetID )( 
            IPlayTLEventPrivate __RPC_FAR * This);
        
        HRESULT ( __stdcall __RPC_FAR *GetAppData )( 
            IPlayTLEventPrivate __RPC_FAR * This,
            LPVOID __RPC_FAR *ppData,
            DWORD __RPC_FAR *pNumBytes);
        
        HRESULT ( __stdcall __RPC_FAR *SetAppData )( 
            IPlayTLEventPrivate __RPC_FAR * This,
            LPVOID pData,
            DWORD numBytes);
        
        IUnknown __RPC_FAR *( STDMETHODCALLTYPE __RPC_FAR *GetAppObject )( 
            IPlayTLEventPrivate __RPC_FAR * This);
        
        HRESULT ( __stdcall __RPC_FAR *SetAppObject )( 
            IPlayTLEventPrivate __RPC_FAR * This,
            IUnknown __RPC_FAR *pObject);
        
        DWORD ( __stdcall __RPC_FAR *GetStartTime )( 
            IPlayTLEventPrivate __RPC_FAR * This);
        
        HRESULT ( __stdcall __RPC_FAR *SetStartTime )( 
            IPlayTLEventPrivate __RPC_FAR * This,
            DWORD dwTime);
        
        DWORD ( __stdcall __RPC_FAR *GetEndTime )( 
            IPlayTLEventPrivate __RPC_FAR * This);
        
        HRESULT ( __stdcall __RPC_FAR *SetEndTime )( 
            IPlayTLEventPrivate __RPC_FAR * This,
            DWORD dwTime);
        
        DWORD ( __stdcall __RPC_FAR *GetLength )( 
            IPlayTLEventPrivate __RPC_FAR * This);
        
        HRESULT ( __stdcall __RPC_FAR *SetLength )( 
            IPlayTLEventPrivate __RPC_FAR * This,
            DWORD dwTime);
        
        DWORD ( __stdcall __RPC_FAR *GetEventType )( 
            IPlayTLEventPrivate __RPC_FAR * This);
        
        HRESULT ( __stdcall __RPC_FAR *SetColor )( 
            IPlayTLEventPrivate __RPC_FAR * This,
            DWORD dwColor);
        
        DWORD ( __stdcall __RPC_FAR *GetColor )( 
            IPlayTLEventPrivate __RPC_FAR * This);
        
        IPlayTLTrack __RPC_FAR *( STDMETHODCALLTYPE __RPC_FAR *GetTrack )( 
            IPlayTLEventPrivate __RPC_FAR * This);
        
        IPlayTLEvent __RPC_FAR *( STDMETHODCALLTYPE __RPC_FAR *GetNextEvent )( 
            IPlayTLEventPrivate __RPC_FAR * This);
        
        IPlayTLEvent __RPC_FAR *( STDMETHODCALLTYPE __RPC_FAR *GetPreviousEvent )( 
            IPlayTLEventPrivate __RPC_FAR * This);
        
        HRESULT ( __stdcall __RPC_FAR *SetUserDWORD )( 
            IPlayTLEventPrivate __RPC_FAR * This,
            DWORD dwUserDWORD);
        
        DWORD ( __stdcall __RPC_FAR *GetUserDWORD )( 
            IPlayTLEventPrivate __RPC_FAR * This);
        
        IPlayTLEvent __RPC_FAR *( STDMETHODCALLTYPE __RPC_FAR *GetParentEvent )( 
            IPlayTLEventPrivate __RPC_FAR * This);
        
        IPlayTLEvent __RPC_FAR *( STDMETHODCALLTYPE __RPC_FAR *GetChildEvent )( 
            IPlayTLEventPrivate __RPC_FAR * This,
            long lIndex);
        
        IPlayTLEvent __RPC_FAR *( STDMETHODCALLTYPE __RPC_FAR *GetFirstEventNextLevel )( 
            IPlayTLEventPrivate __RPC_FAR * This);
        
        IPlayTLEvent __RPC_FAR *( STDMETHODCALLTYPE __RPC_FAR *GetFirstEventPreviousLevel )( 
            IPlayTLEventPrivate __RPC_FAR * This);
        
        IPlayTLEvent __RPC_FAR *( STDMETHODCALLTYPE __RPC_FAR *GetNextEventSameLevel )( 
            IPlayTLEventPrivate __RPC_FAR * This);
        
        IPlayTLEvent __RPC_FAR *( STDMETHODCALLTYPE __RPC_FAR *GetPreviousEventSameLevel )( 
            IPlayTLEventPrivate __RPC_FAR * This);
        
        long ( STDMETHODCALLTYPE __RPC_FAR *GetChildLevel )( 
            IPlayTLEventPrivate __RPC_FAR * This);
        
        HRESULT ( __stdcall __RPC_FAR *SetChildEvent )( 
            IPlayTLEventPrivate __RPC_FAR * This,
            IPlayTLEvent __RPC_FAR *pChildEvent,
            long lIndex,
            DWORD dwFlag);
        
        DWORD ( STDMETHODCALLTYPE __RPC_FAR *GetGroupID )( 
            IPlayTLEventPrivate __RPC_FAR * This);
        
        IPlayTLEvent __RPC_FAR *( STDMETHODCALLTYPE __RPC_FAR *GetPreviousGroupMember )( 
            IPlayTLEventPrivate __RPC_FAR * This);
        
        IPlayTLEvent __RPC_FAR *( STDMETHODCALLTYPE __RPC_FAR *GetNextGroupMember )( 
            IPlayTLEventPrivate __RPC_FAR * This);
        
        DWORD ( STDMETHODCALLTYPE __RPC_FAR *GetSourceIn )( 
            IPlayTLEventPrivate __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetSourceIn )( 
            IPlayTLEventPrivate __RPC_FAR * This,
            DWORD dwTime);
        
        IPlayTLEvent __RPC_FAR *( STDMETHODCALLTYPE __RPC_FAR *GetFirstChildEvent )( 
            IPlayTLEventPrivate __RPC_FAR * This);
        
        void ( STDMETHODCALLTYPE __RPC_FAR *DieChildrenDie )( 
            IPlayTLEventPrivate __RPC_FAR * This,
            BOOL bDoYouMeanIt);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetGroup )( 
            IPlayTLEventPrivate __RPC_FAR * This,
            DWORD dwGroupID);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetPicon )( 
            IPlayTLEventPrivate __RPC_FAR * This,
            IGXIntBitmap __RPC_FAR *picture);
        
        IGXIntBitmap __RPC_FAR *( STDMETHODCALLTYPE __RPC_FAR *GetPicon )( 
            IPlayTLEventPrivate __RPC_FAR * This);
        
        BOOL ( STDMETHODCALLTYPE __RPC_FAR *GetClipRoll )( 
            IPlayTLEventPrivate __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetClipRoll )( 
            IPlayTLEventPrivate __RPC_FAR * This,
            BOOL bOn);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *EnableStartHandle )( 
            IPlayTLEventPrivate __RPC_FAR * This,
            BOOL bOn);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *EnableEndHandle )( 
            IPlayTLEventPrivate __RPC_FAR * This,
            BOOL bOn);
        
        BOOL ( STDMETHODCALLTYPE __RPC_FAR *IsStartHandleEnabled )( 
            IPlayTLEventPrivate __RPC_FAR * This);
        
        BOOL ( STDMETHODCALLTYPE __RPC_FAR *IsEndHandleEnabled )( 
            IPlayTLEventPrivate __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetLabel )( 
            IPlayTLEventPrivate __RPC_FAR * This,
            LPSTR pszLabel);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetLabel )( 
            IPlayTLEventPrivate __RPC_FAR * This,
            LPSTR pszLabel,
            DWORD cbBuffer);
        
        IPlayTLEvent __RPC_FAR *( __stdcall __RPC_FAR *Clone )( 
            IPlayTLEventPrivate __RPC_FAR * This);
        
        HRESULT ( __stdcall __RPC_FAR *SetNextEvent )( 
            IPlayTLEventPrivate __RPC_FAR * This,
            IPlayTLEvent __RPC_FAR *pEvent);
        
        HRESULT ( __stdcall __RPC_FAR *SetPreviousEvent )( 
            IPlayTLEventPrivate __RPC_FAR * This,
            IPlayTLEvent __RPC_FAR *pEvent);
        
        HRESULT ( __stdcall __RPC_FAR *SetTrack )( 
            IPlayTLEventPrivate __RPC_FAR * This,
            IPlayTLTrack __RPC_FAR *pTrack);
        
        HRESULT ( __stdcall __RPC_FAR *SetParentEvent )( 
            IPlayTLEventPrivate __RPC_FAR * This,
            IPlayTLEvent __RPC_FAR *pParentEvent);
        
        HRESULT ( __stdcall __RPC_FAR *SetFirstEventNextLevel )( 
            IPlayTLEventPrivate __RPC_FAR * This,
            IPlayTLEvent __RPC_FAR *pFirstEvent);
        
        HRESULT ( __stdcall __RPC_FAR *SetFirstEventPreviousLevel )( 
            IPlayTLEventPrivate __RPC_FAR * This,
            IPlayTLEvent __RPC_FAR *pFirstEvent);
        
        HRESULT ( __stdcall __RPC_FAR *SetNextEventSameLevel )( 
            IPlayTLEventPrivate __RPC_FAR * This,
            IPlayTLEvent __RPC_FAR *pNextEvent);
        
        HRESULT ( __stdcall __RPC_FAR *SetPreviousEventSameLevel )( 
            IPlayTLEventPrivate __RPC_FAR * This,
            IPlayTLEvent __RPC_FAR *pPrevEvent);
        
        HRESULT ( __stdcall __RPC_FAR *SetChildLevel )( 
            IPlayTLEventPrivate __RPC_FAR * This,
            long lLevel);
        
        HRESULT ( __stdcall __RPC_FAR *SetFirstChildEvent )( 
            IPlayTLEventPrivate __RPC_FAR * This,
            IPlayTLEvent __RPC_FAR *pChildEvent);
        
        HRESULT ( __stdcall __RPC_FAR *SetNextGroupMember )( 
            IPlayTLEventPrivate __RPC_FAR * This,
            IPlayTLEvent __RPC_FAR *pEvent);
        
        HRESULT ( __stdcall __RPC_FAR *SetPreviousGroupMember )( 
            IPlayTLEventPrivate __RPC_FAR * This,
            IPlayTLEvent __RPC_FAR *pEvent);
        
        HRESULT ( __stdcall __RPC_FAR *SetGroupID )( 
            IPlayTLEventPrivate __RPC_FAR * This,
            DWORD dwGroupID);
        
        HRESULT ( __stdcall __RPC_FAR *SetID )( 
            IPlayTLEventPrivate __RPC_FAR * This,
            DWORD dwId);
        
        HRESULT ( __stdcall __RPC_FAR *HookUpLinks )( 
            IPlayTLEventPrivate __RPC_FAR * This,
            IPlayTimeLine __RPC_FAR *pTimeLine);
        
        END_INTERFACE
    } IPlayTLEventPrivateVtbl;

    interface IPlayTLEventPrivate
    {
        CONST_VTBL struct IPlayTLEventPrivateVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IPlayTLEventPrivate_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IPlayTLEventPrivate_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IPlayTLEventPrivate_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IPlayTLEventPrivate_GetID(This)	\
    (This)->lpVtbl -> GetID(This)

#define IPlayTLEventPrivate_GetAppData(This,ppData,pNumBytes)	\
    (This)->lpVtbl -> GetAppData(This,ppData,pNumBytes)

#define IPlayTLEventPrivate_SetAppData(This,pData,numBytes)	\
    (This)->lpVtbl -> SetAppData(This,pData,numBytes)

#define IPlayTLEventPrivate_GetAppObject(This)	\
    (This)->lpVtbl -> GetAppObject(This)

#define IPlayTLEventPrivate_SetAppObject(This,pObject)	\
    (This)->lpVtbl -> SetAppObject(This,pObject)


#define IPlayTLEventPrivate_GetStartTime(This)	\
    (This)->lpVtbl -> GetStartTime(This)

#define IPlayTLEventPrivate_SetStartTime(This,dwTime)	\
    (This)->lpVtbl -> SetStartTime(This,dwTime)

#define IPlayTLEventPrivate_GetEndTime(This)	\
    (This)->lpVtbl -> GetEndTime(This)

#define IPlayTLEventPrivate_SetEndTime(This,dwTime)	\
    (This)->lpVtbl -> SetEndTime(This,dwTime)

#define IPlayTLEventPrivate_GetLength(This)	\
    (This)->lpVtbl -> GetLength(This)

#define IPlayTLEventPrivate_SetLength(This,dwTime)	\
    (This)->lpVtbl -> SetLength(This,dwTime)

#define IPlayTLEventPrivate_GetEventType(This)	\
    (This)->lpVtbl -> GetEventType(This)

#define IPlayTLEventPrivate_SetColor(This,dwColor)	\
    (This)->lpVtbl -> SetColor(This,dwColor)

#define IPlayTLEventPrivate_GetColor(This)	\
    (This)->lpVtbl -> GetColor(This)

#define IPlayTLEventPrivate_GetTrack(This)	\
    (This)->lpVtbl -> GetTrack(This)

#define IPlayTLEventPrivate_GetNextEvent(This)	\
    (This)->lpVtbl -> GetNextEvent(This)

#define IPlayTLEventPrivate_GetPreviousEvent(This)	\
    (This)->lpVtbl -> GetPreviousEvent(This)

#define IPlayTLEventPrivate_SetUserDWORD(This,dwUserDWORD)	\
    (This)->lpVtbl -> SetUserDWORD(This,dwUserDWORD)

#define IPlayTLEventPrivate_GetUserDWORD(This)	\
    (This)->lpVtbl -> GetUserDWORD(This)

#define IPlayTLEventPrivate_GetParentEvent(This)	\
    (This)->lpVtbl -> GetParentEvent(This)

#define IPlayTLEventPrivate_GetChildEvent(This,lIndex)	\
    (This)->lpVtbl -> GetChildEvent(This,lIndex)

#define IPlayTLEventPrivate_GetFirstEventNextLevel(This)	\
    (This)->lpVtbl -> GetFirstEventNextLevel(This)

#define IPlayTLEventPrivate_GetFirstEventPreviousLevel(This)	\
    (This)->lpVtbl -> GetFirstEventPreviousLevel(This)

#define IPlayTLEventPrivate_GetNextEventSameLevel(This)	\
    (This)->lpVtbl -> GetNextEventSameLevel(This)

#define IPlayTLEventPrivate_GetPreviousEventSameLevel(This)	\
    (This)->lpVtbl -> GetPreviousEventSameLevel(This)

#define IPlayTLEventPrivate_GetChildLevel(This)	\
    (This)->lpVtbl -> GetChildLevel(This)

#define IPlayTLEventPrivate_SetChildEvent(This,pChildEvent,lIndex,dwFlag)	\
    (This)->lpVtbl -> SetChildEvent(This,pChildEvent,lIndex,dwFlag)

#define IPlayTLEventPrivate_GetGroupID(This)	\
    (This)->lpVtbl -> GetGroupID(This)

#define IPlayTLEventPrivate_GetPreviousGroupMember(This)	\
    (This)->lpVtbl -> GetPreviousGroupMember(This)

#define IPlayTLEventPrivate_GetNextGroupMember(This)	\
    (This)->lpVtbl -> GetNextGroupMember(This)

#define IPlayTLEventPrivate_GetSourceIn(This)	\
    (This)->lpVtbl -> GetSourceIn(This)

#define IPlayTLEventPrivate_SetSourceIn(This,dwTime)	\
    (This)->lpVtbl -> SetSourceIn(This,dwTime)

#define IPlayTLEventPrivate_GetFirstChildEvent(This)	\
    (This)->lpVtbl -> GetFirstChildEvent(This)

#define IPlayTLEventPrivate_DieChildrenDie(This,bDoYouMeanIt)	\
    (This)->lpVtbl -> DieChildrenDie(This,bDoYouMeanIt)

#define IPlayTLEventPrivate_SetGroup(This,dwGroupID)	\
    (This)->lpVtbl -> SetGroup(This,dwGroupID)

#define IPlayTLEventPrivate_SetPicon(This,picture)	\
    (This)->lpVtbl -> SetPicon(This,picture)

#define IPlayTLEventPrivate_GetPicon(This)	\
    (This)->lpVtbl -> GetPicon(This)

#define IPlayTLEventPrivate_GetClipRoll(This)	\
    (This)->lpVtbl -> GetClipRoll(This)

#define IPlayTLEventPrivate_SetClipRoll(This,bOn)	\
    (This)->lpVtbl -> SetClipRoll(This,bOn)

#define IPlayTLEventPrivate_EnableStartHandle(This,bOn)	\
    (This)->lpVtbl -> EnableStartHandle(This,bOn)

#define IPlayTLEventPrivate_EnableEndHandle(This,bOn)	\
    (This)->lpVtbl -> EnableEndHandle(This,bOn)

#define IPlayTLEventPrivate_IsStartHandleEnabled(This)	\
    (This)->lpVtbl -> IsStartHandleEnabled(This)

#define IPlayTLEventPrivate_IsEndHandleEnabled(This)	\
    (This)->lpVtbl -> IsEndHandleEnabled(This)

#define IPlayTLEventPrivate_SetLabel(This,pszLabel)	\
    (This)->lpVtbl -> SetLabel(This,pszLabel)

#define IPlayTLEventPrivate_GetLabel(This,pszLabel,cbBuffer)	\
    (This)->lpVtbl -> GetLabel(This,pszLabel,cbBuffer)

#define IPlayTLEventPrivate_Clone(This)	\
    (This)->lpVtbl -> Clone(This)


#define IPlayTLEventPrivate_SetNextEvent(This,pEvent)	\
    (This)->lpVtbl -> SetNextEvent(This,pEvent)

#define IPlayTLEventPrivate_SetPreviousEvent(This,pEvent)	\
    (This)->lpVtbl -> SetPreviousEvent(This,pEvent)

#define IPlayTLEventPrivate_SetTrack(This,pTrack)	\
    (This)->lpVtbl -> SetTrack(This,pTrack)

#define IPlayTLEventPrivate_SetParentEvent(This,pParentEvent)	\
    (This)->lpVtbl -> SetParentEvent(This,pParentEvent)

#define IPlayTLEventPrivate_SetFirstEventNextLevel(This,pFirstEvent)	\
    (This)->lpVtbl -> SetFirstEventNextLevel(This,pFirstEvent)

#define IPlayTLEventPrivate_SetFirstEventPreviousLevel(This,pFirstEvent)	\
    (This)->lpVtbl -> SetFirstEventPreviousLevel(This,pFirstEvent)

#define IPlayTLEventPrivate_SetNextEventSameLevel(This,pNextEvent)	\
    (This)->lpVtbl -> SetNextEventSameLevel(This,pNextEvent)

#define IPlayTLEventPrivate_SetPreviousEventSameLevel(This,pPrevEvent)	\
    (This)->lpVtbl -> SetPreviousEventSameLevel(This,pPrevEvent)

#define IPlayTLEventPrivate_SetChildLevel(This,lLevel)	\
    (This)->lpVtbl -> SetChildLevel(This,lLevel)

#define IPlayTLEventPrivate_SetFirstChildEvent(This,pChildEvent)	\
    (This)->lpVtbl -> SetFirstChildEvent(This,pChildEvent)

#define IPlayTLEventPrivate_SetNextGroupMember(This,pEvent)	\
    (This)->lpVtbl -> SetNextGroupMember(This,pEvent)

#define IPlayTLEventPrivate_SetPreviousGroupMember(This,pEvent)	\
    (This)->lpVtbl -> SetPreviousGroupMember(This,pEvent)

#define IPlayTLEventPrivate_SetGroupID(This,dwGroupID)	\
    (This)->lpVtbl -> SetGroupID(This,dwGroupID)

#define IPlayTLEventPrivate_SetID(This,dwId)	\
    (This)->lpVtbl -> SetID(This,dwId)

#define IPlayTLEventPrivate_HookUpLinks(This,pTimeLine)	\
    (This)->lpVtbl -> HookUpLinks(This,pTimeLine)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT __stdcall IPlayTLEventPrivate_SetNextEvent_Proxy( 
    IPlayTLEventPrivate __RPC_FAR * This,
    IPlayTLEvent __RPC_FAR *pEvent);


void __RPC_STUB IPlayTLEventPrivate_SetNextEvent_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT __stdcall IPlayTLEventPrivate_SetPreviousEvent_Proxy( 
    IPlayTLEventPrivate __RPC_FAR * This,
    IPlayTLEvent __RPC_FAR *pEvent);


void __RPC_STUB IPlayTLEventPrivate_SetPreviousEvent_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT __stdcall IPlayTLEventPrivate_SetTrack_Proxy( 
    IPlayTLEventPrivate __RPC_FAR * This,
    IPlayTLTrack __RPC_FAR *pTrack);


void __RPC_STUB IPlayTLEventPrivate_SetTrack_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT __stdcall IPlayTLEventPrivate_SetParentEvent_Proxy( 
    IPlayTLEventPrivate __RPC_FAR * This,
    IPlayTLEvent __RPC_FAR *pParentEvent);


void __RPC_STUB IPlayTLEventPrivate_SetParentEvent_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT __stdcall IPlayTLEventPrivate_SetFirstEventNextLevel_Proxy( 
    IPlayTLEventPrivate __RPC_FAR * This,
    IPlayTLEvent __RPC_FAR *pFirstEvent);


void __RPC_STUB IPlayTLEventPrivate_SetFirstEventNextLevel_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT __stdcall IPlayTLEventPrivate_SetFirstEventPreviousLevel_Proxy( 
    IPlayTLEventPrivate __RPC_FAR * This,
    IPlayTLEvent __RPC_FAR *pFirstEvent);


void __RPC_STUB IPlayTLEventPrivate_SetFirstEventPreviousLevel_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT __stdcall IPlayTLEventPrivate_SetNextEventSameLevel_Proxy( 
    IPlayTLEventPrivate __RPC_FAR * This,
    IPlayTLEvent __RPC_FAR *pNextEvent);


void __RPC_STUB IPlayTLEventPrivate_SetNextEventSameLevel_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT __stdcall IPlayTLEventPrivate_SetPreviousEventSameLevel_Proxy( 
    IPlayTLEventPrivate __RPC_FAR * This,
    IPlayTLEvent __RPC_FAR *pPrevEvent);


void __RPC_STUB IPlayTLEventPrivate_SetPreviousEventSameLevel_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT __stdcall IPlayTLEventPrivate_SetChildLevel_Proxy( 
    IPlayTLEventPrivate __RPC_FAR * This,
    long lLevel);


void __RPC_STUB IPlayTLEventPrivate_SetChildLevel_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT __stdcall IPlayTLEventPrivate_SetFirstChildEvent_Proxy( 
    IPlayTLEventPrivate __RPC_FAR * This,
    IPlayTLEvent __RPC_FAR *pChildEvent);


void __RPC_STUB IPlayTLEventPrivate_SetFirstChildEvent_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT __stdcall IPlayTLEventPrivate_SetNextGroupMember_Proxy( 
    IPlayTLEventPrivate __RPC_FAR * This,
    IPlayTLEvent __RPC_FAR *pEvent);


void __RPC_STUB IPlayTLEventPrivate_SetNextGroupMember_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT __stdcall IPlayTLEventPrivate_SetPreviousGroupMember_Proxy( 
    IPlayTLEventPrivate __RPC_FAR * This,
    IPlayTLEvent __RPC_FAR *pEvent);


void __RPC_STUB IPlayTLEventPrivate_SetPreviousGroupMember_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT __stdcall IPlayTLEventPrivate_SetGroupID_Proxy( 
    IPlayTLEventPrivate __RPC_FAR * This,
    DWORD dwGroupID);


void __RPC_STUB IPlayTLEventPrivate_SetGroupID_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT __stdcall IPlayTLEventPrivate_SetID_Proxy( 
    IPlayTLEventPrivate __RPC_FAR * This,
    DWORD dwId);


void __RPC_STUB IPlayTLEventPrivate_SetID_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT __stdcall IPlayTLEventPrivate_HookUpLinks_Proxy( 
    IPlayTLEventPrivate __RPC_FAR * This,
    IPlayTimeLine __RPC_FAR *pTimeLine);


void __RPC_STUB IPlayTLEventPrivate_HookUpLinks_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IPlayTLEventPrivate_INTERFACE_DEFINED__ */


/****************************************
 * Generated header for interface: __MIDL_itf_timeline_0126
 * at Tue Nov 23 05:02:07 1999
 * using MIDL 3.01.75
 ****************************************/
/* [local] */ 





extern RPC_IF_HANDLE __MIDL_itf_timeline_0126_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_timeline_0126_v0_0_s_ifspec;

#ifndef __IPlayTLAdviser_INTERFACE_DEFINED__
#define __IPlayTLAdviser_INTERFACE_DEFINED__

/****************************************
 * Generated header for interface: IPlayTLAdviser
 * at Tue Nov 23 05:02:07 1999
 * using MIDL 3.01.75
 ****************************************/
/* [local][uuid][object] */ 



EXTERN_C const IID IID_IPlayTLAdviser;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    interface DECLSPEC_UUID("8335e60d-ab3b-11ce-8468-0000b468276b")
    IPlayTLAdviser : public IUnknown
    {
    public:
        virtual HRESULT __stdcall OnEventSelect( 
            IPlayTimeLine __RPC_FAR *pTimeLine,
            IPlayTLEvent __RPC_FAR *pEvent) = 0;
        
        virtual HRESULT __stdcall OnEventDeSelect( 
            IPlayTimeLine __RPC_FAR *pTimeLine,
            IPlayTLEvent __RPC_FAR *pEvent) = 0;
        
        virtual HRESULT __stdcall OnPreEventAdd( 
            IPlayTimeLine __RPC_FAR *pTimeLine,
            IPlayTLTrack __RPC_FAR *pTrack,
            IPlayTLEvent __RPC_FAR *pEvent) = 0;
        
        virtual HRESULT __stdcall OnPostEventAdd( 
            IPlayTimeLine __RPC_FAR *pTimeLine,
            IPlayTLTrack __RPC_FAR *pTrack,
            IPlayTLEvent __RPC_FAR *pEvent) = 0;
        
        virtual HRESULT __stdcall OnPreEventRemove( 
            IPlayTimeLine __RPC_FAR *pTimeLine,
            IPlayTLTrack __RPC_FAR *pTrack,
            IPlayTLEvent __RPC_FAR *pEvent) = 0;
        
        virtual HRESULT __stdcall OnPostEventRemove( 
            IPlayTimeLine __RPC_FAR *pTimeLine,
            IPlayTLTrack __RPC_FAR *pTrack,
            IPlayTLEvent __RPC_FAR *pEvent) = 0;
        
        virtual HRESULT __stdcall OnFileDrop( 
            IPlayTimeLine __RPC_FAR *pTimeLine,
            IPlayTLTrack __RPC_FAR *pTrack,
            DWORD dwTime,
            LPSTR pFileName) = 0;
        
        virtual HRESULT __stdcall OnPreEventMove( 
            IPlayTimeLine __RPC_FAR *pTimeLine,
            IPlayTLTrack __RPC_FAR *pTrack,
            IPlayTLEvent __RPC_FAR *pEvent,
            DWORD dwNewStartTime,
            BOOL bRipple,
            DWORD dwFirstTime) = 0;
        
        virtual HRESULT __stdcall OnEventMoving( 
            IPlayTimeLine __RPC_FAR *pTimeLine,
            IPlayTLTrack __RPC_FAR *pTrack,
            IPlayTLEvent __RPC_FAR *pEvent,
            DWORD dwNewStartTime,
            BOOL bRipple,
            DWORD dwFirstTime) = 0;
        
        virtual HRESULT __stdcall OnPostEventMove( 
            IPlayTimeLine __RPC_FAR *pTimeLine,
            IPlayTLTrack __RPC_FAR *pTrack,
            IPlayTLEvent __RPC_FAR *pEvent,
            DWORD dwNewStartTime,
            BOOL bRipple,
            DWORD dwFirstTime) = 0;
        
        virtual HRESULT __stdcall OnPrePositionBarMove( 
            IPlayTimeLine __RPC_FAR *pTimeLine,
            DWORD dwCurrentTime) = 0;
        
        virtual HRESULT __stdcall OnPositionBarMoving( 
            IPlayTimeLine __RPC_FAR *pTimeLine,
            DWORD dwCurrentTime) = 0;
        
        virtual HRESULT __stdcall OnPostPositionBarMove( 
            IPlayTimeLine __RPC_FAR *pTimeLine,
            DWORD dwCurrentTime) = 0;
        
        virtual HRESULT __stdcall OnPreEventSizeStart( 
            IPlayTimeLine __RPC_FAR *pTimeLine,
            IPlayTLTrack __RPC_FAR *pTrack,
            IPlayTLEvent __RPC_FAR *pEvent,
            DWORD dwNewStartTime) = 0;
        
        virtual HRESULT __stdcall OnPreEventSizeEnd( 
            IPlayTimeLine __RPC_FAR *pTimeLine,
            IPlayTLTrack __RPC_FAR *pTrack,
            IPlayTLEvent __RPC_FAR *pEvent,
            DWORD dwNewEndTime) = 0;
        
        virtual HRESULT __stdcall OnPostEventSize( 
            IPlayTimeLine __RPC_FAR *pTimeLine,
            IPlayTLTrack __RPC_FAR *pTrack,
            IPlayTLEvent __RPC_FAR *pEvent,
            DWORD dwNewLength) = 0;
        
        virtual HRESULT __stdcall OnPopupMenu( 
            IPlayPopup __RPC_FAR *pPopup,
            IPlayTimeLine __RPC_FAR *pTimeLine,
            IPlayTLTrack __RPC_FAR *pTrack,
            IPlayTLEvent __RPC_FAR *pEvent,
            DWORD dwTime) = 0;
        
        virtual IPlayTLTrack __RPC_FAR *STDMETHODCALLTYPE OnEventSwitchTrack( 
            IPlayTimeLine __RPC_FAR *pTimeLine,
            IPlayTLTrack __RPC_FAR *pNewTrack,
            IPlayTLEvent __RPC_FAR *pEvent) = 0;
        
        virtual HRESULT __stdcall OnPreSetSourceIn( 
            IPlayTimeLine __RPC_FAR *pTimeLine,
            IPlayTLEvent __RPC_FAR *pEvent,
            DWORD dwNewSourceIn) = 0;
        
        virtual HRESULT __stdcall OnPostSetSourceIn( 
            IPlayTimeLine __RPC_FAR *pTimeLine,
            IPlayTLEvent __RPC_FAR *pEvent,
            DWORD dwNewSourceIn) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE OnPreEventValueChange( 
            IPlayTimeLine __RPC_FAR *pTimeLine,
            IPlayTLTrack __RPC_FAR *pTrack,
            IPlayTLEvent __RPC_FAR *pEvent,
            double dwNewValue) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE OnEventValueChanging( 
            IPlayTimeLine __RPC_FAR *pTimeLine,
            IPlayTLTrack __RPC_FAR *pTrack,
            IPlayTLEvent __RPC_FAR *pEvent,
            double dwNewValue) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE OnPostEventValueChange( 
            IPlayTimeLine __RPC_FAR *pTimeLine,
            IPlayTLTrack __RPC_FAR *pTrack,
            IPlayTLEvent __RPC_FAR *pEvent,
            double dwNewValue) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE OnEventValueDisplay( 
            IPlayTimeLine __RPC_FAR *pTimeLine,
            IPlayTLTrack __RPC_FAR *pTrack,
            IPlayTLEvent __RPC_FAR *pEvent,
            double dNewValue,
            LPSTR pszOutput,
            long numBytes) = 0;
        
        virtual HRESULT __stdcall OnPaste( 
            IPlayTimeLine __RPC_FAR *pTimeLine,
            IPlayTLTrack __RPC_FAR *pTrack,
            IPlayTLEvent __RPC_FAR *pEvent) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IPlayTLAdviserVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            IPlayTLAdviser __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            IPlayTLAdviser __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            IPlayTLAdviser __RPC_FAR * This);
        
        HRESULT ( __stdcall __RPC_FAR *OnEventSelect )( 
            IPlayTLAdviser __RPC_FAR * This,
            IPlayTimeLine __RPC_FAR *pTimeLine,
            IPlayTLEvent __RPC_FAR *pEvent);
        
        HRESULT ( __stdcall __RPC_FAR *OnEventDeSelect )( 
            IPlayTLAdviser __RPC_FAR * This,
            IPlayTimeLine __RPC_FAR *pTimeLine,
            IPlayTLEvent __RPC_FAR *pEvent);
        
        HRESULT ( __stdcall __RPC_FAR *OnPreEventAdd )( 
            IPlayTLAdviser __RPC_FAR * This,
            IPlayTimeLine __RPC_FAR *pTimeLine,
            IPlayTLTrack __RPC_FAR *pTrack,
            IPlayTLEvent __RPC_FAR *pEvent);
        
        HRESULT ( __stdcall __RPC_FAR *OnPostEventAdd )( 
            IPlayTLAdviser __RPC_FAR * This,
            IPlayTimeLine __RPC_FAR *pTimeLine,
            IPlayTLTrack __RPC_FAR *pTrack,
            IPlayTLEvent __RPC_FAR *pEvent);
        
        HRESULT ( __stdcall __RPC_FAR *OnPreEventRemove )( 
            IPlayTLAdviser __RPC_FAR * This,
            IPlayTimeLine __RPC_FAR *pTimeLine,
            IPlayTLTrack __RPC_FAR *pTrack,
            IPlayTLEvent __RPC_FAR *pEvent);
        
        HRESULT ( __stdcall __RPC_FAR *OnPostEventRemove )( 
            IPlayTLAdviser __RPC_FAR * This,
            IPlayTimeLine __RPC_FAR *pTimeLine,
            IPlayTLTrack __RPC_FAR *pTrack,
            IPlayTLEvent __RPC_FAR *pEvent);
        
        HRESULT ( __stdcall __RPC_FAR *OnFileDrop )( 
            IPlayTLAdviser __RPC_FAR * This,
            IPlayTimeLine __RPC_FAR *pTimeLine,
            IPlayTLTrack __RPC_FAR *pTrack,
            DWORD dwTime,
            LPSTR pFileName);
        
        HRESULT ( __stdcall __RPC_FAR *OnPreEventMove )( 
            IPlayTLAdviser __RPC_FAR * This,
            IPlayTimeLine __RPC_FAR *pTimeLine,
            IPlayTLTrack __RPC_FAR *pTrack,
            IPlayTLEvent __RPC_FAR *pEvent,
            DWORD dwNewStartTime,
            BOOL bRipple,
            DWORD dwFirstTime);
        
        HRESULT ( __stdcall __RPC_FAR *OnEventMoving )( 
            IPlayTLAdviser __RPC_FAR * This,
            IPlayTimeLine __RPC_FAR *pTimeLine,
            IPlayTLTrack __RPC_FAR *pTrack,
            IPlayTLEvent __RPC_FAR *pEvent,
            DWORD dwNewStartTime,
            BOOL bRipple,
            DWORD dwFirstTime);
        
        HRESULT ( __stdcall __RPC_FAR *OnPostEventMove )( 
            IPlayTLAdviser __RPC_FAR * This,
            IPlayTimeLine __RPC_FAR *pTimeLine,
            IPlayTLTrack __RPC_FAR *pTrack,
            IPlayTLEvent __RPC_FAR *pEvent,
            DWORD dwNewStartTime,
            BOOL bRipple,
            DWORD dwFirstTime);
        
        HRESULT ( __stdcall __RPC_FAR *OnPrePositionBarMove )( 
            IPlayTLAdviser __RPC_FAR * This,
            IPlayTimeLine __RPC_FAR *pTimeLine,
            DWORD dwCurrentTime);
        
        HRESULT ( __stdcall __RPC_FAR *OnPositionBarMoving )( 
            IPlayTLAdviser __RPC_FAR * This,
            IPlayTimeLine __RPC_FAR *pTimeLine,
            DWORD dwCurrentTime);
        
        HRESULT ( __stdcall __RPC_FAR *OnPostPositionBarMove )( 
            IPlayTLAdviser __RPC_FAR * This,
            IPlayTimeLine __RPC_FAR *pTimeLine,
            DWORD dwCurrentTime);
        
        HRESULT ( __stdcall __RPC_FAR *OnPreEventSizeStart )( 
            IPlayTLAdviser __RPC_FAR * This,
            IPlayTimeLine __RPC_FAR *pTimeLine,
            IPlayTLTrack __RPC_FAR *pTrack,
            IPlayTLEvent __RPC_FAR *pEvent,
            DWORD dwNewStartTime);
        
        HRESULT ( __stdcall __RPC_FAR *OnPreEventSizeEnd )( 
            IPlayTLAdviser __RPC_FAR * This,
            IPlayTimeLine __RPC_FAR *pTimeLine,
            IPlayTLTrack __RPC_FAR *pTrack,
            IPlayTLEvent __RPC_FAR *pEvent,
            DWORD dwNewEndTime);
        
        HRESULT ( __stdcall __RPC_FAR *OnPostEventSize )( 
            IPlayTLAdviser __RPC_FAR * This,
            IPlayTimeLine __RPC_FAR *pTimeLine,
            IPlayTLTrack __RPC_FAR *pTrack,
            IPlayTLEvent __RPC_FAR *pEvent,
            DWORD dwNewLength);
        
        HRESULT ( __stdcall __RPC_FAR *OnPopupMenu )( 
            IPlayTLAdviser __RPC_FAR * This,
            IPlayPopup __RPC_FAR *pPopup,
            IPlayTimeLine __RPC_FAR *pTimeLine,
            IPlayTLTrack __RPC_FAR *pTrack,
            IPlayTLEvent __RPC_FAR *pEvent,
            DWORD dwTime);
        
        IPlayTLTrack __RPC_FAR *( STDMETHODCALLTYPE __RPC_FAR *OnEventSwitchTrack )( 
            IPlayTLAdviser __RPC_FAR * This,
            IPlayTimeLine __RPC_FAR *pTimeLine,
            IPlayTLTrack __RPC_FAR *pNewTrack,
            IPlayTLEvent __RPC_FAR *pEvent);
        
        HRESULT ( __stdcall __RPC_FAR *OnPreSetSourceIn )( 
            IPlayTLAdviser __RPC_FAR * This,
            IPlayTimeLine __RPC_FAR *pTimeLine,
            IPlayTLEvent __RPC_FAR *pEvent,
            DWORD dwNewSourceIn);
        
        HRESULT ( __stdcall __RPC_FAR *OnPostSetSourceIn )( 
            IPlayTLAdviser __RPC_FAR * This,
            IPlayTimeLine __RPC_FAR *pTimeLine,
            IPlayTLEvent __RPC_FAR *pEvent,
            DWORD dwNewSourceIn);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *OnPreEventValueChange )( 
            IPlayTLAdviser __RPC_FAR * This,
            IPlayTimeLine __RPC_FAR *pTimeLine,
            IPlayTLTrack __RPC_FAR *pTrack,
            IPlayTLEvent __RPC_FAR *pEvent,
            double dwNewValue);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *OnEventValueChanging )( 
            IPlayTLAdviser __RPC_FAR * This,
            IPlayTimeLine __RPC_FAR *pTimeLine,
            IPlayTLTrack __RPC_FAR *pTrack,
            IPlayTLEvent __RPC_FAR *pEvent,
            double dwNewValue);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *OnPostEventValueChange )( 
            IPlayTLAdviser __RPC_FAR * This,
            IPlayTimeLine __RPC_FAR *pTimeLine,
            IPlayTLTrack __RPC_FAR *pTrack,
            IPlayTLEvent __RPC_FAR *pEvent,
            double dwNewValue);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *OnEventValueDisplay )( 
            IPlayTLAdviser __RPC_FAR * This,
            IPlayTimeLine __RPC_FAR *pTimeLine,
            IPlayTLTrack __RPC_FAR *pTrack,
            IPlayTLEvent __RPC_FAR *pEvent,
            double dNewValue,
            LPSTR pszOutput,
            long numBytes);
        
        HRESULT ( __stdcall __RPC_FAR *OnPaste )( 
            IPlayTLAdviser __RPC_FAR * This,
            IPlayTimeLine __RPC_FAR *pTimeLine,
            IPlayTLTrack __RPC_FAR *pTrack,
            IPlayTLEvent __RPC_FAR *pEvent);
        
        END_INTERFACE
    } IPlayTLAdviserVtbl;

    interface IPlayTLAdviser
    {
        CONST_VTBL struct IPlayTLAdviserVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IPlayTLAdviser_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IPlayTLAdviser_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IPlayTLAdviser_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IPlayTLAdviser_OnEventSelect(This,pTimeLine,pEvent)	\
    (This)->lpVtbl -> OnEventSelect(This,pTimeLine,pEvent)

#define IPlayTLAdviser_OnEventDeSelect(This,pTimeLine,pEvent)	\
    (This)->lpVtbl -> OnEventDeSelect(This,pTimeLine,pEvent)

#define IPlayTLAdviser_OnPreEventAdd(This,pTimeLine,pTrack,pEvent)	\
    (This)->lpVtbl -> OnPreEventAdd(This,pTimeLine,pTrack,pEvent)

#define IPlayTLAdviser_OnPostEventAdd(This,pTimeLine,pTrack,pEvent)	\
    (This)->lpVtbl -> OnPostEventAdd(This,pTimeLine,pTrack,pEvent)

#define IPlayTLAdviser_OnPreEventRemove(This,pTimeLine,pTrack,pEvent)	\
    (This)->lpVtbl -> OnPreEventRemove(This,pTimeLine,pTrack,pEvent)

#define IPlayTLAdviser_OnPostEventRemove(This,pTimeLine,pTrack,pEvent)	\
    (This)->lpVtbl -> OnPostEventRemove(This,pTimeLine,pTrack,pEvent)

#define IPlayTLAdviser_OnFileDrop(This,pTimeLine,pTrack,dwTime,pFileName)	\
    (This)->lpVtbl -> OnFileDrop(This,pTimeLine,pTrack,dwTime,pFileName)

#define IPlayTLAdviser_OnPreEventMove(This,pTimeLine,pTrack,pEvent,dwNewStartTime,bRipple,dwFirstTime)	\
    (This)->lpVtbl -> OnPreEventMove(This,pTimeLine,pTrack,pEvent,dwNewStartTime,bRipple,dwFirstTime)

#define IPlayTLAdviser_OnEventMoving(This,pTimeLine,pTrack,pEvent,dwNewStartTime,bRipple,dwFirstTime)	\
    (This)->lpVtbl -> OnEventMoving(This,pTimeLine,pTrack,pEvent,dwNewStartTime,bRipple,dwFirstTime)

#define IPlayTLAdviser_OnPostEventMove(This,pTimeLine,pTrack,pEvent,dwNewStartTime,bRipple,dwFirstTime)	\
    (This)->lpVtbl -> OnPostEventMove(This,pTimeLine,pTrack,pEvent,dwNewStartTime,bRipple,dwFirstTime)

#define IPlayTLAdviser_OnPrePositionBarMove(This,pTimeLine,dwCurrentTime)	\
    (This)->lpVtbl -> OnPrePositionBarMove(This,pTimeLine,dwCurrentTime)

#define IPlayTLAdviser_OnPositionBarMoving(This,pTimeLine,dwCurrentTime)	\
    (This)->lpVtbl -> OnPositionBarMoving(This,pTimeLine,dwCurrentTime)

#define IPlayTLAdviser_OnPostPositionBarMove(This,pTimeLine,dwCurrentTime)	\
    (This)->lpVtbl -> OnPostPositionBarMove(This,pTimeLine,dwCurrentTime)

#define IPlayTLAdviser_OnPreEventSizeStart(This,pTimeLine,pTrack,pEvent,dwNewStartTime)	\
    (This)->lpVtbl -> OnPreEventSizeStart(This,pTimeLine,pTrack,pEvent,dwNewStartTime)

#define IPlayTLAdviser_OnPreEventSizeEnd(This,pTimeLine,pTrack,pEvent,dwNewEndTime)	\
    (This)->lpVtbl -> OnPreEventSizeEnd(This,pTimeLine,pTrack,pEvent,dwNewEndTime)

#define IPlayTLAdviser_OnPostEventSize(This,pTimeLine,pTrack,pEvent,dwNewLength)	\
    (This)->lpVtbl -> OnPostEventSize(This,pTimeLine,pTrack,pEvent,dwNewLength)

#define IPlayTLAdviser_OnPopupMenu(This,pPopup,pTimeLine,pTrack,pEvent,dwTime)	\
    (This)->lpVtbl -> OnPopupMenu(This,pPopup,pTimeLine,pTrack,pEvent,dwTime)

#define IPlayTLAdviser_OnEventSwitchTrack(This,pTimeLine,pNewTrack,pEvent)	\
    (This)->lpVtbl -> OnEventSwitchTrack(This,pTimeLine,pNewTrack,pEvent)

#define IPlayTLAdviser_OnPreSetSourceIn(This,pTimeLine,pEvent,dwNewSourceIn)	\
    (This)->lpVtbl -> OnPreSetSourceIn(This,pTimeLine,pEvent,dwNewSourceIn)

#define IPlayTLAdviser_OnPostSetSourceIn(This,pTimeLine,pEvent,dwNewSourceIn)	\
    (This)->lpVtbl -> OnPostSetSourceIn(This,pTimeLine,pEvent,dwNewSourceIn)

#define IPlayTLAdviser_OnPreEventValueChange(This,pTimeLine,pTrack,pEvent,dwNewValue)	\
    (This)->lpVtbl -> OnPreEventValueChange(This,pTimeLine,pTrack,pEvent,dwNewValue)

#define IPlayTLAdviser_OnEventValueChanging(This,pTimeLine,pTrack,pEvent,dwNewValue)	\
    (This)->lpVtbl -> OnEventValueChanging(This,pTimeLine,pTrack,pEvent,dwNewValue)

#define IPlayTLAdviser_OnPostEventValueChange(This,pTimeLine,pTrack,pEvent,dwNewValue)	\
    (This)->lpVtbl -> OnPostEventValueChange(This,pTimeLine,pTrack,pEvent,dwNewValue)

#define IPlayTLAdviser_OnEventValueDisplay(This,pTimeLine,pTrack,pEvent,dNewValue,pszOutput,numBytes)	\
    (This)->lpVtbl -> OnEventValueDisplay(This,pTimeLine,pTrack,pEvent,dNewValue,pszOutput,numBytes)

#define IPlayTLAdviser_OnPaste(This,pTimeLine,pTrack,pEvent)	\
    (This)->lpVtbl -> OnPaste(This,pTimeLine,pTrack,pEvent)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT __stdcall IPlayTLAdviser_OnEventSelect_Proxy( 
    IPlayTLAdviser __RPC_FAR * This,
    IPlayTimeLine __RPC_FAR *pTimeLine,
    IPlayTLEvent __RPC_FAR *pEvent);


void __RPC_STUB IPlayTLAdviser_OnEventSelect_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT __stdcall IPlayTLAdviser_OnEventDeSelect_Proxy( 
    IPlayTLAdviser __RPC_FAR * This,
    IPlayTimeLine __RPC_FAR *pTimeLine,
    IPlayTLEvent __RPC_FAR *pEvent);


void __RPC_STUB IPlayTLAdviser_OnEventDeSelect_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT __stdcall IPlayTLAdviser_OnPreEventAdd_Proxy( 
    IPlayTLAdviser __RPC_FAR * This,
    IPlayTimeLine __RPC_FAR *pTimeLine,
    IPlayTLTrack __RPC_FAR *pTrack,
    IPlayTLEvent __RPC_FAR *pEvent);


void __RPC_STUB IPlayTLAdviser_OnPreEventAdd_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT __stdcall IPlayTLAdviser_OnPostEventAdd_Proxy( 
    IPlayTLAdviser __RPC_FAR * This,
    IPlayTimeLine __RPC_FAR *pTimeLine,
    IPlayTLTrack __RPC_FAR *pTrack,
    IPlayTLEvent __RPC_FAR *pEvent);


void __RPC_STUB IPlayTLAdviser_OnPostEventAdd_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT __stdcall IPlayTLAdviser_OnPreEventRemove_Proxy( 
    IPlayTLAdviser __RPC_FAR * This,
    IPlayTimeLine __RPC_FAR *pTimeLine,
    IPlayTLTrack __RPC_FAR *pTrack,
    IPlayTLEvent __RPC_FAR *pEvent);


void __RPC_STUB IPlayTLAdviser_OnPreEventRemove_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT __stdcall IPlayTLAdviser_OnPostEventRemove_Proxy( 
    IPlayTLAdviser __RPC_FAR * This,
    IPlayTimeLine __RPC_FAR *pTimeLine,
    IPlayTLTrack __RPC_FAR *pTrack,
    IPlayTLEvent __RPC_FAR *pEvent);


void __RPC_STUB IPlayTLAdviser_OnPostEventRemove_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT __stdcall IPlayTLAdviser_OnFileDrop_Proxy( 
    IPlayTLAdviser __RPC_FAR * This,
    IPlayTimeLine __RPC_FAR *pTimeLine,
    IPlayTLTrack __RPC_FAR *pTrack,
    DWORD dwTime,
    LPSTR pFileName);


void __RPC_STUB IPlayTLAdviser_OnFileDrop_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT __stdcall IPlayTLAdviser_OnPreEventMove_Proxy( 
    IPlayTLAdviser __RPC_FAR * This,
    IPlayTimeLine __RPC_FAR *pTimeLine,
    IPlayTLTrack __RPC_FAR *pTrack,
    IPlayTLEvent __RPC_FAR *pEvent,
    DWORD dwNewStartTime,
    BOOL bRipple,
    DWORD dwFirstTime);


void __RPC_STUB IPlayTLAdviser_OnPreEventMove_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT __stdcall IPlayTLAdviser_OnEventMoving_Proxy( 
    IPlayTLAdviser __RPC_FAR * This,
    IPlayTimeLine __RPC_FAR *pTimeLine,
    IPlayTLTrack __RPC_FAR *pTrack,
    IPlayTLEvent __RPC_FAR *pEvent,
    DWORD dwNewStartTime,
    BOOL bRipple,
    DWORD dwFirstTime);


void __RPC_STUB IPlayTLAdviser_OnEventMoving_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT __stdcall IPlayTLAdviser_OnPostEventMove_Proxy( 
    IPlayTLAdviser __RPC_FAR * This,
    IPlayTimeLine __RPC_FAR *pTimeLine,
    IPlayTLTrack __RPC_FAR *pTrack,
    IPlayTLEvent __RPC_FAR *pEvent,
    DWORD dwNewStartTime,
    BOOL bRipple,
    DWORD dwFirstTime);


void __RPC_STUB IPlayTLAdviser_OnPostEventMove_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT __stdcall IPlayTLAdviser_OnPrePositionBarMove_Proxy( 
    IPlayTLAdviser __RPC_FAR * This,
    IPlayTimeLine __RPC_FAR *pTimeLine,
    DWORD dwCurrentTime);


void __RPC_STUB IPlayTLAdviser_OnPrePositionBarMove_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT __stdcall IPlayTLAdviser_OnPositionBarMoving_Proxy( 
    IPlayTLAdviser __RPC_FAR * This,
    IPlayTimeLine __RPC_FAR *pTimeLine,
    DWORD dwCurrentTime);


void __RPC_STUB IPlayTLAdviser_OnPositionBarMoving_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT __stdcall IPlayTLAdviser_OnPostPositionBarMove_Proxy( 
    IPlayTLAdviser __RPC_FAR * This,
    IPlayTimeLine __RPC_FAR *pTimeLine,
    DWORD dwCurrentTime);


void __RPC_STUB IPlayTLAdviser_OnPostPositionBarMove_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT __stdcall IPlayTLAdviser_OnPreEventSizeStart_Proxy( 
    IPlayTLAdviser __RPC_FAR * This,
    IPlayTimeLine __RPC_FAR *pTimeLine,
    IPlayTLTrack __RPC_FAR *pTrack,
    IPlayTLEvent __RPC_FAR *pEvent,
    DWORD dwNewStartTime);


void __RPC_STUB IPlayTLAdviser_OnPreEventSizeStart_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT __stdcall IPlayTLAdviser_OnPreEventSizeEnd_Proxy( 
    IPlayTLAdviser __RPC_FAR * This,
    IPlayTimeLine __RPC_FAR *pTimeLine,
    IPlayTLTrack __RPC_FAR *pTrack,
    IPlayTLEvent __RPC_FAR *pEvent,
    DWORD dwNewEndTime);


void __RPC_STUB IPlayTLAdviser_OnPreEventSizeEnd_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT __stdcall IPlayTLAdviser_OnPostEventSize_Proxy( 
    IPlayTLAdviser __RPC_FAR * This,
    IPlayTimeLine __RPC_FAR *pTimeLine,
    IPlayTLTrack __RPC_FAR *pTrack,
    IPlayTLEvent __RPC_FAR *pEvent,
    DWORD dwNewLength);


void __RPC_STUB IPlayTLAdviser_OnPostEventSize_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT __stdcall IPlayTLAdviser_OnPopupMenu_Proxy( 
    IPlayTLAdviser __RPC_FAR * This,
    IPlayPopup __RPC_FAR *pPopup,
    IPlayTimeLine __RPC_FAR *pTimeLine,
    IPlayTLTrack __RPC_FAR *pTrack,
    IPlayTLEvent __RPC_FAR *pEvent,
    DWORD dwTime);


void __RPC_STUB IPlayTLAdviser_OnPopupMenu_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


IPlayTLTrack __RPC_FAR *STDMETHODCALLTYPE IPlayTLAdviser_OnEventSwitchTrack_Proxy( 
    IPlayTLAdviser __RPC_FAR * This,
    IPlayTimeLine __RPC_FAR *pTimeLine,
    IPlayTLTrack __RPC_FAR *pNewTrack,
    IPlayTLEvent __RPC_FAR *pEvent);


void __RPC_STUB IPlayTLAdviser_OnEventSwitchTrack_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT __stdcall IPlayTLAdviser_OnPreSetSourceIn_Proxy( 
    IPlayTLAdviser __RPC_FAR * This,
    IPlayTimeLine __RPC_FAR *pTimeLine,
    IPlayTLEvent __RPC_FAR *pEvent,
    DWORD dwNewSourceIn);


void __RPC_STUB IPlayTLAdviser_OnPreSetSourceIn_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT __stdcall IPlayTLAdviser_OnPostSetSourceIn_Proxy( 
    IPlayTLAdviser __RPC_FAR * This,
    IPlayTimeLine __RPC_FAR *pTimeLine,
    IPlayTLEvent __RPC_FAR *pEvent,
    DWORD dwNewSourceIn);


void __RPC_STUB IPlayTLAdviser_OnPostSetSourceIn_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IPlayTLAdviser_OnPreEventValueChange_Proxy( 
    IPlayTLAdviser __RPC_FAR * This,
    IPlayTimeLine __RPC_FAR *pTimeLine,
    IPlayTLTrack __RPC_FAR *pTrack,
    IPlayTLEvent __RPC_FAR *pEvent,
    double dwNewValue);


void __RPC_STUB IPlayTLAdviser_OnPreEventValueChange_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IPlayTLAdviser_OnEventValueChanging_Proxy( 
    IPlayTLAdviser __RPC_FAR * This,
    IPlayTimeLine __RPC_FAR *pTimeLine,
    IPlayTLTrack __RPC_FAR *pTrack,
    IPlayTLEvent __RPC_FAR *pEvent,
    double dwNewValue);


void __RPC_STUB IPlayTLAdviser_OnEventValueChanging_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IPlayTLAdviser_OnPostEventValueChange_Proxy( 
    IPlayTLAdviser __RPC_FAR * This,
    IPlayTimeLine __RPC_FAR *pTimeLine,
    IPlayTLTrack __RPC_FAR *pTrack,
    IPlayTLEvent __RPC_FAR *pEvent,
    double dwNewValue);


void __RPC_STUB IPlayTLAdviser_OnPostEventValueChange_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IPlayTLAdviser_OnEventValueDisplay_Proxy( 
    IPlayTLAdviser __RPC_FAR * This,
    IPlayTimeLine __RPC_FAR *pTimeLine,
    IPlayTLTrack __RPC_FAR *pTrack,
    IPlayTLEvent __RPC_FAR *pEvent,
    double dNewValue,
    LPSTR pszOutput,
    long numBytes);


void __RPC_STUB IPlayTLAdviser_OnEventValueDisplay_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT __stdcall IPlayTLAdviser_OnPaste_Proxy( 
    IPlayTLAdviser __RPC_FAR * This,
    IPlayTimeLine __RPC_FAR *pTimeLine,
    IPlayTLTrack __RPC_FAR *pTrack,
    IPlayTLEvent __RPC_FAR *pEvent);


void __RPC_STUB IPlayTLAdviser_OnPaste_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IPlayTLAdviser_INTERFACE_DEFINED__ */


#ifndef __IPlayTLAdviser2_INTERFACE_DEFINED__
#define __IPlayTLAdviser2_INTERFACE_DEFINED__

/****************************************
 * Generated header for interface: IPlayTLAdviser2
 * at Tue Nov 23 05:02:07 1999
 * using MIDL 3.01.75
 ****************************************/
/* [local][uuid][object] */ 



EXTERN_C const IID IID_IPlayTLAdviser2;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    interface DECLSPEC_UUID("8335e620-ab3b-11ce-8468-0000b468276b")
    IPlayTLAdviser2 : public IPlayTLAdviser
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE OnPostEventSwitchTrack( 
            IPlayTimeLine __RPC_FAR *pTimeLine,
            IPlayTLTrack __RPC_FAR *pNewTrack,
            IPlayTLTrack __RPC_FAR *pOldTrack,
            IPlayTLEvent __RPC_FAR *pEvent) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IPlayTLAdviser2Vtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            IPlayTLAdviser2 __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            IPlayTLAdviser2 __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            IPlayTLAdviser2 __RPC_FAR * This);
        
        HRESULT ( __stdcall __RPC_FAR *OnEventSelect )( 
            IPlayTLAdviser2 __RPC_FAR * This,
            IPlayTimeLine __RPC_FAR *pTimeLine,
            IPlayTLEvent __RPC_FAR *pEvent);
        
        HRESULT ( __stdcall __RPC_FAR *OnEventDeSelect )( 
            IPlayTLAdviser2 __RPC_FAR * This,
            IPlayTimeLine __RPC_FAR *pTimeLine,
            IPlayTLEvent __RPC_FAR *pEvent);
        
        HRESULT ( __stdcall __RPC_FAR *OnPreEventAdd )( 
            IPlayTLAdviser2 __RPC_FAR * This,
            IPlayTimeLine __RPC_FAR *pTimeLine,
            IPlayTLTrack __RPC_FAR *pTrack,
            IPlayTLEvent __RPC_FAR *pEvent);
        
        HRESULT ( __stdcall __RPC_FAR *OnPostEventAdd )( 
            IPlayTLAdviser2 __RPC_FAR * This,
            IPlayTimeLine __RPC_FAR *pTimeLine,
            IPlayTLTrack __RPC_FAR *pTrack,
            IPlayTLEvent __RPC_FAR *pEvent);
        
        HRESULT ( __stdcall __RPC_FAR *OnPreEventRemove )( 
            IPlayTLAdviser2 __RPC_FAR * This,
            IPlayTimeLine __RPC_FAR *pTimeLine,
            IPlayTLTrack __RPC_FAR *pTrack,
            IPlayTLEvent __RPC_FAR *pEvent);
        
        HRESULT ( __stdcall __RPC_FAR *OnPostEventRemove )( 
            IPlayTLAdviser2 __RPC_FAR * This,
            IPlayTimeLine __RPC_FAR *pTimeLine,
            IPlayTLTrack __RPC_FAR *pTrack,
            IPlayTLEvent __RPC_FAR *pEvent);
        
        HRESULT ( __stdcall __RPC_FAR *OnFileDrop )( 
            IPlayTLAdviser2 __RPC_FAR * This,
            IPlayTimeLine __RPC_FAR *pTimeLine,
            IPlayTLTrack __RPC_FAR *pTrack,
            DWORD dwTime,
            LPSTR pFileName);
        
        HRESULT ( __stdcall __RPC_FAR *OnPreEventMove )( 
            IPlayTLAdviser2 __RPC_FAR * This,
            IPlayTimeLine __RPC_FAR *pTimeLine,
            IPlayTLTrack __RPC_FAR *pTrack,
            IPlayTLEvent __RPC_FAR *pEvent,
            DWORD dwNewStartTime,
            BOOL bRipple,
            DWORD dwFirstTime);
        
        HRESULT ( __stdcall __RPC_FAR *OnEventMoving )( 
            IPlayTLAdviser2 __RPC_FAR * This,
            IPlayTimeLine __RPC_FAR *pTimeLine,
            IPlayTLTrack __RPC_FAR *pTrack,
            IPlayTLEvent __RPC_FAR *pEvent,
            DWORD dwNewStartTime,
            BOOL bRipple,
            DWORD dwFirstTime);
        
        HRESULT ( __stdcall __RPC_FAR *OnPostEventMove )( 
            IPlayTLAdviser2 __RPC_FAR * This,
            IPlayTimeLine __RPC_FAR *pTimeLine,
            IPlayTLTrack __RPC_FAR *pTrack,
            IPlayTLEvent __RPC_FAR *pEvent,
            DWORD dwNewStartTime,
            BOOL bRipple,
            DWORD dwFirstTime);
        
        HRESULT ( __stdcall __RPC_FAR *OnPrePositionBarMove )( 
            IPlayTLAdviser2 __RPC_FAR * This,
            IPlayTimeLine __RPC_FAR *pTimeLine,
            DWORD dwCurrentTime);
        
        HRESULT ( __stdcall __RPC_FAR *OnPositionBarMoving )( 
            IPlayTLAdviser2 __RPC_FAR * This,
            IPlayTimeLine __RPC_FAR *pTimeLine,
            DWORD dwCurrentTime);
        
        HRESULT ( __stdcall __RPC_FAR *OnPostPositionBarMove )( 
            IPlayTLAdviser2 __RPC_FAR * This,
            IPlayTimeLine __RPC_FAR *pTimeLine,
            DWORD dwCurrentTime);
        
        HRESULT ( __stdcall __RPC_FAR *OnPreEventSizeStart )( 
            IPlayTLAdviser2 __RPC_FAR * This,
            IPlayTimeLine __RPC_FAR *pTimeLine,
            IPlayTLTrack __RPC_FAR *pTrack,
            IPlayTLEvent __RPC_FAR *pEvent,
            DWORD dwNewStartTime);
        
        HRESULT ( __stdcall __RPC_FAR *OnPreEventSizeEnd )( 
            IPlayTLAdviser2 __RPC_FAR * This,
            IPlayTimeLine __RPC_FAR *pTimeLine,
            IPlayTLTrack __RPC_FAR *pTrack,
            IPlayTLEvent __RPC_FAR *pEvent,
            DWORD dwNewEndTime);
        
        HRESULT ( __stdcall __RPC_FAR *OnPostEventSize )( 
            IPlayTLAdviser2 __RPC_FAR * This,
            IPlayTimeLine __RPC_FAR *pTimeLine,
            IPlayTLTrack __RPC_FAR *pTrack,
            IPlayTLEvent __RPC_FAR *pEvent,
            DWORD dwNewLength);
        
        HRESULT ( __stdcall __RPC_FAR *OnPopupMenu )( 
            IPlayTLAdviser2 __RPC_FAR * This,
            IPlayPopup __RPC_FAR *pPopup,
            IPlayTimeLine __RPC_FAR *pTimeLine,
            IPlayTLTrack __RPC_FAR *pTrack,
            IPlayTLEvent __RPC_FAR *pEvent,
            DWORD dwTime);
        
        IPlayTLTrack __RPC_FAR *( STDMETHODCALLTYPE __RPC_FAR *OnEventSwitchTrack )( 
            IPlayTLAdviser2 __RPC_FAR * This,
            IPlayTimeLine __RPC_FAR *pTimeLine,
            IPlayTLTrack __RPC_FAR *pNewTrack,
            IPlayTLEvent __RPC_FAR *pEvent);
        
        HRESULT ( __stdcall __RPC_FAR *OnPreSetSourceIn )( 
            IPlayTLAdviser2 __RPC_FAR * This,
            IPlayTimeLine __RPC_FAR *pTimeLine,
            IPlayTLEvent __RPC_FAR *pEvent,
            DWORD dwNewSourceIn);
        
        HRESULT ( __stdcall __RPC_FAR *OnPostSetSourceIn )( 
            IPlayTLAdviser2 __RPC_FAR * This,
            IPlayTimeLine __RPC_FAR *pTimeLine,
            IPlayTLEvent __RPC_FAR *pEvent,
            DWORD dwNewSourceIn);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *OnPreEventValueChange )( 
            IPlayTLAdviser2 __RPC_FAR * This,
            IPlayTimeLine __RPC_FAR *pTimeLine,
            IPlayTLTrack __RPC_FAR *pTrack,
            IPlayTLEvent __RPC_FAR *pEvent,
            double dwNewValue);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *OnEventValueChanging )( 
            IPlayTLAdviser2 __RPC_FAR * This,
            IPlayTimeLine __RPC_FAR *pTimeLine,
            IPlayTLTrack __RPC_FAR *pTrack,
            IPlayTLEvent __RPC_FAR *pEvent,
            double dwNewValue);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *OnPostEventValueChange )( 
            IPlayTLAdviser2 __RPC_FAR * This,
            IPlayTimeLine __RPC_FAR *pTimeLine,
            IPlayTLTrack __RPC_FAR *pTrack,
            IPlayTLEvent __RPC_FAR *pEvent,
            double dwNewValue);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *OnEventValueDisplay )( 
            IPlayTLAdviser2 __RPC_FAR * This,
            IPlayTimeLine __RPC_FAR *pTimeLine,
            IPlayTLTrack __RPC_FAR *pTrack,
            IPlayTLEvent __RPC_FAR *pEvent,
            double dNewValue,
            LPSTR pszOutput,
            long numBytes);
        
        HRESULT ( __stdcall __RPC_FAR *OnPaste )( 
            IPlayTLAdviser2 __RPC_FAR * This,
            IPlayTimeLine __RPC_FAR *pTimeLine,
            IPlayTLTrack __RPC_FAR *pTrack,
            IPlayTLEvent __RPC_FAR *pEvent);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *OnPostEventSwitchTrack )( 
            IPlayTLAdviser2 __RPC_FAR * This,
            IPlayTimeLine __RPC_FAR *pTimeLine,
            IPlayTLTrack __RPC_FAR *pNewTrack,
            IPlayTLTrack __RPC_FAR *pOldTrack,
            IPlayTLEvent __RPC_FAR *pEvent);
        
        END_INTERFACE
    } IPlayTLAdviser2Vtbl;

    interface IPlayTLAdviser2
    {
        CONST_VTBL struct IPlayTLAdviser2Vtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IPlayTLAdviser2_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IPlayTLAdviser2_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IPlayTLAdviser2_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IPlayTLAdviser2_OnEventSelect(This,pTimeLine,pEvent)	\
    (This)->lpVtbl -> OnEventSelect(This,pTimeLine,pEvent)

#define IPlayTLAdviser2_OnEventDeSelect(This,pTimeLine,pEvent)	\
    (This)->lpVtbl -> OnEventDeSelect(This,pTimeLine,pEvent)

#define IPlayTLAdviser2_OnPreEventAdd(This,pTimeLine,pTrack,pEvent)	\
    (This)->lpVtbl -> OnPreEventAdd(This,pTimeLine,pTrack,pEvent)

#define IPlayTLAdviser2_OnPostEventAdd(This,pTimeLine,pTrack,pEvent)	\
    (This)->lpVtbl -> OnPostEventAdd(This,pTimeLine,pTrack,pEvent)

#define IPlayTLAdviser2_OnPreEventRemove(This,pTimeLine,pTrack,pEvent)	\
    (This)->lpVtbl -> OnPreEventRemove(This,pTimeLine,pTrack,pEvent)

#define IPlayTLAdviser2_OnPostEventRemove(This,pTimeLine,pTrack,pEvent)	\
    (This)->lpVtbl -> OnPostEventRemove(This,pTimeLine,pTrack,pEvent)

#define IPlayTLAdviser2_OnFileDrop(This,pTimeLine,pTrack,dwTime,pFileName)	\
    (This)->lpVtbl -> OnFileDrop(This,pTimeLine,pTrack,dwTime,pFileName)

#define IPlayTLAdviser2_OnPreEventMove(This,pTimeLine,pTrack,pEvent,dwNewStartTime,bRipple,dwFirstTime)	\
    (This)->lpVtbl -> OnPreEventMove(This,pTimeLine,pTrack,pEvent,dwNewStartTime,bRipple,dwFirstTime)

#define IPlayTLAdviser2_OnEventMoving(This,pTimeLine,pTrack,pEvent,dwNewStartTime,bRipple,dwFirstTime)	\
    (This)->lpVtbl -> OnEventMoving(This,pTimeLine,pTrack,pEvent,dwNewStartTime,bRipple,dwFirstTime)

#define IPlayTLAdviser2_OnPostEventMove(This,pTimeLine,pTrack,pEvent,dwNewStartTime,bRipple,dwFirstTime)	\
    (This)->lpVtbl -> OnPostEventMove(This,pTimeLine,pTrack,pEvent,dwNewStartTime,bRipple,dwFirstTime)

#define IPlayTLAdviser2_OnPrePositionBarMove(This,pTimeLine,dwCurrentTime)	\
    (This)->lpVtbl -> OnPrePositionBarMove(This,pTimeLine,dwCurrentTime)

#define IPlayTLAdviser2_OnPositionBarMoving(This,pTimeLine,dwCurrentTime)	\
    (This)->lpVtbl -> OnPositionBarMoving(This,pTimeLine,dwCurrentTime)

#define IPlayTLAdviser2_OnPostPositionBarMove(This,pTimeLine,dwCurrentTime)	\
    (This)->lpVtbl -> OnPostPositionBarMove(This,pTimeLine,dwCurrentTime)

#define IPlayTLAdviser2_OnPreEventSizeStart(This,pTimeLine,pTrack,pEvent,dwNewStartTime)	\
    (This)->lpVtbl -> OnPreEventSizeStart(This,pTimeLine,pTrack,pEvent,dwNewStartTime)

#define IPlayTLAdviser2_OnPreEventSizeEnd(This,pTimeLine,pTrack,pEvent,dwNewEndTime)	\
    (This)->lpVtbl -> OnPreEventSizeEnd(This,pTimeLine,pTrack,pEvent,dwNewEndTime)

#define IPlayTLAdviser2_OnPostEventSize(This,pTimeLine,pTrack,pEvent,dwNewLength)	\
    (This)->lpVtbl -> OnPostEventSize(This,pTimeLine,pTrack,pEvent,dwNewLength)

#define IPlayTLAdviser2_OnPopupMenu(This,pPopup,pTimeLine,pTrack,pEvent,dwTime)	\
    (This)->lpVtbl -> OnPopupMenu(This,pPopup,pTimeLine,pTrack,pEvent,dwTime)

#define IPlayTLAdviser2_OnEventSwitchTrack(This,pTimeLine,pNewTrack,pEvent)	\
    (This)->lpVtbl -> OnEventSwitchTrack(This,pTimeLine,pNewTrack,pEvent)

#define IPlayTLAdviser2_OnPreSetSourceIn(This,pTimeLine,pEvent,dwNewSourceIn)	\
    (This)->lpVtbl -> OnPreSetSourceIn(This,pTimeLine,pEvent,dwNewSourceIn)

#define IPlayTLAdviser2_OnPostSetSourceIn(This,pTimeLine,pEvent,dwNewSourceIn)	\
    (This)->lpVtbl -> OnPostSetSourceIn(This,pTimeLine,pEvent,dwNewSourceIn)

#define IPlayTLAdviser2_OnPreEventValueChange(This,pTimeLine,pTrack,pEvent,dwNewValue)	\
    (This)->lpVtbl -> OnPreEventValueChange(This,pTimeLine,pTrack,pEvent,dwNewValue)

#define IPlayTLAdviser2_OnEventValueChanging(This,pTimeLine,pTrack,pEvent,dwNewValue)	\
    (This)->lpVtbl -> OnEventValueChanging(This,pTimeLine,pTrack,pEvent,dwNewValue)

#define IPlayTLAdviser2_OnPostEventValueChange(This,pTimeLine,pTrack,pEvent,dwNewValue)	\
    (This)->lpVtbl -> OnPostEventValueChange(This,pTimeLine,pTrack,pEvent,dwNewValue)

#define IPlayTLAdviser2_OnEventValueDisplay(This,pTimeLine,pTrack,pEvent,dNewValue,pszOutput,numBytes)	\
    (This)->lpVtbl -> OnEventValueDisplay(This,pTimeLine,pTrack,pEvent,dNewValue,pszOutput,numBytes)

#define IPlayTLAdviser2_OnPaste(This,pTimeLine,pTrack,pEvent)	\
    (This)->lpVtbl -> OnPaste(This,pTimeLine,pTrack,pEvent)


#define IPlayTLAdviser2_OnPostEventSwitchTrack(This,pTimeLine,pNewTrack,pOldTrack,pEvent)	\
    (This)->lpVtbl -> OnPostEventSwitchTrack(This,pTimeLine,pNewTrack,pOldTrack,pEvent)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE IPlayTLAdviser2_OnPostEventSwitchTrack_Proxy( 
    IPlayTLAdviser2 __RPC_FAR * This,
    IPlayTimeLine __RPC_FAR *pTimeLine,
    IPlayTLTrack __RPC_FAR *pNewTrack,
    IPlayTLTrack __RPC_FAR *pOldTrack,
    IPlayTLEvent __RPC_FAR *pEvent);


void __RPC_STUB IPlayTLAdviser2_OnPostEventSwitchTrack_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IPlayTLAdviser2_INTERFACE_DEFINED__ */


#ifndef __IPlayLButtonAdviseSink_INTERFACE_DEFINED__
#define __IPlayLButtonAdviseSink_INTERFACE_DEFINED__

/****************************************
 * Generated header for interface: IPlayLButtonAdviseSink
 * at Tue Nov 23 05:02:07 1999
 * using MIDL 3.01.75
 ****************************************/
/* [local][uuid][object] */ 



EXTERN_C const IID IID_IPlayLButtonAdviseSink;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    interface DECLSPEC_UUID("8335e61f-ab3b-11ce-8468-0000b468276b")
    IPlayLButtonAdviseSink : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE OnLButtonDown( 
            HWND hWnd,
            WPARAM wParam,
            LPARAM lParam) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE OnLButtonUp( 
            HWND hWnd,
            WPARAM wParam,
            LPARAM lParam) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IPlayLButtonAdviseSinkVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            IPlayLButtonAdviseSink __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            IPlayLButtonAdviseSink __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            IPlayLButtonAdviseSink __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *OnLButtonDown )( 
            IPlayLButtonAdviseSink __RPC_FAR * This,
            HWND hWnd,
            WPARAM wParam,
            LPARAM lParam);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *OnLButtonUp )( 
            IPlayLButtonAdviseSink __RPC_FAR * This,
            HWND hWnd,
            WPARAM wParam,
            LPARAM lParam);
        
        END_INTERFACE
    } IPlayLButtonAdviseSinkVtbl;

    interface IPlayLButtonAdviseSink
    {
        CONST_VTBL struct IPlayLButtonAdviseSinkVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IPlayLButtonAdviseSink_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IPlayLButtonAdviseSink_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IPlayLButtonAdviseSink_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IPlayLButtonAdviseSink_OnLButtonDown(This,hWnd,wParam,lParam)	\
    (This)->lpVtbl -> OnLButtonDown(This,hWnd,wParam,lParam)

#define IPlayLButtonAdviseSink_OnLButtonUp(This,hWnd,wParam,lParam)	\
    (This)->lpVtbl -> OnLButtonUp(This,hWnd,wParam,lParam)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE IPlayLButtonAdviseSink_OnLButtonDown_Proxy( 
    IPlayLButtonAdviseSink __RPC_FAR * This,
    HWND hWnd,
    WPARAM wParam,
    LPARAM lParam);


void __RPC_STUB IPlayLButtonAdviseSink_OnLButtonDown_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IPlayLButtonAdviseSink_OnLButtonUp_Proxy( 
    IPlayLButtonAdviseSink __RPC_FAR * This,
    HWND hWnd,
    WPARAM wParam,
    LPARAM lParam);


void __RPC_STUB IPlayLButtonAdviseSink_OnLButtonUp_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IPlayLButtonAdviseSink_INTERFACE_DEFINED__ */


#ifndef __IPlayTLManagerAdviser_INTERFACE_DEFINED__
#define __IPlayTLManagerAdviser_INTERFACE_DEFINED__

/****************************************
 * Generated header for interface: IPlayTLManagerAdviser
 * at Tue Nov 23 05:02:07 1999
 * using MIDL 3.01.75
 ****************************************/
/* [local][uuid][object] */ 



EXTERN_C const IID IID_IPlayTLManagerAdviser;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    interface DECLSPEC_UUID("8335e60e-ab3b-11ce-8468-0000b468276b")
    IPlayTLManagerAdviser : public IUnknown
    {
    public:
        virtual HRESULT __stdcall OnPreLoad( 
            IPlayTimeLine __RPC_FAR *pTimeLine,
            LPSTR pFilename,
            IStorage __RPC_FAR *pStg) = 0;
        
        virtual HRESULT __stdcall OnPostLoad( 
            IPlayTimeLine __RPC_FAR *pTimeLine,
            LPSTR pFilename,
            IStorage __RPC_FAR *pStg) = 0;
        
        virtual HRESULT __stdcall OnPreViewRemoval( 
            IPlayTimeLine __RPC_FAR *pTimeLine) = 0;
        
        virtual HRESULT __stdcall OnPostViewRemoval( 
            IPlayTimeLine __RPC_FAR *pTimeLine) = 0;
        
        virtual HRESULT __stdcall OnPreSave( 
            IPlayTimeLine __RPC_FAR *pTimeLine,
            IStorage __RPC_FAR *pStg) = 0;
        
        virtual HRESULT __stdcall OnPostSave( 
            IPlayTimeLine __RPC_FAR *pTimeLine,
            IStorage __RPC_FAR *pStg) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IPlayTLManagerAdviserVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            IPlayTLManagerAdviser __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            IPlayTLManagerAdviser __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            IPlayTLManagerAdviser __RPC_FAR * This);
        
        HRESULT ( __stdcall __RPC_FAR *OnPreLoad )( 
            IPlayTLManagerAdviser __RPC_FAR * This,
            IPlayTimeLine __RPC_FAR *pTimeLine,
            LPSTR pFilename,
            IStorage __RPC_FAR *pStg);
        
        HRESULT ( __stdcall __RPC_FAR *OnPostLoad )( 
            IPlayTLManagerAdviser __RPC_FAR * This,
            IPlayTimeLine __RPC_FAR *pTimeLine,
            LPSTR pFilename,
            IStorage __RPC_FAR *pStg);
        
        HRESULT ( __stdcall __RPC_FAR *OnPreViewRemoval )( 
            IPlayTLManagerAdviser __RPC_FAR * This,
            IPlayTimeLine __RPC_FAR *pTimeLine);
        
        HRESULT ( __stdcall __RPC_FAR *OnPostViewRemoval )( 
            IPlayTLManagerAdviser __RPC_FAR * This,
            IPlayTimeLine __RPC_FAR *pTimeLine);
        
        HRESULT ( __stdcall __RPC_FAR *OnPreSave )( 
            IPlayTLManagerAdviser __RPC_FAR * This,
            IPlayTimeLine __RPC_FAR *pTimeLine,
            IStorage __RPC_FAR *pStg);
        
        HRESULT ( __stdcall __RPC_FAR *OnPostSave )( 
            IPlayTLManagerAdviser __RPC_FAR * This,
            IPlayTimeLine __RPC_FAR *pTimeLine,
            IStorage __RPC_FAR *pStg);
        
        END_INTERFACE
    } IPlayTLManagerAdviserVtbl;

    interface IPlayTLManagerAdviser
    {
        CONST_VTBL struct IPlayTLManagerAdviserVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IPlayTLManagerAdviser_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IPlayTLManagerAdviser_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IPlayTLManagerAdviser_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IPlayTLManagerAdviser_OnPreLoad(This,pTimeLine,pFilename,pStg)	\
    (This)->lpVtbl -> OnPreLoad(This,pTimeLine,pFilename,pStg)

#define IPlayTLManagerAdviser_OnPostLoad(This,pTimeLine,pFilename,pStg)	\
    (This)->lpVtbl -> OnPostLoad(This,pTimeLine,pFilename,pStg)

#define IPlayTLManagerAdviser_OnPreViewRemoval(This,pTimeLine)	\
    (This)->lpVtbl -> OnPreViewRemoval(This,pTimeLine)

#define IPlayTLManagerAdviser_OnPostViewRemoval(This,pTimeLine)	\
    (This)->lpVtbl -> OnPostViewRemoval(This,pTimeLine)

#define IPlayTLManagerAdviser_OnPreSave(This,pTimeLine,pStg)	\
    (This)->lpVtbl -> OnPreSave(This,pTimeLine,pStg)

#define IPlayTLManagerAdviser_OnPostSave(This,pTimeLine,pStg)	\
    (This)->lpVtbl -> OnPostSave(This,pTimeLine,pStg)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT __stdcall IPlayTLManagerAdviser_OnPreLoad_Proxy( 
    IPlayTLManagerAdviser __RPC_FAR * This,
    IPlayTimeLine __RPC_FAR *pTimeLine,
    LPSTR pFilename,
    IStorage __RPC_FAR *pStg);


void __RPC_STUB IPlayTLManagerAdviser_OnPreLoad_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT __stdcall IPlayTLManagerAdviser_OnPostLoad_Proxy( 
    IPlayTLManagerAdviser __RPC_FAR * This,
    IPlayTimeLine __RPC_FAR *pTimeLine,
    LPSTR pFilename,
    IStorage __RPC_FAR *pStg);


void __RPC_STUB IPlayTLManagerAdviser_OnPostLoad_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT __stdcall IPlayTLManagerAdviser_OnPreViewRemoval_Proxy( 
    IPlayTLManagerAdviser __RPC_FAR * This,
    IPlayTimeLine __RPC_FAR *pTimeLine);


void __RPC_STUB IPlayTLManagerAdviser_OnPreViewRemoval_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT __stdcall IPlayTLManagerAdviser_OnPostViewRemoval_Proxy( 
    IPlayTLManagerAdviser __RPC_FAR * This,
    IPlayTimeLine __RPC_FAR *pTimeLine);


void __RPC_STUB IPlayTLManagerAdviser_OnPostViewRemoval_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT __stdcall IPlayTLManagerAdviser_OnPreSave_Proxy( 
    IPlayTLManagerAdviser __RPC_FAR * This,
    IPlayTimeLine __RPC_FAR *pTimeLine,
    IStorage __RPC_FAR *pStg);


void __RPC_STUB IPlayTLManagerAdviser_OnPreSave_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT __stdcall IPlayTLManagerAdviser_OnPostSave_Proxy( 
    IPlayTLManagerAdviser __RPC_FAR * This,
    IPlayTimeLine __RPC_FAR *pTimeLine,
    IStorage __RPC_FAR *pStg);


void __RPC_STUB IPlayTLManagerAdviser_OnPostSave_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IPlayTLManagerAdviser_INTERFACE_DEFINED__ */


#ifndef __IPlayTLCloneAppObject_INTERFACE_DEFINED__
#define __IPlayTLCloneAppObject_INTERFACE_DEFINED__

/****************************************
 * Generated header for interface: IPlayTLCloneAppObject
 * at Tue Nov 23 05:02:07 1999
 * using MIDL 3.01.75
 ****************************************/
/* [local][uuid][object] */ 



EXTERN_C const IID IID_IPlayTLCloneAppObject;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    interface DECLSPEC_UUID("8335e644-ab3b-11ce-8468-0000b468276b")
    IPlayTLCloneAppObject : public IUnknown
    {
    public:
        virtual HRESULT __stdcall Clone( 
            IUnknown __RPC_FAR *__RPC_FAR *pUnknown) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IPlayTLCloneAppObjectVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            IPlayTLCloneAppObject __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            IPlayTLCloneAppObject __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            IPlayTLCloneAppObject __RPC_FAR * This);
        
        HRESULT ( __stdcall __RPC_FAR *Clone )( 
            IPlayTLCloneAppObject __RPC_FAR * This,
            IUnknown __RPC_FAR *__RPC_FAR *pUnknown);
        
        END_INTERFACE
    } IPlayTLCloneAppObjectVtbl;

    interface IPlayTLCloneAppObject
    {
        CONST_VTBL struct IPlayTLCloneAppObjectVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IPlayTLCloneAppObject_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IPlayTLCloneAppObject_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IPlayTLCloneAppObject_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IPlayTLCloneAppObject_Clone(This,pUnknown)	\
    (This)->lpVtbl -> Clone(This,pUnknown)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT __stdcall IPlayTLCloneAppObject_Clone_Proxy( 
    IPlayTLCloneAppObject __RPC_FAR * This,
    IUnknown __RPC_FAR *__RPC_FAR *pUnknown);


void __RPC_STUB IPlayTLCloneAppObject_Clone_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IPlayTLCloneAppObject_INTERFACE_DEFINED__ */


/* Additional Prototypes for ALL interfaces */

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif
