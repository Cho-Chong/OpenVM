#include "MachineService.h"
#include "OpCodes.h"

namespace Service
{
    MachineService::MachineService(Model::Machine* machine) : Machine(machine)
    {
    }

    MachineService::~MachineService()
    {

    }

    void MachineService::Initialize()
    {
    }

    void MachineService::Execute()
    {
        WORD instruction = Fetch();
        Decode(instruction);
        Evaluate(instruction);
    }

    WORD MachineService::Fetch()
    {
        return Machine->Program.GetValues(Machine->ProgramCounter.value++);
    }

    void MachineService::Decode(const WORD& instruction)
    {

    }

    void MachineService::Evaluate(const WORD& instruction)
    {
            switch (instruction)
            {
                case OP_NOP:
                {

                } break;
                case OP_INC:
                {

                } break;
                case OP_DEC:
                {

                } break;
                case OP_ADD:
                {

                } break;
                case OP_SUB:
                {

                } break;
                case OP_CALL:
                {

                } break;
                case OP_JMP:
                {

                } break;
                case OP_MOV:
                {

                } break;
                default:
                {

                } break;
            }
    }



    
}