#include <stdio.h>

int laSoNguyenTo(int n) 
{
    if (n < 2) return 0;
    if (n == 2) return 1;
    if (n % 2 == 0) return 0;
    
    for (int i = 3; i * i <= n; i += 2) 
	{
        if (n % i == 0) return 0;
    }
    return 1;
}

int tongChuSo(int n) 
{
    int tong = 0;
    while (n > 0) {
        tong += n % 10;
        n /= 10;
    }
    return tong;
}

int main() 
{
    int n;
    scanf("%d", &n);
    
    int dem = 0;
    int dauin = 1;
    
    for (int i = 2; i < n; i++) 
	{
        if (laSoNguyenTo(i) && tongChuSo(i) % 5 == 0) 
		{
            if (!dauin) printf(" ");
            printf("%d", i);
            dauin = 0;
            dem++;
        }
    }
    
    printf("\n%d\n", dem);
    
    return 0;
}
