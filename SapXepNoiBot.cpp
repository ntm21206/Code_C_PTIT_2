#include <stdio.h>

int main() 
{
    int n, i, j, temp;
    int mang[100];
    int buoc = 1;
    int codoithao;
    
    scanf("%d", &n);
    for (i = 0; i < n; i++) 
	{
        scanf("%d", &mang[i]);
    }
    
    for (i = 0; i < n - 1; i++) 
	{
        codoithao = 0;
        for (j = 0; j < n - 1 - i; j++) 
		{
            if (mang[j] > mang[j + 1]) 
			{
                temp = mang[j];
                mang[j] = mang[j + 1];
                mang[j + 1] = temp;
                codoithao = 1;
            }
        }
        
        if (codoithao) 
		{
            printf("Buoc %d: ", buoc);
            for (j = 0; j < n; j++) 
			{
                printf("%d", mang[j]);
                if (j < n - 1) printf(" ");
            }
            printf("\n");
            buoc++;
        } 
		else 
		{
            break;
        }
    }
    
    return 0;
}
