//+---------------------------------------------------------------------------
//
//  Trinity Implementation
//  Copyright (C) Play Incorporated, 1995
//
//  File:     Request.H
//
//  Contents: Declaration of CRequest and related classes
//
//  Classes:
//
//  Notes:    The CRequest class is closely related to the CCommand class
//            used in the server-side implementation.  Any changes which
//            affect the placement of command, status, or routing information
//            in the ipc buffers must be made to both classes.
//
//  History:  july 28, 1995 cpdaniel  created
//
//----------------------------------------------------------------------------
#ifndef __REQUEST_H__
#define __REQUEST_H__

#ifndef __TRNOEM_h__
#include "trnoem.h"
#endif

#ifndef __AUTOCT_h__
#include "autoct.h"
#endif

class CRequest
{
  public:
    CRequest( DWORD DestSocket,
              DWORD ReplySocket,
              DWORD CommandCode,
              ITrnConnection* pConnection,
              DWORD SendBuffSize=128,
              DWORD RcvBuffSize=128 );

    virtual ~CRequest();

    HRESULT __stdcall Invoke();

    // Parameter insertion operators

    CRequest& operator << (char);
    CRequest& operator << (signed char);
    CRequest& operator << (unsigned char);
    CRequest& operator << (signed short);
    CRequest& operator << (unsigned short);
    CRequest& operator << (signed int);
    CRequest& operator << (unsigned int);
    CRequest& operator << (signed long);
    CRequest& operator << (unsigned long);
    CRequest& operator << (const char*);
    CRequest& operator << (const wchar_t*);
    CRequest& operator << (const STrnPlayList*);
    CRequest& operator << (const STrnTimeType*);

    // Result extraction operators

    CRequest& operator >> (char&);
    CRequest& operator >> (signed char&);
    CRequest& operator >> (unsigned char&);
    CRequest& operator >> (signed short&);
    CRequest& operator >> (unsigned short&);
    CRequest& operator >> (signed int&);
    CRequest& operator >> (unsigned int&);
    CRequest& operator >> (signed long&);
    CRequest& operator >> (unsigned long&);
    CRequest& operator >> (char*);
    CRequest& operator >> (wchar_t*);

    // Raw read/write
    void    __stdcall ResetReadPtr();
    void    __stdcall Read(LPVOID pBuffer, unsigned size);
    void    __stdcall ReadSwap(LPVOID pBuffer, unsigned size);
    void    __stdcall ReadWSwap(LPVOID pBuffer, unsigned size);

    void    __stdcall ResetWritePtr();
    void    __stdcall Write(LPVOID pBuffer, unsigned size);
    void    __stdcall WriteSwap(LPVOID pBuffer, unsigned size);
    void    __stdcall WriteWSwap(LPVOID pBuffer, unsigned size);

    // Status
    __inline  BOOL      Ok();
    __inline  DWORD     ParamSize();
    __inline  DWORD     ParamSpaceRemaining();
    __inline  DWORD     BytesRemaining();
    __inline  DWORD     ResponseFormat();

  private:
    typedef enum {STATE_NEW=0, STATE_BAD=1, STATE_INVOKED=2} ERequestState;

    ITrnConnection*     m_pConnection;

    ERequestState       m_state;
    DWORD               m_RespFormat;   // Response format code

    PSTrnMessageHeader  m_pSendBuff;
    LPVOID              m_pSendEnd;
    LPVOID              m_WritePtr;
    LPVOID              m_WriteResetPoint;
    DWORD               m_SendBuffSize;

    PSTrnMessageHeader  m_pRcvBuff;
    LPVOID              m_pRcvEnd;
    LPVOID              m_ReadPtr;
    LPVOID              m_ReadResetPoint;
    DWORD               m_RcvBuffSize;

    static DWORD        m_threadListenSocketTLSIndex;
    static bool         m_TLSAllocated;
};

//+---------------------------------------------------------------------------
//
//  Trinity Implementation
//  Copyright (C) Play Incorporated, 1995
//
//  Contents: Implementation of CRequest inline member functions
//
//  History:  August 1,		1995 cpdaniel  created
//            December 21,	1995 cmdaniel  updated for real ITrnConnection
//
//----------------------------------------------------------------------------
// Macro ReadBase -
#define ReadBase(v,t) { (v)=(*((t*)m_ReadPtr)); m_ReadPtr=(char*)m_ReadPtr+sizeof(t); }

// Macro WriteBase -
#define WriteBase(v,t) { (*((t*)m_WritePtr))=(v); m_WritePtr=(char*)m_WritePtr+sizeof(t); }

inline CRequest& CRequest::operator << (char dat)
{
  WriteBase(dat,char);
  return *this;
}

inline CRequest& CRequest::operator << (signed char dat)
{
  WriteBase(dat,signed char);
  return *this;
}

inline CRequest& CRequest::operator << (unsigned char dat)
{
  WriteBase(dat,unsigned char);
  return *this;
}

inline CRequest& CRequest::operator << (signed short dat)
{
  WriteBase(dat,signed short);
  return *this;
}

inline CRequest& CRequest::operator << (unsigned short dat)
{
  WriteBase(dat,unsigned short);
  return *this;
}

inline CRequest& CRequest::operator << (signed int dat)
{
  WriteBase(dat,signed int);
  return *this;
}

inline CRequest& CRequest::operator << (unsigned int dat)
{
  WriteBase(dat,unsigned int);
  return *this;
}

inline CRequest& CRequest::operator << (signed long dat)
{
  WriteBase(dat,signed long);
  return *this;
}

inline CRequest& CRequest::operator << (unsigned long dat)
{
  WriteBase(dat,unsigned long);
  return *this;
}

inline CRequest& CRequest::operator << (const char* str)
{
  size_t length=strlen(str);
  WriteBase(length,size_t);
  Write((void*)str,length);
  return *this;
}

inline CRequest& CRequest::operator << (const wchar_t* str)
{
  size_t length=wcslen(str);
  WriteBase(length,size_t);
  Write((void*)str,length*sizeof(wchar_t));
  return *this;
}

inline CRequest& CRequest::operator << (const STrnTimeType* pTime)
{
  WriteBase(pTime->baseTime,DWORD);
  WriteBase(pTime->trackNumber,DWORD);
  return *this;
}

inline CRequest& CRequest::operator >> (char& dat)
{
  ReadBase(dat,char);
  return *this;
}

inline CRequest& CRequest::operator >> (signed char& dat)
{
  ReadBase(dat,signed char);
  return *this;
}

inline CRequest& CRequest::operator >> (unsigned char& dat)
{
  ReadBase(dat,unsigned char);
  return *this;
}

inline CRequest& CRequest::operator >> (signed short& dat)
{
  ReadBase(dat,signed short);
  return *this;
}

inline CRequest& CRequest::operator >> (unsigned short& dat)
{
  ReadBase(dat,unsigned short);
  return *this;
}

inline CRequest& CRequest::operator >> (signed int& dat)
{
  ReadBase(dat,signed int);
  return *this;
}

inline CRequest& CRequest::operator >> (unsigned int& dat)
{
  ReadBase(dat,unsigned int);
  return *this;
}

inline CRequest& CRequest::operator >> (signed long& dat)
{
  ReadBase(dat,signed long);
  return *this;
}

inline CRequest& CRequest::operator >> (unsigned long& dat)
{
  ReadBase(dat,unsigned long);
  return *this;
}

inline CRequest& CRequest::operator >> (char* str)
{
  size_t length;
  ReadBase(length,size_t);
  Read(str,length);
  return *this;
}

inline CRequest& CRequest::operator >> (wchar_t* str)
{
  size_t length;
  ReadBase(length,size_t);
  Read(str,length*sizeof(wchar_t));
  return *this;
}

__inline BOOL CRequest::Ok()
{
  return m_state != STATE_BAD;
}

__inline DWORD CRequest::ResponseFormat()
{
  return m_RespFormat;
}

__inline DWORD CRequest::ParamSize()
// returns the value that would go into the DataLength field
// of the STrnMessageHeader
{
  return (DWORD)((char*)m_WritePtr -
                 (char*)m_pSendBuff -
                 sizeof(STrnMessageHeader));
}

__inline DWORD CRequest::ParamSpaceRemaining()
// returns the number of BYTEs remaining in the write buffer.
{
  if (STATE_NEW==m_state)
    return DWORD( LPBYTE(m_pSendEnd) - LPBYTE(m_WritePtr) );
  else
    return 0;
}

__inline DWORD CRequest::BytesRemaining()
// returns the number of BYTEs remaining in the read buffer.
{
  if (STATE_INVOKED==m_state)
    return DWORD( LPBYTE(m_pRcvEnd) - LPBYTE(m_ReadPtr) );
  else
    return 0;
}


#endif
// End of Request.h
