#include <cstdio>
#define K 1000000007
typedef unsigned long long ull;
ull b1, b2, b3, b4;
ull f[2][2]={{1, 1},{1, 0}};
ull b[2][2]={{1, 1},{1, 0}};

void Mul(ull b[][2], ull c[][2])
{
	b1=(((b[0][0]*c[0][0])%K) + ((b[0][1]*c[1][0])%K))%K;
	b2=(((b[0][0]*c[0][1])%K) + ((b[0][1]*c[1][1])%K))%K;
	b3=(((b[1][0]*c[0][0])%K) + ((b[1][1]*c[1][0])%K))%K;
	b4=(((b[1][0]*c[0][1])%K) + ((b[1][1]*c[1][1])%K))%K;
	
	b[0][0]=b1;
	b[0][1]=b2;
	b[1][0]=b3;
	b[1][1]=b4;
}

void Fibo(ull f[][2], ull N)
{
	while(N)
	{
		if(N&1) Mul(f, b);
		Mul(b, b);
		N >>= 1;
	}
}

int main()
{
	ull a1, n;
	scanf("%llu%llu", &a1, &n);
	Fibo(f, n);
	printf("%llu", ((a1%K)*(f[0][0]-1))%K);
	
	return 0;
}
