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
        static Model::Machine machine;
        static WORD Fetch();
        static void Decode(const WORD& instruction);
        static void Evaluate(const WORD& instruction);
    };
}

#endif /*MACHINESERVICE_H*/