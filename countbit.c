/* 练习 */
#include <stdio.h>

int tail_countbit(unsigned int x, int count)
{
  if (x)
    return tail_countbit(x >> 1 , count + (x & 1));
  //位與位或的優先級還不如加減
  return count;
}

int countbit(unsigned int x)
{
  return tail_countbit(x, 0);
}

int main(void)
{
  int i;
  printf("%d\n", countbit(262143));
  return 0;
}
