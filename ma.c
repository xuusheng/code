#include <stdio.h>
#define Max 5229
double a[Max];
int m[Max];
int keys;
int main(void)
{
  int i;
  FILE *fp = fopen("ma.txt", "r");
  if (fp == NULL) {
    printf("can't open file.\n");
    return -1;
  }

  for (i = 0; i < Max; ++i) {
    fscanf(fp, "%lf", &a[i]);
    a[i] /= 100;
  }
  fclose(fp);
  
  int n, n0, n1;
  int l;
  double sum;
  int keys = 16;

  for (n = 2; n < keys - 1; ++n)  {
    n0 = 0;
    n1 = n;
    for (l = 1; l < 9; ++l) {
      for (i = n0; i < Max && i < n1; ++i)
	m[i] = l;
      n0 = n1;
      n1 = n1 * (keys - n) + n;
    }

    sum = 0;
    for (i = 0; i < Max; ++i)
      sum += m[i] * a[i];
    printf("%d,%f\n", n, sum);
  }

  return 0;
}
