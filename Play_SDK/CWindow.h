#ifndef __INCLUDED_CWINDOW_H__
#define __INCLUDED_CWINDOW_H__
#include <wtypes.h>

class CWindow
{
public:
    CWindow() { m_hWnd = NULL; };
    virtual ~CWindow() { if ( m_hWnd ) { DestroyWindow(m_hWnd); m_hWnd = NULL; } };

    virtual BOOL SetWindowPos( HWND hWndOther, int x, int y, int w, int h, UINT flags )
    {
        return( ::SetWindowPos( m_hWnd, hWndOther, x,y, w,h, flags ) );
    }

    virtual LRESULT UseWindowMessage( HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam )
    {
        return( DefWindowProc( hWnd, uMsg, wParam, lParam ) );
    }

    BOOL CreateWnd( LPSTR title, DWORD dwStyle, long x,long y, long w, long h, HWND hWnd, HINSTANCE hInstance )
    {
        if ( !m_hWnd )
        {
            WNDCLASS wndclass;
            memset( &wndclass, 0, sizeof(WNDCLASS) );

            wndclass.style = CS_OWNDC|CS_HREDRAW|CS_VREDRAW; 
            wndclass.lpfnWndProc = (WNDPROC)CWindow::WndProc; 
            wndclass.hInstance = hInstance; 
            wndclass.lpszClassName="PLAYWNDCLASS"; 
            RegisterClass( &wndclass );

            m_hWnd = CreateWindow( "PLAYWNDCLASS",title,dwStyle,x,y,w,h,hWnd,NULL,hInstance,(LPVOID)this );
        }
        return( m_hWnd != NULL );
    };

//protected:
    HWND m_hWnd;

private:
    static LRESULT CALLBACK WndProc( HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam )
    {
        if ( uMsg == WM_CREATE )
        {
            CREATESTRUCT *lpcs = (CREATESTRUCT*)lParam;
            CWindow *ths = (CWindow *)lpcs->lpCreateParams;
            SetWindowLong( hWnd, GWL_USERDATA, (long)ths );
            return( ths->UseWindowMessage(  hWnd, uMsg, wParam, lParam ) );
        }

        CWindow *ths = (CWindow *)GetWindowLong( hWnd, GWL_USERDATA );
        if ( ths )
            return( ths->UseWindowMessage(  hWnd, uMsg, wParam, lParam ) );
        else
            return( DefWindowProc(  hWnd, uMsg, wParam, lParam ) );
    };

};

#endif //__INCLUDED_CWINDOW_H__
