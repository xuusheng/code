#include <stdio.h>
int q[51] = {1, 1,};
int main(void)
{

  int i, a, b, n, c;
  scanf("%d%d%d", &a, &b, &n);
  
  for (i = 2; i < 51; ++i)
    q[i] = (a*q[i-1] + b*q[i-2])%7;

  for (i = 49; i; --i)
    if (q[i] == q[50] && q[i-1] == q[49]) {
      c = 50-i;
      break;
    }

  if (n > 51)
    n = n % c;
  while (n < 52-c)
    n += c;

  printf("%d\n", q[n-1]);

  return 0;
}
