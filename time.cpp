#include "time.h"

const char *MM[12]={"Jan","Feb","Mar","Apr","May","Jun","Jul","Aug","Sep","Oct","Nov","Dec"};

Time_type::Time_type()
{
 h=m=y=s=0;
 memset(_month,0,sizeof _month);
 memset(_day,0,sizeof _day);
}

Time_type::~Time_type()
{
}

int Time_type::year()
{
 return y;
}

int Time_type::month()
{
 return mm;
}

int Time_type::day()
{
 return d;
}

int Time_type::hour()
{
 return h;
}

int Time_type::minutes()
{
 return m;
}

int Time_type::seconds()
{
 return s;
}

void Time_type::Get_time()
{
 time_t rawtime;
 struct tm * timeinfo;
 time(&rawtime);
 timeinfo=localtime(&rawtime);
 strcpy(text,asctime(timeinfo));
 for(int i=0;i<=2;i++)
     _day[i]=text[i];
 for(int i=4;i<=6;i++)
     _month[i-4]=text[i];
 for(int i=0;i<12;i++)
     if(strcmp(_month,MM[i])==0)
        mm=i;
 char X[5]={0,0,0,0,0};
 int i=8;
 while(text[i]!=' ')
       {
        X[i-8]=text[i];
        i++;
       }
 d=atoi(X);
 X[0]=0;
 i++;
 y=i;
 while(text[i]!=':')
       {
        X[i-y]=text[i];
        i++;
       }
 h=atoi(X);
 X[0]=0;
 i++;
 y=i;
 while(text[i]!=':')
       {
        X[i-y]=text[i];
        i++;
       }
 m=atoi(X);
 X[0]=0;
 i++;
 y=i;
 while(text[i]!=' ')
       {
        X[i-y]=text[i];
        i++;
       }
 s=atoi(X);
 X[0]=0;
 i++;
 y=i;
 while(i<strlen(text))
       {
        X[i-y]=text[i];
        i++;
       }
 y=atoi(X);
}

void Time_type::Print_time(FILE *where)
{
 fprintf(where,"%d.%d.%d %d:%d:%d\n",d,mm,y,h,m,s);
}

void Time_type::Read_time(FILE *where)
{
 fscanf(where,"%d.%d.%d %d:%d:%d\n",&d,&mm,&y,&h,&m,&s);
}
