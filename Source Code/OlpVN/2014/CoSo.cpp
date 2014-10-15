#include <cstdio>
#include <cmath>

unsigned long long get_min_base(unsigned long long a)
{
	unsigned long long b;
	unsigned long long r;
	unsigned long long c;
	unsigned long long sq = sqrt(a);
	unsigned long long d=1;
	
	for(unsigned long long i=2;; i++)
	{
		b = a;
		r = b % i;
		c = r;
		b = b / i;
		
		if(r != 0) d++;
		
		if(d==sq && d==i) return a-1;
		
		while(b>0)
		{
			r = b % i;
			b = b / i;
			if(r != c) break;
		}
		
		if(r==c) return i;
	}
	
	return a-1;
}

int main()
{
	int T;
	unsigned long long a;
	scanf("%d", &T);
	
	for(int i=0; i<T; i++)
	{
		scanf("%llu", &a);
		printf("%llu\n", get_min_base(a));
	}
	return 0;
}
