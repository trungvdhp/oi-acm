#include <stdio.h>
#define MAXN 4782
char a[MAXN][1000];
int b[MAXN];
int i, n;

void fib(int n)
{
	int u = n-1;
	int v = n-2;
	char s, d=0;
	b[n] = b[n-1];
	
	for (i = 0; i < b[n]; i++)
	{
		s = a[u][i] + a[v][i] + d;
		a[n][i] = s % 10;
		d = s / 10;
	}
	
	if (d > 0)
	{
		a[n][i] = d;
		b[n] ++;
	}
}

int main()
{
	a[1][0] = 1;
	a[2][0] = 1;
	b[0] = b[1] = b[2] = 1;
	
	n = 3;
	
	while (n < MAXN)
	{
		fib(n++);
	}
	
	while (scanf("%d", &n) > 0)
	{
		for (i = b[n]-1; i >=0; i--)
		{
			printf("%d", a[n][i]);
		}
	
		printf ("\n");
	}

	return 0;
}
