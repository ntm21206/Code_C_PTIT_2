#include <stdio.h>
#include <string.h>

int max(int a, int b) {
    return a > b ? a : b;
}

int lps(char s[], int n) {
    int dp[n][n];
    
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            dp[i][j] = 0;
    
    for (int i = 0; i < n; i++)
        dp[i][i] = 1;
    
    for (int len = 2; len <= n; len++) {
        for (int i = 0; i <= n - len; i++) {
            int j = i + len - 1;
            if (s[i] == s[j]) {
                if (len == 2)
                    dp[i][j] = 2;
                else
                    dp[i][j] = dp[i+1][j-1] + 2;
            } else {
                dp[i][j] = max(dp[i+1][j], dp[i][j-1]);
            }
        }
    }
    
    return dp[0][n-1];
}

int main() {
    char s[100001];
    fgets(s, sizeof(s), stdin);
    
    int len = strlen(s);
    if (s[len-1] == '\n') {
        s[len-1] = '\0';
        len--;
    }
    
    int dauDaiNhat = lps(s, len);
    
    printf("%d\n", len - 1);
    
    return 0;
}
