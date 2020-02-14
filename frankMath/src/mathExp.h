#ifndef H_mathExp
#define H_mathExp
#include <string>
using namespace std;

class mathExp
{
	friend ostream& operator << (ostream&, mathExp&);
public:
	void getInfix(string);
	void showInfix();
	void convertToPostfix();
	void showPostfix();
	bool precedence(char opr1, char opr2);
	mathExp(string = "");
		
private:
	string  ifx;
	string  pfx;
};

#endif



