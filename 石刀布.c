#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void)
{
  char a[3][7]={"石", "刀", "布"};
  char b[3][4]={"平", "输", "赢"};
  int m, c;
  
  srand(time(NULL));
  
  while(1) {
    scanf("%d", &m);
    c = rand() % 3;
    printf("你%s了！ 你出%s，电脑出%s\n", b[(m-c+3) % 3], a[m], a[c]);
  }
  
  return 0;
}
