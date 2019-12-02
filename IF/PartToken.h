#pragma once
#include <string>
using namespace std;
namespace std {
    enum PartType {LINK, SET, GOTO, IF, ELSEIF, ELSE, BLOCK, TEXT};
}
class PartToken {
    private:
        PartType type;
        string text;
    public:
        PartType getType() const;
        string getText() const;
        PartToken();
        PartToken(PartType, string);
        ~PartToken();
};