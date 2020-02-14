/*
 *  Infix2Postfix.cpp
 *
 *  Created on: Nov 23, 2019
 *  Author: akhilcherukuri
 */

#include <iostream>
#include <cassert>
#include <string>
//#include <stack>

#include "Infix2Postfix.h"

using namespace std;

stack_I2P::stack_I2P(){
stackTop = NULL;
}

void stack_I2P::initializeStack(){
nodeType *temp;
while (stackTop != NULL){
temp = stackTop;
stackTop = stackTop->link;
delete temp;
}
}

bool stack_I2P::empty(){
return(stackTop == NULL);
}


void stack_I2P::push(const char& newElement){
nodeType *newNode;
newNode = new nodeType;
newNode->data = newElement;
newNode->link = stackTop;
stackTop = newNode;
}

char stack_I2P::top(){
assert(stackTop != NULL);
return stackTop->data;
}

void stack_I2P::pop(){
nodeType *temp;
if (stackTop != NULL){
temp = stackTop;
stackTop = stackTop->link;
delete temp;
}else
cout<<"NOTHING TO REMOVE FROM EMPTY STACK"<<endl;
}

stack_I2P::~stack_I2P(){
initializeStack();
}

bool IsOperand(char C)
{
if(C >= 'A' && C <= 'Z') return true;
return false;
}

bool IsOperator(char C)
{
if(C == '+' || C == '-' || C == '*' || C == '/')
return true;

return false;
}

int Priority(char op)
{
int pr = -1;
switch(op)
{
case '+':pr = 1;
break;
case '-':pr = 1;
break;
case '*':pr = 2;
break;
case '/':pr = 2;
break;
}
return pr;
}

int HigherPriority(char op1, char op2)
{

if(Priority(op1) == Priority(op2))
return true;
else if(Priority(op1) > Priority(op2))
return true;
else
return false;
}

string stack_I2P::infixToPostfix(string infix)
{
string postfix = "";
for(unsigned i = 0; i< infix.length();i++) {
if(infix[i] == ' ') continue;
else if(IsOperator(infix[i]))
{
while(!empty() && top() != '(' && HigherPriority(top(),infix[i]))
{
postfix+= top();
pop();
}
push(infix[i]);
}
else if(IsOperand(infix[i]))
{
postfix +=infix[i];
}

else if (infix[i] == '(')
{
push(infix[i]);
}

else if(infix[i] == ')')
{
while(!empty() && top() !=  '(') {
postfix += top();
pop();
}
pop();
}
}

while(!empty()) {
postfix += top();
pop();
}

return postfix;
}
