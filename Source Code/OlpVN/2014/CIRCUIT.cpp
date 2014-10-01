#include <cstdio>
#include <vector>
using namespace std;
int start;
vector < vector<int> > a(201);
vector <bool> visited(201);
vector <int> trace(201);

bool dfs(int v)
{
	
	int k = a[v].size();
	bool chk = false;
	visited[v] = true;
	
	for( int u=0; u<k; ++u)
	{	
		if (!visited[ a[v][u] ])
		{
			trace[ a[v][u] ] = v;
			chk = dfs(a[v][u]);
			
			if (chk) break;
		}
		else if (a[v][u] == start && trace[v] != start)
		{
			trace[start] = v;
			chk = true;
			break;
		}
	}
	
	return chk;
}

int main()
{
	int n;
	int u,v;
	scanf("%d%d", &n, &start);
	
	while( scanf("%d%d", &u, &v) == 2)
	{
		a[u].push_back(v);
		a[v].push_back(u);
	}

	bool chk = dfs(start);
		
	if (chk)
	{
		printf("YES\n");
		u=start;
		
		while(1)
		{
			printf("%d ", u);
			u = trace[u];
			
			if(u==start)
			{
				printf("%d", start);
				break;
			}
		}
	}
	else printf("NO");
	
	return 0;
}
