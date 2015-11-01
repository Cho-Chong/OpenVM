#ifndef DEBUGSERVICE_H
#define DEBUGSERVICE_H

#include "Configuration.h"

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

        PROGRAM_ASSEMBLY_MAP debuggerMap;
    };
}

#endif /*DEBUGSERVICE_H*/
