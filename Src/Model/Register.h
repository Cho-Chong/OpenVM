#ifndef REGISTER_H
#define REGISTER_H

#include "Configuration.h"

namespace Model
{
    class Register
    {
    public:
        Register(std::string name) : 
            Value(0), 
            Name(name)
        {
        }

        ~Register() {}

        void Print()
        {
            printf("%s: %d", Name, Value);
        }

        std::string Name;
        WORD Value;
    };
}

#endif /*REGISTER_H*/
