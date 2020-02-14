#include <iostream>
#include <fstream>
#include <string>
#include "mathExp.h"

using namespace std;

int main()
{
	/*mathExp  InfixExp;
	string infix;
	ifstream infile;

	infile.open("Infix2Postfix.txt");
	if(!infile)
	{
		cout << "Cannot open input file. Program terminates!!!" << endl;
		return 1;
	}
	getline(infile,infix);
	while(infile)
	{
		InfixExp.getInfix(infix);
		cout << InfixExp;
		getline(infile,infix);
	}
	infile.close();*/

	mathExp ex2("abc+def-((333*444/3.14)-5.2)");
	cout << ex2;
	return 0;
}

