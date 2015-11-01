#ifndef ASSEMBLYPARSER_H
#define ASSEMBLYPARSER_H

#include "Configuration.h"
#include "OpCodes.h"
#include "Instruction.h"
#include "Memory.h"

namespace Service
{
    class AssemblyParser
    {
    public:
        AssemblyParser(std::vector<Model::Instruction> *inst_set);
        ~AssemblyParser();

        //TODO: # params getting out of hand
        void Parse(const ASSEMBLY &assembly, Model::Memory &memory, PROGRAM_ASSEMBLY_MAP &program_map);

    private:
        std::vector<Model::Instruction>* InstructionSet;

        OPCODE_ENUM ParseInstruction(const char* inst);

        int ParseRegister(const char* line);

        WORD ParseRegValue(const char* line);
    };
}

#endif /*ASSEMBLYPARSER_H*/
