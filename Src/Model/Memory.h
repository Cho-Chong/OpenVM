#ifndef MEMORY_H
#define MEMORY_H

#include "Configuration.h"

namespace Model
{
    class Memory
    {
    public:
        Memory(unsigned int max_size)  : MaxSize(max_size)
        {
            
        }
        ~Memory() {}

        WORD GetValues(ADDRESS address)
        {
            return Words[address];
        }

        void PushWord(ADDRESS address, WORD word)
        {
            if (address < MaxSize)
            {
                Words[address] = word;
            }
            else
            {
                
            }
        }

        unsigned int MaxSize;
        WORDS_MAP Words;
    };
}

#endif /*MEMORY_H*/
