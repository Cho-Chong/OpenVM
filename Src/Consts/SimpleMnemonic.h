#ifndef SIMPLEMNEUMONIC_H
#define SIMPLEMNEUMONIC_H

#include <vector>
#include "Instruction.h"
#include "OpCodes.h"


//TODO: awkwardly floating out in ether
static const Model::Instruction MOV("MOV", OP_MOV);

static const Model::Instruction INC("INC", OP_INC);

static const Model::Instruction ADD("ADD", OP_ADD);

static const Model::Instruction SUB("SUB", OP_SUB);

//TODO: make a map with the assembly name as key?
static std::vector<Model::Instruction> SIMPLE_INSTRUCTION_SET =
{
    MOV,
    INC,
    ADD,
    SUB
};

#endif /*SIMPLEMNEUMONIC_H*/
