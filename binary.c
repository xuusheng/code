#include <stdio.h>
#include <string.h>
#define MAX 20
int ball[1<<MAX];
int main(int argc, char *argv[])
{

     int i, j, d, n;

     while(scanf("%d%d", &d, &n) == 2)
     {
	  memset(ball, 0, sizeof(ball));

	  while (n--)
	  {
	       i = 1;
	       for (j = 1; j < d; ++j)
	       {
		    ball[i] = !(ball[i]);
		    i = ball[i] ? 2 * i : 2 * i + 1;
	       }
	  }
	  printf("%d\n", i);
     }
     return 0;
}
