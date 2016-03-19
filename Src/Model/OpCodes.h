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

        static OPCODE_ENUM GetBaseOpCode(const WORD& op_code);

        static int GetRegisterOffset(const WORD& instruction);

        static int GetNumArguments(OPCODE_ENUM op_code);
    private:
    };
}

#endif /*OPCODES_H*/
