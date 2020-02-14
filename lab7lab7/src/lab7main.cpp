#include <iostream>
#include <cassert>
using namespace std;

template <class Type>
struct nodeType
{
Type data;
nodeType<Type> *link;
};

template <class Type> class linkedListStack{
public:
	void initializeStack();
	void push(const Type& newItem);
	bool empty();
	Type top();
	void pop();
	linkedListStack();
	~linkedListStack();
	nodeType<Type> *stackTop;
};


template <class Type>
linkedListStack<Type>::linkedListStack(){
	stackTop = NULL;
}

template <class Type>
void linkedListStack<Type>:: initializeStack(){
	nodeType<Type> *temp;
	while (stackTop != NULL){
		temp = stackTop;
		stackTop = stackTop->link;
		delete temp;
	}
}

template <class Type>
bool linkedListStack<Type>::empty(){
	return(stackTop == NULL);
}

template <class Type>
void linkedListStack<Type>::push(const Type& newElement){
	nodeType<Type> *newNode;
	newNode = new nodeType<Type>;
	newNode->data = newElement;
	newNode->link = stackTop;
	stackTop = newNode;
}

template <class Type>
Type linkedListStack<Type>::top(){
	assert(stackTop != NULL);
	return stackTop->data;
}

template <class Type>
void linkedListStack<Type>::pop(){
	nodeType<Type> *temp;
	if (stackTop != NULL){
		temp = stackTop;
		stackTop = stackTop->link;
		delete temp;
	}else
		cout<<"Cannot remove from an empty stack."<<endl;
}

template <class Type>
linkedListStack<Type>::~linkedListStack(){
	initializeStack();
}


int main(){
	linkedListStack<int> Stack;
	Stack.push(50);
	Stack.push(60);
	Stack.push(20);
	while (!Stack.empty())
	{
	cout << Stack.top() << endl;
	Stack.pop();
	}
	return 0;
}
