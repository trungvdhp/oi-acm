#include<cstdio>
#include<cmath>
int main()
{
	int n;
	int m;
	double count;
	int i;
	
	scanf("%d",&n);
	m=n/2+n%2;
	count=pow(2,m);
	char bin[n+1];
	bin[n]=0;
	
	printf("%.0lf",count);
	
	if(n)
	{
		for(i=0;i<n;i++)
		{
			bin[i]='0';
		}
		printf("\n%s",bin);
	
		while(1)
		{
			for(i=m-1;i>=0;i--)
			{
				if(bin[i]=='0')
				{
					bin[i]='1';
					bin[n-i-1]='1';
					break;
				}
				bin[i]='0';
				bin[n-i-1]='0';
			}
			
			if(i==-1) break;
			printf("\n%s",bin);
		}
	}
	
	
	return 0;
}
