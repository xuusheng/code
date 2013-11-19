#include <stdio.h>
#include <stdint.h>
#include <math.h>

int A[15][15];
int n;
int workload(int, unsigned int);
unsigned int mylog2(const unsigned int);

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
     return min;
}

unsigned int mylog2(const unsigned int x) {
     int var=x;
     unsigned int r=0;
     while (var >>= 1)
	  r++;
     return r;
}
