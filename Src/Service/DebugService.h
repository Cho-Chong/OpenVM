#ifndef DEBUGSERVICE_H
#define DEBUGSERVICE_H

#include "Configuration.h"
#include "Breakpoint.h"

namespace Service
{
    class DebugService
    {
    public:
        DebugService();
        ~DebugService();

        void StepOver();
        void StepInto();
        void StepOut();
        void RunTo();
        void SetBreakpoint();

        PROGRAM_ASSEMBLY_MAP DebuggerMap;
        std::vector<Model::BreakPoint> BreakPoints;
    };
}

#endif /*DEBUGSERVICE_H*/
