#include "Machine.h"

namespace Model
{
    Model::Machine::Machine(Memory* program, Memory* data) :
        Program(program),
        Data(data)
    {
        int reg_index = 0;
        Acc.index = reg_index;
        Acc.value = 0;

        for (int index = 0; index < NUM_REGISTERS; index++)
        {
            reg_index++;
            Registers[index].index = reg_index;
            Registers[index].value = 0;
        }
    }

    Model::Machine::~Machine()
    {
    }

    void Machine::Print()
    {
        printf("SP: %d, PC: %d, ACC: %d\n", Sp.value, PC.value, Acc.value);

        // print the program memory
        // print the register contents
        for (int index = 0; index < NUM_REGISTERS; index++)
        {
            printf("Reg %d: %d\n", Registers[index].index, Registers[index].value);
        }
    }
}