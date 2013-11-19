#include <stdio.h>
void DFS(int a, int b, int temp);
int flag_a, flag_b;
int main(void)
{
    int a, b, t;
    
    while (scanf("%d%d", &a, &b) == 2)
    {
        flag_a = flag_b = 0;
        if (a > b)
        {
            t = a;
            a = b;
            b = t;
        }
            
        DFS(a, b, 2);
        
        if (flag_a && !flag_b)
            printf("%d\n", a);
        else
            printf("%d\n", b);
    }
    return 0;
}

void DFS(int a, int b, int temp)
{
    if (flag_b == 1) return;
    if (a == 1 && b == 1)
         flag_b = 1;
    else if (a == 1)
         flag_a = 1;

    
    while (temp <= 100 && (a >= temp || b >= temp))
    {        
        if (b % temp == 0)
            DFS(a, b / temp, temp+1);
        if (a % temp == 0)
            DFS(a / temp, b, temp+1);
            
        temp++;
    }
}
