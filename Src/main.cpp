#include <iostream>
#include "SimpleMnemonic.h"
#include "OpCodes.h"
#include "AssemblyParser.h"
#include "ProgramParser.h"
#include "Machine.h"
#include "MachineService.h"
#include "SimpleMnemonic.h"
#include "DebugService.h"

Service::ProgramParser programParser;
Service::AssemblyParser assemblyParser(&SIMPLE_INSTRUCTION_SET);
Model::Machine machine(MAX_CODE_SIZE, MAX_DATA_SIZE);
Service::MachineService machineService(&machine);
Service::DebugService debugService;

int main()
{
    
    return 0;
}

void Compile(const char* file)
{
    auto assembly = programParser.Parse(file);
    assemblyParser.Parse(assembly, 0x0000, machine.Program, debugService.debuggerMap);
}

void Run()
{
    machineService.Execute();
}
