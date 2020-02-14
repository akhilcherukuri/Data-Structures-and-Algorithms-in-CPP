#include <iostream>
#include <fstream>
#include "sorting.h"

using namespace std;

int main()
{
	complexDB list(20);
	complex a1(1,22),a2(22,1),a3(15,67),a4(55,42),a;

	int selection;
	char choose;

	list.add(a1);
	list.add(a2);
	list.add(a3);
	list.add(a4);

do{
	cout<<"1 -- > Display"<<endl;
	cout<<"2 -- > Save"<<endl;
	cout<<"3 -- > Insert"<<endl;
	cout<<"4 -- > Remove"<<endl;
	cout<<"5 -- > Bubble Sort"<<endl;
	cout<<"6 -- > Insertion Sort"<<endl;
	cout<<"7 -- > Selection Sort"<<endl;
	cout<<"ENTER SELECTION: "<<endl;
	cin>>selection;

	switch(selection){
	case 1:
		{
			list.display();
			break;
		}
	case 2:
		{
			list.save();
			cout<<"SAVED:'ComplexObj.txt' Created"<<endl;
			break;
		}
	case 3:
	{
		cout<<"INSERT:Enter the Complex number"<<endl;
		cin>>a;
		list.insert(a);
		break;
	}
	case 4:
	{
		cout<<"DELETE:Enter the Complex number"<<endl;
		cin>>a;
		list.remove(a);
		break;
	}
	case 5:
	{
			list.bubble();
			cout<<"DONE:Bubble sorting"<<endl;
			break;
	}
	case 6:
	{
			list.insertion();
			cout<<"DONE:Insertion sorting"<<endl;
			break;
	}
	case 7:
	{
			list.selection();
			cout<<"DONE:Selection sorting"<<endl;
			break;
	}

	default:
		cout<<"Invalid option"<<endl;
}

	cout<<"\nContinue (Y/N): ";
	cin>>choose;
}while((choose == 'Y')||(choose == 'y'));
}



