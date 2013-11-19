#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	extern char **environ;
	int i;
	printf("%s\n", getenv("HOME"));
	return 0;
}
