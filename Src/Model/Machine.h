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
        Machine(unsigned int max_code_size, unsigned int max_data_size);
        ~Machine();

        Memory Program;
        Memory Data;
        //TODO: do registers/accumulators reside in memory or is it special hardware?
        Register Registers[NUM_REGISTERS];
        Register Accumulator;
        Register ProgramCounter;
    };
}

#endif /*MACHINE_H_*/
