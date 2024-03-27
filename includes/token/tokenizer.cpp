#include <iostream>
#include <string.h>
#include "tokenizer.h"
#include "operator.h"
#include "leftparen.h"
#include "rightparen.h"
#include "integer.h"
#include "function.h"
#include "variable.h"

using namespace std;

Queue<Token *> Tokenizer::tokenize()
{
    // to check if - is unary
    bool isUnary = true;

    // loop through each character
    for (int i = 0; i < _input.size(); i++)
    {
        switch (tolower(_input[i]))
        {

        // ignore spaces
        case ' ':
            break;

        case ',':
        {
            // if - follows, it is unary
            isUnary = true;
            break;
        }

        case 'x':
        {
            _infix.push(new Variable("X"));
            isUnary = false; // if - follows, it is not unary
            break;
        }
        case '+':
        {
            _infix.push(new Operator("+"));
            isUnary = true;
            break;
        }
        case '-':
        {
            if (isUnary)
                _infix.push(new Function("-", 1));
            else
                _infix.push(new Operator("-"));

            isUnary = true;
            break;
        }
        case '*':
        {
            _infix.push(new Operator("*"));
            isUnary = true;
            break;
        }

        case '/':
        {
            _infix.push(new Operator("/"));
            isUnary = true;
            break;
        }
        case '^':
        {
            _infix.push(new Operator("^"));
            isUnary = true;
            break;
        }

        case '(':
        {
            _infix.push(new LeftParen());
            isUnary = true;
            break;
        }
        case ')':
        {
            _infix.push(new RightParen());
            isUnary = false;
            break;
        }
        default:
            // if it is a number
            if (isdigit(_input[i]))
            {
                //-48 to work with ASCII
                _infix.push(new Integer(static_cast<int>(_input[i]) - 48));
                isUnary = false;
            }
            // it is a function
            else
            {
                string func = "";
                // getting the function name
                while (i < _input.size() && _input[i] != '(')
                {
                    if (_input[i] == ' ')
                    {
                        // skip spaces
                        i++;
                        break;
                    }

                    // append the char to the string
                    func.push_back(_input[i]);
                    i++;
                }

                // now find for commans
                int j = i;
                int arg = 1; // argument count
                while (_input[j] != ')')
                {

                    if (_input[j] == ',')
                        arg++; // one comma - one more arg
                    j++;
                }

                _infix.push(new Function(func, arg));
                _infix.push(new LeftParen());
            }
            break;
        }
    }
    return _infix;
}
