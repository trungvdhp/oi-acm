#include<stdio.h>
#include<math.h>
//Phan tich ra thua so nguyen to
int main()
{
	int n, i, j, k, m;
	while(1)
	{
		scanf("%d", &n);
		if(n == 0) break;
		printf("%d: ", n);
		m = sqrt(n);
		for(i = 2; i <= m; i++)
		{
			k = 0;
			j = 0;
			while(1)
			{
				k = n % i;
				if(k) break;
				n = n / i;
				j++;
			}
			
			if(j > 0)
			{
				printf("%d^%d ",i, j);
			}
		}
		if(n > 1)
		{
			printf("%d", n);
		}
		printf("\n");
	}
	return 0;		
}
