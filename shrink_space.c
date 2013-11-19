#include <stdio.h>

int spacep (char c)
{
  return c == ' ' || c == '\t' || c == '\n';
}

char *shrink_space(char *dest, const char *src, size_t n)
{
  int i, j = 0;
  for (i = 0; src[i] != 0 && i - j < n; ++i)
    if (spacep(src[i]))
      if (spacep(src[i-1]))
	++j;
      else
	dest[i-j] = ' ';
    else
      dest[i-j] = src[i];
  
  dest[i-j] = 0;
  return dest;
}

int main(void)
{
  char buf[27];
  shrink_space(buf, "hello, \t \n world     \t\n!", sizeof(buf)-1);
  printf("%s\n", buf);

  return 0;
}
