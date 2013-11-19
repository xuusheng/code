#include <stdio.h>
#include <stdlib.h>
void mergeSort(int, int, void(*)(int,int,int));
void merge1(int, int, int);
void merge2(int, int, int);
int A[200000];
int B[200000];
long long inversion = 0;
int main(void)
{
     int i, j;
     int n;

     scanf("%d", &n);
     for (i=0;i<n;i++)
     {
	  scanf("%d%d", &A[i], &B[i]);
     }
     
     mergeSort(0, n, merge1);
     mergeSort(0, n, merge2);
     printf("%lld\n", inversion);

     return 0;
}

void mergeSort(int lo, int hi, void (*merge)(int, int, int))
{
     if (hi - lo < 2)
	  return;
     int mi=lo+(hi-lo)/2;
     mergeSort(lo, mi, merge);
     mergeSort(mi, hi, merge);
     merge(lo, mi, hi);
}

void merge1(int lo, int mi, int hi)
{
     int *pa = malloc((mi-lo) * sizeof(int));
     int *pb = malloc((mi-lo) * sizeof(int));
     int i, j, k;
     for (i=lo; i<mi; i++)
     {
	  pa[i-lo]=A[i];
	  pb[i-lo]=B[i];
     }
     

     for (i=0, j=mi, k=lo; i < mi - lo;k++)
     {
	  if(pa[i] < A[j] || (pa[i] == A[j] && pb[i] <= B[j]) || j > hi - 1)
	  {
	       A[k]=pa[i];
	       B[k]=pb[i];
	       i++;
	  }
	  else
	  {
	       A[k]=A[j];
	       B[k]=B[j];
	       j++;
	  }
     }
     free(pa);
     free(pb);
}

void merge2(int lo, int mi, int hi)
{
     int *pt = malloc((mi-lo) * sizeof(int));
     int i, j, k;
     for (i=lo; i<mi; i++)
	  pt[i-lo]=B[i];

     for (i=0, j=mi, k=lo; i < mi - lo;)
     {
	  if(pt[i] < B[j] || j > hi - 1)
	  {
	       B[k++]=pt[i++];
	       inversion += hi-j;

	  }
	  else
	  {
	       B[k++]=B[j++];
	  }
     }
     free(pt);
}
