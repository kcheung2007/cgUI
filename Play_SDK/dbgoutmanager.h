// a class that lets one output selectable things to either a console or a window
#include "CStdCon.h"

class CDebugOutputManager
{
    CStdoutConsole *m_pConsole;
    DWORD           m_dwDebugMask;
public:
    CDebugOutputManager( LPSTR keyName )
    {
        m_pConsole = NULL;
        m_dwDebugMask = 0;
        HKEY hkey;
        if ( ERROR_SUCCESS == RegOpenKeyEx( HKEY_LOCAL_MACHINE, keyName, 0, KEY_READ, &hkey) )
        {
            DWORD dwType;
            DWORD dwSize = 4;
            char fileName[MAX_PATH];
            if ( ERROR_SUCCESS == RegQueryValueEx( hkey, "OutputDebugEnableMask", 0, &dwType, (LPBYTE)&m_dwDebugMask, &dwSize ) )
            {
                if ( m_dwDebugMask )
                {
                    dwSize = MAX_PATH;
                    if ( ERROR_SUCCESS == RegQueryValueEx( hkey, "OutputDebugFilename", 0, &dwType, (LPBYTE)fileName, &dwSize ) )
                    {
                        fileName[dwSize] = 0;
                        m_pConsole = new CStdoutConsole(fileName);
                    } else
                        m_pConsole = new CStdoutConsole(NULL);
                }
            }
            RegCloseKey( hkey );
        }
    };

    ~CDebugOutputManager()
    {
        if ( m_pConsole )
            delete m_pConsole;
    };

    void dbgprintf( DWORD dwMask, LPSTR pszFmt ... )
    {
#ifdef _DEBUG
        if ( dwMask & m_dwDebugMask )
#else
        if ( m_pConsole && ( dwMask & m_dwDebugMask ) )
#endif
        {
            va_list args;
            va_start( args, pszFmt );
            if ( m_pConsole )
                vprintf( pszFmt, args );
#ifdef _DEBUG
            else
            {
                char buffer[200];
                vsprintf( buffer, pszFmt, args );
                OutputDebugString( buffer );
            }
#endif
            va_end( args );
        }
    };

};

