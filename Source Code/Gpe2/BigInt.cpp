#include <iostream>
#include <string>
#include <cstdio>
#include <algorithm>
using namespace std;
const int BASE = 10;

class BigInt
{
	public:
		int length;
		string value;
    	BigInt(); 
		BigInt(int);
    	BigInt(const string &);
    	BigInt(const BigInt & rhs);
    	const BigInt & operator = (const BigInt &);
	    const BigInt & operator += (const BigInt &);
	    const BigInt & operator *= (const BigInt &);
	    const BigInt & operator *= (int num);
	    string ToString() const;
    	bool Equal(const BigInt & rhs)        const;
    	bool LessThan(const BigInt & rhs)     const;
    	int  GetDigit(int k) const;
    	void ChangeDigit(int k, int a);
    	void AppendDigit(int a);
};

// free functions

ostream & operator <<(ostream &, const BigInt &);
istream & operator >>(istream &, BigInt &);

BigInt operator +(const BigInt & lhs, const BigInt & rhs);
BigInt operator *(const BigInt & lhs, const BigInt & rhs);
BigInt operator *(const BigInt & lhs, char num);
BigInt operator *(char num, const BigInt & rhs);

bool operator == (const BigInt & lhs, const BigInt & rhs);
bool operator <  (const BigInt & lhs, const BigInt & rhs);
bool operator != (const BigInt & lhs, const BigInt & rhs);
bool operator >  (const BigInt & lhs, const BigInt & rhs);
bool operator >= (const BigInt & lhs, const BigInt & rhs);
bool operator <= (const BigInt & lhs, const BigInt & rhs);

BigInt::BigInt()
{
	value = "0";
	length = 1;
}

BigInt::BigInt(const BigInt & rhs)
{
	value = rhs.value;
	length = rhs.length;  
}

const BigInt & BigInt::operator = (const BigInt & rhs)
{
	value = rhs.value;
	length = rhs.length;
	
	return *this;
}

BigInt::BigInt(int num)
{
	AppendDigit(num % BASE);
    num /= BASE;
    
    while (num != 0)
    {   
		AppendDigit(num % BASE);
        num /= BASE;
    }
    
	length = value.length();
}

BigInt::BigInt(const string & s)
{
	value = s;
	reverse(value.begin(), value.end());
	length = s.length();
}

const BigInt & BigInt::operator +=(const BigInt & rhs)
{
	int sum;
    int carry = 0;
    int k;
    int len = length;

    if (this == &rhs)
    {
		*this *= 2;
      	return *this;
    }

    if (rhs.value == "0")
    {
   		return *this;
    }

    if (len < rhs.length)
    {
        len = rhs.length;
    }
    
    for (k = 0; k < len; k++)
    {
        sum = GetDigit(k) + rhs.GetDigit(k) + carry;
        carry = sum / BASE;
        sum = sum % BASE;

        if (k < length)
        {
            ChangeDigit(k, sum);
        }
        else
        {
            AppendDigit(sum);
        }
    }
    
    if (carry != 0)
    {
        AppendDigit(carry);
    }
    
    return *this;
}

BigInt operator +(const BigInt & lhs, const BigInt & rhs)
{
    BigInt result(lhs);
    result += rhs;
    return result;
}

string BigInt::ToString() const
{
    string s = value;
    reverse(s.begin(), s.end());

    return s;
}

ostream & operator <<(ostream & out, const BigInt & big)
{
    out << big.ToString();
    return out;
}

istream & operator >> (istream & in, BigInt & big)
{
    string s;
    in >> s;
    big = BigInt(s);
    return in;
}

bool operator == (const BigInt & lhs, const BigInt & rhs)
{
    return lhs.Equal(rhs);
}

bool BigInt::Equal(const BigInt & rhs) const
{

    if (length != rhs.length)
    {
        return false;
    }

    int k;
    
    for (k = 0; k < length; k++)
    {
        if (value[k] != rhs.value[k]) return false;
    }

    return true;
}

bool operator != (const BigInt & lhs, const BigInt & rhs)
{
    return ! (lhs == rhs);
}

bool operator < (const BigInt & lhs, const BigInt & rhs)
{
    return lhs.LessThan(rhs);
}

bool BigInt::LessThan(const BigInt & rhs) const
{
    if (length != rhs.length)
    {
        return (length < rhs.length);
    }
    
    int k;

    for(k = length - 1; k >= 0; k--)
    {
        if (value[k] < rhs.value[k]) return true;
        if (value[k] > rhs.value[k]) return false;
    }
    
    return false;
}

int BigInt::GetDigit(int k) const
{
    if (0 <= k && k < length)
    {
        return value[k] - '0';
    }
    
    return 0;
}

void BigInt::ChangeDigit(int k, int a)
{
    if (0 <= k && k < length)
    {
        value[k] = char('0' + a);
    }
}

void BigInt::AppendDigit(int a)
{
	char c = '0' + a;
	value += c;
	length++;
}

bool operator > (const BigInt & lhs, const BigInt & rhs)
{
    return rhs < lhs;
}

bool operator <= (const BigInt & lhs, const BigInt & rhs)
{
    return lhs == rhs || lhs < rhs;
}
bool operator >= (const BigInt & lhs, const BigInt & rhs)
{
    return lhs == rhs || lhs > rhs;
}

const BigInt & BigInt::operator *=(int num)
{
    int carry = 0;
    int product;
    int k;

    if (0 == num)
    {
       	value = "0";
       	length = 1;
       	
        return *this;
    }

    if (1 == num)
    {
        return *this;
    }
	
    for (k = 0; k < length; k++)
    {
        product = num * GetDigit(k) + carry;
        carry = product/BASE;
        ChangeDigit(k, product % BASE);
    }

    while (carry != 0)
    {
        AppendDigit(carry % BASE);
        carry /= BASE;
    }
    
    return *this;
}


BigInt operator *(const BigInt & a, int num)
{
    BigInt result(a);
    result *= num;
    return result;
}

BigInt operator *(int num, const BigInt & a)
{
    BigInt result(a);
    result *= num;
    return result;
}


const BigInt & BigInt::operator *=(const BigInt & rhs)
{
    BigInt self(*this);
    BigInt sum; 
    int k;
    int len = rhs.length;

    for (k = 0; k < len; k++)
    {
       sum += self * rhs.GetDigit(k); 
       self *= BASE; 
    }
    *this = sum;
    
    return *this;
}

BigInt operator *(const BigInt & lhs, const BigInt & rhs)
{
    BigInt result(lhs);
    result *= rhs;
    return result;
}

void Init(BigInt *mat)
{
	mat[0] = BigInt(1);
	mat[1] = BigInt(1);
	mat[2] = BigInt(1);
	mat[3] = BigInt(0);
}

void Copy(BigInt *mat1,BigInt *mat2)
{
	mat1[0] = mat2[0];
	mat1[1] = mat2[1];
	mat1[2] = mat2[2];
	mat1[3] = mat2[3];
}

BigInt* MultiplyMatrix(BigInt *mat1, BigInt *mat2) 
{
	BigInt *mat = new BigInt[4];
	
	mat[0] = mat1[0]*mat2[0] + mat1[1]*mat2[2];
	mat[1] = mat1[0]*mat2[1] + mat1[1]*mat2[3];
	mat[2] = mat1[2]*mat2[0] + mat1[3]*mat2[2];
	mat[3] = mat1[2]*mat2[1] + mat1[3]*mat2[3];
	
	return mat;
}

BigInt Fibonacci(int n) 
{
	BigInt number[4];
    BigInt result[4];
	Init(number);
	Init(result);

    if (n == 0) 
	{
        return BigInt(0);
    }
    else if (n < 3) 
	{
        return BigInt(1);
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

int main()
{
	int n;
	
	while (scanf("%d", &n) > 0)
    {
    	cout << "The Fibonacci number for " << n << " is " << Fibonacci(n) << endl;
    }
	
	return 0;
}
