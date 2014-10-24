// Road
#include <iostream>
#include <fstream>
#include <queue>
#include <vector>
#include <set>
using namespace std;
int k, n, r;
class State
{
	public:
		int vertex;
		int distance;
		int cost;
		State(int v, int d, int c):vertex(v),distance(d), cost(c)
		{
		}
		friend bool operator < (const State & s1, const State & s2)
		{
         if(s1.distance != s2.distance)
				return s1.distance > s2.distance;
			if(s1.cost != s2.cost)
				return s1.cost > s2.cost;
			if(s1.vertex != s2.vertex)
				return s1.vertex > s2.vertex;
			return false;
		}
};

int main()
{
	int i, s, d, l, t;
	bool found = false;
	vector<State> edge[100];
	ifstream fin("roads.in2",ifstream::in);
	fin >> k >> n >> r;
	for(i=0;i<r;i++)
	{
		fin >> s >> d >> l >> t;
		edge[s-1].emplace_back(State(d-1, l, t));
	}
	fin.close();
	priority_queue<State> pq;
	set<State> visited;
	pq.push(State(0,0,0));
	while(!pq.empty())
	{
		State node = pq.top();
		int v = node.vertex;
		int distance = node.distance;
		int cost = node.cost;
		pq.pop();
		if(v==n-1)
		{
			cout << node.distance;
			found = true;
			break;
		}
		visited.insert(node);
		/*
		for(vector<State>::iterator it=edge[v].begin();it!=edge[v].end();it++)
		{
			if((visited.find(*it)==visited.end())&&(cost+it->cost<=k))
				pq.push(State(it->vertex, distance+it->distance, cost+it->cost));
		}
		*/
		for(auto it: edge[v])
		{
			if((visited.find(it)==visited.end())&&(cost+it.cost<=k))
				pq.push(State(it.vertex, distance+it.distance, cost+it.cost));
		}		
	}
	if(!found)
		cout << "-1";
	system("pause");
	return 0;
}
/*
		for(auto it: edge[v])
		{
			if((visited.find(it)==visited.end())&&(cost+it.cost<=k))
				pq.push(State(it.vertex, distance+it.distance, cost+it.cost));
		}
*/
