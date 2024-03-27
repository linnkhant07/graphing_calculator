#ifndef LEFTPAREN_H
#define LEFTPAREN_H
#include "operator.h"
#include <assert.h>
#include <iostream>
#include <string>
#include "constants.h"

using namespace std;

class LeftParen : public Token
{
public:
    LeftParen() : Token("(", LEFT_PAREN) {}
    void Print(ostream &outs) const { outs << token(); }
};

#endif