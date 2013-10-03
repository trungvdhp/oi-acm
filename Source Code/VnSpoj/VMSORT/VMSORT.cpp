#include<iostream>
#include<set>
using namespace std;
int main()
{
	int k, n;
	set<string> a;
	string s;
	cin>>k;
	while(k--)
	{
		cin>>n;
		while(n--)
		{
			cin>>s;
			a.insert(s);
		}
	}
	cout<<a.size();
	return 0;
}
