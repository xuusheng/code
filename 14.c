#include <stdio.h>
#include <string.h>
int main(int argc, char *argv[])
{
     int i, j;
     char s[81];
     scanf("%s", s);
     int len = strlen(s);
     for (i = 1; i <= len; i++) 
	  if (len % i == 0)
	  {
	       int ok = 1;
	       for (j = i; j < len; j++)
		    if (s[j] != s [j % i])
		    {
			 ok = 0;
			 break;
		    }
	       if (ok)
	       {
		    printf("%d\n", i);
		    break;
	       }
	  }

     return 0;
}
