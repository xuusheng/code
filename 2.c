#include <stdio.h>
#include <string.h>
int main(void)
{
     char a[10];
     memset(a, 0, 10);
     memcpy(a,"abc",2);
     char *b=a;
     printf("%ld\n", sizeof(a));
     printf("%ld\n", sizeof(b));
     printf("%d\n", strlen(a));
     printf("%d\n", strlen(b));
     printf("%s\n", a);
     return 0;
}
