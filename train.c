#include <stdio.h>
#define MAX 100000

typedef struct
{
  int data[MAX];
  int head;
} stack_t;

int push(stack_t *, int);
int pop(stack_t *);
int top(stack_t *);
int empty(stack_t *);


stack_t A, B, S;

int n, m;

int main(int argc, char *argv[])
{
  scanf("%d%d", &n, &m);
  int i;
  for (i = n - 1; i >= 0; i--)
    {
      scanf("%d", B.data+i);
      A.data[i] = n - i;
    }

  B.head = n - 1;
  A.head = n - 1;
  S.head = -1;
  

  int success = 1;

  int b;
  while(!empty(&B))
    {
      b = top(&B);

      if (b == top(&S))
	{
	  pop(&S);
	  pop(&B);
	}
      else if (b == top(&A))
	{
	  if (push(&S, pop(&A)))
	    {
	      success = 0;
	      break;
	    }
	  pop(&S);
	  pop(&B);
	}
      else
	{
	  if (push(&S, pop(&A)))
	    {
	      success = 0;
	      break;
	    }
	}
    }

  success?printf("Yes\n"):printf("No\n");
  return 0;
}


int top(stack_t *S)
{
  return S->head == -1 ? S->head : S->data[S->head];
}

int push(stack_t *S, int e)
{
  if (e < 0 || m - 2 < S->head)
    return -1;
  else
    S->data[++S->head] = e;
  return 0;
}

int pop(stack_t *S)
{
  if (S->head == -1)
    return -1;
  return S->data[S->head--];
}

int empty(stack_t *S)
{
  return S->head == -1;
}
