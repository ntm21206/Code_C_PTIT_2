#include <stdio.h>

long long demSoDep(int soChuSo) {
    if (soChuSo % 2 == 0) {
        int nua = soChuSo / 2;
        
        if (nua == 1) {
            return 1;
        }
        
        long long dp[6][91] = {0};
        dp[0][0] = 1;
        
        for (int digit = 1; digit <= 9; digit++) {
            dp[1][digit] = 1;
        }
        
        for (int i = 2; i <= nua; i++) {
            for (int sum = 0; sum <= 9 * nua; sum++) {
                for (int digit = 0; digit <= 9; digit++) {
                    if (sum >= digit) {
                        dp[i][sum] += dp[i-1][sum-digit];
                    }
                }
            }
        }
        
        long long ketQua = 0;
        for (int tongNua = 0; tongNua <= 9 * nua; tongNua++) {
            if ((tongNua * 2) % 10 == 0) {
                ketQua += dp[nua][tongNua];
            }
        }
        
        return ketQua;
    } else {
        int nua = soChuSo / 2;
        long long ketQua = 0;
        
        for (int chuSoGiua = 0; chuSoGiua <= 9; chuSoGiua++) {
            if (nua == 0) {
                if (chuSoGiua != 0 && chuSoGiua % 10 == 0) {
                    ketQua += 1;
                }
                continue;
            }
            
            long long dp[6][91] = {0};
            dp[0][0] = 1;
            
            for (int digit = 1; digit <= 9; digit++) {
                dp[1][digit] = 1;
            }
            
            for (int i = 2; i <= nua; i++) {
                for (int sum = 0; sum <= 9 * nua; sum++) {
                    for (int digit = 0; digit <= 9; digit++) {
                        if (sum >= digit) {
                            dp[i][sum] += dp[i-1][sum-digit];
                        }
                    }
                }
            }
            
            for (int tongNua = 0; tongNua <= 9 * nua; tongNua++) {
                if ((tongNua * 2 + chuSoGiua) % 10 == 0) {
                    ketQua += dp[nua][tongNua];
                }
            }
        }
        
        return ketQua;
    }
}

int main() {
    int soBoTest;
    scanf("%d", &soBoTest);
    
    while (soBoTest--) {
        int soChuSo;
        scanf("%d", &soChuSo);
        
        long long ketQua = demSoDep(soChuSo);
        printf("%lld\n", ketQua);
    }
    
    return 0;
}
