/* 2012-08 烟台恒丰 银联标准*/

/*  a 指向来源证件号码，最长20位，左对齐，右补空格。 */
/*  c 指向目标证件号码，与来源证件号码位数相同，但会 */
/* 过滤掉来源号码的字母， 且最多6位有效数字，左补0  */

#include <stdio.h>
#include <string.h>

void TransId(char *c, const char *a)
{
     int i;
     for (i = 0; i < 20; ++i)
	  if (a[i] == ' ')
	       break;
     
     int iaLen = i;
     int j = iaLen - 1;

     memset(c, '0', iaLen);
     
     for (i = iaLen -1; i >= 0; --i)
	  if (a[i] >= '0' && a[i] <= '9')
	  {
	       c[j] = a[i];
	       --j;
	       if (j == iaLen - 7)
		    break;
	  }
}
