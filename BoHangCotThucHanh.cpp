#include <stdio.h>

int main()
{
    int t;
    scanf("%d", &t);
    
    for(int test = 1; test <= t; test++)
    {
        int n, m;
        scanf("%d %d", &n, &m);
        
        int matran[10][10];
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                scanf("%d", &matran[i][j]);
            }
        }
        
        int tongHang[10];
        for(int i = 0; i < n; i++)
        {
            tongHang[i] = 0;
            for(int j = 0; j < m; j++)
            {
                tongHang[i] += matran[i][j];
            }
        }
        
        int hangMax = 0;
        for(int i = 1; i < n; i++)
        {
            if(tongHang[i] > tongHang[hangMax])
            {
                hangMax = i;
            }
        }
        
        int matranMoi[10][10];
        int hangMoi = 0;
        for(int i = 0; i < n; i++)
        {
            if(i != hangMax)
            {
                for(int j = 0; j < m; j++)
                {
                    matranMoi[hangMoi][j] = matran[i][j];
                }
                hangMoi++;
            }
        }
        n--;
        
        int tongCot[10];
        for(int j = 0; j < m; j++)
        {
            tongCot[j] = 0;
            for(int i = 0; i < n; i++)
            {
                tongCot[j] += matranMoi[i][j];
            }
        }
        
        int cotMax = 0;
        for(int j = 1; j < m; j++)
        {
            if(tongCot[j] > tongCot[cotMax])
            {
                cotMax = j;
            }
        }
        
        int ketQua[10][10];
        for(int i = 0; i < n; i++)
        {
            int cotMoi = 0;
            for(int j = 0; j < m; j++)
            {
                if(j != cotMax)
                {
                    ketQua[i][cotMoi] = matranMoi[i][j];
                    cotMoi++;
                }
            }
        }
        m--;
        
        printf("Test %d:\n", test);
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                printf("%d ", ketQua[i][j]);
            }
            printf("\n");
        }
    }
    
    return 0;
}
