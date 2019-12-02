#include "ifinterpreter.h"
#include <iostream>
#include <string>
#include <fstream>
#include "storytokenizer.h"
#include "PassageTokenizer.h"
#include "text.h"
#include "link.h"
#include "goto.h"
#include "set.h"
#include "if.h"
#include "block.h"

using namespace std;

IFInterpreter::IFInterpreter(){
    
}

IFInterpreter::IFInterpreter(string file_name){
    string line, story;

    ifstream in(file_name);

    //Read in the story from input.txt
    getline(in, line);
    while (in && line != "</html>")
    {
        story += line + '\n';
        getline(in, line);
    }

    //Construct the StoryTokenizer object
    st = StoryTokenizer(story);
}

void IFInterpreter::print(){

    int pass = 0;
    while (st.hasNextPassage())
    {
        //Use the PassageToken to construct a PassageTokenizer
        PassageToken ptok = st.nextPassage();
        PassageTokenizer pt(ptok.getText());

        //Iterate through all of the parts of the passage
        cout << "Passage " << ptok.getName() << ":" << endl;
        while (pt.hasNextPart())
        {
            PartToken stok = pt.nextPart();
            switch (stok.getType())
            {
                case LINK:
                    cout << "Link:  ";
                    cout << Link(stok.getText()).print() << endl;
                    break;
                case SET:
                    cout << "Set:  ";
                    cout << Set(stok.getText()).print() << endl;
                    break;
                case GOTO:
                    cout << "Go-to:  ";
                    cout << GoTo(stok.getText()).print() << endl;
                    break;
                case IF:
                    cout << "If:  ";
                    cout << If(stok.getText()).print() << endl;
                    break;
                case ELSEIF:
                    cout << "Else-if:  ";
                    cout << If(stok.getText()).print() << endl;
                    break;
                case ELSE:
                    cout << "Else" << endl;
                    break;
                case BLOCK:
                    Block(stok.getText()).print();
                    break;
                case TEXT:
                    cout << "Text:  ";
                    cout << Text(stok.getText()).print() << endl;
                    break;
                default:
                    cout << "ERROR";
            }
            //cout << stok.getText() << endl;
        }
    }
}
