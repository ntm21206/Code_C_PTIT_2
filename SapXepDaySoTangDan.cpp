#include <stdio.h>

int main()
{
    int n;
    scanf("%d", &n);
    
    int mang[200];
    for(int i = 0; i < n; i++)
    {
        scanf("%d", &mang[i]);
    }
    
    for(int buoc = 0; buoc < n - 1; buoc++)
    {
        int viTriMin = buoc;
        for(int j = buoc + 1; j < n; j++)
        {
            if(mang[j] < mang[viTriMin])
            {
                viTriMin = j;
            }
        }
        
        if(viTriMin != buoc)
        {
            int tam = mang[buoc];
            mang[buoc] = mang[viTriMin];
            mang[viTriMin] = tam;
        }
        
        printf("Buoc %d: ", buoc + 1);
        for(int k = 0; k < n; k++)
        {
            printf("%d ", mang[k]);
        }
        printf("\n");
    }
    
    return 0;
}
