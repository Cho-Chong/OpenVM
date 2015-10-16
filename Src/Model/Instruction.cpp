#include "stdafx.h"
#include "Instruction.h"
#include <string>

namespace Model
{
    Instruction::Instruction(const char* mnemonic, OPCODE_ENUM byte_code) :
        ByteCode(byte_code)
    {
        strcpy(Mnemonic, mnemonic);
    }

    Instruction::~Instruction()
    {

    }
}