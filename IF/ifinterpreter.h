#pragma once
#include <string>
#include <vector>
#include "storytokenizer.h"
using namespace std;

class IFInterpreter {
    public:
        StoryTokenizer st;
        IFInterpreter(string);
        IFInterpreter();
        void print();
};