#include<stdio.h>
#include<string.h>
int f2[]={2, 4, 8, 16, 32, 64, 128, 256, 512, 1024, 2048, 4096, 8192, 16384};
int f5[]={5, 25, 125, 625, 3125, 15625};
char s[10001];
int a[123];
	
int count2(int n)
{
	int k=0;;
	int count=0;
	
	while(f2[k]<=n)
	{
		count+=n/f2[k];
		k++;
	}
	
	return count;
}

int count5(int n)
{
	int k=0;;
	int count=0;
	
	while(f5[k]<=n)
	{
		count+=n/f5[k];
		k++;
	}
	
	return count;
}

int main()
{
	int n;
	int i;
	int c2, c5;
	
	scanf("%s", &s);
	n=strlen(s);
	c2=count2(n);
	c5=count5(n);
	
	for(i='a'; i<='z'; i++) a[i] = 0;
	
	for(i=0; i<n; i++)
		a[s[i]]++;
		
	for(i='a'; i<='z'; i++)
		if(a[i]>1)
		{
			c2-=count2(a[i]);
			c5-=count5(a[i]);
		}
			
	printf("%d", c2<c5?c2:c5);
	
	return 0;
}
