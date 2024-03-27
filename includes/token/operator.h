#ifndef OPERATOR_H
#define OPERATOR_H
#include <iostream>
#include <string>
#include "token.h"
#include "constants.h"

using namespace std;

class Operator : public Token
{
public:
    Operator(const string &op) : Token(op, OPERATOR)
    {
        _prec = find_prec();
    }

    int find_prec();
    int get_prec() { return _prec; }
    Token *eval(Token *left, Token *right);
    void Print(ostream &outs) const { outs << token(); }

private:
    int _prec;
};

#endif