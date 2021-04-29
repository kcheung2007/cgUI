#include "stdlib.h"
#include "search.h"

template <class T> class CClassList
{
    T **        m_ppList;
    long        m_lArraySize;
    long        m_lNumObjects;
    BOOL        m_bKillList;

private:
    CClassList( CClassList& rCopyFrom ); // disabled copy constructor

public:
    CClassList( )
    {
        m_lArraySize = 0;
        m_ppList = NULL;
        m_lNumObjects = 0;
        m_bKillList = TRUE;
    };

    virtual ~CClassList()
    {
        if ( m_bKillList )
        {
            for ( long i=0; i<m_lNumObjects; i++ )
                if ( m_ppList[i] )
                    delete m_ppList[i];
        }
        delete []m_ppList;
    };

    long Size()
    {
        return( m_lNumObjects );
    };

    void RemoveMember( long index )
    {
        if ( index >= 0 && index < m_lNumObjects )
        {
            if ( m_bKillList )
                delete m_ppList[index];
            m_lNumObjects--;
            for ( long j=index; j<m_lNumObjects; j++ )
                m_ppList[j] = m_ppList[j+1];
        }
    };

    void RemoveMember( T *member )
    {
        for ( long i=0; i<m_lNumObjects; i++ )
        {
            if ( m_ppList[i] == member )
            {
                if ( m_bKillList )
                    delete m_ppList[i];
                m_lNumObjects--;
                for ( long j=i; j<m_lNumObjects; j++ )
                    m_ppList[j] = m_ppList[j+1];
                break;
            }
        }
    };

    void AddMember( T *pObj )
    {
        if ( m_lNumObjects == m_lArraySize )
        {
            m_lArraySize = max( 10, 2*m_lArraySize );
            T **ppNewList = new T*[m_lArraySize];
            if ( m_ppList )
            {
                memcpy( ppNewList, m_ppList, m_lNumObjects*sizeof(T*) );
                delete []m_ppList;
            }
            m_ppList = ppNewList;
        }
        m_ppList[m_lNumObjects++] = pObj;
    };

    void InsertMember( T *pObj, int index )
    {
        if ( m_lNumObjects == m_lArraySize )
        {
            m_lArraySize = max( 10, 2*m_lArraySize );
            T **ppNewList = new T*[m_lArraySize];
            if ( m_ppList )
            {
                memcpy( ppNewList, m_ppList, m_lNumObjects*sizeof(T*) );
                delete []m_ppList;
            }
            m_ppList = ppNewList;
        }
        
        if ( index < 0 || index >= m_lNumObjects )
            index = m_lNumObjects;
        
        for ( long i=m_lNumObjects; i>index; i-- )
            m_ppList[i] = m_ppList[i-1];

        m_ppList[index] = pObj;
        m_lNumObjects++;
    };

    T * operator[]( int index )
    {
        if ( index >= 0 && index < m_lNumObjects )
            return( m_ppList[index] );
        else
            return( NULL );
    };

    void KillObjectsOnDelete( BOOL bKill )
    {
        m_bKillList = bKill;
    }

    // compare function will actually get called with two T** pointers
    void Sort( int (__cdecl *compare )(const void *elem1, const void *elem2 ) )
    {
        if ( m_lNumObjects > 1 )
            qsort( m_ppList, m_lNumObjects, sizeof( T* ), compare );
    }

};

