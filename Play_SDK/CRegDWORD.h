#ifndef __REGISTRY_SHADOWED_DWORD_H__
#define __REGISTRY_SHADOWED_DWORD_H__

// CRegDWORD.h - Created 5/6/98 by T.Sprague

// a class to load a DWORD's value from the registry when it's created, and store it again when
// it's destroyed.  It persists this variable's value.

class CRegistryShadowedDWORD
{
    DWORD   m_dwValue;
    HKEY    m_hMainKey;
    LPSTR   m_pszKeyname;
    LPSTR   m_pszValuename;

    HKEY OpenKey( REGSAM access )
    {
        HKEY hkey = NULL;

        DWORD dwDisp;
        if ( ERROR_SUCCESS != RegCreateKeyEx( m_hMainKey, m_pszKeyname, 0, 0, 0, access, NULL, &hkey, &dwDisp ) )
            hkey = NULL;

        return( hkey );
    };

public:
    CRegistryShadowedDWORD( HKEY mainkey, LPSTR keyname, LPSTR valuename, DWORD dwDefaultValue )
    {
        m_dwValue = dwDefaultValue; // in case it's not in the registry yet

        m_pszKeyname = new char[strlen(keyname)+1];
        strcpy( m_pszKeyname, keyname );

        m_pszValuename = new char[strlen(valuename)+1];
        strcpy( m_pszValuename, valuename );
        
        m_hMainKey = mainkey;

        HKEY hkey = OpenKey( KEY_READ );
        if ( hkey )
        {
            DWORD dwType, dwSize=sizeof(DWORD);
            RegQueryValueEx( hkey, m_pszValuename, 0, &dwType, (BYTE*)&m_dwValue, &dwSize );
            RegCloseKey( hkey );
        }
    };

    virtual ~CRegistryShadowedDWORD()
    {
        HKEY hkey = OpenKey( KEY_WRITE );
        if ( hkey )
        {
            RegSetValueEx( hkey, m_pszValuename, 0, REG_DWORD, (BYTE*)&m_dwValue, sizeof(DWORD) );
            RegCloseKey( hkey );
        }

        if ( m_pszKeyname )
            delete []m_pszKeyname;
        if ( m_pszValuename )
            delete []m_pszValuename;
    };

    DWORD Set( DWORD dwNewValue )
    {
        m_dwValue = dwNewValue;
        return( m_dwValue );
    };

    DWORD Value()
    {
        return( m_dwValue );
    };

    operator=( DWORD value )
    {
        return( m_dwValue = value );
    };

    operator DWORD ()
    {
        return( m_dwValue );
    };
};


class CRegistryShadowedSTRING
{
    //LPSTR   m_pszValue;
    char	m_pszValue[MAX_PATH];
    HKEY    m_hMainKey;
    LPSTR   m_pszKeyname;
    LPSTR   m_pszValuename;

    HKEY OpenKey( REGSAM access )
    {
        HKEY hkey = NULL;

        DWORD dwDisp;
        if ( ERROR_SUCCESS != RegCreateKeyEx( m_hMainKey, m_pszKeyname, 0, "REG_SZ", 0, access, NULL, &hkey, &dwDisp ) )
            hkey = NULL;

        return( hkey );
    };

public:
    CRegistryShadowedSTRING( HKEY mainkey, LPSTR keyname, LPSTR valuename, LPSTR defaultValue )
    {
        //m_pszValue = new char[strlen(defaultValue)+1];
        strcpy( m_pszValue, defaultValue );

        m_pszKeyname = new char[strlen(keyname)+1];
        strcpy( m_pszKeyname, keyname );

        m_pszValuename = new char[strlen(valuename)+1];
        strcpy( m_pszValuename, valuename );
        
        m_hMainKey = mainkey;

        HKEY hkey = OpenKey( KEY_READ );
        if ( hkey )
        {
            DWORD dwType, dwSize=MAX_PATH;
            RegQueryValueEx( hkey, m_pszValuename, 0, &dwType, (BYTE*)m_pszValue, &dwSize );
            RegCloseKey( hkey );
        }
    };

    virtual ~CRegistryShadowedSTRING()
    {
        HKEY hkey = OpenKey( KEY_WRITE );
        if ( hkey )
        {
            RegSetValueEx( hkey, m_pszValuename, 0, REG_SZ, (BYTE*)m_pszValue, strlen(m_pszValue)+1 );
            RegCloseKey( hkey );
        }

        if ( m_pszKeyname )
            delete []m_pszKeyname;
        if ( m_pszValuename )
            delete []m_pszValuename;
        //if ( m_pszValue )
        //    delete []m_pszValue;
    };

    LPSTR Set( LPSTR NewValue )
    {
        //if ( m_pszValue )
        //    delete []m_pszValue;
		//m_pszValue = new char[strlen(NewValue)+1];
        strcpy( m_pszValue, NewValue );

        return( m_pszValue );
    };

    LPSTR Value()	// This may not work...
    {
        return( m_pszValue );
    };

};

#endif