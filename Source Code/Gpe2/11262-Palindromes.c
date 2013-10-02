#include <stdio.h>
#include <string.h>

char s[1001];
	
int dx(int i, int j)
{
	while (i < j)
	{
		if (s[i] != s[j]) return 0;
		i++;
		j--;
	}
	
	return 1;
}

int main()
{
	int i, j, k, n, m, count;
	
	scanf("%d", &n);
	
	while (n--)
	{
		scanf("%s", &s);
		m = strlen(s);
		k = 0;
		count = 0;
		
		while (k < m)
		{
			i = k;
			
			for (j = i + 1; j < m; j++)
			{
				if (dx(i, j)) k = j;
			}
			k++;
			count++;
		}
		
		printf("%d\n", count);
	}
	
	return 0;
}
