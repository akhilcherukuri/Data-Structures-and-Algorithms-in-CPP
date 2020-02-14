#include "complexType.h"
#include <fstream>
#include <iostream>

using namespace std;

int main()
{
	complexType c[10], sum;
	int i,n;

	cout<<"NUMBER OF COMPLEX NUMBERS: ";
	cin>>n;

	for(i=0;i<n;i++){
		cout<<"COMPLEX NUMBER "<<i+1<<endl;
		cin>>c[i];}

	for(i=0;i<n;i++){
		cout<<"COMPLEX NUMBER "<<i+1<<" : ";
		cout<<c[i];}

	for(i=0;i<n;i++){
		sum=sum+c[i];
	}
	cout<<"\nSUM OF ALL THE COMPLEX NUMBERS: "<<sum;

	ofstream myfile;
	myfile.open("ComplexObj.txt");
	myfile <<"SUM OF ALL THE COMPLEX NUMBERS: "<<sum;
	myfile.close();

}
