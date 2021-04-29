// =====================================================================
// Smart Pointer COM helper class
// 
// (C) 1997 Play Incorporated, all rights reserved
//
// CP Daniel  October 16, 1997
// =====================================================================
#ifndef __smartptr_h__
#define __smartptr_h__

typedef enum {NoAddRef} PtrRefEnum;

template <class T> class Ptr
{
  T*  m_p;

  public:
    // Default constructor - create with a NULL pointer
    Ptr()
      : m_p(0)
    {
    }

    // Copy constructor.  Referenced object (if any) is AddRef'd
    Ptr(Ptr<T>& p)
      : m_p(p.m_p)
    {
      if (m_p)
        m_p->AddRef();
    }

    // Conversion from T*  Referenced object (if any) is AddRef'd
    Ptr(T* p)
      : m_p(p)
    {
      if (m_p)
        m_p->AddRef();
    }

    // Conversion from T*  Referenced object is not AddRef'd
    Ptr(T* p, PtrRefEnum)
      : m_p(p)
    {
    }

    // Destructor 
    ~Ptr()
    {
      if (m_p)
        m_p->Release();
    }

    // Equality operator
    bool operator==(const Ptr<T>& p) const
    {
      return m_p == p.m_p;
    }

    bool operator==(const T* p) const
    {
      return m_p == p;
    }

    // Inequality operator
    bool operator!=(const Ptr<T>& p) const
    {
      return m_p != p.m_p;
    }

    bool operator!=(const T* p) const
    {
      return m_p != p;
    }

    // Native assignment operator
    Ptr& operator=(const Ptr<T>& p)
    {
      if (m_p != p.m_p)
      {
        if (m_p)
          m_p->Release();
        m_p = p.m_p;
        if (m_p)
          m_p->AddRef();
      }
      return *this;
    }

    // Assignment from T*  Referenced object IS AddRef'd
    // (compare with Set(), below)
    Ptr& operator=(T* const p )
    {
      if (m_p != p)
      {
        if (m_p)
          m_p->Release();
        m_p = p;
        if (m_p)
          m_p->AddRef();
      }
      return *this;
    }

    // Transfer of ownership from Ptr<T> - the object is not addref'd or released
    // rhs will be zero'd!
    //
    // Granted, this does stretch the rules about overloading operators only
    // when the original semantics are more or less preserved.  Think of this as
    // "shifting ownership" from one Ptr<T> to another...
    Ptr& operator <<= (Ptr& rhs)
    {
      if (m_p)
        m_p->Release();
      m_p = rhs.m_p;
      rhs.m_p = 0;
      return *this;
    }

    // Conversion to void**  Returns naked reference to internal pointer.
    // Any existing reference is Release'd and zeroed.  Suitable for passing
    // to void** parameters of functions like CoCreateInstance() which return
    // pointers indirectly.
    // This function is the "left half" of an assignment!
    operator void**()
    {
      if (m_p)
      {
        m_p->Release();
        m_p = 0;
      }
      return (void**)&m_p;
    }

    // Conversion to T**.  Returns typed reference to internal pointer.
    // Any existing reference is Release'd and zeroed.  Suitable for passing
    // to T** parameters of functions which return pointers indirectly.
    // This function is the "left half" of an assignment!
    operator T**()
    {
      if (m_p)
      {
        m_p->Release();
        m_p = 0;
      }
      return &m_p;
    }

    // const dereference operator
    const T* operator ->() const
    {
      return m_p;
    }

    // non-const dereference operator
    T* operator->()
    {
      return m_p;
    }

    // conversion to T* - copied pointer is NOT AddRef'd
    operator T*() const
    {
      return m_p;
    }

    // conversion to T* - copied pointer IS AddRef'd
    T* Ref() const
    {
      if (m_p)
        m_p->AddRef();
      return m_p;
    }

    // Assignment from T* - copied pointer IS NOT AddRef'd
    // (compare with operator=(), above)
    Ptr& Set(T* p)
    {
      if (m_p)
        m_p->Release();
      m_p = p;
      return *this;
    }

    // Unary dereference operator
    T& operator*()
    {
      return *m_p;
    }

    // const unary dereference operator
    const T& operator*() const
    {
      return *m_p;
    }

    // Test for NULL
    bool IsNull() const
    {
      return !m_p;
    }

    // Basically, shorthand for IsNull()
    bool operator!() const
    {
      return !m_p;
    }

    // conversion to bool
    operator bool() const
    {
      return !!m_p;
    }
};

#endif

// End of SmartPtr.h
