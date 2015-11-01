#ifndef MACHINESERVICE_H
#define MACHINESERVICE_H

#include "Machine.h"
#include "Instruction.h"

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
        void Decode(const WORD& instruction);
        void Evaluate(const WORD& instruction);
    };
}

#endif /*MACHINESERVICE_H*/
