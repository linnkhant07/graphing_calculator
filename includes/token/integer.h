#ifndef INTEGER_H
#define INTEGER_H
#include <iostream>
#include <string>
#include <iomanip>
#include "token.h"
#include "constants.h"

using namespace std;

class Integer : public Token
{
public:
    // integer type is 1: these are enums! {INTEGER, OPERATOR}
    Integer(double i = 0) : Token(to_string(i), INTEGER), _value(i) {}
    Integer(const string &n = "0.0") : Token(n, INTEGER), _value(stod(n)) {}
    void int_only() { cout << "hello from integer!"; }
    void Print(ostream &outs) const { outs << fixed << setprecision(2) << _value << " "; }
    double value() { return _value; }

private:
    double _value;
};

#endif
