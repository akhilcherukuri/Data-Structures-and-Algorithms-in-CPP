/*
 * complextype.h
 *
 * Created on: Sep 16, 2019
 * Author: Akhil CHerukuri
 */

#ifndef COMPLEXTYPE_H_
#define COMPLEXTYPE_H_

#include <iostream>
using namespace std;

class complexType{
	friend ostream& operator << (ostream& out, const complexType& complex);
	friend istream& operator >> (istream& in, complexType& complex);
	friend complexType operator + (const complexType& c1, const complexType& c2);
private:
	int real, imag;

public:
	complexType(int realnum,int imagnum);
	complexType();
		};

#endif /* COMPLEXTYPE_H_ */
