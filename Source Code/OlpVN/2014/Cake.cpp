#include <cstdio>
#include <cmath>

struct cake
{
	int size;
	int diff;
	int left;
	int right;
};

int get_min_diff(cake* a, int m)
{
	int min = 2000000000;
	int i, k;
	
	for(i = 0; i < m; ++i)
	{
		if(a[i].size > 0)
		{
			k = i;
			break;
		}
	}
	
	for(; i < m; ++i)
	{
		if(a[i].size > 0)
		{
			if((a[i].diff < a[k].diff) || (a[i].diff == a[k].diff && a[i].size > a[k].size))
			{
				k = i;
			}
		}
	}
	
	return k;
}

int main()
{
	cake a[48];
	int m=0;
	int rem;
	int n;
	int i, j, k;
	int r, l;
	int sum;
	
	while(scanf("%d", &a[m].size) > 0) m++;
	
	n = m/3;
	k = 0;
	sum = 0;
	
	a[0].diff = a[m-1].size + a[1].size - a[0].size;
	a[0].left = m-1;
	a[0].right = 1;
	
	a[m-1].diff = a[m-2].size + a[0].size - a[m-1].size;
	a[m-1].left = m-2;
	a[m-1].right = 0;
	
	for(i = 1; i < m-1; ++i)
	{
		a[i].left = i-1;
		a[i].right = i+1;
		a[i].diff = a[a[i].left].size + a[a[i].right].size - a[i].size;
	}
		
	for(i = 0; i < n; ++i)
	{
		k = get_min_diff(a, m);
		sum += a[k].size;
		
		r = a[a[k].right].right;
		a[r].left = a[a[k].left].left;
		a[r].diff = a[a[r].left].size + a[a[r].right].size - a[r].size;
		
		l = a[r].left;
		a[l].right = r;
		a[l].diff = a[a[l].left].size + a[a[l].right].size - a[l].size;
		
		a[k].size = 0;
		a[a[k].left].size = 0;
		a[a[k].right].size = 0;
		
		/*printf("\n------------------------------------------------------------\n");
		printf("%-5s ", "ID");
		for(j = 0; j < m; ++j)
		{
			printf("%-3d ", j);
		}
		printf("\n------------------------------------------------------------\n");
		printf("%-5s ", "SIZE");
		
		for(j = 0; j < m; ++j)
		{
			printf("%-3d ", a[j].size);
		}
		printf("\n");
		printf("%-5s ", "LEFT");
		for(j = 0; j < m; ++j)
		{
			printf("%-3d ", a[j].left);
		}
		printf("\n");
		printf("%-5s ", "RIGHT");
		for(j = 0; j < m; ++j)
		{
			printf("%-3d ", a[j].right);
		}
		printf("\n");
		printf("%-5s ", "DIFF");
		for(j = 0; j < m; ++j)
		{
			printf("%-3d ", a[j].diff);
		}
		printf("\n------------------------------------------------------------");
		printf("\nEATS CAKE #%d\n", k);*/
	}
	/*printf("\n------------------------------------------------------------\n");
	printf("TOTAL SIZE ");*/
	printf("%d", sum);
	
	return 0;
}
