#include <stdio.h>

int main() 
{
    int n, i, j, min, temp;
    int a[100];
    
    scanf("%d", &n);
    
    for (i = 0; i < n; i++) 
	{
        scanf("%d", &a[i]);
    }
    
    for (i = 0; i < n - 1; i++) 
	{
        min = i;
        
        for (j = i + 1; j < n; j++) 
		{
            if (a[j] < a[min]) 
			{
                min = j;
            }
        }
        
        if (min != i) 
		{
            temp = a[i];
            a[i] = a[min];
            a[min] = temp;
        }
        
        for (j = 0; j < n; j++) 
		{
            printf("%d", a[j]);
            if (j < n - 1) printf(" ");
        }
        printf("\n");
    }
    
    return 0;
}
