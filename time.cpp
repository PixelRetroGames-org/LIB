#include "time.h"

const char *MM[12]={"Jan","Feb","Mar","Apr","May","Jun","Jul","Aug","Sep","Oct","Nov","Dec"};

Time_type::Time_type()
{
 h=m=y=s=0;
 memset(month,0,sizeof month);
 memset(day,0,sizeof day);
}

Time_type::~Time_type()
{
}

void Time_type::Get_time()
{
 time_t rawtime;
 struct tm * timeinfo;
 time(&rawtime);
 timeinfo=localtime(&rawtime);
 strcpy(text,asctime(timeinfo));
 for(int i=0;i<=2;i++)
     day[i]=text[i];
 for(int i=4;i<=6;i++)
     month[i-4]=text[i];
 for(int i=1;i<=12;i++)
     if(strcmp(month,MM[i])==0)
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
