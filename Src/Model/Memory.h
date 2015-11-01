#ifndef MEMORY_H
#define MEMORY_H

#include "Configuration.h"

namespace Model
{
    class Memory
    {
    public:
        Memory(unsigned int max_size, ADDRESS top_address)  : 
            MaxSize(max_size),
            TopAddress(top_address)
        {
            
        }
        ~Memory() {}

        WORD GetValue(ADDRESS address)
        {
            return Words[address];
        }

        void SetValue(ADDRESS address, WORD word)
        {
            if (address < MaxSize)
            {
                Words[address] = word;
            }
            else
            {
                
            }
        }

        ADDRESS GetTopAddress()
        {
            return TopAddress;
        }

    private:
        ADDRESS TopAddress;
        unsigned int MaxSize;
        WORDS_MAP Words;
    };
}

#endif /*MEMORY_H*/
