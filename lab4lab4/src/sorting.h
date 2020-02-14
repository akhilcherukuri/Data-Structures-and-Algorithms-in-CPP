#ifndef SORTING_H_
#define SORTING_H_

#include <iostream>
#include <math.h>
using namespace std;

class complex{
public:
	friend ostream& operator <<(ostream&, const complex&);
	friend istream& operator >>(istream&, complex&);

	bool operator > (const complex& a){
		double a1,a2;
		a1=sqrt((real*real)+(imag*imag));
		a2=sqrt((a.real*a.real)+(a.imag*a.imag));
		if(a1>a2)
			return true;
		else
			return false;
	}

	bool operator == (const complex& b){
		if((real == b.real) && (imag == b.imag))
			return true;
		else
			return false;
	}


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

	void swap(complex& a, complex& b){
		complex temp;
		temp=a;
		a=b;
		b=temp;
	}

	void bubble(){
		for(int i=0;i<length;i++)
			for(int j=0; j<length-1-i;j++)
				if(array[j]>array[j+1])
					swap(array[j],array[j+1]);
	}

	void insertion(){
		for(int i=1;i<length;i++){
			complex temp = array[i];
			int j=i;
			while(j>0 && array[j-1]>temp)
				{
					array[j] = array[j-1];
					j=j-1;
				}
				array[j] = temp ;
		}
	}

	void selection(){
		for(int i=0;i<length-1;i++){
			int min_idx=i;
			for(int j=i+1; j<length;j++)
				if(array[min_idx]>array[j])
					min_idx=j;

			swap(array[min_idx],array[i]);
		}
	}

	complex * array;
	int length;
	int max_size;
	complexDB(int);
	~complexDB();
};
#endif /* SORTING_H_ */
