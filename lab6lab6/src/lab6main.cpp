#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include "stockDoubleLinkedList.h"
using namespace std;

int main() {
	stockNode sn;
	DoublyLinkedList list;

	int pos, option, disp;
	char choose;

	ifstream file("Stocks.txt");
	string str;
	while (getline(file, str)){
		istringstream ss(str);
		string word;
		int a,b;
		ss >> word;
		ss >> a;
		ss >> b;
		stockNode s(word,a,b);
		list.AddNode(s);
	}

	do{
		cout<<"Enter an option below:"<<endl;
		cout<<"1) Insert"<<endl;
		cout<<"2) Delete"<<endl;
		cout<<"3) Display"<<endl;
		cout<<"4) Get Middle Node "<<endl;
		cin>>option;

		switch(option){
		case 1:
		{
			cout<<"Enter the stock to be inserted"<<endl;
			cin>>sn;
			cout<<"Which node do you want this stock to be ("<<list.getCount()<<" Nodes available) : ";
			cin>>pos;
			list.InsertNode(sn,pos);
			break;
		}
		case 2:
		{
			cout<<"Enter the Node location you want to delete ("<<list.getCount()<<" Nodes available) : ";
			cin>>pos;
			list.RemoveNode(pos);
			break;
		}
		case 3:
		{
			cout<<"1) Display Forward"<<endl;
			cout<<"2) Display Reverse"<<endl;
			cin>>disp;
			if(disp == 1)
				list.DisplayForward();
			else
				if(disp == 2)
					list.DisplayReverse();
				else
					cout<<"Incorrect option entered"<<endl;
			break;
		}
		case 4:
		{
			list.FindMiddleNode();
			break;
		}
		default:
			cout<<"Wrong option entered"<<endl;
		}

		cout<<"Do you want to continue? Press Y or N : ";
		cin>>choose;
	}while((choose == 'Y')||(choose == 'y'));
}
