#ifndef __INCLUDED_CSTDCON_H__
#define __INCLUDED_CSTDCON_H__

#include <stdio.h>
#include <fcntl.h>
#include <io.h>

//-----------------------------------------------------------------------------

// Debug stuff
//-----------------------------------------------------------------------------
class CStdoutConsole
{
public:
    CStdoutConsole( LPSTR filename=NULL ) // NULL means create a console
    {
        /* Allocate a console and connect it to STDOUT */
        int i;
        if ( !filename )
        {
            // Spark up a console.
            BOOL allocresult=AllocConsole();
//            assert(allocresult);

            ConsoleHandle = (long)GetStdHandle(STD_OUTPUT_HANDLE);
            COORD coord = { 80, 5000 };
            SetConsoleScreenBufferSize( GetStdHandle(STD_OUTPUT_HANDLE), coord );

            hCrt = _open_osfhandle(ConsoleHandle, _O_TEXT);
            hf = _fdopen( hCrt, "w" );

        } else
        {
            // Just burp into a file.
            hf = fopen(filename,"w");
        }
        prevstdout = *stdout;
        *stdout = *hf;
        i = setvbuf( stdout, NULL, _IONBF, 0 );
    };

    ~CStdoutConsole( )
    {
        *stdout = prevstdout;
        fclose( hf );
        FreeConsole();
    }

    long ConsoleHandle;
    int hCrt;
    FILE *hf,prevstdout;
};


#endif
