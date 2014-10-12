#include <cstdio>
int get_min_3(int x, int y, int z)
{
	if(y<x) x = y;
	
	if(z<x) x = z;
	
	return x;
}

int main()
{
	int n;
	int i, j;
	int max_size=0;
	int count=0;
	
	scanf("%d", &n);
	int a[n][n];
	
	for(i=0; i<n; i++)
		for(j=0; j<n; j++)
			scanf("%d", &a[i][j]);
	
	for(i=1; i<n; i++)
		for(j=1; j<n; j++)
			if(a[i][j]>0)
				a[i][j] = get_min_3(a[i-1][j-1], a[i-1][j], a[i][j-1])+1;
				
	for(i=0; i<n; i++)
	{
		for(j=0; j<n; j++)
		{
			if(a[i][j]>max_size)
			{
				max_size = a[i][j];
				count = 1;
			}
			else if(a[i][j]==max_size)
				count++;
		}
	}
	
	printf("%d", max_size*count);
	return 0;
}
