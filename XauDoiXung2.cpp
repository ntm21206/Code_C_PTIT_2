#include <stdio.h>
#include <string.h>

int max(int a, int b) {
    return a > b ? a : b;
}

int main() {
    char s[100001];
    fgets(s, sizeof(s), stdin);
    
    int n = strlen(s);
    if (s[n - 1] == '\n') {
        s[n - 1] = '\0';
        n--;
    }
    
    int dp[2][n + 1];
    
    for (int i = 0; i <= n; i++) {
        dp[0][i] = dp[1][i] = 0;
    }
    
    for (int i = 1; i <= n; i++) {
        int curr = i % 2;
        int prev = 1 - curr;
        
        for (int j = 1; j <= n; j++) {
            if (s[i-1] == s[n-j]) {
                dp[curr][j] = dp[prev][j-1] + 1;
            } else {
                dp[curr][j] = max(dp[prev][j], dp[curr][j-1]);
            }
        }
    }
    
    int lcs = dp[n % 2][n];
    printf("%d\n", n - lcs);
    
    return 0;
}
