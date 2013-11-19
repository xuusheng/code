#include <stdio.h>
#include <math.h>
#define M 8163
#define N 5000
#define MAX 100

unsigned char ans[M];
double e;

int main(int argc, char *argv[])
{
     int i, j;
     int c, s;
     ans[0] = 1;

     for (i = 1; i <= N; ++i)
     {
	  c = 0;
	  e += log(i) / log(MAX);
	  for (j = (i - 1) / 10; j < e; ++j)
	  {
	       s = ans[j] * i + c;
	       c = s / MAX;
	       ans[j] = s % MAX;
	  }
     }

     for (i = M - 1; i >= 0; --i)
     	  printf("%02d", ans[i]);
     putchar('\n');
 

     return 0;
}
