#pragma once
#include "command.h"
using namespace std;

class If : public Command{
    private:
        string var;
        string val;
    public:
        If(string);
        string print() const;
};