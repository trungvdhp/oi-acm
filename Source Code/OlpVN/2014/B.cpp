#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
// Chay loi dang sua
void binary_insert(vector<int> *A, int i, int K, int value)
{
	int M=min(i,K);
	int left=0;
	int right=M-1;
	int mid;

	while(left<=right)
	{
		mid=(left+right)>>1;
		
		if((*A)[mid]<value)
			left=mid+1;
		else if((*A)[mid]>value)
			right=mid-1;
		else break;
	}
	//printf("Found value=%d A[%d]=%d\n",value,mid,(*A)[mid]);

	for(right=M;right>mid;right--)
		(*A)[right]=(*A)[right-1];
			
	if((*A)[mid] >= value)
		(*A)[mid]=value;
	else if(mid==0)
		(*A)[mid+1]=value;
	else
		(*A)[M]=value;
	
	/*for(int j=0; j<=M; ++j)
		printf("%d ", (*A)[j]);
	printf("\n");*/
}
int main()
{
	int test;
	int i;
	scanf("%d",&test);
	long long N,K,S,C1,C2,M;
	
	while(test--)
	{
		scanf("%lld%lld%ld%lld%lld%lld",&N,&K,&S,&C1,&C2,&M);
		vector<int> A(K);
		A[0]=S;
		
		for(i=1;i<N;++i)
		{	
			S=(C1*S+C2)%M;
			binary_insert(&A,i,K,S);
			//if(S==40) break;
		}

		for( i=0; i<K; ++i)
			printf("%d ", A[i]);
		
		printf("\n");
	}
	return 0;
}
