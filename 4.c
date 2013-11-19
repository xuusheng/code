#include<stdio.h>

int main(void)
{
     int m;
     char a[5];

     scanf("%d%c", &m, &a[4]);
     int i;
     for (i = 0; i < m; ++i)
     {
	  scanf("%c%c%c%c", &a[0], &a[1], &a[2], &a[3]);
	  int i, j, t;
	  for (i = 0; i < 3; ++i)
	  {
	       for (j = i + 1; j < 3; ++j)
	       {
	  	    if (a[i] > a[j])
	  	    {
	  		 t = a[i];
	  		 a[i]=a[j];
	  		 a[j]=t;
	  	    }
		    
	       }
	       
	  }

	  printf("%c %c %c\n", a[0], a[1], a[2]);
     }
     return 0;
}
