#include<cstdio>

int main()
{
	int test;
	int k;
	long long a[]={-1, -1, -1, -1, 1210, 21200, -1, 3211000, 42101000, 521001000, 6210001000};
	scanf("%d",&test);
	
	while(test--)
	{
		scanf("%d",&k);
		
		if(k>0)
			printf("%lld",a[k]);
		else
			printf("-1");
			
		if(test) printf("\n");
	}
	return 0;
}
