#pragma once
#include "PartToken.h"
#include <string>
#include <vector>
using namespace std;
class PassageTokenizer {
    private:
        vector<PartToken> parts;
    public:
        static vector<PartToken> processPart(string);
        bool hasNextPart() const;
        PartToken nextPart();
        PassageTokenizer();
        PassageTokenizer(string);
        ~PassageTokenizer();
};