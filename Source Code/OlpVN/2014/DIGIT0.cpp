#include<cstdio>
#include<cstring>
int f2[]={2, 4, 8, 16, 32, 64, 128, 256, 512, 1024, 2048, 4096, 8192, 16384};
int f5[]={5, 25, 125, 625, 3125, 15625};

// Tinh so mu cua thua so 2 trong n!
int count2(int n)
{
	int k=0;;
	int count=0;
	
	while(f2[k]<=n)
		count+=n/f2[k++];
	
	return count;
}

// Tinh so mu cua thua so 5 trong n!
int count5(int n)
{
	int k=0;;
	int count=0;
	
	while(f5[k]<=n)
		count+=n/f5[k++];
	
	return count;
}


// Xau S co N ki tu, tan so cua cac ki tu xuat hien nhieu hon 1 lan (=2) la
// {a(1), a(2), .., a(k)}, a(i)>=2, i=1..k
// So cach xep a(i) ki tu giong nhau la
// mot to hop chap a(i) cua N - (a(1)+a(2)+..+a(i-1)) ki tu
// Tong tan so cua cac ki tu xuat hien chi 1 lan trong chuoi la
// a(k+1) = N - (a(1) + a(2) + .. + a(k))
// So cach xep a(k+1) ki tu khac nhau vao (k+1) vi tri la 1 hoan vi cua a(k+1)
// Tong so cach xep
// P = C(N, a(1)) * C(N-a(1), a(2)) * C(N-(a(1)+a(2)), a(3)) * .. *
// * C(N-(a(1)+a(2)+..+a(k-1)), a(k)) * a(k+1)!
// Rut gon
// P = N!/(a(1)! * a(2)! * a(3)! * .. * a(k)!)
// P co dang (..*2^x*5^y)/(..*2^z*5^t)
// So chu so 0 tan cung cua P = min(x-z, y-t);
int main()
{
	int test;
	int n;
	int i;
	int c2, c5;
	char s[10001];
	int a[91];

	scanf("%d", &test);
	
	while(test--)
	{
		scanf("%s", &s);
		n=strlen(s);
		c2=count2(n);
		c5=count5(n);
		
		for(i='A'; i<='Z'; i++) a[i] = 0;
		
		for(i=0; i<n; i++)
			a[s[i]]++;
			
		for(i='A'; i<='Z'; i++)
			if(a[i]>1)
			{
				c2-=count2(a[i]);
				c5-=count5(a[i]);	
			}
				
		printf("%d\n", c2<c5?c2:c5);
	}
	return 0;
}
