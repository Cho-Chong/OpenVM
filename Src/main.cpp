#include <iostream>
#include "SimpleMnemonic.h"
#include "OpCodes.h"
#include "AssemblyParser.h"
#include "ProgramParser.h"
#include "Machine.h"
#include "MachineService.h"
#include "SimpleMnemonic.h"
#include "DebugService.h"

//Initate model of machine
Model::Memory Program(MAX_CODE_SIZE, CODE_START_ADDRESS);
Model::Memory Data(MAX_CODE_SIZE, DATA_START_ADDRESS);
Model::Machine machine(&Program, &Data);

//Initate services
Service::ProgramParser programParser;
Service::AssemblyParser assemblyParser(&SIMPLE_INSTRUCTION_SET);
Service::MachineService machineService(&machine);
Service::DebugService debugService;

int main()
{
    return 0;
}

void Compile(const char* file)
{
    auto assembly = programParser.Parse(file);
    assemblyParser.Parse(assembly, *machine.Program, debugService.DebuggerMap);
}

void Run()
{
    machineService.Execute();
}
