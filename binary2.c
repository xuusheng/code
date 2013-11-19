#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[])
{

     int i, d, n;

     while(scanf("%d%d", &d, &n) == 2)
     {

	  i = 1;
	  n--;
	  while(--d)
	  {
	       i = 2 * i + n % 2;
	       n /= 2;
	  }
	  printf("%d\n", i);
     }
     return 0;
}
