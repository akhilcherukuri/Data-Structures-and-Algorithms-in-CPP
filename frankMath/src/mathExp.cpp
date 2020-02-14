#include <iostream>
#include <string>
#include <stack>
#include "mathExp.h"

using namespace std;


void mathExp::getInfix(string infx) {
	ifx = infx;
	convertToPostfix();
}

void mathExp::showInfix()	{
	cout<<"Infix:"<<endl;
	//cout<< exp.ifx;
}

void mathExp::showPostfix()	{
	cout<<"Postfix:"<<endl;
	//cout<< exp.pfx;

}

mathExp::mathExp(string infx)
{
	ifx = infx;
	convertToPostfix();
}

ostream& operator << (ostream& os, mathExp& exp)
{
	cout << "Infix = " << exp.ifx << endl;
	cout << "Postfix = " << exp.pfx << endl;
	cout << "----------------------------------------------------------------------------- " << endl;
	return os;
}

bool mathExp::precedence(char opr1, char opr2)
{
	int prec1, prec2;

	switch (opr1) {
	case '*':
	case '/': prec1 = 2; break;
	case '+':
	case '-': prec1 = 1; break;
	case '(': prec1 = 0;
	}

	switch (opr2) {
	case '*':
	case '/': prec2 = 2; break;
	case '+':
	case '-': prec2 = 1; break;
	case '(': prec2 = 0;
	}
	return (prec1 >= prec2);
}


void mathExp::convertToPostfix()
{
	stack<char>  oprStack;	// operand stack
	char sOpr;

	while (!oprStack.empty())  oprStack.pop();	// clear opr stack
	pfx = "";		// clear postfix

	int len = ifx.length();
	for (int i = 0; i < len; i++)
		if (isalnum(ifx[i]) || ifx[i]=='.')	// if operand, just go to pfx
			pfx = pfx + ifx[i];
		else
		{
			//pfx += ' ';  // add a space to separate operand
	        switch (ifx[i])		// deal with operators
			{
			case '(':  		// push (
                oprStack.push(ifx[i]); break;

			case ')':   	// pop every opr until (
				do {
                	sOpr = oprStack.top();
                	oprStack.pop();
                	if (sOpr != '(') pfx += sOpr;
                }
				while (sOpr != '(');
	            break;

			case ';': 	// ignore ; or white space
			case '\r':
            case ' ':  break;
			default:
                // stack is empty, just push
                // stack is not empty, pop higher priority opr, then push
                while ((!oprStack.empty()) && precedence(oprStack.top(),ifx[i]))
                {
                    pfx += oprStack.top();
                    oprStack.pop();
                }
                oprStack.push(ifx[i]);
            }//end switch
        }//end else

	while (!oprStack.empty())	// end of the expression, pop the remaining opr
	{
		pfx += oprStack.top();
		oprStack.pop();
	}
}







