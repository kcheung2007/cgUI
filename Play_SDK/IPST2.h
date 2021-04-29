/*****************************************************************************
  PLAY CONFIDENTIAL - Copyright 1999 Play Inc., All Rights Reserved.
   Project : Play Storage II
      File : IPST2.h
   Purpose : Master header file
   8/11/99 : Created (Mark Riley)
*****************************************************************************/

#ifndef _IPST2_H_
#define _IPST2_H_

#include <IPIO.h>

typedef unsigned long ulong;
typedef unsigned short ushort;
typedef unsigned char uchar;
typedef unsigned __int64 uint64;

struct IPSTNode;

/****************************************************************************/

struct IPSTStream : IPIO
  {
  STDMETHOD(GetNode)(IPSTNode** p_node) PURE;
  };

extern "C" const IID IID_IPSTStream;

/****************************************************************************/

struct IPSTNotify
  {
  virtual void __stdcall Changed() { }
  virtual void __stdcall ChildCreated(IPSTNode* child) { }
  virtual void __stdcall ChildDeleted(IPSTNode* child) { }
  virtual void __stdcall ChildChanged(IPSTNode* child) { }
  };

/****************************************************************************/

enum
  {
  IPST2_INFO_NAME    = 0x00000001,
  IPST2_INFO_FLAGS   = 0x00000002,
  IPST2_INFO_SIZE    = 0x00000004,
  IPST2_INFO_MDATE   = 0x00000008,
  IPST2_INFO_CDATE   = 0x00000010,

  IPST2_INFO_TYPE    = 0x00010000,
  IPST2_INFO_DATA    = 0x00020000,
  };

struct IPST2_INFO
  {
  ulong field;
  char* name;
  ulong flags;
  ulong size;
  uint64 mdate;
  uint64 cdate;

  ulong type;
  uchar* data;
  };

/****************************************************************************/

enum
  {
  IPST2_TYPE_CLSID,
  IPST2_TYPE_SYMBOLIC_LINK,
  IPST2_TYPE_STRING,
  IPST2_TYPE_DWORD,
  IPST2_TYPE_WORD,
  IPST2_TYPE_BYTE,
  IPST2_TYPE_BOOL,
  };

/****************************************************************************/

enum
  {
  IPST2_NODE_NOUNIQUE      = 0x00010000,
  IPST2_NODE_NOPATH        = 0x00020000,
  IPST2_NODE_CDATE         = 0x00040000,
  IPST2_NODE_MDATE         = 0x00080000,
  IPST2_NODE_AFTER         = 0x00100000,
  IPST2_NODE_BEFORE        = 0x00200000,
  IPST2_NODE_FIRST         = IPST2_NODE_AFTER | IPST2_NODE_BEFORE,
  IPST2_NODE_VOLATILE      = 0x00400000,  // Node lives in memory only
  IPST2_NODE_ALWAYS        = 0x00800000,  // Create node or use existing
  };

/****************************************************************************/

enum
  {
  IPST2_STREAM_COMPRESSED  = 0x10000000,
  IPST2_STREAM_SEQUENTIAL  = 0x20000000,  // Stream will be accessed sequentially
  IPST2_STREAM_CACHE       = 0x40000000,  // Stream should be cached after closing
  };

/****************************************************************************/

struct IPSTNode : IUnknown
  {
  STDMETHOD(CreateNode)(IPSTNode** p_node, IPST2_INFO* info, ulong flags) PURE;
  STDMETHOD(DeleteNode)(const char* path, ulong flags) PURE;

  STDMETHOD(CreateStream)(IPSTStream** p_stream, const char* path, ulong flags) PURE;

  STDMETHOD(GetNode)(IPSTNode** p_node, const char* path, ulong flags) PURE;
  STDMETHOD(GetParent)(IPSTNode** p_node) PURE;
  STDMETHOD(GetChild)(IPSTNode** p_node) PURE;
  STDMETHOD(GetNext)(IPSTNode** p_node) PURE;

  STDMETHOD(GetName)(char* buffer, ulong* p_bufsize) PURE;
  STDMETHOD(GetPath)(char* buffer, ulong* p_bufsize) PURE;

  //STDMETHOD(GetData)(void* data, ulong* p_size) PURE;

  STDMETHOD(Lock)() PURE;
  STDMETHOD(Unlock)() PURE;

  STDMETHOD(LockInfo)(IPST2_INFO* info) PURE;
  STDMETHOD(SetInfo)(IPST2_INFO* info) PURE;
  STDMETHOD(DeleteInfo)(ulong field) PURE;
  STDMETHOD(GetField)(ulong* p_field) PURE;

  STDMETHOD(MoveNode)(IPSTNode* where, ulong flags) PURE;
  
  STDMETHOD(MountNode)(IPSTNode* node) PURE;

  STDMETHOD(GetMaster)(IUnknown** p_unknown) PURE;

  STDMETHOD(AddNotify)(IPSTNotify* notify) PURE;
  STDMETHOD(RemoveNotify)(IPSTNotify* notify) PURE;
  };

extern "C" const IID IID_IPSTNode;

/****************************************************************************/

enum IPST2_OPEN
  {
  IPST2_OPEN_NEW           = 0x00000001, // Erases existing data (if any)
  IPST2_OPEN_READ_ONLY     = 0x00000002, // Discards any changes
  IPST2_OPEN_NO_SIZE       = 0x00000004, // Doesn't resize disk file (grow or shrink)
  IPST2_OPEN_LOAD_NODES    = 0x00000008, // Load node hierarchy into memory
  IPST2_OPEN_LOAD_STREAMS  = 0x00000010, // Load all streams into memory
  };

struct IPST2 : IUnknown
  {
  STDMETHOD(Open)(IPIO* pio, long flags) PURE;
  //STDMETHOD(Close)() PURE;

  STDMETHOD(GetRoot)(IPSTNode** p_node) PURE;
  };
  
HRESULT __stdcall CreatePST2(IPST2**);

extern "C" const CLSID CLSID_PST2;
extern "C" const IID IID_IPST2;

extern "C" const GUID GUID_PST;
extern "C" const GUID GUID_PST2;

/*****************************************************************************
  IStoragePSTNode - IStorage on top of IPSTNode
*****************************************************************************/

struct IStoragePSTNode : IStorage
  {
  STDMETHOD(Setup)(IPSTNode* node) PURE;
  };

HRESULT __stdcall CreateStoragePSTNode(IStoragePSTNode** p_o);
HRESULT __stdcall CreateStorage_PSTNode(IStorage** p_storage, IPSTNode* node);

extern "C" const CLSID CLSID_StoragePSTNode;
extern "C" const IID IID_IStoragePSTNode;

enum
  {
  PSTGM_FILE_MAPPING = 0x80000000ul,
  };

HRESULT __stdcall PStgOpenStorage(
  const WCHAR * pwcsName,
  IStorage * pstgPriority,
  DWORD grfMode,
  SNB snbExclude,
  DWORD reserved,
  IStorage ** ppstgOpen);

HRESULT __stdcall PStgCreateDocfile(
  const WCHAR * pwcsName,
  DWORD grfMode,
  DWORD reserved,
  IStorage ** ppstgOpen);

/*****************************************************************************
  Helper functions
*****************************************************************************/

HRESULT __stdcall CreatePST2_PIO(IPST2** p_pst, ulong flags, IPIO* pio);
HRESULT __stdcall CreatePSTNode_PIO(IPSTNode** p_root, ulong flags,
  IPIO* pio);

HRESULT __stdcall CreatePST2_Path(IPST2** p_pst, ulong flags,
  const char* path, ulong pflags);
HRESULT __stdcall CreatePSTNode_Path(IPSTNode** p_root, ulong flags,
  const char* path, ulong pflags);

#ifdef WIN32

HRESULT __stdcall CreatePST2_Resource(IPST2** p_pst, ulong flags,
  HMODULE hModule, LPCTSTR lpType, LPCTSTR lpName, WORD wLanguage);
HRESULT __stdcall CreatePSTNode_Resource(IPSTNode** p_root, ulong flags,
  HMODULE hModule, LPCTSTR lpType, LPCTSTR lpName, WORD wLanguage);

#endif

HRESULT __stdcall IsValidPST2(IPIO* pio);

/*****************************************************************************
  Error code range assignments
    0xE8320000 IPST
    0xE8320100 IPIO
    0xE8320200 IPIOMemory
    0xE8320300 IPIOZDeflate & IPIOZInflate
    0xE8320400
    0xE8320500
    0xE8320600
    0xE8320700
*****************************************************************************/

enum
  {
  IPST2_ERROR = 0xE8320001,
  IPST2_ERROR_INVALID_PST,
  IPST2_ERROR_ALREADY_OPEN,
  IPST2_ERROR_NOT_OPEN,
  IPST2_ERROR_NO_PARENT,
  IPST2_ERROR_NO_CHILD,
  IPST2_ERROR_NO_NODE,
  IPST2_ERROR_BUFFER_TOO_SMALL,
  IPST2_ERROR_PATH_NOT_FOUND,
  IPST2_ERROR_STORAGE_FULL,
  IPST2_ERROR_NO_STREAM,
  IPST2_ERROR_NODE_EXISTS,
  IPST2_ERROR_NODE_DELETED,
  IPST2_ERROR_NODE_NOT_RELATED,
  IPST2_ERROR_NODE_IS_DESCENDANT,
  IPST2_ERROR_NO_ROOT_SIBLINGS,
  IPST2_ERROR_CANT_DELETE_ROOT,
  };

/****************************************************************************/

struct PST2LockInfo : IPST2_INFO
  {
  IPSTNode* node;

  PST2LockInfo() : node(0) {}
  ~PST2LockInfo() { if (node) node->Unlock(); }

  HRESULT Lock(IPSTNode* node)
    {
    Unlock();
    HRESULT hr = node->LockInfo(this);
    if SUCCEEDED(hr) this->node = node;
    return hr;
    }

  void Unlock()
    {
    if (node) { node->Unlock(); node = 0; }
    }
  };

/****************************************************************************/

#endif

/* EOF */
