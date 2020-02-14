#ifndef STUDENTGRADE_H
#define STUDENTGRADE_H
#include <iostream>
using namespace std;

class studentGrade
{
    friend ostream& operator<< (ostream&, const studentGrade&);
    friend istream& operator>> (istream&, studentGrade&);


public:
    string name;
    int grade;
};

#endif
