#include<cstdio>
#include<cmath>
#include<set>
using namespace std;
int distance(int x1, int y1, int x2, int y2);

int main()
{
	int n, m;
	int x0, y0, x1, y1, x2, y2;
	int d;
	
	set<int> a;
	set<int>::iterator it;
	
	freopen("PERIM.INP", "rt", stdin);
	scanf("%d", &n);
	
	for(int i=0; i<n; ++i)
	{
		scanf("%d",&m);
		scanf("%d%d%d%d", &x0, &y0, &x1, &y1);
		d = distance(x0, y0, x1, y1);
		
		for(int j = 2; j<m; ++j)
		{
			scanf("%d%d", &x2, &y2);
			d += distance(x1, y1, x2, y2);
			x1 = x2;
			y1 = y2;
		}
		
		if(m > 2) d += distance(x0, y0, x1, y1);
		
		for(it = a.begin(); it != a.end(); ++it)
		{
			if((*it) % d == 0) break;
			if(d % (*it) == 0) a.erase(it);
		}
		
		if(it == a.end()) a.insert(d);
	}
	
	freopen("PERIM.OUT", "wt", stdout);
	printf("%d\n", a.size());
	
	for(it = --a.end(); it != a.begin(); --it) printf("%d ", *it);
	printf("%d", *it);
	
	return 0;
}

int distance(int x1, int y1, int x2, int y2)
{
	return abs(x2 - x1) + abs(y2 - y1);
}
