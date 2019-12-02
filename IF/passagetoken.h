#pragma once
#include <string>
using namespace std;
class PassageToken {
    private:
        string name;
        string text;
    public:
        string getName() const;
        string getText() const;
        PassageToken();
        PassageToken(string, string);
        ~PassageToken();
};