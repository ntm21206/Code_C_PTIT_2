#include <stdio.h>
#include <string.h>

long long taosomin(long long so)
{
	char chuoi[20];
	sprintf(chuoi,"%lld", so);
	int dodai = strlen(chuoi);
	
	for (int i = 0; i < dodai; i++)
	{
		if(chuoi[i] == '6')
		{
			chuoi[i] = '5';
		}
	}
	
	long long ketqua;
	sscanf(chuoi,"%lld", &ketqua);
	return ketqua;
}
long long taosomax(long long so)
{
	char chuoi[20];
	sprintf(chuoi,"%lld",so);
	int dodai = strlen(chuoi);
	
	for (int i = 0; i < dodai; i++)
	{
		if(chuoi[i] == '5')
		{
			chuoi[i] = '6';
		}
	}
	
	long long ketqua;
	sscanf(chuoi,"%lld", &ketqua);
	return ketqua;
}
int main()
{
	int t;
	scanf("%d",&t);
	
	while (t--)
	{
		long long x1,x2;
		scanf("%lld %lld", &x1, &x2);
		
		long long tongmin = taosomin(x1) + taosomin(x2);
		long long tongmax = taosomax(x1) + taosomax(x2);
		
		printf("%lld %lld\n", tongmin, tongmax);
	}
	
	return 0;
}
