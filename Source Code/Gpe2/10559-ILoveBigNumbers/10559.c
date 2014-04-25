#include <stdio.h>
#define MAXN 1001

char a[2568];
int c[MAXN];
int m = 1, n = 1;
int i;

void f(int n)
{
	int s, d=0;
	
	for (i = 0; i < m; i++)
	{
		s = a[i] * n + d;
		a[i] = s % 10;
		c[n] += a[i];
		d = s / 10;
	}
	
	while (d != 0)
	{
		a[i] = d % 10;
		c[n] += a[i];
		i++;
		d = d / 10;
	}
	
	m = i;
}

int main()
{
	a[0] = 1;
	c[0] = 1;
	
	while (n < MAXN)
	{
		f(n++);
	}
	
	while (scanf("%d", &n) > 0)
	{
		printf ("%d\n", c[n]);
	}

	return 0;
}
