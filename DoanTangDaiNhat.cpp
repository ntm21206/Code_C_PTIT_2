#include <stdio.h>

int main() 
{
    int sotest, n, i, j;
    int mang[100];
    int dodai[100], batdau[100];
    int dodaimax, soduongmax;
    
    scanf("%d", &sotest);
    
    for (int test = 1; test <= sotest; test++) 
	{
        scanf("%d", &n);
        
        for (i = 0; i < n; i++) 
		{
            scanf("%d", &mang[i]);
        }
        
        dodaimax = 1;
        soduongmax = 0;
        
        for (i = 0; i < n; i++) 
		{
            dodai[i] = 1;
            batdau[i] = i;
            
            for (j = i + 1; j < n && mang[j] > mang[j-1]; j++) 
			{
                dodai[i]++;
            }
            
            if (dodai[i] > dodaimax) 
			{
                dodaimax = dodai[i];
                soduongmax = 1;
            } 
			else if (dodai[i] == dodaimax) 
			{
                soduongmax++;
            }
        }
        
        printf("Test %d:\n", test);
        printf("%d\n", dodaimax);
        
        for (i = 0; i < n; i++) 
		{
            if (dodai[i] == dodaimax) 
			{
                for (j = i; j < i + dodaimax; j++) 
				{
                    printf("%d", mang[j]);
                    if (j < i + dodaimax - 1) printf(" ");
                }
                printf("\n");
                i += dodaimax - 1;
            }
        }
    }
    
    return 0;
}
