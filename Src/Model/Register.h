#ifndef REGISTER_H
#define REGISTER_H

#include "Configuration.h"

namespace Model
{
    class Register
    {
    public:
        Register() {}
        ~Register() {}

        unsigned int index;
        WORD value;
    };
}

#endif /*REGISTER_H*/
