#include <assert.h>
#include <iostream>
#include <string>
#include <math.h>
#include "function.h"
#include "integer.h"
#include "../graphing/miscellanous.h"

using namespace std;

Token *Function::eval(Token *arg)
{
    // cast string to double
    double num = stod(arg->token());

    string func = token();
    if (func == "sin")
        return new Integer(sin(num));
    if (func == "cos")
        return new Integer(cos(num));
    if (func == "tan")
        return new Integer(tan(num));
    if (func == "cot")
    {
        if (double_equals(1 / tan(num), 0.0))
        {
            return new Integer(0.0);
        }

        return new Integer(1 / tan(num));
    }

    if (func == "sec")
        return new Integer(1 / cos(num));
    if (func == "csc")
        return new Integer(1 / sin(num));
    if (func == "-")
        return new Integer(num * -1);
    if (func == "sqrt")
    {

        if (num < 0.0)
        {
            return new Integer(nan(""));
        }
        return new Integer(sqrt(num));
    }
}
Token *Function::eval(Token *left, Token *right)
{
    double num_l = stod(left->token());
    double num_r = stod(right->token());

    string func = token();
    if (func == "pow")
        return new Integer(pow(num_l, num_r));
}
