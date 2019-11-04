#ifndef PARTTOKEN_H
#define PARTTOKEN_H

#include <string>
using namespace std;

class PartToken
{
    private:
    string text;
    string type;

    public:
    string getText();
    int getType();

    PartToken();
    PartToken(string str1, string str2);

};

#endif