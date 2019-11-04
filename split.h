#ifndef SPLIT_H
#define SPLIT_H
#include <vector>
#include <string>
using namespace std;


//splits string into multiple strings into a vector
vector<string> split(string str, char ch = ' ')
{
    vector<string> vec;
    int loc = str.find(ch);
    vec.push_back(str.substr(0, loc-1));
    int prevloc = 0;

    while(loc != string::npos)
    {
        vec.push_back(str.substr(prevloc, loc-prevloc));
        prevloc = loc +1;
        loc = str.find(ch, loc+1);
    }
    vec.push_back(str.substr(prevloc));

    return vec;
}

#endif