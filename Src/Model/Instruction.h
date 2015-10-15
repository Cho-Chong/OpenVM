#ifndef INSTRUCTION_H
#define INSTRUCTION_H

#include "Configuration.h"
#include <vector>

namespace Model
{
    class Instruction
    {
    public:
        Instruction(const char* mnemonic, WORD byte_code);

        ~Instruction();

        static const int MAX_MONIC_LENGTH = 5;
        char Mnemonic[MAX_MONIC_LENGTH];
        WORD ByteCode;
    };

    typedef std::vector<Instruction> InstructionSet;
}

#endif /*INSTRUCTION_H*/

