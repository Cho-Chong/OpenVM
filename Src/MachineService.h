#ifndef MACHINESERVICE_H
#define MACHINESERVICE_H

#include "Machine.h"
#include "Instruction.h"

namespace Service
{
    class MachineService
    {
    public:
        MachineService();
        ~MachineService();

        void Initialize();
        void Execute();

    private:
        // TODO: would be nice to inject the machine
        Model::Machine machine;

        WORD Fetch();
        void Decode(const WORD& instruction);
        void Evaluate(const WORD& instruction);
    };
}

#endif /*MACHINESERVICE_H*/
