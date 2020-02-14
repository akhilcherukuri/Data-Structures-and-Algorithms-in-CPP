#include <iostream>
#include <cstdlib>
#include <string>
#include "lab10.h"

using namespace std;

int main()
{
	queue<string> q(10);

	q.push_queue("a");
	q.push_queue("b");
	q.push_queue("c");

	cout << "QUEUE SIZE: " << q.size_queue() << endl;

	q.pop_queue();

	cout << "QUEUE SIZE: " << q.size_queue() << endl;

	cout << "EMPTYING QUEUE NOW"<< endl;
	q.empty_queue();

	cout << "QUEUE SIZE: " << q.size_queue() << endl;

	if (q.isEmpty())
		cout << "QUEUE IS EMPTY \n";
	else
		cout << "QUEUE Is EMPTY \n";

	return 0;
}
