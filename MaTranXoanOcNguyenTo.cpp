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

int timNguyenToThu(int thu) {
    int dem = 0;
    int n = 2;
    
    while (dem < thu) {
        if (kiemTraNguyenTo(n)) {
            dem++;
            if (dem == thu) return n;
        }
        n++;
    }
    return n;
}

int main() {
    int soTest;
    scanf("%d", &soTest);
    
    for (int test = 1; test <= soTest; test++) {
        int n;
        int matran[20][20];
        
        scanf("%d", &n);
        
        int top = 0, bottom = n - 1;
        int left = 0, right = n - 1;
        int thuTu = 1;
        
        while (top <= bottom && left <= right) {
            for (int j = left; j <= right; j++) {
                matran[top][j] = timNguyenToThu(thuTu++);
            }
            top++;
            
            for (int i = top; i <= bottom; i++) {
                matran[i][right] = timNguyenToThu(thuTu++);
            }
            right--;
            
            if (top <= bottom) {
                for (int j = right; j >= left; j--) {
                    matran[bottom][j] = timNguyenToThu(thuTu++);
                }
                bottom--;
            }
            
            if (left <= right) {
                for (int i = bottom; i >= top; i--) {
                    matran[i][left] = timNguyenToThu(thuTu++);
                }
                left++;
            }
        }
        
        printf("Test %d:\n", test);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                printf("%2d", matran[i][j]);
                if (j < n - 1) printf(" ");
            }
            printf("\n");
        }
    }
    
    return 0;
}
