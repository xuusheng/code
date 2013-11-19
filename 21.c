#include <stdio.h>
#include <math.h>
#include <time.h>
#define M 74858250		/* 74M内存！ */
#define N 10000		/* 最大值为21691754，计算其阶乘需要一个月时间 */
#define MAX 100			

/* 当N为十万时，约需46秒 */
/* 使用数学软件mathematica 5.0计算100000！的每一位有效数字耗时仅1秒左右。 */
/* 二阶时间效率 */
/* Maximatica的算法为一阶时间效率 */

/* 飘渺世间天的程序 / 某君的死算程序 /Mathematica5.0 / Factorial.exe  */
/* 1000! 1.297s / 0.000s / 0.000s / 0.000s  */
/* 1 0000! 172.438s / 1.359s / 0.015s / 0.012s  */
/* 10 0000! (未测试）/ 426.391s /0.266s / 0.285s  */
/* 100 0000! (未测试）/(未测试）/ 7.657s / 4.595s  */
/* 1000 0000! (未测试）/(未测试）/156.656s / 77.955s */
/* 在这方面maxima也不遑多让，计算十万的阶乘，秒内即得 */
/* 不过百万的阶乘，maxima就不去计算了，我觉得这是应该的 */
/* n*log(n)-n+0.5*log(2*n*pi); */
/* 此公式仍不能密合,仍有可改进之余地 */
/* 如何判定两组数据遵循指数规律？ */
/* 曲线形式为y=a*e^(bx)+c，系数a，b好对付，系统c可以用差分的方法消去，然后对y值取对数，看看其与x值是否成比例关系 */
/* 249998 */
/* 249 */

/* 用FFT计算大数乘法 */

/* n!=(p1^[n/p1])*(p2^[n/p2])*.....*(pm^[n/pm]),公式大致是这个样子，p1,....,pm依次为小于n的素数，用这个公式算很快，乘法的次数会大幅度的减少 */

/* Maxima计算 100,0000! / 1000!瞬间即得，结果的结尾有249个0，验证一下 */
/* 这个是我看错眼了，应该说Maxima并没有计算百万的阶乘，而只是计算了千的阶乘。我看到的结尾0的个数是千阶乘结尾零的个数 */
/* 这可以解释为什么瞬间即得，和结尾有249个0 */
unsigned char ans[M];
double e;

int main(int argc, char *argv[])
{
     int i, j;
     int c, s;
     ans[0] = 1;

     for (i = 2; i <= N; ++i)
     {
	  c = 0;
	  e += log(i) / log(MAX); /* 根据数学知识，求得精确最高位 */
	  for (j = (i - 1) / 10; j < e; ++j) /* 为兼顾效率，粗算最低有效位 */
	  {
	       s = ans[j] * i + c;
	       c = s / MAX;
	       ans[j] = s % MAX;
	  }
     }

     printf("%d", ans[i]);
     for (i = (int)e; i >= 0; --i)
     	       printf("%02d", ans[i]);
     putchar('\n');

     printf("%ld\n", clock());

     return 0;
}
