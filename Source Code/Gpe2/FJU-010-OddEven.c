#include <stdio.h>

int main()
{
	int n;
	
	while (scanf("%d", &n) > 0)
	{
		if (n % 2)
		{
			printf ("%d is odd\n", n);
		}
		else
		{
			printf ("%d is even\n", n);
		}
	}
	
	return 0;
}
