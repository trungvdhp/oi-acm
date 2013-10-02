#include <stdio.h>

int main()
{
	unsigned long long a;
	
	while (scanf("%lld", &a) > 0)
	{
		a = a * (a + 1 )/ 2;
		printf("%lld\n", a * a);
	}
	
	return 0;
}
