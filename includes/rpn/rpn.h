#ifndef RPN_H
#define RPN_H

#include <iostream>
#include <string>
#include "../token/token.h"
#include "../queue/MyQueue.h"

using namespace std;

// calculate infixes from shunting_yard

class RPN
{
public:
    RPN() {}
    RPN(Queue<Token *> &inputQueue) : postFix(inputQueue) {}
    void set_input(Queue<Token *> iniQueue);
    double operator()(double value = 0);

private:
    Queue<Token *> postFix;
};

#endif
