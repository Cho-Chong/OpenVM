#ifndef SIMPLEMNEUMONIC_H
#define SIMPLEMNEUMONIC_H

#include <vector>
#include "Instruction.h"
#include "OpCodes.h"


//TODO: awkwardly floating out in ether
static const Model::Instruction MOV("MOV", OP_MOV);

static const Model::Instruction INC("INC", OP_INC);

//TODO: make a map with the assembly name as key?
static std::vector<Model::Instruction> SIMPLE_INSTRUCTION_SET =
{
    MOV,
    INC
};

#endif /*SIMPLEMNEUMONIC_H*/
