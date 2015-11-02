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
        AssemblyParser(MNEUMONIC_MAP* inst_set);
        ~AssemblyParser();

        //TODO: # params getting out of hand
        void Parse(const ASSEMBLY &assembly, Model::Memory &memory, PROGRAM_ASSEMBLY_MAP &program_map);

    private:
        MNEUMONIC_MAP* InstructionSet;

        OPCODE_ENUM ParseInstruction(const std::string& token);

        WORD ParseRegister(const std::string& token);

        WORD ParseRegValue(const std::string& token);

        void ParseTags();

        void ParseSubroutines();
    };
}

#endif /*ASSEMBLYPARSER_H*/
