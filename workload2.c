#include <stdio.h>
#include <stdint.h>

int A[15][15];
int n;
int workload(int, uint32_t);
static inline  uint32_t mylog2(const uint32_t);

int main(int argc, char *argv[])
{
     scanf("%d", &n);
     int i;
     for(i=0; i<n*n; i++)
	  scanf("%d", &A[i/n][i%n]);

     uint32_t list=(1<<n)-1;

     int r=workload(n, list);
     printf("%d\n", r);
     
     return 0;
}

int workload(int m, uint32_t list)
{
     if(m < 1)
	  return A[n-1][mylog2(list)];

     int r;
     int i;
     int min=15*10000;
     uint32_t templist=list;
     
     while(i = templist^(templist & (templist - 1)))
     {
	  r = A[n-m][mylog2(i)] + workload(m-1, list ^ i);

	  if (r < min)
	       min = r;
	  templist -= i;
     }
     return min;
}

static inline uint32_t mylog2(const uint32_t x) {
     uint32_t y;
     asm("\tbsr %1, %0\n"
	 : "=r"(y)
	 : "r" (x)
	  );
     return y;
}
