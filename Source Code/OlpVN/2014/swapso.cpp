#include <iostream>
#include <set>
#include <queue>
#include <cstdlib>
using namespace std;
queue<int> q;
set<int> used;
char buf[10];
int find(int n)
{
	int best = n;
	int m;
	int i, j;
	q.push(n);
	used.insert(n);
	while(!q.empty())
	{
		m = q.front();
		q.pop();
		sprintf(buf, "%d", m);
		for (i = 0; buf[i]; i++) 
		{
        	if (buf[i] == '0') 
				continue;
        	for (j = i+1; buf[j]; j++) 
			{
          		if (buf[j] == '0') 
				  	continue;
          		buf[i]--; buf[j]--; 
				swap(buf[i], buf[j]);
          		int y = atoi(buf);
          		if (used.find(y) == used.end()) 
				{
            		used.insert(y);
            		q.push(y);
            		//if(y > best) cout << y << endl;
            		best = (best>y)?best:y;
            		
          		}
          		
				swap(buf[i], buf[j]); buf[i]++; buf[j]++;
				/*if(y==866236200)
					cout << "i=" << i << " j=" << j << " src=" << buf << endl;*/
				
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

