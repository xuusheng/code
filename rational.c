#include <stdio.h>

struct rational {
  int a;
  int b;
};

typedef struct rational rational_t;

void sgsg (int *a, int *b)
{
  int i = 1, j = 1;
  while (*a != *b)
    if (*a > *b) {
      *a -= *b;
      i += j;
    } else {
      *b -= *a;
      j += i;
    }

  *a = i;
  *b = j;
}

/* rational_t make_rational(int a, int b) */
/* { */
/*   rational_t n; */
/*   euclid(&a, &b); */
/*   euclid(&a, &b); */
/*   n.a = a; */
/*   n.b = b; */

/*   return n; */
/* } */

 
int main(void)
{
  int m = 14284400, n = 1489125000;
  sgsg(&m, &n);
  printf("%d, %d\n", m, n);
  sgsg(&m, &n);
  printf("%d, %d\n", m, n);
  return 0;
}
