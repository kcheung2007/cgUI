/*****************************************************************************
  PLAY CONFIDENTIAL - Copyright 1999 Play Inc., All Rights Reserved.
   Project : Toolbox
      File : MRTools.h
   Purpose : Handy programming thingies
    8/3/99 : Created from CppTools.h & WinTools.h (Mark Riley)
*****************************************************************************/

#ifndef _MRTOOLS_H_
#define _MRTOOLS_H_

#ifndef BIT
#define BIT(x) (1<<(x))
#endif

typedef signed char schar;
typedef unsigned char uchar;
typedef unsigned short ushort;
typedef unsigned long ulong;
typedef unsigned int uint;
typedef __int64 int64;
typedef unsigned __int64 uint64;

extern HINSTANCE g_hInstance;

/*****************************************************************************
  Warnings
*****************************************************************************/

#pragma warning(3 :4001)
#pragma warning(3 :4019)
#pragma warning(3 :4032)
#pragma warning(3 :4057)
//#pragma warning(3 :4061)  // no case statement found for enumeration identifier
#pragma warning(3 :4092)
//#pragma warning(3 :4100)  // unreferenced formal parameter
#pragma warning(3 :4112)
#pragma warning(3 :4121)
#pragma warning(3 :4125)
//#pragma warning(3 :4127)  // conditional expression is constant
#pragma warning(3 :4128)
#pragma warning(3 :4130)
#pragma warning(3 :4131)
#pragma warning(3 :4132)
#pragma warning(3 :4134)
#pragma warning(3 :4152)
#pragma warning(3 :4189)
#pragma warning(3 :4200)
//#pragma warning(3 :4201)  // nonstandard extension used : nameless struct/union
#pragma warning(3 :4202)
#pragma warning(3 :4206)
#pragma warning(3 :4207)
#pragma warning(3 :4208)
#pragma warning(3 :4209)
#pragma warning(3 :4210)
#pragma warning(3 :4211)
#pragma warning(3 :4212)
#pragma warning(3 :4213)
#pragma warning(3 :4214)
#pragma warning(3 :4220)
#pragma warning(3 :4221)
#pragma warning(3 :4222)
#pragma warning(3 :4232)
#pragma warning(3 :4233)
#pragma warning(3 :4234)
#pragma warning(3 :4235)
#pragma warning(3 :4236)
#pragma warning(3 :4238)
#pragma warning(3 :4239)
#pragma warning(3 :4244)
#pragma warning(3 :4245)
#pragma warning(3 :4268)
#pragma warning(3 :4504)
#pragma warning(3 :4505)
#pragma warning(3 :4507)
//#pragma warning(3 :4514)  // unreferenced inline function has been removed 
#pragma warning(3 :4515)
#pragma warning(3 :4516)
#pragma warning(3 :4517)
#pragma warning(3 :4611)
#pragma warning(3 :4663)
#pragma warning(3 :4665)
#pragma warning(3 :4670)
#pragma warning(3 :4671)
#pragma warning(3 :4672)
#pragma warning(3 :4673)
#pragma warning(3 :4674)
#pragma warning(3 :4699)
#pragma warning(3 :4701)
#pragma warning(3 :4705)
//#pragma warning(3 :4706)  // assignment within conditional expression
#pragma warning(3 :4709)
//#pragma warning(3 :4710)  // inline not expanded
//#pragma warning(3 :4727)  // conditional expression is constant

/*****************************************************************************
  Debug Stuff
*****************************************************************************/

#ifdef _DEBUG
void _dprintf(const char* format, ...);
void _dbhr(const char* message, HRESULT hr);
#define DBOUT(x) OutputDebugString(x)
#define DBFMT(x) _dprintf x
#define DBHR(msg,hr) _dbhr(msg, hr)
#else
#define DBOUT(x) while (false)
#define DBFMT(x) while (false)
#define DBHR(msg,hr) while (false)
#endif

/*****************************************************************************
  C/C++ Stuff
*****************************************************************************/

#define ARRAY_COUNT(x) (sizeof(x) / sizeof(*(x)))
#define ZERO_STRUCT(x) memset((x), 0, sizeof(*(x)))

/****************************************************************************/

void __stdcall SetStringBuffer(char* buffer, int size, const char* s);
void __stdcall AppendStringBuffer(char* buffer, int size, const char* s);

//void GUID2String(const GUID* guid, char *string);

/****************************************************************************/

template<class T>
class ObjectOwner
  {
  T* m_obj;
public:
  ObjectOwner() { m_obj = 0; }
  ObjectOwner(T* obj) { m_obj = obj; }
  operator T*() throw() { return m_obj; }
  T** operator&() throw() { return &m_obj; }
  T* operator->() const throw() { return m_obj; }
  T& operator*() const throw() { return *m_obj; }
  void Destroy() throw() { if (m_obj) { delete m_obj; m_obj = 0; } }
  T* Detach() throw() { T* temp = m_obj; m_obj = 0; return temp; }
  T* Attach(T* obj) throw() { if (m_obj) delete m_obj; return m_obj = obj; }
  T* operator=(T* obj) throw() { return Attach(obj); }
  ~ObjectOwner() { if (m_obj) delete m_obj; }
  };

/****************************************************************************/

template <class T>
class ObjectHolder
  {
  T* m_obj;
  bool m_fOwner;
  void Delete() { if (m_obj && m_fOwner) delete m_obj; }
public:
  ObjectHolder() : m_obj(0) {}
  operator T*() throw() { return m_obj; }
  T* Get() const throw() { return m_obj; }
  T* operator->() const throw() { return m_obj; }
  T& operator*() const throw() { return *m_obj; }
  void Destroy() throw() { Delete();  m_obj = 0; }
  T* Detach() throw() { T* temp = m_obj; m_obj = 0; return temp; }
  ObjectHolder<T>& operator=(ObjectHolder<T>& x) throw()
    { m_obj = x.m_obj; m_fOwner = x.m_fOwner; x.m_fOwner = false; return *this; }
  void Set(T* obj, bool fOwner) throw() { Delete(); m_obj = obj; m_fOwner = fOwner; }
  ~ObjectHolder() { Delete(); }
  };

/****************************************************************************/

template<class T>
class ReleasableObject
  {
  T* m_obj;
public:
  ReleasableObject() { m_obj = 0; }
  ReleasableObject(T* obj) { m_obj = obj; }
  operator T*() throw() { return m_obj; }
  T** operator&() throw() { return &m_obj; }
  T* Get() const throw() { return m_obj; }
  T* operator->() const throw() { return m_obj; }
  T& operator*() const throw() { return *m_obj; }
  void Release() throw() { if (m_obj) { m_obj->Release(); m_obj = 0; } }
  T* Detach() throw() { T* temp = m_obj; m_obj = 0; return temp; }
  T* operator=(T* obj) throw() { if (m_obj) m_obj->Release(); return m_obj = obj; }
  ~ReleasableObject() { if (m_obj) m_obj->Release(); }
  };

/****************************************************************************/

template <class T>
inline void SimpleArrayInsert(T* array, int size, int index, int count = 1)
  {
  array += index;
  memmove(array + count, array, (size - index) * sizeof(T));
  }

template <class T>
inline void SimpleArrayDelete(T* array, int size, int index, int count = 1)
  {
  array += index;
  memmove(array, array + count, (size - count - index) * sizeof(T));
  }

template <class T>
inline void SimpleArrayMove(T* array, int src, int dest)
  {
  if (src != dest)
    {
    T temp = array[src];
    if (dest > src)
      SimpleArrayDelete(array, dest + 1, src);
    else
      SimpleArrayInsert(array, src, dest);
    array[dest] = temp;
    }
  }

/****************************************************************************/

template<class T>
class SimpleArrayOwner
  {
private:
  T* sao_array;
  void _Destroy() { if (sao_array) delete[] sao_array; }
public:
  SimpleArrayOwner() { sao_array = 0; }
  SimpleArrayOwner(SimpleArrayOwner<T> &sao) { sao_array = sao.Detach(); }
  ~SimpleArrayOwner() { _Destroy(); }
  void Destroy() throw() { if (sao_array) { delete[] sao_array; sao_array = 0; } }
  T* Allocate(int n) { _Destroy(); return sao_array = new T[n]; }
  operator T*() throw() { return sao_array; }
  T* Get() throw() { return sao_array; }
  T* Attach(T* array) throw() { _Destroy(); return sao_array = array; }
  T* Detach() throw() { T* temp = sao_array; sao_array = 0; return temp; }
  T* operator=(T* array) throw() { return Attach(array); }
  T* operator=(SimpleArrayOwner<T> &sao) throw() { return Attach(sao.Detach()); }
  };

/****************************************************************************/

template<class T>
class ArrayOwner
  {
public:
  typedef T type;
private:
  T* m_array;
  size_t m_size;
  void _Destroy() { if (m_array) delete[] m_array; }
public:
  ArrayOwner(const ArrayOwner<T>& x) {}
  void operator=(const ArrayOwner<T>& x) {}
  ArrayOwner() { m_array = 0; m_size = 0; }
  T* Allocate(size_t n) { _Destroy(); if (m_array = new T[n]) m_size = n; return m_array; }
  void Attach(T* array, size_t n) throw() { _Destroy(); m_array = array; m_size = n; }
  operator T*() throw() { return m_array; }
  size_t Size() throw() { return m_size; }
  T* Detach() throw() { T* temp = m_array; m_array = 0; m_size = 0; return temp; }
  void Destroy() throw() { if (m_array) { delete[] m_array; m_array = 0; m_size = 0; } }
  ~ArrayOwner() { _Destroy(); }
  };

/****************************************************************************/

class StringOwner
  {
protected:
  char* m_str;
  void _Destroy() { if (m_str) delete[] m_str; }
  static char _Null[];

public:
  StringOwner() { m_str = 0; }
  ~StringOwner() { _Destroy(); }

  void Destroy() { _Destroy(); m_str = 0; }

  operator char*() { return m_str; }
  char* operator ~() { return m_str ? m_str : _Null; }

  char* Set(const char* str);
  char* operator=(const char* str) { return Set(str); }

  char* Append(const char* str);
  char* operator+=(const char* str) { return Append(str); }

  char* Set(const char* str, int size);

  void Attach(char* str) { _Destroy(); m_str = str; }
  char* Detach() { char* temp = m_str; m_str = 0; return temp; }
  };

/****************************************************************************/

#include <unknwn.h>

template <class T>
class _NoAddRefReleaseOnPComPtr : public T
  {
private:
  STDMETHOD_(ULONG, AddRef)()=0;
  STDMETHOD_(ULONG, Release)()=0;
  };

template <class T>
class PComPtr  // Adapted from ATL...
  {
public:
  typedef T _PtrClass;
  PComPtr() { p = 0; }
  PComPtr(T* x) { if (p = x) p->AddRef(); }
  PComPtr(const PComPtr<T>& x) { if (p = x.p) p->AddRef(); }
  ~PComPtr() { if (p) p->Release(); }
  void Release() { T* x = p; if (x = p) { p = 0; x->Release(); } }
  operator T*() const { return p; }
  T& operator*() const { return *p; }
  T** operator&() { return &p; }
  _NoAddRefReleaseOnPComPtr<T>* operator->() const
    { return (_NoAddRefReleaseOnPComPtr<T>*)p; }
  T* Assign(T* x)
    { if (x) x->AddRef(); if (p) p->Release(); return p = x; }
  T* operator=(T* x) { return Assign(x); }
  T* operator=(const PComPtr<T>& x) { return Assign(x.p); }
  bool operator!() const { return !p; }
  bool operator==(T* x) const { return p == x; }
  void Attach(T* x) { if (p) p->Release(); p = x; }
  T* Detach() { T* x = p; p = 0; return x; }
  void Take(PComPtr<T>& x) { if (p) p->Release(); p = x.p; x.p = 0; }
  void CopyTo(T** ppT) { if (*ppT = p) p->AddRef(); }
  T* p;
  };

/****************************************************************************/

template<class T>
inline const T& Min(const T& x, const T& y)
  { return x < y ? x : y; }

template<class T>
inline const T& Max(const T& x, const T& y)
  { return x > y ? x : y; }

/****************************************************************************/

/*
#define BINARY_SEARCH(type,first,last,result,compare)                        \
  {                                                                          \
  type _f = first, _l = last;                                                \
  while (_f != _l)                                                           \
    {                                                                        \
    result = (_f + _l) >> 1;                                                 \
    if (compare) _f = result + 1; else _l = result;                          \
    }                                                                        \
  result = _f;                                                               \
  }

/****************************************************************************/

/*
#define BINARY_SORT_ITEM(type,first,last,from,to,compare,move)               \
  {                                                                          \
  BINARY_SEARCH(type,first,last,to,compare);                                 \
  if (from != to) move;                                                      \
  }

/****************************************************************************/

#define BINARY_SORT(type,first,last,compare,move)                            \
  do {                                                                       \
  type _first = first;                                                       \
  type _last = last;                                                         \
  type src;                                                                  \
  for (src = _first + 1; src < _last; src++)                                 \
    {                                                                        \
    type _low = _first;                                                      \
    type _high = src;                                                        \
    type dest;                                                               \
    while (_low != _high)                                                    \
      {                                                                      \
      dest = (_low + _high) >> 1;                                            \
      if (compare) _low = dest + 1; else _high = dest;                       \
      }                                                                      \
    dest = _low;                                                             \
    if (src != dest) move;                                                   \
    }                                                                        \
  } while (false)

/****************************************************************************/

template<class T>
class LockedObject
  {
  T* m_obj;
  LockedObject(const LockedObject<T>& x) {}
  void operator=(const LockedObject<T>& x) {}
public:
  LockedObject(T* obj) { (m_obj = obj)->LockObject(); }
  operator T*() throw() { return m_obj; }
  T* operator->() const throw() { return m_obj; }
  T& operator*() const throw() { return *m_obj; }
  ~LockedObject() { m_obj->UnlockObject(); }
  };

/****************************************************************************/

#define DECLARE_ILISTELEMENT(class)                            \
  class* &Next() { return *(class**)&IListElement::Next(); }   \
  class* &Prev() { return *(class**)&IListElement::Prev(); }

// Restriction: Needs to be first data member of derived class
class IListElement
  {
public:
  IListElement* m_next;
  IListElement* m_prev;

  IListElement* &Next() { return m_next; }
  IListElement* &Prev() { return m_prev; }

  bool IsBegin() { return !m_prev; }
  bool IsEnd() { return !m_next; }

  void InsertAfter(IListElement* e)
    {
    (m_next = e->m_next)->m_prev = this;
    (m_prev = e)->m_next = this;
    }
  void InsertBefore(IListElement* e)
    {
    (m_prev = e->m_prev)->m_next = this;
    (m_next = e)->m_prev = this;
    }

  void Remove()
    {
    (m_prev->m_next = m_next)->m_prev = m_prev;
    }
  };

template <class T>
class IList
  {
  IListElement m_begin;
  IListElement m_end;
  size_t m_count;

public:
  IList() : m_count(0)
    {
    m_begin.m_prev = 0;
    m_begin.m_next = &m_end;
    m_end.m_prev = &m_begin;
    m_end.m_next = 0;
    }

  T* Begin() { return static_cast<T*>(&m_begin); }
  T* End() { return static_cast<T*>(&m_end); }

  T* First() { return Next(Begin()); }
  T* Last() { return Prev(End()); }

  size_t Count() { return m_count; }

  void ElementInserted() { m_count++; }
  void ElementRemoved() { m_count--; }

  void InsertAfter(T* element, T* after)
    { element->InsertAfter(after); ElementInserted(); }
  void InsertBefore(T* element, T* before)
    { element->InsertBefore(before); ElementInserted(); }

  void InsertFirst(T* element) { InsertAfter(element, Begin()); }
  void InsertLast(T* element) { InsertBefore(element, End()); }

  void Remove(T* element)
    { element->Remove(); ElementRemoved(); }

  T* RemoveFirst()
    { T* element = First(); Remove(element); return element; }
  T* RemoveLast()
    { T* element = Last(); Remove(element); return element; }

  T* Next(T* element) { return static_cast<T*>(element->Next()); }
  T* Prev(T* element) { return static_cast<T*>(element->Prev()); }
  };

/****************************************************************************/

template <class T>
class INextList
  {
  T* m_first;
  T* m_last;
  size_t m_count;

  void ElementInserted() { m_count++; }
  void ElementRemoved() { m_count--; }

public:
  INextList() : m_first(0), m_last(0), m_count(0) {}

  size_t Count() { return m_count; }

  T* First() { return m_first; }
  T* Last() { return m_last; }

  void InsertFirst(T* element)
    {
    if (!(element->Next() = m_first))
      m_last = element;
    m_first = element;
    ElementInserted(); 
    }

  void InsertLast(T* element)
    {
    element->Next() = 0;
    if (m_last)
      m_last->Next() = element;
    else
      m_first = element;
    m_last = element;
    ElementInserted(); 
    }

  void InsertAfter(T* element, T* after)
    {
    if (!(element->Next() = after->Next()))
      m_last = element;
    after->Next() = element;
    ElementInserted();
    }

  T* RemoveFirst()
    {
    T* element = First();
    if (!(m_first = element->Next()))
      m_last = 0;
    ElementRemoved();
    return element;
    }

  T* Next(T* element) { return static_cast<T*>(element->Next()); }
  };

/****************************************************************************/

template <class T>
class NListElement
  {
private:
  T* nle_next;
  T* nle_prev;

public:
  T* &Next() { return nle_next; }
  T* &Prev() { return nle_prev; }
  };

template <class T>
class NList
  {
private:
  T* nl_first;
  T* nl_last;
  int nl_count;

public:
  NList() : nl_first(0), nl_last(0), nl_count(0) {}

  T* &First() { return nl_first; }
  T* &Last() { return nl_last; }

  int Count() { return nl_count; }

  inline void InsertFirst(T* element)
    {
    if (element->Next() = nl_first)
      nl_first->Prev() = element;
    else
      nl_last = element;
    nl_first = element;
    element->Prev() = 0;
    nl_count++;
    }

  inline void InsertAfter(T* element, T* after)
    {
    T* next = after->Next();
    if (element->Next() = next)
      next->Prev() = element;
    else
      nl_last = element;
    after->Next() = element;
    element->Prev() = after;
    nl_count++;
    }

  inline void InsertLast(T* element)
    {
    if (element->Prev() = nl_last)
      nl_last->Next() = element;
    else
      nl_first = element;
    nl_last = element;
    element->Next() = 0;
    nl_count++;
    }

  inline void InsertBefore(T* element, T* before)
    {
    T* prev = before->Prev();
    if (element->Prev() = prev)
      prev->Next() = element;
    else
      nl_first = element;
    before->Prev() = element;
    element->Next() = before;
    nl_count++;
    }

  inline void Remove(T* element)
    {
    if (element->Prev())
      element->Prev()->Next() = element->Next();
    else
      nl_first = element->Next();
    if (element->Next())
      element->Next()->Prev() = element->Prev();
    else
      nl_last = element->Prev();
    nl_count--;
    }
  };

/*****************************************************************************
  SUnknown - Simple IUnknown implementation
*****************************************************************************/

struct SUnknown : IUnknown
  {
  SUnknown() : m_refcount(1) {}
  virtual ~SUnknown();

  STDMETHOD_(ULONG,AddRef)();
  STDMETHOD_(ULONG,Release)();
  STDMETHOD(QueryInterface)(REFIID iid, void **ppv);

protected:
  LONG m_refcount;
  virtual void DeleteMe();
  };

#define DECLARE_SUNKNOWN                                               \
  STDMETHOD(QueryInterface)(REFIID iid, void **ppv);                       \
  STDMETHODIMP_(ULONG) AddRef() { return SUnknown::AddRef(); }             \
  STDMETHODIMP_(ULONG) Release() { return SUnknown::Release(); }

/*****************************************************************************
  SmallItemAllocatorBase - Allocates lots of little fixed sized blocks
*****************************************************************************/

struct SmallItemAllocatorBase
  {
  SmallItemAllocatorBase(uint size, uint alignment, uint multiple);
  ~SmallItemAllocatorBase();

  void Close();

  void* New();
  void Delete(void* o);

  // Override these functions to allocate blocks from a
  // different heap (defaults to using malloc()/free())
  virtual void* AllocateMemory(uint size);
  virtual void FreeMemory(void* m);

protected:
  struct Block
    {
    Block* next;
    void* original;
    };

  struct Item
    {
    Item* next;
    };

  uint m_mask;
  uint m_size;
  uint m_base;
  uint m_allocate;

  Block* m_blocks;
  Item* m_free;
  };

template <class T>
struct SmallItemAllocator : SmallItemAllocatorBase
  {
  SmallItemAllocator(uint alignment, uint multiple) :
    SmallItemAllocatorBase(sizeof(T), alignment, multiple)
      {}
  T* New() { return (T*)SmallItemAllocatorBase::New(); }
  void Delete(T* o) { SmallItemAllocatorBase::Delete(o); }
  };

/*****************************************************************************
  Byte Order Stuff
*****************************************************************************/

#ifdef _M_IX86

#pragma warning(disable:4035)  

inline short SwapOrder(short x)
  {
  _asm mov ax,[x]
  _asm rol ax,8
  }

inline ushort SwapOrder(ushort x)
  {
  _asm mov ax,[x]
  _asm rol ax,8
  }

inline long SwapOrder(long x)
  {
  _asm mov eax,[x]
  _asm bswap eax
  }

inline ulong SwapOrder(ulong x)
  {
  _asm mov eax,[x]
  _asm bswap eax
  }

inline int64 SwapOrder(int64 x)
  {
  _asm mov edx,[dword ptr x]
  _asm mov eax,[dword ptr x + 4]
  _asm bswap edx
  _asm bswap eax
  }

inline uint64 SwapOrder(uint64 x)
  {
  _asm mov edx,[dword ptr x]
  _asm mov eax,[dword ptr x + 4]
  _asm bswap edx
  _asm bswap eax
  }

#pragma warning(default:4035)  

inline short MotorolaOrder(short x) { return SwapOrder(x); }
inline ushort MotorolaOrder(ushort x) { return SwapOrder(x); }
inline long MotorolaOrder(long x) { return SwapOrder(x); }
inline ulong MotorolaOrder(ulong x) { return SwapOrder(x); }
inline int64 MotorolaOrder(int64 x) { return SwapOrder(x); }
inline uint64 MotorolaOrder(uint64 x) { return SwapOrder(x); }

inline short IntelOrder(short x) { return x; }
inline ushort IntelOrder(ushort x) { return x; }
inline long IntelOrder(long x) { return x; }
inline ulong IntelOrder(ulong x) { return x; }
inline int64 IntelOrder(int64 x) { return x; }
inline uint64 IntelOrder(uint64 x) { return x; }

inline void SwapOrder(short* x)
  {
  _asm mov edx,[x]
  _asm mov ax,[edx]
  _asm rol ax,8
  _asm mov [edx],ax
  }

inline void SwapOrder(ushort* x)
  {
  _asm mov edx,[x]
  _asm mov ax,[edx]
  _asm rol ax,8
  _asm mov [edx],ax
  }

inline void SwapOrder(long* x)
  {
  _asm mov edx,[x]
  _asm mov eax,[edx]
  _asm bswap eax
  _asm mov [edx],eax
  }

inline void SwapOrder(ulong* x)
  {
  _asm mov edx,[x]
  _asm mov eax,[edx]
  _asm bswap eax
  _asm mov [edx],eax
  }

inline void SwapOrder(int64* x)
  {
  _asm mov edx,[x]
  _asm mov eax,[edx]
  _asm mov ebx,[edx + 4]
  _asm bswap eax
  _asm bswap ebx
  _asm mov [edx + 4],eax
  _asm mov [edx],ebx
  }

inline void SwapOrder(uint64* x)
  {
  _asm mov edx,[x]
  _asm mov eax,[edx]
  _asm mov ebx,[edx + 4]
  _asm bswap eax
  _asm bswap ebx
  _asm mov [edx + 4],eax
  _asm mov [edx],ebx
  }

inline void MotorolaOrder(short* x) { SwapOrder(x); }
inline void MotorolaOrder(ushort* x) { SwapOrder(x); }
inline void MotorolaOrder(long* x) { SwapOrder(x); }
inline void MotorolaOrder(ulong* x) { SwapOrder(x); }
inline void MotorolaOrder(int64* x) { SwapOrder(x); }
inline void MotorolaOrder(uint64* x) { SwapOrder(x); }

inline void IntelOrder(short* x) { }
inline void IntelOrder(ushort* x) { }
inline void IntelOrder(long* x) { }
inline void IntelOrder(ulong* x) { }
inline void IntelOrder(int64* x) { }
inline void IntelOrder(uint64* x) { }

#else

#error ??? Need to supply non-Intel implementations

#endif

/*****************************************************************************
  Windows Stuff
*****************************************************************************/

#ifdef _WINDOWS_

/****************************************************************************/

const char* __stdcall JustWantFileName(const char* path);
void __stdcall AdjustComboBoxRect(HWND hWnd);
void __stdcall GetRectInParent(HWND hWnd, RECT* r);

/****************************************************************************/

class CriticalSection
  {
  CRITICAL_SECTION m_crit;

public:
  CriticalSection() { InitializeCriticalSection(&m_crit); }
  ~CriticalSection() { DeleteCriticalSection(&m_crit); }
  void Lock() { EnterCriticalSection(&m_crit); }
  void Unlock() { LeaveCriticalSection(&m_crit); }
  };

/****************************************************************************/

class LockCriticalSection
  {
  CriticalSection* m_crit;

public:
  LockCriticalSection(CriticalSection &ref) : m_crit(&ref) { m_crit->Lock(); }
  LockCriticalSection(CriticalSection* crit) : m_crit(crit) { m_crit->Lock(); }
  ~LockCriticalSection() { m_crit->Unlock(); }
  };

/****************************************************************************/

class ObjectCriticalSection
  {
protected:
  CriticalSection m_crit;

public:
  void LockObject() { m_crit.Lock(); }
  void UnlockObject() { m_crit.Unlock(); }
  };

/****************************************************************************/

struct InitializeCOM
  {
  InitializeCOM() { CoInitialize(0); }
  ~InitializeCOM() { CoUninitialize(); }
  };

/****************************************************************************/

struct PBaseWindow
  {
  PBaseWindow();
  virtual ~PBaseWindow();

  virtual void __stdcall Destroy();

  virtual const char*  __stdcall GetWindowClassName() = 0;

  HRESULT __stdcall Create(HWND parent, RECT* r);
  virtual HRESULT __stdcall Create2(WNDCLASSEX* wc, CREATESTRUCT* cs);

  HWND m_hWnd;
  operator HWND() { return m_hWnd; }

  static LRESULT CALLBACK WndProc(
    HWND hWnd,
    UINT uMsg,
    WPARAM wParam,
    LPARAM lParam);

  virtual LRESULT __stdcall ProcessMessage(
    UINT uMsg,
    WPARAM wParam,
    LPARAM lParam);
  };

/****************************************************************************/

#endif
#endif

/* EOF */
