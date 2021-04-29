/* this ALWAYS GENERATED file contains the definitions for the interfaces */


/* File created by MIDL compiler version 3.01.75 */
/* at Tue Nov 23 05:28:26 1999
 */
/* Compiler settings for autoct.idl:
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

#ifndef __autoct_h__
#define __autoct_h__

#ifdef __cplusplus
extern "C"{
#endif 

/* Forward Declarations */ 

#ifndef __ITrnAutomationController_FWD_DEFINED__
#define __ITrnAutomationController_FWD_DEFINED__
typedef interface ITrnAutomationController ITrnAutomationController;
#endif 	/* __ITrnAutomationController_FWD_DEFINED__ */


#ifndef __ITrnAutomationController2_FWD_DEFINED__
#define __ITrnAutomationController2_FWD_DEFINED__
typedef interface ITrnAutomationController2 ITrnAutomationController2;
#endif 	/* __ITrnAutomationController2_FWD_DEFINED__ */


#ifndef __ITrnEventAdviseSink_FWD_DEFINED__
#define __ITrnEventAdviseSink_FWD_DEFINED__
typedef interface ITrnEventAdviseSink ITrnEventAdviseSink;
#endif 	/* __ITrnEventAdviseSink_FWD_DEFINED__ */


/* header files for imported files */
#include "wtypes.h"
#include "unknwn.h"
#include "plylst.h"

void __RPC_FAR * __RPC_USER MIDL_user_allocate(size_t);
void __RPC_USER MIDL_user_free( void __RPC_FAR * ); 

/****************************************
 * Generated header for interface: __MIDL_itf_autoct_0000
 * at Tue Nov 23 05:28:26 1999
 * using MIDL 3.01.75
 ****************************************/
/* [local] */ 





extern RPC_IF_HANDLE __MIDL_itf_autoct_0000_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_autoct_0000_v0_0_s_ifspec;

#ifndef __ITrnAutomationController_INTERFACE_DEFINED__
#define __ITrnAutomationController_INTERFACE_DEFINED__

/****************************************
 * Generated header for interface: ITrnAutomationController
 * at Tue Nov 23 05:28:26 1999
 * using MIDL 3.01.75
 ****************************************/
/* [unique][uuid][object][local] */ 


//+-------------------------------------------------------------------------
//
//  Trinity Core API
//  Copyright (C) Play Incorporated, 1995.
//  PRELIMINARY - ALL SPECIFICATIONS SUBJECT TO CHANGE
//  PLAY CONFIDENTIAL - DO NOT DISTRIBUTE
//
//--------------------------------------------------------------------------
#define TRACK_ASAP     0xFFFFFFFDL
#define TRACK_NEXTVBL  0xFFFFFFFEL
#define TRACK_ABSOLUTE 0xFFFFFFFFL
typedef struct  tagSTrnTimeType
    {
    DWORD baseTime;
    DWORD trackNumber;
    }	STrnTimeType;

typedef 
enum tagETrnTrackState
    {	TSReset	= 0,
	TSPaused	= TSReset + 1,
	TSPreroll	= TSPaused + 1,
	TSRunning	= TSPreroll + 1,
	TSPositioning	= TSRunning + 1,
	TSPausing	= TSPositioning + 1,
	TSResetting	= TSPausing + 1
    }	ETrnTrackState;

typedef struct  tagSTrnTrackInfo
    {
    DWORD prerollTime;
    DWORD stablizationTime;
    DWORD trackTime;
    unsigned int bindCount;
    ETrnTrackState state;
    }	STrnTrackInfo;

typedef 
enum tagETrnTimelineCallbackInfo
    {	TCIItemDone	= 0,
	TCIItemUndone	= TCIItemDone + 1
    }	ETrnTimelineCallbackInfo;


EXTERN_C const IID IID_ITrnAutomationController;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    interface DECLSPEC_UUID("8335e3eb-ab3b-11ce-8468-0000b468276b")
    ITrnAutomationController : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE QuerySystemTime( 
            /* [out] */ DWORD __RPC_FAR *pTime) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE QuerySystemClockRate( 
            /* [out] */ DWORD __RPC_FAR *pTicksPerInterval,
            /* [out] */ DWORD __RPC_FAR *pMicrosecondsPerInterval) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE ResetSystemTime( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE QueryNumTracks( 
            /* [out] */ DWORD __RPC_FAR *pnTracks) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE AllocTrack( 
            /* [out] */ DWORD __RPC_FAR *pdwTrack) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE FreeTrack( 
            DWORD dwTrack) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE PositionTrack( 
            /* [in] */ DWORD TrackNumber,
            /* [in] */ DWORD fieldNumber,
            /* [in] */ BOOL forcePause) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE TriggerTrack( 
            /* [in] */ DWORD dwTrackNumber,
            /* [in] */ STrnTimeType __RPC_FAR *pTriggerTime) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE BindTrack( 
            /* [in] */ DWORD dwTrackNumber,
            /* [in] */ STrnTimeType __RPC_FAR *pTriggerTime) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE PauseTrack( 
            /* [in] */ DWORD dwTrackNumber,
            /* [in] */ STrnTimeType __RPC_FAR *pTriggerTime) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE ResetTrack( 
            /* [in] */ DWORD dwTrackNumber) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE UndoTrack( 
            /* [in] */ DWORD dwTrackNumber) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE FlushTrack( 
            /* [in] */ DWORD dwTrackNumber) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE FlushAllTracks( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE QueryTrackInfo( 
            /* [in] */ DWORD dwTrackNumber,
            /* [out] */ STrnTrackInfo __RPC_FAR *pInfo) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE FireSystemEvent( 
            /* [in] */ DWORD dwEventNumber,
            /* [in] */ STrnTimeType __RPC_FAR *pEventTime) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE QueryEventPreroll( 
            /* [in] */ DWORD dwEventNumber,
            /* [out] */ DWORD __RPC_FAR *preRoll) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE TriggerTrackOnEvent( 
            /* [in] */ STrnTimeType __RPC_FAR *pTime,
            /* [in] */ DWORD dwEventNumber,
            /* [in] */ DWORD dwTrackNumber) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE ScheduleCallback( 
            /* [in] */ STrnTimeType __RPC_FAR *pTime,
            /* [in] */ ITrnEventAdviseSink __RPC_FAR *pAdvise,
            /* [in] */ DWORD dwClientInfo,
            /* [out] */ DWORD __RPC_FAR *pdwEventId) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE CancelCallback( 
            /* [in] */ ITrnEventAdviseSink __RPC_FAR *pAdvise) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct ITrnAutomationControllerVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            ITrnAutomationController __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            ITrnAutomationController __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            ITrnAutomationController __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QuerySystemTime )( 
            ITrnAutomationController __RPC_FAR * This,
            /* [out] */ DWORD __RPC_FAR *pTime);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QuerySystemClockRate )( 
            ITrnAutomationController __RPC_FAR * This,
            /* [out] */ DWORD __RPC_FAR *pTicksPerInterval,
            /* [out] */ DWORD __RPC_FAR *pMicrosecondsPerInterval);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *ResetSystemTime )( 
            ITrnAutomationController __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryNumTracks )( 
            ITrnAutomationController __RPC_FAR * This,
            /* [out] */ DWORD __RPC_FAR *pnTracks);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *AllocTrack )( 
            ITrnAutomationController __RPC_FAR * This,
            /* [out] */ DWORD __RPC_FAR *pdwTrack);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *FreeTrack )( 
            ITrnAutomationController __RPC_FAR * This,
            DWORD dwTrack);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *PositionTrack )( 
            ITrnAutomationController __RPC_FAR * This,
            /* [in] */ DWORD TrackNumber,
            /* [in] */ DWORD fieldNumber,
            /* [in] */ BOOL forcePause);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *TriggerTrack )( 
            ITrnAutomationController __RPC_FAR * This,
            /* [in] */ DWORD dwTrackNumber,
            /* [in] */ STrnTimeType __RPC_FAR *pTriggerTime);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *BindTrack )( 
            ITrnAutomationController __RPC_FAR * This,
            /* [in] */ DWORD dwTrackNumber,
            /* [in] */ STrnTimeType __RPC_FAR *pTriggerTime);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *PauseTrack )( 
            ITrnAutomationController __RPC_FAR * This,
            /* [in] */ DWORD dwTrackNumber,
            /* [in] */ STrnTimeType __RPC_FAR *pTriggerTime);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *ResetTrack )( 
            ITrnAutomationController __RPC_FAR * This,
            /* [in] */ DWORD dwTrackNumber);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *UndoTrack )( 
            ITrnAutomationController __RPC_FAR * This,
            /* [in] */ DWORD dwTrackNumber);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *FlushTrack )( 
            ITrnAutomationController __RPC_FAR * This,
            /* [in] */ DWORD dwTrackNumber);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *FlushAllTracks )( 
            ITrnAutomationController __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryTrackInfo )( 
            ITrnAutomationController __RPC_FAR * This,
            /* [in] */ DWORD dwTrackNumber,
            /* [out] */ STrnTrackInfo __RPC_FAR *pInfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *FireSystemEvent )( 
            ITrnAutomationController __RPC_FAR * This,
            /* [in] */ DWORD dwEventNumber,
            /* [in] */ STrnTimeType __RPC_FAR *pEventTime);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryEventPreroll )( 
            ITrnAutomationController __RPC_FAR * This,
            /* [in] */ DWORD dwEventNumber,
            /* [out] */ DWORD __RPC_FAR *preRoll);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *TriggerTrackOnEvent )( 
            ITrnAutomationController __RPC_FAR * This,
            /* [in] */ STrnTimeType __RPC_FAR *pTime,
            /* [in] */ DWORD dwEventNumber,
            /* [in] */ DWORD dwTrackNumber);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *ScheduleCallback )( 
            ITrnAutomationController __RPC_FAR * This,
            /* [in] */ STrnTimeType __RPC_FAR *pTime,
            /* [in] */ ITrnEventAdviseSink __RPC_FAR *pAdvise,
            /* [in] */ DWORD dwClientInfo,
            /* [out] */ DWORD __RPC_FAR *pdwEventId);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *CancelCallback )( 
            ITrnAutomationController __RPC_FAR * This,
            /* [in] */ ITrnEventAdviseSink __RPC_FAR *pAdvise);
        
        END_INTERFACE
    } ITrnAutomationControllerVtbl;

    interface ITrnAutomationController
    {
        CONST_VTBL struct ITrnAutomationControllerVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ITrnAutomationController_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define ITrnAutomationController_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define ITrnAutomationController_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define ITrnAutomationController_QuerySystemTime(This,pTime)	\
    (This)->lpVtbl -> QuerySystemTime(This,pTime)

#define ITrnAutomationController_QuerySystemClockRate(This,pTicksPerInterval,pMicrosecondsPerInterval)	\
    (This)->lpVtbl -> QuerySystemClockRate(This,pTicksPerInterval,pMicrosecondsPerInterval)

#define ITrnAutomationController_ResetSystemTime(This)	\
    (This)->lpVtbl -> ResetSystemTime(This)

#define ITrnAutomationController_QueryNumTracks(This,pnTracks)	\
    (This)->lpVtbl -> QueryNumTracks(This,pnTracks)

#define ITrnAutomationController_AllocTrack(This,pdwTrack)	\
    (This)->lpVtbl -> AllocTrack(This,pdwTrack)

#define ITrnAutomationController_FreeTrack(This,dwTrack)	\
    (This)->lpVtbl -> FreeTrack(This,dwTrack)

#define ITrnAutomationController_PositionTrack(This,TrackNumber,fieldNumber,forcePause)	\
    (This)->lpVtbl -> PositionTrack(This,TrackNumber,fieldNumber,forcePause)

#define ITrnAutomationController_TriggerTrack(This,dwTrackNumber,pTriggerTime)	\
    (This)->lpVtbl -> TriggerTrack(This,dwTrackNumber,pTriggerTime)

#define ITrnAutomationController_BindTrack(This,dwTrackNumber,pTriggerTime)	\
    (This)->lpVtbl -> BindTrack(This,dwTrackNumber,pTriggerTime)

#define ITrnAutomationController_PauseTrack(This,dwTrackNumber,pTriggerTime)	\
    (This)->lpVtbl -> PauseTrack(This,dwTrackNumber,pTriggerTime)

#define ITrnAutomationController_ResetTrack(This,dwTrackNumber)	\
    (This)->lpVtbl -> ResetTrack(This,dwTrackNumber)

#define ITrnAutomationController_UndoTrack(This,dwTrackNumber)	\
    (This)->lpVtbl -> UndoTrack(This,dwTrackNumber)

#define ITrnAutomationController_FlushTrack(This,dwTrackNumber)	\
    (This)->lpVtbl -> FlushTrack(This,dwTrackNumber)

#define ITrnAutomationController_FlushAllTracks(This)	\
    (This)->lpVtbl -> FlushAllTracks(This)

#define ITrnAutomationController_QueryTrackInfo(This,dwTrackNumber,pInfo)	\
    (This)->lpVtbl -> QueryTrackInfo(This,dwTrackNumber,pInfo)

#define ITrnAutomationController_FireSystemEvent(This,dwEventNumber,pEventTime)	\
    (This)->lpVtbl -> FireSystemEvent(This,dwEventNumber,pEventTime)

#define ITrnAutomationController_QueryEventPreroll(This,dwEventNumber,preRoll)	\
    (This)->lpVtbl -> QueryEventPreroll(This,dwEventNumber,preRoll)

#define ITrnAutomationController_TriggerTrackOnEvent(This,pTime,dwEventNumber,dwTrackNumber)	\
    (This)->lpVtbl -> TriggerTrackOnEvent(This,pTime,dwEventNumber,dwTrackNumber)

#define ITrnAutomationController_ScheduleCallback(This,pTime,pAdvise,dwClientInfo,pdwEventId)	\
    (This)->lpVtbl -> ScheduleCallback(This,pTime,pAdvise,dwClientInfo,pdwEventId)

#define ITrnAutomationController_CancelCallback(This,pAdvise)	\
    (This)->lpVtbl -> CancelCallback(This,pAdvise)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE ITrnAutomationController_QuerySystemTime_Proxy( 
    ITrnAutomationController __RPC_FAR * This,
    /* [out] */ DWORD __RPC_FAR *pTime);


void __RPC_STUB ITrnAutomationController_QuerySystemTime_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE ITrnAutomationController_QuerySystemClockRate_Proxy( 
    ITrnAutomationController __RPC_FAR * This,
    /* [out] */ DWORD __RPC_FAR *pTicksPerInterval,
    /* [out] */ DWORD __RPC_FAR *pMicrosecondsPerInterval);


void __RPC_STUB ITrnAutomationController_QuerySystemClockRate_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE ITrnAutomationController_ResetSystemTime_Proxy( 
    ITrnAutomationController __RPC_FAR * This);


void __RPC_STUB ITrnAutomationController_ResetSystemTime_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE ITrnAutomationController_QueryNumTracks_Proxy( 
    ITrnAutomationController __RPC_FAR * This,
    /* [out] */ DWORD __RPC_FAR *pnTracks);


void __RPC_STUB ITrnAutomationController_QueryNumTracks_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE ITrnAutomationController_AllocTrack_Proxy( 
    ITrnAutomationController __RPC_FAR * This,
    /* [out] */ DWORD __RPC_FAR *pdwTrack);


void __RPC_STUB ITrnAutomationController_AllocTrack_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE ITrnAutomationController_FreeTrack_Proxy( 
    ITrnAutomationController __RPC_FAR * This,
    DWORD dwTrack);


void __RPC_STUB ITrnAutomationController_FreeTrack_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE ITrnAutomationController_PositionTrack_Proxy( 
    ITrnAutomationController __RPC_FAR * This,
    /* [in] */ DWORD TrackNumber,
    /* [in] */ DWORD fieldNumber,
    /* [in] */ BOOL forcePause);


void __RPC_STUB ITrnAutomationController_PositionTrack_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE ITrnAutomationController_TriggerTrack_Proxy( 
    ITrnAutomationController __RPC_FAR * This,
    /* [in] */ DWORD dwTrackNumber,
    /* [in] */ STrnTimeType __RPC_FAR *pTriggerTime);


void __RPC_STUB ITrnAutomationController_TriggerTrack_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE ITrnAutomationController_BindTrack_Proxy( 
    ITrnAutomationController __RPC_FAR * This,
    /* [in] */ DWORD dwTrackNumber,
    /* [in] */ STrnTimeType __RPC_FAR *pTriggerTime);


void __RPC_STUB ITrnAutomationController_BindTrack_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE ITrnAutomationController_PauseTrack_Proxy( 
    ITrnAutomationController __RPC_FAR * This,
    /* [in] */ DWORD dwTrackNumber,
    /* [in] */ STrnTimeType __RPC_FAR *pTriggerTime);


void __RPC_STUB ITrnAutomationController_PauseTrack_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE ITrnAutomationController_ResetTrack_Proxy( 
    ITrnAutomationController __RPC_FAR * This,
    /* [in] */ DWORD dwTrackNumber);


void __RPC_STUB ITrnAutomationController_ResetTrack_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE ITrnAutomationController_UndoTrack_Proxy( 
    ITrnAutomationController __RPC_FAR * This,
    /* [in] */ DWORD dwTrackNumber);


void __RPC_STUB ITrnAutomationController_UndoTrack_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE ITrnAutomationController_FlushTrack_Proxy( 
    ITrnAutomationController __RPC_FAR * This,
    /* [in] */ DWORD dwTrackNumber);


void __RPC_STUB ITrnAutomationController_FlushTrack_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE ITrnAutomationController_FlushAllTracks_Proxy( 
    ITrnAutomationController __RPC_FAR * This);


void __RPC_STUB ITrnAutomationController_FlushAllTracks_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE ITrnAutomationController_QueryTrackInfo_Proxy( 
    ITrnAutomationController __RPC_FAR * This,
    /* [in] */ DWORD dwTrackNumber,
    /* [out] */ STrnTrackInfo __RPC_FAR *pInfo);


void __RPC_STUB ITrnAutomationController_QueryTrackInfo_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE ITrnAutomationController_FireSystemEvent_Proxy( 
    ITrnAutomationController __RPC_FAR * This,
    /* [in] */ DWORD dwEventNumber,
    /* [in] */ STrnTimeType __RPC_FAR *pEventTime);


void __RPC_STUB ITrnAutomationController_FireSystemEvent_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE ITrnAutomationController_QueryEventPreroll_Proxy( 
    ITrnAutomationController __RPC_FAR * This,
    /* [in] */ DWORD dwEventNumber,
    /* [out] */ DWORD __RPC_FAR *preRoll);


void __RPC_STUB ITrnAutomationController_QueryEventPreroll_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE ITrnAutomationController_TriggerTrackOnEvent_Proxy( 
    ITrnAutomationController __RPC_FAR * This,
    /* [in] */ STrnTimeType __RPC_FAR *pTime,
    /* [in] */ DWORD dwEventNumber,
    /* [in] */ DWORD dwTrackNumber);


void __RPC_STUB ITrnAutomationController_TriggerTrackOnEvent_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE ITrnAutomationController_ScheduleCallback_Proxy( 
    ITrnAutomationController __RPC_FAR * This,
    /* [in] */ STrnTimeType __RPC_FAR *pTime,
    /* [in] */ ITrnEventAdviseSink __RPC_FAR *pAdvise,
    /* [in] */ DWORD dwClientInfo,
    /* [out] */ DWORD __RPC_FAR *pdwEventId);


void __RPC_STUB ITrnAutomationController_ScheduleCallback_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE ITrnAutomationController_CancelCallback_Proxy( 
    ITrnAutomationController __RPC_FAR * This,
    /* [in] */ ITrnEventAdviseSink __RPC_FAR *pAdvise);


void __RPC_STUB ITrnAutomationController_CancelCallback_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __ITrnAutomationController_INTERFACE_DEFINED__ */


#ifndef __ITrnAutomationController2_INTERFACE_DEFINED__
#define __ITrnAutomationController2_INTERFACE_DEFINED__

/****************************************
 * Generated header for interface: ITrnAutomationController2
 * at Tue Nov 23 05:28:26 1999
 * using MIDL 3.01.75
 ****************************************/
/* [unique][uuid][object][local] */ 



EXTERN_C const IID IID_ITrnAutomationController2;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    interface DECLSPEC_UUID("8335e441-ab3b-11ce-8468-0000b468276b")
    ITrnAutomationController2 : public ITrnAutomationController
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE PositionTrackEx( 
            /* [in] */ unsigned int numTracks,
            /* [in] */ STrnTimeType __RPC_FAR *paTrackTimes,
            /* [in] */ BOOL forcePause) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct ITrnAutomationController2Vtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            ITrnAutomationController2 __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            ITrnAutomationController2 __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            ITrnAutomationController2 __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QuerySystemTime )( 
            ITrnAutomationController2 __RPC_FAR * This,
            /* [out] */ DWORD __RPC_FAR *pTime);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QuerySystemClockRate )( 
            ITrnAutomationController2 __RPC_FAR * This,
            /* [out] */ DWORD __RPC_FAR *pTicksPerInterval,
            /* [out] */ DWORD __RPC_FAR *pMicrosecondsPerInterval);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *ResetSystemTime )( 
            ITrnAutomationController2 __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryNumTracks )( 
            ITrnAutomationController2 __RPC_FAR * This,
            /* [out] */ DWORD __RPC_FAR *pnTracks);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *AllocTrack )( 
            ITrnAutomationController2 __RPC_FAR * This,
            /* [out] */ DWORD __RPC_FAR *pdwTrack);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *FreeTrack )( 
            ITrnAutomationController2 __RPC_FAR * This,
            DWORD dwTrack);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *PositionTrack )( 
            ITrnAutomationController2 __RPC_FAR * This,
            /* [in] */ DWORD TrackNumber,
            /* [in] */ DWORD fieldNumber,
            /* [in] */ BOOL forcePause);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *TriggerTrack )( 
            ITrnAutomationController2 __RPC_FAR * This,
            /* [in] */ DWORD dwTrackNumber,
            /* [in] */ STrnTimeType __RPC_FAR *pTriggerTime);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *BindTrack )( 
            ITrnAutomationController2 __RPC_FAR * This,
            /* [in] */ DWORD dwTrackNumber,
            /* [in] */ STrnTimeType __RPC_FAR *pTriggerTime);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *PauseTrack )( 
            ITrnAutomationController2 __RPC_FAR * This,
            /* [in] */ DWORD dwTrackNumber,
            /* [in] */ STrnTimeType __RPC_FAR *pTriggerTime);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *ResetTrack )( 
            ITrnAutomationController2 __RPC_FAR * This,
            /* [in] */ DWORD dwTrackNumber);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *UndoTrack )( 
            ITrnAutomationController2 __RPC_FAR * This,
            /* [in] */ DWORD dwTrackNumber);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *FlushTrack )( 
            ITrnAutomationController2 __RPC_FAR * This,
            /* [in] */ DWORD dwTrackNumber);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *FlushAllTracks )( 
            ITrnAutomationController2 __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryTrackInfo )( 
            ITrnAutomationController2 __RPC_FAR * This,
            /* [in] */ DWORD dwTrackNumber,
            /* [out] */ STrnTrackInfo __RPC_FAR *pInfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *FireSystemEvent )( 
            ITrnAutomationController2 __RPC_FAR * This,
            /* [in] */ DWORD dwEventNumber,
            /* [in] */ STrnTimeType __RPC_FAR *pEventTime);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryEventPreroll )( 
            ITrnAutomationController2 __RPC_FAR * This,
            /* [in] */ DWORD dwEventNumber,
            /* [out] */ DWORD __RPC_FAR *preRoll);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *TriggerTrackOnEvent )( 
            ITrnAutomationController2 __RPC_FAR * This,
            /* [in] */ STrnTimeType __RPC_FAR *pTime,
            /* [in] */ DWORD dwEventNumber,
            /* [in] */ DWORD dwTrackNumber);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *ScheduleCallback )( 
            ITrnAutomationController2 __RPC_FAR * This,
            /* [in] */ STrnTimeType __RPC_FAR *pTime,
            /* [in] */ ITrnEventAdviseSink __RPC_FAR *pAdvise,
            /* [in] */ DWORD dwClientInfo,
            /* [out] */ DWORD __RPC_FAR *pdwEventId);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *CancelCallback )( 
            ITrnAutomationController2 __RPC_FAR * This,
            /* [in] */ ITrnEventAdviseSink __RPC_FAR *pAdvise);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *PositionTrackEx )( 
            ITrnAutomationController2 __RPC_FAR * This,
            /* [in] */ unsigned int numTracks,
            /* [in] */ STrnTimeType __RPC_FAR *paTrackTimes,
            /* [in] */ BOOL forcePause);
        
        END_INTERFACE
    } ITrnAutomationController2Vtbl;

    interface ITrnAutomationController2
    {
        CONST_VTBL struct ITrnAutomationController2Vtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ITrnAutomationController2_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define ITrnAutomationController2_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define ITrnAutomationController2_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define ITrnAutomationController2_QuerySystemTime(This,pTime)	\
    (This)->lpVtbl -> QuerySystemTime(This,pTime)

#define ITrnAutomationController2_QuerySystemClockRate(This,pTicksPerInterval,pMicrosecondsPerInterval)	\
    (This)->lpVtbl -> QuerySystemClockRate(This,pTicksPerInterval,pMicrosecondsPerInterval)

#define ITrnAutomationController2_ResetSystemTime(This)	\
    (This)->lpVtbl -> ResetSystemTime(This)

#define ITrnAutomationController2_QueryNumTracks(This,pnTracks)	\
    (This)->lpVtbl -> QueryNumTracks(This,pnTracks)

#define ITrnAutomationController2_AllocTrack(This,pdwTrack)	\
    (This)->lpVtbl -> AllocTrack(This,pdwTrack)

#define ITrnAutomationController2_FreeTrack(This,dwTrack)	\
    (This)->lpVtbl -> FreeTrack(This,dwTrack)

#define ITrnAutomationController2_PositionTrack(This,TrackNumber,fieldNumber,forcePause)	\
    (This)->lpVtbl -> PositionTrack(This,TrackNumber,fieldNumber,forcePause)

#define ITrnAutomationController2_TriggerTrack(This,dwTrackNumber,pTriggerTime)	\
    (This)->lpVtbl -> TriggerTrack(This,dwTrackNumber,pTriggerTime)

#define ITrnAutomationController2_BindTrack(This,dwTrackNumber,pTriggerTime)	\
    (This)->lpVtbl -> BindTrack(This,dwTrackNumber,pTriggerTime)

#define ITrnAutomationController2_PauseTrack(This,dwTrackNumber,pTriggerTime)	\
    (This)->lpVtbl -> PauseTrack(This,dwTrackNumber,pTriggerTime)

#define ITrnAutomationController2_ResetTrack(This,dwTrackNumber)	\
    (This)->lpVtbl -> ResetTrack(This,dwTrackNumber)

#define ITrnAutomationController2_UndoTrack(This,dwTrackNumber)	\
    (This)->lpVtbl -> UndoTrack(This,dwTrackNumber)

#define ITrnAutomationController2_FlushTrack(This,dwTrackNumber)	\
    (This)->lpVtbl -> FlushTrack(This,dwTrackNumber)

#define ITrnAutomationController2_FlushAllTracks(This)	\
    (This)->lpVtbl -> FlushAllTracks(This)

#define ITrnAutomationController2_QueryTrackInfo(This,dwTrackNumber,pInfo)	\
    (This)->lpVtbl -> QueryTrackInfo(This,dwTrackNumber,pInfo)

#define ITrnAutomationController2_FireSystemEvent(This,dwEventNumber,pEventTime)	\
    (This)->lpVtbl -> FireSystemEvent(This,dwEventNumber,pEventTime)

#define ITrnAutomationController2_QueryEventPreroll(This,dwEventNumber,preRoll)	\
    (This)->lpVtbl -> QueryEventPreroll(This,dwEventNumber,preRoll)

#define ITrnAutomationController2_TriggerTrackOnEvent(This,pTime,dwEventNumber,dwTrackNumber)	\
    (This)->lpVtbl -> TriggerTrackOnEvent(This,pTime,dwEventNumber,dwTrackNumber)

#define ITrnAutomationController2_ScheduleCallback(This,pTime,pAdvise,dwClientInfo,pdwEventId)	\
    (This)->lpVtbl -> ScheduleCallback(This,pTime,pAdvise,dwClientInfo,pdwEventId)

#define ITrnAutomationController2_CancelCallback(This,pAdvise)	\
    (This)->lpVtbl -> CancelCallback(This,pAdvise)


#define ITrnAutomationController2_PositionTrackEx(This,numTracks,paTrackTimes,forcePause)	\
    (This)->lpVtbl -> PositionTrackEx(This,numTracks,paTrackTimes,forcePause)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE ITrnAutomationController2_PositionTrackEx_Proxy( 
    ITrnAutomationController2 __RPC_FAR * This,
    /* [in] */ unsigned int numTracks,
    /* [in] */ STrnTimeType __RPC_FAR *paTrackTimes,
    /* [in] */ BOOL forcePause);


void __RPC_STUB ITrnAutomationController2_PositionTrackEx_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __ITrnAutomationController2_INTERFACE_DEFINED__ */


#ifndef __ITrnEventAdviseSink_INTERFACE_DEFINED__
#define __ITrnEventAdviseSink_INTERFACE_DEFINED__

/****************************************
 * Generated header for interface: ITrnEventAdviseSink
 * at Tue Nov 23 05:28:26 1999
 * using MIDL 3.01.75
 ****************************************/
/* [unique][uuid][object][local] */ 



EXTERN_C const IID IID_ITrnEventAdviseSink;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    interface DECLSPEC_UUID("8335e400-ab3b-11ce-8468-0000b468276b")
    ITrnEventAdviseSink : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE OnEvent( 
            /* [in] */ DWORD dwSystemTime,
            /* [in] */ DWORD dwEventId,
            /* [in] */ DWORD dwClientInfo,
            /* [in] */ DWORD dwSystemInfo) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE OnCancel( 
            /* [in] */ DWORD dwEventId) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct ITrnEventAdviseSinkVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            ITrnEventAdviseSink __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            ITrnEventAdviseSink __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            ITrnEventAdviseSink __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *OnEvent )( 
            ITrnEventAdviseSink __RPC_FAR * This,
            /* [in] */ DWORD dwSystemTime,
            /* [in] */ DWORD dwEventId,
            /* [in] */ DWORD dwClientInfo,
            /* [in] */ DWORD dwSystemInfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *OnCancel )( 
            ITrnEventAdviseSink __RPC_FAR * This,
            /* [in] */ DWORD dwEventId);
        
        END_INTERFACE
    } ITrnEventAdviseSinkVtbl;

    interface ITrnEventAdviseSink
    {
        CONST_VTBL struct ITrnEventAdviseSinkVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ITrnEventAdviseSink_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define ITrnEventAdviseSink_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define ITrnEventAdviseSink_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define ITrnEventAdviseSink_OnEvent(This,dwSystemTime,dwEventId,dwClientInfo,dwSystemInfo)	\
    (This)->lpVtbl -> OnEvent(This,dwSystemTime,dwEventId,dwClientInfo,dwSystemInfo)

#define ITrnEventAdviseSink_OnCancel(This,dwEventId)	\
    (This)->lpVtbl -> OnCancel(This,dwEventId)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE ITrnEventAdviseSink_OnEvent_Proxy( 
    ITrnEventAdviseSink __RPC_FAR * This,
    /* [in] */ DWORD dwSystemTime,
    /* [in] */ DWORD dwEventId,
    /* [in] */ DWORD dwClientInfo,
    /* [in] */ DWORD dwSystemInfo);


void __RPC_STUB ITrnEventAdviseSink_OnEvent_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE ITrnEventAdviseSink_OnCancel_Proxy( 
    ITrnEventAdviseSink __RPC_FAR * This,
    /* [in] */ DWORD dwEventId);


void __RPC_STUB ITrnEventAdviseSink_OnCancel_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __ITrnEventAdviseSink_INTERFACE_DEFINED__ */


/* Additional Prototypes for ALL interfaces */

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif
