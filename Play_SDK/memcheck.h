/* memcheck.h : include file to do memory tracing */

#ifdef TRACE_OBJECT_MEMORY
#include "crtdbg.h"
#define INIT_MEMCHECK _CrtMemState memChk; _CrtMemCheckpoint( &memChk );

#ifdef MEM_STATS_ONLY
#define MEMCHECK(x) { OutputDebugString( x ); \
         _CrtMemState memNow,memDiff; \
         _CrtMemCheckpoint( &memNow ); \
         if ( _CrtMemDifference( &memDiff, &memChk, &memNow ) )\
            _CrtMemDumpStatistics( &memDiff );\
        _CrtMemCheckpoint( &memChk ); }
#define MEMCHECK1(x,y) { dbprintf( x,y ); \
         _CrtMemState memNow,memDiff;\
         _CrtMemCheckpoint( &memNow );\
         if ( _CrtMemDifference( &memDiff, &memChk, &memNow ) )\
            _CrtMemDumpStatistics( &memDiff );\
        _CrtMemCheckpoint( &memChk ); }
#else
#define MEMCHECK(x) { OutputDebugString( x ); \
        _CrtMemDumpAllObjectsSince( &memChk ); \
        _CrtMemCheckpoint( &memChk ); }
#define MEMCHECK1(x,y) { dbprintf( x,y ); \
        _CrtMemDumpAllObjectsSince( &memChk ); \
        _CrtMemCheckpoint( &memChk ); }
#endif

#else
#define INIT_MEMCHECK ;
#define MEMCHECK(x) ;
#define MEMCHECK1(x,y) ;
#endif

