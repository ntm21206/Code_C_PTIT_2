#include <stdio.h>

int main() 
{
    int t, n, i;
    long long a[100000];
    long long maxsum, currentsum;
    
    scanf("%d", &t);
    
    while (t--) 
	{
        scanf("%d", &n);
        
        for (i = 0; i < n; i++) 
		{
            scanf("%lld", &a[i]);
        }
        
        maxsum = a[0];
        currentsum = a[0];
        
        for (i = 1; i < n; i++) 
		{
            if (currentsum < 0) 
			{
                currentsum = a[i];
            } 
			else 
			{
                currentsum += a[i];
            }
            
            if (currentsum > maxsum) 
			{
                maxsum = currentsum;
            }
        }
        
        printf("%lld\n", maxsum);
    }
    
    return 0;
}
