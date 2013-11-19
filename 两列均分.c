/* 两个数列长度相等，通过交换元素，使两个数列的和相差最小 */
/* 2012-08-19 练习 */

#include <stdio.h>
#define L 8
void swap (int *a, int *b)
{
     int tmp;
     tmp = *a;
     *a = *b;
     *b = tmp;
}     

int sum(int a[])
{
     int i, sum = 0;
     for (i = 0; i < L; ++i)
	  sum += a[i];

     return sum;
}

void sort(int a[])
{
     int i, j;
     for (i = 1; i < L; ++i)
	  for (j = 0; j < i; ++j)
	       if (a[i] < a[j])
		    swap(&a[i], &a[j]);
}

int main (int argc, char *argv[])
{
     int a[L] = {1, 2, 3, 4, 5, 6, 7, 8};
     int b[L] = {1, 2, 4, 8, 16, 32, 64, 128};
     
     sort(a);
     sort(b);

     int i;
     int at, bh;
     int diff;
     int *A;
     int *B;
     
     if (sum(a) < sum(b))
     {
	  A = b;
	  B = a;
     }
     else
     {
	  A = a;
	  B = b;
     }

     for (at = L - 1; at >= 0; --at)
     {
     	  printf("[%4d] ", sum(A));
     	  for (i = 0; i < L; ++i)
     	       printf("%3d  ", A[i]);
     	  printf("\n");
     	  printf("[%4d] ", sum(B));
     	  for (i = 0; i < L; ++i)
     	       printf("%3d  ", B[i]);
     	  printf("\n");
	  printf("\033[32m %2d   %3d \033[0m\n", at, sum(A) - sum(B));
	  printf("\n");

	  if (!(diff = (sum(A) - sum(B)) / 2))
	       break;

	  for (bh = 0; bh < L; ++bh)
	       if ((A[at] - B[bh]) <= diff && A[at] > B[bh])
	       {
	  	    swap(&A[at], &B[bh]);
	  	    break;
	       }

     }

     return 0;
}


