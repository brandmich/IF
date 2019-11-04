#ifndef STORYTOKENIZER_H
#define STORYTOKENIZER_H

#include <string>
#include <vector>
#include "passagetoken.h"
using namespace std;

class StoryTokenizer
{
    private: 
    vector <string> story;
    vector <string> temp;
    int curr;
    string next;
    string name;
    string text;
    int start;
    int end;

    public:
    bool hasNextPassage();
    PassageToken nextPassage();  

    StoryTokenizer();
    StoryTokenizer(string story);
};
#endif