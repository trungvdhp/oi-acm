#include<stdio.h>
char b[3000001];
char ca[128];
char cb[128];
int main()
{
	int i, j, sa = 0, sb = 0, rs=0;
	int n, m;
	char c;
	scanf("%d%d", &n, &m);
	scanf("%c", &c);
	for(i = 0; i < n; i++)
	{
		scanf("%c", &c);
		ca[c]++;
	}
	scanf("%c", &c);
	for(i = 0; i < n; i++)
	{
		scanf("%c", &b[i]);
		cb[b[i]]++;
	}
	for(i = 0; i < 128; i++)
	{
		if(ca[i])
		{
			sa++;
			if(ca[i] == cb[i]) sb++;
		} 
	}
	if(sb == sa) rs++;
	//printf("sa = %d, sb = %d\n", sa, sb);
	for(i = n; i < m; i++)
	{
		scanf("%c", &b[i]);
		j = i - n;
		cb[b[j]]--;
		if(ca[b[j]])
		{
			if(ca[b[j]] == cb[b[j]] + 1) sb--;
			else if(ca[b[j]] == cb[b[j]]) sb++;
		}
		cb[b[i]]++;
		if(ca[b[i]])
		{
			if(ca[b[i]] == cb[b[i]] - 1) sb--;
			else if(ca[b[i]] == cb[b[i]]) sb++;
		}
		//printf("sb = %d\n", sb);
		if(sb == sa) rs++;
	}
	printf("%d", rs);
	return 0;
}
