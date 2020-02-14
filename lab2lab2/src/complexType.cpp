/*
 * complexType.cpp
 *
 * Created on: Sep 16, 2019
 * Author: Akhil CHerukuri
 */
#include "complexType.h"
#include <iostream>

using namespace std;

complexType::complexType(int realnum, int imagnum)
{
	real=realnum;
	imag=imagnum;
}

complexType::complexType()
{
	real=0;
	imag=0;
}

ostream& operator << (ostream& out, const complexType& complex)
{
	out<< "(" << complex.real << ", "<< complex.imag << ")" << endl;
	return out;
}
istream& operator >> (istream& in, complexType& complex)
{
	cout<<"real part: ";
	in>>complex.real;
	cout<<"imaginary part: ";
	in>>complex.imag;
	cout<<endl;
	return in;
}

complexType operator + (const complexType& c1, const complexType& c2)
{
	complexType c3;
	c3.real=c1.real+c2.real;
	c3.imag=c1.imag+c2.imag;
	return c3;
}
