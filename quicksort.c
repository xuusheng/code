#include <stdio.h>

void swap(int *a, int l, int u)
{
  int t;
  t = a[l];
  a[l] = a[u];
  a[u] = t;
}

void quicksort(int *a, int l, int u)
{
  if (l >= u)
    return;

  int i, m;

  m = l;
  for (i = l+1; i <= u; ++i)
    if (a[i] < a[l])
      swap(a, ++m, i);
  swap(a, l, m);
  quicksort(a, l, m - 1);
  quicksort(a, m + 1, u);
}
	       
int main(void)
{
  int i;
  int a[6] = {5, 2, 8, 14, 9, 7};

  quicksort(a, 0, 5);

  for (i = 0; i < 6; ++i)
    printf("%d\t", a[i]);

  printf("\n");
  
  return 0;
}

