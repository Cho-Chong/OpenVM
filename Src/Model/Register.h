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

        ADDRESS address;
        WORD value;
    };
}

#endif /*REGISTER_H*/
