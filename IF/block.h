#pragma once
#include <string>
#include "PassageTokenizer.h"
using namespace std;

class Block{
    private:
        PassageTokenizer tokenizer;
    public:
        Block(string);
        void print();
};