#ifndef GOTO_H
#define GOTO_H
#include "command.h"

class Goto : public Command
{
    private:
    string target;
    public:
    void setTarget(string);
    Goto();
    Goto(string);
};
#endif
