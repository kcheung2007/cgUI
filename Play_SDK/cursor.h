/* this ALWAYS GENERATED file contains the definitions for the interfaces */


/* File created by MIDL compiler version 3.01.75 */
/* at Tue Nov 23 05:02:16 1999
 */
/* Compiler settings for cursor.idl:
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

#ifndef __cursor_h__
#define __cursor_h__

#ifdef __cplusplus
extern "C"{
#endif 

/* Forward Declarations */ 

#ifndef __IPlayCursor_FWD_DEFINED__
#define __IPlayCursor_FWD_DEFINED__
typedef interface IPlayCursor IPlayCursor;
#endif 	/* __IPlayCursor_FWD_DEFINED__ */


/* header files for imported files */
#include "oleidl.h"

void __RPC_FAR * __RPC_USER MIDL_user_allocate(size_t);
void __RPC_USER MIDL_user_free( void __RPC_FAR * ); 

/****************************************
 * Generated header for interface: __MIDL_itf_cursor_0000
 * at Tue Nov 23 05:02:16 1999
 * using MIDL 3.01.75
 ****************************************/
/* [local] */ 


typedef 
enum _EPlayCursor
    {	Pointer	= 0,
	Wait	= Pointer + 1,
	SizeAll	= Wait + 1,
	SizeEW	= SizeAll + 1,
	SizeNS	= SizeEW + 1,
	DragCopy	= SizeNS + 1,
	DragMove	= DragCopy + 1,
	DragShortcut	= DragMove + 1,
	DragNo	= DragShortcut + 1,
	Text	= DragNo + 1,
	ClipRoll	= Text + 1,
	HyperLink	= ClipRoll + 1
    }	EPlayCursor;



extern RPC_IF_HANDLE __MIDL_itf_cursor_0000_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_cursor_0000_v0_0_s_ifspec;

#ifndef __IPlayCursor_INTERFACE_DEFINED__
#define __IPlayCursor_INTERFACE_DEFINED__

/****************************************
 * Generated header for interface: IPlayCursor
 * at Tue Nov 23 05:02:16 1999
 * using MIDL 3.01.75
 ****************************************/
/* [unique][uuid][object][local] */ 



EXTERN_C const IID IID_IPlayCursor;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    interface DECLSPEC_UUID("8335e45c-ab3b-11ce-8468-0000b468276b")
    IPlayCursor : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE SetCursor( 
            /* [in] */ EPlayCursor cursor,
            /* [out] */ EPlayCursor __RPC_FAR *pPrevCorsor) = 0;
        
        virtual HCURSOR STDMETHODCALLTYPE GetHCursor( 
            /* [in] */ EPlayCursor cursor) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IPlayCursorVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            IPlayCursor __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            IPlayCursor __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            IPlayCursor __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetCursor )( 
            IPlayCursor __RPC_FAR * This,
            /* [in] */ EPlayCursor cursor,
            /* [out] */ EPlayCursor __RPC_FAR *pPrevCorsor);
        
        HCURSOR ( STDMETHODCALLTYPE __RPC_FAR *GetHCursor )( 
            IPlayCursor __RPC_FAR * This,
            /* [in] */ EPlayCursor cursor);
        
        END_INTERFACE
    } IPlayCursorVtbl;

    interface IPlayCursor
    {
        CONST_VTBL struct IPlayCursorVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IPlayCursor_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IPlayCursor_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IPlayCursor_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IPlayCursor_SetCursor(This,cursor,pPrevCorsor)	\
    (This)->lpVtbl -> SetCursor(This,cursor,pPrevCorsor)

#define IPlayCursor_GetHCursor(This,cursor)	\
    (This)->lpVtbl -> GetHCursor(This,cursor)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE IPlayCursor_SetCursor_Proxy( 
    IPlayCursor __RPC_FAR * This,
    /* [in] */ EPlayCursor cursor,
    /* [out] */ EPlayCursor __RPC_FAR *pPrevCorsor);


void __RPC_STUB IPlayCursor_SetCursor_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HCURSOR STDMETHODCALLTYPE IPlayCursor_GetHCursor_Proxy( 
    IPlayCursor __RPC_FAR * This,
    /* [in] */ EPlayCursor cursor);


void __RPC_STUB IPlayCursor_GetHCursor_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IPlayCursor_INTERFACE_DEFINED__ */


/* Additional Prototypes for ALL interfaces */

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif
