#include <stdio.h>

long long UCLN(long long n) 
{
	long long uocmax = -1;
	
	while (n % 2 == 0) 
	{
		uocmax = 2;
		n /= 2; 
	}
	
	for ( long long i = 3; i * i <= n; i += 2) 
	{
		while ( n % i == 0)
		{
			uocmax = i;
			n /= i; 
		} 
	}
	
	if ( n > 2) 
	{
		uocmax = n; 
	}
	return uocmax; 
}

int main() 
{
	int t;
	scanf("%d", &t);
	
	while (t--) 
	{
		long long n;
		scanf("%lld",&n);
		
		printf("%lld\n", UCLN(n));
	}
	return 0; 
}
