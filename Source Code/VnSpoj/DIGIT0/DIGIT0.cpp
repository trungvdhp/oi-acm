#include<stdio.h>
#include<string.h>
int f[]={5, 25, 125, 625, 3125, 15625};
char s[10001];
int a[123];
	
int countP(int n)
{
	int k=0;;
	int count=0;
	
	while(f[k]<=n)
	{
		count+=n/f[k];
		k++;
	}
	
	return count;
}

int main()
{
	int n;
	int i;
	int count;
	
	scanf("%s", &s);
	n=strlen(s);
	count=countP(n);
	printf("%d\n", count);
	for(i='a'; i<='z'; i++) a[i] = 0;
	
	for(i=0; i<n; i++)
		a[s[i]]++;
		
	for(i='a'; i<='z'; i++)
		if(a[i]>1)
		{
			
			count-=countP(a[i]);
			printf("%c: %d - %d\n", i, a[i], count);
		}
			
	printf("%d", count);
	
	return 0;
}
