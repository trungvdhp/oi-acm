#include <cstdio>

char a[250][251];
bool c[250][250];

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
		
	for(k = 2; k <= n; ++k)
	{
		m = n - k + 1;
		count = 0;
		
		for(i = 0; i < m; ++i)
		{
			for(j = 0; j < m; ++j)
			{
				if (!c[i][j])
				{
					check = true;
					
					for(u = 0; u < k; ++u)
					{
						for(v = 0; v < k; ++v)
						{
							if (a[i+u][j+v] == '0')
							{
								check = false;
								break;
							}
						}
						
						if (!check)
						{
							c[i][j] = true;
							break;				
						}
					}
					
					if (check) count++;
				}
			}
		}
		
		if (count > 0)
			printf("%d %d\n", k, count);
	}
	return 0;
}
