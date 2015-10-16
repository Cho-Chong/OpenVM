#ifndef ASSEMBLYPARSER_H
#define ASSEMBLYPARSER_H

#include "Configuration.h"
#include "OpCodes.h"

namespace Service
{
    class AssemblyParser
    {
    public:
        AssemblyParser();
        ~AssemblyParser();

        WORDS Parse(const ASSEMBLY &assembly);

    private:
        OPCODE_ENUM ParseInstruction(const char* inst);

        int ParseRegister(const char* line);

        WORD ParseRegValue(const char* line);
    };
}

#endif /*ASSEMBLYPARSER_H*/
