#include <iostream>
#include "studentGrade.h"

using namespace std;

ostream& operator<< (ostream& os, const studentGrade& sg)
{
    os << sg.name << "  " << sg.grade << endl;
    return os;
}

istream& operator>> (istream& is, studentGrade& sg)
{
    is >> sg.name >>  sg.grade;
    return is;
}

