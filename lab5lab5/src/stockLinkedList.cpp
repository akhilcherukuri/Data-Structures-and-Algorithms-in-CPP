#include <iostream>
#include <string>
#include "stockLinkedList.h"
using namespace std;

ostream& operator <<(ostream& os, const stock& stock1){
	os<<stock1.symbol<<"  "<<stock1.price<<"  "<<stock1.shares<<endl;
	return os;
}

istream& operator >>(istream& is, stock& stock1){
	cout<<"Company Name : ";
	is>>stock1.symbol;
	cout<<"Price of each stock : ";
	is>>stock1.price;
	cout<<"Number of stocks : ";
	is>>stock1.shares;
	return is;
}

void SingleLinkedList :: AddNode(const stock& stock1){
	stockNode *NodeToInsert =new stockNode;
	NodeToInsert->s=stock1;
	NodeToInsert->link=NULL;
	if(head==NULL){
		head=NodeToInsert;
		tail=NodeToInsert;
		count++;
	}
	else{
		tail->link=NodeToInsert;
		tail=NodeToInsert;
		count++;
	}
}

void SingleLinkedList::InsertNode(const stock& stock1, int location){
	if((location>count+1)||(location<1)){
		cout<<"Location out of range"<<endl;
		cout<<endl;
	}
	else{
		if(location==count+1){
			AddNode(stock1);
			cout<<"Stock inserted to Linked List"<<endl;
			cout<<endl;
		}
		else{
			if(location==1){
				stockNode *NodeToInsert =new stockNode;
				NodeToInsert->s=stock1;
				NodeToInsert->link=head;
				head=NodeToInsert;
				count++;
				cout<<"Stock inserted to Linked List"<<endl;
				cout<<endl;
			}
			else{
				int i=1;
				stockNode *NodeToInsert =new stockNode;
				NodeToInsert->s=stock1;
				stockNode *current;
				current=head;
				while(i<location-1){
					current=current->link;
					i++;
				}
				NodeToInsert->link=current->link;
				current->link=NodeToInsert;
				count++;
				cout<<"Stock inserted to Linked List"<<endl;
				cout<<endl;
			}
		}
	}
}

void SingleLinkedList::RemoveNode(int location){
	if(head==NULL){
		cout<<"Couldn't operate on Empty list"<<endl;
		cout<<endl;
	}
	else{
		if((location>count)||(location<1)){
			cout<<"Location out of range"<<endl;
			cout<<endl;
		}
		else{
			if(location==1){
				stockNode *ToDelete;
				ToDelete = head;
				head=head->link;
				count--;
				delete ToDelete;
				cout<<"Stock Node removed from Linked List"<<endl;
				cout<<endl;
			}
			else{
				stockNode *ToDelete;
				int i=1;
				stockNode *current;
				current=head;
				while(i<location-1){
					current=current->link;
					i++;
				}
				ToDelete = current->link;
				current->link=ToDelete->link;
				count--;
				delete ToDelete;
				cout<<"Stock Node removed from Linked List"<<endl;
				cout<<endl;
			}
		}
	}
}

void SingleLinkedList::FindMiddleNode(){
	if(head==NULL){
		cout<<"Couldn't operate on Empty list"<<endl;
		cout<<endl;
	}
	else{
		int i=1;
		stockNode *middle;
		middle=head;
		while(i<(count/2)){
			middle=middle->link;
			i++;
		}
		if((count%2)==1){
			cout<<"One Middle Node as list is odd: "<<middle->link->s<<endl;
		}
		else{
			cout<<"Two Middle nodes as list is even : "<<endl;
			cout<<middle->s;
			cout<<middle->link->s;
		}
	}
}

int SingleLinkedList::getCount(){
	return count;
}

SingleLinkedList::SingleLinkedList(){
	count=0;
	head = NULL;
	tail = NULL;
}

void SingleLinkedList::DisplayLinkedList(){
	if(head==NULL){
		cout<<"List is empty"<<endl;
		cout<<endl;
	}
	else{
		cout<<"List of all the stocks:"<<endl;
		stockNode *current;
		current=head;
		while(current!=NULL){
			cout<<current->s;
			current=current->link;
		}
	}
}


stock::stock(string sym,int pr,int sh){
	symbol=sym;
	price=pr;
	shares=sh;
}

stock::stock(){
	symbol=' ';
	price=0;
	shares=0;
}
