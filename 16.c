/* 输入不超过1000的正整数n，输出n!的精确结果 */
/* log(1000!)=2567.6，所以，总共需要2568位 */
/* e的值约为(i*log(i)-i+1)/log(10) + log(i)/4.8 */
#include <stdio.h>
#include <time.h>
#include <math.h>
#define M 16326
#define N 5000

char ans[M];
double e;

int main(int argc, char *argv[])
{
     int i, j;
     int c, s;
     ans[0] = 1;

     for (i = 1; i <= N; ++i)
     {
	  c = 0;
	  e += log10(i);
	  for (j = (i-1)/5l; j < e; ++j)
	  {
	       s = ans[j] * i + c;
	       c = s / 10;
	       ans[j] = s % 10;

	  }
     }
     
     for (i = M - 1; i >= 0; --i)
     	  printf("%d",ans[i]);
     putchar('\n');
     printf("%ld\n", clock());
     /* 对于5000的规模，目前最好的成绩是48，还能再提高效率吗？ */

     /* 看来，计算log需要耗费相当的时间 */
     /* 看来，需要一个低精度运算的模块 */
     return 0;
}
