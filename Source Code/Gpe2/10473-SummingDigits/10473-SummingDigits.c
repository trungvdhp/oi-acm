#include <stdio.h>
int a[90];
void init()
{
	int i, j;
	
	for (i = 0; i < 10; i++)
	{
		for (j = 1; j < 10; j++)
		{
			a[i*9 + j] = j;
		}
	}
}

int solve(int n)
{
	int b = 0;
	
	while (n)
	{
		b += n % 10;
		n /= 10;
	}
	
	return a[b];
}

int main()
{
	int n;
	init();
	
	while (1)
	{
		scanf("%d", &n);
		if (n > 0) 
			printf("%d\n", solve(n));
		else break;
	}
	
	return 0;
}
