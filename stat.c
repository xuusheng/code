#include <stdio.h>
int main(void)
{
     char *filename="1.c";
     struct stat statbuf;
     stat(filename, &statbuf);
//     printf("%s", statbuf.st_dev);

     return 0;
}
     
