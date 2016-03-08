#include "user.h"

User::User()
{
 user_id=0;
 number_of_borrowed_books_in_total=0;
 number_of_borrowed_books_now=0;
 memset(name,0,sizeof name);
 memset(surname,0,sizeof surname);
 memset(username,0,sizeof username);
}

User::~User()
{
 user_id=0;
 number_of_borrowed_books_in_total=0;
 number_of_borrowed_books_now=0;
 memset(name,0,sizeof name);
 memset(surname,0,sizeof surname);
 memset(username,0,sizeof username);
}

void User::Set_id(int id)
{
 user_id=id;
}

void User::Set_name(char *_name)
{
 strcpy(name,_name);
}

void User::Set_surname(char *_surname)
{
 strcpy(surname,_surname);
}

void User::Set_username(char *_username)
{
 strcpy(username,_username);
}

char* User::Get_username()
{
 return (char*)username;
}

void User::Read_information()
{
 char path[NAME_MAX_LENGHT];
 strcpy(path,"Users/");
 char file[_NAME_MAX_LENGHT];
 itoa(user_id,file);
 strcat(file,".user");
 strcat(path,file);
 FILE *in=fopen(path,"r");
 fgets(name,sizeof name,in);
 name[strlen(name)-1]=NULL;
 fgets(surname,sizeof surname,in);
 surname[strlen(surname)-1]=NULL;
 fgets(username,sizeof username,in);
 username[strlen(username)-1]=NULL;
 fscanf(in,"%d %d ",&number_of_borrowed_books_in_total,&number_of_borrowed_books_now);
 for(int i=0;i<number_of_borrowed_books_in_total;i++)
     fscanf(in,"%d ",&borrowed_books_ids[i]);
 fclose(in);
}

void User::Update_information()
{
 char path[NAME_MAX_LENGHT];
 strcpy(path,"Users/");
 char file[_NAME_MAX_LENGHT];
 itoa(user_id,file);
 strcat(file,".user");
 strcat(path,file);
 FILE *out=fopen(path,"w");
 fputs(name,out);
 fputc('\n',out);
 fputs(surname,out);
 fputc('\n',out);
 fputs(username,out);
 fputc('\n',out);
 fprintf(out,"%d %d\n",number_of_borrowed_books_in_total,number_of_borrowed_books_now);
 for(int i=0;i<number_of_borrowed_books_in_total;i++)
     fprintf(out,"%d\n",borrowed_books_ids[i]);
 fclose(out);
}

void User::Print_information(FILE *where)
{
 fprintf(where,"Name: %s\n",name);
 fprintf(where,"Surname: %s\n",surname);
 fprintf(where,"Username: %s\n",username);
 fprintf(where,"Number of borrowed books in total: %d\nNumber of borrowed books now: %d\n",number_of_borrowed_books_in_total,number_of_borrowed_books_now);
 fprintf(where,"Books borrowed now:\n");
 Book aux;
 Time_type T;
 for(int i=number_of_borrowed_books_in_total-1;i>number_of_borrowed_books_in_total-number_of_borrowed_books_now;i--)
     {
      fprintf(where,"%d ",borrowed_books_ids[i]);
      aux.Set_id(borrowed_books_ids[i]);
      aux.Read_information();
      T=aux.Get_time_when_it_was_last_borrowed();
      fprintf(where,"- %s - ",aux.Get_title());
      T.Print_time(where);
     }
 fprintf(where,"Last borrowed books:\n");
 for(int i=number_of_borrowed_books_in_total-number_of_borrowed_books_now;i>0;i--)
     {
      fprintf(where,"%d ",borrowed_books_ids[i]);
      aux.Set_id(borrowed_books_ids[i]);
      aux.Read_information();
      fprintf(where,"- %s\n",aux.Get_title());
     }
}

void User::Borrow(int book_id)
{
 borrowed_books_ids[number_of_borrowed_books_in_total++]=book_id;
 number_of_borrowed_books_now++;
 Book aux;
 aux.Set_id(book_id);
 aux.Read_information();
 aux.Borrow(user_id);
}

bool User::Is_late()
{
 Book aux;
 Time_type T,T1;
 T1.Get_time();
 for(int i=0;i<number_of_borrowed_books_now;i++)
     {
      aux.Set_id(borrowed_books_ids[i]);
      aux.Read_information();
      if(aux.Is_late())
         return true;
     }
 return false;
}

void User::Delete()
{
 char path[NAME_MAX_LENGHT];
 strcpy(path,"Users/");
 char file[_NAME_MAX_LENGHT];
 itoa(user_id,file);
 strcat(file,".user");
 strcat(path,file);
 remove(path);
}
