#include <stdio.h>

int thuannghich(int so) 
{
	int goc = so;
	int nguoc = 0;
	
	while (so > 0) 
	{
		nguoc = nguoc * 10 + so % 10;
		so /= 10; 
	}
	
	return goc == nguoc; 
}

int so9(int so) 
{
	while ( so > 0 ) 
	{
		if (so % 10 == 9)
		{
			return 0; 
		} 
		so /= 10; 
	}
	return 1; 
}

int main() 
{
	int n;
	int dem = 0;
	
	scanf ("%d",&n);
	
	for (int i = 2; i < n; i++)
	{
		if( thuannghich(i) && so9(i))  
		{
			printf("%d ", i);
			dem++; 
		}
	} 
	
	printf("\n%d\n", dem);
	
	return 0; 
}
