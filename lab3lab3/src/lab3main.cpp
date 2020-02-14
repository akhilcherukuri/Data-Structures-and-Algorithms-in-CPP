#include <iostream>
#include <fstream>
#include "complexDB.h"
using namespace std;

int main()
{
	complexDB list(20);
	complex a1(1,2),a2(3,4),a3(7,8),a4(5,6),a;

	int selection;
	char choose;

	list.add(a1);
	list.add(a2);
	list.add(a3);
	list.add(a4);

do{
	cout<<"1 -- > Display"<<endl;
	cout<<"2 -- > Insert"<<endl;
	cout<<"3 -- > Delete"<<endl;
	cout<<"4 -- > Save"<<endl;
	cout<<"SELECT SELECTION:"<<endl;

	cin>>selection;

	switch(selection){
	case 1:
	{
		cout<<"DISPLAY:"<<endl;
		list.display();
		break;
	}
	case 2:
	{
		cout<<"INSERT:Enter Complex Number"<<endl;
		cin>>a;
		list.insert(a);
		break;
	}
	case 3:
	{
		cout<<"DELETE:Enter Complex Number"<<endl;
		cin>>a;
		list.remove(a);
		break;
	}
	case 4:
	{
		list.save();
		cout<<"SAVED:'ComplexObj.txt' Created"<<endl;
		break;
	}
	}

	cout<<"\nContinue (Y/N): ";
	cin>>choose;
}while((choose == 'Y')||(choose == 'y'));
}



