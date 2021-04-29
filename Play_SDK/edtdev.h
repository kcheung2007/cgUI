/* this ALWAYS GENERATED file contains the definitions for the interfaces */


/* File created by MIDL compiler version 3.01.75 */
/* at Tue Nov 23 05:28:29 1999
 */
/* Compiler settings for edtdev.idl:
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

#ifndef __edtdev_h__
#define __edtdev_h__

#ifdef __cplusplus
extern "C"{
#endif 

/* Forward Declarations */ 

#ifndef __IEditorDevice_FWD_DEFINED__
#define __IEditorDevice_FWD_DEFINED__
typedef interface IEditorDevice IEditorDevice;
#endif 	/* __IEditorDevice_FWD_DEFINED__ */


/* header files for imported files */
#include "unknwn.h"
#include "autoct.h"
#include "trnity.h"

void __RPC_FAR * __RPC_USER MIDL_user_allocate(size_t);
void __RPC_USER MIDL_user_free( void __RPC_FAR * ); 

#ifndef __IEditorDevice_INTERFACE_DEFINED__
#define __IEditorDevice_INTERFACE_DEFINED__

/****************************************
 * Generated header for interface: IEditorDevice
 * at Tue Nov 23 05:28:29 1999
 * using MIDL 3.01.75
 ****************************************/
/* [uuid][object][local] */ 



EXTERN_C const IID IID_IEditorDevice;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    interface DECLSPEC_UUID("8335e627-ab3b-11ce-8468-0000b468276b")
    IEditorDevice : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE Pause( 
            STrnTimeType __RPC_FAR *pTime) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE FwdFrame( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE RevFrame( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE FwdPlay( 
            STrnTimeType __RPC_FAR *pTime) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE RevPlay( 
            STrnTimeType __RPC_FAR *pTime) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE FwdFast( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE RevFast( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Select( 
            BOOL bSelOnBus,
            long __RPC_FAR *plTransportDisableMask) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE DeSelect( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Stop( 
            STrnTimeType __RPC_FAR *pTime) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE IsStopped( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetStandby( 
            STrnTimeType __RPC_FAR *pTime,
            DWORD bOn) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE CueToFrame( 
            ULONG uFrame) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Eject( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE ShuttleSpeed( 
            STrnTimeType __RPC_FAR *pTime,
            long lSpeed) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetFrame( 
            ULONG __RPC_FAR *pdwCurFrame) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetTCType( 
            ULONG __RPC_FAR *pTCType) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetDevType( 
            LONG __RPC_FAR *plType) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetReel( 
            /* [string][out] */ LPSTR name,
            DWORD size) = 0;
        
        virtual void STDMETHODCALLTYPE SetReel( 
            /* [string][in] */ LPSTR name) = 0;
        
        virtual BOOL STDMETHODCALLTYPE HasReel( 
            /* [string][in] */ LPSTR name) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetAudLevel( 
            STrnTimeType __RPC_FAR *pTime,
            long vtrinput,
            ETrnACParamType Param,
            long index,
            STrnPlayList __RPC_FAR *plist) = 0;
        
        virtual DWORD STDMETHODCALLTYPE GetVidPort( void) = 0;
        
        virtual DWORD STDMETHODCALLTYPE GetAudInput( 
            DWORD dwChannel) = 0;
        
        virtual void STDMETHODCALLTYPE SetInPoint( 
            long lIn) = 0;
        
        virtual void STDMETHODCALLTYPE SetOutPoint( 
            long lOut) = 0;
        
        virtual long STDMETHODCALLTYPE GetInPoint( void) = 0;
        
        virtual long STDMETHODCALLTYPE GetOutPoint( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Record( 
            STrnTimeType __RPC_FAR *pTime) = 0;
        
        virtual DWORD STDMETHODCALLTYPE GetAudOutput( 
            DWORD dwChannel) = 0;
        
        virtual DWORD STDMETHODCALLTYPE GetVidOutput( void) = 0;
        
        virtual BOOL STDMETHODCALLTYPE IsRecordDeck( void) = 0;
        
        virtual DWORD STDMETHODCALLTYPE GetInputComponentMask( void) = 0;
        
        virtual DWORD STDMETHODCALLTYPE GetOutputComponentMask( void) = 0;
        
        virtual DWORD STDMETHODCALLTYPE GetSerialPort( void) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IEditorDeviceVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            IEditorDevice __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            IEditorDevice __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            IEditorDevice __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Pause )( 
            IEditorDevice __RPC_FAR * This,
            STrnTimeType __RPC_FAR *pTime);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *FwdFrame )( 
            IEditorDevice __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *RevFrame )( 
            IEditorDevice __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *FwdPlay )( 
            IEditorDevice __RPC_FAR * This,
            STrnTimeType __RPC_FAR *pTime);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *RevPlay )( 
            IEditorDevice __RPC_FAR * This,
            STrnTimeType __RPC_FAR *pTime);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *FwdFast )( 
            IEditorDevice __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *RevFast )( 
            IEditorDevice __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Select )( 
            IEditorDevice __RPC_FAR * This,
            BOOL bSelOnBus,
            long __RPC_FAR *plTransportDisableMask);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *DeSelect )( 
            IEditorDevice __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Stop )( 
            IEditorDevice __RPC_FAR * This,
            STrnTimeType __RPC_FAR *pTime);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *IsStopped )( 
            IEditorDevice __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetStandby )( 
            IEditorDevice __RPC_FAR * This,
            STrnTimeType __RPC_FAR *pTime,
            DWORD bOn);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *CueToFrame )( 
            IEditorDevice __RPC_FAR * This,
            ULONG uFrame);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Eject )( 
            IEditorDevice __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *ShuttleSpeed )( 
            IEditorDevice __RPC_FAR * This,
            STrnTimeType __RPC_FAR *pTime,
            long lSpeed);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetFrame )( 
            IEditorDevice __RPC_FAR * This,
            ULONG __RPC_FAR *pdwCurFrame);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTCType )( 
            IEditorDevice __RPC_FAR * This,
            ULONG __RPC_FAR *pTCType);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetDevType )( 
            IEditorDevice __RPC_FAR * This,
            LONG __RPC_FAR *plType);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetReel )( 
            IEditorDevice __RPC_FAR * This,
            /* [string][out] */ LPSTR name,
            DWORD size);
        
        void ( STDMETHODCALLTYPE __RPC_FAR *SetReel )( 
            IEditorDevice __RPC_FAR * This,
            /* [string][in] */ LPSTR name);
        
        BOOL ( STDMETHODCALLTYPE __RPC_FAR *HasReel )( 
            IEditorDevice __RPC_FAR * This,
            /* [string][in] */ LPSTR name);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetAudLevel )( 
            IEditorDevice __RPC_FAR * This,
            STrnTimeType __RPC_FAR *pTime,
            long vtrinput,
            ETrnACParamType Param,
            long index,
            STrnPlayList __RPC_FAR *plist);
        
        DWORD ( STDMETHODCALLTYPE __RPC_FAR *GetVidPort )( 
            IEditorDevice __RPC_FAR * This);
        
        DWORD ( STDMETHODCALLTYPE __RPC_FAR *GetAudInput )( 
            IEditorDevice __RPC_FAR * This,
            DWORD dwChannel);
        
        void ( STDMETHODCALLTYPE __RPC_FAR *SetInPoint )( 
            IEditorDevice __RPC_FAR * This,
            long lIn);
        
        void ( STDMETHODCALLTYPE __RPC_FAR *SetOutPoint )( 
            IEditorDevice __RPC_FAR * This,
            long lOut);
        
        long ( STDMETHODCALLTYPE __RPC_FAR *GetInPoint )( 
            IEditorDevice __RPC_FAR * This);
        
        long ( STDMETHODCALLTYPE __RPC_FAR *GetOutPoint )( 
            IEditorDevice __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Record )( 
            IEditorDevice __RPC_FAR * This,
            STrnTimeType __RPC_FAR *pTime);
        
        DWORD ( STDMETHODCALLTYPE __RPC_FAR *GetAudOutput )( 
            IEditorDevice __RPC_FAR * This,
            DWORD dwChannel);
        
        DWORD ( STDMETHODCALLTYPE __RPC_FAR *GetVidOutput )( 
            IEditorDevice __RPC_FAR * This);
        
        BOOL ( STDMETHODCALLTYPE __RPC_FAR *IsRecordDeck )( 
            IEditorDevice __RPC_FAR * This);
        
        DWORD ( STDMETHODCALLTYPE __RPC_FAR *GetInputComponentMask )( 
            IEditorDevice __RPC_FAR * This);
        
        DWORD ( STDMETHODCALLTYPE __RPC_FAR *GetOutputComponentMask )( 
            IEditorDevice __RPC_FAR * This);
        
        DWORD ( STDMETHODCALLTYPE __RPC_FAR *GetSerialPort )( 
            IEditorDevice __RPC_FAR * This);
        
        END_INTERFACE
    } IEditorDeviceVtbl;

    interface IEditorDevice
    {
        CONST_VTBL struct IEditorDeviceVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IEditorDevice_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IEditorDevice_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IEditorDevice_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IEditorDevice_Pause(This,pTime)	\
    (This)->lpVtbl -> Pause(This,pTime)

#define IEditorDevice_FwdFrame(This)	\
    (This)->lpVtbl -> FwdFrame(This)

#define IEditorDevice_RevFrame(This)	\
    (This)->lpVtbl -> RevFrame(This)

#define IEditorDevice_FwdPlay(This,pTime)	\
    (This)->lpVtbl -> FwdPlay(This,pTime)

#define IEditorDevice_RevPlay(This,pTime)	\
    (This)->lpVtbl -> RevPlay(This,pTime)

#define IEditorDevice_FwdFast(This)	\
    (This)->lpVtbl -> FwdFast(This)

#define IEditorDevice_RevFast(This)	\
    (This)->lpVtbl -> RevFast(This)

#define IEditorDevice_Select(This,bSelOnBus,plTransportDisableMask)	\
    (This)->lpVtbl -> Select(This,bSelOnBus,plTransportDisableMask)

#define IEditorDevice_DeSelect(This)	\
    (This)->lpVtbl -> DeSelect(This)

#define IEditorDevice_Stop(This,pTime)	\
    (This)->lpVtbl -> Stop(This,pTime)

#define IEditorDevice_IsStopped(This)	\
    (This)->lpVtbl -> IsStopped(This)

#define IEditorDevice_SetStandby(This,pTime,bOn)	\
    (This)->lpVtbl -> SetStandby(This,pTime,bOn)

#define IEditorDevice_CueToFrame(This,uFrame)	\
    (This)->lpVtbl -> CueToFrame(This,uFrame)

#define IEditorDevice_Eject(This)	\
    (This)->lpVtbl -> Eject(This)

#define IEditorDevice_ShuttleSpeed(This,pTime,lSpeed)	\
    (This)->lpVtbl -> ShuttleSpeed(This,pTime,lSpeed)

#define IEditorDevice_GetFrame(This,pdwCurFrame)	\
    (This)->lpVtbl -> GetFrame(This,pdwCurFrame)

#define IEditorDevice_GetTCType(This,pTCType)	\
    (This)->lpVtbl -> GetTCType(This,pTCType)

#define IEditorDevice_GetDevType(This,plType)	\
    (This)->lpVtbl -> GetDevType(This,plType)

#define IEditorDevice_GetReel(This,name,size)	\
    (This)->lpVtbl -> GetReel(This,name,size)

#define IEditorDevice_SetReel(This,name)	\
    (This)->lpVtbl -> SetReel(This,name)

#define IEditorDevice_HasReel(This,name)	\
    (This)->lpVtbl -> HasReel(This,name)

#define IEditorDevice_SetAudLevel(This,pTime,vtrinput,Param,index,plist)	\
    (This)->lpVtbl -> SetAudLevel(This,pTime,vtrinput,Param,index,plist)

#define IEditorDevice_GetVidPort(This)	\
    (This)->lpVtbl -> GetVidPort(This)

#define IEditorDevice_GetAudInput(This,dwChannel)	\
    (This)->lpVtbl -> GetAudInput(This,dwChannel)

#define IEditorDevice_SetInPoint(This,lIn)	\
    (This)->lpVtbl -> SetInPoint(This,lIn)

#define IEditorDevice_SetOutPoint(This,lOut)	\
    (This)->lpVtbl -> SetOutPoint(This,lOut)

#define IEditorDevice_GetInPoint(This)	\
    (This)->lpVtbl -> GetInPoint(This)

#define IEditorDevice_GetOutPoint(This)	\
    (This)->lpVtbl -> GetOutPoint(This)

#define IEditorDevice_Record(This,pTime)	\
    (This)->lpVtbl -> Record(This,pTime)

#define IEditorDevice_GetAudOutput(This,dwChannel)	\
    (This)->lpVtbl -> GetAudOutput(This,dwChannel)

#define IEditorDevice_GetVidOutput(This)	\
    (This)->lpVtbl -> GetVidOutput(This)

#define IEditorDevice_IsRecordDeck(This)	\
    (This)->lpVtbl -> IsRecordDeck(This)

#define IEditorDevice_GetInputComponentMask(This)	\
    (This)->lpVtbl -> GetInputComponentMask(This)

#define IEditorDevice_GetOutputComponentMask(This)	\
    (This)->lpVtbl -> GetOutputComponentMask(This)

#define IEditorDevice_GetSerialPort(This)	\
    (This)->lpVtbl -> GetSerialPort(This)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE IEditorDevice_Pause_Proxy( 
    IEditorDevice __RPC_FAR * This,
    STrnTimeType __RPC_FAR *pTime);


void __RPC_STUB IEditorDevice_Pause_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IEditorDevice_FwdFrame_Proxy( 
    IEditorDevice __RPC_FAR * This);


void __RPC_STUB IEditorDevice_FwdFrame_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IEditorDevice_RevFrame_Proxy( 
    IEditorDevice __RPC_FAR * This);


void __RPC_STUB IEditorDevice_RevFrame_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IEditorDevice_FwdPlay_Proxy( 
    IEditorDevice __RPC_FAR * This,
    STrnTimeType __RPC_FAR *pTime);


void __RPC_STUB IEditorDevice_FwdPlay_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IEditorDevice_RevPlay_Proxy( 
    IEditorDevice __RPC_FAR * This,
    STrnTimeType __RPC_FAR *pTime);


void __RPC_STUB IEditorDevice_RevPlay_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IEditorDevice_FwdFast_Proxy( 
    IEditorDevice __RPC_FAR * This);


void __RPC_STUB IEditorDevice_FwdFast_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IEditorDevice_RevFast_Proxy( 
    IEditorDevice __RPC_FAR * This);


void __RPC_STUB IEditorDevice_RevFast_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IEditorDevice_Select_Proxy( 
    IEditorDevice __RPC_FAR * This,
    BOOL bSelOnBus,
    long __RPC_FAR *plTransportDisableMask);


void __RPC_STUB IEditorDevice_Select_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IEditorDevice_DeSelect_Proxy( 
    IEditorDevice __RPC_FAR * This);


void __RPC_STUB IEditorDevice_DeSelect_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IEditorDevice_Stop_Proxy( 
    IEditorDevice __RPC_FAR * This,
    STrnTimeType __RPC_FAR *pTime);


void __RPC_STUB IEditorDevice_Stop_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IEditorDevice_IsStopped_Proxy( 
    IEditorDevice __RPC_FAR * This);


void __RPC_STUB IEditorDevice_IsStopped_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IEditorDevice_SetStandby_Proxy( 
    IEditorDevice __RPC_FAR * This,
    STrnTimeType __RPC_FAR *pTime,
    DWORD bOn);


void __RPC_STUB IEditorDevice_SetStandby_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IEditorDevice_CueToFrame_Proxy( 
    IEditorDevice __RPC_FAR * This,
    ULONG uFrame);


void __RPC_STUB IEditorDevice_CueToFrame_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IEditorDevice_Eject_Proxy( 
    IEditorDevice __RPC_FAR * This);


void __RPC_STUB IEditorDevice_Eject_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IEditorDevice_ShuttleSpeed_Proxy( 
    IEditorDevice __RPC_FAR * This,
    STrnTimeType __RPC_FAR *pTime,
    long lSpeed);


void __RPC_STUB IEditorDevice_ShuttleSpeed_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IEditorDevice_GetFrame_Proxy( 
    IEditorDevice __RPC_FAR * This,
    ULONG __RPC_FAR *pdwCurFrame);


void __RPC_STUB IEditorDevice_GetFrame_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IEditorDevice_GetTCType_Proxy( 
    IEditorDevice __RPC_FAR * This,
    ULONG __RPC_FAR *pTCType);


void __RPC_STUB IEditorDevice_GetTCType_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IEditorDevice_GetDevType_Proxy( 
    IEditorDevice __RPC_FAR * This,
    LONG __RPC_FAR *plType);


void __RPC_STUB IEditorDevice_GetDevType_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IEditorDevice_GetReel_Proxy( 
    IEditorDevice __RPC_FAR * This,
    /* [string][out] */ LPSTR name,
    DWORD size);


void __RPC_STUB IEditorDevice_GetReel_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


void STDMETHODCALLTYPE IEditorDevice_SetReel_Proxy( 
    IEditorDevice __RPC_FAR * This,
    /* [string][in] */ LPSTR name);


void __RPC_STUB IEditorDevice_SetReel_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


BOOL STDMETHODCALLTYPE IEditorDevice_HasReel_Proxy( 
    IEditorDevice __RPC_FAR * This,
    /* [string][in] */ LPSTR name);


void __RPC_STUB IEditorDevice_HasReel_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IEditorDevice_SetAudLevel_Proxy( 
    IEditorDevice __RPC_FAR * This,
    STrnTimeType __RPC_FAR *pTime,
    long vtrinput,
    ETrnACParamType Param,
    long index,
    STrnPlayList __RPC_FAR *plist);


void __RPC_STUB IEditorDevice_SetAudLevel_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


DWORD STDMETHODCALLTYPE IEditorDevice_GetVidPort_Proxy( 
    IEditorDevice __RPC_FAR * This);


void __RPC_STUB IEditorDevice_GetVidPort_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


DWORD STDMETHODCALLTYPE IEditorDevice_GetAudInput_Proxy( 
    IEditorDevice __RPC_FAR * This,
    DWORD dwChannel);


void __RPC_STUB IEditorDevice_GetAudInput_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


void STDMETHODCALLTYPE IEditorDevice_SetInPoint_Proxy( 
    IEditorDevice __RPC_FAR * This,
    long lIn);


void __RPC_STUB IEditorDevice_SetInPoint_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


void STDMETHODCALLTYPE IEditorDevice_SetOutPoint_Proxy( 
    IEditorDevice __RPC_FAR * This,
    long lOut);


void __RPC_STUB IEditorDevice_SetOutPoint_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


long STDMETHODCALLTYPE IEditorDevice_GetInPoint_Proxy( 
    IEditorDevice __RPC_FAR * This);


void __RPC_STUB IEditorDevice_GetInPoint_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


long STDMETHODCALLTYPE IEditorDevice_GetOutPoint_Proxy( 
    IEditorDevice __RPC_FAR * This);


void __RPC_STUB IEditorDevice_GetOutPoint_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IEditorDevice_Record_Proxy( 
    IEditorDevice __RPC_FAR * This,
    STrnTimeType __RPC_FAR *pTime);


void __RPC_STUB IEditorDevice_Record_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


DWORD STDMETHODCALLTYPE IEditorDevice_GetAudOutput_Proxy( 
    IEditorDevice __RPC_FAR * This,
    DWORD dwChannel);


void __RPC_STUB IEditorDevice_GetAudOutput_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


DWORD STDMETHODCALLTYPE IEditorDevice_GetVidOutput_Proxy( 
    IEditorDevice __RPC_FAR * This);


void __RPC_STUB IEditorDevice_GetVidOutput_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


BOOL STDMETHODCALLTYPE IEditorDevice_IsRecordDeck_Proxy( 
    IEditorDevice __RPC_FAR * This);


void __RPC_STUB IEditorDevice_IsRecordDeck_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


DWORD STDMETHODCALLTYPE IEditorDevice_GetInputComponentMask_Proxy( 
    IEditorDevice __RPC_FAR * This);


void __RPC_STUB IEditorDevice_GetInputComponentMask_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


DWORD STDMETHODCALLTYPE IEditorDevice_GetOutputComponentMask_Proxy( 
    IEditorDevice __RPC_FAR * This);


void __RPC_STUB IEditorDevice_GetOutputComponentMask_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


DWORD STDMETHODCALLTYPE IEditorDevice_GetSerialPort_Proxy( 
    IEditorDevice __RPC_FAR * This);


void __RPC_STUB IEditorDevice_GetSerialPort_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IEditorDevice_INTERFACE_DEFINED__ */


/* Additional Prototypes for ALL interfaces */

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif
