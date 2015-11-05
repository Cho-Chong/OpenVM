#include "stdafx.h"
#include "OpCodes.h"
#include <map>

namespace Model
{
    OpCode::OpCode()
    {

    }

    OpCode::~OpCode()
    {

    }

    //TODO: rework op_code calculations
    //TODO: handle accumulator
    WORD OpCode::GetOpCode(OPCODE_ENUM base_op_code, int register_index)
    {
        WORD op_code = (base_op_code) + register_index;

        if (op_code <= MIN_OP_CODE || op_code >= MAX_OP_CODE)
        {
            //TODO: throw
        }

        return op_code;
    }

    OPCODE_ENUM OpCode::GetBaseOpCode(const WORD& op_code)
    {
        return OPCODE_ENUM(op_code);
    }

    int OpCode::GetRegisterOffset(const WORD& instruction)
    {
        return instruction;
    }

    int OpCode::GetNumArguments(OPCODE_ENUM op_code)
    {
        //TODO: kinda don't like this
        static const std::map<OPCODE_ENUM, int> OPCODE_ARGUMENTS_MAP = 
        {
            {OP_NOP, 0},
            {OP_INC, 1},     // 1
            {OP_DEC, 1},     // 2
            {OP_JMP, 1},     // 3
            {OP_CALL, 1},    // 4
            {OP_ADD, 2},    // 5
            {OP_SUB, 2},    // 6
            {OP_MOV, 2},    // 7
            {OP_SBUF, 1}
        };

        std::map<OPCODE_ENUM, int>::const_iterator it = OPCODE_ARGUMENTS_MAP.find(op_code);

        if (it != OPCODE_ARGUMENTS_MAP.end())
        {
            return it->second;
        }
        else
        {
            return 0;
        }
    }

}