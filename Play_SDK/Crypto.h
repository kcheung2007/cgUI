/* this ALWAYS GENERATED file contains the definitions for the interfaces */


/* File created by MIDL compiler version 3.01.75 */
/* at Tue Nov 23 05:28:28 1999
 */
/* Compiler settings for Crypto.idl:
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

#ifndef __Crypto_h__
#define __Crypto_h__

#ifdef __cplusplus
extern "C"{
#endif 

/* Forward Declarations */ 

#ifndef __IPSHash_FWD_DEFINED__
#define __IPSHash_FWD_DEFINED__
typedef interface IPSHash IPSHash;
#endif 	/* __IPSHash_FWD_DEFINED__ */


#ifndef __IPSBlockCipher_FWD_DEFINED__
#define __IPSBlockCipher_FWD_DEFINED__
typedef interface IPSBlockCipher IPSBlockCipher;
#endif 	/* __IPSBlockCipher_FWD_DEFINED__ */


#ifndef __IPSStreamProgress_FWD_DEFINED__
#define __IPSStreamProgress_FWD_DEFINED__
typedef interface IPSStreamProgress IPSStreamProgress;
#endif 	/* __IPSStreamProgress_FWD_DEFINED__ */


#ifndef __IPSFilter_FWD_DEFINED__
#define __IPSFilter_FWD_DEFINED__
typedef interface IPSFilter IPSFilter;
#endif 	/* __IPSFilter_FWD_DEFINED__ */


#ifndef __IPSErrorAdvise_FWD_DEFINED__
#define __IPSErrorAdvise_FWD_DEFINED__
typedef interface IPSErrorAdvise IPSErrorAdvise;
#endif 	/* __IPSErrorAdvise_FWD_DEFINED__ */


#ifndef __IPSStreamBlockCipher_FWD_DEFINED__
#define __IPSStreamBlockCipher_FWD_DEFINED__
typedef interface IPSStreamBlockCipher IPSStreamBlockCipher;
#endif 	/* __IPSStreamBlockCipher_FWD_DEFINED__ */


#ifndef __IPSFileProgress_FWD_DEFINED__
#define __IPSFileProgress_FWD_DEFINED__
typedef interface IPSFileProgress IPSFileProgress;
#endif 	/* __IPSFileProgress_FWD_DEFINED__ */


#ifndef __IPSFileServices_FWD_DEFINED__
#define __IPSFileServices_FWD_DEFINED__
typedef interface IPSFileServices IPSFileServices;
#endif 	/* __IPSFileServices_FWD_DEFINED__ */


#ifndef __IPSFileRecord_FWD_DEFINED__
#define __IPSFileRecord_FWD_DEFINED__
typedef interface IPSFileRecord IPSFileRecord;
#endif 	/* __IPSFileRecord_FWD_DEFINED__ */


#ifndef __IPSFileCollection_FWD_DEFINED__
#define __IPSFileCollection_FWD_DEFINED__
typedef interface IPSFileCollection IPSFileCollection;
#endif 	/* __IPSFileCollection_FWD_DEFINED__ */


#ifndef __IPSFileRepository_FWD_DEFINED__
#define __IPSFileRepository_FWD_DEFINED__
typedef interface IPSFileRepository IPSFileRepository;
#endif 	/* __IPSFileRepository_FWD_DEFINED__ */


#ifndef __IPSBatchProgress_FWD_DEFINED__
#define __IPSBatchProgress_FWD_DEFINED__
typedef interface IPSBatchProgress IPSBatchProgress;
#endif 	/* __IPSBatchProgress_FWD_DEFINED__ */


#ifndef __IPSChangeNotify_FWD_DEFINED__
#define __IPSChangeNotify_FWD_DEFINED__
typedef interface IPSChangeNotify IPSChangeNotify;
#endif 	/* __IPSChangeNotify_FWD_DEFINED__ */


#ifndef __IPSNotifyManager_FWD_DEFINED__
#define __IPSNotifyManager_FWD_DEFINED__
typedef interface IPSNotifyManager IPSNotifyManager;
#endif 	/* __IPSNotifyManager_FWD_DEFINED__ */


#ifndef __IPSShredder_FWD_DEFINED__
#define __IPSShredder_FWD_DEFINED__
typedef interface IPSShredder IPSShredder;
#endif 	/* __IPSShredder_FWD_DEFINED__ */


#ifndef __IPSVault_FWD_DEFINED__
#define __IPSVault_FWD_DEFINED__
typedef interface IPSVault IPSVault;
#endif 	/* __IPSVault_FWD_DEFINED__ */


/* header files for imported files */
#include "wtypes.h"
#include "unknwn.h"
#include "objidl.h"

void __RPC_FAR * __RPC_USER MIDL_user_allocate(size_t);
void __RPC_USER MIDL_user_free( void __RPC_FAR * ); 

/****************************************
 * Generated header for interface: __MIDL_itf_Crypto_0000
 * at Tue Nov 23 05:28:28 1999
 * using MIDL 3.01.75
 ****************************************/
/* [local] */ 


// ----------------------------------------------------------------------------
// Play Incorporated Security Provider                                         
// Copyright 1988, Play Incorporated, All rights Reserved                      
//                                                                             
// File: Crypto.idl .h                                                         
//                                                                             
// Contents:                                                                   
//  Declares interfaces for Play Cryptography objects                          
//                                                                             
// History:                                                                    
//    May 1998    cpdaniel  created                                            
// ----------------------------------------------------------------------------


extern RPC_IF_HANDLE __MIDL_itf_Crypto_0000_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_Crypto_0000_v0_0_s_ifspec;

#ifndef __IPSHash_INTERFACE_DEFINED__
#define __IPSHash_INTERFACE_DEFINED__

/****************************************
 * Generated header for interface: IPSHash
 * at Tue Nov 23 05:28:28 1999
 * using MIDL 3.01.75
 ****************************************/
/* [unique][uuid][object][local] */ 



EXTERN_C const IID IID_IPSHash;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    interface DECLSPEC_UUID("8335e7d2-ab3b-11ce-8468-0000b468276b")
    IPSHash : public IUnknown
    {
    public:
        virtual DWORD STDMETHODCALLTYPE HashSize( void) = 0;
        
        virtual DWORD STDMETHODCALLTYPE BlockSize( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Init( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Update( 
            /* [in] */ LPVOID pData,
            /* [in] */ unsigned int cbData) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Finish( 
            /* [out] */ LPVOID pHash) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IPSHashVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            IPSHash __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            IPSHash __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            IPSHash __RPC_FAR * This);
        
        DWORD ( STDMETHODCALLTYPE __RPC_FAR *HashSize )( 
            IPSHash __RPC_FAR * This);
        
        DWORD ( STDMETHODCALLTYPE __RPC_FAR *BlockSize )( 
            IPSHash __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Init )( 
            IPSHash __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Update )( 
            IPSHash __RPC_FAR * This,
            /* [in] */ LPVOID pData,
            /* [in] */ unsigned int cbData);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Finish )( 
            IPSHash __RPC_FAR * This,
            /* [out] */ LPVOID pHash);
        
        END_INTERFACE
    } IPSHashVtbl;

    interface IPSHash
    {
        CONST_VTBL struct IPSHashVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IPSHash_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IPSHash_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IPSHash_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IPSHash_HashSize(This)	\
    (This)->lpVtbl -> HashSize(This)

#define IPSHash_BlockSize(This)	\
    (This)->lpVtbl -> BlockSize(This)

#define IPSHash_Init(This)	\
    (This)->lpVtbl -> Init(This)

#define IPSHash_Update(This,pData,cbData)	\
    (This)->lpVtbl -> Update(This,pData,cbData)

#define IPSHash_Finish(This,pHash)	\
    (This)->lpVtbl -> Finish(This,pHash)

#endif /* COBJMACROS */


#endif 	/* C style interface */



DWORD STDMETHODCALLTYPE IPSHash_HashSize_Proxy( 
    IPSHash __RPC_FAR * This);


void __RPC_STUB IPSHash_HashSize_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


DWORD STDMETHODCALLTYPE IPSHash_BlockSize_Proxy( 
    IPSHash __RPC_FAR * This);


void __RPC_STUB IPSHash_BlockSize_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IPSHash_Init_Proxy( 
    IPSHash __RPC_FAR * This);


void __RPC_STUB IPSHash_Init_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IPSHash_Update_Proxy( 
    IPSHash __RPC_FAR * This,
    /* [in] */ LPVOID pData,
    /* [in] */ unsigned int cbData);


void __RPC_STUB IPSHash_Update_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IPSHash_Finish_Proxy( 
    IPSHash __RPC_FAR * This,
    /* [out] */ LPVOID pHash);


void __RPC_STUB IPSHash_Finish_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IPSHash_INTERFACE_DEFINED__ */


#ifndef __IPSBlockCipher_INTERFACE_DEFINED__
#define __IPSBlockCipher_INTERFACE_DEFINED__

/****************************************
 * Generated header for interface: IPSBlockCipher
 * at Tue Nov 23 05:28:28 1999
 * using MIDL 3.01.75
 ****************************************/
/* [unique][uuid][object][local] */ 



EXTERN_C const IID IID_IPSBlockCipher;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    interface DECLSPEC_UUID("8335e7d3-ab3b-11ce-8468-0000b468276b")
    IPSBlockCipher : public IUnknown
    {
    public:
        virtual DWORD STDMETHODCALLTYPE KeySize( void) = 0;
        
        virtual DWORD STDMETHODCALLTYPE BlockSize( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetKey( 
            /* [in] */ LPVOID pKey,
            /* [in] */ unsigned int keyLen) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE EncryptBlock( 
            /* [in] */ LPVOID pPlainText,
            /* [out] */ LPVOID pCipherText) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE DecryptBlock( 
            /* [in] */ LPVOID pCipherText,
            /* [out] */ LPVOID pPlainText) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IPSBlockCipherVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            IPSBlockCipher __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            IPSBlockCipher __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            IPSBlockCipher __RPC_FAR * This);
        
        DWORD ( STDMETHODCALLTYPE __RPC_FAR *KeySize )( 
            IPSBlockCipher __RPC_FAR * This);
        
        DWORD ( STDMETHODCALLTYPE __RPC_FAR *BlockSize )( 
            IPSBlockCipher __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetKey )( 
            IPSBlockCipher __RPC_FAR * This,
            /* [in] */ LPVOID pKey,
            /* [in] */ unsigned int keyLen);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *EncryptBlock )( 
            IPSBlockCipher __RPC_FAR * This,
            /* [in] */ LPVOID pPlainText,
            /* [out] */ LPVOID pCipherText);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *DecryptBlock )( 
            IPSBlockCipher __RPC_FAR * This,
            /* [in] */ LPVOID pCipherText,
            /* [out] */ LPVOID pPlainText);
        
        END_INTERFACE
    } IPSBlockCipherVtbl;

    interface IPSBlockCipher
    {
        CONST_VTBL struct IPSBlockCipherVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IPSBlockCipher_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IPSBlockCipher_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IPSBlockCipher_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IPSBlockCipher_KeySize(This)	\
    (This)->lpVtbl -> KeySize(This)

#define IPSBlockCipher_BlockSize(This)	\
    (This)->lpVtbl -> BlockSize(This)

#define IPSBlockCipher_SetKey(This,pKey,keyLen)	\
    (This)->lpVtbl -> SetKey(This,pKey,keyLen)

#define IPSBlockCipher_EncryptBlock(This,pPlainText,pCipherText)	\
    (This)->lpVtbl -> EncryptBlock(This,pPlainText,pCipherText)

#define IPSBlockCipher_DecryptBlock(This,pCipherText,pPlainText)	\
    (This)->lpVtbl -> DecryptBlock(This,pCipherText,pPlainText)

#endif /* COBJMACROS */


#endif 	/* C style interface */



DWORD STDMETHODCALLTYPE IPSBlockCipher_KeySize_Proxy( 
    IPSBlockCipher __RPC_FAR * This);


void __RPC_STUB IPSBlockCipher_KeySize_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


DWORD STDMETHODCALLTYPE IPSBlockCipher_BlockSize_Proxy( 
    IPSBlockCipher __RPC_FAR * This);


void __RPC_STUB IPSBlockCipher_BlockSize_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IPSBlockCipher_SetKey_Proxy( 
    IPSBlockCipher __RPC_FAR * This,
    /* [in] */ LPVOID pKey,
    /* [in] */ unsigned int keyLen);


void __RPC_STUB IPSBlockCipher_SetKey_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IPSBlockCipher_EncryptBlock_Proxy( 
    IPSBlockCipher __RPC_FAR * This,
    /* [in] */ LPVOID pPlainText,
    /* [out] */ LPVOID pCipherText);


void __RPC_STUB IPSBlockCipher_EncryptBlock_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IPSBlockCipher_DecryptBlock_Proxy( 
    IPSBlockCipher __RPC_FAR * This,
    /* [in] */ LPVOID pCipherText,
    /* [out] */ LPVOID pPlainText);


void __RPC_STUB IPSBlockCipher_DecryptBlock_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IPSBlockCipher_INTERFACE_DEFINED__ */


#ifndef __IPSStreamProgress_INTERFACE_DEFINED__
#define __IPSStreamProgress_INTERFACE_DEFINED__

/****************************************
 * Generated header for interface: IPSStreamProgress
 * at Tue Nov 23 05:28:28 1999
 * using MIDL 3.01.75
 ****************************************/
/* [unique][uuid][object][local] */ 



EXTERN_C const IID IID_IPSStreamProgress;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    interface DECLSPEC_UUID("8335e7dd-ab3b-11ce-8468-0000b468276b")
    IPSStreamProgress : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE OnProgress( 
            unsigned int chunkSize,
            unsigned int passNumber,
            unsigned int totalPasses) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IPSStreamProgressVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            IPSStreamProgress __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            IPSStreamProgress __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            IPSStreamProgress __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *OnProgress )( 
            IPSStreamProgress __RPC_FAR * This,
            unsigned int chunkSize,
            unsigned int passNumber,
            unsigned int totalPasses);
        
        END_INTERFACE
    } IPSStreamProgressVtbl;

    interface IPSStreamProgress
    {
        CONST_VTBL struct IPSStreamProgressVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IPSStreamProgress_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IPSStreamProgress_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IPSStreamProgress_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IPSStreamProgress_OnProgress(This,chunkSize,passNumber,totalPasses)	\
    (This)->lpVtbl -> OnProgress(This,chunkSize,passNumber,totalPasses)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE IPSStreamProgress_OnProgress_Proxy( 
    IPSStreamProgress __RPC_FAR * This,
    unsigned int chunkSize,
    unsigned int passNumber,
    unsigned int totalPasses);


void __RPC_STUB IPSStreamProgress_OnProgress_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IPSStreamProgress_INTERFACE_DEFINED__ */


#ifndef __IPSFilter_INTERFACE_DEFINED__
#define __IPSFilter_INTERFACE_DEFINED__

/****************************************
 * Generated header for interface: IPSFilter
 * at Tue Nov 23 05:28:28 1999
 * using MIDL 3.01.75
 ****************************************/
/* [unique][uuid][object][local] */ 


typedef 
enum tagEPSFilterFlags
    {	EPSFForward	= 1,
	EPSFOverlapped	= 2
    }	EPSFilterFlags;

typedef struct  tagSPSFilterOverlapped
    {
    HRESULT finalResult;
    HANDLE hFinishEvent;
    }	SPSFilterOverlapped;


EXTERN_C const IID IID_IPSFilter;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    interface DECLSPEC_UUID("8335e7d8-ab3b-11ce-8468-0000b468276b")
    IPSFilter : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE FilterStream( 
            /* [in] */ IPSStreamProgress __RPC_FAR *pProgress,
            /* [in] */ ISequentialStream __RPC_FAR *pInputStream,
            /* [out] */ ISequentialStream __RPC_FAR *pOutputStream,
            /* [in] */ unsigned int cbSuggestedBufferSize,
            /* [in] */ DWORD dwFlags,
            /* [in] */ SPSFilterOverlapped __RPC_FAR *pOverlapped) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IPSFilterVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            IPSFilter __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            IPSFilter __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            IPSFilter __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *FilterStream )( 
            IPSFilter __RPC_FAR * This,
            /* [in] */ IPSStreamProgress __RPC_FAR *pProgress,
            /* [in] */ ISequentialStream __RPC_FAR *pInputStream,
            /* [out] */ ISequentialStream __RPC_FAR *pOutputStream,
            /* [in] */ unsigned int cbSuggestedBufferSize,
            /* [in] */ DWORD dwFlags,
            /* [in] */ SPSFilterOverlapped __RPC_FAR *pOverlapped);
        
        END_INTERFACE
    } IPSFilterVtbl;

    interface IPSFilter
    {
        CONST_VTBL struct IPSFilterVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IPSFilter_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IPSFilter_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IPSFilter_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IPSFilter_FilterStream(This,pProgress,pInputStream,pOutputStream,cbSuggestedBufferSize,dwFlags,pOverlapped)	\
    (This)->lpVtbl -> FilterStream(This,pProgress,pInputStream,pOutputStream,cbSuggestedBufferSize,dwFlags,pOverlapped)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE IPSFilter_FilterStream_Proxy( 
    IPSFilter __RPC_FAR * This,
    /* [in] */ IPSStreamProgress __RPC_FAR *pProgress,
    /* [in] */ ISequentialStream __RPC_FAR *pInputStream,
    /* [out] */ ISequentialStream __RPC_FAR *pOutputStream,
    /* [in] */ unsigned int cbSuggestedBufferSize,
    /* [in] */ DWORD dwFlags,
    /* [in] */ SPSFilterOverlapped __RPC_FAR *pOverlapped);


void __RPC_STUB IPSFilter_FilterStream_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IPSFilter_INTERFACE_DEFINED__ */


#ifndef __IPSErrorAdvise_INTERFACE_DEFINED__
#define __IPSErrorAdvise_INTERFACE_DEFINED__

/****************************************
 * Generated header for interface: IPSErrorAdvise
 * at Tue Nov 23 05:28:28 1999
 * using MIDL 3.01.75
 ****************************************/
/* [unique][uuid][object][local] */ 



EXTERN_C const IID IID_IPSErrorAdvise;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    interface DECLSPEC_UUID("8335e7e1-ab3b-11ce-8468-0000b468276b")
    IPSErrorAdvise : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE OnError( 
            HRESULT error) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IPSErrorAdviseVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            IPSErrorAdvise __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            IPSErrorAdvise __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            IPSErrorAdvise __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *OnError )( 
            IPSErrorAdvise __RPC_FAR * This,
            HRESULT error);
        
        END_INTERFACE
    } IPSErrorAdviseVtbl;

    interface IPSErrorAdvise
    {
        CONST_VTBL struct IPSErrorAdviseVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IPSErrorAdvise_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IPSErrorAdvise_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IPSErrorAdvise_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IPSErrorAdvise_OnError(This,error)	\
    (This)->lpVtbl -> OnError(This,error)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE IPSErrorAdvise_OnError_Proxy( 
    IPSErrorAdvise __RPC_FAR * This,
    HRESULT error);


void __RPC_STUB IPSErrorAdvise_OnError_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IPSErrorAdvise_INTERFACE_DEFINED__ */


#ifndef __IPSStreamBlockCipher_INTERFACE_DEFINED__
#define __IPSStreamBlockCipher_INTERFACE_DEFINED__

/****************************************
 * Generated header for interface: IPSStreamBlockCipher
 * at Tue Nov 23 05:28:28 1999
 * using MIDL 3.01.75
 ****************************************/
/* [unique][uuid][object][local] */ 



EXTERN_C const IID IID_IPSStreamBlockCipher;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    interface DECLSPEC_UUID("8335e7d4-ab3b-11ce-8468-0000b468276b")
    IPSStreamBlockCipher : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE Encrypt( 
            /* [in] */ IPSStreamProgress __RPC_FAR *pProgress,
            /* [in] */ IPSBlockCipher __RPC_FAR *pCipher,
            /* [in] */ LPVOID pKey,
            /* [in] */ unsigned int keySize,
            /* [in] */ LPVOID pSalt,
            /* [in] */ ISequentialStream __RPC_FAR *pPlaintextStream,
            /* [in] */ unsigned int cbSuggestedBufferSize,
            /* [out] */ ISequentialStream __RPC_FAR *pCiphertextStream,
            /* [out] */ unsigned int __RPC_FAR *pcbCiphertextStream,
            /* [in] */ IPSHash __RPC_FAR *pHash,
            /* [out] */ LPVOID pHashData) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Decrypt( 
            /* [in] */ IPSStreamProgress __RPC_FAR *pProgress,
            /* [in] */ IPSBlockCipher __RPC_FAR *pCipher,
            /* [in] */ LPVOID pKey,
            /* [in] */ unsigned int keySize,
            /* [in] */ LPVOID pSalt,
            /* [in] */ ISequentialStream __RPC_FAR *pCiphertextStream,
            /* [in] */ unsigned int cbSuggestedBufferSize,
            /* [out] */ ISequentialStream __RPC_FAR *pPlaintextStream,
            /* [out] */ unsigned int __RPC_FAR *pcbPlaintextStream,
            /* [in] */ IPSHash __RPC_FAR *pHash,
            /* [in] */ LPVOID pHashData) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IPSStreamBlockCipherVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            IPSStreamBlockCipher __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            IPSStreamBlockCipher __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            IPSStreamBlockCipher __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Encrypt )( 
            IPSStreamBlockCipher __RPC_FAR * This,
            /* [in] */ IPSStreamProgress __RPC_FAR *pProgress,
            /* [in] */ IPSBlockCipher __RPC_FAR *pCipher,
            /* [in] */ LPVOID pKey,
            /* [in] */ unsigned int keySize,
            /* [in] */ LPVOID pSalt,
            /* [in] */ ISequentialStream __RPC_FAR *pPlaintextStream,
            /* [in] */ unsigned int cbSuggestedBufferSize,
            /* [out] */ ISequentialStream __RPC_FAR *pCiphertextStream,
            /* [out] */ unsigned int __RPC_FAR *pcbCiphertextStream,
            /* [in] */ IPSHash __RPC_FAR *pHash,
            /* [out] */ LPVOID pHashData);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Decrypt )( 
            IPSStreamBlockCipher __RPC_FAR * This,
            /* [in] */ IPSStreamProgress __RPC_FAR *pProgress,
            /* [in] */ IPSBlockCipher __RPC_FAR *pCipher,
            /* [in] */ LPVOID pKey,
            /* [in] */ unsigned int keySize,
            /* [in] */ LPVOID pSalt,
            /* [in] */ ISequentialStream __RPC_FAR *pCiphertextStream,
            /* [in] */ unsigned int cbSuggestedBufferSize,
            /* [out] */ ISequentialStream __RPC_FAR *pPlaintextStream,
            /* [out] */ unsigned int __RPC_FAR *pcbPlaintextStream,
            /* [in] */ IPSHash __RPC_FAR *pHash,
            /* [in] */ LPVOID pHashData);
        
        END_INTERFACE
    } IPSStreamBlockCipherVtbl;

    interface IPSStreamBlockCipher
    {
        CONST_VTBL struct IPSStreamBlockCipherVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IPSStreamBlockCipher_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IPSStreamBlockCipher_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IPSStreamBlockCipher_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IPSStreamBlockCipher_Encrypt(This,pProgress,pCipher,pKey,keySize,pSalt,pPlaintextStream,cbSuggestedBufferSize,pCiphertextStream,pcbCiphertextStream,pHash,pHashData)	\
    (This)->lpVtbl -> Encrypt(This,pProgress,pCipher,pKey,keySize,pSalt,pPlaintextStream,cbSuggestedBufferSize,pCiphertextStream,pcbCiphertextStream,pHash,pHashData)

#define IPSStreamBlockCipher_Decrypt(This,pProgress,pCipher,pKey,keySize,pSalt,pCiphertextStream,cbSuggestedBufferSize,pPlaintextStream,pcbPlaintextStream,pHash,pHashData)	\
    (This)->lpVtbl -> Decrypt(This,pProgress,pCipher,pKey,keySize,pSalt,pCiphertextStream,cbSuggestedBufferSize,pPlaintextStream,pcbPlaintextStream,pHash,pHashData)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE IPSStreamBlockCipher_Encrypt_Proxy( 
    IPSStreamBlockCipher __RPC_FAR * This,
    /* [in] */ IPSStreamProgress __RPC_FAR *pProgress,
    /* [in] */ IPSBlockCipher __RPC_FAR *pCipher,
    /* [in] */ LPVOID pKey,
    /* [in] */ unsigned int keySize,
    /* [in] */ LPVOID pSalt,
    /* [in] */ ISequentialStream __RPC_FAR *pPlaintextStream,
    /* [in] */ unsigned int cbSuggestedBufferSize,
    /* [out] */ ISequentialStream __RPC_FAR *pCiphertextStream,
    /* [out] */ unsigned int __RPC_FAR *pcbCiphertextStream,
    /* [in] */ IPSHash __RPC_FAR *pHash,
    /* [out] */ LPVOID pHashData);


void __RPC_STUB IPSStreamBlockCipher_Encrypt_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IPSStreamBlockCipher_Decrypt_Proxy( 
    IPSStreamBlockCipher __RPC_FAR * This,
    /* [in] */ IPSStreamProgress __RPC_FAR *pProgress,
    /* [in] */ IPSBlockCipher __RPC_FAR *pCipher,
    /* [in] */ LPVOID pKey,
    /* [in] */ unsigned int keySize,
    /* [in] */ LPVOID pSalt,
    /* [in] */ ISequentialStream __RPC_FAR *pCiphertextStream,
    /* [in] */ unsigned int cbSuggestedBufferSize,
    /* [out] */ ISequentialStream __RPC_FAR *pPlaintextStream,
    /* [out] */ unsigned int __RPC_FAR *pcbPlaintextStream,
    /* [in] */ IPSHash __RPC_FAR *pHash,
    /* [in] */ LPVOID pHashData);


void __RPC_STUB IPSStreamBlockCipher_Decrypt_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IPSStreamBlockCipher_INTERFACE_DEFINED__ */


#ifndef __IPSFileProgress_INTERFACE_DEFINED__
#define __IPSFileProgress_INTERFACE_DEFINED__

/****************************************
 * Generated header for interface: IPSFileProgress
 * at Tue Nov 23 05:28:28 1999
 * using MIDL 3.01.75
 ****************************************/
/* [unique][uuid][object][local] */ 


typedef 
enum tagEFPProcess
    {	FPEncrypt	= 0,
	FPDecrypt	= FPEncrypt + 1,
	FPShred	= FPDecrypt + 1
    }	EFPProcess;


EXTERN_C const IID IID_IPSFileProgress;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    interface DECLSPEC_UUID("8335e7dc-ab3b-11ce-8468-0000b468276b")
    IPSFileProgress : public IPSStreamProgress
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE OnFileStart( 
            const unsigned char __RPC_FAR *pszTargetFile,
            DWORD fileSize,
            DWORD fileSizeHigh,
            EFPProcess process,
            unsigned int param) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IPSFileProgressVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            IPSFileProgress __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            IPSFileProgress __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            IPSFileProgress __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *OnProgress )( 
            IPSFileProgress __RPC_FAR * This,
            unsigned int chunkSize,
            unsigned int passNumber,
            unsigned int totalPasses);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *OnFileStart )( 
            IPSFileProgress __RPC_FAR * This,
            const unsigned char __RPC_FAR *pszTargetFile,
            DWORD fileSize,
            DWORD fileSizeHigh,
            EFPProcess process,
            unsigned int param);
        
        END_INTERFACE
    } IPSFileProgressVtbl;

    interface IPSFileProgress
    {
        CONST_VTBL struct IPSFileProgressVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IPSFileProgress_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IPSFileProgress_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IPSFileProgress_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IPSFileProgress_OnProgress(This,chunkSize,passNumber,totalPasses)	\
    (This)->lpVtbl -> OnProgress(This,chunkSize,passNumber,totalPasses)


#define IPSFileProgress_OnFileStart(This,pszTargetFile,fileSize,fileSizeHigh,process,param)	\
    (This)->lpVtbl -> OnFileStart(This,pszTargetFile,fileSize,fileSizeHigh,process,param)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE IPSFileProgress_OnFileStart_Proxy( 
    IPSFileProgress __RPC_FAR * This,
    const unsigned char __RPC_FAR *pszTargetFile,
    DWORD fileSize,
    DWORD fileSizeHigh,
    EFPProcess process,
    unsigned int param);


void __RPC_STUB IPSFileProgress_OnFileStart_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IPSFileProgress_INTERFACE_DEFINED__ */


#ifndef __IPSFileServices_INTERFACE_DEFINED__
#define __IPSFileServices_INTERFACE_DEFINED__

/****************************************
 * Generated header for interface: IPSFileServices
 * at Tue Nov 23 05:28:28 1999
 * using MIDL 3.01.75
 ****************************************/
/* [unique][uuid][object][local] */ 


typedef /* [public][public][public] */ struct  __MIDL_IPSFileServices_0001
    {
    DWORD dwSizeof;
    unsigned char __RPC_FAR *pszNameBuffer;
    unsigned int cbNameBuffer;
    unsigned char __RPC_FAR *pszHintBuffer;
    unsigned int cbHintBuffer;
    DWORD dwOrigSize;
    DWORD dwFileSize;
    FILETIME origCreateTime;
    FILETIME origAccessTime;
    FILETIME origWriteTime;
    DWORD origAttributes;
    FILETIME encryptTime;
    }	SPSFileInfo;

typedef 
enum tagEPSExportStatus
    {	ESDomestic	= 0,
	ESInternational	= ESDomestic + 1
    }	EPSExportStatus;


EXTERN_C const IID IID_IPSFileServices;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    interface DECLSPEC_UUID("8335e7d9-ab3b-11ce-8468-0000b468276b")
    IPSFileServices : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE EncryptFile( 
            IPSFileProgress __RPC_FAR *pProgress,
            const unsigned char __RPC_FAR *lpszInFileName,
            unsigned char __RPC_FAR *lpszPassPhrase,
            BOOL bDontHashKey,
            const unsigned char __RPC_FAR *lpszOutFileName,
            const unsigned char __RPC_FAR *lpszUserHint) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE DecryptFile( 
            IPSFileProgress __RPC_FAR *pProgress,
            const unsigned char __RPC_FAR *lpszInFileName,
            unsigned char __RPC_FAR *lpszPassPhrase,
            BOOL bDontHashKey,
            const unsigned char __RPC_FAR *lpszOutFileName) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE QueryEncryptedFileInfo( 
            const unsigned char __RPC_FAR *lpszInFileName,
            SPSFileInfo __RPC_FAR *pFileInfo) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE EraseFile( 
            IPSFileProgress __RPC_FAR *pProgress,
            const unsigned char __RPC_FAR *lpszFileName,
            const unsigned char __RPC_FAR *lpszDisplayName,
            unsigned int eraseLevel) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE RandSet( 
            LPVOID pBuffer,
            unsigned int cbBuffer) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetDefaultHash( 
            IPSHash __RPC_FAR *__RPC_FAR *ppHash) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetDefaultCipher( 
            EPSExportStatus export,
            IPSBlockCipher __RPC_FAR *__RPC_FAR *ppCipher) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetDefaultProtocol( 
            IPSStreamBlockCipher __RPC_FAR *__RPC_FAR *ppStreamBlockCipher) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IPSFileServicesVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            IPSFileServices __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            IPSFileServices __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            IPSFileServices __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *EncryptFile )( 
            IPSFileServices __RPC_FAR * This,
            IPSFileProgress __RPC_FAR *pProgress,
            const unsigned char __RPC_FAR *lpszInFileName,
            unsigned char __RPC_FAR *lpszPassPhrase,
            BOOL bDontHashKey,
            const unsigned char __RPC_FAR *lpszOutFileName,
            const unsigned char __RPC_FAR *lpszUserHint);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *DecryptFile )( 
            IPSFileServices __RPC_FAR * This,
            IPSFileProgress __RPC_FAR *pProgress,
            const unsigned char __RPC_FAR *lpszInFileName,
            unsigned char __RPC_FAR *lpszPassPhrase,
            BOOL bDontHashKey,
            const unsigned char __RPC_FAR *lpszOutFileName);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryEncryptedFileInfo )( 
            IPSFileServices __RPC_FAR * This,
            const unsigned char __RPC_FAR *lpszInFileName,
            SPSFileInfo __RPC_FAR *pFileInfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *EraseFile )( 
            IPSFileServices __RPC_FAR * This,
            IPSFileProgress __RPC_FAR *pProgress,
            const unsigned char __RPC_FAR *lpszFileName,
            const unsigned char __RPC_FAR *lpszDisplayName,
            unsigned int eraseLevel);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *RandSet )( 
            IPSFileServices __RPC_FAR * This,
            LPVOID pBuffer,
            unsigned int cbBuffer);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetDefaultHash )( 
            IPSFileServices __RPC_FAR * This,
            IPSHash __RPC_FAR *__RPC_FAR *ppHash);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetDefaultCipher )( 
            IPSFileServices __RPC_FAR * This,
            EPSExportStatus export,
            IPSBlockCipher __RPC_FAR *__RPC_FAR *ppCipher);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetDefaultProtocol )( 
            IPSFileServices __RPC_FAR * This,
            IPSStreamBlockCipher __RPC_FAR *__RPC_FAR *ppStreamBlockCipher);
        
        END_INTERFACE
    } IPSFileServicesVtbl;

    interface IPSFileServices
    {
        CONST_VTBL struct IPSFileServicesVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IPSFileServices_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IPSFileServices_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IPSFileServices_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IPSFileServices_EncryptFile(This,pProgress,lpszInFileName,lpszPassPhrase,bDontHashKey,lpszOutFileName,lpszUserHint)	\
    (This)->lpVtbl -> EncryptFile(This,pProgress,lpszInFileName,lpszPassPhrase,bDontHashKey,lpszOutFileName,lpszUserHint)

#define IPSFileServices_DecryptFile(This,pProgress,lpszInFileName,lpszPassPhrase,bDontHashKey,lpszOutFileName)	\
    (This)->lpVtbl -> DecryptFile(This,pProgress,lpszInFileName,lpszPassPhrase,bDontHashKey,lpszOutFileName)

#define IPSFileServices_QueryEncryptedFileInfo(This,lpszInFileName,pFileInfo)	\
    (This)->lpVtbl -> QueryEncryptedFileInfo(This,lpszInFileName,pFileInfo)

#define IPSFileServices_EraseFile(This,pProgress,lpszFileName,lpszDisplayName,eraseLevel)	\
    (This)->lpVtbl -> EraseFile(This,pProgress,lpszFileName,lpszDisplayName,eraseLevel)

#define IPSFileServices_RandSet(This,pBuffer,cbBuffer)	\
    (This)->lpVtbl -> RandSet(This,pBuffer,cbBuffer)

#define IPSFileServices_GetDefaultHash(This,ppHash)	\
    (This)->lpVtbl -> GetDefaultHash(This,ppHash)

#define IPSFileServices_GetDefaultCipher(This,export,ppCipher)	\
    (This)->lpVtbl -> GetDefaultCipher(This,export,ppCipher)

#define IPSFileServices_GetDefaultProtocol(This,ppStreamBlockCipher)	\
    (This)->lpVtbl -> GetDefaultProtocol(This,ppStreamBlockCipher)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE IPSFileServices_EncryptFile_Proxy( 
    IPSFileServices __RPC_FAR * This,
    IPSFileProgress __RPC_FAR *pProgress,
    const unsigned char __RPC_FAR *lpszInFileName,
    unsigned char __RPC_FAR *lpszPassPhrase,
    BOOL bDontHashKey,
    const unsigned char __RPC_FAR *lpszOutFileName,
    const unsigned char __RPC_FAR *lpszUserHint);


void __RPC_STUB IPSFileServices_EncryptFile_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IPSFileServices_DecryptFile_Proxy( 
    IPSFileServices __RPC_FAR * This,
    IPSFileProgress __RPC_FAR *pProgress,
    const unsigned char __RPC_FAR *lpszInFileName,
    unsigned char __RPC_FAR *lpszPassPhrase,
    BOOL bDontHashKey,
    const unsigned char __RPC_FAR *lpszOutFileName);


void __RPC_STUB IPSFileServices_DecryptFile_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IPSFileServices_QueryEncryptedFileInfo_Proxy( 
    IPSFileServices __RPC_FAR * This,
    const unsigned char __RPC_FAR *lpszInFileName,
    SPSFileInfo __RPC_FAR *pFileInfo);


void __RPC_STUB IPSFileServices_QueryEncryptedFileInfo_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IPSFileServices_EraseFile_Proxy( 
    IPSFileServices __RPC_FAR * This,
    IPSFileProgress __RPC_FAR *pProgress,
    const unsigned char __RPC_FAR *lpszFileName,
    const unsigned char __RPC_FAR *lpszDisplayName,
    unsigned int eraseLevel);


void __RPC_STUB IPSFileServices_EraseFile_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IPSFileServices_RandSet_Proxy( 
    IPSFileServices __RPC_FAR * This,
    LPVOID pBuffer,
    unsigned int cbBuffer);


void __RPC_STUB IPSFileServices_RandSet_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IPSFileServices_GetDefaultHash_Proxy( 
    IPSFileServices __RPC_FAR * This,
    IPSHash __RPC_FAR *__RPC_FAR *ppHash);


void __RPC_STUB IPSFileServices_GetDefaultHash_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IPSFileServices_GetDefaultCipher_Proxy( 
    IPSFileServices __RPC_FAR * This,
    EPSExportStatus export,
    IPSBlockCipher __RPC_FAR *__RPC_FAR *ppCipher);


void __RPC_STUB IPSFileServices_GetDefaultCipher_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IPSFileServices_GetDefaultProtocol_Proxy( 
    IPSFileServices __RPC_FAR * This,
    IPSStreamBlockCipher __RPC_FAR *__RPC_FAR *ppStreamBlockCipher);


void __RPC_STUB IPSFileServices_GetDefaultProtocol_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IPSFileServices_INTERFACE_DEFINED__ */


#ifndef __IPSFileRecord_INTERFACE_DEFINED__
#define __IPSFileRecord_INTERFACE_DEFINED__

/****************************************
 * Generated header for interface: IPSFileRecord
 * at Tue Nov 23 05:28:28 1999
 * using MIDL 3.01.75
 ****************************************/
/* [unique][uuid][object][local] */ 


typedef /* [public][public][public] */ struct  __MIDL_IPSFileRecord_0001
    {
    DWORD dwSizeof;
    FILETIME ftEntryTime;
    DWORD dwFileSizeLow;
    DWORD dwFileSizeHigh;
    }	SFRFileInfo;

typedef 
enum tagEPSFileNameID
    {	EFNInternalName	= 0,
	EFNExternalName	= EFNInternalName + 1
    }	EPSFileNameID;

typedef 
enum tagEPSSortFlags
    {	SFDescending	= 1,
	SFByDate	= 2,
	SFBySize	= 4,
	SFNoSort	= 32768
    }	EPSSortFlags;


EXTERN_C const IID IID_IPSFileRecord;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    interface DECLSPEC_UUID("8335e7da-ab3b-11ce-8468-0000b468276b")
    IPSFileRecord : public IPersistStream
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE Init( 
            unsigned char __RPC_FAR *pInternalName,
            unsigned char __RPC_FAR *pExternalName,
            SFRFileInfo __RPC_FAR *pFileInfo) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetName( 
            unsigned int whichName,
            unsigned char __RPC_FAR *pszBuffer,
            unsigned int __RPC_FAR *pcbBuffer) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetInfo( 
            SFRFileInfo __RPC_FAR *pFileInfo) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Compare( 
            IPSFileRecord __RPC_FAR *pFileOnRight,
            DWORD dwSortFlags) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IPSFileRecordVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            IPSFileRecord __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            IPSFileRecord __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            IPSFileRecord __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetClassID )( 
            IPSFileRecord __RPC_FAR * This,
            /* [out] */ CLSID __RPC_FAR *pClassID);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *IsDirty )( 
            IPSFileRecord __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Load )( 
            IPSFileRecord __RPC_FAR * This,
            /* [unique][in] */ IStream __RPC_FAR *pStm);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Save )( 
            IPSFileRecord __RPC_FAR * This,
            /* [unique][in] */ IStream __RPC_FAR *pStm,
            /* [in] */ BOOL fClearDirty);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetSizeMax )( 
            IPSFileRecord __RPC_FAR * This,
            /* [out] */ ULARGE_INTEGER __RPC_FAR *pcbSize);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Init )( 
            IPSFileRecord __RPC_FAR * This,
            unsigned char __RPC_FAR *pInternalName,
            unsigned char __RPC_FAR *pExternalName,
            SFRFileInfo __RPC_FAR *pFileInfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetName )( 
            IPSFileRecord __RPC_FAR * This,
            unsigned int whichName,
            unsigned char __RPC_FAR *pszBuffer,
            unsigned int __RPC_FAR *pcbBuffer);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetInfo )( 
            IPSFileRecord __RPC_FAR * This,
            SFRFileInfo __RPC_FAR *pFileInfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Compare )( 
            IPSFileRecord __RPC_FAR * This,
            IPSFileRecord __RPC_FAR *pFileOnRight,
            DWORD dwSortFlags);
        
        END_INTERFACE
    } IPSFileRecordVtbl;

    interface IPSFileRecord
    {
        CONST_VTBL struct IPSFileRecordVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IPSFileRecord_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IPSFileRecord_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IPSFileRecord_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IPSFileRecord_GetClassID(This,pClassID)	\
    (This)->lpVtbl -> GetClassID(This,pClassID)


#define IPSFileRecord_IsDirty(This)	\
    (This)->lpVtbl -> IsDirty(This)

#define IPSFileRecord_Load(This,pStm)	\
    (This)->lpVtbl -> Load(This,pStm)

#define IPSFileRecord_Save(This,pStm,fClearDirty)	\
    (This)->lpVtbl -> Save(This,pStm,fClearDirty)

#define IPSFileRecord_GetSizeMax(This,pcbSize)	\
    (This)->lpVtbl -> GetSizeMax(This,pcbSize)


#define IPSFileRecord_Init(This,pInternalName,pExternalName,pFileInfo)	\
    (This)->lpVtbl -> Init(This,pInternalName,pExternalName,pFileInfo)

#define IPSFileRecord_GetName(This,whichName,pszBuffer,pcbBuffer)	\
    (This)->lpVtbl -> GetName(This,whichName,pszBuffer,pcbBuffer)

#define IPSFileRecord_GetInfo(This,pFileInfo)	\
    (This)->lpVtbl -> GetInfo(This,pFileInfo)

#define IPSFileRecord_Compare(This,pFileOnRight,dwSortFlags)	\
    (This)->lpVtbl -> Compare(This,pFileOnRight,dwSortFlags)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE IPSFileRecord_Init_Proxy( 
    IPSFileRecord __RPC_FAR * This,
    unsigned char __RPC_FAR *pInternalName,
    unsigned char __RPC_FAR *pExternalName,
    SFRFileInfo __RPC_FAR *pFileInfo);


void __RPC_STUB IPSFileRecord_Init_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IPSFileRecord_GetName_Proxy( 
    IPSFileRecord __RPC_FAR * This,
    unsigned int whichName,
    unsigned char __RPC_FAR *pszBuffer,
    unsigned int __RPC_FAR *pcbBuffer);


void __RPC_STUB IPSFileRecord_GetName_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IPSFileRecord_GetInfo_Proxy( 
    IPSFileRecord __RPC_FAR * This,
    SFRFileInfo __RPC_FAR *pFileInfo);


void __RPC_STUB IPSFileRecord_GetInfo_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IPSFileRecord_Compare_Proxy( 
    IPSFileRecord __RPC_FAR * This,
    IPSFileRecord __RPC_FAR *pFileOnRight,
    DWORD dwSortFlags);


void __RPC_STUB IPSFileRecord_Compare_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IPSFileRecord_INTERFACE_DEFINED__ */


#ifndef __IPSFileCollection_INTERFACE_DEFINED__
#define __IPSFileCollection_INTERFACE_DEFINED__

/****************************************
 * Generated header for interface: IPSFileCollection
 * at Tue Nov 23 05:28:28 1999
 * using MIDL 3.01.75
 ****************************************/
/* [unique][uuid][object][local] */ 



EXTERN_C const IID IID_IPSFileCollection;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    interface DECLSPEC_UUID("8335e7db-ab3b-11ce-8468-0000b468276b")
    IPSFileCollection : public IPersistStream
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE AddRecord( 
            IPSFileRecord __RPC_FAR *pFileRecord) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE RemoveRecord( 
            IPSFileRecord __RPC_FAR *pFileRecord) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE EnumRecords( 
            IEnumUnknown __RPC_FAR *__RPC_FAR *ppEnum) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE FindRecord( 
            unsigned char __RPC_FAR *pwszInternalName,
            IPSFileRecord __RPC_FAR *__RPC_FAR *ppItem) = 0;
        
        virtual DWORD STDMETHODCALLTYPE RecordCount( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Clear( void) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IPSFileCollectionVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            IPSFileCollection __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            IPSFileCollection __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            IPSFileCollection __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetClassID )( 
            IPSFileCollection __RPC_FAR * This,
            /* [out] */ CLSID __RPC_FAR *pClassID);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *IsDirty )( 
            IPSFileCollection __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Load )( 
            IPSFileCollection __RPC_FAR * This,
            /* [unique][in] */ IStream __RPC_FAR *pStm);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Save )( 
            IPSFileCollection __RPC_FAR * This,
            /* [unique][in] */ IStream __RPC_FAR *pStm,
            /* [in] */ BOOL fClearDirty);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetSizeMax )( 
            IPSFileCollection __RPC_FAR * This,
            /* [out] */ ULARGE_INTEGER __RPC_FAR *pcbSize);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *AddRecord )( 
            IPSFileCollection __RPC_FAR * This,
            IPSFileRecord __RPC_FAR *pFileRecord);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *RemoveRecord )( 
            IPSFileCollection __RPC_FAR * This,
            IPSFileRecord __RPC_FAR *pFileRecord);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *EnumRecords )( 
            IPSFileCollection __RPC_FAR * This,
            IEnumUnknown __RPC_FAR *__RPC_FAR *ppEnum);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *FindRecord )( 
            IPSFileCollection __RPC_FAR * This,
            unsigned char __RPC_FAR *pwszInternalName,
            IPSFileRecord __RPC_FAR *__RPC_FAR *ppItem);
        
        DWORD ( STDMETHODCALLTYPE __RPC_FAR *RecordCount )( 
            IPSFileCollection __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Clear )( 
            IPSFileCollection __RPC_FAR * This);
        
        END_INTERFACE
    } IPSFileCollectionVtbl;

    interface IPSFileCollection
    {
        CONST_VTBL struct IPSFileCollectionVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IPSFileCollection_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IPSFileCollection_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IPSFileCollection_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IPSFileCollection_GetClassID(This,pClassID)	\
    (This)->lpVtbl -> GetClassID(This,pClassID)


#define IPSFileCollection_IsDirty(This)	\
    (This)->lpVtbl -> IsDirty(This)

#define IPSFileCollection_Load(This,pStm)	\
    (This)->lpVtbl -> Load(This,pStm)

#define IPSFileCollection_Save(This,pStm,fClearDirty)	\
    (This)->lpVtbl -> Save(This,pStm,fClearDirty)

#define IPSFileCollection_GetSizeMax(This,pcbSize)	\
    (This)->lpVtbl -> GetSizeMax(This,pcbSize)


#define IPSFileCollection_AddRecord(This,pFileRecord)	\
    (This)->lpVtbl -> AddRecord(This,pFileRecord)

#define IPSFileCollection_RemoveRecord(This,pFileRecord)	\
    (This)->lpVtbl -> RemoveRecord(This,pFileRecord)

#define IPSFileCollection_EnumRecords(This,ppEnum)	\
    (This)->lpVtbl -> EnumRecords(This,ppEnum)

#define IPSFileCollection_FindRecord(This,pwszInternalName,ppItem)	\
    (This)->lpVtbl -> FindRecord(This,pwszInternalName,ppItem)

#define IPSFileCollection_RecordCount(This)	\
    (This)->lpVtbl -> RecordCount(This)

#define IPSFileCollection_Clear(This)	\
    (This)->lpVtbl -> Clear(This)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE IPSFileCollection_AddRecord_Proxy( 
    IPSFileCollection __RPC_FAR * This,
    IPSFileRecord __RPC_FAR *pFileRecord);


void __RPC_STUB IPSFileCollection_AddRecord_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IPSFileCollection_RemoveRecord_Proxy( 
    IPSFileCollection __RPC_FAR * This,
    IPSFileRecord __RPC_FAR *pFileRecord);


void __RPC_STUB IPSFileCollection_RemoveRecord_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IPSFileCollection_EnumRecords_Proxy( 
    IPSFileCollection __RPC_FAR * This,
    IEnumUnknown __RPC_FAR *__RPC_FAR *ppEnum);


void __RPC_STUB IPSFileCollection_EnumRecords_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IPSFileCollection_FindRecord_Proxy( 
    IPSFileCollection __RPC_FAR * This,
    unsigned char __RPC_FAR *pwszInternalName,
    IPSFileRecord __RPC_FAR *__RPC_FAR *ppItem);


void __RPC_STUB IPSFileCollection_FindRecord_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


DWORD STDMETHODCALLTYPE IPSFileCollection_RecordCount_Proxy( 
    IPSFileCollection __RPC_FAR * This);


void __RPC_STUB IPSFileCollection_RecordCount_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IPSFileCollection_Clear_Proxy( 
    IPSFileCollection __RPC_FAR * This);


void __RPC_STUB IPSFileCollection_Clear_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IPSFileCollection_INTERFACE_DEFINED__ */


#ifndef __IPSFileRepository_INTERFACE_DEFINED__
#define __IPSFileRepository_INTERFACE_DEFINED__

/****************************************
 * Generated header for interface: IPSFileRepository
 * at Tue Nov 23 05:28:28 1999
 * using MIDL 3.01.75
 ****************************************/
/* [unique][uuid][object][local] */ 


typedef struct  tagSFRDriveInfo
    {
    DWORD dwSizeof;
    unsigned char driveLetter;
    HRESULT status;
    unsigned int itemCount;
    }	SFRDriveInfo;


EXTERN_C const IID IID_IPSFileRepository;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    interface DECLSPEC_UUID("8335e7d5-ab3b-11ce-8468-0000b468276b")
    IPSFileRepository : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE Open( 
            unsigned char __RPC_FAR *pwcsRootName,
            BOOL bDirectoryPerUser,
            REFCLSID rFolderClsId) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Close( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE EnumObjects( 
            DWORD dwEnumFlags,
            IEnumUnknown __RPC_FAR *__RPC_FAR *ppEnum) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE AddToCollection( 
            unsigned char __RPC_FAR *pszUserName,
            unsigned char __RPC_FAR *pszName) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE RemoveFromCollection( 
            IPSFileRecord __RPC_FAR *pFileToRemove,
            unsigned char __RPC_FAR *pszPath) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetInternalName( 
            IPSFileRecord __RPC_FAR *pFile,
            unsigned char __RPC_FAR *pBuffer,
            unsigned int __RPC_FAR *pcbBuffer) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Clear( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetDriveInfo( 
            SFRDriveInfo __RPC_FAR *pInfo) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Rebuild( 
            unsigned char driveLetter) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IPSFileRepositoryVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            IPSFileRepository __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            IPSFileRepository __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            IPSFileRepository __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Open )( 
            IPSFileRepository __RPC_FAR * This,
            unsigned char __RPC_FAR *pwcsRootName,
            BOOL bDirectoryPerUser,
            REFCLSID rFolderClsId);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Close )( 
            IPSFileRepository __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *EnumObjects )( 
            IPSFileRepository __RPC_FAR * This,
            DWORD dwEnumFlags,
            IEnumUnknown __RPC_FAR *__RPC_FAR *ppEnum);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *AddToCollection )( 
            IPSFileRepository __RPC_FAR * This,
            unsigned char __RPC_FAR *pszUserName,
            unsigned char __RPC_FAR *pszName);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *RemoveFromCollection )( 
            IPSFileRepository __RPC_FAR * This,
            IPSFileRecord __RPC_FAR *pFileToRemove,
            unsigned char __RPC_FAR *pszPath);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetInternalName )( 
            IPSFileRepository __RPC_FAR * This,
            IPSFileRecord __RPC_FAR *pFile,
            unsigned char __RPC_FAR *pBuffer,
            unsigned int __RPC_FAR *pcbBuffer);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Clear )( 
            IPSFileRepository __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetDriveInfo )( 
            IPSFileRepository __RPC_FAR * This,
            SFRDriveInfo __RPC_FAR *pInfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Rebuild )( 
            IPSFileRepository __RPC_FAR * This,
            unsigned char driveLetter);
        
        END_INTERFACE
    } IPSFileRepositoryVtbl;

    interface IPSFileRepository
    {
        CONST_VTBL struct IPSFileRepositoryVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IPSFileRepository_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IPSFileRepository_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IPSFileRepository_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IPSFileRepository_Open(This,pwcsRootName,bDirectoryPerUser,rFolderClsId)	\
    (This)->lpVtbl -> Open(This,pwcsRootName,bDirectoryPerUser,rFolderClsId)

#define IPSFileRepository_Close(This)	\
    (This)->lpVtbl -> Close(This)

#define IPSFileRepository_EnumObjects(This,dwEnumFlags,ppEnum)	\
    (This)->lpVtbl -> EnumObjects(This,dwEnumFlags,ppEnum)

#define IPSFileRepository_AddToCollection(This,pszUserName,pszName)	\
    (This)->lpVtbl -> AddToCollection(This,pszUserName,pszName)

#define IPSFileRepository_RemoveFromCollection(This,pFileToRemove,pszPath)	\
    (This)->lpVtbl -> RemoveFromCollection(This,pFileToRemove,pszPath)

#define IPSFileRepository_GetInternalName(This,pFile,pBuffer,pcbBuffer)	\
    (This)->lpVtbl -> GetInternalName(This,pFile,pBuffer,pcbBuffer)

#define IPSFileRepository_Clear(This)	\
    (This)->lpVtbl -> Clear(This)

#define IPSFileRepository_GetDriveInfo(This,pInfo)	\
    (This)->lpVtbl -> GetDriveInfo(This,pInfo)

#define IPSFileRepository_Rebuild(This,driveLetter)	\
    (This)->lpVtbl -> Rebuild(This,driveLetter)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE IPSFileRepository_Open_Proxy( 
    IPSFileRepository __RPC_FAR * This,
    unsigned char __RPC_FAR *pwcsRootName,
    BOOL bDirectoryPerUser,
    REFCLSID rFolderClsId);


void __RPC_STUB IPSFileRepository_Open_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IPSFileRepository_Close_Proxy( 
    IPSFileRepository __RPC_FAR * This);


void __RPC_STUB IPSFileRepository_Close_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IPSFileRepository_EnumObjects_Proxy( 
    IPSFileRepository __RPC_FAR * This,
    DWORD dwEnumFlags,
    IEnumUnknown __RPC_FAR *__RPC_FAR *ppEnum);


void __RPC_STUB IPSFileRepository_EnumObjects_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IPSFileRepository_AddToCollection_Proxy( 
    IPSFileRepository __RPC_FAR * This,
    unsigned char __RPC_FAR *pszUserName,
    unsigned char __RPC_FAR *pszName);


void __RPC_STUB IPSFileRepository_AddToCollection_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IPSFileRepository_RemoveFromCollection_Proxy( 
    IPSFileRepository __RPC_FAR * This,
    IPSFileRecord __RPC_FAR *pFileToRemove,
    unsigned char __RPC_FAR *pszPath);


void __RPC_STUB IPSFileRepository_RemoveFromCollection_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IPSFileRepository_GetInternalName_Proxy( 
    IPSFileRepository __RPC_FAR * This,
    IPSFileRecord __RPC_FAR *pFile,
    unsigned char __RPC_FAR *pBuffer,
    unsigned int __RPC_FAR *pcbBuffer);


void __RPC_STUB IPSFileRepository_GetInternalName_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IPSFileRepository_Clear_Proxy( 
    IPSFileRepository __RPC_FAR * This);


void __RPC_STUB IPSFileRepository_Clear_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IPSFileRepository_GetDriveInfo_Proxy( 
    IPSFileRepository __RPC_FAR * This,
    SFRDriveInfo __RPC_FAR *pInfo);


void __RPC_STUB IPSFileRepository_GetDriveInfo_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IPSFileRepository_Rebuild_Proxy( 
    IPSFileRepository __RPC_FAR * This,
    unsigned char driveLetter);


void __RPC_STUB IPSFileRepository_Rebuild_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IPSFileRepository_INTERFACE_DEFINED__ */


#ifndef __IPSBatchProgress_INTERFACE_DEFINED__
#define __IPSBatchProgress_INTERFACE_DEFINED__

/****************************************
 * Generated header for interface: IPSBatchProgress
 * at Tue Nov 23 05:28:28 1999
 * using MIDL 3.01.75
 ****************************************/
/* [unique][uuid][object][local] */ 



EXTERN_C const IID IID_IPSBatchProgress;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    interface DECLSPEC_UUID("8335e7de-ab3b-11ce-8468-0000b468276b")
    IPSBatchProgress : public IPSFileProgress
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE OnProcessEnd( void) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IPSBatchProgressVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            IPSBatchProgress __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            IPSBatchProgress __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            IPSBatchProgress __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *OnProgress )( 
            IPSBatchProgress __RPC_FAR * This,
            unsigned int chunkSize,
            unsigned int passNumber,
            unsigned int totalPasses);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *OnFileStart )( 
            IPSBatchProgress __RPC_FAR * This,
            const unsigned char __RPC_FAR *pszTargetFile,
            DWORD fileSize,
            DWORD fileSizeHigh,
            EFPProcess process,
            unsigned int param);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *OnProcessEnd )( 
            IPSBatchProgress __RPC_FAR * This);
        
        END_INTERFACE
    } IPSBatchProgressVtbl;

    interface IPSBatchProgress
    {
        CONST_VTBL struct IPSBatchProgressVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IPSBatchProgress_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IPSBatchProgress_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IPSBatchProgress_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IPSBatchProgress_OnProgress(This,chunkSize,passNumber,totalPasses)	\
    (This)->lpVtbl -> OnProgress(This,chunkSize,passNumber,totalPasses)


#define IPSBatchProgress_OnFileStart(This,pszTargetFile,fileSize,fileSizeHigh,process,param)	\
    (This)->lpVtbl -> OnFileStart(This,pszTargetFile,fileSize,fileSizeHigh,process,param)


#define IPSBatchProgress_OnProcessEnd(This)	\
    (This)->lpVtbl -> OnProcessEnd(This)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE IPSBatchProgress_OnProcessEnd_Proxy( 
    IPSBatchProgress __RPC_FAR * This);


void __RPC_STUB IPSBatchProgress_OnProcessEnd_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IPSBatchProgress_INTERFACE_DEFINED__ */


#ifndef __IPSChangeNotify_INTERFACE_DEFINED__
#define __IPSChangeNotify_INTERFACE_DEFINED__

/****************************************
 * Generated header for interface: IPSChangeNotify
 * at Tue Nov 23 05:28:28 1999
 * using MIDL 3.01.75
 ****************************************/
/* [unique][uuid][object][local] */ 



EXTERN_C const IID IID_IPSChangeNotify;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    interface DECLSPEC_UUID("8335e7df-ab3b-11ce-8468-0000b468276b")
    IPSChangeNotify : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE OnChange( 
            IUnknown __RPC_FAR *pUnk) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IPSChangeNotifyVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            IPSChangeNotify __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            IPSChangeNotify __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            IPSChangeNotify __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *OnChange )( 
            IPSChangeNotify __RPC_FAR * This,
            IUnknown __RPC_FAR *pUnk);
        
        END_INTERFACE
    } IPSChangeNotifyVtbl;

    interface IPSChangeNotify
    {
        CONST_VTBL struct IPSChangeNotifyVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IPSChangeNotify_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IPSChangeNotify_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IPSChangeNotify_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IPSChangeNotify_OnChange(This,pUnk)	\
    (This)->lpVtbl -> OnChange(This,pUnk)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE IPSChangeNotify_OnChange_Proxy( 
    IPSChangeNotify __RPC_FAR * This,
    IUnknown __RPC_FAR *pUnk);


void __RPC_STUB IPSChangeNotify_OnChange_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IPSChangeNotify_INTERFACE_DEFINED__ */


#ifndef __IPSNotifyManager_INTERFACE_DEFINED__
#define __IPSNotifyManager_INTERFACE_DEFINED__

/****************************************
 * Generated header for interface: IPSNotifyManager
 * at Tue Nov 23 05:28:28 1999
 * using MIDL 3.01.75
 ****************************************/
/* [unique][uuid][object][local] */ 



EXTERN_C const IID IID_IPSNotifyManager;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    interface DECLSPEC_UUID("8335e7e0-ab3b-11ce-8468-0000b468276b")
    IPSNotifyManager : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE Notify( 
            IPSChangeNotify __RPC_FAR *pNotifier) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE StopNotify( 
            IPSChangeNotify __RPC_FAR *pNotifier) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IPSNotifyManagerVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            IPSNotifyManager __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            IPSNotifyManager __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            IPSNotifyManager __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Notify )( 
            IPSNotifyManager __RPC_FAR * This,
            IPSChangeNotify __RPC_FAR *pNotifier);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *StopNotify )( 
            IPSNotifyManager __RPC_FAR * This,
            IPSChangeNotify __RPC_FAR *pNotifier);
        
        END_INTERFACE
    } IPSNotifyManagerVtbl;

    interface IPSNotifyManager
    {
        CONST_VTBL struct IPSNotifyManagerVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IPSNotifyManager_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IPSNotifyManager_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IPSNotifyManager_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IPSNotifyManager_Notify(This,pNotifier)	\
    (This)->lpVtbl -> Notify(This,pNotifier)

#define IPSNotifyManager_StopNotify(This,pNotifier)	\
    (This)->lpVtbl -> StopNotify(This,pNotifier)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE IPSNotifyManager_Notify_Proxy( 
    IPSNotifyManager __RPC_FAR * This,
    IPSChangeNotify __RPC_FAR *pNotifier);


void __RPC_STUB IPSNotifyManager_Notify_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IPSNotifyManager_StopNotify_Proxy( 
    IPSNotifyManager __RPC_FAR * This,
    IPSChangeNotify __RPC_FAR *pNotifier);


void __RPC_STUB IPSNotifyManager_StopNotify_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IPSNotifyManager_INTERFACE_DEFINED__ */


#ifndef __IPSShredder_INTERFACE_DEFINED__
#define __IPSShredder_INTERFACE_DEFINED__

/****************************************
 * Generated header for interface: IPSShredder
 * at Tue Nov 23 05:28:28 1999
 * using MIDL 3.01.75
 ****************************************/
/* [unique][uuid][object][local] */ 


typedef /* [public] */ 
enum __MIDL_IPSShredder_0001
    {	ESSPerMachine	= 0,
	ESSPerUser	= ESSPerMachine + 1
    }	EShredScope;

typedef /* [public] */ 
enum __MIDL_IPSShredder_0002
    {	ESMDemand	= 0,
	ESMInstant	= ESMDemand + 1
    }	EShredMode;

typedef /* [public] */ 
enum __MIDL_IPSShredder_0003
    {	ESLWipe	= 0,
	ESLErase	= ESLWipe + 1,
	ESLDisintegrate	= ESLErase + 1,
	ESLObliterate	= ESLDisintegrate + 1
    }	EShredLevel;

typedef /* [public] */ 
enum __MIDL_IPSShredder_0004
    {	ESFPromptBeforeShred	= 1,
	ESFCantChangeScope	= 2,
	ESFNotEmpty	= 0x80000000
    }	EShredFlags;

typedef /* [public][public][public] */ 
enum __MIDL_IPSShredder_0005
    {	ESPScope	= 0,
	ESPMode	= ESPScope + 1,
	ESPLevel	= ESPMode + 1,
	ESPFlags	= ESPLevel + 1
    }	EShredderParam;


EXTERN_C const IID IID_IPSShredder;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    interface DECLSPEC_UUID("8335e7d7-ab3b-11ce-8468-0000b468276b")
    IPSShredder : public IUnknown
    {
    public:
        virtual DWORD STDMETHODCALLTYPE GetParam( 
            EShredderParam param) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetParam( 
            EShredderParam param,
            DWORD value) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE ShredNow( 
            IPSBatchProgress __RPC_FAR *pProgress) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE EnumObjects( 
            DWORD dwEnumFlags,
            IEnumUnknown __RPC_FAR *__RPC_FAR *ppEnum) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE MoveToShredder( 
            IPSFileProgress __RPC_FAR *pProgress,
            unsigned char __RPC_FAR *pszFileName,
            unsigned char __RPC_FAR *pszDisplayName) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE RemoveFromShredder( 
            IPSFileRecord __RPC_FAR *pFileToRemove,
            unsigned char __RPC_FAR *pszPath) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE RemoveAndShred( 
            IPSFileProgress __RPC_FAR *pProgress,
            IPSFileRecord __RPC_FAR *pFileToRemove) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IPSShredderVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            IPSShredder __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            IPSShredder __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            IPSShredder __RPC_FAR * This);
        
        DWORD ( STDMETHODCALLTYPE __RPC_FAR *GetParam )( 
            IPSShredder __RPC_FAR * This,
            EShredderParam param);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetParam )( 
            IPSShredder __RPC_FAR * This,
            EShredderParam param,
            DWORD value);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *ShredNow )( 
            IPSShredder __RPC_FAR * This,
            IPSBatchProgress __RPC_FAR *pProgress);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *EnumObjects )( 
            IPSShredder __RPC_FAR * This,
            DWORD dwEnumFlags,
            IEnumUnknown __RPC_FAR *__RPC_FAR *ppEnum);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *MoveToShredder )( 
            IPSShredder __RPC_FAR * This,
            IPSFileProgress __RPC_FAR *pProgress,
            unsigned char __RPC_FAR *pszFileName,
            unsigned char __RPC_FAR *pszDisplayName);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *RemoveFromShredder )( 
            IPSShredder __RPC_FAR * This,
            IPSFileRecord __RPC_FAR *pFileToRemove,
            unsigned char __RPC_FAR *pszPath);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *RemoveAndShred )( 
            IPSShredder __RPC_FAR * This,
            IPSFileProgress __RPC_FAR *pProgress,
            IPSFileRecord __RPC_FAR *pFileToRemove);
        
        END_INTERFACE
    } IPSShredderVtbl;

    interface IPSShredder
    {
        CONST_VTBL struct IPSShredderVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IPSShredder_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IPSShredder_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IPSShredder_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IPSShredder_GetParam(This,param)	\
    (This)->lpVtbl -> GetParam(This,param)

#define IPSShredder_SetParam(This,param,value)	\
    (This)->lpVtbl -> SetParam(This,param,value)

#define IPSShredder_ShredNow(This,pProgress)	\
    (This)->lpVtbl -> ShredNow(This,pProgress)

#define IPSShredder_EnumObjects(This,dwEnumFlags,ppEnum)	\
    (This)->lpVtbl -> EnumObjects(This,dwEnumFlags,ppEnum)

#define IPSShredder_MoveToShredder(This,pProgress,pszFileName,pszDisplayName)	\
    (This)->lpVtbl -> MoveToShredder(This,pProgress,pszFileName,pszDisplayName)

#define IPSShredder_RemoveFromShredder(This,pFileToRemove,pszPath)	\
    (This)->lpVtbl -> RemoveFromShredder(This,pFileToRemove,pszPath)

#define IPSShredder_RemoveAndShred(This,pProgress,pFileToRemove)	\
    (This)->lpVtbl -> RemoveAndShred(This,pProgress,pFileToRemove)

#endif /* COBJMACROS */


#endif 	/* C style interface */



DWORD STDMETHODCALLTYPE IPSShredder_GetParam_Proxy( 
    IPSShredder __RPC_FAR * This,
    EShredderParam param);


void __RPC_STUB IPSShredder_GetParam_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IPSShredder_SetParam_Proxy( 
    IPSShredder __RPC_FAR * This,
    EShredderParam param,
    DWORD value);


void __RPC_STUB IPSShredder_SetParam_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IPSShredder_ShredNow_Proxy( 
    IPSShredder __RPC_FAR * This,
    IPSBatchProgress __RPC_FAR *pProgress);


void __RPC_STUB IPSShredder_ShredNow_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IPSShredder_EnumObjects_Proxy( 
    IPSShredder __RPC_FAR * This,
    DWORD dwEnumFlags,
    IEnumUnknown __RPC_FAR *__RPC_FAR *ppEnum);


void __RPC_STUB IPSShredder_EnumObjects_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IPSShredder_MoveToShredder_Proxy( 
    IPSShredder __RPC_FAR * This,
    IPSFileProgress __RPC_FAR *pProgress,
    unsigned char __RPC_FAR *pszFileName,
    unsigned char __RPC_FAR *pszDisplayName);


void __RPC_STUB IPSShredder_MoveToShredder_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IPSShredder_RemoveFromShredder_Proxy( 
    IPSShredder __RPC_FAR * This,
    IPSFileRecord __RPC_FAR *pFileToRemove,
    unsigned char __RPC_FAR *pszPath);


void __RPC_STUB IPSShredder_RemoveFromShredder_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IPSShredder_RemoveAndShred_Proxy( 
    IPSShredder __RPC_FAR * This,
    IPSFileProgress __RPC_FAR *pProgress,
    IPSFileRecord __RPC_FAR *pFileToRemove);


void __RPC_STUB IPSShredder_RemoveAndShred_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IPSShredder_INTERFACE_DEFINED__ */


#ifndef __IPSVault_INTERFACE_DEFINED__
#define __IPSVault_INTERFACE_DEFINED__

/****************************************
 * Generated header for interface: IPSVault
 * at Tue Nov 23 05:28:28 1999
 * using MIDL 3.01.75
 ****************************************/
/* [unique][uuid][object][local] */ 


typedef /* [public] */ 
enum __MIDL_IPSVault_0001
    {	EVSPerMachine	= 0,
	EVSPerUser	= EVSPerMachine + 1
    }	EVaultScope;

typedef /* [public] */ 
enum __MIDL_IPSVault_0002
    {	EVSMShredImmediate	= 0,
	EVSMMoveToShredder	= EVSMShredImmediate + 1
    }	EVaultShredMode;

typedef /* [public] */ 
enum __MIDL_IPSVault_0003
    {	EVLMExplicit	= 0,
	EVLMDelayAfterOpen	= EVLMExplicit + 1,
	EVLMDelayAfterUse	= EVLMDelayAfterOpen + 1,
	EVLMOnInsert	= EVLMDelayAfterUse + 1
    }	EVaultLockMode;

typedef /* [public] */ 
enum __MIDL_IPSVault_0004
    {	EVPMUseVaultPass	= 0,
	EVPMUseFilePass	= EVPMUseVaultPass + 1
    }	EVaultPassMode;

typedef /* [public] */ 
enum __MIDL_IPSVault_0005
    {	EVLSLocked	= 0,
	EVLSUnlocked	= EVLSLocked + 1,
	EVLSUpdate	= EVLSUnlocked + 1
    }	EVaultLockState;

typedef /* [public] */ 
enum __MIDL_IPSVault_0006
    {	EVFNoVaultPassphrase	= 1,
	EVFCantChangeScope	= 2,
	EVFDestroysOriginal	= 4
    }	EVaultFlags;

typedef /* [public][public][public][public][public] */ 
enum __MIDL_IPSVault_0007
    {	EVPScope	= 0,
	EVPShredMode	= EVPScope + 1,
	EVPLockMode	= EVPShredMode + 1,
	EVPLockTime	= EVPLockMode + 1,
	EVPPassMode	= EVPLockTime + 1,
	EVPLockState	= EVPPassMode + 1,
	EVPPassHint	= EVPLockState + 1,
	EVPPassphrase	= EVPPassHint + 1,
	EVPMultifile	= EVPPassphrase + 1,
	EVPFlags	= EVPMultifile + 1,
	EVPKeySize	= EVPFlags + 1
    }	EVaultParam;


EXTERN_C const IID IID_IPSVault;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    interface DECLSPEC_UUID("8335e7d6-ab3b-11ce-8468-0000b468276b")
    IPSVault : public IUnknown
    {
    public:
        virtual DWORD STDMETHODCALLTYPE GetParam( 
            EVaultParam param) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetParamString( 
            EVaultParam param,
            unsigned char __RPC_FAR *pBuffer,
            unsigned int cbBuffer) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetParam( 
            EVaultParam param,
            DWORD value) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetParamString( 
            EVaultParam param,
            unsigned char __RPC_FAR *pBuffer) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE EnumObjects( 
            DWORD dwEnumFlags,
            IEnumUnknown __RPC_FAR *__RPC_FAR *ppEnum) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE QueryVaultFileInfo( 
            IPSFileRecord __RPC_FAR *pFileToExamine,
            SPSFileInfo __RPC_FAR *pFileInfo) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE MoveToVault( 
            IPSFileProgress __RPC_FAR *pProgress,
            unsigned char __RPC_FAR *pszPassPhrase,
            BOOL bDontHashKey,
            BOOL bDontEraseSource,
            unsigned char __RPC_FAR *pszFileName,
            unsigned char __RPC_FAR *pszUserHint) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE RemoveFromVault( 
            IPSFileProgress __RPC_FAR *pProgress,
            unsigned char __RPC_FAR *pszPassPhrase,
            BOOL bDontHashKey,
            IPSFileRecord __RPC_FAR *pFileToRemove,
            unsigned char __RPC_FAR *pszPath) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Insert( 
            BOOL bDontEraseSource,
            unsigned char __RPC_FAR *lpszPath) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Extract( 
            IPSFileRecord __RPC_FAR *pFileToExtract,
            unsigned char __RPC_FAR *lpszPath) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Copy( 
            IPSFileRecord __RPC_FAR *pFileToCopy,
            unsigned char __RPC_FAR *lpszPath) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Discard( 
            IPSFileProgress __RPC_FAR *pProgress,
            IPSFileRecord __RPC_FAR *pFileToRemove) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IPSVaultVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            IPSVault __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            IPSVault __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            IPSVault __RPC_FAR * This);
        
        DWORD ( STDMETHODCALLTYPE __RPC_FAR *GetParam )( 
            IPSVault __RPC_FAR * This,
            EVaultParam param);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetParamString )( 
            IPSVault __RPC_FAR * This,
            EVaultParam param,
            unsigned char __RPC_FAR *pBuffer,
            unsigned int cbBuffer);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetParam )( 
            IPSVault __RPC_FAR * This,
            EVaultParam param,
            DWORD value);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetParamString )( 
            IPSVault __RPC_FAR * This,
            EVaultParam param,
            unsigned char __RPC_FAR *pBuffer);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *EnumObjects )( 
            IPSVault __RPC_FAR * This,
            DWORD dwEnumFlags,
            IEnumUnknown __RPC_FAR *__RPC_FAR *ppEnum);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryVaultFileInfo )( 
            IPSVault __RPC_FAR * This,
            IPSFileRecord __RPC_FAR *pFileToExamine,
            SPSFileInfo __RPC_FAR *pFileInfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *MoveToVault )( 
            IPSVault __RPC_FAR * This,
            IPSFileProgress __RPC_FAR *pProgress,
            unsigned char __RPC_FAR *pszPassPhrase,
            BOOL bDontHashKey,
            BOOL bDontEraseSource,
            unsigned char __RPC_FAR *pszFileName,
            unsigned char __RPC_FAR *pszUserHint);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *RemoveFromVault )( 
            IPSVault __RPC_FAR * This,
            IPSFileProgress __RPC_FAR *pProgress,
            unsigned char __RPC_FAR *pszPassPhrase,
            BOOL bDontHashKey,
            IPSFileRecord __RPC_FAR *pFileToRemove,
            unsigned char __RPC_FAR *pszPath);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Insert )( 
            IPSVault __RPC_FAR * This,
            BOOL bDontEraseSource,
            unsigned char __RPC_FAR *lpszPath);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Extract )( 
            IPSVault __RPC_FAR * This,
            IPSFileRecord __RPC_FAR *pFileToExtract,
            unsigned char __RPC_FAR *lpszPath);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Copy )( 
            IPSVault __RPC_FAR * This,
            IPSFileRecord __RPC_FAR *pFileToCopy,
            unsigned char __RPC_FAR *lpszPath);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Discard )( 
            IPSVault __RPC_FAR * This,
            IPSFileProgress __RPC_FAR *pProgress,
            IPSFileRecord __RPC_FAR *pFileToRemove);
        
        END_INTERFACE
    } IPSVaultVtbl;

    interface IPSVault
    {
        CONST_VTBL struct IPSVaultVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IPSVault_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IPSVault_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IPSVault_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IPSVault_GetParam(This,param)	\
    (This)->lpVtbl -> GetParam(This,param)

#define IPSVault_GetParamString(This,param,pBuffer,cbBuffer)	\
    (This)->lpVtbl -> GetParamString(This,param,pBuffer,cbBuffer)

#define IPSVault_SetParam(This,param,value)	\
    (This)->lpVtbl -> SetParam(This,param,value)

#define IPSVault_SetParamString(This,param,pBuffer)	\
    (This)->lpVtbl -> SetParamString(This,param,pBuffer)

#define IPSVault_EnumObjects(This,dwEnumFlags,ppEnum)	\
    (This)->lpVtbl -> EnumObjects(This,dwEnumFlags,ppEnum)

#define IPSVault_QueryVaultFileInfo(This,pFileToExamine,pFileInfo)	\
    (This)->lpVtbl -> QueryVaultFileInfo(This,pFileToExamine,pFileInfo)

#define IPSVault_MoveToVault(This,pProgress,pszPassPhrase,bDontHashKey,bDontEraseSource,pszFileName,pszUserHint)	\
    (This)->lpVtbl -> MoveToVault(This,pProgress,pszPassPhrase,bDontHashKey,bDontEraseSource,pszFileName,pszUserHint)

#define IPSVault_RemoveFromVault(This,pProgress,pszPassPhrase,bDontHashKey,pFileToRemove,pszPath)	\
    (This)->lpVtbl -> RemoveFromVault(This,pProgress,pszPassPhrase,bDontHashKey,pFileToRemove,pszPath)

#define IPSVault_Insert(This,bDontEraseSource,lpszPath)	\
    (This)->lpVtbl -> Insert(This,bDontEraseSource,lpszPath)

#define IPSVault_Extract(This,pFileToExtract,lpszPath)	\
    (This)->lpVtbl -> Extract(This,pFileToExtract,lpszPath)

#define IPSVault_Copy(This,pFileToCopy,lpszPath)	\
    (This)->lpVtbl -> Copy(This,pFileToCopy,lpszPath)

#define IPSVault_Discard(This,pProgress,pFileToRemove)	\
    (This)->lpVtbl -> Discard(This,pProgress,pFileToRemove)

#endif /* COBJMACROS */


#endif 	/* C style interface */



DWORD STDMETHODCALLTYPE IPSVault_GetParam_Proxy( 
    IPSVault __RPC_FAR * This,
    EVaultParam param);


void __RPC_STUB IPSVault_GetParam_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IPSVault_GetParamString_Proxy( 
    IPSVault __RPC_FAR * This,
    EVaultParam param,
    unsigned char __RPC_FAR *pBuffer,
    unsigned int cbBuffer);


void __RPC_STUB IPSVault_GetParamString_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IPSVault_SetParam_Proxy( 
    IPSVault __RPC_FAR * This,
    EVaultParam param,
    DWORD value);


void __RPC_STUB IPSVault_SetParam_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IPSVault_SetParamString_Proxy( 
    IPSVault __RPC_FAR * This,
    EVaultParam param,
    unsigned char __RPC_FAR *pBuffer);


void __RPC_STUB IPSVault_SetParamString_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IPSVault_EnumObjects_Proxy( 
    IPSVault __RPC_FAR * This,
    DWORD dwEnumFlags,
    IEnumUnknown __RPC_FAR *__RPC_FAR *ppEnum);


void __RPC_STUB IPSVault_EnumObjects_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IPSVault_QueryVaultFileInfo_Proxy( 
    IPSVault __RPC_FAR * This,
    IPSFileRecord __RPC_FAR *pFileToExamine,
    SPSFileInfo __RPC_FAR *pFileInfo);


void __RPC_STUB IPSVault_QueryVaultFileInfo_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IPSVault_MoveToVault_Proxy( 
    IPSVault __RPC_FAR * This,
    IPSFileProgress __RPC_FAR *pProgress,
    unsigned char __RPC_FAR *pszPassPhrase,
    BOOL bDontHashKey,
    BOOL bDontEraseSource,
    unsigned char __RPC_FAR *pszFileName,
    unsigned char __RPC_FAR *pszUserHint);


void __RPC_STUB IPSVault_MoveToVault_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IPSVault_RemoveFromVault_Proxy( 
    IPSVault __RPC_FAR * This,
    IPSFileProgress __RPC_FAR *pProgress,
    unsigned char __RPC_FAR *pszPassPhrase,
    BOOL bDontHashKey,
    IPSFileRecord __RPC_FAR *pFileToRemove,
    unsigned char __RPC_FAR *pszPath);


void __RPC_STUB IPSVault_RemoveFromVault_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IPSVault_Insert_Proxy( 
    IPSVault __RPC_FAR * This,
    BOOL bDontEraseSource,
    unsigned char __RPC_FAR *lpszPath);


void __RPC_STUB IPSVault_Insert_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IPSVault_Extract_Proxy( 
    IPSVault __RPC_FAR * This,
    IPSFileRecord __RPC_FAR *pFileToExtract,
    unsigned char __RPC_FAR *lpszPath);


void __RPC_STUB IPSVault_Extract_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IPSVault_Copy_Proxy( 
    IPSVault __RPC_FAR * This,
    IPSFileRecord __RPC_FAR *pFileToCopy,
    unsigned char __RPC_FAR *lpszPath);


void __RPC_STUB IPSVault_Copy_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IPSVault_Discard_Proxy( 
    IPSVault __RPC_FAR * This,
    IPSFileProgress __RPC_FAR *pProgress,
    IPSFileRecord __RPC_FAR *pFileToRemove);


void __RPC_STUB IPSVault_Discard_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IPSVault_INTERFACE_DEFINED__ */


/****************************************
 * Generated header for interface: __MIDL_itf_Crypto_0071
 * at Tue Nov 23 05:28:28 1999
 * using MIDL 3.01.75
 ****************************************/
/* [local] */ 


// End of Crypto.h


extern RPC_IF_HANDLE __MIDL_itf_Crypto_0071_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_Crypto_0071_v0_0_s_ifspec;

/* Additional Prototypes for ALL interfaces */

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif
