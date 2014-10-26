#include <cstdio>
#include <cmath>
// if a = m^2-n^2 = (m-n)(m+n) = xy => m=(x+y)/2, n=(x-y)/2 then b=2mn=(x^2-y^2)/2
// if a = 2mn  then b = m^2-n^2
// b > a, c=m^2+n^2

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
		
		if(T) printf("\n");
	}
	return 0;
}
