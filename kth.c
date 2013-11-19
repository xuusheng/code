#include <stdio.h>
#include <stdlib.h>

void swap(int *a, int i, int j)
{
  int t;
  t = a[i];
  a[i] = a[j];
  a[j] = t;
}

int kth(int *a, int l, int u, int k)
{
  int i, m;
  m = l;
  for (i = l+1; i <= u; ++i)
    if (a[i] < a[l])
      swap(a, ++m, i);
  swap(a, l, m);
  if (m == l+k)
    return a[m];
  else if (m < l+k)
    return kth(a, m+1, u, k-m+l-1);
  else
    return kth(a, l, m-1, k);
}

int main(int argc, char **argv)
{
  int i, b, a[5];
  for (i = 0; i < argc-1; ++i)
    a[i] = atoi(argv[i+1]);

  for (i = 0; i < argc-1; ++i) {
    b = kth(a, 0, argc-2, i);
    printf("%d\t", b);
  }
  printf("\n");
  
  return 0;
}
