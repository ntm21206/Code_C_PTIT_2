#include <stdio.h> 

int timluythua(int n, int p)
{
	int ketqua = 0;
	int luythua = p;
	
	while(luythua <= n) 
	{
		ketqua += n / luythua;
		if(luythua > n / p) break;
		luythua *= p; 
	}
	
	return ketqua; 
} 

int main()
{
	int t;
	scanf("%d", &t);
	
	while(t--) 
	{
		int n;
		int p;
		scanf("%d  %d", &n,&p);
		 
		printf("%d\n", timluythua(n, p)); 
	}
	
	return 0; 
} 
