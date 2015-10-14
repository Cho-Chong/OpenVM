#ifndef INSTRUCTION_H
#define INSTRUCTION_H

#include "Configuration.h"
#include <string>

namespace Model
{
    class Instruction
    {
    public:
        Instruction(const char* mnemonic, WORD byte_code) :
            ByteCode(byte_code)
        {
            strcpy(Mnemonic, mnemonic);
        }

        ~Instruction() {}


        static const int MAX_MONIC_LENGTH = 5;
        char Mnemonic[MAX_MONIC_LENGTH];
        WORD ByteCode;
    };
}

#endif /*INSTRUCTION_H*/

