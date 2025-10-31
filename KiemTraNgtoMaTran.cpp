#include <stdio.h>

int nguyento(int so)
{
	if (so < 2)
	{
		return 0;
	}
	
	if (so == 2)
	{
		return 1;
	}
	
	if (so % 2 == 0)
	{
		return 0;
	}
	
	for (int i = 3; i * i <= so; i += 2)
	{
		if (so % i == 0)
		{
			return 0;
		}
	}
	
	return 1;
}

int main()
{
	int n,m;
	int matran[20][20];
	
	scanf("%d %d", &n, &m);
	
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			scanf("%d", &matran[i][j]);
		}
	}
	
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (nguyento(matran[i][j]))
			{
				matran[i][j] = 1;
			}
			else
			
			{
				matran[i][j] = 0;
			}
		}
	}
	
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			printf("%d", matran[i][j]);
			
			if ( j < m - 1)
			{
				printf(" ");
			}
		}
		
		printf("\n");
		
	}
	
	return 0;
	
}
