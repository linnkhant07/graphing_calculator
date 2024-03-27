#include "rpn.h"
#include "../queue/MyQueue.h"
#include "../stack/MyStack.h"
#include "../token/token.h"
#include "../token/integer.h"
#include "../token/operator.h"
#include "../shunting_yard/shunting_yard.h"
#include <iostream>
#include <math.h>

using namespace std;

// man proposes god disposes

void RPN::set_input(Queue<Token *> iniQueue)
{
    postFix = iniQueue;
}
double RPN::operator()(double value)
{
    // DON'T DESTROYY!!!! WE WILL REPEAT THIS
    Stack<Token *> stack; // to store the integers

    // to repeat
    for (Queue<Token *>::Iterator it = postFix.begin(); it != postFix.end(); it++)
    {
        Token *temp = *it;

        int type = temp->type();
        // if it is integer
        switch (type)
        {
        case INTEGER:
            stack.push(temp);
            break;

        case VARIABLE:
            stack.push(new Integer(value));
            break;

        case OPERATOR:
        {
            Token *operand1 = stack.pop();
            Token *operand2 = stack.pop();

            Token *result = castOP(temp)->eval(operand2, operand1);

            double result_d = castInt(result)->value();
            if (isnan(result_d) || isinf(result_d))
                return nan("");
            stack.push(result);
            // double num_result = stod(result->token());
            // stack.push(new Integer(num_result));
        }
        break;

        case FUNCTION:
        {
            int arg = castFunc(temp)->num_of_args();
            // check the number of arguments
            switch (arg)
            {
            case 1:
            {
                Token *operand = stack.pop();

                Token *result = castFunc(temp)->eval(operand);
                double result_d = castInt(result)->value();
                if (isnan(result_d) || isinf(result_d))
                    return nan("");
                stack.push(result);
            }

            break;

            case 2:
            {
                Token *operand1 = stack.pop();
                Token *operand2 = stack.pop();

                Token *result = castFunc(temp)->eval(operand2, operand1);
                double result_d = castInt(result)->value();
                if (isnan(result_d) || isinf(result_d))
                    return nan("");
                stack.push(result);
            }
            break;

            default:
                assert(false);
            }
        }
        break;

        default:
            assert(false);
        }
    }

    /*
    while (!postFix.empty())
    {
        Token *temp = postFix.pop();

        int type = temp->type();
        // if it is integer
        switch (type)
        {
        case INTEGER:
            stack.push(temp);
            break;

        case VARIABLE:
            stack.push(new Integer(value));
            break;

        case OPERATOR:
        {
            Token *operand1 = stack.pop();
            Token *operand2 = stack.pop();

            Token *result = castOP(temp)->eval(operand2, operand1);
            stack.push(result);
            // double num_result = stod(result->token());
            // stack.push(new Integer(num_result));
        }
        break;

        case FUNCTION:
        {
            int arg = castFunc(temp)->num_of_args();
            // check the number of arguments
            switch (arg)
            {
            case 1:
            {
                Token *operand = stack.pop();

                Token *result = castFunc(temp)->eval(operand);
                stack.push(result);
            }

            break;

            case 2:
            {
                Token *operand1 = stack.pop();
                Token *operand2 = stack.pop();

                Token *result = castFunc(temp)->eval(operand2, operand1);
                stack.push(result);
            }
            break;

            default:
                assert(false);
            }
        }
        break;

        default:
            assert(false);
        }
    }*/

    // only one double (final result) left
    double result = castInt(stack.pop())->value();
    if (isnan(result) || isinf(result))
        return nan("");

    return result;
}

/*
function evaluateRPN(expression):
    inputQueue = convertToRPN(expression)   // convert infix expression to RPN using shunting yard algorithm
    stack = empty stack

    while inputQueue is not empty:
        token = dequeue(inputQueue)
        if token is a number:
            push(stack, token)
        else if token is an operator:
            operand2 = pop(stack)
            operand1 = pop(stack)
            result = evaluate(operand1, operand2, token)
            push(stack, result)

    return pop(stack)
*/