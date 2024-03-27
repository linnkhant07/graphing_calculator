#ifndef SHUNTING_YARD_H
#define SHUNTING_YARD_H
#include <iostream>
#include "../queue/MyQueue.h"
#include "../token/token.h"
#include "../token/operator.h"
#include "../token/function.h"
#include "../token/integer.h"

using namespace std;

Operator *castOP(Token *p);
Function *castFunc(Token *p);
Integer *castInt(Token *p);
// go from infix to postfix

class ShuntingYard
{
public:
    ShuntingYard() {}
    ShuntingYard(Queue<Token *> myQueue) : tokenQueue(myQueue) {}
    Queue<Token *> postfix();
    Queue<Token *> postfix(Queue<Token *> fixMe);
    void infix(Queue<Token *> fixMe);

private:
    Queue<Token *> tokenQueue;
};

#endif