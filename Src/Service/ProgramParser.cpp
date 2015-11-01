#include <fstream>
#include "ProgramParser.h"

namespace Service
{
    ProgramParser::ProgramParser()
    {

    }

    ProgramParser::~ProgramParser()
    {

    }

    ASSEMBLY ProgramParser::Parse(const char* file)
    {
        ASSEMBLY assembly;
        std::ifstream in;

        in.open(file);
        
        return assembly;
    }

}