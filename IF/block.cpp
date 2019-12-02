#include "block.h"
#include <iostream>
#include "text.h"
#include "link.h"
#include "goto.h"
#include "set.h"
#include "if.h"

using namespace std;

Block::Block(string _text){
    string inside_text = _text.substr(1, _text.length() - 2);
    tokenizer = PassageTokenizer(inside_text);
    //cout << "TEST: " << inside_text << endl;
}

void Block::print() {
    //string output = "";
    cout << "START BLOCK" << endl;
    while (tokenizer.hasNextPart())
        {
            PartToken stok = tokenizer.nextPart();
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
        }
    cout << "END BLOCK" << endl;
}