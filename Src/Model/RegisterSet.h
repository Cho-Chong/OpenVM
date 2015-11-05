#ifndef REGISTERSET_H
#define REGISTERSET_H

#include <map>
#include "Register.h"

namespace Model
{
    typedef enum
    {
        REG_PC = 0,
        REG_SP,
        REG_ACC,
        REG_SBUF,
        REG_B,
        REG_IR,
        REG_MAR,
        REG_MDR,
        NUM_SPECIAL_REGS,
    } REG_SPECIALS_ENUM;

    typedef enum
    {
        REG_0 = 0,
        REG_1,
        REG_2,
        REG_3,
        REG_4,
        REG_5,
        REG_6,
        REG_7,
        NUM_MEM_REGS
    } REG_MEMORY_ENUM;

    typedef std::map<int, Model::Register*> RegisterMap;

    //TODO: doesn't really seem right to be a class...
    //hardware registers is more of a single instance thing
    //maybe make singleton?
    class RegisterSet
    {
    public:
        RegisterSet();
        ~RegisterSet();

        void PrintMem();
        void PrintSpecial();
        Register* GetMem(const REG_MEMORY_ENUM &index);
        Register* GetSpecial(const REG_SPECIALS_ENUM &index);

    private:
        void PrintRegs(const RegisterMap& regs);

        RegisterMap SpecialRegMap;

        RegisterMap MemRegisterMap;
    };
}

#endif /*REGISTERSET_H*/
