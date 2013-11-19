#include <stdio.h>

int a[12] = {1, 13, 15, 19, 21, 30, 31, 32, 32, 33, 33, 52};
int bisearch(int n,  int l, int u)
{
  if (l > u)
    return -1;
  int m = (l + u) / 2;
  if (n == a[m]) {
    while (n == a[m])
      m--;
    return m+1;
  }
  else if (n < a[m])
    bisearch(n, l, m-1);
  else
    bisearch(n, m+1, u);
}
int main(void)
{
  printf("%d\n", bisearch(31, 0, 11));
  printf("5\n");
}
