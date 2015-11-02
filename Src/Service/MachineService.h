#ifndef MACHINESERVICE_H
#define MACHINESERVICE_H

#include "Machine.h"
#include "Instruction.h"
#include <functional>

namespace Service
{
    class MachineService
    {
    public:
        MachineService(Model::Machine* machine);
        ~MachineService();

        void Initialize();
        void Execute();

    private:
        Model::Machine* Machine;

        WORD Fetch();
        OPCODE_ENUM Decode(const WORD& instruction);
        void Evaluate(const WORD& instruction);
        void RefetchAndExecute(const WORD& instruction, std::function<void(Model::Register*, WORD)> work);
        Model::Register* GetRegister(const WORD& instruction);
    };
}

#endif /*MACHINESERVICE_H*/
