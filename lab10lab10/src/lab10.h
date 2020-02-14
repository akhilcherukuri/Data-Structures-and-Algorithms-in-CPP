/*
 * CirQue.h
 *
 *  Created on: Nov 24, 2019
 *      Author: akhilcherukuri
 */

#ifndef LAB10_H_
#define LAB10_H_

#define SIZE 10
#include <iostream>
#include <cstdlib>

using namespace std;

template <class X>
class queue
{
	X *arr;
	int capacity;
	int front;
	int rear;
	int count;

public:
	queue(int size = SIZE);

	void pop_queue();
	void push_queue(X x);
	void empty_queue();
	int size_queue();
	bool isEmpty();
	bool isFull();
};





#endif /* LAB10_H_ */
