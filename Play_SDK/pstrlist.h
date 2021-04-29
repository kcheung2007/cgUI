/* this ALWAYS GENERATED file contains the definitions for the interfaces */


/* File created by MIDL compiler version 3.01.75 */
/* at Tue Nov 23 05:02:14 1999
 */
/* Compiler settings for pstrlist.idl:
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

#ifndef __pstrlist_h__
#define __pstrlist_h__

#ifdef __cplusplus
extern "C"{
#endif 

/* Forward Declarations */ 

#ifndef __IPlayStringList_FWD_DEFINED__
#define __IPlayStringList_FWD_DEFINED__
typedef interface IPlayStringList IPlayStringList;
#endif 	/* __IPlayStringList_FWD_DEFINED__ */


/* header files for imported files */
#include "unknwn.h"

void __RPC_FAR * __RPC_USER MIDL_user_allocate(size_t);
void __RPC_USER MIDL_user_free( void __RPC_FAR * ); 

#ifndef __IPlayStringList_INTERFACE_DEFINED__
#define __IPlayStringList_INTERFACE_DEFINED__

/****************************************
 * Generated header for interface: IPlayStringList
 * at Tue Nov 23 05:02:14 1999
 * using MIDL 3.01.75
 ****************************************/
/* [uuid][object][local] */ 



EXTERN_C const IID IID_IPlayStringList;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    interface DECLSPEC_UUID("8335e432-ab3b-11ce-8468-0000b468276b")
    IPlayStringList : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE AddString( 
            /* [string] */ LPSTR pszSelection,
            int nPos) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE CopyString( 
            int nPos,
            /* [string] */ LPSTR pszCopyDest,
            int nMaxChars) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE DelString( 
            int nPos) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetMutuallyExclusive( 
            int nDefault) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetNumber( 
            DWORD dwMask,
            int __RPC_FAR *pResult) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetStringIndex( 
            DWORD dwMask,
            int __RPC_FAR *pNumberArray,
            int __RPC_FAR *pReturned) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IPlayStringListVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            IPlayStringList __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            IPlayStringList __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            IPlayStringList __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *AddString )( 
            IPlayStringList __RPC_FAR * This,
            /* [string] */ LPSTR pszSelection,
            int nPos);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *CopyString )( 
            IPlayStringList __RPC_FAR * This,
            int nPos,
            /* [string] */ LPSTR pszCopyDest,
            int nMaxChars);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *DelString )( 
            IPlayStringList __RPC_FAR * This,
            int nPos);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetMutuallyExclusive )( 
            IPlayStringList __RPC_FAR * This,
            int nDefault);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetNumber )( 
            IPlayStringList __RPC_FAR * This,
            DWORD dwMask,
            int __RPC_FAR *pResult);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetStringIndex )( 
            IPlayStringList __RPC_FAR * This,
            DWORD dwMask,
            int __RPC_FAR *pNumberArray,
            int __RPC_FAR *pReturned);
        
        END_INTERFACE
    } IPlayStringListVtbl;

    interface IPlayStringList
    {
        CONST_VTBL struct IPlayStringListVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IPlayStringList_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IPlayStringList_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IPlayStringList_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IPlayStringList_AddString(This,pszSelection,nPos)	\
    (This)->lpVtbl -> AddString(This,pszSelection,nPos)

#define IPlayStringList_CopyString(This,nPos,pszCopyDest,nMaxChars)	\
    (This)->lpVtbl -> CopyString(This,nPos,pszCopyDest,nMaxChars)

#define IPlayStringList_DelString(This,nPos)	\
    (This)->lpVtbl -> DelString(This,nPos)

#define IPlayStringList_SetMutuallyExclusive(This,nDefault)	\
    (This)->lpVtbl -> SetMutuallyExclusive(This,nDefault)

#define IPlayStringList_GetNumber(This,dwMask,pResult)	\
    (This)->lpVtbl -> GetNumber(This,dwMask,pResult)

#define IPlayStringList_GetStringIndex(This,dwMask,pNumberArray,pReturned)	\
    (This)->lpVtbl -> GetStringIndex(This,dwMask,pNumberArray,pReturned)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE IPlayStringList_AddString_Proxy( 
    IPlayStringList __RPC_FAR * This,
    /* [string] */ LPSTR pszSelection,
    int nPos);


void __RPC_STUB IPlayStringList_AddString_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IPlayStringList_CopyString_Proxy( 
    IPlayStringList __RPC_FAR * This,
    int nPos,
    /* [string] */ LPSTR pszCopyDest,
    int nMaxChars);


void __RPC_STUB IPlayStringList_CopyString_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IPlayStringList_DelString_Proxy( 
    IPlayStringList __RPC_FAR * This,
    int nPos);


void __RPC_STUB IPlayStringList_DelString_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IPlayStringList_SetMutuallyExclusive_Proxy( 
    IPlayStringList __RPC_FAR * This,
    int nDefault);


void __RPC_STUB IPlayStringList_SetMutuallyExclusive_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IPlayStringList_GetNumber_Proxy( 
    IPlayStringList __RPC_FAR * This,
    DWORD dwMask,
    int __RPC_FAR *pResult);


void __RPC_STUB IPlayStringList_GetNumber_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IPlayStringList_GetStringIndex_Proxy( 
    IPlayStringList __RPC_FAR * This,
    DWORD dwMask,
    int __RPC_FAR *pNumberArray,
    int __RPC_FAR *pReturned);


void __RPC_STUB IPlayStringList_GetStringIndex_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IPlayStringList_INTERFACE_DEFINED__ */


/* Additional Prototypes for ALL interfaces */

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif
