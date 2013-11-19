#include <stdio.h>
#include <string.h>

int main(void)
{
     int m;
     scanf("%d", &m);
     int s;
     char a[10+1];
     memset(a, 0, sizeof(a));
     int an;
     char b[1000+1];
     memset(b, 0, sizeof(b));
     char t[10+1];
     int tn;
     int i;
     while (m--)
     {
	  s = 0;
	  scanf("%s", a);
	  an=atoi(a);
	  scanf("%s", b);
	  for (i = 0; i <= strlen(b) - strlen(a); ++i)
	  {
	       memset(t, 0, sizeof(t));
	       memcpy(t, b+i, strlen(a));
	       tn=atoi(t);
	       if (tn == an)
		    s++;
	  }
	  printf("%d\n", s);
     }
     return 0;
}

/* 后悔当时没有接触acm啊。 */
