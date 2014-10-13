#include<cstdio>
#include<cstring>
int f[]={5, 25, 125, 625, 3125, 15625};

// Dem chu so 0 tan cung cua so cac hoan vi P=N!
// N! = ...2^x.5^y, y <= x => count = min(x, y) = y

int countP(int n)
{
	int k=0;;
	int count=0;
	
	while(f[k]<=n)
	{
		count+=n/f[k];
		k++;
	}
	
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
// So chu so 0 tan cung cua P = so chu so 0 tan cung cua N! tru di 
// tong so chu so 0 tan cung cua a(1)!, a(2)!,..,a(k)!
int main()
{
	int test;
	int n;
	char s[10001];
	int a[91];
	int i;
	int count;
	
	scanf("%d", &test);
	
	while(test--)
	{
		scanf("%s", &s);
		n=strlen(s);
		count=countP(n);
		
		for(i='A'; i<='Z'; i++) a[i] = 0;
		
		for(i=0; i<n; i++)
			a[s[i]]++;
			
		for(i='A'; i<='Z'; i++)
			if(a[i]>1)
				count-=countP(a[i]);	
		printf("%d\n", count);
	}
	return 0;
}
