#ifndef OPCODES_H
#define OPCODES_H

#include "Configuration.h"



namespace Model
{
    class OpCode
    {
    public:
        OpCode();
        ~OpCode();

        static WORD GetOpCode(OPCODE_ENUM op_code, int register_index);

        static OPCODE_ENUM GetBaseOpCode(WORD op_code);

        static int GetNumArguments(OPCODE_ENUM op_code);
    private:
        static const int OP_CODE_START = 0x0000;
    };
}

#endif /*OPCODES_H*/
