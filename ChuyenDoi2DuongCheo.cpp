#include <stdio.h>

int main() {
    int m;
    int matran[50][50];
    int temp;
    
    scanf("%d", &m);
    
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < m; j++) {
            scanf("%d", &matran[i][j]);
        }
    }
    
    for (int i = 0; i < m; i++) {
        temp = matran[i][i];
        matran[i][i] = matran[i][m-1-i];
        matran[i][m-1-i] = temp;
    }
    
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < m; j++) {
            printf("%d ", matran[i][j]);
        }
        printf("\n");
    }
    
    return 0;
}
