#include <stdio.h>
#define N 20

int head = N;
int tail = N;
int a[2*N];
int list[N] = {0,0,1,1,2,2,3,3,4,4,5,5,6,6,7,7,8,8,9,-1};
void dfs();
int search(int);
int main(int argc, char *argv[])
{
     a[head++] = 9;
     dfs();
     return 0;
}

void dfs() 
{
     int i;
     if(head - tail >=  N)
     {

	  for (i = tail; i < head; i++)
	       printf("%d ", a[i]);
	  printf("\n");
	  return;
     }
     
     int n, m;

     n = a[head - 1];
     m = a[tail];

     if((i = search(n+1)) != -1)
     {
	  a[head++] = n + 1;
	  list[i] = -1;
	  dfs();
	  list[i] = n + 1;
	  head--;
     }

     if((i = search(m+1)) != -1)
     {
	  a[--tail] = m + 1;
	  list[i] = -1;
	  dfs();
	  list[i] = m + 1;
	  tail++;
     }


     if((i = search(n - 1)) != -1)
     {
	  a[head++] = n - 1;
	  list[i] = -1;
	  dfs();
	  list[i] =  n - 1;
	  head--;
     }

     if((i = search(m - 1)) != -1)
     {
	  a[--tail] = m - 1;
	  list[i] = -1;
	  dfs();
	  list[i] = m - 1;
	  tail++;
     }

}


int search(int n)
{
     if (n < 0)
	  return -1;
     int i;
     for (i = 0; i < N; i++)
	  if (list[i] == n)
	       return i;
     return -1;
}
