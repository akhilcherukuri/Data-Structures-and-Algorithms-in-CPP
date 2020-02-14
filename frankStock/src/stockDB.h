#ifndef STOCKDB_H
#define STOCKDB_H
#include <iostream>
#include <string>
#include "stock.h"
#define stockNode stockNodeIsA

using namespace std;

class stockDBdlink
{
public:
	stockDBdlink();
    bool load(string, int=0);	// load db with different insert function
    bool save(string);
    void print();
    void print_rev();
    void print_rev_recursive(); // added F16 to test fwd list
    void insert_inorder(stockNode *);
    void insert_inorder2pt(stockNode *);
    void insert_front(stockNode *);
    stockNode *find_middle();
    stockNode *find_middle2();
    stockNode *find_middle3();
    void split( stockDBdlink& secondHalf);  // the original list becomes the firstHalf

private:
    stockNode * head;
    stockNode * tail;
    int		length;
    string	dbFileName;
};

#endif
