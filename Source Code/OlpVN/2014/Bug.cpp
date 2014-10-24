#include<stdio.h>
#define MAX 2001

int father[MAX], mark[MAX], rank[MAX];

int find(int t)
{
    int tmp=t,flag=mark[t];
    
    while(father[tmp]!=tmp)
	{
        flag^=mark[father[tmp]];
        tmp=father[tmp];
    }
    father[t]=tmp;
    mark[t]=flag;
    
    return tmp;
}

int main()
{
    int i, nTest, k=1;
    int n, m;
    int x, y;
    int a, b, flag;
    
    scanf("%d",&nTest);
    
    for(k=1; k<=nTest; k++)
	{
        scanf("%d%d",&n,&m);
        flag = 0;
        
        for(i=1; i<=n; i++) 
		{
			father[i] = i;
			mark[i] = 0;
			rank[i] = 0;
		}
        
        while(m--)
		{
            scanf("%d%d",&a,&b);
            
            x = find(a);
            y = find(b);
            
            if(flag==0 && x==y && mark[a]==mark[b]) 
				flag=1;
            else if(flag==0 && x!=y)
			{
                if(rank[x] > rank[y])
				{
                    father[x] = y;
                    mark[x] = !(mark[a]^mark[b]);
                }
                else
				{
                    father[y] = x;
                    mark[y] = !(mark[a] ^ mark[b]);
                    
                    if(rank[x] == rank[y]) 
						rank[x]++;
                }
            }
        }
        printf("Scenario #%d:\n", k);
        	
        if(flag==1) 
			printf("Suspicious bugs found!\n");
        else 
			printf("No suspicious bugs found!\n");
    }
    
    return 0;
}
