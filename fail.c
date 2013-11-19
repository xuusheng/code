#include <stdio.h>
#include <stdlib.h>

#define N 3

int a[3]= {1, 2, 3};

void pailie(int n)
{
  int i;
  int m=4;
  for (i = 0; i < N; ++i) {
    if(n&(m>>i)) {
      printf("%d ", a[i]);
      pailie(n&(7^(m>>i)));
    }
  }
}


int main(void)
{
  pailie(7);
  return 0;
}
    
