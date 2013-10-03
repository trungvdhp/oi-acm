#include <stdio.h>
#include <malloc.h>

void Copy(unsigned long long *mat1,unsigned long long *mat2)
{
	mat1[0] = mat2[0];
	mat1[1] = mat2[1];
	mat1[2] = mat2[2];
	mat1[3] = mat2[3];
}

unsigned long long* MultiplyMatrix(unsigned long long *mat1, unsigned long long *mat2) 
{
	unsigned long long *mat = malloc(4*sizeof(unsigned long long));
	
	mat[0] = mat1[0]*mat2[0] + mat1[1]*mat2[2];
	mat[1] = mat1[0]*mat2[1] + mat1[1]*mat2[3];
	mat[2] = mat1[2]*mat2[0] + mat1[3]*mat2[2];
	mat[3] = mat1[2]*mat2[1] + mat1[3]*mat2[3];
	
	return mat;
}

unsigned long long Fibonacci(unsigned long long n) 
{
	unsigned long long number[4] = { 1, 1 , 1, 0 };
    unsigned long long result[4] = { 1, 1 , 1, 0 };
    
    if (n == 0) 
	{
        return 0;
    }
    else if (n < 3) 
	{
        return 1;
    }

    while (n) 
	{
        if (n % 2) 
			Copy(result, MultiplyMatrix(result, number));
        Copy(number, MultiplyMatrix(number, number));
        n >>= 1;
    }
    
    return result[3];
}

unsigned long long main() 
{
    int n;
    
    while (scanf("%d", &n) > 0)
    {
    	printf("%lld\n", Fibonacci(n));
    }
    
    return 0;
}
