#pragma once
#include <string>
using namespace std;

class Text {
    private:
        string text;
    public:
        Text(string);
        string print() const;
};