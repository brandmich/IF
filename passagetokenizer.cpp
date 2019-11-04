#include <string>
#include <vector>
#include "storytokenizer.h"
#include <ostream>
#include <iostream>
#include "passagetokenizer.h"
using namespace std;

//default constructor
PassageTokenizer::PassageTokenizer()
{
    currPassage = "";
    curr = 0;
    type = "";
    text = "";
    level = 0;
    currChar = ' ';
}

PassageTokenizer::PassageTokenizer(string passage)
{
    currPassage = passage;
    curr = 0;
    type = "";
    text = "";
    level = 0;
    currChar = ' ';
}

//Returns next element
PartToken PassageTokenizer::nextPart()
{
    if(hasNextPart())
    {
        int i;
        
        for(i = curr;  currChar != '\n'; i++)
        {
            text = "";
            type = "";
            currChar = currPassage[i];

            //LINKS
            if(currChar == '[' && currPassage[i + 1] == '[')
            {
                while(currPassage[i-2] != ']' )
                {
                    currChar = currPassage[i];
                    text += currChar;
                    i++;
                }
                type = "LINK";
                curr = i; 
                return PartToken(text, type);
            }

            //COMMANDS
            if(currChar == '(')
            {
                currChar = currPassage[i];
                text += currChar;
                i++;
                while(currChar != ':')
                {
                    currChar = currPassage[i];
                    type += toupper(currChar);
                    text += currChar;
                    i++;
                }

                while(currPassage[i-1] != ')')
                {
                    currChar = currPassage[i];
                    text += currChar;
                    i++;
                }

                curr = i;
                return PartToken(text, type);
            }
            

            //TEXT
            if(currPassage[i+1] != '(' && currPassage[i+1] != ')' && (currChar != '[' && currPassage[i+1] != '['))
            {
                while(currPassage[i+1] != '(' && currPassage[i+1] != ')' && (currChar != '[' && currPassage[i+1] != '[')  && currChar != '\n')
                {
                    currChar = currPassage[i];
                    type = "TEXT";
                    text += currChar;
                    i++;
                }
                curr = i;
                return PartToken(text, type);
            }

            //BLOCKS
            if(currChar == '[' && currPassage[i+1] != '[')
            {
                int level = 1;
                text += currChar;
                i++;
                while(level != 0 && currPassage[i-2] != ']')
                {
                    currChar = currPassage[i];
                    type = "BLOCK";
                    
                    if(currChar == '[')
                        level++;
                    if(currChar == ']')
                        level--;

                    text += currChar;
                    i++;
                }
                curr = i;
                return PartToken(text, type);

            }

        }
       return PartToken();
    }   
    else
    {
        return PartToken();
    }
    
}

//check if there are any more elements (basically if there is more passage there is more elements)
bool PassageTokenizer::hasNextPart()
{
    int i;
    
    if(currChar != '\n')
    {
        currChar = currPassage[curr];
        return true;
    }
    else
    {
        curr = 0;
        return false;
    }
}