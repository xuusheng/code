/* 筛法求质数 */
#include <stdio.h>
long long p[10000];
int n, a[10000] = {1,1};


void sieve(){
  int i,j;
  for(i=2;i<10000;i++){
    if(!a[i]){
      for(j=2*i;j<10000;j+=i) a[j]=1;
      p[n++]=i;
    }
  }
}

int main(int argc, char **argv)
{
     sieve();
     int i;
     for (i = 0; i < 100; i++)
	  printf("%lld ", p[i]);
     return 0;
}
