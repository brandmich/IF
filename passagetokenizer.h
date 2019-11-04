#ifndef PASSAGETOKENIZER_H
#define PASSAGETOKENIZER_H

#include <string>
#include <vector>
#include "partToken.h"
using namespace std;

class PassageTokenizer //change to PassageTokenizer
{
    private:
    string currPassage;
    int curr;
    string type;
    string text;
    int level;
    char currChar;

    public:
    PartToken nextPart();
    bool hasNextPart();

    PassageTokenizer();
    PassageTokenizer(string passage);

    friend PassageToken;
    friend StoryTokenizer;

};
#endif