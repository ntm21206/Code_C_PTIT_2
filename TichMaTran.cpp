#include <stdio.h>

int main() 
{
    int n, m, p;
    int ma_tran_a[50][50];
    int ma_tran_b[50][50];
    int ma_tran_tich[50][50];
    
    scanf("%d %d %d", &n, &m, &p);
    
    for (int i = 0; i < n; i++) 
	{
        for (int j = 0; j < m; j++) 
		{
            scanf("%d", &ma_tran_a[i][j]);
        }
    }
    
    for (int i = 0; i < m; i++) 
	{
        for (int j = 0; j < p; j++) 
		{
            scanf("%d", &ma_tran_b[i][j]);
        }
    }
    
    for (int i = 0; i < n; i++) 
	{
        for (int j = 0; j < p; j++) 
		{
            ma_tran_tich[i][j] = 0;
            for (int k = 0; k < m; k++) 
			{
                ma_tran_tich[i][j] += ma_tran_a[i][k] * ma_tran_b[k][j];
            }
        }
    }
    
    for (int i = 0; i < n; i++) 
	{
        for (int j = 0; j < p; j++) 
		{
            printf("%d", ma_tran_tich[i][j]);
            if (j < p - 1) 
			{
                printf(" ");
            }
        }
        printf("\n");
    }
    
    return 0;
}
