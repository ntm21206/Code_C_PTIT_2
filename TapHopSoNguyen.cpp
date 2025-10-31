#include <stdio.h>

int main() {
    int n, m, i, j;
    int a[100], b[100];
    int tapA[1000] = {0}, tapB[1000] = {0};
    int giao[1000], hieuAB[1000], hieuBA[1000];
    int demgiao = 0, demAB = 0, demBA = 0;
    
    scanf("%d %d", &n, &m);
    
    for (i = 0; i < n; i++) {
        scanf("%d", &a[i]);
        tapA[a[i]] = 1;
    }
    
    for (i = 0; i < m; i++) {
        scanf("%d", &b[i]);
        tapB[b[i]] = 1;
    }
    
    for (i = 1; i < 1000; i++) {
        if (tapA[i] == 1 && tapB[i] == 1) {
            giao[demgiao++] = i;
        }
        
        if (tapA[i] == 1 && tapB[i] == 0) {
            hieuAB[demAB++] = i;
        }
        
        if (tapB[i] == 1 && tapA[i] == 0) {
            hieuBA[demBA++] = i;
        }
    }
    
    for (i = 0; i < demgiao; i++) {
        printf("%d", giao[i]);
        if (i < demgiao - 1) printf(" ");
    }
    printf("\n");
    
    for (i = 0; i < demAB; i++) {
        printf("%d", hieuAB[i]);
        if (i < demAB - 1) printf(" ");
    }
    printf("\n");
    
    for (i = 0; i < demBA; i++) {
        printf("%d", hieuBA[i]);
        if (i < demBA - 1) printf(" ");
    }
    printf("\n");
    
    return 0;
}
