#include <stdio.h>

int a = 0; //全局初始化区
char *p1; //全局未初始化区
int main(int argc, char *argv[])
{
	int b; //栈
	char s[] = "abc"; //栈
	char *p2; //栈
	char *p3 = "123456"; //字符串常量区
	static int c = 0; //全局初始化区
	char *q1 = (char *)malloc(10);//堆
	void hello(void)
	{
	}
	printf("栈区 b: %d, s: %d, p2: %d, p3: %d, q1: %d\n", &b, s, &p2, &p3, &q1);
	printf("堆区 q1: %d\n", q1);
	printf("串区 p3: %d, %d\n", p3, "abc");
	printf("静区 a: %d, c: %d, p1: %d\n", &a, &c, &p1);
	printf("函区 hello: %d\n", hello);



	return 0;
}
