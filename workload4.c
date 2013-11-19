#include <stdio.h>
#include <stdint.h>

int A[15][15];
int n;
int workload(int, unsigned int);
unsigned int mylog2(const unsigned int);
int cache[32768];

int main(int argc, char *argv[])
{
     scanf("%d", &n);
     int i;
     for(i=0; i<n*n; i++)
	  scanf("%d", &A[i/n][i%n]);

     unsigned int list=(1<<n)-1;

     int r=workload(n, list);
     printf("%d\n", r);
     
     return 0;
}

int workload(int m, unsigned int list)
{

     if (cache[list])
	  return cache[list];
     if(m < 2)
	  return A[n-1][mylog2(list)];
     

     int r;
     int i;
     int min=15*10000;
     unsigned int templist=list;
     
     while(i = templist^(templist & (templist - 1)))
     {
	  r = A[n-m][mylog2(i)] + workload(m-1, list ^ i);

	  if (r < min)
	       min = r;
	  templist -= i;
     }
     return cache[list]=min;

}

unsigned int mylog2(const unsigned int x) {
     unsigned int y;
     asm("\tbsr %1, %0\n"
	 : "=r"(y)
	 : "r" (x)
	  );
     return y;
}
