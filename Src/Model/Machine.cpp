#include "Machine.h"
#include <string>

namespace Model
{


    Machine::Machine(Memory* program, Memory* data) :
        Program(program),
        Data(data)
    {
    }

    Machine::~Machine()
    {
    }

    void Machine::Print()
    {
        Registers.PrintMem();
        Registers.PrintSpecial();
    }
}