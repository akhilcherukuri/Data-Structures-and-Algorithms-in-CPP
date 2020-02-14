#include <iostream>
#include <cstdlib>
#include "lab10.h"

using namespace std;

template <class X>
queue<X>::queue(int size)
{
	arr = new X[size];
	capacity = size;
	front = 0;
	rear = -1;
	count = 0;
}

template <class X>
void queue<X>::pop_queue()
{
	if (isEmpty())
	{
		cout << "UnderFlow \n Program Terminated \n";
		exit(EXIT_FAILURE);
	}

	cout << "POPING " << arr[front] << " FROM QUEUE \n";

	front = (front + 1) % capacity;
	count--;
}


template <class X>
void queue<X>::push_queue(X item)
{
	// check for queue overflow
	if (isFull())
	{
		cout << "OverFlow\nProgram Terminated\n";
		exit(EXIT_FAILURE);
	}

	cout << "PUSHING " << item <<  " TO QUEUE \n";

	rear = (rear + 1) % capacity;
	arr[rear] = item;
	count++;
}


template <class X>
int queue<X>::size_queue()
{
	return count;
}

template <class X>
bool queue<X>::isEmpty()
{
	return (size_queue() == 0);
}

template <class X>
bool queue<X>::isFull()
{
	return (size_queue() == capacity);
}

template <class X>
void queue<X>::empty_queue(){
	front = 0;
	rear = -1;
	count = 0;
}


