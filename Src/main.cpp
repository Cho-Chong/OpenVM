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
Model::Memory program(MAX_CODE_SIZE, CODE_START_ADDRESS);
Model::Memory data(MAX_CODE_SIZE, DATA_START_ADDRESS);
Model::Machine machine(&program, &data);

//Initate services
Service::ProgramParser programParser;
Service::AssemblyParser assemblyParser(&SIMPLE_INSTRUCTION_SET);
Service::MachineService machineService(&machine);
Service::DebugService debugService;

void Compile(const std::string file);
void Run();

int main()
{
    Compile("C:\\Users\\Hero\\Documents\\Visual Studio 2015\\Projects\\OpenVM\\OpenVM\\src\\test.txt");
    Run();
    system("PAUSE");
    return 0;
}

void Compile(const std::string file)
{
    auto assembly = programParser.Parse(file);
    assemblyParser.Parse(assembly, *machine.Program, debugService.DebuggerMap);
}

void Run()
{
    machineService.Execute();
}
