/*
 * studentGradeDB.cpp
*/
#include <fstream>
#include <iostream>
#include <string>
#include "studentGradeDB.h"

using namespace std;

bool studentGradeDB::load(string fn)
{
	ifstream	fin;
	fin.open(fn.c_str());
	if (fin.fail()) return(false);
	studentGrade sg;
	while(!fin.eof()){
		fin >> sg;
		sgdb.push_back(sg);
	}
	fin.close();
	return(true);
}

void studentGradeDB::print()
{
	vector <studentGrade>::iterator itsg;
	for (itsg = sgdb.begin(); itsg!= sgdb.end(); ++itsg)
	    cout << *itsg;
}

void studentGradeDB::print_rev()
{
	for (int i=sgdb.size()-1; i>=0; i--)
	    cout << sgdb[i];
}

bool studentGradeDB::save(string fn)
{
	if (fn.empty()) fn=dbFileName;
	ofstream	fout(fn.c_str());
	if (fout.fail()) return(false);

	vector <studentGrade>::iterator itsg;
	for (itsg = sgdb.begin(); itsg!= sgdb.end(); ++itsg)
	    fout << *itsg;
	fout.close();
	return(true);
}

double studentGradeDB::calculateAVG()
{
	double sum=0;
	for (unsigned int i=0; i< sgdb.size(); i++)
	    sum += sgdb[i].grade;
	if (sgdb.size()==0) return 0;
	return (sum/sgdb.size());
}

bool studentGradeDB::remove(string name)
{
	vector <studentGrade>::iterator itsg;
	for (itsg = sgdb.begin(); itsg!= sgdb.end(); ++itsg)
	{
		if (itsg->name != name) continue;
		sgdb.erase(itsg);
		return true;
	}
	return false;
}



