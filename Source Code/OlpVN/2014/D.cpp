#include<cstdio>
#include<cmath>
#define MAX 1000001

int a[MAX];
int b[1000];
bool c[MAX];

int main()
{
	int test;
	int N=0;
	int i,j;
	int M;
	scanf("%d",&test);
	
	for(i=0;i<test;i++)
	{
		scanf("%d",&b[i]);
		
		if(b[i]>N) N=b[i];
	}
	M=(int)sqrt(N)+1;
	a[1]=1;
	
	for(i=2;i<M;i++)
	{
		if(!c[i])
		{
			a[i]=a[i-1]+1;
			
			for(j=i+i;j<=N;j+=i) 
				c[j]=1;
		}
		else
			a[i]=a[i-1];
	}
	
	for(i=M;i<=N;i++)
	{
		if(!c[i])
			a[i]=a[i-1]+1;
		else
			a[i]=a[i-1];
	}
	
	for(i=1;i<test;i++)
		printf("Case #%d: %d\n",i,a[b[i-1]]);
	printf("Case #%d: %d",test,a[b[test-1]]);
	
	return 0;
}
