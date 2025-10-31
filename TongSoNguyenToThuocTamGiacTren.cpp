#include <stdio.h>

bool kiemTraNguyenTo(int n) {
    if (n < 2) return false;
    if (n == 2) return true;
    if (n % 2 == 0) return false;
    
    for (int i = 3; i * i <= n; i += 2) {
        if (n % i == 0) return false;
    }
    return true;
}

int main() {
    int n;
    int matran[50][50];
    int tong = 0;
    
    scanf("%d", &n);
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &matran[i][j]);
        }
    }
    
    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            if (kiemTraNguyenTo(matran[i][j])) {
                tong += matran[i][j];
            }
        }
    }
    
    printf("%d\n", tong);
    
    return 0;
}
