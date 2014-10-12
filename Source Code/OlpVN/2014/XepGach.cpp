#include <cstdio>

int main()
{
	int test;
	int n;
	unsigned long long a[91];
	a[1] = 1;
	a[2] = 2;

	for(int i=3; i<91; i++)
		a[i] = a[i-1] + a[i-2];
		
	scanf("%d", &test);	
	
	while(test--)
	{
		scanf("%d", &n);
		printf("%llu\n", a[n]);
	}
	
	return 0;
}
