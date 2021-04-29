/* this ALWAYS GENERATED file contains the definitions for the interfaces */


/* File created by MIDL compiler version 3.01.75 */
/* at Tue Nov 23 05:28:34 1999
 */
/* Compiler settings for smedia.idl:
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

#ifndef __smedia_h__
#define __smedia_h__

#ifdef __cplusplus
extern "C"{
#endif 

/* Forward Declarations */ 

#ifndef __ITapeAdviseSink_FWD_DEFINED__
#define __ITapeAdviseSink_FWD_DEFINED__
typedef interface ITapeAdviseSink ITapeAdviseSink;
#endif 	/* __ITapeAdviseSink_FWD_DEFINED__ */


#ifndef __IMediaManager_FWD_DEFINED__
#define __IMediaManager_FWD_DEFINED__
typedef interface IMediaManager IMediaManager;
#endif 	/* __IMediaManager_FWD_DEFINED__ */


#ifndef __IMediaManager2_FWD_DEFINED__
#define __IMediaManager2_FWD_DEFINED__
typedef interface IMediaManager2 IMediaManager2;
#endif 	/* __IMediaManager2_FWD_DEFINED__ */


#ifndef __ITrnDeviceProfileDB_FWD_DEFINED__
#define __ITrnDeviceProfileDB_FWD_DEFINED__
typedef interface ITrnDeviceProfileDB ITrnDeviceProfileDB;
#endif 	/* __ITrnDeviceProfileDB_FWD_DEFINED__ */


#ifndef __ITapeVtr_FWD_DEFINED__
#define __ITapeVtr_FWD_DEFINED__
typedef interface ITapeVtr ITapeVtr;
#endif 	/* __ITapeVtr_FWD_DEFINED__ */


#ifndef __IRemovableMediaDevice_FWD_DEFINED__
#define __IRemovableMediaDevice_FWD_DEFINED__
typedef interface IRemovableMediaDevice IRemovableMediaDevice;
#endif 	/* __IRemovableMediaDevice_FWD_DEFINED__ */


#ifndef __IMediaConfig_FWD_DEFINED__
#define __IMediaConfig_FWD_DEFINED__
typedef interface IMediaConfig IMediaConfig;
#endif 	/* __IMediaConfig_FWD_DEFINED__ */


/* header files for imported files */
#include "wtypes.h"
#include "unknwn.h"
#include "objidl.h"
#include "autoct.h"
#include "props.h"

void __RPC_FAR * __RPC_USER MIDL_user_allocate(size_t);
void __RPC_USER MIDL_user_free( void __RPC_FAR * ); 

/****************************************
 * Generated header for interface: __MIDL_itf_smedia_0000
 * at Tue Nov 23 05:28:34 1999
 * using MIDL 3.01.75
 ****************************************/
/* [local] */ 






#define Mask(n) (((LONGLONG)(1))<<(n))


extern RPC_IF_HANDLE __MIDL_itf_smedia_0000_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_smedia_0000_v0_0_s_ifspec;

#ifndef __ITapeAdviseSink_INTERFACE_DEFINED__
#define __ITapeAdviseSink_INTERFACE_DEFINED__

/****************************************
 * Generated header for interface: ITapeAdviseSink
 * at Tue Nov 23 05:28:34 1999
 * using MIDL 3.01.75
 ****************************************/
/* [unique][uuid][object][local] */ 


//+-------------------------------------------------------------------------
//
//  Simple Tape API
//  Copyright (C) Play Incorporated, 1995.
//  PRELIMINARY - ALL SPECIFICATIONS SUBJECT TO CHANGE
//  PLAY CONFIDENTIAL - DO NOT DISTRIBUTE
//
//--------------------------------------------------------------------------
typedef struct  tagSTapeStatus
    {
    DWORD dwPortNum;
    DWORD statusType;
    LONGLONG liCurrentModes;
    LONGLONG liChangedModes;
    LONGLONG liCurrentStats;
    LONGLONG liChangedStats;
    DWORD dwTCData;
    DWORD dwUBData;
    }	STapeStatus;

typedef 
enum tagETapeVtrAdvise
    {	TATimeCodeLTC	= 1,
	TATimeCodeVITC	= 2,
	TATimeCodeGEN	= 4,
	TATimeCodeUB	= 8,
	TAStatus	= 16,
	TAMode	= 32,
	TACommand	= 64,
	TATimeCodeTimer1	= 128
    }	ETapeVtrAdvise;

typedef 
enum tagETrnCompletionCode
    {	CCAck	= 0,
	CCNak	= CCAck + 1,
	CCTimeout	= CCNak + 1,
	CCBadChecksum	= CCTimeout + 1,
	CCTimeValue	= CCBadChecksum + 1,
	CCSpeedValue	= CCTimeValue + 1
    }	ETrnCompletionCode;

typedef struct  tagSTrnCompletionRecord
    {
    DWORD dwPortNum;
    DWORD dwCommandId;
    ETrnCompletionCode code;
    union 
        {
        DWORD timeValue;
        DWORD speedValue;
        }	data;
    }	STrnCompletionRecord;


EXTERN_C const IID IID_ITapeAdviseSink;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    interface DECLSPEC_UUID("8335e3e7-ab3b-11ce-8468-0000b468276b")
    ITapeAdviseSink : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE OnStatusChange( 
            /* [in] */ DWORD dwSystemTime,
            /* [in] */ DWORD dwNumStatusElements,
            /* [in] */ STapeStatus __RPC_FAR *pStatsArray) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE OnCommandComplete( 
            /* [in] */ STrnCompletionRecord __RPC_FAR *pCompletionData) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct ITapeAdviseSinkVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            ITapeAdviseSink __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            ITapeAdviseSink __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            ITapeAdviseSink __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *OnStatusChange )( 
            ITapeAdviseSink __RPC_FAR * This,
            /* [in] */ DWORD dwSystemTime,
            /* [in] */ DWORD dwNumStatusElements,
            /* [in] */ STapeStatus __RPC_FAR *pStatsArray);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *OnCommandComplete )( 
            ITapeAdviseSink __RPC_FAR * This,
            /* [in] */ STrnCompletionRecord __RPC_FAR *pCompletionData);
        
        END_INTERFACE
    } ITapeAdviseSinkVtbl;

    interface ITapeAdviseSink
    {
        CONST_VTBL struct ITapeAdviseSinkVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ITapeAdviseSink_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define ITapeAdviseSink_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define ITapeAdviseSink_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define ITapeAdviseSink_OnStatusChange(This,dwSystemTime,dwNumStatusElements,pStatsArray)	\
    (This)->lpVtbl -> OnStatusChange(This,dwSystemTime,dwNumStatusElements,pStatsArray)

#define ITapeAdviseSink_OnCommandComplete(This,pCompletionData)	\
    (This)->lpVtbl -> OnCommandComplete(This,pCompletionData)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE ITapeAdviseSink_OnStatusChange_Proxy( 
    ITapeAdviseSink __RPC_FAR * This,
    /* [in] */ DWORD dwSystemTime,
    /* [in] */ DWORD dwNumStatusElements,
    /* [in] */ STapeStatus __RPC_FAR *pStatsArray);


void __RPC_STUB ITapeAdviseSink_OnStatusChange_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE ITapeAdviseSink_OnCommandComplete_Proxy( 
    ITapeAdviseSink __RPC_FAR * This,
    /* [in] */ STrnCompletionRecord __RPC_FAR *pCompletionData);


void __RPC_STUB ITapeAdviseSink_OnCommandComplete_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __ITapeAdviseSink_INTERFACE_DEFINED__ */


#ifndef __IMediaManager_INTERFACE_DEFINED__
#define __IMediaManager_INTERFACE_DEFINED__

/****************************************
 * Generated header for interface: IMediaManager
 * at Tue Nov 23 05:28:34 1999
 * using MIDL 3.01.75
 ****************************************/
/* [unique][uuid][object][local] */ 


typedef 
enum tagEMediaType
    {	MTVTR	= 0,
	MTATR	= MTVTR + 1,
	MTNLR	= MTATR + 1
    }	EMediaType;


EXTERN_C const IID IID_IMediaManager;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    interface DECLSPEC_UUID("8335e3f6-ab3b-11ce-8468-0000b468276b")
    IMediaManager : public IUnknown
    {
    public:
        virtual ULONG STDMETHODCALLTYPE QueryNumDevices( 
            EMediaType whichType) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE QueryController( 
            /* [out] */ ITrnAutomationController __RPC_FAR *__RPC_FAR *ppController) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE EnumDevices( 
            EMediaType whichType,
            IEnumUnknown __RPC_FAR *__RPC_FAR *ppEnum) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Advise( 
            /* [in] */ ULONG dwPortNum,
            /* [in] */ ITapeAdviseSink __RPC_FAR *pAdv,
            /* [in] */ ULONG filter,
            /* [in] */ LONGLONG statFilter,
            /* [in] */ LONGLONG modeFilter) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE UnAdvise( 
            /* [in] */ ULONG dwPortNum) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE RegisterAdviseSink( 
            /* [in] */ ITapeAdviseSink __RPC_FAR *pAdv) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE UnRegisterAdviseSink( 
            /* [in] */ ITapeAdviseSink __RPC_FAR *pAdv) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE AutoConfigDeviceOnPort( 
            /* [in] */ DWORD portNumber) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE DisconnectDeviceFromPort( 
            /* [in] */ DWORD portNumber) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IMediaManagerVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            IMediaManager __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            IMediaManager __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            IMediaManager __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *QueryNumDevices )( 
            IMediaManager __RPC_FAR * This,
            EMediaType whichType);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryController )( 
            IMediaManager __RPC_FAR * This,
            /* [out] */ ITrnAutomationController __RPC_FAR *__RPC_FAR *ppController);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *EnumDevices )( 
            IMediaManager __RPC_FAR * This,
            EMediaType whichType,
            IEnumUnknown __RPC_FAR *__RPC_FAR *ppEnum);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Advise )( 
            IMediaManager __RPC_FAR * This,
            /* [in] */ ULONG dwPortNum,
            /* [in] */ ITapeAdviseSink __RPC_FAR *pAdv,
            /* [in] */ ULONG filter,
            /* [in] */ LONGLONG statFilter,
            /* [in] */ LONGLONG modeFilter);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *UnAdvise )( 
            IMediaManager __RPC_FAR * This,
            /* [in] */ ULONG dwPortNum);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *RegisterAdviseSink )( 
            IMediaManager __RPC_FAR * This,
            /* [in] */ ITapeAdviseSink __RPC_FAR *pAdv);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *UnRegisterAdviseSink )( 
            IMediaManager __RPC_FAR * This,
            /* [in] */ ITapeAdviseSink __RPC_FAR *pAdv);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *AutoConfigDeviceOnPort )( 
            IMediaManager __RPC_FAR * This,
            /* [in] */ DWORD portNumber);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *DisconnectDeviceFromPort )( 
            IMediaManager __RPC_FAR * This,
            /* [in] */ DWORD portNumber);
        
        END_INTERFACE
    } IMediaManagerVtbl;

    interface IMediaManager
    {
        CONST_VTBL struct IMediaManagerVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IMediaManager_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IMediaManager_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IMediaManager_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IMediaManager_QueryNumDevices(This,whichType)	\
    (This)->lpVtbl -> QueryNumDevices(This,whichType)

#define IMediaManager_QueryController(This,ppController)	\
    (This)->lpVtbl -> QueryController(This,ppController)

#define IMediaManager_EnumDevices(This,whichType,ppEnum)	\
    (This)->lpVtbl -> EnumDevices(This,whichType,ppEnum)

#define IMediaManager_Advise(This,dwPortNum,pAdv,filter,statFilter,modeFilter)	\
    (This)->lpVtbl -> Advise(This,dwPortNum,pAdv,filter,statFilter,modeFilter)

#define IMediaManager_UnAdvise(This,dwPortNum)	\
    (This)->lpVtbl -> UnAdvise(This,dwPortNum)

#define IMediaManager_RegisterAdviseSink(This,pAdv)	\
    (This)->lpVtbl -> RegisterAdviseSink(This,pAdv)

#define IMediaManager_UnRegisterAdviseSink(This,pAdv)	\
    (This)->lpVtbl -> UnRegisterAdviseSink(This,pAdv)

#define IMediaManager_AutoConfigDeviceOnPort(This,portNumber)	\
    (This)->lpVtbl -> AutoConfigDeviceOnPort(This,portNumber)

#define IMediaManager_DisconnectDeviceFromPort(This,portNumber)	\
    (This)->lpVtbl -> DisconnectDeviceFromPort(This,portNumber)

#endif /* COBJMACROS */


#endif 	/* C style interface */



ULONG STDMETHODCALLTYPE IMediaManager_QueryNumDevices_Proxy( 
    IMediaManager __RPC_FAR * This,
    EMediaType whichType);


void __RPC_STUB IMediaManager_QueryNumDevices_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IMediaManager_QueryController_Proxy( 
    IMediaManager __RPC_FAR * This,
    /* [out] */ ITrnAutomationController __RPC_FAR *__RPC_FAR *ppController);


void __RPC_STUB IMediaManager_QueryController_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IMediaManager_EnumDevices_Proxy( 
    IMediaManager __RPC_FAR * This,
    EMediaType whichType,
    IEnumUnknown __RPC_FAR *__RPC_FAR *ppEnum);


void __RPC_STUB IMediaManager_EnumDevices_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IMediaManager_Advise_Proxy( 
    IMediaManager __RPC_FAR * This,
    /* [in] */ ULONG dwPortNum,
    /* [in] */ ITapeAdviseSink __RPC_FAR *pAdv,
    /* [in] */ ULONG filter,
    /* [in] */ LONGLONG statFilter,
    /* [in] */ LONGLONG modeFilter);


void __RPC_STUB IMediaManager_Advise_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IMediaManager_UnAdvise_Proxy( 
    IMediaManager __RPC_FAR * This,
    /* [in] */ ULONG dwPortNum);


void __RPC_STUB IMediaManager_UnAdvise_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IMediaManager_RegisterAdviseSink_Proxy( 
    IMediaManager __RPC_FAR * This,
    /* [in] */ ITapeAdviseSink __RPC_FAR *pAdv);


void __RPC_STUB IMediaManager_RegisterAdviseSink_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IMediaManager_UnRegisterAdviseSink_Proxy( 
    IMediaManager __RPC_FAR * This,
    /* [in] */ ITapeAdviseSink __RPC_FAR *pAdv);


void __RPC_STUB IMediaManager_UnRegisterAdviseSink_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IMediaManager_AutoConfigDeviceOnPort_Proxy( 
    IMediaManager __RPC_FAR * This,
    /* [in] */ DWORD portNumber);


void __RPC_STUB IMediaManager_AutoConfigDeviceOnPort_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IMediaManager_DisconnectDeviceFromPort_Proxy( 
    IMediaManager __RPC_FAR * This,
    /* [in] */ DWORD portNumber);


void __RPC_STUB IMediaManager_DisconnectDeviceFromPort_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IMediaManager_INTERFACE_DEFINED__ */


#ifndef __IMediaManager2_INTERFACE_DEFINED__
#define __IMediaManager2_INTERFACE_DEFINED__

/****************************************
 * Generated header for interface: IMediaManager2
 * at Tue Nov 23 05:28:34 1999
 * using MIDL 3.01.75
 ****************************************/
/* [unique][uuid][object][local] */ 



EXTERN_C const IID IID_IMediaManager2;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    interface DECLSPEC_UUID("8335e442-ab3b-11ce-8468-0000b468276b")
    IMediaManager2 : public IMediaManager
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE AutoConfigDeviceOnPort( 
            /* [in] */ DWORD portNumber,
            /* [in] */ REFCLSID ProtocolClass) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IMediaManager2Vtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            IMediaManager2 __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            IMediaManager2 __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            IMediaManager2 __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *QueryNumDevices )( 
            IMediaManager2 __RPC_FAR * This,
            EMediaType whichType);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryController )( 
            IMediaManager2 __RPC_FAR * This,
            /* [out] */ ITrnAutomationController __RPC_FAR *__RPC_FAR *ppController);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *EnumDevices )( 
            IMediaManager2 __RPC_FAR * This,
            EMediaType whichType,
            IEnumUnknown __RPC_FAR *__RPC_FAR *ppEnum);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Advise )( 
            IMediaManager2 __RPC_FAR * This,
            /* [in] */ ULONG dwPortNum,
            /* [in] */ ITapeAdviseSink __RPC_FAR *pAdv,
            /* [in] */ ULONG filter,
            /* [in] */ LONGLONG statFilter,
            /* [in] */ LONGLONG modeFilter);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *UnAdvise )( 
            IMediaManager2 __RPC_FAR * This,
            /* [in] */ ULONG dwPortNum);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *RegisterAdviseSink )( 
            IMediaManager2 __RPC_FAR * This,
            /* [in] */ ITapeAdviseSink __RPC_FAR *pAdv);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *UnRegisterAdviseSink )( 
            IMediaManager2 __RPC_FAR * This,
            /* [in] */ ITapeAdviseSink __RPC_FAR *pAdv);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *AutoConfigDeviceOnPort )( 
            IMediaManager2 __RPC_FAR * This,
            /* [in] */ DWORD portNumber);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *DisconnectDeviceFromPort )( 
            IMediaManager2 __RPC_FAR * This,
            /* [in] */ DWORD portNumber);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *AutoConfigDeviceOnPort )( 
            IMediaManager2 __RPC_FAR * This,
            /* [in] */ DWORD portNumber,
            /* [in] */ REFCLSID ProtocolClass);
        
        END_INTERFACE
    } IMediaManager2Vtbl;

    interface IMediaManager2
    {
        CONST_VTBL struct IMediaManager2Vtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IMediaManager2_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IMediaManager2_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IMediaManager2_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IMediaManager2_QueryNumDevices(This,whichType)	\
    (This)->lpVtbl -> QueryNumDevices(This,whichType)

#define IMediaManager2_QueryController(This,ppController)	\
    (This)->lpVtbl -> QueryController(This,ppController)

#define IMediaManager2_EnumDevices(This,whichType,ppEnum)	\
    (This)->lpVtbl -> EnumDevices(This,whichType,ppEnum)

#define IMediaManager2_Advise(This,dwPortNum,pAdv,filter,statFilter,modeFilter)	\
    (This)->lpVtbl -> Advise(This,dwPortNum,pAdv,filter,statFilter,modeFilter)

#define IMediaManager2_UnAdvise(This,dwPortNum)	\
    (This)->lpVtbl -> UnAdvise(This,dwPortNum)

#define IMediaManager2_RegisterAdviseSink(This,pAdv)	\
    (This)->lpVtbl -> RegisterAdviseSink(This,pAdv)

#define IMediaManager2_UnRegisterAdviseSink(This,pAdv)	\
    (This)->lpVtbl -> UnRegisterAdviseSink(This,pAdv)

#define IMediaManager2_AutoConfigDeviceOnPort(This,portNumber)	\
    (This)->lpVtbl -> AutoConfigDeviceOnPort(This,portNumber)

#define IMediaManager2_DisconnectDeviceFromPort(This,portNumber)	\
    (This)->lpVtbl -> DisconnectDeviceFromPort(This,portNumber)


#define IMediaManager2_AutoConfigDeviceOnPort(This,portNumber,ProtocolClass)	\
    (This)->lpVtbl -> AutoConfigDeviceOnPort(This,portNumber,ProtocolClass)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE IMediaManager2_AutoConfigDeviceOnPort_Proxy( 
    IMediaManager2 __RPC_FAR * This,
    /* [in] */ DWORD portNumber,
    /* [in] */ REFCLSID ProtocolClass);


void __RPC_STUB IMediaManager2_AutoConfigDeviceOnPort_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IMediaManager2_INTERFACE_DEFINED__ */


#ifndef __ITrnDeviceProfileDB_INTERFACE_DEFINED__
#define __ITrnDeviceProfileDB_INTERFACE_DEFINED__

/****************************************
 * Generated header for interface: ITrnDeviceProfileDB
 * at Tue Nov 23 05:28:34 1999
 * using MIDL 3.01.75
 ****************************************/
/* [unique][uuid][object][local] */ 


typedef 
enum tagETapeFormat
    {	TFVhs	= 0x1,
	TFSvhs	= 0x2,
	TFM2	= 0x4,
	TFBetaCam	= 0x8,
	TFD1	= 0x10,
	TFD2	= 0x20,
	TFD3	= 0x40,
	TF8mm	= 0x80,
	TFDVCam	= 0x100,
	TFDVCPro	= 0x200,
	TFDV	= 0x400,
	TFHi8	= 0x800,
	TF3Quarterin	= 0x1000,
	TF1in	= 0x2000,
	TF2in	= 0x4000,
	TFDigBetaCam	= 0x8000,
	TFDigSVHS	= 0x10000
    }	ETapeFormat;


EXTERN_C const IID IID_ITrnDeviceProfileDB;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    interface DECLSPEC_UUID("8335e42b-ab3b-11ce-8468-0000b468276b")
    ITrnDeviceProfileDB : public IUnknown
    {
    public:
        virtual BOOL STDMETHODCALLTYPE DeviceProfileExists( 
            /* [in] */ DWORD deviceType) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE CreateDeviceProfile( 
            /* [in] */ DWORD deviceType,
            /* [in] */ LONGLONG supportedModes,
            /* [in] */ DWORD tapeFormats,
            /* [string][in] */ LPSTR mfgNameAndModel,
            /* [in] */ IPlayProperties __RPC_FAR *propSet) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetDeviceProfile( 
            /* [in] */ DWORD deviceType,
            /* [out] */ LONGLONG __RPC_FAR *supportedModes,
            /* [out] */ DWORD __RPC_FAR *tapeFormats,
            /* [string][out] */ LPSTR mfgNameAndModel,
            /* [in] */ DWORD bufferSize,
            /* [out] */ IPlayProperties __RPC_FAR *__RPC_FAR *propSet) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE DeleteDeviceProfile( 
            /* [in] */ DWORD deviceType) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct ITrnDeviceProfileDBVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            ITrnDeviceProfileDB __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            ITrnDeviceProfileDB __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            ITrnDeviceProfileDB __RPC_FAR * This);
        
        BOOL ( STDMETHODCALLTYPE __RPC_FAR *DeviceProfileExists )( 
            ITrnDeviceProfileDB __RPC_FAR * This,
            /* [in] */ DWORD deviceType);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *CreateDeviceProfile )( 
            ITrnDeviceProfileDB __RPC_FAR * This,
            /* [in] */ DWORD deviceType,
            /* [in] */ LONGLONG supportedModes,
            /* [in] */ DWORD tapeFormats,
            /* [string][in] */ LPSTR mfgNameAndModel,
            /* [in] */ IPlayProperties __RPC_FAR *propSet);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetDeviceProfile )( 
            ITrnDeviceProfileDB __RPC_FAR * This,
            /* [in] */ DWORD deviceType,
            /* [out] */ LONGLONG __RPC_FAR *supportedModes,
            /* [out] */ DWORD __RPC_FAR *tapeFormats,
            /* [string][out] */ LPSTR mfgNameAndModel,
            /* [in] */ DWORD bufferSize,
            /* [out] */ IPlayProperties __RPC_FAR *__RPC_FAR *propSet);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *DeleteDeviceProfile )( 
            ITrnDeviceProfileDB __RPC_FAR * This,
            /* [in] */ DWORD deviceType);
        
        END_INTERFACE
    } ITrnDeviceProfileDBVtbl;

    interface ITrnDeviceProfileDB
    {
        CONST_VTBL struct ITrnDeviceProfileDBVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ITrnDeviceProfileDB_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define ITrnDeviceProfileDB_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define ITrnDeviceProfileDB_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define ITrnDeviceProfileDB_DeviceProfileExists(This,deviceType)	\
    (This)->lpVtbl -> DeviceProfileExists(This,deviceType)

#define ITrnDeviceProfileDB_CreateDeviceProfile(This,deviceType,supportedModes,tapeFormats,mfgNameAndModel,propSet)	\
    (This)->lpVtbl -> CreateDeviceProfile(This,deviceType,supportedModes,tapeFormats,mfgNameAndModel,propSet)

#define ITrnDeviceProfileDB_GetDeviceProfile(This,deviceType,supportedModes,tapeFormats,mfgNameAndModel,bufferSize,propSet)	\
    (This)->lpVtbl -> GetDeviceProfile(This,deviceType,supportedModes,tapeFormats,mfgNameAndModel,bufferSize,propSet)

#define ITrnDeviceProfileDB_DeleteDeviceProfile(This,deviceType)	\
    (This)->lpVtbl -> DeleteDeviceProfile(This,deviceType)

#endif /* COBJMACROS */


#endif 	/* C style interface */



BOOL STDMETHODCALLTYPE ITrnDeviceProfileDB_DeviceProfileExists_Proxy( 
    ITrnDeviceProfileDB __RPC_FAR * This,
    /* [in] */ DWORD deviceType);


void __RPC_STUB ITrnDeviceProfileDB_DeviceProfileExists_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE ITrnDeviceProfileDB_CreateDeviceProfile_Proxy( 
    ITrnDeviceProfileDB __RPC_FAR * This,
    /* [in] */ DWORD deviceType,
    /* [in] */ LONGLONG supportedModes,
    /* [in] */ DWORD tapeFormats,
    /* [string][in] */ LPSTR mfgNameAndModel,
    /* [in] */ IPlayProperties __RPC_FAR *propSet);


void __RPC_STUB ITrnDeviceProfileDB_CreateDeviceProfile_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE ITrnDeviceProfileDB_GetDeviceProfile_Proxy( 
    ITrnDeviceProfileDB __RPC_FAR * This,
    /* [in] */ DWORD deviceType,
    /* [out] */ LONGLONG __RPC_FAR *supportedModes,
    /* [out] */ DWORD __RPC_FAR *tapeFormats,
    /* [string][out] */ LPSTR mfgNameAndModel,
    /* [in] */ DWORD bufferSize,
    /* [out] */ IPlayProperties __RPC_FAR *__RPC_FAR *propSet);


void __RPC_STUB ITrnDeviceProfileDB_GetDeviceProfile_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE ITrnDeviceProfileDB_DeleteDeviceProfile_Proxy( 
    ITrnDeviceProfileDB __RPC_FAR * This,
    /* [in] */ DWORD deviceType);


void __RPC_STUB ITrnDeviceProfileDB_DeleteDeviceProfile_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __ITrnDeviceProfileDB_INTERFACE_DEFINED__ */


#ifndef __ITapeVtr_INTERFACE_DEFINED__
#define __ITapeVtr_INTERFACE_DEFINED__

/****************************************
 * Generated header for interface: ITapeVtr
 * at Tue Nov 23 05:28:34 1999
 * using MIDL 3.01.75
 ****************************************/
/* [unique][uuid][object][local] */ 


typedef 
enum tagETapeVtrMode
    {	VTLocal	= 0,
	VTStandby	= VTLocal + 1,
	VTFullEE	= VTStandby + 1,
	VTSelectEE	= VTFullEE + 1,
	VTEditMode	= VTSelectEE + 1,
	VTFreeze	= VTEditMode + 1,
	VTAutoMode	= VTFreeze + 1,
	VTPlay	= VTAutoMode + 1,
	VTSyncPlay	= VTPlay + 1,
	VTRecord	= VTSyncPlay + 1,
	VTEject	= VTRecord + 1,
	VTFastForward	= VTEject + 1,
	VTRewind	= VTFastForward + 1,
	VTStop	= VTRewind + 1,
	VTTensionRelease	= VTStop + 1,
	VTPreroll	= VTTensionRelease + 1,
	VTPreview	= VTPreroll + 1,
	VTReview	= VTPreview + 1,
	VTAutoEdit	= VTReview + 1,
	VTVideoReference	= VTAutoEdit + 1,
	VTAntiClog	= VTVideoReference + 1,
	VTTimeCodeGen	= VTAntiClog + 1,
	VTLostLockReset	= VTTimeCodeGen + 1,
	VTDAInputSelect	= VTLostLockReset + 1,
	VTInputCheck	= VTDAInputSelect + 1,
	VTTimer1Set	= VTInputCheck + 1,
	VTTimeCodeSet	= VTTimer1Set + 1,
	VTInTimeSet	= VTTimeCodeSet + 1,
	VTOutTimeSet	= VTInTimeSet + 1,
	VTUserBitSet	= VTOutTimeSet + 1,
	VTPrerollSet	= VTUserBitSet + 1,
	VTCuePointSet	= VTPrerollSet + 1,
	VTJog	= VTCuePointSet + 1,
	VTShuttle	= VTJog + 1,
	VTVarSpeedPlay	= VTShuttle + 1,
	VTEditSetup	= VTVarSpeedPlay + 1,
	VTServoRefSelect	= VTEditSetup + 1,
	VTPlayHeadSelect	= VTServoRefSelect + 1,
	VTColorFrameSelect	= VTPlayHeadSelect + 1,
	VTTimerModeSelect	= VTColorFrameSelect + 1,
	VTVideoInputSelect	= VTTimerModeSelect + 1,
	VTAudioModeSelect	= VTVideoInputSelect + 1,
	VTPreReadModeSelect	= VTAudioModeSelect + 1
    }	ETapeVtrMode;

typedef 
enum tagENLRMode
    {	NLRStop	= 0,
	NLRPlay	= NLRStop + 1,
	NLRRecord	= NLRPlay + 1,
	NLRCopy	= NLRRecord + 1
    }	ENLRMode;

typedef 
enum tagTapeVtrModeValue
    {	MVOFF	= 0,
	MVON	= MVOFF + 1,
	EMInsert	= MVON + 1,
	EMAssemble	= EMInsert + 1,
	EMEnableVideo	= EMAssemble + 1,
	EMEnableTimeCode	= EMEnableVideo + 1,
	EMEnableAudio1	= EMEnableTimeCode + 1,
	EMEnableAudio2	= EMEnableAudio1 + 1,
	SRAuto	= EMEnableAudio2 + 1,
	SRExternal	= SRAuto + 1,
	SRDefault	= SRExternal + 1,
	PHRecordPlay	= SRDefault + 1,
	PHPlayback	= PHRecordPlay + 1,
	PHDefault	= PHPlayback + 1,
	CF2Field	= PHDefault + 1,
	CF4Field	= CF2Field + 1,
	CF8Field	= CF4Field + 1,
	CFDefault	= CF8Field + 1,
	VIComposite	= CFDefault + 1,
	VIComponent	= VIComposite + 1,
	VIDub	= VIComponent + 1,
	VIDefault	= VIDub + 1,
	AMPCM	= VIDefault + 1,
	AMLinear	= AMPCM + 1,
	AMDefault	= AMLinear + 1
    }	ETapeVtrModeValue;

typedef 
enum tagTapeVtrStatus
    {	VSTapeOut	= 0,
	VSTapeTrouble	= VSTapeOut + 1,
	VSHardError	= VSTapeTrouble + 1,
	VSServoLock	= VSHardError + 1,
	VSTSOverride	= VSServoLock + 1,
	VSDirection	= VSTSOverride + 1,
	VSStill	= VSDirection + 1,
	VSCueComplete	= VSStill + 1,
	VSInsert	= VSCueComplete + 1,
	VSAssemble	= VSInsert + 1,
	VSVideo	= VSAssemble + 1,
	VSTimeCode	= VSVideo + 1,
	VSChangeTC	= VSTimeCode + 1,
	VSChangeUB	= VSChangeTC + 1,
	VSAudio1	= VSChangeUB + 1,
	VSAudio2	= VSAudio1 + 1,
	VSLampStill	= VSAudio2 + 1,
	VSLampFwd	= VSLampStill + 1,
	VSLampRev	= VSLampFwd + 1,
	VSInOut	= VSLampRev + 1,
	VSLostLock	= VSInOut + 1,
	VSNearEndOfTape	= VSLostLock + 1,
	VSEndOfTape	= VSNearEndOfTape + 1,
	VSColorFrameLock	= VSEndOfTape + 1,
	VSRecordInhibit	= VSColorFrameLock + 1,
	VSDropFrame	= VSRecordInhibit + 1,
	VSTimeCodeVITC	= VSDropFrame + 1,
	VSTimeCodeLTC	= VSTimeCodeVITC + 1,
	VSTimeCodeCTL	= VSTimeCodeLTC + 1
    }	ETapeVtrStatus;

typedef 
enum tagENLRStatus
    {	NLRSError	= 0,
	NLRSChangeTC	= NLRSError + 1
    }	ENLRStatus;


EXTERN_C const IID IID_ITapeVtr;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    interface DECLSPEC_UUID("8335e3e5-ab3b-11ce-8468-0000b468276b")
    ITapeVtr : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE QueryManager( 
            /* [out] */ IMediaManager __RPC_FAR *__RPC_FAR *ppManager) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE QuerySupportedModes( 
            /* [out] */ LONGLONG __RPC_FAR *pdwModes) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE QueryStatus( 
            /* [out] */ STapeStatus __RPC_FAR *pStatus) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetMode( 
            /* [in] */ STrnTimeType __RPC_FAR *pTime,
            /* [in] */ ETapeVtrMode mode,
            /* [in] */ ETapeVtrModeValue modeValue,
            /* [out] */ DWORD __RPC_FAR *pdwCommandId) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetModeMask( 
            /* [in] */ STrnTimeType __RPC_FAR *pTime,
            /* [in] */ ETapeVtrMode mode,
            /* [in] */ LONGLONG modeMask,
            /* [out] */ DWORD __RPC_FAR *pdwCommandId) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetVarSpeedMode( 
            /* [in] */ STrnTimeType __RPC_FAR *pTime,
            /* [in] */ ETapeVtrMode mode,
            /* [in] */ LONG speed,
            /* [out] */ DWORD __RPC_FAR *pdwCommandId) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetTime( 
            /* [in] */ STrnTimeType __RPC_FAR *pTime,
            /* [in] */ ETapeVtrMode mode,
            /* [in] */ DWORD time,
            /* [out] */ DWORD __RPC_FAR *pdwCommandId) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE EditSpeedAdjust( 
            /* [in] */ STrnTimeType __RPC_FAR *pTime,
            /* [in] */ LONG SpeedIndex,
            /* [out] */ DWORD __RPC_FAR *pdwCommandId) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE QueryAdjustRange( 
            /* [out] */ LONG __RPC_FAR *pdwPosLimit,
            /* [out] */ LONG __RPC_FAR *pdwNegLimit) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE QueryAdjustSpeed( 
            /* [in] */ LONG SpeedIndex,
            /* [out] */ ULONG __RPC_FAR *pdwTapeSpeed) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE QueryTapeSpeed( 
            /* [out] */ DWORD __RPC_FAR *pdwCommandId) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE QueryTapeFormat( 
            /* [out] */ DWORD __RPC_FAR *pdwFormat) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetSupportedModes( 
            /* [in] */ LONGLONG __RPC_FAR *pdwModes) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetTapeFormat( 
            /* [in] */ DWORD dwFormat) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct ITapeVtrVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            ITapeVtr __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            ITapeVtr __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            ITapeVtr __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryManager )( 
            ITapeVtr __RPC_FAR * This,
            /* [out] */ IMediaManager __RPC_FAR *__RPC_FAR *ppManager);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QuerySupportedModes )( 
            ITapeVtr __RPC_FAR * This,
            /* [out] */ LONGLONG __RPC_FAR *pdwModes);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryStatus )( 
            ITapeVtr __RPC_FAR * This,
            /* [out] */ STapeStatus __RPC_FAR *pStatus);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetMode )( 
            ITapeVtr __RPC_FAR * This,
            /* [in] */ STrnTimeType __RPC_FAR *pTime,
            /* [in] */ ETapeVtrMode mode,
            /* [in] */ ETapeVtrModeValue modeValue,
            /* [out] */ DWORD __RPC_FAR *pdwCommandId);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetModeMask )( 
            ITapeVtr __RPC_FAR * This,
            /* [in] */ STrnTimeType __RPC_FAR *pTime,
            /* [in] */ ETapeVtrMode mode,
            /* [in] */ LONGLONG modeMask,
            /* [out] */ DWORD __RPC_FAR *pdwCommandId);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetVarSpeedMode )( 
            ITapeVtr __RPC_FAR * This,
            /* [in] */ STrnTimeType __RPC_FAR *pTime,
            /* [in] */ ETapeVtrMode mode,
            /* [in] */ LONG speed,
            /* [out] */ DWORD __RPC_FAR *pdwCommandId);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetTime )( 
            ITapeVtr __RPC_FAR * This,
            /* [in] */ STrnTimeType __RPC_FAR *pTime,
            /* [in] */ ETapeVtrMode mode,
            /* [in] */ DWORD time,
            /* [out] */ DWORD __RPC_FAR *pdwCommandId);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *EditSpeedAdjust )( 
            ITapeVtr __RPC_FAR * This,
            /* [in] */ STrnTimeType __RPC_FAR *pTime,
            /* [in] */ LONG SpeedIndex,
            /* [out] */ DWORD __RPC_FAR *pdwCommandId);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryAdjustRange )( 
            ITapeVtr __RPC_FAR * This,
            /* [out] */ LONG __RPC_FAR *pdwPosLimit,
            /* [out] */ LONG __RPC_FAR *pdwNegLimit);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryAdjustSpeed )( 
            ITapeVtr __RPC_FAR * This,
            /* [in] */ LONG SpeedIndex,
            /* [out] */ ULONG __RPC_FAR *pdwTapeSpeed);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryTapeSpeed )( 
            ITapeVtr __RPC_FAR * This,
            /* [out] */ DWORD __RPC_FAR *pdwCommandId);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryTapeFormat )( 
            ITapeVtr __RPC_FAR * This,
            /* [out] */ DWORD __RPC_FAR *pdwFormat);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetSupportedModes )( 
            ITapeVtr __RPC_FAR * This,
            /* [in] */ LONGLONG __RPC_FAR *pdwModes);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetTapeFormat )( 
            ITapeVtr __RPC_FAR * This,
            /* [in] */ DWORD dwFormat);
        
        END_INTERFACE
    } ITapeVtrVtbl;

    interface ITapeVtr
    {
        CONST_VTBL struct ITapeVtrVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ITapeVtr_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define ITapeVtr_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define ITapeVtr_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define ITapeVtr_QueryManager(This,ppManager)	\
    (This)->lpVtbl -> QueryManager(This,ppManager)

#define ITapeVtr_QuerySupportedModes(This,pdwModes)	\
    (This)->lpVtbl -> QuerySupportedModes(This,pdwModes)

#define ITapeVtr_QueryStatus(This,pStatus)	\
    (This)->lpVtbl -> QueryStatus(This,pStatus)

#define ITapeVtr_SetMode(This,pTime,mode,modeValue,pdwCommandId)	\
    (This)->lpVtbl -> SetMode(This,pTime,mode,modeValue,pdwCommandId)

#define ITapeVtr_SetModeMask(This,pTime,mode,modeMask,pdwCommandId)	\
    (This)->lpVtbl -> SetModeMask(This,pTime,mode,modeMask,pdwCommandId)

#define ITapeVtr_SetVarSpeedMode(This,pTime,mode,speed,pdwCommandId)	\
    (This)->lpVtbl -> SetVarSpeedMode(This,pTime,mode,speed,pdwCommandId)

#define ITapeVtr_SetTime(This,pTime,mode,time,pdwCommandId)	\
    (This)->lpVtbl -> SetTime(This,pTime,mode,time,pdwCommandId)

#define ITapeVtr_EditSpeedAdjust(This,pTime,SpeedIndex,pdwCommandId)	\
    (This)->lpVtbl -> EditSpeedAdjust(This,pTime,SpeedIndex,pdwCommandId)

#define ITapeVtr_QueryAdjustRange(This,pdwPosLimit,pdwNegLimit)	\
    (This)->lpVtbl -> QueryAdjustRange(This,pdwPosLimit,pdwNegLimit)

#define ITapeVtr_QueryAdjustSpeed(This,SpeedIndex,pdwTapeSpeed)	\
    (This)->lpVtbl -> QueryAdjustSpeed(This,SpeedIndex,pdwTapeSpeed)

#define ITapeVtr_QueryTapeSpeed(This,pdwCommandId)	\
    (This)->lpVtbl -> QueryTapeSpeed(This,pdwCommandId)

#define ITapeVtr_QueryTapeFormat(This,pdwFormat)	\
    (This)->lpVtbl -> QueryTapeFormat(This,pdwFormat)

#define ITapeVtr_SetSupportedModes(This,pdwModes)	\
    (This)->lpVtbl -> SetSupportedModes(This,pdwModes)

#define ITapeVtr_SetTapeFormat(This,dwFormat)	\
    (This)->lpVtbl -> SetTapeFormat(This,dwFormat)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE ITapeVtr_QueryManager_Proxy( 
    ITapeVtr __RPC_FAR * This,
    /* [out] */ IMediaManager __RPC_FAR *__RPC_FAR *ppManager);


void __RPC_STUB ITapeVtr_QueryManager_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE ITapeVtr_QuerySupportedModes_Proxy( 
    ITapeVtr __RPC_FAR * This,
    /* [out] */ LONGLONG __RPC_FAR *pdwModes);


void __RPC_STUB ITapeVtr_QuerySupportedModes_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE ITapeVtr_QueryStatus_Proxy( 
    ITapeVtr __RPC_FAR * This,
    /* [out] */ STapeStatus __RPC_FAR *pStatus);


void __RPC_STUB ITapeVtr_QueryStatus_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE ITapeVtr_SetMode_Proxy( 
    ITapeVtr __RPC_FAR * This,
    /* [in] */ STrnTimeType __RPC_FAR *pTime,
    /* [in] */ ETapeVtrMode mode,
    /* [in] */ ETapeVtrModeValue modeValue,
    /* [out] */ DWORD __RPC_FAR *pdwCommandId);


void __RPC_STUB ITapeVtr_SetMode_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE ITapeVtr_SetModeMask_Proxy( 
    ITapeVtr __RPC_FAR * This,
    /* [in] */ STrnTimeType __RPC_FAR *pTime,
    /* [in] */ ETapeVtrMode mode,
    /* [in] */ LONGLONG modeMask,
    /* [out] */ DWORD __RPC_FAR *pdwCommandId);


void __RPC_STUB ITapeVtr_SetModeMask_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE ITapeVtr_SetVarSpeedMode_Proxy( 
    ITapeVtr __RPC_FAR * This,
    /* [in] */ STrnTimeType __RPC_FAR *pTime,
    /* [in] */ ETapeVtrMode mode,
    /* [in] */ LONG speed,
    /* [out] */ DWORD __RPC_FAR *pdwCommandId);


void __RPC_STUB ITapeVtr_SetVarSpeedMode_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE ITapeVtr_SetTime_Proxy( 
    ITapeVtr __RPC_FAR * This,
    /* [in] */ STrnTimeType __RPC_FAR *pTime,
    /* [in] */ ETapeVtrMode mode,
    /* [in] */ DWORD time,
    /* [out] */ DWORD __RPC_FAR *pdwCommandId);


void __RPC_STUB ITapeVtr_SetTime_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE ITapeVtr_EditSpeedAdjust_Proxy( 
    ITapeVtr __RPC_FAR * This,
    /* [in] */ STrnTimeType __RPC_FAR *pTime,
    /* [in] */ LONG SpeedIndex,
    /* [out] */ DWORD __RPC_FAR *pdwCommandId);


void __RPC_STUB ITapeVtr_EditSpeedAdjust_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE ITapeVtr_QueryAdjustRange_Proxy( 
    ITapeVtr __RPC_FAR * This,
    /* [out] */ LONG __RPC_FAR *pdwPosLimit,
    /* [out] */ LONG __RPC_FAR *pdwNegLimit);


void __RPC_STUB ITapeVtr_QueryAdjustRange_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE ITapeVtr_QueryAdjustSpeed_Proxy( 
    ITapeVtr __RPC_FAR * This,
    /* [in] */ LONG SpeedIndex,
    /* [out] */ ULONG __RPC_FAR *pdwTapeSpeed);


void __RPC_STUB ITapeVtr_QueryAdjustSpeed_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE ITapeVtr_QueryTapeSpeed_Proxy( 
    ITapeVtr __RPC_FAR * This,
    /* [out] */ DWORD __RPC_FAR *pdwCommandId);


void __RPC_STUB ITapeVtr_QueryTapeSpeed_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE ITapeVtr_QueryTapeFormat_Proxy( 
    ITapeVtr __RPC_FAR * This,
    /* [out] */ DWORD __RPC_FAR *pdwFormat);


void __RPC_STUB ITapeVtr_QueryTapeFormat_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE ITapeVtr_SetSupportedModes_Proxy( 
    ITapeVtr __RPC_FAR * This,
    /* [in] */ LONGLONG __RPC_FAR *pdwModes);


void __RPC_STUB ITapeVtr_SetSupportedModes_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE ITapeVtr_SetTapeFormat_Proxy( 
    ITapeVtr __RPC_FAR * This,
    /* [in] */ DWORD dwFormat);


void __RPC_STUB ITapeVtr_SetTapeFormat_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __ITapeVtr_INTERFACE_DEFINED__ */


#ifndef __IRemovableMediaDevice_INTERFACE_DEFINED__
#define __IRemovableMediaDevice_INTERFACE_DEFINED__

/****************************************
 * Generated header for interface: IRemovableMediaDevice
 * at Tue Nov 23 05:28:34 1999
 * using MIDL 3.01.75
 ****************************************/
/* [unique][uuid][object][local] */ 


#define S_VOLUMEABSENT 2

EXTERN_C const IID IID_IRemovableMediaDevice;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    interface DECLSPEC_UUID("8335e439-ab3b-11ce-8468-0000b468276b")
    IRemovableMediaDevice : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE GetVolumeName( 
            /* [string][out] */ LPSTR buffer,
            /* [in] */ DWORD bufsize,
            /* [out] */ DWORD __RPC_FAR *pdwActSize) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetVolumeName( 
            /* [string][in] */ LPSTR name) = 0;
        
        virtual ULONG STDMETHODCALLTYPE HasVolume( 
            /* [string][in] */ LPSTR name) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IRemovableMediaDeviceVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            IRemovableMediaDevice __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            IRemovableMediaDevice __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            IRemovableMediaDevice __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetVolumeName )( 
            IRemovableMediaDevice __RPC_FAR * This,
            /* [string][out] */ LPSTR buffer,
            /* [in] */ DWORD bufsize,
            /* [out] */ DWORD __RPC_FAR *pdwActSize);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetVolumeName )( 
            IRemovableMediaDevice __RPC_FAR * This,
            /* [string][in] */ LPSTR name);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *HasVolume )( 
            IRemovableMediaDevice __RPC_FAR * This,
            /* [string][in] */ LPSTR name);
        
        END_INTERFACE
    } IRemovableMediaDeviceVtbl;

    interface IRemovableMediaDevice
    {
        CONST_VTBL struct IRemovableMediaDeviceVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IRemovableMediaDevice_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IRemovableMediaDevice_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IRemovableMediaDevice_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IRemovableMediaDevice_GetVolumeName(This,buffer,bufsize,pdwActSize)	\
    (This)->lpVtbl -> GetVolumeName(This,buffer,bufsize,pdwActSize)

#define IRemovableMediaDevice_SetVolumeName(This,name)	\
    (This)->lpVtbl -> SetVolumeName(This,name)

#define IRemovableMediaDevice_HasVolume(This,name)	\
    (This)->lpVtbl -> HasVolume(This,name)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE IRemovableMediaDevice_GetVolumeName_Proxy( 
    IRemovableMediaDevice __RPC_FAR * This,
    /* [string][out] */ LPSTR buffer,
    /* [in] */ DWORD bufsize,
    /* [out] */ DWORD __RPC_FAR *pdwActSize);


void __RPC_STUB IRemovableMediaDevice_GetVolumeName_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IRemovableMediaDevice_SetVolumeName_Proxy( 
    IRemovableMediaDevice __RPC_FAR * This,
    /* [string][in] */ LPSTR name);


void __RPC_STUB IRemovableMediaDevice_SetVolumeName_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


ULONG STDMETHODCALLTYPE IRemovableMediaDevice_HasVolume_Proxy( 
    IRemovableMediaDevice __RPC_FAR * This,
    /* [string][in] */ LPSTR name);


void __RPC_STUB IRemovableMediaDevice_HasVolume_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IRemovableMediaDevice_INTERFACE_DEFINED__ */


#ifndef __IMediaConfig_INTERFACE_DEFINED__
#define __IMediaConfig_INTERFACE_DEFINED__

/****************************************
 * Generated header for interface: IMediaConfig
 * at Tue Nov 23 05:28:34 1999
 * using MIDL 3.01.75
 ****************************************/
/* [unique][uuid][object][local] */ 



EXTERN_C const IID IID_IMediaConfig;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    interface DECLSPEC_UUID("8335e420-ab3b-11ce-8468-0000b468276b")
    IMediaConfig : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE InstallSelfOnPort( 
            /* [in] */ DWORD portNum) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE RefreshSelfFromDatabase( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE QueryVidInputSlot( 
            /* [out] */ DWORD __RPC_FAR *pSlot) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetVidInputSlot( 
            /* [in] */ DWORD slot) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE QueryVidOutputSlot( 
            /* [out] */ DWORD __RPC_FAR *pSlot) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetVidOutputSlot( 
            /* [in] */ DWORD slot) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE QueryAudInput( 
            /* [in] */ DWORD output,
            /* [out] */ DWORD __RPC_FAR *input) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetAudInput( 
            /* [in] */ DWORD output,
            /* [in] */ DWORD input) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE QueryAudOutput( 
            /* [in] */ DWORD input,
            /* [out] */ DWORD __RPC_FAR *output) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetAudOutput( 
            /* [in] */ DWORD input,
            /* [in] */ DWORD output) = 0;
        
        virtual ULONG STDMETHODCALLTYPE QueryPortNum( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE QueryDeviceType( 
            /* [out] */ ULONG __RPC_FAR *pDeviceType,
            /* [string][out] */ unsigned char __RPC_FAR *pDeviceTypeName,
            /* [in] */ ULONG cbNameBuff) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE QueryDeviceName( 
            /* [string][out] */ unsigned char __RPC_FAR *pDeviceName,
            /* [in] */ ULONG cbNameBuff) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetDeviceName( 
            /* [string][in] */ unsigned char __RPC_FAR *pDeviceName) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IMediaConfigVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            IMediaConfig __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            IMediaConfig __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            IMediaConfig __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *InstallSelfOnPort )( 
            IMediaConfig __RPC_FAR * This,
            /* [in] */ DWORD portNum);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *RefreshSelfFromDatabase )( 
            IMediaConfig __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryVidInputSlot )( 
            IMediaConfig __RPC_FAR * This,
            /* [out] */ DWORD __RPC_FAR *pSlot);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetVidInputSlot )( 
            IMediaConfig __RPC_FAR * This,
            /* [in] */ DWORD slot);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryVidOutputSlot )( 
            IMediaConfig __RPC_FAR * This,
            /* [out] */ DWORD __RPC_FAR *pSlot);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetVidOutputSlot )( 
            IMediaConfig __RPC_FAR * This,
            /* [in] */ DWORD slot);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryAudInput )( 
            IMediaConfig __RPC_FAR * This,
            /* [in] */ DWORD output,
            /* [out] */ DWORD __RPC_FAR *input);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetAudInput )( 
            IMediaConfig __RPC_FAR * This,
            /* [in] */ DWORD output,
            /* [in] */ DWORD input);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryAudOutput )( 
            IMediaConfig __RPC_FAR * This,
            /* [in] */ DWORD input,
            /* [out] */ DWORD __RPC_FAR *output);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetAudOutput )( 
            IMediaConfig __RPC_FAR * This,
            /* [in] */ DWORD input,
            /* [in] */ DWORD output);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *QueryPortNum )( 
            IMediaConfig __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryDeviceType )( 
            IMediaConfig __RPC_FAR * This,
            /* [out] */ ULONG __RPC_FAR *pDeviceType,
            /* [string][out] */ unsigned char __RPC_FAR *pDeviceTypeName,
            /* [in] */ ULONG cbNameBuff);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryDeviceName )( 
            IMediaConfig __RPC_FAR * This,
            /* [string][out] */ unsigned char __RPC_FAR *pDeviceName,
            /* [in] */ ULONG cbNameBuff);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetDeviceName )( 
            IMediaConfig __RPC_FAR * This,
            /* [string][in] */ unsigned char __RPC_FAR *pDeviceName);
        
        END_INTERFACE
    } IMediaConfigVtbl;

    interface IMediaConfig
    {
        CONST_VTBL struct IMediaConfigVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IMediaConfig_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IMediaConfig_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IMediaConfig_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IMediaConfig_InstallSelfOnPort(This,portNum)	\
    (This)->lpVtbl -> InstallSelfOnPort(This,portNum)

#define IMediaConfig_RefreshSelfFromDatabase(This)	\
    (This)->lpVtbl -> RefreshSelfFromDatabase(This)

#define IMediaConfig_QueryVidInputSlot(This,pSlot)	\
    (This)->lpVtbl -> QueryVidInputSlot(This,pSlot)

#define IMediaConfig_SetVidInputSlot(This,slot)	\
    (This)->lpVtbl -> SetVidInputSlot(This,slot)

#define IMediaConfig_QueryVidOutputSlot(This,pSlot)	\
    (This)->lpVtbl -> QueryVidOutputSlot(This,pSlot)

#define IMediaConfig_SetVidOutputSlot(This,slot)	\
    (This)->lpVtbl -> SetVidOutputSlot(This,slot)

#define IMediaConfig_QueryAudInput(This,output,input)	\
    (This)->lpVtbl -> QueryAudInput(This,output,input)

#define IMediaConfig_SetAudInput(This,output,input)	\
    (This)->lpVtbl -> SetAudInput(This,output,input)

#define IMediaConfig_QueryAudOutput(This,input,output)	\
    (This)->lpVtbl -> QueryAudOutput(This,input,output)

#define IMediaConfig_SetAudOutput(This,input,output)	\
    (This)->lpVtbl -> SetAudOutput(This,input,output)

#define IMediaConfig_QueryPortNum(This)	\
    (This)->lpVtbl -> QueryPortNum(This)

#define IMediaConfig_QueryDeviceType(This,pDeviceType,pDeviceTypeName,cbNameBuff)	\
    (This)->lpVtbl -> QueryDeviceType(This,pDeviceType,pDeviceTypeName,cbNameBuff)

#define IMediaConfig_QueryDeviceName(This,pDeviceName,cbNameBuff)	\
    (This)->lpVtbl -> QueryDeviceName(This,pDeviceName,cbNameBuff)

#define IMediaConfig_SetDeviceName(This,pDeviceName)	\
    (This)->lpVtbl -> SetDeviceName(This,pDeviceName)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE IMediaConfig_InstallSelfOnPort_Proxy( 
    IMediaConfig __RPC_FAR * This,
    /* [in] */ DWORD portNum);


void __RPC_STUB IMediaConfig_InstallSelfOnPort_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IMediaConfig_RefreshSelfFromDatabase_Proxy( 
    IMediaConfig __RPC_FAR * This);


void __RPC_STUB IMediaConfig_RefreshSelfFromDatabase_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IMediaConfig_QueryVidInputSlot_Proxy( 
    IMediaConfig __RPC_FAR * This,
    /* [out] */ DWORD __RPC_FAR *pSlot);


void __RPC_STUB IMediaConfig_QueryVidInputSlot_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IMediaConfig_SetVidInputSlot_Proxy( 
    IMediaConfig __RPC_FAR * This,
    /* [in] */ DWORD slot);


void __RPC_STUB IMediaConfig_SetVidInputSlot_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IMediaConfig_QueryVidOutputSlot_Proxy( 
    IMediaConfig __RPC_FAR * This,
    /* [out] */ DWORD __RPC_FAR *pSlot);


void __RPC_STUB IMediaConfig_QueryVidOutputSlot_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IMediaConfig_SetVidOutputSlot_Proxy( 
    IMediaConfig __RPC_FAR * This,
    /* [in] */ DWORD slot);


void __RPC_STUB IMediaConfig_SetVidOutputSlot_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IMediaConfig_QueryAudInput_Proxy( 
    IMediaConfig __RPC_FAR * This,
    /* [in] */ DWORD output,
    /* [out] */ DWORD __RPC_FAR *input);


void __RPC_STUB IMediaConfig_QueryAudInput_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IMediaConfig_SetAudInput_Proxy( 
    IMediaConfig __RPC_FAR * This,
    /* [in] */ DWORD output,
    /* [in] */ DWORD input);


void __RPC_STUB IMediaConfig_SetAudInput_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IMediaConfig_QueryAudOutput_Proxy( 
    IMediaConfig __RPC_FAR * This,
    /* [in] */ DWORD input,
    /* [out] */ DWORD __RPC_FAR *output);


void __RPC_STUB IMediaConfig_QueryAudOutput_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IMediaConfig_SetAudOutput_Proxy( 
    IMediaConfig __RPC_FAR * This,
    /* [in] */ DWORD input,
    /* [in] */ DWORD output);


void __RPC_STUB IMediaConfig_SetAudOutput_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


ULONG STDMETHODCALLTYPE IMediaConfig_QueryPortNum_Proxy( 
    IMediaConfig __RPC_FAR * This);


void __RPC_STUB IMediaConfig_QueryPortNum_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IMediaConfig_QueryDeviceType_Proxy( 
    IMediaConfig __RPC_FAR * This,
    /* [out] */ ULONG __RPC_FAR *pDeviceType,
    /* [string][out] */ unsigned char __RPC_FAR *pDeviceTypeName,
    /* [in] */ ULONG cbNameBuff);


void __RPC_STUB IMediaConfig_QueryDeviceType_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IMediaConfig_QueryDeviceName_Proxy( 
    IMediaConfig __RPC_FAR * This,
    /* [string][out] */ unsigned char __RPC_FAR *pDeviceName,
    /* [in] */ ULONG cbNameBuff);


void __RPC_STUB IMediaConfig_QueryDeviceName_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IMediaConfig_SetDeviceName_Proxy( 
    IMediaConfig __RPC_FAR * This,
    /* [string][in] */ unsigned char __RPC_FAR *pDeviceName);


void __RPC_STUB IMediaConfig_SetDeviceName_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IMediaConfig_INTERFACE_DEFINED__ */


/* Additional Prototypes for ALL interfaces */

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif
