#include<stdio.h>
#define MaxN 100001
int b[MaxN];
int c[MaxN];

int compare (const void * a, const void * b)
{
  return ( *(long*)a - *(long*)b );
}

int main()
{
	long n, i, j;
	long rs, k;
	scanf("%d", &n);
	for(i = 0; i < n; i++)
	{
		scanf("%ld", &b[i]);
	}
	for(i = 0; i < n; i++)
	{
		scanf("%ld", &c[i]);
	}
	qsort(b, n, sizeof(long), compare);
	qsort(c, n, sizeof(long), compare);
	i = 0;
	j = n-1;
	rs = b[i] + c[j];
	rs = rs < 0 ? -rs : rs;
	while((i<n )&& (j>=0))
	{
		if(rs == 0) break;
		k = b[i] + c[j];
		if(k < 0) i++;
		else j--;
		k = k < 0 ? -k : k;
		rs = rs < k ? rs : k;
	}
	printf("%ld", rs);
	return 0;
}
