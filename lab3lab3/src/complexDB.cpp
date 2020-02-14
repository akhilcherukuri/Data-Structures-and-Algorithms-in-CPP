#include "complexDB.h"
#include <iostream>
#include <fstream>
#include <math.h>
using namespace std;

ostream& operator <<(ostream& os, const complex& complex1){
	os<<"("<<complex1.real<<","<<complex1.imag<<")"<<endl;
	return os;
}

istream& operator >>(istream& is, complex& complex1){
	cout<<"Real part :";
	is>>complex1.real;
	cout<<"Imaginary part :";
	is>>complex1.imag;
	return is;
}

complex :: complex(){
	real=0;
	imag=0;
}

complex :: complex(int a,int b){
	real=a;
	imag=b;
}

complexDB :: complexDB(const complexDB& array1){
	max_size = array1.max_size;
	length = array1.length;

	array = new complex [max_size];


	for(int i =0; i < length; i++)
		array[i] = array1.array[i];
}

int complexDB :: search(const complex& complex1){
	int pos;
	bool found = false;

	for(pos=0;pos<length;pos++)
		if(array[pos] == complex1)
		{
			found = true;
			break;
		}
	if(found)
		return pos;
	else
		return -1;
}

void complexDB :: display(){
	for(int i=0;i<length;i++)
		cout<<array[i];
}

void complexDB:: remove(const complex& complex1){
	int pos;
	if (length == 0)
		cout<< "Can't delete item from empty array"<<endl;
	else
	{
		pos=search(complex1);
		if(pos== -1)
			cout<<"Item not present in the array"<<endl;
		else
			{for(int i=pos;i<length-1;i++)
				array[i]=array[i+1];}
		length--;
	}
}

void complexDB :: insert(const complex& complex1){
	int pos1;
	cout<<"Enter the location(0 to "<<length<<"): ";
	cin>>pos1;
	if((pos1<0) || (pos1>length))
		cout<<"Index out of range"<<endl;
	else
		{for(int i=length; i> pos1; i--)
			array[i]=array[i-1];

		array[pos1]=complex1;
		length++;}
}

void complexDB :: add(const complex& complex1){
	array[length]=complex1;
	length++;
}

void complexDB :: save(){
	ofstream myfile;
	myfile.open("ComplexObj.txt");
	myfile <<"Complex numbers in the Dynamic Array :\n";
	for(int i=0;i<length;i++)
		myfile<<array[i];

	myfile.close();
}

complexDB :: complexDB(int size){
	if (size < 0)
	{
		cout<<"Array size must be positive. Creating an array of size 100"<<endl;
		max_size = 100;
	}
	else
		max_size = size;

	length = 0;
	array = new complex[max_size];

}

complexDB :: ~complexDB()
{
	delete [] array;
}

int real,imag;
bool operator > (const complex& a, const complex& a){
			double a1,a2;
			a1=sqrt((real*real)+(imag*imag));
			a2=sqrt((a.real*a.real)+(a.imag*a.imag));
			if(a1>a2)
				return true;
			else
				return false;
		}

		bool operator == (const complex& b, const complex& b){
			if((real == b.real) && (imag == b.imag))
				return true;
			else
				return false;
		}
