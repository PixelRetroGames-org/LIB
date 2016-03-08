#include<cstdio>
#include<algorithm>
#include<cstring>
#include<vector>
#include<cctype>

#include "user.h"
#include "book.h"

#define COMMAND_MAX_LENGHT 100
#define QUOTE '\''

int number_of_books,number_of_users;
std::vector<int> book_ids;
std::vector<int> user_ids;

///BOOKS

int Search_book_title(char *title)
{
 char _title[NAME_MAX_LENGHT];
 Book aux;
 for(int i=0;i<number_of_books;i++)
     {
      aux.Set_id(book_ids[i]);
      aux.Read_information();
      strcpy(_title,aux.Get_title());
      int x=strlen(_title);
      for(int j=0;j<x;j++)
          _title[j]=tolower(_title[j]);
      if(strcmp(_title,title)==0)
         return i;
     }
 return -1;
}

void Load_Books_ids()
{
 FILE *in=fopen("Ids/Book.ids","r");
 fscanf(in,"%d ",&number_of_books);
 book_ids.resize(number_of_books+1);
 for(int i=0;i<number_of_books;i++)
     {
      fscanf(in,"%d ",&book_ids[i]);
     }
 fclose(in);
}

void Update_Books_ids()
{
 FILE *out=fopen("Ids/Book.ids","w");
 fprintf(out,"%d\n",number_of_books);
 for(int i=0;i<number_of_books;i++)
     {
      fprintf(out,"%d\n",book_ids[i]);
     }
 fclose(out);
}

void Print_all_books()
{
 Book aux;
 printf("\n/*****************************************/\n\n");
 for(int i=0;i<number_of_books;i++)
     {
      aux.Set_id(book_ids[i]);
      aux.Read_information();
      aux.Print_information(stdout);
      printf("\n/*****************************************/\n\n");
     }
}

void New_book()
{
 book_ids.resize(number_of_books+1);
 if(number_of_books==0)
    book_ids[number_of_books]=1;
 else
    book_ids[number_of_books]=book_ids[number_of_books-1]+1;
 number_of_books++;
 char s[NAME_MAX_LENGHT];
 Book a;
 printf("Type the new book's title: ");
 gets(s);
 a.Set_title(s);
 printf("Type the new book's author name: ");
 gets(s);
 a.Set_author_name(s);
 printf("Type the new book's publisher name: ");
 gets(s);
 a.Set_publisher_name(s);
 printf("Type the new book's year of publishing: ");
 int y;
 scanf("%d",&y);
 a.Set_year(y);
 a.Set_id(book_ids[number_of_books-1]);
 a.Update_information();
 Update_Books_ids();
}

///USERS

int Search_user_name(char *name)
{
 User aux;
 char _name[NAME_MAX_LENGHT];
 for(int i=0;i<number_of_users;i++)
     {
      aux.Set_id(user_ids[i]);
      aux.Read_information();
      strcpy(_name,aux.Get_username());
      int x=strlen(_name);
      for(int j=0;j<x;j++)
          _name[j]=tolower(_name[j]);
      if(strcmp(_name,name)==0)
         return i;
     }
 return -1;
}

void Load_Users_ids()
{
 FILE *in=fopen("Ids/User.ids","r");
 fscanf(in,"%d ",&number_of_users);
 user_ids.resize(number_of_users+1);
 for(int i=0;i<number_of_users;i++)
     {
      fscanf(in,"%d ",&user_ids[i]);
     }
 fclose(in);
}

void Update_Users_ids()
{
 FILE *out=fopen("Ids/User.ids","w");
 fprintf(out,"%d\n",number_of_users);
 for(int i=0;i<number_of_users;i++)
     {
      fprintf(out,"%d\n",user_ids[i]);
     }
 fclose(out);
}

void Print_all_users()
{
 User aux;
 printf("\n/*****************************************/\n\n");
 for(int i=0;i<number_of_users;i++)
     {
      aux.Set_id(user_ids[i]);
      aux.Read_information();
      aux.Print_information(stdout);
      printf("\n/*****************************************/\n\n");
     }
}

void New_user()
{
 //int X=user_ids[number_of_users-1]+1;
 user_ids.resize(number_of_users+1);
 if(number_of_users==0)
    user_ids[number_of_users]=1;
 else
    user_ids[number_of_users]=user_ids[number_of_users-1]+1;
 number_of_users++;
 char s[NAME_MAX_LENGHT];
 User a;
 printf("Type the new user's name: ");
 gets(s);
 a.Set_name(s);
 printf("Type the new user's surname: ");
 gets(s);
 a.Set_surname(s);
 printf("Type the new user's username: ");
 gets(s);
 a.Set_username(s);
 a.Set_id(user_ids[number_of_users-1]);
 a.Update_information();
 Update_Users_ids();
}

///Borrow

void Borrow(int _user_id,int _book_id)
{
 User user;
 user.Set_id(_user_id);
 user.Read_information();
 Book book;
 book.Set_id(_book_id);
 book.Read_information();
 if(book.Is_borrowed())
    {
     printf("This book is already borrowed!\n\n");
     return;
    }
 if(user.Is_late())
    {
     printf("This user should return the books he borrowed!\n\n");
     return;
    }
 user.Borrow(_book_id);
 user.Update_information();
 book.Update_information();
}

///COMMAND ANALIZER

bool Run_command(char *command)
{
 char main_command[COMMAND_MAX_LENGHT];
 int i1=0;
 int i=0,n=strlen(command);
 while(command[i]!=' ' && i<n)
       {
        main_command[i1++]=tolower(command[i++]);
       }
 main_command[i1]=NULL;
 while(command[i]==' ')
       i++;
 if(strcmp(main_command,"new")==0)
    {
     char sub_command[COMMAND_MAX_LENGHT];
     int i3=0;
     while(command[i]!=' ' && i<n)
           {
            sub_command[i3++]=tolower(command[i++]);
           }
     sub_command[i3]=NULL;
     while(command[i]==' ')
           i++;
     if(strcmp(sub_command,"user")==0)
        New_user();
     else
        if(strcmp(sub_command,"book")==0)
           New_book();
        else
           printf("Unknown subcommand! Try %cnew user%c or %cnew book%c\n",QUOTE,QUOTE,QUOTE,QUOTE);
    }
 else
    if(strcmp(main_command,"print")==0)
       {
        char sub_command[COMMAND_MAX_LENGHT];
        int i3=0;
        while(command[i]!=' ' && i<n)
              {
               sub_command[i3++]=tolower(command[i++]);
              }
        sub_command[i3]=NULL;
        while(command[i]==' ')
              i++;
        if(strcmp(sub_command,"user")==0)
           {
            char parameter[COMMAND_MAX_LENGHT];
            while(i<n)
                  {
                   int i4=0;
                   while(command[i]!=' ' && i<n)
                         {
                          parameter[i4++]=tolower(command[i++]);
                         }
                   parameter[i4]=NULL;
                   if(strcmp(parameter,"--all")==0)
                      {
                       Print_all_users();
                      }
                   else
                      {
                       if(parameter[0]!='-' && isdigit(parameter[0]))
                          {
                           int id;
                           printf("\n/*****************************************/\n\n");
                           atoi(id,parameter);
                           User aux;
                           aux.Set_id(id);
                           aux.Read_information();
                           aux.Print_information(stdout);
                           printf("\n/*****************************************/\n\n");
                          }
                       else
                          if(parameter[0]!='-')
                             {
                              int poz=Search_user_name(parameter);
                              if(poz==-1)
                                 printf("The username is not in the database!\n");
                              else
                                 {
                                  int id=user_ids[poz];
                                  User aux;
                                  aux.Set_id(id);
                                  aux.Read_information();
                                  aux.Print_information(stdout);
                                 }
                             }
                          else
                             printf("Unknown parameter!\n");
                      }
                   while(command[i]==' ')
                         i++;
                  }
           }
        else
           if(strcmp(sub_command,"book")==0)
              {
               char parameter[COMMAND_MAX_LENGHT];
               while(i<n)
                     {
                      int i4=0;
                      while(command[i]!=' ' && i<n)
                            {
                             parameter[i4++]=tolower(command[i++]);
                            }
                      parameter[i4]=NULL;
                      if(strcmp(parameter,"--all")==0)
                         {
                          Print_all_books();
                         }
                      else
                         {
                          if(parameter[0]!='-' && isdigit(parameter[0]))
                             {
                              int id;
                              printf("\n/*****************************************/\n\n");
                              atoi(id,parameter);
                              Book aux;
                              aux.Set_id(id);
                              aux.Read_information();
                              aux.Print_information(stdout);
                              printf("\n/*****************************************/\n\n");
                             }
                          else
                             if(parameter[0]!='-')
                                {
                                 int poz=Search_book_title(parameter);
                                 if(poz==-1)
                                    printf("The book title is not in the database!\n\n");
                                 else
                                    {
                                     int id=book_ids[poz];
                                     Book aux;
                                     aux.Set_id(id);
                                     aux.Read_information();
                                     aux.Print_information(stdout);
                                    }
                                }
                             else
                                printf("Unknown parameter!\n\n");
                         }
                      while(command[i]==' ')
                            i++;
                     }
              }
           else
              printf("Unknown subcommand! Try %cprint user%c or %cprint book%c\n\n",QUOTE,QUOTE,QUOTE,QUOTE);
       }
    else
       if(strcmp(main_command,"delete")==0)
          {
           char sub_command[COMMAND_MAX_LENGHT];
           int i3=0;
           while(command[i]!=' ' && i<n)
                 {
                  sub_command[i3++]=tolower(command[i++]);
                 }
           sub_command[i3]=NULL;
           while(command[i]==' ')
                 i++;
           if(strcmp(sub_command,"user")==0)
              {
               char parameter[COMMAND_MAX_LENGHT];
               while(i<n)
                     {
                      int i4=0;
                      while(command[i]!=' ' && i<n)
                            {
                             parameter[i4++]=tolower(command[i++]);
                            }
                      parameter[i4]=NULL;
                      if(strcmp(parameter,"--all")==0)
                         {
                          User aux;
                          for(int i=0;i<number_of_users;i++)
                              {
                               aux.Set_id(user_ids[i]);
                               aux.Delete();
                               user_ids[i]=0;
                              }
                          number_of_users=0;
                          Update_Users_ids();
                         }
                      else
                         {
                          if(parameter[0]!='-' && isdigit(parameter[0]))
                             {
                              int id;
                              atoi(id,parameter);
                              User aux;
                              int sq;
                              for(sq=0;sq<number_of_users;sq++)
                                  {
                                   user_ids[sq]==id;
                                   break;
                                  }
                              for(;sq<number_of_users-1;sq++)
                                  user_ids[sq]=user_ids[sq+1];
                              number_of_users--;
                              aux.Set_id(id);
                              aux.Delete();
                             }
                          else
                             if(parameter[0]!='-')
                                {
                                 int poz=Search_user_name(parameter);
                                 if(poz==-1)
                                    printf("The username is not in the database!\n\n");
                                 else
                                    {
                                     int id=user_ids[poz];
                                     User aux;
                                     aux.Set_id(id);
                                     aux.Delete();
                                     for(int sq=id;sq<number_of_users-1;sq++)
                                         user_ids[sq]=user_ids[sq+1]-1;
                                     number_of_users--;
                                    }
                                }
                             else
                                printf("Unknown parameter!\n\n");
                         }
                      while(command[i]==' ')
                            i++;
                     }
              }
           else
              if(strcmp(sub_command,"book")==0)
                 {
                  char parameter[COMMAND_MAX_LENGHT];
                  while(i<n)
                        {
                         int i4=0;
                         while(command[i]!=' ' && i<n)
                               {
                                parameter[i4++]=tolower(command[i++]);
                               }
                         parameter[i4]=NULL;
                         if(strcmp(parameter,"--all")==0)
                            {
                             Book aux;
                             for(int i=0;i<number_of_books;i++)
                                 {
                                  aux.Set_id(book_ids[i]);
                                  aux.Delete();
                                  book_ids[i]=0;
                                 }
                             number_of_books=0;
                             Update_Books_ids();
                            }
                         else
                            {
                             if(parameter[0]!='-' && isdigit(parameter[0]))
                                {
                                 int id;
                                 atoi(id,parameter);
                                 Book aux;
                                 aux.Set_id(id);
                                 aux.Delete();
                                 for(int sq=id;sq<number_of_books-1;sq++)
                                     book_ids[sq]=book_ids[sq+1]-1;
                                 number_of_books--;
                                }
                             else
                                if(parameter[0]!='-')
                                   {
                                    int poz=Search_book_title(parameter);
                                    if(poz==-1)
                                       printf("The book title is not in the database!\n\n");
                                    else
                                       {
                                        int id=book_ids[poz];
                                        Book aux;
                                        aux.Set_id(id);
                                        aux.Delete();
                                        for(int sq=id;sq<number_of_books-1;sq++)
                                            user_ids[sq]=user_ids[sq+1]-1;
                                        number_of_books--;
                                       }
                                   }
                                else
                                   printf("Unknown parameter!\n\n");
                            }
                         while(command[i]==' ')
                               i++;
                        }
                 }
              else
                 printf("Unknown subcommand! Try %cdelete user%c or %cdelete book%c\n\n",QUOTE,QUOTE,QUOTE,QUOTE);
          }
       else
          {
           if(strcmp(main_command,"borrow")==0)
              {
               int _book_id,_user_id;
               char sub_command[COMMAND_MAX_LENGHT];
               int i3=0;
               while(command[i]!=' ' && i<n)
                     {
                      sub_command[i3++]=tolower(command[i++]);
                     }
               sub_command[i3]=NULL;
               while(command[i]==' ')
                     i++;
               User aux;
               for(int i=0;i<number_of_users;i++)
                   {
                    aux.Set_id(user_ids[i]);
                    aux.Read_information();
                    if(strcmp(aux.Get_username(),sub_command)==0)
                       {
                        _user_id=user_ids[i];
                        break;
                       }
                   }
               if(_user_id==0)
                  {
                   printf("User is not in the database!\n\n");
                   return false;
                  }
               i3=0;
               while(command[i]!=' ' && i<n)
                     {
                      sub_command[i3++]=tolower(command[i++]);
                     }
               sub_command[i3]=NULL;
               while(command[i]==' ')
                     i++;
               atoi(_book_id,sub_command);
               Borrow(_user_id,_book_id);
              }
           else
              {
               if(strcmp(command,"clear")==0 || strcmp(command,"cls")==0)
                  system("cls");
               else
                  if(strcmp(command,"exit")==0 || strcmp(command,"quit")==0)
                     return true;
              }
          }
 return false;
}

int main()
{
 Load_Books_ids();
 Load_Users_ids();
 char command[COMMAND_MAX_LENGHT];
 bool quit=false;
 while(!quit)
       {
        gets(command);
        quit=Run_command(command);
       }
 return 0;
}
