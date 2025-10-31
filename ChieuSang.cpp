#include <stdio.h>

int main() {
    int n, m, k, i, j;
    int vitri[1000];
    int chieusan[1001] = {0};
    int demden = 0;
    
    scanf("%d", &n);
    scanf("%d", &m);
    scanf("%d", &k);
    
    for (i = 0; i < m; i++) {
        scanf("%d", &vitri[i]);
    }
    
    for (i = 0; i < m; i++) {
        int batdau = vitri[i] - k;
        int ketthuc = vitri[i] + k;
        
        if (batdau < 1) batdau = 1;
        if (ketthuc > n) ketthuc = n;
        
        for (j = batdau; j <= ketthuc; j++) {
            chieusan[j] = 1;
        }
    }
    
    i = 1;
    while (i <= n) {
        if (chieusan[i] == 0) {
            int vitrimoi = i + k;
            if (vitrimoi > n) vitrimoi = n;
            
            int batdau = vitrimoi - k;
            int ketthuc = vitrimoi + k;
            
            if (batdau < 1) batdau = 1;
            if (ketthuc > n) ketthuc = n;
            
            for (j = batdau; j <= ketthuc; j++) {
                chieusan[j] = 1;
            }
            
            demden++;
            i = ketthuc + 1;
        } else {
            i++;
        }
    }
    
    printf("%d\n", demden);
    
    return 0;
}
