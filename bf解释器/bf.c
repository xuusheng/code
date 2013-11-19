/* Interpreter of BrainFuck */
/* 2012-04-08 */
/* xuusheng@qq.com */
#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

int main(int argc, char **argv)
{
     if (argc != 2) {
	  printf("usage: bf FILENAME\n");
	  exit(1);
     }

     FILE *fp = fopen(argv[1], "r");
     if (fp == NULL) {
	  printf("can't open file: %s\n", argv[1]);
	  exit(1);
     }

     char input[4096];
     if (fgets(input, 4096, fp) == NULL) {
	  printf("can't read from file: %s\n", argv[1]);
	  exit(1);
     }
       
     char t[4096] = {};
     int i = 0, j = 0, n;
 
     while ((n = input[i]) != 0) {
	  ++i;
	  if (n == '[')
	       if (t[j])
		    push(i-1);
	       else
		    push(-1);
	  else if (n == ']')
	       if(t[j])
		    i = pop();
	       else
		    pop();
	  else
	       if (head() + 1)
		    switch (n) {
		    case '+':
			 ++t[j];break;
		    case '-':
			 --t[j];break;
		    case '>':
			 ++j;break;
		    case '<':
			 --j;break;
		    case ',':
			 t[j]=getchar();break;
		    case '.':
			 putchar(t[j]);
		    }
     }
     return 0;
}
