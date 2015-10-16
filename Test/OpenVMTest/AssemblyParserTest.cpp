#include "stdafx.h"
#include "CppUnitTest.h"
#include "AssemblyParser.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace OpenVMTest
{		
    TEST_CLASS(AssemblyParserTest)
    {
    public:
        Service::AssemblyParser subject;

        TEST_METHOD(CanParseSimpleInstructions)
        {
            ASSEMBLY assembly;

            //i.e.
            //MOV R1, 20
            //INC R1
            //MOV R1, A
            assembly.push_back("MOV R1, 20");
            assembly.push_back("INC R1");
            //assembly.push_back("MOV R1, A");

            subject.Parse(assembly);
        }

        //TODO: lower level unit tests

    };
}
