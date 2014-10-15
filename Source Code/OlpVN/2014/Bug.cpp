#include <cstdio>

int main()
{
	int ntest;
	int n, m;
	int x, y;
	bool check;
	char a[1001];
	int i, k;
	
	scanf("%d", &ntest);
	ntest++;
	
	for(k=1; k<ntest; k++)
	{
		scanf("%d%d", &n, &m);
		check = true;

		while(n--) a[n] = 0;
		
		while(m--)
		{
			scanf("%d%d", &x, &y);
			
			if(!a[x])
			{
				if(!a[y]) a[y]++;
				a[x] = 3 - a[y];
			}
			else if(a[x] == a[y])
			{
				check = false;
				break;
			}
			else a[y] = 3 - a[x];

		}
		printf("Test %d:\n", k);
		
		if(check)
			printf("Khong tim thay dau hieu nghi ngo\n");
		else 
			printf("Co dau hieu nghi ngo\n");
	}
	return 0;
}
