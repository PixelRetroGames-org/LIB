#ifndef BOOK_H
#define BOOK_H

#include "time.h"
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include "lib.h"

#ifndef NAME_MAX_LENGHT
#define NAME_MAX_LENGHT 100
#define NUMBER_OF_LAST_BORROWERS 20
#endif // NAME_MAX_LENGHT

class Book
{
 private:
 char title[NAME_MAX_LENGHT],author_name[NAME_MAX_LENGHT],publisher_name[NAME_MAX_LENGHT];
 int year;
 int number_of_times_it_was_borrowed;
 int id_last_borrowers[NUMBER_OF_LAST_BORROWERS],book_id;
 Time_type time_when_it_was_last_borrowed;
 bool is_borrowed;
 public:
 Book();
 ~Book();
 void Set_id(int id);
 bool Is_borrowed();
 void Read_information();
 void Update_information();
 void Print_information(FILE *where);
 void Clear();
};

#endif //BOOK_H
