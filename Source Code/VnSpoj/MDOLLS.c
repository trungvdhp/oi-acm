#include<stdio.h>
#include<stdlib.h>
#define SIZE 20001
typedef struct wood
{
	int l;
	int w;
}wood;
wood a[SIZE];
int lis[SIZE];
int k;
void insert(int left, int right, int x)
{
    if(left == right)
    {
        if(x <= lis[left]) lis[k++] = x;
        else lis[left] = x;
        return;
    }   
    int middle = (left + right) >> 1;
    if(x > lis[middle]) insert(left, middle, x);
    else insert(middle + 1, right, x);
}
int compare (const void * a, const void * b)
{
	wood w1 = (*(wood*)a);
	wood w2 = (*(wood*)b);
	if(w1.l == w2.l)
		return w2.w - w1.w;
	return w1.l - w2.l;
}
int main()
{
	int i, t, n;
	scanf("%d", &t);
	while(t--)
	{
		scanf("%d", &n);
		for(i = 0; i < n; i++)
			scanf("%d%d", &a[i].l, &a[i].w);
		qsort(a, n, sizeof(wood), compare);
		lis[0] = a[0].w;
		k = 1;
	    for(i = 1; i < n; i++)
	    	insert(0, k - 1, a[i].w);
		printf("%d\n", k);
	}
	return 0;
}
