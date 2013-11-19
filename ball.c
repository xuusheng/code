#include <stdio.h>
#define MAX 512
int left[MAX];
int right[MAX];

void link(int x, int y)
{
     right[x] = y;
     left[y] = x;
}
int main(int argc, char *argv[])
{
     int i, n, m, p;
     char type[6];
     int x, y;
     for (i = 0; i < MAX; ++i)
     {
	  left[i] = i - 1;
	  right[i] = i + 1;
     }

     scanf("%d%d", &n, &m);
     while (m--)
     {
	  scanf("%s%d%d", type, &x, &y);
	  link(left[x], right[x]);

	  if (type[0] == 'A')
	  {
	       link(left[y], x);
	       link(x, y);
	  }
	  else
	  {
	       link(x, right[y]);
	       link(y, x);
	  }
     }

     for (i = 0, p = 0; i < n; ++i, p = right[p])
     {
	  printf("%d ", right[p]);
     }
     printf("\n");

     return 0;
}
