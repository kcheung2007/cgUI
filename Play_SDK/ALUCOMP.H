#ifndef ALUCOMP_H
#define ALUCOMP_H

#define NOMINMAX
#include <windows.h>
#include "dvemath.h"



//Define this to have stuff sent to the fifo, also sent to a file.
//#define DebugOutput "fifoout.txt"
#ifdef DebugOutput
#include <stdio.h>
#endif

typedef unsigned __int64 QWORD;



class ALUFIFO
{
private:
  enum { ALUFIFOLength = 250*1024 } ;     //Length of the ALU FIFO in bytes. (Allow header and footer)
  BYTE* buf;                              //Address of the FIFO image we're building.
  BYTE* current;                          //Current address of operation.
  BOOL  valid;                            //Whether there is a valid FIFO buffer.
  int   length;                           // number of NIBBLES written.

#ifdef DebugOutput
  FILE* outfile;                          //Text file for output.
#endif

  BOOL AddNibble(BYTE nibble);

public:

  // Allocate our working buffer and set up our variables.
  ALUFIFO();

  // Nuke ourselves.
  ~ALUFIFO();

  // Reset the FIFO input pointer back to the beginning of the buffer.
  void Reset();

  // True only if there is a valid buffer.  Used by clients.
  BOOL IsValid()
  {
    return valid;
  }

  // Returns the length of the buffer in bytes, accounting for the fact that
  // there may be an off number of nibbles in the buffer.
  int  Length()
  {
    return ( (length & 1) + length / 2 );
  }

  // Return our buffer address.
  BYTE* BufferAddress()
  {
    return buf;
  }

  // Place an opcode into the ALU FIFO.
  // Returns TRUE if the nibble fit into the FIFO.
  //         FALSE if the FIFO is full.
  BOOL AddOpcode(BYTE Opcode);

  // Place a Value argument into the ALU FIFO.
  // Only the low 20 bits are placed into the FIFO, and nibbles are stuffed
  // big end first.
  // Returns TRUE if the nibble fit into the FIFO.
  //         FALSE if the FIFO is full.
  BOOL AddValue(DWORD Value);

  // Place an Opcode and Value argument into the ALU FIFO.
  // Only the low 20 bits of the Value are placed into the FIFO, and nibbles are stuffed
  // big end first.
  // Returns TRUE if the nibbles fit into the FIFO.
  //         FALSE if the FIFO is full.
  BOOL AddOpcodeValue(BYTE Opcode, DWORD Value);
};


// This class emulates the hardware ALU adding registers.  If the hardware changes,
// the class must be changed to reflect the new hardware.
// This knows how to convert from double to the ALU format, and how to emulate the
// addition operations.
// Hopefully, any funny business about the actual numeric format can be encapsulated
// within this class. (With the exception that ALUFIFOs know that values are 20 bits.)
class ALUSeg
{

  QWORD ddt, dt, t;
  BOOL valid;

  QWORD DoubleToALU(double& d);

  void ALUSet (double _t, double _dt, double _ddt);

public:

  //This default constructor set the registers to illegal values.
  ALUSeg();

  //This constructor takes the register values as doubles, then converts them
  //to the ALU specific format.
  ALUSeg (double _t, double _dt, double _ddt);

  ALUSeg (Seg& s);

  //Advance will update the registers as if the ALU has performed an update
  //to move on to the next pixel.
  void Advance(int n=1);

// Here's our accumulator(registers) as stored in objects of this class:
//    6         5         4         3         2         1         0
// 3210987654321098765432109876543210987654321098765432109876543210
// 000000000000000000000000wwwwwwwwwwffffffffffffffffffffffffffffff
// where 'w' marks bits which are part of the whole part of numbers in the
// accumulator, and 'f' marks the fractional bits.  The following routines
// take pieces of this format to grab 20 bit fields for stuffing into the
// ALUFIFO.

// Return the t value formatted so that it can be loaded into an ALUFIFO.
//    6         5         4         3         2         1         0
// 3210987654321098765432109876543210987654321098765432109876543210
// 000000000000000000000000wwwwwwwwwwffffffffffffffffffffffffffffff
//                         ^^^^^^^^^^^^^^^^^^^^ <-these bits are returned
  DWORD FIFO_t();

// Return the dt value formatted so that it can be loaded into an ALUFIFO.
//    6         5         4         3         2         1         0
// 3210987654321098765432109876543210987654321098765432109876543210
// 000000000000000000000000wwwwwwwwwwffffffffffffffffffffffffffffff
//                         ^^^^^^^^^^^^^^^^^^^^ <-these bits are returned
  DWORD FIFO_dthi();

// Return the dt value formatted so that it can be loaded into an ALUFIFO.
//    6         5         4         3         2         1         0
// 3210987654321098765432109876543210987654321098765432109876543210
// 000000000000000000000000wwwwwwwwwwffffffffffffffffffffffffffffff
//                         00000000000000000000^^^^^^^^^^^^^^^^^^^^<-these bits are returned
  DWORD FIFO_dtlo();

// Return the ddt value formatted so that it can be loaded into an ALUFIFO.
//    6         5         4         3         2         1         0
// 3210987654321098765432109876543210987654321098765432109876543210
// 000000000000000000000000wwwwwwwwwwffffffffffffffffffffffffffffff
//                         ^^^^^^^^^^^^^^^^^^^^ <-these bits are returned
  DWORD FIFO_ddthi();

// Return the ddt value formatted so that it can be loaded into an ALUFIFO.
//    6         5         4         3         2         1         0
// 3210987654321098765432109876543210987654321098765432109876543210
// 000000000000000000000000wwwwwwwwwwffffffffffffffffffffffffffffff
//                         00000000000000000000^^^^^^^^^^^^^^^^^^^^<-these bits are returned
  DWORD FIFO_ddtlo();


  BOOL dt_is_high_precision();
  BOOL ddt_is_sign_extended();


  // Compare this ALUSeg with another one (presumably a previous one) to determine
  // which register changed.
  void Compare(ALUSeg& other, BOOL& tchanged, BOOL& dtchanged, BOOL& ddtchanged);

};


// The ALUProgramGenerator knows about the ALU opcodes, and how to use ALUSegs
// and ALUFIFOs to generate an ALU program.
class ALUProgramGenerator
{
private:
  // These are the state of the last segment at the end of their run.
  // Their values correspond to the registers values at the next pixel
  // to be fetched.
  ALUSeg last_u, last_v;

  // How long the current contiguous (no register loads) segment it.
  DWORD current_count;

  // Defines the target DVE for register sizes, default is PLAY_WE_DVE_ID
  DWORD DVE_Target; 

  // The Offset for the DVE in memory
  POINT VideoOffset;

  // Start of current contiguous segment.
  int DestinationX;

  // A reference to the FIFO we're loading.
  ALUFIFO& fifo;

  enum opcodes {
    NOP       = 0x0,
    LoadU     = 0x8,
    LoadV     = 0x9,
    LoaddU    = 0xA,
    LoaddV    = 0xB,
    LoadddU   = 0xC,
    LoadddV   = 0xD,
    LoadCount = 0x7
               };


  BOOL DoLoadCount();

public:
  ALUProgramGenerator(ALUFIFO& _fifo) :
      fifo(_fifo),
      current_count(0)
  {
  }

  ~ALUProgramGenerator()
  {
	  DoLoadCount();
	}

  void SetTargetDVE(DWORD ID_NUM)
  {
	  DVE_Target = ID_NUM;
  }

  void SetVideoOffset(POINT _VideoOffset)
  {
	  VideoOffset = _VideoOffset;
  }

  BOOL AddTrace(Trace& trace, BOOL IsUpsideDown=FALSE);

  // This is called after the last trace has been added to give an opportunity
  // to stuff the current segment into the fifo.
  BOOL NoMoreTraces();
};

class ControlFrameGenerator
{
 /* 
  MASKDEF <name>,n, m
    Define bit number m as name
  MASKVAL <name>,<0val>,<1val>
    Define the bit state for <name>ed bit.
        MASKDEF RASTERFIFO,0,7
        MASKVAL RASTERFIFO,CLOCK,STOP
        MASKDEF RASTERMODE,0,6
        MASKVAL RASTERMODE,MATTE,PIXEL
        MASKDEF VIDEOREGISTER,0,5
        MASKVAL VIDEOREGISTER,HOLD,UPDATE
        MASKDEF BLANKING,0,4
        MASKVAL BLANKING,BLANKOFF,BLANKON
        MASKDEF VIDEOFIFO,0,3
        MASKVAL VIDEOFIFO,RESET,NORMAL

        MASKDEF CONTROL_UNUSED2,0,2
        MASKDEF CONTROL_UNUSED1,0,1

        MASKDEF KEYPRIORITY,0,0
        MASKVAL KEYPRIORITY,BACK,FORE
 */
  enum ControlOps 
  {
    InactivePixel=0x8F,    
      ActivePixel=0x6E,
	  ActiveMatte=0x29 // These should be changed DEP
  };
  BYTE* ControlBuf;
  int width, length;

public:
  void Reset()
  {
    memset(ControlBuf, InactivePixel, length);
  }

  ControlFrameGenerator(int MaxX, int MaxY)
  {
    length = MaxX * MaxY;
    ControlBuf=new BYTE[length];
    width=MaxX;
    Reset();
  }

  ~ControlFrameGenerator()
  {
    delete [] ControlBuf;
  }

  BYTE* BufferAddress()
  {
    return ControlBuf;
  }


  void AddTrace(Trace& trace)
  {
    extern int DebugSeg;

	BYTE* outptr = ControlBuf + trace.ydest*width + trace.xdest;
    if(DebugSeg)
		*outptr++ = ActiveMatte;
	for (int i=DebugSeg; i<trace.len; i++)
      *outptr++ = ActivePixel;
  }

};

#endif