#ifndef __crc32_h__
#define __crc32_h__

#include <windows.h>

ULONG crc32(ULONG crc, const BYTE *buf, size_t len);

#endif
