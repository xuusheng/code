#include <gmp.h>
#include <string.h>
#include <stdio.h>

main() {
  mpz_t n;
  int i, j, total=0;
  char s[1000];

  mpz_init(n);
  for(i=1;i<10;i++)
    for(j=1;j<30;j++) {
      mpz_ui_pow_ui(n, i, j);
      gmp_sprintf(s, "%Zd", n);
      if(strlen(s) == j)
        total++;
    }
  printf("%d\n", total);
}
