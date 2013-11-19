#include <stdio.h>

unsigned int multiply(unsigned int x, unsigned int y)
{
  int i = 0, prod = 0;
  for (; y; y >>= 1)
    prod +=  (x << i++) * (y & 1);
  return prod;
}
    
int main(void)
{
  int a = 5, b = 15;
  printf("%d乘以%d等於%d\n", a, b, multiply(a, b));
  return 0;
}
