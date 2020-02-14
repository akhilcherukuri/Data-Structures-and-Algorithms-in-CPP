#ifndef STOCKDOUBLELINKEDLIST_H_
#define STOCKDOUBLELINKEDLIST_H_
#include <iostream>
#include <string>
using namespace std;

class stock{
public:
	string symbol;
	int price;
	int shares;
};

class stockNode : public stock{
public:
	stockNode *next;
	stockNode *prev;
	friend ostream& operator <<(ostream&, const stockNode&);
	friend istream& operator >>(istream&, stockNode&);
	stockNode(string,int,int);
	stockNode();
};

class DoublyLinkedList{
public:
	int count;
	stockNode *head;
	stockNode *tail;
	void RemoveNode(int);
	void InsertNode(stockNode&, int);
	void AddNode(stockNode&);
	void DisplayForward();
	void DisplayReverse();
	void FindMiddleNode();
	int getCount();
	DoublyLinkedList();
};
#endif /* STOCKDOUBLELINKEDLIST_H_ */
