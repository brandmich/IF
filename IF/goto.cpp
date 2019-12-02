#include "goto.h"

using namespace std;

GoTo::GoTo(string _text){
    int f = _text.find("&quot;");
    int l = _text.find("&quot;", f + 1);
    target = _text.substr(f + 6, l - f - 6);
}

string GoTo::print() const {
    return "target=" + target;
}