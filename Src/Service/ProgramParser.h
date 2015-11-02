#ifndef PROGRAMPARSER_H
#define PROGRAMPARSER_H

#include "Configuration.h"

namespace Service
{
    class ProgramParser
    {
    public:
        ProgramParser();
        ~ProgramParser();
        ASSEMBLY Parse(const std::string& file);

    private:

    };
}

#endif /*PROGRAMPARSER_H*/
