#include <stdio.h>

int main() {
    int soTest;
    scanf("%d", &soTest);
    
    for (int test = 1; test <= soTest; test++) {
        int n;
        int A[20][20];
        int AT[20][20];
        int ketQua[20][20];
        
        scanf("%d", &n);
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (j <= i) {
                    A[i][j] = j + 1;
                } else {
                    A[i][j] = 0;
                }
            }
        }
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                AT[j][i] = A[i][j];
            }
        }
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                ketQua[i][j] = 0;
                for (int k = 0; k < n; k++) {
                    ketQua[i][j] += A[i][k] * AT[k][j];
                }
            }
        }
        
        printf("Test %d:\n", test);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                printf("%d", ketQua[i][j]);
                if (j < n - 1) printf(" ");
            }
            printf("\n");
        }
        printf("\n");
    }
    
    return 0;
}
