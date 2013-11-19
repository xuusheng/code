#include <stdio.h>
#include <string.h>
#include <time.h>
#define MOD 1000000

int main(int argc, char *argv[])
{
     int n;
     int sum = 0;
     int i, j;
     int fact;
     if (argc < 2)
     {
	  printf("Too few args\n");
	  return -1;
     }
     n = atoi(argv[1]);
	      
     for(i = 1; i <= n; ++i)
     {
	  fact = 1;
	  for (j = 1; j <= i; ++j)
	       fact = fact * j % MOD;
	  sum = (sum + fact) % MOD;
     }
     printf("%d\n", sum);
     printf("Time Used = %.2lf\n", (double)clock()/CLOCKS_PER_SEC);
     return 0;
}

