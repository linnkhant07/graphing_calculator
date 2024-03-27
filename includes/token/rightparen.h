#ifndef RIGHTPAREN_H
#define RIGHTPAREN_H
#include "operator.h"
#include <assert.h>
#include <iostream>
#include <string>
#include "constants.h"

using namespace std;

class RightParen : public Token
{
public:
    RightParen() : Token(")", RIGHT_PAREN) {}
    void Print(ostream &outs) const { outs << token(); }
};

#endif