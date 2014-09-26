#include<stdio.h>
#include<stdlib.h>

typedef struct segment
		{
			int start;
			int end;
		}SEG;
				
int compare(const void *a, const void *b)
{
	SEG s1=*(SEG*)a;
	SEG s2=*(SEG*)b;
	
	if(s1.start!=s2.start) 
		return s1.start-s2.start;
	return s2.end-s1.end;
}

int main()
{
	int n;
	int p,q,r,s;
	int i;
	int max1,max2,maxp,maxq,maxr,maxs;
	scanf("%d",&n);
	SEG A[n];
	
	for(i=0;i<n;i++)
		scanf("%d%d",&A[i].start,&A[i].end);
	qsort(A,n,sizeof(SEG),compare);
	
	scanf("%d%d",&p,&q);
	scanf("%d%d",&r,&s);
	
	// Kiem tra xem doan [p,q] luon co chuong trinh chay khong
	for(i=0;i<n;i++)
	{
		if(A[i].start>p || p>q) break;
		if(A[i].end>p) p=A[i].end;
	}
	if(p<q) printf("0");
	else printf("1");
	// Kiem tra xem doan [r,s] luon ko co chuong trinh chay khong
	for(i=0;i<n;i++)
	{
		if(A[i].end<r) continue;
		else if(A[i].start>s)
		{
			i=n;
			break;
		}
		else break;
	}
	
	if(i==n) printf("\n1");
	else printf("\n0");
	// Tim doan [p,q] dai nhat ma tai moi thoi diem luon co chuong trinh chay
	// Va tim doan [r,s] dai nhat ma tai moi thoi diem luon ko co chuong trinh chay
	p=A[0].start;
	q=A[0].end;
	
	max1=0;
	maxp=0;
	maxq=0;
	
	maxr=0;
	maxs=p-1;
	max2=maxs-maxr+1;
	
	for(i=1;i<n;i++)
	{
		if(A[i].start>q)
		{
			if(q-p+1>max1)
			{
				 max1=q-p+1;
				 maxp=p;
				 maxq=q;
			}
			
			if(A[i].start-q-1>max2)
			{
				maxr=q+1;
				maxs=A[i].start-1;
				max2=maxs-maxr+1;
			}
			p=A[i].start;
			q=A[i].end;
		}
		else if(A[i].end>q)
		{
			q=A[i].end;
		}
	}
	
	if(q-p+1>max1)
	{
		 maxp=p;
		 maxq=q;
	}
			
	printf("\n%d %d",maxp,maxq);
	
	if(8640000-A[n-1].end>max2)
	{
		maxr=A[n-1].end+1;
		maxs=8640000;
	}

	printf("\n%d %d",maxr,maxs);
	return 0;
}
