#include<cstdio>
#include<cstdlib>
#include<ctime>
#define MAXV 70000
#define MAXN 1000
using namespace std;

void gentest();
int a[MAXV];

int main()
{
	int n, i, j;
	int s, f;
	int m = 0;
	int rs = 1;
	gentest();
	
	freopen("ROOMS.INP", "rt", stdin);
	scanf("%d", &n);
	
	for(i = 0; i < n; ++i)
	{
		scanf("%d%d", &s, &f);
		if (rs < f) m = f;
		
		for(j = s; j < f; ++j)
			a[j]++;
	}
	
	for(i = 0; i < m; ++i)
		if (a[i] > rs) rs = a[i];
		
	freopen("ROOMS.OUT", "wt", stdout);
	printf("%d", rs);
	fclose(stdin);
	fclose(stdout);
	
	return 0;
}

void gentest()
{
	int s, f, n;
	
	freopen("ROOMS.INP", "wt", stdout);
	srand(time(NULL));
	n = rand()% (MAXN + 1);
	printf("%d\n", n);
	
	for(int i = 1; i < n; ++i)
	{
		s = rand() % (MAXV + 1);
		f = s + rand() % (MAXV + 1);
		
		if(n < f) n = f;
		
		printf("%d %d\n", s, f);
	}
	
	fclose(stdout);
}
