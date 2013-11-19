#include <stdio.h>
#define MIN 0.0000001

int main(void)
{
     double x0, y0, x1, y1, xn, yn;
     int m, n;
     scanf("%d", &m);
     while(m--)
     {
	  scanf("%d", &n);
	  scanf("%lf%lf", &x0, &y0);
	  scanf("%lf%lf", &x1, &y1);

	  double s=0;
	  double g=0;
	  double v[2]={x1-x0,y1-y0};
	  double p=(x0+y0+x1+y1)/3;

	  double vn[2];
	  double sn;
	  double gn;

	  while ((n--) - 2)
	  {
	       scanf("%lf%lf", &xn, &yn);
	       vn[0]=xn-x0;
	       vn[1]=yn-y0;
	       sn=(v[0]*vn[1]-vn[0]*v[1])/2.0;
	       gn=p+(xn+yn)/3;
	       v[0]=vn[0];
	       v[1]=vn[1];
	       p=(x0+y0+xn+yn)/3;
	       if ((s+sn>-MIN) && (s+sn)<MIN)
		    g = 0;
	       else
		    g=(g*s+gn*sn)/(s+sn);
	       s+=sn;
	  }
	  if (s < 0)
	       s = -s;
	  printf("%.3lf %.3lf\n", s, g);
     }
     return 0;
}
