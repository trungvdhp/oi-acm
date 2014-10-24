#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <set>
#define MAX 2147000000
using namespace std;

int find(int N, int M, set<int> a)
{
	int p;
	int k;
	int i;
	char buf[11];
	bool odd=true;
	bool five=false;
	bool check;
	
	if(N==0) return 0;
	
	if(N==1) return *(a.begin());
	
	for (set<int>::iterator it=a.begin(); it!=a.end(); ++it)
	{
		if(!((*it)&1)) odd=false;
		
		if(!((*it)%5)) five=true;
	}
	
	if( (odd && ((N&1) == 0)) || (!five && (N%5)==0) ) return 0;
	
	
	for(k=N; k<MAX; k+=N)
	{
		sprintf(buf, "%d", k);
		check = true;
		
		for(i=0; buf[i]; i++)
			if(a.find(buf[i]-'0')==a.end())
			{
				check = false;
				break;
			}
		if(check) return k;
	}
	
	return 0;
}

int main()
{
	int N;
	int M;
	int i;
	int k;
	
	while(scanf("%d%d", &N, &M))
	{
		set<int> a;
		
		for(i=0; i<M; i++)
		{
			scanf("%d", &k);
			a.insert(k);
		}
		printf("%d\n", find(N, M, a));
	}
	return 0;
}
