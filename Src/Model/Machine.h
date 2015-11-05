#ifndef MACHINE_H_
#define MACHINE_H_

#include "Configuration.h"
#include "RegisterSet.h"
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
        Memory* Data;  // external RAM
        RegisterSet Registers;
        std::stack<ADDRESS> stack;
    };
}

#endif /*MACHINE_H_*/
