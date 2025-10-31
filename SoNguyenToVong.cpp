#include <stdio.h>
#include <string.h>
#include <math.h>

int la_nguyen_to(int n) {
    if (n < 2) return 0;
    if (n == 2) return 1;
    if (n % 2 == 0) return 0;
    
    for (int i = 3; i <= sqrt(n); i += 2) {
        if (n % i == 0) return 0;
    }
    return 1;
}

int chuyen_thanh_so(char s[]) {
    int so = 0;
    int len = strlen(s);
    for (int i = 0; i < len; i++) {
        so = so * 10 + (s[i] - '0');
    }
    return so;
}

int la_nguyen_to_vong(int n) {
    char s[20];
    sprintf(s, "%d", n);
    int len = strlen(s);
    
    for (int i = 0; i < len; i++) {
        char xoay[20];
        strcpy(xoay, s + i);
        strncat(xoay, s, i);
        
        int so_xoay = chuyen_thanh_so(xoay);
        if (!la_nguyen_to(so_xoay)) {
            return 0;
        }
    }
    return 1;
}

int main() {
    int t;
    scanf("%d", &t);
    
    while (t--) {
        int n;
        scanf("%d", &n);
        
        if (la_nguyen_to_vong(n)) {
            printf("1\n");
        } else {
            printf("0\n");
        }
    }
    
    return 0;
}
