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

            WORDS byte_codes = subject.Parse(assembly);
            /* expected byte code
            0x0000 0x39 0x14
            0x0002 0x09
            0x0003 0x39
            */
            Assert::IsTrue(byte_codes[0] == 0);
        }

        //TODO: lower level unit tests

    };
}
