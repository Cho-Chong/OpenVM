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
        typedef std::tuple<bool, std::function<void(Model::Machine*, Model::Register*, WORD)>> OP_FUNCTION;

        MachineService(Model::Machine* machine);
        ~MachineService();

        void Initialize();
        void Execute();

    private:
        Model::Machine* Machine;

        WORD Fetch();
        OPCODE_ENUM Decode(const WORD& instruction);
        void Evaluate(const WORD& instruction);
        void RefetchAndExecute(const WORD& instruction, OP_FUNCTION work);
        Model::Register* GetRegister(const WORD& instruction);
    };
}

#endif /*MACHINESERVICE_H*/
