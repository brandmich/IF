#include <string>
#include "goto.h"
using namespace std;

//Default constructor
Goto::Goto()
{
    target = "";
}

Goto::Goto(string tar)
{
    target = tar;
}

void Goto::setTarget(string tar)
{
    target = tar;
}