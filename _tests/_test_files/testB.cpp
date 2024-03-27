#include "gtest/gtest.h"
#include <cmath>
#include <iostream>
#include <iomanip>
#include <set>
#include <vector>

//------------------------------------------------------------------------------------------
// Files we are testing:

#include "../../includes/token/token.h"
#include "../../includes/token/tokenizer.h"
#include "../../includes/token/operator.h"
#include "../../includes/token/integer.h"
#include "../../includes/token/function.h"
#include "../../includes/token/leftparen.h"
#include "../../includes/token/rightparen.h"
#include "../../includes/token/constants.h"

#include "../../includes/queue/MyQueue.h"

#include "../../includes/shunting_yard/shunting_yard.h"
#include "../../includes/rpn/rpn.h"
using namespace std;

bool test_shunting_yard(bool debug = false)
{

  if (debug)
  {
    //(5 + 3 * 2 - 1) / (4 - 2) / 3
    Queue<Token *> infix;
    infix.push(new LeftParen());
    infix.push(new Integer(5));
    infix.push(new Operator("+"));
    infix.push(new Integer(3));
    infix.push(new Operator("*"));
    infix.push(new Integer(2));
    infix.push(new Operator("-"));
    infix.push(new Integer(1));
    infix.push(new RightParen());
    infix.push(new Operator("/"));
    infix.push(new LeftParen());
    infix.push(new Integer(4));
    infix.push(new Operator("-"));
    infix.push(new Integer(2));
    infix.push(new RightParen());
    infix.push(new Operator("/"));
    infix.push(new Integer(3));

    ShuntingYard sy(infix);
    Queue<Token *> postfix = sy.postfix();
    for (Queue<Token *>::Iterator it = postfix.begin(); it != postfix.end(); it++)
    {
      (*it)->Print(cout);
      // cout << setw(3) << (*it)->token();
    }
    cout << endl;
    // 5 3 2 * + 1 - 4 2 - / 3 /
  }
  return true;
}

bool test_rpn(bool debug = false)
{
  if (debug)
  {
    //(5 + 3 * 2 - 1) / (4 - 2) / 3
    Queue<Token *> infix;
    infix.push(new LeftParen());
    infix.push(new Integer(5));
    infix.push(new Operator("+"));
    infix.push(new Integer(3));
    infix.push(new Operator("*"));
    infix.push(new Integer(2));
    infix.push(new Operator("-"));
    infix.push(new Integer(1));
    infix.push(new RightParen());
    infix.push(new Operator("/"));
    infix.push(new LeftParen());
    infix.push(new Integer(4));
    infix.push(new Operator("-"));
    infix.push(new Integer(2));
    infix.push(new RightParen());
    infix.push(new Operator("/"));
    infix.push(new Integer(3));

    ShuntingYard sy(infix);
    Queue<Token *> postfix = sy.postfix();
    RPN rpn(postfix);
    cout << "(5 + 3 * 2 - 1) / (4 - 2) / 3 = " << rpn() << endl;
    // 1.66667
  }
  return true;
}

bool free_test(bool debug = false)
{
  /*
  int x = VARIABLE;
  cout << "x is " << x << endl;
  cout << "free testing\n";*/

  Token *t = new Function("sin", 1);
  // cout << "function is " << t << endl;

  return true;
}

bool test_func(bool debug = false)
{
  if (debug)
  {
    // sin (4 + 2) / tan (pow(2,3))
    Queue<Token *> infix;
    infix.push(new Function("sin", 1));
    infix.push(new LeftParen());
    infix.push(new Integer(4));
    infix.push(new Operator("+"));
    infix.push(new Integer(2));
    infix.push(new RightParen());
    infix.push(new Operator("/"));
    infix.push(new Function("tan", 1));
    infix.push(new LeftParen());
    infix.push(new Function("pow", 2));
    infix.push(new LeftParen());
    infix.push(new Integer(2));
    infix.push(new Integer(3));
    infix.push(new RightParen());
    infix.push(new RightParen());

    ShuntingYard sy(infix);
    Queue<Token *> postfix = sy.postfix();
    RPN rpn(postfix);
    cout << "sin (4 + 2) / tan (pow(2,3)) = " << rpn() << endl;
    // bro I got it right at the first test...siuu
    //  0.04109225811

    // sin -3.14
    Queue<Token *> infix2;

    infix2.push(new Function("sin", 1));
    infix2.push(new Function("-", 1));
    infix2.push(new Integer(3.14));

    ShuntingYard sy2(infix2);
    Queue<Token *> postfix2 = sy2.postfix();
    RPN rpn2(postfix2);
    cout << "sin -3.14 = " << rpn2() << endl;

    //-0.001592

    // tan sin 1.07
    Queue<Token *> infix3;

    infix3.push(new Function("tan", 1));
    infix3.push(new Function("sin", 1));
    infix3.push(new Integer(1.07));

    ShuntingYard sy3(infix3);
    Queue<Token *> postfix3 = sy3.postfix();
    RPN rpn3(postfix3);
    cout << "tan sin 1.07 = " << rpn3() << endl;

    // 1.20279
  }
  return true;
}

bool test_tokenizer(bool debug = false)
{
  if (debug)
  {
    string str;
    cout << "Enter a function y = ";
    getline(cin, str);
    Tokenizer tokenizer(str);
    Queue<Token *> q = tokenizer.tokenize();
    cout << q << endl;
  }

  return true;
}

TEST(TEST, FreeTest)
{
  EXPECT_EQ(1, free_test(true));
}

TEST(TEST_RPN, TestShuntingYard)
{
  EXPECT_EQ(1, test_shunting_yard(true));
}

TEST(TEST_RPN, TestRPN)
{
  EXPECT_EQ(1, test_rpn(true));
}

TEST(TEST_RPN, TestFunc)
{
  EXPECT_EQ(1, test_func(true));
}

TEST(TEST_RPN, TestTokenizer)
{
  EXPECT_EQ(1, test_tokenizer(true));
}

int main(int argc, char **argv)
{
  ::testing::InitGoogleTest(&argc, argv);
  std::cout << "\n\n----------running testB.cpp---------\n\n"
            << std::endl;
  return RUN_ALL_TESTS();
}
