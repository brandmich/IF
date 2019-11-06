#ifndef COMMAND_H
#define COMMAND_H
#include <string>
using namespace std;

class Command
{
    private:
    bool value;
    string variable;
    string target;
    public:
    void setVar(string);
    void setVal(string);
    void setTarget(string);
    command();
    command(string, string);//var, target
};
#endif