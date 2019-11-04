#include <string>
#include <vector>
#include "passagetoken.h"
#include "storytokenizer.h"
using namespace std;


PassageToken::PassageToken()
{
    name = "";
    text = "";
}

PassageToken::PassageToken(string str1, string str2)
{
    name = str1;
    text = str2;
}


//finds the name within the data
string PassageToken::getName()
{
    return name;
    
}

//extracts text from the story.
string PassageToken::getText()
{
    return text;
}