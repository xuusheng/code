#include <stdio.h>

void input(void);
void insertN(void);
void insert(int, int);
void output(void);
int A[1000];
int B[1000];
int n, m;
int count=0;
int cur=0;

int main(void)
{
     input();
     insertN();
     output();
     return 0;
}

void input()
{
     scanf("%d%d", &n, &m);
     int i;
     for(i=0; i<n; i++)
	  scanf("%d", A+i);
}

void insertN()
{
     int i;
     B[0] = A[0];
     count = 1;
     cur = 0;
     
     for(i=1; i<n; i++)
	  insert((cur = (cur+m-1)%count + 1), A[i]);
}

void insert(int index, int id)
{
     int i;
     for (i = count; i> index; i--)
	  B[i] = B[i-1];
     B[index] = id;
     count++;
}

void output()
{
     int i;
     for (i = 0; i < count; i++)
	  printf("%d ", B[(cur - i + count)%count]);
     printf("\n");
}
