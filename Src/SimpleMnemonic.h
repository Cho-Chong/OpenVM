#ifndef SIMPLEMNEUMONIC_H
#define SIMPLEMNEUMONIC_H

#include <vector>
#include "Instruction.h"
#include "OpCodes.h"

static const Model::Instruction MOV("MOV", OP_MOV);

static const Model::Instruction INC("INC", OP_INC);

std::vector<Model::Instruction> InstructionSet =
{
    MOV,
    INC
};

#endif /*SIMPLEMNEUMONIC_H*/
