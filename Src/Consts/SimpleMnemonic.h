#ifndef SIMPLEMNEUMONIC_H
#define SIMPLEMNEUMONIC_H

#include <vector>
#include "Instruction.h"
#include "OpCodes.h"

static MNEUMONIC_MAP SIMPLE_INSTRUCTION_SET =
{
    { "A", OP_ACC },
    { "R", OP_REG },
    { "MOV", OP_MOV },
    { "INC", OP_INC },
    { "ADD", OP_ADD },
    { "SUB", OP_SUB },
    { "JMP", OP_JMP },
    { "CALL", OP_CALL},
    { "SBUF", OP_SBUF},
    { "RET", OP_RET}
};

#endif /*SIMPLEMNEUMONIC_H*/
