#include<cstdio>
#include<algorithm>
#include<cstring>

#include "user.h"
#include "book.h"
#include "lib.h"
#include "time.h"

int main()
{
 Book test;
 test.Set_id(1234);
 test.Read_information();
 test.Print_information(stdout);
}
