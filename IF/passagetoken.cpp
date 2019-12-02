
#include "passagetoken.h"
#include <string>

using namespace std;

string PassageToken::getName() const {
    return name;
}

string PassageToken::getText() const {
    return text;
}

PassageToken::PassageToken(){
    name = "";
    text = "";
}

PassageToken::PassageToken(string _name, string _text){
    name = _name;
    text = _text;
}

PassageToken::~PassageToken(){
    
}
