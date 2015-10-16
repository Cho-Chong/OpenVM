#ifndef CONFIGURATION_H
#define CONFIGURATION_H

#include <vector>

// define as 16-bit address and data
typedef unsigned short WORD;

typedef std::vector<WORD> WORDS;

typedef std::vector<char*> ASSEMBLY;

typedef unsigned short ADDRESS;

static const int MAX_CODE_SIZE = 0x2000;

static const int MAX_DATA_SIZE = 0x2000;

static const int NUM_REGISTERS = 8;


#endif /*CONFIGURATION_H*/
