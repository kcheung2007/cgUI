//+---------------------------------------------------------------------------
//
//  Trinity Implementation
//  Copyright (C) Play Incorporated, 1995
//
//  File:     PtrQueue.H
//
//  Contents: Declaration of PtrQueue class.
//
//  History:  January 29, 1996  CMDaniel created
//
//----------------------------------------------------------------------------
#ifndef __PTRQUEUE_H__
#define __PTRQUEUE_H__

class PtrQueue
{
  public:
    PtrQueue( long int MaxItems );
    virtual ~PtrQueue();

    BOOL __stdcall Add( void* Item, DWORD Timeout );
    void* __stdcall Remove( DWORD Timeout );
    BOOL __stdcall IsEmpty();

  private:
    void** __inline BumpPtr( void** Ptr );

    void**        QueueMem;       /* pointer to beginning of storage area */
    void**        QueueEnd;       /* pointer to highest addressed entry */
    long int      QueueSize;      /* Number of entries in the queue */
    void**        InPtr;          /* pointer to the most recently enqueued item */
    void**        OutPtr;         /* pointer to the least recently enqueued item */
    long int      NumItems;       /* number of items in the queue now */
    CRITICAL_SECTION LockCS;      /* protection for control variables */
    HANDLE        hReadEvent;     /* Event for DeQueue to wait on when queue is empty */
    HANDLE        hWriteEvent;    /* Event for EnQueue to wait on when queue is full */
};


#endif

// end of PtrQueue.h
