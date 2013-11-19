#include <stdio.h>

int top = 0;
char stack[512];

char pop(void)
{
  return stack[--top];
}

void push(char c)
{
  stack[top++] = c;
}

int main(void)
{
  push('a');
  push('b');
  push('c');
  push('d');

  while(top)
    putchar(pop());
  putchar('\n');

  return 0;
}
