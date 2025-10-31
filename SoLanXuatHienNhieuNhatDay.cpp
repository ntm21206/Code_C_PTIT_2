#include<stdio.h>

int main()
{
    int t;
    scanf("%d", &t);
    
    while(t--)
    {
        int n;
        scanf("%d", &n);
        
        int day[100];
        int tanxuat[30001] = {0};
        int xuathien[30001] = {0};
        
        for(int i = 0; i < n; i++)
        {
            scanf("%d", &day[i]);
            tanxuat[day[i]]++;
            if(xuathien[day[i]] == 0)
            {
                xuathien[day[i]] = i + 1;
            }
        }
        
        int maxTanXuat = 0;
        for(int i = 0; i <= 30000; i++)
        {
            if(tanxuat[i] > maxTanXuat)
            {
                maxTanXuat = tanxuat[i];
            }
        }
        
        int dau = 1;
        for(int i = 0; i < n; i++)
        {
            if(tanxuat[day[i]] == maxTanXuat && xuathien[day[i]] == i + 1)
            {
                if(dau == 1)
                {
                    printf("%d", day[i]);
                    dau = 0;
                }
                else
                {
                    printf(" %d", day[i]);
                }
            }
        }
        printf("\n");
    }
    
    return 0;
}
