#include "link.h"

using namespace std;

Link::Link(string _text){
    int gt = _text.find("-&gt;");
    if(gt > -1){
        display = _text.substr(2, gt - 2);
        target = _text.substr(gt + 5, _text.length() - (gt + 7));
    }
    else{
        display = _text.substr(2, _text.length() - 4);
        target = display;
    }
}

string Link::print() const {
    return "display=" + display + ", target=" + target;
}