#ifndef ALPHA_H
#define VARIALBE_H
#include "operator.h"
#include <assert.h>
#include <iostream>
#include <string>
#include "constants.h"

using namespace std;

class Variable : public Token
{
public:
    Variable() : variable("X"), Token("X", VARIABLE) {}
    Variable(string v) : variable(v), Token(v, VARIABLE) {}

    void Print(ostream &outs) const { outs << variable; }

private:
    string variable;
};

#endif