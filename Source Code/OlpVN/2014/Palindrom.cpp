#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cctype>
#define N 301
int main()
{
	int a[N];
	char buf[10];
	char check;
	int i,j;
	int m, k;
	int b;
	
	scanf("%d", &b);
	
	if(b<2 || k > 20) return 0;
	
	for(i=1; i<N; i++)
		a[i] = i*i;
		
	for(i=1; i<N; i++)
	{
		itoa(a[i], buf, b);
		m = strlen(buf);
		k = m/2 + 1;
		m--;
		check = 1;
		
		for(j=0; j<k; j++)
			if(buf[j] != buf[m-j])
			{
				check = 0;
				break;
			}
		if(check)
		{
			for(j=0; j<k; j++) buf[j] = toupper(buf[j]);
			
			printf("%d %s\n", i, buf);
		}
	}
	return 0;
}
