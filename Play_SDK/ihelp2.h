/* this ALWAYS GENERATED file contains the definitions for the interfaces */


/* File created by MIDL compiler version 3.01.75 */
/* at Tue Nov 23 05:02:15 1999
 */
/* Compiler settings for ihelp2.idl:
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

#ifndef __ihelp2_h__
#define __ihelp2_h__

#ifdef __cplusplus
extern "C"{
#endif 

/* Forward Declarations */ 

#ifndef __IHelpServer1_FWD_DEFINED__
#define __IHelpServer1_FWD_DEFINED__
typedef interface IHelpServer1 IHelpServer1;
#endif 	/* __IHelpServer1_FWD_DEFINED__ */


#ifndef __IHelpServer2_FWD_DEFINED__
#define __IHelpServer2_FWD_DEFINED__
typedef interface IHelpServer2 IHelpServer2;
#endif 	/* __IHelpServer2_FWD_DEFINED__ */


#ifndef __IHelpAdvise_FWD_DEFINED__
#define __IHelpAdvise_FWD_DEFINED__
typedef interface IHelpAdvise IHelpAdvise;
#endif 	/* __IHelpAdvise_FWD_DEFINED__ */


/* header files for imported files */
#include "unknwn.h"
#include "objidl.h"

void __RPC_FAR * __RPC_USER MIDL_user_allocate(size_t);
void __RPC_USER MIDL_user_free( void __RPC_FAR * ); 

/****************************************
 * Generated header for interface: __MIDL_itf_ihelp2_0000
 * at Tue Nov 23 05:02:15 1999
 * using MIDL 3.01.75
 ****************************************/
/* [local] */ 







extern RPC_IF_HANDLE __MIDL_itf_ihelp2_0000_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_ihelp2_0000_v0_0_s_ifspec;

#ifndef __IHelpServer1_INTERFACE_DEFINED__
#define __IHelpServer1_INTERFACE_DEFINED__

/****************************************
 * Generated header for interface: IHelpServer1
 * at Tue Nov 23 05:02:15 1999
 * using MIDL 3.01.75
 ****************************************/
/* [unique][uuid][object][local] */ 


typedef 
enum tagEApplicationID
    {	AppIDPanamation	= 0,
	AppIDPFX	= AppIDPanamation + 1,
	AppIDSwitcher	= AppIDPFX + 1,
	AppIDEditor	= AppIDSwitcher + 1,
	AppIDMixer	= AppIDEditor + 1,
	AppIDTitleWave	= AppIDMixer + 1,
	AppIDTiaInternal	= AppIDTitleWave + 1,
	AppIDSnappy	= AppIDTiaInternal + 1,
	AppIDTrinityInstall	= AppIDSnappy + 1,
	AppIDUndefined	= AppIDTrinityInstall + 1
    }	EApplicationID;

typedef 
enum tagEInvocationType
    {	ISTKeyboardGeneral	= 0,
	ISTBinHandler	= ISTKeyboardGeneral + 1,
	ISTMenuGeneral	= ISTBinHandler + 1,
	ISTMenuContextSensitive	= ISTMenuGeneral + 1,
	ISTControlContextSensitive	= ISTMenuContextSensitive + 1,
	ISTErrorApplication	= ISTControlContextSensitive + 1,
	ISTErrorHelpInternal	= ISTErrorApplication + 1,
	ISTEventTrigger	= ISTErrorHelpInternal + 1,
	ISTUndefinedEvent	= ISTEventTrigger + 1
    }	EInvocationType;


EXTERN_C const IID IID_IHelpServer1;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    interface DECLSPEC_UUID("8335e603-ab3b-11ce-8468-0000b468276b")
    IHelpServer1 : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE InvokeHelp( 
            /* [in] */ EApplicationID appidApplicationID,
            /* [in] */ EInvocationType istInvocationType,
            /* [in] */ LPSTR lpstrMessage,
            /* [in] */ LPVOID pvExtraParms) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetAdvise( 
            /* [in] */ IHelpAdvise __RPC_FAR *pIHelpAdvise) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IHelpServer1Vtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            IHelpServer1 __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            IHelpServer1 __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            IHelpServer1 __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *InvokeHelp )( 
            IHelpServer1 __RPC_FAR * This,
            /* [in] */ EApplicationID appidApplicationID,
            /* [in] */ EInvocationType istInvocationType,
            /* [in] */ LPSTR lpstrMessage,
            /* [in] */ LPVOID pvExtraParms);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetAdvise )( 
            IHelpServer1 __RPC_FAR * This,
            /* [in] */ IHelpAdvise __RPC_FAR *pIHelpAdvise);
        
        END_INTERFACE
    } IHelpServer1Vtbl;

    interface IHelpServer1
    {
        CONST_VTBL struct IHelpServer1Vtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IHelpServer1_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IHelpServer1_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IHelpServer1_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IHelpServer1_InvokeHelp(This,appidApplicationID,istInvocationType,lpstrMessage,pvExtraParms)	\
    (This)->lpVtbl -> InvokeHelp(This,appidApplicationID,istInvocationType,lpstrMessage,pvExtraParms)

#define IHelpServer1_SetAdvise(This,pIHelpAdvise)	\
    (This)->lpVtbl -> SetAdvise(This,pIHelpAdvise)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE IHelpServer1_InvokeHelp_Proxy( 
    IHelpServer1 __RPC_FAR * This,
    /* [in] */ EApplicationID appidApplicationID,
    /* [in] */ EInvocationType istInvocationType,
    /* [in] */ LPSTR lpstrMessage,
    /* [in] */ LPVOID pvExtraParms);


void __RPC_STUB IHelpServer1_InvokeHelp_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IHelpServer1_SetAdvise_Proxy( 
    IHelpServer1 __RPC_FAR * This,
    /* [in] */ IHelpAdvise __RPC_FAR *pIHelpAdvise);


void __RPC_STUB IHelpServer1_SetAdvise_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IHelpServer1_INTERFACE_DEFINED__ */


/****************************************
 * Generated header for interface: __MIDL_itf_ihelp2_0055
 * at Tue Nov 23 05:02:15 1999
 * using MIDL 3.01.75
 ****************************************/
/* [local] */ 


typedef IHelpServer1 __RPC_FAR *PIHelpServer1;



extern RPC_IF_HANDLE __MIDL_itf_ihelp2_0055_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_ihelp2_0055_v0_0_s_ifspec;

#ifndef __IHelpServer2_INTERFACE_DEFINED__
#define __IHelpServer2_INTERFACE_DEFINED__

/****************************************
 * Generated header for interface: IHelpServer2
 * at Tue Nov 23 05:02:15 1999
 * using MIDL 3.01.75
 ****************************************/
/* [unique][uuid][object][local] */ 



EXTERN_C const IID IID_IHelpServer2;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    interface DECLSPEC_UUID("8335e602-ab3b-11ce-8468-0000b468276b")
    IHelpServer2 : public IHelpServer1
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE SetWindow( 
            /* [in] */ HWND hwndParent) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IHelpServer2Vtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            IHelpServer2 __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            IHelpServer2 __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            IHelpServer2 __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *InvokeHelp )( 
            IHelpServer2 __RPC_FAR * This,
            /* [in] */ EApplicationID appidApplicationID,
            /* [in] */ EInvocationType istInvocationType,
            /* [in] */ LPSTR lpstrMessage,
            /* [in] */ LPVOID pvExtraParms);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetAdvise )( 
            IHelpServer2 __RPC_FAR * This,
            /* [in] */ IHelpAdvise __RPC_FAR *pIHelpAdvise);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetWindow )( 
            IHelpServer2 __RPC_FAR * This,
            /* [in] */ HWND hwndParent);
        
        END_INTERFACE
    } IHelpServer2Vtbl;

    interface IHelpServer2
    {
        CONST_VTBL struct IHelpServer2Vtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IHelpServer2_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IHelpServer2_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IHelpServer2_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IHelpServer2_InvokeHelp(This,appidApplicationID,istInvocationType,lpstrMessage,pvExtraParms)	\
    (This)->lpVtbl -> InvokeHelp(This,appidApplicationID,istInvocationType,lpstrMessage,pvExtraParms)

#define IHelpServer2_SetAdvise(This,pIHelpAdvise)	\
    (This)->lpVtbl -> SetAdvise(This,pIHelpAdvise)


#define IHelpServer2_SetWindow(This,hwndParent)	\
    (This)->lpVtbl -> SetWindow(This,hwndParent)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE IHelpServer2_SetWindow_Proxy( 
    IHelpServer2 __RPC_FAR * This,
    /* [in] */ HWND hwndParent);


void __RPC_STUB IHelpServer2_SetWindow_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IHelpServer2_INTERFACE_DEFINED__ */


/****************************************
 * Generated header for interface: __MIDL_itf_ihelp2_0056
 * at Tue Nov 23 05:02:15 1999
 * using MIDL 3.01.75
 ****************************************/
/* [local] */ 


typedef IHelpServer2 __RPC_FAR *PIHelpServer2;



extern RPC_IF_HANDLE __MIDL_itf_ihelp2_0056_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_ihelp2_0056_v0_0_s_ifspec;

#ifndef __IHelpAdvise_INTERFACE_DEFINED__
#define __IHelpAdvise_INTERFACE_DEFINED__

/****************************************
 * Generated header for interface: IHelpAdvise
 * at Tue Nov 23 05:02:15 1999
 * using MIDL 3.01.75
 ****************************************/
/* [unique][uuid][object][local] */ 



EXTERN_C const IID IID_IHelpAdvise;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    interface DECLSPEC_UUID("8335e601-ab3b-11ce-8468-0000b468276b")
    IHelpAdvise : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE OnWindowClose( void) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IHelpAdviseVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            IHelpAdvise __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            IHelpAdvise __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            IHelpAdvise __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *OnWindowClose )( 
            IHelpAdvise __RPC_FAR * This);
        
        END_INTERFACE
    } IHelpAdviseVtbl;

    interface IHelpAdvise
    {
        CONST_VTBL struct IHelpAdviseVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IHelpAdvise_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IHelpAdvise_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IHelpAdvise_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IHelpAdvise_OnWindowClose(This)	\
    (This)->lpVtbl -> OnWindowClose(This)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE IHelpAdvise_OnWindowClose_Proxy( 
    IHelpAdvise __RPC_FAR * This);


void __RPC_STUB IHelpAdvise_OnWindowClose_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IHelpAdvise_INTERFACE_DEFINED__ */


/****************************************
 * Generated header for interface: __MIDL_itf_ihelp2_0057
 * at Tue Nov 23 05:02:15 1999
 * using MIDL 3.01.75
 ****************************************/
/* [local] */ 


typedef IHelpAdvise __RPC_FAR *PIHelpAdvise;



extern RPC_IF_HANDLE __MIDL_itf_ihelp2_0057_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_ihelp2_0057_v0_0_s_ifspec;

/* Additional Prototypes for ALL interfaces */

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif
