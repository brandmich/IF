#include <string>
#include <vector>
#include <iostream>
#include <ostream>
using namespace std;
#include "storytokenizer.h"
#include "passagetoken.h"
#include "split.h"

StoryTokenizer::StoryTokenizer()
{
    int curr = 0;
    start = 0;
    end = 0;
    string next = "";
    string name = "";
    string text = "";

}

//splits story and data into vector story then brings current position to first instance of data.
StoryTokenizer::StoryTokenizer(string storyRead)
{
    temp = split(storyRead, '\n');
    curr = 0;

    //finds where the story begins
    while(temp.at(curr).substr(0, 15) != "<tw-passagedata")
    {
        curr++;
    }
    
    for(; curr < temp.size(); curr++)
    {
        story.push_back(temp[curr]);
    }
    curr = 0;
    //next = story.at(curr);
    /*for(int i = 0; i < story.size(); i++)
    {
        cout << story[i] << endl;
    }*/

    start = 0;
    end = 0;
    name = "";
    text = "";

}

//tests to see if story is the end of the story data
bool StoryTokenizer::hasNextPassage()
{
    next = story.at(curr+1);
    if(next.empty())
    {
        
        return false;
    }
    else
    {
        return true;
    }
    
    
}

//goes to next passage if there is one
PassageToken StoryTokenizer::nextPassage()
{
    if(hasNextPassage())
    {
        //find name
        next = story.at(curr);
        start = next.find("name=", 0) + 5;
        end = next.find("\"", start + 1);
        end = end - start + 1;
        name = next.substr(start, end);


        //find text
        start = next.find("\">", 0) + 2;
        end = next.find("</", 0);
        end = end - start;
        text = next.substr(start, end);
        text += '\n';
        curr++;
        next= story.at(curr);

        return PassageToken(name, text);//returns the name and text
        
    
        
    }

    else
    {
        return PassageToken(); //returns empty
    }
    
}
