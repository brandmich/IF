#include "PartToken.h"
#include <string>

using namespace std;

PartType PartToken::getType() const {
    return type;
}

string PartToken::getText() const {
    return text;
}

PartToken::PartToken(){
    type = TEXT;
    text = "";
}

PartToken::PartToken(PartType _type, string _text){
    type = _type;
    text = _text;
}

PartToken::~PartToken(){
    
}