/* this ALWAYS GENERATED file contains the definitions for the interfaces */


/* File created by MIDL compiler version 3.01.75 */
/* at Tue Nov 23 05:02:09 1999
 */
/* Compiler settings for panel.idl:
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

#ifndef __panel_h__
#define __panel_h__

#ifdef __cplusplus
extern "C"{
#endif 

/* Forward Declarations */ 

#ifndef __IPlayPanel_FWD_DEFINED__
#define __IPlayPanel_FWD_DEFINED__
typedef interface IPlayPanel IPlayPanel;
#endif 	/* __IPlayPanel_FWD_DEFINED__ */


#ifndef __IPlayPanel2_FWD_DEFINED__
#define __IPlayPanel2_FWD_DEFINED__
typedef interface IPlayPanel2 IPlayPanel2;
#endif 	/* __IPlayPanel2_FWD_DEFINED__ */


#ifndef __IPlayPagedPanelAdviseSink_FWD_DEFINED__
#define __IPlayPagedPanelAdviseSink_FWD_DEFINED__
typedef interface IPlayPagedPanelAdviseSink IPlayPagedPanelAdviseSink;
#endif 	/* __IPlayPagedPanelAdviseSink_FWD_DEFINED__ */


#ifndef __IPlayPagedPanel_FWD_DEFINED__
#define __IPlayPagedPanel_FWD_DEFINED__
typedef interface IPlayPagedPanel IPlayPagedPanel;
#endif 	/* __IPlayPagedPanel_FWD_DEFINED__ */


#ifndef __IPlayPagedPanel2_FWD_DEFINED__
#define __IPlayPagedPanel2_FWD_DEFINED__
typedef interface IPlayPagedPanel2 IPlayPagedPanel2;
#endif 	/* __IPlayPagedPanel2_FWD_DEFINED__ */


#ifndef __IPlayColorPanel_FWD_DEFINED__
#define __IPlayColorPanel_FWD_DEFINED__
typedef interface IPlayColorPanel IPlayColorPanel;
#endif 	/* __IPlayColorPanel_FWD_DEFINED__ */


/* header files for imported files */
#include "unknwn.h"
#include "plyctl.h"
#include "psttab.h"

void __RPC_FAR * __RPC_USER MIDL_user_allocate(size_t);
void __RPC_USER MIDL_user_free( void __RPC_FAR * ); 

#ifndef __IPlayPanel_INTERFACE_DEFINED__
#define __IPlayPanel_INTERFACE_DEFINED__

/****************************************
 * Generated header for interface: IPlayPanel
 * at Tue Nov 23 05:02:09 1999
 * using MIDL 3.01.75
 ****************************************/
/* [uuid][object][local] */ 



EXTERN_C const IID IID_IPlayPanel;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    interface DECLSPEC_UUID("8335e423-ab3b-11ce-8468-0000b468276b")
    IPlayPanel : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE AddControl( 
            IPlayControl __RPC_FAR *pipc,
            DWORD dwPlacement) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE PutInWindow( 
            HWND hWnd,
            /* [string] */ unsigned char __RPC_FAR *pszPanelSaveFilename) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Reset( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetAttr( 
            DWORD dwAttr,
            DWORD dwSubAttr,
            DWORD dwValue) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetAttr( 
            DWORD dwAttr,
            DWORD dwSubAttr,
            DWORD __RPC_FAR *pValue) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE ShowProperties( 
            IPlayControl __RPC_FAR *pipc,
            HWND hWndParent,
            LPARAM lParam) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Close( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE DrawToDIB( 
            LPVOID pBMIH,
            BYTE __RPC_FAR *pBits,
            RECT __RPC_FAR *pUpdRect,
            POINT __RPC_FAR *pUpdOfs) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE ShowAndHide( 
            IPlayControl __RPC_FAR *__RPC_FAR *ppShowList,
            ULONG nNumShow,
            IPlayControl __RPC_FAR *__RPC_FAR *ppHideList,
            ULONG nNumHide) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetStringTable( 
            /* [out] */ IPlayStringTable __RPC_FAR *__RPC_FAR *ppStringTable) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetName( 
            /* [string] */ unsigned char __RPC_FAR *panelName) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IPlayPanelVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            IPlayPanel __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            IPlayPanel __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            IPlayPanel __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *AddControl )( 
            IPlayPanel __RPC_FAR * This,
            IPlayControl __RPC_FAR *pipc,
            DWORD dwPlacement);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *PutInWindow )( 
            IPlayPanel __RPC_FAR * This,
            HWND hWnd,
            /* [string] */ unsigned char __RPC_FAR *pszPanelSaveFilename);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Reset )( 
            IPlayPanel __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetAttr )( 
            IPlayPanel __RPC_FAR * This,
            DWORD dwAttr,
            DWORD dwSubAttr,
            DWORD dwValue);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetAttr )( 
            IPlayPanel __RPC_FAR * This,
            DWORD dwAttr,
            DWORD dwSubAttr,
            DWORD __RPC_FAR *pValue);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *ShowProperties )( 
            IPlayPanel __RPC_FAR * This,
            IPlayControl __RPC_FAR *pipc,
            HWND hWndParent,
            LPARAM lParam);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Close )( 
            IPlayPanel __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *DrawToDIB )( 
            IPlayPanel __RPC_FAR * This,
            LPVOID pBMIH,
            BYTE __RPC_FAR *pBits,
            RECT __RPC_FAR *pUpdRect,
            POINT __RPC_FAR *pUpdOfs);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *ShowAndHide )( 
            IPlayPanel __RPC_FAR * This,
            IPlayControl __RPC_FAR *__RPC_FAR *ppShowList,
            ULONG nNumShow,
            IPlayControl __RPC_FAR *__RPC_FAR *ppHideList,
            ULONG nNumHide);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetStringTable )( 
            IPlayPanel __RPC_FAR * This,
            /* [out] */ IPlayStringTable __RPC_FAR *__RPC_FAR *ppStringTable);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetName )( 
            IPlayPanel __RPC_FAR * This,
            /* [string] */ unsigned char __RPC_FAR *panelName);
        
        END_INTERFACE
    } IPlayPanelVtbl;

    interface IPlayPanel
    {
        CONST_VTBL struct IPlayPanelVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IPlayPanel_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IPlayPanel_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IPlayPanel_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IPlayPanel_AddControl(This,pipc,dwPlacement)	\
    (This)->lpVtbl -> AddControl(This,pipc,dwPlacement)

#define IPlayPanel_PutInWindow(This,hWnd,pszPanelSaveFilename)	\
    (This)->lpVtbl -> PutInWindow(This,hWnd,pszPanelSaveFilename)

#define IPlayPanel_Reset(This)	\
    (This)->lpVtbl -> Reset(This)

#define IPlayPanel_SetAttr(This,dwAttr,dwSubAttr,dwValue)	\
    (This)->lpVtbl -> SetAttr(This,dwAttr,dwSubAttr,dwValue)

#define IPlayPanel_GetAttr(This,dwAttr,dwSubAttr,pValue)	\
    (This)->lpVtbl -> GetAttr(This,dwAttr,dwSubAttr,pValue)

#define IPlayPanel_ShowProperties(This,pipc,hWndParent,lParam)	\
    (This)->lpVtbl -> ShowProperties(This,pipc,hWndParent,lParam)

#define IPlayPanel_Close(This)	\
    (This)->lpVtbl -> Close(This)

#define IPlayPanel_DrawToDIB(This,pBMIH,pBits,pUpdRect,pUpdOfs)	\
    (This)->lpVtbl -> DrawToDIB(This,pBMIH,pBits,pUpdRect,pUpdOfs)

#define IPlayPanel_ShowAndHide(This,ppShowList,nNumShow,ppHideList,nNumHide)	\
    (This)->lpVtbl -> ShowAndHide(This,ppShowList,nNumShow,ppHideList,nNumHide)

#define IPlayPanel_GetStringTable(This,ppStringTable)	\
    (This)->lpVtbl -> GetStringTable(This,ppStringTable)

#define IPlayPanel_SetName(This,panelName)	\
    (This)->lpVtbl -> SetName(This,panelName)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE IPlayPanel_AddControl_Proxy( 
    IPlayPanel __RPC_FAR * This,
    IPlayControl __RPC_FAR *pipc,
    DWORD dwPlacement);


void __RPC_STUB IPlayPanel_AddControl_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IPlayPanel_PutInWindow_Proxy( 
    IPlayPanel __RPC_FAR * This,
    HWND hWnd,
    /* [string] */ unsigned char __RPC_FAR *pszPanelSaveFilename);


void __RPC_STUB IPlayPanel_PutInWindow_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IPlayPanel_Reset_Proxy( 
    IPlayPanel __RPC_FAR * This);


void __RPC_STUB IPlayPanel_Reset_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IPlayPanel_SetAttr_Proxy( 
    IPlayPanel __RPC_FAR * This,
    DWORD dwAttr,
    DWORD dwSubAttr,
    DWORD dwValue);


void __RPC_STUB IPlayPanel_SetAttr_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IPlayPanel_GetAttr_Proxy( 
    IPlayPanel __RPC_FAR * This,
    DWORD dwAttr,
    DWORD dwSubAttr,
    DWORD __RPC_FAR *pValue);


void __RPC_STUB IPlayPanel_GetAttr_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IPlayPanel_ShowProperties_Proxy( 
    IPlayPanel __RPC_FAR * This,
    IPlayControl __RPC_FAR *pipc,
    HWND hWndParent,
    LPARAM lParam);


void __RPC_STUB IPlayPanel_ShowProperties_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IPlayPanel_Close_Proxy( 
    IPlayPanel __RPC_FAR * This);


void __RPC_STUB IPlayPanel_Close_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IPlayPanel_DrawToDIB_Proxy( 
    IPlayPanel __RPC_FAR * This,
    LPVOID pBMIH,
    BYTE __RPC_FAR *pBits,
    RECT __RPC_FAR *pUpdRect,
    POINT __RPC_FAR *pUpdOfs);


void __RPC_STUB IPlayPanel_DrawToDIB_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IPlayPanel_ShowAndHide_Proxy( 
    IPlayPanel __RPC_FAR * This,
    IPlayControl __RPC_FAR *__RPC_FAR *ppShowList,
    ULONG nNumShow,
    IPlayControl __RPC_FAR *__RPC_FAR *ppHideList,
    ULONG nNumHide);


void __RPC_STUB IPlayPanel_ShowAndHide_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IPlayPanel_GetStringTable_Proxy( 
    IPlayPanel __RPC_FAR * This,
    /* [out] */ IPlayStringTable __RPC_FAR *__RPC_FAR *ppStringTable);


void __RPC_STUB IPlayPanel_GetStringTable_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IPlayPanel_SetName_Proxy( 
    IPlayPanel __RPC_FAR * This,
    /* [string] */ unsigned char __RPC_FAR *panelName);


void __RPC_STUB IPlayPanel_SetName_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IPlayPanel_INTERFACE_DEFINED__ */


#ifndef __IPlayPanel2_INTERFACE_DEFINED__
#define __IPlayPanel2_INTERFACE_DEFINED__

/****************************************
 * Generated header for interface: IPlayPanel2
 * at Tue Nov 23 05:02:09 1999
 * using MIDL 3.01.75
 ****************************************/
/* [uuid][object][local] */ 



EXTERN_C const IID IID_IPlayPanel2;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    interface DECLSPEC_UUID("8335e607-ab3b-11ce-8468-0000b468276b")
    IPlayPanel2 : public IPlayPanel
    {
    public:
        virtual void STDMETHODCALLTYPE SetExcitedControl( 
            /* [in] */ IPlayControl __RPC_FAR *pControl) = 0;
        
        virtual IPlayControl __RPC_FAR *STDMETHODCALLTYPE FindControl( 
            DWORD dwUserDWORD) = 0;
        
        virtual IPlayControl __RPC_FAR *STDMETHODCALLTYPE FindControlID( 
            DWORD dwUserID) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetBackgroundBitmap( 
            IGXIntBitmap __RPC_FAR *pBitmap) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IPlayPanel2Vtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            IPlayPanel2 __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            IPlayPanel2 __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            IPlayPanel2 __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *AddControl )( 
            IPlayPanel2 __RPC_FAR * This,
            IPlayControl __RPC_FAR *pipc,
            DWORD dwPlacement);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *PutInWindow )( 
            IPlayPanel2 __RPC_FAR * This,
            HWND hWnd,
            /* [string] */ unsigned char __RPC_FAR *pszPanelSaveFilename);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Reset )( 
            IPlayPanel2 __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetAttr )( 
            IPlayPanel2 __RPC_FAR * This,
            DWORD dwAttr,
            DWORD dwSubAttr,
            DWORD dwValue);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetAttr )( 
            IPlayPanel2 __RPC_FAR * This,
            DWORD dwAttr,
            DWORD dwSubAttr,
            DWORD __RPC_FAR *pValue);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *ShowProperties )( 
            IPlayPanel2 __RPC_FAR * This,
            IPlayControl __RPC_FAR *pipc,
            HWND hWndParent,
            LPARAM lParam);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Close )( 
            IPlayPanel2 __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *DrawToDIB )( 
            IPlayPanel2 __RPC_FAR * This,
            LPVOID pBMIH,
            BYTE __RPC_FAR *pBits,
            RECT __RPC_FAR *pUpdRect,
            POINT __RPC_FAR *pUpdOfs);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *ShowAndHide )( 
            IPlayPanel2 __RPC_FAR * This,
            IPlayControl __RPC_FAR *__RPC_FAR *ppShowList,
            ULONG nNumShow,
            IPlayControl __RPC_FAR *__RPC_FAR *ppHideList,
            ULONG nNumHide);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetStringTable )( 
            IPlayPanel2 __RPC_FAR * This,
            /* [out] */ IPlayStringTable __RPC_FAR *__RPC_FAR *ppStringTable);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetName )( 
            IPlayPanel2 __RPC_FAR * This,
            /* [string] */ unsigned char __RPC_FAR *panelName);
        
        void ( STDMETHODCALLTYPE __RPC_FAR *SetExcitedControl )( 
            IPlayPanel2 __RPC_FAR * This,
            /* [in] */ IPlayControl __RPC_FAR *pControl);
        
        IPlayControl __RPC_FAR *( STDMETHODCALLTYPE __RPC_FAR *FindControl )( 
            IPlayPanel2 __RPC_FAR * This,
            DWORD dwUserDWORD);
        
        IPlayControl __RPC_FAR *( STDMETHODCALLTYPE __RPC_FAR *FindControlID )( 
            IPlayPanel2 __RPC_FAR * This,
            DWORD dwUserID);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetBackgroundBitmap )( 
            IPlayPanel2 __RPC_FAR * This,
            IGXIntBitmap __RPC_FAR *pBitmap);
        
        END_INTERFACE
    } IPlayPanel2Vtbl;

    interface IPlayPanel2
    {
        CONST_VTBL struct IPlayPanel2Vtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IPlayPanel2_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IPlayPanel2_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IPlayPanel2_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IPlayPanel2_AddControl(This,pipc,dwPlacement)	\
    (This)->lpVtbl -> AddControl(This,pipc,dwPlacement)

#define IPlayPanel2_PutInWindow(This,hWnd,pszPanelSaveFilename)	\
    (This)->lpVtbl -> PutInWindow(This,hWnd,pszPanelSaveFilename)

#define IPlayPanel2_Reset(This)	\
    (This)->lpVtbl -> Reset(This)

#define IPlayPanel2_SetAttr(This,dwAttr,dwSubAttr,dwValue)	\
    (This)->lpVtbl -> SetAttr(This,dwAttr,dwSubAttr,dwValue)

#define IPlayPanel2_GetAttr(This,dwAttr,dwSubAttr,pValue)	\
    (This)->lpVtbl -> GetAttr(This,dwAttr,dwSubAttr,pValue)

#define IPlayPanel2_ShowProperties(This,pipc,hWndParent,lParam)	\
    (This)->lpVtbl -> ShowProperties(This,pipc,hWndParent,lParam)

#define IPlayPanel2_Close(This)	\
    (This)->lpVtbl -> Close(This)

#define IPlayPanel2_DrawToDIB(This,pBMIH,pBits,pUpdRect,pUpdOfs)	\
    (This)->lpVtbl -> DrawToDIB(This,pBMIH,pBits,pUpdRect,pUpdOfs)

#define IPlayPanel2_ShowAndHide(This,ppShowList,nNumShow,ppHideList,nNumHide)	\
    (This)->lpVtbl -> ShowAndHide(This,ppShowList,nNumShow,ppHideList,nNumHide)

#define IPlayPanel2_GetStringTable(This,ppStringTable)	\
    (This)->lpVtbl -> GetStringTable(This,ppStringTable)

#define IPlayPanel2_SetName(This,panelName)	\
    (This)->lpVtbl -> SetName(This,panelName)


#define IPlayPanel2_SetExcitedControl(This,pControl)	\
    (This)->lpVtbl -> SetExcitedControl(This,pControl)

#define IPlayPanel2_FindControl(This,dwUserDWORD)	\
    (This)->lpVtbl -> FindControl(This,dwUserDWORD)

#define IPlayPanel2_FindControlID(This,dwUserID)	\
    (This)->lpVtbl -> FindControlID(This,dwUserID)

#define IPlayPanel2_SetBackgroundBitmap(This,pBitmap)	\
    (This)->lpVtbl -> SetBackgroundBitmap(This,pBitmap)

#endif /* COBJMACROS */


#endif 	/* C style interface */



void STDMETHODCALLTYPE IPlayPanel2_SetExcitedControl_Proxy( 
    IPlayPanel2 __RPC_FAR * This,
    /* [in] */ IPlayControl __RPC_FAR *pControl);


void __RPC_STUB IPlayPanel2_SetExcitedControl_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


IPlayControl __RPC_FAR *STDMETHODCALLTYPE IPlayPanel2_FindControl_Proxy( 
    IPlayPanel2 __RPC_FAR * This,
    DWORD dwUserDWORD);


void __RPC_STUB IPlayPanel2_FindControl_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


IPlayControl __RPC_FAR *STDMETHODCALLTYPE IPlayPanel2_FindControlID_Proxy( 
    IPlayPanel2 __RPC_FAR * This,
    DWORD dwUserID);


void __RPC_STUB IPlayPanel2_FindControlID_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IPlayPanel2_SetBackgroundBitmap_Proxy( 
    IPlayPanel2 __RPC_FAR * This,
    IGXIntBitmap __RPC_FAR *pBitmap);


void __RPC_STUB IPlayPanel2_SetBackgroundBitmap_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IPlayPanel2_INTERFACE_DEFINED__ */


#ifndef __IPlayPagedPanelAdviseSink_INTERFACE_DEFINED__
#define __IPlayPagedPanelAdviseSink_INTERFACE_DEFINED__

/****************************************
 * Generated header for interface: IPlayPagedPanelAdviseSink
 * at Tue Nov 23 05:02:09 1999
 * using MIDL 3.01.75
 ****************************************/
/* [uuid][object][local] */ 



EXTERN_C const IID IID_IPlayPagedPanelAdviseSink;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    interface DECLSPEC_UUID("8335e493-ab3b-11ce-8468-0000b468276b")
    IPlayPagedPanelAdviseSink : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE StoreRevertInfo( 
            DWORD dwPageID) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Revert( 
            DWORD dwPageID) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE OnShowPage( 
            DWORD dwPageID) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE OnClose( void) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IPlayPagedPanelAdviseSinkVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            IPlayPagedPanelAdviseSink __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            IPlayPagedPanelAdviseSink __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            IPlayPagedPanelAdviseSink __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *StoreRevertInfo )( 
            IPlayPagedPanelAdviseSink __RPC_FAR * This,
            DWORD dwPageID);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Revert )( 
            IPlayPagedPanelAdviseSink __RPC_FAR * This,
            DWORD dwPageID);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *OnShowPage )( 
            IPlayPagedPanelAdviseSink __RPC_FAR * This,
            DWORD dwPageID);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *OnClose )( 
            IPlayPagedPanelAdviseSink __RPC_FAR * This);
        
        END_INTERFACE
    } IPlayPagedPanelAdviseSinkVtbl;

    interface IPlayPagedPanelAdviseSink
    {
        CONST_VTBL struct IPlayPagedPanelAdviseSinkVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IPlayPagedPanelAdviseSink_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IPlayPagedPanelAdviseSink_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IPlayPagedPanelAdviseSink_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IPlayPagedPanelAdviseSink_StoreRevertInfo(This,dwPageID)	\
    (This)->lpVtbl -> StoreRevertInfo(This,dwPageID)

#define IPlayPagedPanelAdviseSink_Revert(This,dwPageID)	\
    (This)->lpVtbl -> Revert(This,dwPageID)

#define IPlayPagedPanelAdviseSink_OnShowPage(This,dwPageID)	\
    (This)->lpVtbl -> OnShowPage(This,dwPageID)

#define IPlayPagedPanelAdviseSink_OnClose(This)	\
    (This)->lpVtbl -> OnClose(This)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE IPlayPagedPanelAdviseSink_StoreRevertInfo_Proxy( 
    IPlayPagedPanelAdviseSink __RPC_FAR * This,
    DWORD dwPageID);


void __RPC_STUB IPlayPagedPanelAdviseSink_StoreRevertInfo_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IPlayPagedPanelAdviseSink_Revert_Proxy( 
    IPlayPagedPanelAdviseSink __RPC_FAR * This,
    DWORD dwPageID);


void __RPC_STUB IPlayPagedPanelAdviseSink_Revert_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IPlayPagedPanelAdviseSink_OnShowPage_Proxy( 
    IPlayPagedPanelAdviseSink __RPC_FAR * This,
    DWORD dwPageID);


void __RPC_STUB IPlayPagedPanelAdviseSink_OnShowPage_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IPlayPagedPanelAdviseSink_OnClose_Proxy( 
    IPlayPagedPanelAdviseSink __RPC_FAR * This);


void __RPC_STUB IPlayPagedPanelAdviseSink_OnClose_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IPlayPagedPanelAdviseSink_INTERFACE_DEFINED__ */


#ifndef __IPlayPagedPanel_INTERFACE_DEFINED__
#define __IPlayPagedPanel_INTERFACE_DEFINED__

/****************************************
 * Generated header for interface: IPlayPagedPanel
 * at Tue Nov 23 05:02:09 1999
 * using MIDL 3.01.75
 ****************************************/
/* [uuid][object][local] */ 



EXTERN_C const IID IID_IPlayPagedPanel;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    interface DECLSPEC_UUID("8335e433-ab3b-11ce-8468-0000b468276b")
    IPlayPagedPanel : public IUnknown
    {
    public:
        virtual HRESULT __stdcall AddPage( 
            LPSTR pszPageName,
            DWORD __RPC_FAR *dwPageID) = 0;
        
        virtual HRESULT __stdcall AddControl( 
            DWORD dwPageID,
            IPlayControl __RPC_FAR *pControl,
            DWORD dwFlags) = 0;
        
        virtual HRESULT __stdcall ShowPage( 
            DWORD dwPageID) = 0;
        
        virtual HRESULT __stdcall UnlistPage( 
            DWORD dwPageID) = 0;
        
        virtual HRESULT __stdcall RelistPage( 
            DWORD dwPageID) = 0;
        
        virtual HRESULT __stdcall ChangePageName( 
            LPSTR pszPageName,
            DWORD dwPageID) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Advise( 
            IPlayPagedPanelAdviseSink __RPC_FAR *pAdviseSink) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IPlayPagedPanelVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            IPlayPagedPanel __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            IPlayPagedPanel __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            IPlayPagedPanel __RPC_FAR * This);
        
        HRESULT ( __stdcall __RPC_FAR *AddPage )( 
            IPlayPagedPanel __RPC_FAR * This,
            LPSTR pszPageName,
            DWORD __RPC_FAR *dwPageID);
        
        HRESULT ( __stdcall __RPC_FAR *AddControl )( 
            IPlayPagedPanel __RPC_FAR * This,
            DWORD dwPageID,
            IPlayControl __RPC_FAR *pControl,
            DWORD dwFlags);
        
        HRESULT ( __stdcall __RPC_FAR *ShowPage )( 
            IPlayPagedPanel __RPC_FAR * This,
            DWORD dwPageID);
        
        HRESULT ( __stdcall __RPC_FAR *UnlistPage )( 
            IPlayPagedPanel __RPC_FAR * This,
            DWORD dwPageID);
        
        HRESULT ( __stdcall __RPC_FAR *RelistPage )( 
            IPlayPagedPanel __RPC_FAR * This,
            DWORD dwPageID);
        
        HRESULT ( __stdcall __RPC_FAR *ChangePageName )( 
            IPlayPagedPanel __RPC_FAR * This,
            LPSTR pszPageName,
            DWORD dwPageID);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Advise )( 
            IPlayPagedPanel __RPC_FAR * This,
            IPlayPagedPanelAdviseSink __RPC_FAR *pAdviseSink);
        
        END_INTERFACE
    } IPlayPagedPanelVtbl;

    interface IPlayPagedPanel
    {
        CONST_VTBL struct IPlayPagedPanelVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IPlayPagedPanel_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IPlayPagedPanel_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IPlayPagedPanel_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IPlayPagedPanel_AddPage(This,pszPageName,dwPageID)	\
    (This)->lpVtbl -> AddPage(This,pszPageName,dwPageID)

#define IPlayPagedPanel_AddControl(This,dwPageID,pControl,dwFlags)	\
    (This)->lpVtbl -> AddControl(This,dwPageID,pControl,dwFlags)

#define IPlayPagedPanel_ShowPage(This,dwPageID)	\
    (This)->lpVtbl -> ShowPage(This,dwPageID)

#define IPlayPagedPanel_UnlistPage(This,dwPageID)	\
    (This)->lpVtbl -> UnlistPage(This,dwPageID)

#define IPlayPagedPanel_RelistPage(This,dwPageID)	\
    (This)->lpVtbl -> RelistPage(This,dwPageID)

#define IPlayPagedPanel_ChangePageName(This,pszPageName,dwPageID)	\
    (This)->lpVtbl -> ChangePageName(This,pszPageName,dwPageID)

#define IPlayPagedPanel_Advise(This,pAdviseSink)	\
    (This)->lpVtbl -> Advise(This,pAdviseSink)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT __stdcall IPlayPagedPanel_AddPage_Proxy( 
    IPlayPagedPanel __RPC_FAR * This,
    LPSTR pszPageName,
    DWORD __RPC_FAR *dwPageID);


void __RPC_STUB IPlayPagedPanel_AddPage_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT __stdcall IPlayPagedPanel_AddControl_Proxy( 
    IPlayPagedPanel __RPC_FAR * This,
    DWORD dwPageID,
    IPlayControl __RPC_FAR *pControl,
    DWORD dwFlags);


void __RPC_STUB IPlayPagedPanel_AddControl_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT __stdcall IPlayPagedPanel_ShowPage_Proxy( 
    IPlayPagedPanel __RPC_FAR * This,
    DWORD dwPageID);


void __RPC_STUB IPlayPagedPanel_ShowPage_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT __stdcall IPlayPagedPanel_UnlistPage_Proxy( 
    IPlayPagedPanel __RPC_FAR * This,
    DWORD dwPageID);


void __RPC_STUB IPlayPagedPanel_UnlistPage_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT __stdcall IPlayPagedPanel_RelistPage_Proxy( 
    IPlayPagedPanel __RPC_FAR * This,
    DWORD dwPageID);


void __RPC_STUB IPlayPagedPanel_RelistPage_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT __stdcall IPlayPagedPanel_ChangePageName_Proxy( 
    IPlayPagedPanel __RPC_FAR * This,
    LPSTR pszPageName,
    DWORD dwPageID);


void __RPC_STUB IPlayPagedPanel_ChangePageName_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IPlayPagedPanel_Advise_Proxy( 
    IPlayPagedPanel __RPC_FAR * This,
    IPlayPagedPanelAdviseSink __RPC_FAR *pAdviseSink);


void __RPC_STUB IPlayPagedPanel_Advise_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IPlayPagedPanel_INTERFACE_DEFINED__ */


#ifndef __IPlayPagedPanel2_INTERFACE_DEFINED__
#define __IPlayPagedPanel2_INTERFACE_DEFINED__

/****************************************
 * Generated header for interface: IPlayPagedPanel2
 * at Tue Nov 23 05:02:09 1999
 * using MIDL 3.01.75
 ****************************************/
/* [uuid][object][local] */ 



EXTERN_C const IID IID_IPlayPagedPanel2;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    interface DECLSPEC_UUID("8335e7ee-ab3b-11ce-8468-0000b468276b")
    IPlayPagedPanel2 : public IUnknown
    {
    public:
        virtual HRESULT __stdcall DoPageSelectionPopup( 
            IPlayControl __RPC_FAR *pControl,
            int xOffset,
            int yOffset) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IPlayPagedPanel2Vtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            IPlayPagedPanel2 __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            IPlayPagedPanel2 __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            IPlayPagedPanel2 __RPC_FAR * This);
        
        HRESULT ( __stdcall __RPC_FAR *DoPageSelectionPopup )( 
            IPlayPagedPanel2 __RPC_FAR * This,
            IPlayControl __RPC_FAR *pControl,
            int xOffset,
            int yOffset);
        
        END_INTERFACE
    } IPlayPagedPanel2Vtbl;

    interface IPlayPagedPanel2
    {
        CONST_VTBL struct IPlayPagedPanel2Vtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IPlayPagedPanel2_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IPlayPagedPanel2_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IPlayPagedPanel2_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IPlayPagedPanel2_DoPageSelectionPopup(This,pControl,xOffset,yOffset)	\
    (This)->lpVtbl -> DoPageSelectionPopup(This,pControl,xOffset,yOffset)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT __stdcall IPlayPagedPanel2_DoPageSelectionPopup_Proxy( 
    IPlayPagedPanel2 __RPC_FAR * This,
    IPlayControl __RPC_FAR *pControl,
    int xOffset,
    int yOffset);


void __RPC_STUB IPlayPagedPanel2_DoPageSelectionPopup_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IPlayPagedPanel2_INTERFACE_DEFINED__ */


#ifndef __IPlayColorPanel_INTERFACE_DEFINED__
#define __IPlayColorPanel_INTERFACE_DEFINED__

/****************************************
 * Generated header for interface: IPlayColorPanel
 * at Tue Nov 23 05:02:09 1999
 * using MIDL 3.01.75
 ****************************************/
/* [uuid][object][local] */ 



EXTERN_C const IID IID_IPlayColorPanel;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    interface DECLSPEC_UUID("8335e430-ab3b-11ce-8468-0000b468276b")
    IPlayColorPanel : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE PutInWindow( 
            HWND hWnd,
            unsigned char __RPC_FAR *pszFileName) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IPlayColorPanelVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            IPlayColorPanel __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            IPlayColorPanel __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            IPlayColorPanel __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *PutInWindow )( 
            IPlayColorPanel __RPC_FAR * This,
            HWND hWnd,
            unsigned char __RPC_FAR *pszFileName);
        
        END_INTERFACE
    } IPlayColorPanelVtbl;

    interface IPlayColorPanel
    {
        CONST_VTBL struct IPlayColorPanelVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IPlayColorPanel_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IPlayColorPanel_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IPlayColorPanel_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IPlayColorPanel_PutInWindow(This,hWnd,pszFileName)	\
    (This)->lpVtbl -> PutInWindow(This,hWnd,pszFileName)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE IPlayColorPanel_PutInWindow_Proxy( 
    IPlayColorPanel __RPC_FAR * This,
    HWND hWnd,
    unsigned char __RPC_FAR *pszFileName);


void __RPC_STUB IPlayColorPanel_PutInWindow_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IPlayColorPanel_INTERFACE_DEFINED__ */


/* Additional Prototypes for ALL interfaces */

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif
