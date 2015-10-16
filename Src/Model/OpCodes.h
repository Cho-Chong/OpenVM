#ifndef OPCODES_H
#define OPCODES_H

#include "Configuration.h"

//TODO: how to handle instructions for different registers?
//8051 makes each opcode + register as an offset value
typedef enum
{
    OP_NOP = 0, // 0 
    OP_INC,     // 1
    OP_DEC,     // 2
    OP_JMP,     // 3
    OP_CALL,    // 4
    OP_ADD,     // 5
    OP_SUB,     // 6
    OP_MOV,     // 7
    OP_ERROR,
    NUM_OP_CODES
} OPCODE_ENUM;

namespace Model
{
    class OpCode
    {
    public:
        OpCode();
        ~OpCode();

        static WORD GetOpCode(OPCODE_ENUM op_code, int register_index);

        static WORD GetBaseOpCode(WORD op_code);

        static int GetNumArguments(OPCODE_ENUM op_code);
    private:
        static const int OP_CODE_START = 0x0000;
    };
}

#endif /*OPCODES_H*/
