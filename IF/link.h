#pragma once
#include <string>
using namespace std;

class Link {
    private:
        string display;
        string target;
    public:
        Link(string);
        string print() const;
};