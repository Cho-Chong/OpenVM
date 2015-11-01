#ifndef BREAKPOINT_H
#define BREAKPOINT_H

namespace Model
{
    class BreakPoint
    {
    public:
        BreakPoint() {}
        ~BreakPoint() {}

        unsigned int LineNumber;
        bool IsActive;
    private:
    };
}

#endif /*BREAKPOINT_H*/
