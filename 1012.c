#include <stdio.h>
char net[4][5];
int max = 0;
int allow(int n, int row, int col){
     if(net[row][col] == 'X'){
	  return 0;
     }

     int i;
     for(i = row; i >= 0; --i) {
	  if(net[i][col]=='@')
	       return 0;
	  else if(net[i][col] == 'X')
	       break;
     }
     for(i = col; i >=0; --i){
	  if(net[row][i] == '@')
	       return 0;
	  else if(net[row][i] == 'X')
	       break;
     }
     return 1;
}

void BackTrack(int n, int k, int num){
     if(k == n * n){
	  if(num > max){
	       max = num;
	  }
	  return;
     }

     int row = k / n, col = k % n;
     if (allow(n, row, col)){
	  net[row][col] = '@';
	  BackTrack(n, k + 1, num + 1);
	  net[row][col] = '.';
     }
     BackTrack(n, k + 1, num);
}

int main(){
     int n, i;
     while(scanf("%d", &n) && n) {
	  max = 0;
	  for (i = 0; i < n; ++i){
	       scanf("%s", net[i]);
	  }
	  BackTrack(n, 0, 0);
	  printf("%d\n", max);
     }
     return 0;
}


void Trackback(int n, int m, int sum)
{
     if (m == n * n)
     {
	  if (sum > max)
	       max = sum;
	  return;
     }
     int row = m / n, col = m % n;
     if (allow(n, row, col))
     {
	  map[row][col]='O';
	  Trackback(n, m + 1, sum + 1);
	  map[row][col]='.';
     }
     Trackback(n, m + 1, sum);
}
