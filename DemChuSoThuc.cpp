#include <stdio.h>
#include <string.h>

int main()
{
    char num[25];
    int count = 0;
    int i;

    scanf("%s", num);

    for (i = 0; i < strlen(num); i++)
    {
        if (num[i] >= '0' && num[i] <= '9')
        {
            count++;
        }
    }
    
    printf("%d\n", count);
    
    return 0;
}
