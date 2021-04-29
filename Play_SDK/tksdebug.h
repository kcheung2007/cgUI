#ifndef INCLUDED_TKSDEBUG
#define INCLUDED_TKSDEBUG

#ifdef _DEBUG
#include <stdio.h>
#include <stdarg.h>
#define DECLARE_DBPRINTF \
void dbprintf( char *fmt, ... )         \
{                                       \
    char odsbuffer[200];                \
    va_list args;                       \
                                        \
    va_start( args, fmt );              \
                                        \
    wvsprintf( odsbuffer, fmt, args );   \
    OutputDebugString( odsbuffer );     \
    va_end( args );                     \
}
extern void dbprintf( char *fmt, ... );

#define DEBUG_BREAK         __asm { int 3 };

#else
// this turns off the "too many actual parameters for macro" warning that comes up
// in release builds
#pragma warning (disable:4002)
#define dbprintf( x ) /* nothing */
#define DECLARE_DBPRINTF      /* also nothing */
#define DEBUG_BREAK         ;
#endif


#endif // INCLUDED_TKSDEBUG
