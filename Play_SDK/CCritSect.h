// just a simple class to make critical sections easier
#ifndef __INCLUDED_CCRITSECT_H
#define __INCLUDED_CCRITSECT_H

class CCriticalSection
{
public:
    
    CCriticalSection() 
        { 
            InitializeCriticalSection(&m_CritSect); 
        };
    ~CCriticalSection()
        { 
            DeleteCriticalSection(&m_CritSect); 
        };

    void Enter()
        { 
            EnterCriticalSection(&m_CritSect); 
        };
    void Leave()
        { 
            LeaveCriticalSection(&m_CritSect); 
        };
private:
    CRITICAL_SECTION    m_CritSect;
};

class CSmartScopeCriticalSection
{
    CCriticalSection *m_pCritSect;
public:
    CSmartScopeCriticalSection( CCriticalSection *pCritSect )
    {
        m_pCritSect = pCritSect;
        m_pCritSect->Enter();
    };
    CSmartScopeCriticalSection( CCriticalSection& rCritSect )
    {
        m_pCritSect = &rCritSect;
        m_pCritSect->Enter();
    };

    ~CSmartScopeCriticalSection()
    {
        m_pCritSect->Leave();
    };
};


#endif
