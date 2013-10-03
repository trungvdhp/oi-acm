#include<stdio.h>
#include<conio.h>
#include<math.h>
#include<stdlib.h>
void quick_sort(int *a,int l,int r)
{
	int i,j,mid,tg;
	i=l;
	j=r;
	mid=(l+r)/2;
	while(i<j)
	{
	while(a[i]<a[mid]) i++;
	while(a[j]>a[mid]) j--;
	if (i<=j)
	{
		tg=a[i];
		a[i]=a[j];
		a[j]=tg;
	}
	i++;
	j--;
	}
	if (i<r) quick_sort(a,i,r);
	if(j>l) quick_sort(a,l,j);
}
int main()
{
	int n,i,min;
	int *a;
	FILE *f;
	f=fopen("HIGHWAY.INP","rt");
	fscanf(f,"%d",&n);
	for (i=0;i<n;i++)
	fscanf(f,"%d",&a[i]);
	fclose(f);
	quick_sort(a,0,n-1);
	min=abs(a[0]-a[1]);
	for(i=0;i<n-1;i++)
	if (abs(a[i]-a[i+1])<min)
	min=abs(a[i]-a[i+1]);
	f=fopen("HIGHWAY.OUT","wt");
	fprintf(f,"%d",min);
	fclose(f);
	getch();
	return 0;
}
	
	
	
		
