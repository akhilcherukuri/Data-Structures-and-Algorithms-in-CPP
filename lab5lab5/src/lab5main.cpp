#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include "stockLinkedList.h"
using namespace std;

int main() {
	stock st;
	SingleLinkedList list;

	int pos, option;
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
		stock stk(word,a,b);
		list.AddNode(stk);
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
			cin>>st;
			cout<<"Which node do you want this stock to be ("<<list.getCount()<<" Nodes available) : ";
			cin>>pos;
			list.InsertNode(st,pos);
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
			list.DisplayLinkedList();
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
