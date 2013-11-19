#define MAX_LENGTH 10000 //每行的最大长度
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char stack[MAX_LENGTH];
int stacksize = 0;


//底层函数
int err(char *s)
{
     printf("%s err encountered!\n", s);
     return -1;
}

void echo(char *s)
{
     printf("%s\n", s);
}

void push(char c)
{
     stack[stacksize++] = c;
}

char pop(void)
{
     if (stacksize == 0)
	  return 'X';
     return stack[--stacksize];
}


//中层函数
int process_line (char *line)
{
     int n = 0;
     stacksize=0;
     /* C语言缺乏集合的概念 */
     while (line[n] != '\n')
     {
	  char d = line[n];
	  char c;
	  switch (d)
	  {
	  case '(':
	  case '[':
	       push(d);
	       break;
	  case ')':
	       c = pop();
	       if ((c == '[') || (c == 'X'))
		    return -1;
	       break;
	  case ']':
	       c = pop();
	       if ((c == '(') || (c == 'X'))
		    return -1;
	       break;
	  default:
	       return -1;
	  }
	  ++n;
     }
     if (stacksize == 0)
	  return 0;
     return 1;
}


//主函数
int main(void)
{
     int n_line;
     int r;
     char line[MAX_LENGTH+1];
     char *s;
     int i;

     s = fgets(line,5,stdin);
     n_line = atoi(line);

     for (i=0; i < n_line; ++i)
     {
     	  s = fgets(line, MAX_LENGTH+1, stdin);
	  if (s==NULL)
	       err("fgets");	       
	  if (process_line(line) == 0)
	       echo("Yes");
	  else
	       echo("No");
     }

     return 0;
}

/* 而且这个还达不到最好的运行效率，内存占用稍高。  */
/* 为什么传递失败，因为没有利用指针 */
/* 一定要把指针传进去，否则是不行的。 */
/* 如果一行的字符数无法确定怎么办？ */

//ssize_t 表示有符号的size_t 
