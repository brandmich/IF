#include "if.h"

using namespace std;

If::If(string _text){
    int ff = _text.find("$");
    int sf = _text.find(" ", ff + 1);
    var = _text.substr(ff + 1, sf - ff - 1);
    int fs = _text.find(" is ");
    val = _text.substr(fs + 4, _text.length() - fs - 5);
}

string If::print() const {
    return "var=" + var + ", value=" + val;
}