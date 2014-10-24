#include <iostream>
#include <set>
#include <queue>
#include <string>
#include <cstdlib>
using namespace std;

typedef pair<string, int> Pair;

/*inline bool less_than_second( const Pair& b1, const Pair& b2 ){
   return b1.second < b2.second;
}*/
queue< Pair > q;
char sm[10];
string buf;

int find(int n)
{
	int best = n;
	Pair p;
	int i;
	int y;
	buf = string(itoa(n, sm, 10));
	int k = buf.length();
	char c;
	q.push(make_pair(buf, 0));

	while(!q.empty())
	{
		p = q.front();
		q.pop();
		
		y = atoi(p.first.c_str());
		best = (best>y)?best:y;
			
		if(p.second < k)
		{
			c = p.first[p.second];
		
	    	if (c == '0')
	    	{
	    		q.push(make_pair(p.first, p.second+1));
	    	}
	    	else
	    	{
	    		c++;
	    		
	    		for (i = p.second+1; p.first[i]; i++) 
				{	
					if(p.first[i] > c)
					{
						p.first[p.second]--;
						p.first[i]--;
						swap(p.first[p.second], p.first[i]);
						q.push(make_pair(p.first, p.second));
						
						swap(p.first[p.second], p.first[i]);
						p.first[p.second]++;
						p.first[i]++;
					}
				}
				
				if(i==k)
					q.push(make_pair(p.first, p.second+1));
		    }	
		}	
	}
	return best;
}

int main()
{
	int n;
	
	while(cin >> n)
		cout << find(n) << endl;
	//system("pause");
	return 0;
}

