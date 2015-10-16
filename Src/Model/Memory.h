#ifndef MEMORY_H
#define MEMORY_H

#include "Configuration.h"
namespace Model
{
    template <int MAX_SIZE>
    class Memory
    {
    public:
        Memory() {}
        ~Memory() {}

        WORD GetValue(ADDRESS address)
        {
            return 0;
        }

        ADDRESS startingAddress;
        WORD values[MAX_SIZE];
    };
}

#endif /*MEMORY_H*/