#include <stdio.h>

int gcd(int a, int b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}

int lcm(int a, int b) {
    return (a * b) / gcd(a, b);
}

void rutgon(int *tu, int *mau) {
    int ucln = gcd(*tu, *mau);
    *tu /= ucln;
    *mau /= ucln;
}

int main() {
    int t;
    scanf("%d", &t);
    
    for (int i = 1; i <= t; i++) {
        int tu1, mau1, tu2, mau2;
        scanf("%d %d %d %d", &tu1, &mau1, &tu2, &mau2);
        
        rutgon(&tu1, &mau1);
        rutgon(&tu2, &mau2);
        
        printf("Case #%d:\n", i);
        
        int msc = lcm(mau1, mau2);
        int tu1_qd = tu1 * (msc / mau1);
        int tu2_qd = tu2 * (msc / mau2);
        printf("%d/%d %d/%d\n", tu1_qd, msc, tu2_qd, msc);
        
        int tu_tong = tu1_qd + tu2_qd;
        int mau_tong = msc;
        rutgon(&tu_tong, &mau_tong);
        printf("%d/%d\n", tu_tong, mau_tong);
        
        int tu_thuong = tu1 * mau2;
        int mau_thuong = mau1 * tu2;
        rutgon(&tu_thuong, &mau_thuong);
        printf("%d/%d\n", tu_thuong, mau_thuong);
    }
    
    return 0;
}
