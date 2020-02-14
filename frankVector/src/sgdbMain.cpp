/*
 * sgdbMain.cpp
 */
#include <iostream>
#include "studentGradeDB.h"

using namespace std;

int main()
{
	studentGradeDB	exam1;
	exam1.load("frankDB.txt");
	exam1.print();
	exam1.save("test.txt");
	cout << "avg = " << exam1.calculateAVG()<<endl;
	exam1.print_rev();
	exam1.save();
	exam1.remove("Frank");
	cout << "avg = " << exam1.calculateAVG()<<endl;
}

