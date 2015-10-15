#include "Instruction.h"
#include <string>

namespace Model
{
    Instruction::Instruction(const char* mnemonic, WORD byte_code) :
        ByteCode(byte_code)
    {
        strcpy(Mnemonic, mnemonic);
    }

    Instruction::~Instruction()
    {

    }
}