#include <stdio.h>

int main() 
{
    int n, i, j, key;
    int mang[100];
    
    scanf("%d", &n);
    for (i = 0; i < n; i++) 
	{
        scanf("%d", &mang[i]);
    }
    
    printf("Buoc 0: %d\n", mang[0]);
    
    for (i = 1; i < n; i++) 
	{
        key = mang[i];
        j = i - 1;
        
        while (j >= 0 && mang[j] > key) 
		{
            mang[j + 1] = mang[j];
            j--;
        }
        mang[j + 1] = key;
        
        printf("Buoc %d: ", i);
        for (j = 0; j <= i; j++) 
		{
            printf("%d", mang[j]);
            if (j < i) printf(" ");
        }
        printf("\n");
    }
    
    return 0;
}
