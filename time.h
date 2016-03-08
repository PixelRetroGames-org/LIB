#ifndef TIME_H
#define TIME_H

#include<cstdio>
#include<ctime>
#include<windows.h>
#include<cstring>
#include<cstdlib>
#include "lib.h"

extern const char *MM[12];

class Time_type
{
 private:
 int s,m,h,d,mm,y;
 char _month[4],_day[4];
 char text[20];
 public:
 Time_type();
 ~Time_type();
 int year();
 int month();
 int day();
 int hour();
 int minutes();
 int seconds();
 void Get_time();
 void Print_time(FILE *where);
 void Read_time(FILE *where);
};

#endif //TIME_H
