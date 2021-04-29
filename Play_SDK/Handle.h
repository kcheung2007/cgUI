#ifndef __handle__
#define __handle__

class Handle
{
  HANDLE  m_handle;

  public:
    Handle() 
      : m_handle(INVALID_HANDLE_VALUE) 
    {
    }

    Handle(HANDLE h) 
      : m_handle(h) 
    {
    }

    ~Handle() 
    { 
      CloseHandle(m_handle); 
    }

    operator HANDLE() 
    { 
      return m_handle; 
    }

    Handle& operator=(HANDLE h) 
    { 
      if (INVALID_HANDLE_VALUE != m_handle)
        CloseHandle(m_handle); 
      m_handle = h; 
      return *this; 
    }

    bool  Valid()
    {
      return INVALID_HANDLE_VALUE != m_handle;
    }

    void Close()
    {
      if (INVALID_HANDLE_VALUE != m_handle)
        CloseHandle(m_handle);
      m_handle = INVALID_HANDLE_VALUE;
    }
};

#endif
