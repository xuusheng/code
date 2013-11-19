#include <stdio.h>
#include "maze.h"
#include "stack.h"

int maze[49] = {
  1, 1, 1, 1, 1, 1, 1,
  1, 2, 0, 0, 0, 0, 1,
  1, 0, 0, 0, 0, 0, 1,
  1, 0, 0, 0, 0, 0, 1,
  1, 0, 0, 0, 0, 0, 1,
  1, 0, 0, 0, 0, 0, 1,
  1, 1, 1, 1, 1, 1, 1,
};

int main(void)
{
  path(8);
  
  return 0;
}

void path(int i)
{
  if (i == 40) {
    int t;
    while (i != 8) {
      t = maze[i];
      maze[i] = 2;
      i = t;
    }
    //由2串连起来的路就是迷宫问题的解
    printf("^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n");
    int j, k;
    for (j = 1; j < 6; ++j) {
      for (k = 1; k < 6; ++k)
	printf("%d\t", maze[7*j+k]);
      printf("\n");
    }
    printf("^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^"
	   "\n柳暗花明又一村\n");
    return;
  }
    
  if (maze[i+7] == 0) {
    maze[i+7] = i;
    enq(i+7);
  }
  if (maze[i+1] == 0) {
    maze[i+1] = i;
    enq(i+1);
  }
  if (maze[i-7] == 0) {
    maze[i-7] = i;
    enq(i-7);
  }
  if (maze[i-1] == 0) {
    maze[i-1] = i;
    enq(i-1);
  }

  if (!some()) {
    printf("山重水復疑無路\n");
    return;
  }
  path(deq());
}
