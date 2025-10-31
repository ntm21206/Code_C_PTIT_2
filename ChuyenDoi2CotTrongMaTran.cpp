#include <stdio.h>

int main() {
    int m, n, i, j;
    int matran[50][50];
    int a, b, temp;
    
    scanf("%d %d", &m, &n);
    
    for (i = 0; i < m; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &matran[i][j]);
        }
    }
    
    scanf("%d %d", &a, &b);
    
    for (i = 0; i < m; i++) {
        temp = matran[i][a-1];
        matran[i][a-1] = matran[i][b-1];
        matran[i][b-1] = temp;
    }
    
    for (i = 0; i < m; i++) {
        for (j = 0; j < n; j++) {
            printf("%d", matran[i][j]);
            if (j < n - 1) printf(" ");
        }
        printf("\n");
    }
    
    return 0;
}
