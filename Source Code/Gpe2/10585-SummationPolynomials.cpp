#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
	unsigned long long a;
	
	while (cin >> a)
	{
		a = a * (a + 1);
		a /= 2;
		a *= a;
		cout << a << endl;
	}
	
	return 0;
}
