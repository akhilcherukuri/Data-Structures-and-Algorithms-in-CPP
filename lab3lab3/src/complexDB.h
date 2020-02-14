#ifndef COMPLEXDB_H_
#define COMPLEXDB_H_

#include <iostream>
#include <math.h>
using namespace std;

class complex{
public:
	friend ostream& operator <<(ostream&, const complex&);
	friend istream& operator >>(istream&, complex&);

	bool operator > (const complex& a,const complex& b);
	bool operator == (const complex& a,const complex& b);

	int real,imag;
	complex();
	complex(int,int);
};

class complexDB{
public:
	complexDB(const complexDB&);
	int search(const complex&);
	void remove(const complex&);
	void insert(const complex&);
	void add(const complex&);
	void save();
	void display();


	complex * array;
	int length;
	int max_size;
	complexDB(int);
	~complexDB();
};
#endif /* COMPLEXDB_H_ */
