#include <stdio.h>
#include <math.h>

int main()
{
	int A, B;
	int nA, nB;
	int n1, n2;
	
	scanf("%d%d", &A, &B);
	
	// (sqrt(1+8a)-1)/2 la nghiem cua phuong trinh n*(n+1)/2 = a hay
	// n^2 + n - 2a = 0;
	nA = (int)((sqrt(1+8*(A-1))-1)/2);
	nB = (int)((sqrt(1+8*B)-1)/2);

	// n*(n+1)/2
	n1 = (nA*(nA+1))>>1;
	n2 = (nB*(nB+1))>>1;
	
	A = (A-n1-1)*(nA+1);
	B = (B-n2)*(nB+1);
	
	// (n*(n+1)*(2n+1)/6
	nA = (n1*(nA*2+1))/3;
	nB = (n2*(nB*2+1))/3;
	
	printf("%d", nB-nA-A+B);
	
	return 0;
}
