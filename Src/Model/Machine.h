#ifndef MACHINE_H_
#define MACHINE_H_

#include "Configuration.h"
#include "Register.h"
#include "Memory.h"

namespace Model
{
    class Machine
    {
    public:
        Memory<MAX_CODE_SIZE> Code;
        Memory<MAX_DATA_SIZE> Program;
        Register Registers[NUM_REGISTERS];
        Register Accumulator;
        Register ProgramCounter;
    };
}

#endif /*MACHINE_H_*/
