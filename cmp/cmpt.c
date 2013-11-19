#include <stdio.h>
#include <math.h>
#include "fact.h"
#include "stack.h"

void computer(void)
{
  double p1, p2;
  double result;
  push(0);
  char input = getchar();
  while (input != '\n') {
    switch (input) {
    case '+':
      pop();
      p1 = pop();
      p2 = pop();
      result = p1 + p2;
      push(result);
      push(0);
      break;
    case '.':
      push(0);
      break;
    case 'a':
      result = pop();
      result /= 10.;
      push(result);
      push(0);
      break;
    case 'b':
      result = pop();
      result /= 100.;
      push(result);
      push(0);
      break;
    case '&':
      pop();
      p1 = pop();
      result = 1. / p1;
      push(result);
      push(0);
      break;
    case '!':
      pop();
      p1 = pop();
      result = fact(p1, 1);
      push(result);
      push(0);
      break;
    case 'S':
      pop();
      p1 = pop();
      result = sin(p1);
      push(result);
      push(0);
      break;
    case 'C':
      pop();
      p1 = pop();
      result = cos(p1);
      push(result);
      push(0);
      break;
    case 'T':
      pop();
      p1 = pop();
      result = tan(p1);
      push(result);
      push(0);
      break;
    case '_':
      pop();
      p1 = pop();
      result = 0 - result;
      push(result);
      push(0);
      break;
    case 'A':
      pop();
      p1 = pop();
      result = p1 > 0 ? result : (0 - result);
      push(result);
      push(0);
      break;
    case 'B':
      pop();
      p1 = pop();
      p2 = pop();
      result = log(p2)/log(p1);
      push(result);
      push(0);
      break;
    case 'R':
      pop();
      p1 = pop();
      p2 = pop();
      result = pow(p2, 1/p1);
      push(result);
      push(0);
      break;
    case '^':
      pop();
      p1 = pop();
      p2 = pop();
      result = pow(p2, p1);
      push(result);
      push(0);
      break;
    case '*':
      pop();
      p1 = pop();
      p2 = pop();
      result = p1 * p2;
      push(result);
      push(0);
      break;
    case '-':
      pop();
      p1 = pop();
      p2 = pop();
      result = p2 - p1;
      push(result);
      push(0);
      break;
    case '/':
      pop();
      p1 = pop();
      p2 = pop();
      result = p2 / p1;
      push(result);
      push(0);
      break;
    default:
      p1 = pop();
      p2 = (double) (input - '0');
      result = p1 * 10 + p2;
      push(result);
    }
    input = getchar();
  }
  printf("%.2f\n", result);
}
