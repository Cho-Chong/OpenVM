#include <iostream>
#include <sstream>
#include <string>
#include <fstream>
#include "ProgramParser.h"

namespace Service
{
    static const unsigned int MAX_LINE_CHARS = 128;

    ProgramParser::ProgramParser()
    {

    }

    ProgramParser::~ProgramParser()
    {

    }

    ASSEMBLY ProgramParser::Parse(const std::string& file)
    {
        ASSEMBLY assembly;
        std::ifstream in;
        std::string line;

        in.open(file);
        while (std::getline(in, line))
        {
            assembly.push_back(line);
        }
        
        in.close();
        return assembly;
    }

}