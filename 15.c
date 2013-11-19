/* 假设输入的整数位数不超过9 */
#include <math.h>
#include <stdio.h>
int main(int argc, char *argv[])
{
     int a, b;
     int i;
     while (scanf("%d%d", &a, &b) == 2)
     {
	  if (!a && !b)
	       return 0;
	  int c = 0, ans = 0;
	  for (i = 9; i >= 0; --i)
	  {
	       c = (a % 10 + b % 10 + c) > 9 ? 1 : 0;
	       ans += c;
	       a /= 10; b /= 10;
	  }

	  printf("%d\n", ans);
     }

     return 0;
}


