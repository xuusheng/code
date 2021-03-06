/* 如果用一个字节表示10进制数,则i最大不能超过UINT_MAX/9,如果用其代表256进制数则i不超过UINT_MAX/255 */
/* 输入不超过1000的正整数n，输出n!的精确结果 */
/* log(1000!)=2567.6，所以，总共需要2568位 */
/* e的值约为(i*log(i)-i+1)/log(10) + log(i)/4.8 */
/* 本程序是一个学习长整数，无符号整数的极好例子 */
/* 现在，程序是4294967296进制，把它转为10000000000 */
#include <stdio.h>
#include <time.h>
#include <math.h>
#define M 1695
#define N 5000
#define MAX 4294967296
#define BITS 32

unsigned int ans[M];
double e;

int main(int argc, char *argv[])
{
     unsigned long long i;
     int j;
     unsigned long long s;
     unsigned long long c;

     
     ans[0] = 1;

     for (i = 1; i <= N; ++i)
     {
	  c = 0;
	  e += log2(i) / BITS;
	  for (j = 0; j < e; ++j)
	  {
	       s = ans[j] * i + c; //这个公式十分关键，相乘从大，相加从小
	       c = s / MAX;
	       ans[j] = s % MAX; //其实直接s就可以，但好像几乎不节省时间，所以还是写全一点吧。
	  }
     }

     for (j = M - 1; j >= 0; --j) //这个也非常奇怪，如果用llu类型的i，则不行，何也。
	  //知道了，因为u型的整数，是求远不会有小于0的时候的。
     	  printf("%08x", ans[j]);
     putchar('\n');
     printf("%ld\n", clock());     

     /* 对于5000的规模，目前最好的成绩是48，还能再提高效率吗？ */
     /* 如果用一个字节存储256进制的一位，则成绩提高到26 */
     /* 如果修正终点，则成绩提高到12 */
     /* 如果在编译时用-O3优化，则时间减少到4 */
     /* 如果用四个字节存储一位，则成绩提高到4 */
     /* 如果用-O3优化，则成绩提高到2 */
     /* 看来，计算log需要耗费相当的时间 */
     /* 看来，需要一个低精度运算的模块 */
     /* 16进制转为10进制 */
     return 0;
}
