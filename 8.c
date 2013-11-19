#include <stdio.h>
#define QUEEN 8

int x[QUEEN]={-1};
int myabs(int n)
{
     return n>0 ? n : -n;
}
int allow(int k)
{
     int i;
     for(i = 0; i < k; ++i)
	  if (x[i] == x[k] || myabs(i-k)==myabs(x[i]-x[k]))
	       return 0;
     return 1;
}

void printout(int *x)
{
     int i, j;
     
     for (i = 0; i < QUEEN; ++i)
     {
	  printf("|");
	  for (j = 0; j < x[i]; ++j)
	       printf(" |");
	  printf("*|");
	  for (j = x[i] + 1; j < QUEEN; ++j)
	       printf(" |");
	  printf("\n");
     }
     for (i = 0; i < QUEEN; ++i)
	  printf("--");
     printf("-\n");
}
void queen(void)
{
     int    k = 0;
     while (k >= 0)
     {
	  x[k]++;
	  while(x[k] < QUEEN && !allow(k))
	       x[k]++;
	  if (x[k] < QUEEN && k == QUEEN - 1)
	       printout(x);

	  else if(x[k] < QUEEN && k < QUEEN)
	       k++;
	  else
	  {
	       x[k]=-1;
	       k--;
	  }
     }
}

int main(int argc, char *argv[])
{
     queen();
     return 0;
}

