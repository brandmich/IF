#include <string>
#include "command.h"
using namespace std;

//default constructor
Command::Command()
{
    value = false;
    variable = "";
    target = "";
}

Command::Command(string var, string tar)
{
    variable = var;
    target = tar;
}

void Command::setVar(string var)
{
    variable = var;
}

void Command::setVar(string tar)
{
    target = tar;
}

void Command::setVal(string val)
{
    if(val == "true")
        value = true;
    else
        value = false;
}

