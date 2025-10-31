#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);
    
    int a[105], b[105];
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &a[i], &b[i]);
    }
    
    // Tim min cua tung chieu
    int min_a = a[0], min_b = b[0];
    for (int i = 1; i < n; i++) {
        if (a[i] < min_a) min_a = a[i];
        if (b[i] < min_b) min_b = b[i];
    }
    
    // Gia tri max la so phep toan chua diem (min_a, min_b)
    int max_val = 0;
    for (int i = 0; i < n; i++) {
        if (min_a <= a[i] && min_b <= b[i]) {
            max_val++;
        }
    }
    
    // Dem so diem co gia tri max
    int count = 0;
    for (int i = 1; i <= min_a; i++) {
        for (int j = 1; j <= min_b; j++) {
            int val = 0;
            for (int k = 0; k < n; k++) {
                if (i <= a[k] && j <= b[k]) {
                    val++;
                }
            }
            if (val == max_val) {
                count++;
            }
        }
    }
    
    printf("%d\n", count);
    return 0;
}
