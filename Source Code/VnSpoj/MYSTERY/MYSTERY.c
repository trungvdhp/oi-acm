#include<stdio.h>
#include<math.h>
#define XMAX 84420
#define MAX 20122007
int main()
{
	int a;
	int x[XMAX + 1];
	int i, j, k;
	long long rs;
	scanf("%d", &a);
	k = (int)sqrt(a) + 1;
	x[0] = 1;
	for(i = 1; i <= XMAX; i++)
	{
		x[i] = (x[i - 1] * 3) % MAX;
	}
	rs = 1;
	for(i = 1; i < k; i++)
	{
		if(a % i == 0)
		{
			j = a / i;
			rs = (rs * (x[i%XMAX] - 1))%MAX;
			if(j != i)
			{
				rs = (rs * (x[j%XMAX] - 1))%MAX;
			}
		}	
	}
	printf("%lld", rs);
	return 0;
}
