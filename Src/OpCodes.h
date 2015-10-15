#ifndef OPCODES_H
#define OPCODES_H

//TODO: how to handle instructions for different registers?
//8051 makes each opcode + register as an offset value
typedef enum
{
    OP_NOP = 0,
    OP_INC,
    OP_DEC,
    OP_JMP,
    OP_CALL,
    OP_ADD,
    OP_SUB,
    OP_MOV,
} OPCODE_ENUM;

#endif /*OPCODES_H*/
