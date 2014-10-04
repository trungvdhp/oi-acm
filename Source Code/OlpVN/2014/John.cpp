#include <cstdio>

char a[250][251];

int main()
{
	int n, m;
	int i, j, k;
	int u, v;
	int count;
	bool check;
	scanf("%d",&n);
	
	for(i = 0; i < n; ++i)
		scanf("%s", &a[i]);
	n++;
		
	for(k = 2; k < n; ++k)
	{
		m = n - k;
		count = 0;
		
		for(i = 0; i < m; ++i)
		{
			for(j = 0; j < m; ++j)
			{
				if (a[i][j]=='1' && a[i+1][j]=='1' && a[i][j+1]=='1'&& a[i+1][j+1]=='1')
					count++;
				else a[i][j] = '0';
			}
		}
		
		if (count > 0)
			printf("%d %d\n", k, count);
	}
	return 0;
}
