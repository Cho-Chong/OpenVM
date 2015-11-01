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
        auto op_code = Decode(instruction);
        Evaluate(op_code);
    }

    WORD MachineService::Fetch()
    {
        return Machine->Program->GetValue(Machine->PC.value++);
    }

    OPCODE_ENUM MachineService::Decode(const WORD& instruction)
    {
        return Model::OpCode::GetBaseOpCode(instruction);
    }

    // TODO: extract, abstract and create an ALU and buses (data, control, address)
    void MachineService::Evaluate(const OPCODE_ENUM& instruction)
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