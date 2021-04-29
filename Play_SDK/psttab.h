/* this ALWAYS GENERATED file contains the definitions for the interfaces */


/* File created by MIDL compiler version 3.01.75 */
/* at Tue Nov 23 05:02:14 1999
 */
/* Compiler settings for psttab.idl:
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

#ifndef __psttab_h__
#define __psttab_h__

#ifdef __cplusplus
extern "C"{
#endif 

/* Forward Declarations */ 

#ifndef __IPlayStringTable_FWD_DEFINED__
#define __IPlayStringTable_FWD_DEFINED__
typedef interface IPlayStringTable IPlayStringTable;
#endif 	/* __IPlayStringTable_FWD_DEFINED__ */


/* header files for imported files */
#include "unknwn.h"

void __RPC_FAR * __RPC_USER MIDL_user_allocate(size_t);
void __RPC_USER MIDL_user_free( void __RPC_FAR * ); 

/****************************************
 * Generated header for interface: __MIDL_itf_psttab_0000
 * at Tue Nov 23 05:02:14 1999
 * using MIDL 3.01.75
 ****************************************/
/* [local] */ 





extern RPC_IF_HANDLE __MIDL_itf_psttab_0000_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_psttab_0000_v0_0_s_ifspec;

#ifndef __IPlayStringTable_INTERFACE_DEFINED__
#define __IPlayStringTable_INTERFACE_DEFINED__

/****************************************
 * Generated header for interface: IPlayStringTable
 * at Tue Nov 23 05:02:14 1999
 * using MIDL 3.01.75
 ****************************************/
/* [uuid][object][local] */ 



EXTERN_C const IID IID_IPlayStringTable;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    interface DECLSPEC_UUID("4c3eb2c0-ecaa-11cf-aa37-002018313831")
    IPlayStringTable : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE GetString( 
            DWORD stringNum,
            /* [string][out] */ LPSTR string,
            DWORD size) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetString( 
            DWORD stringNum,
            /* [string][in] */ LPSTR string) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE RemoveString( 
            DWORD stringNum) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Load( 
            /* [string][in] */ LPSTR filename) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE LoadStm( 
            /* [in] */ IStream __RPC_FAR *pStm) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Save( 
            /* [string][in] */ LPSTR filename) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SaveStm( 
            /* [in] */ IStream __RPC_FAR *pStm) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IPlayStringTableVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            IPlayStringTable __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            IPlayStringTable __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            IPlayStringTable __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetString )( 
            IPlayStringTable __RPC_FAR * This,
            DWORD stringNum,
            /* [string][out] */ LPSTR string,
            DWORD size);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetString )( 
            IPlayStringTable __RPC_FAR * This,
            DWORD stringNum,
            /* [string][in] */ LPSTR string);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *RemoveString )( 
            IPlayStringTable __RPC_FAR * This,
            DWORD stringNum);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Load )( 
            IPlayStringTable __RPC_FAR * This,
            /* [string][in] */ LPSTR filename);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *LoadStm )( 
            IPlayStringTable __RPC_FAR * This,
            /* [in] */ IStream __RPC_FAR *pStm);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Save )( 
            IPlayStringTable __RPC_FAR * This,
            /* [string][in] */ LPSTR filename);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SaveStm )( 
            IPlayStringTable __RPC_FAR * This,
            /* [in] */ IStream __RPC_FAR *pStm);
        
        END_INTERFACE
    } IPlayStringTableVtbl;

    interface IPlayStringTable
    {
        CONST_VTBL struct IPlayStringTableVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IPlayStringTable_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IPlayStringTable_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IPlayStringTable_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IPlayStringTable_GetString(This,stringNum,string,size)	\
    (This)->lpVtbl -> GetString(This,stringNum,string,size)

#define IPlayStringTable_SetString(This,stringNum,string)	\
    (This)->lpVtbl -> SetString(This,stringNum,string)

#define IPlayStringTable_RemoveString(This,stringNum)	\
    (This)->lpVtbl -> RemoveString(This,stringNum)

#define IPlayStringTable_Load(This,filename)	\
    (This)->lpVtbl -> Load(This,filename)

#define IPlayStringTable_LoadStm(This,pStm)	\
    (This)->lpVtbl -> LoadStm(This,pStm)

#define IPlayStringTable_Save(This,filename)	\
    (This)->lpVtbl -> Save(This,filename)

#define IPlayStringTable_SaveStm(This,pStm)	\
    (This)->lpVtbl -> SaveStm(This,pStm)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE IPlayStringTable_GetString_Proxy( 
    IPlayStringTable __RPC_FAR * This,
    DWORD stringNum,
    /* [string][out] */ LPSTR string,
    DWORD size);


void __RPC_STUB IPlayStringTable_GetString_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IPlayStringTable_SetString_Proxy( 
    IPlayStringTable __RPC_FAR * This,
    DWORD stringNum,
    /* [string][in] */ LPSTR string);


void __RPC_STUB IPlayStringTable_SetString_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IPlayStringTable_RemoveString_Proxy( 
    IPlayStringTable __RPC_FAR * This,
    DWORD stringNum);


void __RPC_STUB IPlayStringTable_RemoveString_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IPlayStringTable_Load_Proxy( 
    IPlayStringTable __RPC_FAR * This,
    /* [string][in] */ LPSTR filename);


void __RPC_STUB IPlayStringTable_Load_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IPlayStringTable_LoadStm_Proxy( 
    IPlayStringTable __RPC_FAR * This,
    /* [in] */ IStream __RPC_FAR *pStm);


void __RPC_STUB IPlayStringTable_LoadStm_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IPlayStringTable_Save_Proxy( 
    IPlayStringTable __RPC_FAR * This,
    /* [string][in] */ LPSTR filename);


void __RPC_STUB IPlayStringTable_Save_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IPlayStringTable_SaveStm_Proxy( 
    IPlayStringTable __RPC_FAR * This,
    /* [in] */ IStream __RPC_FAR *pStm);


void __RPC_STUB IPlayStringTable_SaveStm_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IPlayStringTable_INTERFACE_DEFINED__ */


/* Additional Prototypes for ALL interfaces */

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif
