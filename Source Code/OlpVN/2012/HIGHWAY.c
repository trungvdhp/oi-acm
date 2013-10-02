#include<stdio.h>
#define MaxN 1000001
int a[MaxN];

int compare (const void * a, const void * b)
{
  return ( *(int*)a - *(int*)b );
}

int main()
{
	int n, i, j, d, min;
	freopen("HIGHWAY.INP","rt", stdin);
	scanf("%d", &n);
	
	for(i = 0; i < n; ++i)
	{
		scanf("%d", &a[i]);
	}
	
	fclose(stdin);
	qsort(a, n, sizeof(int), compare);
	min = a[1] - a[0];
	
	for(i=2; i<n; ++i)
	{
		if(min==0) break;
		if(a[i] - a[i-1] < min)
			min = a[i] - a[i-1];
	}
	
	freopen("HIGHWAY.OUT", "wt", stdout);
	printf("%d", min);
	return 0;
}
