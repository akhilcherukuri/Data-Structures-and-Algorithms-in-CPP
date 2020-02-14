#ifndef STOCKLINKEDLISTREC_H_
#define STOCKLINKEDLISTREC_H_
#include <iostream>
#include <string>
using namespace std;

class stock{
public:
	string symbol;
	int price;
	int shares;
	friend ostream& operator <<(ostream&, const stock&);
	friend istream& operator >>(istream&, stock&);
	stock(string,int,int);
	stock();
};

class stockNode{
public:
	stock s;
	stockNode *link;
};

class SingleLinkedList{
public:
	int count;
	stockNode *head;
	stockNode *tail;
	void RemoveNode(int);
	void InsertNode(const stock&, int);
	void AddNode(const stock&);
	void DisplayLinkedList(int);
	void DisplayForwardR(stockNode*);
	void DisplayReverseR(stockNode*);
	void FindMiddleNode();
	int getCount();
	SingleLinkedList();
};
#endif /* STOCKLINKEDLISTREC_H_ */
