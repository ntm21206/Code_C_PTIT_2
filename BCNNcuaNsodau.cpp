#include<stdio.h>

long long gcd(long long a, long long b)
{
	while(b != 0)
	{
		long long temp = b;
		b = a % b;
		a = temp;
	}
	return a;
}

long long lcm(long long a, long long b)
{
	return (a / gcd(a,b)) * b;
}

long long timlcm(int n)
{
	long long ketqua = 1;
	for(int i = 2; i <= n; i++)
	{
		ketqua = lcm(ketqua,i);
	}
	
	return ketqua;
}

int main()
{
	int t;
	scanf("%d",&t);
	
	while(t--)
	{
		int n;
		scanf("%d",&n);
		printf("%lld\n", timlcm(n));
	}
	
	return 0;
}
