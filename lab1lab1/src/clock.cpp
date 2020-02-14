/*
 * clock.cpp
 *
 * Created on: Sep 10, 2019
 * Author: Akhil Cherukuri
 */
#include "clocktype.h"
#include <iostream>
using namespace std;

clockType::clockType()
{
    hrs = 0;
    mins = 0;
    secs = 0;
}

clockType::clockType(int hours, int minutes, int seconds)
{
    setTime(hours, minutes, seconds);
}

clockType::clockType(int hours, int minutes)
{
    hrs = hours;
    mins = minutes;
    secs = 0;
}

void clockType::setTime(int hours, int minutes, int seconds)
{    if (0 <= hours && hours < 24)
       hrs = hours;
    else
        hrs = 0;
    if (0 <= minutes && minutes < 60)
        mins = minutes;
    else
        mins = 0;
    if(0 <= seconds && seconds < 60)
        secs = seconds;
    else
        secs = 0;
 }

ostream& operator<<(ostream& os, const clockType& out)
{
    os << out.hrs << ":" << out.mins << ":" << out.secs <<endl;
    return os;
}

clockType operator+(const clockType& c1, const clockType& c2)
{
    clockType c3;
    c3.hrs = c1.hrs + c2.hrs;
    c3.mins = c1.mins + c2.mins;
    c3.secs = c1.secs + c2.secs;
    return c3;
}




