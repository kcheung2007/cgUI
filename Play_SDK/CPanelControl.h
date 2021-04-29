class CPanelControl
{
public:
    IPlayPanel *m_pPanel;
    CPanelControl( LPSTR name, HRESULT *pHr )
    {
        HRESULT hr = CoCreateInstance( CLSID_CPlayPanel, 0, CLSCTX_INPROC_SERVER, IID_IPlayPanel, (void**)&m_pPanel );
        if ( SUCCEEDED(hr) && name )
            m_pPanel->SetName( (BYTE*)name );

        if ( pHr )
            *pHr = hr;
    };
    HRESULT AddControl( IPlayControl *pipc, DWORD dwFlags )
    {
        return( m_pPanel->AddControl( pipc, dwFlags ) );
    };
    HRESULT AddToPanel( IPlayPanel *pPanel, long cx, long cy, DWORD dwFlags )
    {
        if ( !m_pPanel )
            return( E_FAIL );

        HRESULT hr;
        IPlayControl *pipc;
        if ( SUCCEEDED( hr = m_pPanel->QueryInterface( IID_IPlayControl, (void**)&pipc ) ) )
        {
            SIZE sz = { cx, cy };
            pipc->SuggestSize( SIZE_WINDOW, &sz );
            pPanel->AddControl( pipc, dwFlags );
            pipc->Release();
        }
        return( hr );
    };
    HRESULT AddToPanel( IPlayPagedPanel *pPanel, DWORD dwPage, long cx, long cy, DWORD dwFlags )
    {
        if ( !m_pPanel )
            return( E_FAIL );

        HRESULT hr;
        IPlayControl *pipc;
        if ( SUCCEEDED( hr = m_pPanel->QueryInterface( IID_IPlayControl, (void**)&pipc ) ) )
        {
            SIZE sz = { cx, cy };
            pipc->SuggestSize( SIZE_WINDOW, &sz );
            pPanel->AddControl( dwPage, pipc, dwFlags );
            pipc->Release();
        }
        return( hr );
    };
    virtual ~CPanelControl( void )
    {
        if ( m_pPanel )
            m_pPanel->Release();
    };

    IPlayControl *Control()
    {
        IPlayControl *pipc;
        if ( SUCCEEDED( m_pPanel->QueryInterface( IID_IPlayControl, (void**)&pipc ) ) )
        {
            pipc->Release();
            return( pipc );
        }
        return( NULL );
    };

    IPlayPanel *Panel()
    {
        return( m_pPanel );
    };

};

