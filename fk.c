#include <stdio.h>
#include <string.h>

#define MAXWID 512
#define MAXROW 1000

int main (int argc, char **argv)
{
     int i, j, k, lines;

     if (argc != 2)
     {
	  printf("用法：fk [反馈报文文件名]\n");
	  return -1;
     }

     FILE *fp;
     fp = fopen(argv[1], "r");
     if (fp == NULL)
     {
	  printf("打开文件错误\n");
	  return -1;
     }

     char buf[MAXROW][MAXWID];
     memset(buf, 0, sizeof(buf));

     lines = 0;
     while (!feof(fp))
     {
	  fgets(buf[lines], MAXWID, fp);
	  ++lines;
     }

     printf("出错原因代码：");
     for (i = 95; i < 97; ++i)
	  printf("%c", buf[0][i]);
     printf("\n");
     printf("出错记录行数：%d\n", lines - 3);
     
     printf("\n");


     for (k = 2; k < lines - 1; ++k)
     {
	  printf("第%d行：\n", k - 1);
	  printf("出错账户号：");
	  for (i = 84; i < 124; ++i)
	       printf("%c", buf[k][i]);
	  printf("\n");

	  printf("应还款日期：");
	  for (i = 196; i < 204; ++i)
	       printf("%c", buf[k][i]);
	  printf("\n");

	  for (i = 0; i < 5; ++i)
	  {
	       printf("出错字段标识符%d：", i + 1);
	       for (j = 0; j < 4; ++j)	  
		    printf("%c", buf[k][27+7*i+j]);
	       printf("\n错误代码%d：", i + 1);
	       for (j = 5; j < 7; ++j)
		    printf("%c", buf[k][27+7*i+j]);
	       printf("\n");
	  }
	  printf("\n");
     }
     
     if(fclose(fp) != 0)
     {
	  printf("文件关闭错误\n");
	  return -1;
     }
     
     return 0;
}
     
     
