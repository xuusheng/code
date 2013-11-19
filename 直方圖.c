#include <stdio.h>
#include <stdlib.h>
#define N 400

int a[N];
int b[10];

void gen_random(int upper_bound)
{
  int i;
  for (i = 0; i < N; ++i)
    a[i] = rand() % upper_bound;
}

void print_random()
{
  int i;
  for (i = 0; i < N; ++i)
    printf("%d ", a[i]);
  printf("\n");
}


void count_random()
{
  int i;
  for (i = 0; i < N; ++i)
    ++b[a[i]];
  for (i = 0; i < 10; ++i)
    printf("%d ", i);
  printf("\n");

  int sum = N;
  
  while(sum) {
    for (i = 0; i < 10; ++i)
      if(b[i] > 0) {
	printf("* ");
	--b[i];
	--sum;
      }
      else
	printf("  ");
    printf("\n");
  }
}

int main(void)
{
  gen_random(10);
  count_random();
  return 0;
}
