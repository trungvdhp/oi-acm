#include <cstdio>

int main()
{
	int T; 
	int m, n;
	int i, j;
	int count;
	char a[100][100];
	
	scanf("%d", &T);
	
	while(T--)
	{
		scanf("%d%d", &m, &n);
		count = 0;
		
		for(i=0; i<m; i++)
			for(j=0; j<n; j++)
				scanf("%d", &a[i][j]);
				
		for(i=0; i<n; i++)
		{
			a[m-1][i] = !a[m-1][i];
			
			for(j=m-2; j>=0; j--)
			{
				if(a[j][i])
				{
					count+=a[j+1][i];
					a[j][i]=a[j+1][i];
				}
				else
				{
					a[j][i]=a[j+1][i]+1;
				}
			}
		}
		printf("%d", count);
		
		if(T) printf("\n");
	}
	return 0;
}
