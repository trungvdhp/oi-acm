#include <cstdio>

int main()
{
	int n;
	int i, j;
	int count=0, k=0;
	int d=1;
	int a[500001];
	
	scanf("%d", &n);
	
	for(i=0; i<n; i++)
		scanf("%d", &a[i]);

	for(i=0; i<n-2; i++)
	{
		//printf("i=%d ", i);
		if(a[i+1]<=a[i])
		{
			for(j=i+2; j<n; j++)
			{
				if(a[j]<=a[i])
				{
					if(a[j]==a[j-1]) k++;
				
					if(a[j]>a[j-1])
					{
						count+=k;
						k=0;
					}
					
					if(a[j]<a[j-1]) 
					{
						count+=j-i-2;
						
						if(k>0) count+=k-1;
						i=j-2;
						k=0;
						break;
					}
				}
				else 
				{
					count+=j-i-1+k;
					i=j-1;
					k=0;
					break;
				}
			}
			
			if(j==n) 
			{
				count+=k;
				//printf("j=%d count=%d\n", j, count);
				break;
			}
			
			//printf("j=%d count=%d\n", j, count);
		}
	}
	printf("%d", count + n-1);
	
	return 0;
}
