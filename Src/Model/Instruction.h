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
        Instruction(OPCODE_ENUM byte_code);

        ~Instruction();

        OPCODE_ENUM ByteCode;
    };
}

#endif /*INSTRUCTION_H*/

