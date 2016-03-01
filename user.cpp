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

void User::Read_information()
{
 char file[_NAME_MAX_LENGHT];
 itoa(user_id,file);
 FILE *in=fopen(file,"r");
 gets(name);
 gets(surname);
 gets(username);
 fscanf(in,"%d %d ",&number_of_borrowed_books_in_total,&number_of_borrowed_books_now);
 for(int i=0;i<number_of_borrowed_books_in_total;i++)
     fscanf(in,"%d ",&borrowed_books_ids[i]);
}
void Update_information();
void Print_information(FILE *where);
