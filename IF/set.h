#pragma once
#include "command.h"
using namespace std;

class Set : public Command{
    private:
        string var;
        string val;
    public:
        Set(string);
        string print() const;
};