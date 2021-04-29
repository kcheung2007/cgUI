/* this ALWAYS GENERATED file contains the definitions for the interfaces */


/* File created by MIDL compiler version 3.01.75 */
/* at Tue Nov 23 05:28:26 1999
 */
/* Compiler settings for AudioRtr.idl:
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

#ifndef __AudioRtr_h__
#define __AudioRtr_h__

#ifdef __cplusplus
extern "C"{
#endif 

/* Forward Declarations */ 

#ifndef __ITrnAudioDevice_FWD_DEFINED__
#define __ITrnAudioDevice_FWD_DEFINED__
typedef interface ITrnAudioDevice ITrnAudioDevice;
#endif 	/* __ITrnAudioDevice_FWD_DEFINED__ */


#ifndef __ITrnAudioNetwork_FWD_DEFINED__
#define __ITrnAudioNetwork_FWD_DEFINED__
typedef interface ITrnAudioNetwork ITrnAudioNetwork;
#endif 	/* __ITrnAudioNetwork_FWD_DEFINED__ */


#ifndef __ITrnAudioNetworkAdvise_FWD_DEFINED__
#define __ITrnAudioNetworkAdvise_FWD_DEFINED__
typedef interface ITrnAudioNetworkAdvise ITrnAudioNetworkAdvise;
#endif 	/* __ITrnAudioNetworkAdvise_FWD_DEFINED__ */


#ifndef __ITrnAudioDeviceFactory_FWD_DEFINED__
#define __ITrnAudioDeviceFactory_FWD_DEFINED__
typedef interface ITrnAudioDeviceFactory ITrnAudioDeviceFactory;
#endif 	/* __ITrnAudioDeviceFactory_FWD_DEFINED__ */


/* header files for imported files */
#include "wtypes.h"
#include "unknwn.h"
#include "objidl.h"
#include "trnity.h"

void __RPC_FAR * __RPC_USER MIDL_user_allocate(size_t);
void __RPC_USER MIDL_user_free( void __RPC_FAR * ); 

/****************************************
 * Generated header for interface: __MIDL_itf_AudioRtr_0000
 * at Tue Nov 23 05:28:26 1999
 * using MIDL 3.01.75
 ****************************************/
/* [local] */ 


#define OBJREF_AUDIO_NETWORK(n)  OBJREF_TRINITY_ADDON(n,Play.TDMAudio)





extern RPC_IF_HANDLE __MIDL_itf_AudioRtr_0000_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_AudioRtr_0000_v0_0_s_ifspec;

#ifndef __ITrnAudioDevice_INTERFACE_DEFINED__
#define __ITrnAudioDevice_INTERFACE_DEFINED__

/****************************************
 * Generated header for interface: ITrnAudioDevice
 * at Tue Nov 23 05:28:26 1999
 * using MIDL 3.01.75
 ****************************************/
/* [unique][uuid][object][local] */ 


typedef 
enum tagETrnStandardPinId
    {	SPIInput1	= 0,
	SPIInput2	= SPIInput1 + 1,
	SPIInput3	= SPIInput2 + 1,
	SPIInput4	= SPIInput3 + 1,
	SPIInput5	= SPIInput4 + 1,
	SPIInput6	= SPIInput5 + 1,
	SPIInput7	= SPIInput6 + 1,
	SPIInput8	= SPIInput7 + 1,
	SPIProgram1	= 0x100,
	SPIProgram2	= SPIProgram1 + 1,
	SPIMonitor1	= 0x200,
	SPIMonitor2	= SPIMonitor1 + 1,
	SPISend1	= 0x300,
	SPISend2	= SPISend1 + 1,
	SPIOutput1	= 0x100,
	SPIOutput2	= SPIOutput1 + 1,
	SPIOutput3	= SPIOutput2 + 1,
	SPIOutput4	= SPIOutput3 + 1,
	SPIOutput5	= SPIOutput4 + 1,
	SPIOutput6	= SPIOutput5 + 1,
	SPIOutput7	= SPIOutput6 + 1,
	SPIOutput8	= SPIOutput7 + 1,
	SPIRecord1	= 0,
	SPIRecord2	= SPIRecord1 + 1,
	SPIRecord3	= SPIRecord2 + 1,
	SPIRecord4	= SPIRecord3 + 1,
	SPIRecord5	= SPIRecord4 + 1,
	SPIRecord6	= SPIRecord5 + 1,
	SPIRecord7	= SPIRecord6 + 1,
	SPIRecord8	= SPIRecord7 + 1,
	SPIPlay1	= 0x100,
	SPIPlay2	= SPIPlay1 + 1,
	SPIPlay3	= SPIPlay2 + 1,
	SPIPlay4	= SPIPlay3 + 1,
	SPIPlay5	= SPIPlay4 + 1,
	SPIPlay6	= SPIPlay5 + 1,
	SPIPlay7	= SPIPlay6 + 1,
	SPIPlay8	= SPIPlay7 + 1,
	SPIInvalid	= 0xffff
    }	ETrnStandardPinId;

typedef struct  tagSTrnAudioDeviceInfo
    {
    DWORD dwSizeOf;
    DWORD dwDeviceType;
    DWORD dwDeviceInstance;
    DWORD dwDeviceId;
    unsigned int uNumPins;
    unsigned char szDevName[ 64 ];
    }	STrnAudioDeviceInfo;

typedef 
enum tagETrnPinType
    {	PTListener	= 0,
	PTTalker	= PTListener + 1,
	PTTalkSilence	= PTTalker + 1,
	PTTalkTone1k	= PTTalkSilence + 1
    }	ETrnPinType;

typedef 
enum tagETrnPinFlags
    {	PFStereoPair	= 1,
	PFPermanentSlot	= 2,
	PFCantDisable	= 4
    }	ETrnPinFlags;

typedef struct  tagSTrnPinDescriptor
    {
    ETrnPinType ptType;
    DWORD dwPinId;
    DWORD dwFlags;
    unsigned char szPinName[ 64 ];
    }	STrnPinDescriptor;


EXTERN_C const IID IID_ITrnAudioDevice;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    interface DECLSPEC_UUID("8335e640-ab3b-11ce-8468-0000b468276b")
    ITrnAudioDevice : public IUnknown
    {
    public:
        virtual DWORD STDMETHODCALLTYPE QueryInfo( 
            /* [out] */ STrnAudioDeviceInfo __RPC_FAR *pInfo) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE EnumPins( 
            /* [in] */ unsigned int startingIndex,
            /* [in] */ unsigned int numberOfPins,
            /* [out] */ unsigned int __RPC_FAR *pNumFetched,
            /* [out] */ STrnPinDescriptor __RPC_FAR *pstpd) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct ITrnAudioDeviceVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            ITrnAudioDevice __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            ITrnAudioDevice __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            ITrnAudioDevice __RPC_FAR * This);
        
        DWORD ( STDMETHODCALLTYPE __RPC_FAR *QueryInfo )( 
            ITrnAudioDevice __RPC_FAR * This,
            /* [out] */ STrnAudioDeviceInfo __RPC_FAR *pInfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *EnumPins )( 
            ITrnAudioDevice __RPC_FAR * This,
            /* [in] */ unsigned int startingIndex,
            /* [in] */ unsigned int numberOfPins,
            /* [out] */ unsigned int __RPC_FAR *pNumFetched,
            /* [out] */ STrnPinDescriptor __RPC_FAR *pstpd);
        
        END_INTERFACE
    } ITrnAudioDeviceVtbl;

    interface ITrnAudioDevice
    {
        CONST_VTBL struct ITrnAudioDeviceVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ITrnAudioDevice_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define ITrnAudioDevice_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define ITrnAudioDevice_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define ITrnAudioDevice_QueryInfo(This,pInfo)	\
    (This)->lpVtbl -> QueryInfo(This,pInfo)

#define ITrnAudioDevice_EnumPins(This,startingIndex,numberOfPins,pNumFetched,pstpd)	\
    (This)->lpVtbl -> EnumPins(This,startingIndex,numberOfPins,pNumFetched,pstpd)

#endif /* COBJMACROS */


#endif 	/* C style interface */



DWORD STDMETHODCALLTYPE ITrnAudioDevice_QueryInfo_Proxy( 
    ITrnAudioDevice __RPC_FAR * This,
    /* [out] */ STrnAudioDeviceInfo __RPC_FAR *pInfo);


void __RPC_STUB ITrnAudioDevice_QueryInfo_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE ITrnAudioDevice_EnumPins_Proxy( 
    ITrnAudioDevice __RPC_FAR * This,
    /* [in] */ unsigned int startingIndex,
    /* [in] */ unsigned int numberOfPins,
    /* [out] */ unsigned int __RPC_FAR *pNumFetched,
    /* [out] */ STrnPinDescriptor __RPC_FAR *pstpd);


void __RPC_STUB ITrnAudioDevice_EnumPins_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __ITrnAudioDevice_INTERFACE_DEFINED__ */


#ifndef __ITrnAudioNetwork_INTERFACE_DEFINED__
#define __ITrnAudioNetwork_INTERFACE_DEFINED__

/****************************************
 * Generated header for interface: ITrnAudioNetwork
 * at Tue Nov 23 05:28:26 1999
 * using MIDL 3.01.75
 ****************************************/
/* [unique][uuid][object][local] */ 


typedef struct  tagSTrnAudioNode
    {
    DWORD dwDeviceId;
    DWORD dwPinId;
    }	STrnAudioNode;

typedef struct  tagSTrnAudioConnection
    {
    STrnAudioNode source;
    STrnAudioNode dest;
    }	STrnAudioConnection;


EXTERN_C const IID IID_ITrnAudioNetwork;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    interface DECLSPEC_UUID("8335e641-ab3b-11ce-8468-0000b468276b")
    ITrnAudioNetwork : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE EnumDevices( 
            IEnumUnknown __RPC_FAR *__RPC_FAR *ppEnum) = 0;
        
        virtual ULONG STDMETHODCALLTYPE QueryNumConnections( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE EnumConnections( 
            /* [in] */ unsigned int startingIndex,
            /* [in] */ unsigned int numberOfConnections,
            /* [out] */ unsigned int __RPC_FAR *pNumFetched,
            /* [out] */ STrnAudioConnection __RPC_FAR *pstac) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE MakeConnection( 
            /* [in] */ STrnTimeType __RPC_FAR *pTime,
            /* [in] */ STrnAudioNode __RPC_FAR *source,
            /* [in] */ STrnAudioNode __RPC_FAR *dest) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE BreakConnection( 
            /* [in] */ STrnTimeType __RPC_FAR *pTime,
            /* [in] */ STrnAudioNode __RPC_FAR *dest) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Advise( 
            /* [in] */ ITrnAudioNetworkAdvise __RPC_FAR *pAdv) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE UnAdvise( 
            /* [in] */ ITrnAudioNetworkAdvise __RPC_FAR *pAdv) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct ITrnAudioNetworkVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            ITrnAudioNetwork __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            ITrnAudioNetwork __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            ITrnAudioNetwork __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *EnumDevices )( 
            ITrnAudioNetwork __RPC_FAR * This,
            IEnumUnknown __RPC_FAR *__RPC_FAR *ppEnum);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *QueryNumConnections )( 
            ITrnAudioNetwork __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *EnumConnections )( 
            ITrnAudioNetwork __RPC_FAR * This,
            /* [in] */ unsigned int startingIndex,
            /* [in] */ unsigned int numberOfConnections,
            /* [out] */ unsigned int __RPC_FAR *pNumFetched,
            /* [out] */ STrnAudioConnection __RPC_FAR *pstac);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *MakeConnection )( 
            ITrnAudioNetwork __RPC_FAR * This,
            /* [in] */ STrnTimeType __RPC_FAR *pTime,
            /* [in] */ STrnAudioNode __RPC_FAR *source,
            /* [in] */ STrnAudioNode __RPC_FAR *dest);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *BreakConnection )( 
            ITrnAudioNetwork __RPC_FAR * This,
            /* [in] */ STrnTimeType __RPC_FAR *pTime,
            /* [in] */ STrnAudioNode __RPC_FAR *dest);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Advise )( 
            ITrnAudioNetwork __RPC_FAR * This,
            /* [in] */ ITrnAudioNetworkAdvise __RPC_FAR *pAdv);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *UnAdvise )( 
            ITrnAudioNetwork __RPC_FAR * This,
            /* [in] */ ITrnAudioNetworkAdvise __RPC_FAR *pAdv);
        
        END_INTERFACE
    } ITrnAudioNetworkVtbl;

    interface ITrnAudioNetwork
    {
        CONST_VTBL struct ITrnAudioNetworkVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ITrnAudioNetwork_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define ITrnAudioNetwork_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define ITrnAudioNetwork_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define ITrnAudioNetwork_EnumDevices(This,ppEnum)	\
    (This)->lpVtbl -> EnumDevices(This,ppEnum)

#define ITrnAudioNetwork_QueryNumConnections(This)	\
    (This)->lpVtbl -> QueryNumConnections(This)

#define ITrnAudioNetwork_EnumConnections(This,startingIndex,numberOfConnections,pNumFetched,pstac)	\
    (This)->lpVtbl -> EnumConnections(This,startingIndex,numberOfConnections,pNumFetched,pstac)

#define ITrnAudioNetwork_MakeConnection(This,pTime,source,dest)	\
    (This)->lpVtbl -> MakeConnection(This,pTime,source,dest)

#define ITrnAudioNetwork_BreakConnection(This,pTime,dest)	\
    (This)->lpVtbl -> BreakConnection(This,pTime,dest)

#define ITrnAudioNetwork_Advise(This,pAdv)	\
    (This)->lpVtbl -> Advise(This,pAdv)

#define ITrnAudioNetwork_UnAdvise(This,pAdv)	\
    (This)->lpVtbl -> UnAdvise(This,pAdv)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE ITrnAudioNetwork_EnumDevices_Proxy( 
    ITrnAudioNetwork __RPC_FAR * This,
    IEnumUnknown __RPC_FAR *__RPC_FAR *ppEnum);


void __RPC_STUB ITrnAudioNetwork_EnumDevices_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


ULONG STDMETHODCALLTYPE ITrnAudioNetwork_QueryNumConnections_Proxy( 
    ITrnAudioNetwork __RPC_FAR * This);


void __RPC_STUB ITrnAudioNetwork_QueryNumConnections_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE ITrnAudioNetwork_EnumConnections_Proxy( 
    ITrnAudioNetwork __RPC_FAR * This,
    /* [in] */ unsigned int startingIndex,
    /* [in] */ unsigned int numberOfConnections,
    /* [out] */ unsigned int __RPC_FAR *pNumFetched,
    /* [out] */ STrnAudioConnection __RPC_FAR *pstac);


void __RPC_STUB ITrnAudioNetwork_EnumConnections_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE ITrnAudioNetwork_MakeConnection_Proxy( 
    ITrnAudioNetwork __RPC_FAR * This,
    /* [in] */ STrnTimeType __RPC_FAR *pTime,
    /* [in] */ STrnAudioNode __RPC_FAR *source,
    /* [in] */ STrnAudioNode __RPC_FAR *dest);


void __RPC_STUB ITrnAudioNetwork_MakeConnection_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE ITrnAudioNetwork_BreakConnection_Proxy( 
    ITrnAudioNetwork __RPC_FAR * This,
    /* [in] */ STrnTimeType __RPC_FAR *pTime,
    /* [in] */ STrnAudioNode __RPC_FAR *dest);


void __RPC_STUB ITrnAudioNetwork_BreakConnection_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE ITrnAudioNetwork_Advise_Proxy( 
    ITrnAudioNetwork __RPC_FAR * This,
    /* [in] */ ITrnAudioNetworkAdvise __RPC_FAR *pAdv);


void __RPC_STUB ITrnAudioNetwork_Advise_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE ITrnAudioNetwork_UnAdvise_Proxy( 
    ITrnAudioNetwork __RPC_FAR * This,
    /* [in] */ ITrnAudioNetworkAdvise __RPC_FAR *pAdv);


void __RPC_STUB ITrnAudioNetwork_UnAdvise_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __ITrnAudioNetwork_INTERFACE_DEFINED__ */


#ifndef __ITrnAudioNetworkAdvise_INTERFACE_DEFINED__
#define __ITrnAudioNetworkAdvise_INTERFACE_DEFINED__

/****************************************
 * Generated header for interface: ITrnAudioNetworkAdvise
 * at Tue Nov 23 05:28:26 1999
 * using MIDL 3.01.75
 ****************************************/
/* [unique][uuid][object][local] */ 



EXTERN_C const IID IID_ITrnAudioNetworkAdvise;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    interface DECLSPEC_UUID("8335e642-ab3b-11ce-8468-0000b468276b")
    ITrnAudioNetworkAdvise : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE OnConnect( 
            /* [in] */ DWORD dwSystemTime,
            /* [in] */ STrnAudioConnection __RPC_FAR *pstac) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE OnDisconnect( 
            /* [in] */ DWORD dwSystemTime,
            /* [in] */ STrnAudioNode __RPC_FAR *pstan) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct ITrnAudioNetworkAdviseVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            ITrnAudioNetworkAdvise __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            ITrnAudioNetworkAdvise __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            ITrnAudioNetworkAdvise __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *OnConnect )( 
            ITrnAudioNetworkAdvise __RPC_FAR * This,
            /* [in] */ DWORD dwSystemTime,
            /* [in] */ STrnAudioConnection __RPC_FAR *pstac);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *OnDisconnect )( 
            ITrnAudioNetworkAdvise __RPC_FAR * This,
            /* [in] */ DWORD dwSystemTime,
            /* [in] */ STrnAudioNode __RPC_FAR *pstan);
        
        END_INTERFACE
    } ITrnAudioNetworkAdviseVtbl;

    interface ITrnAudioNetworkAdvise
    {
        CONST_VTBL struct ITrnAudioNetworkAdviseVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ITrnAudioNetworkAdvise_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define ITrnAudioNetworkAdvise_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define ITrnAudioNetworkAdvise_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define ITrnAudioNetworkAdvise_OnConnect(This,dwSystemTime,pstac)	\
    (This)->lpVtbl -> OnConnect(This,dwSystemTime,pstac)

#define ITrnAudioNetworkAdvise_OnDisconnect(This,dwSystemTime,pstan)	\
    (This)->lpVtbl -> OnDisconnect(This,dwSystemTime,pstan)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE ITrnAudioNetworkAdvise_OnConnect_Proxy( 
    ITrnAudioNetworkAdvise __RPC_FAR * This,
    /* [in] */ DWORD dwSystemTime,
    /* [in] */ STrnAudioConnection __RPC_FAR *pstac);


void __RPC_STUB ITrnAudioNetworkAdvise_OnConnect_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE ITrnAudioNetworkAdvise_OnDisconnect_Proxy( 
    ITrnAudioNetworkAdvise __RPC_FAR * This,
    /* [in] */ DWORD dwSystemTime,
    /* [in] */ STrnAudioNode __RPC_FAR *pstan);


void __RPC_STUB ITrnAudioNetworkAdvise_OnDisconnect_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __ITrnAudioNetworkAdvise_INTERFACE_DEFINED__ */


#ifndef __ITrnAudioDeviceFactory_INTERFACE_DEFINED__
#define __ITrnAudioDeviceFactory_INTERFACE_DEFINED__

/****************************************
 * Generated header for interface: ITrnAudioDeviceFactory
 * at Tue Nov 23 05:28:26 1999
 * using MIDL 3.01.75
 ****************************************/
/* [unique][uuid][object][local] */ 



EXTERN_C const IID IID_ITrnAudioDeviceFactory;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    interface DECLSPEC_UUID("8335e643-ab3b-11ce-8468-0000b468276b")
    ITrnAudioDeviceFactory : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE Create( 
            /* [in] */ ITrnConnection __RPC_FAR *pTC,
            /* [in] */ DWORD dwListenSocket,
            /* [in] */ DWORD dwDeviceId,
            /* [in] */ unsigned int type,
            /* [in] */ unsigned int instance,
            /* [in] */ HKEY hkModule,
            /* [in] */ REFIID riid,
            /* [out] */ void __RPC_FAR *__RPC_FAR *ppv) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct ITrnAudioDeviceFactoryVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            ITrnAudioDeviceFactory __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            ITrnAudioDeviceFactory __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            ITrnAudioDeviceFactory __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Create )( 
            ITrnAudioDeviceFactory __RPC_FAR * This,
            /* [in] */ ITrnConnection __RPC_FAR *pTC,
            /* [in] */ DWORD dwListenSocket,
            /* [in] */ DWORD dwDeviceId,
            /* [in] */ unsigned int type,
            /* [in] */ unsigned int instance,
            /* [in] */ HKEY hkModule,
            /* [in] */ REFIID riid,
            /* [out] */ void __RPC_FAR *__RPC_FAR *ppv);
        
        END_INTERFACE
    } ITrnAudioDeviceFactoryVtbl;

    interface ITrnAudioDeviceFactory
    {
        CONST_VTBL struct ITrnAudioDeviceFactoryVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ITrnAudioDeviceFactory_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define ITrnAudioDeviceFactory_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define ITrnAudioDeviceFactory_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define ITrnAudioDeviceFactory_Create(This,pTC,dwListenSocket,dwDeviceId,type,instance,hkModule,riid,ppv)	\
    (This)->lpVtbl -> Create(This,pTC,dwListenSocket,dwDeviceId,type,instance,hkModule,riid,ppv)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE ITrnAudioDeviceFactory_Create_Proxy( 
    ITrnAudioDeviceFactory __RPC_FAR * This,
    /* [in] */ ITrnConnection __RPC_FAR *pTC,
    /* [in] */ DWORD dwListenSocket,
    /* [in] */ DWORD dwDeviceId,
    /* [in] */ unsigned int type,
    /* [in] */ unsigned int instance,
    /* [in] */ HKEY hkModule,
    /* [in] */ REFIID riid,
    /* [out] */ void __RPC_FAR *__RPC_FAR *ppv);


void __RPC_STUB ITrnAudioDeviceFactory_Create_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __ITrnAudioDeviceFactory_INTERFACE_DEFINED__ */


/* Additional Prototypes for ALL interfaces */

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif
