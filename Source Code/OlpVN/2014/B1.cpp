#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;

int main()
{
	int test;
	int i;
	scanf("%d",&test);
	long long N,K,S,C1,C2,M;
	
	while(test--)
	{
		scanf("%lld%lld%ld%lld%lld%lld",&N,&K,&S,&C1,&C2,&M);
		vector<int> A;
		
		for(i=1;i<N;++i)
		{
			A.push_back(S);	
			S=(C1*S+C2)%M;
		}
		sort(A.begin(),A.end());
		
		for( i=0; i<K; ++i)
			printf("%d ", A[i]);
		
		printf("\n");
	}
	return 0;
}
