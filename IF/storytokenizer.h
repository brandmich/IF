#pragma once
#include <string>
#include <vector>
#include "passagetoken.h"

using namespace std;

class StoryTokenizer{
    private:
        vector<PassageToken> passages;
        string title;
        //PassageToken processPassage(string);
    public:
        bool hasNextPassage() const;
        PassageToken nextPassage();
        vector<PassageToken> processPassage(string);
        StoryTokenizer(string);
        StoryTokenizer();
        ~StoryTokenizer();
};