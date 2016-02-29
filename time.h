#ifndef TIME_H
#define TIME_H

#include<cstdio>
#include<ctime>
#include<windows.h>
#include<cstring>
#include<cstdlib>

extern const char *MM[14];

class Time_type
{
 private:
 int s,m,h,d,mm,y;
 char month[4],day[4];
 char text[20];
 public:
 Time_type();
 ~Time_type();
 void Get_time();
 void Print_time(FILE *where);
 void Read_time(FILE *where);
};

#endif //TIME_H
