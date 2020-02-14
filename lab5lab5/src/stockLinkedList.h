#ifndef STOCKLINKEDLIST_H_
#define STOCKLINKEDLIST_H_
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
	void DisplayLinkedList();
	void FindMiddleNode();
	int getCount();
	SingleLinkedList();
};
#endif /* STOCKLINKEDLIST_H_ */
