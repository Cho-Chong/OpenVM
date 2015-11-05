#include "RegisterSet.h"

namespace Model
{
    RegisterSet::RegisterSet()
    {
        SpecialRegMap =
        {
            { REG_PC, new Model::Register("PC") },
            { REG_SP, new Model::Register("SP") },
            { REG_ACC, new Model::Register("ACC") },
            { REG_SBUF, new Model::Register("SBUF") },
            { REG_B, new Model::Register("B") },
            { REG_IR, new Model::Register("IR") },
            { REG_MAR, new Model::Register("MAR") },
            { REG_MDR, new Model::Register("MDR") }
        };

        MemRegisterMap =
        {
            { REG_0, new Model::Register("REG 0") },
            { REG_1, new Model::Register("REG 1") },
            { REG_2, new Model::Register("REG 2") },
            { REG_3, new Model::Register("REG 3") },
            { REG_4, new Model::Register("REG 4") },
            { REG_5, new Model::Register("REG 5") },
            { REG_6, new Model::Register("REG 6") },
            { REG_7, new Model::Register("REG 7") }
        };
    }

    RegisterSet::~RegisterSet()
    {
        for (auto reg : SpecialRegMap)
        {
            delete reg.second;
        }

        for (auto reg : MemRegisterMap)
        {
            delete reg.second;
        }

        MemRegisterMap.clear();
        SpecialRegMap.clear();
    }

    void RegisterSet::PrintMem()
    {
        PrintRegs(MemRegisterMap);
    }

    void RegisterSet::PrintSpecial()
    {
        PrintRegs(SpecialRegMap);
    }

    Register* RegisterSet::GetMem(const REG_MEMORY_ENUM &index)
    {
        return MemRegisterMap[index];
    }

    Register* RegisterSet::GetSpecial(const REG_SPECIALS_ENUM &index)
    {
        return SpecialRegMap[index];
    }

    void RegisterSet::PrintRegs(const RegisterMap& regs)
    {
        for (auto reg : regs)
        {
            reg.second->Print();
        }
    }
}