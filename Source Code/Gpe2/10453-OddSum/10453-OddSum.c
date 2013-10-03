#include <stdio.h>

int main()
{
	int i;
	int n, a, b;
	
	scanf("%d", &n);
	n++;
	
	for (i = 1; i < n; i++)
	{
		scanf("%d%d", &a, &b);
		a = (a - (a % 2)) >> 1;
		b = (b + (b % 2)) >> 1;
		printf("Case %d: %d\n", i, b*b - a*a);
	}
	
	return 0;
}
