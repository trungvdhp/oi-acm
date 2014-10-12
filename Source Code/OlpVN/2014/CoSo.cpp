#include <cstdio>

unsigned long long get_min_base(unsigned long long a)
{
	unsigned long long b;
	unsigned long long r;
	unsigned long long c;
	
	for(unsigned long long i=2;; i++)
	{
		b = a;
		r = b % i;
		c = r;
		b = b / i;
		
		while(b>0)
		{
			r = b % i;
			b = b / i;
			if(r != c) break;
		}
		
		if(b==0) return i;
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
