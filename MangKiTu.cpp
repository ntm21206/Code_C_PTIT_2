#include <stdio.h>
#include <string.h>

int doixung(char xau[]) 
{
    char ngan[1000];
    int dinh = -1;
    int i;
    
    for (i = 0; i < strlen(xau); i++) 
	{
        char kitu = xau[i];
        
        if (kitu == '(' || kitu == '[' || kitu == '{' || kitu == '\'' || kitu == '"') 
		{
            dinh++;
            ngan[dinh] = kitu;
        }
        else if (kitu == ')' || kitu == ']' || kitu == '}' || kitu == '\'' || kitu == '"') {
            if (dinh == -1) return 0;
            
            char kitumo = ngan[dinh];
            
            if ((kitu == ')' && kitumo == '(') ||
                (kitu == ']' && kitumo == '[') ||
                (kitu == '}' && kitumo == '{') ||
                (kitu == '\'' && kitumo == '\'') ||
                (kitu == '"' && kitumo == '"')) {
                dinh--;
            }
            else 
			{
                return 0;
            }
        }
    }
    
    return (dinh == -1) ? 1 : 0;
}

int main() {
    char xau[1000];
    fgets(xau, sizeof(xau), stdin);
    
    if (xau[strlen(xau) - 1] == '\n') {
        xau[strlen(xau) - 1] = '\0';
    }
    
    printf("%d\n", doixung(xau));
    
    return 0;
}
