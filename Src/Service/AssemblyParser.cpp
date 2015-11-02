#include "stdafx.h"
#include <iostream>
#include <string>
#include <sstream>
#include "AssemblyParser.h"
#include "SimpleMnemonic.h"
#include "Memory.h"

namespace Service
{
    static const WORD BAD_REGISTER_INDEX = -1;
    AssemblyParser::AssemblyParser(MNEUMONIC_MAP *inst_set)
    {
        InstructionSet = inst_set;
    }

    AssemblyParser::~AssemblyParser()
    {

    }

    void AssemblyParser::Parse(const ASSEMBLY &assembly, Model::Memory &memory, PROGRAM_ASSEMBLY_MAP &program_map)
    {
        ADDRESS byte_address = memory.GetTopAddress();
        unsigned int line_number = 0;

        for (auto line : assembly) 
        {
            if (!line.empty())
            {
                //TODO: perhaps use this for a sort of debugger in order to step through assembly
                program_map[line_number] = byte_address;

                std::istringstream strstream(line);
                std::string token;
                std::getline(strstream, token, ' ');

                auto base_op_code = ParseInstruction(token);
                auto num_arguments = Model::OpCode::GetNumArguments(base_op_code);

                if (num_arguments >= 1)
                {
                    std::getline(strstream, token, ' ');
                    //TODO: get rid of comma
                    auto register_index = ParseRegister(token);

                    auto op_code = Model::OpCode::GetOpCode(base_op_code, register_index);
                    memory.SetValue(byte_address++, op_code);

                    if (num_arguments >= 2)
                    {
                        std::getline(strstream, token, ' ');
                        auto value = ParseRegValue(token);
                        memory.SetValue(byte_address++, value);
                    }

                    //TODO: what if more arguments? i.e. what about inline comments
                }
                else
                {
                    memory.SetValue(byte_address++, base_op_code);
                }
                
                line_number++;
            }
        }
    }

    OPCODE_ENUM AssemblyParser::ParseInstruction(const std::string& token)
    {
        return (*InstructionSet)[token];
    }

    WORD AssemblyParser::ParseRegister(const std::string& token)
    {
        auto reg_op = (*InstructionSet)[token.substr(0,1)];
        WORD register_index = 0;

        //TODO: would be nice to use a regex?
        if (reg_op == OP_ACC)
        {
            register_index = 0;
        }
        else if(reg_op == OP_REG)
        {
            std::istringstream strstream( token.substr(1, token.length()) );
            std::string subtoken;
            std::getline(strstream, subtoken, ',');

            register_index = stoi(subtoken);
        }
        else
        {
            register_index = BAD_REGISTER_INDEX;
        }

        return register_index;
    }

    WORD AssemblyParser::ParseRegValue(const std::string& token)
    {
        WORD reg_index = ParseRegister(token);
        if (reg_index == BAD_REGISTER_INDEX)
        {
            reg_index = stoi(token);
        }
        // TODO: support bin/hex/ASCII formats (0xAA, b1010101010101010, #'4)
        return reg_index;
    }
}
