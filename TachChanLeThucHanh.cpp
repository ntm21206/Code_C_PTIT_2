#include <stdio.h>
int main()
{
	int n;
	scanf("%d", &n);
	
	int mang[100];
	for(int i = 0; i < n; i++)
	{
		scanf("%d", &mang[i]);
	}
	
	int chan[100], le[100];
	int sochan = 0, sole = 0;
	
	for (int i = 0; i < n; i++)
	{
		if(mang[i] % 2 == 0)
		{
			chan[sochan] = mang[i];
			sochan++;
		}
		else
		{
			le[sole] = mang[i];
			sole++;
		}
	}
	
	for(int i = 0; i < sochan - 1; i++)
	{
		for(int j = i + 1; j < sochan; j++)
		{
			if(chan[i] > chan[j])
			{
				int tam = chan[i];
				chan[i] = chan[j];
				chan[j] = tam;
			}
		}
	}
	
	for(int i = 0; i < sole - 1; i++)
	{
		for(int j = i + 1; j < sole; j++)
		{
			if(le[i] > le[j])
			{
				int tam = le[i];
				le[i] = le[j];
				le[j] = tam;
			}
		}
	}
	
	for(int i = 0; i < sochan; i++)
	{
		printf("%d ",chan[i]);
	}
	
	for(int i = 0; i < sole; i++)
	{
		printf("%d ",le[i]);
	}
	
	return 0;
}
