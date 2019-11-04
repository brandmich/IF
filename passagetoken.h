#ifndef PASSAGETOKEN_H
#define PASSAGETOKEN_H

#include <string>

using namespace std;

class PassageToken
{

    private:
    string name;
    string text;

    public:
    PassageToken();
    PassageToken(string str1, string str2);
    string getName();
    string getText();
};

#endif
