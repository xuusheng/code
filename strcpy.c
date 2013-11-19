#include <stdio.h>

char *strcpy (char *dest, const char *src)
{
  int i;
  for (i = 0; i <= sizeof(src); ++i) {
    dest[i] = src[i];
  }
  return dest;
}

int main(void)
{
  char buf[10];
  strcpy(buf, "hello.");
  printf("%s\n", buf);

  return 0;
}
