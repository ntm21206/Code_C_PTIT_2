#include <stdio.h>

int main() {
    int n;
    int matran[9][9];
    int fib[100];
    
    scanf("%d", &n);
    
    fib[0] = 0;
    fib[1] = 1;
    for (int i = 2; i < 100; i++) {
        fib[i] = fib[i-1] + fib[i-2];
    }
    
    int top = 0, bottom = n - 1;
    int left = 0, right = n - 1;
    int thuTu = 0;
    
    while (top <= bottom && left <= right) {
        for (int j = left; j <= right; j++) {
            matran[top][j] = fib[thuTu++];
        }
        top++;
        
        for (int i = top; i <= bottom; i++) {
            matran[i][right] = fib[thuTu++];
        }
        right--;
        
        if (top <= bottom) {
            for (int j = right; j >= left; j--) {
                matran[bottom][j] = fib[thuTu++];
            }
            bottom--;
        }
        
        if (left <= right) {
            for (int i = bottom; i >= top; i--) {
                matran[i][left] = fib[thuTu++];
            }
            left++;
        }
    }
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d", matran[i][j]);
            if (j < n - 1) printf(" ");
        }
        printf("\n");
    }
    
    return 0;
}
