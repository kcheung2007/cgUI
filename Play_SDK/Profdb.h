/* this ALWAYS GENERATED file contains the definitions for the interfaces */


/* File created by MIDL compiler version 3.01.75 */
/* at Tue Nov 23 05:28:33 1999
 */
/* Compiler settings for Profdb.idl:
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

#ifndef __Profdb_h__
#define __Profdb_h__

#ifdef __cplusplus
extern "C"{
#endif 

/* Forward Declarations */ 

#ifndef __I422DeviceProfile_FWD_DEFINED__
#define __I422DeviceProfile_FWD_DEFINED__
typedef interface I422DeviceProfile I422DeviceProfile;
#endif 	/* __I422DeviceProfile_FWD_DEFINED__ */


#ifndef __I422DeviceProfileDatabaseManager_FWD_DEFINED__
#define __I422DeviceProfileDatabaseManager_FWD_DEFINED__
typedef interface I422DeviceProfileDatabaseManager I422DeviceProfileDatabaseManager;
#endif 	/* __I422DeviceProfileDatabaseManager_FWD_DEFINED__ */


/* header files for imported files */
#include "unknwn.h"

void __RPC_FAR * __RPC_USER MIDL_user_allocate(size_t);
void __RPC_USER MIDL_user_free( void __RPC_FAR * ); 

/****************************************
 * Generated header for interface: __MIDL_itf_Profdb_0000
 * at Tue Nov 23 05:28:33 1999
 * using MIDL 3.01.75
 ****************************************/
/* [local] */ 





extern RPC_IF_HANDLE __MIDL_itf_Profdb_0000_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_Profdb_0000_v0_0_s_ifspec;

#ifndef __I422DeviceProfile_INTERFACE_DEFINED__
#define __I422DeviceProfile_INTERFACE_DEFINED__

/****************************************
 * Generated header for interface: I422DeviceProfile
 * at Tue Nov 23 05:28:33 1999
 * using MIDL 3.01.75
 ****************************************/
/* [uuid][object][local] */ 


typedef struct  tagS422DeviceProfileInfo
    {
    DWORD dwID;
    LONGLONG llModes;
    DWORD dwFormats;
    unsigned char szDevname[ 260 ];
    }	S422DeviceProfileInfo;


EXTERN_C const IID IID_I422DeviceProfile;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    interface DECLSPEC_UUID("8335e495-ab3b-11ce-8468-0000b468276b")
    I422DeviceProfile : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE Load( 
            IStorage __RPC_FAR *pStg,
            DWORD dwID) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Save( 
            IStorage __RPC_FAR *pStg) = 0;
        
        virtual I422DeviceProfile __RPC_FAR *STDMETHODCALLTYPE Clone( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetInfo( 
            /* [in] */ long structSize,
            /* [out] */ S422DeviceProfileInfo __RPC_FAR *pStruct) = 0;
        
        virtual DWORD STDMETHODCALLTYPE GetID( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetName( 
            LPSTR pszName) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetID( 
            DWORD dwID) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetFormat( 
            DWORD dwFormats) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetModes( 
            LONGLONG llModes) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct I422DeviceProfileVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            I422DeviceProfile __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            I422DeviceProfile __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            I422DeviceProfile __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Load )( 
            I422DeviceProfile __RPC_FAR * This,
            IStorage __RPC_FAR *pStg,
            DWORD dwID);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Save )( 
            I422DeviceProfile __RPC_FAR * This,
            IStorage __RPC_FAR *pStg);
        
        I422DeviceProfile __RPC_FAR *( STDMETHODCALLTYPE __RPC_FAR *Clone )( 
            I422DeviceProfile __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetInfo )( 
            I422DeviceProfile __RPC_FAR * This,
            /* [in] */ long structSize,
            /* [out] */ S422DeviceProfileInfo __RPC_FAR *pStruct);
        
        DWORD ( STDMETHODCALLTYPE __RPC_FAR *GetID )( 
            I422DeviceProfile __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetName )( 
            I422DeviceProfile __RPC_FAR * This,
            LPSTR pszName);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetID )( 
            I422DeviceProfile __RPC_FAR * This,
            DWORD dwID);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetFormat )( 
            I422DeviceProfile __RPC_FAR * This,
            DWORD dwFormats);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetModes )( 
            I422DeviceProfile __RPC_FAR * This,
            LONGLONG llModes);
        
        END_INTERFACE
    } I422DeviceProfileVtbl;

    interface I422DeviceProfile
    {
        CONST_VTBL struct I422DeviceProfileVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define I422DeviceProfile_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define I422DeviceProfile_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define I422DeviceProfile_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define I422DeviceProfile_Load(This,pStg,dwID)	\
    (This)->lpVtbl -> Load(This,pStg,dwID)

#define I422DeviceProfile_Save(This,pStg)	\
    (This)->lpVtbl -> Save(This,pStg)

#define I422DeviceProfile_Clone(This)	\
    (This)->lpVtbl -> Clone(This)

#define I422DeviceProfile_GetInfo(This,structSize,pStruct)	\
    (This)->lpVtbl -> GetInfo(This,structSize,pStruct)

#define I422DeviceProfile_GetID(This)	\
    (This)->lpVtbl -> GetID(This)

#define I422DeviceProfile_SetName(This,pszName)	\
    (This)->lpVtbl -> SetName(This,pszName)

#define I422DeviceProfile_SetID(This,dwID)	\
    (This)->lpVtbl -> SetID(This,dwID)

#define I422DeviceProfile_SetFormat(This,dwFormats)	\
    (This)->lpVtbl -> SetFormat(This,dwFormats)

#define I422DeviceProfile_SetModes(This,llModes)	\
    (This)->lpVtbl -> SetModes(This,llModes)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE I422DeviceProfile_Load_Proxy( 
    I422DeviceProfile __RPC_FAR * This,
    IStorage __RPC_FAR *pStg,
    DWORD dwID);


void __RPC_STUB I422DeviceProfile_Load_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE I422DeviceProfile_Save_Proxy( 
    I422DeviceProfile __RPC_FAR * This,
    IStorage __RPC_FAR *pStg);


void __RPC_STUB I422DeviceProfile_Save_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


I422DeviceProfile __RPC_FAR *STDMETHODCALLTYPE I422DeviceProfile_Clone_Proxy( 
    I422DeviceProfile __RPC_FAR * This);


void __RPC_STUB I422DeviceProfile_Clone_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE I422DeviceProfile_GetInfo_Proxy( 
    I422DeviceProfile __RPC_FAR * This,
    /* [in] */ long structSize,
    /* [out] */ S422DeviceProfileInfo __RPC_FAR *pStruct);


void __RPC_STUB I422DeviceProfile_GetInfo_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


DWORD STDMETHODCALLTYPE I422DeviceProfile_GetID_Proxy( 
    I422DeviceProfile __RPC_FAR * This);


void __RPC_STUB I422DeviceProfile_GetID_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE I422DeviceProfile_SetName_Proxy( 
    I422DeviceProfile __RPC_FAR * This,
    LPSTR pszName);


void __RPC_STUB I422DeviceProfile_SetName_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE I422DeviceProfile_SetID_Proxy( 
    I422DeviceProfile __RPC_FAR * This,
    DWORD dwID);


void __RPC_STUB I422DeviceProfile_SetID_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE I422DeviceProfile_SetFormat_Proxy( 
    I422DeviceProfile __RPC_FAR * This,
    DWORD dwFormats);


void __RPC_STUB I422DeviceProfile_SetFormat_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE I422DeviceProfile_SetModes_Proxy( 
    I422DeviceProfile __RPC_FAR * This,
    LONGLONG llModes);


void __RPC_STUB I422DeviceProfile_SetModes_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __I422DeviceProfile_INTERFACE_DEFINED__ */


#ifndef __I422DeviceProfileDatabaseManager_INTERFACE_DEFINED__
#define __I422DeviceProfileDatabaseManager_INTERFACE_DEFINED__

/****************************************
 * Generated header for interface: I422DeviceProfileDatabaseManager
 * at Tue Nov 23 05:28:33 1999
 * using MIDL 3.01.75
 ****************************************/
/* [uuid][object][local] */ 



EXTERN_C const IID IID_I422DeviceProfileDatabaseManager;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    interface DECLSPEC_UUID("8335e494-ab3b-11ce-8468-0000b468276b")
    I422DeviceProfileDatabaseManager : public IUnknown
    {
    public:
        virtual DWORD STDMETHODCALLTYPE QueryNumProfiles( void) = 0;
        
        virtual I422DeviceProfile __RPC_FAR *STDMETHODCALLTYPE FindProfileIndexed( 
            DWORD dwIndex) = 0;
        
        virtual I422DeviceProfile __RPC_FAR *STDMETHODCALLTYPE FindProfile( 
            DWORD dwID) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Load( 
            LPSTR pszFilename) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Save( 
            LPSTR pszFilename) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE AddProfile( 
            I422DeviceProfile __RPC_FAR *pProfile) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE RemoveProfile( 
            DWORD dwID) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Merge( 
            I422DeviceProfileDatabaseManager __RPC_FAR *pMergeFrom,
            long fReplace,
            DWORD __RPC_FAR *pdwNumMerged) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE IsSaved( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetDirty( void) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct I422DeviceProfileDatabaseManagerVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            I422DeviceProfileDatabaseManager __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            I422DeviceProfileDatabaseManager __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            I422DeviceProfileDatabaseManager __RPC_FAR * This);
        
        DWORD ( STDMETHODCALLTYPE __RPC_FAR *QueryNumProfiles )( 
            I422DeviceProfileDatabaseManager __RPC_FAR * This);
        
        I422DeviceProfile __RPC_FAR *( STDMETHODCALLTYPE __RPC_FAR *FindProfileIndexed )( 
            I422DeviceProfileDatabaseManager __RPC_FAR * This,
            DWORD dwIndex);
        
        I422DeviceProfile __RPC_FAR *( STDMETHODCALLTYPE __RPC_FAR *FindProfile )( 
            I422DeviceProfileDatabaseManager __RPC_FAR * This,
            DWORD dwID);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Load )( 
            I422DeviceProfileDatabaseManager __RPC_FAR * This,
            LPSTR pszFilename);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Save )( 
            I422DeviceProfileDatabaseManager __RPC_FAR * This,
            LPSTR pszFilename);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *AddProfile )( 
            I422DeviceProfileDatabaseManager __RPC_FAR * This,
            I422DeviceProfile __RPC_FAR *pProfile);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *RemoveProfile )( 
            I422DeviceProfileDatabaseManager __RPC_FAR * This,
            DWORD dwID);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Merge )( 
            I422DeviceProfileDatabaseManager __RPC_FAR * This,
            I422DeviceProfileDatabaseManager __RPC_FAR *pMergeFrom,
            long fReplace,
            DWORD __RPC_FAR *pdwNumMerged);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *IsSaved )( 
            I422DeviceProfileDatabaseManager __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetDirty )( 
            I422DeviceProfileDatabaseManager __RPC_FAR * This);
        
        END_INTERFACE
    } I422DeviceProfileDatabaseManagerVtbl;

    interface I422DeviceProfileDatabaseManager
    {
        CONST_VTBL struct I422DeviceProfileDatabaseManagerVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define I422DeviceProfileDatabaseManager_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define I422DeviceProfileDatabaseManager_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define I422DeviceProfileDatabaseManager_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define I422DeviceProfileDatabaseManager_QueryNumProfiles(This)	\
    (This)->lpVtbl -> QueryNumProfiles(This)

#define I422DeviceProfileDatabaseManager_FindProfileIndexed(This,dwIndex)	\
    (This)->lpVtbl -> FindProfileIndexed(This,dwIndex)

#define I422DeviceProfileDatabaseManager_FindProfile(This,dwID)	\
    (This)->lpVtbl -> FindProfile(This,dwID)

#define I422DeviceProfileDatabaseManager_Load(This,pszFilename)	\
    (This)->lpVtbl -> Load(This,pszFilename)

#define I422DeviceProfileDatabaseManager_Save(This,pszFilename)	\
    (This)->lpVtbl -> Save(This,pszFilename)

#define I422DeviceProfileDatabaseManager_AddProfile(This,pProfile)	\
    (This)->lpVtbl -> AddProfile(This,pProfile)

#define I422DeviceProfileDatabaseManager_RemoveProfile(This,dwID)	\
    (This)->lpVtbl -> RemoveProfile(This,dwID)

#define I422DeviceProfileDatabaseManager_Merge(This,pMergeFrom,fReplace,pdwNumMerged)	\
    (This)->lpVtbl -> Merge(This,pMergeFrom,fReplace,pdwNumMerged)

#define I422DeviceProfileDatabaseManager_IsSaved(This)	\
    (This)->lpVtbl -> IsSaved(This)

#define I422DeviceProfileDatabaseManager_SetDirty(This)	\
    (This)->lpVtbl -> SetDirty(This)

#endif /* COBJMACROS */


#endif 	/* C style interface */



DWORD STDMETHODCALLTYPE I422DeviceProfileDatabaseManager_QueryNumProfiles_Proxy( 
    I422DeviceProfileDatabaseManager __RPC_FAR * This);


void __RPC_STUB I422DeviceProfileDatabaseManager_QueryNumProfiles_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


I422DeviceProfile __RPC_FAR *STDMETHODCALLTYPE I422DeviceProfileDatabaseManager_FindProfileIndexed_Proxy( 
    I422DeviceProfileDatabaseManager __RPC_FAR * This,
    DWORD dwIndex);


void __RPC_STUB I422DeviceProfileDatabaseManager_FindProfileIndexed_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


I422DeviceProfile __RPC_FAR *STDMETHODCALLTYPE I422DeviceProfileDatabaseManager_FindProfile_Proxy( 
    I422DeviceProfileDatabaseManager __RPC_FAR * This,
    DWORD dwID);


void __RPC_STUB I422DeviceProfileDatabaseManager_FindProfile_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE I422DeviceProfileDatabaseManager_Load_Proxy( 
    I422DeviceProfileDatabaseManager __RPC_FAR * This,
    LPSTR pszFilename);


void __RPC_STUB I422DeviceProfileDatabaseManager_Load_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE I422DeviceProfileDatabaseManager_Save_Proxy( 
    I422DeviceProfileDatabaseManager __RPC_FAR * This,
    LPSTR pszFilename);


void __RPC_STUB I422DeviceProfileDatabaseManager_Save_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE I422DeviceProfileDatabaseManager_AddProfile_Proxy( 
    I422DeviceProfileDatabaseManager __RPC_FAR * This,
    I422DeviceProfile __RPC_FAR *pProfile);


void __RPC_STUB I422DeviceProfileDatabaseManager_AddProfile_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE I422DeviceProfileDatabaseManager_RemoveProfile_Proxy( 
    I422DeviceProfileDatabaseManager __RPC_FAR * This,
    DWORD dwID);


void __RPC_STUB I422DeviceProfileDatabaseManager_RemoveProfile_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE I422DeviceProfileDatabaseManager_Merge_Proxy( 
    I422DeviceProfileDatabaseManager __RPC_FAR * This,
    I422DeviceProfileDatabaseManager __RPC_FAR *pMergeFrom,
    long fReplace,
    DWORD __RPC_FAR *pdwNumMerged);


void __RPC_STUB I422DeviceProfileDatabaseManager_Merge_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE I422DeviceProfileDatabaseManager_IsSaved_Proxy( 
    I422DeviceProfileDatabaseManager __RPC_FAR * This);


void __RPC_STUB I422DeviceProfileDatabaseManager_IsSaved_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE I422DeviceProfileDatabaseManager_SetDirty_Proxy( 
    I422DeviceProfileDatabaseManager __RPC_FAR * This);


void __RPC_STUB I422DeviceProfileDatabaseManager_SetDirty_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __I422DeviceProfileDatabaseManager_INTERFACE_DEFINED__ */


/* Additional Prototypes for ALL interfaces */

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif
