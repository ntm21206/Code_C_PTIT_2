#include <stdio.h>

typedef struct 
{
    unsigned long long tu_so;
    unsigned long long mau_so;
} PhanSo;

unsigned long long ucln(unsigned long long a, unsigned long long b) 
{
    while (b != 0) 
	{
        unsigned long long temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

int main() 
{
    PhanSo ps;
    unsigned long long uoc_chung;
    
    scanf("%llu %llu", &ps.tu_so, &ps.mau_so);
    
    uoc_chung = ucln(ps.tu_so, ps.mau_so);
    
    ps.tu_so /= uoc_chung;
    ps.mau_so /= uoc_chung;
    
    printf("%llu/%llu\n", ps.tu_so, ps.mau_so);
    
    return 0;
}
