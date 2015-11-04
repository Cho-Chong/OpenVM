#ifndef CONFIGURATION_H
#define CONFIGURATION_H

#include <vector>
#include <map>

//TODO: how to handle instructions for different registers?
//8051 makes each opcode + register as an offset value
typedef enum
{
    OP_NOP = 0, // 0 
    OP_INC,     // 1
    OP_DEC,     // 2
    OP_JMP,     // 3
    OP_CALL,    // 4
    OP_ADD,     // 5
    OP_SUB,     // 6
    OP_MOV,     // 7
    OP_RET,
    OP_ACC,
    OP_SBUF,
    OP_REG,
    OP_BEGIN,
    OP_END,
    OP_ERROR,
    NUM_OP_CODES
} OPCODE_ENUM;

typedef unsigned short WORD;

typedef std::vector<WORD> WORDS;

typedef unsigned short ADDRESS;

typedef std::map<ADDRESS, WORD> WORDS_MAP;

typedef std::map<unsigned int, ADDRESS> PROGRAM_ASSEMBLY_MAP;

typedef std::vector<std::string> ASSEMBLY;

typedef std::map<std::string, OPCODE_ENUM> MNEUMONIC_MAP;

static const int MAX_CODE_SIZE = 0x2000;

static const int MAX_DATA_SIZE = 0x2000;

static const ADDRESS CODE_START_ADDRESS = 0x0000;

static const ADDRESS DATA_START_ADDRESS = CODE_START_ADDRESS + MAX_CODE_SIZE;

static const int NUM_REGISTERS = 8;

#endif /*CONFIGURATION_H*/
