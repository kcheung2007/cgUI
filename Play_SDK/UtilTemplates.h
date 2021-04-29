/******************************************************************************************
FileName		: Array.h
Author			: Andy Preston
Purpose		    : Template(s) for class/built in arrays
Date Of Creation: 5/12/99
Copyright       : Play Incorporated 1999
Modification History :
Date             Modifications
******************************************************************************************/


#ifndef ARRAY_AP_H
#define ARRAY_AP_H

#include <assert.h>

/*

//Andy Preston 5/17/99- What follows is a mess. This is a wrapper around the 
  normal smart pointer class, since it is causeing a name collision with 
  Quicktime. It also is then more obvious from its name, what exactly it does !

  */

namespace ISmartPtr 
{
#include "SmartPtr.h"
};


/*
 This isn't the best array template, since it stores arrays of objects, nt arrays of
 pointers to object, but it's simple for most purposes for simple type of storage.

 It won't be that fast either for multiple resize, due to the copy, so if you see 
 lots of resizing  happening , then initialise at a decent size
 i.e. BasicArray<type> Name(200)
   or Name->SetSize(200);
*/

template <class type>
class BasicArray
{
 private :
 type *p;
 unsigned long size;
 unsigned long CurrentPos;
 unsigned long MaxPos;
 unsigned long BaseSize;
 bool NoResize;
 inline void Init(void) {p=NULL;size=0;SetSize(BaseSize);CurrentPos=0;MaxPos=0; };

 public :
 BasicArray(unsigned long sz) {BaseSize=sz;NoResize=false;Init();};
 BasicArray() {BaseSize=0;NoResize=false;Init();};
 ~BasicArray() {Clear();};
 inline void Clear(void) {if (p) delete[] p;p=NULL;};
 inline void SetNoResize(bool Rsz) {NoResize=Rsz;};
 inline void SetBaseSize(unsigned long sz) {BaseSize=sz;};
 type & Get(unsigned long index)
   {
    if (!p) 
     {
      BaseSize=4;
      Init();
     }
    if (index < 0) 
     {
      assert(0);
      index=0;
     }
    if (index >= size)
     {
      if (NoResize) 
       {
        assert(0);
        index=size-1;
       }
      else
       {
        SetSize(size *2);
       }
     }
    CurrentPos=index;
    if ((index+1) > MaxPos) MaxPos=index+1;
    return p[index];
   };
 inline type &operator[](unsigned long index)
   {
    return(Get(index));
   } ;
 inline unsigned long Count(void)
   {
    return(MaxPos);
   } ;
 inline void Start(void)
   {
    CurrentPos=-1;
   }  ;
 inline void End(void)
   {
    CurrentPos=MaxPos;
   }   ;
 inline type &Next(void)
   {
    return(Get(++CurrentPos));
   }    ;
 inline type &Previous(void)
   {
    return(Get(--CurrentPos));
   }     ;
 void SetSize(unsigned long NewSize)
   {
    type * temp;                                                                                                 
    unsigned long oldSize=size;                                                                                            

    if (NewSize == size) return;
    temp= new type[NewSize];                                                                                        

    if (p)
      {
       if (NewSize < size)
         {
          for(unsigned long loop=0;loop < NewSize;loop++)                                                                        
            {                                                                                                           
             temp[loop]=p[loop];                                                                                        
            }                                                                                                           
         }
        else
         {
          for(unsigned long loop=0;loop < oldSize;loop++)                                                                        
           {                                                                                                           
            temp[loop]=p[loop];                                                                                        
           }                                                                                                           
         }
        delete[] p;  
      }
    p=temp;                                                                                                      
    size=NewSize;
    if (MaxPos > size) MaxPos=size;
    BaseSize=NewSize;
   };
 void SortAsc(void)   // this performs a pretty slow bubble sort ! (Max 2N passes !) // assumes > is defined for the "type"
   {
    for(unsigned long loop1= 0 ;loop1 < Count();loop1++)
      {
       bool swap=false;
       for(unsigned long loop2=0;loop2 < Count()-1;loop2++)
         {
          if (p[loop2] > p[loop2+1])
           {
            type temp;
            temp=p[loop2];
            p[loop2]=p[loop2+1];
            p[loop2+1]=temp;
            swap=true;
           }
         }
        if (!swap) return;
      }
   };
};




#endif
