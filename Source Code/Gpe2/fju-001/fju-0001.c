#include <stdio.h>
#define INT_MAX 2147483647
int main()
{
	int a, b;

	while (scanf("%d%d", &a, &b) > 0)
	{
		printf("%d\n", a + b);
	}
	
	return 0;
}
