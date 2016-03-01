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

bool Book::Is_borrowed()
{
 return is_borrowed;
}

void Book::Read_information()
{
 char file[NAME_MAX_LENGHT];
 itoa(book_id,file);
 FILE *in=fopen(file,"r");
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
 //Time_type now;
 //now.Get_time();
 //is_borrowed=(now-time_when_it_was_last_borrowed>one_month);
 fclose(in);
}

void Book::Update_information()
{
 char file[NAME_MAX_LENGHT];
 itoa(book_id,file);
 FILE *out=fopen(file,"w");
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

void Book::Clear()
{
 memset(title,0,sizeof title);
 memset(author_name,0,sizeof author_name);
 memset(publisher_name,0,sizeof publisher_name);
 number_of_times_it_was_borrowed=book_id=year=0;
 memset(id_last_borrowers,0,sizeof id_last_borrowers);
 is_borrowed=false;
}
