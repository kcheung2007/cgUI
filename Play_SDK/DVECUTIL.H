#ifndef dvecutil_h
#define dvecutil_h

#define NOMINMAX
#include <windows.h>

inline BOOL writevoid(HANDLE o, void* what, DWORD len)
{
  DWORD written;
  ::WriteFile(o, what, len, &written, NULL);
  return len==written;
}

inline BOOL writetext(HANDLE o, char* what)
{
  return writevoid(o, what, strlen(what));
}

inline HANDLE open_for_output(char* what)
{
  return ::CreateFile(
    what,           // pointer to name of the file
    GENERIC_WRITE,  // access (read-write) mode
    0,              // share mode
    NULL,           // pointer to security descriptor
    CREATE_ALWAYS,  // how to create
    FILE_ATTRIBUTE_NORMAL|FILE_FLAG_SEQUENTIAL_SCAN,  // file attributes
    NULL            // handle to file with attributes to copy
   );
}

inline HANDLE open_for_input(char* what)
{
  return ::CreateFile(
    what,           // pointer to name of the file
    GENERIC_READ,   // access (read-write) mode
    0,              // share mode
    NULL,           // pointer to security descriptor
    OPEN_EXISTING,  // how to create
    FILE_ATTRIBUTE_NORMAL|FILE_FLAG_SEQUENTIAL_SCAN,  // file attributes
    NULL            // handle to file with attributes to copy
   );
}

#endif