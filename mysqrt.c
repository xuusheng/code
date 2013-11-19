/* 这个程序的返回结果为什么是nan？ */

#include <stdio.h>
#define P 0.01

float mysqrt(float, float, float);

int main(void)
{
  printf("%f\n", mysqrt(3, 1, 2));
  return 0;
}

float mysqrt(float number, float l, float u)
{
  float m, e;
  m = (l + u) / 2;
  e = m * m - number;
  if (e < 0)
    e = -e;
  
  if (e < P)
    return m;
  if (m * m < number)
    mysqrt(number, m, u);
  else
    mysqrt(number, l, m);
}
  
