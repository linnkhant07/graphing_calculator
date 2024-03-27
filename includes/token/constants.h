#ifndef CONSTANTS_RPN_H
#define CONSTANTS_RPN_H
#include <iostream>
#include <string>

// DO ENUM
enum TOKEN_TYPES
{
    INTEGER = 1,
    OPERATOR,
    VARIABLE,
    LEFT_PAREN,
    RIGHT_PAREN,
    FUNCTION = 10
};

#endif