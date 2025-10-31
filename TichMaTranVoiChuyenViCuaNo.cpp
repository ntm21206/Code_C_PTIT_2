#include <stdio.h>

int main() {
    int soTest;
    scanf("%d", &soTest);
    
    for (int test = 1; test <= soTest; test++) {
        int n, m;
        int A[100][100];
        int AT[100][100];
        int ketQua[100][100];
        
        scanf("%d %d", &n, &m);
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                scanf("%d", &A[i][j]);
            }
        }
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                AT[j][i] = A[i][j];
            }
        }
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                ketQua[i][j] = 0;
                for (int k = 0; k < m; k++) {
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
    }
    
    return 0;
}
