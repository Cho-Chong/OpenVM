#ifndef REGISTER_H
#define REGISTER_H

#include "Configuration.h"

namespace Model
{
    class Register
    {
    public:
        Register()
        {
            index = 0;
            value = 0;
        }

        ~Register() {}

        unsigned int index;
        WORD value;
    };
}

#endif /*REGISTER_H*/
