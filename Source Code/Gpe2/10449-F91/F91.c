#include <stdio.h>
int f[1000001];
	
int main()
{
	int n;

	for (n = 0; n < 101; n++) f[n] = 91;
	for (n = 101; n < 1000001; n++) f[n] = n - 10;
	
	while(1)
	{
		scanf("%d", &n);
		
		if (n == 0) break;
		
		printf ("f91(%d) = %d\n", n, f[n]);
	}
	
	return 0;
}
