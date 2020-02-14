#ifndef STUDENTGRADEDB_H
#define STUDENTGRADEDB_H
#include <iostream>
#include <string>
#include <vector>
#include "studentGrade.h"

using namespace std;
class studentGradeDB
{
public:
    bool load(string);
    void print();
    void print_rev();
    bool save(string="");
    double calculateAVG();	// cal avg
    bool remove(string);	// remove student

private:
    vector <studentGrade> sgdb;
    string	dbFileName;
};

#endif
