#include <stdio.h>

int main() {
    int n;
    int matran[100][100];
    
    scanf("%d", &n);
    
    int top = 0, bottom = n - 1;
    int left = 0, right = n - 1;
    int giatri = 1;
    
    while (top <= bottom && left <= right) {
        for (int j = left; j <= right; j++) {
            matran[top][j] = giatri++;
        }
        top++;
        
        for (int i = top; i <= bottom; i++) {
            matran[i][right] = giatri++;
        }
        right--;
        
        if (top <= bottom) {
            for (int j = right; j >= left; j--) {
                matran[bottom][j] = giatri++;
            }
            bottom--;
        }
        
        if (left <= right) {
            for (int i = bottom; i >= top; i--) {
                matran[i][left] = giatri++;
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
