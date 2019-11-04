#include <string>
#include "partToken.h"
using namespace std;


//default constructor
PartToken::PartToken()
{
    text = "";
    type = "TEXT";

}

PartToken::PartToken(string str1, string str2)
{
    text = str1;
    type = str2;
}


//finds text in the part of the passage
string PartToken::getText()
{
    return text;
}


//returns the type of text that was returned
int PartToken::getType()
{
    if(type == "LINK")
        return 1;
    if(type == "SET:")
        return 2;
    if(type == "GO-TO:")
        return 3;
    if(type == "IF:")
        return 4;
    if(type == "ELSE-IF:")
        return 5;
    if(type == "ELSE:")
        return 6;
    if(type == "BLOCK")
        return 7;
    if(type == "TEXT")
        return 8;
    else
    {
        return -1;
    }
}