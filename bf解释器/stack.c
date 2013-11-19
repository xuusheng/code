static int top;
static int stack[64];

void push(int number)
{
  stack[top++] = number;
}

int pop(void)
{
  return stack[--top];
}

int head(void)
{
  return stack[top-1];
}

