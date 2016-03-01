#include<cstdio>
#include<algorithm>
#include<cstring>
#include<vector>

#include "user.h"
#include "book.h"

int number_of_books,number_of_users;
std::vector<int> book_ids;
std::vector<int> user_ids;

void Load_Books()
{
 FILE *in=fopen("Ids/Book.ids","r");
 fscanf(in,"%d ",&number_of_books);
 book_ids.resize(number_of_books+1);
 for(int i=1;i<=number_of_books;i++)
     {
      fscanf(in,"%d ",&book_ids[i]);
     }
 fclose(in);
}

void Load_Users()
{
 FILE *in=fopen("Ids/User.ids","r");
 fscanf(in,"%d ",&number_of_users);
 user_ids.resize(number_of_users+1);
 for(int i=1;i<=number_of_users;i++)
     {
      fscanf(in,"%d ",&user_ids[i]);
     }
 fclose(in);
}

int main()
{
 Load_Books();
 Book test;
 for(int i=1;i<=number_of_books;i++)
     {
      test.Set_id(book_ids[i]);
      test.Read_information();
      test.Print_information(stdout);
     }
 Load_Users();
 User test1;
 for(int i=1;i<=number_of_users;i++)
     {
      test1.Set_id(user_ids[i]);
      test1.Read_information();
      test1.Print_information(stdout);
     }
 return 0;
}
