#include <iostream>
#include <set>
#include <string>
#include <vector>
using namespace std;
typedef unsigned long long ull;
int main()
{
	int i;
	int n, m;
	ull a1, a2;
	string query;
	
	vector<ull> qa;
	vector<ull> qb;
	
	multiset<int> mb;
	multiset<int>::iterator itlow,itup;	
	
	cin>>n;
	a1=0;
	qa.push_back(a1);
	qb.push_back(a1);
	mb.insert(a1);
	
	for(i=0; i<n; i++)
	{
		cin>>a2;
		qa.push_back(a2);
		a1^=a2;
		qb.push_back(a1);
		mb.insert(a1);
	}
	n++;
	cin>>m;
	
	while(m--)
	{
		cin>>query;
		
		if(query=="POP")
		{
			qa.erase(qa.begin());
			mb.clear();
			
			for(i=1; i<n; i++)
			{
				qb[i]=qb[i]^qb[0];
				mb.insert(qb[i]);
			}
			qb.erase(qb.begin());
			n--;
		}
		else if(query=="PUSH")
		{
			cin>>a1;
			qa.push_back(a1);
			qb.push_back(a1^qb[n-1]);
			mb.insert(qb[n]);
			n++;;
		}
		else
		{
			cin>>a1>>a2;
			itlow=mb.lower_bound(a1);
			itup=mb.upper_bound(a2);
			cout<<distance(itlow, itup)<<endl;
		}
	}
	
	return 0;
}
