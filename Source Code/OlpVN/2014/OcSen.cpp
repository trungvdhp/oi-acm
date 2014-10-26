#include <cstdio>

int main()
{
	int A, B, V;
	int x;
	
	scanf("%d%d%d", &A, &B, &V);
	
	x=(V-B)/(A-B);
	
	if((A-B)*x+B < V) x++;
	
	printf("%d", x);
	
	return 0;
}
