#include <stdio.h>

int main() {
    int test, n, m, i, j, k;
    int matran[10][10];
    int tonghang[10], tongcot[10];
    int maxhang, maxcot, vithang, vitcot;
    
    scanf("%d", &test);
    
    for (int t = 1; t <= test; t++) {
        scanf("%d %d", &n, &m);
        
        for (i = 0; i < n; i++) {
            for (j = 0; j < m; j++) {
                scanf("%d", &matran[i][j]);
            }
        }
        
        maxhang = -1;
        vithang = 0;
        for (i = 0; i < n; i++) {
            tonghang[i] = 0;
            for (j = 0; j < m; j++) {
                tonghang[i] += matran[i][j];
            }
            if (tonghang[i] > maxhang) {
                maxhang = tonghang[i];
                vithang = i;
            }
        }
        
        for (i = vithang; i < n - 1; i++) {
            for (j = 0; j < m; j++) {
                matran[i][j] = matran[i + 1][j];
            }
        }
        n--;
        
        maxcot = -1;
        vitcot = 0;
        for (j = 0; j < m; j++) {
            tongcot[j] = 0;
            for (i = 0; i < n; i++) {
                tongcot[j] += matran[i][j];
            }
            if (tongcot[j] > maxcot) {
                maxcot = tongcot[j];
                vitcot = j;
            }
        }
        
        for (j = vitcot; j < m - 1; j++) {
            for (i = 0; i < n; i++) {
                matran[i][j] = matran[i][j + 1];
            }
        }
        m--;
        
        printf("Test %d:\n", t);
        for (i = 0; i < n; i++) {
            for (j = 0; j < m; j++) {
                printf("%d", matran[i][j]);
                if (j < m - 1) printf(" ");
            }
            printf("\n");
        }
    }
    
    return 0;
}
