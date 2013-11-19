/* getchar会取得句末的换行符，然后才遇到EOF */
/* 其他键（包括空格、回车）原样输出，`也原样输出*/
/* 已知问题：输入的字符应该为ascii码值，否则会出错*/
#include <stdio.h>
char s[47] = "`1234567890-=QWERTYUIOP[]ASDFGHJKL;'ZXCVBNM,./";
char b[128];
int main()
{
     int i, c;
     for (i = 1; i < 46; ++i)
	  b[s[i]] = s[i - 1];
     while ((c = getchar()) != EOF)
	  putchar(b[c] ? b[c] : c);
     return 0;
}
