#include "PassageTokenizer.h"
#include "PartToken.h"
#include <string>
#include <sstream>
#include <vector>

using namespace std;

bool PassageTokenizer::hasNextPart() const {
    return parts.size() > 0;
}

PartToken PassageTokenizer::nextPart() {
    PartToken rer = parts.back();
    parts.pop_back();
    return rer;
}

vector<PartToken> PassageTokenizer::processPart(string text){
    vector<PartToken> rer;
    string r_text = text;
    while(r_text.length() > 0){
        if(r_text.at(0) == '('){
            //button
            int start = 0;
            int end = r_text.find(")") + 1;
            string p_text = r_text.substr(start, end - start);
            string p_type_temp = p_text.substr(1, p_text.find(":") - 1);
            PartType p_type;
            if(p_type_temp == "set"){
                p_type = SET;
            }
            else if(p_type_temp == "go-to"){
                p_type = GOTO;
            }
            else if(p_type_temp == "if"){
                p_type = IF;
            }
            else if(p_type_temp == "else"){
                p_type = ELSE;
            }
            else{
                p_type = ELSEIF;
            }
            rer.insert(rer.begin(), PartToken(p_type, p_text));          
            r_text = r_text.substr(end, (r_text.length() - end));
            //rer.push_back(PartToken(TEXT, r_text));
        }
        else if(r_text.substr(0, 2) == "[[" && r_text.substr(0, 3) != "[[["){
            //link
            int start = 0;
            int end = r_text.find("]]") + 2;
            string p_text = r_text.substr(start, (end - start));
            PartType p_type = LINK;
            rer.insert(rer.begin(), PartToken(p_type, p_text));    
            r_text = r_text.substr(end, (r_text.length() - end));
            //rer.push_back(PartToken(TEXT, r_text));
        }
        else if(r_text.at(0) == '['){
            //block
            int start = 0;
            int end = r_text.find("]") + 1;
            if(r_text.substr(end - 1, 2) == "]]"){
                end += 1;
            }
            string p_text = r_text.substr(start, (end - start));
            PartType p_type = BLOCK;
            rer.insert(rer.begin(), PartToken(p_type, p_text));    
            r_text = r_text.substr(end, (r_text.length() - end));
            //rer.push_back(PartToken(TEXT, r_text));
        }
        else{
            //text
            int start = 0;
            int b_start = r_text.find("(");
            int bl_start = r_text.find("[");
            int end;
            if(b_start == string::npos && bl_start == string::npos){
                end = r_text.length();
            }
            else if(b_start == string::npos){
                end = bl_start;
            }
            else if(bl_start == string::npos){
                end = b_start;
            }
            else{
                if(b_start < bl_start)
                    end = b_start;
                else
                    end = bl_start;
            }
            string p_text = r_text.substr(start, (end - start));
            PartType p_type = TEXT;
            rer.insert(rer.begin(), PartToken(p_type, p_text));          
            r_text = r_text.substr(end, (r_text.length() - end));
            //rer.push_back(PartToken(TEXT, r_text));
        }
    }
    return rer;
}

PassageTokenizer::PassageTokenizer(string text){
    parts = processPart(text);
}

PassageTokenizer::PassageTokenizer(){
    
}

PassageTokenizer::~PassageTokenizer(){

}