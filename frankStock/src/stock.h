#ifndef STOCK_H
#define STOCK_H
#include <iostream>
using namespace std;

class stock
{
    friend ostream& operator<< (ostream&, const stock&);
    friend istream& operator>> (istream&, stock&);
public:
    stock(string sym="", int c=0, int s=0);  // constructor with default
    void setstock(string, int, int);
    bool operator< (const stock&);  // less operator
private:
    string symbol;
    int cost;
    int shares;
};

// stock node with Has-A relationship
class stockNodeHasA {
public:
	stock stk;
private:
	stockNodeHasA * prev;
	stockNodeHasA * next;
};

// stock node with inheritance
class stockNodeIsA : public stock {
public:
	stockNodeIsA  * prev;
	stockNodeIsA  * next;
};

// stock node with struct
struct stockNodeStruct {
	stock	stk;
	stockNodeStruct * prev;
	stockNodeStruct * next;
};

#endif
