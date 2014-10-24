#include <cstdio>
#include <cmath>
#include <vector>
#define MAX 50000000
using namespace std;
bool a[MAX];
bool seg[MAX];

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
            int y=k<<1;
            
            for(j=k*k-1; j<=n; j+=y)
            {
                if(a[j>>1]==0)
                    a[j>>1]=1;
            }
        }        
    }
}

vector<int> get_primes(int n)
{
	vector<int> primes;
	int i;
	
	if(n<2) return primes;
	
	int m = (n>>1) + n%2;
	//primes.push_back(2);
	    
    for(i=1; i<m; ++i)
    {
        if(!a[i])
            primes.push_back((i<<1)+1);
    }
    
    return primes;
}

vector<int> get_primes(int A, int B)
{
	vector<int> primes;
	int i;
    A = A>>1;
    B = (B>>1) + B%2;
	    
    for(i=A; i<B; ++i)
    {
        if(seg[i-A]==0)
            primes.push_back((i<<1)+1);
    }
    
    return primes;
}

void sieve(int A, int B)
{
    int i,j,k;
    vector<int> p = get_primes((int)sqrt(B));
    int m = p.size();
    double x = (double)A;
    A = A>>1;
        
    for(i=0; i<m;i++)
    {
    	k = max((int)ceil(x/p[i]), 2);
        
        for(j=k*p[i]; j<=B; j+=p[i])
        {
            if(seg[(j>>1)-A]==0)
                seg[(j>>1)-A]=1;
        }
    }
}

int main()
{
	int i;
	int count=0;
	int A, B;
	scanf("%d%d", &A, &B);
	int M = MAX<<1;
	vector<int> rs;
	int n, k;
	bool check;
	int x;
	
	if(M>B)
	{
		sieve(B);
	    A = A>>1;
	    B = (B>>1) + B%2;
	    
	    for(i=A; i<B; ++i)
	    {
	        if(a[i]==0)
	        {
	        	
	        	x = (i<<1)+1;
	        	k=x;
	        	check=true;
	        	
	        	while(1)
	        	{
	        		k = k/10;
	        	
	        		if(k<3) break;
	        		
	        		if(k%2==0 || a[k>>1])
	        		{
	        			check=false;
	        			break;
	        		}
	        	}
	        	
	        	if(check)
	        	{
	        		rs.push_back(x);
	        	}
	        } 
	    }
	}
	else if(M<A)
	{
		sieve(M);
		sieve(A, B);
		vector<int> primes = get_primes(A, B);
		
		n = primes.size();
		
		for(i=0; i<n; i++)
		{
			check=true;
	        x = primes[i];
			k = x;

        	while(1)
        	{
        		k = k/10;
        		
        		if(k<3) break;
        		
        		if(k%2==0 || a[k>>1])
        		{
        			check=false;
        			break;
        		}
        	}
        	
        	if(check)
        		rs.push_back(x);
		}
	}
	else
	{
		sieve(M);
		sieve(M, B);
		vector<int> primes = get_primes(M, B);
		
		A = A>>1;
	    M = (M>>1) + M%2;
	    
	    for(i=A; i<MAX; ++i)
	    {
	        if(a[i]==0)
	        {
	        	x = (i<<1)+1;
	        	k = x;
	        	check=true;
	        	
	        	while(1)
	        	{
	        		k = k/10;
	        		
	        		if(k<3) break;
	        		
	        		if(k%2==0 || a[k>>1])
	        		{
	        			check=false;
	        			break;
	        		}
	        	}
	        	
	        	if(check)
	        		rs.push_back(x);
	        } 
	    }
	    
	    n = primes.size();
		
		for(i=0; i<n; i++)
		{
			check=true;
	        x = primes[i];
	        k = x;
				
        	while(1)
        	{
        		k = k/10;
        		
        		if(k<3) break;
        		
        		if(k%2==0 || a[k>>1])
        		{
        			check=false;
        			break;
        		}
        	}
        	
        	if(check)
        		rs.push_back(x);
		}
	}
	
	n = rs.size();
	printf("%d", n);
	
	if(n)
	{
		for(i=0; i<n; i++)
			printf("\n%d", rs[i]);
	}
	return 0;
}
