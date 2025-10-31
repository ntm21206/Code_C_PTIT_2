#include <stdio.h>
#include <string.h>

int main() 
{
    int t;
    char line[10000];
    int num, sochan, sole, tongso;
    
    scanf("%d", &t);
    getchar();
    
    while (t--) 
	{
        fgets(line, sizeof(line), stdin);
        
        sochan = 0;
        sole = 0;
        tongso = 0;
        
        char *token = strtok(line, " \n");
        while (token != NULL) 
		{
            sscanf(token, "%d", &num);
            tongso++;
            
            if (num % 2 == 0) 
			{
                sochan++;
            } 
			else 
			{
                sole++;
            }
            
            token = strtok(NULL, " \n");
        }
        
        if ((tongso % 2 == 0 && sochan > sole) || (tongso % 2 == 1 && sole > sochan)) 
		{
            printf("YES\n");
        } 
		else 
		{
            printf("NO\n");
        }
    }
    
    return 0;
}
