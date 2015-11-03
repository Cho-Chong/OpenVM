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
    static const std::string COMMENT_BEGIN = "#";
    static const std::string PROGRAM_BEGIN = "BEGIN";
    static const std::string PROGRAM_END = "END";
    static const std::string ROUTINE_RET = "RET";
    static const char TAG_END = ':';

    AssemblyParser::AssemblyParser(MNEUMONIC_MAP *inst_set)
    {
        InstructionSet = inst_set;
    }

    AssemblyParser::~AssemblyParser()
    {

    }

    //TODO: oh god, getting so ugly
    void AssemblyParser::Parse(const ASSEMBLY &assembly, Model::Memory &memory, PROGRAM_ASSEMBLY_MAP &program_map)
    {
        ADDRESS byte_address = memory.GetTopAddress();
        std::map<std::string, ADDRESS> tag_map;
        unsigned int line_number = 0;
        bool found_begin = false;
        bool found_end = false;

        for (auto line : assembly) 
        {
            line_number++;

            if (line == PROGRAM_BEGIN && !found_begin)
            {
                found_begin = true;
                memory.SetValue(byte_address++, Model::OpCode::GetOpCode(OP_BEGIN, 0));
            }
            else if (line == PROGRAM_END && !found_end)
            {
                found_end = true;
                memory.SetValue(byte_address++, Model::OpCode::GetOpCode(OP_END, 0));
            }
            else if (found_begin && !line.empty())
            {
                std::istringstream strstream(line);
                std::string token;
                std::getline(strstream, token, ' ');

                //TODO: tags are any strings (a-z, A-Z, ending with :)
                //Tags must be defined before use

                //TODO: subroutines are blocks beginning with a tag and ending with ROUTINE_RET

                if (token.substr(0,1) == COMMENT_BEGIN)
                {
                    continue;
                }
                else if (token.back() == TAG_END)
                {
                    tag_map[token.substr(0,token.length() - 1)] = byte_address;
                    memory.SetValue(byte_address++, OP_NOP);
                }
                else
                {
                    program_map[line_number] = byte_address;

                    auto base_op_code = ParseInstruction(token);


                    auto num_arguments = Model::OpCode::GetNumArguments(base_op_code);

                    if (num_arguments >= 1)
                    {
                        std::getline(strstream, token, ' ');
                        int register_index = 0;
                        auto op_code = Model::OpCode::GetOpCode(base_op_code, register_index);

                        //TODO: get rid of comma
                        if (base_op_code == OP_JMP)
                        {
                            if (tag_map.find(token) != tag_map.end())
                            {
                                memory.SetValue(byte_address++, op_code);
                                memory.SetValue(byte_address++, tag_map[token]);
                            }
                        }
                        else
                        {
                            register_index = ParseRegister(token);
                            op_code = Model::OpCode::GetOpCode(base_op_code, register_index);
                            memory.SetValue(byte_address++, op_code);
                        }

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
                }
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
        //TODO: UH OH, HOW TO DIFFERENTIATE BETWEEN ACCUMULATOR AND NUMERICAL??????
        WORD reg_index = ParseRegister(token);
        if (reg_index == BAD_REGISTER_INDEX)
        {
            reg_index = stoi(token);
        }
        // TODO: support bin/hex/ASCII formats (0xAA, b1010101010101010
        return reg_index;
    }

    void AssemblyParser::ParseSubroutines()
    {
        // is it a subroutine?
        // if its a subroutine, map its tag to the current byte address
    }
}
