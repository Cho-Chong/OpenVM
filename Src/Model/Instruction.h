#ifndef INSTRUCTION_H
#define INSTRUCTION_H

#include "Configuration.h"
#include "OpCodes.h"
#include <vector>

namespace Model
{
    class Instruction
    {
    public:
        Instruction(const char* mnemonic, OPCODE_ENUM byte_code);

        ~Instruction();

        static const int MAX_MONIC_LENGTH = 5;
        char Mnemonic[MAX_MONIC_LENGTH];
        OPCODE_ENUM ByteCode;
    };

    typedef std::vector<Instruction> InstructionSet;
}

#endif /*INSTRUCTION_H*/

