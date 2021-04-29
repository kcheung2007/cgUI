/*****************************************************************************
  PLAY CONFIDENTIAL - Copyright 1999 Play Inc., All Rights Reserved.
   Project : COM Wrapper DLL
      File : PComWrap.h
   Purpose : Lightweight library allows multiple COM objects to easily be
             packaged in a single DLL or used seperately as libs
   7/29/99 : Created (Mark Riley)
*****************************************************************************/

#ifndef _PCOMWRAP_H_
#define _PCOMWRAP_H_

#include <unknwn.h>

/****************************************************************************/

extern HINSTANCE g_hInstance;  // DLL instance
extern LONG g_PCW_locks;

/****************************************************************************/

// Restriction: Should be first base class in derived class because
// the Release() function does a delete call on 'this'.  If not the
// first base class, override the DeleteMe() function to properly
// self delete.

struct PUnknown : IUnknown
  {
  PUnknown();
  virtual ~PUnknown();

  STDMETHOD(QueryInterface)(REFIID iid, void **ppv);
  STDMETHOD_(ULONG,AddRef)();
  STDMETHOD_(ULONG,Release)();

protected:
  LONG m_refcount;
  virtual void DeleteMe();
  };

/****************************************************************************/

#define PCW_DECLARE_IUNKNOWN                                               \
  STDMETHOD(QueryInterface)(REFIID iid, void **ppv);                       \
  STDMETHODIMP_(ULONG) AddRef() { return PUnknown::AddRef(); }             \
  STDMETHODIMP_(ULONG) Release() { return PUnknown::Release(); }

/****************************************************************************/

struct PClassInfo
  {
  typedef HRESULT (__stdcall *fCreateObject)(void** ppv);
  fCreateObject CreateObject;
  const CLSID* clsid;
  };

/****************************************************************************/

struct PClassFactory : IClassFactory
  {
  PClassFactory();
  ~PClassFactory();

  // IUnknown
  STDMETHOD(QueryInterface)(REFIID riid, void **ppv);
  STDMETHOD_(ULONG,AddRef)();
  STDMETHOD_(ULONG,Release)();

  // IClassFactory
  STDMETHOD(LockServer)(BOOL fLock);
  STDMETHOD(CreateInstance)(IUnknown* pUnkOuter, REFIID riid, void** ppv);

  LONG m_refcount;

  PClassInfo* m_info;

  PClassFactory* m_next;
  static PClassFactory* s_factories[];
  void AddFactory(PClassInfo* info);
  };

/****************************************************************************/

#define PCW_CONSTRUCT(name) InterlockedIncrement(&g_PCW_locks);
#define PCW_DESTRUCT(name) InterlockedDecrement(&g_PCW_locks);

/****************************************************************************/

#define PCW_DEFINE_INFO(name)                                              \
extern "C" PClassInfo g_PCI_##name =                                       \
  { (PClassInfo::fCreateObject)Create##name, &CLSID_##name };

/****************************************************************************/

#define PCW_DEFINE_FACTORY(name)                                           \
extern "C" PClassInfo g_PCI_##name;                                        \
struct PCF_##name : PClassFactory                                          \
  { PCF_##name() { AddFactory(&g_PCI_##name); } };                         \
PCF_##name g_PCF_##name##_factory;

/****************************************************************************/

#define PCW_DEFINE_CREATE(name)                                            \
extern "C" const CLSID CLSID_##name;                                       \
extern "C" const IID IID_I##name;                                          \
HRESULT __stdcall Create##name(struct I##name** p_object)                            \
  {                                                                        \
  return CoCreateInstance(CLSID_##name, 0, CLSCTX_INPROC_SERVER,           \
    IID_I##name, (void**)p_object);                                        \
  }

#define PCW_DEFINE_CREATE2(name,face)                                      \
extern "C" const CLSID CLSID_##name;                                       \
extern "C" const IID IID_##face;                                           \
HRESULT __stdcall Create##name(struct face** p_object)                               \
  {                                                                        \
  return CoCreateInstance(CLSID_##name, 0, CLSCTX_INPROC_SERVER,           \
    IID_##face, (void**)p_object);                                         \
  }

/****************************************************************************/

#endif

/* EOF */
