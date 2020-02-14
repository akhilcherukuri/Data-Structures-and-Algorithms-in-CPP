/*
 * clocktype.h
 *
 * Created on: Sep 10, 2019
 * Author: Akhil Cherukuri
 */
#ifndef CLOCKTYPE_H
#define CLOCKTYPE_H
#include <iostream>
#include <ostream>

class clockType
{
friend std::ostream& operator<<(std::ostream& os, const clockType& out);
friend clockType operator+(const clockType& c1, const clockType& c2);
public:
    clockType();
    clockType(int hours, int minutes, int seconds);
    clockType(int hours, int minutes);
    void setTime(int hours, int minutes, int seconds);
    void getTime(int& hours, int& minutes, int& seconds);
    void printTime();

private:
    int hrs;
    int mins;
    int secs;
};

#endif /* CLOCKTYPE_H */
