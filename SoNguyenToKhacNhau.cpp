#include <stdio.h>
#include <stdbool.h>

bool laSoNguyenTo(int n) {
    if (n < 2) return false;
    if (n == 2) return true;
    if (n % 2 == 0) return false;
    
    for (int i = 3; i * i <= n; i += 2) {
        if (n % i == 0) return false;
    }
    return true;
}

int main() {
    int soBoTest;
    scanf("%d", &soBoTest);
    
    while (soBoTest--) {
        int N;
        scanf("%d", &N);
        
        bool coMatSoNguyenTo[1001] = {false};
        
        for (int i = 0; i < N; i++) {
            int so;
            scanf("%d", &so);
            if (laSoNguyenTo(so)) {
                coMatSoNguyenTo[so] = true;
            }
        }
        
        bool dau = true;
        for (int i = 2; i <= 1000; i++) {
            if (coMatSoNguyenTo[i]) {
                if (!dau) printf(" ");
                printf("%d", i);
                dau = false;
            }
        }
        printf("\n");
    }
    
    return 0;
}
