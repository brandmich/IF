#ifndef LINK_H
#define LINK_H
#include<string>
using namespace std;

class Link
{
    private:
    bool hasGT;
    string display;
    string target;

    public:
    void setHasGT(bool);
    void setDisplay(string);
    void setTarget(string);
};

#endif