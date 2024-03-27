#ifndef TOKENIZER_H
#define TOKENIZER_H
#include <iostream>
#include <string.h>
#include "../queue/MyQueue.h"
#include "token.h"

using namespace std;

class Tokenizer
{

public:
    Tokenizer(string input) : _input(input) {}
    Queue<Token *> tokenize();

private:
    string _input;
    Queue<Token *> _infix;
};

#endif