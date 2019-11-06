#ifndef ifElse
#define ifElse
#include "command.h"

class ifElse : public Command
{
    private:
    string variable;
    bool value;
    public:
    void setVar(string);
    void setVal(string);
    ifElse();
    ifElse(string);
};
#endif