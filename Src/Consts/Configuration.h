#ifndef CONFIGURATION_H
#define CONFIGURATION_H

#include <vector>
#include <map>

typedef unsigned short WORD;

typedef std::vector<WORD> WORDS;

typedef unsigned short ADDRESS;

typedef std::map<ADDRESS, WORD> WORDS_MAP;

typedef std::map<unsigned int, ADDRESS> PROGRAM_ASSEMBLY_MAP;

typedef std::vector<char*> ASSEMBLY;

static const int MAX_CODE_SIZE = 0x2000;

static const int MAX_DATA_SIZE = 0x2000;

static const int NUM_REGISTERS = 8;

#endif /*CONFIGURATION_H*/
