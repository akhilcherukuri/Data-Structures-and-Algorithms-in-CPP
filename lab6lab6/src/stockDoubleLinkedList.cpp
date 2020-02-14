#include <iostream>
#include <string>
#include "stockDoubleLinkedList.h"
using namespace std;

ostream& operator <<(ostream& os, const stockNode& stock1){
	os<<stock1.symbol<<"  "<<stock1.price<<"  "<<stock1.shares<<endl;
	return os;
}

istream& operator >>(istream& is, stockNode& stock1){
	cout<<"Company Name : ";
	is>>stock1.symbol;
	cout<<"Price of each stock : ";
	is>>stock1.price;
	cout<<"Number of stocks : ";
	is>>stock1.shares;
	return is;
}

void DoublyLinkedList :: AddNode(stockNode& stock1){
	stockNode *NodeToInsert = new stockNode;
	*NodeToInsert=stock1;
	NodeToInsert->next=NULL;
	NodeToInsert->prev=NULL;
	if(head==NULL){
		head=NodeToInsert;
		tail=NodeToInsert;
		count++;
	}
	else{
		tail->next=NodeToInsert;
		NodeToInsert->prev = tail;
		tail=NodeToInsert;
		count++;
	}
}

void DoublyLinkedList::InsertNode(stockNode& stock1, int location){
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
				*NodeToInsert=stock1;
				NodeToInsert->next=head;
				NodeToInsert->prev=NULL;
				head->prev=NodeToInsert;
				head=NodeToInsert;
				count++;
				cout<<"Stock inserted to Linked List"<<endl;
				cout<<endl;
			}
			else{
				int i=1;
				stockNode *NodeToInsert =new stockNode;
				*NodeToInsert=stock1;
				stockNode *current;
				current=head;
				while(i<location-1){
					current=current->next;
					i++;
				}
				NodeToInsert->next=current->next;
				current->next=NodeToInsert;
				NodeToInsert->prev = current;
				count++;
				cout<<"Stock inserted to Linked List"<<endl;
				cout<<endl;
			}
		}
	}
}

void DoublyLinkedList::RemoveNode(int location){
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
				head=head->next;
				count--;
				delete ToDelete;
				cout<<"Stock Node removed from Linked List"<<endl;
				cout<<endl;
			}
			else{
				if(location==count){
					stockNode *ToDelete;
					ToDelete = tail;
					tail=tail->prev;
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
						current=current->next;
						i++;
					}
					ToDelete = current->next;
					current->next=ToDelete->next;
					ToDelete->next->prev=ToDelete->prev;
					count--;
					delete ToDelete;
					cout<<"Stock Node removed from Linked List"<<endl;
					cout<<endl;
				}
			}
		}
	}
}

void DoublyLinkedList::FindMiddleNode(){
	if(head==NULL){
		cout<<"Couldn't operate on Empty list"<<endl;
		cout<<endl;
	}
	else{
		int i=1;
		stockNode *middle;
		middle=head;
		while(i<(count/2)){
			middle=middle->next;
			i++;
		}
		if((count%2)==1){
			cout<<"One Middle Node as list is odd: "<<middle->next<<endl;
		}
		else{
			cout<<"Two Middle nodes as list is even : "<<endl;
			cout<<*middle;
			cout<<*(middle->next);
		}
	}
}

int DoublyLinkedList::getCount(){
	return count;
}

DoublyLinkedList::DoublyLinkedList(){
	count=0;
	head = NULL;
	tail = NULL;
}

void DoublyLinkedList::DisplayForward(){
	if(head==NULL){
		cout<<"List is empty"<<endl;
		cout<<endl;
	}
	else{
		cout<<"List of all the stocks:"<<endl;
		stockNode *current;
		current=head;
		while(current!=NULL){
			cout<<*current;
			current=current->next;
		}
	}
}

void DoublyLinkedList::DisplayReverse(){
	if(head==NULL){
		cout<<"List is empty"<<endl;
		cout<<endl;
	}
	else{
		cout<<"List of all the stocks:"<<endl;
		stockNode *current;
		current=tail;
		while(current!=NULL){
			cout<<*current;
			current=current->prev;
		}
	}
}


stockNode::stockNode(string sym,int pr,int sh){
	symbol=sym;
	price=pr;
	shares=sh;
	prev=NULL;
	next=NULL;
}

stockNode::stockNode(){
	symbol=' ';
	price=0;
	shares=0;
	prev=NULL;
	next=NULL;
}
