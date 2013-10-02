#include<stdio.h>
#include<string.h>
int c[31][31];//Mang to hop, max n = 31
char binary[32];//chuoi nhi phan
//Tinh to hop chap i cua j phan tu voi i = 1..n va j = 1..n
void combin_calc()
{
	int i, j;
	for(i = 0; i < 31; i++)
	{
		for(j = i; j < 31; j++)
		{
			if(i == j)
			{
				c[i][j] = 1;
			}
			else if(i == 0)
			{
				c[i][j] = j + 1;
			}
			else
			{
				c[i][j] = c[i][j-1] + c[i-1][j-1];
			}
		}
	}
}

//Lay to hop chap k cua n phan tu
int combin(int n, int k)
{
	if(k > n) return 0;
	if(k == 1 || k == n - 1) return n;
	if(k == 0 || k == n) return 1;
	return c[k-1][n-1];
}

int main()
{
	int n, k;
	int i, j, m;
	int rs;//Ket qua
	combin_calc();
	while(scanf("%d%d", &n, &k) > 0)
	{
		m = n;
		i = 0;
		//Chuyen sang chuoi nhi phan
		while(m)
		{
			binary[i++] = (m % 2) + 48;
			m >>= 1;
		}
		binary[i] = 0;
		//Tinh so cac chuoi nhi phan do dai i ma co dung k chu so 0 co nghia
		rs = combin(i, k + 1);
		//printf("%s\n", strrev(binary));
		//strrev(binary);
		//printf("combin(%d, %d) = %d\n", i, k + 1, combin(i, k + 1));
		//truong hop k = 1 co 1 so thoa man la so 0
		if(k == 1)
		{
			rs++;
		}
		i -= 2;
		k = i - k;
		while(i >= 0 && k <= i && k >= 0)
		{
			//printf("i = %d\n", i);
			//tim vi tri chu so 1 xuat hien dau tien
			for(j = i; j >= 0 && binary[j] == '0'; j--)
			{
				rs -= combin(j, k);
				//printf("combin(%d, %d) = %d\n", j, k, combin(j, k));
			}
			if(j == i)
			{
				i--;
				k--;
			}
			else
			{
				i = j;
			}
		}
		printf("%d\n", rs);
	}
	return 0;
}
