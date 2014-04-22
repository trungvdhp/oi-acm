#include <stdio.h>

int a[100000];
int b[11];
int c[400001];
int n;

int input_a()
{
	n = 0;
	int max = 0;
	
	while (scanf("%d", &a[n]) > 0)
	{
		if (a[n] > max) max = a[n];
		n++;
	}
	
	return max;
}

void init_b(int n)
{
	int i=1,k;
	
	for (k = 5; k <= n; k *= 5) 
	{
		b[i++] = k;
		//printf("%d ", k);
	}
	b[i] = k;
}

void init_c(int n)
{
	int i, j, k;
	int d;
	i = 1;
	init_b(n);
	
	for (k = 5; k <= n; k += 5)
	{
		d = 0;
		j = 1;
		
		while (k >= b[j])
		{
			d += k / b[j++];
		}
		c[i++] = d;
		
		//printf("%d\n", d);
	}
}

void solve()
{
	int i;
	
	for (i = 0; i < n; i++)
	{
		printf ("%d\n", c[a[i]/5]);
	}
}

int main()
{
	int max_a = input_a();
	init_c(max_a);
	solve();
	system("pause");
	return 0;
}
