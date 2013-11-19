#include <stdio.h>
#include <string.h>
#define MAX 1000
char A[MAX+1];
char B[MAX+1];
char S[MAX+1];
char P[2*MAX];

int length;
int stop, ptop;
void dfs(int, int);

int main(int argc, char *argv[])
{
  while(scanf("%s%s", A, B) != EOF)
    {
      length = strlen(A);
      stop = 0;
      ptop = 0;
      printf("[\n");
      dfs(0, 0);
      printf("]\n");
    }
  return 0;
}

void dfs(int npush, int npop)
{
  if (npush == length && npop == length)
    {
      int i;
      for (i = 0; i < 2*length; i++)
	printf("%c ", P[i]);
      printf("\n");

      return;
    }

  if (npush < length)
    {
      S[stop++] = A[npush];
      P[ptop++] = 'i';
      dfs(npush + 1, npop);
      stop--;
      ptop--;
    }

  if (stop > 0 && S[stop-1] == B[npop])
    {
      char tmp;
      tmp = S[--stop];
      P[ptop++] = 'o';
      dfs(npush, npop+1);
      ptop--;
      S[stop++] = tmp;
    }
}
