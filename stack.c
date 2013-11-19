#include <stdio.h>
#define LEN 8 //解此題之最小棧空間
static int top, tail;
static int stack[LEN];


void push(int number)
{
  if (top == LEN) {
    fprintf(stderr, "錯誤：棧滿！\n");
    return;
  }
  stack[top++] = number;
}

int pop(void)
{
  if (top == 0) {
    fprintf(stderr, "錯誤：棧空！\n");
    return -1;
  }
  return stack[--top];
}

int head(void)
{
  return stack[top-1];
}

int remain(void)
{
  return top;
}

int some(void)
{
  return top - tail;
}

void enq (int number)
{
  if ((top + 1) % LEN == tail) { //頭追尾，棧滿
    fprintf(stderr, "錯誤：棧滿！\n");
    return;
  }
  stack[top] = number;
  top = (top + 1) % LEN;
}

int deq(void)
{
  if (tail == top) { //尾追頭，棧空
    fprintf(stderr, "錯誤：棧空！\n");
    return -1;
  }
  int t = stack[tail];
  tail = (tail + 1) % LEN;
  return t;
}

//严谨的代码在每次在push、pop之前应该检查棧情况，
//但这样有失简洁。如果把检查代码放在函数里面，效果
//亦欠佳。此时最宜使用函数式宏。
