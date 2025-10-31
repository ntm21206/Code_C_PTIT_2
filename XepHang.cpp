#include <stdio.h>

struct khach 
{
    int thoidiemden;
    int thoigianxuly;
};

int main() 
{
    int n, i, j;
    struct khach danhsach[100];
    struct khach temp;
    int thoidiemketthuc = 0;
    
    scanf("%d", &n);
    
    for (i = 0; i < n; i++) 
	{
        scanf("%d %d", &danhsach[i].thoidiemden, &danhsach[i].thoigianxuly);
    }
    
    for (i = 0; i < n - 1; i++) 
	{
        for (j = i + 1; j < n; j++) 
		{
            if (danhsach[i].thoidiemden > danhsach[j].thoidiemden) 
			{
                temp = danhsach[i];
                danhsach[i] = danhsach[j];
                danhsach[j] = temp;
            }
        }
    }
    
    for (i = 0; i < n; i++) 
	{
        if (danhsach[i].thoidiemden > thoidiemketthuc) 
		{
            thoidiemketthuc = danhsach[i].thoidiemden;
        }
        thoidiemketthuc += danhsach[i].thoigianxuly;
    }
    
    printf("%d\n", thoidiemketthuc);
    
    return 0;
}
