#ifndef ifElse
#define ifElse
#include "command.h"

class IfElse : public Command
{
    private:
    string variable;
    bool value;
    public:
    void setVar(string);
    void setVal(string);
    IfElse();
    IfElse(string);
};
#endif