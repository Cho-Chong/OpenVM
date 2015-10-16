#include "stdafx.h"
#include "AssemblyParser.h"
#include "SimpleMnemonic.h"

namespace Service
{
    AssemblyParser::AssemblyParser()
    {

    }

    AssemblyParser::~AssemblyParser()
    {

    }

    WORDS AssemblyParser::Parse(const ASSEMBLY &assembly)
    {
        WORDS byte_code;


        for (auto line : assembly)
        {
            if (line != NULL)
            {
                //TODO: what about comments?
                //HACK: HACKITY HACK
                char temp[50];
                strcpy(temp, line);
                char* argument = strtok(temp, " ");

                // TODO: support bin/hex/ASCII formats (0xAA, b1010101010101010, #'4)
                OPCODE_ENUM base_op_code = ParseInstruction(argument);
                int num_arguments = Model::OpCode::GetNumArguments(base_op_code);

                if (num_arguments >= 1)
                {
                    argument = strtok(NULL, " ");
                    //TODO: get rid of comma
                    int register_index = ParseRegister(argument);

                    WORD op_code = Model::OpCode::GetOpCode(base_op_code, register_index);
                    byte_code.push_back(op_code);

                    if (num_arguments >= 2)
                    {
                        argument = strtok(NULL, " ");
                        WORD value = ParseRegValue(argument);
                        byte_code.push_back(value);
                    }

                    //TODO: what if more arguments? i.e. what about inline comments
                }
                else
                {
                    byte_code.push_back(base_op_code);
                }
            }

            /* expected byte code
            0x0000 0x39 0x14
            0x0002 0x09
            0x0003 0x39
            */
        }

        return byte_code;
    }

    OPCODE_ENUM AssemblyParser::ParseInstruction(const char* inst)
    {
        OPCODE_ENUM matched_instruction = OP_ERROR;

        //TODO: be nice to inject the instruction set we want to use
        for (auto instruction : SIMPLE_INSTRUCTION_SET)
        {
            if (strcmp(instruction.Mnemonic, inst) == 0)
            {
                matched_instruction = instruction.ByteCode;
                //TODO: dirty
                break;
            }
        }

        return matched_instruction;
    }

    int AssemblyParser::ParseRegister(const char* reg)
    {
        int reg_len = strlen(reg);
        int register_index = 0;

        //HACK: hackish, magicalish
        if (reg_len == 1) // must be accumulator
        {
            return 0;
        }
        else // normal register
        {
            // i.e. "R1," or "R11,"
            if (reg_len >= 3)
            {
                //TODO: SO MUCH MAGIC
                int start_ic = 1;
                int end_ic = reg_len - 1;
                char int_buf[2] = "0";

                for (int ic = start_ic, buf_ic = 0; ic < end_ic; ic++, buf_ic++)
                {
                    int_buf[buf_ic] = reg[ic];
                }

                register_index = atoi(int_buf);
            }
        }

        return register_index;
    }

    WORD AssemblyParser::ParseRegValue(const char* reg_val)
    {
        return 0;
    }
}
