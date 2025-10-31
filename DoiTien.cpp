#include <stdio.h>

int main() 
{
    int t, n;
    int menhgia[] = {1000, 500, 200, 100, 50, 20, 10, 5, 2, 1};
    int soto, i;
    
    scanf("%d", &t);
    
    while (t--) 
	{
        scanf("%d", &n);
        soto = 0;
        
        for (i = 0; i < 10; i++) 
		{
            soto += n / menhgia[i];
            n %= menhgia[i];
        }
        
        printf("%d\n", soto);
    }
    
    return 0;
}
