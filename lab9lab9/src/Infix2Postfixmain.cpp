/*
 *  Infix2Postfixmain.cpp
 *
 *  Created on: Nov 23, 2019
 *  Author: akhilcherukuri
 */

#include <iostream>
#include <cassert>
#include <string>

#include "Infix2Postfix.h"

using namespace std;

int main(){
stack_I2P Expression;
string ex1;

ex1 = Expression.infixToPostfix("A+B-C");
cout << ex1 << endl;

ex1 = Expression.infixToPostfix("(A+B)*C");
cout << ex1 << endl;

ex1 = Expression.infixToPostfix("(A+B)*(C-D)");
cout << ex1 << endl;

ex1 = Expression.infixToPostfix("A+((B+C)*(E-F)-G)/(H-I)");
cout << ex1 << endl;

ex1 = Expression.infixToPostfix("A+B*(C+D)-E/F*G+H");
cout << ex1 << endl;

return 0;
}
