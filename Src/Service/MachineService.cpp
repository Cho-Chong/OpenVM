#include "MachineService.h"
#include "OpCodes.h"

namespace Service
{
    //TODO: won't work with call, jmp, etc...
    static std::map<OPCODE_ENUM, std::function<void(Model::Register*, WORD)>> OpWorkMap =
    {
        { OP_MOV, [](auto reg, auto val) { reg->value = val; } },
        { OP_ADD, [](auto reg, auto val) { reg->value += val; } },
        { OP_SUB, [](auto reg, auto val) { reg->value -= val; } },
        { OP_INC, [](auto reg, auto val) { reg->value++; } },
        { OP_DEC, [](auto reg, auto val) { reg->value--; } }
    };

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
        Machine->Print();
        WORD instruction = Fetch();
        Evaluate(instruction);
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
    // TODO: be able to get values from RAM/data memory
    void MachineService::Evaluate(const WORD& instruction)
    {
        auto base_code = Decode(instruction);
        if (OpWorkMap.find(base_code) != OpWorkMap.end())
        {
            RefetchAndExecute(instruction, OpWorkMap[base_code]);
        }
    }

    void MachineService::RefetchAndExecute(const WORD& instruction, std::function<void(Model::Register*, WORD)> work)
    {
        auto reg = GetRegister(instruction);
        auto val = Fetch();
        work(reg, val);
    }

    Model::Register* MachineService::GetRegister(const WORD& instruction)
    {
        int register_index = Model::OpCode::GetRegisterOffset(instruction);
        Model::Register* reg = &Machine->Acc;

        if (register_index > 0)
        {
            reg = &Machine->Registers[register_index - 1];
        }

        return reg;
    }
}

