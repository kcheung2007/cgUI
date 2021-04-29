/* this ALWAYS GENERATED file contains the definitions for the interfaces */


/* File created by MIDL compiler version 3.01.75 */
/* at Fri Feb 06 14:08:05 1998
 */
/* Compiler settings for TitleWave.idl:
    Os (OptLev=s), W1, Zp8, env=Win32, ms_ext, c_ext
    error checks: none
*/
//@@MIDL_FILE_HEADING(  )
#include "rpc.h"
#include "rpcndr.h"
#ifndef COM_NO_WINDOWS_H
#include "windows.h"
#include "ole2.h"
#endif /*COM_NO_WINDOWS_H*/

#ifndef __TitleWave_h__
#define __TitleWave_h__

#ifdef __cplusplus
extern "C"{
#endif 

/* Forward Declarations */ 

#ifndef __ITitleWave_FWD_DEFINED__
#define __ITitleWave_FWD_DEFINED__
typedef interface ITitleWave ITitleWave;
#endif 	/* __ITitleWave_FWD_DEFINED__ */


/* header files for imported files */
#include "unknwn.h"

void __RPC_FAR * __RPC_USER MIDL_user_allocate(size_t);
void __RPC_USER MIDL_user_free( void __RPC_FAR * ); 

#ifndef __ITitleWave_INTERFACE_DEFINED__
#define __ITitleWave_INTERFACE_DEFINED__

/****************************************
 * Generated header for interface: ITitleWave
 * at Fri Feb 06 14:08:05 1998
 * using MIDL 3.01.75
 ****************************************/
/* [uuid][object][local] */ 



EXTERN_C const IID IID_ITitleWave;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    interface DECLSPEC_UUID("7abd2320-a20b-11d0-9816-00aa00682823")
    ITitleWave : public IUnknown
    {
    public:
        virtual DWORD STDMETHODCALLTYPE MakeProgramWindow( 
            /* [in] */ DWORD hInstance,
            /* [in] */ DWORD size_flag,
            /* [out] */ DWORD __RPC_FAR *program_window) = 0;
        
        virtual DWORD STDMETHODCALLTYPE StartGettingMessages( 
            /* [in] */ BYTE flag) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE OpenWorkspace( 
            /* [in] */ BYTE __RPC_FAR *name) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SaveStill( 
            /* [in] */ BYTE __RPC_FAR *name) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SaveRoll( 
            /* [in] */ BYTE __RPC_FAR *name) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SaveCrawl( 
            /* [in] */ BYTE __RPC_FAR *name) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE ReplaceString( 
            /* [in] */ BYTE __RPC_FAR *tag,
            /* [in] */ BYTE __RPC_FAR *replace_string) = 0;
        
        virtual DWORD STDMETHODCALLTYPE ExitProgram( 
            /* [in] */ BYTE flag) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct ITitleWaveVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            ITitleWave __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            ITitleWave __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            ITitleWave __RPC_FAR * This);
        
        DWORD ( STDMETHODCALLTYPE __RPC_FAR *MakeProgramWindow )( 
            ITitleWave __RPC_FAR * This,
            /* [in] */ DWORD hInstance,
            /* [in] */ DWORD size_flag,
            /* [out] */ DWORD __RPC_FAR *program_window);
        
        DWORD ( STDMETHODCALLTYPE __RPC_FAR *StartGettingMessages )( 
            ITitleWave __RPC_FAR * This,
            /* [in] */ BYTE flag);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *OpenWorkspace )( 
            ITitleWave __RPC_FAR * This,
            /* [in] */ BYTE __RPC_FAR *name);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SaveStill )( 
            ITitleWave __RPC_FAR * This,
            /* [in] */ BYTE __RPC_FAR *name);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SaveRoll )( 
            ITitleWave __RPC_FAR * This,
            /* [in] */ BYTE __RPC_FAR *name);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SaveCrawl )( 
            ITitleWave __RPC_FAR * This,
            /* [in] */ BYTE __RPC_FAR *name);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *ReplaceString )( 
            ITitleWave __RPC_FAR * This,
            /* [in] */ BYTE __RPC_FAR *tag,
            /* [in] */ BYTE __RPC_FAR *replace_string);
        
        DWORD ( STDMETHODCALLTYPE __RPC_FAR *ExitProgram )( 
            ITitleWave __RPC_FAR * This,
            /* [in] */ BYTE flag);
        
        END_INTERFACE
    } ITitleWaveVtbl;

    interface ITitleWave
    {
        CONST_VTBL struct ITitleWaveVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ITitleWave_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define ITitleWave_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define ITitleWave_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define ITitleWave_MakeProgramWindow(This,hInstance,size_flag,program_window)	\
    (This)->lpVtbl -> MakeProgramWindow(This,hInstance,size_flag,program_window)

#define ITitleWave_StartGettingMessages(This,flag)	\
    (This)->lpVtbl -> StartGettingMessages(This,flag)

#define ITitleWave_OpenWorkspace(This,name)	\
    (This)->lpVtbl -> OpenWorkspace(This,name)

#define ITitleWave_SaveStill(This,name)	\
    (This)->lpVtbl -> SaveStill(This,name)

#define ITitleWave_SaveRoll(This,name)	\
    (This)->lpVtbl -> SaveRoll(This,name)

#define ITitleWave_SaveCrawl(This,name)	\
    (This)->lpVtbl -> SaveCrawl(This,name)

#define ITitleWave_ReplaceString(This,tag,replace_string)	\
    (This)->lpVtbl -> ReplaceString(This,tag,replace_string)

#define ITitleWave_ExitProgram(This,flag)	\
    (This)->lpVtbl -> ExitProgram(This,flag)

#endif /* COBJMACROS */


#endif 	/* C style interface */



DWORD STDMETHODCALLTYPE ITitleWave_MakeProgramWindow_Proxy( 
    ITitleWave __RPC_FAR * This,
    /* [in] */ DWORD hInstance,
    /* [in] */ DWORD size_flag,
    /* [out] */ DWORD __RPC_FAR *program_window);


void __RPC_STUB ITitleWave_MakeProgramWindow_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


DWORD STDMETHODCALLTYPE ITitleWave_StartGettingMessages_Proxy( 
    ITitleWave __RPC_FAR * This,
    /* [in] */ BYTE flag);


void __RPC_STUB ITitleWave_StartGettingMessages_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE ITitleWave_OpenWorkspace_Proxy( 
    ITitleWave __RPC_FAR * This,
    /* [in] */ BYTE __RPC_FAR *name);


void __RPC_STUB ITitleWave_OpenWorkspace_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE ITitleWave_SaveStill_Proxy( 
    ITitleWave __RPC_FAR * This,
    /* [in] */ BYTE __RPC_FAR *name);


void __RPC_STUB ITitleWave_SaveStill_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE ITitleWave_SaveRoll_Proxy( 
    ITitleWave __RPC_FAR * This,
    /* [in] */ BYTE __RPC_FAR *name);


void __RPC_STUB ITitleWave_SaveRoll_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE ITitleWave_SaveCrawl_Proxy( 
    ITitleWave __RPC_FAR * This,
    /* [in] */ BYTE __RPC_FAR *name);


void __RPC_STUB ITitleWave_SaveCrawl_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE ITitleWave_ReplaceString_Proxy( 
    ITitleWave __RPC_FAR * This,
    /* [in] */ BYTE __RPC_FAR *tag,
    /* [in] */ BYTE __RPC_FAR *replace_string);


void __RPC_STUB ITitleWave_ReplaceString_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


DWORD STDMETHODCALLTYPE ITitleWave_ExitProgram_Proxy( 
    ITitleWave __RPC_FAR * This,
    /* [in] */ BYTE flag);


void __RPC_STUB ITitleWave_ExitProgram_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __ITitleWave_INTERFACE_DEFINED__ */


/* Additional Prototypes for ALL interfaces */

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif
