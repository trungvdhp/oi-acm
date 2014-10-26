#include <cstdio>
#include <cmath>
int main()
{
	int T;
	int a, b;
	int i, x, y, count;
	scanf("%d", &T);
	
	while(T--)
	{
		scanf("%d", &a);
		count = 0;
		x = (int)sqrt(a)+1;
		
		if(!(a&1))
		{
			b=a>>1;
			y=(int)sqrt(b)+1;
			
			for(i=1; i<y; i++)
			{
				if(b%i==0 && (b/i)*(b/i)-i*i > a)
					count++;
			}
		}
		
		for(i=1; i<x; i++)
		{
			if(a%i==0)
			{
				b=a/i;
				
				if(b!=i && !((b-i)&1) && ((b*b-i*i)>>1) > a)
					count++;
			}	
		}
		
		printf("%d", count);
		
		if(T>1) printf("\n");
	}
	return 0;
}
