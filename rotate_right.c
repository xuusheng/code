/*原题似乎有错误，一是函数原型不对，二是例如给出的结果不对  */
#include <stdio.h>

unsigned int rotate_right(unsigned int x)
{
  return (x & 1) << 31 | x >> 1;
}

unsigned int rotate(unsigned int x, int n)
{
  int i;
  for (i = 0; i < n; ++i)
    x = rotate_right(x);
  return x;
}

int main(void)
{
  printf("%x\n", rotate(0xdeadbeef, 16));
  /* 给他一个负的参数，当然希望结果是左移，但事实却非如此。难道是二进行
     不够完美，如果换用有符号的三进制数能够解决这个问题吗？还是，C语言
     的语法不够完美？ */
  return 0;
}
