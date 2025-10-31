#include <stdio.h>

int main() {
    int u0, d, n;
    scanf("%d %d %d", &u0, &d, &n);
    
    long long tong = 0;
    int so_hang = u0;
    
    for (int i = 0; i < n; i++) {
        tong += so_hang;
        so_hang += d;
    }
    
    printf("%lld\n", tong);
    
    return 0;
}
