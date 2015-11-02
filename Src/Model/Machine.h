#ifndef MACHINE_H_
#define MACHINE_H_

#include "Configuration.h"
#include "Register.h"
#include "Memory.h"
#include <stack>

namespace Model
{
    class Machine
    {
    public:
        Machine(Memory* program, Memory* data);
        ~Machine();

        void Print();

        Memory* Program;
        Memory* Data;
        //TODO: do registers/accumulators reside in memory or is it special hardware?
        Register Registers[NUM_REGISTERS];
        Register Sp;   //stack pointer
        Register Acc;  //accumulator
        Register PC;   //program counter
        Register IR;   //instruction register
        Register MAR;  //memory address register
        Register MDR;  //memory data register
        std::stack<ADDRESS> stack;

    };
}

#endif /*MACHINE_H_*/
