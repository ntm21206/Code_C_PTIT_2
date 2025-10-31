#include<stdio.h>

void sapxep(int arr[], int n)
{
    for(int i = 0; i < n - 1; i++)
    {
        for(int j = i + 1; j < n; j++)
        {
            if(arr[i] > arr[j])
            {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

int main()
{
    int n;
    scanf("%d", &n);
    
    int a[100];
    int chan[100], le[100];
    int demchan = 0, demle = 0;
    
    for(int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
        if(a[i] % 2 == 0)
        {
            chan[demchan] = a[i];
            demchan++;
        }
        else
        {
            le[demle] = a[i];
            demle++;
        }
    }
    
    sapxep(chan, demchan);
    sapxep(le, demle);
    
    for(int i = 0; i < demchan; i++)
    {
        if(i == 0)
            printf("%d", chan[i]);
        else
            printf(" %d", chan[i]);
    }
    
    for(int i = 0; i < demle; i++)
    {
        if(i == 0 && demchan == 0)
            printf("%d", le[i]);
        else
            printf(" %d", le[i]);
    }
    
    printf("\n");
    
    return 0;
}
