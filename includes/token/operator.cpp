#include "operator.h"
#include <assert.h>
#include <iostream>
#include <string>
#include <math.h>
#include "integer.h"
#include "../graphing/miscellanous.h"

using namespace std;

int Operator::find_prec()
{
    switch (token()[0])
    {

    case '-':
        return 1;
    case '+':
        return 1;
    case '/':
        return 2;
    case '*':
        return 2;
    case '^':
        return 3;
    default:
        assert(false);
    }
}

Token *Operator::eval(Token *left, Token *right)
{
    // change string to double first
    double num_l = stod(left->token());
    double num_r = stod(right->token());

    // we need a character - token is string
    switch (token()[0])
    {

    case '-':
        return new Integer(num_l - num_r);
    case '+':
        return new Integer(num_l + num_r);
    case '/':
    {

        if (double_equals(num_r, 0.000000))
            return new Integer(nan(""));

        return new Integer(num_l / num_r);
    }

    case '*':
        return new Integer(num_l * num_r);
    case '^':
        return new Integer(pow(num_l, num_r));

    default:
        assert(false);
    }
}