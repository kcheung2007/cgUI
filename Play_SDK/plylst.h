/* this ALWAYS GENERATED file contains the definitions for the interfaces */


/* File created by MIDL compiler version 3.01.75 */
/* at Tue Nov 23 05:28:32 1999
 */
/* Compiler settings for plylst.idl:
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

#ifndef __plylst_h__
#define __plylst_h__

#ifdef __cplusplus
extern "C"{
#endif 

/* Forward Declarations */ 

#ifndef __ITrnPlayList_FWD_DEFINED__
#define __ITrnPlayList_FWD_DEFINED__
typedef interface ITrnPlayList ITrnPlayList;
#endif 	/* __ITrnPlayList_FWD_DEFINED__ */


#ifndef __ITrnPlayListElement_FWD_DEFINED__
#define __ITrnPlayListElement_FWD_DEFINED__
typedef interface ITrnPlayListElement ITrnPlayListElement;
#endif 	/* __ITrnPlayListElement_FWD_DEFINED__ */


#ifndef __ITrnPlayListRamp_FWD_DEFINED__
#define __ITrnPlayListRamp_FWD_DEFINED__
typedef interface ITrnPlayListRamp ITrnPlayListRamp;
#endif 	/* __ITrnPlayListRamp_FWD_DEFINED__ */


#ifndef __ITrnPlayListCubic_FWD_DEFINED__
#define __ITrnPlayListCubic_FWD_DEFINED__
typedef interface ITrnPlayListCubic ITrnPlayListCubic;
#endif 	/* __ITrnPlayListCubic_FWD_DEFINED__ */


#ifndef __ITrnPlayListIterator_FWD_DEFINED__
#define __ITrnPlayListIterator_FWD_DEFINED__
typedef interface ITrnPlayListIterator ITrnPlayListIterator;
#endif 	/* __ITrnPlayListIterator_FWD_DEFINED__ */


#ifndef __ITrnPlayListLoop_FWD_DEFINED__
#define __ITrnPlayListLoop_FWD_DEFINED__
typedef interface ITrnPlayListLoop ITrnPlayListLoop;
#endif 	/* __ITrnPlayListLoop_FWD_DEFINED__ */


#ifndef __ITrnPlayListConditional_FWD_DEFINED__
#define __ITrnPlayListConditional_FWD_DEFINED__
typedef interface ITrnPlayListConditional ITrnPlayListConditional;
#endif 	/* __ITrnPlayListConditional_FWD_DEFINED__ */


/* header files for imported files */
#include "wtypes.h"
#include "unknwn.h"
#include "objidl.h"

void __RPC_FAR * __RPC_USER MIDL_user_allocate(size_t);
void __RPC_USER MIDL_user_free( void __RPC_FAR * ); 

/****************************************
 * Generated header for interface: __MIDL_itf_plylst_0000
 * at Tue Nov 23 05:28:32 1999
 * using MIDL 3.01.75
 ****************************************/
/* [local] */ 











extern RPC_IF_HANDLE __MIDL_itf_plylst_0000_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_plylst_0000_v0_0_s_ifspec;

#ifndef __ITrnPlayList_INTERFACE_DEFINED__
#define __ITrnPlayList_INTERFACE_DEFINED__

/****************************************
 * Generated header for interface: ITrnPlayList
 * at Tue Nov 23 05:28:32 1999
 * using MIDL 3.01.75
 ****************************************/
/* [unique][uuid][object][local] */ 


typedef struct  tagSTrnPlayList
    {
    DWORD schemeSize;
    /* [size_is] */ LPVOID pIterationScheme;
    DWORD tableSize;
    DWORD tableEltSize;
    /* [size_is] */ LPVOID pMapTable;
    }	STrnPlayList;


enum __MIDL_ITrnPlayList_0001
    {	NOVALUE	= -1
    };

EXTERN_C const IID IID_ITrnPlayList;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    interface DECLSPEC_UUID("8335e5df-ab3b-11ce-8468-0000b468276b")
    ITrnPlayList : public IPersistStream
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE LoadFromMemory( 
            STrnPlayList __RPC_FAR *pList) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE LoadWithByteTable( 
            BYTE __RPC_FAR *pTable,
            unsigned int tableSize) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE LoadWithWordTable( 
            WORD __RPC_FAR *pTable,
            unsigned int tableSize) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE LoadWithDWordTable( 
            DWORD __RPC_FAR *pTable,
            unsigned int tableSize) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE ConcatLiteral( 
            unsigned long value) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE ConcatRamp( 
            unsigned long start,
            long increment,
            unsigned long duration) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE ConcatRampCannonical( 
            double linearCoeff,
            double constCoeff,
            double scale,
            unsigned long duration) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE ConcatCubic( 
            unsigned long initx,
            long initdx,
            long initddx,
            long dddx,
            unsigned long duration) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE ConcatCubicCannonical( 
            double a,
            double b,
            double c,
            double d,
            double scale,
            unsigned long duration) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE ConcatPlayList( 
            ITrnPlayList __RPC_FAR *secondList) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE WrapWithIterator( 
            unsigned long duration,
            unsigned long exitevent) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE WrapWithLoop( 
            unsigned long exitEventId) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE WrapWithConditional( 
            unsigned long seteventid,
            unsigned long clreventid,
            unsigned long initialvalue) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetMapTable( 
            unsigned int tableSize,
            unsigned int tableEltSize,
            LPVOID pMapTable) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SaveToMemory( 
            STrnPlayList __RPC_FAR *pCoreData) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Clone( 
            ITrnPlayList __RPC_FAR *__RPC_FAR *ppList) = 0;
        
        virtual long STDMETHODCALLTYPE Init( 
            BOOL initialize) = 0;
        
        virtual BOOL STDMETHODCALLTYPE ProcessSystemEvent( 
            unsigned long id) = 0;
        
        virtual long STDMETHODCALLTYPE Advance( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE EnumerateEvents( 
            LPDWORD pBuffer,
            unsigned int dwBufferSize,
            unsigned int __RPC_FAR *pEventsReturned) = 0;
        
        virtual long STDMETHODCALLTYPE SchemeLength( void) = 0;
        
        virtual long STDMETHODCALLTYPE ValueAt( 
            long t) = 0;
        
        virtual long STDMETHODCALLTYPE SetPosition( 
            long t) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE CurrentElement( 
            ITrnPlayListElement __RPC_FAR *__RPC_FAR *ppV) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE EnumElements( 
            IEnumUnknown __RPC_FAR *__RPC_FAR *ppEnum) = 0;
        
        virtual STrnPlayList __RPC_FAR *STDMETHODCALLTYPE Data( void) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct ITrnPlayListVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            ITrnPlayList __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            ITrnPlayList __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            ITrnPlayList __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetClassID )( 
            ITrnPlayList __RPC_FAR * This,
            /* [out] */ CLSID __RPC_FAR *pClassID);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *IsDirty )( 
            ITrnPlayList __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Load )( 
            ITrnPlayList __RPC_FAR * This,
            /* [unique][in] */ IStream __RPC_FAR *pStm);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Save )( 
            ITrnPlayList __RPC_FAR * This,
            /* [unique][in] */ IStream __RPC_FAR *pStm,
            /* [in] */ BOOL fClearDirty);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetSizeMax )( 
            ITrnPlayList __RPC_FAR * This,
            /* [out] */ ULARGE_INTEGER __RPC_FAR *pcbSize);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *LoadFromMemory )( 
            ITrnPlayList __RPC_FAR * This,
            STrnPlayList __RPC_FAR *pList);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *LoadWithByteTable )( 
            ITrnPlayList __RPC_FAR * This,
            BYTE __RPC_FAR *pTable,
            unsigned int tableSize);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *LoadWithWordTable )( 
            ITrnPlayList __RPC_FAR * This,
            WORD __RPC_FAR *pTable,
            unsigned int tableSize);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *LoadWithDWordTable )( 
            ITrnPlayList __RPC_FAR * This,
            DWORD __RPC_FAR *pTable,
            unsigned int tableSize);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *ConcatLiteral )( 
            ITrnPlayList __RPC_FAR * This,
            unsigned long value);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *ConcatRamp )( 
            ITrnPlayList __RPC_FAR * This,
            unsigned long start,
            long increment,
            unsigned long duration);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *ConcatRampCannonical )( 
            ITrnPlayList __RPC_FAR * This,
            double linearCoeff,
            double constCoeff,
            double scale,
            unsigned long duration);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *ConcatCubic )( 
            ITrnPlayList __RPC_FAR * This,
            unsigned long initx,
            long initdx,
            long initddx,
            long dddx,
            unsigned long duration);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *ConcatCubicCannonical )( 
            ITrnPlayList __RPC_FAR * This,
            double a,
            double b,
            double c,
            double d,
            double scale,
            unsigned long duration);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *ConcatPlayList )( 
            ITrnPlayList __RPC_FAR * This,
            ITrnPlayList __RPC_FAR *secondList);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *WrapWithIterator )( 
            ITrnPlayList __RPC_FAR * This,
            unsigned long duration,
            unsigned long exitevent);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *WrapWithLoop )( 
            ITrnPlayList __RPC_FAR * This,
            unsigned long exitEventId);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *WrapWithConditional )( 
            ITrnPlayList __RPC_FAR * This,
            unsigned long seteventid,
            unsigned long clreventid,
            unsigned long initialvalue);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetMapTable )( 
            ITrnPlayList __RPC_FAR * This,
            unsigned int tableSize,
            unsigned int tableEltSize,
            LPVOID pMapTable);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SaveToMemory )( 
            ITrnPlayList __RPC_FAR * This,
            STrnPlayList __RPC_FAR *pCoreData);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Clone )( 
            ITrnPlayList __RPC_FAR * This,
            ITrnPlayList __RPC_FAR *__RPC_FAR *ppList);
        
        long ( STDMETHODCALLTYPE __RPC_FAR *Init )( 
            ITrnPlayList __RPC_FAR * This,
            BOOL initialize);
        
        BOOL ( STDMETHODCALLTYPE __RPC_FAR *ProcessSystemEvent )( 
            ITrnPlayList __RPC_FAR * This,
            unsigned long id);
        
        long ( STDMETHODCALLTYPE __RPC_FAR *Advance )( 
            ITrnPlayList __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *EnumerateEvents )( 
            ITrnPlayList __RPC_FAR * This,
            LPDWORD pBuffer,
            unsigned int dwBufferSize,
            unsigned int __RPC_FAR *pEventsReturned);
        
        long ( STDMETHODCALLTYPE __RPC_FAR *SchemeLength )( 
            ITrnPlayList __RPC_FAR * This);
        
        long ( STDMETHODCALLTYPE __RPC_FAR *ValueAt )( 
            ITrnPlayList __RPC_FAR * This,
            long t);
        
        long ( STDMETHODCALLTYPE __RPC_FAR *SetPosition )( 
            ITrnPlayList __RPC_FAR * This,
            long t);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *CurrentElement )( 
            ITrnPlayList __RPC_FAR * This,
            ITrnPlayListElement __RPC_FAR *__RPC_FAR *ppV);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *EnumElements )( 
            ITrnPlayList __RPC_FAR * This,
            IEnumUnknown __RPC_FAR *__RPC_FAR *ppEnum);
        
        STrnPlayList __RPC_FAR *( STDMETHODCALLTYPE __RPC_FAR *Data )( 
            ITrnPlayList __RPC_FAR * This);
        
        END_INTERFACE
    } ITrnPlayListVtbl;

    interface ITrnPlayList
    {
        CONST_VTBL struct ITrnPlayListVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ITrnPlayList_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define ITrnPlayList_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define ITrnPlayList_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define ITrnPlayList_GetClassID(This,pClassID)	\
    (This)->lpVtbl -> GetClassID(This,pClassID)


#define ITrnPlayList_IsDirty(This)	\
    (This)->lpVtbl -> IsDirty(This)

#define ITrnPlayList_Load(This,pStm)	\
    (This)->lpVtbl -> Load(This,pStm)

#define ITrnPlayList_Save(This,pStm,fClearDirty)	\
    (This)->lpVtbl -> Save(This,pStm,fClearDirty)

#define ITrnPlayList_GetSizeMax(This,pcbSize)	\
    (This)->lpVtbl -> GetSizeMax(This,pcbSize)


#define ITrnPlayList_LoadFromMemory(This,pList)	\
    (This)->lpVtbl -> LoadFromMemory(This,pList)

#define ITrnPlayList_LoadWithByteTable(This,pTable,tableSize)	\
    (This)->lpVtbl -> LoadWithByteTable(This,pTable,tableSize)

#define ITrnPlayList_LoadWithWordTable(This,pTable,tableSize)	\
    (This)->lpVtbl -> LoadWithWordTable(This,pTable,tableSize)

#define ITrnPlayList_LoadWithDWordTable(This,pTable,tableSize)	\
    (This)->lpVtbl -> LoadWithDWordTable(This,pTable,tableSize)

#define ITrnPlayList_ConcatLiteral(This,value)	\
    (This)->lpVtbl -> ConcatLiteral(This,value)

#define ITrnPlayList_ConcatRamp(This,start,increment,duration)	\
    (This)->lpVtbl -> ConcatRamp(This,start,increment,duration)

#define ITrnPlayList_ConcatRampCannonical(This,linearCoeff,constCoeff,scale,duration)	\
    (This)->lpVtbl -> ConcatRampCannonical(This,linearCoeff,constCoeff,scale,duration)

#define ITrnPlayList_ConcatCubic(This,initx,initdx,initddx,dddx,duration)	\
    (This)->lpVtbl -> ConcatCubic(This,initx,initdx,initddx,dddx,duration)

#define ITrnPlayList_ConcatCubicCannonical(This,a,b,c,d,scale,duration)	\
    (This)->lpVtbl -> ConcatCubicCannonical(This,a,b,c,d,scale,duration)

#define ITrnPlayList_ConcatPlayList(This,secondList)	\
    (This)->lpVtbl -> ConcatPlayList(This,secondList)

#define ITrnPlayList_WrapWithIterator(This,duration,exitevent)	\
    (This)->lpVtbl -> WrapWithIterator(This,duration,exitevent)

#define ITrnPlayList_WrapWithLoop(This,exitEventId)	\
    (This)->lpVtbl -> WrapWithLoop(This,exitEventId)

#define ITrnPlayList_WrapWithConditional(This,seteventid,clreventid,initialvalue)	\
    (This)->lpVtbl -> WrapWithConditional(This,seteventid,clreventid,initialvalue)

#define ITrnPlayList_SetMapTable(This,tableSize,tableEltSize,pMapTable)	\
    (This)->lpVtbl -> SetMapTable(This,tableSize,tableEltSize,pMapTable)

#define ITrnPlayList_SaveToMemory(This,pCoreData)	\
    (This)->lpVtbl -> SaveToMemory(This,pCoreData)

#define ITrnPlayList_Clone(This,ppList)	\
    (This)->lpVtbl -> Clone(This,ppList)

#define ITrnPlayList_Init(This,initialize)	\
    (This)->lpVtbl -> Init(This,initialize)

#define ITrnPlayList_ProcessSystemEvent(This,id)	\
    (This)->lpVtbl -> ProcessSystemEvent(This,id)

#define ITrnPlayList_Advance(This)	\
    (This)->lpVtbl -> Advance(This)

#define ITrnPlayList_EnumerateEvents(This,pBuffer,dwBufferSize,pEventsReturned)	\
    (This)->lpVtbl -> EnumerateEvents(This,pBuffer,dwBufferSize,pEventsReturned)

#define ITrnPlayList_SchemeLength(This)	\
    (This)->lpVtbl -> SchemeLength(This)

#define ITrnPlayList_ValueAt(This,t)	\
    (This)->lpVtbl -> ValueAt(This,t)

#define ITrnPlayList_SetPosition(This,t)	\
    (This)->lpVtbl -> SetPosition(This,t)

#define ITrnPlayList_CurrentElement(This,ppV)	\
    (This)->lpVtbl -> CurrentElement(This,ppV)

#define ITrnPlayList_EnumElements(This,ppEnum)	\
    (This)->lpVtbl -> EnumElements(This,ppEnum)

#define ITrnPlayList_Data(This)	\
    (This)->lpVtbl -> Data(This)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE ITrnPlayList_LoadFromMemory_Proxy( 
    ITrnPlayList __RPC_FAR * This,
    STrnPlayList __RPC_FAR *pList);


void __RPC_STUB ITrnPlayList_LoadFromMemory_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE ITrnPlayList_LoadWithByteTable_Proxy( 
    ITrnPlayList __RPC_FAR * This,
    BYTE __RPC_FAR *pTable,
    unsigned int tableSize);


void __RPC_STUB ITrnPlayList_LoadWithByteTable_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE ITrnPlayList_LoadWithWordTable_Proxy( 
    ITrnPlayList __RPC_FAR * This,
    WORD __RPC_FAR *pTable,
    unsigned int tableSize);


void __RPC_STUB ITrnPlayList_LoadWithWordTable_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE ITrnPlayList_LoadWithDWordTable_Proxy( 
    ITrnPlayList __RPC_FAR * This,
    DWORD __RPC_FAR *pTable,
    unsigned int tableSize);


void __RPC_STUB ITrnPlayList_LoadWithDWordTable_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE ITrnPlayList_ConcatLiteral_Proxy( 
    ITrnPlayList __RPC_FAR * This,
    unsigned long value);


void __RPC_STUB ITrnPlayList_ConcatLiteral_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE ITrnPlayList_ConcatRamp_Proxy( 
    ITrnPlayList __RPC_FAR * This,
    unsigned long start,
    long increment,
    unsigned long duration);


void __RPC_STUB ITrnPlayList_ConcatRamp_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE ITrnPlayList_ConcatRampCannonical_Proxy( 
    ITrnPlayList __RPC_FAR * This,
    double linearCoeff,
    double constCoeff,
    double scale,
    unsigned long duration);


void __RPC_STUB ITrnPlayList_ConcatRampCannonical_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE ITrnPlayList_ConcatCubic_Proxy( 
    ITrnPlayList __RPC_FAR * This,
    unsigned long initx,
    long initdx,
    long initddx,
    long dddx,
    unsigned long duration);


void __RPC_STUB ITrnPlayList_ConcatCubic_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE ITrnPlayList_ConcatCubicCannonical_Proxy( 
    ITrnPlayList __RPC_FAR * This,
    double a,
    double b,
    double c,
    double d,
    double scale,
    unsigned long duration);


void __RPC_STUB ITrnPlayList_ConcatCubicCannonical_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE ITrnPlayList_ConcatPlayList_Proxy( 
    ITrnPlayList __RPC_FAR * This,
    ITrnPlayList __RPC_FAR *secondList);


void __RPC_STUB ITrnPlayList_ConcatPlayList_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE ITrnPlayList_WrapWithIterator_Proxy( 
    ITrnPlayList __RPC_FAR * This,
    unsigned long duration,
    unsigned long exitevent);


void __RPC_STUB ITrnPlayList_WrapWithIterator_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE ITrnPlayList_WrapWithLoop_Proxy( 
    ITrnPlayList __RPC_FAR * This,
    unsigned long exitEventId);


void __RPC_STUB ITrnPlayList_WrapWithLoop_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE ITrnPlayList_WrapWithConditional_Proxy( 
    ITrnPlayList __RPC_FAR * This,
    unsigned long seteventid,
    unsigned long clreventid,
    unsigned long initialvalue);


void __RPC_STUB ITrnPlayList_WrapWithConditional_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE ITrnPlayList_SetMapTable_Proxy( 
    ITrnPlayList __RPC_FAR * This,
    unsigned int tableSize,
    unsigned int tableEltSize,
    LPVOID pMapTable);


void __RPC_STUB ITrnPlayList_SetMapTable_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE ITrnPlayList_SaveToMemory_Proxy( 
    ITrnPlayList __RPC_FAR * This,
    STrnPlayList __RPC_FAR *pCoreData);


void __RPC_STUB ITrnPlayList_SaveToMemory_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE ITrnPlayList_Clone_Proxy( 
    ITrnPlayList __RPC_FAR * This,
    ITrnPlayList __RPC_FAR *__RPC_FAR *ppList);


void __RPC_STUB ITrnPlayList_Clone_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


long STDMETHODCALLTYPE ITrnPlayList_Init_Proxy( 
    ITrnPlayList __RPC_FAR * This,
    BOOL initialize);


void __RPC_STUB ITrnPlayList_Init_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


BOOL STDMETHODCALLTYPE ITrnPlayList_ProcessSystemEvent_Proxy( 
    ITrnPlayList __RPC_FAR * This,
    unsigned long id);


void __RPC_STUB ITrnPlayList_ProcessSystemEvent_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


long STDMETHODCALLTYPE ITrnPlayList_Advance_Proxy( 
    ITrnPlayList __RPC_FAR * This);


void __RPC_STUB ITrnPlayList_Advance_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE ITrnPlayList_EnumerateEvents_Proxy( 
    ITrnPlayList __RPC_FAR * This,
    LPDWORD pBuffer,
    unsigned int dwBufferSize,
    unsigned int __RPC_FAR *pEventsReturned);


void __RPC_STUB ITrnPlayList_EnumerateEvents_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


long STDMETHODCALLTYPE ITrnPlayList_SchemeLength_Proxy( 
    ITrnPlayList __RPC_FAR * This);


void __RPC_STUB ITrnPlayList_SchemeLength_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


long STDMETHODCALLTYPE ITrnPlayList_ValueAt_Proxy( 
    ITrnPlayList __RPC_FAR * This,
    long t);


void __RPC_STUB ITrnPlayList_ValueAt_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


long STDMETHODCALLTYPE ITrnPlayList_SetPosition_Proxy( 
    ITrnPlayList __RPC_FAR * This,
    long t);


void __RPC_STUB ITrnPlayList_SetPosition_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE ITrnPlayList_CurrentElement_Proxy( 
    ITrnPlayList __RPC_FAR * This,
    ITrnPlayListElement __RPC_FAR *__RPC_FAR *ppV);


void __RPC_STUB ITrnPlayList_CurrentElement_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE ITrnPlayList_EnumElements_Proxy( 
    ITrnPlayList __RPC_FAR * This,
    IEnumUnknown __RPC_FAR *__RPC_FAR *ppEnum);


void __RPC_STUB ITrnPlayList_EnumElements_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


STrnPlayList __RPC_FAR *STDMETHODCALLTYPE ITrnPlayList_Data_Proxy( 
    ITrnPlayList __RPC_FAR * This);


void __RPC_STUB ITrnPlayList_Data_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __ITrnPlayList_INTERFACE_DEFINED__ */


#ifndef __ITrnPlayListElement_INTERFACE_DEFINED__
#define __ITrnPlayListElement_INTERFACE_DEFINED__

/****************************************
 * Generated header for interface: ITrnPlayListElement
 * at Tue Nov 23 05:28:32 1999
 * using MIDL 3.01.75
 ****************************************/
/* [unique][uuid][object][local] */ 



EXTERN_C const IID IID_ITrnPlayListElement;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    interface DECLSPEC_UUID("8335e5e0-ab3b-11ce-8468-0000b468276b")
    ITrnPlayListElement : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE Next( 
            ITrnPlayListElement __RPC_FAR *__RPC_FAR *ppElt) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE EnumElements( 
            IEnumUnknown __RPC_FAR *__RPC_FAR *ppEnum) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct ITrnPlayListElementVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            ITrnPlayListElement __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            ITrnPlayListElement __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            ITrnPlayListElement __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Next )( 
            ITrnPlayListElement __RPC_FAR * This,
            ITrnPlayListElement __RPC_FAR *__RPC_FAR *ppElt);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *EnumElements )( 
            ITrnPlayListElement __RPC_FAR * This,
            IEnumUnknown __RPC_FAR *__RPC_FAR *ppEnum);
        
        END_INTERFACE
    } ITrnPlayListElementVtbl;

    interface ITrnPlayListElement
    {
        CONST_VTBL struct ITrnPlayListElementVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ITrnPlayListElement_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define ITrnPlayListElement_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define ITrnPlayListElement_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define ITrnPlayListElement_Next(This,ppElt)	\
    (This)->lpVtbl -> Next(This,ppElt)

#define ITrnPlayListElement_EnumElements(This,ppEnum)	\
    (This)->lpVtbl -> EnumElements(This,ppEnum)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE ITrnPlayListElement_Next_Proxy( 
    ITrnPlayListElement __RPC_FAR * This,
    ITrnPlayListElement __RPC_FAR *__RPC_FAR *ppElt);


void __RPC_STUB ITrnPlayListElement_Next_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE ITrnPlayListElement_EnumElements_Proxy( 
    ITrnPlayListElement __RPC_FAR * This,
    IEnumUnknown __RPC_FAR *__RPC_FAR *ppEnum);


void __RPC_STUB ITrnPlayListElement_EnumElements_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __ITrnPlayListElement_INTERFACE_DEFINED__ */


#ifndef __ITrnPlayListRamp_INTERFACE_DEFINED__
#define __ITrnPlayListRamp_INTERFACE_DEFINED__

/****************************************
 * Generated header for interface: ITrnPlayListRamp
 * at Tue Nov 23 05:28:32 1999
 * using MIDL 3.01.75
 ****************************************/
/* [unique][uuid][object][local] */ 



EXTERN_C const IID IID_ITrnPlayListRamp;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    interface DECLSPEC_UUID("8335e5e1-ab3b-11ce-8468-0000b468276b")
    ITrnPlayListRamp : public ITrnPlayListElement
    {
    public:
        virtual DWORD STDMETHODCALLTYPE GetDuration( void) = 0;
        
        virtual void STDMETHODCALLTYPE SetDuration( 
            DWORD duration) = 0;
        
        virtual DWORD STDMETHODCALLTYPE GetCurrentPosition( void) = 0;
        
        virtual void STDMETHODCALLTYPE SetCurrentPosition( 
            DWORD position) = 0;
        
        virtual long STDMETHODCALLTYPE GetCurrentValue( void) = 0;
        
        virtual void STDMETHODCALLTYPE ScaleTime( 
            double scale) = 0;
        
        virtual void STDMETHODCALLTYPE SetFromLinear( 
            double linearCoeff,
            double constCoeff,
            double scale) = 0;
        
        virtual DWORD STDMETHODCALLTYPE GetStartValue( void) = 0;
        
        virtual void STDMETHODCALLTYPE SetStartValue( 
            DWORD value) = 0;
        
        virtual long STDMETHODCALLTYPE GetFirstDifference( void) = 0;
        
        virtual void STDMETHODCALLTYPE SetFirstDifference( 
            long diff) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct ITrnPlayListRampVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            ITrnPlayListRamp __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            ITrnPlayListRamp __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            ITrnPlayListRamp __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Next )( 
            ITrnPlayListRamp __RPC_FAR * This,
            ITrnPlayListElement __RPC_FAR *__RPC_FAR *ppElt);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *EnumElements )( 
            ITrnPlayListRamp __RPC_FAR * This,
            IEnumUnknown __RPC_FAR *__RPC_FAR *ppEnum);
        
        DWORD ( STDMETHODCALLTYPE __RPC_FAR *GetDuration )( 
            ITrnPlayListRamp __RPC_FAR * This);
        
        void ( STDMETHODCALLTYPE __RPC_FAR *SetDuration )( 
            ITrnPlayListRamp __RPC_FAR * This,
            DWORD duration);
        
        DWORD ( STDMETHODCALLTYPE __RPC_FAR *GetCurrentPosition )( 
            ITrnPlayListRamp __RPC_FAR * This);
        
        void ( STDMETHODCALLTYPE __RPC_FAR *SetCurrentPosition )( 
            ITrnPlayListRamp __RPC_FAR * This,
            DWORD position);
        
        long ( STDMETHODCALLTYPE __RPC_FAR *GetCurrentValue )( 
            ITrnPlayListRamp __RPC_FAR * This);
        
        void ( STDMETHODCALLTYPE __RPC_FAR *ScaleTime )( 
            ITrnPlayListRamp __RPC_FAR * This,
            double scale);
        
        void ( STDMETHODCALLTYPE __RPC_FAR *SetFromLinear )( 
            ITrnPlayListRamp __RPC_FAR * This,
            double linearCoeff,
            double constCoeff,
            double scale);
        
        DWORD ( STDMETHODCALLTYPE __RPC_FAR *GetStartValue )( 
            ITrnPlayListRamp __RPC_FAR * This);
        
        void ( STDMETHODCALLTYPE __RPC_FAR *SetStartValue )( 
            ITrnPlayListRamp __RPC_FAR * This,
            DWORD value);
        
        long ( STDMETHODCALLTYPE __RPC_FAR *GetFirstDifference )( 
            ITrnPlayListRamp __RPC_FAR * This);
        
        void ( STDMETHODCALLTYPE __RPC_FAR *SetFirstDifference )( 
            ITrnPlayListRamp __RPC_FAR * This,
            long diff);
        
        END_INTERFACE
    } ITrnPlayListRampVtbl;

    interface ITrnPlayListRamp
    {
        CONST_VTBL struct ITrnPlayListRampVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ITrnPlayListRamp_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define ITrnPlayListRamp_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define ITrnPlayListRamp_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define ITrnPlayListRamp_Next(This,ppElt)	\
    (This)->lpVtbl -> Next(This,ppElt)

#define ITrnPlayListRamp_EnumElements(This,ppEnum)	\
    (This)->lpVtbl -> EnumElements(This,ppEnum)


#define ITrnPlayListRamp_GetDuration(This)	\
    (This)->lpVtbl -> GetDuration(This)

#define ITrnPlayListRamp_SetDuration(This,duration)	\
    (This)->lpVtbl -> SetDuration(This,duration)

#define ITrnPlayListRamp_GetCurrentPosition(This)	\
    (This)->lpVtbl -> GetCurrentPosition(This)

#define ITrnPlayListRamp_SetCurrentPosition(This,position)	\
    (This)->lpVtbl -> SetCurrentPosition(This,position)

#define ITrnPlayListRamp_GetCurrentValue(This)	\
    (This)->lpVtbl -> GetCurrentValue(This)

#define ITrnPlayListRamp_ScaleTime(This,scale)	\
    (This)->lpVtbl -> ScaleTime(This,scale)

#define ITrnPlayListRamp_SetFromLinear(This,linearCoeff,constCoeff,scale)	\
    (This)->lpVtbl -> SetFromLinear(This,linearCoeff,constCoeff,scale)

#define ITrnPlayListRamp_GetStartValue(This)	\
    (This)->lpVtbl -> GetStartValue(This)

#define ITrnPlayListRamp_SetStartValue(This,value)	\
    (This)->lpVtbl -> SetStartValue(This,value)

#define ITrnPlayListRamp_GetFirstDifference(This)	\
    (This)->lpVtbl -> GetFirstDifference(This)

#define ITrnPlayListRamp_SetFirstDifference(This,diff)	\
    (This)->lpVtbl -> SetFirstDifference(This,diff)

#endif /* COBJMACROS */


#endif 	/* C style interface */



DWORD STDMETHODCALLTYPE ITrnPlayListRamp_GetDuration_Proxy( 
    ITrnPlayListRamp __RPC_FAR * This);


void __RPC_STUB ITrnPlayListRamp_GetDuration_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


void STDMETHODCALLTYPE ITrnPlayListRamp_SetDuration_Proxy( 
    ITrnPlayListRamp __RPC_FAR * This,
    DWORD duration);


void __RPC_STUB ITrnPlayListRamp_SetDuration_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


DWORD STDMETHODCALLTYPE ITrnPlayListRamp_GetCurrentPosition_Proxy( 
    ITrnPlayListRamp __RPC_FAR * This);


void __RPC_STUB ITrnPlayListRamp_GetCurrentPosition_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


void STDMETHODCALLTYPE ITrnPlayListRamp_SetCurrentPosition_Proxy( 
    ITrnPlayListRamp __RPC_FAR * This,
    DWORD position);


void __RPC_STUB ITrnPlayListRamp_SetCurrentPosition_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


long STDMETHODCALLTYPE ITrnPlayListRamp_GetCurrentValue_Proxy( 
    ITrnPlayListRamp __RPC_FAR * This);


void __RPC_STUB ITrnPlayListRamp_GetCurrentValue_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


void STDMETHODCALLTYPE ITrnPlayListRamp_ScaleTime_Proxy( 
    ITrnPlayListRamp __RPC_FAR * This,
    double scale);


void __RPC_STUB ITrnPlayListRamp_ScaleTime_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


void STDMETHODCALLTYPE ITrnPlayListRamp_SetFromLinear_Proxy( 
    ITrnPlayListRamp __RPC_FAR * This,
    double linearCoeff,
    double constCoeff,
    double scale);


void __RPC_STUB ITrnPlayListRamp_SetFromLinear_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


DWORD STDMETHODCALLTYPE ITrnPlayListRamp_GetStartValue_Proxy( 
    ITrnPlayListRamp __RPC_FAR * This);


void __RPC_STUB ITrnPlayListRamp_GetStartValue_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


void STDMETHODCALLTYPE ITrnPlayListRamp_SetStartValue_Proxy( 
    ITrnPlayListRamp __RPC_FAR * This,
    DWORD value);


void __RPC_STUB ITrnPlayListRamp_SetStartValue_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


long STDMETHODCALLTYPE ITrnPlayListRamp_GetFirstDifference_Proxy( 
    ITrnPlayListRamp __RPC_FAR * This);


void __RPC_STUB ITrnPlayListRamp_GetFirstDifference_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


void STDMETHODCALLTYPE ITrnPlayListRamp_SetFirstDifference_Proxy( 
    ITrnPlayListRamp __RPC_FAR * This,
    long diff);


void __RPC_STUB ITrnPlayListRamp_SetFirstDifference_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __ITrnPlayListRamp_INTERFACE_DEFINED__ */


#ifndef __ITrnPlayListCubic_INTERFACE_DEFINED__
#define __ITrnPlayListCubic_INTERFACE_DEFINED__

/****************************************
 * Generated header for interface: ITrnPlayListCubic
 * at Tue Nov 23 05:28:32 1999
 * using MIDL 3.01.75
 ****************************************/
/* [unique][uuid][object][local] */ 



EXTERN_C const IID IID_ITrnPlayListCubic;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    interface DECLSPEC_UUID("8335e5e5-ab3b-11ce-8468-0000b468276b")
    ITrnPlayListCubic : public ITrnPlayListRamp
    {
    public:
        virtual long STDMETHODCALLTYPE GetCurrentFirstDifference( void) = 0;
        
        virtual long STDMETHODCALLTYPE GetSecondDifference( void) = 0;
        
        virtual void STDMETHODCALLTYPE SetSecondDifference( 
            long diff) = 0;
        
        virtual long STDMETHODCALLTYPE GetCurrentSecondDifference( void) = 0;
        
        virtual long STDMETHODCALLTYPE GetThirdDifference( void) = 0;
        
        virtual void STDMETHODCALLTYPE SetThirdDifference( void) = 0;
        
        virtual void STDMETHODCALLTYPE SetFromCubic( 
            double a,
            double b,
            double c,
            double d,
            double scale) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct ITrnPlayListCubicVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            ITrnPlayListCubic __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            ITrnPlayListCubic __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            ITrnPlayListCubic __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Next )( 
            ITrnPlayListCubic __RPC_FAR * This,
            ITrnPlayListElement __RPC_FAR *__RPC_FAR *ppElt);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *EnumElements )( 
            ITrnPlayListCubic __RPC_FAR * This,
            IEnumUnknown __RPC_FAR *__RPC_FAR *ppEnum);
        
        DWORD ( STDMETHODCALLTYPE __RPC_FAR *GetDuration )( 
            ITrnPlayListCubic __RPC_FAR * This);
        
        void ( STDMETHODCALLTYPE __RPC_FAR *SetDuration )( 
            ITrnPlayListCubic __RPC_FAR * This,
            DWORD duration);
        
        DWORD ( STDMETHODCALLTYPE __RPC_FAR *GetCurrentPosition )( 
            ITrnPlayListCubic __RPC_FAR * This);
        
        void ( STDMETHODCALLTYPE __RPC_FAR *SetCurrentPosition )( 
            ITrnPlayListCubic __RPC_FAR * This,
            DWORD position);
        
        long ( STDMETHODCALLTYPE __RPC_FAR *GetCurrentValue )( 
            ITrnPlayListCubic __RPC_FAR * This);
        
        void ( STDMETHODCALLTYPE __RPC_FAR *ScaleTime )( 
            ITrnPlayListCubic __RPC_FAR * This,
            double scale);
        
        void ( STDMETHODCALLTYPE __RPC_FAR *SetFromLinear )( 
            ITrnPlayListCubic __RPC_FAR * This,
            double linearCoeff,
            double constCoeff,
            double scale);
        
        DWORD ( STDMETHODCALLTYPE __RPC_FAR *GetStartValue )( 
            ITrnPlayListCubic __RPC_FAR * This);
        
        void ( STDMETHODCALLTYPE __RPC_FAR *SetStartValue )( 
            ITrnPlayListCubic __RPC_FAR * This,
            DWORD value);
        
        long ( STDMETHODCALLTYPE __RPC_FAR *GetFirstDifference )( 
            ITrnPlayListCubic __RPC_FAR * This);
        
        void ( STDMETHODCALLTYPE __RPC_FAR *SetFirstDifference )( 
            ITrnPlayListCubic __RPC_FAR * This,
            long diff);
        
        long ( STDMETHODCALLTYPE __RPC_FAR *GetCurrentFirstDifference )( 
            ITrnPlayListCubic __RPC_FAR * This);
        
        long ( STDMETHODCALLTYPE __RPC_FAR *GetSecondDifference )( 
            ITrnPlayListCubic __RPC_FAR * This);
        
        void ( STDMETHODCALLTYPE __RPC_FAR *SetSecondDifference )( 
            ITrnPlayListCubic __RPC_FAR * This,
            long diff);
        
        long ( STDMETHODCALLTYPE __RPC_FAR *GetCurrentSecondDifference )( 
            ITrnPlayListCubic __RPC_FAR * This);
        
        long ( STDMETHODCALLTYPE __RPC_FAR *GetThirdDifference )( 
            ITrnPlayListCubic __RPC_FAR * This);
        
        void ( STDMETHODCALLTYPE __RPC_FAR *SetThirdDifference )( 
            ITrnPlayListCubic __RPC_FAR * This);
        
        void ( STDMETHODCALLTYPE __RPC_FAR *SetFromCubic )( 
            ITrnPlayListCubic __RPC_FAR * This,
            double a,
            double b,
            double c,
            double d,
            double scale);
        
        END_INTERFACE
    } ITrnPlayListCubicVtbl;

    interface ITrnPlayListCubic
    {
        CONST_VTBL struct ITrnPlayListCubicVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ITrnPlayListCubic_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define ITrnPlayListCubic_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define ITrnPlayListCubic_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define ITrnPlayListCubic_Next(This,ppElt)	\
    (This)->lpVtbl -> Next(This,ppElt)

#define ITrnPlayListCubic_EnumElements(This,ppEnum)	\
    (This)->lpVtbl -> EnumElements(This,ppEnum)


#define ITrnPlayListCubic_GetDuration(This)	\
    (This)->lpVtbl -> GetDuration(This)

#define ITrnPlayListCubic_SetDuration(This,duration)	\
    (This)->lpVtbl -> SetDuration(This,duration)

#define ITrnPlayListCubic_GetCurrentPosition(This)	\
    (This)->lpVtbl -> GetCurrentPosition(This)

#define ITrnPlayListCubic_SetCurrentPosition(This,position)	\
    (This)->lpVtbl -> SetCurrentPosition(This,position)

#define ITrnPlayListCubic_GetCurrentValue(This)	\
    (This)->lpVtbl -> GetCurrentValue(This)

#define ITrnPlayListCubic_ScaleTime(This,scale)	\
    (This)->lpVtbl -> ScaleTime(This,scale)

#define ITrnPlayListCubic_SetFromLinear(This,linearCoeff,constCoeff,scale)	\
    (This)->lpVtbl -> SetFromLinear(This,linearCoeff,constCoeff,scale)

#define ITrnPlayListCubic_GetStartValue(This)	\
    (This)->lpVtbl -> GetStartValue(This)

#define ITrnPlayListCubic_SetStartValue(This,value)	\
    (This)->lpVtbl -> SetStartValue(This,value)

#define ITrnPlayListCubic_GetFirstDifference(This)	\
    (This)->lpVtbl -> GetFirstDifference(This)

#define ITrnPlayListCubic_SetFirstDifference(This,diff)	\
    (This)->lpVtbl -> SetFirstDifference(This,diff)


#define ITrnPlayListCubic_GetCurrentFirstDifference(This)	\
    (This)->lpVtbl -> GetCurrentFirstDifference(This)

#define ITrnPlayListCubic_GetSecondDifference(This)	\
    (This)->lpVtbl -> GetSecondDifference(This)

#define ITrnPlayListCubic_SetSecondDifference(This,diff)	\
    (This)->lpVtbl -> SetSecondDifference(This,diff)

#define ITrnPlayListCubic_GetCurrentSecondDifference(This)	\
    (This)->lpVtbl -> GetCurrentSecondDifference(This)

#define ITrnPlayListCubic_GetThirdDifference(This)	\
    (This)->lpVtbl -> GetThirdDifference(This)

#define ITrnPlayListCubic_SetThirdDifference(This)	\
    (This)->lpVtbl -> SetThirdDifference(This)

#define ITrnPlayListCubic_SetFromCubic(This,a,b,c,d,scale)	\
    (This)->lpVtbl -> SetFromCubic(This,a,b,c,d,scale)

#endif /* COBJMACROS */


#endif 	/* C style interface */



long STDMETHODCALLTYPE ITrnPlayListCubic_GetCurrentFirstDifference_Proxy( 
    ITrnPlayListCubic __RPC_FAR * This);


void __RPC_STUB ITrnPlayListCubic_GetCurrentFirstDifference_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


long STDMETHODCALLTYPE ITrnPlayListCubic_GetSecondDifference_Proxy( 
    ITrnPlayListCubic __RPC_FAR * This);


void __RPC_STUB ITrnPlayListCubic_GetSecondDifference_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


void STDMETHODCALLTYPE ITrnPlayListCubic_SetSecondDifference_Proxy( 
    ITrnPlayListCubic __RPC_FAR * This,
    long diff);


void __RPC_STUB ITrnPlayListCubic_SetSecondDifference_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


long STDMETHODCALLTYPE ITrnPlayListCubic_GetCurrentSecondDifference_Proxy( 
    ITrnPlayListCubic __RPC_FAR * This);


void __RPC_STUB ITrnPlayListCubic_GetCurrentSecondDifference_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


long STDMETHODCALLTYPE ITrnPlayListCubic_GetThirdDifference_Proxy( 
    ITrnPlayListCubic __RPC_FAR * This);


void __RPC_STUB ITrnPlayListCubic_GetThirdDifference_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


void STDMETHODCALLTYPE ITrnPlayListCubic_SetThirdDifference_Proxy( 
    ITrnPlayListCubic __RPC_FAR * This);


void __RPC_STUB ITrnPlayListCubic_SetThirdDifference_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


void STDMETHODCALLTYPE ITrnPlayListCubic_SetFromCubic_Proxy( 
    ITrnPlayListCubic __RPC_FAR * This,
    double a,
    double b,
    double c,
    double d,
    double scale);


void __RPC_STUB ITrnPlayListCubic_SetFromCubic_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __ITrnPlayListCubic_INTERFACE_DEFINED__ */


#ifndef __ITrnPlayListIterator_INTERFACE_DEFINED__
#define __ITrnPlayListIterator_INTERFACE_DEFINED__

/****************************************
 * Generated header for interface: ITrnPlayListIterator
 * at Tue Nov 23 05:28:32 1999
 * using MIDL 3.01.75
 ****************************************/
/* [unique][uuid][object][local] */ 



EXTERN_C const IID IID_ITrnPlayListIterator;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    interface DECLSPEC_UUID("8335e5e2-ab3b-11ce-8468-0000b468276b")
    ITrnPlayListIterator : public ITrnPlayListElement
    {
    public:
        virtual DWORD STDMETHODCALLTYPE GetMaxCount( void) = 0;
        
        virtual void STDMETHODCALLTYPE SetMaxCount( 
            DWORD duration) = 0;
        
        virtual DWORD STDMETHODCALLTYPE GetCurrentCount( void) = 0;
        
        virtual void STDMETHODCALLTYPE SetCurrentCount( 
            DWORD count) = 0;
        
        virtual DWORD STDMETHODCALLTYPE GetExitEvent( void) = 0;
        
        virtual void STDMETHODCALLTYPE SetExitEvent( 
            DWORD event) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct ITrnPlayListIteratorVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            ITrnPlayListIterator __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            ITrnPlayListIterator __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            ITrnPlayListIterator __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Next )( 
            ITrnPlayListIterator __RPC_FAR * This,
            ITrnPlayListElement __RPC_FAR *__RPC_FAR *ppElt);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *EnumElements )( 
            ITrnPlayListIterator __RPC_FAR * This,
            IEnumUnknown __RPC_FAR *__RPC_FAR *ppEnum);
        
        DWORD ( STDMETHODCALLTYPE __RPC_FAR *GetMaxCount )( 
            ITrnPlayListIterator __RPC_FAR * This);
        
        void ( STDMETHODCALLTYPE __RPC_FAR *SetMaxCount )( 
            ITrnPlayListIterator __RPC_FAR * This,
            DWORD duration);
        
        DWORD ( STDMETHODCALLTYPE __RPC_FAR *GetCurrentCount )( 
            ITrnPlayListIterator __RPC_FAR * This);
        
        void ( STDMETHODCALLTYPE __RPC_FAR *SetCurrentCount )( 
            ITrnPlayListIterator __RPC_FAR * This,
            DWORD count);
        
        DWORD ( STDMETHODCALLTYPE __RPC_FAR *GetExitEvent )( 
            ITrnPlayListIterator __RPC_FAR * This);
        
        void ( STDMETHODCALLTYPE __RPC_FAR *SetExitEvent )( 
            ITrnPlayListIterator __RPC_FAR * This,
            DWORD event);
        
        END_INTERFACE
    } ITrnPlayListIteratorVtbl;

    interface ITrnPlayListIterator
    {
        CONST_VTBL struct ITrnPlayListIteratorVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ITrnPlayListIterator_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define ITrnPlayListIterator_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define ITrnPlayListIterator_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define ITrnPlayListIterator_Next(This,ppElt)	\
    (This)->lpVtbl -> Next(This,ppElt)

#define ITrnPlayListIterator_EnumElements(This,ppEnum)	\
    (This)->lpVtbl -> EnumElements(This,ppEnum)


#define ITrnPlayListIterator_GetMaxCount(This)	\
    (This)->lpVtbl -> GetMaxCount(This)

#define ITrnPlayListIterator_SetMaxCount(This,duration)	\
    (This)->lpVtbl -> SetMaxCount(This,duration)

#define ITrnPlayListIterator_GetCurrentCount(This)	\
    (This)->lpVtbl -> GetCurrentCount(This)

#define ITrnPlayListIterator_SetCurrentCount(This,count)	\
    (This)->lpVtbl -> SetCurrentCount(This,count)

#define ITrnPlayListIterator_GetExitEvent(This)	\
    (This)->lpVtbl -> GetExitEvent(This)

#define ITrnPlayListIterator_SetExitEvent(This,event)	\
    (This)->lpVtbl -> SetExitEvent(This,event)

#endif /* COBJMACROS */


#endif 	/* C style interface */



DWORD STDMETHODCALLTYPE ITrnPlayListIterator_GetMaxCount_Proxy( 
    ITrnPlayListIterator __RPC_FAR * This);


void __RPC_STUB ITrnPlayListIterator_GetMaxCount_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


void STDMETHODCALLTYPE ITrnPlayListIterator_SetMaxCount_Proxy( 
    ITrnPlayListIterator __RPC_FAR * This,
    DWORD duration);


void __RPC_STUB ITrnPlayListIterator_SetMaxCount_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


DWORD STDMETHODCALLTYPE ITrnPlayListIterator_GetCurrentCount_Proxy( 
    ITrnPlayListIterator __RPC_FAR * This);


void __RPC_STUB ITrnPlayListIterator_GetCurrentCount_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


void STDMETHODCALLTYPE ITrnPlayListIterator_SetCurrentCount_Proxy( 
    ITrnPlayListIterator __RPC_FAR * This,
    DWORD count);


void __RPC_STUB ITrnPlayListIterator_SetCurrentCount_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


DWORD STDMETHODCALLTYPE ITrnPlayListIterator_GetExitEvent_Proxy( 
    ITrnPlayListIterator __RPC_FAR * This);


void __RPC_STUB ITrnPlayListIterator_GetExitEvent_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


void STDMETHODCALLTYPE ITrnPlayListIterator_SetExitEvent_Proxy( 
    ITrnPlayListIterator __RPC_FAR * This,
    DWORD event);


void __RPC_STUB ITrnPlayListIterator_SetExitEvent_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __ITrnPlayListIterator_INTERFACE_DEFINED__ */


#ifndef __ITrnPlayListLoop_INTERFACE_DEFINED__
#define __ITrnPlayListLoop_INTERFACE_DEFINED__

/****************************************
 * Generated header for interface: ITrnPlayListLoop
 * at Tue Nov 23 05:28:32 1999
 * using MIDL 3.01.75
 ****************************************/
/* [unique][uuid][object][local] */ 



EXTERN_C const IID IID_ITrnPlayListLoop;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    interface DECLSPEC_UUID("8335e5e3-ab3b-11ce-8468-0000b468276b")
    ITrnPlayListLoop : public ITrnPlayListElement
    {
    public:
        virtual DWORD STDMETHODCALLTYPE GetExitEvent( void) = 0;
        
        virtual void STDMETHODCALLTYPE SetExitEvent( 
            DWORD event) = 0;
        
        virtual BOOL STDMETHODCALLTYPE GetTriggeredFlag( void) = 0;
        
        virtual void STDMETHODCALLTYPE SetTriggeredFlag( 
            BOOL triggered) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct ITrnPlayListLoopVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            ITrnPlayListLoop __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            ITrnPlayListLoop __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            ITrnPlayListLoop __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Next )( 
            ITrnPlayListLoop __RPC_FAR * This,
            ITrnPlayListElement __RPC_FAR *__RPC_FAR *ppElt);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *EnumElements )( 
            ITrnPlayListLoop __RPC_FAR * This,
            IEnumUnknown __RPC_FAR *__RPC_FAR *ppEnum);
        
        DWORD ( STDMETHODCALLTYPE __RPC_FAR *GetExitEvent )( 
            ITrnPlayListLoop __RPC_FAR * This);
        
        void ( STDMETHODCALLTYPE __RPC_FAR *SetExitEvent )( 
            ITrnPlayListLoop __RPC_FAR * This,
            DWORD event);
        
        BOOL ( STDMETHODCALLTYPE __RPC_FAR *GetTriggeredFlag )( 
            ITrnPlayListLoop __RPC_FAR * This);
        
        void ( STDMETHODCALLTYPE __RPC_FAR *SetTriggeredFlag )( 
            ITrnPlayListLoop __RPC_FAR * This,
            BOOL triggered);
        
        END_INTERFACE
    } ITrnPlayListLoopVtbl;

    interface ITrnPlayListLoop
    {
        CONST_VTBL struct ITrnPlayListLoopVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ITrnPlayListLoop_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define ITrnPlayListLoop_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define ITrnPlayListLoop_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define ITrnPlayListLoop_Next(This,ppElt)	\
    (This)->lpVtbl -> Next(This,ppElt)

#define ITrnPlayListLoop_EnumElements(This,ppEnum)	\
    (This)->lpVtbl -> EnumElements(This,ppEnum)


#define ITrnPlayListLoop_GetExitEvent(This)	\
    (This)->lpVtbl -> GetExitEvent(This)

#define ITrnPlayListLoop_SetExitEvent(This,event)	\
    (This)->lpVtbl -> SetExitEvent(This,event)

#define ITrnPlayListLoop_GetTriggeredFlag(This)	\
    (This)->lpVtbl -> GetTriggeredFlag(This)

#define ITrnPlayListLoop_SetTriggeredFlag(This,triggered)	\
    (This)->lpVtbl -> SetTriggeredFlag(This,triggered)

#endif /* COBJMACROS */


#endif 	/* C style interface */



DWORD STDMETHODCALLTYPE ITrnPlayListLoop_GetExitEvent_Proxy( 
    ITrnPlayListLoop __RPC_FAR * This);


void __RPC_STUB ITrnPlayListLoop_GetExitEvent_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


void STDMETHODCALLTYPE ITrnPlayListLoop_SetExitEvent_Proxy( 
    ITrnPlayListLoop __RPC_FAR * This,
    DWORD event);


void __RPC_STUB ITrnPlayListLoop_SetExitEvent_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


BOOL STDMETHODCALLTYPE ITrnPlayListLoop_GetTriggeredFlag_Proxy( 
    ITrnPlayListLoop __RPC_FAR * This);


void __RPC_STUB ITrnPlayListLoop_GetTriggeredFlag_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


void STDMETHODCALLTYPE ITrnPlayListLoop_SetTriggeredFlag_Proxy( 
    ITrnPlayListLoop __RPC_FAR * This,
    BOOL triggered);


void __RPC_STUB ITrnPlayListLoop_SetTriggeredFlag_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __ITrnPlayListLoop_INTERFACE_DEFINED__ */


#ifndef __ITrnPlayListConditional_INTERFACE_DEFINED__
#define __ITrnPlayListConditional_INTERFACE_DEFINED__

/****************************************
 * Generated header for interface: ITrnPlayListConditional
 * at Tue Nov 23 05:28:32 1999
 * using MIDL 3.01.75
 ****************************************/
/* [unique][uuid][object][local] */ 



EXTERN_C const IID IID_ITrnPlayListConditional;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    interface DECLSPEC_UUID("8335e5e4-ab3b-11ce-8468-0000b468276b")
    ITrnPlayListConditional : public ITrnPlayListElement
    {
    public:
        virtual DWORD STDMETHODCALLTYPE GetEnableEvent( void) = 0;
        
        virtual void STDMETHODCALLTYPE SetEnableEvent( 
            DWORD event) = 0;
        
        virtual DWORD STDMETHODCALLTYPE GetDisableEvent( void) = 0;
        
        virtual void STDMETHODCALLTYPE SetDisableEvent( 
            DWORD event) = 0;
        
        virtual BOOL STDMETHODCALLTYPE GetInitialState( void) = 0;
        
        virtual void STDMETHODCALLTYPE SetInitialState( 
            BOOL initial) = 0;
        
        virtual BOOL STDMETHODCALLTYPE GetEnabled( void) = 0;
        
        virtual void STDMETHODCALLTYPE SetEnabled( 
            BOOL enabled) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct ITrnPlayListConditionalVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            ITrnPlayListConditional __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            ITrnPlayListConditional __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            ITrnPlayListConditional __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Next )( 
            ITrnPlayListConditional __RPC_FAR * This,
            ITrnPlayListElement __RPC_FAR *__RPC_FAR *ppElt);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *EnumElements )( 
            ITrnPlayListConditional __RPC_FAR * This,
            IEnumUnknown __RPC_FAR *__RPC_FAR *ppEnum);
        
        DWORD ( STDMETHODCALLTYPE __RPC_FAR *GetEnableEvent )( 
            ITrnPlayListConditional __RPC_FAR * This);
        
        void ( STDMETHODCALLTYPE __RPC_FAR *SetEnableEvent )( 
            ITrnPlayListConditional __RPC_FAR * This,
            DWORD event);
        
        DWORD ( STDMETHODCALLTYPE __RPC_FAR *GetDisableEvent )( 
            ITrnPlayListConditional __RPC_FAR * This);
        
        void ( STDMETHODCALLTYPE __RPC_FAR *SetDisableEvent )( 
            ITrnPlayListConditional __RPC_FAR * This,
            DWORD event);
        
        BOOL ( STDMETHODCALLTYPE __RPC_FAR *GetInitialState )( 
            ITrnPlayListConditional __RPC_FAR * This);
        
        void ( STDMETHODCALLTYPE __RPC_FAR *SetInitialState )( 
            ITrnPlayListConditional __RPC_FAR * This,
            BOOL initial);
        
        BOOL ( STDMETHODCALLTYPE __RPC_FAR *GetEnabled )( 
            ITrnPlayListConditional __RPC_FAR * This);
        
        void ( STDMETHODCALLTYPE __RPC_FAR *SetEnabled )( 
            ITrnPlayListConditional __RPC_FAR * This,
            BOOL enabled);
        
        END_INTERFACE
    } ITrnPlayListConditionalVtbl;

    interface ITrnPlayListConditional
    {
        CONST_VTBL struct ITrnPlayListConditionalVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ITrnPlayListConditional_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define ITrnPlayListConditional_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define ITrnPlayListConditional_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define ITrnPlayListConditional_Next(This,ppElt)	\
    (This)->lpVtbl -> Next(This,ppElt)

#define ITrnPlayListConditional_EnumElements(This,ppEnum)	\
    (This)->lpVtbl -> EnumElements(This,ppEnum)


#define ITrnPlayListConditional_GetEnableEvent(This)	\
    (This)->lpVtbl -> GetEnableEvent(This)

#define ITrnPlayListConditional_SetEnableEvent(This,event)	\
    (This)->lpVtbl -> SetEnableEvent(This,event)

#define ITrnPlayListConditional_GetDisableEvent(This)	\
    (This)->lpVtbl -> GetDisableEvent(This)

#define ITrnPlayListConditional_SetDisableEvent(This,event)	\
    (This)->lpVtbl -> SetDisableEvent(This,event)

#define ITrnPlayListConditional_GetInitialState(This)	\
    (This)->lpVtbl -> GetInitialState(This)

#define ITrnPlayListConditional_SetInitialState(This,initial)	\
    (This)->lpVtbl -> SetInitialState(This,initial)

#define ITrnPlayListConditional_GetEnabled(This)	\
    (This)->lpVtbl -> GetEnabled(This)

#define ITrnPlayListConditional_SetEnabled(This,enabled)	\
    (This)->lpVtbl -> SetEnabled(This,enabled)

#endif /* COBJMACROS */


#endif 	/* C style interface */



DWORD STDMETHODCALLTYPE ITrnPlayListConditional_GetEnableEvent_Proxy( 
    ITrnPlayListConditional __RPC_FAR * This);


void __RPC_STUB ITrnPlayListConditional_GetEnableEvent_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


void STDMETHODCALLTYPE ITrnPlayListConditional_SetEnableEvent_Proxy( 
    ITrnPlayListConditional __RPC_FAR * This,
    DWORD event);


void __RPC_STUB ITrnPlayListConditional_SetEnableEvent_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


DWORD STDMETHODCALLTYPE ITrnPlayListConditional_GetDisableEvent_Proxy( 
    ITrnPlayListConditional __RPC_FAR * This);


void __RPC_STUB ITrnPlayListConditional_GetDisableEvent_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


void STDMETHODCALLTYPE ITrnPlayListConditional_SetDisableEvent_Proxy( 
    ITrnPlayListConditional __RPC_FAR * This,
    DWORD event);


void __RPC_STUB ITrnPlayListConditional_SetDisableEvent_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


BOOL STDMETHODCALLTYPE ITrnPlayListConditional_GetInitialState_Proxy( 
    ITrnPlayListConditional __RPC_FAR * This);


void __RPC_STUB ITrnPlayListConditional_GetInitialState_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


void STDMETHODCALLTYPE ITrnPlayListConditional_SetInitialState_Proxy( 
    ITrnPlayListConditional __RPC_FAR * This,
    BOOL initial);


void __RPC_STUB ITrnPlayListConditional_SetInitialState_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


BOOL STDMETHODCALLTYPE ITrnPlayListConditional_GetEnabled_Proxy( 
    ITrnPlayListConditional __RPC_FAR * This);


void __RPC_STUB ITrnPlayListConditional_GetEnabled_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


void STDMETHODCALLTYPE ITrnPlayListConditional_SetEnabled_Proxy( 
    ITrnPlayListConditional __RPC_FAR * This,
    BOOL enabled);


void __RPC_STUB ITrnPlayListConditional_SetEnabled_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __ITrnPlayListConditional_INTERFACE_DEFINED__ */


/* Additional Prototypes for ALL interfaces */

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif
