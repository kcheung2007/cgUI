/* this ALWAYS GENERATED file contains the definitions for the interfaces */


/* File created by MIDL compiler version 3.01.75 */
/* at Tue Nov 23 05:28:27 1999
 */
/* Compiler settings for cfgman.idl:
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

#ifndef __cfgman_h__
#define __cfgman_h__

#ifdef __cplusplus
extern "C"{
#endif 

/* Forward Declarations */ 

#ifndef __ICfgManAdviseSink_FWD_DEFINED__
#define __ICfgManAdviseSink_FWD_DEFINED__
typedef interface ICfgManAdviseSink ICfgManAdviseSink;
#endif 	/* __ICfgManAdviseSink_FWD_DEFINED__ */


#ifndef __ITrnConfigManager_FWD_DEFINED__
#define __ITrnConfigManager_FWD_DEFINED__
typedef interface ITrnConfigManager ITrnConfigManager;
#endif 	/* __ITrnConfigManager_FWD_DEFINED__ */


/* header files for imported files */
#include "unknwn.h"

void __RPC_FAR * __RPC_USER MIDL_user_allocate(size_t);
void __RPC_USER MIDL_user_free( void __RPC_FAR * ); 

/****************************************
 * Generated header for interface: __MIDL_itf_cfgman_0000
 * at Tue Nov 23 05:28:27 1999
 * using MIDL 3.01.75
 ****************************************/
/* [local] */ 



interface IPlayPanel;

interface IPlayPagedPanel;

interface ITrnVideoSystem;

interface IPlayStringList;


extern RPC_IF_HANDLE __MIDL_itf_cfgman_0000_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_cfgman_0000_v0_0_s_ifspec;

#ifndef __ICfgManAdviseSink_INTERFACE_DEFINED__
#define __ICfgManAdviseSink_INTERFACE_DEFINED__

/****************************************
 * Generated header for interface: ICfgManAdviseSink
 * at Tue Nov 23 05:28:27 1999
 * using MIDL 3.01.75
 ****************************************/
/* [uuid][object][local] */ 



EXTERN_C const IID IID_ICfgManAdviseSink;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    interface DECLSPEC_UUID("8335e492-ab3b-11ce-8468-0000b468276b")
    ICfgManAdviseSink : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE CanRemoveDevice( 
            DWORD dwSerialPortNum) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE OnRemoveDevice( 
            DWORD dwSerialPortNum) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE CanChangeConnections( 
            DWORD dwSerialPortNum) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE OnConnectionsChange( 
            DWORD dwSerialPortNum) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE OnNewDevice( 
            DWORD dwSerialPortNum) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE OnSettingsChange( 
            DWORD dwSerialPortNum) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct ICfgManAdviseSinkVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            ICfgManAdviseSink __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            ICfgManAdviseSink __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            ICfgManAdviseSink __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *CanRemoveDevice )( 
            ICfgManAdviseSink __RPC_FAR * This,
            DWORD dwSerialPortNum);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *OnRemoveDevice )( 
            ICfgManAdviseSink __RPC_FAR * This,
            DWORD dwSerialPortNum);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *CanChangeConnections )( 
            ICfgManAdviseSink __RPC_FAR * This,
            DWORD dwSerialPortNum);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *OnConnectionsChange )( 
            ICfgManAdviseSink __RPC_FAR * This,
            DWORD dwSerialPortNum);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *OnNewDevice )( 
            ICfgManAdviseSink __RPC_FAR * This,
            DWORD dwSerialPortNum);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *OnSettingsChange )( 
            ICfgManAdviseSink __RPC_FAR * This,
            DWORD dwSerialPortNum);
        
        END_INTERFACE
    } ICfgManAdviseSinkVtbl;

    interface ICfgManAdviseSink
    {
        CONST_VTBL struct ICfgManAdviseSinkVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ICfgManAdviseSink_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define ICfgManAdviseSink_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define ICfgManAdviseSink_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define ICfgManAdviseSink_CanRemoveDevice(This,dwSerialPortNum)	\
    (This)->lpVtbl -> CanRemoveDevice(This,dwSerialPortNum)

#define ICfgManAdviseSink_OnRemoveDevice(This,dwSerialPortNum)	\
    (This)->lpVtbl -> OnRemoveDevice(This,dwSerialPortNum)

#define ICfgManAdviseSink_CanChangeConnections(This,dwSerialPortNum)	\
    (This)->lpVtbl -> CanChangeConnections(This,dwSerialPortNum)

#define ICfgManAdviseSink_OnConnectionsChange(This,dwSerialPortNum)	\
    (This)->lpVtbl -> OnConnectionsChange(This,dwSerialPortNum)

#define ICfgManAdviseSink_OnNewDevice(This,dwSerialPortNum)	\
    (This)->lpVtbl -> OnNewDevice(This,dwSerialPortNum)

#define ICfgManAdviseSink_OnSettingsChange(This,dwSerialPortNum)	\
    (This)->lpVtbl -> OnSettingsChange(This,dwSerialPortNum)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE ICfgManAdviseSink_CanRemoveDevice_Proxy( 
    ICfgManAdviseSink __RPC_FAR * This,
    DWORD dwSerialPortNum);


void __RPC_STUB ICfgManAdviseSink_CanRemoveDevice_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE ICfgManAdviseSink_OnRemoveDevice_Proxy( 
    ICfgManAdviseSink __RPC_FAR * This,
    DWORD dwSerialPortNum);


void __RPC_STUB ICfgManAdviseSink_OnRemoveDevice_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE ICfgManAdviseSink_CanChangeConnections_Proxy( 
    ICfgManAdviseSink __RPC_FAR * This,
    DWORD dwSerialPortNum);


void __RPC_STUB ICfgManAdviseSink_CanChangeConnections_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE ICfgManAdviseSink_OnConnectionsChange_Proxy( 
    ICfgManAdviseSink __RPC_FAR * This,
    DWORD dwSerialPortNum);


void __RPC_STUB ICfgManAdviseSink_OnConnectionsChange_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE ICfgManAdviseSink_OnNewDevice_Proxy( 
    ICfgManAdviseSink __RPC_FAR * This,
    DWORD dwSerialPortNum);


void __RPC_STUB ICfgManAdviseSink_OnNewDevice_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE ICfgManAdviseSink_OnSettingsChange_Proxy( 
    ICfgManAdviseSink __RPC_FAR * This,
    DWORD dwSerialPortNum);


void __RPC_STUB ICfgManAdviseSink_OnSettingsChange_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __ICfgManAdviseSink_INTERFACE_DEFINED__ */


#ifndef __ITrnConfigManager_INTERFACE_DEFINED__
#define __ITrnConfigManager_INTERFACE_DEFINED__

/****************************************
 * Generated header for interface: ITrnConfigManager
 * at Tue Nov 23 05:28:27 1999
 * using MIDL 3.01.75
 ****************************************/
/* [uuid][object][local] */ 



EXTERN_C const IID IID_ITrnConfigManager;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    interface DECLSPEC_UUID("8335e490-ab3b-11ce-8468-0000b468276b")
    ITrnConfigManager : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE Initialize( 
            ITrnVideoSystem __RPC_FAR *pVidSys,
            ICfgManAdviseSink __RPC_FAR *pAdvise) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE AddToPanel( 
            IPlayPanel __RPC_FAR *pPanel) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE UnadviseControls( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Uninitialize( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE AddToPagedPanel( 
            IPlayPagedPanel __RPC_FAR *pPanel,
            DWORD dwSerialPage,
            DWORD dwInputsPage) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE StoreRevertInfo( 
            DWORD dwPageID) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Revert( 
            DWORD dwPageID) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE MakeHardwareList( 
            IPlayStringList __RPC_FAR *pStrList,
            LONG flags) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct ITrnConfigManagerVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            ITrnConfigManager __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            ITrnConfigManager __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            ITrnConfigManager __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Initialize )( 
            ITrnConfigManager __RPC_FAR * This,
            ITrnVideoSystem __RPC_FAR *pVidSys,
            ICfgManAdviseSink __RPC_FAR *pAdvise);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *AddToPanel )( 
            ITrnConfigManager __RPC_FAR * This,
            IPlayPanel __RPC_FAR *pPanel);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *UnadviseControls )( 
            ITrnConfigManager __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Uninitialize )( 
            ITrnConfigManager __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *AddToPagedPanel )( 
            ITrnConfigManager __RPC_FAR * This,
            IPlayPagedPanel __RPC_FAR *pPanel,
            DWORD dwSerialPage,
            DWORD dwInputsPage);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *StoreRevertInfo )( 
            ITrnConfigManager __RPC_FAR * This,
            DWORD dwPageID);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Revert )( 
            ITrnConfigManager __RPC_FAR * This,
            DWORD dwPageID);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *MakeHardwareList )( 
            ITrnConfigManager __RPC_FAR * This,
            IPlayStringList __RPC_FAR *pStrList,
            LONG flags);
        
        END_INTERFACE
    } ITrnConfigManagerVtbl;

    interface ITrnConfigManager
    {
        CONST_VTBL struct ITrnConfigManagerVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ITrnConfigManager_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define ITrnConfigManager_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define ITrnConfigManager_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define ITrnConfigManager_Initialize(This,pVidSys,pAdvise)	\
    (This)->lpVtbl -> Initialize(This,pVidSys,pAdvise)

#define ITrnConfigManager_AddToPanel(This,pPanel)	\
    (This)->lpVtbl -> AddToPanel(This,pPanel)

#define ITrnConfigManager_UnadviseControls(This)	\
    (This)->lpVtbl -> UnadviseControls(This)

#define ITrnConfigManager_Uninitialize(This)	\
    (This)->lpVtbl -> Uninitialize(This)

#define ITrnConfigManager_AddToPagedPanel(This,pPanel,dwSerialPage,dwInputsPage)	\
    (This)->lpVtbl -> AddToPagedPanel(This,pPanel,dwSerialPage,dwInputsPage)

#define ITrnConfigManager_StoreRevertInfo(This,dwPageID)	\
    (This)->lpVtbl -> StoreRevertInfo(This,dwPageID)

#define ITrnConfigManager_Revert(This,dwPageID)	\
    (This)->lpVtbl -> Revert(This,dwPageID)

#define ITrnConfigManager_MakeHardwareList(This,pStrList,flags)	\
    (This)->lpVtbl -> MakeHardwareList(This,pStrList,flags)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE ITrnConfigManager_Initialize_Proxy( 
    ITrnConfigManager __RPC_FAR * This,
    ITrnVideoSystem __RPC_FAR *pVidSys,
    ICfgManAdviseSink __RPC_FAR *pAdvise);


void __RPC_STUB ITrnConfigManager_Initialize_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE ITrnConfigManager_AddToPanel_Proxy( 
    ITrnConfigManager __RPC_FAR * This,
    IPlayPanel __RPC_FAR *pPanel);


void __RPC_STUB ITrnConfigManager_AddToPanel_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE ITrnConfigManager_UnadviseControls_Proxy( 
    ITrnConfigManager __RPC_FAR * This);


void __RPC_STUB ITrnConfigManager_UnadviseControls_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE ITrnConfigManager_Uninitialize_Proxy( 
    ITrnConfigManager __RPC_FAR * This);


void __RPC_STUB ITrnConfigManager_Uninitialize_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE ITrnConfigManager_AddToPagedPanel_Proxy( 
    ITrnConfigManager __RPC_FAR * This,
    IPlayPagedPanel __RPC_FAR *pPanel,
    DWORD dwSerialPage,
    DWORD dwInputsPage);


void __RPC_STUB ITrnConfigManager_AddToPagedPanel_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE ITrnConfigManager_StoreRevertInfo_Proxy( 
    ITrnConfigManager __RPC_FAR * This,
    DWORD dwPageID);


void __RPC_STUB ITrnConfigManager_StoreRevertInfo_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE ITrnConfigManager_Revert_Proxy( 
    ITrnConfigManager __RPC_FAR * This,
    DWORD dwPageID);


void __RPC_STUB ITrnConfigManager_Revert_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE ITrnConfigManager_MakeHardwareList_Proxy( 
    ITrnConfigManager __RPC_FAR * This,
    IPlayStringList __RPC_FAR *pStrList,
    LONG flags);


void __RPC_STUB ITrnConfigManager_MakeHardwareList_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __ITrnConfigManager_INTERFACE_DEFINED__ */


/* Additional Prototypes for ALL interfaces */

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif
