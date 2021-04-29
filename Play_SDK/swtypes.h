#if !defined(__SW_TYPES_H)
#define __SW_TYPES_H
//
//      Switcher Types and useful definitions
//
//      this is really kludgy for now
//      !!! figure out a better way of exporting assembly structures and
//      equates to .cpp
//
#define swSTRUCTURE(name) struct name {
#define swLABEL(name)    ; } ;

#define swfLONG  unsigned long
#define swfWORD  unsigned short
#define swfBYTE  unsigned char
#define swfSTRUCT unsigned char
#define swfAPTR  swfLONG

#define swLONG  ; unsigned long
#define swWORD  ; unsigned short
#define swBYTE  ; unsigned char
#define swSTRUCT ; unsigned char
#define swAPTR  swLONG

#define SW_COMMAND_OFFSET       0x00080000L
#define SW_CMD(Cmd_ID)  (SW_ ## Cmd_ID + SW_COMMAND_OFFSET)

#endif // !defined(__SW_TYPES_H)
