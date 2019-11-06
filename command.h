#ifndef COMMAND_H
#define COMMAND_H
#include <string>
using namespace std;

class Command
{
    private:
    bool value;
    string variable;
    public:
    void setVar(string);
    void setVal(string);
    void setTarget(string);
};
#endif