#include "book.h"
#include "lib.h"
#include<cstdlib>
#include<cstdio>
#include<algorithm>

Book::Book()
{
 memset(title,0,sizeof title);
 memset(author_name,0,sizeof author_name);
 memset(publisher_name,0,sizeof publisher_name);
 number_of_times_it_was_borrowed=book_id=year=0;
 memset(id_last_borrowers,0,sizeof id_last_borrowers);
 is_borrowed=false;
}

Book::~Book()
{

}

void Book::Set_id(int id)
{
 book_id=id;
}

void Book::Set_title(char* _title)
{
 strcpy(title,_title);
}

void Book::Set_author_name(char* _author_name)
{
 strcpy(author_name,_author_name);
}

void Book::Set_publisher_name(char* _publisher_name)
{
 strcpy(publisher_name,_publisher_name);
}

void Book::Set_year(int _year)
{
 year=_year;
}

bool Book::Is_borrowed()
{
 return is_borrowed;
}

bool Book::Is_late()
{
 Time_type T=Get_time_when_it_was_last_borrowed(),T1;
 T1.Get_time();
 if(T1.year()-T.year()>1)
    return true;
 else
    {
     if(T1.year()==T.year()+1)
        if(T.month()!=12 && T1.month()>1)
           return true;
     if(T1.month()-T.month()>1)
        return true;
     if(T1.month()-T.month()==1)
        return false;
     if(T.day()<=28 && T1.day()>T.day())
        return true;
     if(T.day()>28 && T1.day()>28)
        return true;
     return false;
    }
}

void Book::Read_information(FILE *input)
{
 char path[NAME_MAX_LENGHT];
 strcpy(path,"Books/");
 FILE *in=input;
 if(input==NULL)
    {
     char file[NAME_MAX_LENGHT];
     itoa(book_id,file);
     strcat(file,".book");
     strcat(path,file);
     in=fopen(path,"r");
    }
 fgets(title,sizeof title,in);
 title[strlen(title)-1]=NULL;
 fgets(author_name,sizeof author_name,in);
 author_name[strlen(author_name)-1]=NULL;
 fgets(publisher_name,sizeof publisher_name,in);
 publisher_name[strlen(publisher_name)-1]=NULL;
 fscanf(in,"%d %d",&year,&number_of_times_it_was_borrowed);
 for(int i=0;i<std::min(number_of_times_it_was_borrowed,NUMBER_OF_LAST_BORROWERS);i++)
     fscanf(in,"%d ",&id_last_borrowers[i]);
 time_when_it_was_last_borrowed.Read_time(in);
 fclose(in);
}

void Book::Update_information()
{
 char path[NAME_MAX_LENGHT];
 strcpy(path,"Books/");
 char file[NAME_MAX_LENGHT];
 itoa(book_id,file);
 strcat(file,".book");
 strcat(path,file);
 FILE *out=fopen(path,"w");
 fputs(title,out);
 fputc('\n',out);
 fputs(author_name,out);
 fputc('\n',out);
 fputs(publisher_name,out);
 fputc('\n',out);
 fprintf(out,"%d\n%d\n",year,number_of_times_it_was_borrowed);
 for(int i=0;i<std::min(number_of_times_it_was_borrowed,NUMBER_OF_LAST_BORROWERS);i++)
     fprintf(out,"%d\n",id_last_borrowers[i]);
 time_when_it_was_last_borrowed.Print_time(out);
 fclose(out);
}

void Book::Print_information(FILE *where)
{
 fprintf(where,"ID: %d\n",book_id);
 fprintf(where,"Title: ");
 fputs(title,where);
 fputc('\n',where);
 fprintf(where,"Author: ");
 fputs(author_name,where);
 fputc('\n',where);
 fprintf(where,"Publisher: ");
 fputs(publisher_name,where);
 fputc('\n',where);
 fprintf(where,"Year: %d\n#Times borrowed: %d\n",year,number_of_times_it_was_borrowed);
 fprintf(where,"Last 20 borrowers:\n");
 for(int i=0;i<std::min(number_of_times_it_was_borrowed,NUMBER_OF_LAST_BORROWERS);i++)
     fprintf(where,"                  %d\n",id_last_borrowers[i]);
 if(is_borrowed)
    {
     fprintf(where,"It was borrowed on ");
     time_when_it_was_last_borrowed.Print_time(where);
    }
 if(where!=stdout)
    fclose(where);
}

void Book::Borrow(int user_id)
{
 is_borrowed=true;
 time_when_it_was_last_borrowed.Get_time();
 number_of_times_it_was_borrowed++;
 for(int i=std::min(number_of_times_it_was_borrowed,NUMBER_OF_LAST_BORROWERS);i>=1;i--)
     id_last_borrowers[i]=id_last_borrowers[i-1];
 id_last_borrowers[0]=user_id;
}

void Book::Clear()
{
 memset(title,0,sizeof title);
 memset(author_name,0,sizeof author_name);
 memset(publisher_name,0,sizeof publisher_name);
 number_of_times_it_was_borrowed=book_id=year=0;
 memset(id_last_borrowers,0,sizeof id_last_borrowers);
 is_borrowed=false;
}

void Book::Delete()
{
 char path[NAME_MAX_LENGHT];
 strcpy(path,"Books/");
 char file[NAME_MAX_LENGHT];
 itoa(book_id,file);
 strcat(file,".book");
 strcat(path,file);
 remove(path);
}

char* Book::Get_title()
{
 return (char*)title;
}

Time_type Book::Get_time_when_it_was_last_borrowed()
{
 return time_when_it_was_last_borrowed;
}
