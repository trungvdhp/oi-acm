#include <cstdio>

int main()
{
	int N=1, L, C;
	
	while(N)
	{
		scanf("%d%d%d", &N, &L, &C);
		int K = (C+1)/(L+1);
		
		if (K%13 == 0) K--;
		int M = N/K;
		K = N - M*K;
		
		if(M ==0 && K%13 == 0) M++;
		
		if(K>0) M++;
		printf("%d", M);
	}
	return 0;
}
