#include <iostream>
#include "SimpleMnemonic.h"
#include "OpCodes.h"
#include "AssemblyParser.h"
#include "ProgramParser.h"
#include "Machine.h"
#include "MachineService.h"
#include "SimpleMnemonic.h"

int main()
{
    Service::ProgramParser programParser;
    Service::AssemblyParser assemblyParser(&SIMPLE_INSTRUCTION_SET);
    Model::Machine machine(MAX_CODE_SIZE, MAX_DATA_SIZE);
    Service::MachineService machineService(&machine);
    PROGRAM_ASSEMBLY_MAP debugger_map;

    auto assembly = programParser.Parse("Test.txt");
    assemblyParser.Parse(assembly, 0x0000, machine.Program, debugger_map);
    machineService.Execute();
    
    return 0;
}

