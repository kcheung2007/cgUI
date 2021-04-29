/* this ALWAYS GENERATED file contains the definitions for the interfaces */


/* File created by MIDL compiler version 3.01.75 */
/* at Tue Nov 23 05:28:38 1999
 */
/* Compiler settings for trnoem.idl:
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

#ifndef __trnoem_h__
#define __trnoem_h__

#ifdef __cplusplus
extern "C"{
#endif 

/* Forward Declarations */ 

#ifndef __ITrnConnectionClient_FWD_DEFINED__
#define __ITrnConnectionClient_FWD_DEFINED__
typedef interface ITrnConnectionClient ITrnConnectionClient;
#endif 	/* __ITrnConnectionClient_FWD_DEFINED__ */


#ifndef __ITrnConnection_FWD_DEFINED__
#define __ITrnConnection_FWD_DEFINED__
typedef interface ITrnConnection ITrnConnection;
#endif 	/* __ITrnConnection_FWD_DEFINED__ */


#ifndef __ITrnConnection2_FWD_DEFINED__
#define __ITrnConnection2_FWD_DEFINED__
typedef interface ITrnConnection2 ITrnConnection2;
#endif 	/* __ITrnConnection2_FWD_DEFINED__ */


#ifndef __ITrnConnectionControl_FWD_DEFINED__
#define __ITrnConnectionControl_FWD_DEFINED__
typedef interface ITrnConnectionControl ITrnConnectionControl;
#endif 	/* __ITrnConnectionControl_FWD_DEFINED__ */


#ifndef __ITrnConnectionControl2_FWD_DEFINED__
#define __ITrnConnectionControl2_FWD_DEFINED__
typedef interface ITrnConnectionControl2 ITrnConnectionControl2;
#endif 	/* __ITrnConnectionControl2_FWD_DEFINED__ */


#ifndef __ILockMemory_FWD_DEFINED__
#define __ILockMemory_FWD_DEFINED__
typedef interface ILockMemory ILockMemory;
#endif 	/* __ILockMemory_FWD_DEFINED__ */


/* header files for imported files */
#include "wtypes.h"
#include "unknwn.h"
#include "objidl.h"
#include "autoct.h"

void __RPC_FAR * __RPC_USER MIDL_user_allocate(size_t);
void __RPC_USER MIDL_user_free( void __RPC_FAR * ); 

/****************************************
 * Generated header for interface: __MIDL_itf_trnoem_0000
 * at Tue Nov 23 05:28:38 1999
 * using MIDL 3.01.75
 ****************************************/
/* [local] */ 


#define NUM_MAIN_SLOTS    15
#define NUM_INPUT_SLOTS   7
#define NUM_INOUT_SLOTS   5
#define NUM_SERIAL_PORTS  16
/* Trinity busses (idealized - not actual hardware config) */
#define BUS_MAIN      0
#define BUS_INPUT     1
#define BUS_INOUT     2
#define BUS_INTERNAL  3
#define BUS_SERIAL    4
/* Internal 'bus' slot constants */
#define SLOT_SWITCHER 0
#define SLOT_ROUTER   1
#define SLOT_MIXER    2
#define SLOT_TIMELINE 3
#define SLOT_KERNEL   4




extern RPC_IF_HANDLE __MIDL_itf_trnoem_0000_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_trnoem_0000_v0_0_s_ifspec;

#ifndef __ITrnConnectionClient_INTERFACE_DEFINED__
#define __ITrnConnectionClient_INTERFACE_DEFINED__

/****************************************
 * Generated header for interface: ITrnConnectionClient
 * at Tue Nov 23 05:28:38 1999
 * using MIDL 3.01.75
 ****************************************/
/* [unique][uuid][object][local] */ 


typedef struct tagSTrnMessageHeader __RPC_FAR *PSTrnMessageHeader;


EXTERN_C const IID IID_ITrnConnectionClient;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    interface DECLSPEC_UUID("8335e3ed-ab3b-11ce-8468-0000b468276b")
    ITrnConnectionClient : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE OnAsyncReceive( 
            /* [in] */ LPVOID pBuffer,
            /* [in] */ DWORD socketNumber,
            /* [in] */ BOOL repeated) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE OnAsyncMessage( 
            /* [in] */ PSTrnMessageHeader pBuffer,
            /* [in] */ BOOL repeated) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE OnAsyncError( 
            /* [in] */ LPVOID pBuffer,
            /* [in] */ DWORD socketNumber,
            /* [in] */ DWORD ErrCode) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetupSyncImageBlock( 
            /* [in] */ DWORD socketNumber,
            /* [in] */ DWORD offset,
            /* [in] */ DWORD remainder,
            /* [out][in] */ LPDWORD blockSize) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct ITrnConnectionClientVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            ITrnConnectionClient __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            ITrnConnectionClient __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            ITrnConnectionClient __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *OnAsyncReceive )( 
            ITrnConnectionClient __RPC_FAR * This,
            /* [in] */ LPVOID pBuffer,
            /* [in] */ DWORD socketNumber,
            /* [in] */ BOOL repeated);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *OnAsyncMessage )( 
            ITrnConnectionClient __RPC_FAR * This,
            /* [in] */ PSTrnMessageHeader pBuffer,
            /* [in] */ BOOL repeated);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *OnAsyncError )( 
            ITrnConnectionClient __RPC_FAR * This,
            /* [in] */ LPVOID pBuffer,
            /* [in] */ DWORD socketNumber,
            /* [in] */ DWORD ErrCode);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetupSyncImageBlock )( 
            ITrnConnectionClient __RPC_FAR * This,
            /* [in] */ DWORD socketNumber,
            /* [in] */ DWORD offset,
            /* [in] */ DWORD remainder,
            /* [out][in] */ LPDWORD blockSize);
        
        END_INTERFACE
    } ITrnConnectionClientVtbl;

    interface ITrnConnectionClient
    {
        CONST_VTBL struct ITrnConnectionClientVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ITrnConnectionClient_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define ITrnConnectionClient_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define ITrnConnectionClient_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define ITrnConnectionClient_OnAsyncReceive(This,pBuffer,socketNumber,repeated)	\
    (This)->lpVtbl -> OnAsyncReceive(This,pBuffer,socketNumber,repeated)

#define ITrnConnectionClient_OnAsyncMessage(This,pBuffer,repeated)	\
    (This)->lpVtbl -> OnAsyncMessage(This,pBuffer,repeated)

#define ITrnConnectionClient_OnAsyncError(This,pBuffer,socketNumber,ErrCode)	\
    (This)->lpVtbl -> OnAsyncError(This,pBuffer,socketNumber,ErrCode)

#define ITrnConnectionClient_SetupSyncImageBlock(This,socketNumber,offset,remainder,blockSize)	\
    (This)->lpVtbl -> SetupSyncImageBlock(This,socketNumber,offset,remainder,blockSize)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE ITrnConnectionClient_OnAsyncReceive_Proxy( 
    ITrnConnectionClient __RPC_FAR * This,
    /* [in] */ LPVOID pBuffer,
    /* [in] */ DWORD socketNumber,
    /* [in] */ BOOL repeated);


void __RPC_STUB ITrnConnectionClient_OnAsyncReceive_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE ITrnConnectionClient_OnAsyncMessage_Proxy( 
    ITrnConnectionClient __RPC_FAR * This,
    /* [in] */ PSTrnMessageHeader pBuffer,
    /* [in] */ BOOL repeated);


void __RPC_STUB ITrnConnectionClient_OnAsyncMessage_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE ITrnConnectionClient_OnAsyncError_Proxy( 
    ITrnConnectionClient __RPC_FAR * This,
    /* [in] */ LPVOID pBuffer,
    /* [in] */ DWORD socketNumber,
    /* [in] */ DWORD ErrCode);


void __RPC_STUB ITrnConnectionClient_OnAsyncError_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE ITrnConnectionClient_SetupSyncImageBlock_Proxy( 
    ITrnConnectionClient __RPC_FAR * This,
    /* [in] */ DWORD socketNumber,
    /* [in] */ DWORD offset,
    /* [in] */ DWORD remainder,
    /* [out][in] */ LPDWORD blockSize);


void __RPC_STUB ITrnConnectionClient_SetupSyncImageBlock_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __ITrnConnectionClient_INTERFACE_DEFINED__ */


/****************************************
 * Generated header for interface: __MIDL_itf_trnoem_0073
 * at Tue Nov 23 05:28:38 1999
 * using MIDL 3.01.75
 ****************************************/
/* [local] */ 


#define CONNECT_SIMULATION   0
#define CONNECT_VIDEONET     1


extern RPC_IF_HANDLE __MIDL_itf_trnoem_0073_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_trnoem_0073_v0_0_s_ifspec;

#ifndef __ITrnConnection_INTERFACE_DEFINED__
#define __ITrnConnection_INTERFACE_DEFINED__

/****************************************
 * Generated header for interface: ITrnConnection
 * at Tue Nov 23 05:28:38 1999
 * using MIDL 3.01.75
 ****************************************/
/* [unique][uuid][object][local] */ 


typedef struct  tagSTrnMessageHeader
    {
    ULONG DestSocket;
    ULONG ReplySocket;
    ULONG DataLength;
    }	STrnMessageHeader;

typedef struct  tagSTrnDmaWindow
    {
    LPVOID base;
    DWORD height;
    DWORD width;
    LONG stride;
    }	STrnDmaWindow;


EXTERN_C const IID IID_ITrnConnection;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    interface DECLSPEC_UUID("8335e3ee-ab3b-11ce-8468-0000b468276b")
    ITrnConnection : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE GetConnectionInfo( 
            /* [out] */ ULONG __RPC_FAR *pVersion,
            /* [out] */ ULONG __RPC_FAR *pType) = 0;
        
        virtual ULONG STDMETHODCALLTYPE GetUniqueSocketNumber( void) = 0;
        
        virtual ULONG STDMETHODCALLTYPE GetListenSocketForSlot( 
            ULONG bus,
            ULONG slot) = 0;
        
        virtual void STDMETHODCALLTYPE GetSlotFromSocket( 
            /* [in] */ ULONG Socket,
            /* [out] */ ULONG __RPC_FAR *pBus,
            /* [out] */ ULONG __RPC_FAR *pSlot) = 0;
        
        virtual ULONG STDMETHODCALLTYPE GetMaxMsgSize( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetMsgBuffer( 
            /* [out][in] */ DWORD __RPC_FAR *pBuffSize,
            /* [out] */ PSTrnMessageHeader __RPC_FAR *ppBuffer) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetDMABuffer( 
            /* [out][in] */ DWORD __RPC_FAR *pBuffSize,
            /* [out] */ LPVOID __RPC_FAR *ppBuffer) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE FreeBuffer( 
            /* [in] */ LPVOID pBuffer) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetTimeout( 
            /* [in] */ ULONG Timeout) = 0;
        
        virtual ULONG STDMETHODCALLTYPE GetTimeout( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE TransactMessage( 
            PSTrnMessageHeader pSendBuffer,
            PSTrnMessageHeader pRcvBuffer,
            ULONG rcvBuffSize,
            ULONG Timeout) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SendMessage( 
            PSTrnMessageHeader pBuffer) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE WaitMessage( 
            PSTrnMessageHeader pBuffer,
            ULONG buffSize,
            ULONG Timeout,
            ULONG waitSocket) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE AsyncWaitMessage( 
            PSTrnMessageHeader pBuffer,
            ULONG buffSize,
            ULONG Timeout,
            ULONG waitSocket,
            BOOL repeated,
            ITrnConnectionClient __RPC_FAR *pCaller) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SyncSendImageMemory( 
            LPVOID start,
            ULONG size,
            DWORD targetAddress,
            BOOL swapBytes) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SyncSendImageStream( 
            IStream __RPC_FAR *pStream,
            ULONG size,
            DWORD targetAddress,
            BOOL swapBytes) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SyncSendImageFile( 
            HANDLE hFile,
            ULONG size,
            DWORD targetAddress,
            BOOL swapBytes) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SyncSendImageFileMapping( 
            HANDLE hMap,
            ULONG offset,
            ULONG size,
            DWORD targetAddress,
            BOOL swapBytes) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE AsyncGetImageMemory( 
            LPVOID start,
            ULONG size,
            DWORD socketNumber,
            BOOL repeated,
            BOOL swapBytes,
            ITrnConnectionClient __RPC_FAR *pCaller) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE AsyncGetImageFileMapping( 
            HANDLE hMap,
            ULONG offset,
            ULONG size,
            DWORD socketNumber,
            BOOL repeated,
            BOOL swapBytes,
            ITrnConnectionClient __RPC_FAR *pCaller) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SyncGetImageMemory( 
            LPVOID buffer,
            ULONG size,
            DWORD socketNumber,
            BOOL swapBytes,
            ITrnConnectionClient __RPC_FAR *pCaller) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SyncGetImageFileMapping( 
            HANDLE hMap,
            ULONG offset,
            ULONG size,
            DWORD socketNumber,
            BOOL swapBytes,
            ITrnConnectionClient __RPC_FAR *pCaller) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SyncGetImageStream( 
            IStream __RPC_FAR *pStream,
            ULONG size,
            DWORD socketNumber,
            BOOL swapBytes,
            ITrnConnectionClient __RPC_FAR *pCaller) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SyncGetImageFile( 
            HANDLE hFile,
            ULONG size,
            DWORD socketNumber,
            BOOL swapBytes,
            ITrnConnectionClient __RPC_FAR *pCaller) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SyncReadMemory( 
            DWORD socketNum,
            DWORD sourceAddress,
            DWORD alignment,
            DWORD size,
            LPVOID pBuffer) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SyncWriteMemory( 
            DWORD socketNum,
            DWORD destAddress,
            DWORD alignment,
            DWORD size,
            LPVOID pBuffer) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE CancelAsyncTransfer( 
            DWORD socketNumber) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE WaitVBlank( 
            /* [out] */ LPDWORD pLocalTime) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE LockWindowBuffer( 
            STrnDmaWindow __RPC_FAR *pWindows,
            DWORD nWindows,
            DWORD __RPC_FAR *pdwBufferId) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE UnlockWindowBuffer( 
            DWORD dwBufferId) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SyncSendImageMemoryWindow( 
            DWORD dwBufferId,
            DWORD socketNumber,
            DWORD targetAddress,
            BOOL swapBytes) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE AsyncGetImageMemoryWindow( 
            DWORD dwBufferId,
            DWORD socketNumber,
            BOOL repeated,
            BOOL swapBytes,
            ITrnConnectionClient __RPC_FAR *pCaller) = 0;
        
        virtual ULONG STDMETHODCALLTYPE GetApplicationTag( void) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct ITrnConnectionVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            ITrnConnection __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            ITrnConnection __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            ITrnConnection __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetConnectionInfo )( 
            ITrnConnection __RPC_FAR * This,
            /* [out] */ ULONG __RPC_FAR *pVersion,
            /* [out] */ ULONG __RPC_FAR *pType);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *GetUniqueSocketNumber )( 
            ITrnConnection __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *GetListenSocketForSlot )( 
            ITrnConnection __RPC_FAR * This,
            ULONG bus,
            ULONG slot);
        
        void ( STDMETHODCALLTYPE __RPC_FAR *GetSlotFromSocket )( 
            ITrnConnection __RPC_FAR * This,
            /* [in] */ ULONG Socket,
            /* [out] */ ULONG __RPC_FAR *pBus,
            /* [out] */ ULONG __RPC_FAR *pSlot);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *GetMaxMsgSize )( 
            ITrnConnection __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetMsgBuffer )( 
            ITrnConnection __RPC_FAR * This,
            /* [out][in] */ DWORD __RPC_FAR *pBuffSize,
            /* [out] */ PSTrnMessageHeader __RPC_FAR *ppBuffer);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetDMABuffer )( 
            ITrnConnection __RPC_FAR * This,
            /* [out][in] */ DWORD __RPC_FAR *pBuffSize,
            /* [out] */ LPVOID __RPC_FAR *ppBuffer);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *FreeBuffer )( 
            ITrnConnection __RPC_FAR * This,
            /* [in] */ LPVOID pBuffer);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetTimeout )( 
            ITrnConnection __RPC_FAR * This,
            /* [in] */ ULONG Timeout);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *GetTimeout )( 
            ITrnConnection __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *TransactMessage )( 
            ITrnConnection __RPC_FAR * This,
            PSTrnMessageHeader pSendBuffer,
            PSTrnMessageHeader pRcvBuffer,
            ULONG rcvBuffSize,
            ULONG Timeout);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SendMessage )( 
            ITrnConnection __RPC_FAR * This,
            PSTrnMessageHeader pBuffer);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *WaitMessage )( 
            ITrnConnection __RPC_FAR * This,
            PSTrnMessageHeader pBuffer,
            ULONG buffSize,
            ULONG Timeout,
            ULONG waitSocket);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *AsyncWaitMessage )( 
            ITrnConnection __RPC_FAR * This,
            PSTrnMessageHeader pBuffer,
            ULONG buffSize,
            ULONG Timeout,
            ULONG waitSocket,
            BOOL repeated,
            ITrnConnectionClient __RPC_FAR *pCaller);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SyncSendImageMemory )( 
            ITrnConnection __RPC_FAR * This,
            LPVOID start,
            ULONG size,
            DWORD targetAddress,
            BOOL swapBytes);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SyncSendImageStream )( 
            ITrnConnection __RPC_FAR * This,
            IStream __RPC_FAR *pStream,
            ULONG size,
            DWORD targetAddress,
            BOOL swapBytes);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SyncSendImageFile )( 
            ITrnConnection __RPC_FAR * This,
            HANDLE hFile,
            ULONG size,
            DWORD targetAddress,
            BOOL swapBytes);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SyncSendImageFileMapping )( 
            ITrnConnection __RPC_FAR * This,
            HANDLE hMap,
            ULONG offset,
            ULONG size,
            DWORD targetAddress,
            BOOL swapBytes);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *AsyncGetImageMemory )( 
            ITrnConnection __RPC_FAR * This,
            LPVOID start,
            ULONG size,
            DWORD socketNumber,
            BOOL repeated,
            BOOL swapBytes,
            ITrnConnectionClient __RPC_FAR *pCaller);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *AsyncGetImageFileMapping )( 
            ITrnConnection __RPC_FAR * This,
            HANDLE hMap,
            ULONG offset,
            ULONG size,
            DWORD socketNumber,
            BOOL repeated,
            BOOL swapBytes,
            ITrnConnectionClient __RPC_FAR *pCaller);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SyncGetImageMemory )( 
            ITrnConnection __RPC_FAR * This,
            LPVOID buffer,
            ULONG size,
            DWORD socketNumber,
            BOOL swapBytes,
            ITrnConnectionClient __RPC_FAR *pCaller);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SyncGetImageFileMapping )( 
            ITrnConnection __RPC_FAR * This,
            HANDLE hMap,
            ULONG offset,
            ULONG size,
            DWORD socketNumber,
            BOOL swapBytes,
            ITrnConnectionClient __RPC_FAR *pCaller);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SyncGetImageStream )( 
            ITrnConnection __RPC_FAR * This,
            IStream __RPC_FAR *pStream,
            ULONG size,
            DWORD socketNumber,
            BOOL swapBytes,
            ITrnConnectionClient __RPC_FAR *pCaller);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SyncGetImageFile )( 
            ITrnConnection __RPC_FAR * This,
            HANDLE hFile,
            ULONG size,
            DWORD socketNumber,
            BOOL swapBytes,
            ITrnConnectionClient __RPC_FAR *pCaller);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SyncReadMemory )( 
            ITrnConnection __RPC_FAR * This,
            DWORD socketNum,
            DWORD sourceAddress,
            DWORD alignment,
            DWORD size,
            LPVOID pBuffer);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SyncWriteMemory )( 
            ITrnConnection __RPC_FAR * This,
            DWORD socketNum,
            DWORD destAddress,
            DWORD alignment,
            DWORD size,
            LPVOID pBuffer);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *CancelAsyncTransfer )( 
            ITrnConnection __RPC_FAR * This,
            DWORD socketNumber);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *WaitVBlank )( 
            ITrnConnection __RPC_FAR * This,
            /* [out] */ LPDWORD pLocalTime);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *LockWindowBuffer )( 
            ITrnConnection __RPC_FAR * This,
            STrnDmaWindow __RPC_FAR *pWindows,
            DWORD nWindows,
            DWORD __RPC_FAR *pdwBufferId);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *UnlockWindowBuffer )( 
            ITrnConnection __RPC_FAR * This,
            DWORD dwBufferId);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SyncSendImageMemoryWindow )( 
            ITrnConnection __RPC_FAR * This,
            DWORD dwBufferId,
            DWORD socketNumber,
            DWORD targetAddress,
            BOOL swapBytes);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *AsyncGetImageMemoryWindow )( 
            ITrnConnection __RPC_FAR * This,
            DWORD dwBufferId,
            DWORD socketNumber,
            BOOL repeated,
            BOOL swapBytes,
            ITrnConnectionClient __RPC_FAR *pCaller);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *GetApplicationTag )( 
            ITrnConnection __RPC_FAR * This);
        
        END_INTERFACE
    } ITrnConnectionVtbl;

    interface ITrnConnection
    {
        CONST_VTBL struct ITrnConnectionVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ITrnConnection_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define ITrnConnection_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define ITrnConnection_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define ITrnConnection_GetConnectionInfo(This,pVersion,pType)	\
    (This)->lpVtbl -> GetConnectionInfo(This,pVersion,pType)

#define ITrnConnection_GetUniqueSocketNumber(This)	\
    (This)->lpVtbl -> GetUniqueSocketNumber(This)

#define ITrnConnection_GetListenSocketForSlot(This,bus,slot)	\
    (This)->lpVtbl -> GetListenSocketForSlot(This,bus,slot)

#define ITrnConnection_GetSlotFromSocket(This,Socket,pBus,pSlot)	\
    (This)->lpVtbl -> GetSlotFromSocket(This,Socket,pBus,pSlot)

#define ITrnConnection_GetMaxMsgSize(This)	\
    (This)->lpVtbl -> GetMaxMsgSize(This)

#define ITrnConnection_GetMsgBuffer(This,pBuffSize,ppBuffer)	\
    (This)->lpVtbl -> GetMsgBuffer(This,pBuffSize,ppBuffer)

#define ITrnConnection_GetDMABuffer(This,pBuffSize,ppBuffer)	\
    (This)->lpVtbl -> GetDMABuffer(This,pBuffSize,ppBuffer)

#define ITrnConnection_FreeBuffer(This,pBuffer)	\
    (This)->lpVtbl -> FreeBuffer(This,pBuffer)

#define ITrnConnection_SetTimeout(This,Timeout)	\
    (This)->lpVtbl -> SetTimeout(This,Timeout)

#define ITrnConnection_GetTimeout(This)	\
    (This)->lpVtbl -> GetTimeout(This)

#define ITrnConnection_TransactMessage(This,pSendBuffer,pRcvBuffer,rcvBuffSize,Timeout)	\
    (This)->lpVtbl -> TransactMessage(This,pSendBuffer,pRcvBuffer,rcvBuffSize,Timeout)

#define ITrnConnection_SendMessage(This,pBuffer)	\
    (This)->lpVtbl -> SendMessage(This,pBuffer)

#define ITrnConnection_WaitMessage(This,pBuffer,buffSize,Timeout,waitSocket)	\
    (This)->lpVtbl -> WaitMessage(This,pBuffer,buffSize,Timeout,waitSocket)

#define ITrnConnection_AsyncWaitMessage(This,pBuffer,buffSize,Timeout,waitSocket,repeated,pCaller)	\
    (This)->lpVtbl -> AsyncWaitMessage(This,pBuffer,buffSize,Timeout,waitSocket,repeated,pCaller)

#define ITrnConnection_SyncSendImageMemory(This,start,size,targetAddress,swapBytes)	\
    (This)->lpVtbl -> SyncSendImageMemory(This,start,size,targetAddress,swapBytes)

#define ITrnConnection_SyncSendImageStream(This,pStream,size,targetAddress,swapBytes)	\
    (This)->lpVtbl -> SyncSendImageStream(This,pStream,size,targetAddress,swapBytes)

#define ITrnConnection_SyncSendImageFile(This,hFile,size,targetAddress,swapBytes)	\
    (This)->lpVtbl -> SyncSendImageFile(This,hFile,size,targetAddress,swapBytes)

#define ITrnConnection_SyncSendImageFileMapping(This,hMap,offset,size,targetAddress,swapBytes)	\
    (This)->lpVtbl -> SyncSendImageFileMapping(This,hMap,offset,size,targetAddress,swapBytes)

#define ITrnConnection_AsyncGetImageMemory(This,start,size,socketNumber,repeated,swapBytes,pCaller)	\
    (This)->lpVtbl -> AsyncGetImageMemory(This,start,size,socketNumber,repeated,swapBytes,pCaller)

#define ITrnConnection_AsyncGetImageFileMapping(This,hMap,offset,size,socketNumber,repeated,swapBytes,pCaller)	\
    (This)->lpVtbl -> AsyncGetImageFileMapping(This,hMap,offset,size,socketNumber,repeated,swapBytes,pCaller)

#define ITrnConnection_SyncGetImageMemory(This,buffer,size,socketNumber,swapBytes,pCaller)	\
    (This)->lpVtbl -> SyncGetImageMemory(This,buffer,size,socketNumber,swapBytes,pCaller)

#define ITrnConnection_SyncGetImageFileMapping(This,hMap,offset,size,socketNumber,swapBytes,pCaller)	\
    (This)->lpVtbl -> SyncGetImageFileMapping(This,hMap,offset,size,socketNumber,swapBytes,pCaller)

#define ITrnConnection_SyncGetImageStream(This,pStream,size,socketNumber,swapBytes,pCaller)	\
    (This)->lpVtbl -> SyncGetImageStream(This,pStream,size,socketNumber,swapBytes,pCaller)

#define ITrnConnection_SyncGetImageFile(This,hFile,size,socketNumber,swapBytes,pCaller)	\
    (This)->lpVtbl -> SyncGetImageFile(This,hFile,size,socketNumber,swapBytes,pCaller)

#define ITrnConnection_SyncReadMemory(This,socketNum,sourceAddress,alignment,size,pBuffer)	\
    (This)->lpVtbl -> SyncReadMemory(This,socketNum,sourceAddress,alignment,size,pBuffer)

#define ITrnConnection_SyncWriteMemory(This,socketNum,destAddress,alignment,size,pBuffer)	\
    (This)->lpVtbl -> SyncWriteMemory(This,socketNum,destAddress,alignment,size,pBuffer)

#define ITrnConnection_CancelAsyncTransfer(This,socketNumber)	\
    (This)->lpVtbl -> CancelAsyncTransfer(This,socketNumber)

#define ITrnConnection_WaitVBlank(This,pLocalTime)	\
    (This)->lpVtbl -> WaitVBlank(This,pLocalTime)

#define ITrnConnection_LockWindowBuffer(This,pWindows,nWindows,pdwBufferId)	\
    (This)->lpVtbl -> LockWindowBuffer(This,pWindows,nWindows,pdwBufferId)

#define ITrnConnection_UnlockWindowBuffer(This,dwBufferId)	\
    (This)->lpVtbl -> UnlockWindowBuffer(This,dwBufferId)

#define ITrnConnection_SyncSendImageMemoryWindow(This,dwBufferId,socketNumber,targetAddress,swapBytes)	\
    (This)->lpVtbl -> SyncSendImageMemoryWindow(This,dwBufferId,socketNumber,targetAddress,swapBytes)

#define ITrnConnection_AsyncGetImageMemoryWindow(This,dwBufferId,socketNumber,repeated,swapBytes,pCaller)	\
    (This)->lpVtbl -> AsyncGetImageMemoryWindow(This,dwBufferId,socketNumber,repeated,swapBytes,pCaller)

#define ITrnConnection_GetApplicationTag(This)	\
    (This)->lpVtbl -> GetApplicationTag(This)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE ITrnConnection_GetConnectionInfo_Proxy( 
    ITrnConnection __RPC_FAR * This,
    /* [out] */ ULONG __RPC_FAR *pVersion,
    /* [out] */ ULONG __RPC_FAR *pType);


void __RPC_STUB ITrnConnection_GetConnectionInfo_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


ULONG STDMETHODCALLTYPE ITrnConnection_GetUniqueSocketNumber_Proxy( 
    ITrnConnection __RPC_FAR * This);


void __RPC_STUB ITrnConnection_GetUniqueSocketNumber_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


ULONG STDMETHODCALLTYPE ITrnConnection_GetListenSocketForSlot_Proxy( 
    ITrnConnection __RPC_FAR * This,
    ULONG bus,
    ULONG slot);


void __RPC_STUB ITrnConnection_GetListenSocketForSlot_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


void STDMETHODCALLTYPE ITrnConnection_GetSlotFromSocket_Proxy( 
    ITrnConnection __RPC_FAR * This,
    /* [in] */ ULONG Socket,
    /* [out] */ ULONG __RPC_FAR *pBus,
    /* [out] */ ULONG __RPC_FAR *pSlot);


void __RPC_STUB ITrnConnection_GetSlotFromSocket_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


ULONG STDMETHODCALLTYPE ITrnConnection_GetMaxMsgSize_Proxy( 
    ITrnConnection __RPC_FAR * This);


void __RPC_STUB ITrnConnection_GetMaxMsgSize_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE ITrnConnection_GetMsgBuffer_Proxy( 
    ITrnConnection __RPC_FAR * This,
    /* [out][in] */ DWORD __RPC_FAR *pBuffSize,
    /* [out] */ PSTrnMessageHeader __RPC_FAR *ppBuffer);


void __RPC_STUB ITrnConnection_GetMsgBuffer_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE ITrnConnection_GetDMABuffer_Proxy( 
    ITrnConnection __RPC_FAR * This,
    /* [out][in] */ DWORD __RPC_FAR *pBuffSize,
    /* [out] */ LPVOID __RPC_FAR *ppBuffer);


void __RPC_STUB ITrnConnection_GetDMABuffer_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE ITrnConnection_FreeBuffer_Proxy( 
    ITrnConnection __RPC_FAR * This,
    /* [in] */ LPVOID pBuffer);


void __RPC_STUB ITrnConnection_FreeBuffer_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE ITrnConnection_SetTimeout_Proxy( 
    ITrnConnection __RPC_FAR * This,
    /* [in] */ ULONG Timeout);


void __RPC_STUB ITrnConnection_SetTimeout_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


ULONG STDMETHODCALLTYPE ITrnConnection_GetTimeout_Proxy( 
    ITrnConnection __RPC_FAR * This);


void __RPC_STUB ITrnConnection_GetTimeout_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE ITrnConnection_TransactMessage_Proxy( 
    ITrnConnection __RPC_FAR * This,
    PSTrnMessageHeader pSendBuffer,
    PSTrnMessageHeader pRcvBuffer,
    ULONG rcvBuffSize,
    ULONG Timeout);


void __RPC_STUB ITrnConnection_TransactMessage_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE ITrnConnection_SendMessage_Proxy( 
    ITrnConnection __RPC_FAR * This,
    PSTrnMessageHeader pBuffer);


void __RPC_STUB ITrnConnection_SendMessage_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE ITrnConnection_WaitMessage_Proxy( 
    ITrnConnection __RPC_FAR * This,
    PSTrnMessageHeader pBuffer,
    ULONG buffSize,
    ULONG Timeout,
    ULONG waitSocket);


void __RPC_STUB ITrnConnection_WaitMessage_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE ITrnConnection_AsyncWaitMessage_Proxy( 
    ITrnConnection __RPC_FAR * This,
    PSTrnMessageHeader pBuffer,
    ULONG buffSize,
    ULONG Timeout,
    ULONG waitSocket,
    BOOL repeated,
    ITrnConnectionClient __RPC_FAR *pCaller);


void __RPC_STUB ITrnConnection_AsyncWaitMessage_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE ITrnConnection_SyncSendImageMemory_Proxy( 
    ITrnConnection __RPC_FAR * This,
    LPVOID start,
    ULONG size,
    DWORD targetAddress,
    BOOL swapBytes);


void __RPC_STUB ITrnConnection_SyncSendImageMemory_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE ITrnConnection_SyncSendImageStream_Proxy( 
    ITrnConnection __RPC_FAR * This,
    IStream __RPC_FAR *pStream,
    ULONG size,
    DWORD targetAddress,
    BOOL swapBytes);


void __RPC_STUB ITrnConnection_SyncSendImageStream_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE ITrnConnection_SyncSendImageFile_Proxy( 
    ITrnConnection __RPC_FAR * This,
    HANDLE hFile,
    ULONG size,
    DWORD targetAddress,
    BOOL swapBytes);


void __RPC_STUB ITrnConnection_SyncSendImageFile_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE ITrnConnection_SyncSendImageFileMapping_Proxy( 
    ITrnConnection __RPC_FAR * This,
    HANDLE hMap,
    ULONG offset,
    ULONG size,
    DWORD targetAddress,
    BOOL swapBytes);


void __RPC_STUB ITrnConnection_SyncSendImageFileMapping_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE ITrnConnection_AsyncGetImageMemory_Proxy( 
    ITrnConnection __RPC_FAR * This,
    LPVOID start,
    ULONG size,
    DWORD socketNumber,
    BOOL repeated,
    BOOL swapBytes,
    ITrnConnectionClient __RPC_FAR *pCaller);


void __RPC_STUB ITrnConnection_AsyncGetImageMemory_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE ITrnConnection_AsyncGetImageFileMapping_Proxy( 
    ITrnConnection __RPC_FAR * This,
    HANDLE hMap,
    ULONG offset,
    ULONG size,
    DWORD socketNumber,
    BOOL repeated,
    BOOL swapBytes,
    ITrnConnectionClient __RPC_FAR *pCaller);


void __RPC_STUB ITrnConnection_AsyncGetImageFileMapping_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE ITrnConnection_SyncGetImageMemory_Proxy( 
    ITrnConnection __RPC_FAR * This,
    LPVOID buffer,
    ULONG size,
    DWORD socketNumber,
    BOOL swapBytes,
    ITrnConnectionClient __RPC_FAR *pCaller);


void __RPC_STUB ITrnConnection_SyncGetImageMemory_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE ITrnConnection_SyncGetImageFileMapping_Proxy( 
    ITrnConnection __RPC_FAR * This,
    HANDLE hMap,
    ULONG offset,
    ULONG size,
    DWORD socketNumber,
    BOOL swapBytes,
    ITrnConnectionClient __RPC_FAR *pCaller);


void __RPC_STUB ITrnConnection_SyncGetImageFileMapping_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE ITrnConnection_SyncGetImageStream_Proxy( 
    ITrnConnection __RPC_FAR * This,
    IStream __RPC_FAR *pStream,
    ULONG size,
    DWORD socketNumber,
    BOOL swapBytes,
    ITrnConnectionClient __RPC_FAR *pCaller);


void __RPC_STUB ITrnConnection_SyncGetImageStream_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE ITrnConnection_SyncGetImageFile_Proxy( 
    ITrnConnection __RPC_FAR * This,
    HANDLE hFile,
    ULONG size,
    DWORD socketNumber,
    BOOL swapBytes,
    ITrnConnectionClient __RPC_FAR *pCaller);


void __RPC_STUB ITrnConnection_SyncGetImageFile_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE ITrnConnection_SyncReadMemory_Proxy( 
    ITrnConnection __RPC_FAR * This,
    DWORD socketNum,
    DWORD sourceAddress,
    DWORD alignment,
    DWORD size,
    LPVOID pBuffer);


void __RPC_STUB ITrnConnection_SyncReadMemory_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE ITrnConnection_SyncWriteMemory_Proxy( 
    ITrnConnection __RPC_FAR * This,
    DWORD socketNum,
    DWORD destAddress,
    DWORD alignment,
    DWORD size,
    LPVOID pBuffer);


void __RPC_STUB ITrnConnection_SyncWriteMemory_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE ITrnConnection_CancelAsyncTransfer_Proxy( 
    ITrnConnection __RPC_FAR * This,
    DWORD socketNumber);


void __RPC_STUB ITrnConnection_CancelAsyncTransfer_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE ITrnConnection_WaitVBlank_Proxy( 
    ITrnConnection __RPC_FAR * This,
    /* [out] */ LPDWORD pLocalTime);


void __RPC_STUB ITrnConnection_WaitVBlank_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE ITrnConnection_LockWindowBuffer_Proxy( 
    ITrnConnection __RPC_FAR * This,
    STrnDmaWindow __RPC_FAR *pWindows,
    DWORD nWindows,
    DWORD __RPC_FAR *pdwBufferId);


void __RPC_STUB ITrnConnection_LockWindowBuffer_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE ITrnConnection_UnlockWindowBuffer_Proxy( 
    ITrnConnection __RPC_FAR * This,
    DWORD dwBufferId);


void __RPC_STUB ITrnConnection_UnlockWindowBuffer_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE ITrnConnection_SyncSendImageMemoryWindow_Proxy( 
    ITrnConnection __RPC_FAR * This,
    DWORD dwBufferId,
    DWORD socketNumber,
    DWORD targetAddress,
    BOOL swapBytes);


void __RPC_STUB ITrnConnection_SyncSendImageMemoryWindow_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE ITrnConnection_AsyncGetImageMemoryWindow_Proxy( 
    ITrnConnection __RPC_FAR * This,
    DWORD dwBufferId,
    DWORD socketNumber,
    BOOL repeated,
    BOOL swapBytes,
    ITrnConnectionClient __RPC_FAR *pCaller);


void __RPC_STUB ITrnConnection_AsyncGetImageMemoryWindow_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


ULONG STDMETHODCALLTYPE ITrnConnection_GetApplicationTag_Proxy( 
    ITrnConnection __RPC_FAR * This);


void __RPC_STUB ITrnConnection_GetApplicationTag_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __ITrnConnection_INTERFACE_DEFINED__ */


#ifndef __ITrnConnection2_INTERFACE_DEFINED__
#define __ITrnConnection2_INTERFACE_DEFINED__

/****************************************
 * Generated header for interface: ITrnConnection2
 * at Tue Nov 23 05:28:38 1999
 * using MIDL 3.01.75
 ****************************************/
/* [unique][uuid][object][local] */ 



EXTERN_C const IID IID_ITrnConnection2;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    interface DECLSPEC_UUID("8335e63d-ab3b-11ce-8468-0000b468276b")
    ITrnConnection2 : public ITrnConnection
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE GetConnectionStatus( void) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct ITrnConnection2Vtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            ITrnConnection2 __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            ITrnConnection2 __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            ITrnConnection2 __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetConnectionInfo )( 
            ITrnConnection2 __RPC_FAR * This,
            /* [out] */ ULONG __RPC_FAR *pVersion,
            /* [out] */ ULONG __RPC_FAR *pType);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *GetUniqueSocketNumber )( 
            ITrnConnection2 __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *GetListenSocketForSlot )( 
            ITrnConnection2 __RPC_FAR * This,
            ULONG bus,
            ULONG slot);
        
        void ( STDMETHODCALLTYPE __RPC_FAR *GetSlotFromSocket )( 
            ITrnConnection2 __RPC_FAR * This,
            /* [in] */ ULONG Socket,
            /* [out] */ ULONG __RPC_FAR *pBus,
            /* [out] */ ULONG __RPC_FAR *pSlot);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *GetMaxMsgSize )( 
            ITrnConnection2 __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetMsgBuffer )( 
            ITrnConnection2 __RPC_FAR * This,
            /* [out][in] */ DWORD __RPC_FAR *pBuffSize,
            /* [out] */ PSTrnMessageHeader __RPC_FAR *ppBuffer);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetDMABuffer )( 
            ITrnConnection2 __RPC_FAR * This,
            /* [out][in] */ DWORD __RPC_FAR *pBuffSize,
            /* [out] */ LPVOID __RPC_FAR *ppBuffer);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *FreeBuffer )( 
            ITrnConnection2 __RPC_FAR * This,
            /* [in] */ LPVOID pBuffer);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetTimeout )( 
            ITrnConnection2 __RPC_FAR * This,
            /* [in] */ ULONG Timeout);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *GetTimeout )( 
            ITrnConnection2 __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *TransactMessage )( 
            ITrnConnection2 __RPC_FAR * This,
            PSTrnMessageHeader pSendBuffer,
            PSTrnMessageHeader pRcvBuffer,
            ULONG rcvBuffSize,
            ULONG Timeout);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SendMessage )( 
            ITrnConnection2 __RPC_FAR * This,
            PSTrnMessageHeader pBuffer);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *WaitMessage )( 
            ITrnConnection2 __RPC_FAR * This,
            PSTrnMessageHeader pBuffer,
            ULONG buffSize,
            ULONG Timeout,
            ULONG waitSocket);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *AsyncWaitMessage )( 
            ITrnConnection2 __RPC_FAR * This,
            PSTrnMessageHeader pBuffer,
            ULONG buffSize,
            ULONG Timeout,
            ULONG waitSocket,
            BOOL repeated,
            ITrnConnectionClient __RPC_FAR *pCaller);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SyncSendImageMemory )( 
            ITrnConnection2 __RPC_FAR * This,
            LPVOID start,
            ULONG size,
            DWORD targetAddress,
            BOOL swapBytes);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SyncSendImageStream )( 
            ITrnConnection2 __RPC_FAR * This,
            IStream __RPC_FAR *pStream,
            ULONG size,
            DWORD targetAddress,
            BOOL swapBytes);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SyncSendImageFile )( 
            ITrnConnection2 __RPC_FAR * This,
            HANDLE hFile,
            ULONG size,
            DWORD targetAddress,
            BOOL swapBytes);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SyncSendImageFileMapping )( 
            ITrnConnection2 __RPC_FAR * This,
            HANDLE hMap,
            ULONG offset,
            ULONG size,
            DWORD targetAddress,
            BOOL swapBytes);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *AsyncGetImageMemory )( 
            ITrnConnection2 __RPC_FAR * This,
            LPVOID start,
            ULONG size,
            DWORD socketNumber,
            BOOL repeated,
            BOOL swapBytes,
            ITrnConnectionClient __RPC_FAR *pCaller);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *AsyncGetImageFileMapping )( 
            ITrnConnection2 __RPC_FAR * This,
            HANDLE hMap,
            ULONG offset,
            ULONG size,
            DWORD socketNumber,
            BOOL repeated,
            BOOL swapBytes,
            ITrnConnectionClient __RPC_FAR *pCaller);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SyncGetImageMemory )( 
            ITrnConnection2 __RPC_FAR * This,
            LPVOID buffer,
            ULONG size,
            DWORD socketNumber,
            BOOL swapBytes,
            ITrnConnectionClient __RPC_FAR *pCaller);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SyncGetImageFileMapping )( 
            ITrnConnection2 __RPC_FAR * This,
            HANDLE hMap,
            ULONG offset,
            ULONG size,
            DWORD socketNumber,
            BOOL swapBytes,
            ITrnConnectionClient __RPC_FAR *pCaller);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SyncGetImageStream )( 
            ITrnConnection2 __RPC_FAR * This,
            IStream __RPC_FAR *pStream,
            ULONG size,
            DWORD socketNumber,
            BOOL swapBytes,
            ITrnConnectionClient __RPC_FAR *pCaller);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SyncGetImageFile )( 
            ITrnConnection2 __RPC_FAR * This,
            HANDLE hFile,
            ULONG size,
            DWORD socketNumber,
            BOOL swapBytes,
            ITrnConnectionClient __RPC_FAR *pCaller);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SyncReadMemory )( 
            ITrnConnection2 __RPC_FAR * This,
            DWORD socketNum,
            DWORD sourceAddress,
            DWORD alignment,
            DWORD size,
            LPVOID pBuffer);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SyncWriteMemory )( 
            ITrnConnection2 __RPC_FAR * This,
            DWORD socketNum,
            DWORD destAddress,
            DWORD alignment,
            DWORD size,
            LPVOID pBuffer);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *CancelAsyncTransfer )( 
            ITrnConnection2 __RPC_FAR * This,
            DWORD socketNumber);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *WaitVBlank )( 
            ITrnConnection2 __RPC_FAR * This,
            /* [out] */ LPDWORD pLocalTime);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *LockWindowBuffer )( 
            ITrnConnection2 __RPC_FAR * This,
            STrnDmaWindow __RPC_FAR *pWindows,
            DWORD nWindows,
            DWORD __RPC_FAR *pdwBufferId);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *UnlockWindowBuffer )( 
            ITrnConnection2 __RPC_FAR * This,
            DWORD dwBufferId);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SyncSendImageMemoryWindow )( 
            ITrnConnection2 __RPC_FAR * This,
            DWORD dwBufferId,
            DWORD socketNumber,
            DWORD targetAddress,
            BOOL swapBytes);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *AsyncGetImageMemoryWindow )( 
            ITrnConnection2 __RPC_FAR * This,
            DWORD dwBufferId,
            DWORD socketNumber,
            BOOL repeated,
            BOOL swapBytes,
            ITrnConnectionClient __RPC_FAR *pCaller);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *GetApplicationTag )( 
            ITrnConnection2 __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetConnectionStatus )( 
            ITrnConnection2 __RPC_FAR * This);
        
        END_INTERFACE
    } ITrnConnection2Vtbl;

    interface ITrnConnection2
    {
        CONST_VTBL struct ITrnConnection2Vtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ITrnConnection2_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define ITrnConnection2_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define ITrnConnection2_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define ITrnConnection2_GetConnectionInfo(This,pVersion,pType)	\
    (This)->lpVtbl -> GetConnectionInfo(This,pVersion,pType)

#define ITrnConnection2_GetUniqueSocketNumber(This)	\
    (This)->lpVtbl -> GetUniqueSocketNumber(This)

#define ITrnConnection2_GetListenSocketForSlot(This,bus,slot)	\
    (This)->lpVtbl -> GetListenSocketForSlot(This,bus,slot)

#define ITrnConnection2_GetSlotFromSocket(This,Socket,pBus,pSlot)	\
    (This)->lpVtbl -> GetSlotFromSocket(This,Socket,pBus,pSlot)

#define ITrnConnection2_GetMaxMsgSize(This)	\
    (This)->lpVtbl -> GetMaxMsgSize(This)

#define ITrnConnection2_GetMsgBuffer(This,pBuffSize,ppBuffer)	\
    (This)->lpVtbl -> GetMsgBuffer(This,pBuffSize,ppBuffer)

#define ITrnConnection2_GetDMABuffer(This,pBuffSize,ppBuffer)	\
    (This)->lpVtbl -> GetDMABuffer(This,pBuffSize,ppBuffer)

#define ITrnConnection2_FreeBuffer(This,pBuffer)	\
    (This)->lpVtbl -> FreeBuffer(This,pBuffer)

#define ITrnConnection2_SetTimeout(This,Timeout)	\
    (This)->lpVtbl -> SetTimeout(This,Timeout)

#define ITrnConnection2_GetTimeout(This)	\
    (This)->lpVtbl -> GetTimeout(This)

#define ITrnConnection2_TransactMessage(This,pSendBuffer,pRcvBuffer,rcvBuffSize,Timeout)	\
    (This)->lpVtbl -> TransactMessage(This,pSendBuffer,pRcvBuffer,rcvBuffSize,Timeout)

#define ITrnConnection2_SendMessage(This,pBuffer)	\
    (This)->lpVtbl -> SendMessage(This,pBuffer)

#define ITrnConnection2_WaitMessage(This,pBuffer,buffSize,Timeout,waitSocket)	\
    (This)->lpVtbl -> WaitMessage(This,pBuffer,buffSize,Timeout,waitSocket)

#define ITrnConnection2_AsyncWaitMessage(This,pBuffer,buffSize,Timeout,waitSocket,repeated,pCaller)	\
    (This)->lpVtbl -> AsyncWaitMessage(This,pBuffer,buffSize,Timeout,waitSocket,repeated,pCaller)

#define ITrnConnection2_SyncSendImageMemory(This,start,size,targetAddress,swapBytes)	\
    (This)->lpVtbl -> SyncSendImageMemory(This,start,size,targetAddress,swapBytes)

#define ITrnConnection2_SyncSendImageStream(This,pStream,size,targetAddress,swapBytes)	\
    (This)->lpVtbl -> SyncSendImageStream(This,pStream,size,targetAddress,swapBytes)

#define ITrnConnection2_SyncSendImageFile(This,hFile,size,targetAddress,swapBytes)	\
    (This)->lpVtbl -> SyncSendImageFile(This,hFile,size,targetAddress,swapBytes)

#define ITrnConnection2_SyncSendImageFileMapping(This,hMap,offset,size,targetAddress,swapBytes)	\
    (This)->lpVtbl -> SyncSendImageFileMapping(This,hMap,offset,size,targetAddress,swapBytes)

#define ITrnConnection2_AsyncGetImageMemory(This,start,size,socketNumber,repeated,swapBytes,pCaller)	\
    (This)->lpVtbl -> AsyncGetImageMemory(This,start,size,socketNumber,repeated,swapBytes,pCaller)

#define ITrnConnection2_AsyncGetImageFileMapping(This,hMap,offset,size,socketNumber,repeated,swapBytes,pCaller)	\
    (This)->lpVtbl -> AsyncGetImageFileMapping(This,hMap,offset,size,socketNumber,repeated,swapBytes,pCaller)

#define ITrnConnection2_SyncGetImageMemory(This,buffer,size,socketNumber,swapBytes,pCaller)	\
    (This)->lpVtbl -> SyncGetImageMemory(This,buffer,size,socketNumber,swapBytes,pCaller)

#define ITrnConnection2_SyncGetImageFileMapping(This,hMap,offset,size,socketNumber,swapBytes,pCaller)	\
    (This)->lpVtbl -> SyncGetImageFileMapping(This,hMap,offset,size,socketNumber,swapBytes,pCaller)

#define ITrnConnection2_SyncGetImageStream(This,pStream,size,socketNumber,swapBytes,pCaller)	\
    (This)->lpVtbl -> SyncGetImageStream(This,pStream,size,socketNumber,swapBytes,pCaller)

#define ITrnConnection2_SyncGetImageFile(This,hFile,size,socketNumber,swapBytes,pCaller)	\
    (This)->lpVtbl -> SyncGetImageFile(This,hFile,size,socketNumber,swapBytes,pCaller)

#define ITrnConnection2_SyncReadMemory(This,socketNum,sourceAddress,alignment,size,pBuffer)	\
    (This)->lpVtbl -> SyncReadMemory(This,socketNum,sourceAddress,alignment,size,pBuffer)

#define ITrnConnection2_SyncWriteMemory(This,socketNum,destAddress,alignment,size,pBuffer)	\
    (This)->lpVtbl -> SyncWriteMemory(This,socketNum,destAddress,alignment,size,pBuffer)

#define ITrnConnection2_CancelAsyncTransfer(This,socketNumber)	\
    (This)->lpVtbl -> CancelAsyncTransfer(This,socketNumber)

#define ITrnConnection2_WaitVBlank(This,pLocalTime)	\
    (This)->lpVtbl -> WaitVBlank(This,pLocalTime)

#define ITrnConnection2_LockWindowBuffer(This,pWindows,nWindows,pdwBufferId)	\
    (This)->lpVtbl -> LockWindowBuffer(This,pWindows,nWindows,pdwBufferId)

#define ITrnConnection2_UnlockWindowBuffer(This,dwBufferId)	\
    (This)->lpVtbl -> UnlockWindowBuffer(This,dwBufferId)

#define ITrnConnection2_SyncSendImageMemoryWindow(This,dwBufferId,socketNumber,targetAddress,swapBytes)	\
    (This)->lpVtbl -> SyncSendImageMemoryWindow(This,dwBufferId,socketNumber,targetAddress,swapBytes)

#define ITrnConnection2_AsyncGetImageMemoryWindow(This,dwBufferId,socketNumber,repeated,swapBytes,pCaller)	\
    (This)->lpVtbl -> AsyncGetImageMemoryWindow(This,dwBufferId,socketNumber,repeated,swapBytes,pCaller)

#define ITrnConnection2_GetApplicationTag(This)	\
    (This)->lpVtbl -> GetApplicationTag(This)


#define ITrnConnection2_GetConnectionStatus(This)	\
    (This)->lpVtbl -> GetConnectionStatus(This)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE ITrnConnection2_GetConnectionStatus_Proxy( 
    ITrnConnection2 __RPC_FAR * This);


void __RPC_STUB ITrnConnection2_GetConnectionStatus_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __ITrnConnection2_INTERFACE_DEFINED__ */


#ifndef __ITrnConnectionControl_INTERFACE_DEFINED__
#define __ITrnConnectionControl_INTERFACE_DEFINED__

/****************************************
 * Generated header for interface: ITrnConnectionControl
 * at Tue Nov 23 05:28:38 1999
 * using MIDL 3.01.75
 ****************************************/
/* [unique][uuid][object][local] */ 



EXTERN_C const IID IID_ITrnConnectionControl;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    interface DECLSPEC_UUID("8335e3f8-ab3b-11ce-8468-0000b468276b")
    ITrnConnectionControl : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE Connect( 
            HKEY hSystemKey) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct ITrnConnectionControlVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            ITrnConnectionControl __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            ITrnConnectionControl __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            ITrnConnectionControl __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Connect )( 
            ITrnConnectionControl __RPC_FAR * This,
            HKEY hSystemKey);
        
        END_INTERFACE
    } ITrnConnectionControlVtbl;

    interface ITrnConnectionControl
    {
        CONST_VTBL struct ITrnConnectionControlVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ITrnConnectionControl_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define ITrnConnectionControl_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define ITrnConnectionControl_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define ITrnConnectionControl_Connect(This,hSystemKey)	\
    (This)->lpVtbl -> Connect(This,hSystemKey)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE ITrnConnectionControl_Connect_Proxy( 
    ITrnConnectionControl __RPC_FAR * This,
    HKEY hSystemKey);


void __RPC_STUB ITrnConnectionControl_Connect_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __ITrnConnectionControl_INTERFACE_DEFINED__ */


#ifndef __ITrnConnectionControl2_INTERFACE_DEFINED__
#define __ITrnConnectionControl2_INTERFACE_DEFINED__

/****************************************
 * Generated header for interface: ITrnConnectionControl2
 * at Tue Nov 23 05:28:38 1999
 * using MIDL 3.01.75
 ****************************************/
/* [unique][uuid][object][local] */ 


typedef 
enum tagETrnConnectOptions
    {	CODontWait	= 1
    }	ETrnConnectOptions;


EXTERN_C const IID IID_ITrnConnectionControl2;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    interface DECLSPEC_UUID("8335e63f-ab3b-11ce-8468-0000b468276b")
    ITrnConnectionControl2 : public ITrnConnectionControl
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE ConnectEx( 
            /* [in] */ DWORD dwOptions,
            /* [in] */ HKEY hkSystemKey) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct ITrnConnectionControl2Vtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            ITrnConnectionControl2 __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            ITrnConnectionControl2 __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            ITrnConnectionControl2 __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Connect )( 
            ITrnConnectionControl2 __RPC_FAR * This,
            HKEY hSystemKey);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *ConnectEx )( 
            ITrnConnectionControl2 __RPC_FAR * This,
            /* [in] */ DWORD dwOptions,
            /* [in] */ HKEY hkSystemKey);
        
        END_INTERFACE
    } ITrnConnectionControl2Vtbl;

    interface ITrnConnectionControl2
    {
        CONST_VTBL struct ITrnConnectionControl2Vtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ITrnConnectionControl2_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define ITrnConnectionControl2_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define ITrnConnectionControl2_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define ITrnConnectionControl2_Connect(This,hSystemKey)	\
    (This)->lpVtbl -> Connect(This,hSystemKey)


#define ITrnConnectionControl2_ConnectEx(This,dwOptions,hkSystemKey)	\
    (This)->lpVtbl -> ConnectEx(This,dwOptions,hkSystemKey)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE ITrnConnectionControl2_ConnectEx_Proxy( 
    ITrnConnectionControl2 __RPC_FAR * This,
    /* [in] */ DWORD dwOptions,
    /* [in] */ HKEY hkSystemKey);


void __RPC_STUB ITrnConnectionControl2_ConnectEx_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __ITrnConnectionControl2_INTERFACE_DEFINED__ */


#ifndef __ILockMemory_INTERFACE_DEFINED__
#define __ILockMemory_INTERFACE_DEFINED__

/****************************************
 * Generated header for interface: ILockMemory
 * at Tue Nov 23 05:28:38 1999
 * using MIDL 3.01.75
 ****************************************/
/* [unique][uuid][object][local] */ 



EXTERN_C const IID IID_ILockMemory;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    interface DECLSPEC_UUID("8335e63c-ab3b-11ce-8468-0000b468276b")
    ILockMemory : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE LockBuffer( 
            /* [in] */ LPVOID pBuffer,
            /* [in] */ DWORD dwBuffSize) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE UnlockBuffer( 
            /* [in] */ LPVOID pBuffer,
            /* [in] */ DWORD dwBuffSize) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct ILockMemoryVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            ILockMemory __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            ILockMemory __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            ILockMemory __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *LockBuffer )( 
            ILockMemory __RPC_FAR * This,
            /* [in] */ LPVOID pBuffer,
            /* [in] */ DWORD dwBuffSize);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *UnlockBuffer )( 
            ILockMemory __RPC_FAR * This,
            /* [in] */ LPVOID pBuffer,
            /* [in] */ DWORD dwBuffSize);
        
        END_INTERFACE
    } ILockMemoryVtbl;

    interface ILockMemory
    {
        CONST_VTBL struct ILockMemoryVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ILockMemory_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define ILockMemory_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define ILockMemory_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define ILockMemory_LockBuffer(This,pBuffer,dwBuffSize)	\
    (This)->lpVtbl -> LockBuffer(This,pBuffer,dwBuffSize)

#define ILockMemory_UnlockBuffer(This,pBuffer,dwBuffSize)	\
    (This)->lpVtbl -> UnlockBuffer(This,pBuffer,dwBuffSize)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE ILockMemory_LockBuffer_Proxy( 
    ILockMemory __RPC_FAR * This,
    /* [in] */ LPVOID pBuffer,
    /* [in] */ DWORD dwBuffSize);


void __RPC_STUB ILockMemory_LockBuffer_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE ILockMemory_UnlockBuffer_Proxy( 
    ILockMemory __RPC_FAR * This,
    /* [in] */ LPVOID pBuffer,
    /* [in] */ DWORD dwBuffSize);


void __RPC_STUB ILockMemory_UnlockBuffer_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __ILockMemory_INTERFACE_DEFINED__ */


/* Additional Prototypes for ALL interfaces */

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif
