/*
 * lab1main.cpp
 *
 * Created on: Sep 10, 2019
 * Author: Akhil Cherukuri
 */
#include <iostream>
#include "../../lab1lab1/src/clocktype.h"
using namespace std;

int main()
{
    clockType c1(15, 45, 30), c2(3, 20);
    cout << c1;
    cout << c2;
    cout << c1+c2;
    c2 = c1+c1;
    cout << c2;
}
