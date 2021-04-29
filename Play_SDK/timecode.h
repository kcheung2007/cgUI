/*==========================================================================*\
||  FILE:       TIMECODE.H                                                  ||
||  DESC:       Defines Timecode class                                      ||
||  MODIFIED:   11-15-95        T.Sprague       Created                     ||
\*==========================================================================*/

#ifndef TIMECODE_H_INCLUDED
#define TIMECODE_H_INCLUDED

class CTimeCode
{
    public:
        CTimeCode();
        CTimeCode(const int val);
        CTimeCode(char *pszStr );
        ~CTimeCode();

        // I/O conversions
        char *ToASCII( char *pszDest );  // dest must be at least 12 chars
        int FromASCII( char *pszSrc ); // another parm for type?
        unsigned long ToFrames( void ); // how many frames from 00:00:00:00 ?
        void FromFrames( unsigned long ); // how many frames from 00:00:00:00 ?
        unsigned long ToFields( void ); // how many FIELDS from 00:00:00:00 ?   (even only)
        void FromFields( unsigned long ); // how many fields from 00:00:00:00 ? (even only)
        void FromBCD( unsigned long dwBCD );        // convert to timecode from BCD
        unsigned long ToBCD( );        // convert from timecode to BCD
        
        // internal conversion fcns
        void ToDropFrame( void );
        void ToNonDropFrame( void );
        void ToPAL( void );
        void ToFilm( void );
        
        // what kind is it?
        int IsDropFrame( void );
        int IsNonDropFrame( void );
        int IsPAL( void );
        int IsFilm( void );
        
        // streams support
//        CTimeCode& operator<<( CTimeCode& tc );
//        CTimeCode& operator>>( CTimeCode& tc );
        
        // add/subtract
        CTimeCode operator+( CTimeCode tc1 );
        CTimeCode operator-( CTimeCode tc1 );
        CTimeCode operator+( int nFrames );
        CTimeCode operator-( int nFrames );
        friend CTimeCode operator+( int nFrames, CTimeCode tc1 );
        friend CTimeCode operator-( int nFrames, CTimeCode tc1 );

        // assignment
        CTimeCode& operator+=( CTimeCode tc );
        CTimeCode& operator+=( int nFrames ); // add nFrames to timecode
        CTimeCode& operator-=( CTimeCode tc );
        CTimeCode& operator-=( int nFrames ); // subtract nFrames to timecode
        CTimeCode& operator=( CTimeCode tc );
        CTimeCode& operator=( int nFrames );  // convert # frames to timecode (type should be set first...)
        CTimeCode& operator=( char *pszTC );

        // comparison
        int operator>( CTimeCode tc1 );
        int operator<( CTimeCode tc1 );
        int operator>=( CTimeCode tc1 );
        int operator<=( CTimeCode tc1 );
        int operator==( CTimeCode tc1 );
        int operator!=( CTimeCode tc1 );

        long MaxFrames( void ); // return max # frames in one day for current TC type

    private:

        unsigned long       m_dwFrames;             // timecode converted to frmaes. format still TBD.  may have flags for DF, NDF, PAL, film, etc

};

#endif // TIMECODE_H_INCLUDED
