#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main()
{
    char chuoi[1001];
    char cacTu[100][51];
    int soLan[100];
    int soTu = 0;
    char *tu;
    int i, j, timThay;
    
    fgets(chuoi, sizeof(chuoi), stdin);
    
    tu = strtok(chuoi, " \n\t");
    
    while (tu != NULL)
    {
        for (i = 0; tu[i]; i++)
        {
            tu[i] = tolower(tu[i]);
        }
        
        timThay = 0;
        for (i = 0; i < soTu; i++)
        {
            if (strcmp(cacTu[i], tu) == 0)
            {
                soLan[i]++;
                timThay = 1;
                break;
            }
        }
        
        if (!timThay)
        {
            strcpy(cacTu[soTu], tu);
            soLan[soTu] = 1;
            soTu++;
        }
        
        tu = strtok(NULL, " \n\t");
    }
    
    for (i = 0; i < soTu; i++)
    {
        printf("%s %d\n", cacTu[i], soLan[i]);
    }
    
    return 0;
}
