#include <fstream>
#include <iostream>
#include <string>
#include "stockDB.h"

using namespace std;

stockDBdlink::stockDBdlink() {
	head = tail = NULL;
	length = 0;
}

bool stockDBdlink::load(string fn, int ver)
{
	ifstream	fin;
	fin.open(fn.c_str());
	if (fin.fail()) return(false);
	while(!fin.eof()){
		stockNode *sp = new stockNode();
		fin >> *sp;
		switch (ver) {
		case 1: insert_inorder(sp); break;
		case 2: insert_inorder2pt(sp); break;
		default: insert_front(sp);
		}
	}
	fin.close();
	return(true);
}

void stockDBdlink::print()
{
	cout << "== print DB\n";
	stockNode *p = head;
	while (p != NULL) {
		cout << *p;
		p = p->next;
	}
}

void stockDBdlink::print_rev()
{
	cout << "== print_rev\n";
	stockNode *p = tail;
	while (p != NULL) {
		cout << *p;
		p = p->prev;
	}
}

void print_rev_recursive_helper(stockNode *p) {
	if (p!= NULL) {
		print_rev_recursive_helper(p->next);
		cout << *p;
	}
}

void stockDBdlink::print_rev_recursive()
{
	cout << "== print_rev_recursive" << endl;
	if (head == NULL) return;
	print_rev_recursive_helper(head);
}

bool stockDBdlink::save(string fn)
{
	if (fn.empty()) fn=dbFileName;
	ofstream	fout(fn.c_str());
	if (fout.fail()) return(false);
	stockNode *p = head;
	while (p != NULL) {
		fout << *p;
		p = p->next;
	}
	fout.close();
	return(true);
}

void stockDBdlink::insert_front(stockNode *p)	// insert front
{
	if (length == 0) {
		p->prev = p->next = NULL;
		head = tail = p;
		length++;
		return;
	}
	p->next = head;
	p->prev = NULL;
	p->next->prev = p;
	head = p;
	length++;
}

void stockDBdlink::insert_inorder(stockNode *p)
{
	if (length == 0) {
		p->prev = p->next = NULL;
		head = tail = p;
		length++;
		return;
	}
	// find a larger node and insert before it
	stockNode * temp = head;
	while (temp != NULL) {
		if (*temp < *p)		temp = temp->next;
		else {
			// insert before temp
			p->next = temp;  //fwd link
			if (head==temp) head = p;  else temp->prev->next = p; // first node case
			p->prev = temp->prev; temp->prev = p;  //bkwd link
			length++;
			return;
		}
	}
	// nobody is larger, insert at end
	p->next = NULL; 	p->prev = tail;
	tail->next = p; tail = p;	length++;
}

void stockDBdlink::insert_inorder2pt(stockNode *p)
{
	if (length == 0) {
		p->prev = p->next = NULL;
		head = tail = p;
		length++;
		return;
	}
	// find a larger node and insert before it
	stockNode *current=head, *behind=NULL;
	while (current != NULL) {
		if (*current < *p)	{
			behind = current;  current = current->next;
		}
		else {
			// insert before current
			p->next = current;  //fwd link
			if (behind==NULL) head = p;  else behind->next = p; // first node case
			p->prev = current->prev; current->prev = p;  //bkwd link
			length++;
			return;
		}
	}
	// nobody is larger, insert at end
	p->next = NULL; 	p->prev = tail;
	tail->next = p; tail = p;	length++;
}

stockNode * stockDBdlink::find_middle() {
	stockNode *slow=head, *fast=head;
	while (fast != NULL) {
//		if (slow == NULL) exit(-1);  // should not happen
		slow = slow->next;
		fast = fast->next;
		if (fast != NULL) fast=fast->next;  // need to check
	}
	return slow;
}

stockNode * stockDBdlink::find_middle2() {
	stockNode *slow=head, *fast=head;
	while (fast != NULL) {
//		if (slow == NULL) exit(-1);  // should not happen
		fast = fast->next;
		if (fast == NULL) return slow;
		slow = slow->next;
		fast=fast->next;
	}
	return slow;
}

stockNode * stockDBdlink::find_middle3() {
	stockNode *slow=head, *fast=head;
	while ((fast != NULL) && (fast->next != NULL)) {
//		if (slow == NULL) exit(-1);  // should not happen
		fast = fast->next->next;
		slow = slow->next;
	}
	return slow;
}

void stockDBdlink::split( stockDBdlink& secondHalf) {  // the original list becomes the firstHalf
	stockNode *mid = find_middle3();
	secondHalf.tail = this->tail;	// set up tail for second half
	if (mid!=NULL) {
		this->tail = mid->prev;  // ground the first half
		tail->next = NULL;
	}
	secondHalf.head = mid;
	// TBD: code to handle length
}

void stockDBtest(){
	stockDBdlink	port1;
	port1.load("frankDB.txt");
	port1.print();
	port1.save("test.txt");
	port1.print_rev();
	port1.print_rev_recursive();
}

void stockDBsplitTest() {
	stockDBdlink port1, port2;
	port1.load("frankDB.txt");
	port1.print();

	stockNode *sp = port1.find_middle();
	cout << "middle is " << *sp;
	sp = port1.find_middle2();
	cout << "middle2 is " << *sp;
	sp = port1.find_middle3();
	cout << "middle3 is " << *sp;

	port1.split(port2);
	port1.print();
	port2.print();
	port2.print_rev_recursive();
}

