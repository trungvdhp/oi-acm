#include<cstdio>
#include<cstdlib>

struct task
{
	int start;
	int end;
};
// Ham so sanh dung cho QuickSort: Sap xep theo thoi diem bat dau tang dan
// neu thoi diem bat dau bang nhau thi sap xep giam dan theo thoi diem ket thuc			
int compare(const void*, const void*);

int main()
{
	int i;
	int n;
	task t1,t2,t3;
	// max1: khoang thoi gian dai nhat luon co chuong trinh chay
	// max2: khoang thoi gian dai nhat luon khong co chuong trinh chay
	int max1,max2;
	scanf("%d",&n);
	task T[n];
	// Doc du lieu thoi gian cua cac tac vu
	for(i=0;i<n;i++)
		scanf("%d%d",&T[i].start,&T[i].end);
	// Dung QuickSort sap xep cac tac vu cho de xu ly
	qsort(T,n,sizeof(task),compare);
	//Doc [p q] va [r s]
	scanf("%d%d",&t1.start,&t1.end); 
	scanf("%d%d",&t2.start,&t2.end);
	
	// Kiem tra xem doan [p,q] luon co chuong trinh chay khong
	for(i=0;i<n;i++)
	{
		if(T[i].start>t1.start || t1.start>t1.end) break;
		
		if(T[i].end>t1.start) t1.start=T[i].end;
	}
	
	if(t1.start<t1.end) printf("0");
	else printf("1");
	// Kiem tra xem doan [r,s] luon ko co chuong trinh chay khong
	for(i=0;i<n;i++)
	{
		if(T[i].end<t2.start) continue;
		else if(T[i].start>t2.end)
		{
			i=n;
			break;
		}
		else break;
	}
	
	if(i==n) printf("\n1");
	else printf("\n0");
	// Tim doan t2=[p,q] dai nhat ma tai moi thoi diem luon co chuong trinh chay
	// va tim doan t3=[r,s] dai nhat ma tai moi thoi diem luon ko co chuong trinh chay
	t1=T[0];
	t2.start=0;
	t2.end=0;
	max1=0;
	
	t3.start=0;
	t3.end=t1.start-1;
	max2=t1.start;
	
	for(i=1;i<n;i++)
	{
		if(T[i].start>t1.end)
		{
			if(t1.end-t1.start+1>max1)
			{
				 max1=t1.end-t1.start+1;
				 t2=t1;
			}
			
			if(T[i].start-t1.end-1>max2)
			{
				t3.start=t1.end+1;
				t3.end=T[i].start-1;
				max2=t3.end-t3.start+1;
			}
			t1=T[i];
		}
		else if(T[i].end>t1.end) t1.end=T[i].end;
	}
	// Xu ly cho khoang thoi gian cuoi cung va in ket qua
	if(t1.end-t1.start+1>max1) t2=t1;
	printf("\n%d %d",t2.start,t2.end);
	
	if(8640000-T[n-1].end>max2)
	{
		t3.start=T[n-1].end+1;
		t3.end=8640000;
	}
	printf("\n%d %d",t3.start,t3.end);
	
	return 0;
}

int compare(const void *a, const void *b)
{
	task s1=*(task*)a;
	task s2=*(task*)b;
	
	if(s1.start!=s2.start) 
		return s1.start-s2.start;
	return s2.end-s1.end;
}
