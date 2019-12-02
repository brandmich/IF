#include "text.h"

using namespace std;

Text::Text(string _text){
    text = _text;
}

string Text::print() const {
    return "\"" + text + "\"";
}