#include <stdio.h>
#include <sys/times.h>

int nsum(int n)
{
	return	n % 10 + n / 10;
}

int main(void)
{
	char n[30];
	FILE *fp;
	int r, i = 0, l, s = 0;
	
	fp = fopen("cardno.txt", "r");
	if (!fp)
	{
		printf("open file error!\n");
		return -1;
	}
	if (!fgets(n, 30, fp))
	{
		printf("read file error!\n");
		return -1;
	}

	if (fclose(fp))
	{	
		printf("close file error!\n");
		return -1;
	}
	
	while (n[i])
		++i;
	i -= 2;
	l = i;	
		
	for (; i >= 0; --i)
	{
		n[i] -= '0';
		if ((l - i +1) % 2)
			n[i] = nsum(2 * n[i]);
		s += n[i];
	}
	
	r = (1000 - s) % 10;
	printf("%d\n", r);
	
	return 0;
}
	
