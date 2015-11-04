#include "MachineService.h"
#include "OpCodes.h"
#include <string>
#include <thread>
#include <chrono>

namespace Service
{
    //TODO: I don't like the op_function...
    static std::map<OPCODE_ENUM, MachineService::OP_FUNCTION> OpWorkMap =
    {
        { OP_MOV, std::make_tuple(true, [](auto machine, auto reg, auto val) { reg->value = val; }) },
        { OP_ADD, std::make_tuple(true, [](auto machine, auto reg, auto val) { reg->value += val; }) },
        { OP_SUB, std::make_tuple(true, [](auto machine, auto reg, auto val) { reg->value -= val; }) },
        { OP_JMP, std::make_tuple(true, [](auto machine, auto reg, auto val) { machine->PC.value = val; }) },
        { OP_INC, std::make_tuple(false, [](auto machine, auto reg, auto val) { reg->value++; }) },
        { OP_DEC, std::make_tuple(false, [](auto machine, auto reg, auto val) { reg->value--; }) },
        { OP_CALL, std::make_tuple(false, [](auto machine, auto reg, auto val) { machine->stack.push(machine->PC.value); }) },
        { OP_RET, std::make_tuple(false, [](auto machine, auto reg, auto val) {
                                                                                            machine->PC.value = machine->stack.top();
                                                                                            machine->stack.pop();
                                                                                        }) },
        { OP_SBUF, std::make_tuple(true, [](auto machine, auto reg, auto val) { printf(std::to_string(val).c_str()); }) }
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

        do
        {
            instruction = Fetch();
            Evaluate(instruction);
            Machine->Print();
            std::this_thread::sleep_for(std::chrono::seconds(1));
        } while (Model::OpCode::GetBaseOpCode(instruction) != OP_END);

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

        //TODO: oh god, getting so ugly
        if (OpWorkMap.find(base_code) != OpWorkMap.end())
        {
            RefetchAndExecute(instruction, OpWorkMap[base_code]);
        }
    }

    //TODO: design flaw with op codes... need to make unique op code for dual register operation as well
    void MachineService::RefetchAndExecute(const WORD& instruction, OP_FUNCTION work)
    {
        auto reg = GetRegister(instruction);
        WORD val = 0;

        if (std::get<0>(work))
        {
            val = Fetch();
        }
        std::get<1>(work)(Machine, reg, val);
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