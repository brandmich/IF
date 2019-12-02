#include "passagetoken.h"
#include "storytokenizer.h"
#include <string>
#include <sstream>
#include <vector>

using namespace std;

bool StoryTokenizer::hasNextPassage() const {
    return passages.size() > 0;
}

PassageToken StoryTokenizer::nextPassage(){
    PassageToken rer = passages.back();
    passages.pop_back();
    return rer;
}

vector<PassageToken> StoryTokenizer::processPassage(string story){
    int start = story.find("<tw-passagedata");
    int end = story.find("</tw-storydata>") - 1;
    story = story.substr(start, end-start);
    string line;
    stringstream ss;
    vector<PassageToken> output;
    ss.str(story);
    while(getline(ss, line)){
        int name_start = line.find("name=\"") + 6;
        int name_end = line.find("\"", name_start);
        string name = line.substr(name_start, name_end - name_start);
        int text_start = line.find(">", name_end) + 1;
        int text_end = line.find("</tw-passagedata>", text_start);
        string text = line.substr(text_start, text_end - text_start);
        PassageToken token(name, text);
        output.insert(output.begin(), token);
    }
    return output;
}

StoryTokenizer::StoryTokenizer(string story){
    passages = processPassage(story);
}

StoryTokenizer::StoryTokenizer(){
    
}

StoryTokenizer::~StoryTokenizer(){

}