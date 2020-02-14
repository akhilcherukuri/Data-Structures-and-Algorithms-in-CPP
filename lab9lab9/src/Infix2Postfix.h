/*
 *  Infix2Postfix.h
 *
 *  Created on: Nov 23, 2019
 *  Author: akhilcherukuri
 */

#ifndef INFIX2POSTFIX_H_
#define INFIX2POSTFIX_H_

#include <iostream>
#include <string>

using namespace std;

struct nodeType
{
char data;
nodeType *link;
};

class stack_I2P{
	friend ostream& operator << (ostream&, stack_I2P&);
public:
void initializeStack();
void push(const char& newItem);
bool empty();
char top();
void pop();
stack_I2P();
~stack_I2P();
string infixToPostfix(string);
nodeType *stackTop;
//bool isOperand(char C);
//bool IsOperator(char C);
//int Priority(char op);
//int HigherPriority(char op1, char op2);
};




#endif /* INFIX2POSTFIX_H_ */
