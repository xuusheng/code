#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char *toBin(int inHex, char *bin);

/*  把一个十六进制字符串转换为二进制字符串，命令 ./a.out "1A"将输出
 * "00011010" 我现在的思路是一位一位的转，一位十六进制转化为四位二进制
 * 数*/

int main(int argc, char **argv)
{
     if (argc < 2)
     {
	  printf("usage: %s BMP\n", argv[0]);
	  return -1;
     }

     int nLen = strlen(argv[1]);
     char *oBuf = (char *)malloc(4 * nLen + 1);
     memset(oBuf, 0, 4 * nLen + 1);

     char bin[4];
     int i;
     for (i = 0; i < nLen; ++i)
     {
	  memcpy(oBuf + 4 * i,  toBin((int)argv[1][i], bin), 4);
     }
     
     printf("bin: %s\n", oBuf);
     free(oBuf);
     
     return 0;
}

char *toBin(int inHex, char *bin)
{
     int nDec;

     if (inHex > 0x40)
	  nDec = inHex - 0x37;
     else
	  nDec = inHex - 0x30;
     
     memset(bin, '0', 4);
     int i;
     for (i = 3; i >= 0; --i)
     {
	  bin[i] += (nDec & 1);
	  nDec >>= 1;
     }
     return bin;
}
