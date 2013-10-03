#include<stdio.h>
int main()
{
	long n, i = 0, j, k, m;
	char arr[33], tmp;
	scanf("%ld", &n);
	while(n)
	{
		arr[i++] = (n % 2) + 48;
		n >>= 1;
	}
	arr[i] = 0;
	k = i - 1;
	i >>= 1;
	for(j = 0; j < i; j++)
	{
		tmp = arr[j];
		m = k - j;
		arr[j] = arr[m];
		arr[m] = tmp;
	}
	printf("%s", arr);
	return 0;
}
