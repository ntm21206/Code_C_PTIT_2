#include <stdio.h>

int main() 
{
    int a;
    scanf("%d", &a);
    
    if (a == 0) 
	{
        printf("0\n");
        return 0;
    }
    
    char nhiphan[32];
    int chiSo = 0;
    
    while (a > 0) 
	{
        nhiphan[chiSo] = (a % 2) + '0';
        a = a / 2;
        chiSo++;
    }
    
    for (int i = chiSo - 1; i >= 0; i--) 
	{
        printf("%c", nhiphan[i]);
    }
    printf("\n");
    
    return 0;
}
