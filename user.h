#ifndef USER_H
#define USER_H

#include "lib.h"
#include "book.h"
#include<cstdio>
#include<cstring>

#ifndef _NAME_MAX_LENGHT
#define _NAME_MAX_LENGHT 100
#define NUMBER_OF_BOORROWED_BOOKS_MAX 10
#endif // NAME_MAX_LENGHT

class User
{
 private:
 char name[_NAME_MAX_LENGHT],surname[_NAME_MAX_LENGHT],username[_NAME_MAX_LENGHT];
 int user_id;
 int number_of_borrowed_books_in_total=0,number_of_borrowed_books_now=0;
 int borrowed_books_ids[NUMBER_OF_BOORROWED_BOOKS_MAX];
 public:
 User();
 ~User();
 void Set_id(int id);
 void Set_name(char *_name);
 void Set_surname(char *_surname);
 void Set_username(char *_username);
 char* Get_username();
 void Read_information();
 void Update_information();
 void Borrow(int book_id);
 bool Is_late();
 void Print_information(FILE *where);
 void Delete();
};

#endif //USER_H
