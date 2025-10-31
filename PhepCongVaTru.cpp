#include <stdio.h>
#include <string.h>

void cong(char a[], char b[], char kq[]) {
    int la = strlen(a), lb = strlen(b);
    int nho = 0, k = 0;
    int i = la - 1, j = lb - 1;
    
    while (i >= 0 || j >= 0 || nho) {
        int s = nho;
        if (i >= 0) s += a[i--] - '0';
        if (j >= 0) s += b[j--] - '0';
        kq[k++] = s % 10 + '0';
        nho = s / 10;
    }
    kq[k] = 0;
}

void tru(char a[], char b[], char kq[]) {
    int la = strlen(a), lb = strlen(b);
    if (la < lb || (la == lb && strcmp(a, b) < 0)) {
        tru(b, a, kq);
        return;
    }
    
    int muon = 0, k = 0;
    int i = la - 1, j = lb - 1;
    
    while (i >= 0) {
        int s = a[i--] - '0' - muon;
        if (j >= 0) s -= b[j--] - '0';
        if (s < 0) { s += 10; muon = 1; } else muon = 0;
        kq[k++] = s + '0';
    }
    
    while (k > 1 && kq[k-1] == '0') k--;
    kq[k] = 0;
}

void dao(char s[]) {
    int n = strlen(s);
    for (int i = 0; i < n/2; i++) {
        char t = s[i]; s[i] = s[n-1-i]; s[n-1-i] = t;
    }
}

int main() {
    int t;
    scanf("%d", &t);
    
    while (t--) {
        char a[35], b[35], tong[35], hieu[35];
        scanf("%s %s", a, b);
        
        cong(a, b, tong);
        tru(a, b, hieu);
        
        dao(tong); dao(hieu);
        printf("%s %s\n", tong, hieu);
    }
    
    return 0;
}
