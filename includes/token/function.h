#ifndef FUNCTION_H
#define FUNCTION_H
#include "operator.h"
#include <assert.h>
#include <iostream>
#include <string>
#include "constants.h"

using namespace std;

class Function : public Token
{
public:
    Function(const string &func, int args) : _args(args), Token(func, FUNCTION) {}
    int num_of_args() { return _args; }

    Token *eval(Token *left, Token *right); // two arg functions
    Token *eval(Token *arg);                // one arg functions
    void Print(ostream &outs) const { outs << token() << "<f>"; }

private:
    int _args;
};

#endif