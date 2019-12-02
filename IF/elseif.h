#pragma once
#include "command.h"
using namespace std;

class ElseIf : public Command{
    private:
        string var;
        string val;
    public:
        ElseIf(string);
        string print() const;
};