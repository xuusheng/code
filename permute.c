#include <stdio.h>
#include <stdlib.h>
#define N 9
void permute(int *, int *, int);
int main(int argc, char *argv[])
{
     int B[N]={1,2,3,4,5,6,7,8,9};
     int C[N];

     permute(B,C,N);
     return 0;
}

void permute(int *B, int *C, int n)
{
     int i, j;
     if (n < 1)
     {
	  for(i = 0; i < N; i++)
	       printf("%d ", C[i]);
	  printf("\n");
	  return;
     }
     

     for (i = 0; i < N; i++)
     {
	  if (B[i] + 1)
	  {
	       C[N-n] = B[i];
	       B[i] = -1;
	       permute(B, C, n - 1);
	       B[i] = C[N-n];
	  }
     }
     
}
