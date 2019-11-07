#include <string>
#include "link.h"
using namespace std;

//default constructor
Link::Link()
{
    hasGT = false;
    display = "";
    target = "";
}

Link::Link(string dis, string tar)
{
    display = dis;
    target = tar;
}

void Link::setHasGT(string gt)
{
    if(gt == "-&gt;")
    {
        hasGT = true;
    }
    else
    {
        hasGT = false;
    }
    
}

void Link::setDisplay(string dis)
{
    display = dis;
}

void Link::setTarget(string tar)
{
    if(hasGT != NULL && hasGT == true)
    {
        target = tar;
    }
    else
    {
        target = display;
    }
    
}