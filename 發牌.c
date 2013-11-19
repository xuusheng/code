/* 将五十二张牌随机发给甲乙丙丁四个玩家，*/
/* 打印出他们获得的牌，并进行排序 */
/* 徐盛 xuusheng@gmail.com */
/* 2012-04-09 */
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <unistd.h>

/* 交换两个变量的值 */
/* 参数是两个变量的地址 */
/* 两个参数不能指向同一个变量 */
void swap(int *m, int *n)
{
  *m = *m + *n;
  *n = *m - *n;
  *m = *m - *n;
}

/* 对index数组从begin开始，长13的部分进行排序 */
void sort(int begin, int *index)
{
  int i, j;
  for (i = begin+1; i < begin+13; ++i)
    for (j = begin; j < i; ++j)
      if (index[j] > index[i])
	swap(&index[i], &index[j]);
}

int main(int argc, char **argv)
{
  char numbers[13][2+1] =
    {"A", "2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K"};
  char colors[4][2*3+1] = {"黑桃", "红桃", "梅花", "方块"};
  char players[4][1*3+1] = {"甲", "乙", "丙", "丁"};

  int index[52] = {};

  int i = 1, j, randnum, number;

  srand(time(NULL) + getpid());

  while (i < 52 ) {
    randnum = rand() % 52;
    if (index[randnum] == 0)
      index[randnum] = i++;
  }

  for (i = 0; i < 4; ++i)
    sort(i*13, index);
  
  for (i = 0; i < 4; ++i) {
    printf("%s之牌：", players[i]);
    for (j = 0; j < 13; ++j) {
      number = index[j + 13 * i];
      printf("%s%s\t", colors[number%4], numbers[number/4]);
    }
    printf("\n");
  }
  
  return 0;
}
