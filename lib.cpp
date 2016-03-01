#include "lib.h"

/*const int NAME_MAX_LENGHT=100,NUMBER_OF_LAST_BORROWERS=20;
const int _NAME_MAX_LENGHT=100,NUMBER_OF_BOORROWED_BOOKS_MAX=10;
const char *MM[12]={"Jan","Feb","Mar","Apr","May","Jun","Jul","Aug","Sep","Oct","Nov","Dec"};*/


void itoa(int n, char s[])
{
 int i, sign;
 if ((sign = n) < 0)  /* record sign */
     n = -n;          /* make n positive */
 i = 0;
 do {       /* generate digits in reverse order */
     s[i++] = n % 10 + '0';   /* get next digit */
 } while ((n /= 10) > 0);     /* delete it */
 if (sign < 0)
     s[i++] = '-';
 s[i] = '\0';
 reverse(s);
}

void reverse(char s[])
{
 int i, j;
 char c;

 for (i = 0, j = strlen(s)-1; i<j; i++, j--) {
     c = s[i];
     s[i] = s[j];
     s[j] = c;
 }
}
