#include <iostream>
#include "stock.h"

using namespace std;

ostream& operator<< (ostream& os, const stock& sg)
{
    os << sg.symbol << " " << sg.cost << " " << sg.shares << endl;
    return os;
}

istream& operator>> (istream& is, stock& sg)
{
    is >> sg.symbol >> sg.cost >> sg.shares;
    return is;
}

stock::stock(string sym, int c, int sh) {
	setstock(sym, c, sh);
}
void stock::setstock(string sym, int c, int sh) {
	symbol=sym; cost=c; shares=sh;
}

bool stock::operator< (const stock& rhs) {
//	if (this->symbol < rhs.symbol) return true; else return false;
	return (symbol < rhs.symbol);
}

void stocktest() {
	stock s1("APPL", 125, 50), s2("FB", 80), s3;
	s3 = s1;
	cout << s1 << s2 << s3;
	s1.setstock("GOOG", 553, 72);
	stock s4(s1);
	cout << (s1 < s2) << (s2<s1) << endl;
	cout << s4;

}

void stockNodetest() {
	stock s;
	stockNodeHasA snhas;
	stockNodeIsA snis;
	stockNodeStruct snst;

	cout << sizeof (stock) << endl;
	cout << sizeof (stockNodeHasA) << endl;
	cout << sizeof (stockNodeIsA) << endl;
	cout << sizeof (stockNodeStruct) << endl;

	s.setstock("abc", 23,45);
	snhas.stk.setstock("has-a",55,66);
	snis.setstock("is-a",100,200);
	snst.stk = s;

	cout << s;
	cout << snhas.stk;
	cout << snis;
	cout << snst.stk;
}




