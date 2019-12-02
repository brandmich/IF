#pragma once
#include "command.h"
using namespace std;

class GoTo : public Command{
    private:
        string target;
    public:
        GoTo(string);
        string print() const;
};