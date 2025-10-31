#include <stdio.h>

int kiemTraNguyenTo(int n) {
    if (n < 2) return 0;
    if (n == 2) return 1;
    if (n % 2 == 0) return 0;
    
    for (int i = 3; i * i <= n; i += 2) {
        if (n % i == 0) return 0;
    }
    return 1;
}

int main() {
    int n;
    int matran[30][30];
    
    scanf("%d", &n);
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &matran[i][j]);
        }
    }
    
    int maxSoLuong = 0;
    int hangTotNhat = -1;
    
    for (int i = 0; i < n; i++) {
        int dem = 0;
        for (int j = 0; j < n; j++) {
            if (kiemTraNguyenTo(matran[i][j])) {
                dem++;
            }
        }
        if (dem > maxSoLuong) {
            maxSoLuong = dem;
            hangTotNhat = i;
        }
    }
    
    printf("%d\n", hangTotNhat + 1);
    
    int dauTien = 1;
    for (int j = 0; j < n; j++) {
        if (kiemTraNguyenTo(matran[hangTotNhat][j])) {
            if (!dauTien) printf(" ");
            printf("%d", matran[hangTotNhat][j]);
            dauTien = 0;
        }
    }
    printf("\n");
    
    return 0;
}
