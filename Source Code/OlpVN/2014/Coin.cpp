#include<stdio.h>
typedef struct way
		{
			int count;
			int trace;	
		}way;
		
way F[151][151];
int V[20],W[20];

int main()
{
	int n,mv,mw;
	int i,j,k;
	int v,w;
	scanf("%d%d%d",&n,&mv,&mw);
	
	for(i=0;i<n;i++)
		scanf("%d%d",&V[i],&W[i]);
		
	for(i=0;i<=mv;i++)
		for(j=0;j<=mw;j++)
			F[i][j].count=n+1;
	F[0][0].count=0;
	
	for(k=0;k<n;k++)
	{
		for(i=1;i<=mv;i++)
		{
			v=i-V[k];
			
			if(v>=0)
			{
				for(j=1;j<=mw;j++)
				{
					w=j-W[k];
					// Neu bo dieu kien !(F[v][w].trace & (1<<k)) thi se khong gioi han so luong dong moi loai duoc chon
					if(w>=0 && !(F[v][w].trace & (1<<k)) && F[v][w].count+1<F[i][j].count)
					{
						F[i][j].count=F[v][w].count+1;
						F[i][j].trace=F[v][w].trace|(1<<k);
					}
				}
			}
		}
	}
	
	if(F[mv][mw].count>n)
		printf("0");
	else
	{
		printf("%d\n",F[mv][mw].count);
	
		for(i=0;i<n;i++)
			if(F[mv][mw].trace & (1<<i))
				printf("%d ",i+1);
	}
	return 0;
}
