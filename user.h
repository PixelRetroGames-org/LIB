#ifndef USER_H
#define USER_H

#include<cstdio>
#include<cstring>

extern const int _NAME_MAX_LENGHT=100,NUMBER_OF_BOORROWED_BOOKS_MAX=10;

class User
{
 private:
 char name[_NAME_MAX_LENGHT],surname[_NAME_MAX_LENGHT],username[_NAME_MAX_LENGHT];
 int user_id;
 int number_of_borrowed_books_in_total,number_of_borrowed_books_now;
 int borrowed_books_ids[NUMBER_OF_BOORROWED_BOOKS_MAX];
 public:
 User();
 ~User();
 void Set_id(int id);
 void Set_name(char *_name);
 void Set_surname(char *_surname);
 void Set_username(char *_username);
 void Read_information();
 void Update_information();
 void Print_information(FILE *where);
};

#endif //USER_H
