#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cstring>

int main()
{
	int i, n, m, x, K;
	char buf[30];
	scanf("%d", &K);
	
	x =(int)log2(K);
	
	if(K==1) n=0;
	else n = K+1-(1<<x);
	itoa(n, buf, 2);
	m = strlen(buf);
	
	if(m<x)
	{
		x-=m;
		for(i=0; i<x; i++) printf("4");
	}
	
	for(i=0; buf[i]; i++)
	{
		if(buf[i] == '0') buf[i] = '4';
		else buf[i] = '7';
	}
	printf("%s", buf);
	
	return 0;
}
