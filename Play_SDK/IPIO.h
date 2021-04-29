/*****************************************************************************
  PLAY CONFIDENTIAL - Copyright 1999 Play Inc., All Rights Reserved.
   Project : Play Storage II
      File : IPIO.h
   Purpose : Declarations for IPIO interface
   8/11/99 : Created (Mark Riley)
*****************************************************************************/

#ifndef _IPIO_H_
#define _IPIO_H_

#include <unknwn.h>

typedef unsigned long ulong;
typedef unsigned short ushort;
typedef unsigned char uchar;
typedef unsigned __int64 uint64;

/*****************************************************************************
  IPIO
*****************************************************************************/

enum
  {
  IPIO_READ        = 0x00000001,
  IPIO_WRITE       = 0x00000002,
  IPIO_DENY_READ   = 0x00000004,
  IPIO_DENY_WRITE  = 0x00000008,
  IPIO_ALWAYS      = 0x00000010,
  IPIO_CREATE      = 0x00000020,

  IPIO_READWRITE   = IPIO_READ | IPIO_WRITE,
  IPIO_EXCLUSIVE   = IPIO_DENY_READ | IPIO_DENY_WRITE,
  IPIO_NEW         = IPIO_CREATE | IPIO_ALWAYS,

  IPIO_XREAD       = IPIO_EXCLUSIVE | IPIO_READ,
  IPIO_XWRITE      = IPIO_EXCLUSIVE | IPIO_WRITE,
  IPIO_XREADWRITE  = IPIO_EXCLUSIVE | IPIO_READWRITE,
  };

enum
  {
  IPIO_INFO_NAME    = 0x00000001,
  IPIO_INFO_FLAGS   = 0x00000002,
  IPIO_INFO_SIZE    = 0x00000004,
  IPIO_INFO_MDATE   = 0x00000008,
  IPIO_INFO_CDATE   = 0x00000010,

  IPIO_INFO_MAXSIZE = 0x00010000,
  };  
  
struct IPIO_INFO
  {
  ulong field;
  char* name;
  ulong flags;
  ulong size;
  uint64 mdate;
  uint64 cdate;

  long name_size;
  ulong maxsize;
  };

enum IPIO_SEEK
  {
  IPIO_SEEK_START,
  IPIO_SEEK_CURRENT,
  IPIO_SEEK_END,
  };

struct IPIO : IUnknown
  {
  STDMETHOD(Read)(void* buffer, ulong* size) PURE;
  STDMETHOD(Write)(const void* buffer, ulong* size) PURE;
  STDMETHOD(Seek)(IPIO_SEEK mode, long offset) PURE;
  STDMETHOD(Tell)(ulong* position) PURE;
  STDMETHOD(Truncate)() PURE;
  //STDMETHOD(SetSize)(ulong size) PURE;
  STDMETHOD(Info)(IPIO_INFO* info) PURE;
  //STDMETHOD(Flush)() PURE;
  //STDMETHOD(Close)() PURE;
  };

enum
  {
  IPIO_S_EXISTS = 1,
  IPIO_ERROR = 0xE8320101,
  IPIO_ERROR_EOF,
  IPIO_ERROR_NOT_OPEN,
  IPIO_ERROR_SEEK,
  IPIO_ERROR_NOT_FOUND,
  IPIO_ERROR_ACCESS_DENIED,
  IPIO_ERROR_NO_WRITES,
  IPIO_ERROR_NO_READS,
  IPIO_ERROR_EXISTS,
  IPIO_ERROR_ALREADY_OPEN,
  };

extern "C" const IID IID_IPIO;

/*****************************************************************************
  IPIOWin32 - Implemention of IPIO for Win32 file handles
*****************************************************************************/

#ifdef WIN32

struct IPIOWin32 : IPIO
  {
  STDMETHOD(SetHandle)(HANDLE handle, bool fClose) PURE;
  STDMETHOD(GetHandle)(HANDLE* p_handle, bool fDetach) PURE;
  STDMETHOD(Close)() PURE;
  STDMETHOD(SetName)(const char* name) PURE;
  };

HRESULT __stdcall CreatePIOWin32(IPIOWin32**);

extern "C" const CLSID CLSID_PIOWin32;
extern "C" const IID IID_IPIOWin32;

#endif

/*****************************************************************************
  IPIOFileMapping - Implemention of IPIO for Win32 file mapping
*****************************************************************************/

#ifdef WIN32

struct IPIOFileMapping : IPIO
  {
  STDMETHOD(Open)(const char* path, ulong flags) PURE;
  };

HRESULT __stdcall CreatePIOFileMapping(IPIOFileMapping**);

extern "C" const CLSID CLSID_PIOFileMapping;
extern "C" const IID IID_IPIOFileMapping;

#endif

/*****************************************************************************
  IPIOMemBlk - Implementation of IPIO on top of IMemBlk
*****************************************************************************/

struct IPIOMemBlk : IPIO
  {
  STDMETHOD(Setup)(struct IMemBlk* memblk, ulong eof) PURE;
  STDMETHOD(SetName)(const char* name) PURE;
  };

HRESULT __stdcall CreatePIOMemBlk(IPIOMemBlk**);
HRESULT __stdcall CreatePIO_MemBlk(IPIO** p_pio, struct IMemBlk* memblk,
  ulong eof);

extern "C" const CLSID CLSID_PIOMemBlk;
extern "C" const IID IID_IPIOMemBlk;

/*****************************************************************************
  IPIOMemFilt - Implementation of IPIO using IMemFilt to filter
*****************************************************************************/

struct IPIOMemFilt : IPIO
  {
  STDMETHOD(Setup)(IPIO* pio, struct IMemFilt* filt, ulong bufsize) PURE;
  STDMETHOD(Flush)() PURE;
  };

HRESULT __stdcall CreatePIOMemFilt(IPIOMemFilt**);

extern "C" const CLSID CLSID_PIOMemFilt;
extern "C" const IID IID_IPIOMemFilt;

/*****************************************************************************
  IPIOMemory - Memory implementation of IPIO
*****************************************************************************/

struct IPIOMemory : IPIO
  {
  STDMETHOD(SetBlockBits)(int blockbits) PURE;
  };

HRESULT __stdcall CreatePIOMemory(IPIOMemory**);
HRESULT __stdcall CreatePIO_Memory(IPIO** p_pio, int blockbits);

extern "C" const CLSID CLSID_PIOMemory;
extern "C" const IID IID_IPIOMemory;

enum
  {
  IPIOMEMORY_ERROR = 0xE8320201,

  // Can't change block size once file contains data
  IPIOMEMORY_ERROR_HAS_DATA,
  };

/*****************************************************************************
  IPIOZDeflate & IPIOZInflate - Implementations using ZLIB compression
*****************************************************************************/

struct IPIOZDeflate : IPIO
  {
  STDMETHOD(Setup)(IPIO* pio, ulong bufsize, long level) PURE;
  STDMETHOD(Flush)() PURE;
  };

struct IPIOZInflate : IPIO
  {
  STDMETHOD(Setup)(IPIO* pio, ulong bufsize) PURE;
  STDMETHOD(Flush)() PURE;
  };

HRESULT __stdcall CreatePIOZDeflate(IPIOZDeflate**);
HRESULT __stdcall CreatePIOZInflate(IPIOZInflate**);

extern "C" const CLSID CLSID_PIOZDeflate;
extern "C" const CLSID CLSID_PIOZInflate;
extern "C" const IID IID_IPIOZDeflate;
extern "C" const IID IID_IPIOZInflate;

enum
  {
  IPIOZ_ERROR = 0xE8320301,

  // Can't switch between data-push and data-pull modes
  IPIOZ_ERROR_BAD_MODE,

  // Improper data or checksum mismatch
  IPIOZ_ERROR_DATA,
  };

/*****************************************************************************
  IPIODebug - Sends output to OutputDebugString()
*****************************************************************************/

HRESULT __stdcall CreatePIODebug(IPIO**);

extern "C" const CLSID CLSID_PIODebug;

/*****************************************************************************
  IStreamPIO - IStream on top of IPIO
*****************************************************************************/

struct IStreamPIO : IStream
  {
  STDMETHOD(SetPIO)(IPIO* pio) PURE;
  };

HRESULT __stdcall CreateStreamPIO(IStreamPIO**);
HRESULT __stdcall CreateStream_PIO(IStream** p_stm, IPIO* pio);

extern "C" const CLSID CLSID_StreamPIO;
extern "C" const IID IID_IStreamPIO;

/*****************************************************************************
  IPIOStream - IPIO on top of IStream
*****************************************************************************/

struct IPIOStream : IPIO
  {
  STDMETHOD(SetStream)(IStream* stm) PURE;
  };

HRESULT __stdcall CreatePIOStream(IPIOStream**);
HRESULT __stdcall CreatePIO_Stream(IPIO** p_pio, IStream* stm);

extern "C" const CLSID CLSID_PIOStream;
extern "C" const IID IID_IPIOStream;

/*****************************************************************************
  Helper functions
*****************************************************************************/

HRESULT __stdcall CreatePIO_Static(IPIO** p_pio, void* block, ulong size,
  ulong eof);

#ifdef WIN32
HRESULT __stdcall CreatePIO_Resource(IPIO** p_pio, HMODULE hModule,
  LPCTSTR lpType, LPCTSTR lpName, WORD wLanguage);
#endif

HRESULT __stdcall CreatePIO_Path(IPIO** p_pio, const char* path,
  ulong flags);

HRESULT __stdcall PIO_Copy(IPIO* src, IPIO* dest, ulong* p_count);

/*****************************************************************************
  IMIO
*****************************************************************************/

struct IMIO : IUnknown
  {
  STDMETHOD(LockBuffer)(void** p_buffer, ulong* p_size) PURE;
  STDMETHOD(UnlockBuffer)(ulong size) PURE;
  STDMETHOD(Seek)(IPIO_SEEK mode, long offset) PURE;
  STDMETHOD(Tell)(ulong* position) PURE;
  STDMETHOD(SetSize)(ulong size) PURE;
  STDMETHOD(Info)(IPIO_INFO* info) PURE;
  STDMETHOD(Flush)() PURE;
  STDMETHOD(Close)() PURE;
  };

/****************************************************************************/

#endif

/* EOF */
