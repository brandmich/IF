#ifndef SET_H
#define SET_H
#include "command.h"

class Set : public Command
{
    private:
    string variable;
    bool value;

    public:
    void setVar(string);
    void setVal(bool);
};
#endif