#include <stdio.h>

int main(void)
{
	for (i = 0; i < N; ++i)
		if (a[i] < a[i+1])
			swap(i, i+1);
	
