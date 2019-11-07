#include <string>
#include "set.h"
using namespace std;


//default constructor
Set::Set()
{
    variable = "";
    value = false;
}

Set::Set(string var)
{
    variable = var;
}

void Set::setVar(string var)
{
    variable = var;
}

void Set::setVal(string val)
{
    if(val == "true")
    {
        value = true;
    }
    else
    {
        value = false;
    }
    
}