#include<cstdio>
#include<vector>
using namespace std;

int main()
{
	int test;
	scanf("%d",&test);
	long long N, K, S, C1, C2, M;
	long long n, k;
	int i, j;
	
	while(test--)
	{
		scanf("%lld%lld%ld%lld%lld%lld",&N, &K, &S, &C1, &C2, &M);
		n=S>M?S:M;
		vector<int> A(n);
		
		for( i=1; i<N; ++i)
		{
			A[S]++;
			S = (C1*S + C2) % M;
		}
		i=0;
		k=0;
		
		for( i=0; i<n && k<K; ++i)
		{
			if (A[i])
				for( j=0; j<A[i] && k<K; j++, k++)
					printf("%d ", i);
		}
		printf("\n");
	}
	return 0;
}
