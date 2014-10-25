#include <cstdio>
#include <cmath>
#include <vector>
#include <queue>
#define MAX 16000
using namespace std;
bool a[MAX];
vector<int> primes;

void sieve(int n)
{
    int i,j,k;
    int x = (int)sqrt(n);
    
    for(i=1;;i++)
    {
        k = (i<<1)+1;
        
        if(k>x) break;
        
        if(a[i]==0)
        {
        	primes.push_back(k);
            int y=k<<1;
            
            for(j=k*k-1; j<=n; j+=y)
            {
                if(a[j>>1]==0)
                    a[j>>1]=1;
            }
        }        
    }
    
	k = (n>>1) + n%2;
  
    for(; i<k; ++i)
    {
        if(!a[i])
            primes.push_back((i<<1)+1);
    } 
}

bool isprime(int n, int x)
{
	if(n&1)
	{
		if(n<=x) return !a[n>>1];
		
		x = (int)sqrt(n) + 1;

		for(int i=0; primes[i]<x; i++)
			if((n % primes[i]) == 0) return 0;
	}
	else return 0;
	
	return 1;
}

vector<int> find(int A, int B)
{
	int x = (int)sqrt(B);
	vector<int> rs;
	sieve(x);
	queue<int> q;
	q.push(2);
	q.push(3);
	q.push(5);
	q.push(7);
	int b = B/10;
	int k, p;
	
	while(!q.empty())
	{
		p = q.front();
		q.pop();

		if(p>=A && p<=B)
			rs.push_back(p);
		
		if(p>b) continue;
		
		p *= 10;
		
		k=p+1;
		if(k<=B && isprime(k, x)) q.push(k);
		
		k=p+3;
		if(k<=B && isprime(k, x)) q.push(k);
		
		k=p+7;
		if(k<=B && isprime(k, x)) q.push(k);
		
		k=p+9;
		if(k<=B && isprime(k, x)) q.push(k);
	}
	
	return rs;	
}

int main()
{
	int A, B;
	
	scanf("%d%d", &A, &B);
	
	vector<int> rs = find(A, B);
	int n = rs.size();
	
	printf("%d", n);
	
	for(int i=0; i<n; i++)
		printf("\n%d", rs[i]);
		
	return 0;
}
