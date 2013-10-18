#include <iostream>
#include <cstdio>
#include <ctime>
#define INT_MIN -2147483647
#define MAXN 500
using namespace std;
int a[MAXN][MAXN];

int lss(int *a,int n)
{
    int i,j;
    int rs=INT_MIN;
    int *b=new int[n+1];
    int *c=new int[n+1];
    b[0]=0;
    c[0]=0;
    for(int i=1;i<=n;i++)
        b[i]=b[i-1]+a[i-1];
    for(i=1;i<=n;i++)
        c[i]=b[c[i-1]]>b[i-1]?i-1:c[i-1];
    for(i=1;i<=n;i++)
        if(rs<b[i]-b[c[i]])
            rs=b[i]-b[c[i]];
    return rs;             
}

int LargestSumSubMatrix(int r, int c)
{
    int i,j,k,total,max=INT_MIN;
    if(r>c)
    {
    	int *b=new int[r];
	    for(i=0;i<c;i++)
	    {
	        for(k=0;k<r;k++)
	            b[k]=0;
	        for(j=i;j<c;j++)
	        {
	            for(k=0;k<r;k++)
	                b[k]+=a[k][j];
	            total=lss(b,r);
	            if(max<total)
	                max=total;
	        }
	    }
    }
    else
    {
    	int *b=new int[c];
	    for(i=0;i<r;i++)
	    {
	        for(k=0;k<c;k++)
	            b[k]=0;
	        for(j=i;j<r;j++)
	        {
	            for(k=0;k<c;k++)
	                b[k]=b[k]+a[j][k];
	            total=lss(b,c);
	            if(max<total)
	                max=total;
	        }
	    }
    }
    
    return max;
}

int main()
{
	int m,n,x,y;
	int i, j, k;
	clock_t start = clock();
	scanf("%d%d%d%d",&m,&n,&x,&y);
	x+=y;
	for(i=0;i<m;i++)
		for(j=0;j<n;j++)
		{
			scanf("%d", &y);
			a[i][j]=y-x;
		}
	printf("%d\n", LargestSumSubMatrix(m,n));
	clock_t finish = clock();
	printf("%.10lf", (double)(finish - start)*1.0f/CLOCKS_PER_SEC);
	return 0;
}
