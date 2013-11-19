#include<cstdio>
#include<queue>
using namespace std;


int f(queue<int> q)
{
     if(q.empty)
	  return 1;
     
     int n = q.front();
     q.pop();
     for (int i = 1; i < n; ++i)
	  if (q.front() != n-i)
	       return 0;
     f(q);
}

int main()
{
     int m;
     scanf("%d", &m);
     queue<int> q;
     for(int i = 0; i < m; i++)
     {
	  int t;
	  scanf("%d", &t);
	  q.push(t);
     }

     printf("%s\n", f(q) ? "Yes" : "No");
     return 0;
}
