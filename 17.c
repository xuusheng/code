/* 如果用一个字节表示10进制数,则i最大不能超过UINT_MAX/9,如果用其代表256进制数则i不超过UINT_MAX/255 */
/* 输入不超过1000的正整数n，输出n!的精确结果 */
/* log(1000!)=2567.6，所以，总共需要2568位 */
/* e的值约为(i*log(i)-i+1)/log(10) + log(i)/4.8 */

#include <stdio.h>
#include <time.h>
#include <math.h>
#define M 6780
#define N 5000
#define MAX 256

unsigned char ans[M];
double e;

int main(int argc, char *argv[])
{
     int i, j;
     unsigned c, s;
     ans[0] = 1;

     for (i = 1; i <= N; ++i)
     {
	  c = 0;
	  e += log2(i) / 8;
	  for (j = i >> 4; j < e; ++j)
	  {
	       s = ans[j] * i + c;
	       c = s >> 8;
	       ans[j] = s; 	/* Int赋值给char，自动会把前三个字节去掉 */
	  }
     }

     /* for (i = M - 1; i >= 0; --i) */
     /* 	  printf("%02x", ans[i]); */
     /* putchar('\n'); */
     printf("%ld\n", clock());     

     /* 对于5000的规模，目前最好的成绩是48，还能再提高效率吗？ */
     /* 如果用一个字节存储256进制的一位，则成绩提高到26 */
     /* 如果修正终点，则成绩提高到12 */
     /* 如果在编译时用-O3优化，则时间减少到4 */
     /* 看来，计算log需要耗费相当的时间 */
     /* 看来，需要一个低精度运算的模块 */
     /* 16进制转为10进制 */
     return 0;
}
