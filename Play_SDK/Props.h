/* this ALWAYS GENERATED file contains the definitions for the interfaces */


/* File created by MIDL compiler version 3.01.75 */
/* at Tue Nov 23 05:02:14 1999
 */
/* Compiler settings for Props.idl:
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

#ifndef __Props_h__
#define __Props_h__

#ifdef __cplusplus
extern "C"{
#endif 

/* Forward Declarations */ 

#ifndef __IPlayPropertiesOwnerAdviseSink_FWD_DEFINED__
#define __IPlayPropertiesOwnerAdviseSink_FWD_DEFINED__
typedef interface IPlayPropertiesOwnerAdviseSink IPlayPropertiesOwnerAdviseSink;
#endif 	/* __IPlayPropertiesOwnerAdviseSink_FWD_DEFINED__ */


#ifndef __IPlayPropertiesAdviseSink_FWD_DEFINED__
#define __IPlayPropertiesAdviseSink_FWD_DEFINED__
typedef interface IPlayPropertiesAdviseSink IPlayPropertiesAdviseSink;
#endif 	/* __IPlayPropertiesAdviseSink_FWD_DEFINED__ */


#ifndef __IPlayProperties_FWD_DEFINED__
#define __IPlayProperties_FWD_DEFINED__
typedef interface IPlayProperties IPlayProperties;
#endif 	/* __IPlayProperties_FWD_DEFINED__ */


/* header files for imported files */
#include "unknwn.h"

void __RPC_FAR * __RPC_USER MIDL_user_allocate(size_t);
void __RPC_USER MIDL_user_free( void __RPC_FAR * ); 

/****************************************
 * Generated header for interface: __MIDL_itf_Props_0000
 * at Tue Nov 23 05:02:14 1999
 * using MIDL 3.01.75
 ****************************************/
/* [local] */ 






interface IPlayPanel;
interface IPlayControl;
interface IPlayStringList;


extern RPC_IF_HANDLE __MIDL_itf_Props_0000_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_Props_0000_v0_0_s_ifspec;

#ifndef __IPlayPropertiesOwnerAdviseSink_INTERFACE_DEFINED__
#define __IPlayPropertiesOwnerAdviseSink_INTERFACE_DEFINED__

/****************************************
 * Generated header for interface: IPlayPropertiesOwnerAdviseSink
 * at Tue Nov 23 05:02:14 1999
 * using MIDL 3.01.75
 ****************************************/
/* [uuid][object][local] */ 



EXTERN_C const IID IID_IPlayPropertiesOwnerAdviseSink;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    interface DECLSPEC_UUID("8335e62e-ab3b-11ce-8468-0000b468276b")
    IPlayPropertiesOwnerAdviseSink : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE OnOwnedPropertyValueChange( 
            IPlayProperties __RPC_FAR *pPropSet,
            LPSTR pszPropName) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IPlayPropertiesOwnerAdviseSinkVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            IPlayPropertiesOwnerAdviseSink __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            IPlayPropertiesOwnerAdviseSink __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            IPlayPropertiesOwnerAdviseSink __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *OnOwnedPropertyValueChange )( 
            IPlayPropertiesOwnerAdviseSink __RPC_FAR * This,
            IPlayProperties __RPC_FAR *pPropSet,
            LPSTR pszPropName);
        
        END_INTERFACE
    } IPlayPropertiesOwnerAdviseSinkVtbl;

    interface IPlayPropertiesOwnerAdviseSink
    {
        CONST_VTBL struct IPlayPropertiesOwnerAdviseSinkVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IPlayPropertiesOwnerAdviseSink_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IPlayPropertiesOwnerAdviseSink_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IPlayPropertiesOwnerAdviseSink_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IPlayPropertiesOwnerAdviseSink_OnOwnedPropertyValueChange(This,pPropSet,pszPropName)	\
    (This)->lpVtbl -> OnOwnedPropertyValueChange(This,pPropSet,pszPropName)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE IPlayPropertiesOwnerAdviseSink_OnOwnedPropertyValueChange_Proxy( 
    IPlayPropertiesOwnerAdviseSink __RPC_FAR * This,
    IPlayProperties __RPC_FAR *pPropSet,
    LPSTR pszPropName);


void __RPC_STUB IPlayPropertiesOwnerAdviseSink_OnOwnedPropertyValueChange_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IPlayPropertiesOwnerAdviseSink_INTERFACE_DEFINED__ */


#ifndef __IPlayPropertiesAdviseSink_INTERFACE_DEFINED__
#define __IPlayPropertiesAdviseSink_INTERFACE_DEFINED__

/****************************************
 * Generated header for interface: IPlayPropertiesAdviseSink
 * at Tue Nov 23 05:02:14 1999
 * using MIDL 3.01.75
 ****************************************/
/* [uuid][object][local] */ 



EXTERN_C const IID IID_IPlayPropertiesAdviseSink;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    interface DECLSPEC_UUID("8335e62d-ab3b-11ce-8468-0000b468276b")
    IPlayPropertiesAdviseSink : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE CanEditFromUI( 
            IPlayProperties __RPC_FAR *pPropSet,
            LPSTR pszPropName) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE ValueIsChanging( 
            IPlayProperties __RPC_FAR *pPropSet,
            LPSTR pszPropName) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE ValueHasChanged( 
            IPlayProperties __RPC_FAR *pPropSet,
            LPSTR pszPropName) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE CanDeleteFromUI( 
            IPlayProperties __RPC_FAR *pPropSet,
            LPSTR pszPropName) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IPlayPropertiesAdviseSinkVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            IPlayPropertiesAdviseSink __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            IPlayPropertiesAdviseSink __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            IPlayPropertiesAdviseSink __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *CanEditFromUI )( 
            IPlayPropertiesAdviseSink __RPC_FAR * This,
            IPlayProperties __RPC_FAR *pPropSet,
            LPSTR pszPropName);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *ValueIsChanging )( 
            IPlayPropertiesAdviseSink __RPC_FAR * This,
            IPlayProperties __RPC_FAR *pPropSet,
            LPSTR pszPropName);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *ValueHasChanged )( 
            IPlayPropertiesAdviseSink __RPC_FAR * This,
            IPlayProperties __RPC_FAR *pPropSet,
            LPSTR pszPropName);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *CanDeleteFromUI )( 
            IPlayPropertiesAdviseSink __RPC_FAR * This,
            IPlayProperties __RPC_FAR *pPropSet,
            LPSTR pszPropName);
        
        END_INTERFACE
    } IPlayPropertiesAdviseSinkVtbl;

    interface IPlayPropertiesAdviseSink
    {
        CONST_VTBL struct IPlayPropertiesAdviseSinkVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IPlayPropertiesAdviseSink_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IPlayPropertiesAdviseSink_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IPlayPropertiesAdviseSink_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IPlayPropertiesAdviseSink_CanEditFromUI(This,pPropSet,pszPropName)	\
    (This)->lpVtbl -> CanEditFromUI(This,pPropSet,pszPropName)

#define IPlayPropertiesAdviseSink_ValueIsChanging(This,pPropSet,pszPropName)	\
    (This)->lpVtbl -> ValueIsChanging(This,pPropSet,pszPropName)

#define IPlayPropertiesAdviseSink_ValueHasChanged(This,pPropSet,pszPropName)	\
    (This)->lpVtbl -> ValueHasChanged(This,pPropSet,pszPropName)

#define IPlayPropertiesAdviseSink_CanDeleteFromUI(This,pPropSet,pszPropName)	\
    (This)->lpVtbl -> CanDeleteFromUI(This,pPropSet,pszPropName)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE IPlayPropertiesAdviseSink_CanEditFromUI_Proxy( 
    IPlayPropertiesAdviseSink __RPC_FAR * This,
    IPlayProperties __RPC_FAR *pPropSet,
    LPSTR pszPropName);


void __RPC_STUB IPlayPropertiesAdviseSink_CanEditFromUI_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IPlayPropertiesAdviseSink_ValueIsChanging_Proxy( 
    IPlayPropertiesAdviseSink __RPC_FAR * This,
    IPlayProperties __RPC_FAR *pPropSet,
    LPSTR pszPropName);


void __RPC_STUB IPlayPropertiesAdviseSink_ValueIsChanging_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IPlayPropertiesAdviseSink_ValueHasChanged_Proxy( 
    IPlayPropertiesAdviseSink __RPC_FAR * This,
    IPlayProperties __RPC_FAR *pPropSet,
    LPSTR pszPropName);


void __RPC_STUB IPlayPropertiesAdviseSink_ValueHasChanged_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IPlayPropertiesAdviseSink_CanDeleteFromUI_Proxy( 
    IPlayPropertiesAdviseSink __RPC_FAR * This,
    IPlayProperties __RPC_FAR *pPropSet,
    LPSTR pszPropName);


void __RPC_STUB IPlayPropertiesAdviseSink_CanDeleteFromUI_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IPlayPropertiesAdviseSink_INTERFACE_DEFINED__ */


#ifndef __IPlayProperties_INTERFACE_DEFINED__
#define __IPlayProperties_INTERFACE_DEFINED__

/****************************************
 * Generated header for interface: IPlayProperties
 * at Tue Nov 23 05:02:14 1999
 * using MIDL 3.01.75
 ****************************************/
/* [uuid][object][local] */ 


typedef 
enum tagEPropValueType
    {	PVTString	= 0,
	PVTLong	= 1,
	PVTGuid	= 2,
	PVTLongWithRange	= 3
    }	EPropValueType;

typedef 
enum tagEPropFlags
    {	PFUserEditable	= 0x1,
	PFUserUnderstands	= 0x2,
	PFSearchKeyword	= 0x4,
	PFUserAdjustKnob	= 0x8,
	PFUserAdjustNumber	= 0x10,
	PFUserAdjustTimeCode	= 0x20
    }	EPropFlags;

typedef 
enum tagEPPValidationMethod
    {	PPVMRail	= 0,
	PPVMModulo	= 1
    }	EPPValidationMethod;


EXTERN_C const IID IID_IPlayProperties;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    interface DECLSPEC_UUID("8335e62a-ab3b-11ce-8468-0000b468276b")
    IPlayProperties : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE GetPropType( 
            /* [string][in] */ LPSTR pszProperty,
            /* [out] */ LONG __RPC_FAR *peType) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetPropFlags( 
            /* [string][in] */ LPSTR pszProperty,
            /* [out] */ LONG __RPC_FAR *peFlags) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetNumProps( 
            /* [out] */ DWORD __RPC_FAR *dwNum) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetPropName( 
            /* [in] */ DWORD index,
            /* [string][out] */ LPSTR pszName,
            /* [in] */ DWORD dwBufSize) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetPropString( 
            /* [string][in] */ LPSTR pszProperty,
            /* [string][in] */ LPSTR pszValue,
            /* [in] */ LONG flags) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetPropString( 
            /* [string][in] */ LPSTR pszProperty,
            /* [string][out] */ LPSTR pszBuffer,
            /* [in] */ ULONG uBufSize) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetPropLong( 
            /* [string][in] */ LPSTR pszProperty,
            /* [in] */ LONG lValue,
            /* [in] */ LONG flags) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetPropLong( 
            /* [string][in] */ LPSTR pszProperty,
            /* [out] */ LONG __RPC_FAR *plVal) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE DeleteProp( 
            /* [string][in] */ LPSTR pszProperty) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE AddEditControls( 
            IPlayPanel __RPC_FAR *pPanel) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Clone( 
            IPlayProperties __RPC_FAR *__RPC_FAR *ppProps) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetSearchKeys( 
            IPlayStringList __RPC_FAR *pPlayCtl) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetPropGuid( 
            /* [string][in] */ LPSTR pszProperty,
            /* [in] */ GUID __RPC_FAR *pguidValue,
            /* [in] */ LONG flags) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetPropGuid( 
            /* [string][in] */ LPSTR pszProperty,
            /* [out] */ GUID __RPC_FAR *pguidVal) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Merge( 
            /* [in] */ IPlayProperties __RPC_FAR *pSrcSet,
            /* [in] */ BOOL bReplace) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE StoreInKey( 
            /* [in] */ HKEY hkeyDest) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE RetrieveFromKey( 
            /* [in] */ HKEY hkeyDest) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Advise( 
            IPlayPropertiesAdviseSink __RPC_FAR *pAdviseSink) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetLongPropRange( 
            LPSTR pszPropName,
            long minValue,
            long maxValue,
            EPPValidationMethod eValid) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE QueryLongPropRange( 
            LPSTR pszPropName,
            long __RPC_FAR *pminValue,
            long __RPC_FAR *pmaxValue,
            EPPValidationMethod __RPC_FAR *peValid) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetOwner( 
            IPlayPropertiesOwnerAdviseSink __RPC_FAR *pAdviseSink) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE UpdateExistingFrom( 
            /* [in] */ IPlayProperties __RPC_FAR *pSrcSet) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IPlayPropertiesVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            IPlayProperties __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            IPlayProperties __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            IPlayProperties __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetPropType )( 
            IPlayProperties __RPC_FAR * This,
            /* [string][in] */ LPSTR pszProperty,
            /* [out] */ LONG __RPC_FAR *peType);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetPropFlags )( 
            IPlayProperties __RPC_FAR * This,
            /* [string][in] */ LPSTR pszProperty,
            /* [out] */ LONG __RPC_FAR *peFlags);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetNumProps )( 
            IPlayProperties __RPC_FAR * This,
            /* [out] */ DWORD __RPC_FAR *dwNum);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetPropName )( 
            IPlayProperties __RPC_FAR * This,
            /* [in] */ DWORD index,
            /* [string][out] */ LPSTR pszName,
            /* [in] */ DWORD dwBufSize);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetPropString )( 
            IPlayProperties __RPC_FAR * This,
            /* [string][in] */ LPSTR pszProperty,
            /* [string][in] */ LPSTR pszValue,
            /* [in] */ LONG flags);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetPropString )( 
            IPlayProperties __RPC_FAR * This,
            /* [string][in] */ LPSTR pszProperty,
            /* [string][out] */ LPSTR pszBuffer,
            /* [in] */ ULONG uBufSize);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetPropLong )( 
            IPlayProperties __RPC_FAR * This,
            /* [string][in] */ LPSTR pszProperty,
            /* [in] */ LONG lValue,
            /* [in] */ LONG flags);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetPropLong )( 
            IPlayProperties __RPC_FAR * This,
            /* [string][in] */ LPSTR pszProperty,
            /* [out] */ LONG __RPC_FAR *plVal);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *DeleteProp )( 
            IPlayProperties __RPC_FAR * This,
            /* [string][in] */ LPSTR pszProperty);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *AddEditControls )( 
            IPlayProperties __RPC_FAR * This,
            IPlayPanel __RPC_FAR *pPanel);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Clone )( 
            IPlayProperties __RPC_FAR * This,
            IPlayProperties __RPC_FAR *__RPC_FAR *ppProps);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetSearchKeys )( 
            IPlayProperties __RPC_FAR * This,
            IPlayStringList __RPC_FAR *pPlayCtl);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetPropGuid )( 
            IPlayProperties __RPC_FAR * This,
            /* [string][in] */ LPSTR pszProperty,
            /* [in] */ GUID __RPC_FAR *pguidValue,
            /* [in] */ LONG flags);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetPropGuid )( 
            IPlayProperties __RPC_FAR * This,
            /* [string][in] */ LPSTR pszProperty,
            /* [out] */ GUID __RPC_FAR *pguidVal);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Merge )( 
            IPlayProperties __RPC_FAR * This,
            /* [in] */ IPlayProperties __RPC_FAR *pSrcSet,
            /* [in] */ BOOL bReplace);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *StoreInKey )( 
            IPlayProperties __RPC_FAR * This,
            /* [in] */ HKEY hkeyDest);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *RetrieveFromKey )( 
            IPlayProperties __RPC_FAR * This,
            /* [in] */ HKEY hkeyDest);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Advise )( 
            IPlayProperties __RPC_FAR * This,
            IPlayPropertiesAdviseSink __RPC_FAR *pAdviseSink);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetLongPropRange )( 
            IPlayProperties __RPC_FAR * This,
            LPSTR pszPropName,
            long minValue,
            long maxValue,
            EPPValidationMethod eValid);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryLongPropRange )( 
            IPlayProperties __RPC_FAR * This,
            LPSTR pszPropName,
            long __RPC_FAR *pminValue,
            long __RPC_FAR *pmaxValue,
            EPPValidationMethod __RPC_FAR *peValid);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetOwner )( 
            IPlayProperties __RPC_FAR * This,
            IPlayPropertiesOwnerAdviseSink __RPC_FAR *pAdviseSink);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *UpdateExistingFrom )( 
            IPlayProperties __RPC_FAR * This,
            /* [in] */ IPlayProperties __RPC_FAR *pSrcSet);
        
        END_INTERFACE
    } IPlayPropertiesVtbl;

    interface IPlayProperties
    {
        CONST_VTBL struct IPlayPropertiesVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IPlayProperties_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IPlayProperties_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IPlayProperties_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IPlayProperties_GetPropType(This,pszProperty,peType)	\
    (This)->lpVtbl -> GetPropType(This,pszProperty,peType)

#define IPlayProperties_GetPropFlags(This,pszProperty,peFlags)	\
    (This)->lpVtbl -> GetPropFlags(This,pszProperty,peFlags)

#define IPlayProperties_GetNumProps(This,dwNum)	\
    (This)->lpVtbl -> GetNumProps(This,dwNum)

#define IPlayProperties_GetPropName(This,index,pszName,dwBufSize)	\
    (This)->lpVtbl -> GetPropName(This,index,pszName,dwBufSize)

#define IPlayProperties_SetPropString(This,pszProperty,pszValue,flags)	\
    (This)->lpVtbl -> SetPropString(This,pszProperty,pszValue,flags)

#define IPlayProperties_GetPropString(This,pszProperty,pszBuffer,uBufSize)	\
    (This)->lpVtbl -> GetPropString(This,pszProperty,pszBuffer,uBufSize)

#define IPlayProperties_SetPropLong(This,pszProperty,lValue,flags)	\
    (This)->lpVtbl -> SetPropLong(This,pszProperty,lValue,flags)

#define IPlayProperties_GetPropLong(This,pszProperty,plVal)	\
    (This)->lpVtbl -> GetPropLong(This,pszProperty,plVal)

#define IPlayProperties_DeleteProp(This,pszProperty)	\
    (This)->lpVtbl -> DeleteProp(This,pszProperty)

#define IPlayProperties_AddEditControls(This,pPanel)	\
    (This)->lpVtbl -> AddEditControls(This,pPanel)

#define IPlayProperties_Clone(This,ppProps)	\
    (This)->lpVtbl -> Clone(This,ppProps)

#define IPlayProperties_GetSearchKeys(This,pPlayCtl)	\
    (This)->lpVtbl -> GetSearchKeys(This,pPlayCtl)

#define IPlayProperties_SetPropGuid(This,pszProperty,pguidValue,flags)	\
    (This)->lpVtbl -> SetPropGuid(This,pszProperty,pguidValue,flags)

#define IPlayProperties_GetPropGuid(This,pszProperty,pguidVal)	\
    (This)->lpVtbl -> GetPropGuid(This,pszProperty,pguidVal)

#define IPlayProperties_Merge(This,pSrcSet,bReplace)	\
    (This)->lpVtbl -> Merge(This,pSrcSet,bReplace)

#define IPlayProperties_StoreInKey(This,hkeyDest)	\
    (This)->lpVtbl -> StoreInKey(This,hkeyDest)

#define IPlayProperties_RetrieveFromKey(This,hkeyDest)	\
    (This)->lpVtbl -> RetrieveFromKey(This,hkeyDest)

#define IPlayProperties_Advise(This,pAdviseSink)	\
    (This)->lpVtbl -> Advise(This,pAdviseSink)

#define IPlayProperties_SetLongPropRange(This,pszPropName,minValue,maxValue,eValid)	\
    (This)->lpVtbl -> SetLongPropRange(This,pszPropName,minValue,maxValue,eValid)

#define IPlayProperties_QueryLongPropRange(This,pszPropName,pminValue,pmaxValue,peValid)	\
    (This)->lpVtbl -> QueryLongPropRange(This,pszPropName,pminValue,pmaxValue,peValid)

#define IPlayProperties_SetOwner(This,pAdviseSink)	\
    (This)->lpVtbl -> SetOwner(This,pAdviseSink)

#define IPlayProperties_UpdateExistingFrom(This,pSrcSet)	\
    (This)->lpVtbl -> UpdateExistingFrom(This,pSrcSet)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE IPlayProperties_GetPropType_Proxy( 
    IPlayProperties __RPC_FAR * This,
    /* [string][in] */ LPSTR pszProperty,
    /* [out] */ LONG __RPC_FAR *peType);


void __RPC_STUB IPlayProperties_GetPropType_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IPlayProperties_GetPropFlags_Proxy( 
    IPlayProperties __RPC_FAR * This,
    /* [string][in] */ LPSTR pszProperty,
    /* [out] */ LONG __RPC_FAR *peFlags);


void __RPC_STUB IPlayProperties_GetPropFlags_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IPlayProperties_GetNumProps_Proxy( 
    IPlayProperties __RPC_FAR * This,
    /* [out] */ DWORD __RPC_FAR *dwNum);


void __RPC_STUB IPlayProperties_GetNumProps_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IPlayProperties_GetPropName_Proxy( 
    IPlayProperties __RPC_FAR * This,
    /* [in] */ DWORD index,
    /* [string][out] */ LPSTR pszName,
    /* [in] */ DWORD dwBufSize);


void __RPC_STUB IPlayProperties_GetPropName_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IPlayProperties_SetPropString_Proxy( 
    IPlayProperties __RPC_FAR * This,
    /* [string][in] */ LPSTR pszProperty,
    /* [string][in] */ LPSTR pszValue,
    /* [in] */ LONG flags);


void __RPC_STUB IPlayProperties_SetPropString_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IPlayProperties_GetPropString_Proxy( 
    IPlayProperties __RPC_FAR * This,
    /* [string][in] */ LPSTR pszProperty,
    /* [string][out] */ LPSTR pszBuffer,
    /* [in] */ ULONG uBufSize);


void __RPC_STUB IPlayProperties_GetPropString_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IPlayProperties_SetPropLong_Proxy( 
    IPlayProperties __RPC_FAR * This,
    /* [string][in] */ LPSTR pszProperty,
    /* [in] */ LONG lValue,
    /* [in] */ LONG flags);


void __RPC_STUB IPlayProperties_SetPropLong_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IPlayProperties_GetPropLong_Proxy( 
    IPlayProperties __RPC_FAR * This,
    /* [string][in] */ LPSTR pszProperty,
    /* [out] */ LONG __RPC_FAR *plVal);


void __RPC_STUB IPlayProperties_GetPropLong_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IPlayProperties_DeleteProp_Proxy( 
    IPlayProperties __RPC_FAR * This,
    /* [string][in] */ LPSTR pszProperty);


void __RPC_STUB IPlayProperties_DeleteProp_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IPlayProperties_AddEditControls_Proxy( 
    IPlayProperties __RPC_FAR * This,
    IPlayPanel __RPC_FAR *pPanel);


void __RPC_STUB IPlayProperties_AddEditControls_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IPlayProperties_Clone_Proxy( 
    IPlayProperties __RPC_FAR * This,
    IPlayProperties __RPC_FAR *__RPC_FAR *ppProps);


void __RPC_STUB IPlayProperties_Clone_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IPlayProperties_GetSearchKeys_Proxy( 
    IPlayProperties __RPC_FAR * This,
    IPlayStringList __RPC_FAR *pPlayCtl);


void __RPC_STUB IPlayProperties_GetSearchKeys_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IPlayProperties_SetPropGuid_Proxy( 
    IPlayProperties __RPC_FAR * This,
    /* [string][in] */ LPSTR pszProperty,
    /* [in] */ GUID __RPC_FAR *pguidValue,
    /* [in] */ LONG flags);


void __RPC_STUB IPlayProperties_SetPropGuid_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IPlayProperties_GetPropGuid_Proxy( 
    IPlayProperties __RPC_FAR * This,
    /* [string][in] */ LPSTR pszProperty,
    /* [out] */ GUID __RPC_FAR *pguidVal);


void __RPC_STUB IPlayProperties_GetPropGuid_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IPlayProperties_Merge_Proxy( 
    IPlayProperties __RPC_FAR * This,
    /* [in] */ IPlayProperties __RPC_FAR *pSrcSet,
    /* [in] */ BOOL bReplace);


void __RPC_STUB IPlayProperties_Merge_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IPlayProperties_StoreInKey_Proxy( 
    IPlayProperties __RPC_FAR * This,
    /* [in] */ HKEY hkeyDest);


void __RPC_STUB IPlayProperties_StoreInKey_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IPlayProperties_RetrieveFromKey_Proxy( 
    IPlayProperties __RPC_FAR * This,
    /* [in] */ HKEY hkeyDest);


void __RPC_STUB IPlayProperties_RetrieveFromKey_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IPlayProperties_Advise_Proxy( 
    IPlayProperties __RPC_FAR * This,
    IPlayPropertiesAdviseSink __RPC_FAR *pAdviseSink);


void __RPC_STUB IPlayProperties_Advise_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IPlayProperties_SetLongPropRange_Proxy( 
    IPlayProperties __RPC_FAR * This,
    LPSTR pszPropName,
    long minValue,
    long maxValue,
    EPPValidationMethod eValid);


void __RPC_STUB IPlayProperties_SetLongPropRange_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IPlayProperties_QueryLongPropRange_Proxy( 
    IPlayProperties __RPC_FAR * This,
    LPSTR pszPropName,
    long __RPC_FAR *pminValue,
    long __RPC_FAR *pmaxValue,
    EPPValidationMethod __RPC_FAR *peValid);


void __RPC_STUB IPlayProperties_QueryLongPropRange_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IPlayProperties_SetOwner_Proxy( 
    IPlayProperties __RPC_FAR * This,
    IPlayPropertiesOwnerAdviseSink __RPC_FAR *pAdviseSink);


void __RPC_STUB IPlayProperties_SetOwner_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IPlayProperties_UpdateExistingFrom_Proxy( 
    IPlayProperties __RPC_FAR * This,
    /* [in] */ IPlayProperties __RPC_FAR *pSrcSet);


void __RPC_STUB IPlayProperties_UpdateExistingFrom_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IPlayProperties_INTERFACE_DEFINED__ */


/* Additional Prototypes for ALL interfaces */

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif
