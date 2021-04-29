//+---------------------------------------------------------------------------
//
//  Trinity Implementation 
//  Copyright (C) Play Incorporated, 1995
//
//  File:       ComBase.H
//
//  Contents:   Declaration of CClassTemplate, CUnknown
//
//  History:    October 3, 1995 cpdaniel created 
//
//----------------------------------------------------------------------------
#ifndef __combase_h_
#define __combase_h_
#include <unknwn.h>

/*

a. Derive your COM object from CUnknown

b. Make a static CreateInstance function that takes an LPUNKNOWN, and an 
   HRESULT *. The LPUNKNOWN defines the object to delegate IUnknown calls
   to. The HRESULT * allows error codes to be passed around constructors.

   It is important that constructors only change the HRESULT * if they have
   to set an ERROR code, if it was successful then leave it alone or you may
   overwrite an error code from an object previously created.

c. Have a constructor for your object that passes the LPUNKNOWN and HRESULT *
   to the CUnknown constructor. You can set the HRESULT if you have an
   error, or just simply pass it through to the constructor.

   The object creation will fail in the class factory if the HRESULT indicates
   an error (ie FAILED(HRESULT) == TRUE)

d. Create a CClassTemplate with your object's class id and CreateInstance
   function.

Then (for each interface) either

Multiple inheritance

1. Also derive it from ISomeInterface
2. Include DECLARE_IUNKNOWN in your class definition to declare
   implementations of QueryInterface, AddRef and Release that
   call the outer unknown
3. Override NonDelegatingQueryInterface to expose ISomeInterface by
   code something like

     if (riid == IID_ISomeInterface) {
         return GetInterface((ISomeInterface *) this, ppv);
     } else {
         return CUnknown::NonDelegatingQueryInterface(riid, ppv);
     }

4. Declare and implement the member functions of ISomeInterface.

or: Nested interfaces

1. Declare a class derived from CUnknown
2. Include DECLARE_IUNKNOWN in your class definition
3. Override NonDelegatingQueryInterface to expose ISomeInterface by
   code something like

     if (riid == IID_ISomeInterface) {
         return GetInterface((ISomeInterface *) this, ppv);
     } else {
         return CUnknown::NonDelegatingQueryInterface(riid, ppv);
     }

4. Implement the member functions of ISomeInterface. Use GetOwner() to
   access the COM object class.

And in your COM object class:

5. Make the nested class a friend of the COM object class, and declare
   an instance of the nested class as a member of the COM object class.

   NOTE that because you must always pass the outer unknown and an hResult
   to the CUnknown constructor you cannot use a default constructor, in
   other words you will have to make the member variable a pointer to the
   class and make a NEW call in your constructor to actually create it.

6. override the NonDelegatingQueryInterface with code like this:

     if (riid == IID_ISomeInterface) {
         return m_pImplFilter->
            NonDelegatingQueryInterface(IID_ISomeInterface, ppv);
     } else {
         return CUnknown::NonDelegatingQueryInterface(riid, ppv);
     }

You can have mixed classes which support some interfaces via multiple
inheritance and some via nested classes

===========================================================

EXE Servers:  You can write your own WinMain and messageloop, just put the 
              following at the beginning of your WinMain:

    HRESULT hr;
    BOOL bExit;
    CWinMainHousekeeping house( hInstance, lpCmdLine, &hr, &bExit );

    if ( FAILED(hr) )
        ; // print error of some kind here, 
          //  the server failed to register, COM couldn't init etc.
    
    if ( bExit )
        return(0); // this may happen even without errors if the EXE
                   // was told to register or unregister itself.

*/

/* Version of IUnknown that is renamed to allow a class to support both
   non delegating and delegating IUnknowns in the same COM object */

DECLARE_INTERFACE(INonDelegatingUnknown)
{
    STDMETHOD(NonDelegatingQueryInterface) (THIS_ REFIID, LPVOID *) PURE;
    STDMETHOD_(ULONG, NonDelegatingAddRef)(THIS) PURE;
    STDMETHOD_(ULONG, NonDelegatingRelease)(THIS) PURE;
};

typedef INonDelegatingUnknown *PNDUNKNOWN;

/* Set by DllMain on PROCESS_ATTACH */
extern HINSTANCE g_hInstance;
extern HINSTANCE g_hKernelDll;

/* An object that supports one or more COM interfaces will be based on
   this class. It supports counting of total objects for DLLCanUnloadNow
   support, and an implementation of the core non delegating IUnknown */

class CWinMainHousekeeping
{
public:
    CWinMainHousekeeping( HINSTANCE hInstance, LPSTR pszCmdLine, HRESULT *pHr, BOOL *pbExit );
    virtual ~CWinMainHousekeeping();

private:
    HRESULT m_hrCoInit,
            m_hrRegFactories;

};

class CClassTemplate;

class CUnknown : public INonDelegatingUnknown
{
    friend class CClassFactory;

private:

    static LONG m_cObjects;     /* Total number of objects active */
    LPUNKNOWN   m_pUnknown;     /* Owner of this object */

protected:                      /* So we can override NonDelegatingRelease() */
    LONG        m_cRef;         /* Number of reference counts */

public:
    static long LockServer( BOOL bAddRef );

    static VOID CALLBACK SuicideTimerProc(
                              HWND hwnd,     // handle of window for timer messages
                              UINT uMsg,     // WM_TIMER message
                              UINT idEvent,  // timer identifier
                              DWORD dwTime   // current system time
                            );

    CUnknown(LPUNKNOWN pUnk, HRESULT *phr);
    virtual ~CUnknown();

    static void InitReferenceCounting( BOOL bIsEXE );
    typedef LONG (__stdcall * CountingFn)(LPLONG);
    static CountingFn m_IncrementCount;
    static CountingFn m_DecrementCount;

    /* Return the owner of this object */

    LPUNKNOWN GetOwner() const 
    {
        return m_pUnknown;
    };

    /* Called from the class factory to create a new instance, it is
       static and class-specific so it must be overriden in your derived class */

    /* static CUnknown *CreateInstance(LPUNKNOWN, HRESULT *) */

    /* Non delegating unknown implementation */

    STDMETHODIMP NonDelegatingQueryInterface(REFIID, void **);
    STDMETHODIMP_(ULONG) NonDelegatingAddRef();
    STDMETHODIMP_(ULONG) NonDelegatingRelease();

    /* Return an interface pointer to a requesting client
       performing a thread safe AddRef as necessary */

    HRESULT GetInterface(LPUNKNOWN pUnk, void **ppv);

    virtual void PrintSelf( void ( __stdcall *printFcn)(LPCTSTR) );

    static LONG ObjectsActive() 
    {
        return m_cObjects;
    }
    void SetClassTemplate( CClassTemplate *classTemplate );
    CClassTemplate *m_pTemplate;

    static HRESULT ParseDisplayNameItem(
      /* [unique][in] */ IBindCtx __RPC_FAR *pbc,
      /* [in] */ LPOLESTR pszDisplayName,
      /* [out] */ ULONG __RPC_FAR *pchEaten,
      /* [out] */ IMoniker __RPC_FAR *__RPC_FAR *ppmkOut
      );

    static ULONG    SingletonRelease(IUnknown*);
    static HRESULT  SingletonFactory(REFCLSID rclsid, REFIID riid, void** ppv);
    static void     InitSingletonFactory(BOOL loading);
};

/* You must override the (pure virtual) NonDelegatingQueryInterface to return
   interface pointers (using GetInterface) to the interfaces your derived
   class supports (the default implementation only supports IUnknown) */

#define DECLARE_IUNKNOWN                                        \
    STDMETHODIMP QueryInterface(REFIID riid, void **ppv) {      \
        return GetOwner()->QueryInterface(riid,ppv);            \
    };                                                          \
    STDMETHODIMP_(ULONG) AddRef() {                             \
        return GetOwner()->AddRef();                            \
    };                                                          \
    STDMETHODIMP_(ULONG) Release() {                            \
        return GetOwner()->Release();                           \
    };

#define DECLARE_SINGLETON_IUNKNOWN                              \
    STDMETHODIMP QueryInterface(REFIID riid, void **ppv) {      \
        return GetOwner()->QueryInterface(riid,ppv);            \
    };                                                          \
    STDMETHODIMP_(ULONG) AddRef() {                             \
        return GetOwner()->AddRef();                            \
    };                                                          \
    STDMETHODIMP_(ULONG) Release() {                            \
        return CUnknown::SingletonRelease(GetOwner());          \
    };



//----------------------------------------------------------------------------
// _ITemplateObjectList -- interface to a list of CUnknowns
//----------------------------------------------------------------------------

interface _ITemplateObjectList
{
public:
    // none of these functions addref/release the object
    // it will not call any member functions on the pointer.
    // it's solely for use as bookkeeping to know the pointers
    // of objects that didn't go away.
    virtual HRESULT AddObject( CUnknown *pObject ) = 0;
    virtual HRESULT RemoveObject( CUnknown *pObject ) = 0;

    // return the number of objects currently in the list
    virtual long NumObjects( void ) = 0;
    
    // return the object number of the next one to be added.  The
    // object number goes up with each object added,
    // but never down.  It starts with 0.  To be used to
    // stop CClassTemplate when it reaches object # X.
    virtual long NextAddIndex( void ) = 0;

    // Get object with given index in the currect list.
    // also returns the object number so next run can see if
    // same object is unfreed...
    virtual HRESULT GetObject( long index, CUnknown **ppunk, long *objectNumber ) = 0;
};

//----------------------------------------------------------------------------
// CClassTemplate - connects class implementations to the central class factory
//----------------------------------------------------------------------------

#ifdef _DEBUG
#define DEBUG_NAME(p) #p
#else
#define DEBUG_NAME(p) NULL
#endif

#define DECLARE_CLASS_TEMPLATE_N( name ) static CClassTemplate TemplateFor##name( CLSID_##name, name::CreateInstance, NULL, NULL, NULL, DEBUG_NAME(name) );
#define DECLARE_CLASS_TEMPLATE( clsid, name ) static CClassTemplate TemplateFor##name( clsid, name::CreateInstance, NULL, NULL, NULL, DEBUG_NAME(name) );
#define DECLARE_CLASS_TEMPLATE_INIT( clsid, name, init ) static CClassTemplate TemplateFor##name( clsid, name::CreateInstance, name::init, NULL, NULL, DEBUG_NAME(name) );
#define DECLARE_CLASS_TEMPLATE_FULL( clsid, name, init, create ) static CClassTemplate TemplateFor##name( clsid, name::create, name::init, NULL, NULL, DEBUG_NAME(name) );
#define DECLARE_CLASS_TEMPLATE_FULL2( clsid, name, init, create, reg) static CClassTemplate TemplateFor##name(clsid, name::create, name::init, name::reg, NULL, DEBUG_NAME(name) );
#define DECLARE_CLASS_TEMPLATE_FULL3( clsid, name, init, create, reg, fact) static CClassTemplate TemplateFor##name(clsid, name::create, name::init, name::reg, name::fact, DEBUG_NAME(name) );
#define DECLARE_CLASS_TEMPLATE_REG( clsid, name, create, reg) static CClassTemplate TemplateFor##name(clsid, name::create, NULL, name::reg, NULL, DEBUG_NAME(name) );
#define DECLARE_CLASS_TEMPLATE_SINGLETON( clsid, name ) static CClassTemplate TemplateFor##name( clsid, name::CreateInstance, NULL, NULL, CUnknown::SingletonFactory, DEBUG_NAME(name) ); 

class CClassTemplate
{
  public:
    typedef CUnknown* (*PFNNewObject)(IUnknown* pUnkOuter, HRESULT* pRslt);
    typedef void (*PFNInitClass)(BOOL loading, const CLSID *prclsid);
    typedef HRESULT (*PFNRegClass)(BOOL register, const CLSID* prclsid);
    typedef HRESULT (*PFNGetClassObject)(REFCLSID rclsid, REFIID riid, void** ppv);

    CClassTemplate(const CLSID *pClsId,
                   PFNNewObject pfnNew, 
                   PFNInitClass pfnInit);
    CClassTemplate(const CLSID *pClsId,
                   PFNNewObject pfnNew, 
                   PFNInitClass pfnInit,
                   PFNRegClass  pfnReg,
                   PFNGetClassObject pfnFactory,
                   const char *name );

    virtual ~CClassTemplate();

    BOOL IsClassID(REFCLSID rclsid) const;

    CUnknown *CreateInstance(IUnknown* pUnk, HRESULT *phr) const;

    HRESULT GetClassObject(REFCLSID rclsid, REFIID riid, void** ppv);

    static CClassTemplate* FindTemplate(const CLSID *pClsId);

    static void ProcessAttach(BOOL);

    static HRESULT RegisterAllClasses(void);

    static HRESULT UnregisterAllClasses(void);
    
    static HRESULT RegisterAllClassesLocal(void);

    static HRESULT UnregisterAllClassesLocal(void);

    static HRESULT RegisterAllClassFactories(void);

    static HRESULT RevokeAllClassFactories(void);

    static CClassTemplate *GetHead(void);

    CClassTemplate *GetNext(void);

    void DecObjects( CUnknown *objectDying );
    static void ShowObjects();

    static void InitializeClasses( BOOL bLoad );

    static void SetObjectNumberBreak( REFCLSID pclsid, long objectNumber );
    static BOOL IsObjectNumberBreak( REFCLSID pclsid, long objectNumber );

    const CLSID    *m_ClsID;
  private:
    const char *m_pszClassName;
    long        m_cClassObjects;
    static CClassTemplate *s_pHead;
    static long s_bInitialized;

    PFNNewObject    m_lpfnNew;
    PFNInitClass    m_lpfnInit;
    PFNRegClass     m_lpfnReg;
    PFNGetClassObject m_lpfnFactory;
    CClassTemplate *m_pNext;
    DWORD           m_dwRegisterID;
    long            m_fClassRegistered;

    _ITemplateObjectList    *m_pObjectList;
};

template <class T> inline void SET_PTR(T*& d, T*p) 
{ 
  if (p) 
    ((d)=(p))->AddRef(); 
  else 
    (d)=0; 
}

template <class T> inline void SAFE_RELEASE(T*& p) 
{
 (p)?(void)((p)->Release(),(p)=0):(void)0; 
}

extern HRESULT CoCreateInProcess(
  REFCLSID    rclsid,
  REFIID      riid,
  LPVOID FAR* ppv
  );

#define DECLARE_ITRNITEMCONTAINERBASE                                                 \
    HRESULT STDMETHODCALLTYPE                                                         \
    ParseDisplayName(                                                                 \
        /* [unique][in] */ IBindCtx __RPC_FAR *pbc,                                   \
        /* [in] */ LPOLESTR pszDisplayName,                                           \
        /* [out] */ ULONG __RPC_FAR *pchEaten,                                        \
        /* [out] */ IMoniker __RPC_FAR *__RPC_FAR *ppmkOut)                           \
    {                                                                                 \
      return CUnknown::ParseDisplayNameItem(pbc,pszDisplayName,pchEaten,ppmkOut);     \
    }                                                                                 \
                                                                                      \
    HRESULT STDMETHODCALLTYPE                                                         \
    EnumObjects(                                                                      \
        /* [in] */ DWORD grfFlags,                                                    \
        /* [out] */ IEnumUnknown __RPC_FAR *__RPC_FAR *ppenum)                        \
    {                                                                                 \
      return E_NOTIMPL;                                                               \
    }                                                                                 \
                                                                                      \
    HRESULT STDMETHODCALLTYPE                                                         \
    LockContainer(                                                                    \
        /* [in] */ BOOL fLock)                                                        \
    {                                                                                 \
      CUnknown::LockServer(fLock);                                                    \
      return S_OK;                                                                    \
    }                                                                                 \
                                                                                      \
    HRESULT STDMETHODCALLTYPE                                                         \
    GetObjectStorage(                                                                 \
        /* [in] */ LPOLESTR pszItem,                                                  \
        /* [unique][in] */ IBindCtx __RPC_FAR *pbc,                                   \
        /* [in] */ REFIID riid,                                                       \
        /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvStorage)                    \
    {                                                                                 \
      return MK_E_NOSTORAGE;                                                          \
    }                                                                                 \
                                                                                      \
    HRESULT STDMETHODCALLTYPE                                                         \
    IsRunning(                                                                        \
        /* [in] */ LPOLESTR pszItem)                                                  \
    {                                                                                 \
      return S_FALSE;                                                                 \
    }                                                                                 \
                                                                                      
#define DECLARE_ITRNITEMCONTAINER                                                     \
    DECLARE_ITRNITEMCONTAINERBASE                                                     \
    HRESULT STDMETHODCALLTYPE                                                         \
    GetObject(                                                                        \
        /* [in] */ LPOLESTR pszItem,                                                  \
        /* [in] */ DWORD dwSpeedNeeded,                                               \
        /* [unique][in] */ IBindCtx __RPC_FAR *pbc,                                   \
        /* [in] */ REFIID riid,                                                       \
        /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);                    \
                                                                                      \
    HRESULT STDMETHODCALLTYPE                                                         \
    GetMoniker(                                                                       \
      /* [in] */ IUnknown __RPC_FAR *pItem,                                           \
      /* [in] */ DWORD dwWhichMoniker,                                                \
      /* [out] */ IMoniker __RPC_FAR *__RPC_FAR *ppMk);                               

#endif

//
// Handy macros for use with #pragma message
// Use #pragma tagged_message("your message here") and it will have file & line number
// added to it (and yes, the IDE can parse the strings so you can double-click on them!
// (and yes, tagged_message2 IS necessary to force the preprocessor to evaluate
// the __LINE__ passed in from tagged_message
//
#define tagged_message3(l,m) __FILE__"(" #l ") : "m
#define tagged_message2(l,m) tagged_message3(l,m)
#define tagged_message(m) message(tagged_message2(__LINE__,m))

// End of Combase.H
