#include <stdio.h>
int intsqrt(long long n);
int main(int argc, char *argv[])
{
     printf("%d\n", intsqrt(1234));

     return 0;
}

int intsqrt(long long n)
{
     long long p, q;
	q = n / 2;
     do
     {
	  p = q;
	  q = (p + n/p)/2;
     } while (q < p);
     
     return q;
}
