#include <ctype.h>
#include <stdio.h>

int main(void)
{
  int ch = getchar();

  while (ch != EOF) {
    putchar(toupper(ch));
    ch = getchar();
  }

  return 0;
}
